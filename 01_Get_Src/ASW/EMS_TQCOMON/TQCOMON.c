/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCOMON                                                  */
/*                                                                            */
/* !Module         : TQCOMON                                                  */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQCOMON.C75                                              */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMON/TQCOMON.c7v   $*/
/* $Revision::   1.1      $$Author::   acabresp       $$Date::   19 Oct 2009 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQCOMON.h"
#include "TQCOMON_l.h"


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define TMS_START_SEC_CALIB_UNSPECIFIED
#include "MemMap.h"

const boolean      SftyMgt_bNRegGBxCf_C = 0;
const boolean      SftyMgt_bTqCkEfcFilCf_C = 0;
const boolean      SftyMgt_bTqGBxCf_C = 0;
const uint16      SftyMgt_tiDlyTqCoChaDftOff_C = 0;
const uint16      SftyMgt_tiDlyTqCoChaDftOn_C = 0;
const uint16      SftyMgt_tqErrThdSftyTqCoCha_C = 0;
const uint8      TQCOMON_u8Inhib = 0;

#define TMS_STOP_SEC_CALIB_UNSPECIFIED
#include "MemMap.h"


/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define TMS_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

boolean  SftyMgt_bDgoCoCha;
boolean  TQCOMON_bDebounceInputPrev;
sint16  SftyMgt_tqCkEfcFilCo;
sint16  SftyMgt_tqCoCha_MP;
sint16  SftyMgt_tqEfcCoGBx;
sint16  SftyMgt_tqEfcReqCoCha;
sint16  SftyMgt_tqEfcReqCoVSCtl;
sint16  SftyMgt_tqIdcCoGBx;
sint16  SftyMgt_tqIdcCoNReg;
sint16  SftyMgt_tqIdcEngLimCo;
uint16  TQCOMON_u16TiDlyCounter;

#define TMS_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*-------------------------------- end of file -------------------------------*/
