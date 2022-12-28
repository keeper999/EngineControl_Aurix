/***************************************************************************
;**
;** FILE NAME      : ENGREQH_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGREQH_L_H
#define ENGREQH_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  EngReqH_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ENGREQH_bAndLogicalConditionPrev;
extern boolean EngReqH_bAuthStopSTTLsOk;
extern boolean EngReqH_bAuthStopSTTPOil;
extern boolean EngReqH_bAuthStopSTTStrtDly;
extern boolean EngReqH_bAuthStopSTTTAir;
extern boolean EngReqH_bAuthStopSTTTCo;
extern boolean EngReqH_bAuthStopSTTTCoMem_MP;
extern boolean EngReqH_bAuthStopSTTTOil;
extern boolean EngReqH_bAuthStopSTTTOxC;
extern boolean EngReqH_bAuthStopSTTTTrb;
extern boolean EngReqH_bCdnAuthStopSTT;
extern boolean EngReqH_bCdnTCoMax_MP;
extern boolean EngReqH_bCdnTCoMin_MP;
extern boolean EngReqH_bCdnTOilMax_MP;
extern boolean EngReqH_bCdnTOilMin_MP;
extern boolean EngReqH_bCntTDCRstrtAutnAvl;
extern boolean ENGREQH_bDeacCanPurgMPPrev;
extern boolean ENGREQH_bEnaCounterPrev;
extern boolean EngReqH_bEngRstrtAutnAvlTmp_MP;
extern boolean EngReqH_bFctAuthStopSTTTCo;
extern boolean EngReqH_bFctAuthStopSTTTOil;
extern boolean EngReqH_bFctAuthStopSTTTOxCHi;
extern boolean EngReqH_bFctAuthStopSTTTOxCLo;
extern boolean EngReqH_bFctStopAuthTAir;
extern boolean EngReqH_bFctStopTAirMem_MP;
extern boolean EngReqH_bForcCdnStopSTTTCo;
extern boolean EngReqH_bForcCdnStopSTTTOil;
extern boolean EngReqH_bForcCdnStopSTTTOxC;
extern boolean EngReqH_bForcStopAuthTAir;
extern boolean EngReqH_bGlblStopSTTLsOk_MP;
extern boolean EngReqH_bGlblStopSTTPOil_MP;
extern boolean EngReqH_bGlblStopSTTStrtDly_MP;
extern boolean EngReqH_bGlblStopSTTTAir_MP;
extern boolean EngReqH_bGlblStopSTTTCo_MP;
extern boolean EngReqH_bGlblStopSTTTOil_MP;
extern boolean EngReqH_bGlblStopSTTTOxC_MP;
extern boolean EngReqH_bGlblStopSTTTTrb_MP;
extern boolean ENGREQH_bHysteresisOutput;
extern boolean ENGREQH_bInhLrnAFAOut;
extern boolean ENGREQH_bLogicalAndInhLrnAFAPrev;
extern boolean ENGREQH_bLogicalORPrev;
extern boolean EngReqH_bNEngRstrtAutnAvl;
extern boolean ENGREQH_bOutRSLatchDmgTrb;
extern boolean ENGREQH_bOutRSLatchSTTStrtDly;
extern boolean ENGREQH_bOutRSLatchSTTStrtPrev;
extern boolean ENGREQH_bOutRSLatchSTTTOxCLo;
extern boolean ENGREQH_bOutRSLatchTrbProt;
extern boolean ENGREQH_bOutTurnOnDelay;
extern boolean ENGREQH_bpAirDeltaUnfav;
extern boolean ENGREQH_bpAirExtMemPrev;
extern boolean ENGREQH_bpAirExtMemPrev_2;
extern boolean ENGREQH_bpAirExtUnfav;
extern boolean EngReqH_bpOilAuthSTT;
extern boolean ENGREQH_bpOilAuthSTTPrev;
extern boolean ENGREQH_bRSTCounterPrev;
extern boolean ENGREQH_bRSTEngNOnIdlPev;
extern boolean EngReqH_bSTTRstrtReqCdnTFu;
extern boolean EngReqH_bSTTRstrtReqCdnTFu_MP;
extern boolean EngReqH_bSTTRstrtReqCdnThMgt;
extern boolean ENGREQH_bSwitchAuthTAirMem;
extern boolean ENGREQH_bSwitcherStopSTTTCo;
extern boolean ENGREQH_bSwitcherStopSTTTOil;
extern boolean EngReqH_bSyntNotSTTRstrtReq;
extern boolean EngReqH_bSyntSTTRstrtReq;
extern uint32 ENGREQH_u32FilTrbEstimMem;
extern uint32 ENGREQH_u32nEngFiltMem;
extern uint8 EngReqH_ctTDCPnd_MP;
extern uint8 ENGREQH_u8CoPTStEngPrev;
extern uint8 ENGREQH_u8pOilAuthSTTCount;
extern uint8 ENGREQH_u8STTRstrtReqCount;
extern sint16 ENGREQH_s16nEngRstrtAutn;
extern sint16 EngReqH_tAirVal;
extern uint16 EngReqH_ctTDCPndRaw_MP;
extern uint16 EngReqH_facCorCntTDC_MP;
extern uint16 EngReqH_nEngFil;
extern uint16 EngReqH_pAirExtMem_MP;
extern uint16 EngReqH_tiInhEngStop_MP;
extern uint16 EngReqH_tiInhEngStopAFA_MP;
extern uint16 EngReqH_tiInhEngStopAuthSTT_MP;
extern uint16 EngReqH_tiInhEngStopCanPurg_MP;
extern uint16 EngReqH_tiInhEngStopDft_MP;
extern uint16 EngReqH_tiInhEngStopInjSys_MP;
extern uint16 EngReqH_tiInhEngStopRStrtReq_MP;
extern uint16 EngReqH_tiInhEngStopTqAdp_MP;
extern uint16 EngReqH_tiPAirExtMem_MP;
extern uint16 EngReqH_tOxCMinHeatStopAuth_MP;
extern uint16 EngReqH_tOxCMinStopAuth_MP;
extern uint16 ENGREQH_u16AuthStopSTTLsOkCount;
extern uint16 ENGREQH_u16CounterTrbProt;
extern uint16 ENGREQH_u16DeacCanPurgMPCount;
extern uint16 ENGREQH_u16InhLrnAFACount;
extern uint16 ENGREQH_u16nEngFilter;
extern uint16 ENGREQH_u16StopSTTStrtDlyCount;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGREQH_vidAutorisMoteurSTOP(void);
void ENGREQH_vidChoixTemperatureAir(void);
void ENGREQH_vidConditionRegimeMoteur(void);
void ENGREQH_vidCondNombrePMHRestant(void);
void ENGREQH_vidCondPresHuileAutoStop(void);
void ENGREQH_vidCondRedemaAutonomeSTT(void);
void ENGREQH_vidCondRedemarrAutonome(void);
void ENGREQH_vidCondSeuilBasTempCatal(void);
void ENGREQH_vidCondSeuilHautTempCata(void);
void ENGREQH_vidCondSondLambdaAutStop(void);
void ENGREQH_vidCondTempCatalyAutStop(void);
void ENGREQH_vidCondTempEauAutoriStop(void);
void ENGREQH_vidCondTemperAirAutoStop(void);
void ENGREQH_vidCondTempHuileAutoStop(void);
void ENGREQH_vidConTempCarTurbAutStop(void);
void ENGREQH_vidCriticPresAtmospheriq(void);
void ENGREQH_vidDemandeRedemarrage(void);
void ENGREQH_vidFiltreRegimeMoteur(void);
void ENGREQH_vidInitOutput(void);
void ENGREQH_vidObserTempsMinimumStop(void);
void ENGREQH_vidPartieDisfoncTempAir(void);
void ENGREQH_vidPartieDisfoncTempCata(void);
void ENGREQH_vidPartieDisfoncTempEau(void);
void ENGREQH_vidPartieDisfonTempHuile(void);
void ENGREQH_vidPartieFonctionTempAir(void);
void ENGREQH_vidPartieFonctionTempEau(void);
void ENGREQH_vidPartieFonctTempHuile(void);
void ENGREQH_vidRedemBesoinThermCapot(void);
void ENGREQH_vidRedemSeuilTempEssence(void);
void ENGREQH_vidSelectActivFonctions(void);
void ENGREQH_vidTempoDemarrageAutStop(void);


#endif /* ENGREQH_L_H */

/*-------------------------------- end of file -------------------------------*/
