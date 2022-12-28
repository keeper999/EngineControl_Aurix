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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSInfo.h
* Version int :/main/00PSASWC_D2/5 Date: 4/1/2012 16 h 31 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 22/11/2011 12 h 36 m User:demezil 
*    TWK_model:NO_MODEL
*    comments :for VSInfo 12.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 22/11/2011 9 h 25 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSInfo 12.0
* Version int :/main/00PSASWC_D2/4 Date: 25/8/2011 16 h 5 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\6 Date: 25/8/2011 10 h 5 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\5 Date: 29/7/2011 11 h 52 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\4 Date: 18/7/2011 14 h 39 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\3 Date: 13/7/2011 15 h 8 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 7/7/2011 10 h 13 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 15/6/2011 11 h 10 m User:demezil
*    TWK_model:NO_MODEL
*    comments :update for VSInfo 11.0
* Version int :/main/00PSASWC_D2/3 Date: 12/5/2011 8 h 49 m User:meme
*    TWK_model:NO_MODEL
*    comments :update dds_lib version
* Version dev :\main\branch_demezil_generic_view\1 Date: 10/5/2011 17 h 26 m User:demezil
*    TWK_model:NO_MODEL
*    comments :update dds_lib version
* Version int :/main/00PSASWC_D2/2 Date: 4/3/2011 12 h 17 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 3/3/2011 9 h 44 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 24/2/2011 10 h 13 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version int :/main/00PSASWC_D2/1 Date: 14/2/2011 15 h 16 m User:meme
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\10 Date: 14/2/2011 11 h 9 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\9 Date: 8/2/2011 14 h 0 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 2/2/2011 18 h 21 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/1/2011 14 h 10 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correct IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 7/1/2011 9 h 13 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correct IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 6/1/2011 14 h 25 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correc IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 23/12/2010 14 h 56 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 19 h 25 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :all prototype (except for Stateflow)
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 21/12/2010 14 h 27 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :work in progress
*
*******************************************************************************/

#ifndef VSINFO_H
#define VSINFO_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_VSInfo.h"
#include "SC.h"

/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define VSINFO_DDS_LIB_VERSION_REQ 400

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_

  /* Size for MAP */
#define VSINFO_2_SIZE                            2
#define VSINFO_8_SIZE                            8

  /* Size for Matrix multiply */
#define VSINFO_V_DYN_MAP_M_X                  (5 * BIN0)
#define VSINFO_V_DYN_MAP_M_Y                  (3 * BIN0)

  /* Scheduling */
#define VSINFO_SCHEDULING_10MS                (10)      /* 10 ms */
#define VSINFO_SCHEDULING_40MS                (40)      /* 40 ms */

  /* Min / Max values */
#define VSCTL_ARESESTIM_MIN                   (-10 * BIN10)
#define VSCTL_ARESESTIM_MAX                   (10 * BIN10)

#define VSCTL_AVEH_MIN                        (-10 * BIN10)
#define VSCTL_AVEH_MAX                        (10 * BIN10)

#define VSCTL_SPDVEH_MIN                      (0 * BIN7)
#define VSCTL_SPDVEH_MAX                      (255 * BIN7)

  /* VSCtl_stVehInfo */
#define VSCTL_STVEHINFO_ARRET           (0)
#define VSCTL_STVEHINFO_VERIF_12        (1)
#define VSCTL_STVEHINFO_INIT_12         (2)
#define VSCTL_STVEHINFO_NOMINAL_12      (3)
#define VSCTL_STVEHINFO_DEFAUT_12       (4)

  /* VSCtl_stObsDyn */
#define VSCTL_STOBSDYN_INIT             (0)
#define VSCTL_STOBSDYN_TRANSITOIRE      (1)
#define VSCTL_STOBSDYN_STABILISE        (2)
#define VSCTL_STOBSDYN_ANTISATURATION   (3)

  /* VSCtl_stPTInfo_pt1 */
  /* VSCtl_stPTInfo_pt2 */
#define VSCTL_STPTINFO_ARRET            (0)
#define VSCTL_STPTINFO_VERIF_1          (1)
#define VSCTL_STPTINFO_INIT_1           (2)
#define VSCTL_STPTINFO_NOMINAL_1        (3)
#define VSCTL_STPTINFO_DEFAUT_1         (4)

#define VSCTL_STPTINFO_INIT_7                       (2)
#define VSCTL_STPTINFO_NOMINAL_7                    (3)
#define VSCTL_STPTINFO_DEFAUT_7                     (4)

