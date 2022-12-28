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
* Ref X:\integration_view_00PSASWC_EC00D01\blois_psa_sstg\Software\Appli\CoTq\src\CoTq.h
* Version int :/main/00PSASWC_EC/1 Date: 5/11/2010 11 h 57 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\3 Date: 26/10/2010 17 h 2 m User:demezil 
*    TWK_model:NO_MODEL
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 46 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 43 m User:lemort
*    TWK_model:NO_MODEL
*    comments :first dev CoTq
*
*******************************************************************************/


#ifndef COTQ_H
#define COTQ_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_CoTq.h"


/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define COTQ_DDS_LIB_VERSION_REQ 250

/*******************************************************************************
*  SW-C Macro Definitions
*******************************************************************************/
#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

/******************************************************************************/

#define COTQ_TQCKEFC_VECT_SIZE               2

/* TqSys_stDrivFilPha */
#define TQSYS_STFILTRAGE_DESACTIVE									0
#define TQSYS_STFILTRAGE_INACTIF									1
#define TQSYS_ACCEL_ZONE_2_SAUT_DEBUE_DU_FILTRAGE					2
#define TQSYS_ACCEL_ZONE_3_1ER_ORDRE								3
#define TQSYS_ACCEL_ZONE_4_PENTE_DE_TRAVERSEE_DES_JEUX				4
#define TQSYS_ACCEL_ZONE_5_FORME_PARABOLIQUE						5
#define TQSYS_ACCEL_ZONE_6_LIMITATION_DE_LA_PARABOLE				6
#define TQSYS_ACCEL_ZONE_7_PENTE_AU_DESSUS_DES_JEUX					7
#define TQSYS_DECEL_ZONE_8_SAUT_DE_DEBUT_DE_FILTRAGE				8
#define TQSYS_DECEL_ZONE_9_PREMIERE_PENTE							9
#define TQSYS_DECEL_ZONE_10_2ND_PENTE_POUR_LA_TRAVERSEE_DES_JEUX	10
#define TQSYS_DECEL_ZONE_11_3EME_PENTE								11
#define TQSYS_STRESERVE_12											12
#define TQSYS_STRESERVE_13											13
#define TQSYS_STRESERVE_14											14
#define TQSYS_STRESERVE_15											15

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"

