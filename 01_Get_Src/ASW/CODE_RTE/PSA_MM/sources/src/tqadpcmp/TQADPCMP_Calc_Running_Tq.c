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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Calc_Running_Tq.c
* Version int :/main/L03_01/1 Date: 21/3/2012 15 h 8 m User:esnault 
*    TWK_model:TQADPCMP_Calc_Running_Tq_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 2/3/2012 10 h 1 m User:halouane 
*    TWK_model:TQADPCMP_Calc_Running_Tq_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_02/2 Date: 15/9/2011 9 h 57 m User:esnault
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_020_IMPL3_D
*    comments :correction ALTIS_1638552/FDS A0202589
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 15/9/2011 9 h 32 m User:lemort
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_020_IMPL3_D
*    comments :correction ALTIS_1638552/FDS A0202589
* Version int :/main/L02_02/1 Date: 22/6/2011 17 h 24 m User:esnault
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_020_IMPL3
*    comments :TU corrections
* Version dev :\main\branch_lemort_tqadpcmp_dev\3 Date: 21/6/2011 12 h 0 m User:lemort
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_020_IMPL3
*    comments :TU corrections
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 16/6/2011 9 h 44 m User:lemort
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_020_IMPL2
*    comments :TU corrections
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 9/6/2011 14 h 56 m User:lemort
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_020_IMPL1
*    comments :for CSMT_CGMT06_2117 v8_1
* Version int :/main/L02_01/1 Date: 18/11/2010 12 h 49 m User:meme
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 17/11/2010 16 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 16/11/2010 17 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L02_010_IMPL1
*    comments :For TqAdpCmp 10.2
* Version int :/main/L01_01/3 Date: 12/10/2010 9 h 45 m User:meme
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1_D
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 8/10/2010 14 h 42 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1_D
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 8/10/2010 14 h 37 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1_D
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 7/10/2010 9 h 3 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1_D
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 6/10/2010 18 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1_D
*    comments :for TqAdpCmp
* Version int :/main/L01_01/2 Date: 13/9/2010 17 h 20 m User:esnault
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\14 Date: 13/9/2010 16 h 55 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 18 m User:esnault
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\13 Date: 13/9/2010 9 h 59 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\12 Date: 10/9/2010 10 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\11 Date: 9/9/2010 17 h 27 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 2/8/2010 12 h 15 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 22/7/2010 16 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 9/7/2010 16 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 8/7/2010 18 h 4 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 25/6/2010 14 h 3 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 24/6/2010 17 h 45 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 21 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Running_Tq_L01_010_IMPL1
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

#define TQADPCMP_TISCHED                      10    /* DEC3 */
/*copt_stdragred*/
#define COPT_STDRAGRED_PARK_OU_N            (UInt32)0
#define COPT_STDRAGRED_DEBRAYE_A_LARRET     (UInt32)1
#define COPT_STDRAGRED_INFO_INDISPONIBLE    (UInt32)3


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRedIni[TQADPCMP_8_SIZE]; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeutIni[TQADPCMP_8_SIZE]; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnIrvAC; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqAdp_bDragRed;
extern VAR(UInt8, AUTOMATIC) TqAdp_idxTEng; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnIrvAC;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"



