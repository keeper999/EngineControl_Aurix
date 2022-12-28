/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQDRIVMON                                                */
/*                                                                            */
/* !Module         : TQDRIVMON                                                */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQDRIVMON.C75                                            */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQDRIVMON/TQDRIVMON.c7$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   12 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQDRIVMON.h"
#include "TQDRIVMON_l.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const boolean  SftyMgt_bDeacDZone_C = 0;
const boolean  SftyMgt_bDeacTakeOffNReg_C = 0;
const boolean  SftyMgt_bTakeOffSpdCoPt_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_32BIT
#include "MemMap.h"
const uint32  SftyMgt_tqCkEfc_nEngY_A[SFTYMGT_TQCKEFC_NENGY_A_COLS] = {0};
#define TMS_STOP_SEC_CALIB_32BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_facNEngIdl_T[SFTYMGT_FACNENGIDL_T_COLS] = {0};
const uint8  SftyMgt_tiDlyTakeOffDft_C = 0;
const uint8  SftyMgt_tiDlyTqDemDft_C = 0;
const uint8  TQDRIVMON_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqCkLossOfs_C = 0;
const sint16  SftyMgt_tqDeacDZone_C = 0;
const sint16  SftyMgt_tqErrThdSftyTqDem_C = 0;
const sint16  SftyMgt_tqTakeOffThd_C = 0;
const uint16  SftyMgt_facNEngIdl_A[SFTYMGT_FACNENGIDL_A_COLS] = {0};
const uint16  SftyMgt_rAccPOfs_C = 0;
const uint16  SftyMgt_rAccPThdAcvTakeOff_C = 0;
const uint16  SftyMgt_rAccPThdDZone_C = 0;
const uint16  SftyMgt_spdVehDft_C = 0;
const uint16  SftyMgt_spdVehMaxTakeOff_C = 0;
const uint16  SftyMgt_tiDlyModSptDft_C = 0;
const uint16  SftyMgt_tiDlyTakeOff_C = 0;
const uint16  SftyMgt_tiDlyTakeOffDftFRM_C = 0;
const uint16  SftyMgt_tiDlyTakeOffErr_C = 0;
const uint16  SftyMgt_tiDZoneErr_C = 0;
const uint16  SftyMgt_tqCkEfc_rAccPX_A[SFTYMGT_TQCKEFC_RACCPX_A_COLS] = {0};
const uint16  SftyMgt_tqCkEfcMaxAbs_M[SFTYMGT_TQCKEFCMAXABS_M_LNS][SFTYMGT_TQCKEFCMAXABS_M_COLS] = {0};
const uint16  SftyMgt_tqCkEfcTakeOff_M[SFTYMGT_TQCKEFCTAKEOFF_M_LNS][SFTYMGT_TQCKEFCTAKEOFF_M_COLS] = {0};
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
boolean SftyMgt_bAccPDZone_MP;
boolean SftyMgt_bDgo_rDrivTakeOff;
boolean SftyMgt_bDgo_rDrivTakeOff_MP;
boolean SftyMgt_bDgoDZone;
boolean SftyMgt_bDgoTakeOff;
boolean SftyMgt_bDgoTakeOffRaw_MP;
boolean SftyMgt_bDgoTqDem;
boolean SftyMgt_bDgoTqDemMax_MP;
boolean SftyMgt_bDgoTqDemMaxRaw_MP;
boolean SftyMgt_bModSptDft;
boolean SftyMgt_bTakeOffInh_MP;
boolean SftyMgt_bTqAccPOff_MP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 SftyMgt_facAdpAccPOff_MP;
uint8 SftyMgt_facNIdl_MP;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_tqCkEfc;
sint16 SftyMgt_tqCkEfcWoutAntiDBTol;
sint16 SftyMgt_tqCkMaxAbs;
uint16 TQDRIVMON_aSftyMgt_tqCkEfc_nEngY[TQDRIVMON_ASFTYMGT_TQCKEFC_NENGY_COLS];
uint16 TQDRIVMON_u16facNEngIdl;
uint16 TQDRIVMON_u16TurnOnDelayCounter;
uint16 TQDRIVMON_u16TurnOnDelayCounter1;
uint16 TQDRIVMON_u16TurnOnDelayCounter2;
uint16 TQDRIVMON_u16TurnOnDelayCounter3;
uint16 TQDRIVMON_u16TurnOnDelayCounter4;
uint16 TQDRIVMON_u16TurnOnDelayCounter5;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

