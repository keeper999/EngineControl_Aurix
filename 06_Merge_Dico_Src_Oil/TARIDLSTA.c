/***************************************************************************
;**
;** FILE NAME      : TARIDLSTA.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TARIDLSTA.H"
#include "TARIDLSTA_L.H"
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
const boolean  TqSys_bAcvNIdlATReq_C = 0;
const boolean  TqSys_bAcvTarIdlSpdAC_C = 0;
const boolean  TqSys_bAcvTarIdlSpdAlt_C = 0;
const boolean  TqSys_bAcvTarIdlSpdBatt_C = 0;
const boolean  TqSys_bAcvTarIdlSpdWaHt_C = 0;
const boolean  TqSys_bCfNTarIdlAC_C = 0;
const boolean  TqSys_bCfTEngTarIdlNorm_C = 0;
const boolean  TqSys_bCVC_C = 0;
const boolean  TqSys_bIniNTarIdlStrt_C = 0;
const sint8  TqSys_uErrMinTarIdlBatt_C = 0;
const uint8  TARIDLSTA_u8Inhib = 0;
const uint8  TqSys_ctHiTarIdlBatt_C = 0;
const uint8  TqSys_ctLoTarIdlBatt_C = 0;
const uint8  TqSys_ctMaxTarIdlBatt_C = 0;
const uint8  TqSys_facCorTAltTarIdl_C = 0;
const uint8  TqSys_facCorTarIdlBatt_C = 0;
const uint8  TqSys_facCorTarIdlStrt_T[TQSYS_FACCORTARIDLSTRT_T_COLS] = {0};
const uint8  TqSys_facFilTqACTarIdl_C = 0;
const uint8  TqSys_facFilTqAltTarIdl_C = 0;
const uint8  TqSys_facPAirTarIdlVacPmp_C = 0;
const uint8  TqSys_facTIdlAsiAlt_C = 0;
const uint8  TqSys_noGearTarIdlDft_C = 0;
const uint8  TqSys_pAirOfsTarIdlVacPmp_C = 0;
const uint8  TqSys_pThdTarIdlStgPmp_C = 0;
const uint8  TqSys_spdThdHiLihPed_C = 0;
const uint8  TqSys_spdThdLoLihPed_C = 0;
const uint8  TqSys_spdThdNeutHi_C = 0;
const uint8  TqSys_spdThdNeutLo_C = 0;
const uint8  TqSys_spdVehHiTarIdlAC_C = 0;
const uint8  TqSys_spdVehHiTarIdlAlt_C = 0;
const uint8  TqSys_spdVehLimIdl_C = 0;
const uint8  TqSys_spdVehLoTarIdlAC_C = 0;
const uint8  TqSys_spdVehLoTarIdlAlt_C = 0;
const uint8  TqSys_spdVehNIdlATReq_A[TQSYS_SPDVEHNIDLATREQ_A_COLS] = {0};
const uint8  TqSys_spdVehTarIdlVacPmp_C = 0;
const uint8  TqSys_spdVehThdAcvNIdlATReq_C = 0;
const uint8  TqSys_tAirTarIdlAC_A[TQSYS_TAIRTARIDLAC_A_COLS] = {0};
const uint8  TqSys_tAltTarIdl_A[TQSYS_TALTTARIDL_A_COLS] = {0};
const uint8  TqSys_tCoTarIdlUH_A[TQSYS_TCOTARIDLUH_A_COLS] = {0};
const uint8  TqSys_tEngTarIdl_A[TQSYS_TENGTARIDL_A_COLS] = {0};
const uint8  TqSys_tOilTarIdl_A[TQSYS_TOILTARIDL_A_COLS] = {0};
const uint8  TqSys_uThdTarIdlBatt_C = 0;
const sint16  TqSys_nDecMaxTarIdl_C = 0;
const sint16  TqSys_nDecTarIdlAC_C = 0;
const sint16  TqSys_nDecTarIdlAlt_C = 0;
const sint16  TqSys_nDecTarIdlATBas_C = 0;
const sint16  TqSys_nDecTarIdlATEgd_C = 0;
const sint16  TqSys_nDecTarIdlATInc_C = 0;
const sint16  TqSys_nDecTarIdlBatt_C = 0;
const sint16  TqSys_nDecTarIdlCanPurg_C = 0;
const sint16  TqSys_nDecTarIdlEngSpdLim_C = 0;
const sint16  TqSys_nDecTarIdlLihPed_C = 0;
const sint16  TqSys_nDecTarIdlNorm_C = 0;
const sint16  TqSys_nDecTarIdlStgPmp_C = 0;
const sint16  TqSys_nDecTarIdlUH_C = 0;
const sint16  TqSys_nDecTarIdlVacPmp_C = 0;
const sint16  TqSys_nDecTarIdlWaHt_C = 0;
const sint16  TqSys_tEngDftTarIdl_C = 0;
const uint16  TqSys_facFrntWhlGBxOut_C = 0;
const uint16  TqSys_facSpdVehGBxOut_C = 0;
const uint16  TqSys_facTarIdlCanPurg_A[TQSYS_FACTARIDLCANPURG_A_COLS] = {0};
const uint16  TqSys_nExtMaxTarIdlAC_C = 0;
const uint16  TqSys_nExtMinTarIdlAC_C = 0;
const uint16  TqSys_nGBxDftTarIdl_C = 0;
const uint16  TqSys_nGBxOut_A[TQSYS_NGBXOUT_A_COLS] = {0};
const uint16  TqSys_nGBxOutThdHi_C = 0;
const uint16  TqSys_nGBxOutThdLo_C = 0;
const uint16  TqSys_nIdlATReq_T[TQSYS_NIDLATREQ_T_COLS] = {0};
const uint16  TqSys_nIncMaxTarIdl_C = 0;
const uint16  TqSys_nIncTarIdlAC_C = 0;
const uint16  TqSys_nIncTarIdlAlt_C = 0;
const uint16  TqSys_nIncTarIdlATBas_C = 0;
const uint16  TqSys_nIncTarIdlBatt_C = 0;
const uint16  TqSys_nIncTarIdlCanPurg_C = 0;
const uint16  TqSys_nIncTarIdlEngSpdLim_C = 0;
const uint16  TqSys_nIncTarIdlLihPed_C = 0;
const uint16  TqSys_nIncTarIdlNorm_C = 0;
const uint16  TqSys_nIncTarIdlStgPmp_C = 0;
const uint16  TqSys_nIncTarIdlUH_C = 0;
const uint16  TqSys_nIncTarIdlVacPmp_C = 0;
const uint16  TqSys_nIncTarIdlWaHt_C = 0;
const uint16  TqSys_nOfsHiIdlClc_C = 0;
const uint16  TqSys_nOfsLoIdlClc_C = 0;
const uint16  TqSys_nOfsTarIdlPAir_T[TQSYS_NOFSTARIDLPAIR_T_COLS] = {0};
const uint16  TqSys_nOfsTarIdlStrt_M[TQSYS_NOFSTARIDLSTRT_M_LNS][TQSYS_NOFSTARIDLSTRT_M_COLS] = {0};
const uint16  TqSys_nTarIdlAC_M[TQSYS_NTARIDLAC_M_LNS][TQSYS_NTARIDLAC_M_COLS] = {0};
const uint16  TqSys_nTarIdlACTq_T[TQSYS_NTARIDLACTQ_T_COLS] = {0};
const uint16  TqSys_nTarIdlAltCmp_T[TQSYS_NTARIDLALTCMP_T_COLS] = {0};
const uint16  TqSys_nTarIdlAltTq_T[TQSYS_NTARIDLALTTQ_T_COLS] = {0};
const uint16  TqSys_nTarIdlATBas1_M[TQSYS_NTARIDLATBAS1_M_LNS][TQSYS_NTARIDLATBAS1_M_COLS] = {0};
const uint16  TqSys_nTarIdlATBas2_M[TQSYS_NTARIDLATBAS2_M_LNS][TQSYS_NTARIDLATBAS2_M_COLS] = {0};
const uint16  TqSys_nTarIdlATInc_M[TQSYS_NTARIDLATINC_M_LNS][TQSYS_NTARIDLATINC_M_COLS] = {0};
const uint16  TqSys_nTarIdlBatt_C = 0;
const uint16  TqSys_nTarIdlCanPurg_T[TQSYS_NTARIDLCANPURG_T_COLS] = {0};
const uint16  TqSys_nTarIdlEngSpdLim_C = 0;
const uint16  TqSys_nTarIdlIni_C = 0;
const uint16  TqSys_nTarIdlLihPedRun_C = 0;
const uint16  TqSys_nTarIdlLihPedRunBrk_C = 0;
const uint16  TqSys_nTarIdlLihPedStop_C = 0;
const uint16  TqSys_nTarIdlLihPedStopBrk_C = 0;
const uint16  TqSys_nTarIdlMax_C = 0;
const uint16  TqSys_nTarIdlMin_C = 0;
const uint16  TqSys_nTarIdlNorm1_M[TQSYS_NTARIDLNORM1_M_LNS][TQSYS_NTARIDLNORM1_M_COLS] = {0};
const uint16  TqSys_nTarIdlNorm2_M[TQSYS_NTARIDLNORM2_M_LNS][TQSYS_NTARIDLNORM2_M_COLS] = {0};
const uint16  TqSys_nTarIdlStgPmp_C = 0;
const uint16  TqSys_nTarIdlTOil_T[TQSYS_NTARIDLTOIL_T_COLS] = {0};
const uint16  TqSys_nTarIdlUH_T[TQSYS_NTARIDLUH_T_COLS] = {0};
const uint16  TqSys_nTarIdlVacPmp_C = 0;
const uint16  TqSys_nTarIdlVacPmpDft_C = 0;
const uint16  TqSys_nTarIdlWaHt_C = 0;
const uint16  TqSys_pAirTarIdl_A[TQSYS_PAIRTARIDL_A_COLS] = {0};
const uint16  TqSys_tiAcvTarIdlATEgd_C = 0;
const uint16  TqSys_tiAcvTarIdlStgPmp_C = 0;
const uint16  TqSys_tiEngRunTarIdl_A[TQSYS_TIENGRUNTARIDL_A_COLS] = {0};
const uint16  TqSys_tiStopTarIdl_A[TQSYS_TISTOPTARIDL_A_COLS] = {0};
const uint16  TqSys_tiStrtDlyTarIdlCus_C = 0;
const uint16  TqSys_tiStrtDlyTarIdlTakeOff_C = 0;
const uint16  TqSys_tqACFilTarIdl_A[TQSYS_TQACFILTARIDL_A_COLS] = {0};
const uint16  TqSys_tqAltFilTarIdl_A[TQSYS_TQALTFILTARIDL_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TARIDLSTA_bATCunFlipFlopOut;
boolean TARIDLSTA_bEnableRateLimiter;
boolean TARIDLSTA_bEngAsiReqTrvPrev;
boolean TARIDLSTA_bIdlTarExtRisingEdge;
boolean TARIDLSTA_bNegHysTarIdlAC;
boolean TARIDLSTA_bPosHysGBxOut;
boolean TARIDLSTA_bPosHysLihPedOut;
boolean TARIDLSTA_bPosHysNeutOut;
boolean TARIDLSTA_bTarIdlACFlipFlopOut;
boolean TARIDLSTA_bTarIdlAltFlipFlopOut;
boolean TARIDLSTA_bTarIdlWaHtFlipFlopOut;
boolean TARIDLSTA_bTurnOffDlyRisingEdge;
boolean TARIDLSTA_bTurnOffDlyStgPmp;
boolean TqSys_bAcvBrkTarIdl;
boolean TqSys_bAcvSpdCdnTarIdlAlt;
boolean TqSys_bAcvTarIdlAC_MP;
boolean TqSys_bAcvTarIdlAltCmpReq_MP;
boolean TqSys_bAcvTarIdlATBas_MP;
boolean TqSys_bAcvTarIdlATEgd_MP;
boolean TqSys_bAcvTarIdlATInc_MP;
boolean TqSys_bAcvTarIdlBatt_MP;
boolean TqSys_bAcvTarIdlCanPurg_MP;
boolean TqSys_bAcvTarIdlLihPed_MP;
boolean TqSys_bAcvTarIdlSpdLim_MP;
boolean TqSys_bAcvTarIdlStgPmp_MP;
boolean TqSys_bAcvTarIdlTqAC;
boolean TqSys_bAcvTarIdlTqAlt;
boolean TqSys_bAcvTarIdlVacPmp_MP;
boolean TqSys_bAcvTarIdlWaHt_MP;
boolean TqSys_bAuthTarIdlCus;
boolean TqSys_bIdlClcReq;
boolean TqSys_bTarIdlSpd;
boolean TqSys_stTarIdlBatt_MP;
boolean TqSys_stTarIdlNorm_MP;
uint32 TARIDLSTA_u32TqACFilTarIdlMem;
uint8 TARIDLSTA_u8DragRedPrev;
uint8 TqSys_noGearTarIdl;
sint16 TARIDLSTA_s16BaryCentreOut;
sint16 TqSys_tAltTarIdl_MP;
sint16 TqSys_tEngTarIdl_MP;
sint16 TqSys_tqAltFilTarIdl_MP;
uint16 TARIDLSTA_u16ATEngTrnOffDlyCntr;
uint16 TARIDLSTA_u16EngSpdLimSlewOut;
uint16 TARIDLSTA_u16LihPedSlewOut;
uint16 TARIDLSTA_u16NeutSlewInput;
uint16 TARIDLSTA_u16NeutSlewOut;
uint16 TARIDLSTA_u16NormSlewInput;
uint16 TARIDLSTA_u16StgPmpTrnOffDlyCntr;
uint16 TqSys_ctTarIdlBatt_MP;
uint16 TqSys_nGBxOut;
uint16 TqSys_nTarIdlAC;
uint16 TqSys_nTarIdlAlt;
uint16 TqSys_nTarIdlAT;
uint16 TqSys_nTarIdlATBas;
uint16 TqSys_nTarIdlATEgd;
uint16 TqSys_nTarIdlATInc;
uint16 TqSys_nTarIdlATReq;
uint16 TqSys_nTarIdlBatt;
uint16 TqSys_nTarIdlCanPurg;
uint16 TqSys_nTarIdlCus;
uint16 TqSys_nTarIdlDft;
uint16 TqSys_nTarIdlDsl;
uint16 TqSys_nTarIdlEng;
uint16 TqSys_nTarIdlGsl;
uint16 TqSys_nTarIdlNorm;
uint16 TqSys_nTarIdlPrev;
uint16 TqSys_nTarIdlSfty;
uint16 TqSys_nTarIdlStgPmp;
uint16 TqSys_nTarIdlTOil;
uint16 TqSys_nTarIdlUH;
uint16 TqSys_nTarIdlVacPmp;
uint16 TqSys_nTarIdlWaHt;
uint16 TqSys_tqACFilTarIdl_MP;
sint32 TARIDLSTA_s32TqAltFilTarIdlMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

