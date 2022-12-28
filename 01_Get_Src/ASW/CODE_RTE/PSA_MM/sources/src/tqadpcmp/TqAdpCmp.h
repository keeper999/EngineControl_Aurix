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
* Ref X:\integration_view_00PSASWC_E521D11\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TqAdpCmp.h
* Version int :/main/00PSASWC_E5/6 Date: 2/5/2013 12 h 22 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :update TQADPCMP_Estim_Air_Cond_T4
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 25/4/2013 13 h 19 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :update TQADPCMP_Estim_Air_Cond_T4
* Version int :/main/00PSASWC_E5/5 Date: 21/3/2012 15 h 8 m User:esnault
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 20/3/2012 11 h 11 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/00PSASWC_E5/4 Date: 14/9/2011 16 h 28 m User:meme
*    TWK_model:NO_MODEL
*    comments :dev TqAdpCmp 10.6
* Version dev :\main\branch_halouane_tqadpcmp_euro6\3 Date: 12/9/2011 12 h 42 m User:halouane
*    TWK_model:NO_MODEL
*    comments :dev TqAdpCmp 10.6
* Version dev :\main\branch_halouane_tqadpcmp_euro6\2 Date: 26/8/2011 14 h 29 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_10.6_e6, Add a diversity constant "OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC",
*    comments :and correction FDS "A0202589".
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 26/8/2011 14 h 28 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_10.6_e6, Add a diversity constant "OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC",
*    comments :and correction FDS "A0202589".
* Version int :/main/00PSASWC_E5/2 Date: 18/11/2010 12 h 49 m User:meme
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 17/11/2010 16 h 49 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 16/11/2010 16 h 51 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp 10.2
* Version int :/main/00PSASWC_E5/1 Date: 13/9/2010 14 h 17 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 10/9/2010 11 h 12 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 10/9/2010 10 h 40 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 3/9/2010 12 h 29 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 9/7/2010 16 h 22 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 8/7/2010 18 h 4 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 7/7/2010 9 h 22 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 29/6/2010 11 h 48 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 1.0
* Version int :/main/P2868/BR_06D5/1 Date: 9/9/2009 13 h 29 m User:langendorf
*    TWK_model:LDCR_Application_06E510_IMPL1
*    comments :pass define in UInt32
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 1/9/2009 11 h 5 m User:lemort
*    TWK_model:LDCR_Application_06E510_IMPL1
*    comments :pass define in UInt32
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 24/8/2009 13 h 10 m User:lemort
*    TWK_model:LDCR_Application_06E510_IMPL1
*    comments :work in progress, for STIL 2.0
* Version int :/main/P2868/BR_06E5/2 Date: 23/10/2008 14 h 4 m User:boucher
*    TWK_model:LDCR_Application_06E500_IMPL2
*    comments :Add TQCMP_V_CA_SIZE
* Version dev :\main\branch_moisan_tqadpcmp_validation\2 Date: 15/10/2008 9 h 40 m User:moisan
*    TWK_model:LDCR_Application_06E500_IMPL2
*    comments :Add TQCMP_V_CA_SIZE
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 24/9/2008 14 h 44 m User:moisan
*    TWK_model:LDCR_Application_06E500_IMPL2
*    comments :Wrong interface in TQADPCMP_Coord_Global_Loss
* Version int :/main/P2868/BR_06E5/1 Date: 23/9/2008 10 h 28 m User:boucher
*    TWK_model:LDCR_Application_06E500_IMPL1
*    comments :First version for TqAdpCmp 1.0
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\2 Date: 22/9/2008 17 h 12 m User:girodon
*    TWK_model:LDCR_Application_06E500_IMPL1
*    comments :First version for TqAdpCmp 1.0
*
*******************************************************************************/


#ifndef TQADPCMP_H
#define TQADPCMP_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_TqAdpCmp.h"


/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define TQADPCMP_DDS_LIB_VERSION_REQ 250

/*******************************************************************************
*  SW-C Macro Definitions
*******************************************************************************/
#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_


/* For TqAdp_stCdnNxtCkg & TqAdp_stCdnNxtCkgLrnOn */
#define TQADPCMP_NOMINAL		(UInt32)0
#define TQADPCMP_FAVORABLE		(UInt32)1
#define TQADPCMP_DEFAVORABLE	(UInt32)2

#define TQADPCMP_DIESEL     (UInt32)0
#define TQADPCMP_GASOLINE   (UInt32)1

#define TQADPCMP_NEUTRAL_PARK   (UInt32)0
#define TQADPCMP_ACTIVATED      (UInt32)1
#define TQADPCMP_DEACTIVATED    (UInt32)2
#define TQADPCMP_UNCERTAIN      (UInt32)3

#define TQADPCMP_TQDEM_NCK_CA_SIZE 16
#define TQCMP_V_CA_SIZE            5


