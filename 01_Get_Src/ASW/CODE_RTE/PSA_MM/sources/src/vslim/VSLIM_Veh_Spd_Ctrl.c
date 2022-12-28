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
* Ref X:\integration_view_00PSASWC_D520D01\blois_psa_sstg\Software\Appli\VSLim\src\VSLIM_Veh_Spd_Ctrl.c
* Version int :/main/L01_03/1 Date: 6/1/2012 15 h 3 m User:esnault 
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_030_IMPL2
*    comments :Calibrations values update for VSReg_12_0_e6
* Version dev :\main\branch_halouane_vslim_euro6\1 Date: 6/1/2012 11 h 7 m User:halouane 
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_030_IMPL2
*    comments :Calibrations values update for VSReg_12_0_e6
* Version dev :\main\branch_morisseau_vslim_euro6\3 Date: 30/11/2011 10 h 9 m User:morisseau
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_030_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vslim_euro6\1 Date: 15/11/2011 17 h 26 m User:morisseau
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_030_IMPL1
*    comments :for VSLim 12.0: spec update
* Version int :/main/L01_02/1 Date: 30/8/2011 11 h 51 m User:meme
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_020_IMPL1
*    comments :for VSLim 11.0
* Version dev :\main\branch_morisseau_vslim_euro6\2 Date: 27/7/2011 11 h 47 m User:morisseau
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_020_IMPL1
*    comments :for VSLim 11.0
* Version int :/main/L01_01/4 Date: 3/2/2011 15 h 12 m User:esnault
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_010_IMPL1_D
*    comments :for VSLim 10.1. corrcetion following remark tracking sheet
* Version int :/main/L01_01/3 Date: 25/1/2011 15 h 40 m User:esnault
*    TWK_model:VSLIM_Veh_Spd_Ctrl_L01_010_IMPL1
*    comments :For VSLim 10.0
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

#define VSC_16_SIZE                           16
#define VSC_8_SIZE                            8

/* VSCtl_stFilSpdVehVSLim */
#define VSLIM_STFILSPDVEHVSLIM_ARRET        (UInt32)0
#define VSLIM_STFILSPDVEHVSLIM_NON_FILTRE   (UInt32)1
#define VSLIM_STFILSPDVEHVSLIM_FILTRE       (UInt32)2

#define VSLIM_CONSIGNE_VITESSE_VEHICULE_MAX     (255 * BIN7)

#define VSLIM_SCHEDULING                            40 /* 40 ms */

#define VSLIM_P10_BIN10         (SInt16)(10 * BIN10)
#define VSLIM_N10_BIN10         (SInt16)(-10 * BIN10)

#define VSLIM_P1_BIN7           (UInt16)(1 * BIN7)

#define VSLIM_P10_BIN7          (SInt16)(10 * BIN7)

#define VSLIM_SAT_JERK_VEH_MIN      (SInt16)(-100 * BIN7)
#define VSLIM_SAT_JERK_VEH_MAX      (SInt16)( 100 * BIN7)

#define VSLIM_GABARITS_ACCEL_VEH_MIN  (SInt16)(-10 * BIN10)
#define VSLIM_GABARITS_ACCEL_VEH_MAX  (SInt16)( 10 * BIN10)

/* VSCtl_stSatAVehVSLim */
#define VSLIM_STSATAVEHVSLIM_ARRET                  (UInt32)0
#define VSLIM_STSATAVEHVSLIM_INIT_27                (UInt32)1
#define VSLIM_STSATAVEHVSLIM_NON_EFFECTIF_27        (UInt32)2
#define VSLIM_STSATAVEHVSLIM_EFFECTIF_27            (UInt32)3
#define VSLIM_STSATAVEHVSLIM_ACTIVATION_27          (UInt32)4
/* VSCtl_stSatJrkVehMaxVSLim */
/* VSCtl_stSatJrkVehMinVSLim */
#define VSLIM_STSATJRKVEH_ARRET                     (UInt32)0
#define VSLIM_STSATJRKVEH_NON_EFFECTIF              (UInt32)1
#define VSLIM_STSATJRKVEH_EFFECTIF                  (UInt32)2

/* F42141_Determiner_Mode_Controle_Vitesse_Vehicule */
#define VSLIM_COND_CHGT_DYN_INIT                    (UInt32)0
#define VSLIM_COND_CHGT_DYN_TRANSITOIRE             (UInt32)1
#define VSLIM_COND_CHGT_DYN_CONF                    (UInt32)2
#define VSLIM_COND_CHGT_DYN_DECONF                  (UInt32)3
#define VSLIM_COND_CHGT_DYN_STABILISE               (UInt32)4

#define VSLIM_LIS_CTRL_VIT_INIT                     (UInt32)0
#define VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_1          (UInt32)1
#define VSLIM_LIS_CTRL_VIT_CONF                     (UInt32)2
#define VSLIM_LIS_CTRL_VIT_DECONF                   (UInt32)3
#define VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_2          (UInt32)4

#define VSLIM_TAUX_APPLI_DYN_TRANS_MAX  (100 * BIN7)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* NONE */


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

/* 16-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimReq; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSLimReqFil; /* BIN7 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_16BIT
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehMaxSpdVehVSLimReq_C = (CONST(UInt16, AUTOMATIC))(2.3125 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehMinSpdVehVSLimReq_C = (CONST(UInt16, AUTOMATIC))(2.3125 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSLimDynStbMax_C = (CONST(UInt16, AUTOMATIC))(0.2001953125 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSLimDynStbMin_C = (CONST(SInt16, AUTOMATIC))(-0.2001953125 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGain2VSLimAVeh_C = (CONST(UInt16, AUTOMATIC))(0.5 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGainVSLimAVehPot_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdELimAVehP_HysHiN_C = (CONST(SInt16, AUTOMATIC))(-255 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdELimAVehP_HysHiP_C = (CONST(SInt16, AUTOMATIC))(25 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdELimAVehP_HysLoN_C = (CONST(SInt16, AUTOMATIC))(-10 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdELimAVehP_HysLoP_C = (CONST(SInt16, AUTOMATIC))(20 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrVSLimSDyn_HysHi_C = (CONST(SInt16, AUTOMATIC))(1.5 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErrVSLimSDyn_HysLo_C = (CONST(SInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSLimReqImp_C = (CONST(UInt16, AUTOMATIC))(1.5 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReqIni_C = (CONST(UInt16, AUTOMATIC))(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSLimReqIni_C = (CONST(UInt16, AUTOMATIC))(1.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVehPotVSLimRq_C = (CONST(UInt16, AUTOMATIC))(0.28899999999999998 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVehVSLimRq_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfm_rSDynCtlVSLim_C = (CONST(UInt16, AUTOMATIC))(4 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiDiCfm_rCtlTDynVSLim_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
#define VSLIM_STOP_SEC_CALIB_16BIT
#include "VSLim_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSLIM_START_SEC_CALIB_8BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvJrkSatMnCritVSLim_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimNGear_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimNGear_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimNGear_REP_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimPed_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimPed_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimPed_REP_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimTq_AE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimTq_ANE_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvPotVSLimTq_REP_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacImpDetVSLim_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacStSatAVehVSLim_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSLimMod_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDiCfmSDynCtlChgVSLim_C = (CONST(UInt8, AUTOMATIC))(50 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_stCtlAVehVSLim_C = (CONST(UInt8, AUTOMATIC))(74 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSdwnVSLimR1_C = (CONST(UInt8, AUTOMATIC))(0.3359375 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSdwnVSLimR2_C = (CONST(UInt8, AUTOMATIC))(0.0703125 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSupVSLimRq1_C = (CONST(UInt8, AUTOMATIC))(0.5 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSupVSLimRq2_C = (CONST(UInt8, AUTOMATIC))(0.25 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiTol_DynCtlVSLim_C = (CONST(UInt8, AUTOMATIC))(49 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiCfm_SDynCtlChgVSLim_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
#define VSLIM_STOP_SEC_CALIB_8BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSLIM_START_SEC_CARTO_16BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSLimSatMaxAbs_A[VSC_16_SIZE] = {
(SInt16)(-1 * BIN10), (SInt16)(-0.796875 * BIN10),
(SInt16)(-0.6015625 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.203125 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.6015625 * BIN10), (SInt16)(1 * BIN10), (SInt16)(2.1015625 * BIN10),
(SInt16)(2.203125 * BIN10), (SInt16)(2.296875 * BIN10),
(SInt16)(2.3984375 * BIN10), (SInt16)(2.5 * BIN10), (SInt16)(3 * BIN10),
(SInt16)(3.5 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSLimSatMaxCvg_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-5 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.453125 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.2109375 * BIN10), (SInt16)(-0.203125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.1015625 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.296875 * BIN10), (SInt16)(0.3984375 * BIN10),
(SInt16)(0.5 * BIN10), (SInt16)(5 * BIN10), (SInt16)(6 * BIN10),
(SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSLimSatMinAbs_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-9 * BIN10), (SInt16)(-8 * BIN10),
(SInt16)(-7 * BIN10), (SInt16)(-6 * BIN10), (SInt16)(-5 * BIN10),
(SInt16)(-4 * BIN10), (SInt16)(-3 * BIN10), (SInt16)(-2 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-0.796875 * BIN10),
(SInt16)(-0.6015625 * BIN10), (SInt16)(-0.203125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(1.5 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSLimSatMinCvg_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-6 * BIN10), (SInt16)(-5 * BIN10),
(SInt16)(-0.5 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.296875 * BIN10), (SInt16)(-0.203125 * BIN10),
(SInt16)(-0.1015625 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.2109375 * BIN10), (SInt16)(0.3984375 * BIN10),
(SInt16)(0.453125 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(5 * BIN10),
(SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSLimSatMxTra1Y_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0.203125 * BIN10), (SInt16)(0.6015625 * BIN10), (SInt16)(1 * BIN10),
(SInt16)(2 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSLimSatMxTra2Y_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0.203125 * BIN10), (SInt16)(0.6015625 * BIN10), (SInt16)(1 * BIN10),
(SInt16)(2 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehPotOftVSLimReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehReq_tiCfmSupVSLimX_A[VSC_8_SIZE] = {
(SInt16)(-3.5 * BIN10), (SInt16)(-1.25 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.203125 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.3984375 * BIN10), (SInt16)(1.25 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehSpdCtlGain1VSLimX_A[VSC_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(1 * BIN10),
(SInt16)(2 * BIN10), (SInt16)(4 * BIN10), (SInt16)(6 * BIN10),
(SInt16)(8 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMaxAbs_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMaxCft_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10) },
{
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10) },
{
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10), (UInt16)(0.125 * BIN10),
(UInt16)(0.125 * BIN10) },
{
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10),
(UInt16)(0.400390625 * BIN10), (UInt16)(0.400390625 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10),
(UInt16)(3.400390625 * BIN10), (UInt16)(3.400390625 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMinAbs_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) },
{
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10),
(SInt16)(-3.400390625 * BIN10), (SInt16)(-3.400390625 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMinCft_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(-1 * BIN10) },
{
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.7998046875 * BIN10), (SInt16)(-0.7998046875 * BIN10) },
{
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10) },
{
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10) },
{
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10), (SInt16)(-0.125 * BIN10),
(SInt16)(-0.125 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jVehVSLimReqSatMx1Tra_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jVehVSLimReqSatMx2Tra_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7) },
{
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7) },
{
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7) },
{
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7), (UInt16)(12 * BIN7),
(UInt16)(12 * BIN7), (UInt16)(12 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) },
{
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(6 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMaxAbs_T
[VSC_16_SIZE] = {
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMaxCvg_T
[VSC_16_SIZE] = {
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMinAbs_T
[VSC_16_SIZE] = {
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-20 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMinCvg_T
[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-100 * BIN7), (SInt16)(-100 * BIN7),
(SInt16)(-100 * BIN7), (SInt16)(-100 * BIN7), (SInt16)(-100 * BIN7),
(SInt16)(-100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVeh_tiCfmSupVSLimY_A[VSC_8_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-5 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0.5 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(5 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSLimSatMxAbsY_A[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(2 * BIN7),
(SInt16)(5 * BIN7), (SInt16)(10 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(40 * BIN7), (SInt16)(50 * BIN7), (SInt16)(60 * BIN7),
(SInt16)(70 * BIN7), (SInt16)(80 * BIN7), (SInt16)(90 * BIN7),
(SInt16)(100 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rCtlTqPotVSLim_T
[VSC_8_SIZE] = {
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(50 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdAJrkVSLimSatMxTra1X_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(90 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(255 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSLimSatMxCftY_A[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(2 * BIN7),
(SInt16)(5 * BIN7), (SInt16)(10 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(40 * BIN7), (SInt16)(50 * BIN7), (SInt16)(60 * BIN7),
(SInt16)(70 * BIN7), (SInt16)(80 * BIN7), (SInt16)(90 * BIN7),
(SInt16)(100 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdAJrkVSLimSatMxTra2X_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(90 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGain1VSLimAVeh_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdESpdCtlGain1VSLimY_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN7), (SInt16)(0 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(35 * BIN7), (SInt16)(40 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdE_aVehPotOftVSLimRqY_A[VSC_8_SIZE] = {
(SInt16)(-60 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(10 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(60 * BIN7), (SInt16)(80 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErr_rCtlPotVSLim_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN7), (SInt16)(0 * BIN7), (SInt16)(10 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(30 * BIN7), (SInt16)(40 * BIN7),
(SInt16)(50 * BIN7), (SInt16)(60 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSLimSatMnAbsY_A[VSC_16_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-90 * BIN7), (SInt16)(-80 * BIN7),
(SInt16)(-70 * BIN7), (SInt16)(-60 * BIN7), (SInt16)(-50 * BIN7),
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-25 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-2 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSLimSatMaxAbsX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSLimSatMinAbsX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSLimSatMinCftX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSLimSatMxCftX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehE_tiCfmSdwnVSLiY_A[VSC_8_SIZE] = {
(SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(5 * BIN7), (SInt16)(10 * BIN7),
(SInt16)(15 * BIN7), (SInt16)(20 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_tiCfmSdwnVSLimX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(80 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spd_aVehPotOftVSLimReqX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(90 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(180 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSLimSatMnCftY_A[VSC_16_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-90 * BIN7), (SInt16)(-80 * BIN7),
(SInt16)(-70 * BIN7), (SInt16)(-60 * BIN7), (SInt16)(-50 * BIN7),
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-25 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-2 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2) },
{
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSLimReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2), (UInt16)(2 * DEC2),
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2), (UInt16)(2 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) }
};

#define VSLIM_STOP_SEC_CARTO_16BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSLIM_START_SEC_VAR_UNSPECIFIED
#include "VSLim_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehpotoftvslimreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvslimreqsatmaxabs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvslimreqsatmaxcft_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvslimreqsatminabs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvslimreqsatmincft_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_jvehvslimreqsatmx1tra_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_jvehvslimreqsatmx2tra_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvslimsatmaxabs_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvslimsatmaxcvg_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvslimsatminabs_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvslimsatmincvg_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_rctltqpotvslim_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_spdctlgain1vslimaveh_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsdwnvslimreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsupvslimreq_m_sav;
STATIC VAR(t_dds_m_slew, AUTOMATIC) vsctl_f4212_slew_struct_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vslim_f42232_filter_lp1_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vslim_f4232_filt_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vslim_f4234_filter_1_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vslim_f4234_filter_2_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vslim_f4234_filter_3_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vslim_f4234_filter_4_struct;
#define VSLIM_STOP_SEC_VAR_UNSPECIFIED
#include "VSLim_MemMap.h"

/* 8-bits variable definition */
#define VSLIM_START_SEC_VAR_8BIT
#include "VSLim_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_avehvslim_prev;
STATIC VAR(UInt8, AUTOMATIC) vslim_condition_changement_dynamique_state;
STATIC VAR(UInt8, AUTOMATIC) vslim_lissage_controle_vitesse_state;
STATIC VAR(UInt8, AUTOMATIC) vsctl_bctl_avehpotvslim_prev;
#define VSLIM_STOP_SEC_VAR_8BIT
#include "VSLim_MemMap.h"