/* VSCtl_stGrdLkInfo */
#define VSCTL_STGRDLKINFO_ARRET                     (0)
#define VSCTL_STGRDLKINFO_VERIF_35                  (1)
#define VSCTL_STGRDLKINFO_INIT_35                   (2)
#define VSCTL_STGRDLKINFO_NOMINAL_35                (3)
#define VSCTL_STGRDLKINFO_DEFAUT_35                 (4)

/* Ext_stGBxCf */
#define EXT_STGBXCF_BVM                             (0)
#define EXT_STGBXCF_BVA                             (1)
#define EXT_STGBXCF_BVMP                            (2)

/* VSCtl_strConvTraExtModClc */
#define VSCTL_STRCONVTRAEXTMODCLC_ARRET             (0)
#define VSCTL_STRCONVTRAEXTMODCLC_VERIF             (1)
#define VSCTL_STRCONVTRAEXTMODCLC_INIT              (2)
#define VSCTL_STRCONVTRAEXTMODCLC_NOMINAL           (3)
#define VSCTL_STRCONVTRAEXTMODCLC_DEFAULT           (4)

/* VSCtl_strConvTraModClc */
#define VSCTL_STRCONVTRAMODCLC_ARRET                (0)
#define VSCTL_STRCONVTRAMODCLC_VERIF                (1)
#define VSCTL_STRCONVTRAMODCLC_INIT                 (2)
#define VSCTL_STRCONVTRAMODCLC_EXTERNE              (3)
#define VSCTL_STRCONVTRAMODCLC_1_INTERNE            (4)
#define VSCTL_STRCONVTRAMODCLC_2_INTERNE            (5)
#define VSCTL_STRCONVTRAMODCLC_DEFAULT              (6)



#define EXT_BVSLIMCF_PRESENT                        (1)
#define EXT_BVSMAXFCF_PRESENT                       (1)
#define EXT_BVSMAXPCF_PRESENT                       (1)
#define EXT_BVSMAXSCF_PRESENT                       (1)
#define EXT_BVSMAXFCF_ABSENT                        (0)
#define EXT_BVSMAXPCF_ABSENT                        (0)
#define EXT_BVSMAXSCF_ABSENT                        (0)
#define EXT_BVSLIMCF_ABSENT                         (0)

#define VSCTL_BCTLCMDPTTQCF_SC_COUPLE_ROUE               (1)
#define EXT_STDVSREGCF_RVV_PRESENT                  (1)
#define EXT_STDVSREGCF_ACC_PRESENT                  (2)
#define VSCTL_STDIAGSPDVEH_ARRET                    (0)

/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************/
/* VSINFO_Accel_Estim.c */
extern FUNC(void, AUTOMATIC) VSINFO_Accel_Estim(
                            UInt8 VSCtl_stVehInfo_swc_in,
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aAero_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aRes_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReq_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReqRaw_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTIni_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTLim_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMax_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMaxNotCtla_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMin_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMinNotCtla_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMax_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMaxCtla_no1_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMin_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPreCoVSCtlReq_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_swc_out /* BIN7 */);


/*******************************************/
/* VSINFO_Available_Tq_Gmp1_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_Available_Tq_Gmp1_Sl(
                           UInt8 FRM_bDeacVSCtlrTqWhlPTReClc_swc_in,
                           SInt16 PtLim_tqWhlPTPotMaxCtla_no1_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTPotMaxCtla_no2_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTPotMinCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlThPTPotMin_swc_in, /* BIN1 */
                           UInt8 VehEst_bCtlTqWhlPT_swc_in,
                           UInt16 VehEst_rTqWhlPTRe_swc_in, /* BIN7 */
                           SInt16 VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                           SInt16 VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                           SInt16 VSCtl_tqWhlPotMinRsvHiThd_swc_in, /* BIN1 */
                           SInt16 VSCtl_tqWhlPotMinRsvLoThd_swc_in  /* BIN1 */);

/*******************************************/
/* VSINFO_Elabor_Car_Info_Sl.c */

