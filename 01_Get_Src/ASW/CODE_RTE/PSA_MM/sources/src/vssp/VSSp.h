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
* Ref X:\integration_view_00PSASWC_D820D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSp.h
* Version int :/main/00PSASWC_D8/5 Date: 6/1/2012 11 h 10 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version dev :\main\branch_moisan_module_dev\1 Date: 4/1/2012 15 h 45 m User:moisan 
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 1/12/2011 14 h 6 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 28/11/2011 11 h 49 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version int :/main/00PSASWC_D8/4 Date: 7/9/2011 16 h 40 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\5 Date: 31/8/2011 9 h 52 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\4 Date: 25/8/2011 10 h 5 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\3 Date: 4/8/2011 17 h 9 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 26/7/2011 17 h 2 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 21/7/2011 17 h 36 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version int :/main/00PSASWC_D8/3 Date: 30/5/2011 9 h 8 m User:esnault
*    TWK_model:NO_MODEL
*    comments :update dds_lib version for VSSp 10.1 (barycentre_V2)
* Version dev :\main\branch_lemort_eom_dev\1 Date: 20/5/2011 11 h 7 m User:lemort
*    TWK_model:NO_MODEL
*    comments :update dds_lib version for VSSp 10.1 (barycentre_V2)
* Version int :/main/00PSASWC_D8/2 Date: 16/3/2011 11 h 47 m User:esnault
*    TWK_model:NO_MODEL
*    comments :VSSp 10.0 : . VSCtl_stTqWhlPTCutOffReqPrev rename with VSCtl_stTqWhlPTCutOffReqDly
* Version dev :\main\branch_morisseau_vssp_euro6\9 Date: 16/3/2011 10 h 59 m User:veillard
*    TWK_model:NO_MODEL
*    comments :VSSp 10.0 : . VSCtl_stTqWhlPTCutOffReqPrev rename with VSCtl_stTqWhlPTCutOffReqDly
* Version dev :\main\branch_morisseau_vssp_euro6\9 Date: 16/3/2011 10 h 56 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :VSSp 10.0 : . VSCtl_stTqWhlPTCutOffReqPrev rename with VSCtl_stTqWhlPTCutOffReqDly
* Version int :/main/00PSASWC_D8/1 Date: 25/2/2011 8 h 53 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\8 Date: 23/2/2011 16 h 54 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\7 Date: 22/2/2011 16 h 56 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\6 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 18/1/2011 14 h 4 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSSp
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 5/1/2011 14 h 56 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 4/1/2011 17 h 49 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 3/1/2011 14 h 17 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 23/12/2010 14 h 56 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
*
*******************************************************************************/

#ifndef VSSP_H
#define VSSP_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_VSSp.h"
#include "SC.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define VSSP_DDS_LIB_VERSION_REQ 400

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

#define VSSP_2_SIZE                           2
#define VSSP_4_SIZE                           4
#define VSSP_7_SIZE                           7
#define VSSP_8_SIZE                           8
#define VSSP_13_SIZE                          13
#define VSSP_16_SIZE                          16
#define VSSP_25_SIZE                          25

/* CoPt_noTarGearCordIt */
#define VSSP_COPT_NOTARGEARCORDIT_MAR               (-1)
#define VSSP_COPT_NOTARGEARCORDIT_NEUTRE            (0)
#define VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT       (1)
#define VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT      (2)
#define VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT      (3)
#define VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT      (4)
#define VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT      (5)
#define VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT      (6)
#define VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT      (7)
#define VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT      (8)

/* Ext_stTraTypCf */
#define EXT_STTRATYPCF_AL4            (0)
#define EXT_STTRATYPCF_AX6            (1)
#define EXT_STTRATYPCF_XXX1AUTO       (2)
#define EXT_STTRATYPCF_DCT            (3)
#define EXT_STTRATYPCF_MCP            (4)
#define EXT_STTRATYPCF_MAP            (5)
#define EXT_STTRATYPCF_XXX1PILOTE     (6)
#define EXT_STTRATYPCF_BVM            (7)

 /* Ext_stCtlCmdPTTqPotCf */
