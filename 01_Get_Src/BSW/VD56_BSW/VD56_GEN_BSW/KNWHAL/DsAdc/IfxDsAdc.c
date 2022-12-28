/******************************************************************************/
/* !Layer          : HAL                                                      */
/* !Component      : DSADC                                                    */
/* !Description    : DSADC driver                                             */
/*                                                                            */
/* !File           : IfxDsAdc.c                                               */
/* !Description    : DSADC driver                                             */
/*                                                                            */
/* !Reference      :                                                          */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A170705.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "std_types.h"
#include "IfxDsAdc.h"
#include "IfxGtm_reg.h"
#include "IfxDsadc_reg.h"
#include "Mcal_DmaLib.h"
#include "Mcal_WdgLib.h"
#include "IfxSrc_bf.h"
#include "IfxGtm_Def.h"

/*****************************************************************************/
/*                           Global Variables                                */
/*****************************************************************************/

/*****************************************************************************/
/*                           Function prototypes                             */
/*****************************************************************************/
static void IfxDsadc_ResetClr(void);
/*****************************************************************************/
/*                           Functions                                       */
/*****************************************************************************/

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_Init                                               */
/*                                                                            */
/* !Description  : This method Initialise the DSADC module to run with the    */
/*                 expected modulator frequency and channel run control       */
/*                 Also the API Takes care of reseting the DSADC module       */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
uint8 IfxDsadc_Init(IfxDsadc_InitConfig *ConfigPtr)
{
   uint16 timeout;
   uint8  RetVal;


   RetVal = 0U;

   /* Enable the ADC Module Clock */
   Mcal_ResetENDINIT();
   /* Enable the ADC Module */
   IFX_GTM_CLEAR_BIT(MODULE_DSADC.CLC.U, IFX_DSADC_CLC_DISR_OFF);
   /*DSADC_CLC.B.DISR = 0U; */

   /* Enable Sleep Mode if configured */
   if (ConfigPtr->AdcSleepModeEnable)
   {
      IFX_GTM_SET_BIT(MODULE_DSADC.CLC.U, IFX_DSADC_CLC_EDIS_OFF);
   }
   else
   {
      IFX_GTM_CLEAR_BIT(MODULE_DSADC.CLC.U, IFX_DSADC_CLC_EDIS_OFF);
   }
   /*MODULE_DSADC.CLC.B.EDIS = ConfigPtr->AdcSleepModeEnable;*/
   Mcal_SetENDINIT();

   /* Read back the CLC register */
   timeout = 5000U; /* IFXDSADC_INIT_TIMEOUT; */
   do
   {
      timeout--;
   } while (  (MODULE_DSADC.CLC.B.DISS)
           && (timeout > 0UL) );

   if (0UL != timeout)
   {
      /* reset the kernels */
      IfxDsadc_Reset();
      IfxDsadc_ResetClr();

      /* Set Modulator Clock */
      /* Post calibration DPCALx always enabled */
      MODULE_DSADC.GLOBCFG.U = ConfigPtr->GlobCfg;
      MODULE_DSADC.GLOBRC.U  = ConfigPtr->ChRunMod;
   }
   else
   {
      RetVal = 1U;
   }
   return(RetVal);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_Reset                                              */
/*                                                                            */
/* !Description  : This routine shall be used to reset the DSADC module,      */
/*                 without resetting the whole controller.                    */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IfxDsadc_Reset(void)
{
   Mcal_ResetENDINIT();

   IFX_GTM_SET_BIT(MODULE_DSADC.KRST1.U, IFX_DSADC_KRST1_RST_OFF);
   IFX_GTM_SET_BIT(MODULE_DSADC.KRST0.U, IFX_DSADC_KRST0_RST_OFF);
   /*
      MODULE_DSADC.KRST1.B.RST = 1U;
      MODULE_DSADC.KRST0.B.RST = 1U;
    */
   Mcal_SetENDINIT();

   /* Wait until reset is executed */
   while (MODULE_DSADC.KRST0.B.RSTSTAT == 0U)
   {
      ;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_ResetClr                                           */
/*                                                                            */
/* !Description  : This routine clears the ADC module reset information.      */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
static void IfxDsadc_ResetClr(void)
{
   Mcal_ResetENDINIT();
   IFX_GTM_CLEAR_BIT(MODULE_DSADC.KRSTCLR.U, IFX_DSADC_KRSTCLR_CLR_OFF);
   /*MODULE_DSADC.KRSTCLR.B.CLR = 1U;*/
   Mcal_SetENDINIT();
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_InitCh                                             */
/*                                                                            */
/* !Description  : This routine initializes the DSADC channel.                */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IfxDsadc_InitCh(IfxDsadc_ChCfg *ConfigPtr,
                     uint8           Channel)
{
   if (IFXDSADC_TRIGGERSEL_DSADC_TRIG0 == ConfigPtr->trigSel)
   {
      GTM_INOUTSEL_DSADC_OUTSEL00.U |= ( (uint32)ConfigPtr->HwExtTrigOpSel << ( (uint32)(Channel) * 4U) );
   }
   else
   {
      if (IFXDSADC_TRIGGERSEL_DSADC_TRIG1 == ConfigPtr->trigSel)
      {
         GTM_INOUTSEL_DSADC_OUTSEL10.U |= ( (uint32)ConfigPtr->HwExtTrigOpSel << ( ( (uint32)Channel) * 4U) );
      }
   }

   /*GTM_INOUTSEL_DSADC_OUTSEL10.B.SEL3 = ConfigPtr->HwExtTrigOpSel;*/
   MODULE_DSADC.CH[Channel].DICFG.U  = ConfigPtr->DemodulCfg->U | ( (uint32)(ConfigPtr->trigSel) << 12U);
   MODULE_DSADC.CH[Channel].MODCFG.U = ConfigPtr->ModulatorCfg->U;

   MODULE_DSADC.CH[Channel].FCFGM.U = ConfigPtr->MainFilCfg->U;
   MODULE_DSADC.CH[Channel].FCFGC.U = ConfigPtr->CombiFilCfg->U;
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_DisableInterrupt                                   */
/*                                                                            */
/* !Description  : This routine disables the DSADC channel interrupt.         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IfxDsadc_DisableInterrupt(IfxDsadc_ChannelId Dsadc_Channel)
{
   IFX_GTM_CLEAR_BIT(MODULE_SRC.DSADC.DSADC[Dsadc_Channel].SRM.U, IFX_SRC_SRCR_SRE_OFF);
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_EnableInterrupt                                    */
/*                                                                            */
/* !Description  : This routine enables the DSADC channel interrupt.          */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IfxDsadc_EnableInterrupt(IfxDsadc_ChannelId Dsadc_Channel,
                              Dma_ChannelType    Channel)
{
   /* Write the priority to the DMA channel number */
   IFX_GTM_WRITE_REG(MODULE_SRC.DSADC.DSADC[Dsadc_Channel].SRM.U,
                     IFX_DSADC_SRC_SRM_SRPN_MASK,
                     IFX_SRC_SRCR_SRPN_OFF,
                     Channel);
   /* Write the TOS to DMA */
   IFX_GTM_WRITE_REG(MODULE_SRC.DSADC.DSADC[Dsadc_Channel].SRM.U,
                     IFX_DSADC_SRC_SRM_TOS_MASK,
                     IFX_SRC_SRCR_TOS_OFF,
                     3U); /* 0x1800 */

   /*MODULE_SRC.DSADC.DSADC[Dsadc_Channel].SRM.U = 0x1804 ;*/
   /* set SREN enable bit */
   IFX_GTM_SET_BIT(MODULE_SRC.DSADC.DSADC[Dsadc_Channel].SRM.U, IFX_SRC_SRCR_SRE_OFF);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_SetServiceReq                                      */
/*                                                                            */
/* !Description  : This routine sets the SRGM bit on the DSADC channel        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IfxDsadc_SetServiceReq(IfxDsadc_ChannelId Channel,
                            uint16             Value)
{
   IFX_GTM_WRITE_REG(
      MODULE_DSADC.CH[Channel].FCFGC.U,
      IFX_DSADC_CH_SRGM_MASK,
      IFX_DSADC_CH_FCFGC_SRGM_OFF,
      Value
                    );
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IfxDsadc_SetClockDivider                                    */
/*                                                                            */
/* !Description  : This routine sets the DIVM on the DSADC channel.           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IfxDsadc_SetClockDivider(IfxDsadc_ChannelId Channel,
                              uint32             u32localDivM)
{
   IFX_GTM_WRITE_REG(
      MODULE_DSADC.CH[Channel].MODCFG.U,
      IFX_DSADC_CH_DIVM_MASK,
      IFX_DSADC_CH_MODCFG_DIVM_OFF,
      u32localDivM
                    );
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : IxDsadc_SetOverSamplingRate                                 */
/*                                                                            */
/* !Description  : This routine sets the OSR on the DSADC channel   .         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void IxDsadc_SetOverSamplingRate(IfxDsadc_ChannelId Channel,
                                 uint32             u32localOsr)
{
   IFX_GTM_WRITE_REG(
      MODULE_DSADC.CH[Channel].FCFGC.U,
      IFX_DSADC_CH_CFMDF_MASK,
      IFX_DSADC_CH_FCFGC_CFMDF_OFF,
      u32localOsr
                    );
}
/*------------------------------- end of file --------------------------------*/