#define TQADPCMP_2_SIZE                       2
#define TQADPCMP_4_SIZE                       4
#define TQADPCMP_5_SIZE                       5
#define TQADPCMP_6_SIZE                       6
#define TQADPCMP_7_SIZE                       7
#define TQADPCMP_8_SIZE                       8
#define TQADPCMP_10_SIZE                      10
#define TQADPCMP_16_SIZE                      16


/* For Ext_stACTypCf */
#define TQADPCMP_PAS_DE_CLIM   (UInt8)0
#define TQADPCMP_CLIM_TYPE_3   (UInt8)1
#define TQADPCMP_CLIM_TYPE_4   (UInt8)2
#define TQADPCMP_RESERVE_3     (UInt8)3

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

extern FUNC(void, AUTOMATIC) TQADPCMP_Allow_Inhibit_Stt(UInt8 CoPTSt_stEng_swc_in,
                                           UInt32 Ext_dstVehMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhAdp_swc_in,
                                           UInt8 TqAdp_bMonRunORngDragRed_swc_in,
                                           UInt8 TqAdp_bMonRunORngNeut_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bInhEngStop_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_stCdnNxtCkg_swc_out);

extern FUNC(void, AUTOMATIC) TQADPCMP_Calc_Running_Tq(UInt8 AC_bACClu_swc_in,
                                           UInt8 CoOptmEl_stElProd_swc_in,
                                           UInt8 CoPt_bTqTx_swc_in,
                                           UInt8 CoPt_stCpl_swc_in,
                                           UInt16 EOM_tiEngRunStrt_swc_in, /* DEC2 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhAdp_swc_in,
                                           UInt8 TqAdp_bFrzAdpACOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpAltOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpCnvOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpStgPmpOn_swc_in,
                                           UInt16 TqCmp_tqACLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossEstim_swc_in, /* BIN4 */
                                           UInt8 TqSys_bEngNOnIdl_swc_in,
                                           UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           UInt8 CoPt_stDragRed_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngNeut_swc_out );

