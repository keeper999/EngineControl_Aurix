#if !defined(RTE_ACCMD_H)
#define RTE_ACCMD_H

/**
 * \file
 *
 * \brief AUTOSAR Rte
 *
 * This file contains the implementation of the AUTOSAR
 * module Rte.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /*
  * This file contains Rte component declarations for component type ACCMD
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.57
  * on Mon Nov 03 12:24:27 CET 2014. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <Rte_Intern_Application_Core1.h>
#include <Rte_Main.h>         /* RTE main header file */
#include <Rte_ACCMD_Type.h> /* RTE application types header file */
#include <Rte_Hook.h> /* RTE VFB trace hooks header file */

/*==================[macros]=================================================*/

#if (!defined RTE_CORE) /* if included by software component */

#if (!defined RTE_APPLICATION_HEADER_FILE_H) /* prevent double inclusion */
#define RTE_APPLICATION_HEADER_FILE_H
#else
#error Multiple application header files included.
#endif /* if !defined( RTE_APPLICATION_HEADER_FILE_H ) */

#endif

/*------------------[API mapping]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV)
#define Rte_IrvRead_RE_ACCmd_003_DRE_ACCmd_spdVeh_irv() (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_spdVeh_irv)

#define Rte_IrvRead_RE_ACCmd_003_DRE_ACCmd_bInhTDCClc_irv() (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhTDCClc_irv)

#define Rte_IrvWrite_RE_ACCmd_003_DRE_ACCmd_bInhTakeOff_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhTakeOff_irv = (data))

#define Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(data) Rte_Read_ACCMD_R_TqSys_nTarIdl_TqSys_nTarIdl(data)

#define Rte_IsUpdated_R_TqSys_nTarIdl_TqSys_nTarIdl() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1928.isUpdated)

#define Rte_Read_R_AC_bACClu_AC_bACClu(data) Rte_Read_ACCMD_R_AC_bACClu_AC_bACClu(data)

#define Rte_IsUpdated_R_AC_bACClu_AC_bACClu() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1922.isUpdated)

#define Rte_Read_R_Ext_tiTDC_Ext_tiTDC(data) Rte_Read_ACCMD_R_Ext_tiTDC_Ext_tiTDC(data)

#define Rte_IsUpdated_R_Ext_tiTDC_Ext_tiTDC() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1923.isUpdated)

#define Rte_Read_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd(data) Rte_Read_ACCMD_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd(data)

#define Rte_IsUpdated_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1942.isUpdated)

#define Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(data) Rte_Read_ACCMD_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(data)

#define Rte_IsUpdated_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1929.isUpdated)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV)
#define Rte_Write_P_ACCmd_nAntiStall_ACCmd_nAntiStall(data) Rte_Write_ACCMD_P_ACCmd_nAntiStall_ACCmd_nAntiStall(data)

#define Rte_Write_P_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(data) Rte_Write_ACCMD_P_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(data)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV)
#define Rte_Read_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw(data) Rte_Read_ACCMD_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw(data)

#define Rte_IsUpdated_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1930.isUpdated)

#define Rte_Read_R_AccP_rAccP_AccP_rAccP(data) Rte_Read_ACCMD_R_AccP_rAccP_AccP_rAccP(data)

#define Rte_IsUpdated_R_AccP_rAccP_AccP_rAccP() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1916.isUpdated)

#define Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(data) Rte_Read_ACCMD_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(data)

#define Rte_IsUpdated_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1927.isUpdated)

#define Rte_Read_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(data) Rte_Read_ACCMD_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt(data)

#define Rte_IsUpdated_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1934.isUpdated)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV)
#define Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_spdVeh_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_spdVeh_irv = (data))

#define Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhACOn_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhACOn_irv = (data))

#define Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhTakeOff_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhTakeOff_irv = (data))

#define Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhTDCClc_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhTDCClc_irv = (data))

#define Rte_IrvWrite_RE_ACCmd_001_MSE_ACCmd_bInhAst_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhAst_irv = (data))

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV)
#define Rte_Write_P_ACCmd_stReq_ACCmd_stReq(data) (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_948.value = (data), RTE_E_OK)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV)
#define Rte_IrvWrite_RE_ACCmd_004_TEV_ACCmd_bInhAst_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhAst_irv = (data))

#define Rte_IrvWrite_RE_ACCmd_004_TEV_ACCmd_bInhACOn_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhACOn_irv = (data))

#define Rte_Read_R_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn(data) Rte_Read_ACCMD_R_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn(data)

#define Rte_IsUpdated_R_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1936.isUpdated)

#define Rte_Call_R_FRM_bInhPwrPresInvld_GetFunctionPermission(Permission) (RE_FRM_bInhPwrPresInvld_GetFunctionPermission(Permission), RTE_E_OK)

#define Rte_Call_R_FRM_bInhACOn_GetFunctionPermission(Permission) (RE_FRM_bInhACOn_GetFunctionPermission(Permission), RTE_E_OK)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE)
#define Rte_Read_R_Ext_tAir_Ext_tAir(data) Rte_Read_ACCMD_R_Ext_tAir_Ext_tAir(data)

#define Rte_IsUpdated_R_Ext_tAir_Ext_tAir() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1935.isUpdated)

#define Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(data) Rte_Read_ACCMD_R_CoPTSt_stEng_CoPTSt_stEng(data)

#define Rte_IsUpdated_R_CoPTSt_stEng_CoPTSt_stEng() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1919.isUpdated)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE) || !defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV)
#define Rte_IrvRead_RE_ACCmd_002_TEV_ACCmd_bInhACOn_irv() (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhACOn_irv)

#define Rte_IrvRead_RE_ACCmd_002_TEV_ACCmd_bInhAst_irv() (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhAst_irv)

#define Rte_IrvRead_RE_ACCmd_002_TEV_ACCmd_bInhTakeOff_irv() (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhTakeOff_irv)

#define Rte_IrvWrite_RE_ACCmd_002_TEV_ACCmd_bInhTDCClc_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_bInhTDCClc_irv = (data))

#define Rte_IrvWrite_RE_ACCmd_002_TEV_ACCmd_spdVeh_irv(data) (Rte_SwcBDS_Application_Core1.Rte_Irv_inst_TopLevelComposition_ACCMD_ACCmd_spdVeh_irv = (data))

#define Rte_Read_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi(data) Rte_Read_ACCMD_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi(data)

#define Rte_IsUpdated_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1939.isUpdated)

#define Rte_Read_R_Eng_nCkFil_Eng_nCkFil(data) Rte_Read_ACCMD_R_Eng_nCkFil_Eng_nCkFil(data)

#define Rte_IsUpdated_R_Eng_nCkFil_Eng_nCkFil() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1920.isUpdated)

#define Rte_Read_R_CoPt_bFrzAC_CoPt_bFrzAC(data) Rte_Read_ACCMD_R_CoPt_bFrzAC_CoPt_bFrzAC(data)

#define Rte_IsUpdated_R_CoPt_bFrzAC_CoPt_bFrzAC() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1918.isUpdated)

#define Rte_Read_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim(data) Rte_Read_ACCMD_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim(data)

#define Rte_IsUpdated_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1921.isUpdated)

#define Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(data) Rte_Read_ACCMD_R_Ext_stGBxCf_Ext_stGBxCf(data)

#define Rte_IsUpdated_R_Ext_stGBxCf_Ext_stGBxCf() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1924.isUpdated)

#define Rte_Read_R_Veh_spdVeh_Veh_spdVeh(data) Rte_Read_ACCMD_R_Veh_spdVeh_Veh_spdVeh(data)

#define Rte_IsUpdated_R_Veh_spdVeh_Veh_spdVeh() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1931.isUpdated)

#define Rte_Read_R_TqSys_bInhBrio_TqSys_bInhBrio(data) Rte_Read_ACCMD_R_TqSys_bInhBrio_TqSys_bInhBrio(data)

#define Rte_IsUpdated_R_TqSys_bInhBrio_TqSys_bInhBrio() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1933.isUpdated)

#define Rte_Read_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(data) Rte_Read_ACCMD_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall(data)

#define Rte_IsUpdated_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1940.isUpdated)

#define Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(data) Rte_Read_ACCMD_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(data)

#define Rte_IsUpdated_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1937.isUpdated)

#define Rte_Read_R_ACCmd_nAntiStall_ACCmd_nAntiStall(data) Rte_Read_ACCMD_R_ACCmd_nAntiStall_ACCmd_nAntiStall(data)

#define Rte_IsUpdated_R_ACCmd_nAntiStall_ACCmd_nAntiStall() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1941.isUpdated)

#define Rte_Read_R_TqEM_bFrzACComp_TqEM_bFrzACComp(data) Rte_Read_ACCMD_R_TqEM_bFrzACComp_TqEM_bFrzACComp(data)

#define Rte_IsUpdated_R_TqEM_bFrzACComp_TqEM_bFrzACComp() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1926.isUpdated)

#define Rte_Read_R_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq(data) Rte_Read_ACCMD_R_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq(data)

#define Rte_IsUpdated_R_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1925.isUpdated)

#define Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(data) Rte_Read_ACCMD_R_Ext_bCluPedPrss_Ext_bCluPedPrss(data)

#define Rte_IsUpdated_R_Ext_bCluPedPrss_Ext_bCluPedPrss() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1932.isUpdated)

#define Rte_Read_R_Cha_stTqReq_Cha_stTqReq(data) Rte_Read_ACCMD_R_Cha_stTqReq_Cha_stTqReq(data)

#define Rte_IsUpdated_R_Cha_stTqReq_Cha_stTqReq() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1917.isUpdated)

#define Rte_Read_R_TqRes_bFrzAC_TqRes_bFrzAC(data) Rte_Read_ACCMD_R_TqRes_bFrzAC_TqRes_bFrzAC(data)

#define Rte_IsUpdated_R_TqRes_bFrzAC_TqRes_bFrzAC() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1938.isUpdated)

#define Rte_Call_R_FRM_bInhRvFrzESP_GetFunctionPermission(Permission) (RE_FRM_bInhRvFrzESP_GetFunctionPermission(Permission), RTE_E_OK)

#define Rte_Call_R_FRM_bInhBrioVst_GetFunctionPermission(Permission) (RE_FRM_bInhBrioVst_GetFunctionPermission(Permission), RTE_E_OK)

#define Rte_Call_R_FRM_bInhACRlsTakeOff_GetFunctionPermission(Permission) (RE_FRM_bInhACRlsTakeOff_GetFunctionPermission(Permission), RTE_E_OK)

#endif

#endif

/*------------------[port handle API mapping]--------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*------------------[application errors]-------------------------------------*/

