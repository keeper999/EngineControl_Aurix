/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_DetErrors                                         */
/*!Description     : The Det error and service Ids reported to DET from LinIf */
/*                                                                            */
/*!\File             LinIf_Cfg.h                                             */
/* \par              The Det error and service Ids reported to DET from LinIf */
/*!Scope           : Public                                                  */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.5      $$Author::   MTAYMOUR       $$Date::   Feb 19 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_DETERRORS_H
#define LINIF_DETERRORS_H

#include "Std_Types.h"
#include "Compiler.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*********************************** Service IDs ******************************/
/*!\Description The service ID of the LinIf_Init                              */
#define LinIf_u8LINIF_INIT_SRV_ID       0x01U

/*!\Description The service ID of the LinIf_GetVersionInfo                    */
#define LinIf_u8LINIF_GET_VERSION_ID    0x03U

/*!\Description The service ID of the LinIf_MainFunction                      */
#define LinIf_u8LINIF_MAINFN_SRV_ID     0x80U

/*!\Description The service ID of the LinIf_Transmit                          */
#define LinIf_u8LINIF_TRNSMT_SRV_ID     0x04U

/*!\Description The service ID of the LinIf_CancelTransmit                    */
#define LinIf_u8LINIF_CNCLTX_SRV_ID     0x0CU

/*!\Description The service ID of the LinIf_ScheduleRequest                   */
#define LinIf_u8LINIF_SCHREQ_SRV_ID     0x05U

/*!\Description The service ID of the LinIf_GotoSleep                         */
#define LinIf_u8LINIF_GOSLEEP_SRV_ID    0x06U

/*!\Description The service ID of the LinIf_Wakeup                            */
#define LinIf_u8LINIF_WAKEUP_SRV_ID     0x07U

/*!\Description The service ID of the LinIf_CheckWakeup                       */
#define LinIf_u8LINIF_CHKWKUP_SRV_ID    0x60U

/*!\Description The service ID of the LinIf_SetTrcvMode                       */
#define LinIf_u8LINIF_SETTRCVMODE_ID    0x08U

/*!\Description The service ID of the LinIf_GetTrcvMode                       */
#define LinIf_u8LINIF_GETTRCVMODE_ID    0x09U

/*!\Description The service ID of the LinIf_SetTrcvWakeupMode                 */
#define LinIf_u8LINIF_SETTRCVWUMD_ID    0x0BU

/*!\Description The service ID of the LinIf_GetTrcvWakeupReason               */
#define LinIf_u8LINIF_GETTRCVWURS_ID    0x0AU

/*!\Description The service ID of the LinTp_Init                              */
#define LinIf_u8LINTP_INIT_ID           0x40U

/*!\Description The service ID of the LinTp_Transmit                          */
#define LinIf_u8LINTP_TRANSMIT_ID       0x41U

/*!\Description The service ID of the LinTp_Shutdown                          */
#define LinIf_u8LINTP_SHUTDOWN_ID       0x43U

/*!\Description The service ID of the LinTp_CancelTransmitRequest             */
#define LinIf_u8LINTP_CANCEL_TX_ID      0x46U

/*!\Description The service ID of the LinTp_ChangeParameterRequest            */
#define LinIf_u8LINTP_CHG_PARAM_ID      0x44U

/*!\Description The service ID of the LinTp_CancelReceiveRequest              */
#define LinIf_u8LINTP_CANCEL_REC_ID     0x47U

/*!\Description The service ID of the LinTp_GetVersionInfo                    */
#define LinIf_u8LINTP_GET_VERSION_ID    0x42U
/******************************************************************************/
/************************************ Error IDs *******************************/
/*!\Description The Error ID when an API is called and the module is not      */
/*            Initialized before                                              */
#define LINIF_E_UNINIT                  0x00U
/*!\Description The Error ID of reinitializing the LinIf while it is already  */
/*            Initialized before                                              */
#define LINIF_E_ALREADY_INITIALIZED     0x10U
/*!\Description The Error ID when an invalid channel ID is passed to an API   */
#define LINIF_E_NONEXISTENT_CHANNEL     0x20U
/*!\Description The Error ID of invalid parameter passed to an API            */
#define LINIF_E_PARAMETER               0x30U
/*!\Description The Error ID of invalid pointer passed to an API              */
#define LINIF_E_PARAMETER_POINTER       0x40U
/*!\Description The Error ID when a request to change the schedule table of a */
/*            channel that is sleep                                           */
#define LINIF_E_SCHEDULE_REQUEST_ERROR  0x51U
/*!\Description The Error ID of invalid channel is passed to a Transciever    */
/*            related API                                                     */
#define LINIF_E_TRCV_INV_CHANNEL        0x52U
/*!\Description The Error ID of invalid mode is passed to a Transciever       */
/*              related API                                                   */
#define LINIF_E_TRCV_INV_MODE           0x53U
/*!\Description The Error ID when a transceiver is not in normal mode and a   */
/*            transition into sleep mode is requested                         */
#define LINIF_E_TRCV_NOT_NORMAL        0x54U
/*!\Description The Error ID of invalid wakeup source                         */
#define LINIF_E_PARAM_WAKEUPSOURCE         0x55U

/*!\Description The Error ID when the length of copied data from PduR to LinIf
                in TriggerTransmit function is not equal to the length 
                configured for the requested frame                            */
#define LinIf_u8E_INV_PDU_LEN             0xA0U


#endif /* LINIF_DETERRORS_H */

/*-------------------------------- end of file -------------------------------*/
