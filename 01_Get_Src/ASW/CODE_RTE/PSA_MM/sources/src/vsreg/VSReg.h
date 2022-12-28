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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSReg.h
* Version int :/main/00PSASWC_D3/4 Date: 5/1/2012 11 h 23 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\3 Date: 21/11/2011 14 h 31 m User:demezil 
*    TWK_model:NO_MODEL
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 16/11/2011 15 h 20 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 16/11/2011 14 h 51 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSReg 12.0
* Version int :/main/00PSASWC_D3/3 Date: 25/8/2011 10 h 47 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\3 Date: 24/8/2011 15 h 31 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 19/7/2011 16 h 26 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 19/7/2011 12 h 33 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSReg 11.0
* Version int :/main/00PSASWC_D3/2 Date: 11/2/2011 12 h 47 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 10/2/2011 15 h 16 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSReg 10.0
* Version int :/main/00PSASWC_D3/1 Date: 28/1/2011 10 h 27 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\6 Date: 27/1/2011 15 h 48 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\5 Date: 23/12/2010 12 h 1 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\4 Date: 23/12/2010 10 h 20 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_xvv_vsreg\3 Date: 23/12/2010 9 h 39 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\2 Date: 20/12/2010 14 h 33 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 17/12/2010 16 h 31 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
*
*******************************************************************************/

#ifndef VSREG_H
#define VSREG_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_VSReg.h"
#include "SC.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define VSREG_DDS_LIB_VERSION_REQ 400

/*******************************************************************************
*  SWC Macro Definitions
*******************************************************************************/


#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

/* Scheduling */
#define VSREG_SCHEDULING_40MS                               40 /* ms DEC0 = s DEC3 */

/* map size */


/* VSCtl_stMonVSReg */
#define VSCTL_STMONVSREG_ARRET              (0)
#define VSCTL_STMONVSREG_VERIF              (1)
#define VSCTL_STMONVSREG_INIT               (2)
#define VSCTL_STMONVSREG_NOMINAL            (3)
#define VSCTL_STMONVSREG_DEFAUT_REV         (4)
#define VSCTL_STMONVSREG_DEFAUT_IRREV       (5)

/* CoPt_noEgdGearCordIt */
/* VSCtl_noGearEgd_DeacVSReg */
#define VSREG_COPT_NOEGDGEARCORDIT_MAR              (SInt32)(-1)
#define VSREG_COPT_NOEGDGEARCORDIT_NEUTRE           (SInt32)(0)
#define VSREG_COPT_NOEGDGEARCORDIT_1ER_RAPPORT      (SInt32)(1)
#define VSREG_COPT_NOEGDGEARCORDIT_2EME_RAPPORT     (SInt32)(2)
#define VSREG_COPT_NOEGDGEARCORDIT_3EME_RAPPORT     (SInt32)(3)
#define VSREG_COPT_NOEGDGEARCORDIT_4EME_RAPPORT     (SInt32)(4)
#define VSREG_COPT_NOEGDGEARCORDIT_5EME_RAPPORT     (SInt32)(5)
#define VSREG_COPT_NOEGDGEARCORDIT_6EME_RAPPORT     (SInt32)(6)
#define VSREG_COPT_NOEGDGEARCORDIT_7EME_RAPPORT     (SInt32)(7)
#define VSREG_COPT_NOEGDGEARCORDIT_8EME_RAPPORT     (SInt32)(8)

/* VSCtl_posnGBxDeacVSReg */
#define VSCTL_POSNGBXDEACVSREG_P                        (0)
#define VSCTL_POSNGBXDEACVSREG_R                        (1)
#define VSCTL_POSNGBXDEACVSREG_N                        (2)
#define VSCTL_POSNGBXDEACVSREG_DRIVE                    (3)
#define VSCTL_POSNGBXDEACVSREG_INTERMEDIAIRE_PR_OU_NR   (4)
#define VSCTL_POSNGBXDEACVSREG_INTERMEDIAIRE_ND         (5)
#define VSCTL_POSNGBXDEACVSREG_MODE_MANUEL              (6)
#define VSCTL_POSNGBXDEACVSREG_INDISPONIBLE             (7)

/* VSCtl_stCtl_aVehVSReg */
#define VSREG_VSCTL_STCTL_AVEHVSREG_ARRET               ((UInt32)0)
#define VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE            ((UInt32)1)
#define VSREG_VSCTL_STCTL_AVEHVSREG_TRANSITION          ((UInt32)2)

