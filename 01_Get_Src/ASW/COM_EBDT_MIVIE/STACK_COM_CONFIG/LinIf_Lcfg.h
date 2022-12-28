/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : LinIf_Lcfg                                              */
/*!Description     : The Link-time configuration parameters                  */
/*                                                                            */
/*!\File             LinIf_Lcfg.h                                            */
/* \par              The Link-time configuration parameters                  */
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
/* $Revision::   1.3      $$Author::   mnabil         $$Date::   Oct 20 2011 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [2213, 3132]: Configuration file, no need  */
/*              to do this.                                                   */
/* PRQA S 2213, 3132 L1                                                       */

#ifndef LINIF_LCFG_H
#define LINIF_LCFG_H

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf_Types.h"
#include "LinIf_Types_Internal.h"



/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*! \Description   The number of channels controlled by the Lin Interface    */
/*   \Range         0..255                                                    */
/* Configuration: Number of LinIfChannels */
#define LinIf_u8NUMBER_OF_CHANNELS      1U
#define LinIf_u8NUMBER_OF_DRIVERS       1U
#define LinIf_u8NUMBER_OF_TRCVS         0U
#define LinIf_u8NUMBER_OF_SLAVES        1U

#define LinIf_u16INDICATED_COUNT 1
#define LinIf_u8MAX_PORT         2
#define LinIf_u8NET_OFFSET       2
#define LinIf_bCONT_PORTS        TRUE

#if (LinIf_bCONT_PORTS == FALSE)
#define LinIf_u8UNUSED           1
#endif /* LinIf_bCONT_PORTS */
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define LINIF_START_CONFIG_DATA_8
#include "Memmap.h"

extern CONST(uint8, LINIF_CFG_CONST) LinIf_ku8eNumberOfChannels;

#define LINIF_STOP_CONFIG_DATA_8
#include "Memmap.h"

#define LINIF_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

extern CONST(LinIf_tstrChannelStaticConf, LINIF_CFG_CONST) 
                            LinIf_akstreChannelsLT[LinIf_u8NUMBER_OF_CHANNELS];

extern CONST(LinIf_tstrChannelCriticalSec, LINIF_CFG_CONST) 
                    LinIf_akstreChannelsCritSec[LinIf_u8NUMBER_OF_CHANNELS];

extern CONST(LinIf_tstrLinDrvRef, LINIF_CFG_CONST) LinIf_akstreLinDrvConf[1];


#if (LinIf_u8NUMBER_OF_TRCVS > 0U)
extern CONST(LinIf_tstrTransceiverDrvConfig, LINIF_CFG_CONST) 
                                            LinIf_akstreLinTrcvDrvConf[0];
#endif

extern CONST(LinIf_tstrChannelSlaveParams, LINIF_CFG_CONST)
                                                        LinIf_akstreSlaves[1];

#define LINIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Memmap.h"

extern VAR(LinIf_tstrChannelVars, LINIF_VAR) 
                            LinIf_astreChannelsVars[LinIf_u8NUMBER_OF_CHANNELS];

#define LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Memmap.h"




#endif /* LINIF_LCFG_H */

/*-------------------------------- end of file -------------------------------*/
/* PRQA L:L1                                                                  */
