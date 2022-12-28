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
* Ref X:\integration_view_00PSASWC_D520D01\blois_psa_sstg\Software\Appli\VSLim\src\VSLim.h
* Version int :/main/00PSASWC_D5/3 Date: 6/1/2012 15 h 2 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :For VSLim_12_0_e6
* Version dev :\main\branch_halouane_vslim_euro6\1 Date: 6/1/2012 13 h 33 m User:halouane 
*    TWK_model:NO_MODEL
*    comments :For VSLim_12_0_e6
* Version dev :\main\branch_morisseau_vslim_euro6\2 Date: 23/12/2011 10 h 19 m User:halouane
*    TWK_model:NO_MODEL
*    comments :VSLim 12_0_
* Version dev :\main\branch_morisseau_vslim_euro6\1 Date: 15/11/2011 17 h 26 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSLim 12.0
* Version int :/main/00PSASWC_D5/2 Date: 30/8/2011 11 h 52 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSLim 11.0
* Version dev :\main\branch_morisseau_vslim_euro6\2 Date: 30/8/2011 11 h 2 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSLim 11.0
* Version dev :\main\branch_morisseau_vslim_euro6\1 Date: 27/7/2011 11 h 47 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSLim 11.0
* Version int :/main/00PSASWC_D5/1 Date: 12/1/2011 16 h 22 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSLim 10.0
* Version dev :\main\branch_demezil_vslim\1 Date: 22/12/2010 15 h 8 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSLim 10.0
* Version dev :\main\branch_demezil\1 Date: 22/12/2010 14 h 54 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSLim 10.0
* Version dev :\main\branch_veillard_vslim\4 Date: 22/12/2010 14 h 15 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\3 Date: 21/12/2010 17 h 55 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\2 Date: 17/12/2010 9 h 42 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\1 Date: 10/12/2010 9 h 1 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSLim 10.0
*
*******************************************************************************/



#ifndef VSLIM_H
#define VSLIM_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_VSLim.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define VSLIM_DDS_LIB_VERSION_REQ 370


#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/
/* VSLIM_Fct_Mode.c */

/* VSCtl_stVSCtlInfo */
#define VSLIM_STVSCTLINFO_ARRET         (UInt32)0
#define VSLIM_STVSCTLINFO_VERIF_20      (UInt32)1
#define VSLIM_STVSCTLINFO_INIT_20       (UInt32)2
#define VSLIM_STVSCTLINFO_NOMINAL_20    (UInt32)3
#define VSLIM_STVSCTLINFO_DEFAUT_20     (UInt32)4


/* Ext_bVSLimCf */
#define VSLIM_BVSLIMCF_PRESENT          ((UInt32)1)


/* VSCtl_stMonVSLim */
#define VSLIM_STMONVSLIM_ARRET          ((UInt32)0)
#define VSLIM_STMONVSLIM_VERIFICATION   ((UInt32)1)
#define VSLIM_STMONVSLIM_INITIALISATION ((UInt32)2)
#define VSLIM_STMONVSLIM_NOMINAL        ((UInt32)3)
#define VSLIM_STMONVSLIM_DEFAUT_REV     ((UInt32)4)
#define VSLIM_STMONVSLIM_DEFAUT_IRREV   ((UInt32)5)

/*Ext_stModRegVSCtlReq*/
#define VSLIM_STMODREGVSCTLREQ_NO_REGULATION        ((UInt32)0)
#define VSLIM_STMODREGVSCTLREQ_REGULATION_RVV       ((UInt32)1)
#define VSLIM_STMODREGVSCTLREQ_REGULATION_LVV       ((UInt32)2)
#define VSLIM_STMODREGVSCTLREQ_REGULATION_ACC       ((UInt32)3)


/* Ext_stAcvRegVSCtlReq */
#define VSLIM_STACVREGVSCTLREQ_NO_REGULATION        ((UInt32)0)
#define VSLIM_STACVREGVSCTLREQ_REGULATION_RVV       ((UInt32)1)
#define VSLIM_STACVREGVSCTLREQ_REGULATION_LVV       ((UInt32)2)
#define VSLIM_STACVREGVSCTLREQ_REGULATION_ACC       ((UInt32)3)

/* Ext_stCtlCmdPTTqPotCf */
#define VSLIM_STCTLCMDPTTQPOTCF_DESACTIVE                       ((UInt32)0)
#define VSLIM_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR      ((UInt32)1)
#define VSLIM_STCTLCMDPTTQPOTCF_COUPLE                          ((UInt32)2)
#define VSLIM_STCTLCMDPTTQPOTCF_RAPPORT                         ((UInt32)3)

