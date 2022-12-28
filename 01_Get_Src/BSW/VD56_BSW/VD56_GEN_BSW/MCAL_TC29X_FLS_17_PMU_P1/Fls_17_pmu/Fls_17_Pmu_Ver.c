/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Fls_17_Pmu_Ver.c $                                         **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-11-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - functionality of Flash driver                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
   Traceability:
                 [cover parentID=DS_NAS_PR730]
                 [/cover]
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of SchM Header File */
#include "SchM_17_McalCfg.h"
#include SCHM_FLS_17_PMU_HEADER

/* Inclusion of Flash header file */
#include "Fls_17_Pmu.h"

/* Inclusion of Fls_17_Pmu module's local header file */
#include "Fls_17_Pmu_Local.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*
    AUTOSAR VERSION CHECK FOR FLS MODULE INCLUSION
*/

#ifndef FLS_17_PMU_AR_RELEASE_MAJOR_VERSION
  #error "FLS_17_PMU_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef FLS_17_PMU_AR_RELEASE_MINOR_VERSION
  #error "FLS_17_PMU_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef FLS_17_PMU_AR_RELEASE_REVISION_VERSION
  #error "FLS_17_PMU_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if ( FLS_17_PMU_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "FLS_17_PMU_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( FLS_17_PMU_AR_RELEASE_MINOR_VERSION != 0U )
  #error "FLS_17_PMU_AR_RELEASE_MINOR_VERSION does not match. "
#endif

/*
    DRIVER VERSION CHECK FOR FLS MODULE INCLUSION
*/

#ifndef FLS_17_PMU_SW_MAJOR_VERSION
  #error "FLS_17_PMU_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef FLS_17_PMU_SW_MINOR_VERSION
  #error "FLS_17_PMU_SW_MINOR_VERSION is not defined. "
#endif

#ifndef FLS_17_PMU_SW_PATCH_VERSION
  #error "FLS_17_PMU_SW_PATCH_VERSION is not defined. "
#endif

#if (FLS_17_PMU_SW_MAJOR_VERSION != 2U)
  #error "FLS_17_PMU_SW_MAJOR_VERSION does not match."
#endif

#if (FLS_17_PMU_SW_MINOR_VERSION != 1U)
  #error "FLS_17_PMU_SW_MINOR_VERSION does not match."
#endif

/*
    VERSION CHECK FOR DET MODULE INCLUSION
*/
#if ( FLS_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif

/*
    VERSION CHECK FOR DEM MODULE INCLUSION
*/

#if((FLS_E_COMPARE_FAILED_DEM_REPORT == ENABLE_DEM_REPORT) ||  \
    (FLS_E_ERASE_FAILED_DEM_REPORT == ENABLE_DEM_REPORT) ||    \
    (FLS_E_WRITE_FAILED_DEM_REPORT == ENABLE_DEM_REPORT) ||    \
    (FLS_E_READ_FAILED_DEM_REPORT == ENABLE_DEM_REPORT))

#ifndef DEM_AR_RELEASE_MAJOR_VERSION
  #error "DEM_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DEM_AR_RELEASE_MINOR_VERSION
  #error "DEM_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if ( DEM_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DEM_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( DEM_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DEM_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lDemReportError_Erase(void)                      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Reports Erase error to DEM                                   **