#define VSSP_EXT_STCTLCMDPTTQPOTCF_DESACTIVE                                0
#define VSSP_EXT_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR               1
#define EXT_STCTLCMDPTTQPOTCF_LEURAGE_PED                                   (1)
#define VSSP_EXT_STCTLCMDPTTQPOTCF_COUPLE                                   2
#define EXT_STCTLCMDPTTQPOTCF_COUPLE                                        (2)
#define VSSP_EXT_STCTLCMDPTTQPOTCF_RAPPORT                                  3

 /* VSCtl_noGearReqMax */
 /* VSCtl_noGearReqMin */
 /* VSCtl_noGearMaxTqPosRaw */
#define VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS       0
#define VSSP_VSCTL_NOGEARREQ_1ER_RAPPORT                1
#define VSSP_VSCTL_NOGEARREQ_2EME_RAPPORT               2
#define VSSP_VSCTL_NOGEARREQ_3EME_RAPPORT               3
#define VSSP_VSCTL_NOGEARREQ_4EME_RAPPORT               4
#define VSSP_VSCTL_NOGEARREQ_5EME_RAPPORT               5
#define VSSP_VSCTL_NOGEARREQ_6EME_RAPPORT               6
#define VSSP_VSCTL_NOGEARREQ_7EME_RAPPORT               7
#define VSSP_VSCTL_NOGEARREQ_8EME_RAPPORT               8
#define VSSP_VSCTL_NOGEARREQ_RESERVE_9                  9
#define VSSP_VSCTL_NOGEARREQ_RESERVE_10                 10
#define VSSP_VSCTL_NOGEARREQ_RESERVE_11                 11
#define VSSP_VSCTL_NOGEARREQ_RESERVE_12                 12
#define VSSP_VSCTL_NOGEARREQ_RESERVE_13                 13
#define VSSP_VSCTL_NOGEARREQ_RESERVE_14                 14
#define VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT      15

 /* VSCtl_stCtl_noGear */
#define VSSP_VSCTL_STCTL_NOGEAR_ARRET                   0
#define VSSP_VSCTL_STCTL_NOGEAR_CONTROLE                1
#define VSSP_VSCTL_STCTL_NOGEAR_DEFAUT                  2

 /* VSCtl_stCtl_tqWhlPTMin */
#define VSSP_VSCTL_STCTL_TQWHLPTMIN_CONTROLE            1
#define VSSP_VSCTL_STCTL_TQWHLPTMIN_ARRET               0


 /* VSCtl_stCtl_tqWhlPTMax */
#define VSSP_VSCTL_STCTL_TQWHLPTMAX_ARRET               0
#define VSSP_VSCTL_STCTL_TQWHLPTMAX_CONTROLE            1
#define VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_L             2
#define VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_R             3
#define VSSP_VSCTL_STCTL_TQWHLPTMAX_INIT                4

/* VSCtl_stCtl_tqCkEfcMin */
#define VSSP_VSCTL_STCTL_TQCKEFCMIN_ARRET               0
#define VSSP_VSCTL_STCTL_TQCKEFCMIN_CONTROLE            1
#define VSCTL_STCTL_TQCKEFCMIN_ARRET                    0
#define VSCTL_STCTL_TQCKEFCMIN_CONTROLE                 1

 /* VSCtl_stCtl_tqCkEfcMax */
#define VSSP_VSCTL_STCTL_TQCKEFCMAX_ARRET               0
#define VSSP_VSCTL_STCTL_TQCKEFCMAX_CONTROLE            1
#define VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_L             2
#define VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_R             3
#define VSSP_VSCTL_STCTL_TQCKEFCMAX_INIT                4
#define VSCTL_STCTL_TQCKEFCMAX_INIT                     4
#define VSCTL_STCTL_TQCKEFCMAX_CONTROLE                 1
#define VSCTL_STCTL_TQCKEFCMAX_TRANS_L                  2
#define VSCTL_STCTL_TQCKEFCMAX_ARRET                    0
#define VSCTL_STCTL_TQCKEFCMAX_TRANS_R                  3

 /* VSCtl_stGearCtlReq */