/* 16-bits variable definition */
#define VSLIM_START_SEC_VAR_16BIT
#include "VSLim_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vslim_f4232_sat_out_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehpotvslimreq_out_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_rctltqwhlptpotvslim_out_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_ticfmsdwnvslimreq_out_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_ticfmsupvslimreq_out_prev;
#define VSLIM_STOP_SEC_VAR_16BIT
#include "VSLim_MemMap.h"

/* 32-bits variable definition */
#define VSLIM_START_SEC_VAR_32BIT
#include "VSLim_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) vslim_f42232_out_sat_prev;    /* BIN10 */
#define VSLIM_STOP_SEC_VAR_32BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPotVSLimReqOft; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPotVSLimReqRaw; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqMax; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqMin; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqRaw; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMax; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMaxAbs; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMaxApl; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMaxCft; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMin; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMinAbs; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMinApl; /* BIN10 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSatMinCft; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehPotVSLimReq; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMax; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMax1Tran; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMax2Tran; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMaxAbs; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMaxCrit; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMaxCvg; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMin; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMinAbs; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimSatMinCvg; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rSpdVehCtlVSLimDyn; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdCtlGain1VSLimAVeh; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSLimReqPrev; /* BIN7 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReqRaw1; /* DEC2 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReqRaw2; /* DEC2 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReqRaw3; /* DEC2 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSLimReqRaw1; /* DEC2 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSLimReqRaw2; /* DEC2 */
/* <PRQA_COMMENT><3229> variable not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSLimReqRaw3; /* DEC2 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"

/* 8-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilSpdVehVSLimReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehPotVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bDynCtlSpdVehVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bInhFilSpdVehVSLimReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stFilSpdVehVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stSatAVehVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMaxVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMinVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilSpdVehCtlVSLimDyn; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilStCtlAVehVSLim; /* BIN0 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSLIM_START_SEC_CONST_UNSPECIFIED
#include "VSLim_MemMap.h"
STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHPOTOFTVSLIMREQ_M_APM = {
&vsctl_avehpotoftvslimreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spd_aVehPotOftVSLimReqX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdE_aVehPotOftVSLimRqY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehPotOftVSLimReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_AVEHVSLIMREQSATMAXABS_M_APM = {
&vsctl_avehvslimreqsatmaxabs_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSLimSatMaxAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSLimSatMxAbsY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSLimReqSatMaxAbs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_AVEHVSLIMREQSATMAXCFT_M_APM = {
&vsctl_avehvslimreqsatmaxcft_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSLimSatMxCftX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSLimSatMxCftY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSLimReqSatMaxCft_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHVSLIMREQSATMINABS_M_APM = {
&vsctl_avehvslimreqsatminabs_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSLimSatMinAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSLimSatMnAbsY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSLimReqSatMinAbs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHVSLIMREQSATMINCFT_M_APM = {
&vsctl_avehvslimreqsatmincft_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSLimSatMinCftX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSLimSatMnCftY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSLimReqSatMinCft_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_JVEHVSLIMREQSATMX1TRA_M_APM = {
&vsctl_jvehvslimreqsatmx1tra_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdAJrkVSLimSatMxTra1X_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSLimSatMxTra1Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jVehVSLimReqSatMx1Tra_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_JVEHVSLIMREQSATMX2TRA_M_APM = {
&vsctl_jvehvslimreqsatmx2tra_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdAJrkVSLimSatMxTra2X_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSLimSatMxTra2Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jVehVSLimReqSatMx2Tra_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_JRKVEHVSLIMSATMAXABS_T_APM = {
&vsctl_jrkvehvslimsatmaxabs_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSLimSatMaxAbs_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSLimSatMaxAbs_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_JRKVEHVSLIMSATMAXCVG_T_APM = {
&vsctl_jrkvehvslimsatmaxcvg_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSLimSatMaxCvg_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSLimSatMaxCvg_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHVSLIMSATMINABS_T_APM = {
&vsctl_jrkvehvslimsatminabs_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSLimSatMinAbs_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSLimSatMinAbs_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHVSLIMSATMINCVG_T_APM = {
&vsctl_jrkvehvslimsatmincvg_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSLimSatMinCvg_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSLimSatMinCvg_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RCTLTQPOTVSLIM_T_APM = {
&vsctl_rctltqpotvslim_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdErr_rCtlPotVSLim_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rCtlTqPotVSLim_T[0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_SPDCTLGAIN1VSLIMAVEH_M_APM = {
&vsctl_spdctlgain1vslimaveh_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehSpdCtlGain1VSLimX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdESpdCtlGain1VSLimY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdCtlGain1VSLimAVeh_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_TICFMSDWNVSLIMREQ_M_APM = {
&vsctl_ticfmsdwnvslimreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_tiCfmSdwnVSLimX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVehE_tiCfmSdwnVSLiY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSdwnVSLimReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_TICFMSUPVSLIMREQ_M_APM = {
&vsctl_ticfmsupvslimreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehReq_tiCfmSupVSLimX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVeh_tiCfmSupVSLimY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSupVSLimReq_M[0][0]
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

STATIC FUNC(void, AUTOMATIC) VSLIM_F421_Determiner_Consigne_Vitesse_Vehicule(
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveherrvslim_ptr /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4211_Determiner_Mode_Calcul_Consigne_Vitesse_Vehicule(
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvslimextd_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4212_Determiner_Consigne_Vitesse_Vehicule(
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveherrvslim_ptr /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F422_Determiner_Consigne_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehcordvsregreq_par, /* BIN10 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_bendtranvslim_par,
                                            UInt8 vsctl_bfastdeacvslimreq_par,
                                            UInt16 vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_ptr, /* BIN10 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_avehvslim_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4221_Determiner_Mode_Commande_Acceleration_Vehicule(
                                            UInt8 vsctl_bendtranvslim_par,
                                            UInt8 vsctl_bfastdeacvslimreq_par,
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_avehvslim_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4222_Determiner_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehcordvsregreq_par, /* BIN10 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt16 vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_1_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_2_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_3_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42222_Determiner_Saturations_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F422221_Determiner_Saturation_Acceleration_Vehicule_Max(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F422222_Determiner_Saturation_Acceleration_Vehicule_Min(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42223_Determiner_Saturations_Jerk_Vehicule(
                                            SInt16 vsctl_avehcordvsregreq_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt16 vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42224_Determiner_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4223_Determiner_Consigne_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42231_Determiner_Mode_Controle_Vitesse_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42231_1_Determiner_Mode_Controle_Vitesse_Vehicule (
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42231_2_Determiner_Mode_Controle_Vitesse_Vehicule (
                                            UInt8 vsctl_stctl_avehvslim_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F42232_Determiner_Consigne_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F423_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 ext_stctlcmdpttqpotcf_par,
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehpotvslimreq_ptr, /* BIN10 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bctl_avehpotvslim_ptr,
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_rctltqwhlptpotvslim_ptr, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwnvslimreq_ptr, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsupvslimreq_ptr /* DEC2 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 ext_stctlcmdpttqpotcf_par,
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bctl_avehpotvslim_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                                            UInt8 vsctl_bctl_avehpotvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehpotvslimreq_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP(
                                            UInt8 vsctl_bctl_avehpotvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_rctltqwhlptpotvslim_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4234_Determiner_Temps_Confirmation_Changement_Rapport(
                                            SInt16 vsctl_avehpotvslimreq_par, /* BIN10 */
                                            UInt8 vsctl_bctl_avehpotvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwnvslimreq_ptr, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsupvslimreq_ptr /* DEC2 */);

/*******************************************************************************
*
* Function Name : VSLIM_Veh_Spd_Ctrl
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Veh_Spd_Ctrl(UInt8 Ext_spdVehVSLimReq_swc_in, /* BIN0 */
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
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSLimReq_swc_out /* DEC2 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.20.2 */
    VSLIM_F421_Determiner_Consigne_Vitesse_Vehicule(Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                                    VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    VSCtl_stVSLimExtd_swc_in,
                                                    VSCtl_spdVehErrVSLim_swc_out /* BIN7 */);

    VSLIM_F422_Determiner_Consigne_Acceleration_Vehicule(*VSCtl_spdVehErrVSLim_swc_out, /* BIN7 */
                                                            VSCtl_aVehCordVSRegReq_swc_in, /* BIN10 */
                                                            VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                            VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                            VSCtl_aVehReq_swc_in, /* BIN10 */
                                                            VSCtl_bEndTranVSLim_swc_in,
                                                            VSCtl_bFastDeacVSLimReq_swc_in,
                                                            VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                                                            VSCtl_spdVeh_swc_in, /* BIN7 */
                                                            VSCtl_stVSCtlInfo_swc_in,
                                                            VSCtl_stVSLimExtd_swc_in,
                                                            VSCtl_aVehVSLimReq_swc_out, /* BIN10 */
                                                            VSCtl_stCtl_aVehVSLim_swc_out);

    if(VSLIM_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR != (UInt32)Ext_stCtlCmdPTTqPotCf_swc_in)
    {
        VSLIM_F423_Determiner_Consigne_Potentiel_Acceleration_Vehicule(*VSCtl_spdVehErrVSLim_swc_out, /* BIN7 */
                                                                       *VSCtl_stCtl_aVehVSLim_swc_out,
                                                                       Ext_stCtlCmdPTTqPotCf_swc_in,
                                                                       VSCtl_spdVeh_swc_in, /* BIN7 */
                                                                       VSCtl_stVSCtlInfo_swc_in,
                                                                       VSCtl_stVSLimExtd_swc_in,
                                                                       &vsctl_avehpotvslimreq_out_prev, /* BIN10 */
                                                                       &vsctl_bctl_avehpotvslim_prev,
                                                                       &vsctl_rctltqwhlptpotvslim_out_prev, /* BIN4 */
                                                                       &vsctl_ticfmsdwnvslimreq_out_prev, /* DEC2 */
                                                                       &vsctl_ticfmsupvslimreq_out_prev /* DEC2 */);
    }
    else
    {
        /* Nothing to do */
    }
    *VSCtl_aVehPotVSLimReq_swc_out =        vsctl_avehpotvslimreq_out_prev;
    *VSCtl_bCtl_aVehPotVSLim_swc_out =      vsctl_bctl_avehpotvslim_prev;
    *VSCtl_rCtlTqWhlPTPotVSLim_swc_out =    vsctl_rctltqwhlptpotvslim_out_prev;
    *VSCtl_tiCfmSdwnVSLimReq_swc_out =      vsctl_ticfmsdwnvslimreq_out_prev;
    *VSCtl_tiCfmSupVSLimReq_swc_out =       vsctl_ticfmsupvslimreq_out_prev;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_F421_Determiner_Consigne_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F421_Determiner_Consigne_Vitesse_Vehicule(
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveherrvslim_ptr /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.23.1 */
    VSLIM_F4211_Determiner_Mode_Calcul_Consigne_Vitesse_Vehicule(ext_spdvehvslimreq_par, /* BIN0 */
                                                                    vsctl_spdveh_par, /* BIN7 */
                                                                    vsctl_stvslimextd_par);

    VSLIM_F4212_Determiner_Consigne_Vitesse_Vehicule(ext_spdvehvslimreq_par, /* BIN0 */
                                                        vsctl_spdveh_par, /* BIN7 */
                                                        vsctl_spdveherrvslim_ptr /* BIN7 */);
}

