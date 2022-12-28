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
* Ref X:\integration_view_00PSASWC_E611D01\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Decel_Thres_Slew.c
* Version int :/main/L01_02/2 Date: 16/5/2011 15 h 7 m User:esnault 
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL3_D
*    comments :update remark tracking sheet for TU
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 13/5/2011 10 h 43 m User:demezil 
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL3_D
*    comments :update remark tracking sheet for TU
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 9/5/2011 16 h 39 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL3_D
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 29/4/2011 10 h 56 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/4/2011 14 h 41 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :for CPU optimization
* Version int :/main/L01_02/1 Date: 17/2/2011 15 h 36 m User:meme
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\6 Date: 31/1/2011 16 h 50 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\5 Date: 31/1/2011 14 h 56 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :Update for 11.0
* Version dev :\main\branch_halouane\4 Date: 28/1/2011 10 h 51 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\3 Date: 27/1/2011 16 h 11 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :Update for 11.0
* Version dev :\main\branch_halouane\2 Date: 27/1/2011 12 h 49 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane\1 Date: 14/1/2011 16 h 3 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL1
*    comments :update for PFilFasr11_0
* Version int :/main/L01_01/2 Date: 20/9/2010 15 h 10 m User:meme
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL2
*    comments :FDS 32164 / PFilFast 10.0 /
* Version dev :\main\branch_demezil_pfilfast_dev\6 Date: 14/9/2010 16 h 58 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL2
*    comments :FDS 32164 / PFilFast 10.0 /
* Ref X:\integration_view_00PSASWC_E611D01\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Decel_Thres_Slew.c
* Version int :/main/L01_02/2 Date: 16/5/2011 15 h 7 m User:esnault 
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL3_D
*    comments :update remark tracking sheet for TU
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 13/5/2011 10 h 43 m User:demezil 
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL3_D
*    comments :update remark tracking sheet for TU
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 9/5/2011 16 h 39 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL3_D
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 29/4/2011 10 h 56 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/4/2011 14 h 41 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :for CPU optimization
* Version int :/main/L01_02/1 Date: 17/2/2011 15 h 36 m User:meme
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\6 Date: 31/1/2011 16 h 50 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\5 Date: 31/1/2011 14 h 56 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :Update for 11.0
* Version dev :\main\branch_halouane\4 Date: 28/1/2011 10 h 51 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\3 Date: 27/1/2011 16 h 11 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :Update for 11.0
* Version dev :\main\branch_halouane\2 Date: 27/1/2011 12 h 49 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane\1 Date: 14/1/2011 16 h 3 m User:halouane
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_020_IMPL1
*    comments :update for PFilFasr11_0
* Version int :/main/L01_01/2 Date: 20/9/2010 15 h 10 m User:meme
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL2
*    comments :FDS 32164 / PFilFast 10.0 /
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 39 m User:esnault
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL2
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 12/8/2010 9 h 26 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL2
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 9/8/2010 9 h 29 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL2
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 6/7/2010 10 h 11 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 1/7/2010 17 h 5 m User:demezil
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_lemort_pfilfast_dev\2 Date: 30/6/2010 15 h 4 m User:lemort
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_pfilfast_dev\1 Date: 30/6/2010 11 h 19 m User:lemort
*    TWK_model:PFILFAST_Decel_Thres_Slew_L01_010_IMPL1
*    comments :dev pfilfast e6
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

#include "PFilFast.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define PFILFAST_10_SIZE                      10
#define PFILFAST_12_SIZE                      12
#define PFILFAST_5_SIZE                       5
#define PFILFAST_7_SIZE                       7
#define PFILFAST_8_SIZE                       8

#define PFILFAST_P2000_BIN4 ((SInt32)2000 * BIN4)
#define PFILFAST_N2000_BIN4 ((SInt32)-2000 * BIN4)

#define PFILFAST_P2000_BIN11    ((SInt32)2000 * BIN11)
#define PFILFAST_N2000_BIN11    ((SInt32)-2000 * BIN11)

