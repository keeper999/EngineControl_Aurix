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
* Ref X:\integration_view_00PSASWC_EB20D11\blois_psa_sstg\Software\Appli\CurDrivFil\src\CURDRIVFIL_Curatif_Param.c
* Version int :/main/L02_01/1 Date: 19/11/2012 12 h 19 m User:posmyk 
*    TWK_model:CURDRIVFIL_Curatif_Param_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6. remove define to push in curdrivfil.h
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\4 Date: 16/11/2012 13 h 45 m User:halouane 
*    TWK_model:CURDRIVFIL_Curatif_Param_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
*    comments :remove define to push in curdrivfil.h
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\3 Date: 5/11/2012 11 h 46 m User:halouane
*    TWK_model:CURDRIVFIL_Curatif_Param_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\2 Date: 26/10/2012 15 h 43 m User:halouane
*    TWK_model:CURDRIVFIL_Curatif_Param_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\1 Date: 26/10/2012 10 h 15 m User:halouane
*    TWK_model:CURDRIVFIL_Curatif_Param_L02_010_IMPL1
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_morisseau_curdriv_euro6_dev\4 Date: 19/10/2012 9 h 57 m User:morisseau
*    TWK_model:CURDRIVFIL_Curatif_Param_L02_010_IMPL1
*    comments :spec update for CurDrivFil 12.0
* Version int :/main/L01_02/1 Date: 7/6/2012 16 h 55 m User:meme
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_020_IMPL1
*    comments :For CurDrivFil_11_0_e6
* Version int :/main/L01_01/3 Date: 18/5/2011 17 h 27 m User:esnault
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_011_IMPL1
*    comments :For CurDrivFil 10.2, Include CPU load reduction and default calibration on TqSys_rAccP_AOS_A
*    comments :axis
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\4 Date: 13/5/2011 10 h 41 m User:veillard
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_011_IMPL1
*    comments :For CurDrivFil 10.2, Include CPU load reduction and default calibration on TqSys_rAccP_AOS_A
*    comments :axis
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 13/5/2011 9 h 48 m User:veillard
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_011_IMPL1
*    comments :For CurDrivFil 10.2, Include CPU load reduction and default calibration on TqSys_rAccP_AOS_A
*    comments :axis
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 12/5/2011 9 h 3 m User:veillard
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_011_IMPL1
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_demezil_curdrivfil_dev\1 Date: 28/4/2011 14 h 19 m User:demezil
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_010_IMPL1_D
*    comments :To reduce CPU load
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 20/4/2011 16 h 12 m User:veillard
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_010_IMPL1_D
*    comments :To reduce CPU load
* Version int :/main/L01_01/2 Date: 30/8/2010 11 h 58 m User:meme
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\10 Date: 27/8/2010 15 h 27 m User:veillard
*    TWK_model:CURDRIVFIL_Curatif_Param_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
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

#define TQSYS_TITRANCORCLRCROSSAOS_MAX (UInt32)(3 * DEC3)

#define TQSYS_FACCORGLBL_MAX            (SInt32)(50 * BIN4)

