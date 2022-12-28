/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCOMP                                                   */
/*                                                                            */
/* !Module         : TQCOMP                                                   */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQCOMP.H                                                 */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMP/TQCOMP.H_v     $*/
/* $Revision::   1.5.1.1  $$Author::   mbenfrad       $$Date::   15 Feb 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQCOMP_H
#define TQCOMP_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_NERRTHDSFTYCOMPX_A_COLS        (16)
#define SFTYMGT_NOFSSFTYCOMP_A_COLS            (16)
#define SFTYMGT_TQERRTHDSFTYCOMP_M_LNS        (16)
#define SFTYMGT_TQERRTHDSFTYCOMP_M_COLS        (16)
#define SFTYMGT_TQERRTHDSFTYCOMPY_A_COLS       (16)
#define SFTYMGT_TQOFSSFTYCOMP_T_COLS           (16)

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
extern const uint8  SftyMgt_tiRefDly_C;
extern const uint8  SftyMgt_tiRefDlyZeroTq_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_tqErrTolZeroTq_C;
extern const sint16  SftyMgt_tqOfst0Tq_C;
extern const uint16  SftyMgt_nErrThdSftyCompX_A[SFTYMGT_NERRTHDSFTYCOMPX_A_COLS];
extern const uint16  SftyMgt_nOfsSftyComp_A[SFTYMGT_NOFSSFTYCOMP_A_COLS];
extern const uint16  SftyMgt_tqErrThdSftyComp_M[SFTYMGT_TQERRTHDSFTYCOMP_M_LNS][SFTYMGT_TQERRTHDSFTYCOMP_M_COLS];
extern const uint16  SftyMgt_tqErrThdSftyCompY_A[SFTYMGT_TQERRTHDSFTYCOMPY_A_COLS];
extern const uint16  SftyMgt_tqOfsSftyComp_T[SFTYMGT_TQOFSSFTYCOMP_T_COLS];
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
extern boolean SftyMgt_bDgoSftyTqComp;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_tqComp(void);
void TQCOMP_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQCOMP_H */

/*-------------------------------- end of file -------------------------------*/
