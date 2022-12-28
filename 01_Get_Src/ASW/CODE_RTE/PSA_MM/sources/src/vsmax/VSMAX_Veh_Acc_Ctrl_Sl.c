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
* Ref X:\integration_view_00PSASWC_D620D01\blois_psa_sstg\Software\Appli\VSMax\src\VSMAX_Veh_Acc_Ctrl_Sl.c
* Version int :/main/L01_03/1 Date: 6/1/2012 12 h 4 m User:meme 
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_030_IMPL2
*    comments :calibration value update for VSMax 12.0
* Version dev :\main\branch_demezil_vsmax_view\1 Date: 5/1/2012 16 h 52 m User:demezil 
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_030_IMPL2
*    comments :calibration value update for VSMax 12.0
* Version dev :\main\branch_morisseau_xvv_vsmax_e6_dev\2 Date: 22/11/2011 8 h 55 m User:morisseau
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_030_IMPL1
*    comments :calibration value update
* Version int :/main/L01_02/1 Date: 25/8/2011 10 h 47 m User:meme
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_020_IMPL1
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\2 Date: 27/7/2011 10 h 45 m User:demezil
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_020_IMPL1
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\1 Date: 18/7/2011 11 h 28 m User:demezil
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL2_D
*    comments :for VSMax 11.0 : optimisation of function F52223
* Version int :/main/L01_01/2 Date: 3/2/2011 15 h 9 m User:esnault
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL2
*    comments :UT correction
* Version dev :\main\branch_lemort_vsmax_dev\6 Date: 2/2/2011 10 h 34 m User:lemort
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL2
*    comments :UT correction
* Version dev :\main\branch_lemort_vsmax_dev\5 Date: 24/1/2011 11 h 43 m User:demezil
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL2
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\4 Date: 18/1/2011 8 h 13 m User:demezil
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\3 Date: 18/1/2011 8 h 12 m User:demezil
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 17/1/2011 17 h 52 m User:lemort
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\1 Date: 17/12/2010 14 h 14 m User:lemort
*    TWK_model:VSMAX_Veh_Acc_Ctrl_Sl_L01_010_IMPL1
*    comments :for dev VSMax 10.0
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/


#include "VSMax.h"



/*******************************************************************************
* File Macro Definitions
*******************************************************************************/




/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_tiFilStCtlAVehVSMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMinVSMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMaxVSMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehPotVSMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehVSMax;
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"

