/*******************************************************************************
*                    Delphi Diesel Systems
*
*                    This document is the property of
*                    Delphi Diesel Systems
*                    It must not be copied (in whole or in part)
*                    or disclosed without prior written consent
*                    of the company. Any copies by any method
*                    must also include a copy of this legend.
********************************************************************************
* Task File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*------------------------------------------------------------------------------*
*
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TqDem.h
* Version int :/main/00PSASWC_E4/BR_00PSASWC_E41/1 Date: 17/7/2012 15 h 49 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.3 CDC 1.9
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 11/7/2012 15 h 45 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.3 CDC 1.9
* Version int :/main/00PSASWC_E4/4 Date: 10/3/2011 11 h 45 m User:esnault
*    TWK_model:NO_MODEL
*    comments :Update for TqDem 11.1
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 2/3/2011 11 h 46 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for TqDem 11.1
* Version int :/main/00PSASWC_E4/3 Date: 13/1/2011 15 h 49 m User:meme
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.0
*    comments :for TqDem 11.0
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 13/1/2011 15 h 17 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.0
* Version int :/main/00PSASWC_E4/2 Date: 13/1/2011 14 h 48 m User:meme
*    TWK_model:NO_MODEL
*    comments :For TqDem 11.0.. Spec CSMT_CGMT05_1397_v3_1
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 4/1/2011 12 h 21 m User:demezil
*    TWK_model:NO_MODEL
*    comments :For TqDem 11.0.
*    comments :Spec CSMT_CGMT05_1397_v3_1
* Version int :/main/00PSASWC_E4/1 Date: 1/9/2010 14 h 4 m User:esnault
*    TWK_model:NO_MODEL
*    comments :dev TqDem e6
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 31/8/2010 15 h 15 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev TqDem e6
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev in progress
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 20/7/2010 14 h 23 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for TqDem 3.0 euro6
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 20/7/2010 14 h 18 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for TqDem 3.0 euro6
* Version dev :\main\branch_salmane_tqdem_e6_dev\1 Date: 15/7/2010 15 h 27 m User:salmane
*    TWK_model:NO_MODEL
*    comments :TqDem1.0 Euro6
* Version int :/main/P2868/BR_06E4/4 Date: 23/11/2009 10 h 54 m User:langendorf
*    TWK_model:LDCR_Application_06E411_IMPL1
*    comments :TqDem_tqCkTakeOff1Reg and TqDem_tqCkTakeOff2Reg are 2-dimensions
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 10/11/2009 17 h 14 m User:moisan
*    TWK_model:
*    comments :TqDem_tqCkTakeOff1Reg and TqDem_tqCkTakeOff2Reg are 2-dimensions
* Version int :/main/P2868/BR_06E4/3 Date: 16/9/2009 10 h 44 m User:langendorf
*    TWK_model:LDCR_Application_06E410_IMPL1
*    comments :First issue for TqDem 2.0
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 28/8/2009 17 h 22 m User:moisan
*    TWK_model:LDCR_Application_06E410_IMPL1
*    comments :First issue for TqDem 2.0
* Version int :/main/P2868/BR_06E4/2 Date: 10/10/2008 10 h 49 m User:boucher
*    TWK_model:LDCR_Application_06E400_IMPL2
*    comments :Change library version required according to update of this one.
* Version dev :\main\branch_girodon_tqdem_1_dev\2 Date: 9/10/2008 9 h 25 m User:girodon
*    TWK_model:LDCR_Application_06E400_IMPL2
*    comments :Change library version required according to update of this one.
* Version int :/main/P2868/BR_06E4/1 Date: 9/9/2008 8 h 7 m User:boucher
*    TWK_model:LDCR_Application_06E400_IMPL1
*    comments :First implementation for "TqDem" PSA SSTG
* Version dev :\main\branch_girodon_tqdem_1_dev\1 Date: 5/9/2008 13 h 36 m User:girodon
*    TWK_model:LDCR_Application_06E400_IMPL1
*    comments :First implementation for "TqDem" PSA SSTG
*
*******************************************************************************/


