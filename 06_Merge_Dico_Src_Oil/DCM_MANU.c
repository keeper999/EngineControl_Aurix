/***************************************************************************
;**
;** FILE NAME      : DCM_MANU.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DCM_MANU_FIX.h"
#include "IUPRRATIO.h"
#include "RTE_TYPE.h"
#include "DCM_MANU.H"
#include "DCM_MANU_L.H"
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
const boolean  Srv_bInhImmoToBoot_C = 0;
const boolean  Srv_bManuInhOBD_C = 0;
const boolean  Srv_bTeleSAOkInh_C = 0;
const boolean  Srv_bTeleSASeedInh_C = 0;
const boolean  Srv_bWriteTeleEnable_C = 0;
const uint8  ActrTstMng_tCoMesMinTest_C = 0;
const uint8  ActrTstMng_tCoMesMinTestFarSp_C = 0;
const uint8  ActrTstMng_tCoMesMinTestHpPmp_C = 0;
const uint8  ActrTstMng_VVehiMax = 0;
const uint8  Diag_seuil_vit_veh = 0;
const uint8  Srv_ctActrTstHpPmpMax_C = 0;
const uint8  Srv_ctInjrChrnWrSt_C = 0;
const uint8  Srv_ctPostEquWrSt_C = 0;
const uint8  Srv_ctTeleWrSt_C = 0;
const uint8  Srv_InjrChrnDataSize_C = 0;
const uint8  Srv_PostEquDataSize_C = 0;
const uint8  Srv_TeleDataSize_C = 0;
const uint8  Srv_tiBypCntOverNEngMax_C = 0;
const uint8  Srv_tiBypCtAuthCloThr_C = 0;
const sint16  Srv_uDwnldMaxVolt_C = 0;
const sint16  Srv_uDwnldMinVolt_C = 0;
const uint16  ActrTstMng_nEngRunMaxTest_C = 0;
const uint16  ActrTstMng_nEngRunMaxTestFarSp_C = 0;
const uint16  ActrTstMng_nEngRunMaxTestHpPmp_C = 0;
const uint16  ActrTstMng_nEngRunMinTest_C = 0;
const uint16  ActrTstMng_nEngRunMinTestFarSp_C = 0;
const uint16  ActrTstMng_nEngRunMinTestHpPmp_C = 0;
const uint16  ActrTstMng_nEngStopMaxTest_C = 0;
const uint16  ActrTstMng_pFuMaxHpPmp_C = 0;
const uint16  ActrTstMng_pFuMaxTestInj_C = 0;
const uint16  ActrTstMng_UBatMax = 0;
const uint16  ActrTstMng_UBatMin = 0;
const uint16  Srv_pFuRailAftsThd_C = 0;
const uint16  Srv_tiRcRstEnd_C = 0;
const uint16  Srv_tiRcSttEnd_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
uint8 DCM_MANU_ActionDmnd;
uint8 Srv_stTeleAccessStatus;
boolean Afts_bAcvModAfts;
boolean Afts_bEnaTestAftsDiag;
boolean Afts_bEngCtlDiagRun;
boolean Afts_bRstCntDiagCluP;
boolean Afts_bRstCtAuthCloThr;
boolean Afts_bRstESLim;
boolean DCM_MANU_bEnaNack;
boolean DCM_MANU_bSaEnable;
boolean DCM_MANU_ReqIuprReceived;
boolean DCM_MANU_Srv_bInhBoostGDI_prev;
boolean Presence_BP;
boolean Presence_CAT1;
boolean Presence_EVAP;
boolean Presence_O2S1;
boolean Presence_SO2S1;
boolean Presence_VVT;
boolean Srv_bActrTstDmd;
boolean Srv_bActrTstDmdWithCndVld;
boolean Srv_bActrTstRunning;
boolean Srv_bActrTstStop;
boolean Srv_bAcvUnloadRail;
boolean Srv_bBypCntOverNEngMax;
boolean Srv_bBypCtAuthCloThr;
boolean Srv_bInhBoostGDI;
boolean Srv_bInhSftyLvl2;
boolean Srv_bInhThr;
boolean Srv_bPostEquWrChck;
boolean Srv_bRcCdnNok_AcvUnloadRail;
boolean Srv_bRcCdnNok_BattChg;
boolean Srv_bRcCdnNok_InhBoostGDI;
boolean Srv_bRcCdnNok_IniRealTiTroCnt;
boolean Srv_bRcCdnNok_MkdPwrl;
boolean Srv_bRcCdnNok_ModeSTTAftsReq;
boolean Srv_bRcCdnNok_ModeSTTBatt;
boolean Srv_bRcCdnNok_ModeSTTFactReq;
boolean Srv_bRcCdnNok_ProdTest;
boolean Srv_bRcCdnNok_RstAFAMgtT;
boolean Srv_bRcCdnNok_RstCluDftCnt;
boolean Srv_bRcCdnNok_RstCoReqRStrt;
boolean Srv_bRcCdnNok_RstCtAuthCloThr;
boolean Srv_bRcCdnNok_RstCurRdB;
boolean Srv_bRcCdnNok_RstCylHdDmgCnt;
boolean Srv_bRcCdnNok_RstCylHdDmgCplmCnt;
boolean Srv_bRcCdnNok_RstDfwChg;
boolean Srv_bRcCdnNok_RstESLim;
boolean Srv_bRcCdnNok_RstLrn_Misf;
boolean Srv_bRcCdnNok_RstMnfDmgCnt;
boolean Srv_bRcCdnNok_RstPed;
boolean Srv_bRcCdnNok_RstReqStcBatt;
boolean Srv_bRcCdnNok_RstStaCnt;
boolean Srv_bRcCdnNok_RstTrbActSys;
boolean Srv_bRcCdnNok_RstTrbDmgCnt;
boolean Srv_bRcCdnNok_SftyLvl2;
boolean Srv_bRcCdnNok_ThrInh;
boolean Srv_bRcCdnOk_AcvUnloadRail;
boolean Srv_bRcCdnOk_BattChg;
boolean Srv_bRcCdnOk_InhBoostGDI;
boolean Srv_bRcCdnOk_IniRealTiTroCnt;
boolean Srv_bRcCdnOk_MkdPwrl;
boolean Srv_bRcCdnOk_ModeSTTAftsReq;
boolean Srv_bRcCdnOk_ModeSTTBatt;
boolean Srv_bRcCdnOk_ModeSTTFactReq;
boolean Srv_bRcCdnOk_ProdTest;
boolean Srv_bRcCdnOk_RstAFAMgtT;
boolean Srv_bRcCdnOk_RstCluDftCnt;
boolean Srv_bRcCdnOk_RstCoReqRStrt;
boolean Srv_bRcCdnOk_RstCtAuthCloThr;
boolean Srv_bRcCdnOk_RstCurRdB;
boolean Srv_bRcCdnOk_RstCylHdDmgCnt;
boolean Srv_bRcCdnOk_RstCylHdDmgCplmCnt;
boolean Srv_bRcCdnOk_RstDfwChg;
boolean Srv_bRcCdnOk_RstESLim;
boolean Srv_bRcCdnOk_RstLrn_Misf;
boolean Srv_bRcCdnOk_RstMnfDmgCnt;
boolean Srv_bRcCdnOk_RstPed;
boolean Srv_bRcCdnOk_RstReqStcBatt;
boolean Srv_bRcCdnOk_RstStaCnt;
boolean Srv_bRcCdnOk_RstTrbActSys;
boolean Srv_bRcCdnOk_RstTrbDmgCnt;
boolean Srv_bRcCdnOk_SftyLvl2;
boolean Srv_bRcCdnOk_ThrInh;
boolean Srv_bRcCom_AcvUnloadRail;
boolean Srv_bRcCom_BattChg;
boolean Srv_bRcCom_InhBoostGDI;
boolean Srv_bRcCom_IniRealTiTroCnt;
boolean Srv_bRcCom_MkdPwrl;
boolean Srv_bRcCom_ModeSTTAftsReq;
boolean Srv_bRcCom_ModeSTTBatt;
boolean Srv_bRcCom_ModeSTTFactReq;
boolean Srv_bRcCom_ProdTest;
boolean Srv_bRcCom_RstAFAMgtT;
boolean Srv_bRcCom_RstCluDftCnt;
boolean Srv_bRcCom_RstCoReqRStrt;
boolean Srv_bRcCom_RstCtAuthCloThr;
boolean Srv_bRcCom_RstCurRdB;
boolean Srv_bRcCom_RstCylHdDmgCnt;
boolean Srv_bRcCom_RstCylHdDmgCplmCnt;
boolean Srv_bRcCom_RstDfwChg;
boolean Srv_bRcCom_RstESLim;
boolean Srv_bRcCom_RstLrn_Misf;
boolean Srv_bRcCom_RstMnfDmgCnt;
boolean Srv_bRcCom_RstPed;
boolean Srv_bRcCom_RstReqStcBatt;
boolean Srv_bRcCom_RstStaCnt;
boolean Srv_bRcCom_RstTrbActSys;
boolean Srv_bRcCom_RstTrbDmgCnt;
boolean Srv_bRcCom_SftyLvl2;
boolean Srv_bRcCom_ThrInh;
boolean Srv_bRcCondOk_AcvUnloadRail;
boolean Srv_bRcCondOk_BattChg;
boolean Srv_bRcCondOk_InhBoostGDI;
boolean Srv_bRcCondOk_IniRealTiTroCnt;
boolean Srv_bRcCondOk_MkdPwrl;
boolean Srv_bRcCondOk_ModeSTTAftsReq;
boolean Srv_bRcCondOk_ModeSTTBatt;
boolean Srv_bRcCondOk_ModeSTTFactReq;
boolean Srv_bRcCondOk_ProdTest;
boolean Srv_bRcCondOk_RstAFAMgtT;
boolean Srv_bRcCondOk_RstCluDftCnt;
boolean Srv_bRcCondOk_RstCoReqRStrt;
boolean Srv_bRcCondOk_RstCtAuthCloThr;
boolean Srv_bRcCondOk_RstCurRdB;
boolean Srv_bRcCondOk_RstCylHdDmgCnt;
boolean Srv_bRcCondOk_RstCylHdDmgCplmCnt;
boolean Srv_bRcCondOk_RstDfwChg;
boolean Srv_bRcCondOk_RstESLim;
boolean Srv_bRcCondOk_RstLrn_Misf;
boolean Srv_bRcCondOk_RstMnfDmgCnt;
boolean Srv_bRcCondOk_RstPed;
boolean Srv_bRcCondOk_RstReqStcBatt;
boolean Srv_bRcCondOk_RstStaCnt;
boolean Srv_bRcCondOk_RstTrbActSys;
boolean Srv_bRcCondOk_RstTrbDmgCnt;
boolean Srv_bRcCondOk_SftyLvl2;
boolean Srv_bRcCondOk_ThrInh;
boolean Srv_bRcReq_ActrTst;
boolean Srv_bRcReq_AcvUnloadRail;
boolean Srv_bRcReq_BattChg;
boolean Srv_bRcReq_InhBoostGDI;
boolean Srv_bRcReq_IniRealTiTroCnt;
boolean Srv_bRcReq_MkdPwrl;
boolean Srv_bRcReq_ModeSTTAftsReq;
boolean Srv_bRcReq_ModeSTTBatt;
boolean Srv_bRcReq_ModeSTTFactReq;
boolean Srv_bRcReq_ProdTest;
boolean Srv_bRcReq_RstAFAMgtT;
boolean Srv_bRcReq_RstCluDftCnt;
boolean Srv_bRcReq_RstCoReqRStrt;
boolean Srv_bRcReq_RstCtAuthCloThr;
boolean Srv_bRcReq_RstCurRdB;
boolean Srv_bRcReq_RstCylHdDmgCnt;
boolean Srv_bRcReq_RstCylHdDmgCplmCnt;
boolean Srv_bRcReq_RstDfwChg;
boolean Srv_bRcReq_RstESLim;
boolean Srv_bRcReq_RstLrn_Misf;
boolean Srv_bRcReq_RstMnfDmgCnt;
boolean Srv_bRcReq_RstPed;
boolean Srv_bRcReq_RstReqStcBatt;
boolean Srv_bRcReq_RstStaCnt;
boolean Srv_bRcReq_RstTrbActSys;
boolean Srv_bRcReq_RstTrbDmgCnt;
boolean Srv_bRcReq_SftyLvl2;
boolean Srv_bRcReq_ThrInh;
boolean Srv_bRcStart_ActrTst;
boolean Srv_bRcStart_AcvUnloadRail;
boolean Srv_bRcStart_BattChg;
boolean Srv_bRcStart_InhBoostGDI;
boolean Srv_bRcStart_IniRealTiTroCnt;
boolean Srv_bRcStart_MkdPwrl;
boolean Srv_bRcStart_ModeSTTAftsReq;
boolean Srv_bRcStart_ModeSTTBatt;
boolean Srv_bRcStart_ModeSTTFactReq;
boolean Srv_bRcStart_ProdTest;
boolean Srv_bRcStart_RstAFAMgtT;
boolean Srv_bRcStart_RstCluDftCnt;
boolean Srv_bRcStart_RstCoReqRStrt;
boolean Srv_bRcStart_RstCtAuthCloThr;
boolean Srv_bRcStart_RstCurRdB;
boolean Srv_bRcStart_RstCylHdDmgCnt;
boolean Srv_bRcStart_RstCylHdDmgCplmCnt;
boolean Srv_bRcStart_RstDfwChg;
boolean Srv_bRcStart_RstESLim;
boolean Srv_bRcStart_RstLrn_Misf;
boolean Srv_bRcStart_RstMnfDmgCnt;
boolean Srv_bRcStart_RstPed;
boolean Srv_bRcStart_RstReqStcBatt;
boolean Srv_bRcStart_RstStaCnt;
boolean Srv_bRcStart_RstTrbActSys;
boolean Srv_bRcStart_RstTrbDmgCnt;
boolean Srv_bRcStart_SftyLvl2;
boolean Srv_bRcStart_ThrInh;
boolean Srv_bRcStop_ActrTst;
boolean Srv_bRcStop_AcvUnloadRail;
boolean Srv_bRcStop_BattChg;
boolean Srv_bRcStop_InhBoostGDI;
boolean Srv_bRcStop_IniRealTiTroCnt;
boolean Srv_bRcStop_MkdPwrl;
boolean Srv_bRcStop_ModeSTTAftsReq;
boolean Srv_bRcStop_ModeSTTBatt;
boolean Srv_bRcStop_ModeSTTFactReq;
boolean Srv_bRcStop_ProdTest;
boolean Srv_bRcStop_RstAFAMgtT;
boolean Srv_bRcStop_RstCluDftCnt;
boolean Srv_bRcStop_RstCoReqRStrt;
boolean Srv_bRcStop_RstCtAuthCloThr;
boolean Srv_bRcStop_RstCurRdB;
boolean Srv_bRcStop_RstCylHdDmgCnt;
boolean Srv_bRcStop_RstCylHdDmgCplmCnt;
boolean Srv_bRcStop_RstDfwChg;
boolean Srv_bRcStop_RstESLim;
boolean Srv_bRcStop_RstLrn_Misf;
boolean Srv_bRcStop_RstMnfDmgCnt;
boolean Srv_bRcStop_RstPed;
boolean Srv_bRcStop_RstReqStcBatt;
boolean Srv_bRcStop_RstStaCnt;
boolean Srv_bRcStop_RstTrbActSys;
boolean Srv_bRcStop_RstTrbDmgCnt;
boolean Srv_bRcStop_SftyLvl2;
boolean Srv_bRcStop_ThrInh;
boolean Srv_bReqDSCDiagReceived;
boolean Srv_bRstSw_DiagSrv;
boolean Srv_bStartDiag;
boolean Srv_bTeleWrChck;
boolean Srv_ClearDTC_Dmnd;
uint32 DCM_MANU_Code_Antidemarrage;
uint32 DCM_MANU_SaCalcKeyAdr;
uint32 DCM_MANU_TeleSaSeed;
Std_ReturnType DCM_MANU_TestProdReturnValue;
uint8 DataBuffer[DATABUFFER_COLS];
uint8 DCM_MANU_Cntrl_Inhibition;
uint8 DCM_MANU_Cntrl_ModeSTT;
uint8 DCM_MANU_CodeTestBlowby_prev;
uint8 DCM_MANU_CodeTestBobine_prev;
uint8 DCM_MANU_CodeTestChoixCyl_prev;
uint8 DCM_MANU_CodeTestChoixSonde_prev;
uint8 DCM_MANU_CodeTestChoixVites_prev;
uint8 DCM_MANU_CodeTestVVT_prev;
uint8 DCM_MANU_Data_DADAPT[DCM_MANU_DATA_DADAPT_LNS];
uint8 DCM_MANU_ErrorCode;
uint8 DCM_MANU_Option_Appairage;
uint8 DCM_MANU_PFuCtl_agWdPmpCmdReq;
uint8 Det_Cpt;
uint8 Det_u8ApiId[DET_U8APIID_COLS];
uint8 Det_u8ErrorId[DET_U8ERRORID_COLS];
uint8 Det_u8InstanceId[DET_U8INSTANCEID_COLS];
uint8 Srv_ctActrTstHpPmp;
uint8 Srv_ctInjrChrnWrSt;
uint8 Srv_ctPostEquWrSt;
uint8 Srv_ctTeleWrSt;
uint8 Srv_prmPostEquRawData[SRV_PRMPOSTEQURAWDATA_COLS];
uint8 Srv_stActrTstCode;
uint8 Srv_stActrTstCodePrev;
uint8 Srv_stInjrChrnGetSt;
uint8 Srv_stInjrChrnWrChck;
uint8 Srv_stInjrChrnWrSt;
uint8 Srv_stPostEquWrChck;
uint8 Srv_stPostEquWrSt;
uint8 Srv_stRc_AcvUnloadRail;
uint8 Srv_stRc_BattChg;
uint8 Srv_stRc_InhBoostGDI;
uint8 Srv_stRc_IniRealTiTroCnt;
uint8 Srv_stRc_MkdPwrl;
uint8 Srv_stRc_ModeSTTAftsReq;
uint8 Srv_stRc_ModeSTTBatt;
uint8 Srv_stRc_ModeSTTFactReq;
uint8 Srv_stRc_ProdTest;
uint8 Srv_stRc_RstAFAMgtT;
uint8 Srv_stRc_RstCluDftCnt;
uint8 Srv_stRc_RstCoReqRStrt;
uint8 Srv_stRc_RstCtAuthCloThr;
uint8 Srv_stRc_RstCurRdB;
uint8 Srv_stRc_RstCylHdDmgCnt;
uint8 Srv_stRc_RstCylHdDmgCplmCnt;
uint8 Srv_stRc_RstDfwChg;
uint8 Srv_stRc_RstESLim;
uint8 Srv_stRc_RstLrn_Misf;
uint8 Srv_stRc_RstMnfDmgCnt;
uint8 Srv_stRc_RstPed;
uint8 Srv_stRc_RstReqStcBatt;
uint8 Srv_stRc_RstStaCnt;
uint8 Srv_stRc_RstTrbActSys;
uint8 Srv_stRc_RstTrbDmgCnt;
uint8 Srv_stRc_SftyLvl2;
uint8 Srv_stRc_ThrInh;
uint8 Srv_stRcActrTst;
uint8 Srv_stRcEnd_AcvUnloadRail;
uint8 Srv_stRcEnd_BattChg;
uint8 Srv_stRcEnd_InhBoostGDI;
uint8 Srv_stRcEnd_IniRealTiTroCnt;
uint8 Srv_stRcEnd_MkdPwrl;
uint8 Srv_stRcEnd_ModeSTTAftsReq;
uint8 Srv_stRcEnd_ModeSTTBatt;
uint8 Srv_stRcEnd_ModeSTTFactReq;
uint8 Srv_stRcEnd_ProdTest;
uint8 Srv_stRcEnd_RstAFAMgtT;
uint8 Srv_stRcEnd_RstCluDftCnt;
uint8 Srv_stRcEnd_RstCoReqRStrt;
uint8 Srv_stRcEnd_RstCtAuthCloThr;
uint8 Srv_stRcEnd_RstCurRdB;
uint8 Srv_stRcEnd_RstCylHdDmgCnt;
uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;
uint8 Srv_stRcEnd_RstDfwChg;
uint8 Srv_stRcEnd_RstESLim;
uint8 Srv_stRcEnd_RstLrn_Misf;
uint8 Srv_stRcEnd_RstMnfDmgCnt;
uint8 Srv_stRcEnd_RstPed;
uint8 Srv_stRcEnd_RstReqStcBatt;
uint8 Srv_stRcEnd_RstStaCnt;
uint8 Srv_stRcEnd_RstTrbActSys;
uint8 Srv_stRcEnd_RstTrbDmgCnt;
uint8 Srv_stRcEnd_SftyLvl2;
uint8 Srv_stRcEnd_ThrInh;
uint8 Srv_stTeleWrChck;
uint8 Srv_stTeleWrSt;
uint8 Srv_tiBypCntOverNEngMax;
uint8 Srv_tiBypCtAuthCloThr;
uint8 Tele_program_raw_data[TELE_PROGRAM_RAW_DATA_COLS];
uint16 DCM_MANU_IuprDen[DCM_MANU_IUPRDEN_COLS];
uint16 DCM_MANU_IuprNum[DCM_MANU_IUPRNUM_COLS];
uint16 DCM_MANU_sizeECUIdentification;
uint16 DCM_MANU_TestProdParam;
uint16 DCM_MANU_UdsIuprFrameSize;
uint16 DCM_MANU_UdsIuprIndexToSend;
uint16 DCM_MANU_UdsIuprNbByteSent;
uint16 Det_u16ModuleId[DET_U16MODULEID_COLS];
uint16 Srv_ctAuthCloThr;
uint16 Srv_tiCntOverNEngMax;
uint16 Srv_tiRcRstEnd;
uint16 Srv_tiRcSttEnd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

