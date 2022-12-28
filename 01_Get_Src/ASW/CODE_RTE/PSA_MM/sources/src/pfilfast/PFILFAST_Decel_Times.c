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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Decel_Times.c
* Version int :/main/C00_00/1 Date: 29/8/2013 11 h 44 m User:meme 
*    TWK_model:PFILFAST_Decel_Times_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\3 Date: 21/8/2013 13 h 26 m User:thauvin 
*    TWK_model:PFILFAST_Decel_Times_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 5/8/2013 16 h 59 m User:thauvin
*    TWK_model:PFILFAST_Decel_Times_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 15 h 50 m User:thauvin
*    TWK_model:PFILFAST_Decel_Times_C00_000_IMPL1
*    comments :dev PFilFast 14.0
* Version int :/main/L01_01/4 Date: 16/5/2011 15 h 6 m User:esnault
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1_D
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 29/4/2011 10 h 56 m User:demezil
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1_D
*    comments :for CPU optimization
* Version int :/main/L01_01/3 Date: 17/2/2011 16 h 55 m User:meme
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for 11.0
*    comments :update for 11.0
* Version dev :\main\branch_halouane\8 Date: 17/2/2011 16 h 45 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\7 Date: 17/2/2011 16 h 19 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :for PFilFast 11.0
* Version dev :\main\branch_halouane\6 Date: 17/2/2011 11 h 17 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane\5 Date: 8/2/2011 12 h 41 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update after TU
* Version dev :\main\branch_halouane\4 Date: 28/1/2011 10 h 33 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\3 Date: 28/1/2011 10 h 32 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\2 Date: 27/1/2011 16 h 32 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\1 Date: 27/1/2011 12 h 48 m User:halouane
*    TWK_model:PFILFAST_Decel_Times_L01_011_IMPL1
*    comments :update for TU
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 39 m User:esnault
*    TWK_model:PFILFAST_Decel_Times_L01_010_IMPL2
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 12/8/2010 9 h 25 m User:demezil
*    TWK_model:PFILFAST_Decel_Times_L01_010_IMPL2
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 3/8/2010 9 h 35 m User:demezil
*    TWK_model:PFILFAST_Decel_Times_L01_010_IMPL2
*    comments :For PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 5/7/2010 17 h 37 m User:demezil
*    TWK_model:PFILFAST_Decel_Times_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Decel_Times_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 30/6/2010 16 h 42 m User:demezil
*    TWK_model:PFILFAST_Decel_Times_L01_010_IMPL1
*    comments :for PFilFast e6
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/
#include "PFilFast.h"
/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define PFILFAST_8_SIZE                       8
#define PFILFAST_7_SIZE                       7
#define PFILFAST_12_SIZE                      12
#define PFILFAST_5_SIZE                       5

#define PFILFAST_CONF_0                       (UInt32)(0 * BIN0)
#define PFILFAST_CONF_1                       (UInt32)(1 * BIN0)
#define PFILFAST_CONF_2                       (UInt32)(2 * BIN0)
#define PFILFAST_CONF_3                       (UInt32)(3 * BIN0)
#define PFILFAST_CONF_4                       (UInt32)(4 * BIN0)

