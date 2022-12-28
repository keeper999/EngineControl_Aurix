/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : LIHCHK                                                   */
/*                                                                            */
/* !Module         : LIHCHK                                                   */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : LIHCHK.C75                                               */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/LIHCHK/LIHCHK.c7v     $*/
/* $Revision::   1.2      $$Author::   lthibaud       $$Date::   09 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "LIHCHK.h"
#include "LIHCHK_l.h"


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16      SftyMgt_nEngLimThd_C = 0;
const uint16      SftyMgt_nEngSpdLimHiThd_T[SFTYMGT_NENGSPDLIMHITHD_T_COLS  ] = {0};
const uint16      SftyMgt_nEngSpdLimLoThd_T[SFTYMGT_NENGSPDLIMLOTHD_T_COLS  ] = {0};
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"
#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8      LIHCHK_u8Inhib = 0;
const uint8      SftyMgt_noGearCord_A[SFTYMGT_NOGEARCORD_A_COLS  ] = {0};
const uint8      SftyMgt_tiDlyDgoEngLim_C = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"


/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
boolean  LIHCHK_bTurnOnDelayInPrev;
boolean SftyMgt_bDgoLih;
boolean  SftyMgt_bRcvMonRunLih;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"
#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16  SftyMgt_nEngLim;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8  LIHCHK_u8TurnOnDelayCnt;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"


/*-------------------------------- end of file -------------------------------*/