/*******************************************************************************
*
* Function Name : VSLIM_F4211_Determiner_Mode_Calcul_Consigne_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4211_Determiner_Mode_Calcul_Consigne_Vitesse_Vehicule(
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvslimextd_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.24.2 */
        SInt32 diff_1,diff_2;

        /* INHIBITION FILTRAGE */
        /* BIN7 = (BIN0 * BIN7) - BIN7 */
        diff_1 = ((SInt32)ext_spdvehvslimreq_par * BIN7) - (SInt32)VSCtl_spdVehVSLimReqPrev;
        /* BIN7 = (BIN0 * BIN7) - BIN7 */
        diff_2 = ((SInt32)ext_spdvehvslimreq_par * BIN7) - (SInt32)vsctl_spdveh_par;

        if ((UInt32)DDS_TRUE != (UInt32)VSCtl_bInhFilSpdVehVSLimReq)
        {
            if( (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)) &&
                ((UInt32)VSCtl_spdVehVSLimReqFil == (UInt32)VSCtl_spdVehVSLimReqPrev)   &&
                (((UInt32)ext_spdvehvslimreq_par * BIN7) != (UInt32)VSCtl_spdVehVSLimReqPrev)   &&
                (DDS_M_ABS (diff_1) < (SInt32)VSCtl_spdVehVSLimReqImp_C)    &&
                (DDS_M_ABS (diff_2) < (SInt32)VSCtl_spdVehVSLimReqImp_C)    &&
                ((UInt32)DDS_FALSE == (UInt32)VSCtl_bDeacImpDetVSLim_C))
            {
                VSCtl_bInhFilSpdVehVSLimReq = DDS_TRUE;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            VSCtl_bInhFilSpdVehVSLimReq = DDS_FALSE;
        }

        /* MODE_FILTRAGES */
        switch((UInt32)VSCtl_stFilSpdVehVSLim)
        {
            case VSLIM_STFILSPDVEHVSLIM_ARRET:
                if( (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)  )
                {
                    VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_NON_FILTRE;
                    VSCtl_bAcvFilSpdVehVSLimReq = DDS_FALSE;
                }
                else    /* during actions of this state */
                {
                    /* NONE */
                }
                break;

            case VSLIM_STFILSPDVEHVSLIM_NON_FILTRE:
                if( (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   &&
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   &&
                    (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)  )
                {
                    VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_ARRET;
                    VSCtl_bAcvFilSpdVehVSLimReq = DDS_FALSE;
                }
                else if((UInt32)DDS_FALSE == (UInt32)VSCtl_bInhFilSpdVehVSLimReq)
                {
                    VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_FILTRE;
                    VSCtl_bAcvFilSpdVehVSLimReq = DDS_TRUE;
                }
                else    /* during actions of this state */
                {
                    /* NONE */
                }
                break;

            case VSLIM_STFILSPDVEHVSLIM_FILTRE:
                if( (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   &&
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   &&
                    (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)  )
                {
                    VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_ARRET;
                    VSCtl_bAcvFilSpdVehVSLimReq = DDS_FALSE;
                }
                else if((UInt32)DDS_TRUE == (UInt32)VSCtl_bInhFilSpdVehVSLimReq)
                {
                    VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_NON_FILTRE;
                    VSCtl_bAcvFilSpdVehVSLimReq = DDS_FALSE;
                }
                else    /* during actions of this state */
                {
                    /* NONE */
                }
                break;

            default:
                VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_ARRET;
                break;
        }

        /* MEMOIRE */
        /* BIN7 = BIN0 * BIN7 */
        VSCtl_spdVehVSLimReqPrev = (UInt16)((UInt32)ext_spdvehvslimreq_par * BIN7);
}

/*******************************************************************************
*
* Function Name : VSLIM_F4212_Determiner_Consigne_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4212_Determiner_Consigne_Vitesse_Vehicule(
                                            UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveherrvslim_ptr /* BIN7 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.23.1 */
    SInt32 rate_limiter_dec_in,rate_limiter_inc_in;
    UInt32 rate_limiter_out;

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFilSpdVehVSLimReq)
    {
        /* Slew input = ext_spdvehvslimreq_par[0;255]BIN0 * DEC3 * BIN10 * 5 (1 305 600 000) */
        rate_limiter_out = DDS_M_SLEW_U32_INIT(&vsctl_f4212_slew_struct_ptr,
                                               ((UInt32)ext_spdvehvslimreq_par * DEC3 * BIN10 * 5));   /* * 5 120 000 */
    }
    else
    {
        /* DECREMENTATION */
        /* [0;0.4] DEC3 * BIN10 * 3.6 = 0.04 * DEC3 * [0;10]BIN10 * 3.6   */
        /* [0;0.4] DEC3 * BIN10 * (18 / 5) = 0.04 * DEC3 * [0;10]BIN10 * (18 / 5)  */
        /* the /5 operation is done at the end  of the calculation */
        /* [0;0.4] DEC3 * BIN10 * 18 = 0.04 * DEC3 * [0;10]BIN10 * 18   */
        /* Max numerical value : 7 372 800 < DDS_SINT32_MAX */
        rate_limiter_dec_in = ((SInt32)VSLIM_SCHEDULING * (SInt32)VSCtl_aVehMinSpdVehVSLimReq_C * 18) ;

        /* INCREMENTATION */
        /* [0;0.4] DEC3 * BIN10 * 3.6 = 0.04 * DEC3 * [0;10]BIN10 * 3.6   */
        /* [0;0.4] DEC3 * BIN10 * (18 / 5) = 0.04 * DEC3 * [0;10]BIN10 * (18 / 5)  */
        /* the /5 operation is done at the end  of the calculation */
        /* [0;0.4] DEC3 * BIN10 * 18 = 0.04 * DEC3 * [0;10]BIN10 * 18   */
        /* Max numerical value : 7 372 800 < DDS_SINT32_MAX */
        rate_limiter_inc_in = ((SInt32)VSLIM_SCHEDULING * (SInt32)VSCtl_aVehMaxSpdVehVSLimReq_C * 18) ;

        /* Slew input = ext_spdvehvslimreq_par * DEC3 * BIN10 * 5 */
        rate_limiter_out = DDS_M_SLEW_U32(&vsctl_f4212_slew_struct_ptr,
                                          ((UInt32)ext_spdvehvslimreq_par * DEC3 * BIN10 * 5),
                                          (UInt32)rate_limiter_inc_in,
                                          (UInt32)rate_limiter_dec_in);
    }

    if (VSLIM_STFILSPDVEHVSLIM_ARRET == (UInt32)VSCtl_stFilSpdVehVSLim)
    {
        VSCtl_spdVehVSLimReqFil     = VSLIM_CONSIGNE_VITESSE_VEHICULE_MAX;
        *vsctl_spdveherrvslim_ptr   = VSLIM_CONSIGNE_VITESSE_VEHICULE_MAX;
    }
    else
    {
        /* BIN7 = ((DEC3 * BIN10 * 5) / (DEC3 * BIN3)) / 5 */
        VSCtl_spdVehVSLimReqFil     = (UInt16)((rate_limiter_out / (DEC3 * BIN3)) / 5);
        /* [-255;255]BIN7 = [0;255](((DEC3 * BIN10 * 5) / (DEC3 * BIN3)) / 5) - [0;255]BIN7 */
        *vsctl_spdveherrvslim_ptr   = (SInt16)((((SInt32)rate_limiter_out / (DEC3 * BIN3)) / 5) - (SInt32)vsctl_spdveh_par);
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F422_Determiner_Consigne_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F422_Determiner_Consigne_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehcordvsregreq_par, /* BIN10 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_bendtranvslim_par,
                                            UInt8 vsctl_bfastdeacvslimreq_par,
                                            UInt16 vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_ptr, /* BIN10 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_avehvslim_ptr)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.21.2 */
    VSLIM_F4221_Determiner_Mode_Commande_Acceleration_Vehicule(vsctl_bendtranvslim_par,
                                                                vsctl_bfastdeacvslimreq_par,
                                                                vsctl_stvsctlinfo_par,
                                                                vsctl_stvslimextd_par,
                                                                vsctl_stctl_avehvslim_ptr);

    VSLIM_F4222_Determiner_Gabarits_Acceleration_Vehicule(vsctl_spdveherrvslim_par, /* BIN7 */
                                                            vsctl_avehcordvsregreq_par, /* BIN10 */
                                                            vsctl_avehptmax_par, /* BIN10 */
                                                            vsctl_avehptmin_par, /* BIN10 */
                                                            vsctl_avehreq_par, /* BIN10 */
                                                            vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                                            vsctl_spdveh_par, /* BIN7 */
                                                            *vsctl_stctl_avehvslim_ptr,
                                                            vsctl_stvslimextd_par);

    VSLIM_F4223_Determiner_Consigne_Acceleration_Vehicule(vsctl_spdveherrvslim_par, /* BIN7 */
                                                            vsctl_avehptmax_par, /* BIN10 */
                                                            *vsctl_stctl_avehvslim_ptr,
                                                            vsctl_avehvslimreq_ptr /* BIN10 */);
}

/*******************************************************************************
*
* Function Name : VSLIM_F4221_Determiner_Mode_Commande_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4221_Determiner_Mode_Commande_Acceleration_Vehicule(
                                            UInt8 vsctl_bendtranvslim_par,
                                            UInt8 vsctl_bfastdeacvslimreq_par,
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_avehvslim_ptr)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.64.0 */
    switch((UInt32)vsctl_stctl_avehvslim_prev)
    {
        case VSLIM_STCTL_AVEHVSLIM_ARRET:
            if( (VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par) &&
                (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)))
            {
                vsctl_stctl_avehvslim_prev  = (UInt8)VSLIM_STCTL_AVEHVSLIM_CONTROLE;
                VSCtl_tiFilStCtlAVehVSLim   = VSCtl_tiFil_stCtlAVehVSLim_C;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
        break;

        case VSLIM_STCTL_AVEHVSLIM_CONTROLE:
            if (VSLIM_STVSCTLINFO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par)
            {
                vsctl_stctl_avehvslim_prev = (UInt8)VSLIM_STCTL_AVEHVSLIM_ARRET;
                VSCtl_bAcvFil_aVehVSLim = DDS_FALSE;
            }
            else if(    /* (VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par)  &&  useless */
                        (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   &&
                        (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   &&
                        (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)  )
            {
                vsctl_stctl_avehvslim_prev  = (UInt8)VSLIM_STCTL_AVEHVSLIM_TRANSITION_LENTE;
                VSCtl_bAcvFil_aVehVSLim = DDS_TRUE;
            }
            else if(    /* (VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par)  && useless */
                        (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)  )
            {
                vsctl_stctl_avehvslim_prev  = (UInt8)VSLIM_STCTL_AVEHVSLIM_TRANSITION_RAPIDE;
                VSCtl_bAcvFil_aVehVSLim = DDS_TRUE;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
        break;

        case VSLIM_STCTL_AVEHVSLIM_TRANSITION_LENTE:
            if( (VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par) &&      /* always true due to spec */
                (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)))
            {
                vsctl_stctl_avehvslim_prev  = (UInt8)VSLIM_STCTL_AVEHVSLIM_CONTROLE;
                VSCtl_tiFilStCtlAVehVSLim   = VSCtl_tiFil_stCtlAVehVSLim_C;
            }
            else if(    (VSLIM_STVSCTLINFO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par) ||
                        ((UInt32)DDS_TRUE == (UInt32)vsctl_bendtranvslim_par)   ||
                        (0 == (UInt32)VSCtl_tiFilStCtlAVehVSLim)    )
            {
                vsctl_stctl_avehvslim_prev = (UInt8)VSLIM_STCTL_AVEHVSLIM_ARRET;
                VSCtl_bAcvFil_aVehVSLim = DDS_FALSE;
            }
            else if ((UInt32)DDS_TRUE == (UInt32)vsctl_bfastdeacvslimreq_par)
            {
                vsctl_stctl_avehvslim_prev = (UInt8)VSLIM_STCTL_AVEHVSLIM_TRANSITION_RAPIDE;
                VSCtl_bAcvFil_aVehVSLim = DDS_TRUE;
            }
            else    /* during actions of this state */
            {
                VSCtl_tiFilStCtlAVehVSLim = (UInt8)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiFilStCtlAVehVSLim, (UInt32)(1 * BIN0));
            }
        break;

        case VSLIM_STCTL_AVEHVSLIM_TRANSITION_RAPIDE:
            if( (VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par) &&      /* always true due to spec */
                (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   ||
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)))
            {
                vsctl_stctl_avehvslim_prev  = (UInt8)VSLIM_STCTL_AVEHVSLIM_CONTROLE;
                VSCtl_tiFilStCtlAVehVSLim   = VSCtl_tiFil_stCtlAVehVSLim_C;
            }
            else if(    (VSLIM_STVSCTLINFO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par) ||
                        ((UInt32)DDS_TRUE == (UInt32)vsctl_bendtranvslim_par)   ||
                        (0 == (UInt32)VSCtl_tiFilStCtlAVehVSLim)    )
            {
                vsctl_stctl_avehvslim_prev = (UInt8)VSLIM_STCTL_AVEHVSLIM_ARRET;
                VSCtl_bAcvFil_aVehVSLim = DDS_FALSE;
            }
            else    /* during actions of this state */
            {
                VSCtl_tiFilStCtlAVehVSLim = (UInt8)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiFilStCtlAVehVSLim, (UInt32)(1 * BIN0));
            }
        break;
        default:
            vsctl_stctl_avehvslim_prev = (UInt8)VSLIM_STCTL_AVEHVSLIM_ARRET;
            VSCtl_bAcvFil_aVehVSLim = DDS_FALSE;
            break;
    }
    *vsctl_stctl_avehvslim_ptr = vsctl_stctl_avehvslim_prev;
}

