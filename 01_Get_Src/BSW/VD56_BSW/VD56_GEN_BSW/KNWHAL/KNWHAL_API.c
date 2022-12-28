/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNWHAL_API.c                                            */
/* !Description     : API of the KNWHAL component                             */
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
 * %PID: P2017_BSW:0A170706.A-SRC;5 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "std_types.h"
#include "Std_Limits.h"
#include "knwhal.h"
#include "Mcal_DmaLib.h"
#include "KNWHAL_I.h"
#include "CRKHAL.h"
#include "KNWHAL_Cfg.h"
#include "KNWHAL_gtm.h"
#include "KNWHAL_Dsadc_Cfg.h"
#include "IfxGtm_Ccu.h"
#include "SWFAIL.h"

#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"

/*lint -esym(960,17.4) */
/*lint -save -e718 */
/*lint -save -e746 */
/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidInit / D                                          */
/*                                                                            */
/* !Description  : KNWHAL_vidInit shall initialize all internal variables     */
/*                 of the KNWHAL component.                                   */
/*                 DSADC and DMA channels used for knock acquisitions         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidInit(void)
{
   KNWHAL_bKnwInitialized          = (boolean)FALSE;
   KNWHAL_u8SamplingWinNr          = (uint8)UINT8_MIN;
   KNWHAL_u16KnockSamplePeriod     = KNWHAL_u16DEFAULT_SAMPLE_PERIOD;
   KNWHAL_u32SampleTblAddress      = (uint32)UINT32_MIN;
   KNWHAL_u32SampleTblMaxSize      = (uint32)UINT32_MIN;
   KNWHAL_u32SamplingWinTblAddress = (uint32)UINT32_MIN;
   KNWHAL_u32SamplingWinIdxTblAddr = (uint32)UINT32_MIN;
   KNWHAL_u8SamplingWinIdx         = UINT8_MIN;
   KNWHAL_bDigitalWindow           = FALSE;
   #if (KNWHAL_coENA_HW_GAIN_SELECTION == KNWHAL_coGAIN_SELECTION_ENABLED)
   KNWHAL_vidWriteGainOutputLevel(KNWHAL_u8DEF_INP_STAGE_GAIN_IDX);
   #endif
   KNWHAL_vidDeactivateResources();
   KNWHAL_vidGetOsr(KNWHAL_u16KnockSamplePeriod);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_udtSamplingWinTrigger / D                            */
