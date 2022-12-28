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
* Ref X:\integration_view_00PSASWC_D520D01\blois_psa_sstg\Software\Appli\VSLim\src\VSLIM_Det_Cond_Func.c
* Version int :/main/L01_03/1 Date: 6/1/2012 15 h 3 m User:esnault 
*    TWK_model:VSLIM_Det_Cond_Func_L01_030_IMPL1
*    comments :for VSLim 12.0: only calibration value update
* Version dev :\main\branch_morisseau_vslim_euro6\2 Date: 16/11/2011 9 h 26 m User:morisseau 
*    TWK_model:VSLIM_Det_Cond_Func_L01_030_IMPL1
*    comments :for VSLim 12.0: only calibration value update
* Version int :/main/L01_02/1 Date: 30/8/2011 11 h 51 m User:meme
*    TWK_model:VSLIM_Det_Cond_Func_L01_020_IMPL1
*    comments :for VSLim 11.0
* Version dev :\main\branch_morisseau_vslim_euro6\1 Date: 27/7/2011 11 h 47 m User:morisseau
*    TWK_model:VSLIM_Det_Cond_Func_L01_020_IMPL1
*    comments :for VSLim 11.0
* Version int :/main/L01_01/3 Date: 3/2/2011 15 h 13 m User:esnault
*    TWK_model:VSLIM_Det_Cond_Func_L01_010_IMPL1_D
*    comments :for VSLim 10.1
* Version int :/main/L01_01/2 Date: 25/1/2011 15 h 38 m User:esnault
*    TWK_model:VSLIM_Det_Cond_Func_L01_010_IMPL1
*    comments :For VSLim 10.0 : corrections following TU
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSLim.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define VSC_8_SIZE                            8

#define VSLIM_N255_BIN7                     (SInt32)(-255 * BIN7)
#define VSLIM_P255_BIN7                     (SInt32)(255 * BIN7)

/* vsctl_bdrvovrdvslim_tmp */

#define VSLIM_TMP_FAUX                          ((UInt32)0)
#define VSLIM_TMP_TEMPO                         ((UInt32)1)
#define VSLIM_TMP_NON_TEMPO                     ((UInt32)2)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSLimReqFil; /* BIN7 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"

/* 8-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSLim;
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"



/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Scalar Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Map Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* 8-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSLim;
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSLimReq;
VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_Brk;
VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_Fct; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_pt;
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSLIM_START_SEC_CALIB_16BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVhEAcvOvrdVSLim_HysHi_C = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVhEAcvWaitVSLim_HysHi_C = (CONST(UInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAcvOvrdVSLim_HysHi_C = (CONST(SInt16, AUTOMATIC))(2 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAcvOvrdVSLim_HysLo_C = (CONST(SInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAcvWaitVSLim_HysHi_C = (CONST(SInt16, AUTOMATIC))(5 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAcvWaitVSLim_HysLo_C = (CONST(SInt16, AUTOMATIC))(4 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehOvrdVSLim_HysHi_C = (CONST(SInt16, AUTOMATIC))(5 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehOvrdVSLim_HysLo_C = (CONST(SInt16, AUTOMATIC))(5 * BIN7);
#define VSLIM_STOP_SEC_CALIB_16BIT
#include "VSLim_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSLIM_START_SEC_CALIB_8BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvOvrdFromANEVSLim_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacCtlnoGearVSLim_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacTyreWarnVSLim_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDrvOvrdFromAEVSLim_C = (CONST(UInt8, AUTOMATIC))(24 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDrvOvrdFromANEVSLim_C = (CONST(UInt8, AUTOMATIC))(24 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDrvOvrdFromWaitVSLim_C = (CONST(UInt8, AUTOMATIC))(24 * BIN0);
#define VSLIM_STOP_SEC_CALIB_8BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSLIM_START_SEC_CARTO_16BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVeh_AuthVSLim_HysHi_T
[VSC_8_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(1 * BIN10),
(SInt16)(1 * BIN10), (SInt16)(1 * BIN10), (SInt16)(1.9296875 * BIN10),
(SInt16)(10 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVeh_AuthVSLim_HysLo_T
[VSC_8_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(1.4296875 * BIN10),
(SInt16)(9 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdE_aVehVSLim_HysHi_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN7), (SInt16)(-5.0078125 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(2.6015625 * BIN7), (SInt16)(5 * BIN7),
(SInt16)(25.703125 * BIN7), (SInt16)(29 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdE_aVehVSLim_HysLo_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN7), (SInt16)(-5 * BIN7), (SInt16)(-0.0078125 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(2.6015625 * BIN7), (SInt16)(5 * BIN7),
(SInt16)(25.703125 * BIN7), (SInt16)(29 * BIN7)
};

#define VSLIM_STOP_SEC_CARTO_16BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSLIM_START_SEC_VAR_UNSPECIFIED
#include "VSLim_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_aveh_authvslim_hyshi_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_aveh_authvslim_hyslo_t_sav;
#define VSLIM_STOP_SEC_VAR_UNSPECIFIED
#include "VSLim_MemMap.h"

/* 8-bits variable definition */
#define VSLIM_START_SEC_VAR_8BIT
#include "VSLim_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bdrvovrdvslim_tmp;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stmonvslim_cpy;
#define VSLIM_STOP_SEC_VAR_8BIT
#include "VSLim_MemMap.h"