/*******************************************************************************
*
* Function Name : VSLIM_F4222_Determiner_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4222_Determiner_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehcordvsregreq_par, /* BIN10 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt16 vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.26.2 */
    VSLIM_F42221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(vsctl_avehreq_par, /* BIN10 */
                                                                        vsctl_stctl_avehvslim_par,
                                                                        vsctl_stvslimextd_par);

    VSLIM_F42222_Determiner_Saturations_Acceleration_Vehicule(vsctl_spdveherrvslim_par, /* BIN7 */
                                                                vsctl_avehptmax_par, /* BIN10 */
                                                                vsctl_avehptmin_par, /* BIN10 */
                                                                vsctl_stctl_avehvslim_par);

    VSLIM_F42223_Determiner_Saturations_Jerk_Vehicule(vsctl_avehcordvsregreq_par, /* BIN10 */
                                                        vsctl_avehreq_par, /* BIN10 */
                                                        vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                                        vsctl_spdveh_par, /* BIN7 */
                                                        vsctl_stctl_avehvslim_par);

    VSLIM_F42224_Determiner_Gabarits_Acceleration_Vehicule(vsctl_avehptmax_par, /* BIN10 */
                                                            vsctl_avehptmin_par, /* BIN10 */
                                                            vsctl_avehreq_par, /* BIN10 */
                                                            vsctl_stctl_avehvslim_par);
}

/*******************************************************************************
*
* Function Name : VSLIM_F42221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.27.2 */
    /* MODES_CALCUL_GABARITS_ACCELERATION_VEHICULE */
    VSLIM_F42221_1_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule (vsctl_avehreq_par, /* BIN10 */
                                                                            vsctl_stctl_avehvslim_par,
                                                                            vsctl_stvslimextd_par);

    /* JERK_MAX */
    VSLIM_F42221_2_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule (vsctl_stctl_avehvslim_par,
                                                                            vsctl_stvslimextd_par);

    /* JERK_MIN */
    VSLIM_F42221_3_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule (vsctl_stctl_avehvslim_par,
                                                                            vsctl_stvslimextd_par);
}

/*******************************************************************************
*
* Function Name : VSLIM_F42221_1_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_1_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.27.2 */

    /* MODES_CALCUL_GABARITS_ACCELERATION_VEHICULE */
    switch((UInt32)VSCtl_stSatAVehVSLim)
    {
        case VSLIM_STSATAVEHVSLIM_ARRET:
            if( (VSLIM_STCTL_AVEHVSLIM_ARRET != (UInt32)vsctl_stctl_avehvslim_par) &&
                ((UInt32)DDS_FALSE == (UInt32)VSCtl_bDeacStSatAVehVSLim_C)  )
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_INIT_27;
            }
            else if(    (VSLIM_STCTL_AVEHVSLIM_ARRET != (UInt32)vsctl_stctl_avehvslim_par) &&
                        ((UInt32)DDS_TRUE == (UInt32)VSCtl_bDeacStSatAVehVSLim_C)   )
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_EFFECTIF_27;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATAVEHVSLIM_INIT_27:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ARRET;
            }
            else
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_NON_EFFECTIF_27;
            }
            break;

        case VSLIM_STSATAVEHVSLIM_NON_EFFECTIF_27:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ARRET;
            }
            else if(((UInt32)DDS_TRUE != (UInt32)VSCtl_stSatAVehMinVSLimMod_C) &&
                    ((SInt32)vsctl_avehreq_par <= (SInt32)VSCtl_aVehVSLimReqSatMax) &&
                    ((SInt32)vsctl_avehreq_par >= (SInt32)VSCtl_aVehVSLimReqSatMin) &&
                    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   )
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_EFFECTIF_27;
            }
            else if(    ((UInt32)DDS_TRUE == (UInt32)VSCtl_stSatAVehMinVSLimMod_C)  &&
                        (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   )
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ACTIVATION_27;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATAVEHVSLIM_EFFECTIF_27:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ARRET;
            }
            else if(VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_NON_EFFECTIF_27;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATAVEHVSLIM_ACTIVATION_27:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ARRET;
            }
            else if(    ((SInt32)vsctl_avehreq_par <= (SInt32)VSCtl_aVehVSLimReqSatMax) &&
                        ((SInt32)vsctl_avehreq_par >= (SInt32)VSCtl_aVehVSLimReqSatMin)  &&
                        (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   )
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_EFFECTIF_27;
            }
            else if(    (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                        ((UInt32)DDS_TRUE != (UInt32)VSCtl_stSatAVehMinVSLimMod_C)  )
            {
                VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_NON_EFFECTIF_27;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;
        default:
            VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ARRET;
            break;
    }
}


/*******************************************************************************
*
* Function Name : VSLIM_F42221_2_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_2_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.27.2 */

    /* JERK_MAX */
    switch((UInt32)VSCtl_stSatJrkVehMaxVSLim)
    {
        case VSLIM_STSATJRKVEH_ARRET:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET != (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_NON_EFFECTIF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATJRKVEH_NON_EFFECTIF:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
            }
            else if(VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)
            {
                VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_EFFECTIF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATJRKVEH_EFFECTIF:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
            }
            else if (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)
            {
                VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_NON_EFFECTIF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
        break;
        default:
            VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
            break;
    }
}


