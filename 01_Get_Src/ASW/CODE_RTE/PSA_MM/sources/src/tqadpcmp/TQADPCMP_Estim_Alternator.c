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
* Ref X:\integration_view_00PSASWC_E510D02\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Estim_Alternator.c
* Version int :/main/L08_02/2 Date: 30/3/2012 11 h 24 m User:esnault 
*    TWK_model:TQADPCMP_Estim_Alternator_L08_020_IMPL2
*    comments :For TqAdpCmp_11_0_e6_DELIV2
* Version dev :\main\branch_halouane_tqadpcmp_e6\3 Date: 27/3/2012 14 h 54 m User:halouane 
*    TWK_model:TQADPCMP_Estim_Alternator_L08_020_IMPL2
*    comments :For TqAdpCmp_11_0_e6_DELIV2
* Version dev :\main\branch_halouane_tqadpcmp_e6\2 Date: 23/3/2012 17 h 2 m User:halouane
*    TWK_model:TQADPCMP_Estim_Alternator_L08_020_IMPL2
*    comments :For Tq AdpCmp_11_0_e6 / DELIV_2
* Version int :/main/L08_02/1 Date: 21/3/2012 15 h 9 m User:esnault
*    TWK_model:TQADPCMP_Estim_Alternator_L08_020_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 2/3/2012 10 h 25 m User:halouane
*    TWK_model:TQADPCMP_Estim_Alternator_L08_020_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L08_01/1 Date: 14/9/2011 16 h 28 m User:meme
*    TWK_model:TQADPCMP_Estim_Alternator_L08_010_IMPL1
*    comments :UT corrections for TqAdpCmp 10.6
* Version dev :\main\branch_halouane_tqadpcmp_euro6\3 Date: 14/9/2011 9 h 43 m User:halouane
*    TWK_model:TQADPCMP_Estim_Alternator_L08_010_IMPL1
*    comments :UT corrections for TqAdpCmp 10.6
* Version dev :\main\branch_halouane_tqadpcmp_euro6\2 Date: 6/9/2011 12 h 25 m User:halouane
*    TWK_model:TQADPCMP_Estim_Alternator_L08_010_IMPL1
*    comments :change model for TqAdpCmp 10.6
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 26/8/2011 14 h 22 m User:halouane
*    TWK_model:TQADPCMP_Estim_Alternator_L05_010_IMPL1_D
*    comments :For TqAdpCmp_10.6_e6, Add a divirsity constant "OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC",
*    comments :and correction FDS "A0202589".
* Version dev :\main\branch_demezil_tqadpcmp_dev\2 Date: 2/5/2011 9 h 57 m User:demezil
*    TWK_model:TQADPCMP_Estim_Alternator_L05_010_IMPL1_D
*    comments :UT correction
* Version dev :\main\branch_demezil_tqadpcmp_dev\1 Date: 28/4/2011 17 h 21 m User:demezil
*    TWK_model:TQADPCMP_Estim_Alternator_L05_010_IMPL1_D
*    comments :to reduce CPU load
* Version int :/main/L05_01/1 Date: 21/12/2010 17 h 54 m User:esnault
*    TWK_model:TQADPCMP_Estim_Alternator_L05_010_IMPL1
*    comments :For TqAdpCmp 10.3. Correct FDS_32371 . Correct FDS_32968 (model only). Correct FDS_32359.
*    comments :Correct FDS_32209 (model only)
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 25/11/2010 15 h 55 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L05_010_IMPL1
*    comments :correct FDS32371 (TqAdpCmp 10.3)
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 22/11/2010 14 h 41 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L04_011_IMPL1_D
*    comments :correct FDS32371 (TqAdpCmp 10.3)
* Version int :/main/L04_01/1 Date: 18/11/2010 12 h 48 m User:meme
*    TWK_model:TQADPCMP_Estim_Alternator_L04_011_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 17/11/2010 16 h 50 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L04_011_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 16/11/2010 16 h 59 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L04_011_IMPL1
*    comments :For TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 15/11/2010 12 h 29 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L04_011_IMPL1
*    comments :for TqAdpCmp
* Version int :/main/L03_01/1 Date: 13/9/2010 14 h 19 m User:esnault
*    TWK_model:TQADPCMP_Estim_Alternator_L03_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\12 Date: 10/9/2010 12 h 44 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L03_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\11 Date: 10/9/2010 10 h 1 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L03_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\10 Date: 9/9/2010 10 h 27 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L03_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 22/7/2010 10 h 33 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 21/7/2010 17 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 28/6/2010 15 h 40 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 28/6/2010 14 h 28 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Alternator_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
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
#include "SC.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQADPCMP_TMRRST_SCHED                 ((UInt32)10) /* 0.01*DEC3 */
#define TQADPCMP_05_01_03_CPT_MAX             ((UInt32)400)
#define TQADPCMP_ALTERNATEUR_STANDARD     0
#define TQADPCMP_ALTERNATEUR_PILOTE       1
#define TQADPCMP_ALTERNATEUR_REVERSIBLE   2
#define TQADPCMP_CONVERTISSEUR_DC_DC      3

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
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilAltCycOpRate_C = (CONST(UInt16, AUTOMATIC))(0.05 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilDftTqAltLoss_C = (CONST(UInt16, AUTOMATIC))(0.05 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilStrtTqAltLoss_C = (CONST(UInt16, AUTOMATIC))(0.05 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqAltExt_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_facPndTqAlt_C = (CONST(SInt16, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiAfterAltDftFil_C = (CONST(UInt16, AUTOMATIC))(0.1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiAfterAltStrtFil_C = (CONST(UInt16, AUTOMATIC))(0.1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiDftAltRv_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiDlyAltStrt_C = (CONST(UInt16, AUTOMATIC))(0.1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiDlyIdfAlt_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltRvStrt_C = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqGrdFrzAdpAlt_C = (CONST(SInt16, AUTOMATIC))(10 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqThdDftAltRv_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facFilTqAltLoss_C = (CONST(UInt16, AUTOMATIC))(0.05 * BIN10);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_ctAltRvDft_C = (CONST(UInt8, AUTOMATIC))(255 * BIN0);
STATIC volatile CONST(SInt8, AUTOMATIC) TqCmp_facTqAltSign_C = (CONST(SInt8, AUTOMATIC))(1 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltClasDft_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltGapClas1_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltGapClas2_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltGapClas3_C = (CONST(UInt8, AUTOMATIC))(3 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltGapMdl1_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltGapMdl2_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltGapMdl3_C = (CONST(UInt8, AUTOMATIC))(3 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltMdlDft_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqAltLossDown_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10),
(UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10),
(UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10),
(UInt16)(0.1 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqAltLossUp_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10),
(UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10),
(UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10),
(UInt16)(0.05 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_iAltX_A[TQADPCMP_10_SIZE] = {
(UInt16)(0.5 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1.5 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2.5 * BIN4), (UInt16)(3 * BIN4),
(UInt16)(3.5 * BIN4), (UInt16)(4 * BIN4), (UInt16)(4.5 * BIN4),
(UInt16)(5 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_iDftComAltLoss_T
[TQADPCMP_10_SIZE] = {
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_iDftElAltLoss_T
[TQADPCMP_10_SIZE] = {
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_iDftMecAltLoss_T
[TQADPCMP_10_SIZE] = {
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4), (UInt16)(2 * BIN4), (UInt16)(2 * BIN4),
(UInt16)(2 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_nCkEngX_A[TQADPCMP_10_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(750 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1250 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(1750 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(2250 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(2750 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_rAltCycOpRateX_A[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(10 * BIN0), (UInt16)(20 * BIN0),
(UInt16)(30 * BIN0), (UInt16)(40 * BIN0), (UInt16)(50 * BIN0),
(UInt16)(60 * BIN0), (UInt16)(70 * BIN0), (UInt16)(80 * BIN0),
(UInt16)(100 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_rDftComAltStdLoss_T
[TQADPCMP_10_SIZE] = {
(UInt16)(10 * BIN0), (UInt16)(10 * BIN0), (UInt16)(10 * BIN0),
(UInt16)(10 * BIN0), (UInt16)(10 * BIN0), (UInt16)(10 * BIN0),
(UInt16)(10 * BIN0), (UInt16)(10 * BIN0), (UInt16)(10 * BIN0),
(UInt16)(10 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas1Mdl1_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas1Mdl2_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas1Mdl3_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas2Mdl1_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas2Mdl2_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas2Mdl3_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas3Mdl1_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas3Mdl2_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltGapLossClas3Mdl3_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4) },
{
(UInt16)(4.50 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(2.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(1.50 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.13 * BIN4), (UInt16)(1.00 * BIN4), (UInt16)(0.88 * BIN4),
(UInt16)(0.81 * BIN4) },
{
(UInt16)(18.81 * BIN4), (UInt16)(12.50 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(7.50 * BIN4), (UInt16)(6.25 * BIN4), (UInt16)(5.38 * BIN4),
(UInt16)(4.69 * BIN4), (UInt16)(4.19 * BIN4), (UInt16)(3.75 * BIN4),
(UInt16)(3.44 * BIN4) },
{
(UInt16)(25.94 * BIN4), (UInt16)(17.31 * BIN4), (UInt16)(13.00 * BIN4),
(UInt16)(10.38 * BIN4), (UInt16)(8.63 * BIN4), (UInt16)(7.44 * BIN4),
(UInt16)(6.50 * BIN4), (UInt16)(5.75 * BIN4), (UInt16)(5.19 * BIN4),
(UInt16)(4.75 * BIN4) },
{
(UInt16)(33.13 * BIN4), (UInt16)(22.06 * BIN4), (UInt16)(16.56 * BIN4),
(UInt16)(13.25 * BIN4), (UInt16)(11.00 * BIN4), (UInt16)(9.44 * BIN4),
(UInt16)(8.25 * BIN4), (UInt16)(7.38 * BIN4), (UInt16)(6.63 * BIN4),
(UInt16)(6.00 * BIN4) },
{
(UInt16)(40.25 * BIN4), (UInt16)(26.81 * BIN4), (UInt16)(20.13 * BIN4),
(UInt16)(16.13 * BIN4), (UInt16)(13.44 * BIN4), (UInt16)(11.50 * BIN4),
(UInt16)(10.06 * BIN4), (UInt16)(8.94 * BIN4), (UInt16)(8.06 * BIN4),
(UInt16)(7.31 * BIN4) },
{
(UInt16)(47.44 * BIN4), (UInt16)(31.63 * BIN4), (UInt16)(23.69 * BIN4),
(UInt16)(19.00 * BIN4), (UInt16)(15.81 * BIN4), (UInt16)(13.56 * BIN4),
(UInt16)(11.88 * BIN4), (UInt16)(10.56 * BIN4), (UInt16)(9.50 * BIN4),
(UInt16)(8.63 * BIN4) },
{
(UInt16)(54.56 * BIN4), (UInt16)(36.38 * BIN4), (UInt16)(27.31 * BIN4),
(UInt16)(21.81 * BIN4), (UInt16)(18.19 * BIN4), (UInt16)(15.56 * BIN4),
(UInt16)(13.63 * BIN4), (UInt16)(12.13 * BIN4), (UInt16)(10.94 * BIN4),
(UInt16)(9.94 * BIN4) },
{
(UInt16)(61.75 * BIN4), (UInt16)(41.19 * BIN4), (UInt16)(30.88 * BIN4),
(UInt16)(24.69 * BIN4), (UInt16)(20.56 * BIN4), (UInt16)(17.63 * BIN4),
(UInt16)(15.44 * BIN4), (UInt16)(13.75 * BIN4), (UInt16)(12.38 * BIN4),
(UInt16)(11.25 * BIN4) },
{
(UInt16)(68.88 * BIN4), (UInt16)(45.94 * BIN4), (UInt16)(34.44 * BIN4),
(UInt16)(27.56 * BIN4), (UInt16)(23.00 * BIN4), (UInt16)(19.69 * BIN4),
(UInt16)(17.25 * BIN4), (UInt16)(15.31 * BIN4), (UInt16)(13.75 * BIN4),
(UInt16)(12.50 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltItPnd_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltLossMax_T
[TQADPCMP_10_SIZE] = {
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltLossMin_T
[TQADPCMP_10_SIZE] = {
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4),
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4),
(SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4), (SInt16)(-2000 * BIN4),
(SInt16)(-2000 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltPnd_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltStdLossClas1_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(6.0000 * BIN4), (UInt16)(6.0000 * BIN4), (UInt16)(14.0000 * BIN4),
(UInt16)(14.0000 * BIN4), (UInt16)(13.6900 * BIN4), (UInt16)(13.0000 * BIN4),
(UInt16)(8.0000 * BIN4), (UInt16)(13.0000 * BIN4), (UInt16)(11.0000 * BIN4),
(UInt16)(2.3800 * BIN4) },
{
(UInt16)(15.0000 * BIN4), (UInt16)(15.0000 * BIN4), (UInt16)(19.0000 * BIN4),
(UInt16)(19.0000 * BIN4), (UInt16)(18.0000 * BIN4), (UInt16)(17.5000 * BIN4),
(UInt16)(13.0000 * BIN4), (UInt16)(14.0000 * BIN4), (UInt16)(12.0000 * BIN4),
(UInt16)(4.5000 * BIN4) },
{
(UInt16)(22.0000 * BIN4), (UInt16)(22.0000 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(24.0000 * BIN4), (UInt16)(17.0000 * BIN4), (UInt16)(14.5000 * BIN4),
(UInt16)(6.8800 * BIN4) },
{
(UInt16)(24.3800 * BIN4), (UInt16)(24.3800 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(25.6300 * BIN4), (UInt16)(20.1900 * BIN4), (UInt16)(17.3100 * BIN4),
(UInt16)(9.3800 * BIN4) },
{
(UInt16)(35.0000 * BIN4), (UInt16)(32.5000 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(26.0000 * BIN4), (UInt16)(21.0000 * BIN4), (UInt16)(18.0000 * BIN4),
(UInt16)(10.0000 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltStdLossClas2_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(6.0000 * BIN4), (UInt16)(6.0000 * BIN4), (UInt16)(14.0000 * BIN4),
(UInt16)(14.0000 * BIN4), (UInt16)(13.6900 * BIN4), (UInt16)(13.0000 * BIN4),
(UInt16)(8.0000 * BIN4), (UInt16)(13.0000 * BIN4), (UInt16)(11.0000 * BIN4),
(UInt16)(2.3800 * BIN4) },
{
(UInt16)(15.0000 * BIN4), (UInt16)(15.0000 * BIN4), (UInt16)(19.0000 * BIN4),
(UInt16)(19.0000 * BIN4), (UInt16)(18.0000 * BIN4), (UInt16)(17.5000 * BIN4),
(UInt16)(13.0000 * BIN4), (UInt16)(14.0000 * BIN4), (UInt16)(12.0000 * BIN4),
(UInt16)(4.5000 * BIN4) },
{
(UInt16)(22.0000 * BIN4), (UInt16)(22.0000 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(24.0000 * BIN4), (UInt16)(17.0000 * BIN4), (UInt16)(14.5000 * BIN4),
(UInt16)(6.8800 * BIN4) },
{
(UInt16)(24.3800 * BIN4), (UInt16)(24.3800 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(25.6300 * BIN4), (UInt16)(20.1900 * BIN4), (UInt16)(17.3100 * BIN4),
(UInt16)(9.3800 * BIN4) },
{
(UInt16)(35.0000 * BIN4), (UInt16)(32.5000 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(26.0000 * BIN4), (UInt16)(21.0000 * BIN4), (UInt16)(18.0000 * BIN4),
(UInt16)(10.0000 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqAltStdLossClas3_M
[TQADPCMP_10_SIZE][TQADPCMP_10_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(6.0000 * BIN4), (UInt16)(6.0000 * BIN4), (UInt16)(14.0000 * BIN4),
(UInt16)(14.0000 * BIN4), (UInt16)(13.6900 * BIN4), (UInt16)(13.0000 * BIN4),
(UInt16)(8.0000 * BIN4), (UInt16)(13.0000 * BIN4), (UInt16)(11.0000 * BIN4),
(UInt16)(2.3800 * BIN4) },
{
(UInt16)(15.0000 * BIN4), (UInt16)(15.0000 * BIN4), (UInt16)(19.0000 * BIN4),
(UInt16)(19.0000 * BIN4), (UInt16)(18.0000 * BIN4), (UInt16)(17.5000 * BIN4),
(UInt16)(13.0000 * BIN4), (UInt16)(14.0000 * BIN4), (UInt16)(12.0000 * BIN4),
(UInt16)(4.5000 * BIN4) },
{
(UInt16)(22.0000 * BIN4), (UInt16)(22.0000 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(24.0000 * BIN4), (UInt16)(17.0000 * BIN4), (UInt16)(14.5000 * BIN4),
(UInt16)(6.8800 * BIN4) },
{
(UInt16)(24.3800 * BIN4), (UInt16)(24.3800 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(25.6300 * BIN4), (UInt16)(20.1900 * BIN4), (UInt16)(17.3100 * BIN4),
(UInt16)(9.3800 * BIN4) },
{
(UInt16)(35.0000 * BIN4), (UInt16)(32.5000 * BIN4), (UInt16)(30.0000 * BIN4),
(UInt16)(30.0000 * BIN4), (UInt16)(29.0000 * BIN4), (UInt16)(28.0000 * BIN4),
(UInt16)(26.0000 * BIN4), (UInt16)(21.0000 * BIN4), (UInt16)(18.0000 * BIN4),
(UInt16)(10.0000 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltY_A[TQADPCMP_10_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(15 * BIN4), (SInt16)(20 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(30 * BIN4), (SInt16)(35 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(50 * BIN4)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxAltStdClas_T[TQADPCMP_8_SIZE] = {
(UInt8)(1 * BIN0), (UInt8)(1 * BIN0), (UInt8)(1 * BIN0), (UInt8)(1 * BIN0),
(UInt8)(1 * BIN0), (UInt8)(1 * BIN0), (UInt8)(1 * BIN0), (UInt8)(1 * BIN0)
};

#define TQADPCMP_STOP_SEC_CARTO_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqaltlossdown_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqaltlossup_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_idftcomaltloss_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_idftelaltloss_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_idftmecaltloss_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_rdftcomaltstdloss_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas1mdl1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas1mdl2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas1mdl3_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas2mdl1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas2mdl2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas2mdl3_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas3mdl1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas3mdl2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltgaplossclas3mdl3_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltitpnd_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tqaltlossmax_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tqaltlossmin_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltpnd_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltstdlossclas1_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltstdlossclas2_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_tqaltstdlossclas3_m_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_02_filtre;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_05_03_filtre;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_05_01_02_02_filtre;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_05_turn_off_delay1;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_05_turn_off_delay2;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_05_turn_off_delay3;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_05_01_03_turn_off_delay;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqcmp_tqaltloss_prev;
STATIC VAR(UInt16, AUTOMATIC) tqadpcmp_05_01_01_tmrrst_value;
STATIC VAR(UInt16, AUTOMATIC) tqadpcmp_05_01_03_counter;
#define TQADPCMP_STOP_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_05_01_01_is_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_02_filter_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_05_01_01_or_output_prev;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_05_01_01_tmrrst_output;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_05_01_02_02_filter_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_05_03_filter_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) AltCtl_iAltSel; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_facFilTqAltLoss_MP; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAltLossExt; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqAltLossGap; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAltLossItUnlim; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAltLossRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAltLossSTT; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqAltLossStd; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAltLossTrvUnlim; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAltSel; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) AltCtl_idxAltClasSel; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) AltCtl_idxAltMdlSel; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) Ext_rAltStdCycOpSel; /* BIN0 */
/* <PRQA_COMMENT><3229> Variable is used as a mesure point </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bFrzAdpAlt_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bAltTypDft;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bDftAltFilAcv;
/* <PRQA_COMMENT><3229> Variable is used as a mesure point </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bDftAltTyp_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bDftIdfAlt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bDgo_tqAltRvIt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bEngStrtReqAlt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bStrtAltFilAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bTqAltLossMax;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bTqAltLossMin;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bTqAltLossOff;
/* <PRQA_COMMENT><3229> Variable is used as a mesure point </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_idxFacFilTqAltLoss_MP; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQALTLOSSDOWN_T_APM = {
&tqcmp_facfiltqaltlossdown_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqAltLossDown_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQALTLOSSUP_T_APM = {
&tqcmp_facfiltqaltlossup_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqAltLossUp_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_IDFTCOMALTLOSS_T_APM = {
&tqcmp_idftcomaltloss_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iDftComAltLoss_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_IDFTELALTLOSS_T_APM = {
&tqcmp_idftelaltloss_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iDftElAltLoss_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_IDFTMECALTLOSS_T_APM = {
&tqcmp_idftmecaltloss_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iDftMecAltLoss_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_RDFTCOMALTSTDLOSS_T_APM = {
&tqcmp_rdftcomaltstdloss_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rDftComAltStdLoss_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS1MDL1_M_APM = {
&tqcmp_tqaltgaplossclas1mdl1_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas1Mdl1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS1MDL2_M_APM = {
&tqcmp_tqaltgaplossclas1mdl2_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas1Mdl2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS1MDL3_M_APM = {
&tqcmp_tqaltgaplossclas1mdl3_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas1Mdl3_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS2MDL1_M_APM = {
&tqcmp_tqaltgaplossclas2mdl1_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas2Mdl1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS2MDL2_M_APM = {
&tqcmp_tqaltgaplossclas2mdl2_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas2Mdl2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS2MDL3_M_APM = {
&tqcmp_tqaltgaplossclas2mdl3_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas2Mdl3_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS3MDL1_M_APM = {
&tqcmp_tqaltgaplossclas3mdl1_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas3Mdl1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS3MDL2_M_APM = {
&tqcmp_tqaltgaplossclas3mdl2_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas3Mdl2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTGAPLOSSCLAS3MDL3_M_APM = {
&tqcmp_tqaltgaplossclas3mdl3_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_iAltX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltGapLossClas3Mdl3_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) TQCMP_TQALTITPND_M_APM = {
&tqcmp_tqaltitpnd_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltItPnd_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQCMP_TQALTLOSSMAX_T_APM = {
&tqcmp_tqaltlossmax_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltLossMax_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQCMP_TQALTLOSSMIN_T_APM = {
&tqcmp_tqaltlossmin_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltLossMin_T[0]
};

STATIC CONST(t_dds_m_map3d_uss16, AUTOMATIC) TQCMP_TQALTPND_M_APM = {
&tqcmp_tqaltpnd_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltPnd_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTSTDLOSSCLAS1_M_APM = {
&tqcmp_tqaltstdlossclas1_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rAltCycOpRateX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltStdLossClas1_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTSTDLOSSCLAS2_M_APM = {
&tqcmp_tqaltstdlossclas2_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rAltCycOpRateX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltStdLossClas2_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TQALTSTDLOSSCLAS3_M_APM = {
&tqcmp_tqaltstdlossclas3_m_sav,
TQADPCMP_10_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rAltCycOpRateX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqAltStdLossClas3_M[0][0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Couple_Externe(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           SInt16 cooptmel_tqalt_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Couple_Interne(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt8 frm_bdftalttyp_par,
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 ext_idxaltclas_par, /* BIN0 */
                                           UInt8 ext_idxctlaltprovidf_par, /* BIN0 */
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 ext_raltcycop_par, /* BIN0 */
                                           UInt8 coptuh_stpwt_par,
                                           UInt8 ext_stelprodcf_par,
                                           UInt8 tqdem_btqgrdlim_par,
                                           UInt8 coptst_steng_par,
                                           UInt8 ext_staltclascf_par,
                                           UInt16 ext_facrattqaltcf_par, /* BIN7 */
                                           UInt8 frm_binhaltlossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_Traitement_Des_Entrees(
                                           UInt8 coptst_steng_par,
                                           UInt8 coptuh_stpwt_par,
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt8 ext_idxaltclas_par, /* BIN0 */
                                           UInt8 ext_idxctlaltprovidf_par, /* BIN0 */
                                           UInt8 ext_raltcycop_par, /* BIN0 */
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 frm_bdftalttyp_par,
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 frm_binhaltlossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_01_Identification_Alternateur(
                                           UInt8 frm_bdftalttyp_par,
                                           UInt8 ext_idxaltclas_par, /* BIN0 */
                                           UInt8 ext_idxctlaltprovidf_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_Gestion_Temporisations(
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 coptst_steng_par,
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 frm_binhaltlossmdl_par,
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_raltcycop_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_01_Gestion_Defaut_IAlt(
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_02_Gestion_Defaut_RCO(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 frm_binhaltlossmdl_par,
                                           UInt8 ext_raltcycop_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_03_Gestion_Defaut_STT(
                                           UInt8 frm_binhaltlossmdl_par,
                                           SInt16 ext_tqalt_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_04_Gestion_Defaut_Generique(
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 frm_binhaltlossmdl_par,
                                           UInt8 coptst_steng_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_03_Diag_Functionnel_MEL(
                                           UInt8 coptuh_stpwt_par,
                                           SInt16 ext_tqalt_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_Calcul_Du_Couple(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_stelprodcf_par,
                                           UInt8 ext_staltclascf_par,
                                           UInt16 ext_facrattqaltcf_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_01_ICCP(
                                           UInt8 ext_staltclascf_par,
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_02_GAP(
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(UInt16, AUTOMATIC) TQADPCMP_05_02_02_Gap_P1(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqcmp_bidxclas1vld_par,
                                           UInt8 tqcmp_bidxclas2vld_par,
                                           UInt8 tqcmp_bidxclas3vld_par);

STATIC FUNC(UInt16, AUTOMATIC) TQADPCMP_05_02_02_Gap_P2(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqcmp_bidxclas1vld_par,
                                           UInt8 tqcmp_bidxclas2vld_par,
                                           UInt8 tqcmp_bidxclas3vld_par);

STATIC FUNC(UInt16, AUTOMATIC) TQADPCMP_05_02_02_Gap_P3(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqcmp_bidxclas1vld_par,
                                           UInt8 tqcmp_bidxclas2vld_par,
                                           UInt8 tqcmp_bidxclas3vld_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_03_STT_HY(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt16 ext_facrattqaltcf_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_03_Filtrage(
                                           UInt8 tqdem_btqgrdlim_par,
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Limitation(
                                           UInt16 tqres_tqfanstrtloss_par, /* BIN4 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqaltloss_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Adaptation_Alternator(
                                           SInt16 tqcmp_tqaltloss_par, /* BIN4 */
                                           UInt8 frm_binhaltlossmdl_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpalton_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Alternator
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Alternator(SInt16 CoOptmEl_tqAlt_swc_in, /* BIN4 */
                                           UInt8 CoPTSt_stEng_swc_in,
                                           UInt8 CoPtUH_stPwt_swc_in,
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_bTqAltEstimElSys_swc_in,
                                           UInt16 Ext_facRatTqAltCf_swc_in, /* BIN7 */
                                           UInt8 Ext_iAltExct_swc_in, /* DEC1 */
                                           UInt8 Ext_idxAltClas_swc_in, /* BIN0 */
                                           UInt8 Ext_idxCtlAltProvIdf_swc_in, /* BIN0 */
                                           UInt8 Ext_rAltCycOp_swc_in, /* BIN0 */
                                           UInt8 Ext_stAltClasCf_swc_in,
                                           UInt8 Ext_stElProdCf_swc_in,
                                           SInt16 Ext_tqAlt_swc_in, /* BIN4 */
                                           UInt8 FRM_bDftAltTyp_swc_in,
                                           UInt8 FRM_bDftComAlt_swc_in,
                                           UInt8 FRM_bDftElAlt_swc_in,
                                           UInt8 FRM_bDftMecAlt_swc_in,
                                           UInt8 FRM_bInhAltLossMdl_swc_in,
                                           UInt8 TqDem_bTqGrdLim_swc_in,
                                           UInt16 TqRes_tqFanStrtLoss_swc_in, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpAltOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bDgo_tqAltRv_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAltLoss_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.1.1 */
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.19.0 */



    if((UInt32)Ext_bTqAltEstimElSys_swc_in!=(UInt32)DDS_FALSE)
    {

        /* Calculation of TqCmp_tqAltLossExt */
        TQADPCMP_02_Couple_Externe(Eng_nCkFil_swc_in, /* BIN2 */
                               CoOptmEl_tqAlt_swc_in /* BIN4 */);

        *TqCmp_bDgo_tqAltRv_swc_out = DDS_FALSE;
        TqCmp_tqAltLossTrvUnlim = TqCmp_tqAltLossExt;

    }
    else
    {	/* <PRQA_COMMENT><2742>  statement value change with VSCtl_bCtlCmdPTTqCf_SC </2742></PRQA_COMMENT> */
		if ((UInt32)0 ==  (UInt32)OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC)
		{  /* Calculation of TqCmp_bDgo_tqAltRvIt and TqCmp_tqAltLossItUnlim */
     		 /* <PRQA_COMMENT><2880> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2880></PRQA_COMMENT> */
     		 TQADPCMP_05_Couple_Interne(Eng_nCkFil_swc_in, /* BIN2 */
                                  Ext_iAltExct_swc_in, /* BIN4 */
                                  FRM_bDftAltTyp_swc_in,
                                  FRM_bDftComAlt_swc_in,
                                  FRM_bDftElAlt_swc_in,
                                  FRM_bDftMecAlt_swc_in,
                                  Ext_idxAltClas_swc_in, /* BIN0 */
                                  Ext_idxCtlAltProvIdf_swc_in, /* BIN0 */
                                  Ext_tqAlt_swc_in, /* BIN4 */
                                  Ext_rAltCycOp_swc_in, /* BIN0 */
                                  CoPtUH_stPwt_swc_in,
                                  Ext_stElProdCf_swc_in,
                                  TqDem_bTqGrdLim_swc_in,
                                  CoPTSt_stEng_swc_in,
                                  Ext_stAltClasCf_swc_in,
                                  Ext_facRatTqAltCf_swc_in, /* BIN7 */
                                  FRM_bInhAltLossMdl_swc_in);
		}

		else
		{
				TqCmp_tqAltLossItUnlim = 0;
				TqCmp_bDgo_tqAltRvIt = 0;
		}

	*TqCmp_bDgo_tqAltRv_swc_out = TqCmp_bDgo_tqAltRvIt;
	TqCmp_tqAltLossTrvUnlim = TqCmp_tqAltLossItUnlim;
	}




    TQADPCMP_03_Limitation(TqRes_tqFanStrtLoss_swc_in, /* BIN4 */
                           Eng_nCkFil_swc_in, /* BIN2 */
                           TqCmp_tqAltLoss_swc_out /* BIN4 */);

    TQADPCMP_04_Adaptation_Alternator(*TqCmp_tqAltLoss_swc_out, /* BIN4 */
                           FRM_bInhAltLossMdl_swc_in,
                           TqAdp_bFrzAdpAltOn_swc_out);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_02_Couple_Externe
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Couple_Externe(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           SInt16 cooptmel_tqalt_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.2.0 */
    SInt32 tqadpcmp_02_sval;
    SInt32 tqadpcmp_02_map_out;

    tqadpcmp_02_sval = ((SInt32)cooptmel_tqalt_par * (SInt32)TqCmp_facPndTqAlt_C) / BIN4;
    tqadpcmp_02_sval = DDS_M_LIMIT(tqadpcmp_02_sval,-2000*BIN4,2000*BIN4);
    tqadpcmp_02_map_out = (SInt32)DDS_M_MAP3D_USS16(&TQCMP_TQALTPND_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),(SInt16)tqadpcmp_02_sval);

    if((UInt32)tqadpcmp_02_filter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_02_filter_init = DDS_TRUE;
        TqCmp_tqAltLossExt = DDS_M_FILTER_LP1_S16_INIT(&tqadpcmp_02_filtre, (SInt16)tqadpcmp_02_map_out);
    }
    else
    {
        TqCmp_tqAltLossExt = DDS_M_FILTER_LP1_S16(&tqadpcmp_02_filtre, (SInt16)tqadpcmp_02_map_out, TqCmp_facFilTqAltExt_C, BIN10);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Limitation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Limitation(
                                           UInt16 tqres_tqfanstrtloss_par, /* BIN4 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqaltloss_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.3.0 */
    SInt32 tqadpcmp_03_sval;
    SInt32 tqadpcmp_03_sval2;
    SInt32 tqadpcmp_03_sval3;

    tqadpcmp_03_sval = (SInt32)TqCmp_tqAltLossTrvUnlim + (SInt32)tqres_tqfanstrtloss_par ;
    tqadpcmp_03_sval2 = (SInt32) DDS_M_MAP2D_US16(&TQCMP_TQALTLOSSMAX_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
    tqadpcmp_03_sval3 = (SInt32) DDS_M_MAP2D_US16(&TQCMP_TQALTLOSSMIN_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));

    if(tqadpcmp_03_sval>=tqadpcmp_03_sval2)
    {
        TqCmp_bTqAltLossMax = DDS_TRUE;
        TqCmp_bTqAltLossMin = DDS_FALSE;
    }
    else if(tqadpcmp_03_sval<=tqadpcmp_03_sval3)
    {
        TqCmp_bTqAltLossMax = DDS_FALSE;
        TqCmp_bTqAltLossMin = DDS_TRUE;
    }
    else
    {
        TqCmp_bTqAltLossMax = DDS_FALSE;
        TqCmp_bTqAltLossMin = DDS_FALSE;
    }

    *tqcmp_tqaltloss_ptr = (SInt16) DDS_M_SATURATION_V2(tqadpcmp_03_sval,tqadpcmp_03_sval3,tqadpcmp_03_sval2);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Adaptation_Alternator
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Adaptation_Alternator(
                                           SInt16 tqcmp_tqaltloss_par, /* BIN4 */
                                           UInt8 frm_binhaltlossmdl_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpalton_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.4.0 */
    SInt32 tqadpcmp_04_sval;

    tqadpcmp_04_sval = DDS_M_ABS((SInt32)tqcmp_tqaltloss_par-(SInt32)tqcmp_tqaltloss_prev);
    tqcmp_tqaltloss_prev = tqcmp_tqaltloss_par;

    if(  ((SInt32)tqcmp_tqaltloss_par != (SInt32)0)
       &&(  ((UInt32)TqCmp_bTqAltLossMax != (UInt32)DDS_FALSE)
          ||((UInt32)TqCmp_bTqAltLossMin != (UInt32)DDS_FALSE)
          ||(tqadpcmp_04_sval >= (SInt32)TqCmp_tqGrdFrzAdpAlt_C)))
    {
        TqAdp_bFrzAdpAlt_MP = DDS_TRUE;
        *tqadp_bfrzadpalton_ptr = DDS_TRUE;
    }
    else
    {
        TqAdp_bFrzAdpAlt_MP = DDS_FALSE;
        if((UInt32)frm_binhaltlossmdl_par != (UInt32)DDS_FALSE)
        {
            *tqadp_bfrzadpalton_ptr = DDS_TRUE;
        }
        else
        {
            *tqadp_bfrzadpalton_ptr = DDS_FALSE;
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_Couple_Interne
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Couple_Interne(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt8 frm_bdftalttyp_par,
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 ext_idxaltclas_par, /* BIN0 */
                                           UInt8 ext_idxctlaltprovidf_par, /* BIN0 */
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 ext_raltcycop_par, /* BIN0 */
                                           UInt8 coptuh_stpwt_par,
                                           UInt8 ext_stelprodcf_par,
                                           UInt8 tqdem_btqgrdlim_par,
                                           UInt8 coptst_steng_par,
                                           UInt8 ext_staltclascf_par,
                                           UInt16 ext_facrattqaltcf_par, /* BIN7 */
                                           UInt8 frm_binhaltlossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.5.1 */
    TQADPCMP_05_01_Traitement_Des_Entrees(coptst_steng_par,
                                          coptuh_stpwt_par,
                                          eng_nckfil_par, /* BIN2 */
                                          ext_ialtexct_par, /* DEC1 */
                                          ext_idxaltclas_par, /* BIN0 */
                                          ext_idxctlaltprovidf_par, /* BIN0 */
                                          ext_raltcycop_par, /* BIN0 */
                                          ext_tqalt_par, /* BIN4 */
                                          frm_bdftalttyp_par,
                                          frm_bdftcomalt_par,
                                          frm_bdftelalt_par,
                                          frm_bdftmecalt_par,
                                          frm_binhaltlossmdl_par);

    TQADPCMP_05_02_Calcul_Du_Couple(eng_nckfil_par, /* BIN2 */
                                    ext_stelprodcf_par,
                                    ext_staltclascf_par,
                                    ext_facrattqaltcf_par /* BIN7 */);

    TQADPCMP_05_03_Filtrage(tqdem_btqgrdlim_par,
                            eng_nckfil_par /* BIN2 */);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_Traitement_Des_Entrees
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_Traitement_Des_Entrees(
                                           UInt8 coptst_steng_par,
                                           UInt8 coptuh_stpwt_par,
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt8 ext_idxaltclas_par, /* BIN0 */
                                           UInt8 ext_idxctlaltprovidf_par, /* BIN0 */
                                           UInt8 ext_raltcycop_par, /* BIN0 */
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 frm_bdftalttyp_par,
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 frm_binhaltlossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.6.0 */

    TQADPCMP_05_01_01_Identification_Alternateur(frm_bdftalttyp_par,
                                                 ext_idxaltclas_par, /* BIN0 */
                                                 ext_idxctlaltprovidf_par /* BIN0 */);

    TQADPCMP_05_01_02_Gestion_Temporisations(ext_tqalt_par, /* BIN4 */
                                             coptst_steng_par,
                                             ext_ialtexct_par, /* DEC1 */
                                             frm_bdftcomalt_par,
                                             frm_bdftelalt_par,
                                             frm_bdftmecalt_par,
                                             frm_binhaltlossmdl_par,
                                             eng_nckfil_par, /* BIN2 */
                                             ext_raltcycop_par /* BIN0 */);

    TQADPCMP_05_01_03_Diag_Functionnel_MEL(coptuh_stpwt_par,
                                           ext_tqalt_par /* BIN4 */);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_01_Identification_Alternateur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_01_Identification_Alternateur(
                                           UInt8 frm_bdftalttyp_par,
                                           UInt8 ext_idxaltclas_par, /* BIN0 */
                                           UInt8 ext_idxctlaltprovidf_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.7.0 */
    /* Timer reset implementation */ /* there is no reset in this one, input link to 0 */
    if((UInt32)tqadpcmp_05_01_01_is_init == (UInt32)DDS_FALSE)
    {
		tqadpcmp_05_01_01_tmrrst_value = (UInt16)((UInt32)TqCmp_tiDlyIdfAlt_C * DEC1);
		if((UInt32)tqadpcmp_05_01_01_tmrrst_value == 0)
		{
			tqadpcmp_05_01_01_tmrrst_output = DDS_FALSE;
		}
		else
		{
			tqadpcmp_05_01_01_tmrrst_output = DDS_TRUE;
		}
		tqadpcmp_05_01_01_is_init = DDS_TRUE;
	}
    else
    {
		if((UInt32)tqadpcmp_05_01_01_tmrrst_value <= TQADPCMP_TMRRST_SCHED)
		{
			tqadpcmp_05_01_01_tmrrst_value = 0;
			tqadpcmp_05_01_01_tmrrst_output = DDS_FALSE;
		}
		else
		{
			tqadpcmp_05_01_01_tmrrst_value = (UInt16)((UInt32)tqadpcmp_05_01_01_tmrrst_value - TQADPCMP_TMRRST_SCHED);
			tqadpcmp_05_01_01_tmrrst_output = DDS_TRUE;
		}
	}

    if( ((UInt32)tqadpcmp_05_01_01_tmrrst_output != (UInt32)DDS_FALSE)  ||
        ((UInt32)tqadpcmp_05_01_01_or_output_prev != (UInt32)DDS_FALSE) ||
        ((UInt32)frm_bdftalttyp_par != (UInt32)DDS_FALSE)   )
    {
        if((UInt32)DDS_FALSE == (UInt32)frm_bdftalttyp_par)
        {
            TqCmp_bDftAltTyp_MP = DDS_TRUE;
        }
        else
        {
            TqCmp_bDftAltTyp_MP = DDS_FALSE;
        }
        TqCmp_bAltTypDft = DDS_TRUE;
        AltCtl_idxAltMdlSel = TqCmp_idxAltMdlDft_C;
        AltCtl_idxAltClasSel = TqCmp_idxAltClasDft_C;
    }
    else
    {
        TqCmp_bDftAltTyp_MP = DDS_FALSE;
        TqCmp_bAltTypDft = DDS_FALSE;
        AltCtl_idxAltMdlSel = ext_idxctlaltprovidf_par;
        AltCtl_idxAltClasSel = ext_idxaltclas_par;
    }


}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_02_Gestion_Temporisations
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_Gestion_Temporisations(
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 coptst_steng_par,
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 frm_binhaltlossmdl_par,
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_raltcycop_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.8.0 */
    TQADPCMP_05_01_02_01_Gestion_Defaut_IAlt(frm_bdftcomalt_par,
                                             frm_bdftelalt_par,
                                             frm_bdftmecalt_par,
                                             ext_ialtexct_par, /* DEC1 */
                                             eng_nckfil_par /* BIN2 */);

    TQADPCMP_05_01_02_02_Gestion_Defaut_RCO(eng_nckfil_par, /* BIN2 */
                                            frm_binhaltlossmdl_par,
                                            ext_raltcycop_par /* BIN0 */);

    TQADPCMP_05_01_02_03_Gestion_Defaut_STT(frm_binhaltlossmdl_par,
                                            ext_tqalt_par /* BIN4 */);

    TQADPCMP_05_01_02_04_Gestion_Defaut_Generique(ext_tqalt_par, /* BIN4 */
                                                  frm_binhaltlossmdl_par,
                                                  coptst_steng_par);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_02_01_Gestion_Defaut_IAlt
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_01_Gestion_Defaut_IAlt(
                                           UInt8 frm_bdftcomalt_par,
                                           UInt8 frm_bdftelalt_par,
                                           UInt8 frm_bdftmecalt_par,
                                           UInt8 ext_ialtexct_par, /* DEC1 */
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.9.0 */

    if((UInt32)frm_bdftelalt_par!=(UInt32)DDS_FALSE)
    {
        AltCtl_iAltSel = DDS_M_MAP2D_U16(&TQCMP_IDFTELALTLOSS_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
    }
    else if((UInt32)frm_bdftcomalt_par!=(UInt32)DDS_FALSE)
    {
        AltCtl_iAltSel = DDS_M_MAP2D_U16(&TQCMP_IDFTCOMALTLOSS_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
    }
    else if((UInt32)frm_bdftmecalt_par!=(UInt32)DDS_FALSE)
    {
        AltCtl_iAltSel = DDS_M_MAP2D_U16(&TQCMP_IDFTMECALTLOSS_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
    }
    else
    {
        AltCtl_iAltSel = (UInt16)(((UInt32)ext_ialtexct_par*BIN4)/DEC1);
    }


}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_02_02_Gestion_Defaut_RCO
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_02_Gestion_Defaut_RCO(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 frm_binhaltlossmdl_par,
                                           UInt8 ext_raltcycop_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.10.0 */
    UInt16 TQADPCMP_05_01_02_02_filter_in;

    if((UInt32)frm_binhaltlossmdl_par!=(UInt32)DDS_FALSE)
    {
        TQADPCMP_05_01_02_02_filter_in = DDS_M_MAP2D_U16(&TQCMP_RDFTCOMALTSTDLOSS_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
    }
    else
    {
        TQADPCMP_05_01_02_02_filter_in = (UInt16)ext_raltcycop_par;
    }

    if((UInt32)tqadpcmp_05_01_02_02_filter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_05_01_02_02_filter_init = DDS_TRUE;
        Ext_rAltStdCycOpSel = (UInt8)DDS_M_FILTER_LP1_U16_INIT(&tqadpcmp_05_01_02_02_filtre, TQADPCMP_05_01_02_02_filter_in);
    }
    else
    {
        Ext_rAltStdCycOpSel = (UInt8)DDS_M_FILTER_LP1_U16(&tqadpcmp_05_01_02_02_filtre,
                                                          TQADPCMP_05_01_02_02_filter_in,
                                                          TqCmp_facFilAltCycOpRate_C,
                                                          BIN10);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_02_03_Gestion_Defaut_STT
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_03_Gestion_Defaut_STT(
                                           UInt8 frm_binhaltlossmdl_par,
                                           SInt16 ext_tqalt_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.11.0 */
    if((UInt32)frm_binhaltlossmdl_par!=(UInt32)DDS_FALSE)
    {
        TqCmp_tqAltSel = 0;
    }
    else
    {
        TqCmp_tqAltSel = ext_tqalt_par;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_02_04_Gestion_Defaut_Generique
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_02_04_Gestion_Defaut_Generique(
                                           SInt16 ext_tqalt_par, /* BIN4 */
                                           UInt8 frm_binhaltlossmdl_par,
                                           UInt8 coptst_steng_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.12.0 */
    UInt8 tqadpcmp_05_01_02_04_bool;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    if(  ((UInt32)coptst_steng_par == 3)
       ||((UInt32)coptst_steng_par == 7))
    {
        TqCmp_bEngStrtReqAlt = DDS_TRUE;
        tqadpcmp_05_01_02_04_bool = DDS_TRUE;
    }
    else
    {
        TqCmp_bEngStrtReqAlt = DDS_FALSE;
        if((SInt32)ext_tqalt_par == (SInt32)TqCmp_tqAltRvStrt_C)
        {
            tqadpcmp_05_01_02_04_bool = DDS_TRUE;
        }
        else
        {
            tqadpcmp_05_01_02_04_bool = DDS_FALSE;
        }
    }

    TqCmp_bTqAltLossOff = DDS_M_TURN_OFF_DELAY(tqadpcmp_05_01_02_04_bool,
                                               tqadpcmp_te,
                                               ((UInt32)TqCmp_tiDlyAltStrt_C*DEC1),
                                               &tqadpcmp_05_turn_off_delay1);

    TqCmp_bStrtAltFilAcv = DDS_M_TURN_OFF_DELAY(TqCmp_bTqAltLossOff,
                                               tqadpcmp_te,
                                               ((UInt32)TqCmp_tiAfterAltStrtFil_C*DEC1),
                                               &tqadpcmp_05_turn_off_delay2);

    if(  ((UInt32)frm_binhaltlossmdl_par == (UInt32)DDS_TRUE)
       ||((UInt32)TqCmp_bAltTypDft == (UInt32)DDS_TRUE))
    {
        TqCmp_bDftAltFilAcv = DDS_M_TURN_OFF_DELAY(DDS_TRUE,
                                                   tqadpcmp_te,
                                                   ((UInt32)TqCmp_tiAfterAltDftFil_C*DEC1),
                                                   &tqadpcmp_05_turn_off_delay3);
    }
    else
    {
        TqCmp_bDftAltFilAcv = DDS_M_TURN_OFF_DELAY(DDS_FALSE,
                                                   tqadpcmp_te,
                                                   ((UInt32)TqCmp_tiAfterAltDftFil_C*DEC1),
                                                   &tqadpcmp_05_turn_off_delay3);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_01_03_Diag_Functionnel_MEL
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_01_03_Diag_Functionnel_MEL(
                                           UInt8 coptuh_stpwt_par,
                                           SInt16 ext_tqalt_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.13.0 */
    UInt32 test_status;
    UInt32 t_off_status;
    SInt32 tqadpcmp_05_01_03_tq; /* [-2000; 2000] bin4 */
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    if ((UInt32)coptuh_stpwt_par <= (UInt32)11)
    {
        tqadpcmp_05_01_03_tq = (SInt32)ext_tqalt_par;
    }
    else
    {
        tqadpcmp_05_01_03_tq = -(SInt32)ext_tqalt_par;
    }

    if(tqadpcmp_05_01_03_tq >= (SInt32)TqCmp_tqThdDftAltRv_C)
    {
        test_status = (UInt32)DDS_TRUE;
    }
    else
    {
        test_status = (UInt32)DDS_FALSE;
    }

    /* Counter */
    if ((UInt32)DDS_TRUE != (UInt32)TqCmp_bEngStrtReqAlt)
    {
        /* Increment counter if possible */
        if (  ((UInt32)tqadpcmp_05_01_03_counter < TQADPCMP_05_01_03_CPT_MAX)
            &&(test_status!=(UInt32)DDS_TRUE))
        {
            tqadpcmp_05_01_03_counter = (UInt16)((UInt32)tqadpcmp_05_01_03_counter + (UInt32)1);
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Clear counter */
        tqadpcmp_05_01_03_counter = 0;
    }

    /* Turn off delay */
    t_off_status = (UInt32)DDS_M_TURN_OFF_DELAY((UInt8)test_status,
                                                tqadpcmp_te,
                                                ((UInt32)TqCmp_tiDftAltRv_C * DEC1),
                                                &tqadpcmp_05_01_03_turn_off_delay);

    /* TqCmp_bDgo_tqMEL */
    /*------------------*/
    if (((UInt32)tqadpcmp_05_01_03_counter >= (UInt32)TqCmp_ctAltRvDft_C) ||
        ((UInt32)DDS_FALSE != t_off_status))
    {
        TqCmp_bDgo_tqAltRvIt = DDS_TRUE;
    }
    else
    {
        TqCmp_bDgo_tqAltRvIt = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_Calcul_Du_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_Calcul_Du_Couple(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 ext_stelprodcf_par,
                                           UInt8 ext_staltclascf_par,
                                           UInt16 ext_facrattqaltcf_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.14.0 */
    if((UInt32)TQADPCMP_ALTERNATEUR_PILOTE == (UInt32)ext_stelprodcf_par)
    {
		/* F05_02_01_ICCP (reset) */
		TqCmp_tqAltLossStd = 0;

		/* F05_02_02_GAP */
        TQADPCMP_05_02_02_GAP(eng_nckfil_par /* BIN2 */);
        if((UInt32)TqCmp_bTqAltLossOff != (UInt32)DDS_FALSE)
        {
            TqCmp_tqAltLossRaw = 0;
        }
        else
        {
            TqCmp_tqAltLossRaw = (SInt16)TqCmp_tqAltLossGap;
        }

		/* F05_02_03_STT_HY (reset) */
		TqCmp_tqAltLossSTT = 0;
    }
    else
    {
		if((UInt32)TqCmp_bTqAltLossOff != (UInt32)DDS_FALSE)
        {
            TqCmp_tqAltLossRaw = 0;

        }
        else
        {
            if( ((UInt32)TQADPCMP_ALTERNATEUR_REVERSIBLE == (UInt32)ext_stelprodcf_par) ||
                ((UInt32)TQADPCMP_CONVERTISSEUR_DC_DC == (UInt32)ext_stelprodcf_par) )
            {
				 /* F05_02_01_ICCP (reset) */
				TqCmp_tqAltLossStd = 0;
				/* F05_02_02_GAP (reset) */
				TqCmp_tqAltLossGap = 0;
			    TqCmp_bDftIdfAlt = DDS_FALSE;

				  /* F05_02_03_STT_HY */
                TQADPCMP_05_02_03_STT_HY(eng_nckfil_par, /* BIN2 */
                                         ext_facrattqaltcf_par /* BIN7 */);

                TqCmp_tqAltLossRaw = TqCmp_tqAltLossSTT;
            }
            else
            {
    			/* F05_02_01_ICCP */
                TQADPCMP_05_02_01_ICCP(ext_staltclascf_par,
                                   eng_nckfil_par /* BIN2 */);
				/* F05_02_02_GAP (reset) */
				TqCmp_tqAltLossGap = 0;
				TqCmp_bDftIdfAlt = DDS_FALSE;
				/* F05_02_03_STT_HY (reset) */
				TqCmp_tqAltLossSTT = 0;

                TqCmp_tqAltLossRaw = (SInt16)TqCmp_tqAltLossStd;
            }
        }
    }

		 /* Update 1/Z */
		if (((UInt32)DDS_FALSE != (UInt32)tqadpcmp_05_01_01_or_output_prev) ||
			((UInt32)DDS_FALSE != (UInt32)TqCmp_bDftIdfAlt))
		{
			tqadpcmp_05_01_01_or_output_prev = DDS_TRUE;
		}
		else
		{
			tqadpcmp_05_01_01_or_output_prev = DDS_FALSE;
		}

}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_01_ICCP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_01_ICCP(
                                           UInt8 ext_staltclascf_par,
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.15.0 */
    UInt32 tqadpcmp_05_02_01_index;

    tqadpcmp_05_02_01_index = (UInt32)TqCmp_idxAltStdClas_T[(UInt32)ext_staltclascf_par];


    if (0 == tqadpcmp_05_02_01_index)
    {
        /* [0; 500] BIN4 */
        TqCmp_tqAltLossStd = DDS_M_MAP3D_U16(&TQCMP_TQALTSTDLOSSCLAS1_M_APM, (UInt16)((UInt32)eng_nckfil_par/BIN2), (UInt16)Ext_rAltStdCycOpSel);
    }
    else if (1 == tqadpcmp_05_02_01_index)
    {
        /* [0; 500] BIN4 */
        TqCmp_tqAltLossStd = DDS_M_MAP3D_U16(&TQCMP_TQALTSTDLOSSCLAS2_M_APM, (UInt16)((UInt32)eng_nckfil_par/BIN2), (UInt16)Ext_rAltStdCycOpSel);
    }
    else /* 2 */
    {
        /* [0; 500] BIN4 */
        TqCmp_tqAltLossStd = DDS_M_MAP3D_U16(&TQCMP_TQALTSTDLOSSCLAS3_M_APM, (UInt16)((UInt32)eng_nckfil_par/BIN2), (UInt16)Ext_rAltStdCycOpSel);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_02_GAP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_02_GAP(
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.16.0 */
    UInt8 tqadpcmp_05_02_02_bidxclas1vld;
    UInt8 tqadpcmp_05_02_02_bidxclas2vld;
    UInt8 tqadpcmp_05_02_02_bidxclas3vld;
    UInt8 tqadpcmp_05_02_02_bidxprov1vld;
    UInt8 tqadpcmp_05_02_02_bidxprov2vld;
    UInt8 tqadpcmp_05_02_02_bidxprov3vld;

    UInt32 tqadpcmp_05_02_02_out_p1;
    UInt32 tqadpcmp_05_02_02_out_p2;
    UInt32 tqadpcmp_05_02_02_out_p3;

    /* calculating TqCmp_bIdxClas1Vld,TqCmp_bIdxClas2Vld ,TqCmp_bIdxClas3Vld . */
    if((UInt32)AltCtl_idxAltClasSel == (UInt32)TqCmp_idxAltGapClas1_C)
    {
        tqadpcmp_05_02_02_bidxclas1vld = DDS_TRUE;
    }
    else
    {
        tqadpcmp_05_02_02_bidxclas1vld = DDS_FALSE;
    }
    if((UInt32)AltCtl_idxAltClasSel == (UInt32)TqCmp_idxAltGapClas2_C)
    {
        tqadpcmp_05_02_02_bidxclas2vld = DDS_TRUE;
    }
    else
    {
        tqadpcmp_05_02_02_bidxclas2vld = DDS_FALSE;
    }
    if((UInt32)AltCtl_idxAltClasSel == (UInt32)TqCmp_idxAltGapClas3_C)
    {
        tqadpcmp_05_02_02_bidxclas3vld = DDS_TRUE;
    }
    else
    {
        tqadpcmp_05_02_02_bidxclas3vld = DDS_FALSE;
    }

    /* calculating TqCmp_bIdxProv1Vld,TqCmp_bIdxProv2Vld ,TqCmp_bIdxProv3Vld . */
    if((UInt32)AltCtl_idxAltMdlSel == (UInt32)TqCmp_idxAltGapMdl1_C)
    {
        tqadpcmp_05_02_02_bidxprov1vld = DDS_TRUE;
        tqadpcmp_05_02_02_out_p1 = (UInt32)TQADPCMP_05_02_02_Gap_P1(eng_nckfil_par, /* BIN2 */
                                                                    tqadpcmp_05_02_02_bidxclas1vld,
                                                                    tqadpcmp_05_02_02_bidxclas2vld,
                                                                    tqadpcmp_05_02_02_bidxclas3vld);
    }
    else
    {
        tqadpcmp_05_02_02_bidxprov1vld = DDS_FALSE;
        tqadpcmp_05_02_02_out_p1 = 0;
    }
    if((UInt32)AltCtl_idxAltMdlSel == (UInt32)TqCmp_idxAltGapMdl2_C)
    {
        tqadpcmp_05_02_02_bidxprov2vld = DDS_TRUE;
        tqadpcmp_05_02_02_out_p2 = (UInt32)TQADPCMP_05_02_02_Gap_P2(eng_nckfil_par, /* BIN2 */
                                                                    tqadpcmp_05_02_02_bidxclas1vld,
                                                                    tqadpcmp_05_02_02_bidxclas2vld,
                                                                    tqadpcmp_05_02_02_bidxclas3vld);
    }
    else
    {
        tqadpcmp_05_02_02_bidxprov2vld = DDS_FALSE;
        tqadpcmp_05_02_02_out_p2 = 0;
    }
    if((UInt32)AltCtl_idxAltMdlSel == (UInt32)TqCmp_idxAltGapMdl3_C)
    {
        tqadpcmp_05_02_02_bidxprov3vld = DDS_TRUE;
        tqadpcmp_05_02_02_out_p3 = (UInt32)TQADPCMP_05_02_02_Gap_P3(eng_nckfil_par, /* BIN2 */
                                                                    tqadpcmp_05_02_02_bidxclas1vld,
                                                                    tqadpcmp_05_02_02_bidxclas2vld,
                                                                    tqadpcmp_05_02_02_bidxclas3vld);
    }
    else
    {
        tqadpcmp_05_02_02_bidxprov3vld = DDS_FALSE;
        tqadpcmp_05_02_02_out_p3 = 0;
    }

    /* TqCmp_bDftIdfAlt */
    /*--------------------*/
    if ((((UInt32)DDS_FALSE == (UInt32)tqadpcmp_05_02_02_bidxprov1vld) &&
         ((UInt32)DDS_FALSE == (UInt32)tqadpcmp_05_02_02_bidxprov2vld) &&
         ((UInt32)DDS_FALSE == (UInt32)tqadpcmp_05_02_02_bidxprov3vld)) ||
        (((UInt32)DDS_FALSE == (UInt32)tqadpcmp_05_02_02_bidxclas1vld) &&
         ((UInt32)DDS_FALSE == (UInt32)tqadpcmp_05_02_02_bidxclas2vld) &&
         ((UInt32)DDS_FALSE == (UInt32)tqadpcmp_05_02_02_bidxclas3vld)))
    {
        TqCmp_bDftIdfAlt = DDS_TRUE;
    }
    else
    {
        TqCmp_bDftIdfAlt = DDS_FALSE;
    }

    TqCmp_tqAltLossGap = (UInt16)DDS_M_MIN(tqadpcmp_05_02_02_out_p1+tqadpcmp_05_02_02_out_p2+tqadpcmp_05_02_02_out_p3,500*BIN4);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_02_Gap_P1
* Description :
*
*******************************************************************************/
STATIC FUNC(UInt16, AUTOMATIC) TQADPCMP_05_02_02_Gap_P1(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqcmp_bidxclas1vld_par,
                                           UInt8 tqcmp_bidxclas2vld_par,
                                           UInt8 tqcmp_bidxclas3vld_par)
{
    UInt32 tqadpcmp_elem1;
    UInt32 tqadpcmp_elem2;
    UInt32 tqadpcmp_elem3;

    if((UInt32)tqcmp_bidxclas1vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem1 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS1MDL1_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem1 = 0;
    }
    if((UInt32)tqcmp_bidxclas2vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem2 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS2MDL1_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem2 = 0;
    }
    if((UInt32)tqcmp_bidxclas3vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem3 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS3MDL1_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem3 = 0;
    }

    return (UInt16)(tqadpcmp_elem1+tqadpcmp_elem2+tqadpcmp_elem3);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_02_Gap_P2
* Description :
*
*******************************************************************************/
STATIC FUNC(UInt16, AUTOMATIC) TQADPCMP_05_02_02_Gap_P2(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqcmp_bidxclas1vld_par,
                                           UInt8 tqcmp_bidxclas2vld_par,
                                           UInt8 tqcmp_bidxclas3vld_par)
{
    UInt32 tqadpcmp_elem1;
    UInt32 tqadpcmp_elem2;
    UInt32 tqadpcmp_elem3;

    if((UInt32)tqcmp_bidxclas1vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem1 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS1MDL2_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem1 = 0;
    }
    if((UInt32)tqcmp_bidxclas2vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem2 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS2MDL2_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem2 = 0;
    }
    if((UInt32)tqcmp_bidxclas3vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem3 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS3MDL2_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem3 = 0;
    }

    return (UInt16)(tqadpcmp_elem1+tqadpcmp_elem2+tqadpcmp_elem3);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_02_Gap_P3
* Description :
*
*******************************************************************************/
STATIC FUNC(UInt16, AUTOMATIC) TQADPCMP_05_02_02_Gap_P3(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqcmp_bidxclas1vld_par,
                                           UInt8 tqcmp_bidxclas2vld_par,
                                           UInt8 tqcmp_bidxclas3vld_par)
{
    UInt32 tqadpcmp_elem1;
    UInt32 tqadpcmp_elem2;
    UInt32 tqadpcmp_elem3;

    if((UInt32)tqcmp_bidxclas1vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem1 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS1MDL3_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem1 = 0;
    }
    if((UInt32)tqcmp_bidxclas2vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem2 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS2MDL3_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem2 = 0;
    }
    if((UInt32)tqcmp_bidxclas3vld_par!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_elem3 = DDS_M_MAP3D_U16(&TQCMP_TQALTGAPLOSSCLAS3MDL3_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),AltCtl_iAltSel);
    }
    else
    {
        tqadpcmp_elem3 = 0;
    }

    return (UInt16)(tqadpcmp_elem1+tqadpcmp_elem2+tqadpcmp_elem3);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_02_03_STT_HY
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_02_03_STT_HY(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt16 ext_facrattqaltcf_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.17.0 */
    SInt32 tqadpcmp_05_02_03_prod;
    SInt32 tqadpcmp_05_02_03_prod_limited;


    /* [-20000;20000]BIN11 =[-2000;2000]BIN4 * [0;10]BIN7 * [-1;1]BIN0 */
    tqadpcmp_05_02_03_prod = ((SInt32)TqCmp_tqAltSel * (SInt32)ext_facrattqaltcf_par) * (SInt32)TqCmp_facTqAltSign_C;


    tqadpcmp_05_02_03_prod_limited = DDS_M_LIMIT((tqadpcmp_05_02_03_prod / BIN7),
                                                 -2000*BIN4,
                                                 2000*BIN4);

    /* [-2000;2000]BIN4 */
    TqCmp_tqAltLossSTT = DDS_M_MAP3D_USS16(&TQCMP_TQALTITPND_M_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2),(SInt16)tqadpcmp_05_02_03_prod_limited);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_03_Filtrage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_03_Filtrage(
                                           UInt8 tqdem_btqgrdlim_par,
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1806.FR.18.0 */
    if((UInt32)tqdem_btqgrdlim_par != (UInt32)DDS_FALSE)
    {
        TqCmp_idxFacFilTqAltLoss_MP = 3;
        TqCmp_facFilTqAltLoss_MP = TqDem_facFilTqAltLoss_C;
    }
    else if((UInt32)TqCmp_bDftAltFilAcv != (UInt32)DDS_FALSE)
    {
        TqCmp_idxFacFilTqAltLoss_MP = 2;
        TqCmp_facFilTqAltLoss_MP = TqCmp_facFilDftTqAltLoss_C;
    }
    else if((UInt32)TqCmp_bStrtAltFilAcv != (UInt32)DDS_FALSE)
    {
        TqCmp_idxFacFilTqAltLoss_MP = 1;
        TqCmp_facFilTqAltLoss_MP = TqCmp_facFilStrtTqAltLoss_C;
    }
    else
    {
        TqCmp_idxFacFilTqAltLoss_MP = 0;
        if((SInt32)TqCmp_tqAltLossRaw>(SInt32)TqCmp_tqAltLossItUnlim)
        {
            TqCmp_facFilTqAltLoss_MP = DDS_M_MAP2D_U16(&TQCMP_FACFILTQALTLOSSUP_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
        }
        else
        {
            TqCmp_facFilTqAltLoss_MP = DDS_M_MAP2D_U16(&TQCMP_FACFILTQALTLOSSDOWN_T_APM,(UInt16)((UInt32)eng_nckfil_par/BIN2));
        }
    }

    if((UInt32)tqadpcmp_05_03_filter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_05_03_filter_init = DDS_TRUE;
        TqCmp_tqAltLossItUnlim = DDS_M_FILTER_LP1_S16_INIT(&tqadpcmp_05_03_filtre, TqCmp_tqAltLossRaw);
    }
    else
    {
        TqCmp_tqAltLossItUnlim = DDS_M_FILTER_LP1_S16(&tqadpcmp_05_03_filtre, TqCmp_tqAltLossRaw, TqCmp_facFilTqAltLoss_MP, BIN10);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Alternator_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Alternator_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bDgo_tqAltRv_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpAltOn_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAltLoss_swc_out /* BIN4 */)
{
    *TqCmp_bDgo_tqAltRv_swc_out = DDS_FALSE;
    *TqCmp_tqAltLoss_swc_out = 0;
    *TqAdp_bFrzAdpAltOn_swc_out = DDS_FALSE;

    tqadpcmp_02_filter_init = DDS_FALSE;
    tqadpcmp_05_03_filter_init = DDS_FALSE;
    tqcmp_tqaltloss_prev = 0;
    tqadpcmp_05_01_01_or_output_prev = DDS_FALSE;
    tqadpcmp_05_01_01_tmrrst_output = DDS_FALSE;
    tqadpcmp_05_01_02_02_filter_init = DDS_FALSE;
    tqadpcmp_05_01_01_tmrrst_value = 0;
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_05_turn_off_delay1);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_05_turn_off_delay2);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_05_turn_off_delay3);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_05_01_03_turn_off_delay);
    tqadpcmp_05_01_03_counter = 0;
    TqCmp_tqAltLossStd = 0;
    TqCmp_tqAltLossGap = 0;
    TqCmp_bDftIdfAlt = DDS_FALSE;
    TqCmp_tqAltLossSTT = 0;
    TqCmp_tqAltLossItUnlim = 0;


    TqAdp_bFrzAdpAlt_MP     = DDS_FALSE;
    TqCmp_bTqAltLossMax     = DDS_FALSE;
    TqCmp_bTqAltLossMin     = DDS_FALSE;
    TqCmp_bAltTypDft        = DDS_FALSE;
    TqCmp_bDftAltFilAcv     = DDS_FALSE;
    TqCmp_bDftAltTyp_MP     = DDS_FALSE;
    TqCmp_bTqAltLossOff     = DDS_FALSE;
    TqCmp_bStrtAltFilAcv    = DDS_FALSE;
    TqCmp_bDgo_tqAltRvIt    = DDS_FALSE;
    TqCmp_bEngStrtReqAlt    = DDS_FALSE;

    TqCmp_idxFacFilTqAltLoss_MP = (UInt8)(0 * BIN0);

    Ext_rAltStdCycOpSel     = (UInt8)(0 * BIN0);
    TqCmp_tqAltLossExt      = (SInt16)(0 * BIN4);
    TqCmp_tqAltLossTrvUnlim = (SInt16)(0 * BIN4);
    AltCtl_iAltSel          = (UInt16)(0 * BIN4);
    TqCmp_facFilTqAltLoss_MP = (UInt16)(1 * BIN10);
    TqCmp_tqAltLossRaw      = (SInt16)(0 * BIN4);
    TqCmp_tqAltSel          = (SInt16)(0 * BIN4);

    tqadpcmp_05_01_01_is_init = DDS_FALSE;


}


#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

