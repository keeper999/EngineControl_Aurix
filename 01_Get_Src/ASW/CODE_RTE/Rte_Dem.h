#if !defined(RTE_DEM_H)
#define RTE_DEM_H

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
  * This file contains Rte component declarations for component type Dem
  *
  * This file has been automatically generated by
  * EB tresos AutoCore Rte Generator Version 6.1.57
  * on Mon Nov 03 12:24:33 CET 2014. !!!IGNORE-LINE!!!
  */

 /* \addtogroup Rte Runtime Environment
  * @{ */

/*==================[inclusions]=============================================*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <Rte_Intern_Application_Core1.h>
#include <Rte_Main.h>         /* RTE main header file */
#include <Rte_Dem_Type.h> /* RTE application types header file */
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

#endif

/*------------------[port handle API mapping]--------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*------------------[application errors]-------------------------------------*/

#define RTE_E_DiagnosticMonitor_E_NOT_OK 1U

/*------------------[init values]--------------------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */

#endif

/*==================[type definitions]=======================================*/

/*------------------[instance handle type]-----------------------------------*/

#if (!defined RTE_CORE) /* if included by software component */
typedef CONSTP2CONST(Rte_CDS_Dem, RTE_CONST, RTE_CONST) Rte_Instance;
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

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CatMon_ORng_Cat_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CatMon_ORng_Cat_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CatMon_ORng_CatApv_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CatMon_ORng_CatApv_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAMgt_ObsAdp_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAMgt_ObsAdp_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffEGRVlvLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffEGRVlvLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfs1Lim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfs1Lim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfs2Lim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfs2Lim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfs3Lim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfs3Lim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfsLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpArEffThrOfsLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpClsExOfsLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpClsExOfsLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpInjOfsLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpInjOfsLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpIvsInjConLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpIvsInjConLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpOpInOfsLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpOpInOfsLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpSlopInjConLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_AFAT_AFA_AdpSlopInjConLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_Blt_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_Blt_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_CutReq_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_CutReq_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGcClu_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGcClu_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGcNeut_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGcNeut_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGearEnaClu_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGearEnaClu_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGearNeut_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGearNeut_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGcMinClu_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGcMinClu_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGearMinClu_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_ORngGearMinClu_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_LgEngRStrtInh_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPtUH_LgEngRStrtInh_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_DfwCtl_ProtAdp_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_DfwCtl_ProtAdp_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftOnOffHi_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftOnOffHi_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftOnOffLo_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftOnOffLo_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftOscCfm_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftOscCfm_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegHi_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegHi_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegHiCfm_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegHiCfm_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegLo_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegLo_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegLoCfm_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_DftRegLoCfm_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_PresMesFrz_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_PresMesFrz_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_PresToHi_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_PresToHi_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_PresToLo_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_OilSys_PresToLo_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__iBattMes_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__iBattMes_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__resBattIt_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__resBattIt_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__tBattMes_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__tBattMes_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattMes_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattMes_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattRstrt_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattRstrt_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ElProdMgt_CorLoss_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ElProdMgt_CorLoss_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoOptmEl_TqAlt_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoOptmEl_TqAlt_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattOc_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattOc_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattStrt_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattStrt_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ElProdMgt_CorSpCur_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ElProdMgt_CorSpCur_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__iBattMaxCkg_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__iBattMaxCkg_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__rBattSoC_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__rBattSoC_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattMinCkg_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_BatMgt__uBattMinCkg_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_UCE_RCDLineScg_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_UCE_RCDLineScg_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_UCE_MainWkuDisrd_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_UCE_MainWkuDisrd_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_UCE_MainWkuIncst_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_UCE_MainWkuIncst_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaCmd_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaCmd_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaElCmd_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaElCmd_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StuckMec_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StuckMec_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaAcvThd1_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaAcvThd1_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaAcvThd2_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaAcvThd2_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaCmdInfo_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_StaStrtMgt_StaCmdInfo_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoSTT_ORngCutOffReq_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoSTT_ORngCutOffReq_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoSTT_ORngStopReq_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoSTT_ORngStopReq_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPTSt_ORngMplReq_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPTSt_ORngMplReq_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPTSt_SftyORngAMT_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPTSt_SftyORngAMT_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPTSt_SftyORngAT_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_CoPTSt_SftyORngAT_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_AntiBoil_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_AntiBoil_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_CoSysDfct_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_CoSysDfct_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_FSFBlockCls_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_FSFBlockCls_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_FSFBlockOp_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_FSFBlockOp_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoBlock_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoBlock_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoOverEstim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoOverEstim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoSlowRise_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoSlowRise_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoUndEstim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoUndEstim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoWarn_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_TCoWarn_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_ThermoStuckCls_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_ThermoStuckCls_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_ThermoStuckOp_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_ThMgt_ThermoStuckOp_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngHiDragRed_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngHiDragRed_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngHiNeut_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngHiNeut_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngLoDragRed_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngLoDragRed_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngLoNeut_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqAdp_ORngLoNeut_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqCmp_tqAltRv_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TqCmp_tqAltRv_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TrbAct_ArDeltaCorLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_TrbAct_ArDeltaCorLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_RatConvTraClc_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_RatConvTraClc_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_SpdVehClc_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_SpdVehClc_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSLim_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSLim_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSLimBody_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSLimBody_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSMax_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSMax_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSMaxp_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSMaxp_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSReg_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSReg_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSRegBody_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSRegBody_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSRegVeh_SetEventStatus(Dem_EventStatusType EventStatus);

extern FUNC(Std_ReturnType, RTE_APPL_CODE) RE_VSCtl_VSRegVeh_GetEventStatus(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA) EventStatusExtended);

#define RTE_STOP_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by Rte]--------------*/

#define RTE_START_SEC_APPLICATION_CORE1_CODE
#include "MemMap.h"

#define RTE_STOP_SEC_APPLICATION_CORE1_CODE
#include "MemMap.h"

/*--------------[declaration of API functions provided by other Appl]--------*/

#define RTE_START_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

#if (!defined RTE_CORE) /* if included by software component */

#endif /* (!defined RTE_CORE) */

#define RTE_STOP_SEC_APPLICATION_CORE1_APPL_CODE
#include "MemMap.h"

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*------------------[instance handle declaration]----------------------------*/
#define RTE_START_SEC_APPLICATION_CORE1_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONSTP2CONST(Rte_CDS_Dem, RTE_CONST, RTE_CONST) Rte_Inst_Dem;

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
#endif /* !defined(RTE_DEM_H) */
/*==================[end of file]============================================*/
