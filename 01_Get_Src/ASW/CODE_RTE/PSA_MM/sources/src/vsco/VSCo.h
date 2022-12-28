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
* Ref X:\integration_view_00PSASWC_D721D01\blois_psa_sstg\Software\Appli\VSCo\src\VSCo.h
* Version int :/main/00PSASWC_D7/4 Date: 12/4/2012 13 h 55 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for VSCo 12.1
* Version dev :\main\branch_morisseau_vsco_euro6\1 Date: 12/4/2012 11 h 14 m User:morisseau 
*    TWK_model:NO_MODEL
*    comments :for VSCo 12.1
* Version int :/main/00PSASWC_D7/3 Date: 10/1/2012 8 h 34 m User:meme
*    TWK_model:NO_MODEL
*    comments :For VSCo_12_0_e6
* Version dev :\main\branch_halouane_vsco_euro6\1 Date: 6/1/2012 15 h 24 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For VSCo_12_0_e6
* Version int :/main/00PSASWC_D7/2 Date: 6/9/2011 15 h 43 m User:meme
*    TWK_model:NO_MODEL
*    comments :Update for VSCo 11.0
* Version dev :\main\branch_moisan_tmp\1 Date: 6/9/2011 15 h 2 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for VSCo 11.0
* Version dev :\main\branch_halouane_vsco_euro6\1 Date: 9/8/2011 15 h 51 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For vsco_11.0_e6
* Version int :/main/00PSASWC_D7/1 Date: 4/2/2011 17 h 29 m User:esnault
*    TWK_model:NO_MODEL
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\4 Date: 4/2/2011 12 h 2 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\3 Date: 16/12/2010 11 h 10 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\2 Date: 15/12/2010 17 h 58 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\1 Date: 10/12/2010 10 h 49 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For VSCo 10.0
*
*******************************************************************************/


#ifndef VSCO_H
#define VSCO_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_VSCo.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define VSCO_DDS_LIB_VERSION_REQ 360

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/




/*   -----------------------ENUM COMMON DEFINITION------------  */
/*  VSCtl_bDrvOvrdVSReg_aVeh
    VSCtl_bDrvOvrdDVSReg_aVeh
    VSCtl_bDrvOvrdVSLim_aVeh
    VSCtl_bDrvOvrdVSMax_aVeh
    VSCtl_bDrvOvrdDVSRegInt_aVeh
    VSCtl_bDrvOvrdVSRegInt_aVeh                                 */
#define VSCO_ACCELERATION_EFFECTIVE         (UInt32)0
#define VSCO_ACCELERATION_NON_EFFECTIVE     (UInt32)1


/*  VSCtl_bCtlEfc_aVeh
    VSCtl_bCtlEfc_aVehMin
    VSCtl_bCtlEfc_aVehMax                                       */
#define VSCO_NON_EFFECTIF       (UInt32)0
#define VSCO_EFFECTIF           (UInt32)1

/*  VSCtl_stCtlaVehMinSat */
#define VSCO_STCTLAVEHMINSAT_ARRET              (UInt32)0
#define VSCO_STCTLAVEHMINSAT_ACTIVATION_31      (UInt32)1
#define VSCO_STCTLAVEHMINSAT_CONTROLE_31        (UInt32)2
#define VSCO_STCTLAVEHMINSAT_DESACTIVATION_31   (UInt32)3


/*  VSCtl_stCtl_aVeh
    VSCtl_stCtl_tqWhlMin
    VSCtl_stCtl_tqWhlMax
    VSCtl_stCtl_aVehPot
    VSCtl_stCtl_tqWhlPot
    VSCtl_bCtl_aVehPotVSLim
    VSCtl_bCtl_aVehPotVSMax
    VSCtl_stCtl_tqWhlPotMax
    VSCtl_stCtl_tqWhlPotMin                         */
#define VSCO_ARRET      (UInt32)0
#define VSCO_CONTROLE   (UInt32)1

/*  Ext_stDVSRegCf */
#define VSCO_ABSENTE        (UInt32)0
#define VSCO_RVV_PRESENTE   (UInt32)1
#define VSCO_ACC_PRESENTE   (UInt32)2


