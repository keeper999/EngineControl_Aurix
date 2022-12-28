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
* Ref X:\integration_view_00PSASWC_D620D01\blois_psa_sstg\Software\Appli\VSMax\src\VSMax.h
* Version int :/main/00PSASWC_D6/4 Date: 6/1/2012 12 h 3 m User:meme 
*    TWK_model:NO_MODEL
*    comments :for VSMax 12.0
* Version dev :\main\branch_demezil_vsmax_view\1 Date: 24/11/2011 14 h 59 m User:demezil 
*    TWK_model:NO_MODEL
*    comments :for VSMax 12.0
* Version dev :\main\branch_morisseau_xvv_vsmax_e6_dev\1 Date: 24/11/2011 11 h 58 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSMax
* Version int :/main/00PSASWC_D6/3 Date: 25/8/2011 10 h 47 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\4 Date: 25/8/2011 9 h 18 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\3 Date: 1/8/2011 15 h 48 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\2 Date: 18/7/2011 14 h 38 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\1 Date: 18/7/2011 10 h 47 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSMax 11.0
* Version int :/main/00PSASWC_D6/2 Date: 3/2/2011 15 h 8 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\4 Date: 24/1/2011 11 h 38 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\3 Date: 24/1/2011 10 h 16 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 17/1/2011 17 h 52 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\1 Date: 17/12/2010 14 h 13 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev VSMax 10.0
*
*******************************************************************************/

#ifndef VSMAX_H
#define VSMAX_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_VSMax.h"
#include "SC.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define VSMAX_DDS_LIB_VERSION_REQ 400


/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