/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSMaxReqInt; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rSpdVehCtlVSMaxDyn; /* BIN7 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"

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



/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMaxAbs; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMaxApl; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMaxCft; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMinAbs; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMinApl; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMinCft; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMax1Tran; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMaxAbs; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMaxCrit; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMaxCvg; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMinAbs; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMinCvg; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdCtlGain1VSMaxAVeh; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReqRaw1; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReqRaw2; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReqRaw3; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSMaxReqRaw1; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSMaxReqRaw2; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSMaxReqRaw3; /* DEC2 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxReq; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMax; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMin; /* BIN10 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSMAX_START_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSMaxDynStbMin_C = (CONST(SInt16, AUTOMATIC))(-0.2001953125 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSMaxDynStbMax_C = (CONST(UInt16, AUTOMATIC))(0.2001953125 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGain2VSMaxAVeh_C = (CONST(UInt16, AUTOMATIC))(0.5 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGainVSMaxAVehPot_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReqIni_C = (CONST(UInt16, AUTOMATIC))(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSMaxReqIni_C = (CONST(UInt16, AUTOMATIC))(1.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVehPotVSMaxRq_C = (CONST(UInt16, AUTOMATIC))(0.286 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVehVSMaxRq_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
#define VSMAX_STOP_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSMAX_START_SEC_CALIB_8BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvJrkSatMnCritVSMax_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSdwnVSMxRq1_C = (CONST(UInt8, AUTOMATIC))(0.3359375 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSdwnVSMxRq2_C = (CONST(UInt8, AUTOMATIC))(0.0703125 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSupVSMaxRq1_C = (CONST(UInt8, AUTOMATIC))(0.3359375 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSupVSMaxRq2_C = (CONST(UInt8, AUTOMATIC))(0.0703125 * BIN7);
#define VSMAX_STOP_SEC_CALIB_8BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSMAX_START_SEC_CARTO_16BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSMaxSatMaxAbsY_A[VSC_8_SIZE] = {
(SInt16)(-1 * BIN10), (SInt16)(-0.796875 * BIN10),
(SInt16)(-0.6015625 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.203125 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.6015625 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSMaxSatMaxCvg_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-5 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.453125 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.2109375 * BIN10), (SInt16)(-0.203125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.1015625 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.296875 * BIN10), (SInt16)(0.3984375 * BIN10),
(SInt16)(0.5 * BIN10), (SInt16)(5 * BIN10), (SInt16)(6 * BIN10),
(SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSMaxSatMinAbsY_A[VSC_8_SIZE] = {
(SInt16)(-1 * BIN10), (SInt16)(-0.796875 * BIN10),
(SInt16)(-0.6015625 * BIN10), (SInt16)(-0.203125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.3984375 * BIN10), (SInt16)(0.6015625 * BIN10),
(SInt16)(0.796875 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSMaxSatMinCvg_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-6 * BIN10), (SInt16)(-5 * BIN10),
(SInt16)(-0.5 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.296875 * BIN10), (SInt16)(-0.203125 * BIN10),
(SInt16)(-0.1015625 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.2109375 * BIN10), (SInt16)(0.3984375 * BIN10),
(SInt16)(0.453125 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(5 * BIN10),
(SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSMaxSatMxTra1Y_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-1 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0.203125 * BIN10), (SInt16)(0.6015625 * BIN10), (SInt16)(1 * BIN10),
(SInt16)(2 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehReq_tiCfmSupVSMaxX_A[VSC_8_SIZE] = {
(SInt16)(-3.5 * BIN10), (SInt16)(-1.25 * BIN10), (SInt16)(-0.3984375 * BIN10),
(SInt16)(-0.203125 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.3984375 * BIN10), (SInt16)(1.25 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehSpdCtlGain1VSMaxX_A[VSC_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(1 * BIN10),
(SInt16)(2 * BIN10), (SInt16)(4 * BIN10), (SInt16)(6 * BIN10),
(SInt16)(8 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMaxAbs_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMaxCft_M
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
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) },
{
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10), (UInt16)(2 * BIN10), (UInt16)(2 * BIN10),
(UInt16)(2 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMinAbs_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSatMinCft_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) },
{
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10), (SInt16)(-10 * BIN10),
(SInt16)(-10 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSMaxReqSatMx1Tra_M
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

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMaxAbs_M
[VSC_8_SIZE][VSC_8_SIZE] = {
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
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7) },
{
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMaxCvg_T
[VSC_16_SIZE] = {
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMinAbs_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7) },
{
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7) },
{
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7) },
{
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7) },
{
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7) },
{
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7) },
{
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7) },
{
(SInt16)(-20 * BIN7), (SInt16)(-20 * BIN7), (SInt16)(-20 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-20 * BIN7), (SInt16)(-20 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-20 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMinCvg_T
[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-100 * BIN7), (SInt16)(-100 * BIN7),
(SInt16)(-100 * BIN7), (SInt16)(-100 * BIN7), (SInt16)(-100 * BIN7),
(SInt16)(-100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVeh_tiCfmSupVSMaxY_A[VSC_8_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-5 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(-0.5 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0.5 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(5 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rCtlTqPotVSMax_T
[VSC_8_SIZE] = {
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(50 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdAJrkVSMaxSatMaxAbsX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(80 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdAJrkVSMaxSatMinAbsX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(80 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdAJrkVSMaxSatMxTra1X_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(90 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGain1VSMaxAVeh_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSMaxSatMnAbsY_A[VSC_16_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-90 * BIN7), (SInt16)(-80 * BIN7),
(SInt16)(-70 * BIN7), (SInt16)(-60 * BIN7), (SInt16)(-50 * BIN7),
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-25 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-2 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSMaxSatMnCftY_A[VSC_16_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-90 * BIN7), (SInt16)(-80 * BIN7),
(SInt16)(-70 * BIN7), (SInt16)(-60 * BIN7), (SInt16)(-50 * BIN7),
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-25 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-2 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSMaxSatMxAbsY_A[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(2 * BIN7),
(SInt16)(5 * BIN7), (SInt16)(10 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(40 * BIN7), (SInt16)(50 * BIN7), (SInt16)(60 * BIN7),
(SInt16)(70 * BIN7), (SInt16)(80 * BIN7), (SInt16)(90 * BIN7),
(SInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSMaxSatMxCftY_A[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(2 * BIN7),
(SInt16)(5 * BIN7), (SInt16)(10 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(40 * BIN7), (SInt16)(50 * BIN7), (SInt16)(60 * BIN7),
(SInt16)(70 * BIN7), (SInt16)(80 * BIN7), (SInt16)(90 * BIN7),
(SInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdESpdCtlGain1VSMaxY_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN7), (SInt16)(0 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(35 * BIN7), (SInt16)(40 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErr_rCtlPotVSMax_A[VSC_8_SIZE] = {
(SInt16)(-10 * BIN7), (SInt16)(0 * BIN7), (SInt16)(10 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(30 * BIN7), (SInt16)(40 * BIN7),
(SInt16)(50 * BIN7), (SInt16)(60 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSMaxSatMaxAbsX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSMaxSatMinAbsX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSMaxSatMinCftX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSMaxSatMxCftX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};


STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehE_tiCfmSdwnVSMaY_A[VSC_8_SIZE] = {
(SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(5 * BIN7), (SInt16)(10 * BIN7),
(SInt16)(15 * BIN7), (SInt16)(20 * BIN7)
};


STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_tiCfmSdwnVSMaxX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(80 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
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
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSMaxReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2), (UInt16)(2 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(2 * DEC2), (UInt16)(2 * DEC2), (UInt16)(2 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) }
};

#define VSMAX_STOP_SEC_CARTO_16BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSMAX_START_SEC_VAR_UNSPECIFIED
#include "VSMax_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsmaxreqsatmaxabs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsmaxreqsatmaxcft_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsmaxreqsatminabs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsmaxreqsatmincft_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_jrkvehvsmaxreqsatmx1tra_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_jrkvehvsmaxsatmaxabs_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsmaxsatmaxcvg_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_jrkvehvsmaxsatminabs_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsmaxsatmincvg_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_rctltqpotvsmax_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_spdctlgain1vsmaxaveh_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsdwnvsmaxreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsupvsmaxreq_m_sav;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsmax_f52232_filter_str;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsmax_f5232_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsmaxh_f5234_filter_1;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsmaxh_f5234_filter_2;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsmaxh_f5234_filter_3;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsmaxh_f5234_filter_4;
#define VSMAX_STOP_SEC_VAR_UNSPECIFIED
#include "VSMax_MemMap.h"


/* 16bit variable definition */
#define VSMAX_START_SEC_VAR_16BIT
#include "VSMax_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsmax_f52232_saturation_prev; /* BIN10 */
STATIC VAR(SInt16, AUTOMATIC) vsmax_f5232_saturation_prev; /* BIN10 */
#define VSMAX_STOP_SEC_VAR_16BIT
#include "VSMax_MemMap.h"

