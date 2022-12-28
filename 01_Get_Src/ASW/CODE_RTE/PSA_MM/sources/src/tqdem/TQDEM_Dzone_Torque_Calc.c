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
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Dzone_Torque_Calc.c
* Version int :/main/L04_01/2 Date: 17/7/2012 15 h 48 m User:posmyk 
*    TWK_model:TQDEM_Dzone_Torque_Calc_L04_010_IMPL1_D
*    comments :add INLINE for static functions
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 12 m User:lemort 
*    TWK_model:TQDEM_Dzone_Torque_Calc_L04_010_IMPL1_D
*    comments :add INLINE for static functions
* Version int :/main/L04_01/1 Date: 10/3/2011 11 h 46 m User:esnault
*    TWK_model:TQDEM_Dzone_Torque_Calc_L04_010_IMPL1
*    comments :Update model only: DZone_tqEfcDifLrnOut becomes output of module
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/3/2011 12 h 0 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L04_010_IMPL1
*    comments :Update model only: DZone_tqEfcDifLrnOut becomes output of module
* Version int :/main/L03_01/3 Date: 13/1/2011 14 h 48 m User:meme
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_011_IMPL1_D
*    comments :Correction following TU for TqDem 10.2 & 11.0
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 13/1/2011 10 h 39 m User:demezil
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_011_IMPL1_D
*    comments :Correction following TU for TqDem 10.2 & 11.0
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 13/1/2011 10 h 36 m User:demezil
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_011_IMPL1_D
*    comments :Correction following TU for TqDem 10.2 & 11.0
* Version int :/main/L03_01/2 Date: 8/10/2010 16 h 31 m User:meme
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_011_IMPL1
*    comments :Update code
* Version dev :\main\branch_salmane_tqdem_e6_dev\2 Date: 30/9/2010 14 h 30 m User:salmane
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_011_IMPL1
*    comments :Update code
* Version dev :\main\branch_salmane_tqdem_e6_dev\1 Date: 22/9/2010 9 h 47 m User:salmane
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_011_IMPL1
*    comments :correct code
* Version int :/main/L03_01/1 Date: 1/9/2010 14 h 6 m User:esnault
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 12/8/2010 10 h 7 m User:lemort
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 19/7/2010 15 h 34 m User:demezil
*    TWK_model:TQDEM_Dzone_Torque_Calc_L03_010_IMPL1
*    comments :for TqDem e6
*    comments :spec CSMT_CGMT06_2030_v3_0
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 18/6/2010 9 h 25 m User:demezil
*    TWK_model:TQDEM_Dzone_Torque_Calc_L02_010_IMPL2_D
*    comments :QAC and code shaker e6 pass
* Version int :/main/L02_01/1 Date: 16/9/2009 10 h 45 m User:langendorf
*    TWK_model:TQDEM_Dzone_Torque_Calc_L02_010_IMPL2
*    comments :Correct wrong use of SATURATION bloc and replace by SATURATION_V2
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 2/9/2009 15 h 31 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L02_010_IMPL2
*    comments :Correct wrong use of SATURATION bloc and replace by SATURATION_V2
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 2/9/2009 9 h 16 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L02_010_IMPL2
*    comments :Change model only: TQDEM_Dzone_Torque_Calc_L02_010_IMPL2
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 28/8/2009 15 h 11 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L02_010_IMPL1
*    comments :New specification for TqDem 2.0: CSMT_CGMT06_2030_v2_1
* Version int :/main/L01_01/3 Date: 14/10/2008 16 h 22 m User:langendorf
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :DDS_M_ABS(dzone_tqckidlfil_sub)<= DZone_tqCkIdlDelta_C is wrong
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 14/10/2008 10 h 24 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :DDS_M_ABS(dzone_tqckidlfil_sub)<= DZone_tqCkIdlDelta_C is wrong
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 22/9/2008 12 h 57 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :Fail test correction: DZone_tqDifLrn must be initialized
* Version dev :\main\branch_moisan_tqdem_integ\1 Date: 19/9/2008 16 h 29 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :Correction of a fail test: F01_03_02_Filtrage
* Version int :/main/L01_01/1 Date: 9/9/2008 8 h 8 m User:boucher
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :Wrong definition of DZone_noGearCordX_A
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 5/9/2008 13 h 11 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :Wrong definition of DZone_noGearCordX_A
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 3/9/2008 13 h 24 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :Snapshot of TqDem_tqCkEfc1
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 29/8/2008 10 h 5 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :Correction after fail QAC
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 29/8/2008 9 h 54 m User:moisan
*    TWK_model:TQDEM_Dzone_Torque_Calc_L01_010_IMPL1
*    comments :First implementation for Torque E / PSA SSTG
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "TqDem.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQDEM_DZONE_6_SIZE                      6
#define TQDEM_DZONE_8_SIZE                      8
#define TQDEM_DZONE_9_SIZE                      9