/*                                                                            */
/* !Description  : KNWHAL_udtSamplingWinTrigger shall trigger the knocking    */
/*                 acquisitions on angles specified by the other KNWHAL APIs  */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType KNWHAL_udtSamplingWinTrigger(void)
{
   Std_ReturnType udtLocalStatus;
   Dma_StatusType blocalItFlag;
   uint16         u16Local_counter;
   boolean        bLocalAcqRunning;
   boolean        bLocalIsSynchronized;


   udtLocalStatus = CRKHAL_udtReadStatus(CRKHAL_u8SYNCHRONISED,
                                         &bLocalIsSynchronized);
   if (udtLocalStatus != E_OK)
   {
      udtLocalStatus =
         CAMHAL_udtReadStatus(KNWHAL_udtCAMHAL_CH,
                              CAMHAL_u8SYNCHRONISED, &bLocalIsSynchronized);
      if (udtLocalStatus != E_OK)
      {
         bLocalIsSynchronized = (boolean)FALSE;
      }
   }
   bLocalAcqRunning = KNWHAL_bKnwAcquisitionRunning;
   if (  (bLocalIsSynchronized != (boolean)FALSE)
      && (KNWHAL_bKnwInitialized != (boolean)FALSE)
      && (bLocalAcqRunning == (boolean)FALSE) )
   {
      KNWHAL_bKnwAcquisitionRunning = (boolean)TRUE;
      KNWHAL_vidInitSamplePeriod();

      KNWHAL_GtmEnable();

      /************************************************************************/
      /* !Comment: Configuration of DMA_KNW_PERIOD_ACQ_CH                     */
      /************************************************************************/
      KNWHAL_vidInitDma(KNWHAL_snDMA_KNOCK_SAMPLE_CH);

      /* !Comment: Configuration of DMA Source Address                        */
      Mcal_DmaSetDestAddr(KNWHAL_snDMA_KNOCK_SAMPLE_CH,
                          KNWHAL_u32SampleTblAddress);

      /* !Comment: Configuration of Number of DMA Transfers                   */
      Mcal_DmaSetTxCount(KNWHAL_snDMA_KNOCK_SAMPLE_CH,
                         KNWHAL_u32SampleTblMaxSize);
      /* !Comment: Clear of DMA Interrupt Flag                                */
      blocalItFlag = (Dma_StatusType)(Mcal_DmaGetIntStatus(KNWHAL_snDMA_KNOCK_SAMPLE_CH) );
      if (blocalItFlag != (Dma_StatusType)FALSE)
      {
         Mcal_DmaChClrIntrFlags(KNWHAL_snDMA_KNOCK_SAMPLE_CH);
      }
      /* !Comment: Enable of DMA Transfers                                    */
      Mcal_DmaEnableHwTransfer(KNWHAL_snDMA_KNOCK_SAMPLE_CH);

      /* Enable ADC interrupt */
      IfxDsadc_EnableInterrupt(KNWHAL_snDSADCDRV_KNOCK_CONVERTER,
                               KNWHAL_snDMA_KNOCK_SAMPLE_CH);
      /* !Comment: Programing of angular alarm                                */
      CRKHAL_vidEnableAlarmNotif(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN);
      CRKHAL_vidActivateAlarmMode(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN, MODE_OUTPUT_1);

      if ( ( ( (uint16 *)KNWHAL_u32SamplingWinTblAddress)[0u]) >= KNWHAL_u16_1_DEG_FOR_MOD_ON)
      {
         u16Local_counter = ( ( (uint16 *)KNWHAL_u32SamplingWinTblAddress)[0u]) - KNWHAL_u16_1_DEG_FOR_MOD_ON;
      }
      else
      {
         u16Local_counter = ( ( (uint16 *)KNWHAL_u32SamplingWinTblAddress)[0u]) + (KNWHAL_u16ENGINE_CYCLE - KNWHAL_u16_1_DEG_FOR_MOD_ON);
      }

      KNWHAL_bKnwModulatorOnWindow = (boolean)TRUE;
      CRKHAL_vidSetAbsAlarm(KNWHAL_u8CRKHAL_ALARM_KNOCK_WIN,
                            u16Local_counter);
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
   }
   return(udtLocalStatus);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidWriteSamplePeriod / D                             */
/*                                                                            */
/* !Description  : To be taken into account, an update of the sampling period */
/*                 has to be followed by a new call to                        */
/*                 KNWHAL_TriggerAcquisitions                                 */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidWriteSamplePeriod
(
   uint16 u16SamplePeriod
)
{
   if (u16SamplePeriod != 0U)
   {
      if (KNWHAL_u16KnockSamplePeriod != u16SamplePeriod)
      {
         KNWHAL_u16KnockSamplePeriod = u16SamplePeriod;
         /* Check the closest */
         KNWHAL_vidGetOsr(KNWHAL_u16KnockSamplePeriod);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}
/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidSetSamplingWinIdxTbl / A                          */
/*                                                                            */
/* !Description  : KNWHAL_vidSetSamplingWinIdxTbl shall write the address of  */
/*                 the table where acquisition indexes shall be saved.        */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidSetSamplingWinIdxTbl
(
   uint32 *pau32SamplingWinIdxTbl
)
{
   KNWHAL_u32SamplingWinIdxTblAddr = (uint32)pau32SamplingWinIdxTbl;
   if (  (KNWHAL_u32SamplingWinTblAddress != (uint32)UINT32_MIN)
      && (KNWHAL_u32SampleTblAddress != (uint32)UINT32_MIN) )
   {
      KNWHAL_bKnwInitialized = (boolean)TRUE;
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidSetSampleTblPrms / A                              */
/*                                                                            */
/* !Description  : KNWHAL_vidSetSampleTblPrms shall write the address and the */
/*               size of the table where knocking acquisitions shall be saved */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidSetSampleTblPrms
(
   uint16 *pau16SampleTbl,
   uint32  u32SampleTblMaxSize
)
{
   KNWHAL_u32SampleTblAddress = (uint32)pau16SampleTbl;
   KNWHAL_u32SampleTblMaxSize = u32SampleTblMaxSize;
   if (KNWHAL_u32SamplingWinTblAddress != (uint32)UINT32_MIN)
   {
      if (KNWHAL_u32SamplingWinIdxTblAddr != (uint32)UINT32_MIN)
      {
         KNWHAL_bKnwInitialized = (boolean)TRUE;
      }
   }
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_udtSetSamplingWinPrms / A                            */
/*                                                                            */
/* !Description  : KNWHAL_vidSetSamplingWinPrms shall write the address of the*/
/*                 table containing angles of beginnings and ends of knocking */
/*                 windows                                                    */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType KNWHAL_udtSetSamplingWinPrms
(
   uint16 *pau16SamplingWinTbl,
   uint8   u8SamplingWinNr
)
{
   Std_ReturnType udtLocalStatus;


   if (u8SamplingWinNr != (uint8)UINT8_MIN)
   {
      KNWHAL_u32SamplingWinTblAddress = (uint32)pau16SamplingWinTbl;
      KNWHAL_u8SamplingWinNr          = u8SamplingWinNr;

      if (KNWHAL_u32SampleTblAddress != (uint32)UINT32_MIN)
      {
         if (KNWHAL_u32SamplingWinIdxTblAddr != (uint32)UINT32_MIN)
         {
            KNWHAL_bKnwInitialized = (boolean)TRUE;
         }
      }
      udtLocalStatus = E_OK;
   }
   else
   {
      udtLocalStatus = E_NOT_OK;
   }
   return(udtLocalStatus);
}

/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_udtWriteInputStageGain / A                           */
/*                                                                            */
/* !Description  : KNWHAL_udtWriteInputStageGain shall modify levels of output*/
/*                 pins linked to knocking input stage gain. The pin levels   */
/*                 shall correspond to the gain targeted by the input argument*/
/*                 <u8InputStageGain>                                         */
/*                                                                            */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
Std_ReturnType KNWHAL_udtWriteInputStageGain
(
   uint8 u8InputStageGainIdx
)
{
   #if (KNWHAL_coENA_HW_GAIN_SELECTION == KNWHAL_coGAIN_SELECTION_ENABLED)
   Std_ReturnType udtLocalStatus;
   uint8          u8LocalGainValue;

   udtLocalStatus = E_NOT_OK;

   if (KNWHAL_bKnwAcquisitionRunning == (boolean)FALSE)
   {
      if (u8InputStageGainIdx < KNWHAL_u8NUMBER_OF_GAINS)
      {
         u8LocalGainValue = u8InputStageGainIdx;
         udtLocalStatus   = E_OK;
      }
      else
      {
         u8LocalGainValue = KNWHAL_u8DEF_INP_STAGE_GAIN_IDX;
         SWFAIL_vidSoftwareErrorHook();
      }
      KNWHAL_vidWriteGainOutputLevel(u8LocalGainValue);
   }

   return(udtLocalStatus);

   #else /* if (KNWHAL_coENA_HW_GAIN_SELECTION == KNWHAL_coGAIN_SELECTION_ENABLED) */
   SWFAIL_vidSoftwareErrorHook();
   return(E_NOT_OK);

   #endif /* if (KNWHAL_coENA_HW_GAIN_SELECTION == KNWHAL_coGAIN_SELECTION_ENABLED) */
}
/*lint -restore */
#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
