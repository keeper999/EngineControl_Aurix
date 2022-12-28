/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCOMP                                                   */
/*                                                                            */
/* !Module         : TQCOMP                                                   */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQCOMP.C75                                               */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMP/TQCOMP.c7v     $*/
/* $Revision::   1.4.1.1  $$Author::   mbenfrad       $$Date::   15 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCOMP.h"
#include "TQCOMP_l.h"

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_tiRefDly_C = 0;
const uint8  SftyMgt_tiRefDlyZeroTq_C = 0;
const uint8  TQCOMP_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqErrTolZeroTq_C = 0;
const sint16  SftyMgt_tqOfst0Tq_C = 0;
const uint16  SftyMgt_nErrThdSftyCompX_A[SFTYMGT_NERRTHDSFTYCOMPX_A_COLS] = {0};
const uint16  SftyMgt_nOfsSftyComp_A[SFTYMGT_NOFSSFTYCOMP_A_COLS] = {0};
const uint16  SftyMgt_tqErrThdSftyComp_M[SFTYMGT_TQERRTHDSFTYCOMP_M_LNS][SFTYMGT_TQERRTHDSFTYCOMP_M_COLS] = {0};
const uint16  SftyMgt_tqErrThdSftyCompY_A[SFTYMGT_TQERRTHDSFTYCOMPY_A_COLS] = {0};
const uint16  SftyMgt_tqOfsSftyComp_T[SFTYMGT_TQOFSSFTYCOMP_T_COLS] = {0};
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
boolean SftyMgt_bDgoSftyTqComp;
boolean SftyMgt_bZeroTqOn_MP;
boolean TQCOMP_bCondInPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 TQCOMP_u8tiDlyTqComp;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_tqIdcEngLimMax_MP;
uint16 SftyMgt_tqOfsSftyComp_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

