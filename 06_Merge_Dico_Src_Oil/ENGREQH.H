/***************************************************************************
;**
;** FILE NAME      : ENGREQH.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGREQH_H
#define ENGREQH_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGREQH_FACCORCNTTDC_T_COLS            ( 8 )
#define ENGREQH_FACCORCNTTDCX_A_COLS           ( 8 )
#define ENGREQH_FACDMGOXCX_A_COLS              ( 4 )
#define ENGREQH_NENGRSTRTAUTN_T_COLS           ( 12 )
#define ENGREQH_NENGRSTRTAUTNX_A_COLS          ( 12 )
#define ENGREQH_NOFSRSTRTAUTN_T_COLS           ( 8 )
#define ENGREQH_NOFSRSTRTAUTNX_A_COLS          ( 8 )
#define ENGREQH_TCOMESSTRTY_A_COLS             ( 6 )
#define ENGREQH_TCOMINSTOPAUTH_T_COLS          ( 12 )
#define ENGREQH_TCOSTOPAUTHX_A_COLS            ( 12 )
#define ENGREQH_TIDLYSTRTSTTAUTH_T_COLS        ( 12 )
#define ENGREQH_TIPOILSTOPAUTH_T_COLS          ( 8 )
#define ENGREQH_TIPOILSTOPAUTHX_A_COLS         ( 8 )
#define ENGREQH_TOXCHILIMSTTRSTRTREQ_T_COLS    ( 4 )
#define ENGREQH_TOXCMINHEATSTOPAUTH_M_LNS     ( 4 )
#define ENGREQH_TOXCMINHEATSTOPAUTH_M_COLS     ( 6 )
#define ENGREQH_TOXCMINSTOPAUTH_M_LNS         ( 4 )
#define ENGREQH_TOXCMINSTOPAUTH_M_COLS         ( 6 )

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

extern const boolean  EngReqH_bAcvStopAuthLsOk_C;
extern const boolean  EngReqH_bAcvStopAuthPOil_C;
extern const boolean  EngReqH_bAcvStopAuthStrtDly_C;
extern const boolean  EngReqH_bAcvStopAuthTAir_C;
extern const boolean  EngReqH_bAcvStopAuthTCo_C;
extern const boolean  EngReqH_bAcvStopAuthTOil_C;
extern const boolean  EngReqH_bAcvStopAuthTOxC_C;
extern const boolean  EngReqH_bAcvStopAuthTTrb_C;
extern const boolean  EngReqH_bCfNEngRstrtAutn_C;
extern const boolean  EngReqH_bCfTEngRstrtAutn_C;
extern const boolean  EngReqH_bDeacCdnRstrtThMgt_C;
extern const boolean  EngReqH_bDeacCdnSTTRstrtTFu_C;
extern const boolean  EngReqH_bDeacCdnSTTTOxCMin_C;
extern const boolean  EngReqH_bDeacDsLs_C;
extern const boolean  EngReqH_bDeacInhEngStopAFA_C;
extern const boolean  EngReqH_bDeacInhEngStopCanPurg_C;
extern const boolean  EngReqH_bDeacInhEngStopInjSys_C;
extern const boolean  EngReqH_bDeacInhEngStopTqAdp_C;
extern const boolean  EngReqH_bDeacRstrtTOxCMax_C;
extern const boolean  EngReqH_bDeacUsLs_C;
extern const boolean  EngReqH_bTestDeacCdnLsOk_C;
extern const boolean  EngReqH_bTestDeacCdnPOil_C;
extern const boolean  EngReqH_bTestDeacCdnStrtDly_C;
extern const boolean  EngReqH_bTestDeacCdnTAir_C;
extern const boolean  EngReqH_bTestDeacCdnTCo_C;
extern const boolean  EngReqH_bTestDeacCdnTOil_C;
extern const boolean  EngReqH_bTestDeacCdnTOxC_C;
extern const boolean  EngReqH_bTestDeacCdnTTrb_C;
extern const uint32  EngReqH_tiDlyTOxC_C;
extern const uint8  EngReqH_ctTDCRstrtAutnAvl_C;
extern const uint8  EngReqH_facFilNEng_C;
extern const uint8  EngReqH_nEngRstrtAutnX_A[ENGREQH_NENGRSTRTAUTNX_A_COLS];
extern const uint8  EngReqH_noCyl_C;
extern const uint8  EngReqH_pAirDeltaHysUnfav_C;
extern const uint8  EngReqH_pAirExtHysUnfav_C;
extern const uint8  EngReqH_pOilHysMaxAuthSTT_C;
extern const uint8  EngReqH_stForcTAirSel_C;
extern const uint8  EngReqH_stTAirSel_C;
extern const uint8  EngReqH_stTAirTCoDft_C;
extern const uint8  EngReqH_stTCoDftVal_C;
extern const uint8  EngReqH_stTOilDftVal_C;
extern const uint8  EngReqH_tCoMesStrtY_A[ENGREQH_TCOMESSTRTY_A_COLS];
extern const uint8  EngReqH_tCoMinStopAuth_T[ENGREQH_TCOMINSTOPAUTH_T_COLS];
extern const uint8  EngReqH_tCoStopAuthX_A[ENGREQH_TCOSTOPAUTHX_A_COLS];
extern const uint8  EngReqH_tiDlyAutSTTRstrt_C;
extern const uint8  EngReqH_tiPOilStopAuth_T[ENGREQH_TIPOILSTOPAUTH_T_COLS];
extern const uint8  EngReqH_tiPOilStopAuthX_A[ENGREQH_TIPOILSTOPAUTHX_A_COLS];
extern const uint8  EngReqH_tTrbHysMaxStopAuth_C;
extern const sint16  EngReqH_facTAirStopAuth_C;
extern const sint16  EngReqH_pAirDeltaUnfav_C;
extern const sint16  EngReqH_tAirMinStopAuth_C;
extern const sint16  EngReqH_tAirVal_C;
extern const sint16  EngReqH_tCoHysMaxStopAuth_C;
extern const sint16  EngReqH_tCoHysMinStopAuth_C;
extern const sint16  EngReqH_tCoMaxStopAuth_C;
extern const sint16  EngReqH_tCoMin_tAirStopAuth_C;
extern const sint16  EngReqH_tCoOfsStopAuth_C;
extern const sint16  EngReqH_tFuHiLimSTTRstrtReq_C;
extern const sint16  EngReqH_tFuHysLimSTTRstrtReq_C;
extern const sint16  EngReqH_tOilHysMaxStopAuth_C;
extern const sint16  EngReqH_tOilHysMinStopAuth_C;
extern const sint16  EngReqH_tOilMaxStopAuth_C;
extern const sint16  EngReqH_tOilMinStopAuth_C;
extern const sint16  EngReqH_tOxCHysLimRstrtReq_C;
extern const sint16  EngReqH_tTrbMaxStopAuth_C;
extern const uint16  EngReqH_facCorCntTDC_T[ENGREQH_FACCORCNTTDC_T_COLS];
extern const uint16  EngReqH_facCorCntTDCX_A[ENGREQH_FACCORCNTTDCX_A_COLS];
extern const uint16  EngReqH_facDmgOxCX_A[ENGREQH_FACDMGOXCX_A_COLS];
extern const uint16  EngReqH_jEng_C;
extern const uint16  EngReqH_nEngRstrtAutn_T[ENGREQH_NENGRSTRTAUTN_T_COLS];
extern const uint16  EngReqH_nOfsRstrtAutn_T[ENGREQH_NOFSRSTRTAUTN_T_COLS];
extern const uint16  EngReqH_nOfsRstrtAutnX_A[ENGREQH_NOFSRSTRTAUTNX_A_COLS];
extern const uint16  EngReqH_pAirExtUnfav_C;
extern const uint16  EngReqH_pOilMaxAuthSTT_C;
extern const uint16  EngReqH_tiDlyStopAuthLsOk_C;
extern const uint16  EngReqH_tiDlyStrtSTTAuth_T[ENGREQH_TIDLYSTRTSTTAUTH_T_COLS];
extern const uint16  EngReqH_tiInhEngStopAFA_C;
extern const uint16  EngReqH_tiInhEngStopAuthSTT_C;
extern const uint16  EngReqH_tiInhEngStopCanPurg_C;
extern const uint16  EngReqH_tiInhEngStopDft_C;
extern const uint16  EngReqH_tiInhEngStopInjSys_C;
extern const uint16  EngReqH_tiInhEngStopRstrtReq_C;
extern const uint16  EngReqH_tiInhEngStopThdHi_C;
extern const uint16  EngReqH_tiInhEngStopThdLo_C;
extern const uint16  EngReqH_tiInhEngStopTqAdp_C;
extern const uint16  EngReqH_tiPAirExtMem_C;
extern const uint16  EngReqH_tOxCHiLimSTTRstrtReq_T[ENGREQH_TOXCHILIMSTTRSTRTREQ_T_COLS];
extern const uint16  EngReqH_tOxCMinHeatStopAuth_M[ENGREQH_TOXCMINHEATSTOPAUTH_M_LNS][ENGREQH_TOXCMINHEATSTOPAUTH_M_COLS];
extern const uint16  EngReqH_tOxCMinStopAuth_M[ENGREQH_TOXCMINSTOPAUTH_M_LNS][ENGREQH_TOXCMINSTOPAUTH_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EngReqH_SdlFast_EngReqH(void);
void EngReqH_SdlMid_EngReqH(void);
void ENGREQH_vidEntryInit(void);


#endif /* ENGREQH_H */

/*-------------------------------- end of file -------------------------------*/