/* VSCtl_stCtl_tqWhlPotMin
   VSCtl_stCtl_tqWhlPotMax  */
#define VSCO_POT_ARRET          (UInt32)0
#define VSCO_POT_CONTROLE       (UInt32)1

/* VSCtl_stVSCtlInfo */
/*#define VSCO_ARRET                (UInt32)0*/
#define VSCO_VERIF_20           (UInt32)1
#define VSCO_INIT_20            (UInt32)2
#define VSCO_NOMINAL_20         (UInt32)3
#define VSCO_DEFAUT_20          (UInt32)4


/* CoPt_posnLev */
#define VSCO_COPT_POSNLEV_P                 (UInt32)0
#define VSCO_COPT_POSNLEV_R                 (UInt32)1
#define VSCO_COPT_POSNLEV_N                 (UInt32)2
#define VSCO_COPT_POSNLEV_DRIVE             (UInt32)3
#define VSCO_COPT_POSNLEV_PR_NR             (UInt32)4
#define VSCO_COPT_POSNLEV_ND                (UInt32)5
#define VSCO_COPT_POSNLEV_MANUEL            (UInt32)6
#define VSCO_COPT_POSNLEV_INDISPONIBLE      (UInt32)7


 /* Ext_stGBxCf */
#define VSCO_BVM    (UInt32)0
#define VSCO_BVA    (UInt32)1
#define VSCO_BVMP   (UInt32)2


/* VSCtl_stCtl_aVehVSLim */
#define VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET                (UInt32)0
#define VSCO_VSCTL_STCTL_AVEHVSLIM_CONTROL              (UInt32)1
#define VSCO_VSCTL_STCTL_AVEHVSLIM_TRANSITION_LENTE     (UInt32)2
#define VSCO_VSCTL_STCTL_AVEHVSLIM_TRANSITION_RAPIDE    (UInt32)3

/* VSCtl_stCtl_aVehVSMax */
#define VSCO_VSCTL_STCTL_AVEHVSMAX_ARRET                (UInt32)0
#define VSCO_VSCTL_STCTL_AVEHVSMAX_CONTROL              (UInt32)1
#define VSCO_VSCTL_STCTL_AVEHVSMAX_TRANSITION           (UInt32)2

/* VSCtl_stCtl_aVehVSReg */
#define VSCO_VSCTL_STCTL_AVEHVSREG_ARRET        (UInt32)0
#define VSCO_VSCTL_STCTL_AVEHVSREG_CONTROL      (UInt32)1
#define VSCO_VSCTL_STCTL_AVEHVSREG_TRANSITION   (UInt32)2

/* Ext_stCtlCmdPTTqPotCf */
#define VSCO_STCTLCMDPTTQPOTCF_DESACTIVE           (UInt32)0
#define VSCO_STCTLCMDPTTQPOTCF_LEURAGE_PED         (UInt32)1
#define VSCO_STCTLCMDPTTQPOTCF_COUPLE              (UInt32)2
#define VSCO_STCTLCMDPTTQPOTCF_RAPPORT             (UInt32)3





/*   -----------------------MAP AXIS DEFINITION---------------  */
#define VSC_8_SIZE              8
#define VSCO_PREV_TAB_SIZE_4    4





/*  ----------------------  LIMITS ---------------------------  */

#define VSCO_TORQUE_CONS_16000_BIN1_NEG (SInt16)(-16000 * BIN1)
#define VSCO_TORQUE_CONS_16000_BIN1_POS (SInt16)(16000 * BIN1)
#define VSCO_TORQUE_CONS_0_BIN1         (SInt16)(0 * BIN1)




/*  ----------------------  SCHEDULING -----------------------  */
#define VSCO_SCHEDULING_T1       40 /* 40ms DEC3 */
#define VSCO_SCHEDULING_T2       10 /* 10ms DEC3 */




/*   -----------------------USE FOR QAC ONLY -----------------  */
#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_



/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define VSCO_START_SEC_CODE
#include "VSCo_MemMap.h"

