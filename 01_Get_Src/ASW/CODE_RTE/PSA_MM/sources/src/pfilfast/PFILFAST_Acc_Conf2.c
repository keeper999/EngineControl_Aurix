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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Acc_Conf2.c
* Version int :/main/C00_00/1 Date: 29/8/2013 11 h 44 m User:meme 
*    TWK_model:PFILFAST_Acc_Conf2_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 23/8/2013 14 h 29 m User:thauvin 
*    TWK_model:PFILFAST_Acc_Conf2_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 13 h 40 m User:thauvin
*    TWK_model:PFILFAST_Acc_Conf2_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version int :/main/L02_02/1 Date: 12/3/2012 15 h 13 m User:esnault
*    TWK_model:PFILFAST_Acc_Conf2_L02_020_IMPL1
*    comments :for PFilFast 12.0: spec update
* Version dev :\main\branch_morisseau_pfilfast_euro6_dev\1 Date: 5/3/2012 12 h 41 m User:morisseau
*    TWK_model:PFILFAST_Acc_Conf2_L02_020_IMPL1
*    comments :for PFilFast 12.0: spec update
* Version int :/main/L02_01/1 Date: 17/2/2011 15 h 36 m User:meme
*    TWK_model:PFILFAST_Acc_Conf2_L02_010_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\4 Date: 28/1/2011 12 h 32 m User:halouane
*    TWK_model:PFILFAST_Acc_Conf2_L02_010_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\3 Date: 28/1/2011 12 h 30 m User:halouane
*    TWK_model:PFILFAST_Acc_Conf2_L02_010_IMPL1
*    comments :Update for 11.0
* Version dev :\main\branch_halouane\2 Date: 25/1/2011 17 h 31 m User:halouane
*    TWK_model:PFILFAST_Acc_Conf2_L02_010_IMPL1
*    comments :for 11.0
* Version dev :\main\branch_halouane\1 Date: 20/1/2011 11 h 25 m User:halouane
*    TWK_model:PFILFAST_Acc_Conf2_L02_010_IMPL1
*    comments :update for PFilFast11_0
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 40 m User:esnault
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL2
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\8 Date: 12/8/2010 9 h 26 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL2
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\7 Date: 30/7/2010 16 h 4 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL2
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\6 Date: 13/7/2010 12 h 21 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 7/7/2010 10 h 55 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 6/7/2010 15 h 45 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 5/7/2010 17 h 37 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 25/6/2010 14 h 36 m User:demezil
*    TWK_model:PFILFAST_Acc_Conf2_L01_010_IMPL1
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
#define PFILFAST_10_SIZE                      10
#define PFILFAST_12_SIZE                      12

#define PFILFAST_FACPHA3CF2_MAX             (SInt32)(1 * BIN7)
#define PFILFAST_FACPHACF2_MAX              (SInt32)(1 * BIN7)
#define PFILFAST_FACPHA5CF2_MAX             (UInt32)(1 * BIN16)
#define PFILFAST_TQSLOPPHA6CF2_MAX          (SInt32)(2000 * BIN11)
#define PFILFAST_TQSLOPPHA6CF2_MIN          (SInt32)(-2000 * BIN11)
#define PFILFAST_TQSLOPPHA7CF2_MAX          (SInt32)(2000 * BIN11)
#define PFILFAST_TQSLOPPHA7CF2_MIN          (SInt32)(-2000 * BIN11)
#define PFILFAST_TQSLOPPHA4CF2_MAX          (SInt32)(2000 * BIN11)
#define PFILFAST_TQSLOPPHA4CF2_MIN          (SInt32)(-2000 * BIN11)
#define PFILFAST__MP_MIN                    (SInt32)(0 * BIN7)
#define PFILFAST__MP_MAX                    (SInt32)(2 * BIN7)
#define PFILFAST_FACPRMCF2_6_MAX            (UInt32)(1 * BIN7)
#define PFILFAST_FACPRMCF2_6_MIN            (UInt32)(0 * BIN7)
#define PFILFAST_FACPRMCF2_2_MAX            (UInt32)(1 * BIN16)
#define PFILFAST_FACPRMCF2_3_MIN            (SInt32)(-2000 * BIN11)
#define PFILFAST_FACPRMCF2_3_MAX            (SInt32)(2000 * BIN11)
#define PFILFAST_FACPRMCF2_4_MIN            (SInt32)(-2000 * BIN11)
#define PFILFAST_FACPRMCF2_4_MAX            (SInt32)(2000 * BIN11)
#define PFILFAST_FACPRMCF2_5_MIN            (SInt32)(-2000 * BIN11)
#define PFILFAST_FACPRMCF2_5_MAX            (SInt32)(2000 * BIN11)
#define PFILFAST_PRMCF2_2_MAX               (UInt32)(2000 * BIN16)
#define PFILFAST_PRMCF2_3_MIN               (SInt32)(-2000 * BIN11)
#define PFILFAST_PRMCF2_3_MAX               (SInt32)(2000 * BIN11)
#define PFILFAST_PRMCF2_4_MIN               (SInt32)(-2000 * BIN11)
#define PFILFAST_PRMCF2_4_MAX               (SInt32)(2000 * BIN11)
#define PFILFAST_PRMCF2_5_MIN               (SInt32)(-2000 * BIN11)
#define PFILFAST_PRMCF2_5_MAX               (SInt32)(2000 * BIN11)
#define PFILFAST_FACPRMCF2_1_MAX			(UInt32)(1 * BIN7)
#define PFILFAST_FACPRMCF2_1_MIN			(UInt32)(0 * BIN7)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

typedef unsigned long long t_pfilfast_divtemp_u64;