extern FUNC(void, AUTOMATIC) VSINFO_F142_Determiner_Parametres_Vehicule(
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_mVeh_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rdWhl_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_F143_Filtrer_Vitesse_Vehicule(
                                 UInt16 VSCtl_spdVehRef_swc_in, /* BIN7 */
                                 UInt8 VSCtl_stVehInfo_swc_in);

extern FUNC(void, AUTOMATIC) VSINFO_F144_Determiner_Accelerations_Gmp(
                                 UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                 UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                 UInt8 VSCtl_stVehInfo_swc_in,
                                 SInt16 VSCtl_tqWhlPTAplReq_swc_in, /* BIN1 */
                                 SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTIni_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTLim_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPotMax_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPotMaxCtla_no1_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPotMin_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTReal_swc_in /* BIN1*/);

extern FUNC(void, AUTOMATIC) VSINFO_F145_Determiner_Acceleration_Frein(
                                 UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                 UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                 UInt8 VSCtl_stVehInfo_swc_in,
                                 SInt16 VSCtl_tqWhlBrkEstim_swc_in, /* BIN1 */
                                 SInt16 VSCtl_tqWhlBrkReq_swc_in /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSINFO_F1462_Determiner_Acceleration_Gmp_Filtree(
                                 UInt8 VSCtl_stVehInfo_swc_in);

extern FUNC(void, AUTOMATIC) VSINFO_F1463_Determiner_Acceleration_Frein_Filtree(
                                 UInt8 VSCtl_stVehInfo_swc_in);

/*******************************************/
/* VSINFO_Elabor_Info_Brake_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_F122_Determiner_Couples_Roue_Frein(
                           SInt16 Brk_tqWhlBrkEstim_swc_in, /* BIN1 */
                           SInt16 Brk_tqWhlBrkReq_swc_in, /* BIN1 */
                           UInt8 Ext_bTqWhlBrkCf_swc_in,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkEstim_swc_out,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkReq_swc_out);

/*******************************************/
/* VSINFO_Elabor_Info_Gmp_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Gmp_Sl(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no1_swc_out,
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no2_swc_out,
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no3_swc_out,
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlaTqPT_swc_out,
                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_swc_out, /* BIN7 */
                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTRe_swc_out, /* BIN7 */
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stPTInfo_swc_out,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTAplReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReqRaw_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTIni_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTLim_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMax_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMax_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtla_no1_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMinReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCtlReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTReal_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTPotMin_swc_out /* BIN1 */);

