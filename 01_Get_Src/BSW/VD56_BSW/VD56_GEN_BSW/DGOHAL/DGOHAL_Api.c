/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : DGOHAL                                                                                          */
/* !Description     : Diagnostics of the ECU                                                                          */
/*                                                                                                                    */
/* !File            : DGOHAL_API.c                                                                                    */
/* !Description     : API of the DGOHAL Component                                                                     */
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
 * %PID: LIBEMB:DGOHAL API C-99052622X1608X61.A-SRC;1.11 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "STD_TYPES.h"
#include "Std_Limits.h"
#include "DGOHAL.h"
#include "DGOHAL_L.h"
#include "DGOHAL_Types.h"
#include "DGOHAL_Def.h"
#include "DGOHAL_Co.h"
#include "SchM_Dgohal.h"
#include "SWFAIL.h"

/* !MComment: Check of defines declaration                                                                            */
#ifndef DGOHAL_coCALLBACK_PRESENT
   #error The macro-constant DGOHAL_coCALLBACK_PRESENT shall be defined
#endif
#ifndef DGOHAL_coENABLED
   #error The macro-constant DGOHAL_coENABLED shall be defined
#endif
#ifndef DGOHAL_coFAULT_FILTERING
   #error The macro-constant DGOHAL_coFAULT_FILTERING shall be defined
#endif
#ifndef DGOHAL_coFILTER_FAULT_1
   #error The macro-constant DGOHAL_coFILTER_FAULT_1 shall be defined
#endif
#ifndef DGOHAL_coFILTER_FAULT_2
   #error The macro-constant DGOHAL_coFILTER_FAULT_2 shall be defined
#endif
#ifndef DGOHAL_coFILTER_FAULT_3
   #error The macro-constant DGOHAL_coFILTER_FAULT_3 shall be defined
#endif
#ifndef DGOHAL_coFILTER_FAULT_4
   #error The macro-constant DGOHAL_coFILTER_FAULT_4 shall be defined
#endif
#ifndef DGOHAL_coSINGLE_FILTER_MODE
   #error The macro-constant DGOHAL_coSINGLE_FILTER_MODE shall be defined
#endif

#if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)
STATIC INLINE void vidFaultFilteringManagement(DGOHAL_tudtChannel udtChannel,
                                               DGOHAL_tbfStatus   bfDiagDone,
                                               DGOHAL_tbfStatus   bfFailResult);
#endif /* (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED) */

