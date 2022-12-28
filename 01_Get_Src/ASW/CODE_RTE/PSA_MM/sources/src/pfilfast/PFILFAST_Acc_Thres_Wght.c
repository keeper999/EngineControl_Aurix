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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Acc_Thres_Wght.c
* Version int :/main/C00_00/1 Date: 29/8/2013 11 h 44 m User:meme 
*    TWK_model:PFILFAST_Acc_Thres_Wght_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\4 Date: 26/8/2013 12 h 11 m User:thauvin 
*    TWK_model:PFILFAST_Acc_Thres_Wght_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\3 Date: 7/8/2013 14 h 57 m User:thauvin
*    TWK_model:PFILFAST_Acc_Thres_Wght_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 5/8/2013 15 h 50 m User:thauvin
*    TWK_model:PFILFAST_Acc_Thres_Wght_C00_000_IMPL1
*    comments :dev PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 13 h 29 m User:thauvin
*    TWK_model:PFILFAST_Acc_Thres_Wght_C00_000_IMPL1
*    comments :dev for PFilFast 14.0
* Version int :/main/L02_01/2 Date: 8/8/2012 10 h 13 m User:posmyk
*    TWK_model:PFILFAST_Acc_Thres_Wght_L02_010_IMPL1_D
*    comments :For PFilFast_13_1_e6
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\1 Date: 7/8/2012 15 h 24 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L02_010_IMPL1_D
*    comments :For PFilFast_13_1_e6
* Version int :/main/L02_01/1 Date: 26/7/2012 11 h 5 m User:posmyk
*    TWK_model:PFILFAST_Acc_Thres_Wght_L02_010_IMPL1
*    comments :For PFilFast_13_0_e6, correction for UT
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\2 Date: 24/7/2012 9 h 48 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L02_010_IMPL1
*    comments :For PFilFast_13_0_e6, correction for UT
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\1 Date: 19/7/2012 10 h 44 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L02_010_IMPL1
*    comments :For PFilFast_13_0_e6
* Version int :/main/L01_03/1 Date: 12/3/2012 15 h 13 m User:esnault
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_030_IMPL1
*    comments :for PFilFast 12.0: spec update
* Version dev :\main\branch_morisseau_pfilfast_euro6_dev\1 Date: 5/3/2012 12 h 39 m User:morisseau
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_030_IMPL1
*    comments :for PFilFast 12.0: spec update
* Version int :/main/L01_02/2 Date: 16/5/2011 15 h 7 m User:esnault
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL2_D
*    comments :correction following TU
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 11/5/2011 14 h 15 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL2_D
*    comments :correction following TU
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 29/4/2011 10 h 56 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL2_D
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/4/2011 14 h 31 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL2_D
*    comments :for CPU optimization
* Version int :/main/L01_02/1 Date: 17/2/2011 15 h 36 m User:meme
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL2
*    comments :update for PFilFast11.0
* Version dev :\main\branch_halouane\4 Date: 27/1/2011 15 h 59 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL2
*    comments :update for PFilFast11.0
* Version dev :\main\branch_halouane\3 Date: 17/1/2011 10 h 23 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL1
*    comments :update for PFilFast11
* Version dev :\main\branch_halouane\2 Date: 14/1/2011 17 h 22 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL1
*    comments :update for PFilFast11
* Version dev :\main\branch_halouane\1 Date: 14/1/2011 17 h 1 m User:halouane
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_020_IMPL1
*    comments :update for PFilFast11_0
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 40 m User:esnault
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL2
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\9 Date: 12/8/2010 10 h 13 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL2
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\8 Date: 3/8/2010 15 h 15 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL2
*    comments :For PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\7 Date: 13/7/2010 12 h 21 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\6 Date: 6/7/2010 15 h 45 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 5/7/2010 17 h 37 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
*    comments :for PFilFast
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 28/6/2010 11 h 23 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 25/6/2010 11 h 42 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 23/6/2010 16 h 14 m User:demezil
*    TWK_model:PFILFAST_Acc_Thres_Wght_L01_010_IMPL1
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

/**/
#define TQSYS_VECT_SIZE     2


#define PFILFAST_11_SIZE                      11
#define PFILFAST_12_SIZE                      12
#define PFILFAST_8_SIZE                       8
#define PFILFAST_7_SIZE                       7
#define PFILFAST_10_SIZE                      10

#define PFILFAST_CONF_0                       (UInt32)0
#define PFILFAST_CONF_1                       (UInt32)1
#define PFILFAST_CONF_2                       (UInt32)2
#define PFILFAST_CONF_3                       (UInt32)3
#define PFILFAST_CONF_4                       (UInt32)4

#define PFILFAST_TQ_MIN                     (SInt32)(-2000 * BIN4)
#define PFILFAST_TQ_MAX                     (SInt32)(2000 * BIN4)
#define PFILFAST_FAC_MIN                    (SInt32)(-0.99 * BIN7)
#define PFILFAST_FAC_MAX                    (SInt32)(3 * BIN7)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
extern VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivNotFil; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt16, AUTOMATIC) TqSys_nTrb; /* BIN2 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt8, AUTOMATIC) tqsys_stdrivfilphait_prev; /* BIN0 */
#define PFILFAST_STOP_SEC_VAR_8BIT
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
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng3_A[PFILFAST_12_SIZE]; /* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_A[PFILFAST_10_SIZE]; /* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_rAccP_A[PFILFAST_10_SIZE]; /* BIN7 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_idxTqAccuY_A[PFILFAST_10_SIZE]; /* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_A[PFILFAST_7_SIZE]; /* BIN0 */
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
VAR(SInt16, AUTOMATIC) TqSys_facSacDeceCf1; /* BIN7 */
VAR(SInt16, AUTOMATIC) TqSys_facScaAcceCf1; /* BIN7 */
VAR(SInt16, AUTOMATIC) TqSys_facScaAcceCf2; /* BIN7 */
VAR(SInt16, AUTOMATIC) TqSys_facScaAcceSpt; /* BIN7 */
VAR(SInt16, AUTOMATIC) TqSys_facScaDeceSpt; /* BIN7 */
VAR(SInt16, AUTOMATIC) TqSys_tqOfsPha3Thd; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqSys_tqThdOfsPha8Cf1; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqSys_tqThdPha2; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqSys_tqThdPha4; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqSys_tqThdPha3Phy; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTrbHys_C = (UInt16)(2000 * BIN2);
#define PFILFAST_STOP_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"


