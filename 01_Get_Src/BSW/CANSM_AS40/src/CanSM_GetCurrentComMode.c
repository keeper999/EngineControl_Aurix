/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <TSAutosar.h>              /* EB specific standard types */
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_Cfg.h>              /* DET configuration */
#include <CanSM_ComM.h>             /* Module ComM API */
#include <CanSM_Internal.h>         /* Module private API */
#include <ComM.h>                   /* Communication Manager's types */

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                    /* Development Error Tracer */
#endif

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_START_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode (
  NetworkHandleType  network,
  P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
)
{
  Std_ReturnType retval = E_OK;

  DBG_CANSM_GETCURRENTCOMMODE_ENTRY(network,ComM_ModePtr);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT )
  {
    CANSM_DET(CANSM_SID_GETCURRENTCOMMODE, CANSM_E_UNINIT);
    retval = E_NOT_OK;
  }
  else if ( ComM_ModePtr == NULL_PTR )
  {
    CANSM_DET(CANSM_SID_GETCURRENTCOMMODE, CANSM_E_PARAM_POINTER);
    retval = E_NOT_OK;
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  {
    /* CANSM371 */
    if ( CANSM_NW_HANDLE_IS_VALID(network) )
    {
      /* CANSM186 */
      uint8 networkModeState;
      TS_AtomicAssign8(
                        networkModeState,
                        CANSM_NW_INFO_STATE(CANSM_NW_IDX_FROM_HANDLE(network))
                      );

      switch (networkModeState)
      {
      case CANSM_UNINITED:
        retval = E_NOT_OK;
        break;
      case CANSM_NO_COMMUNICATION:
        *ComM_ModePtr = COMM_NO_COMMUNICATION;
        break;
      case CANSM_SILENT_COMMUNICATION:
        *ComM_ModePtr = COMM_SILENT_COMMUNICATION;
        break;
      case CANSM_FULL_COMMUNICATION:
        *ComM_ModePtr = COMM_FULL_COMMUNICATION;
        break;
      /* CHECK: NOPARSE */
      default:
        CANSM_UNREACHABLE_CODE_ASSERT(CANSM_SID_GETCURRENTCOMMODE);
        break;
      /* CHECK: PARSE */
      }
    }
    else
    {
  #if (CANSM_DEV_ERROR_DETECT == STD_ON)
      /* CANSM187 */
      CANSM_DET(CANSM_SID_GETCURRENTCOMMODE, CANSM_E_INVALID_NETWORK_HANDLE);
  #endif
      retval = E_NOT_OK;
    }
  }


  DBG_CANSM_GETCURRENTCOMMODE_EXIT(retval,network,ComM_ModePtr);
  return retval;

}

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE  */

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

