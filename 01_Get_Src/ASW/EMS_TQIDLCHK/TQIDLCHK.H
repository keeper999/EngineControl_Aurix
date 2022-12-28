/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQIDLCHK                                                 */
/*                                                                            */
/* !Module         : TQIDLCHK                                                 */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQIDLCHK.H                                               */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDLCHK/TQIDLCHK.H_v $*/
/* $Revision::   1.1      $$Author::   lthibaud       $$Date::   02 Feb 2010 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQIDLCHK_H
#define TQIDLCHK_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_nOfsIdlTakeOff(void);
void SftyMgt_SdlMid_IdlChk(void);
void SftyMgt_SdlMid_tqIdl(void);
void TQIDLCHK_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define SFTYMGT_FACTQLDCIDLFIL_T_COLS          (4)
#define SFTYMGT_TQLDCIDL_A_COLS                (4)


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8      SftyMgt_facTqldcIdlFil_T[SFTYMGT_FACTQLDCIDLFIL_T_COLS  ];
extern const uint8      SftyMgt_tiDlyOfsIdlTakeOff_C;
extern const uint8      SftyMgt_tiTqIdlDly_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16      SftyMgt_tqIdlThd_C;
extern const uint16      SftyMgt_nOfsIdlTakeOff_C;
extern const uint16      SftyMgt_nTarIdlOfs_C;
extern const uint16      SftyMgt_tqldcIdl_A[SFTYMGT_TQLDCIDL_A_COLS  ];
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
extern boolean  SftyMgt_bDgoTqIdl;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"


#endif /* TQIDLCHK_H */

/*-------------------------------- end of file -------------------------------*/
