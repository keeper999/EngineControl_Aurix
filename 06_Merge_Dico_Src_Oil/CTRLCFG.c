/***************************************************************************
;**
;** FILE NAME      : CTRLCFG.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CTRLCFG.H"
#include "CTRLCFG_L.H"
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
const boolean  CoT_bAcv_TrbCoWaPmp_C = 0;
const boolean  Ctrl_bAcv_EngMes_C = 0;
const boolean  Ctrl_bAcv_pAirExtMes_C = 0;
const boolean  Ctrl_bAcv_pDsThr_C = 0;
const boolean  Ctrl_bAvc_BlowBy1_C = 0;
const boolean  Ctrl_bAvc_BlowBy2_C = 0;
const boolean  Ctrl_bfAcvConstEm2_C = 0;
const boolean  Ctrl_bfSlavePtlWkuSt_C = 0;
const boolean  Ctrl_bFuTnkEmp_C = 0;
const boolean  Ctrl_BSI_412_C = 0;
const boolean  Ctrl_BSI_432_C = 0;
const boolean  Ctrl_BSI_4F2_C = 0;
const boolean  Ctrl_BSI_592_C = 0;
const boolean  Ctrl_BSI_612_C = 0;
const boolean  Ctrl_BSI_CMM_0A8_C = 0;
const boolean  Ctrl_bTAirExtMes_C = 0;
const boolean  Ctrl_bTreatAdHeatRly_C = 0;
const boolean  Ctrl_bVehCollWarn_C = 0;
const boolean  Ctrl_CLIM_50E_C = 0;
const boolean  Ctrl_CMM_108_C = 0;
const boolean  Ctrl_CMM_208_C = 0;
const boolean  Ctrl_CMM_228_C = 0;
const boolean  Ctrl_CMM_348_C = 0;
const boolean  Ctrl_CMM_468_C = 0;
const boolean  Ctrl_CMM_488_C = 0;
const boolean  Ctrl_CMM_588_C = 0;
const boolean  Ctrl_CMM_608_C = 0;
const boolean  Ctrl_CMM_788_C = 0;
const boolean  Ctrl_CRASH_4C8_C = 0;
const boolean  Ctrl_ctClcProc228_C = 0;
const boolean  Ctrl_DIAG_ON_CAN_688_C = 0;
const boolean  Ctrl_DIAG_ON_CAN_6A8_C = 0;
const boolean  Ctrl_DMTR_57C_C = 0;
const boolean  Ctrl_EAC_CMM_BSI_072_C = 0;
const boolean  Ctrl_EAC_CMM_UCC_0E8_C = 0;
const boolean  Ctrl_ELECTRON_BSI_092_C = 0;
const boolean  Ctrl_EOBD_ON_CAN_7DF_C = 0;
const boolean  Ctrl_EOBD_ON_CAN_7E0_C = 0;
const boolean  Ctrl_EOBD_ON_CAN_7E8_C = 0;
const boolean  Ctrl_EOBD_ON_CAN_7ED_C = 0;
const boolean  Ctrl_iBattMes_C = 0;
const boolean  Ctrl_IS_VIN_VDS_BSI_492_C = 0;
const boolean  Ctrl_IS_VIN_VIS_BSI_4B2_C = 0;
const boolean  Ctrl_IS_VIN_WMI_BSI_4D2_C = 0;
const boolean  Ctrl_noCks228_C = 0;
const boolean  Ctrl_noSupvDTC_C = 0;
const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CC_C = 0;
const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CD_C = 0;
const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CE_C = 0;
const boolean  Ctrl_OUTIL_PRTCLE_CCP_7CF_C = 0;
const boolean  Ctrl_rAccP_C = 0;
const boolean  Ctrl_resBattIt_C = 0;
const boolean  Ctrl_RQD_CMM_BSI_072_C = 0;
const boolean  Ctrl_RQD_CMM_UCC_0E8_C = 0;
const boolean  Ctrl_SecBrkPedPrss_C = 0;
const boolean  Ctrl_spdVeh_C = 0;
const boolean  Ctrl_stBrkIp_C = 0;
const boolean  Ctrl_stECUMiss_C = 0;
const boolean  Ctrl_stJDD2Answ_C = 0;
const boolean  Ctrl_stJDDAnsw_C = 0;
const boolean  Ctrl_stPwt_C = 0;
const boolean  Ctrl_StRlyR3_C = 0;
const boolean  Ctrl_stSt_C = 0;
const boolean  Ctrl_tCoMes_C = 0;
const boolean  Ctrl_tqDrvFil_C = 0;
const boolean  Ctrl_uBattOc_C = 0;
const boolean  Ctrl_uBattStrt_C = 0;
const boolean  Ctrl_UCC_CMM_0E0_C = 0;
const boolean  Ctrl_UDS_ON_CAN_7FF_C = 0;
const boolean  Ext_bAcv_AccPSftyLvl2_C = 0;
const boolean  Ext_bAcv_BrkAsiSftyLvl2_C = 0;
const boolean  Ext_bAcv_BrkSftyLvl2_C = 0;
const boolean  Ext_bAcv_CluSftyLvl2_C = 0;
const boolean  Ext_bAcv_FHCANF329Lvl2_C = 0;
const boolean  Ext_bAcv_FHCANF349Lvl2_C = 0;
const boolean  Ext_bAcv_FHCANF34DLvl2_C = 0;
const boolean  Ext_bAcv_FHCANF38DLvl2_C = 0;
const boolean  Ext_bAcv_FHCANF3C9Lvl2_C = 0;
const boolean  Ext_bAcv_NeutPosnAcqSftyLvl2_C = 0;
const boolean  Ext_bAcv_RelBrkAsiSftyLvl2_C = 0;
const boolean  Ext_bAcv_ThrSftyLvl2_C = 0;
const boolean  Ext_bAcv_VehSpdSftyLvl2_C = 0;
const boolean  Far_bSelFarSpMdlCf_C = 0;
const boolean  Fu_bAcv_FuTnkPmp_C = 0;
const boolean  Fu_bAcv_HpPmp_C = 0;
const boolean  HPPmpAct_bAcv_PFuAcq_C = 0;
const boolean  Oil_bAcv_uEngOilLvl_C = 0;
const boolean  OilSysHw_bOilPmpCmd_C = 0;
const boolean  Spg_bAcv_pUsThr_C = 0;
const boolean  VlvAct_bAcvVlvActExStr_C = 0;
const boolean  VlvAct_bAcvVlvActInStr_C = 0;
const boolean  Wg_bTrbAct_rCtl_C = 0;
const uint8  CTRLCFG_u8Inhib = 0;
const uint8  Ext_stBrkAsiTypCf_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Cf_bKeyLine;
boolean Cf_bPushLine;
boolean Ctrl_ABR_38D;
boolean Ctrl_ABR_44D;
boolean Ctrl_ABR_50D;
boolean Ctrl_Acq_bNeut;
boolean Ctrl_bACClu;
boolean Ctrl_bAcv_bModSptReq;
boolean Ctrl_bAcv_ctStaAcv;
boolean Ctrl_bAcv_pwrEngSndModSpt;
boolean Ctrl_bAcv_rBoostPresSndModSpt;
boolean Ctrl_bAcv_rPwrEngSndModSpt;
boolean Ctrl_bAcv_rTqEfcSndModSpt;
boolean Ctrl_bAcv_stModSpt;
boolean Ctrl_bAcv_stVehCf;
boolean Ctrl_bAcv_tqEfcSndModSpt;
boolean Ctrl_bAcvSta;
boolean Ctrl_bAcvStaReq;
boolean Ctrl_bChaTqAvl;
boolean Ctrl_bChaTqCrt;
boolean Ctrl_bCluPedPrss;
boolean Ctrl_bCluPedPrssSen;
boolean Ctrl_bCmExAcq;
boolean Ctrl_bCmInAcq;
boolean Ctrl_bDgoBody;
boolean Ctrl_bDrvAvl;
boolean Ctrl_bDynFctAcvCplm;
boolean Ctrl_bDynFctAcvSec;
boolean Ctrl_bEngCutReq;
boolean Ctrl_bEngRStrtReqSTT;
boolean Ctrl_bEngStrtReq;
boolean Ctrl_bEngStrtReq2;
boolean Ctrl_bfAcvConstEm2;
boolean Ctrl_bfSlavePtlWkuSt;
boolean Ctrl_bFuTnkEmp;
boolean Ctrl_bHeatReq;
boolean Ctrl_bHillAsiRdyEngStop;
boolean Ctrl_bInfoAcvCluPed;
boolean Ctrl_bInfoRdy;
boolean Ctrl_bInhAcqESPFrnt;
boolean Ctrl_bLiMILReqGUS;
boolean Ctrl_BlowBy1Hw;
boolean Ctrl_bMainBrkPedPrss;
boolean Ctrl_bMainBrkPedPrssHSCha;
boolean Ctrl_bMainBrkPedPrssHSVeh;
boolean Ctrl_bMainBrkPedPrssMes;
boolean Ctrl_bNeut;
boolean Ctrl_bOpFSFReq;
boolean Ctrl_bPosnFSF;
boolean Ctrl_bPush;
boolean Ctrl_bRecNotStop;
boolean Ctrl_bRStrtAnt;
boolean Ctrl_bRvs;
boolean Ctrl_bSelFarSpMdlCf;
boolean Ctrl_BSI_412;
boolean Ctrl_BSI_432;
boolean Ctrl_BSI_4F2;
boolean Ctrl_BSI_552;
boolean Ctrl_BSI_572;
boolean Ctrl_BSI_592;
boolean Ctrl_BSI_612;
boolean Ctrl_BSI_792;
boolean Ctrl_BSI_CMM_0A8;
boolean Ctrl_bStopIp;
boolean Ctrl_bStrtLockAcq;
boolean Ctrl_bTAirExtMes;
boolean Ctrl_bTraTqAuthRaw;
boolean Ctrl_bTypStrt;
boolean Ctrl_bUncrt_tqCkEngReal;
boolean Ctrl_bUncrt_tqEM;
boolean Ctrl_bVehCollWarn;
boolean Ctrl_bVSCtlDft;
boolean Ctrl_bVSLimReq;
boolean Ctrl_bVSRegDVSRegReq;
boolean Ctrl_bVSSNwAcvSt;
boolean Ctrl_bVVTVlvEx;
boolean Ctrl_bVVTVlvIn;
boolean Ctrl_bWaitStrtReq;
boolean Ctrl_bWkuMainSev;
boolean Ctrl_bWupAcv;
boolean Ctrl_CDS_34D;
boolean Ctrl_CLIM_50E;
boolean Ctrl_CMM_108;
boolean Ctrl_CMM_1E8;
boolean Ctrl_CMM_208;
boolean Ctrl_CMM_228;
boolean Ctrl_CMM_348;
boolean Ctrl_CMM_388;
boolean Ctrl_CMM_3B8;
boolean Ctrl_CMM_438;
boolean Ctrl_CMM_468;
boolean Ctrl_CMM_488;
boolean Ctrl_CMM_588;
boolean Ctrl_CMM_5F8;
boolean Ctrl_CMM_608;
boolean Ctrl_CMM_788;
boolean Ctrl_CMM_BV_2E8;
boolean Ctrl_CMMPropSnsrOnly_PTT;
boolean Ctrl_CONTEXTE_1_5B2;
boolean Ctrl_CONTEXTE_1_7F2;
boolean Ctrl_CRASH_4C8;
boolean Ctrl_ctBSIFrame;
boolean Ctrl_ctClcProc228;
boolean Ctrl_ctClcProc50D;
boolean Ctrl_DAT_BSI_532;
boolean Ctrl_DIAG_ON_CAN_688;
boolean Ctrl_DIAG_ON_CAN_6A8;
boolean Ctrl_DIRA_495;
boolean Ctrl_DMTR_57C;
boolean Ctrl_EAC_CMM_BSI_072;
boolean Ctrl_EAC_CMM_UCC_0E8;
boolean Ctrl_EASY_MOVE_3AD;
boolean Ctrl_ELECTRON_BSI_092;
boolean Ctrl_EOBD_ON_CAN_7DF;
boolean Ctrl_EOBD_ON_CAN_7E0;
boolean Ctrl_EOBD_ON_CAN_7E8;
boolean Ctrl_EOBD_ON_CAN_7ED;
boolean Ctrl_ESPPropSnsr_CMMPropSnsr;
boolean Ctrl_ESPPropSnsr_CMMSwt;
boolean Ctrl_facSen_uEmPredRstrt;
boolean Ctrl_FRE_30D;
boolean Ctrl_FRE_3CD;
boolean Ctrl_iBattMes;
boolean Ctrl_idxPtSptBVA;
boolean Ctrl_idxPtSptBVMP;
boolean Ctrl_JDD_CAN_BSI_772;
boolean Ctrl_JDD_CAN_CMM_768;
boolean Ctrl_NEW_JDD_55F;
boolean Ctrl_NEW_JDD_CMM_768;
boolean Ctrl_noCalCurBattMes;
boolean Ctrl_noCks228;
boolean Ctrl_noCks50D;
boolean Ctrl_noCks50E;
boolean Ctrl_noEngStrt;
boolean Ctrl_noIncCurBattMes;
boolean Ctrl_noJDD;
boolean Ctrl_noSupvDTC;
boolean Ctrl_nTrb;
boolean Ctrl_OUTIL_PRTCLE_CCP_7CC;
boolean Ctrl_OUTIL_PRTCLE_CCP_7CD;
boolean Ctrl_OUTIL_PRTCLE_CCP_7CE;
boolean Ctrl_OUTIL_PRTCLE_CCP_7CF;
boolean Ctrl_pAC;
boolean Ctrl_pBoostSndModSpt;
boolean Ctrl_pBrkMCT;
boolean Ctrl_posnAMTLev;
boolean Ctrl_pwrAC;
boolean Ctrl_rAccP;
boolean Ctrl_rBattSoC;
boolean Ctrl_rCluP;
boolean Ctrl_rCluPCAN;
boolean Ctrl_rCluPedPrssMes;
boolean Ctrl_rCnvTq;
boolean Ctrl_resBattIt;
boolean Ctrl_RQD_CMM_BSI_072;
boolean Ctrl_RQD_CMM_UCC_0E8;
boolean Ctrl_rSlopStab;
boolean Ctrl_SecBrkPedPrss;
boolean Ctrl_spdVeh;
boolean Ctrl_spdVehVSCtlReq;
boolean Ctrl_stAcvWarn;
boolean Ctrl_stAdHeat;
boolean Ctrl_stBattSoC;
boolean Ctrl_stBrkIp;
boolean Ctrl_stDiagESPReq;
boolean Ctrl_stDrvAvl;
boolean Ctrl_stECUMiss;
boolean Ctrl_stElEProv;
boolean Ctrl_stEngRStrtInh;
boolean Ctrl_stEngRStrtReq;
boolean Ctrl_stEngStopAuth;
boolean Ctrl_stGearShiftReq;
boolean Ctrl_stGSIEna;
boolean Ctrl_stHillAsi;
boolean Ctrl_stJDD2Answ;
boolean Ctrl_stJDDAnsw;
boolean Ctrl_stNetwEl;
boolean Ctrl_stPosATLevPNCAN;
boolean Ctrl_stPosn;
boolean Ctrl_stPosnFSFReq;
boolean Ctrl_stPrioVoltMax;
boolean Ctrl_stPrioVoltMin;
boolean Ctrl_stPwt;
boolean Ctrl_stReq;
boolean Ctrl_stReqBlsVoltCtl;
boolean Ctrl_StRlyR3;
boolean Ctrl_stSt;
boolean Ctrl_stStaAuth;
boolean Ctrl_stSTTLightAcv;
boolean Ctrl_STT_BV_329;
boolean Ctrl_STT_CMM_3C8;
boolean Ctrl_stTypEmPredRstrt;
boolean Ctrl_stVSCtl;
boolean Ctrl_stVSCtlReq;
boolean Ctrl_tCoMes;
boolean Ctrl_tqCnsATRStrt;
boolean Ctrl_tqCnvExtd;
boolean Ctrl_tqDrvFil;
boolean Ctrl_tqEM;
boolean Ctrl_tqLoss;
boolean Ctrl_uBattClc;
boolean Ctrl_uBattOc;
boolean Ctrl_uBattStrt;
boolean Ctrl_UCC_CMM_0E0;
boolean Ctrl_UDS_ON_CAN_7FF;
boolean Ctrl_uEmPredRstrt;
boolean Ctrl_uReqProdMax;
boolean Ctrl_uReqProdMin;
boolean Ctrl_uReqProdSlope;
boolean Ctrl_V2_BSI_552;
boolean Ctrl_V2_BV_3C9;
boolean Ctrl_V2_BV_489;
boolean Ctrl_V2_BVA_349;
boolean Ctrl_V2_BVMP_349;
boolean Ctrl_VDS_BSI_492;
boolean Ctrl_VIS_BSI_4B2;
boolean Ctrl_VOL_305;
boolean Ctrl_VSSNwMgt_bVSSNwAcvAuth;
boolean Ctrl_WMI_BSI_4D2;
boolean Ext_bAcv_AccPSftyLvl2;
boolean Ext_bAcv_BrkAsiSftyLvl2;
boolean Ext_bAcv_BrkSftyLvl2;
boolean Ext_bAcv_CluSftyLvl2;
boolean Ext_bAcv_FHCANF329Lvl2;
boolean Ext_bAcv_FHCANF349Lvl2;
boolean Ext_bAcv_FHCANF34DLvl2;
boolean Ext_bAcv_FHCANF38DLvl2;
boolean Ext_bAcv_FHCANF3C9Lvl2;
boolean Ext_bAcv_NeutPosnAcqSftyLvl2;
boolean Ext_bAcv_RelBrkAsiSftyLvl2;
boolean Ext_bAcv_ThrSftyLvl2;
boolean Ext_bAcv_VehSpdSftyLvl2;
boolean Ext_bEngRun_Archi2010EcoPush;
uint8 Ext_stBrkAsiTypCf;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

