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
* Ref X:\integration_view_00PSASWC_D810D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Control_Wheel_Gmp1_Sl.c
* Version int :/main/L02_01/1 Date: 7/9/2011 16 h 40 m User:esnault 
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 4/8/2011 17 h 15 m User:demezil 
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 26/7/2011 14 h 47 m User:demezil
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version int :/main/L01_01/3 Date: 30/5/2011 9 h 9 m User:esnault
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL3_D
*    comments :BARYCENTRE -> BARYCENTRE_V2
* Version dev :\main\branch_lemort_eom_dev\1 Date: 20/5/2011 10 h 19 m User:lemort
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL3_D
*    comments :BARYCENTRE -> BARYCENTRE_V2
* Version int :/main/L01_01/2 Date: 16/3/2011 11 h 48 m User:esnault
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL3
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\12 Date: 7/3/2011 14 h 23 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL3
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\10 Date: 3/3/2011 9 h 15 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL2
*    comments :VSSp 10.0 : . VSCtl_stTqWhlPTCutOffReqPrev rename with VSCtl_stTqWhlPTCutOffReqDly;

*    comments :UT correction
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 53 m User:meme
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\7 Date: 14/2/2011 14 h 21 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\6 Date: 14/2/2011 9 h 53 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 9/2/2011 17 h 25 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 19/1/2011 8 h 39 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
*    comments :correct map name
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 6 m User:morisseau
*    TWK_model:VSSP_Control_Wheel_Gmp1_Sl_L01_010_IMPL1
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
extern VAR(UInt16, AUTOMATIC) VSCtl_tiFiltqWhlPTMaxReq; /* DEC0 */
extern VAR(UInt16, AUTOMATIC) VSCtl_tiTqWhlPTMinSatTraMax; /* BIN0 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilTqWhlPTMinSat;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAntTqWhlPTMaxReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAntTqWhlPTMinReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTCutOffReqPrev; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlPTMinSat; /* BIN0 */
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
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReqDly; /* BIN1 */
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilDw_tiFilMinTqWhlMn_C = (CONST(UInt16, AUTOMATIC))(0.094 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilDw_tiFilMinTqWhlMx_C = (CONST(UInt16, AUTOMATIC))(0.094 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilStabDyn_tqWhlMax_C = (CONST(UInt16, AUTOMATIC))(0.078 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilStabDyn_tqWhlMin_C = (CONST(UInt16, AUTOMATIC))(0.078 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilTranDyn_tqWhlMax_C = (CONST(UInt16, AUTOMATIC))(0.203 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilTranDyn_tqWhlMin_C = (CONST(UInt16, AUTOMATIC))(0.195 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilUp_tiFilMinTqWhlMn_C = (CONST(UInt16, AUTOMATIC))(0.047 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilUp_tiFilMinTqWhlMx_C = (CONST(UInt16, AUTOMATIC))(0.047 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlPTMinSat_C = (CONST(UInt16, AUTOMATIC))(0.203 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqErrFTra_tqWhlMaxVSCtl_C = (CONST(UInt16, AUTOMATIC))(38 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqErrSTra_tqWhlMaxVSCtl_C = (CONST(UInt16, AUTOMATIC))(19 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqErrTran_tqMinSat_C = (CONST(UInt16, AUTOMATIC))(19 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPPTMax_C = (CONST(UInt16, AUTOMATIC))(0.203 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rAccPPTMin_C = (CONST(UInt16, AUTOMATIC))(0.203 * BIN10);
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvTqWhlPTMaxReqSat_C = DDS_TRUE;
#define VSSP_STOP_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSSP_START_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilMinTqWhlMin_tqDif_T
[VSSP_8_SIZE] = {
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlDif_tiFilMinTqMin_A[VSSP_8_SIZE] = {
(SInt16)(-4000 * BIN1), (SInt16)(0 * BIN1), (SInt16)(40 * BIN1),
(SInt16)(7000 * BIN1), (SInt16)(8000 * BIN1), (SInt16)(9000 * BIN1),
(SInt16)(10000 * BIN1), (SInt16)(11000 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPPTSatMax_T
[VSSP_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPPTSatMin_T
[VSSP_8_SIZE] = {
(UInt16)(100 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTErr_rAccPPTSatMn_A[VSSP_8_SIZE] = {
(SInt16)(0 * BIN1), (SInt16)(5 * BIN1), (SInt16)(10 * BIN1),
(SInt16)(20 * BIN1), (SInt16)(40 * BIN1), (SInt16)(60 * BIN1),
(SInt16)(80 * BIN1), (SInt16)(100 * BIN1)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTErr_rAccPPTSatMx_A[VSSP_8_SIZE] = {
(SInt16)(0 * BIN1), (SInt16)(5 * BIN1), (SInt16)(10 * BIN1),
(SInt16)(20 * BIN1), (SInt16)(40 * BIN1), (SInt16)(60 * BIN1),
(SInt16)(80 * BIN1), (SInt16)(100 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPPTMin_M
[VSSP_25_SIZE][VSSP_13_SIZE] = {
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(8 * BIN7),
(UInt16)(15 * BIN7), (UInt16)(20 * BIN7), (UInt16)(32 * BIN7),
(UInt16)(37 * BIN7), (UInt16)(44 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(23 * BIN7), (UInt16)(26 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(34 * BIN7), (UInt16)(39 * BIN7), (UInt16)(44 * BIN7),
(UInt16)(71 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(3 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(24 * BIN7), (UInt16)(25 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(33 * BIN7), (UInt16)(35 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(91 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(3 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(24 * BIN7), (UInt16)(25 * BIN7), (UInt16)(29 * BIN7),
(UInt16)(31 * BIN7), (UInt16)(33 * BIN7), (UInt16)(36 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(46 * BIN7), (UInt16)(97 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(22 * BIN7), (UInt16)(23 * BIN7), (UInt16)(28 * BIN7),
(UInt16)(31 * BIN7), (UInt16)(33 * BIN7), (UInt16)(35 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(45 * BIN7), (UInt16)(84 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(8 * BIN7), (UInt16)(19 * BIN7),
(UInt16)(22 * BIN7), (UInt16)(23 * BIN7), (UInt16)(28 * BIN7),
(UInt16)(32 * BIN7), (UInt16)(34 * BIN7), (UInt16)(36 * BIN7),
(UInt16)(41 * BIN7), (UInt16)(48 * BIN7), (UInt16)(83 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(16 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(22 * BIN7), (UInt16)(23 * BIN7), (UInt16)(28 * BIN7),
(UInt16)(32 * BIN7), (UInt16)(34 * BIN7), (UInt16)(39 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(54 * BIN7), (UInt16)(93 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(15 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(23 * BIN7), (UInt16)(24 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(33 * BIN7), (UInt16)(36 * BIN7), (UInt16)(42 * BIN7),
(UInt16)(45 * BIN7), (UInt16)(68 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(19 * BIN7), (UInt16)(22 * BIN7),
(UInt16)(24 * BIN7), (UInt16)(26 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(35 * BIN7), (UInt16)(41 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(53 * BIN7), (UInt16)(94 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(21 * BIN7), (UInt16)(24 * BIN7),
(UInt16)(26 * BIN7), (UInt16)(28 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(38 * BIN7), (UInt16)(44 * BIN7), (UInt16)(51 * BIN7),
(UInt16)(67 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(22 * BIN7), (UInt16)(24 * BIN7),
(UInt16)(28 * BIN7), (UInt16)(30 * BIN7), (UInt16)(34 * BIN7),
(UInt16)(41 * BIN7), (UInt16)(46 * BIN7), (UInt16)(59 * BIN7),
(UInt16)(86 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(22 * BIN7), (UInt16)(25 * BIN7),
(UInt16)(28 * BIN7), (UInt16)(30 * BIN7), (UInt16)(36 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(52 * BIN7), (UInt16)(73 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(23 * BIN7), (UInt16)(27 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(31 * BIN7), (UInt16)(41 * BIN7),
(UInt16)(47 * BIN7), (UInt16)(67 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(34 * BIN7), (UInt16)(37 * BIN7), (UInt16)(48 * BIN7),
(UInt16)(71 * BIN7), (UInt16)(94 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(29 * BIN7),
(UInt16)(33 * BIN7), (UInt16)(35 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(66 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(34 * BIN7), (UInt16)(37 * BIN7), (UInt16)(48 * BIN7),
(UInt16)(83 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(35 * BIN7), (UInt16)(39 * BIN7), (UInt16)(52 * BIN7),
(UInt16)(98 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(32 * BIN7),
(UInt16)(39 * BIN7), (UInt16)(43 * BIN7), (UInt16)(66 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(41 * BIN7), (UInt16)(44 * BIN7), (UInt16)(97 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(44 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(45 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(45 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(32 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(45 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(48 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(14 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(65 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinReq_rAccPMnX_A[VSSP_13_SIZE] = {
(SInt16)(-500 * BIN1), (SInt16)(0 * BIN1), (SInt16)(200 * BIN1),
(SInt16)(400 * BIN1), (SInt16)(500 * BIN1), (SInt16)(1000 * BIN1),
(SInt16)(1500 * BIN1), (SInt16)(2000 * BIN1), (SInt16)(2500 * BIN1),
(SInt16)(3000 * BIN1), (SInt16)(4000 * BIN1), (SInt16)(5000 * BIN1),
(SInt16)(5500 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPPTMin_Y_A[VSSP_25_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(1 * BIN7), (UInt16)(5 * BIN7),
(UInt16)(7.5 * BIN7), (UInt16)(10 * BIN7), (UInt16)(12.5 * BIN7),
(UInt16)(15 * BIN7), (UInt16)(20 * BIN7), (UInt16)(25 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(35 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(70 * BIN7),
(UInt16)(80 * BIN7), (UInt16)(90 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(110 * BIN7), (UInt16)(120 * BIN7), (UInt16)(140 * BIN7),
(UInt16)(160 * BIN7), (UInt16)(180 * BIN7), (UInt16)(200 * BIN7),
(UInt16)(220 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilMinTqWhlMax_tqDif_T
[VSSP_8_SIZE] = {
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlDif_tiFilMinTqMax_A[VSSP_8_SIZE] = {
(SInt16)(-4000 * BIN1), (SInt16)(-3500 * BIN1), (SInt16)(-3000 * BIN1),
(SInt16)(-2500 * BIN1), (SInt16)(-2000 * BIN1), (SInt16)(-40 * BIN1),
(SInt16)(0 * BIN1), (SInt16)(11000 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPPTMax_M
[VSSP_25_SIZE][VSSP_13_SIZE] = {
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(8 * BIN7),
(UInt16)(15 * BIN7), (UInt16)(20 * BIN7), (UInt16)(32 * BIN7),
(UInt16)(37 * BIN7), (UInt16)(44 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(23 * BIN7), (UInt16)(26 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(34 * BIN7), (UInt16)(39 * BIN7), (UInt16)(44 * BIN7),
(UInt16)(71 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(3 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(24 * BIN7), (UInt16)(25 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(33 * BIN7), (UInt16)(35 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(91 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(3 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(24 * BIN7), (UInt16)(25 * BIN7), (UInt16)(29 * BIN7),
(UInt16)(31 * BIN7), (UInt16)(33 * BIN7), (UInt16)(36 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(46 * BIN7), (UInt16)(97 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(5 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(22 * BIN7), (UInt16)(23 * BIN7), (UInt16)(28 * BIN7),
(UInt16)(31 * BIN7), (UInt16)(33 * BIN7), (UInt16)(35 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(45 * BIN7), (UInt16)(84 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(8 * BIN7), (UInt16)(19 * BIN7),
(UInt16)(22 * BIN7), (UInt16)(23 * BIN7), (UInt16)(28 * BIN7),
(UInt16)(32 * BIN7), (UInt16)(34 * BIN7), (UInt16)(36 * BIN7),
(UInt16)(41 * BIN7), (UInt16)(48 * BIN7), (UInt16)(83 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(16 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(22 * BIN7), (UInt16)(23 * BIN7), (UInt16)(28 * BIN7),
(UInt16)(32 * BIN7), (UInt16)(34 * BIN7), (UInt16)(39 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(54 * BIN7), (UInt16)(93 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(15 * BIN7), (UInt16)(21 * BIN7),
(UInt16)(23 * BIN7), (UInt16)(24 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(33 * BIN7), (UInt16)(36 * BIN7), (UInt16)(42 * BIN7),
(UInt16)(45 * BIN7), (UInt16)(68 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(19 * BIN7), (UInt16)(22 * BIN7),
(UInt16)(24 * BIN7), (UInt16)(26 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(35 * BIN7), (UInt16)(41 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(53 * BIN7), (UInt16)(94 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(21 * BIN7), (UInt16)(24 * BIN7),
(UInt16)(26 * BIN7), (UInt16)(28 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(38 * BIN7), (UInt16)(44 * BIN7), (UInt16)(51 * BIN7),
(UInt16)(67 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(22 * BIN7), (UInt16)(24 * BIN7),
(UInt16)(28 * BIN7), (UInt16)(30 * BIN7), (UInt16)(34 * BIN7),
(UInt16)(41 * BIN7), (UInt16)(46 * BIN7), (UInt16)(59 * BIN7),
(UInt16)(86 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(22 * BIN7), (UInt16)(25 * BIN7),
(UInt16)(28 * BIN7), (UInt16)(30 * BIN7), (UInt16)(36 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(52 * BIN7), (UInt16)(73 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(23 * BIN7), (UInt16)(27 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(31 * BIN7), (UInt16)(41 * BIN7),
(UInt16)(47 * BIN7), (UInt16)(67 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(34 * BIN7), (UInt16)(37 * BIN7), (UInt16)(48 * BIN7),
(UInt16)(71 * BIN7), (UInt16)(94 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(29 * BIN7),
(UInt16)(33 * BIN7), (UInt16)(35 * BIN7), (UInt16)(45 * BIN7),
(UInt16)(66 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(34 * BIN7), (UInt16)(37 * BIN7), (UInt16)(48 * BIN7),
(UInt16)(83 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(35 * BIN7), (UInt16)(39 * BIN7), (UInt16)(52 * BIN7),
(UInt16)(98 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(32 * BIN7),
(UInt16)(39 * BIN7), (UInt16)(43 * BIN7), (UInt16)(66 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(41 * BIN7), (UInt16)(44 * BIN7), (UInt16)(97 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(44 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(27 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(45 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(26 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(45 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(32 * BIN7),
(UInt16)(42 * BIN7), (UInt16)(45 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(25 * BIN7), (UInt16)(33 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(48 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) },
{
(UInt16)(0 * BIN7), (UInt16)(14 * BIN7), (UInt16)(31 * BIN7),
(UInt16)(44 * BIN7), (UInt16)(65 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(100 * BIN7) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReq_rAccPMxX_A[VSSP_13_SIZE] = {
(SInt16)(-500 * BIN1), (SInt16)(0 * BIN1), (SInt16)(200 * BIN1),
(SInt16)(400 * BIN1), (SInt16)(500 * BIN1), (SInt16)(1000 * BIN1),
(SInt16)(1500 * BIN1), (SInt16)(2000 * BIN1), (SInt16)(2500 * BIN1),
(SInt16)(3000 * BIN1), (SInt16)(4000 * BIN1), (SInt16)(5000 * BIN1),
(SInt16)(5500 * BIN1)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPPTMax_Y_A[VSSP_25_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(1 * BIN7), (UInt16)(5 * BIN7),
(UInt16)(7.5 * BIN7), (UInt16)(10 * BIN7), (UInt16)(12.5 * BIN7),
(UInt16)(15 * BIN7), (UInt16)(20 * BIN7), (UInt16)(25 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(35 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(60 * BIN7), (UInt16)(70 * BIN7),
(UInt16)(80 * BIN7), (UInt16)(90 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(110 * BIN7), (UInt16)(120 * BIN7), (UInt16)(140 * BIN7),
(UInt16)(160 * BIN7), (UInt16)(180 * BIN7), (UInt16)(200 * BIN7),
(UInt16)(220 * BIN7)
};
#define VSSP_STOP_SEC_CARTO_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_raccpptsatmax_t_sav[VSSP_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_raccpptsatmin_t_sav[VSSP_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tifilmintqwhlmax_tqdif_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tifilmintqwhlmin_tqdif_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccpptmax_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) vsctl_raccpptmin_m_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71212_filter_assym_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71212_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71214_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f712231_filter_assym_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f712231_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71225_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f71232_filter_str;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"

/* 16-bits variable definition */
#define VSSP_START_SEC_VAR_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vssp_f712232_switch_out_dly; /* BIN1 */
STATIC VAR(SInt16, AUTOMATIC) vssp_f71232_vsctl_tqwhlptminsat_dly; /* BIN1 */
#define VSSP_STOP_SEC_VAR_16BIT
#include "VSSp_MemMap.h"

/* 8-bits variable definition */
#define VSSP_START_SEC_VAR_8BIT
#include "VSSp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vssp_f712232_switch_out_dly_init;
STATIC VAR(UInt8, AUTOMATIC) vssp_stctl_tqwhlptmax_loc;
#define VSSP_STOP_SEC_VAR_8BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMax; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMaxRaw1; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMaxRaw2; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMaxRaw3; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMin; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMinRaw1; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMinRaw2; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlMinRaw3; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReqCll; /* BIN1 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReqRaw; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinReqRaw1; /* BIN1 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinReqRaw2; /* BIN1 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* Variable To Keep On Hot Reset
*******************************************************************************/

#define VSSP_START_SEC_VAR_POWER_ON_INIT_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReqDly_NV;
#define VSSP_STOP_SEC_VAR_POWER_ON_INIT_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSSP_START_SEC_CONST_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_TIFILMINTQWHLMIN_TQDIF_T_APM = {
&vsctl_tifilmintqwhlmin_tqdif_t_sav,
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlDif_tiFilMinTqMin_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiFilMinTqWhlMin_tqDif_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RACCPPTSATMAX_T_APM[VSSP_2_SIZE] = {
{
&vsctl_raccpptsatmax_t_sav[0],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlPTErr_rAccPPTSatMx_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPPTSatMax_T[0]
},
{
&vsctl_raccpptsatmax_t_sav[1],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlPTErr_rAccPPTSatMx_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPPTSatMax_T[0]
}
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_RACCPPTSATMIN_T_APM[VSSP_2_SIZE] = {
{
&vsctl_raccpptsatmin_t_sav[0],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlPTErr_rAccPPTSatMn_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPPTSatMin_T[0]
},
{
&vsctl_raccpptsatmin_t_sav[1],
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlPTErr_rAccPPTSatMn_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPPTSatMin_T[0]
}
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPPTMIN_M_APM = {
&vsctl_raccpptmin_m_sav,
VSSP_13_SIZE,
VSSP_25_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlPTMinReq_rAccPMnX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPPTMin_Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPPTMin_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) VSCTL_RACCPPTMAX_M_APM = {
&vsctl_raccpptmax_m_sav,
VSSP_13_SIZE,
VSSP_25_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlPTMaxReq_rAccPMxX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPPTMax_Y_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPPTMax_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) VSCTL_TIFILMINTQWHLMAX_TQDIF_T_APM = {
&vsctl_tifilmintqwhlmax_tqdif_t_sav,
VSSP_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqWhlDif_tiFilMinTqMax_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tiFilMinTqWhlMax_tqDif_T[0]
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



STATIC FUNC(void, AUTOMATIC) VSSP_F712231_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Fermee(
                                                 SInt16 vsctl_tqwhlmaxreq_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptmax_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptmaxnotctla_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptmin_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptminnotctla_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptprecovsctlreq_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSSP_F712232_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Ouverte(
                                                 SInt16 vsctl_tqwhlptprecovscminreq_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptprecovsctlreq_par, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlptmaxreq_ptr /* BIN1 */);

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
* Function Name : VSSP_F71212_Determiner_Consigne_Couple_Roue_Gmp_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71212_Determiner_Consigne_Couple_Roue_Gmp_Min(
                                                 SInt16 VSCtl_tqWhlMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinReq_swc_out /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.08.3 */
    UInt32 vssp_bary_filter_out;
    UInt32 vssp_filter_assy_out;
    SInt32 vssp_filter_out;
    UInt32 vssp_max_out;
    SInt32 vssp_svalue;
    SInt16 vssp_saturation_out;
    UInt16 vssp_map_out;
    UInt8 vsctl_sttqwhlptcutoffreqprev_loc;

    vsctl_sttqwhlptcutoffreqprev_loc = VSCtl_stTqWhlPTCutOffReqPrev;

    /* filtre_barycentrique */
    /* BIN10:[0;1] */
    vssp_bary_filter_out = (UInt32)DDS_M_BARY_FILTER_S32_V2((SInt32)VSCtl_tiFilTranDyn_tqWhlMin_C,
                                                         (SInt32)VSCtl_tiFilStabDyn_tqWhlMin_C,
                                                         VSCtl_rAnt_tqWhlPTMin,
                                                         (UInt16)(100 * BIN7));

    /* saturation */
    /* BIN1:[-16000;16000] */
    vssp_saturation_out = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlMinReq_swc_in,
                                                      (SInt32)VSCtl_tqWhlPTMin_swc_in,
                                                      (SInt32)VSCtl_tqWhlPTMax_swc_in);

    /* map VSCtl_tiFilMinTqWhlMin_tqDif_T */
    /* BIN1:[-32000;32000] */
    vssp_svalue = (SInt32)vssp_saturation_out - (SInt32)VSCtl_tqWhlPTPreCoVSCtlReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    vssp_map_out = DDS_M_MAP2D_SU16(&VSCTL_TIFILMINTQWHLMIN_TQDIF_T_APM,(SInt16)vssp_svalue);

    /* filtre_1er_ordre assymetrique */
    /* filtre_1er_ordre */
    if((UInt32)VSCtl_bAntTqWhlPTMinReq != (UInt32)DDS_FALSE)
    {
        vssp_filter_assy_out = (UInt32)DDS_M_FILTER_LP1_ASSYM_S16(
                                                &vssp_f71212_filter_assym_str,
                                                (SInt16)vssp_map_out,               /* [0;1]BIN10 */
                                                VSCtl_tiFilUp_tiFilMinTqWhlMn_C,    /* [0;1]BIN10 */
                                                VSCtl_tiFilDw_tiFilMinTqWhlMn_C,    /* [0;1]BIN10 */
                                                BIN10);

        /* BIN10:[0;1] */
        vssp_max_out = DDS_M_MAX(vssp_filter_assy_out,vssp_bary_filter_out);

        /* BIN1:[-16000;16000] */
        vssp_filter_out = (SInt32)DDS_M_FILTER_LP1_S16(&vssp_f71212_filter_str, vssp_saturation_out, (UInt16)vssp_max_out, BIN10);
    }
    else
    {
        vssp_filter_assy_out = (UInt32)DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f71212_filter_assym_str,(SInt16)vssp_map_out);

        /* BIN10:[0;1] */
        vssp_max_out = DDS_M_MAX(vssp_filter_assy_out,vssp_bary_filter_out);

        /* BIN1:[-16000;16000] */
        vssp_filter_out = (SInt32)DDS_M_FILTER_LP1_S16_INIT(&vssp_f71212_filter_str, vssp_saturation_out);
    }


    if((UInt32)VSCtl_stCtl_tqWhlPTMin == VSSP_VSCTL_STCTL_TQWHLPTMIN_ARRET)
    {
        *VSCtl_tqWhlPTMinReq_swc_out = (SInt16)(-4000 * BIN1);
        VSCtl_tqWhlPTMinReqRaw1 = (SInt16)(-4000 * BIN1);
        VSCtl_tqWhlPTMinReqRaw2 = (SInt16)(-4000 * BIN1);
        VSCtl_tiFil_tqWhlMin = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqWhlMinRaw1 = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqWhlMinRaw2 = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqWhlMinRaw3 = (UInt16)(1 * BIN10);
    }
    else
    {
        if((UInt32)vsctl_sttqwhlptcutoffreqprev_loc == VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_HAUT)
        {
            vssp_svalue = DDS_M_MAX((SInt32)VSCtl_tqWhlPTMaxNotCtla_swc_in,vssp_filter_out);
        }
        else if((UInt32)vsctl_sttqwhlptcutoffreqprev_loc == VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_BAS)
        {
            vssp_svalue = DDS_M_MIN((SInt32)VSCtl_tqWhlPTMinNotCtla_swc_in,vssp_filter_out);
        }
        else
        {
            vssp_svalue = vssp_filter_out;
        }
        VSCtl_tqWhlPTMinReqRaw1 = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_4000_BIN1,VSSP_11000_BIN1);


        vssp_svalue = DDS_M_MAX((SInt32)VSCtl_tqWhlPTMinReqRaw1,(SInt32)VSCtl_tqWhlPTPreCoVSCMinReq_swc_in);
        *VSCtl_tqWhlPTMinReq_swc_out = (SInt16)DDS_M_LIMIT(vssp_svalue,-VSSP_4000_BIN1,VSSP_11000_BIN1);

        VSCtl_tqWhlPTMinReqRaw2 = (SInt16)DDS_M_LIMIT((SInt32)vssp_saturation_out,-VSSP_4000_BIN1,VSSP_11000_BIN1);
        VSCtl_tiFil_tqWhlMin = (UInt16)vssp_max_out;
        VSCtl_tiFil_tqWhlMinRaw1 = (UInt16)vssp_filter_assy_out;
        VSCtl_tiFil_tqWhlMinRaw2 = (UInt16)vssp_bary_filter_out;
        VSCtl_tiFil_tqWhlMinRaw3 = vssp_map_out;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F71214_Determiner_Position_Pedale_Accelerateur_Gmp_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71214_Determiner_Position_Pedale_Accelerateur_Gmp_Min(
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMinReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMin_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.10.1 */
    UInt32 vssp_table_max_out;
    UInt32 vssp_table_min_out;
    UInt32 vssp_map_out;
    UInt16 vssp_filter_out;
    SInt32 vssp_svalue;
    UInt32 vssp_uvalue;

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqWhlPTMinReq_swc_in - (SInt32)VSCtl_tqWhlPTDrvMinReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    /* BIN7:[0;100]% */
    vssp_table_max_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPPTSATMAX_T_APM[0],(SInt16)vssp_svalue);

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqWhlPTDrvMaxReq_swc_in - (SInt32)VSCtl_tqWhlPTMinReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    /* BIN7:[0;100]% */
    vssp_table_min_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPPTSATMIN_T_APM[0],(SInt16)vssp_svalue);

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPTMinReq_swc_in,
                                      (SInt32)VSCtl_tqWhlPTDrvMinReq_swc_in,
                                      (SInt32)VSCtl_tqWhlPTDrvMaxReq_swc_in);

    /* BIN7:[0;100]% */
    vssp_map_out = (UInt32)DDS_M_MAP3D_SUU16(&VSCTL_RACCPPTMIN_M_APM,(SInt16)vssp_svalue,VSCtl_spdVeh_swc_in);

    if((UInt32)VSCtl_bAcvFil_tqWhlPTMin != (UInt32)DDS_FALSE)
    {
        /* BIN7:[0;100]% */
        vssp_uvalue = DDS_M_SATURATION_V2(vssp_map_out,vssp_table_min_out,vssp_table_max_out);
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f71214_filter_str, (UInt16)vssp_uvalue, VSCtl_tiFil_rAccPPTMin_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f71214_filter_str, 0);
    }


    if((UInt32)VSCtl_stCtl_tqWhlPTMin == VSSP_VSCTL_STCTL_TQWHLPTMIN_CONTROLE)
    {
        *VSCtl_rAccPPTMin_swc_out = vssp_filter_out;
    }
    else
    {
        *VSCtl_rAccPPTMin_swc_out = (UInt16)(0 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F71221_Determiner_Consigne_Couple_Roue_Gmp_Max_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71221_Determiner_Consigne_Couple_Roue_Gmp_Max_Init(
                                                 SInt16 VSCtl_tqWhlPTMaxReq_swc_in /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.45.0 */
    VSCtl_tqWhlPTMaxReqDly = VSCtl_tqWhlPTMaxReq_swc_in;
    VSCtl_tqWhlPTMaxReqDly_NV = VSCtl_tqWhlPTMaxReq_swc_in;
}

/*******************************************************************************
*
* Function Name : VSSP_F71223_Determiner_Consigne_Couple_Roue_Gmp_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71223_Determiner_Consigne_Couple_Roue_Gmp_Max(
                                                 SInt16 VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxReq_swc_out /* BIN1 */)
{
    vssp_stctl_tqwhlptmax_loc = VSCtl_stCtl_tqWhlPTMax;

    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.132.0 */
    VSSP_F712231_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Fermee(
                                                 VSCtl_tqWhlMaxReq_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in /* BIN1 */);

    VSSP_F712232_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Ouverte(
                                                 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                                                 VSCtl_tqWhlPTMaxReq_swc_out /* BIN1 */);
}

/*******************************************************************************
*
* Function Name : VSSP_F712231_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Fermee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F712231_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Fermee(
                                                 SInt16 vsctl_tqwhlmaxreq_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptmax_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptmaxnotctla_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptmin_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptminnotctla_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptprecovsctlreq_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.16.2 */
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
    UInt8 vsctl_sttqwhlptcutoffreqprev_loc;

    vsctl_sttqwhlptcutoffreqprev_loc = VSCtl_stTqWhlPTCutOffReqPrev;

    /* [-16000,16000]BIN1 */
    sat_out = (SInt16)(DDS_M_SATURATION_V2((SInt32)vsctl_tqwhlmaxreq_par,(SInt32)vsctl_tqwhlptmin_par,(SInt32)vsctl_tqwhlptmax_par));

    /* [-32000,32000]BIN1 =[-16000,16000]BIN1 - [-16000,16000]BIN1  */
    map_in = (SInt32)sat_out - (SInt32)vsctl_tqwhlptprecovsctlreq_par;

    map_in_lim = (SInt16)DDS_M_LIMIT(map_in,-VSSP_16000_BIN1,VSSP_16000_BIN1);

     /* [0;1]BIN10 */
    map_out = DDS_M_MAP2D_SU16(&VSCTL_TIFILMINTQWHLMAX_TQDIF_T_APM,map_in_lim);

    /* [0;1]BIN10 */
    bary_tmp_out = DDS_M_BARY_FILTER_S16_V2((SInt16)VSCtl_tiFilTranDyn_tqWhlMax_C,     /* [0;1]BIN10 */
                                         (SInt16)VSCtl_tiFilStabDyn_tqWhlMax_C,     /* [0;1]BIN10 */
                                         (SInt16)VSCtl_rAnt_tqWhlPTMax,             /* [0;100]BIN7 */
                                         (UInt16)(100 * BIN7));

    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAntTqWhlPTMaxReq)
    {
        /* [0;1]BIN10 */
        filter_assym_out = DDS_M_FILTER_LP1_ASSYM_S16(&vssp_f712231_filter_assym_str,
                                                      (SInt16)map_out,                    /* [0;1]BIN10 */
                                                      VSCtl_tiFilUp_tiFilMinTqWhlMx_C,    /* [0;1]BIN10 */
                                                      VSCtl_tiFilDw_tiFilMinTqWhlMx_C,    /* [0;1]BIN10 */
                                                      BIN10);

        /* [0;1]BIN10 */
        filter_in_factor_max = (UInt16)DDS_M_MAX((SInt32)filter_assym_out,(SInt32)bary_tmp_out);

        /* [-16000,16000]BIN1 */
        filter_out = DDS_M_FILTER_LP1_S16(&vssp_f712231_filter_str,
                                          sat_out,                          /* [-16000,16000]BIN1 */
                                          filter_in_factor_max,             /* [0;1]BIN10 */
                                          BIN10);
    }
    else
    {
        /* [0;1]BIN10 */
        filter_assym_out = DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f712231_filter_assym_str,
                                                      (SInt16)map_out);

        /* [0;1]BIN10 */
        filter_in_factor_max = (UInt16)DDS_M_MAX((SInt32)filter_assym_out,(SInt32)bary_tmp_out);

        /* [-16000,16000]BIN1 */
        filter_out = DDS_M_FILTER_LP1_S16_INIT(&vssp_f712231_filter_str,
                                               sat_out);    /* [-16000,16000]BIN1 */
    }

    /* [-16000,16000]BIN1 */
    switch_in_1 = DDS_M_MAX((SInt32)filter_out,(SInt32)vsctl_tqwhlptmaxnotctla_par);
    switch_in_2 = DDS_M_MIN((SInt32)filter_out,(SInt32)vsctl_tqwhlptminnotctla_par);

    if(VSSP_VSCTL_STCTL_TQWHLPTMAX_CONTROLE != (UInt32)vssp_stctl_tqwhlptmax_loc)
    {
        VSCtl_tqWhlPTMaxReqCll      = (SInt16)(11000 * BIN1);
        VSCtl_tqWhlPTMaxReqRaw      = (SInt16)(11000 * BIN1);
        VSCtl_tiFil_tqWhlMax        = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqWhlMaxRaw1    = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqWhlMaxRaw2    = (UInt16)(1 * BIN10);
        VSCtl_tiFil_tqWhlMaxRaw3    = (UInt16)(1 * BIN10);
    }
    else    /* VSSP_VSCTL_STCTL_TQWHLPTMAX_CONTROLE == VSCtl_stCtl_tqWhlPTMax */
    {
        if(VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_HAUT == (UInt32)vsctl_sttqwhlptcutoffreqprev_loc)
        {
            vssph_temp = switch_in_1;
        }
        else if(VSSP_VSCTL_STTQWHLPTCUTOFFREQ_PILOTAGE_BAS == (UInt32)vsctl_sttqwhlptcutoffreqprev_loc)
        {
            vssph_temp = switch_in_2;
        }
        else  /* VSCtl_stTqWhlPTCutOffReqPrev == VSSP_VSCTL_STTQWHLPTCUTOFFREQ_ARRET_INDETERMINE */
        {
            vssph_temp = (SInt32)filter_out;
        }

        /* [-4000,11000]BIN1 = MAX ( [-4000,11000]BIN1  ;  [-4000,11000]BIN1) */
        VSCtl_tqWhlPTMaxReqCll = (SInt16)DDS_M_LIMIT(vssph_temp,
                                                     -VSSP_4000_BIN1,
                                                     VSSP_11000_BIN1);

        /* [-4000;11000]BIN1 */
        VSCtl_tqWhlPTMaxReqRaw = (SInt16)DDS_M_LIMIT((SInt32)sat_out,
                                                     -VSSP_4000_BIN1,
                                                     VSSP_11000_BIN1);

        /* [0;1]DEC */
        VSCtl_tiFil_tqWhlMax = filter_in_factor_max;
        VSCtl_tiFil_tqWhlMaxRaw1 = (UInt16)filter_assym_out;
        VSCtl_tiFil_tqWhlMaxRaw2 = (UInt16)bary_tmp_out;
        VSCtl_tiFil_tqWhlMaxRaw3 = map_out;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F712232_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Ouverte
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSSP_F712232_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Ouverte(
                                                 SInt16 vsctl_tqwhlptprecovscminreq_par, /* BIN1 */
                                                 SInt16 vsctl_tqwhlptprecovsctlreq_par, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlptmaxreq_ptr /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.17.3 */
    SInt32 div_out;
    SInt32 switch_in_2;
    SInt32 switch_in_3;
    SInt32 vsctl_tqwhlptmaxreq_unlim;
    SInt16 vsctl_tqwhlptmaxreq_loc;
    UInt16 vsctl_tifiltqwhlptmaxreq_loc;

    vsctl_tifiltqwhlptmaxreq_loc = VSCtl_tiFiltqWhlPTMaxReq;

    if((UInt32)vssp_f712232_switch_out_dly_init != (UInt32)DDS_TRUE)
    {
        vssp_f712232_switch_out_dly_init = DDS_TRUE;
        vssp_f712232_switch_out_dly = VSCtl_tqWhlPTMaxReqDly;
    }
    else
    {
        /* Nothing to do */
    }

    if(  (VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_L == (UInt32)vssp_stctl_tqwhlptmax_loc)
       ||(VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_R == (UInt32)vssp_stctl_tqwhlptmax_loc))
    {
        if(0 == ((SInt32)vsctl_tqwhlptprecovsctlreq_par - (SInt32)vssp_f712232_switch_out_dly))          /* [-32000,32000]BIN1 */
        {
            div_out = 0 * BIN1; /* Middle value */
        }
        else if(0 == (UInt32)vsctl_tifiltqwhlptmaxreq_loc)  /* [0;65535]DEC0 */
        {
            if(((SInt32)vsctl_tqwhlptprecovsctlreq_par - (SInt32)vssp_f712232_switch_out_dly) > 0)
            {
                div_out = 11000 * BIN1;     /* Max positive value */
            }
            else
            {
                div_out = -4000 * BIN1; /* Max negative value */
            }
        }
        else
        {
            /*  [-32000;32000]BIN1 / [0;65535]DEC0 */
            div_out = ((SInt32)vsctl_tqwhlptprecovsctlreq_par - (SInt32)vssp_f712232_switch_out_dly) / (SInt32)vsctl_tifiltqwhlptmaxreq_loc;
        }

        if((UInt32)TRUE == (UInt32)VSCtl_bAcvTqWhlPTMaxReqSat_C)
        {
            /* BIN1 */
            switch_in_2 = DDS_M_MAX(div_out, (SInt32)VSCtl_tqErrSTra_tqWhlMaxVSCtl_C) + (SInt32)vssp_f712232_switch_out_dly;
            /* BIN1 */
            switch_in_3 = DDS_M_MAX(div_out, (SInt32)VSCtl_tqErrFTra_tqWhlMaxVSCtl_C) + (SInt32)vssp_f712232_switch_out_dly;
        }
        else
        {
            /* [-16000;27000]BIN1 = [0;11000]BIN1  + [-16000;16000]BIN1 */
            switch_in_2 = (SInt32)VSCtl_tqErrSTra_tqWhlMaxVSCtl_C + (SInt32)vssp_f712232_switch_out_dly;
            /* [-16000;27000]BIN1 = [0;11000]BIN1  + [-16000;16000]BIN1 */
            switch_in_3 = (SInt32)VSCtl_tqErrFTra_tqWhlMaxVSCtl_C + (SInt32)vssp_f712232_switch_out_dly;
        }
    }

    switch((UInt32)VSCtl_stCtl_tqWhlPTMax)
    {
        case (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_ARRET:
            vssp_f712232_switch_out_dly = (SInt16)(11000 * BIN1);
            vsctl_tqwhlptmaxreq_loc = (SInt16)(11000 * BIN1);
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_CONTROLE:
            /* In this case, MIN block is useless because second value is lesser or equal to 11000 */
            vssp_f712232_switch_out_dly = VSCtl_tqWhlPTMaxReqCll;
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f712232_switch_out_dly,(SInt32)vsctl_tqwhlptprecovscminreq_par);
            vsctl_tqwhlptmaxreq_loc  = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptmaxreq_unlim,
                                                    -VSSP_4000_BIN1,
                                                    VSSP_11000_BIN1);
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_L:
/* <PRQA_COMMENT><3353> Variable switch_in_2 is set in previous if test </3353></PRQA_COMMENT> */
            vssp_f712232_switch_out_dly = (SInt16)DDS_M_MIN(VSSP_11000_BIN1, switch_in_2);
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f712232_switch_out_dly,(SInt32)vsctl_tqwhlptprecovscminreq_par);
            vsctl_tqwhlptmaxreq_loc  = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptmaxreq_unlim,
                                                    -VSSP_4000_BIN1,
                                                    VSSP_11000_BIN1);
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_R:
/* <PRQA_COMMENT><3353> Variable switch_in_3 is set in previous if test </3353></PRQA_COMMENT> */
            vssp_f712232_switch_out_dly = (SInt16)DDS_M_MIN(VSSP_11000_BIN1, switch_in_3);
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f712232_switch_out_dly,(SInt32)vsctl_tqwhlptprecovscminreq_par);
            vsctl_tqwhlptmaxreq_loc  = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptmaxreq_unlim,
                                                    -VSSP_4000_BIN1,
                                                    VSSP_11000_BIN1);
            break;

        case (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_INIT:
            vssp_f712232_switch_out_dly = (SInt16)DDS_M_MIN(VSSP_11000_BIN1, (SInt32)VSCtl_tqWhlPTMaxReqDly);
            vsctl_tqwhlptmaxreq_unlim = DDS_M_MAX((SInt32)vssp_f712232_switch_out_dly,(SInt32)vsctl_tqwhlptprecovscminreq_par);
            vsctl_tqwhlptmaxreq_loc  = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptmaxreq_unlim,
                                                    -VSSP_4000_BIN1,
                                                    VSSP_11000_BIN1);
            break;

        default:
            vssp_f712232_switch_out_dly = (SInt16)(11000 * BIN1);
            vsctl_tqwhlptmaxreq_loc = (SInt16)(11000 * BIN1);
            break;
    }

    *vsctl_tqwhlptmaxreq_ptr = vsctl_tqwhlptmaxreq_loc;
}

/*******************************************************************************
*
* Function Name : VSSP_F71225_Determiner_Position_Pedale_Accelerateur_Gmp_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71225_Determiner_Position_Pedale_Accelerateur_Gmp_Max(
                                                 UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 SInt16 VSCtl_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTMaxReq_swc_in, /* BIN1 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMax_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.19.1 */
    UInt32 vssp_table_max_out;
    UInt32 vssp_table_min_out;
    UInt32 vssp_map_out;
    UInt16 vssp_filter_out;
    SInt32 vssp_svalue;
    UInt32 vssp_uvalue;

    vssp_stctl_tqwhlptmax_loc = VSCtl_stCtl_tqWhlPTMax;

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqWhlPTMaxReq_swc_in - (SInt32)VSCtl_tqWhlPTDrvMinReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    /* BIN7:[0;100]% */
    vssp_table_max_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPPTSATMAX_T_APM[1],(SInt16)vssp_svalue);

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = (SInt32)VSCtl_tqWhlPTDrvMaxReq_swc_in - (SInt32)VSCtl_tqWhlPTMaxReq_swc_in;
    vssp_svalue = DDS_M_LIMIT(vssp_svalue,-VSSP_16000_BIN1,VSSP_16000_BIN1);
    /* BIN7:[0;100]% */
    vssp_table_min_out = (UInt32)DDS_M_MAP2D_SU16(&VSCTL_RACCPPTSATMIN_T_APM[1],(SInt16)vssp_svalue);

    /* BIN1:[-16000;16000]N.m */
    vssp_svalue = DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPTMaxReq_swc_in,
                                      (SInt32)VSCtl_tqWhlPTDrvMinReq_swc_in,
                                      (SInt32)VSCtl_tqWhlPTDrvMaxReq_swc_in);

    /* BIN7:[0;100]% */
    vssp_map_out = (UInt32)DDS_M_MAP3D_SUU16(&VSCTL_RACCPPTMAX_M_APM,(SInt16)vssp_svalue,VSCtl_spdVeh_swc_in);

    if((UInt32)VSCtl_bAcvFil_tqWhlPTMax != (UInt32)DDS_FALSE)
    {
        /* BIN7:[0;100]% */
        vssp_uvalue = DDS_M_SATURATION_V2(vssp_map_out,vssp_table_min_out,vssp_table_max_out);
        vssp_filter_out = DDS_M_FILTER_LP1_U16(&vssp_f71225_filter_str, (UInt16)vssp_uvalue, VSCtl_tiFil_rAccPPTMax_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vssp_f71225_filter_str, (UInt16)(100 * BIN7));
    }


    if(  ((UInt32)vssp_stctl_tqwhlptmax_loc == (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_CONTROLE)
       ||((UInt32)vssp_stctl_tqwhlptmax_loc == (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_L)
       ||((UInt32)vssp_stctl_tqwhlptmax_loc == (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_TRANS_R)
       ||((UInt32)vssp_stctl_tqwhlptmax_loc == (UInt32)VSSP_VSCTL_STCTL_TQWHLPTMAX_INIT))
    {
        *VSCtl_rAccPPTMax_swc_out = vssp_filter_out;
    }
    else
    {
        *VSCtl_rAccPPTMax_swc_out = (UInt16)(100 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F71232_Determiner_Consigne_Limitation_Couple_Roue_Gmp_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F71232_Determiner_Consigne_Limitation_Couple_Roue_Gmp_Min(
                                                 SInt16 VSCtl_tqWhlMinSat_swc_in, /* BIN1 */
                                                 SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinSat_swc_out /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.50.0 */
    SInt32 vssp_svalue;
    SInt16 vssp_filter_out;
    UInt16 vsctl_titqwhlptminsattramax_loc;
    UInt8 vsctl_sttqwhlptminsat_loc;

    vsctl_titqwhlptminsattramax_loc = VSCtl_tiTqWhlPTMinSatTraMax;
    vsctl_sttqwhlptminsat_loc = VSCtl_stTqWhlPTMinSat;

    /* BIN1:[-4000;0]N.m */
    vssp_svalue = DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlMinSat_swc_in,-VSSP_4000_BIN1,VSSP_0);
    if((UInt32)VSCtl_bAcvFilTqWhlPTMinSat != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_S16(&vssp_f71232_filter_str, (SInt16)vssp_svalue, VSCtl_tiFil_tqWhlPTMinSat_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_S16_INIT(&vssp_f71232_filter_str, (SInt16)vssp_svalue);
    }

    if((UInt32)vsctl_sttqwhlptminsat_loc == (UInt32)VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
    {
        vssp_f71232_vsctl_tqwhlptminsat_dly = vssp_filter_out;
        *VSCtl_tqWhlPTMinSat_swc_out = vssp_filter_out;
    }
    else if((UInt32)vsctl_sttqwhlptminsat_loc == (UInt32)VSSP_VSCTL_STTQWHLPTMINSAT_TRANSITION)
    {
        if(((SInt32)vssp_f71232_vsctl_tqwhlptminsat_dly - (SInt32)VSCtl_tqWhlPTDrvMinReqRaw_swc_in) == 0)
        {
            vssp_svalue = (SInt32)VSCtl_tqErrTran_tqMinSat_C;
        }
        else if((UInt32)vsctl_titqwhlptminsattramax_loc == 0)
        {
            if(((SInt32)vssp_f71232_vsctl_tqwhlptminsat_dly - (SInt32)VSCtl_tqWhlPTDrvMinReqRaw_swc_in) > 0)
            {
                vssp_svalue = DDS_M_MAX((SInt32)VSCtl_tqErrTran_tqMinSat_C,VSSP_11000_BIN1);
            }
            else
            {
                vssp_svalue = (SInt32)VSCtl_tqErrTran_tqMinSat_C;
            }
        }
        else
        {
            vssp_svalue =   ((SInt32)vssp_f71232_vsctl_tqwhlptminsat_dly - (SInt32)VSCtl_tqWhlPTDrvMinReqRaw_swc_in)
                          / (SInt32)vsctl_titqwhlptminsattramax_loc;
            vssp_svalue = DDS_M_MAX((SInt32)VSCtl_tqErrTran_tqMinSat_C,vssp_svalue);
        }
        vssp_svalue = (SInt32)vssp_f71232_vsctl_tqwhlptminsat_dly - vssp_svalue;
        vssp_svalue = DDS_M_MAX((SInt32)-VSSP_4000_BIN1,vssp_svalue);
        vssp_svalue = DDS_M_MIN(vssp_svalue,VSSP_11000_BIN1);

        vssp_f71232_vsctl_tqwhlptminsat_dly = (SInt16)vssp_svalue;
        *VSCtl_tqWhlPTMinSat_swc_out = (SInt16)vssp_svalue;
    }
    else
    {
        vssp_f71232_vsctl_tqwhlptminsat_dly = (SInt16)(-4000 * BIN1);
        *VSCtl_tqWhlPTMinSat_swc_out = (SInt16)(-4000 * BIN1);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Control_Wheel_Gmp1_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp1_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMax_swc_out, /* BIN7 */
                                                      CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccPPTMin_swc_out, /* BIN7 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxReq_swc_out, /* BIN1 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinReq_swc_out, /* BIN1 */
                                                      CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinSat_swc_out /* BIN1 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_rAccPPTMax_swc_out = (UInt16)(100 * BIN7);
    *VSCtl_rAccPPTMin_swc_out = (UInt16)(0 * BIN7);
    *VSCtl_tqWhlPTMaxReq_swc_out = (SInt16)(11000 * BIN1);
    *VSCtl_tqWhlPTMinReq_swc_out = (SInt16)(-4000 * BIN1);
    *VSCtl_tqWhlPTMinSat_swc_out = (SInt16)(-4000 * BIN1);

    VSCtl_tqWhlPTMaxReqDly = VSCtl_tqWhlPTMaxReqDly_NV;

    /* ---- Init Global Datas ---- */
    VSCtl_tiFil_tqWhlMax = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMaxRaw1 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMaxRaw2 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMaxRaw3 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMin = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMinRaw1 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMinRaw2 = (UInt16)(1 * BIN10);
    VSCtl_tiFil_tqWhlMinRaw3 = (UInt16)(1 * BIN10);
    VSCtl_tqWhlPTMaxReqCll = (SInt16)(11000 * BIN1);
    VSCtl_tqWhlPTMaxReqRaw = (SInt16)(11000 * BIN1);
    VSCtl_tqWhlPTMinReqRaw1 = (SInt16)(-4000 * BIN1);
    VSCtl_tqWhlPTMinReqRaw2 = (SInt16)(-4000 * BIN1);

    vssp_stctl_tqwhlptmax_loc = VSSP_VSCTL_STCTL_TQWHLPTMAX_INIT;

    /* ---- VSSP_F71212_Determiner_Consigne_Couple_Roue_Gmp_Min ---- */
    DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f71212_filter_assym_str, 0);
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f71212_filter_str, 0);

    /* ---- VSSP_F71214_Determiner_Position_Pedale_Accelerateur_Gmp_Min ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f71214_filter_str, 0);

    /* ---- VSSP_F71221_Determiner_Consigne_Couple_Roue_Gmp_Max_Init ---- */

    /* ---- VSSP_F71223_Determiner_Consigne_Couple_Roue_Gmp_Max ---- */

    /* ---- VSSP_F712231_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Fermee ---- */
    DDS_M_FILTER_LP1_ASSYM_S16_INIT(&vssp_f712231_filter_assym_str, 0);
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f712231_filter_str, 0);

    /* ---- VSSP_F712232_Determiner_Consigne_Couple_Roue_Gmp_Max_Boucle_Ouverte ---- */
    vssp_f712232_switch_out_dly = 0;
    vssp_f712232_switch_out_dly_init = DDS_FALSE;

    /* ---- VSSP_F71225_Determiner_Position_Pedale_Accelerateur_Gmp_Max ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f71225_filter_str, 0);

    /* ---- VSSP_F71232_Determiner_Consigne_Limitation_Couple_Roue_Gmp_Min ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vssp_f71232_filter_str, 0);
    vssp_f71232_vsctl_tqwhlptminsat_dly = (SInt16)(-4000 * BIN1);
}

/*******************************************************************************
*
* Function Name : VSSP_Control_Wheel_Gmp1_Sl_Cinit
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Control_Wheel_Gmp1_Sl_Cinit(void)
{
    VSCtl_tqWhlPTMaxReqDly_NV = 11000 * BIN1;
}

#define VSSP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSSp_MemMap.h"