#define EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED           (1)
#define EXT_STCTLCMDPTTQPOTCF_DESACTIVE             (0)
#define EXT_STCTLCMDPTTQPOTCF_COUPLE                (2)
#define EXT_STCTLCMDPTTQPOTCF_RAPPORT               (3)
#define EXT_STGBXCF_BVM                             (0)
#define EXT_STGBXCF_BVMP                            (2)
#define EXT_STGBXCF_BVA                             (1)
#define VSCTL_NOGEAREGD_DEACVSMAX_6EME_RAPPORT      (6)
#define VSCTL_NOGEAREGD_DEACVSMAX_MARCHE_ARRIERE    (7)
#define VSCTL_NOGEAREGD_DEACVSMAX_3EME_RAPPORT      (3)
#define VSCTL_NOGEAREGD_DEACVSMAX_AUTRES_VALEURS    (8)
#define VSCTL_NOGEAREGD_DEACVSMAX_4EME_RAPPORT      (4)
#define VSCTL_NOGEAREGD_DEACVSMAX_NEUTRE            (0)
#define VSCTL_NOGEAREGD_DEACVSMAX_5EME_RAPPORT      (5)
#define VSCTL_NOGEAREGD_DEACVSMAX_1ER_RAPPORT       (1)
#define VSCTL_NOGEAREGD_DEACVSMAX_2EME_RAPPORT      (2)
#define VSCTL_BTCTL_AVEHPOTVSMAX_ARRET              (0)
#define VSCTL_STCTL_AVEHVSMAX_CONTROLE              (1)
#define VSCTL_STCTL_AVEHVSMAX_ARRET                 (0)
#define VSCTL_STCTL_AVEHVSMAX_TRANSITION            (2)
#define VSCTL_STDVSREGEXTD_RERSERVE                 (6)
#define VSCTL_STDVSREGEXTD_DEFAUT                   (7)
#define VSCTL_STDVSREGEXTD_ATTENTE                  (3)
#define VSCTL_STDVSREGEXTD_ACTIF_NON_EFFECTIF       (4)
#define VSCTL_STDVSREGEXTD_ACTIF_EFFECTIF           (5)
#define VSCTL_STDVSREGEXTD_INHIBE                   (2)
#define VSCTL_STDVSREGEXTD_ARRET                    (0)
#define VSCTL_STDVSREGEXTD_INITIALISATION           (1)
#define VSCTL_STMONVSMAX_INIT                       (2)
#define VSCTL_STMONVSMAX_VERIF                      (1)
#define VSCTL_STMONVSMAX_NOMINAL                    (3)
#define VSCTL_STMONVSMAX_DEFAUT_REV                 (4)
#define VSCTL_STMONVSMAX_DEFAUT_IRREV               (5)
#define VSCTL_STMONVSMAX_ARRET                      (0)
#define VSCTL_STSATAVEHMINVSMAX_NON_EFFECTIF_30     (2)
#define VSCTL_STSATAVEHMINVSMAX_EFFECTIF_30         (3)
#define VSCTL_STSATAVEHMINVSMAX_INIT_30             (1)
#define VSCTL_STSATAVEHMINVSMAX_ACTIVATION_30       (4)
#define VSCTL_STSATAVEHMINVSMAX_ARRET               (0)
#define VSCTL_STSPDVEHCRITFILMODCLC_BLOQUE_18       (2)
#define VSCTL_STSPDVEHCRITFILMODCLC_INIT_18         (1)
#define VSCTL_STSPDVEHCRITFILMODCLC_ARRET           (0)
#define VSCTL_STSPDVEHCRITMODCLC_EFFECTIF_17        (2)
#define VSCTL_STSPDVEHCRITMODCLC_NON_EFFECTIF_17    (1)
#define VSCTL_STSPDVEHCRITMODCLC_ARRET              (0)
#define VSCTL_STVSCTLINFO_NOMINAL                   (3)
#define VSCTL_STVSCTLINFO_VERIF                     (1)
#define VSCTL_STVSCTLINFO_DEFAUT_20                 (4)
#define VSCTL_STVSCTLINFO_INIT                      (2)
#define VSCTL_STVSCTLINFO_ARRET                     (0)
#define VSCTL_STVSMAX_DEACVSMAX_DEFAUT              (7)
#define VSCTL_STVSMAX_DEACVSMAX_ATTENTE             (3)
#define VSCTL_STVSMAX_DEACVSMAX_ACTIF_NON_EFFECTIF  (4)
#define VSCTL_STVSMAX_DEACVSMAX_ACTIF_EFFECTIF      (5)
#define VSCTL_STVSMAX_DEACVSMAX_INHIBE              (2)
#define VSCTL_STVSMAX_DEACVSMAX_REPRISE             (6)
#define VSCTL_STVSMAX_DEACVSMAX_ARRET               (0)
#define VSCTL_STVSMAX_DEACVSMAX_INITIALISATION      (1)
#define EXT_BVSMAXFCF_PRESENT                       (1)
#define EXT_BVSMAXFCF_ABSENT                        (0)
#define EXT_BVSMAXFCF_PRESENT                       (1)
#define EXT_BVSMAXSCF_PRESENT                       (1)
#define EXT_BVSMAXPCF_PRESENT                       (1)

#define VSC_16_SIZE                             (16)
#define VSC_8_SIZE                              (8)

#define VSMAX_0                                 (0)
#define VSMAX_1_BIN7                            (1 * BIN7)
#define VSMAX_10_BIN10                          (10 * BIN10)
#define VSMAX_100_BIN7                          (100 * BIN7)
#define VSMAX_255_BIN7                          (255 * BIN7)

#define VSMAX_SCHEDULING                        (UInt32)(40) /* VSMax scheduling = 40ms */


/* VSCtl_stVSMaxExtd */

#define VSCTL_STVSMAXEXTD_ARRET             (0)
#define VSCTL_STVSMAXEXTD_INITIALISATION    (1)
#define VSCTL_STVSMAXEXTD_INHIBEE           (2)
#define VSCTL_STVSMAXEXTD_ATTENTE           (3)
#define VSCTL_STVSMAXEXTD_ANE               (4)
#define VSCTL_STVSMAXEXTD_AE                (5)
#define VSCTL_STVSMAXEXTD_REPRISE           (6)
#define VSCTL_STVSMAXEXTD_DEFAUT            (7)