/*******************************************/
/* VSINFO_Elabor_Info_Gmp2_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_F11233_Determiner_Couples_Roue_Gmp(
                                                    UInt16 VSCtl_rConvTra_swc_in, /* BIN7 */
                                                    SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqLossTra_swc_in /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSINFO_F11234_Determiner_Potentiels_Couple_Roue_Gmp(
                                                    SInt16 VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPotMinRsvHiThd_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPotMinRsvLoThd_swc_in  /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSINFO_F11235_Determiner_Pilotabilite_Couple_Roue_Gmp(
                                                    UInt8 InjSys_bFuCutOff_swc_in);

extern FUNC(void, AUTOMATIC) VSINFO_F11236_Determiner_Consigne_Couple_Roue_Gmp_Normee(void);

extern FUNC(void, AUTOMATIC) VSINFO_F11237_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar(void);

/*******************************************/
/* VSINFO_Elabor_Info_Las_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_F1332_Determiner_Vitesse_Vehicule_Reference(
                               UInt16 Ext_spdFrntWhl_swc_in, /* BIN7 */
                               UInt16 Ext_spdReWhl_swc_in, /* BIN7 */
                               UInt8 FRM_bRcvVSCtlSpdFrntWhl_swc_in,
                               UInt8 FRM_bRcvVSCtlSpdReWhl_swc_in,
                               UInt16 VSCtl_rTqWhlPTRe_swc_in, /* BIN7 */
                               UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehRef_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_F1342_Determiner_Glissement_Relatif(
                               UInt16 Ext_spdFrntWhl_swc_in, /* BIN7 */
                               UInt16 Ext_spdReWhl_swc_in, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no1_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no2_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_F1352_Determiner_Niveau_Adherence(
                               UInt8 Ext_bDetLoWhlGrip_swc_in);

extern FUNC(void, AUTOMATIC) VSINFO_F1362_Determiner_Regime_Roue_Avant(
                               UInt32 Ext_nFrntWhl_swc_in, /* BIN7 */
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nFrntWhlFil_swc_out /* BIN7 */);

/*******************************************/
/* VSINFO_Elabor_Repair_Req_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_F16_Determiner_Conditions_Maintenance(UInt8 FRM_bDeacVSCtlEngClc_swc_in,
                          UInt8 FRM_bDeacVSCtlGrdLkClc_swc_in,
                          UInt8 FRM_bDeacVSCtlPTClc_swc_in,
                          UInt8 FRM_bDeacVSCtlTraClc_swc_in,
                          UInt8 FRM_bDeacVSCtlVehClc_swc_in,
                          UInt8 VSCtl_stDiagSpdVeh_swc_in,
                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSCtlInfo_swc_out );

/*******************************************/
/* VSINFO_Get_Info_Gmp2_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_F11212_Determiner_Couples_Moteur(
                                   SInt16 EngLim_tqEfcMaxStatVehSpdCtl_swc_in, /* BIN4 */
                                   UInt32 Ext_nFrntWhl_swc_in, /* BIN7 */
                                   SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                   SInt16 TqDem_tqCkEfc_swc_in, /* BIN4 */
                                   SInt16 TqDem_tqCkEfcMax_swc_in, /* BIN4 */
                                   SInt16 TqDem_tqCkEfcMin_swc_in, /* BIN4 */
                                   SInt16 TqSys_tqCkEfcMinFeas_swc_in, /* BIN4 */
                                   SInt16 TqSys_tqCkEfcReq_swc_in, /* BIN4 */
                                   SInt16 TqSys_tqCkEngReal_swc_in, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMaxReq_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMinReq_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMax_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtla_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMin_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinNotCtla_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCMinReq_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtlReq_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSINFO_F11213_Determiner_Regime_Moteur_Filtree(
                                      UInt16 Ext_nEng_swc_in, /* BIN0 */
                                      CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nEngFil_swc_out /* BIN0 */);

/*******************************************/
/* VSINFO_Info_Transmission_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_F112222_Determiner_Taux_Conversion_Couple(
                                                    UInt16 Ext_nEng_swc_in, /* BIN0 */
                                                    UInt32 Ext_nFrntWhl_swc_in, /* BIN7 */
                                                    UInt16 Ext_spdFrntWhl_swc_in, /* BIN7 */
                                                    UInt16 CoPt_rCnvTq_swc_in, /* BIN7 */
                                                    UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                                    UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_grdRatConvTra_swc_out, /* BIN1 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rConvTra_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_F11223_Determiner_Couple_Perte_BV(UInt16 TqCmp_tqCnvLoss_swc_in, /* BIN4 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqLossTra_swc_out /* BIN4 */);


/*******************************************/
/* Re002tev */
extern FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp1_Re002tev_Sf(UInt8 Ext_bVSMaxfCf_swc_in,
                               UInt8 FRM_bDeacVSCtlPTClc_swc_in,
                               UInt8 Ext_bVSLimCf_swc_in,
                               UInt8 Ext_bAvlTqWhlPT_no1_swc_in,
                               UInt8 VSCtl_bCtlEfc_tqWhlPTMax_swc_in,
                               UInt8 Ext_bVSMaxpCf_swc_in,
                               UInt8 Ext_stDVSRegCf_swc_in,
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt8 Ext_bVSMaxsCf_swc_in);

extern FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp2_Re002tev_Sf(SInt16 VSCtl_tqWhlPotMaxRsvHiThd_swc_in,                    /*BIN1*/
                               UInt8 VSCtl_bCtlEfc_tqCkEfcMax_swc_in,
                               SInt8 CoPt_noEgdGearCordIt_swc_in,                   /*BIN0*/
                               SInt16 TqSys_tqCkEfcMinFeas_swc_in,                         /*BIN4*/
                               UInt8 FRM_bRcvVSCtlrConvTra_Int1_swc_in,
                               SInt16 VSCtl_tqWhlPotMinRsvLoThd_swc_in,                    /*BIN1*/
                               UInt8 FRM_bRcvVSCtlrConvTra_Int2_swc_in,
                               SInt16 VSCtl_tqWhlPotMaxRsvLoThd_swc_in,                    /*BIN1*/
                               UInt8 FRM_bDeacVSCtlEngClc_swc_in,
                               UInt8 Ext_stDVSRegCf_swc_in,
                               UInt8 CoPt_bSIPCord_swc_in,
                               UInt16 TqCmp_tqCnvLoss_swc_in,                              /*BIN4*/
                               UInt16 CoPt_rCnvTq_swc_in,                                  /*BIN7*/
                               SInt16 TqSys_tqCkEngReal_swc_in,                            /*BIN4*/
                               UInt16 Ext_spdFrntWhl_swc_in,                               /*BIN7*/
                               UInt8 FRM_bRcvVSCtlrConvTra_Ext_swc_in,
                               UInt8 Ext_bPosnGBxCf_swc_in,
                               UInt8 ECU_bAuthVSCtlIni_swc_in,
                               UInt8 CoPTSt_stEng_swc_in,
                               SInt16 TqDem_tqCkEfcMin_swc_in,                             /*BIN4*/
                               SInt16 TqCmp_tqSumLossCmp_swc_in,                           /*BIN4*/
                               UInt8 Ext_bRatConvTraCf_swc_in,
                               UInt8 CoPt_stClu_swc_in,
                               UInt8 Ext_stGBxCf_swc_in,
                               SInt16 TqDem_tqCkEfcMax_swc_in,                             /*BIN4*/
                               UInt8 InjSys_bFuCutOff_swc_in,
                               UInt32 Ext_nFrntWhl_swc_in,                                 /*BIN7*/
                               UInt8 Ext_stPTCf_swc_in,
                               UInt8 Ext_bVSLimCf_swc_in,
                               UInt8 Ext_bSpdFrntWhlCf_swc_in,
                               UInt16 VSCtl_rdWhl_swc_in,                                  /*BIN7*/
                               SInt16 TqSys_tqCkEfcReq_swc_in,                             /*BIN4*/
                               UInt8 Ext_bVSMaxfCf_swc_in,
                               UInt16 VSCtl_spdVeh_swc_in,                                 /*BIN7*/
                               UInt8 Ext_bCluPedPrss_swc_in,
                               UInt16 Ext_nEng_swc_in,                                     /*BIN0*/
                               UInt8 FRM_bDeacVSCtlTraClc_swc_in,
                               UInt8 Ext_bVSMaxpCf_swc_in,
                               SInt16 TqDem_tqCkEfc_swc_in,                                /*BIN4*/
                               UInt8 CoPt_posnLev_swc_in,
                               UInt8 Ext_bRotSpdFrntWhlCf_swc_in,
                               UInt8 Ext_bVSMaxsCf_swc_in,
                               SInt16 EngLim_tqEfcMaxStatVehSpdCtl_swc_in,                 /*BIN4*/
                               SInt16 VSCtl_tqWhlPotMinRsvHiThd_swc_in,                    /*BIN1*/
                               UInt8 FRM_bDeacVSCtlNoGearChgClc_swc_in,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMin_swc_out,                             /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMax_swc_out,                             /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMinReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMaxReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqLossTra_swc_out,                              /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCtlReq_swc_out,                   /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rConvTra_swc_out,                               /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_grdRatConvTra_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCMinReq_swc_out,                  /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bNbGearEgdChg_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nEngFil_swc_out);                                /*BIN0*/

extern FUNC(void, AUTOMATIC) VSINFO_Inf_Mnt_Re002tev_Sf(UInt8 VSCtl_stPTInfo_swc_in,
                               UInt32 Ext_nFrntWhl_swc_in,                                 /*BIN7*/
                               UInt8 Ext_stPTCf_swc_in,
                               UInt8 Ext_bSpdReWhlCf_swc_in,
                               UInt8 FRM_bDeacVSCtlGrdLkClc_swc_in,
                               UInt8 FRM_bRcvVSCtlSpdReWhl_swc_in,
                               UInt8 Ext_bDetLoWhlGrip_swc_in,
                               UInt8 Ext_bSpdFrntWhlCf_swc_in,
                               UInt16 VSCtl_rTqWhlPTRe_swc_in,                             /*BIN7*/
                               UInt8 FRM_bRcvVSCtlSpdFrntWhl_swc_in,
                               UInt8 FRM_bDeacVSCtlLoWhlGripClc_swc_in,
                               UInt8 Ext_bTqWhlBrkCf_swc_in,
                               UInt16 Veh_spdVeh_swc_in,                                   /*BIN7*/
                               SInt16 Brk_tqWhlBrkEstim_swc_in,                            /*BIN1*/
                               UInt8 FRM_bDeacSpdVehClc_swc_in,
                               UInt8 Ext_bDetLoWhlGripCf_swc_in,
                               UInt8 FRM_bDeacVSCtlBrkClc_swc_in,
                               UInt8 FRM_bDeacVSCtlWhlSlipClc_swc_in,
                               SInt16 Brk_tqWhlBrkReq_swc_in,                              /*BIN1*/
                               UInt8 FRM_bDeacNFrntWhlClc_swc_in,
                               UInt16 Ext_spdReWhl_swc_in,                                 /*BIN7*/
                               UInt16 Ext_spdFrntWhl_swc_in,                               /*BIN7*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stDiagSpdVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGrdLkInfo_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehRef_swc_out,                              /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkReq_swc_out,                            /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoSpdVehClc_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunSpdVehClc_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nFrntWhlFil_swc_out,                            /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkEstim_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no1_swc_out,                           /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no2_swc_out);                           /*BIN7*/

/*******************************************/
/* VSINFO_Re003tev_Sf.c */
extern FUNC(void, AUTOMATIC) VSINFO_Re003tev_Sf(SInt16 VSCtl_tqWhlPTLim_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in,                    /*BIN1*/
                               UInt8 Ext_stGBxCf_swc_in,
                               SInt16 VSCtl_tqWhlBrkReq_swc_in,                            /*BIN1*/
                               UInt8 VSCtl_stPTInfo_swc_in,
                               SInt16 VSCtl_tqWhlPTReal_swc_in,                            /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMin_swc_in,                             /*BIN1*/
                               SInt16 VSCtl_tqWhlPTAplReq_swc_in,                          /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMax_swc_in,                             /*BIN1*/
                               UInt8 Ext_bBrkDynCf_swc_in,
                               SInt16 VSCtl_tqWhlPTPotMaxCtla_no1_swc_in,                  /*BIN1*/
                               UInt8 Brk_bBrkDyn_swc_in,
                               SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in,                   /*BIN1*/
                               UInt16 VSCtl_spdVehRef_swc_in,                              /*BIN7*/
                               UInt8 Ext_bBrkPedPrss_swc_in,
                               UInt8 VSCtl_stGrdLkInfo_swc_in,
                               UInt8 Ext_bBrkAutoCf_swc_in,
                               UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                               UInt8 FRM_bDeacVSCtlVehClc_swc_in,
                               SInt16 VSCtl_tqWhlPTPotMin_swc_in,                          /*BIN1*/
                               SInt16 VSCtl_aVehReq_swc_in,                         /*BIN10*/
                               SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in,                       /*BIN1*/
                               SInt16 VSCtl_tqWhlPTPotMax_swc_in,                          /*BIN1*/
                               SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in,                      /*BIN1*/
                               UInt8 Brk_bBrkAuto_swc_in,
                               SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in,                      /*BIN1*/
                               SInt16 VSCtl_tqWhlBrkEstim_swc_in,                          /*BIN1*/
                               UInt8 Ext_bPrkBrk_swc_in,
                               SInt16 VSCtl_tqWhlPTIni_swc_in,                             /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVehInfo_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bLgtCtlDyn_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_mVeh_swc_out,                                   /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rdWhl_swc_out);


/*******************************************/
/* VSINFO_Speed_Estim.c */
extern FUNC(void, AUTOMATIC) VSINFO_Speed_Estim(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_swc_out /* BIN7 */);

/*******************************************/
/* VSINFO_Wheel_Info_Gmp1_Sl.c */
extern FUNC(void, AUTOMATIC) VSINFO_Wheel_Info_Gmp1_Sl(
                           UInt8 Ext_bAvlTqWhlPT_no1_swc_in,
                           UInt8 Ext_bAvlTqWhlPT_no2_swc_in,
                           UInt8 Ext_bAvlTqWhlPT_no3_swc_in,
                           SInt16 PtLim_tqWhlPTMaxCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTMinCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlThPTMin_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                           SInt16 VehEst_tqWhlPTRealEstim_swc_in, /* BIN1 */
                           SInt16 VehEst_tqWhlPTReq_swc_in, /* BIN1 */
                           SInt16 VSCtl_aAero_swc_in, /* BIN10 */
                           UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                           UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                           SInt16 VSCtl_rSlop_swc_in /* BIN7 */);

/*******************************************/
/* VSINFO_Elabor_State_Info_Sf.c */
extern FUNC(void, AUTOMATIC) VSINFO_Elabor_State_Info_Sf(UInt8 VSCtl_stVehInfo_swc_in,
                               UInt8 VSCtl_stPTInfo_swc_in,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSCtlInfo_swc_out);

/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/
extern FUNC(void, AUTOMATIC) VSINFO_Accel_Estim_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aAero_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aRes_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReqRaw_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTIni_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTLim_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMaxNotCtla_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMin_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMinNotCtla_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMaxCtla_no1_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMin_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPreCoVSCtlReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_Available_Tq_Gmp1_Sl_Init(void);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Car_Info_Sl_Init(
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_mVeh_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rdWhl_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Brake_Sl_Init(
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkEstim_swc_out,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkReq_swc_out);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Gmp_Sl_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no1_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no2_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no3_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlaTqPT_swc_out,
                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_swc_out, /* BIN7 */
                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTRe_swc_out, /* BIN7 */
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stPTInfo_swc_out,
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTAplReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReqRaw_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTIni_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTLim_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMax_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMax_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtla_no1_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMinReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCtlReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTReal_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTPotMin_swc_out /* BIN1 */);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Gmp2_Sl_Init(void);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Las_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no1_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no2_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nFrntWhlFil_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehRef_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_Repair_Req_Sl_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSCtlInfo_swc_out);

extern FUNC(void, AUTOMATIC) VSINFO_Get_Info_Gmp2_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMaxReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMinReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMax_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtla_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMin_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinNotCtla_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCMinReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtlReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nEngFil_swc_out /* BIN0 */);

