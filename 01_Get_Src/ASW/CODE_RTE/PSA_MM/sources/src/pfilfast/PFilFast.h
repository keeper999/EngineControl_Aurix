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
* SW-C File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*------------------------------------------------------------------------------*
*
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFilFast.h
* Version int :/main/00PSASWC_E6/5 Date: 29/8/2013 11 h 45 m User:meme 
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\3 Date: 7/8/2013 16 h 49 m User:thauvin 
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 7/8/2013 15 h 23 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 15 h 50 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :dev PFilFast 14.0
* Version int :/main/00PSASWC_E6/4 Date: 26/7/2012 11 h 6 m User:posmyk
*    TWK_model:NO_MODEL
*    comments :For PFilFast_13_0_e6
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\1 Date: 26/7/2012 9 h 14 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For PFilFast_13_0_e6
* Version int :/main/00PSASWC_E6/3 Date: 17/2/2011 15 h 35 m User:meme
*    TWK_model:NO_MODEL
*    comments :update for dds.lib
* Version dev :\main\branch_halouane\5 Date: 16/2/2011 16 h 53 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for dds.lib
* Version dev :\main\branch_halouane\4 Date: 16/2/2011 15 h 6 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for TU
* Version dev :\main\branch_halouane\3 Date: 1/2/2011 15 h 39 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for 11.0
* Version dev :\main\branch_halouane\2 Date: 27/1/2011 17 h 42 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for 11.0
* Version dev :\main\branch_halouane\1 Date: 24/1/2011 12 h 52 m User:halouane
*    TWK_model:NO_MODEL
*    comments :Add new function required by spliting of "Acc Thres Wght" function
* Version int :/main/00PSASWC_E6/2 Date: 13/8/2010 9 h 31 m User:esnault
*    TWK_model:NO_MODEL
*    comments :change dds_lib version
* Version dev :\main\branch_lemort_pfilfast_dev\1 Date: 13/8/2010 9 h 11 m User:lemort
*    TWK_model:NO_MODEL
*    comments :change dds_lib version
* Version int :/main/00PSASWC_E6/1 Date: 12/8/2010 12 h 41 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 16/7/2010 13 h 52 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 1/7/2010 17 h 1 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 1/7/2010 15 h 39 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 1/7/2010 14 h 44 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 18/6/2010 9 h 42 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast 3.0
* Version int :/main/P2868/BR_06E6/5 Date: 14/1/2010 14 h 47 m User:esnault
*    TWK_model:LDCR_Application_06E611_IMPL1
*    comments :a new spec.requirement : TqSys_bAcvPlayCrossOn shoud be renamed as TqSys_bAcvPlayCross

*    comments :a new spec.requirement : TqSys_bAcvPlayCrossOn shoud be renamed as TqSys_bAcvPlayCross
* Version dev :\main\branch_salmane_pfilfast\3 Date: 30/9/2009 11 h 39 m User:salmane
*    TWK_model:LDCR_Application_06E610_IMPL2
*    comments :a new spec.requirement : TqSys_bAcvPlayCrossOn shoud be renamed as TqSys_bAcvPlayCross
* Version dev :\main\branch_salmane_pfilfast\2 Date: 28/9/2009 11 h 32 m User:salmane
*    TWK_model:LDCR_Application_06E610_IMPL2
*    comments :a new specification on CSMT_CGMT06_2094_Remark_Tracking_Sheet.xls
* Version int :/main/P2868/BR_06E6/3 Date: 24/9/2009 10 h 33 m User:langendorf
*    TWK_model:LDCR_Application_06E610_IMPL1
*    comments :for PFilFast 2.0
* Version dev :\main\branch_salmane_pfilfast\1 Date: 8/9/2009 9 h 36 m User:salmane
*    TWK_model:LDCR_Application_06E610_IMPL1
*    comments :for PFilFast 2.0
* Version int :/main/P2868/BR_06E6/2 Date: 14/11/2008 16 h 51 m User:langendorf
*    TWK_model:LDCR_Application_06E600_IMPL2
*    comments :Evolution DDS LIB
* Version dev :\main\branch_salmane_pfilfast\6 Date: 14/11/2008 12 h 12 m User:salmane
*    TWK_model:LDCR_Application_06E600_IMPL2
*    comments :Evolution DDS LIB
* Version dev :\main\branch_salmane_pfilfast_valid\2 Date: 13/11/2008 10 h 54 m User:salmane
*    TWK_model:LDCR_Application_06E600_IMPL2
*    comments :For PFilFast
* Version dev :\main\branch_salmane_pfilfast\4 Date: 10/11/2008 10 h 33 m User:salmane
*    TWK_model:LDCR_Application_06E600_IMPL2
*    comments :To Add Param.c
*    comments :To modify CoPt_noDrivFilTyp state
* Version dev :\main\branch_salmane_pfilfast\3 Date: 23/10/2008 10 h 30 m User:salmane
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :TqSys_noGearDrivFil should be UInt8
* Version dev :\main\branch_salmane_pfilfast\2 Date: 21/10/2008 11 h 8 m User:salmane
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments : "CoCha_bInhEGR" instead of "CoPt_bInhEGR". . .
* Version dev :\main\branch_moisan_pfilfast_dev\5 Date: 20/10/2008 17 h 26 m User:moisan
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :Work in progress
* Version dev :\main\branch_moisan_pfilfast_dev\4 Date: 20/10/2008 14 h 51 m User:moisan
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :Change in interface
* Version dev :\main\branch_moisan_pfilfast_dev\3 Date: 20/10/2008 14 h 30 m User:moisan
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :Change in function.
* Version dev :\main\branch_moisan_pfilfast_dev\2 Date: 16/10/2008 14 h 23 m User:moisan
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :Wrong interface
* Version dev :\main\branch_moisan_pfilfast_dev\1 Date: 16/10/2008 13 h 10 m User:moisan
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :temporary Version
* Version dev :\main\branch_salmane_pfilfast\1 Date: 8/10/2008 14 h 59 m User:salmane
*    TWK_model:LDCR_Application_06E600_IMPL1
*    comments :for proto
*
*******************************************************************************/