#define TQDEM_STENG_ENGINE_RUNNING                  (UInt32)(5 * BIN0)

#define TQDEM_F02_02_TQMIN                  (SInt32)(-2000 * BIN4)
#define TQDEM_F02_02_TQMAX                  (SInt32)(2000 * BIN4)

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
#define TQDEM_START_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilUpLoSpdVeh_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilUpHiSpdVeh_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilDownLoSpdVeh_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilDownHiSpdVeh_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilNCkIdlDelta_C = (CONST(UInt16, AUTOMATIC))(0.8 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilTqIdl_C = (CONST(UInt16, AUTOMATIC))(0.8 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_facFilTqDif_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_nCkThdClc_C = (CONST(UInt16, AUTOMATIC))(1500 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_nIdlThdClc_C = (CONST(UInt16, AUTOMATIC))(1000 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_nEngOfsTakeOff_C = (CONST(UInt16, AUTOMATIC))(100 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_rAccPInhThd_C = (CONST(UInt16, AUTOMATIC))(0.1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_rAccPThdClc_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_rAccPMax_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_rAccPMin_C = (CONST(UInt16, AUTOMATIC))(0.1 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) DZone_tqMaxSatTqDif_C = (CONST(SInt16, AUTOMATIC))(50 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) DZone_tqMinSatTqDif_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_spdVehThdFilSel_C = (CONST(UInt16, AUTOMATIC))(10 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_spdVehThd_C = (CONST(UInt16, AUTOMATIC))(40 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_tiFrzClc_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) DZone_tqCkIdlDelta_C = (CONST(SInt16, AUTOMATIC))(10 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) DZone_tqCkIdlFilOfs_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) DZone_bAcv_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) DZone_bTqDifSel_C = DDS_TRUE;
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQDEM_START_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) DZone_nCkTarDifX_A[TQDEM_DZONE_6_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(50 * BIN2), (UInt16)(100 * BIN2),
(UInt16)(150 * BIN2), (UInt16)(200 * BIN2), (UInt16)(300 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_noGearCordX_A[TQDEM_DZONE_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(7 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_rAccPY_A[TQDEM_DZONE_6_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(1.5 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(5 * BIN7), (UInt16)(7 * BIN7), (UInt16)(10 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_spdVehThdClc_T
[TQDEM_DZONE_8_SIZE] = {
(UInt16)(5 * BIN7), (UInt16)(5 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(25 * BIN7), (UInt16)(35 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(55 * BIN7), (UInt16)(55 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_spdVehY_A[TQDEM_DZONE_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(15 * BIN7), (UInt16)(20 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(80 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) DZone_tqDifLrn_A[TQDEM_DZONE_6_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_tqDifLrn_T
[TQDEM_DZONE_6_SIZE] = {
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_tqGainGearSpd_M
[TQDEM_DZONE_8_SIZE][TQDEM_DZONE_8_SIZE] = {
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) DZone_tqGainNCkAccP_M
[TQDEM_DZONE_6_SIZE][TQDEM_DZONE_6_SIZE] = {
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10) }
};

#define TQDEM_STOP_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define TQDEM_START_SEC_VAR_8BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqdem_f02_03_initialized;       /* Boolean */
STATIC VAR(UInt8, AUTOMATIC) tqdem_f02_02_initialized;       /* Boolean */
STATIC VAR(UInt8, AUTOMATIC) tqdem_f02_01_initialized;       /* Boolean */
#define TQDEM_STOP_SEC_VAR_8BIT
#include "TqDem_MemMap.h"

/* Complex variable definition */
#define TQDEM_START_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) dzone_spdvehthdclc_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) dzone_tqdiflrn_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) dzone_tqgaingearspd_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) dzone_tqgainnckaccp_m_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_f02_01_filter;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_apprentissage_1;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_apprentissage_2;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_application_attenuation;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_application_filtrage;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqdem_calculation_turn_off;
#define TQDEM_STOP_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"

/* 16-bits variable definition */
#define TQDEM_START_SEC_VAR_16BIT
#include "TqDem_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) dzone_tqckidlfilprev; /* BIN4 */
#define TQDEM_STOP_SEC_VAR_16BIT
#include "TqDem_MemMap.h"

/* 32-bits variable definition */
#define TQDEM_START_SEC_VAR_32BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) dzone_resultswitchattenuationprev; /* BIN4 */
STATIC VAR(SInt32, AUTOMATIC) dzone_facfiltqdifunlim_prev; /* BIN10 */
#define TQDEM_STOP_SEC_VAR_32BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) DZone_facFilTqDifUnLim; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqCkIdlFil; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDIfLrnResi_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) DZone_facFilTqDif_MP; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifEfc_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifLoss_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifLrn; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifLrnOut; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifLrnOutPrev; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifLrnOutRaw_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifLrnUnLim; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) DZone_tqDifSat_MP; /* BIN4 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) DZone_bClcAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) DZone_bTqAux_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) DZone_bTqIdlStab_MP;
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQDEM_START_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) DZONE_SPDVEHTHDCLC_T_APM = {
&dzone_spdvehthdclc_t_sav,
TQDEM_DZONE_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_noGearCordX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_spdVehThdClc_T[0]
};


/*STATIC CONST(t_dds_m_tab2d_u16, AUTOMATIC) DZONE_SPDVEHTHDCLC_T_APT = {
TQDEM_DZONE_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_noGearCordX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_spdVehThdClc_T[0]
};*/


STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) DZONE_TQDIFLRN_T_APM = {
&dzone_tqdiflrn_t_sav,
TQDEM_DZONE_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&DZone_tqDifLrn_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_tqDifLrn_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) DZONE_TQGAINGEARSPD_M_APM = {
&dzone_tqgaingearspd_m_sav,
TQDEM_DZONE_8_SIZE,
TQDEM_DZONE_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_noGearCordX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_spdVehY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_tqGainGearSpd_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) DZONE_TQGAINNCKACCP_M_APM = {
&dzone_tqgainnckaccp_m_sav,
TQDEM_DZONE_6_SIZE,
TQDEM_DZONE_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_nCkTarDifX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_rAccPY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&DZone_tqGainNCkAccP_M[0][0]
};


#define TQDEM_STOP_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_DZone (SInt16 tqdem_tqckefcwoutantidb_par, /* BIN4 */
                                               UInt16 tqsys_nofstottakeoff_par, /* BIN2 */
                                               UInt8 copt_noegdgearcord_par,
                                               UInt16 covsctl_raccpeng_par, /* BIN7 */
                                               UInt16 eng_nckfil_par, /* BIN2 */
                                               UInt8 tqadp_bfrzadpacon_par,
                                               UInt8 tqadp_bfrzadpalton_par,
                                               UInt8 tqadp_bfrzadpcnvon_par,
                                               UInt8 tqadp_bfrzadpstgpmpon_par,
                                               SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                               UInt8 tqsys_bacvantistall_par,
                                               UInt8 tqsys_bengnonidl_par,
                                               UInt16 tqsys_ntaridl_par, /* BIN2 */
                                               SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                               UInt16 veh_spdveh_par /* BIN7 */);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_Calculation_Condition (UInt16 tqsys_nofstottakeoff_par, /* BIN2 */
                                                                   UInt8 copt_noegdgearcord_par,
                                                                   UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                   UInt16 eng_nckfil_par, /* BIN2 */
                                                                   UInt8 tqadp_bfrzadpacon_par,
                                                                   UInt8 tqadp_bfrzadpalton_par,
                                                                   UInt8 tqadp_bfrzadpcnvon_par,
                                                                   UInt8 tqadp_bfrzadpstgpmpon_par,
                                                                   UInt8 tqsys_bacvantistall_par,
                                                                   UInt8 tqsys_bengnonidl_par,
                                                                   UInt16 tqsys_ntaridl_par, /* BIN2 */
                                                                   SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                                                   UInt16 veh_spdveh_par /* BIN7 */);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_Calcul (UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                    SInt16 tqdem_tqckefcwoutantidb_par, /* BIN4 */
                                                    SInt16 tqcmp_tqsumlosscmp_par /* BIN4 */);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_03_Application (UInt8 copt_noegdgearcord_par,
                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                        UInt16 tqsys_ntaridl_par, /* BIN2 */
                                                        UInt16 veh_spdveh_par, /* BIN7 */
                                                        UInt16 covsctl_raccpeng_par /* BIN7 */);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_01_Definition_DeltaCouple (UInt16 covsctl_raccpeng_par,   /* BIN7 */
                                                                       SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                                                       SInt16 tqdem_tqckefcwoutantidb_par /* BIN4 */);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_02_Apprentissage (void);

  INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_03_01_Attenuation (UInt16 covsctl_raccpeng_par,  /* BIN7 */
                                                            UInt8 copt_noegdgearcord_par,
                                                            UInt16 tqsys_ntaridl_par,     /* BIN2 */
                                                            UInt16 veh_spdveh_par,      /* BIN7 */
                                                            UInt16 eng_nckfil_par);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_03_02_Filtrage (UInt16 veh_spdveh_par);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQDEM_Dzone_Torque_Calc
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Dzone_Torque_Calc(SInt16 TqDem_tqCkEfcWoutAntiDB_swc_in, /* BIN4 */
                                               UInt16 TqSys_nOfsTotTakeOff_swc_in, /* BIN2 */
                                               UInt8 CoPTSt_stEng_swc_in,
                                               UInt8 CoPt_noEgdGearCord_swc_in,
                                               UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                               UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                               UInt8 FRM_bInhAntiDB_swc_in,
                                               UInt8 TqAdp_bFrzAdpACOn_swc_in,
                                               UInt8 TqAdp_bFrzAdpAltOn_swc_in,
                                               UInt8 TqAdp_bFrzAdpCnvOn_swc_in,
                                               UInt8 TqAdp_bFrzAdpStgPmpOn_swc_in,
                                               SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                               UInt8 TqSys_bAcvAntiStall_swc_in,
                                               UInt8 TqSys_bEngNOnIdl_swc_in,
                                               UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                               SInt16 TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                               UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) DZone_tqEfcDifLrnOut_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.1 */
    if( ((UInt32)DDS_FALSE == (UInt32)FRM_bInhAntiDB_swc_in) &&
        ((UInt32)DDS_FALSE != (UInt32)DZone_bAcv_C) &&
        (TQDEM_STENG_ENGINE_RUNNING == (UInt32)CoPTSt_stEng_swc_in) )
    {
        /* DZone_tqDifLrnOut */
        TQDEM_F02_DZone (TqDem_tqCkEfcWoutAntiDB_swc_in, /* BIN4 */
                            TqSys_nOfsTotTakeOff_swc_in, /* BIN2 */
                            CoPt_noEgdGearCord_swc_in,
                            CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                            Eng_nCkFil_swc_in, /* BIN2 */
                            TqAdp_bFrzAdpACOn_swc_in,
                            TqAdp_bFrzAdpAltOn_swc_in,
                            TqAdp_bFrzAdpCnvOn_swc_in,
                            TqAdp_bFrzAdpStgPmpOn_swc_in,
                            TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                            TqSys_bAcvAntiStall_swc_in,
                            TqSys_bEngNOnIdl_swc_in,
                            TqSys_nTarIdl_swc_in, /* BIN2 */
                            TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                            Veh_spdVeh_swc_in /* BIN7 */);

        *DZone_tqEfcDifLrnOut_swc_out = DZone_tqDifLrnOut;
    }
    else
    {
        *DZone_tqEfcDifLrnOut_swc_out = 0 * BIN4;
    }
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_F02_DZone
* Description :   Calculation of DZone_tqDifLrnOut
*
*******************************************************************************/
 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_DZone (SInt16 tqdem_tqckefcwoutantidb_par, /* BIN4 */
                                               UInt16 tqsys_nofstottakeoff_par, /* BIN2 */
                                               UInt8 copt_noegdgearcord_par,
                                               UInt16 covsctl_raccpeng_par, /* BIN7 */
                                               UInt16 eng_nckfil_par, /* BIN2 */
                                               UInt8 tqadp_bfrzadpacon_par,
                                               UInt8 tqadp_bfrzadpalton_par,
                                               UInt8 tqadp_bfrzadpcnvon_par,
                                               UInt8 tqadp_bfrzadpstgpmpon_par,
                                               SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                               UInt8 tqsys_bacvantistall_par,
                                               UInt8 tqsys_bengnonidl_par,
                                               UInt16 tqsys_ntaridl_par, /* BIN2 */
                                               SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                               UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.2 */

    /* update prev*/
    DZone_tqDifLrnOutPrev = DZone_tqDifLrnOut;

     /* Calculation of DZone_bClcAcv and DZone_tqCkIdlFil */
     TQDEM_F02_01_Calculation_Condition (tqsys_nofstottakeoff_par, /* BIN2 */
                                         copt_noegdgearcord_par,
                                         covsctl_raccpeng_par, /* BIN7 */
                                         eng_nckfil_par, /* BIN2 */
                                         tqadp_bfrzadpacon_par,
                                         tqadp_bfrzadpalton_par,
                                         tqadp_bfrzadpcnvon_par,
                                         tqadp_bfrzadpstgpmpon_par,
                                         tqsys_bacvantistall_par,
                                         tqsys_bengnonidl_par,
                                         tqsys_ntaridl_par, /* BIN2 */
                                         tqsys_tqckidlcmn_par, /* BIN4 */
                                         veh_spdveh_par /* BIN7 */);

    if((UInt32)DDS_FALSE != (UInt32)DZone_bClcAcv)
    {
         /* Calculation of DZone_tqDifLrn */
         TQDEM_F02_02_Calcul (covsctl_raccpeng_par, /* BIN7 */
                                tqdem_tqckefcwoutantidb_par, /* BIN4 */
                                tqcmp_tqsumlosscmp_par /* BIN4 */);
    }
    else
    {
        /* DO NOTHING */
    }

    /* Calculation of DZone_tqDifLrnOut */
    TQDEM_F02_03_Application (copt_noegdgearcord_par,
                                eng_nckfil_par, /* BIN2 */
                                tqsys_ntaridl_par, /* BIN2 */
                                veh_spdveh_par, /* BIN7 */
                                covsctl_raccpeng_par /* BIN7 */);

    tqdem_f02_01_initialized = DDS_TRUE;

}

/*******************************************************************************
*
* Function Name : TQDEM_F02_01_Calculation_Condition
* Description :   Calculation of DZone_bClcAcv  and DZone_tqCkIdlFil
*
*******************************************************************************/
 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_Calculation_Condition (UInt16 tqsys_nofstottakeoff_par, /* BIN2 */
                                                                   UInt8 copt_noegdgearcord_par,
                                                                   UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                   UInt16 eng_nckfil_par, /* BIN2 */
                                                                   UInt8 tqadp_bfrzadpacon_par,
                                                                   UInt8 tqadp_bfrzadpalton_par,
                                                                   UInt8 tqadp_bfrzadpcnvon_par,
                                                                   UInt8 tqadp_bfrzadpstgpmpon_par,
                                                                   UInt8 tqsys_bacvantistall_par,
                                                                   UInt8 tqsys_bengnonidl_par,
                                                                   UInt16 tqsys_ntaridl_par, /* BIN2 */
                                                                   SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                                                   UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.3 */

    SInt32  dzone_tqckidlfil_sub;
    UInt32  result_turn_off;
    UInt32  table_output_calculation;
    UInt32  condition;

    /*************************************************************/
    /* Calculation of DZone_tqCkIdlFil and dzone_tqckidlfilprev */
    /*************************************************************/

    if((UInt32)DDS_FALSE != (UInt32)tqdem_f02_01_initialized)
    {
        /* BIN4 */
        /* [-2000; 2000] */
        DZone_tqCkIdlFil = DDS_M_FILTER_LP1_S16(&tqdem_f02_01_filter,
                                                 tqsys_tqckidlcmn_par,
                                                 DZone_facFilTqIdl_C,
                                                 BIN10);
    }
    else
    {
        DZone_tqCkIdlFil = DDS_M_FILTER_LP1_S16_INIT(&tqdem_f02_01_filter,
                                                    tqsys_tqckidlcmn_par);
    }

    /* BIN4 */
    /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000]*/
    dzone_tqckidlfil_sub = (SInt32)dzone_tqckidlfilprev - (SInt32)DZone_tqCkIdlFil;
    dzone_tqckidlfilprev = DZone_tqCkIdlFil;

    /*************************************************************/
    /*              Calculation of DZone_bClcAcv                 */
    /*************************************************************/

    if( ((UInt32)DDS_FALSE != (UInt32)tqadp_bfrzadpalton_par) ||
        ((UInt32)DDS_FALSE != (UInt32)tqadp_bfrzadpacon_par) ||
        ((UInt32)DDS_FALSE != (UInt32)tqadp_bfrzadpstgpmpon_par) ||
        ((UInt32)DDS_FALSE != (UInt32)tqadp_bfrzadpcnvon_par) )
    {
        DZone_bTqAux_MP = DDS_TRUE;
    }
    else
    {
        DZone_bTqAux_MP = DDS_FALSE;
    }

    result_turn_off = (UInt32)DDS_M_TURN_OFF_DELAY(DZone_bTqAux_MP,
                                                    DDS_TQDEM_1MS_U32_TIME,
                                                    (UInt32)(DZone_tiFrzClc_C) * DEC1,
                                                    &tqdem_calculation_turn_off);
    if((UInt32)DDS_FALSE == result_turn_off)
    {
        result_turn_off = (UInt32)DDS_TRUE;
    }
    else
    {
        result_turn_off = (UInt32)DDS_FALSE;
    }

    /* BIN7 */
    /* [0; 500] */
    table_output_calculation = (UInt32)DDS_M_MAP2D_U16(&DZONE_SPDVEHTHDCLC_T_APM,
                                                     (UInt16)copt_noegdgearcord_par);


    /*table_output_calculation = (UInt32)DDS_M_TAB2D_U16(&DZONE_SPDVEHTHDCLC_T_APT,
                (UInt16)copt_noegdgearcord_par);*/


    if(((UInt32)DZone_nEngOfsTakeOff_C <= (UInt32)tqsys_nofstottakeoff_par) ||
        ((UInt32)DDS_FALSE != (UInt32)tqsys_bacvantistall_par))
    {
        condition = (UInt32)DDS_FALSE;
    }
    else
    {
        condition = (UInt32)DDS_TRUE;
    }

    if((SInt32)DZone_tqCkIdlDelta_C > DDS_M_ABS(dzone_tqckidlfil_sub))
    {
        DZone_bTqIdlStab_MP = DDS_TRUE;
    }
    else
    {
        DZone_bTqIdlStab_MP = DDS_FALSE;
    }

    if( ((UInt32)DZone_rAccPThdClc_C < (UInt32)covsctl_raccpeng_par) ||
        ((UInt32)veh_spdveh_par > table_output_calculation) ||
        ((UInt32)DDS_FALSE == (UInt32)tqsys_bengnonidl_par) ||
        ((UInt32)DZone_nIdlThdClc_C < (UInt32)tqsys_ntaridl_par) ||
        ((UInt32)DDS_FALSE == result_turn_off) ||
        ((UInt32)DZone_nCkThdClc_C < (UInt32)eng_nckfil_par) ||
        ((UInt32)DDS_FALSE == condition) ||
        ((UInt32)DDS_FALSE == (UInt32)DZone_bTqIdlStab_MP) )
    {
        DZone_bClcAcv = DDS_FALSE;
    }
    else
    {
        DZone_bClcAcv = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F02_02_Calcul
* Description :   Calculation of DZone_tqDifLrn
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_Calcul (UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                    SInt16 tqdem_tqckefcwoutantidb_par, /* BIN4 */
                                                    SInt16 tqcmp_tqsumlosscmp_par /* BIN4 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.4 */

    /* DZone_tqDifNoSat */
    TQDEM_F02_02_01_Definition_DeltaCouple (covsctl_raccpeng_par,    /* BIN7 */
                                             tqcmp_tqsumlosscmp_par, /* BIN4 */
                                             tqdem_tqckefcwoutantidb_par /* BIN4 */);

    /* DZone_tqDifLrn */
    TQDEM_F02_02_02_Apprentissage();

    tqdem_f02_02_initialized = DDS_TRUE;
}

/*******************************************************************************
*
* Function Name : TQDEM_F02_02_01_Definition_DeltaCouple
* Description :   Calculation of DZone_tqDifNoSat
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_01_Definition_DeltaCouple (UInt16 covsctl_raccpeng_par,   /* BIN7 */
                                                                       SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                                                       SInt16 tqdem_tqckefcwoutantidb_par /* BIN4 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.5 */
    SInt32 temp_s32;

    /**************************************************************************
    *       DZone_tqDifLoss_MP calculation
    ***************************************************************************/
    /* BIN4 = BIN4 + BIN4 - BIN4 */
    temp_s32 = ((SInt32)DZone_tqCkIdlFilOfs_C + (SInt32)DZone_tqCkIdlFil) - (SInt32)tqcmp_tqsumlosscmp_par;

    DZone_tqDifLoss_MP = (SInt16)DDS_M_LIMIT(temp_s32,
                                            TQDEM_F02_02_TQMIN,
                                            TQDEM_F02_02_TQMAX);

    /***************************************************************************
    *       condition calculation
    ****************************************************************************/
    if( ((UInt32)DZone_rAccPMax_C < (UInt32)covsctl_raccpeng_par) ||
        ((UInt32)DZone_rAccPMin_C > (UInt32)covsctl_raccpeng_par) )
    {
        DZone_tqDifEfc_MP = (SInt16)(0 * BIN4);
    }
    else
    {
        /* BIN4 = BIN4 - BIN4 */
        temp_s32 = temp_s32 - (SInt32)tqdem_tqckefcwoutantidb_par;
        DZone_tqDifEfc_MP = (SInt16)DDS_M_LIMIT(temp_s32,
                                                TQDEM_F02_02_TQMIN,
                                                TQDEM_F02_02_TQMAX);
    }

    /***************************************************************************
    *       DZone_tqDifLrnUnLim calculation
    ****************************************************************************/
    if((UInt32)DDS_FALSE == (UInt32)DZone_bTqDifSel_C)
    {
        DZone_tqDifLrnUnLim = DZone_tqDifLoss_MP;
    }
    else
    {
        DZone_tqDifLrnUnLim = DZone_tqDifEfc_MP;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F02_02_02_Apprentissage
* Description :   Calculation of DZone_tqDifLrn
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_02_Apprentissage (void)
 {
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.6 */

    SInt32 result_filter;
    SInt32 result_sub;
    UInt16 table_output_apprentissage;

    if((UInt32)DDS_FALSE != (UInt32)tqdem_f02_02_initialized)
    {
        /* BIN4 */
        /* [-2000; 2000] */
        result_filter = DDS_M_FILTER_LP1_S16(&tqdem_filter_apprentissage_1,
                                             DZone_tqDifLrnUnLim,
                                             DZone_facFilTqDif_C,
                                             BIN10);
    }
    else
    {
        result_filter = DDS_M_FILTER_LP1_S16_INIT(&tqdem_filter_apprentissage_1,
                                                    DZone_tqDifLrnUnLim);
    }

    DZone_tqDifSat_MP = (SInt16)DDS_M_SATURATION_V2(result_filter,
                                                    (SInt32)DZone_tqMinSatTqDif_C,
                                                    (SInt32)DZone_tqMaxSatTqDif_C);

    /* BIN4 = BIN4 - BIN4 */
    /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000] */
    result_sub = (SInt32)DZone_tqDifSat_MP - (SInt32)DZone_tqDifLrnOutPrev;

    DZone_tqDIfLrnResi_MP = (SInt16)DDS_M_LIMIT(result_sub,
                                                TQDEM_F02_02_TQMIN,
                                                TQDEM_F02_02_TQMAX);

    /* BIN10 [0, 1] */
    table_output_apprentissage = DDS_M_MAP2D_SU16(&DZONE_TQDIFLRN_T_APM,
                                                    DZone_tqDIfLrnResi_MP);

    if((UInt32)DDS_FALSE != (UInt32)tqdem_f02_02_initialized)
    {
        /* BIN4 */
        /* [-2000; 2000] */
        DZone_tqDifLrn = DDS_M_FILTER_LP1_S16(&tqdem_filter_apprentissage_2,
                                                DZone_tqDifSat_MP,
                                                table_output_apprentissage,
                                                BIN10);
    }
    else
    {
        DZone_tqDifLrn = DDS_M_FILTER_LP1_S16_INIT(&tqdem_filter_apprentissage_2,
                                                     DZone_tqDifSat_MP);
    }
 }


/*******************************************************************************
*
* Function Name : TQDEM_F02_03_Application
* Description :   Calculation of DZone_tqDifLrnOut
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_03_Application (UInt8 copt_noegdgearcord_par,
                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                        UInt16 tqsys_ntaridl_par, /* BIN2 */
                                                        UInt16 veh_spdveh_par, /* BIN7 */
                                                        UInt16 covsctl_raccpeng_par /* BIN7 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.7 */

    TQDEM_F02_03_01_Attenuation (covsctl_raccpeng_par,  /* BIN7 */
                                copt_noegdgearcord_par,
                                tqsys_ntaridl_par,       /* BIN2 */
                                veh_spdveh_par,         /* BIN7 */
                                eng_nckfil_par);

    TQDEM_F02_03_02_Filtrage(veh_spdveh_par);

    tqdem_f02_03_initialized = DDS_TRUE;
}

/*******************************************************************************
*
* Function Name : TQDEM_F02_03_01_Attenuation
* Description :   Calculation of DZone_facFilTqDifUnLim
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_03_01_Attenuation (UInt16 covsctl_raccpeng_par,  /* BIN7 */
                                                            UInt8 copt_noegdgearcord_par,
                                                            UInt16 tqsys_ntaridl_par,     /* BIN2 */
                                                            UInt16 veh_spdveh_par,      /* BIN7 */
                                                            UInt16 eng_nckfil_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.8 */

    SInt32 filter_in, filter_out;
    UInt32 map1_output, map2_output, map_mux;
    UInt32 result_switch;

    /* BIN2 = BIN2 - BIN2 */
    /* [-8000; 8000] = [0; 8000] - [0; 8000] */
    filter_in = (SInt32)eng_nckfil_par - (SInt32)tqsys_ntaridl_par;

    if((UInt32)DDS_FALSE != (UInt32)tqdem_f02_03_initialized)
    {
        /* BIN2 */
        /* [-8000; 8000] */
        filter_out = DDS_M_FILTER_LP1_S16(&tqdem_filter_application_attenuation,
                                            (SInt16)filter_in,
                                            DZone_facFilNCkIdlDelta_C,
                                            BIN10);
    }
    else
    {
        filter_out = DDS_M_FILTER_LP1_S16_INIT(&tqdem_filter_application_attenuation,
                                                 (SInt16)filter_in);
    }

    filter_out = DDS_M_MAX(filter_out,
                            (SInt32)(0 * BIN2));

    /* BIN10 = MAP3D(BIN2, BIN7) */
    /* [0; 1] */
    map2_output = (UInt32)DDS_M_MAP3D_U16(&DZONE_TQGAINNCKACCP_M_APM,
                                            (UInt16)filter_out,
                                            covsctl_raccpeng_par);

    /* BIN10 = MAP3D(BIN0, BIN7) */
    /* [0; 1] */
    map1_output = (UInt32)DDS_M_MAP3D_U16(&DZONE_TQGAINGEARSPD_M_APM,
                                            (UInt16)copt_noegdgearcord_par,
                                            veh_spdveh_par);



    /* [0; 1] = [0; 1] * [0 ;1] */
    /* BIN10 = BIN10 * BIN10 / BIN10 */
    map_mux = ( (map1_output * map2_output) / BIN10 );

    if((UInt32)DZone_rAccPInhThd_C <= (UInt32)covsctl_raccpeng_par)
    {
        result_switch = 0 * BIN10;
    }
    else
    {
        result_switch = map_mux;
    }

    if((UInt32)DZone_spdVehThd_C >= (UInt32)veh_spdveh_par)
    {
        DZone_facFilTqDifUnLim = (UInt16)result_switch;
    }

    else
    {
        DZone_facFilTqDifUnLim = (UInt16)DDS_M_MIN(dzone_resultswitchattenuationprev , result_switch);
    }

    dzone_resultswitchattenuationprev = result_switch;
}

/*******************************************************************************
*
* Function Name : TQDEM_F02_03_02_Filtrage
* Description :   Calculation of DZone_tqDifLrnOut
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_03_02_Filtrage (UInt16 veh_spdveh_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2030.FR.9 */

    SInt32 sub;
    UInt16 result_switch_hi, result_switch_lo, result_switch_middle;

    /* [-1; 1] = [0; 1] - [0 ;1] */
    /* BIN10 = BIN10 - BIN10 */
    sub = (SInt32)DZone_facFilTqDifUnLim - dzone_facfiltqdifunlim_prev ;

    if(sub >= 0)
    {
        result_switch_lo = DZone_facFilDownLoSpdVeh_C;
        result_switch_hi    = DZone_facFilDownHiSpdVeh_C;
    }
    else
    {
        result_switch_lo = DZone_facFilUpLoSpdVeh_C;
        result_switch_hi    = DZone_facFilUpHiSpdVeh_C;
    }

    if((UInt32)DZone_spdVehThdFilSel_C >= (UInt32)veh_spdveh_par)
    {
        result_switch_middle = result_switch_lo;
    }
    else
    {
        result_switch_middle = result_switch_hi;
    }

    if((UInt32)DDS_FALSE != (UInt32)tqdem_f02_03_initialized)
    {
        /* BIN10 */
        /* [0; 1] */
        DZone_facFilTqDif_MP = DDS_M_FILTER_LP1_U16(&tqdem_filter_application_filtrage,
                                                    DZone_facFilTqDifUnLim,
                                                    result_switch_middle,
                                                    BIN10);
    }
    else
    {
        DZone_facFilTqDif_MP = DDS_M_FILTER_LP1_U16_INIT(&tqdem_filter_application_filtrage,
                                                         DZone_facFilTqDifUnLim);
    }

    /* BIN4 = (BIN4 * BIN10) / BIN10 */
    /* [-2000; 2000] = [-2000; 2000] * [0; 1] */
    DZone_tqDifLrnOutRaw_MP = (SInt16)(((SInt32)DZone_tqDifLrn * (SInt32)DZone_facFilTqDif_MP) / BIN10);

    if((UInt32)DDS_FALSE != (UInt32)DZone_bClcAcv)
    {
        DZone_tqDifLrnOut = 0 * BIN4;
    }
    else
    {
        DZone_tqDifLrnOut = DZone_tqDifLrnOutRaw_MP;
    }

    /* Update prev */
    dzone_facfiltqdifunlim_prev = (SInt32)DZone_facFilTqDifUnLim;
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Dzone_Torque_Calc_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Dzone_Torque_Calc_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) DZone_tqEfcDifLrnOut_swc_out /* BIN4 */)
{
    /* Init prev */
    DZone_tqDifLrnOut = 0;
    dzone_tqckidlfilprev  = 0;
    dzone_resultswitchattenuationprev = 0;
    dzone_facfiltqdifunlim_prev = 0;

    DZone_tqDifLrn = 0;

    /* Init macro */
    (void)DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE, &tqdem_calculation_turn_off);

    tqdem_f02_03_initialized = DDS_FALSE;
    tqdem_f02_02_initialized = DDS_FALSE;
    tqdem_f02_01_initialized = DDS_FALSE;

    /* Init Outputs */
    *DZone_tqEfcDifLrnOut_swc_out = 0;
}



#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