/* 8bit variable definition */
#define VSMAX_START_SEC_VAR_8BIT
#include "VSMax_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsmax_f52232_filter_str_init; /* Enum */
STATIC VAR(UInt8, AUTOMATIC) vsmax_f5232_filter_str_init; /* Enum */
STATIC VAR(UInt8, AUTOMATIC) vsmax_f5234_filter_str_init; /* Enum */
#define VSMAX_STOP_SEC_VAR_8BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
/* <PRQA_COMMENT><3229> variables calculated but not used in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqRaw; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqMax; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqMin; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehPotVSMaxReq; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMax; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxSatMin; /* BIN7 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"




/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSMAX_START_SEC_CONST_UNSPECIFIED
#include "VSMax_MemMap.h"
STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_AVEHVSMAXREQSATMAXABS_M_APM = {
&vsctl_avehvsmaxreqsatmaxabs_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSMaxSatMaxAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSMaxSatMxAbsY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSMaxReqSatMaxAbs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_AVEHVSMAXREQSATMAXCFT_M_APM = {
&vsctl_avehvsmaxreqsatmaxcft_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSMaxSatMxCftX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSMaxSatMxCftY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSMaxReqSatMaxCft_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHVSMAXREQSATMINABS_M_APM = {
&vsctl_avehvsmaxreqsatminabs_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSMaxSatMinAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSMaxSatMnAbsY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSMaxReqSatMinAbs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHVSMAXREQSATMINCFT_M_APM = {
&vsctl_avehvsmaxreqsatmincft_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSMaxSatMinCftX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSMaxSatMnCftY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSMaxReqSatMinCft_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_JRKVEHVSMAXREQSATMX1TRA_M_APM = {
&vsctl_jrkvehvsmaxreqsatmx1tra_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdAJrkVSMaxSatMxTra1X_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSMaxSatMxTra1Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSMaxReqSatMx1Tra_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_JRKVEHVSMAXSATMAXABS_M_APM = {
&vsctl_jrkvehvsmaxsatmaxabs_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdAJrkVSMaxSatMaxAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSMaxSatMaxAbsY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSMaxSatMaxAbs_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_JRKVEHVSMAXSATMAXCVG_T_APM = {
&vsctl_jrkvehvsmaxsatmaxcvg_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSMaxSatMaxCvg_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSMaxSatMaxCvg_T[0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_JRKVEHVSMAXSATMINABS_M_APM = {
&vsctl_jrkvehvsmaxsatminabs_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdAJrkVSMaxSatMinAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSMaxSatMinAbsY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSMaxSatMinAbs_M[0][0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHVSMAXSATMINCVG_T_APM = {
&vsctl_jrkvehvsmaxsatmincvg_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSMaxSatMinCvg_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSMaxSatMinCvg_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RCTLTQPOTVSMAX_T_APM = {
&vsctl_rctltqpotvsmax_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdErr_rCtlPotVSMax_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rCtlTqPotVSMax_T[0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_SPDCTLGAIN1VSMAXAVEH_M_APM = {
&vsctl_spdctlgain1vsmaxaveh_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehSpdCtlGain1VSMaxX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdESpdCtlGain1VSMaxY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdCtlGain1VSMaxAVeh_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_TICFMSDWNVSMAXREQ_M_APM = {
&vsctl_ticfmsdwnvsmaxreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_tiCfmSdwnVSMaxX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVehE_tiCfmSdwnVSMaY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSdwnVSMaxReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_TICFMSUPVSMAXREQ_M_APM = {
&vsctl_ticfmsupvsmaxreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehReq_tiCfmSupVSMaxX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVeh_tiCfmSupVSMaxY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSupVSMaxReq_M[0][0]
};

#define VSMAX_STOP_SEC_CONST_UNSPECIFIED
#include "VSMax_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSMAX_START_SEC_CODE
#include "VSMax_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_swc_inamtype parameter); */