/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqSys_facScaAcceCf2; /* BIN7 */
extern VAR(SInt16, AUTOMATIC) TqSys_facScaAcceSpt; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) TqSys_facScaPha3Cf2; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqSys_facMinPha3; /* BIN7 */
extern VAR(UInt8, AUTOMATIC) TqSys_facMinPhaConv; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
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
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_A[PFILFAST_7_SIZE]; /* BIN0 */
extern volatile CONST(SInt16, AUTOMATIC) TqSys_tCo1_A[PFILFAST_8_SIZE]; /* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_rAccP_A[PFILFAST_10_SIZE]; /* BIN7 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng3_A[PFILFAST_12_SIZE]; /* BIN2 */
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

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
VAR(UInt32, AUTOMATIC) TqSys_PrmCf2_2; /* BIN16 */
VAR(SInt32, AUTOMATIC) TqSys_PrmCf2_3; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_PrmCf2_4; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_PrmCf2_5; /* BIN11 */
VAR(UInt32, AUTOMATIC) TqSys_facPrmCf2_2; /* BIN16 */
VAR(SInt32, AUTOMATIC) TqSys_facPrmCf2_3; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_facPrmCf2_4; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_facPrmCf2_5; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
VAR(UInt16, AUTOMATIC) TqSys_PrmCf2_1; /* BIN7 */
VAR(UInt16, AUTOMATIC) TqSys_PrmCf2_6; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
VAR(UInt8, AUTOMATIC) TqSys_facPrmCf2_1; /* BIN7 */
VAR(UInt8, AUTOMATIC) TqSys_facPrmCf2_6; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha3Cf2_tCo_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha3Cf2_rAccP_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha3Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha5Cf2_tCo_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha5Cf2_rAccP_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha5Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) },
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) },
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) },
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) },
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) },
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) },
{
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12),
(UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12), (UInt16)(15.9997 * BIN12) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha6Cf2_tCo_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha6Cf2_rAccP_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha7Cf2_tCo_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha7Cf2_rAccP_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facSlopPha4Cf2_tCo_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPha4Cf2_rAccP_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPhaConvCf2_tCo_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPhaConvCf2_rAccP_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPhaConvCf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSlopPha6Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSlopPha7Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSlopPha4Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4),
(SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4),
(SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4),
(SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4), (SInt16)(0.5 * BIN4) },
{
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4),
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4),
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4),
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4) },
{
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4),
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4),
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4),
(SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4), (SInt16)(0.7 * BIN4) },
{
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4) },
{
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4) },
{
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(2 * BIN4) }
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha3cf2_tco_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha3cf2_raccp_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha3cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha5cf2_tco_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha5cf2_raccp_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha5cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha6cf2_tco_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha6cf2_raccp_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha7cf2_tco_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha7cf2_raccp_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facsloppha4cf2_tco_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha4cf2_raccp_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facphaconvcf2_tco_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facphaconvcf2_raccp_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facphaconvcf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsloppha6cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsloppha7cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsloppha4cf2_bas_m_sav;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt32, AUTOMATIC) TqSys_facPha5Cf2; /* BIN16 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha6Cf2; /* BIN11 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha7Cf2; /* BIN11 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha4Cf2; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facScaPha3Cf2_MP; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_facPhaCf2; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_facPha3Cf2; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACPHA3CF2_TCO_M_APM = {
&tqsys_facpha3cf2_tco_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha3Cf2_tCo_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA3CF2_RACCP_M_APM = {
&tqsys_facpha3cf2_raccp_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha3Cf2_rAccP_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA3CF2_BAS_M_APM = {
&tqsys_facpha3cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha3Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACPHA5CF2_TCO_M_APM = {
&tqsys_facpha5cf2_tco_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha5Cf2_tCo_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA5CF2_RACCP_M_APM = {
&tqsys_facpha5cf2_raccp_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha5Cf2_rAccP_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA5CF2_BAS_M_APM = {
&tqsys_facpha5cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha5Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACPHA6CF2_TCO_M_APM = {
&tqsys_facpha6cf2_tco_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha6Cf2_tCo_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA6CF2_RACCP_M_APM = {
&tqsys_facpha6cf2_raccp_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha6Cf2_rAccP_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACPHA7CF2_TCO_M_APM = {
&tqsys_facpha7cf2_tco_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha7Cf2_tCo_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA7CF2_RACCP_M_APM = {
&tqsys_facpha7cf2_raccp_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha7Cf2_rAccP_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACSLOPPHA4CF2_TCO_M_APM = {
&tqsys_facsloppha4cf2_tco_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facSlopPha4Cf2_tCo_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHA4CF2_RACCP_M_APM = {
&tqsys_facpha4cf2_raccp_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha4Cf2_rAccP_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACPHACONVCF2_TCO_M_APM = {
&tqsys_facphaconvcf2_tco_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCo1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPhaConvCf2_tCo_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHACONVCF2_RACCP_M_APM = {
&tqsys_facphaconvcf2_raccp_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPhaConvCf2_rAccP_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACPHACONVCF2_BAS_M_APM = {
&tqsys_facphaconvcf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPhaConvCf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSLOPPHA6CF2_BAS_M_APM = {
&tqsys_tqsloppha6cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSlopPha6Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSLOPPHA7CF2_BAS_M_APM = {
&tqsys_tqsloppha7cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSlopPha7Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSLOPPHA4CF2_BAS_M_APM = {
&tqsys_tqsloppha4cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSlopPha4Cf2_Bas_M[0][0]
};

#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                    UInt16 eng_nckfil_par, /* BIN2 */
                                                    SInt16 ext_tcomes_par, /* BIN0 */
                                                    UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_01_Calc_Accel_Phase3_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                UInt16 eng_nckfil_par, /* BIN2 */
                                                                                SInt16 ext_tcomes_par, /* BIN0 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_02_Calc_Accel_Phase5_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                UInt16 eng_nckfil_par, /* BIN2 */
                                                                                SInt16 ext_tcomes_par, /* BIN0 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_03_Calc_Accel_Phase6_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                UInt16 eng_nckfil_par, /* BIN2 */
                                                                                SInt16 ext_tcomes_par, /* BIN0 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_04_Calc_Accel_Phase7_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                UInt16 eng_nckfil_par, /* BIN2 */
                                                                                SInt16 ext_tcomes_par, /* BIN0 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_05_Calc_Accel_Phase4_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                UInt16 eng_nckfil_par, /* BIN2 */
                                                                                SInt16 ext_tcomes_par, /* BIN0 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_06_Calc_Accel_Phase_Conv_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                UInt16 eng_nckfil_par, /* BIN2 */
                                                                                SInt16 ext_tcomes_par, /* BIN0 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_02_ModSpt(void);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_03_FacSca(void);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Acc_Conf2
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Acc_Conf2(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 TqSys_noGearCordDrivFil_swc_in /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.41 */
    PFILFAST_F03_02_04_01_01_Cfg2(CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                    Eng_nCkFil_swc_in, /* BIN2 */
                                    Ext_tCoMes_swc_in, /* BIN0 */
                                    TqSys_noGearCordDrivFil_swc_in /* BIN0 */);

    PFILFAST_F03_02_04_01_02_ModSpt();

    PFILFAST_F03_02_04_01_03_FacSca();
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/
/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                            UInt16 eng_nckfil_par, /* BIN2 */
                                                            SInt16 ext_tcomes_par, /* BIN0 */
                                                            UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.42 */
    PFILFAST_F03_02_04_01_01_01_Calc_Accel_Phase3_Coef_Cfg2(covsctl_raccpeng_par, /* BIN7 */
                                                            eng_nckfil_par, /* BIN2 */
                                                            ext_tcomes_par, /* BIN0 */
                                                            tqsys_nogearcorddrivfil_par /* BIN0 */);

    PFILFAST_F03_02_04_01_01_02_Calc_Accel_Phase5_Coef_Cfg2(covsctl_raccpeng_par, /* BIN7 */
                                                            eng_nckfil_par, /* BIN2 */
                                                            ext_tcomes_par, /* BIN0 */
                                                            tqsys_nogearcorddrivfil_par /* BIN0 */);

    PFILFAST_F03_02_04_01_01_03_Calc_Accel_Phase6_Coef_Cfg2(covsctl_raccpeng_par, /* BIN7 */
                                                            eng_nckfil_par, /* BIN2 */
                                                            ext_tcomes_par, /* BIN0 */
                                                            tqsys_nogearcorddrivfil_par /* BIN0 */);

    PFILFAST_F03_02_04_01_01_04_Calc_Accel_Phase7_Coef_Cfg2(covsctl_raccpeng_par, /* BIN7 */
                                                            eng_nckfil_par, /* BIN2 */
                                                            ext_tcomes_par, /* BIN0 */
                                                            tqsys_nogearcorddrivfil_par /* BIN0 */);

    PFILFAST_F03_02_04_01_01_05_Calc_Accel_Phase4_Coef_Cfg2(covsctl_raccpeng_par, /* BIN7 */
                                                            eng_nckfil_par, /* BIN2 */
                                                            ext_tcomes_par, /* BIN0 */
                                                            tqsys_nogearcorddrivfil_par /* BIN0 */);

    PFILFAST_F03_02_04_01_01_06_Calc_Accel_Phase_Conv_Coef_Cfg2(covsctl_raccpeng_par, /* BIN7 */
                                                                eng_nckfil_par, /* BIN2 */
                                                                ext_tcomes_par, /* BIN0 */
                                                                tqsys_nogearcorddrivfil_par /* BIN0 */);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_01_Calc_Accel_Phase3_Coef_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_01_Calc_Accel_Phase3_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        SInt16 ext_tcomes_par, /* BIN0 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.43 */
    SInt32 tqsys_facpha3cf2_tco_m;
    SInt32 tqsys_facpha3cf2_raccp_m;
    SInt32 tqsys_facpha3cf2_bas_m;
    SInt32 temp_s32;

    tqsys_facpha3cf2_tco_m = (SInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACPHA3CF2_TCO_M_APM,
                                                        ext_tcomes_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha3cf2_raccp_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA3CF2_RACCP_M_APM,
                                                        covsctl_raccpeng_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha3cf2_bas_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA3CF2_BAS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN21 = BIN7 * BIN7 * BIN7 */
    temp_s32 = (tqsys_facpha3cf2_tco_m * tqsys_facpha3cf2_raccp_m) * tqsys_facpha3cf2_bas_m;
    /* BIN7 = (BIN21 - BIN21) / BIN14 */
    temp_s32 = ((1 * BIN21) - temp_s32) / BIN14;

    temp_s32 = DDS_M_MAX(temp_s32, (SInt32)TqSys_facMinPha3);
    TqSys_facPha3Cf2 = (UInt8)DDS_M_MIN(temp_s32, PFILFAST_FACPHA3CF2_MAX);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_02_Calc_Accel_Phase5_Coef_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_02_Calc_Accel_Phase5_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        SInt16 ext_tcomes_par, /* BIN0 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.44 */
    UInt32 tqsys_facpha5cf2_tco_m;
    UInt32 tqsys_facpha5cf2_raccp_m;
    UInt32 tqsys_facpha5cf2_bas_m;
    UInt32 temp_u32;

    tqsys_facpha5cf2_tco_m = (UInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACPHA5CF2_TCO_M_APM,
                                                        ext_tcomes_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha5cf2_raccp_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA5CF2_RACCP_M_APM,
                                                        covsctl_raccpeng_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha5cf2_bas_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA5CF2_BAS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN26 = (BIN7 * BIN7) * BIN12 */
    temp_u32 = (tqsys_facpha5cf2_tco_m * tqsys_facpha5cf2_raccp_m) * (tqsys_facpha5cf2_bas_m >> 4);
    /* BIN16 = BIN26 / BIN10 */
    temp_u32 = temp_u32 / BIN10;

    TqSys_facPha5Cf2 = DDS_M_MIN(temp_u32, PFILFAST_FACPHA5CF2_MAX);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_03_Calc_Accel_Phase6_Coef_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_03_Calc_Accel_Phase6_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        SInt16 ext_tcomes_par, /* BIN0 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.45 */
    SInt32 tqsys_facpha6cf2_tco_m;
    SInt32 tqsys_facpha6cf2_raccp_m;
    SInt32 tqsys_tqsloppha6cf2_bas_m;
    SInt32 temp_s32;

    tqsys_facpha6cf2_tco_m = (SInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACPHA6CF2_TCO_M_APM,
                                                        ext_tcomes_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha6cf2_raccp_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA6CF2_RACCP_M_APM,
                                                        covsctl_raccpeng_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_tqsloppha6cf2_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSLOPPHA6CF2_BAS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN14 = BIN7 * BIN7 */
    /* [0;9] * BIN14 */
    temp_s32 = tqsys_facpha6cf2_tco_m * tqsys_facpha6cf2_raccp_m;

    if(temp_s32 == 0)
    {
        TqSys_tqSlopPha6Cf2 = 0;
    }
    else
    {
        if( ((DDS_SINT32_MAX / temp_s32) > tqsys_tqsloppha6cf2_bas_m) &&
            ((DDS_SINT32_MIN / temp_s32) < tqsys_tqsloppha6cf2_bas_m)   )
        {
            /* BIN11 = (BIN14 * BIN4) / BIN7 */
            temp_s32 = (temp_s32 * tqsys_tqsloppha6cf2_bas_m) / BIN7;

            TqSys_tqSlopPha6Cf2 = DDS_M_LIMIT(temp_s32,
                                                PFILFAST_TQSLOPPHA6CF2_MIN,
                                                PFILFAST_TQSLOPPHA6CF2_MAX);
        }
        else
        {
            /* if overflow => product in range > [-8191;8191] * BIN18 */
            /* so TqSys_tqSlopPha6Cf2 value is MAX or MIN */
            /*  the sign is only depending of the sign of tqsys_tqsloppha6cf2_bas_m because temp_s32 > 0*/
            if(tqsys_tqsloppha6cf2_bas_m > 0)
            {
                TqSys_tqSlopPha6Cf2 = PFILFAST_TQSLOPPHA6CF2_MAX;
            }
            else
            {
                TqSys_tqSlopPha6Cf2 = PFILFAST_TQSLOPPHA6CF2_MIN;
            }
        }
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_04_Calc_Accel_Phase7_Coef_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_04_Calc_Accel_Phase7_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        SInt16 ext_tcomes_par, /* BIN0 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.46 */
    SInt32 tqsys_facpha7cf2_tco_m;
    SInt32 tqsys_facpha7cf2_raccp_m;
    SInt32 tqsys_tqsloppha7cf2_bas_m;
    SInt32 temp_s32;

    tqsys_facpha7cf2_tco_m = (SInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACPHA7CF2_TCO_M_APM,
                                                        ext_tcomes_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha7cf2_raccp_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA7CF2_RACCP_M_APM,
                                                        covsctl_raccpeng_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_tqsloppha7cf2_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSLOPPHA7CF2_BAS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN14 = BIN7 * BIN7 */
    /* [0;9] * BIN14 */
    temp_s32 = tqsys_facpha7cf2_tco_m * tqsys_facpha7cf2_raccp_m;

    if(temp_s32 == 0)
    {
        TqSys_tqSlopPha7Cf2 = 0;
    }
    else
    {
        if( ((DDS_SINT32_MAX / temp_s32) > tqsys_tqsloppha7cf2_bas_m) &&
            ((DDS_SINT32_MIN / temp_s32) < tqsys_tqsloppha7cf2_bas_m)   )
        {
            /* BIN11 = (BIN14 * BIN4) / BIN7 */
            temp_s32 = (temp_s32 * tqsys_tqsloppha7cf2_bas_m) / BIN7;

            TqSys_tqSlopPha7Cf2 = DDS_M_LIMIT(temp_s32,
                                                PFILFAST_TQSLOPPHA7CF2_MIN,
                                                PFILFAST_TQSLOPPHA7CF2_MAX);
        }
        else
        {
            /* if overflow => product in range > [-8191;8191] * BIN18 */
            /* so TqSys_tqSlopPha7Cf2 value is MAX or MIN */
            /*  the sign is only depending of the sign of tqsys_tqsloppha7cf2_bas_m because temp_s32 > 0*/
            if(tqsys_tqsloppha7cf2_bas_m > 0)
            {
                TqSys_tqSlopPha7Cf2 = PFILFAST_TQSLOPPHA7CF2_MAX;
            }
            else
            {
                TqSys_tqSlopPha7Cf2 = PFILFAST_TQSLOPPHA7CF2_MIN;
            }
        }
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_05_Calc_Accel_Phase4_Coef_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_05_Calc_Accel_Phase4_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        SInt16 ext_tcomes_par, /* BIN0 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)

{
    /* SSTG REQ_TAG : 01460_10_01107.FR.47 */
    SInt32 tqsys_facsloppha4cf2_tco_m;
    SInt32 tqsys_facpha4cf2_raccp_m;
    SInt32 tqsys_tqsloppha4cf2_bas_m;
    SInt32 temp_s32;

    tqsys_facsloppha4cf2_tco_m = (SInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACSLOPPHA4CF2_TCO_M_APM,
                                                        ext_tcomes_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facpha4cf2_raccp_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHA4CF2_RACCP_M_APM,
                                                        covsctl_raccpeng_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_tqsloppha4cf2_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSLOPPHA4CF2_BAS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN14 = BIN7 * BIN7 */
    /* [0;9] * BIN14 */
    temp_s32 = tqsys_facsloppha4cf2_tco_m * tqsys_facpha4cf2_raccp_m;

    if(temp_s32 == 0)
    {
        TqSys_tqSlopPha4Cf2 = 0;
    }
    else
    {
        if( ((DDS_SINT32_MAX / temp_s32) > tqsys_tqsloppha4cf2_bas_m) &&
            ((DDS_SINT32_MIN / temp_s32) < tqsys_tqsloppha4cf2_bas_m)   )
        {
            /* BIN11 = (BIN14 * BIN4) / BIN7 */
            temp_s32 = (temp_s32 * tqsys_tqsloppha4cf2_bas_m) / BIN7;

            TqSys_tqSlopPha4Cf2 = DDS_M_LIMIT(temp_s32,
                                                PFILFAST_TQSLOPPHA4CF2_MIN,
                                                PFILFAST_TQSLOPPHA4CF2_MAX);
        }
        else
        {
            /* if overflow => product in range > [-8191;8191] * BIN18 */
            /* so TqSys_tqSlopPha4Cf2 value is MAX or MIN */
            /*  the sign is only depending of the sign of tqsys_tqsloppha4cf2_bas_m because temp_s32 > 0*/
            if(tqsys_tqsloppha4cf2_bas_m > 0)
            {
                TqSys_tqSlopPha4Cf2 = PFILFAST_TQSLOPPHA4CF2_MAX;
            }
            else
            {
                TqSys_tqSlopPha4Cf2 = PFILFAST_TQSLOPPHA4CF2_MIN;
            }
        }
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_01_06_Calc_Accel_Phase_Conv_Coef_Cfg2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_01_06_Calc_Accel_Phase_Conv_Coef_Cfg2(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                                            UInt16 eng_nckfil_par, /* BIN2 */
                                                                                            SInt16 ext_tcomes_par, /* BIN0 */
                                                                                            UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.48.1 */
    SInt32 tqsys_facphaconvcf2_tco_m;
    SInt32 tqsys_facphaconvcf2_raccp_m;
    SInt32 tqsys_facphaconvcf2_bas_m;
    SInt32 temp_s32;

    tqsys_facphaconvcf2_tco_m = (SInt32)DDS_M_MAP3D_SUU16(&TQSYS_FACPHACONVCF2_TCO_M_APM,
                                                        ext_tcomes_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facphaconvcf2_raccp_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHACONVCF2_RACCP_M_APM,
                                                        covsctl_raccpeng_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facphaconvcf2_bas_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACPHACONVCF2_BAS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN21 = BIN7 * BIN7 * BIN7 */
    temp_s32 = (tqsys_facphaconvcf2_tco_m * tqsys_facphaconvcf2_raccp_m) * tqsys_facphaconvcf2_bas_m;
    /* BIN7 = (BIN21 - BIN21) / BIN14 */
    temp_s32 = ((1 * BIN21) - temp_s32) / BIN14;

    temp_s32 = DDS_M_MAX(temp_s32, (SInt32)TqSys_facMinPhaConv);
    TqSys_facPhaCf2 = (UInt8)DDS_M_MIN(temp_s32, PFILFAST_FACPHACF2_MAX);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_02_ModSpt
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_02_ModSpt(void)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.49 */
    SInt32 temp_s32;
    UInt32 temp_u32;
    UInt32 temp_prmcf2_u32;
    SInt32 temp_prmcf2_s32;
    UInt32 tqsys_facscaaccespt_plus_one;
    SInt32 tqsys_facscaaccespt_cpy;

    /* snapshot TqSys_facScaAcceSpt */
    tqsys_facscaaccespt_cpy = (SInt32)TqSys_facScaAcceSpt;

    /* TqSys_PrmCf2_1 */
    /* 1 / (((X + 1) / In) - X)  = In / ((X * (1 - In)) + 1) */
    /* BIN14 = (BIN7 * (BIN7 - BIN7)) + BIN14 */
    /* [0.0078125; 4] = [-0.9921875; 3] * (1 - [0; 1]) + 1 */
    temp_s32 = (tqsys_facscaaccespt_cpy * ((1 * BIN7) - (SInt32)TqSys_facPha3Cf2)) + (1 * BIN14);
    /* BIN7 = (BIN7 * BIN14) / BIN14 */
    /* [0; 128]  = [0; 1] / [0.0078125; 4] */
    TqSys_PrmCf2_1 = (UInt16)(((SInt32)TqSys_facPha3Cf2 * BIN14) / temp_s32);

    /* TqSys_PrmCf2_2 */
    /* BIN7 = BIN7 + BIN7 */
    /* [0.0078125; 4] = [-0.9921875; 3] + 1 */
    tqsys_facscaaccespt_plus_one = (UInt32)(tqsys_facscaaccespt_cpy + (SInt32)(1 * BIN7));
    /* BIN14 = (BIN7 + BIN7) * (BIN7 + BIN7) */
    /* [0.00006103515625; 16] = [0.0078125; 4]  * [0.0078125; 4]  */
    temp_u32 = tqsys_facscaaccespt_plus_one * tqsys_facscaaccespt_plus_one;
    /* BIN16 = (BIN16 * BIN14) / BIN14 */
    /* [0; 16384] = [0;1] / [0.00006103515625; 16] */
    temp_prmcf2_u32 = (TqSys_facPha5Cf2 * BIN14) / temp_u32;
	/* [0 ;2000] BIN16 */
	TqSys_PrmCf2_2 = DDS_M_MIN(temp_prmcf2_u32,PFILFAST_PRMCF2_2_MAX);

    /* TqSys_PrmCf2_3 */
    /* BIN11 = (BIN11 * BIN7) / (BIN7) */
    /* [-256000; 256000] = [-2000; 2000] / [0.0078125; 4] */
    temp_prmcf2_s32 = (TqSys_tqSlopPha6Cf2 * BIN7) / (SInt32)tqsys_facscaaccespt_plus_one;

    TqSys_PrmCf2_3 =  DDS_M_LIMIT(temp_prmcf2_s32,
                                  PFILFAST_PRMCF2_3_MIN,
                                  PFILFAST_PRMCF2_3_MAX);

    /* TqSys_PrmCf2_4 */
    /* BIN11 = (BIN11 * BIN7) / (BIN7) */
    /* [-256000; 256000] = [-2000; 2000] / [0.0078125; 4] */
    temp_prmcf2_s32 = (TqSys_tqSlopPha7Cf2 * BIN7) / (SInt32)tqsys_facscaaccespt_plus_one;
    TqSys_PrmCf2_4  =  DDS_M_LIMIT(temp_prmcf2_s32,
                                  PFILFAST_PRMCF2_4_MIN,
                                  PFILFAST_PRMCF2_4_MAX);

    /* TqSys_PrmCf2_5 */
    /* BIN11 = (BIN11 * BIN7) / (BIN7) */
    /* [-256000; 256000] = [-2000; 2000] / [0.0078125; 4] */
     temp_prmcf2_s32 = (TqSys_tqSlopPha4Cf2 * BIN7) / (SInt32)tqsys_facscaaccespt_plus_one;
     TqSys_PrmCf2_5  =  DDS_M_LIMIT(temp_prmcf2_s32,
                                  PFILFAST_PRMCF2_5_MIN,
                                  PFILFAST_PRMCF2_5_MAX);

    /* TqSys_PrmCf2_6 */
    /* 1 / (((X + 1) / In) - X)  = In / ((X * (1 - In)) + 1) */
    /* BIN14 = (BIN7 * (BIN7 - BIN7)) + BIN14 */
    /* [0.0078125; 4] = [-0.9921875; 3] * (1 - [0; 1]) + 1 */
    temp_s32 = (tqsys_facscaaccespt_cpy * ((1 * BIN7) - (SInt32)TqSys_facPhaCf2)) + (1 * BIN14);
    /* BIN7 = (BIN7 * BIN14) / BIN14 */
    /* [0; 128]  = [0; 1] / [0.0078125; 4] */
    TqSys_PrmCf2_6 = (UInt16)(((SInt32)TqSys_facPhaCf2 * BIN14) / temp_s32);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_04_01_03_FacSca
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_04_01_03_FacSca(void)

{
    /* SSTG REQ_TAG : 01460_10_01107.FR.50 */
    SInt32 temp_s32;
    UInt32 temp_u32;
    SInt32 tqsys_facscaaccecf2_cpy;
    UInt32 tqsys_facscaaccecf2_plus_one;
    t_pfilfast_divtemp_u64 temp_u64;

    tqsys_facscaaccecf2_cpy = TqSys_facScaAcceCf2;
    /* BIN7 = BIN7 + BIN7 */
	 /* [0.0078125; 4] = [-0.9921875; 3] + 1 */
    tqsys_facscaaccecf2_plus_one = (UInt32)(tqsys_facscaaccecf2_cpy + (SInt32)(1 * BIN7));

    /* BIN7 = (BIN7 * BIN7) / BIN7 */
    temp_s32 = (tqsys_facscaaccecf2_cpy * (SInt32)TqSys_facScaPha3Cf2) / BIN7;
    TqSys_facScaPha3Cf2_MP = (UInt16)DDS_M_LIMIT(temp_s32,
                                                PFILFAST__MP_MIN,
                                                PFILFAST__MP_MAX);
    /* TqSys_facPrmCf2_1 */
    /* 1 / (((X + 1) / In) - X)  = In / ((X * (1 - In)) + 1) */
    /* BIN14 = (BIN7 * (BIN7 - BIN7)) + BIN14 */
    /* [-253; 255] = [0 2] * ([-127; 1]) + 1 */
    temp_s32 = ((SInt32)TqSys_facScaPha3Cf2_MP * ((1 * BIN7) - (SInt32)TqSys_PrmCf2_1)) + (1 * BIN14);

	/*Protection of division by 0 and negative result for TqSys_facPrmCf2_1 */
	if(temp_s32 == 0)
	{
	  TqSys_facPrmCf2_1 = (UInt8)PFILFAST_FACPRMCF2_1_MAX;
	}
	else if(temp_s32 < (SInt32)0)
    {
	  TqSys_facPrmCf2_1 = (UInt8)PFILFAST_FACPRMCF2_1_MIN;
	}
	else
	{
		/* BIN7 = (BIN7 * BIN14) / BIN14 */
		/* [0; 2097152] = [0; 128] / [0,00006103515625;255] */
		temp_u32 = (((UInt32)TqSys_PrmCf2_1 * BIN14) / (UInt32)temp_s32);
    	TqSys_facPrmCf2_1 = (UInt8)DDS_M_MIN(temp_u32, PFILFAST_FACPRMCF2_1_MAX);
	}




    /* TqSys_facPrmCf2_2 */
    /* BIN14 = (BIN7 + BIN7) * (BIN7 + BIN7) */
    /* [0.00006103515625; 16] = [0.0078125; 4]  * [0.0078125; 4]  */
    temp_u32 = tqsys_facscaaccecf2_plus_one * tqsys_facscaaccecf2_plus_one;

    /* BIN16 = (BIN16 * BIN14) / BIN14 */
	/* [0;1] = [0; 2000] / [0.00006103515625; 16] */

    if((temp_u32 * BIN2) <= TqSys_PrmCf2_2) /*Borne TqSys_facPrmCf2_2 à [0 1]*/
    {
		TqSys_facPrmCf2_2 = PFILFAST_FACPRMCF2_2_MAX;
	}
	else if(TqSys_PrmCf2_2 < 262143) /* (BIN32 - 1)/BIN14) */
	{
		TqSys_facPrmCf2_2 = (TqSys_PrmCf2_2 * BIN14) / temp_u32;
	}
	else
	{
		temp_u64 = ((t_pfilfast_divtemp_u64)TqSys_PrmCf2_2 * (t_pfilfast_divtemp_u64)BIN14) / (t_pfilfast_divtemp_u64)temp_u32;


		TqSys_facPrmCf2_2 = (UInt32)temp_u64;
	}


    /* TqSys_facPrmCf2_3 */
    /* BIN11 = (BIN11 * BIN7) / (BIN7 + BIN7) */
    /* [-256000, 256000] = [-2000; 2000] / [0.0078125; 4] */
    /* <PRQA_COMMENT><2834> Not division by 0 because tqsys_facscaaccecf2_plus_one is in range [0.0078125; 4] </2834></PRQA_COMMENT>*/
    temp_s32 = (TqSys_PrmCf2_3 * BIN7) / (SInt32)tqsys_facscaaccecf2_plus_one;
    TqSys_facPrmCf2_3 = DDS_M_LIMIT(temp_s32,
                                            PFILFAST_FACPRMCF2_3_MIN,
                                            PFILFAST_FACPRMCF2_3_MAX);

    /* TqSys_facPrmCf2_4 */
    /* BIN11 = (BIN11 * BIN7) / (BIN7 + BIN7) */
    /* [-256000, 256000] = [-2000; 2000] / [0.0078125; 4] */
    /* <PRQA_COMMENT><2834> Not division by 0 because tqsys_facscaaccecf2_plus_one is in range [0.0078125; 4] </2834></PRQA_COMMENT>*/
    temp_s32 = (TqSys_PrmCf2_4 * BIN7) / (SInt32)tqsys_facscaaccecf2_plus_one;
    TqSys_facPrmCf2_4 = DDS_M_LIMIT(temp_s32,
                                            PFILFAST_FACPRMCF2_4_MIN,
                                            PFILFAST_FACPRMCF2_4_MAX);
    /* TqSys_facPrmCf2_5 */
    /* BIN11 = (BIN11 * BIN7) / (BIN7 + BIN7) */
    /* [-256000, 256000] = [-2000; 2000] / [0.0078125; 4] */
    /* <PRQA_COMMENT><2834> Not division by 0 because tqsys_facscaaccecf2_plus_one is in range [0.0078125; 4] </2834></PRQA_COMMENT>*/
    temp_s32 = (TqSys_PrmCf2_5 * BIN7) / (SInt32)tqsys_facscaaccecf2_plus_one;
    TqSys_facPrmCf2_5 = DDS_M_LIMIT(temp_s32,
                                            PFILFAST_FACPRMCF2_5_MIN,
                                            PFILFAST_FACPRMCF2_5_MAX);
    /* TqSys_facPrmCf2_6 */
    /* 1 / (((X + 1) / In) - X)  = In / ((X * (1 - In)) + 1) */
    /* BIN14 = (BIN7 * (BIN7 - BIN7)) + BIN14 */
    /* [-380; 4] = [-0.99 3] * ([-127; 1]) + 1 */
    temp_s32 = (tqsys_facscaaccecf2_cpy * ((1 * BIN7) - (SInt32)TqSys_PrmCf2_6)) + (1 * BIN14);
	/*Protection of division by 0 and negative result for TqSys_facPrmCf2_1 */
	if(temp_s32 == 0)
	{
	  TqSys_facPrmCf2_6 = (UInt8)PFILFAST_FACPRMCF2_6_MAX;
	}
	else if(temp_s32 < (SInt32)0)
    {
	  TqSys_facPrmCf2_6 = (UInt8)PFILFAST_FACPRMCF2_6_MIN;
	}
	else
	{
		/*Protection of division by 0 and negative result for TqSys_facPrmCf2_6 so new range for temp_s32=> [0,00006103515625; 4] */
		/* BIN7 = (BIN7 * BIN14) / BIN14 */
		/* [0; 2097152]  = [0; 128] / [0,00006103515625;4] */
		temp_u32 = (UInt32)(((SInt32)TqSys_PrmCf2_6 * BIN14) / temp_s32);
		TqSys_facPrmCf2_6 = (UInt8)DDS_M_MIN(temp_u32, PFILFAST_FACPRMCF2_6_MAX);
	}
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Acc_Conf2_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Acc_Conf2_Init(void)
{
    TqSys_PrmCf2_1 = (0 * BIN7);
    TqSys_PrmCf2_2 = (0 * BIN16);
    TqSys_PrmCf2_3 = (0 * BIN11);
    TqSys_PrmCf2_4 = (0 * BIN11);
    TqSys_PrmCf2_5 = (0 * BIN11);
    TqSys_PrmCf2_6 = (0 * BIN7);
    TqSys_facPrmCf2_1 = (0 * BIN7);
    TqSys_facPrmCf2_2 = (0 * BIN16);
    TqSys_facPrmCf2_3 = (0 * BIN11);
    TqSys_facPrmCf2_4 = (0 * BIN11);
    TqSys_facPrmCf2_5 = (0 * BIN11);
    TqSys_facPrmCf2_6 = (0 * BIN7);

    TqSys_facPha5Cf2 = (0 * BIN16);
    TqSys_facPhaCf2 = (0 * BIN7);
    TqSys_tqSlopPha6Cf2= (0 * BIN11);
    TqSys_facPha3Cf2 = (0 * BIN7);
    TqSys_facScaPha3Cf2_MP = (0 * BIN7);
    TqSys_tqSlopPha4Cf2 = (0 * BIN11);
    TqSys_tqSlopPha7Cf2 = (0 * BIN11);
}

#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 11:50:16
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
CoVSCtl_rAccPEng ; ;COVSCTL ;% ;0 ;100 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur pédale moteur ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Eng_nCkFil ; ;ENG ;rpm ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime moteur filtré envoyé à 10ms ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_tCoMes ; ;EXT ;deg C ;-40 ;214 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Teau post traitement envoyée à l'applicatif ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil ; ;TQSYS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilise dans la strategie ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng3_A ;1{t_pfilfast_neng3_a}PFILFAST_12_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de régime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGear_A ;1{t_pfilfast_nogear_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de rapport de boite ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccP_A ;1{t_pfilfast_raccp_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de position pedale ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tCo1_A ;1{t_pfilfast_tco1_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de température d'eau ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facMinPha3 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient minimum de la phase 0 en accélération ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facMinPhaConv ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient minimum de la phase 4 en accélération ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceCf2 ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de pondération en configuration 2 et 4 pondéré en accélération ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceSpt ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de pondération en mode sport pondéré en accélération ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaPha3Cf2 ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Facteur de modulation du filtrage pour la phase 3 en configuration 2 (point de mesure) ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

* OUTPUT_SECTION *
TqSys_PrmCf2_1 ; ;TQSYS ;N/A ;0 ;128 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[0] ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_2 ; ;TQSYS ;N/A ;0 ;2000 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[1] ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_3 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[2] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[3] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_5 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[4] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_6 ; ;TQSYS ;N/A ;0 ;128 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[5] ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_1 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[0] ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_2 ; ;TQSYS ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[1] ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_3 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[2] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[3] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_5 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[4] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_6 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[5] ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

* LOCAL_SECTION *
PFILFAST_10_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ;10 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_12_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;12 ;12 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_7_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;7 ;7 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_8_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;8 ;8 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaPha3Cf2_MP ; ;TQSYS ;N/A ;0 ;2 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Facteur de modulation du filtrage pour la phase 3 en configuration 2 (point de mesure) ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3Cf2 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 0 d'accélération en configuration 2 ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3Cf2_Bas_M ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] ;Coefficient nominal de la phase 3 en accélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3Cf2_rAccP_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour le coefficient de la phase 3 en accélération en configuration 2 fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3Cf2_tCo_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Facteur d'échelle pour le coefficient de la phase 3 en accélération en configuration 2 fonction de la température d'eau ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tCo1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha4Cf2_rAccP_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la rampe de la phase 4 en accélération en configuration 2 fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha5Cf2 ; ;TQSYS ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 1 d'accélération en configuration 2 ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha5Cf2_Bas_M ; ;TQSYS ;N/A ;0 ;15.9997 ;1/4096 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] [15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] [15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] [15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] [15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] [15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] [15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997 15.9997] ;Coefficient nominal de la phase 5 en accélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_U16 ;BIN12 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha5Cf2_rAccP_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour le coefficient de la phase 5 en accélération en configuration 2 fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha5Cf2_tCo_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Facteur d'échelle pour le coefficient de la phase 5 en accélération en configuration 2 fonction de la température d'eau ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tCo1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha6Cf2_rAccP_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la rampe de la phase 6 en accélération en configuration 2 fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha6Cf2_tCo_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la rampe de la phase 6 en accélération en configuration 2 fonction de la température d'eau ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tCo1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha7Cf2_rAccP_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la rampe de la phase 7 en accélération en configuration 2 fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha7Cf2_tCo_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la rampe de la phase 7 en accélération en configuration 2 fonction de la température d'eau ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tCo1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPhaCf2 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Gain du filtre de la phase 4 de l’accélération en config 2 ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPhaConvCf2_Bas_M ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] ;Coefficient nominal de la phase de convergence sur le couple conducteur en accélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPhaConvCf2_rAccP_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Facteur d'échelle pour le coefficient de la phase de convergence sur le couple conducteur en accélération en configuration 2 fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPhaConvCf2_tCo_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Facteur d'échelle pour le coefficient de la phase de convergence sur le couple conducteur en accélération en configuration 2 fonction de la température d'eau ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tCo1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facSlopPha4Cf2_tCo_M ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Ext_tCoMes ;N/A ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Facteur d'échelle pour la rampe de la phase 4 en accélération en configuration 2 fonction de la température d'eau ;["YES"] ;DDS_M_MAP3D_SUU16 ;BIN7 ;TqSys_tCo1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha4Cf2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur de l’incrénement de couple dans la phase 01 en config 2 ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha4Cf2_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1 1 1] [0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5] [0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7] [0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7 0.7] [2 2 2 2 2 2 2 2 2 2 2 2] [2 2 2 2 2 2 2 2 2 2 2 2] [2 2 2 2 2 2 2 2 2 2 2 2] ;Rampe nominale de la phase 4 en accélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha6Cf2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 2 d'accélération en configuration 2 ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha6Cf2_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] ;Rampe nominale de la phase 6 en accélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha7Cf2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 3 d'accélération en configuration 2 ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha7Cf2_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] [2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000] ;Rampe nominale de la phase 7 en accélération en configuration 2 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng3_a ; ;PFILFAST ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng3_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_nogear_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_noGear_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_raccp_a ; ;PFILFAST ;% ;0 ;100 ;1/128 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_rAccP_A ;["NO"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tco1_a ; ;PFILFAST ;deg C ;-40 ;214 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tCo1_A ;["NO"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

