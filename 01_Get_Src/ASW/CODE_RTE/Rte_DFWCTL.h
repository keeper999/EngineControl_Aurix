/*This file has been automatically modified by "modif_Rte_module v1.0"*/
#if !defined(RTE_DFWCTL_H)
#define RTE_DFWCTL_H

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
  * This file contains Rte component declarations for component type DFWCTL
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.57
  * on Mon Nov 03 12:24:29 CET 2014. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <Rte_Intern_Application_Core1.h>
#include <Rte_Main.h>         /* RTE main header file */
#include <Rte_DFWCTL_Type.h> /* RTE application types header file */
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
#if !defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramRead_1) || !defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramReset_1)
#define Rte_Write_P_DfwCtl_noOverOscDetProtAcv_DfwCtl_noOverOscDetProtAcv(data) (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_892.value = (data), RTE_E_OK)

#define Rte_Write_P_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl(data) Rte_Write_DFWCTL_P_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl(data)

#define Rte_Write_P_DfwCtl_noProtAdp_DfwCtl_noProtAdp(data) (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1272.value = (data), RTE_E_OK)

#define Rte_Write_P_DfwCtl_bInhInjProtDfw_DfwCtl_bInhInjProtDfw(data) (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_1665.value = (data), RTE_E_OK)

#endif
#if !defined(RTE_RUNNABLEAPI_RE_DfwCtl_001_MSE) || !defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramRead_1) || !defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramReset_1)
#define Rte_Read_R_CoSync_bDetNNull_CoSync_bDetNNull(data) Rte_Read_DFWCTL_R_CoSync_bDetNNull_CoSync_bDetNNull(data)

#define Rte_IsUpdated_R_CoSync_bDetNNull_CoSync_bDetNNull() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2753.isUpdated)

#define Rte_Read_R_Ext_tCoMes_Ext_tCoMes(data) Rte_Read_DFWCTL_R_Ext_tCoMes_Ext_tCoMes(data)

#define Rte_IsUpdated_R_Ext_tCoMes_Ext_tCoMes() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2758.isUpdated)

#define Rte_Read_R_Veh_spdVeh_Veh_spdVeh(data) Rte_Read_DFWCTL_R_Veh_spdVeh_Veh_spdVeh(data)

#define Rte_IsUpdated_R_Veh_spdVeh_Veh_spdVeh() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2761.isUpdated)

#define Rte_Read_R_Ext_nEng_Ext_nEng(data) Rte_Read_DFWCTL_R_Ext_nEng_Ext_nEng(data)

#define Rte_IsUpdated_R_Ext_nEng_Ext_nEng() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2756.isUpdated)

#define Rte_Read_R_PredEs_bVldFastN_PredEs_bVldFastN(data) Rte_Read_DFWCTL_R_PredEs_bVldFastN_PredEs_bVldFastN(data)

#define Rte_IsUpdated_R_PredEs_bVldFastN_PredEs_bVldFastN() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2759.isUpdated)

#define Rte_Read_R_Ext_bDirRotCk_Ext_bDirRotCk(data) Rte_Read_DFWCTL_R_Ext_bDirRotCk_Ext_bDirRotCk(data)

#define Rte_IsUpdated_R_Ext_bDirRotCk_Ext_bDirRotCk() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2755.isUpdated)

#define Rte_Read_R_Ext_bCluPedPrss_Ext_bCluPedPrss(data) Rte_Read_DFWCTL_R_Ext_bCluPedPrss_Ext_bCluPedPrss(data)

#define Rte_IsUpdated_R_Ext_bCluPedPrss_Ext_bCluPedPrss() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2754.isUpdated)

#define Rte_Read_R_PredEs_nFast_PredEs_nFast(data) Rte_Read_DFWCTL_R_PredEs_nFast_PredEs_nFast(data)

#define Rte_IsUpdated_R_PredEs_nFast_PredEs_nFast() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2760.isUpdated)

#define Rte_Read_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(data) Rte_Read_DFWCTL_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq(data)

#define Rte_IsUpdated_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2757.isUpdated)

#define Rte_Read_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(data) Rte_Read_DFWCTL_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq(data)

#define Rte_IsUpdated_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2752.isUpdated)

#define Rte_Read_R_Afts_bRstDfwChg_Afts_bRstDfwChg(data) Rte_Read_DFWCTL_R_Afts_bRstDfwChg_Afts_bRstDfwChg(data)

#define Rte_IsUpdated_R_Afts_bRstDfwChg_Afts_bRstDfwChg() (Rte_SwcBDS_Application_Core1.Rte_ReceiveBuffer_2751.isUpdated)

#define Rte_Call_R_DfwCtl_ProtAdp_SetEventStatus RE_DfwCtl_ProtAdp_SetEventStatus

#define Rte_Call_R_FRM_bInhOscDet_GetFunctionPermission(Permission) (RE_FRM_bInhOscDet_GetFunctionPermission(Permission), RTE_E_OK)

#endif

#endif

/*------------------[port handle API mapping]--------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*------------------[application errors]-------------------------------------*/

#define RTE_E_DiagnosticMonitor_E_NOT_OK 1U

