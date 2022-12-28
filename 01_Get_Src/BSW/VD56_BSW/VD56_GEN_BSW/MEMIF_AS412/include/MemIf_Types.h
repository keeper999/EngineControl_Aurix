/******************************************************************************/
/*                                                                            */
/* !Layer           : ECU Abstraction Layer                                   */
/*                                                                            */
/* !Component       : MemIf                                                   */
/* !Description     : AutOSAR Memory Abstraction Interface component    */
/*                                                                            */
/* !Module          : MemIf                                                   */
/* !Description     : Memory Abstraction Interface main module                */
/*                                                                            */
/* !File            : MemIf_Types.h                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO - All Rights Reserved                                 */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/13_MemIf/02_Development/02_Source_Code/03_Header_Files/MemIf_Types.h-arc   1.6   Jun 10 2014 11:23:04   AELSOHBY  $
*******************************************************************************/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.3            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/10/11 */
/* Description: - Updated due to Bug # 44207.                    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.2            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 14/09/11 */
/* Description: - Removed "BASIS" word from the file.                    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.1.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11 */
/* Description: - Updated after solving peer review bugs.                    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.0.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 10/05/11 */
/* Description: - Initial version for AUTOSAR Release 4.0.                    */
/******************************************************************************/
#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

/*-- Include Component Externals --*/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0032                                       */
/*lint -save -vo -e537 -v                                                     */
#include "Std_Types.h"
/*lint -restore                                                               */

/*============================================================================*/
/*=== Public Component Types Definition ======================================*/
/*============================================================================*/
/*! \Trace_To  GSCSW-MemIf-SDD-001-0004                                       */

/*!  Enumeration type denoting the current status of the underlying 
             abstraction module and device driver. To be used as the return
             value of the corresponding driver's "GetStatus" function.      
             Note: order of labels is important to manage a priority        
             of statuses when compiling many device statuses in "GetStatus" */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0007                                       */
typedef enum 
{
    /*!  MemAbstr/DeviceDrv currently idle                            */
    MEMIF_IDLE          = 0,
    /*!  MemAbstr/DeviceDrv busy with internal management operations  */
    MEMIF_BUSY_INTERNAL = 1,
    /*!  MemAbstr/DeviceDrv busy with a job                           */
    MEMIF_BUSY          = 2,
    /*!  MemAbstr/DeviceDrv not initialized                           */
    MEMIF_UNINIT        = 3
}MemIf_StatusType;
           

/*!  Enumeration type denoting the result of the underlying         
             abstraction module's last job.                                 */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0008                                       */
typedef enum 
{
    /*!  Job has finished successfully                                */
    MEMIF_JOB_OK              = 0,
    /*!  Job has finished with a failure                              */
    MEMIF_JOB_FAILED          = 1,
    /*!  Job has not yet been finished                                */
    MEMIF_JOB_PENDING         = 2,
    /*!  Job has been cancelled                                       */
    MEMIF_JOB_CANCELED       = 3,
    /*!  Requested block corrupted                                    */
    MEMIF_BLOCK_INCONSISTENT  = 4,
    /*!  Requested block marked as invalid                            */
    MEMIF_BLOCK_INVALID       = 5         
}MemIf_JobResultType; 
              
/*!  Enumeration type to be used for the parameter passed into      
             "SetMode" API to define the speed mode of the device driver    
             (i.e. number of bytes treated in one device job cycle)         */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0009                                       */
typedef enum 
{
    /*!  DeviceDrv working in slow mode (few bytes treated/cycle)     */
    MEMIF_MODE_SLOW = 0,
    /*!  DeviceDrv working in fast mode (many bytes treated/cycle)    */
    MEMIF_MODE_FAST = 1
}MemIf_ModeType;
               
/* !MComment : Enumeration fields for MEMIF_u8API_CONFIG_CLASS Configuration  */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0031                                       */
#define MEMIF_u8API_CONFIG_CLASS_1            (0U)
#define MEMIF_u8API_CONFIG_CLASS_2            (1U)


/*============================================================================*/
/*=== PrivateComponent types definition ======================================*/
/*============================================================================*/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/*!  Type used to configure wrap table for SetMode APIs             */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0038                                       */
typedef P2FUNC(void, MEMIF_APPL_CODE, 
               MemIf_tpfvidSetModeApi)(MemIf_ModeType Mode);

/*!  Type used to configure wrap table for GetStatus APIs           */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0039                                       */
typedef P2FUNC(MemIf_StatusType, MEMIF_APPL_CODE, 
               MemIf_tpfenuGetStatusApi)(void);
               
/*!  Type used to configure wrap table for GetJobResult APIs        */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0040                                       */
typedef P2FUNC(MemIf_JobResultType, MEMIF_APPL_CODE, 
               MemIf_tpfenuGetJobResultApi)(void);

/*!  Type used to configure wrap table for Read APIs                */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0041                                       */
typedef P2FUNC(Std_ReturnType, MEMIF_APPL_CODE, 
               MemIf_tpfudtReadApi)(
               uint16 BlockNumber, 
               uint16 BlockOffset, 
               P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr, 
               uint16 Length);

/*!  Type used to configure wrap table for Write APIs               */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0042                                       */
typedef P2FUNC(Std_ReturnType, MEMIF_APPL_CODE, 
               MemIf_tpfudtWriteApi)(
               uint16 BlockNumber, 
               P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr);

/*!  Type used to configure wrap table for EraseImmediateBlock APIs */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0043                                       */
typedef P2FUNC(Std_ReturnType, MEMIF_APPL_CODE, 
               MemIf_tpfudtEraseImdtBlockApi)(uint16 BlockNumber);

/*!  Type used to configure wrap table for InvalidateBlock APIs     */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0044                                       */
typedef P2FUNC(Std_ReturnType, MEMIF_APPL_CODE, 
               MemIf_tpfudtInvalidateBlockApi)(uint16 BlockNumber);

/*!  Type used to configure wrap table for Cancel APIs              */
/*! \Trace_To  GSCSW-MemIf-SDD-001-0045                                       */
typedef P2FUNC(void, MEMIF_APPL_CODE, 
               MemIf_tpfvidCancelApi)(void);
/* PRQA S 0850 --                                                             */
/*############################################################################*/
/*## NOTE: Previous function wrapping types are supposed to be used only    ##*/
/*##       if the number of configured memory devices is greater than 1.    ##*/
/*############################################################################*/


#endif /* MEMIF_TYPES_H */

/*==== End of File ===========================================================*/
