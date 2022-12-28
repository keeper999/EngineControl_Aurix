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
* Ref X:\integration_view_00PSASWC_EB20D11\blois_psa_sstg\Software\Appli\CurDrivFil\src\CURDRIVFIL_Accel_State.c
* Version int :/main/L02_01/1 Date: 19/11/2012 12 h 19 m User:posmyk 
*    TWK_model:CURDRIVFIL_Accel_State_L02_010_IMPL2
*    comments :curdrivfil 12.0 . CSCT_CSMT09_2433 10.0. UT corrections
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\5 Date: 16/11/2012 12 h 22 m User:halouane 
*    TWK_model:CURDRIVFIL_Accel_State_L02_010_IMPL2
*    comments :curdrivfil 12.0 
*    comments :CSCT_CSMT09_2433 10.0
*    comments :UT corrections
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\4 Date: 16/11/2012 11 h 59 m User:halouane
*    TWK_model:CURDRIVFIL_Accel_State_L02_010_IMPL2
*    comments :curdrivfil 12.0
*    comments :CSCT_CSMT09_2433 10.0
*    comments :UT corrections
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\3 Date: 26/10/2012 16 h 12 m User:halouane
*    TWK_model:CURDRIVFIL_Accel_State_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\2 Date: 26/10/2012 11 h 3 m User:halouane
*    TWK_model:CURDRIVFIL_Accel_State_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\1 Date: 26/10/2012 10 h 16 m User:halouane
*    TWK_model:CURDRIVFIL_Accel_State_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
* Version int :/main/L01_01/2 Date: 18/5/2011 17 h 27 m User:esnault
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL3_D
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 11/5/2011 15 h 6 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL3_D
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 20/4/2011 16 h 12 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL3_D
*    comments :To reduce CPU load
* Version int :/main/L01_01/1 Date: 27/8/2010 10 h 47 m User:meme
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL3
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\8 Date: 26/8/2010 15 h 21 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL3
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_demezil_curdrivfil_dev\1 Date: 17/8/2010 16 h 52 m User:demezil
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL2
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\7 Date: 22/7/2010 16 h 2 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\6 Date: 21/7/2010 11 h 47 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\5 Date: 21/7/2010 11 h 14 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\4 Date: 19/7/2010 16 h 41 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 7/7/2010 11 h 48 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 2/7/2010 11 h 9 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 29/6/2010 8 h 53 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 29/6/2010 8 h 49 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 25/6/2010 17 h 5 m User:veillard
*    TWK_model:CURDRIVFIL_Accel_State_L01_010_IMPL1
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

#define CURDRIVFIL_RPM_PER_SEC_MIN	(SInt32)(-8000 * BIN2)
#define CURDRIVFIL_0_RPM_PER_SEC	(SInt32)(0 * BIN2)
#define CURDRIVFIL_RPM_PER_SEC_MAX	(SInt32)(8000 * BIN2)

#define CURDRIVFIL_TQSYS_MAX	(UInt32)(10 * DEC2)
#define CURDRIVFIL_TQCLRCROS_EFFECTIF_CST	(UInt32)(2 * BIN0)

#define  TQSYS_5_SIZE  5


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

