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
* Ref X:\integration_view_00PSASWC_EB22D11\blois_psa_sstg\Software\Appli\CurDrivFil\src\CURDRIVFIL_Final_Curat_Corr.c
* Version int :/main/L02_01/2 Date: 23/7/2013 15 h 42 m User:posmyk 
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL3_D
*    comments :CurDrivFil 12.2 : correct FDS A0208449
* Version dev :\main\branch_lemort_e6_dev\1 Date: 18/7/2013 11 h 17 m User:lemort 
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL3_D
*    comments :CurDrivFil 12.2 : correct FDS A0208449
* Version int :/main/L02_01/1 Date: 19/11/2012 12 h 18 m User:posmyk
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL3
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\3 Date: 8/11/2012 15 h 21 m User:halouane
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL3
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\2 Date: 6/11/2012 14 h 30 m User:halouane
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL2
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\1 Date: 26/10/2012 10 h 14 m User:halouane
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL2
*    comments :For CurDrivFil_12_0_e6
* Version dev :\main\branch_morisseau_curdriv_euro6_dev\5 Date: 17/10/2012 11 h 46 m User:morisseau
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L02_010_IMPL1
*    comments :spec update for CurDrivFil 12.0
* Version int :/main/L01_01/2 Date: 18/5/2011 17 h 30 m User:esnault
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL3_D
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 12/5/2011 9 h 52 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL3_D
*    comments :For CurDrivFil 10.2, Include CPU load reduction
* Version dev :\main\branch_demezil_curdrivfil_dev\1 Date: 28/4/2011 14 h 28 m User:demezil
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL3_D
*    comments :To reduce CPU load
* Version int :/main/L01_01/1 Date: 27/8/2010 10 h 49 m User:meme
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL3
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\6 Date: 26/8/2010 15 h 21 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL3
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_demezil_curdrivfil_dev\1 Date: 18/8/2010 12 h 15 m User:demezil
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL2
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\5 Date: 21/7/2010 11 h 14 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\4 Date: 20/7/2010 10 h 58 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL1
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 7/7/2010 14 h 54 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 2/7/2010 15 h 14 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 30/6/2010 17 h 27 m User:veillard
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_moisan_curdrivfil\3 Date: 25/6/2010 16 h 57 m User:moisan
*    TWK_model:CURDRIVFIL_Final_Curat_Corr_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_moisan_curdrivfil\2 Date: 25/6/2010 16 h 40 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Work in progress
* Version dev :\main\branch_moisan_curdrivfil\1 Date: 25/6/2010 15 h 32 m User:moisan
*    TWK_model:NO_MODEL
*    comments :First issue for CurDrivFil Euro6
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "CurDrivFil.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define CURDRIVFIL_0                (UInt32)0
#define CURDRIVFIL_1_BIN10          (UInt32)(1 * BIN10)
#define CURDRIVFIL_0_BIN10          (UInt32)(0 * BIN10)
#define CURDRIVFIL_100_DEC3         (UInt32)(100 * DEC3)
#define CURDRIVFIL_400_BIN0         (UInt32)(400 * BIN0)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component NVM Variables: Inputs from other Files
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
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_AOS_A[TQSYS_9_SIZE];      /* BIN0 */
extern volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDeceIni_AOS_A[CURDRIVFIL_5_SIZE];      /* BIN4 */
extern volatile CONST(SInt16, AUTOMATIC) TqSys_tqLimEM_AOS_A[CURDRIVFIL_5_SIZE];      /* BIN4 */
#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
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

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facCnvNFil2_C = (SInt16)(1 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tCoMesMinAOS_C = (SInt16)(0 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiMaxRstAOS_C = (UInt16)(90 * DEC1);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdCordMaxThd_C = (SInt16)(-20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqMaxSafety_C = (SInt16)(100 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqRstAOS_nIdl_C = (SInt16)(510 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSetAOS_nIdl_C = (SInt16)(0 * BIN4);
#define CURDRIVFIL_STOP_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bAOS_tiMaxEna_C = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bAOSIdlEna_C = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bAOSSlopAcv_C = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bCorManGBx_C = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bDiAOS_C = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bSetAOS_tiEna_C = DDS_TRUE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bSelAOSTran_C = DDS_TRUE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_bSelCdnAOS_C = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_facSelSetAOS_C = (SInt8)(2 * BIN0);
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"



/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_ctRstSmallMax_T[TQSYS_9_SIZE] = {
(UInt16)(10 * BIN0),(UInt16)(10 * BIN0),(UInt16)(10 * BIN0),(UInt16)(10 * BIN0),
(UInt16)(10 * BIN0),(UInt16)(10 * BIN0),(UInt16)(10 * BIN0),(UInt16)(10 * BIN0),
(UInt16)(10 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_ctSetHiMax_T[TQSYS_9_SIZE] = {
(UInt16)(0 * BIN0),(UInt16)(0 * BIN0),(UInt16)(0 * BIN0),(UInt16)(0 * BIN0),
(UInt16)(0 * BIN0),(UInt16)(0 * BIN0),(UInt16)(0 * BIN0),(UInt16)(0 * BIN0),
(UInt16)(0 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_AOSAcv_A[CURDRIVFIL_8_SIZE] = {
(UInt16)(500 * BIN2),(UInt16)(1000 * BIN2),(UInt16)(1500 * BIN2),
(UInt16)(2000 * BIN2),(UInt16)(2500 * BIN2),(UInt16)(3000 * BIN2),
(UInt16)(3500 * BIN2),(UInt16)(4000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nHiSpdAntiStall_T[TQSYS_9_SIZE] = {
(UInt16)(4500 * BIN2),(UInt16)(4500 * BIN2),(UInt16)(4500 * BIN2),
(UInt16)(4500 * BIN2),(UInt16)(4500 * BIN2),(UInt16)(4500 * BIN2),
(UInt16)(4500 * BIN2),(UInt16)(4500 * BIN2),(UInt16)(4500 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nLoSpdAntiStall_T[TQSYS_9_SIZE] = {
(UInt16)(600 * BIN2),(UInt16)(600 * BIN2),(UInt16)(600 * BIN2),
(UInt16)(600 * BIN2),(UInt16)(600 * BIN2),(UInt16)(600 * BIN2),
(UInt16)(600 * BIN2),(UInt16)(600 * BIN2),(UInt16)(600 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiCkRawAOSFil_T[TQSYS_9_SIZE] = {
(UInt16)(0.2 * DEC2),(UInt16)(0.2 * DEC2),(UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2),(UInt16)(0.2 * DEC2),(UInt16)(0.2 * DEC2),
(UInt16)(0.2 * DEC2),(UInt16)(0.2 * DEC2),(UInt16)(0.2 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiMaxRstAOS_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)},
{
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),
(UInt16)(10 * DEC1),(UInt16)(10 * DEC1),(UInt16)(10 * DEC1)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqMaxAOS_T[TQSYS_9_SIZE] = {
(SInt16)(510 * BIN4),(SInt16)(510 * BIN4),(SInt16)(510 * BIN4),
(SInt16)(510 * BIN4),(SInt16)(510 * BIN4),(SInt16)(510 * BIN4),
(SInt16)(510 * BIN4),(SInt16)(510 * BIN4),(SInt16)(510 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqMaxIdlAOS_T[TQSYS_9_SIZE] = {
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4),(SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4),(SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqMinAOS_T[TQSYS_9_SIZE] = {
(SInt16)(-100 * BIN4),(SInt16)(-100 * BIN4),(SInt16)(-100 * BIN4),
(SInt16)(-100 * BIN4),(SInt16)(-100 * BIN4),(SInt16)(-100 * BIN4),
(SInt16)(-100 * BIN4),(SInt16)(-100 * BIN4),(SInt16)(-100 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqRawMaxAOS_T[TQSYS_9_SIZE] = {
(SInt16)(50 * BIN4),(SInt16)(50 * BIN4),(SInt16)(50 * BIN4),(SInt16)(50 * BIN4),
(SInt16)(50 * BIN4),(SInt16)(50 * BIN4),(SInt16)(50 * BIN4),(SInt16)(50 * BIN4),
(SInt16)(50 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqSetChgClrCrossAOS_T[TQSYS_9_SIZE] = {
(UInt16)(0.2 * BIN4),(UInt16)(0.2 * BIN4),(UInt16)(0.2 * BIN4),
(UInt16)(0.2 * BIN4),(UInt16)(0.2 * BIN4),(UInt16)(0.2 * BIN4),
(UInt16)(0.2 * BIN4),(UInt16)(0.2 * BIN4),(UInt16)(0.2 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSetCordChgAOS_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSetCordChgAOS_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSetCordChgDeceAOS_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)},
{
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),(SInt16)(5 * BIN4),
(SInt16)(5 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSetCordChgDeceAOS_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSmlAOS_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSmlAOS_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSmlClrCross_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSmlDece_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)},
{
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqSmlDece_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqHiDece_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqGearHiClrCross_T[TQSYS_9_SIZE] = {
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqGearSmlClrCross_T[TQSYS_9_SIZE] = {
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),(SInt16)(10 * BIN4),
(SInt16)(10 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqHiAOS_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqHiClrCross_T[CURDRIVFIL_5_SIZE] = {
(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),(SInt16)(1 * BIN4),
(SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqHiAOS_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqHiDece_M[CURDRIVFIL_8_SIZE][TQSYS_9_SIZE] = {
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)},
{
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),
(SInt16)(20 * BIN4),(SInt16)(20 * BIN4),(SInt16)(20 * BIN4)}
};
#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"



/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define CURDRIVFIL_START_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) curdrivfil_f02_04_calc_aos_hyst_struct;
STATIC VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC) curdrivfil_f01_calc_off_delay;
STATIC VAR(t_dds_m_soft_trans_delta_s32_type, AUTOMATIC) curdrivfil_f01_trans_structure;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) curdrivfil_f03_01_edgedetect_ptr;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) curdrivfil_f02_04_p_edge_0;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) curdrivfil_f02_04_p_edge_1;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_ctrstsmallmax_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_ctsethimax_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_nhispdantistall_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_nlospdantistall_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tickrawaosfil_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_timaxrstaos_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqgearhiclrcross_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqgearsmlclrcross_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqhiaos_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqhiaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqhiclrcross_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqhidece_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqhidece_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqmaxaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqmaxidlaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqminaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqrawmaxaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqsetchgclrcrossaos_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsetcordchgaos_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqsetcordchgaos_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsetcordchgdeceaos_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqsetcordchgdeceaos_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsmlaos_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqsmlaos_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqsmlclrcross_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqsmldece_m_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_tqsmldece_t_sav;
#define CURDRIVFIL_STOP_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/* 32-bits variable definition */
#define CURDRIVFIL_START_SEC_VAR_32BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) curdrivfil_f01_mem_block;
#define CURDRIVFIL_STOP_SEC_VAR_32BIT
#include "CurDrivFil_MemMap.h"

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) curdrivfil_f02_04_aos_cnt_0;
STATIC VAR(SInt16, AUTOMATIC) curdrivfil_f02_04_aos_cnt_1;
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckenglimcord_prev;
#define CURDRIVFIL_STOP_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqsys_baosacv_prev;
STATIC VAR(UInt8, AUTOMATIC) tqsys_baosprev_bacv_prev;
STATIC VAR(UInt8, AUTOMATIC) curdrivfil_tqsys_stacceaos_prev;
#define CURDRIVFIL_STOP_SEC_VAR_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_32BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt32, AUTOMATIC) TqSys_tiAOSCur_MP; /* DEC3 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_32BIT
#include "CurDrivFil_MemMap.h"

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facTqAOS_stManGBx; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkRawAOS; /* BIN4 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAOSPrev_bAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bRstAOS_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bRstAOS_tiMaxAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bRstAOS_tqIdl;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bRstAOS_tqMaxCord;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bRstAOS_tqRawSmall;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_nEngHi;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_nEngLo;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_tCoMes;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_tqCordChg;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_tqIdl;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bSetAOS_tqRawHi;
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"



/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQHIAOS_M_APM = {
&tqsys_tqhiaos_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqHiAOS_M[0] [0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQHIDECE_M_APM = {
&tqsys_tqhidece_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqHiDece_M[0] [0]
};

STATIC CONST(t_dds_m_tab2d_us16, AUTOMATIC) TQSYS_TQGEARHICLRCROSS_T_APM = {
&tqsys_tqgearhiclrcross_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqGearHiClrCross_T[0]
};

STATIC CONST(t_dds_m_tab2d_us16, AUTOMATIC) TQSYS_TQGEARSMLCLRCROSS_T_APM = {
&tqsys_tqgearsmlclrcross_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqGearSmlClrCross_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQHIAOS_T_APM = {
&tqsys_tqhiaos_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqHiAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQHICLRCROSS_T_APM = {
&tqsys_tqhiclrcross_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqHiClrCross_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQSMLAOS_T_APM = {
&tqsys_tqsmlaos_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSmlAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQSMLCLRCROSS_T_APM = {
&tqsys_tqsmlclrcross_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSmlClrCross_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQHIDECE_T_APM = {
&tqsys_tqhidece_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkDeceIni_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqHiDece_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQSMLDECE_T_APM = {
&tqsys_tqsmldece_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkDeceIni_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSmlDece_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQSETCORDCHGDECEAOS_T_APM = {
&tqsys_tqsetcordchgdeceaos_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqCkDeceIni_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSetCordChgDeceAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_s16, AUTOMATIC) TQSYS_TQSETCORDCHGAOS_T_APM = {
&tqsys_tqsetcordchgaos_t_sav,
CURDRIVFIL_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqLimEM_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSetCordChgAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_us16, AUTOMATIC) TQSYS_TQMINAOS_T_APM = {
&tqsys_tqminaos_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqMinAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_us16, AUTOMATIC) TQSYS_TQMAXAOS_T_APM = {
&tqsys_tqmaxaos_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqMaxAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_us16, AUTOMATIC) TQSYS_TQMAXIDLAOS_T_APM = {
&tqsys_tqmaxidlaos_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqMaxIdlAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_us16, AUTOMATIC) TQSYS_TQRAWMAXAOS_T_APM = {
&tqsys_tqrawmaxaos_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqRawMaxAOS_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_CTRSTSMALLMAX_T_APM = {
&tqsys_ctrstsmallmax_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_ctRstSmallMax_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_CTSETHIMAX_T_APM = {
&tqsys_ctsethimax_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_ctSetHiMax_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_NHISPDANTISTALL_T_APM = {
&tqsys_nhispdantistall_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nHiSpdAntiStall_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_NLOSPDANTISTALL_T_APM = {
&tqsys_nlospdantistall_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nLoSpdAntiStall_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_TICKRAWAOSFIL_T_APM = {
&tqsys_tickrawaosfil_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiCkRawAOSFil_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TIMAXRSTAOS_M_APM = {
&tqsys_timaxrstaos_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiMaxRstAOS_M[0] [0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_TQSETCHGCLRCROSSAOS_T_APM = {
&tqsys_tqsetchgclrcrossaos_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSetChgClrCrossAOS_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSETCORDCHGAOS_M_APM = {
&tqsys_tqsetcordchgaos_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSetCordChgAOS_M[0] [0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSETCORDCHGDECEAOS_M_APM = {
&tqsys_tqsetcordchgdeceaos_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSetCordChgDeceAOS_M[0] [0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSMLAOS_M_APM = {
&tqsys_tqsmlaos_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSmlAOS_M[0] [0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQSMLDECE_M_APM = {
&tqsys_tqsmldece_m_sav,
TQSYS_9_SIZE,
CURDRIVFIL_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_AOS_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSAcv_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqSmlDece_M[0] [0]
};

#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"



/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_Calc_Aos_torque_corrected(
                                             UInt8  copt_nogearcorddrivfil_par,
                                             UInt8  ext_titdc_par,
                                             SInt16 tqsys_tqckfilrawaos_par,
                                             SInt16 tqsys_faccorglbl_par,
                                             UInt8  tqsys_stacceaos_par);


INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Calc_Aos_active(
                                   UInt8  copt_nogearcorddrivfil_par,
                                   SInt16 copt_tqidcreqcord_nregreq_par,
                                   UInt16 ext_nengclc0_par,
                                   SInt16 ext_tcomes_par,
                                   UInt8  ext_titdc_par,
                                   UInt8  frm_binhaos_par,
                                   SInt16 tqlimem_tqlimemtrv_par,
                                   UInt8  tqsys_baosslopacv_par,
                                   UInt8  tqsys_brstaos_par,
                                   SInt16 tqsys_nfil2aos_par,
                                   UInt8  tqsys_stacceaos_par,
                                   SInt16 tqsys_tqckdeceini_par,
                                   SInt16 tqsys_tqckenglimcord_par,
                                   SInt16 tqsys_tqckidlcord_par,
                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosacv_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_Calc_Aos_set_condition(
                                             UInt8  copt_nogearcorddrivfil_par,
                                             SInt16 copt_tqidcreqcord_nregreq_par,
                                             UInt16 ext_nengclc0_par,
                                             SInt16 ext_tcomes_par,
                                             SInt16 tqlimem_tqlimemtrv_par,
                                             UInt8  tqsys_stacceaos_par,
                                             SInt16 tqsys_tqckdeceini_par,
                                             SInt16 tqsys_tqckenglimcord_par,
                                             SInt16 tqsys_tqckidlcord_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_01_Calc_Aos_set_speed_conds(UInt16 ext_nengclc0_par,
                                                  UInt8 copt_nogearcorddrivfil_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_02_Calc_Aos_set_torque_change(
                                                    UInt8  copt_nogearcorddrivfil_par,
                                                    UInt16 ext_nengclc0_par,
                                                    SInt16 tqlimem_tqlimemtrv_par,
                                                    UInt8  tqsys_stacceaos_par,
                                                    SInt16 tqsys_tqckdeceini_par,
                                                    SInt16 tqsys_tqckenglimcord_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_03_Calc_Aos_set_idle(SInt16 tqsys_tqckidlcord_par,
                                           SInt16 copt_tqidcreqcord_nregreq_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_04_Calc_Aos_set_temp(SInt16 ext_tcomes_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_Calc_Aos_reset_condition(UInt16 ext_nengclc0_par,
                                               UInt8 copt_nogearcorddrivfil_par,
                                               UInt8 ext_titdc_par,
                                               SInt16 tqsys_tqckidlcord_par,
                                               SInt16 copt_tqidcreqcord_nregreq_par,
                                               SInt16 tqsys_tqckenglimcord_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_01_Calc_Aos_Reset_Time_Max (
                                                    UInt8 ext_titdc_par,
                                                    UInt8 copt_nogearcorddrivfil_par,
                                                    UInt16 ext_nengclc0_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_03_Calc_Aos_reset_idle (
                                                UInt8 copt_nogearcorddrivfil_par,
                                                SInt16 tqsys_tqckidlcord_par,
                                                SInt16 copt_tqidcreqcord_nregreq_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_04_Calc_Aos_Reset_No_Torque (SInt16 tqsys_tqckenglimcord_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Calc_Aos_Activation(
                                          UInt8 tqsys_baosslopacv_par,
                                          UInt8 tqsys_brstaos_par,
                                          UInt8 frm_binhaos_par,
                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosacv_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Set_Calculation (
                                   UInt8 tqsys_baosslopacv_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Reset_Calculation (
                                        UInt8 tqsys_brstaos_par,
                                        UInt8 frm_binhaos_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Flip_Ouput_Calculation (
                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosacv_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_04_Calc_Aos_cond_N_torque(
                                    UInt8  copt_nogearcorddrivfil_par,
                                    UInt16 ext_nengclc0_par,
                                    SInt16 tqlimem_tqlimemtrv_par,
                                    SInt16 tqsys_nfil2aos_par,
                                    UInt8  tqsys_stacceaos_par,
                                    SInt16 tqsys_tqckdeceini_par);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Calc_Aos_final_torque(
                                         UInt16 copt_facantijerk_par,
                                         UInt8  copt_nogearcorddrivfil_par,
                                         UInt8  ext_stgbxcf_par,
                                         UInt8  tqsys_baosacv_par,
                                         UInt8  tqsys_baosslopacv_par,
                                         UInt16 tqsys_ctincacvaos_par,
                                         UInt16 tqsys_ctincdiaos_par,
                                         UInt16 tqsys_ctofsacvaos_par,
                                         SInt16 tqsys_faccoridlpha_par,
                                         SInt16 tqsys_faccoroxcheatpha_par,
                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckaoscor_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_01_Calc_Aos_torque_activation(
                                         UInt8  tqsys_baosacv_par,
                                         UInt8  tqsys_baosslopacv_par,
                                         UInt16 tqsys_ctincacvaos_par,
                                         UInt16 tqsys_ctincdiaos_par,
                                         UInt16 tqsys_ctofsacvaos_par);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Final_Curat_Corr
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Final_Curat_Corr(
            UInt16 CoPt_facAntiJerk_swc_in, /* BIN8 */
            UInt8  CoPt_noGearCordDrivFil_swc_in,
            SInt16 CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
            UInt16 Ext_nEngClc0_swc_in, /* BIN2 */
            UInt8  Ext_stGBxCf_swc_in,
            SInt16 Ext_tCoMes_swc_in, /* BIN0 */
            UInt8  Ext_tiTDC_swc_in, /* DEC3 */
            UInt8  FRM_bInhAOS_swc_in,
            SInt16 TqLimEM_tqLimEMTrv_swc_in, /* BIN4 */
            UInt8  TqSys_bAOSSlopAcv_swc_in,
            UInt8  TqSys_bRstAOS_swc_in,
            UInt16 TqSys_ctIncAcvAOS_swc_in, /* BIN10 */
            UInt16 TqSys_ctIncDiAOS_swc_in, /* BIN10 */
            UInt16 TqSys_ctOfsAcvAOS_swc_in, /* BIN10 */
            SInt16 TqSys_facCorGlbl_swc_in, /* BIN4 */
            SInt16 TqSys_facCorIdlPha_swc_in, /* BIN4 */
            SInt16 TqSys_facCorOxCHeatPha_swc_in, /* BIN4 */
            SInt16 TqSys_nFil2AOS_swc_in, /* BIN2 */
            UInt8  TqSys_stAcceAOS_swc_in,
            SInt16 TqSys_tqCkDeceIni_swc_in, /* BIN4 */
            SInt16 TqSys_tqCkEngLimCord_swc_in, /* BIN4 */
            SInt16 TqSys_tqCkFilRawAOS_swc_in, /* BIN4 */
            SInt16 TqSys_tqCkIdlCord_swc_in, /* BIN4 */
            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAOSAcv_swc_out,
            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCor_swc_out /* BIN4 */)
{
    /* SSTG REQ TAG : CSCT_CGMT09_2089.FR.1.1 */
    UInt8 tqsys_baosacv_loc;

    CURDRIVFIL_F01_Calc_Aos_torque_corrected(CoPt_noGearCordDrivFil_swc_in,
                                             Ext_tiTDC_swc_in,
                                             TqSys_tqCkFilRawAOS_swc_in,
                                             TqSys_facCorGlbl_swc_in,
                                             TqSys_stAcceAOS_swc_in);

    CURDRIVFIL_F02_Calc_Aos_active(CoPt_noGearCordDrivFil_swc_in,
                                   CoPt_tqIdcReqCord_nRegReq_swc_in,
                                   Ext_nEngClc0_swc_in,
                                   Ext_tCoMes_swc_in,
                                   Ext_tiTDC_swc_in,
                                   FRM_bInhAOS_swc_in,
                                   TqLimEM_tqLimEMTrv_swc_in,
                                   TqSys_bAOSSlopAcv_swc_in,
                                   TqSys_bRstAOS_swc_in,
                                   TqSys_nFil2AOS_swc_in,
                                   TqSys_stAcceAOS_swc_in,
                                   TqSys_tqCkDeceIni_swc_in,
                                   TqSys_tqCkEngLimCord_swc_in,
                                   TqSys_tqCkIdlCord_swc_in,
                                   &tqsys_baosacv_loc);
    *TqSys_bAOSAcv_swc_out = tqsys_baosacv_loc;

    CURDRIVFIL_F03_Calc_Aos_final_torque(CoPt_facAntiJerk_swc_in,
                                         CoPt_noGearCordDrivFil_swc_in,
                                         Ext_stGBxCf_swc_in,
                                         tqsys_baosacv_loc,
                                         TqSys_bAOSSlopAcv_swc_in,
                                         TqSys_ctIncAcvAOS_swc_in,
                                         TqSys_ctIncDiAOS_swc_in,
                                         TqSys_ctOfsAcvAOS_swc_in,
                                         TqSys_facCorIdlPha_swc_in,
                                         TqSys_facCorOxCHeatPha_swc_in,
                                         TqSys_tqCkAOSCor_swc_out);
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_Calc_Aos_torque_corrected
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_Calc_Aos_torque_corrected(
                                             UInt8  copt_nogearcorddrivfil_par,
                                             UInt8  ext_titdc_par,
                                             SInt16 tqsys_tqckfilrawaos_par,
                                             SInt16 tqsys_faccorglbl_par,
                                             UInt8  tqsys_stacceaos_par)
 {
    /* SSTG REQ TAG : CSCT_CGMT09_2089.FR.2.3 */
    SInt32 curdrivfil_tq_corrected_unlim;
    SInt32 curdrivfil_temp_lim;
    SInt32 tqsys_tqckrawaos_saturated;
    SInt32 tqsys_tqckrawaos_filtered;
    UInt16 turn_off_delay_tdly;
    UInt8 f01_result_turn_off;
    UInt8 count_sel_input;

    /* BIN8 = BIN4 * BIN4 */
    /* [-100000;100000] = [-2000;2000] * [-50;50] */
    curdrivfil_tq_corrected_unlim = (SInt32)tqsys_tqckfilrawaos_par * (SInt32)tqsys_faccorglbl_par;

    curdrivfil_temp_lim = ((SInt32)DDS_M_TAB2D_NEAREST_US16(&TQSYS_TQRAWMAXAOS_T_APM, (UInt16)copt_nogearcorddrivfil_par )) * BIN4;

    /* [-2000;2000] BIN8 */
    tqsys_tqckrawaos_saturated = DDS_M_SATURATION_V2(curdrivfil_tq_corrected_unlim,
                                                     -curdrivfil_temp_lim,
                                                     curdrivfil_temp_lim);

    /* turn off delay calculation */
    turn_off_delay_tdly = (UInt16)((UInt32)DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_TICKRAWAOSFIL_T_APM,(UInt16)copt_nogearcorddrivfil_par) * DEC1);
    if((UInt32)tqsys_stacceaos_par != (UInt32)curdrivfil_tqsys_stacceaos_prev)
    {
        f01_result_turn_off = DDS_M_TURN_OFF_DELAY_DELTA(DDS_TRUE,
                                                         (UInt32)ext_titdc_par, /* DEC3 */
                                                         (UInt32)turn_off_delay_tdly,   /* DEC3 */
                                                         &curdrivfil_f01_calc_off_delay);
    }
    else
    {
        f01_result_turn_off = DDS_M_TURN_OFF_DELAY_DELTA(DDS_FALSE,
                                                         (UInt32)ext_titdc_par, /* DEC3 */
                                                         (UInt32)turn_off_delay_tdly,   /* DEC3 */
                                                         &curdrivfil_f01_calc_off_delay);
    }

    /* memory block */
    /* set ContMltpSwRmpTran input */
    if((UInt32)DDS_FALSE != (UInt32)f01_result_turn_off)
    {
        /* turn_off_delay_tdly = turn_off_delay_tdly; */
        count_sel_input = DDS_FALSE; /* 2 */
        /* curdrivfil_f01_mem_block = curdrivfil_f01_mem_block; */
    }
    else
    {
        turn_off_delay_tdly = 0;
        count_sel_input = DDS_TRUE; /* 1 */
        curdrivfil_f01_mem_block = tqsys_tqckrawaos_saturated;
    }

    tqsys_tqckrawaos_filtered = DDS_M_SOFT_TRANS_DELTA_S32(
            count_sel_input,
            tqsys_tqckrawaos_saturated, /* to get a positive value */
            curdrivfil_f01_mem_block, /* to get a positive value */
            (UInt32)ext_titdc_par,
            (UInt32)turn_off_delay_tdly,
            (UInt32)turn_off_delay_tdly,
            &curdrivfil_f01_trans_structure);


    /* set output */
    if((SInt32)DDS_TRUE != (SInt32)TqSys_bSelAOSTran_C)
    {
        TqSys_tqCkRawAOS = (SInt16)(tqsys_tqckrawaos_filtered / BIN4);
    }
    else
    {
        TqSys_tqCkRawAOS = (SInt16)(tqsys_tqckrawaos_saturated / BIN4);
    }

    curdrivfil_tqsys_stacceaos_prev = tqsys_stacceaos_par;
 }


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_Calc_Aos_active
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Calc_Aos_active(
                                   UInt8  copt_nogearcorddrivfil_par,
                                   SInt16 copt_tqidcreqcord_nregreq_par,
                                   UInt16 ext_nengclc0_par,
                                   SInt16 ext_tcomes_par,
                                   UInt8  ext_titdc_par,
                                   UInt8  frm_binhaos_par,
                                   SInt16 tqlimem_tqlimemtrv_par,
                                   UInt8  tqsys_baosslopacv_par,
                                   UInt8  tqsys_brstaos_par,
                                   SInt16 tqsys_nfil2aos_par,
                                   UInt8  tqsys_stacceaos_par,
                                   SInt16 tqsys_tqckdeceini_par,
                                   SInt16 tqsys_tqckenglimcord_par,
                                   SInt16 tqsys_tqckidlcord_par,
                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosacv_ptr)
{
    /* SSTG REQ TAG : CSCT_CGMT09_2089.FR.3.2 */

    CURDRIVFIL_F02_01_Calc_Aos_set_condition(copt_nogearcorddrivfil_par,
                                             copt_tqidcreqcord_nregreq_par,
                                             ext_nengclc0_par,
                                             ext_tcomes_par,
                                             tqlimem_tqlimemtrv_par,
                                             tqsys_stacceaos_par,
                                             tqsys_tqckdeceini_par,
                                             tqsys_tqckenglimcord_par,
                                             tqsys_tqckidlcord_par);

    CURDRIVFIL_F02_02_Calc_Aos_reset_condition(ext_nengclc0_par,
                                               copt_nogearcorddrivfil_par,
                                               ext_titdc_par,
                                               tqsys_tqckidlcord_par,
                                               copt_tqidcreqcord_nregreq_par,
                                               tqsys_tqckenglimcord_par);

    CURDRIVFIL_F02_04_Calc_Aos_cond_N_torque(
                                    copt_nogearcorddrivfil_par,
                                    ext_nengclc0_par,
                                    tqlimem_tqlimemtrv_par,
                                    tqsys_nfil2aos_par,
                                    tqsys_stacceaos_par,
                                    tqsys_tqckdeceini_par);

	CURDRIVFIL_F02_03_Calc_Aos_Activation(tqsys_baosslopacv_par,
                                          tqsys_brstaos_par,
                                          frm_binhaos_par,
                                          tqsys_baosacv_ptr);
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_01_Calc_Aos_set_condition
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_Calc_Aos_set_condition(
                                             UInt8  copt_nogearcorddrivfil_par,
                                             SInt16 copt_tqidcreqcord_nregreq_par,
                                             UInt16 ext_nengclc0_par,
                                             SInt16 ext_tcomes_par,
                                             SInt16 tqlimem_tqlimemtrv_par,
                                             UInt8  tqsys_stacceaos_par,
                                             SInt16 tqsys_tqckdeceini_par,
                                             SInt16 tqsys_tqckenglimcord_par,
                                             SInt16 tqsys_tqckidlcord_par)
{
    /* SSTG REQ TAG : CSCT_CGMT09_2089.FR.4.1 */

    CURDRIVFIL_F02_01_01_Calc_Aos_set_speed_conds(ext_nengclc0_par,
                                                  copt_nogearcorddrivfil_par);

    CURDRIVFIL_F02_01_02_Calc_Aos_set_torque_change(copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par,
                                                    tqlimem_tqlimemtrv_par,
                                                    tqsys_stacceaos_par,
                                                    tqsys_tqckdeceini_par,
                                                    tqsys_tqckenglimcord_par);

    CURDRIVFIL_F02_01_03_Calc_Aos_set_idle(tqsys_tqckidlcord_par,
                                           copt_tqidcreqcord_nregreq_par);

    CURDRIVFIL_F02_01_04_Calc_Aos_set_temp(ext_tcomes_par);
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_01_01_Calc_Aos_set_speed_conds
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_01_Calc_Aos_set_speed_conds(
                                                  UInt16 ext_nengclc0_par,
                                                  UInt8 copt_nogearcorddrivfil_par)
{
    /* SSTG REQ TAG : CSCT_CGMT09_2089.FR.5.1 */

    UInt16 temp_map_1 = DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_NHISPDANTISTALL_T_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par );

    UInt16 temp_map_2 = DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_NLOSPDANTISTALL_T_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par );


    if ( (UInt32)ext_nengclc0_par <= (UInt32)temp_map_1 )
    {
        TqSys_bSetAOS_nEngHi = DDS_TRUE;
    }
    else
    {
        TqSys_bSetAOS_nEngHi = DDS_FALSE;
    }

    if ( (UInt32)ext_nengclc0_par >= (UInt32)temp_map_2 )
    {
        TqSys_bSetAOS_nEngLo = DDS_TRUE;
    }
    else
    {
        TqSys_bSetAOS_nEngLo = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_01_01_Calc_Aos_set_speed_conds
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_02_Calc_Aos_set_torque_change(
                                                    UInt8  copt_nogearcorddrivfil_par,
                                                    UInt16 ext_nengclc0_par,
                                                    SInt16 tqlimem_tqlimemtrv_par,
                                                    UInt8  tqsys_stacceaos_par,
                                                    SInt16 tqsys_tqckdeceini_par,
                                                    SInt16 tqsys_tqckenglimcord_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.6.3  */
    SInt32 switch_out;
    SInt32 temp_s32;

    switch((UInt32)tqsys_stacceaos_par)
    {
        case CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX:
            /* [-2000;2000]BIN4 */
            switch_out = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSETCORDCHGAOS_M_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            switch_out = switch_out * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQSETCORDCHGAOS_T_APM,
                                                                      tqlimem_tqlimemtrv_par);
            break;

        case CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX:
            /* [0:50]BIN4 */
            switch_out = (SInt32)DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_TQSETCHGCLRCROSSAOS_T_APM,
                                                            (UInt16)copt_nogearcorddrivfil_par);
            /* BIN8 = BIN4 * BIN4 */
            switch_out = switch_out * BIN4;
            break;

        case CURDRIVFIL_DECELERATION:
        default:
            /* [-2000;2000]BIN4 */
            switch_out = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSETCORDCHGDECEAOS_M_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            switch_out = switch_out * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQSETCORDCHGDECEAOS_T_APM,
                                                                      tqsys_tqckdeceini_par);
            break;
    }

    temp_s32 = ((SInt32)tqsys_tqckenglimcord_par - (SInt32)tqsys_tqckenglimcord_prev) * BIN4;
    if ( DDS_M_ABS(temp_s32) >= switch_out )
    {
        TqSys_bSetAOS_tqCordChg = DDS_TRUE;
    }
    else
    {
        TqSys_bSetAOS_tqCordChg = DDS_FALSE;
    }

    tqsys_tqckenglimcord_prev = tqsys_tqckenglimcord_par;
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_01_03_Calc_Aos_set_idle
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_03_Calc_Aos_set_idle(
                                           SInt16 tqsys_tqckidlcord_par,
                                           SInt16 copt_tqidcreqcord_nregreq_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.7.1  */

    if ( (SInt32)tqsys_tqckidlcord_par < ((SInt32)copt_tqidcreqcord_nregreq_par - (SInt32)TqSys_tqSetAOS_nIdl_C) )
    {
        TqSys_bSetAOS_tqIdl = DDS_TRUE;
    }
    else
    {
        TqSys_bSetAOS_tqIdl = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_01_04_Calc_Aos_set_temp
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_01_04_Calc_Aos_set_temp(SInt16 ext_tcomes_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.8.1  */

    if ( (SInt32)ext_tcomes_par >= (SInt32)TqSys_tCoMesMinAOS_C)
    {
        TqSys_bSetAOS_tCoMes = DDS_TRUE;
    }
    else
    {
        TqSys_bSetAOS_tCoMes = DDS_FALSE;
    }
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_02_Calc_Aos_reset_condition
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_Calc_Aos_reset_condition(UInt16 ext_nengclc0_par,
                                               UInt8 copt_nogearcorddrivfil_par,
                                               UInt8 ext_titdc_par,
                                               SInt16 tqsys_tqckidlcord_par,
                                               SInt16 copt_tqidcreqcord_nregreq_par,
                                               SInt16 tqsys_tqckenglimcord_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.9.2  */

    CURDRIVFIL_F02_02_01_Calc_Aos_Reset_Time_Max (  ext_titdc_par,
                                                    copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

    CURDRIVFIL_F02_02_03_Calc_Aos_reset_idle (  copt_nogearcorddrivfil_par,
                                                tqsys_tqckidlcord_par,
                                                copt_tqidcreqcord_nregreq_par);

    CURDRIVFIL_F02_02_04_Calc_Aos_Reset_No_Torque (tqsys_tqckenglimcord_par);
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_02_01_Calc_Aos_Reset_Time_Max
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_01_Calc_Aos_Reset_Time_Max (
                                                    UInt8 ext_titdc_par,
                                                    UInt8 copt_nogearcorddrivfil_par,
                                                    UInt16 ext_nengclc0_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.10.1  */

    UInt32 curdrivfil_temp_time_1; /* DEC3 */
    UInt32 curdrivfil_temp_time_2; /* DEC1 */

    if(((UInt32)DDS_FALSE == (UInt32)TqSys_bAOSPrev_bAcv) && ((UInt32)DDS_FALSE != (UInt32)tqsys_baosprev_bacv_prev))
    {
        TqSys_tiAOSCur_MP = 0 * DEC3 ;
    }
    else if((UInt32)DDS_FALSE != (UInt32)TqSys_bAOSPrev_bAcv)
    {
        /* [0;100]DEC3 */
        TqSys_tiAOSCur_MP = DDS_M_LIMITED_INCREMENT_U32(TqSys_tiAOSCur_MP,
                                                        (UInt16)ext_titdc_par,
                                                        CURDRIVFIL_100_DEC3);
    }
    else
    {
        /* do nothing */
    }

    /* [0,100]DEC3 */
    curdrivfil_temp_time_1 = (UInt32)TqSys_tiMaxRstAOS_C * DEC2;
    curdrivfil_temp_time_1 = DDS_M_MIN(curdrivfil_temp_time_1,
                                       TqSys_tiAOSCur_MP);

    /* [0,100]DEC3 */
    curdrivfil_temp_time_2 = DDS_M_MAP3D_U16(&TQSYS_TIMAXRSTAOS_M_APM,
                                             (UInt16)copt_nogearcorddrivfil_par,
                                             ext_nengclc0_par);
    curdrivfil_temp_time_2 = curdrivfil_temp_time_2 * DEC2;

    if(curdrivfil_temp_time_1 >= curdrivfil_temp_time_2)
    {
       TqSys_bRstAOS_tiMaxAcv = DDS_TRUE;
    }
    else
    {
       TqSys_bRstAOS_tiMaxAcv = DDS_FALSE;
    }

    /* update prev datas */
    tqsys_baosprev_bacv_prev = TqSys_bAOSPrev_bAcv;
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_02_03_Calc_Aos_reset_idle
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_03_Calc_Aos_reset_idle (
                                                UInt8 copt_nogearcorddrivfil_par,
                                                SInt16 tqsys_tqckidlcord_par,
                                                SInt16 copt_tqidcreqcord_nregreq_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.12.1  */

    SInt16 temp_s16;

    if((SInt32)tqsys_tqckidlcord_par > ((SInt32)copt_tqidcreqcord_nregreq_par - (SInt32)TqSys_tqRstAOS_nIdl_C))
    {
        temp_s16 = DDS_M_TAB2D_NEAREST_US16(&TQSYS_TQMAXIDLAOS_T_APM,
                                            (UInt16)copt_nogearcorddrivfil_par );

        if((SInt32)tqsys_tqckidlcord_par > (SInt32)temp_s16)
        {
            TqSys_bRstAOS_tqIdl = DDS_TRUE;
        }
        else
        {
            TqSys_bRstAOS_tqIdl = DDS_FALSE;
        }
    }
    else
    {
        TqSys_bRstAOS_tqIdl = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_02_04_Calc_Aos_Reset_No_Torque
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_02_04_Calc_Aos_Reset_No_Torque (SInt16 tqsys_tqckenglimcord_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.13.1  */

    if ((SInt32)tqsys_tqckenglimcord_par <= (SInt32)TqSys_tqIdCordMaxThd_C)
    {
        TqSys_bRstAOS_tqMaxCord = DDS_TRUE;
    }
    else
    {
        TqSys_bRstAOS_tqMaxCord = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_03_Calc_Aos_Activation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Calc_Aos_Activation(
                                          UInt8 tqsys_baosslopacv_par,
                                          UInt8 tqsys_brstaos_par,
                                          UInt8 frm_binhaos_par,
                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosacv_ptr)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.14.2  */

    CURDRIVFIL_F02_03_Set_Calculation (tqsys_baosslopacv_par);

    CURDRIVFIL_F02_03_Reset_Calculation (tqsys_brstaos_par,
                                         frm_binhaos_par);

    CURDRIVFIL_F02_03_Flip_Ouput_Calculation (tqsys_baosacv_ptr);
}



/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_03_Set_Calculation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Set_Calculation (
                                          UInt8 tqsys_baosslopacv_par)
{
    if(  ((UInt32)DDS_TRUE != (UInt32)tqsys_baosslopacv_par)
       ||((UInt32)DDS_TRUE != (UInt32)TqSys_bSetAOS_nEngHi)
       ||((UInt32)DDS_TRUE != (UInt32)TqSys_bSetAOS_nEngLo)
       ||((UInt32)DDS_TRUE != (UInt32)TqSys_bSetAOS_tCoMes)
       ||(  ((SInt32)DDS_TRUE != (SInt32)TqSys_bAOSIdlEna_C)
          &&((UInt32)DDS_TRUE != (UInt32)TqSys_bSetAOS_tqIdl)))
    {
        TqSys_bSetAOS_MP = DDS_FALSE;
    }
    else
    {
        switch((UInt32)TqSys_facSelSetAOS_C)
        {
            case (UInt32)1:
                if(  ((UInt32)DDS_FALSE != (UInt32)TqSys_bSetAOS_tqCordChg)
                   ||((UInt32)DDS_FALSE != (UInt32)TqSys_bSetAOS_tqRawHi))
                {
                    TqSys_bSetAOS_MP = DDS_TRUE;
                }
                else
                {
                    TqSys_bSetAOS_MP = DDS_FALSE;
                }
                break;
            case (UInt32)2:
                TqSys_bSetAOS_MP = TqSys_bSetAOS_tqCordChg;
                break;
            case (UInt32)0:
            default:
                TqSys_bSetAOS_MP = TqSys_bSetAOS_tqRawHi;
                break;
        }
    }
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_03_Reset_Calculation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Reset_Calculation (
                                        UInt8 tqsys_brstaos_par,
                                        UInt8 frm_binhaos_par)
{
    if(  (  ((SInt32)DDS_FALSE == (SInt32)TqSys_bAOS_tiMaxEna_C)
          &&((UInt32)DDS_FALSE != (UInt32)TqSys_bRstAOS_tiMaxAcv))
       ||((UInt32)DDS_FALSE != (UInt32)TqSys_bRstAOS_tqRawSmall)
       ||(  ((SInt32)DDS_FALSE == (SInt32)TqSys_bAOSIdlEna_C)
          &&((UInt32)DDS_FALSE != (UInt32)TqSys_bRstAOS_tqIdl))
       ||((UInt32)DDS_FALSE != (UInt32)TqSys_bRstAOS_tqMaxCord)
       ||((UInt32)DDS_FALSE != (UInt32)tqsys_brstaos_par)
       ||((SInt32)DDS_FALSE != (SInt32)TqSys_bDiAOS_C)
       ||((UInt32)DDS_FALSE != (UInt32)frm_binhaos_par))
    {
        TqSys_bRstAOS_MP = DDS_TRUE;
    }
    else
    {
        TqSys_bRstAOS_MP = DDS_FALSE;
    }

}

/*******************************************************************************
*
* Function Name : TQS_F02_03_Flip_Ouput_Calculation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_03_Flip_Ouput_Calculation (
                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_baosacv_ptr)
{
    TqSys_bAOSPrev_bAcv = tqsys_baosacv_prev;
    /* Reset priority */
    if ((UInt32)DDS_FALSE != (UInt32)TqSys_bRstAOS_MP)
    {
        /* Reset value */
        tqsys_baosacv_prev = DDS_FALSE;
    }
    else if ((UInt32)DDS_FALSE != (UInt32)TqSys_bSetAOS_MP)
    {
        /* Set value */
        tqsys_baosacv_prev = DDS_TRUE;
    }
    else
    {
        /* Keep previous value */
    }
    *tqsys_baosacv_ptr = tqsys_baosacv_prev;
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_04_Calc_Aos_cond_N_torque
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_04_Calc_Aos_cond_N_torque(
                                    UInt8  copt_nogearcorddrivfil_par,
                                    UInt16 ext_nengclc0_par,
                                    SInt16 tqlimem_tqlimemtrv_par,
                                    SInt16 tqsys_nfil2aos_par,
                                    UInt8  tqsys_stacceaos_par,
                                    SInt16 tqsys_tqckdeceini_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.16.1  */
    SInt32 hysteresys_high;
    SInt32 hysteresys_low;
    SInt32 hysteresys_input;
    UInt16 temp_u16;
    UInt8 hysteresys_output;
    UInt8 negative_edge_input_0;
    UInt8 negative_edge_input_1;
    UInt8 negative_edge_result_0;
    UInt8 negative_edge_result_1;

    switch((UInt32)tqsys_stacceaos_par)
    {
        case CURDRIVFIL_ACCELERATION_AU_DESSUS_DES_JEUX:
            /* --- Hysteresys High Calculation --- */
            /* [-2000;2000]BIN4 */
            hysteresys_high = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQHIAOS_M_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            hysteresys_high = hysteresys_high * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQHIAOS_T_APM,
                                                                              tqlimem_tqlimemtrv_par);


            /* --- Hysteresys Low Calculation --- */
            /* [-2000;2000]BIN4 */
            hysteresys_low = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSMLAOS_M_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            hysteresys_low = hysteresys_low * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQSMLAOS_T_APM,
                                                                      tqlimem_tqlimemtrv_par);
            break;

        case CURDRIVFIL_ACCELERATION_EN_DESSOUS_DES_JEUX:
            /* --- Hysteresys High Calculation --- */
            /* [-2000;2000]BIN4 */
            hysteresys_high = (SInt32)DDS_M_TAB2D_NEAREST_US16(&TQSYS_TQGEARHICLRCROSS_T_APM,
                                                              (UInt16)copt_nogearcorddrivfil_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            hysteresys_high = hysteresys_high * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQHICLRCROSS_T_APM,
                                                                                tqlimem_tqlimemtrv_par);


            /* --- Hysteresys Low Calculation --- */
            /* [-2000;2000]BIN4 */
            hysteresys_low = (SInt32)DDS_M_TAB2D_NEAREST_US16(&TQSYS_TQGEARSMLCLRCROSS_T_APM,
                                                              (UInt16)copt_nogearcorddrivfil_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            hysteresys_low = hysteresys_low * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQSMLCLRCROSS_T_APM,
                                                                              tqlimem_tqlimemtrv_par);
            break;

        case CURDRIVFIL_DECELERATION:
        default:
            /* --- Hysteresys High Calculation --- */
            /* [-2000;2000]BIN4 */
            hysteresys_high = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQHIDECE_M_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            hysteresys_high = hysteresys_high * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQHIDECE_T_APM,
                                                                              tqsys_tqckdeceini_par);


            /* --- Hysteresys Low Calculation --- */
            /* [-2000;2000]BIN4 */
            hysteresys_low = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQSMLDECE_M_APM,
                                                   (UInt16)copt_nogearcorddrivfil_par,
                                                    ext_nengclc0_par);

            /* BIN8 = BIN4 * BIN4 */
            /* [-4000000;4000000] = [-2000;2000] * [-2000;2000]*/
            hysteresys_low = hysteresys_low * (SInt32)DDS_M_TAB2D_NEAREST_S16(&TQSYS_TQSMLDECE_T_APM,
                                                                      tqsys_tqckdeceini_par);
            break;
    }

    if((SInt32)DDS_TRUE != (SInt32)TqSys_bSelCdnAOS_C)
    {
        hysteresys_input = (SInt32)TqSys_tqCkRawAOS;
    }
    else
    {
        hysteresys_input = (SInt32)tqsys_nfil2aos_par * BIN2;
    }

    /* BIN14 = BIN4 * BIN10 */
    /* [-8000;8000] = [-8000;8000] * [0;1] */
    hysteresys_input = DDS_M_ABS(hysteresys_input) * (SInt32)TqSys_facCnvNFil2_C;
    /* BIN8 = BIN14 / BIN6 */
    hysteresys_input = hysteresys_input / BIN6;


    hysteresys_output = DDS_M_HYST_PH_S32(&curdrivfil_f02_04_calc_aos_hyst_struct,
                                         hysteresys_input,
                                         hysteresys_high,
                                         hysteresys_low);

    if((UInt32)DDS_TRUE != (UInt32)hysteresys_output)
    {
        negative_edge_input_0 = TqSys_bAOSPrev_bAcv;
        negative_edge_input_1 = DDS_FALSE;
    }
    else
    {
        negative_edge_input_0 = DDS_FALSE;
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bSetAOS_tiEna_C )
        {
            negative_edge_input_1 = DDS_TRUE;
        }
        else
        {
			if((UInt32)DDS_FALSE != (UInt32)TqSys_bAOSPrev_bAcv)
			{
				negative_edge_input_1 = DDS_FALSE;
			}
			else
            {
				negative_edge_input_1 = DDS_TRUE;
			}
        }
    }

    /* --- TqSys_bRstAOS_tqRawSmall calculation --- */
    negative_edge_result_0 = DDS_M_NEGATIVE_EDGE_DETECT(&curdrivfil_f02_04_p_edge_0,
                                                        negative_edge_input_0);

    if((UInt32)DDS_TRUE == (UInt32)negative_edge_result_0)
	{
		curdrivfil_f02_04_aos_cnt_0 = (SInt16)CURDRIVFIL_0;
	}
	else if((UInt32)DDS_TRUE == (UInt32)negative_edge_input_0)
	{
		curdrivfil_f02_04_aos_cnt_0 = (SInt16)DDS_M_LIMITED_INCREMENT_S32((SInt32)curdrivfil_f02_04_aos_cnt_0,
																		  (UInt16)1,
																		  (SInt32)CURDRIVFIL_400_BIN0);
	}
	else
	{
		/* nothing to do */
	}



    /* [0;255]BIN0 */
    temp_u16 = DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_CTRSTSMALLMAX_T_APM,
                                          (UInt16)copt_nogearcorddrivfil_par);

    if((SInt32)temp_u16 > (SInt32)curdrivfil_f02_04_aos_cnt_0)
    {
        TqSys_bRstAOS_tqRawSmall = DDS_FALSE;
    }
    else
    {
        TqSys_bRstAOS_tqRawSmall = DDS_TRUE;
    }


    /* --- TqSys_bSetAOS_tqRawHi calculation --- */
    negative_edge_result_1 = DDS_M_NEGATIVE_EDGE_DETECT(&curdrivfil_f02_04_p_edge_1,
                                                        negative_edge_input_1);

    if((UInt32)DDS_TRUE == (UInt32)negative_edge_result_1)
	{
		curdrivfil_f02_04_aos_cnt_1 = (SInt16)CURDRIVFIL_0;
	}
	else if((UInt32)DDS_TRUE == (UInt32)negative_edge_input_1)
	{
		curdrivfil_f02_04_aos_cnt_1 = (SInt16)DDS_M_LIMITED_INCREMENT_S32((SInt32)curdrivfil_f02_04_aos_cnt_1,
																		  (UInt16)1,
																		  (SInt32)CURDRIVFIL_400_BIN0);
	}
	else
	{
		/* nothing to do */
	}

    /* [0;255]BIN0 */
    temp_u16 = DDS_M_TAB2D_NEAREST_U16_V2(&TQSYS_CTSETHIMAX_T_APM,
                                          (UInt16)copt_nogearcorddrivfil_par);

    if((SInt32)temp_u16 > (SInt32)curdrivfil_f02_04_aos_cnt_1)
    {
        TqSys_bSetAOS_tqRawHi = DDS_FALSE;
    }
    else
    {
        TqSys_bSetAOS_tqRawHi = DDS_TRUE;
    }
}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_Calc_Aos_final_torque
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Calc_Aos_final_torque(
                                         UInt16 copt_facantijerk_par,
                                         UInt8  copt_nogearcorddrivfil_par,
                                         UInt8  ext_stgbxcf_par,
                                         UInt8  tqsys_baosacv_par,
                                         UInt8  tqsys_baosslopacv_par,
                                         UInt16 tqsys_ctincacvaos_par,
                                         UInt16 tqsys_ctincdiaos_par,
                                         UInt16 tqsys_ctofsacvaos_par,
                                         SInt16 tqsys_faccoridlpha_par,
                                         SInt16 tqsys_faccoroxcheatpha_par,
                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckaoscor_ptr)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.15.2  */
    t_dds_m_sint64 temp_s64;
    UInt32 result_switch;
    SInt32 result_final;
    SInt16 high_lim;
    SInt16 low_lim;

    CURDRIVFIL_F03_01_Calc_Aos_torque_activation(tqsys_baosacv_par,
                                                 tqsys_baosslopacv_par,
                                                 tqsys_ctincacvaos_par,
                                                 tqsys_ctincdiaos_par,
                                                 tqsys_ctofsacvaos_par);

    high_lim = DDS_M_TAB2D_NEAREST_US16(&TQSYS_TQMAXAOS_T_APM,
                                        (UInt16)copt_nogearcorddrivfil_par);

    low_lim = DDS_M_TAB2D_NEAREST_US16(&TQSYS_TQMINAOS_T_APM,
                                        (UInt16)copt_nogearcorddrivfil_par);

    if(  (BVM != (UInt32)ext_stgbxcf_par)
       &&((SInt32)DDS_FALSE == (SInt32)TqSys_bCorManGBx_C) )
    {
        /* BIN10 [0;1] = MIN ( (BIN8*BIN2 [0;1]) ; BIN10 [0;1] ) */
        result_switch = (UInt32)copt_facantijerk_par * BIN2;
        result_switch = DDS_M_MIN(result_switch, (UInt32)TqSys_facTqAOS_stManGBx);
    }
    else
    {
        /* BIN10 [0;1] */
        result_switch = (UInt32)TqSys_facTqAOS_stManGBx;
    }

    /****************************************************************/

    /* BIN22 = BIN10 * BIN4 * BIN4 * BIN4 */
    /* [-200000;200000] = [0;1] * [-2000;2000] * [-10;10] * [-10;10] */
    temp_s64 =  (t_dds_m_sint64)result_switch
              * (t_dds_m_sint64)TqSys_tqCkRawAOS
              * (t_dds_m_sint64)tqsys_faccoroxcheatpha_par
              * (t_dds_m_sint64)tqsys_faccoridlpha_par;

    /* BIN4 = BIN22 / BIN18 */
    result_final = (SInt32)(temp_s64 / (t_dds_m_sint64)BIN18);

    result_final = DDS_M_SATURATION_V2(result_final,
                                       (SInt32)low_lim,
                                       (SInt32)high_lim);

    *tqsys_tqckaoscor_ptr = (SInt16)DDS_M_MIN(result_final, (SInt32)TqSys_tqMaxSafety_C);
}

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_01_Calc_Aos_torque_activation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_01_Calc_Aos_torque_activation(
                                         UInt8  tqsys_baosacv_par,
                                         UInt8  tqsys_baosslopacv_par,
                                         UInt16 tqsys_ctincacvaos_par,
                                         UInt16 tqsys_ctincdiaos_par,
                                         UInt16 tqsys_ctofsacvaos_par)
{
    /* SSTG_REQ_TAG: CSCT_CGMT09_2089.FR.17.1 */
    t_dds_m_edge_detected_event pfl_edge_result;
    UInt32 temp_u32;
    SInt32	temp_0_s32;
    UInt8 tqsys_baosena;
    UInt16 tqsys_factqaos_stmangbx_prev;

    UInt16 tqsys_facacvtqantiosc_stmangbx;
    UInt16 tqsys_facditqantiosc_stmangbx;

    tqsys_factqaos_stmangbx_prev = (UInt16)TqSys_facTqAOS_stManGBx;

    if((SInt32)DDS_TRUE != (SInt32)TqSys_bAOSSlopAcv_C)
    {
        tqsys_baosena = tqsys_baosslopacv_par;
    }
    else
    {
        tqsys_baosena = tqsys_baosacv_par;
    }

    pfl_edge_result = DDS_M_EDGE_DETECT(&curdrivfil_f03_01_edgedetect_ptr,
                                        tqsys_baosena);

    if((UInt32)DDS_TRUE != (UInt32)tqsys_baosacv_par)
    {
        if((UInt32)tqsys_factqaos_stmangbx_prev != CURDRIVFIL_0)
        {
            /* [-1;1]BIN10 = [0;1]BIN10 - [0;1]BIN10 */
            temp_0_s32 = (SInt32)tqsys_factqaos_stmangbx_prev - (SInt32)tqsys_ctincdiaos_par;

            /* [0;1]BIN10 */
            tqsys_facditqantiosc_stmangbx = (UInt16)DDS_M_LIMIT(temp_0_s32,
            												(SInt32)CURDRIVFIL_0_BIN10,
                                                            (SInt32)CURDRIVFIL_1_BIN10);
        }
        else
        {
            tqsys_facditqantiosc_stmangbx = (UInt16)CURDRIVFIL_0;
        }
        TqSys_facTqAOS_stManGBx = (SInt16)tqsys_facditqantiosc_stmangbx;
    }
    else
    {
        if(  (CURDRIVFIL_1_BIN10 == (UInt32)tqsys_factqaos_stmangbx_prev)
           ||(  ((UInt32)DDS_TRUE == (UInt32)tqsys_baosslopacv_par)
              &&(DDS_M_POSITIVE_EDGE_DETECTED == pfl_edge_result)))
        {
            tqsys_facacvtqantiosc_stmangbx = (UInt16)CURDRIVFIL_1_BIN10;
        }
        else
        {
            /* [0;2]BIN10 = [0;1]BIN10 + [0;1]BIN10 */
            temp_u32 = (UInt32)tqsys_factqaos_stmangbx_prev + (UInt32)tqsys_ctincacvaos_par;
            if(DDS_M_POSITIVE_EDGE_DETECTED == pfl_edge_result)
            {
                /* [0;2]BIN10 */
                temp_u32 = DDS_M_MAX(temp_u32,(UInt32)tqsys_ctofsacvaos_par);
            }
            else
            {
                /* Nothing to do */
            }

            tqsys_facacvtqantiosc_stmangbx = (UInt16)DDS_M_MIN(temp_u32,
                                                               CURDRIVFIL_1_BIN10);
        }

        TqSys_facTqAOS_stManGBx = (SInt16)tqsys_facacvtqantiosc_stmangbx;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Final_Curat_Corr_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Final_Curat_Corr_Init(
            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAOSAcv_swc_out,
            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCor_swc_out /* BIN4 */)
{
    /* ---- Init Global Datas ---- */

    /* --- CURDRIVFIL_F01_Calc_Aos_torque_corrected --- */
    TqSys_tqCkRawAOS = (SInt16)(0 * BIN4);
    curdrivfil_tqsys_stacceaos_prev = (UInt8)CURDRIVFIL_DECELERATION;
    curdrivfil_f01_mem_block = 0;
    DDS_M_TURN_OFF_DELAY_DELTA_INIT(DDS_FALSE,
                                    &curdrivfil_f01_calc_off_delay);

    (void)DDS_M_SOFT_TRANS_DELTA_S32_INIT(DDS_FALSE,                            /* E -> Boolean */
                                        (SInt32)1* BIN8,                        /* Val 0 */
                                        (SInt32)0* BIN8,                        /* Val 1 BIN4[0;50] */
                                        /*DDS_CURDRIVFIL_1MS_U32_TIME,         Current time */
                                        (UInt8*)DDS_NULL_PTR,
                                        &curdrivfil_f01_trans_structure);     /* Pointer to structure */

    /* --- CURDRIVFIL_F02_Calc_Aos_active --- */

    /* --- CURDRIVFIL_F02_01_01_Calc_Aos_set_speed_conds --- */
    TqSys_bSetAOS_nEngHi        = DDS_FALSE;
    TqSys_bSetAOS_nEngLo        = DDS_FALSE;

    /* --- CURDRIVFIL_F02_01_02_Calc_Aos_set_torque_change --- */
    TqSys_bSetAOS_tqCordChg     = DDS_FALSE;
    tqsys_tqckenglimcord_prev = (SInt16)(0 * BIN4);

    /* --- CURDRIVFIL_F02_01_03_Calc_Aos_set_idle --- */
    TqSys_bSetAOS_tqIdl         = DDS_FALSE;

    /* --- CURDRIVFIL_F02_01_04_Calc_Aos_set_temp --- */
    TqSys_bSetAOS_tCoMes        = DDS_FALSE;

    /* --- CURDRIVFIL_F02_01_Calc_Aos_set_condition --- */

    /* --- CURDRIVFIL_F02_02_01_Calc_Aos_Reset_Time_Max  --- */
    TqSys_bRstAOS_tiMaxAcv      = DDS_FALSE;
    TqSys_tiAOSCur_MP = (UInt32)(0 * DEC3);
    tqsys_baosprev_bacv_prev = DDS_FALSE;

    /* --- CURDRIVFIL_F02_02_03_Calc_Aos_reset_idle  --- */
    TqSys_bRstAOS_tqIdl         = DDS_FALSE;

    /* --- CURDRIVFIL_F02_02_04_Calc_Aos_Reset_No_Torque --- */
    TqSys_bRstAOS_tqMaxCord     = DDS_FALSE;

    /* --- CURDRIVFIL_F02_02_Calc_Aos_reset_condition --- */

    /* --- CURDRIVFIL_F02_03_Calc_Aos_Activation --- */
    *TqSys_bAOSAcv_swc_out = DDS_FALSE;
    TqSys_bAOSPrev_bAcv         = DDS_FALSE;
    TqSys_bRstAOS_MP            = DDS_FALSE;
    TqSys_bSetAOS_MP            = DDS_FALSE;
    tqsys_baosacv_prev = DDS_FALSE;

    /* --- CURDRIVFIL_F02_04_Calc_Aos_cond_N_torque --- */
    TqSys_bRstAOS_tqRawSmall    = DDS_FALSE;
    TqSys_bSetAOS_tqRawHi       = DDS_FALSE;

    (void)DDS_M_HYST_S32_INIT(&curdrivfil_f02_04_calc_aos_hyst_struct, DDS_FALSE);
    curdrivfil_f02_04_aos_cnt_0 = (SInt16)CURDRIVFIL_0;
    curdrivfil_f02_04_aos_cnt_1 = (SInt16)CURDRIVFIL_0;
    (void)DDS_M_POS_NEG_EDGE_DETECT_INIT(&curdrivfil_f02_04_p_edge_0, DDS_FALSE);
    (void)DDS_M_POS_NEG_EDGE_DETECT_INIT(&curdrivfil_f02_04_p_edge_1, DDS_FALSE);

    /* --- CURDRIVFIL_F03_Calc_Aos_final_torque --- */
    *TqSys_tqCkAOSCor_swc_out = (SInt16)(0 * BIN4);

    /* --- CURDRIVFIL_F03_01_Calc_Aos_torque_activation --- */
    (void)DDS_M_POS_NEG_EDGE_DETECT_INIT(&curdrivfil_f03_01_edgedetect_ptr,DDS_FALSE);
    TqSys_facTqAOS_stManGBx = (SInt16)(0 * BIN10);
}

#define CURDRIVFIL_STOP_SEC_CODE
#include "CurDrivFil_MemMap.h"

