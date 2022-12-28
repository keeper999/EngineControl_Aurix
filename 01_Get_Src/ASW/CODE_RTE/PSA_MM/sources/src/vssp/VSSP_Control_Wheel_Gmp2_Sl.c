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
* Ref X:\integration_view_00PSASWC_D820D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Control_Wheel_Gmp2_Sl.c
* Version int :/main/L03_01/1 Date: 6/1/2012 11 h 10 m User:esnault 
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L03_010_IMPL2
*    comments :Correct fail code
* Version dev :\main\branch_moisan_module_dev\1 Date: 3/1/2012 17 h 41 m User:moisan 
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L03_010_IMPL2
*    comments :Correct fail code
* Version dev :\main\branch_demezil_vssp_view\3 Date: 21/12/2011 12 h 18 m User:halouane
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L03_010_IMPL1
*    comments :For VSSp_12_0_e6, correction dor UT
* Version dev :\main\branch_demezil_vssp_view\2 Date: 28/11/2011 10 h 57 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L03_010_IMPL1
*    comments :for VSSp 12.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 25/11/2011 16 h 0 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L03_010_IMPL1
*    comments :for VSSp 12.0
* Version int :/main/L02_01/1 Date: 7/9/2011 16 h 40 m User:esnault
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L02_010_IMPL2
*    comments :for VSSp 11.0 : correction following TU report
* Version dev :\main\branch_demezil_vssp_view\4 Date: 31/8/2011 9 h 47 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L02_010_IMPL2
*    comments :for VSSp 11.0 : correction following TU report
* Version dev :\main\branch_demezil_vssp_view\3 Date: 4/8/2011 17 h 26 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 4/8/2011 17 h 15 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 26/7/2011 14 h 54 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version int :/main/L01_01/3 Date: 30/5/2011 9 h 9 m User:esnault
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_011_IMPL1
*    comments :TU correction for VSSp 10.1
* Version dev :\main\branch_lemort_eom_dev\3 Date: 24/5/2011 12 h 14 m User:lemort
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_011_IMPL1
*    comments :TU correction for VSSp 10.1
* Version dev :\main\branch_lemort_eom_dev\2 Date: 20/5/2011 10 h 19 m User:lemort
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_011_IMPL1
*    comments :BARYCENTRE -> BARYCENTRE_V2
* Version dev :\main\branch_lemort_eom_dev\1 Date: 12/5/2011 15 h 46 m User:lemort
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_011_IMPL1
*    comments :correction ALTIS 1601871 / FDS A0201704
*    comments :correction ALTIS 1602072 / FDS A0201701
*    comments :correction ALTIS 1601874 / FDS A0201691
* Version int :/main/L01_01/2 Date: 16/3/2011 11 h 48 m User:esnault
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL2
*    comments :For VSSp 10.0 , correction after TU
* Version dev :\main\branch_morisseau_vssp_euro6\11 Date: 14/3/2011 14 h 39 m User:veillard
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL2
*    comments :For VSSp 10.0 , correction after TU
* Version dev :\main\branch_morisseau_vssp_euro6\10 Date: 7/3/2011 14 h 23 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL2
*    comments :VSSp 10.0 : . VSCtl_stTqWhlPTCutOffReqPrev rename with VSCtl_stTqWhlPTCutOffReqDly
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 53 m User:meme
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\9 Date: 22/2/2011 17 h 51 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\8 Date: 22/2/2011 16 h 56 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\7 Date: 14/2/2011 14 h 21 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\6 Date: 14/2/2011 9 h 53 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 9/2/2011 17 h 25 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 19/1/2011 8 h 39 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :correct map name
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 16 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp2_Sl_L01_010_IMPL1
*    comments :add model
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 11/1/2011 16 h 41 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSSp
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSSp.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define VSSP_0                  (0)
#define VSSP_2000_BIN4          (2000 * BIN4)
#define VSSP_4000_BIN1          (4000 * BIN1)
#define VSSP_11000_BIN1         (11000 * BIN1)
#define VSSP_16000_BIN1         (16000 * BIN1)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_rAnt_tqWhlPTMax; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rAnt_tqWhlPTMin; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_tiFiltqCkEfcMaxReq; /* BIN0 */
extern VAR(UInt16, AUTOMATIC) VSCtl_tiFilStCtlTqEfcTarMin;
extern VAR(UInt16, AUTOMATIC) VSCtl_tiFilStCtlTqEfcTarMax;
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqCkEfcMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqCkEfcMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAntTqWhlPTMaxReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAntTqWhlPTMinReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqCkEfcMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqCkEfcMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTCutOffReqPrev; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqEfcTarMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqEfcTarMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqEfcTarMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqEfcTarMax;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"



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