/*------------------[init values]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#define Rte_InitValue_P_ACCmd_stReq_ACCmd_stReq 1U
#define Rte_InitValue_P_ACCmd_nAntiStall_ACCmd_nAntiStall 0U
#define Rte_InitValue_P_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall 0U
#define Rte_InitValue_R_AccP_rAccP_AccP_rAccP 0U
#define Rte_InitValue_R_Cha_stTqReq_Cha_stTqReq 0U
#define Rte_InitValue_R_CoPt_bFrzAC_CoPt_bFrzAC 0U
#define Rte_InitValue_R_CoPTSt_stEng_CoPTSt_stEng 1U
#define Rte_InitValue_R_Eng_nCkFil_Eng_nCkFil 0U
#define Rte_InitValue_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim 32000
#define Rte_InitValue_R_AC_bACClu_AC_bACClu 0U
#define Rte_InitValue_R_Ext_tiTDC_Ext_tiTDC 100U
#define Rte_InitValue_R_Ext_stGBxCf_Ext_stGBxCf 0U
#define Rte_InitValue_R_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq 0U
#define Rte_InitValue_R_TqEM_bFrzACComp_TqEM_bFrzACComp 0U
#define Rte_InitValue_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl 1U
#define Rte_InitValue_R_TqSys_nTarIdl_TqSys_nTarIdl 0U
#define Rte_InitValue_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd 0
#define Rte_InitValue_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw 0U
#define Rte_InitValue_R_Veh_spdVeh_Veh_spdVeh 0U
#define Rte_InitValue_R_Ext_bCluPedPrss_Ext_bCluPedPrss 0U
#define Rte_InitValue_R_TqSys_bInhBrio_TqSys_bInhBrio 0U
#define Rte_InitValue_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt 0
#define Rte_InitValue_R_Ext_tAir_Ext_tAir 20
#define Rte_InitValue_R_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn 0U
#define Rte_InitValue_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv 0
#define Rte_InitValue_R_TqRes_bFrzAC_TqRes_bFrzAC 0U
#define Rte_InitValue_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi 0U
#define Rte_InitValue_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall 0U
#define Rte_InitValue_R_ACCmd_nAntiStall_ACCmd_nAntiStall 0U
#define Rte_InitValue_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd 0U

#endif

/*==================[type definitions]=======================================*/

