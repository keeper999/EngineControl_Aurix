/***************************************************************************
;**
;** FILE NAME      : TQACRES.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQACRES.H"
#include "TQACRES_L.H"
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
const boolean  TqRes_bAuthFrzAC_C = 0;
const boolean  TqRes_bInhResACCluOp_C = 0;
const uint8  TQACRES_u8Inhib = 0;
const uint8  TqRes_pAC_A[TQRES_PAC_A_COLS] = {0};
const uint8  TqRes_pwrACSftyACRes_C = 0;
const uint8  TqRes_pwrACThrFrzAC_C = 0;
const uint8  TqRes_tiAC3Res_C = 0;
const uint8  TqRes_tiAC4Res_C = 0;
const uint8  TqRes_tiAC4ResTmpMax_C = 0;
const sint16  TqRes_tqDecMaxACRes_C = 0;
const uint16  TqRes_nEngThdOptmRes_C = 0;
const uint16  TqRes_nEngThrFrzAC_C = 0;
const uint16  TqRes_tqAC3Res_T[TQRES_TQAC3RES_T_COLS] = {0};
const uint16  TqRes_tqAC4Res_A[TQRES_TQAC4RES_A_COLS] = {0};
const uint16  TqRes_tqAC4Res_T[TQRES_TQAC4RES_T_COLS] = {0};
const uint16  TqRes_tqDftValACRes_C = 0;
const uint16  TqRes_tqIncMaxACRes_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 TQACRES_StActual_Status;
boolean Ext_bACCluAuth_prev;
boolean TQACRES_bTqRes_bCdnACRes_Prev;
boolean TqRes_bAcvOptmTqACRes;
boolean TqRes_bCdnAC3CluAuth_MP;
boolean TqRes_bCdnAC3Res;
boolean TqRes_bCdnAC4Res;
boolean TqRes_bCdnACRes;
boolean TqRes_bCdnNEngFrzAC_MP;
boolean TqRes_bCdnPwrFrzAC_MP;
boolean TqRes_bDftAC4SwtOn;
uint16 TQACRES_u16tiResAC3;
uint16 TqRes_tiAC4Res;
uint16 TqRes_tiAC4ResTmpMax;
uint16 TqRes_tiAcvAC4Res_MP;
uint16 TqRes_tiCplAC4Res_MP;
uint16 TqRes_tqAC3Res;
uint16 TqRes_tqAC4Raw_MP;
uint16 TqRes_tqAC4Res;
uint16 TqRes_tqACRes;
uint16 TqRes_tqACResRaw;
uint16 TqRes_tqACResSat_MP;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