/* 8-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvFrzAccP_C = DDS_FALSE;
#define PFILFAST_STOP_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha3ThdCf2_rAccPSpt_T
[PFILFAST_10_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha3ThdCf2_rAccP_T
[PFILFAST_10_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha4_TqThdCf1Spt_T
[PFILFAST_10_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha4_TqThdCf1_T
[PFILFAST_10_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha4_TqThdCf2Spt_T
[PFILFAST_10_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha4_TqThdCf2_T
[PFILFAST_10_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facSca1AcceCf1_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facSca2AcceCf1_A[PFILFAST_10_SIZE] = {
(SInt16)(-3000 * BIN2), (SInt16)(-2000 * BIN2), (SInt16)(-1000 * BIN2),
(SInt16)(-500 * BIN2), (SInt16)(-100 * BIN2), (SInt16)(100 * BIN2),
(SInt16)(500 * BIN2), (SInt16)(1000 * BIN2), (SInt16)(2000 * BIN2),
(SInt16)(3000 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facSca2AcceCf1_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaAcceSptTyp_T
[PFILFAST_10_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaAcceSpt_M
[PFILFAST_8_SIZE][PFILFAST_7_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaCf2_Tq_M
[PFILFAST_10_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaCf2_aEng_A[PFILFAST_10_SIZE] = {
(SInt16)(-3000 * BIN2), (SInt16)(-2000 * BIN2), (SInt16)(-1000 * BIN2),
(SInt16)(-500 * BIN2), (SInt16)(-100 * BIN2), (SInt16)(100 * BIN2),
(SInt16)(500 * BIN2), (SInt16)(1000 * BIN2), (SInt16)(2000 * BIN2),
(SInt16)(3000 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaCf2_aEng_M
[PFILFAST_10_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaCf2_aTrb_A[PFILFAST_10_SIZE] = {
(SInt16)(-3000 * BIN2), (SInt16)(-2000 * BIN2), (SInt16)(-1000 * BIN2),
(SInt16)(-500 * BIN2), (SInt16)(-100 * BIN2), (SInt16)(100 * BIN2),
(SInt16)(500 * BIN2), (SInt16)(1000 * BIN2), (SInt16)(2000 * BIN2),
(SInt16)(3000 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaDeceCf1_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facScaDeceSpt_M
[PFILFAST_8_SIZE][PFILFAST_7_SIZE] = {
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) },
{
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsPha3_T
[PFILFAST_10_SIZE] = {
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdOfsPha8Cf1_A[PFILFAST_11_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0.1 * BIN7), (SInt16)(0.2 * BIN7),
(SInt16)(0.3 * BIN7), (SInt16)(0.4 * BIN7), (SInt16)(0.5 * BIN7),
(SInt16)(0.6 * BIN7), (SInt16)(0.7 * BIN7), (SInt16)(0.8 * BIN7),
(SInt16)(0.9 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdOfsPha8Cf1_T
[PFILFAST_11_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha2_M
[PFILFAST_10_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) },
{
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-30 * BIN4),
(SInt16)(-30 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf1_Accu_M
[PFILFAST_12_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf1_Driv_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf2_Accu_M
[PFILFAST_12_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf2_Driv_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha4Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) },
{
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4),
(SInt16)(7 * BIN4), (SInt16)(7 * BIN4), (SInt16)(7 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha4Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tq_facScaCf2_A[PFILFAST_10_SIZE] = {
(SInt16)(-100 * BIN4), (SInt16)(0 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(100 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(200 * BIN4), (SInt16)(250 * BIN4), (SInt16)(300 * BIN4),
(SInt16)(350 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha3_TqThdCf1Spt_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha3_TqThdCf1_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) },
{
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7) }
};
#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha3thdcf2_raccpspt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha3thdcf2_raccp_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha4_tqthdcf1spt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha4_tqthdcf1_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha4_tqthdcf2spt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha4_tqthdcf2_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facsca1accecf1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facsca2accecf1_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facscaaccespttyp_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscaaccespt_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscacf2_tq_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscacf2_aeng_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscadececf1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facscadecespt_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqofspha3_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqthdofspha8cf1_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha3cf1_accu_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha3cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha3cf1_driv_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha3cf2_accu_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha3cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha3cf2_driv_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha4cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha3_tqthdcf1spt_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpha3_tqthdcf1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha4cf2_bas_m_sav;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"


/* 16-bits variable definition */
#define PFILFAST_START_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqsys_raccpengfrz_prev;
#define PFILFAST_STOP_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf1[TQSYS_VECT_SIZE]; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha3Cf2[TQSYS_VECT_SIZE]; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha4Cf1; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha4Cf2; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_rAccPEngFrz; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACPHA3THDCF2_RACCPSPT_T_APM = {
&tqsys_facpha3thdcf2_raccpspt_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha3ThdCf2_rAccPSpt_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACPHA3THDCF2_RACCP_T_APM = {
&tqsys_facpha3thdcf2_raccp_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha3ThdCf2_rAccP_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACPHA4_TQTHDCF1SPT_T_APM = {
&tqsys_facpha4_tqthdcf1spt_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha4_TqThdCf1Spt_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACPHA4_TQTHDCF1_T_APM = {
&tqsys_facpha4_tqthdcf1_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha4_TqThdCf1_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACPHA4_TQTHDCF2SPT_T_APM = {
&tqsys_facpha4_tqthdcf2spt_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha4_TqThdCf2Spt_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACPHA4_TQTHDCF2_T_APM = {
&tqsys_facpha4_tqthdcf2_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha4_TqThdCf2_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_FACSCA1ACCECF1_M_APM = {
&tqsys_facsca1accecf1_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facSca1AcceCf1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_FACSCA2ACCECF1_M_APM = {
&tqsys_facsca2accecf1_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facSca2AcceCf1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facSca2AcceCf1_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_FACSCAACCESPTTYP_T_APM = {
&tqsys_facscaaccespttyp_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaAcceSptTyp_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_FACSCAACCESPT_M_APM = {
&tqsys_facscaaccespt_m_sav,
PFILFAST_7_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaAcceSpt_M[0][0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_FACSCACF2_TQ_M_APM = {
&tqsys_facscacf2_tq_m_sav,
PFILFAST_10_SIZE,
PFILFAST_10_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tq_facScaCf2_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaCf2_Tq_M[0][0]
};

STATIC CONST(t_dds_m_map3d_s16, AUTOMATIC) TQSYS_FACSCACF2_AENG_M_APM = {
&tqsys_facscacf2_aeng_m_sav,
PFILFAST_10_SIZE,
PFILFAST_10_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaCf2_aTrb_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaCf2_aEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaCf2_aEng_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_FACSCADECECF1_M_APM = {
&tqsys_facscadececf1_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaDeceCf1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_FACSCADECESPT_M_APM = {
&tqsys_facscadecespt_m_sav,
PFILFAST_7_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facScaDeceSpt_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_TQOFSPHA3_T_APM = {
&tqsys_tqofspha3_t_sav,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqOfsPha3_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_TQTHDOFSPHA8CF1_T_APM = {
&tqsys_tqthdofspha8cf1_t_sav,
PFILFAST_11_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdOfsPha8Cf1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdOfsPha8Cf1_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA2_M_APM = {
&tqsys_tqthdpha2_m_sav,
PFILFAST_10_SIZE,
PFILFAST_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_idxTqAccuY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA3CF1_ACCU_M_APM = {
&tqsys_tqthdpha3cf1_accu_m_sav,
PFILFAST_10_SIZE,
PFILFAST_12_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_idxTqAccuY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha3Cf1_Accu_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA3CF1_BAS_M_APM = {
&tqsys_tqthdpha3cf1_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha3Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA3CF1_DRIV_M_APM = {
&tqsys_tqthdpha3cf1_driv_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha3Cf1_Driv_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA3CF2_ACCU_M_APM = {
&tqsys_tqthdpha3cf2_accu_m_sav,
PFILFAST_10_SIZE,
PFILFAST_12_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_idxTqAccuY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha3Cf2_Accu_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA3CF2_BAS_M_APM = {
&tqsys_tqthdpha3cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha3Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA3CF2_DRIV_M_APM = {
&tqsys_tqthdpha3cf2_driv_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha3Cf2_Driv_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA4CF1_BAS_M_APM = {
&tqsys_tqthdpha4cf1_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha4Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TqSys_facPha3_TqThdCf1Spt_M_APM = {
&tqsys_facpha3_tqthdcf1spt_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha3_TqThdCf1Spt_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TqSys_facPha3_TqThdCf1_M_APM = {
&tqsys_facpha3_tqthdcf1_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_rAccP_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_facPha3_TqThdCf1_M[0][0]
};


STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA4CF2_BAS_M_APM = {
&tqsys_tqthdpha4cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC) )&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC) )&TqSys_tqThdPha4Cf2_Bas_M[0][0]
};

#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"


STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_01_01_Acceleration_Thresholds_Phase3_Config1(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_01_02_Acceleration_Thresholds_Phase3_Config2(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_02_Acceleration_Thresholds_Phase2(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                                                        SInt16 tqsys_tqthdpha3it_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_03_Acceleration_Thresholds_Phase4(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_stdrivfilcfpha_par, /* BIN0 */
                                                                        UInt8 tqdem_bmodspt_par,
                                                                        SInt16 tqsys_tqthdpha3it_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_03_01_Acceleration_Thresholds_Phase4_Config1(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    SInt16 tqsys_tqthdpha3it_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_03_02_Acceleration_Thresholds_Phase4_Config2(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    SInt16 tqsys_tqthdpha3it_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_02_Acceleration_Deceleration_Weightings_Configs1and3(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                        SInt16 tqsys_ndif_nengntrb_par, /* BIN2 */
                                                                                        UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                        UInt8 tqsys_nogeardece_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_03_Acceleration_Weightings_Configs2and4(UInt16 eng_nckfil_par, /* BIN2 */
                                                                            SInt16 tqsys_ndif_nengntrb_par, /* BIN2 */
                                                                            SInt16 treattenms_nckgrdfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_06_Acceleration_Weightings_Modspt(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                        UInt8 tqdem_bmodspt_par);
/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Acc_Thres_Wght
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Acc_Thres_Wght(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 TqDem_bModSpt_swc_in,
                                           SInt16 TqSys_nDif_nEngNTrb_swc_in, /* BIN2 */
                                           UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                           UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                           SInt16 TreatTenms_nCkGrdFil_swc_in /* BIN2 */)
{


    PFILFAST_F03_02_02_Acceleration_Deceleration_Weightings_Configs1and3(Eng_nCkFil_swc_in, /* BIN2 */
                                                                TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                                TqSys_nDif_nEngNTrb_swc_in, /* BIN2 */
                                                                TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                                TqSys_noGearDece_swc_in /* BIN0 */);

    PFILFAST_F03_02_03_Acceleration_Weightings_Configs2and4(Eng_nCkFil_swc_in, /* BIN2 */
                                                    TqSys_nDif_nEngNTrb_swc_in, /* BIN2 */
                                                    TreatTenms_nCkGrdFil_swc_in /* BIN2 */);

    PFILFAST_F03_02_06_Acceleration_Weightings_Modspt(CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                                Eng_nCkFil_swc_in, /* BIN2 */
                                                TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                                TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                TqSys_noGearDece_swc_in, /* BIN0 */
                                                TqDem_bModSpt_swc_in);
}




/*******************************************************************************
*
* Function Name : F03_02_01_Acceleration_Thresholds
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_Acceleration_Thresholds(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                             UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                             UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                             UInt8 TqSys_stDrivFilCfPha_swc_in, /* BIN0 */
                                             UInt8 TqDem_bModSpt_swc_in,
                                             UInt16 CoVSCtl_rAccPEng_swc_in,
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3It_swc_out /* BIN4 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.19.1 */
    /* Called by MSN.c */

    /* SSTG REQ_TAG : 01460_10_01107.FR.86.0 */
	/* F03_02_01_04 */
	if(((UInt32)tqsys_stdrivfilphait_prev == PFILFAST_ACCE_SET_PASS_SLOPE )
	&&((UInt32) DDS_FALSE != (UInt32)TqSys_bAcvFrzAccP_C))
	{
		TqSys_rAccPEngFrz = tqsys_raccpengfrz_prev;
	}
	else
	{
		TqSys_rAccPEngFrz = CoVSCtl_rAccPEng_swc_in;
	}

	/* Update prev*/
	tqsys_raccpengfrz_prev = TqSys_rAccPEngFrz;


    /* SSTG REQ_TAG : 01460_10_01107.FR.21.1 */
	/* F03_02_01_01 */
    switch((UInt32)TqSys_stDrivFilCfPha_swc_in)
    {
        case PFILFAST_CONF_1 :
        case PFILFAST_CONF_2 :
            PFILFAST_F03_02_01_01_01_Acceleration_Thresholds_Phase3_Config1(Eng_nCkFil_swc_in, /* BIN2 */
                                                                    TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                                    TqSys_idxTqAccu_swc_in, /* BIN0 */
                                                                    TqDem_bModSpt_swc_in);
            TqSys_tqThdPha3Phy = TqSys_tqThdPha3Cf1[0];
            *TqSys_tqThdPha3It_swc_out = TqSys_tqThdPha3Cf1[1] ;
            break;

        case PFILFAST_CONF_3 :
        case PFILFAST_CONF_4 :
            PFILFAST_F03_02_01_01_02_Acceleration_Thresholds_Phase3_Config2(Eng_nCkFil_swc_in, /* BIN2 */
                                                                    TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                                    TqSys_idxTqAccu_swc_in, /* BIN0 */
                                                                    TqDem_bModSpt_swc_in);
            TqSys_tqThdPha3Phy = TqSys_tqThdPha3Cf2[0];
            *TqSys_tqThdPha3It_swc_out = TqSys_tqThdPha3Cf2[1];
            break;

        case PFILFAST_CONF_0 :
        default :
            *TqSys_tqThdPha3It_swc_out = (SInt16)(0 * BIN4);
            TqSys_tqThdPha3Phy = (SInt16)(0 * BIN4);
            break;
    }

    PFILFAST_F03_02_01_02_Acceleration_Thresholds_Phase2(Eng_nCkFil_swc_in, /* BIN2 */
                                                TqSys_idxTqAccu_swc_in, /* BIN0 */
                                                *TqSys_tqThdPha3It_swc_out /* BIN4 */);

    PFILFAST_F03_02_01_03_Acceleration_Thresholds_Phase4(Eng_nCkFil_swc_in, /* BIN2 */
                                                TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                TqSys_stDrivFilCfPha_swc_in, /* BIN0 */
                                                TqDem_bModSpt_swc_in,
                                                *TqSys_tqThdPha3It_swc_out /* BIN4 */);
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : F03_02_01_01_01_Acceleration_Thresholds_Phase3_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_01_01_Acceleration_Thresholds_Phase3_Config1(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.22.2 */
    SInt32 tqsys_tqthdpha3cf1_bas_m;    /* BIN4 */
    SInt32 tqsys_tqthdpha3cf1_accu_m;   /* BIN4 */
    SInt32 tqsys_tqthdpha3cf1_driv_m;   /* BIN4 */
    SInt32 temp_s32;

    tqsys_tqthdpha3cf1_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA3CF1_BAS_M_APM,
                                                            eng_nckfil_par,
                                                            (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_tqthdpha3cf1_accu_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA3CF1_ACCU_M_APM,
                                                            (UInt16)tqsys_idxtqaccu_par,
                                                            eng_nckfil_par);

    tqsys_tqthdpha3cf1_driv_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA3CF1_DRIV_M_APM,
                                                            eng_nckfil_par,
                                                            (UInt16)tqsys_nogearcorddrivfil_par);

    if((UInt32)DDS_FALSE != (UInt32)tqdem_bmodspt_par)
    {
        temp_s32 = (SInt32)DDS_M_MAP3D_UUS16(&TqSys_facPha3_TqThdCf1Spt_M_APM,
                                                        TqSys_rAccPEngFrz,
                                                        (UInt16)tqsys_nogearcorddrivfil_par );
    }
    else
    {
        temp_s32 = (SInt32)DDS_M_MAP3D_UUS16(&TqSys_facPha3_TqThdCf1_M_APM,
                                                            TqSys_rAccPEngFrz,
                                                            (UInt16)tqsys_nogearcorddrivfil_par);
    }
    /* BIN11 = (BIN7 * BIN4) + (BIN4 * BIN7) + (BIN4 * BIN7) */
    temp_s32 = (temp_s32 * tqsys_tqthdpha3cf1_driv_m) + (tqsys_tqthdpha3cf1_bas_m * BIN7) + (tqsys_tqthdpha3cf1_accu_m * BIN7);
    /* BIN4 = BIN11 / BIN7 */
    temp_s32 = temp_s32 / BIN7;

	TqSys_tqThdPha3Cf1[0] = (SInt16)tqsys_tqthdpha3cf1_bas_m ;
    TqSys_tqThdPha3Cf1[1] = (SInt16)DDS_M_LIMIT(temp_s32,
                                            PFILFAST_TQ_MIN,
                                            PFILFAST_TQ_MAX);
}

/*******************************************************************************
*
* Function Name : F03_02_01_01_02_Acceleration_Thresholds_Phase3_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_01_02_Acceleration_Thresholds_Phase3_Config2(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.23 */
    SInt32 tqsys_tqthdpha3cf2_bas_m;    /* BIN4 */
    SInt32 tqsys_tqthdpha3cf2_accu_m;   /* BIN4 */
    SInt32 tqsys_tqthdpha3cf2_driv_m;   /* BIN4 */
    SInt32 temp_s32;

    tqsys_tqthdpha3cf2_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA3CF2_BAS_M_APM,
                                                            eng_nckfil_par,
                                                            (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_tqthdpha3cf2_accu_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA3CF2_ACCU_M_APM,
                                                            (UInt16)tqsys_idxtqaccu_par,
                                                            eng_nckfil_par);

    tqsys_tqthdpha3cf2_driv_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA3CF2_DRIV_M_APM,
                                                            eng_nckfil_par,
                                                            (UInt16)tqsys_nogearcorddrivfil_par);

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        temp_s32 = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACPHA3THDCF2_RACCP_T_APM,
                                                            TqSys_rAccPEngFrz);
    }
    else
    {
        temp_s32 = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACPHA3THDCF2_RACCPSPT_T_APM,
                                                                TqSys_rAccPEngFrz);
    }
    /* BIN11 = (BIN7 * BIN4) + (BIN4 * BIN7) + (BIN4 * BIN7) */
    temp_s32 = (temp_s32 * tqsys_tqthdpha3cf2_driv_m) + (tqsys_tqthdpha3cf2_bas_m * BIN7) + (tqsys_tqthdpha3cf2_accu_m * BIN7);
    /* BIN4 = BIN11 / BIN7 */
    temp_s32 = temp_s32 / BIN7;

	TqSys_tqThdPha3Cf2[0] = (SInt16)tqsys_tqthdpha3cf2_bas_m;
    TqSys_tqThdPha3Cf2[1] = (SInt16)DDS_M_LIMIT(temp_s32,
                                            PFILFAST_TQ_MIN,
                                            PFILFAST_TQ_MAX);
}

/*******************************************************************************
*
* Function Name : F03_02_01_02_Acceleration_Thresholds_Phase2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_02_Acceleration_Thresholds_Phase2(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                                                        SInt16 tqsys_tqthdpha3it_par /* BIN4 */)
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2094.FR.20.1 */
    SInt32 tqsys_tqthdpha2_m;

    tqsys_tqthdpha2_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA2_M_APM,
                                                    eng_nckfil_par,
                                                    (UInt16)tqsys_idxtqaccu_par);

    TqSys_tqThdPha2 = (SInt16)DDS_M_MIN((SInt32)tqsys_tqthdpha3it_par, tqsys_tqthdpha2_m);

    TqSys_tqOfsPha3Thd = DDS_M_MAP2D_US16(&TQSYS_TQOFSPHA3_T_APM,
                                                TqSys_rAccPEngFrz);
}

/*******************************************************************************
*
* Function Name : F03_02_01_03_Acceleration_Thresholds_Phase4
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_03_Acceleration_Thresholds_Phase4(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_stdrivfilcfpha_par, /* BIN0 */
                                                                        UInt8 tqdem_bmodspt_par,
                                                                        SInt16 tqsys_tqthdpha3it_par /* BIN4 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.24.1 */


    switch((UInt32)tqsys_stdrivfilcfpha_par)
    {
        case PFILFAST_CONF_1 :
        case PFILFAST_CONF_2 :
            PFILFAST_F03_02_01_03_01_Acceleration_Thresholds_Phase4_Config1(eng_nckfil_par, /* BIN2 */
                                                                    tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                    tqdem_bmodspt_par,
                                                                    tqsys_tqthdpha3it_par /* BIN4 */);

            TqSys_tqThdPha4 = TqSys_tqThdPha4Cf1;
            break;

        case PFILFAST_CONF_3 :
        case PFILFAST_CONF_4 :
            PFILFAST_F03_02_01_03_02_Acceleration_Thresholds_Phase4_Config2(eng_nckfil_par, /* BIN2 */
                                                                    tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                    tqdem_bmodspt_par,
                                                                    tqsys_tqthdpha3it_par /* BIN4 */);

            TqSys_tqThdPha4 = TqSys_tqThdPha4Cf2;
            break;

        case PFILFAST_CONF_0 :
        default :
            TqSys_tqThdPha4 = (SInt16)(0 * BIN4);
            break;
    }
}



/*******************************************************************************
*
* Function Name : F03_02_01_03_01_Acceleration_Thresholds_Phase4_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_03_01_Acceleration_Thresholds_Phase4_Config1(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    SInt16 tqsys_tqthdpha3it_par /* BIN4 */)
{
    /* SSTG REQ_TAG : CSCT_CGMT06_2094.FR.25.1 */
    SInt32 tqsys_tqthdpha4cf1_bas_m;    /* BIN4 */
    SInt32 temp_s32;

    tqsys_tqthdpha4cf1_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA4CF1_BAS_M_APM,
                                                            eng_nckfil_par,
                                                            (UInt16)tqsys_nogearcorddrivfil_par);

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        temp_s32 = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACPHA4_TQTHDCF1_T_APM,
                                                        TqSys_rAccPEngFrz);
    }
    else
    {
        temp_s32 = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACPHA4_TQTHDCF1SPT_T_APM,
                                                            TqSys_rAccPEngFrz);
    }
    /* BIN11 = (BIN7 * BIN4) + (BIN4 * BIN7)*/
    temp_s32 = (temp_s32 * tqsys_tqthdpha4cf1_bas_m) + ((SInt32)tqsys_tqthdpha3it_par * BIN7);
    /* BIN4 = BIN11 / BIN7 */
    temp_s32 = temp_s32 / BIN7;

    TqSys_tqThdPha4Cf1 = (SInt16)DDS_M_LIMIT(temp_s32,
                                            PFILFAST_TQ_MIN,
                                            PFILFAST_TQ_MAX);
}

/*******************************************************************************
*
* Function Name : F03_02_01_03_02_Acceleration_Thresholds_Phase4_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_01_03_02_Acceleration_Thresholds_Phase4_Config2(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    SInt16 tqsys_tqthdpha3it_par /* BIN4 */)
{
    /* SSTG REQ_TAG : CSCT_CGMT06_2094.FR.26.1 */
        SInt32 tqsys_tqthdpha4cf2_bas_m;    /* BIN4 */
        SInt32 temp_s32;

        tqsys_tqthdpha4cf2_bas_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA4CF2_BAS_M_APM,
                                                                eng_nckfil_par,
                                                                (UInt16)tqsys_nogearcorddrivfil_par);

        if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
        {
            temp_s32 = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACPHA4_TQTHDCF2_T_APM,
                                                            TqSys_rAccPEngFrz);
        }
        else
        {
            temp_s32 = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACPHA4_TQTHDCF2SPT_T_APM,
                                                                TqSys_rAccPEngFrz);
        }
        /* BIN11 = (BIN7 * BIN4) + (BIN4 * BIN7)*/
        temp_s32 = (temp_s32 * tqsys_tqthdpha4cf2_bas_m) + ((SInt32)tqsys_tqthdpha3it_par * BIN7);
        /* BIN4 = BIN11 / BIN7 */
        temp_s32 = temp_s32 / BIN7;

        TqSys_tqThdPha4Cf2 = (SInt16)DDS_M_LIMIT(temp_s32,
                                                PFILFAST_TQ_MIN,
                                                PFILFAST_TQ_MAX);
}

/*******************************************************************************
*
* Function Name : F03_02_02_Acceleration_Deceleration_Weightings_Configs1and3
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_02_Acceleration_Deceleration_Weightings_Configs1and3(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                        SInt16 tqsys_ndif_nengntrb_par, /* BIN2 */
                                                                                        UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                                        UInt8 tqsys_nogeardece_par /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.27 */
    SInt32 tqsys_facsca2accecf1_m;  /* BIN7 */
    SInt32 tqsys_facsca1accecf1_m;  /* BIN7 */
    SInt32 temp_s32;

    tqsys_facsca2accecf1_m = (SInt32)DDS_M_MAP3D_SUS16(&TQSYS_FACSCA2ACCECF1_M_APM,
                                                        tqsys_ndif_nengntrb_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    tqsys_facsca1accecf1_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_FACSCA1ACCECF1_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* BIN7 = (BIN7 * BIN7) / BIN7 */
    temp_s32 = (tqsys_facsca2accecf1_m * tqsys_facsca1accecf1_m) / BIN7;

    TqSys_facScaAcceCf1 = (SInt16)DDS_M_LIMIT(temp_s32,
                                                    PFILFAST_FAC_MIN,
                                                    PFILFAST_FAC_MAX);

    TqSys_facSacDeceCf1 = DDS_M_MAP3D_UUS16(&TQSYS_FACSCADECECF1_M_APM,
                                                    tqsys_nengdeceini_par,
                                                    (UInt16)tqsys_nogeardece_par);

    TqSys_tqThdOfsPha8Cf1 = DDS_M_MAP2D_S16(&TQSYS_TQTHDOFSPHA8CF1_T_APM,
                                                    TqSys_facSacDeceCf1);
}

/*******************************************************************************
*
* Function Name : F03_02_03_Acceleration_Weightings_Configs2and4
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_03_Acceleration_Weightings_Configs2and4(UInt16 eng_nckfil_par, /* BIN2 */
                                                                            SInt16 tqsys_ndif_nengntrb_par, /* BIN2 */
                                                                            SInt16 treattenms_nckgrdfil_par /* BIN2 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.28.1 */
    SInt32 tqsys_facscacf2_aeng_m;  /* BIN7 */
    SInt32 tqsys_facscacf2_tq_m;    /* BIN7 */
    SInt32 temp_s32;


    temp_s32 = (SInt32)TqSys_nTrb + (SInt32)TqSys_nTrbHys_C;
    if(temp_s32 < (SInt32)eng_nckfil_par)
    {
        TqSys_facScaAcceCf2 = (SInt16)(0 * BIN7);
    }
    else
    {
        tqsys_facscacf2_aeng_m = (SInt32)DDS_M_MAP3D_S16(&TQSYS_FACSCACF2_AENG_M_APM,
                                                            treattenms_nckgrdfil_par,
                                                            tqsys_ndif_nengntrb_par);

        tqsys_facscacf2_tq_m = (SInt32)DDS_M_MAP3D_SUS16(&TQSYS_FACSCACF2_TQ_M_APM,
                                                            (SInt16)(TqSys_tqCkDrivNotFil / BIN7),
                                                            eng_nckfil_par);

        /* BIN7 = (BIN7 * BIN7) / BIN7 */
        temp_s32 = (tqsys_facscacf2_aeng_m * tqsys_facscacf2_tq_m) / BIN7;

        TqSys_facScaAcceCf2 = (SInt16)DDS_M_LIMIT(temp_s32,
                                                        PFILFAST_FAC_MIN,
                                                        PFILFAST_FAC_MAX);
    }
}

/*******************************************************************************
*
* Function Name : F03_02_06_Acceleration_Weightings_ModSpt
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_06_Acceleration_Weightings_Modspt(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt16 tqsys_nengdeceini_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_nogeardece_par, /* BIN0 */
                                                                        UInt8 tqdem_bmodspt_par)

{
    /* SSTG REQ_TAG : 01460_10_01107.FR.72 */
    SInt32 tqsys_facscaaccespt_m;   /* BIN7 */
    SInt32 tqsys_facscaaccespttyp_t;    /* BIN7 */
    SInt32 tqsys_facscadecespt_m;   /* BIN7 */
    SInt32 temp_s32;

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        TqSys_facScaDeceSpt = (SInt16)(0 * BIN7);
        TqSys_facScaAcceSpt = (SInt16)(0 * BIN7);
    }
    else
    {
        tqsys_facscaaccespt_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_FACSCAACCESPT_M_APM,
                                                        (UInt16)tqsys_nogearcorddrivfil_par,
                                                        eng_nckfil_par);

        tqsys_facscaaccespttyp_t = (SInt32)DDS_M_MAP2D_US16(&TQSYS_FACSCAACCESPTTYP_T_APM,
                                                            covsctl_raccpeng_par);

        /* BIN7 = (BIN7 * BIN7) / BIN7 */
        temp_s32 = (tqsys_facscaaccespt_m * tqsys_facscaaccespttyp_t) / BIN7;

        tqsys_facscadecespt_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_FACSCADECESPT_M_APM,
                                                        (UInt16)tqsys_nogeardece_par,
                                                        tqsys_nengdeceini_par);

        TqSys_facScaAcceSpt = (SInt16)DDS_M_LIMIT(temp_s32, PFILFAST_FAC_MIN, PFILFAST_FAC_MAX);
        TqSys_facScaDeceSpt = (SInt16)DDS_M_LIMIT(tqsys_facscadecespt_m, PFILFAST_FAC_MIN, PFILFAST_FAC_MAX);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Acc_Thres_Wght_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Acc_Thres_Wght_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3It_swc_out /* BIN4 */)
{
	UInt32 i;
    /* Init output*/
    *TqSys_tqThdPha3It_swc_out = (0 * BIN4);

    /* Init RUN_OUT */
    TqSys_tqThdPha4 = (0 * BIN4);
    TqSys_facSacDeceCf1 = (0 * BIN7);
    TqSys_facScaAcceCf1 = (0 * BIN7);
    TqSys_facScaAcceCf2 = (0 * BIN7);
    TqSys_facScaAcceSpt = (0 * BIN7);
    TqSys_facScaDeceSpt = (0 * BIN7);
    TqSys_tqOfsPha3Thd = (0 * BIN4);
    TqSys_tqThdOfsPha8Cf1 = (0 * BIN4);
    TqSys_tqThdPha2 = (0 * BIN4);
    TqSys_tqThdPha4Cf2 = (0 * BIN4);
    TqSys_tqThdPha4Cf1 = (0 * BIN4);
    TqSys_rAccPEngFrz = (0 * BIN7);
    TqSys_tqThdPha3Phy = (0 * BIN4);

    tqsys_stdrivfilphait_prev = (UInt8)PFILFAST_DRIVFIL_OFF;

    /* Init prev */
    tqsys_raccpengfrz_prev = (0 * BIN7);

    for (i=0;i<TQSYS_VECT_SIZE;i++)
  {
		TqSys_tqThdPha3Cf2[i] = (0 * BIN4);
		TqSys_tqThdPha3Cf1[i] = (0 * BIN4);
  }

}

#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 14:37:07
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
TqDem_bModSpt ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Mode sport coordonné ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_idxTqAccu ; ;TQS ;N/A ;1 ;10 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Indice de précision de couple ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_idxTqAccuY_A ;1{t_pfilfast_idxtqaccuy_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Indice de précision ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nDif_nEngNTrb ; ;TQS ;rpm ;-8000 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Difference entre le régime moteur filtré et le régime de l'arbre primaire de la boite de vitesse ;["YES"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng1_A ;1{t_pfilfast_neng1_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de régime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng3_A ;1{t_pfilfast_neng3_a}PFILFAST_12_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de régime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEngDeceIni ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime moteur filtré à l'activation de la décélération ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng_A ;1{t_pfilfast_neng_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de regime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nTrb ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Regime de l arbre primaire de la boite de vitesse utilise dans la strategie ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil ; ;TQSYS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilise dans la strategie ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearDece ; ;TQS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilisé pendant la décélération ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGear_A ;1{t_pfilfast_nogear_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de rapport de boite ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccP_A ;1{t_pfilfast_raccp_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de position pedale ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_stDrivFilCfPha ;["CONF_0"*0*|"CONF_1"*1*|"CONF_2"*2*|"CONF_3"*3*|"CONF_4"*4*] ;TQS ;N/A ;0 ;4 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat de configuration du filtrage utilisé dans les calculs des coefficients ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivNotFil ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple non filtré après limitation pour motorisation essence ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TreatTenms_nCkGrdFil ; ;TREATTENMS ;rpm/s ;-8000 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Dérivée filtrée du régime moteur au pmh envoyé à 10ms ;["YES"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
tqsys_stdrivfilphait_prev ;["DRIVFIL_OFF"*0*|"DRIVFIL_DISABLING"*1*|"ACCE_GAP_START_FILT"*2*|"ACCE_1ST_ORDER_FILT"*3*|"ACCE_SET_PASS_SLOPE"*4*|"ACCE_PARABOL"*5*|"ACCE_SLOPE_AFTER_PARABOL"*6*|"ACCE_SLOPE_ABOVE_SET"*7*|"DECE_D0_GAP"*8*|"DECE_1ST_SLOPE"*9*|"DECE_2ND_SLOPE"*10*|"DECE_3RD_SLOPE"*11*|"RESERVED_12"*12*|"RESERVED_13"*13*|"RESERVED_14"*14*|"RESERVED_15"*15*] ;TQS ;N/A ;0 ;15 ;1 ;["NULL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;enum output prev ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
TqSys_facSacDeceCf1 ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de ponderation en configuration 1 et 3 pondere en deceleration ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceCf1 ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de pondération en configuration 1 et 4 pondéré en accélération ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceCf2 ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de pondération en configuration 2 et 4 pondéré en accélération ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceSpt ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de pondération en mode sport pondéré en accélération ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaDeceSpt ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficients de ponderation en mode sport pondere en deceleration ;["YES"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsPha3Thd ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Offset de couple pour la convergence de la phase 0 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdOfsPha8Cf1 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Offset ajouté au seuil en décélération en configurations 1 et 3 pondéré ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 00 a phase 0 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Phy ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple physique pour l'entrée dans la zone des jeux ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 01 a phase 1 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3It ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple d'entree de la zone des jeux ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
PFILFAST_10_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ;10 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_11_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;11 ;11 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_12_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;12 ;12 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_7_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;7 ;7 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_8_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;8 ;8 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TQSYS_VECT_SIZE ; ;TQSYS ;N/A ;2 ;2 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;2 ;taille vect ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvFrzAccP_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Permet d'activer le figeage de la position pédale pendant la traversée des jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3ThdCf2_rAccPSpt_T ; ;TQSYS ;N/A ;-1 ;2 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0] ;Facteur d echelle pour le coefficient de la phase 3 en acceleration en configuration 2 en fonction de la position pedale en mode sport ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3ThdCf2_rAccP_T ; ;TQSYS ;N/A ;-1 ;2 ;0.01 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0] ;Facteur d echelle pour le coefficient de la phase 3 en acceleration en configuration 2 en fonction de la position pedale ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3_TqThdCf1Spt_M ; ;TQSYS ;N/A ;-1 ;2 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_rAccPEngFrz ;TqSys_noGearCordDrivFil ;N/A ;[0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] ;Correction du seuil de couple de la phase 3 en configuration 1 en fonction de la position pédale en mode sport ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha3_TqThdCf1_M ; ;TQSYS ;N/A ;-1 ;2 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_rAccPEngFrz ;TqSys_noGearCordDrivFil ;N/A ;[0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] ;Correction du seuil de couple de la phase 3 en configuration 1 en fonction de la position pédale ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN7 ;TqSys_rAccP_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha4_TqThdCf1Spt_T ; ;TQSYS ;N/A ;-1 ;2 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] ;Facteur d echelle pour la duree de la phase 4 en acceleration en configuration 1 en fonction d un seuil de couple en mode sport ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha4_TqThdCf1_T ; ;TQSYS ;N/A ;-1 ;2 ;0.01 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] ;Facteur d echelle pour la duree de la phase 4 en acceleration en configuration 1 en fonction d un seuil de couple ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha4_TqThdCf2Spt_T ; ;TQSYS ;N/A ;-1 ;2 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0] ;Facteur d echelle pour la duree de la phase 4 en acceleration en configuration 2 en fonction d un seuil de couple en mode sport ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPha4_TqThdCf2_T ; ;TQSYS ;N/A ;-1 ;2 ;0.01 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0] ;Facteur d echelle pour la duree de la phase 4 en acceleration en configuration 2 en fonction d un seuil de couple ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facSca1AcceCf1_M ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Ponderation 1 en configurations 1 et 3 en acceleration fonction du regime moteur et du rapport de boite ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN7 ;TqSys_nEng_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facSca2AcceCf1_A ;1{t_pfilfast_facsca2accecf1_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[-3000 -2000 -1000 -500 -100 100 500 1000 2000 3000] ;Difference entre le regime moteur filtre et le regime de l arbre primaire de la boite de vitesse ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facSca2AcceCf1_M ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_nDif_nEngNTrb ;TqSys_noGearCordDrivFil ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Ponderation 2 en configurations 1 et 3 en acceleration fonction du regime moteur et du rapport de boite ;["YES"] ;DDS_M_MAP3D_SUS16 ;BIN7 ;TqSys_facSca2AcceCf1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceSptTyp_T ; ;TQSYS ;N/A ;-0.99 ;2 ;1/128 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[1 1 1 1 1 1 1 1 1 1] ;Ponderation de l acceleration en fonction du type de mode sport ;["YES"] ;DDS_M_MAP2D_US16 ;BIN7 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaAcceSpt_M ; ;TQSYS ;N/A ;-0.99 ;2 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_noGearCordDrivFil ;Eng_nCkFil ;N/A ;[1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] ;Ponderation de l acceleration en mode sport ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN7 ;TqSys_noGear_A ;TqSys_nEng1_A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaCf2_Tq_M ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["MAP"] ;["N/A"] ;N/A ;Eng_nCkFil ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Ponderation en configurations 2 et 4 fonction du couple et du regime ;["YES"] ;DDS_M_MAP3D_SUS16 ;BIN7 ;TqSys_tq_facScaCf2_A ;TqSys_nEng_A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaCf2_aEng_A ;1{t_pfilfast_scacf2_aeng_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[-3000 -2000 -1000 -500 -100 100 500 1000 2000 3000] ;Difference entre le regime moteur filtre et le regime de l arbre primaire de la boite de vitesse ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaCf2_aEng_M ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["MAP"] ;["N/A"] ;TreatTenms_nCkGrdFil ;TqSys_nDif_nEngNTrb ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Ponderation en configurations 2 et 4 fonction de l acceleration et du delta entre le regime arbra primaire et le regime moteur ;["YES"] ;DDS_M_MAP3D_S16 ;BIN7 ;TqSys_facScaCf2_aTrb_A ;TqSys_facScaCf2_aEng_A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaCf2_aTrb_A ;1{t_pfilfast_scacf2_atrb_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[-3000 -2000 -1000 -500 -100 100 500 1000 2000 3000] ;Acceleration filtree du moteur / filtered engine acceleration ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaDeceCf1_M ; ;TQSYS ;N/A ;-0.99 ;3 ;1/128 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] ;Ponderation en configurations 1 et 3 en deceleration fonction du regime moteur et du rapport de boite ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN7 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaDeceSpt_M ; ;TQSYS ;N/A ;-0.99 ;2 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_noGearDece ;TqSys_nEngDeceIni ;N/A ;[1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] [1 1 1 1 1 1 1] ;Ponderation de la deceleration en mode sport ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN7 ;TqSys_noGear_A ;TqSys_nEng1_A ;N/A ;N/A ;N/A ;N/A
TqSys_nTrbHys_C ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Difference minimum pour activer la ponderation en configurations 2 et 4 ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccPEngFrz ; ;TQSYS ;% ;0 ;100 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Position pédale figée pendant la traversée des jeux ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsPha3_T ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;CoVSCtl_rAccPEng ;N/A ;N/A ;[5 5 5 5 5 5 5 5 5 5] ;Offset de couple sur la phase 3 ;["YES"] ;DDS_M_MAP2D_US16 ;BIN4 ;TqSys_rAccP_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdOfsPha8Cf1_A ;1{t_pfilfast_tqthdofspha8cf1_a}PFILFAST_11_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1] ;Coefficients de ponderation en configuration 1 et 3 pondere en deceleration ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdOfsPha8Cf1_T ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 0 0 0 0 0 0 0 0 0 0] ;Offset en configurations 1 et 3 en deceleration fonction du regime moteur et du rapport de boite ;["YES"] ;DDS_M_MAP2D_S16 ;BIN4 ;TqSys_tqThdOfsPha8Cf1_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha2_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_idxTqAccu ;N/A ;[-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] [-30 -30 -30 -30 -30 -30 -30 -30 -30 -30] ;Calibration nominale du seuil de couple de la phase 2 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng_A ;TqSys_idxTqAccuY_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf1 ;1{tqsys_tqrhdpha3cf1_vect_type}TQSYS_VECT_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la phase 0 en acceleration en configuration 1 ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf1_Accu_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;TqSys_idxTqAccu ;Eng_nCkFil ;N/A ;[0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] ;Correction du seuil de couple de la phase 3 en configuration 1 en fonction de l indice de precision ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_idxTqAccuY_A ;TqSys_nEng3_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf1_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] ;Calibration nominale du seuil de couple de la phase 3 en configuration 1 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf1_Driv_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] ;Correction du seuil de couple de la phase 3 en configuration 1 en fonction de la manoeuvrabilite ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf2 ;1{tqsys_tqrhdpha3cf2_vect_type}TQSYS_VECT_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la phase 0 en acceleration en configuration 2 ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf2_Accu_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;TqSys_idxTqAccu ;Eng_nCkFil ;N/A ;[0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0] ;Correction du seuil de couple de la phase 3 en configuration 2 en fonction de l indice de precision ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_idxTqAccuY_A ;TqSys_nEng3_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf2_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] ;Calibration nominale du seuil de couple de la phase 3 en configuration 2 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Cf2_Driv_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] ;Correction du seuil de couple de la phase 3 en configuration 2 en fonction de la manoeuvrabilite ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4Cf1 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 01 a phase 1 en acceleration en configuration 1 ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4Cf1_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] [7 7 7 7 7 7 7 7 7 7 7 7] ;Calibration nominale du seuil de couple de la phase 4 en configuration 1 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4Cf2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 01 a phase 1 en acceleration en configuration 2 ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4Cf2_Bas_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0 0 0 0 0] ;Calibration nominale du seuil de couple de la phase 4 en configuration 2 ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng3_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tq_facScaCf2_A ;1{t_pfilfast_facscacf2_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[-100 0 10 50 100 150 200 250 300 350] ;Couple non filtre ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
pfilfast_acc_thres_wght_store ;PFILFAST_11_SIZE+PFILFAST_12_SIZE+PFILFAST_8_SIZE+PFILFAST_7_SIZE+PFILFAST_10_SIZE+TqSys_facPha3ThdCf2_rAccPSpt_T+TqSys_facPha3ThdCf2_rAccP_T+TqSys_facPha4_TqThdCf1Spt_T+TqSys_facPha4_TqThdCf1_T+TqSys_facPha4_TqThdCf2Spt_T+TqSys_facPha4_TqThdCf2_T+TqSys_facSca1AcceCf1_M+TqSys_facSca2AcceCf1_A+TqSys_facSca2AcceCf1_M+TqSys_facScaAcceSptTyp_T+TqSys_facScaAcceSpt_M+TqSys_facScaCf2_Tq_M+TqSys_facScaCf2_aEng_A+TqSys_facScaCf2_aEng_M+TqSys_facScaCf2_aTrb_A+TqSys_facScaDeceCf1_M+TqSys_facScaDeceSpt_M+TqSys_nTrbHys_C+TqSys_bAcvFrzAccP_C+TqSys_tqOfsPha3_T+TqSys_tqThdOfsPha8Cf1_A+TqSys_tqThdOfsPha8Cf1_T+TqSys_tqThdPha2_M+TqSys_tqThdPha3Cf1+TqSys_tqThdPha3Cf1_Accu_M+TqSys_tqThdPha3Cf1_Bas_M+TqSys_tqThdPha3Cf1_Driv_M+TqSys_tqThdPha3Cf2+TqSys_tqThdPha3Cf2_Accu_M+TqSys_tqThdPha3Cf2_Bas_M+TqSys_tqThdPha3Cf2_Driv_M+TqSys_tqThdPha4Cf1+TqSys_tqThdPha4Cf1_Bas_M+TqSys_tqThdPha4Cf2+TqSys_tqThdPha4Cf2_Bas_M+TqSys_tq_facScaCf2_A+TqSys_rAccPEngFrz+TqSys_facPha3_TqThdCf1Spt_M+TqSys_facPha3_TqThdCf1_M ;PFILFAST ;N/A ;N/A ;N/A ;N/A ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;local variables ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_facsca2accecf1_a ; ;TQSYS ;RPM ;-8000 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_facSca2AcceCf1_A ;["NO"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_facscacf2_a ; ;PFILFAST ;N.m ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tq_facScaCf2_A ;["NO"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_idxtqaccuy_a ; ;PFILFAST ;N/A ;1 ;10 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_idxTqAccuY_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng1_a ; ;PFILFAST ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng1_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng3_a ; ;PFILFAST ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng3_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng_a ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_nogear_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_noGear_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_raccp_a ; ;PFILFAST ;% ;0 ;100 ;1/128 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_rAccP_A ;["NO"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_scacf2_aeng_a ; ;PFILFAST ;N/A ;-8000 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_facScaCf2_aEng_A ;["NO"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_scacf2_atrb_a ; ;PFILFAST ;rpm/s ;-8000 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_facScaCf2_aTrb_A ;["NO"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqthdofspha8cf1_a ; ;PFILFAST ;N/A ;-0.99 ;3 ;1/128 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tqThdOfsPha8Cf1_A ;["NO"] ;SInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
tqsys_tqrhdpha3cf1_vect_type ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;type vect ;["NO"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
tqsys_tqrhdpha3cf2_vect_type ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;type vect ;["NO"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