/* CoPt_noEgdGearCordIt */
/* VSCtl_noGearEgd_DeacVSMax */
#define VSMAX_COPT_NOEGDGEARCORDIT_MAR              (SInt32)(-1)
#define VSMAX_COPT_NOEGDGEARCORDIT_NEUTRE           (SInt32)(0)
#define VSMAX_COPT_NOEGDGEARCORDIT_1ER_RAPPORT      (SInt32)(1)
#define VSMAX_COPT_NOEGDGEARCORDIT_2EME_RAPPORT     (SInt32)(2)
#define VSMAX_COPT_NOEGDGEARCORDIT_3EME_RAPPORT     (SInt32)(3)
#define VSMAX_COPT_NOEGDGEARCORDIT_4EME_RAPPORT     (SInt32)(4)
#define VSMAX_COPT_NOEGDGEARCORDIT_5EME_RAPPORT     (SInt32)(5)
#define VSMAX_COPT_NOEGDGEARCORDIT_6EME_RAPPORT     (SInt32)(6)
#define VSMAX_COPT_NOEGDGEARCORDIT_7EME_RAPPORT     (SInt32)(7)
#define VSMAX_COPT_NOEGDGEARCORDIT_8EME_RAPPORT     (SInt32)(8)

/* VSCtl_posnGBxDeacVSReg */
#define VSCTL_POSNGBXDEACVSMAX_P                        (0)
#define VSCTL_POSNGBXDEACVSMAX_R                        (1)
#define VSCTL_POSNGBXDEACVSMAX_N                        (2)
#define VSCTL_POSNGBXDEACVSMAX_DRIVE                    (3)
#define VSCTL_POSNGBXDEACVSMAX_INTERMEDIAIRE_PR_OU_NR   (4)
#define VSCTL_POSNGBXDEACVSMAX_INTERMEDIAIRE_ND         (5)
#define VSCTL_POSNGBXDEACVSMAX_MODE_MANUEL              (6)
#define VSCTL_POSNGBXDEACVSMAX_INDISPONIBLE             (7)


  /* VSCtl_stVSMax_DeacVSMax */
  /* VSCtl_stVSMaxPrev_DeacVSMax */
#define VSMAX_STVSMAX_DEAC_ARRET                (0)
#define VSCTL_STVSMAXPREV_AE                    (5)
#define VSCTL_STVSMAXPREV_DEFAUT                (7)
#define VSCTL_STVSMAXPREV_ATTENTE               (3)
#define VSCTL_STVSMAXPREV_INHIBE                (2)
#define VSCTL_STVSMAXPREV_ANE                   (4)
#define VSCTL_STVSMAXPREV_REPRISE               (6)
#define VSCTL_STVSMAXPREV_ARRET                 (0)
#define VSCTL_STVSMAXPREV_INITIALISATION        (1)
#define VSCTL_STVSMAXPREV_DEACVSMAX_ARRET       (0)

 /* VSCtl_stCtl_aVehVSMax */
#define VSMAX_STCTL_AVEHVSMAX_ARRET                 (0)
#define VSMAX_STCTL_AVEHVSMAX_CONTROLE              (1)
#define VSMAX_STCTL_AVEHVSMAX_TRANSITION            (2)



  /* VSCtl_stSatJrkVehMaxVSMax */
#define VSCTL_STSATJRKVEHMAXVSMAX_ARRET             (0)
#define VSCTL_STSATJRKVEHMAXVSMAX_NON_EFFECTIF      (1)
#define VSCTL_STSATJRKVEHMAXVSMAX_EFFECTIF          (2)

  /* VSCtl_stSatJrkVehMinVSMax */
#define VSCTL_STSATJRKVEHMINVSMAX_ARRET             (0)
#define VSCTL_STSATJRKVEHMINVSMAX_NON_EFFECTIF      (1)
#define VSCTL_STSATJRKVEHMINVSMAX_EFFECTIF          (2)

  /* VSCtl_stSatAVehMinVSMax */
