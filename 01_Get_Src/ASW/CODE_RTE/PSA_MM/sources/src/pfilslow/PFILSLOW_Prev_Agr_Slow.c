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
* Ref X:\integration_view_00PSASWC_E300D01\blois_psa_sstg\Software\Appli\PFilSlow\src\PFILSLOW_Prev_Agr_Slow.c
* Version int :/main/L02_01/1 Date: 23/7/2010 14 h 41 m User:esnault 
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L02_010_IMPL1
*    comments :correction after UT for PFilSlow 10.0
* Version dev :\main\branch_lemort_pfilslow_dev\3 Date: 12/7/2010 10 h 22 m User:lemort 
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L02_010_IMPL1
*    comments :correction after UT for PFilSlow 10.0
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 1/7/2010 12 h 41 m User:lemort
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L02_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 30/6/2010 16 h 35 m User:lemort
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L02_010_IMPL1
*    comments :for PFilSlow e6
* Version int :/main/L01_01/4 Date: 19/11/2008 9 h 38 m User:boucher
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2_D
*    comments :Correction of FDS 24801
* Version dev :\main\branch_moisan_pfilslow\9 Date: 12/11/2008 13 h 15 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2_D
*    comments :Correction of FDS 24801
* Version int :/main/L01_01/3 Date: 25/9/2008 10 h 58 m User:boucher
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2
*    comments :Correction of OVFL 2
*    comments :Correction of OVFL 2
* Version int :/main/L01_01/2 Date: 25/9/2008 9 h 8 m User:boucher
* Version dev :\main\branch_moisan_pfilslow\8 Date: 25/9/2008 10 h 41 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2
*    comments :Correction of OVFL 2
* Version dev :\main\branch_moisan_pfilslow\7 Date: 25/9/2008 10 h 30 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2
*    comments :Ovl correction
* Version dev :\main\branch_moisan_pfilslow\6 Date: 22/9/2008 12 h 10 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2
*    comments :No change: evolution of the tracking sheet only
* Version dev :\main\branch_moisan_pfilslow\5 Date: 19/9/2008 15 h 44 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL2
*    comments :None change
* Version dev :\main\branch_moisan_pfilslow\4 Date: 19/9/2008 15 h 28 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL1
*    comments :Correction of fail test
* Version dev :\main\branch_moisan_pfilslow\3 Date: 16/9/2008 14 h 53 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL1
*    comments :Detectsat correction in F04_02_Saturation_Couple
* Version dev :\main\branch_moisan_pfilslow\2 Date: 12/9/2008 9 h 12 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL1
*    comments :Correction of TqSys_bDrivFilAir_C and two axes
* Version dev :\main\branch_moisan\1 Date: 11/9/2008 17 h 4 m User:moisan
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL1
*    comments :error bin with two axes
* Version int :/main/L01_01/1 Date: 2/9/2008 15 h 37 m User:boucher
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL1
*    comments :Implement "CSMT_CGMT07_2710 v1.0".
* Version dev :\main\branch_girodon_pfilslow_1_dev\1 Date: 2/9/2008 8 h 13 m User:girodon
*    TWK_model:PFILSLOW_Prev_Agr_Slow_L01_010_IMPL1
*    comments :Implement "CSMT_CGMT07_2710 v1.0".
*
*******************************************************************************/


/*******************************************************************************
*  Library Include Files
*******************************************************************************/

/* DDS Library */
#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "PFilSlow.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQSYS_FACSCAAIRACCEC1WGHX_A_SIZE      10
#define TQSYS_FACSCAAIRACCE_RACCY_A_SIZE      10
#define TQSYS_FACSCAAIRDECE_TQDECEY_A_SIZE    12
#define TQSYS_FACSCAAIR_NENGX_A_SIZE          12
#define TQSYS_FACSCAAIR_TQX_A_SIZE            12
#define TQSYS_TQAIRX_A_SIZE                   12
#define TQSYS_TQAIRY_A_SIZE                   7

/* TqSys_stDrivFilCfPha */
#define TQSYS_PAS_DE_FILTRAGE				(UInt8)0
#define TQSYS_FILTRAGE_NOMINAL				(UInt8)1
#define TQSYS_FILTRAGE_NOMINAL_PONDERE		(UInt8)2
#define TQSYS_FILTRAGE_CORRIGE				(UInt8)3
#define TQSYS_FILTRAGE_CORRIGE_PONDERE		(UInt8)4


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
#define PFILSLOW_START_SEC_CALIB_16BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaOfsAirAcce_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaOfsAirDece_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThd_tqDeltaAirDece_C = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
#define PFILSLOW_STOP_SEC_CALIB_16BIT
#include "PFilSlow_MemMap.h"


/* 8-bits scalar calibration definition */
#define PFILSLOW_START_SEC_CALIB_8BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDrivFilAir_C = DDS_TRUE;
#define PFILSLOW_STOP_SEC_CALIB_8BIT
#include "PFilSlow_MemMap.h"

