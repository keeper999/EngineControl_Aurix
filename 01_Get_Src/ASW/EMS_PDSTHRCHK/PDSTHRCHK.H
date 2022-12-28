/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : PDSTHRCHK                                                */
/*                                                                            */
/* !Module         : PDSTHRCHK                                                */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : PDSTHRCHK.H                                              */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/PDSTHRCHK/PDSTHRCHK.H_$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   23 May 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef PDSTHRCHK_H
#define PDSTHRCHK_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_FACAIREXTCOR_T_COLS            (10)
#define SFTYMGT_NCKFILSFTYPRESX_A_COLS         (8)
#define SFTYMGT_NCKFILTRBACTX_A_COLS           (8)
#define SFTYMGT_NPRESOFFSSFTY_A_COLS           (8)
#define SFTYMGT_PAIREXT_A_COLS                 (10)
#define SFTYMGT_PDSTHRESTIMBAS1_M_LNS         (8)
#define SFTYMGT_PDSTHRESTIMBAS1_M_COLS         (8)
#define SFTYMGT_PDSTHRESTIMBAS2_M_LNS         (8)
#define SFTYMGT_PDSTHRESTIMBAS2_M_COLS         (8)
#define SFTYMGT_PDSTHROFS_M_LNS               (8)
#define SFTYMGT_PDSTHROFS_M_COLS               (8)
#define SFTYMGT_POFFSSFTY_T_COLS               (8)
#define SFTYMGT_POSNTHRSFTYPRESY_A_COLS        (8)
#define SFTYMGT_PTRBACTCORBAS1_M_LNS          (8)
#define SFTYMGT_PTRBACTCORBAS1_M_COLS          (8)
#define SFTYMGT_PTRBACTCORBAS2_M_LNS          (8)
#define SFTYMGT_PTRBACTCORBAS2_M_COLS          (8)
#define SFTYMGT_ROPTRBACTFILY_A_COLS           (8)
#define SftyMgt_tiSdlPresDsThr_SC         40           /* 40 */

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
extern const boolean  SftyMgt_bInhDftAirExt_C;
extern const boolean  SftyMgt_bInhDftGrdAirExt_C;
extern const boolean  SftyMgt_bInhDftPresDsThr_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_facAirExtCor_T[SFTYMGT_FACAIREXTCOR_T_COLS];
extern const uint8  SftyMgt_tiAirExtFil_C;
extern const uint8  SftyMgt_tiDlyAirExtDft_C;
extern const uint8  SftyMgt_tiDlyGrdAirExtDft_C;
extern const uint8  SftyMgt_tiDlyPresDsThrOn_C;
extern const uint8  SftyMgt_tiOpTrbActFil_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16  SftyMgt_nCkFilSftyPresX_A[SFTYMGT_NCKFILSFTYPRESX_A_COLS];
extern const uint16  SftyMgt_nCkFilTrbActX_A[SFTYMGT_NCKFILTRBACTX_A_COLS];
extern const uint16  SftyMgt_nPresOffsSfty_A[SFTYMGT_NPRESOFFSSFTY_A_COLS];
extern const uint16  SftyMgt_pAirExt_A[SFTYMGT_PAIREXT_A_COLS];
extern const uint16  SftyMgt_pAirExtDftThd_C;
extern const uint16  SftyMgt_pDsThrEstimBas1_M[SFTYMGT_PDSTHRESTIMBAS1_M_LNS][SFTYMGT_PDSTHRESTIMBAS1_M_COLS];
extern const uint16  SftyMgt_pDsThrEstimBas2_M[SFTYMGT_PDSTHRESTIMBAS2_M_LNS][SFTYMGT_PDSTHRESTIMBAS2_M_COLS];
extern const uint16  SftyMgt_pDsThrOfs_M[SFTYMGT_PDSTHROFS_M_LNS][SFTYMGT_PDSTHROFS_M_COLS];
extern const uint16  SftyMgt_pGrdAirExtDftThd_C;
extern const uint16  SftyMgt_pOffsSfty_T[SFTYMGT_POFFSSFTY_T_COLS];
extern const uint16  SftyMgt_posnThrSftyPresY_A[SFTYMGT_POSNTHRSFTYPRESY_A_COLS];
extern const uint16  SftyMgt_pTrbActCorBas1_M[SFTYMGT_PTRBACTCORBAS1_M_LNS][SFTYMGT_PTRBACTCORBAS1_M_COLS];
extern const uint16  SftyMgt_pTrbActCorBas2_M[SFTYMGT_PTRBACTCORBAS2_M_LNS][SFTYMGT_PTRBACTCORBAS2_M_COLS];
extern const uint16  SftyMgt_rOpTrbActFilY_A[SFTYMGT_ROPTRBACTFILY_A_COLS];
extern const uint16  SftyMgt_rOpTrbActReqGrdThd_C;
extern const uint16  SftyMgt_tiOpTrbActFilDown_C;
extern const uint16  SftyMgt_tiOpTrbActFilUp_C;
extern const uint16  SftyMgt_tiPosnThrFil_C;
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
extern boolean SftyMgt_bDgoPresDsThr;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void PDSTHRCHK_vidEntryInit(void);
void SftyMgt_SdlMid_pDsThrChk(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* PDSTHRCHK_H */

/*-------------------------------- end of file -------------------------------*/