#define VSSP_VSCTL_STGEARCTLREQ_NON_DEMANDE                     0
#define VSSP_VSCTL_STGEARCTLREQ_DEMANDE                         1
#define VSSP_VSCTL_STGEARCTLREQ_DEMANDE_EN_MODE_FULL_PASS       2
#define VSSP_VSCTL_STGEARCTLREQ_RESERVE                         3

 /* VSCtl_stTqPTMaxCtl */
 /* VSCtl_stTqPTMinCtl */
#define VSSP_VSCTL_STTQPTCTL_INACTIF                    0
#define VSSP_VSCTL_STTQPTCTL_ACTIF_EFFECTIF             1
#define VSSP_VSCTL_STTQPTCTL_ACTIF_NON_EFFECTIF         2

 /* VSCtl_stTqWhlPTCutOffReq */
 /* VSCtl_stTqWhlPTCutOffReqDly */
#define VSSP_VSCTL_STTQWHLPTCUTOFFREQ_ARRET_INDETERMINE 0
#define VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_HAUT     1
#define VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_BAS      2

 /* VSCtl_stTqWhlPTMinSat */
 /* VSCtl_stCtl_aVehVSMax */
 /* VSCtl_stCtl_tqWhlPotMin */
#define VSSP_VSCTL_STTQWHLPTMINSAT_ARRET                0
#define VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE             1
#define VSSP_VSCTL_STTQWHLPTMINSAT_TRANSITION           2

 /* VSCtl_stTqWhlPTPotCtlReq */
#define VSSP_VSCTL_STTQWHLPTPOTCTLREQ_NON_DEMANDE       0
#define VSSP_VSCTL_STTQWHLPTPOTCTLREQ_DEMANDE_MODE_1    1
#define VSSP_VSCTL_STTQWHLPTPOTCTLREQ_DEMANDE_MODE_2    2
#define VSSP_VSCTL_STTQWHLPTPOTCTLREQ_DEMANDE_MODE_3    3

/* VSCtl_stCtl_tqEfcTarMin */
#define VSCTL_STCTL_TQEFCTARMIN_ARRET                   (0)
#define VSCTL_STCTL_TQEFCTARMIN_HORS_SIP                (1)
#define VSCTL_STCTL_TQEFCTARMIN_SIP                     (2)
#define VSCTL_STCTL_TQEFCTARMIN_FIN_SIP_HIGH            (3)
#define VSCTL_STCTL_TQEFCTARMIN_FIN_SIP_LOW             (4)

/* VSCtl_stCtl_tqEfcTarMax */
#define VSCTL_STCTL_TQEFCTARMAX_ARRET                   (0)
#define VSCTL_STCTL_TQEFCTARMAX_HORS_SIP                (1)
#define VSCTL_STCTL_TQEFCTARMAX_SIP                     (2)
#define VSCTL_STCTL_TQEFCTARMAX_FIN_SIP_HIGH            (3)
#define VSCTL_STCTL_TQEFCTARMAX_FIN_SIP_LOW             (4)

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