#ifndef PFILFAST_H
#define PFILFAST_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_PFilFast.h"


/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define PFILFAST_DDS_LIB_VERSION_REQ 280

/*******************************************************************************
*  SW-C Macro Definitions
*******************************************************************************/
#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_


#define TQSYS_NENG_PFILFAST1X_A_SIZE    8
#define TQSYS_NENG_PFILFAST3X_A_SIZE    12
#define TQSYS_NOGEAR_PFILFASTY_A_SIZE   7
#define TQSYS_RACCP_PFILFASTX_A_SIZE    10
#define TQSYS_TCO_PFILFAST1_A_SIZE      8

/* Ext_stGBxCf enumeration : SWC_IN */
#define STGBXCF_CONFIGURATION_BVM       (UInt32)0
#define STGBXCF_CONFIGURATION_BVA       (UInt32)1
#define STGBXCF_CONFIGURATION_BVMP      (UInt32)2

/* CoPTSt_stEng SWC_IN */
#define STENG_COUPE_CALE            (UInt32)1
#define STENG_PREPARATION           (UInt32)2
#define STENG_DRIVEN_START          (UInt32)3
#define STENG_AUTONOMOUS_START      (UInt32)4
#define STENG_ENGINE_RUNNING        (UInt32)5
#define STENG_STATE_STOP            (UInt32)6
#define STENG_DRIVEN_RESTART        (UInt32)7
#define STENG_AUTONOMOUS_RESTART    (UInt32)8

/* CoPt_noEgdGearCord SWC_IN */
#define NOEGDGEARCORD_N  (UInt32)0
#define NOEGDGEARCORD_R1 (UInt32)1
#define NOEGDGEARCORD_R2 (UInt32)2
#define NOEGDGEARCORD_R3 (UInt32)3
#define NOEGDGEARCORD_R4 (UInt32)4
#define NOEGDGEARCORD_R5 (UInt32)5
#define NOEGDGEARCORD_R6 (UInt32)6
#define NOEGDGEARCORD_MA (UInt32)7

/* CoPt_noDrivFilTyp : SWC_IN */
/*The use of "NODRIVABILITYFILTYP" is to avoid confusion with another definition */
#define NODRIVABILITYFILTYP_AGB_CONF_0          (UInt32)0
#define NODRIVABILITYFILTYP_AGB_CONF_1          (UInt32)1
#define NODRIVABILITYFILTYP_AGB_CONF_1_WGH      (UInt32)2
#define NODRIVABILITYFILTYP_AGB_CONF_2          (UInt32)3
#define NODRIVABILITYFILTYP_AGB_CONF_2_WGH      (UInt32)4

/* TqCmp_tqSumLossCmp_nCkTqDem : SWC_IN array */
#define TQCMP_TQSUMLOSSCMP_NCKTQDEM_SIZE 16