*******************************************************************************/
_INLINE_ void Fls_lDemReportError_Erase(void)
{
  #if (FLS_E_ERASE_FAILED_DEM_REPORT == ENABLE_DEM_REPORT)
  if (Fls_ConfigPtr->FlsEraseFailedId != DISABLE_DEM_REPORT)
  {
    Dem_ReportErrorStatus(Fls_ConfigPtr->FlsEraseFailedId,
                          DEM_EVENT_STATUS_FAILED);
  }
  #endif
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lDemReportError_Read(void)                       **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Reports Read error to DEM                                    **
*******************************************************************************/
_INLINE_ void Fls_lDemReportError_Read(void)
{
  #if (FLS_E_READ_FAILED_DEM_REPORT == ENABLE_DEM_REPORT)
  if (Fls_ConfigPtr->FlsReadFailedId != DISABLE_DEM_REPORT)
  {
    Dem_ReportErrorStatus(Fls_ConfigPtr->FlsReadFailedId, 
                          DEM_EVENT_STATUS_FAILED);
  }
  #endif
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lDemReportError_Write(void)                      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Reports Write error to DEM                                   **
*******************************************************************************/
_INLINE_ void Fls_lDemReportError_Write(void)
{
  #if (FLS_E_WRITE_FAILED_DEM_REPORT == ENABLE_DEM_REPORT)
  if(Fls_ConfigPtr->FlsWriteFailedId != DISABLE_DEM_REPORT)
  {
    Dem_ReportErrorStatus(Fls_ConfigPtr->FlsWriteFailedId,
                          DEM_EVENT_STATUS_FAILED);
  }
  #endif
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lDemReportError_Compare(void)                    **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Reports Compare error to DEM                                 **
*******************************************************************************/
_INLINE_ void Fls_lDemReportError_Compare(void)
{
  #if (FLS_E_COMPARE_FAILED_DEM_REPORT == ENABLE_DEM_REPORT)
  if(Fls_ConfigPtr->FlsCompareFailedId != DISABLE_DEM_REPORT)
  {
    Dem_ReportErrorStatus(Fls_ConfigPtr->FlsCompareFailedId,
                          DEM_EVENT_STATUS_FAILED);
  }
  #endif
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMEnter_Init(void)                            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Enters critical section of Init                              **
*******************************************************************************/
_INLINE_ void Fls_lSchMEnter_Init(void)
{
  SchM_Enter_Fls_17_Pmu_Init();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMExit_Init(void)                             **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Exits critical section of Init                               **
*******************************************************************************/
_INLINE_ void Fls_lSchMExit_Init(void)
{
  SchM_Exit_Fls_17_Pmu_Init();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMEnter_Erase(void)                           **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Enters critical section of Erase                             **
*******************************************************************************/
_INLINE_ void Fls_lSchMEnter_Erase(void)
{
  SchM_Enter_Fls_17_Pmu_Erase();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMExit_Erase(void)                            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Exits critical section of Erase                              **
*******************************************************************************/
_INLINE_ void Fls_lSchMExit_Erase(void)
{
  SchM_Exit_Fls_17_Pmu_Erase();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMEnter_Write(void)                           **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Enters critical section of Write                             **
*******************************************************************************/
_INLINE_ void Fls_lSchMEnter_Write(void)
{
  SchM_Enter_Fls_17_Pmu_Write();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMExit_Write(void)                            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Exits critical section of Write                              **
*******************************************************************************/
_INLINE_ void Fls_lSchMExit_Write(void)
{
  SchM_Exit_Fls_17_Pmu_Write();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMEnter_ResumeErase(void)                     **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Enters critical section of Resume Erase                      **
*******************************************************************************/
_INLINE_ void Fls_lSchMEnter_ResumeErase(void)
{
  SchM_Enter_Fls_17_Pmu_ResumeErase();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMExit_ResumeErase(void)                      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Exits critical section of Resume Erase                       **
*******************************************************************************/
_INLINE_ void Fls_lSchMExit_ResumeErase(void)
{
  SchM_Exit_Fls_17_Pmu_ResumeErase();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMEnter_Main(void)                            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Enters critical section of Main Function                     **
*******************************************************************************/
_INLINE_ void Fls_lSchMEnter_Main(void)
{
  SchM_Enter_Fls_17_Pmu_Main();
}

/*******************************************************************************
** Syntax: _INLINE_ void Fls_lSchMExit_Main(void)                             **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Exits critical section of Main Function                      **
*******************************************************************************/
_INLINE_ void Fls_lSchMExit_Main(void)
{
  SchM_Exit_Fls_17_Pmu_Main();
}

/*******************************************************************************
** Syntax: _INLINE_ MemIf_ModeType Fls_lSetDefaultMode(void)                  **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : MemIf_ModeType                                           **
**                                                                            **
** Description : Returns the default mode of FLS driver                       **
*******************************************************************************/
_INLINE_ MemIf_ModeType Fls_lSetDefaultMode(void)
{
  return (Fls_ConfigPtr->FlsDefaultMode);
}

#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