/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : VSMAX_F522221_Determiner_Saturations_Acceleration_Vehicule_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F522221_Determiner_Saturations_Acceleration_Vehicule_Max(
                            SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.20.2 */
    SInt32 sat_max;
    SInt32 map_out_1;
    SInt32 map_out_2;

    /* BIN10: [0; 10] */
    map_out_1 = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_AVEHVSMAXREQSATMAXCFT_M_APM,
                                          VSCtl_spdVehVSMaxReqInt,
                                          VSCtl_spdVehErrVSMax_swc_in);

    /* BIN10: [0; 10] */
    map_out_2 = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_AVEHVSMAXREQSATMAXABS_M_APM,
                                          VSCtl_spdVehVSMaxReqInt,
                                          VSCtl_spdVehErrVSMax_swc_in);

    if ((VSMAX_STCTL_AVEHVSMAX_ARRET != (UInt32)VSCtl_stCtl_aVehVSMax_swc_in) &&
        (VSMAX_STCTL_AVEHVSMAX_TRANSITION != (UInt32)VSCtl_stCtl_aVehVSMax_swc_in) )
    {
        sat_max = DDS_M_MAX((SInt32)VSCtl_aVehPTMax_swc_in, map_out_1);
        VSCtl_aVehVSMaxReqSatMax = (SInt16)DDS_M_MIN(sat_max, map_out_2);

        VSCtl_aVehVSMaxReqSatMaxCft  = (SInt16)map_out_1;
        VSCtl_aVehVSMaxReqSatMaxAbs  = (SInt16)map_out_2;
    }
    else
    {
        VSCtl_aVehVSMaxReqSatMax = (SInt16)VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMaxCft = (SInt16)VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMaxAbs = (SInt16)VSMAX_10_BIN10;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F522222_Determiner_Saturations_Acceleration_Vehicule_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F522222_Determiner_Saturations_Acceleration_Vehicule_Min(
                            SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.21.2 */
    SInt32 sat_max;
    SInt32 map_out_1;
    SInt32 map_out_2;

    /* BIN10: [0; 10] */
    map_out_1 = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHVSMAXREQSATMINCFT_M_APM,
                                          VSCtl_spdVehVSMaxReqInt,
                                          VSCtl_spdVehErrVSMax_swc_in);

    /* BIN10: [0; 10] */
    map_out_2 = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHVSMAXREQSATMINABS_M_APM,
                                          VSCtl_spdVehVSMaxReqInt,
                                          VSCtl_spdVehErrVSMax_swc_in);

    if ((VSMAX_STCTL_AVEHVSMAX_ARRET != (UInt32)VSCtl_stCtl_aVehVSMax_swc_in) &&
        (VSMAX_STCTL_AVEHVSMAX_TRANSITION != (UInt32)VSCtl_stCtl_aVehVSMax_swc_in) )
    {
        sat_max = DDS_M_MIN((SInt32)VSCtl_aVehPTMin_swc_in, map_out_1);
        VSCtl_aVehVSMaxReqSatMin = (SInt16)DDS_M_MAX(sat_max, map_out_2);

        VSCtl_aVehVSMaxReqSatMinCft  = (SInt16)map_out_1;
        VSCtl_aVehVSMaxReqSatMinAbs  = (SInt16)map_out_2;
    }
    else
    {
        VSCtl_aVehVSMaxReqSatMin = (SInt16)-VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMinCft = (SInt16)-VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMinAbs = (SInt16)-VSMAX_10_BIN10;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F52223_Determiner_Saturations_Jerk_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F52223_Determiner_Saturations_Jerk_Vehicule(
                            SInt16 VSCtl_aVehCordVSLimReq_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
/* <PRQA_COMMENT><3206> This parameter is linked to a terminator.</3206></PRQA_COMMENT> */
                            UInt16 VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.22.2 */

    /* Input VSCtl_rTqWhlPTDrvReq is link to a terminator */

    SInt32 sub_sat_max, sub_sat_min;
    SInt32 switch_select_2_in_2,switch_select_2_in_4,switch_select_2_in_5;
    SInt32 div_num;

    /* BIN10[-20;20] = [-10;10] - [-10;10] BIN7 */
    sub_sat_max = (SInt32)VSCtl_aVehReq_swc_in - (SInt32)VSCtl_aVehVSMaxReqSatMax;
    sub_sat_min = (SInt32)VSCtl_aVehReq_swc_in - (SInt32)VSCtl_aVehVSMaxReqSatMin;

    if((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == VSMAX_STCTL_AVEHVSMAX_CONTROLE)
    {
        /* BIN7[0;100] */
        VSCtl_jrkVehVSMaxSatMaxCvg = (SInt16)DDS_M_MAP2D_SU16(&VSCTL_JRKVEHVSMAXSATMAXCVG_T_APM,
                                                       (SInt16)sub_sat_max);

        /* BIN7[0;100] */
        VSCtl_jrkVehVSMaxSatMaxAbs = (SInt16)DDS_M_MAP3D_USU16(&VSCTL_JRKVEHVSMAXSATMAXABS_M_APM,
                                                         VSCtl_spdVeh_swc_in,
                                                         VSCtl_aVehReq_swc_in);

        /* BIN7[0;100] */
        VSCtl_jrkVehVSMaxSatMax = (SInt16)DDS_M_MIN((SInt32)VSCtl_jrkVehVSMaxSatMaxCvg,(SInt32)VSCtl_jrkVehVSMaxSatMaxAbs);

        VSCtl_jrkVehVSMaxSatMax1Tran = (SInt16)VSMAX_100_BIN7;

        VSCtl_jrkVehVSMaxSatMaxCrit = (SInt16)VSMAX_100_BIN7;

        /* BIN7[-100; 0] */
        VSCtl_jrkVehVSMaxSatMinAbs = DDS_M_MAP3D_USS16(&VSCTL_JRKVEHVSMAXSATMINABS_M_APM,
                                                     VSCtl_spdVeh_swc_in,
                                                     VSCtl_aVehReq_swc_in);

        /* BIN7[-100;0] */
        VSCtl_jrkVehVSMaxSatMinCvg = DDS_M_MAP2D_S16(&VSCTL_JRKVEHVSMAXSATMINCVG_T_APM,
                                                   (SInt16)sub_sat_min);

        /* BIN7[-100;0] */
        VSCtl_jrkVehVSMaxSatMin = (SInt16)DDS_M_MAX((SInt32)VSCtl_jrkVehVSMaxSatMinAbs,(SInt32)VSCtl_jrkVehVSMaxSatMinCvg);
    }
    else if((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == VSMAX_STCTL_AVEHVSMAX_TRANSITION)
    {
        /* BIN7[0;100] */
        switch_select_2_in_4 = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_JRKVEHVSMAXREQSATMX1TRA_M_APM,
                                                         VSCtl_spdVeh_swc_in,
                                                         VSCtl_aVehReq_swc_in);

        /* BIN10: [-20; 20] */
        div_num = (SInt32)VSCtl_aVehCordVSLimReq_swc_in - (SInt32)VSCtl_aVehReq_swc_in;

        if(0 == div_num)
        {
            switch_select_2_in_5 = 0 * BIN7;  /* Min value */
        }
        else if(0 == (UInt32)VSCtl_tiFilStCtlAVehVSMax)  /* DEC0 */
        {
            if( div_num > 0)
            {
                switch_select_2_in_5 = (SInt32)VSMAX_100_BIN7;  /* Max value */
            }
            else
            {
                switch_select_2_in_5 = -(SInt32)VSMAX_100_BIN7;  /* Min value */
            }
        }
        else
        {
            /* [-500; 500] = [-20; 20] * 1000 / [0; 255] * 40 */
            /* BIN10 = BIN10 / DEC0 */
            switch_select_2_in_5 = (div_num * DEC3) / ((SInt32)VSCtl_tiFilStCtlAVehVSMax * (SInt32)VSMAX_SCHEDULING);
            /* [-100; 100] BIN7 */
            switch_select_2_in_5 = switch_select_2_in_5 / BIN3;
            switch_select_2_in_5 = DDS_M_LIMIT(switch_select_2_in_5, -(SInt32)VSMAX_100_BIN7, (SInt32)VSMAX_100_BIN7);
        }

        if((UInt32)DDS_TRUE != (UInt32)VSCtl_bAcvJrkSatMnCritVSMax_C)
        {
            switch_select_2_in_2 = switch_select_2_in_4;
        }
        else
        {
            switch_select_2_in_2 = DDS_M_MAX(switch_select_2_in_4,switch_select_2_in_5);
        }

        VSCtl_jrkVehVSMaxSatMaxCvg   = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMax      = (SInt16)(switch_select_2_in_2);
        VSCtl_jrkVehVSMaxSatMaxAbs   = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMax1Tran = (SInt16)(switch_select_2_in_4);
        VSCtl_jrkVehVSMaxSatMaxCrit  = (SInt16)(switch_select_2_in_5);
        VSCtl_jrkVehVSMaxSatMinAbs   = (SInt16)-VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMin      = (SInt16)-VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMinCvg   = (SInt16)-VSMAX_100_BIN7;
    }
    else
    { /* VSMAX_STCTL_AVEHVSMAX_ARRET: */
        VSCtl_jrkVehVSMaxSatMaxCvg   = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMax      = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMaxAbs   = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMax1Tran = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMaxCrit  = (SInt16)VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMinAbs   = (SInt16)-VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMin      = (SInt16)-VSMAX_100_BIN7;
        VSCtl_jrkVehVSMaxSatMinCvg   = (SInt16)-VSMAX_100_BIN7;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F52224_Determiner_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F52224_Determiner_Gabarits_Acceleration_Vehicule(
                            SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in /* Enum */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.59.0 */
    SInt32 vsctl_avehvsmaxreqsatmaxapl_loc;
    SInt32 vsctl_avehvsminreqsatmaxapl_loc;
    SInt32 vsmax_svalue_max;
    SInt32 vsmax_svalue_min;


    /* m/s2 = m/s2 + ((m/s3) * scheduling) */
    /* scheduling is in ms but we need s. So we divide it by 1000*/
    /* [-14;14] = [-10;10] + ([-100;100] * 40/1000) */
    /* BIN10 = BIN10 + (BIN7 * BIN3 * 40/1000) */
    vsmax_svalue_max = (SInt32)VSCtl_aVehReq_swc_in + (((SInt32)VSCtl_jrkVehVSMaxSatMax * (BIN3 * (SInt32)VSMAX_SCHEDULING)) / DEC3);
    vsmax_svalue_min = (SInt32)VSCtl_aVehReq_swc_in + (((SInt32)VSCtl_jrkVehVSMaxSatMin * (BIN3 * (SInt32)VSMAX_SCHEDULING)) / DEC3);


    switch((UInt32)VSCtl_stSatAVehMinVSMax)
    {
        case (UInt32)VSMAX_STSATAVEHMINVSMAX_INIT:
            vsctl_avehvsmaxreqsatmaxapl_loc = (SInt32)VSCtl_aVehPTMax_swc_in;
            vsctl_avehvsminreqsatmaxapl_loc = (SInt32)VSCtl_aVehPTMin_swc_in;
            break;
        case (UInt32)VSMAX_STSATAVEHMINVSMAX_NON_EFFECTIF:
            vsctl_avehvsmaxreqsatmaxapl_loc = (SInt32)VSCtl_aVehPTMax_swc_in;
            vsctl_avehvsminreqsatmaxapl_loc = (SInt32)VSCtl_aVehPTMin_swc_in;
            break;
        case (UInt32)VSMAX_STSATAVEHMINVSMAX_EFFECTIF:
            vsctl_avehvsmaxreqsatmaxapl_loc = DDS_M_MIN((SInt32)VSCtl_aVehPTMax_swc_in,(SInt32)VSCtl_aVehVSMaxReqSatMax);
            vsctl_avehvsminreqsatmaxapl_loc = DDS_M_MAX((SInt32)VSCtl_aVehPTMin_swc_in,(SInt32)VSCtl_aVehVSMaxReqSatMin);
            break;
        case (UInt32)VSMAX_STSATAVEHMINVSMAX_ACTIVATION:
            vsctl_avehvsmaxreqsatmaxapl_loc = DDS_M_MIN((SInt32)VSCtl_aVehPTMax_swc_in,(SInt32)VSCtl_aVehReq_swc_in);
            vsctl_avehvsminreqsatmaxapl_loc = (SInt32)VSCtl_aVehPTMin_swc_in;
            break;
        case (UInt32)VSMAX_STSATAVEHMINVSMAX_ARRET:
        default:
            vsctl_avehvsmaxreqsatmaxapl_loc = VSMAX_10_BIN10;
            vsctl_avehvsminreqsatmaxapl_loc = -VSMAX_10_BIN10;
            break;
    }

    if(VSMAX_STCTL_AVEHVSMAX_CONTROLE == (UInt32)VSCtl_stCtl_aVehVSMax_swc_in)
    {
        if(VSCTL_STSATJRKVEHMAXVSMAX_NON_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMaxVSMax)
        {
            VSCtl_aVehVSMaxReqMax = (SInt16)vsctl_avehvsmaxreqsatmaxapl_loc;
        }
        else if(VSCTL_STSATJRKVEHMAXVSMAX_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMaxVSMax)
        {
            VSCtl_aVehVSMaxReqMax = (SInt16)DDS_M_SATURATION_V1(vsmax_svalue_max,vsctl_avehvsminreqsatmaxapl_loc,vsctl_avehvsmaxreqsatmaxapl_loc);
        }
        else
        { /* VSMAX_STSATJRKVEHMAXVSMAX_ARRET */
            VSCtl_aVehVSMaxReqMax = (SInt16)VSMAX_10_BIN10;
        }

        if(VSCTL_STSATJRKVEHMINVSMAX_NON_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMinVSMax)
        {
            VSCtl_aVehVSMaxReqMin = (SInt16)vsctl_avehvsminreqsatmaxapl_loc;
        }
        else if(VSCTL_STSATJRKVEHMINVSMAX_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMinVSMax)
        {
            VSCtl_aVehVSMaxReqMin = (SInt16)DDS_M_SATURATION_V1(vsmax_svalue_min,vsctl_avehvsminreqsatmaxapl_loc,vsctl_avehvsmaxreqsatmaxapl_loc);
        }
        else
        { /* VSMAX_STSATJRKVEHMINVSMAX_ARRET */
            VSCtl_aVehVSMaxReqMin = (SInt16)-VSMAX_10_BIN10;
        }

        VSCtl_aVehVSMaxReqSatMaxApl = (SInt16)vsctl_avehvsmaxreqsatmaxapl_loc;
        VSCtl_aVehVSMaxReqSatMinApl = (SInt16)vsctl_avehvsminreqsatmaxapl_loc;
    }
    else if(VSCTL_STCTL_AVEHVSMAX_TRANSITION == (UInt32)VSCtl_stCtl_aVehVSMax_swc_in)
    {
        VSCtl_aVehVSMaxReqMax = (SInt16)DDS_M_LIMIT(vsmax_svalue_max,-VSMAX_10_BIN10,VSMAX_10_BIN10);
        VSCtl_aVehVSMaxReqMin = (SInt16)-VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMaxApl = (SInt16)vsctl_avehvsmaxreqsatmaxapl_loc;
        VSCtl_aVehVSMaxReqSatMinApl = (SInt16)vsctl_avehvsminreqsatmaxapl_loc;
    }
    else
    { /* VSMAX_STCTL_AVEHVSMAX_ARRET: */
        VSCtl_aVehVSMaxReqMax = (SInt16)VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqMin = (SInt16)-VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMaxApl = (SInt16)VSMAX_10_BIN10;
        VSCtl_aVehVSMaxReqSatMinApl = (SInt16)-VSMAX_10_BIN10;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F52232_Determiner_Consigne_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F52232_Determiner_Consigne_Acceleration_Vehicule(
                            SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            UInt8 VSCtl_stCtl_aVehVSMax_swc_in, /* Enum */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_swc_out /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.61.0 */
    SInt32 vsmax_svalue_1;
    SInt32 vsmax_svalue_2;
    UInt32 vsmax_uvalue;
    SInt32 vsmax_barycentre_output;
    UInt16 vsmax_map_output;
    SInt32 vsmax_filter_output;

    /* BIN7: [0;10] */
    vsmax_map_output = DDS_M_MAP3D_SSU16(&VSCTL_SPDCTLGAIN1VSMAXAVEH_M_APM,VSCtl_aVehPTMax_swc_in,VSCtl_spdVehErrVSMax_swc_in);

    /* Barycentre calculation */
    /* input 1 = map_output * VSCtl_spdVehErrVSMax / 3.6 */
    /* BIN10 = BIN7 * BIN7 / (3.6 * BIN4) */
    /* BIN10 = BIN7 * BIN7 * 5 / (18 * BIN4) */
    /* m/s2 = 1/s * km/h / 3.6 */
    /* [-709,709] = [0;10] * [-255;255] / 3.6 */
    vsmax_svalue_1 = (((SInt32)vsmax_map_output * (SInt32)VSCtl_spdVehErrVSMax_swc_in) * 5) / (18 * BIN4);

    /* input 2 = VSCtl_spdCtlGain2VSMaxAVeh_C * VSCtl_spdVehErrVSMax / 3.6 */
    /* BIN10 = BIN7 * BIN7 / (3.6 * BIN4) */
    /* BIN10 = BIN7 * BIN7 * 5 / (18 * BIN4) */
    /* m/s2 = 1/s * km/h / 3.6 */
    /* [-709,709] = [0;10] * [-255;255] / 3.6 */
    vsmax_svalue_2 = (((SInt32)VSCtl_spdCtlGain2VSMaxAVeh_C * (SInt32)VSCtl_spdVehErrVSMax_swc_in) * 5) / (18 * BIN4);
    vsmax_svalue_2 = DDS_M_SATURATION_V2(vsmax_svalue_2,(SInt32)VSCtl_aVehVSMaxDynStbMin_C,(SInt32)VSCtl_aVehVSMaxDynStbMax_C);

    vsmax_barycentre_output = DDS_M_BARY_FILTER_S32(vsmax_svalue_1,vsmax_svalue_2,VSCtl_rSpdVehCtlVSMaxDyn,(UInt16)VSMAX_100_BIN7);

    /* filter calculation */
    if((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == VSMAX_STCTL_AVEHVSMAX_CONTROLE)
    {
        vsmax_svalue_1 = vsmax_barycentre_output;
    }
    else
    {
        vsmax_svalue_1 = VSMAX_10_BIN10;
    }
    /* BIN10: [-10;10] m/s2 */
    vsmax_svalue_1 = DDS_M_SATURATION_V2(vsmax_svalue_1,(SInt32)VSCtl_aVehVSMaxReqMin,(SInt32)VSCtl_aVehVSMaxReqMax);
    /* BIN10: [-20;20] m/s2 */
    vsmax_svalue_2 = vsmax_svalue_1 - (SInt32)vsmax_f52232_saturation_prev;
    vsmax_f52232_saturation_prev = (SInt16)vsmax_svalue_1;

    /* m/s3 = m/s2 / scheduling */
    /* scheduling = 40ms = (40/1000) s*/
    /* BIN10: [-500;500] m/s3 */
    vsmax_svalue_2 = (vsmax_svalue_2 * DEC3)/ (SInt32)VSMAX_SCHEDULING;

    if(  ((UInt32)VSCtl_bAcvFil_aVehVSMax != (UInt32)DDS_FALSE)
       &&((UInt32)vsmax_f52232_filter_str_init != (UInt32)DDS_FALSE))
    {
        vsmax_uvalue = (UInt32)VSCtl_tiFil_jrkVehVSMaxRq_C * BIN5;
        vsmax_filter_output = DDS_M_FILTER_LP1_S32(&vsmax_f52232_filter_str,vsmax_svalue_2,(UInt16)vsmax_uvalue);
    }
    else
    {
        vsmax_f52232_filter_str_init = DDS_TRUE;
        vsmax_filter_output = DDS_M_FILTER_LP1_S32_INIT(&vsmax_f52232_filter_str,vsmax_svalue_2);
    }

    if(  ((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == VSMAX_STCTL_AVEHVSMAX_CONTROLE)
       ||((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == VSMAX_STCTL_AVEHVSMAX_TRANSITION))
    {
        VSCtl_spdCtlGain1VSMaxAVeh = vsmax_map_output;
        *VSCtl_aVehVSMaxReq_swc_out = (SInt16)vsmax_svalue_1;
        vsmax_filter_output = vsmax_filter_output / BIN3;
        VSCtl_jrkVehVSMaxReq = (SInt16)DDS_M_LIMIT(vsmax_filter_output,-VSMAX_100_BIN7,VSMAX_100_BIN7);
        VSCtl_aVehVSMaxReqRaw = (SInt16)DDS_M_LIMIT(vsmax_barycentre_output,-VSMAX_10_BIN10,VSMAX_10_BIN10);
    }
    else
    {
        VSCtl_spdCtlGain1VSMaxAVeh = (UInt16)VSMAX_1_BIN7;
        *VSCtl_aVehVSMaxReq_swc_out = (SInt16)VSMAX_10_BIN10;
        VSCtl_jrkVehVSMaxReq = (SInt16)VSMAX_0;
        VSCtl_aVehVSMaxReqRaw = (SInt16)VSMAX_10_BIN10;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                            UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in, /* Enum */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSMaxReq_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.62.0 */
    SInt32 vsmax_svalue_1;
    SInt32 vsmax_svalue_2;
    SInt32 vsmax_filter_output;
    UInt32 vsmax_uvalue;

    /* input_tmp 2 = VSCtl_spdCtlGainVSMaxAVehPot_C * VSCtl_spdVehErrVSMax / 3.6 */
    /* BIN10 = BIN7 * BIN7 / (3.6 * BIN4) */
    /* BIN10 = BIN7 * BIN7 * 5 / (18 * BIN4) */
    /* m/s2 = 1/s * km/h / 3.6 */
    /* [-709,709] = [0;10] * [-255;255] / 3.6 */
    vsmax_svalue_1 = (((SInt32)VSCtl_spdCtlGainVSMaxAVehPot_C * (SInt32)VSCtl_spdVehErrVSMax_swc_in) * 5) / (18 * BIN4);

    /* BIN10: [-10;10] m/s2 */
    vsmax_svalue_1 = DDS_M_SATURATION_V2(vsmax_svalue_1,(SInt32)VSCtl_aVehVSMaxReqSatMin,(SInt32)VSCtl_aVehVSMaxReqSatMax);
    /* BIN10: [-20;20] m/s2 */
    vsmax_svalue_2 = vsmax_svalue_1 - (SInt32)vsmax_f5232_saturation_prev;
    vsmax_f5232_saturation_prev = (SInt16)vsmax_svalue_1;

    /* m/s3 = m/s2 / scheduling */
    /* scheduling = 40ms = (40/1000) s*/
    /* BIN10: [-500;500] m/s3 */
    vsmax_svalue_2 = (vsmax_svalue_2 * DEC3)/ (SInt32)VSMAX_SCHEDULING;

    if(  ((UInt32)VSCtl_bAcvFil_aVehPotVSMax != (UInt32)DDS_FALSE)
       &&((UInt32)vsmax_f5232_filter_str_init != (UInt32)DDS_FALSE))
    {
        vsmax_uvalue =(UInt32)VSCtl_tiFil_jrkVehPotVSMaxRq_C * BIN5;
        vsmax_filter_output = DDS_M_FILTER_LP1_S32(&vsmax_f5232_filter_str,vsmax_svalue_2,(UInt16)vsmax_uvalue);
    }
    else
    {
        vsmax_f5232_filter_str_init = DDS_TRUE;
        vsmax_filter_output = DDS_M_FILTER_LP1_S32_INIT(&vsmax_f5232_filter_str,vsmax_svalue_2);
    }

    if((UInt32)VSCtl_bCtl_aVehPotVSMax_swc_in == (UInt32)DDS_TRUE)
    {
        *VSCtl_aVehPotVSMaxReq_swc_out = vsmax_f5232_saturation_prev;
        vsmax_filter_output = vsmax_filter_output / BIN3;
        VSCtl_jrkVehPotVSMaxReq = (SInt16)DDS_M_LIMIT(vsmax_filter_output,-VSMAX_100_BIN7,VSMAX_100_BIN7);
    }
    else
    {
        *VSCtl_aVehPotVSMaxReq_swc_out = (SInt16)VSMAX_10_BIN10;
        VSCtl_jrkVehPotVSMaxReq = (SInt16)VSMAX_0;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp(
                            UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in, /* Enum */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSMax_swc_out /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.31.1 */
    if((UInt32)DDS_TRUE != (UInt32)VSCtl_bCtl_aVehPotVSMax_swc_in)
    {
        *VSCtl_rCtlTqWhlPTPotVSMax_swc_out = (UInt16)VSMAX_0;
    }
    else
    {
        *VSCtl_rCtlTqWhlPTPotVSMax_swc_out = DDS_M_MAP2D_SU16(&VSCTL_RCTLTQPOTVSMAX_T_APM, VSCtl_spdVehErrVSMax_swc_in);
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5234_Determiner_Temps_Confirmation_Changement_Rapport
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5234_Determiner_Temps_Confirmation_Changement_Rapport(
                            SInt16 VSCtl_aVehPotVSMaxReq_swc_in, /* BIN10 */
                            UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in, /* Enum */
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            SInt16 VSCtl_spdVehErrVSMax_swc_in, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReq_swc_out, /* DEC2 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSMaxReq_swc_out /* DEC2 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.32.1 */

    UInt16 map_out_1, map_out_2;
    UInt16 filter_out_1, filter_out_2, filter_out_3, filter_out_4;

    /* [0; 16] DEC2 */
    map_out_1 = DDS_M_MAP3D_SSU16(&VSCTL_TICFMSUPVSMAXREQ_M_APM,
                                  VSCtl_aVehPotVSMaxReq_swc_in,
                                  VSCtl_jrkVehPotVSMaxReq);
    /* [0; 16] DEC2 */
    map_out_2 = DDS_M_MAP3D_USU16(&VSCTL_TICFMSDWNVSMAXREQ_M_APM,
                                  VSCtl_spdVeh_swc_in,
                                  VSCtl_spdVehErrVSMax_swc_in);

    if(  ((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvFil_aVehPotVSMax)
       &&((UInt32)DDS_FALSE != (UInt32)vsmax_f5234_filter_str_init))
    {
        filter_out_1 = DDS_M_FILTER_LP1_U16(&vsmaxh_f5234_filter_1,
                                            map_out_1,
                                            (UInt16)VSCtl_tiFil_tiCfmSupVSMaxRq1_C,
                                            BIN7);

        filter_out_2 = DDS_M_FILTER_LP1_U16(&vsmaxh_f5234_filter_2,
                                            map_out_1,
                                            (UInt16)VSCtl_tiFil_tiCfmSupVSMaxRq2_C,
                                            BIN7);

        filter_out_3 = DDS_M_FILTER_LP1_U16(&vsmaxh_f5234_filter_3,
                                            map_out_2,
                                            (UInt16)VSCtl_tiFil_tiCfmSdwnVSMxRq1_C,
                                            BIN7);

        filter_out_4 = DDS_M_FILTER_LP1_U16(&vsmaxh_f5234_filter_4,
                                            map_out_2,
                                            (UInt16)VSCtl_tiFil_tiCfmSdwnVSMxRq2_C,
                                            BIN7);
    }
    else
    {
        vsmax_f5234_filter_str_init = DDS_TRUE;
        filter_out_1 = DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_1, VSCtl_tiCfmSupVSMaxReqIni_C);
        filter_out_2 = DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_2, VSCtl_tiCfmSupVSMaxReqIni_C);
        filter_out_3 = DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_3, VSCtl_tiCfmSdwnVSMaxReqIni_C);
        filter_out_4 = DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_4, VSCtl_tiCfmSdwnVSMaxReqIni_C);
    }

    if((UInt32)DDS_TRUE == (UInt32)VSCtl_bCtl_aVehPotVSMax_swc_in)
    {
        VSCtl_tiCfmSupVSMaxReqRaw1 = map_out_1;
        VSCtl_tiCfmSupVSMaxReqRaw2 = filter_out_1;
        *VSCtl_tiCfmSupVSMaxReq_swc_out = (UInt16)DDS_M_MAX((UInt32)filter_out_1, (UInt32)filter_out_2);
        VSCtl_tiCfmSupVSMaxReqRaw3 = filter_out_2;

        VSCtl_tiCfmSdwnVSMaxReqRaw1 = map_out_2;
        VSCtl_tiCfmSdwnVSMaxReqRaw2 = filter_out_3;
        *VSCtl_tiCfmSdwnVSMaxReq_swc_out = (UInt16)DDS_M_MAX((UInt32)filter_out_3, (UInt32)filter_out_4);
        VSCtl_tiCfmSdwnVSMaxReqRaw3 = filter_out_4;
    }
    else
    {
        VSCtl_tiCfmSupVSMaxReqRaw1 = (UInt16)VSMAX_0;
        VSCtl_tiCfmSupVSMaxReqRaw2 = (UInt16)VSMAX_0;
        *VSCtl_tiCfmSupVSMaxReq_swc_out = (UInt16)VSMAX_0;
        VSCtl_tiCfmSupVSMaxReqRaw3 = (UInt16)VSMAX_0;

        VSCtl_tiCfmSdwnVSMaxReqRaw1 = (UInt16)VSMAX_0;
        VSCtl_tiCfmSdwnVSMaxReqRaw2 = (UInt16)VSMAX_0;
        *VSCtl_tiCfmSdwnVSMaxReq_swc_out = (UInt16)VSMAX_0;
        VSCtl_tiCfmSdwnVSMaxReqRaw3 = (UInt16)VSMAX_0;
    }
}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSMAX_Simulink_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_Veh_Acc_Ctrl_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSMaxReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSMax_swc_out, /* BIN4 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSMaxReq_swc_out, /* DEC2 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSMaxReq_swc_out /* DEC2 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_aVehPotVSMaxReq_swc_out = (SInt16)VSMAX_10_BIN10;
    *VSCtl_aVehVSMaxReq_swc_out = (SInt16)VSMAX_10_BIN10;

    *VSCtl_rCtlTqWhlPTPotVSMax_swc_out = (UInt16)VSMAX_0;
    *VSCtl_tiCfmSdwnVSMaxReq_swc_out = (UInt16)VSMAX_0;
    *VSCtl_tiCfmSupVSMaxReq_swc_out = (UInt16)VSMAX_0;

    /* ---- Init Output to others files Datas ---- */
    VSCtl_aVehVSMaxReqMax = (SInt16)(10 * BIN10);
    VSCtl_aVehVSMaxReqMin = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSMaxReqRaw = (SInt16)(0 * BIN10);
    VSCtl_aVehVSMaxReqSatMax = (SInt16)(10 * BIN10);
    VSCtl_aVehVSMaxReqSatMaxAbs = (SInt16)(10 * BIN10);
    VSCtl_aVehVSMaxReqSatMaxApl = (SInt16)(10 * BIN10);
    VSCtl_aVehVSMaxReqSatMaxCft = (SInt16)(10 * BIN10);
    VSCtl_aVehVSMaxReqSatMin = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSMaxReqSatMinAbs = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSMaxReqSatMinApl = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSMaxReqSatMinCft = (SInt16)(-10 * BIN10);

    VSCtl_jrkVehVSMaxReq = (SInt16)(0 * BIN7);
    VSCtl_jrkVehVSMaxSatMax1Tran = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSMaxSatMax = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSMaxSatMaxAbs = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSMaxSatMaxCrit = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSMaxSatMaxCvg = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSMaxSatMin = (SInt16)(-100 * BIN7);
    VSCtl_jrkVehVSMaxSatMinAbs = (SInt16)(-100 * BIN7);
    VSCtl_jrkVehVSMaxSatMinCvg = (SInt16)(-100 * BIN7);
    VSCtl_spdCtlGain1VSMaxAVeh = (UInt16)(0 * BIN7);

    VSCtl_tiCfmSdwnVSMaxReqRaw1 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSdwnVSMaxReqRaw2 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSdwnVSMaxReqRaw3 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupVSMaxReqRaw1 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupVSMaxReqRaw2 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupVSMaxReqRaw3 = (UInt16)(0 * DEC2);

    VSCtl_jrkVehPotVSMaxReq = (SInt16)(0 * BIN7);


    /* ---- VSMAX_F522221_Determiner_Saturations_Acceleration_Vehicule_Max ---- */

    /* ---- VSMAX_F522222_Determiner_Saturations_Acceleration_Vehicule_Min ---- */

    /* ---- VSMAX_F52223_Determiner_Saturations_Jerk_Vehicule ---- */

    /* ---- VSMAX_F52224_Determiner_Gabarits_Acceleration_Vehicule ---- */

    /* ---- VSMAX_F52232_Determiner_Consigne_Acceleration_Vehicule ---- */
    vsmax_f52232_saturation_prev = 0; /* BIN10 */
    vsmax_f52232_filter_str_init = DDS_FALSE; /* Enum */
    DDS_M_FILTER_LP1_S32_INIT(&vsmax_f52232_filter_str,0);

    /* ---- VSMAX_F5232_Determiner_Consigne_Potentiel_Acceleration_Vehicule ---- */
    vsmax_f5232_saturation_prev = 0; /* BIN10 */
    vsmax_f5232_filter_str_init = DDS_FALSE; /* Enum */
    DDS_M_FILTER_LP1_S32_INIT(&vsmax_f5232_filter_str,0);

    /* ---- VSMAX_F5233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp ---- */

    /* ---- VSMAX_F5234_Determiner_Temps_Confirmation_Changement_Rapport ---- */
    vsmax_f5234_filter_str_init = DDS_FALSE; /* Enum */
    DDS_M_FILTER_LP1_S32_INIT(&vsmax_f5232_filter_str,0);
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_1, 0);
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_2, 0);
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_3, 0);
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsmaxh_f5234_filter_4, 0);
}

#define VSMAX_STOP_SEC_CODE
#include "VSMax_MemMap.h"