#define TQSYS_TIDLYPHAXCFX_MAX              (UInt32)(4000 / DEC1)
/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqSys_facSacDeceCf1; /* BIN7 */
extern VAR(SInt16, AUTOMATIC) TqSys_facScaDeceSpt; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* 16-bits calibrations definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng1_A[PFILFAST_8_SIZE]; /* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_A[PFILFAST_7_SIZE]; /* BIN0 */
extern volatile CONST(SInt16, AUTOMATIC) TqSys_tqFil_A[PFILFAST_12_SIZE]; /* BIN4 */
#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"



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
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha9; /* NDEC1 */
VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha10; /* NDEC1 */
VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha11; /* NDEC1 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyPha9Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 / DEC1), (UInt16)(1 / DEC1), (UInt16)(1 / DEC1),
(UInt16)(1 / DEC1), (UInt16)(1 / DEC1), (UInt16)(1 / DEC1),
(UInt16)(1 / DEC1), (UInt16)(1 / DEC1) },
{
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1), (UInt16)(150 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1), (UInt16)(150 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1) },
{
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1), (UInt16)(150 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1), (UInt16)(150 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1) },
{
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1), (UInt16)(150 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1), (UInt16)(150 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1) },
{
(UInt16)(130 / DEC1), (UInt16)(130 / DEC1), (UInt16)(130 / DEC1),
(UInt16)(130 / DEC1), (UInt16)(130 / DEC1), (UInt16)(130 / DEC1),
(UInt16)(130 / DEC1), (UInt16)(130 / DEC1) },
{
(UInt16)(200 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(200 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1) },
{
(UInt16)(200 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(200 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(150 / DEC1) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha9Cf1_nEng_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyPha10Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 / DEC1), (UInt16)(1 / DEC1), (UInt16)(1 / DEC1),
(UInt16)(1 / DEC1), (UInt16)(1 / DEC1), (UInt16)(1 / DEC1),
(UInt16)(1 / DEC1), (UInt16)(1 / DEC1) },
{
(UInt16)(350 / DEC1), (UInt16)(350 / DEC1), (UInt16)(350 / DEC1),
(UInt16)(350 / DEC1), (UInt16)(300 / DEC1), (UInt16)(300 / DEC1),
(UInt16)(250 / DEC1), (UInt16)(200 / DEC1) },
{
(UInt16)(450 / DEC1), (UInt16)(450 / DEC1), (UInt16)(450 / DEC1),
(UInt16)(450 / DEC1), (UInt16)(450 / DEC1), (UInt16)(450 / DEC1),
(UInt16)(350 / DEC1), (UInt16)(300 / DEC1) },
{
(UInt16)(350 / DEC1), (UInt16)(350 / DEC1), (UInt16)(350 / DEC1),
(UInt16)(350 / DEC1), (UInt16)(220 / DEC1), (UInt16)(220 / DEC1),
(UInt16)(220 / DEC1), (UInt16)(220 / DEC1) },
{
(UInt16)(350 / DEC1), (UInt16)(350 / DEC1), (UInt16)(350 / DEC1),
(UInt16)(350 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(200 / DEC1), (UInt16)(200 / DEC1) },
{
(UInt16)(300 / DEC1), (UInt16)(300 / DEC1), (UInt16)(300 / DEC1),
(UInt16)(300 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(100 / DEC1) },
{
(UInt16)(300 / DEC1), (UInt16)(300 / DEC1), (UInt16)(300 / DEC1),
(UInt16)(300 / DEC1), (UInt16)(200 / DEC1), (UInt16)(200 / DEC1),
(UInt16)(150 / DEC1), (UInt16)(100 / DEC1) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha10Cf1_nEng_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyPha11Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha11Cf1_nEng_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha11Cf1_tCo_T
[PFILFAST_8_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7),(UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tCo2_A[PFILFAST_8_SIZE] = {
(SInt16)(-40 * BIN0), (SInt16)(-20 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(20 * BIN0), (SInt16)(40 * BIN0), (SInt16)(60 * BIN0),
(SInt16)(80 * BIN0),(SInt16)(120 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyPha9Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha9Cf2_nEng_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyPha10Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha10Cf2_nEng_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyPha11Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) },
{
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1), (UInt16)(25 / DEC1),
(UInt16)(25 / DEC1), (UInt16)(25 / DEC1) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha11Cf2_nEng_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTiPha11Cf2_tCo_T
[PFILFAST_8_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlypha9cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factipha9cf1_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlypha10cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factipha10cf1_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlypha11cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factipha11cf1_neng_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_factipha11cf1_tco_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlypha9cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factipha9cf2_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlypha10cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factipha10cf2_neng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlypha11cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factipha11cf2_neng_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_factipha11cf2_tco_t_sav;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"

/* 32-bits variable definition */
#define PFILFAST_START_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) pfilfast_tqsys_facscadecespt_cpy;
#define PFILFAST_STOP_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha9Cf1; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha9Cf2; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha10Cf1; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha10Cf2; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha11Cf1; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha11Cf2; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaTiDlyPha9Cf1; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaTiDlyPha9Cf2; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaTiDlyPha10Cf1; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaTiDlyPha10Cf2; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaTiDlyPha11Cf1; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaTiDlyPha11Cf2; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha9Cf1_MP; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha9Cf2_MP; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha10Cf1_MP; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha10Cf2_MP; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha11Cf1_MP; /* NDEC1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha11Cf2_MP; /* NDEC1 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYPHA9CF1_BAS_M_APM = {
&tqsys_tidlypha9cf1_bas_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyPha9Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTIPHA9CF1_NENG_M_APM = {
&tqsys_factipha9cf1_neng_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha9Cf1_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYPHA10CF1_BAS_M_APM = {
&tqsys_tidlypha10cf1_bas_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyPha10Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTIPHA10CF1_NENG_M_APM = {
&tqsys_factipha10cf1_neng_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha10Cf1_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYPHA11CF1_BAS_M_APM = {
&tqsys_tidlypha11cf1_bas_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyPha11Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTIPHA11CF1_NENG_M_APM = {
&tqsys_factipha11cf1_neng_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha11Cf1_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_FACTIPHA11CF1_TCO_T_APM = {
&tqsys_factipha11cf1_tco_t_sav,
PFILFAST_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo2_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha11Cf1_tCo_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYPHA9CF2_BAS_M_APM = {
&tqsys_tidlypha9cf2_bas_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyPha9Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTIPHA9CF2_NENG_M_APM = {
&tqsys_factipha9cf2_neng_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha9Cf2_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYPHA10CF2_BAS_M_APM = {
&tqsys_tidlypha10cf2_bas_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyPha10Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTIPHA10CF2_NENG_M_APM = {
&tqsys_factipha10cf2_neng_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha10Cf2_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYPHA11CF2_BAS_M_APM = {
&tqsys_tidlypha11cf2_bas_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyPha11Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTIPHA11CF2_NENG_M_APM = {
&tqsys_factipha11cf2_neng_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha11Cf2_nEng_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_FACTIPHA11CF2_TCO_T_APM = {
&tqsys_factipha11cf2_tco_t_sav,
PFILFAST_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo2_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTiPha11Cf2_tCo_T[0]
};

#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_Deceleration_Times_Config1(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                   UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                   UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                   SInt16 ext_tcomes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_01_Deceleration_Times_Config1_Phase9(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                           UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                           UInt8 tqsys_nogeardece_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_02_Deceleration_Times_Config1_Phase10(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_03_Deceleration_Times_Config1_Phase11(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                               SInt16 ext_tcomes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_Deceleration_Times_Config2(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                   UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                   UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                   SInt16 ext_tcomes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_01_Deceleration_Times_Config2_Phase9(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                           UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                           UInt8 tqsys_nogeardece_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_02_Deceleration_Times_Config2_Phase10(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_03_Deceleration_Times_Config2_Phase11(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                               SInt16 ext_tcomes_par /* BIN0 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Decel_Times
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Decel_Times(SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                           UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                           UInt8 TqSys_stDrivFilCfPha_swc_in,
                                           SInt16 TqSys_tqCkDeceIniIt_swc_in /* BIN4 */)
{
    pfilfast_tqsys_facscadecespt_cpy = (SInt32)TqSys_facScaDeceSpt;


    switch((UInt32)TqSys_stDrivFilCfPha_swc_in)
    {
        case PFILFAST_CONF_1 :
            PFILFAST_F03_02_05_01_01_Deceleration_Times_Config1(TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                                                TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                                TqSys_noGearDece_swc_in, /* BIN0 */
                                                                Ext_tCoMes_swc_in /* BIN0 */);

            TqSys_tiDlyPha9 = TqSys_tiDlyPha9Cf1;
            TqSys_tiDlyPha10 = TqSys_tiDlyPha10Cf1;
            TqSys_tiDlyPha11 = TqSys_tiDlyPha11Cf1;
            break;

        case PFILFAST_CONF_2:
            PFILFAST_F03_02_05_01_01_Deceleration_Times_Config1(TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                                                TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                                TqSys_noGearDece_swc_in, /* BIN0 */
                                                                Ext_tCoMes_swc_in /* BIN0 */);

            TqSys_tiDlyPha9 = TqSys_facScaTiDlyPha9Cf1;
            TqSys_tiDlyPha10 = TqSys_facScaTiDlyPha10Cf1;
            TqSys_tiDlyPha11 = TqSys_facScaTiDlyPha11Cf1;
            break;

        case PFILFAST_CONF_3 :
            PFILFAST_F03_02_05_01_02_Deceleration_Times_Config2(TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                                                TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                                TqSys_noGearDece_swc_in, /* BIN0 */
                                                                Ext_tCoMes_swc_in /* BIN0 */);

            TqSys_tiDlyPha9 = TqSys_tiDlyPha9Cf2;
            TqSys_tiDlyPha10 = TqSys_tiDlyPha10Cf2;
            TqSys_tiDlyPha11 = TqSys_tiDlyPha11Cf2;
            break;

        case PFILFAST_CONF_4 :
            PFILFAST_F03_02_05_01_02_Deceleration_Times_Config2(TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                                                TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                                TqSys_noGearDece_swc_in, /* BIN0 */
                                                                Ext_tCoMes_swc_in /* BIN0 */);

            TqSys_tiDlyPha9 = TqSys_facScaTiDlyPha9Cf2;
            TqSys_tiDlyPha10 = TqSys_facScaTiDlyPha10Cf2;
            TqSys_tiDlyPha11 = TqSys_facScaTiDlyPha11Cf2;
            break;

        case PFILFAST_CONF_0 :
        default :
            TqSys_tiDlyPha9 = (UInt16)(0 / DEC1);
            TqSys_tiDlyPha10 = (UInt16)(0 / DEC1);
            TqSys_tiDlyPha11 = (UInt16)(0 / DEC1);
            break;
    }
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_01_Deceleration_Times_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_Deceleration_Times_Config1(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                   UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                   UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                   SInt16 ext_tcomes_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.53.0*/
    UInt32 temp_u32;
    SInt32 tqsys_facsacdececf1_cpy;

    tqsys_facsacdececf1_cpy = (SInt32)TqSys_facSacDeceCf1;

    PFILFAST_F03_02_05_01_01_01_Deceleration_Times_Config1_Phase9(tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                    tqsys_nengdeceini_par, /* BIN2 */
                                                                    tqsys_nogeardece_par /* BIN0 */);

    PFILFAST_F03_02_05_01_01_02_Deceleration_Times_Config1_Phase10(tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                   tqsys_nengdeceini_par, /* BIN2 */
                                                                   tqsys_nogeardece_par /* BIN0 */);

    PFILFAST_F03_02_05_01_01_03_Deceleration_Times_Config1_Phase11(tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                    tqsys_nengdeceini_par, /* BIN2 */
                                                                    tqsys_nogeardece_par, /* BIN0 */
                                                                    ext_tcomes_par /* BIN0 */);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + pfilfast_tqsys_facscadecespt_cpy) * (UInt32)TqSys_tiDlyPha9Cf1_MP) / BIN7;
    TqSys_tiDlyPha9Cf1 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + pfilfast_tqsys_facscadecespt_cpy) * (UInt32)TqSys_tiDlyPha10Cf1_MP) / BIN7;
    TqSys_tiDlyPha10Cf1 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + pfilfast_tqsys_facscadecespt_cpy)  * (UInt32)TqSys_tiDlyPha11Cf1_MP) / BIN7;
    TqSys_tiDlyPha11Cf1 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + tqsys_facsacdececf1_cpy) * (UInt32)TqSys_tiDlyPha9Cf1) / BIN7;
    TqSys_facScaTiDlyPha9Cf1 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + tqsys_facsacdececf1_cpy) * (UInt32)TqSys_tiDlyPha10Cf1) / BIN7;
    TqSys_facScaTiDlyPha10Cf1 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + tqsys_facsacdececf1_cpy) * (UInt32)TqSys_tiDlyPha11Cf1) / BIN7;
    TqSys_facScaTiDlyPha11Cf1 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_01_01_Deceleration_Times_Config1_Phase9
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_01_Deceleration_Times_Config1_Phase9(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                           UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                           UInt8 tqsys_nogeardece_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.54.0*/
    UInt32 tqsys_tidlypha9cf1_bas_m;
    UInt32 tqsys_factipha9cf1_neng_m;
    UInt32 temp_u32;

    tqsys_tidlypha9cf1_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYPHA9CF1_BAS_M_APM,
                                                tqsys_nengdeceini_par,
                                                (UInt16)tqsys_nogeardece_par);

    tqsys_factipha9cf1_neng_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACTIPHA9CF1_NENG_M_APM,
                                                    tqsys_tqckdeceiniit_par,
                                                    (UInt16)tqsys_nogeardece_par);

    /* 1/ DEC1 = (BIN7 * (1 / DEC1)) / BIN7 */
    temp_u32 = (tqsys_factipha9cf1_neng_m * tqsys_tidlypha9cf1_bas_m) / BIN7;
    TqSys_tiDlyPha9Cf1_MP = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_01_02_Deceleration_Times_Config1_Phase10
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_02_Deceleration_Times_Config1_Phase10(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.55.0*/
    UInt32 tqsys_tidlypha10cf1_bas_m;
    UInt32 tqsys_factipha10cf1_neng_m;
    UInt32 temp_u32;

    tqsys_tidlypha10cf1_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYPHA10CF1_BAS_M_APM,
                                                tqsys_nengdeceini_par,
                                                (UInt16)tqsys_nogeardece_par);

    tqsys_factipha10cf1_neng_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACTIPHA10CF1_NENG_M_APM,
                                                    tqsys_tqckdeceiniit_par,
                                                    (UInt16)tqsys_nogeardece_par);

    /* 1/ DEC1 = (BIN7 * (1 / DEC1)) / BIN7 */
    temp_u32 = (tqsys_factipha10cf1_neng_m * tqsys_tidlypha10cf1_bas_m) / BIN7;
    TqSys_tiDlyPha10Cf1_MP = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_01_03_Deceleration_Times_Config1_Phase11
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_01_03_Deceleration_Times_Config1_Phase11(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                               SInt16 ext_tcomes_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.56.0*/
    UInt32 tqsys_tidlypha11cf1_bas_m;
    UInt32 tqsys_factipha11cf1_neng_m;
    UInt32 tqsys_factipha11cf1_tco_t;
    UInt32 temp_u32;

    tqsys_tidlypha11cf1_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYPHA11CF1_BAS_M_APM,
                                                tqsys_nengdeceini_par,
                                                (UInt16)tqsys_nogeardece_par);

    tqsys_factipha11cf1_neng_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACTIPHA11CF1_NENG_M_APM,
                                                    tqsys_tqckdeceiniit_par,
                                                    (UInt16)tqsys_nogeardece_par);

    tqsys_factipha11cf1_tco_t = (UInt32)DDS_M_MAP2D_SU16(&TQSYS_FACTIPHA11CF1_TCO_T_APM,
                                                            ext_tcomes_par);

    /* 1/ DEC1 = (BIN7 * (1 / DEC1) * BIN7) / BIN14 */
    temp_u32 = ((tqsys_factipha11cf1_neng_m * tqsys_tidlypha11cf1_bas_m) * tqsys_factipha11cf1_tco_t) / BIN14;
    TqSys_tiDlyPha11Cf1_MP = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_02_Deceleration_Times_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_Deceleration_Times_Config2(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                   UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                   UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                   SInt16 ext_tcomes_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.57.0*/
    UInt32 temp_u32;

    PFILFAST_F03_02_05_01_02_01_Deceleration_Times_Config2_Phase9(tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                    tqsys_nengdeceini_par, /* BIN2 */
                                                                    tqsys_nogeardece_par /* BIN0 */);

    PFILFAST_F03_02_05_01_02_02_Deceleration_Times_Config2_Phase10(tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                   tqsys_nengdeceini_par, /* BIN2 */
                                                                   tqsys_nogeardece_par /* BIN0 */);

    PFILFAST_F03_02_05_01_02_03_Deceleration_Times_Config2_Phase11(tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                    tqsys_nengdeceini_par, /* BIN2 */
                                                                    tqsys_nogeardece_par, /* BIN0 */
                                                                    ext_tcomes_par /* BIN0 */);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + pfilfast_tqsys_facscadecespt_cpy)  * (UInt32)TqSys_tiDlyPha9Cf2_MP) / BIN7;
    TqSys_tiDlyPha9Cf2 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + pfilfast_tqsys_facscadecespt_cpy)  * (UInt32)TqSys_tiDlyPha10Cf2_MP) / BIN7;
    TqSys_tiDlyPha10Cf2 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = ((BIN7 + BIN7) * (1 / DEC1)) / BIN7 */
    temp_u32 = ((UInt32)((SInt32)(1 * BIN7) + pfilfast_tqsys_facscadecespt_cpy)  * (UInt32)TqSys_tiDlyPha11Cf2_MP) / BIN7;
    TqSys_tiDlyPha11Cf2 = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);

    /* 1 / DEC1 = 1 / DEC1 */
    TqSys_facScaTiDlyPha9Cf2 = TqSys_tiDlyPha9Cf2;

    /* 1 / DEC1 = 1 / DEC1 */
    TqSys_facScaTiDlyPha10Cf2 = TqSys_tiDlyPha10Cf2;

    /* 1 / DEC1 = 1 / DEC1 */
    TqSys_facScaTiDlyPha11Cf2 = TqSys_tiDlyPha11Cf2;
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_02_01_Deceleration_Times_Config2_Phase9
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_01_Deceleration_Times_Config2_Phase9(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                           UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                           UInt8 tqsys_nogeardece_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.58.0*/
    UInt32 tqsys_tidlypha9cf2_bas_m;
    UInt32 tqsys_factipha9cf2_neng_m;
    UInt32 temp_u32;

    tqsys_tidlypha9cf2_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYPHA9CF2_BAS_M_APM,
                                                tqsys_nengdeceini_par,
                                                (UInt16)tqsys_nogeardece_par);

    tqsys_factipha9cf2_neng_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACTIPHA9CF2_NENG_M_APM,
                                                    tqsys_tqckdeceiniit_par,
                                                    (UInt16)tqsys_nogeardece_par);

    /* 1/ DEC1 = (BIN7 * (1 / DEC1)) / BIN7 */
    temp_u32 = (tqsys_factipha9cf2_neng_m * tqsys_tidlypha9cf2_bas_m) / BIN7;
    TqSys_tiDlyPha9Cf2_MP = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_02_02_Deceleration_Times_Config2_Phase10
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_02_Deceleration_Times_Config2_Phase10(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.59.0*/
    UInt32 tqsys_tidlypha10cf2_bas_m;
    UInt32 tqsys_factipha10cf2_neng_m;
    UInt32 temp_u32;

    tqsys_tidlypha10cf2_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYPHA10CF2_BAS_M_APM,
                                                tqsys_nengdeceini_par,
                                                (UInt16)tqsys_nogeardece_par);

    tqsys_factipha10cf2_neng_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACTIPHA10CF2_NENG_M_APM,
                                                    tqsys_tqckdeceiniit_par,
                                                    (UInt16)tqsys_nogeardece_par);

    /* 1/ DEC1 = (BIN7 * (1 / DEC1)) / BIN7 */
    temp_u32 = (tqsys_factipha10cf2_neng_m * tqsys_tidlypha10cf2_bas_m) / BIN7;
    TqSys_tiDlyPha10Cf2_MP = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_01_02_03_Deceleration_Times_Config2_Phase11
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_01_02_03_Deceleration_Times_Config2_Phase11(SInt16 tqsys_tqckdeceiniit_par, /* BIN4 */
                                                                                               UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                               UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                                               SInt16 ext_tcomes_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.60.0*/
    UInt32 tqsys_tidlypha11cf2_bas_m;
    UInt32 tqsys_factipha11cf2_neng_m;
    UInt32 tqsys_factipha11cf2_tco_t;
    UInt32 temp_u32;

    tqsys_tidlypha11cf2_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYPHA11CF2_BAS_M_APM,
                                                tqsys_nengdeceini_par,
                                                (UInt16)tqsys_nogeardece_par);

    tqsys_factipha11cf2_neng_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACTIPHA11CF2_NENG_M_APM,
                                                    tqsys_tqckdeceiniit_par,
                                                    (UInt16)tqsys_nogeardece_par);

    tqsys_factipha11cf2_tco_t = (UInt32)DDS_M_MAP2D_SU16(&TQSYS_FACTIPHA11CF2_TCO_T_APM,
                                                            ext_tcomes_par);

    /* 1/ DEC1 = (BIN7 * (1 / DEC1) * BIN7) / BIN14 */
    temp_u32 = ((tqsys_factipha11cf2_neng_m * tqsys_tidlypha11cf2_bas_m) * tqsys_factipha11cf2_tco_t) / BIN14;
    TqSys_tiDlyPha11Cf2_MP = (UInt16)DDS_M_MIN(TQSYS_TIDLYPHAXCFX_MAX, temp_u32);
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Decel_Times_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Decel_Times_Init(void)
{
    TqSys_tiDlyPha9 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha10 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha11 = (UInt16)(0 / DEC1);

    TqSys_tiDlyPha11Cf2_MP = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha11Cf1 = (UInt16)(0 / DEC1);
    TqSys_facScaTiDlyPha10Cf1 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha11Cf1_MP = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha10Cf1 = (UInt16)(0 / DEC1);
    TqSys_facScaTiDlyPha11Cf1 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha9Cf2 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha9Cf1 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha9Cf1_MP = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha11Cf2 = (UInt16)(0 / DEC1);
    TqSys_facScaTiDlyPha11Cf2 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha9Cf2_MP = (UInt16)(0 / DEC1);
    TqSys_facScaTiDlyPha10Cf2 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha10Cf1_MP = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha10Cf2_MP = (UInt16)(0 / DEC1);
    TqSys_facScaTiDlyPha9Cf2 = (UInt16)(0 / DEC1);
    TqSys_facScaTiDlyPha9Cf1 = (UInt16)(0 / DEC1);
    TqSys_tiDlyPha10Cf2 = (UInt16)(0 / DEC1);

    pfilfast_tqsys_facscadecespt_cpy = (SInt32)0;
}

