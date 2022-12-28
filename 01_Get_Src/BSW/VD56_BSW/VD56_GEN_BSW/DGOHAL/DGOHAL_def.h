/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : DGOHAL                                                                                          */
/* !Description     : Diagnostics of the ECU                                                                          */
/*                                                                                                                    */
/* !File            : DGOHAL_Def.h                                                                                    */
/* !Description     : Data definition of the DGOHAL Component                                                         */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5395989                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:DGOHAL DEF H-99052624X1608X77.A-SRC;1.4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef DGOHAL_DEF_H
#define DGOHAL_DEF_H

#include "DGOHAL_Types.h"
#include "DGOHAL_Cfg.h"
#include "DGOHAL_Co.h"

#if (DGOHAL_coCALLBACK_PRESENT == DGOHAL_coDISABLED) || (DGOHAL_coFAULT_FILTERING == DGOHAL_coDISABLED)
#include "SWFAIL.h"
#endif /* (DGOHAL_coCALLBACK_PRESENT == DGOHAL_coDISABLED) || (DGOHAL_coFAULT_FILTERING == DGOHAL_coDISABLED) */

/**********************************************************************************************************************/
/* Check that Conditionnal Compilation define are defined                                                             */
/**********************************************************************************************************************/

#ifndef DGOHAL_coENABLED
   #error The macro-constant DGOHAL_coENABLED shall be defined
#endif
#ifndef DGOHAL_coDISABLED
   #error The macro-constant DGOHAL_coDISABLED shall be defined
#endif
#ifndef DGOHAL_coFAULT_CLEAR_NOTIF
   #error The macro-constant DGOHAL_coFAULT_CLEAR_NOTIF shall be defined
#endif
#ifndef DGOHAL_coFAULT_FILTERING
   #error The macro-constant DGOHAL_coFAULT_FILTERING shall be defined
#endif
#ifndef DGOHAL_coCALLBACK_PRESENT
   #error The macro-constant DGOHAL_coCALLBACK_PRESENT shall be defined
#endif


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* MACRO FUNCTIONS                                                                                                    */
/**********************************************************************************************************************/


/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidCLEAR_FAILURE_NOTIFICATION                                                                */
/* !Description : Callback on cleared fault macro                                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#if DGOHAL_coFAULT_CLEAR_NOTIF == DGOHAL_coENABLED

#define DGOHAL_vidCLEAR_FAILURE_NOTIFICATION( \
\
   snFaultIndex \
\
) \
do{                                                                                                  \
   if ((pstrConstInstance->kpfvidClearFailureConfirmation_##snFaultIndex) != NULL_PTR)               \
   {                                                                                                 \
      (*(pstrConstInstance->kpfvidClearFailureConfirmation_##snFaultIndex))();                       \
   }                                                                                                 \
}while(0)

#else
#define DGOHAL_vidCLEAR_FAILURE_NOTIFICATION(snFaultIndex)
#endif /* DGOHAL_coFAULT_CLEAR_NOTIF == DGOHAL_coENABLED */


/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidCONFIRM_FAILURE_NOTIFICATION                                                              */
/* !Description : Callback on confirmed fault macro                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#if DGOHAL_coFAULT_CONFIRM_NOTIF == DGOHAL_coENABLED

#define DGOHAL_vidCONFIRM_FAILURE_NOTIFICATION( \
\
   snFaultIndex \
\
) \
do{                                                                                                  \
   if ((pstrConstInstance->kpfvidSetFailureConfirmation_##snFaultIndex) != NULL_PTR)               \
   {                                                                                                 \
      (*(pstrConstInstance->kpfvidSetFailureConfirmation_##snFaultIndex))();                       \
   }                                                                                                 \
}while(0)

#else
#define DGOHAL_vidCONFIRM_FAILURE_NOTIFICATION(snFaultIndex)
#endif /* DGOHAL_coFAULT_CONFIRM_NOTIF == DGOHAL_coENABLED */



