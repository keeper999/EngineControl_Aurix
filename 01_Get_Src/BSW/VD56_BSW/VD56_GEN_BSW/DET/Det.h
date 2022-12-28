/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Det                                                     */
/* !Description     : AutoSAR BASIS DET Module                                */
/*                                                                            */
/* !Module          : Det                                                     */
/* !Description     : DET Module                                              */
/*                                                                            */
/* !File            : Det.h                                                   */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.16    R2.2.0     AR3.0.0                                    */
/* Done by    : A.Metwelly                                      Date : 5/06/12 */
/* Description: - Updated software version.             						 */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.15    R2.1.0     AR3.0.0                                    */
/* Done by    : M.Hegazy                                      Date : 11/03/12 */
/* Description: - Updated software version.                                   */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.14    R2.0.2     AR3.0.0                                    */
/* Done by    : M.Hegazy                                      Date : 11/03/12 */
/* Description: - Updated DET_SW_PATCH_VERSION.                                */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.13    R2.0.1     AR3.0.0                                    */
/* Done by    : A.Farid                                       Date : 21/11/10 */
/* Description: - Updated DET_SW_PATCH_VERSION                                */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.12    R2.0.1     AR3.0.0                                    */
/* Done by    : A.Farid                                       Date : 21/11/10 */
/* Description: - Updated DET_SW_PATCH_VERSION                                */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.11    2.0.0     AR3.0.0                                     */
/* Done by    : H.Salem                                       Date : 28/12/09 */
/* Description: - Updated range in comments                                   */
/*                                                                            */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.10     2.0.0     AR3.0.0                                    */
/* Done by    : H.Salem                                       Date : 08/09/09 */
/* Description: - Solved teamtrack tickets                                    */
/*                   #01531, #01533, #01535, #01536, #01538, #01810           */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.9                                                           */
/* Done by    : Moustafa Adel                                Date : 18/08/08  */
/* Description: DET_VENDOR_API_INFIX was modified to be defined as an empty   */
/*              macro as DET module can't have multiple instances on the same */
/*              ECU.                                                          */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.8                                                           */
/* Done by    : Moustafa Adel                                Date : 17/07/08  */
/* Description: - DET_GetVersionInfo function prototype was added based on    */
/*                TeamTrack StdSW#00683                                       */
/*              - DET_AR_MAJOR_VERSION was updated to 2                       */
/*              - DET_AR_MINOR_VERSION was updated to 2                       */
/*              - DET_SW_MINOR_VERSION was updated to 5                       */
/*              - DET_SW_PATCH_VERSION was modified to 0                      */
/*              - A new published information DET_VENDOR_API_INFIX was added  */
/*                based on TeamTrack StdSW#00682                              */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.7                                                           */
/* Done by    : M. Assem Gawdat                              Date : 18/10/07  */
/* Description: Changes due to Rework points ISS-DET-13,11,29,38,9,24,25,32,20*/
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/* PVCS Information                                                          
   $Header:   I:/PROJETS/LIBEMB/LOG/SRV/DET/LOG/Det.h_v   1.0   06 Aug 2012 15:31:26   lvoilmy  $
*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef Det_H
#define Det_H

/* !Trace_To: GSCSW-DET-SDD-001-0022                                          */
#include "Det_Types.h"
#include "Det_Cfg.h"

#if (DET_TYPE_IMPLEMENTED == DET_COM)
#include "Det_Com.h"
#endif

/******************************************************************************/
/* Global Type definitions                                                    */
/******************************************************************************/


/******************************************************************************/
/* !Comment         : DET Version Info symbols                                */
/* !Trace_To        : GSCSW-DET-SDD-001-0024, GSCSW-DET-SDD-001-0015          */
/******************************************************************************/

/* !Comment   : Vendor ID of the dedicated implementation of this module
                according to the AUTOSAR vendor list.                         */
/* !Range     : 38                                                            */
#define DET_VENDOR_ID 			((uint16)38)

/* !Comment   : Module ID of the 'DET' module from AUTOSAR Modules List.      */
/* !Range     : 15                                                            */
#define DET_MODULE_ID 			((uint8)15)

/* !Comment   : Major version number of AUTOSAR specification on which the
                appropriate implementation is based on.                       */
/* !Range     : 3                                                             */
#define DET_AR_MAJOR_VERSION 		(3U)

/* !Comment   : Minor version number of AUTOSAR specification on which the
                appropriate implementation is based on.                       */
/* !Range     : 0                                                             */
#define DET_AR_MINOR_VERSION 		(0U)

/* !Comment   : Patch version number of AUTOSAR specification on which the
                appropriate implementation is based on.                       */
/* !Range     : 0                                                             */
#define DET_AR_PATCH_VERSION 		(0U)

/* !Comment   : Major version number of the vendor specific implementation of
                the module. The numbering is vendor specific.                 */
/* !Range     : 2                                                             */
#define DET_SW_MAJOR_VERSION 		(2U)

/* !Comment   : Minor version number of the vendor specific implementation of
                the module. The numbering is vendor specific.                 */
/* !Range     : 0                                                             */
#define DET_SW_MINOR_VERSION 		(2U)

/* !Comment   : Patch version number of the vendor specific implementation of
                the module. The numbering is vendor specific.                 */
/* !Range     : 0                                                             */
#define DET_SW_PATCH_VERSION 		(0U)