/* TqDem_stDrivTakeOff : SWC_OUT */
#define STDRIVTAKEOFF_DECO                  (UInt32)1
#define STDRIVTAKEOFF_HORS_DECO             (UInt32)2
#define STDRIVTAKEOFF_TRANS_CONV_COUPLE     (UInt32)3
#define STDRIVTAKEOFF_ATTENTE               (UInt32)4
#define STDRIVTAKEOFF_TRANS_TEMP_DECO_ROUL  (UInt32)5
#define STDRIVTAKEOFF_TRANS_TEMP_ROUL_DECO  (UInt32)6

/* TqSys_stDrivFilConfPha : INTER_RUN  */
#define STDRIVFILCONF_CONF_0            (UInt32)0
#define STDRIVFILCONF_CONF_1            (UInt32)1
#define STDRIVFILCONF_CONF_1_WGH        (UInt32)2
#define STDRIVFILCONF_CONF_2            (UInt32)3
#define STDRIVFILCONF_CONF_2_WGH        (UInt32)4
#define STDRIVFILCONF_CONF_3            (UInt32)5
#define STDRIVFILCONF_CONF_3_WGH        (UInt32)6
#define STDRIVFILCONF_CONF_4            (UInt32)7
#define STDRIVFILCONF_CONF_4_WGH        (UInt32)8

/* TqDem_stTqDem : INTER_RUN  */
#define STTQDEM_MA          (UInt32)0
#define STTQDEM_BV          (UInt32)2
#define STTQDEM_TRANS_BV_MV (UInt32)3
#define STTQDEM_MV          (UInt32)4
#define STTQDEM_TRANS_MV_HV (UInt32)5
#define STTQDEM_HV          (UInt32)6

/* TqDem_stGreen SWC_OUT */
#define STGREEN_NON_DEMARRE             (UInt32)1
#define STGREEN_DEMARRE                 (UInt32)2
#define STGREEN_TRANSITION_TEMPORELLE   (UInt32)3
#define STGREEN_ATTENTE                 (UInt32)4
#define STGREEN_NORMAL                  (UInt32)5

/* Ext_bRvs */
#define EXT_BRVS_MA_NON_ENGAGEE     (UInt32)0
#define EXT_BRVS_MA_ENGAGEE         (UInt32)1


/*TqSys_stDrivFilPhaIt  SWC_OUT*/

#define PFILFAST_DRIVFIL_OFF						(UInt32)(0 * BIN0)
#define PFILFAST_DRIVFIL_DISABLING					(UInt32)(1 * BIN0)
#define PFILFAST_ACCE_GAP_START_FILT				(UInt32)(2 * BIN0)
#define PFILFAST_ACCE_1ST_ORDER_FILT				(UInt32)(3 * BIN0)
#define PFILFAST_ACCE_SET_PASS_SLOPE				(UInt32)(4 * BIN0)
#define PFILFAST_ACCE_PARABOL						(UInt32)(5 * BIN0)
#define PFILFAST_ACCE_SLOPE_AFTER_PARABOL			(UInt32)(6 * BIN0)
#define PFILFAST_ACCE_SLOPE_ABOVE_SET				(UInt32)(7 * BIN0)
#define PFILFAST_DECE_D0_GAP						(UInt32)(8 * BIN0)
#define PFILFAST_DECE_1ST_SLOPE						(UInt32)(9 * BIN0)
#define PFILFAST_DECE_2ND_SLOPE						(UInt32)(10 * BIN0)
#define PFILFAST_DECE_3RD_SLOPE						(UInt32)(11 * BIN0)




/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

/* On Engine Synchronisation */

extern FUNC(void, AUTOMATIC) PFILFAST_Coord_Esp(UInt8 Cha_stTqReq_swc_in, /* BIN0 */
                                               SInt16 Cha_tqDynASRReq_swc_in, /* BIN4 */
                                               SInt16 Cha_tqMSRReq_swc_in, /* BIN4 */
                                               SInt16 EngLim_tqCkEfcChaLim_swc_in, /* BIN4 */
                                               SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                               SInt16 CoPt_tqEfcMaxProtDftl_swc_in, /* BIN4 */
                                               SInt16 EngLim_tqEfcMaxDynVehSpdCtl_swc_in, /* BIN4 */
                                               UInt8 FRM_bInhESPReq_swc_in,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcReq_swc_out, /* BIN4 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGR_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqAccuReq_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqDynReq_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqASR_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqMSR_swc_out,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLim_swc_out, /* BIN4 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bRstAOS_swc_out,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLimTqMaxDyn_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Acc_Thres_Wght(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 TqDem_bModSpt_swc_in,
                                           SInt16 TqSys_nDif_nEngNTrb_swc_in, /* BIN2 */
                                           UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                           UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                           SInt16 TreatTenms_nCkGrdFil_swc_in /* BIN2 */);