/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidFAULT_FILTERING                                                                           */
/* !Description : Fault Filtering processing Macro For the four filters to be generated by this macro                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define DGOHAL_vidFAULT_FILTERING( \
\
   snFaultIndex \
\
) \
do{                                                                                                              \
   u16LocalFaultCounter = pstrVarInstance->u16FilterCounter_##snFaultIndex;                                      \
   if ((bfFailResult & DGOHAL_bfFAULT_DETECTED_MASK_##snFaultIndex) == 0x00)                                     \
   {                                                                                                             \
      /* CPU load optimization: no treatement to do if coutner is already == 0  */                               \
      if (u16LocalFaultCounter != 0)                                                                             \
      {                                                                                                          \
         u16LocalFaultDecrementValue = *(pstrConstInstance->pu16DecrementFault_##snFaultIndex);                  \
         if (u16LocalFaultCounter <= u16LocalFaultDecrementValue)                                                \
         {                                                                                                       \
            /* in this branch we will reach 0 */                                                                 \
            pstrVarInstance->u16FilterCounter_##snFaultIndex = 0;                                                \
            /* Do the notification only on failure reset transition */                                           \
            if (pstrVarInstance->bConfirmedFault_##snFaultIndex != FALSE)                                        \
            {                                                                                                    \
               pstrVarInstance->bConfirmedFault_##snFaultIndex = FALSE;                                          \
               DGOHAL_vidCLEAR_FAILURE_NOTIFICATION(snFaultIndex);                                               \
            }                                                                                                    \
         }                                                                                                       \
         else                                                                                                    \
         {                                                                                                       \
            pstrVarInstance->u16FilterCounter_##snFaultIndex -= u16LocalFaultDecrementValue;                     \
         }                                                                                                       \
      }                                                                                                          \
   }                                                                                                             \
   else                                                                                                          \
   {                                                                                                             \
      /* CPU load optimization: no treatement to do if coutner is already == UINT16_MAX  */                      \
      if (u16LocalFaultCounter != (uint16)UINT16_MAX)                                                            \
      {                                                                                                          \
         u32LocalCounter = (uint32_least)u16LocalFaultCounter + (*(pstrConstInstance->pu16IncrementFault_##snFaultIndex)); \
         if (u32LocalCounter >= (uint32)UINT16_MAX)                                                              \
         {                                                                                                       \
            pstrVarInstance->u16FilterCounter_##snFaultIndex = UINT16_MAX;                                       \
            /* Do the notification only on failure confirmation transition */                                    \
            if (pstrVarInstance->bConfirmedFault_##snFaultIndex == FALSE)                                        \
            {                                                                                                    \
               pstrVarInstance->bConfirmedFault_##snFaultIndex = TRUE;                                           \
               DGOHAL_vidCONFIRM_FAILURE_NOTIFICATION(snFaultIndex);                                             \
            }                                                                                                    \
         }                                                                                                       \
         else                                                                                                    \
         {                                                                                                       \
            pstrVarInstance->u16FilterCounter_##snFaultIndex = (uint16)u32LocalCounter;                          \
         }                                                                                                       \
      }                                                                                                          \
   }                                                                                                             \
}while(0)



#if DGOHAL_coCALLBACK_PRESENT == DGOHAL_coDISABLED
/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidEnableNotification                                                                        */
/* !Description : Macro which redirect the enable APIs to SWFAIL_vidSoftwareErrorHook in case of no notification needs*/
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define DGOHAL_vidEnableNotification(udtChannel)   SWFAIL_vidSoftwareErrorHook()

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidDisableNotification                                                                       */
/* !Description : Macro which redirect the disable APIs to SWFAIL_vidSoftwareErrorHook in case of no notification need*/
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define DGOHAL_vidDisableNotification(udtChannel)  SWFAIL_vidSoftwareErrorHook()

#else /* DGOHAL_coCALLBACK_PRESENT == DGOHAL_coDISABLED */
/* !MComment: the APIs to be declared for notifications needed  */
extern void DGOHAL_vidDisableNotification(DGOHAL_tudtChannel udtChannel);
extern void DGOHAL_vidEnableNotification(DGOHAL_tudtChannel udtChannel);

#endif /*  DGOHAL_coCALLBACK_PRESENT == DGOHAL_coDISABLED */


#if DGOHAL_coFAULT_FILTERING == DGOHAL_coDISABLED
/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidSetConfirmedFailure                                                                       */
/* !Description : Macro which redirect the failure set APIs to SWFAIL_vidSoftwareErrorHook in case of no notification */
/*                needs                                                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define DGOHAL_vidSetConfirmedFailure(udtChannel,bfFaultIds)   SWFAIL_vidSoftwareErrorHook()

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidClearConfirmedFailure                                                                     */
/* !Description : Macro which redirect the failure clear APIs to SWFAIL_vidSoftwareErrorHook in case of no            */
/*                notification needs                                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
#define DGOHAL_vidClearConfirmedFailure(udtChannel,bfFaultIds)  SWFAIL_vidSoftwareErrorHook()

#else /* DGOHAL_coFAULT_FILTERING == DGOHAL_coDISABLED */

/* !MComment: the APIs to be declared for Filtering needed  */
extern void DGOHAL_vidClearConfirmedFailure(DGOHAL_tudtChannel udtChannel,DGOHAL_tbfStatus bfFaultIds );
extern void DGOHAL_vidSetConfirmedFailure(DGOHAL_tudtChannel udtChannel, DGOHAL_tbfStatus bfFaultIds);

#endif /*  DGOHAL_coFAULT_FILTERING == DGOHAL_coDISABLED */

/**********************************************************************************************************************/
/* TYPES                                                                                                              */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* CALIBRATIONS DEFINITION                                                                                            */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* CONSTANTS DEFINITION                                                                                               */
/**********************************************************************************************************************/
#define DGOHAL_START_SEC_CONST_UNSPECIFIED
#include "DGOHAL_MemMap.h"


#if DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED
/* !MComment: Declaration of the array of pointer to functions of all defined callbacks   */

extern CONST(DGOHAL_tpfvidCallback, DGOHAL_CONST) DGOHAL_akpfvidCallback[DGOHAL_udtCALLBACK_TABLE_SIZE];
#endif /*  DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED */

#if DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED

extern CONST( DGOHAL_tstrConstFilterInfo , DGOHAL_CONST) DGOHAL_kastrFaultConfiguration[DGOHAL_udtCHANNEL_NB];

#endif /*  DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED */

#define DGOHAL_STOP_SEC_CONST_UNSPECIFIED
#include "DGOHAL_MemMap.h"


/**********************************************************************************************************************/
/* DATA DEFINITION                                                                                                    */
/**********************************************************************************************************************/

#define DGOHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "DGOHAL_MemMap.h"

#if DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED
/* !MComment: Declaration of the diagnostic and status arrays                 */
extern VAR(boolean, DGOHAL_VAR) DGOHAL_abNotificationStatus[DGOHAL_udtCALLBACK_TABLE_SIZE];
#endif /*  DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED */

#define DGOHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "DGOHAL_MemMap.h"


#define DGOHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "DGOHAL_MemMap.h"

extern VAR(DGOHAL_tbfStatus, DGOHAL_VAR) DGOHAL_abfStatusTable[DGOHAL_udtCHANNEL_NB];

#define DGOHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "DGOHAL_MemMap.h"

/**********************************************************************************************************************/
/* FUNCTIONS                                                                                                          */
/**********************************************************************************************************************/


#endif  /* COMINL_DEF_H */

/*-------------------------------------------------- end of file -----------------------------------------------------*/
