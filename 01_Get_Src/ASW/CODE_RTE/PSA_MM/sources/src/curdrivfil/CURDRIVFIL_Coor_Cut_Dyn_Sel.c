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
* Ref X:\integration_view_00PSASWC_EB02D01\blois_psa_sstg\Software\Appli\CurDrivFil\src\CURDRIVFIL_Coor_Cut_Dyn_Sel.c
* Version int :/main/L01_01/3 Date: 18/5/2011 17 h 30 m User:esnault 
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1_D
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 12/5/2011 11 h 16 m User:veillard 
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1_D
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_demezil_curdrivfil_dev\1 Date: 28/4/2011 14 h 45 m User:demezil
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1_D
*    comments :To reduce CPU load
* Version int :/main/L01_01/2 Date: 30/8/2010 11 h 58 m User:meme
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\8 Date: 30/8/2010 9 h 52 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\7 Date: 21/7/2010 11 h 14 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\6 Date: 9/7/2010 15 h 58 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\5 Date: 6/7/2010 15 h 39 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\4 Date: 2/7/2010 11 h 38 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 1/7/2010 16 h 52 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 30/6/2010 17 h 26 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 30/6/2010 16 h 10 m User:veillard
*    TWK_model:CURDRIVFIL_Coor_Cut_Dyn_Sel_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CurDrivFil.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQSYS_TIOFFTHRINJCUTDYN_4000_BIN0_MAX       (SInt32)(4000 * BIN0)
#define TQSYS_TIOFFTHRINJCUTDYN_1_BIN0_MIN          (SInt32)(1 * BIN0)

#define TQSYS_TIAOSCORRMAXMEM_4000_BIN0_MAX         (UInt32)(4000 * BIN0)
#define TQSYS_TIAOSCORRMAXMEM_1_BIN0_MIN            (UInt32)(1 * BIN0)

#define TQSYS_TQAOSCORRMINTHD_2000_BIN4_MIN         (SInt32)(-2000 * BIN4)
#define TQSYS_TQAOSCORRMINTHD_2000_BIN4_MAX         (SInt32)(2000 * BIN4)
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