/* Ext_stGBxCf */
#define VSLIM_EXT_STGBXCF_BVM   ((UInt32)0)
#define VSLIM_EXT_STGBXCF_BVA   ((UInt32)1)
#define VSLIM_EXT_STGBXCF_BVMP  ((UInt32)2)

/* VSCtl_stCtl_noGear */
#define VSLIM_VSCTL_STCTL_NOGEAR_ARRET      ((UInt32)0)
#define VSLIM_VSCTL_STCTL_NOGEAR_CONTROLE   ((UInt32)1)
#define VSLIM_VSCTL_STCTL_NOGEAR_DEFAUT     ((UInt32)2)

/* VSCtl_noGearEgd_DeacVSLim */
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_NEUTRE             ((UInt32)0)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_1ER_RAPPORT        ((UInt32)1)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_2EME_RAPPORT       ((UInt32)2)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_3EME_RAPPORT       ((UInt32)3)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_4EME_RAPPORT       ((UInt32)4)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_5EME_RAPPORT       ((UInt32)5)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_6EME_RAPPORT       ((UInt32)6)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_MARCHE_ARRIERE     ((UInt32)7)
#define VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_AUTRES_VALEURS     ((UInt32)8)

/* VSCtl_posnGBxDeacVSLim */
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_NEUTRE             ((UInt32)0)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_1ER_RAPPORT        ((UInt32)1)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_2EME_RAPPORT       ((UInt32)2)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_3EME_RAPPORT       ((UInt32)3)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_4EME_RAPPORT       ((UInt32)4)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_5EME_RAPPORT       ((UInt32)5)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_6EME_RAPPORT       ((UInt32)6)
#define VSLIM_VSCTL_POSNGBXDEACVSLIM_MARCHE_ARRIERE     ((UInt32)7)


/* VSCtl_stRec_stDeacVSLimReq1 */
/* VSCtl_stRec_stDeacVSLimReq2 */
#define VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE                   ((UInt32)0)
#define VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION              ((UInt32)1)
#define VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES   ((UInt32)2)

/* VSCtl_stVSLimExtd */
/* VSCtl_stVSLimPrev */
/* VSCtl_stVSLimPrev_DeacVSLim */
/* VSCtl_stVSLim_DeacVSLim */
#define VSLIM_VSCTL_STVSLIMEXTD_ARRET                   ((UInt32)0)
#define VSLIM_VSCTL_STVSLIMEXTD_INITIALISATION          ((UInt32)1)
#define VSLIM_VSCTL_STVSLIMEXTD_INHIBE                  ((UInt32)2)
#define VSLIM_VSCTL_STVSLIMEXTD_ATTENTE                 ((UInt32)3)
#define VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF      ((UInt32)4)
#define VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF          ((UInt32)5)
#define VSLIM_VSCTL_STVSLIMEXTD_REPRISE                 ((UInt32)6)
#define VSLIM_VSCTL_STVSLIMEXTD_DEFAUT                  ((UInt32)7)

/* VSCtl_stCtl_aVehVSLim */
#define VSLIM_STCTL_AVEHVSLIM_ARRET                 (UInt32)0
#define VSLIM_STCTL_AVEHVSLIM_CONTROLE              (UInt32)1
#define VSLIM_STCTL_AVEHVSLIM_TRANSITION_LENTE      (UInt32)2
#define VSLIM_STCTL_AVEHVSLIM_TRANSITION_RAPIDE     (UInt32)3

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define VSLIM_START_SEC_CODE
#include "VSLim_MemMap.h"



extern FUNC(void, AUTOMATIC) VSLIM_Fct_Mode(UInt8 ECU_bAuthVSCtlIni_swc_in,
                                             UInt8 Ext_bKeyOff_swc_in,
                                             UInt8 Ext_bVSLimCf_swc_in,
                                             UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                                             UInt8 Ext_stModRegVSCtlReq_swc_in,
                                             UInt8 FRM_bDeacIrvVSLim_swc_in,
                                             UInt8 FRM_bDeacRvVSLim_swc_in,
                                             UInt8 FRM_bDiFastDeacVSCtlVSLim_swc_in,
                                             UInt8 SftyMgt_bDeacIrvVSLim_swc_in,
                                             UInt8 VSCtl_stVSCtlInfo_swc_in,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLim_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLim_swc_out );

