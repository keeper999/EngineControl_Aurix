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
* Ref X:\integration_view_00PSASWC_E620D01\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Scnd_Out.c
* Version int :/main/L01_03/1 Date: 12/3/2012 15 h 14 m User:esnault 
*    TWK_model:PFILFAST_Scnd_Out_L01_030_IMPL2
*    comments :for PFilFast 12.0: spec update
* Version dev :\main\branch_morisseau_pfilfast_euro6_dev\4 Date: 7/3/2012 8 h 46 m User:morisseau 
*    TWK_model:PFILFAST_Scnd_Out_L01_030_IMPL2
*    comments :for PFilFast 12.0: spec update
* Version int :/main/L01_02/2 Date: 16/5/2011 15 h 6 m User:esnault
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL4_D
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/4/2011 14 h 46 m User:demezil
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL4_D
*    comments :for CPU optimization
* Version int :/main/L01_02/1 Date: 17/2/2011 15 h 36 m User:meme
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL4
*    comments :update for TU
* Version dev :\main\branch_halouane\9 Date: 17/2/2011 11 h 19 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL4
*    comments :update for TU
* Version dev :\main\branch_halouane\8 Date: 16/2/2011 15 h 0 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL3
*    comments :update for TU
* Version dev :\main\branch_halouane\7 Date: 31/1/2011 17 h 7 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\6 Date: 31/1/2011 17 h 3 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\5 Date: 31/1/2011 11 h 31 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL2
*    comments :Update for 11.0
* Version dev :\main\branch_halouane\4 Date: 27/1/2011 12 h 51 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane\3 Date: 17/1/2011 12 h 21 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL1
*    comments :update for PFilFast11_0
* Version dev :\main\branch_halouane\2 Date: 17/1/2011 11 h 52 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_020_IMPL1
*    comments :update for PFilFast11_0
* Version dev :\main\branch_halouane\1 Date: 17/1/2011 11 h 51 m User:halouane
*    TWK_model:PFILFAST_Scnd_Out_L01_010_IMPL1_D
*    comments :update for PFilFast11_0
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 38 m User:esnault
*    TWK_model:PFILFAST_Scnd_Out_L01_010_IMPL1
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 12/8/2010 9 h 25 m User:demezil
*    TWK_model:PFILFAST_Scnd_Out_L01_010_IMPL1
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 13/7/2010 12 h 20 m User:demezil
*    TWK_model:PFILFAST_Scnd_Out_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Scnd_Out_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 29/6/2010 11 h 56 m User:demezil
*    TWK_model:PFILFAST_Scnd_Out_L01_010_IMPL1
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

#define PFILFAST_7_SIZE                       7
#define PFILFAST_4_SIZE                       4
#define PFILFAST_6_SIZE                       6
#define PFILFAST_8_SIZE                       8

#define PFILFAST_BVM                                (UInt32)(0 * BIN0)
#define PFILFAST_BVA                                (UInt32)(1 * BIN0)
#define PFILFAST_BVMP                               (UInt32)(2 * BIN0)

#define TYPE_1                                      (UInt32)(1 * BIN0)
#define TYPE_1_POND                                 (UInt32)(2 * BIN0)
#define TYPE_2                                      (UInt32)(3 * BIN0)
#define TYPE_2_POND                                 (UInt32)(4 * BIN0)

#define PFILFAST_STATE_NON_FIG_BVX                  (UInt32)(0 * BIN0)
#define PFILFAST_STATE_FIG_BVX_ACCEL_CLOSED         (UInt32)(1 * BIN0)
#define PFILFAST_STATE_FIG_BVX_DECEL_CLOSED         (UInt32)(2 * BIN0)
#define PFILFAST_STATE_FIG_BVX_ACCEL_OPEN           (UInt32)(3 * BIN0)
#define PFILFAST_STATE_FIG_BVX_DECEL_OPEN           (UInt32)(4 * BIN0)





#define DETECTION_EFFECIF                           (UInt32)(2 * BIN0)
/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqSys_bAcceAcv;
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

