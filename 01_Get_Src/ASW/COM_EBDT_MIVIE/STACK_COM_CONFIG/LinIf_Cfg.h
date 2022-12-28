/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_Cfg                                               */
/*!Description     : The pre-compile time configuration parameters           */
/*                                                                            */
/*!\File            LinIf_Cfg.h                                             */
/* \par             The pre-compile time configuration parameters            */
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
/* $Revision::   1.5      $$Author::   sedrees        $$Date::   Dec 11 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

#ifndef LINIF_CFG_H
#define LINIF_CFG_H

#include "Std_Types.h"
#include "Compiler.h"



/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/*! \Description   The Configuration Major version                           */
#define LINIF_CFG_MAJOR_VERSION                         (2U)
/*! \Description   The Configuration Minor version                           */
#define LINIF_CFG_MINOR_VERSION                         (0U)

/* LinIfVersionInfoApi */
/*! \Description   Switch to Enable/Disable LinIf_GetVersionInfo API         */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bIF_VERSION_INFO_API                      STD_OFF


/* LinIfJitter */
/*! \Description   The difference between the maximum and minimum delay from 
                    the point of requesting header transmission till the actual
                    start of transmission                   */
/*   \Range         0..255                                                    */
/*   \Unit          milliseconds                                              */
  
#define LinIf_u8LINIF_JITTER                            100U

/* LinIfDevErrorDetect */
/*! \Description   Switch to Enable/Disable Development Errors Detection     */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_u8DEV_ERROR_DETECT                        STD_ON

/* LinIfInterModVerCheck */
/*! \Description   Determines whether version check is to be made between 
                   LinIf and other interfaced modules or not.                 */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bINTER_MOD_VER_CHECK                        STD_OFF

/* LinIfMultipleDriversSupported */
/*! \Description   Switch to Enable/Disable Multiple driver support          */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bMULTIPLE_DRV_SUPPORT                     STD_OFF


/* LinIfMultipleTrcvDriverSupported */
/*! \Description   Switch to Enable/Disable Transciever drivers support      */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bMULTIPL_TRCV_SUPPORT                     STD_OFF



/* LinIfNcOptionalRequestSupported */
/*! \Description   Switch to Enable/Disable Optional Node configuration 
                    commands support                                          */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bOPTIONAL_REQ_SUPPORT                     STD_OFF



/* LinTpVersionInfoApi */
/*! \Description   Switch to Enable/Disable LinTp_GetVersionInfo API         */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bTP_VERSION_INFO_API                      


/* LinIfCancelTransmitSupported */
/*! \Description   Switch to Enable/Disable LinIf_CancelTransmit API         */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_bCANCEL_TX_SUPPORT                        STD_ON


/* LinIfTpSupported */
/*! \Description   Switch to Enable/Disable LinTp module (without Node 
                    configuration)                                            */
/*   \Range         STD_ON / STD_OFF                                          */
#define LinIf_u8TP_SUPPORTED                            STD_OFF



/*! \Description   Number of PB LinIf Configuration Structures               */
/*   \Range         0..255                                                    */
#define LinIf_u8NUMBER_OF_IF_CONFIGS                    1

/*! \Description   Number of PB LinTp Configuration Structures               */
/*   \Range         0..255                                                    */
#define LinIf_u8NUMBER_OF_TP_CONFIGS                    0


/* Exporting LinIfFrame Symbolic Names with the value of LinIfPduDirection/LinIfTxPduId */
  
#define LinIf_CDE_ALT                    0
  
/* Exporting LinIfChannel Symbolic Names with the value of LinIfChannelId */
  
#define LinIf_CMM                    2
  
/* Exporting LinIfScheduleTable Symbolic Names with the value of LinIfScheduleTableIndex */
  
#define LinIf_RUN_MAIN                    1

/* Exporting LinTpRxFrame Symbolic Names with the value of LinTpRxNSduId */
  

/* Exporting LinTpTxFrame Symbolic Names with the value of LinTpTxNSduId */
  

#endif /* LINIF_CFG_H */

/*-------------------------------- end of file -------------------------------*/
