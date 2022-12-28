/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQIDCENGREAL                                             */
/*                                                                            */
/* !Module         : TQIDCENGREAL                                             */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQIDCENGREAL.H                                           */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQIDCENGREAL/TQIDCENGR$*/
/* $Revision::   1.5      $$Author::   MBENFRAD       $$Date::   02 May 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQIDCENGREAL_H
#define TQIDCENGREAL_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_AGIGADVDIFOPTMCURX_A_COLS      (8)
#define SFTYMGT_AGIGOPTMESTIM_M_LNS           (8)
#define SFTYMGT_AGIGOPTMESTIM_M_COLS           (8)
#define SFTYMGT_EFFIGOPTESTIM_T_COLS           (8)
#define SFTYMGT_NCKFIL_AGIGOPTMX_A_COLS        (8)
#define SFTYMGT_NCKFIL_RAIRLDX_A_COLS          (8)
#define SFTYMGT_NCKFIL_TQIDCAGIGMINX_A_COLS    (8)
#define SFTYMGT_NCKFIL_TQIDCOPTMX_A_COLS       (8)
#define SFTYMGT_PDSTHR_AGIGOPTMY_A_COLS        (8)
#define SFTYMGT_PDSTHR_RAIRLDY_A_COLS          (8)
#define SFTYMGT_PDSTHR_TQIDCAGIGMINY_A_COLS    (8)
#define SFTYMGT_RAIRLDESTIM_M_LNS             (8)
#define SFTYMGT_RAIRLDESTIM_M_COLS             (8)
#define SFTYMGT_RAIRLDESTIM_TQIDCOPTMY_A_COLS  (8)
#define SftyMgt_tiSdlTqIdcEngReal_SC      40           /* 40 */
#define SFTYMGT_TQIDCAGIGMIN_M_LNS            (8)
#define SFTYMGT_TQIDCAGIGMIN_M_COLS            (8)
#define SFTYMGT_TQIDCOPTMESTIM_M_LNS          (8)
#define SFTYMGT_TQIDCOPTMESTIM_M_COLS          (8)

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
extern const boolean  SftyMgt_bTqIdcAgIgMinCor_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_noCyl_C;
extern const uint8  SftyMgt_tiAirLdTauFilDown_C;
extern const uint8  SftyMgt_tiAirLdTauFilUp_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const uint16  SftyMgt_agIgAdvDifOptmCurX_A[SFTYMGT_AGIGADVDIFOPTMCURX_A_COLS];
extern const uint16  SftyMgt_agIgOptmEstim_M[SFTYMGT_AGIGOPTMESTIM_M_LNS][SFTYMGT_AGIGOPTMESTIM_M_COLS];
extern const uint16  SftyMgt_effIgOptEstim_T[SFTYMGT_EFFIGOPTESTIM_T_COLS];
extern const uint16  SftyMgt_nCkFil_agIgOptmX_A[SFTYMGT_NCKFIL_AGIGOPTMX_A_COLS];
extern const uint16  SftyMgt_nCkFil_rAirLdX_A[SFTYMGT_NCKFIL_RAIRLDX_A_COLS];
extern const uint16  SftyMgt_nCkFil_TqIdcAgIgMinX_A[SFTYMGT_NCKFIL_TQIDCAGIGMINX_A_COLS];
extern const uint16  SftyMgt_nCkFil_TqIdcOptmX_A[SFTYMGT_NCKFIL_TQIDCOPTMX_A_COLS];
extern const uint16  SftyMgt_pDsThr_agIgOptmY_A[SFTYMGT_PDSTHR_AGIGOPTMY_A_COLS];
extern const uint16  SftyMgt_pDsThr_rAirLdY_A[SFTYMGT_PDSTHR_RAIRLDY_A_COLS];
extern const uint16  SftyMgt_pDsThr_TqIdcAgIgMinY_A[SFTYMGT_PDSTHR_TQIDCAGIGMINY_A_COLS];
extern const uint16  SftyMgt_rAirLdEstim_M[SFTYMGT_RAIRLDESTIM_M_LNS][SFTYMGT_RAIRLDESTIM_M_COLS];
extern const uint16  SftyMgt_rAirLdEstim_TqIdcOptmY_A[SFTYMGT_RAIRLDESTIM_TQIDCOPTMY_A_COLS];
extern const uint16  SftyMgt_rAirLdGrdThd_C;
extern const uint16  SftyMgt_TqIdcAgIgMin_M[SFTYMGT_TQIDCAGIGMIN_M_LNS][SFTYMGT_TQIDCAGIGMIN_M_COLS];
extern const uint16  SftyMgt_tqIdcEngRealMax_C;
extern const uint16  SftyMgt_tqIdcOptmEstim_M[SFTYMGT_TQIDCOPTMESTIM_M_LNS][SFTYMGT_TQIDCOPTMESTIM_M_COLS];
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqIdcAgIgMin;
extern uint16 SftyMgt_tqIdcEngCurEstim;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_tqIdcEngReal(void);
void TQIDCENGREAL_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQIDCENGREAL_H */

/*-------------------------------- end of file -------------------------------*/
