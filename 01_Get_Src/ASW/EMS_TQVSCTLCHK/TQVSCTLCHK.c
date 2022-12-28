/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQVSCTLCHK                                               */
/*                                                                            */
/* !Module         : TQVSCTLCHK                                               */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQVSCTLCHK.C75                                           */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQVSCTLCHK/TQVSCTLCHK.$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   12 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQVSCTLCHK.h"
#include "TQVSCTLCHK_l.h"

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
const boolean  SftyMgt_bInhAcvNotEfcTqPTMin_C = 0;
const boolean  SftyMgt_bInhDftBrkPedPress_C = 0;
const boolean  SftyMgt_bInhDftTqVSCtl_C = 0;
const boolean  SftyMgt_bTypTqVSCtl_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_stAcvEfcTqPTMinVSCtl_C = 0;
const uint8  SftyMgt_stAcvNotEfcTqPTMin_C = 0;
const uint8  SftyMgt_tiDlyOnDftTqVSCtl_C = 0;
const uint8  SftyMgt_tiDlyOnDftVSCtl_C = 0;
const uint8  TQVSCTLCHK_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqCkEfcThdVSCtl_C = 0;
const sint16  SftyMgt_tqOfsDftVSCtl_C = 0;
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
boolean SftyMgt_bDeac0TqVSCtl;
boolean SftyMgt_bDftBrkPedPress_MP;
boolean SftyMgt_bDftTqVSCtl_MP;
boolean SftyMgt_bDgoVSCtl;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_tqCkEfc_MP;
sint16 SftyMgt_tqEfcVSCtlSum_MP;
uint16 TQCKEFCFIL_u16BrkPedPressCounter;
uint16 TQCKEFCFIL_u16TqVSCtl_Counter;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

