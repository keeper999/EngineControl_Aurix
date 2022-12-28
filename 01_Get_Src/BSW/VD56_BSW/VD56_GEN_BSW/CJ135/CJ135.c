/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135.c                                                                                         */
/* !Description     : Main file                                                                                       */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A188668.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_SpiM.h"
#include "CJ135_Spi.h"
#include "CJ135_Types.h"
#include "CJ135_Cfg.h"
#include "Dio.h"/*mockup : shall be configurable*/
#include "Gpt.h"/*mockup : shall be configurable*/
#include "Port.h"/*mockup : shall be configurable*/
#include "Icu.h"/*mockup : shall be configurable*/

#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSendFirstIRQ                                                                               */
/* !Description : Command the first /IRQ for the beginning of the sequencer                                           */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSendFirstIRQ(CJ135_strData  *pstrData)
{
   if (pstrData->bSendFirstIRQ==TRUE)
   {
      Icu_DisableEdgeDetection(IcuConf_IcuChannel_M_UEGO_IRQ);
      Icu_DisableNotification(IcuConf_IcuChannel_M_UEGO_IRQ);
      Port_SetPinDirection(PORT_23_PIN_3, PORT_PIN_OUT);/*mockup : shall be configurable*/
      Dio_WriteChannel(DioConf_DioChannel_M_UEGO_IRQ, STD_LOW);/*mockup : shall be configurable*/
      Gpt_EnableNotification(GptConf_GptChannel_CJ135_IRQ_TIMER);/*mockup : shall be configurable*/
      pstrData->bWaitForIRQ=TRUE;
      Gpt_StartTimer(GptConf_GptChannel_CJ135_IRQ_TIMER, (Gpt_ValueType)625);/*mockup : shall be configurable*/
      pstrData->bSendFirstIRQ=FALSE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidReceiveFirstIRQ                                                                            */
/* !Description : Configure the IRQ pin as input when first manually triggered IRQ has been done                      */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidReceiveFirstIRQ(CJ135_strData  *pstrData)
{
   if (pstrData->bWaitForIRQ==TRUE)
   {
      pstrData->bSchedulerStarted = TRUE;
      Gpt_DisableNotification(GptConf_GptChannel_CJ135_IRQ_TIMER);/*mockup : shall be configurable*/
      Dio_WriteChannel(DioConf_DioChannel_M_UEGO_IRQ, STD_HIGH);/*mockup : shall be configurable*/
      Port_SetPinDirection(PORT_23_PIN_3, PORT_PIN_IN);/*mockup : shall be configurable*/
      Icu_EnableNotification(IcuConf_IcuChannel_M_UEGO_IRQ);
      Icu_EnableEdgeDetection(IcuConf_IcuChannel_M_UEGO_IRQ);
      pstrData->bWaitForIRQ=FALSE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtCheckConfig                                                                                */
/* !Description : Check if registers are correctly written                                                            */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtCheckConfig(CJ135_strData  *pstrData)
{
   Std_ReturnType udtLocalRetVal;

   /* ACTUAL_MODE is not tested and takedata bit of MODE is excluded */
   if ((pstrData->u16ExpectedRegConfigDsp == pstrData->u16SpiMChipRegConfigDsp)
     &&(pstrData->u16ExpectedRegIpOff == pstrData->u16SpiMChipRegIpOff)
     &&(CJ135_u16CLEAR_TAKEDATA(pstrData->u16ExpectedRegMode) == CJ135_u16CLEAR_TAKEDATA(pstrData->u16SpiMChipRegMode))
     &&(pstrData->u16ExpectedRegRefpat == pstrData->u16SpiMChipRegRefpat)
     &&(pstrData->u16ExpectedRegSteerpat == pstrData->u16SpiMChipRegSteerpat)
     &&(pstrData->u16ExpectedRegTrim == pstrData->u16SpiMChipRegTrim)
     &&(pstrData->u16ExpectedRegUnset == pstrData->u16SpiMChipRegUnset)
     &&(pstrData->u16ExpectedRegUego0 == pstrData->u16SpiMChipRegUego0)
     &&(pstrData->u16ExpectedRegUego1 == pstrData->u16SpiMChipRegUego1)
     &&(pstrData->u16ExpectedRegUego2 == pstrData->u16SpiMChipRegUego2)
     &&(pstrData->u16ExpectedRegUego3 == pstrData->u16SpiMChipRegUego3)
     &&(pstrData->u16ExpectedRegUego4 == pstrData->u16SpiMChipRegUego4)
     &&(pstrData->u16ExpectedRegUego5 == pstrData->u16SpiMChipRegUego5)
     &&(pstrData->u16ExpectedRegUp0lean == pstrData->u16SpiMChipRegUp0lean)
     &&(pstrData->u16ExpectedRegUp0rich == pstrData->u16SpiMChipRegUp0rich)
     &&(pstrData->u16ExpectedRegFree == pstrData->u16SpiMChipRegFree))
   {
      udtLocalRetVal = E_OK;
   }
   else
   {
      udtLocalRetVal = E_NOT_OK;
   }

   return(udtLocalRetVal);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtCalculateRie                                                                               */
/* !Description : Use the parameters read in RAM to calculate Rie                                                     */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtCalculateRie(const CJ135_tstrConfig *pkstrConfig,
                                              CJ135_strData          *pstrData)
{
   Std_ReturnType udtLocalRetVal;

   pstrData->u16Rie = (uint16)(((sint32)pstrData->s16RamUrie - pstrData->s16RamUn0)*(*(pkstrConfig->pu16Rcal))/pstrData->s16RamUcal);

   pstrData->u16RieWU = pstrData->u16Rie*20/7;

   udtLocalRetVal = E_OK;

   return(udtLocalRetVal);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtCalculateIpeff                                                                             */
/* !Description : Use the parameters read in RAM to calculate Ipeff                                                   */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtCalculateIpeff(const CJ135_tstrConfig *pkstrConfig,
                                              CJ135_strData          *pstrData)
{
   Std_ReturnType udtLocalRetVal;

   pstrData->s16Mean5IP = (sint16)(((sint32)pstrData->s16RamIP1 + pstrData->s16RamIP2 + pstrData->s16RamIP3 + pstrData->s16RamIP4 + pstrData->s16RamIP5)/5);

   pstrData->s16Ipeff = (sint16)(((sint32)pstrData->s16RamUg0) * pstrData->s16Mean5IP / (*(pkstrConfig->pu16Rgnds)) * 4096 / 8325 );

   udtLocalRetVal = E_OK;

   return(udtLocalRetVal);
}

#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