extern FUNC(void, AUTOMATIC) TQADPCMP_Calc_Tq_Applicable(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLossAdp_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Coord_Accessory_Ls(UInt16 TqCmp_tqACLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                           UInt16 TqCmp_tqAuxLoss_swc_in, /* BIN4 */
                                           UInt16 TqCmp_tqStgPmpLoss_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossEstim_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Coord_Global_Loss(UInt8 CoPTSt_stEng_swc_in,
                                           SInt16 TqCmp_tqAuxSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAuxSumLossEstim_swc_in, /* BIN4 */
                                           UInt16 TqCmp_tqCnvLoss_swc_in, /* BIN4 */
                                           UInt16 TqSys_tqCkEngLoss_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkEngLossAdp_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmpWoutCnv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossEstim_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Coord_Lost_Motor(UInt32 EOM_tiEngStop_swc_in, /* DEC0 */
                                           UInt16 EngM_rAirLdCor_swc_in, /* BIN14 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt16 ExM_pExMnfEstim_swc_in, /* NBIN3 */
                                           SInt16 ExM_pUsTrbEstimTqSys_swc_in, /* BIN0 */
                                           UInt16 Ext_pAirExtMes_swc_in, /* BIN0 */
                                           SInt16 Ext_pDsThrMes_swc_in, /* BIN0 */
                                           UInt16 Ext_pOilMes_swc_in, /* BIN7 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tOilMes_swc_in, /* DEC1 */
                                           UInt8 FRM_bAcvTqEngLossDftOil_swc_in,
                                           UInt8 FRM_bAcvTqEngLossDftPDs_swc_in,
                                           UInt8 FRM_bAcvTqEngLossDftPmp_swc_in,
                                           UInt8 FRM_bAcvTqEngLossDftT_swc_in,
                                           UInt16 InM_pDsThrCor_swc_in, /* NBIN3 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_tqCkPumpHiPLoss_swc_in, /* BIN4 */
                                           UInt16 Ext_nEng_swc_in, /*BIN0*/
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stACTypCf_swc_in, /* BIN0 */
                                           UInt8 TqAdp_bFrzAdpACAuxOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpACExtECUOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpACItECUOn_swc_in,
                                           UInt8 TqCmp_bACExtECUOffDftSelOn_swc_in,
                                           UInt16 TqCmp_pwrACAuxLoss_swc_in, /* BIN0 */
                                           UInt16 TqCmp_pwrACExtECULoss_swc_in, /* BIN0 */
                                           UInt16 TqCmp_pwrACItECULoss_swc_in, /* BIN0 */
                                           UInt8 TqDem_bTqGrdLim_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACLoss_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqACLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T3(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_bACCluAuth_swc_in,
                                           UInt16 Ext_pAC_swc_in, /* BIN0 */
                                           SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhACItECULossMdl_swc_in,
                                           UInt8 Ext_stACTypCf_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACItECUOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACItECULoss_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T4(UInt8 AC_bACClu_swc_in,
                                           UInt8 AC_pwrAC_swc_in, /* NBIN0 resol 25 */
                                           UInt8 FRM_bInhACExtECULossMdl_swc_in,
                                           UInt8 TqRes_bDftACSwtOn_swc_in,
                                           UInt8 Ext_stACTypCf_swc_in,
                                           SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           UInt16 Ext_pAC_swc_in, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACExtECUOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACExtECUOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACExtECULoss_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Alternator(SInt16 CoOptmEl_tqAlt_swc_in, /* BIN4 */
                                           UInt8 CoPTSt_stEng_swc_in,
                                           UInt8 CoPtUH_stPwt_swc_in,
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_bTqAltEstimElSys_swc_in,
                                           UInt16 Ext_facRatTqAltCf_swc_in, /* BIN7 */
                                           UInt8 Ext_iAltExct_swc_in, /* DEC1 */
                                           UInt8 Ext_idxAltClas_swc_in, /* BIN0 */
                                           UInt8 Ext_idxCtlAltProvIdf_swc_in, /* BIN0 */
                                           UInt8 Ext_rAltCycOp_swc_in, /* BIN0 */
                                           UInt8 Ext_stAltClasCf_swc_in,
                                           UInt8 Ext_stElProdCf_swc_in,
                                           SInt16 Ext_tqAlt_swc_in, /* BIN4 */
                                           UInt8 FRM_bDftAltTyp_swc_in,
                                           UInt8 FRM_bDftComAlt_swc_in,
                                           UInt8 FRM_bDftElAlt_swc_in,
                                           UInt8 FRM_bDftMecAlt_swc_in,
                                           UInt8 FRM_bInhAltLossMdl_swc_in,
                                           UInt8 TqDem_bTqGrdLim_swc_in,
                                           UInt16 TqRes_tqFanStrtLoss_swc_in, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpAltOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bDgo_tqAltRv_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAltLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Bva(UInt8 CoPt_bTqTx_swc_in,
                                           UInt16 CoPt_nTrb_swc_in, /* BIN2 */
                                           UInt8 CoPt_stDragRed_swc_in,
                                           SInt16 CoPt_tOilGBx_swc_in, /* BIN2 */
                                           SInt16 CoPt_tqCnvClu_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 FRM_bInhCnvLossMdl_swc_in,
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpCnvOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqCnvLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Steering(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stStgPmpCf_swc_in,
                                           UInt8 FRM_bInhStgPmpLossMdl_swc_in,
                                           UInt8 Stg_bStgPmpThdMes_swc_in,
                                           UInt16 Stg_pStgPmpLnrMes_swc_in, /* BIN2 */
                                           UInt8 TqDem_bTqGrdLim_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqStgPmpLoss_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpStgPmpOn_swc_out);

extern FUNC(void, AUTOMATIC) TQADPCMP_Loss_Nvm(void);

extern FUNC(void, AUTOMATIC) TQADPCMP_Model_Tair(UInt16 AirSys_mfAirMesThrEstim_swc_in, /* BIN7 */
                                           UInt8 CoPTSt_stEng_swc_in,
                                           UInt32 EOM_tiEngRun_swc_in, /* DEC0 */
                                           UInt32 EOM_tiEngStop_swc_in, /* DEC0 */
                                           SInt16 Ext_tAirUsCmprMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tDsThrMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhTAirEstim_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bEngStrtReq_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bTAirChk_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqCmp_tAirEstim_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Temp_Engine(UInt8 CoPt_stDragRed_swc_in,
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tOilMes_swc_in /* DEC1 */);

/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) TQADPCMP_Allow_Inhibit_Stt_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bInhEngStop_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_stCdnNxtCkg_swc_out );

extern FUNC(void, AUTOMATIC) TQADPCMP_Calc_Running_Tq_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngNeut_swc_out );

extern FUNC(void, AUTOMATIC) TQADPCMP_Calc_Tq_Applicable_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLossAdp_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Coord_Accessory_Ls_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossEstim_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Coord_Global_Loss_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmpWoutCnv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossEstim_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Coord_Lost_Motor_Init( CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACLoss_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqACLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T3_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACItECUOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACItECULoss_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T4_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACExtECUOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACExtECUOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACExtECULoss_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Alternator_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bDgo_tqAltRv_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpAltOn_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAltLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Bva_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpCnvOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqCnvLoss_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Estim_Steering_Init(
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqStgPmpLoss_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpStgPmpOn_swc_out);

extern FUNC(void, AUTOMATIC) TQADPCMP_Loss_Nvm_Init(void);

extern FUNC(void, AUTOMATIC) TQADPCMP_Model_Tair_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bEngStrtReq_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bTAirChk_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqCmp_tAirEstim_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) TQADPCMP_Temp_Engine_Init(void);

/* SWC Global Function */
extern FUNC(UInt32, AUTOMATIC) TqAdpCmp_Timer_1ms_U32(void);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_TQADPCMP_1MS_U32_TIME TqAdpCmp_Timer_1ms_U32()

#define TQADPCMP_STOP_SEC_CODE
#include "TqAdpCmp_MemMap.h"

#endif