/* 16-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReqDly; /* BIN4 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilDw_tiFilMinTqCkMax_C = (CONST(UInt16, AUTOMATIC))(0.094 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilDw_tiFilMinTqCkMin_C = (CONST(UInt16, AUTOMATIC))(0.094 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilStabDyn_tqCkMax_C = (CONST(UInt16, AUTOMATIC))(0.078 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilStabDyn_tqCkMin_C = (CONST(UInt16, AUTOMATIC))(0.078 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilTranDyn_tqCkMax_C = (CONST(UInt16, AUTOMATIC))(0.200 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilTranDyn_tqCkMin_C = (CONST(UInt16, AUTOMATIC))(0.200 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilUp_tiFilMinTqCkMax_C = (CONST(UInt16, AUTOMATIC))(0.047 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilUp_tiFilMinTqCkMin_C = (CONST(UInt16, AUTOMATIC))(0.047 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPEngMax_C = (CONST(UInt16, AUTOMATIC))(0.200 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPEngMin_C = (CONST(UInt16, AUTOMATIC))(0.200 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_tqEfcTarMin_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqErrFTran_tqCkMaxVSCtl_C = (CONST(UInt16, AUTOMATIC))(10 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqErrSTran_tqCkMaxVSCtl_C = (CONST(UInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqSIPNegTran_tqEfcTarMin_C = (CONST(SInt16, AUTOMATIC))(0.1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqSIPPosTran_tqEfcTarMin_C = (CONST(SInt16, AUTOMATIC))(0.1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqSIPNegTran_tqEfcTarMax_C = (CONST(SInt16, AUTOMATIC))(0.1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqSIPPosTran_tqEfcTarMax_C = (CONST(SInt16, AUTOMATIC))(0.1 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_tqEfcTarMax_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvTqCkEfcMaxReqSat_C = DDS_TRUE;
#define VSSP_STOP_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSSP_START_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPEngSatMax_T
[VSSP_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPEngSatMin_T
[VSSP_8_SIZE] = {
(UInt16)(100 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilMinTqCkMax_tqDif_T
[VSSP_8_SIZE] = {
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkDif_tiFilMinTqMax_A[VSSP_8_SIZE] = {
(SInt16)(-400 * BIN4), (SInt16)(-350 * BIN4), (SInt16)(-300 * BIN4),
(SInt16)(-250 * BIN4), (SInt16)(-200 * BIN4), (SInt16)(-4 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(2000 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcEr_rAccPEngSatMn_A[VSSP_8_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(40 * BIN4), (SInt16)(60 * BIN4),
(SInt16)(80 * BIN4), (SInt16)(100 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcEr_rAccPEngSatMx_A[VSSP_8_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(5 * BIN4), (SInt16)(10 * BIN4),
(SInt16)(20 * BIN4), (SInt16)(40 * BIN4), (SInt16)(60 * BIN4),
(SInt16)(80 * BIN4), (SInt16)(100 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilMinTqCkMin_tqDif_T
[VSSP_8_SIZE] = {
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkDif_tiFilMinTqMin_A[VSSP_8_SIZE] = {
(SInt16)(-2000 * BIN4), (SInt16)(0 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(700 * BIN4), (SInt16)(800 * BIN4), (SInt16)(900 * BIN4),
(SInt16)(1000 * BIN4), (SInt16)(2000 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPEngMin_M
[VSSP_16_SIZE][VSSP_16_SIZE] = {
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinR_rAccPEngMnX_A[VSSP_16_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(70 * BIN4),
(SInt16)(90 * BIN4), (SInt16)(110 * BIN4),
(SInt16)(130 * BIN4), (SInt16)(150 * BIN4), (SInt16)(170 * BIN4),
(SInt16)(190 * BIN4), (SInt16)(210 * BIN4), (SInt16)(230 * BIN4),
(SInt16)(250 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEng_rAccPEngMin_Y_A[VSSP_16_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(750 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1200 * BIN0), (UInt16)(1600 * BIN0), (UInt16)(1800 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(2200 * BIN0), (UInt16)(2400 * BIN0),
(UInt16)(2600 * BIN0), (UInt16)(2800 * BIN0), (UInt16)(3200 * BIN0),
(UInt16)(3600 * BIN0), (UInt16)(4000 * BIN0), (UInt16)(4400 * BIN0),
(UInt16)(4800 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPEngMax_M
[VSSP_16_SIZE][VSSP_16_SIZE] = {
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(10 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(65 * BIN7),
(UInt16)(70 * BIN7), (UInt16)(75 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(85 * BIN7), (UInt16)(90 * BIN7), (UInt16)(95 * BIN7),
(UInt16)(100 * BIN7) }
};


STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxR_rAccPEngMxX_A[VSSP_16_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-30 * BIN4), (SInt16)(-10 * BIN4),
(SInt16)(10 * BIN4), (SInt16)(30 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(70 * BIN4),
(SInt16)(90 * BIN4), (SInt16)(110 * BIN4),
(SInt16)(130 * BIN4), (SInt16)(150 * BIN4), (SInt16)(170 * BIN4),
(SInt16)(190 * BIN4), (SInt16)(210 * BIN4), (SInt16)(230 * BIN4),
(SInt16)(250 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEng_rAccPEngMax_Y_A[VSSP_16_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(750 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1200 * BIN0), (UInt16)(1600 * BIN0), (UInt16)(1800 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(2200 * BIN0), (UInt16)(2400 * BIN0),
(UInt16)(2600 * BIN0), (UInt16)(2800 * BIN0), (UInt16)(3200 * BIN0),
(UInt16)(3600 * BIN0), (UInt16)(4000 * BIN0), (UInt16)(4400 * BIN0),
(UInt16)(4800 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nPrimShaftTar_tqEfcTar_A[VSSP_8_SIZE] = {
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2000 * BIN0),
(UInt16)(2700 * BIN0), (UInt16)(3000 * BIN0), (UInt16)(3500 * BIN0),
(UInt16)(4000 * BIN0), (UInt16)(5000 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqEfcTarMax_T
[VSSP_8_SIZE] = {
(SInt16)(117.625 * BIN4), (SInt16)(140 * BIN4), (SInt16)(160 * BIN4),
(SInt16)(180 * BIN4), (SInt16)(200 * BIN4), (SInt16)(230 * BIN4),
(SInt16)(250 * BIN4), (SInt16)(250 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqEfcTarMin_T
[VSSP_8_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4),
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4),
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4)
};

#define VSSP_STOP_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tqefctarmax_t_sav[VSSP_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tqefctarmin_t_sav[VSSP_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_raccpengsatmax_t_sav[VSSP_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_raccpengsatmin_t_sav[VSSP_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tifilmintqckmax_tqdif_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tifilmintqckmin_tqdif_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccpengmax_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccpengmin_m_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71312_filter_assym_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71312_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71314_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f713231_filter_assym_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71317_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f713231_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71325_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71328_filter_str;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"

/* 16-bits variable definition */
#define VSSP_START_SEC_VAR_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vssp_f713232_switch_out_dly; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqefctarmin_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqefctarmax_prev;
#define VSSP_STOP_SEC_VAR_16BIT
#include "VSSp_MemMap.h"

/* 8-bits variable definition */
#define VSSP_START_SEC_VAR_8BIT
#include "VSSp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vssp_f713232_switch_out_dly_init;
STATIC VAR(UInt8, AUTOMATIC) vssp_stctl_tqckefcmax_loc;
#define VSSP_STOP_SEC_VAR_8BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfclMax; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMaxRaw1; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMaxRaw2; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMaxRaw3; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMin; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMinRaw1; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMinRaw2; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqCkEfcMinRaw3; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReqCll; /* BIN4 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReqRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinReqRaw1; /* BIN4 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinReqRaw2; /* BIN4 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqEfcTarMinRaw; /* BIN4 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqSIPTranMinSecu; /* BIN4 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqEfcTarMaxRaw; /* BIN4 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqSIPTranMaxSecu; /* BIN4 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* Variable To Keep On Hot Reset
*******************************************************************************/