/*------------------[instance handle type]-----------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_ACCMD, RTE_CONST, RTE_CONST) Rte_Instance;
#endif

/*------------------[port handle types]--------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
#endif

/*------------------[per instance memory types]------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*==================[external function declarations]=========================*/

/*------------------[declaration of runnable entities]-----------------------*/

#define RTE_START_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

extern FUNC(void, RTE_APPL_CODE) RE_ACCmd_003_DRE(void);

extern FUNC(void, RTE_APPL_CODE) RE_ACCmd_001_MSE(void);

extern FUNC(void, RTE_APPL_CODE) RE_ACCmd_004_TEV(void);

extern FUNC(void, RTE_APPL_CODE) RE_ACCmd_002_TEV(void);

#define RTE_STOP_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by Rte]--------------*/

#define RTE_START_SEC_APPLICATION_CORE1_CODE
#include "MemMap.h"
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV)) || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqSys_nTarIdl_TqSys_nTarIdl (P2VAR(DT_TqSys_nTarIdl, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_AC_bACClu_AC_bACClu (P2VAR(DT_AC_bACClu, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Ext_tiTDC_Ext_tiTDC (P2VAR(DT_Ext_tiTDC, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqSys_EveSync_ACCmd_TqSys_EveSync_ACCmd (P2VAR(DT_TqSys_EveSync_ACCmd, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd (P2VAR(DT_TreatTDC_nCkGrd, AUTOMATIC, RTE_APPL_DATA) data);

#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ACCMD_P_ACCmd_nAntiStall_ACCmd_nAntiStall (DT_ACCmd_nAntiStall data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ACCMD_P_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall (DT_ACCmd_bInhAntiStall data);

#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TreatTenms_nCkRaw_TreatTenms_nCkRaw (P2VAR(DT_TreatTenms_nCkRaw, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_AccP_rAccP_AccP_rAccP (P2VAR(DT_AccP_rAccP, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl (P2VAR(DT_TqSys_bEngNOnIdl, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_CoPt_noEgdGearCordIt_CoPt_noEgdGearCordIt (P2VAR(DT_CoPt_noEgdGearCordIt, AUTOMATIC, RTE_APPL_DATA) data);

#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV)) || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV))
#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV))
#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE)) || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_002_TEV))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn (P2VAR(DT_TqCmp_bACOffDftSelOn, AUTOMATIC, RTE_APPL_DATA) data);

#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Ext_tAir_Ext_tAir (P2VAR(DT_Ext_tAir, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_CoPTSt_stEng_CoPTSt_stEng (P2VAR(DT_CoPTSt_stEng, AUTOMATIC, RTE_APPL_DATA) data);

#endif
#if (!defined(RTE_RUNNABLEAPI_RE_ACCmd_003_DRE))  || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_001_MSE)) || (!defined(RTE_RUNNABLEAPI_RE_ACCmd_004_TEV))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqSys_bInhACBrkAsi_TqSys_bInhACBrkAsi (P2VAR(DT_TqSys_bInhACBrkAsi, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Eng_nCkFil_Eng_nCkFil (P2VAR(DT_Eng_nCkFil, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_CoPt_bFrzAC_CoPt_bFrzAC (P2VAR(DT_CoPt_bFrzAC, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_EngLim_tqCkEfcACCmprLim_EngLim_tqCkEfcACCmprLim (P2VAR(DT_EngLim_tqCkEfcACCmprLim, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Ext_stGBxCf_Ext_stGBxCf (P2VAR(DT_Ext_stGBxCf, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Veh_spdVeh_Veh_spdVeh (P2VAR(DT_Veh_spdVeh, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqSys_bInhBrio_TqSys_bInhBrio (P2VAR(DT_TqSys_bInhBrio, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_ACCmd_bInhAntiStall_ACCmd_bInhAntiStall (P2VAR(DT_ACCmd_bInhAntiStall, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv (P2VAR(DT_TqLimEM_tqLimEMTrv, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_ACCmd_nAntiStall_ACCmd_nAntiStall (P2VAR(DT_ACCmd_nAntiStall, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqEM_bFrzACComp_TqEM_bFrzACComp (P2VAR(DT_TqEM_bFrzACComp, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_ThMgt_bACCmprOffReq_ThMgt_bACCmprOffReq (P2VAR(DT_ThMgt_bACCmprOffReq, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Ext_bCluPedPrss_Ext_bCluPedPrss (P2VAR(DT_Ext_bCluPedPrss, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_Cha_stTqReq_Cha_stTqReq (P2VAR(DT_Cha_stTqReq, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ACCMD_R_TqRes_bFrzAC_TqRes_bFrzAC (P2VAR(DT_TqRes_bFrzAC, AUTOMATIC, RTE_APPL_DATA) data);

#endif

#define RTE_STOP_SEC_APPLICATION_CORE1_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by other Appl]--------*/

#define RTE_START_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

#if (!defined RTE_CORE) /* if included by software component */

extern FUNC(void, RTE_APPL_CODE) RE_FRM_bInhPwrPresInvld_GetFunctionPermission (P2VAR(DT_Permission, AUTOMATIC, RTE_APPL_DATA) Permission);
extern FUNC(void, RTE_APPL_CODE) RE_FRM_bInhACOn_GetFunctionPermission (P2VAR(DT_Permission, AUTOMATIC, RTE_APPL_DATA) Permission);
extern FUNC(void, RTE_APPL_CODE) RE_FRM_bInhRvFrzESP_GetFunctionPermission (P2VAR(DT_Permission, AUTOMATIC, RTE_APPL_DATA) Permission);
extern FUNC(void, RTE_APPL_CODE) RE_FRM_bInhBrioVst_GetFunctionPermission (P2VAR(DT_Permission, AUTOMATIC, RTE_APPL_DATA) Permission);
extern FUNC(void, RTE_APPL_CODE) RE_FRM_bInhACRlsTakeOff_GetFunctionPermission (P2VAR(DT_Permission, AUTOMATIC, RTE_APPL_DATA) Permission);

#endif /* (!defined RTE_CORE) */

#define RTE_STOP_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*------------------[instance handle declaration]----------------------------*/
#define RTE_START_SEC_APPLICATION_CORE1_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2CONST(Rte_CDS_ACCMD, RTE_CONST, RTE_CONST) Rte_Inst_ACCMD;

#define RTE_STOP_SEC_APPLICATION_CORE1_CONST_UNSPECIFIED
#include "MemMap.h"

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */
/** @} doxygen end group definition */
#endif /* !defined(RTE_ACCMD_H) */
/*==================[end of file]============================================*/