extern FUNC(void, AUTOMATIC) VSCO_Veh_Accel_Cons(UInt8 VSCtl_stTqWhlPTCutOffReq_swc_in,
                                                   UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                   UInt8 CoPt_posnLev_swc_in,
                                                   UInt8 Ext_stGBxCf_swc_in,
                                                   UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                                                   UInt8 VSCtl_stVSCtlInfo_swc_in,
                                                   SInt16 VSCtl_aVehPTMinNotCtla_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehPTMaxNotCtla_swc_in, /* BIN10 */
                                                   UInt8 Ext_bVSLimCf_swc_in,
                                                   UInt8 Ext_bVSMaxfCf_swc_in,
                                                   UInt8 Ext_bVSMaxpCf_swc_in,
                                                   UInt8 Ext_bVSMaxsCf_swc_in,
                                                   UInt8 Ext_stDVSRegCf_swc_in,
                                                   SInt16 VSCtl_aVehPreCoVSCtlReq_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehVSLimReq_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehVSMaxReq_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehVSRegReq_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehDVSRegReq_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                   UInt8 VSCtl_bCtlEfc_tqCkEfcMax_swc_in,
                                                   UInt8 VSCtl_bCtlEfc_tqCkEfcMin_swc_in,
                                                   UInt8 VSCtl_bCtlEfc_tqWhlPTMax_swc_in,
                                                   UInt8 VSCtl_bCtlEfc_tqWhlPTMin_swc_in,
                                                   SInt16 VSCtl_aVehPTLim_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehPTDrvMinReq_swc_in, /* BIN10 */
                                                   SInt16 VSCtl_aVehPTDrvMinReqRaw_swc_in, /* BIN10 */
                                                   UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                                                   UInt8 VSCtl_stCtl_tqWhlMax_swc_in,
                                                   UInt8 VSCtl_stCtl_tqWhlMin_swc_in,
                                                   UInt8 Ext_bPosnGBxCf_swc_in,
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehReq_swc_out, /* BIN10 */
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSLimReq_swc_out, /* BIN10 */
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSRegReq_swc_out, /* BIN10 */
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSReg_swc_out,
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSLim_swc_out,
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSMax_swc_out,
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_swc_out,
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdDVSReg_aVeh_swc_out,
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSLim_aVeh_swc_out,
                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSMax_aVeh_swc_out);



extern FUNC(void, AUTOMATIC) VSCO_Wheel_Torque_Cons(SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                    UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                                                    UInt8 VSCtl_stCtl_aVehDVSReg_swc_in,
                                                    UInt8 VSCtl_stCtl_aVehVSLim_swc_in,
                                                    UInt8 VSCtl_stCtl_aVehVSMax_swc_in,
                                                    UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                                    UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                                    SInt16 VSCtl_aRes_swc_in, /* BIN10 */
                                                    SInt16 VSCtl_tqWhlThPTMin_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlThPTPotMin_swc_in, /* BIN1 */
                                                    UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinReq_swc_out, /* BIN1 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMaxReq_swc_out, /* BIN1 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMin_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMax_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMin_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMax_swc_out,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinSat_swc_out, /* BIN1 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bTqWhlMinSat_swc_out);




extern FUNC(void, AUTOMATIC) VSCO_Veh_Acc_Pot_Act_Cons(UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                                                       SInt16 VSCtl_aRes_swc_in, /* BIN10 */
                                                       SInt16 VSCtl_aVehPotVSRegReq_swc_in, /* BIN10 */
                                                       SInt16 VSCtl_aVehPotVSLimReq_swc_in, /* BIN10 */
                                                       SInt16 VSCtl_aVehPotDVSRegReq_swc_in, /* BIN10 */
                                                       SInt16 VSCtl_aVehPotVSMaxReq_swc_in, /* BIN10 */
                                                       UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                       UInt8 Ext_stGBxCf_swc_in,
                                                       UInt8 CoPt_posnLev_swc_in,
                                                       SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                       SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                       UInt8 VSCtl_stVSCtlInfo_swc_in,
                                                       SInt16 VSCtl_aVehPTPotMax_swc_in, /* BIN10 */
                                                       SInt16 VSCtl_aVehPTPotMin_swc_in, /* BIN10 */
                                                       UInt8 Ext_stDVSRegCf_swc_in,
                                                       UInt8 Ext_bVSLimCf_swc_in,
                                                       UInt8 Ext_bVSMaxfCf_swc_in,
                                                       UInt8 Ext_bVSMaxpCf_swc_in,
                                                       UInt8 Ext_bVSMaxsCf_swc_in,
                                                       UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                       UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in,
                                                       UInt8 Ext_bPosnGBxCf_swc_in,
                                                       UInt8 Ext_stCtlCmdPTTqPotCf_swc_in);