/* NONE */


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiAcceDetAOS_C = (CONST(UInt16, AUTOMATIC))(0.4 * DEC3);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdDeceUHFrz_C = (CONST(SInt16, AUTOMATIC))(10 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdDeceUHFrzOff_C = (CONST(SInt16, AUTOMATIC))(10 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaAcceAOS_C = (CONST(SInt16, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdDeltaAcceAOS_C = (CONST(SInt16, AUTOMATIC))(20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaHighAcceAOS_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaDeceAOS_C = (CONST(SInt16, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdDeltaDeceAOS_C = (CONST(SInt16, AUTOMATIC))(20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaHighDeceAOS_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsClrCross_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCylCutAuthHi_C = (CONST(SInt16, AUTOMATIC))(50 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCylCutAuthLo_C = (CONST(SInt16, AUTOMATIC))(45 * BIN4);
#define PFILFAST_STOP_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvUHFrzOff_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvUHFrz_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDetClrCrossAcv_C = DDS_TRUE;
#define PFILFAST_STOP_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyAcceClrCross_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2),
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) },
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) ,
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2)},
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2),
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) },
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) ,
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2)},
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) ,
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2)},
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) ,
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2)},
{
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2) ,
(UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2), (UInt16)(0 * DEC2)}
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyAcceClrCross_A[PFILFAST_8_SIZE] = {
(UInt16)(750 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2),
(UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(3500 * BIN2), (UInt16)(4000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiAcceTranCll_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiAcceTranCllX_A[PFILFAST_8_SIZE] = {
(UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(7000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiAcceTranCllY_A[PFILFAST_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDeceTranCll_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDeceTranCllX_A[PFILFAST_8_SIZE] = {
(UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(7000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDeceTranCllY_A[PFILFAST_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqAcceIncCll_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};


STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqDeceIncCll_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_noCylCutAuthHi_T
[PFILFAST_6_SIZE] = {
(SInt16)(0 * BIN0), (SInt16)(0 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(0 * BIN0), (SInt16)(0 * BIN0), (SInt16)(0 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_noCylCutAuth_A[PFILFAST_6_SIZE] = {
(UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(3000 * BIN2), (UInt16)(4000 * BIN2), (UInt16)(5000 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_noCylCutAuthLo_T
[PFILFAST_6_SIZE] = {
(SInt16)(0 * BIN0), (SInt16)(0 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(0 * BIN0), (SInt16)(0 * BIN0), (SInt16)(0 * BIN0)
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlyacceclrcross_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tiaccetrancll_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidecetrancll_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqacceinccll_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeceinccll_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_nocylcutauthhi_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_nocylcutauthlo_t_sav;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) pfilfast_f02_02_turnoffdelay_ptr;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) pfilfast_f02_03_turnoffdelay_ptr;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) pfilfast_hyst_ptr;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"

/* 32-bits variable definition */
#define PFILFAST_START_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) pfilfast_f02_01_01_state;
STATIC VAR(SInt32, AUTOMATIC) pfilfast_f02_02_tqsys_tqckefcfil_prev; /* BIN4 */
#define PFILFAST_STOP_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqsys_bacceacv_copy;
STATIC VAR(UInt8, AUTOMATIC) tqsys_buhfrzreq_cpy;
#define PFILFAST_STOP_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
/* <PRQA_COMMENT><3229> Variable calculated, but never used in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdDeceUHFrz; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqThdDeceUHFrzOff; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvUHFrzOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvUHFrz;
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYACCECLRCROSS_M_APM = {
&tqsys_tidlyacceclrcross_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyAcceClrCross_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyAcceClrCross_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIACCETRANCLL_M_APM = {
&tqsys_tiaccetrancll_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAcceTranCllX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAcceTranCllY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAcceTranCll_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDECETRANCLL_M_APM = {
&tqsys_tidecetrancll_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDeceTranCllX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDeceTranCllY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDeceTranCll_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TQACCEINCCLL_M_APM = {
&tqsys_tqacceinccll_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAcceTranCllX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiAcceTranCllY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqAcceIncCll_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TQDECEINCCLL_M_APM = {
&tqsys_tqdeceinccll_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDeceTranCllX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDeceTranCllY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeceIncCll_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_NOCYLCUTAUTHHI_T_APM = {
&tqsys_nocylcutauthhi_t_sav,
PFILFAST_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noCylCutAuth_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_noCylCutAuthHi_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_NOCYLCUTAUTHLO_T_APM = {
&tqsys_nocylcutauthlo_t_sav,
PFILFAST_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noCylCutAuth_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_noCylCutAuthLo_T[0]
};

#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_01_Subsystem(UInt8 tqsys_stdrivfilphait_par, /* BIN0 */
                                                        UInt8 ext_stgbxcf_par,
                                                        UInt8 copt_nodrivfiltyp_par,
                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                        UInt8 tqsys_bdeceacvit_par,
                                                        SInt16 tqsys_tqckefcfil_par,
                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_buhfrzreq_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_01_01_TqSys_Calc_Pf_Freeze_Request_UH(UInt8 tqsys_stdrivfilphait_par, /* BIN0 */
                                                                                UInt8 ext_stgbxcf_par,
                                                                                UInt8 copt_nodrivfiltyp_par,
                                                                                UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                UInt8 tqsys_bdeceacvit_par,
                                                                                SInt16 tqsys_tqckefcfil_par,
                                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_buhfrzreq_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_02_Acceleration_State(UInt8 tqclrcros_stdetclr_par, /* BIN0 */
                                                                SInt16 tqsys_tqthdpha3it_par,
                                                                SInt16 tqsys_tqckefcfil_par,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baccedetaosit_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacceclrcrossaosit_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bdecedetaosit_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_03_TqSys_Calc_Pf_Play_Crossing(UInt16 eng_nckfil_par, /* BIN2 */
                                                                            UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                            UInt8 tqsys_stdrivfilphait_par, /* BIN0 */
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bclrcrossacce_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_04_TqSys_Calc_Pf_CloseLoop(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_bdeceacvit_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvcllit_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_titrancllit_ptr, /* DEC2 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_tqinccllit_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_04_01_TqSys_Calc_Pf_CloseLoop_Active(UInt8 tqsys_bdeceacvit_par,
                                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvcllit_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_04_02_TqSys_Calc_Pf_CloseLoop(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_titrancllit_ptr, /* DEC2 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_tqinccllit_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_05_TqSys_Calc_Pf_Nb_Cyl_Cut_Auth(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        SInt16 englim_tqckdrivfil_par, /* BIN4 */
                                                                        CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) tqsys_nocylcutauthit_ptr /* BIN0 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Scnd_Out
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Scnd_Out(UInt8 CoPt_noDrivFilTyp_swc_in,
                                           SInt16 EngLim_tqCkDrivFil_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 TqClrCros_stDetClr_swc_in,
                                           UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt8 TqSys_stDrivFilPhaIt_swc_in,
                                           SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                           UInt8 TqSys_bDeceAcvIt_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCllIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bClrCrossAcce_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bUHFrzReq_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthIt_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCllIt_swc_out, /* DEC2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCllIt_swc_out /* BIN4 */)
{
    tqsys_bacceacv_copy = TqSys_bAcceAcv;

    PFILFAST_F02_01_Subsystem(TqSys_stDrivFilPhaIt_swc_in, /* BIN0 */
                                Ext_stGBxCf_swc_in,
                                CoPt_noDrivFilTyp_swc_in,
                                TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                TqSys_bDeceAcvIt_swc_in,
                                TqSys_tqCkEfcFil_swc_in,
                                TqSys_bUHFrzReq_swc_out);

    PFILFAST_F02_02_Acceleration_State(TqClrCros_stDetClr_swc_in, /* BIN0 */
                                        TqSys_tqThdPha3It_swc_in,
                                        TqSys_tqCkEfcFil_swc_in,
                                        TqSys_bAcceDetAOSIt_swc_out,
                                        TqSys_bAcceClrCrossAOSIt_swc_out,
                                        TqSys_bDeceDetAOSIt_swc_out);

    PFILFAST_F02_03_TqSys_Calc_Pf_Play_Crossing(Eng_nCkFil_swc_in, /* BIN2 */
                                                    TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                    TqSys_stDrivFilPhaIt_swc_in, /* BIN0 */
                                                    TqSys_bClrCrossAcce_swc_out);

    PFILFAST_F02_04_TqSys_Calc_Pf_CloseLoop(Eng_nCkFil_swc_in, /* BIN2 */
                                                TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                TqSys_bDeceAcvIt_swc_in,
                                                TqSys_bAcvCllIt_swc_out,
                                                TqSys_tiTranCllIt_swc_out, /* DEC2 */
                                                TqSys_tqIncCllIt_swc_out /* BIN4 */);

    PFILFAST_F02_05_TqSys_Calc_Pf_Nb_Cyl_Cut_Auth(Eng_nCkFil_swc_in, /* BIN2 */
                                                    EngLim_tqCkDrivFil_swc_in, /* BIN4 */
                                                    TqSys_noCylCutAuthIt_swc_out /* BIN0 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_F02_01_Subsystem
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_01_Subsystem(UInt8 tqsys_stdrivfilphait_par, /* BIN0 */
                                                        UInt8 ext_stgbxcf_par,
                                                        UInt8 copt_nodrivfiltyp_par,
                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                        UInt8 tqsys_bdeceacvit_par,
                                                        SInt16 tqsys_tqckefcfil_par,
                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_buhfrzreq_ptr)
{
    /* We do not use a current time for all task in order to have the minimum modification with previous verion. */
    /* We do so because PFilFast is near SOP (Start Of Production) */

    /* SSTG REQ_TAG 01460_10_01107.FR.78.1*/
    TqSys_tqThdDeceUHFrz = TqSys_tqThdDeceUHFrz_C;
    TqSys_tqThdDeceUHFrzOff = TqSys_tqThdDeceUHFrzOff_C;
    TqSys_bAcvUHFrzOff = TqSys_bAcvUHFrzOff_C;
    TqSys_bAcvUHFrz = TqSys_bAcvUHFrz_C;

    PFILFAST_F02_01_01_TqSys_Calc_Pf_Freeze_Request_UH(tqsys_stdrivfilphait_par, /* BIN0 */
                                                        ext_stgbxcf_par,
                                                        copt_nodrivfiltyp_par,
                                                        tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                        tqsys_bdeceacvit_par,
                                                        tqsys_tqckefcfil_par,
                                                        tqsys_buhfrzreq_ptr);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_01_01_TqSys_Calc_Pf_Freeze_Request_UH
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_01_01_TqSys_Calc_Pf_Freeze_Request_UH(UInt8 tqsys_stdrivfilphait_par, /* BIN0 */
                                                                                UInt8 ext_stgbxcf_par,
                                                                                UInt8 copt_nodrivfiltyp_par,
                                                                                UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                UInt8 tqsys_bdeceacvit_par,
                                                                                SInt16 tqsys_tqckefcfil_par,
                                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_buhfrzreq_ptr)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.78*/
    switch(pfilfast_f02_01_01_state)
    {
        case PFILFAST_STATE_NON_FIG_BVX :

            if((((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_copy) || ((UInt32)DDS_FALSE != (UInt32)tqsys_bdeceacvit_par)) &&
                (((UInt32)DDS_FALSE != (UInt32)TqSys_bAcvUHFrz) && ((UInt32)0 != (UInt32)tqsys_nogearcorddrivfil_par)))
            {
                if(((UInt32)DDS_FALSE != (UInt32)TqSys_bAcvUHFrzOff) &&
                    ( (TYPE_2 == (UInt32)copt_nodrivfiltyp_par) ||
                      (TYPE_2_POND == (UInt32)copt_nodrivfiltyp_par) ))
                {
                    if(((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_copy) &&
                        ( (PFILFAST_ACCE_GAP_START_FILT == (UInt32)tqsys_stdrivfilphait_par) ||
                          (PFILFAST_ACCE_1ST_ORDER_FILT == (UInt32)tqsys_stdrivfilphait_par) ||
                          (PFILFAST_ACCE_SET_PASS_SLOPE == (UInt32)tqsys_stdrivfilphait_par) ))
                    {
                        pfilfast_f02_01_01_state = PFILFAST_STATE_FIG_BVX_ACCEL_OPEN;
                        tqsys_buhfrzreq_cpy = DDS_TRUE;
                    }
                    else
                    {
                        if( ((UInt32)DDS_FALSE != (UInt32)tqsys_bdeceacvit_par) &&
                            (   (   (PFILFAST_DECE_1ST_SLOPE == (UInt32)tqsys_stdrivfilphait_par) &&
                                    ((SInt32)tqsys_tqckefcfil_par <= (SInt32)TqSys_tqThdDeceUHFrzOff)) ||
                                (PFILFAST_DECE_3RD_SLOPE == (UInt32)tqsys_stdrivfilphait_par) ||
                                (PFILFAST_DECE_2ND_SLOPE == (UInt32)tqsys_stdrivfilphait_par)))
                        {
                            pfilfast_f02_01_01_state = PFILFAST_STATE_FIG_BVX_DECEL_OPEN;
                            tqsys_buhfrzreq_cpy = DDS_TRUE;
                        }
                        else
                        {
                            /* DO NOTHING */
                        }
                    }
                }
                else
                {
                    if((((PFILFAST_BVA == (UInt32)ext_stgbxcf_par) || (PFILFAST_BVMP == (UInt32)ext_stgbxcf_par)) &&
                        ((TYPE_1 == (UInt32)copt_nodrivfiltyp_par) || (TYPE_1_POND == (UInt32)copt_nodrivfiltyp_par))) ||
                        ((UInt32)ext_stgbxcf_par == PFILFAST_BVM))
                    {
                        if( ((UInt32)DDS_FALSE != (UInt32)tqsys_bdeceacvit_par) &&
                            (   (   (PFILFAST_DECE_1ST_SLOPE == (UInt32)tqsys_stdrivfilphait_par) &&
                                    ((SInt32)tqsys_tqckefcfil_par <= (SInt32)TqSys_tqThdDeceUHFrzOff)) ||
                                (PFILFAST_DECE_3RD_SLOPE == (UInt32)tqsys_stdrivfilphait_par) ||
                                (PFILFAST_DECE_2ND_SLOPE == (UInt32)tqsys_stdrivfilphait_par)))
                        {
                            pfilfast_f02_01_01_state = PFILFAST_STATE_FIG_BVX_DECEL_CLOSED;
                            tqsys_buhfrzreq_cpy = DDS_TRUE;
                        }
                        else
                        {
                            if( ((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_copy) &&
                                (   (PFILFAST_ACCE_GAP_START_FILT == (UInt32)tqsys_stdrivfilphait_par) ||
                                    (PFILFAST_ACCE_1ST_ORDER_FILT == (UInt32)tqsys_stdrivfilphait_par) ||
                                    (PFILFAST_ACCE_SET_PASS_SLOPE == (UInt32)tqsys_stdrivfilphait_par) ))
                            {
                                pfilfast_f02_01_01_state = PFILFAST_STATE_FIG_BVX_ACCEL_CLOSED;
                                tqsys_buhfrzreq_cpy = DDS_TRUE;
                            }
                            else
                            {
                                /* DO NOTHING */
                            }
                        }
                    }
                }
            }
            else
            {
                /* DO NOTHING*/
            }
            break;

        case PFILFAST_STATE_FIG_BVX_ACCEL_CLOSED :

            if((UInt32)DDS_FALSE == (UInt32)tqsys_bacceacv_copy)
            {
                pfilfast_f02_01_01_state = PFILFAST_STATE_NON_FIG_BVX;
                tqsys_buhfrzreq_cpy = DDS_FALSE;
            }
            else
            {
                /* DO NOTHING */
            }
            break;

        case PFILFAST_STATE_FIG_BVX_DECEL_CLOSED :

            if((UInt32)DDS_FALSE == (UInt32)tqsys_bdeceacvit_par)
            {
                pfilfast_f02_01_01_state = PFILFAST_STATE_NON_FIG_BVX;
                tqsys_buhfrzreq_cpy = DDS_FALSE;
            }
            else
            {
                /* DO NOTHING */
            }
            break;

        case PFILFAST_STATE_FIG_BVX_ACCEL_OPEN :

            if((UInt32)DDS_FALSE == (UInt32)tqsys_bacceacv_copy)
            {
                pfilfast_f02_01_01_state = PFILFAST_STATE_NON_FIG_BVX;
                tqsys_buhfrzreq_cpy = DDS_FALSE;
            }
            else
            {
                /* DO NOTHING */
            }
            break;

        case PFILFAST_STATE_FIG_BVX_DECEL_OPEN :

            if((UInt32)DDS_FALSE == (UInt32)tqsys_bdeceacvit_par)
            {
                pfilfast_f02_01_01_state = PFILFAST_STATE_NON_FIG_BVX;
                tqsys_buhfrzreq_cpy = DDS_FALSE;
            }
            else
            {
                /* DO NOTHING */
            }
            break;

        default :
            pfilfast_f02_01_01_state = PFILFAST_STATE_NON_FIG_BVX;
            tqsys_buhfrzreq_cpy = DDS_FALSE;
            break;
    }

    *tqsys_buhfrzreq_ptr = tqsys_buhfrzreq_cpy;
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_02_Acceleration_State
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_02_Acceleration_State(UInt8 tqclrcros_stdetclr_par, /* BIN0 */
                                                                SInt16 tqsys_tqthdpha3it_par,
                                                                SInt16 tqsys_tqckefcfil_par,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baccedetaosit_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacceclrcrossaosit_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bdecedetaosit_ptr)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.79.1 */
    SInt32 temp_s32;
    UInt8 tqsys_baccedet;
    UInt8 tqsys_baccedetaosit_delay_input;
    UInt32 current_time;

    /* We do not use a current time for all task in order to have the minimum modification with previous verion. */
    /* We do so because PFilFast is near SOP (Start Of Production) */
    current_time = DDS_PFILFAST_1MS_U32_TIME;

    /* calul tqsys_baccedet*/
    if((SInt32)tqsys_tqckefcfil_par > (SInt32)TqSys_tqThdDeltaAcceAOS_C)
    {
        /* BIN4 = BIN4 + BIN4 */
        temp_s32 = (SInt32)TqSys_tqDeltaHighAcceAOS_C + pfilfast_f02_02_tqsys_tqckefcfil_prev;
    }
    else
    {
        /* BIN4 = BIN4 + BIN4 */
        temp_s32 = (SInt32)TqSys_tqDeltaAcceAOS_C + pfilfast_f02_02_tqsys_tqckefcfil_prev;
    }
    if((SInt32)tqsys_tqckefcfil_par < temp_s32)
    {
        tqsys_baccedet = DDS_FALSE;
    }
    else
    {
        tqsys_baccedet = DDS_TRUE;
    }

    /* calcul TqSys_bDeceDetAOSIt*/
    if((SInt32)tqsys_tqckefcfil_par > (SInt32)TqSys_tqThdDeltaDeceAOS_C)
    {
        /* BIN4 = BIN4 + BIN4 */
        temp_s32 = pfilfast_f02_02_tqsys_tqckefcfil_prev - (SInt32)TqSys_tqDeltaHighDeceAOS_C;
    }
    else
    {
        /* BIN4 = BIN4 + BIN4 */
        temp_s32 = pfilfast_f02_02_tqsys_tqckefcfil_prev - (SInt32)TqSys_tqDeltaDeceAOS_C;
    }
    if((SInt32)tqsys_tqckefcfil_par > temp_s32)
    {
        *tqsys_bdecedetaosit_ptr = DDS_FALSE;
    }
    else
    {
        *tqsys_bdecedetaosit_ptr = DDS_TRUE;
    }

    /* calcul other outputs */
    if((UInt32)tqsys_baccedet != (UInt32)DDS_FALSE)
    {
        /* BIN4 = BIN4 + BIN4 */
        temp_s32 = (SInt32)tqsys_tqthdpha3it_par + (SInt32)TqSys_tqOfsClrCross_C;
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bDetClrCrossAcv_C)
        {
            if((SInt32)tqsys_tqckefcfil_par > temp_s32)
            {
                tqsys_baccedetaosit_delay_input = DDS_TRUE;
                *tqsys_bacceclrcrossaosit_ptr = DDS_FALSE;
            }
            else
            {
                tqsys_baccedetaosit_delay_input = DDS_FALSE;
                *tqsys_bacceclrcrossaosit_ptr = DDS_TRUE;
            }
        }
        else
        {
            if(DETECTION_EFFECIF > (UInt32)tqclrcros_stdetclr_par)
            {
                tqsys_baccedetaosit_delay_input = DDS_FALSE;
                *tqsys_bacceclrcrossaosit_ptr = DDS_TRUE;
            }
            else
            {
                tqsys_baccedetaosit_delay_input = DDS_TRUE;
                *tqsys_bacceclrcrossaosit_ptr = DDS_FALSE;
            }
        }
    }
    else
    {
        tqsys_baccedetaosit_delay_input = DDS_FALSE;
        *tqsys_bacceclrcrossaosit_ptr = DDS_FALSE;
    }
    *tqsys_baccedetaosit_ptr = DDS_M_TURN_OFF_DELAY(tqsys_baccedetaosit_delay_input,
                                                    current_time,
                                                    TqSys_tiAcceDetAOS_C,
                                                    &pfilfast_f02_02_turnoffdelay_ptr);

    /* update prev */
    pfilfast_f02_02_tqsys_tqckefcfil_prev = (SInt32)tqsys_tqckefcfil_par;
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_03_TqSys_Calc_Pf_Play_Crossing
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_03_TqSys_Calc_Pf_Play_Crossing(UInt16 eng_nckfil_par, /* BIN2 */
                                                                            UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                            UInt8 tqsys_stdrivfilphait_par, /* BIN0 */
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bclrcrossacce_ptr)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.80*/
    UInt32 tqsys_tidlyacceclrcross_m;
    UInt8 in_turn_off_delay;

    tqsys_tidlyacceclrcross_m = (UInt32)DDS_M_MAP3D_U16(&TQSYS_TIDLYACCECLRCROSS_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    if(PFILFAST_ACCE_SET_PASS_SLOPE == (UInt32)tqsys_stdrivfilphait_par)
    {
        in_turn_off_delay = DDS_TRUE;
    }
    else
    {
        in_turn_off_delay = DDS_FALSE;
    }

    *tqsys_bclrcrossacce_ptr = DDS_M_TURN_OFF_DELAY(in_turn_off_delay,
                                                    DDS_PFILFAST_1MS_U32_TIME,
                                                    (tqsys_tidlyacceclrcross_m * DEC1),
                                                    &pfilfast_f02_03_turnoffdelay_ptr);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_04_TqSys_Calc_Pf_CloseLoop
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_04_TqSys_Calc_Pf_CloseLoop(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_bdeceacvit_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvcllit_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_titrancllit_ptr, /* DEC2 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_tqinccllit_ptr /* BIN4 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.81*/
    PFILFAST_F02_04_01_TqSys_Calc_Pf_CloseLoop_Active(tqsys_bdeceacvit_par,
                                                        tqsys_bacvcllit_ptr);

    PFILFAST_F02_04_02_TqSys_Calc_Pf_CloseLoop(eng_nckfil_par, /* BIN2 */
                                                tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                tqsys_titrancllit_ptr, /* DEC2 */
                                                tqsys_tqinccllit_ptr /* BIN4 */);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_04_01_TqSys_Calc_Pf_CloseLoop_Active
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_04_01_TqSys_Calc_Pf_CloseLoop_Active(UInt8 tqsys_bdeceacvit_par,
                                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvcllit_ptr)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.82*/
    if( ((UInt32)DDS_FALSE != (UInt32)tqsys_bdeceacvit_par) ||
        ((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_copy) )
    {
        *tqsys_bacvcllit_ptr = DDS_TRUE;
    }
    else
    {
        *tqsys_bacvcllit_ptr = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_04_02_TqSys_Calc_Pf_CloseLoop
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_04_02_TqSys_Calc_Pf_CloseLoop(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_titrancllit_ptr, /* DEC2 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_tqinccllit_ptr /* BIN4 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.83*/
    if((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_copy)
    {
        *tqsys_titrancllit_ptr = DDS_M_MAP3D_U16(&TQSYS_TIACCETRANCLL_M_APM,
                                            eng_nckfil_par,
                                            (UInt16)tqsys_nogearcorddrivfil_par);

        *tqsys_tqinccllit_ptr = DDS_M_MAP3D_U16(&TQSYS_TQACCEINCCLL_M_APM,
                                            eng_nckfil_par,
                                            (UInt16)tqsys_nogearcorddrivfil_par);
    }
    else
    {
        *tqsys_titrancllit_ptr = DDS_M_MAP3D_U16(&TQSYS_TIDECETRANCLL_M_APM,
                                            eng_nckfil_par,
                                            (UInt16)tqsys_nogearcorddrivfil_par);

        *tqsys_tqinccllit_ptr = DDS_M_MAP3D_U16(&TQSYS_TQDECEINCCLL_M_APM,
                                            eng_nckfil_par,
                                            (UInt16)tqsys_nogearcorddrivfil_par);
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F02_05_TqSys_Calc_Pf_Nb_Cyl_Cut_Auth
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F02_05_TqSys_Calc_Pf_Nb_Cyl_Cut_Auth(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        SInt16 englim_tqckdrivfil_par, /* BIN4 */
                                                                        CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) tqsys_nocylcutauthit_ptr /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.85*/
    UInt8 pfilfast_out_hyst;

    pfilfast_out_hyst = DDS_M_HYST_PH_S32 (&pfilfast_hyst_ptr,
                                            (SInt32)englim_tqckdrivfil_par,
                                            (SInt32)TqSys_tqCylCutAuthHi_C,
                                            (SInt32)TqSys_tqCylCutAuthLo_C);

    if((UInt32)DDS_FALSE != (UInt32)pfilfast_out_hyst)
    {
        *tqsys_nocylcutauthit_ptr = (SInt8)DDS_M_MAP2D_US16(&TQSYS_NOCYLCUTAUTHHI_T_APM,
                                                        eng_nckfil_par);
    }
    else
    {
        *tqsys_nocylcutauthit_ptr = (SInt8)DDS_M_MAP2D_US16(&TQSYS_NOCYLCUTAUTHLO_T_APM,
                                                        eng_nckfil_par);
    }
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Scnd_Out_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Scnd_Out_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCllIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bClrCrossAcce_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOSIt_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bUHFrzReq_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuthIt_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCllIt_swc_out, /* DEC2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCllIt_swc_out /* BIN4 */)
{
    /* Init state machine of f02_01_01*/
    pfilfast_f02_01_01_state = (UInt32)0;

    /* Init prev */
    pfilfast_f02_02_tqsys_tqckefcfil_prev = (SInt32)(0 * BIN4);

    /* Init macros */
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,
                                &pfilfast_f02_03_turnoffdelay_ptr);

    DDS_M_HYST_S32_INIT (&pfilfast_hyst_ptr,
                            DDS_TRUE);

    /* Init outputs */
    *TqSys_bAcceDetAOSIt_swc_out = DDS_FALSE;
    *TqSys_bAcceClrCrossAOSIt_swc_out = DDS_FALSE;
    *TqSys_bAcvCllIt_swc_out = DDS_FALSE;
    *TqSys_bDeceDetAOSIt_swc_out = DDS_FALSE;
    *TqSys_bClrCrossAcce_swc_out = DDS_FALSE;
    *TqSys_bUHFrzReq_swc_out = DDS_FALSE;
    *TqSys_noCylCutAuthIt_swc_out = (0 * BIN0);
    *TqSys_tiTranCllIt_swc_out = (0 * DEC2);
    *TqSys_tqIncCllIt_swc_out = (0 * BIN4);

    tqsys_buhfrzreq_cpy = DDS_FALSE;

    /* Init Displayable Variable */
    TqSys_bAcvUHFrz = DDS_FALSE;
    TqSys_tqThdDeceUHFrzOff = (0 * BIN4);
    TqSys_tqThdDeceUHFrz  = (0 * BIN4);
    TqSys_bAcvUHFrzOff  = DDS_FALSE;

    /* Init Non Displayable Variable */
    tqsys_bacceacv_copy = DDS_FALSE;

    /** PFILFAST_F02_02_Acceleration_State **/
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,
                              &pfilfast_f02_02_turnoffdelay_ptr);
}

#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

