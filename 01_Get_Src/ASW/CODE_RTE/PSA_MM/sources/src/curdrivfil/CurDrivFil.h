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
* Ref X:\integration_view_00PSASWC_EB20D11\blois_psa_sstg\Software\Appli\CurDrivFil\src\CurDrivFil.h
* Version int :/main/00PSASWC_EB/2 Date: 19/11/2012 12 h 19 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :dev curdrivfil 12.0
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\2 Date: 16/11/2012 11 h 59 m User:halouane 
*    TWK_model:NO_MODEL
*    comments :dev curdrivfil 12.0
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\1 Date: 29/10/2012 11 h 56 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_morisseau_curdriv_euro6_dev\1 Date: 15/10/2012 14 h 52 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CurDrivFil 12.0
* Version int :/main/00PSASWC_EB/1 Date: 27/8/2010 10 h 47 m User:meme
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\5 Date: 21/7/2010 11 h 14 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\4 Date: 9/7/2010 17 h 9 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 9/7/2010 12 h 47 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 7/7/2010 15 h 50 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 25/6/2010 12 h 0 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil.h Euro-6
* Version int :/main/P2868/BR_06E0/2 Date: 8/10/2009 15 h 21 m User:esnault
*    TWK_model:LDCR_Application_06E020_IMPL1
*    comments :CurDrivFil.h, modification on range of "TreatTDC_nCkGrd"
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_3_0\4 Date: 5/10/2009 9 h 33 m User:veillard
*    TWK_model:LDCR_Application_06E020_SPEC1
*    comments :CurDrivFil.h, modification on range of "TreatTDC_nCkGrd"
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_3_0\3 Date: 28/9/2009 16 h 26 m User:veillard
*    TWK_model:LDCR_Application_06E020_SPEC1
*    comments :CurDrivFil.h, modification from last tracking sheet on CSCT_CGMT09_1958 V1.0
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_3_0\2 Date: 16/9/2009 14 h 14 m User:veillard
*    TWK_model:LDCR_Application_06E020_SPEC1
*    comments :CurDrivFil.h work in progress
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_3_0\1 Date: 13/8/2009 16 h 49 m User:veillard
*    TWK_model:LDCR_Application_06E020_SPEC1
*    comments :CurDrivFil.h en cours
* Version int :/main/P2868/BR_06E0/1 Date: 18/11/2008 18 h 51 m User:boucher
*    TWK_model:LDCR_Application_06E010_IMPL1
*    comments :DDS_lib has changed
* Version dev :\main\branch_moisan_curdrivfil_dev\2 Date: 17/11/2008 13 h 22 m User:moisan
*    TWK_model:LDCR_Application_06E010_IMPL1
*    comments :DDS_lib has changed
* Version dev :\main\branch_veillard_curdrivfil\1 Date: 20/10/2008 15 h 36 m User:veillard
*    TWK_model:LDCR_Application_06E010_IMPL1
*    comments :R6513106 v3.0
*
*******************************************************************************/



#ifndef CURDRIVFIL_H
#define CURDRIVFIL_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/
#define RTE_PTR2ARRAYBASETYPE_PASSING

#include "Rte_CurDrivFil.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define CURDRIVFIL_DDS_LIB_VERSION_REQ 410


/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

/* Ext_stGBxCf enumeration : SWC_IN */
#define BVM     (UInt32) 0
#define BVA     (UInt32) 1
#define BVMP    (UInt32) 2

/* TqSys_stAcceAOS  : SWC_OUT & SWC_IN */
#define CURDRIVFIL_DECELERATION                         (UInt32) 1
#define CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX      (UInt32) 2
#define CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX     (UInt32) 3

/* TqClrCros_stDetClr   : SWC_OUT */
#define CURDRIVFIL_DETECTION_INACTIF                (UInt32)0
#define CURDRIVFIL_DETECTION_EN_COURS               (UInt32)1
#define CURDRIVFIL_DETECTION_EFFECIF                (UInt32)2
#define CURDRIVFIL_FIN_DE_DETECTION                 (UInt32)3

