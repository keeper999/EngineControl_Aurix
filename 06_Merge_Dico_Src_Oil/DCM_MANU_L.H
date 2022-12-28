/***************************************************************************
;**
;** FILE NAME      : DCM_MANU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DCM_MANU_L_H
#define DCM_MANU_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DCM_MANU_FIX.h"
#include "IUPRRATIO.h"
#include "RTE_TYPE.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DATABUFFER_COLS                        ( 24 )
#define DATALENGTH_1                      1
#define DATALENGTH_10                     10
#define DATALENGTH_11                     11
#define DATALENGTH_16                     16
#define DATALENGTH_2                      2
#define DATALENGTH_21                     21
#define DATALENGTH_24                     24
#define DATALENGTH_4                      4
#define DATALENGTH_7                      7
#define DATALENGTH_9                      9
#define DCM_MANU_CLRDTC_OBD_SID           4
#define DCM_MANU_CLRDTC_UDS_SID           20
#define DCM_MANU_CONTROLDTCSETTING_SID    133
#define DCM_MANU_DATA_DADAPT_LNS              ( 33 )
#define DCM_MANU_DATALENGTH_E018          4
#define DCM_MANU_DATALENGTH_E019          2
#define DCM_MANU_DATALENGTH_E01B          4
#define DCM_MANU_ECUMANUFDATE_DID         61835
#define DCM_MANU_EREGORTYPEAPPRVLNUM_DID  61846
#define DCM_MANU_IUPRDEN_COLS                  ( 106 )
#define DCM_MANU_IUPRNUM_COLS                  ( 106 )
#define DCM_MANU_KEY_SIZE                 4
#define DCM_MANU_MANUFACTURINGDATESIZE    3
#define DCM_MANU_OBDSRV09_INFTYP_00       0
#define DCM_MANU_OBDSRV09_INFTYP_02       2
#define DCM_MANU_OBDSRV09_INFTYP_04       4
#define DCM_MANU_OBDSRV09_INFTYP_08       8
#define DCM_MANU_OBDSRV09_SID             9
#define DCM_MANU_SIGNATURE_OUTILS         61530
#define DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE  2
#define DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE  11
#define DCM_MANU_WRITE_SID                46
#define DCM_MANU_ZA_BYTE_SIZE             22
#define DCM_MANU_ZA_DID                   61568
#define DCM_MANU_ZI_BYTE_SIZE             24
#define DCM_MANU_ZI_DID                   61694
#define DET_U16MODULEID_COLS                   ( 10 )
#define DET_U8APIID_COLS                       ( 10 )
#define DET_U8ERRORID_COLS                     ( 10 )
#define DET_U8INSTANCEID_COLS                  ( 10 )
#define RC_COND_NOK                       0
#define RC_ENGINE_RUNNING                 1
#define RC_ENGINE_RUNNING_TOO_HIGH        2
#define RC_ENGINE_RUNNING_TOO_LOW         3
#define RC_FINISHED_NOK                   4
#define RC_FINISHED_OK                    5
#define RC_GEAR                           6
#define RC_INIT                           7
#define RC_PEDAL_TOO_HIGH                 8
#define RC_REJECT                         19
#define RC_REQ_SEQU_ERROR                 9
#define RC_RUNNING                        10
#define RC_STOPPED                        11
#define RC_STRT_AFTER_STRT                12
#define RC_VEHICULE_SPEED                 13
#define RC_VOLT_TOO_HIGH                  15
#define RC_VOLT_TOO_LOW                   16
#define RC_WAITING                        17
#define RC_WATER_TEMP_TOO_LOW             18
#define ROUTINE_EN_COURS                  1
#define TERMINE_NOK                       3
#define TERMINE_OK                        2

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st666 */
/*extern uint8 DCM_MANU_ActionDmnd;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint8 DCM_MANU_ActionDmnd;
extern boolean DCM_MANU_bEnaNack;
extern boolean DCM_MANU_bSaEnable;
extern boolean DCM_MANU_ReqIuprReceived;
extern boolean DCM_MANU_Srv_bInhBoostGDI_prev;
extern boolean Presence_BP;
extern boolean Presence_CAT1;
extern boolean Presence_EVAP;
extern boolean Presence_O2S1;
extern boolean Presence_SO2S1;
extern boolean Presence_VVT;
extern boolean Srv_bRcCdnNok_AcvUnloadRail;
extern boolean Srv_bRcCdnNok_BattChg;
extern boolean Srv_bRcCdnNok_InhBoostGDI;
extern boolean Srv_bRcCdnNok_IniRealTiTroCnt;
extern boolean Srv_bRcCdnNok_MkdPwrl;
extern boolean Srv_bRcCdnNok_ModeSTTAftsReq;
extern boolean Srv_bRcCdnNok_ModeSTTBatt;
extern boolean Srv_bRcCdnNok_ModeSTTFactReq;
extern boolean Srv_bRcCdnNok_ProdTest;
extern boolean Srv_bRcCdnNok_RstAFAMgtT;
extern boolean Srv_bRcCdnNok_RstCluDftCnt;
extern boolean Srv_bRcCdnNok_RstCoReqRStrt;
extern boolean Srv_bRcCdnNok_RstCtAuthCloThr;
extern boolean Srv_bRcCdnNok_RstCurRdB;
extern boolean Srv_bRcCdnNok_RstCylHdDmgCnt;
extern boolean Srv_bRcCdnNok_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcCdnNok_RstDfwChg;
extern boolean Srv_bRcCdnNok_RstESLim;
extern boolean Srv_bRcCdnNok_RstLrn_Misf;
extern boolean Srv_bRcCdnNok_RstMnfDmgCnt;
extern boolean Srv_bRcCdnNok_RstPed;
extern boolean Srv_bRcCdnNok_RstReqStcBatt;
extern boolean Srv_bRcCdnNok_RstStaCnt;
extern boolean Srv_bRcCdnNok_RstTrbActSys;
extern boolean Srv_bRcCdnNok_RstTrbDmgCnt;
extern boolean Srv_bRcCdnNok_SftyLvl2;
extern boolean Srv_bRcCdnNok_ThrInh;
extern boolean Srv_bRcCdnOk_AcvUnloadRail;
extern boolean Srv_bRcCdnOk_BattChg;
extern boolean Srv_bRcCdnOk_InhBoostGDI;
extern boolean Srv_bRcCdnOk_IniRealTiTroCnt;
extern boolean Srv_bRcCdnOk_MkdPwrl;
extern boolean Srv_bRcCdnOk_ModeSTTAftsReq;
extern boolean Srv_bRcCdnOk_ModeSTTBatt;
extern boolean Srv_bRcCdnOk_ModeSTTFactReq;
extern boolean Srv_bRcCdnOk_ProdTest;
extern boolean Srv_bRcCdnOk_RstAFAMgtT;
extern boolean Srv_bRcCdnOk_RstCluDftCnt;
extern boolean Srv_bRcCdnOk_RstCoReqRStrt;
extern boolean Srv_bRcCdnOk_RstCtAuthCloThr;
extern boolean Srv_bRcCdnOk_RstCurRdB;
extern boolean Srv_bRcCdnOk_RstCylHdDmgCnt;
extern boolean Srv_bRcCdnOk_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcCdnOk_RstDfwChg;
extern boolean Srv_bRcCdnOk_RstESLim;
extern boolean Srv_bRcCdnOk_RstLrn_Misf;
extern boolean Srv_bRcCdnOk_RstMnfDmgCnt;
extern boolean Srv_bRcCdnOk_RstPed;
extern boolean Srv_bRcCdnOk_RstReqStcBatt;
extern boolean Srv_bRcCdnOk_RstStaCnt;
extern boolean Srv_bRcCdnOk_RstTrbActSys;
extern boolean Srv_bRcCdnOk_RstTrbDmgCnt;
extern boolean Srv_bRcCdnOk_SftyLvl2;
extern boolean Srv_bRcCdnOk_ThrInh;
extern boolean Srv_bRcCom_AcvUnloadRail;
extern boolean Srv_bRcCom_BattChg;
extern boolean Srv_bRcCom_InhBoostGDI;
extern boolean Srv_bRcCom_IniRealTiTroCnt;
extern boolean Srv_bRcCom_MkdPwrl;
extern boolean Srv_bRcCom_ModeSTTAftsReq;
extern boolean Srv_bRcCom_ModeSTTBatt;
extern boolean Srv_bRcCom_ModeSTTFactReq;
extern boolean Srv_bRcCom_ProdTest;
extern boolean Srv_bRcCom_RstAFAMgtT;
extern boolean Srv_bRcCom_RstCluDftCnt;
extern boolean Srv_bRcCom_RstCoReqRStrt;
extern boolean Srv_bRcCom_RstCtAuthCloThr;
extern boolean Srv_bRcCom_RstCurRdB;
extern boolean Srv_bRcCom_RstCylHdDmgCnt;
extern boolean Srv_bRcCom_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcCom_RstDfwChg;
extern boolean Srv_bRcCom_RstESLim;
extern boolean Srv_bRcCom_RstLrn_Misf;
extern boolean Srv_bRcCom_RstMnfDmgCnt;
extern boolean Srv_bRcCom_RstPed;
extern boolean Srv_bRcCom_RstReqStcBatt;
extern boolean Srv_bRcCom_RstStaCnt;
extern boolean Srv_bRcCom_RstTrbActSys;
extern boolean Srv_bRcCom_RstTrbDmgCnt;
extern boolean Srv_bRcCom_SftyLvl2;
extern boolean Srv_bRcCom_ThrInh;
extern boolean Srv_bRcCondOk_AcvUnloadRail;
extern boolean Srv_bRcCondOk_BattChg;
extern boolean Srv_bRcCondOk_InhBoostGDI;
extern boolean Srv_bRcCondOk_IniRealTiTroCnt;
extern boolean Srv_bRcCondOk_MkdPwrl;
extern boolean Srv_bRcCondOk_ModeSTTAftsReq;
extern boolean Srv_bRcCondOk_ModeSTTBatt;
extern boolean Srv_bRcCondOk_ModeSTTFactReq;
extern boolean Srv_bRcCondOk_ProdTest;
extern boolean Srv_bRcCondOk_RstAFAMgtT;
extern boolean Srv_bRcCondOk_RstCluDftCnt;
extern boolean Srv_bRcCondOk_RstCoReqRStrt;
extern boolean Srv_bRcCondOk_RstCtAuthCloThr;
extern boolean Srv_bRcCondOk_RstCurRdB;
extern boolean Srv_bRcCondOk_RstCylHdDmgCnt;
extern boolean Srv_bRcCondOk_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcCondOk_RstDfwChg;
extern boolean Srv_bRcCondOk_RstESLim;
extern boolean Srv_bRcCondOk_RstLrn_Misf;
extern boolean Srv_bRcCondOk_RstMnfDmgCnt;
extern boolean Srv_bRcCondOk_RstPed;
extern boolean Srv_bRcCondOk_RstReqStcBatt;
extern boolean Srv_bRcCondOk_RstStaCnt;
extern boolean Srv_bRcCondOk_RstTrbActSys;
extern boolean Srv_bRcCondOk_RstTrbDmgCnt;
extern boolean Srv_bRcCondOk_SftyLvl2;
extern boolean Srv_bRcCondOk_ThrInh;
extern boolean Srv_bRcReq_ActrTst;
extern boolean Srv_bRcReq_AcvUnloadRail;
extern boolean Srv_bRcReq_BattChg;
extern boolean Srv_bRcReq_InhBoostGDI;
extern boolean Srv_bRcReq_IniRealTiTroCnt;
extern boolean Srv_bRcReq_MkdPwrl;
extern boolean Srv_bRcReq_ModeSTTAftsReq;
extern boolean Srv_bRcReq_ModeSTTBatt;
extern boolean Srv_bRcReq_ModeSTTFactReq;
extern boolean Srv_bRcReq_ProdTest;
extern boolean Srv_bRcReq_RstAFAMgtT;
extern boolean Srv_bRcReq_RstCluDftCnt;
extern boolean Srv_bRcReq_RstCoReqRStrt;
extern boolean Srv_bRcReq_RstCtAuthCloThr;
extern boolean Srv_bRcReq_RstCurRdB;
extern boolean Srv_bRcReq_RstCylHdDmgCnt;
extern boolean Srv_bRcReq_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcReq_RstDfwChg;
extern boolean Srv_bRcReq_RstESLim;
extern boolean Srv_bRcReq_RstLrn_Misf;
extern boolean Srv_bRcReq_RstMnfDmgCnt;
extern boolean Srv_bRcReq_RstPed;
extern boolean Srv_bRcReq_RstReqStcBatt;
extern boolean Srv_bRcReq_RstStaCnt;
extern boolean Srv_bRcReq_RstTrbActSys;
extern boolean Srv_bRcReq_RstTrbDmgCnt;
extern boolean Srv_bRcReq_SftyLvl2;
extern boolean Srv_bRcReq_ThrInh;
extern boolean Srv_bRcStart_ActrTst;
extern boolean Srv_bRcStart_AcvUnloadRail;
extern boolean Srv_bRcStart_BattChg;
extern boolean Srv_bRcStart_InhBoostGDI;
extern boolean Srv_bRcStart_IniRealTiTroCnt;
extern boolean Srv_bRcStart_MkdPwrl;
extern boolean Srv_bRcStart_ModeSTTAftsReq;
extern boolean Srv_bRcStart_ModeSTTBatt;
extern boolean Srv_bRcStart_ModeSTTFactReq;
extern boolean Srv_bRcStart_ProdTest;
extern boolean Srv_bRcStart_RstAFAMgtT;
extern boolean Srv_bRcStart_RstCluDftCnt;
extern boolean Srv_bRcStart_RstCoReqRStrt;
extern boolean Srv_bRcStart_RstCtAuthCloThr;
extern boolean Srv_bRcStart_RstCurRdB;
extern boolean Srv_bRcStart_RstCylHdDmgCnt;
extern boolean Srv_bRcStart_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcStart_RstDfwChg;
extern boolean Srv_bRcStart_RstESLim;
extern boolean Srv_bRcStart_RstLrn_Misf;
extern boolean Srv_bRcStart_RstMnfDmgCnt;
extern boolean Srv_bRcStart_RstPed;
extern boolean Srv_bRcStart_RstReqStcBatt;
extern boolean Srv_bRcStart_RstStaCnt;
extern boolean Srv_bRcStart_RstTrbActSys;
extern boolean Srv_bRcStart_RstTrbDmgCnt;
extern boolean Srv_bRcStart_SftyLvl2;
extern boolean Srv_bRcStart_ThrInh;
extern boolean Srv_bRcStop_ActrTst;
extern boolean Srv_bRcStop_AcvUnloadRail;
extern boolean Srv_bRcStop_BattChg;
extern boolean Srv_bRcStop_InhBoostGDI;
extern boolean Srv_bRcStop_IniRealTiTroCnt;
extern boolean Srv_bRcStop_MkdPwrl;
extern boolean Srv_bRcStop_ModeSTTAftsReq;
extern boolean Srv_bRcStop_ModeSTTBatt;
extern boolean Srv_bRcStop_ModeSTTFactReq;
extern boolean Srv_bRcStop_ProdTest;
extern boolean Srv_bRcStop_RstAFAMgtT;
extern boolean Srv_bRcStop_RstCluDftCnt;
extern boolean Srv_bRcStop_RstCoReqRStrt;
extern boolean Srv_bRcStop_RstCtAuthCloThr;
extern boolean Srv_bRcStop_RstCurRdB;
extern boolean Srv_bRcStop_RstCylHdDmgCnt;
extern boolean Srv_bRcStop_RstCylHdDmgCplmCnt;
extern boolean Srv_bRcStop_RstDfwChg;
extern boolean Srv_bRcStop_RstESLim;
extern boolean Srv_bRcStop_RstLrn_Misf;
extern boolean Srv_bRcStop_RstMnfDmgCnt;
extern boolean Srv_bRcStop_RstPed;
extern boolean Srv_bRcStop_RstReqStcBatt;
extern boolean Srv_bRcStop_RstStaCnt;
extern boolean Srv_bRcStop_RstTrbActSys;
extern boolean Srv_bRcStop_RstTrbDmgCnt;
extern boolean Srv_bRcStop_SftyLvl2;
extern boolean Srv_bRcStop_ThrInh;
extern boolean Srv_bReqDSCDiagReceived;
extern uint32 DCM_MANU_SaCalcKeyAdr;
extern uint32 DCM_MANU_TeleSaSeed;
extern Std_ReturnType DCM_MANU_TestProdReturnValue;
extern uint8 DataBuffer[DATABUFFER_COLS];
extern uint8 DCM_MANU_Cntrl_Inhibition;
extern uint8 DCM_MANU_Cntrl_ModeSTT;
extern uint8 DCM_MANU_CodeTestBlowby_prev;
extern uint8 DCM_MANU_CodeTestBobine_prev;
extern uint8 DCM_MANU_CodeTestChoixCyl_prev;
extern uint8 DCM_MANU_CodeTestChoixSonde_prev;
extern uint8 DCM_MANU_CodeTestChoixVites_prev;
extern uint8 DCM_MANU_CodeTestVVT_prev;
extern uint8 DCM_MANU_Data_DADAPT[DCM_MANU_DATA_DADAPT_LNS];
extern uint8 DCM_MANU_ErrorCode;
extern uint8 DCM_MANU_PFuCtl_agWdPmpCmdReq;
extern uint8 Det_Cpt;
extern uint8 Det_u8ApiId[DET_U8APIID_COLS];
extern uint8 Det_u8ErrorId[DET_U8ERRORID_COLS];
extern uint8 Det_u8InstanceId[DET_U8INSTANCEID_COLS];
extern uint8 Srv_ctActrTstHpPmp;
extern uint8 Srv_ctInjrChrnWrSt;
extern uint8 Srv_ctPostEquWrSt;
extern uint8 Srv_stInjrChrnGetSt;
extern uint8 Srv_stInjrChrnWrSt;
extern uint8 Srv_stPostEquWrChck;
extern uint8 Srv_stPostEquWrSt;
extern uint8 Srv_stRc_AcvUnloadRail;
extern uint8 Srv_stRc_BattChg;
extern uint8 Srv_stRc_InhBoostGDI;
extern uint8 Srv_stRc_IniRealTiTroCnt;
extern uint8 Srv_stRc_MkdPwrl;
extern uint8 Srv_stRc_ModeSTTAftsReq;
extern uint8 Srv_stRc_ModeSTTBatt;
extern uint8 Srv_stRc_ModeSTTFactReq;
extern uint8 Srv_stRc_ProdTest;
extern uint8 Srv_stRc_RstAFAMgtT;
extern uint8 Srv_stRc_RstCluDftCnt;
extern uint8 Srv_stRc_RstCoReqRStrt;
extern uint8 Srv_stRc_RstCtAuthCloThr;
extern uint8 Srv_stRc_RstCurRdB;
extern uint8 Srv_stRc_RstCylHdDmgCnt;
extern uint8 Srv_stRc_RstCylHdDmgCplmCnt;
extern uint8 Srv_stRc_RstDfwChg;
extern uint8 Srv_stRc_RstESLim;
extern uint8 Srv_stRc_RstLrn_Misf;
extern uint8 Srv_stRc_RstMnfDmgCnt;
extern uint8 Srv_stRc_RstPed;
extern uint8 Srv_stRc_RstReqStcBatt;
extern uint8 Srv_stRc_RstStaCnt;
extern uint8 Srv_stRc_RstTrbActSys;
extern uint8 Srv_stRc_RstTrbDmgCnt;
extern uint8 Srv_stRc_SftyLvl2;
extern uint8 Srv_stRc_ThrInh;
extern uint8 Srv_stRcActrTst;
extern uint8 Srv_stRcEnd_AcvUnloadRail;
extern uint8 Srv_stRcEnd_BattChg;
extern uint8 Srv_stRcEnd_InhBoostGDI;
extern uint8 Srv_stRcEnd_IniRealTiTroCnt;
extern uint8 Srv_stRcEnd_MkdPwrl;
extern uint8 Srv_stRcEnd_ModeSTTAftsReq;
extern uint8 Srv_stRcEnd_ModeSTTBatt;
extern uint8 Srv_stRcEnd_ModeSTTFactReq;
extern uint8 Srv_stRcEnd_ProdTest;
extern uint8 Srv_stRcEnd_RstAFAMgtT;
extern uint8 Srv_stRcEnd_RstCluDftCnt;
extern uint8 Srv_stRcEnd_RstCoReqRStrt;
extern uint8 Srv_stRcEnd_RstCtAuthCloThr;
extern uint8 Srv_stRcEnd_RstCurRdB;
extern uint8 Srv_stRcEnd_RstCylHdDmgCnt;
extern uint8 Srv_stRcEnd_RstCylHdDmgCplmCnt;
extern uint8 Srv_stRcEnd_RstDfwChg;
extern uint8 Srv_stRcEnd_RstESLim;
extern uint8 Srv_stRcEnd_RstLrn_Misf;
extern uint8 Srv_stRcEnd_RstMnfDmgCnt;
extern uint8 Srv_stRcEnd_RstPed;
extern uint8 Srv_stRcEnd_RstReqStcBatt;
extern uint8 Srv_stRcEnd_RstStaCnt;
extern uint8 Srv_stRcEnd_RstTrbActSys;
extern uint8 Srv_stRcEnd_RstTrbDmgCnt;
extern uint8 Srv_stRcEnd_SftyLvl2;
extern uint8 Srv_stRcEnd_ThrInh;
extern uint8 Srv_tiBypCntOverNEngMax;
extern uint8 Srv_tiBypCtAuthCloThr;
extern uint16 DCM_MANU_IuprDen[DCM_MANU_IUPRDEN_COLS];
extern uint16 DCM_MANU_IuprNum[DCM_MANU_IUPRNUM_COLS];
extern uint16 DCM_MANU_sizeECUIdentification;
extern uint16 DCM_MANU_TestProdParam;
extern uint16 DCM_MANU_UdsIuprFrameSize;
extern uint16 DCM_MANU_UdsIuprIndexToSend;
extern uint16 DCM_MANU_UdsIuprNbByteSent;
extern uint16 Det_u16ModuleId[DET_U16MODULEID_COLS];
extern uint16 Srv_tiRcRstEnd;
extern uint16 Srv_tiRcSttEnd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DCM_MANU_ActTstStateMachineTransition(void);
void DCM_MANU_EveAckActrTstDmd(void);
void DCM_MANU_EveRC_SdlMid(void);
void DCM_MANU_EveRcRst1(void);
void DCM_MANU_EveRcRst2(void);
void DCM_MANU_EveRcRst4(void);
void DCM_MANU_EveRst_ActrTstRc(void);
void DCM_MANU_EveRst_RC(void);
void DCM_MANU_EveSessChg(void);
void DCM_MANU_EveSessChg_ActrTstRc(void);
void DCM_MANU_EveSessChg_RC(void);
void DCM_MANU_IuprResponseCreate(void);
void DCM_MANU_PostEquipementWriteReqInit(void);
void DCM_MANU_RcAcv_AcvUnloadRail(void);
void DCM_MANU_RcAcv_BattChg(void);
void DCM_MANU_RcAcv_InhBoostGDI(void);
void DCM_MANU_RcAcv_IniRealTiTroCnt(void);
void DCM_MANU_RcAcv_MkdPwrl(void);
void DCM_MANU_RcAcv_ModeSTTAftsReq(void);
void DCM_MANU_RcAcv_ModeSTTBatt(void);
void DCM_MANU_RcAcv_ModeSTTFactReq(void);
void DCM_MANU_RcAcv_ProdTest(void);
void DCM_MANU_RcAcv_RstAFAMgtT(void);
void DCM_MANU_RcAcv_RstCluDftCnt(void);
void DCM_MANU_RcAcv_RstCoReqRStrt(void);
void DCM_MANU_RcAcv_RstCurRdB(void);
void DCM_MANU_RcAcv_RstCylHdDmgCnt(void);
void DCM_MANU_RcAcv_RstCylHdDmgCplmCnt(void);
void DCM_MANU_RcAcv_RstDfwChg(void);
void DCM_MANU_RcAcv_RstESLim(void);
void DCM_MANU_RcAcv_RstLrn_Misf(void);
void DCM_MANU_RcAcv_RstMnfDmgCnt(void);
void DCM_MANU_RcAcv_RstPed(void);
void DCM_MANU_RcAcv_RstReqStcBatt(void);
void DCM_MANU_RcAcv_RstStaCnt(void);
void DCM_MANU_RcAcv_RstTrbActSys(void);
void DCM_MANU_RcAcv_RstTrbDmgCnt(void);
void DCM_MANU_RcAcv_SftyLvl2(void);
void DCM_MANU_RcAcv_ThrInh(void);
void DCM_MANU_ResetInit(void);
void DCM_MANU_SecurityAcessReqInit(void);
void DCM_MANU_TelecodageWriteReqInit(void);
void DCM_MANU_vidChgSesType(void);
void DCM_MANU_vidPwrl_SrvRc(void);
void DCM_MANU_VidReinitAftsVariables(void);
void DCM_MANU_vidSdlFast_DiagSrvSA(void);
void DCM_MANU_vidSetAftsVariables(boolean aftsValue);
Std_ReturnType DCM_MANU_Stop_Rc_Acttest_Factor_Mngmt(uint8 code_test, uint8  *routine_status, uint16  *last_param_lgth, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_ReqResActuatorTst(uint8 code_test_in, uint8  *ErrorCodeOut, uint8  *RoutineStatusOut, uint8  *OutputParam);
Std_ReturnType DCM_MANU_StartActuatorTst(uint8 code_test_in, uint8  *ErrorCodeOut, uint8  *RoutineStatusOut, uint8  *OutputParam);
Std_ReturnType DCM_MANU_StopActuatorTst(uint8 code_test_in, uint8  *ErrorCodeOut, uint8  *RoutineStatusOut, uint8  *OutputParam);
Std_ReturnType DCM_MANU_WriteCaracInj(uint8  *Data_in, uint16 DataLength_in, Dcm_OpStatusType OpStatus_in, Dcm_NegativeResponseCodeType  *ErrorCode_out);
Std_ReturnType DCM_MANU_WritePostEquipementMngt(uint8  *Data_in, uint16 DataLength_in, Dcm_OpStatusType OpStatus_in, Dcm_NegativeResponseCodeType  *ErrorCode_out);
Std_ReturnType DCM_MANU_WriteTelecodageMngt(uint8  *Data_in, uint16 DataLength_in, Dcm_OpStatusType OpStatus_in, Dcm_NegativeResponseCodeType  *ErrorCode_out);
boolean DCM_MANU_ActuatorTestCheckCond_Farsp(void);
Std_ReturnType DCM_MANU_CheckChangeSessionSWCcondition(uint8 SesCtrlType, uint8 RequestedMode, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstAFAMgtT(uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCnt(uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstCylHdDmgCplmCnt(uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstMnfDmgCnt(uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstTrbActSys(uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_CheckRcCdn_RstTrbDmgCnt(uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_RcAcv_RstAFAMgtT(uint8  *InBuffer, uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_RcAcv_RstCylHdDmgCnt(uint8  *InBuffer, uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_RcAcv_RstCylHdDmgCplmCnt(uint8  *InBuffer, uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_RcAcv_RstMnfDmgCnt(uint8  *InBuffer, uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_RcAcv_RstTrbActSys(uint8  *InBuffer, uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CALL_RcAcv_RstTrbDmgCnt(uint8  *InBuffer, uint8  *OutBuffer, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_Checking_Result_Analyse(uint8  *u8LocalRoutineStatus, uint8  *u8LocalErrorCode, uint8  *u8LocalOutputParam, uint16  *u16LocalCurrentDataLength);
Std_ReturnType DCM_MANU_Matching_Result_Analyse(uint8  *u8LocalRoutineStatus, uint8  *u8LocalErrorCode, uint8  *u8LocalOutputParam, uint16  *u16LocalCurrentDataLength);
Std_ReturnType DCM_MANU_Programming_Result_Analyse(uint8  *u8LocalRoutineStatus, uint8  *u8LocalErrorCode, uint8  *u8LocalOutputParam, uint16  *u16LocalCurrentDataLength);
Std_ReturnType DCM_MANU_ActTstResAnalyse(uint8  *ErrorCodeOut, uint8  *RoutineStatusOut, uint8  *OutputParam);
boolean DCM_MANU_ActuatorTestCheckCond(uint8 u8TstCode_par);
void DCM_MANU_CheckCond4AcvUnloadRail(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4BattChg(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4InhBoostGDI(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4IniRealTiTroCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4MkdPwrl(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4ModeSTTAftsReq(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4ModeSTTBatt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4ModeSTTFactReq(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4ProdTest(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstAFAMgtT(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstCluDftCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstCoReqRStrt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstCurRdB(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstCylHdDmgCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstCylHdDmgCplmCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstDfwChg(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstESLim(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstLrn_Misf(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstMnfDmgCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstPed(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstReqStcBatt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstStaCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstTrbActSys(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4RstTrbDmgCnt(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4SftyLvl2(boolean  *Srv_bRcCondOk_Namefunc);
void DCM_MANU_CheckCond4ThrInh(boolean  *Srv_bRcCondOk_Namefunc);
Std_ReturnType DCM_MANU_CheckFunctionalAvailability(uint8 SID, uint8  *RequestData, uint8 DcmRxPduId);
void DCM_MANU_CheckRcCdn_BattChg(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_MkdPwrl(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_ModeSTTAftsReq(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_ModeSTTBatt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_ModeSTTFactReq(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstAFAMgtT(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstCluDftCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstCoReqRStrt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstCurRdB(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstCylHdDmgCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstCylHdDmgCplmCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstDfwChg(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstESLim(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstMnfDmgCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstStaCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstTrbActSys(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_RstTrbDmgCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_CheckRcCdn_tiRcRstEnd(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_4AcvUnloadRail(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_InhBoostGDI(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_IniRealTiTroCnt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_ProdTest(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_RstLrn_Misf(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_RstPed(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_RstReqStcBatt(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_SftyLvl2(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
void DCM_MANU_RcCdn_ThrInh(boolean  *Srv_bRcCdnOk_NameFunc, boolean  *Srv_bRcCdnNok_NameFunc);
uint8 DCM_MANU_IuprResponseConcat(uint8  *au8IUPR, uint16  *u16Size);
Std_ReturnType DCM_MANU_RequestResult_Rc_Acttest_Factor_Mngmt(uint8 code_test, uint8  *routine_status, uint8  *output_param, uint16  *last_param_lgth, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_RoutineResAnalyse(uint8 Srv_stRc_NameFunc, boolean  *Srv_bRcCom_NameFunc, uint8  *Srv_stRcEnd_NameFunc, Dcm_NegativeResponseCodeType  *u8ErrorCode, uint8  *u8RoutineStatus);
Std_ReturnType DCM_MANU_Start_Rc_Acttest_Factor_Mngmt(uint8 code_test, uint8  *routine_status, uint16  *last_param_lgth, Dcm_NegativeResponseCodeType  *ErrorCode);


#endif /* DCM_MANU_L_H */

/*-------------------------------- end of file -------------------------------*/
