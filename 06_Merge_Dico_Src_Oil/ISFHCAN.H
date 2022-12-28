/***************************************************************************
;**
;** FILE NAME      : ISFHCAN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ISFHCAN_H
#define ISFHCAN_H

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

extern const boolean  AC_bACCluRcf_C;
extern const boolean  AC_bOpFSFReqRcf_C;
extern const boolean  AltCtl_bCmpReqRcf_C;
extern const boolean  Cha_bInhVSCtlRcf_C;
extern const boolean  Cha_bMainBrkPedPrssMesRcf_C;
extern const boolean  Cha_tqRevAcvRcf_C;
extern const boolean  CoReqAMT_bEngRStrtReqRcf_C;
extern const boolean  CoReqCha_bEngRStrtReqRcf_C;
extern const boolean  CoReqStg_bEngRStrtReqRcf_C;
extern const boolean  CoReqStg_bEngStopAuthRcf_C;
extern const boolean  CoReqVeh_bEngStrtReqRcf_C;
extern const boolean  CoReqVeh_bMainBrkPedPrssHSRcf_C;
extern const boolean  CoReqVeh_bMainBrkPedPrssRcf_C;
extern const boolean  CoReqVeh_bOilMesReqRcf_C;
extern const boolean  Ext_bABSRegRcf_C;
extern const boolean  Ext_bAcvStaRcf_C;
extern const boolean  Ext_bASRRegFirstRcf_C;
extern const boolean  Ext_bAuthWupElMgtRcf_C;
extern const boolean  Ext_bBrkParkRcf_C;
extern const boolean  Ext_bDftFctEMRcf_C;
extern const boolean  Ext_bDgo_iBattMesRcf_C;
extern const boolean  Ext_bDgo_tBattMesRcf_C;
extern const boolean  Ext_bDgo_uBattClcRcf_C;
extern const boolean  Ext_bDgoBodyRcf_C;
extern const boolean  Ext_bDynFctAcvCplmRcf_C;
extern const boolean  Ext_bEngStopReqRcf_C;
extern const boolean  Ext_bEngStrtReqRcf_C;
extern const boolean  Ext_bESPRegFirstRcf_C;
extern const boolean  Ext_bFuTnkEmpRcf_C;
extern const boolean  Ext_bImmoUnlockWkuReqRcf_C;
extern const boolean  Ext_bInhStrtAMTRcf_C;
extern const boolean  Ext_bModSptReqRcf_C;
extern const boolean  Ext_bOilWkuReqRcf_C;
extern const boolean  Ext_bPushRcf_C;
extern const boolean  Ext_bRStrtAuthTraRcf_C;
extern const boolean  Ext_bRvsRcf_C;
extern const boolean  Ext_bTypStrtRcf_C;
extern const boolean  Ext_bVSSNwAcvStRcf_C;
extern const boolean  GBx_bSpdFanGBxReqRcf_C;
extern const boolean  Tra_bFrzACRcf_C;
extern const boolean  Tra_bNRegReqRcf_C;
extern const boolean  Tra_bSIPPrepRcf_C;
extern const boolean  Tra_bSIPRcf_C;
extern const boolean  Tra_bSTTDftRcf_C;
extern const boolean  Tra_bTqTxRcf_C;
extern const boolean  Veh_bHeatReqRcf_C;
extern const sint8  CoReqCha_rSlopStabRcf_C;
extern const sint8  Ext_iBattMaxCkgRcf_C;
extern const sint8  Tra_noEgdGearRcf_C;
extern const sint8  Tra_noTarGearRcf_C;
extern const uint8  AC_pwrACRcf_C;
extern const uint8  AC_rSpdFanReqRcf_C;
extern const uint8  Cha_stEPBRcf_C;
extern const uint8  CoReqAMT_bEngStopAuthRcf_C;
extern const uint8  CoReqCha_stEngRStrtInhRcf_C;
extern const uint8  CoReqVeh_stAdHeatRcf_C;
extern const uint8  CoReqVeh_stEngRStrtReqRcf_C;
extern const uint8  CoReqVeh_stEngStopAuthRcf_C;
extern const uint8  CoReqVeh_stWkuMainRcf_C;
extern const uint8  ElecMgt_stPrioVoltMaxRcf_C;
extern const uint8  ElecMgt_stPrioVoltMinRcf_C;
extern const uint8  ElecMgt_stProdMgtTypRcf_C;
extern const uint8  ElecMgt_uReqProdSlopeRcf_C;
extern const uint8  Ext_bfAcvConstElMgt1Rcf_C;
extern const uint8  Ext_bfAcvConstElMgt2Rcf_C;
extern const uint8  Ext_bfAcvConstElMgt3Rcf_C;
extern const uint8  Ext_CtRstCurVehTmrRcf_C;
extern const uint8  Ext_noCks228IniCks_C;
extern const uint8  Ext_noCks305IniCks_C;
extern const uint8  Ext_noCks329IniCks_C;
extern const uint8  Ext_noCks349IniCks_C;
extern const uint8  Ext_noCks38DIniCks_C;
extern const uint8  Ext_noCks3ADIniCks_C;
extern const uint8  Ext_noCks3C9IniCks_C;
extern const uint8  Ext_noCks50DIniCks_C;
extern const uint8  Ext_posnATLevRcf_C;
extern const uint8  Ext_resBattItNormRcf_C;
extern const uint8  Ext_rFuTnkPercRcf_C;
extern const uint8  Ext_stBattSoCRcf_C;
extern const uint8  Ext_stBrkIpRcf_C;
extern const uint8  Ext_stCtlModFSFRcf_C;
extern const uint8  Ext_stFuLvlDftRcf_C;
extern const uint8  Ext_stHillAsiRcf_C;
extern const uint8  Ext_stPosATLevPNCANRcf_C;
extern const uint8  Ext_stTqReqRcf_C;
extern const uint8  Ext_stVehCfRcf_C;
extern const uint8  Ext_tiMonRunBSItoCMM_C;
extern const uint8  Ext_tiMonRunBVtoCMM1_C;
extern const uint8  Ext_tiMonRunBVtoCMM2_C;
extern const uint8  Ext_tiMonRunBVtoCMM3_C;
extern const uint8  Ext_tiMonRunCAVtoCMM1_C;
extern const uint8  Ext_tiMonRunCAVtoCMM2_C;
extern const uint8  Ext_tiMonRunCAVtoCMM3_C;
extern const uint8  Ext_tiMonRunDIRAtoCMM1_C;
extern const uint8  Ext_tiMonRunDIRAtoCMM2_C;
extern const uint8  Ext_tiMonRunDIRAtoCMM3_C;
extern const uint8  Ext_tiMonRunDMTRtoCMM1_C;
extern const uint8  Ext_tiMonRunDMTRtoCMM2_C;
extern const uint8  Ext_tiMonRunDMTRtoCMM3_C;
extern const uint8  Ext_tiMonRunUCFtoCMM1_C;
extern const uint8  Ext_tiMonRunUCFtoCMM2_C;
extern const uint8  Ext_tiMonRunUCFtoCMM3_C;
extern const uint8  Ext_tqAirASRReqRcf_C;
extern const uint8  Ext_tqDynASRReqRcf_C;
extern const uint8  Ext_tqMSRReqRcf_C;
extern const uint8  ShdFlap_stPosnRcf_C;
extern const uint8  Tra_idxPtSptRcf_C;
extern const uint8  Tra_stCnvCluRcf_C;
extern const uint8  Tra_stCplRcf_C;
extern const uint8  Tra_stDragRedRcf_C;
extern const uint8  Tra_stGBxModRcf_C;
extern const uint8  Tra_stGearCtlFirstRcf_C;
extern const uint8  Tra_stGearRatRcf_C;
extern const uint8  Tra_stGSTypRcf_C;
extern const uint8  Tra_stNRegTypRcf_C;
extern const uint8  Tra_tqCnsATRStrtRcf_C;
extern const uint8  Veh_stDrvAvlRcf_C;
extern const sint16  Ext_aVehRcf_C;
extern const sint16  Ext_tAirExtMesRcf_C;
extern const sint16  Ext_tBattMesRcf_C;
extern const sint16  Ext_tOilGBxRcf_C;
extern const sint16  Ext_tqCkCANRcf_C;
extern const sint16  Ext_uBattMaxBSItoCMM_C;
extern const sint16  Ext_uBattMaxBVtoCMM_C;
extern const sint16  Ext_uBattMaxCAVtoCMM_C;
extern const sint16  Ext_uBattMaxDAEtoCMM_C;
extern const sint16  Ext_uBattMaxDIRAtoCMM_C;
extern const sint16  Ext_uBattMaxUCFtoCMM_C;
extern const sint16  Ext_uBattMinBSItoCMM_C;
extern const sint16  Ext_uBattMinBVtoCMM_C;
extern const sint16  Ext_uBattMinCAVtoCMM_C;
extern const sint16  Ext_uBattMinDIRAtoCMM_C;
extern const sint16  Ext_uBattMinDMTRtoCMM_C;
extern const sint16  Ext_uBattMinUCFtoCMM_C;
extern const sint16  Stg_agStrWhlRcf_C;
extern const sint16  Tra_tqLossRcf_C;
extern const sint16  Tra_tqMaxGBxRcf_C;
extern const sint16  Tra_tqReqGBxRcf_C;
extern const uint16  CAN_noIncCurBattMesRcf_C;
extern const uint16  Clm_nTarIdlRcf_C;
extern const uint16  ElecMgt_uReqProdMaxRcf_C;
extern const uint16  ElecMgt_uReqProdMinRcf_C;
extern const uint16  Ext_nAvrFrntWhlRcf_C;
extern const uint16  Ext_rBattSoCRcf_C;
extern const uint16  Ext_rCluPCANRcf_C;
extern const uint16  Ext_resBattItRcf_C;
extern const uint16  Ext_spdEspVehRcf_C;
extern const uint16  Ext_spdLeFrntWhlRcf_C;
extern const uint16  Ext_spdLeReWhlRcf_C;
extern const uint16  Ext_spdRiFrntWhlRcf_C;
extern const uint16  Ext_spdRiReWhlRcf_C;
extern const uint16  Ext_spdVehAvrFrntWhlRcf_C;
extern const uint16  Ext_uBattClcRcf_C;
extern const uint16  Ext_uBattMinCkgRcf_C;
extern const uint16  Ext_uBattOcRcf_C;
extern const uint16  Ext_uBattRstrtRcf_C;
extern const uint16  Ext_vLeReWhlMesRcf_C;
extern const uint16  Ext_vRiReWhlMesRcf_C;
extern const uint16  Stg_agvStrWhlRcf_C;
extern const uint16  Tra_rCnvTqRcf_C;
extern const uint16  Tra_tqCnvExtdRcf_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AltCtl_bCmpReq;
extern boolean Can_bFrzAC;
extern boolean Can_bNRegReq;
extern boolean Can_bSIP;
extern boolean Can_bSIPPrep;
extern boolean Can_bTqTx;
extern boolean Cc_acc_regulation_type_mux;
extern boolean Cc_limitation_speed_on_mux;
extern boolean Cc_regulation_speed_on_mux;
extern boolean Cha_bInhVSCtl;
extern boolean Cha_bMainBrkPedPrssMes;
extern boolean Cha_tqRevAcv;
extern boolean CoReqCha_bEngStopAuth;
extern boolean CoReqStg_bEngStopAuth;
extern boolean CoReqVeh_bMainBrkPedPrss;
extern boolean CoReqVeh_bMainBrkPedPrssHS;
extern boolean CoReqVeh_bOilMesReq;
extern boolean CoReqVeh_bOilWkuReq;
extern boolean Ext_bABSReg50D;
extern boolean Ext_bASRRegFirst;
extern boolean Ext_bBrkPark;
extern boolean Ext_bDelDftReq;
extern boolean Ext_bDftFctEM;
extern boolean Ext_bDgo_iBattMes;
extern boolean Ext_bDgo_tBattMes;
extern boolean Ext_bDgo_uBattClc;
extern boolean Ext_bDgoBody;
extern boolean Ext_bDynFctAcvCplm;
extern boolean Ext_bElIntgDiag;
extern boolean Ext_bElIntgDiagMod;
extern boolean Ext_bESPRegFirst;
extern boolean Ext_bFuLvlDft;
extern boolean Ext_bFuTnkEmp;
extern boolean Ext_bImmoUnlockWkuReq;
extern boolean Ext_bLiRegESPASR;
extern boolean Ext_bModSptReq;
extern boolean Ext_bMonRunBSItoCMM;
extern boolean Ext_bMonRunBVtoCMM;
extern boolean Ext_bMonRunCAVtoCMM;
extern boolean Ext_bMonRunDIRAtoCMM;
extern boolean Ext_bMonRunDMTRtoCMM;
extern boolean Ext_bMonRunUCFreintoCMM;
extern boolean Ext_bNotAvl_CtRstCurVehTmr;
extern boolean Ext_bNotAvl_iBattMaxCkg;
extern boolean Ext_bNotAvl_noIncCurBattMes;
extern boolean Ext_bNotAvl_nTar;
extern boolean Ext_bNotAvl_rCluPCAN;
extern boolean Ext_bNotAvl_resBattItNorm;
extern boolean Ext_bNotAvl_rSlopStab;
extern boolean Ext_bNotAvl_spdLeFrntWhl;
extern boolean Ext_bNotAvl_spdLeReWhl;
extern boolean Ext_bNotAvl_spdRiFrntWhl;
extern boolean Ext_bNotAvl_spdRiReWhl;
extern boolean Ext_bNotAvl_stProdMgtTyp;
extern boolean Ext_bNotAvl_tAirExtMes;
extern boolean Ext_bNotAvl_tiCurVehTmr;
extern boolean Ext_bNotAvl_uBattMinCkg;
extern boolean Ext_bOilWkuReq;
extern boolean Ext_bPrepIgEngWkuReq;
extern boolean Ext_bRCDLineSec;
extern boolean Ext_bRvsMux;
extern boolean Ext_bStopEngCoWkuReq;
extern boolean Ext_bVSLimReq;
extern boolean Ext_bVSRegDVSRegReq;
extern boolean Flev_low_fuel_level_mux;
extern boolean GBx_bSpdFanGBxReq;
extern boolean ISCAN_bF572PM1446;
extern boolean MonBrk_bMainBrkPedPrssHS;
extern boolean Tra_bCntMILRst;
extern boolean Tra_bGBxRdy;
extern boolean Tra_bLevMod;
extern boolean Tra_bLiMILReq;
extern boolean Tra_bLiMILReqGUS;
extern boolean Tra_bSTTDft;
extern boolean WaHt_bWaHt1Out;
extern boolean WaHt_bWaHt2Out;
extern uint32 Ext_ctSecCAN;
extern uint32 Ext_tiCurVehTmr;
extern uint32 Km_vehicle_mux_552h;
extern uint32 Km_vehicle_mux_7F2h;
extern sint8 Can_noEgdGear;
extern sint8 Can_noTarGear;
extern uint8 CAN_noCalCurBattMes;
extern uint8 Can_posnATLev;
extern uint8 Can_stCnvClu;
extern uint8 Can_stCpl;
extern uint8 Can_stDragRed;
extern uint8 Can_stGearRat;
extern uint8 Can_stGSTyp;
extern uint8 Can_stNRegTyp;
extern uint8 Can_stPosATLevExtdCAN;
extern uint8 CoRegVeh_stDftOBD;
extern uint8 CoReqVeh_stAdHeat;
extern uint8 CoReqVeh_stNetwEl;
extern uint8 CoReqVeh_stWkuMain;
extern uint8 CoReqVeh_stWkuMainSEV;
extern uint8 ElecMgt_stProdMgtTyp;
extern uint8 Ext_ctBSIFrame;
extern uint8 Ext_ctClcProc305;
extern uint8 Ext_ctClcProc329;
extern uint8 Ext_ctClcProc349;
extern uint8 Ext_ctClcProc34D;
extern uint8 Ext_ctClcProc38D;
extern uint8 Ext_ctClcProc3AD;
extern uint8 Ext_ctClcProc3C9;
extern uint8 Ext_ctClcProc50D;
extern uint8 Ext_CtRstCurVehTmr;
extern uint8 Ext_ctYrCAN;
extern uint8 Ext_noCks305;
extern uint8 Ext_noCks329;
extern uint8 Ext_noCks349;
extern uint8 Ext_noCks38D;
extern uint8 Ext_noCks3AD;
extern uint8 Ext_noCks3C9;
extern uint8 Ext_noCks50D;
extern uint8 Ext_noCks50E;
extern uint8 Ext_noDiag;
extern uint8 Ext_noJDD;
extern uint8 Ext_noVDS1;
extern uint8 Ext_noVDS2;
extern uint8 Ext_noVDS3;
extern uint8 Ext_noVDS4;
extern uint8 Ext_noVDS5;
extern uint8 Ext_noVDS6;
extern uint8 Ext_noVIS1;
extern uint8 Ext_noVIS2;
extern uint8 Ext_noVIS3;
extern uint8 Ext_noVIS4;
extern uint8 Ext_noVIS5;
extern uint8 Ext_noVIS6;
extern uint8 Ext_noVIS7;
extern uint8 Ext_noVIS8;
extern uint8 Ext_noWMI1;
extern uint8 Ext_noWMI2;
extern uint8 Ext_noWMI3;
extern uint8 Ext_rFuTnkPerc;
extern uint8 Ext_spdVehVSCtlReq;
extern uint8 Ext_stBrkIp;
extern uint8 Ext_stCtlModFSF;
extern uint8 Ext_stFuLvlDft;
extern uint8 Ext_stHillAsi;
extern uint8 Ext_stJDD2Answ;
extern uint8 Ext_stJDDAnsw;
extern uint8 Ext_stPosATLevPNCAN;
extern uint8 Ext_stTqReq;
extern uint8 Ext_stVehCf;
extern uint8 Ext_stVSCtlReq;
extern uint8 Ext_tqAirASRReq;
extern uint8 Ext_tqDynASRReq;
extern uint8 Ext_tqMSRReq;
extern uint8 Fuel_gauge_diag_mux;
extern uint8 ISCAN_u8F0A8Pos1;
extern uint8 ISCAN_u8F0A8Pos2;
extern uint8 ISCAN_u8F0A8Pos3;
extern uint8 ISCAN_u8F0A8Pos4;
extern uint8 ISCAN_u8F0A8Pos5;
extern uint8 ISCAN_u8F0E0Pos1;
extern uint8 ISCAN_u8F0E0Pos2;
extern uint8 ISCAN_u8F0E0Pos3;
extern uint8 ISCAN_u8F0E0Pos4;
extern uint8 ISCAN_u8F0E0Pos5;
extern uint8 ISCAN_u8N2F4F2P429;
extern uint8 ISCAN_u8N2F50EP232;
extern uint8 ISCAN_u8N3F34DP047;
extern uint8 ISCAN_u8N4F34DP157;
extern uint8 ISCAN_u8N6F34DPM1413;
extern uint8 ISCAN_u8N8F34DP043;
extern uint8 ISCAN_u8N8F34DP044;
extern uint8 ISCAN_u8N8F34DP045;
extern uint8 ISCAN_u8N8F492PM1475;
extern uint8 ISCAN_u8N8F492PM1476;
extern uint8 ISCAN_u8N8F492PM1477;
extern uint8 ISCAN_u8N8F492PM1478;
extern uint8 ISCAN_u8N8F492PM1479;
extern uint8 ISCAN_u8N8F492PM1480;
extern uint8 ISCAN_u8N8F4B2PM1481;
extern uint8 ISCAN_u8N8F4B2PM1482;
extern uint8 ISCAN_u8N8F4B2PM1483;
extern uint8 ISCAN_u8N8F4B2PM1484;
extern uint8 ISCAN_u8N8F4B2PM1485;
extern uint8 ISCAN_u8N8F4B2PM1486;
extern uint8 ISCAN_u8N8F4B2PM1487;
extern uint8 ISCAN_u8N8F4B2PM1488;
extern uint8 ISCAN_u8N8F4D2PM1472;
extern uint8 ISCAN_u8N8F4D2PM1473;
extern uint8 ISCAN_u8N8F4D2PM1474;
extern uint8 ISCAN_u8N8F50EP219;
extern uint8 ISCAN_u8N8F7F2P849;
extern uint8 Tra_stGBxDft;
extern uint8 Tra_stGearCtlFirst;
extern uint8 Tra_tqCnsATRStrt;
extern sint16 Can_tqMaxGBx;
extern sint16 Can_tqReqGBx;
extern sint16 Ext_aVeh;
extern sint16 Ext_tAirSideMirrMes_5B2h;
extern sint16 Ext_tAirSideMirrMes_7F2h;
extern sint16 Ext_tqCkCAN;
extern sint16 Tra_tqLoss;
extern uint16 CAN_noIncCurBattMes;
extern uint16 Can_nTar;
extern uint16 Clm_nTarIdl;
extern uint16 Ext_ctDayCAN;
extern uint16 Ext_rCluPCAN;
extern uint16 Ext_spdEspVeh;
extern uint16 Ext_spdLeFrntWhl;
extern uint16 Ext_spdRiFrntWhl;
extern uint16 Ext_vLeReWhlMes;
extern uint16 Ext_vRiReWhlMes;
extern uint16 ISCAN_u16N16F30DP263;
extern uint16 ISCAN_u16N16F30DP264;
extern uint16 ISCAN_u16N16F30DP265;
extern uint16 ISCAN_u16N16F30DP266;
extern uint16 Tra_rConvTra;
extern uint16 Tra_tqCnvExtd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* ISFHCAN_H */

/*-------------------------------- end of file -------------------------------*/