/* CoPt_noGearCordDrivFil */
#define CURDRIVFIL_RAPPORT_EQUIVALENT_0        (UInt32)0
#define CURDRIVFIL_RAPPORT_EQUIVALENT_1        (UInt32)1
#define CURDRIVFIL_RAPPORT_EQUIVALENT_2        (UInt32)2
#define CURDRIVFIL_RAPPORT_EQUIVALENT_3        (UInt32)3
#define CURDRIVFIL_RAPPORT_EQUIVALENT_4        (UInt32)4
#define CURDRIVFIL_RAPPORT_EQUIVALENT_5        (UInt32)5
#define CURDRIVFIL_RAPPORT_EQUIVALENT_6        (UInt32)6
#define CURDRIVFIL_RAPPORT_EQUIVALENT_7        (UInt32)7
#define CURDRIVFIL_RAPPORT_EQUIVALENT_8        (UInt32)8

/* Vector */
#define CURDRIVFIL_NBRSAMPLING_SIZE         6

#define CURDRIVFIL_5_SIZE                   5
#define TQSYS_6_SIZE                        6
#define CURDRIVFIL_8_SIZE                   8
#define TQSYS_9_SIZE                        9
#define TQSYS_10_SIZE                       10
#define TQSYS_12_SIZE                       12

#ifdef _DDS_STATIC_
    #undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

/* For FS: Add static word */
#ifndef INLINE
    #define INLINE
#endif

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

/* On Engine Synchronisation */


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Accel_State(UInt8 CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                                    UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                                    UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                                    UInt8 TqSys_bAcceClrCrossAOS_swc_in,
                                                    UInt8 TqSys_bAcceDetAOS_swc_in,
                                                    UInt8 TqSys_bDeceDetAOS_swc_in,
                                                    SInt16 TqSys_nFil2AOS_swc_in, /* BIN2 */
                                                    UInt8 TqClrCros_stDetClr_swc_in,  /* BIN0 */
												   	SInt16 TqLimEM_tqLimEMTrv_swc_in, /*BIN4*/
												   	SInt16 TqSys_tqCkAOSCor_swc_in, /*BIN4*/
												   	SInt16 TqSys_tqCkDeceIni_swc_in, /*BIN4*/
												   	SInt16 TqSys_tqCkEfcFilTrv_swc_in, /*BIN4*/
                                         		  	SInt16 TqSys_tqThdPha3_swc_in, /*BIN4*/
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stAcceAOS_swc_out,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_prm_AOSConf3_swc_out);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Curatif_Param(
                                           UInt8  CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt16 CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                                           UInt8  EOM_bTWCHeatPha_swc_in,
                                           UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                           UInt8  Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8  TqSys_bEngNOnIdl_swc_in,
                                           CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC) TqSys_prm_AOSConf3_swc_in,/* tab[] BIN10 */
                                           UInt8  TqSys_stAcceAOS_swc_in,
                                           SInt16 TqSys_tqCkDeceIni_swc_in, /* BIN4 */
                                           SInt16 TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAOSSlopAcv_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncDiAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctOfsAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorGlbl_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorIdlPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorOxCHeatPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq2AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq3AOS_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) CURDRIVFIL_Aos_Func_Agr(UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                                       UInt16 Ext_nEngClc1_swc_in, /* BIN2 */
                                                       SInt16 TqSys_facSpd0AOS_swc_in, /* BIN10 */
                                                       SInt16 TqSys_facSpd1AOS_swc_in, /* BIN10 */
                                                       SInt16 TqSys_facTq0AOS_swc_in, /* BIN10 */
                                                       SInt16 TqSys_facTq1AOS_swc_in, /* BIN10 */
                                                       SInt16 TqSys_facTq2AOS_swc_in, /* BIN10 */
                                                       SInt16 TqSys_facTq3AOS_swc_in, /* BIN10 */
                                                       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nFil2AOS_swc_out, /* BIN2 */
                                                       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkFilRawAOS_swc_out /* BIN4 */);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Final_Curat_Corr(
													UInt16 CoPt_facAntiJerk_swc_in, /* BIN8 */
													UInt8 CoPt_noGearCordDrivFil_swc_in,
													SInt16 CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
													UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
													UInt8 Ext_stGBxCf_swc_in,
													SInt16 Ext_tCoMes_swc_in, /* BIN0 */
													UInt8 Ext_tiTDC_swc_in, /* DEC3 */
													UInt8 FRM_bInhAOS_swc_in,
													SInt16 TqLimEM_tqLimEMTrv_swc_in, /* BIN4 */
													UInt8 TqSys_bAOSSlopAcv_swc_in,
													UInt8 TqSys_bRstAOS_swc_in,
													UInt16 TqSys_ctIncAcvAOS_swc_in, /* BIN10 */
													UInt16 TqSys_ctIncDiAOS_swc_in, /* BIN10 */
													UInt16 TqSys_ctOfsAcvAOS_swc_in, /* BIN10 */
													SInt16 TqSys_facCorGlbl_swc_in, /* BIN4 */
													SInt16 TqSys_facCorIdlPha_swc_in, /* BIN4 */
													SInt16 TqSys_facCorOxCHeatPha_swc_in, /* BIN4 */
													SInt16 TqSys_nFil2AOS_swc_in, /* BIN2 */
													UInt8 TqSys_stAcceAOS_swc_in,
													SInt16 TqSys_tqCkDeceIni_swc_in, /* BIN4 */
													SInt16 TqSys_tqCkEngLimCord_swc_in, /* BIN4 */
													SInt16 TqSys_tqCkFilRawAOS_swc_in, /* BIN4 */
													SInt16 TqSys_tqCkIdlCord_swc_in, /* BIN4 */
													CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAOSAcv_swc_out,
													CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCor_swc_out /* BIN4 */);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Detect_Clr_Cross(UInt8 CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                                         UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                                         UInt16 Ext_nEngClc1_swc_in, /* BIN2 */
                                                         UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                                         SInt16 TqSys_tqCkEfcFilTrv_swc_in, /* BIN4 */
                                                         SInt16 TqSys_tqThdPha3_swc_in, /* BIN4 */
                                                         SInt16 TqSys_tqCkFilRawAOS_swc_in,
                                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_bAcvClrCross_swc_out,
                                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_stDetClr_swc_out);