#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 14:57:16
* PERL v5.14.2
* Lib_CC 1.34
* Lib_Clipboard 1.01
* Lib_CQ 1.21
* Lib_DD_Check 2.00
* Lib_DD_Check_Checks 1.32
* Lib_DD_Check_Checks 1.34
* Lib_DD_Check_Data 2.01
* Lib_DD_Check_Utils 2.00
* Lib_DD_Compare 1.05
* Lib_DD_GenCode 3.23
* Lib_DD_Load 3.04
* Lib_DD_Load 3.06
* Lib_DD_Structure 1.10
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.02
* Lib_Gui_ComboBox 1.05
* Lib_Gui_Common 1.42
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.01
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.15
* Lib_Hash 1.30
* Lib_Log 1.25
* Lib_Pjt 1.30
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.07
* Lib_Scheduler_XML 1.45
* Lib_Spectool_Gen_DD 2.23
* Lib_Twk 1.06
* Lib_Utils 1.05
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.08
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* INPUT_SECTION *
Ext_tCoMes ; ;EXT ;deg C ;-40 ;214 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Teau post traitement envoyée à l'applicatif ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEngDeceIni ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime moteur filtré à l'activation de la décélération ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearDece ; ;TQS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilisé pendant la décélération ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_stDrivFilCfPha ;["CONF_0"*0*|"CONF_1"*1*|"CONF_2"*2*|"CONF_3"*3*|"CONF_4"*4*] ;TQS ;N/A ;0 ;4 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat de configuration du filtrage utilisé dans les calculs des coefficients ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDeceIniIt ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple à l'initialisation de la décélération ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facSacDeceCf1 ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de ponderation en configuration 1 et 3 pondere en deceleration ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaDeceSpt ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de ponderation en mode sport pondere en deceleration ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng1_A ;1{t_pfilfast_neng1_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de régime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGear_A ;1{t_pfilfast_nogear_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de rapport de boite ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqFil_A ;1{t_pfilfast_tqfil_a}PFILFAST_12_SIZE ;PFILFAST ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur du couple filtré ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