/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILSLOW_START_SEC_CARTO_16BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaAirAcceC1WghX_A
[TQSYS_FACSCAAIRACCEC1WGHX_A_SIZE] = {
(SInt16)(500 * BIN2),  (SInt16)(1000 * BIN2), (SInt16)(1500 * BIN2),
(SInt16)(2000 * BIN2), (SInt16)(2500 * BIN2), (SInt16)(3000 * BIN2),
(SInt16)(4000 * BIN2), (SInt16)(5000 * BIN2), (SInt16)(6000 * BIN2),
(SInt16)(7000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirAcceC1Wgh_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIRACCEC1WGHX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirAcceC1_nEng_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirAcceC1_rAcc_M
[TQSYS_FACSCAAIRACCE_RACCY_A_SIZE][TQSYS_TQAIRX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirDeceC1_tqDece_M
[TQSYS_FACSCAAIRDECE_TQDECEY_A_SIZE][TQSYS_TQAIRX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirAcceC1_tq_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_TQX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirAcceC2_nEng_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirAcce_rAccY_A
[TQSYS_FACSCAAIRACCE_RACCY_A_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(40 * BIN7), (UInt16)(50 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaAirDece_tqDeceY_A
[TQSYS_FACSCAAIRDECE_TQDECEY_A_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(20 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(60 * BIN4), (SInt16)(80 * BIN4), (SInt16)(100 * BIN4),
(SInt16)(120 * BIN4), (SInt16)(140 * BIN4), (SInt16)(160 * BIN4),
(SInt16)(200 * BIN4), (SInt16)(220 * BIN4), (SInt16)(240 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirDeceC1Wgh_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirDeceC1_nEng_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirDeceC1_tq_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_TQX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaAirDeceC2_nEng_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaAir_nEngX_A
[TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
(SInt16)(500 * BIN2), (SInt16)(1000 * BIN2), (SInt16)(1500 * BIN2),
(SInt16)(2000 * BIN2), (SInt16)(2500 * BIN2), (SInt16)(3000 * BIN2),
(SInt16)(4000 * BIN2), (SInt16)(4500 * BIN2), (SInt16)(5000 * BIN2),
(SInt16)(5500 * BIN2), (SInt16)(6000 * BIN2), (SInt16)(7000 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaAir_tqX_A
[TQSYS_FACSCAAIR_TQX_A_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(20 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(60 * BIN4), (SInt16)(80 * BIN4), (SInt16)(100 * BIN4),
(SInt16)(120 * BIN4), (SInt16)(140 * BIN4), (SInt16)(160 * BIN4),
(SInt16)(200 * BIN4), (SInt16)(220 * BIN4), (SInt16)(240 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqAirX_A[TQSYS_TQAIRX_A_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-20 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(40 * BIN4), (SInt16)(60 * BIN4),
(SInt16)(80 * BIN4), (SInt16)(100 * BIN4), (SInt16)(120 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(200 * BIN4), (SInt16)(240 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqAirY_A[TQSYS_TQAIRY_A_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqDeltaMinAirAcce_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqDeltaMinAirDece_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_FACSCAAIR_NENGX_A_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) },
{
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqOfsAirAcceC1_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_TQAIRX_A_SIZE] = {
{
(UInt16)(500 * BIN4), (UInt16)(500 * BIN4), (UInt16)(500 * BIN4),
(UInt16)(500 * BIN4), (UInt16)(500 * BIN4), (UInt16)(500 * BIN4),
(UInt16)(500 * BIN4), (UInt16)(500 * BIN4), (UInt16)(500 * BIN4),
(UInt16)(500 * BIN4), (UInt16)(500 * BIN4), (UInt16)(500 * BIN4) },
{
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4) },
{
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4) },
{
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4) },
{
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4) },
{
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4) },
{
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4),
(UInt16)(300 * BIN4), (UInt16)(300 * BIN4), (UInt16)(300 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsAirDeceC1_M
[TQSYS_TQAIRY_A_SIZE][TQSYS_TQAIRX_A_SIZE] = {
{
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4),
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4),
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4),
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4) },
{
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4) },
{
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4) },
{
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4) },
{
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4) },
{
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4) },
{
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4), (SInt16)(-300 * BIN4) }
};

#define PFILSLOW_STOP_SEC_CARTO_16BIT
#include "PFilSlow_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define PFILSLOW_START_SEC_VAR_32BIT
#include "PFilSlow_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) pfilslow_f04_01_limit_tq_max_sav;
STATIC VAR(SInt32, AUTOMATIC) pfilslow_f04_01_limit_tq_min_sav;
#define PFILSLOW_STOP_SEC_VAR_32BIT
#include "PFilSlow_MemMap.h"

/* Complex variable definition */
#define PFILSLOW_START_SEC_VAR_UNSPECIFIED
#include "PFilSlow_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairaccec1wgh_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairaccec1_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairaccec1_racc_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairdecec1_tqdece_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairaccec1_tq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairaccec2_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairdecec1wgh_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairdecec1_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairdecec1_tq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaairdecec2_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltaminairacce_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltaminairdece_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqofsairaccec1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqofsairdecec1_m_sav;
#define PFILSLOW_STOP_SEC_VAR_UNSPECIFIED
#include "PFilSlow_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define PFILSLOW_START_SEC_INTERNAL_VAR_16BIT
#include "PFilSlow_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facWghAcceAirC1; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facWghAcceAirC2; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facWghDeceAirC1; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facWghDeceAirC2; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkDeltaLim; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqEfcAirFilUnSat; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqOfsAcceAir; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqOfsAcceAirC1; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqOfsAir; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqOfsDeceAir; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqOfsDeceAirC1; /* BIN4 */
#define PFILSLOW_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilSlow_MemMap.h"

/* 8-bits variable definition */
#define PFILSLOW_START_SEC_INTERNAL_VAR_8BIT
#include "PFilSlow_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceAirAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceAirReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceAirAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceAirReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDrivFilAirAcv;
#define PFILSLOW_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilSlow_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILSLOW_START_SEC_CONST_UNSPECIFIED
#include "PFilSlow_MemMap.h"
STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRACCEC1WGH_M_APM = {
&tqsys_facscaairaccec1wgh_m_sav,
TQSYS_FACSCAAIRACCEC1WGHX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcceC1WghX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcceC1Wgh_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRACCEC1_NENG_M_APM = {
&tqsys_facscaairaccec1_neng_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcceC1_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRACCEC1_RACC_M_APM = {
&tqsys_facscaairaccec1_racc_m_sav,
TQSYS_TQAIRX_A_SIZE,
TQSYS_FACSCAAIRACCE_RACCY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcce_rAccY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcceC1_rAcc_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQSYS_FACSCAAIRDECEC1_TQDECE_M_APM = {
&tqsys_facscaairdecec1_tqdece_m_sav,
TQSYS_TQAIRX_A_SIZE,
TQSYS_FACSCAAIRDECE_TQDECEY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirDece_tqDeceY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirDeceC1_tqDece_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRACCEC1_TQ_M_APM = {
&tqsys_facscaairaccec1_tq_m_sav,
TQSYS_FACSCAAIR_TQX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_tqX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcceC1_tq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRACCEC2_NENG_M_APM = {
&tqsys_facscaairaccec2_neng_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirAcceC2_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRDECEC1WGH_M_APM = {
&tqsys_facscaairdecec1wgh_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirDeceC1Wgh_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRDECEC1_NENG_M_APM = {
&tqsys_facscaairdecec1_neng_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirDeceC1_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRDECEC1_TQ_M_APM = {
&tqsys_facscaairdecec1_tq_m_sav,
TQSYS_FACSCAAIR_TQX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_tqX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirDeceC1_tq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSCAAIRDECEC2_NENG_M_APM = {
&tqsys_facscaairdecec2_neng_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAirDeceC2_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_TQDELTAMINAIRACCE_M_APM = {
&tqsys_tqdeltaminairacce_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMinAirAcce_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_TQDELTAMINAIRDECE_M_APM = {
&tqsys_tqdeltaminairdece_m_sav,
TQSYS_FACSCAAIR_NENGX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facScaAir_nEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMinAirDece_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_TQOFSAIRACCEC1_M_APM = {
&tqsys_tqofsairaccec1_m_sav,
TQSYS_TQAIRX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqOfsAirAcceC1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_TQOFSAIRDECEC1_M_APM = {
&tqsys_tqofsairdecec1_m_sav,
TQSYS_TQAIRX_A_SIZE,
TQSYS_TQAIRY_A_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAirY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqOfsAirDeceC1_M[0][0]
};

#define PFILSLOW_STOP_SEC_CONST_UNSPECIFIED
#include "PFilSlow_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILSLOW_START_SEC_CODE
#include "PFilSlow_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F01_Calcul_Entrees( SInt16 tqlimem_tqlimem_par,
                                                            SInt16 tqsys_tqckefcfil_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F02_Activation( UInt16 eng_nckfil_par,
														UInt8 tqsys_nogearcorddrivfil_par,
														SInt16 tqsys_tqthdpha3it_par,
														SInt16 tqlimem_tqlimem_par,
														SInt16 tqsys_tqckefcfil_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F02_01_Activation_Acceleration( SInt16 tqsys_tqthdpha3it_par,
                                                                        SInt16 tqlimem_tqlimem_par,
                                                                        SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F02_02_Activation_Deceleration( SInt16 tqlimem_tqlimem_par,
                                                                        SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_Calcul_Reserves(    SInt16 tqsys_tqckefcfil_par,
                                                                UInt16 eng_nckfil_par,
                                                                UInt8 tqsys_nogearcorddrivfil_par,
                                                                UInt16 covsctl_raccpeng_par,
                                                                UInt8 tqsys_stdrivfilcfpha_par,
                                                                SInt16 tqsys_ndif_nengntrb_par,
                                                                UInt16 tqsys_nengdeceini_par,
                                                                UInt8 tqsys_nogeardece_par,
                                                                SInt16 tqsys_tqckdeceiniit_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_Reserves_Acceleration(   SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par,
                                                                        UInt16 covsctl_raccpeng_par,
                                                                        UInt8 tqsys_stdrivfilcfpha_par,
                                                                        SInt16 tqsys_ndif_nengntrb_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_01_Accel_Config1(    	SInt16 tqsys_tqckefcfil_par,
                                                                    	UInt16 eng_nckfil_par,
                                                                    	UInt8 tqsys_nogearcorddrivfil_par,
                                                                    	UInt16 covsctl_raccpeng_par,
                                                                    	SInt16 tqsys_ndif_nengntrb_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_01_01_Config1_Nominale(  SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par,
                                                                        UInt16 covsctl_raccpeng_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_01_02_Config1_Ponderation(   UInt8 tqsys_nogearcorddrivfil_par,
                                                                            SInt16 tqsys_ndif_nengntrb_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_02_Accel_Config2(    UInt16 eng_nckfil_par,
                                                                    UInt8 tqsys_nogearcorddrivfil_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_03_Accel_Selection(  UInt8 tqsys_stdrivfilcfpha_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_Reserves_Deceleration(   SInt16 tqsys_tqckefcfil_par,
                                                                        UInt8 tqsys_stdrivfilcfpha_par,
                                                                        UInt16 tqsys_nengdeceini_par,
                                                                        UInt8 tqsys_nogeardece_par,
                                                                        SInt16 tqsys_tqckdeceiniit_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_01_Decel_Config1(    SInt16 tqsys_tqckefcfil_par,
                                                                    UInt16 tqsys_nengdeceini_par,
                                                                    UInt8 tqsys_nogeardece_par,
                                                                    SInt16 tqsys_tqckdeceiniit_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_01_01_Config1_Nominale(  SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 tqsys_nengdeceini_par,
                                                                        UInt8 tqsys_nogeardece_par,
                                                                        SInt16 tqsys_tqckdeceiniit_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_01_02_Config1_Ponderation(   UInt16 tqsys_nengdeceini_par,
                                                                            UInt8 tqsys_nogeardece_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_02_Decel_Config2(    UInt8 tqsys_nogeardece_par,
                                                                    UInt16 tqsys_nengdeceini_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_03_Decel_Selection(  UInt8 tqsys_stdrivfilcfpha_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_03_Choix_Reserves(void);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F04_Calcul_Couple_Air(  SInt16 tqsys_tqckefcfil_par,
                                                                SInt16 tqlimem_tqlimem_par,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcairfil_ptr);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F04_01_Limitation_Couple(   SInt16 tqsys_tqckefcfil_par);

STATIC FUNC(void, AUTOMATIC) PFILSLOW_F04_02_Saturation_Couple(   SInt16 tqlimem_tqlimem_par,
                                                                    SInt16 tqsys_tqckefcfil_par,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcairfil_ptr);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILSLOW_Prev_Agr_Slow
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILSLOW_Prev_Agr_Slow(   UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                                UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                                SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                                SInt16 TqSys_nDif_nEngNTrb_swc_in, /* BIN2 */
                                                UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                                UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                UInt8 TqSys_stDrivFilCfPha_swc_in, /* BIN0 */
                                                SInt16 TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                                SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                                SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcAirFil_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT07_2710.FR.1.0 */
    PFILSLOW_F01_Calcul_Entrees(TqLimEM_tqLimEM_swc_in, TqSys_tqCkEfcFil_swc_in);

    PFILSLOW_F02_Activation(Eng_nCkFil_swc_in,
    					    TqSys_noGearCordDrivFil_swc_in,
    					    TqSys_tqThdPha3It_swc_in,
    					    TqLimEM_tqLimEM_swc_in,
    					    TqSys_tqCkEfcFil_swc_in);

    PFILSLOW_F03_Calcul_Reserves(TqSys_tqCkEfcFil_swc_in,
    							 Eng_nCkFil_swc_in,
    							 TqSys_noGearCordDrivFil_swc_in,
    							 CoVSCtl_rAccPEng_swc_in,
    							 TqSys_stDrivFilCfPha_swc_in,
    							 TqSys_nDif_nEngNTrb_swc_in,
    							 TqSys_nEngDeceIni_swc_in,
    							 TqSys_noGearDece_swc_in,
    							 TqSys_tqCkDeceIniIt_swc_in);

    PFILSLOW_F04_Calcul_Couple_Air(TqSys_tqCkEfcFil_swc_in,
    							   TqLimEM_tqLimEM_swc_in,
    							   TqSys_tqCkEfcAirFil_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILSLOW_F01_Calcul_Entrees
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F01_Calcul_Entrees( SInt16 tqlimem_tqlimem_par,
                                                            SInt16 tqsys_tqckefcfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.2.0 */
    SInt32 result;

    TqSys_bDrivFilAirAcv = TqSys_bDrivFilAir_C;

    /* BIN4 = BIN4 + BIN4 */
    /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000] */
    result = (SInt32)tqlimem_tqlimem_par - (SInt32)tqsys_tqckefcfil_par;
    TqSys_tqCkDeltaLim = (UInt16)DDS_M_LIMIT(result, (0 * BIN4), (2000 * BIN4));
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F02_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F02_Activation( UInt16 eng_nckfil_par,
                                                        UInt8 tqsys_nogearcorddrivfil_par,
                                                        SInt16 tqsys_tqthdpha3it_par,
                                                        SInt16 tqlimem_tqlimem_par,
                                                        SInt16 tqsys_tqckefcfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.3.0 */
    PFILSLOW_F02_01_Activation_Acceleration(tqsys_tqthdpha3it_par,
    										tqlimem_tqlimem_par,
    										tqsys_tqckefcfil_par,
    										eng_nckfil_par,
    										tqsys_nogearcorddrivfil_par);

    PFILSLOW_F02_02_Activation_Deceleration(tqlimem_tqlimem_par,
    										tqsys_tqckefcfil_par,
    										eng_nckfil_par,
    										tqsys_nogearcorddrivfil_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F02_01_Activation_Acceleration
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F02_01_Activation_Acceleration( SInt16 tqsys_tqthdpha3it_par,
                                                                        SInt16 tqlimem_tqlimem_par,
                                                                        SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.4.0 */

    UInt16 mapresult;
    SInt32 output;
    SInt32 add_tmp;

    /* BIN4 */
    /* [0; 2000] */
    mapresult = DDS_M_MAP3D_SUU16(&TQSYS_TQDELTAMINAIRACCE_M_APM, (SInt16)eng_nckfil_par, (UInt16)tqsys_nogearcorddrivfil_par);

    if ((SInt32)tqsys_tqckefcfil_par >= (SInt32)tqsys_tqthdpha3it_par)
    {
        /* BIN4 = BIN4 + BIN4 */
        /* [-2000; 4000] = [-2000; 2000] + [0; 2000] */
        output = (SInt32)TqSys_tqDeltaOfsAirAcce_C + (SInt32)mapresult;
    }
    else
    {
        /* BIN4 */
        /* [0; 2000] */
        output = (SInt32)mapresult;
    }

	/* [-4000; 6000] = [-2000; 4000] + [-2000; 2000] */
	add_tmp = output + (SInt32)tqsys_tqckefcfil_par;
	if((SInt32)tqlimem_tqlimem_par > add_tmp)
	{
		TqSys_bAcceAirReq = DDS_TRUE;
	}
	else
	{
		TqSys_bAcceAirReq = DDS_FALSE;
	}

    if (((SInt32)tqlimem_tqlimem_par <= (SInt32)tqsys_tqckefcfil_par)
    || ((UInt32)DDS_FALSE == (UInt32)TqSys_bDrivFilAirAcv))
    {
        TqSys_bAcceAirAcv = DDS_FALSE;
    }
    else
    {
		if ((UInt32)DDS_FALSE != (UInt32)TqSys_bAcceAirReq)
		{
			TqSys_bAcceAirAcv = DDS_TRUE;
		}
		else
		{
			/* Do nothing: keep current value */
		}
	}
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F02_02_Activation_Deceleration
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F02_02_Activation_Deceleration( SInt16 tqlimem_tqlimem_par,
                                                                        SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.5.0 */
    UInt16 mapresult;
    SInt32 output;
    SInt32 temp_sub;

	/* [0; 2000] BIN4 */
    mapresult = DDS_M_MAP3D_SUU16(&TQSYS_TQDELTAMINAIRDECE_M_APM, (SInt16)eng_nckfil_par, (UInt16)tqsys_nogearcorddrivfil_par);

    if((SInt32)tqsys_tqckefcfil_par >= (SInt32)TqSys_tqThd_tqDeltaAirDece_C)
    {
		/* BIN4 = BIN4 + BIN4 */
		/* [-2000; 4000] = [-2000; 2000] + [0; 2000] */
        output = (SInt32)TqSys_tqDeltaOfsAirDece_C + (SInt32)mapresult;
    }
    else
    {
        output = (SInt32)mapresult;
    }

	/* BIN4 = BIN4 - BIN4 */
	/* [-6000; 4000] = [-2000; 2000] - [-2000; 4000] */
	temp_sub = (SInt32)tqsys_tqckefcfil_par - output;

	if((SInt32)tqlimem_tqlimem_par < temp_sub)
	{
		TqSys_bDeceAirReq = DDS_TRUE;
	}
	else
	{
		TqSys_bDeceAirReq = DDS_FALSE;
	}

    if(((SInt32)tqlimem_tqlimem_par >= (SInt32)tqsys_tqckefcfil_par)
    || ((UInt32)DDS_FALSE == (UInt32)TqSys_bDrivFilAirAcv))
    {
        TqSys_bDeceAirAcv = 0;
    }
    else
	{
		if((UInt32)DDS_FALSE != (UInt32)TqSys_bDeceAirReq)
		{
			TqSys_bDeceAirAcv = 1;
		}
		else
		{
			/* Do nothing. */
		}
	}
}


/*******************************************************************************
*
* Function Name : PFILSLOW_F03_Calcul_Reserves
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_Calcul_Reserves(    SInt16 tqsys_tqckefcfil_par,
                                                                UInt16 eng_nckfil_par,
                                                                UInt8 tqsys_nogearcorddrivfil_par,
                                                                UInt16 covsctl_raccpeng_par,
                                                                UInt8 tqsys_stdrivfilcfpha_par,
                                                                SInt16 tqsys_ndif_nengntrb_par,
                                                                UInt16 tqsys_nengdeceini_par,
                                                                UInt8 tqsys_nogeardece_par,
                                                                SInt16 tqsys_tqckdeceiniit_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.6.0 */
    PFILSLOW_F03_01_Reserves_Acceleration(tqsys_tqckefcfil_par,
    									  eng_nckfil_par,
    									  tqsys_nogearcorddrivfil_par,
    									  covsctl_raccpeng_par,
    									  tqsys_stdrivfilcfpha_par,
    									  tqsys_ndif_nengntrb_par);

    PFILSLOW_F03_02_Reserves_Deceleration(tqsys_tqckefcfil_par,
    									  tqsys_stdrivfilcfpha_par,
    									  tqsys_nengdeceini_par,
    									  tqsys_nogeardece_par,
    									  tqsys_tqckdeceiniit_par);

    PFILSLOW_F03_03_Choix_Reserves();
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_01_Reserves_Acceleration
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_Reserves_Acceleration(   SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par,
                                                                        UInt16 covsctl_raccpeng_par,
                                                                        UInt8 tqsys_stdrivfilcfpha_par,
                                                                        SInt16 tqsys_ndif_nengntrb_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.7.0 */
    PFILSLOW_F03_01_01_Accel_Config1(tqsys_tqckefcfil_par,
    								 eng_nckfil_par,
    								 tqsys_nogearcorddrivfil_par,
    								 covsctl_raccpeng_par,
    								 tqsys_ndif_nengntrb_par);

    PFILSLOW_F03_01_02_Accel_Config2(eng_nckfil_par, tqsys_nogearcorddrivfil_par);

    PFILSLOW_F03_01_03_Accel_Selection(tqsys_stdrivfilcfpha_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_01_01_Accel_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_01_Accel_Config1(    SInt16 tqsys_tqckefcfil_par,
                                                                    UInt16 eng_nckfil_par,
                                                                    UInt8 tqsys_nogearcorddrivfil_par,
                                                                    UInt16 covsctl_raccpeng_par,
                                                                    SInt16 tqsys_ndif_nengntrb_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.8.0 */
    PFILSLOW_F03_01_01_01_Config1_Nominale(tqsys_tqckefcfil_par,
    										eng_nckfil_par,
                                            tqsys_nogearcorddrivfil_par,
                                            covsctl_raccpeng_par);

    PFILSLOW_F03_01_01_02_Config1_Ponderation(tqsys_nogearcorddrivfil_par, tqsys_ndif_nengntrb_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_01_01_01_Config1_Nominale
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_01_01_Config1_Nominale(  SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 eng_nckfil_par,
                                                                        UInt8 tqsys_nogearcorddrivfil_par,
                                                                        UInt16 covsctl_raccpeng_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.9.0 */
    UInt32 result1;
    UInt16 result2;
    UInt16 result3;
    UInt16 result4;
    UInt32 tqsys_tqofsacceairc1_tmp;

    /* BIN4 */
    /* [0; 2000] */
    result1 = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_TQOFSAIRACCEC1_M_APM, tqsys_tqckefcfil_par, (UInt16)tqsys_nogearcorddrivfil_par);
    /* BIN7 */
    /* [0; 3] */
    result2 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRACCEC1_NENG_M_APM, (SInt16)eng_nckfil_par, (UInt16)tqsys_nogearcorddrivfil_par);
    /* BIN7 */
    /* [0; 3] */
    result3 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRACCEC1_RACC_M_APM, tqsys_tqckefcfil_par, covsctl_raccpeng_par);
    /* BIN7 */
    /* [0; 3] */
    result4 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRACCEC1_TQ_M_APM, (SInt16)TqSys_tqCkDeltaLim, (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN21 = BIN7 * BIN7 * BIN7 */
    /* [0; 27] = [0; 3] * [0; 3] * [0; 3] */
    tqsys_tqofsacceairc1_tmp =  ((UInt32)result2 * (UInt32)result3) * (UInt32)result4;
    /* Only value above 1/(2000*BIN4) have influence on final result */
    /* therefore reduce resolution to BIN15 = BIN21/ BIN6 */
    tqsys_tqofsacceairc1_tmp /=  BIN6;

    if (0 == result1)
    {
        tqsys_tqofsacceairc1_tmp = 0;
    }
    else
    {
		if (tqsys_tqofsacceairc1_tmp > (DDS_UINT32_MAX/result1))
		{
			tqsys_tqofsacceairc1_tmp = DDS_UINT32_MAX;
		}
		else
		{
			/* BIN19 = BIN15 * BIN4 */
			/* [0; 4096[ */
			tqsys_tqofsacceairc1_tmp *= result1;
			/* BIN4 = BIN19 / BIN15 */
			tqsys_tqofsacceairc1_tmp /= (UInt32)BIN15;
		}
	}

    /* BIN4 */
    /* [0; 2000] */
    TqSys_tqOfsAcceAirC1 = (UInt16)DDS_M_MIN(tqsys_tqofsacceairc1_tmp, (2000 * BIN4));

}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_01_01_02_Config1_Ponderation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_01_02_Config1_Ponderation(   UInt8 tqsys_nogearcorddrivfil_par,
                                                                            SInt16 tqsys_ndif_nengntrb_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.10.0 */
    TqSys_facWghAcceAirC1 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRACCEC1WGH_M_APM,
    										tqsys_ndif_nengntrb_par,
    										(UInt16)tqsys_nogearcorddrivfil_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_01_02_Accel_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_02_Accel_Config2(    UInt16 eng_nckfil_par,
                                                                    UInt8 tqsys_nogearcorddrivfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.11.0 */
    TqSys_facWghAcceAirC2 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRACCEC2_NENG_M_APM, (SInt16)eng_nckfil_par, (UInt16)tqsys_nogearcorddrivfil_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_01_03_Accel_Selection
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_01_03_Accel_Selection(UInt8 tqsys_stdrivfilcfpha_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.12.0 */
    UInt32 temp_u32; /* BIN 11 */

    switch((UInt32)tqsys_stdrivfilcfpha_par)
    {
        case TQSYS_PAS_DE_FILTRAGE:
            TqSys_tqOfsAcceAir = 0;
        	break;
        case TQSYS_FILTRAGE_NOMINAL:
            TqSys_tqOfsAcceAir = TqSys_tqOfsAcceAirC1;
        	break;
        case TQSYS_FILTRAGE_NOMINAL_PONDERE:
            /* BIN11 = BIN4 * BIN7*/
            /* [0; 6000] = [0; 2000] * [0; 3]*/
            temp_u32 = (UInt32)TqSys_tqOfsAcceAirC1 * (UInt32)TqSys_facWghAcceAirC1;
            /* BIN4 = BIN11 / BIN7 */
            temp_u32 /= BIN7;
            /* BIN4 */
            /* [0; 2000] */
            TqSys_tqOfsAcceAir = (UInt16)DDS_M_MIN(temp_u32, (2000 * BIN4));
        	break;
        case TQSYS_FILTRAGE_CORRIGE:
            /* BIN11 = BIN4 * BIN7*/
            /* [0; 6000] = [0; 2000] * [0; 3]*/
            temp_u32 = (UInt32)TqSys_tqOfsAcceAirC1 * (UInt32)TqSys_facWghAcceAirC2;
            /* BIN4 = BIN11 / BIN7 */
            temp_u32 /= BIN7;
            /* BIN4 */
            /* [0; 2000] */
            TqSys_tqOfsAcceAir = (UInt16)DDS_M_MIN(temp_u32, (2000 * BIN4));
        	break;
        case TQSYS_FILTRAGE_CORRIGE_PONDERE:
            /* BIN11 = BIN4 * BIN7*/
            /* [0; 6000] = [0; 2000] * [0; 3]*/
            temp_u32 = (UInt32)TqSys_tqOfsAcceAirC1 * (UInt32)TqSys_facWghAcceAirC2;
            /* BIN4 = BIN11 / BIN7 */
            temp_u32 /= BIN7;
            /* BIN4 */
            /* [0; 2000] */
            TqSys_tqOfsAcceAir = (UInt16)DDS_M_MIN(temp_u32, (2000 * BIN4));
        	break;
        default:
            TqSys_tqOfsAcceAir = 0;
        	break;
    }
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_02_Reserves_Deceleration
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_Reserves_Deceleration(   SInt16 tqsys_tqckefcfil_par,
                                                                        UInt8 tqsys_stdrivfilcfpha_par,
                                                                        UInt16 tqsys_nengdeceini_par,
                                                                        UInt8 tqsys_nogeardece_par,
                                                                        SInt16 tqsys_tqckdeceiniit_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.13.0 */
    PFILSLOW_F03_02_01_Decel_Config1(tqsys_tqckefcfil_par,
                                     tqsys_nengdeceini_par,
                                     tqsys_nogeardece_par,
                                     tqsys_tqckdeceiniit_par);

    PFILSLOW_F03_02_02_Decel_Config2(tqsys_nogeardece_par, tqsys_nengdeceini_par);

    PFILSLOW_F03_02_03_Decel_Selection(tqsys_stdrivfilcfpha_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_02_01_Decel_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_01_Decel_Config1(    SInt16 tqsys_tqckefcfil_par,
                                                                    UInt16 tqsys_nengdeceini_par,
                                                                    UInt8 tqsys_nogeardece_par,
                                                                    SInt16 tqsys_tqckdeceiniit_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.14.0 */
    PFILSLOW_F03_02_01_01_Config1_Nominale(tqsys_tqckefcfil_par, tqsys_nengdeceini_par, tqsys_nogeardece_par, tqsys_tqckdeceiniit_par);

    PFILSLOW_F03_02_01_02_Config1_Ponderation(tqsys_nengdeceini_par, tqsys_nogeardece_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_02_01_01_Config1_Nominale
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_01_01_Config1_Nominale(  SInt16 tqsys_tqckefcfil_par,
                                                                        UInt16 tqsys_nengdeceini_par,
                                                                        UInt8 tqsys_nogeardece_par,
                                                                        SInt16 tqsys_tqckdeceiniit_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.15.0 */
    SInt32 result1; /* BIN 4 */
    UInt16 result2; /* BIN 7 */
    UInt16 result3; /* BIN 7 */
    UInt16 result4; /* BIN 7 */
    UInt32 temp_u32;
    UInt32 pfilslow_abs;
    SInt32 tqsys_tqofsdeceairc1_tmp; /* BIN 21 */

    /* BIN4 */
    /* [-2000; 2000] */
    result1 = (SInt32)DDS_M_MAP3D_SUS16(&TQSYS_TQOFSAIRDECEC1_M_APM, tqsys_tqckefcfil_par, (UInt16)tqsys_nogeardece_par);
    /* BIN7 */
    /* [0; 3] */
    result2 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRDECEC1_NENG_M_APM, (SInt16)tqsys_nengdeceini_par, (UInt16)tqsys_nogeardece_par);
    /* BIN7 */
    /* [0; 3] */
    result3 = DDS_M_MAP3D_SSU16(&TQSYS_FACSCAAIRDECEC1_TQDECE_M_APM, tqsys_tqckefcfil_par, tqsys_tqckdeceiniit_par);
    /* BIN7 */
    /* [0; 3] */
    result4 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRDECEC1_TQ_M_APM, (SInt16)TqSys_tqCkDeltaLim, (UInt16)tqsys_nogeardece_par);

    /* BIN21 = BIN7 * BIN7 * BIN7 */
    /* [0; 27] = [0; 3] * [0; 3] * [0; 3] */
    temp_u32 =  ((UInt32)result2 * (UInt32)result3) * (UInt32)result4;
    /* Only value above 1/(2000*BIN4) have influence on final result */
    /* therefore reduce resolution to BIN15 = BIN21/ BIN6 */
    temp_u32 /=  BIN6;

    if (0 == result1)
    {
        tqsys_tqofsdeceairc1_tmp = 0;
    }
    else
    {
		pfilslow_abs = (UInt32)DDS_M_ABS(DDS_SINT32_MAX/result1);
		if (temp_u32 > pfilslow_abs)
		{
			if(result1 < 0)
			{
				tqsys_tqofsdeceairc1_tmp = DDS_SINT32_MIN;
			}
			else
			{
				tqsys_tqofsdeceairc1_tmp = DDS_SINT32_MAX;
			}
		}
		else
		{
			/* BIN19 = BIN15 * BIN4 */
			/* ]-4096; 4096[ */
			tqsys_tqofsdeceairc1_tmp = (SInt32)temp_u32 * result1;
			/* BIN4 = BIN19 / BIN15 */
			tqsys_tqofsdeceairc1_tmp /= BIN15;
		}
	}
    /* BIN4 */
    /* [0; 2000]: limitation of tqsys_tqofsdeceairc1_tmp (]-4096; 4096[) */
    TqSys_tqOfsDeceAirC1 = (SInt16)DDS_M_LIMIT(tqsys_tqofsdeceairc1_tmp, (-2000 * BIN4), (2000 * BIN4));
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_02_01_02_Config1_Ponderation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_01_02_Config1_Ponderation(   UInt16 tqsys_nengdeceini_par,
                                                                            UInt8 tqsys_nogeardece_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.16.1 */
    TqSys_facWghDeceAirC1 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRDECEC1WGH_M_APM, (SInt16)tqsys_nengdeceini_par, (UInt16)tqsys_nogeardece_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_02_02_Decel_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_02_Decel_Config2(    UInt8 tqsys_nogeardece_par,
                                                                    UInt16 tqsys_nengdeceini_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.17.1 */
    TqSys_facWghDeceAirC2 = DDS_M_MAP3D_SUU16(&TQSYS_FACSCAAIRDECEC2_NENG_M_APM, (SInt16)tqsys_nengdeceini_par, (UInt16)tqsys_nogeardece_par);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_02_02_Decel_Selection
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_02_03_Decel_Selection(UInt8 tqsys_stdrivfilcfpha_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.18.0 */
    SInt32 temp_s32; /* BIN 11 */

    switch((UInt32)tqsys_stdrivfilcfpha_par)
    {
        case TQSYS_PAS_DE_FILTRAGE:
            TqSys_tqOfsDeceAir = 0;
        	break;
        case TQSYS_FILTRAGE_NOMINAL:
            TqSys_tqOfsDeceAir = TqSys_tqOfsDeceAirC1;
        	break;
        case TQSYS_FILTRAGE_NOMINAL_PONDERE:
            /* BIN11 = BIN4 * BIN7*/
            /* [-6000; 6000] = [-2000; 2000] * [0; 3]*/
            temp_s32 = (SInt32)TqSys_tqOfsDeceAirC1 * (SInt32)TqSys_facWghDeceAirC1;
            /* BIN4 = BIN11 / BIN7 */
            temp_s32 /= BIN7;
            /* BIN4 */
            /* [-2000; 2000] */
            TqSys_tqOfsDeceAir = (SInt16)DDS_M_LIMIT(temp_s32, (-2000 * BIN4), (2000 * BIN4));
        	break;
        case TQSYS_FILTRAGE_CORRIGE:
            /* BIN11 = BIN4 * BIN7*/
            /* [-6000; 6000] = [-2000; 2000] * [0; 3]*/
            temp_s32 = (SInt32)TqSys_tqOfsDeceAirC1 * (SInt32)TqSys_facWghDeceAirC2;
            /* BIN4 = BIN11 / BIN7 */
            temp_s32 /= BIN7;
            /* BIN4 */
            /* [-2000; 2000] */
            TqSys_tqOfsDeceAir = (SInt16)DDS_M_LIMIT(temp_s32, (-2000 * BIN4), (2000 * BIN4));
        	break;
        case TQSYS_FILTRAGE_CORRIGE_PONDERE:
            /* BIN11 = BIN4 * BIN7*/
            /* [-6000; 6000] = [-2000; 2000] * [0; 3]*/
            temp_s32 = (SInt32)TqSys_tqOfsDeceAirC1 * (SInt32)TqSys_facWghDeceAirC2;
            /* BIN4 = BIN11 / BIN7 */
            temp_s32 /= BIN7;
            /* BIN4 */
            /* [-2000; 2000] */
            TqSys_tqOfsDeceAir = (SInt16)DDS_M_LIMIT(temp_s32, (-2000 * BIN4), (2000 * BIN4));
        	break;
        default:
            TqSys_tqOfsDeceAir = 0;
        	break;
    }
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F03_03_Choix_Reserves
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F03_03_Choix_Reserves(void)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.19.0 */
    if((UInt32)DDS_FALSE == (UInt32)TqSys_bAcceAirAcv)
    {
        if((UInt32)DDS_FALSE == (UInt32)TqSys_bDeceAirAcv)
        {
            TqSys_tqOfsAir = 0;
        }
        else
        {
            TqSys_tqOfsAir = TqSys_tqOfsDeceAir;
        }
    }
    else
    {
        TqSys_tqOfsAir = (SInt16)TqSys_tqOfsAcceAir;
    }
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F04_Calcul_Couple_Air
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F04_Calcul_Couple_Air(  SInt16 tqsys_tqckefcfil_par,
                                                                SInt16 tqlimem_tqlimem_par,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcairfil_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.20.0 */
    PFILSLOW_F04_01_Limitation_Couple(tqsys_tqckefcfil_par);

    PFILSLOW_F04_02_Saturation_Couple(tqlimem_tqlimem_par, tqsys_tqckefcfil_par, tqsys_tqckefcairfil_ptr);
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F04_01_Limitation_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F04_01_Limitation_Couple(SInt16 tqsys_tqckefcfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.21.0 */
    SInt32 result;
    SInt32 max_tmp;
    SInt32 min_tmp;

    /* BIN4 = BIN4 + BIN4 */
    /* [-4000; 4000] = [-2000; 2000] + [-2000; 2000] */
    result = (SInt32)TqSys_tqOfsAir + (SInt32)tqsys_tqckefcfil_par;

    max_tmp = DDS_M_MAX(result, pfilslow_f04_01_limit_tq_max_sav);
    pfilslow_f04_01_limit_tq_max_sav = result;

    min_tmp = DDS_M_MIN(result, pfilslow_f04_01_limit_tq_min_sav);
    pfilslow_f04_01_limit_tq_min_sav = result;

    if((UInt32)DDS_FALSE != (UInt32)TqSys_bAcceAirAcv)
    {
        TqSys_tqEfcAirFilUnSat = (SInt16)DDS_M_LIMIT(max_tmp, (-2000 * BIN4), (2000 * BIN4));
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bDeceAirAcv)
        {
            TqSys_tqEfcAirFilUnSat = (SInt16)DDS_M_LIMIT(min_tmp, (-2000 * BIN4), (2000 * BIN4));
        }
        else
        {
            TqSys_tqEfcAirFilUnSat = (SInt16)DDS_M_LIMIT(result, (-2000 * BIN4), (2000 * BIN4));
        }
    }
}

/*******************************************************************************
*
* Function Name : PFILSLOW_F04_02_Saturation_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILSLOW_F04_02_Saturation_Couple(   SInt16 tqlimem_tqlimem_par,
                                                                    SInt16 tqsys_tqckefcfil_par,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcairfil_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT07_2710.FR.22.0 */
    if((UInt32)DDS_FALSE != (UInt32)TqSys_bAcceAirAcv)
    {
        *tqsys_tqckefcairfil_ptr = (SInt16)DDS_M_LIMIT((SInt32)TqSys_tqEfcAirFilUnSat,
        												(SInt32)tqsys_tqckefcfil_par,
        												(SInt32)tqlimem_tqlimem_par);
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bDeceAirAcv)
        {
            *tqsys_tqckefcairfil_ptr = (SInt16)DDS_M_MAX((SInt32)tqlimem_tqlimem_par, (SInt32)TqSys_tqEfcAirFilUnSat);
        }
        else
        {
            *tqsys_tqckefcairfil_ptr = tqlimem_tqlimem_par;
        }
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILSLOW_Prev_Agr_Slow
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILSLOW_Prev_Agr_Slow_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcAirFil_swc_out /* BIN4 */)
{

    /* SWC output */
    *TqSys_tqCkEfcAirFil_swc_out = 0; /* BIN4 */

    /* Initialize local variables */
    TqSys_facWghAcceAirC1 = 0;      /* BIN7 */
    TqSys_facWghAcceAirC2 = 0;      /* BIN7 */
    TqSys_facWghDeceAirC1 = 0;      /* BIN7 */
    TqSys_facWghDeceAirC2 = 0;      /* BIN7 */
    TqSys_tqCkDeltaLim = 0;         /* BIN4 */
    TqSys_tqEfcAirFilUnSat = 0;     /* BIN4 */
    TqSys_tqOfsAcceAir = 0;         /* BIN4 */
    TqSys_tqOfsAcceAirC1 = 0;       /* BIN4 */
    TqSys_tqOfsAir = 0;             /* BIN4 */
    TqSys_tqOfsDeceAir = 0;         /* BIN4 */
    TqSys_tqOfsDeceAirC1 = 0;       /* BIN4 */
    TqSys_bAcceAirAcv = DDS_FALSE;
    TqSys_bAcceAirReq = DDS_FALSE;
    TqSys_bDeceAirAcv = DDS_FALSE;
    TqSys_bDeceAirReq = DDS_FALSE;
    TqSys_bDrivFilAirAcv = DDS_FALSE;


    /* File Scope Non-displayable Variable */
    pfilslow_f04_01_limit_tq_max_sav = 0;
    pfilslow_f04_01_limit_tq_min_sav = 0;
}



#define PFILSLOW_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "PFilSlow_MemMap.h"