extern FUNC(void, AUTOMATIC) CURDRIVFIL_Coor_Cut_Dyn_Sel(SInt8 CoCha_noCylCutAuth_swc_in, /* BIN0 */
                                                           UInt8 CoPt_bInjCutDynAuth1_swc_in,
                                                           UInt8 CoPt_bInjCutDynAuth2_swc_in,
                                                           UInt8 CoPt_bInjCutDynAuth3_swc_in,
                                                           SInt8 CoPt_noCylCutAuth_swc_in, /* BIN0 */
                                                           UInt8 CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                                           SInt16 CoPt_tqIdcCordLimBuf_tqGBx_swc_in, /* BIN4 */
                                                           UInt16 CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                                           UInt8 Ext_noCylEng_swc_in, /* BIN0 */
                                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                                           UInt8 TqCll_bForcCll_swc_in,
                                                           SInt8 TqSys_noCylCutAuth_swc_in, /* BIN0 */
                                                           SInt16 TqSys_tqCkDeceIni_swc_in, /* BIN4 */
                                                           SInt16 TqSys_tqCkEfcFilTrv_swc_in, /* BIN4 */
                                                           SInt16 TqSys_tqCkFilRawAOS_swc_in, /* BIN4 */
                                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInjCutDynReq_swc_out,
                                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthCord_swc_out /* BIN0 */);





/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) CurDrivFil_Timer_1ms_U32(void);


/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Accel_State_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stAcceAOS_swc_out,
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_prm_AOSConf3_swc_out);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Curatif_Param_Init(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAOSSlopAcv_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncDiAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctOfsAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorGlbl_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorIdlPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorOxCHeatPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq2AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq3AOS_swc_out /* BIN10 */);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Aos_Func_Agr_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nFil2AOS_swc_out, /* BIN2 */
                                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkFilRawAOS_swc_out /* BIN4 */);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Final_Curat_Corr_Init(
            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAOSAcv_swc_out,
            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCor_swc_out /* BIN4 */);


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Detect_Clr_Cross_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_bAcvClrCross_swc_out,
                                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_stDetClr_swc_out );


extern FUNC(void, AUTOMATIC) CURDRIVFIL_Coor_Cut_Dyn_Sel_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInjCutDynReq_swc_out,
                                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthCord_swc_out /* BIN0 */);


/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_CURDRIVFIL_1MS_U32_TIME CurDrivFil_Timer_1ms_U32()

#define CURDRIVFIL_STOP_SEC_CODE
#include "CurDrivFil_MemMap.h"

#endif

