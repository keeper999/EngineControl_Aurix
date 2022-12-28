/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !Module          : Dcm                                                     */
/* !Description     : Dcm                                                     */
/*                                                                            */
/* !File            : Dcm_Common.c                                            */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/B791031T0/archives/B791031T0/04_Software_Component$*/
/* $Revision::   1.24     $$Author::   afarid         $$Date::   May 22 2011 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/

/* !Deviation : Re-Including autosar MemMap.h   */
/* PRQA S 0838 L1                                                             */
#include "Dcm.h"
#include "Dcm_Internal.h"
/* PRQA L:L1                                                                  */

#if(DCM_bINTER_MOD_VER_CHECK == STD_ON)
/******************************************************************************/
/* Intermodule Version Checking                                              */
/******************************************************************************/
/* Check versus MemMap */
#ifdef MEMMAP_AR_RELEASE_MAJOR_VERSION
#ifdef MEMMAP_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (MEMMAP_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "MEMMAP AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (MEMMAP_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "MEMMAP AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "MEMMAP AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "MEMMAP AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus Compiler */
#ifdef COMPILER_AR_RELEASE_MAJOR_VERSION
#ifdef COMPILER_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (COMPILER_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "COMPILER AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (COMPILER_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "COMPILER AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "COMPILER AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "COMPILER AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus StdTypes */
#ifdef STD_TYPES_AR_RELEASE_MAJOR_VERSION
#ifdef STD_TYPES_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (STD_TYPES_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "STD_TYPES AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (STD_TYPES_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "STD_TYPES AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "STD_TYPES AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "STD_TYPES AR RELEASE MAJOR VERSION not defined"
#endif
/******************************************************************************/
/* Check versus PlatformTypes */
#ifdef PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION
#ifdef PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION
/* Major version check */
#if (PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION)
#error "PLATFORM_TYPES AR RELEASE MAJOR VERSION is not compatible with \
DCM AR RELEASE MAJOR VERSION"
#endif
/* Minor version check */
#if (PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION)
#error "PLATFORM_TYPES AR RELEASE MINOR VERSION is not compatible with \
DCM AR RELEASE MINOR VERSION"
#endif
#else
#error "PLATFORM_TYPES AR RELEASE MINOR VERSION not defined"
#endif
#else
#error "PLATFORM_TYPES AR RELEASE MAJOR VERSION not defined"
#endif
#endif /* #if(DCM_bINTER_MOD_VER_CHECK == STD_ON) */

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* \Trace_To: CDD-COM-0016(0) */
/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#define DCM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/* !Deviation : Inhibit MISRA rule [3406]: QAC bug.   */
/* PRQA S 3406 ++ */
/******************************************************************************/
/*!   \Description Post build configuration pointer. \n
      \Range       Not Null
*******************************************************************************/
P2CONST(Dcm_ConfigType,DCM_VAR,DCM_APPL_CONST) Dcm_pkstrePbConfig;
/* PRQA S 3406 -- */

/******************************************************************************/
/*!   \Description Copy No1 of Post Build Configuration pointer. \n
      \Range       Not Null
*******************************************************************************/
static P2CONST(Dcm_ConfigType,DCM_VAR,DCM_APPL_CONST) Dcm_pkstrPbConfigCopy1;

/******************************************************************************/
/*!   \Description Copy No2 of Post Build Configuration pointer. \n
      \Range       Not Null
*******************************************************************************/
static P2CONST(Dcm_ConfigType,DCM_VAR,DCM_APPL_CONST) Dcm_pkstrPbConfigCopy2;
#define DCM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define DCM_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
/******************************************************************************/
/*!   \Description Indicates whether the Dcm is intialized or not. \n
      \Range       [FALSE,TRUE]
*******************************************************************************/
VAR(boolean,DCM_VAR) Dcm_beInitDone = FALSE;
#define DCM_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */

/******************************************************************************/
/*! \Description This service is used for processing the tasks of the main 
                 loop \n
    \return      void \n
    \Trace_To    CDD-1221(0),CDD-1222(0),CDD-1223(0),CDD-1589(0),
                 CDD-COM-0017(0),CDD-COM-0019(0),CDD-COM-0020(0),
                 CDD-COM-0021(0),CDD-COM-0022(0),CDD-COM-0023(0),
                 CDD-COM-0024(0),CDD-1174(0)
*******************************************************************************/
FUNC(void,DCM_CODE) Dcm_MainFunction(void)
{
  boolean bInitDone;

  bInitDone = Dcm_beInitDone;

  /*! If the Dcm is not initializaed, Do Nothing. */
  if(bInitDone == FALSE)
  {
  }
  /*! Else */
  else
  {
    /*! If the current Pb pointer equals the first Pb copy Then
          set the second copy of Pb pointer to be the same value.
        Else if the current Pb pointer equals the second Pb copy Then
          set the first copy of Pb pointer to be the same value.
        Else if the first copy Pb pointer equals the second Pb copy Then
          set the current Pb pointer to be the same value.
        Else (the 3 pointers have different values)
          Do Nothing
    */
          

    if(Dcm_pkstrePbConfig == Dcm_pkstrPbConfigCopy1)
    {
      Dcm_pkstrPbConfigCopy2 = Dcm_pkstrePbConfig;
    }
    else if(Dcm_pkstrePbConfig == Dcm_pkstrPbConfigCopy2)
    {
      Dcm_pkstrPbConfigCopy1 = Dcm_pkstrePbConfig;
    }
    else if(Dcm_pkstrPbConfigCopy1 == Dcm_pkstrPbConfigCopy2)
    {
      Dcm_pkstrePbConfig = Dcm_pkstrPbConfigCopy1;
    }
    else
    {
    
    }
    
    /*! Call the Main functions of the Dsl,Dsd,Dsp. */
    DslInternal_Main();
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
    DsdInternal_Main();
#endif
    DspInternal_Main();
  }
}

/******************************************************************************/
/*! \Description Service for basic initialization of DCM module. 
    \param[in]   ConfigPtr Post Build configuration pointer. \n
    \Range       Not Null \n
    \return      void 
    \Trace_To    CDD-1170(0),CDD-1171(0),CDD-1589(0),CDD-COM-0017(0),
                 CDD-COM-0019(0),CDD-COM-0020(0),CDD-COM-0021(0),
                 CDD-COM-0022(0),CDD-COM-0023(0),CDD-COM-0024(0)
*******************************************************************************/
FUNC(void,DCM_CODE) Dcm_Init(
    P2CONST(Dcm_ConfigType,AUTOMATIC,DCM_APPL_CONST) ConfigPtr)
{
  Dcm_pkstrePbConfig = ConfigPtr;
  /*! Store 2 copies for the Post build configuration pointer.*/
  Dcm_pkstrPbConfigCopy1 = ConfigPtr;
  Dcm_pkstrPbConfigCopy2 = ConfigPtr;
  
  /*! Call the initialization function of Dsl,Dsd,Dsp.*/
  DslInternal_Init();
#if(DCM_PAGED_BUFFER_ENABLED == STD_ON)
  DsdInternal_Init();
#endif
  DspInternal_Init();
  
  /*! Set the Dcm Initialized global variable to TRUE.*/
  Dcm_beInitDone = TRUE;
}

/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#define DCM_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */

/** \} */ /* end of Dcm_Common module group */
/** \} */ /* end of Dcm_Common Component group */
/*-------------------------------- end of file -------------------------------*/
