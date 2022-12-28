/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : LIHCHK                                                   */
/*                                                                            */
/* !Module         : LIHCHK                                                   */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : LIHCHK.H                                                 */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/LIHCHK/LIHCHK.H_v     $*/
/* $Revision::   1.3.1.0  $$Author::   MBENFRAD       $$Date::   Nov 10 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef LIHCHK_H
#define LIHCHK_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_LihChk(void);
void LIHCHK_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define SFTYMGT_NENGSPDLIMHITHD_T_COLS         (8)
#define SFTYMGT_NENGSPDLIMLOTHD_T_COLS         (8)
#define SFTYMGT_NOGEARCORD_A_COLS              (8)


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16      SftyMgt_nEngLimThd_C;
extern const uint16      SftyMgt_nEngSpdLimHiThd_T[SFTYMGT_NENGSPDLIMHITHD_T_COLS  ];
extern const uint16      SftyMgt_nEngSpdLimLoThd_T[SFTYMGT_NENGSPDLIMLOTHD_T_COLS  ];
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"
#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8      SftyMgt_noGearCord_A[SFTYMGT_NOGEARCORD_A_COLS  ];
extern const uint8      SftyMgt_tiDlyDgoEngLim_C;
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
extern boolean SftyMgt_bDgoLih;
extern boolean  SftyMgt_bRcvMonRunLih;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#endif /* LIHCHK_H */

/*-------------------------------- end of file -------------------------------*/