/**********************************************************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                                                         */
/**********************************************************************************************************************/
#define DGOHAL_START_SEC_CODE
#include "DGOHAL_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidInit                                                                                      */
/* !Description : Initialize all internal variables                                                                   */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(void, DGOHAL_CODE) DGOHAL_vidInit(void)
{
   DGOHAL_tudtChannel udtLocalChannel;


   #if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)
   DGOHAL_tstrVarFilterInfo *pstrLocalFault;
   #endif /* DGOHAL_coFAULT_FILTERING */

   /* !Comment: RAZ of DGOHAL_abfStatusTable array  */
   /* !Trace_To: VEMS_R_06_03891_001.01   */
   /* !Trace_To: VEMS_R_06_03891_002.01   */
   for (udtLocalChannel = 0;
        udtLocalChannel < DGOHAL_udtCHANNEL_NB;
        udtLocalChannel++)
   {
      DGOHAL_abfStatusTable[udtLocalChannel] = DGOHAL_bfNO_DIAGNOSTIC;

      #if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)
      pstrLocalFault = DGOHAL_kastrFaultConfiguration[udtLocalChannel].pstrVarFilterInstance;
      if (pstrLocalFault != NULL_PTR)
      {
         #if (DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED)
         pstrLocalFault->u16FilterCounter_1 = UINT16_MIN;
         pstrLocalFault->bConfirmedFault_1  = FALSE;
         #endif /* (DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED)
         pstrLocalFault->u16FilterCounter_2 = UINT16_MIN;
         pstrLocalFault->bConfirmedFault_2  = FALSE;
         #endif /* (DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED)
         pstrLocalFault->u16FilterCounter_3 = UINT16_MIN;
         pstrLocalFault->bConfirmedFault_3  = FALSE;
         #endif /* (DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED)
         pstrLocalFault->u16FilterCounter_4 = UINT16_MIN;
         pstrLocalFault->bConfirmedFault_4  = FALSE;
         #endif /* (DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED) */
      }
      #endif /* DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED */

   }

   #if (DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED)
   /* !Comment: RAZ of DGOHAL_abNotificationStatus array  */
   /* !Trace_To VEMS_R_06_03891_003.01                    */
   for (udtLocalChannel = 0;
        udtLocalChannel < DGOHAL_udtCALLBACK_TABLE_SIZE;
        udtLocalChannel++)
   {
      DGOHAL_abNotificationStatus[udtLocalChannel] = TRUE;
   }
   #endif /* DGOHAL_coCALLBACK_PRESENT */

}

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_bfRead                                                                                       */
/* !Description : Return the bfStatus of the udtChannel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(DGOHAL_tbfStatus, DGOHAL_CODE) DGOHAL_bfRead
(
   DGOHAL_tudtChannel udtChannel
)
{
   DGOHAL_tbfStatus  bfLocalStatus;
   DGOHAL_tbfStatus *pbfLocalStoredStatus;


   if (udtChannel < DGOHAL_udtCHANNEL_NB)
   {
      pbfLocalStoredStatus = &DGOHAL_abfStatusTable[udtChannel];
      SchM_Enter_DGOHAL_ACCESS_001();
      /* !Trace_To: VEMS_R_06_03891_006.01 */
      bfLocalStatus = *pbfLocalStoredStatus;
      /* !Trace_To: VEMS_R_06_03891_007.01 */
      *pbfLocalStoredStatus = DGOHAL_bfNO_DIAGNOSTIC;
      SchM_Exit_DGOHAL_ACCESS_001();
   }
   else
   {
      /* !Trace_To: VEMS_R_06_03891_005.01 */
      bfLocalStatus = DGOHAL_bfNO_DIAGNOSTIC;
      SWFAIL_vidSoftwareErrorHook();
   }
   return(bfLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidWrite                                                                                     */
/* !Description : Update the diagnostic bfStatus identified by bfDiagDone with the new diagnostic result received by  */
/*                bfFailResult                                                                                        */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(void, DGOHAL_CODE) DGOHAL_vidWrite
(
   DGOHAL_tudtChannel udtChannel,
   DGOHAL_tbfStatus bfDiagDone,
   DGOHAL_tbfStatus bfFailResult
)
{
   DGOHAL_tbfStatus  bfLocalStatus;
   DGOHAL_tbfStatus *pbfLocalStoredStatus;


   if (udtChannel < DGOHAL_udtCHANNEL_NB)
   {
      /* !Trace_To: VEMS_R_06_03891_008.01 */
      /* !Trace_To: VEMS_R_06_03891_009.01 */
      /* !Trace_To: VEMS_R_06_03891_010.01 */
      bfLocalStatus        = (DGOHAL_tbfStatus)(bfDiagDone | bfFailResult);
      pbfLocalStoredStatus = &DGOHAL_abfStatusTable[udtChannel];
      SchM_Enter_DGOHAL_ACCESS_002();
      *pbfLocalStoredStatus |= bfLocalStatus;
      SchM_Exit_DGOHAL_ACCESS_002();

      #if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)
      vidFaultFilteringManagement(udtChannel, bfDiagDone, bfFailResult);
      #endif /* (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED) */
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

   #if (DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED)
   /* !Comment: callback call if notifications enabled */
   /* !Trace_To: VEMS_R_06_03891_011.01 */
   if (  (udtChannel < DGOHAL_udtCALLBACK_TABLE_SIZE)
      && (DGOHAL_abNotificationStatus[udtChannel] != FALSE)
      && (bfFailResult != 0) )
   {
      DGOHAL_akpfvidCallback[udtChannel]();
   }
   #endif /* DGOHAL_coCALLBACK_PRESENT */
}

#if (DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED)

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidEnableNotification                                                                        */
/* !Description : Enable the notifications Callbacks                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(void, DGOHAL_CODE) DGOHAL_vidEnableNotification
(
   DGOHAL_tudtChannel udtChannel
)
{
   if (udtChannel < DGOHAL_udtCALLBACK_TABLE_SIZE)
   {
      /* !Trace_To: VEMS_R_06_03891_012.01 */
      DGOHAL_abNotificationStatus[udtChannel] = TRUE;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#endif /* DGOHAL_coCALLBACK_PRESENT */

#if (DGOHAL_coCALLBACK_PRESENT == DGOHAL_coENABLED)

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidDisableNotification                                                                       */
/* !Description : Disable the notifications Callbacks                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(void, DGOHAL_CODE) DGOHAL_vidDisableNotification
(
   DGOHAL_tudtChannel udtChannel
)
{
   if (udtChannel < DGOHAL_udtCALLBACK_TABLE_SIZE)
   {
      /* !Trace_To: VEMS_R_06_03891_014.01 */
      DGOHAL_abNotificationStatus[udtChannel] = FALSE;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#endif /* DGOHAL_coCALLBACK_PRESENT */

#if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidSetConfirmedFailure                                                                       */
/* !Description : force the fault state to be confirmed failure                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(void, DGOHAL_CODE) DGOHAL_vidSetConfirmedFailure
(
   DGOHAL_tudtChannel udtChannel,
   DGOHAL_tbfStatus bfFaultIds
)
{

   DGOHAL_tbfStatus          bfLocalFilterMask;
   DGOHAL_tstrVarFilterInfo *pstrLocalFault;
   uint16                   *pu16Counter;
   boolean                  *pbConfirmedFault;


   if (udtChannel < DGOHAL_udtCHANNEL_NB)
   {
      pstrLocalFault = DGOHAL_kastrFaultConfiguration[udtChannel].pstrVarFilterInstance;
      if (pstrLocalFault != NULL_PTR)
      {
         /* Check if the requested faults are configured with filtering or not */
         bfLocalFilterMask = DGOHAL_kastrFaultConfiguration[udtChannel].bfAuthorizedFiltering;
         if ( (DGOHAL_tbfStatus)(bfFaultIds | bfLocalFilterMask) != bfLocalFilterMask)
         {
            /* User bfFaultIds is bad, containing a request to SetConfirmedFailure for invalid fault, or bad format */
            /* But process can continue because no impact on the behvaior */
            SWFAIL_vidSoftwareErrorHook();
         }

         #if (DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_1);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_1);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_1);

            SchM_Enter_DGOHAL_ACCESS_003();
            /* Set the filter counter to Max and set Confirmed Fault to True*/
            *pu16Counter      = UINT16_MAX;
            *pbConfirmedFault = TRUE;
            SchM_Exit_DGOHAL_ACCESS_003();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_2);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_2);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_2);

            SchM_Enter_DGOHAL_ACCESS_003();
            /* Set the filter counter to Max and set Confirmed Fault to True*/
            *pu16Counter      = UINT16_MAX;
            *pbConfirmedFault = TRUE;
            SchM_Exit_DGOHAL_ACCESS_003();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_3);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_3);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_3);

            SchM_Enter_DGOHAL_ACCESS_003();
            /* Set the filter counter to Max and set Confirmed Fault to True*/
            *pu16Counter      = UINT16_MAX;
            *pbConfirmedFault = TRUE;
            SchM_Exit_DGOHAL_ACCESS_003();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_4);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_4);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_4);

            SchM_Enter_DGOHAL_ACCESS_003();
            /* Set the filter counter to Max and set Confirmed Fault to True*/
            *pu16Counter      = UINT16_MAX;
            *pbConfirmedFault = TRUE;
            SchM_Exit_DGOHAL_ACCESS_003();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED) */

      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#endif /* (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED) */