/*******************************************************************************
*
* Function Name : VSLIM_F42221_3_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42221_3_Determiner_Mode_Calcul_Gabarits_Acceleration_Vehicule(
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 vsctl_stvslimextd_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.27.2 */

    /* JERK_MIN */
    switch((UInt32)VSCtl_stSatJrkVehMinVSLim)
    {
        case VSLIM_STSATJRKVEH_ARRET:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET != (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatJrkVehMinVSLim = (UInt8)VSLIM_STSATJRKVEH_EFFECTIF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATJRKVEH_EFFECTIF:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatJrkVehMinVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
            }
            else if(VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)
            {
                VSCtl_stSatJrkVehMinVSLim =  (UInt8)VSLIM_STSATJRKVEH_NON_EFFECTIF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_STSATJRKVEH_NON_EFFECTIF:
            if(VSLIM_STCTL_AVEHVSLIM_ARRET == (UInt32)vsctl_stctl_avehvslim_par)
            {
                VSCtl_stSatJrkVehMinVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
            }
            else if(VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)
            {
                VSCtl_stSatJrkVehMinVSLim = (UInt8)VSLIM_STSATJRKVEH_EFFECTIF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        default:
            VSCtl_stSatJrkVehMinVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F42222_Determiner_Saturations_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42222_Determiner_Saturations_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.28.1 */
    VSLIM_F422221_Determiner_Saturation_Acceleration_Vehicule_Max(vsctl_spdveherrvslim_par, /* BIN7 */
                                                                    vsctl_avehptmax_par, /* BIN10 */
                                                                    vsctl_stctl_avehvslim_par);

    VSLIM_F422222_Determiner_Saturation_Acceleration_Vehicule_Min(vsctl_spdveherrvslim_par, /* BIN7 */
                                                                    vsctl_avehptmin_par, /* BIN10 */
                                                                    vsctl_stctl_avehvslim_par);
}

/*******************************************************************************
*
* Function Name : VSLIM_F422221_Determiner_Saturation_Acceleration_Vehicule_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F422221_Determiner_Saturation_Acceleration_Vehicule_Max(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.29.2 */
    SInt32 vsctl_avehvslimreqsatmaxcft_m;
    SInt32 vsctl_avehvslimreqsatmaxabs_m;

    if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
    {
        VSCtl_aVehVSLimReqSatMax = VSLIM_P10_BIN10;
        VSCtl_aVehVSLimReqSatMaxCft = VSLIM_P10_BIN10;
        VSCtl_aVehVSLimReqSatMaxAbs = VSLIM_P10_BIN10;
    }
    else
    {
        vsctl_avehvslimreqsatmaxcft_m = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_AVEHVSLIMREQSATMAXCFT_M_APM,
                                                                    VSCtl_spdVehVSLimReqFil,
                                                                    vsctl_spdveherrvslim_par);

        vsctl_avehvslimreqsatmaxabs_m = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_AVEHVSLIMREQSATMAXABS_M_APM,
                                                                    VSCtl_spdVehVSLimReqFil,
                                                                    vsctl_spdveherrvslim_par);

        VSCtl_aVehVSLimReqSatMax = (SInt16)DDS_M_SATURATION_V2(vsctl_avehvslimreqsatmaxcft_m,
                                                                (SInt32)vsctl_avehptmax_par,
                                                                vsctl_avehvslimreqsatmaxabs_m);

        VSCtl_aVehVSLimReqSatMaxCft = (SInt16)vsctl_avehvslimreqsatmaxcft_m;

        VSCtl_aVehVSLimReqSatMaxAbs = (SInt16)vsctl_avehvslimreqsatmaxabs_m;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F422222_Determiner_Saturation_Acceleration_Vehicule_Min
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F422222_Determiner_Saturation_Acceleration_Vehicule_Min(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.30.2 */
    SInt32 vsctl_avehvslimreqsatmincft_m;
    SInt32 vsctl_avehvslimreqsatminabs_m;

    if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
    {
        VSCtl_aVehVSLimReqSatMin = VSLIM_N10_BIN10;
        VSCtl_aVehVSLimReqSatMinCft = VSLIM_N10_BIN10;
        VSCtl_aVehVSLimReqSatMinAbs = VSLIM_N10_BIN10;
    }
    else
    {
        vsctl_avehvslimreqsatmincft_m = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHVSLIMREQSATMINCFT_M_APM,
                                                                    VSCtl_spdVehVSLimReqFil,
                                                                    vsctl_spdveherrvslim_par);

        vsctl_avehvslimreqsatminabs_m = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHVSLIMREQSATMINABS_M_APM,
                                                                    VSCtl_spdVehVSLimReqFil,
                                                                    vsctl_spdveherrvslim_par);

        VSCtl_aVehVSLimReqSatMin = (SInt16)DDS_M_LIMIT_V2(vsctl_avehvslimreqsatmincft_m,
                                                            vsctl_avehvslimreqsatminabs_m,
                                                            (SInt32)vsctl_avehptmin_par);

        VSCtl_aVehVSLimReqSatMinCft = (SInt16)vsctl_avehvslimreqsatmincft_m;

        VSCtl_aVehVSLimReqSatMinAbs = (SInt16)vsctl_avehvslimreqsatminabs_m;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F42223_Determiner_Saturations_Jerk_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42223_Determiner_Saturations_Jerk_Vehicule(
                                            SInt16 vsctl_avehcordvsregreq_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
/* <PRQA_COMMENT><3206> Variable used as input of a terminator block </3206></PRQA_COMMENT> */
                                            UInt16 vsctl_rtqwhlptdrvreq_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.31.2 */
    SInt32 map_sat_max_cvg_in,map_sat_min_cvg_in;
    SInt32 switch_select_1_in_1,switch_select_1_in_2,switch_select_1_in_3;
    SInt32 switch_select_2_in_2,switch_select_2_in_4,switch_select_2_in_5;
    SInt32 switch_select_3_in_2,switch_select_3_in_5,switch_select_3_in_6;
    SInt32 switch_select_4_in_1,switch_select_4_in_2,switch_select_4_in_3;
    SInt32 div_num;

    /* [-20;20] = [-10;10] - [-10;10] */
    map_sat_max_cvg_in = (SInt32)vsctl_avehreq_par - (SInt32)VSCtl_aVehVSLimReqSatMax;

    /* Switch select 1 */
    switch_select_1_in_1 = (SInt32)DDS_M_MAP2D_SU16(&VSCTL_JRKVEHVSLIMSATMAXCVG_T_APM,      /* [0;100]BIN7 */
                                                   (SInt16)map_sat_max_cvg_in);

    switch_select_1_in_3 = (SInt32)DDS_M_MAP2D_SU16(&VSCTL_JRKVEHVSLIMSATMAXABS_T_APM,      /* [0;100]BIN7 */
                                                    vsctl_avehreq_par);

    switch_select_1_in_2 = DDS_M_MIN(switch_select_1_in_1,switch_select_1_in_3);            /* [0;100]BIN7 */

    /* Switch select 2 */
    switch_select_2_in_4 = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_JVEHVSLIMREQSATMX1TRA_M_APM,    /* */
                                                     vsctl_spdveh_par,
                                                     vsctl_avehreq_par);

    /* [-20;20]BIN10 = [-10;10]BIN10 - [-10;10]BIN10 */
    div_num = ((SInt32)vsctl_avehcordvsregreq_par - (SInt32)vsctl_avehreq_par);

    if(0 == div_num)
    {
        switch_select_2_in_5 = 0 * BIN7;    /* Min value */
    }
    else if(0 == (UInt32)VSCtl_tiFilStCtlAVehVSLim)  /* BIN0 */
    {
        if(0 > div_num)
        {
            switch_select_2_in_5 = (SInt32)VSLIM_SAT_JERK_VEH_MIN;  /* Min value */
        }
        else
        {
            switch_select_2_in_5 = (SInt32)VSLIM_SAT_JERK_VEH_MAX;  /* Max value */
        }
    }
    else
    {
        /*  [-500;500]BIN7 = [-20;20]BIN10 * DEC3 / (([0;255] BIN0 * 0.04 DEC3) * BIN3)*/
        switch_select_2_in_5 = (div_num * DEC3) / (((SInt32)VSCtl_tiFilStCtlAVehVSLim * VSLIM_SCHEDULING) * BIN3); /* Calculated value */
    }

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvJrkSatMnCritVSLim_C)
    {
        switch_select_2_in_2 = switch_select_2_in_4;
    }
    else
    {
        switch_select_2_in_2 = DDS_M_MAX(switch_select_2_in_4,switch_select_2_in_5);
    }

    /* Switch select 3 */
    switch_select_3_in_5 = switch_select_2_in_5;

    switch_select_3_in_6 = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_JVEHVSLIMREQSATMX2TRA_M_APM,
                                                     vsctl_spdveh_par,
                                                     vsctl_avehreq_par);

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvJrkSatMnCritVSLim_C)
    {
        switch_select_3_in_2 = switch_select_3_in_6;
    }
    else
    {
        switch_select_3_in_2 = DDS_M_MAX(switch_select_2_in_5,switch_select_3_in_6);
    }

    /* Switch select 4 */
    map_sat_min_cvg_in = (SInt32)vsctl_avehreq_par - (SInt32)VSCtl_aVehVSLimReqSatMin;

    switch_select_4_in_1 = (SInt32)DDS_M_MAP2D_S16(&VSCTL_JRKVEHVSLIMSATMINABS_T_APM,
                                                   vsctl_avehreq_par);

    switch_select_4_in_3 = (SInt32)DDS_M_MAP2D_S16(&VSCTL_JRKVEHVSLIMSATMINCVG_T_APM,
                                                   (SInt16)map_sat_min_cvg_in);

    switch_select_4_in_2 = DDS_M_MAX(switch_select_4_in_1,switch_select_4_in_3);

    /* Output calculation */
    switch((UInt32)vsctl_stctl_avehvslim_par)
    {
        case VSLIM_STCTL_AVEHVSLIM_ARRET:       /* 0 */
            VSCtl_jrkVehVSLimSatMaxCvg      = VSLIM_SAT_JERK_VEH_MAX;  /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMax         = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMaxAbs      = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMax1Tran    = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMaxCrit     = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMax2Tran    = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */

            VSCtl_jrkVehVSLimSatMinAbs      = VSLIM_SAT_JERK_VEH_MIN;   /* -100*BIN7 */
            VSCtl_jrkVehVSLimSatMin         = VSLIM_SAT_JERK_VEH_MIN;   /* -100*BIN7 */
            VSCtl_jrkVehVSLimSatMinCvg      = VSLIM_SAT_JERK_VEH_MIN;   /* -100*BIN7 */
            break;

        case VSLIM_STCTL_AVEHVSLIM_CONTROLE:        /* 1 */
            VSCtl_jrkVehVSLimSatMaxCvg      = (SInt16)switch_select_1_in_1;
            VSCtl_jrkVehVSLimSatMax         = (SInt16)switch_select_1_in_2;
            VSCtl_jrkVehVSLimSatMaxAbs      = (SInt16)switch_select_1_in_3;
            VSCtl_jrkVehVSLimSatMax1Tran    = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMaxCrit     = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMax2Tran    = VSLIM_SAT_JERK_VEH_MAX;

            VSCtl_jrkVehVSLimSatMinAbs      = (SInt16)switch_select_4_in_1;
            VSCtl_jrkVehVSLimSatMin         = (SInt16)switch_select_4_in_2;
            VSCtl_jrkVehVSLimSatMinCvg      = (SInt16)switch_select_4_in_3;
            break;

        case VSLIM_STCTL_AVEHVSLIM_TRANSITION_LENTE:        /* 2 */
            VSCtl_jrkVehVSLimSatMaxCvg      = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMax         = (SInt16)DDS_M_MIN(switch_select_2_in_2,(SInt32)VSLIM_SAT_JERK_VEH_MAX);
            VSCtl_jrkVehVSLimSatMaxAbs      = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMax1Tran    = (SInt16)switch_select_2_in_4;
            VSCtl_jrkVehVSLimSatMaxCrit     = (SInt16)DDS_M_LIMIT(switch_select_2_in_5,(SInt32)VSLIM_SAT_JERK_VEH_MIN,(SInt32)VSLIM_SAT_JERK_VEH_MAX);
            VSCtl_jrkVehVSLimSatMax2Tran    = VSLIM_SAT_JERK_VEH_MAX;

            VSCtl_jrkVehVSLimSatMinAbs      = VSLIM_SAT_JERK_VEH_MIN;
            VSCtl_jrkVehVSLimSatMin         = VSLIM_SAT_JERK_VEH_MIN;
            VSCtl_jrkVehVSLimSatMinCvg      = VSLIM_SAT_JERK_VEH_MIN;
            break;

        case VSLIM_STCTL_AVEHVSLIM_TRANSITION_RAPIDE:       /* 3 */
            VSCtl_jrkVehVSLimSatMaxCvg      = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMax         = (SInt16)DDS_M_MIN(switch_select_3_in_2,(SInt32)VSLIM_SAT_JERK_VEH_MAX);
            VSCtl_jrkVehVSLimSatMaxAbs      = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMax1Tran    = VSLIM_SAT_JERK_VEH_MAX;
            VSCtl_jrkVehVSLimSatMaxCrit     = (SInt16)DDS_M_LIMIT(switch_select_3_in_5,(SInt32)VSLIM_SAT_JERK_VEH_MIN,(SInt32)VSLIM_SAT_JERK_VEH_MAX);
            VSCtl_jrkVehVSLimSatMax2Tran    = (SInt16)switch_select_3_in_6;

            VSCtl_jrkVehVSLimSatMinAbs      = VSLIM_SAT_JERK_VEH_MIN;
            VSCtl_jrkVehVSLimSatMin         = VSLIM_SAT_JERK_VEH_MIN;
            VSCtl_jrkVehVSLimSatMinCvg      = VSLIM_SAT_JERK_VEH_MIN;
            break;

        default:
            VSCtl_jrkVehVSLimSatMaxCvg      = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMax         = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMaxAbs      = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMax1Tran    = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMaxCrit     = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */
            VSCtl_jrkVehVSLimSatMax2Tran    = VSLIM_SAT_JERK_VEH_MAX;   /* 100*BIN7 */

            VSCtl_jrkVehVSLimSatMinAbs      = VSLIM_SAT_JERK_VEH_MIN;   /* -100*BIN7 */
            VSCtl_jrkVehVSLimSatMin         = VSLIM_SAT_JERK_VEH_MIN;   /* -100*BIN7 */
            VSCtl_jrkVehVSLimSatMinCvg      = VSLIM_SAT_JERK_VEH_MIN;   /* -100*BIN7 */
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F42224_Determiner_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42224_Determiner_Gabarits_Acceleration_Vehicule(
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            SInt16 vsctl_avehptmin_par, /* BIN10 */
                                            SInt16 vsctl_avehreq_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.67.0 */
    SInt32 mult_sat_max_te,mult_sat_min_te;
    SInt32 switch_select_1_in_23;
    SInt32 switch_select_2_out_01,switch_select_2_out_02;
    SInt32 sat_in_1,sat_out_1,sat_in_2,sat_out_2;

    /* [-8;8]BIN10 = ([-100;100]BIN7 * 0.04 * DEC3 * BIN3) / DEC3 */
    mult_sat_max_te = ((((SInt32)VSCtl_jrkVehVSLimSatMax * VSLIM_SCHEDULING) * BIN3) / DEC3);
    mult_sat_min_te = ((((SInt32)VSCtl_jrkVehVSLimSatMin * VSLIM_SCHEDULING) * BIN3) / DEC3);

    /* [-18;18]BIN10 = [-10;10]BIN10 + [-8;8]BIN10  */
    switch_select_1_in_23 = (SInt32)vsctl_avehreq_par + mult_sat_max_te;

    /* Switch 2 */
    switch((UInt32)VSCtl_stSatAVehVSLim)
    {
        case VSLIM_STSATAVEHVSLIM_ARRET:
            switch_select_2_out_01 = (SInt32)VSLIM_GABARITS_ACCEL_VEH_MAX;
            switch_select_2_out_02 = (SInt32)VSLIM_GABARITS_ACCEL_VEH_MIN;
            break;

        case VSLIM_STSATAVEHVSLIM_INIT_27:
        case VSLIM_STSATAVEHVSLIM_NON_EFFECTIF_27:
            switch_select_2_out_01 = (SInt32)vsctl_avehptmax_par;
            switch_select_2_out_02 = (SInt32)vsctl_avehptmin_par;
            break;

        case VSLIM_STSATAVEHVSLIM_EFFECTIF_27:
            switch_select_2_out_01 = DDS_M_MIN((SInt32)vsctl_avehptmax_par,(SInt32)VSCtl_aVehVSLimReqSatMax);
            switch_select_2_out_02 = DDS_M_MAX((SInt32)vsctl_avehptmin_par,(SInt32)VSCtl_aVehVSLimReqSatMin);
            break;

        case VSLIM_STSATAVEHVSLIM_ACTIVATION_27:
            switch_select_2_out_01 = DDS_M_MIN((SInt32)vsctl_avehptmax_par,(SInt32)vsctl_avehreq_par);
            switch_select_2_out_02 = (SInt32)vsctl_avehptmin_par;
            break;

        default:
            switch_select_2_out_01 = (SInt32)VSLIM_GABARITS_ACCEL_VEH_MAX;
            switch_select_2_out_02 = (SInt32)VSLIM_GABARITS_ACCEL_VEH_MIN;
            break;

    }

    /* Saturation */
    /* [-18;18]BIN7 = [-8;8]BIN7 + [-10;10]BIN7 */
    sat_in_1 = mult_sat_max_te + (SInt32)vsctl_avehreq_par;
    sat_in_2 = mult_sat_min_te + (SInt32)vsctl_avehreq_par;



    sat_out_1 = DDS_M_MIN((DDS_M_MAX(sat_in_1,switch_select_2_out_02)),switch_select_2_out_01);

    sat_out_2 = DDS_M_MIN((DDS_M_MAX(sat_in_2,switch_select_2_out_02)), switch_select_2_out_01);

    /* Output calculation */
    switch((UInt32)vsctl_stctl_avehvslim_par)
    {
        case VSLIM_STCTL_AVEHVSLIM_ARRET:   /* 0 */
            VSCtl_aVehVSLimReqMax = VSLIM_GABARITS_ACCEL_VEH_MAX;
            VSCtl_aVehVSLimReqMin = VSLIM_GABARITS_ACCEL_VEH_MIN;
            VSCtl_aVehVSLimReqSatMaxApl = VSLIM_GABARITS_ACCEL_VEH_MAX;
            VSCtl_aVehVSLimReqSatMinApl = VSLIM_GABARITS_ACCEL_VEH_MIN;
            break;

        case VSLIM_STCTL_AVEHVSLIM_CONTROLE:    /* 1 */
            if(VSLIM_STSATJRKVEH_ARRET == (UInt32)VSCtl_stSatJrkVehMaxVSLim)
            {
                VSCtl_aVehVSLimReqMax = VSLIM_GABARITS_ACCEL_VEH_MAX;
            }
            else if(VSLIM_STSATJRKVEH_NON_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMaxVSLim)
            {
                VSCtl_aVehVSLimReqMax = (SInt16)switch_select_2_out_01;
            }
            else if(VSLIM_STSATJRKVEH_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMaxVSLim)
            {
                VSCtl_aVehVSLimReqMax = (SInt16)sat_out_1;
            }
            else
            {
                /* Do nothing */
            }

            if(VSLIM_STSATJRKVEH_ARRET == (UInt32)VSCtl_stSatJrkVehMinVSLim)
            {
                VSCtl_aVehVSLimReqMin = VSLIM_GABARITS_ACCEL_VEH_MIN;
            }
            else if(VSLIM_STSATJRKVEH_NON_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMinVSLim)
            {
                VSCtl_aVehVSLimReqMin = (SInt16)switch_select_2_out_02;
            }
            else if(VSLIM_STSATJRKVEH_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMinVSLim)
            {
                VSCtl_aVehVSLimReqMin = (SInt16)sat_out_2;
            }
            else
            {
                /* Do nothing */
            }
            VSCtl_aVehVSLimReqSatMaxApl = (SInt16)switch_select_2_out_01;
            VSCtl_aVehVSLimReqSatMinApl = (SInt16)switch_select_2_out_02;
            break;

        case VSLIM_STCTL_AVEHVSLIM_TRANSITION_LENTE:        /* 2 & 3 */
        case VSLIM_STCTL_AVEHVSLIM_TRANSITION_RAPIDE:
            VSCtl_aVehVSLimReqMax = (SInt16)DDS_M_LIMIT(        switch_select_1_in_23,
                                                        (SInt32)VSLIM_GABARITS_ACCEL_VEH_MIN,
                                                        (SInt32)VSLIM_GABARITS_ACCEL_VEH_MAX);

            VSCtl_aVehVSLimReqMin = VSLIM_GABARITS_ACCEL_VEH_MIN;
            VSCtl_aVehVSLimReqSatMaxApl = (SInt16)switch_select_2_out_01;
            VSCtl_aVehVSLimReqSatMinApl = (SInt16)switch_select_2_out_02;
            break;

        default:
            VSCtl_aVehVSLimReqMax = VSLIM_GABARITS_ACCEL_VEH_MAX;
            VSCtl_aVehVSLimReqMin = VSLIM_GABARITS_ACCEL_VEH_MIN;
            VSCtl_aVehVSLimReqSatMaxApl = VSLIM_GABARITS_ACCEL_VEH_MAX;
            VSCtl_aVehVSLimReqSatMinApl = VSLIM_GABARITS_ACCEL_VEH_MIN;
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F4223_Determiner_Consigne_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4223_Determiner_Consigne_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_ptr /* BIN10 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.21.2 */
    VSLIM_F42231_Determiner_Mode_Controle_Vitesse_Vehicule(vsctl_spdveherrvslim_par, /* BIN7 */
                                                            vsctl_stctl_avehvslim_par);

    VSLIM_F42232_Determiner_Consigne_Acceleration_Vehicule(vsctl_spdveherrvslim_par, /* BIN7 */
                                                            vsctl_avehptmax_par, /* BIN10 */
                                                            vsctl_stctl_avehvslim_par,
                                                            vsctl_avehvslimreq_ptr /* BIN10 */);
}

/*******************************************************************************
*
* Function Name : VSLIM_F42231_Determiner_Mode_Controle_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42231_Determiner_Mode_Controle_Vitesse_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.34.1 */
    /* MODE_CONTROLE_VITESSE_VEHICULE */
    VSLIM_F42231_1_Determiner_Mode_Controle_Vitesse_Vehicule (vsctl_stctl_avehvslim_par,
                                                                vsctl_spdveherrvslim_par);

    /* LISSAGE CONTROLE VITESSE */
    VSLIM_F42231_2_Determiner_Mode_Controle_Vitesse_Vehicule (vsctl_stctl_avehvslim_par);
}

/*******************************************************************************
*
* Function Name : VSLIM_F42231_1_Determiner_Mode_Controle_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42231_1_Determiner_Mode_Controle_Vitesse_Vehicule (
                                            UInt8  vsctl_stctl_avehvslim_par,
                                            SInt16  vsctl_spdveherrvslim_par) /* BIN7 */
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2271.FR.34.0 */
    /* MODE_CONTROLE_VITESSE_VEHICULE */
    switch((UInt32)vslim_condition_changement_dynamique_state)
    {
        case VSLIM_COND_CHGT_DYN_INIT:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE == (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_TRANSITOIRE;
                VSCtl_bDynCtlSpdVehVSLim        = DDS_FALSE;
                VSCtl_tiFilSpdVehCtlVSLimDyn    = VSCtl_tiTol_DynCtlVSLim_C;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_COND_CHGT_DYN_TRANSITOIRE:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_INIT;
                VSCtl_bDynCtlSpdVehVSLim        = DDS_FALSE;
            }
            else if(DDS_M_ABS((SInt32)vsctl_spdveherrvslim_par) < (SInt32)VSCtl_spdErrVSLimSDyn_HysLo_C)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_CONF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_COND_CHGT_DYN_CONF:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_INIT;
                VSCtl_bDynCtlSpdVehVSLim        = DDS_FALSE;
            }
            else if(DDS_M_ABS((SInt32)vsctl_spdveherrvslim_par) > DDS_M_MAX((SInt32)VSCtl_spdErrVSLimSDyn_HysHi_C,
                                                                            (SInt32)VSCtl_spdErrVSLimSDyn_HysLo_C))
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_DECONF;
            }
            else if(   (DDS_M_ABS((SInt32)vsctl_spdveherrvslim_par) < DDS_M_MIN((SInt32)VSCtl_spdErrVSLimSDyn_HysLo_C,
                                                                                (SInt32)VSCtl_spdErrVSLimSDyn_HysHi_C))
                     &&((UInt32)VSCtl_tiFilSpdVehCtlVSLimDyn <= (0 * BIN0)))
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_STABILISE;
                VSCtl_bDynCtlSpdVehVSLim = DDS_TRUE;
            }
            else    /* during actions of this state */
            {

                VSCtl_tiFilSpdVehCtlVSLimDyn = (UInt8)DDS_M_POSITIVE_DECREMENT((SInt32)VSCtl_tiFilSpdVehCtlVSLimDyn,
                                                                                (SInt32)VSCtl_tiCfm_SDynCtlChgVSLim_C);
            }
            break;

        case VSLIM_COND_CHGT_DYN_DECONF:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_INIT;
                VSCtl_bDynCtlSpdVehVSLim        = DDS_FALSE;
            }
            else if(    (DDS_M_ABS((SInt32)vsctl_spdveherrvslim_par) > (SInt32)VSCtl_spdErrVSLimSDyn_HysHi_C) &&
                        ((UInt32)VSCtl_tiFilSpdVehCtlVSLimDyn >= (UInt32)VSCtl_tiTol_DynCtlVSLim_C) )
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_TRANSITOIRE;
                VSCtl_bDynCtlSpdVehVSLim        = DDS_FALSE;
                VSCtl_tiFilSpdVehCtlVSLimDyn    = VSCtl_tiTol_DynCtlVSLim_C;
            }
            else if(DDS_M_ABS((SInt32)vsctl_spdveherrvslim_par) < (SInt32)VSCtl_spdErrVSLimSDyn_HysLo_C)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_CONF;
            }
            else    /* during actions of this state */
            {
                VSCtl_tiFilSpdVehCtlVSLimDyn = (UInt8)DDS_M_LIMITED_INCREMENT((SInt32)VSCtl_tiFilSpdVehCtlVSLimDyn,
                                                                                (SInt32)VSCtl_tiDiCfmSDynCtlChgVSLim_C,
                                                                                (SInt32)VSCtl_tiTol_DynCtlVSLim_C);
            }
            break;

        case VSLIM_COND_CHGT_DYN_STABILISE:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_INIT;
                VSCtl_bDynCtlSpdVehVSLim        = DDS_FALSE;
            }
            else if(DDS_M_ABS((SInt32)vsctl_spdveherrvslim_par) > (SInt32)VSCtl_spdErrVSLimSDyn_HysHi_C)
            {
                vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_DECONF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        default:
            vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_INIT;
            VSCtl_bDynCtlSpdVehVSLim = DDS_FALSE;
            break;
    }
}