#define VSSP_START_SEC_VAR_POWER_ON_INIT_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReqDly_NV;
#define VSSP_STOP_SEC_VAR_POWER_ON_INIT_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSSP_START_SEC_CONST_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RACCPENGSATMAX_T_APM[VSSP_2_SIZE] = {
{
&vsctl_raccpengsatmax_t_sav[0],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcEr_rAccPEngSatMx_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPEngSatMax_T[0]
},
{
&vsctl_raccpengsatmax_t_sav[1],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcEr_rAccPEngSatMx_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPEngSatMax_T[0]
}
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RACCPENGSATMIN_T_APM[VSSP_2_SIZE] = {
{
&vsctl_raccpengsatmin_t_sav[0],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcEr_rAccPEngSatMn_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPEngSatMin_T[0]
},
{
&vsctl_raccpengsatmin_t_sav[1],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcEr_rAccPEngSatMn_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPEngSatMin_T[0]
}
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_TIFILMINTQCKMAX_TQDIF_T_APM = {
&vsctl_tifilmintqckmax_tqdif_t_sav,
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkDif_tiFilMinTqMax_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiFilMinTqCkMax_tqDif_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_TIFILMINTQCKMIN_TQDIF_T_APM = {
&vsctl_tifilmintqckmin_tqdif_t_sav,
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkDif_tiFilMinTqMin_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiFilMinTqCkMin_tqDif_T[0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPENGMIN_M_APM = {
&vsctl_raccpengmin_m_sav,
VSSP_16_SIZE,
VSSP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMinR_rAccPEngMnX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_rAccPEngMin_Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPEngMin_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPENGMAX_M_APM = {
&vsctl_raccpengmax_m_sav,
VSSP_16_SIZE,
VSSP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMaxR_rAccPEngMxX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEng_rAccPEngMax_Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPEngMax_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_TQEFCTARMAX_T_APM[VSSP_2_SIZE] = {
{
&vsctl_tqefctarmax_t_sav[0],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nPrimShaftTar_tqEfcTar_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqEfcTarMax_T[0]
},
{
&vsctl_tqefctarmax_t_sav[1],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nPrimShaftTar_tqEfcTar_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqEfcTarMax_T[0]
}
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_TQEFCTARMIN_T_APM[VSSP_2_SIZE] = {
{
&vsctl_tqefctarmin_t_sav[0],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nPrimShaftTar_tqEfcTar_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqEfcTarMin_T[0]
},
{
&vsctl_tqefctarmin_t_sav[1],
VSSP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nPrimShaftTar_tqEfcTar_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqEfcTarMin_T[0]
}
};

#define VSSP_STOP_SEC_CONST_UNSPECIFIED
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */



STATIC FUNC(void, AUTOMATIC) VSSP_F713231_Determiner_Consigne_Couple_Moteur_Max_Boucle_Fermee(
                                                 UInt16 vsctl_rconvtra_par, /* BIN7 */
                                                 SInt16 vsctl_tqckefcmax_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcmaxnotctla_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcmin_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcminnotctla_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcprecovsctlreq_par, /* BIN4 */
                                                 SInt16 vsctl_tqwhlmaxreq_par, /* BIN1 */
                                                 SInt16 vsctl_tqlosstra_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) VSSP_F713232_Determiner_Consigne_Couple_Moteur_Max_Boucle_Ouverte(
                                                 SInt16 vsctl_tqckefcprecovscminreq_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcprecovsctlreq_par, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqckefcmaxreq_ptr /* BIN4 */);

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
*
* Function Name : VSSP_F71312_Determiner_Consigne_Couple_Moteur_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71312_Determiner_Consigne_Couple_Moteur_Min(
                                                 UInt16 VSCtl_rConvTra_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqLossTra_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqWhlMinReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinReq_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.54.1 */
    UInt32 vssp_bary_filter_out;
    UInt32 vssp_filter_assy_out;
    SInt32 vssp_filter_out;
    UInt32 vssp_max_out;
    SInt32 vssp_svalue;
    SInt16 vssp_saturation_out;
    UInt16 vssp_map_out;

    /* filtre_barycentrique */
    /* BIN10 [0;1] */
    vssp_bary_filter_out = (UInt32)DDS_M_BARY_FILTER_S32_V2((SInt32)VSCtl_tiFilTranDyn_tqCkMin_C,  /* [0;1]BIN10 */
                                                         (SInt32)VSCtl_tiFilStabDyn_tqCkMin_C,  /* [0;1]BIN10 */
                                                         VSCtl_rAnt_tqWhlPTMin,                 /* [0;100]BIN7 */
                                                         (UInt16)(100 * BIN7));

    /* saturation */
    /* BIN4 = BIN1 * BIN10 / BIN7 */
/* <PRQA_COMMENT><2834> Range of VSCtl_rConvTra is 0.0078125 to 20. </2834></PRQA_COMMENT> */
    vssp_svalue = ((SInt32)VSCtl_tqWhlMinReq_swc_in * BIN10) / (SInt32)VSCtl_rConvTra_swc_in;
    vssp_svalue = vssp_svalue - (SInt32)VSCtl_tqLossTra_swc_in;
    /* BIN4:[-2000;2000] */
    vssp_saturation_out = (SInt16)DDS_M_SATURATION_V2(vssp_svalue,
                                                      (SInt32)VSCtl_tqCkEfcMin_swc_in,
                                                      (SInt32)VSCtl_tqCkEfcMax_swc_in);

    /* map VSCtl_tiFilMinTqCkMin_tqDif_T */
    /* BIN4:[-4000;4000] */
    vssp_svalue = (SInt32)vssp_saturation_out - (SInt32)VSCtl_tqCkEfcPreCoVSCtlReq_swc_in;
    /* BIN4:[-2000;2000] */
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_2000_BIN4,VSSP_2000_BIN4);
    /* BIN10:[0;1] */
    vssp_map_out = DDS_M_MAP2D_SU16(&VSCTL_TIFILMINTQCKMIN_TQDIF_T_APM,(SInt16)vssp_svalue);

    /* filtre_1er_ordre assymetrique */
    /* filtre_1er_ordre */
    if((UInt32)VSCtl_bAntTqWhlPTMinReq != (UInt32)DDS_FALSE)
    {
        vssp_filter_assy_out = (UInt32)DDS_M_FILTER_LP1_ASSYM_S16(
                                                &vssp_f71312_filter_assym_str,
                                                (SInt16)vssp_map_out,               /* [0;1]BIN10 */
                                                VSCtl_tiFilUp_tiFilMinTqCkMin_C,    /* [0;1]BIN10 */
                                                VSCtl_tiFilDw_tiFilMinTqCkMin_C,    /* [0;1]BIN10 */
                                                BIN10);

        /* BIN10:[0;1] */
        vssp_max_out = DDS_M_MAX(vssp_filter_assy_out, vssp_bary_filter_out);

        /* BIN4:[-2000;2000] */
        vssp_filter_out = (SInt32)DDS_M_FILTER_LP1_S16(&vssp_f71312_filter_str, vssp_saturation_out, (UInt16)vssp_max_out, BIN10);
    }
    else
    {
        vssp_filter_assy_out = (UInt32)DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f71312_filter_assym_str,(SInt16)vssp_map_out);

        /* BIN10:[0;1] */
        vssp_max_out = DDS_M_MAX(vssp_filter_assy_out,vssp_bary_filter_out);

        /* BIN4:[-2000;2000] */
        vssp_filter_out = (SInt32)DDS_M_FILTER_LP1_S16_INIT(&vssp_f71312_filter_str, vssp_saturation_out);
    }


    if((UInt32)VSCtl_stCtl_tqCkEfcMin == VSSP_VSCTL_STCTL_TQCKEFCMIN_ARRET)
    {
        *VSCtl_tqCkEfcMinReq_swc_out = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinReqRaw1 = (SInt16)(-2000 * BIN4);
        VSCtl_tqCkEfcMinReqRaw2 = (SInt16)(-2000 * BIN4);
        VSCtl_tiFil_tqCkEfcMin = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqCkEfcMinRaw1 = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqCkEfcMinRaw2 = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqCkEfcMinRaw3 = (UInt16)(1 * BIN10);
    }
    else
    {
        if((UInt32)VSCtl_stTqWhlPTCutOffReqPrev == VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_HAUT)
        {
            VSCtl_tqCkEfcMinReqRaw1 = (SInt16)DDS_M_MAX((SInt32)VSCtl_tqCkEfcMaxNotCtla_swc_in,vssp_filter_out);
        }
        else if((UInt32)VSCtl_stTqWhlPTCutOffReqPrev == VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_BAS)
        {
            VSCtl_tqCkEfcMinReqRaw1 = (SInt16)DDS_M_MIN((SInt32)VSCtl_tqCkEfcMinNotCtla_swc_in,vssp_filter_out);
        }
        else
        {
            VSCtl_tqCkEfcMinReqRaw1 = (SInt16)vssp_filter_out;
        }
        *VSCtl_tqCkEfcMinReq_swc_out = (SInt16)DDS_M_MAX((SInt32)VSCtl_tqCkEfcMinReqRaw1,(SInt32)VSCtl_tqCkEfcPreCoVSCMinReq_swc_in);
        VSCtl_tqCkEfcMinReqRaw2 = vssp_saturation_out;
        VSCtl_tiFil_tqCkEfcMin = (UInt16)vssp_max_out;
        VSCtl_tiFil_tqCkEfcMinRaw1 = (UInt16)vssp_filter_assy_out;
        VSCtl_tiFil_tqCkEfcMinRaw2 = (UInt16)vssp_bary_filter_out;
        VSCtl_tiFil_tqCkEfcMinRaw3 = vssp_map_out;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min(
                                                 UInt32 VSCtl_nEngFil_swc_in, /* BIN0 */
                                                 SInt16 VSCtl_tqCkEfcMinReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMin_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.56.0 */
    UInt32 vssp_table_max_out;
    UInt32 vssp_table_min_out;
    UInt32 vssp_map_out;
    UInt16 vssp_filter_out;
    SInt32 vssp_svalue;
    UInt32 vssp_uvalue;

    /* BIN4:[-2000;2000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqCkEfcMinReq_swc_in - (SInt32)VSCtl_tqCkEfcDrvMinReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_2000_BIN4,VSSP_2000_BIN4);
    /* BIN7:[0;100]% */
    vssp_table_max_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPENGSATMAX_T_APM[0],(SInt16)vssp_svalue);

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqCkEfcDrvMaxReq_swc_in - (SInt32)VSCtl_tqCkEfcMinReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_2000_BIN4,VSSP_2000_BIN4);
    /* BIN7:[0;100]% */
    vssp_table_min_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPENGSATMIN_T_APM[0],(SInt16)vssp_svalue);

    vssp_svalue = DDS_M_SATURATION_V2((SInt32)VSCtl_tqCkEfcMinReq_swc_in,
                                      (SInt32)VSCtl_tqCkEfcDrvMinReq_swc_in,
                                      (SInt32)VSCtl_tqCkEfcDrvMaxReq_swc_in);

    /* BIN7:[0;100]% */
    vssp_map_out = (UInt32)DDS_M_MAP3D_SUU16(&VSCTL_RACCPENGMIN_M_APM,(SInt16)vssp_svalue,(UInt16)VSCtl_nEngFil_swc_in);

    if((UInt32)VSCtl_bAcvFil_tqCkEfcMin != (UInt32)DDS_FALSE)
    {
        /* BIN7:[0;100]% */
        vssp_uvalue = DDS_M_SATURATION_V2(vssp_map_out,vssp_table_min_out,vssp_table_max_out);
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f71314_filter_str, (UInt16)vssp_uvalue, VSCtl_tiFil_rAccPEngMin_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f71314_filter_str, 0);
    }


    if((UInt32)VSCtl_stCtl_tqCkEfcMin == VSSP_VSCTL_STCTL_TQCKEFCMIN_CONTROLE)
    {
        *VSCtl_rAccPEngMin_swc_out = vssp_filter_out;
    }
    else
    {
        *VSCtl_rAccPEngMin_swc_out = (UInt16)(0 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : F71317_Determiner_Consigne_Couple_Moteur_Cible_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71317_Determiner_Consigne_Couple_Moteur_Cible_Min(UInt16 CoPt_nPrimShaftTar_swc_in,   /* BIN0 */
                                                                UInt32 Ext_nFrntWhl_swc_in,         /* BIN7 */
                                                                SInt16 VSCtl_tqCkEfcMinReq_swc_in,     /* BIN4 */
                                                                SInt16 VSCtl_tqWhlMinReq_swc_in,    /* BIN1 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMin_swc_out)     /* BIN4 */
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.139.0 */
    SInt32 vsctl_tqefctarmax_t;
    SInt32 vsctl_tqefctarmin_t;
    SInt32 filter_input;
    SInt16 filter_output;
    UInt32 temp_u32;
    SInt32 temp_s32;
    SInt32 out_securedivi2;
    UInt16 vsctl_tifilstctltqefctarmin_cpy;

    vsctl_tifilstctltqefctarmin_cpy = VSCtl_tiFilStCtlTqEfcTarMin;

/* --------------------------- calculate filter input --------------------------------------------- */
    vsctl_tqefctarmax_t = (SInt32)DDS_M_MAP2D_US16(&VSCTL_TQEFCTARMAX_T_APM[0],
                                                    CoPt_nPrimShaftTar_swc_in);

    vsctl_tqefctarmin_t = (SInt32)DDS_M_MAP2D_US16(&VSCTL_TQEFCTARMIN_T_APM[0],
                                                    CoPt_nPrimShaftTar_swc_in);

    if((SInt32)VSCtl_tqWhlMinReq_swc_in ==0)
    {
        filter_input = 0;
    }
    else
    {
        if((UInt32)CoPt_nPrimShaftTar_swc_in == 0)
        {
            temp_u32 = (UInt32)(0.1 * BIN12);
        }
        else if(Ext_nFrntWhl_swc_in == 0)
        {
            temp_u32 = (UInt32)(20 * BIN12);
        }
        else
        {
            /* [0.00005;64]BIN12 = ([1/2;8000]BIN0 * BIN19) / [1/128;10000]BIN7 */
            temp_u32 = ((UInt32)CoPt_nPrimShaftTar_swc_in * BIN19) / Ext_nFrntWhl_swc_in;
            temp_u32 = DDS_M_LIMIT(temp_u32,
                                    (UInt32)(0.1 * BIN12),
                                    (UInt32)(20 * BIN12));
        }
        /* [-160000;160000]BIN4 = ([-16000;16000]BIN1 * BIN15) / [0.1;10000]BIN12 */
        /* <PRQA_COMMENT><2834> Range of temp_u32 is 0.00005 to 64 </2834></PRQA_COMMENT> */
        filter_input = ((SInt32)VSCtl_tqWhlMinReq_swc_in * BIN15) / (SInt32)temp_u32;
    }
    filter_input = DDS_M_SATURATION_V2(filter_input,
                                        vsctl_tqefctarmin_t,
                                        vsctl_tqefctarmax_t);
/* --------------------------- calculate filter output --------------------------------------------- */
    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_tqEfcTarMin)
    {
        filter_output = DDS_M_FILTER_LP1_S16_INIT(&vssp_f71317_filter_str,
                                                    (SInt16)filter_input);
    }
    else
    {
        filter_output = DDS_M_FILTER_LP1_S16(&vssp_f71317_filter_str,
                                                    (SInt16)filter_input,
                                                    VSCtl_tiFil_tqEfcTarMin_C,
                                                    BIN10);
    }
/* --------------------------- calculate out_securedivi2 --------------------------------------------- */
    if((SInt32)VSCtl_tqCkEfcMinReq_swc_in != (SInt32)vsctl_tqefctarmin_prev)
    {
        if((UInt32)vsctl_tifilstctltqefctarmin_cpy == 0)
        {
            if((SInt32)VSCtl_tqCkEfcMinReq_swc_in > (SInt32)vsctl_tqefctarmin_prev)
            {
                out_securedivi2 = VSSP_2000_BIN4;
            }
            else
            {
                out_securedivi2 = -VSSP_2000_BIN4;
            }
        }
        else
        {
            /* [-4000;4000]BIN4 = ([-2000;2000]BIN4 - [-2000;2000]BIN4) / [0;65535]BIN0 */
            out_securedivi2 = ((SInt32)VSCtl_tqCkEfcMinReq_swc_in - (SInt32)vsctl_tqefctarmin_prev) / (SInt32)vsctl_tifilstctltqefctarmin_cpy;
            out_securedivi2 = DDS_M_LIMIT(out_securedivi2,
                                            -VSSP_2000_BIN4,
                                            VSSP_2000_BIN4);
        }
    }
    else
    {
        out_securedivi2 = 0;
    }
/* --------------------------- calculate outputs --------------------------------------------- */
    if(VSCTL_STCTL_TQEFCTARMIN_FIN_SIP_LOW == (UInt32)VSCtl_stCtl_tqEfcTarMin)
    {
        /* [-2000;2000]BIN4 */
        temp_s32 = DDS_M_MIN(out_securedivi2,(SInt32)VSCtl_tqSIPNegTran_tqEfcTarMin_C);
        /* [-4000;4000]BIN4 = [-2000;2000]BIN4 + [-2000;2000]BIN4 */
        temp_s32 = temp_s32 + (SInt32)vsctl_tqefctarmin_prev;
        /* [-2000;4000]BIN4 */
        temp_s32 = DDS_M_MAX(temp_s32,(SInt32)VSCtl_tqCkEfcMinReq_swc_in);
        /* [-2000;2000]BIN4 */
        *VSCtl_tqEfcTarMin_swc_out = (SInt16)DDS_M_MIN(temp_s32,VSSP_2000_BIN4);

        VSCtl_tqEfcTarMinRaw = 0;

        VSCtl_tqSIPTranMinSecu = (SInt16)out_securedivi2;
    }
    else if(VSCTL_STCTL_TQEFCTARMIN_FIN_SIP_HIGH == (UInt32)VSCtl_stCtl_tqEfcTarMin)
    {
        /* [-2000;2000]BIN4 */
        temp_s32 = DDS_M_MAX(out_securedivi2,(SInt32)VSCtl_tqSIPPosTran_tqEfcTarMin_C);
        /* [-4000;4000]BIN4 = [-2000;2000]BIN4 + [-2000;2000]BIN4 */
        temp_s32 = temp_s32 + (SInt32)vsctl_tqefctarmin_prev;
        /* [-4000;2000]BIN4 */
        temp_s32 = DDS_M_MIN(temp_s32,(SInt32)VSCtl_tqCkEfcMinReq_swc_in);
        /* [-2000;2000]BIN4 */
        *VSCtl_tqEfcTarMin_swc_out = (SInt16)DDS_M_MAX(temp_s32,-VSSP_2000_BIN4);

        VSCtl_tqEfcTarMinRaw = 0;

        VSCtl_tqSIPTranMinSecu = (SInt16)out_securedivi2;
    }
    else if(VSCTL_STCTL_TQEFCTARMIN_SIP == (UInt32)VSCtl_stCtl_tqEfcTarMin)
    {
        *VSCtl_tqEfcTarMin_swc_out = filter_output;

        VSCtl_tqEfcTarMinRaw = (SInt16)filter_input;

        VSCtl_tqSIPTranMinSecu = 0;
    }
    else if(VSCTL_STCTL_TQEFCTARMIN_HORS_SIP == (UInt32)VSCtl_stCtl_tqEfcTarMin)
    {
        *VSCtl_tqEfcTarMin_swc_out = VSCtl_tqCkEfcMinReq_swc_in;

        VSCtl_tqEfcTarMinRaw = 0;

        VSCtl_tqSIPTranMinSecu = 0;
    }
    else    /* VSCTL_STCTL_TQEFCTARMIN_ARRET == (UInt32)VSCtl_stCtl_tqEfcTarMin */
    {
        *VSCtl_tqEfcTarMin_swc_out = (SInt16)(-VSSP_2000_BIN4);

        VSCtl_tqEfcTarMinRaw = 0;

        VSCtl_tqSIPTranMinSecu = 0;
    }

    vsctl_tqefctarmin_prev = *VSCtl_tqEfcTarMin_swc_out;
}

/*******************************************************************************
*
* Function Name : VSSP_F71321_Determiner_Consigne_Couple_Moteur_Max_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71321_Determiner_Consigne_Couple_Moteur_Max_Init(
                                                 SInt16 VSCtl_tqCkEfcMaxReq_swc_in /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.59.0 */
    VSCtl_tqCkEfcMaxReqDly = VSCtl_tqCkEfcMaxReq_swc_in;
    VSCtl_tqCkEfcMaxReqDly_NV = VSCtl_tqCkEfcMaxReq_swc_in;
}

/*******************************************************************************
*
* Function Name : VSSP_F71323_Determiner_Consigne_Couple_Moteur_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71323_Determiner_Consigne_Couple_Moteur_Max(
                                                 UInt16 VSCtl_rConvTra_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqLossTra_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxReq_swc_out /* BIN4 */)
{
    vssp_stctl_tqckefcmax_loc = VSCtl_stCtl_tqCkEfcMax;

    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.61.0 */
    VSSP_F713231_Determiner_Consigne_Couple_Moteur_Max_Boucle_Fermee(
                                           VSCtl_rConvTra_swc_in, /* BIN7 */
                                           VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                           VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                           VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                           VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                           VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                           VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                           VSCtl_tqLossTra_swc_in /* BIN4 */);

    VSSP_F713232_Determiner_Consigne_Couple_Moteur_Max_Boucle_Ouverte(
                                           VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                           VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                           VSCtl_tqCkEfcMaxReq_swc_out /* BIN4 */);
}

/*******************************************************************************
*
* Function Name : VSSP_F713231_Determiner_Consigne_Couple_Moteur_Max_Boucle_Fermee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F713231_Determiner_Consigne_Couple_Moteur_Max_Boucle_Fermee(
                                                 UInt16 vsctl_rconvtra_par, /* BIN7 */
                                                 SInt16 vsctl_tqckefcmax_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcmaxnotctla_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcmin_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcminnotctla_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcprecovsctlreq_par, /* BIN4 */
                                                 SInt16 vsctl_tqwhlmaxreq_par, /* BIN1 */
                                                 SInt16 vsctl_tqlosstra_par /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.133.1 */
    SInt16 sat_out;
    SInt16 filter_assym_out;
    SInt16 bary_tmp_out;
    SInt16 map_in_lim;
    SInt16 filter_out;
    SInt32 map_in;
    SInt32 switch_in_1;
    SInt32 switch_in_2;
    SInt32 vssph_temp;
    UInt16 map_out;
    UInt16 filter_in_factor_max;

    /* [-2000,2000]*/
    /* BIN4 = BIN1 * BIN10 / BIN7 */
/* <PRQA_COMMENT><2834> Range of VSCtl_rConvTra is 0.0078125 to 20. </2834></PRQA_COMMENT> */
    vssph_temp = ((SInt32)vsctl_tqwhlmaxreq_par * BIN10) / (SInt32)vsctl_rconvtra_par;
    vssph_temp = vssph_temp - (SInt32)vsctl_tqlosstra_par;
    sat_out = (SInt16)(DDS_M_SATURATION_V2(vssph_temp,(SInt32)vsctl_tqckefcmin_par,(SInt32)vsctl_tqckefcmax_par));

    /* [-4000,4000]BIN4 =[-2000,2000]BIN4 - [-2000,2000]BIN4  */
    map_in = (SInt32)sat_out - (SInt32)vsctl_tqckefcprecovsctlreq_par;

    map_in_lim = (SInt16)DDS_M_LIMIT(map_in,-VSSP_2000_BIN4,VSSP_2000_BIN4);

     /* [0;1]BIN10 */
    map_out = DDS_M_MAP2D_SU16(&VSCTL_TIFILMINTQCKMAX_TQDIF_T_APM,map_in_lim);

    /* [0;1]BIN10 */
    bary_tmp_out = DDS_M_BARY_FILTER_S16_V2((SInt16)VSCtl_tiFilTranDyn_tqCkMax_C,     /* [0;1]BIN10 */
                                         (SInt16)VSCtl_tiFilStabDyn_tqCkMax_C,     /* [0;1]BIN10 */
                                         (SInt16)VSCtl_rAnt_tqWhlPTMax,            /* [0;100]BIN7 */
                                         (UInt16)(100 * BIN7));

    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAntTqWhlPTMaxReq)
    {
        /* [0;1]BIN10 */
        filter_assym_out = DDS_M_FILTER_LP1_ASSYM_S16(&vssp_f713231_filter_assym_str,
                                                      (SInt16)map_out,                    /* [0;1]BIN10 */
                                                      VSCtl_tiFilUp_tiFilMinTqCkMax_C,    /* [0;1]BIN10 */
                                                      VSCtl_tiFilDw_tiFilMinTqCkMax_C,    /* [0;1]BIN10 */
                                                      BIN10);

        /* [0;1]BIN10 */
        filter_in_factor_max = (UInt16)DDS_M_MAX((SInt32)filter_assym_out,(SInt32)bary_tmp_out);

        /* [-2000,2000]BIN4 */
        filter_out = DDS_M_FILTER_LP1_S16(&vssp_f713231_filter_str,
                                          sat_out,                          /* [-2000,2000]BIN4 */
                                          filter_in_factor_max,             /* [0;1]BIN10 */
                                          BIN10);
    }
    else
    {
        /* [0;1]BIN10 */
        filter_assym_out = DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f713231_filter_assym_str,
                                                      (SInt16)map_out);

        /* [0;1]BIN10 */
        filter_in_factor_max = (UInt16)DDS_M_MAX((SInt32)filter_assym_out,(SInt32)bary_tmp_out);

        /* [-2000,2000]BIN4 */
        filter_out = DDS_M_FILTER_LP1_S16_INIT(&vssp_f713231_filter_str,
                                               sat_out);    /* [-2000,2000]BIN4 */
    }

    /* [-2000,2000]BIN4 */
    switch_in_1 = DDS_M_MAX((SInt32)filter_out,(SInt32)vsctl_tqckefcmaxnotctla_par);
    switch_in_2 = DDS_M_MIN((SInt32)filter_out,(SInt32)vsctl_tqckefcminnotctla_par);

    if(VSSP_VSCTL_STCTL_TQCKEFCMAX_CONTROLE != (UInt32)vssp_stctl_tqckefcmax_loc)
    {
        VSCtl_tqCkEfcMaxReqCll      = (SInt16)(2000 * BIN4);
        VSCtl_tqCkEfcMaxReqRaw      = (SInt16)(2000 * BIN4);
        VSCtl_tiFil_tqCkEfclMax       = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqCkEfcMaxRaw1    = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqCkEfcMaxRaw2    = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqCkEfcMaxRaw3    = (UInt16)(1 * BIN10);
    }
    else    /* VSSP_VSCTL_STCTL_TQCKEFCMAX_CONTROLE == VSCtl_stCtl_tqCkEfcMax */
    {
        if(VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_HAUT == (UInt32)VSCtl_stTqWhlPTCutOffReqPrev)
        {
            vssph_temp = switch_in_1;
        }
        else if(VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_BAS == (UInt32)VSCtl_stTqWhlPTCutOffReqPrev)
        {
            vssph_temp = switch_in_2;
        }
        else  /* VSCtl_stTqWhlPTCutOffReqPrev == VSSP_VSCTL_STTQWHLPTCUTOFFREQ_ARRET_INDETERMINE */
        {
            vssph_temp = (SInt32)filter_out;
        }

        /* [-2000,2000]BIN4 */
        VSCtl_tqCkEfcMaxReqCll = (SInt16)vssph_temp;

        /* [-2000;2000]BIN4 */
        VSCtl_tqCkEfcMaxReqRaw = sat_out;

        /* [0;1]DEC */
        VSCtl_tiFil_tqCkEfclMax = filter_in_factor_max;
        VSCtl_tiFil_tqCkEfcMaxRaw1 = (UInt16)filter_assym_out;
        VSCtl_tiFil_tqCkEfcMaxRaw2 = (UInt16)bary_tmp_out;
        VSCtl_tiFil_tqCkEfcMaxRaw3 = map_out;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F713232_Determiner_Consigne_Couple_Moteur_Max_Boucle_Ouverte
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F713232_Determiner_Consigne_Couple_Moteur_Max_Boucle_Ouverte(
                                                 SInt16 vsctl_tqckefcprecovscminreq_par, /* BIN4 */
                                                 SInt16 vsctl_tqckefcprecovsctlreq_par, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqckefcmaxreq_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.134.0 */
    SInt32 div_out;
    SInt32 switch_in_2;
    SInt32 switch_in_3;
    SInt32 vsctl_tqwhlptmaxreq_unlim;
    SInt16 vsctl_tqckefcmaxreq_loc;
    UInt16 vsctl_tifiltqckefcmaxreq_loc;

    vsctl_tifiltqckefcmaxreq_loc = VSCtl_tiFiltqCkEfcMaxReq;

    if((UInt32)vssp_f713232_switch_out_dly_init != (UInt32)DDS_TRUE)
    {
        vssp_f713232_switch_out_dly_init = DDS_TRUE;
        vssp_f713232_switch_out_dly = VSCtl_tqCkEfcMaxReqDly;
    }
    else
    {
        /* Nothing to do */
    }

    if(  (VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_L == (UInt32)vssp_stctl_tqckefcmax_loc)
       ||(VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_R == (UInt32)vssp_stctl_tqckefcmax_loc))
    {
        if(0 == ((SInt32)vsctl_tqckefcprecovsctlreq_par - (SInt32)vssp_f713232_switch_out_dly))          /* [-32000,32000]BIN1 */
        {
            div_out = 0 * BIN4; /* Middle value */
        }
        else if(0 == (UInt32)vsctl_tifiltqckefcmaxreq_loc)  /* [0;65535]DEC0 */
        {
            if(((SInt32)vsctl_tqckefcprecovsctlreq_par - (SInt32)vssp_f713232_switch_out_dly) > 0)
            {
                div_out = 11000 * BIN4;     /* Max positive value */
            }
            else
            {
                div_out = -4000 * BIN4; /* Max negative value */
            }
        }
        else
        {
            /*  [-4000;4000]BIN4 / [0;65535]DEC0 */
            div_out = ((SInt32)vsctl_tqckefcprecovsctlreq_par - (SInt32)vssp_f713232_switch_out_dly) / (SInt32)vsctl_tifiltqckefcmaxreq_loc;
        }

        if((UInt32)TRUE == (UInt32)VSCtl_bAcvTqCkEfcMaxReqSat_C)
        {
            /* BIN4 */
            switch_in_2 = DDS_M_MAX(div_out, (SInt32)VSCtl_tqErrSTran_tqCkMaxVSCtl_C) + (SInt32)vssp_f713232_switch_out_dly;
            /* BIN4 */
            switch_in_3 = DDS_M_MAX(div_out, (SInt32)VSCtl_tqErrFTran_tqCkMaxVSCtl_C) + (SInt32)vssp_f713232_switch_out_dly;
        }
        else
        {
            /* [-4000;4000]BIN4 = [0;2000]BIN4  + [-2000;2000]BIN4 */
            switch_in_2 = (SInt32)VSCtl_tqErrSTran_tqCkMaxVSCtl_C + (SInt32)vssp_f713232_switch_out_dly;
            /* [-4000;4000]BIN4 = [0;2000]BIN4  + [-2000;2000]BIN4 */
            switch_in_3 = (SInt32)VSCtl_tqErrFTran_tqCkMaxVSCtl_C + (SInt32)vssp_f713232_switch_out_dly;
        }
    }

    switch((UInt32)vssp_stctl_tqckefcmax_loc)
    {
        case (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_ARRET:
            vssp_f713232_switch_out_dly = (SInt16)(2000 * BIN4);
            vsctl_tqckefcmaxreq_loc = (SInt16)(2000 * BIN4);
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_CONTROLE:
            /* In this case, MIN block is useless because second value is lesser or equal to 2000 */
            vssp_f713232_switch_out_dly = VSCtl_tqCkEfcMaxReqCll;
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f713232_switch_out_dly,(SInt32)vsctl_tqckefcprecovscminreq_par);
            vsctl_tqckefcmaxreq_loc  = (SInt16)vsctl_tqwhlptmaxreq_unlim;
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_L:
/* <PRQA_COMMENT><2962> Variable switch_in_2 is set in previous if test </2962></PRQA_COMMENT> */
            vssp_f713232_switch_out_dly = (SInt16)DDS_M_MIN(VSSP_2000_BIN4, switch_in_2);
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f713232_switch_out_dly,(SInt32)vsctl_tqckefcprecovscminreq_par);
            vsctl_tqckefcmaxreq_loc  = (SInt16)vsctl_tqwhlptmaxreq_unlim;
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_R:
/* <PRQA_COMMENT><2962> Variable switch_in_3 is set in previous if test </2962></PRQA_COMMENT> */
            vssp_f713232_switch_out_dly = (SInt16)DDS_M_MIN(VSSP_2000_BIN4, switch_in_3);
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f713232_switch_out_dly,(SInt32)vsctl_tqckefcprecovscminreq_par);
            vsctl_tqckefcmaxreq_loc  = (SInt16)vsctl_tqwhlptmaxreq_unlim;
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_INIT:
            vssp_f713232_switch_out_dly = VSCtl_tqCkEfcMaxReqDly;
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f713232_switch_out_dly,(SInt32)vsctl_tqckefcprecovscminreq_par);
            vsctl_tqckefcmaxreq_loc  = (SInt16)vsctl_tqwhlptmaxreq_unlim;
            break;

        default:
            vssp_f713232_switch_out_dly = (SInt16)(2000 * BIN4);
            vsctl_tqckefcmaxreq_loc = (SInt16)(2000 * BIN4);
            break;
    }

    *vsctl_tqckefcmaxreq_ptr = vsctl_tqckefcmaxreq_loc;
}