#ifndef TQDEM_H
#define TQDEM_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#define RTE_PTR2ARRAYBASETYPE_PASSING

#include "Rte_TqDem.h"


/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define TQDEM_DDS_LIB_VERSION_REQ 250

/*******************************************************************************
*  SW-C Macro Definitions
*******************************************************************************/
#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

/******************************************************************************/

#define TQDEM_TQCKEFC_VECT_SIZE               2
#define TQDEM_2_SIZE     2

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

extern FUNC(void, AUTOMATIC) TQDEM_Coord_Lim_Em(SInt16 CoVSCtl_tqEfcReq_swc_in, /* BIN4 */
                                                   UInt8 Cha_stEPB_swc_in, /* BIN0 */
                                                   UInt8 Cha_stHillAsi_swc_in, /* BIN0 */
                                                   UInt8 CoPTSt_stEng_swc_in,
                                                   UInt8 CoPt_noEgdGearCord_swc_in,
                                                   UInt8 Ext_stGBxCf_swc_in,
                                                   UInt8 FRM_bInhTqLimEM_swc_in,
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEM_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQDEM_Coord_Xvv(SInt16 TqDem_tqCkEfc_swc_in, /* BIN4 */
                                           UInt16 TqDem_rAccPSptMod_swc_in, /* BIN7 */
                                           UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                           SInt16 VSCtl_tqCkEfcMinReq_swc_in, /* BIN4 */
                                           SInt16 VSCtl_tqCkEfcMaxReq_swc_in, /* BIN4 */
                                           UInt16 VSCtl_rAccPEngMax_swc_in, /* BIN7 */
                                           UInt16 VSCtl_rAccPEngMin_swc_in, /* BIN7 */
                                           UInt16 VSCtl_rAccPTraMax_swc_in, /* BIN7 */
                                           UInt16 VSCtl_rAccPTraMin_swc_in, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_tqEfcReq_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEng_swc_out, /* BIN7 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPTra_swc_out, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoVSCtl_stAccP_swc_out );

extern FUNC(void, AUTOMATIC) TQDEM_Dzone_Torque_Calc(SInt16 TqDem_tqCkEfcWoutAntiDB_swc_in, /* BIN4 */
                                                       UInt16 TqSys_nOfsTotTakeOff_swc_in, /* BIN2 */
                                                       UInt8 CoPTSt_stEng_swc_in,
                                                       UInt8 CoPt_noEgdGearCord_swc_in,
                                                       UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                                       UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                                       UInt8 FRM_bInhAntiDB_swc_in,
                                                       UInt8 TqAdp_bFrzAdpACOn_swc_in,
                                                       UInt8 TqAdp_bFrzAdpAltOn_swc_in,
                                                       UInt8 TqAdp_bFrzAdpCnvOn_swc_in,
                                                       UInt8 TqAdp_bFrzAdpStgPmpOn_swc_in,
                                                       SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                                       UInt8 TqSys_bAcvAntiStall_swc_in,
                                                       UInt8 TqSys_bEngNOnIdl_swc_in,
                                                       UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                                       SInt16 TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                                       UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                                       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) DZone_tqEfcDifLrnOut_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQDEM_Ivc_Content(SInt16 DZone_tqEfcDifLrnOut_swc_in, /* BIN4 */
                                           UInt8 TqDem_bAcvNRegTakeOff_swc_in,
                                           CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  TqDem_tqEfcNRegTakeOffEco_swc_in, /* tab[] BIN4 */
                                           CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  TqDem_tqEfcNRegTakeOffNorm_swc_in, /* tab[] BIN4 */
                                           UInt16 TqDem_rDrivTakeOff_swc_in, /* BIN10 */
                                           UInt8 TqDem_idxMapRvsDrv_swc_in, /* BIN0 */
                                           UInt8 TqDem_idxMapTranDrvFirst_swc_in, /* BIN0 */
                                           UInt8 TqDem_idxMapTranDrvSec_swc_in, /* BIN0 */
                                           UInt16 TqDem_rTranDrv_swc_in, /* BIN10 */
                                           UInt16 TqDem_rTranEcoNorm_swc_in, /* BIN10 */
                                           UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           UInt8 CoPt_bAcvProtCluP_swc_in,
                                           UInt8 CoPt_noEgdGearCord_swc_in,
                                           UInt32 CoPt_spdVehGearRatCord_swc_in, /* BIN10 */
                                           UInt8 Ext_bModSpt_swc_in,
                                           UInt8 FRM_bInhTqDemSptMod_swc_in,
                                           UInt8 TqSys_bInhTqDemSptMod_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bTqGrdLim_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfc_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMin_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkTakeOffMap_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bModSpt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rAccPSptMod_swc_out, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaTakeOff_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaEcoNorm_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcWoutAntiDB_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQDEM_Ivc_Structure(UInt8 TqDem_bAcvNRegTakeOff_swc_in,
                                         SInt16 TqDem_tqCkEfcDeltaTakeOff_swc_in, /* BIN4 */
                                         SInt16 TqDem_tqCkEfcDeltaEcoNorm_swc_in, /* BIN4 */
                                         UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                         UInt8 CoPTSt_stEng_swc_in,
                                         UInt8 CoPt_bTakeOff_swc_in,
                                         UInt8 CoPt_idxPtSpt_swc_in, /* BIN0 */
                                         UInt8 CoPt_noEgdGearCord_swc_in,
                                         UInt32 CoPt_spdVehGearRatCord_swc_in, /* BIN10 */
                                         UInt8 Ext_bKeyOn_swc_in,
                                         UInt8 Ext_bRvs_swc_in,
                                         UInt16 Ext_nEng_swc_in, /* BIN0 */
                                         UInt8 Ext_stGBxCf_swc_in,
                                         SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                         SInt16 Ext_tOxCEstim_swc_in, /* BIN0 */
                                         UInt8 FRM_bInhEco_swc_in,
                                         UInt8 FRM_bInhGreen_tCoMes_swc_in,
                                         UInt8 FRM_bInhGreen_tOxCEstim_swc_in,
                                         UInt8 FRM_bInhRvTqDemRevStOff_swc_in,
                                         UInt8 FRM_bInhRvTqDemTakeOff_swc_in,
                                         UInt8 TqSys_bAcvAntiStall_swc_in,
                                         UInt8 TqSys_bTypFu_swc_in,
                                         UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                         UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                         UInt8 EOM_bTWCHeatPha_swc_in,
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bDrivTakeOff_swc_out,
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFil_nCk_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rDrivTakeOff_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_idxMapRvsDrv_swc_out, /* BIN0 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_idxMapTranDrvFirst_swc_out, /* BIN0 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_idxMapTranDrvSec_swc_out, /* BIN0 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranDrv_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranEcoNorm_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) TQDEM_Take_Off_Assist(
                                           UInt16 CoVSCtl_rAccPEng_swc_out_par, /* BIN7 */
                                           UInt8 Cha_stTqReq_swc_in, /* BIN0 */
                                           UInt8 CoPt_bCluDiEgdCord_swc_in,
                                           UInt16 CoPt_nTarIdlCVC_swc_in, /* BIN2 */
                                           UInt16 Ext_pAirExtMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bDft_pAirExt_swc_in,
                                           UInt8 FRM_bInhNTarIdlTakeOff_swc_in,
                                           UInt8 TqSys_bAcvAntiStallMan_swc_in,
                                           UInt16 TqSys_nOfsFFL_swc_in, /* BIN2 */
                                           UInt16 TqSys_nOfsLauchIdlTakeOff_swc_in, /* BIN2 */
                                           UInt16 TqSys_nTarIdlFil_swc_in, /* BIN2 */
                                           UInt16 TqSys_nTarIdlNeut_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nOfsTotTakeOff_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarFFL_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarIdlCVCReq_swc_out /* BIN2 */);

extern FUNC(void, AUTOMATIC) TQDEM_Trq_Take_Off_Assist(UInt16 AccP_rAccP_swc_in,
                                           UInt8 CoPt_bAcvProtCluP_swc_in,
                                           UInt8 CoPt_bRvsCord_swc_in,
                                           UInt16 CoPt_nPrimShaft_swc_in,
                                           UInt8 CoPt_noEgdGearCord_swc_in,
                                           SInt16 CoPt_tqMaxClu_swc_in,
                                           UInt8 ESLim_bAcvTrqLim_swc_in,
                                           UInt16 ESLim_nLoFuCutOff_swc_in,
                                           SInt16 EngLim_tqEfcNRegTakeOffLim_swc_in,
                                           UInt16 Eng_nCkFil_swc_in,
                                           UInt16 Ext_nEng_swc_in,
                                           SInt16 Ext_tCoMes_swc_in,
                                           UInt8 FRM_bInhNRegTakeOff_swc_in,
                                           UInt8 FRM_bInhRegNLimN_swc_in,
                                           SInt16 TqCmp_tqSumLossCmp_swc_in,
                                           UInt16 TqDem_rAccPSptMod_swc_in,
                                           UInt16 TqDem_rDrivTakeOff_swc_in,
                                           SInt16 TqDem_tqCkEfc_swc_in,
                                           UInt8 TqSys_bEngNOnIdl_swc_in,
                                           UInt16 TqSys_nTarIdl_swc_in,
                                           SInt16 TqSys_tqIdcAirLimCordWiRes_swc_in,
                                           SInt16 TreatTenms_nCkGrd_swc_in,
                                           UInt16 Veh_spdVeh_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffEco_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffNorm_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqIdcLimNReg_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bAcvNRegTakeOff_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_nEngReq_swc_out);


/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) TQDEM_Coord_Lim_Em_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEM_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQDEM_Coord_Xvv_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_tqEfcReq_swc_out, /* BIN4 */
                                                                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEng_swc_out, /* BIN7 */
                                                                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPTra_swc_out, /* BIN7 */
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoVSCtl_stAccP_swc_out );