/*******************************************************************************
*
* Function Name : VSLIM_F42231_2_Determiner_Mode_Controle_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42231_2_Determiner_Mode_Controle_Vitesse_Vehicule (
                                            UInt8  vsctl_stctl_avehvslim_par) /* BIN7 */
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2271.FR.34.0 */
    /* LISSAGE CONTROLE VITESSE */
    switch((UInt32)vslim_lissage_controle_vitesse_state)
    {
        case VSLIM_LIS_CTRL_VIT_INIT:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE == (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_1;
                VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_1:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_INIT;
                VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            }
            else if((UInt32)DDS_TRUE == (UInt32)VSCtl_bDynCtlSpdVehVSLim)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_CONF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        case VSLIM_LIS_CTRL_VIT_CONF:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_INIT;
                VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            }
            else if((UInt32)DDS_FALSE == (UInt32)VSCtl_bDynCtlSpdVehVSLim)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_DECONF;
            }
            else if(((UInt32)DDS_TRUE == (UInt32)VSCtl_bDynCtlSpdVehVSLim) &&
                    ((UInt32)VSCtl_rSpdVehCtlVSLimDyn <= 0))
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_2;
            }
            else    /* during actions of this state */
            {
                VSCtl_rSpdVehCtlVSLimDyn = (UInt16)DDS_M_POSITIVE_DECREMENT((SInt32)VSCtl_rSpdVehCtlVSLimDyn,
                                                                            (SInt32)VSCtl_tiCfm_rSDynCtlVSLim_C);
            }
            break;

        case VSLIM_LIS_CTRL_VIT_DECONF:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_INIT;
                VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            }
            else if(((UInt32)DDS_FALSE == (UInt32)VSCtl_bDynCtlSpdVehVSLim) &&
                    ((UInt32)VSCtl_rSpdVehCtlVSLimDyn >= VSLIM_TAUX_APPLI_DYN_TRANS_MAX))
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_1;
                VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            }
            else if((UInt32)DDS_TRUE == (UInt32)VSCtl_bDynCtlSpdVehVSLim)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_CONF;
            }
            else    /* during actions of this state */
            {
                VSCtl_rSpdVehCtlVSLimDyn = (UInt16)DDS_M_LIMITED_INCREMENT((SInt32)VSCtl_rSpdVehCtlVSLimDyn,
                                                                                (SInt32)VSCtl_tiDiCfm_rCtlTDynVSLim_C,
                                                                                (SInt32)VSLIM_TAUX_APPLI_DYN_TRANS_MAX);
            }
            break;

        case VSLIM_LIS_CTRL_VIT_BARYCENTRE_IN_2:
            if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_INIT;
                VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            }
            else if((UInt32)DDS_FALSE == (UInt32)VSCtl_bDynCtlSpdVehVSLim)
            {
                vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_DECONF;
            }
            else    /* during actions of this state */
            {
                /* NONE */
            }
            break;

        default:
            vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_INIT;
            VSCtl_rSpdVehCtlVSLimDyn = VSLIM_TAUX_APPLI_DYN_TRANS_MAX;
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F42232_Determiner_Consigne_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F42232_Determiner_Consigne_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            SInt16 vsctl_avehptmax_par, /* BIN10 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_ptr /* BIN10 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.66.0 */
    UInt16 vsctl_spdctlgain1vslimaveh_m;    /* BIN7 */
    SInt32 vslim_f42232_out_sat;    /* BIN10 */
    SInt32 barycentre_in1;  /* BIN14 */
    SInt32 barycentre_in2;  /* BIN14 */
    SInt32 barycentre_out;  /* BIN10 */
    SInt32 temp_s32;
    SInt32 filter_in;   /* [-500;500]BIN10 */
    SInt32 filter_out;  /* [-100;100]BIN7 */

    vsctl_spdctlgain1vslimaveh_m = DDS_M_MAP3D_SSU16(&VSCTL_SPDCTLGAIN1VSLIMAVEH_M_APM,
                                                        vsctl_avehptmax_par,
                                                        vsctl_spdveherrvslim_par);

    /* [-708;708]BIN14 = [0;10]BIN7 * [-255;255]BIN7 / 3.6*/
    /* barycentre_in1 = vsctl_spdctlgain1vslimaveh_m * vsctl_spdveherrvslim_par / 3.6 */
    /* barycentre_in1 = vsctl_spdctlgain1vslimaveh_m * vsctl_spdveherrvslim_par * 5 / 18 */

    /* [-1275;1275]BIN7 = [-255;255]BIN7 * 5*/
    temp_s32 = (SInt32)vsctl_spdveherrvslim_par * 5;

    /* [-708;708]BIN14 = [0;10]BIN7 * [-1275;1275]BIN7 / 18*/
    barycentre_in1 = ((SInt32)vsctl_spdctlgain1vslimaveh_m * temp_s32) / 18;

    /* [-708;708]BIN14 = [0;10]BIN7 * [-1275;1275]BIN7 / 18*/
    barycentre_in2 = ((SInt32)VSCtl_spdCtlGain2VSLimAVeh_C * temp_s32) / 18;

    barycentre_in2 = DDS_M_SATURATION_V2(barycentre_in2,
                                            /* BIN14 = BIN10 * BIN4 */
                                            (SInt32)VSCtl_aVehVSLimDynStbMin_C * BIN4,
                                            (SInt32)VSCtl_aVehVSLimDynStbMax_C * BIN4);

    /* BIN10 = BIN14 / BIN4 */
    barycentre_out = DDS_M_BARY_FILTER_S32(barycentre_in1,
                                                 barycentre_in2,
                                                 VSCtl_rSpdVehCtlVSLimDyn,
                                                 (UInt16)(100 * BIN7)) / BIN4;

    if(VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)
    {
        vslim_f42232_out_sat = DDS_M_SATURATION_V2((SInt32)VSLIM_P10_BIN10,
                                                    (SInt32)VSCtl_aVehVSLimReqMin,
                                                    (SInt32)VSCtl_aVehVSLimReqMax);
    }
    else
    {

        vslim_f42232_out_sat = DDS_M_SATURATION_V2(barycentre_out,
                                                    (SInt32)VSCtl_aVehVSLimReqMin,
                                                    (SInt32)VSCtl_aVehVSLimReqMax);
    }

    /* [-500;500]BIN10 = (([-10;10]BIN10 - [-10;10]BIN10)  * DEC3) / (0.04 * DEC3) */
    /* [-500;500]BIN10 = ([-20;20]BIN10 * DEC3) / (0.04 * DEC3) */
    filter_in = ((vslim_f42232_out_sat - vslim_f42232_out_sat_prev) * DEC3) / VSLIM_SCHEDULING;

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_aVehVSLim)
    {
        /* BIN7 = BIN10 / BIN3 */
        filter_out = DDS_M_FILTER_LP1_S32_INIT(&vslim_f42232_filter_lp1_ptr,
                                                  filter_in) / BIN3;
    }
    else
    {
        /* BIN7 = BIN10 / BIN3 */
        filter_out = DDS_M_FILTER_LP1_S32(&vslim_f42232_filter_lp1_ptr,
                                             filter_in,
                                             /* BIN15 = BIN10 * BIN5 */
                                             (UInt16)((UInt32)VSCtl_tiFil_jrkVehVSLimRq_C * BIN5)) / BIN3;
    }
    filter_out = DDS_M_LIMIT(filter_out,
                                (SInt32)VSLIM_SAT_JERK_VEH_MIN,
                                (SInt32)VSLIM_SAT_JERK_VEH_MAX);

    if(VSLIM_STCTL_AVEHVSLIM_ARRET != (UInt32)vsctl_stctl_avehvslim_par)
    {
        VSCtl_spdCtlGain1VSLimAVeh = vsctl_spdctlgain1vslimaveh_m;
        *vsctl_avehvslimreq_ptr = (SInt16)vslim_f42232_out_sat;
        VSCtl_jrkVehVSLimReq = (SInt16)filter_out;
        VSCtl_aVehVSLimReqRaw = (SInt16)DDS_M_LIMIT(barycentre_out,
                                                    (SInt32)VSLIM_N10_BIN10,
                                                    (SInt32)VSLIM_P10_BIN10);
    }
    else
    {
        VSCtl_spdCtlGain1VSLimAVeh = VSLIM_P1_BIN7;
        *vsctl_avehvslimreq_ptr = VSLIM_P10_BIN10;
        VSCtl_jrkVehVSLimReq = 0;
        VSCtl_aVehVSLimReqRaw = VSLIM_P10_BIN10;
    }

    vslim_f42232_out_sat_prev = vslim_f42232_out_sat;
}

