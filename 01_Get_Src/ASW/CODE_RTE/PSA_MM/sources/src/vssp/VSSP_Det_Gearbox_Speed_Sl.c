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
* Ref X:\integration_view_00PSASWC_D820D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Det_Gearbox_Speed_Sl.c
* Version int :/main/L03_01/1 Date: 6/1/2012 11 h 11 m User:esnault 
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L03_010_IMPL2
*    comments :For VSSp_12_0_e6, correction for UT
* Version dev :\main\branch_demezil_vssp_view\3 Date: 13/12/2011 16 h 42 m User:halouane 
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L03_010_IMPL2
*    comments :For VSSp_12_0_e6, correction for UT
* Version dev :\main\branch_demezil_vssp_view\2 Date: 1/12/2011 10 h 49 m User:demezil
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L03_010_IMPL1
*    comments :for VSSp 12.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 29/11/2011 15 h 17 m User:demezil
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L03_010_IMPL1
*    comments :for VSSp 12.0
* Version int :/main/L02_01/1 Date: 7/9/2011 16 h 40 m User:esnault
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 26/7/2011 11 h 9 m User:demezil
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 21/7/2011 16 h 17 m User:demezil
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1_D
*    comments :for VSSp 11.0
* Version int :/main/L01_01/2 Date: 16/3/2011 11 h 48 m User:esnault
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 3/3/2011 11 h 11 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 53 m User:meme
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 17/2/2011 18 h 13 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 21 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Speed_Sl_L01_010_IMPL1
*    comments :add model
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 11/1/2011 16 h 41 m User:morisseau
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

