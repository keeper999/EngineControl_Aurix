/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : DCM_MANU_Fix.h                                          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* !Reference   : V02NT1102667 / 5                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/DCM_MANU_Fix.h_v            $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   19 Jun 2014 $*/
/* $Author::   croche2                                $$Date::   19 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#ifndef DCM_MANU_FIX_H
#define DCM_MANU_FIX_H

#include "STD_TYPES.h"
#include "DCM_TYPES.h"
#include "Rte_Type.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/
#ifdef HEADER_H
typedef uint8 UInt8;

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/
Std_ReturnType Rte_Call_R_CoEmSTT_AftsNvramRead_1_op_CoEmSTT_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_CoEmSTT_AftsNvramWrite_1_op_CoEmSTT_AftsNvramWrite_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_CoStopStart_AftsNvramRead_1_CoStopStart_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_CoStopStart_AftsNvramWrite_1_CoStopStart_AftsNvramWrite_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_ProdElEng_AftsNvramRead_1_op_ProdElEng_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_ProdElEng_AftsNvramWrite_1_op_ProdElEng_AftsNvramWrite_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_StopStrtEm_AftsNvramRead_1_op_StopStrtEm_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_StopStrtEm_AftsNvramWrite_1_op_StopStrtEm_AftsNvramWrite_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_ThMgt_AftsNvramRead_1_op_ThMgt_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_ThMgt_AftsNvramWrite_1_op_ThMgt_AftsNvramWrite_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_ProdElEm_AftsNvramWrite_1_op_CoEmSTT_AftsNvramWrite_1(UInt8 *Data);
//Std_ReturnType Rte_Call_R_DidServices_TrbActSys_NVMID01_ReadData(UInt8 *Data);
//Std_ReturnType Rte_Call_R_DidServices_TrbActSys_NVMID01_WriteData(UInt8 *Data, uint16 dataLength, Dcm_NegativeResponseCodeType* ErrorCode);
//Std_ReturnType Rte_Call_R_RoutineServices_TAS_NVMID03_Start(UInt8 *InBuffer, UInt8 *OutBuffer, Dcm_NegativeResponseCodeType* ErrorCode);
//Std_ReturnType Rte_Call_R_RoutineServices_TAS_NVMID03_RequestResults(UInt8 *Data, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID01_ReadData(UInt8 *Data);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID01_WriteData(UInt8 *Data, uint16 dataLength, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID02_ReadData(UInt8 *Data);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID02_WriteData(UInt8 *Data, uint16 dataLength, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID05_ReadData(UInt8 *Data);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID05_WriteData(UInt8 *Data, uint16 dataLength, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID06_ReadData(UInt8 *Data);
Std_ReturnType Rte_Call_R_DidServices_MPM_NVMID06_WriteData(UInt8 *Data, uint16 dataLength, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_DfwCtl_AftsNvramRead_1_DfwCtl_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_ProdElEm_AftsNvramRead_1_op_ProdElEm_AftsNvramRead_1(UInt8 *Data);
Std_ReturnType Rte_Call_R_RoutineServices_AFMgtT_NVMID03_Start(UInt8 *InBuffer, UInt8 *OutBuffer, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID03_Start(UInt8 *InBuffer, UInt8 *OutBuffer, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID03_RequestResults(UInt8 *OutBuffer, Dcm_NegativeResponseCodeType*ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID04_Start(UInt8 *InBuffer, UInt8 *OutBuffer, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID04_RequestResults(UInt8 *OutBuffer, Dcm_NegativeResponseCodeType*ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID07_Start(UInt8 *InBuffer, UInt8 *OutBuffer, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID07_RequestResults(UInt8 *OutBuffer, Dcm_NegativeResponseCodeType*ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID08_Start(UInt8 *InBuffer, UInt8 *OutBuffer, Dcm_NegativeResponseCodeType* ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_MPM_NVMID08_RequestResults(UInt8 *OutBuffer, Dcm_NegativeResponseCodeType*ErrorCode);
Std_ReturnType Rte_Call_R_RoutineServices_AFMgtT_NVMID03_RequestResults(UInt8 *OutBuffer, Dcm_NegativeResponseCodeType*ErrorCode);

#else
#define RTE_PTR2ARRAYBASETYPE_PASSING
#endif

Std_ReturnType Dcm_SetProgConditions(Dcm_ProgConditionsType *ProgConditions);
Dcm_EcuStartModeType Dcm_GetProgConditions(Dcm_ProgConditionsType *ProgConditions);
Std_ReturnType DCM_MANU_ReqResRoutineDmnd
(
   uint8 *Srv_stRc_NameFunc,
   boolean *Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean *Srv_bRcReq_NameFunc,
   boolean *Srv_bRcStop_NameFunc,
   Dcm_NegativeResponseCodeType *u8ErrorCode,
   uint8 *u8RoutineStatus,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
);

Std_ReturnType DCM_MANU_StartRoutineDmnd
(
   uint8 *Srv_stRc_NameFunc,
   boolean *Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean *Srv_bRcReq_NameFunc,
   boolean *Srv_bRcStop_NameFunc,
   Dcm_NegativeResponseCodeType *u8ErrorCode,
   uint8 *u8RoutineStatus,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
);

Std_ReturnType DCM_MANU_StopRoutineDmnd
(
   uint8 *Srv_stRc_NameFunc,
   boolean *Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean *Srv_bRcReq_NameFunc,
   boolean *Srv_bRcStop_NameFunc,
   Dcm_NegativeResponseCodeType *u8ErrorCode,
   uint8 *u8RoutineStatus,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
);

void DCM_MANU_RoutineCntrlMachineTransition
(
   uint8 *Srv_stRc_NameFunc,
   boolean Srv_bRcStart_NameFunc,
   uint8 *Srv_stRcEnd_NameFunc,
   boolean *Srv_bRcCondOk_Namefunc,
   boolean Srv_bRcSho_NameFunc,
   boolean *Srv_bRcCom_NameFunc,
   boolean *Srv_bRcCdnOk_NameFunc,
   boolean *Srv_bRcCdnNok_NameFunc,
   boolean Srv_bRcReq_NameFunc,
   boolean Srv_bRcStop_NameFunc,
   void (*CALL_RcAcv_NameFunc)(void),
   void (*CALL_RcTestCond_NameFunc)( boolean *),
   void (*CALL_RcCdn_NameFunc)(boolean *, boolean *)
);

#endif /* DCM_MANU_FIX_H */

/*-------------------------------- end of file -------------------------------*/
