/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNWHAL_1.c                                              */
/* !Description     : General sub-functions of the KNWHAL component           */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:0A170704.A-SRC;5 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "std_types.h"
#include "std_limits.h"
#include "KNWHAL.h"
#include "KNWHAL_I.h"
#include "KNWHAL_Cfg.h"
#include "CRKHAL.h"
#include "IfxDsAdc.h"
#include "Mcal_DmaLib.h"
#include "TSKSRV.h"
#include "KNWHAL_dsadc_cfg.h"
#include "IfxDsAdc.h"
#include "Mcal_DmaLib.h"
#include "IfxDma_bf.h"
#include "IfxGtm_Def.h"
#include "IfxDsAdc.h"
#include "KNWHAL_gtm.h"

#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"

/*lint -esym(960,17.4) */
/*lint -save -e718 */
/*lint -save -e746 */
/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidInitSamplePeriod / A                              */
/*                                                                            */
/* !Description  : Sets the Clock divider depending on the sample time        */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidInitSamplePeriod(void)
{
   IfxDsadc_SetClockDivider(KNWHAL_snDSADCDRV_KNOCK_CONVERTER,
                            (uint32)KNWHAL_u8KnockClockDividor);
   IxDsadc_SetOverSamplingRate(KNWHAL_snDSADCDRV_KNOCK_CONVERTER,
                               (uint32)KNWHAL_u8KnockOverSamplingRate);
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidItKnockWindow / A                                 */
/*                                                                            */
/* !Description  : Call back function for the KNWHAL Angle                    */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidItKnockWindow(void)
{
   uint32 u32LocalDmatcrRegisterVal;
   uint32 u32LocalDmaSizeRemaining;
   uint32 u32LocalIndex;


   /* First Window starting */
   if (KNWHAL_bKnwModulatorOnWindow == (boolean)FALSE)
   {
      if (KNWHAL_bDigitalWindow == (boolean)FALSE)
      {
         /* End of Window 1 and begining of Window 2 */
         KNWHAL_bDigitalWindow   = (boolean)TRUE;
         KNWHAL_u8SamplingWinIdx = 1U;
         /* Start the ADC aqusitions */
         IfxDsadc_SetServiceReq(KNWHAL_snDSADCDRV_KNOCK_CONVERTER, IFXDSADC_SRCGEN_GATEHIGH /*IfxDsadc_Srcgen_Always*/);

         CRKHAL_vidSetAbsAlarm(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN,
                               ( (uint16 *)KNWHAL_u32SamplingWinTblAddress)[1]);
         ( (uint32 *)KNWHAL_u32SamplingWinIdxTblAddr)[UINT8_MIN] = (uint32)UINT32_MIN;
      }
      else
      {
         /* !Comment: Saving of sampling window index = DMA transfer number      */
         /*           = initial DMATCR - current DMATCR                          */
         u32LocalDmatcrRegisterVal = Mcal_DmaGetTransferCount
                                        (KNWHAL_snDMA_KNOCK_SAMPLE_CH);
         u32LocalDmaSizeRemaining =
            (uint32)(KNWHAL_u32SampleTblMaxSize - u32LocalDmatcrRegisterVal);
         u32LocalIndex                                               = KNWHAL_u8SamplingWinIdx;
         ( (uint32 *)KNWHAL_u32SamplingWinIdxTblAddr)[u32LocalIndex] =
            u32LocalDmaSizeRemaining;

         KNWHAL_u8SamplingWinIdx++;
         u32LocalIndex = KNWHAL_u8SamplingWinIdx;
         if (u32LocalIndex <= KNWHAL_u8SamplingWinNr)
         {
            /* Not the last window */
            CRKHAL_vidSetAbsAlarm(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN,
                                  ( (uint16 *)KNWHAL_u32SamplingWinTblAddress)[
                                     u32LocalIndex]);
         }
         else
         {
            KNWHAL_bDigitalWindow = (boolean)FALSE;
            /* !Comment: Disable of DMA Transfers                                */
            IfxDsadc_SetServiceReq(KNWHAL_snDSADCDRV_KNOCK_CONVERTER, IFXDSADC_SRCGEN_NEVER);
            Mcal_DmaDisableHwTransfer(KNWHAL_snDMA_KNOCK_SAMPLE_CH);
            Mcal_DmaResetDmaChannel(KNWHAL_snDMA_KNOCK_SAMPLE_CH);
            /* !Comment: Disable of knock angular alarms                         */
            CRKHAL_vidDisableAlarmNotif(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN);
            KNWHAL_GtmDisable();
            /* !Comment: Activation of Task of End of Knock Window               */
            TSKSRV_vidActivateTask(KNWHAL_KNK_WIN_EVENT);
            KNWHAL_bKnwAcquisitionRunning = (boolean)FALSE;
         }
      }
   }
   else
   {
      KNWHAL_bKnwModulatorOnWindow = (boolean)FALSE;
      CRKHAL_vidActivateAlarmMode(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN, MODE_OUTPUT_1);
      CRKHAL_vidSetAbsAlarm(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN,
                            ((uint16 *)KNWHAL_u32SamplingWinTblAddress)[0u]);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidDeactivateResources / A                           */
/* !Description : Initializes the DSADC registers to default value            */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidDeactivateResources(void)
{
   uint8 u8LocalRetVal;


   /* Disable the Alarm Notification, mode is disabled */
   CRKHAL_vidDisableAlarmNotif(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN);
   KNWHAL_GtmDisable();

   Mcal_DmaDisableHwTransfer(KNWHAL_snDMA_KNOCK_SAMPLE_CH);
   Mcal_DmaResetDmaChannel(KNWHAL_snDMA_KNOCK_SAMPLE_CH);

   KNWHAL_bDigitalWindow         = (boolean)FALSE;
   KNWHAL_bKnwAcquisitionRunning = (boolean)FALSE;
   KNWHAL_u8SamplingWinIdx       = (uint8)UINT8_MIN;

   /* !Comment: Disable of ADC Interrupt                                      */
   IfxDsadc_DisableInterrupt(KNWHAL_snDSADCDRV_KNOCK_CONVERTER);

   /* Init the DS Module here */
   u8LocalRetVal = IfxDsadc_Init(&IfxDsAdc_InitData);
   if (0U == u8LocalRetVal)
   {
      IfxDsadc_InitCh(&IfxDsadc_Channel, (uint8)KNWHAL_snDSADCDRV_KNOCK_CONVERTER);
      IfxDsadc_SetServiceReq(KNWHAL_snDSADCDRV_KNOCK_CONVERTER, IFXDSADC_SRCGEN_NEVER);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : KNWHAL_u32GetOsrFromTbl / A                                 */
/* !Description : Finds the closet OSR from the truth table given             */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
uint32 KNWHAL_u32GetOsrFromTbl(const IfxDsadc_OsrTbl *Tbl,
                               uint8                  u8Count,
                               uint32                 u32Period,
                               uint32                *pu32Index)
{
   /*volatile*/ sint32  s32LocalDifference;
   /*volatile */ uint32 u32Osr_Val;
   /*volatile*/ uint32  u32Index;
   /*volatile */ uint32 U32IndexTable;


   u32Osr_Val    = 0U;
   U32IndexTable = 0U;

   for (u32Index = 0U; u32Index < u8Count; u32Index++)
   {
      s32LocalDifference = (sint32)( (sint32)(Tbl[u32Index].SampleRate) - (sint32)(u32Period) );
      if (s32LocalDifference < 0)
      {
         s32LocalDifference = (sint32)( (sint32)(u32Period) - (sint32)(Tbl[u32Index].SampleRate) );
      }
      if (u32Index == 0U)
      {
         u32Osr_Val    = (uint32)s32LocalDifference;
         U32IndexTable = u32Index;
      }

      if ( (uint32)s32LocalDifference < u32Osr_Val)
      {
         u32Osr_Val    = (uint32)s32LocalDifference;
         U32IndexTable = u32Index;
      }
   }

   *pu32Index = U32IndexTable;
   return(u32Osr_Val);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidInitDma / A                                       */
/* !Description : Initializes the DMA parameter to the dafult value           */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidInitDma(Dma_ChannelType Channel)
{
   /* Write the PROAT = 0  :oneTransferPerRequest  */
   IFX_GTM_WRITE_REG(MODULE_DMA.CH[Channel].CHCFGR.U,
                     IFX_KNWHAL_DMA_PROAT_ONE_TRANSFER,
                     IFX_DMA_CH_CHCFGR_RROAT_OFF,
                     (uint32)0u);

   /* Write the PRSEL = 0  :ChRequestSel_peripheral  */
   IFX_GTM_WRITE_REG(MODULE_DMA.CH[Channel].CHCFGR.U,
                     (uint32)IFX_KNWHAL_DMA_PERIPHERAL,
                     (uint32)IFX_DMA_CH_CHCFGR_PRSEL_OFF,
                     (uint32)0u);

   /* Write the DMA Prio = 0  :Low priority  */
   IFX_GTM_WRITE_REG(MODULE_DMA.CH[Channel].CHCFGR.U,
                     (uint32)IFX_KNWHAL_DMA_PRIORITY,
                     (uint32)IFX_DMA_CH_CHCFGR_DMAPRIO_OFF,
                     (uint32)0u);

   /* Write the CHMODE (Single  Mode) */
   IFX_GTM_WRITE_REG(MODULE_DMA.CH[Channel].CHCFGR.U,
                     (uint32)IFX_KNWHAL_DMA_MODE_CONTINUOUS,
                     (uint32)IFX_DMA_CH_CHCFGR_CHMODE_OFF,
                     (uint32)0u);
   Mcal_DmaCfgNoOfMovesPerTransfer(Channel, 1U);

   /* 16 bit DMA transfer */
   Mcal_DmaSetDataWidth(Channel, 1U);

   /* Set ADICR register with the data */
   Mcal_DmaSetAdicr(Channel, (uint32)KNWHAL_DMA_CONFIG);

   /* !Comment: Configuration of DMA Source Address        */
   Mcal_DmaSetSourceAddr(Channel,
                         KNWHAL_u32DMA_KNOCK_SAMPLE_SADR);

}
/*lint -restore */
#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