/* !Comment   : The vendor specific name that is used in extending the APIs
                names in case a BSW module is used in multiple implementations
				on the same ECU.                                              
				For DET module, DET_VENDOR_API_INFIX is defined as an empty
				macro as DET can't have multiple instances on the same ECU.   */

/* !Range     : --															  */
#define DET_VENDOR_API_INFIX

/******************************************************************************/
/*                  Configuration File Version Checking                       */
/******************************************************************************/


/* Check this component version information toward configured one             */
/* !Trace_To: GSCSW-DET-SDD-001-0052                                          */
#ifdef DET_CFG_MAJOR_VERSION 
  #ifdef DET_CFG_MINOR_VERSION
    /* Major version of the vendor specific implementation of DET module      */
    #if (DET_SW_MAJOR_VERSION != DET_CFG_MAJOR_VERSION)
      #error "Configuration Major Version incompatible with vendor C & H files"
    #endif
    /* Minor version of the vendor specific implementation of DET module      */
    #if (DET_SW_MINOR_VERSION > DET_CFG_MINOR_VERSION)
      #error "Configuration Minor Version incompatible with vendor C & H files"
    #endif 
  #else
    #error "Configuration Minor Version for C and H files not defined"
  #endif /* DET_CFG_MINOR_VERSION */
#else
  #error "Configuration Major Version for C and H files not defined"
#endif  /* DET_CFG_MAJOR_VERSION */


/******************************************************************************/
/* !Comment         : Error information data structure                        */
/* !Trace_To        : GSCSW-DET-SDD-001-0018                                  */
/******************************************************************************/
typedef struct
{
  /* !Comment : Id of the Reporting Module                                    */
  uint16 u16ModuleId;	
  /* !Comment : Id of the Reporting Instance                                  */
  uint8 u8InstanceId;	
  /* !Comment : Id of the Reporting API                                       */
  uint8 u8ApiId;	
  /* !Comment : Id of the Reported Error                                      */
  uint8 u8ErrorId;
  
} Det_tstrReportError;


/******************************************************************************/
/* Function prototypes                                                        */
/******************************************************************************/

/******************************************************************************/
/* !Comment: Start of memory mapping for DET code segment                     */
/* !Trace_to: GSCSW-DET-SRS-003-0026                                          */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_START_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */


/******************************************************************************/
/* !Description      : DET module initialization service                      */
/* !Trace_To         : GSCSW-DET-SDD-001-0019                                 */
/*                                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, DET_CODE) Det_Init ( void );
/* PRQA S 0850 --                                                             */

/******************************************************************************/
/* !Description      : DET module error reporting service                     */
/* !Trace_To         : GSCSW-DET-SDD-001-0020, GSCSW-DET-SDD-001-0028         */
/* !Trace_To         : GSCSW-DET-SDD-001-0035                                 */
/*                                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, DET_CODE) Det_ReportError ( 
                         /* !Comment : Id of the Reporting Module             */
                         uint16 u16ModuleId,
                         /* !Comment : Id of the Reporting Instance           */
                         uint8  u8InstanceId,
                         /* !Comment : Id of the Reporting API                */
                         uint8  u8ApiId,
                         /* !Comment : Id of the Reported Error               */
                         uint8  u8ErrorId
                       );
/* PRQA S 0850 --                                                             */


/******************************************************************************/
/* !Description      : DET module start service                               */
/* !Trace_To         : GSCSW-DET-SDD-001-0021                                 */
/*                                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, DET_CODE) Det_Start ( void );
/* PRQA S 0850 --                                                             */


/******************************************************************************/
/* !Description      : DET module main handling function                      */
/* !Trace_To         : GSCSW-DET-SDD-001-0029, GSCSW-DET-SDD-001-0035         */
/*                                                                            */
/******************************************************************************/
#if (DET_MAINFUNCTION_IMPLEMENTED == STD_ON)
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, DET_CODE) Det_MainFunction ( void );
/* PRQA S 0850 --                                                             */
#endif /* #if (DET_MAINFUNCTION_IMPLEMENTED == ON ) */


/******************************************************************************/
/* !Description      : DET callback function prototype                        */
/*                     This function is user defined                          */
/* !Trace_To         : GSCSW-DET-SDD-001-0030                                 */
/*                                                                            */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
extern FUNC(void, DET_CODE) Det_CallBack \
            ( P2VAR(Det_tstrReportError, AUTOMATIC, DET_VAR_NOINIT) pstrError);
/* PRQA S 0850 --                                                             */


/* If version information API is supported                                    */
/* !Trace_To: GSCSW-DET-SDD-001-0060                                          */
#if (DET_VERSION_INFO_API == STD_ON)

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/* !Description: This service returns the version information of this module  */
/* !Trace_To: GSCSW-DET-SDD-001-0058, GSCSW-DET-SDD-001-0059                  */
/******************************************************************************/
extern FUNC(void, DET_CODE) Det_GetVersionInfo
              (
               /* !Comment: Pointer to where to store the version information */
               /*           of this module                                    */
               /* !Size: 1 Std_VersionInfoType element                        */
               P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) versioninfo
              );
/* PRQA S 0850 --                                                             */
                               
#endif /* (DET_VERSION_INFO_API == STD_ON) */


/******************************************************************************/
/* !Comment: End of memory mapping for DET code segment                       */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */

#endif