extern FUNC(void, AUTOMATIC) COTQ_Sync_Engine_Speed(SInt16 CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
                                             UInt8 CoPTSt_bMainEngStopReq_swc_in,
                                             UInt8 CoPTSt_stEng_swc_in,
                                             SInt16 EngLim_tqIdcEngCur_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcEngLimMax_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcFLdLim_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcLdMaxTrbMax_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcLdMinAdvMin_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcLdMinAdvMinSelc_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcMaxNReg_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcPresUsThrMax_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcEngCurGBx_swc_in, /* BIN4 */
                                             UInt32 EOM_tiEngStop_swc_in, /* BIN0 */
                                             SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                             UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                             SInt16 Ext_tOilMes_swc_in, /* BIN4 */
                                             SInt16 InjSys_tqIdcMinFeas_swc_in, /* BIN4 */
                                             SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                             SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                             SInt16 TqCmp_tqSumLossCmpWoutCnv_swc_in, /* BIN4 */
                                             SInt16 TqEst_tqIdcEstim_swc_in, /* BIN4 */
                                             SInt16 TqLimEM_tqLimEMTrv_swc_in, /* BIN4 */
                                             UInt8 TqSys_bTypFu_swc_in,
                                             SInt16 TqSys_tqCkEngLimCord_swc_in, /* BIN4 */
                                             UInt16 TreatTDC_nCkFil_swc_in, /* BIN2 */
                                             SInt16 TreatTDC_nCkGrdFil_swc_in, /* BIN2 */
                                             UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcReqCord_nRegReq_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLim_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLimCmb_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdAdvMinFuCutSel_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMinAdvMin_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxEngLimCmb_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxNReg_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcMinFeas_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngReal_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngRealEM_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcEngWoutAOS_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Conversion_10ms(UInt8 CoPTSt_bMainEngStopReq_swc_in,
                                           UInt8 CoPTSt_stEng_swc_in,
                                           SInt16 EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngCurMin_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngCurMinSelc_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcFLdLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcLdMaxTrbMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcLdMaxTrbMaxNoOvb_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcPresUsThrMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSfty_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSmkLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                           UInt16 Ext_pAirExtMes_swc_in, /* BIN0 */
                                           SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           SInt16 IdlSys_tqIdcAirIdl_swc_in, /* BIN4 */
                                           UInt16 ThMgt_tqIdcLimReq_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           SInt16 TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcReq_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcFLdLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcSmkLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcCurMinFuCutSel_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMin_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngProt_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxTrbMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxWoutOvb_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurCutOffTrv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurTrv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinEngLimCmb_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcPresUsThrMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcRed_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSfty_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSyst_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) ThMgt_tqEfcLimAntiBoilProt_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_rLdEngRef_swc_out, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcReq_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcAirIdl_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcIdl_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Func_Call(UInt16 Ext_nEng_swc_in, /* BIN0 */
                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvTqCnv_swc_out );

extern FUNC(void, AUTOMATIC) COTQ_Torque_Selection(UInt8 CoCha_bAcvCllIt_swc_in,
                                            UInt8 CoCha_bInhEGR_swc_in,
                                            UInt8 CoCha_bInhEGRExt_swc_in,
                                            SInt8 CoCha_noCylCutAuthIt_swc_in, /* BIN0 */
                                            UInt16 CoCha_tiTranCllIt_swc_in, /* DEC2 */
                                            SInt16 CoCha_tqIncCllIt_swc_in, /* BIN4 */
                                            UInt8 CoPt_bDeacCllExt_swc_in,
                                            UInt8 CoPt_bDeacCllIt_swc_in,
                                            SInt16 CoPt_tqEfcAirCordLimExtTqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqEfcAirCordLimIt_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqEfcCordLimExt_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqEfcCordLimIt_tqGBx_swc_in, /* BIN4 */
                                            UInt8 CoPtUH_bEngAsiReq_swc_in,
                                            UInt8 CoPtUH_bEngAsiReqExt_swc_in,
                                            UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                            UInt16 CoVSCtl_rAccPEngExt_swc_in, /* BIN7 */
                                            SInt16 EngLim_tqCkEfcStatLimExt_swc_in, /* BIN4 */
                                            SInt16 EngLim_tqCkEfcStatLimIt_swc_in, /* BIN4 */
                                            UInt8 Ext_stTraTypCf_swc_in,
                                            UInt16 TqDem_facGainFil_nCk_swc_in, /* BIN10 */
                                            SInt16 TqDem_tqCkEfc_swc_in, /* BIN4 */
                                            SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                            SInt16 TqLimEM_tqLimEMExt_swc_in, /* BIN4 */
                                            UInt8 TqSys_bAcceClrCrossAOSExt_swc_in,
                                            UInt8 TqSys_bAcceClrCrossAOSIt_swc_in,
                                            UInt8 TqSys_bAcceDetAOSExt_swc_in,
                                            UInt8 TqSys_bAcceDetAOSIt_swc_in,
                                            UInt8 TqSys_bAcvCllExt_swc_in,
                                            UInt8 TqSys_bAcvCllIt_swc_in,
                                            UInt8 TqSys_bDeceAcvExt_swc_in,
                                            UInt8 TqSys_bDeceAcvIt_swc_in,
                                            UInt8 TqSys_bDeceDetAOSExt_swc_in,
                                            UInt8 TqSys_bDeceDetAOSIt_swc_in,
                                            SInt8 TqSys_noCylCutAuthExt_swc_in, /* BIN0 */
                                            SInt8 TqSys_noCylCutAuthIt_swc_in, /* BIN0 */
                                            UInt8 TqSys_stDrivFilPhaExt_swc_in,
                                            UInt8 TqSys_stDrivFilPhaIt_swc_in,
                                            UInt8 TqSys_stTypPwtCf_swc_in,
                                            UInt16 TqSys_tiTranCllExt_swc_in, /* DEC2 */
                                            UInt16 TqSys_tiTranCllIt_swc_in, /* DEC2 */
                                            SInt16 TqSys_tqCkDeceIniExt_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqCkEfcFilExt_swc_in, /* BIN4 */
                                            UInt16 TqSys_tqIncCllExt_swc_in, /* BIN4 */
                                            UInt16 TqSys_tqIncCllIt_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqThdPha3Ext_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCll_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGRTrv_swc_out,
                                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoCha_noCylCutAuth_swc_out, /* BIN0 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCll_swc_out, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCll_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCll_swc_out,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLim_tqGBx_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEngTrv_swc_out, /* BIN7 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcStatLim_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFilTrv_nCk_swc_out, /* BIN10 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcTrv_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEMTrv_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOS_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOS_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCll_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcv_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOS_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngAsiReqTrv_swc_out,
                                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuth_swc_out, /* BIN0 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPha_swc_out,
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCll_swc_out, /* DEC2 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIni_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFilTrv_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCll_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Tempo_Data_Synch(UInt8 CoPt_bAcvNRegReq_swc_in,
                                            UInt8 CoPt_bDeacCll_swc_in,
                                            UInt8 CoPt_bSIP_swc_in,
                                            SInt8 CoPt_noTarGearCordIt_swc_in,
                                            UInt16 CoPt_nTar_swc_in, /* BIN2 */
                                            SInt16 CoPt_tqEfcCordLim_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqIdcCordLim_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqIdcMaxGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqMaxGBx_nReg_swc_in, /* BIN4 */
                                            SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                            SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                            UInt8 TqSys_bTypFu_swc_in,
                                            SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvNRegReqBuf_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCllBuf_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth1_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth2_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bSIPBuf_swc_out,
                                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoPt_noTarGearCordBuf_swc_out, /* BIN0 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoPt_nTarBuf_swc_out, /* BIN2 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLimBuf_tqGBx_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBxBuf_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqMaxGBx_nRegBuf_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Cord_Lim_Torq_Struct(SInt16 CoPt_tqAirCord_tqGBx_swc_in, /* BIN4 */
                                                SInt16 CoPt_tqCord_tqGBx_swc_in, /* BIN4 */
                                                SInt16 EngLim_tqCkEfcAirGBxLimCord_swc_in, /* BIN4 */
                                                SInt16 EngLim_tqCkEfcGBxLimCord_swc_in, /* BIN4 */
                                                UInt8 TqSys_bTypFu_swc_in,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLimIt_tqGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLimIt_tqGBx_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Cme_Cmi_Convers(UInt8 CoCha_bInhEGRTrv_swc_in,
                                           UInt8 CoCha_bRstAOS_swc_in,
                                           UInt8 CoPt_bInhEGR_swc_in,
                                           SInt16 CoPt_tqAirMaxGBx_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqEfcAirCordLim_tqGBx_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqEfcCordLim_tqGBx_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqMaxGBx_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqCkEfcAirLim_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqLimEM_tqLimEMTrv_swc_in, /* BIN4 */
                                           UInt8 TqSys_bFuCutOffReq_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirMaxGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLim_tqGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqIdcLimEM_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInhEGR_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bRstAOS_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLim_swc_out /* BIN4 */);

/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) COTQ_Sync_Engine_Speed_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcReqCord_nRegReq_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLim_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLimCmb_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdAdvMinFuCutSel_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMinAdvMin_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxEngLimCmb_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxNReg_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcMinFeas_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngReal_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngRealEM_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcEngWoutAOS_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Conversion_10ms_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcFLdLim_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcLim_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcSmkLim_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcCurMinFuCutSel_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMax_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMin_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngProt_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxTrbMax_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxWoutOvb_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurCutOffTrv_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurTrv_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinEngLimCmb_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcPresUsThrMax_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcRed_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSfty_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSyst_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) ThMgt_tqEfcLimAntiBoilProt_swc_out, /* BIN4 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_rLdEngRef_swc_out, /* BIN0 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcReq_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcAirIdl_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcIdl_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Func_Call_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvTqCnv_swc_out );

extern FUNC(void, AUTOMATIC) COTQ_Torque_Selection_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCll_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGRTrv_swc_out,
                                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoCha_noCylCutAuth_swc_out, /* BIN0 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCll_swc_out, /* DEC2 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCll_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCll_swc_out,
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLim_tqGBx_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEngTrv_swc_out, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcStatLim_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFilTrv_nCk_swc_out, /* BIN10 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcTrv_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEMTrv_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOS_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOS_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCll_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcv_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOS_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngAsiReqTrv_swc_out,
                                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuth_swc_out, /* BIN0 */
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPha_swc_out,
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCll_swc_out, /* DEC2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIni_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFilTrv_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCll_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Tempo_Data_Synch_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvNRegReqBuf_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCllBuf_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth1_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth2_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bSIPBuf_swc_out,
                                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoPt_noTarGearCordBuf_swc_out, /* BIN0 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoPt_nTarBuf_swc_out, /* BIN2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLimBuf_tqGBx_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBxBuf_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqMaxGBx_nRegBuf_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Cord_Lim_Torq_Struct_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLimIt_tqGBx_swc_out, /* BIN4 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLimIt_tqGBx_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COTQ_Cme_Cmi_Convers_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirMaxGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLim_tqGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqIdcLimEM_swc_out, /* BIN4 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInhEGR_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bRstAOS_swc_out,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLim_swc_out /* BIN4 */);

/*******************************************************************************
*  SWC Global Function
*******************************************************************************/

extern FUNC(UInt32, AUTOMATIC) CoTq_Timer_1ms_U32(void);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

#define DDS_COTQ_1MS_U32_TIME  CoTq_Timer_1ms_U32()

#define COTQ_STOP_SEC_CODE
#include "CoTq_MemMap.h"

#endif
