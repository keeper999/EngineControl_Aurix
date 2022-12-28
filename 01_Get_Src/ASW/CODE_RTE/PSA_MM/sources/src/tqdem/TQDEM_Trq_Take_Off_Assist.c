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
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Trq_Take_Off_Assist.c
* Version int :/main/L04_01/4 Date: 17/7/2012 15 h 48 m User:posmyk 
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_012_IMPL1
*    comments :correct FDS A0204587 / ALTIS 1718332
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 11/7/2012 11 h 18 m User:lemort 
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_012_IMPL1
*    comments :correct FDS A0204587 / ALTIS 1718332
* Version int :/main/L04_01/3 Date: 15/9/2011 10 h 20 m User:meme
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_011_IMPL1
*    comments :Correct FDS A0202653
* Version dev :\main\branch_moisan_module_dev\1 Date: 12/9/2011 11 h 56 m User:moisan
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_011_IMPL1
*    comments :Correct FDS A0202653
* Version int :/main/L04_01/2 Date: 11/3/2011 9 h 41 m User:esnault
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_010_IMPL1
*    comments :Correct fail code (PSTR overflow on typecasting)
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 11/3/2011 9 h 29 m User:moisan
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_010_IMPL1
*    comments :Correct fail code (PSTR overflow on typecasting)
* Version int :/main/L04_01/1 Date: 10/3/2011 11 h 46 m User:esnault
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_010_IMPL1
*    comments :correct code for TqDem 11.1
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 9/3/2011 14 h 51 m User:moisan
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_010_IMPL1
*    comments :correct code for TqDem 11.1
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 1/3/2011 14 h 28 m User:moisan
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_010_IMPL1
*    comments :Update code and model for "tqdem_tqefcnregtakeoffeco" and " tqdem_tqefcnregtakeoffnorm"
*    comments :which become Input/Output (not irv any more)
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/3/2011 14 h 10 m User:moisan
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L04_010_IMPL1
*    comments :Update code and model for "tqdem_tqefcnregtakeoffeco" and " tqdem_tqefcnregtakeoffnorm"
*    comments :which become Input/Output (not irv any more)
* Version int :/main/L03_01/2 Date: 8/10/2010 16 h 32 m User:meme
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_011_IMPL2
*    comments :new file version for new CQ file
* Version dev :\main\branch_lemort_dev_tqdem\3 Date: 8/10/2010 14 h 10 m User:lemort
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_011_IMPL2
*    comments :new file version for new CQ file
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 6/10/2010 11 h 36 m User:lemort
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_011_IMPL2
*    comments :corrections after UT
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 1/10/2010 10 h 24 m User:lemort
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_011_IMPL1
*    comments :debug after UT
* Version int :/main/L03_01/1 Date: 1/9/2010 14 h 13 m User:esnault
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 20/7/2010 14 h 12 m User:lemort
*    TWK_model:TQDEM_Trq_Take_Off_Assist_L03_010_IMPL1
*    comments :dev TqDem e6
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

#define TQDEM_10_SIZE                         10
#define TQDEM_5_SIZE                          5
#define TQDEM_7_SIZE                          7
#define TQDEM_8_SIZE                          8
#define TQDEM_9_SIZE                          9

#define TQDEM_FAC_0_01_BIN7         ((UInt32)1)
#define TQDEM_FAC_1_BIN7            ((UInt32)1 * BIN7)
#define TQDEM_FAC_2_BIN7            ((UInt32)2 * BIN7)

#define TQDEM_FAC_0_01_DEC2         ((UInt32)1)
#define TQDEM_FAC_2_DEC2            ((UInt32)2 * DEC2)

#define TQDEM_SCHEDULING                      10

#define TQDEM_PI_BIN14              (UInt32)51472       /* Pi * BIN14 = Pi * 16384 = 51472 */

#define TQDEM_POS_2000_BIN4                   (SInt32)(2000 * BIN4)
#define TQDEM_NEG_2000_BIN4                   (SInt32)(-2000 * BIN4)