extern FUNC(void, AUTOMATIC) VSCO_Whl_Tq_Pot_Cons_Kick(UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                                UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotVSLim_swc_in, /* BIN4 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotVSMax_swc_in, /* BIN4 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotDVSReg_swc_in, /* BIN4 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotVSReg_swc_in, /* BIN4 */
                                                SInt16 VSCtl_tqWhlPTPotMax_swc_in, /* BIN1 */
                                                SInt16 VSCtl_tqWhlPTPotMin_swc_in, /* BIN1 */
                                                UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in,
                                                UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                UInt8 VSCtl_bCtl_aVehPotVSLim_swc_in,
                                                UInt8 VSCtl_stCtl_aVehPotDVSReg_swc_in,
                                                UInt16 VSCtl_tiCfmSdwnDVSRegReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSdwnVSLimReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSdwnVSMaxReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSdwnVSRegReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupDVSRegReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupVSLimReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupVSMaxReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupVSRegReq_swc_in, /* DEC2 */
                                                UInt8 VSCtl_stVSCtlInfo_swc_in,
                                                UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                                                UInt8 VSCtl_bDrvOvrdVSMax_aVeh_swc_in,
                                                UInt8 VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                                UInt8 VSCtl_stCtl_aVehDVSReg_swc_in,
                                                UInt8 VSCtl_stCtl_aVehVSLim_swc_in,
                                                UInt8 VSCtl_stCtl_aVehVSMax_swc_in,
                                                UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                                                UInt8 FRM_bDeacVSCtlKDCtl_swc_in,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinReq_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxReq_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvLoThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvHiThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvLoThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvHiThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMaxReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMinReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMaxReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMinReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPot_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMax_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMin_swc_out,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotReq_swc_out, /* BIN1 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bKdAuth_swc_out);

/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) VSCO_Veh_Accel_Cons_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehReq_swc_out, /* BIN10 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSLimReq_swc_out, /* BIN10 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSRegReq_swc_out, /* BIN10 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSReg_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSLim_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSMax_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdDVSReg_aVeh_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSLim_aVeh_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSMax_aVeh_swc_out);


extern FUNC(void, AUTOMATIC) VSCO_Wheel_Torque_Cons_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinReq_swc_out, /* BIN1 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMaxReq_swc_out, /* BIN1 */
                                                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMin_swc_out,
                                                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMax_swc_out,
                                                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMin_swc_out,
                                                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMax_swc_out,
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinSat_swc_out, /* BIN1 */
                                                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bTqWhlMinSat_swc_out);



extern FUNC(void, AUTOMATIC) VSCO_Veh_Acc_Pot_Act_Cons_Init(void);



extern FUNC(void, AUTOMATIC) VSCO_Whl_Tq_Pot_Cons_Kick_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinReq_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxReq_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvLoThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvHiThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvLoThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvHiThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMaxReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMinReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMaxReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMinReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPot_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMax_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMin_swc_out,
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotReq_swc_out, /* BIN1 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bKdAuth_swc_out);

/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) VSCo_Timer_1ms_U32(void);



/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_VSCO_1MS_U32_TIME  VSCo_Timer_1ms_U32()

#define VSCO_STOP_SEC_CODE
#include "VSCo_MemMap.h"

#endif