extern FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_Acceleration_Thresholds(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
											 UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
											 UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
											 UInt8 TqSys_stDrivFilCfPha_swc_in, /* BIN0 */
											 UInt8 TqDem_bModSpt_swc_in,
											 UInt16 CoVSCtl_rAccPEng_swc_in,
											 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3It_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Acc_Conf2(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 TqSys_noGearCordDrivFil_swc_in /* BIN0 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Acc_Conf1(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 TqSys_noGearCordDrivFil_swc_in /* BIN0 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Decel_Thres_Slew(SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           UInt8 TqDem_bModSpt_swc_in,
                                           UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                           UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                           UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                           UInt8 TqSys_stDrivFilCfPha_swc_in,
                                           SInt16 TqSys_tqCkDeceIniIt_swc_in /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Decel_Times(SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                           UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                           UInt8 TqSys_stDrivFilCfPha_swc_in,
                                           SInt16 TqSys_tqCkDeceIniIt_swc_in /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Filt_Activ(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           SInt16 EngLim_tqCkDrivFil_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 TqCll_bAcvCll_swc_in,
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                           UInt8 TqSys_bDiDrivFilReq_swc_in,
                                           UInt8 TqSys_bInjCutDynReq_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcvIt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nEngDeceIni_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearDece_swc_out, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIniIt_swc_out /* BIN4 */ );

extern FUNC(void, AUTOMATIC) PFILFAST_Pre_Treat(UInt16 CoPt_nTrb_swc_in, /* BIN2 */
                                           UInt8 CoPt_noDrivFilTyp_swc_in,
                                           UInt8 CoPt_noGearCordDrivFil_swc_in,
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_bDiDrivFilReq_swc_in,
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 TqClrCros_bAcvClrCross_swc_in,
                                           UInt16 TqCmp_tqACLoss_swc_in, /* BIN4 */
                                           UInt8 TqDem_bDrivTakeOff_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           UInt8 FRM_bDft_spdVeh_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDiDrivFilReq_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nDif_nEngNTrb_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilCfPha_swc_out);

extern FUNC(void, AUTOMATIC) PFILFAST_Scnd_Out(UInt8 CoPt_noDrivFilTyp_swc_in,
                                           SInt16 EngLim_tqCkDrivFil_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 TqClrCros_stDetClr_swc_in,
                                           UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt8 TqSys_stDrivFilPhaIt_swc_in,
                                           SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                           UInt8 TqSys_bDeceAcvIt_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCllIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bClrCrossAcce_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bUHFrzReq_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthIt_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCllIt_swc_out, /* DEC2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCllIt_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_State_Machine(UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                           SInt16 Cha_tqDynASRReq_swc_in, /* BIN4 */
                                           UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAcvVehSpdCtlReg_swc_in,
                                           UInt8 TqSys_bDeceAcvIt_swc_in,
                                           UInt8 TqSys_bDiDrivFilReq_swc_in,
                                           SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                           UInt8 TqClrCros_stDetClr_swc_in, /*BIN0*/
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPhaIt_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFil_swc_out /* BIN4 */);

/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) PFILFAST_Coord_Esp_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcReq_swc_out, /* BIN4 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGR_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqAccuReq_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqDynReq_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqASR_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqMSR_swc_out,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLim_swc_out, /* BIN4 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bRstAOS_swc_out,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLimTqMaxDyn_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Acc_Thres_Wght_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3It_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Acc_Conf2_Init(void);

extern FUNC(void, AUTOMATIC) PFILFAST_Acc_Conf1_Init(void);

extern FUNC(void, AUTOMATIC) PFILFAST_Decel_Thres_Slew_Init(void);


extern FUNC(void, AUTOMATIC) PFILFAST_Decel_Times_Init(void);

extern FUNC(void, AUTOMATIC) PFILFAST_Filt_Activ_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcvIt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nEngDeceIni_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearDece_swc_out, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIniIt_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_Pre_Treat_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDiDrivFilReq_swc_out,
                                                       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nDif_nEngNTrb_swc_out, /* BIN2 */
                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilCfPha_swc_out);

extern FUNC(void, AUTOMATIC) PFILFAST_Scnd_Out_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCllIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bClrCrossAcce_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bUHFrzReq_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthIt_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCllIt_swc_out, /* DEC2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCllIt_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILFAST_State_Machine_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPhaIt_swc_out, /* BIN0 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFil_swc_out /* BIN4 */);

/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) PFilFast_Timer_1ms_U32(void);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_PFILFAST_1MS_U32_TIME   PFilFast_Timer_1ms_U32()

#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

#endif

