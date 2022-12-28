/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                     */
/*                                                                            */
/*\!Component       : CanIf                                                   \n
    Description         : It represents the interface to the services of 
                      the CAN Driver for the upper communication layers.      */
/*                                                                            */
/*!\Module          : CanIf_General                                           */
/*!\file            : CanIf_General.h                                         \n
    \Description    : This subcomponent is responsible for general            \n
                      functionalities that canot be in other sub-components   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/17_CanIf/0$*/
/* $Revision::   1.9      $$Author::   mamroussy      $$Date::   Jul 30 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef CANIF_GENERAL_H
#define CANIF_GENERAL_H

/******************************************************************************/
/*!  \Description definition to Rsume loops
*******************************************************************************/
#define CanIf_u8RESUME_LOOP                   (uint8)     0x01
/******************************************************************************/
/*!  \Description definition to abort loops
*******************************************************************************/
#define CanIf_u8ABORT_LOOP                    (uint8)     0x00

typedef enum
{
    CanIf_UNINITIALAIZED = 0,
    CanIf_INITIALAIZED=1
}CanIf_tenuGeneralState;

#define CANIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description General Sate of Canif Initialized or un initialized         \n
     \Renge  CanIf_UNINITIALAIZED,CanIf_INITIALAIZED
*******************************************************************************/
extern VAR(CanIf_tenuGeneralState, CANIF_VAR) CanIf_enueGeneralState;
#define CANIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define CANIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
/******************************************************************************/
/*!  \Description Pointer to configuration parameter set, used for post build   
                  parameters.
*******************************************************************************/
extern P2CONST(CanIf_ConfigType,CANIF_VAR,CANIF_APPL_CONST)
            CanIf_pkstreConfigPtr;
#define CANIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/*!  \Description bit 31 mask of the CanIf.
*******************************************************************************/
#define CanIf_u32CANID_MSB_MASK                 (0x80000000UL)
/******************************************************************************/
/*!  \Description Invalid Standard CanId Mask
*******************************************************************************/
#define CanIf_u32CANID_STANDARD_MASK            0x000007FF
/******************************************************************************/
/*!  \Description Invalid Extended CanId Mask
*******************************************************************************/
#define CanIf_u32CANID_EXTENDED_MASK            (0x1FC00000UL)


/******************************************************************************/
/*                           FUNCTION-LIKE MACRO                              */
/******************************************************************************/
/* PRQA S 3453 ++ */
/*MISRA Msg justification:  Function Like Macro is used here to 
                            simplify Det Error Calling                        */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#define CanIf_vidDET_REPORT_ERROR(APIID,ErrorCode)\
                                                    (void)(Det_ReportError(\
                                                    CANIF_MODULE_ID,\
                                                    (uint8) CANIF_INSTANCE_ID,\
                                                    (APIID),\
                                                    (ErrorCode)))
#endif

/******************************************************************************/
/*!  \Description Getting Controller Configuration from PB Configuration
*******************************************************************************/
#define CanIf_udtGET_CTRL_PBCFG    \
            (CanIf_pkstreConfigPtr->CanIf_pkudteCtrlPbCfg)

/* PRQA S 3453 -- */
#endif
