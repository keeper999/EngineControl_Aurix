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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Veh_Speed_Control_Sl.c
* Version int :/main/L02_01/2 Date: 6/1/2012 9 h 15 m User:esnault 
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL2
*    comments :Calibrations values update for VSReg_12_0_e6
*    comments :Calibrations values update for VSReg_12_0_e6
* Version dev :\main\branch_halouane_vsreg_euro6\1 Date: 5/1/2012 17 h 9 m User:halouane 
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL2
*    comments :Calibrations values update for VSReg_12_0_e6
*
*******************************************************************************/

/* Version dev :\main\branch_demezil_vsreg_view\5 Date: 28/11/2011 11 h 5 m User:demezil
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0: correction following TU report
* Version dev :\main\branch_demezil_vsreg_view\4 Date: 21/11/2011 10 h 38 m User:demezil
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\3 Date: 14/11/2011 15 h 49 m User:demezil
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 14/11/2011 15 h 41 m User:demezil
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 14/11/2011 15 h 38 m User:demezil
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version int :/main/L01_01/3 Date: 17/5/2011 14 h 35 m User:esnault
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1_D
*    comments :Correct failt code on VSCtl_aVehVSRegReqRaw calculation
* Version dev :\main\branch_moisan_module_dev\1 Date: 12/5/2011 9 h 33 m User:moisan
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1_D
*    comments :Correct failt code on VSCtl_aVehVSRegReqRaw calculation
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 29/4/2011 11 h 4 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1_D
*    comments :UT correction
* Version int :/main/L01_01/2 Date: 11/2/2011 12 h 48 m User:esnault
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_xvv_vsreg\7 Date: 11/2/2011 9 h 7 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_xvv_vsreg\6 Date: 11/2/2011 9 h 2 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\5 Date: 10/2/2011 14 h 53 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version int :/main/L01_01/1 Date: 28/1/2011 10 h 26 m User:esnault
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\4 Date: 27/1/2011 15 h 48 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\3 Date: 22/12/2010 16 h 29 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :remove useless RUN_OUT
* Version dev :\main\branch_morisseau_xvv_vsreg\2 Date: 20/12/2010 14 h 32 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :first version for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 17/12/2010 10 h 43 m User:morisseau
*    TWK_model:VSREG_Veh_Speed_Control_Sl_L01_010_IMPL1
*    comments :add model to file
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSReg.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define VSC_16_SIZE                           16
#define VSC_8_SIZE                            8

#define VSREG_0                               0
#define VSREG_10_BIN10                        (10 * BIN10)
#define VSREG_100_BIN7                        (100 * BIN7)
#define VSREG_255_BIN7                        (255 * BIN7)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_rSpdVehCtlVSRegDyn; /* BIN7 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"

/* 8-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stFilSpdVehVSReg; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilSpdVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_stSatMaxSpdVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_stSatJrkVehMinVSReg; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_tiFilStCtlAVehVSReg; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stSatAVehMinVSReg; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvCtlAVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehPotVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDynCtlSpdVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_no2;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



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

/* 16-bits  variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMin; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegReq; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSRegReqFil; /* BIN7 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSREG_START_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehMinSpdVehVSRegReq_C = (CONST(UInt16, AUTOMATIC))(2.3134765625 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehMaxSpdVehVSRegReq_C = (CONST(UInt16, AUTOMATIC))(2.3134765625 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no1_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no2_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no3_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no4_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no5_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no6_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no7_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSRegSatMax_no8_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGainVSRegAVehPot_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVehPotVSRegRq_C = (CONST(UInt16, AUTOMATIC))(0.286 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSRegReqIni_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReqIni_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGain1VSRegAVeh_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdCtlGain2VSRegAVeh_C = (CONST(UInt16, AUTOMATIC))(0.5 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSRegDynStbMax_C = (CONST(UInt16, AUTOMATIC))(0.125 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSRegDynStbMin_C = (CONST(SInt16, AUTOMATIC))(-0.125 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_jrkVehVSRegRq_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
#define VSREG_STOP_SEC_CALIB_16BIT
#include "VSReg_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvJrkSatMnCritVSReg_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvInitAVehVSReg_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSupVSRegRq1_C = (CONST(UInt8, AUTOMATIC))(0.203125 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSupVSRegRq2_C = (CONST(UInt8, AUTOMATIC))(0.0390625 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSdwnVSRegR1_C = (CONST(UInt8, AUTOMATIC))(0.203125 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_tiCfmSdwnVSRegR2_C = (CONST(UInt8, AUTOMATIC))(0.0390625 * BIN7);
#define VSREG_STOP_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSREG_START_SEC_CARTO_16BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSRegSatMaxAbs_A[VSC_16_SIZE] = {
(SInt16)(-1 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.599609375 * BIN10), (SInt16)(-0.400390625 * BIN10),
(SInt16)(-0.2001953125 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0.2001953125 * BIN10), (SInt16)(0.599609375 * BIN10),
(SInt16)(1 * BIN10), (SInt16)(2.099609375 * BIN10),
(SInt16)(2.2001953125 * BIN10), (SInt16)(2.2998046875 * BIN10),
(SInt16)(2.400390625 * BIN10), (SInt16)(2.5 * BIN10), (SInt16)(3 * BIN10),
(SInt16)(3.5 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSRegSatMaxCvg_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-5 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.400390625 * BIN10), (SInt16)(-0.2998046875 * BIN10),
(SInt16)(-0.2001953125 * BIN10), (SInt16)(-0.099609375 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.099609375 * BIN10),
(SInt16)(0.2001953125 * BIN10), (SInt16)(0.2998046875 * BIN10),
(SInt16)(0.400390625 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(5 * BIN10),
(SInt16)(6 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSRegSatMinAbs_A[VSC_16_SIZE] = {
(SInt16)(-1 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.599609375 * BIN10), (SInt16)(-0.2001953125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.400390625 * BIN10),
(SInt16)(0.599609375 * BIN10), (SInt16)(0.7998046875 * BIN10),
(SInt16)(1 * BIN10), (SInt16)(1.2001953125 * BIN10), (SInt16)(1.5 * BIN10),
(SInt16)(1.7998046875 * BIN10), (SInt16)(2 * BIN10),
(SInt16)(2.2998046875 * BIN10), (SInt16)(2.5 * BIN10), (SInt16)(3 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSRegSatMinCvg_A[VSC_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-5 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.400390625 * BIN10), (SInt16)(-0.2998046875 * BIN10),
(SInt16)(-0.2001953125 * BIN10), (SInt16)(-0.099609375 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.099609375 * BIN10),
(SInt16)(0.2001953125 * BIN10), (SInt16)(0.2998046875 * BIN10),
(SInt16)(0.400390625 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(5 * BIN10),
(SInt16)(6 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aJrkVehVSRegSatMnTran_A[VSC_16_SIZE] = {
(SInt16)(-1 * BIN10), (SInt16)(-0.7998046875 * BIN10),
(SInt16)(-0.599609375 * BIN10), (SInt16)(-0.2001953125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.400390625 * BIN10),
(SInt16)(0.599609375 * BIN10), (SInt16)(0.7998046875 * BIN10),
(SInt16)(1 * BIN10), (SInt16)(1.2001953125 * BIN10), (SInt16)(1.5 * BIN10),
(SInt16)(1.7998046875 * BIN10), (SInt16)(2 * BIN10),
(SInt16)(2.2998046875 * BIN10), (SInt16)(2.599609375 * BIN10),
(SInt16)(3 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehPotOftVSRegReq_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehRq_tiCfmSupStVSRegX_A[VSC_8_SIZE] = {
(SInt16)(-3.5 * BIN10), (SInt16)(-1.25 * BIN10),
(SInt16)(-0.400390625 * BIN10), (SInt16)(-0.2001953125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.2001953125 * BIN10),
(SInt16)(0.400390625 * BIN10), (SInt16)(1.25 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehRq_tiCfmSupTrVSRegX_A[VSC_8_SIZE] = {
(SInt16)(-3.5 * BIN10), (SInt16)(-1.25 * BIN10),
(SInt16)(-0.400390625 * BIN10), (SInt16)(-0.2001953125 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.2001953125 * BIN10),
(SInt16)(0.400390625 * BIN10), (SInt16)(1.25 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMaxAbs_M
[VSC_16_SIZE][VSC_16_SIZE] = {
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) },
{
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10), (UInt16)(1.4501953125 * BIN10),
(UInt16)(1.4501953125 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMaxCft_M
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
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(0.7998046875 * BIN10), (UInt16)(0.7998046875 * BIN10) },
{
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10),
(UInt16)(1.2001953125 * BIN10), (UInt16)(1.2001953125 * BIN10) },
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

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMinAbs_M
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
(SInt16)(-1 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMinCft_M
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

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMaxAbs_T
[VSC_16_SIZE] = {
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMaxCvg_T
[VSC_16_SIZE] = {
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7), (UInt16)(3 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(0.25 * BIN7), (UInt16)(0.25 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMinAbs_T
[VSC_16_SIZE] = {
(SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(-0.5 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMinCvg_T
[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(-0.25 * BIN7), (SInt16)(-0.25 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMnTran_T
[VSC_16_SIZE] = {
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7),
(SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7),
(SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7),
(SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7), (SInt16)(-6 * BIN7),
(SInt16)(-6 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVeh_tiCfmSupStVSRegY_A[VSC_8_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-2 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(0 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(2 * BIN7), (SInt16)(3 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVeh_tiCfmSupTrVSRegY_A[VSC_8_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-2 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(0 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(2 * BIN7), (SInt16)(3 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rCtlTqWhlPotVSReg_T
[VSC_8_SIZE] = {
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSRegSatMnAbsY_A[VSC_16_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-90 * BIN7), (SInt16)(-80 * BIN7),
(SInt16)(-70 * BIN7), (SInt16)(-60 * BIN7), (SInt16)(-50 * BIN7),
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-25 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-2 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSRegSatMnCftY_A[VSC_16_SIZE] = {
(SInt16)(-100 * BIN7), (SInt16)(-90 * BIN7), (SInt16)(-80 * BIN7),
(SInt16)(-70 * BIN7), (SInt16)(-60 * BIN7), (SInt16)(-50 * BIN7),
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-25 * BIN7),
(SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-2 * BIN7), (SInt16)(-1 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSRegSatMxAbsY_A[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(2 * BIN7),
(SInt16)(5 * BIN7), (SInt16)(10 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(40 * BIN7), (SInt16)(50 * BIN7), (SInt16)(60 * BIN7),
(SInt16)(70 * BIN7), (SInt16)(80 * BIN7), (SInt16)(90 * BIN7),
(SInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdEAVehVSRegSatMxCftY_A[VSC_16_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(2 * BIN7),
(SInt16)(5 * BIN7), (SInt16)(10 * BIN7), (SInt16)(15 * BIN7),
(SInt16)(20 * BIN7), (SInt16)(25 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(40 * BIN7), (SInt16)(50 * BIN7), (SInt16)(60 * BIN7),
(SInt16)(70 * BIN7), (SInt16)(80 * BIN7), (SInt16)(90 * BIN7),
(SInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdE_aVehPotOftVSRegRqY_A[VSC_8_SIZE] = {
(SInt16)(-60 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-10 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(10 * BIN7), (SInt16)(30 * BIN7),
(SInt16)(60 * BIN7), (SInt16)(80 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdE_tiCfmSdwnStVSRegY_A[VSC_8_SIZE] = {
(SInt16)(-20 * BIN7), (SInt16)(-10 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(10 * BIN7),
(SInt16)(50 * BIN7), (SInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdE_tiCfmSdwnTrVSRegY_A[VSC_8_SIZE] = {
(SInt16)(-20 * BIN7), (SInt16)(-10 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(1 * BIN7), (SInt16)(10 * BIN7),
(SInt16)(50 * BIN7), (SInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdErr_rCtlPotVSReg_A[VSC_8_SIZE] = {
(SInt16)(-40 * BIN7), (SInt16)(-30 * BIN7), (SInt16)(-20 * BIN7),
(SInt16)(-15 * BIN7), (SInt16)(-10 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(10 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSRegSatMaxAbsX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSRegSatMinAbsX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSRegSatMinCftX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdRAVehVSRegSatMxCftX_A[VSC_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(30 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(110 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7), (UInt16)(170 * BIN7),
(UInt16)(190 * BIN7), (UInt16)(210 * BIN7), (UInt16)(230 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_tiCfmSdwnStVSRgX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(80 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_tiCfmSdwnTrVSRgX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(80 * BIN7), (UInt16)(110 * BIN7),
(UInt16)(130 * BIN7), (UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spd_aVehPotOftVSRegReqX_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(90 * BIN7), (UInt16)(120 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(180 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnStVSRegReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2) },
{
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2) },
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
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnTrVSRegReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2) },
{
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2), (UInt16)(0.2 * DEC2) },
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
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupStVSRegReq_M
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
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupTrVSRegReq_M
[VSC_8_SIZE][VSC_8_SIZE] = {
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(2 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(2 * DEC2),
(UInt16)(2 * DEC2), (UInt16)(1.5 * DEC2) },
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
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) },
{
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2),
(UInt16)(1.5 * DEC2), (UInt16)(1.5 * DEC2) }
};

#define VSREG_STOP_SEC_CARTO_16BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSREG_START_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehpotoftvsregreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsregreqsatmaxabs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsregreqsatmaxcft_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsregreqsatminabs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_avehvsregreqsatmincft_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsregsatmaxabs_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsregsatmaxcvg_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsregsatminabs_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsregsatmincvg_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehvsregsatmntran_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_rctltqwhlpotvsreg_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsdwnstvsregreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsdwntrvsregreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsupstvsregreq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsuptrvsregreq_m_sav;
STATIC VAR(t_dds_m_slew, AUTOMATIC) vsreg_f2212_slew_struct_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsreg_f22232_filter_struct_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsreg_f2232_filter_struct_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsreg_f2234_filter_1_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsreg_f2234_filter_2_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsreg_f2234_filter_3_struct;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsreg_f2234_filter_4_struct;
#define VSREG_STOP_SEC_VAR_UNSPECIFIED
#include "VSReg_MemMap.h"

/* 16-bits variable definition */
#define VSREG_START_SEC_VAR_16BIT
#include "VSReg_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsreg_f22232_saturation_out_dly;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehpotvsregreq_dwn_dly;
#define VSREG_STOP_SEC_VAR_16BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMaxAbs; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMaxApl; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMaxCft; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMinAbs; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMinApl; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMinCft; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPotVSRegReqOft; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPotVSRegReqRaw; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_spdVehErrVSRegRaw; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSatMax; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqMax; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqMin; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMax; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMin; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehPotVSRegReq; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSRegReqFilRaw; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMaxAbs; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMaxCvg; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMinAbs; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMinCrit; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMinCvg; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegSatMinTran; /* BIN7 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReqRaw1; /* DEC2 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReqRaw2; /* DEC2 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReqRaw3; /* DEC2 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSRegReqRaw1; /* DEC2 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSRegReqRaw2; /* DEC2 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupVSRegReqRaw3; /* DEC2 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqRaw; /* BIN10 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSREG_START_SEC_CONST_UNSPECIFIED
#include "VSReg_MemMap.h"
STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHPOTOFTVSREGREQ_M_APM = {
&vsctl_avehpotoftvsregreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spd_aVehPotOftVSRegReqX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdE_aVehPotOftVSRegRqY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehPotOftVSRegReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_AVEHVSREGREQSATMAXABS_M_APM = {
&vsctl_avehvsregreqsatmaxabs_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSRegSatMaxAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSRegSatMxAbsY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSRegReqSatMaxAbs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_AVEHVSREGREQSATMAXCFT_M_APM = {
&vsctl_avehvsregreqsatmaxcft_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSRegSatMxCftX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSRegSatMxCftY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSRegReqSatMaxCft_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHVSREGREQSATMINABS_M_APM = {
&vsctl_avehvsregreqsatminabs_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSRegSatMinAbsX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSRegSatMnAbsY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSRegReqSatMinAbs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) VSCTL_AVEHVSREGREQSATMINCFT_M_APM = {
&vsctl_avehvsregreqsatmincft_m_sav,
VSC_16_SIZE,
VSC_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdRAVehVSRegSatMinCftX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdEAVehVSRegSatMnCftY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehVSRegReqSatMinCft_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_JRKVEHVSREGSATMAXABS_T_APM = {
&vsctl_jrkvehvsregsatmaxabs_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSRegSatMaxAbs_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSRegSatMaxAbs_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_JRKVEHVSREGSATMAXCVG_T_APM = {
&vsctl_jrkvehvsregsatmaxcvg_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSRegSatMaxCvg_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSRegSatMaxCvg_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHVSREGSATMINABS_T_APM = {
&vsctl_jrkvehvsregsatminabs_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSRegSatMinAbs_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSRegSatMinAbs_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHVSREGSATMINCVG_T_APM = {
&vsctl_jrkvehvsregsatmincvg_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSRegSatMinCvg_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSRegSatMinCvg_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHVSREGSATMNTRAN_T_APM = {
&vsctl_jrkvehvsregsatmntran_t_sav,
VSC_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aJrkVehVSRegSatMnTran_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehVSRegSatMnTran_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RCTLTQWHLPOTVSREG_T_APM = {
&vsctl_rctltqwhlpotvsreg_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdErr_rCtlPotVSReg_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rCtlTqWhlPotVSReg_T[0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_TICFMSDWNSTVSREGREQ_M_APM = {
&vsctl_ticfmsdwnstvsregreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_tiCfmSdwnStVSRgX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdE_tiCfmSdwnStVSRegY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSdwnStVSRegReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) VSCTL_TICFMSDWNTRVSREGREQ_M_APM = {
&vsctl_ticfmsdwntrvsregreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_tiCfmSdwnTrVSRgX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdE_tiCfmSdwnTrVSRegY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSdwnTrVSRegReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_TICFMSUPSTVSREGREQ_M_APM = {
&vsctl_ticfmsupstvsregreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehRq_tiCfmSupStVSRegX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVeh_tiCfmSupStVSRegY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSupStVSRegReq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_TICFMSUPTRVSREGREQ_M_APM = {
&vsctl_ticfmsuptrvsregreq_m_sav,
VSC_8_SIZE,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehRq_tiCfmSupTrVSRegX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVeh_tiCfmSupTrVSRegY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSupTrVSRegReq_M[0][0]
};

#define VSREG_STOP_SEC_CONST_UNSPECIFIED
#include "VSReg_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSREG_START_SEC_CODE
#include "VSReg_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
*
* Function Name : VSREG_F2212_Determiner_Consigne_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2212_Determiner_Consigne_Vitesse_Vehicule(
                                                 SInt8 CoPt_noEgdGearCordIt_swc_in,
                                                 UInt8 Ext_spdVehVSRegReq_swc_in, /* BIN0 */
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSReg_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.125.1 */
    UInt32 vsctl_f22122_slew_inc;
    UInt32 vsctl_f22122_slew_dec;
    UInt16 vsreg_rate_output;
    UInt32 vsreg_uvalue;

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFilSpdVehVSReg)
    {
        /* BIN7 = BIN14 / BIN7 */
        /* [0; 255] = [0; 255] */
        vsreg_rate_output = (UInt16)(DDS_M_SLEW_U32_INIT(&vsreg_f2212_slew_struct_ptr,
                                                         ((UInt32)Ext_spdVehVSRegReq_swc_in) * BIN14) / BIN7);
    }
    else
    {
        /* INC and DEC must be >0 */
        /* BIN14 = BIN10 * BIN0 / BIN0 * DEC3 * BIN4 / DEC3 */
        /* [0 ; 720] = [0; 10] * 3.6 * 20 */
        vsctl_f22122_slew_inc = (((((UInt32)VSCtl_aVehMaxSpdVehVSRegReq_C
                                * (UInt32)(36 * BIN0))
                                / (UInt32)(10 * BIN0))
                                * VSREG_SCHEDULING_40MS)
                                * BIN4)
                                / DEC3;

        /* BIN14 = BIN10 * BIN0 / BIN0 * DEC3 * BIN4 / DEC3 */
        /* [0 ; 720] = [0; 10] * 3.6 * 20 */
        vsctl_f22122_slew_dec = (((((UInt32)VSCtl_aVehMinSpdVehVSRegReq_C
                                * (UInt32)(36 * BIN0))
                                / (UInt32)(10 * BIN0))
                                * VSREG_SCHEDULING_40MS)
                                * BIN4)
                                / DEC3;

        /* BIN7 = BIN14 / BIN7 */
        /* [0; 255] = [0; 255] */
        vsreg_rate_output = (UInt16)(DDS_M_SLEW_U32(&vsreg_f2212_slew_struct_ptr,
                                                    ((UInt32)Ext_spdVehVSRegReq_swc_in * BIN14),
                                                    vsctl_f22122_slew_inc,
                                                    vsctl_f22122_slew_dec) / BIN7);
    }


    if(  (VSREG_VSCTL_STFILSPDVEHVSREG_NON_FILTREE == (UInt32)VSCtl_stFilSpdVehVSReg)
       ||(VSREG_VSCTL_STFILSPDVEHVSREG_FILTREE == (UInt32)VSCtl_stFilSpdVehVSReg))
    {
        VSCtl_spdVehVSRegReqFilRaw = vsreg_rate_output;
        if((UInt32)VSCtl_stSatMaxSpdVehVSReg == (UInt32)DDS_TRUE)
        {
            /* not needed to add 1 to CoPt_noEgdGearCordIt to implement the switch */
            switch((SInt32)CoPt_noEgdGearCordIt_swc_in)
            {
                case VSREG_COPT_NOEGDGEARCORDIT_1ER_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no1_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_2EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no2_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_3EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no3_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_4EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no4_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_5EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no5_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_6EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no6_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_7EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no7_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_8EME_RAPPORT:
                    vsreg_uvalue = VSCtl_spdVehVSRegSatMax_no8_C;
                    break;
                case VSREG_COPT_NOEGDGEARCORDIT_MAR:
                case VSREG_COPT_NOEGDGEARCORDIT_NEUTRE:
                default:
                    vsreg_uvalue = VSREG_255_BIN7;
                    break;
            }
            VSCtl_spdVehVSRegReqFil = (UInt16)DDS_M_MIN(vsreg_uvalue,(UInt32)VSCtl_spdVehVSRegReqFilRaw);
        }
        else
        {
            VSCtl_spdVehVSRegReqFil = VSCtl_spdVehVSRegReqFilRaw;
        }

        VSCtl_spdVehErrVSRegRaw = (SInt16)((SInt32)VSCtl_spdVehVSRegReqFilRaw - (SInt32)VSCtl_spdVeh_swc_in);
        *VSCtl_spdVehErrVSReg_swc_out = (SInt16)((SInt32)VSCtl_spdVehVSRegReqFil - (SInt32)VSCtl_spdVeh_swc_in);
    }
    else
    {
        VSCtl_spdVehVSRegReqFilRaw = VSREG_0;
        VSCtl_spdVehVSRegReqFil = VSREG_0;

        VSCtl_spdVehErrVSRegRaw = VSREG_0;
        *VSCtl_spdVehErrVSReg_swc_out = VSREG_0;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F222221_Determiner_Saturation_Acceleration_Vehicule_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F222221_Determiner_Saturation_Acceleration_Vehicule_Max(
                                                 SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.62.3 */
    SInt32 vsreg_map_abs_out;
    SInt32 vsreg_map_cft_out;

    vsreg_map_abs_out = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_AVEHVSREGREQSATMAXABS_M_APM,VSCtl_spdVehVSRegReqFil,VSCtl_spdVehErrVSReg_swc_in);
    vsreg_map_cft_out = (SInt32)DDS_M_MAP3D_USU16(&VSCTL_AVEHVSREGREQSATMAXCFT_M_APM,VSCtl_spdVehVSRegReqFil,VSCtl_spdVehErrVSReg_swc_in);

    if(  ((UInt32)VSCtl_stCtl_aVehVSReg_swc_in == VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE)
       ||((UInt32)VSCtl_stCtl_aVehVSReg_swc_in == VSREG_VSCTL_STCTL_AVEHVSREG_TRANSITION))
    {
        VSCtl_aVehVSRegReqSatMax = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_aVehPTMax_swc_in,vsreg_map_cft_out,vsreg_map_abs_out);
        VSCtl_aVehVSRegReqSatMaxCft = (SInt16)vsreg_map_cft_out;
        VSCtl_aVehVSRegReqSatMaxAbs = (SInt16)vsreg_map_abs_out;
    }
    else
    {
        VSCtl_aVehVSRegReqSatMax = VSREG_10_BIN10;
        VSCtl_aVehVSRegReqSatMaxCft = VSREG_10_BIN10;
        VSCtl_aVehVSRegReqSatMaxAbs = VSREG_10_BIN10;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F222222_Determiner_Saturation_Acceleration_Vehicule_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F222222_Determiner_Saturation_Acceleration_Vehicule_Min(
                                                 SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.63.4 */
    SInt32 vsreg_map_abs_out;
    SInt32 vsreg_map_cft_out;

    vsreg_map_abs_out = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHVSREGREQSATMINABS_M_APM,VSCtl_spdVehVSRegReqFil,VSCtl_spdVehErrVSReg_swc_in);
    vsreg_map_cft_out = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHVSREGREQSATMINCFT_M_APM,VSCtl_spdVehVSRegReqFil,VSCtl_spdVehErrVSReg_swc_in);

    if(  ((UInt32)VSCtl_stCtl_aVehVSReg_swc_in == VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE)
       ||((UInt32)VSCtl_stCtl_aVehVSReg_swc_in == VSREG_VSCTL_STCTL_AVEHVSREG_TRANSITION))
    {
        VSCtl_aVehVSRegReqSatMin = (SInt16)DDS_M_LIMIT_V2((SInt32)VSCtl_aVehPTMin_swc_in,vsreg_map_abs_out,vsreg_map_cft_out);
        VSCtl_aVehVSRegReqSatMinCft = (SInt16)vsreg_map_cft_out;
        VSCtl_aVehVSRegReqSatMinAbs = (SInt16)vsreg_map_abs_out;
    }
    else
    {
        VSCtl_aVehVSRegReqSatMin = -VSREG_10_BIN10;
        VSCtl_aVehVSRegReqSatMinCft = -VSREG_10_BIN10;
        VSCtl_aVehVSRegReqSatMinAbs = -VSREG_10_BIN10;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F22223_Determiner_Saturations_Jerk_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F22223_Determiner_Saturations_Jerk_Vehicule(
                                                 SInt16 VSCtl_aVehPreCoVSCtlReq_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                                 UInt16 VSCtl_rTqWhlPTDrvReq_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.64.4 */
    SInt16 vsregh_temp;
    SInt16 vsregh_temp1;
    SInt32 vsregh_temp2;
    SInt32 vsctl_jrkvehvsregsatmincrit_temp;
    UInt8 vsregh_tifilstctlavehvsreg_cpy;

    switch((UInt32)VSCtl_stCtl_aVehVSReg_swc_in)
    {
        case VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE:
            vsregh_temp1 = (SInt16)((SInt32)VSCtl_aVehReq_swc_in - (SInt32)VSCtl_aVehVSRegReqSatMax);
            VSCtl_jrkVehVSRegSatMaxCvg = (SInt16)DDS_M_MAP2D_SU16(&VSCTL_JRKVEHVSREGSATMAXCVG_T_APM,
                                                                    vsregh_temp1);
            VSCtl_jrkVehVSRegSatMaxAbs = (SInt16)DDS_M_MAP2D_SU16(&VSCTL_JRKVEHVSREGSATMAXABS_T_APM,
                                                                    VSCtl_aVehReq_swc_in);
            VSCtl_jrkVehVSRegSatMax = (SInt16)DDS_M_MIN((SInt32)VSCtl_jrkVehVSRegSatMaxCvg,
                                                        (SInt32)VSCtl_jrkVehVSRegSatMaxAbs);

            VSCtl_jrkVehVSRegSatMinAbs = DDS_M_MAP2D_S16(&VSCTL_JRKVEHVSREGSATMINABS_T_APM,
                                                        VSCtl_aVehReq_swc_in);
            vsregh_temp =  (SInt16)((SInt32)VSCtl_aVehReq_swc_in - (SInt32)VSCtl_aVehVSRegReqSatMin);
            VSCtl_jrkVehVSRegSatMinCvg = DDS_M_MAP2D_S16(&VSCTL_JRKVEHVSREGSATMINCVG_T_APM,
                                                        vsregh_temp);
            if(VSCTL_STSATJRKVEHMINVSREG_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMinVSReg)
            {
                VSCtl_jrkVehVSRegSatMin = (SInt16)DDS_M_MAX((SInt32)VSCtl_jrkVehVSRegSatMinAbs, (SInt32)VSCtl_jrkVehVSRegSatMinCvg);
            }
            else
            {
                VSCtl_jrkVehVSRegSatMin = (SInt16)(-100 * BIN7);
            }
            VSCtl_jrkVehVSRegSatMinTran = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMinCrit = (SInt16)(-100 * BIN7);
            break;
        case VSREG_VSCTL_STCTL_AVEHVSREG_TRANSITION:
            VSCtl_jrkVehVSRegSatMaxCvg = (SInt16)(100 * BIN7);
            VSCtl_jrkVehVSRegSatMax = (SInt16)(100 * BIN7);
            VSCtl_jrkVehVSRegSatMaxAbs = (SInt16)(100 * BIN7);
            VSCtl_jrkVehVSRegSatMinAbs = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMinCvg = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMinTran = DDS_M_MAP2D_S16(&VSCTL_JRKVEHVSREGSATMNTRAN_T_APM,
                                                            VSCtl_aVehReq_swc_in);
            /* [-20;20] BIN10 */
            vsregh_temp2 = (SInt32)VSCtl_aVehPreCoVSCtlReq_swc_in - (SInt32)VSCtl_aVehReq_swc_in;

            /* [0;255] BIN0 */
            vsregh_tifilstctlavehvsreg_cpy = VSCtl_tiFilStCtlAVehVSReg;

            /* Secure div */
            if ((SInt32)0 == vsregh_temp2)                                  /* Numerator test */
            {
                VSCtl_jrkVehVSRegSatMinCrit = (SInt16)(0 * BIN7);
            }
            else if ((UInt32)0 == (UInt32)vsregh_tifilstctlavehvsreg_cpy)   /* Denominator test */
            {
                if(vsregh_temp2 > (SInt32)(0 * BIN7))
                {
                    VSCtl_jrkVehVSRegSatMinCrit = (SInt16)(100 * BIN7);
                }
                else
                {
                    VSCtl_jrkVehVSRegSatMinCrit = (SInt16)(-100 * BIN7);
                }
            }
            else                                                            /* Division */
            {
                /* [-500;500]BIN10 = [-20;20]BIN10 * DEC3 / [0;255]BIN0 * 40 (equal to 0.04 * DEC3) */
                vsctl_jrkvehvsregsatmincrit_temp = (vsregh_temp2 * DEC3) / ((SInt32)vsregh_tifilstctlavehvsreg_cpy * VSREG_SCHEDULING_40MS);

                vsctl_jrkvehvsregsatmincrit_temp = vsctl_jrkvehvsregsatmincrit_temp / BIN3;
                VSCtl_jrkVehVSRegSatMinCrit = (SInt16)DDS_M_LIMIT(vsctl_jrkvehvsregsatmincrit_temp,
                                                                  -VSREG_100_BIN7,
                                                                  VSREG_100_BIN7);
            }




            if((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvJrkSatMnCritVSReg_C)
            {
                VSCtl_jrkVehVSRegSatMin = (SInt16)DDS_M_MIN((SInt32)VSCtl_jrkVehVSRegSatMinTran,
                                                            (SInt32)VSCtl_jrkVehVSRegSatMinCrit);
            }
            else
            {
                VSCtl_jrkVehVSRegSatMin = VSCtl_jrkVehVSRegSatMinTran;
            }
            break;
        case VSREG_VSCTL_STCTL_AVEHVSREG_ARRET:
        default:
            VSCtl_jrkVehVSRegSatMaxCvg = (SInt16)(100 * BIN7);
            VSCtl_jrkVehVSRegSatMax = (SInt16)(100 * BIN7);
            VSCtl_jrkVehVSRegSatMaxAbs = (SInt16)(100 * BIN7);
            VSCtl_jrkVehVSRegSatMinAbs = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMin = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMinCvg = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMinTran = (SInt16)(-100 * BIN7);
            VSCtl_jrkVehVSRegSatMinCrit = (SInt16)(-100 * BIN7);
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F22224_Determiner_Gabarits_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F22224_Determiner_Gabarits_Acceleration_Vehicule(
                                                 SInt16 VSCtl_aVehPTIni_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                 SInt16 VSCtl_aVehReq_swc_in, /* BIN10 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.126.0 */
    SInt32 sat_min, sat_max;
    SInt32 temp_min, temp_max;
    SInt32 temp_min_out, temp_max_out;
    SInt32 vsreg_svalue;

    switch((UInt32)VSCtl_stSatAVehMinVSReg)
    {
        case VSCTL_STSATAVEHMINVSREG_ARRET:
            sat_max = (SInt32)(10 * BIN10);
            sat_min = (SInt32)(-10 * BIN10);
            break;
        case VSCTL_STSATAVEHMINVSREG_NON_EFFECTIF_29:
            sat_max = (SInt32)VSCtl_aVehPTMax_swc_in;
            sat_min = (SInt32)VSCtl_aVehPTMin_swc_in;
            break;
        case VSCTL_STSATAVEHMINVSREG_EFFECTIF_29:
            sat_max = DDS_M_MIN((SInt32)VSCtl_aVehVSRegReqSatMax, (SInt32)VSCtl_aVehPTMax_swc_in);
            sat_min = DDS_M_MAX((SInt32)VSCtl_aVehVSRegReqSatMin, (SInt32)VSCtl_aVehPTMin_swc_in);
            break;
        case VSCTL_STSATAVEHMINVSREG_ACTIVATION_29:
            sat_max = (SInt32)VSCtl_aVehPTMax_swc_in;
            sat_min = DDS_M_MAX((SInt32)VSCtl_aVehPTMin_swc_in,(SInt32)VSCtl_aVehReq_swc_in);
            break;
        default:
            sat_max = (SInt32)(10 * BIN10);
            sat_min = (SInt32)(-10 * BIN10);
            break;
    }

    switch((UInt32)VSCtl_stCtl_aVehVSReg_swc_in)
    {
        case VSREG_VSCTL_STCTL_AVEHVSREG_ARRET:
            VSCtl_aVehVSRegReqMax = (SInt16)(10 * BIN10);
            VSCtl_aVehVSRegReqMin = (SInt16)(-10 * BIN10);
            VSCtl_aVehVSRegReqSatMaxApl = (SInt16)(10 * BIN10);
            VSCtl_aVehVSRegReqSatMinApl = (SInt16)(-10 * BIN10);
            break;
        case VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE:
            /* [-14;14]BIN10 = [-10;10]BIN10 + (([-100;100]BIN7 * BIN3) * 40 (equal to 0.04 * DEC3)) / DEC3 */
            temp_max = (SInt32)VSCtl_aVehReq_swc_in + (((SInt32)VSCtl_jrkVehVSRegSatMax * (BIN3 * VSREG_SCHEDULING_40MS)) / (DEC3));
            temp_min = (SInt32)VSCtl_aVehReq_swc_in + (((SInt32)VSCtl_jrkVehVSRegSatMin * (BIN3 * VSREG_SCHEDULING_40MS)) / (DEC3));

            /* [-10;10]BIN10 */
            temp_max_out = DDS_M_SATURATION_V2(temp_max, sat_min,sat_max);


            /* [-10;10]BIN10 */
            temp_min_out = DDS_M_SATURATION_V2(temp_min,sat_min,sat_max);


            if(  ((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvInitAVehVSReg_C)
               &&((UInt32)DDS_TRUE == (UInt32)VSCtl_bAcvCtlAVehVSReg))
            {
                VSCtl_aVehVSRegReqMax = (SInt16)(DDS_M_MAX(temp_max_out, (SInt32)VSCtl_aVehPTIni_swc_in));
            }
            else
            {
                VSCtl_aVehVSRegReqMax = (SInt16)temp_max_out;
            }

            if(VSCTL_STSATJRKVEHMINVSREG_EFFECTIF == (UInt32)VSCtl_stSatJrkVehMinVSReg)
            {
                VSCtl_aVehVSRegReqMin = (SInt16)temp_min_out;
            }
            else
            {
                VSCtl_aVehVSRegReqMin = (SInt16)sat_min;
            }

            VSCtl_aVehVSRegReqSatMaxApl = (SInt16)sat_max;

            VSCtl_aVehVSRegReqSatMinApl = (SInt16)sat_min;
            break;
        case VSREG_VSCTL_STCTL_AVEHVSREG_TRANSITION:
            VSCtl_aVehVSRegReqMax = (SInt16)(10 * BIN10);

            /* [-14;14]BIN10 = [-10;10]BIN10 + ( ([-100;100]BIN7 * BIN3 * 40) / DEC3) */
            vsreg_svalue = (((SInt32)VSCtl_aVehReq_swc_in + (((SInt32)VSCtl_jrkVehVSRegSatMin * (BIN3 * VSREG_SCHEDULING_40MS)) / DEC3)));
            VSCtl_aVehVSRegReqMin = (SInt16)DDS_M_LIMIT(vsreg_svalue,
                                                        -VSREG_10_BIN10,
                                                        VSREG_10_BIN10);

            VSCtl_aVehVSRegReqSatMaxApl = (SInt16)sat_max;

            VSCtl_aVehVSRegReqSatMinApl = (SInt16)sat_min;

            break;
        default:
            VSCtl_aVehVSRegReqMax = (SInt16)(10 * BIN10);
            VSCtl_aVehVSRegReqMin = (SInt16)(-10 * BIN10);
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F22232_Determiner_Consigne_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F22232_Determiner_Consigne_Acceleration_Vehicule(
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_swc_out /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.54.3 */
    SInt32 vsreg_inp_bary_1;   /* BIN10 */
    SInt32 vsreg_inp_bary_2;   /* BIN10 */
    SInt32 vsreg_output_bary;  /* BIN10 */
    SInt32 vsreg_output_saturation;  /* BIN10 */
    SInt32 vsreg_filter_out; /* BIN7 */
    SInt32 vsreg_svalue;

    /*************** filtre_barycentrique calculation ************/
    /* BIN10 = (BIN7 * BIN7) / BIN4 */
    /* [-708,3; 708,3] = [-255;255] * [0;10] / 3.6 */
    vsreg_inp_bary_1 = (((SInt32)VSCtl_spdVehErrVSReg_swc_in * (SInt32)VSCtl_spdCtlGain1VSRegAVeh_C) * 10) / (36 * BIN4);

    /* BIN10 = (BIN7 * BIN7) / BIN4 */
    /* [-708,3; 708,3] = [-255;255] * [0;10] / 3.6 */
    vsreg_inp_bary_2 = (((SInt32)VSCtl_spdVehErrVSReg_swc_in * (SInt32)VSCtl_spdCtlGain2VSRegAVeh_C) * 10) / (36 * BIN4);

    vsreg_inp_bary_2 = DDS_M_SATURATION_V2(vsreg_inp_bary_2,(SInt32)VSCtl_aVehVSRegDynStbMin_C,(SInt32)VSCtl_aVehVSRegDynStbMax_C);

    vsreg_output_bary = DDS_M_BARY_FILTER_S32(vsreg_inp_bary_1,
                                              vsreg_inp_bary_2,
                                              VSCtl_rSpdVehCtlVSRegDyn,
                                              (UInt16)VSREG_100_BIN7);

    VSCtl_aVehVSRegReqRaw = (SInt16)DDS_M_LIMIT(vsreg_output_bary,-VSREG_10_BIN10,VSREG_10_BIN10);

    /*************** VSCtl_aVehVSRegReq and VSCtl_jrkVehVSRegReq calculation ************/
    if((UInt32)VSCtl_stCtl_aVehVSReg_swc_in != VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE)
    {
        vsreg_output_bary = -VSREG_10_BIN10;
    }
    else
    {
        /* Nothing to do */
    }
    vsreg_output_saturation = DDS_M_SATURATION_V2(vsreg_output_bary,(SInt32)VSCtl_aVehVSRegReqMin,(SInt32)VSCtl_aVehVSRegReqMax);

    /* BIN10 = (BIN10 - BIN10) * (DEC3 / DEC3) */
    /* [-20;20] = ([-10;10] - [-10;10]) / 0.04 */
    /* DEC3 / VSREG_SCHEDULING_40MS = 1000 / 40 = 25: so we could put "(" and ")" as done */
    vsreg_svalue = (vsreg_output_saturation - (SInt32)vsreg_f22232_saturation_out_dly) * (DEC3 / VSREG_SCHEDULING_40MS);

    if((UInt32)VSCtl_bAcvFil_aVehVSReg == (UInt32)DDS_TRUE)
    {
        vsreg_filter_out = DDS_M_FILTER_LP1_S32(&vsreg_f22232_filter_struct_ptr, vsreg_svalue, (UInt16)((UInt32)VSCtl_tiFil_jrkVehVSRegRq_C * BIN5));
    }
    else
    {
        vsreg_filter_out = DDS_M_FILTER_LP1_S32_INIT(&vsreg_f22232_filter_struct_ptr, vsreg_svalue);
    }

    if(  ((UInt32)VSCtl_stCtl_aVehVSReg_swc_in == VSREG_VSCTL_STCTL_AVEHVSREG_CONTROLE)
       ||((UInt32)VSCtl_stCtl_aVehVSReg_swc_in == VSREG_VSCTL_STCTL_AVEHVSREG_TRANSITION))
    {
        *VSCtl_aVehVSRegReq_swc_out = (SInt16)vsreg_output_saturation;

        vsreg_filter_out = vsreg_filter_out / BIN3;
        VSCtl_jrkVehVSRegReq = (SInt16)DDS_M_LIMIT(vsreg_filter_out,-VSREG_100_BIN7,VSREG_100_BIN7);
    }
    else
    {
        *VSCtl_aVehVSRegReq_swc_out = (SInt16)(-10 * BIN10);
        VSCtl_jrkVehVSRegReq = (SInt16)(0 * BIN7);
    }

    vsreg_f22232_saturation_out_dly = (SInt16)vsreg_output_saturation;
}

/*******************************************************************************
*
* Function Name : VSREG_F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule(
                                                 UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSRegReq_swc_out /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.70.6 */
    SInt32 vsctl_avehpotvsregreqraw_loc;
    SInt32 vsctl_avehpotvsregreqoft_loc;
    SInt32 vsctl_avehpotvsregreq_dwn;
    SInt32 vsreg_output_saturation; /* BIN10 */
    SInt32 vsreg_filter_out; /* BIN7 */
    SInt32 vsreg_svalue;


    /* [-708;708]BIN10 = ([-255;255]BIN7 * [0;10]BIN7) * 10*BIN0 / 36*BIN4 */
    vsctl_avehpotvsregreqraw_loc =   ((((SInt32)VSCtl_spdVehErrVSReg_swc_in * (SInt32)VSCtl_spdCtlGainVSRegAVehPot_C) * (SInt32)(10 * BIN0))
                                   / (SInt32)(36 * BIN4)) ;
    vsctl_avehpotvsregreqraw_loc = DDS_M_LIMIT(vsctl_avehpotvsregreqraw_loc,-VSREG_10_BIN10,VSREG_10_BIN10);

    /* BIN10: [-10;10] */
    vsctl_avehpotvsregreqoft_loc = (SInt32)DDS_M_MAP3D_USS16(&VSCTL_AVEHPOTOFTVSREGREQ_M_APM,VSCtl_spdVeh_swc_in,VSCtl_spdVehErrVSReg_swc_in);

    /* [-10;10]BIN10 */
    vsreg_output_saturation = DDS_M_SATURATION_V2(vsctl_avehpotvsregreqraw_loc,
                                                  (SInt32)VSCtl_aVehVSRegReqSatMin,
                                                  (SInt32)VSCtl_aVehVSRegReqSatMax);

    /* [-20;20]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
    vsctl_avehpotvsregreq_dwn = vsctl_avehpotvsregreqoft_loc + vsreg_output_saturation;

    /* BIN10 = (BIN10 - BIN10) * (DEC3 / DEC3) */
    /* [-1000;1000] = ([-20;20] - [-20;20]) / 0.04 */
    /* DEC3 / VSREG_SCHEDULING_40MS = 1000 / 40 = 25: so we could put "(" and ")" as done */
    vsreg_svalue = (vsctl_avehpotvsregreq_dwn - (SInt32)vsctl_avehpotvsregreq_dwn_dly) * (DEC3 / VSREG_SCHEDULING_40MS);

    if((UInt32)VSCtl_bAcvFil_aVehPotVSReg == (UInt32)DDS_TRUE)
    {
        /* [-1000;1000]BIN10 */
        vsreg_filter_out = DDS_M_FILTER_LP1_S32(&vsreg_f2232_filter_struct_ptr,
                                                vsreg_svalue,
                                                (UInt16)((UInt32)VSCtl_tiFil_jrkVehPotVSRegRq_C * BIN5));
    }
    else
    {
        vsreg_filter_out = DDS_M_FILTER_LP1_S32_INIT(&vsreg_f2232_filter_struct_ptr, vsreg_svalue);
    }

    /*************** set output ************/
    if((UInt32)VSCtl_bCtl_aVehPotVSReg_swc_in == (UInt32)DDS_TRUE)
    {
        VSCtl_aVehPotVSRegReqRaw = (SInt16)vsctl_avehpotvsregreqraw_loc;
        *VSCtl_aVehPotVSRegReq_swc_out = (SInt16)DDS_M_LIMIT(vsctl_avehpotvsregreq_dwn,
                                                                -VSREG_10_BIN10,
                                                                VSREG_10_BIN10);
        vsreg_filter_out = vsreg_filter_out / BIN3;
        VSCtl_jrkVehPotVSRegReq = (SInt16)DDS_M_LIMIT(vsreg_filter_out,-VSREG_100_BIN7,VSREG_100_BIN7);
        VSCtl_aVehPotVSRegReqOft = (SInt16)vsctl_avehpotvsregreqoft_loc;
    }
    else
    {
        VSCtl_aVehPotVSRegReqRaw = (SInt16)(0 * BIN10);
        *VSCtl_aVehPotVSRegReq_swc_out = (SInt16)(-10 * BIN10);
        VSCtl_jrkVehPotVSRegReq = (SInt16)(0 * BIN7);
        VSCtl_aVehPotVSRegReqOft = (SInt16)(0 * BIN10);
    }

    vsctl_avehpotvsregreq_dwn_dly = (SInt16)vsctl_avehpotvsregreq_dwn;

}

/*******************************************************************************
*
* Function Name : VSREG_F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp(
                                                 UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSReg_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.73.4 */

    if((UInt32)VSCtl_bCtl_aVehPotVSReg_swc_in == (UInt32)DDS_TRUE)
    {
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bDrvOvrdVSReg_aVeh_no2)
        {
            *VSCtl_rCtlTqWhlPTPotVSReg_swc_out = DDS_M_MAP2D_SU16(&VSCTL_RCTLTQWHLPOTVSREG_T_APM,VSCtl_spdVehErrVSReg_swc_in);
        }
        else
        {
            *VSCtl_rCtlTqWhlPTPotVSReg_swc_out = (UInt16)(100 * BIN4);
        }
    }
    else
    {
        *VSCtl_rCtlTqWhlPTPotVSReg_swc_out = (UInt16)(0 * BIN4);
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F2234_Determiner_Temps_Confirmation_Changement_Rapport
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2234_Determiner_Temps_Confirmation_Changement_Rapport(
                                                 SInt16 VSCtl_aVehPotVSRegReq_swc_in, /* BIN10 */
                                                 UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_spdVehErrVSReg_swc_in, /* BIN7 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReq_swc_out, /* DEC2 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSRegReq_swc_out /* DEC2 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.74.1 */
    UInt16 vsreg_f2234_map_out_1;
    UInt16 vsreg_f2234_map_out_2;
    UInt16 vsreg_f2234_map_out_3;
    UInt16 vsreg_f2234_map_out_4;

    UInt16 vsreg_f2234_filter_output_1;
    UInt16 vsreg_f2234_filter_output_2;
    UInt16 vsreg_f2234_filter_output_3;
    UInt16 vsreg_f2234_filter_output_4;

    UInt16 vsreg_filter_sup_input;
    UInt16 vsreg_filter_sdwn_input;

    /* [0;16]DEC2 */
    vsreg_f2234_map_out_1 = DDS_M_MAP3D_SSU16(&VSCTL_TICFMSUPTRVSREGREQ_M_APM,
                                              VSCtl_aVehPotVSRegReq_swc_in,
                                              VSCtl_jrkVehPotVSRegReq);

    /* [0;16]DEC2 */
    vsreg_f2234_map_out_2 = DDS_M_MAP3D_SSU16(&VSCTL_TICFMSUPSTVSREGREQ_M_APM,
                                              VSCtl_aVehPotVSRegReq_swc_in,
                                              VSCtl_jrkVehPotVSRegReq);

    /* [0;16]DEC2 */
    vsreg_f2234_map_out_3 = DDS_M_MAP3D_USU16(&VSCTL_TICFMSDWNTRVSREGREQ_M_APM,
                                              VSCtl_spdVeh_swc_in,
                                              VSCtl_spdVehErrVSReg_swc_in);

    /* [0;16]DEC2 */
    vsreg_f2234_map_out_4 = DDS_M_MAP3D_USU16(&VSCTL_TICFMSDWNSTVSREGREQ_M_APM,
                                              VSCtl_spdVeh_swc_in,
                                              VSCtl_spdVehErrVSReg_swc_in);

    if((UInt32)VSCtl_bDynCtlSpdVehVSReg == (UInt32)DDS_TRUE)
    {
        vsreg_filter_sup_input = vsreg_f2234_map_out_2;
        vsreg_filter_sdwn_input = vsreg_f2234_map_out_4;
    }
    else
    {
        vsreg_filter_sup_input = vsreg_f2234_map_out_1;
        vsreg_filter_sdwn_input = vsreg_f2234_map_out_3;
    }


    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvFil_aVehPotVSReg)
    {
        vsreg_f2234_filter_output_1 = DDS_M_FILTER_LP1_U16(&vsreg_f2234_filter_1_struct,
                                                           vsreg_filter_sup_input,
                                                           (UInt16)VSCtl_tiFil_tiCfmSupVSRegRq1_C,
                                                           BIN7);

        vsreg_f2234_filter_output_2 = DDS_M_FILTER_LP1_U16(&vsreg_f2234_filter_2_struct,
                                                           vsreg_filter_sup_input,
                                                           (UInt16)VSCtl_tiFil_tiCfmSupVSRegRq2_C,
                                                           BIN7);

        vsreg_f2234_filter_output_3 = DDS_M_FILTER_LP1_U16(&vsreg_f2234_filter_3_struct,
                                                           vsreg_filter_sdwn_input,
                                                           (UInt16)VSCtl_tiFil_tiCfmSdwnVSRegR1_C,
                                                           BIN7);

        vsreg_f2234_filter_output_4 = DDS_M_FILTER_LP1_U16(&vsreg_f2234_filter_4_struct,
                                                           vsreg_filter_sdwn_input,
                                                           (UInt16)VSCtl_tiFil_tiCfmSdwnVSRegR2_C,
                                                           BIN7);
    }
    else
    {
        vsreg_f2234_filter_output_1 = DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_1_struct,
                                                                VSCtl_tiCfmSupVSRegReqIni_C);

        vsreg_f2234_filter_output_2 = DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_2_struct,
                                                                VSCtl_tiCfmSupVSRegReqIni_C);

        vsreg_f2234_filter_output_3 = DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_3_struct,
                                                                VSCtl_tiCfmSdwnVSRegReqIni_C);

        vsreg_f2234_filter_output_4 = DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_4_struct,
                                                                VSCtl_tiCfmSdwnVSRegReqIni_C);
    }

    if((UInt32)VSCtl_bCtl_aVehPotVSReg_swc_in == (UInt32)DDS_TRUE)
    {
        VSCtl_tiCfmSupVSRegReqRaw1  = vsreg_filter_sup_input;
        VSCtl_tiCfmSupVSRegReqRaw2  = vsreg_f2234_filter_output_1;
        *VSCtl_tiCfmSupVSRegReq_swc_out = (UInt16)DDS_M_MAX((UInt32)vsreg_f2234_filter_output_1, (UInt32)vsreg_f2234_filter_output_2);
        VSCtl_tiCfmSupVSRegReqRaw3  = vsreg_f2234_filter_output_2;


        VSCtl_tiCfmSdwnVSRegReqRaw1  = vsreg_filter_sdwn_input;
        VSCtl_tiCfmSdwnVSRegReqRaw2  = vsreg_f2234_filter_output_3;
        *VSCtl_tiCfmSdwnVSRegReq_swc_out = (UInt16)DDS_M_MAX((UInt32)vsreg_f2234_filter_output_3, (UInt32)vsreg_f2234_filter_output_4);
        VSCtl_tiCfmSdwnVSRegReqRaw3  = vsreg_f2234_filter_output_4;
    }
    else
    {
        VSCtl_tiCfmSupVSRegReqRaw1  = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSupVSRegReqRaw2  = (UInt16)(0 * DEC2);
        *VSCtl_tiCfmSupVSRegReq_swc_out = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSupVSRegReqRaw3  = (UInt16)(0 * DEC2);

        VSCtl_tiCfmSdwnVSRegReqRaw1 = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSdwnVSRegReqRaw2 = (UInt16)(0 * DEC2);
        *VSCtl_tiCfmSdwnVSRegReq_swc_out = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSdwnVSRegReqRaw3 = (UInt16)(0 * DEC2);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSREG_Veh_Speed_Control_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_Veh_Speed_Control_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSReg_swc_out, /* BIN7 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_swc_out, /* BIN10 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPotVSRegReq_swc_out, /* BIN10 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rCtlTqWhlPTPotVSReg_swc_out, /* BIN4 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupVSRegReq_swc_out, /* DEC2 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnVSRegReq_swc_out /* DEC2 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_aVehPotVSRegReq_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVehVSRegReq_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_rCtlTqWhlPTPotVSReg_swc_out = (UInt16)(0 * BIN4);
    *VSCtl_spdVehErrVSReg_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_tiCfmSdwnVSRegReq_swc_out = (UInt16)(0 * DEC2);
    *VSCtl_tiCfmSupVSRegReq_swc_out = (UInt16)(0 * DEC2);

    VSCtl_aVehPotVSRegReqOft = (SInt16)(0 * BIN10);
    VSCtl_aVehPotVSRegReqRaw = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSRegReqRaw = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSRegReqSatMaxAbs = (SInt16)(10 * BIN10);
    VSCtl_aVehVSRegReqSatMaxApl = (SInt16)(10 * BIN10);
    VSCtl_aVehVSRegReqSatMaxCft = (SInt16)(10 * BIN10);
    VSCtl_aVehVSRegReqSatMinAbs = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSRegReqSatMinApl = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSRegReqSatMinCft = (SInt16)(-10 * BIN10);
    VSCtl_jrkVehVSRegReq = (SInt16)(0 * BIN7);
    VSCtl_spdVehErrVSRegRaw = (SInt16)(0 * BIN7);
    VSCtl_tiCfmSdwnVSRegReqRaw1 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSdwnVSRegReqRaw2 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSdwnVSRegReqRaw3 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupVSRegReqRaw1 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupVSRegReqRaw2 = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupVSRegReqRaw3 = (UInt16)(0 * DEC2);

    /* ---- Init Global Datas ---- */
    VSCtl_aVehVSRegReqMax = (SInt16)(10 * BIN10);
    VSCtl_aVehVSRegReqMin = (SInt16)(-10 * BIN10);
    VSCtl_aVehVSRegReqSatMax = (SInt16)(10 * BIN10);
    VSCtl_aVehVSRegReqSatMin = (SInt16)(-10 * BIN10);
    VSCtl_jrkVehPotVSRegReq = (SInt16)(0 * BIN7);
    VSCtl_jrkVehVSRegSatMax = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSRegSatMaxAbs = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSRegSatMaxCvg = (SInt16)(100 * BIN7);
    VSCtl_jrkVehVSRegSatMin = (SInt16)(-100 * BIN7);
    VSCtl_jrkVehVSRegSatMinAbs = (SInt16)(-100 * BIN7);
    VSCtl_jrkVehVSRegSatMinCrit = (SInt16)(-100 * BIN7);
    VSCtl_jrkVehVSRegSatMinCvg = (SInt16)(-100 * BIN7);
    VSCtl_jrkVehVSRegSatMinTran = (SInt16)(-100 * BIN7);
    VSCtl_spdVehVSRegReqFil = (UInt16)(0 * BIN7);
    VSCtl_spdVehVSRegReqFilRaw = (UInt16)(0 * BIN7);


    /* ---- VSREG_F2212_Determiner_Consigne_Vitesse_Vehicule ---- */
    DDS_M_SLEW_U32_INIT(&vsreg_f2212_slew_struct_ptr,
                        (UInt32)(0 * BIN14));

    /* ---- VSREG_F222221_Determiner_Saturation_Acceleration_Vehicule_Max ---- */

    /* ---- VSREG_F222222_Determiner_Saturation_Acceleration_Vehicule_Min ---- */

    /* ---- VSREG_F22223_Determiner_Saturations_Jerk_Vehicule ---- */

    /* ---- VSREG_F22224_Determiner_Gabarits_Acceleration_Vehicule ---- */

    /* ---- VSREG_F22232_Determiner_Consigne_Acceleration_Vehicule ---- */
    vsreg_f22232_saturation_out_dly = 0;
    DDS_M_FILTER_LP1_S32_INIT(&vsreg_f22232_filter_struct_ptr, (SInt16)0);

    /* ---- VSREG_F2232_Determiner_Consigne_Potentiel_Acceleration_Vehicule ---- */
    vsctl_avehpotvsregreq_dwn_dly = 0;
    DDS_M_FILTER_LP1_S32_INIT(&vsreg_f2232_filter_struct_ptr, (SInt16)0);

    /* ---- VSREG_F2233_Determiner_Taux_Application_Potentiel_Couple_Roue_Gmp ---- */

    /* ---- VSREG_F2234_Determiner_Temps_Confirmation_Changement_Rapport ---- */
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_1_struct,
                                    VSCtl_tiCfmSupVSRegReqIni_C);

    (void)DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_2_struct,
                                    VSCtl_tiCfmSupVSRegReqIni_C);

    (void)DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_3_struct,
                                    VSCtl_tiCfmSdwnVSRegReqIni_C);

    (void)DDS_M_FILTER_LP1_U16_INIT(&vsreg_f2234_filter_4_struct,
                                    VSCtl_tiCfmSdwnVSRegReqIni_C);

}

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

