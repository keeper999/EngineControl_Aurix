/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQIDLCHK                                                 */
/*                                                                            */
/* !Module         : TQIDLCHK                                                 */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQIDLCHK.C75                                             */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDLCHK/TQIDLCHK.c7v $*/
/* $Revision::   1.3      $$Author::   hmelloul       $$Date::   04 Jan 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQIDLCHK.h"
#include "TQIDLCHK_l.h"


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_facTqldcIdlFil_T[SFTYMGT_FACTQLDCIDLFIL_T_COLS] = {0};
const uint8  SftyMgt_tiDlyOfsIdlTakeOff_C = 0;
const uint8  SftyMgt_tiTqIdlDly_C = 0;
const uint8  TQIDLCHK_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqIdlThd_C = 0;
const uint16  SftyMgt_nOfsIdlTakeOff_C = 0;
const uint16  SftyMgt_nTarIdlOfs_C = 0;
const uint16  SftyMgt_tqldcIdl_A[SFTYMGT_TQLDCIDL_A_COLS] = {0};
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
boolean SftyMgt_bDgoIdlReg;
boolean SftyMgt_bDgoIdlTakeOff;
boolean SftyMgt_bDgoTqIdl;
boolean SftyMgt_bDgoTqIdlRaw_MP;
boolean SftyMgt_bEngNOnIdl_MP;
boolean SftyMgt_bErrNIdl_MP;
boolean SftyMgt_bTqGrd_MP;
boolean SftyMgt_bTqIdcIdl_MP;
boolean SftyMgt_bTqIdlErr_MP;
boolean TQIDLCHK_bOfsIdlTakeOffPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
uint8 SftyMgt_facTqIdcIdlFil_MP;
uint8 TQIDLCHK_u8DgoIdlRegTempo;
uint8 TQIDLCHK_u8ElValidateSlowTempo;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
sint16 SftyMgt_tqIdcIdlComp_MP;
sint16 SftyMgt_tqIdcIdlFil_MP;
uint16 TQIDLCHK_u16nOfsIdlTakeOffPrev;
uint16 TQIDLCHK_u16tqIdcIdlCompMP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
sint32 TQIDLCHK_s32tqIdcIdlFilMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"
/*-------------------------------- end of file -------------------------------*/