/***************************************************/
/* VSSP_Control_Wheel_Gmp1_Sl.c */
extern FUNC(void, AUTOMATIC) VSSP_F71212_Determiner_Consigne_Couple_Roue_Gmp_Min(
                                                 SInt16 VSCtl_tqWhlMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinReq_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_F71214_Determiner_Position_Pedale_Accelerateur_Gmp_Min(
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMinReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMin_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSSP_F71221_Determiner_Consigne_Couple_Roue_Gmp_Max_Init(
                                                 SInt16 VSCtl_tqWhlPTMaxReq_swc_in /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_F71223_Determiner_Consigne_Couple_Roue_Gmp_Max(
                                                 SInt16 VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxReq_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_F71225_Determiner_Position_Pedale_Accelerateur_Gmp_Max(
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMaxReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMax_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSSP_F71232_Determiner_Consigne_Limitation_Couple_Roue_Gmp_Min(
                                                 SInt16 VSCtl_tqWhlMinSat_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinSat_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp1_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMax_swc_out, /* BIN7 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMin_swc_out, /* BIN7 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxReq_swc_out, /* BIN1 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinReq_swc_out, /* BIN1 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinSat_swc_out /* BIN1 */);


/***************************************************/
/* VSSP_Control_Wheel_Gmp2_Sl.c */
extern FUNC(void, AUTOMATIC) VSSP_F71312_Determiner_Consigne_Couple_Moteur_Min(
                                                 UInt16 VSCtl_rConvTra_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqLossTra_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqWhlMinReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinReq_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSSP_F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min(
                                                 UInt32 VSCtl_nEngFil_swc_in, /* BIN0 */
                                                 SInt16 VSCtl_tqCkEfcMinReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMin_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSSP_F71317_Determiner_Consigne_Couple_Moteur_Cible_Min(UInt16 CoPt_nPrimShaftTar_swc_in,   /* BIN0 */
                                                                UInt32 Ext_nFrntWhl_swc_in,         /* BIN0 */
                                                                SInt16 VSCtl_tqCkEfcMinReq_swc_in,     /* BIN4 */
                                                                SInt16 VSCtl_tqWhlMinReq_swc_in,    /* BIN1 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMin_swc_out);     /* BIN4 */

extern FUNC(void, AUTOMATIC) VSSP_F71321_Determiner_Consigne_Couple_Moteur_Max_Init(
                                                 SInt16 VSCtl_tqCkEfcMaxReq_swc_in /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSSP_F71323_Determiner_Consigne_Couple_Moteur_Max(
                                                 UInt16 VSCtl_rConvTra_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqLossTra_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxReq_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSSP_F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max(
                                                 UInt32 VSCtl_nEngFil_swc_in, /* BIN0 */
                                                 SInt16 VSCtl_tqCkEfcMaxReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMax_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSSP_F71328_Determiner_Consigne_Couple_Moteur_Cible_Max(UInt16 CoPt_nPrimShaftTar_swc_in,   /* BIN0 */
                                                                UInt32 Ext_nFrntWhl_swc_in,         /* BIN7 */
                                                                SInt16 VSCtl_tqCkEfcMaxReq_swc_in,     /* BIN4 */
                                                                SInt16 VSCtl_tqWhlMaxReq_swc_in,    /* BIN1 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMax_swc_out);

extern FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp2_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMax_swc_out, /* BIN7 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMin_swc_out, /* BIN7 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxReq_swc_out, /* BIN4 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinReq_swc_out, /* BIN4 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMax_swc_out, /* BIN4 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMin_swc_out);  /* BIN4 */

/***************************************************/
/* VSSP_Det_Gearbox_Order_Sl.c */
extern FUNC(void, AUTOMATIC) VSSP_F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute(
                                                UInt8 VSCtl_stCtl_aVehVSMax_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute(void);

extern FUNC(void, AUTOMATIC) VSSP_F72264_Determiner_Consigne_Rapport_Max(
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMax_swc_out);

extern FUNC(void, AUTOMATIC) VSSP_F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute(void);

extern FUNC(void, AUTOMATIC) VSSP_F72273_Coordonner_Consigne_Rapport_Min(
                                                UInt8 VSCtl_noGearReqMax_swc_in,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMin_swc_out );

extern FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Order_Sl_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMax_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMin_swc_out );

/***************************************************/
/* VSSP_Potential_Gmp_Sl.c */
extern FUNC(void, AUTOMATIC) VSSP_F72112_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Min(
                                            UInt8  Ext_stCtlCmdPTTqPotCf_swc_in,
                                            UInt8  VSCtl_stCtl_tqWhlPotMin_swc_in,
                                            SInt16 VSCtl_tqWhlPotMinReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMinReq_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_F72122_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Max(
                                            UInt8  Ext_stCtlCmdPTTqPotCf_swc_in,
                                            UInt8  VSCtl_stCtl_tqWhlPotMax_swc_in,
                                            SInt16 VSCtl_tqWhlPotMaxReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxReq_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_F7214_Determiner_Temps_Confirmation_Changement_Rapport(
                                            UInt8  Ext_stCtlCmdPTTqPotCf_swc_in,
                                            UInt16 VSCtl_tiCfmSdwnTqMaxReq_swc_in, /* DEC2 */
                                            UInt16 VSCtl_tiCfmSdwnTqMinReq_swc_in, /* DEC2 */
                                            UInt16 VSCtl_tiCfmSupTqMaxReq_swc_in, /* DEC2 */
                                            UInt16 VSCtl_tiCfmSupTqMinReq_swc_in, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupReq_swc_out, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnReq_swc_out /* DEC2 */);

extern FUNC(void, AUTOMATIC) VSSP_F72152_Determiner_Consigne_Potentiel_Couple_Roue_Gmp(
                                            SInt16 VSCtl_tqWhlPotReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotReq_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_Potential_Gmp_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnReq_swc_out, /* DEC2 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupReq_swc_out, /* DEC2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxReq_swc_out, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMinReq_swc_out, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotReq_swc_out /* BIN1 */);

/***************************************************/
/* VSSP_Det_Gearbox_Speed_Sl.c */
extern FUNC(void, AUTOMATIC) VSSP_F7222_Coordonner_Consignes_Potentiel_Couple_Roue_Gmp(
                                                UInt8 VSCtl_stCtl_noGear_swc_in,
                                                UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F7223_Determiner_Plage_Rapport_Pilotable(
                                                SInt8 CoPt_noTarGearCordIt_swc_in,
                                                UInt32 VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                                                UInt8 VSCtl_stCtl_noGear_swc_in,
                                                UInt8 Ext_stTraTypCf_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F7224_Determiner_Seuils_Changement_Rapport(
                                                SInt8 CoPt_noTarGearCordIt_swc_in,
                                                UInt32 VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                                                UInt8 VSCtl_stCtl_noGear_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F7225_Determiner_Temps_Confirmation_Changement_Rapport(
                                                UInt32 VSCtl_nEngFil_swc_in, /* BIN0 */
                                                UInt8 VSCtl_stCtl_noGear_swc_in,
                                                SInt16 VSCtl_tqWhlPTPotReq_swc_in /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Speed_Sl_Init(void);

/***************************************************/
/* VSSP_Effec_Process_Xvv.c */
extern FUNC(void, AUTOMATIC) VSSP_Effec_Process_Xvv(UInt8 VSCtl_bCtlEfc_tqWhlPT_pt1_swc_in,
                                                    UInt8 VSCtl_bCtlEfc_tqWhlPT_pt2_swc_in,
                                                    UInt8 VSCtl_stTqPTMaxCtl_pt1_swc_in,
                                                    UInt8 VSCtl_stTqPTMaxCtl_pt2_swc_in,
                                                    UInt8 VSCtl_stTqPTMinCtl_pt1_swc_in,
                                                    UInt8 VSCtl_stTqPTMinCtl_pt2_swc_in,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPt_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMaxCtl_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMinCtl_swc_out);

extern FUNC(void, AUTOMATIC) VSSP_Effec_Process_Xvv_Init(
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPt_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMaxCtl_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMinCtl_swc_out);

/***************************************************/
/* VSSP_Position_Pedale_Sl.c */
extern FUNC(void, AUTOMATIC) VSSP_F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV(
                                                SInt16 VSCtl_spdVehErrVSReg_swc_in,
                                                UInt16 AccP_rAccP_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC(
                                                SInt16 VSCtl_aVehDVSRegReq_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV(
                                                SInt16 VSCtl_spdVehErrVSLim_swc_in,
                                                UInt16 AccP_rAccP_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV(
                                                SInt16 VSCtl_spdVehErrVSMax_swc_in,
                                                UInt16 AccP_rAccP_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in);

extern FUNC(void, AUTOMATIC) VSSP_F7236_Determiner_Position_Pedales_Tramsmission_XVV(
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMax_swc_out,
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMin_swc_out);

extern FUNC(void, AUTOMATIC) VSSP_Position_Pedale_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMax_swc_out, /* BIN7 */
                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMin_swc_out /* BIN7 */);

/***************************************************/
/* VSSP_Sf */
extern FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp1_Sf(SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in,                    /*BIN1*/
                               UInt8 VSCtl_bLgtCtlDyn_swc_in,
                               SInt16 VSCtl_tqWhlPTMin_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMax_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlMinSat_swc_in,                            /*BIN1*/
                               SInt16 VSCtl_tqWhlMinReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlMin_swc_in,
                               UInt8 VSCtl_bTqWhlMinSat_swc_in,
                               SInt16 VSCtl_tqWhlMaxReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlMax_swc_in,
                               SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in,                   /*BIN1*/
                               SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in,                  /*BIN1*/
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 VSCtl_bAuthAntTqWhlMin_swc_in,
                               SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in,                       /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in,                      /*BIN1*/
                               UInt8 VSCtl_bAuthAntTqWhlMax_swc_in,
                               SInt16 VSCtl_tqWhlPTDrvMaxReq_swc_in,                       /*BIN1*/
                               UInt8 VSCtl_bCtlaTqPT_swc_in,
                               SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in,                      /*BIN1*/
                               UInt8 VSCtl_bFastDeacVSLimReq_swc_in,
                               UInt16 AccP_rAccP_swc_in,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTCutOffReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bAcvTqWhlPTMinSat_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt1_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinSat_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMin_swc_out,                             /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMaxReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMax_swc_out);                            /*BIN7*/

extern FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp2_Sf(SInt16 VSCtl_tqWhlPTPotRawMin_swc_in,                       /*BIN1*/
                               SInt16 VSCtl_tqWhlPTPotRawMax_swc_in,                       /*BIN1*/
                               UInt32 Ext_nFrntWhl_swc_in,                                 /*BIN7*/
                               SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in,                       /*BIN4*/
                               UInt8 Ext_stTraTypCf_swc_in,
                               SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in,                      /*BIN4*/
                               SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in,                       /*BIN4*/
                               UInt16 VSCtl_tiCfmSupTqMinReq_swc_in,                       /*DEC2*/
                               SInt16 VSCtl_tqWhlMinReq_swc_in,                            /*BIN1*/
                               SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in,                      /*BIN4*/
                               UInt8 VSCtl_stCtl_tqWhlMin_swc_in,
                               UInt16 VSCtl_tiCfmSupTqMaxReq_swc_in,                       /*DEC2*/
                               SInt16 VSCtl_tqWhlMaxReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlMax_swc_in,
                               UInt16 VSCtl_tiCfmSdwnTqMinReq_swc_in,                      /*DEC2*/
                               UInt16 VSCtl_tiCfmSdwnTqMaxReq_swc_in,                      /*DEC2*/
                               UInt32 VSCtl_nEngFil_swc_in,                                /*BIN0*/
                               SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in,                  /*BIN1*/
                               SInt16 VSCtl_tqCkEfcMin_swc_in,                             /*BIN4*/
                               SInt16 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in,                  /*BIN1*/
                               SInt16 VSCtl_tqCkEfcMax_swc_in,                             /*BIN4*/
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               SInt16 VSCtl_tqWhlPotReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPot_swc_in,
                               UInt16 CoPt_nPrimShaftTar_swc_in,                           /*BIN0*/
                               SInt16 VSCtl_tqLossTra_swc_in,                              /*BIN4*/
                               SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in,                   /*BIN4*/
                               UInt16 VSCtl_rConvTra_swc_in,                               /*BIN7*/
                               SInt16 VSCtl_tqWhlPotMinReq_swc_in,                         /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in,
                               UInt8 VSCtl_bFastDeacVSLimReq_swc_in,
                               SInt16 VSCtl_tqWhlPotMaxReq_swc_in,                         /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                               SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in,                  /*BIN4*/
                               UInt16 AccP_rAccP_swc_in,                            /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMaxReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMin_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnReq_swc_out,                           /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTPotCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMin_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bInhRecup_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMax_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMin_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMinReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupReq_swc_out);                            /*DEC2*/

extern FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Pedal_Sf(UInt8 FRM_bDeacVSCtlGearCtl_swc_in,
                               SInt16 VSCtl_aVehDVSRegReq_swc_in,                          /*BIN10*/
                               UInt8 VSCtl_stCtl_aVehVSLim_swc_in,
                               UInt8 VSCtl_stCtl_aVehDVSReg_swc_in,
                               UInt8 Ext_stTraTypCf_swc_in,
                               SInt16 VSCtl_spdVehErrVSReg_swc_in,                         /*BIN7*/
                               UInt8 VSCtl_stCtl_aVehVSMax_swc_in,
                               SInt16 VSCtl_spdVehErrVSLim_swc_in,                         /*BIN7*/
                               SInt16 VSCtl_spdVehErrVSMax_swc_in,                         /*BIN7*/
                               UInt32 VSCtl_nEngFil_swc_in,                                /*BIN0*/
                               UInt8 Tra_stGearCtl_swc_in,
                               UInt16 VSCtl_rAccPEngMin_swc_in,                     /*BIN7*/
                               UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt32 VSCtl_nFrntWhlFil_swc_in,                            /*BIN7*/
                               UInt8 VSCtl_bCtlaTqPT_swc_in,
                               SInt16 VSCtl_tqWhlPTPotReq_swc_in,                          /*BIN1*/
                               UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in,
                               UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                               SInt8 CoPt_noTarGearCordIt_swc_in,                          /*BIN0*/
                               UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                               UInt16 AccP_rAccP_swc_in,                                   /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_noGear_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGearCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMax_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMin_swc_out);                            /*BIN7*/

extern FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp1_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTCutOffReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt1_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPTMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bAcvTqWhlPTMinSat_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt1_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMinSat_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMin_swc_out,                             /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTMaxReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPPTMax_swc_out);                             /*BIN7*/

extern FUNC(void, AUTOMATIC) VSSP_Torque_Control_Gmp2_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMaxReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMin_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSdwnReq_swc_out,                           /*DEC2*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqWhlPTPotCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqCkEfcMax_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bCtlEfc_tqWhlPT_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMin_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bInhRecup_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqEfcTarMax_swc_out,                            /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMin_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPEngMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMinCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stTqPTMaxCtl_pt2_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotReq_swc_out,                          /*BIN1*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxReq_swc_out,                          /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlPTPotMinReq_swc_out,                       /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tiCfmSupReq_swc_out);                            /*DEC2*/

extern FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Pedal_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stCtl_noGear_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMax_swc_out,                            /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMin_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGearCtlReq_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearReqMax_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rAccPTraMin_swc_out);                            /*BIN7*/

/****************************/
/* init NV data */
extern FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp1_Sl_Cinit(void);

extern FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp2_Sl_Cinit(void);


/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) VSSp_Timer_1ms_U32(void);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_VSSP_1MS_U32_TIME  VSSp_Timer_1ms_U32()

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

#endif

