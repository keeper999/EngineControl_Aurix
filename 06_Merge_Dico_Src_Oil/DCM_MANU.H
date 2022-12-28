/***************************************************************************
;**
;** FILE NAME      : DCM_MANU.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DCM_MANU_H
#define DCM_MANU_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DCM_MANU_FIX.h"
#include "IUPRRATIO.h"
#include "RTE_TYPE.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BP                                10
#define BUF_SIZE                          24
#define CODE_TEST_B2FANHISPD              252
#define CODE_TEST_B2FANLOSPD              236
#define CODE_TEST_BLOW_BY_1               233
#define CODE_TEST_BLOW_BY_2               217
#define CODE_TEST_BOBINE_1                223
#define CODE_TEST_BOBINE_2                207
#define CODE_TEST_BOBINE_3                191
#define CODE_TEST_BOBINE_4                175
#define CODE_TEST_CTP                     235
#define CODE_TEST_CTRLTHER                226
#define CODE_TEST_DUMPVALVE               218
#define CODE_TEST_FARSP                   219
#define CODE_TEST_FUPMP                   210
#define CODE_TEST_HPPMP                   220
#define CODE_TEST_INJECTEUR_1             237
#define CODE_TEST_INJECTEUR_2             221
#define CODE_TEST_INJECTEUR_3             205
#define CODE_TEST_INJECTEUR_4             189
#define CODE_TEST_MEAP                    204
#define CODE_TEST_OILPMP                  225
#define CODE_TEST_PAP_MOT                 232
#define CODE_TEST_PURGE                   231
#define CODE_TEST_RELAIS_PUISSANCE        239
#define CODE_TEST_SO2_AM                  254
#define CODE_TEST_SO2_AV                  238
#define CODE_TEST_TURBO                   230
#define CODE_TEST_VVT_ADM                 222
#define CODE_TEST_VVT_ECH                 206
#define CODE_TEST_WTRPMP                  234
#define DCM_MANU_CHANGESESSION_SID        16
#define DCM_MANU_READ_SID                 34
#define SRV_CODCHK                        1
#define SRV_CODPROG                       2
#define SRV_LAMBDA                        0
#define SRV_MATCHING                      3
#define SRV_PRMPOSTEQURAWDATA_COLS             ( 2 )
#define TELE_PROGRAM_RAW_DATA_COLS             ( 11 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

typedef Dcm_ProgConditionsType Dcm_ProgConditionsType_typedef;
/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st58 */
#define SRV_TELEACCESS_REQ_NOK            0
#define SRV_TELEACCESS_IDLE               1
#define SRV_TELEACCESS_PRGM               2
#define SRV_TELEACCESS_REQ_OK             4
#define SRV_TELEACCESS_TELE_ENABLE        8
#define SRV_TELEACCESS_PRGM_POSTEQU       16
/*extern uint8 Srv_stTeleAccessStatus;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Srv_bInhImmoToBoot_C;
extern const boolean  Srv_bManuInhOBD_C;
extern const boolean  Srv_bTeleSAOkInh_C;
extern const boolean  Srv_bTeleSASeedInh_C;
extern const boolean  Srv_bWriteTeleEnable_C;
extern const uint8  ActrTstMng_tCoMesMinTest_C;
extern const uint8  ActrTstMng_tCoMesMinTestFarSp_C;
extern const uint8  ActrTstMng_tCoMesMinTestHpPmp_C;
extern const uint8  ActrTstMng_VVehiMax;
extern const uint8  Diag_seuil_vit_veh;
extern const uint8  Srv_ctActrTstHpPmpMax_C;
extern const uint8  Srv_ctInjrChrnWrSt_C;
extern const uint8  Srv_ctPostEquWrSt_C;
extern const uint8  Srv_ctTeleWrSt_C;
extern const uint8  Srv_InjrChrnDataSize_C;
extern const uint8  Srv_PostEquDataSize_C;
extern const uint8  Srv_TeleDataSize_C;
extern const uint8  Srv_tiBypCntOverNEngMax_C;
extern const uint8  Srv_tiBypCtAuthCloThr_C;
extern const sint16  Srv_uDwnldMaxVolt_C;
extern const sint16  Srv_uDwnldMinVolt_C;
extern const uint16  ActrTstMng_nEngRunMaxTest_C;
extern const uint16  ActrTstMng_nEngRunMaxTestFarSp_C;
extern const uint16  ActrTstMng_nEngRunMaxTestHpPmp_C;
extern const uint16  ActrTstMng_nEngRunMinTest_C;
extern const uint16  ActrTstMng_nEngRunMinTestFarSp_C;
extern const uint16  ActrTstMng_nEngRunMinTestHpPmp_C;
extern const uint16  ActrTstMng_nEngStopMaxTest_C;
extern const uint16  ActrTstMng_pFuMaxHpPmp_C;
extern const uint16  ActrTstMng_pFuMaxTestInj_C;
extern const uint16  ActrTstMng_UBatMax;
extern const uint16  ActrTstMng_UBatMin;
extern const uint16  Srv_pFuRailAftsThd_C;
extern const uint16  Srv_tiRcRstEnd_C;
extern const uint16  Srv_tiRcSttEnd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern uint8 Srv_stTeleAccessStatus;
extern boolean Afts_bAcvModAfts;
extern boolean Afts_bEnaTestAftsDiag;
extern boolean Afts_bEngCtlDiagRun;
extern boolean Afts_bRstCntDiagCluP;
extern boolean Afts_bRstCtAuthCloThr;
extern boolean Afts_bRstESLim;
extern boolean Srv_bActrTstDmd;
extern boolean Srv_bActrTstDmdWithCndVld;
extern boolean Srv_bActrTstRunning;
extern boolean Srv_bActrTstStop;
extern boolean Srv_bAcvUnloadRail;
extern boolean Srv_bBypCntOverNEngMax;
extern boolean Srv_bBypCtAuthCloThr;
extern boolean Srv_bInhBoostGDI;
extern boolean Srv_bInhSftyLvl2;
extern boolean Srv_bInhThr;
extern boolean Srv_bPostEquWrChck;
extern boolean Srv_bRstSw_DiagSrv;
extern boolean Srv_bStartDiag;
extern boolean Srv_bTeleWrChck;
extern boolean Srv_ClearDTC_Dmnd;
extern uint32 DCM_MANU_Code_Antidemarrage;
extern uint8 DCM_MANU_Option_Appairage;
extern uint8 Srv_ctTeleWrSt;
extern uint8 Srv_prmPostEquRawData[SRV_PRMPOSTEQURAWDATA_COLS];
extern uint8 Srv_stActrTstCode;
extern uint8 Srv_stActrTstCodePrev;
extern uint8 Srv_stInjrChrnWrChck;
extern uint8 Srv_stTeleWrChck;
extern uint8 Srv_stTeleWrSt;
extern uint8 Tele_program_raw_data[TELE_PROGRAM_RAW_DATA_COLS];
extern uint16 Srv_ctAuthCloThr;
extern uint16 Srv_tiCntOverNEngMax;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Dcm_Confirmation(Dcm_IdContextType idContext, PduIdType dcmRxPduId, Dcm_ConfirmationStatusType status);
void DCM_MANU_CaracInjWriteReqInit(void);
void DCM_MANU_EveRcStt(void);
void DCM_MANU_Reset(void);
void DCM_MANU_vidEveRst(void);
void DCM_MANU_vidEveRst_SrvDiagConst(void);
void DCM_MANU_vidSdlFast(void);
void DCM_MANU_vidSdlMid_SrvDiagConst(void);
void Dcm_vidStopAllRoutines(void);
void Srv_EveAckActrTstDmd_ActrTstMng(void);
void Srv_EveInitSa_DiagSrv(void);
void Srv_EveInitWdbi_DiagSrv(void);
void Srv_EvePwrl_SrvRc(void);
void SrvRc_SdlFast_DiagSrv(void);
void SrvRc_SdlMid_RcRst(void);
Std_ReturnType DCM_MANU_StartProtocol(Dcm_ProtocolType ProtocolID);
Std_ReturnType DCM_MANU_StopProtocol(Dcm_ProtocolType ProtocolID);
Std_ReturnType DCM_MANU_SupplierIndication(uint8 SID, uint8  *RequestData, uint16 DataSize, uint8 ReqType, uint8 DcmRxPduId, uint8  *ErrorCode);
Dcm_ReturnReadMemoryType Dcm_ReadMemory(uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8  *MemoryData);
Dcm_ReturnWriteMemoryType Dcm_WriteMemory(uint8 MemoryIdentifier, uint32 MemoryAddress, uint32 MemorySize, uint8  *MemoryData);
Std_ReturnType DLT_ReadData_E013(Dcm_OpStatusType OpStatus, uint8  *Data);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID01(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID02(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID03(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID04(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID07(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID08(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TID0A(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TIDA0(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID01_TIDA1(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID01(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID02(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID03(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID04(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID07(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TID08(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TIDC0(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TIDC1(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID02_TIDC2(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID21_TID81(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID41_TIDD0(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMID42_TIDDA(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA2_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA2_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA3_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA3_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA4_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA4_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA5_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_GetDTRValue_OBDMIDA5_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType DCM_MANU_CompareKey_SecLevel_2(uint8  *Key, Dcm_OpStatusType OpStatus);
Std_ReturnType DCM_MANU_GetSeed_SecLevel_2(uint8  *SecurityAccessDataRecord, Dcm_OpStatusType OpStatus, uint8  *pau8Seed, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CheckADCCondition(uint8 SrvType, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_CheckVehicleCondition(Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType DCM_MANU_ManufacturerIndication(uint8 SID, uint8  *RequestData, uint16 DataSize, uint8 ReqType, uint8 DcmRxPduId, uint8  *ErrorCode);
Std_ReturnType DCM_MANU_ManufSupplIndication(uint8 SID, uint8  *RequestData, uint16 DataSize, uint8 ReqType, uint8 DcmRxPduId, uint8  *ErrorCode);


#endif /* DCM_MANU_H */

/*-------------------------------- end of file -------------------------------*/
