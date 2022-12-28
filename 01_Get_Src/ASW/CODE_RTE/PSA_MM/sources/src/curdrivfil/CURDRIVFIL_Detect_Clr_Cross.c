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
* Ref X:\integration_view_00PSASWC_EB00D01\blois_psa_sstg\Software\Appli\CurDrivFil\src\CURDRIVFIL_Detect_Clr_Cross.c
* Version int :/main/L01_01/1 Date: 27/8/2010 10 h 48 m User:meme 
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL4
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\6 Date: 26/8/2010 15 h 21 m User:veillard 
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL4
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_demezil_curdrivfil_dev\2 Date: 20/8/2010 9 h 31 m User:demezil 
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL3
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_demezil_curdrivfil_dev\1 Date: 18/8/2010 15 h 2 m User:demezil
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL2
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\5 Date: 21/7/2010 11 h 14 m User:veillard
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\4 Date: 9/7/2010 12 h 47 m User:veillard
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 2/7/2010 14 h 2 m User:veillard
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 2/7/2010 12 h 33 m User:veillard
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 30/6/2010 17 h 26 m User:veillard
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_moisan_curdrivfil\2 Date: 28/6/2010 11 h 56 m User:moisan
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_moisan_curdrivfil\1 Date: 28/6/2010 11 h 44 m User:moisan
*    TWK_model:CURDRIVFIL_Detect_Clr_Cross_L01_010_IMPL1
*    comments :First issue for CurDrivFil euro6
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

#define CURDRIVFIL_500_BIN4							(500 * BIN4)
#define CURDRIVFIL_M100_BIN4						(-100 * BIN4)
#define CURDRIVFIL_100_BIN4							(100 * BIN4)

#define CURDRIVFIL_M8000_BIN2						(-8000 * BIN2)
#define CURDRIVFIL_8000_BIN2						(8000 * BIN2)


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_facScale_C = (CONST(UInt16, AUTOMATIC))(0.001 * BIN10);
#define CURDRIVFIL_STOP_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqClrCros_bSelDetClrTyp_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqClrCros_tqOffSetClrAcv_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_detClr_nEngX_A[TQSYS_10_SIZE] = {
(UInt16)(500 * BIN2), (UInt16)(800 * BIN2), (UInt16)(1000 * BIN2),
(UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2),
(UInt16)(3000 * BIN2), (UInt16)(4000 * BIN2), (UInt16)(5000 * BIN2),
(UInt16)(6000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_detClr_noGearY_A[TQSYS_9_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(7 * BIN0), (UInt16)(8 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_facFiltGrdNEng_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) },
{
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_tiMaxDetClr_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) },
{
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3), (UInt16)(0.15 * DEC3),
(UInt16)(0.15 * DEC3) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_tqClrAcv_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) },
{
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(10 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqClrCros_valCurHystDetClr_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) },
{
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4), (UInt16)(100 * BIN4), (UInt16)(100 * BIN4),
(UInt16)(100 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqClrCros_valCurThdDetClr_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4) }
};

#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define CURDRIVFIL_START_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqclrcros_facfiltgrdneng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqclrcros_timaxdetclr_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqclrcros_tqclracv_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqclrcros_valcurhystdetclr_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqclrcros_valcurthddetclr_m_sav;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) f02_hyst_struct;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) f04_01_filter_struct;
#define CURDRIVFIL_STOP_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckfilrawaos_prev;
#define CURDRIVFIL_STOP_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqclrcros_stdetclr_prev;
STATIC VAR(UInt8, AUTOMATIC) tqclrcros_bacvclrcross_prev;
#define CURDRIVFIL_STOP_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_deltaGrdNEngFilt; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_deltaTqCorCur; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_facCurDetClr_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqClrCros_facFiltGrdNEng; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_grdNEngFilt; /* BIN2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_grdNEngFiltDly; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqClrCros_tiDetClr; /* DEC3 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqClrCros_tiMaxDetClr; /* DEC3 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqClrCros_tqThdClrDet; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_valCurDetClr; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqClrCros_valCurHystDetClr; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqClrCros_valCurThdDetClr; /* BIN4 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqClrCros_bA0ThdCros;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqClrCros_bClrAcv;
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"




