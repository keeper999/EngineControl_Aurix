/***************************************************************************
;**
;** FILE NAME      : TQCATHEATRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQCATHEATRES.H"
#include "TQCATHEATRES_L.H"
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

#pragma section ".calib" a
const uint8  TQCATHEATRES_u8Inhib = 0;
const uint16  TqRes_nEngEOMResMod1_A[TQRES_NENGEOMRESMOD1_A_COLS] = {0};
const uint16  TqRes_nEngEOMResMod2_A[TQRES_NENGEOMRESMOD2_A_COLS] = {0};
const uint16  TqRes_nEngEOMResMod3_A[TQRES_NENGEOMRESMOD3_A_COLS] = {0};
const uint16  TqRes_nEngEOMResMod4_A[TQRES_NENGEOMRESMOD4_A_COLS] = {0};
const uint16  TqRes_nEngEOMResMod5_A[TQRES_NENGEOMRESMOD5_A_COLS] = {0};
const uint16  TqRes_nEngEOMResMod6_A[TQRES_NENGEOMRESMOD6_A_COLS] = {0};
const uint16  TqRes_nEngEOMResMod7_A[TQRES_NENGEOMRESMOD7_A_COLS] = {0};
const uint16  TqRes_tqEOMResMod1_M[TQRES_TQEOMRESMOD1_M_LNS][TQRES_TQEOMRESMOD1_M_COLS] = {0};
const uint16  TqRes_tqEOMResMod2_M[TQRES_TQEOMRESMOD2_M_LNS][TQRES_TQEOMRESMOD2_M_COLS] = {0};
const uint16  TqRes_tqEOMResMod3_M[TQRES_TQEOMRESMOD3_M_LNS][TQRES_TQEOMRESMOD3_M_COLS] = {0};
const uint16  TqRes_tqEOMResMod4_M[TQRES_TQEOMRESMOD4_M_LNS][TQRES_TQEOMRESMOD4_M_COLS] = {0};
const uint16  TqRes_tqEOMResMod5_M[TQRES_TQEOMRESMOD5_M_LNS][TQRES_TQEOMRESMOD5_M_COLS] = {0};
const uint16  TqRes_tqEOMResMod6_M[TQRES_TQEOMRESMOD6_M_LNS][TQRES_TQEOMRESMOD6_M_COLS] = {0};
const uint16  TqRes_tqEOMResMod7_M[TQRES_TQEOMRESMOD7_M_LNS][TQRES_TQEOMRESMOD7_M_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod1_A[TQRES_TQIDCAIREOMRESMOD1_A_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod2_A[TQRES_TQIDCAIREOMRESMOD2_A_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod3_A[TQRES_TQIDCAIREOMRESMOD3_A_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod4_A[TQRES_TQIDCAIREOMRESMOD4_A_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod5_A[TQRES_TQIDCAIREOMRESMOD5_A_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod6_A[TQRES_TQIDCAIREOMRESMOD6_A_COLS] = {0};
const uint16  TqRes_tqIdcAirEOMResMod7_A[TQRES_TQIDCAIREOMRESMOD7_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TqRes_bAcvEOMResMod1;
boolean TqRes_bAcvEOMResMod2;
boolean TqRes_bAcvEOMResMod3;
boolean TqRes_bAcvEOMResMod4;
boolean TqRes_bAcvEOMResMod5;
boolean TqRes_bAcvEOMResMod6;
boolean TqRes_bAcvEOMResMod7;
boolean TqRes_bAcvEOMResMod8;
boolean TqRes_prm_bAcvEOMResMod[TQRES_PRM_BACVEOMRESMOD_COLS];
uint8 TqRes_facBasModCur;
uint8 TqRes_facBasModTar;
uint8 TqRes_facTranMod;
uint8 TqRes_idxBas1ModCur;
uint8 TqRes_idxBas1ModTar;
uint8 TqRes_idxBas2ModCur;
uint8 TqRes_idxBas2ModTar;
uint16 TqRes_prm_tqEOMRes[TQRES_PRM_TQEOMRES_COLS];
uint16 TqRes_tqBas1ModCur;
uint16 TqRes_tqBas1ModTar;
uint16 TqRes_tqBas2ModCur;
uint16 TqRes_tqBas2ModTar;
uint16 TqRes_tqEOMRes;
uint16 TqRes_tqEOMResMod1;
uint16 TqRes_tqEOMResMod2;
uint16 TqRes_tqEOMResMod3;
uint16 TqRes_tqEOMResMod4;
uint16 TqRes_tqEOMResMod5;
uint16 TqRes_tqEOMResMod6;
uint16 TqRes_tqEOMResMod7;
uint16 TqRes_tqEOMResMod8;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