#if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)

/**********************************************************************************************************************/
/* !FuncName    : DGOHAL_vidClearConfirmedFailure                                                                     */
/* !Description : force the fault state to be no failure                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

FUNC(void, DGOHAL_CODE) DGOHAL_vidClearConfirmedFailure
(
   DGOHAL_tudtChannel udtChannel,
   DGOHAL_tbfStatus bfFaultIds
)
{

   DGOHAL_tbfStatus          bfLocalFilterMask;
   DGOHAL_tstrVarFilterInfo *pstrLocalFault;
   uint16                   *pu16Counter;
   boolean                  *pbConfirmedFault;


   if (udtChannel < DGOHAL_udtCHANNEL_NB)
   {
      pstrLocalFault = DGOHAL_kastrFaultConfiguration[udtChannel].pstrVarFilterInstance;
      if (pstrLocalFault != NULL_PTR)
      {
         /* Check if the requested faults are configured with filtering or not */
         bfLocalFilterMask = DGOHAL_kastrFaultConfiguration[udtChannel].bfAuthorizedFiltering;
         if ( (DGOHAL_tbfStatus)(bfFaultIds | bfLocalFilterMask) != bfLocalFilterMask)
         {
            /* User bfFaultIds is bad, containing a request to SetConfirmedFailure for invalid fault, or bad format */
            /* But process can continue because no impact on the behvaior */
            SWFAIL_vidSoftwareErrorHook();
         }

         #if (DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_1);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_1);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_1);

            SchM_Enter_DGOHAL_ACCESS_004();
            /* Set the filter counter to Min and set Confirmed Fault to false*/
            *pu16Counter      = UINT16_MIN;
            *pbConfirmedFault = FALSE;
            SchM_Exit_DGOHAL_ACCESS_004();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_2);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_2);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_2);

            SchM_Enter_DGOHAL_ACCESS_004();
            /* Set the filter counter to Min and set Confirmed Fault to false*/
            *pu16Counter      = UINT16_MIN;
            *pbConfirmedFault = FALSE;
            SchM_Exit_DGOHAL_ACCESS_004();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_3);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_3);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_3);

            SchM_Enter_DGOHAL_ACCESS_004();
            /* Set the filter counter to Min and set Confirmed Fault to false*/
            *pu16Counter      = UINT16_MIN;
            *pbConfirmedFault = FALSE;
            SchM_Exit_DGOHAL_ACCESS_004();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED) */

         #if (DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED)
         bfLocalFilterMask = (DGOHAL_tbfStatus)(bfFaultIds & DGOHAL_bfFAULT_MASK_4);

         /* Check if this fault is the intended*/
         if (bfLocalFilterMask != 0)
         {
            pu16Counter      = &(pstrLocalFault->u16FilterCounter_4);
            pbConfirmedFault = &(pstrLocalFault->bConfirmedFault_4);

            SchM_Enter_DGOHAL_ACCESS_004();
            /* Set the filter counter to Min and set Confirmed Fault to false*/
            *pu16Counter      = UINT16_MIN;
            *pbConfirmedFault = FALSE;
            SchM_Exit_DGOHAL_ACCESS_004();
         }
         #endif /* (DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED) */
      }
      else
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}
#endif /* (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED) */