/*******************************************************************************
*
* Function Name : VSLIM_F423_Determiner_Consigne_Potentiel_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F423_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 ext_stctlcmdpttqpotcf_par,
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehpotvslimreq_ptr, /* BIN10 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bctl_avehpotvslim_ptr,
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_rctltqwhlptpotvslim_ptr, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwnvslimreq_ptr, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsupvslimreq_ptr /* DEC2 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.37.2 */
    VSLIM_F4231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule(vsctl_spdveherrvslim_par, /* BIN7 */
                                                                            vsctl_stctl_avehvslim_par,
                                                                            ext_stctlcmdpttqpotcf_par,
                                                                            vsctl_stvsctlinfo_par,
                                                                            vsctl_stvslimextd_par,
                                                                            vsctl_bctl_avehpotvslim_ptr);

    VSLIM_F4232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(*vsctl_bctl_avehpotvslim_ptr,
                                                                    vsctl_spdveherrvslim_par, /* BIN7 */
                                                                    vsctl_spdveh_par, /* BIN7 */
                                                                    vsctl_avehpotvslimreq_ptr /* BIN10 */);

    VSLIM_F4233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP(*vsctl_bctl_avehpotvslim_ptr,
                                                                        vsctl_spdveherrvslim_par, /* BIN7 */
                                                                        vsctl_rctltqwhlptpotvslim_ptr /* BIN4 */);

    VSLIM_F4234_Determiner_Temps_Confirmation_Changement_Rapport(*vsctl_avehpotvslimreq_ptr, /* BIN10 */
                                                                    *vsctl_bctl_avehpotvslim_ptr,
                                                                    vsctl_spdveherrvslim_par, /* BIN7 */
                                                                    vsctl_spdveh_par, /* BIN7 */
                                                                    vsctl_ticfmsdwnvslimreq_ptr, /* DEC2 */
                                                                    vsctl_ticfmsupvslimreq_ptr /* DEC2 */);
}

/*******************************************************************************
*
* Function Name : VSLIM_F4231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4231_Determiner_Mode_Commande_Potentiel_Acceleration_Vehicule(
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt8 vsctl_stctl_avehvslim_par,
                                            UInt8 ext_stctlcmdpttqpotcf_par,
                                            UInt8 vsctl_stvsctlinfo_par,
                                            UInt8 vsctl_stvslimextd_par,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bctl_avehpotvslim_ptr)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.65.0 */

    if((UInt32)DDS_TRUE != (UInt32)vsctl_bctl_avehpotvslim_prev)
    {
        if( (VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par) &&
            (VSLIM_STCTL_AVEHVSLIM_CONTROLE == (UInt32)vsctl_stctl_avehvslim_par)   &&
            ((SInt32)VSCtl_spdELimAVehP_HysLoP_C > (SInt32)vsctl_spdveherrvslim_par)    &&
            ((SInt32)VSCtl_spdELimAVehP_HysLoN_C < (SInt32)vsctl_spdveherrvslim_par)    &&
            (   (   (VSLIM_STCTLCMDPTTQPOTCF_RAPPORT == (UInt32)ext_stctlcmdpttqpotcf_par)  &&
                    (   (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimNGear_AE_C)) ||
                        (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimNGear_ANE_C))    ||
                        (   (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)  &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimNGear_REP_C))))  ||
                (   (VSLIM_STCTLCMDPTTQPOTCF_COUPLE == (UInt32)ext_stctlcmdpttqpotcf_par)   &&
                    (   (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimTq_AE_C))    ||
                        (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimTq_ANE_C))   ||
                        (   (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)  &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimTq_REP_C)))) ||
                (   (VSLIM_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR == (UInt32)ext_stctlcmdpttqpotcf_par)   &&
                    (   (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimPed_AE_C))   ||
                        (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF == (UInt32)vsctl_stvslimextd_par)   &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimPed_ANE_C))  ||
                        (   (VSLIM_VSCTL_STVSLIMEXTD_REPRISE == (UInt32)vsctl_stvslimextd_par)  &&
                            ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvPotVSLimPed_REP_C))))))
        {
            vsctl_bctl_avehpotvslim_prev = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        if( (VSLIM_STVSCTLINFO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par) ||
            (VSLIM_STCTL_AVEHVSLIM_CONTROLE != (UInt32)vsctl_stctl_avehvslim_par)     ||
            ((SInt32)VSCtl_spdELimAVehP_HysHiP_C < (SInt32)vsctl_spdveherrvslim_par)    ||
            ((SInt32)VSCtl_spdELimAVehP_HysHiN_C > (SInt32)vsctl_spdveherrvslim_par)    ||
            (   (   (VSLIM_STCTLCMDPTTQPOTCF_RAPPORT == (UInt32)ext_stctlcmdpttqpotcf_par)  &&
                    (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_AE_C))    &&
                        (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_ANE_C))   &&
                        (   (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)  ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_REP_C)))  ||
                (   (VSLIM_STCTLCMDPTTQPOTCF_COUPLE == (UInt32)ext_stctlcmdpttqpotcf_par)   &&
                    (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_AE_C))    &&
                        (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_ANE_C))   &&
                        (   (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)  ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_REP_C)))  ||
                (   (VSLIM_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR == (UInt32)ext_stctlcmdpttqpotcf_par)   &&
                    (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_AE_C))    &&
                        (   (VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF != (UInt32)vsctl_stvslimextd_par)   ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_ANE_C))   &&
                        (   (VSLIM_VSCTL_STVSLIMEXTD_REPRISE != (UInt32)vsctl_stvslimextd_par)  ||
                            ((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvPotVSLimNGear_REP_C)))))
        {
            vsctl_bctl_avehpotvslim_prev = DDS_FALSE;
            VSCtl_bAcvFil_aVehPotVSLim = DDS_FALSE;
        }
        else
        {
            VSCtl_bAcvFil_aVehPotVSLim = DDS_TRUE;
        }
    }

    *vsctl_bctl_avehpotvslim_ptr = vsctl_bctl_avehpotvslim_prev;
}

/*******************************************************************************
*
* Function Name : VSLIM_F4232_Determiner_Consigne_Potentiel_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                                            UInt8 vsctl_bctl_avehpotvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehpotvslimreq_ptr /* BIN10 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.68.1 */
    SInt32 sat_out,vslim_f4232_input_filter;
    SInt32 vslim_f4232_filt_output;
    SInt32 vsctl_avehpotoftvslimreq_m;  /* BIN10 */
    SInt32 vsctl_avehpotvslimreqraw_tmp;

    /* [-10;10]BIN10 */
    vsctl_avehpotoftvslimreq_m = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHPOTOFTVSLIMREQ_M_APM,
                                                            vsctl_spdveh_par,
                                                            vsctl_spdveherrvslim_par);

    /* [-12750;12750]BIN14 = ([-255;255]BIN7 * 5) * [0;10]BIN7 */
    vsctl_avehpotvslimreqraw_tmp = ((SInt32)vsctl_spdveherrvslim_par * 5) * (SInt32)VSCtl_spdCtlGainVSLimAVehPot_C;

    /* [-708;708]BIN10 = [-12750;12750]BIN14 / (18 * BIN4) */
    vsctl_avehpotvslimreqraw_tmp = vsctl_avehpotvslimreqraw_tmp / (18 * BIN4);

    /* [-10;10] BIN10 */
    sat_out = DDS_M_SATURATION_V2(vsctl_avehpotvslimreqraw_tmp, (SInt32)VSCtl_aVehVSLimReqSatMin,(SInt32)VSCtl_aVehVSLimReqSatMax);

    /* [-20;20] BIN10 */
    sat_out = sat_out + vsctl_avehpotoftvslimreq_m;

    /* [-750;750] BIN10 = ( ( [-20;20] BIN10 - [-10;10] BIN10 ) * DEC3 ) / (0.04 DEC3) */
    vslim_f4232_input_filter = (((sat_out - (SInt32)vslim_f4232_sat_out_prev) * DEC3) / VSLIM_SCHEDULING);   /* VSLIM_SCHEDULING constant */

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_aVehPotVSLim)
    {
        /* BIN7 = BIN10 / BIN3 */
        vslim_f4232_filt_output = DDS_M_FILTER_LP1_S32_INIT(&vslim_f4232_filt_struct,
                                                            vslim_f4232_input_filter) / BIN3;
    }
    else
    {
        /* BIN7 = BIN10 / BIN3 */
        vslim_f4232_filt_output = DDS_M_FILTER_LP1_S32(&vslim_f4232_filt_struct,
                                                            vslim_f4232_input_filter,
                                                            /* BIN15 = BIN10 * BIN5 */
                                                            (UInt16)((UInt32)VSCtl_tiFil_jrkVehPotVSLimRq_C * BIN5)) / BIN3;
    }

    if((UInt32)DDS_FALSE != (UInt32)vsctl_bctl_avehpotvslim_par)
    {
        VSCtl_aVehPotVSLimReqRaw = (SInt16)DDS_M_LIMIT(vsctl_avehpotvslimreqraw_tmp,
                                                        (SInt32)VSLIM_N10_BIN10,
                                                        (SInt32)VSLIM_P10_BIN10);

        *vsctl_avehpotvslimreq_ptr = (SInt16)DDS_M_LIMIT(sat_out,
                                                        (SInt32)VSLIM_N10_BIN10,
                                                        (SInt32)VSLIM_P10_BIN10);

        VSCtl_jrkVehPotVSLimReq = (SInt16)DDS_M_LIMIT(vslim_f4232_filt_output,
                                                        (SInt32)VSLIM_SAT_JERK_VEH_MIN,
                                                        (SInt32)VSLIM_SAT_JERK_VEH_MAX);

        VSCtl_aVehPotVSLimReqOft = (SInt16)vsctl_avehpotoftvslimreq_m;
    }
    else
    {
        VSCtl_aVehPotVSLimReqRaw = 0;
        *vsctl_avehpotvslimreq_ptr = VSLIM_P10_BIN10;
        VSCtl_jrkVehPotVSLimReq = 0;
        VSCtl_aVehPotVSLimReqOft = 0;
    }

    vslim_f4232_sat_out_prev = (SInt16)sat_out;
}