/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* 16-bits calibrations definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTEng_A[TQADPCMP_8_SIZE]; /* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTqAccu_A[TQADPCMP_10_SIZE]; /* BIN0 */
#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"



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
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRed[TQADPCMP_8_SIZE]; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeut[TQADPCMP_8_SIZE]; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnAC; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnDragRed;
VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNeut;
VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnWoutAC;
VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnCdnAC;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 32-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_32BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) TqAdp_tiDlyACDeac_C = (CONST(UInt32, AUTOMATIC))(0.5 * DEC2);
#define TQADPCMP_STOP_SEC_CALIB_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_nEngMvMax_C = (CONST(UInt16, AUTOMATIC))(1100 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_nEngMvStabThd_C = (CONST(UInt16, AUTOMATIC))(50 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_spdVehThd_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_tiDlyAst_C = (CONST(UInt16, AUTOMATIC))(5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_tiNEngMvStab_C = (CONST(UInt16, AUTOMATIC))(0.5 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnACMax_C = (CONST(SInt16, AUTOMATIC))(20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnACMin_C = (CONST(SInt16, AUTOMATIC))(-20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutMax_C = (CONST(SInt16, AUTOMATIC))(20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutMin_C = (CONST(SInt16, AUTOMATIC))(-20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqThdHysACDeac_C = (CONST(SInt16, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedMax_C = (CONST(SInt16, AUTOMATIC))(20 * BIN9);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedMin_C = (CONST(SInt16, AUTOMATIC))(-20 * BIN9);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bCluCfSel_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_tiDlyCdn_C = (CONST(UInt8, AUTOMATIC))(2 * DEC0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_tiDlyDirAsiDeac_C = (CONST(UInt8, AUTOMATIC))(0.5 * DEC1);
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_facFilTqCkIdl_C = (CONST(UInt8, AUTOMATIC))(0.1 * BIN7);
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_bAuthAdpAC_T
[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_bAuthAdpTqAccuOn_T
[TQADPCMP_10_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_bFrzAdpElProdOn_T
[TQADPCMP_4_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_idxDragRedGain_T
[TQADPCMP_8_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_idxNeutGain_T
[TQADPCMP_8_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_nEngMvGrdMax_T
[TQADPCMP_2_SIZE] = {
(UInt16)(30 * BIN2), (UInt16)(30 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcDragRedGain1_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcDragRedGain2_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcDragRedGain3_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcNeutGain1_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcNeutGain2_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcNeutGain3_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rEfcACGain_M
[TQADPCMP_7_SIZE][TQADPCMP_7_SIZE] = {
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) },
{
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18), (UInt16)(0.002 * BIN18),
(UInt16)(0.002 * BIN18) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_stElProd_A[TQADPCMP_4_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tCoMes_A[TQADPCMP_2_SIZE] = {
(SInt16)(0 * BIN2), (SInt16)(90 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqACThd_T
[TQADPCMP_8_SIZE] = {
(SInt16)(3 * BIN4), (SInt16)(3 * BIN4), (SInt16)(3 * BIN4),
(SInt16)(3 * BIN4), (SInt16)(3 * BIN4), (SInt16)(3 * BIN4),
(SInt16)(3 * BIN4), (SInt16)(3 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnThdAC_T
[TQADPCMP_8_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnThdDragRed_T
[TQADPCMP_8_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnThdNeut_T
[TQADPCMP_8_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqEfcACX_A[TQADPCMP_7_SIZE] = {
(SInt16)(-30 * BIN4), (SInt16)(-15 * BIN4), (SInt16)(-5 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(15 * BIN4),
(SInt16)(30 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqDeltaACY_A[TQADPCMP_7_SIZE] = {
(SInt16)(-30 * BIN4), (SInt16)(-15 * BIN4), (SInt16)(-5 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(15 * BIN4),
(SInt16)(30 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqDeltaDragRedY_A[TQADPCMP_7_SIZE] = {
(SInt16)(-30 * BIN9), (SInt16)(-15 * BIN9), (SInt16)(-5 * BIN9),
(SInt16)(0 * BIN9), (SInt16)(5 * BIN9), (SInt16)(15 * BIN9),
(SInt16)(30 * BIN9)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqDeltaNeutY_A[TQADPCMP_7_SIZE] = {
(SInt16)(-30 * BIN9), (SInt16)(-15 * BIN9), (SInt16)(-5 * BIN9),
(SInt16)(0 * BIN9), (SInt16)(5 * BIN9), (SInt16)(15 * BIN9),
(SInt16)(30 * BIN9)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqDeltaTqIdlTqLoss_T
[TQADPCMP_8_SIZE] = {
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqEfcDragRedX_A[TQADPCMP_7_SIZE] = {
(SInt16)(-30 * BIN4), (SInt16)(-15 * BIN4), (SInt16)(-5 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(15 * BIN4),
(SInt16)(30 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqEfcNeutX_A[TQADPCMP_7_SIZE] = {
(SInt16)(-30 * BIN4), (SInt16)(-15 * BIN4), (SInt16)(-5 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(15 * BIN4),
(SInt16)(30 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqThdDragRedAC_T
[TQADPCMP_8_SIZE] = {
(SInt16)(20 * BIN4), (SInt16)(20 * BIN4), (SInt16)(20 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(20 * BIN4), (SInt16)(20 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(20 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqThdNeutAC_T
[TQADPCMP_8_SIZE] = {
(SInt16)(20 * BIN4), (SInt16)(20 * BIN4), (SInt16)(20 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(20 * BIN4), (SInt16)(20 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(20 * BIN4)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_bauthadpac_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_bauthadptqaccuon_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_bfrzadpelprodon_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_idxdragredgain_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_idxneutgain_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_nengmvgrdmax_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcdragredgain1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcdragredgain2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcdragredgain3_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcacgain_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcneutgain1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcneutgain2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqadp_refcneutgain3_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqacthd_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqcorlrnthdac_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqcorlrnthddragred_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqcorlrnthdneut_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqdeltatqidltqloss_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqthddragredac_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqthdneutac_t_sav;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_01_02_02_01_01_01_turn_on_delay;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_01_02_02_01_01_02_turn_off_delay;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_01_02_02_01_01_04_turn_on_delay;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) tqadpcmp_01_02_02_01_02_hyst;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_01_02_02_01_02_turn_off_delay;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_01_02_02_01_04_03_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_01_02_02_01_05_03_edge_detect;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) filter_12213_str;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqadpcmp_01_02_02_01_01_01_eng_nckfil_dly;
STATIC VAR(SInt16, AUTOMATIC) tqadpcmp_01_02_02_02_02_dly1;
STATIC VAR(SInt16, AUTOMATIC) tqadpcmp_tqdeltadb_dly;
#define TQADPCMP_STOP_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_02_01_01_03_bdragred_dly;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_02_01_04_03_switch_dly;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_02_01_05_03_switch_dly;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_04_02_prm_dly_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_05_02_prm_dly_init;
STATIC VAR(UInt8, AUTOMATIC) tqadp_idxteng_loc; /* BIN0 */
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdragred_loc;
STATIC VAR(UInt8, AUTOMATIC) filter_12213_is_initialised;
STATIC VAR(UInt8, AUTOMATIC) tqadp_tqcorlrnac_is_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/


/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRedOn[TQADPCMP_8_SIZE]; /* BIN9 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeutOn[TQADPCMP_8_SIZE]; /* BIN9 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedOn; /* BIN9 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnIrvACPrev; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutOn; /* BIN9 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqDeltaDB; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqDeltaTqIdlTqLoss_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqEfcAC_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqEfcDragRed_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqEfcNeut_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqAdp_nDeltaNEngNTarIdl_MP; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqAdp_nEngMvGrdMax_MP; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqAdp_nGrdNEng_MP; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqAdp_rEfcACGain_MP; /* BIN9 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqAdp_rEfcDragRedGain_MP; /* BIN9 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqAdp_rEfcNeutGain_MP; /* BIN9 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCkIdlFil_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqDeltaAC_MP; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"


/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bAcvAdp_MP;
/* <PRQA_COMMENT><3229> use only as mesure point </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnAC;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnDragRedAC;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnDragRedCdn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnIrvACPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNEngMvCdn1_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNEngMvCdn2_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNEngMvCdn3_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNeutAC;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNeutCdn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNEngMvCdn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bAuxOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bAuthAdpGBx;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bSyntCorLrnCdnAC;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/* 32-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_32BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_tqCorLrnDragRedSel_MP; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_tqCorLrnNeutSel_MP; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_tqDeltaDragRed_MP; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_tqDeltaNeut_MP; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_prm_tqCorLrnDragRedPrev[TQADPCMP_8_SIZE]; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_prm_tqCorLrnNeutPrev[TQADPCMP_8_SIZE]; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_prm_tqLrnDragRedOn_MP[TQADPCMP_8_SIZE]; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_prm_tqLrnNeutOn_MP[TQADPCMP_8_SIZE]; /* BIN18 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqAdp_tqLrnAC_MP;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_32BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_BAUTHADPAC_T_APM = {
&tqadp_bauthadpac_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_bAuthAdpAC_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_BAUTHADPTQACCUON_T_APM = {
&tqadp_bauthadptqaccuon_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTqAccu_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_bAuthAdpTqAccuOn_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_BFRZADPELPRODON_T_APM = {
&tqadp_bfrzadpelprodon_t_sav,
TQADPCMP_4_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_stElProd_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_bFrzAdpElProdOn_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_IDXDRAGREDGAIN_T_APM = {
&tqadp_idxdragredgain_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxDragRedGain_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_IDXNEUTGAIN_T_APM = {
&tqadp_idxneutgain_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxNeutGain_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQADP_NENGMVGRDMAX_T_APM = {
&tqadp_nengmvgrdmax_t_sav,
TQADPCMP_2_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tCoMes_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_nEngMvGrdMax_T[0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCDRAGREDGAIN1_M_APM = {
&tqadp_refcdragredgain1_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcDragRedX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaDragRedY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcDragRedGain1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCDRAGREDGAIN2_M_APM = {
&tqadp_refcdragredgain2_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcDragRedX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaDragRedY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcDragRedGain2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCDRAGREDGAIN3_M_APM = {
&tqadp_refcdragredgain3_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcDragRedX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaDragRedY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcDragRedGain3_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCNEUTGAIN1_M_APM = {
&tqadp_refcneutgain1_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcNeutX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaNeutY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcNeutGain1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCNEUTGAIN2_M_APM = {
&tqadp_refcneutgain2_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcNeutX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaNeutY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcNeutGain2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCNEUTGAIN3_M_APM = {
&tqadp_refcneutgain3_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcNeutX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaNeutY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcNeutGain3_M[0][0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQADP_REFCACGAIN_M_APM = {
&tqadp_refcacgain_m_sav,
TQADPCMP_7_SIZE,
TQADPCMP_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqEfcACX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaACY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rEfcACGain_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQACTHD_T_APM = {
&tqadp_tqacthd_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqACThd_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQCORLRNTHDAC_T_APM = {
&tqadp_tqcorlrnthdac_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqCorLrnThdAC_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQCORLRNTHDDRAGRED_T_APM = {
&tqadp_tqcorlrnthddragred_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqCorLrnThdDragRed_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQCORLRNTHDNEUT_T_APM = {
&tqadp_tqcorlrnthdneut_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqCorLrnThdNeut_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQDELTATQIDLTQLOSS_T_APM = {
&tqadp_tqdeltatqidltqloss_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqDeltaTqIdlTqLoss_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQTHDDRAGREDAC_T_APM = {
&tqadp_tqthddragredac_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqThdDragRedAC_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQTHDNEUTAC_T_APM = {
&tqadp_tqthdneutac_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqThdNeutAC_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_04_Retarder(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_Calculer_Couple_Courant(
                                           UInt8 ac_bacclu_par,
                                           UInt8 cooptmel_stelprod_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_stgbxcf_par,
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 frm_binhadp_par,
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           SInt16 tqcmp_tqsumlossestim_par, /* BIN4 */
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 copt_stdragred_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr );

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_Calculer_Couple_Base(
                                           UInt8 ac_bacclu_par,
                                           UInt8 cooptmel_stelprod_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_stgbxcf_par,
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 frm_binhadp_par,
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           SInt16 tqcmp_tqsumlossestim_par, /* BIN4 */
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 copt_stdragred_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr );

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_Determiner_Conditions_Apprentissage(
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt8 cooptmel_stelprod_par,
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt8 frm_binhadp_par,
                                           UInt8 copt_stdragred_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_01_Determiner_Conditions_Moteur(
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           SInt16 ext_tcomes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_02_Determiner_Conditions_Auxiliaires(
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt8 cooptmel_stelprod_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_03_Determiner_Conditions_Boite(
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt8 copt_stdragred_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_04_Synthetiser_Conditions_Apprentissage(
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt8 frm_binhadp_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_02_Determiner_Etat_Climatisation(UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           UInt8 ac_bacclu_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_03_Determiner_Ecart_Couple(
                                           SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                           SInt16 tqcmp_tqsumlossestim_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_Calculer_Couple_Neutre(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr );

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_01_Determiner_Conditions_Activation(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr );

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_02_Calculer_Couple(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_03_Initialiser(
                                           UInt8 tqadp_bmonrunorngneut_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_Calculer_Couple_Drive(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_01_Determiner_Conditions_Activation(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_02_Calculer_Couple(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_03_Initialiser(
                                           UInt8 tqadp_bmonrunorngdragred_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_02_Calculer_Couple_Climatisation(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_02_01_Determiner_Conditions_Activation(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_02_02_Calculer_Couple(void);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Calc_Running_Tq
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Calc_Running_Tq(UInt8 AC_bACClu_swc_in,
                                           UInt8 CoOptmEl_stElProd_swc_in,
                                           UInt8 CoPt_bTqTx_swc_in,
                                           UInt8 CoPt_stCpl_swc_in,
                                           UInt16 EOM_tiEngRunStrt_swc_in, /* DEC2 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhAdp_swc_in,
                                           UInt8 TqAdp_bFrzAdpACOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpAltOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpCnvOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpStgPmpOn_swc_in,
                                           UInt16 TqCmp_tqACLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossEstim_swc_in, /* BIN4 */
                                           UInt8 TqSys_bEngNOnIdl_swc_in,
                                           UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           UInt8 CoPt_stDragRed_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngNeut_swc_out )
{
    tqadp_idxteng_loc = TqAdp_idxTEng;
    tqadp_bdragred_loc = TqAdp_bDragRed;

    TQADPCMP_01_02_04_Retarder();

    TQADPCMP_01_02_02_Calculer_Couple_Courant(AC_bACClu_swc_in,
                                              CoOptmEl_stElProd_swc_in,
                                              CoPt_bTqTx_swc_in,
                                              CoPt_stCpl_swc_in,
                                              EOM_tiEngRunStrt_swc_in, /* DEC2 */
                                              Eng_nCkFil_swc_in, /* BIN2 */
                                              Ext_stGBxCf_swc_in,
                                              Ext_tCoMes_swc_in, /* BIN0 */
                                              FRM_bInhAdp_swc_in,
                                              TqAdp_bFrzAdpACOn_swc_in,
                                              TqAdp_bFrzAdpAltOn_swc_in,
                                              TqAdp_bFrzAdpCnvOn_swc_in,
                                              TqAdp_bFrzAdpStgPmpOn_swc_in,
                                              TqCmp_tqACLoss_swc_in, /* BIN4 */
                                              TqCmp_tqSumLossEstim_swc_in, /* BIN4 */
                                              TqSys_bEngNOnIdl_swc_in,
                                              TqSys_idxTqAccu_swc_in, /* BIN0 */
                                              TqSys_nTarIdl_swc_in, /* BIN2 */
                                              TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                              Veh_spdVeh_swc_in, /* BIN7 */
                                              CoPt_stDragRed_swc_in,
                                              TqAdp_bDgoORngHiDragRed_swc_out,
                                              TqAdp_bDgoORngHiNeut_swc_out,
                                              TqAdp_bDgoORngLoDragRed_swc_out,
                                              TqAdp_bDgoORngLoNeut_swc_out,
                                              TqAdp_bMonRunORngDragRed_swc_out,
                                              TqAdp_bMonRunORngNeut_swc_out );

    tqadpcmp_tqdeltadb_dly = TqAdp_tqDeltaDB;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_04_Retarder
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_04_Retarder(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.39.0 */

    TqAdp_bCorLrnIrvACPrev = TqAdp_bCorLrnIrvAC;
    TqAdp_tqCorLrnIrvACPrev = TqAdp_tqCorLrnIrvAC;
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_Calculer_Couple_Courant
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_Calculer_Couple_Courant(
                                           UInt8 ac_bacclu_par,
                                           UInt8 cooptmel_stelprod_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_stgbxcf_par,
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 frm_binhadp_par,
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           SInt16 tqcmp_tqsumlossestim_par, /* BIN4 */
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 copt_stdragred_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.1.3 */
    TQADPCMP_01_02_02_01_Calculer_Couple_Base(ac_bacclu_par,
                                              cooptmel_stelprod_par,
                                              copt_btqtx_par,
                                              copt_stcpl_par,
                                              eom_tiengrunstrt_par, /* DEC2 */
                                              eng_nckfil_par, /* BIN2 */
                                              ext_stgbxcf_par,
                                              ext_tcomes_par, /* BIN0 */
                                              frm_binhadp_par,
                                              tqadp_bfrzadpacon_par,
                                              tqadp_bfrzadpalton_par,
                                              tqadp_bfrzadpcnvon_par,
                                              tqadp_bfrzadpstgpmpon_par,
                                              tqcmp_tqacloss_par, /* BIN4 */
                                              tqcmp_tqsumlossestim_par, /* BIN4 */
                                              tqsys_bengnonidl_par,
                                              tqsys_idxtqaccu_par, /* BIN0 */
                                              tqsys_ntaridl_par, /* BIN2 */
                                              tqsys_tqckidlcmn_par, /* BIN4 */
                                              veh_spdveh_par, /* BIN7 */
                                              copt_stdragred_par,
                                              tqadp_bdgoornghidragred_ptr,
                                              tqadp_bdgoornghineut_ptr,
                                              tqadp_bdgoornglodragred_ptr,
                                              tqadp_bdgoorngloneut_ptr,
                                              tqadp_bmonrunorngdragred_ptr,
                                              tqadp_bmonrunorngneut_ptr );

    TQADPCMP_01_02_02_02_Calculer_Couple_Climatisation();
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_Calculer_Couple_Base
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_Calculer_Couple_Base(
                                           UInt8 ac_bacclu_par,
                                           UInt8 cooptmel_stelprod_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_stgbxcf_par,
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 frm_binhadp_par,
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           SInt16 tqcmp_tqsumlossestim_par, /* BIN4 */
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 copt_stdragred_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.2.3 */

    TQADPCMP_01_02_02_01_01_Determiner_Conditions_Apprentissage(tqsys_ntaridl_par, /* BIN2 */
                                                                eng_nckfil_par, /* BIN2 */
                                                                ext_tcomes_par, /* BIN0 */
                                                                tqadp_bfrzadpacon_par,
                                                                tqadp_bfrzadpalton_par,
                                                                tqadp_bfrzadpcnvon_par,
                                                                tqadp_bfrzadpstgpmpon_par,
                                                                cooptmel_stelprod_par,
                                                                ext_stgbxcf_par,
                                                                copt_btqtx_par,
                                                                copt_stcpl_par,
                                                                tqsys_bengnonidl_par,
                                                                veh_spdveh_par, /* BIN7 */
                                                                eom_tiengrunstrt_par, /* DEC2 */
                                                                tqsys_idxtqaccu_par, /* BIN0 */
                                                                frm_binhadp_par,
                                                                copt_stdragred_par);

    TQADPCMP_01_02_02_01_02_Determiner_Etat_Climatisation(tqcmp_tqacloss_par, /* BIN4 */
                                                          ac_bacclu_par);

    TQADPCMP_01_02_02_01_03_Determiner_Ecart_Couple(tqsys_tqckidlcmn_par, /* BIN4 */
                                                    tqcmp_tqsumlossestim_par /* BIN4 */);

    TQADPCMP_01_02_02_01_04_Calculer_Couple_Neutre(tqadp_bdgoornghineut_ptr,
                                                   tqadp_bdgoorngloneut_ptr,
                                                   tqadp_bmonrunorngneut_ptr );

    TQADPCMP_01_02_02_01_05_Calculer_Couple_Drive(tqadp_bdgoornghidragred_ptr,
                                                  tqadp_bdgoornglodragred_ptr,
                                                  tqadp_bmonrunorngdragred_ptr);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_01_Determiner_Conditions_Apprentissage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_Determiner_Conditions_Apprentissage(
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt8 cooptmel_stelprod_par,
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt8 frm_binhadp_par,
                                           UInt8 copt_stdragred_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.3.6 */

    TQADPCMP_01_02_02_01_01_01_Determiner_Conditions_Moteur(tqsys_ntaridl_par, /* BIN2 */
                                                            eng_nckfil_par, /* BIN2 */
                                                            ext_tcomes_par /* BIN0 */);

    TQADPCMP_01_02_02_01_01_02_Determiner_Conditions_Auxiliaires(tqadp_bfrzadpacon_par,
                                                                 tqadp_bfrzadpalton_par,
                                                                 tqadp_bfrzadpcnvon_par,
                                                                 tqadp_bfrzadpstgpmpon_par,
                                                                 cooptmel_stelprod_par);

    TQADPCMP_01_02_02_01_01_03_Determiner_Conditions_Boite(ext_stgbxcf_par,
                                                           copt_btqtx_par,
                                                           copt_stcpl_par,
                                                           copt_stdragred_par);

    TQADPCMP_01_02_02_01_01_04_Synthetiser_Conditions_Apprentissage(tqsys_bengnonidl_par,
                                                                    veh_spdveh_par, /* BIN7 */
                                                                    eom_tiengrunstrt_par, /* DEC2 */
                                                                    tqsys_idxtqaccu_par, /* BIN0 */
                                                                    frm_binhadp_par);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_01_01_Determiner_Conditions_Moteur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_01_Determiner_Conditions_Moteur(
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           SInt16 ext_tcomes_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.4.1 */
    SInt32 tqadpcmp_calc;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    tqadpcmp_calc = DDS_M_ABS((SInt32)eng_nckfil_par - (SInt32)tqsys_ntaridl_par);

    TqAdp_nDeltaNEngNTarIdl_MP = (UInt16)tqadpcmp_calc;

    if((UInt32)TqAdp_nDeltaNEngNTarIdl_MP<(UInt32)TqAdp_nEngMvStabThd_C)
    {
        TqAdp_bCorLrnNEngMvCdn1_MP = DDS_M_TURN_ON_DELAY(DDS_TRUE,
                                                           tqadpcmp_te,
                                                           ((UInt32)TqAdp_tiNEngMvStab_C*DEC1),
                                                           &tqadpcmp_01_02_02_01_01_01_turn_on_delay);
    }
    else
    {
        TqAdp_bCorLrnNEngMvCdn1_MP = DDS_M_TURN_ON_DELAY(DDS_FALSE,
                                                           tqadpcmp_te,
                                                           ((UInt32)TqAdp_tiNEngMvStab_C*DEC1),
                                                           &tqadpcmp_01_02_02_01_01_01_turn_on_delay);
    }

    if((UInt32)eng_nckfil_par<=(UInt32)TqAdp_nEngMvMax_C)
    {
        TqAdp_bCorLrnNEngMvCdn2_MP = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnNEngMvCdn2_MP = DDS_FALSE;
    }


    tqadpcmp_calc = DDS_M_ABS((SInt32)eng_nckfil_par - (SInt32)tqadpcmp_01_02_02_01_01_01_eng_nckfil_dly);
    tqadpcmp_01_02_02_01_01_01_eng_nckfil_dly = eng_nckfil_par;

    TqAdp_nGrdNEng_MP = (UInt16)tqadpcmp_calc;

    TqAdp_nEngMvGrdMax_MP = DDS_M_MAP2D_SU16(&TQADP_NENGMVGRDMAX_T_APM,(SInt16)((SInt32)ext_tcomes_par*BIN2));

    if((UInt32)TqAdp_nGrdNEng_MP<=(UInt32)TqAdp_nEngMvGrdMax_MP)
    {
        TqAdp_bCorLrnNEngMvCdn3_MP = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnNEngMvCdn3_MP = DDS_FALSE;
    }


    if(  ((UInt32)TqAdp_bCorLrnNEngMvCdn1_MP == (UInt32)DDS_TRUE)
       &&((UInt32)TqAdp_bCorLrnNEngMvCdn2_MP == (UInt32)DDS_TRUE)
       &&((UInt32)TqAdp_bCorLrnNEngMvCdn3_MP == (UInt32)DDS_TRUE))
    {
        TqAdp_bCorLrnNEngMvCdn = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnNEngMvCdn = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_01_02_Determiner_Conditions_Auxiliaires
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_02_Determiner_Conditions_Auxiliaires(
                                           UInt8 tqadp_bfrzadpacon_par,
                                           UInt8 tqadp_bfrzadpalton_par,
                                           UInt8 tqadp_bfrzadpcnvon_par,
                                           UInt8 tqadp_bfrzadpstgpmpon_par,
                                           UInt8 cooptmel_stelprod_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.45.0 */
    UInt32 tqadpcmp_te;
    UInt32 tqadpcmp_turn_off_out;
    UInt32 tqadpcmp_map_out;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    if((UInt32)tqadp_bfrzadpstgpmpon_par != (UInt32)DDS_FALSE)
    {
        tqadpcmp_turn_off_out = (UInt32)DDS_M_TURN_OFF_DELAY(DDS_TRUE,
                                                           tqadpcmp_te,
                                                           ((UInt32)TqAdp_tiDlyDirAsiDeac_C*DEC2),
                                                           &tqadpcmp_01_02_02_01_01_02_turn_off_delay);
    }
    else
    {
        tqadpcmp_turn_off_out = (UInt32)DDS_M_TURN_OFF_DELAY(DDS_FALSE,
                                                           tqadpcmp_te,
                                                           ((UInt32)TqAdp_tiDlyDirAsiDeac_C*DEC2),
                                                           &tqadpcmp_01_02_02_01_01_02_turn_off_delay);
    }

    tqadpcmp_map_out = (UInt32)DDS_M_MAP2D_U16(&TQADP_BFRZADPELPRODON_T_APM,cooptmel_stelprod_par);

    if(  (tqadpcmp_turn_off_out == (UInt32)DDS_TRUE)
       ||((UInt32)tqadp_bfrzadpalton_par == (UInt32)DDS_TRUE)
       ||((UInt32)tqadp_bfrzadpacon_par == (UInt32)DDS_TRUE)
       ||((UInt32)tqadp_bfrzadpcnvon_par == (UInt32)DDS_TRUE)
       ||(tqadpcmp_map_out == (UInt32)DDS_TRUE))
    {
        TqAdp_bAuxOff = DDS_FALSE;
    }
    else
    {
        TqAdp_bAuxOff = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_01_03_Determiner_Conditions_Boite
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_03_Determiner_Conditions_Boite(
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt8 copt_stdragred_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.46.0 */

    switch((UInt32)ext_stgbxcf_par)
    {
        case (UInt32)0:
            TqAdp_bAuthAdpGBx = DDS_TRUE;
            break;
        case (UInt32)1:
            if(((UInt32)tqadp_bdragred_loc==(UInt32)tqadpcmp_01_02_02_01_01_03_bdragred_dly)
            &&	((UInt32)copt_stdragred_par <= COPT_STDRAGRED_DEBRAYE_A_LARRET))
            {
                TqAdp_bAuthAdpGBx = DDS_TRUE;
            }
            else
            {
                TqAdp_bAuthAdpGBx = DDS_FALSE;
            }
            break;
        case (UInt32)2:
        default:
            if((UInt32)TqAdp_bCluCfSel_C!=(UInt32)DDS_FALSE)
            {
                if((UInt32)copt_btqtx_par!=(UInt32)DDS_TRUE)
                {
                    TqAdp_bAuthAdpGBx = DDS_TRUE;
                }
                else
                {
                    TqAdp_bAuthAdpGBx = DDS_FALSE;
                }
            }
            else
            {
                if(  ((UInt32)copt_btqtx_par!=(UInt32)DDS_FALSE)
                   ||((UInt32)copt_stcpl_par!=0))
                {
                    TqAdp_bAuthAdpGBx = DDS_FALSE;
                }
                else
                {
                    TqAdp_bAuthAdpGBx = DDS_TRUE;
                }
            }
            break;
    }

    tqadpcmp_01_02_02_01_01_03_bdragred_dly = tqadp_bdragred_loc;
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_01_04_Synthetiser_Conditions_Apprentissage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_01_04_Synthetiser_Conditions_Apprentissage(
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt16 eom_tiengrunstrt_par, /* DEC2 */
                                           UInt8 tqsys_idxtqaccu_par, /* BIN0 */
                                           UInt8 frm_binhadp_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.47.0 */
    UInt32 tqadpcmp_val;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    tqadpcmp_val = (UInt32)DDS_M_MAP2D_U16(&TQADP_BAUTHADPTQACCUON_T_APM,tqsys_idxtqaccu_par);

    if(  ((UInt32)TqAdp_bCorLrnNEngMvCdn == (UInt32)DDS_TRUE)
       &&((UInt32)TqAdp_bAuxOff == (UInt32)DDS_TRUE)
       &&((UInt32)TqAdp_bAuthAdpGBx == (UInt32)DDS_TRUE)
       &&((UInt32)tqsys_bengnonidl_par == (UInt32)DDS_TRUE)
       &&((UInt32)veh_spdveh_par <= (UInt32)TqAdp_spdVehThd_C)
       &&((UInt32)eom_tiengrunstrt_par >= (UInt32)TqAdp_tiDlyAst_C)
       &&(tqadpcmp_val == (UInt32)DDS_TRUE)
       &&((UInt32)frm_binhadp_par == (UInt32)DDS_FALSE))
    {
        TqAdp_bAcvAdp_MP = DDS_TRUE;
    }
    else
    {
        TqAdp_bAcvAdp_MP = DDS_FALSE;
    }

    tqadpcmp_val = (UInt32)DDS_M_TURN_ON_DELAY(TqAdp_bAcvAdp_MP,
                                               tqadpcmp_te,
                                               ((UInt32)TqAdp_tiDlyCdn_C*DEC3),
                                               &tqadpcmp_01_02_02_01_01_04_turn_on_delay);

    if(  ((UInt32)tqadp_bdragred_loc == (UInt32)DDS_FALSE)
       &&(tqadpcmp_val == (UInt32)DDS_TRUE))
    {
        TqAdp_bCorLrnNeutCdn = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnNeutCdn = DDS_FALSE;
    }

    if(  ((UInt32)tqadp_bdragred_loc == (UInt32)DDS_TRUE)
       &&(tqadpcmp_val == (UInt32)DDS_TRUE))
    {
        TqAdp_bCorLrnDragRedCdn = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnDragRedCdn = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_02_Determiner_Etat_Climatisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_02_Determiner_Etat_Climatisation(UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           UInt8 ac_bacclu_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.5.2 */
    SInt32 tqadpcmp_val;
    UInt8 tqadpcmp_hyst_out;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    tqadpcmp_val = (SInt32)DDS_M_MAP2D_US16(&TQADP_TQACTHD_T_APM,(UInt16)tqadp_idxteng_loc);

    tqadpcmp_hyst_out = DDS_M_HYST_PH_S32(&tqadpcmp_01_02_02_01_02_hyst,
                                      (SInt32)tqcmp_tqacloss_par,
                                      tqadpcmp_val,
                                      tqadpcmp_val-(SInt32)TqAdp_tqThdHysACDeac_C);

    tqadpcmp_val = (SInt32)DDS_M_TURN_OFF_DELAY(tqadpcmp_hyst_out,
                                                tqadpcmp_te,
                                                TqAdp_tiDlyACDeac_C*DEC1,
                                                &tqadpcmp_01_02_02_01_02_turn_off_delay);

    if((UInt32)ac_bacclu_par != (UInt32)DDS_FALSE)
    {
        if(tqadpcmp_val != (SInt32)DDS_TRUE)
        {
            TqAdp_bCorLrnWoutAC = DDS_TRUE;
        }
        else
        {
            TqAdp_bCorLrnWoutAC = DDS_FALSE;
        }
    }
    else
    {
        TqAdp_bCorLrnWoutAC = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_03_Determiner_Ecart_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_03_Determiner_Ecart_Couple(
                                           SInt16 tqsys_tqckidlcmn_par, /* BIN4 */
                                           SInt16 tqcmp_tqsumlossestim_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.6.3 */
    SInt32 tqadpcmp_val;
    SInt32 tqadpcmp_val2;

    tqadpcmp_val = (SInt32)DDS_M_MAP2D_US16(&TQADP_TQDELTATQIDLTQLOSS_T_APM,(UInt16)tqadp_idxteng_loc);

    if((UInt32)DDS_FALSE == (UInt32)filter_12213_is_initialised)
    {
        TqAdp_tqCkIdlFil_MP = DDS_M_FILTER_LP1_S16_INIT(&filter_12213_str, tqsys_tqckidlcmn_par);
        filter_12213_is_initialised = DDS_TRUE;
    }
    else
    {
        TqAdp_tqCkIdlFil_MP = DDS_M_FILTER_LP1_S16(&filter_12213_str,
                                                    tqsys_tqckidlcmn_par,
                                                    TqAdp_facFilTqCkIdl_C,
                                                    BIN7);
    }

    TqAdp_tqDeltaTqIdlTqLoss_MP = (SInt16)DDS_M_LIMIT((SInt32)TqAdp_tqCkIdlFil_MP-(SInt32)tqcmp_tqsumlossestim_par,-2000*BIN4,2000*BIN4);

    tqadpcmp_val2 = DDS_M_SATURATION_V2((SInt32)TqAdp_tqDeltaTqIdlTqLoss_MP,-tqadpcmp_val,tqadpcmp_val);

    tqadpcmp_val = (SInt32)TqAdp_tqDeltaTqIdlTqLoss_MP-tqadpcmp_val2;
    TqAdp_tqDeltaDB = (SInt16)DDS_M_SATURATION_V2(tqadpcmp_val,-2000*BIN4,2000*BIN4);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_04_Calculer_Couple_Neutre
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_Calculer_Couple_Neutre(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.43.0 */
    UInt32 tqadpcmp_index;

    for(tqadpcmp_index=0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
    {
        TqAdp_prm_tqCorLrnNeutPrev[tqadpcmp_index] = DDS_M_LIMIT((SInt32)TqAdp_prm_tqCorLrnNeut[tqadpcmp_index] * BIN14,
                                                                (-50*BIN18),
                                                                (50*BIN18));
    }

    TQADPCMP_01_02_02_01_04_01_Determiner_Conditions_Activation(tqadp_bmonrunorngneut_ptr );

    if((UInt32)*tqadp_bmonrunorngneut_ptr != (UInt32)DDS_FALSE)
    {
        TQADPCMP_01_02_02_01_04_02_Calculer_Couple(tqadp_bdgoornghineut_ptr,
                                                   tqadp_bdgoorngloneut_ptr);
    }
    else
    {
        /* nothing to do */
    }

    TQADPCMP_01_02_02_01_04_03_Initialiser(*tqadp_bmonrunorngneut_ptr);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_04_01_Determiner_Conditions_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_01_Determiner_Conditions_Activation(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngneut_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.48.0 */

    if(  ((UInt32)TqAdp_bCorLrnNeutCdn == (UInt32)DDS_TRUE)
       &&((UInt32)TqAdp_bCorLrnWoutAC == (UInt32)DDS_TRUE))
    {
        *tqadp_bmonrunorngneut_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bmonrunorngneut_ptr = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_04_02_Calculer_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_02_Calculer_Couple(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghineut_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoorngloneut_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.9.4 */
    UInt32 tqadpcmp_switch_index;
    SInt32 tqadpcmp_sval_b4;
    SInt32 tqadpcmp_sval_b18;
    SInt32 tqadpcmp_sval;
    SInt32 tqadpcmp_sval2;
    SInt16 tqadp_tqdeltaneut_mp_bin9;

    if((UInt32)tqadpcmp_04_02_prm_dly_init != (UInt32)DDS_TRUE)
    {
        TqAdp_prm_tqCorLrnNeutOn[0] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[0] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[1] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[1] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[2] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[2] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[3] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[3] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[4] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[4] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[5] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[5] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[6] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[6] / BIN9);
        TqAdp_prm_tqCorLrnNeutOn[7] = (SInt16)(TqAdp_prm_tqCorLrnNeutPrev[7] / BIN9);
        TqAdp_prm_tqLrnNeutOn_MP[0] = TqAdp_prm_tqCorLrnNeutPrev[0];
        TqAdp_prm_tqLrnNeutOn_MP[1] = TqAdp_prm_tqCorLrnNeutPrev[1];
        TqAdp_prm_tqLrnNeutOn_MP[2] = TqAdp_prm_tqCorLrnNeutPrev[2];
        TqAdp_prm_tqLrnNeutOn_MP[3] = TqAdp_prm_tqCorLrnNeutPrev[3];
        TqAdp_prm_tqLrnNeutOn_MP[4] = TqAdp_prm_tqCorLrnNeutPrev[4];
        TqAdp_prm_tqLrnNeutOn_MP[5] = TqAdp_prm_tqCorLrnNeutPrev[5];
        TqAdp_prm_tqLrnNeutOn_MP[6] = TqAdp_prm_tqCorLrnNeutPrev[6];
        TqAdp_prm_tqLrnNeutOn_MP[7] = TqAdp_prm_tqCorLrnNeutPrev[7];
    }
    else
    {
        /* nothing to do */
    }

    TqAdp_tqCorLrnNeutSel_MP = TqAdp_prm_tqLrnNeutOn_MP[(UInt32)((SInt32)tqadp_idxteng_loc-1)];

    TqAdp_tqEfcNeut_MP = (SInt16)DDS_M_LIMIT((SInt32)TqAdp_tqDeltaDB-(SInt32)tqadpcmp_tqdeltadb_dly,-2000*BIN4,2000*BIN4);
    TqAdp_tqDeltaNeut_MP = DDS_M_LIMIT(((SInt32)TqAdp_tqDeltaDB*BIN14)-TqAdp_tqCorLrnNeutSel_MP,-50*BIN18,50*BIN18);

    tqadpcmp_switch_index = (UInt32)DDS_M_MAP2D_U16(&TQADP_IDXNEUTGAIN_T_APM,(UInt16)tqadp_idxteng_loc);
    tqadp_tqdeltaneut_mp_bin9 = (SInt16)(TqAdp_tqDeltaNeut_MP / BIN9);

    switch(tqadpcmp_switch_index)
    {
        case (UInt32)1:
            TqAdp_rEfcNeutGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCNEUTGAIN1_M_APM,TqAdp_tqEfcNeut_MP,tqadp_tqdeltaneut_mp_bin9);
            break;
        case (UInt32)2:
            TqAdp_rEfcNeutGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCNEUTGAIN2_M_APM,TqAdp_tqEfcNeut_MP,tqadp_tqdeltaneut_mp_bin9);
            break;
        case (UInt32)3:
        default:
            TqAdp_rEfcNeutGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCNEUTGAIN3_M_APM,TqAdp_tqEfcNeut_MP,tqadp_tqdeltaneut_mp_bin9);
            break;
    }

    /*BIN18 = ((BIN18 / BIN14) * BIN18 / BIN4) + BIN18 */
    tqadpcmp_sval_b18 = (((TqAdp_tqDeltaNeut_MP / BIN14) * (SInt32)TqAdp_rEfcNeutGain_MP) / BIN4) + TqAdp_tqCorLrnNeutSel_MP;
    tqadpcmp_sval_b4 = tqadpcmp_sval_b18 / BIN14;

    if(tqadpcmp_sval_b4>=(SInt32)TqAdp_tqCorLrnNeutMax_C)
    {
        *tqadp_bdgoornghineut_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bdgoornghineut_ptr = DDS_FALSE;
    }

    if(tqadpcmp_sval_b4<=(SInt32)TqAdp_tqCorLrnNeutMin_C)
    {
        *tqadp_bdgoorngloneut_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bdgoorngloneut_ptr = DDS_FALSE;
    }

    tqadpcmp_sval_b18 = DDS_M_SATURATION_V2(tqadpcmp_sval_b18,
                                            ((SInt32)TqAdp_tqCorLrnNeutMin_C * BIN14),
                                            ((SInt32)TqAdp_tqCorLrnNeutMax_C * BIN14));
    TqAdp_tqCorLrnNeutOn = (SInt16)(tqadpcmp_sval_b18 / BIN9);

    if((UInt32)tqadpcmp_04_02_prm_dly_init != (UInt32)DDS_TRUE)
    {
        tqadpcmp_04_02_prm_dly_init = DDS_TRUE;
    }
    else
    {
        TqAdp_prm_tqLrnNeutOn_MP[(UInt32)((SInt32)tqadp_idxteng_loc-1)] = tqadpcmp_sval_b18;
        TqAdp_prm_tqCorLrnNeutOn[(UInt32)((SInt32)tqadp_idxteng_loc-1)] = TqAdp_tqCorLrnNeutOn;
    }

    tqadpcmp_sval = DDS_M_ABS(TqAdp_tqDeltaNeut_MP / BIN14);
    tqadpcmp_sval2 = DDS_M_MAP2D_US16(&TQADP_TQCORLRNTHDNEUT_T_APM,(UInt16)tqadp_idxteng_loc);
    if(tqadpcmp_sval <= tqadpcmp_sval2)
    {
        TqAdp_bCorLrnNeut = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnNeut = DDS_FALSE;
    }

    tqadpcmp_sval2 = DDS_M_MAP2D_US16(&TQADP_TQTHDNEUTAC_T_APM,(UInt16)tqadp_idxteng_loc);
    if(tqadpcmp_sval<=tqadpcmp_sval2)
    {
        TqAdp_bCorLrnNeutAC = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnNeutAC = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_04_03_Initialiser
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_04_03_Initialiser(
                                           UInt8 tqadp_bmonrunorngneut_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.49.0 */
    UInt32 tqadpcmp_index;
    t_dds_m_edge_detected_event tqadpcmp_edge_out;

    tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_01_02_02_01_04_03_edge_detect,tqadp_bmonrunorngneut_par);
    if(tqadpcmp_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        tqadpcmp_01_02_02_01_04_03_switch_dly = DDS_TRUE;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)tqadpcmp_01_02_02_01_04_03_switch_dly != (UInt32)DDS_FALSE)
    {
        for(tqadpcmp_index=0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
        {
            TqAdp_prm_tqCorLrnNeut[tqadpcmp_index] = (SInt16)((SInt32)TqAdp_prm_tqCorLrnNeutOn[tqadpcmp_index] / BIN5);
        }
    }
    else
    {
        for(tqadpcmp_index=0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
        {
            TqAdp_prm_tqCorLrnNeut[tqadpcmp_index] = TqAdp_prm_tqCorLrnNeutIni[tqadpcmp_index];
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_05_Calculer_Couple_Drive
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_Calculer_Couple_Drive(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.44.0 */
    TQADPCMP_01_02_02_01_05_01_Determiner_Conditions_Activation(tqadp_bmonrunorngdragred_ptr);

    if((UInt32)*tqadp_bmonrunorngdragred_ptr != (UInt32)DDS_FALSE)
    {
        TQADPCMP_01_02_02_01_05_02_Calculer_Couple(tqadp_bdgoornghidragred_ptr,
                                                   tqadp_bdgoornglodragred_ptr);
    }
    else
    {
        /* Nothing to do */
    }

    TQADPCMP_01_02_02_01_05_03_Initialiser(*tqadp_bmonrunorngdragred_ptr);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_05_01_Determiner_Conditions_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_01_Determiner_Conditions_Activation(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bmonrunorngdragred_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.50.0 */

    if(  ((UInt32)TqAdp_bCorLrnDragRedCdn == (UInt32)DDS_TRUE)
       &&((UInt32)TqAdp_bCorLrnWoutAC == (UInt32)DDS_TRUE))
    {
        *tqadp_bmonrunorngdragred_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bmonrunorngdragred_ptr = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_05_02_Calculer_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_02_Calculer_Couple(
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornghidragred_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bdgoornglodragred_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.8.4 */
    UInt32 tqadpcmp_switch_index;
    SInt32 tqadpcmp_sval;
    SInt32 tqadpcmp_sval2;
    SInt32 tqadpcmp_sval_b18;
    SInt32 tqadpcmp_sval_b9;
    SInt16 tqadp_tqdeltadragred_mp_bin9;

    if((UInt32)tqadpcmp_05_02_prm_dly_init != (UInt32)DDS_TRUE)
    {
        TqAdp_prm_tqCorLrnDragRedOn[0] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[0] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[1] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[1] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[2] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[2] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[3] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[3] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[4] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[4] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[5] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[5] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[6] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[6] / BIN9);
        TqAdp_prm_tqCorLrnDragRedOn[7] = (SInt16)(TqAdp_prm_tqCorLrnDragRedPrev[7] / BIN9);
        TqAdp_prm_tqLrnDragRedOn_MP[0] = TqAdp_prm_tqCorLrnDragRedPrev[0];
        TqAdp_prm_tqLrnDragRedOn_MP[1] = TqAdp_prm_tqCorLrnDragRedPrev[1];
        TqAdp_prm_tqLrnDragRedOn_MP[2] = TqAdp_prm_tqCorLrnDragRedPrev[2];
        TqAdp_prm_tqLrnDragRedOn_MP[3] = TqAdp_prm_tqCorLrnDragRedPrev[3];
        TqAdp_prm_tqLrnDragRedOn_MP[4] = TqAdp_prm_tqCorLrnDragRedPrev[4];
        TqAdp_prm_tqLrnDragRedOn_MP[5] = TqAdp_prm_tqCorLrnDragRedPrev[5];
        TqAdp_prm_tqLrnDragRedOn_MP[6] = TqAdp_prm_tqCorLrnDragRedPrev[6];
        TqAdp_prm_tqLrnDragRedOn_MP[7] = TqAdp_prm_tqCorLrnDragRedPrev[7];
    }
    else
    {
        /* nothing to do */
    }

    TqAdp_tqCorLrnDragRedSel_MP = TqAdp_prm_tqLrnDragRedOn_MP[(UInt32)((SInt32)tqadp_idxteng_loc-1)];

    tqadpcmp_sval = (SInt32)TqAdp_tqDeltaDB-(SInt32)tqadpcmp_tqdeltadb_dly;
    TqAdp_tqEfcDragRed_MP = (SInt16)DDS_M_LIMIT(tqadpcmp_sval,-2000*BIN4,2000*BIN4);

    tqadpcmp_sval = ((SInt32)TqAdp_tqDeltaDB * BIN14)-TqAdp_tqCorLrnDragRedSel_MP;
    TqAdp_tqDeltaDragRed_MP = DDS_M_LIMIT(tqadpcmp_sval,-50*BIN18,50*BIN18);

    tqadpcmp_switch_index = (UInt32)DDS_M_MAP2D_U16(&TQADP_IDXDRAGREDGAIN_T_APM,(UInt16)tqadp_idxteng_loc);
    tqadp_tqdeltadragred_mp_bin9 = (SInt16)(TqAdp_tqDeltaDragRed_MP / BIN9);

    switch(tqadpcmp_switch_index)
    {
        case (UInt32)1:
            TqAdp_rEfcDragRedGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCDRAGREDGAIN1_M_APM,TqAdp_tqEfcDragRed_MP,tqadp_tqdeltadragred_mp_bin9);
            break;
        case (UInt32)2:
            TqAdp_rEfcDragRedGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCDRAGREDGAIN2_M_APM,TqAdp_tqEfcDragRed_MP,tqadp_tqdeltadragred_mp_bin9);
            break;
        case (UInt32)3:
        default:
            TqAdp_rEfcDragRedGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCDRAGREDGAIN3_M_APM,TqAdp_tqEfcDragRed_MP,tqadp_tqdeltadragred_mp_bin9);
            break;
    }

    /*BIN18 = ((BIN18 / BIN14) * BIN18 / BIN4) + BIN18 */
    tqadpcmp_sval_b18 = (((TqAdp_tqDeltaDragRed_MP / BIN14) * (SInt32)TqAdp_rEfcDragRedGain_MP) / BIN4) + TqAdp_tqCorLrnDragRedSel_MP;
    tqadpcmp_sval_b9 = tqadpcmp_sval_b18 / BIN9;

    if(tqadpcmp_sval_b9>=(SInt32)TqAdp_tqCorLrnDragRedMax_C)
    {
        *tqadp_bdgoornghidragred_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bdgoornghidragred_ptr = DDS_FALSE;
    }

    if(tqadpcmp_sval_b9<=(SInt32)TqAdp_tqCorLrnDragRedMin_C)
    {
        *tqadp_bdgoornglodragred_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bdgoornglodragred_ptr = DDS_FALSE;
    }

    tqadpcmp_sval_b18 = DDS_M_SATURATION_V2(tqadpcmp_sval_b18,
                                            ((SInt32)TqAdp_tqCorLrnDragRedMin_C * BIN9),
                                            ((SInt32)TqAdp_tqCorLrnDragRedMax_C * BIN9));

    TqAdp_tqCorLrnDragRedOn = (SInt16)(tqadpcmp_sval_b18 / BIN9);

    if((UInt32)tqadpcmp_05_02_prm_dly_init != (UInt32)DDS_TRUE)
    {
        tqadpcmp_05_02_prm_dly_init = DDS_TRUE;
    }
    else
    {
        TqAdp_prm_tqLrnDragRedOn_MP[(UInt32)((SInt32)tqadp_idxteng_loc-1)] = tqadpcmp_sval_b18;
        TqAdp_prm_tqCorLrnDragRedOn[(UInt32)((SInt32)tqadp_idxteng_loc-1)] = TqAdp_tqCorLrnDragRedOn;
    }

    tqadpcmp_sval = DDS_M_ABS(TqAdp_tqDeltaDragRed_MP / BIN14);
    tqadpcmp_sval2 = DDS_M_MAP2D_US16(&TQADP_TQCORLRNTHDDRAGRED_T_APM,(UInt16)tqadp_idxteng_loc);
    if(tqadpcmp_sval<=tqadpcmp_sval2)
    {
        TqAdp_bCorLrnDragRed = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnDragRed = DDS_FALSE;
    }

    tqadpcmp_sval2 = DDS_M_MAP2D_US16(&TQADP_TQTHDDRAGREDAC_T_APM,(UInt16)tqadp_idxteng_loc);
    if(tqadpcmp_sval<=tqadpcmp_sval2)
    {
        TqAdp_bCorLrnDragRedAC = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnDragRedAC = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_01_05_03_Initialiser
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_01_05_03_Initialiser(
                                           UInt8 tqadp_bmonrunorngdragred_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.51.0 */
    UInt32 tqadpcmp_index;
    t_dds_m_edge_detected_event tqadpcmp_edge_out;

    for(tqadpcmp_index=0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
    {
        TqAdp_prm_tqCorLrnDragRedPrev[tqadpcmp_index] = DDS_M_LIMIT((SInt32)TqAdp_prm_tqCorLrnDragRed[tqadpcmp_index] * BIN14,
                                                                    -50*BIN18,
                                                                    50*BIN18);
    }

    tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_01_02_02_01_05_03_edge_detect,tqadp_bmonrunorngdragred_par);
    if(tqadpcmp_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        tqadpcmp_01_02_02_01_05_03_switch_dly = DDS_TRUE;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)tqadpcmp_01_02_02_01_05_03_switch_dly !=(UInt32)DDS_FALSE)
    {
        for(tqadpcmp_index=0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
        {
            TqAdp_prm_tqCorLrnDragRed[tqadpcmp_index] = (SInt16)((SInt32)TqAdp_prm_tqCorLrnDragRedOn[tqadpcmp_index] / BIN5);
        }
    }
    else
    {
        for(tqadpcmp_index=0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
        {
            TqAdp_prm_tqCorLrnDragRed[tqadpcmp_index] = TqAdp_prm_tqCorLrnDragRedIni[tqadpcmp_index];
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_02_Calculer_Couple_Climatisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_02_Calculer_Couple_Climatisation(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.14.3 */
    TQADPCMP_01_02_02_02_01_Determiner_Conditions_Activation();

    if((UInt32)TqAdp_bSyntCorLrnCdnAC != (UInt32)DDS_FALSE)
    {
        TQADPCMP_01_02_02_02_02_Calculer_Couple();
    }
    else
    {
        /* Nothing to do */
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_02_01_Determiner_Conditions_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_02_01_Determiner_Conditions_Activation(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.52.0 */
    UInt32 tqadpcmp_val1;
    UInt32 tqadpcmp_val2;
    UInt32 tqadpcmp_map_out;

    if((UInt32)tqadp_bdragred_loc != (UInt32)DDS_FALSE)
    {
        tqadpcmp_val1 = (UInt32)TqAdp_bCorLrnDragRedCdn;
        tqadpcmp_val2 = (UInt32)TqAdp_bCorLrnDragRedAC;
    }
    else
    {
        tqadpcmp_val1 = (UInt32)TqAdp_bCorLrnNeutCdn;
        tqadpcmp_val2 = (UInt32)TqAdp_bCorLrnNeutAC;
    }

    tqadpcmp_map_out = (UInt32)DDS_M_MAP2D_U16(&TQADP_BAUTHADPAC_T_APM,(UInt16)tqadp_idxteng_loc);

    if(  ((UInt32)TqAdp_bCorLrnWoutAC == (UInt32)DDS_FALSE)
       &&(tqadpcmp_val1 == (UInt32)DDS_TRUE)
       &&(tqadpcmp_val2 == (UInt32)DDS_TRUE)
       &&(tqadpcmp_map_out == (UInt32)DDS_TRUE))
    {
        TqAdp_bSyntCorLrnCdnAC = DDS_TRUE;
        TqAdp_bCorLrnCdnAC = DDS_TRUE;
    }
    else
    {
        if((UInt32)TqAdp_bCorLrnIrvACPrev!=(UInt32)DDS_FALSE)
        {
            TqAdp_bSyntCorLrnCdnAC = DDS_TRUE;
        }
        else
        {
            TqAdp_bSyntCorLrnCdnAC = DDS_FALSE;
        }
        TqAdp_bCorLrnCdnAC = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_02_02_02_Calculer_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_02_02_02_Calculer_Couple(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.15.3 */
    SInt32 tqadpcmp_val;
    SInt32 tqadp_tqdeltaac_mp_bin18;
    SInt32 tqadp_s32_temp;

    TqAdp_tqEfcAC_MP = (SInt16)DDS_M_LIMIT((SInt32)TqAdp_tqDeltaDB-(SInt32)tqadpcmp_01_02_02_02_02_dly1,-2000*BIN4,2000*BIN4);
    tqadpcmp_01_02_02_02_02_dly1 = TqAdp_tqDeltaDB;

    if((UInt32)tqadp_bdragred_loc!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_val = ((SInt32)TqAdp_prm_tqCorLrnDragRed[(UInt32)((SInt32)tqadp_idxteng_loc-1)])*BIN5;
    }
    else
    {
        tqadpcmp_val = ((SInt32)TqAdp_prm_tqCorLrnNeut[(UInt32)((SInt32)tqadp_idxteng_loc-1)])*BIN5;
    }

    tqadp_tqdeltaac_mp_bin18 = DDS_M_LIMIT(((((SInt32)TqAdp_tqDeltaDB*BIN5)-tqadpcmp_val)* BIN9)-TqAdp_tqLrnAC_MP,
                                             -2000*BIN18,
                                             2000*BIN18);

    TqAdp_tqDeltaAC_MP = (SInt16)(tqadp_tqdeltaac_mp_bin18 / BIN14);

    TqAdp_rEfcACGain_MP = DDS_M_MAP3D_SSU16(&TQADP_REFCACGAIN_M_APM,TqAdp_tqEfcAC_MP,TqAdp_tqDeltaAC_MP);

    tqadpcmp_val = (SInt32)DDS_M_MAP2D_US16(&TQADP_TQCORLRNTHDAC_T_APM,(UInt16)tqadp_idxteng_loc);

    tqadp_s32_temp = DDS_M_ABS((SInt32)TqAdp_tqDeltaAC_MP);

    if(tqadp_s32_temp <= tqadpcmp_val)
    {
        TqAdp_bCorLrnAC = DDS_TRUE;
    }
    else
    {
        TqAdp_bCorLrnAC = DDS_FALSE;
    }
    /* BIN9 = BIN9 * BIN9 + BIN9 */

    if((UInt32)TqAdp_bCorLrnIrvACPrev!=(UInt32)DDS_FALSE)
    {
        TqAdp_tqLrnAC_MP = DDS_M_SATURATION_V2((SInt32)TqAdp_tqCorLrnIrvACPrev*BIN14,
                                            (SInt32)TqAdp_tqCorLrnACMin_C*BIN14,
                                            (SInt32)TqAdp_tqCorLrnACMax_C*BIN14);
    }
    else
    {
        /*BIN18 = (BIN4 * BIN18 / BIN4) + BIN18 */
        tqadpcmp_val = ((((SInt32)TqAdp_tqDeltaAC_MP * (SInt32)TqAdp_rEfcACGain_MP))/BIN4)+ TqAdp_tqLrnAC_MP;
        TqAdp_tqLrnAC_MP = DDS_M_SATURATION_V2(tqadpcmp_val,(SInt32)TqAdp_tqCorLrnACMin_C*BIN14,(SInt32)TqAdp_tqCorLrnACMax_C*BIN14);
    }

    if((UInt32)DDS_FALSE == (UInt32)tqadp_tqcorlrnac_is_init)
    {
        TqAdp_tqCorLrnAC = 0;
        tqadp_tqcorlrnac_is_init = DDS_TRUE;
    }
    else
    {
        TqAdp_tqCorLrnAC = (SInt16)(TqAdp_tqLrnAC_MP/BIN14);
    }
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Calc_Running_Tq_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Calc_Running_Tq_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngHiNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bDgoORngLoNeut_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngDragRed_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bMonRunORngNeut_swc_out )
{
    UInt32 tqadpcmp_index;

    *TqAdp_bDgoORngHiDragRed_swc_out = DDS_FALSE;
    *TqAdp_bDgoORngHiNeut_swc_out = DDS_FALSE;
    *TqAdp_bDgoORngLoDragRed_swc_out = DDS_FALSE;
    *TqAdp_bDgoORngLoNeut_swc_out = DDS_FALSE;
    *TqAdp_bMonRunORngDragRed_swc_out = DDS_FALSE;
    *TqAdp_bMonRunORngNeut_swc_out = DDS_FALSE;


    tqadpcmp_01_02_02_01_01_01_eng_nckfil_dly = 0;
    tqadpcmp_01_02_02_01_01_03_bdragred_dly = 0;

    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_02_01_01_01_turn_on_delay);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_02_01_01_02_turn_off_delay);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_02_01_01_04_turn_on_delay);
    DDS_M_HYST_S32_INIT(&tqadpcmp_01_02_02_01_02_hyst,0);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_02_01_02_turn_off_delay);

    TqAdp_bCorLrnNeut = DDS_FALSE;
    TqAdp_bCorLrnNeutAC = DDS_FALSE;
    TqAdp_tqCorLrnNeutOn = 0;
    TqAdp_tqCorLrnAC = 0;
    TqAdp_bCorLrnAC = DDS_FALSE;

    for(tqadpcmp_index = 0;tqadpcmp_index<TQADPCMP_8_SIZE;tqadpcmp_index++)
    {
        TqAdp_prm_tqCorLrnNeut[tqadpcmp_index] = 0;
        TqAdp_prm_tqCorLrnNeutOn[tqadpcmp_index] = 0;
        TqAdp_prm_tqCorLrnNeutPrev[tqadpcmp_index] = 0;
        TqAdp_prm_tqCorLrnDragRedOn[tqadpcmp_index] = 0;
        TqAdp_prm_tqCorLrnDragRed[tqadpcmp_index] = 0;
        TqAdp_prm_tqCorLrnDragRedPrev[tqadpcmp_index] = 0;
    }

    tqadpcmp_01_02_02_01_04_03_switch_dly = DDS_FALSE;
    tqadpcmp_01_02_02_01_05_03_switch_dly = DDS_FALSE;

    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_01_02_02_01_04_03_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_01_02_02_01_05_03_edge_detect,DDS_FALSE);

    tqadpcmp_01_02_02_02_02_dly1 = 0;
    TqAdp_tqLrnAC_MP = 0;

    TqAdp_tqDeltaDB         = (SInt16)(0 * BIN4);
    tqadpcmp_tqdeltadb_dly  = (SInt16)(0 * BIN4);

    tqadpcmp_04_02_prm_dly_init = DDS_FALSE;
    tqadpcmp_05_02_prm_dly_init = DDS_FALSE;

    TqAdp_tqEfcDragRed_MP = (SInt16)(0 * BIN4);
    TqAdp_bCorLrnDragRedCdn = DDS_FALSE;

    TqAdp_tqCorLrnIrvACPrev = (SInt16)(0 * BIN4);
    TqAdp_bCorLrnIrvACPrev = DDS_FALSE;
    TqAdp_bAcvAdp_MP = DDS_FALSE;

    filter_12213_is_initialised = DDS_FALSE;
    tqadp_tqcorlrnac_is_init = DDS_FALSE;

    TqAdp_bAuthAdpGBx = DDS_FALSE;
    TqAdp_bAuxOff = DDS_FALSE;
    TqAdp_bCorLrnCdnAC = DDS_FALSE;
    TqAdp_bCorLrnDragRed = DDS_FALSE;
    TqAdp_bCorLrnDragRedAC = DDS_FALSE;
    TqAdp_bCorLrnNEngMvCdn = DDS_FALSE;
    TqAdp_bCorLrnNEngMvCdn1_MP = DDS_FALSE;
    TqAdp_bCorLrnNEngMvCdn2_MP = DDS_FALSE;
    TqAdp_bCorLrnNEngMvCdn3_MP = DDS_FALSE;
    TqAdp_bCorLrnNeutCdn = DDS_FALSE;
    TqAdp_bCorLrnWoutAC = DDS_FALSE;
    TqAdp_bSyntCorLrnCdnAC = DDS_FALSE;

    TqAdp_nDeltaNEngNTarIdl_MP = 0;
    TqAdp_nEngMvGrdMax_MP = 0;
    TqAdp_nGrdNEng_MP = 0;
    TqAdp_rEfcACGain_MP = 0;
    TqAdp_rEfcDragRedGain_MP = 0;
    TqAdp_rEfcNeutGain_MP = 0;
    TqAdp_tqCkIdlFil_MP = 0;
    TqAdp_tqCorLrnDragRedOn = 0;
    TqAdp_tqCorLrnDragRedSel_MP = 0;
    TqAdp_tqCorLrnNeutSel_MP = 0;
    TqAdp_tqDeltaAC_MP = 0;
    TqAdp_tqDeltaDragRed_MP = 0;
    TqAdp_tqDeltaNeut_MP = 0;
    TqAdp_tqDeltaTqIdlTqLoss_MP = 0;
    TqAdp_tqEfcAC_MP = 0;
    TqAdp_tqEfcNeut_MP = 0;


}

#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