#if (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED)
/**********************************************************************************************************************/
/* !FuncName    : vidFaultFilteringManagement                                                                         */
/* !Description : Static API for the Filtering Feature handling.                                                      */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/

STATIC INLINE void vidFaultFilteringManagement
(
   DGOHAL_tudtChannel udtChannel,
   DGOHAL_tbfStatus   bfDiagDone,
   DGOHAL_tbfStatus   bfFailResult
)
{

   uint16                            u16LocalFaultCounter;
   uint16                            u16LocalFaultDecrementValue;
   uint32                            u32LocalCounter;
   const DGOHAL_tstrConstFilterInfo *pstrConstInstance;
   DGOHAL_tstrVarFilterInfo         *pstrVarInstance;


   pstrConstInstance = &DGOHAL_kastrFaultConfiguration[udtChannel];
   pstrVarInstance   = pstrConstInstance->pstrVarFilterInstance;
   if (pstrVarInstance != NULL_PTR)  /* The channel use filtering */
   {

      /* if we need to treat more than one fault, then start to mask only filtering to do in this channel */
      bfDiagDone &= (pstrConstInstance->bfAuthorizedFiltering);
      if (bfDiagDone != 0)
      {

         /* Test if a diagnostic was done on Failure 1 */
         #if DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED
         #if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED
         DGOHAL_vidFAULT_FILTERING(1);
         #else
         if ( (bfDiagDone & DGOHAL_bfFAULT_MASK_1) != 0x00)
         {
            DGOHAL_vidFAULT_FILTERING(1);
         }
         #endif /* if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED */
         #endif /* if DGOHAL_coFILTER_FAULT_1 == DGOHAL_coENABLED */

         #if DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED
         #if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED
         DGOHAL_vidFAULT_FILTERING(2);
         #else
         if ( (bfDiagDone & DGOHAL_bfFAULT_MASK_2) != 0x00)
         {
            DGOHAL_vidFAULT_FILTERING(2);
         }
         #endif /* if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED */
         #endif /* if DGOHAL_coFILTER_FAULT_2 == DGOHAL_coENABLED */

         #if DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED
         #if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED
         DGOHAL_vidFAULT_FILTERING(3);
         #else
         if ( (bfDiagDone & DGOHAL_bfFAULT_MASK_3) != 0x00)
         {
            DGOHAL_vidFAULT_FILTERING(3);
         }
         #endif /* if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED */
         #endif /* if DGOHAL_coFILTER_FAULT_3 == DGOHAL_coENABLED */

         #if DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED
         #if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED
         DGOHAL_vidFAULT_FILTERING(4);
         #else
         if ( (bfDiagDone & DGOHAL_bfFAULT_MASK_4) != 0x00)
         {
            DGOHAL_vidFAULT_FILTERING(4);
         }
         #endif /* if DGOHAL_coSINGLE_FILTER_MODE == DGOHAL_coENABLED */
         #endif /* if DGOHAL_coFILTER_FAULT_4 == DGOHAL_coENABLED */
      }
   }
}
#endif /* (DGOHAL_coFAULT_FILTERING == DGOHAL_coENABLED) */

#define DGOHAL_STOP_SEC_CODE
#include "DGOHAL_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