extern FUNC(void, AUTOMATIC) VSINFO_Info_Transmission_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_grdRatConvTra_swc_out, /* BIN1 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rConvTra_swc_out, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqLossTra_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp1_Re002tev_Sf_Init(void);

extern FUNC(void, AUTOMATIC) VSINFO_Ela_Gmp2_Re002tev_Sf_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMin_swc_out,                             /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMax_swc_out,                             /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMinReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMinNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcDrvMaxReq_swc_out,                       /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcMaxNotCtla_swc_out,                      /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqLossTra_swc_out,                              /*BIN4*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCtlReq_swc_out,                   /*BIN4*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rConvTra_swc_out,                               /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_grdRatConvTra_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoRatConvTraClc_swc_out,
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqCkEfcPreCoVSCMinReq_swc_out,                  /*BIN4*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bNbGearEgdChg_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nEngFil_swc_out);                                /*BIN0*/


extern FUNC(void, AUTOMATIC) VSINFO_Inf_Mnt_Re002tev_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stDiagSpdVeh_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stGrdLkInfo_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehRef_swc_out,                              /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkReq_swc_out,                            /*BIN1*/
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoSpdVehClc_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunSpdVehClc_swc_out,
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC)  VSCtl_nFrntWhlFil_swc_out,                            /*BIN7*/
                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)  VSCtl_tqWhlBrkEstim_swc_out,                          /*BIN1*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no1_swc_out,                           /*BIN7*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rWhlSlip_no2_swc_out);                           /*BIN7*/

