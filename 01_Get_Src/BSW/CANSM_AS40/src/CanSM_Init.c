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

#include <CanSM_Api_Static.h>       /* Module public API */
#include <CanSM_Cfg.h>              /* Module generated configuration */
#include <CanSM_Internal.h>         /* Module interna */

/*==================[version check]=========================================*/

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

FUNC(void, CANSM_CODE) CanSM_Init (
  P2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST ) ConfigPtr
)
{
  CanSM_NetworkIndexType nw;

  DBG_CANSM_INIT_ENTRY(ConfigPtr);

  /* The parameter is ignored because post-build configuration is not
     supported. */
  TS_PARAM_UNUSED( ConfigPtr );

  for ( nw=0U; nw<CANSM_NETWORKS_NUM; nw++)
  {
    CANSM_NW_INFO_STATE(nw) = CANSM_UNINITED;
    CANSM_NW_INFO_INTERNALSTATE(nw) = CANSM_S_NOIN;
#if (CANSM_PNSUPPORT == STD_ON)
    CANSM_NW_INFO_REQ_STATE(nw) = CANSM_NO_STATE_REQ;
#endif /* CANSM_PNSUPPORT == STD_ON */
  }


  DBG_CANSM_GLOBALINIT((CanSM_GlobalInit),(CANSM_GLOBAL_INIT));
  CanSM_GlobalInit = CANSM_GLOBAL_INIT;

  for ( nw=0U; nw<CANSM_NETWORKS_NUM; nw++)
  {
    CanSM_DoTransitionSequence(nw, CANSM_T_RNOCO_INITIAL, FALSE);
  }

  DBG_CANSM_INIT_EXIT(ConfigPtr);
}

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