/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCLRCROS_FACFILTGRDNENG_M_APM = {
&tqclrcros_facfiltgrdneng_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_noGearY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_facFiltGrdNEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCLRCROS_TIMAXDETCLR_M_APM = {
&tqclrcros_timaxdetclr_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_noGearY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_tiMaxDetClr_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCLRCROS_TQCLRACV_M_APM = {
&tqclrcros_tqclracv_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_noGearY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_tqClrAcv_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCLRCROS_VALCURHYSTDETCLR_M_APM = {
&tqclrcros_valcurhystdetclr_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_noGearY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_valCurHystDetClr_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQCLRCROS_VALCURTHDDETCLR_M_APM = {
&tqclrcros_valcurthddetclr_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_detClr_noGearY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqClrCros_valCurThdDetClr_M[0][0]
};

#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Seuil_activation(UInt16  ext_nengclc0_par,
															  UInt8  copt_nogearcorddrivfil_par,
															  SInt16 tqsys_tqckefcfiltrv_par,
															  SInt16 tqsys_tqthdpha3_par);

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Critere_Curatif(SInt16 tqsys_tqckfilrawaos_par);


 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_Critere_Grad_Regime(
 	 								   UInt8  ext_titdc_par,
 									   UInt16 ext_nengclc0_par,
 									   UInt16 ext_nengclc1_par,
									   UInt8  copt_nogearcorddrivfil_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_01_Derivee_Regime(
	 										UInt8  ext_titdc_par,
	 										UInt16 ext_nengclc0_par,
	 									    UInt16 ext_nengclc1_par,
									   	    UInt8  copt_nogearcorddrivfil_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_02_Calc_IDC(void);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F05_Parameters(UInt16 ext_nengclc0_par,
							  	    				   UInt8 copt_nogearcorddrivfil_par);

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F06_SF_Detect_jeu(
	 							 UInt8 ext_titdc_par,
								 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqclrcros_bacvclrcross_ptr,
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqclrcros_stdetclr_ptr );


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : CURDRIVFIL_Detect_Clr_Cross
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Detect_Clr_Cross(UInt8 CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                           UInt16 Ext_nEngClc1_swc_in, /* BIN2 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           SInt16 TqSys_tqCkEfcFilTrv_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqThdPha3_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkFilRawAOS_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_bAcvClrCross_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_stDetClr_swc_out )
{
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.1.1 */
	CURDRIVFIL_F02_Seuil_activation(Ext_nEngClc0_swc_in,
									CoPt_noGearCordDrivFil_swc_in,
									TqSys_tqCkEfcFilTrv_swc_in,
									TqSys_tqThdPha3_swc_in);

	/* TqClrCros_deltaTqCorCur */
	CURDRIVFIL_F03_Critere_Curatif(TqSys_tqCkFilRawAOS_swc_in);

	/* TqClrCros_deltaGrdNEngFilt */
	CURDRIVFIL_F04_Critere_Grad_Regime(Ext_tiTDC_swc_in,
									   Ext_nEngClc0_swc_in,
									   Ext_nEngClc1_swc_in,
									   CoPt_noGearCordDrivFil_swc_in);

	if((UInt32)DDS_FALSE != (UInt32)TqClrCros_bSelDetClrTyp_C)
	{
		TqClrCros_valCurDetClr = TqClrCros_deltaTqCorCur;
	}
	else
	{
		TqClrCros_valCurDetClr = TqClrCros_deltaGrdNEngFilt;
	}

	CURDRIVFIL_F05_Parameters(Ext_nEngClc0_swc_in,
							  CoPt_noGearCordDrivFil_swc_in);


	CURDRIVFIL_F06_SF_Detect_jeu(Ext_tiTDC_swc_in,
								 TqClrCros_bAcvClrCross_swc_out,
								 TqClrCros_stDetClr_swc_out);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_Seuil_activation
* Description :
*
*******************************************************************************/

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Seuil_activation(UInt16  ext_nengclc0_par,
															  UInt8  copt_nogearcorddrivfil_par,
															  SInt16 tqsys_tqckefcfiltrv_par,
															  SInt16 tqsys_tqthdpha3_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.2.1 */
	SInt32 low_hyst;
	UInt16 curdrivfil_output_map = DDS_M_MAP3D_U16(&TQCLRCROS_TQCLRACV_M_APM,
												   ext_nengclc0_par,
												   (UInt16)copt_nogearcorddrivfil_par);

	/* [0; 500] BIN4 */
	TqClrCros_tqThdClrDet = (UInt16)DDS_M_LIMIT((SInt32)tqsys_tqthdpha3_par - (SInt32)curdrivfil_output_map, 0, CURDRIVFIL_500_BIN4);

	if((SInt32)tqsys_tqckefcfiltrv_par >= (SInt32)tqsys_tqthdpha3_par)
	{
		TqClrCros_bA0ThdCros = DDS_TRUE;
	}
	else
	{
		TqClrCros_bA0ThdCros = DDS_FALSE;
	}

	low_hyst = (SInt32)TqClrCros_tqThdClrDet - ((SInt32)TqClrCros_tqOffSetClrAcv_C * BIN4);


	TqClrCros_bClrAcv = DDS_M_HYST_PH_S32 (&f02_hyst_struct,
										  (SInt32)tqsys_tqckefcfiltrv_par,
										  (SInt32)TqClrCros_tqThdClrDet,
										  low_hyst);

}



/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_Critere_Curatif
* Description :
*
*******************************************************************************/

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Critere_Curatif(SInt16 tqsys_tqckfilrawaos_par)
 {
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.3.0 */

	SInt32 sub_tmp = (SInt32)tqsys_tqckfilrawaos_par - (SInt32)tqsys_tqckfilrawaos_prev;

    TqClrCros_deltaTqCorCur = (SInt16)DDS_M_LIMIT(sub_tmp,
    									  CURDRIVFIL_M100_BIN4,
    									  CURDRIVFIL_100_BIN4);


	tqsys_tqckfilrawaos_prev = tqsys_tqckfilrawaos_par;
 }


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F04_Critere_Grad_Regime
* Description :
*
*******************************************************************************/

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_Critere_Grad_Regime(
	 								   UInt8  ext_titdc_par,
									   UInt16 ext_nengclc0_par,
									   UInt16 ext_nengclc1_par,
									   UInt8  copt_nogearcorddrivfil_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.4.1 */

	CURDRIVFIL_F04_01_Derivee_Regime(ext_titdc_par,
									 ext_nengclc0_par,
									 ext_nengclc1_par,
									 copt_nogearcorddrivfil_par);

	CURDRIVFIL_F04_02_Calc_IDC();

}



/*******************************************************************************
*
* Function Name : CURDRIVFIL_F04_01_Derivee_Regime
* Description :
*
*******************************************************************************/

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_01_Derivee_Regime(
	 										UInt8  ext_titdc_par,
	 										UInt16 ext_nengclc0_par,
	 									    UInt16 ext_nengclc1_par,
									   	    UInt8  copt_nogearcorddrivfil_par)
{
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.5.1 */
	SInt32 sub_tmp, div_tmp;
	SInt32 tqclrcros_grdnengfilt_temp;	/* BIN2 */

	/* [0; 1] BIN10 */
	TqClrCros_facFiltGrdNEng = DDS_M_MAP3D_U16(&TQCLRCROS_FACFILTGRDNENG_M_APM,
											   ext_nengclc0_par,
											   (UInt16)copt_nogearcorddrivfil_par);

	/* [-8000; 8000] BIN2 */
	sub_tmp = (SInt32)ext_nengclc0_par - (SInt32)ext_nengclc1_par;


	if(0 == sub_tmp)
	{
		div_tmp = 0;
	}
	else if(0 == (UInt32)ext_titdc_par)
	{
		if(sub_tmp > 0)
		{
			div_tmp = DDS_SINT32_MAX;
		}
		else
		{
			div_tmp = DDS_SINT32_MIN;
		}
	}
	else
	{
		/* BIN2 = BIN2 * DEC3 / DEC3 */
		/* [-8000; 8000] / [0; 0.1] */
		div_tmp = (sub_tmp * DEC3) / (SInt32)ext_titdc_par;
	}


	TqClrCros_grdNEngFiltDly = TqClrCros_grdNEngFilt;
	tqclrcros_grdnengfilt_temp = DDS_M_FILTER_LP1_S32(&f04_01_filter_struct,
													 div_tmp,
													 (UInt16)((SInt32)TqClrCros_facFiltGrdNEng * BIN5));	/* BIN15 = BIN10 * BIN5 */

	TqClrCros_grdNEngFilt = (SInt16)DDS_M_LIMIT(tqclrcros_grdnengfilt_temp,
												  CURDRIVFIL_M8000_BIN2,
												  CURDRIVFIL_8000_BIN2);

}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F04_02_Calc_IDC
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_02_Calc_IDC(void)
{
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.6.0 */

	SInt32 sub1_tmp, sub2_tmp, mux1_tmp, mux2_tmp;
	SInt32 sub_end;

	/* [-16000; 16000] BIN2 */
	sub1_tmp = (SInt32)TqClrCros_grdNEngFilt - (SInt32)TqClrCros_grdNEngFiltDly;

	/* BIN12 = BIN10 * BIN2 */
	/* [-160000; 160000] = [0; 10] * [-16000; 16000]  */
	mux1_tmp = (SInt32)TqClrCros_facScale_C * sub1_tmp;

	/* BIN10 = BIN10 - BIN10 */
	/* [-1; 1] = [0; 1] - 1 */
	sub2_tmp = (1 * BIN10) - (SInt32)TqClrCros_facFiltGrdNEng;

	/* BIN14 = BIN4 * BIN10 */
	/* [-100; 100] = [-1; 1] * [-100; 100] */
	mux2_tmp = (SInt32)TqClrCros_facCurDetClr_MP * sub2_tmp;

	/* BIN12 */
	sub_end = mux1_tmp - (mux2_tmp / BIN2);
	/* BIN4 */
	sub_end = sub_end / BIN8;

	sub_end = DDS_M_LIMIT(sub_end,
						  CURDRIVFIL_M100_BIN4,
						  CURDRIVFIL_100_BIN4);

	TqClrCros_deltaGrdNEngFilt = (SInt16)DDS_M_LIMIT(sub_end - (SInt32)TqClrCros_facCurDetClr_MP,
										     CURDRIVFIL_M100_BIN4,
										     CURDRIVFIL_100_BIN4);

	TqClrCros_facCurDetClr_MP = (SInt16)sub_end;
}



/*******************************************************************************
*
* Function Name : CURDRIVFIL_F05_Parameters
* Description :
*
*******************************************************************************/

 STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F05_Parameters(UInt16 ext_nengclc0_par,
							  							UInt8 copt_nogearcorddrivfil_par)
{

	/* [-100; 100] BIN4 */
	TqClrCros_valCurThdDetClr = DDS_M_MAP3D_UUS16(&TQCLRCROS_VALCURTHDDETCLR_M_APM,
											   ext_nengclc0_par,
											   (UInt16)copt_nogearcorddrivfil_par);

	/* [0; 100] BIN4 */
	TqClrCros_valCurHystDetClr = DDS_M_MAP3D_U16(&TQCLRCROS_VALCURHYSTDETCLR_M_APM,
											   ext_nengclc0_par,
											   (UInt16)copt_nogearcorddrivfil_par);

	/* [0; 10] BIN4 */
	TqClrCros_tiMaxDetClr = DDS_M_MAP3D_U16(&TQCLRCROS_TIMAXDETCLR_M_APM,
											ext_nengclc0_par,
											(UInt16)copt_nogearcorddrivfil_par);
}




/*******************************************************************************
*
* Function Name : CURDRIVFIL_F06_SF_Detect_jeu
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F06_SF_Detect_jeu(
	 							 UInt8 ext_titdc_par,
								 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqclrcros_bacvclrcross_ptr,
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqclrcros_stdetclr_ptr )
{
    /* SSTG REQ TAG : CSMT_CGMT08_0934.FR.8.2 */

	SInt32 sum_tmp;
    switch((UInt32)tqclrcros_stdetclr_prev)
    {
        case CURDRIVFIL_DETECTION_INACTIF:
            if( ((UInt32)TqClrCros_bClrAcv == (UInt32)DDS_TRUE) || ((UInt32)TqClrCros_bA0ThdCros == (UInt32)DDS_TRUE))
            {
                tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_DETECTION_EN_COURS;
                tqclrcros_bacvclrcross_prev = 0;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case CURDRIVFIL_DETECTION_EN_COURS:
            if((UInt32)TqClrCros_bClrAcv == (UInt32)DDS_FALSE )
            {
                tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_DETECTION_INACTIF;
                tqclrcros_bacvclrcross_prev = 0;
                TqClrCros_tiDetClr =0;
            }
            else if ( ((SInt32)TqClrCros_valCurDetClr <= (SInt32)TqClrCros_valCurThdDetClr) || ((UInt32)TqClrCros_bA0ThdCros == (UInt32)DDS_TRUE) )
            {
				tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_DETECTION_EFFECIF;
				tqclrcros_bacvclrcross_prev = DDS_TRUE;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case CURDRIVFIL_DETECTION_EFFECIF:
			sum_tmp = (SInt32)TqClrCros_valCurThdDetClr + (SInt32)TqClrCros_valCurHystDetClr;
            if(((UInt32)TqClrCros_tiDetClr >= (UInt32)TqClrCros_tiMaxDetClr) || ((SInt32)TqClrCros_valCurDetClr > sum_tmp))
            {
                tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_FIN_DE_DETECTION;
                tqclrcros_bacvclrcross_prev = 0;
                TqClrCros_tiDetClr =0;
            }
            else    /* during actions */
            {
                TqClrCros_tiDetClr = (UInt16)DDS_M_LIMITED_INCREMENT((UInt32)TqClrCros_tiDetClr,
                                                                     (UInt32)ext_titdc_par,
                                                                     (UInt32)(10 * DEC3));
            }
        break;
        case CURDRIVFIL_FIN_DE_DETECTION:

            if((UInt32)TqClrCros_bClrAcv == (UInt32)DDS_FALSE)
            {
                tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_DETECTION_INACTIF;
                tqclrcros_bacvclrcross_prev = 0;
                TqClrCros_tiDetClr =0;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;
        default :
			tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_DETECTION_INACTIF;
			tqclrcros_bacvclrcross_prev = 0;
			TqClrCros_tiDetClr =0;
		break;
    }

	*tqclrcros_bacvclrcross_ptr = tqclrcros_bacvclrcross_prev;
	*tqclrcros_stdetclr_ptr = tqclrcros_stdetclr_prev;
}




/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Detect_Clr_Cross_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Detect_Clr_Cross_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_bAcvClrCross_swc_out,
                                           				CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqClrCros_stDetClr_swc_out )
{
	(void)DDS_M_HYST_S32_INIT(&f02_hyst_struct, DDS_FALSE);
	tqsys_tqckfilrawaos_prev = 0;

	(void)DDS_M_FILTER_LP1_S32_INIT(&f04_01_filter_struct, 0);

	*TqClrCros_stDetClr_swc_out = (UInt8)CURDRIVFIL_DETECTION_INACTIF;
	tqclrcros_stdetclr_prev = (UInt8)CURDRIVFIL_DETECTION_INACTIF;
	*TqClrCros_bAcvClrCross_swc_out = 0 ;
	tqclrcros_bacvclrcross_prev = 0;
	TqClrCros_tiDetClr = 0;

	TqClrCros_deltaGrdNEngFilt = 0;
	TqClrCros_deltaTqCorCur = 0;
	TqClrCros_facCurDetClr_MP = 0;
	TqClrCros_facFiltGrdNEng = (UInt16)(0.001 * BIN10);
	TqClrCros_grdNEngFilt = 0;
	TqClrCros_grdNEngFiltDly = 0;
	TqClrCros_tiMaxDetClr = 0;
	TqClrCros_tqThdClrDet = 0;
	TqClrCros_valCurDetClr = 0;
	TqClrCros_valCurHystDetClr = 0;
	TqClrCros_valCurThdDetClr = 0;
	TqClrCros_bA0ThdCros = DDS_FALSE;
	TqClrCros_bClrAcv = DDS_FALSE;
}



#define CURDRIVFIL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CurDrivFil_MemMap.h"