/* VSCtl_stFilSpdVehVSReg */
#define VSREG_VSCTL_STFILSPDVEHVSREG_ARRET              ((UInt32)0)
#define VSREG_VSCTL_STFILSPDVEHVSREG_NON_FILTREE        ((UInt32)1)
#define VSREG_VSCTL_STFILSPDVEHVSREG_FILTREE            ((UInt32)2)

/* VSCtl_stRec_stDeacVSRegReq1 */
/* VSCtl_stRec_stDeacVSRegReq2 */
#define VSCTL_STREC_STDEACVSREGREQ_ATTENTE                      ((UInt32)0)
#define VSCTL_STREC_STDEACVSREGREQ_MEMORISATION                 ((UInt32)1)
#define VSCTL_STREC_STDEACVSREGREQ_EFFACEMENT_DES_MEMOIRES      ((UInt32)2)

/* VSCtl_stSatAVehMinVSReg */
#define VSCTL_STSATAVEHMINVSREG_ARRET             ((UInt32)0)
#define VSCTL_STSATAVEHMINVSREG_NON_EFFECTIF_29   ((UInt32)1)
#define VSCTL_STSATAVEHMINVSREG_EFFECTIF_29       ((UInt32)2)
#define VSCTL_STSATAVEHMINVSREG_ACTIVATION_29     ((UInt32)3)

/* VSCtl_stSatJrkVehMinVSReg */
#define VSCTL_STSATJRKVEHMINVSREG_ARRET           ((UInt32)0)
#define VSCTL_STSATJRKVEHMINVSREG_NON_EFFECTIF    ((UInt32)1)
#define VSCTL_STSATJRKVEHMINVSREG_EFFECTIF        ((UInt32)2)

/* VSCtl_stVSRegExtd */
/* VSCtl_stVSRegPrev_DeacVSReg */
/* VSCtl_stVSReg_DeacVSReg */
#define VSREG_VSCTL_STVSREGEXTD_ARRET                   ((UInt32)0)
#define VSREG_VSCTL_STVSREGEXTD_INITIALISATION          ((UInt32)1)
#define VSREG_VSCTL_STVSREGEXTD_INHIBE                  ((UInt32)2)
#define VSREG_VSCTL_STVSREGEXTD_ATTENTE                 ((UInt32)3)
#define VSREG_VSCTL_STVSREGEXTD_ACTIF_NON_EFFECTIF      ((UInt32)4)
#define VSREG_VSCTL_STVSREGEXTD_ACTIF_EFFECTIF          ((UInt32)5)
#define VSREG_VSCTL_STVSREGEXTD_REPRISE                 ((UInt32)6)
#define VSREG_VSCTL_STVSREGEXTD_DEFAUT                  ((UInt32)7)

/* VSCtl_bCtlCmdPTTqCf_SC */
#define VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE           (1)
#define VSCTL_BCTLCMDPTTQCF_SC_COUPLE_MOTEUR         (0)
/*******************************************************************************
*  SWC Level Type Definitions
*******************************************************************************/

/* None */


/*******************************************************************************
*  RUN & SWC Global Function Prototype Region
*******************************************************************************/
#define VSREG_START_SEC_CODE
#include "VSReg_MemMap.h"