extern FUNC(void, AUTOMATIC) VSLIM_Det_Cond_Func(UInt8 Ext_bAccPHdPt_swc_in,
                                          UInt8 Ext_bTyreWarn_swc_in,
                                          UInt8 Ext_bTyreWarnCf_swc_in,
                                          UInt8 Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                          UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                                          UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                                          UInt8 Ext_stGBxCf_swc_in,
                                          UInt8 Ext_stModRegVSCtlReq_swc_in,
                                          SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                                          UInt8 VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                          UInt8 VSCtl_stCtl_noGear_swc_in,
                                          UInt8 VSCtl_stVSLimExtd_swc_in,
                                          UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                          UInt8 FRM_bDiFastDeacVSCtlVSLim_swc_in,
                                          UInt8 FRM_bInhVSLim_swc_in,
                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bFastDeacVSLimReq_swc_out );

extern FUNC(void, AUTOMATIC) VSLIM_Det_State_Diag_Mnt(UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                               UInt8 Afts_bRst_stDeacVSLimReq1_swc_in,
                                               UInt8 Afts_bRst_stDeacVSLimReq2_swc_in,
                                               UInt32 Ext_dstVehTotMes_swc_in, /* BIN0 */
                                               SInt8 CoPt_noEgdGearCordIt_swc_in,
                                               UInt8 CoPt_posnLev_swc_in,
                                               UInt8 Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                               UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                                               UInt8 Ext_stModRegVSCtlReq_swc_in,
                                               SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                                               SInt16 VSCtl_aVehVSLimReq_swc_in, /* BIN10 */
                                               UInt8 VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                               SInt16 VSCtl_jrkVeh_swc_in, /* BIN7 */
                                               SInt16 VSCtl_rSlop_swc_in, /* BIN7 */
                                               UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                               UInt8 VSCtl_stDeacVSCtlInfo_swc_in, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_DeacVSLim_swc_out, /* BIN10 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSLim_swc_out, /* BIN10 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSLim_swc_out, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSLim_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSLim_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSLim_swc_out, /* BIN0 */
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no1_swc_out, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no2_swc_out, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq1_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq2_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimExtd_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimPrev_DeacVSLim_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLim_DeacVSLim_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLimBody_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLimBody_swc_out );

extern FUNC(void, AUTOMATIC) VSLIM_Veh_Spd_Ctrl(UInt8 Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                         UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                                         SInt16 VSCtl_aVehCordVSRegReq_swc_in, /* BIN10 */
                                         SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                         SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                         SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                                         UInt8 VSCtl_bEndTranVSLim_swc_in,
                                         UInt8 VSCtl_bFastDeacVSLimReq_swc_in,
                                         UInt16 VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                                         UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                         UInt8 VSCtl_stVSCtlInfo_swc_in,
                                         UInt8 VSCtl_stVSLimExtd_swc_in,
                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSLimReq_swc_out, /* BIN10 */
                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtl_aVehPotVSLim_swc_out,
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSLim_swc_out, /* BIN4 */
                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSLim_swc_out, /* BIN7 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_aVehVSLim_swc_out,
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReq_swc_out, /* DEC2 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSLimReq_swc_out /* DEC2 */);



/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) VSLIM_Fct_Mode_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLim_swc_out);

extern FUNC(void, AUTOMATIC) VSLIM_Det_Cond_Func_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bFastDeacVSLimReq_swc_out );

extern FUNC(void, AUTOMATIC) VSLIM_Det_State_Diag_Mnt_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimExtd_swc_out,
                                                    CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no1_swc_out, /* BIN0 */
                                                    CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no2_swc_out, /* BIN0 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq1_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq2_swc_out,
                                                    CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSLim_swc_out, /* BIN0 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSLim_swc_out, /* BIN10 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLim_DeacVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimPrev_DeacVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSLim_swc_out, /* BIN0 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_DeacVSLim_swc_out, /* BIN10 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSLim_swc_out,
                                                    CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLimBody_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLimBody_swc_out );

extern FUNC(void, AUTOMATIC) VSLIM_Veh_Spd_Ctrl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSLimReq_swc_out, /* BIN10 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_swc_out, /* BIN10 */
                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtl_aVehPotVSLim_swc_out,
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSLim_swc_out, /* BIN4 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSLim_swc_out, /* BIN7 */
                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_aVehVSLim_swc_out,
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReq_swc_out, /* DEC2 */
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSLimReq_swc_out /* DEC2 */);

/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) VSLim_Timer_1ms_U32(void);



/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_VSLIM_1MS_U32_TIME  VSLim_Timer_1ms_U32()

#define VSLIM_STOP_SEC_CODE
#include "VSLim_MemMap.h"

#endif