#define PFILFAST_CONF_0 (UInt32)0
#define PFILFAST_CONF_1 (UInt32)1
#define PFILFAST_CONF_2 (UInt32)2
#define PFILFAST_CONF_3 (UInt32)3
#define PFILFAST_CONF_4 (UInt32)4

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
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdOfsPha8Cf1; /* BIN4 */
extern VAR(UInt16, AUTOMATIC) TqSys_tqACLossFil; /* BIN4 */
extern VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha9; /* DEC1 */
extern VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha10; /* DEC1 */
extern VAR(UInt16, AUTOMATIC) TqSys_tiDlyPha11; /* DEC1 */
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
extern volatile CONST(UInt16, AUTOMATIC) TqSys_idxTqAccuY_A[PFILFAST_10_SIZE]; /* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng1_A[PFILFAST_8_SIZE]; /* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng3_A[PFILFAST_12_SIZE]; /* BIN2 */
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

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
VAR(SInt32, AUTOMATIC) TqSys_tqFilDifMin; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha10; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha11; /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha9; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
VAR(SInt16, AUTOMATIC) TqSys_tqThdPha8; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqSys_tqThdPha9; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqSys_tqThdPha10; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 32-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_32BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(SInt32, AUTOMATIC) TqSys_tqFilDifMin_C = (CONST(SInt32, AUTOMATIC))(0 * BIN11);
#define PFILFAST_STOP_SEC_CALIB_32BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_Ext_tAir_ACLoss_A[PFILFAST_5_SIZE] = {
(SInt16)(-30 * BIN0), (SInt16)(-10 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(20 * BIN0), (SInt16)(40 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha10Cf1_Typ_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha10Cf1_TypSpt_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha10Cf2_Typ_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha10Cf2_TypSpt_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha8_TqThdCf1Typ_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha8_TqThdCf1TypSpt_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha8_TqThdCf2Typ_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha8_TqThdCf2TypSpt_T
[PFILFAST_12_SIZE] = {
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7),
(SInt16)(1 * BIN7), (SInt16)(1 * BIN7), (SInt16)(1 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha9Cf1_ACLoss_T
[PFILFAST_5_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha9Cf1_Typ_T
[PFILFAST_12_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha9Cf1_TypSpt_T
[PFILFAST_12_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha9Cf2_Ext_tAir_T
[PFILFAST_5_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha9Cf2_Typ_T
[PFILFAST_12_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facPha9Cf2_TypSpt_T
[PFILFAST_12_SIZE] = {
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7),
(SInt16)(0 * BIN7), (SInt16)(0 * BIN7), (SInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqACLossFil_A[PFILFAST_8_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(5 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(20 * BIN4), (UInt16)(30 * BIN4), (UInt16)(40 * BIN4),
(UInt16)(50 * BIN4), (UInt16)(60 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha10Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha10Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf1_Accu_M
[PFILFAST_8_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf1_Typ_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf2_Accu_M
[PFILFAST_8_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf2_Typ_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf1_Accu_M
[PFILFAST_8_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf1_ACLoss_M
[PFILFAST_8_SIZE][PFILFAST_8_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf1_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf1_Typ_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf2_Accu_M
[PFILFAST_8_SIZE][PFILFAST_10_SIZE] = {
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf2_ACLoss_M
[PFILFAST_8_SIZE][PFILFAST_8_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf2_Bas_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf2_Typ_M
[PFILFAST_7_SIZE][PFILFAST_12_SIZE] = {
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) },
{
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(10 * BIN4), (SInt16)(10 * BIN4) }
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha10cf1_typ_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha10cf1_typspt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha10cf2_typ_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha10cf2_typspt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha8_tqthdcf1typ_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha8_tqthdcf1typspt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha8_tqthdcf2typ_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha8_tqthdcf2typspt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha9cf1_acloss_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha9cf1_typ_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha9cf1_typspt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha9cf2_ext_tair_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha9cf2_typ_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpha9cf2_typspt_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha10cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha10cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha8cf1_accu_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha8cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha8cf1_typ_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha8cf2_accu_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha8cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha8cf2_typ_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf1_accu_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf1_acloss_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf1_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf1_typ_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf2_accu_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf2_acloss_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf2_bas_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdpha9cf2_typ_m_sav;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"

/* 16-bits variable definition */
#define PFILFAST_START_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqsys_tqaclossfil_cpy;
#define PFILFAST_STOP_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha10Cf1; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha10Cf2; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf1; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha8Cf2; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf1; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdPha9Cf2; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA10CF1_TYP_T_APM = {
&tqsys_facpha10cf1_typ_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha10Cf1_Typ_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA10CF1_TYPSPT_T_APM = {
&tqsys_facpha10cf1_typspt_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha10Cf1_TypSpt_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA10CF2_TYP_T_APM = {
&tqsys_facpha10cf2_typ_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha10Cf2_Typ_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA10CF2_TYPSPT_T_APM = {
&tqsys_facpha10cf2_typspt_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha10Cf2_TypSpt_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA8_TQTHDCF1TYP_T_APM = {
&tqsys_facpha8_tqthdcf1typ_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha8_TqThdCf1Typ_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA8_TQTHDCF1TYPSPT_T_APM = {
&tqsys_facpha8_tqthdcf1typspt_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha8_TqThdCf1TypSpt_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA8_TQTHDCF2TYP_T_APM = {
&tqsys_facpha8_tqthdcf2typ_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha8_TqThdCf2Typ_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA8_TQTHDCF2TYPSPT_T_APM = {
&tqsys_facpha8_tqthdcf2typspt_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha8_TqThdCf2TypSpt_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA9CF1_ACLOSS_T_APM = {
&tqsys_facpha9cf1_acloss_t_sav,
PFILFAST_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_Ext_tAir_ACLoss_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha9Cf1_ACLoss_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA9CF1_TYP_T_APM = {
&tqsys_facpha9cf1_typ_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha9Cf1_Typ_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA9CF1_TYPSPT_T_APM = {
&tqsys_facpha9cf1_typspt_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha9Cf1_TypSpt_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA9CF2_EXT_TAIR_T_APM = {
&tqsys_facpha9cf2_ext_tair_t_sav,
PFILFAST_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_Ext_tAir_ACLoss_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha9Cf2_Ext_tAir_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA9CF2_TYP_T_APM = {
&tqsys_facpha9cf2_typ_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha9Cf2_Typ_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_FACPHA9CF2_TYPSPT_T_APM = {
&tqsys_facpha9cf2_typspt_t_sav,
PFILFAST_12_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqFil_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPha9Cf2_TypSpt_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA10CF1_BAS_M_APM = {
&tqsys_tqthdpha10cf1_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha10Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA10CF2_BAS_M_APM = {
&tqsys_tqthdpha10cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha10Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA8CF1_ACCU_M_APM = {
&tqsys_tqthdpha8cf1_accu_m_sav,
PFILFAST_10_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxTqAccuY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha8Cf1_Accu_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA8CF1_BAS_M_APM = {
&tqsys_tqthdpha8cf1_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha8Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA8CF1_TYP_M_APM = {
&tqsys_tqthdpha8cf1_typ_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha8Cf1_Typ_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA8CF2_ACCU_M_APM = {
&tqsys_tqthdpha8cf2_accu_m_sav,
PFILFAST_10_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxTqAccuY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha8Cf2_Accu_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA8CF2_BAS_M_APM = {
&tqsys_tqthdpha8cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha8Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA8CF2_TYP_M_APM = {
&tqsys_tqthdpha8cf2_typ_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha8Cf2_Typ_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF1_ACCU_M_APM = {
&tqsys_tqthdpha9cf1_accu_m_sav,
PFILFAST_10_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxTqAccuY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf1_Accu_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF1_ACLOSS_M_APM = {
&tqsys_tqthdpha9cf1_acloss_m_sav,
PFILFAST_8_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqACLossFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf1_ACLoss_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF1_BAS_M_APM = {
&tqsys_tqthdpha9cf1_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf1_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF1_TYP_M_APM = {
&tqsys_tqthdpha9cf1_typ_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf1_Typ_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF2_ACCU_M_APM = {
&tqsys_tqthdpha9cf2_accu_m_sav,
PFILFAST_10_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxTqAccuY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf2_Accu_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF2_ACLOSS_M_APM = {
&tqsys_tqthdpha9cf2_acloss_m_sav,
PFILFAST_8_SIZE,
PFILFAST_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqACLossFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf2_ACLoss_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF2_BAS_M_APM = {
&tqsys_tqthdpha9cf2_bas_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf2_Bas_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQTHDPHA9CF2_TYP_M_APM = {
&tqsys_tqthdpha9cf2_typ_m_sav,
PFILFAST_12_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng3_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdPha9Cf2_Typ_M[0][0]
};


#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

/* STATIC FUNC(void, AUTOMATIC) Local_Function (t_paramtype parameter); */

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_Deceleration_Thresholds_Coefficients(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                        SInt16 tqsys_tqckdeceiniit_par,
                                                                                        UInt16 tqsys_nengdeceini_par,
                                                                                        UInt8 tqdem_bmodspt_par,
                                                                                        UInt8 tqsys_nogeardece_par,
                                                                                        UInt8 tqsys_idxtqaccu_par,
                                                                                        SInt8 ext_tair_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_01_Deceleration_Thresholds_Phase8(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                    SInt16 tqsys_tqckdeceiniit_par,
                                                                                    UInt16 tqsys_nengdeceini_par,
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    UInt8 tqsys_nogeardece_par,
                                                                                    UInt8 tqsys_idxtqaccu_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_01_01_Deceleration_Thresholds_Phase8_Config1(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_01_02_Deceleration_Thresholds_Phase8_Config2(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_02_Deceleration_Thresholds_Phase9(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                    SInt16 tqsys_tqckdeceiniit_par,
                                                                                    UInt16 tqsys_nengdeceini_par,
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    UInt8 tqsys_nogeardece_par,
                                                                                    UInt8 tqsys_idxtqaccu_par,
                                                                                    SInt8 ext_tair_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_02_01_Deceleration_Thresholds_Phase9_Config1(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par,
                                                                                                SInt8 ext_tair_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_02_02_Deceleration_Thresholds_Phase9_Config2(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par,
                                                                                                SInt8 ext_tair_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_03_Deceleration_Thresholds_Phase10(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                    SInt16 tqsys_tqckdeceiniit_par,
                                                                                    UInt16 tqsys_nengdeceini_par,
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    UInt8 tqsys_nogeardece_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_03_01_Deceleration_Thresholds_Phase10_Config1(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_03_02_Deceleration_Thresholds_Phase10_Config2(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_03_Decelerations_Slews(void);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Decel_Thres_Slew_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Decel_Thres_Slew(SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           UInt8 TqDem_bModSpt_swc_in,
                                           UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                           UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
                                           UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
                                           UInt8 TqSys_stDrivFilCfPha_swc_in,
                                           SInt16 TqSys_tqCkDeceIniIt_swc_in /* BIN4 */)
{

    PFILFAST_F03_02_05_02_Deceleration_Thresholds_Coefficients(TqSys_stDrivFilCfPha_swc_in,
                                                                TqSys_tqCkDeceIniIt_swc_in,
                                                                TqSys_nEngDeceIni_swc_in,
                                                                TqDem_bModSpt_swc_in,
                                                                TqSys_noGearDece_swc_in, /* BIN0 */
                                                                TqSys_idxTqAccu_swc_in,
                                                                Ext_tAir_swc_in);

    PFILFAST_F03_02_05_03_Decelerations_Slews();


}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_Deceleration_Thresholds_Coefficients
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_Deceleration_Thresholds_Coefficients(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                        SInt16 tqsys_tqckdeceiniit_par,
                                                                                        UInt16 tqsys_nengdeceini_par,
                                                                                        UInt8 tqdem_bmodspt_par,
                                                                                        UInt8 tqsys_nogeardece_par,
                                                                                        UInt8 tqsys_idxtqaccu_par,
                                                                                        SInt8 ext_tair_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.61.0  */

    PFILFAST_F03_02_05_02_01_Deceleration_Thresholds_Phase8(tqsys_stdrivfilcfpha_par,
                                                            tqsys_tqckdeceiniit_par,
                                                            tqsys_nengdeceini_par,
                                                            tqdem_bmodspt_par,
                                                            tqsys_nogeardece_par,
                                                            tqsys_idxtqaccu_par);

    PFILFAST_F03_02_05_02_02_Deceleration_Thresholds_Phase9(tqsys_stdrivfilcfpha_par,
                                                            tqsys_tqckdeceiniit_par,
                                                            tqsys_nengdeceini_par,
                                                            tqdem_bmodspt_par,
                                                            tqsys_nogeardece_par,
                                                            tqsys_idxtqaccu_par,
                                                            ext_tair_par);

    PFILFAST_F03_02_05_02_03_Deceleration_Thresholds_Phase10(tqsys_stdrivfilcfpha_par,
                                                            tqsys_tqckdeceiniit_par,
                                                            tqsys_nengdeceini_par,
                                                            tqdem_bmodspt_par,
                                                            tqsys_nogeardece_par);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_01_Deceleration_Thresholds_Phase8
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_01_Deceleration_Thresholds_Phase8(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                    SInt16 tqsys_tqckdeceiniit_par,
                                                                                    UInt16 tqsys_nengdeceini_par,
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    UInt8 tqsys_nogeardece_par,
                                                                                    UInt8 tqsys_idxtqaccu_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.62.0  */
    switch((UInt32)tqsys_stdrivfilcfpha_par)
    {
        case( PFILFAST_CONF_1):
            PFILFAST_F03_02_05_02_01_01_Deceleration_Thresholds_Phase8_Config1(tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par,
                                                                                tqsys_idxtqaccu_par);

            TqSys_tqThdPha8 = TqSys_tqThdPha8Cf1;
            break;

        case(PFILFAST_CONF_2):
            PFILFAST_F03_02_05_02_01_01_Deceleration_Thresholds_Phase8_Config1(tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par,
                                                                                tqsys_idxtqaccu_par);

            TqSys_tqThdPha8 = (SInt16)DDS_M_LIMIT(((SInt32)TqSys_tqThdPha8Cf1 + (SInt32)TqSys_tqThdOfsPha8Cf1),
                                                    PFILFAST_N2000_BIN4,
                                                    PFILFAST_P2000_BIN4);
            break;

        case(PFILFAST_CONF_3):
        case(PFILFAST_CONF_4):
            PFILFAST_F03_02_05_02_01_02_Deceleration_Thresholds_Phase8_Config2( tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par,
                                                                                tqsys_idxtqaccu_par);

            TqSys_tqThdPha8 = TqSys_tqThdPha8Cf2;
            break;

        case(PFILFAST_CONF_0):
        default:
            TqSys_tqThdPha8 = 0;
            break;
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_01_01_Deceleration_Thresholds_Phase8_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_01_01_Deceleration_Thresholds_Phase8_Config1(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.63.0 */

    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA8_TQTHDCF1TYP_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }
    else
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA8_TQTHDCF1TYPSPT_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA8CF1_TYP_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 = BIN7 * BIN4 / BIN7 */
    pfilfast_s32_temp2 = (pfilfast_s32_temp3 * pfilfast_s32_temp1) / BIN7;

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA8CF1_BAS_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 */
    pfilfast_s32_temp3 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA8CF1_ACCU_M_APM,
                                                                    (UInt16)tqsys_idxtqaccu_par,
                                                                    tqsys_nengdeceini_par);

    /* BIN4 */
    TqSys_tqThdPha8Cf1 = (SInt16)DDS_M_LIMIT( ((pfilfast_s32_temp2
                                                + pfilfast_s32_temp1)
                                                + pfilfast_s32_temp3),
                                            PFILFAST_N2000_BIN4,
                                            PFILFAST_P2000_BIN4);

}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_01_02_Deceleration_Thresholds_Phase8_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_01_02_Deceleration_Thresholds_Phase8_Config2(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.64.0 */

    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA8_TQTHDCF2TYP_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }
    else
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA8_TQTHDCF2TYPSPT_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA8CF2_TYP_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 = BIN7 * BIN4 / BIN7 */
    pfilfast_s32_temp2 = (pfilfast_s32_temp3 * pfilfast_s32_temp1) / BIN7;

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA8CF2_BAS_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 */
    pfilfast_s32_temp3 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA8CF2_ACCU_M_APM,
                                                                    (UInt16)tqsys_idxtqaccu_par,
                                                                    tqsys_nengdeceini_par);

    /* BIN4 */
    TqSys_tqThdPha8Cf2 = (SInt16)DDS_M_LIMIT( ((pfilfast_s32_temp2
                                                + pfilfast_s32_temp1)
                                                + pfilfast_s32_temp3),
                                            PFILFAST_N2000_BIN4,
                                            PFILFAST_P2000_BIN4);

}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_02_Deceleration_Thresholds_Phase9
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_02_Deceleration_Thresholds_Phase9(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                    SInt16 tqsys_tqckdeceiniit_par,
                                                                                    UInt16 tqsys_nengdeceini_par,
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    UInt8 tqsys_nogeardece_par,
                                                                                    UInt8 tqsys_idxtqaccu_par,
                                                                                    SInt8 ext_tair_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.65.0 */

    tqsys_tqaclossfil_cpy = TqSys_tqACLossFil;

    switch((UInt32)tqsys_stdrivfilcfpha_par)
    {
        case(PFILFAST_CONF_1):
        case(PFILFAST_CONF_2):
            PFILFAST_F03_02_05_02_02_01_Deceleration_Thresholds_Phase9_Config1(tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par,
                                                                                tqsys_idxtqaccu_par,
                                                                                ext_tair_par);

            TqSys_tqThdPha9 = TqSys_tqThdPha9Cf1;
            break;

        case(PFILFAST_CONF_3):
        case(PFILFAST_CONF_4):
            PFILFAST_F03_02_05_02_02_02_Deceleration_Thresholds_Phase9_Config2(tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par,
                                                                                tqsys_idxtqaccu_par,
                                                                                ext_tair_par);

            TqSys_tqThdPha9 = TqSys_tqThdPha9Cf2;
            break;

        case(PFILFAST_CONF_0):
        default:
            TqSys_tqThdPha9 = 0;
            break;
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_02_01_Deceleration_Thresholds_Phase9_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_02_01_Deceleration_Thresholds_Phase9_Config1(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par,
                                                                                                SInt8 ext_tair_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.66.0 */

    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;
    SInt32 pfilfast_s32_temp4;
    SInt32 pfilfast_s32_temp5;

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA9CF1_TYP_T_APM,
                                                        tqsys_tqckdeceiniit_par);
    }
    else
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA9CF1_TYPSPT_T_APM,
                                                        tqsys_tqckdeceiniit_par);
    }

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF1_TYP_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 = BIN7 * BIN4 / BIN7 */
    pfilfast_s32_temp2 = ((pfilfast_s32_temp3 * pfilfast_s32_temp1) / BIN7);

    /* BIN7 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA9CF1_ACLOSS_T_APM,
                                                                    (SInt16)ext_tair_par);

    /* BIN4 */
    pfilfast_s32_temp3 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF1_ACLOSS_M_APM,
                                                                    tqsys_tqaclossfil_cpy,
                                                                    tqsys_nengdeceini_par);


    /* BIN4 = BIN7 * BIN4 / BIN7 */
    pfilfast_s32_temp4 = ((pfilfast_s32_temp1 * pfilfast_s32_temp3) / BIN7);

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF1_BAS_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 */
    pfilfast_s32_temp3 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF1_ACCU_M_APM,
                                                                    (UInt16)tqsys_idxtqaccu_par,
                                                                    tqsys_nengdeceini_par );

    pfilfast_s32_temp5 = (((pfilfast_s32_temp2 + pfilfast_s32_temp4) +
                            pfilfast_s32_temp1) + pfilfast_s32_temp3);

    pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp5, (SInt32)TqSys_tqThdPha8);

    TqSys_tqThdPha9Cf1 = (SInt16)DDS_M_MAX(pfilfast_s32_temp1,
                                            PFILFAST_N2000_BIN4);
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_02_02_Deceleration_Thresholds_Phase9_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_02_02_Deceleration_Thresholds_Phase9_Config2(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par,
                                                                                                UInt8 tqsys_idxtqaccu_par,
                                                                                                SInt8 ext_tair_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.67.0 */

    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;
    SInt32 pfilfast_s32_temp4;
    SInt32 pfilfast_s32_temp5;

    if((UInt32)DDS_FALSE != (UInt32)tqdem_bmodspt_par)
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA9CF2_TYPSPT_T_APM,
                                                        tqsys_tqckdeceiniit_par);
    }
    else
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA9CF2_TYP_T_APM,
                                                        tqsys_tqckdeceiniit_par);
    }

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF2_TYP_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 = BIN7 * BIN4 / BIN7 */
    pfilfast_s32_temp2 = ((pfilfast_s32_temp3 * pfilfast_s32_temp1) / BIN7);

    /* BIN7 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA9CF2_EXT_TAIR_T_APM,
                                                                    (SInt16)ext_tair_par);

    /* BIN4 */
    pfilfast_s32_temp3 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF2_ACLOSS_M_APM,
                                                                    tqsys_tqaclossfil_cpy,
                                                                    tqsys_nengdeceini_par);


    /* BIN4 = BIN7 * BIN4 / BIN7 */
    pfilfast_s32_temp4 = ((pfilfast_s32_temp1 * pfilfast_s32_temp3) / BIN7);

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF2_BAS_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 */
    pfilfast_s32_temp3 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA9CF2_ACCU_M_APM,
                                                                    (UInt16)tqsys_idxtqaccu_par,
                                                                    tqsys_nengdeceini_par );

    pfilfast_s32_temp5 = (((pfilfast_s32_temp2 +
                                pfilfast_s32_temp4) +
                                pfilfast_s32_temp1) +
                                pfilfast_s32_temp3);

    pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp5, (SInt32)TqSys_tqThdPha8);

    TqSys_tqThdPha9Cf2 = (SInt16)DDS_M_MAX(pfilfast_s32_temp1,
                                            PFILFAST_N2000_BIN4);
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_03_Deceleration_Thresholds_Phase10
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_03_Deceleration_Thresholds_Phase10(UInt8 tqsys_stdrivfilcfpha_par,
                                                                                    SInt16 tqsys_tqckdeceiniit_par,
                                                                                    UInt16 tqsys_nengdeceini_par,
                                                                                    UInt8 tqdem_bmodspt_par,
                                                                                    UInt8 tqsys_nogeardece_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.68.0 */
    switch((UInt32)tqsys_stdrivfilcfpha_par)
    {
        case(PFILFAST_CONF_1):
        case(PFILFAST_CONF_2):
            PFILFAST_F03_02_05_02_03_01_Deceleration_Thresholds_Phase10_Config1(tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par);

            TqSys_tqThdPha10 = TqSys_tqThdPha10Cf1;
            break;

        case(PFILFAST_CONF_3):
        case(PFILFAST_CONF_4):
            PFILFAST_F03_02_05_02_03_02_Deceleration_Thresholds_Phase10_Config2(tqsys_tqckdeceiniit_par,
                                                                                tqsys_nengdeceini_par,
                                                                                tqdem_bmodspt_par,
                                                                                tqsys_nogeardece_par);

            TqSys_tqThdPha10 = TqSys_tqThdPha10Cf2;
            break;

        case(PFILFAST_CONF_0):
        default:
            TqSys_tqThdPha10 = 0;
            break;
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_03_01_Deceleration_Thresholds_Phase10_Config1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_03_01_Deceleration_Thresholds_Phase10_Config1(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.69.0 */

    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA10CF1_TYP_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }
    else
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA10CF1_TYPSPT_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA10CF1_BAS_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 = BIN4 * BIN7 / BIN4 */
    pfilfast_s32_temp2 = (pfilfast_s32_temp1 * pfilfast_s32_temp3) / BIN7;

    /* BIN4 */
    pfilfast_s32_temp3 = DDS_M_MIN((SInt32)TqSys_tqThdPha9 - pfilfast_s32_temp2,
                                                    (SInt32)TqSys_tqThdPha9);

    TqSys_tqThdPha10Cf1 = (SInt16)DDS_M_MAX(pfilfast_s32_temp3,
                                            PFILFAST_N2000_BIN4);
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_02_03_02_Deceleration_Thresholds_Phase10_Config2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_02_03_02_Deceleration_Thresholds_Phase10_Config2(SInt16 tqsys_tqckdeceiniit_par,
                                                                                                UInt16 tqsys_nengdeceini_par,
                                                                                                UInt8 tqdem_bmodspt_par,
                                                                                                UInt8 tqsys_nogeardece_par)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.70.0 */

    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    if((UInt32)DDS_FALSE == (UInt32)tqdem_bmodspt_par)
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA10CF2_TYP_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }
    else
    {
        pfilfast_s32_temp3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_FACPHA10CF2_TYPSPT_T_APM,
                                                                    tqsys_tqckdeceiniit_par);
    }

    /* BIN4 */
    pfilfast_s32_temp1 = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQTHDPHA10CF2_BAS_M_APM,
                                                                    tqsys_nengdeceini_par,
                                                                    (UInt16)tqsys_nogeardece_par);

    /* BIN4 = BIN4 * BIN7 / BIN4 */
    pfilfast_s32_temp2 = (pfilfast_s32_temp1 * pfilfast_s32_temp3) / BIN7;

    /* BIN4 */
    pfilfast_s32_temp3 = DDS_M_MIN((SInt32)TqSys_tqThdPha9 + pfilfast_s32_temp2,
                                                    (SInt32)TqSys_tqThdPha9);

    TqSys_tqThdPha10Cf2 = (SInt16)DDS_M_MAX(pfilfast_s32_temp3,
                                            PFILFAST_N2000_BIN4);
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_02_05_03_Decelerations_Slews
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_02_05_03_Decelerations_Slews(void)
{
    /* SSTG_REQ_TAG : 01460_10_01107.FR.71.0 */

    SInt32 pfilfast_s32_diff;
    SInt32 pfilfast_temp_s32;
    SInt32 tqsys_tidlypha9_cpy;         /* NDEC1 */
    SInt32 tqsys_tidlypha10_cpy;        /* NDEC1 */
    SInt32 tqsys_tidlypha11_cpy;        /* NDEC1 */
    SInt32 tqsys_tqckdrivnotfil_cpy;    /* BIN11 */

    tqsys_tidlypha9_cpy = (SInt32)TqSys_tiDlyPha9;
    tqsys_tidlypha10_cpy = (SInt32)TqSys_tiDlyPha10;
    tqsys_tidlypha11_cpy = (SInt32)TqSys_tiDlyPha11;
    tqsys_tqckdrivnotfil_cpy = TqSys_tqCkDrivNotFil;

    TqSys_tqFilDifMin = TqSys_tqFilDifMin_C;

    if((SInt32)TqSys_tqThdPha8 > (SInt32)TqSys_tqThdPha9)
    {
        if(tqsys_tidlypha9_cpy == 0)
        {
            TqSys_tqSlopPha9 = - PFILFAST_P2000_BIN11;
        }
        else
        {
            /* BIN4 */
            pfilfast_s32_diff = (SInt32)TqSys_tqThdPha9 - (SInt32)TqSys_tqThdPha8;

            /* BIN11 = (BIN4 * BIN7 * 10) / (NDEC1 * DEC1) */
            /* BIN11 = (BIN4 * BIN7) / NDEC1 */
            pfilfast_temp_s32 = (pfilfast_s32_diff * BIN7) / tqsys_tidlypha9_cpy;

            TqSys_tqSlopPha9 = DDS_M_LIMIT(pfilfast_temp_s32,
                                            PFILFAST_N2000_BIN11,
                                            PFILFAST_P2000_BIN11);
        }
    }
    else
    {
        TqSys_tqSlopPha9 = -1 * TqSys_tqFilDifMin;
    }

    if((SInt32)TqSys_tqThdPha9 > (SInt32)TqSys_tqThdPha10)
    {
        if(tqsys_tidlypha10_cpy == 0)
        {
            TqSys_tqSlopPha10 = - PFILFAST_P2000_BIN11;
        }
        else
        {
            /* BIN4 */
            pfilfast_s32_diff = (SInt32)TqSys_tqThdPha10 - (SInt32)TqSys_tqThdPha9;

            /* BIN11 = (BIN4 * BIN7 * 10) / (NDEC1 * DEC1) */
            /* BIN11 = (BIN4 * BIN7) / NDEC1 */
            pfilfast_temp_s32 = (pfilfast_s32_diff * BIN7) / tqsys_tidlypha10_cpy;

            TqSys_tqSlopPha10 = DDS_M_LIMIT(pfilfast_temp_s32,
                                            PFILFAST_N2000_BIN11,
                                            PFILFAST_P2000_BIN11);
        }
    }
    else
    {
        TqSys_tqSlopPha10 = -1 * TqSys_tqFilDifMin;
    }

    if(((SInt32)TqSys_tqThdPha10 * BIN7) > tqsys_tqckdrivnotfil_cpy)
    {
        if(tqsys_tidlypha11_cpy == 0)
        {
            TqSys_tqSlopPha11 = - PFILFAST_P2000_BIN11;
        }
        else
        {
            /* BIN11 */
            pfilfast_s32_diff = tqsys_tqckdrivnotfil_cpy - ((SInt32)TqSys_tqThdPha10 * BIN7);

            /* BIN11 = (BIN4 * BIN7 * 10) / (NDEC1 * DEC1) */
            /* BIN11 = (BIN4 * BIN7) / NDEC1 */
            pfilfast_temp_s32 = pfilfast_s32_diff / tqsys_tidlypha11_cpy;

            TqSys_tqSlopPha11 = DDS_M_LIMIT(pfilfast_temp_s32,
                                            PFILFAST_N2000_BIN11,
                                            PFILFAST_P2000_BIN11);
        }
    }
    else
    {
        TqSys_tqSlopPha11 = -1 * TqSys_tqFilDifMin;
    }
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Decel_Thres_Slew_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Decel_Thres_Slew_Init(void)
{
    TqSys_tqFilDifMin = (0 * BIN11);
    TqSys_tqSlopPha10 = (0 * BIN11);
    TqSys_tqSlopPha11 = (0 * BIN11);
    TqSys_tqSlopPha9 = (0 * BIN11);
    TqSys_tqThdPha8 = (0 * BIN4);
    TqSys_tqThdPha9 = (0 * BIN4);
    TqSys_tqThdPha10 = (0 * BIN4);
    TqSys_tqThdPha9Cf1 = (0 * BIN4);
    TqSys_tqThdPha8Cf1 = (0 * BIN4);
    TqSys_tqThdPha8Cf2 = (0 * BIN4);
    TqSys_tqThdPha10Cf2 = (0 * BIN4);
    TqSys_tqThdPha9Cf2 = (0 * BIN4);
    TqSys_tqThdPha10Cf1 = (0 * BIN4);
    tqsys_tqaclossfil_cpy = (0 * BIN4);
}



#define PFILFAST_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "PFilFast_MemMap.h"

