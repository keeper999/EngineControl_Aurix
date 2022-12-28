/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQIDCENGREAL                                             */
/*                                                                            */
/* !Module         : TQIDCENGREAL                                             */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQIDCENGREAL.C75                                         */
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

#include "STD_TYPES.h"
#include "TQIDCENGREAL.h"
#include "TQIDCENGREAL_l.h"

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

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bTqIdcAgIgMinCor_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_noCyl_C = 0;
const uint8  SftyMgt_tiAirLdTauFilDown_C = 0;
const uint8  SftyMgt_tiAirLdTauFilUp_C = 0;
const uint8  TQIDCENGREAL_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const uint16  SftyMgt_agIgAdvDifOptmCurX_A[SFTYMGT_AGIGADVDIFOPTMCURX_A_COLS] = {0};
const uint16  SftyMgt_agIgOptmEstim_M[SFTYMGT_AGIGOPTMESTIM_M_LNS][SFTYMGT_AGIGOPTMESTIM_M_COLS] = {0};
const uint16  SftyMgt_effIgOptEstim_T[SFTYMGT_EFFIGOPTESTIM_T_COLS] = {0};
const uint16  SftyMgt_nCkFil_agIgOptmX_A[SFTYMGT_NCKFIL_AGIGOPTMX_A_COLS] = {0};
const uint16  SftyMgt_nCkFil_rAirLdX_A[SFTYMGT_NCKFIL_RAIRLDX_A_COLS] = {0};
const uint16  SftyMgt_nCkFil_TqIdcAgIgMinX_A[SFTYMGT_NCKFIL_TQIDCAGIGMINX_A_COLS] = {0};
const uint16  SftyMgt_nCkFil_TqIdcOptmX_A[SFTYMGT_NCKFIL_TQIDCOPTMX_A_COLS] = {0};
const uint16  SftyMgt_pDsThr_agIgOptmY_A[SFTYMGT_PDSTHR_AGIGOPTMY_A_COLS] = {0};
const uint16  SftyMgt_pDsThr_rAirLdY_A[SFTYMGT_PDSTHR_RAIRLDY_A_COLS] = {0};
const uint16  SftyMgt_pDsThr_TqIdcAgIgMinY_A[SFTYMGT_PDSTHR_TQIDCAGIGMINY_A_COLS] = {0};
const uint16  SftyMgt_rAirLdEstim_M[SFTYMGT_RAIRLDESTIM_M_LNS][SFTYMGT_RAIRLDESTIM_M_COLS] = {0};
const uint16  SftyMgt_rAirLdEstim_TqIdcOptmY_A[SFTYMGT_RAIRLDESTIM_TQIDCOPTMY_A_COLS] = {0};
const uint16  SftyMgt_rAirLdGrdThd_C = 0;
const uint16  SftyMgt_TqIdcAgIgMin_M[SFTYMGT_TQIDCAGIGMIN_M_LNS][SFTYMGT_TQIDCAGIGMIN_M_COLS] = {0};
const uint16  SftyMgt_tqIdcEngRealMax_C = 0;
const uint16  SftyMgt_tqIdcOptmEstim_M[SFTYMGT_TQIDCOPTMESTIM_M_LNS][SFTYMGT_TQIDCOPTMESTIM_M_COLS] = {0};
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
sint16 SftyMgt_agIgAdvOptmEstim;
sint16 SftyMgt_tqIdcAgIgMin;
sint16 TQIDCENGREAL_s16agIgAdvDifOptCur;
uint16 SftyMgt_effAdvTqIdcEstim;
uint16 SftyMgt_rAcvCyl;
uint16 SftyMgt_rAirLdEstim;
uint16 SftyMgt_rAirLdEstimRaw_MP;
uint16 SftyMgt_tqIdcEngCurEstim;
uint16 SftyMgt_tqIdcOptmEngCurEstim;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
sint32 SftyMgt_rAirLdEstimGrd_MP;
uint32 TQIDCENGREAL_u32FilterMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

