/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : NTARIDLCHK                                               */
/*                                                                            */
/* !Module         : NTARIDLCHK                                               */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : NTARIDLCHK.C75                                           */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEMS                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/NTARIDLCHK/NTARIDLCHK.$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   05 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "NTARIDLCHK.h"
#include "NTARIDLCHK_l.h"

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
const boolean  SftyMgt_bInhIniIdlDyn_C = 0;
const boolean  SftyMgt_bInhIniNTarIdlStrt_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  NTARIDLCHK_u8Inhib = 0;
const uint8  SftyMgt_stGBxAT_C = 0;
const uint8  SftyMgt_tiDlyNTarIdlDynDft_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_nGrdNTarIdlDyn_C = 0;
const uint16  SftyMgt_facIncMaxTarIdl_C = 0;
const uint16  SftyMgt_nMinEngSetTqSysAcv_C = 0;
const uint16  SftyMgt_nOfsErrTarIdl_C = 0;
const uint16  SftyMgt_nOfsNTarIdlDyn_C = 0;
const uint16  SftyMgt_nTarIdlDynThd_C = 0;
const uint16  SftyMgt_nTarIdlIni_C = 0;
const uint16  SftyMgt_nTarIdlMax_C = 0;
const uint16  SftyMgt_tiDlyNTarIdlDftOn_C = 0;
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
boolean NTARIDLCHK_bTqSysAcvTqSysPrev;
boolean NTARIDLCHK_bTurnOnDlyTMS1;
boolean NTARIDLCHK_bTurnOnDlyTMS2;
boolean SftyMgt_bAcvIdlDynMon_MP;
boolean SftyMgt_bDgoNIdl;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16 NTARIDLCHK_u16CounterTMS1;
uint16 NTARIDLCHK_u16CounterTMS2;
uint16 NTARIDLCHK_u16TarIdlDynIdSysPrev;
uint16 SftyMgt_nTarIdlStrt_MP;
uint16 SftyMgt_nTarIdlTqSysDly_MP;
uint16 SftyMgt_nTarIdlTqSysTol_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