#define VSMAX_STSATAVEHMINVSMAX_ARRET               (0)
#define VSMAX_STSATAVEHMINVSMAX_INIT                (1)
#define VSMAX_STSATAVEHMINVSMAX_NON_EFFECTIF        (2)
#define VSMAX_STSATAVEHMINVSMAX_EFFECTIF            (3)
#define VSMAX_STSATAVEHMINVSMAX_ACTIVATION          (4)


  /* VSCtl_bCtl_aVehPotVSMax */
#define VSCTL_BCTL_AVEHPOTVSMAX_ARRET               (0)
#define VSCTL_BCTL_AVEHPOTVSMAX_CONTROLE            (1)

  /* VSCtl_stRec_stDeacVSMaxReq1 */
#define VSCTL_STREC_STDEACVSMAXREQ1_ATTENTE         (0)
#define VSCTL_STREC_STDEACVSMAXREQ1_CAPTURE         (1)
#define VSCTL_STREC_STDEACVSMAXREQ1_RESET           (2)
/* VSCtl_stRec_stDeacVSMaxReq2 */
#define VSCTL_STREC_STDEACVSMAXREQ2_ATTENTE         (0)
#define VSCTL_STREC_STDEACVSMAXREQ2_CAPTURE         (1)
#define VSCTL_STREC_STDEACVSMAXREQ2_RESET           (2)




#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define VSMAX_START_SEC_CODE
#include "VSMax_MemMap.h"


extern FUNC(void, AUTOMATIC) VSMAX_F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite(
                            UInt8 Ext_bKeyOff_swc_in,
                            UInt8 FRM_bDeacIrvVSMax_swc_in,
                            UInt8 FRM_bDeacRvVSMax_swc_in);

extern FUNC(void, AUTOMATIC) VSMAX_F51211_Determiner_Condition_Alerte_Pneumatiques(
                            UInt8 Ext_bTyreWarn_swc_in,
                            UInt8 Ext_bTyreWarnCf_swc_in);

extern FUNC(void, AUTOMATIC) VSMAX_F51212_Determiner_Conditions_Maintenance_Frein_Las(void);

extern FUNC(void, AUTOMATIC) VSMAX_F51223_Determiner_Condition_Conditions_Maintenance_Fonction(
                            UInt8 FRM_bInhVSMax_swc_in);

extern FUNC(void, AUTOMATIC) VSMAX_F5151_Determiner_Conditions_Maintenance_Bvv(
                            UInt8 VSCtl_stDeacVSCtlInfo_swc_in, /* BIN0 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no1_swc_out, /* BIN0 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no2_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) VSMAX_F5153_Determiner_Contexte_Maintenance_Bvv(
                            UInt16 AccP_rAccP_swc_in, /* BIN7 */
                            UInt32 Ext_dstVehTotMes_swc_in, /* BIN0 */
                            SInt8 CoPt_noEgdGearCordIt_swc_in, /* Enum */
                            UInt8 CoPt_posnLev_swc_in, /* Enum */
                            SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehVSMaxReq_swc_in, /* BIN10 */
                            SInt16 VSCtl_jrkVeh_swc_in, /* BIN7 */
                            SInt16 VSCtl_rSlop_swc_in, /* BIN7 */
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt16 VSCtl_spdVehVSMaxReq_swc_in, /* BIN7 */
                            UInt8 VSCtl_stVSMaxExtd_swc_in, /* Enum */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_DeacVSMax_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSMax_swc_out, /* BIN10 */
                            CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSMax_swc_out, /* BIN0 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSMax_swc_out, /* Enum */
                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSMax_swc_out, /* Enum */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMaxPrev_DeacVSMax_swc_out, /* Enum */
                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMax_DeacVSMax_swc_out /* Enum */);

extern FUNC(void, AUTOMATIC) VSMAX_F5211_Determiner_Consigne_Vitesse_Bvvf(
                            UInt8 Ext_bVSMaxfCf_swc_in,
                            UInt8 FRM_bDeacRvVSMaxf_swc_in);

extern FUNC(void, AUTOMATIC) VSMAX_F5212_Determiner_Consigne_Vitesse_Bvvp(
                            UInt8 Ext_bVSMaxpCf_swc_in,
                            UInt8 Ext_spdVehVSMaxPrmaReq_swc_in,
                            UInt8 FRM_bDeacRvVSMaxp_swc_in);

