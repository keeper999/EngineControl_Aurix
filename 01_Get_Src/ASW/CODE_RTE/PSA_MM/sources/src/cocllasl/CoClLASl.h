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
* Ref X:\integration_view_00PSASWC_EA30D11\blois_psa_sstg\Software\Appli\CoClLASl\src\CoClLASl.h
* Version int :/main/00PSASWC_EA/7 Date: 21/1/2014 11 h 58 m User:groult 
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl 13.0
* Version dev :\main\branch_lemort_generic\1 Date: 17/12/2013 16 h 40 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl 13.0
* Version dev :\main\branch_lemort\1 Date: 17/12/2013 15 h 32 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl 13.0
* Version int :/main/00PSASWC_EA/6 Date: 11/4/2012 13 h 9 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 12.0
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 2/4/2012 10 h 25 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 12.0
* Version int :/main/00PSASWC_EA/5 Date: 6/6/2011 10 h 39 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 11.2 (input renamed)
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 23/5/2011 17 h 17 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 11.2 (input renamed)
* Version int :/main/00PSASWC_EA/4 Date: 17/3/2011 9 h 26 m User:esnault
*    TWK_model:NO_MODEL
*    comments :update for CoClLASl 11.1
* Version dev :\main\branch_demezil_cocllasl_view\1 Date: 15/3/2011 15 h 37 m User:demezil
*    TWK_model:NO_MODEL
*    comments :update for CoClLASl 11.1
* Version int :/main/00PSASWC_EA/3 Date: 25/2/2011 11 h 29 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for QAC
* Version dev :\main\branch_halouane_CoClLASl_dev\3 Date: 16/2/2011 17 h 54 m User:halouane
*    TWK_model:NO_MODEL
*    comments :for QAC
* Version dev :\main\branch_halouane_CoClLASl_dev\2 Date: 4/2/2011 15 h 16 m User:halouane
*    TWK_model:NO_MODEL
*    comments :delete static
* Version dev :\main\branch_halouane_CoClLASl_dev\1 Date: 4/2/2011 11 h 12 m User:halouane
*    TWK_model:NO_MODEL
*    comments :Update for 11.0
* Version int :/main/00PSASWC_EA/2 Date: 4/10/2010 14 h 21 m User:meme
*    TWK_model:NO_MODEL
*    comments :update DDS_lib
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 4/10/2010 14 h 7 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :update DDS_lib
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 4/10/2010 13 h 59 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl
* Version int :/main/00PSASWC_EA/1 Date: 1/9/2010 17 h 55 m User:esnault
*    TWK_model:NO_MODEL
*    comments :delete static
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 1/9/2010 10 h 0 m User:lemort
*    TWK_model:NO_MODEL
*    comments :delete static
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 1/9/2010 9 h 59 m User:lemort
*    TWK_model:NO_MODEL
*    comments :add CoClLASl_Timer_1ms_U32
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 31/8/2010 17 h 42 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 29/7/2010 17 h 33 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 39 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
*
*******************************************************************************/

#ifndef COCLLASL_H
#define COCLLASL_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_CoClLASl.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define COCLLASL_DDS_LIB_VERSION_REQ 270

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_


/* map size */
#define COCLLASL_2_SIZE                       2
#define COCLLASL_4_SIZE                       4
#define COCLLASL_6_SIZE                       6
#define COCLLASL_7_SIZE                       7
#define COCLLASL_8_SIZE                       8
#define COCLLASL_10_SIZE                      10
#define COCLLASL_12_SIZE                      12



/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

