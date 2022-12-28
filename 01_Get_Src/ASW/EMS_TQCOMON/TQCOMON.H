/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCOMON                                                  */
/*                                                                            */
/* !Module         : TQCOMON                                                  */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQCOMON.H                                                */
/*                                                                            */
/* !Scope          : Public                                                   */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMON/TQCOMON.H_v   $*/
/* $Revision::   1.3      $$Author::   lthibaud       $$Date::   06 Jan 2010 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQCOMON_H
#define TQCOMON_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define TMS_START_SEC_CODE
#include "MemMap.h"

void SftyMgt_SdlMid_tqCoVSCtl(void);
void SftyMgt_SdlMid_tqEfcCoGBx(void);
void SftyMgt_SdlMid_tqEfcFilCo(void);
void SftyMgt_SdlMid_tqEfcReqCoCha(void);
void SftyMgt_SdlMid_tqIdcCoGBx(void);
void SftyMgt_SdlMid_tqIdcCoNReg(void);
void SftyMgt_SdlMid_tqIdcEngLimCo(void);
void TQCOMON_vidEntryInit(void);

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/



/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
#define TMS_START_SEC_CALIB_UNSPECIFIED
#include "MemMap.h"

extern const boolean      SftyMgt_bNRegGBxCf_C;
extern const boolean      SftyMgt_bTqCkEfcFilCf_C;
extern const boolean      SftyMgt_bTqGBxCf_C;
extern const uint16      SftyMgt_tiDlyTqCoChaDftOff_C;
extern const uint16      SftyMgt_tiDlyTqCoChaDftOn_C;
extern const uint16      SftyMgt_tqErrThdSftyTqCoCha_C;

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

extern boolean  SftyMgt_bDgoCoCha;
extern sint16  SftyMgt_tqCkEfcFilCo;
extern sint16  SftyMgt_tqEfcCoGBx;
extern sint16  SftyMgt_tqEfcReqCoCha;
extern sint16  SftyMgt_tqEfcReqCoVSCtl;
extern sint16  SftyMgt_tqIdcCoGBx;
extern sint16  SftyMgt_tqIdcCoNReg;
extern sint16  SftyMgt_tqIdcEngLimCo;

#define TMS_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#endif /* TQCOMON_H */

/*-------------------------------- end of file -------------------------------*/