* OUTPUT_SECTION *
TqSys_tiDlyPha9 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 1 de décélération ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 2 de décélération ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 3 de décélération ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

* LOCAL_SECTION *
PFILFAST_12_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;12 ;12 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_5_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;5 ;5 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_7_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;7 ;7 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_8_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;8 ;8 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaTiDlyPha10Cf1 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée pondérée de la phase 2 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaTiDlyPha10Cf2 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée pondérée de la phase 2 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaTiDlyPha11Cf1 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée pondérée de la phase 3 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaTiDlyPha11Cf2 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée pondérée de la phase 3 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaTiDlyPha9Cf1 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée pondérée de la phase 1 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaTiDlyPha9Cf2 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée pondérée de la phase 1 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha10Cf1_nEng_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_tqCkDeceIniIt ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 10 en décélération en configuration 1 ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tqFil_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha10Cf2_nEng_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_tqCkDeceIniIt ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 10 en décélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tqFil_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha11Cf1_nEng_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_tqCkDeceIniIt ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 11 en décélération en configuration 1 ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tqFil_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha11Cf1_tCo_T ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 11 en décélération en configuration 1 en fonction de la température d'eau ;["YES"] ;DDS_M_MAP2D_SU16 ;BIN7 ;TqSys_tCo2_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha11Cf2_nEng_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_tqCkDeceIniIt ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 11 en décélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tqFil_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha11Cf2_tCo_T ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 11 en décélération en configuration 2 en fonction de la température d'eau ;["YES"] ;DDS_M_MAP2D_SU16 ;BIN7 ;TqSys_tCo2_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha9Cf1_nEng_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_tqCkDeceIniIt ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 9 en décélération en configuration 1 ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tqFil_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facTiPha9Cf2_nEng_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_tqCkDeceIniIt ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la durée de la phase 9 en décélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tqFil_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tCo2_A ;1{t_pfilfast_tco2_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[-40 -20 0 20 40 60 80 120] ;Vecteur de température d'eau ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10Cf1 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 2 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10Cf1_Bas_M ; ;TQSYS ;ms ;0 ;4000 ;10 ;["MAP"] ;["N/A"] ;TqSys_nEngDeceIni ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [350 350 350 350 300 300 250 200] [450 450 450 450 450 450 350 300] [350 350 350 350 220 220 220 220] [350 350 350 350 200 200 200 200] [300 300 300 300 200 200 150 100] [300 300 300 300 200 200 150 100] ;Durée nominale de la phase 10 en décélération en configuration 1 ;["YES"] ;DDS_M_MAP3D_U16 ;NDEC1 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10Cf1_MP ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 2 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10Cf2 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 2 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10Cf2_Bas_M ; ;TQSYS ;ms ;0 ;4000 ;10 ;["MAP"] ;["N/A"] ;TqSys_nEngDeceIni ;N/A ;N/A ;[25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] ;Durée nominale de la phase 10 en décélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_U16 ;NDEC1 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha10Cf2_MP ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 2 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11Cf1 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 3 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11Cf1_Bas_M ; ;TQSYS ;ms ;0 ;4000 ;10 ;["MAP"] ;["N/A"] ;TqSys_nEngDeceIni ;N/A ;N/A ;[25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] ;Durée nominale de la phase 11 en décélération en configuration 1 ;["YES"] ;DDS_M_MAP3D_U16 ;NDEC1 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11Cf1_MP ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 3 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11Cf2 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 3 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11Cf2_Bas_M ; ;TQSYS ;ms ;0 ;4000 ;10 ;["MAP"] ;["N/A"] ;TqSys_nEngDeceIni ;N/A ;N/A ;[25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] ;Durée nominale de la phase 11 en décélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_U16 ;NDEC1 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha11Cf2_MP ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 3 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha9Cf1 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 1 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha9Cf1_Bas_M ; ;TQSYS ;ms ;0 ;4000 ;10 ;["MAP"] ;["N/A"] ;TqSys_nEngDeceIni ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [150 150 150 150 150 150 150 150] [150 150 150 150 150 150 150 150] [150 150 150 150 150 150 150 150] [130 130 130 130 130 130 130 130] [200 200 200 200 200 200 150 150] [200 200 200 200 200 200 150 150] ;Durée nominale de la phase 9 en décélération en configuration 1 ;["YES"] ;DDS_M_MAP3D_U16 ;NDEC1 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha9Cf1_MP ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 1 de décélération en configuration 1 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha9Cf2 ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 1 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha9Cf2_Bas_M ; ;TQSYS ;ms ;0 ;4000 ;10 ;["MAP"] ;["N/A"] ;TqSys_nEngDeceIni ;N/A ;N/A ;[25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] [25 25 25 25 25 25 25 25] ;Durée nominale de la phase 9 en décélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_U16 ;NDEC1 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDlyPha9Cf2_MP ; ;TQSYS ;ms ;0 ;4000 ;10 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Durée de la phase 1 de décélération en configuration 2 ;["YES"] ;UInt16 ;NDEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng1_a ; ;PFILFAST ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng1_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_nogear_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_noGear_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tco2_a ; ;PFILFAST ;deg C ;-40 ;214 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tCo2_A ;["NO"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqfil_a ; ;PFILFAST ;Nm ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tqFil_A ;["NO"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

