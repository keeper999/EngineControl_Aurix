/***************************************************************************
;**
;** FILE NAME      : FLOWMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FLOWMNG_H
#define FLOWMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ABSENT                            0
#define DAGMP_Key_Meca                    0
#define Driv_Train_closed                 1
#define DRIVALTMGT_BSS                    1
#define DRIVALTMGT_LIN                    0
#define DRIVALTMGT_NOSUBNET               2
#define EIPRODCF_ALTDRV                   1
#define EIPRODCF_ALTRV                    2
#define EIPRODCF_ALTSTD                   0
#define EXT_STPRGBSSCH_0                  0
#define EXT_STPRGBSSCH_1                  1
#define EXT_STPRGBSSCH_2                  2
#define EXT_STPRGBSSCH_3                  3
#define OTHER                             7
#define PRODPRGCH_06                      6
#define PRODPRGCH_07                      7
#define PRODPRGCH_10                      10
#define PRODPRGCH_14                      14
#define PRODPRGCHDI_NENG_04               4
#define PRODPRGCHDI_NENG_15               15

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

extern const boolean  Cf_rBattSoCSeln_C;
extern const boolean  FuPmp_bTypFuTnkPmp_C;
extern const uint32  TiCt_ctSecInDay_C;
extern const uint32  Tpsveh_seuil_bas_C;
extern const uint32  Tpsveh_seuil_haut_C;
extern const uint8  Ext_posnGBxLevDft_C;
extern const uint8  Ext_pRelBrkAsiInit_C;
extern const uint8  Ext_tPosATLevExtdInCoh_C;
extern const uint8  Ext_tPosATLevExtdInter_C;
extern const uint8  Ext_tPosATLevInCoh_C;
extern const uint8  Fgigb_ti_VsctlDiagIniGb_C;
extern const uint8  TiCt_ctTiUSec_C;
extern const sint16  Ext_tOilDft;
extern const sint16  TqCnvClu_tqRcvVal_C;
extern const uint16  ElProdMgt_uElProdSp_C;
extern const uint16  FuPmp_rLoAcvFuTnkPmp_C;
extern const uint16  TiCt_ctDayInYr_C;
extern const uint16  TqCnvClu_nEngNorm_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Bps_brake_pedal_can_hs;
extern boolean Bps_brake_pedal_can_input;
extern boolean Cps_clutch_pedal_input;
extern boolean Ext_bAcvLoFuPmp;
extern boolean Ext_bBrkPedPrssHs;
extern boolean Ext_bMainBrkPedPrssHsMes;
extern boolean Ext_bMainBrkPedPrssMes;
extern boolean Ext_bOilPres;
extern boolean Ext_bPresOilEng;
extern boolean Ext_bPresOilWarn;
extern boolean Ext_bPrgChBSSDi_nEng;
extern boolean Ext_bRawOilPres;
extern boolean Ext_bTAirChk;
extern boolean Oil_pres_alert;
extern uint32 AraMth_ctStaAcv;
extern uint32 Ext_ctSecEngStop;
extern uint32 Km_vehicle_mux;
extern uint32 TiCt_ctSecStopEng;
extern uint8 Ext_rSpdFanPred;
extern uint8 Ext_rSpdFanReqB2;
extern uint8 Ext_rSpdFanReqC;
extern uint8 Ext_stPrgBSSCh;
extern uint8 Ext_stPrgChLINDi_nEng;
extern uint8 Ext_stPrgLINCh;
extern uint8 Ext_stPwt;
extern uint8 Tra_posnATLevExtSecu;
extern sint16 Ext_tAirExtMesFineResl;
extern sint16 Ext_tAirMesFineResl;
extern sint16 Ext_tOil;
extern uint16 Bat_rBattSoC;
extern uint16 Ext_uAltBSSSp;
extern uint16 Ext_uAltLINSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Can_EveRst_FHCanF349_FlowMng(void);
void Can_EveRst_FHCanF552_FlowMng(void);
void Can_EveRxn349_FHCanF349_FlowMng(void);
void Can_EveRxn489_FHCanF489_FlowMng(void);
void Can_EveRxn552_FHCanF552_FlowMng(void);
void Can_EveRxn7F2_FHCanF7F2_FlowMng(void);
void Can_SdlSlow_FHCanF349_FlowMng(void);
void Cf_EvePwrl_FlowMng(void);
void Cf_EveRst_AirTFlowMng(void);
void Cf_EveRst_FlowMngAlt(void);
void Cf_EveRst_FlowMngBatt(void);
void Cf_EveRst_FlowMngBrk(void);
void Cf_EveRst_FlowMngBrkAsi(void);
void Cf_EveRst_FlowMngClu_1(void);
void Cf_EveRst_FlowMngClu_2(void);
void Cf_EveRst_FlowMngDayCt(void);
void Cf_EveRst_FlowMngGear(void);
void Cf_EveRst_FlowMngGmv(void);
void Cf_EveRst_FlowMngOilPres(void);
void Cf_EveRst_FlowMngPedPrss(void);
void Cf_EveRst_FlowMngPwt(void);
void Cf_EveRst_FlowMngTqSel(void);
void Cf_EveRst_FuPmp(void);
void Cf_EveRxn552_FlowMng(void);
void Cf_EveRxn552bis_FlowMng(void);
void Cf_EveTele_TunCfg_FlowMng(void);
void Cf_FuPmp_EveKOn_Mng(void);
void Cf_FuPmp_EveStTR_Mng(void);
void Cf_SdlFast_FlowMngAlt(void);
void Cf_SdlFast_FlowMngBatt(void);
void Cf_SdlFast_FlowMngBrk(void);
void Cf_SdlFast_FlowMngBrkAsi(void);
void Cf_SdlFast_FlowMngClu_1(void);
void Cf_SdlFast_FlowMngClu_2(void);
void Cf_SdlFast_FlowMngGear(void);
void Cf_SdlFast_FlowMngOilPres(void);
void Cf_SdlFast_FlowMngPedPrss(void);
void Cf_SdlFast_FlowMngPwt(void);
void Cf_SdlFast_FuPmp(void);
void Cf_SdlMid_FlowMngGmv(void);
void Cf_SdlMid_FlowMngTAir(void);
void Cf_SdlMid_FlowMngTOil(void);
void Cf_SdlSlow_FlowMng(void);
void FLOWMNG_vidEntryInit(void);


#endif /* FLOWMNG_H */

/*-------------------------------- end of file -------------------------------*/