/*******************************************************************************
*
* Function Name : VSSP_F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max(
                                                 UInt32 VSCtl_nEngFil_swc_in, /* BIN0 */
                                                 SInt16 VSCtl_tqCkEfcMaxReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                 SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMax_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.63.0 */
    UInt32 vssp_table_max_out;
    UInt32 vssp_table_min_out;
    UInt32 vssp_map_out;
    UInt16 vssp_filter_out;
    SInt32 vssp_svalue;
    UInt32 vssp_uvalue;

    /* BIN4:[-4000;4000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqCkEfcMaxReq_swc_in - (SInt32)VSCtl_tqCkEfcDrvMinReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_2000_BIN4,VSSP_2000_BIN4);
    /* BIN7:[0;100]% */
    vssp_table_max_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPENGSATMAX_T_APM[1],(SInt16)vssp_svalue);

    /* BIN4:[-4000;4000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqCkEfcDrvMaxReq_swc_in - (SInt32)VSCtl_tqCkEfcMaxReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_2000_BIN4,VSSP_2000_BIN4);
    /* BIN7:[0;100]% */
    vssp_table_min_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPENGSATMIN_T_APM[1],(SInt16)vssp_svalue);

    vssp_svalue = DDS_M_SATURATION_V2((SInt32)VSCtl_tqCkEfcMaxReq_swc_in,
                                      (SInt32)VSCtl_tqCkEfcDrvMinReq_swc_in,
                                      (SInt32)VSCtl_tqCkEfcDrvMaxReq_swc_in);

    /* BIN7:[0;100]% */
    vssp_map_out = (UInt32)DDS_M_MAP3D_SUU16(&VSCTL_RACCPENGMAX_M_APM,(SInt16)vssp_svalue,(UInt16)VSCtl_nEngFil_swc_in);

    if((UInt32)VSCtl_bAcvFil_tqCkEfcMax != (UInt32)DDS_FALSE)
    {
        /* BIN7:[0;100]% */
        vssp_uvalue = DDS_M_SATURATION_V2(vssp_map_out,vssp_table_min_out,vssp_table_max_out);
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f71325_filter_str, (UInt16)vssp_uvalue, VSCtl_tiFil_rAccPEngMax_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f71325_filter_str, (UInt16)(100 * BIN7));
    }


    if(  ((UInt32)VSCtl_stCtl_tqCkEfcMax == (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_CONTROLE)
       ||((UInt32)VSCtl_stCtl_tqCkEfcMax == (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_L)
       ||((UInt32)VSCtl_stCtl_tqCkEfcMax == (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_TRANS_R)
       ||((UInt32)VSCtl_stCtl_tqCkEfcMax == (UInt32)VSSP_VSCTL_STCTL_TQCKEFCMAX_INIT))
    {
        *VSCtl_rAccPEngMax_swc_out = vssp_filter_out;
    }
    else
    {
        *VSCtl_rAccPEngMax_swc_out = (UInt16)(100 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : F71328_Determiner_Consigne_Couple_Moteur_Cible_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71328_Determiner_Consigne_Couple_Moteur_Cible_Max(UInt16 CoPt_nPrimShaftTar_swc_in,   /* BIN0 */
                                                                UInt32 Ext_nFrntWhl_swc_in,         /* BIN7 */
                                                                SInt16 VSCtl_tqCkEfcMaxReq_swc_in,     /* BIN4 */
                                                                SInt16 VSCtl_tqWhlMaxReq_swc_in,    /* BIN1 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMax_swc_out)     /* BIN4 */
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.141.0 */
    SInt32 vsctl_tqefctarmax_t;
    SInt32 vsctl_tqefctarmin_t;
    SInt32 filter_input;
    SInt16 filter_output;
    UInt32 temp_u32;
    SInt32 temp_s32;
    SInt32 out_securedivi2;
    UInt16 vsctl_tifilstctltqefctarmax_cpy;

    vsctl_tifilstctltqefctarmax_cpy = VSCtl_tiFilStCtlTqEfcTarMax;

/* --------------------------- calculate filter input --------------------------------------------- */
    vsctl_tqefctarmax_t = (SInt32)DDS_M_MAP2D_US16(&VSCTL_TQEFCTARMAX_T_APM[0],
                                                    CoPt_nPrimShaftTar_swc_in);

    vsctl_tqefctarmin_t = (SInt32)DDS_M_MAP2D_US16(&VSCTL_TQEFCTARMIN_T_APM[0],
                                                    CoPt_nPrimShaftTar_swc_in);

    if((SInt32)VSCtl_tqWhlMaxReq_swc_in ==0)
    {
        filter_input = 0;
    }
    else
    {
        if((UInt32)CoPt_nPrimShaftTar_swc_in == 0)
        {
            temp_u32 = (UInt32)(0.1 * BIN12);
        }
        else if(Ext_nFrntWhl_swc_in == 0)
        {
            temp_u32 = (UInt32)(20 * BIN12);
        }
        else
        {
            /* [0.00005;64]BIN12 = ([1/2;8000]BIN0 * BIN19) / [1/128;10000]BIN7 */
            temp_u32 = ((UInt32)CoPt_nPrimShaftTar_swc_in * BIN19) / Ext_nFrntWhl_swc_in;
            temp_u32 = DDS_M_LIMIT(temp_u32,
                                    (UInt32)(0.1 * BIN12),
                                    (UInt32)(20 * BIN12));
        }
        /* [-160000;160000]BIN4 = ([-16000;16000]BIN1 * BIN15) / [0.1;10000]BIN12 */
        /* <PRQA_COMMENT><2834> Range of temp_u32 is 0.00005 to 64 </2834></PRQA_COMMENT> */
        filter_input = ((SInt32)VSCtl_tqWhlMaxReq_swc_in * BIN15) / (SInt32)temp_u32;
    }

    filter_input = DDS_M_SATURATION_V2(filter_input,
                                        vsctl_tqefctarmin_t,
                                        vsctl_tqefctarmax_t);
/* --------------------------- calculate filter output --------------------------------------------- */
    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_tqEfcTarMax)
    {
        filter_output = DDS_M_FILTER_LP1_S16_INIT(&vssp_f71328_filter_str,
                                                    (SInt16)filter_input);
    }
    else
    {
        filter_output = DDS_M_FILTER_LP1_S16(&vssp_f71328_filter_str,
                                                    (SInt16)filter_input,
                                                    VSCtl_tiFil_tqEfcTarMax_C,
                                                    BIN10);
    }
/* --------------------------- calculate out_securedivi2 --------------------------------------------- */
    if((SInt32)VSCtl_tqCkEfcMaxReq_swc_in != (SInt32)vsctl_tqefctarmax_prev)
    {
        if((UInt32)vsctl_tifilstctltqefctarmax_cpy == 0)
        {
            if((SInt32)VSCtl_tqCkEfcMaxReq_swc_in > (SInt32)vsctl_tqefctarmax_prev)
            {
                out_securedivi2 = VSSP_2000_BIN4;
            }
            else
            {
                out_securedivi2 = -VSSP_2000_BIN4;
            }
        }
        else
        {
            /* [-4000;4000]BIN4 = ([-2000;2000]BIN4 - [-2000;2000]BIN4) / [0;65535]BIN0 */
            out_securedivi2 = ((SInt32)VSCtl_tqCkEfcMaxReq_swc_in - (SInt32)vsctl_tqefctarmax_prev) / (SInt32)vsctl_tifilstctltqefctarmax_cpy;
            out_securedivi2 = DDS_M_LIMIT(out_securedivi2,
                                            -VSSP_2000_BIN4,
                                            VSSP_2000_BIN4);
        }
    }
    else
    {
        out_securedivi2 = 0;
    }
/* --------------------------- calculate outputs --------------------------------------------- */
    if(VSCTL_STCTL_TQEFCTARMAX_FIN_SIP_LOW == (UInt32)VSCtl_stCtl_tqEfcTarMax)
    {
        /* [-2000;2000]BIN4 */
        temp_s32 = DDS_M_MIN(out_securedivi2,(SInt32)VSCtl_tqSIPNegTran_tqEfcTarMax_C);
        /* [-4000;4000]BIN4 = [-2000;2000]BIN4 + [-2000;2000]BIN4 */
        temp_s32 = temp_s32 + (SInt32)vsctl_tqefctarmax_prev;
        /* [-2000;4000]BIN4 */
        temp_s32 = DDS_M_MAX(temp_s32,(SInt32)VSCtl_tqCkEfcMaxReq_swc_in);
        /* [-2000;2000]BIN4 */
        *VSCtl_tqEfcTarMax_swc_out = (SInt16)DDS_M_MIN(temp_s32,VSSP_2000_BIN4);

        VSCtl_tqEfcTarMaxRaw = 0;

        VSCtl_tqSIPTranMaxSecu = (SInt16)out_securedivi2;
    }
    else if(VSCTL_STCTL_TQEFCTARMAX_FIN_SIP_HIGH == (UInt32)VSCtl_stCtl_tqEfcTarMax)
    {
        /* [-2000;2000]BIN4 */
        temp_s32 = DDS_M_MAX(out_securedivi2,(SInt32)VSCtl_tqSIPPosTran_tqEfcTarMax_C);
        /* [-4000;4000]BIN4 = [-2000;2000]BIN4 + [-2000;2000]BIN4 */
        temp_s32 = temp_s32 + (SInt32)vsctl_tqefctarmax_prev;
        /* [-4000;2000]BIN4 */
        temp_s32 = DDS_M_MIN(temp_s32,(SInt32)VSCtl_tqCkEfcMaxReq_swc_in);
        /* [-2000;2000]BIN4 */
        *VSCtl_tqEfcTarMax_swc_out = (SInt16)DDS_M_MAX(temp_s32,-VSSP_2000_BIN4);

        VSCtl_tqEfcTarMaxRaw = 0;

        VSCtl_tqSIPTranMaxSecu = (SInt16)out_securedivi2;
    }
    else if(VSCTL_STCTL_TQEFCTARMAX_SIP == (UInt32)VSCtl_stCtl_tqEfcTarMax)
    {
        *VSCtl_tqEfcTarMax_swc_out = filter_output;

        VSCtl_tqEfcTarMaxRaw = (SInt16)filter_input;

        VSCtl_tqSIPTranMaxSecu = 0;
    }
    else if(VSCTL_STCTL_TQEFCTARMAX_HORS_SIP == (UInt32)VSCtl_stCtl_tqEfcTarMax)
    {
        *VSCtl_tqEfcTarMax_swc_out = VSCtl_tqCkEfcMaxReq_swc_in;

        VSCtl_tqEfcTarMaxRaw = 0;

        VSCtl_tqSIPTranMaxSecu = 0;
    }
    else    /* VSCTL_STCTL_TQEFCTARMAX_ARRET == (UInt32)VSCtl_stCtl_tqEfcTarMax */
    {
        *VSCtl_tqEfcTarMax_swc_out = (SInt16)(VSSP_2000_BIN4);

        VSCtl_tqEfcTarMaxRaw = 0;

        VSCtl_tqSIPTranMaxSecu = 0;
    }

    vsctl_tqefctarmax_prev = *VSCtl_tqEfcTarMax_swc_out;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Control_Wheel_Gmp2_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp2_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMax_swc_out, /* BIN7 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPEngMin_swc_out, /* BIN7 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxReq_swc_out, /* BIN4 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinReq_swc_out, /* BIN4 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMax_swc_out, /* BIN4 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqEfcTarMin_swc_out)   /* BIN4 */
{
    /* ---- Init Outputs ---- */
    *VSCtl_rAccPEngMax_swc_out = (UInt16)(100 * BIN7);
    *VSCtl_rAccPEngMin_swc_out = (UInt16)(0 * BIN7);
    *VSCtl_tqCkEfcMaxReq_swc_out = (SInt16)(2000 * BIN4);
    *VSCtl_tqCkEfcMinReq_swc_out = (SInt16)(-2000 * BIN4);
    *VSCtl_tqEfcTarMin_swc_out = (SInt16)(-2000 * BIN4);
    *VSCtl_tqEfcTarMax_swc_out = (SInt16)(2000 * BIN4);

    VSCtl_tqCkEfcMaxReqDly = VSCtl_tqCkEfcMaxReqDly_NV;

    /* ---- Init Global Datas ---- */
    vssp_stctl_tqckefcmax_loc = VSSP_VSCTL_STCTL_TQCKEFCMAX_INIT;

    /* ---- VSSP_F71312_Determiner_Consigne_Couple_Moteur_Min ---- */
    VSCtl_tqCkEfcMinReqRaw1 = (SInt16)(-2000 * BIN4);
    VSCtl_tqCkEfcMinReqRaw2 = (SInt16)(-2000 * BIN4);
    VSCtl_tiFil_tqCkEfcMin = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqCkEfcMinRaw1 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqCkEfcMinRaw2 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqCkEfcMinRaw3 = (UInt16)(1 * BIN10);
    DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f71312_filter_assym_str, 0);
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f71312_filter_str, 0);

    /* ---- VSSP_F71314_Determiner_Position_Pedale_Accelerateur_Moteur_Min ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f71314_filter_str, 0);

    /* ---- F71317_Determiner_Consigne_Couple_Moteur_Cible_Min ---- */
    vsctl_tqefctarmin_prev = *VSCtl_tqEfcTarMin_swc_out;
    VSCtl_tqEfcTarMinRaw = 0;
    VSCtl_tqSIPTranMinSecu = 0;
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f71317_filter_str,
                            (SInt16)0);

    /* ---- VSSP_F71323_Determiner_Consigne_Couple_Moteur_Max ---- */

    /* ---- VSSP_F713231_Determiner_Consigne_Couple_Moteur_Max_Boucle_Fermee ---- */
    VSCtl_tqCkEfcMaxReqCll      = (SInt16)(2000 * BIN4);
    VSCtl_tqCkEfcMaxReqRaw      = (SInt16)(2000 * BIN4);
    VSCtl_tiFil_tqCkEfclMax        = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqCkEfcMaxRaw1    = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqCkEfcMaxRaw2    = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqCkEfcMaxRaw3    = (UInt16)(1 * BIN10);
    DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f713231_filter_assym_str, 0);
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f713231_filter_str, 0);

    /* ---- VSSP_F713232_Determiner_Consigne_Couple_Moteur_Max_Boucle_Ouverte ---- */
    vssp_f713232_switch_out_dly_init = DDS_FALSE;

    /* ---- VSSP_F71325_Determiner_Position_Pedale_Accelerateur_Moteur_Max ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f71325_filter_str, 0);

    /* ---- F71328_Determiner_Consigne_Couple_Moteur_Cible_Max ---- */
    vsctl_tqefctarmax_prev = *VSCtl_tqEfcTarMax_swc_out;
    VSCtl_tqEfcTarMaxRaw = 0;
    VSCtl_tqSIPTranMaxSecu = 0;
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f71328_filter_str,
                            (SInt16)0);
}

/*******************************************************************************
*
* Function Name : VSSP_Control_Wheel_Gmp1_Sl_Cinit
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp2_Sl_Cinit(void)
{
    VSCtl_tqCkEfcMaxReqDly_NV = 2000 * BIN4;
}

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