/* NONE */


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nCkFilMaxInjCutDyn_C = (CONST(UInt16, AUTOMATIC))(2000 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nCkFilMinInjCutDyn_C = (CONST(UInt16, AUTOMATIC))(1500 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccPEngTrvThd_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccPEngTrvThdRst_C = (CONST(UInt16, AUTOMATIC))(2 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tCoMesMinInjCutDyn_C = (CONST(SInt16, AUTOMATIC))(60 * BIN0);
#define CURDRIVFIL_STOP_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDiInjCutDyn_C = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_CutDyn_nEngX_A[TQSYS_10_SIZE] = {
(UInt16)(700 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1300 * BIN2),
(UInt16)(1500 * BIN2), (UInt16)(1750 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2), (UInt16)(4000 * BIN2),
(UInt16)(4500 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_CutDyn_noGearY_A[TQSYS_9_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(7 * BIN0), (UInt16)(8 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_CutDyn_tqMemX_A[TQSYS_10_SIZE] = {
(SInt16)(10 * BIN4), (SInt16)(20 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(60 * BIN4), (SInt16)(80 * BIN4), (SInt16)(100 * BIN4),
(SInt16)(110 * BIN4), (SInt16)(130 * BIN4), (SInt16)(200 * BIN4),
(SInt16)(300 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_CutDynWgh_tq_A[TQSYS_12_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(0 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(30 * BIN4), (SInt16)(50 * BIN4),
(SInt16)(75 * BIN4), (SInt16)(100 * BIN4), (SInt16)(125 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(200 * BIN4), (SInt16)(300 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiAOSCorrMaxMem_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) },
{
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiAOSCorrMaxMemWgh_T
[TQSYS_12_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiOffThrInjCutDyn_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) },
{
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0), (UInt16)(500 * BIN0), (UInt16)(500 * BIN0),
(UInt16)(500 * BIN0) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiOffThrInjCutDynWgh_T
[TQSYS_12_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqAOSCorrMinThd_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqAOSCorrMinThdWgh_T
[TQSYS_12_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqAOSThd_tqMem_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) },
{
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(30 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(30 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEfcMinCutDyn_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqEfcFilMaxCutDyn_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqEfcFilMaxCutDynWgh_T
[TQSYS_12_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqEfcFilMinCutDynWgh_T
[TQSYS_12_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) f01_02_condition_rs_prev;
STATIC VAR(UInt8, AUTOMATIC) tqsys_binjcutdyncondena_prev;
STATIC VAR(UInt8, AUTOMATIC) f01_01_01_04_condition_rs_prev;
STATIC VAR(UInt8, AUTOMATIC) f01_01_01_04_rs_flip_flop_reset_prev;
STATIC VAR(UInt8, AUTOMATIC) f01_01_01_04_rs_flip_flop_set_prev;
#define CURDRIVFIL_STOP_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"

/* 16-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckaoscormaxmem_prev;
#define CURDRIVFIL_STOP_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"


/* Complex variable definition */
#define CURDRIVFIL_START_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tiaoscorrmaxmem_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tiaoscorrmaxmemwgh_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tioffthrinjcutdyn_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tioffthrinjcutdynwgh_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqaoscorrminthd_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqaoscorrminthdwgh_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqaosthd_tqmem_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqckefcmincutdyn_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqefcfilmaxcutdyn_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqefcfilmaxcutdynwgh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqefcfilmincutdynwgh_t_sav;
STATIC VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC) f01_01_02_03_turn_on_auth;
STATIC VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC) f01_01_01_04_turn_on_cond;
#define CURDRIVFIL_STOP_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiAOSCorrMaxMem; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiOffThrInjCutDyn; /* BIN0 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqAOSCorrMinThd; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkAOSCorAuth; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkAOSCorMaxMem; /* BIN4 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bInjCutDynAuthDly_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bInjCutDynCondAuth;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bInjCutDynCondDi_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bInjCutDynCondEna;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bTqThdCutDynAuth;
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIAOSCORRMAXMEM_M_APM = {
&tqsys_tiaoscorrmaxmem_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_noGearY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAOSCorrMaxMem_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_TIAOSCORRMAXMEMWGH_T_APM = {
&tqsys_tiaoscorrmaxmemwgh_t_sav,
TQSYS_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDynWgh_tq_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAOSCorrMaxMemWgh_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIOFFTHRINJCUTDYN_M_APM = {
&tqsys_tioffthrinjcutdyn_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_noGearY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiOffThrInjCutDyn_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_TIOFFTHRINJCUTDYNWGH_T_APM = {
&tqsys_tioffthrinjcutdynwgh_t_sav,
TQSYS_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDynWgh_tq_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiOffThrInjCutDynWgh_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQAOSCORRMINTHD_M_APM = {
&tqsys_tqaoscorrminthd_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_noGearY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAOSCorrMinThd_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_TQAOSCORRMINTHDWGH_T_APM = {
&tqsys_tqaoscorrminthdwgh_t_sav,
TQSYS_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDynWgh_tq_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAOSCorrMinThdWgh_T[0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_TQAOSTHD_TQMEM_M_APM = {
&tqsys_tqaosthd_tqmem_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_tqMemX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_noGearY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAOSThd_tqMem_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQCKEFCMINCUTDYN_M_APM = {
&tqsys_tqckefcmincutdyn_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_noGearY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkEfcMinCutDyn_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQEFCFILMAXCUTDYN_M_APM = {
&tqsys_tqefcfilmaxcutdyn_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDyn_noGearY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqEfcFilMaxCutDyn_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_TQEFCFILMAXCUTDYNWGH_T_APM = {
&tqsys_tqefcfilmaxcutdynwgh_t_sav,
TQSYS_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDynWgh_tq_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqEfcFilMaxCutDynWgh_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_TQEFCFILMINCUTDYNWGH_T_APM = {
&tqsys_tqefcfilmincutdynwgh_t_sav,
TQSYS_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_CutDynWgh_tq_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqEfcFilMinCutDynWgh_T[0]
};

#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_Conditions_Activation(SInt16 tqsys_tqckfilrawaos_par,
                                                                     SInt16 tqsys_tqckefcfiltrv_par,
                                                                     UInt16 covsctl_raccpengtrv_par,
                                                                     UInt16 eng_nckfil_par,
                                                                     UInt8 copt_nogearcorddrivfil_par,
                                                                     SInt16 tqsys_tqckdeceini_par,
                                                                     SInt16 ext_tcomes_par,
                                                                     UInt8 ext_titdc_par,
                                                                     UInt8 copt_binjcutdynauth2_par);


STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_Autorisation(UInt16 eng_nckfil_par,
                                                               UInt8  copt_nogearcorddrivfil_par,
                                                               SInt16 tqsys_tqckefcfiltrv_par,
                                                               SInt16 tqsys_tqckdeceini_par,
                                                               UInt16 covsctl_raccpengtrv_par,
                                                               UInt8  copt_binjcutdynauth2_par,
                                                               SInt16 ext_tcomes_par,
                                                               UInt8  ext_titdc_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_01_Couples_Maxi_Mini(SInt16 tqsys_tqckefcfiltrv_par,
                                                                       UInt16 eng_nckfil_par,
                                                                       UInt8  copt_nogearcorddrivfil_par,
                                                                       SInt16 tqsys_tqckdeceini_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_02_Temporisation_Pied_Leve(UInt16 eng_nckfil_par,
                                                                             UInt8  copt_nogearcorddrivfil_par,
                                                                             SInt16 tqsys_tqckdeceini_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_03_Autorisation(UInt16 eng_nckfil_par,
                                                                  UInt16 covsctl_raccpengtrv_par,
                                                                  UInt8  copt_binjcutdynauth2_par,
                                                                  SInt16 ext_tcomes_par,
                                                                  UInt8  ext_titdc_par);


STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_Condition_Dynamique(SInt16 tqsys_tqckfilrawaos_par,
                                                                      UInt16 eng_nckfil_par,
                                                                      UInt8  copt_nogearcorddrivfil_par,
                                                                      SInt16 tqsys_tqckdeceini_par,
                                                                      UInt8  ext_titdc_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_01_Memorisation_Couple_Curatif(SInt16 tqsys_tqckfilrawaos_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_02_Temporisation_Maxi_Curatif(UInt16 eng_nckfil_par,
                                                                                UInt8  copt_nogearcorddrivfil_par,
                                                                                SInt16 tqsys_tqckdeceini_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_03_Seuil_Mini_curatif(UInt16 eng_nckfil_par,
                                                                        UInt8  copt_nogearcorddrivfil_par,
                                                                        SInt16 tqsys_tqckdeceini_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_04_Condition_Dynamique(UInt8  copt_nogearcorddrivfil_par,
                                                UInt8  ext_titdc_par);


STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_02_Gestion_Activation(UInt16 eng_nckfil_par,
                                                                  UInt8  copt_nogearcorddrivfil_par,
                                                                  UInt16 covsctl_raccpengtrv_par,
                                                                  UInt8  copt_binjcutdynauth1_par,
                                                                  UInt8  copt_binjcutdynauth3_par,
                                                                  UInt8  copt_binjcutdynauth2_par,
                                                                  SInt16 copt_tqidccordlimbuf_tqgbx_par,
                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_binjcutdynreq_ptr);


STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_03_Coord_Coup_Selective(SInt8 copt_nocylcutauth_par,
                                                                    SInt8 tqsys_nocylcutauth_par,
                                                                    SInt8 cocha_nocylcutauth_par,
                                                                    UInt8 ext_nocyleng_par,
                                                                    UInt8 tqcll_bforccll_par,
                                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_nocylcutauthcord_ptr);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : CURDRIVFIL_Coor_Cut_Dyn_Sel
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Coor_Cut_Dyn_Sel(SInt8 CoCha_noCylCutAuth_swc_in, /* BIN0 */
                                           UInt8 CoPt_bInjCutDynAuth1_swc_in,
                                           UInt8 CoPt_bInjCutDynAuth2_swc_in,
                                           UInt8 CoPt_bInjCutDynAuth3_swc_in,
                                           SInt8 CoPt_noCylCutAuth_swc_in, /* BIN0 */
                                           UInt8 CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                           SInt16 CoPt_tqIdcCordLimBuf_tqGBx_swc_in, /* BIN4 */
                                           UInt16 CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_noCylEng_swc_in, /* BIN0 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 TqCll_bForcCll_swc_in,
                                           SInt8 TqSys_noCylCutAuth_swc_in, /* BIN0 */
                                           SInt16 TqSys_tqCkDeceIni_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkEfcFilTrv_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkFilRawAOS_swc_in, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInjCutDynReq_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthCord_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.1.2 */

    CURDRIVFIL_F01_01_Conditions_Activation(TqSys_tqCkFilRawAOS_swc_in,
                                            TqSys_tqCkEfcFilTrv_swc_in,
                                            CoVSCtl_rAccPEngTrv_swc_in,
                                            Eng_nCkFil_swc_in,
                                            CoPt_noGearCordDrivFil_swc_in,
                                            TqSys_tqCkDeceIni_swc_in,
                                            Ext_tCoMes_swc_in,
                                            Ext_tiTDC_swc_in,
                                            CoPt_bInjCutDynAuth2_swc_in);


    CURDRIVFIL_F01_02_Gestion_Activation(Eng_nCkFil_swc_in,
                                        CoPt_noGearCordDrivFil_swc_in,
                                        CoVSCtl_rAccPEngTrv_swc_in,
                                        CoPt_bInjCutDynAuth1_swc_in,
                                        CoPt_bInjCutDynAuth3_swc_in,
                                        CoPt_bInjCutDynAuth2_swc_in,
                                        CoPt_tqIdcCordLimBuf_tqGBx_swc_in,
                                        TqSys_bInjCutDynReq_swc_out);


    CURDRIVFIL_F01_03_Coord_Coup_Selective(CoPt_noCylCutAuth_swc_in,
                                            TqSys_noCylCutAuth_swc_in,
                                            CoCha_noCylCutAuth_swc_in,
                                            Ext_noCylEng_swc_in,
                                            TqCll_bForcCll_swc_in,
                                            TqSys_noCylCutAuthCord_swc_out);



}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_Conditions_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_Conditions_Activation(SInt16 tqsys_tqckfilrawaos_par,
                                                                     SInt16 tqsys_tqckefcfiltrv_par,
                                                                     UInt16 covsctl_raccpengtrv_par,
                                                                     UInt16 eng_nckfil_par,
                                                                     UInt8 copt_nogearcorddrivfil_par,
                                                                     SInt16 tqsys_tqckdeceini_par,
                                                                     SInt16 ext_tcomes_par,
                                                                     UInt8 ext_titdc_par,
                                                                     UInt8 copt_binjcutdynauth2_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.2.2 */

    CURDRIVFIL_F01_01_02_Autorisation(eng_nckfil_par,
                                      copt_nogearcorddrivfil_par,
                                      tqsys_tqckefcfiltrv_par,
                                      tqsys_tqckdeceini_par,
                                      covsctl_raccpengtrv_par,
                                      copt_binjcutdynauth2_par,
                                      ext_tcomes_par,
                                      ext_titdc_par);

    CURDRIVFIL_F01_01_01_Condition_Dynamique(tqsys_tqckfilrawaos_par,
                                            eng_nckfil_par,
                                            copt_nogearcorddrivfil_par,
                                            tqsys_tqckdeceini_par,
                                            ext_titdc_par);




}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_02_Gestion_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_02_Gestion_Activation(UInt16 eng_nckfil_par,
                                                                  UInt8  copt_nogearcorddrivfil_par,
                                                                  UInt16 covsctl_raccpengtrv_par,
                                                                  UInt8  copt_binjcutdynauth1_par,
                                                                  UInt8  copt_binjcutdynauth3_par,
                                                                  UInt8  copt_binjcutdynauth2_par,
                                                                  SInt16 copt_tqidccordlimbuf_tqgbx_par,
                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_binjcutdynreq_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.12.1 */

    UInt8 f01_02_condition_rs;

    /* Calculation of TqSys_bInjCutDynCondDi_MP */
    if( ((UInt32)eng_nckfil_par <= (UInt32)TqSys_nCkFilMinInjCutDyn_C)              ||
        ((UInt32)copt_nogearcorddrivfil_par == (UInt32)(0 * BIN0))                  ||
        ((UInt32)covsctl_raccpengtrv_par   >= (UInt32)TqSys_rAccPEngTrvThdRst_C)    ||
        ((UInt32)DDS_FALSE == (UInt32)copt_binjcutdynauth1_par)                     ||
        ((UInt32)DDS_FALSE == (UInt32)copt_binjcutdynauth2_par)                     ||
        ((UInt32)DDS_FALSE == (UInt32)copt_binjcutdynauth3_par)                     ||
        ((SInt32)(0 * BIN4) == (SInt32)copt_tqidccordlimbuf_tqgbx_par) )
    {
        TqSys_bInjCutDynCondDi_MP = DDS_TRUE;
    }
    else
    {
        TqSys_bInjCutDynCondDi_MP = DDS_FALSE;
    }


    /* Reset priority */
    if ((UInt32)DDS_TRUE == (UInt32)TqSys_bInjCutDynCondDi_MP)
    {
        /* Reset value */
        f01_02_condition_rs = DDS_FALSE;
    }
    else if(((UInt32)DDS_TRUE  == (UInt32)TqSys_bInjCutDynCondEna)      &&
            ((UInt32)DDS_FALSE == (UInt32)tqsys_binjcutdyncondena_prev))
    {
        /* Set value */
        f01_02_condition_rs = DDS_TRUE;
    }
    else
    {
        /* Keep previous value */
        f01_02_condition_rs = f01_02_condition_rs_prev;
    }


    *tqsys_binjcutdynreq_ptr = f01_02_condition_rs;
    f01_02_condition_rs_prev = f01_02_condition_rs;
    tqsys_binjcutdyncondena_prev = TqSys_bInjCutDynCondEna;
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_03_Coord_Coup_Selective
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_03_Coord_Coup_Selective(SInt8 copt_nocylcutauth_par,
                                                                    SInt8 tqsys_nocylcutauth_par,
                                                                    SInt8 cocha_nocylcutauth_par,
                                                                    UInt8 ext_nocyleng_par,
                                                                    UInt8 tqcll_bforccll_par,
                                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_nocylcutauthcord_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.13.2 */

    UInt32 f01_03_sat_max;
    SInt32 f01_03_sat_dyn_input;
    UInt32 tqsys_nocylcutauthcord_unlim;


    /* [0;11]BIN0 = [1;12]BIN0 - 1 */
    f01_03_sat_max = (UInt32)DDS_M_LIMITED_DECREMENT((SInt32)ext_nocyleng_par , (SInt32)(1 * BIN0) , (SInt32)(0 * BIN0));


    if((UInt32)DDS_TRUE  == (UInt32)tqcll_bforccll_par)
    {
        tqsys_nocylcutauthcord_unlim = f01_03_sat_max;  /* [0;11] */
    }
    else
    {
        if((SInt32)(-1 * BIN0) != (SInt32)copt_nocylcutauth_par)
        {
            f01_03_sat_dyn_input = (SInt32)copt_nocylcutauth_par;           /* [-1;6] */
        }
        else if((SInt32)(-1 * BIN0) == (SInt32)cocha_nocylcutauth_par)
        {
            f01_03_sat_dyn_input = (SInt32)tqsys_nocylcutauth_par;          /* [-1;6] */
        }
        else
        {
            f01_03_sat_dyn_input = (SInt32)cocha_nocylcutauth_par;          /* [-1;6] */
        }

        /* [0;11]BIN0 */
        tqsys_nocylcutauthcord_unlim = (UInt32)DDS_M_SATURATION(f01_03_sat_dyn_input, (SInt32)(0 * BIN0), (SInt32)f01_03_sat_max);
    }

    /* [0;6]BIN0 */
    *tqsys_nocylcutauthcord_ptr = (UInt8)DDS_M_MIN(tqsys_nocylcutauthcord_unlim , (UInt32)(6 * BIN0));

}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_02_Autorisation
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_Autorisation(UInt16 eng_nckfil_par,
                                                               UInt8  copt_nogearcorddrivfil_par,
                                                               SInt16 tqsys_tqckefcfiltrv_par,
                                                               SInt16 tqsys_tqckdeceini_par,
                                                               UInt16 covsctl_raccpengtrv_par,
                                                               UInt8  copt_binjcutdynauth2_par,
                                                               SInt16 ext_tcomes_par,
                                                               UInt8  ext_titdc_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.3.1 */

    CURDRIVFIL_F01_01_02_01_Couples_Maxi_Mini(tqsys_tqckefcfiltrv_par,
                                              eng_nckfil_par,
                                              copt_nogearcorddrivfil_par,
                                              tqsys_tqckdeceini_par);


    CURDRIVFIL_F01_01_02_02_Temporisation_Pied_Leve(eng_nckfil_par,
                                                    copt_nogearcorddrivfil_par,
                                                    tqsys_tqckdeceini_par);


    CURDRIVFIL_F01_01_02_03_Autorisation(eng_nckfil_par,
                                         covsctl_raccpengtrv_par,
                                         copt_binjcutdynauth2_par,
                                         ext_tcomes_par,
                                         ext_titdc_par);




}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_01_Condition_Dynamique
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_Condition_Dynamique(SInt16 tqsys_tqckfilrawaos_par,
                                                                      UInt16 eng_nckfil_par,
                                                                      UInt8  copt_nogearcorddrivfil_par,
                                                                      SInt16 tqsys_tqckdeceini_par,
                                                                      UInt8  ext_titdc_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.7.2 */

    CURDRIVFIL_F01_01_01_01_Memorisation_Couple_Curatif(tqsys_tqckfilrawaos_par);


    CURDRIVFIL_F01_01_01_02_Temporisation_Maxi_Curatif(eng_nckfil_par,
                                                       copt_nogearcorddrivfil_par,
                                                       tqsys_tqckdeceini_par);


    CURDRIVFIL_F01_01_01_03_Seuil_Mini_curatif(eng_nckfil_par,
                                               copt_nogearcorddrivfil_par,
                                               tqsys_tqckdeceini_par);


    CURDRIVFIL_F01_01_01_04_Condition_Dynamique(copt_nogearcorddrivfil_par,
                                                ext_titdc_par);


}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_01_01_Memorisation_Couple_Curatif
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_01_Memorisation_Couple_Curatif(SInt16 tqsys_tqckfilrawaos_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.8.2 */


    if((UInt32)DDS_TRUE == (UInt32)TqSys_bInjCutDynCondAuth)
    {
        /* [-2000;2000]BIN4 */
        TqSys_tqCkAOSCorAuth = tqsys_tqckfilrawaos_par;
    }
    else
    {
        TqSys_tqCkAOSCorAuth = (SInt16)(0 * BIN4);
    }


    if((SInt32)TqSys_tqCkAOSCorAuth >= (SInt32)(0 * BIN4))
    {
        /* [-2000;2000]BIN4 */
        TqSys_tqCkAOSCorMaxMem = (SInt16)DDS_M_MAX((SInt32)TqSys_tqCkAOSCorAuth , (SInt32)tqsys_tqckaoscormaxmem_prev);
    }
    else
    {
        TqSys_tqCkAOSCorMaxMem = (SInt16)(0 * BIN4);
    }


    tqsys_tqckaoscormaxmem_prev = TqSys_tqCkAOSCorMaxMem;
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_01_02_Temporisation_Maxi_Curatif
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_02_Temporisation_Maxi_Curatif(UInt16 eng_nckfil_par,
                                                                                UInt8  copt_nogearcorddrivfil_par,
                                                                                SInt16 tqsys_tqckdeceini_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.9.1 */

    UInt32 f01_01_01_02_map_out_0;
    UInt32 f01_01_01_02_map_out_1;

    UInt32 tqsys_tiaoscorrmaxmem_unlim;


    f01_01_01_02_map_out_0 = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIAOSCORRMAXMEM_M_APM , eng_nckfil_par , (UInt16)copt_nogearcorddrivfil_par);
    f01_01_01_02_map_out_1 = (UInt32)DDS_M_MAP2D_SU16(&TQSYS_TIAOSCORRMAXMEMWGH_T_APM , tqsys_tqckdeceini_par);

    /* [0;12000]BIN0 = ( [0;4000]BIN0 * [0;3]BIN7 ) / BIN7 */
    tqsys_tiaoscorrmaxmem_unlim = (f01_01_01_02_map_out_0 * f01_01_01_02_map_out_1) / BIN7;

    /* [1;4000]BIN0 */
    TqSys_tiAOSCorrMaxMem = (UInt16)DDS_M_LIMIT(tqsys_tiaoscorrmaxmem_unlim , TQSYS_TIAOSCORRMAXMEM_1_BIN0_MIN ,TQSYS_TIAOSCORRMAXMEM_4000_BIN0_MAX);

}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_01_03_Seuil_Mini_curatif
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_03_Seuil_Mini_curatif(UInt16 eng_nckfil_par,
                                                                        UInt8  copt_nogearcorddrivfil_par,
                                                                        SInt16 tqsys_tqckdeceini_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.10.1 */

    SInt32 f01_01_01_03_map_out_0;
    SInt32 f01_01_01_03_map_out_1;

    SInt32 tqsys_tqaoscorrminthd_unlim;


    f01_01_01_03_map_out_0 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQAOSCORRMINTHD_M_APM , eng_nckfil_par , (UInt16)copt_nogearcorddrivfil_par);
    f01_01_01_03_map_out_1 = (SInt32)DDS_M_MAP2D_SU16(&TQSYS_TQAOSCORRMINTHDWGH_T_APM , tqsys_tqckdeceini_par);

    /* [-6000;6000]BIN4 = ( [-2000;2000]BIN4 * [0;3]BIN7 ) / BIN7 */
    tqsys_tqaoscorrminthd_unlim = (f01_01_01_03_map_out_0 * f01_01_01_03_map_out_1) / BIN7;

    /* [-2000;2000]BIN4 */
    TqSys_tqAOSCorrMinThd = (SInt16)DDS_M_LIMIT(tqsys_tqaoscorrminthd_unlim,TQSYS_TQAOSCORRMINTHD_2000_BIN4_MIN,TQSYS_TQAOSCORRMINTHD_2000_BIN4_MAX);

}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_01_04_Condition_Dynamique
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_04_Condition_Dynamique(UInt8  copt_nogearcorddrivfil_par,
                                                                         UInt8  ext_titdc_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.11.2 */

    UInt8 f01_01_01_04_condition_rs;
    UInt8 f01_01_01_04_rs_flip_flop_reset;
    UInt8 f01_01_01_04_rs_flip_flop_set;

    UInt8 f01_01_01_04_turn_on_result;

    SInt32 f01_01_01_04_map_out;

    /* Calculation of TqSys_bInjCutDynAuthDly_MP */
    if((SInt32)TqSys_tqCkAOSCorAuth >= (SInt32)(0 * BIN4))
    {
        f01_01_01_04_rs_flip_flop_reset = DDS_TRUE;
    }
    else
    {
        f01_01_01_04_rs_flip_flop_reset = DDS_FALSE;
    }

    if(((SInt32)TqSys_tqCkAOSCorMaxMem != (SInt32)TqSys_tqCkAOSCorAuth)  &&
       ((SInt32)TqSys_tqCkAOSCorMaxMem >= (SInt32)TqSys_tqAOSCorrMinThd))
    {
        f01_01_01_04_rs_flip_flop_set = DDS_TRUE;
    }
    else
    {
        f01_01_01_04_rs_flip_flop_set = DDS_FALSE;
    }





    /* Reset priority */
    if (((UInt32)DDS_TRUE  == (UInt32)f01_01_01_04_rs_flip_flop_reset)          &&
        ((UInt32)DDS_FALSE == (UInt32)f01_01_01_04_rs_flip_flop_reset_prev))
    {
        /* Reset value */
        f01_01_01_04_condition_rs = DDS_FALSE;
    }
    else if(((UInt32)DDS_TRUE  == (UInt32)f01_01_01_04_rs_flip_flop_set)        &&
            ((UInt32)DDS_FALSE == (UInt32)f01_01_01_04_rs_flip_flop_set_prev))
    {
        /* Set value */
        f01_01_01_04_condition_rs = DDS_TRUE;
    }
    else
    {
        /* Keep previous value */
        f01_01_01_04_condition_rs = f01_01_01_04_condition_rs_prev;
    }


    TqSys_bInjCutDynAuthDly_MP = f01_01_01_04_condition_rs;

    f01_01_01_04_turn_on_result = DDS_M_TURN_ON_DELAY_DELTA(TqSys_bInjCutDynAuthDly_MP,
                                                            (UInt32)ext_titdc_par,          /* [0;0.1]DEC3  s dec3 */
                                                            (UInt32)TqSys_tiAOSCorrMaxMem,  /* [0;4000]BIN0 ms */
                                                            &f01_01_01_04_turn_on_cond);

    if( ((UInt32)DDS_FALSE == (UInt32)f01_01_01_04_turn_on_result)  ||
        ((UInt32)DDS_FALSE == (UInt32)TqSys_bInjCutDynCondAuth) )
    {
        TqSys_bInjCutDynCondEna = DDS_FALSE;
    }
    else
    {
        if((SInt32)TqSys_tqCkAOSCorAuth > DDS_M_MIN((-1 * (SInt32)TqSys_tqCkAOSCorMaxMem) , (0 * BIN4)))
        {
            f01_01_01_04_map_out = (SInt32)DDS_M_MAP3D_SUS16(&TQSYS_TQAOSTHD_TQMEM_M_APM,TqSys_tqCkAOSCorMaxMem,(UInt16)copt_nogearcorddrivfil_par);
            if((SInt32)TqSys_tqCkAOSCorAuth > f01_01_01_04_map_out)
            {
                TqSys_bInjCutDynCondEna = DDS_FALSE;
            }
            else
            {
                TqSys_bInjCutDynCondEna = DDS_TRUE;
            }
        }
        else
        {
            TqSys_bInjCutDynCondEna = DDS_TRUE;
        }
    }

    f01_01_01_04_condition_rs_prev = f01_01_01_04_condition_rs;
    f01_01_01_04_rs_flip_flop_reset_prev = f01_01_01_04_rs_flip_flop_reset;
    f01_01_01_04_rs_flip_flop_set_prev = f01_01_01_04_rs_flip_flop_set;
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_02_01_Couples_Maxi_Mini
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_01_Couples_Maxi_Mini(SInt16 tqsys_tqckefcfiltrv_par,
                                                                       UInt16 eng_nckfil_par,
                                                                       UInt8  copt_nogearcorddrivfil_par,
                                                                       SInt16 tqsys_tqckdeceini_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.4.1 */

    SInt32 f01_01_02_01_map_out_0;
    SInt32 f01_01_02_01_map_out_1;
    SInt32 f01_01_02_01_map_mult_0;
    SInt32 f01_01_02_01_map_mult_1;

    f01_01_02_01_map_out_0 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQCKEFCMINCUTDYN_M_APM , eng_nckfil_par , (UInt16)copt_nogearcorddrivfil_par );
    f01_01_02_01_map_out_1 = (SInt32)DDS_M_MAP2D_SU16(&TQSYS_TQEFCFILMINCUTDYNWGH_T_APM , tqsys_tqckdeceini_par );


    /* [-6000;6000]BIN4    = ( [-2000;2000]BIN4 * [0;3]BIN7) / BIN7 */
    f01_01_02_01_map_mult_0 = (f01_01_02_01_map_out_0 * f01_01_02_01_map_out_1) / BIN7;

    if((SInt32)tqsys_tqckefcfiltrv_par < f01_01_02_01_map_mult_0)
    {
        TqSys_bTqThdCutDynAuth = DDS_FALSE;
    }
    else
    {
        f01_01_02_01_map_out_0 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQEFCFILMAXCUTDYN_M_APM , eng_nckfil_par , (UInt16)copt_nogearcorddrivfil_par );
        f01_01_02_01_map_out_1 = (SInt32)DDS_M_MAP2D_SU16(&TQSYS_TQEFCFILMAXCUTDYNWGH_T_APM , tqsys_tqckdeceini_par );
        f01_01_02_01_map_mult_1 = (f01_01_02_01_map_out_0 * f01_01_02_01_map_out_1) / BIN7;

        if((SInt32)tqsys_tqckefcfiltrv_par > f01_01_02_01_map_mult_1)
        {
            TqSys_bTqThdCutDynAuth = DDS_FALSE;
        }
        else
        {
            TqSys_bTqThdCutDynAuth = DDS_TRUE;
        }
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_02_02_Temporisation_Pied_Leve
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_02_Temporisation_Pied_Leve(UInt16 eng_nckfil_par,
                                                                             UInt8  copt_nogearcorddrivfil_par,
                                                                             SInt16 tqsys_tqckdeceini_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.5.1 */

    SInt32 f01_01_02_02_map_out_0;
    SInt32 f01_01_02_02_map_out_1;

    SInt32 f01_01_02_01_map_mult_0;

    f01_01_02_02_map_out_0 = (SInt32)DDS_M_MAP3D_U16(&TQSYS_TIOFFTHRINJCUTDYN_M_APM , eng_nckfil_par , (UInt16)copt_nogearcorddrivfil_par);
    f01_01_02_02_map_out_1 = (SInt32)DDS_M_MAP2D_SU16(&TQSYS_TIOFFTHRINJCUTDYNWGH_T_APM , tqsys_tqckdeceini_par);

    /* [0;12000]BIN0        = ( [0;4000]BIN0 * [0;3]BIN7 ) / BIN7 */
    f01_01_02_01_map_mult_0 = (f01_01_02_02_map_out_0 * f01_01_02_02_map_out_1) / BIN7;

    /* [1;4000]BIN0 */
    TqSys_tiOffThrInjCutDyn = (UInt16)DDS_M_LIMIT(f01_01_02_01_map_mult_0 ,
                                                  TQSYS_TIOFFTHRINJCUTDYN_1_BIN0_MIN,
                                                  TQSYS_TIOFFTHRINJCUTDYN_4000_BIN0_MAX);

}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_02_03_Autorisation
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_03_Autorisation(UInt16 eng_nckfil_par,
                                                                  UInt16 covsctl_raccpengtrv_par,
                                                                  UInt8  copt_binjcutdynauth2_par,
                                                                  SInt16 ext_tcomes_par,
                                                                  UInt8  ext_titdc_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0936.FR.6.1 */

    UInt8 f01_01_02_03_turn_on_input;
    UInt8 f01_01_02_03_turn_on_result;

    if( ((UInt32)covsctl_raccpengtrv_par < (UInt32)TqSys_rAccPEngTrvThd_C) &&
        ((UInt32)DDS_TRUE == (UInt32)copt_binjcutdynauth2_par) )
    {
        f01_01_02_03_turn_on_input = DDS_TRUE;
    }
    else
    {
        f01_01_02_03_turn_on_input = DDS_FALSE;
    }

    f01_01_02_03_turn_on_result = DDS_M_TURN_ON_DELAY_DELTA(f01_01_02_03_turn_on_input,
                                                            (UInt32)ext_titdc_par,              /* [0;0.1]DEC3  s dec3 */
                                                            (UInt32)TqSys_tiOffThrInjCutDyn,    /* [0;4000]BIN0 ms */
                                                            &f01_01_02_03_turn_on_auth);

    if( ((UInt32)DDS_FALSE == (UInt32)TqSys_bDiInjCutDyn_C)                 &&
        ((UInt32)eng_nckfil_par >= (UInt32)TqSys_nCkFilMaxInjCutDyn_C)      &&
        ((SInt32)ext_tcomes_par >= (SInt32)TqSys_tCoMesMinInjCutDyn_C)      &&
        ((UInt32)DDS_TRUE == (UInt32)TqSys_bTqThdCutDynAuth)                &&
        ((UInt32)DDS_TRUE == (UInt32)f01_01_02_03_turn_on_result) )
    {
        TqSys_bInjCutDynCondAuth = DDS_TRUE;
    }
    else
    {
        TqSys_bInjCutDynCondAuth = DDS_FALSE;
    }

}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Coor_Cut_Dyn_Sel_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Coor_Cut_Dyn_Sel_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInjCutDynReq_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthCord_swc_out /* BIN0 */)
{


    /* CURDRIVFIL_F01_01_02_01_Couples_Maxi_Mini */
    TqSys_bTqThdCutDynAuth = DDS_FALSE;

    /* CURDRIVFIL_F01_01_02_02_Temporisation_Pied_Leve */
    TqSys_tiOffThrInjCutDyn = (UInt16)(1 * BIN0);

    /* CURDRIVFIL_F01_01_02_03_Autorisation */
    DDS_M_TURN_ON_DELAY_DELTA_INIT(DDS_FALSE, &f01_01_02_03_turn_on_auth);
    TqSys_bInjCutDynCondAuth = DDS_FALSE;

    /* CURDRIVFIL_F01_01_01_01_Memorisation_Couple_Curatif */
    TqSys_tqCkAOSCorMaxMem      = (SInt16)(0 * BIN4);
    tqsys_tqckaoscormaxmem_prev = (SInt16)(0 * BIN4);

    /* CURDRIVFIL_F01_01_01_02_Temporisation_Maxi_Curatif */
    TqSys_tiAOSCorrMaxMem = (UInt16)(1 * BIN0);

    /* CURDRIVFIL_F01_01_01_03_Seuil_Mini_curatif */
    TqSys_tqAOSCorrMinThd = (SInt16)(0 * BIN4);

    /* CURDRIVFIL_F01_01_01_04_Condition_Dynamique */
    TqSys_bInjCutDynCondEna         = DDS_FALSE;
    TqSys_bInjCutDynAuthDly_MP      = DDS_FALSE;

    f01_01_01_04_condition_rs_prev  = DDS_TRUE;
    f01_01_01_04_rs_flip_flop_reset_prev = DDS_FALSE;
    f01_01_01_04_rs_flip_flop_set_prev   = DDS_FALSE;

    DDS_M_TURN_ON_DELAY_DELTA_INIT(DDS_FALSE, &f01_01_01_04_turn_on_cond);



    /* CURDRIVFIL_F01_02_Gestion_Activation */
    TqSys_bInjCutDynCondDi_MP = DDS_FALSE;
    *TqSys_bInjCutDynReq_swc_out    = DDS_FALSE;
    f01_02_condition_rs_prev        = DDS_TRUE;
    tqsys_binjcutdyncondena_prev    = DDS_FALSE;

    /* CURDRIVFIL_F01_03_Coord_Coup_Selective */
    *TqSys_noCylCutAuthCord_swc_out = (UInt8)(0 * BIN0);




}

#define CURDRIVFIL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CurDrivFil_MemMap.h"