extern FUNC(void, AUTOMATIC) VSMAX_F5213_Determiner_Consigne_Vitesse_Bvvs(
                            UInt8 Ext_bVSMaxsCf_swc_in,
                            UInt8 FRM_bAcvVSMax_no1_swc_in,
                            UInt8 FRM_bAcvVSMax_no2_swc_in);

extern FUNC(void, AUTOMATIC) VSMAX_F52142_Determiner_Consigne_Vitesse_Bvvc(
                            UInt8 VehEst_spdVehCrit_swc_in, /* BIN0 */
                            UInt16 VSCtl_spdVeh_swc_in /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSMAX_F5215_Determiner_Consigne_Vitesse_Vehicule(
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt8 VSCtl_stVSMaxExtd_swc_in, /* Enum */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehVSMaxReq_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSMAX_F522221_Determiner_Saturations_Acceleration_Vehicule_Max(
                            SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */);

extern FUNC(void, AUTOMATIC) VSMAX_F522222_Determiner_Saturations_Acceleration_Vehicule_Min(
                            SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */);

extern FUNC(void, AUTOMATIC) VSMAX_F52223_Determiner_Saturations_Jerk_Vehicule(
                            SInt16 VSCtl_aVehCordVSLimReq_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                            UInt16 VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */);

extern FUNC(void, AUTOMATIC) VSMAX_F52224_Determiner_Gabarits_Acceleration_Vehicule(
                            SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */);

extern FUNC(void, AUTOMATIC) VSMAX_F52232_Determiner_Consigne_Acceleration_Vehicule(
                            SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in, /* Enum */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) VSMAX_F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                            UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in, /* Enum */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSMaxReq_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSMAX_F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp(
                            UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in, /* Enum */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSMax_swc_out /* BIN10 */);

extern FUNC(void, AUTOMATIC) VSMAX_F5234_Determiner_Temps_Confirmation_Changement_Rapport(
                            SInt16 VSCtl_aVehPotVSMaxReq_swc_in, /* BIN10 */
                            UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in, /* Enum */
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReq_swc_out, /* DEC2 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSMaxReq_swc_out /* DEC2 */);


extern FUNC(void, AUTOMATIC) VSMAX_Re002tev_Sf(UInt8 Ext_spdVehVSMaxPrmaReq_swc_in,                        /*BIN0*/
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                          /*BIN0*/
                               UInt8 FRM_bDeacRvVSMax_swc_in,
                               UInt8 VSCtl_stVSRegExtd_swc_in,
                               SInt16 VSCtl_aVeh_swc_in,                                   /*BIN10*/
                               UInt8 VSCtl_stDVSRegExtd_swc_in,
                               UInt8 VSCtl_stVSLimExtd_swc_in,
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt8 FRM_bInhVSMax_swc_in,
                               UInt8 Ext_bKeyOff_swc_in,
                               UInt8 VSCtl_stDeacVSCtlInfo_swc_in,                         /*BIN0*/
                               SInt16 VSCtl_aVehPTMin_swc_in,                              /*BIN10*/
                               SInt16 VSCtl_aVehPTMax_swc_in,                              /*BIN10*/
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt16 AccP_rAccP_swc_in,                                   /*BIN7*/
                               UInt8 Ext_stGBxCf_swc_in,
                               UInt8 Afts_bRst_stDeacVSMaxReq1_swc_in,
                               UInt8 Afts_bRst_stDeacVSMaxReq2_swc_in,
                               UInt16 VSCtl_rTqWhlPTDrvReq_swc_in,                         /*BIN7*/
                               UInt8 VSCtl_bDrvOvrdVSMax_aVeh_swc_in,
                               UInt8 VSCtl_bEndTranVSMax_swc_in,
                               UInt8 VSCtl_stVSCtlInfo_swc_in,
                               SInt16 VSCtl_aVehCordVSLimReq_swc_in,                       /*BIN10*/
                               UInt8 VehEst_spdVehCrit_swc_in,                             /*BIN0*/
                               UInt16 Veh_spdVeh_swc_in,                            /*BIN7*/
                               UInt8 FRM_bDeacRvVSMaxc_swc_in,
                               UInt8 Ext_bTyreWarn_swc_in,
                               UInt8 FRM_bDeacRvVSMaxf_swc_in,
                               UInt8 Ext_bVSMaxfCf_swc_in,
                               UInt8 FRM_bDeacIrvVSMax_swc_in,
                               SInt16 VSCtl_jrkVeh_swc_in,                                 /*BIN7*/
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 Ext_bTyreWarnCf_swc_in,
                               SInt16 VSCtl_aVehReq_swc_in,                                /*BIN10*/
                               UInt8 FRM_bDeacRvVSMaxp_swc_in,
                               UInt8 Ext_bVSMaxpCf_swc_in,
                               UInt32 Ext_dstVehTotMes_swc_in,                             /*BIN0*/
                               SInt16 VSCtl_rSlop_swc_in,                                  /*BIN7*/
                               UInt8 FRM_bAcvVSMax_no1_swc_in,
                               UInt8 CoPt_posnLev_swc_in,
                               UInt8 FRM_bAcvVSMax_no2_swc_in,
                               UInt8 Ext_bVSMaxsCf_swc_in,
                               SInt16 VSCtl_aVehPTPotMaxCtla_no1_swc_in,            /*BIN10*/
                               UInt8 FRM_bDeacRvVSMaxs_swc_in,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_DeacVSMax_swc_out,                 /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no1_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no2_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMaxp_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSMax_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMaxp_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehVSMaxReq_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSMaxReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSMax_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSMax_swc_out,                 /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSMaxReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSMax_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSMax_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSMaxReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMax_DeacVSMax_swc_out);

extern FUNC(void, AUTOMATIC) VSMAX_Re002tev_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_DeacVSMax_swc_out,                 /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no1_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_stDeacVSMaxReq_no2_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMaxp_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehVSMaxReq_swc_out,                           /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_aVehVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stRec_stDeacVSMaxReq2_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVeh_DeacVSMax_swc_out,                         /*BIN10*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMaxp_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehVSMaxReq_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupVSMaxReq_swc_out,                       /*DEC2*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehErrVSMax_swc_out,                         /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccP_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_dstVehTotMes_DeacVSMax_swc_out,                 /*BIN0*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVeh_DeacVSMax_swc_out,                       /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnVSMaxReq_swc_out,                      /*DEC2*/
                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSMax_swc_out,                     /*BIN0*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtl_aVehPotVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxExtd_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rSlop_DeacVSMax_swc_out,                        /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rCtlTqWhlPTPotVSMax_swc_out,                    /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_jrkVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_aVehPotVSMaxReq_swc_out,                        /*BIN10*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSMax_swc_out,                     /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSMax_DeacVSMax_swc_out);

extern FUNC(void, AUTOMATIC) VSMAX_Veh_Spd_Ctrl_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehVSMaxReq_swc_out,
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSMax_swc_out);

extern FUNC(void, AUTOMATIC) VSMAX_Veh_Acc_Ctrl_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSMaxReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSMax_swc_out, /* BIN4 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReq_swc_out, /* DEC2 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSMaxReq_swc_out /* DEC2 */);

extern FUNC(void, AUTOMATIC) VSMAX_Fct_Mode_Sl_Init(
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_DeacVSMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSMax_swc_out, /* BIN0 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSMax_swc_out, /* NBIN6 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSMax_swc_out, /* NBIN6 */
                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSMax_swc_out,
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSMax_swc_out,
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no1_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no2_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMax_DeacVSMax_swc_out);


/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) VSMax_Timer_1ms_U32(void);



/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_VSMAX_1MS_U32_TIME  VSmax_Timer_1ms_U32()

#define VSMAX_STOP_SEC_CODE
#include "VSMax_MemMap.h"

#endif