#define TQDEM_POS_2000_BIN10                   (SInt32)(2000 * BIN10)
#define TQDEM_NEG_2000_BIN10                   (SInt32)(-2000 * BIN10)

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
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nOffNEngReq_C = (CONST(UInt16, AUTOMATIC))(10 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nThdAcvLimNOpm_C = (CONST(UInt16, AUTOMATIC))(5000 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nThdDeacLimN_C = (CONST(UInt16, AUTOMATIC))(5900 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPThdAcvTakeOff_C = (CONST(UInt16, AUTOMATIC))(0.5 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPThdDeacLimN_C = (CONST(UInt16, AUTOMATIC))(10 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_tiTranNRegProtCluPOff_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_tiTranNRegProtCluPOn_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_tqOffSetLimN_C = (CONST(UInt16, AUTOMATIC))(50 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facDirNReqLimN_C = (CONST(UInt16, AUTOMATIC))(0.1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facDirTakeOffRvsSel_C = (CONST(UInt16, AUTOMATIC))(0.35 * BIN7);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bAcvNRegTakeOff_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bAuthLimTqNRegProt_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bDeacFacInt_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bInhLimN_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bProtCluPNRegTakeOff_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bRvsSel_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bTqCluSel_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_facFilGrdNEng_C = (CONST(UInt8, AUTOMATIC))(0.0078125 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_facFilNEngLimN_C = (CONST(UInt8, AUTOMATIC))(0.05 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_facFilNEngTakeOff_C = (CONST(UInt8, AUTOMATIC))(0.02 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_jEng_C = (CONST(UInt8, AUTOMATIC))(0.18 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_spdVehThdAcvTakeOff_C = (CONST(UInt8, AUTOMATIC))(10 * BIN0);
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQDEM_START_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqLimProtCluP_T[TQDEM_9_SIZE] = {
(SInt16)(510 * BIN4), (SInt16)(510 * BIN4), (SInt16)(510 * BIN4),
(SInt16)(510 * BIN4), (SInt16)(510 * BIN4), (SInt16)(510 * BIN4),
(SInt16)(510 * BIN4), (SInt16)(510 * BIN4), (SInt16)(510 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facDirNReqTakeOffX_A[TQDEM_9_SIZE] = {
(UInt16)(850 * BIN0), (UInt16)(950 * BIN0), (UInt16)(1050 * BIN0),
(UInt16)(1150 * BIN0), (UInt16)(1250 * BIN0), (UInt16)(1500 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(3000 * BIN0), (UInt16)(4000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facDirNReqTakeOff_M
[TQDEM_5_SIZE][TQDEM_9_SIZE] = {
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facDirTCoMes_T
[TQDEM_7_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facINReqLimN_T
[TQDEM_8_SIZE] = {
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.3 * DEC2),
(UInt16)(0.3 * DEC2), (UInt16)(0.3 * DEC2), (UInt16)(0.3 * DEC2),
(UInt16)(0.3 * DEC2), (UInt16)(0.3 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facPNReqLimN_T
[TQDEM_8_SIZE] = {
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facPNReqTakeOff_M
[TQDEM_5_SIZE][TQDEM_9_SIZE] = {
{
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.65 * BIN7), (UInt16)(0.8 * BIN7), (UInt16)(1.0 * BIN7),
(UInt16)(1.0 * BIN7), (UInt16)(1.2 * BIN7), (UInt16)(1.2 * BIN7) },
{
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.65 * BIN7), (UInt16)(0.8 * BIN7), (UInt16)(1.0 * BIN7),
(UInt16)(1.0 * BIN7), (UInt16)(1.2 * BIN7), (UInt16)(1.2 * BIN7) },
{
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.65 * BIN7), (UInt16)(0.8 * BIN7), (UInt16)(1.0 * BIN7),
(UInt16)(1.0 * BIN7), (UInt16)(1.2 * BIN7), (UInt16)(1.2 * BIN7) },
{
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.65 * BIN7), (UInt16)(0.8 * BIN7), (UInt16)(1.0 * BIN7),
(UInt16)(1.0 * BIN7), (UInt16)(1.2 * BIN7), (UInt16)(1.2 * BIN7) },
{
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.65 * BIN7), (UInt16)(0.8 * BIN7), (UInt16)(1.0 * BIN7),
(UInt16)(1.0 * BIN7), (UInt16)(1.2 * BIN7), (UInt16)(1.2 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facINReqTakeOff_M
[TQDEM_5_SIZE][TQDEM_9_SIZE] = {
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) },
{
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2),
(UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2), (UInt16)(0.35 * DEC2) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facITCoMes_T
[TQDEM_7_SIZE] = {
(UInt16)(0.5 * DEC2), (UInt16)(0.5 * DEC2), (UInt16)(0.75 * DEC2),
(UInt16)(1 * DEC2), (UInt16)(1 * DEC2), (UInt16)(1 * DEC2),
(UInt16)(1 * DEC2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facPTCoMes_T
[TQDEM_7_SIZE] = {
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.75 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngRegAccPX_A[TQDEM_10_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(1 * BIN7), (UInt16)(5 * BIN7),
(UInt16)(8 * BIN7), (UInt16)(10 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(30 * BIN7), (UInt16)(50 * BIN7),
(UInt16)(100 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngRegGearNb_A[TQDEM_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(7 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngRegNEngX_A[TQDEM_9_SIZE] = {
(UInt16)(850 * BIN0), (UInt16)(950 * BIN0), (UInt16)(1050 * BIN0),
(UInt16)(1150 * BIN0), (UInt16)(1250 * BIN0), (UInt16)(1500 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(3000 * BIN0), (UInt16)(4000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngRegSpdVehY_A[TQDEM_5_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(2 * BIN7),
(UInt16)(5 * BIN7), (UInt16)(10 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_nEngRegTCoMes_A[TQDEM_7_SIZE] = {
(SInt16)(-20 * BIN0), (SInt16)(-10 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(20 * BIN0), (SInt16)(40 * BIN0), (SInt16)(60 * BIN0),
(SInt16)(90 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngReqTakeOffProt_M
[TQDEM_7_SIZE][TQDEM_10_SIZE] = {
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngReqTakeOffY_A[TQDEM_7_SIZE] = {
(UInt16)(700 * BIN0), (UInt16)(800 * BIN0), (UInt16)(900 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1250 * BIN0), (UInt16)(1500 * BIN0),
(UInt16)(2000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngReqTakeOff_M
[TQDEM_7_SIZE][TQDEM_10_SIZE] = {
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(200 * BIN0), (UInt16)(300 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(500 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(5000 * BIN0) }
};

#define TQDEM_STOP_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQDEM_START_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facdirtcomes_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facinreqlimn_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facitcomes_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facpnreqlimn_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facptcomes_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_tqlimprotclup_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_facdirnreqtakeoff_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_facinreqtakeoff_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_facpnreqtakeoff_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_nengreqtakeoff_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_nengreqtakeoffprot_m_sav;
STATIC VAR(t_dds_m_soft_trans_delta_u32_type, AUTOMATIC) tqdem_soft_trans_struct;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqdem_f02_01_02_02_edge_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_f02_02_filter1;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_f02_02_filter2;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) tqdem_f03_01_filter_str;
#define TQDEM_STOP_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"

/* 32-bits variable definition */
#define TQDEM_START_SEC_VAR_32BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqdem_trq_prev_time;
STATIC VAR(UInt32, AUTOMATIC) tqdem_trq_delta_time;
STATIC VAR(SInt32, AUTOMATIC) tqdem_tqckefcnregi_mp_save;
#define TQDEM_STOP_SEC_VAR_32BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_VAR_8BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqdem_f02_02_initialised;
STATIC VAR(UInt8, AUTOMATIC) tqdem_f03_01_initialised;
STATIC VAR(UInt8, AUTOMATIC) tqdem_f03_02_initialised;
STATIC VAR(UInt8, AUTOMATIC) tqdem_f02_01_01_01_01_init;
#define TQDEM_STOP_SEC_VAR_8BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_32BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqDem_agvGrdNEng; /* BIN7 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqDem_agvGrdNEngReq; /* BIN7 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqDem_agvGrdNEngReqFil; /* BIN7 */
_DDS_STATIC_ VAR(UInt32, AUTOMATIC) TqDem_agvNEngReq; /* BIN7 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_32BIT
#include "TqDem_MemMap.h"

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcNRegI_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcNRegP_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqEfcNRegCll;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqEfcNRegOpl;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqEfcNRegRaw;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqIniINReg;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqIniINRegLimN;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqIniINRegTakeOff;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqSatBackNReg;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqSatBackNRegLimN;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqSatBackNRegTakeOff;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facINReg; /* DEC3 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facINRegLimN; /* DEC3 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facINRegTakeOff; /* DEC3 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facPNReg; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facPNRegLimN; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facPNRegTakeOff; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_nEngOfsReq; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_nEngReqLimN; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_nEngReqTakeOff; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rTranLimNOut;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rTranNRegOut;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rTranTakeOffOut;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facDirNReq; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facDirNReqLimN; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facDirNReqTakeOff; /* BIN7 */

#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bAcvLimN;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bAcvLimNOpm;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bAcvNRegOpm;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bAcvTakeOffOpm;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bDeacLimN;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bDeacNReg;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bDeacTakeOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_facFilNEngLimN; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_facFilNEngTakeOff; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_jEng; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_facFilNEng; /* BIN7 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQDEM_START_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQDEM_FACDIRNREQTAKEOFF_M_APM = {
&tqdem_facdirnreqtakeoff_m_sav,
TQDEM_9_SIZE,
TQDEM_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facDirNReqTakeOffX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegSpdVehY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facDirNReqTakeOff_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQDEM_FACDIRTCOMES_T_APM = {
&tqdem_facdirtcomes_t_sav,
TQDEM_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegTCoMes_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facDirTCoMes_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQDEM_TQLIMPROTCLUP_T_APM = {
&tqdem_tqlimprotclup_t_sav,
TQDEM_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegNEngX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqLimProtCluP_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_FACINREQLIMN_T_APM = {
&tqdem_facinreqlimn_t_sav,
TQDEM_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegGearNb_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facINReqLimN_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_FACPNREQLIMN_T_APM = {
&tqdem_facpnreqlimn_t_sav,
TQDEM_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegGearNb_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facPNReqLimN_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQDEM_FACPNREQTAKEOFF_M_APM = {
&tqdem_facpnreqtakeoff_m_sav,
TQDEM_9_SIZE,
TQDEM_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegNEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegSpdVehY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facPNReqTakeOff_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQDEM_FACINREQTAKEOFF_M_APM = {
&tqdem_facinreqtakeoff_m_sav,
TQDEM_9_SIZE,
TQDEM_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegNEngX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegSpdVehY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facINReqTakeOff_M[0][0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQDEM_FACITCOMES_T_APM = {
&tqdem_facitcomes_t_sav,
TQDEM_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegTCoMes_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facITCoMes_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQDEM_FACPTCOMES_T_APM = {
&tqdem_facptcomes_t_sav,
TQDEM_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegTCoMes_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facPTCoMes_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQDEM_NENGREQTAKEOFFPROT_M_APM = {
&tqdem_nengreqtakeoffprot_m_sav,
TQDEM_10_SIZE,
TQDEM_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegAccPX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngReqTakeOffY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngReqTakeOffProt_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQDEM_NENGREQTAKEOFF_M_APM = {
&tqdem_nengreqtakeoff_m_sav,
TQDEM_10_SIZE,
TQDEM_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngRegAccPX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngReqTakeOffY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_nEngReqTakeOff_M[0][0]
};

#define TQDEM_STOP_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_01_01_Calcul_Consigne (UInt8 copt_brvscord_par,
                                                                UInt16 copt_nprimshaft_par,
                                                                SInt16 ext_tcomes_par,
                                                                UInt16 tqsys_ntaridl_par,
                                                                UInt16 veh_spdveh_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_01_01_Gestion_Mode_Protectemb (UInt16 tqsys_ntaridl_par,
                                                                        UInt8 copt_bacvprotclup_par,
                                                                        UInt16 accp_raccp_par,
                                                                        UInt16 tqdem_raccpsptmod_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_01_Calc_Traj_Cons_Deco (UInt16 tqsys_ntaridl_par,
                                                                    UInt8 copt_bacvprotclup_par,
                                                                    UInt16 accp_raccp_par,
                                                                    UInt16 tqdem_raccpsptmod_par,
                                                                    UInt8 copt_brvscord_par,
                                                                    UInt16 copt_nprimshaft_par,
                                                                    SInt16 ext_tcomes_par,
                                                                    UInt16 veh_spdveh_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_02_Activation_Deco (UInt8 frm_binhnregtakeoff_par,
                                                            UInt16 veh_spdveh_par,
                                                            UInt16 accp_raccp_par,
                                                            UInt8 copt_bacvprotclup_par,
                                                            UInt16 tqdem_rdrivtakeoff_par,
                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_03_Param_Regul (SInt16 ext_tcomes_par,
                                                    UInt16 eng_nckfil_par,
                                                    UInt16 veh_spdveh_par,
                                                    UInt8 copt_bacvprotclup_par,
                                                    SInt16 tqdem_tqckefc_par,
                                                    SInt16 englim_tqefcnregtakeofflim_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_03_Param_Regul_Limn (UInt8 copt_noegdgearcord_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 tqsys_tqidcairlimcordwires_par,
                                                            SInt16 tqdem_tqckefc_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_Nregdeco (SInt16 englim_tqefcnregtakeofflim_par,
                                                        SInt16 ext_tcomes_par,
                                                        SInt16 tqcmp_tqsumlosscmp_par,
                                                        SInt16 tqdem_tqckefc_par,
                                                        UInt16 accp_raccp_par,
                                                        UInt16 copt_nprimshaft_par,
                                                        UInt16 eng_nckfil_par,
                                                        UInt16 tqdem_raccpsptmod_par,
                                                        UInt16 tqdem_rdrivtakeoff_par,
                                                        UInt16 tqsys_ntaridl_par,
                                                        UInt16 veh_spdveh_par,
                                                        UInt8 copt_bacvprotclup_par,
                                                        UInt8 copt_brvscord_par,
                                                        UInt8 frm_binhnregtakeoff_par,
                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_01_Calc_Traj_Cons_Limn (UInt16 eslim_nlofucutoff_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_02_Activation_Limn (UInt8 tqsys_bengnonidl_par,
                                                            UInt16 eng_nckfil_par,
                                                            UInt16 accp_raccp_par,
                                                            UInt8 frm_binhregnlimn_par,
                                                            UInt8 eslim_bacvtrqlim_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_Acvnreglimn (UInt16 eslim_nlofucutoff_par,
                                                            UInt8 tqsys_bengnonidl_par,
                                                            UInt16 eng_nckfil_par,
                                                            UInt16 accp_raccp_par,
                                                            UInt8 frm_binhregnlimn_par,
                                                            UInt8 eslim_bacvtrqlim_par,
                                                            UInt8 copt_noegdgearcord_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 tqsys_tqidcairlimcordwires_par,
                                                            SInt16 tqdem_tqckefc_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_03_Coordination (CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_nengreq_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_Activation_Parametres (SInt16 englim_tqefcnregtakeofflim_par,
                                                                SInt16 ext_tcomes_par,
                                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                                SInt16 tqdem_tqckefc_par,
                                                                SInt16 tqsys_tqidcairlimcordwires_par,
                                                                UInt16 accp_raccp_par,
                                                                UInt16 copt_nprimshaft_par,
                                                                UInt16 eng_nckfil_par,
                                                                UInt16 eslim_nlofucutoff_par,
                                                                UInt16 tqdem_raccpsptmod_par,
                                                                UInt16 tqdem_rdrivtakeoff_par,
                                                                UInt16 tqsys_ntaridl_par,
                                                                UInt16 veh_spdveh_par,
                                                                UInt8 copt_bacvprotclup_par,
                                                                UInt8 copt_brvscord_par,
                                                                UInt8 copt_noegdgearcord_par,
                                                                UInt8 eslim_bacvtrqlim_par,
                                                                UInt8 frm_binhnregtakeoff_par,
                                                                UInt8 frm_binhregnlimn_par,
                                                                UInt8 tqsys_bengnonidl_par,
                                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_nengreq_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_Traitement_Regime (UInt16 ext_neng_par,
                                                            SInt16 treattenms_nckgrd_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_Pretraitement (UInt16 accp_raccp_par,
                                                UInt8 copt_bacvprotclup_par,
                                                UInt8 copt_brvscord_par,
                                                UInt8 copt_noegdgearcord_par,
                                                UInt16 copt_nprimshaft_par,
                                                UInt16 eng_nckfil_par,
                                                SInt16 englim_tqefcnregtakeofflim_par,
                                                UInt8 eslim_bacvtrqlim_par,
                                                UInt16 eslim_nlofucutoff_par,
                                                UInt16 ext_neng_par,
                                                SInt16 ext_tcomes_par,
                                                UInt8 frm_binhnregtakeoff_par,
                                                UInt8 frm_binhregnlimn_par,
                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                UInt16 tqdem_raccpsptmod_par,
                                                UInt16 tqdem_rdrivtakeoff_par,
                                                SInt16 tqdem_tqckefc_par,
                                                UInt8 tqsys_bengnonidl_par,
                                                UInt16 tqsys_ntaridl_par,
                                                SInt16 tqsys_tqidcairlimcordwires_par,
                                                SInt16 treattenms_nckgrd_par,
                                                UInt16 veh_spdveh_par,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr,
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_nengreq_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_01_Bo (SInt16 copt_tqmaxclu_par,
                                                SInt16 englim_tqefcnregtakeofflim_par,
                                                SInt16 tqcmp_tqsumlosscmp_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_02_Pi (void);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_Regulation (SInt16 copt_tqmaxclu_par,
                                                    SInt16 englim_tqefcnregtakeofflim_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F04_Couplelimn (SInt16 tqcmp_tqsumlosscmp_par,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqidclimnreg_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_Coupledeco (SInt16 englim_tqefcnregtakeofflim_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par,
                                                    UInt8 tqdem_bacvnregtakeoff_par,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqefcnregtakeoffeco_ptr,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqefcnregtakeoffnorm_ptr);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQDEM_Trq_Take_Off_Assist
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Trq_Take_Off_Assist(UInt16 AccP_rAccP_swc_in,
                                           UInt8 CoPt_bAcvProtCluP_swc_in,
                                           UInt8 CoPt_bRvsCord_swc_in,
                                           UInt16 CoPt_nPrimShaft_swc_in,
                                           UInt8 CoPt_noEgdGearCord_swc_in,
                                           SInt16 CoPt_tqMaxClu_swc_in,
                                           UInt8 ESLim_bAcvTrqLim_swc_in,
                                           UInt16 ESLim_nLoFuCutOff_swc_in,
                                           SInt16 EngLim_tqEfcNRegTakeOffLim_swc_in,
                                           UInt16 Eng_nCkFil_swc_in,
                                           UInt16 Ext_nEng_swc_in,
                                           SInt16 Ext_tCoMes_swc_in,
                                           UInt8 FRM_bInhNRegTakeOff_swc_in,
                                           UInt8 FRM_bInhRegNLimN_swc_in,
                                           SInt16 TqCmp_tqSumLossCmp_swc_in,
                                           UInt16 TqDem_rAccPSptMod_swc_in,
                                           UInt16 TqDem_rDrivTakeOff_swc_in,
                                           SInt16 TqDem_tqCkEfc_swc_in,
                                           UInt8 TqSys_bEngNOnIdl_swc_in,
                                           UInt16 TqSys_nTarIdl_swc_in,
                                           SInt16 TqSys_tqIdcAirLimCordWiRes_swc_in,
                                           SInt16 TreatTenms_nCkGrd_swc_in,
                                           UInt16 Veh_spdVeh_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffEco_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffNorm_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqIdcLimNReg_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bAcvNRegTakeOff_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_nEngReq_swc_out)
{
     /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.1.1 */

    UInt32 tqdem_trq_current_time = DDS_TQDEM_1MS_U32_TIME;
    tqdem_trq_delta_time = tqdem_trq_current_time - tqdem_trq_prev_time;
    tqdem_trq_delta_time = DDS_M_MIN(tqdem_trq_delta_time, (2 * TQDEM_SCHEDULING));

    tqdem_trq_prev_time = tqdem_trq_current_time;

    TQDEM_F02_Pretraitement(AccP_rAccP_swc_in,
                            CoPt_bAcvProtCluP_swc_in,
                            CoPt_bRvsCord_swc_in,
                            CoPt_noEgdGearCord_swc_in,
                            CoPt_nPrimShaft_swc_in,
                            Eng_nCkFil_swc_in,
                            EngLim_tqEfcNRegTakeOffLim_swc_in,
                            ESLim_bAcvTrqLim_swc_in,
                            ESLim_nLoFuCutOff_swc_in,
                            Ext_nEng_swc_in,
                            Ext_tCoMes_swc_in,
                            FRM_bInhNRegTakeOff_swc_in,
                            FRM_bInhRegNLimN_swc_in,
                            TqCmp_tqSumLossCmp_swc_in,
                            TqDem_rAccPSptMod_swc_in,
                            TqDem_rDrivTakeOff_swc_in,
                            TqDem_tqCkEfc_swc_in,
                            TqSys_bEngNOnIdl_swc_in,
                            TqSys_nTarIdl_swc_in,
                            TqSys_tqIdcAirLimCordWiRes_swc_in,
                            TreatTenms_nCkGrd_swc_in,
                            Veh_spdVeh_swc_in,
                            TqDem_bAcvNRegTakeOff_swc_out,
                            TqDem_nEngReq_swc_out);

    if((UInt32)DDS_FALSE != (UInt32)TqDem_bAcvNRegOpm)
    {
        TQDEM_F03_Regulation (CoPt_tqMaxClu_swc_in,
                                EngLim_tqEfcNRegTakeOffLim_swc_in,
                                TqCmp_tqSumLossCmp_swc_in);
    }

    TQDEM_F04_Couplelimn (TqCmp_tqSumLossCmp_swc_in,
                            TqDem_tqIdcLimNReg_swc_out);

    TQDEM_F05_Coupledeco (EngLim_tqEfcNRegTakeOffLim_swc_in,
                            TqCmp_tqSumLossCmp_swc_in,
                            *TqDem_bAcvNRegTakeOff_swc_out,
                            TqDem_tqEfcNRegTakeOffEco_swc_out,
                            TqDem_tqEfcNRegTakeOffNorm_swc_out);


}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_F02_Pretraitement
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_Pretraitement (UInt16 accp_raccp_par,
                                                UInt8 copt_bacvprotclup_par,
                                                UInt8 copt_brvscord_par,
                                                UInt8 copt_noegdgearcord_par,
                                                UInt16 copt_nprimshaft_par,
                                                UInt16 eng_nckfil_par,
                                                SInt16 englim_tqefcnregtakeofflim_par,
                                                UInt8 eslim_bacvtrqlim_par,
                                                UInt16 eslim_nlofucutoff_par,
                                                UInt16 ext_neng_par,
                                                SInt16 ext_tcomes_par,
                                                UInt8 frm_binhnregtakeoff_par,
                                                UInt8 frm_binhregnlimn_par,
                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                UInt16 tqdem_raccpsptmod_par,
                                                UInt16 tqdem_rdrivtakeoff_par,
                                                SInt16 tqdem_tqckefc_par,
                                                UInt8 tqsys_bengnonidl_par,
                                                UInt16 tqsys_ntaridl_par,
                                                SInt16 tqsys_tqidcairlimcordwires_par,
                                                SInt16 treattenms_nckgrd_par,
                                                UInt16 veh_spdveh_par,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr,
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_nengreq_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.2.1 */

    TQDEM_F02_01_Activation_Parametres( englim_tqefcnregtakeofflim_par,
                                        ext_tcomes_par,
                                        tqcmp_tqsumlosscmp_par,
                                        tqdem_tqckefc_par,
                                        tqsys_tqidcairlimcordwires_par,
                                        accp_raccp_par,
                                        copt_nprimshaft_par,
                                        eng_nckfil_par,
                                        eslim_nlofucutoff_par,
                                        tqdem_raccpsptmod_par,
                                        tqdem_rdrivtakeoff_par,
                                        tqsys_ntaridl_par,
                                        veh_spdveh_par,
                                        copt_bacvprotclup_par,
                                        copt_brvscord_par,
                                        copt_noegdgearcord_par,
                                        eslim_bacvtrqlim_par,
                                        frm_binhnregtakeoff_par,
                                        frm_binhregnlimn_par,
                                        tqsys_bengnonidl_par,
                                        tqdem_nengreq_ptr,
                                        tqdem_bacvnregtakeoff_ptr);

    TQDEM_F02_02_Traitement_Regime (ext_neng_par,
                                    treattenms_nckgrd_par);

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_Activation_Parametres
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_Activation_Parametres(SInt16 englim_tqefcnregtakeofflim_par,
                                                                SInt16 ext_tcomes_par,
                                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                                SInt16 tqdem_tqckefc_par,
                                                                SInt16 tqsys_tqidcairlimcordwires_par,
                                                                UInt16 accp_raccp_par,
                                                                UInt16 copt_nprimshaft_par,
                                                                UInt16 eng_nckfil_par,
                                                                UInt16 eslim_nlofucutoff_par,
                                                                UInt16 tqdem_raccpsptmod_par,
                                                                UInt16 tqdem_rdrivtakeoff_par,
                                                                UInt16 tqsys_ntaridl_par,
                                                                UInt16 veh_spdveh_par,
                                                                UInt8 copt_bacvprotclup_par,
                                                                UInt8 copt_brvscord_par,
                                                                UInt8 copt_noegdgearcord_par,
                                                                UInt8 eslim_bacvtrqlim_par,
                                                                UInt8 frm_binhnregtakeoff_par,
                                                                UInt8 frm_binhregnlimn_par,
                                                                UInt8 tqsys_bengnonidl_par,
                                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_nengreq_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.3.1 */

    TQDEM_F02_01_01_Nregdeco (  englim_tqefcnregtakeofflim_par,
                                ext_tcomes_par,
                                tqcmp_tqsumlosscmp_par,
                                tqdem_tqckefc_par,
                                accp_raccp_par,
                                copt_nprimshaft_par,
                                eng_nckfil_par,
                                tqdem_raccpsptmod_par,
                                tqdem_rdrivtakeoff_par,
                                tqsys_ntaridl_par,
                                veh_spdveh_par,
                                copt_bacvprotclup_par,
                                copt_brvscord_par,
                                frm_binhnregtakeoff_par,
                                tqdem_bacvnregtakeoff_ptr);

    TQDEM_F02_01_02_Acvnreglimn(eslim_nlofucutoff_par,
                                tqsys_bengnonidl_par,
                                eng_nckfil_par,
                                accp_raccp_par,
                                frm_binhregnlimn_par,
                                eslim_bacvtrqlim_par,
                                copt_noegdgearcord_par,
                                tqcmp_tqsumlosscmp_par,
                                tqsys_tqidcairlimcordwires_par,
                                tqdem_tqckefc_par);

    TQDEM_F02_01_03_Coordination (tqdem_nengreq_ptr);
}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_01_Nregdeco
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_Nregdeco (SInt16 englim_tqefcnregtakeofflim_par,
                                                        SInt16 ext_tcomes_par,
                                                        SInt16 tqcmp_tqsumlosscmp_par,
                                                        SInt16 tqdem_tqckefc_par,
                                                        UInt16 accp_raccp_par,
                                                        UInt16 copt_nprimshaft_par,
                                                        UInt16 eng_nckfil_par,
                                                        UInt16 tqdem_raccpsptmod_par,
                                                        UInt16 tqdem_rdrivtakeoff_par,
                                                        UInt16 tqsys_ntaridl_par,
                                                        UInt16 veh_spdveh_par,
                                                        UInt8 copt_bacvprotclup_par,
                                                        UInt8 copt_brvscord_par,
                                                        UInt8 frm_binhnregtakeoff_par,
                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.4.1 */

    TQDEM_F02_01_01_01_Calc_Traj_Cons_Deco (tqsys_ntaridl_par,
                                            copt_bacvprotclup_par,
                                            accp_raccp_par,
                                            tqdem_raccpsptmod_par,
                                            copt_brvscord_par,
                                            copt_nprimshaft_par,
                                            ext_tcomes_par,
                                            veh_spdveh_par);

    TQDEM_F02_01_01_02_Activation_Deco (frm_binhnregtakeoff_par,
                                        veh_spdveh_par,
                                        accp_raccp_par,
                                        copt_bacvprotclup_par,
                                        tqdem_rdrivtakeoff_par,
                                        tqdem_bacvnregtakeoff_ptr);

    TQDEM_F02_01_01_03_Param_Regul (ext_tcomes_par,
                                    eng_nckfil_par,
                                    veh_spdveh_par,
                                    copt_bacvprotclup_par,
                                    tqdem_tqckefc_par,
                                    englim_tqefcnregtakeofflim_par,
                                    tqcmp_tqsumlosscmp_par);

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_01_01_Calc_Traj_Cons_Deco
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_01_Calc_Traj_Cons_Deco (UInt16 tqsys_ntaridl_par,
                                                                    UInt8 copt_bacvprotclup_par,
                                                                    UInt16 accp_raccp_par,
                                                                    UInt16 tqdem_raccpsptmod_par,
                                                                    UInt8 copt_brvscord_par,
                                                                    UInt16 copt_nprimshaft_par,
                                                                    SInt16 ext_tcomes_par,
                                                                    UInt16 veh_spdveh_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.5.0 */

    TQDEM_F02_01_01_01_01_Gestion_Mode_Protectemb (tqsys_ntaridl_par,
                                                    copt_bacvprotclup_par,
                                                    accp_raccp_par,
                                                    tqdem_raccpsptmod_par);

    TQDEM_F02_01_01_01_01_Calcul_Consigne (copt_brvscord_par,
                                            copt_nprimshaft_par,
                                            ext_tcomes_par,
                                            tqsys_ntaridl_par,
                                            veh_spdveh_par);

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_01_01_01_Calcul_Consigne
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_01_01_Calcul_Consigne (
                                                                UInt8 copt_brvscord_par,
/* <PRQA_COMMENT><3206> Terminator in specification </3206></PRQA_COMMENT> */
                                                                UInt16 copt_nprimshaft_par,
                                                                SInt16 ext_tcomes_par,
                                                                UInt16 tqsys_ntaridl_par,
                                                                UInt16 veh_spdveh_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.20.0 */
    UInt16 tqdem_facdirtcomes_temp;
    UInt32 tqdem_facdirnreqtakeoff_temp;
    UInt32 tqdem_nengreqtakeoff_temp;

    tqdem_nengreqtakeoff_temp = (UInt32)TqDem_nEngOfsReq + ((UInt32)tqsys_ntaridl_par / BIN2);
    /* BIN0 = BIN0 + (BIN2 / BIN2) */
    TqDem_nEngReqTakeOff = (UInt16)DDS_M_MIN(tqdem_nengreqtakeoff_temp,7500);

    /* [0;3] BIN7 */
    tqdem_facdirtcomes_temp = DDS_M_MAP2D_SU16(&TQDEM_FACDIRTCOMES_T_APM,
                                                ext_tcomes_par);
    /* [0.01;2] DEC2 */
    tqdem_facdirnreqtakeoff_temp = (UInt32)DDS_M_MAP3D_U16(&TQDEM_FACDIRNREQTAKEOFF_M_APM,
                                                            TqDem_nEngReqTakeOff,
                                                            veh_spdveh_par);

    if( ((UInt32)DDS_FALSE != (UInt32)TqDem_bRvsSel_C)
     && ((UInt32)DDS_FALSE != (UInt32)copt_brvscord_par) )
    {
        TqDem_facDirNReqTakeOff = TqDem_facDirTakeOffRvsSel_C;
    }
    else
    {
        /* [0;6] BIN7 = [0;3] BIN7 * [0.01;2] DEC2 / DEC2 */
        tqdem_facdirnreqtakeoff_temp = ((UInt32)tqdem_facdirtcomes_temp  * tqdem_facdirnreqtakeoff_temp) / DEC2;
        TqDem_facDirNReqTakeOff = (UInt16)DDS_M_LIMIT(tqdem_facdirnreqtakeoff_temp,
                                                     TQDEM_FAC_0_01_BIN7,
                                                     TQDEM_FAC_2_BIN7);
    }
}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_01_01_01_Gestion_Mode_Protectemb
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_01_01_Gestion_Mode_Protectemb (UInt16 tqsys_ntaridl_par,
                                                                        UInt8 copt_bacvprotclup_par,
                                                                        UInt16 accp_raccp_par,
                                                                        UInt16 tqdem_raccpsptmod_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.19.0 */

    UInt16 tqdem_in1;
    UInt16 tqdem_in2;
    UInt16 tqsys_ntaridl_bin0;
    UInt8  soft_enable;

    /* BIN0 = BIN2 / BIN2 */
    tqsys_ntaridl_bin0 = (UInt16)((UInt32)tqsys_ntaridl_par / BIN2);

    tqdem_in1 = DDS_M_MAP3D_U16(&TQDEM_NENGREQTAKEOFF_M_APM,
                                tqdem_raccpsptmod_par,
                                tqsys_ntaridl_bin0);


    tqdem_in2 = DDS_M_MAP3D_U16(&TQDEM_NENGREQTAKEOFFPROT_M_APM,
                                accp_raccp_par,
                                tqsys_ntaridl_bin0);

    if((UInt32)copt_bacvprotclup_par == (UInt32)DDS_FALSE)
    {
        soft_enable = 1;
    }
    else
    {
        soft_enable = 0;
    }

    if((UInt32)DDS_FALSE == (UInt32)tqdem_f02_01_01_01_01_init)
    {
        TqDem_nEngOfsReq = (UInt16)DDS_M_SOFT_TRANS_DELTA_U32_INIT(soft_enable,
                                                            (UInt32)tqdem_in1,
                                                            (UInt32)tqdem_in2,
                                                            DDS_NULL_PTR,
                                                            &tqdem_soft_trans_struct );
        tqdem_f02_01_01_01_01_init = DDS_TRUE;
    }
    else
    {

        TqDem_nEngOfsReq = (UInt16)DDS_M_SOFT_TRANS_DELTA_U32(soft_enable,
                                                            (UInt32)tqdem_in1,
                                                            (UInt32)tqdem_in2,
                                                            tqdem_trq_delta_time,
                                                            ((UInt32)TqDem_tiTranNRegProtCluPOff_C * DEC1),
                                                            ((UInt32)TqDem_tiTranNRegProtCluPOn_C * DEC1),
                                                            &tqdem_soft_trans_struct );
    }

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_01_02_Activation_Deco
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_02_Activation_Deco (UInt8 frm_binhnregtakeoff_par,
                                                            UInt16 veh_spdveh_par,
                                                            UInt16 accp_raccp_par,
                                                            UInt8 copt_bacvprotclup_par,
                                                            UInt16 tqdem_rdrivtakeoff_par,
                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bacvnregtakeoff_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.6.1 */

    TqDem_rTranTakeOffOut = tqdem_rdrivtakeoff_par;

    TqDem_facFilNEngTakeOff = TqDem_facFilNEngTakeOff_C;

    if( ((UInt32)DDS_FALSE == (UInt32)frm_binhnregtakeoff_par)
    &&  ((UInt32)DDS_FALSE != (UInt32)TqDem_bAcvNRegTakeOff_C)
    &&  (  ((UInt32)tqdem_rdrivtakeoff_par < (1 * BIN10))
        || ((UInt32)veh_spdveh_par <= ((UInt32)TqDem_spdVehThdAcvTakeOff_C * BIN7)) ) )
    {
        TqDem_bAcvTakeOffOpm = DDS_TRUE;

        if( ((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPThdAcvTakeOff_C)
        &&  ( ((UInt32)DDS_FALSE != (UInt32)TqDem_bProtCluPNRegTakeOff_C)
            ||((UInt32)DDS_FALSE == (UInt32)copt_bacvprotclup_par) ) )
        {
            *tqdem_bacvnregtakeoff_ptr = DDS_TRUE;
            TqDem_bDeacTakeOff = DDS_FALSE;
        }
        else
        {
            *tqdem_bacvnregtakeoff_ptr = DDS_FALSE;
            TqDem_bDeacTakeOff = DDS_TRUE;
        }

    }
    else
    {
        TqDem_bAcvTakeOffOpm = DDS_FALSE;
        *tqdem_bacvnregtakeoff_ptr = DDS_FALSE;
        TqDem_bDeacTakeOff = DDS_TRUE;
    }

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_01_03_Param_Regul
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_01_03_Param_Regul (SInt16 ext_tcomes_par,
                                                    UInt16 eng_nckfil_par,
                                                    UInt16 veh_spdveh_par,
                                                    UInt8 copt_bacvprotclup_par,
                                                    SInt16 tqdem_tqckefc_par,
                                                    SInt16 englim_tqefcnregtakeofflim_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.7.1 */

    UInt16 tqdem_temp1;
    UInt16 tqdem_temp2;
    SInt16 tqdem_temp3;
    UInt32 tqdem_result;
    UInt16 eng_nckfil_bin0;
    SInt32 tqcmp_tqsumlosscmp_invert;

    TqDem_tqIniINRegTakeOff = 0;

    eng_nckfil_bin0 = (UInt16)((UInt32)eng_nckfil_par / BIN2);

    /* [0;3] BIN7 */
    tqdem_temp1 = DDS_M_MAP2D_SU16(&TQDEM_FACPTCOMES_T_APM,
                                    ext_tcomes_par);
    /* [0;5] BIN7 */
    tqdem_temp2 = DDS_M_MAP3D_U16(&TQDEM_FACPNREQTAKEOFF_M_APM,
                                    eng_nckfil_bin0,
                                    veh_spdveh_par);

    /* [0;25] BIN7 = [0;5] BIN7 * [0;5] BIN7 / BIN7 */
    tqdem_result = ((UInt32)tqdem_temp1 * (UInt32)tqdem_temp2) / BIN7;

    TqDem_facPNRegTakeOff = (UInt16)DDS_M_MIN(tqdem_result,((UInt32)5 * BIN7));

    /* [0;5] DEC2 */
    tqdem_temp1 = DDS_M_MAP2D_SU16(&TQDEM_FACITCOMES_T_APM,
                                    ext_tcomes_par);
    /* [0;5] DEC2 */
    tqdem_temp2 = DDS_M_MAP3D_U16(&TQDEM_FACINREQTAKEOFF_M_APM,
                                    eng_nckfil_bin0,
                                    veh_spdveh_par);

    /* DEC3 = DEC2 * DEC2 / DEC1 */
    tqdem_result = ((UInt32)tqdem_temp1 * (UInt32)tqdem_temp2) / DEC1;

    TqDem_facINRegTakeOff = (UInt16)DDS_M_MIN(tqdem_result,((UInt32)5 * DEC3));

    tqdem_temp3 = DDS_M_MAP2D_US16(&TQDEM_TQLIMPROTCLUP_T_APM,
                                    eng_nckfil_bin0);

    tqcmp_tqsumlosscmp_invert = (SInt32)tqcmp_tqsumlosscmp_par * (-1);

    if( ((UInt32)DDS_FALSE != (UInt32)copt_bacvprotclup_par)
    &&  ((UInt32)DDS_FALSE != (UInt32)TqDem_bAuthLimTqNRegProt_C) )
    {
        TqDem_tqSatBackNRegTakeOff = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqckefc_par,
                                                                tqcmp_tqsumlosscmp_invert,
                                                                (SInt32)tqdem_temp3);
    }
    else
    {
        TqDem_tqSatBackNRegTakeOff = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqckefc_par,
                                                                tqcmp_tqsumlosscmp_invert,
                                                                (SInt32)englim_tqefcnregtakeofflim_par);
    }
}



/*******************************************************************************
*
* Function Name : F02_01_02_Acvnreglimn
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_Acvnreglimn (UInt16 eslim_nlofucutoff_par,
                                                            UInt8 tqsys_bengnonidl_par,
                                                            UInt16 eng_nckfil_par,
                                                            UInt16 accp_raccp_par,
                                                            UInt8 frm_binhregnlimn_par,
                                                            UInt8 eslim_bacvtrqlim_par,
                                                            UInt8 copt_noegdgearcord_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 tqsys_tqidcairlimcordwires_par,
                                                            SInt16 tqdem_tqckefc_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.8.1  */

    TQDEM_F02_01_02_01_Calc_Traj_Cons_Limn (eslim_nlofucutoff_par);

    TQDEM_F02_01_02_02_Activation_Limn (tqsys_bengnonidl_par,
                                        eng_nckfil_par,
                                        accp_raccp_par,
                                        frm_binhregnlimn_par,
                                        eslim_bacvtrqlim_par);

    TQDEM_F02_01_02_03_Param_Regul_Limn(copt_noegdgearcord_par,
                                        tqcmp_tqsumlosscmp_par,
                                        tqsys_tqidcairlimcordwires_par,
                                        tqdem_tqckefc_par);

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_02_03_Param_Regul_Limn
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_03_Param_Regul_Limn (UInt8 copt_noegdgearcord_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 tqsys_tqidcairlimcordwires_par,
                                                            SInt16 tqdem_tqckefc_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.11.1 */

    SInt32 tqdem_tqiniinreglimn_unlim;
    SInt32 tqcmp_tqsumlosscmp_invert;
    UInt32 tqdem_facinreglimn_temp;

    /* [0;5] BIN7 */
    TqDem_facPNRegLimN = DDS_M_MAP2D_U16(&TQDEM_FACPNREQLIMN_T_APM,
                                        (UInt16)copt_noegdgearcord_par);
    /* [0;5] DEC2 */
    tqdem_facinreglimn_temp = (UInt32)DDS_M_MAP2D_U16(&TQDEM_FACINREQLIMN_T_APM,
                                                    (UInt16)copt_noegdgearcord_par);

    /* [0;5] DEC3 = [0;5] DEC2 * DEC1 */
    TqDem_facINRegLimN = (UInt16)(tqdem_facinreglimn_temp * DEC1);

    tqdem_tqiniinreglimn_unlim = ((SInt32)tqsys_tqidcairlimcordwires_par - (SInt32)tqcmp_tqsumlosscmp_par)
                                                    - ((SInt32)TqDem_tqOffSetLimN_C * BIN4);

    TqDem_tqIniINRegLimN = (SInt16)DDS_M_LIMIT(tqdem_tqiniinreglimn_unlim,
                                                TQDEM_NEG_2000_BIN4,
                                                TQDEM_POS_2000_BIN4);

    tqcmp_tqsumlosscmp_invert = (SInt32)tqcmp_tqsumlosscmp_par * (-1);

    TqDem_tqSatBackNRegLimN = (SInt16)DDS_M_SATURATION_V2((SInt32)TqDem_tqEfcNRegRaw,
                                                            tqcmp_tqsumlosscmp_invert,
                                                            (SInt32)tqdem_tqckefc_par);

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_02_01_Calc_Traj_Cons_Limn
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_01_Calc_Traj_Cons_Limn (UInt16 eslim_nlofucutoff_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.9.1 */

    SInt32 tqdem_nengreqlimn_unlim;

    TqDem_facDirNReqLimN = TqDem_facDirNReqLimN_C;

    tqdem_nengreqlimn_unlim = (SInt32)eslim_nlofucutoff_par - (SInt32)TqDem_nOffNEngReq_C;

    TqDem_nEngReqLimN = (UInt16)DDS_M_LIMIT(tqdem_nengreqlimn_unlim, 0, 7500);

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_02_02_Activation_Limn
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_02_02_Activation_Limn (UInt8 tqsys_bengnonidl_par,
                                                            UInt16 eng_nckfil_par,
                                                            UInt16 accp_raccp_par,
                                                            UInt8 frm_binhregnlimn_par,
                                                            UInt8 eslim_bacvtrqlim_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.10.1 */

    UInt8 input_edge;
    UInt8 output_edge;

    TqDem_facFilNEngLimN = TqDem_facFilNEngLimN_C;

    TqDem_rTranLimNOut = 0;

    if( ((UInt32)DDS_FALSE != (UInt32)tqsys_bengnonidl_par)
    ||  ((UInt32)eng_nckfil_par < ((UInt32)TqDem_nThdDeacLimN_C * BIN2))
    ||  ((UInt32)accp_raccp_par < (UInt32)TqDem_rAccPThdDeacLimN_C) )
    {
        input_edge = DDS_TRUE;
    }
    else
    {
        input_edge = DDS_FALSE;
    }

    output_edge = (UInt8)DDS_M_EDGE_DETECT(&tqdem_f02_01_02_02_edge_str,
                                            input_edge);

    if( ((UInt32)DDS_FALSE != (UInt32)TqDem_bAcvTakeOffOpm)
    ||  ((UInt32)DDS_FALSE != (UInt32)frm_binhregnlimn_par)
    ||  ((UInt32)DDS_FALSE != (UInt32)TqDem_bInhLimN_C) )
    {
        TqDem_bAcvLimNOpm = DDS_FALSE;
        TqDem_bAcvLimN = DDS_FALSE;
        TqDem_bDeacLimN = DDS_TRUE;
    }
    else
    {
        if((UInt32)DDS_M_POSITIVE_EDGE_DETECTED == (UInt32)output_edge)
        {
            TqDem_bAcvLimNOpm = DDS_FALSE;
        }
        else
        {
            if((UInt32)eng_nckfil_par >= ((UInt32)TqDem_nThdAcvLimNOpm_C * BIN2))
            {
                TqDem_bAcvLimNOpm = DDS_TRUE;
            }
            else
            {
                /* do nothing */
            }
        }

        if((UInt32)DDS_FALSE != (UInt32)input_edge)
        {
            TqDem_bAcvLimN = DDS_FALSE;
            TqDem_bDeacLimN = DDS_TRUE;
        }
        else
        {
            if((UInt32)DDS_FALSE != (UInt32)eslim_bacvtrqlim_par)
            {
                TqDem_bAcvLimN = DDS_TRUE;
                TqDem_bDeacLimN = DDS_FALSE;
            }
            else
            {
                /* do nothing */
            }
        }
    }
}



/*******************************************************************************
*
* Function Name : TQDEM_F02_01_03_Coordination
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_01_03_Coordination (CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_nengreq_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.21.0 */

    if((UInt32)DDS_FALSE != (UInt32)TqDem_bAcvTakeOffOpm)
    {
        TqDem_facDirNReq = TqDem_facDirNReqTakeOff;
        TqDem_rTranNRegOut = TqDem_rTranTakeOffOut;
        TqDem_facFilNEng = TqDem_facFilNEngTakeOff;
        *tqdem_nengreq_ptr = TqDem_nEngReqTakeOff;
        TqDem_facPNReg = TqDem_facPNRegTakeOff;
        TqDem_facINReg = TqDem_facINRegTakeOff;
        TqDem_tqIniINReg = TqDem_tqIniINRegTakeOff;
        TqDem_tqSatBackNReg = TqDem_tqSatBackNRegTakeOff;

        TqDem_bDeacNReg = TqDem_bDeacTakeOff;
        TqDem_bAcvNRegOpm = TqDem_bAcvTakeOffOpm;
    }
    else
    {
        TqDem_facDirNReq = TqDem_facDirNReqLimN;
        TqDem_rTranNRegOut = TqDem_rTranLimNOut;
        TqDem_facFilNEng = TqDem_facFilNEngLimN;
        *tqdem_nengreq_ptr = TqDem_nEngReqLimN;
        TqDem_facPNReg = TqDem_facPNRegLimN;
        TqDem_facINReg = TqDem_facINRegLimN;
        TqDem_tqIniINReg = TqDem_tqIniINRegLimN;
        TqDem_tqSatBackNReg = TqDem_tqSatBackNRegLimN;

        TqDem_bDeacNReg = TqDem_bDeacLimN;
        TqDem_bAcvNRegOpm = TqDem_bAcvLimNOpm;
    }
    /* [0;790] BIN7 = [0;7500] BIN0 * Pi BIN14 / 30 / BIN7 */
    TqDem_agvNEngReq = (((UInt32)*tqdem_nengreq_ptr * TQDEM_PI_BIN14) / 30) / BIN7;

}



/*******************************************************************************
*
* Function Name : TQDEM_F02_02_Traitement_Regime
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_02_Traitement_Regime (UInt16 ext_neng_par,
                                                            SInt16 treattenms_nckgrd_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.12.1 */

    SInt32 tqdem_f02_02_out_filter1;
    SInt16 tqdem_f02_02_out_filter2;
    UInt16 tqdem_f02_02_k_factor;
    UInt32 tqdem_f02_02_out_bary;
    SInt32 tqdem_f02_02_s32;
    SInt32 tqdem_agvgrdnengreq_unlim;
    SInt32 tqdem_agvgrdneng_temp;

    if ((UInt32)DDS_FALSE == (UInt32)tqdem_f02_02_initialised)
    {
        tqdem_f02_02_out_filter1 = (SInt32)DDS_M_FILTER_LP1_U16_INIT(&tqdem_f02_02_filter1, ext_neng_par);
        tqdem_f02_02_out_filter2 = DDS_M_FILTER_LP1_S16_INIT(&tqdem_f02_02_filter2, treattenms_nckgrd_par);

        tqdem_f02_02_initialised = DDS_TRUE;
    }
    else
    {
        /* [1/101;1/2] BIN10 = 0.01 * BIN17 / (0.01 * BIN7 + [0.01 ; 1] BIN7) */
        /* tqdem_f02_02_k_factor = (UInt16)((UInt32)(0.01 * BIN17) / ((UInt32)(0.01 * BIN7) + (UInt32)TqDem_facFilNEng)); --> resolution loss*/
        tqdem_f02_02_k_factor = (UInt16)((UInt32)(1 * BIN17) / ((UInt32)(1 * BIN7) + ((UInt32)TqDem_facFilNEng * DEC2)));

        tqdem_f02_02_out_filter1 = (SInt32)DDS_M_FILTER_LP1_U16(&tqdem_f02_02_filter1,
                                                        ext_neng_par,
                                                        tqdem_f02_02_k_factor,
                                                        BIN10);
        tqdem_f02_02_out_filter2 = DDS_M_FILTER_LP1_S16(&tqdem_f02_02_filter2,
                                                        treattenms_nckgrd_par,
                                                        tqdem_f02_02_k_factor,
                                                        BIN10);
    }

    /* [0;790] BIN7 = [0;7500] BIN0 * Pi BIN14 / 30 / BIN7 */
    tqdem_f02_02_out_filter1 = ((tqdem_f02_02_out_filter1 * (SInt32)TQDEM_PI_BIN14) / 30) / BIN7;

    /* [-790;790]BIN7 = [-8000;8000] BIN2 * Pi BIN14 / 30 / BIN9 */
    tqdem_agvgrdneng_temp = (((SInt32)tqdem_f02_02_out_filter2 * (SInt32)TQDEM_PI_BIN14) / 30) / BIN9;
    TqDem_agvGrdNEng = DDS_M_LIMIT(tqdem_agvgrdneng_temp,((SInt32)-790 * BIN7),((SInt32)790 * BIN7));

    if((UInt32)DDS_FALSE != (UInt32)TqDem_bDeacNReg)
    {
        TqDem_agvGrdNEngReq = 0;
    }
    else
    {
        /* [0;790] BIN7 */
        tqdem_f02_02_out_bary = (UInt32)DDS_M_BARY_FILTER_S32(tqdem_f02_02_out_filter1,
                                                              (SInt32)TqDem_agvNEngReq,
                                                              TqDem_rTranNRegOut,
                                                              (UInt16)BIN10);  /* 1 * BIN10 */

        /* [-790;790] BIN7 = [0;790] BIN7 - [0;790] BIN7 */
        tqdem_f02_02_s32 = (SInt32)tqdem_f02_02_out_bary - tqdem_f02_02_out_filter1;

        if(tqdem_f02_02_s32 == 0)
        {
            tqdem_agvgrdnengreq_unlim = 0;
        }
        else
        {
            if((UInt32)TqDem_facDirNReq == 0)
            {
                if(tqdem_f02_02_s32 > 0)
                {
                    tqdem_agvgrdnengreq_unlim = DDS_SINT32_MAX;
                }
                else
                {
                    tqdem_agvgrdnengreq_unlim = DDS_SINT32_MIN;
                }
            }
            else
            {
                /* [-101120;101120]BIN7 = [-790;790] BIN7 * BIN7 / [1/128;2] BIN7 */
                tqdem_agvgrdnengreq_unlim = (tqdem_f02_02_s32 * BIN7) / (SInt32)TqDem_facDirNReq;
            }
        }

        TqDem_agvGrdNEngReq = DDS_M_LIMIT(tqdem_agvgrdnengreq_unlim,
                                        ((SInt32)-790 * BIN7),
                                        ((SInt32)790 * BIN7));
    }

}



/*******************************************************************************
*
* Function Name : TQDEM_F03_Regulation
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_Regulation (SInt16 copt_tqmaxclu_par,
                                                    SInt16 englim_tqefcnregtakeofflim_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.13.1 */
    SInt32 tqdem_tqefcnregraw_temp;

    TQDEM_F03_01_Bo (copt_tqmaxclu_par,
                        englim_tqefcnregtakeofflim_par,
                        tqcmp_tqsumlosscmp_par);

    TQDEM_F03_02_Pi ();

    tqdem_tqefcnregraw_temp =(SInt32)TqDem_tqEfcNRegOpl + (SInt32)TqDem_tqEfcNRegCll;
    TqDem_tqEfcNRegRaw = (SInt16)DDS_M_LIMIT(tqdem_tqefcnregraw_temp,TQDEM_NEG_2000_BIN4,TQDEM_POS_2000_BIN4);

}



/*******************************************************************************
*
* Function Name : TQDEM_F03_01_Bo
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_01_Bo (SInt16 copt_tqmaxclu_par,
                                                SInt16 englim_tqefcnregtakeofflim_par,
                                                SInt16 tqcmp_tqsumlosscmp_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.14.1 */

    SInt32 tqdem_f03_01_s32_temp1;
    SInt32 tqdem_f03_01_s32_temp2;
    SInt32 tqdem_f03_01_s32_temp3;
    SInt32 tqdem_f03_01_num;
    SInt32 tqdem_f03_01_input_filter;
    SInt32 tqdem_f03_01_output_filter;
    UInt16 kfactor;

    TqDem_jEng = TqDem_jEng_C;

    if((UInt32)DDS_FALSE != (UInt32)TqDem_bTqCluSel_C)
    {
        /* BIN4 */
        tqdem_f03_01_s32_temp1 = (SInt32)copt_tqmaxclu_par;
    }
    else
    {
        tqdem_f03_01_s32_temp1 = 0;
    }

    /* BIN4 = BIN7 * BIN7 / BIN10 */
    tqdem_f03_01_s32_temp2 = (TqDem_agvGrdNEngReq * (SInt32)TqDem_jEng_C) / BIN10;

    /* BIN4 */
    tqdem_f03_01_s32_temp2 = tqdem_f03_01_s32_temp1 + tqdem_f03_01_s32_temp2;

    tqdem_f03_01_s32_temp3 = (SInt32)tqcmp_tqsumlosscmp_par * (-1);

    TqDem_tqEfcNRegOpl = (SInt16)DDS_M_SATURATION_V2(tqdem_f03_01_s32_temp2,
                                            tqdem_f03_01_s32_temp3,
                                            (SInt32)englim_tqefcnregtakeofflim_par);

    /* BIN4 */
    tqdem_f03_01_num = (SInt32)TqDem_tqEfcNRegOpl - tqdem_f03_01_s32_temp1;

    if(tqdem_f03_01_num == 0)
    {
        tqdem_f03_01_input_filter = 0;
    }
    else
    {
        if((SInt32)TqDem_jEng_C == 0)
        {
            if(tqdem_f03_01_num > 0)
            {
                tqdem_f03_01_input_filter = DDS_SINT32_MAX;
            }
            else
            {
                tqdem_f03_01_input_filter = DDS_SINT32_MIN;
            }
        }
        else
        {
            /* BIN7 = BIN4 * BIN10 / BIN7 */
            tqdem_f03_01_input_filter = (tqdem_f03_01_num * BIN10) / (SInt32)TqDem_jEng_C;
        }
    }



    if( ((UInt32)DDS_FALSE == (UInt32)tqdem_f03_01_initialised)
    ||  ((UInt32)DDS_FALSE != (UInt32)TqDem_bDeacNReg) )
    {
        tqdem_f03_01_output_filter = DDS_M_FILTER_LP1_S32_INIT(&tqdem_f03_01_filter_str,
                                                                 tqdem_f03_01_input_filter);
        tqdem_f03_01_initialised = DDS_TRUE;
    }
    else
    {
        /* [1/101;1/2] BIN15 = 0.01 BIN22 / (0.01 BIN7 + [1/128;1] BIN7) */
        kfactor = (UInt16)((UInt32)(0.01 * BIN22) / ((UInt32)(0.01 * BIN7) + (UInt32)TqDem_facFilGrdNEng_C));
        tqdem_f03_01_output_filter = DDS_M_FILTER_LP1_S32(&tqdem_f03_01_filter_str,
                                                         tqdem_f03_01_input_filter,
                                                         kfactor);
    }
    TqDem_agvGrdNEngReqFil = DDS_M_LIMIT(tqdem_f03_01_output_filter,
                                        ((SInt32)-790 * BIN7),
                                        ((SInt32)790 * BIN7));
}



/*******************************************************************************
*
* Function Name : TQDEM_F03_02_Pi
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_02_Pi (void)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.15.1 */

    SInt32 tqdem_tqckefcnregp_unlim;
    SInt32 num_temp;
    SInt32 temp_res_div;
    UInt32 delta_time_temp;
    SInt32 tqdem_facinregg_temp;
    SInt8 nb_shift_num;
    SInt32 temp_res_mult;
    UInt8 tqdem_integrator_act;

    if( ((UInt32)DDS_FALSE != (UInt32)TqDem_bDeacFacInt_C)
    ||  ((UInt32)DDS_FALSE != (UInt32)TqDem_bDeacNReg) )
    {
        tqdem_integrator_act = DDS_TRUE;
    }
    else
    {
        tqdem_integrator_act = DDS_FALSE;
    }

    /* BIN4 = (BIN7 - BIN7) * BIN7 / BIN7 * BIN7 / BIN10 */
    tqdem_tqckefcnregp_unlim = ((((TqDem_agvGrdNEngReqFil - TqDem_agvGrdNEng)
                                    * (SInt32)TqDem_jEng) / BIN7)
                                    * (SInt32)TqDem_facPNReg) / BIN10;

    TqDem_tqCkEfcNRegP_MP = (SInt16)DDS_M_LIMIT(tqdem_tqckefcnregp_unlim,
                                        TQDEM_NEG_2000_BIN4,
                                        TQDEM_POS_2000_BIN4);

    if( ((UInt32)DDS_FALSE == (UInt32)tqdem_f03_02_initialised)
    ||  ((UInt32)DDS_FALSE != (UInt32)tqdem_integrator_act) )
    {
        tqdem_tqckefcnregi_mp_save = (SInt32)TqDem_tqIniINReg * BIN6;
        tqdem_f03_02_initialised = TRUE;
    }
    else
    {
        num_temp = ((SInt32)TqDem_tqSatBackNReg + (SInt32)TqDem_tqCkEfcNRegP_MP) - (SInt32)TqDem_tqEfcNRegRaw;

        if(0 == num_temp)
        {
            temp_res_div = 0;
        }
        else if(0 == (UInt32)TqDem_facINReg)
        {
            if(0 < num_temp)
            {
                temp_res_div = DDS_SINT32_MAX;
            }
            else
            {
                temp_res_div = DDS_SINT32_MIN;
            }
        }
        else
        {
            /* (num_tmp / TqDem_facINReg) * delta_time = (num_tmp * delta_time) / TqDem_facINReg */
            /* BIN4 * DEC3 / DEC3 */
            /* [-6000; 6000] * [0; 20] / [0; 5] */

            /* BIN11 = DEC3 * BIN11 / DEC3 */
            delta_time_temp = (tqdem_trq_delta_time * BIN11) / DEC3;
            tqdem_facinregg_temp = ((SInt32)TqDem_facINReg * BIN11) / DEC3 ;

            /* Use dynamic bin point */
            /* [-120000; 120000] = [-6000; 6000] * [0; 20] */
            /* BINx = BIN4 * BIN11 */
            nb_shift_num = (SInt8)(4 + 11);
            temp_res_mult = DDS_M_DYNAMIC_MULT_S32(num_temp, (SInt32)delta_time_temp, &nb_shift_num);

            /* BIN10 (this is an arbitrary choice as the integrator precision is not specified) */
            /* [-2097151.999; 2097151.999] = [-120000 ; 120000] / [0; 5] */
            temp_res_div = DDS_M_DYNAMIC_DIV_S32(temp_res_mult, tqdem_facinregg_temp, nb_shift_num, 11, 10);
        }

        /* BIN10 */
        tqdem_tqckefcnregi_mp_save = DDS_M_ADDITION_S32(temp_res_div, tqdem_tqckefcnregi_mp_save);
        tqdem_tqckefcnregi_mp_save = DDS_M_LIMIT(tqdem_tqckefcnregi_mp_save,
                                                TQDEM_NEG_2000_BIN10,
                                                TQDEM_POS_2000_BIN10);
    }

    TqDem_tqCkEfcNRegI_MP = (SInt16)(tqdem_tqckefcnregi_mp_save / BIN6);

    num_temp = (SInt32)TqDem_tqCkEfcNRegI_MP + (SInt32)TqDem_tqCkEfcNRegP_MP;

    TqDem_tqEfcNRegCll = (SInt16)DDS_M_LIMIT(num_temp,
                                              TQDEM_NEG_2000_BIN4,
                                              TQDEM_POS_2000_BIN4);
}



/*******************************************************************************
*
* Function Name : TQDEM_F04_Couplelimn
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F04_Couplelimn (SInt16 tqcmp_tqsumlosscmp_par,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqidclimnreg_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.16.1 */
    SInt32 tqdem_tqidclimnreg_temp;

    if((UInt32)DDS_FALSE != (UInt32)TqDem_bAcvLimN)
    {
        tqdem_tqidclimnreg_temp = (SInt32)TqDem_tqEfcNRegRaw + (SInt32)tqcmp_tqsumlosscmp_par;
        *tqdem_tqidclimnreg_ptr = (SInt16)DDS_M_LIMIT(tqdem_tqidclimnreg_temp,
                                              TQDEM_NEG_2000_BIN4,
                                              TQDEM_POS_2000_BIN4);
    }
    else
    {
        *tqdem_tqidclimnreg_ptr = (SInt16)TQDEM_POS_2000_BIN4;
    }

}



/*******************************************************************************
*
* Function Name : TQDEM_F05_Coupledeco
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_Coupledeco (SInt16 englim_tqefcnregtakeofflim_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par,
                                                    UInt8 tqdem_bacvnregtakeoff_par,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqefcnregtakeoffeco_ptr,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqefcnregtakeoffnorm_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0919.FR.17.1 */

    if((UInt32)DDS_FALSE != (UInt32)tqdem_bacvnregtakeoff_par )
    {
        tqdem_tqefcnregtakeoffeco_ptr[0] = TqDem_tqEfcNRegRaw;
        tqdem_tqefcnregtakeoffnorm_ptr[0] = TqDem_tqEfcNRegRaw;
    }
    else
    {
        tqdem_tqefcnregtakeoffeco_ptr[0] = (SInt16)((SInt32)tqcmp_tqsumlosscmp_par * (-1));
        tqdem_tqefcnregtakeoffnorm_ptr[0] = (SInt16)((SInt32)tqcmp_tqsumlosscmp_par * (-1));
    }

    tqdem_tqefcnregtakeoffeco_ptr[1] = englim_tqefcnregtakeofflim_par;
    tqdem_tqefcnregtakeoffnorm_ptr[1] = englim_tqefcnregtakeofflim_par;


}




/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Trq_Take_Off_Assist_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Trq_Take_Off_Assist_Init(
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffEco_swc_out, /* tab[] BIN4 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffNorm_swc_out, /* tab[] BIN4 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqIdcLimNReg_swc_out, /* BIN4 */
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bAcvNRegTakeOff_swc_out,
                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_nEngReq_swc_out /* BIN0 */)
{

    TqDem_tqEfcNRegTakeOffEco_swc_out[0] = 0;
    TqDem_tqEfcNRegTakeOffNorm_swc_out[0] = 0;
    TqDem_tqEfcNRegTakeOffEco_swc_out[1] = 0;
    TqDem_tqEfcNRegTakeOffNorm_swc_out[1] = 0;
    *TqDem_tqIdcLimNReg_swc_out = 0;
    *TqDem_bAcvNRegTakeOff_swc_out = DDS_TRUE;
    *TqDem_nEngReq_swc_out = (UInt16)(750 * BIN0);

    tqdem_f02_01_01_01_01_init = DDS_FALSE;
    tqdem_f02_02_initialised = DDS_FALSE;
    tqdem_f03_01_initialised = DDS_FALSE;
    tqdem_f03_02_initialised = DDS_FALSE;

    (void)DDS_M_EDGE_DETECT_INIT(&tqdem_f02_01_02_02_edge_str,DDS_FALSE);

    tqdem_trq_prev_time = DDS_TQDEM_1MS_U32_TIME;

    TqDem_agvGrdNEng = 0;
    TqDem_agvGrdNEngReq = 0;
    TqDem_agvGrdNEngReqFil = 0;
    TqDem_agvNEngReq = 0;
    TqDem_bAcvLimN = DDS_FALSE;
    TqDem_bAcvLimNOpm = DDS_FALSE;
    TqDem_bAcvNRegOpm = DDS_FALSE;
    TqDem_bAcvTakeOffOpm = DDS_FALSE;
    TqDem_bDeacLimN = DDS_TRUE;
    TqDem_bDeacNReg = DDS_FALSE;
    TqDem_bDeacTakeOff = DDS_TRUE;
    TqDem_facDirNReq = 1; /* = (1/128 * BIN7); */
    TqDem_facDirNReqLimN = 1; /* = (1/128 * BIN7); */
    TqDem_facDirNReqTakeOff = 1; /* = (1/128 * BIN7); */
    TqDem_facFilNEng = 1; /* = ((0.01) * BIN7); */
    TqDem_facFilNEngLimN = 1; /* = ((0.01) * BIN7); */
    TqDem_facFilNEngTakeOff = 1; /* = ((0.01) * BIN7); */
    TqDem_facINReg = 0;
    TqDem_facINRegLimN = 0;
    TqDem_facINRegTakeOff = 0;
    TqDem_facPNReg = 0;
    TqDem_facPNRegLimN = 0;
    TqDem_facPNRegTakeOff = 0;
    TqDem_jEng = 1; /* = ((1/128) * BIN7); */
    TqDem_nEngOfsReq = 0;
    TqDem_nEngReqLimN = 0;
    TqDem_nEngReqTakeOff = 0;
    TqDem_rTranLimNOut = 0;
    TqDem_rTranNRegOut = 0;
    TqDem_rTranTakeOffOut = 0;
    TqDem_tqCkEfcNRegI_MP = 0;
    TqDem_tqCkEfcNRegP_MP = 0;
    TqDem_tqEfcNRegCll = 0;
    TqDem_tqEfcNRegOpl = 0;
    TqDem_tqEfcNRegRaw = 0;
    TqDem_tqIniINReg = 0;
    TqDem_tqIniINRegLimN = 0;
    TqDem_tqIniINRegTakeOff = 0;
    TqDem_tqSatBackNReg = (500 * BIN4);
    TqDem_tqSatBackNRegLimN = (500 * BIN4);
    TqDem_tqSatBackNRegTakeOff = (500 * BIN4);

}


#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