/*******************************************************************************
*
* Function Name : VSLIM_F4233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4233_Determiner_Taux_Application_Potentiel_Couple_Roue_GMP(
                                            UInt8 vsctl_bctl_avehpotvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_rctltqwhlptpotvslim_ptr /* BIN4 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.40.1 */

    if((UInt32)DDS_FALSE == (UInt32)vsctl_bctl_avehpotvslim_par)
    {
        *vsctl_rctltqwhlptpotvslim_ptr = (0 * BIN4);
    }
    else
    {
        *vsctl_rctltqwhlptpotvslim_ptr =  DDS_M_MAP2D_SU16(&VSCTL_RCTLTQPOTVSLIM_T_APM, vsctl_spdveherrvslim_par);
    }
}

/*******************************************************************************
*
* Function Name : VSLIM_F4234_Determiner_Temps_Confirmation_Changement_Rapport
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4234_Determiner_Temps_Confirmation_Changement_Rapport(
                                            SInt16 vsctl_avehpotvslimreq_par, /* BIN10 */
                                            UInt8 vsctl_bctl_avehpotvslim_par,
                                            SInt16 vsctl_spdveherrvslim_par, /* BIN7 */
                                            UInt16 vsctl_spdveh_par, /* BIN7 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwnvslimreq_ptr, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsupvslimreq_ptr /* DEC2 */)
{
    /* SSTG REQ TAG : CSMT_CGMT08_2271.FR.41.1 */
    UInt16 vslim_f4234_map_out_1;
    UInt16 vslim_f4234_map_out_2;
    UInt16 vslim_f4234_filter_output_1;
    UInt16 vslim_f4234_filter_output_2;
    UInt16 vslim_f4234_filter_output_3;
    UInt16 vslim_f4234_filter_output_4;

    /* [0;16]DEC2 */
    vslim_f4234_map_out_1 = DDS_M_MAP3D_SSU16(&VSCTL_TICFMSUPVSLIMREQ_M_APM,
                                                vsctl_avehpotvslimreq_par,
                                                VSCtl_jrkVehPotVSLimReq);

    /* [0;16]DEC2 */
    vslim_f4234_map_out_2 = DDS_M_MAP3D_USU16(&VSCTL_TICFMSDWNVSLIMREQ_M_APM,
                                                vsctl_spdveh_par,
                                                vsctl_spdveherrvslim_par);

    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvFil_aVehPotVSLim)
    {
        vslim_f4234_filter_output_1 = DDS_M_FILTER_LP1_U16(&vslim_f4234_filter_1_struct,
                                                     vslim_f4234_map_out_1,
                                                     (UInt16)VSCtl_tiFil_tiCfmSupVSLimRq1_C,
                                                     ((UInt16)BIN7));

        vslim_f4234_filter_output_2 = DDS_M_FILTER_LP1_U16(&vslim_f4234_filter_2_struct,
                                                     vslim_f4234_map_out_1,
                                                     (UInt16)VSCtl_tiFil_tiCfmSupVSLimRq2_C,
                                                     ((UInt16)BIN7));

        vslim_f4234_filter_output_3 = DDS_M_FILTER_LP1_U16(&vslim_f4234_filter_3_struct,
                                                     vslim_f4234_map_out_2,
                                                     (UInt16)VSCtl_tiFil_tiCfmSdwnVSLimR1_C,
                                                     ((UInt16)BIN7));

        vslim_f4234_filter_output_4 = DDS_M_FILTER_LP1_U16(&vslim_f4234_filter_4_struct,
                                                     vslim_f4234_map_out_2,
                                                     (UInt16)VSCtl_tiFil_tiCfmSdwnVSLimR2_C,
                                                     ((UInt16)BIN7));
    }
    else
    {
        vslim_f4234_filter_output_1 = DDS_M_FILTER_LP1_U16_INIT(&vslim_f4234_filter_1_struct,
                                                            VSCtl_tiCfmSupVSLimReqIni_C);

        vslim_f4234_filter_output_2 = DDS_M_FILTER_LP1_U16_INIT(&vslim_f4234_filter_2_struct,
                                                            VSCtl_tiCfmSupVSLimReqIni_C);

        vslim_f4234_filter_output_3 = DDS_M_FILTER_LP1_U16_INIT(&vslim_f4234_filter_3_struct,
                                                            VSCtl_tiCfmSdwnVSLimReqIni_C);

        vslim_f4234_filter_output_4 = DDS_M_FILTER_LP1_U16_INIT(&vslim_f4234_filter_4_struct,
                                                            VSCtl_tiCfmSdwnVSLimReqIni_C);
    }

    if((UInt32)DDS_FALSE != (UInt32)vsctl_bctl_avehpotvslim_par)
    {
        VSCtl_tiCfmSupVSLimReqRaw1 = vslim_f4234_map_out_1;
        VSCtl_tiCfmSupVSLimReqRaw2 = vslim_f4234_filter_output_1;
        *vsctl_ticfmsupvslimreq_ptr = (UInt16)DDS_M_MAX((UInt32)vslim_f4234_filter_output_1, (UInt32)vslim_f4234_filter_output_2);
        VSCtl_tiCfmSupVSLimReqRaw3 = vslim_f4234_filter_output_2;
        VSCtl_tiCfmSdwnVSLimReqRaw1 = vslim_f4234_map_out_2;
        VSCtl_tiCfmSdwnVSLimReqRaw2 = vslim_f4234_filter_output_3;
        *vsctl_ticfmsdwnvslimreq_ptr = (UInt16)DDS_M_MAX((UInt32)vslim_f4234_filter_output_3, (UInt32)vslim_f4234_filter_output_4);
        VSCtl_tiCfmSdwnVSLimReqRaw3 = vslim_f4234_filter_output_4;
    }
    else
    {
        VSCtl_tiCfmSupVSLimReqRaw1 = 0;
        VSCtl_tiCfmSupVSLimReqRaw2 = 0;
        *vsctl_ticfmsupvslimreq_ptr = 0;
        VSCtl_tiCfmSupVSLimReqRaw3 = 0;
        VSCtl_tiCfmSdwnVSLimReqRaw1 = 0;
        VSCtl_tiCfmSdwnVSLimReqRaw2 = 0;
        *vsctl_ticfmsdwnvslimreq_ptr = 0;
        VSCtl_tiCfmSdwnVSLimReqRaw3 = 0;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_Veh_Spd_Ctrl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Veh_Spd_Ctrl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSLimReq_swc_out, /* BIN10 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_swc_out, /* BIN10 */
                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtl_aVehPotVSLim_swc_out,
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSLim_swc_out, /* BIN4 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSLim_swc_out, /* BIN7 */
                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_aVehVSLim_swc_out,
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSLimReq_swc_out, /* DEC2 */
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSLimReq_swc_out /* DEC2 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_aVehPotVSLimReq_swc_out = VSLIM_P10_BIN10;
    *VSCtl_aVehVSLimReq_swc_out = VSLIM_P10_BIN10;
    *VSCtl_bCtl_aVehPotVSLim_swc_out = DDS_FALSE;
    *VSCtl_rCtlTqWhlPTPotVSLim_swc_out = (UInt16)(0 * BIN4);
    *VSCtl_spdVehErrVSLim_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_stCtl_aVehVSLim_swc_out = (UInt8)VSLIM_STCTL_AVEHVSLIM_ARRET;
    *VSCtl_tiCfmSdwnVSLimReq_swc_out = (UInt16)(0 * DEC2);
    *VSCtl_tiCfmSupVSLimReq_swc_out = (UInt16)(0 * DEC2);
    VSCtl_jrkVehVSLimReq = (SInt16)(0 * BIN7);
    VSCtl_spdVehVSLimReqFil = (UInt16)(255 * BIN7);


    /* ---- Init Macros ---- */
    (void)DDS_M_SLEW_U32_INIT(&vsctl_f4212_slew_struct_ptr,
                                (UInt32)(0 * BIN20));

    (void)DDS_M_FILTER_LP1_S32_INIT(&vslim_f42232_filter_lp1_ptr,
                                                  0);

    /* ---- Init non displayable variables ---- */
    vsctl_stctl_avehvslim_prev = (UInt8)VSLIM_STCTL_AVEHVSLIM_ARRET;
    vslim_lissage_controle_vitesse_state = (UInt8)VSLIM_LIS_CTRL_VIT_INIT;
    vslim_condition_changement_dynamique_state = (UInt8)VSLIM_COND_CHGT_DYN_INIT;

    vsctl_bctl_avehpotvslim_prev = DDS_FALSE;
    vsctl_avehpotvslimreq_out_prev =     *VSCtl_aVehPotVSLimReq_swc_out;
    vsctl_rctltqwhlptpotvslim_out_prev = *VSCtl_rCtlTqWhlPTPotVSLim_swc_out;
    vsctl_ticfmsdwnvslimreq_out_prev =   *VSCtl_tiCfmSdwnVSLimReq_swc_out;
    vsctl_ticfmsupvslimreq_out_prev =    *VSCtl_tiCfmSupVSLimReq_swc_out;

    vslim_f4232_sat_out_prev = 0;
    vslim_f42232_out_sat_prev = 0;

    /* ---- Init displayable variables ---- */
    VSCtl_aVehPotVSLimReqOft = (SInt16)(0 * BIN10); /* BIN10 */
    VSCtl_aVehPotVSLimReqRaw = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqMax = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqMin = VSLIM_N10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqRaw = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMax = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMaxAbs = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMaxApl = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMaxCft = VSLIM_P10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMin = VSLIM_N10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMinAbs = VSLIM_N10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMinApl = VSLIM_N10_BIN10; /* BIN10 */
    VSCtl_aVehVSLimReqSatMinCft = VSLIM_N10_BIN10; /* BIN10 */
    VSCtl_bAcvFil_aVehPotVSLim = DDS_FALSE;
    VSCtl_bAcvFil_aVehVSLim = DDS_FALSE;
    VSCtl_bAcvFilSpdVehVSLimReq = DDS_FALSE;
    VSCtl_bDynCtlSpdVehVSLim = DDS_FALSE;
    VSCtl_bInhFilSpdVehVSLimReq = DDS_FALSE;
    VSCtl_jrkVehPotVSLimReq = (SInt16)(0 * BIN7); /* BIN7 */
    VSCtl_jrkVehVSLimSatMax = VSLIM_SAT_JERK_VEH_MAX; /* BIN7 */
    VSCtl_jrkVehVSLimSatMax1Tran = VSLIM_SAT_JERK_VEH_MAX; /* BIN7 */
    VSCtl_jrkVehVSLimSatMax2Tran = VSLIM_SAT_JERK_VEH_MAX; /* BIN7 */
    VSCtl_jrkVehVSLimSatMaxAbs = VSLIM_SAT_JERK_VEH_MAX; /* BIN7 */
    VSCtl_jrkVehVSLimSatMaxCrit = VSLIM_SAT_JERK_VEH_MAX; /* BIN7 */
    VSCtl_jrkVehVSLimSatMaxCvg = VSLIM_SAT_JERK_VEH_MAX; /* BIN7 */
    VSCtl_jrkVehVSLimSatMin = VSLIM_SAT_JERK_VEH_MIN; /* BIN7 */
    VSCtl_jrkVehVSLimSatMinAbs = VSLIM_SAT_JERK_VEH_MIN; /* BIN7 */
    VSCtl_jrkVehVSLimSatMinCvg = VSLIM_SAT_JERK_VEH_MIN; /* BIN7 */
    VSCtl_rSpdVehCtlVSLimDyn = (UInt16)(100 * BIN7); /* BIN7 */
    VSCtl_spdCtlGain1VSLimAVeh = VSLIM_P1_BIN7; /* BIN7 */
    VSCtl_spdVehVSLimReqPrev = (UInt16)(0 * BIN7); /* BIN7 */
    VSCtl_stFilSpdVehVSLim = (UInt8)VSLIM_STFILSPDVEHVSLIM_ARRET;
    VSCtl_stSatAVehVSLim = (UInt8)VSLIM_STSATAVEHVSLIM_ARRET;
    VSCtl_stSatJrkVehMaxVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
    VSCtl_stSatJrkVehMinVSLim = (UInt8)VSLIM_STSATJRKVEH_ARRET;
    VSCtl_tiCfmSdwnVSLimReqRaw1 = (UInt16)(0 * DEC2); /* DEC2 */
    VSCtl_tiCfmSdwnVSLimReqRaw2 = (UInt16)(0 * DEC2); /* DEC2 */
    VSCtl_tiCfmSdwnVSLimReqRaw3 = (UInt16)(0 * DEC2); /* DEC2 */
    VSCtl_tiCfmSupVSLimReqRaw1 = (UInt16)(0 * DEC2); /* DEC2 */
    VSCtl_tiCfmSupVSLimReqRaw2 = (UInt16)(0 * DEC2); /* DEC2 */
    VSCtl_tiCfmSupVSLimReqRaw3 = (UInt16)(0 * DEC2); /* DEC2 */
    VSCtl_tiFilSpdVehCtlVSLimDyn = VSCtl_tiTol_DynCtlVSLim_C; /* BIN0 */
    VSCtl_tiFilStCtlAVehVSLim = VSCtl_tiFil_stCtlAVehVSLim_C; /* BIN0 */
}

#define VSLIM_STOP_SEC_CODE
#include "VSLim_MemMap.h"