extern FUNC(void, AUTOMATIC) TQDEM_Dzone_Torque_Calc_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) DZone_tqEfcDifLrnOut_swc_out /* BIN4 */);


extern FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bTqGrdLim_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfc_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMin_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkTakeOffMap_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bModSpt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rAccPSptMod_swc_out, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaTakeOff_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaEcoNorm_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcWoutAntiDB_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQDEM_Ivc_Structure_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFil_nCk_swc_out, /* BIN10 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bDrivTakeOff_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqDem_idxMapTranDrvFirst_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqDem_idxMapTranDrvSec_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqDem_idxMapRvsDrv_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rDrivTakeOff_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranEcoNorm_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranDrv_swc_out);

extern FUNC(void, AUTOMATIC) TQDEM_Take_Off_Assist_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nOfsTotTakeOff_swc_out, /* BIN2 */
                                                  CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarFFL_swc_out,      /* BIN2 */
                                                  CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarIdlCVCReq_swc_out);  /* BIN2 */

extern FUNC(void, AUTOMATIC) TQDEM_Trq_Take_Off_Assist_Init(
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffEco_swc_out,
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffNorm_swc_out,
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqIdcLimNReg_swc_out, /* BIN4 */
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bAcvNRegTakeOff_swc_out,
                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_nEngReq_swc_out /* BIN0 */);


/*******************************************************************************
*  SWC Global Function
*******************************************************************************/

extern FUNC(UInt32, AUTOMATIC) TqDem_Timer_1ms_U32(void);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

#define DDS_TQDEM_1MS_U32_TIME  TqDem_Timer_1ms_U32()

#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

#endif

