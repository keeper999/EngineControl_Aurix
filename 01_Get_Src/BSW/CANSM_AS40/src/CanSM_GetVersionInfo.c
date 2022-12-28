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

#include <CanSM_Api.h>              /* Module public API */
#include <CanSM_Version.h>          /* Version information */
#include <CanSM_Cfg.h>              /* Generated configuration */
#include <CanSM_Int_Stc.h>          /* Module private API */

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

#if (CANSM_VERSION_INFO_API == STD_ON)

FUNC(void, CANSM_CODE) CanSM_GetVersionInfo (
  P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
)
{

  DBG_CANSM_GETVERSIONINFO_ENTRY(VersionInfo);

#if (CANSM_DEV_ERROR_DETECT == STD_ON)
  if ( VersionInfo == NULL_PTR )
  {
    CANSM_DET(CANSM_SID_GETVERSIONINFO, CANSM_E_PARAM_POINTER);
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT == STD_ON */
  {
    VersionInfo->vendorID         = CANSM_VENDOR_ID;
    VersionInfo->moduleID         = CANSM_MODULE_ID;
    VersionInfo->sw_major_version = CANSM_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = CANSM_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = CANSM_SW_PATCH_VERSION;
  }

  DBG_CANSM_GETVERSIONINFO_EXIT(VersionInfo);
}

#endif

#if (TS_MERGED_COMPILE == STD_OFF)
#define CANSM_STOP_SEC_CODE
#include <MemMap.h>
#endif /* TS_MERGED_COMPILE */

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

