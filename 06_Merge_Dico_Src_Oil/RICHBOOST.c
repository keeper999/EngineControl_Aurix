/***************************************************************************
;**
;** FILE NAME      : RICHBOOST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "RICHBOOST.H"
#include "RICHBOOST_L.H"
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
const boolean  TqSys_bPrfInhRich_C = 0;
const boolean  TqSys_bPrfOvbAuthSel_C = 0;
const boolean  TqSys_bPrfRichAuthSel_C = 0;
const uint8  RICHBOOST_u8Inhib = 0;
const sint16  TqSys_tCoMesAuthRich_C = 0;
const sint16  TqSys_tqHysOvbAuth_C = 0;
const sint16  TqSys_tqHysRichAuth_C = 0;
const uint16  TqSys_nEngPrfMod_A[TQSYS_NENGPRFMOD_A_COLS] = {0};
const uint16  TqSys_nThdPrfAuthRich_C = 0;
const uint16  TqSys_rAccPHysAuthRich_C = 0;
const uint16  TqSys_rAccPHysOvbAuth_C = 0;
const uint16  TqSys_rAccPThdAuthOvb_T[TQSYS_RACCPTHDAUTHOVB_T_COLS] = {0};
const uint16  TqSys_rAccPThdAuthRich_T[TQSYS_RACCPTHDAUTHRICH_T_COLS] = {0};
const uint16  TqSys_rAccPThdPrfAuthRich_C = 0;
const uint16  TqSys_rAccPThdPrfInhRich_C = 0;
const uint16  TqSys_tiDlyAuthOvb_T[TQSYS_TIDLYAUTHOVB_T_COLS] = {0};
const uint16  TqSys_tiDlyAuthRich_T[TQSYS_TIDLYAUTHRICH_T_COLS] = {0};
const uint16  TqSys_tiDlyOvbRst_T[TQSYS_TIDLYOVBRST_T_COLS] = {0};
const uint16  TqSys_tiDlyPrfAuthOvb_C = 0;
const uint16  TqSys_tiPrfDlyAuthRich_C = 0;
const uint16  TqSys_tiPrfRtAuthRich_C = 0;
const uint16  TqSys_tiSpdLimDlyAuthOvb_C = 0;
const uint16  TqSys_tiSpdLimDlyAuthRich_C = 0;
const uint16  TqSys_tqEfcOfsOvbAuth_T[TQSYS_TQEFCOFSOVBAUTH_T_COLS] = {0};
const uint16  TqSys_tqIdcOfsAuthRich_T[TQSYS_TQIDCOFSAUTHRICH_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean RICHBOOST_bAcvVehSpdCtlLimPrev;
boolean RICHBOOST_bOvbAuthRawPrev;
boolean RICHBOOST_bRichAuthRawPrev;
boolean RICHBOOST_bStrt;
boolean TqSys_bAcvPrfDly;
boolean TqSys_bOvbAuthAccPCnd_MP;
boolean TqSys_bOvbAuthCnd;
boolean TqSys_bOvbAuthRaw;
boolean TqSys_bOvbAuthTqCnd_MP;
boolean TqSys_bRichAuthAccPCnd_MP;
boolean TqSys_bRichAuthCnd;
boolean TqSys_bRichAuthRaw;
boolean TqSys_bRichAuthTqCnd_MP;
boolean TqSys_bRstOvbCnd_MP;
boolean TqSys_bRstOvbSpdLimCnd_MP;
boolean TqSys_bRstRichCnd_MP;
boolean TqSys_bRstRichSpdLimCnd_MP;
uint16 RICHBOOST_u16OvbTurnOffDlyCntr;
uint16 RICHBOOST_u16OvbTurnOnDlyCntr;
uint16 RICHBOOST_u16RichTurnOffDlyCntr;
uint16 RICHBOOST_u16RichTurnOnDlyCntr;
uint16 RICHBOOST_u16TmrRstOut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

