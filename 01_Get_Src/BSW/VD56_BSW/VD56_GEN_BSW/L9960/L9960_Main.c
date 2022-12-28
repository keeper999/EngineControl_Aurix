/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_Main.c                                                                                    */
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
 * %PID: LIBEMB:A6104.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Pwm.h"
#include "L9960.h"
#include "L9960_Private.h"
#include "L9960_SpiM.h"
#include "L9960_Spi.h"
#include "L9960_Types.h"
#include "L9960_Cfg.h"
#include "SchM_L9960.h"


#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"

LOCAL_INLINE void L9960_vidStateMachineMain(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_HWSC_START(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_HWSC_RUNNING(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_REGISTERS_INIT_START(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_REGISTERS_INIT_RUNNING(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_REGISTERS_CHECK_RUNNING(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_ENABLE(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_DISABLE(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidState_TRISTATE(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);

LOCAL_INLINE void L9960_vidLeaveTristateModeTimer(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
LOCAL_INLINE void L9960_vidTreatDiagnostics(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidMainFunction                                                                               */
/* !Description : Periodic main function for L9960                                                                    */
/*                DGOHAL according to detected fault.                                                                 */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidMainFunction(void)
{
   uint8_least    u8LocChannel;
   L9960_strData *pLocStrData;
   L9960_tstrConfig const *pLockstrConfig;
   /* local copy of shared data pstrData->u8SpiDiagnostic */
   uint8 u8LocSpiError;


   for (u8LocChannel = 0; u8LocChannel < L9960_u8NB_OF_DEVICE; u8LocChannel++)
   {
      pLocStrData    = &L9960_astrData[u8LocChannel];
      pLockstrConfig = &L9960_akstrConfig[u8LocChannel];

      /* Decrement the timer used to stay a minimum time in tristate mode                  */
      /* It is called independently of the state machine, to have a determinist delay      */
      /* It must be called before perform diagnostic, otherwise we risk to decrement by 1  */
      /* the timer when we enter in tristate mode, and so delay will be one time too small */
      L9960_vidLeaveTristateModeTimer(pLockstrConfig, pLocStrData);

      /*************************************************************************************/
      /* Treat previous diagnostic result before launching a new diagnostic                */
      /*************************************************************************************/
      /* Diagnostic are done only if result are available of course                        */
      /*                                                                                   */
      /* bOnDiagnosticIsAvailable is a shared data but, we consider the read as atomic     */
      /*   and if bOnDiagnosticIsAvailable == TRUE, then no new diag wil be launched       */
      /*   and, in the if branch, bOnDiagnosticIsAvailable will be not written by ISR      */
      /*   no protection is needed                                                         */
      if ( (pLocStrData->bOnDiagnosticIsAvailable == TRUE)
            || (pLocStrData->bOffDiagnosticIsAvailable == TRUE) )
      {
         L9960_vidTreatDiagnostics(pLockstrConfig, pLocStrData);
         /* Diagnostic are treated */
         pLocStrData->bOnDiagnosticIsAvailable = FALSE;
         pLocStrData->bOffDiagnosticIsAvailable = FALSE;
      }
      
      /* register 5 is treated outside the other diagnostic, because this register read could */
      /* occurs in different sequences like read back register configurations                 */
      if(pLocStrData->bSpiMNewRegState5 == TRUE)
      {
         L9960_vidDecodeRegState5(pLockstrConfig, pLocStrData);
         /* TODO : if bCCFault == 1 */
         /* maybe do a consitency check with Bridge enable (to prevent read CC=1 due to a SPI glitch) */
         /* if CC is confirmed, then launch a leave tristate mode immediatly */
         /* Be careful, we can't read seeral time the CC bit to confirm the fault, because this bit is */
         /* cleared on State 5 register read */
         pLocStrData->bSpiMNewRegState5 = FALSE;
      }
      
      /***********************************************************/
      /* Treat SPI ERROR                                         */
      /***********************************************************/
      /* SPi error is treat here, because in case fo SPI problem L9960_vidTreatDiagnostics is not called  */
      /* due to the fact that sequence is not finish and bOn/OffDiagnosticIsAvailable flag are not set.   */
      /*                                                                                                  */
      /* Read data shared with SPI interrupts                                                             */
      /* u8SpiDiagnostic must be reset to L9960_u8SPI_OK  not count this fault again on next period       */
      /* This data is shared, because it may be updated by another sequence than the Diagnostic one       */
      SchM_Enter_L9960_SPI_ISR();
      u8LocSpiError                = pLocStrData->u8SpiDiagnostic;
      pLocStrData->u8SpiDiagnostic = L9960_u8SPI_OK;
      SchM_Exit_L9960_SPI_ISR();

      if (u8LocSpiError == L9960_u8SPI_OK)
      {
         DGOHAL_vidWrite(pLockstrConfig->udtDgohalEcuChannel, DGOHAL_bfVALID_L9960_SPI_ERROR, 0);
      }
      else
      {
         DGOHAL_vidWrite(pLockstrConfig->udtDgohalEcuChannel, DGOHAL_bfVALID_L9960_SPI_ERROR, DGOHAL_bfFAULT_L9960_SPI_ERROR);
      }
     
      L9960_vidSpiM_MainFunction(pLockstrConfig, pLocStrData);
      L9960_vidStateMachineMain(pLockstrConfig, pLocStrData);
      /* reset the SPI error counter allowed by period */
      L9960_vidSpiResetErrorCounter(pLockstrConfig, pLocStrData);
      /* Launch SPI request sequences */
      L9960_vidSpiM_Manager(pLockstrConfig, pLocStrData);

   }

}

/**********************************************************************************************************************/
/* Internal function                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/* !FuncName    : L9960_vidStateMachineMain                                                                           */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidStateMachineMain(const L9960_tstrConfig *pkstrConfig,
                                            L9960_strData          *pstrData)
{
   switch(pstrData->enuHBridgeState)
   {
      case L9960_STATE_HWSC_START:
         /* Launch the HWSC process.                                                             */
         /* TODO ?? The first read command will be send jsut after the launch and result should  */
         /* be -in progress- so the first read may be delayed...                                 */ 
         /* but should increasethe SW design complexity                                          */ 
         L9960_vidState_HWSC_START(pkstrConfig, pstrData);
         break;
         
      case L9960_STATE_HWSC_RUNNING:
         L9960_vidState_HWSC_RUNNING(pkstrConfig, pstrData);
         break;
         
      case L9960_STATE_REGISTERS_INIT_START:
         L9960_vidState_REGISTERS_INIT_START(pkstrConfig, pstrData);
         break;

      case L9960_STATE_REGISTERS_INIT_RUNNING:
         L9960_vidState_REGISTERS_INIT_RUNNING(pkstrConfig, pstrData);
         break;
         
      case L9960_STATE_REGISTERS_CHECK_RUNNING:
         L9960_vidState_REGISTERS_CHECK_RUNNING(pkstrConfig, pstrData);
         break;

      case L9960_STATE_ENABLE:
         L9960_vidState_ENABLE(pkstrConfig, pstrData);
         break;
         
      case L9960_STATE_DISABLE:
         L9960_vidState_DISABLE(pkstrConfig, pstrData);
         break;
         
      case L9960_STATE_TRISTATE:
         L9960_vidState_TRISTATE(pkstrConfig, pstrData);
         break;
         
      case L9960_STATE_HW_FAILURE:
         if(pstrData->bHWSCPassed == FALSE)
         {
            /* Send periodicaly a HWSC fault to applicative SW */
            DGOHAL_vidWrite(pkstrConfig->udtDgohalEcuChannel, DGOHAL_bfVALID_L9960_HWSC, DGOHAL_bfFAULT_L9960_HWSC);
         }
         break;
         
      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
         
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_HWSC_START                                                                           */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_HWSC_START(const L9960_tstrConfig *pkstrConfig,
                                            L9960_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_HWSC] = TRUE;

   /* next state */
   pstrData->enuHBridgeState = L9960_STATE_HWSC_RUNNING;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_HWSC_RUNNING                                                                         */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_HWSC_RUNNING(const L9960_tstrConfig *pkstrConfig,
                                              L9960_strData          *pstrData)
{
   
   switch(pstrData->u8HWSCLastStatus)
   {
      case L9960_E_SPI_RUNNING:
         /* Do nothing : test in progress */
         break;
      
      case L9960_E_OK:
         /* The bridge could be used, so we initialize the registers */
         pstrData->enuHBridgeState = L9960_STATE_REGISTERS_INIT_START;
         pstrData->bHWSCPassed = TRUE;
         break;
      
      case L9960_E_SPI_ERROR:
         /* TODO: limit to N try ? */
         /* On next Mainfunction, we going to try to resend the HWSC command */
         pstrData->enuHBridgeState = L9960_STATE_HWSC_START;
         break;
   
      case L9960_E_NOT_OK:
         pstrData->enuHBridgeState = L9960_STATE_HW_FAILURE;
         pstrData->bHWSCPassed = FALSE;

         /* The bridge is already in tristate, except if the HWSC finish after the timeout */
         /* To prevent any problem, we disable the bridge, as it is not handled anymore    */
         pkstrConfig->pfvidSetDisPinToHigh();
         
         /* cut pwm output */
         Pwm_SetDutyCycle(pkstrConfig->udtPwmChannel, 0);
         Pwm_SetDutyCycle(pkstrConfig->udtDirChannel, 0);
         
         /* TODO: stop notification ? */
         break;
      
      default:
         /* what to do ?*/
         SWFAIL_vidSoftwareErrorHook();
         pstrData->enuHBridgeState = L9960_STATE_HW_FAILURE;
         pstrData->bHWSCPassed = FALSE;

         /* The bridge is already in tristate, except if the HWSC finish after the tiemout */
         /* To prevent any problem, we disable the bridge, as it is not handled anymore    */
         pkstrConfig->pfvidSetDisPinToHigh();

         /* cut pwm output */
         Pwm_SetDutyCycle(pkstrConfig->udtPwmChannel, 0);
         Pwm_SetDutyCycle(pkstrConfig->udtDirChannel, 0);
         
         /* TODO: stop notification ? */
         break;
   }
      
}
/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_REGISTERS_INIT_START                                                                 */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_REGISTERS_INIT_START(const L9960_tstrConfig *pkstrConfig,
                                                      L9960_strData          *pstrData)
{
   if (pstrData->u8RegisterInitCounter != 0)
   {
      pstrData->u16SpiMChipRegConfiguration1 = L9960_u16SetDefaultValueRegConfig1(pkstrConfig, pstrData);
      pstrData->u16SpiMChipRegConfiguration2 = L9960_u16SetDefaultValueRegConfig2(pkstrConfig, pstrData);
      pstrData->u16SpiMChipRegConfiguration3 = L9960_u16SetDefaultValueRegConfig3(pkstrConfig, pstrData);
      pstrData->u16SpiMChipRegConfiguration4 = L9960_u16SetDefaultValueRegConfig4(pkstrConfig, pstrData);
            
      pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_INIT_ALL_REGISTER] = TRUE;

      /* next state */
      pstrData->enuHBridgeState = L9960_STATE_REGISTERS_INIT_RUNNING;
   }
   else
   {
      /* To many try of init register */

      /* The bridge could not be used, so we stop its management until next reset */
      pstrData->enuHBridgeState = L9960_STATE_HW_FAILURE;

      /* The bridge shoul dbe already in tristate */
      /* But to prevent any problem, we disable the bridge, as it is not handled anymore    */
      pkstrConfig->pfvidSetDisPinToHigh();
   }
}


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_REGISTERS_INIT_RUNNING                                                               */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_REGISTERS_INIT_RUNNING(const L9960_tstrConfig *pkstrConfig,
                                                        L9960_strData          *pstrData)
{
   /* Shared adta read at begining of function to keep its consistency all along the function execution */
   L9960_tenuSpiM_RegisterState enuLocRegisterInitialized = pstrData->enuSpiMRegisterInitialized;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   if(enuLocRegisterInitialized == L9960_REGISTER_INIT_DONE)
   {
      pstrData->u8RegisterCheckCounter = L9960_u8REGISTER_CHECK_NUMBER_OF_TRY;
      pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_CHECK_ALL_REGISTER] = TRUE;
      
      /* next state */
      pstrData->enuHBridgeState = L9960_STATE_REGISTERS_CHECK_RUNNING;
   }
   else if(enuLocRegisterInitialized == L9960_REGISTER_INIT_FAIL)
   {
      pstrData->u8RegisterInitCounter--;
      L9960_vidState_REGISTERS_INIT_START(pkstrConfig, pstrData);
   }
   else
   {
      /* Nothing to do : Configuration in progress */
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_REGISTERS_CHECK_RUNNING                                                              */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_REGISTERS_CHECK_RUNNING(const L9960_tstrConfig *pkstrConfig,
                                                         L9960_strData          *pstrData)
{
   /* Shared data used twice, so to store in a local register */
   L9960_tenuSpiM_RegisterReadState enuLocRegisterRead = pstrData->enuSpiMRegisterRead;
   
   
   if(enuLocRegisterRead == L9960_REGISTER_READ_DONE)
   {
      if(L9960_udtCheckConfigValuesFromFlash(pkstrConfig, pstrData) == E_OK)
      {
         /* Initialization successful, reload the init tentative counter for next init request */
         pstrData->u8RegisterInitCounter     = L9960_u8REGISTER_INIT_NUMBER_OF_TRY;

         if (pstrData->bEnableSetpoint == TRUE)
         {
            L9960_vidEnterInEnableState(pkstrConfig, pstrData);
         }
         else
         {
            pstrData->enuHBridgeState = L9960_STATE_DISABLE;
         }
      }
      else
      {
         if(pstrData->u8RegisterCheckCounter != 0)
         {
            /* redo a read to check that error it is not due to a glitch on SPI bus */
            pstrData->u8RegisterCheckCounter--;
            pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_CHECK_ALL_REGISTER] = TRUE;
            pstrData->enuHBridgeState = L9960_STATE_REGISTERS_CHECK_RUNNING;
         }
         else
         {
            /* Register are badly configured, try to reconfigure them */
            pstrData->u8RegisterInitCounter--;
            L9960_vidState_REGISTERS_INIT_START(pkstrConfig, pstrData);
         }
      }
   }
   else if(enuLocRegisterRead == L9960_REGISTER_READ_FAIL)
   {
      if(pstrData->u8RegisterCheckCounter != 0)
      {
         /* redo a read to check that error it is not due to a glitch on SPI bus */
         pstrData->u8RegisterCheckCounter--;
         pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_CHECK_ALL_REGISTER] = TRUE;
         pstrData->enuHBridgeState = L9960_STATE_REGISTERS_CHECK_RUNNING;
      }
      else
      {
         /* Register are badly configured, try to reconfigure them */
         pstrData->u8RegisterInitCounter--;
         L9960_vidState_REGISTERS_INIT_START(pkstrConfig, pstrData);
      }
   }
   else
   {
      /* in progress: nothing to do */
      /* TODO: maybe have a timeout */
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_ENABLE                                                                               */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_ENABLE(const L9960_tstrConfig *pkstrConfig,
                                        L9960_strData          *pstrData)
{
   /***************************************************************************************/
   /* request to launch a diagnostic                                                      */
   /***************************************************************************************/
   /* Send a L9960_SPIM_SEQ_ON_DIAGNOSTIC_1 sequence, except if we had an open load fault */
   if(pstrData->bOpenLoadLastState == FALSE)
   {
      L9960_vidSpiM_StartOnDiagnosticSeq1(pkstrConfig, pstrData);
   }
   else
   {
      L9960_vidSpiM_StartOnDiagnosticSeq2(pkstrConfig, pstrData);
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_DISABLE                                                                              */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_DISABLE(const L9960_tstrConfig *pkstrConfig,
                                         L9960_strData          *pstrData)
{
   /* Send the Diag Off sequence */
   L9960_vidSpiM_StartOffStateDiagnostic(pkstrConfig, pstrData);
   
   /* TODO: allow to go to enable mode only if no over current nor over temperature detected  */
   /* as it is done on TRISTATE mode                                                          */
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidState_TRISTATE                                                                             */
/* !Description : State machine of the L9960                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidState_TRISTATE(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   /* Send the Diag Off sequence */
   pstrData->abSpiM_SeqRequest[L9960_SPIM_SEQ_OFF_DIAGNOSTIC] = TRUE;
   
   
   /* When protection delay elapse, check if conditions are met to leave tristate mode */
   if (pstrData->bLeaveTristateModeAllowed == TRUE)
   {
      /* TODO: keep this below test or not ? maybe offstate diagnostic are too long to do ? */
      if( (pstrData->bOverTemperatureFault == FALSE)
           && (pstrData->bOffDiagOverCurrentFault == FALSE) )
      {
         /* Minimum time to stay in tristate is elapsed, and L9960 left the Over temperature and */
         /* short to gnd/vbatt conditions */
            
         /* Check if applicative layer want that L9960 is disable or enable */
         if(pstrData->bEnableSetpoint != FALSE)
         {
            L9960_vidEnterInEnableState(pkstrConfig, pstrData);
         }
         else
         {
            pstrData->enuHBridgeState = L9960_STATE_DISABLE;
         }
      }
   }
   /* TODO: limit the tentative of re enable to X (tbd) time, give by the HSI requirements*/
}


/**********************************************************************************************************************/
/* !FuncName    : L9960_vidEnterInEnableState                                                                         */
/* !Description : This function enable the L9960 by setting the DIS pin to low (if authorized by safety)              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidEnterInEnableState(const L9960_tstrConfig *pkstrConfig,
                                 L9960_strData          *pstrData)
{
   /* We pass through a callout, because the DIS pin must be handled by a safety component for the throotle actuator */
   pkstrConfig->pfvidSetDisPinToLow();

   /* It is important to have:                                                                        */
   /* - 0% applied on both pin before these both call.                                                */
   /* - set DIS duty cycle before the PWM one.                                                        */
   /* With this condition, we will have no glitch on output if the Pwm period occurs ebtween the both */
   /* Pwm_SetDutyCycle calls                                                                          */
   Pwm_SetDutyCycle(pkstrConfig->udtDirChannel, pstrData->u16LastRequestedDirDutyCycle);
   Pwm_SetDutyCycle(pkstrConfig->udtPwmChannel, pstrData->u16LastRequestedPwmDutyCycle);
   
   /* next state */
   pstrData->enuHBridgeState = L9960_STATE_ENABLE;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidEnterInTristateState                                                                       */
/* !Description : This function start the disable-enable sequence                                                     */
/*                This sequence is the only one to leave a tristate mode reached due to a failure.                    */
/*                                                                                                                    */
/*                It consist to set the pin DIS to HIGH level for a time, and come back to the LOW state              */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidEnterInTristateState(const L9960_tstrConfig *pkstrConfig,
                                                L9960_strData          *pstrData)
{
   /* TODO: robustness against SPI glitch which end to call this function */
   
   /* Set DIS pin to HIGH level (disable the L9960) */
   pkstrConfig->pfvidSetDisPinToHigh();

   /* For HW, it is not needed to cut DIS and PWM, but to have a nice re-enable without glitch */
   /* we need to set pwm duty cycle to 0%                                                      */
   Pwm_SetDutyCycle(pkstrConfig->udtDirChannel, 0);
   Pwm_SetDutyCycle(pkstrConfig->udtPwmChannel, 0);

   /* Load the minimum time to stay at tristate mode */
   pstrData->u8TristateModeTimer = pkstrConfig->u8TristateTimerReload;
   
   /* Flag to detect when the above timer elapse */
   pstrData->bLeaveTristateModeAllowed = FALSE;
   
   /* Update the state machine state */
   pstrData->enuHBridgeState = L9960_STATE_TRISTATE;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidEnterInHwscStartState                                                                      */
/* !Description : This function go back to HWSC_START_STATE (after a L9960 chip reset detection)                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidEnterInHwscStartState(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   
   /* Set DIS pin to HIGH level (disable the L9960) */
   pkstrConfig->pfvidSetDisPinToHigh();

   /* For HW, it is not needed to cut DIS and PWM, but to have a nice re-enable without glitch */
   /* we need to set pwm duty cycle to 0%                                                      */
   Pwm_SetDutyCycle(pkstrConfig->udtDirChannel, 0);
   Pwm_SetDutyCycle(pkstrConfig->udtPwmChannel, 0);

   /* Update the state machine state */
   pstrData->enuHBridgeState = L9960_STATE_HWSC_START;
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidLeaveTristateModeTimer                                                                     */
/* !Description : This function handle the time to wait before allowed to leave tristate mode                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidLeaveTristateModeTimer(const L9960_tstrConfig *pkstrConfig,
                                                  L9960_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   if (pstrData->u8TristateModeTimer != 0)
   {
      pstrData->u8TristateModeTimer--;
      if (pstrData->u8TristateModeTimer == 0)
      {
         pstrData->bLeaveTristateModeAllowed = TRUE;
      }
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidTreatDiagnostics                                                                           */
/* !Description : This function treat common diagnostics                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
LOCAL_INLINE void L9960_vidTreatDiagnostics(const L9960_tstrConfig *pkstrConfig,
                                            L9960_strData          *pstrData)
{
   /* DGOHAL parameters */
   uint8 u8LocDgohalEcuValid;
   uint8 u8LocDgohalEcuFault = 0;
   uint8 u8LocDgohalActuatorValid = 0;
   uint8 u8LocDgohalActuatorFault = 0;
   
   boolean bLocEnterInTristate = FALSE;
   
   /* Share data must keep consistent during the function execution */
   boolean bLocNewRegState2 = pstrData->bSpiMNewRegState2;

   /* TODO: do a consistency check on register value  ? */

   /*****************************************************************************************/
   /* State 1 register                                                                      */
   /*****************************************************************************************/
   L9960_vidDecodeRegState1(pkstrConfig, pstrData);
   
   u8LocDgohalEcuValid = DGOHAL_bfVALID_L9960_SUPPLY_VOLTAGE | DGOHAL_bfVALID_L9960_I_LIMIT;

   /* Supply voltage error (VDD & VPS) : from L9960_vidDecodeRegState1 */
   if(pstrData->bSupplyVoltageFault == 1)
   {
      u8LocDgohalEcuFault |= DGOHAL_bfFAULT_L9960_SUPPLY_VOLTAGE;
   }
   
   /* I limitation warning (ILIM) : from L9960_vidDecodeRegState1 */
   if(pstrData->bILimitFault == 1)
   {
      u8LocDgohalEcuFault |= DGOHAL_bfFAULT_L9960_I_LIMIT;
   }

   /* Specific case of OnDiagnostic */
   if( (pstrData->bOnDiagnosticIsAvailable == TRUE)
        && (pstrData->bNgFailFault == FALSE))
   {
      /* No new error reported */
      u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OVER_CURRENT | DGOHAL_bfVALID_L9960_OVERLOAD;

      /* If bSpiMNewRegState2 == TRUE then the State2 register will be decoded few line of code below    */
      /* and Open load validity could be different espacially just afer an open load, the reg State 2    */
      /* will be read even if NGFAIL = 1                                                                 */
      if(bLocNewRegState2 != TRUE)
      {
         u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OVER_TEMPERATURE | DGOHAL_bfVALID_L9960_OPEN_LOAD;
      }
   }
   
   /* Test if a L9960 reset occured through the bHwscNotDoneFault info       */
   /* A consistency check is done with bHBridgeDisableFault and bNgFailFault */
   /* NGFAIL = 0 (HWSC not done) and BRIDGE_EN = 0 because bridge is disable */
   if( (pstrData->bHwscNotDoneFault == TRUE)
        && (pstrData->bHBridgeDisableFault == TRUE)
        && (pstrData->bNgFailFault == TRUE) )
   {
      u8LocDgohalEcuValid |= DGOHAL_bfVALID_L9960_HWSC;
      u8LocDgohalEcuFault |= DGOHAL_bfFAULT_L9960_HWSC;
      /* back to uninitialized state */
      L9960_vidEnterInHwscStartState(pkstrConfig, pstrData);
   }

   /*****************************************************************************************/
   /* State 2 register                                                                      */
   /*****************************************************************************************/
   if(bLocNewRegState2 == TRUE)
   {
      L9960_vidDecodeRegState2(pkstrConfig, pstrData);
      
      u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OVER_TEMPERATURE;
      if(pstrData->bOverTemperatureFault == TRUE)
      {
         /* TODO: if we have a spi error on dummy frame following the status 2 register read             */
         /* we may loose teh NOTSD_REG information and so no start the leave tristate mode procedure     */
         /* This case should not arrive as a Over temperature failure keep present during at least 90 ms */
         u8LocDgohalActuatorFault |= DGOHAL_bfFAULT_L9960_OVER_TEMPERATURE;

         /* Specific case of OnDiagnostic */
         /* TODO: is bNgFailFault test needed ?                                                                    */
         /*       If we read Status register 2 when bOnDiagnosticIsAvailable = TRUE, it is because NGFAIL == FALSE */
         /*       The only case on which we read Status register 2 when NGFAIL == FALSE is after an open load.     */
         /*       But how to have an open load fault, with a OT one ? And if occurs we will read OT again in next  */
         /*       MainFunction call... so maybe the (pstrData->bNgFailFault == TRUE) here is redundant.            */
         if( (pstrData->bOnDiagnosticIsAvailable == TRUE)
            && (pstrData->bNgFailFault == TRUE))
         {
            /* Not call this during off state diagnostic because Over temperature fault will         */
            /* still present at least 90ms to ensure reliabilty (refer to data sheet) and so         */
            /* Over temperature will still be detected in diable mode. and we shall not call this    */
            /* function recursively which initilaize the time to wait before to re-enable the bridge */
            bLocEnterInTristate = TRUE;
         }
      }
      
      /* This bOpenLoadDiagDone could be set to true by Diag On State */
      if(pstrData->bOpenLoadDiagDone == TRUE)
      {
         u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OPEN_LOAD;
         if(pstrData->bOpenLoadLastState == TRUE)
         {
            u8LocDgohalActuatorFault |= DGOHAL_bfFAULT_L9960_OPEN_LOAD;
         }
      }
      
      /* Clear the treatment */ 
      pstrData->bSpiMNewRegState2 = FALSE;
   }
   
   
   /*****************************************************************************************/
   /* Off State Register                                                                    */
   /*****************************************************************************************/
   /* This function could return TRUE only by Diag Off State */
   if(L9960_bDecodeDiagnosticOff(pkstrConfig, pstrData) == TRUE)
   {
      u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OPEN_LOAD | DGOHAL_bfVALID_L9960_OVER_CURRENT;
      if(pstrData->bOffDiagOverCurrentFault == TRUE)
      {
         u8LocDgohalActuatorFault |= DGOHAL_bfFAULT_L9960_OVER_CURRENT;
      }
      if(pstrData->bOffDiagOpenLoadFault == TRUE)
      {
         u8LocDgohalActuatorFault |= DGOHAL_bfFAULT_L9960_OPEN_LOAD;
      }
   }
   
   /*****************************************************************************************/
   /* Over Current register                                                                 */
   /*****************************************************************************************/
   if(pstrData->bSpiMNewRegOverCurrent == TRUE)
   {
      L9960_vidDecodeRegOverCurrent(pkstrConfig, pstrData);
      pstrData->bSpiMNewRegOverCurrent = FALSE;
      
      if( ( pstrData->bOverCurrentFault == FALSE)
          && (pstrData->bOverLoadFault == FALSE))
      {
         /* TODO: either the diag is done and we have no fault, either diag is not done */
         u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OVER_CURRENT | DGOHAL_bfVALID_L9960_OVERLOAD;
      }
      else
      {
         /* TODO: if we have a spi error on dummy frame following the over current register read         */
         /* we may loose teh NOTSD_REG information and so no start the leave tristate mode procedure     */
         /* This case could arrive as the H Bridge goes in off state, and so over current can't be       */
         /* detected anymore. In this case the H Bridge will stay at tristate until next reset ?         */
         if(pstrData->bOverCurrentFault == TRUE)
         {
            u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OVER_CURRENT | DGOHAL_bfVALID_L9960_OVERLOAD;
            u8LocDgohalActuatorFault |= DGOHAL_bfFAULT_L9960_OVER_CURRENT;
            bLocEnterInTristate = TRUE;
         }
         if (pstrData->bOverLoadFault == TRUE)
         {
            u8LocDgohalActuatorValid |= DGOHAL_bfVALID_L9960_OVER_CURRENT | DGOHAL_bfVALID_L9960_OVERLOAD;
            u8LocDgohalActuatorFault |= DGOHAL_bfFAULT_L9960_OVERLOAD;
            bLocEnterInTristate = TRUE; /* TODO: Not sure to need it */
         }
      }
   }

   
      

   /***********************************************************/
   /* Go in tristate if needed                                */
   /***********************************************************/
   if(bLocEnterInTristate == TRUE)
   {
      L9960_vidEnterInTristateState(pkstrConfig, pstrData);
   }
   /***********************************************************/
   /* Call DGOHAL Apis                                        */
   /***********************************************************/
   DGOHAL_vidWrite(pkstrConfig->udtDgohalEcuChannel, u8LocDgohalEcuValid, u8LocDgohalEcuFault);
   DGOHAL_vidWrite(pkstrConfig->udtDgohalActuatorChannel, u8LocDgohalActuatorValid, u8LocDgohalActuatorFault);

}

#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