/* 16-bits calibrations definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) TqSys_idxGain_A[TQSYS_6_SIZE]; 		/* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_AOSGain_A[TQSYS_12_SIZE];	/* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_AOS_A[TQSYS_9_SIZE];		/* BIN0 */
extern volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDeceIni_AOS_A[CURDRIVFIL_5_SIZE];		/* BIN4 */
extern volatile CONST(SInt16, AUTOMATIC) TqSys_tqLimEM_AOS_A[CURDRIVFIL_5_SIZE];      /* BIN4 */
#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
extern CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_NENG_AOSGAIN_T_APM;
#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
extern volatile CONST(UInt8, AUTOMATIC) TqSys_bDisNEngEna_C;
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt1Acce_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt1Max_C = (CONST(UInt16, AUTOMATIC))(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt3Dece_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaAcceCur_C  = (CONST(SInt16, AUTOMATIC))(2 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaDeceCur_C  = (CONST(SInt16, AUTOMATIC))(2 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdDeltaAcceCur_C  = (CONST(SInt16, AUTOMATIC))(20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdDeltaDeceCur_C  = (CONST(SInt16, AUTOMATIC))(20 * BIN4);


#define CURDRIVFIL_STOP_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bNSel_ChgStDece_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facNGrdFilChgStDece_C = (CONST(UInt8, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bCorSel_ChgStDece_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bSelStCur_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDetClrCrossAcvCur_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facSelPha3_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_nEngGrdAOS_A[TQSYS_12_SIZE] = {
(SInt16)(800 * BIN2), (SInt16)(1000 * BIN2), (SInt16)(1200 * BIN2),
(SInt16)(1600 * BIN2), (SInt16)(2000 * BIN2), (SInt16)(2400 * BIN2),
(SInt16)(2800 * BIN2), (SInt16)(3200 * BIN2), (SInt16)(3600 * BIN2),
(SInt16)(4000 * BIN2), (SInt16)(4400 * BIN2), (SInt16)(4800 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_nEngGrdAOS_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) },
{
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(0 * BIN2), (SInt16)(0 * BIN2) }
};


STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear0_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear1_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear2_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear3_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear4_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear5_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear6_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear7_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf3_noGear8_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0.2196350 * BIN10), (SInt16)(0.1876660 * BIN10),
(SInt16)(0.1572810 * BIN10), (SInt16)(0.1114650 * BIN10),
(SInt16)(0.08180790 * BIN10), (SInt16)(0.06220790 * BIN10),
(SInt16)(0.04875330 * BIN10), (SInt16)(0.03917530 * BIN10),
(SInt16)(0.03213730 * BIN10), (SInt16)(0.02682380 * BIN10),
(SInt16)(0.02271880 * BIN10), (SInt16)(0.02712590 * BIN10) },
{
(SInt16)(-0.09551520 * BIN10), (SInt16)(-0.07648550 * BIN10),
(SInt16)(-0.06167550 * BIN10), (SInt16)(-0.04181840 * BIN10),
(SInt16)(-0.02993750 * BIN10), (SInt16)(-0.02240190 * BIN10),
(SInt16)(-0.01735970 * BIN10), (SInt16)(-0.01383290 * BIN10),
(SInt16)(-0.01127460 * BIN10), (SInt16)(-0.009362150 * BIN10),
(SInt16)(-0.007896130 * BIN10), (SInt16)(-0.009415560 * BIN10) },
{
(SInt16)(-1.7294300 * BIN10), (SInt16)(-1.7864101 * BIN10),
(SInt16)(-1.8229599 * BIN10), (SInt16)(-1.8676901 * BIN10),
(SInt16)(-1.8942301 * BIN10), (SInt16)(-1.9118500 * BIN10),
(SInt16)(-1.9244200 * BIN10), (SInt16)(-1.9338501 * BIN10),
(SInt16)(-1.9411799 * BIN10), (SInt16)(-1.9470499 * BIN10),
(SInt16)(-1.9518501 * BIN10), (SInt16)(-1.9561700 * BIN10) },
{
(SInt16)(0.7558780001 * BIN10), (SInt16)(0.803271 * BIN10),
(SInt16)(0.8347180 * BIN10), (SInt16)(0.8743690 * BIN10),
(SInt16)(0.8985350 * BIN10), (SInt16)(0.9148620 * BIN10),
(SInt16)(0.9266460 * BIN10), (SInt16)(0.9355570 * BIN10),
(SInt16)(0.9425340 * BIN10), (SInt16)(0.9481460 * BIN10),
(SInt16)(0.9527580 * BIN10), (SInt16)(0.956953000 * BIN10) },
{
(SInt16)(-0.2526140 * BIN10), (SInt16)(-0.4733720 * BIN10),
(SInt16)(-0.6530910 * BIN10), (SInt16)(-0.9168260 * BIN10),
(SInt16)(-1.0971000 * BIN10), (SInt16)(-1.2269001 * BIN10),
(SInt16)(-1.3244700 * BIN10), (SInt16)(-1.4003600 * BIN10),
(SInt16)(-1.4610301 * BIN10), (SInt16)(-1.5105999 * BIN10),
(SInt16)(-1.5518600 * BIN10), (SInt16)(-1.5759399 * BIN10) },
{
(SInt16)(-0.07897040 * BIN10), (SInt16)(0.0302124 * BIN10),
(SInt16)(0.1131680 * BIN10), (SInt16)(0.2381520 * BIN10),
(SInt16)(0.3312730 * BIN10), (SInt16)(0.4042570 * BIN10),
(SInt16)(0.4631200 * BIN10), (SInt16)(0.5115840 * BIN10),
(SInt16)(0.5521550 * BIN10), (SInt16)(0.5865910 * BIN10),
(SInt16)(0.6161720001 * BIN10), (SInt16)(0.6340380 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqGrdAOS_T
[TQSYS_5_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt1MinTq_T
[TQSYS_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt3Tq_T
[TQSYS_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt3Ofs_T
[TQSYS_9_SIZE] = {
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt1Min_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSt3NGear_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) },
{
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaDeceCur_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsClrCross_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaAcceCur_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) },
{
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4) }
};


STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaAcceCur_T
[TQSYS_5_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaDeceCur_T
[TQSYS_5_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) curdrivfil_f01_01_01_is_filter_init;
STATIC VAR(UInt8, AUTOMATIC) tqsys_stacceaos_cpy;
#define CURDRIVFIL_STOP_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"


/* 16-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_nchgstdece_prev; /* BIN2 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckefcfiltrv_prev; /* BIN4 */
#define CURDRIVFIL_STOP_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 32-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_32BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqsys_tist1_dec3;	/* DEC3 */
STATIC VAR(UInt32, AUTOMATIC) tqsys_tist3_dec3;	/* DEC3 */
#define CURDRIVFIL_STOP_SEC_VAR_32BIT
#include "CurDrivFil_MemMap.h"

/* Complex variable definition */
#define CURDRIVFIL_START_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_nenggrdaos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tist1min_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tist3ngear_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltadececur_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltaaccecur_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqofsclrcross_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear0_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear1_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear2_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear3_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear4_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear5_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear6_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear7_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf3_nogear8_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) curdrivfil_f01_01_01_dlowpassfilter_type_k;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqgrdaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tist1mintq_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tist3tq_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tist3ofs_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqdeltaaccecur_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqdeltadececur_t_sav;
#define CURDRIVFIL_STOP_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_AOSGrd_MP; /* BIN2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nChgStDece; /* BIN2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nGrdChgStDece_MP; /* BIN2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nGrdChgStDeceFil; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt1; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt1Acce; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt1Max; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt1Min; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt3; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt3Dece; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt3Max; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiSt3Min; /* DEC2 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bNGrdFil; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceDetCord; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceClrCrossCord; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceDetCord; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceDetCur; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceDetCur; /* BIN0 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_NENGGRDAOS_M_APM = {
&tqsys_nenggrdaos_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_M[0][0]
};


STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR0_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear0_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear0_M[0][0]},
	{&tqsys_prm_aoscf3_nogear0_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear0_M[0][0]},
	{&tqsys_prm_aoscf3_nogear0_m_sav[2],
		TQSYS_12_SIZE,
		TQSYS_6_SIZE,
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear0_M[0][0]},
	{&tqsys_prm_aoscf3_nogear0_m_sav[3],
		TQSYS_12_SIZE,
		TQSYS_6_SIZE,
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear0_M[0][0]},
	{&tqsys_prm_aoscf3_nogear0_m_sav[4],
		TQSYS_12_SIZE,
		TQSYS_6_SIZE,
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear0_M[0][0]},
	{&tqsys_prm_aoscf3_nogear0_m_sav[5],
		TQSYS_12_SIZE,
		TQSYS_6_SIZE,
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
		(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear0_M[0][0]}
};



STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR1_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear1_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear1_M[0][0]},
	{&tqsys_prm_aoscf3_nogear1_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear1_M[0][0]},
	{&tqsys_prm_aoscf3_nogear1_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear1_M[0][0]},
	{&tqsys_prm_aoscf3_nogear1_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear1_M[0][0]},
	{&tqsys_prm_aoscf3_nogear1_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear1_M[0][0]},
	{&tqsys_prm_aoscf3_nogear1_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear1_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR2_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear2_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear2_M[0][0]},
	{&tqsys_prm_aoscf3_nogear2_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear2_M[0][0]},
	{&tqsys_prm_aoscf3_nogear2_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear2_M[0][0]},
	{&tqsys_prm_aoscf3_nogear2_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear2_M[0][0]},
	{&tqsys_prm_aoscf3_nogear2_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear2_M[0][0]},
	{&tqsys_prm_aoscf3_nogear2_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear2_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR3_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear3_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear3_M[0][0]},
	{&tqsys_prm_aoscf3_nogear3_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear3_M[0][0]},
	{&tqsys_prm_aoscf3_nogear3_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear3_M[0][0]},
	{&tqsys_prm_aoscf3_nogear3_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear3_M[0][0]},
	{&tqsys_prm_aoscf3_nogear3_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear3_M[0][0]},
	{&tqsys_prm_aoscf3_nogear3_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear3_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR4_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear4_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear4_M[0][0]},
	{&tqsys_prm_aoscf3_nogear4_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear4_M[0][0]},
	{&tqsys_prm_aoscf3_nogear4_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear4_M[0][0]},
	{&tqsys_prm_aoscf3_nogear4_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear4_M[0][0]},
	{&tqsys_prm_aoscf3_nogear4_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear4_M[0][0]},
	{&tqsys_prm_aoscf3_nogear4_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear4_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR5_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear5_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear5_M[0][0]},
	{&tqsys_prm_aoscf3_nogear5_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear5_M[0][0]},
	{&tqsys_prm_aoscf3_nogear5_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear5_M[0][0]},
	{&tqsys_prm_aoscf3_nogear5_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear5_M[0][0]},
	{&tqsys_prm_aoscf3_nogear5_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear5_M[0][0]},
	{&tqsys_prm_aoscf3_nogear5_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear5_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR6_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear6_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear6_M[0][0]},
	{&tqsys_prm_aoscf3_nogear6_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear6_M[0][0]},
	{&tqsys_prm_aoscf3_nogear6_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear6_M[0][0]},
	{&tqsys_prm_aoscf3_nogear6_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear6_M[0][0]},
	{&tqsys_prm_aoscf3_nogear6_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear6_M[0][0]},
	{&tqsys_prm_aoscf3_nogear6_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear6_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR7_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear7_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear7_M[0][0]},
	{&tqsys_prm_aoscf3_nogear7_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear7_M[0][0]},
	{&tqsys_prm_aoscf3_nogear7_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear7_M[0][0]},
	{&tqsys_prm_aoscf3_nogear7_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear7_M[0][0]},
	{&tqsys_prm_aoscf3_nogear7_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear7_M[0][0]},
	{&tqsys_prm_aoscf3_nogear7_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear7_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF3_NOGEAR8_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
	{&tqsys_prm_aoscf3_nogear8_m_sav[0],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear8_M[0][0]},
	{&tqsys_prm_aoscf3_nogear8_m_sav[1],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear8_M[0][0]},
	{&tqsys_prm_aoscf3_nogear8_m_sav[2],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear8_M[0][0]},
	{&tqsys_prm_aoscf3_nogear8_m_sav[3],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear8_M[0][0]},
	{&tqsys_prm_aoscf3_nogear8_m_sav[4],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear8_M[0][0]},
	{&tqsys_prm_aoscf3_nogear8_m_sav[5],
	TQSYS_12_SIZE,
	TQSYS_6_SIZE,
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
	(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
	(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf3_noGear8_M[0][0]}
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQGRDAOS_T_APM = {
&tqsys_tqgrdaos_t_sav,
TQSYS_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqGrdAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_su16, AUTOMATIC) TQSYS_TIST1MINTQ_T_APM = {
&tqsys_tist1mintq_t_sav,
TQSYS_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkDeceIni_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiSt1MinTq_T[0]
};

STATIC CONST(t_dds_m_tab2d_su16, AUTOMATIC) TQSYS_TIST3TQ_T_APM = {
&tqsys_tist3tq_t_sav,
TQSYS_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiSt3Tq_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_TIST3OFS_T_APM = {
&tqsys_tist3ofs_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiSt3Ofs_T[0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_TIST1MIN_M_APM = {
&tqsys_tist1min_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiSt1Min_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_TIST3NGEAR_M_APM = {
&tqsys_tist3ngear_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiSt3NGear_M[0][0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_TQDELTADECECUR_M_APM = {
&tqsys_tqdeltadececur_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaDeceCur_M[0][0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_TQOFSCLRCROSS_M_APM = {
&tqsys_tqofsclrcross_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqOfsClrCross_M[0][0]
};


STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_TQDELTAACCECUR_M_APM = {
&tqsys_tqdeltaaccecur_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngGrdAOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaAcceCur_M[0][0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQDELTAACCECUR_T_APM = {
&tqsys_tqdeltaaccecur_t_sav,
TQSYS_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaAcceCur_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQDELTADECECUR_T_APM = {
&tqsys_tqdeltadececur_t_sav,
TQSYS_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkDeceIni_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaDeceCur_T[0]
};

#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_State_Calculation(UInt16 ext_nengclc0_par,
																 UInt8  tqsys_baccedetaos_par,
																 UInt8  tqsys_bacceclrcrossaos_par,
															 	 UInt8  tqsys_bdecedetaos_par,
																 UInt8  copt_nogearcorddrivfil_par,
																 SInt16 tqsys_nfil2aos_par,
																 UInt8  ext_titdc_par,
																 UInt8 tqclrcros_stdetclr_par,
																SInt16 tqlimem_tqlimemtrv_par,
																SInt16 tqsys_tqckaoscor_par,
																SInt16 tqsys_tqckdeceini_par,
																SInt16 tqsys_tqckefcfiltrv_par,
																SInt16 tqsys_tqthdpha3_par);


INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_02_Calc_Aos_Map_C3(UInt16 ext_nengclc0_par,
															   UInt8  copt_nogearcorddrivfil_par,
													CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_prm_aosconf3_ptr  );


INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_Grad_Calculation(UInt8 ext_titdc_par);


INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_State_Calc(UInt8 ext_titdc_par);




INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_05_Grad_Calc(UInt16 ext_nengclc0_par,
															SInt16 tqsys_nfil2aos_par,
															UInt8 copt_nogearcorddrivfil_par,
															SInt16 tqlimem_tqlimemtrv_par,
															SInt16 tqsys_tqckaoscor_par,
															UInt8 ext_titdc_par);


INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_03_State_detection(UInt8 tqsys_baccedetaos_par,
																UInt8 tqsys_bacceclrcrossaos_par,
																UInt8 tqsys_bdecedetaos_par,
																SInt16 tqsys_tqckefcfiltrv_par,
																SInt16 tqlimem_tqlimemtrv_par,
																UInt16 ext_nengclc0_par,
																UInt8 copt_nogearcorddrivfil_par,
																UInt8 tqclrcros_stdetclr_par,
																SInt16 tqsys_tqckdeceini_par,
																SInt16 tqsys_tqthdpha3_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_04_Time_Calc(UInt8  copt_nogearcorddrivfil_par,
														UInt16 ext_nengclc0_par,
														SInt16 tqlimem_tqlimemtrv_par,
														SInt16 tqsys_tqckdeceini_par )	;

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : CURDRIVFIL_Accel_State
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Accel_State(UInt8 CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 TqSys_bAcceClrCrossAOS_swc_in,
                                           UInt8 TqSys_bAcceDetAOS_swc_in,
                                           UInt8 TqSys_bDeceDetAOS_swc_in,
                                           SInt16 TqSys_nFil2AOS_swc_in, /* BIN2 */
                                           UInt8 TqClrCros_stDetClr_swc_in,  /* BIN0 */
                                           SInt16 TqLimEM_tqLimEMTrv_swc_in, /*BIN4*/
                                           SInt16 TqSys_tqCkAOSCor_swc_in, /*BIN4*/
                                           SInt16 TqSys_tqCkDeceIni_swc_in, /*BIN4*/
                                           SInt16 TqSys_tqCkEfcFilTrv_swc_in, /*BIN4*/
                                           SInt16 TqSys_tqThdPha3_swc_in, /*BIN4*/
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stAcceAOS_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_prm_AOSConf3_swc_out)
{
	/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.1.1 */

	CURDRIVFIL_F01_01_State_Calculation(Ext_nEngClc0_swc_in,
										TqSys_bAcceDetAOS_swc_in,
										TqSys_bAcceClrCrossAOS_swc_in,
										TqSys_bDeceDetAOS_swc_in,
										CoPt_noGearCordDrivFil_swc_in,
										TqSys_nFil2AOS_swc_in,
										Ext_tiTDC_swc_in,
									   	TqClrCros_stDetClr_swc_in,
									    TqLimEM_tqLimEMTrv_swc_in,
									    TqSys_tqCkAOSCor_swc_in,
									    TqSys_tqCkDeceIni_swc_in,
									    TqSys_tqCkEfcFilTrv_swc_in,
									    TqSys_tqThdPha3_swc_in);

	*TqSys_stAcceAOS_swc_out = tqsys_stacceaos_cpy;

	CURDRIVFIL_F01_02_Calc_Aos_Map_C3(Ext_nEngClc0_swc_in,
									  CoPt_noGearCordDrivFil_swc_in,
									  TqSys_prm_AOSConf3_swc_out);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_State_Calculation
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_State_Calculation(UInt16 ext_nengclc0_par,
																 UInt8  tqsys_baccedetaos_par,
																 UInt8  tqsys_bacceclrcrossaos_par,
															 	 UInt8  tqsys_bdecedetaos_par,
																 UInt8  copt_nogearcorddrivfil_par,
																 SInt16 tqsys_nfil2aos_par,
																 UInt8  ext_titdc_par,
																 UInt8 tqclrcros_stdetclr_par,
																SInt16 tqlimem_tqlimemtrv_par,
																SInt16 tqsys_tqckaoscor_par,
																SInt16 tqsys_tqckdeceini_par,
																SInt16 tqsys_tqckefcfiltrv_par,
																SInt16 tqsys_tqthdpha3_par)
{
	/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.2.4 */

	CURDRIVFIL_F01_01_05_Grad_Calc(
								ext_nengclc0_par,
								tqsys_nfil2aos_par,
								copt_nogearcorddrivfil_par,
								tqlimem_tqlimemtrv_par,
								tqsys_tqckaoscor_par,
								ext_titdc_par);

	CURDRIVFIL_F01_01_03_State_detection(
									tqsys_baccedetaos_par,
									tqsys_bacceclrcrossaos_par,
									tqsys_bdecedetaos_par,
									tqsys_tqckefcfiltrv_par,
									tqlimem_tqlimemtrv_par,
									ext_nengclc0_par,
									copt_nogearcorddrivfil_par,
									tqclrcros_stdetclr_par,
									tqsys_tqckdeceini_par,
									tqsys_tqthdpha3_par);

	CURDRIVFIL_F01_01_04_Time_Calc(
									copt_nogearcorddrivfil_par,
									ext_nengclc0_par,
									tqlimem_tqlimemtrv_par,
									tqsys_tqckdeceini_par );


	CURDRIVFIL_F01_01_02_State_Calc(   ext_titdc_par);

}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_02_Calc_Aos_Map_C3
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_02_Calc_Aos_Map_C3(UInt16 ext_nengclc0_par,
															   UInt8  copt_nogearcorddrivfil_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_prm_aosconf3_ptr)
{
	/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.3.2 */
	SInt32 f01_02_index_tab;
	SInt16 tqsys_prm_aosconf3_ptr_temp[CURDRIVFIL_NBRSAMPLING_SIZE];
	UInt16 curdrivil_out_swith_tmp ; /*BIN2*/

	if((UInt32)DDS_FALSE != (UInt32)TqSys_bDisNEngEna_C)
	{
		/*[0;8000]BIN2*/
		curdrivil_out_swith_tmp = ext_nengclc0_par;
	}
	else
	{
		/*[0;8000]BIN2*/
		curdrivil_out_swith_tmp = DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_NENG_AOSGAIN_T_APM , ext_nengclc0_par);
	}

	switch((UInt32)copt_nogearcorddrivfil_par)
	{
	case CURDRIVFIL_RAPPORT_EQUIVALENT_0:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_1:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR1_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_2:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR2_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_3:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR3_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));

		}
		break;

	case CURDRIVFIL_RAPPORT_EQUIVALENT_4:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR4_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_5:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR5_M_APM[f01_02_index_tab],
																		      curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_6:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR6_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_7:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR7_M_APM[f01_02_index_tab],
																		      curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;


	case CURDRIVFIL_RAPPORT_EQUIVALENT_8:
		for(f01_02_index_tab = 0 ; f01_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f01_02_index_tab++)
		{
			tqsys_prm_aosconf3_ptr_temp[f01_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR8_M_APM[f01_02_index_tab],
																			  curdrivil_out_swith_tmp,
																			  (UInt16)(f01_02_index_tab + 1));
		}
		break;
	default:
		tqsys_prm_aosconf3_ptr_temp[0] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[0], curdrivil_out_swith_tmp , (UInt16)(1));
		tqsys_prm_aosconf3_ptr_temp[1] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[1], curdrivil_out_swith_tmp , (UInt16)(2));
		tqsys_prm_aosconf3_ptr_temp[2] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[2], curdrivil_out_swith_tmp , (UInt16)(3));
		tqsys_prm_aosconf3_ptr_temp[3] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[3], curdrivil_out_swith_tmp , (UInt16)(4));
		tqsys_prm_aosconf3_ptr_temp[4] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[4], curdrivil_out_swith_tmp , (UInt16)(5));
		tqsys_prm_aosconf3_ptr_temp[5] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF3_NOGEAR0_M_APM[5], curdrivil_out_swith_tmp , (UInt16)(6));
		break;
	}

	tqsys_prm_aosconf3_ptr[0] = tqsys_prm_aosconf3_ptr_temp[0];
	tqsys_prm_aosconf3_ptr[1] = tqsys_prm_aosconf3_ptr_temp[1];
	tqsys_prm_aosconf3_ptr[2] = tqsys_prm_aosconf3_ptr_temp[2];
	tqsys_prm_aosconf3_ptr[3] = tqsys_prm_aosconf3_ptr_temp[3];
	tqsys_prm_aosconf3_ptr[4] = tqsys_prm_aosconf3_ptr_temp[4];
	tqsys_prm_aosconf3_ptr[5] = tqsys_prm_aosconf3_ptr_temp[5];

}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_01_Grad_Calculation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_01_Grad_Calculation(UInt8 ext_titdc_par)

{
	/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.11.2 */

	SInt32 f01_01_01_numerator;
	SInt32 f01_01_01_result_div;

	/* [-16000;16000]BIN2 =     [-8000;8000]BIN2 - [-8000;8000]BIN2 */
	f01_01_01_numerator = (SInt32)TqSys_nChgStDece - (SInt32)tqsys_nchgstdece_prev;



	if((SInt32)0 == f01_01_01_numerator)
	{
		f01_01_01_result_div = CURDRIVFIL_0_RPM_PER_SEC;
	}
	else if((SInt32)0 == (SInt32)ext_titdc_par)
	{
		if(f01_01_01_numerator > 0)
		{
			f01_01_01_result_div = CURDRIVFIL_RPM_PER_SEC_MAX;
		}
		else
		{
			f01_01_01_result_div = CURDRIVFIL_RPM_PER_SEC_MIN;
		}
	}
	else
	{
		/* [-160000;160000]BIN2 = [-16000;16000]BIN2 * DEC3 / [0;0.1]DEC3 */
		f01_01_01_result_div = (f01_01_01_numerator * DEC3) / (SInt32)ext_titdc_par;

	}

	/* [-8000;8000]BIN2 */
	TqSys_nGrdChgStDece_MP = (SInt16)DDS_M_LIMIT(f01_01_01_result_div , CURDRIVFIL_RPM_PER_SEC_MIN , CURDRIVFIL_RPM_PER_SEC_MAX);


	if((UInt32)DDS_FALSE == (UInt32)curdrivfil_f01_01_01_is_filter_init)
	{
		TqSys_nGrdChgStDeceFil = DDS_M_FILTER_LP1_S16_INIT(&curdrivfil_f01_01_01_dlowpassfilter_type_k,
														   TqSys_nGrdChgStDece_MP);
		curdrivfil_f01_01_01_is_filter_init = DDS_TRUE;
	}

	else
	{
		/* [-8000;8000]BIN2 */
		TqSys_nGrdChgStDeceFil = DDS_M_FILTER_LP1_S16(&curdrivfil_f01_01_01_dlowpassfilter_type_k,
											   		  TqSys_nGrdChgStDece_MP,						/* [-8000;8000]BIN2 */
											          (UInt16)((UInt32)TqSys_facNGrdFilChgStDece_C * DEC1),
											          DEC3);
	}

	/* Store the result for the next calls */
	tqsys_nchgstdece_prev = TqSys_nChgStDece;

}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_02_State_Calc
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_02_State_Calc(UInt8 ext_titdc_par )
{
	/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.12.4 */

	switch((UInt32)tqsys_stacceaos_cpy)
	{
	case CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX:
		if((UInt32)DDS_TRUE	== (UInt32)TqSys_bAcceClrCrossCord)
		{
			tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX;
			tqsys_tist3_dec3 = 0 * DEC3;
		}
		else if ((UInt32)DDS_TRUE	== (UInt32)TqSys_bDeceDetCord)
		{
			tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_DECELERATION;
			tqsys_tist1_dec3 = 0 * DEC3;
		}
		else	/* during actions of this state */
		{
			/* NONE */
		}
		break;

	case CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX:
		if(	(((UInt32)TqSys_tiSt3 	>= 	(UInt32)TqSys_tiSt3Min) 		&&
			((UInt32)DDS_TRUE 		== 	(UInt32)TqSys_bNGrdFil)) 		||
			((UInt32)TqSys_tiSt3 	>= 	(UInt32)TqSys_tiSt3Max) )
		{
			tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX;
		}
		else if ( ((UInt32)DDS_TRUE 	== 	(UInt32)TqSys_bDeceDetCord) &&
				  ((UInt32)TqSys_tiSt3 	>= 	(UInt32)TqSys_tiSt3Dece) )
		{
			tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_DECELERATION;
			tqsys_tist1_dec3 = 0 * DEC3;
		}
		else	/* during actions of this state */
		{
			/* DEC3 = (DEC3 + DEC3) */
			tqsys_tist3_dec3 = DDS_M_LIMITED_INCREMENT( tqsys_tist3_dec3,
														(UInt32)ext_titdc_par,
														(UInt32)(10 * DEC3)	);
		}
		break;

	case CURDRIVFIL_DECELERATION:
	   if(
			(  (((UInt32)TqSys_bDeceDetCord == (UInt32)DDS_FALSE) && ((UInt32)TqSys_tiSt1 >= (UInt32)TqSys_tiSt1Min))	||
			   ((UInt32)TqSys_bAcceDetCord == (UInt32)DDS_TRUE)  														||
			   ((UInt32)TqSys_tiSt1 >= (UInt32)TqSys_tiSt1Max) ) 															&&
			   ((UInt32)TqSys_bAcceClrCrossCord == (UInt32)DDS_FALSE)
		 )
		{
			tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX;
		}
		else if ( ((UInt32)DDS_TRUE	== (UInt32)TqSys_bAcceClrCrossCord)	 &&
				  ((UInt32)TqSys_tiSt1 >= (UInt32)TqSys_tiSt1Acce) )
		{
			tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX;
			tqsys_tist3_dec3 = 0 * DEC3;
		}
		else	/* during actions of this state */
		{
			/* [0;10]DEC3 = [0;10]DEC3 + [0;0.1]DEC3 */
			tqsys_tist1_dec3 = DDS_M_LIMITED_INCREMENT( tqsys_tist1_dec3,
														(UInt32)ext_titdc_par,
														(UInt32)(10 * DEC3)	);
		}
		break;
	default:
		tqsys_stacceaos_cpy = (UInt8)CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX;
		break;
	}

	/* DEC2 = DEC3 / DEC1 */
	TqSys_tiSt1 = (UInt16)(tqsys_tist1_dec3 / DEC1);
	TqSys_tiSt3 = (UInt16)(tqsys_tist3_dec3 / DEC1);

}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_05_Grad_Calc
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_05_Grad_Calc(UInt16 ext_nengclc0_par,
															SInt16 tqsys_nfil2aos_par,
															UInt8 copt_nogearcorddrivfil_par,
															SInt16 tqlimem_tqlimemtrv_par,
															SInt16 tqsys_tqckaoscor_par,
															UInt8 ext_titdc_par)
{
		/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.13.1 */

	SInt32 curdrivfil_temp_s32;

	if((UInt32)DDS_TRUE == (UInt32)TqSys_bNSel_ChgStDece_C)
	{
		/* [0;8000]BIN2 */
		TqSys_nChgStDece = (SInt16)ext_nengclc0_par;
	}
	else
	{
		/* [-8000;8000]BIN2 */
		TqSys_nChgStDece = tqsys_nfil2aos_par;
	}

	CURDRIVFIL_F01_01_01_Grad_Calculation(ext_titdc_par);

	/* [-8000;8000]BIN2 */
	TqSys_AOSGrd_MP = DDS_M_MAP3D_SUS16(&TQSYS_NENGGRDAOS_M_APM, TqSys_nChgStDece, (UInt16)copt_nogearcorddrivfil_par);

	/* [-2000;2000]BIN4 */
    curdrivfil_temp_s32 = DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQGRDAOS_T_APM , tqlimem_tqlimemtrv_par);

   /* [-16000;16000]BIN6 = [-2000;2000]BIN4 * [-8000;8000]BIN2 */
	curdrivfil_temp_s32 = curdrivfil_temp_s32 * (SInt32)TqSys_AOSGrd_MP;


	if((UInt32)DDS_TRUE == (UInt32)TqSys_bCorSel_ChgStDece_C)
	{
		if(((SInt32)tqsys_tqckaoscor_par * BIN2) < curdrivfil_temp_s32)
		{
			TqSys_bNGrdFil = DDS_TRUE;
		}
		else
		{
			TqSys_bNGrdFil = DDS_FALSE;
		}
	}
	else
	{
		if(((SInt32)TqSys_nGrdChgStDeceFil * BIN4) < curdrivfil_temp_s32)
		{
			TqSys_bNGrdFil = DDS_TRUE;
		}
		else
		{
			TqSys_bNGrdFil = DDS_FALSE;
		}
	}

}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_03_State_detection
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_03_State_detection(UInt8 tqsys_baccedetaos_par,
																UInt8 tqsys_bacceclrcrossaos_par,
																UInt8 tqsys_bdecedetaos_par,
																SInt16 tqsys_tqckefcfiltrv_par,
																SInt16 tqlimem_tqlimemtrv_par,
																UInt16 ext_nengclc0_par,
																UInt8 copt_nogearcorddrivfil_par,
																UInt8 tqclrcros_stdetclr_par,
																SInt16 tqsys_tqckdeceini_par,
																SInt16 tqsys_tqthdpha3_par)
{
		/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.14.1 */

	SInt32 curdrivfil_temp_s32;

	/* To Update TqSys_bAcceDetCur */

	/*[-2000;2000]BIN4*/
	curdrivfil_temp_s32 = DDS_M_MAP3D_SUS16(&TQSYS_TQDELTAACCECUR_M_APM, (SInt16)ext_nengclc0_par, (UInt16)copt_nogearcorddrivfil_par);
	/*[-4000000;4000000]BIN8 = [-2000;2000]BIN4 * [-2000;2000]BIN4 */
	curdrivfil_temp_s32 = curdrivfil_temp_s32 * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQDELTAACCECUR_T_APM , tqlimem_tqlimemtrv_par);

	if((SInt32)tqsys_tqckefcfiltrv_par <= (SInt32)TqSys_tqThdDeltaAcceCur_C  )
	{
		/* [-4002000;4002000]BIN8= [-4000000;4000000]BIN8 + [-2000;2000]BIN4 */
		curdrivfil_temp_s32 = curdrivfil_temp_s32 + ((SInt32)TqSys_tqDeltaAcceCur_C * BIN4);
		/* [-4004000;4004000]BIN8= [-4002000;4002000]BIN8 + [-2000;2000]BIN4 */
		curdrivfil_temp_s32 = curdrivfil_temp_s32 + ((SInt32)tqsys_tqckefcfiltrv_prev * BIN4);

	}
	else
	{
		/* [-4002000;4002000]BIN8= [-4000000;4000000]BIN8 + [-2000;2000]BIN4 */
		curdrivfil_temp_s32 = curdrivfil_temp_s32 + ((SInt32)tqsys_tqckefcfiltrv_prev * BIN4);

	}

	if(((SInt32)tqsys_tqckefcfiltrv_par * BIN4) >= curdrivfil_temp_s32)
	{
		TqSys_bAcceDetCur = DDS_TRUE;
	}
	else
	{
		TqSys_bAcceDetCur = DDS_FALSE;
	}

	/* To Update TqSys_bDeceDetCur */

	/*[-2000;2000]BIN4*/
	curdrivfil_temp_s32 = DDS_M_MAP3D_SUS16(&TQSYS_TQDELTADECECUR_M_APM, (SInt16)ext_nengclc0_par, (UInt16)copt_nogearcorddrivfil_par);
	/*[-4000000;4000000]BIN8 = [-2000;2000]BIN4 * [-2000;2000]BIN4 */
	curdrivfil_temp_s32 = curdrivfil_temp_s32 * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQDELTADECECUR_T_APM , tqsys_tqckdeceini_par);

	if((SInt32)tqsys_tqckefcfiltrv_par <= (SInt32)TqSys_tqThdDeltaDeceCur_C  )
	{
		/* [-4002000;4002000]BIN8= [-4000000;4000000]BIN8 + [-2000;2000]BIN4 */
		curdrivfil_temp_s32 = curdrivfil_temp_s32 + ((SInt32)TqSys_tqDeltaDeceCur_C * BIN4);
		/* [-4004000;4004000]BIN8=  [-2000;2000]BIN4] - [-4002000;4002000]BIN8 */
		curdrivfil_temp_s32 =  ((SInt32)tqsys_tqckefcfiltrv_prev * BIN4) - curdrivfil_temp_s32;

	}
	else
	{
		/* [-4002000;4002000]BIN8=  [-2000;2000]BIN4 - [-4000000;4000000]BIN8 */
		curdrivfil_temp_s32 =((SInt32)tqsys_tqckefcfiltrv_prev * BIN4) -  curdrivfil_temp_s32;

	}

	if(((SInt32)tqsys_tqckefcfiltrv_par * BIN4) <= curdrivfil_temp_s32)
	{
		TqSys_bDeceDetCur = DDS_TRUE;
	}
	else
	{
		TqSys_bDeceDetCur = DDS_FALSE;
	}


	/*Update prev*/
	/*[-2000;2000]BIN4*/
	tqsys_tqckefcfiltrv_prev = tqsys_tqckefcfiltrv_par;

	/*Updating TqSys_bAcceDetCord, TqSys_bAcceClrCrossCord, TqSys_bDeceDetCord */

	if((UInt32)DDS_FALSE != (UInt32)TqSys_bSelStCur_C)
	{
		TqSys_bAcceDetCord = tqsys_baccedetaos_par;
		TqSys_bAcceClrCrossCord = tqsys_bacceclrcrossaos_par;
		TqSys_bDeceDetCord = tqsys_bdecedetaos_par;
	}
	else
	{
		TqSys_bDeceDetCord = TqSys_bDeceDetCur;

		if((UInt32)DDS_FALSE == (UInt32)TqSys_bAcceDetCur)
		{
			TqSys_bAcceDetCord = DDS_FALSE;
			TqSys_bAcceClrCrossCord = DDS_FALSE;
		}
		else
		{
			if((UInt32)DDS_FALSE == (UInt32)TqSys_bDetClrCrossAcvCur_C)
			{
				if((UInt32)tqclrcros_stdetclr_par >= CURDRIVFIL_TQCLRCROS_EFFECTIF_CST)
				{
					TqSys_bAcceDetCord = DDS_TRUE;
					TqSys_bAcceClrCrossCord = DDS_FALSE;
				}
				else
				{
					TqSys_bAcceDetCord = DDS_FALSE;
					TqSys_bAcceClrCrossCord = DDS_TRUE;
				}
			}
			else
			{
				/* [-2000;2000]BIN4 = [-2000;2000]BIN4 * [0;1]BIN0 */
				curdrivfil_temp_s32 = (SInt32)tqsys_tqthdpha3_par * (SInt32)TqSys_facSelPha3_C;
				/* [-4000;4000]BIN4= [-2000;2000]BIN4 + [-2000;2000]BIN4*/
				curdrivfil_temp_s32 = curdrivfil_temp_s32 + (SInt32)DDS_M_MAP3D_SUS16(&TQSYS_TQOFSCLRCROSS_M_APM,
																(SInt16)ext_nengclc0_par, (UInt16)copt_nogearcorddrivfil_par);

				if((SInt32)tqsys_tqckefcfiltrv_par > curdrivfil_temp_s32)
				{
					TqSys_bAcceDetCord = DDS_TRUE;
					TqSys_bAcceClrCrossCord = DDS_FALSE;
				}
				else
				{
					TqSys_bAcceDetCord = DDS_FALSE;
					TqSys_bAcceClrCrossCord = DDS_TRUE;
				}
			}
		}

	}
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_01_04_Time_Calc
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_01_04_Time_Calc(UInt8  copt_nogearcorddrivfil_par,
														UInt16 ext_nengclc0_par,
														SInt16 tqlimem_tqlimemtrv_par,
														SInt16 tqsys_tqckdeceini_par )
{
	/* SSTG_REQ_TAG: CSCT_CGMT09_2433.FR.15.1 */
	UInt32 curdrivfil_temp_u32;

	/* [0;10]DEC2 */
	TqSys_tiSt1Acce = TqSys_tiSt1Acce_C;
	TqSys_tiSt1Max	= TqSys_tiSt1Max_C;
	TqSys_tiSt3Dece	= TqSys_tiSt3Dece_C;


	/* [0;10]DEC2 */
	curdrivfil_temp_u32 = DDS_M_MAP3D_SUU16(&TQSYS_TIST1MIN_M_APM, (SInt16)ext_nengclc0_par, (UInt16)copt_nogearcorddrivfil_par);
	/*[0;20]DEC2 BIN7 = [0;10]DEC2 * [0;2]BIN7 */
	curdrivfil_temp_u32 = curdrivfil_temp_u32 *	(UInt32)DDS_M_TAB2D_NEAREST_SU16(&TQSYS_TIST1MINTQ_T_APM , tqsys_tqckdeceini_par);
	/*[0;10]DEC2 */
	TqSys_tiSt1Min = (UInt16)DDS_M_MIN((curdrivfil_temp_u32 / BIN7),
										CURDRIVFIL_TQSYS_MAX);

	/* [0;10]DEC2 */
	curdrivfil_temp_u32 = DDS_M_MAP3D_SUU16(&TQSYS_TIST3NGEAR_M_APM, (SInt16)ext_nengclc0_par, (UInt16)copt_nogearcorddrivfil_par);
	/*[0;20]DEC2 BIN7 = [0;10]DEC2 * [0;2]BIN7 */
	curdrivfil_temp_u32 = curdrivfil_temp_u32 *	(UInt32)DDS_M_TAB2D_NEAREST_SU16(&TQSYS_TIST3TQ_T_APM , tqlimem_tqlimemtrv_par);
	/*[0;10]DEC2 */
	TqSys_tiSt3Min = (UInt16)DDS_M_MIN((curdrivfil_temp_u32 / BIN7),
										CURDRIVFIL_TQSYS_MAX);

	/*[0;20]DEC2 = [0;10]DEC2 + [0;10]DEC2 */
	curdrivfil_temp_u32	= (UInt32)TqSys_tiSt3Min + (UInt32)DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_TIST3OFS_T_APM , (UInt16)copt_nogearcorddrivfil_par);
	/*[0;10]DEC2*/
	TqSys_tiSt3Max = (UInt16)DDS_M_MIN(curdrivfil_temp_u32,
										CURDRIVFIL_TQSYS_MAX);
}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Accel_state_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Accel_State_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stAcceAOS_swc_out,
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_prm_AOSConf3_swc_out)
{

	/* CURDRIVFIL_F01_01_State_Calculation */
	TqSys_nChgStDece	= (SInt16)(0 * BIN2);
	TqSys_AOSGrd_MP		= (SInt16)(0 * BIN2);
	TqSys_bNGrdFil		= DDS_FALSE;
	TqSys_bAcceDetCord = DDS_FALSE;
	TqSys_bAcceClrCrossCord = DDS_FALSE;
	TqSys_bDeceDetCord = DDS_FALSE;
	TqSys_bDeceDetCur = DDS_FALSE;
	TqSys_bAcceDetCur = DDS_FALSE;

	tqsys_nchgstdece_prev = (SInt16)(0 * BIN2);
	tqsys_tqckefcfiltrv_prev = (SInt16)(0 * BIN4);

	curdrivfil_f01_01_01_is_filter_init = DDS_FALSE;
	TqSys_nGrdChgStDece_MP = (SInt16)(0 * BIN2);
	TqSys_nGrdChgStDeceFil = (SInt16)(0 * BIN2);

	TqSys_tiSt1Acce = (UInt16)(0 * DEC2);
	TqSys_tiSt1Max 	= (UInt16)(0 * DEC2);
	TqSys_tiSt1Min 	= (UInt16)(0 * DEC2);
	TqSys_tiSt3Dece = (UInt16)(0 * DEC2);
	TqSys_tiSt3Max 	= (UInt16)(0 * DEC2);
	TqSys_tiSt3Min 	= (UInt16)(0 * DEC2);

	/* CURDRIVFIL_F01_01_02_State_Calc */
	*TqSys_stAcceAOS_swc_out 	= (UInt8)CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX;
	tqsys_stacceaos_cpy 		= (UInt8)CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX;

	TqSys_tiSt1 		= (UInt16)(0 * DEC2);
	tqsys_tist1_dec3 	= (UInt32)(0 * DEC3);

	TqSys_tiSt3 		= (UInt16)(0 * DEC2);
	tqsys_tist3_dec3 	= (UInt32)(0 * DEC3);

	/* CURDRIVFIL_F01_02_Calc_Aos_Map_C3 */
	TqSys_prm_AOSConf3_swc_out[0] = (SInt16)(0 * BIN10);
	TqSys_prm_AOSConf3_swc_out[1] = (SInt16)(0 * BIN10);
	TqSys_prm_AOSConf3_swc_out[2] = (SInt16)(0 * BIN10);
	TqSys_prm_AOSConf3_swc_out[3] = (SInt16)(0 * BIN10);
	TqSys_prm_AOSConf3_swc_out[4] = (SInt16)(0 * BIN10);
	TqSys_prm_AOSConf3_swc_out[5] = (SInt16)(0 * BIN10);

}

#define CURDRIVFIL_STOP_SEC_CODE
#include "CurDrivFil_MemMap.h"