#define VSSP_0                  (0)
#define VSSP_2000_BIN1          (2000 * BIN1)
#define VSSP_7500_BIN0          (7500 * BIN0)
#define VSSP_16000_BIN1         (16000 * BIN1)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_dtqWhlPTPotReq; /* BIN1 */
extern VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnIntReq; /* DEC2 */
extern VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupIntReq; /* DEC2 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxIntReq; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinIntReq; /* BIN1 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
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
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnReqTqNeg; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnReqTqPos; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupReqTqNeg; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupReqTqPos; /* DEC2 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear2Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear3Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear4Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear5Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear6Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear7Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear8Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear2Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear3Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear4Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear5Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear6Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear7Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear8Thd; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxIntNegReq; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxIntPosReq; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinIntNegReq; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinIntPosReq; /* BIN1 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_noGearMax; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_noGearTqNegMin; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_noGearTqPosMin; /* BIN0 */
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 32-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_32BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear2MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(152.4375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear2MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(146.34375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear2MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(152.4375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear2MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(146.34375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear3MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(231.484375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear3MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(222.21875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear3MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(231.484375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear3MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(222.21875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear4MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(312.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear4MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(300 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear4MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(312.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear4MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(300 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear5MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(419.4609375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear5MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(402.6875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear5MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(419.4609375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear5MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(402.6875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear6MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(525.2109375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear6MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(504.203125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear6MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(525.2109375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear6MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(504.203125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear7MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear7MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(600 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear7MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear7MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(600 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear8MaxAbsHi_C = (CONST(UInt32, AUTOMATIC))(833.33 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear8MaxAbsLo_C = (CONST(UInt32, AUTOMATIC))(800 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear8MaxCtfHi_C = (CONST(UInt32, AUTOMATIC))(833.33 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlGear8MaxCtfLo_C = (CONST(UInt32, AUTOMATIC))(800 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(346.0234375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(342.5625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(242.2109375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(238.7578125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(346.0234375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(342.5625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(242.2109375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear1PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(238.7578125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(609.7578125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(603.65625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(426.828125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(420.734375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(609.7578125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(603.65625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(426.828125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear2PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(420.734375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(925.9296875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(916.6640625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(648.1484375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(638.890625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(925.9296875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(916.6640625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(648.1484375 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear3PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(638.890625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(1250 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(1237.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(862.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(1250 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(1237.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(875 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear4PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(862.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(1677.8515625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(1661.0703125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(1174.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(238.7578125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(1677.8515625 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(1661.0703125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(1174.5 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear5PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(238.7578125 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(2100 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(2080 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(1470 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(1450 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(2100 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(2080 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(1470 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear6PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(1450 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7NegMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(2500 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7NegMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(2475 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7NegMinCftHi_C = (CONST(UInt32, AUTOMATIC))(1750 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7NegMinCftLo_C = (CONST(UInt32, AUTOMATIC))(1725 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7PosMinAbsHi_C = (CONST(UInt32, AUTOMATIC))(2500 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7PosMinAbsLo_C = (CONST(UInt32, AUTOMATIC))(2475 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7PosMinCftHi_C = (CONST(UInt32, AUTOMATIC))(1750 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nWhlGear7PosMinCftLo_C = (CONST(UInt32, AUTOMATIC))(1725 * BIN7);
#define VSSP_STOP_SEC_CALIB_32BIT
#include "VSSp_MemMap.h"

/* 16-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear2_C = (CONST(UInt16, AUTOMATIC))(8.203125 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear3_C = (CONST(UInt16, AUTOMATIC))(5.3984375 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear4_C = (CONST(UInt16, AUTOMATIC))(4 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear5_C = (CONST(UInt16, AUTOMATIC))(2.9765625 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear6_C = (CONST(UInt16, AUTOMATIC))(2.3828125 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear7_C = (CONST(UInt16, AUTOMATIC))(2 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTra_gear8_C = (CONST(UInt16, AUTOMATIC))(1.5 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlErr_gearDownNeg_C = (CONST(SInt16, AUTOMATIC))(-5 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlErr_gearDownPos_C = (CONST(SInt16, AUTOMATIC))(5 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlErr_gearUpNeg_C = (CONST(SInt16, AUTOMATIC))(5 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlErr_gearUpPos_C = (CONST(SInt16, AUTOMATIC))(-5 * BIN1);
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxAL4_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxAx6_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxAuto1_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxDCT_C = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxMCP_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxMAP_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxPilote1_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearMaxBVM_C = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
#define VSSP_STOP_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSSP_START_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMax_T
[VSSP_8_SIZE] = {
(SInt16)(117.625 * BIN4), (SInt16)(140 * BIN4), (SInt16)(160 * BIN4),
(SInt16)(180 * BIN4), (SInt16)(200 * BIN4), (SInt16)(230 * BIN4),
(SInt16)(250 * BIN4), (SInt16)(250 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEng_tqCkEfc_A[VSSP_8_SIZE] = {
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2000 * BIN0),
(UInt16)(2700 * BIN0), (UInt16)(3000 * BIN0), (UInt16)(3500 * BIN0),
(UInt16)(4000 * BIN0), (UInt16)(5000 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMin_T
[VSSP_8_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4),
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4),
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupnEngTqPos_T
[VSSP_8_SIZE] = {
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEng_tiCfmSupTqPos_A[VSSP_8_SIZE] = {
(UInt16)(600 * BIN0), (UInt16)(650 * BIN0), (UInt16)(700 * BIN0),
(UInt16)(750 * BIN0), (UInt16)(2000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5500 * BIN0), (UInt16)(6000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupTqWhlTqPos_M
[VSSP_8_SIZE][VSSP_8_SIZE] = {
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tq_tiCfmSdwnTqWhlTqPosX_A[VSSP_8_SIZE] = {
(SInt16)(-4000 * BIN1), (SInt16)(-2000 * BIN1), (SInt16)(-100 * BIN1),
(SInt16)(0 * BIN1), (SInt16)(600 * BIN1), (SInt16)(2000 * BIN1),
(SInt16)(4000 * BIN1), (SInt16)(11000 * BIN1)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tq_tiCfmSupTqWhlTqPosX_A[VSSP_8_SIZE] = {
(SInt16)(-4000 * BIN1), (SInt16)(-2000 * BIN1), (SInt16)(-100 * BIN1),
(SInt16)(0 * BIN1), (SInt16)(600 * BIN1), (SInt16)(2000 * BIN1),
(SInt16)(4000 * BIN1), (SInt16)(11000 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnnEngTqPos_T
[VSSP_8_SIZE] = {
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_dtq_tiCfmSdwnTqWhlTqP_Y_A[VSSP_8_SIZE] = {
(SInt16)(-100 * BIN1), (SInt16)(-50 * BIN1), (SInt16)(-20 * BIN1),
(SInt16)(0 * BIN1), (SInt16)(10 * BIN1), (SInt16)(20 * BIN1),
(SInt16)(50 * BIN1), (SInt16)(100 * BIN1)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_dtq_tiCfmSupTqWhlTqPosY_A[VSSP_8_SIZE] = {
(SInt16)(-100 * BIN1), (SInt16)(-50 * BIN1), (SInt16)(-20 * BIN1),
(SInt16)(0 * BIN1), (SInt16)(10 * BIN1), (SInt16)(20 * BIN1),
(SInt16)(50 * BIN1), (SInt16)(100 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnTqWhlTqPos_M
[VSSP_8_SIZE][VSSP_8_SIZE] = {
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) },
{
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2), (UInt16)(3 * DEC2),
(UInt16)(3 * DEC2), (UInt16)(3 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEng_tiCfmSdwnTqPos_A[VSSP_8_SIZE] = {
(UInt16)(600 * BIN0), (UInt16)(650 * BIN0), (UInt16)(700 * BIN0),
(UInt16)(750 * BIN0), (UInt16)(2000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5500 * BIN0), (UInt16)(6000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmGearDownPotNeg_T
[VSSP_8_SIZE] = {
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmGearUpPotNeg_T
[VSSP_8_SIZE] = {
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEng_tiCfmGear_A[VSSP_8_SIZE] = {
(UInt16)(600 * BIN0), (UInt16)(650 * BIN0), (UInt16)(700 * BIN0),
(UInt16)(750 * BIN0), (UInt16)(2000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5500 * BIN0), (UInt16)(6000 * BIN0)
};

#define VSSP_STOP_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tqckefcmax_t_sav[VSSP_7_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tqckefcmin_t_sav[VSSP_7_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_ticfmsupnengtqpos_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsuptqwhltqpos_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_ticfmsdwnnengtqpos_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_ticfmsdwntqwhltqpos_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_ticfmgeardownpotneg_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_ticfmgearuppotneg_t_sav;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos0_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos1_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos2_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos3_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos4_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos5_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos6_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos7_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos8_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos9_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos10_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos11_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos12_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72231_hyspos13_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos0_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos1_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos2_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos3_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos4_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos5_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos6_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos7_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos8_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos9_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos10_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos11_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos12_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72232_hyspos13_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos0_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos1_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos2_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos3_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos4_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos5_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos6_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos7_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos8_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos9_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos10_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos11_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos12_str;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) vssp_f72233_hyspos13_str;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear2; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear3; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear4; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear5; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear6; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear7; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_nEngGear8; /* BIN0 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear2; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear3; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear4; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear5; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear6; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear7; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirtGear8; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear2; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear3; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear4; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear5; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear6; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear7; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear8; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear2; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear3; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear4; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear5; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear6; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear7; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear8; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear2; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear3; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear4; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear5; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear6; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear7; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirtGear8; /* BIN4 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSSP_START_SEC_CONST_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_TQCKEFCMAX_T_APM[VSSP_7_SIZE] = {
{
&vsctl_tqckefcmax_t_sav[0],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
},
{
&vsctl_tqckefcmax_t_sav[1],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
},
{
&vsctl_tqckefcmax_t_sav[2],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
},
{
&vsctl_tqckefcmax_t_sav[3],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
},
{
&vsctl_tqckefcmax_t_sav[4],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
},
{
&vsctl_tqckefcmax_t_sav[5],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
},
{
&vsctl_tqckefcmax_t_sav[6],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMax_T[0]
}
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_TQCKEFCMIN_T_APM[VSSP_7_SIZE] = {
{
&vsctl_tqckefcmin_t_sav[0],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
},
{
&vsctl_tqckefcmin_t_sav[1],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
},
{
&vsctl_tqckefcmin_t_sav[2],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
},
{
&vsctl_tqckefcmin_t_sav[3],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
},
{
&vsctl_tqckefcmin_t_sav[4],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
},
{
&vsctl_tqckefcmin_t_sav[5],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
},
{
&vsctl_tqckefcmin_t_sav[6],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tqCkEfc_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMin_T[0]
}
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_TICFMSUPNENGTQPOS_T_APM = {
&vsctl_ticfmsupnengtqpos_t_sav,
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tiCfmSupTqPos_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSupnEngTqPos_T[0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_TICFMSUPTQWHLTQPOS_M_APM = {
&vsctl_ticfmsuptqwhltqpos_m_sav,
VSSP_8_SIZE,
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tq_tiCfmSupTqWhlTqPosX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_dtq_tiCfmSupTqWhlTqPosY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSupTqWhlTqPos_M[0][0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_TICFMSDWNNENGTQPOS_T_APM = {
&vsctl_ticfmsdwnnengtqpos_t_sav,
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tiCfmSdwnTqPos_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSdwnnEngTqPos_T[0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) VSCTL_TICFMSDWNTQWHLTQPOS_M_APM = {
&vsctl_ticfmsdwntqwhltqpos_m_sav,
VSSP_8_SIZE,
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tq_tiCfmSdwnTqWhlTqPosX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_dtq_tiCfmSdwnTqWhlTqP_Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmSdwnTqWhlTqPos_M[0][0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_TICFMGEARDOWNPOTNEG_T_APM = {
&vsctl_ticfmgeardownpotneg_t_sav,
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tiCfmGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmGearDownPotNeg_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_TICFMGEARUPPOTNEG_T_APM = {
&vsctl_ticfmgearuppotneg_t_sav,
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_tiCfmGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiCfmGearUpPotNeg_T[0]
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

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */



STATIC FUNC(void, AUTOMATIC) VSSP_F72231_Determiner_Rapport_Pilotable_Max(
                                                SInt8 copt_notargearcordit_par,
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                UInt8 ext_sttratypcf_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F72232_Determiner_Rapport_Pilotable_Min_Couple_Roue_Positif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                UInt8 ext_sttratypcf_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F72233_Determiner_Rapport_Pilotable_Min_Couple_Roue_Negatif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                UInt8 ext_sttratypcf_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F72241_Determiner_Regime_Moteur_Virtuel(
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F72242_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F722421_Determiner_Couple_Moteur_Max_Virtuel(
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F722422_Determiner_Couple_Roue_Gmp_Max(
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F722423_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F72243_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F722431_Determiner_Couple_Moteur_Min_Virtuel(
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F722432_Determiner_Couple_Roue_Gmp_Min(
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F722433_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt8 vsctl_stctl_nogear_par);

STATIC FUNC(void, AUTOMATIC) VSSP_F72251_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Positif(
                                                UInt32 vsctl_nengfil_par, /* BIN0 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                SInt16 vsctl_tqwhlptpotreq_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSSP_F72252_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Negatif(
                                                UInt32 vsctl_nengfil_par, /* BIN0 */
                                                UInt8 vsctl_stctl_nogear_par);

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
*
* Function Name : VSSP_F7222_Coordonner_Consignes_Potentiel_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F7222_Coordonner_Consignes_Potentiel_Couple_Roue_Gmp(
                                                UInt8 VSCtl_stCtl_noGear_swc_in,
                                                UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.75.1 */
    SInt16 vsctl_tqwhlpotmaxintreq_loc;
    SInt16 vsctl_tqwhlpotminintreq_loc;

    vsctl_tqwhlpotmaxintreq_loc = VSCtl_tqWhlPotMaxIntReq;
    vsctl_tqwhlpotminintreq_loc = VSCtl_tqWhlPotMinIntReq;

    if((UInt32)VSCtl_stCtl_noGear_swc_in == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        if((UInt32)VSCtl_stCtl_tqWhlPotMin_swc_in == VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
        {
            VSCtl_tqWhlPotMinIntPosReq = (SInt16)DDS_M_MAX((SInt32)vsctl_tqwhlpotminintreq_loc,VSSP_0);
            VSCtl_tqWhlPotMinIntNegReq = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_tqwhlpotminintreq_loc,-VSSP_16000_BIN1,VSSP_0);
        }
        else
        {
            VSCtl_tqWhlPotMinIntPosReq = (SInt16)(0 * BIN1);
            VSCtl_tqWhlPotMinIntNegReq = (SInt16)(0 * BIN1);
        }

        if((UInt32)VSCtl_stCtl_tqWhlPotMax_swc_in == VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
        {
            VSCtl_tqWhlPotMaxIntPosReq = (SInt16)DDS_M_MAX((SInt32)vsctl_tqwhlpotmaxintreq_loc,VSSP_0);
            VSCtl_tqWhlPotMaxIntNegReq = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_tqwhlpotmaxintreq_loc,-VSSP_16000_BIN1,VSSP_0);
        }
        else
        {
            VSCtl_tqWhlPotMaxIntPosReq = (SInt16)(16000 * BIN1);
            VSCtl_tqWhlPotMaxIntNegReq = (SInt16)(0 * BIN1);
        }
    }
    else
    {
        VSCtl_tqWhlPotMinIntPosReq = (SInt16)(0 * BIN1);
        VSCtl_tqWhlPotMinIntNegReq = (SInt16)(0 * BIN1);
        VSCtl_tqWhlPotMaxIntPosReq = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPotMaxIntNegReq = (SInt16)(0 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F7223_Determiner_Plage_Rapport_Pilotable
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F7223_Determiner_Plage_Rapport_Pilotable(
                                                SInt8 CoPt_noTarGearCordIt_swc_in,
                                                UInt32 VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                                                UInt8 VSCtl_stCtl_noGear_swc_in,
                                                UInt8 Ext_stTraTypCf_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.76.1 */
    VSSP_F72231_Determiner_Rapport_Pilotable_Max(
                   CoPt_noTarGearCordIt_swc_in,
                   VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                   VSCtl_stCtl_noGear_swc_in,
                   Ext_stTraTypCf_swc_in);

    VSSP_F72232_Determiner_Rapport_Pilotable_Min_Couple_Roue_Positif(
                   CoPt_noTarGearCordIt_swc_in,
                   VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                   VSCtl_stCtl_noGear_swc_in,
                   Ext_stTraTypCf_swc_in);

    VSSP_F72233_Determiner_Rapport_Pilotable_Min_Couple_Roue_Negatif(
                   CoPt_noTarGearCordIt_swc_in,
                   VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                   VSCtl_stCtl_noGear_swc_in,
                   Ext_stTraTypCf_swc_in);
}

/*******************************************************************************
*
* Function Name : VSSP_F72231_Determiner_Rapport_Pilotable_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72231_Determiner_Rapport_Pilotable_Max(
                                                SInt8 copt_notargearcordit_par,
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                UInt8 ext_sttratypcf_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.77.1 */
    UInt32 vss_uvalue;
    UInt32 vss_uvalue_2;
    UInt8 vssp_hyspos_out0;
    UInt8 vssp_hyspos_out1;
    UInt8 vssp_hyspos_out2;
    UInt8 vssp_hyspos_out3;
    UInt8 vssp_hyspos_out4;
    UInt8 vssp_hyspos_out5;
    UInt8 vssp_hyspos_out6;
    UInt8 vssp_hyspos_out7;
    UInt8 vssp_hyspos_out8;
    UInt8 vssp_hyspos_out9;
    UInt8 vssp_hyspos_out10;
    UInt8 vssp_hyspos_out11;
    UInt8 vssp_hyspos_out12;
    UInt8 vssp_hyspos_out13;

    vssp_hyspos_out0 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos0_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear6MaxCtfHi_C,VSCtl_nFrntWhlGear6MaxCtfLo_C);
    vssp_hyspos_out1 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos1_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear5MaxCtfHi_C,VSCtl_nFrntWhlGear5MaxCtfLo_C);
    vssp_hyspos_out2 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos2_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear4MaxCtfHi_C,VSCtl_nFrntWhlGear4MaxCtfLo_C);
    vssp_hyspos_out3 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos3_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear3MaxCtfHi_C,VSCtl_nFrntWhlGear3MaxCtfLo_C);
    vssp_hyspos_out4 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos4_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear2MaxCtfHi_C,VSCtl_nFrntWhlGear2MaxCtfLo_C);
    vssp_hyspos_out5 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos5_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear6MaxAbsHi_C,VSCtl_nFrntWhlGear6MaxAbsLo_C);
    vssp_hyspos_out6 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos6_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear5MaxAbsHi_C,VSCtl_nFrntWhlGear5MaxAbsLo_C);
    vssp_hyspos_out7 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos7_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear4MaxAbsHi_C,VSCtl_nFrntWhlGear4MaxAbsLo_C);
    vssp_hyspos_out8 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos8_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear3MaxAbsHi_C,VSCtl_nFrntWhlGear3MaxAbsLo_C);
    vssp_hyspos_out9 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos9_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear2MaxAbsHi_C,VSCtl_nFrntWhlGear2MaxAbsLo_C);
    vssp_hyspos_out10 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos10_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear8MaxCtfHi_C,VSCtl_nFrntWhlGear8MaxCtfLo_C);
    vssp_hyspos_out11 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos11_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear7MaxCtfHi_C,VSCtl_nFrntWhlGear7MaxCtfLo_C);
    vssp_hyspos_out12 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos12_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear8MaxAbsHi_C,VSCtl_nFrntWhlGear8MaxAbsLo_C);
    vssp_hyspos_out13 = DDS_M_HYST_PH_U32(&vssp_f72231_hyspos13_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nFrntWhlGear7MaxAbsHi_C,VSCtl_nFrntWhlGear7MaxAbsLo_C);

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        if((UInt32)vssp_hyspos_out10 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out11 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out0 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out1 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out2 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out3 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out4 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT;
        }
        else
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT;
        }
        vss_uvalue = (UInt32)DDS_M_MAX((SInt32)copt_notargearcordit_par,(SInt32)vss_uvalue);

        if((UInt32)vssp_hyspos_out12 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out13 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out5 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out6 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out7 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out8 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out9 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT;
        }
        else
        {
            /* In this specific case, MAX test is useless */
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT;
        }

        vss_uvalue = DDS_M_MIN(vss_uvalue,vss_uvalue_2);

        switch((UInt32)ext_sttratypcf_par)
        {
            case (UInt32)EXT_STTRATYPCF_BVM:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxBVM_C);
                break;

            case (UInt32)EXT_STTRATYPCF_XXX1PILOTE:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxPilote1_C);
                break;

            case (UInt32)EXT_STTRATYPCF_MAP:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxMAP_C);
                break;

            case (UInt32)EXT_STTRATYPCF_MCP:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxMCP_C);
                break;

            case (UInt32)EXT_STTRATYPCF_DCT:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxDCT_C);
                break;

            case (UInt32)EXT_STTRATYPCF_XXX1AUTO:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAuto1_C);
                break;

            case (UInt32)EXT_STTRATYPCF_AX6:
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAx6_C);
                break;

            default :
                VSCtl_noGearMax = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAL4_C);
                break;
        }
    }
    else
    {
        VSCtl_noGearMax = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72232_Determiner_Rapport_Pilotable_Min_Couple_Roue_Positif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72232_Determiner_Rapport_Pilotable_Min_Couple_Roue_Positif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                UInt8 ext_sttratypcf_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.78.1 */
    UInt32 vss_uvalue;
    UInt32 vss_uvalue_2;
    UInt8 vssp_hyspos_out0;
    UInt8 vssp_hyspos_out1;
    UInt8 vssp_hyspos_out2;
    UInt8 vssp_hyspos_out3;
    UInt8 vssp_hyspos_out4;
    UInt8 vssp_hyspos_out5;
    UInt8 vssp_hyspos_out6;
    UInt8 vssp_hyspos_out7;
    UInt8 vssp_hyspos_out8;
    UInt8 vssp_hyspos_out9;
    UInt8 vssp_hyspos_out10;
    UInt8 vssp_hyspos_out11;
    UInt8 vssp_hyspos_out12;
    UInt8 vssp_hyspos_out13;

    vssp_hyspos_out0 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos0_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear5PosMinCftHi_C,VSCtl_nWhlGear5PosMinCftLo_C);
    vssp_hyspos_out1 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos1_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear4PosMinCftHi_C,VSCtl_nWhlGear4PosMinCftLo_C);
    vssp_hyspos_out2 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos2_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear3PosMinCftHi_C,VSCtl_nWhlGear3PosMinCftLo_C);
    vssp_hyspos_out3 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos3_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear2PosMinCftHi_C,VSCtl_nWhlGear2PosMinCftLo_C);
    vssp_hyspos_out4 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos4_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear1PosMinCftHi_C,VSCtl_nWhlGear1PosMinCftLo_C);
    vssp_hyspos_out5 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos5_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear5PosMinAbsHi_C,VSCtl_nWhlGear5PosMinAbsLo_C);
    vssp_hyspos_out6 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos6_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear4PosMinAbsHi_C,VSCtl_nWhlGear4PosMinAbsLo_C);
    vssp_hyspos_out7 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos7_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear3PosMinAbsHi_C,VSCtl_nWhlGear3PosMinAbsLo_C);
    vssp_hyspos_out8 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos8_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear2PosMinAbsHi_C,VSCtl_nWhlGear2PosMinAbsLo_C);
    vssp_hyspos_out9 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos9_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear1PosMinAbsHi_C,VSCtl_nWhlGear1PosMinAbsLo_C);
    vssp_hyspos_out10 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos10_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear7PosMinCftHi_C,VSCtl_nWhlGear7PosMinCftLo_C);
    vssp_hyspos_out11 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos11_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear6PosMinCftHi_C,VSCtl_nWhlGear6PosMinCftLo_C);
    vssp_hyspos_out12 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos12_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear7PosMinAbsHi_C,VSCtl_nWhlGear7PosMinAbsLo_C);
    vssp_hyspos_out13 = DDS_M_HYST_PH_U32(&vssp_f72232_hyspos13_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear6PosMinAbsHi_C,VSCtl_nWhlGear6PosMinAbsLo_C);

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        if((UInt32)vssp_hyspos_out10 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out11 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out0 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out1 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out2 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out3 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out4 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT;
        }
        else
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT;
        }
        vss_uvalue = (UInt32)DDS_M_MIN((SInt32)copt_notargearcordit_par,(SInt32)vss_uvalue);

        if((UInt32)vssp_hyspos_out12 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out13 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out5 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out6 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out7 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out8 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out9 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT;
        }
        else
        {
            /* In this specific case, MAX test is useless */
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT;
        }

        vss_uvalue = DDS_M_MAX(vss_uvalue,vss_uvalue_2);

        switch((UInt32)ext_sttratypcf_par)
        {
            case (UInt32)EXT_STTRATYPCF_BVM:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxBVM_C);
                break;

            case (UInt32)EXT_STTRATYPCF_XXX1PILOTE:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxPilote1_C);
                break;

            case (UInt32)EXT_STTRATYPCF_MAP:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxMAP_C);
                break;

            case (UInt32)EXT_STTRATYPCF_MCP:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxMCP_C);
                break;

            case (UInt32)EXT_STTRATYPCF_DCT:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxDCT_C);
                break;

            case (UInt32)EXT_STTRATYPCF_XXX1AUTO:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAuto1_C);
                break;

            case (UInt32)EXT_STTRATYPCF_AX6:
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAx6_C);
                break;

            default :
                VSCtl_noGearTqPosMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAL4_C);
                break;
        }
    }
    else
    {
        VSCtl_noGearTqPosMin = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72233_Determiner_Rapport_Pilotable_Min_Couple_Roue_Negatif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72233_Determiner_Rapport_Pilotable_Min_Couple_Roue_Negatif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                UInt8 ext_sttratypcf_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.79.1 */
    UInt32 vss_uvalue;
    UInt32 vss_uvalue_2;
    UInt8 vssp_hyspos_out0;
    UInt8 vssp_hyspos_out1;
    UInt8 vssp_hyspos_out2;
    UInt8 vssp_hyspos_out3;
    UInt8 vssp_hyspos_out4;
    UInt8 vssp_hyspos_out5;
    UInt8 vssp_hyspos_out6;
    UInt8 vssp_hyspos_out7;
    UInt8 vssp_hyspos_out8;
    UInt8 vssp_hyspos_out9;
    UInt8 vssp_hyspos_out10;
    UInt8 vssp_hyspos_out11;
    UInt8 vssp_hyspos_out12;
    UInt8 vssp_hyspos_out13;

    vssp_hyspos_out0 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos0_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear5NegMinCftHi_C,VSCtl_nWhlGear5NegMinCftLo_C);
    vssp_hyspos_out1 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos1_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear4NegMinCftHi_C,VSCtl_nWhlGear4NegMinCftLo_C);
    vssp_hyspos_out2 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos2_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear3NegMinCftHi_C,VSCtl_nWhlGear3NegMinCftLo_C);
    vssp_hyspos_out3 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos3_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear2NegMinCftHi_C,VSCtl_nWhlGear2NegMinCftLo_C);
    vssp_hyspos_out4 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos4_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear1NegMinCftHi_C,VSCtl_nWhlGear1NegMinCftLo_C);
    vssp_hyspos_out5 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos5_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear5NegMinAbsHi_C,VSCtl_nWhlGear5NegMinAbsLo_C);
    vssp_hyspos_out6 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos6_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear4NegMinAbsHi_C,VSCtl_nWhlGear4NegMinAbsLo_C);
    vssp_hyspos_out7 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos7_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear3NegMinAbsHi_C,VSCtl_nWhlGear3NegMinAbsLo_C);
    vssp_hyspos_out8 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos8_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear2NegMinAbsHi_C,VSCtl_nWhlGear2NegMinAbsLo_C);
    vssp_hyspos_out9 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos9_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear1NegMinAbsHi_C,VSCtl_nWhlGear1NegMinAbsLo_C);
    vssp_hyspos_out10 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos10_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear7NegMinCftHi_C,VSCtl_nWhlGear7NegMinCftLo_C);
    vssp_hyspos_out11 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos11_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear6NegMinCftHi_C,VSCtl_nWhlGear6NegMinCftLo_C);
    vssp_hyspos_out12 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos12_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear7NegMinAbsHi_C,VSCtl_nWhlGear7NegMinAbsLo_C);
    vssp_hyspos_out13 = DDS_M_HYST_PH_U32(&vssp_f72233_hyspos13_str,
                                         vsctl_nfrntwhlfil_par,VSCtl_nWhlGear6NegMinAbsHi_C,VSCtl_nWhlGear6NegMinAbsLo_C);

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        if((UInt32)vssp_hyspos_out10 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out11 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out0 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out1 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out2 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out3 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out4 != (UInt32)DDS_FALSE)
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT;
        }
        else
        {
            vss_uvalue = VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT;
        }
        vss_uvalue = (UInt32)DDS_M_MIN((SInt32)copt_notargearcordit_par,(SInt32)vss_uvalue);

        if((UInt32)vssp_hyspos_out12 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out13 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out5 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out6 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out7 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out8 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT;
        }
        else if((UInt32)vssp_hyspos_out9 != (UInt32)DDS_FALSE)
        {
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT;
        }
        else
        {
            /* In this specific case, MAX test is useless */
            vss_uvalue_2 = VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT;
        }

        vss_uvalue = DDS_M_MAX(vss_uvalue,vss_uvalue_2);

        switch((UInt32)ext_sttratypcf_par)
        {
            case (UInt32)EXT_STTRATYPCF_BVM:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxBVM_C);
                break;

            case (UInt32)EXT_STTRATYPCF_XXX1PILOTE:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxPilote1_C);
                break;

            case (UInt32)EXT_STTRATYPCF_MAP:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxMAP_C);
                break;

            case (UInt32)EXT_STTRATYPCF_MCP:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxMCP_C);
                break;

            case (UInt32)EXT_STTRATYPCF_DCT:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxDCT_C);
                break;

            case (UInt32)EXT_STTRATYPCF_XXX1AUTO:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAuto1_C);
                break;

            case (UInt32)EXT_STTRATYPCF_AX6:
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAx6_C);
                break;

            default :
                VSCtl_noGearTqNegMin = (UInt8)DDS_M_MIN(vss_uvalue,(UInt32)VSCtl_noGearMaxAL4_C);
                break;
        }
    }
    else
    {
        VSCtl_noGearTqNegMin = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F7224_Determiner_Seuils_Changement_Rapport
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F7224_Determiner_Seuils_Changement_Rapport(
                                                SInt8 CoPt_noTarGearCordIt_swc_in,
                                                UInt32 VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                                                UInt8 VSCtl_stCtl_noGear_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.80.1 */
    VSSP_F72241_Determiner_Regime_Moteur_Virtuel(
                   VSCtl_nFrntWhlFil_swc_in, /* BIN7 */
                   VSCtl_stCtl_noGear_swc_in);

    VSSP_F72242_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif(
                   CoPt_noTarGearCordIt_swc_in,
                   VSCtl_stCtl_noGear_swc_in);

    VSSP_F72243_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif(
                   CoPt_noTarGearCordIt_swc_in,
                   VSCtl_stCtl_noGear_swc_in);
}

/*******************************************************************************
*
* Function Name : VSSP_F72241_Determiner_Regime_Moteur_Virtuel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72241_Determiner_Regime_Moteur_Virtuel(
                                                UInt32 vsctl_nfrntwhlfil_par, /* BIN7 */
                                                UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.81.1 */
    UInt32 vssp_uvalue;

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        /* BIN0 = BIN7 * BIN7 / BIN14 */
        /* [0;200000] = [0;10000] * [0;20] */

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear2_C) / BIN14;
        VSCtl_nEngGear2 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear3_C) / BIN14;
        VSCtl_nEngGear3 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear4_C) / BIN14;
        VSCtl_nEngGear4 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear5_C) / BIN14;
        VSCtl_nEngGear5 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear6_C) / BIN14;
        VSCtl_nEngGear6 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear7_C) / BIN14;
        VSCtl_nEngGear7 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);

        vssp_uvalue = (vsctl_nfrntwhlfil_par * (UInt32)VSCtl_rConvTra_gear8_C) / BIN14;
        VSCtl_nEngGear8 = (UInt16)DDS_M_MIN(vssp_uvalue,VSSP_7500_BIN0);
    }
    else
    {
        VSCtl_nEngGear2 = (UInt16)(0 * BIN0);
        VSCtl_nEngGear3 = (UInt16)(0 * BIN0);
        VSCtl_nEngGear4 = (UInt16)(0 * BIN0);
        VSCtl_nEngGear5 = (UInt16)(0 * BIN0);
        VSCtl_nEngGear6 = (UInt16)(0 * BIN0);
        VSCtl_nEngGear7 = (UInt16)(0 * BIN0);
        VSCtl_nEngGear8 = (UInt16)(0 * BIN0);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72242_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72242_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.82.1 */
    VSSP_F722421_Determiner_Couple_Moteur_Max_Virtuel(
                   vsctl_stctl_nogear_par);

    VSSP_F722422_Determiner_Couple_Roue_Gmp_Max(
                   vsctl_stctl_nogear_par);

    VSSP_F722423_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif(
                   copt_notargearcordit_par,
                   vsctl_stctl_nogear_par);
}

/*******************************************************************************
*
* Function Name : VSSP_F722421_Determiner_Couple_Moteur_Max_Virtuel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F722421_Determiner_Couple_Moteur_Max_Virtuel(
                   UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.83.1 */
    SInt16 vssp_map_out[VSSP_7_SIZE];

    /* BIN4:[-2000;2000] N.m */
    vssp_map_out[0] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[0],VSCtl_nEngGear2);
    vssp_map_out[1] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[1],VSCtl_nEngGear3);
    vssp_map_out[2] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[2],VSCtl_nEngGear4);
    vssp_map_out[3] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[3],VSCtl_nEngGear5);
    vssp_map_out[4] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[4],VSCtl_nEngGear6);
    vssp_map_out[5] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[5],VSCtl_nEngGear7);
    vssp_map_out[6] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMAX_T_APM[6],VSCtl_nEngGear8);

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        VSCtl_tqCkEfcMaxVirtGear2 = vssp_map_out[0];
        VSCtl_tqCkEfcMaxVirtGear3 = vssp_map_out[1];
        VSCtl_tqCkEfcMaxVirtGear4 = vssp_map_out[2];
        VSCtl_tqCkEfcMaxVirtGear5 = vssp_map_out[3];
        VSCtl_tqCkEfcMaxVirtGear6 = vssp_map_out[4];
        VSCtl_tqCkEfcMaxVirtGear7 = vssp_map_out[5];
        VSCtl_tqCkEfcMaxVirtGear8 = vssp_map_out[6];
    }
    else
    {
        VSCtl_tqCkEfcMaxVirtGear2 = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxVirtGear3 = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxVirtGear4 = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxVirtGear5 = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxVirtGear6 = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxVirtGear7 = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxVirtGear8 = (SInt16)(2000 * BIN4);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F722422_Determiner_Couple_Roue_Gmp_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F722422_Determiner_Couple_Roue_Gmp_Max(
                   UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.84.1 */
    SInt32 vssp_svalue;

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        /* BIN1 = BIN4 * BIN7 / BIN10 */
        /* [-40000;40000] = [-2000;2000] * [0;20] */

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear2 * (SInt32)VSCtl_rConvTra_gear2_C) / BIN10;
        VSCtl_tqWhlMaxGear2 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear3 * (SInt32)VSCtl_rConvTra_gear3_C) / BIN10;
        VSCtl_tqWhlMaxGear3 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear4 * (SInt32)VSCtl_rConvTra_gear4_C) / BIN10;
        VSCtl_tqWhlMaxGear4 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear5 * (SInt32)VSCtl_rConvTra_gear5_C) / BIN10;
        VSCtl_tqWhlMaxGear5 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear6 * (SInt32)VSCtl_rConvTra_gear6_C) / BIN10;
        VSCtl_tqWhlMaxGear6 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear7 * (SInt32)VSCtl_rConvTra_gear7_C) / BIN10;
        VSCtl_tqWhlMaxGear7 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirtGear8 * (SInt32)VSCtl_rConvTra_gear8_C) / BIN10;
        VSCtl_tqWhlMaxGear8 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlMaxGear2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear3 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear4 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear5 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear6 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear7 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear8 = (SInt16)(16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F722423_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F722423_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif(
                   SInt8 copt_notargearcordit_par,
                   UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.85.1 */
    SInt32 vssp_sum_gear2;
    SInt32 vssp_sum_gear3;
    SInt32 vssp_sum_gear4;
    SInt32 vssp_sum_gear5;
    SInt32 vssp_sum_gear6;
    SInt32 vssp_sum_gear7;
    SInt32 vssp_sum_gear8;

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        /* Saturation and decrement is implicitly done in switch case */
        switch((SInt32)copt_notargearcordit_par)
        {
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearDownPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT:
            default:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpPos_C + (SInt32)VSCtl_tqWhlMaxGear8;
                break;
        }
        VSCtl_tqWhlMaxGear2Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear2,VSSP_0,VSSP_16000_BIN1);
        VSCtl_tqWhlMaxGear3Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear3,VSSP_0,VSSP_16000_BIN1);
        VSCtl_tqWhlMaxGear4Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear4,VSSP_0,VSSP_16000_BIN1);
        VSCtl_tqWhlMaxGear5Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear5,VSSP_0,VSSP_16000_BIN1);
        VSCtl_tqWhlMaxGear6Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear6,VSSP_0,VSSP_16000_BIN1);
        VSCtl_tqWhlMaxGear7Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear7,VSSP_0,VSSP_16000_BIN1);
        VSCtl_tqWhlMaxGear8Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear8,VSSP_0,VSSP_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlMaxGear2Thd = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear3Thd = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear4Thd = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear5Thd = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear6Thd = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear7Thd = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlMaxGear8Thd = (SInt16)(16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72243_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72243_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif(
                                                SInt8 copt_notargearcordit_par,
                                                UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.86.1 */
    VSSP_F722431_Determiner_Couple_Moteur_Min_Virtuel(
                       vsctl_stctl_nogear_par);

    VSSP_F722432_Determiner_Couple_Roue_Gmp_Min(vsctl_stctl_nogear_par);

    VSSP_F722433_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif(
                       copt_notargearcordit_par,
                       vsctl_stctl_nogear_par);
}

/*******************************************************************************
*
* Function Name : VSSP_F722431_Determiner_Couple_Moteur_Min_Virtuel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F722431_Determiner_Couple_Moteur_Min_Virtuel(
                       UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.87.1 */
    SInt16 vssp_map_out[VSSP_7_SIZE];

    /* BIN4:[-2000;2000] N.m */
    vssp_map_out[0] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[0],VSCtl_nEngGear2);
    vssp_map_out[1] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[1],VSCtl_nEngGear3);
    vssp_map_out[2] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[2],VSCtl_nEngGear4);
    vssp_map_out[3] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[3],VSCtl_nEngGear5);
    vssp_map_out[4] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[4],VSCtl_nEngGear6);
    vssp_map_out[5] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[5],VSCtl_nEngGear7);
    vssp_map_out[6] = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMIN_T_APM[6],VSCtl_nEngGear8);

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        VSCtl_tqCkEfcMinVirtGear2 = vssp_map_out[0];
        VSCtl_tqCkEfcMinVirtGear3 = vssp_map_out[1];
        VSCtl_tqCkEfcMinVirtGear4 = vssp_map_out[2];
        VSCtl_tqCkEfcMinVirtGear5 = vssp_map_out[3];
        VSCtl_tqCkEfcMinVirtGear6 = vssp_map_out[4];
        VSCtl_tqCkEfcMinVirtGear7 = vssp_map_out[5];
        VSCtl_tqCkEfcMinVirtGear8 = vssp_map_out[6];
    }
    else
    {
        VSCtl_tqCkEfcMinVirtGear2 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinVirtGear3 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinVirtGear4 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinVirtGear5 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinVirtGear6 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinVirtGear7 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinVirtGear8 = (SInt16)(-2000 * BIN4);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F722432_Determiner_Couple_Roue_Gmp_Min
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F722432_Determiner_Couple_Roue_Gmp_Min(
                        UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.88.1 */
    SInt32 vssp_svalue;

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        /* BIN1 = BIN4 * BIN7 / BIN10 */
        /* [-40000;40000] = [-2000;2000] * [0;20] */

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear2 * (SInt32)VSCtl_rConvTra_gear2_C) / BIN10;
        VSCtl_tqWhlMinGear2 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear3 * (SInt32)VSCtl_rConvTra_gear3_C) / BIN10;
        VSCtl_tqWhlMinGear3 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear4 * (SInt32)VSCtl_rConvTra_gear4_C) / BIN10;
        VSCtl_tqWhlMinGear4 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear5 * (SInt32)VSCtl_rConvTra_gear5_C) / BIN10;
        VSCtl_tqWhlMinGear5 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear6 * (SInt32)VSCtl_rConvTra_gear6_C) / BIN10;
        VSCtl_tqWhlMinGear6 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear7 * (SInt32)VSCtl_rConvTra_gear7_C) / BIN10;
        VSCtl_tqWhlMinGear7 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);

        vssp_svalue = ((SInt32)VSCtl_tqCkEfcMinVirtGear8 * (SInt32)VSCtl_rConvTra_gear8_C) / BIN10;
        VSCtl_tqWhlMinGear8 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlMinGear2 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear3 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear4 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear5 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear6 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear7 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear8 = (SInt16)(-16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F722433_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F722433_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif(
                       SInt8 copt_notargearcordit_par,
                       UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.89.1 */
    SInt32 vssp_sum_gear2;
    SInt32 vssp_sum_gear3;
    SInt32 vssp_sum_gear4;
    SInt32 vssp_sum_gear5;
    SInt32 vssp_sum_gear6;
    SInt32 vssp_sum_gear7;
    SInt32 vssp_sum_gear8;

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        /* Saturation and decrement is implicitly done in switch case */
        switch((SInt32)copt_notargearcordit_par)
        {
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_2EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_3EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_4EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_5EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_6EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_7EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_8EME_RAPPORT:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearDownNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
            case (SInt32)VSSP_COPT_NOTARGEARCORDIT_1ER_RAPPORT:
            default:
                /* BIN1: [-32000;32000] */
                vssp_sum_gear2 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear2;
                vssp_sum_gear3 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear3;
                vssp_sum_gear4 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear4;
                vssp_sum_gear5 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear5;
                vssp_sum_gear6 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear6;
                vssp_sum_gear7 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear7;
                vssp_sum_gear8 = (SInt32)VSCtl_tqWhlErr_gearUpNeg_C + (SInt32)VSCtl_tqWhlMinGear8;
                break;
        }
        VSCtl_tqWhlMinGear2Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear2,-VSSP_16000_BIN1,VSSP_0);
        VSCtl_tqWhlMinGear3Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear3,-VSSP_16000_BIN1,VSSP_0);
        VSCtl_tqWhlMinGear4Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear4,-VSSP_16000_BIN1,VSSP_0);
        VSCtl_tqWhlMinGear5Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear5,-VSSP_16000_BIN1,VSSP_0);
        VSCtl_tqWhlMinGear6Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear6,-VSSP_16000_BIN1,VSSP_0);
        VSCtl_tqWhlMinGear7Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear7,-VSSP_16000_BIN1,VSSP_0);
        VSCtl_tqWhlMinGear8Thd = (SInt16)DDS_M_SATURATION_V2(vssp_sum_gear8,-VSSP_16000_BIN1,VSSP_0);
    }
    else
    {
        VSCtl_tqWhlMinGear2Thd = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear3Thd = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear4Thd = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear5Thd = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear6Thd = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear7Thd = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlMinGear8Thd = (SInt16)(-16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F7225_Determiner_Temps_Confirmation_Changement_Rapport
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F7225_Determiner_Temps_Confirmation_Changement_Rapport(
                                                UInt32 VSCtl_nEngFil_swc_in, /* BIN0 */
                                                UInt8 VSCtl_stCtl_noGear_swc_in,
                                                SInt16 VSCtl_tqWhlPTPotReq_swc_in /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.137.0 */
    VSSP_F72251_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Positif(
                   VSCtl_nEngFil_swc_in, /* BIN0 */
                   VSCtl_stCtl_noGear_swc_in,
                   VSCtl_tqWhlPTPotReq_swc_in /* BIN1 */);

    VSSP_F72252_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Negatif(
                   VSCtl_nEngFil_swc_in, /* BIN0 */
                   VSCtl_stCtl_noGear_swc_in);
}

/*******************************************************************************
*
* Function Name : VSSP_F72251_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Positif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72251_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Positif(
                                                UInt32 vsctl_nengfil_par, /* BIN0 */
                                                UInt8 vsctl_stctl_nogear_par,
                                                SInt16 vsctl_tqwhlptpotreq_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.91.0 */
    UInt32 vssp_tab_sup_out;
    UInt32 vssp_map_sup_out;
    UInt32 vssp_map_sdwn_out;
    UInt32 vssp_tab_sdwn_out;
    UInt32 vssp_uvalue;
    SInt16 vsctl_dtqwhlptpotreq_loc;

    vsctl_dtqwhlptpotreq_loc = VSCtl_dtqWhlPTPotReq;

    /* DEC2:[0;16] s */
    vssp_tab_sup_out = (UInt32)DDS_M_MAP2D_U16(&VSCTL_TICFMSUPNENGTQPOS_T_APM,(UInt16)vsctl_nengfil_par);
    vssp_map_sup_out = (UInt32)DDS_M_MAP3D_SSU16(&VSCTL_TICFMSUPTQWHLTQPOS_M_APM,vsctl_tqwhlptpotreq_par,vsctl_dtqwhlptpotreq_loc);
    vssp_map_sdwn_out = (UInt32)DDS_M_MAP3D_SSU16(&VSCTL_TICFMSDWNTQWHLTQPOS_M_APM,vsctl_tqwhlptpotreq_par,vsctl_dtqwhlptpotreq_loc);
    vssp_tab_sdwn_out = (UInt32)DDS_M_MAP2D_U16(&VSCTL_TICFMSDWNNENGTQPOS_T_APM,(UInt16)vsctl_nengfil_par);

    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        vssp_uvalue = DDS_M_MIN((UInt32)VSCtl_tiCfmSupIntReq,vssp_tab_sup_out);
        VSCtl_tiCfmSupReqTqPos = (UInt16)DDS_M_MIN(vssp_map_sup_out,vssp_uvalue);

        vssp_uvalue = DDS_M_MIN(vssp_map_sdwn_out,vssp_tab_sdwn_out);
        VSCtl_tiCfmSdwnReqTqPos = (UInt16)DDS_M_MIN((UInt32)VSCtl_tiCfmSdwnIntReq,vssp_uvalue);
    }
    else
    {
        VSCtl_tiCfmSupReqTqPos = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSdwnReqTqPos = (UInt16)(0 * DEC2);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72252_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Negatif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F72252_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Negatif(
                                                UInt32 vsctl_nengfil_par, /* BIN0 */
                                                UInt8 vsctl_stctl_nogear_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.92.0 */
    UInt32 vssp_map_up_out;
    UInt32 vssp_map_down_out;

    vssp_map_up_out = (UInt32)DDS_M_MAP2D_U16(&VSCTL_TICFMGEARUPPOTNEG_T_APM,(UInt16)vsctl_nengfil_par);
    vssp_map_down_out = (UInt32)DDS_M_MAP2D_U16(&VSCTL_TICFMGEARDOWNPOTNEG_T_APM,(UInt16)vsctl_nengfil_par);


    if((UInt32)vsctl_stctl_nogear_par == VSSP_VSCTL_STCTL_NOGEAR_CONTROLE)
    {
        VSCtl_tiCfmSupReqTqNeg = (UInt16)vssp_map_up_out;
        VSCtl_tiCfmSdwnReqTqNeg = (UInt16)vssp_map_down_out;
    }
    else
    {
        VSCtl_tiCfmSupReqTqNeg = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSdwnReqTqNeg = (UInt16)(0 * DEC2);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Det_Gearbox_Speed_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Speed_Sl_Init(void)
{
    /* ---- Init Outputs ---- */
    VSCtl_noGearMax = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    VSCtl_noGearTqNegMin = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
    VSCtl_noGearTqPosMin = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
    VSCtl_tiCfmSdwnReqTqNeg = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSdwnReqTqPos = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupReqTqNeg = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupReqTqPos = (UInt16)(0 * DEC2);
    VSCtl_tqWhlMaxGear2Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear3Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear4Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear5Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear6Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear7Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear8Thd = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMinGear2Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear3Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear4Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear5Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear6Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear7Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear8Thd = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPotMaxIntNegReq = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPotMaxIntPosReq = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPotMinIntNegReq = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPotMinIntPosReq = (SInt16)(0 * BIN1);

    /* ---- Init Global Datas ---- */

    /* ---- VSSP_F7222_Coordonner_Consignes_Potentiel_Couple_Roue_Gmp ---- */

    /* ---- VSSP_F7223_Determiner_Plage_Rapport_Pilotable ---- */

    /* ---- VSSP_F72231_Determiner_Rapport_Pilotable_Max ---- */
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos0_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos1_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos2_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos3_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos4_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos5_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos6_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos7_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos8_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos9_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos10_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos11_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos12_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72231_hyspos13_str,DDS_FALSE);

    /* ---- VSSP_F72232_Determiner_Rapport_Pilotable_Min_Couple_Roue_Positif ---- */
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos0_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos1_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos2_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos3_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos4_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos5_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos6_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos7_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos8_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos9_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos10_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos11_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos12_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72232_hyspos13_str,DDS_FALSE);

    /* ---- VSSP_F72233_Determiner_Rapport_Pilotable_Min_Couple_Roue_Negatif ---- */
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos0_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos1_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos2_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos3_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos4_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos5_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos6_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos7_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos8_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos9_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos10_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos11_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos12_str,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&vssp_f72233_hyspos13_str,DDS_FALSE);

    /* ---- VSSP_F7224_Determiner_Seuils_Changement_Rapport ---- */

    /* ---- VSSP_F72241_Determiner_Regime_Moteur_Virtuel ---- */
    VSCtl_nEngGear2 = (UInt16)(0 * BIN0);
    VSCtl_nEngGear3 = (UInt16)(0 * BIN0);
    VSCtl_nEngGear4 = (UInt16)(0 * BIN0);
    VSCtl_nEngGear5 = (UInt16)(0 * BIN0);
    VSCtl_nEngGear6 = (UInt16)(0 * BIN0);
    VSCtl_nEngGear7 = (UInt16)(0 * BIN0);
    VSCtl_nEngGear8 = (UInt16)(0 * BIN0);

    /* ---- VSSP_F72242_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif ---- */

    /* ---- VSSP_F722421_Determiner_Couple_Moteur_Max_Virtuel ---- */
    VSCtl_tqCkEfcMaxVirtGear2 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxVirtGear3 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxVirtGear4 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxVirtGear5 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxVirtGear6 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxVirtGear7 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxVirtGear8 = (SInt16)(0 * BIN4);

    /* ---- VSSP_F722422_Determiner_Couple_Roue_Gmp_Max ---- */
    VSCtl_tqWhlMaxGear2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear3 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear4 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear5 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear6 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear7 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlMaxGear8 = (SInt16)(16000 * BIN1);

    /* ---- VSSP_F722423_Determiner_Seuils_Changement_Rapport_Couple_Roue_Positif ---- */

    /* ---- VSSP_F72243_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif ---- */

    /* ---- VSSP_F722431_Determiner_Couple_Moteur_Min_Virtuel ---- */
    VSCtl_tqCkEfcMinVirtGear2 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMinVirtGear3 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMinVirtGear4 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMinVirtGear5 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMinVirtGear6 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMinVirtGear7 = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMinVirtGear8 = (SInt16)(0 * BIN4);

    /* ---- VSSP_F722432_Determiner_Couple_Roue_Gmp_Min ---- */
    VSCtl_tqWhlMinGear2 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear3 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear4 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear5 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear6 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear7 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlMinGear8 = (SInt16)(-16000 * BIN1);

    /* ---- VSSP_F722433_Determiner_Seuils_Changement_Rapport_Couple_Roue_Negatif ---- */

    /* ---- VSSP_F7225_Determiner_Temps_Confirmation_Changement_Rapport ---- */

    /* ---- VSSP_F72251_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Positif ---- */

    /* ---- VSSP_F72252_Determiner_Temps_Confirmation_Changement_Rapport_Couple_Roue_Negatif ---- */

}

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

