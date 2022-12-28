/***************************************************************************
;**
;** FILE NAME      : CTRLCFG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CTRLCFG_H
#define CTRLCFG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ABSOLU                            1
#define RELATIF                           2

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

extern const boolean  CoT_bAcv_TrbCoWaPmp_C;
extern const boolean  Ctrl_bAcv_EngMes_C;
extern const boolean  Ctrl_bAcv_pAirExtMes_C;
extern const boolean  Ctrl_bAcv_pDsThr_C;
extern const boolean  Ctrl_bAvc_BlowBy1_C;
extern const boolean  Ctrl_bAvc_BlowBy2_C;
extern const boolean  Ctrl_bfAcvConstEm2_C;
extern const boolean  Ctrl_bfSlavePtlWkuSt_C;
extern const boolean  Ctrl_bFuTnkEmp_C;
extern const boolean  Ctrl_BSI_412_C;
extern const boolean  Ctrl_BSI_432_C;
extern const boolean  Ctrl_BSI_4F2_C;
extern const boolean  Ctrl_BSI_592_C;
extern const boolean  Ctrl_BSI_612_C;
extern const boolean  Ctrl_BSI_CMM_0A8_C;
extern const boolean  Ctrl_bTAirExtMes_C;
extern const boolean  Ctrl_bTreatAdHeatRly_C;
extern const boolean  Ctrl_bVehCollWarn_C;
extern const boolean  Ctrl_CLIM_50E_C;
extern const boolean  Ctrl_CMM_108_C;
extern const boolean  Ctrl_CMM_208_C;
extern const boolean  Ctrl_CMM_228_C;
extern const boolean  Ctrl_CMM_348_C;
extern const boolean  Ctrl_CMM_468_C;
extern const boolean  Ctrl_CMM_488_C;
extern const boolean  Ctrl_CMM_588_C;
extern const boolean  Ctrl_CMM_608_C;
extern const boolean  Ctrl_CMM_788_C;
extern const boolean  Ctrl_CRASH_4C8_C;
extern const boolean  Ctrl_ctClcProc228_C;
extern const boolean  Ctrl_DIAG_ON_CAN_688_C;
extern const boolean  Ctrl_DIAG_ON_CAN_6A8_C;
extern const boolean  Ctrl_DMTR_57C_C;
extern const boolean  Ctrl_EAC_CMM_BSI_072_C;
extern const boolean  Ctrl_EAC_CMM_UCC_0E8_C;
extern const boolean  Ctrl_ELECTRON_BSI_092_C;
extern const boolean  Ctrl_EOBD_ON_CAN_7DF_C;
extern const boolean  Ctrl_EOBD_ON_CAN_7E0_C;
extern const boolean  Ctrl_EOBD_ON_CAN_7E8_C;
extern const boolean  Ctrl_EOBD_ON_CAN_7ED_C;
extern const boolean  Ctrl_iBattMes_C;
extern const boolean  Ctrl_IS_VIN_VDS_BSI_492_C;
extern const boolean  Ctrl_IS_VIN_VIS_BSI_4B2_C;
extern const boolean  Ctrl_IS_VIN_WMI_BSI_4D2_C;
extern const boolean  Ctrl_noCks228_C;
extern const boolean  Ctrl_noSupvDTC_C;
extern const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CC_C;
extern const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CD_C;
extern const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CE_C;
extern const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CF_C;
extern const boolean  Ctrl_rAccP_C;
extern const boolean  Ctrl_resBattIt_C;
extern const boolean  Ctrl_RQD_CMM_BSI_072_C;
extern const boolean  Ctrl_RQD_CMM_UCC_0E8_C;
extern const boolean  Ctrl_SecBrkPedPrss_C;
extern const boolean  Ctrl_spdVeh_C;
extern const boolean  Ctrl_stBrkIp_C;
extern const boolean  Ctrl_stECUMiss_C;
extern const boolean  Ctrl_stJDD2Answ_C;
extern const boolean  Ctrl_stJDDAnsw_C;
extern const boolean  Ctrl_stPwt_C;
extern const boolean  Ctrl_StRlyR3_C;
extern const boolean  Ctrl_stSt_C;
extern const boolean  Ctrl_tCoMes_C;
extern const boolean  Ctrl_tqDrvFil_C;
extern const boolean  Ctrl_uBattOc_C;
extern const boolean  Ctrl_uBattStrt_C;
extern const boolean  Ctrl_UCC_CMM_0E0_C;
extern const boolean  Ctrl_UDS_ON_CAN_7FF_C;
extern const boolean  Ext_bAcv_AccPSftyLvl2_C;
extern const boolean  Ext_bAcv_BrkAsiSftyLvl2_C;
extern const boolean  Ext_bAcv_BrkSftyLvl2_C;
extern const boolean  Ext_bAcv_CluSftyLvl2_C;
extern const boolean  Ext_bAcv_FHCANF329Lvl2_C;
extern const boolean  Ext_bAcv_FHCANF349Lvl2_C;
extern const boolean  Ext_bAcv_FHCANF34DLvl2_C;
extern const boolean  Ext_bAcv_FHCANF38DLvl2_C;
extern const boolean  Ext_bAcv_FHCANF3C9Lvl2_C;
extern const boolean  Ext_bAcv_NeutPosnAcqSftyLvl2_C;
extern const boolean  Ext_bAcv_RelBrkAsiSftyLvl2_C;
extern const boolean  Ext_bAcv_ThrSftyLvl2_C;
extern const boolean  Ext_bAcv_VehSpdSftyLvl2_C;
extern const boolean  Far_bSelFarSpMdlCf_C;
extern const boolean  Fu_bAcv_FuTnkPmp_C;
extern const boolean  Fu_bAcv_HpPmp_C;
extern const boolean  HPPmpAct_bAcv_PFuAcq_C;
extern const boolean  Oil_bAcv_uEngOilLvl_C;
extern const boolean  OilSysHw_bOilPmpCmd_C;
extern const boolean  Spg_bAcv_pUsThr_C;
extern const boolean  VlvAct_bAcvVlvActExStr_C;
extern const boolean  VlvAct_bAcvVlvActInStr_C;
extern const boolean  Wg_bTrbAct_rCtl_C;
extern const uint8  Ext_stBrkAsiTypCf_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Cf_bKeyLine;
extern boolean Cf_bPushLine;
extern boolean Ctrl_ABR_38D;
extern boolean Ctrl_ABR_44D;
extern boolean Ctrl_ABR_50D;
extern boolean Ctrl_Acq_bNeut;
extern boolean Ctrl_bACClu;
extern boolean Ctrl_bAcv_bModSptReq;
extern boolean Ctrl_bAcv_ctStaAcv;
extern boolean Ctrl_bAcv_pwrEngSndModSpt;
extern boolean Ctrl_bAcv_rBoostPresSndModSpt;
extern boolean Ctrl_bAcv_rPwrEngSndModSpt;
extern boolean Ctrl_bAcv_rTqEfcSndModSpt;
extern boolean Ctrl_bAcv_stModSpt;
extern boolean Ctrl_bAcv_stVehCf;
extern boolean Ctrl_bAcv_tqEfcSndModSpt;
extern boolean Ctrl_bAcvSta;
extern boolean Ctrl_bAcvStaReq;
extern boolean Ctrl_bChaTqAvl;
extern boolean Ctrl_bChaTqCrt;
extern boolean Ctrl_bCluPedPrss;
extern boolean Ctrl_bCluPedPrssSen;
extern boolean Ctrl_bCmExAcq;
extern boolean Ctrl_bCmInAcq;
extern boolean Ctrl_bDgoBody;
extern boolean Ctrl_bDrvAvl;
extern boolean Ctrl_bDynFctAcvCplm;
extern boolean Ctrl_bDynFctAcvSec;
extern boolean Ctrl_bEngCutReq;
extern boolean Ctrl_bEngRStrtReqSTT;
extern boolean Ctrl_bEngStrtReq;
extern boolean Ctrl_bEngStrtReq2;
extern boolean Ctrl_bfAcvConstEm2;
extern boolean Ctrl_bfSlavePtlWkuSt;
extern boolean Ctrl_bFuTnkEmp;
extern boolean Ctrl_bHeatReq;
extern boolean Ctrl_bHillAsiRdyEngStop;
extern boolean Ctrl_bInfoAcvCluPed;
extern boolean Ctrl_bInfoRdy;
extern boolean Ctrl_bInhAcqESPFrnt;
extern boolean Ctrl_bLiMILReqGUS;
extern boolean Ctrl_BlowBy1Hw;
extern boolean Ctrl_bMainBrkPedPrss;
extern boolean Ctrl_bMainBrkPedPrssHSCha;
extern boolean Ctrl_bMainBrkPedPrssHSVeh;
extern boolean Ctrl_bMainBrkPedPrssMes;
extern boolean Ctrl_bNeut;
extern boolean Ctrl_bOpFSFReq;
extern boolean Ctrl_bPosnFSF;
extern boolean Ctrl_bPush;
extern boolean Ctrl_bRecNotStop;
extern boolean Ctrl_bRStrtAnt;
extern boolean Ctrl_bRvs;
extern boolean Ctrl_bSelFarSpMdlCf;
extern boolean Ctrl_BSI_412;
extern boolean Ctrl_BSI_432;
extern boolean Ctrl_BSI_4F2;
extern boolean Ctrl_BSI_552;
extern boolean Ctrl_BSI_572;
extern boolean Ctrl_BSI_592;
extern boolean Ctrl_BSI_612;
extern boolean Ctrl_BSI_792;
extern boolean Ctrl_BSI_CMM_0A8;
extern boolean Ctrl_bStopIp;
extern boolean Ctrl_bStrtLockAcq;
extern boolean Ctrl_bTAirExtMes;
extern boolean Ctrl_bTraTqAuthRaw;
extern boolean Ctrl_bTypStrt;
extern boolean Ctrl_bUncrt_tqCkEngReal;
extern boolean Ctrl_bUncrt_tqEM;
extern boolean Ctrl_bVehCollWarn;
extern boolean Ctrl_bVSCtlDft;
extern boolean Ctrl_bVSLimReq;
extern boolean Ctrl_bVSRegDVSRegReq;
extern boolean Ctrl_bVSSNwAcvSt;
extern boolean Ctrl_bVVTVlvEx;
extern boolean Ctrl_bVVTVlvIn;
extern boolean Ctrl_bWaitStrtReq;
extern boolean Ctrl_bWkuMainSev;
extern boolean Ctrl_bWupAcv;
extern boolean Ctrl_CDS_34D;
extern boolean Ctrl_CLIM_50E;
extern boolean Ctrl_CMM_108;
extern boolean Ctrl_CMM_1E8;
extern boolean Ctrl_CMM_208;
extern boolean Ctrl_CMM_228;
extern boolean Ctrl_CMM_348;
extern boolean Ctrl_CMM_388;
extern boolean Ctrl_CMM_3B8;
extern boolean Ctrl_CMM_438;
extern boolean Ctrl_CMM_468;
extern boolean Ctrl_CMM_488;
extern boolean Ctrl_CMM_588;
extern boolean Ctrl_CMM_5F8;
extern boolean Ctrl_CMM_608;
extern boolean Ctrl_CMM_788;
extern boolean Ctrl_CMM_BV_2E8;
extern boolean Ctrl_CMMPropSnsrOnly_PTT;
extern boolean Ctrl_CONTEXTE_1_5B2;
extern boolean Ctrl_CONTEXTE_1_7F2;
extern boolean Ctrl_CRASH_4C8;
extern boolean Ctrl_ctBSIFrame;
extern boolean Ctrl_ctClcProc228;
extern boolean Ctrl_ctClcProc50D;
extern boolean Ctrl_DAT_BSI_532;
extern boolean Ctrl_DIAG_ON_CAN_688;
extern boolean Ctrl_DIAG_ON_CAN_6A8;
extern boolean Ctrl_DIRA_495;
extern boolean Ctrl_DMTR_57C;
extern boolean Ctrl_EAC_CMM_BSI_072;
extern boolean Ctrl_EAC_CMM_UCC_0E8;
extern boolean Ctrl_EASY_MOVE_3AD;
extern boolean Ctrl_ELECTRON_BSI_092;
extern boolean Ctrl_EOBD_ON_CAN_7DF;
extern boolean Ctrl_EOBD_ON_CAN_7E0;
extern boolean Ctrl_EOBD_ON_CAN_7E8;
extern boolean Ctrl_EOBD_ON_CAN_7ED;
extern boolean Ctrl_ESPPropSnsr_CMMPropSnsr;
extern boolean Ctrl_ESPPropSnsr_CMMSwt;
extern boolean Ctrl_facSen_uEmPredRstrt;
extern boolean Ctrl_FRE_30D;
extern boolean Ctrl_FRE_3CD;
extern boolean Ctrl_iBattMes;
extern boolean Ctrl_idxPtSptBVA;
extern boolean Ctrl_idxPtSptBVMP;
extern boolean Ctrl_JDD_CAN_BSI_772;
extern boolean Ctrl_JDD_CAN_CMM_768;
extern boolean Ctrl_NEW_JDD_55F;
extern boolean Ctrl_NEW_JDD_CMM_768;
extern boolean Ctrl_noCalCurBattMes;
extern boolean Ctrl_noCks228;
extern boolean Ctrl_noCks50D;
extern boolean Ctrl_noCks50E;
extern boolean Ctrl_noEngStrt;
extern boolean Ctrl_noIncCurBattMes;
extern boolean Ctrl_noJDD;
extern boolean Ctrl_noSupvDTC;
extern boolean Ctrl_nTrb;
extern boolean Ctrl_OUTIL_PRTCLE_CCP_7CC;
extern boolean Ctrl_OUTIL_PRTCLE_CCP_7CD;
extern boolean Ctrl_OUTIL_PRTCLE_CCP_7CE;
extern boolean Ctrl_OUTIL_PRTCLE_CCP_7CF;
extern boolean Ctrl_pAC;
extern boolean Ctrl_pBoostSndModSpt;
extern boolean Ctrl_pBrkMCT;
extern boolean Ctrl_posnAMTLev;
extern boolean Ctrl_pwrAC;
extern boolean Ctrl_rAccP;
extern boolean Ctrl_rBattSoC;
extern boolean Ctrl_rCluP;
extern boolean Ctrl_rCluPCAN;
extern boolean Ctrl_rCluPedPrssMes;
extern boolean Ctrl_rCnvTq;
extern boolean Ctrl_resBattIt;
extern boolean Ctrl_RQD_CMM_BSI_072;
extern boolean Ctrl_RQD_CMM_UCC_0E8;
extern boolean Ctrl_rSlopStab;
extern boolean Ctrl_SecBrkPedPrss;
extern boolean Ctrl_spdVeh;
extern boolean Ctrl_spdVehVSCtlReq;
extern boolean Ctrl_stAcvWarn;
extern boolean Ctrl_stAdHeat;
extern boolean Ctrl_stBattSoC;
extern boolean Ctrl_stBrkIp;
extern boolean Ctrl_stDiagESPReq;
extern boolean Ctrl_stDrvAvl;
extern boolean Ctrl_stECUMiss;
extern boolean Ctrl_stElEProv;
extern boolean Ctrl_stEngRStrtInh;
extern boolean Ctrl_stEngRStrtReq;
extern boolean Ctrl_stEngStopAuth;
extern boolean Ctrl_stGearShiftReq;
extern boolean Ctrl_stGSIEna;
extern boolean Ctrl_stHillAsi;
extern boolean Ctrl_stJDD2Answ;
extern boolean Ctrl_stJDDAnsw;
extern boolean Ctrl_stNetwEl;
extern boolean Ctrl_stPosATLevPNCAN;
extern boolean Ctrl_stPosn;
extern boolean Ctrl_stPosnFSFReq;
extern boolean Ctrl_stPrioVoltMax;
extern boolean Ctrl_stPrioVoltMin;
extern boolean Ctrl_stPwt;
extern boolean Ctrl_stReq;
extern boolean Ctrl_stReqBlsVoltCtl;
extern boolean Ctrl_StRlyR3;
extern boolean Ctrl_stSt;
extern boolean Ctrl_stStaAuth;
extern boolean Ctrl_stSTTLightAcv;
extern boolean Ctrl_STT_BV_329;
extern boolean Ctrl_STT_CMM_3C8;
extern boolean Ctrl_stTypEmPredRstrt;
extern boolean Ctrl_stVSCtl;
extern boolean Ctrl_stVSCtlReq;
extern boolean Ctrl_tCoMes;
extern boolean Ctrl_tqCnsATRStrt;
extern boolean Ctrl_tqCnvExtd;
extern boolean Ctrl_tqDrvFil;
extern boolean Ctrl_tqEM;
extern boolean Ctrl_tqLoss;
extern boolean Ctrl_uBattClc;
extern boolean Ctrl_uBattOc;
extern boolean Ctrl_uBattStrt;
extern boolean Ctrl_UCC_CMM_0E0;
extern boolean Ctrl_UDS_ON_CAN_7FF;
extern boolean Ctrl_uEmPredRstrt;
extern boolean Ctrl_uReqProdMax;
extern boolean Ctrl_uReqProdMin;
extern boolean Ctrl_uReqProdSlope;
extern boolean Ctrl_V2_BSI_552;
extern boolean Ctrl_V2_BV_3C9;
extern boolean Ctrl_V2_BV_489;
extern boolean Ctrl_V2_BVA_349;
extern boolean Ctrl_V2_BVMP_349;
extern boolean Ctrl_VDS_BSI_492;
extern boolean Ctrl_VIS_BSI_4B2;
extern boolean Ctrl_VOL_305;
extern boolean Ctrl_VSSNwMgt_bVSSNwAcvAuth;
extern boolean Ctrl_WMI_BSI_4D2;
extern boolean Ext_bAcv_AccPSftyLvl2;
extern boolean Ext_bAcv_BrkAsiSftyLvl2;
extern boolean Ext_bAcv_BrkSftyLvl2;
extern boolean Ext_bAcv_CluSftyLvl2;
extern boolean Ext_bAcv_FHCANF329Lvl2;
extern boolean Ext_bAcv_FHCANF349Lvl2;
extern boolean Ext_bAcv_FHCANF34DLvl2;
extern boolean Ext_bAcv_FHCANF38DLvl2;
extern boolean Ext_bAcv_FHCANF3C9Lvl2;
extern boolean Ext_bAcv_NeutPosnAcqSftyLvl2;
extern boolean Ext_bAcv_RelBrkAsiSftyLvl2;
extern boolean Ext_bAcv_ThrSftyLvl2;
extern boolean Ext_bAcv_VehSpdSftyLvl2;
extern boolean Ext_bEngRun_Archi2010EcoPush;
extern uint8 Ext_stBrkAsiTypCf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Cf_EveRst_CtrlCfg(void);
void Cf_SdlFast_CtrlCfg(void);


#endif /* CTRLCFG_H */

/*-------------------------------- end of file -------------------------------*/