extern FUNC(void, AUTOMATIC) VSINFO_Re003tev_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVehInfo_swc_out,
                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bLgtCtlDyn_swc_out,
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_mVeh_swc_out,                                   /*BIN0*/
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_rdWhl_swc_out);

extern FUNC(void, AUTOMATIC) VSINFO_Speed_Estim_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_swc_out /* BIN7 */);

extern FUNC(void, AUTOMATIC) VSINFO_Wheel_Info_Gmp1_Sl_Init(void);

/* Feature Global Function */
extern FUNC(UInt32, AUTOMATIC) VSInfo_Timer_1ms_U32(void);

extern FUNC(void, AUTOMATIC) VSINFOH_Dds_M_Prod_Matrix_SInt32(P2CONST(SInt32, AUTOMATIC, AUTOMATIC) matrix_in1,
                              UInt8 nb_row_matrix_in1,
                              UInt8 nb_col_matrix_in1,
                              SInt8 nb_shift_bin_in1,
                              P2CONST(SInt32, AUTOMATIC, AUTOMATIC) matrix_in2,
                              UInt8 nb_col_matrix_in2,
                              SInt8 nb_shift_bin_in2,
                              P2VAR(SInt32, AUTOMATIC, AUTOMATIC) matrix_out,
                              SInt8 nb_shift_bin_scalaire);

extern FUNC(void, AUTOMATIC) VSINFO_Elabor_State_Info_Sf_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSCtlInfo_swc_out);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */
#define DDS_VSINFO_1MS_U32_TIME  VSInfo_Timer_1ms_U32()

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

#endif

