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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Coord_Lost_Motor.c
* Version int :/main/L03_01/1 Date: 21/3/2012 15 h 8 m User:esnault 
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L03_010_IMPL2
*    comments :For TqAdpCmp_11_0_e6 / Correction for UT....
* Version dev :\main\branch_halouane_tqadpcmp_e6\3 Date: 14/3/2012 10 h 16 m User:halouane 
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L03_010_IMPL2
*    comments :For TqAdpCmp_11_0_e6 / Correction for UT....
* Version dev :\main\branch_halouane_tqadpcmp_e6\2 Date: 9/3/2012 14 h 11 m User:halouane
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L03_010_IMPL2
*    comments :For TqAdpCmp_11_0_e6 , correction after UT
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 2/3/2012 10 h 4 m User:halouane
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_01/2 Date: 14/9/2011 16 h 28 m User:meme
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L02_010_IMPL1_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 14/9/2011 14 h 25 m User:halouane
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L02_010_IMPL1_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_demezil_tqadpcmp_dev\1 Date: 29/4/2011 9 h 16 m User:demezil
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L02_010_IMPL1_D
*    comments :to reduce CPU load
* Version int :/main/L02_01/1 Date: 18/11/2010 12 h 48 m User:meme
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L02_010_IMPL1
*    comments :For TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 16/11/2010 17 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L02_010_IMPL1
*    comments :For TqAdpCmp 10.2
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 22 m User:esnault
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\11 Date: 10/9/2010 10 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\10 Date: 8/9/2010 9 h 18 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 6/9/2010 14 h 18 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp euro6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 18/8/2010 8 h 51 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 17/8/2010 16 h 9 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 22/7/2010 16 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 24/6/2010 10 h 54 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 21 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Lost_Motor_L01_010_IMPL1
*    comments :for TqAdpCmp: just structure of file
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

