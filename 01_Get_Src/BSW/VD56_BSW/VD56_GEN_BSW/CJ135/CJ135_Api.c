/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Api.c                                                                                     */
/* !Description     : Apis functions                                                                                  */
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
 * %PID: P2017_BSW:0A188673.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_SpiM.h"
#include "CJ135_Spi.h"
#include "CJ135_Types.h"
#include "CJ135_Cfg.h"


#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"



/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidInit                                                                                       */
/* !Description : Initialize all internal variables                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidInit(void)
{
   uint8_least u8LocChannel;

   CJ135_strData *pLocStrData;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];

      pLocStrData->u8InstanceNumber = u8LocChannel;

      /*************************************************/
      /* reset all data                                */
      /*************************************************/
      CJ135_vidSpiM_Init(&CJ135_akstrConfig[u8LocChannel], pLocStrData);

      CJ135_vidSpiInit(&CJ135_akstrConfig[u8LocChannel], pLocStrData);

      pLocStrData->enuInternalSequencerState = CJ135_STATE_RESET_OR_STARTUP;
      pLocStrData->enuInternalRamSequencerState = CJ135_STATE_RESET_OR_STARTUP;

      pLocStrData->u8RegisterCheckCounter    = 0; /* Don t care as it is initialized before each use */
      pLocStrData->u8RegisterInitCounter     = CJ135_u8REGISTER_INIT_NUMBER_OF_TRY;

      /* By default, we have no reported fault */
      pLocStrData->bFault      = FALSE;

      /* no IRQ shall be sent just after init*/
      pLocStrData->bSendFirstIRQ=FALSE;
      pLocStrData->bWaitForIRQ=FALSE;
      pLocStrData->bModeRead=FALSE;

      pLocStrData->bSchedulerStarted=FALSE;

   }
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtWriteMode                                                                                  */
/* !Description : Launches a request to move into udtState state                                                      */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtWriteMode(CJ135_tenuChipState udtState)
{
   CJ135_strData *pLocStrData;
   CJ135_tenuChipState udtLocalChipState;
   Std_ReturnType udtLocalRetVal;
   uint8_least u8LocChannel; 

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];
      udtLocalChipState = pLocStrData->enuInternalSequencerState;

      if ( (udtState == CJ135_STATE_RESET_OR_STARTUP)
        || (udtState >= CJ135_STATE_HW_FAILURE)
        || (udtState == CJ135_STATE_FAILUREMODE1)
        ||((udtLocalChipState == CJ135_STATE_IDLEMODE1)&&(udtState != CJ135_STATE_SWITCHON)&&(udtState != CJ135_STATE_IDLEMODE1))
        ||((udtLocalChipState == CJ135_STATE_FAILUREMODE1)&&(udtState != CJ135_STATE_IDLEMODE1))
        ||((udtState == CJ135_STATE_IDLEMODE1)&&(udtLocalChipState != CJ135_STATE_FAILUREMODE1)&&(udtLocalChipState != CJ135_STATE_IDLEMODE1))
        ||(pLocStrData->enuSpiMRegisterInitialized != CJ135_REGISTER_INIT_DONE))
      {
         udtLocalRetVal = E_NOT_OK;
      }
      else
      {
         udtLocalRetVal = E_OK;
         pLocStrData->u16ExpectedRegMode = CJ135_u16SET_TAKEDATA(CJ135_u16CLEAR_MODE(pLocStrData->u16ExpectedRegMode)|CJ135_u16SHIFT_MODE(udtState));
         pLocStrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_WRITE_MODE] = TRUE;
         if ((udtLocalChipState == CJ135_STATE_IDLEMODE1)||(udtLocalChipState == CJ135_STATE_FAILUREMODE1))
         {
            pLocStrData->bSendFirstIRQ=TRUE;
         }
      }
   }

   return (udtLocalRetVal);
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtReadMode                                                                                   */
/* !Description : Returns the current state of the CJ135 hardware component.                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtReadMode(CJ135_tenuChipState* pudtState)
{
   uint8_least u8LocChannel;
   CJ135_strData *pLocStrData;
   Std_ReturnType udtLocalRetVal;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];
      if (pLocStrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_DONE)
      {
         *pudtState = pLocStrData->enuInternalSequencerState;
         udtLocalRetVal = E_OK;
      }
      else
      {
         udtLocalRetVal = E_NOT_OK;
      }
   }

   return (udtLocalRetVal);
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtGetProbeTemp                                                                               */
/* !Description : Returns the resistance value meaning the temperature                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtGetProbeTemp(uint16* pu16RieResistor)
{
   uint8_least u8LocChannel;
   CJ135_strData *pLocStrData;
   CJ135_tenuChipState udtLocalChipState;
   Std_ReturnType udtLocalRetVal;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];
      udtLocalChipState = pLocStrData->enuInternalRamSequencerState;

      if ((pLocStrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_DONE)
         &&((udtLocalChipState == CJ135_STATE_WARMUP)||(udtLocalChipState == CJ135_STATE_NORMAL3)))
      {
         udtLocalRetVal = E_OK;

         if (udtLocalChipState == CJ135_STATE_WARMUP)
         {
            *pu16RieResistor = pLocStrData->u16RieWU;
         }
         else if (udtLocalChipState == CJ135_STATE_NORMAL3)
         {
            *pu16RieResistor = pLocStrData->u16Rie;
         }
      }
      else
      {
         udtLocalRetVal = E_NOT_OK;
      }
   }

   return (udtLocalRetVal);
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtGetLambdaInformation                                                                       */
/* !Description : Returns the richness                                                                                */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtGetLambdaInformation(sint16* ps16IpPumpingCurrent)
{
   uint8_least u8LocChannel;
   CJ135_strData *pLocStrData;
   CJ135_tenuChipState udtLocalChipState;
   Std_ReturnType udtLocalRetVal;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];
      udtLocalChipState = pLocStrData->enuInternalRamSequencerState;

      if ((pLocStrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_DONE)
         &&(udtLocalChipState == CJ135_STATE_NORMAL3))
      {
         udtLocalRetVal = E_OK;

         *ps16IpPumpingCurrent = pLocStrData->s16Ipeff;
      }
      else
      {
         udtLocalRetVal = E_NOT_OK;
      }
   }

   return (udtLocalRetVal);
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtWriteReferenceCurrent                                                                      */
/* !Description : Launches a request to configure the pump reference current                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtWriteReferenceCurrent(uint8 u8TRIMSQrValue, uint16 u16REFPATValue)
{
   uint8_least u8LocChannel;
   CJ135_strData *pLocStrData;
   Std_ReturnType udtLocalRetVal;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];

      if (pLocStrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_DONE)
      {
         udtLocalRetVal = E_OK;

         pLocStrData->u16ExpectedRegRefpat = u16REFPATValue;
         pLocStrData->u16ExpectedRegTrim = CJ135_u16CLEAR_TRIMSQR(pLocStrData->u16ExpectedRegTrim)|CJ135_u16SHIFT_TRIMSQR(u8TRIMSQrValue);
         pLocStrData->u16ExpectedRegConfigDsp = CJ135_u16SET_RESREG_RESDSP(pLocStrData->u16ExpectedRegConfigDsp);
         pLocStrData->u16ExpectedRegMode = CJ135_u16SET_TAKEDATA(pLocStrData->u16ExpectedRegMode);

         pLocStrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_UPDATE_CONF_REGISTER] = TRUE;
         pLocStrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_WRITE_MODE] = TRUE;
      }
      else
      {
         udtLocalRetVal = E_NOT_OK;
      }
   }

   return (udtLocalRetVal);
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_udtWritePumpCurrent                                                                           */
/* !Description : Launches a request to configure the ISQ current                                                     */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
Std_ReturnType CJ135_udtWritePumpCurrent(uint8 u8TRIMSQValue)
{
   uint8_least u8LocChannel;
   CJ135_strData *pLocStrData;
   Std_ReturnType udtLocalRetVal;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData = &CJ135_astrData[u8LocChannel];

      if (pLocStrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_DONE)
      {
         udtLocalRetVal = E_OK;

         pLocStrData->u16ExpectedRegTrim = CJ135_u16CLEAR_TRIMSQ(pLocStrData->u16ExpectedRegTrim)|CJ135_u16SHIFT_TRIMSQ(u8TRIMSQValue);
         pLocStrData->u16ExpectedRegConfigDsp = CJ135_u16SET_RESREG_RESDSP(pLocStrData->u16ExpectedRegConfigDsp);
         pLocStrData->u16ExpectedRegMode = CJ135_u16SET_TAKEDATA(pLocStrData->u16ExpectedRegMode);

         pLocStrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_UPDATE_CONF_REGISTER] = TRUE;
         pLocStrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_WRITE_MODE] = TRUE;
      }
      else
      {
         udtLocalRetVal = E_NOT_OK;
      }
   }

   return (udtLocalRetVal);
}

#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
