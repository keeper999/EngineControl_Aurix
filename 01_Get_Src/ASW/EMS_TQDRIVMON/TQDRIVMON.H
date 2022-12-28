/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQDRIVMON                                                */
/*                                                                            */
/* !Module         : TQDRIVMON                                                */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQDRIVMON.H                                              */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQDRIVMON/TQDRIVMON.H_$*/
/* $Revision::   1.5      $$Author::   MBENFRAD       $$Date::   Oct 24 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQDRIVMON_H
#define TQDRIVMON_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_FACNENGIDL_A_COLS              (9)
#define SFTYMGT_FACNENGIDL_T_COLS              (9)
#define SFTYMGT_TQCKEFC_NENGY_A_COLS           (16)
#define SFTYMGT_TQCKEFC_RACCPX_A_COLS          (16)
#define SFTYMGT_TQCKEFCMAXABS_M_LNS           (16)
#define SFTYMGT_TQCKEFCMAXABS_M_COLS           (16)
#define SFTYMGT_TQCKEFCTAKEOFF_M_LNS          (16)
#define SFTYMGT_TQCKEFCTAKEOFF_M_COLS          (16)

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
extern const boolean  SftyMgt_bDeacDZone_C;
extern const boolean  SftyMgt_bDeacTakeOffNReg_C;
extern const boolean  SftyMgt_bTakeOffSpdCoPt_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_32BIT
#include "MemMap.h"
extern const uint32  SftyMgt_tqCkEfc_nEngY_A[SFTYMGT_TQCKEFC_NENGY_A_COLS];
#define TMS_STOP_SEC_CALIB_32BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_facNEngIdl_T[SFTYMGT_FACNENGIDL_T_COLS];
extern const uint8  SftyMgt_tiDlyTakeOffDft_C;
extern const uint8  SftyMgt_tiDlyTqDemDft_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_tqCkLossOfs_C;
extern const sint16  SftyMgt_tqDeacDZone_C;
extern const sint16  SftyMgt_tqErrThdSftyTqDem_C;
extern const sint16  SftyMgt_tqTakeOffThd_C;
extern const uint16  SftyMgt_facNEngIdl_A[SFTYMGT_FACNENGIDL_A_COLS];
extern const uint16  SftyMgt_rAccPOfs_C;
extern const uint16  SftyMgt_rAccPThdAcvTakeOff_C;
extern const uint16  SftyMgt_rAccPThdDZone_C;
extern const uint16  SftyMgt_spdVehDft_C;
extern const uint16  SftyMgt_spdVehMaxTakeOff_C;
extern const uint16  SftyMgt_tiDlyModSptDft_C;
extern const uint16  SftyMgt_tiDlyTakeOff_C;
extern const uint16  SftyMgt_tiDlyTakeOffDftFRM_C;
extern const uint16  SftyMgt_tiDlyTakeOffErr_C;
extern const uint16  SftyMgt_tiDZoneErr_C;
extern const uint16  SftyMgt_tqCkEfc_rAccPX_A[SFTYMGT_TQCKEFC_RACCPX_A_COLS];
extern const uint16  SftyMgt_tqCkEfcMaxAbs_M[SFTYMGT_TQCKEFCMAXABS_M_LNS][SFTYMGT_TQCKEFCMAXABS_M_COLS];
extern const uint16  SftyMgt_tqCkEfcTakeOff_M[SFTYMGT_TQCKEFCTAKEOFF_M_LNS][SFTYMGT_TQCKEFCTAKEOFF_M_COLS];
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bDgoDZone;
extern boolean SftyMgt_bDgoTakeOff;
extern boolean SftyMgt_bDgoTqDem;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqCkEfc;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_Sdl40ms_tqCkEfc(void);
void TQDRIVMON_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQDRIVMON_H */

/*-------------------------------- end of file -------------------------------*/