/*------------------[init values]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#define Rte_InitValue_P_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl 0U
#define Rte_InitValue_P_DfwCtl_bInhInjProtDfw_DfwCtl_bInhInjProtDfw 0U
#define Rte_InitValue_P_DfwCtl_noOverOscDetProtAcv_DfwCtl_noOverOscDetProtAcv 0U
#define Rte_InitValue_P_DfwCtl_noProtAdp_DfwCtl_noProtAdp 0U
#define Rte_InitValue_R_Afts_bRstDfwChg_Afts_bRstDfwChg 0U
#define Rte_InitValue_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq 0U
#define Rte_InitValue_R_CoSync_bDetNNull_CoSync_bDetNNull 0U
#define Rte_InitValue_R_Ext_bCluPedPrss_Ext_bCluPedPrss 0U
#define Rte_InitValue_R_Ext_bDirRotCk_Ext_bDirRotCk 0U
#define Rte_InitValue_R_Ext_nEng_Ext_nEng 0U
#define Rte_InitValue_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq 0U
#define Rte_InitValue_R_Ext_tCoMes_Ext_tCoMes 20
#define Rte_InitValue_R_PredEs_bVldFastN_PredEs_bVldFastN 0U
#define Rte_InitValue_R_PredEs_nFast_PredEs_nFast 0
#define Rte_InitValue_R_Veh_spdVeh_Veh_spdVeh 0U

#endif

/*==================[type definitions]=======================================*/

/*------------------[instance handle type]-----------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_DFWCTL, RTE_CONST, RTE_CONST) Rte_Instance;
#endif

/*------------------[port handle types]--------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
#endif

/*------------------[per instance memory types]------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*==================[external function declarations]=========================*/

/*------------------[declaration of runnable entities]-----------------------*/
#define RTE_PTR2ARRAYBASETYPE_PASSING

#define RTE_START_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

extern FUNC(void, RTE_APPL_CODE) RE_DfwCtl_002_TEV(void);

extern FUNC(void, RTE_APPL_CODE) RE_DfwCtl_001_MSE(void);

extern FUNC(void, RTE_APPL_CODE) DfwCtl_AftsNvramRead_1(P2VAR(UInt8, AUTOMATIC, RTE_APPL_DATA) DfwCtl_tabNVRAM_1);

extern FUNC(void, RTE_APPL_CODE) DfwCtl_AftsNvramReset_1(void);

#define RTE_STOP_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

#undef RTE_PTR2ARRAYBASETYPE_PASSING
/*--------------[declaration of API functions provided by Rte]--------------*/

#define RTE_START_SEC_APPLICATION_CORE1_CODE
#include "MemMap.h"
#if (!defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramRead_1))  || (!defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramReset_1))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DFWCTL_P_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl (DT_DfwCtl_bAcvLimTqIdl data);

#endif
#if (!defined(RTE_RUNNABLEAPI_RE_DfwCtl_001_MSE))  || (!defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramRead_1)) || (!defined(RTE_RUNNABLEAPI_DfwCtl_AftsNvramReset_1))
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_CoSync_bDetNNull_CoSync_bDetNNull (P2VAR(DT_CoSync_bDetNNull, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Ext_tCoMes_Ext_tCoMes (P2VAR(DT_Ext_tCoMes, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Veh_spdVeh_Veh_spdVeh (P2VAR(DT_Veh_spdVeh, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Ext_nEng_Ext_nEng (P2VAR(DT_Ext_nEng, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_PredEs_bVldFastN_PredEs_bVldFastN (P2VAR(DT_PredEs_bVldFastN, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Ext_bDirRotCk_Ext_bDirRotCk (P2VAR(DT_Ext_bDirRotCk, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Ext_bCluPedPrss_Ext_bCluPedPrss (P2VAR(DT_Ext_bCluPedPrss, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_PredEs_nFast_PredEs_nFast (P2VAR(DT_PredEs_nFast, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Ext_rCluPHiFreq_Ext_rCluPHiFreq (P2VAR(DT_Ext_rCluPHiFreq, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_CoStrtRStrt_stEngStrtReq_CoStrtRStrt_stEngStrtReq (P2VAR(DT_CoStrtRStrt_stEngStrtReq, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DFWCTL_R_Afts_bRstDfwChg_Afts_bRstDfwChg (P2VAR(DT_Afts_bRstDfwChg, AUTOMATIC, RTE_APPL_DATA) data);

#endif

#define RTE_STOP_SEC_APPLICATION_CORE1_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by other Appl]--------*/

#define RTE_START_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

#if (!defined RTE_CORE) /* if included by software component */

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_DfwCtl_ProtAdp_SetEventStatus (Dem_EventStatusType EventStatus);
extern FUNC(void, RTE_APPL_CODE) RE_FRM_bInhOscDet_GetFunctionPermission (P2VAR(DT_Permission, AUTOMATIC, RTE_APPL_DATA) Permission);

#endif /* (!defined RTE_CORE) */

#define RTE_STOP_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*------------------[instance handle declaration]----------------------------*/
#define RTE_START_SEC_APPLICATION_CORE1_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2CONST(Rte_CDS_DFWCTL, RTE_CONST, RTE_CONST) Rte_Inst_DFWCTL;

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
#endif /* !defined(RTE_DFWCTL_H) */
/*==================[end of file]============================================*/