#include "TqAdpCmp.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQADPCMP_04_CNT_MAX             ((UInt32)(655 * DEC2))
#define TQADPCMP_INCREMENT_COUNTER            ((UInt32)(0.01 * DEC2))



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
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_pDeltaPmpLossDft_C = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_pOilEngLossDft_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tEngFricLossDft_C = (CONST(SInt16, AUTOMATIC))(90 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tOilEngLossDft_C = (CONST(SInt16, AUTOMATIC))(90 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEngLossDecMax_C = (CONST(SInt16, AUTOMATIC))(-50 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkEngLossIncMax_C = (CONST(UInt16, AUTOMATIC))(50 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nStrtTqLoss_C = (CONST(UInt16, AUTOMATIC))(800 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nStopTqLoss_C = (CONST(UInt16, AUTOMATIC))(400 * BIN0);

#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facTCkEngLoss_C = (CONST(UInt8, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_idxPEx_C = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_idxPmpLoss_C = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorTqCkOilPmpLoss_A[TQADPCMP_8_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(3000 * BIN0), (UInt16)(4000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(6500 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorTqCkOilPmpLoss_T
[TQADPCMP_8_SIZE] = {
(UInt16)(1.0 * BIN10), (UInt16)(1.0 * BIN10), (UInt16)(1.0 * BIN10),
(UInt16)(0.9 * BIN10), (UInt16)(0.8 * BIN10), (UInt16)(0.7 * BIN10),
(UInt16)(0.6 * BIN10), (UInt16)(0.5 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorTqCkStrtLoss_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * DEC0), (UInt16)(60 * DEC0), (UInt16)(120 * DEC0),
(UInt16)(300 * DEC0), (UInt16)(600 * DEC0), (UInt16)(900 * DEC0),
(UInt16)(1500 * DEC0), (UInt16)(3000 * DEC0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorTqCkStrtLoss_T
[TQADPCMP_8_SIZE] = {
(UInt16)(0.0 * BIN10), (UInt16)(0.5 * BIN10), (UInt16)(0.6 * BIN10),
(UInt16)(0.7 * BIN10), (UInt16)(0.8 * BIN10), (UInt16)(0.9 * BIN10),
(UInt16)(1.0 * BIN10), (UInt16)(1.0 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkFricLossX_A[TQADPCMP_16_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(750 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1250 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(1750 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(2250 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(3000 * BIN0), (UInt16)(3500 * BIN0), (UInt16)(4000 * BIN0),
(UInt16)(4500 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5500 * BIN0),
(UInt16)(6500 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkFricLossY_A[TQADPCMP_16_SIZE] = {
(SInt16)(-40 * BIN0), (SInt16)(-20 * BIN0), (SInt16)(-10 * BIN0),
(SInt16)(0 * BIN0), (SInt16)(10 * BIN0), (SInt16)(20 * BIN0),
(SInt16)(30 * BIN0), (SInt16)(40 * BIN0), (SInt16)(50 * BIN0),
(SInt16)(60 * BIN0), (SInt16)(70 * BIN0), (SInt16)(80 * BIN0),
(SInt16)(90 * BIN0), (SInt16)(100 * BIN0), (SInt16)(110 * BIN0),
(SInt16)(120 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkFricLoss_M
[TQADPCMP_16_SIZE][TQADPCMP_16_SIZE] = {
{
(UInt16)(71 * BIN4), (UInt16)(72.25 * BIN4), (UInt16)(73.63 * BIN4),
(UInt16)(75.88 * BIN4), (UInt16)(81.56 * BIN4), (UInt16)(80.75 * BIN4),
(UInt16)(83.56 * BIN4), (UInt16)(87.13 * BIN4), (UInt16)(89.06 * BIN4),
(UInt16)(91.38 * BIN4), (UInt16)(97.06 * BIN4), (UInt16)(100.63 * BIN4),
(UInt16)(101 * BIN4), (UInt16)(101 * BIN4), (UInt16)(101 * BIN4),
(UInt16)(101 * BIN4) },
{
(UInt16)(51.88 * BIN4), (UInt16)(53.19 * BIN4), (UInt16)(54.56 * BIN4),
(UInt16)(56.75 * BIN4), (UInt16)(62.5 * BIN4), (UInt16)(61.69 * BIN4),
(UInt16)(64.5 * BIN4), (UInt16)(68.06 * BIN4), (UInt16)(70 * BIN4),
(UInt16)(72.25 * BIN4), (UInt16)(78 * BIN4), (UInt16)(81.56 * BIN4),
(UInt16)(82 * BIN4), (UInt16)(82 * BIN4), (UInt16)(82 * BIN4),
(UInt16)(82 * BIN4) },
{
(UInt16)(44.94 * BIN4), (UInt16)(46.19 * BIN4), (UInt16)(47.56 * BIN4),
(UInt16)(49.81 * BIN4), (UInt16)(55.5 * BIN4), (UInt16)(54.69 * BIN4),
(UInt16)(57.5 * BIN4), (UInt16)(61.06 * BIN4), (UInt16)(63 * BIN4),
(UInt16)(65.31 * BIN4), (UInt16)(71 * BIN4), (UInt16)(74.56 * BIN4),
(UInt16)(75 * BIN4), (UInt16)(75 * BIN4), (UInt16)(75 * BIN4),
(UInt16)(75 * BIN4) },
{
(UInt16)(36.88 * BIN4), (UInt16)(38.19 * BIN4), (UInt16)(39.56 * BIN4),
(UInt16)(41.75 * BIN4), (UInt16)(47.5 * BIN4), (UInt16)(46.69 * BIN4),
(UInt16)(49.5 * BIN4), (UInt16)(53.06 * BIN4), (UInt16)(55 * BIN4),
(UInt16)(57.25 * BIN4), (UInt16)(63 * BIN4), (UInt16)(66.56 * BIN4),
(UInt16)(67 * BIN4), (UInt16)(67 * BIN4), (UInt16)(67 * BIN4),
(UInt16)(67 * BIN4) },
{
(UInt16)(23.88 * BIN4), (UInt16)(25.19 * BIN4), (UInt16)(26.56 * BIN4),
(UInt16)(28.75 * BIN4), (UInt16)(34.5 * BIN4), (UInt16)(33.69 * BIN4),
(UInt16)(36.5 * BIN4), (UInt16)(40.06 * BIN4), (UInt16)(42 * BIN4),
(UInt16)(44.25 * BIN4), (UInt16)(50 * BIN4), (UInt16)(53.56 * BIN4),
(UInt16)(54 * BIN4), (UInt16)(54 * BIN4), (UInt16)(54 * BIN4),
(UInt16)(54 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) },
{
(UInt16)(20.88 * BIN4), (UInt16)(22.19 * BIN4), (UInt16)(23.56 * BIN4),
(UInt16)(25.75 * BIN4), (UInt16)(31.5 * BIN4), (UInt16)(30.69 * BIN4),
(UInt16)(33.5 * BIN4), (UInt16)(37.06 * BIN4), (UInt16)(39 * BIN4),
(UInt16)(41.25 * BIN4), (UInt16)(47 * BIN4), (UInt16)(50.56 * BIN4),
(UInt16)(51 * BIN4), (UInt16)(51 * BIN4), (UInt16)(51 * BIN4),
(UInt16)(51 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkOilPmpLossX_A[TQADPCMP_8_SIZE] = {
(UInt16)(2.0 * BIN7), (UInt16)(2.5 * BIN7), (UInt16)(3.0 * BIN7),
(UInt16)(3.5 * BIN7), (UInt16)(4.0 * BIN7), (UInt16)(4.5 * BIN7),
(UInt16)(5.0 * BIN7), (UInt16)(6.0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkOilPmpLossY_A[TQADPCMP_8_SIZE] = {
(SInt16)(-40 * BIN0), (SInt16)(-20 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(20 * BIN0), (SInt16)(40 * BIN0), (SInt16)(60 * BIN0),
(SInt16)(80 * BIN0), (SInt16)(100 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkOilPmpLoss_M
[TQADPCMP_8_SIZE][TQADPCMP_8_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkPmpLossAirLdY_A[TQADPCMP_16_SIZE] = {
(UInt16)(0.0 * BIN14), (UInt16)(0.2 * BIN14), (UInt16)(0.4 * BIN14),
(UInt16)(0.6 * BIN14), (UInt16)(0.8 * BIN14), (UInt16)(1.0 * BIN14),
(UInt16)(1.2 * BIN14), (UInt16)(1.4 * BIN14), (UInt16)(1.6 * BIN14),
(UInt16)(1.8 * BIN14), (UInt16)(2.0 * BIN14), (UInt16)(2.2 * BIN14),
(UInt16)(2.4 * BIN14), (UInt16)(2.6 * BIN14), (UInt16)(2.8 * BIN14),
(UInt16)(3.0 * BIN14)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkPmpLossAirLd_M
[TQADPCMP_16_SIZE][TQADPCMP_16_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkPmpLossOfs_A[TQADPCMP_8_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(600 * BIN0), (UInt16)(700 * BIN0),
(UInt16)(800 * BIN0), (UInt16)(900 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1100 * BIN0), (UInt16)(1200 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkPmpLossOfs_T
[TQADPCMP_8_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkPmpLossPAirY_A[TQADPCMP_16_SIZE] = {
(SInt16)(-3.0 * BIN10), (SInt16)(-2.5 * BIN10), (SInt16)(-2.0 * BIN10),
(SInt16)(-1.5 * BIN10), (SInt16)(-1.0 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.25 * BIN10), (SInt16)(-0.1 * BIN10), (SInt16)(0.1 * BIN10),
(SInt16)(0.25 * BIN10), (SInt16)(0.5 * BIN10), (SInt16)(1.0 * BIN10),
(SInt16)(1.5 * BIN10), (SInt16)(2.0 * BIN10), (SInt16)(2.5 * BIN10),
(SInt16)(3.0 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkPmpLossPAir_M
[TQADPCMP_16_SIZE][TQADPCMP_16_SIZE] = {
{
(SInt16)(71 * BIN4), (SInt16)(72.25 * BIN4), (SInt16)(73.63 * BIN4),
(SInt16)(75.88 * BIN4), (SInt16)(81.56 * BIN4), (SInt16)(80.75 * BIN4),
(SInt16)(83.56 * BIN4), (SInt16)(87.13 * BIN4), (SInt16)(89.06 * BIN4),
(SInt16)(91.38 * BIN4), (SInt16)(97.06 * BIN4), (SInt16)(100.63 * BIN4),
(SInt16)(101 * BIN4), (SInt16)(101 * BIN4), (SInt16)(101 * BIN4),
(SInt16)(101 * BIN4) },
{
(SInt16)(51.88 * BIN4), (SInt16)(53.19 * BIN4), (SInt16)(54.56 * BIN4),
(SInt16)(56.75 * BIN4), (SInt16)(62.5 * BIN4), (SInt16)(61.69 * BIN4),
(SInt16)(64.5 * BIN4), (SInt16)(68.06 * BIN4), (SInt16)(70 * BIN4),
(SInt16)(72.25 * BIN4), (SInt16)(78 * BIN4), (SInt16)(81.56 * BIN4),
(SInt16)(82 * BIN4), (SInt16)(82 * BIN4), (SInt16)(82 * BIN4),
(SInt16)(82 * BIN4) },
{
(SInt16)(44.94 * BIN4), (SInt16)(46.19 * BIN4), (SInt16)(47.56 * BIN4),
(SInt16)(49.81 * BIN4), (SInt16)(55.5 * BIN4), (SInt16)(54.69 * BIN4),
(SInt16)(57.5 * BIN4), (SInt16)(61.06 * BIN4), (SInt16)(63 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(71 * BIN4), (SInt16)(74.56 * BIN4),
(SInt16)(75 * BIN4), (SInt16)(75 * BIN4), (SInt16)(75 * BIN4),
(SInt16)(75 * BIN4) },
{
(SInt16)(36.88 * BIN4), (SInt16)(38.19 * BIN4), (SInt16)(39.56 * BIN4),
(SInt16)(41.75 * BIN4), (SInt16)(47.5 * BIN4), (SInt16)(46.69 * BIN4),
(SInt16)(49.5 * BIN4), (SInt16)(53.06 * BIN4), (SInt16)(55 * BIN4),
(SInt16)(57.25 * BIN4), (SInt16)(63 * BIN4), (SInt16)(66.56 * BIN4),
(SInt16)(67 * BIN4), (SInt16)(67 * BIN4), (SInt16)(67 * BIN4),
(SInt16)(67 * BIN4) },
{
(SInt16)(23.88 * BIN4), (SInt16)(25.19 * BIN4), (SInt16)(26.56 * BIN4),
(SInt16)(28.75 * BIN4), (SInt16)(34.5 * BIN4), (SInt16)(33.69 * BIN4),
(SInt16)(36.5 * BIN4), (SInt16)(40.06 * BIN4), (SInt16)(42 * BIN4),
(SInt16)(44.25 * BIN4), (SInt16)(50 * BIN4), (SInt16)(53.56 * BIN4),
(SInt16)(54 * BIN4), (SInt16)(54 * BIN4), (SInt16)(54 * BIN4),
(SInt16)(54 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) },
{
(SInt16)(20.88 * BIN4), (SInt16)(22.19 * BIN4), (SInt16)(23.56 * BIN4),
(SInt16)(25.75 * BIN4), (SInt16)(31.5 * BIN4), (SInt16)(30.69 * BIN4),
(SInt16)(33.5 * BIN4), (SInt16)(37.06 * BIN4), (SInt16)(39 * BIN4),
(SInt16)(41.25 * BIN4), (SInt16)(47 * BIN4), (SInt16)(50.56 * BIN4),
(SInt16)(51 * BIN4), (SInt16)(51 * BIN4), (SInt16)(51 * BIN4),
(SInt16)(51 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkPmpLossX_A[TQADPCMP_16_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(750 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1250 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(1750 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(2250 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(3000 * BIN0), (UInt16)(3500 * BIN0), (UInt16)(4000 * BIN0),
(UInt16)(4500 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5500 * BIN0),
(UInt16)(6500 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkStrtLossX_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * DEC1), (UInt16)(2 * DEC1), (UInt16)(4 * DEC1),
(UInt16)(6 * DEC1), (UInt16)(8 * DEC1), (UInt16)(10 * DEC1),
(UInt16)(15 * DEC1), (UInt16)(20 * DEC1)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkStrtLossY_A[TQADPCMP_8_SIZE] = {
(SInt16)(-40 * BIN0), (SInt16)(-20 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(20 * BIN0), (SInt16)(40 * BIN0), (SInt16)(60 * BIN0),
(SInt16)(80 * BIN0), (SInt16)(100 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkStrtLoss_M
[TQADPCMP_8_SIZE][TQADPCMP_8_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4) }
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_faccortqckoilpmploss_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_faccortqckstrtloss_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqckfricloss_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqckoilpmploss_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqckpmplossairld_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqckpmplossofs_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqckpmplosspair_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqckstrtloss_m_sav;
STATIC VAR(t_dds_m_slew, AUTOMATIC) tqadpcmp_06_rate_limit;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) tqadpcmp_04_hyst;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_06_rate_limiter_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facCorTqCkOilPmpLoss_MP; /* BIN10 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facCorTqCkStrtLoss_MP; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_pBoostDelta_MP; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tEngLossSel; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkEngLossRaw_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkFricLoss; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkOilPmpLoss; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkOilPmpLoss_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkPmpLoss; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkPmpLossAirLd_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkPmpLossOfs_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkPmpLossPAir_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkStrtLoss; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tqCkStrtLoss_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiStrtTqLoss_MP; /* DEC2 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_FACCORTQCKOILPMPLOSS_T_APM = {
&tqsys_faccortqckoilpmploss_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorTqCkOilPmpLoss_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorTqCkOilPmpLoss_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_FACCORTQCKSTRTLOSS_T_APM = {
&tqsys_faccortqckstrtloss_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorTqCkStrtLoss_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorTqCkStrtLoss_T[0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) TQSYS_TQCKFRICLOSS_M_APM = {
&tqsys_tqckfricloss_m_sav,
TQADPCMP_16_SIZE,
TQADPCMP_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkFricLossX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkFricLossY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkFricLoss_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) TQSYS_TQCKOILPMPLOSS_M_APM = {
&tqsys_tqckoilpmploss_m_sav,
TQADPCMP_8_SIZE,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkOilPmpLossX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkOilPmpLossY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkOilPmpLoss_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQCKPMPLOSSAIRLD_M_APM = {
&tqsys_tqckpmplossairld_m_sav,
TQADPCMP_16_SIZE,
TQADPCMP_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossAirLdY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossAirLd_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQSYS_TQCKPMPLOSSOFS_T_APM = {
&tqsys_tqckpmplossofs_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossOfs_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossOfs_T[0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) TQSYS_TQCKPMPLOSSPAIR_M_APM = {
&tqsys_tqckpmplosspair_m_sav,
TQADPCMP_16_SIZE,
TQADPCMP_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossPAirY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkPmpLossPAir_M[0][0]
};

STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) TQSYS_TQCKSTRTLOSS_M_APM = {
&tqsys_tqckstrtloss_m_sav,
TQADPCMP_8_SIZE,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkStrtLossX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkStrtLossY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkStrtLoss_M[0][0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Calc_Friction_Losses_Torque(UInt16 eng_nckfil_par, /* BIN2 */
                                                                     SInt16 ext_toilmes_par, /* DEC1 */
                                                                     SInt16 ext_tcomes_par, /* BIN0 */
                                                                     UInt8 frm_bacvtqenglossdftt_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calc_Pumping_Losses_Torque(UInt16 eng_nckfil_par, /* BIN2 */
                                                                    UInt16 engm_rairldcor_par, /* BIN14 */
                                                                    UInt16 exm_pexmnfestim_par, /* NBIN3 */
                                                                    UInt16 ext_pairextmes_par, /* BIN0 */
                                                                    SInt16 ext_pdsthrmes_par, /* BIN0 */
                                                                    SInt16 exm_pustrbestimtqsys_par, /* BIN0 */
                                                                    UInt8 tqsys_btypfu_par,
                                                                    UInt8 frm_bacvtqenglossdftpds_par,
                                                                    UInt16 inm_pdsthrcor_par, /* NBIN3 */
                                                                    UInt8 frm_bacvtqenglossdftpmp_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Calc_Start_Losses_Torque(UInt16 ext_neng_par, /* BIN0 */
                                                                  UInt32 eom_tiengstop_par /* DEC0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Calc_Oil_Pump_Losses_Torque(UInt16 eng_nckfil_par, /* BIN2 */
                                                                     SInt16 ext_toilmes_par, /* DEC1 */
                                                                     UInt16 ext_poilmes_par, /* BIN7 */
                                                                     UInt8 frm_bacvtqenglossdftoil_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_06_Calc_Engine_Losses_Torque(UInt16 tqsys_tqckpumphiploss_par, /* BIN4 */
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengloss_ptr /* BIN4 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Coord_Lost_Motor
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Coord_Lost_Motor(UInt32 EOM_tiEngStop_swc_in, /* DEC0 */
                                           UInt16 EngM_rAirLdCor_swc_in, /* BIN14 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt16 ExM_pExMnfEstim_swc_in, /* NBIN3 */
                                           SInt16 ExM_pUsTrbEstimTqSys_swc_in, /* BIN0 */
                                           UInt16 Ext_pAirExtMes_swc_in, /* BIN0 */
                                           SInt16 Ext_pDsThrMes_swc_in, /* BIN0 */
                                           UInt16 Ext_pOilMes_swc_in, /* BIN7 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tOilMes_swc_in, /* DEC1 */
                                           UInt8 FRM_bAcvTqEngLossDftOil_swc_in,
                                           UInt8 FRM_bAcvTqEngLossDftPDs_swc_in,
                                           UInt8 FRM_bAcvTqEngLossDftPmp_swc_in,
                                           UInt8 FRM_bAcvTqEngLossDftT_swc_in,
                                           UInt16 InM_pDsThrCor_swc_in, /* NBIN3 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_tqCkPumpHiPLoss_swc_in, /* BIN4 */
                                           UInt16 Ext_nEng_swc_in, /*BIN0*/
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLoss_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2099.FR.1.4 */

    TQADPCMP_02_Calc_Friction_Losses_Torque(Eng_nCkFil_swc_in, /* BIN2 */
                                            Ext_tOilMes_swc_in, /* DEC1 */
                                            Ext_tCoMes_swc_in, /* BIN0 */
                                            FRM_bAcvTqEngLossDftT_swc_in);

    TQADPCMP_03_Calc_Pumping_Losses_Torque(Eng_nCkFil_swc_in, /* BIN2 */
                                           EngM_rAirLdCor_swc_in, /* BIN14 */
                                           ExM_pExMnfEstim_swc_in, /* NBIN3 */
                                           Ext_pAirExtMes_swc_in, /* BIN0 */
                                           Ext_pDsThrMes_swc_in, /* BIN0 */
                                           ExM_pUsTrbEstimTqSys_swc_in, /* BIN0 */
                                           TqSys_bTypFu_swc_in,
                                           FRM_bAcvTqEngLossDftPDs_swc_in,
                                           InM_pDsThrCor_swc_in, /* NBIN3 */
                                           FRM_bAcvTqEngLossDftPmp_swc_in);

    TQADPCMP_04_Calc_Start_Losses_Torque(Ext_nEng_swc_in, /* BIN0 */
                                         EOM_tiEngStop_swc_in /* DEC0 */);

    TQADPCMP_05_Calc_Oil_Pump_Losses_Torque(Eng_nCkFil_swc_in, /* BIN2 */
                                            Ext_tOilMes_swc_in, /* DEC1 */
                                            Ext_pOilMes_swc_in, /* BIN7 */
                                            FRM_bAcvTqEngLossDftOil_swc_in);

    TQADPCMP_06_Calc_Engine_Losses_Torque(TqSys_tqCkPumpHiPLoss_swc_in, /* BIN4 */
                                          TqSys_tqCkEngLoss_swc_out /* BIN4 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_02_Calc_Friction_Losses_Torque
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Calc_Friction_Losses_Torque(UInt16 eng_nckfil_par, /* BIN2 */
                                                                     SInt16 ext_toilmes_par, /* DEC1 */
                                                                     SInt16 ext_tcomes_par, /* BIN0 */
                                                                     UInt8 frm_bacvtqenglossdftt_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2104.FR.2.3 */
    SInt32 tqadpcmp_svalue;

    if((UInt32)frm_bacvtqenglossdftt_par!=(UInt32)DDS_FALSE)
    {
        TqSys_tEngLossSel = (SInt16)((SInt32)TqSys_tEngFricLossDft_C * BIN4);
    }
    else
    {
        tqadpcmp_svalue = (SInt32)DDS_M_BARY_FILTER_S16((SInt16)((SInt32)ext_toilmes_par/DEC1),ext_tcomes_par,(SInt16)TqSys_facTCkEngLoss_C,BIN7);
        TqSys_tEngLossSel = (SInt16)(DDS_M_LIMIT(tqadpcmp_svalue,-50,200) * BIN4);
    }

    TqSys_tqCkFricLoss = DDS_M_MAP3D_USU16(&TQSYS_TQCKFRICLOSS_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),
    											(SInt16)((SInt32)TqSys_tEngLossSel / BIN4));
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Calc_Pumping_Losses_Torque
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calc_Pumping_Losses_Torque(UInt16 eng_nckfil_par, /* BIN2 */
                                                                    UInt16 engm_rairldcor_par, /* BIN14 */
                                                                    UInt16 exm_pexmnfestim_par, /* NBIN3 */
                                                                    UInt16 ext_pairextmes_par, /* BIN0 */
                                                                    SInt16 ext_pdsthrmes_par, /* BIN0 */
                                                                    SInt16 exm_pustrbestimtqsys_par, /* BIN0 */
                                                                    UInt8 tqsys_btypfu_par,
                                                                    UInt8 frm_bacvtqenglossdftpds_par,
                                                                    UInt16 inm_pdsthrcor_par, /* NBIN3 */
                                                                    UInt8 frm_bacvtqenglossdftpmp_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2099.FR.3.3 */

    SInt32 tqadpcmp_03_somme_p;
    SInt32 tqadpcmp_03_somme_n;

    TqSys_tqCkPmpLossOfs_MP = DDS_M_MAP2D_US16(&TQSYS_TQCKPMPLOSSOFS_T_APM,ext_pairextmes_par);

    if((UInt32)TqSys_idxPmpLoss_C!=(UInt32)1)
    {
        if((UInt32)frm_bacvtqenglossdftpmp_par!=(UInt32)DDS_FALSE)
        {
            TqSys_tqCkPmpLossPAir_MP = DDS_M_MAP3D_USS16(&TQSYS_TQCKPMPLOSSPAIR_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),TqSys_pDeltaPmpLossDft_C);
        }
        else
        {
            if((UInt32)frm_bacvtqenglossdftpds_par!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_03_somme_p = ((SInt32)inm_pdsthrcor_par * BIN3) / (SInt32)100;
            }
            else
            {
                tqadpcmp_03_somme_p = (SInt32)ext_pdsthrmes_par;
            }


            if((UInt32)TqSys_idxPEx_C!=(UInt32)1)
            {
                if((UInt32)tqsys_btypfu_par!=(UInt32)DDS_FALSE)
                {
                    tqadpcmp_03_somme_n = ((SInt32)exm_pexmnfestim_par * BIN3) / (SInt32)100;
                }
                else
                {
                    tqadpcmp_03_somme_n = (SInt32)exm_pustrbestimtqsys_par;
                }
            }
            else
            {
                tqadpcmp_03_somme_n = (SInt32)0;
            }

            TqSys_pBoostDelta_MP = (SInt16)(((tqadpcmp_03_somme_p - tqadpcmp_03_somme_n)*BIN10)/1000);

            TqSys_tqCkPmpLossPAir_MP = DDS_M_MAP3D_USS16(&TQSYS_TQCKPMPLOSSPAIR_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),
            												TqSys_pBoostDelta_MP);
        }

        TqSys_tqCkPmpLoss = (SInt16)DDS_M_LIMIT(((SInt32)TqSys_tqCkPmpLossPAir_MP+(SInt32)TqSys_tqCkPmpLossOfs_MP),
        												(SInt32)(-100*BIN4),(SInt32)(500*BIN4));
    }
    else
    {
        TqSys_tqCkPmpLossAirLd_MP = DDS_M_MAP3D_UUS16(&TQSYS_TQCKPMPLOSSAIRLD_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),
        												engm_rairldcor_par);
        TqSys_tqCkPmpLoss = (SInt16)DDS_M_LIMIT(((SInt32)TqSys_tqCkPmpLossAirLd_MP+(SInt32)TqSys_tqCkPmpLossOfs_MP),
        											(SInt32)(-100*BIN4),(SInt32)(500*BIN4));
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Calc_Start_Losses_Torque
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Calc_Start_Losses_Torque(UInt16 ext_neng_par, /* BIN0 */
                                                                  UInt32 eom_tiengstop_par /* DEC0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2099.FR.4.3.B2 */
	UInt8 tqadpcmp_hyst_out;
	UInt16 tqadpcmp_04_eom_tiengstop_limit;

	tqadpcmp_04_eom_tiengstop_limit = (UInt16)DDS_M_MIN(DDS_UINT16_MAX,eom_tiengstop_par);

	tqadpcmp_hyst_out = DDS_M_HYST_PH_U32(&tqadpcmp_04_hyst,
	                                      (UInt32)ext_neng_par,
	                                      (UInt32)TqSys_nStrtTqLoss_C ,
                                          (UInt32)TqSys_nStopTqLoss_C);


	 if ( (UInt32)tqadpcmp_hyst_out == (UInt32)DDS_FALSE )
	{
		TqSys_tiStrtTqLoss_MP = 0 * DEC2 ;
	}
	else
	{
		TqSys_tiStrtTqLoss_MP = (UInt16)DDS_M_LIMITED_INCREMENT((UInt32)TqSys_tiStrtTqLoss_MP,
														TQADPCMP_INCREMENT_COUNTER,  /* prev + 0.01 * DEC2*/
														TQADPCMP_04_CNT_MAX);            /* 655 * DEC2        */
	}

	TqSys_facCorTqCkStrtLoss_MP = DDS_M_MAP2D_U16(&TQSYS_FACCORTQCKSTRTLOSS_T_APM,tqadpcmp_04_eom_tiengstop_limit);

    TqSys_tqCkStrtLoss_MP = DDS_M_MAP3D_USU16(&TQSYS_TQCKSTRTLOSS_M_APM,
    											(UInt16)((UInt32)TqSys_tiStrtTqLoss_MP / DEC1),
    											(SInt16)((SInt32)TqSys_tEngLossSel / BIN4));

    TqSys_tqCkStrtLoss = (UInt16)((((UInt32)TqSys_facCorTqCkStrtLoss_MP)*((UInt32)TqSys_tqCkStrtLoss_MP))/BIN10);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_Calc_Oil_Pump_Losses_Torque
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Calc_Oil_Pump_Losses_Torque(UInt16 eng_nckfil_par, /* BIN2 */
                                                                     SInt16 ext_toilmes_par, /* DEC1 */
                                                                     UInt16 ext_poilmes_par, /* BIN7 */
                                                                     UInt8 frm_bacvtqenglossdftoil_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2099.FR.5.0 */

    TqSys_facCorTqCkOilPmpLoss_MP = DDS_M_MAP2D_U16(&TQSYS_FACCORTQCKOILPMPLOSS_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));

    if((UInt32)frm_bacvtqenglossdftoil_par!=(UInt32)DDS_FALSE)
    {
        TqSys_tqCkOilPmpLoss_MP = DDS_M_MAP3D_USU16(&TQSYS_TQCKOILPMPLOSS_M_APM,TqSys_pOilEngLossDft_C,TqSys_tOilEngLossDft_C);
    }
    else
    {
        TqSys_tqCkOilPmpLoss_MP = DDS_M_MAP3D_USU16(&TQSYS_TQCKOILPMPLOSS_M_APM,ext_poilmes_par,(SInt16)((SInt32)ext_toilmes_par/DEC1));
    }

    TqSys_tqCkOilPmpLoss = (UInt16)(((UInt32)TqSys_facCorTqCkOilPmpLoss_MP*(UInt32)TqSys_tqCkOilPmpLoss_MP)/BIN10);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_06_Calc_Engine_Losses_Torque
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) TQADPCMP_06_Calc_Engine_Losses_Torque(UInt16 tqsys_tqckpumphiploss_par, /* BIN4 */
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengloss_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2099.FR.6.0 */
    SInt32 tqadpcmp_06_somme;
    UInt32 tqadpcmp_temp;

    tqadpcmp_06_somme = (SInt32)TqSys_tqCkFricLoss +
                        (SInt32)TqSys_tqCkPmpLoss +
                        (SInt32)TqSys_tqCkStrtLoss +
                        (SInt32)TqSys_tqCkOilPmpLoss +
                        (SInt32)tqsys_tqckpumphiploss_par;

    TqSys_tqCkEngLossRaw_MP = (UInt16)DDS_M_LIMIT(tqadpcmp_06_somme,0*BIN4,500*BIN4);

    if((UInt32)tqadpcmp_06_rate_limiter_init==(UInt32)DDS_FALSE)
    {
        tqadpcmp_06_rate_limiter_init = DDS_TRUE;
        /* BIN4 * DEC3 */
        tqadpcmp_temp  = DDS_M_SLEW_U32_INIT(&tqadpcmp_06_rate_limit, (UInt32)TqSys_tqCkEngLossRaw_MP * DEC3);
        /* BIN4 = BIN4 * DEC3 / DEC3 */
        *tqsys_tqckengloss_ptr = (UInt16)(tqadpcmp_temp / DEC3);
    }
    else
    {
        /* BIN4 * DEC3 */
        tqadpcmp_temp = DDS_M_SLEW_U32(&tqadpcmp_06_rate_limit,
                                      (UInt32)TqSys_tqCkEngLossRaw_MP * DEC3,/* BIN4 * DEC3 */
                                      (UInt32)(((SInt32)TqSys_tqCkEngLossIncMax_C*(SInt32)BIN3) * (SInt32)(0.01 * DEC3)),/* BIN1 * BIN3 * DEC3 */
                                      (UInt32)(((-(SInt32)TqSys_tqCkEngLossDecMax_C)*(SInt32)BIN3) * (SInt32)(0.01 * DEC3)));/* BIN1 * BIN3 * DEC3 */
        /* BIN4 = BIN4 * DEC3 / DEC3 */
        *tqsys_tqckengloss_ptr = (UInt16)(tqadpcmp_temp / DEC3);
    }
}




/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Coord_Lost_Motor_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Coord_Lost_Motor_Init( CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLoss_swc_out /* BIN4 */)
{
    *TqSys_tqCkEngLoss_swc_out = (UInt16) (0 * BIN4);
    tqadpcmp_06_rate_limiter_init = DDS_FALSE;

    DDS_M_HYST_U32_INIT(&tqadpcmp_04_hyst,0);
	TqSys_tiStrtTqLoss_MP = 0 * DEC2 ;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

