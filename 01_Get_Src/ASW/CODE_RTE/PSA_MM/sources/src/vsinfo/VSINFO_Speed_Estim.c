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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Speed_Estim.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 7 m User:meme 
*    TWK_model:VSINFO_Speed_Estim_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 29/7/2011 14 h 58 m User:demezil 
*    TWK_model:VSINFO_Speed_Estim_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 11 m User:demezil
*    TWK_model:VSINFO_Speed_Estim_L02_010_IMPL1
*    comments :for VSInfo11.0
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 25 m User:meme
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 17/2/2011 11 h 2 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 14 m User:meme
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 8/2/2011 9 h 14 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/2/2011 18 h 16 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :for vSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 2/2/2011 17 h 45 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 1/2/2011 16 h 29 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :correct undisplayable data name
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 9 h 35 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :correct filter init
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 20/12/2010 18 h 14 m User:morisseau
*    TWK_model:VSINFO_Speed_Estim_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 16 h 50 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version VSInfo 10.0
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSInfo.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define VSCTL_JRKVEH_MIN                      (-100 * BIN7)
#define VSCTL_JRKVEH_MAX                      (100 * BIN7)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_aBrk;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPT;
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehFil;
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stObsDyn;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilVehInfo;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"

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

/* NONE */


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVeh_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 32-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_32BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsSpdVehIniGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) },
{
(SInt32)(-1 * BIN14), (SInt32)(0 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsSpdVehStbDynGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0.04 * BIN14), (SInt32)(0.3321 * BIN14), (SInt32)(1 * BIN14),
(SInt32)(-0.3321 * BIN14), (SInt32)(0.04 * BIN14) },
{
(SInt32)(0.006 * BIN14), (SInt32)(0.2818 * BIN14), (SInt32)(0.2835 * BIN14),
(SInt32)(0.4348 * BIN14), (SInt32)(0.006 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(0.6352 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(-0.6352 * BIN14), (SInt32)(1 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsSpdVehTrnDynGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0.04 * BIN14), (SInt32)(0.3321 * BIN14), (SInt32)(1 * BIN14),
(SInt32)(-0.3321 * BIN14), (SInt32)(0.04 * BIN14) },
{
(SInt32)(0.006 * BIN14), (SInt32)(0.2818 * BIN14), (SInt32)(0.2835 * BIN14),
(SInt32)(0.4348 * BIN14), (SInt32)(0.006 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(0.6352 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(-0.6352 * BIN14), (SInt32)(1 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsAVehGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0.04 * BIN14), (SInt32)(0.2456 * BIN14), (SInt32)(1 * BIN14),
(SInt32)(-0.2456 * BIN14), (SInt32)(0.04 * BIN14) },
{
(SInt32)(0.006 * BIN14), (SInt32)(0.2261 * BIN14), (SInt32)(0.2835 * BIN14),
(SInt32)(0.4904 * BIN14), (SInt32)(0.006 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(0.3698 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(-0.3698 * BIN14), (SInt32)(1 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsAVehIniGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) },
{
(SInt32)(-1 * BIN14), (SInt32)(0 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) }
};

#define VSINFO_STOP_SEC_CARTO_32BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* complex variables definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_jrkveh_filter_struct;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* 32-bits variable definition */
#define VSINFO_START_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) vsinfo_f1464_matrix_out_1[VSINFO_V_DYN_MAP_M_Y];       /* BIN20 */
STATIC VAR(SInt32, AUTOMATIC) vsinfo_f1464_matrix_out_1_prev[VSINFO_V_DYN_MAP_M_Y];  /* BIN14 */
STATIC VAR(SInt32, AUTOMATIC) vsinfo_f1465_matrix_out_1[VSINFO_V_DYN_MAP_M_Y];       /* BIN20 */
STATIC VAR(SInt32, AUTOMATIC) vsinfo_f1465_matrix_out_1_prev[VSINFO_V_DYN_MAP_M_Y];  /* BIN14 */
STATIC VAR(UInt32, AUTOMATIC) vsinfo_veh_accel_estim_time_prev;
STATIC VAR(SInt32, AUTOMATIC) vsinfo_aveh_prev;                    /* BIN10 */
#define VSINFO_STOP_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"

/* 16-bits variable definition */
#define VSINFO_START_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsctl_abrk_cpy;
STATIC VAR(SInt16, AUTOMATIC) vsctl_apt_cpy;
STATIC VAR(UInt16, AUTOMATIC) vsctl_spdvehfil_cpy;
#define VSINFO_STOP_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_jrkveh_filter_init;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stobsdyn_loc;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehMesEstim; /* BIN7 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aResEstim; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVeh_no2; /* BIN7 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehMesEstim_no2; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aResEstim_no2; /* BIN10 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC((t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

STATIC FUNC(void, AUTOMATIC) VSINFO_F1464_Estimer_Vitesse_Vehicule(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveh_ptr /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1465_Estimer_Acceleration_Vehicule(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aveh_ptr, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkveh_ptr /* BIN7 */);

/*******************************************************************************
*
* Function Name : VSINFO_Speed_Estim
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Speed_Estim(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_swc_out /* BIN7 */)
{
    vsctl_abrk_cpy = VSCtl_aBrk;
    vsctl_apt_cpy = VSCtl_aPT;
    vsctl_spdvehfil_cpy = VSCtl_spdVehFil;
    vsctl_stobsdyn_loc = VSCtl_stObsDyn;

    VSINFO_F1464_Estimer_Vitesse_Vehicule(VSCtl_spdVeh_swc_out /* BIN7 */);

    VSINFO_F1465_Estimer_Acceleration_Vehicule(VSCtl_aVeh_swc_out, /* BIN10 */
                                     VSCtl_jrkVeh_swc_out /* BIN7 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_F1464_Estimer_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1464_Estimer_Vitesse_Vehicule(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveh_ptr /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.117.1 */
    SInt32 vsinfo_matrix_2[VSINFO_V_DYN_MAP_M_X];
    SInt32 var_out_1,var_out_2,var_out_3;               /* BIN7 */

    P2VAR(SInt32, AUTOMATIC, AUTOMATIC) vsinfo_matrix_1;   /* BIN14 */

    switch((UInt32)vsctl_stobsdyn_loc)
    {
        case (UInt32)VSCTL_STOBSDYN_INIT:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsSpdVehIniGain_M;            /*[-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_TRANSITOIRE:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsSpdVehTrnDynGain_M;         /* [-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_STABILISE:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsSpdVehStbDynGain_M;         /* [-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_ANTISATURATION:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsSpdVehTrnDynGain_M;         /* [-10;10] BIN14 */
            break;
        default:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsSpdVehIniGain_M;            /* [-10;10] BIN14 */
            break;
    }


    vsinfo_matrix_2[0] = ((SInt32)vsctl_abrk_cpy + (SInt32)vsctl_apt_cpy) * BIN4;      /* [-20;20] BIN14 */

    vsinfo_matrix_2[1] = ((SInt32)vsctl_spdvehfil_cpy * 10 * BIN7) / 36;           /* [0;70] BIN14 */

    vsinfo_matrix_2[2] = vsinfo_f1464_matrix_out_1_prev[0] ;                                /* BIN14 */

    vsinfo_matrix_2[3] = vsinfo_f1464_matrix_out_1_prev[1] ;                                /* BIN14 */

    vsinfo_matrix_2[4] = vsinfo_f1464_matrix_out_1_prev[2] ;                                /* BIN14 */


    VSINFOH_Dds_M_Prod_Matrix_SInt32(vsinfo_matrix_1,
                                 (UInt8)VSINFO_V_DYN_MAP_M_Y, (UInt8)VSINFO_V_DYN_MAP_M_X,
                                 14,
                                 vsinfo_matrix_2,
                                 1,
                                 14,
                                 vsinfo_f1464_matrix_out_1,
                                 20);

    /*   ((vsinfo_f1464_matrix_out_1 * 36) / 10) / BIN13 = ((vsinfo_f1464_matrix_out_1 * 18) / 5) / BIN13 */
    /* = ((vsinfo_f1464_matrix_out_1 * 18) / 20) / BIN11 */
    /*   ((vsinfo_f1464_matrix_out_1 * 9) / 10)  / BIN11  */
    /*      (vsinfo_f1464_matrix_out_1 / 10) * 9 + ((vsinfo_f1464_matrix_out_1 % 10) * 9) / 10 */
    var_out_1             = ((vsinfo_f1464_matrix_out_1[0] / 10) * 9) +
                            (((vsinfo_f1464_matrix_out_1[0] % 10) * 9) / 10);
    var_out_1             = var_out_1 / BIN11;
    *vsctl_spdveh_ptr = (UInt16)DDS_M_LIMIT(var_out_1,VSCTL_SPDVEH_MIN,VSCTL_SPDVEH_MAX);

    var_out_2             = ((vsinfo_f1464_matrix_out_1[1] / 10) * 9) +
                            (((vsinfo_f1464_matrix_out_1[1] % 10) * 9) / 10);
    var_out_2             = var_out_2 / BIN11;

    VSCtl_spdVehMesEstim  = (UInt16)DDS_M_LIMIT(var_out_2,VSCTL_SPDVEH_MIN,VSCTL_SPDVEH_MAX);

    var_out_3             = vsinfo_f1464_matrix_out_1[2] / BIN10;
    VSCtl_aResEstim       = (SInt16)DDS_M_LIMIT(var_out_3,VSCTL_ARESESTIM_MIN,VSCTL_ARESESTIM_MAX);

    /* Affectation des prev */
    /* BIN14 = BIN20 / BIN6 */
    vsinfo_f1464_matrix_out_1_prev[0] = vsinfo_f1464_matrix_out_1[0] / BIN6;
    vsinfo_f1464_matrix_out_1_prev[1] = vsinfo_f1464_matrix_out_1[1] / BIN6;
    vsinfo_f1464_matrix_out_1_prev[2] = vsinfo_f1464_matrix_out_1[2] / BIN6;
}

/*******************************************************************************
*
* Function Name : VSINFO_F1465_Estimer_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1465_Estimer_Acceleration_Vehicule(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aveh_ptr, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkveh_ptr /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.118.1 */
    SInt32 vsinfo_matrix_2[VSINFO_V_DYN_MAP_M_X];
    P2VAR(SInt32, AUTOMATIC, AUTOMATIC) vsinfo_matrix_1;   /* BIN14 */
    SInt32 vsinfo_aveh_diff;         /* BIN10 */
    SInt32 vsinfo_filter_in;         /* BIN7 */
    SInt32 filter_out;              /* BIN7 */
    SInt16 vsinfo_aveh_tmp;          /* BIN10 */
    SInt32 var_out_1,var_out_2,var_out_3;

    UInt32 current_time = DDS_VSINFO_1MS_U32_TIME;
    UInt32 delta_time   = current_time - vsinfo_veh_accel_estim_time_prev;

    vsinfo_veh_accel_estim_time_prev = current_time;
    delta_time      = DDS_M_MIN(delta_time, ( 2 * VSINFO_SCHEDULING_40MS));


    /* ESTIMER_ACCELERATION_VEHICULE */

    switch((UInt32)vsctl_stobsdyn_loc)
    {
        case (UInt32)VSCTL_STOBSDYN_INIT:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1  = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAVehIniGain_M;     /* [-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_TRANSITOIRE:
        case (UInt32)VSCTL_STOBSDYN_STABILISE:
        case (UInt32)VSCTL_STOBSDYN_ANTISATURATION:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAVehGain_M;     /* [-10;10] BIN14 */
            break;
        default:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAVehIniGain_M;  /* [-10;10] BIN14 */
            break;
    }


    vsinfo_matrix_2[0] = ((SInt32)vsctl_apt_cpy + (SInt32)vsctl_abrk_cpy) * BIN4;          /* [-20;20] BIN14 */

    vsinfo_matrix_2[1] = ((SInt32)vsctl_spdvehfil_cpy * 10 * BIN7) / 36;               /* [0;70] BIN14 */

    vsinfo_matrix_2[2] = vsinfo_f1465_matrix_out_1_prev[0] ;                                    /* BIN14 */

    vsinfo_matrix_2[3] = vsinfo_f1465_matrix_out_1_prev[1] ;                                    /* BIN14 */

    vsinfo_matrix_2[4] = vsinfo_f1465_matrix_out_1_prev[2] ;                                    /* BIN14 */


    VSINFOH_Dds_M_Prod_Matrix_SInt32(vsinfo_matrix_1,
                                 (UInt8)VSINFO_V_DYN_MAP_M_Y, (UInt8)VSINFO_V_DYN_MAP_M_X,
                                 14,
                                 vsinfo_matrix_2,
                                 1,
                                 14,
                                 vsinfo_f1465_matrix_out_1,
                                 20);

    /*   ((vsinfo_f1465_matrix_out_1 * 36) / 10) / BIN13 = ((vsinfo_f1465_matrix_out_1 * 18) / 5) / BIN13 */
    /* = ((vsinfo_f1465_matrix_out_1 * 18) / 20) / BIN11 */
    /*   ((vsinfo_f1465_matrix_out_1 * 9) / 10)  / BIN11  */
    /*      (vsinfo_f1465_matrix_out_1 / 10) * 9 + ((vsinfo_f1465_matrix_out_1 % 10) * 9) / 10 */
    var_out_1             = ((vsinfo_f1465_matrix_out_1[0] / 10) * 9) +
                            (((vsinfo_f1465_matrix_out_1[0] % 10) * 9) / 10);
    var_out_1             = var_out_1 / BIN11;
    VSCtl_spdVeh_no2          = (UInt16)DDS_M_LIMIT(var_out_1,VSCTL_SPDVEH_MIN,VSCTL_SPDVEH_MAX);       /* [0;255]  UInt16 BIN7 */

    var_out_2             = ((vsinfo_f1465_matrix_out_1[1] / 10) * 9) +
                            (((vsinfo_f1465_matrix_out_1[1] % 10) * 9) / 10);
    var_out_2             = var_out_2 / BIN11;
    VSCtl_spdVehMesEstim_no2  = (UInt16)DDS_M_LIMIT(var_out_2,VSCTL_SPDVEH_MIN,VSCTL_SPDVEH_MAX);       /* [0;255]  UInt16 BIN7 */

    var_out_3                 = (vsinfo_f1465_matrix_out_1[2] / BIN10);
    VSCtl_aResEstim_no2       = (SInt16)DDS_M_LIMIT(var_out_3,VSCTL_ARESESTIM_MIN,VSCTL_ARESESTIM_MAX); /* [-10;10] SInt16 BIN10 */

    if(  ((UInt32)vsctl_stobsdyn_loc == (UInt32)VSCTL_STOBSDYN_TRANSITOIRE)
       ||((UInt32)vsctl_stobsdyn_loc == (UInt32)VSCTL_STOBSDYN_STABILISE)
       ||((UInt32)vsctl_stobsdyn_loc == (UInt32)VSCTL_STOBSDYN_ANTISATURATION))
    {
        /*[-30;30]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 + [-10;10]BIN10*/
        vsinfo_aveh_tmp  = (SInt16)(((SInt32)vsctl_apt_cpy + (SInt32)vsctl_abrk_cpy) + (SInt32)VSCtl_aResEstim_no2);

        /* [-10;10] BIN10 VSCtl_aVeh_swc_out */
        vsinfo_aveh_tmp = (SInt16)DDS_M_LIMIT((SInt32)vsinfo_aveh_tmp,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);
    }
    else
    {
        vsinfo_aveh_tmp = (SInt16)(0 * BIN10);
    }

    *vsctl_aveh_ptr = vsinfo_aveh_tmp;

    /* BIN10 = (BIN10 - BIN10) */
    vsinfo_aveh_diff = (SInt32)vsinfo_aveh_tmp -vsinfo_aveh_prev;

    if((UInt32)(0 * DEC3) != delta_time)
    {
        /* BIN7 = ((BIN10 * DEC3) / DEC3) / BIN3 */
        vsinfo_filter_in = ((vsinfo_aveh_diff * DEC3)  / (SInt32)delta_time) / BIN3;
    }
    else if((SInt32)(0 * BIN10) < vsinfo_aveh_diff)
    {
        vsinfo_filter_in = DDS_SINT32_MAX;
    }
    else if(vsinfo_aveh_diff == 0)
    {
        vsinfo_filter_in = 0;
    }
    else
    {
        vsinfo_filter_in = DDS_SINT32_MIN;
    }

    if(  ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFilVehInfo)
       ||((UInt32)DDS_FALSE == (UInt32)vsinfo_jrkveh_filter_init))
    {
        vsinfo_jrkveh_filter_init = DDS_TRUE;
        filter_out = DDS_M_FILTER_LP1_S32_INIT(&vsinfo_jrkveh_filter_struct,
                                                vsinfo_filter_in);
    }
    else
    {
        filter_out = DDS_M_FILTER_LP1_S32(&vsinfo_jrkveh_filter_struct,
                                           vsinfo_filter_in,
                                           (UInt16)((UInt32)VSCtl_tiFil_jrkVeh_C * BIN5));
    }

    if(  ((UInt32)vsctl_stobsdyn_loc == (UInt32)VSCTL_STOBSDYN_TRANSITOIRE)
       ||((UInt32)vsctl_stobsdyn_loc == (UInt32)VSCTL_STOBSDYN_STABILISE)
       ||((UInt32)vsctl_stobsdyn_loc == (UInt32)VSCTL_STOBSDYN_ANTISATURATION))
    {
        filter_out = DDS_M_LIMIT(filter_out, (SInt32)VSCTL_JRKVEH_MIN, (SInt32)VSCTL_JRKVEH_MAX);
        *vsctl_jrkveh_ptr = (SInt16)filter_out;
    }
    else
    {
        *vsctl_jrkveh_ptr = 0;
    }

    /* Previous value */
    /* BIN14 = BIN20 / BIN6 */
    vsinfo_f1465_matrix_out_1_prev[0] = vsinfo_f1465_matrix_out_1[0] / BIN6;
    vsinfo_f1465_matrix_out_1_prev[1] = vsinfo_f1465_matrix_out_1[1] / BIN6;
    vsinfo_f1465_matrix_out_1_prev[2] = vsinfo_f1465_matrix_out_1[2] / BIN6;
    vsinfo_aveh_prev = vsinfo_aveh_tmp;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Speed_Estim_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Speed_Estim_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_swc_out /* BIN7 */)
{
    UInt32 index;
    /* ---- Init Outputs ---- */
    *VSCtl_aVeh_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_jrkVeh_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_spdVeh_swc_out = (UInt16)(0 * BIN7);


    /* ---- Init Global Datas ---- */
    VSCtl_aResEstim = (SInt16)(0 * BIN10);
    VSCtl_aResEstim_no2 = (SInt16)(0 * BIN10);
    VSCtl_spdVeh_no2 = (UInt16)(0 * BIN7);
    VSCtl_spdVehMesEstim = (UInt16)(0 * BIN7);
    VSCtl_spdVehMesEstim_no2 = (UInt16)(0 * BIN7);


    for(index = 0 ; index < (UInt32)VSINFO_V_DYN_MAP_M_Y ; index++)
    {
        /* ---- VSINFO_F1464_Estimer_Vitesse_Vehicule ---- */
        vsinfo_f1464_matrix_out_1[index]    = (0 * BIN20);
        vsinfo_f1464_matrix_out_1_prev[index]    = (0 * BIN14);
        /* ---- VSINFO_F1465_Estimer_Acceleration_Vehicule ---- */
        vsinfo_f1465_matrix_out_1[index]    = (0 * BIN20);
        vsinfo_f1465_matrix_out_1_prev[index]    = (0 * BIN14);
    }

    /* ---- VSINFO_F1464_Estimer_Vitesse_Vehicule ---- */

    /* ---- VSINFO_F1465_Estimer_Acceleration_Vehicule ---- */
    vsinfo_aveh_prev = 0;
    vsinfo_veh_accel_estim_time_prev = DDS_VSINFO_1MS_U32_TIME;
    vsinfo_jrkveh_filter_init = DDS_FALSE;

}

#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