extern FUNC(void, AUTOMATIC) COCLLASL_Anti_Stall_Param(UInt8 CoPt_bCluDiEgdCord_swc_in,
                                           UInt32 EOM_tiEngRun_swc_in, /* BIN0 */
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 TqSys_bIdlAcvCmn_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_nTarDynIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqIdcReq_swc_in, /* BIN4 */
                                           SInt16 TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           SInt16 TreatTDC_nCkTDCDelta_swc_in, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallMan_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall1_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall2_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall3_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facTqCkAntiStall_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Bvm_Anti_Stall_Reg(UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt16 Ext_nEng1_swc_in, /* BIN2 */
                                           UInt16 Ext_nEng2_swc_in, /* BIN2 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_nTarDynIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqCkIdl_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkIdlMax_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkIdlMin_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAcvAntiStallMan_swc_in,
                                           UInt16 TqSys_facAntiStall1_swc_in, /* BIN14 */
                                           UInt16 TqSys_facAntiStall2_swc_in, /* BIN14 */
                                           UInt16 TqSys_facAntiStall3_swc_in, /* BIN14 */
                                           UInt16 TqSys_facTqCkAntiStall_swc_in, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAntiStall_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord(
                                           SInt16 EngLim_tqIdcAirResMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcAdvOptmTrbMax_swc_in, /* BIN4 */
                                           SInt16 TqDem_tqIdcLimNReg_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcAirLimCordWiRes_swc_in, /* BIN4 */
                                           UInt16 ThMgt_tqIdcLimReq_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLimAfterRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) ESLim_bAcvEngSpdLim_swc_out );

extern FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord_Sync(UInt8 CoPt_noGearCord_swc_in,
                                           SInt16 EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcPresUsThrMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSfty_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           SInt16 TqDem_tqIdcLimNReg_swc_in, /* BIN4 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkCurDrivFil_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcEngLimMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcMaxNReg_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim(SInt16 CoPt_tqIdcAirCord_nCross_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqIdcAirDslCord_nReg_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcAirLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcAirLimAfterRes_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           SInt16 IdlSys_tqIdcAirIdl_swc_in, /* BIN4 */
                                           SInt16 TqRes_tqMaxRes_swc_in, /* BIN4 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           SInt16 TqSys_tqCkIdlCord_swc_in, /* BIN4 */
                                           SInt16 IdlSys_tqIdcIdlAirSBPA_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWiRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWoutRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirReqUnlim_swc_out /* BIN0 */);


extern FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim_Sync(UInt8 CoPt_bSIPCord_swc_in,
                                           SInt16 CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
                                           UInt16 CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                                           UInt8 DfwCtl_bAcvLimTqIdl_swc_in,
                                           SInt16 EngLim_tqIdcColdSmkRaw_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 IdlSys_bAcvAntiStall_swc_in,
                                           UInt8 IdlSys_bAcvIdlCtl_swc_in,
                                           SInt16 IdlSys_tqIdcIdl_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAcvAntiStallAut_swc_in,
                                           UInt8 TqSys_bAcvAntiStallMan_swc_in,
                                           UInt8 TqSys_bIdlAcv_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt8 TqSys_facReqExhTempProt_swc_in, /* BIN7 */
                                           UInt8 TqSys_facReqFuelRunDry_swc_in, /* BIN7 */
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqCkAntiStall_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkIdl_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcLvlSBPA_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcSBPA_swc_in, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStall_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngUHNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bIdlAcvCmn_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCmn_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) IdlSys_tqIdcIdlAirSBPA_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcColdSmkCord_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Req_Cll_Opl_Gbl(UInt8 CoCha_bAcvCll_swc_in,
                                           UInt16 CoCha_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 CoCha_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 CoPt_bAcvCll_swc_in,
                                           UInt8 CoPt_noGearCordDrivFil_swc_in,
                                           UInt16 CoPt_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 CoPt_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 EngLim_bAcvCll_swc_in,
                                           UInt16 EngLim_tiTranCll_swc_in, /* DEC2 */
                                           SInt16 EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           UInt16 EngLim_tqIncCll_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 FRM_bInhTqCll_swc_in,
                                           UInt8 IdlSys_bAcvCll_swc_in,
                                           UInt16 IdlSys_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 IdlSys_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 TqRes_bAcvCll_swc_in,
                                           UInt16 TqRes_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 TqRes_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAOSAcv_swc_in,
                                           UInt8 TqSys_bAcvCll_swc_in,
                                           UInt8 TqSys_bEngNOnIdl_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_tiTranCll_swc_in, /* DEC2 */
                                           SInt16 TqSys_tqIdcAirReqGen_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcEngLimCord_swc_in, /* BIN4 */
                                           UInt16 TqSys_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 Eng_bAcvCllEngReq_swc_in,
                                           UInt8 TqAdvMin_bAcvCll_swc_in,
                                           UInt16 TqAdvMin_tqIncCll_swc_in, /* BIN4 */
                                           UInt16 TqAdvMin_tiTranCll_swc_in, /* DEC2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bAcvCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bForcCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bReqCllPtl_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLimCord_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Trq_Aos_Coord(SInt16 EngLim_tqCkCurDrivFil_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqAOSCVC_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkAOSCor_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkEngLimCord_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCord_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Bva_Bmp_Anti_Stall(UInt8 CoPt_bTqTx_swc_in,
                                           UInt8 CoPt_stCpl_swc_in,
                                           UInt8 CoBrk_bAcvBrk_swc_in,
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 FRM_bInhCoPtBrk_swc_in,
                                           UInt8 FRM_bInhCoPtSpdVeh_swc_in,
                                           UInt8 FRM_bInhCoPtStPt_swc_in,
                                           UInt8 FRM_bInhCoPtTCo_swc_in,
                                           SInt16 TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvAntiStallFil_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallSmk_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallAut_swc_out );

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */


/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) COCLLASL_Anti_Stall_Param_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallMan_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall1_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall2_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall3_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facTqCkAntiStall_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Bvm_Anti_Stall_Reg_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAntiStall_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLimAfterRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) ESLim_bAcvEngSpdLim_swc_out );

extern FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord_Sync_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkCurDrivFil_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcEngLimMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcMaxNReg_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWiRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWoutRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirReqUnlim_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim_Sync_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStall_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngUHNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bIdlAcvCmn_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCmn_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) IdlSys_tqIdcIdlAirSBPA_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcColdSmkCord_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Req_Cll_Opl_Gbl_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bAcvCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bForcCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bReqCllPtl_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLimCord_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Trq_Aos_Coord_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCord_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) COCLLASL_Bva_Bmp_Anti_Stall_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvAntiStallFil_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallSmk_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallAut_swc_out );

/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) CoClLASl_Timer_1ms_U32(void);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_COCLLASL_1MS_U32_TIME  CoClLASl_Timer_1ms_U32()

#define COCLLASL_STOP_SEC_CODE
#include "CoClLASl_MemMap.h"

#endif