#define CURDRIVFIL_FACDITQANTIOSC_STMANGBX_MIN (SInt32)(0 * BIN10)
#define CURDRIVFIL_FACDITQANTIOSC_STMANGBX_MAX (SInt32)(1 * BIN10)


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
extern volatile CONST(UInt16, AUTOMATIC) TqSys_idxGain_A[TQSYS_6_SIZE];         /* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_AOSGain_A[TQSYS_12_SIZE];   /* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_AOS_A[TQSYS_9_SIZE];      /* BIN0 */
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
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_aFilEngMaxThd_C = (CONST(SInt16, AUTOMATIC))(5000 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_spdMinAOS_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_spdLimAOS_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
#define CURDRIVFIL_STOP_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facCorMaxAOS_C = (CONST(UInt8, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facCorMinAOS_C = (CONST(UInt8, AUTOMATIC))(0.6 * BIN4);
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_noGearAOS_C = (CONST(SInt8, AUTOMATIC))(0 * BIN0);
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_ctOfsAcvAOS_M
[TQSYS_12_SIZE][TQSYS_9_SIZE] = {
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) },
{
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCor1AOS_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCor2AOS_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCor3AOS_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorAcceAOS_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorStabAOS_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorDeceAOS_M
[TQSYS_9_SIZE][TQSYS_10_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facCorDeceAOSX_A[TQSYS_10_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(50 * BIN4), (SInt16)(100 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(200 * BIN4), (SInt16)(250 * BIN4),
(SInt16)(300 * BIN4), (SInt16)(350 * BIN4), (SInt16)(400 * BIN4),
(SInt16)(500 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facOnIdlAOS_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facOxCHeatAOS_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_AOSCor_A[TQSYS_12_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(400 * BIN2), (UInt16)(500 * BIN2),
(UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(4500 * BIN2), (UInt16)(5000 * BIN2)
};


STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear0_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear1_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear2_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear3_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear4_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear5_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear6_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear7_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf1_noGear8_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear0_M
[TQSYS_6_SIZE][TQSYS_12_SIZE] = {
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) },
{
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear1_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear2_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear3_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear4_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear5_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear6_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear7_M
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

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSCf2_noGear8_M
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

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccP_AOS_A[TQSYS_10_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(40 * BIN7), (UInt16)(50 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(90 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyOnFil_M
[TQSYS_9_SIZE][TQSYS_12_SIZE] = {
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDurSlopOffFil_M
[TQSYS_12_SIZE][TQSYS_9_SIZE] = {
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDurSlopOnFil_M
[TQSYS_12_SIZE][TQSYS_9_SIZE] = {
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) }
};

#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqsys_btreattdc_nckgrd_prev;
STATIC VAR(UInt8, AUTOMATIC) f04_01_condition_rs_prev;
#define CURDRIVFIL_STOP_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"

/* Complex variable definition */
#define CURDRIVFIL_START_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_ctofsacvaos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_faccor1aos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_faccor2aos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_faccoracceaos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_faccordeceaos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_faconidlaos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facoxcheataos_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear0_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear1_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear2_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear3_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear4_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear5_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear6_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear7_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf1_nogear8_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear0_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear1_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear2_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear3_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear4_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear5_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear6_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear7_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_prm_aoscf2_nogear8_m_sav[CURDRIVFIL_NBRSAMPLING_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidlyonfil_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidurslopofffil_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tidursloponfil_m_sav;
STATIC VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC) f04_01_turn_off_sip;
#define CURDRIVFIL_STOP_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"



/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_prm_AOSConf1[CURDRIVFIL_NBRSAMPLING_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_prm_AOSConf2[CURDRIVFIL_NBRSAMPLING_SIZE];

#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_facCor1AOS; /* BIN4 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_facCor2AOS; /* BIN4 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_CTOFSACVAOS_M_APM = {
&tqsys_ctofsacvaos_m_sav,
TQSYS_9_SIZE,
TQSYS_12_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_ctOfsAcvAOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACCOR1AOS_M_APM = {
&tqsys_faccor1aos_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCor1AOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACCOR2AOS_M_APM = {
&tqsys_faccor2aos_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCor2AOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACCOR3AOS_M_APM = {
&tqsys_faccor2aos_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCor3AOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACCORACCEAOS_M_APM = {
&tqsys_faccoracceaos_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorAcceAOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACCORSTABAOS_M_APM = {
&tqsys_faccoracceaos_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rAccP_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorStabAOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACCORDECEAOS_M_APM = {
&tqsys_faccordeceaos_m_sav,
TQSYS_10_SIZE,
TQSYS_9_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorDeceAOSX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorDeceAOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACONIDLAOS_M_APM = {
&tqsys_faconidlaos_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facOnIdlAOS_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACOXCHEATAOS_M_APM = {
&tqsys_facoxcheataos_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facOxCHeatAOS_M[0][0]
};


/* START_CONF_1 */
STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR0_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear0_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear0_M[0][0]},
    {&tqsys_prm_aoscf1_nogear0_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear0_M[0][0]},
    {&tqsys_prm_aoscf1_nogear0_m_sav[2],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear0_M[0][0]},
    {&tqsys_prm_aoscf1_nogear0_m_sav[3],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear0_M[0][0]},
    {&tqsys_prm_aoscf1_nogear0_m_sav[4],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear0_M[0][0]},
    {&tqsys_prm_aoscf1_nogear0_m_sav[5],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear0_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR1_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear1_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear1_M[0][0]},
    {&tqsys_prm_aoscf1_nogear1_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear1_M[0][0]},
    {&tqsys_prm_aoscf1_nogear1_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear1_M[0][0]},
    {&tqsys_prm_aoscf1_nogear1_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear1_M[0][0]},
    {&tqsys_prm_aoscf1_nogear1_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear1_M[0][0]},
    {&tqsys_prm_aoscf1_nogear1_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear1_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR2_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear2_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear2_M[0][0]},
    {&tqsys_prm_aoscf1_nogear2_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear2_M[0][0]},
    {&tqsys_prm_aoscf1_nogear2_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear2_M[0][0]},
    {&tqsys_prm_aoscf1_nogear2_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear2_M[0][0]},
    {&tqsys_prm_aoscf1_nogear2_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear2_M[0][0]},
    {&tqsys_prm_aoscf1_nogear2_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear2_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR3_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear3_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear3_M[0][0]},
    {&tqsys_prm_aoscf1_nogear3_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear3_M[0][0]},
    {&tqsys_prm_aoscf1_nogear3_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear3_M[0][0]},
    {&tqsys_prm_aoscf1_nogear3_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear3_M[0][0]},
    {&tqsys_prm_aoscf1_nogear3_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear3_M[0][0]},
    {&tqsys_prm_aoscf1_nogear3_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear3_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR4_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear4_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear4_M[0][0]},
    {&tqsys_prm_aoscf1_nogear4_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear4_M[0][0]},
    {&tqsys_prm_aoscf1_nogear4_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear4_M[0][0]},
    {&tqsys_prm_aoscf1_nogear4_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear4_M[0][0]},
    {&tqsys_prm_aoscf1_nogear4_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear4_M[0][0]},
    {&tqsys_prm_aoscf1_nogear4_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear4_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR5_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear5_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear5_M[0][0]},
    {&tqsys_prm_aoscf1_nogear5_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear5_M[0][0]},
    {&tqsys_prm_aoscf1_nogear5_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear5_M[0][0]},
    {&tqsys_prm_aoscf1_nogear5_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear5_M[0][0]},
    {&tqsys_prm_aoscf1_nogear5_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear5_M[0][0]},
    {&tqsys_prm_aoscf1_nogear5_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear5_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR6_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear6_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear6_M[0][0]},
    {&tqsys_prm_aoscf1_nogear6_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear6_M[0][0]},
    {&tqsys_prm_aoscf1_nogear6_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear6_M[0][0]},
    {&tqsys_prm_aoscf1_nogear6_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear6_M[0][0]},
    {&tqsys_prm_aoscf1_nogear6_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear6_M[0][0]},
    {&tqsys_prm_aoscf1_nogear6_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear6_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR7_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear7_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear7_M[0][0]},
    {&tqsys_prm_aoscf1_nogear7_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear7_M[0][0]},
    {&tqsys_prm_aoscf1_nogear7_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear7_M[0][0]},
    {&tqsys_prm_aoscf1_nogear7_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear7_M[0][0]},
    {&tqsys_prm_aoscf1_nogear7_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear7_M[0][0]},
    {&tqsys_prm_aoscf1_nogear7_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear7_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF1_NOGEAR8_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf1_nogear8_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear8_M[0][0]},
    {&tqsys_prm_aoscf1_nogear8_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear8_M[0][0]},
    {&tqsys_prm_aoscf1_nogear8_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear8_M[0][0]},
    {&tqsys_prm_aoscf1_nogear8_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear8_M[0][0]},
    {&tqsys_prm_aoscf1_nogear8_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear8_M[0][0]},
    {&tqsys_prm_aoscf1_nogear8_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf1_noGear8_M[0][0]}
};

/* END_CONF_1 */


/* START_CONF 2 */
STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR0_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear0_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear0_M[0][0]},
    {&tqsys_prm_aoscf2_nogear0_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear0_M[0][0]},
    {&tqsys_prm_aoscf2_nogear0_m_sav[2],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear0_M[0][0]},
    {&tqsys_prm_aoscf2_nogear0_m_sav[3],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear0_M[0][0]},
    {&tqsys_prm_aoscf2_nogear0_m_sav[4],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear0_M[0][0]},
    {&tqsys_prm_aoscf2_nogear0_m_sav[5],
        TQSYS_12_SIZE,
        TQSYS_6_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear0_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR1_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear1_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear1_M[0][0]},
    {&tqsys_prm_aoscf2_nogear1_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear1_M[0][0]},
    {&tqsys_prm_aoscf2_nogear1_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear1_M[0][0]},
    {&tqsys_prm_aoscf2_nogear1_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear1_M[0][0]},
    {&tqsys_prm_aoscf2_nogear1_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear1_M[0][0]},
    {&tqsys_prm_aoscf2_nogear1_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear1_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR2_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear2_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear2_M[0][0]},
    {&tqsys_prm_aoscf2_nogear2_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear2_M[0][0]},
    {&tqsys_prm_aoscf2_nogear2_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear2_M[0][0]},
    {&tqsys_prm_aoscf2_nogear2_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear2_M[0][0]},
    {&tqsys_prm_aoscf2_nogear2_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear2_M[0][0]},
    {&tqsys_prm_aoscf2_nogear2_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear2_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR3_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear3_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear3_M[0][0]},
    {&tqsys_prm_aoscf2_nogear3_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear3_M[0][0]},
    {&tqsys_prm_aoscf2_nogear3_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear3_M[0][0]},
    {&tqsys_prm_aoscf2_nogear3_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear3_M[0][0]},
    {&tqsys_prm_aoscf2_nogear3_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear3_M[0][0]},
    {&tqsys_prm_aoscf2_nogear3_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear3_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR4_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear4_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear4_M[0][0]},
    {&tqsys_prm_aoscf2_nogear4_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear4_M[0][0]},
    {&tqsys_prm_aoscf2_nogear4_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear4_M[0][0]},
    {&tqsys_prm_aoscf2_nogear4_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear4_M[0][0]},
    {&tqsys_prm_aoscf2_nogear4_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear4_M[0][0]},
    {&tqsys_prm_aoscf2_nogear4_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear4_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR5_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear5_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear5_M[0][0]},
    {&tqsys_prm_aoscf2_nogear5_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear5_M[0][0]},
    {&tqsys_prm_aoscf2_nogear5_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear5_M[0][0]},
    {&tqsys_prm_aoscf2_nogear5_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear5_M[0][0]},
    {&tqsys_prm_aoscf2_nogear5_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear5_M[0][0]},
    {&tqsys_prm_aoscf2_nogear5_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear5_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR6_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear6_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear6_M[0][0]},
    {&tqsys_prm_aoscf2_nogear6_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear6_M[0][0]},
    {&tqsys_prm_aoscf2_nogear6_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear6_M[0][0]},
    {&tqsys_prm_aoscf2_nogear6_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear6_M[0][0]},
    {&tqsys_prm_aoscf2_nogear6_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear6_M[0][0]},
    {&tqsys_prm_aoscf2_nogear6_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear6_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR7_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear7_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear7_M[0][0]},
    {&tqsys_prm_aoscf2_nogear7_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear7_M[0][0]},
    {&tqsys_prm_aoscf2_nogear7_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear7_M[0][0]},
    {&tqsys_prm_aoscf2_nogear7_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear7_M[0][0]},
    {&tqsys_prm_aoscf2_nogear7_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear7_M[0][0]},
    {&tqsys_prm_aoscf2_nogear7_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear7_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_PRM_AOSCF2_NOGEAR8_M_APM
[CURDRIVFIL_NBRSAMPLING_SIZE]=
{
    {&tqsys_prm_aoscf2_nogear8_m_sav[0],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear8_M[0][0]},
    {&tqsys_prm_aoscf2_nogear8_m_sav[1],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear8_M[0][0]},
    {&tqsys_prm_aoscf2_nogear8_m_sav[2],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear8_M[0][0]},
    {&tqsys_prm_aoscf2_nogear8_m_sav[3],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear8_M[0][0]},
    {&tqsys_prm_aoscf2_nogear8_m_sav[4],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear8_M[0][0]},
    {&tqsys_prm_aoscf2_nogear8_m_sav[5],
    TQSYS_12_SIZE,
    TQSYS_6_SIZE,
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
    (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_idxGain_A[0],
    (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_prm_AOSCf2_noGear8_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDLYONFIL_M_APM = {
&tqsys_tidlyonfil_m_sav,
TQSYS_12_SIZE,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDlyOnFil_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDURSLOPOFFFIL_M_APM = {
&tqsys_tidurslopofffil_m_sav,
TQSYS_9_SIZE,
TQSYS_12_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDurSlopOffFil_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIDURSLOPONFIL_M_APM = {
&tqsys_tidursloponfil_m_sav,
TQSYS_9_SIZE,
TQSYS_12_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSCor_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiDurSlopOnFil_M[0][0]
};

#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Calc_Aos_Map_Calculation(UInt8  copt_nogearcorddrivfil_par,
                                                                     UInt16 ext_nengclc0_par, /* BIN2 */
                                                                     UInt8  tqsys_stacceaos_par,
                                                                     CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC) tqsys_prm_aosconf3_par,
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_facspd0aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_facspd1aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq0aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq1aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq2aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq3aos_ptr /* BIN10 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_Calc_Aos_Map_C1(
                                                                UInt8  copt_nogearcorddrivfil_par,
                                                                UInt16 ext_nengclc0_par /* BIN2 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_Calc_Aos_Map_C2(
                                                                 UInt8  copt_nogearcorddrivfil_par,
                                                               UInt16 ext_nengclc0_par /* BIN2 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Calc_Aos_Raw_Torque(
                                                         UInt8  copt_nogearcorddrivfil_par,
                                                         UInt16 ext_nengclc0_par, /* BIN2 */
                                                         UInt16 covsctl_raccpengtrv_par, /* BIN7 */
                                                         SInt16 tqsys_tqckdeceini_par, /* BIN4 */
                                                         UInt8  eom_btwcheatpha_par,
                                                         UInt8  tqsys_bengnonidl_par,
                                                         UInt8  tqsys_stacceaos_par,
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoridlpha_ptr, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoroxcheatpha_ptr, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccorglbl_ptr /* BIN4 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_04_Calc_Gain_Cor(UInt8 eom_btwcheatpha_par,
                                                             UInt8 copt_nogearcorddrivfil_par,
                                                             UInt16 ext_nengclc0_par, /* BIN2 */
                                                             UInt8  tqsys_bengnonidl_par,
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoridlpha_ptr, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoroxcheatpha_ptr /* BIN4 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_05_Calc_Aos_Global_Correction(
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccorglbl_ptr /* BIN4 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_IncDecAOS(UInt16 veh_spdveh_par,
                                                      UInt8  copt_nogearcorddrivfil_par,
                                                      UInt16 ext_nengclc0_par, /* BIN2 */
                                                      SInt16 treattdc_nckgrd_par, /* BIN2 */
                                                      UInt8  ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosslopacv_ptr,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincacvaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincdiaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctofsacvaos_ptr /* BIN10 */);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_01_Calc_Aos_SIP_And_Take_Off(UInt16 veh_spdveh_par,
                                                                         UInt8  copt_nogearcorddrivfil_par,
                                                                         UInt16 ext_nengclc0_par, /* BIN2 */
                                                                         SInt16 treattdc_nckgrd_par, /* BIN2 */
                                                                         UInt8  ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosslopacv_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_02_Calc_Aos_Torque_Manual_Gearbox_Map(UInt16 ext_nengclc0_par, /* BIN2 */
                                                                                  UInt8  copt_nogearcorddrivfil_par,
                                                                                  UInt8  ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincacvaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincdiaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctofsacvaos_ptr /* BIN10 */);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : CURDRIVFIL_Curatif_Param
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Curatif_Param(
                                           UInt8  CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                           UInt16 CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                                           UInt8  EOM_bTWCHeatPha_swc_in,
                                           UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
                                           UInt8  Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8  TqSys_bEngNOnIdl_swc_in,
                                           CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC) TqSys_prm_AOSConf3_swc_in,/* tab[] BIN10 */
                                           UInt8  TqSys_stAcceAOS_swc_in,
                                           SInt16 TqSys_tqCkDeceIni_swc_in, /* BIN4 */
                                           SInt16 TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqSys_bAOSSlopAcv_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncDiAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctOfsAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorGlbl_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorIdlPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorOxCHeatPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq2AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq3AOS_swc_out /* BIN10 */)
{
    CURDRIVFIL_F02_Calc_Aos_Map_Calculation(CoPt_noGearCordDrivFil_swc_in,
                                            Ext_nEngClc0_swc_in,
                                            TqSys_stAcceAOS_swc_in,
                                            TqSys_prm_AOSConf3_swc_in,
                                            TqSys_facSpd0AOS_swc_out,
                                            TqSys_facSpd1AOS_swc_out,
                                            TqSys_facTq0AOS_swc_out,
                                            TqSys_facTq1AOS_swc_out,
                                            TqSys_facTq2AOS_swc_out,
                                            TqSys_facTq3AOS_swc_out);

    CURDRIVFIL_F03_Calc_Aos_Raw_Torque(CoPt_noGearCordDrivFil_swc_in,
                                       Ext_nEngClc0_swc_in,
                                       CoVSCtl_rAccPEngTrv_swc_in,
                                       TqSys_tqCkDeceIni_swc_in,
                                       EOM_bTWCHeatPha_swc_in,
                                       TqSys_bEngNOnIdl_swc_in,
                                       TqSys_stAcceAOS_swc_in,
                                       TqSys_facCorIdlPha_swc_out,
                                       TqSys_facCorOxCHeatPha_swc_out,
                                       TqSys_facCorGlbl_swc_out);

    CURDRIVFIL_F04_IncDecAOS(Veh_spdVeh_swc_in,
                             CoPt_noGearCordDrivFil_swc_in,
                             Ext_nEngClc0_swc_in,
                             TreatTDC_nCkGrd_swc_in,
                             Ext_tiTDC_swc_in,
                             TqSys_bAOSSlopAcv_swc_out,
                             TqSys_ctIncAcvAOS_swc_out,
                             TqSys_ctIncDiAOS_swc_out,
                             TqSys_ctOfsAcvAOS_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_Calc_Aos_Map_Calculation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Calc_Aos_Map_Calculation(UInt8  copt_nogearcorddrivfil_par,
                                                                     UInt16 ext_nengclc0_par, /* BIN2 */
                                                                     UInt8  tqsys_stacceaos_par,
                                                       	   CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC) tqsys_prm_aosconf3_par,
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_facspd0aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_facspd1aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq0aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq1aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq2aos_ptr, /* BIN10 */
                                                          CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_factq3aos_ptr /* BIN10 */)

{
    /* SSTG_REQ_TAG: CSCT_CSMT09_1958.FR.4.2 */

    if((UInt32)DDS_TRUE != (UInt32)TqSys_bDisNEngEna_C)
    {
        ext_nengclc0_par = DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_NENG_AOSGAIN_T_APM,ext_nengclc0_par);
    }
    else
    {
        /* Nothing to do */
        /* ext_nengclc0_par = ext_nengclc0_par */
    }

    CURDRIVFIL_F02_01_Calc_Aos_Map_C1(copt_nogearcorddrivfil_par,
                                      ext_nengclc0_par);

    CURDRIVFIL_F02_02_Calc_Aos_Map_C2(copt_nogearcorddrivfil_par,
                                      ext_nengclc0_par);

    /* set outputs */
    if(CURDRIVFIL_DECELERATION == (UInt32)tqsys_stacceaos_par)
    {
        *tqsys_factq0aos_ptr = TqSys_prm_AOSConf1[0];
        *tqsys_factq1aos_ptr = TqSys_prm_AOSConf1[1];
        *tqsys_factq2aos_ptr = TqSys_prm_AOSConf1[2];
        *tqsys_factq3aos_ptr = TqSys_prm_AOSConf1[3];
        *tqsys_facspd0aos_ptr = TqSys_prm_AOSConf1[4];
        *tqsys_facspd1aos_ptr = TqSys_prm_AOSConf1[5];
    }
    else if(CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX == (UInt32)tqsys_stacceaos_par)
    {
        *tqsys_factq0aos_ptr = TqSys_prm_AOSConf2[0];
        *tqsys_factq1aos_ptr = TqSys_prm_AOSConf2[1];
        *tqsys_factq2aos_ptr = TqSys_prm_AOSConf2[2];
        *tqsys_factq3aos_ptr = TqSys_prm_AOSConf2[3];
        *tqsys_facspd0aos_ptr = TqSys_prm_AOSConf2[4];
        *tqsys_facspd1aos_ptr = TqSys_prm_AOSConf2[5];
    }
    else
    {
        *tqsys_factq0aos_ptr = tqsys_prm_aosconf3_par[0];
        *tqsys_factq1aos_ptr = tqsys_prm_aosconf3_par[1];
        *tqsys_factq2aos_ptr = tqsys_prm_aosconf3_par[2];
        *tqsys_factq3aos_ptr = tqsys_prm_aosconf3_par[3];
        *tqsys_facspd0aos_ptr = tqsys_prm_aosconf3_par[4];
        *tqsys_facspd1aos_ptr = tqsys_prm_aosconf3_par[5];

    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_01_Calc_Aos_Map_C1
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_Calc_Aos_Map_C1(UInt8  copt_nogearcorddrivfil_par,
                                                               UInt16 ext_nengclc0_par /* BIN2 */)

{
    /* SSTG_REQ_TAG: CSCT_CSMT09_1958.FR.5.1 */
    SInt32 f02_01_index_tab;

    switch((UInt32)copt_nogearcorddrivfil_par)
    {
        case CURDRIVFIL_RAPPORT_EQUIVALENT_0:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_1:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR1_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_2:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR2_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_3:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR3_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));

            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_4:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR4_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_5:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR5_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_6:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR6_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_7:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR7_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_8:
            for(f02_01_index_tab = 0 ; f02_01_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_01_index_tab++)
            {
                TqSys_prm_AOSConf1[f02_01_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR8_M_APM[f02_01_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_01_index_tab + 1));
            }
            break;
        default:
            TqSys_prm_AOSConf1[0] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[0], ext_nengclc0_par, (UInt16)(1));
            TqSys_prm_AOSConf1[1] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[1], ext_nengclc0_par, (UInt16)(2));
            TqSys_prm_AOSConf1[2] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[2], ext_nengclc0_par, (UInt16)(3));
            TqSys_prm_AOSConf1[3] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[3], ext_nengclc0_par, (UInt16)(4));
            TqSys_prm_AOSConf1[4] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[4], ext_nengclc0_par, (UInt16)(5));
            TqSys_prm_AOSConf1[5] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF1_NOGEAR0_M_APM[5], ext_nengclc0_par, (UInt16)(6));
            break;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_02_Calc_Aos_Map_C2
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_Calc_Aos_Map_C2(UInt8  copt_nogearcorddrivfil_par,
                                                               UInt16 ext_nengclc0_par /* BIN2 */)
{
    /* SSTG_REQ_TAG: CSCT_CSMT09_1958.FR.13.1 */
    SInt32 f02_02_index_tab;

    switch((UInt32)copt_nogearcorddrivfil_par)
    {
        case CURDRIVFIL_RAPPORT_EQUIVALENT_0:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_1:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR1_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_2:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR2_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_3:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR3_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));

            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_4:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR4_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_5:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR5_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_6:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR6_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_7:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR7_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;

        case CURDRIVFIL_RAPPORT_EQUIVALENT_8:
            for(f02_02_index_tab = 0 ; f02_02_index_tab < CURDRIVFIL_NBRSAMPLING_SIZE ; f02_02_index_tab++)
            {
                TqSys_prm_AOSConf2[f02_02_index_tab] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR8_M_APM[f02_02_index_tab],
                                                                         ext_nengclc0_par,
                                                                         (UInt16)(f02_02_index_tab + 1));
            }
            break;
        default:
            TqSys_prm_AOSConf2[0] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[0], ext_nengclc0_par, (UInt16)(1));
            TqSys_prm_AOSConf2[1] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[1], ext_nengclc0_par, (UInt16)(2));
            TqSys_prm_AOSConf2[2] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[2], ext_nengclc0_par, (UInt16)(3));
            TqSys_prm_AOSConf2[3] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[3], ext_nengclc0_par, (UInt16)(4));
            TqSys_prm_AOSConf2[4] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[4], ext_nengclc0_par, (UInt16)(5));
            TqSys_prm_AOSConf2[5] = DDS_M_MAP3D_UUS16(&TQSYS_PRM_AOSCF2_NOGEAR0_M_APM[5], ext_nengclc0_par, (UInt16)(6));
            break;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_Calc_Aos_Raw_Torque
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Calc_Aos_Raw_Torque(UInt8  copt_nogearcorddrivfil_par,
                                                             UInt16 ext_nengclc0_par, /* BIN2 */
                                                             UInt16 covsctl_raccpengtrv_par, /* BIN7 */
                                                             SInt16 tqsys_tqckdeceini_par, /* BIN4 */
                                                             UInt8  eom_btwcheatpha_par,
                                                             UInt8  tqsys_bengnonidl_par,
                                                             UInt8  tqsys_stacceaos_par,
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoridlpha_ptr, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoroxcheatpha_ptr, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccorglbl_ptr /* BIN4 */)

{
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.40.2 */
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.45.3 */
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.46.3 */

    switch((UInt32)tqsys_stacceaos_par)
    {
        case CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX:
        /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.45.3 */
            TqSys_facCor1AOS = (UInt8)DDS_M_MAP3D_U16(&TQSYS_FACCOR2AOS_M_APM , ext_nengclc0_par , (UInt16)copt_nogearcorddrivfil_par);
            /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.46.3 */
            TqSys_facCor2AOS = (UInt8)DDS_M_MAP3D_U16(&TQSYS_FACCORSTABAOS_M_APM , covsctl_raccpengtrv_par , (UInt16)copt_nogearcorddrivfil_par);
            break;

        case CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX:
			 /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.45.3 */
            TqSys_facCor1AOS = (UInt8)DDS_M_MAP3D_U16(&TQSYS_FACCOR3AOS_M_APM , ext_nengclc0_par , (UInt16)copt_nogearcorddrivfil_par);
            /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.46.3 */
            TqSys_facCor2AOS = (UInt8)DDS_M_MAP3D_U16(&TQSYS_FACCORACCEAOS_M_APM , covsctl_raccpengtrv_par , (UInt16)copt_nogearcorddrivfil_par);
            break;

        case CURDRIVFIL_DECELERATION:
        default:
             /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.45.3 */
            TqSys_facCor1AOS = (UInt8)DDS_M_MAP3D_U16(&TQSYS_FACCOR1AOS_M_APM , ext_nengclc0_par , (UInt16)copt_nogearcorddrivfil_par);
            /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.46.3 */
            TqSys_facCor2AOS = (UInt8)DDS_M_MAP3D_SUU16(&TQSYS_FACCORDECEAOS_M_APM , tqsys_tqckdeceini_par , (UInt16)copt_nogearcorddrivfil_par);
            break;
    }


    CURDRIVFIL_F03_04_Calc_Gain_Cor(eom_btwcheatpha_par,
                                    copt_nogearcorddrivfil_par,
                                    ext_nengclc0_par,
                                    tqsys_bengnonidl_par,
                                    tqsys_faccoridlpha_ptr,
                                    tqsys_faccoroxcheatpha_ptr);


    CURDRIVFIL_F03_05_Calc_Aos_Global_Correction(tqsys_faccorglbl_ptr);
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_04_Calc_Gain_Cor
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_04_Calc_Gain_Cor(
                                                        UInt8 eom_btwcheatpha_par,
                                                        UInt8 copt_nogearcorddrivfil_par,
                                                        UInt16 ext_nengclc0_par, /* BIN2 */
                                                        UInt8  tqsys_bengnonidl_par,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoridlpha_ptr, /* BIN4 */
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccoroxcheatpha_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.47.1 */

    /* TqSys_facCorOxCHeatPha calculation */
    if((UInt32)DDS_TRUE == (UInt32)eom_btwcheatpha_par)
    {
        /* [-10;10]BIN4 */
        *tqsys_faccoroxcheatpha_ptr = (SInt16)DDS_M_MAP3D_U16(&TQSYS_FACOXCHEATAOS_M_APM , ext_nengclc0_par , (UInt16)copt_nogearcorddrivfil_par);
    }
    else
    {
        /* [-10;10]BIN4 */
        *tqsys_faccoroxcheatpha_ptr = (SInt16)(1 * BIN4);
    }


    /* TqSys_facCorIdlPha calculation */
    if((UInt32)DDS_TRUE == (UInt32)tqsys_bengnonidl_par)
    {
        /* [-10;10]BIN4 */
        *tqsys_faccoridlpha_ptr = (SInt16)DDS_M_MAP3D_U16(&TQSYS_FACONIDLAOS_M_APM , ext_nengclc0_par , (UInt16)copt_nogearcorddrivfil_par);
    }
    else
    {
        /* [-10;10]BIN4 */
        *tqsys_faccoridlpha_ptr = (SInt16)(1 * BIN4);
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_05_Calc_Aos_Global_Correction
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_05_Calc_Aos_Global_Correction(
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_faccorglbl_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.48.2 */
    SInt32 f03_05_sat_in;

    /* [0;100]BIN4 = ( [0;10]BIN4 * [0;10]BIN4 ) / BIN4 */
    f03_05_sat_in = ((SInt32)TqSys_facCor1AOS * (SInt32)TqSys_facCor2AOS) / BIN4;

    /* [0;10]BIN4 */
    *tqsys_faccorglbl_ptr = (SInt16)DDS_M_SATURATION_V2 (f03_05_sat_in, (SInt32)TqSys_facCorMinAOS_C, (SInt32)TqSys_facCorMaxAOS_C);
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F04_IncDecAOS
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_IncDecAOS(UInt16 veh_spdveh_par,
                                                      UInt8  copt_nogearcorddrivfil_par,
                                                      UInt16 ext_nengclc0_par, /* BIN2 */
                                                      SInt16 treattdc_nckgrd_par, /* BIN2 */
                                                      UInt8  ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosslopacv_ptr,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincacvaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincdiaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctofsacvaos_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.37.2 */

    CURDRIVFIL_F04_01_Calc_Aos_SIP_And_Take_Off(veh_spdveh_par,
                                                copt_nogearcorddrivfil_par,
                                                ext_nengclc0_par,
                                                treattdc_nckgrd_par,
                                                ext_titdc_par,
                                                tqsys_baosslopacv_ptr);


    CURDRIVFIL_F04_02_Calc_Aos_Torque_Manual_Gearbox_Map(ext_nengclc0_par,
                                                         copt_nogearcorddrivfil_par,
                                                         ext_titdc_par,
                                                         tqsys_ctincacvaos_ptr,
                                                         tqsys_ctincdiaos_ptr,
                                                         tqsys_ctofsacvaos_ptr);
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F04_01_Calc_Aos_SIP_And_Take_Off
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_01_Calc_Aos_SIP_And_Take_Off(UInt16 veh_spdveh_par,
                                                                         UInt8  copt_nogearcorddrivfil_par,
                                                                         UInt16 ext_nengclc0_par, /* BIN2 */
                                                                         SInt16 treattdc_nckgrd_par, /* BIN2 */
                                                                         UInt8  ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosslopacv_ptr)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.38.3 */
    UInt16 f04_01_map_out;

    UInt8 f04_01_result_turn_off;
    UInt8 f04_01_condition_rs;


    /* [0;2]DEC3 */
    f04_01_map_out = DDS_M_MAP3D_U16(&TQSYS_TIDLYONFIL_M_APM , ext_nengclc0_par, (UInt16)copt_nogearcorddrivfil_par);


    if(  ((SInt32)TqSys_noGearAOS_C == (SInt32)copt_nogearcorddrivfil_par)
       &&((UInt32)veh_spdveh_par < (UInt32)TqSys_spdLimAOS_C))
    {
        f04_01_result_turn_off = DDS_M_TURN_OFF_DELAY_DELTA(DDS_TRUE,
                                                           (UInt32)ext_titdc_par,    /* DEC3 */
                                                           (UInt32)f04_01_map_out,   /* DEC3 */
                                                           &f04_01_turn_off_sip) ;
    }
    else
    {
        f04_01_result_turn_off = DDS_M_TURN_OFF_DELAY_DELTA(DDS_FALSE,
                                                           (UInt32)ext_titdc_par,    /* DEC3 */
                                                           (UInt32)f04_01_map_out,   /* DEC3 */
                                                           &f04_01_turn_off_sip);
    }

    /* Reset priority */
    if(  ((SInt32)treattdc_nckgrd_par >= 0)
       &&((UInt32)DDS_FALSE != (UInt32)tqsys_btreattdc_nckgrd_prev))
    {
        /* Reset value */
        f04_01_condition_rs = DDS_FALSE;
    }
    else if ( (SInt32)TqSys_aFilEngMaxThd_C  <= (SInt32)treattdc_nckgrd_par)
    {
        /* Set value */
        f04_01_condition_rs = DDS_TRUE;
    }
    else
    {
        /* Keep previous value */
        f04_01_condition_rs = f04_01_condition_rs_prev;
    }

    /* update prev values */
    f04_01_condition_rs_prev = f04_01_condition_rs;


    if((SInt32)treattdc_nckgrd_par < 0)
    {
        tqsys_btreattdc_nckgrd_prev = DDS_TRUE;
    }
    else
    {
        tqsys_btreattdc_nckgrd_prev = DDS_FALSE;
    }

    /* set output */
    if(  ((UInt32)veh_spdveh_par < (UInt32)TqSys_spdMinAOS_C)
       ||((UInt32)DDS_FALSE != (UInt32)f04_01_result_turn_off)
       ||((UInt32)DDS_FALSE != (UInt32)f04_01_condition_rs) )
    {
        *tqsys_baosslopacv_ptr = DDS_FALSE;
    }
    else
    {
        *tqsys_baosslopacv_ptr = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F04_02_Calc_Aos_Torque_Manual_Gearbox_Map
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F04_02_Calc_Aos_Torque_Manual_Gearbox_Map(UInt16 ext_nengclc0_par, /* BIN2 */
                                                                                  UInt8  copt_nogearcorddrivfil_par,
                                                                                  UInt8  ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincacvaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctincdiaos_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ctofsacvaos_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_1958.FR.39.1 */
    UInt32 f04_02_map_out_1;
    UInt32 f04_02_map_out_2;

    /* [0;1]DEC3 */
    f04_02_map_out_1 = DDS_M_MAP3D_U16(&TQSYS_TIDURSLOPOFFFIL_M_APM,
                                    (UInt16)copt_nogearcorddrivfil_par,
                                    ext_nengclc0_par);

    /* [0;1]DEC3 */
    f04_02_map_out_2 = DDS_M_MAP3D_U16(&TQSYS_TIDURSLOPONFIL_M_APM,
                                    (UInt16)copt_nogearcorddrivfil_par,
                                    ext_nengclc0_par);

    /* TqSys_ctIncDiAOS calculation is equivalent to Ext_tiTDC / TqSys_tiDurSlopOffFil_M with a limitation of range to [0; 1] */
    if (0 == (UInt32)ext_titdc_par)
    {
        *tqsys_ctincdiaos_ptr = (UInt16)(0 * BIN10);

    }
    else if(  (0 == f04_02_map_out_1)
            ||(f04_02_map_out_1 < (UInt32)ext_titdc_par))
    {
        *tqsys_ctincdiaos_ptr = (UInt16)(1 * BIN10);
    }
    else
    {
        /* BIN10 = (DEC3 * BIN10) / DEC3 */
        /* DEC3 * BIN10 = 1 024 000 < BIN20 */
        /* [0; 1] = [0; 0.1] / [0; 1] */
        *tqsys_ctincdiaos_ptr = (UInt16)(((UInt32)ext_titdc_par * BIN10) / f04_02_map_out_1);
    }


    /* TqSys_ctIncAcvAOS calculation is equivalent to Ext_tiTDC / TqSys_tiDurSlopOnFil_M with a limitation of range to [0; 1] */
    if (0 == (UInt32)ext_titdc_par)
    {
        *tqsys_ctincacvaos_ptr = 0 * BIN10;
    }
    else if(  (0 == f04_02_map_out_2)
            ||(f04_02_map_out_2 < (UInt32)ext_titdc_par) )
    {
        *tqsys_ctincacvaos_ptr = 1 * BIN10;
    }
    else
    {
        /* BIN10 = (DEC3 * BIN10) / DEC3 */
        /* DEC3 * BIN10 = 1 024 000 < BIN20 */
        /* [0; 1] = [0; 0.1] / [0; 1] */
        *tqsys_ctincacvaos_ptr = (UInt16)(((UInt32)ext_titdc_par * BIN10) / f04_02_map_out_2);
    }

    /* [0;1]BIN10 */
    *tqsys_ctofsacvaos_ptr = DDS_M_MAP3D_U16(&TQSYS_CTOFSACVAOS_M_APM,
                                             (UInt16)copt_nogearcorddrivfil_par,
                                             ext_nengclc0_par);
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Curatif_Param_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Curatif_Param_Init(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqSys_bAOSSlopAcv_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctIncDiAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_ctOfsAcvAOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorGlbl_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorIdlPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facCorOxCHeatPha_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facSpd1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq0AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq1AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq2AOS_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_facTq3AOS_swc_out  /* BIN10 */)
{
    /* ---- Init Global Datas ---- */

    /* --- CURDRIVFIL_F02_Calc_Aos_Map_Calculation --- */
    *TqSys_facTq0AOS_swc_out = (SInt16)(0 * BIN10);
    *TqSys_facTq1AOS_swc_out = (SInt16)(0 * BIN10);
    *TqSys_facTq2AOS_swc_out = (SInt16)(0 * BIN10);
    *TqSys_facTq3AOS_swc_out = (SInt16)(0 * BIN10);
    *TqSys_facSpd0AOS_swc_out = (SInt16)(0 * BIN10);
    *TqSys_facSpd1AOS_swc_out = (SInt16)(0 * BIN10);

    /* --- CURDRIVFIL_F02_01_Calc_Aos_Map_C1 --- */
    TqSys_prm_AOSConf1[0] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf1[1] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf1[2] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf1[3] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf1[4] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf1[5] = (SInt16)(0 * BIN10);

    /* --- CURDRIVFIL_F02_02_Calc_Aos_Map_C2 --- */
    TqSys_prm_AOSConf2[0] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf2[1] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf2[2] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf2[3] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf2[4] = (SInt16)(0 * BIN10);
    TqSys_prm_AOSConf2[5] = (SInt16)(0 * BIN10);

    /* --- CURDRIVFIL_F03_02_Calc_Aos_Torque_Correction_1 --- */
    TqSys_facCor1AOS = (UInt8)(0 * BIN4);

    /* --- CURDRIVFIL_F03_03_Calc_Aos_Torque_Correction_2 --- */
    TqSys_facCor2AOS = (UInt8)(0 * BIN4);

    /* --- CURDRIVFIL_F03_04_Calc_Gain_Cor --- */
    *TqSys_facCorOxCHeatPha_swc_out = (SInt16)(0 * BIN4);
    *TqSys_facCorIdlPha_swc_out     = (SInt16)(0 * BIN4);

    /* --- CURDRIVFIL_F03_05_Calc_Aos_Global_Correction --- */
    *TqSys_facCorGlbl_swc_out = (SInt16)(0 * BIN4);

    /* --- CURDRIVFIL_F04_IncDecAOS --- */
    *TqSys_bAOSSlopAcv_swc_out = DDS_FALSE;

    /* --- CURDRIVFIL_F04_01_Calc_Aos_SIP_And_Take_Off --- */
    tqsys_btreattdc_nckgrd_prev = DDS_FALSE;
    f04_01_condition_rs_prev    = DDS_TRUE;
    *TqSys_bAOSSlopAcv_swc_out  = DDS_FALSE;
    (void)DDS_M_TURN_OFF_DELAY_DELTA_INIT(DDS_FALSE, &f04_01_turn_off_sip);

    /* --- CURDRIVFIL_F04_02_Calc_Aos_Torque_Manual_Gearbox_Map --- */
    *TqSys_ctOfsAcvAOS_swc_out   = (UInt16)(0 * BIN10);
    *TqSys_ctIncDiAOS_swc_out    = (UInt16)(0 * BIN10);
    *TqSys_ctIncAcvAOS_swc_out   = (UInt16)(0 * BIN10);
}



#define CURDRIVFIL_STOP_SEC_CODE
#include "CurDrivFil_MemMap.h"