/* 16-bits variable definition */
#define VSLIM_START_SEC_VAR_16BIT
#include "VSLim_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) vsctl_spdvehvslimreqfil_cpy;
#define VSLIM_STOP_SEC_VAR_16BIT
#include "VSLim_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVeh_AuthVSLim_HysHi; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVeh_AuthVSLim_HysLo; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_spdErr_aVehVSLim_HysHi; /* BIN7 */
/* <PRQA_COMMENT><3229> Variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_spdErr_aVehVSLim_HysLo; /* BIN7 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"

/* 8-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvLimVSCtlReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSLimFromOvrd;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSLimFromWait;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bGearCtlVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bInhVSLimReq_Brk;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bInhVSLimReq_pt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bModLimVSCtlReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bOvrdVSLimFromANE;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bTyreWarnVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilDrvOvrdVSLim; /* BIN0 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSLIM_START_SEC_CONST_UNSPECIFIED
#include "VSLim_MemMap.h"
STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_AVEH_AUTHVSLIM_HYSHI_T_APM = {
&vsctl_aveh_authvslim_hyshi_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdE_aVehVSLim_HysHi_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVeh_AuthVSLim_HysHi_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_AVEH_AUTHVSLIM_HYSLO_T_APM = {
&vsctl_aveh_authvslim_hyslo_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdE_aVehVSLim_HysLo_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVeh_AuthVSLim_HysLo_T[0]
};

#define VSLIM_STOP_SEC_CONST_UNSPECIFIED
#include "VSLim_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSLIM_START_SEC_CODE
#include "VSLim_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSLIM_F4121_Determiner_Conditions_Fonctionnement_GMP(UInt8 ext_stctlcmdpttqpotcf_par,
                                                                                  UInt8 ext_stgbxcf_par,
                                                                                  UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41211_Determiner_Condition_Disponibilite_Controle_Rapport_BV(UInt8 ext_stctlcmdpttqpotcf_par,
                                                                                                  UInt8 ext_stgbxcf_par,
                                                                                                  UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41212_Determiner_Conditions_Maintenance_GMP(void);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41213_Determiner_Demande_Inhibition_GMP(void);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4122_Determiner_Conditions_Fonctionnement_Frein_LAS(UInt8 ext_btyrewarn_par,
                                                                                          UInt8 ext_btyrewarncf_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41221_Determiner_Condition_Alerte_Pneumatiques(UInt8 ext_btyrewarn_par,
                                                                                      UInt8 ext_btyrewarncf_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41222_Determiner_Conditions_Maintenance_Frein_LAS(void);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41223_Determiner_Demande_Inhibition_Frein_LAS(void);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4123_Determiner_Conditions_Fonctionnement_Fonction(
                                            UInt8 vsctl_stvslimextd_par,
                                            UInt8 ext_baccphdpt_par,
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt8 ext_stacvregvsctlreq_par,
                                            UInt8 ext_stmodregvsctlreq_par,
                                            SInt16 vsctl_aveh_par, /* BIN10 */
                                            UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                            UInt16 veh_spdveh_par, /* BIN7 */
                                            UInt8 frm_bdifastdeacvsctlvslim_par,
                                            UInt8 frm_binhvslim_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bfastdeacvslimreq_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41231_Determiner_Condition_Selection_Fonction(UInt8 ext_stmodregvsctlreq_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41232_Determiner_Condition_Activation_Fonction(UInt8 ext_stacvregvsctlreq_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41233_Determiner_Demande_Desactivation_Rapide(
                                            UInt8 ext_baccphdpt_par,
                                            UInt8 frm_bdifastdeacvsctlvslim_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bfastdeacvslimreq_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41234_Determiner_Reprise_Pedale_Accelerateur(UInt8 vsctl_stvslimextd_par,
                                                                                    UInt8 vsctl_bfastdeacvslimreq_par,
                                                                                    UInt8 ext_stacvregvsctlreq_par,
                                                                                    UInt8 ext_stmodregvsctlreq_par,
                                                                                    UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                                                                    SInt16 vsctl_aveh_par, /* BIN10 */
                                                                                    UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                    UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F412341_Determiner_Seuils_Acceleration_Vehicule(UInt8 ext_stacvregvsctlreq_par,
                                                                                    UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                    UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F412342_Determiner_Condition_Reprise_Depuis_Attente(SInt16 vsctl_aveh_par, /* BIN10 */
                                                                                        UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                        UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F412343_Determiner_Condition_Reprise_Depuis_Reprise(SInt16 vsctl_aveh_par, /* BIN10 */
                                                                                        UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                        UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F412344_Determiner_Condition_Reprise_Depuis_Active_Non_Effective(UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F412345_Determiner_Reprise(UInt8 vsctl_stvslimextd_par,
                                                                UInt8 ext_stacvregvsctlreq_par,
                                                                UInt8 ext_stmodregvsctlreq_par,
                                                                UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                                                UInt8 vsctl_bfastdeacvslimreq_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41235_Determiner_Demande_Inhibition(UInt8 frm_binhvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F41236_Determiner_Condition_Conditions_Maintenance_Fonction(UInt8 frm_binhvslim_par,
                                                                                                  UInt8 vsctl_bfastdeacvslimreq_par);

/*******************************************************************************
*
* Function Name : VSLIM_Det_Cond_Func
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Det_Cond_Func(UInt8 Ext_bAccPHdPt_swc_in,
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
                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bFastDeacVSLimReq_swc_out )
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.04.1 */

    vsctl_stmonvslim_cpy = VSCtl_stMonVSLim;
    VSLIM_F4121_Determiner_Conditions_Fonctionnement_GMP(Ext_stCtlCmdPTTqPotCf_swc_in,
                                                            Ext_stGBxCf_swc_in,
                                                            VSCtl_stCtl_noGear_swc_in);

    VSLIM_F4122_Determiner_Conditions_Fonctionnement_Frein_LAS(Ext_bTyreWarn_swc_in,
                                                                Ext_bTyreWarnCf_swc_in);

    VSLIM_F4123_Determiner_Conditions_Fonctionnement_Fonction(VSCtl_stVSLimExtd_swc_in,
                                                                Ext_bAccPHdPt_swc_in,
                                                                Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                                                Ext_stAcvRegVSCtlReq_swc_in,
                                                                Ext_stModRegVSCtlReq_swc_in,
                                                                VSCtl_aVeh_swc_in, /* BIN10 */
                                                                VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                                                Veh_spdVeh_swc_in, /* BIN7 */
                                                                FRM_bDiFastDeacVSCtlVSLim_swc_in,
                                                                FRM_bInhVSLim_swc_in,
                                                                VSCtl_bFastDeacVSLimReq_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_F4121_Determiner_Conditions_Fonctionnement_GMP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4121_Determiner_Conditions_Fonctionnement_GMP(UInt8 ext_stctlcmdpttqpotcf_par,
                                                                                  UInt8 ext_stgbxcf_par,
                                                                                  UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.05.1 */
    VSLIM_F41211_Determiner_Condition_Disponibilite_Controle_Rapport_BV(ext_stctlcmdpttqpotcf_par,
                                                                          ext_stgbxcf_par,
                                                                          vsctl_stctl_nogear_par);

    VSLIM_F41212_Determiner_Conditions_Maintenance_GMP();

    VSLIM_F41213_Determiner_Demande_Inhibition_GMP();
}

/*******************************************************************************
*
* Function Name : VSLIM_F41211_Determiner_Condition_Disponibilite_Controle_Rapport_BV
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41211_Determiner_Condition_Disponibilite_Controle_Rapport_BV(UInt8 ext_stctlcmdpttqpotcf_par,
                                                                                                  UInt8 ext_stgbxcf_par,
                                                                                                  UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.45.0 */
    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bGearCtlVSLim)
    {
        if( (VSLIM_STCTLCMDPTTQPOTCF_RAPPORT != (UInt32)ext_stctlcmdpttqpotcf_par)  ||
            (   (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
                (   ((UInt32)DDS_TRUE == (UInt32)VSCtl_bDeacCtlnoGearVSLim_C)   ||
                    (VSLIM_EXT_STGBXCF_BVM == (UInt32)ext_stgbxcf_par)  ||
                    (   (VSLIM_EXT_STGBXCF_BVMP == (UInt32)ext_stgbxcf_par) &&
                        (VSLIM_VSCTL_STCTL_NOGEAR_DEFAUT != (UInt32)vsctl_stctl_nogear_par))    ||
                    (   (VSLIM_EXT_STGBXCF_BVA == (UInt32)ext_stgbxcf_par)  &&
                        (VSLIM_VSCTL_STCTL_NOGEAR_DEFAUT != (UInt32)vsctl_stctl_nogear_par)))))
        {
            VSCtl_bGearCtlVSLim = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STCTLCMDPTTQPOTCF_RAPPORT == (UInt32)ext_stctlcmdpttqpotcf_par)&&
            (   (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)||
                (   (   (VSLIM_EXT_STGBXCF_BVMP == (UInt32)ext_stgbxcf_par)||
                        (VSLIM_EXT_STGBXCF_BVA == (UInt32)ext_stgbxcf_par))&&
                    ((UInt32)DDS_FALSE == (UInt32)VSCtl_bDeacCtlnoGearVSLim_C)&&
                    (VSLIM_VSCTL_STCTL_NOGEAR_DEFAUT == (UInt32)vsctl_stctl_nogear_par))))
        {
            VSCtl_bGearCtlVSLim = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41212_Determiner_Conditions_Maintenance_GMP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41212_Determiner_Conditions_Maintenance_GMP(void)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.46.0 */
    if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
        ((UInt32)DDS_TRUE == (UInt32)VSCtl_bGearCtlVSLim)   )
    {
        VSCtl_stDeacVSLimReq_pt = DDS_TRUE;
    }
    else
    {
        VSCtl_stDeacVSLimReq_pt = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41213_Determiner_Demande_Inhibition_GMP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41213_Determiner_Demande_Inhibition_GMP(void)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.47.0 */
    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bInhVSLimReq_pt)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bGearCtlVSLim)  )
        {
            VSCtl_bInhVSLimReq_pt = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
            ((UInt32)DDS_FALSE != (UInt32)VSCtl_bGearCtlVSLim)  )
        {
            VSCtl_bInhVSLimReq_pt = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F4122_Determiner_Conditions_Fonctionnement_Frein_LAS
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4122_Determiner_Conditions_Fonctionnement_Frein_LAS(UInt8 ext_btyrewarn_par,
                                                                                          UInt8 ext_btyrewarncf_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.48.0 */
    VSLIM_F41221_Determiner_Condition_Alerte_Pneumatiques(ext_btyrewarn_par,
                                                          ext_btyrewarncf_par);

    VSLIM_F41222_Determiner_Conditions_Maintenance_Frein_LAS();

    VSLIM_F41223_Determiner_Demande_Inhibition_Frein_LAS();
}

/*******************************************************************************
*
* Function Name : VSLIM_F41221_Determiner_Condition_Alerte_Pneumatiques
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41221_Determiner_Condition_Alerte_Pneumatiques(UInt8 ext_btyrewarn_par,
                                                                                      UInt8 ext_btyrewarncf_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.49.0 */
    if(VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)
    {
        VSCtl_bTyreWarnVSLim = DDS_TRUE;
    }
    else
    {
        if( ((UInt32)DDS_TRUE   == (UInt32)VSCtl_bDeacTyreWarnVSLim_C)  ||
            ((UInt32)DDS_TRUE   != (UInt32)ext_btyrewarncf_par) )
        {
            VSCtl_bTyreWarnVSLim = DDS_FALSE;
        }
        else
        {
            VSCtl_bTyreWarnVSLim = ext_btyrewarn_par;
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41222_Determiner_Conditions_Maintenance_Frein_LAS
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41222_Determiner_Conditions_Maintenance_Frein_LAS(void)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.50.0 */
    if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
        ((UInt32)DDS_TRUE == (UInt32)VSCtl_bTyreWarnVSLim)  )
    {
        VSCtl_stDeacVSLimReq_Brk = DDS_TRUE;
    }
    else
    {
        VSCtl_stDeacVSLimReq_Brk = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41223_Determiner_Demande_Inhibition_Frein_LAS
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41223_Determiner_Demande_Inhibition_Frein_LAS(void)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.51.0 */
    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bInhVSLimReq_Brk)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bTyreWarnVSLim) )
        {
            VSCtl_bInhVSLimReq_Brk = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
            ((UInt32)DDS_FALSE != (UInt32)VSCtl_bTyreWarnVSLim) )
        {
            VSCtl_bInhVSLimReq_Brk = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F4123_Determiner_Conditions_Fonctionnement_Fonction
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4123_Determiner_Conditions_Fonctionnement_Fonction(
                                            UInt8 vsctl_stvslimextd_par,
                                            UInt8 ext_baccphdpt_par,
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt8 ext_stacvregvsctlreq_par,
                                            UInt8 ext_stmodregvsctlreq_par,
                                            SInt16 vsctl_aveh_par, /* BIN10 */
                                            UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                            UInt16 veh_spdveh_par, /* BIN7 */
                                            UInt8 frm_bdifastdeacvsctlvslim_par,
                                            UInt8 frm_binhvslim_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bfastdeacvslimreq_ptr)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR..FR.10.1 */
    VSLIM_F41231_Determiner_Condition_Selection_Fonction(ext_stmodregvsctlreq_par);

    VSLIM_F41232_Determiner_Condition_Activation_Fonction(ext_stacvregvsctlreq_par);

    VSLIM_F41233_Determiner_Demande_Desactivation_Rapide(ext_baccphdpt_par,
                                                            frm_bdifastdeacvsctlvslim_par,
                                                            vsctl_bfastdeacvslimreq_ptr);

    VSLIM_F41234_Determiner_Reprise_Pedale_Accelerateur(vsctl_stvslimextd_par,
                                                        *vsctl_bfastdeacvslimreq_ptr,
                                                        ext_stacvregvsctlreq_par,
                                                        ext_stmodregvsctlreq_par,
                                                        vsctl_bdrvovrdvslim_aveh_par,
                                                        vsctl_aveh_par, /* BIN10 */
                                                        ext_spdvehvslimreq_par, /* BIN0 */
                                                        veh_spdveh_par /* BIN7 */);

    VSLIM_F41235_Determiner_Demande_Inhibition(frm_binhvslim_par);

    VSLIM_F41236_Determiner_Condition_Conditions_Maintenance_Fonction(frm_binhvslim_par,
                                                                      *vsctl_bfastdeacvslimreq_ptr);
}

/*******************************************************************************
*
* Function Name : VSLIM_F41231_Determiner_Condition_Selection_Fonction
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41231_Determiner_Condition_Selection_Fonction(UInt8 ext_stmodregvsctlreq_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.52.0 */
    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bModLimVSCtlReq)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
            (VSLIM_STMODREGVSCTLREQ_REGULATION_LVV == (UInt32)ext_stmodregvsctlreq_par) )
        {
            VSCtl_bModLimVSCtlReq = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
            (VSLIM_STMODREGVSCTLREQ_REGULATION_LVV != (UInt32)ext_stmodregvsctlreq_par) )
        {
            VSCtl_bModLimVSCtlReq = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41232_Determiner_Condition_Activation_Fonction
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41232_Determiner_Condition_Activation_Fonction(UInt8 ext_stacvregvsctlreq_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.53.0 */
    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvLimVSCtlReq)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
            (VSLIM_STACVREGVSCTLREQ_REGULATION_LVV == (UInt32)ext_stacvregvsctlreq_par) )
        {
            VSCtl_bAcvLimVSCtlReq = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
            (VSLIM_STACVREGVSCTLREQ_REGULATION_LVV != (UInt32)ext_stacvregvsctlreq_par) )
        {
            VSCtl_bAcvLimVSCtlReq = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41233_Determiner_Demande_Desactivation_Rapide
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41233_Determiner_Demande_Desactivation_Rapide(
                                            UInt8 ext_baccphdpt_par,
                                            UInt8 frm_bdifastdeacvsctlvslim_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bfastdeacvslimreq_ptr)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.11.2 */
    if( (VSLIM_STMONVSLIM_ARRET == (UInt32)vsctl_stmonvslim_cpy)    ||
        ((UInt32)DDS_TRUE == (UInt32)frm_bdifastdeacvsctlvslim_par) )
    {
        *vsctl_bfastdeacvslimreq_ptr = DDS_FALSE;
    }
    else
    {
        *vsctl_bfastdeacvslimreq_ptr = ext_baccphdpt_par;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41234_Determiner_Reprise_Pedale_Accelerateur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41234_Determiner_Reprise_Pedale_Accelerateur(UInt8 vsctl_stvslimextd_par,
                                                                                    UInt8 vsctl_bfastdeacvslimreq_par,
                                                                                    UInt8 ext_stacvregvsctlreq_par,
                                                                                    UInt8 ext_stmodregvsctlreq_par,
                                                                                    UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                                                                    SInt16 vsctl_aveh_par, /* BIN10 */
                                                                                    UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                    UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.12.1 */

    vsctl_spdvehvslimreqfil_cpy = VSCtl_spdVehVSLimReqFil;

    VSLIM_F412341_Determiner_Seuils_Acceleration_Vehicule(ext_stacvregvsctlreq_par,
                                                            ext_spdvehvslimreq_par, /* BIN0 */
                                                            veh_spdveh_par /* BIN7 */);

    VSLIM_F412342_Determiner_Condition_Reprise_Depuis_Attente(vsctl_aveh_par, /* BIN10 */
                                                                ext_spdvehvslimreq_par, /* BIN0 */
                                                                veh_spdveh_par /* BIN7 */);

    VSLIM_F412343_Determiner_Condition_Reprise_Depuis_Reprise(vsctl_aveh_par, /* BIN10 */
                                                                ext_spdvehvslimreq_par, /* BIN0 */
                                                                veh_spdveh_par /* BIN7 */);

    VSLIM_F412344_Determiner_Condition_Reprise_Depuis_Active_Non_Effective(veh_spdveh_par /* BIN7 */);

    VSLIM_F412345_Determiner_Reprise(vsctl_stvslimextd_par,
                                        ext_stacvregvsctlreq_par,
                                        ext_stmodregvsctlreq_par,
                                        vsctl_bdrvovrdvslim_aveh_par,
                                        vsctl_bfastdeacvslimreq_par);
}

/*******************************************************************************
*
* Function Name : VSLIM_F412341_Determiner_Seuils_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F412341_Determiner_Seuils_Acceleration_Vehicule(UInt8 ext_stacvregvsctlreq_par,
                                                                                    UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                    UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.13.1 */
    SInt16 vsctl_spderr_avehvslim_hyshi;    /* BIN7 */
    SInt16 vsctl_spderr_avehvslim_hyslo;    /* BIN7 */
    SInt16 vsctl_aveh_authvslim_hyshi_t;    /* BIN10 */
    SInt16 vsctl_aveh_authvslim_hyslo_t;    /* BIN10 */
    SInt32 temp_s32;

    /* [-500;255]BIN7 = ([0;255]BIN0 * BIN7 - [0;500]BIN7) */
    temp_s32 = ((SInt32)ext_spdvehvslimreq_par * BIN7) - (SInt32)veh_spdveh_par;
    vsctl_spderr_avehvslim_hyshi = (SInt16)DDS_M_MAX(temp_s32,VSLIM_N255_BIN7);

    /* [-500;255]BIN7 = ([0;255]BIN7 - [0;500]BIN7) */
    temp_s32 = (SInt32)vsctl_spdvehvslimreqfil_cpy - (SInt32)veh_spdveh_par;
    vsctl_spderr_avehvslim_hyslo = (SInt16)DDS_M_MAX(temp_s32,VSLIM_N255_BIN7);

    if(VSLIM_STACVREGVSCTLREQ_REGULATION_LVV != (UInt32)ext_stacvregvsctlreq_par)
    {
        vsctl_aveh_authvslim_hyshi_t = DDS_M_MAP2D_S16(&VSCTL_AVEH_AUTHVSLIM_HYSHI_T_APM,
                                                        0);

        vsctl_aveh_authvslim_hyslo_t = DDS_M_MAP2D_S16(&VSCTL_AVEH_AUTHVSLIM_HYSLO_T_APM,
                                                        0);
    }
    else
    {
        vsctl_aveh_authvslim_hyshi_t = DDS_M_MAP2D_S16(&VSCTL_AVEH_AUTHVSLIM_HYSHI_T_APM,
                                                        vsctl_spderr_avehvslim_hyshi);

        vsctl_aveh_authvslim_hyslo_t = DDS_M_MAP2D_S16(&VSCTL_AVEH_AUTHVSLIM_HYSLO_T_APM,
                                                        vsctl_spderr_avehvslim_hyslo);
    }

    if(VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)
    {
        VSCtl_aVeh_AuthVSLim_HysHi = 0;
        VSCtl_aVeh_AuthVSLim_HysLo = 0;
        VSCtl_spdErr_aVehVSLim_HysHi = 0;
        VSCtl_spdErr_aVehVSLim_HysLo = 0;
    }
    else
    {
        VSCtl_aVeh_AuthVSLim_HysHi = vsctl_aveh_authvslim_hyshi_t;
        VSCtl_aVeh_AuthVSLim_HysLo = vsctl_aveh_authvslim_hyslo_t;
        VSCtl_spdErr_aVehVSLim_HysHi = vsctl_spderr_avehvslim_hyshi;
        VSCtl_spdErr_aVehVSLim_HysLo = vsctl_spderr_avehvslim_hyslo;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F412342_Determiner_Condition_Reprise_Depuis_Attente
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F412342_Determiner_Condition_Reprise_Depuis_Attente(SInt16 vsctl_aveh_par, /* BIN10 */
                                                                                        UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                        UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.54.0 */
    if((UInt32)DDS_TRUE != (UInt32)VSCtl_bDrvOvrdVSLimFromWait)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
                /* BIN7 > (BIN0 * BIN7) + BIN7 */
            (   ((SInt32)veh_spdveh_par > (((SInt32)ext_spdvehvslimreq_par * BIN7) + (SInt32)VSCtl_spdEAcvWaitVSLim_HysHi_C)) ||
                ((SInt32)vsctl_aveh_par > (SInt32)VSCtl_aVeh_AuthVSLim_HysHi)))
        {
            VSCtl_bDrvOvrdVSLimFromWait = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy) ||
            (   /* (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy) &&  useless */
                /* BIN7 > (BIN0 * BIN7) + BIN7 */
                ((SInt32)veh_spdveh_par <= (((SInt32)ext_spdvehvslimreq_par * BIN7) + (SInt32)VSCtl_spdEAcvWaitVSLim_HysLo_C)) &&
                /* BIN10 <= BIN10 + BIN10 */
                ((SInt32)vsctl_aveh_par <= ((SInt32)VSCtl_aVeh_AuthVSLim_HysHi + (SInt32)VSCtl_aVhEAcvWaitVSLim_HysHi_C))))
        {
            VSCtl_bDrvOvrdVSLimFromWait = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F412343_Determiner_Condition_Reprise_Depuis_Reprise
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F412343_Determiner_Condition_Reprise_Depuis_Reprise(SInt16 vsctl_aveh_par, /* BIN10 */
                                                                                        UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                                                                        UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.55.0 */
    if((UInt32)DDS_TRUE != (UInt32)VSCtl_bDrvOvrdVSLimFromOvrd)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
                /* BIN7 > BIN7 + BIN7 */
            (   ((SInt32)veh_spdveh_par > ((SInt32)vsctl_spdvehvslimreqfil_cpy + (SInt32)VSCtl_spdEAcvOvrdVSLim_HysLo_C))   ||
                /* BIN10 > BIN10 + BIN10 */
                ((SInt32)vsctl_aveh_par > ((SInt32)VSCtl_aVeh_AuthVSLim_HysHi + (SInt32)VSCtl_aVhEAcvOvrdVSLim_HysHi_C))))
        {
            VSCtl_bDrvOvrdVSLimFromOvrd = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy) ||
            (   /* (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy) && useless */
                    /* BIN7 <= (BIN0 * BIN7) + BIN7 */
                (   ((SInt32)veh_spdveh_par <= (((SInt32)ext_spdvehvslimreq_par * BIN7) + (SInt32)VSCtl_spdEAcvOvrdVSLim_HysHi_C)) &&
                    ((SInt32)vsctl_aveh_par <= (SInt32)VSCtl_aVeh_AuthVSLim_HysLo))))
        {
            VSCtl_bDrvOvrdVSLimFromOvrd = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F412344_Determiner_Condition_Reprise_Depuis_Active_Non_Effective
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F412344_Determiner_Condition_Reprise_Depuis_Active_Non_Effective(UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.16.1 */
    if((UInt32)DDS_TRUE != (UInt32)VSCtl_bOvrdVSLimFromANE)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
            ((SInt32)veh_spdveh_par >= (SInt32)VSCtl_spdVehOvrdVSLim_HysHi_C)   &&
            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvOvrdFromANEVSLim_C)  )
        {
            VSCtl_bOvrdVSLimFromANE = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy) ||
            (   /* (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy) && useless*/
                ((SInt32)veh_spdveh_par < (SInt32)VSCtl_spdVehOvrdVSLim_HysLo_C))||
            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvOvrdFromANEVSLim_C))
        {
            VSCtl_bOvrdVSLimFromANE = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F412345_Determiner_Reprise
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F412345_Determiner_Reprise(UInt8 vsctl_stvslimextd_par,
                                                                UInt8 ext_stacvregvsctlreq_par,
                                                                UInt8 ext_stmodregvsctlreq_par,
                                                                UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                                                UInt8 vsctl_bfastdeacvslimreq_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.56.0 */
    UInt32 vsctl_tifildrvovrdvslim_tmp;

    switch((UInt32)vsctl_bdrvovrdvslim_tmp)/* 0 1 2 */
    {
        case VSLIM_TMP_FAUX:
            if((VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)&&
            (VSLIM_VSCTL_STVSLIMEXTD_ATTENTE == (UInt32)vsctl_stvslimextd_par)&&
            (VSLIM_STMODREGVSCTLREQ_REGULATION_LVV == (UInt32)ext_stmodregvsctlreq_par)&&
            (VSLIM_STACVREGVSCTLREQ_REGULATION_LVV == (UInt32)ext_stacvregvsctlreq_par)&&
            ((UInt32)DDS_FALSE != (UInt32)VSCtl_bDrvOvrdVSLimFromWait))
            {
             VSCtl_tiFilDrvOvrdVSLim = VSCtl_tiDrvOvrdFromWaitVSLim_C ;
             VSCtl_bDrvOvrdVSLim = DDS_TRUE;
             vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_TEMPO;
            }
            else if((VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)&&
            (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)&&
            ((UInt32)DDS_FALSE != (UInt32)vsctl_bfastdeacvslimreq_par)&&
            ((UInt32)DDS_FALSE != (UInt32)VSCtl_bOvrdVSLimFromANE))
            {
            VSCtl_tiFilDrvOvrdVSLim = VSCtl_tiDrvOvrdFromANEVSLim_C;
            VSCtl_bDrvOvrdVSLim = DDS_TRUE;
            vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_TEMPO;
            }
            else if((VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)&&
            (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)&&
            ((UInt32)DDS_FALSE != (UInt32)vsctl_bfastdeacvslimreq_par))
            {
            VSCtl_tiFilDrvOvrdVSLim = VSCtl_tiDrvOvrdFromAEVSLim_C ;
            VSCtl_bDrvOvrdVSLim = DDS_TRUE;
            vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_TEMPO;
            }
            else
            {
             /* do nothing */
            }
            break;

        case VSLIM_TMP_TEMPO:
            if((VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)||
            ((VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)&&
            (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)&&
            (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)) )
            {
                VSCtl_tiFilDrvOvrdVSLim = 0;
                VSCtl_bDrvOvrdVSLim = DDS_FALSE;
                vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_FAUX;
            }
            else if((UInt32)(0*BIN0) == (UInt32)VSCtl_tiFilDrvOvrdVSLim)
            {
                VSCtl_bDrvOvrdVSLim = DDS_TRUE;
                vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_NON_TEMPO;
            }
            else
            {
                 vsctl_tifildrvovrdvslim_tmp = DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiFilDrvOvrdVSLim,
                                                                        (UInt32)(1 * BIN0), (UInt32)(0 * BIN0));
                 VSCtl_tiFilDrvOvrdVSLim = (UInt8)DDS_M_MAX(vsctl_tifildrvovrdvslim_tmp, (UInt32)(0*BIN0));
            }
            break;

        case VSLIM_TMP_NON_TEMPO:
            if((VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)||
            ((VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)&&
            (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)&&
            (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)) )
            {
                VSCtl_tiFilDrvOvrdVSLim = 0;
                VSCtl_bDrvOvrdVSLim = DDS_FALSE;
                vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_FAUX;
            }
            else if(( (UInt32)DDS_FALSE != (UInt32)vsctl_bdrvovrdvslim_aveh_par)&&
            (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)&&
            ((UInt32)DDS_FALSE == (UInt32)vsctl_bfastdeacvslimreq_par)&&
            ( (UInt32)DDS_FALSE == (UInt32)VSCtl_bDrvOvrdVSLimFromOvrd))
            {
                VSCtl_tiFilDrvOvrdVSLim = 0;
                VSCtl_bDrvOvrdVSLim = DDS_FALSE;
                vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_FAUX;
            }
            else
            {
                 /* do nothing*/
            }
            break;

        default:
            VSCtl_tiFilDrvOvrdVSLim = 0;
            VSCtl_bDrvOvrdVSLim = DDS_FALSE;
            break;
    }
  }

/*******************************************************************************
*
* Function Name : VSLIM_F41235_Determiner_Demande_Inhibition
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41235_Determiner_Demande_Inhibition(UInt8 frm_binhvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.18.1 */
    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bInhVSLimReq)
    {
        if( (VSLIM_STMONVSLIM_NOMINAL == (UInt32)vsctl_stmonvslim_cpy)  &&
            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bInhVSLimReq_pt)    &&
            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bInhVSLimReq_Brk)   &&
            ((UInt32)DDS_FALSE == (UInt32)frm_binhvslim_par)    )
        {
            VSCtl_bInhVSLimReq = DDS_FALSE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)  ||
            ((UInt32)DDS_FALSE != (UInt32)VSCtl_bInhVSLimReq_pt)    ||
            ((UInt32)DDS_FALSE != (UInt32)VSCtl_bInhVSLimReq_Brk)   ||
            ((UInt32)DDS_FALSE != (UInt32)frm_binhvslim_par)    )
        {
            VSCtl_bInhVSLimReq = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F41236_Determiner_Condition_Conditions_Maintenance_Fonction
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F41236_Determiner_Condition_Conditions_Maintenance_Fonction(UInt8 frm_binhvslim_par,
                                                                                                  UInt8 vsctl_bfastdeacvslimreq_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.57.0 */
    UInt32 vslim_uvalue;

    if(VSLIM_STMONVSLIM_NOMINAL != (UInt32)vsctl_stmonvslim_cpy)
    {
        VSCtl_stDeacVSLimReq_Fct = 255;
    }
    else
    {
        vslim_uvalue = 0;

        if((UInt32)VSCtl_bModLimVSCtlReq == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 0);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)VSCtl_bAcvLimVSCtlReq == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 1);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)frm_binhvslim_par == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 2);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)VSCtl_bDrvOvrdVSLim == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 4);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)VSCtl_bDrvOvrdVSLimFromWait == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 5);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)VSCtl_bDrvOvrdVSLimFromOvrd == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 6);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)VSCtl_bOvrdVSLimFromANE == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 7);
        }
        else
        {
            /* Nothing to do */
        }

        if((UInt32)vsctl_bfastdeacvslimreq_par == (UInt32)DDS_TRUE)
        {
            DDS_M_BIT_SET32(vslim_uvalue, 3);
        }
        else
        {
            /* Nothing to do */
        }

        VSCtl_stDeacVSLimReq_Fct = (UInt8)vslim_uvalue;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_Det_Cond_Func_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Det_Cond_Func_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bFastDeacVSLimReq_swc_out )
{
    /* ---- Init Outputs ---- */
    *VSCtl_bFastDeacVSLimReq_swc_out = DDS_FALSE;

    /* ---- Init Global Datas ---- */
    VSCtl_bDrvOvrdVSLim = DDS_FALSE;
    VSCtl_bInhVSLimReq = DDS_TRUE;
    VSCtl_stDeacVSLimReq_Brk = DDS_TRUE;
    VSCtl_stDeacVSLimReq_Fct = 255;
    VSCtl_stDeacVSLimReq_pt = DDS_TRUE;

    VSCtl_aVeh_AuthVSLim_HysHi = (SInt16)(0 * BIN10); /* BIN10 */
    VSCtl_aVeh_AuthVSLim_HysLo = (SInt16)(0 * BIN10); /* BIN10 */
    VSCtl_bAcvLimVSCtlReq = DDS_TRUE;
    VSCtl_bDrvOvrdVSLimFromOvrd = DDS_FALSE;
    VSCtl_bDrvOvrdVSLimFromWait = DDS_FALSE;
    VSCtl_bGearCtlVSLim = DDS_TRUE;
    VSCtl_bInhVSLimReq_Brk = DDS_TRUE;
    VSCtl_bInhVSLimReq_pt = DDS_TRUE;
    VSCtl_bModLimVSCtlReq = DDS_TRUE;
    VSCtl_bOvrdVSLimFromANE = DDS_FALSE;
    VSCtl_bTyreWarnVSLim = DDS_TRUE;
    VSCtl_spdErr_aVehVSLim_HysHi = (SInt16)VSLIM_P255_BIN7; /* BIN7 */
    VSCtl_spdErr_aVehVSLim_HysLo = (SInt16)VSLIM_N255_BIN7; /* BIN7 */
    VSCtl_tiFilDrvOvrdVSLim = (UInt8)(0 * BIN0); /* BIN0 */

    vsctl_bdrvovrdvslim_tmp = (UInt8)VSLIM_TMP_FAUX;
    vsctl_spdvehvslimreqfil_cpy = (UInt16)(255 * BIN7);
    vsctl_stmonvslim_cpy = (UInt8)VSLIM_STMONVSLIM_ARRET;
}


#define VSLIM_STOP_SEC_CODE
#include "VSLim_MemMap.h"