/*******************************************************************************/
/* VSREG_Brake_Cond_Sl.c */
extern FUNC(void, AUTOMATIC) VSREG_F21221_Determiner_Condition_Appui_Pedale_Frein(
                                                      UInt8 Ext_bBrkPedPrss_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F21222_Determiner_Condition_Serrage_Frein_Main(
                                                      UInt8 Ext_bPrkBrk_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F21223_Determiner_Condition_Freinage_Automatique(
                                                      UInt8 Brk_bBrkAuto_swc_in,
                                                      UInt8 Ext_bBrkAutoCf_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F21224_Determiner_Condition_Freinage_Dynamique(
                                                      UInt8 Brk_bBrkDyn_swc_in,
                                                      UInt8 Ext_bBrkDynCf_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F21229_Determiner_Condition_Alerte_Pneumatiques(
                                                      UInt8 Ext_bTyreWarn_swc_in,
                                                      UInt8 Ext_bTyreWarnCf_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F2122a_Determiner_Conditions_Maintenance_Frein_Las(void);

extern FUNC(void, AUTOMATIC) VSREG_Brake_Cond_Sl_Init(void);

/*******************************************************************************/
/* VSREG_Gmp_Cond_Calc_Sl.c */
extern FUNC(void, AUTOMATIC) VSREG_F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite(
                                             UInt8 Ext_bKeyOff_swc_in,
                                             UInt8 FRM_bDeacIrvVSReg_swc_in,
                                             UInt8 FRM_bDeacRvVSReg_swc_in,
                                             UInt8 SftyMgt_bDeacIrvVSReg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F212115_Determiner_Conditions_Maintenance_Gmp(void);

extern FUNC(void, AUTOMATIC) VSREG_F2121231_Determiner_Conditions_Maintenance_Gmp(void);

extern FUNC(void, AUTOMATIC) VSREG_F21213_Determiner_Conditions_Fonctionnement_Gmp(void);

extern FUNC(void, AUTOMATIC) VSREG_Gmp_Cond_Calc_Sl_Init(void);

/*******************************************************************************/
/* VSREG_Veh_Running_Cond_Sl.c */
extern FUNC(void, AUTOMATIC) VSREG_F21234_Determiner_Condition_Conditions_Maintenance_Vehicule(void);

extern FUNC(void, AUTOMATIC) VSREG_F21247_Determiner_Condition_Conditions_Maintenance_Fonction(
                                             UInt8 FRM_bInhVSReg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F2141_Determiner_Diagnostic_Fonctionnel_Habitacle(
                                             UInt8 Ext_spdVehVSRegReq_swc_in,
                                             UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                                             UInt8 Ext_stModRegVSCtlReq_swc_in,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSRegBody_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSRegBody_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_F2151_Determiner_Conditions_Maintenance_Rvv(
                                             UInt8 VSCtl_stDeacVSCtlInfo_swc_in,
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no1_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no2_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no1_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no2_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) VSREG_F2153_Determiner_Contexte_Maintenance_Rvv(
                                             UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                             UInt32 Ext_dstVehTotMes_swc_in, /* BIN0 */
                                             SInt8 CoPt_noEgdGearCordIt_swc_in,
                                             UInt8 CoPt_posnLev_swc_in,
                                             UInt8 Ext_spdVehVSRegReq_swc_in, /* BIN0 */
                                             SInt16 VSCtl_aVehVSRegReq_swc_in, /* BIN10 */
                                             SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                                             SInt16 VSCtl_jrkVeh_swc_in, /* BIN7 */
                                             SInt16 VSCtl_rSlop_swc_in, /* BIN7 */
                                             UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                             UInt8 VSCtl_stVSRegExtd_swc_in,
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_DeacVSReg_swc_out, /* BIN10 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSReg_swc_out, /* BIN10 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSReg_swc_out, /* BIN0 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSReg_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSReg_swc_out,
                                             CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSReg_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSReg_DeacVSReg_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Veh_Running_Cond_Sl_Init(
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_DeacVSReg_swc_out, /* BIN10 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSReg_swc_out, /* BIN10 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegBody_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegBody_swc_out,
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSReg_swc_out, /* BIN0 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSReg_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSReg_swc_out,
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSReg_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no1_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no2_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no1_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no2_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSReg_DeacVSReg_swc_out);

/*******************************************************************************/
/* VSREG_Veh_Speed_Control_Sl.c */
extern FUNC(void, AUTOMATIC) VSREG_F2212_Determiner_Consigne_Vitesse_Vehicule(
                                                 SInt8 CoPt_noEgdGearCordIt_swc_in,
                                                 UInt8 Ext_spdVehVSRegReq_swc_in, /* BIN0 */
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSReg_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSREG_F222221_Determiner_Saturation_Acceleration_Vehicule_Max(
                                                 SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F222222_Determiner_Saturation_Acceleration_Vehicule_Min(
                                                 SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F22223_Determiner_Saturations_Jerk_Vehicule(
                                                 SInt16 VSCtl_aVehPreCoVSCtlReq_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                                                 UInt16 VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F22224_Determiner_Gabarits_Acceleration_Vehicule(
                                                 SInt16 VSCtl_aVehPTIni_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_F22232_Determiner_Consigne_Acceleration_Vehicule(
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) VSREG_F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                                                 UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSRegReq_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) VSREG_F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp(
                                                 UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSReg_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSREG_F2234_Determiner_Temps_Confirmation_Changement_Rapport(
                                                 SInt16 VSCtl_aVehPotVSRegReq_swc_in, /* BIN10 */
                                                 UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReq_swc_out, /* DEC2 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSRegReq_swc_out /* DEC2 */);

extern FUNC(void, AUTOMATIC) VSREG_Veh_Speed_Control_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSReg_swc_out, /* BIN7 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_swc_out, /* BIN10 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSRegReq_swc_out, /* BIN10 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSReg_swc_out, /* BIN4 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSRegReq_swc_out, /* DEC2 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReq_swc_out /* DEC2 */);


/*******************************************************************************/
/* VSREG_Re002tev_Sf.c */

extern FUNC(void, AUTOMATIC) VSREG_Det_Init_Secu_Fct_Sf(UInt8 Ext_stModRegVSCtlReq_swc_in,
                               UInt8 FRM_bDeacRvVSReg_swc_in,
                               UInt8 VSCtl_stVSCtlInfo_swc_in,
                               UInt8 FRM_bDeacIrvVSReg_swc_in,
                               UInt8 Ext_stDVSRegCf_swc_in,
                               UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                               UInt8 SftyMgt_bDeacIrvVSReg_swc_in,
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt8 Ext_bKeyOff_swc_in,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSReg_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Det_Init_Secu_Fct_Sf_Init(
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSReg_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSReg_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Gmp_Sf(UInt8 Ext_stGBxCf_swc_in,
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                   /*BIN0*/
                               SInt16 VSCtl_grdRatConvTra_swc_in,                   /*BIN1*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               UInt32 VSCtl_nEngFil_swc_in,                         /*BIN0*/
                               UInt8 VSCtl_stCtl_noGear_swc_in,
                               UInt8 Ext_stDirMoveVeh_swc_in,
                               UInt16 TqSys_nTarIdl_swc_in,                         /*BIN2*/
                               UInt8 VSCtl_bAvlTqWhlPT_no1_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no2_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               UInt8 VehEst_bORng_nPT_swc_in,
                               UInt8 Ext_bCluPedPrss_swc_in,
                               UInt8 Ext_stDirMoveVehReq_swc_in,
                               UInt8 Ext_stDirMoveVehCf_swc_in,
                               UInt16 VSCtl_rConvTra_swc_in,                        /*BIN7*/
                               UInt8 CoPt_posnLev_swc_in,
                               UInt8 Ext_bPosnGBxCf_swc_in,
                               UInt8 CoPTSt_stEng_swc_in,
                               SInt8 CoPt_noTarGearCordIt_swc_in,                   /*BIN0*/
                               UInt8 VSCtl_bNbGearEgdChg_swc_in);

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Gmp_Sf_Init(void);

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Brk_Sf(UInt8 Ext_bABSCf_swc_in,
                               UInt8 Ext_bBrkPedPrss_swc_in,
                               UInt8 Ext_bBrkAutoCf_swc_in,
                               UInt8 Ext_bBrkDynCf_swc_in,
                               UInt8 Ext_bASRReg_swc_in,
                               UInt8 Ext_bABSReg_swc_in,
                               UInt8 Ext_bTyreWarnCf_swc_in,
                               UInt8 Ext_bESPReg_swc_in,
                               UInt8 Brk_bBrkAuto_swc_in,
                               UInt8 Ext_bASRESPCf_swc_in,
                               UInt8 Brk_bBrkDyn_swc_in,
                               UInt16 VSCtl_rWhlSlip_no1_swc_in, /*BIN7*/
                               UInt8 Ext_bTyreWarn_swc_in,
                               UInt8 Ext_bPrkBrk_swc_in,
                               UInt16 VSCtl_rWhlSlip_no2_swc_in); /*BIN7*/

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Brk_Sf_Init(void);

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Veh_Sf(UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                               SInt16 VSCtl_jrkVeh_swc_in, /*BIN7*/
                               UInt8 Ext_bVehCollWarn_swc_in,
                               SInt16 VSCtl_aVehPTMin_swc_in, /*BIN10*/
                               SInt16 VSCtl_aVehPTMax_swc_in, /*BIN10*/
                               UInt8 Ext_spdVehVSRegReq_swc_in, /*BIN0*/
                               UInt8 VSCtl_bCtlaTqPT_swc_in,
                               UInt16 Veh_spdVeh_swc_in, /*BIN7*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_aVeh_swc_in,
                               SInt16 VSCtl_aVeh_swc_in); /*BIN10*/

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Veh_Sf_Init(void);

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Fct_Sf(
                               UInt8 Ext_stModRegVSCtlReq_swc_in,
                               UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                               UInt8 FRM_bInhVSReg_swc_in,
                               UInt16 Veh_spdVeh_swc_in,                            /*BIN7*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_aVeh_swc_in,
                               UInt16 AccP_rAccP_swc_in,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDrvOvrdVSReg_spdVeh_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Det_Cond_Fct_Fct_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDrvOvrdVSReg_spdVeh_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Det_Fct_Diag_Mnt_Sf(UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                               UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                          /*BIN0*/
                               UInt8 Ext_stModRegVSCtlReq_swc_in,
                               UInt8 Ext_spdVehVSRegReq_swc_in,                            /*BIN0*/
                               SInt16 VSCtl_aVeh_swc_in,                                   /*BIN10*/
                               SInt16 VSCtl_jrkVeh_swc_in,                                 /*BIN7*/
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 VSCtl_stDeacVSCtlInfo_swc_in,
                               UInt32 Ext_dstVehTotMes_swc_in,                             /*BIN0*/
                               SInt16 VSCtl_rSlop_swc_in,                                  /*BIN7*/
                               UInt8 Afts_bRst_stDeacVSRegReq1_swc_in,
                               UInt8 Afts_bRst_stDeacVSRegReq2_swc_in,
                               UInt8 CoPt_posnLev_swc_in,
                               SInt16 VSCtl_aVehVSRegReq_swc_in,                           /*BIN10*/
                               UInt16 AccP_rAccP_swc_in,                                   /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSReg_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSReg_swc_out,                 /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegBody_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSReg_swc_out,                      /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSReg_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_DeacVSReg_swc_out,                 /*BIN10*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSReg_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSReg_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegBody_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no2_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegVeh_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq1_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no2_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Det_Fct_Diag_Mnt_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSReg_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSReg_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSReg_swc_out,                 /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegBody_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSReg_swc_out,                      /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSReg_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_DeacVSReg_swc_out,                 /*BIN10*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSReg_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSReg_DeacVSReg_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegBody_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqHi_no2_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegVeh_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no1_swc_out,                   /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSRegReq1_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSReg_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSRegReqLo_no2_swc_out);                   /*BIN0*/

extern FUNC(void, AUTOMATIC) VSREG_Ctrl_Spd_Veh_Sf(UInt8 VSCtl_bEndTranVSReg_swc_in,
                               UInt8 Ext_stGBxCf_swc_in,
                               UInt8 FRM_bDeacSatMaxSpdVehVSReg_swc_in,
                               SInt16 VSCtl_aVehPTIni_swc_in,                              /*BIN10*/
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt16 VSCtl_rTqWhlPTDrvReq_swc_in,                         /*BIN7*/
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                          /*BIN0*/
                               SInt16 VSCtl_aVehReq_swc_in,                                /*BIN10*/
                               SInt16 VSCtl_aVehPTMin_swc_in,                              /*BIN10*/
                               UInt8 Ext_spdVehVSRegReq_swc_in,                            /*BIN0*/
                               SInt16 VSCtl_aVehPTMax_swc_in,                              /*BIN10*/
                               UInt8 VSCtl_stVSCtlInfo_swc_in,
                               SInt16 VSCtl_rSlop_swc_in,                           /*BIN7*/
                               SInt16 VSCtl_aVehPreCoVSCtlReq_swc_in,                      /*BIN10*/
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSRegReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSRegReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSReg_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSRegReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSReg_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSReg_swc_out);

extern FUNC(void, AUTOMATIC) VSREG_Ctrl_Spd_Veh_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSRegReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSRegReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSReg_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSRegReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSReg_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSRegReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSReg_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSReg_swc_out);

/*******************************************************************************/
/* */

/* SWC Global Function */
extern FUNC(UInt32, AUTOMATIC) VSReg_Timer_1ms_U32(void);
extern FUNC(UInt32, AUTOMATIC) VSReg_Timer_1s_U32(void);

/*******************************************************************************
*  RUN & SWC Initialisation Function Prototypes Region
*******************************************************************************/

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_VSREG_1MS_U32_TIME VSReg_Timer_1ms_U32()
#define DDS_VSREG_1S_U32_TIME  VSReg_Timer_1s_U32()
#define DDS_VSREG_1MIN_U32_TIME (DDS_VSREG_1S_U32_TIME / 60U)

extern UInt32 FRunTime_GetTimer1usU32 (void);
extern Std_ReturnType FRunTime_GetTimer1sU32(P2VAR(UInt32, AUTOMATIC, AUTOMATIC) CurrentTime1sPtr);
extern Std_ReturnType FRunTime_GetTimer1msU32(P2VAR(UInt32, AUTOMATIC, AUTOMATIC) CurrentTime1msPtr);
extern Std_ReturnType FRunTime_GetTimer1minU32(P2VAR(UInt32, AUTOMATIC, AUTOMATIC) CurrentTime1minPtr);

#endif

