/***************************************************************************
;**
;** FILE NAME      : ENGREQH.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGREQH.H"
#include "ENGREQH_L.H"
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
const boolean  EngReqH_bAcvStopAuthLsOk_C = 0;
const boolean  EngReqH_bAcvStopAuthPOil_C = 0;
const boolean  EngReqH_bAcvStopAuthStrtDly_C = 0;
const boolean  EngReqH_bAcvStopAuthTAir_C = 0;
const boolean  EngReqH_bAcvStopAuthTCo_C = 0;
const boolean  EngReqH_bAcvStopAuthTOil_C = 0;
const boolean  EngReqH_bAcvStopAuthTOxC_C = 0;
const boolean  EngReqH_bAcvStopAuthTTrb_C = 0;
const boolean  EngReqH_bCfNEngRstrtAutn_C = 0;
const boolean  EngReqH_bCfTEngRstrtAutn_C = 0;
const boolean  EngReqH_bDeacCdnRstrtThMgt_C = 0;
const boolean  EngReqH_bDeacCdnSTTRstrtTFu_C = 0;
const boolean  EngReqH_bDeacCdnSTTTOxCMin_C = 0;
const boolean  EngReqH_bDeacDsLs_C = 0;
const boolean  EngReqH_bDeacInhEngStopAFA_C = 0;
const boolean  EngReqH_bDeacInhEngStopCanPurg_C = 0;
const boolean  EngReqH_bDeacInhEngStopInjSys_C = 0;
const boolean  EngReqH_bDeacInhEngStopTqAdp_C = 0;
const boolean  EngReqH_bDeacRstrtTOxCMax_C = 0;
const boolean  EngReqH_bDeacUsLs_C = 0;
const boolean  EngReqH_bTestDeacCdnLsOk_C = 0;
const boolean  EngReqH_bTestDeacCdnPOil_C = 0;
const boolean  EngReqH_bTestDeacCdnStrtDly_C = 0;
const boolean  EngReqH_bTestDeacCdnTAir_C = 0;
const boolean  EngReqH_bTestDeacCdnTCo_C = 0;
const boolean  EngReqH_bTestDeacCdnTOil_C = 0;
const boolean  EngReqH_bTestDeacCdnTOxC_C = 0;
const boolean  EngReqH_bTestDeacCdnTTrb_C = 0;
const uint32  EngReqH_tiDlyTOxC_C = 0;
const uint8  EngReqH_ctTDCRstrtAutnAvl_C = 0;
const uint8  EngReqH_facFilNEng_C = 0;
const uint8  EngReqH_nEngRstrtAutnX_A[ENGREQH_NENGRSTRTAUTNX_A_COLS] = {0};
const uint8  EngReqH_noCyl_C = 0;
const uint8  EngReqH_pAirDeltaHysUnfav_C = 0;
const uint8  EngReqH_pAirExtHysUnfav_C = 0;
const uint8  EngReqH_pOilHysMaxAuthSTT_C = 0;
const uint8  EngReqH_stForcTAirSel_C = 0;
const uint8  EngReqH_stTAirSel_C = 0;
const uint8  EngReqH_stTAirTCoDft_C = 0;
const uint8  EngReqH_stTCoDftVal_C = 0;
const uint8  EngReqH_stTOilDftVal_C = 0;
const uint8  EngReqH_tCoMesStrtY_A[ENGREQH_TCOMESSTRTY_A_COLS] = {0};
const uint8  EngReqH_tCoMinStopAuth_T[ENGREQH_TCOMINSTOPAUTH_T_COLS] = {0};
const uint8  EngReqH_tCoStopAuthX_A[ENGREQH_TCOSTOPAUTHX_A_COLS] = {0};
const uint8  EngReqH_tiDlyAutSTTRstrt_C = 0;
const uint8  EngReqH_tiPOilStopAuth_T[ENGREQH_TIPOILSTOPAUTH_T_COLS] = {0};
const uint8  EngReqH_tiPOilStopAuthX_A[ENGREQH_TIPOILSTOPAUTHX_A_COLS] = {0};
const uint8  EngReqH_tTrbHysMaxStopAuth_C = 0;
const uint8  EngReqH_u8Inhib = 0;
const sint16  EngReqH_facTAirStopAuth_C = 0;
const sint16  EngReqH_pAirDeltaUnfav_C = 0;
const sint16  EngReqH_tAirMinStopAuth_C = 0;
const sint16  EngReqH_tAirVal_C = 0;
const sint16  EngReqH_tCoHysMaxStopAuth_C = 0;
const sint16  EngReqH_tCoHysMinStopAuth_C = 0;
const sint16  EngReqH_tCoMaxStopAuth_C = 0;
const sint16  EngReqH_tCoMin_tAirStopAuth_C = 0;
const sint16  EngReqH_tCoOfsStopAuth_C = 0;
const sint16  EngReqH_tFuHiLimSTTRstrtReq_C = 0;
const sint16  EngReqH_tFuHysLimSTTRstrtReq_C = 0;
const sint16  EngReqH_tOilHysMaxStopAuth_C = 0;
const sint16  EngReqH_tOilHysMinStopAuth_C = 0;
const sint16  EngReqH_tOilMaxStopAuth_C = 0;
const sint16  EngReqH_tOilMinStopAuth_C = 0;
const sint16  EngReqH_tOxCHysLimRstrtReq_C = 0;
const sint16  EngReqH_tTrbMaxStopAuth_C = 0;
const uint16  EngReqH_facCorCntTDC_T[ENGREQH_FACCORCNTTDC_T_COLS] = {0};
const uint16  EngReqH_facCorCntTDCX_A[ENGREQH_FACCORCNTTDCX_A_COLS] = {0};
const uint16  EngReqH_facDmgOxCX_A[ENGREQH_FACDMGOXCX_A_COLS] = {0};
const uint16  EngReqH_jEng_C = 0;
const uint16  EngReqH_nEngRstrtAutn_T[ENGREQH_NENGRSTRTAUTN_T_COLS] = {0};
const uint16  EngReqH_nOfsRstrtAutn_T[ENGREQH_NOFSRSTRTAUTN_T_COLS] = {0};
const uint16  EngReqH_nOfsRstrtAutnX_A[ENGREQH_NOFSRSTRTAUTNX_A_COLS] = {0};
const uint16  EngReqH_pAirExtUnfav_C = 0;
const uint16  EngReqH_pOilMaxAuthSTT_C = 0;
const uint16  EngReqH_tiDlyStopAuthLsOk_C = 0;
const uint16  EngReqH_tiDlyStrtSTTAuth_T[ENGREQH_TIDLYSTRTSTTAUTH_T_COLS] = {0};
const uint16  EngReqH_tiInhEngStopAFA_C = 0;
const uint16  EngReqH_tiInhEngStopAuthSTT_C = 0;
const uint16  EngReqH_tiInhEngStopCanPurg_C = 0;
const uint16  EngReqH_tiInhEngStopDft_C = 0;
const uint16  EngReqH_tiInhEngStopInjSys_C = 0;
const uint16  EngReqH_tiInhEngStopRstrtReq_C = 0;
const uint16  EngReqH_tiInhEngStopThdHi_C = 0;
const uint16  EngReqH_tiInhEngStopThdLo_C = 0;
const uint16  EngReqH_tiInhEngStopTqAdp_C = 0;
const uint16  EngReqH_tiPAirExtMem_C = 0;
const uint16  EngReqH_tOxCHiLimSTTRstrtReq_T[ENGREQH_TOXCHILIMSTTRSTRTREQ_T_COLS] = {0};
const uint16  EngReqH_tOxCMinHeatStopAuth_M[ENGREQH_TOXCMINHEATSTOPAUTH_M_LNS][ENGREQH_TOXCMINHEATSTOPAUTH_M_COLS] = {0};
const uint16  EngReqH_tOxCMinStopAuth_M[ENGREQH_TOXCMINSTOPAUTH_M_LNS][ENGREQH_TOXCMINSTOPAUTH_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean ENGREQH_bAndLogicalConditionPrev;
boolean EngReqH_bAuthStopSTTLsOk;
boolean EngReqH_bAuthStopSTTPOil;
boolean EngReqH_bAuthStopSTTStrtDly;
boolean EngReqH_bAuthStopSTTTAir;
boolean EngReqH_bAuthStopSTTTCo;
boolean EngReqH_bAuthStopSTTTCoMem_MP;
boolean EngReqH_bAuthStopSTTTOil;
boolean EngReqH_bAuthStopSTTTOxC;
boolean EngReqH_bAuthStopSTTTTrb;
boolean EngReqH_bCdnAuthStopSTT;
boolean EngReqH_bCdnTCoMax_MP;
boolean EngReqH_bCdnTCoMin_MP;
boolean EngReqH_bCdnTOilMax_MP;
boolean EngReqH_bCdnTOilMin_MP;
boolean EngReqH_bCntTDCRstrtAutnAvl;
boolean ENGREQH_bDeacCanPurgMPPrev;
boolean ENGREQH_bEnaCounterPrev;
boolean EngReqH_bEngRstrtAutnAvlTmp_MP;
boolean EngReqH_bFctAuthStopSTTTCo;
boolean EngReqH_bFctAuthStopSTTTOil;
boolean EngReqH_bFctAuthStopSTTTOxCHi;
boolean EngReqH_bFctAuthStopSTTTOxCLo;
boolean EngReqH_bFctStopAuthTAir;
boolean EngReqH_bFctStopTAirMem_MP;
boolean EngReqH_bForcCdnStopSTTTCo;
boolean EngReqH_bForcCdnStopSTTTOil;
boolean EngReqH_bForcCdnStopSTTTOxC;
boolean EngReqH_bForcStopAuthTAir;
boolean EngReqH_bGlblStopSTTLsOk_MP;
boolean EngReqH_bGlblStopSTTPOil_MP;
boolean EngReqH_bGlblStopSTTStrtDly_MP;
boolean EngReqH_bGlblStopSTTTAir_MP;
boolean EngReqH_bGlblStopSTTTCo_MP;
boolean EngReqH_bGlblStopSTTTOil_MP;
boolean EngReqH_bGlblStopSTTTOxC_MP;
boolean EngReqH_bGlblStopSTTTTrb_MP;
boolean ENGREQH_bHysteresisOutput;
boolean ENGREQH_bInhLrnAFAOut;
boolean ENGREQH_bLogicalAndInhLrnAFAPrev;
boolean ENGREQH_bLogicalORPrev;
boolean EngReqH_bNEngRstrtAutnAvl;
boolean ENGREQH_bOutRSLatchDmgTrb;
boolean ENGREQH_bOutRSLatchSTTStrtDly;
boolean ENGREQH_bOutRSLatchSTTStrtPrev;
boolean ENGREQH_bOutRSLatchSTTTOxCLo;
boolean ENGREQH_bOutRSLatchTrbProt;
boolean ENGREQH_bOutTurnOnDelay;
boolean ENGREQH_bpAirDeltaUnfav;
boolean ENGREQH_bpAirExtMemPrev;
boolean ENGREQH_bpAirExtMemPrev_2;
boolean ENGREQH_bpAirExtUnfav;
boolean EngReqH_bpOilAuthSTT;
boolean ENGREQH_bpOilAuthSTTPrev;
boolean ENGREQH_bRSTCounterPrev;
boolean ENGREQH_bRSTEngNOnIdlPev;
boolean EngReqH_bSTTRstrtReqCdnTFu;
boolean EngReqH_bSTTRstrtReqCdnTFu_MP;
boolean EngReqH_bSTTRstrtReqCdnThMgt;
boolean ENGREQH_bSwitchAuthTAirMem;
boolean ENGREQH_bSwitcherStopSTTTCo;
boolean ENGREQH_bSwitcherStopSTTTOil;
boolean EngReqH_bSyntNotSTTRstrtReq;
boolean EngReqH_bSyntSTTRstrtReq;
uint32 ENGREQH_u32FilTrbEstimMem;
uint32 ENGREQH_u32nEngFiltMem;
uint8 EngReqH_ctTDCPnd_MP;
uint8 ENGREQH_u8CoPTStEngPrev;
uint8 ENGREQH_u8pOilAuthSTTCount;
uint8 ENGREQH_u8STTRstrtReqCount;
sint16 ENGREQH_s16nEngRstrtAutn;
sint16 EngReqH_tAirVal;
uint16 EngReqH_ctTDCPndRaw_MP;
uint16 EngReqH_facCorCntTDC_MP;
uint16 EngReqH_nEngFil;
uint16 EngReqH_pAirExtMem_MP;
uint16 EngReqH_tiInhEngStop_MP;
uint16 EngReqH_tiInhEngStopAFA_MP;
uint16 EngReqH_tiInhEngStopAuthSTT_MP;
uint16 EngReqH_tiInhEngStopCanPurg_MP;
uint16 EngReqH_tiInhEngStopDft_MP;
uint16 EngReqH_tiInhEngStopInjSys_MP;
uint16 EngReqH_tiInhEngStopRStrtReq_MP;
uint16 EngReqH_tiInhEngStopTqAdp_MP;
uint16 EngReqH_tiPAirExtMem_MP;
uint16 EngReqH_tOxCMinHeatStopAuth_MP;
uint16 EngReqH_tOxCMinStopAuth_MP;
uint16 ENGREQH_u16AuthStopSTTLsOkCount;
uint16 ENGREQH_u16CounterTrbProt;
uint16 ENGREQH_u16DeacCanPurgMPCount;
uint16 ENGREQH_u16InhLrnAFACount;
uint16 ENGREQH_u16nEngFilter;
uint16 ENGREQH_u16StopSTTStrtDlyCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

