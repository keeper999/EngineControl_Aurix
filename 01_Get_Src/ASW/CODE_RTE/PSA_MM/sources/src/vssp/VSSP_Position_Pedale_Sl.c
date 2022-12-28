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
* Ref X:\integration_view_00PSASWC_D820D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Position_Pedale_Sl.c
* Version int :/main/L03_02/1 Date: 6/1/2012 11 h 11 m User:esnault 
*    TWK_model:VSSP_Position_Pedale_Sl_L03_020_IMPL1
*    comments :Correct typical calibration
* Version dev :\main\branch_moisan_module_dev\1 Date: 3/1/2012 17 h 40 m User:moisan 
*    TWK_model:VSSP_Position_Pedale_Sl_L03_020_IMPL1
*    comments :Correct typical calibration
* Version int :/main/L03_01/1 Date: 7/9/2011 16 h 41 m User:esnault
*    TWK_model:VSSP_Position_Pedale_Sl_L03_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 26/7/2011 10 h 10 m User:demezil
*    TWK_model:VSSP_Position_Pedale_Sl_L03_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 21/7/2011 16 h 57 m User:demezil
*    TWK_model:VSSP_Position_Pedale_Sl_L02_010_IMPL1_D
*    comments :for VSSp 11.0
* Version int :/main/L02_01/1 Date: 30/5/2011 9 h 9 m User:esnault
*    TWK_model:VSSP_Position_Pedale_Sl_L02_010_IMPL1
*    comments :code_checker corrections
* Version dev :\main\branch_lemort_eom_dev\1 Date: 12/5/2011 15 h 46 m User:lemort
*    TWK_model:VSSP_Position_Pedale_Sl_L02_010_IMPL1
*    comments :code_checker corrections
* Version int :/main/L01_01/2 Date: 16/3/2011 11 h 48 m User:esnault
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL2
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\7 Date: 8/3/2011 14 h 22 m User:morisseau
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL2
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\6 Date: 7/3/2011 11 h 24 m User:morisseau
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL2
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 54 m User:meme
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 22/2/2011 17 h 51 m User:morisseau
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 22/2/2011 16 h 56 m User:morisseau
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 22 m User:morisseau
*    TWK_model:VSSP_Position_Pedale_Sl_L01_010_IMPL1
*    comments :add model
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 11/1/2011 16 h 42 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSSp
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSSp.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxDVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxVSLim;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxVSMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rAccPMaxVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPDVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPTra;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSLim;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_rAccPVSReg; /* BIN0 */
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"

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
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSReg; /* BIN7 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPMinVSLim_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPMinVSMax_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMinDVSReg_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMinVSReg_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPTraMaxDVSReg_C = (CONST(UInt16, AUTOMATIC))(0.038 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPTraMaxVSLim_C = (CONST(UInt16, AUTOMATIC))(0.038 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPTraMaxVSMax_C = (CONST(UInt16, AUTOMATIC))(0.038 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPTraMaxVSReg_C = (CONST(UInt16, AUTOMATIC))(0.038 * DEC3);
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSSP_START_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSReg_M
[VSSP_16_SIZE][VSSP_16_SIZE] = {
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehE_rAccPTrMxVSRegX_A[VSSP_16_SIZE] = {
(SInt16)(-255 * BIN7), (SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7),
(SInt16)(-10 * BIN7), (SInt16)(-7.5 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(5 * BIN7), (SInt16)(7.5 * BIN7),
(SInt16)(10 * BIN7), (SInt16)(15 * BIN7), (SInt16)(20 * BIN7),
(SInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPTraMxVSRegY_A[VSSP_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(70 * BIN7),
(UInt16)(80 * BIN7), (UInt16)(90 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(110 * BIN7), (UInt16)(120 * BIN7), (UInt16)(130 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(180 * BIN7), (UInt16)(200 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxDVSReg_M
[VSSP_16_SIZE][VSSP_16_SIZE] = {
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVeh_rAccPTraMaxDVSRegX_A[VSSP_16_SIZE] = {
(SInt16)(-10 * BIN10), (SInt16)(-2 * BIN10), (SInt16)(-1.5 * BIN10),
(SInt16)(-1 * BIN10), (SInt16)(-0.75 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.099609375 * BIN10), (SInt16)(-0.0498046875 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0.099609375 * BIN10), (SInt16)(0.5 * BIN10),
(SInt16)(0.75 * BIN10), (SInt16)(1 * BIN10), (SInt16)(1.5 * BIN10),
(SInt16)(2 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPTrMxDVSRegY_A[VSSP_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(70 * BIN7),
(UInt16)(80 * BIN7), (UInt16)(90 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(110 * BIN7), (UInt16)(120 * BIN7), (UInt16)(130 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(180 * BIN7), (UInt16)(200 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSLim_M
[VSSP_16_SIZE][VSSP_16_SIZE] = {
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehE_rAccPTrMxVSLimX_A[VSSP_16_SIZE] = {
(SInt16)(-255 * BIN7), (SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7),
(SInt16)(-10 * BIN7), (SInt16)(-7.5 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(5 * BIN7), (SInt16)(7.5 * BIN7),
(SInt16)(10 * BIN7), (SInt16)(15 * BIN7), (SInt16)(20 * BIN7),
(SInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPTraMxVSLimY_A[VSSP_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(70 * BIN7),
(UInt16)(80 * BIN7), (UInt16)(90 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(110 * BIN7), (UInt16)(120 * BIN7), (UInt16)(130 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(180 * BIN7), (UInt16)(200 * BIN7),
(UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSMax_M
[VSSP_16_SIZE][VSSP_16_SIZE] = {
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(90 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(90 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehE_rAccPTrMxVSMaxX_A[VSSP_16_SIZE] = {
(SInt16)(-255 * BIN7), (SInt16)(-20 * BIN7), (SInt16)(-15 * BIN7),
(SInt16)(-10 * BIN7), (SInt16)(-7.5 * BIN7), (SInt16)(-5 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(-0.5 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(5 * BIN7), (SInt16)(7.5 * BIN7),
(SInt16)(10 * BIN7), (SInt16)(15 * BIN7), (SInt16)(20 * BIN7),
(SInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPTraMxVSMaxY_A[VSSP_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(70 * BIN7),
(UInt16)(80 * BIN7), (UInt16)(90 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(110 * BIN7), (UInt16)(120 * BIN7), (UInt16)(130 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(180 * BIN7), (UInt16)(200 * BIN7),
(UInt16)(255 * BIN7)
};

#define VSSP_STOP_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccptramaxvsreg_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccptramaxdvsreg_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccptramaxvslim_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccptramaxvsmax_m_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72322_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72332_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72342_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72352_filter_str;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMinVSReg; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMinDVSReg; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxDVSReg; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSLim; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMinVSLim; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMaxVSMax; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rAccPTraMinVSMax; /* BIN7 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSSP_START_SEC_CONST_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPTRAMAXVSREG_M_APM = {
&vsctl_raccptramaxvsreg_m_sav,
VSSP_16_SIZE,
VSSP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVehE_rAccPTrMxVSRegX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPTraMxVSRegY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPTraMaxVSReg_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPTRAMAXDVSREG_M_APM = {
&vsctl_raccptramaxdvsreg_m_sav,
VSSP_16_SIZE,
VSSP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVeh_rAccPTraMaxDVSRegX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPTrMxDVSRegY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPTraMaxDVSReg_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPTRAMAXVSLIM_M_APM = {
&vsctl_raccptramaxvslim_m_sav,
VSSP_16_SIZE,
VSSP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVehE_rAccPTrMxVSLimX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPTraMxVSLimY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPTraMaxVSLim_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPTRAMAXVSMAX_M_APM = {
&vsctl_raccptramaxvsmax_m_sav,
VSSP_16_SIZE,
VSSP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVehE_rAccPTrMxVSMaxX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPTraMxVSMaxY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPTraMaxVSMax_M[0][0]
};

#define VSSP_STOP_SEC_CONST_UNSPECIFIED
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

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
* Function Name : VSSP_F7232_Determiner_Position_Pedale_Accelerateur_Reconstruite_Anticipee
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_RVV(
                                                SInt16 VSCtl_spdVehErrVSReg_swc_in,
                                                UInt16 AccP_rAccP_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.114.0 */
    UInt16 vssp_map_out;
    UInt16 vssp_filter_out;

    /* BIN7:[0;100] % */
    vssp_map_out = DDS_M_MAP3D_SUU16(&VSCTL_RACCPTRAMAXVSREG_M_APM,VSCtl_spdVehErrVSReg_swc_in,VSCtl_spdVeh_swc_in);

    if((UInt32)VSCtl_bAcvFil_rAccPMaxVSReg != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f72322_filter_str, vssp_map_out, VSCtl_tiFil_rAccPTraMaxVSReg_C, DEC3);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f72322_filter_str, vssp_map_out);
    }

    if((UInt32)VSCtl_stCtl_rAccPVSReg == VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
    {
        VSCtl_rAccPTraMinVSReg = VSCtl_rAccPTraMinVSReg_C;
        VSCtl_rAccPTraMaxVSReg = (UInt16)DDS_M_MAX((UInt32)AccP_rAccP_swc_in,(UInt32)vssp_filter_out);
    }
    else if((UInt32)VSCtl_stCtl_rAccPVSReg == VSSP_VSCTL_STTQWHLPTMINSAT_TRANSITION)
    {
        VSCtl_rAccPTraMinVSReg = VSCtl_rAccPTraMinVSReg_C;
        VSCtl_rAccPTraMaxVSReg = (UInt16)DDS_M_MAX((UInt32)AccP_rAccP_swc_in,(UInt32)VSCtl_rAccPTraMaxVSReg);
    }
    else
    {
        VSCtl_rAccPTraMinVSReg = (UInt16)(0 * BIN7);
        VSCtl_rAccPTraMaxVSReg = (UInt16)(100 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_Rvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72332_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_ACC(
                                                SInt16 VSCtl_aVehDVSRegReq_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.118.0 */
    UInt16 vssp_map_out;
    UInt16 vssp_filter_out;

    /* BIN7:[0;100] % */
    vssp_map_out = DDS_M_MAP3D_SUU16(&VSCTL_RACCPTRAMAXDVSREG_M_APM,VSCtl_aVehDVSRegReq_swc_in,VSCtl_spdVeh_swc_in);

    if((UInt32)VSCtl_bAcvFil_rAccPMaxDVSReg != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f72332_filter_str, vssp_map_out, VSCtl_tiFil_rAccPTraMaxDVSReg_C, DEC3);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f72332_filter_str, vssp_map_out);
    }

    if((UInt32)VSCtl_stCtl_rAccPDVSReg == (UInt32)DDS_TRUE)
    {
        VSCtl_rAccPTraMinDVSReg = VSCtl_rAccPTraMinDVSReg_C;
        VSCtl_rAccPTraMaxDVSReg = vssp_filter_out;
    }
    else
    {
        VSCtl_rAccPTraMinDVSReg = (UInt16)(0 * BIN7);
        VSCtl_rAccPTraMaxDVSReg = (UInt16)(100 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_Acc
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_LVV(
                                                SInt16 VSCtl_spdVehErrVSLim_swc_in,
                                                UInt16 AccP_rAccP_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.122.0 */
    UInt16 vssp_map_out;
    UInt16 vssp_filter_out;

    /* BIN7:[0;100] % */
    vssp_map_out = DDS_M_MAP3D_SUU16(&VSCTL_RACCPTRAMAXVSLIM_M_APM,VSCtl_spdVehErrVSLim_swc_in,VSCtl_spdVeh_swc_in);

    if((UInt32)VSCtl_bAcvFil_rAccPMaxVSLim != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f72342_filter_str, vssp_map_out, VSCtl_tiFil_rAccPTraMaxVSLim_C, DEC3);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f72342_filter_str, vssp_map_out);
    }

    if((UInt32)VSCtl_stCtl_rAccPVSLim == (UInt32)DDS_TRUE)
    {
        VSCtl_rAccPTraMinVSLim = (UInt16)DDS_M_MIN((UInt32)VSCtl_rAccPMinVSLim_C,(UInt32)AccP_rAccP_swc_in);
        VSCtl_rAccPTraMaxVSLim = vssp_filter_out;
    }
    else
    {
        VSCtl_rAccPTraMinVSLim = (UInt16)(0 * BIN7);
        VSCtl_rAccPTraMaxVSLim = (UInt16)(100 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_Lvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV(
                                                SInt16 VSCtl_spdVehErrVSMax_swc_in,
                                                UInt16 AccP_rAccP_swc_in,
                                                UInt16 VSCtl_spdVeh_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.126.0 */
    UInt16 vssp_map_out;
    UInt16 vssp_filter_out;

    /* BIN7:[0;100] % */
    vssp_map_out = DDS_M_MAP3D_SUU16(&VSCTL_RACCPTRAMAXVSMAX_M_APM,VSCtl_spdVehErrVSMax_swc_in,VSCtl_spdVeh_swc_in);

    if((UInt32)VSCtl_bAcvFil_rAccPMaxVSMax != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f72352_filter_str, vssp_map_out, VSCtl_tiFil_rAccPTraMaxVSMax_C, DEC3);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f72352_filter_str, vssp_map_out);
    }

    if((UInt32)VSCtl_stCtl_rAccPVSMax == (UInt32)DDS_TRUE)
    {
        VSCtl_rAccPTraMinVSMax = (UInt16)DDS_M_MIN((UInt32)VSCtl_rAccPMinVSMax_C,(UInt32)AccP_rAccP_swc_in);
        VSCtl_rAccPTraMaxVSMax = vssp_filter_out;
    }
    else
    {
        VSCtl_rAccPTraMinVSMax = (UInt16)(0 * BIN7);
        VSCtl_rAccPTraMaxVSMax = (UInt16)(100 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F7236_Determiner_Position_Pedales_Tramsmission_XVV
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F7236_Determiner_Position_Pedales_Tramsmission_XVV(
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMax_swc_out, /* BIN7 */
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMin_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.128.1 */
    UInt32 vssp_temp_u32;

    if((UInt32)VSCtl_stCtl_rAccPTra == (UInt32)DDS_TRUE)
    {
        vssp_temp_u32 = DDS_M_MIN((UInt32)VSCtl_rAccPTraMaxVSReg,(UInt32)VSCtl_rAccPTraMaxDVSReg);
        vssp_temp_u32 = DDS_M_MIN(vssp_temp_u32,(UInt32)VSCtl_rAccPTraMaxVSLim);
        *VSCtl_rAccPTraMax_swc_out = (UInt16)DDS_M_MIN(vssp_temp_u32,(UInt32)VSCtl_rAccPTraMaxVSMax);

        vssp_temp_u32 = DDS_M_MAX((UInt32)VSCtl_rAccPTraMinVSReg,(UInt32)VSCtl_rAccPTraMinDVSReg);
        vssp_temp_u32 = DDS_M_MAX(vssp_temp_u32,(UInt32)VSCtl_rAccPTraMinVSLim);
        *VSCtl_rAccPTraMin_swc_out = (UInt16)DDS_M_MAX(vssp_temp_u32,(UInt32)VSCtl_rAccPTraMinVSMax);
    }
    else
    {
        *VSCtl_rAccPTraMax_swc_out = (UInt16)(100 * BIN7);
        *VSCtl_rAccPTraMin_swc_out = (UInt16)(0 * BIN7);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Position_Pedale_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Position_Pedale_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMax_swc_out, /* BIN7 */
                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPTraMin_swc_out /* BIN7 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_rAccPTraMax_swc_out = (UInt16)(100 * BIN7);
    *VSCtl_rAccPTraMin_swc_out = (UInt16)(0 * BIN7);

    VSCtl_rAccPTraMaxVSReg = (UInt16)(100 * BIN7);

    /* ---- Init Global Datas ---- */
    VSCtl_rAccPTraMaxDVSReg = (UInt16)(100 * BIN7);
    VSCtl_rAccPTraMaxVSLim = (UInt16)(100 * BIN7);
    VSCtl_rAccPTraMaxVSMax = (UInt16)(100 * BIN7);
    VSCtl_rAccPTraMinDVSReg = (UInt16)(0 * BIN7);
    VSCtl_rAccPTraMinVSLim = (UInt16)(0 * BIN7);
    VSCtl_rAccPTraMinVSMax = (UInt16)(0 * BIN7);
    VSCtl_rAccPTraMinVSReg = (UInt16)(0 * BIN7);

    /* ---- VSSP_F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_Rvv ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f72322_filter_str, 0);

    /* ---- VSSP_F72322_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_Acc ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f72332_filter_str, 0);

    /* ---- VSSP_F72342_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_Lvv ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f72342_filter_str, 0);

    /* ---- VSSP_F72352_Calculer_Saturation_Position_Pedale_Accelerateur_Transmission_BVV ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f72352_filter_str, 0);

    /* ---- VSSP_F7236_Determiner_Position_Pedales_Tramsmission_XVV ---- */
}

#define VSSP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSSp_MemMap.h"

