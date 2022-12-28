/* PRQA S 8014, 8114, 8314, 8414, 8614 ++*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
    because file names are imposed by AutOSAR requirements */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : ComM                                                    */
/* !Description     : Communication Manager Module                            */
/*                                                                            */
/* !Module          : ComM                                                    */
/*                                                                            */
/* !File            : ComM_Types.h                                            */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/04-ComM/02$*/
/* $Revision::   1.12     $$Author::   knasr          $$Date::   Aug 20 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
#ifndef COMM_TYPES_H
#define COMM_TYPES_H

#include "ComStack_Types.h"

/******************************************************************************/
/*! \Description Vendor ID of the dedicated implementation of this module
                 according to the AutOSAR vendor list.                      \n\n
    \Range 38                                                               \n\n
    \Unit uint16                                                            \n\n
*******************************************************************************/
#define COMM_VENDOR_ID                    ((uint16)(38))
/******************************************************************************/
/*! \Description Module ID of the dedicated implementation of this module
                 according to the AutOSAR module list.                      \n\n
    \Range 12                                                               \n\n
    \Unit uint16                                                            \n\n
*******************************************************************************/
#define COMM_MODULE_ID                    ((uint16)(12))
/******************************************************************************/
/*! \Description Major version number of AutOSAR specification on which the
                 current implementation is based.                           \n\n
    \Range 4                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_AR_RELEASE_MAJOR_VERSION     (4)
/******************************************************************************/
/*! \Description Minor version number of AutOSAR specification on which the
                 current implementation is based.                           \n\n
    \Range 0                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_AR_RELEASE_MINOR_VERSION     (1)
/******************************************************************************/
/*! \Description Patch level version number of AutOSAR specification on
                 which the current implementation is based.                 \n\n
    \Range 2                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_AR_RELEASE_REVISION_VERSION  (2)
/******************************************************************************/
/*! \Description Major version number of the "VIAS_3_AUTOSAR Platform
                 Development R4.0 - ESW Variant" project implementation of
                 the module. The numbering is vendor specific.              \n\n
    \Range 1                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_SW_MAJOR_VERSION             (3)
/******************************************************************************/
/*! \Description Minor version number of the "VIAS_3_AUTOSAR Platform
                 Development R4.0 - ESW Variant" project implementation of
                 the module. The numbering is vendor specific.              \n\n
    \Range 0                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_SW_MINOR_VERSION             (0)
/******************************************************************************/
/*! \Description Patch level version number of the "VIAS_3_AUTOSAR Platform
                 Development R4.0 - ESW Variant" project implementation of
                 the module.                                                \n\n
    \Range 0                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_SW_PATCH_VERSION             (1)
/******************************************************************************/
/*! \Description Symbol for COMM_NO_COMMUNICATION State.                    \n\n
    \Range 0                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_NO_COMMUNICATION             (0)
/******************************************************************************/
/*! \Description Symbol for COMM_SILENT_COMMUNICATION State.                \n\n
    \Range 1                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_SILENT_COMMUNICATION         (1)
/******************************************************************************/
/*! \Description Symbol for COMM_FULL_COMMUNICATION State.                  \n\n
    \Range 2                                                                \n\n
    \Unit uint8                                                             \n\n
*******************************************************************************/
#define COMM_FULL_COMMUNICATION           (2)

/*    
    \Trace_To   ComM-CDD-0329(0)   
*/
typedef enum {
    COMM_UNINIT,
    COMM_INIT
} ComM_InitStatusType;

/*    
    \Trace_To   ComM-CDD-0333(0)   
*/
typedef enum{
    PNC_REQUESTED,
    PNC_READY_SLEEP,
    PNC_PREPARE_SLEEP,
    PNC_NO_COMMUNICATION,
    PNC_FULL_COMMUNICATION
}ComM_PncModeType;

/*    
    \Trace_To   ComM-CDD-0330(0)   
*/
typedef uint8 ComM_InhibitionStatusType;


/*    
    \Trace_To   ComM-CDD-0331(0)   
*/
typedef uint8 ComM_UserHandleType;


/*    
    \Trace_To   ComM-CDD-0332(0)   
*/
typedef uint8 ComM_ModeType;


/*    
    \Trace_To   ComM-CDD-0334(0)   
*/
typedef uint8 ComM_StateType;






#endif /* COMM_TYPES_H */
