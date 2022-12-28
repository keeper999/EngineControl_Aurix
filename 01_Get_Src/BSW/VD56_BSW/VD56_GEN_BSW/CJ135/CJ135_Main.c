/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Main.c                                                                                    */
/* !Description     : Main function                                                                                   */
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
 * %PID: P2017_BSW:0A188675.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_SpiM.h"
#include "CJ135_Spi.h"
#include "CJ135_Types.h"
#include "CJ135_Cfg.h"
#include "SchM_CJ135.h"


#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"

LOCAL_INLINE void CJ135_vidPeriodicReadModes(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
LOCAL_INLINE void CJ135_vidState_RESET_OR_STARTUP(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
LOCAL_INLINE void CJ135_vidState_IDLEMODE1(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
LOCAL_INLINE void CJ135_vidState_SWITCHON(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
LOCAL_INLINE void CJ135_vidState_WARMUP(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
LOCAL_INLINE void CJ135_vidState_NORMAL3(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
LOCAL_INLINE void CJ135_vidState_FAILUREMODE1(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidMainFunction                                                                               */
/* !Description : Periodic main function for all CJ135 (called on a 10ms recurrence)                                  */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidMainFunction(void)
{
   uint8_least    u8LocChannel;
   CJ135_strData *pLocStrData;
   CJ135_tstrConfig const *pLockstrConfig;

   for (u8LocChannel = 0; u8LocChannel < CJ135_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData    = &CJ135_astrData[u8LocChannel];
      pLockstrConfig = &CJ135_akstrConfig[u8LocChannel];

      if (pLocStrData->bSchedulerStarted == FALSE)
      {
         CJ135_vidPeriodicFunction(pLockstrConfig, pLocStrData);
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidInstanceMainFunction                                                                       */
/* !Description : Periodic main function for only one CJ135 (called after IRQ falling detection)                      */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidInstanceMainFunction(uint8 u8Instance)
{
   CJ135_vidPeriodicFunction(&CJ135_akstrConfig[u8Instance], &CJ135_astrData[u8Instance]);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidPeriodicFunction                                                                           */
/* !Description : Periodic main function for CJ135 (called every 10ms at startup or after each IRQ falling detection) */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidPeriodicFunction(const CJ135_tstrConfig *pkstrConfig,
                                            CJ135_strData          *pstrData)
{
   /* Set request for read modes */
   CJ135_vidPeriodicReadModes(pkstrConfig, pstrData);
   /* reset the SPI error counter allowed by period */
   CJ135_vidSpiResetErrorCounter(pkstrConfig, pstrData);
   /* Launch SPI request sequences */
   CJ135_vidSpiM_Manager(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* Internal function                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidPeriodicReadModes                                                                          */
/* !Description : Periodic readings of the modes of the CJ135                                                         */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidPeriodicReadModes(const CJ135_tstrConfig *pkstrConfig,
                                            CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_MODES] = TRUE;
   pstrData->bModeRead = FALSE;
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidStateMachineMain                                                                           */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidStateMachineMain(const CJ135_tstrConfig *pkstrConfig,
                                            CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   switch(pstrData->enuInternalRamSequencerState)
   {
      case CJ135_STATE_RESET_OR_STARTUP:
         break;

      case CJ135_STATE_IDLEMODE1:
         if (pstrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_NOT_DONE)
         {
            pstrData->enuSpiMRegisterInitialized = CJ135_REGISTER_INIT_RUNNING;
            pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_INIT_CONF_REGISTER] = TRUE;
            pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_CONF_REGISTER] = TRUE;
         }
         /* Automatically switch to Switch On mode if init has been correctly done */
         if (pstrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_DONE)
         {
            pstrData->u16ExpectedRegMode = CJ135_u16SET_TAKEDATA(CJ135_u16CLEAR_MODE(pstrData->u16ExpectedRegMode)|CJ135_u16SHIFT_MODE(CJ135_STATE_SWITCHON));
            pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_WRITE_MODE] = TRUE;
            pstrData->bSendFirstIRQ=TRUE;
         }
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_DIAGNOSTIC] = TRUE;
         break;

      case CJ135_STATE_SWITCHON:
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_DIAGNOSTIC] = TRUE;
         break;

      case CJ135_STATE_WARMUP:
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_TEMP] = TRUE;
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_DIAGNOSTIC] = TRUE;
         break;

      case CJ135_STATE_NORMAL3:
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_RICHNESS_TEMP] = TRUE;
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_DIAGNOSTIC] = TRUE;
         break;

      case CJ135_STATE_FAILUREMODE1:
         pstrData->abSpiM_SeqRequest[CJ135_SPIM_SEQ_READ_DIAGNOSTIC] = TRUE;
         break;

      case CJ135_STATE_HW_FAILURE:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;

   }
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidStateMachinePost                                                                           */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidStateMachinePost(const CJ135_tstrConfig *pkstrConfig,
                               CJ135_strData          *pstrData)
{
   switch(pstrData->enuInternalRamSequencerState)
   {
      case CJ135_STATE_RESET_OR_STARTUP:
         CJ135_vidState_RESET_OR_STARTUP(pkstrConfig, pstrData);
         break;

      case CJ135_STATE_IDLEMODE1:
         CJ135_vidState_IDLEMODE1(pkstrConfig, pstrData);
         break;

      case CJ135_STATE_SWITCHON:
         CJ135_vidState_SWITCHON(pkstrConfig, pstrData);
         break;

      case CJ135_STATE_WARMUP:
         CJ135_vidState_WARMUP(pkstrConfig, pstrData);
         break;

      case CJ135_STATE_NORMAL3:
         CJ135_vidState_NORMAL3(pkstrConfig, pstrData);
         break;

      case CJ135_STATE_FAILUREMODE1:
         CJ135_vidState_FAILUREMODE1(pkstrConfig, pstrData);
         break;

      case CJ135_STATE_HW_FAILURE:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidState_RESET_OR_STARTUP                                                                     */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidState_RESET_OR_STARTUP(const CJ135_tstrConfig *pkstrConfig,
                                            CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   COMPILER_UNUSED_PARAMETER(pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidState_IDLEMODE1                                                                            */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidState_IDLEMODE1(const CJ135_tstrConfig *pkstrConfig,
                                              CJ135_strData          *pstrData)
{
   Std_ReturnType udtLocalRetVal;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   if (pstrData->enuSpiMRegisterInitialized == CJ135_REGISTER_INIT_RUNNING)
   {
      udtLocalRetVal = CJ135_udtCheckConfig(pstrData);

      if (udtLocalRetVal == E_OK)
      {
         pstrData->enuSpiMRegisterInitialized = CJ135_REGISTER_INIT_DONE;
      }
      else
      {
         pstrData->enuSpiMRegisterInitialized = CJ135_REGISTER_INIT_FAIL;
      }
   }

   CJ135_vidSendFirstIRQ(pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidState_SWITCHON                                                                             */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidState_SWITCHON(const CJ135_tstrConfig *pkstrConfig,
                                                      CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   COMPILER_UNUSED_PARAMETER(pstrData);
}


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidState_WARMUP                                                                               */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidState_WARMUP(const CJ135_tstrConfig *pkstrConfig,
                                                        CJ135_strData          *pstrData)
{
   Std_ReturnType udtLocalRetVal;

   COMPILER_UNUSED_PARAMETER(udtLocalRetVal);

   udtLocalRetVal = CJ135_udtCalculateRie(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidState_NORMAL3                                                                              */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidState_NORMAL3(const CJ135_tstrConfig *pkstrConfig,
                                                         CJ135_strData          *pstrData)
{
   Std_ReturnType udtLocalRetVal;

   COMPILER_UNUSED_PARAMETER(udtLocalRetVal);

   udtLocalRetVal = CJ135_udtCalculateRie(pkstrConfig, pstrData);
   udtLocalRetVal = CJ135_udtCalculateIpeff(pkstrConfig, pstrData);
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidState_FAILUREMODE1                                                                         */
/* !Description : State machine of the CJ135                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
LOCAL_INLINE void CJ135_vidState_FAILUREMODE1(const CJ135_tstrConfig *pkstrConfig,
                                        CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   CJ135_vidSendFirstIRQ(pstrData);
}




#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
