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
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Ivc_Content.c
* Version int :/main/L05_01/2 Date: 17/7/2012 15 h 48 m User:posmyk 
*    TWK_model:TQDEM_Ivc_Content_L05_010_IMPL1_D
*    comments :add INLINE for static functions
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 13 m User:lemort 
*    TWK_model:TQDEM_Ivc_Content_L05_010_IMPL1_D
*    comments :add INLINE for static functions
* Version int :/main/L05_01/1 Date: 10/3/2011 11 h 46 m User:esnault
*    TWK_model:TQDEM_Ivc_Content_L05_010_IMPL1
*    comments :Update code and model for "tqdem_tqefcnregtakeoffeco" and " tqdem_tqefcnregtakeoffnorm"
*    comments :which become Input/Output (not irv any more)
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/3/2011 14 h 9 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L05_010_IMPL1
*    comments :Update code and model for "tqdem_tqefcnregtakeoffeco" and " tqdem_tqefcnregtakeoffnorm"
*    comments :which become Input/Output (not irv any more)
* Version int :/main/L04_01/2 Date: 8/10/2010 16 h 31 m User:meme
*    TWK_model:TQDEM_Ivc_Content_L04_011_IMPL1
*    comments :For TqDem 10.1 (correction SSTE 1009342)
* Version dev :\main\branch_lemort_dev_tqdem\4 Date: 5/10/2010 12 h 45 m User:lemort
*    TWK_model:TQDEM_Ivc_Content_L04_011_IMPL1
*    comments :For TqDem 10.1 (correction SSTE 1009342)
* Version dev :\main\branch_lemort_dev_tqdem\3 Date: 4/10/2010 15 h 41 m User:lemort
*    TWK_model:TQDEM_Ivc_Content_L04_011_IMPL1
*    comments :correction after UT
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 1/10/2010 10 h 24 m User:lemort
*    TWK_model:TQDEM_Ivc_Content_L04_011_IMPL1
*    comments :correction after UT
* Version int :/main/L04_01/1 Date: 1/9/2010 14 h 7 m User:esnault
*    TWK_model:TQDEM_Ivc_Content_L04_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:TQDEM_Ivc_Content_L04_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_salmane_tqdem_e6_dev\1 Date: 9/7/2010 15 h 41 m User:salmane
*    TWK_model:TQDEM_Ivc_Content_L04_010_IMPL1
*    comments :For TqDem 1.0 Euro6
* Version int :/main/L03_01/1 Date: 23/11/2009 10 h 55 m User:langendorf
*    TWK_model:TQDEM_Ivc_Content_L03_010_IMPL1
*    comments :for TqDem 2.1
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 16/11/2009 9 h 54 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L03_010_IMPL1
*    comments :for TqDem 2.1
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 10/11/2009 17 h 14 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L03_010_IMPL1
*    comments :Correct FDS28926: TqDem_tqEfcNRegTakeOffEco and TqDem_tqEfcNRegTakeOffNorm are 2-dimensions
*    comments :variables.
* Version int :/main/L02_01/1 Date: 16/9/2009 10 h 44 m User:langendorf
*    TWK_model:TQDEM_Ivc_Content_L02_010_IMPL1
*    comments :Correct PSTR fail. Intialize internal variables.
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 4/9/2009 10 h 59 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L02_010_IMPL1
*    comments :Correct PSTR fail. Intialize internal variables.
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 28/8/2009 15 h 22 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L02_010_IMPL1
*    comments :First issue for TqDem 2.0: CSMT_CGMT06_0062_v2_2
* Version int :/main/L01_01/3 Date: 3/12/2008 19 h 8 m User:boucher
*    TWK_model:TQDEM_Ivc_Content_L01_011_IMPL1
*    comments :Only model has changed (minor modification)
* Version dev :\main\branch_moisan_tqdem_dev\10 Date: 3/12/2008 16 h 52 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_011_IMPL1
*    comments :Only model has changed (minor modification)
* Version dev :\main\branch_moisan_tqdem_dev\9 Date: 24/11/2008 16 h 50 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2_D
*    comments :FDS 24804
* Version int :/main/L01_01/2 Date: 10/10/2008 10 h 52 m User:boucher
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Fail correction: saturation + bad implementation with TqDem_bTqGrdLim
*    comments :Fail correction: saturation + bad implementation with TqDem_bTqGrdLim
* Version int :/main/L01_01/1 Date: 9/9/2008 8 h 8 m User:boucher
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :Correction due to new QAC warnings
* Version dev :\main\branch_moisan_tqdem_dev\8 Date: 8/10/2008 12 h 23 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Fail correction: saturation +  bad implementation with TqDem_bTqGrdLim
* Version dev :\main\branch_moisan_tqdem_dev\7 Date: 7/10/2008 11 h 19 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Change with TqDem_facAdpAccPOff_MP
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 3/10/2008 16 h 0 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Correction of fail test
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 10/9/2008 9 h 47 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :Correction due to Tracking sheet back
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 8/9/2008 9 h 33 m User:moisan
* Version dev :\main\branch_moisan_tqdem_dev\8 Date: 8/10/2008 12 h 23 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Fail correction: saturation +  bad implementation with TqDem_bTqGrdLim
* Version dev :\main\branch_moisan_tqdem_dev\7 Date: 7/10/2008 11 h 19 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Change with TqDem_facAdpAccPOff_MP
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 3/10/2008 16 h 0 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL2
*    comments :Correction of fail test
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 10/9/2008 9 h 47 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :Correction due to Tracking sheet back
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 8/9/2008 9 h 33 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :Correction due to new QAC warnings
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 5/9/2008 13 h 11 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :Error with TQDEM_START_SEC_CODE
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 3/9/2008 13 h 45 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :Correct missed snapshot
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/9/2008 9 h 41 m User:moisan
*    TWK_model:TQDEM_Ivc_Content_L01_010_IMPL1
*    comments :First implementation for TqDem PSA SSTG (E)
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

#define TQCMP_TQSUMLOSSCMP_NCKTQDEM_SIZE      16
#define TQDEM_FAC_IDLNCK_SIZE                 9
#define TQDEM_NVECT_SIZE                      16
#define TQDEM_SPDVEHSPT_SIZE                  10
#define TQDEM_SPDVEHRATSPT_SIZE               8


#define TQDEM_1   (UInt32)1
#define TQDEM_2   (UInt32)2
#define TQDEM_3   (UInt32)3
#define TQDEM_4   (UInt32)4

#define TQDEM_STAUTHSPTMOD_0    (UInt32)(0*BIN0)
#define TQDEM_STAUTHSPTMOD_1    (UInt32)(1*BIN0)
#define TQDEM_STAUTHSPTMOD_2    (UInt32)(2*BIN0)

#define TQDEM_IVC_CONT_SCHED    (UInt32)10


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
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPOfs_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcLossOfs_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPThdAcvSptMod_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_tiTranProtCluPOff_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_tiTranProtCluPOn_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_tiTranSptOff_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC2);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_tiTranSptOn_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bTypSptSel_C = DDS_TRUE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_stAuthSptMod_C = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQDEM_START_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facSptSpdAccP_T
[TQDEM_SPDVEHSPT_SIZE] = {
(UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4),
(UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4),
(UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4),
(UInt16)(1.2 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehSpt_A[TQDEM_SPDVEHSPT_SIZE] = {
(UInt16)(10 * BIN7), (UInt16)(30 * BIN7), (UInt16)(60 * BIN7),
(UInt16)(90 * BIN7), (UInt16)(120 * BIN7), (UInt16)(150 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(150 * BIN7), (UInt16)(150 * BIN7),
(UInt16)(150 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehRatSpt_A[TQDEM_SPDVEHRATSPT_SIZE] = {
(UInt16)(0 * BIN8), (UInt16)(8 * BIN8), (UInt16)(16 * BIN8),
(UInt16)(25 * BIN8), (UInt16)(35 * BIN8), (UInt16)(45 * BIN8),
(UInt16)(55 * BIN8), (UInt16)(55 * BIN8)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facSptSpdRatAccP_T
[TQDEM_SPDVEHRATSPT_SIZE] = {
(UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4),
(UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4),
(UInt16)(1.2 * BIN4), (UInt16)(1.2 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_facNEngIdl_A[TQDEM_FAC_IDLNCK_SIZE] = {
(SInt16)(-1000 * BIN2), (SInt16)(-500 * BIN2), (SInt16)(-250 * BIN2),
(SInt16)(-100 * BIN2), (SInt16)(0 * BIN2), (SInt16)(100 * BIN2),
(SInt16)(250 * BIN2), (SInt16)(500 * BIN2), (SInt16)(1000 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_facNEngIdl_T
[TQDEM_FAC_IDLNCK_SIZE] = {
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPAdp_T
[TQDEM_NVECT_SIZE] = {
(UInt16)(1.00 * BIN7), (UInt16)(1.00 * BIN7), (UInt16)(1.00 * BIN7),
(UInt16)(1.00 * BIN7), (UInt16)(2.00 * BIN7), (UInt16)(2.00 * BIN7),
(UInt16)(2.00 * BIN7), (UInt16)(2.00 * BIN7), (UInt16)(3.00 * BIN7),
(UInt16)(5.00 * BIN7), (UInt16)(6.00 * BIN7), (UInt16)(8.00 * BIN7),
(UInt16)(10.00 * BIN7), (UInt16)(16.00 * BIN7), (UInt16)(18.00 * BIN7),
(UInt16)(20.00 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_tqCkEfc_nEngY_A[TQDEM_NVECT_SIZE] = {
(UInt16)(600 * BIN2), (UInt16)(700 * BIN2), (UInt16)(780 * BIN2),
(UInt16)(1000 * BIN2), (UInt16)(1300 * BIN2), (UInt16)(1500 * BIN2),
(UInt16)(1750 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2),
(UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2), (UInt16)(4000 * BIN2),
(UInt16)(4500 * BIN2), (UInt16)(5000 * BIN2), (UInt16)(5500 * BIN2),
(UInt16)(6000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_tqCkEfc_rAccPX_A[TQDEM_NVECT_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(2 * BIN7), (UInt16)(4 * BIN7),
(UInt16)(6 * BIN7), (UInt16)(10 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(20 * BIN7), (UInt16)(25 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(35 * BIN7), (UInt16)(40 * BIN7), (UInt16)(50 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(100 * BIN7)
};


STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcHiSpdNorm_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(25.22 * BIN4), (SInt16)(48.90 * BIN4),
(SInt16)(81.80 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(17.26 * BIN4), (SInt16)(41.40 * BIN4),
(SInt16)(66.10 * BIN4), (SInt16)(102.70 * BIN4), (SInt16)(139.76 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(13.58 * BIN4), (SInt16)(32.25 * BIN4),
(SInt16)(56.97 * BIN4), (SInt16)(88.73 * BIN4), (SInt16)(126.28 * BIN4),
(SInt16)(145.27 * BIN4), (SInt16)(153.45 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(8.48 * BIN4), (SInt16)(23.57 * BIN4),
(SInt16)(34.44 * BIN4), (SInt16)(56.80 * BIN4), (SInt16)(84.53 * BIN4),
(SInt16)(114.10 * BIN4), (SInt16)(136.16 * BIN4), (SInt16)(153.90 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(3.10 * BIN4), (SInt16)(17.70 * BIN4),
(SInt16)(27.90 * BIN4), (SInt16)(42.65 * BIN4), (SInt16)(63.20 * BIN4),
(SInt16)(91.80 * BIN4), (SInt16)(117.50 * BIN4), (SInt16)(150.40 * BIN4),
(SInt16)(184.28 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(13.80 * BIN4),
(SInt16)(22.56 * BIN4), (SInt16)(33.58 * BIN4), (SInt16)(52.03 * BIN4),
(SInt16)(74.82 * BIN4), (SInt16)(100.84 * BIN4), (SInt16)(136.30 * BIN4),
(SInt16)(168.40 * BIN4), (SInt16)(193.35 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(19.86 * BIN4), (SInt16)(28.89 * BIN4), (SInt16)(44.08 * BIN4),
(SInt16)(63.24 * BIN4), (SInt16)(85.81 * BIN4), (SInt16)(120.00 * BIN4),
(SInt16)(151.30 * BIN4), (SInt16)(179.60 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(24.84 * BIN4), (SInt16)(38.07 * BIN4),
(SInt16)(55.00 * BIN4), (SInt16)(75.41 * BIN4), (SInt16)(104.60 * BIN4),
(SInt16)(136.30 * BIN4), (SInt16)(168.00 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(19.50 * BIN4), (SInt16)(30.26 * BIN4),
(SInt16)(44.74 * BIN4), (SInt16)(63.03 * BIN4), (SInt16)(87.65 * BIN4),
(SInt16)(118.67 * BIN4), (SInt16)(150.68 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(50.94 * BIN4), (SInt16)(73.27 * BIN4),
(SInt16)(104.11 * BIN4), (SInt16)(137.34 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcLoSpdEco_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(25.22 * BIN4), (SInt16)(48.90 * BIN4),
(SInt16)(81.80 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(17.26 * BIN4), (SInt16)(41.40 * BIN4),
(SInt16)(66.10 * BIN4), (SInt16)(102.70 * BIN4), (SInt16)(139.76 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(13.58 * BIN4), (SInt16)(32.25 * BIN4),
(SInt16)(56.97 * BIN4), (SInt16)(88.73 * BIN4), (SInt16)(126.28 * BIN4),
(SInt16)(145.27 * BIN4), (SInt16)(153.45 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(8.48 * BIN4), (SInt16)(23.57 * BIN4),
(SInt16)(34.44 * BIN4), (SInt16)(56.80 * BIN4), (SInt16)(84.53 * BIN4),
(SInt16)(114.10 * BIN4), (SInt16)(136.16 * BIN4), (SInt16)(153.90 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(3.10 * BIN4), (SInt16)(17.70 * BIN4),
(SInt16)(27.90 * BIN4), (SInt16)(42.65 * BIN4), (SInt16)(63.20 * BIN4),
(SInt16)(91.80 * BIN4), (SInt16)(117.50 * BIN4), (SInt16)(150.40 * BIN4),
(SInt16)(184.28 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(13.80 * BIN4),
(SInt16)(22.56 * BIN4), (SInt16)(33.58 * BIN4), (SInt16)(52.03 * BIN4),
(SInt16)(74.82 * BIN4), (SInt16)(100.84 * BIN4), (SInt16)(136.30 * BIN4),
(SInt16)(168.40 * BIN4), (SInt16)(193.35 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(19.86 * BIN4), (SInt16)(28.89 * BIN4), (SInt16)(44.08 * BIN4),
(SInt16)(63.24 * BIN4), (SInt16)(85.81 * BIN4), (SInt16)(120.00 * BIN4),
(SInt16)(151.30 * BIN4), (SInt16)(179.60 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(24.84 * BIN4), (SInt16)(38.07 * BIN4),
(SInt16)(55.00 * BIN4), (SInt16)(75.41 * BIN4), (SInt16)(104.60 * BIN4),
(SInt16)(136.30 * BIN4), (SInt16)(168.00 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(19.50 * BIN4), (SInt16)(30.26 * BIN4),
(SInt16)(44.74 * BIN4), (SInt16)(63.03 * BIN4), (SInt16)(87.65 * BIN4),
(SInt16)(118.67 * BIN4), (SInt16)(150.68 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(50.94 * BIN4), (SInt16)(73.27 * BIN4),
(SInt16)(104.11 * BIN4), (SInt16)(137.34 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcLoSpdNorm_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(25.22 * BIN4), (SInt16)(48.90 * BIN4),
(SInt16)(81.80 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(17.26 * BIN4), (SInt16)(41.40 * BIN4),
(SInt16)(66.10 * BIN4), (SInt16)(102.70 * BIN4), (SInt16)(139.76 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(13.58 * BIN4), (SInt16)(32.25 * BIN4),
(SInt16)(56.97 * BIN4), (SInt16)(88.73 * BIN4), (SInt16)(126.28 * BIN4),
(SInt16)(145.27 * BIN4), (SInt16)(153.45 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(8.48 * BIN4), (SInt16)(23.57 * BIN4),
(SInt16)(34.44 * BIN4), (SInt16)(56.80 * BIN4), (SInt16)(84.53 * BIN4),
(SInt16)(114.10 * BIN4), (SInt16)(136.16 * BIN4), (SInt16)(153.90 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(3.10 * BIN4), (SInt16)(17.70 * BIN4),
(SInt16)(27.90 * BIN4), (SInt16)(42.65 * BIN4), (SInt16)(63.20 * BIN4),
(SInt16)(91.80 * BIN4), (SInt16)(117.50 * BIN4), (SInt16)(150.40 * BIN4),
(SInt16)(184.28 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(13.80 * BIN4),
(SInt16)(22.56 * BIN4), (SInt16)(33.58 * BIN4), (SInt16)(52.03 * BIN4),
(SInt16)(74.82 * BIN4), (SInt16)(100.84 * BIN4), (SInt16)(136.30 * BIN4),
(SInt16)(168.40 * BIN4), (SInt16)(193.35 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(19.86 * BIN4), (SInt16)(28.89 * BIN4), (SInt16)(44.08 * BIN4),
(SInt16)(63.24 * BIN4), (SInt16)(85.81 * BIN4), (SInt16)(120.00 * BIN4),
(SInt16)(151.30 * BIN4), (SInt16)(179.60 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(24.84 * BIN4), (SInt16)(38.07 * BIN4),
(SInt16)(55.00 * BIN4), (SInt16)(75.41 * BIN4), (SInt16)(104.60 * BIN4),
(SInt16)(136.30 * BIN4), (SInt16)(168.00 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(19.50 * BIN4), (SInt16)(30.26 * BIN4),
(SInt16)(44.74 * BIN4), (SInt16)(63.03 * BIN4), (SInt16)(87.65 * BIN4),
(SInt16)(118.67 * BIN4), (SInt16)(150.68 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(50.94 * BIN4), (SInt16)(73.27 * BIN4),
(SInt16)(104.11 * BIN4), (SInt16)(137.34 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcAvrSpdNorm_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(25.22 * BIN4), (SInt16)(48.90 * BIN4),
(SInt16)(81.80 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(17.26 * BIN4), (SInt16)(41.40 * BIN4),
(SInt16)(66.10 * BIN4), (SInt16)(102.70 * BIN4), (SInt16)(139.76 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(13.58 * BIN4), (SInt16)(32.25 * BIN4),
(SInt16)(56.97 * BIN4), (SInt16)(88.73 * BIN4), (SInt16)(126.28 * BIN4),
(SInt16)(145.27 * BIN4), (SInt16)(153.45 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(8.48 * BIN4), (SInt16)(23.57 * BIN4),
(SInt16)(34.44 * BIN4), (SInt16)(56.80 * BIN4), (SInt16)(84.53 * BIN4),
(SInt16)(114.10 * BIN4), (SInt16)(136.16 * BIN4), (SInt16)(153.90 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(3.10 * BIN4), (SInt16)(17.70 * BIN4),
(SInt16)(27.90 * BIN4), (SInt16)(42.65 * BIN4), (SInt16)(63.20 * BIN4),
(SInt16)(91.80 * BIN4), (SInt16)(117.50 * BIN4), (SInt16)(150.40 * BIN4),
(SInt16)(184.28 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(13.80 * BIN4),
(SInt16)(22.56 * BIN4), (SInt16)(33.58 * BIN4), (SInt16)(52.03 * BIN4),
(SInt16)(74.82 * BIN4), (SInt16)(100.84 * BIN4), (SInt16)(136.30 * BIN4),
(SInt16)(168.40 * BIN4), (SInt16)(193.35 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(19.86 * BIN4), (SInt16)(28.89 * BIN4), (SInt16)(44.08 * BIN4),
(SInt16)(63.24 * BIN4), (SInt16)(85.81 * BIN4), (SInt16)(120.00 * BIN4),
(SInt16)(151.30 * BIN4), (SInt16)(179.60 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(24.84 * BIN4), (SInt16)(38.07 * BIN4),
(SInt16)(55.00 * BIN4), (SInt16)(75.41 * BIN4), (SInt16)(104.60 * BIN4),
(SInt16)(136.30 * BIN4), (SInt16)(168.00 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(19.50 * BIN4), (SInt16)(30.26 * BIN4),
(SInt16)(44.74 * BIN4), (SInt16)(63.03 * BIN4), (SInt16)(87.65 * BIN4),
(SInt16)(118.67 * BIN4), (SInt16)(150.68 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(50.94 * BIN4), (SInt16)(73.27 * BIN4),
(SInt16)(104.11 * BIN4), (SInt16)(137.34 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcRev_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(25.22 * BIN4), (SInt16)(48.90 * BIN4),
(SInt16)(81.80 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(17.26 * BIN4), (SInt16)(41.40 * BIN4),
(SInt16)(66.10 * BIN4), (SInt16)(102.70 * BIN4), (SInt16)(139.76 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(13.58 * BIN4), (SInt16)(32.25 * BIN4),
(SInt16)(56.97 * BIN4), (SInt16)(88.73 * BIN4), (SInt16)(126.28 * BIN4),
(SInt16)(145.27 * BIN4), (SInt16)(153.45 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(8.48 * BIN4), (SInt16)(23.57 * BIN4),
(SInt16)(34.44 * BIN4), (SInt16)(56.80 * BIN4), (SInt16)(84.53 * BIN4),
(SInt16)(114.10 * BIN4), (SInt16)(136.16 * BIN4), (SInt16)(153.90 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(3.10 * BIN4), (SInt16)(17.70 * BIN4),
(SInt16)(27.90 * BIN4), (SInt16)(42.65 * BIN4), (SInt16)(63.20 * BIN4),
(SInt16)(91.80 * BIN4), (SInt16)(117.50 * BIN4), (SInt16)(150.40 * BIN4),
(SInt16)(184.28 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(13.80 * BIN4),
(SInt16)(22.56 * BIN4), (SInt16)(33.58 * BIN4), (SInt16)(52.03 * BIN4),
(SInt16)(74.82 * BIN4), (SInt16)(100.84 * BIN4), (SInt16)(136.30 * BIN4),
(SInt16)(168.40 * BIN4), (SInt16)(193.35 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(19.86 * BIN4), (SInt16)(28.89 * BIN4), (SInt16)(44.08 * BIN4),
(SInt16)(63.24 * BIN4), (SInt16)(85.81 * BIN4), (SInt16)(120.00 * BIN4),
(SInt16)(151.30 * BIN4), (SInt16)(179.60 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(24.84 * BIN4), (SInt16)(38.07 * BIN4),
(SInt16)(55.00 * BIN4), (SInt16)(75.41 * BIN4), (SInt16)(104.60 * BIN4),
(SInt16)(136.30 * BIN4), (SInt16)(168.00 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(19.50 * BIN4), (SInt16)(30.26 * BIN4),
(SInt16)(44.74 * BIN4), (SInt16)(63.03 * BIN4), (SInt16)(87.65 * BIN4),
(SInt16)(118.67 * BIN4), (SInt16)(150.68 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(50.94 * BIN4), (SInt16)(73.27 * BIN4),
(SInt16)(104.11 * BIN4), (SInt16)(137.34 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOffEco_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(57.90 * BIN4), (SInt16)(77.40 * BIN4),
(SInt16)(104.00 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(42.20 * BIN4), (SInt16)(66.20 * BIN4),
(SInt16)(94.30 * BIN4), (SInt16)(118.30 * BIN4), (SInt16)(145.20 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(31.30 * BIN4), (SInt16)(57.20 * BIN4),
(SInt16)(88.70 * BIN4), (SInt16)(113.80 * BIN4), (SInt16)(143.00 * BIN4),
(SInt16)(149.70 * BIN4), (SInt16)(155.40 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(19.70 * BIN4), (SInt16)(42.20 * BIN4),
(SInt16)(69.50 * BIN4), (SInt16)(100.00 * BIN4), (SInt16)(127.20 * BIN4),
(SInt16)(142.20 * BIN4), (SInt16)(154.20 * BIN4), (SInt16)(156.50 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(26.80 * BIN4),
(SInt16)(47.40 * BIN4), (SInt16)(77.40 * BIN4), (SInt16)(104.00 * BIN4),
(SInt16)(126.10 * BIN4), (SInt16)(155.00 * BIN4), (SInt16)(177.50 * BIN4),
(SInt16)(191.70 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(17.80 * BIN4),
(SInt16)(36.90 * BIN4), (SInt16)(61.70 * BIN4), (SInt16)(90.00 * BIN4),
(SInt16)(111.50 * BIN4), (SInt16)(148.60 * BIN4), (SInt16)(175.20 * BIN4),
(SInt16)(194.00 * BIN4), (SInt16)(203.70 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(25.70 * BIN4), (SInt16)(43.30 * BIN4), (SInt16)(70.30 * BIN4),
(SInt16)(92.00 * BIN4), (SInt16)(127.60 * BIN4), (SInt16)(158.40 * BIN4),
(SInt16)(179.30 * BIN4), (SInt16)(195.10 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(32.40 * BIN4), (SInt16)(52.30 * BIN4),
(SInt16)(76.70 * BIN4), (SInt16)(106.30 * BIN4), (SInt16)(142.20 * BIN4),
(SInt16)(161.70 * BIN4), (SInt16)(183.10 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(21.20 * BIN4), (SInt16)(33.90 * BIN4),
(SInt16)(54.20 * BIN4), (SInt16)(81.20 * BIN4), (SInt16)(109.60 * BIN4),
(SInt16)(134.00 * BIN4), (SInt16)(156.50 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(56.00 * BIN4), (SInt16)(84.50 * BIN4),
(SInt16)(112.30 * BIN4), (SInt16)(140.00 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOffNorm_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(57.90 * BIN4), (SInt16)(77.40 * BIN4),
(SInt16)(104.00 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(42.20 * BIN4), (SInt16)(66.20 * BIN4),
(SInt16)(94.30 * BIN4), (SInt16)(118.30 * BIN4), (SInt16)(145.20 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(31.30 * BIN4), (SInt16)(57.20 * BIN4),
(SInt16)(88.70 * BIN4), (SInt16)(113.80 * BIN4), (SInt16)(143.00 * BIN4),
(SInt16)(149.70 * BIN4), (SInt16)(155.40 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(19.70 * BIN4), (SInt16)(42.20 * BIN4),
(SInt16)(69.50 * BIN4), (SInt16)(100.00 * BIN4), (SInt16)(127.20 * BIN4),
(SInt16)(142.20 * BIN4), (SInt16)(154.20 * BIN4), (SInt16)(156.50 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(26.80 * BIN4),
(SInt16)(47.40 * BIN4), (SInt16)(77.40 * BIN4), (SInt16)(104.00 * BIN4),
(SInt16)(126.10 * BIN4), (SInt16)(155.00 * BIN4), (SInt16)(177.50 * BIN4),
(SInt16)(191.70 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(17.80 * BIN4),
(SInt16)(36.90 * BIN4), (SInt16)(61.70 * BIN4), (SInt16)(90.00 * BIN4),
(SInt16)(111.50 * BIN4), (SInt16)(148.60 * BIN4), (SInt16)(175.20 * BIN4),
(SInt16)(194.00 * BIN4), (SInt16)(203.70 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(25.70 * BIN4), (SInt16)(43.30 * BIN4), (SInt16)(70.30 * BIN4),
(SInt16)(92.00 * BIN4), (SInt16)(127.60 * BIN4), (SInt16)(158.40 * BIN4),
(SInt16)(179.30 * BIN4), (SInt16)(195.10 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(32.40 * BIN4), (SInt16)(52.30 * BIN4),
(SInt16)(76.70 * BIN4), (SInt16)(106.30 * BIN4), (SInt16)(142.20 * BIN4),
(SInt16)(161.70 * BIN4), (SInt16)(183.10 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(21.20 * BIN4), (SInt16)(33.90 * BIN4),
(SInt16)(54.20 * BIN4), (SInt16)(81.20 * BIN4), (SInt16)(109.60 * BIN4),
(SInt16)(134.00 * BIN4), (SInt16)(156.50 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(56.00 * BIN4), (SInt16)(84.50 * BIN4),
(SInt16)(112.30 * BIN4), (SInt16)(140.00 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOffProt_M
[TQDEM_NVECT_SIZE][TQDEM_NVECT_SIZE] = {
{
(SInt16)(-3.00 * BIN4), (SInt16)(57.90 * BIN4), (SInt16)(77.40 * BIN4),
(SInt16)(104.00 * BIN4), (SInt16)(123.11 * BIN4), (SInt16)(148.57 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(171.10 * BIN4), (SInt16)(177.10 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.00 * BIN4), (SInt16)(42.20 * BIN4), (SInt16)(66.20 * BIN4),
(SInt16)(94.30 * BIN4), (SInt16)(118.30 * BIN4), (SInt16)(145.20 * BIN4),
(SInt16)(153.15 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(158.00 * BIN4), (SInt16)(162.50 * BIN4),
(SInt16)(170.70 * BIN4), (SInt16)(176.00 * BIN4), (SInt16)(181.60 * BIN4),
(SInt16)(189.60 * BIN4) },
{
(SInt16)(-3.12 * BIN4), (SInt16)(31.30 * BIN4), (SInt16)(57.20 * BIN4),
(SInt16)(88.70 * BIN4), (SInt16)(113.80 * BIN4), (SInt16)(143.00 * BIN4),
(SInt16)(149.70 * BIN4), (SInt16)(155.40 * BIN4), (SInt16)(157.88 * BIN4),
(SInt16)(157.88 * BIN4), (SInt16)(157.88 * BIN4), (SInt16)(162.80 * BIN4),
(SInt16)(170.00 * BIN4), (SInt16)(174.10 * BIN4), (SInt16)(180.50 * BIN4),
(SInt16)(189.46 * BIN4) },
{
(SInt16)(-4.00 * BIN4), (SInt16)(19.70 * BIN4), (SInt16)(42.20 * BIN4),
(SInt16)(69.50 * BIN4), (SInt16)(100.00 * BIN4), (SInt16)(127.20 * BIN4),
(SInt16)(142.20 * BIN4), (SInt16)(154.20 * BIN4), (SInt16)(156.50 * BIN4),
(SInt16)(158.00 * BIN4), (SInt16)(160.00 * BIN4), (SInt16)(163.60 * BIN4),
(SInt16)(168.10 * BIN4), (SInt16)(173.30 * BIN4), (SInt16)(180.00 * BIN4),
(SInt16)(188.40 * BIN4) },
{
(SInt16)(-4.82 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(26.80 * BIN4),
(SInt16)(47.40 * BIN4), (SInt16)(77.40 * BIN4), (SInt16)(104.00 * BIN4),
(SInt16)(126.10 * BIN4), (SInt16)(155.00 * BIN4), (SInt16)(177.50 * BIN4),
(SInt16)(191.70 * BIN4), (SInt16)(200.84 * BIN4), (SInt16)(214.29 * BIN4),
(SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4), (SInt16)(217.86 * BIN4),
(SInt16)(241.90 * BIN4) },
{
(SInt16)(-5.63 * BIN4), (SInt16)(1.40 * BIN4), (SInt16)(17.80 * BIN4),
(SInt16)(36.90 * BIN4), (SInt16)(61.70 * BIN4), (SInt16)(90.00 * BIN4),
(SInt16)(111.50 * BIN4), (SInt16)(148.60 * BIN4), (SInt16)(175.20 * BIN4),
(SInt16)(194.00 * BIN4), (SInt16)(203.70 * BIN4), (SInt16)(227.24 * BIN4),
(SInt16)(238.48 * BIN4), (SInt16)(240.98 * BIN4), (SInt16)(240.98 * BIN4),
(SInt16)(258.40 * BIN4) },
{
(SInt16)(-6.97 * BIN4), (SInt16)(-1.20 * BIN4), (SInt16)(11.20 * BIN4),
(SInt16)(25.70 * BIN4), (SInt16)(43.30 * BIN4), (SInt16)(70.30 * BIN4),
(SInt16)(92.00 * BIN4), (SInt16)(127.60 * BIN4), (SInt16)(158.40 * BIN4),
(SInt16)(179.30 * BIN4), (SInt16)(195.10 * BIN4), (SInt16)(221.10 * BIN4),
(SInt16)(240.95 * BIN4), (SInt16)(248.03 * BIN4), (SInt16)(248.03 * BIN4),
(SInt16)(264.80 * BIN4) },
{
(SInt16)(-8.31 * BIN4), (SInt16)(-2.50 * BIN4), (SInt16)(9.50 * BIN4),
(SInt16)(17.04 * BIN4), (SInt16)(32.40 * BIN4), (SInt16)(52.30 * BIN4),
(SInt16)(76.70 * BIN4), (SInt16)(106.30 * BIN4), (SInt16)(142.20 * BIN4),
(SInt16)(161.70 * BIN4), (SInt16)(183.10 * BIN4), (SInt16)(215.23 * BIN4),
(SInt16)(242.31 * BIN4), (SInt16)(250.49 * BIN4), (SInt16)(255.08 * BIN4),
(SInt16)(269.50 * BIN4) },
{
(SInt16)(-10.53 * BIN4), (SInt16)(-5.00 * BIN4), (SInt16)(5.70 * BIN4),
(SInt16)(13.49 * BIN4), (SInt16)(21.20 * BIN4), (SInt16)(33.90 * BIN4),
(SInt16)(54.20 * BIN4), (SInt16)(81.20 * BIN4), (SInt16)(109.60 * BIN4),
(SInt16)(134.00 * BIN4), (SInt16)(156.50 * BIN4), (SInt16)(197.10 * BIN4),
(SInt16)(224.12 * BIN4), (SInt16)(240.94 * BIN4), (SInt16)(250.98 * BIN4),
(SInt16)(273.80 * BIN4) },
{
(SInt16)(-12.75 * BIN4), (SInt16)(-7.60 * BIN4), (SInt16)(2.70 * BIN4),
(SInt16)(9.24 * BIN4), (SInt16)(13.71 * BIN4), (SInt16)(22.28 * BIN4),
(SInt16)(34.55 * BIN4), (SInt16)(56.00 * BIN4), (SInt16)(84.50 * BIN4),
(SInt16)(112.30 * BIN4), (SInt16)(140.00 * BIN4), (SInt16)(183.00 * BIN4),
(SInt16)(211.32 * BIN4), (SInt16)(233.79 * BIN4), (SInt16)(246.87 * BIN4),
(SInt16)(275.30 * BIN4) },
{
(SInt16)(-14.81 * BIN4), (SInt16)(-10.00 * BIN4), (SInt16)(-2.00 * BIN4),
(SInt16)(2.50 * BIN4), (SInt16)(8.50 * BIN4), (SInt16)(16.74 * BIN4),
(SInt16)(26.72 * BIN4), (SInt16)(40.98 * BIN4), (SInt16)(60.96 * BIN4),
(SInt16)(91.28 * BIN4), (SInt16)(125.65 * BIN4), (SInt16)(169.53 * BIN4),
(SInt16)(202.85 * BIN4), (SInt16)(229.12 * BIN4), (SInt16)(243.22 * BIN4),
(SInt16)(275.50 * BIN4) },
{
(SInt16)(-16.87 * BIN4), (SInt16)(-11.50 * BIN4), (SInt16)(-5.80 * BIN4),
(SInt16)(-2.40 * BIN4), (SInt16)(3.60 * BIN4), (SInt16)(12.52 * BIN4),
(SInt16)(20.17 * BIN4), (SInt16)(32.03 * BIN4), (SInt16)(49.44 * BIN4),
(SInt16)(78.61 * BIN4), (SInt16)(113.71 * BIN4), (SInt16)(159.79 * BIN4),
(SInt16)(197.17 * BIN4), (SInt16)(223.76 * BIN4), (SInt16)(239.57 * BIN4),
(SInt16)(268.90 * BIN4) },
{
(SInt16)(-19.30 * BIN4), (SInt16)(-14.00 * BIN4), (SInt16)(-9.20 * BIN4),
(SInt16)(-6.20 * BIN4), (SInt16)(0.00 * BIN4), (SInt16)(7.30 * BIN4),
(SInt16)(15.07 * BIN4), (SInt16)(24.09 * BIN4), (SInt16)(38.43 * BIN4),
(SInt16)(65.31 * BIN4), (SInt16)(99.95 * BIN4), (SInt16)(143.24 * BIN4),
(SInt16)(179.72 * BIN4), (SInt16)(205.14 * BIN4), (SInt16)(223.20 * BIN4),
(SInt16)(260.00 * BIN4) },
{
(SInt16)(-22.30 * BIN4), (SInt16)(-18.10 * BIN4), (SInt16)(-14.00 * BIN4),
(SInt16)(-10.30 * BIN4), (SInt16)(-5.40 * BIN4), (SInt16)(1.00 * BIN4),
(SInt16)(8.10 * BIN4), (SInt16)(18.43 * BIN4), (SInt16)(30.78 * BIN4),
(SInt16)(56.71 * BIN4), (SInt16)(88.10 * BIN4), (SInt16)(126.99 * BIN4),
(SInt16)(164.05 * BIN4), (SInt16)(187.95 * BIN4), (SInt16)(202.53 * BIN4),
(SInt16)(236.50 * BIN4) },
{
(SInt16)(-25.60 * BIN4), (SInt16)(-21.90 * BIN4), (SInt16)(-18.10 * BIN4),
(SInt16)(-14.80 * BIN4), (SInt16)(-10.30 * BIN4), (SInt16)(-3.90 * BIN4),
(SInt16)(3.20 * BIN4), (SInt16)(11.80 * BIN4), (SInt16)(23.85 * BIN4),
(SInt16)(47.15 * BIN4), (SInt16)(75.87 * BIN4), (SInt16)(113.00 * BIN4),
(SInt16)(147.10 * BIN4), (SInt16)(169.60 * BIN4), (SInt16)(185.70 * BIN4),
(SInt16)(214.20 * BIN4) },
{
(SInt16)(-29.40 * BIN4), (SInt16)(-23.80 * BIN4), (SInt16)(-21.10 * BIN4),
(SInt16)(-18.10 * BIN4), (SInt16)(-14.40 * BIN4), (SInt16)(-7.70 * BIN4),
(SInt16)(-0.90 * BIN4), (SInt16)(7.00 * BIN4), (SInt16)(19.05 * BIN4),
(SInt16)(39.85 * BIN4), (SInt16)(65.26 * BIN4), (SInt16)(101.20 * BIN4),
(SInt16)(133.30 * BIN4), (SInt16)(157.20 * BIN4), (SInt16)(173.00 * BIN4),
(SInt16)(195.80 * BIN4) }
};
#define TQDEM_STOP_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQDEM_START_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facnengidl_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facsptspdaccp_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_raccpadp_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefcrev_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefchispdnorm_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefclowspd1_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefclospdnorm_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefcavrspdnorm_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefctakeoffeco_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefctakeoffnorm_m_sav[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqdem_tqckefctakeoffprot_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_facsptspdrataccp_t_sav;
STATIC VAR(t_dds_m_soft_trans_delta_u32_type, AUTOMATIC) f02_01_xped_xvv_soft_trans;
STATIC VAR(t_dds_m_soft_trans_delta_u32_type, AUTOMATIC) f02_03_02_soft_trans[TQDEM_TQCKEFC_VECT_SIZE];

#define TQDEM_STOP_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"


/* 32-bits variable definition */
#define TQDEM_START_SEC_VAR_32BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqdem_ivc_cont_current_time;
STATIC VAR(UInt32, AUTOMATIC) tqdem_ivc_cont_delta_time;
STATIC VAR(UInt32, AUTOMATIC) tqdem_ivc_cont_prev_time;
#define TQDEM_STOP_SEC_VAR_32BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_VAR_8BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) f02_03_02_soft_trans_init[TQDEM_TQCKEFC_VECT_SIZE];
STATIC VAR(UInt8, AUTOMATIC) f02_01_soft_trans_init;
#define TQDEM_STOP_SEC_VAR_8BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rAccP[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcMap[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcMapEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvEcoFirst[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvEcoSec[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcMapNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvNormFirst[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvNormSec[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvDeltaEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvDeltaNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDrvNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcHiSpdEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcHiSpdNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcLoSpdEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcLoSpdNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcAvrSpdEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcAvrSpdNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcRev[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOffEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOffNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcRvsTakeOffEco[TQDEM_TQCKEFC_VECT_SIZE]; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcRvsTakeOffNorm[TQDEM_TQCKEFC_VECT_SIZE]; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkTakeOffEco[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkTakeOffNorm[TQDEM_TQCKEFC_VECT_SIZE];
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcLossDelta_MP;
#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bEcoOn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bDrvLoSpdMap;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bDrvAvrSpdMap;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bDrvHiSpdMap;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bRvsMap;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bTakeOffMap;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bNormOn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_facAdpAccPOff_MP;
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQDEM_START_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_FACSPTSPDRATACCP_T_APM = {
&tqdem_facsptspdrataccp_t_sav,
TQDEM_SPDVEHRATSPT_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_spdVehRatSpt_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facSptSpdRatAccP_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_FACSPTSPDACCP_T_APM = {
&tqdem_facsptspdaccp_t_sav,
TQDEM_SPDVEHSPT_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_spdVehSpt_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_facSptSpdAccP_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQDEM_FACNENGIDL_T_APM = {
&tqdem_facnengidl_t_sav,
TQDEM_FAC_IDLNCK_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_facNEngIdl_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_facNEngIdl_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_RACCPADP_T_APM = {
&tqdem_raccpadp_t_sav,
TQDEM_NVECT_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_rAccPAdp_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCHISPDNORM_M_APM[TQDEM_TQCKEFC_VECT_SIZE] = {
{
  &tqdem_tqckefchispdnorm_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcHiSpdNorm_M[0][0]},
  {
  &tqdem_tqckefchispdnorm_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcHiSpdNorm_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCLOSPDECO_M_APM[TQDEM_TQCKEFC_VECT_SIZE] = {
{
  &tqdem_tqckefclowspd1_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcLoSpdEco_M[0][0]},
  {
  &tqdem_tqckefclowspd1_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcLoSpdEco_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCLOSPDNORM_M_APM[TQDEM_TQCKEFC_VECT_SIZE] = {
{
  &tqdem_tqckefclospdnorm_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcLoSpdNorm_M[0][0]},
  {&tqdem_tqckefclospdnorm_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcLoSpdNorm_M[0][0]}
};


STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCAVRSPDNORM_M_APM[TQDEM_TQCKEFC_VECT_SIZE] = {
{
  &tqdem_tqckefcavrspdnorm_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcAvrSpdNorm_M[0][0]},
  {
  &tqdem_tqckefcavrspdnorm_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcAvrSpdNorm_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCREV_M_APM[TQDEM_TQCKEFC_VECT_SIZE] =
{
  {&tqdem_tqckefcrev_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcRev_M[0][0]},
  {
  &tqdem_tqckefcrev_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcRev_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCTAKEOFFECO_M_APM[TQDEM_TQCKEFC_VECT_SIZE] =
{
  {&tqdem_tqckefctakeoffeco_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcTakeOffEco_M[0][0]},
  {
  &tqdem_tqckefctakeoffeco_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcTakeOffEco_M[0][0]}
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCTAKEOFFNORM_M_APM[TQDEM_TQCKEFC_VECT_SIZE] = {
{
  &tqdem_tqckefctakeoffnorm_m_sav[0],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcTakeOffNorm_M[0][0]},
  {
  &tqdem_tqckefctakeoffnorm_m_sav[1],
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcTakeOffNorm_M[0][0]}
};



STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQDEM_TQCKEFCTAKEOFFPROT_M_APM =
{
  &tqdem_tqckefctakeoffprot_m_sav,
  TQDEM_NVECT_SIZE ,
  TQDEM_NVECT_SIZE ,
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_rAccPX_A[0],
  (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfc_nEngY_A[0],
  (P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqDem_tqCkEfcTakeOffProt_M[0][0]
};

#define TQDEM_STOP_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Interpolations_Cartos (
                  UInt16 accp_raccp_par,        /* BIN7 */
                  UInt16 eng_nckfil_par,
                  UInt16 tqdem_rdrivtakeoff_par,
                  UInt16 tqdem_rtraneconorm_par,
                  UInt8  tqdem_idxmaptrandrvfirst_par,
                  UInt8  tqdem_idxmaptrandrvsec_par,
                  UInt8  tqdem_idxmaprvsdrv_par,
                  UInt8 copt_bacvprotclup_par,
                  UInt8 ext_bmodspt_par,
                  UInt8 copt_noegdgearcord_par,
                  UInt8 frm_binhtqdemsptmod_par,
                  UInt8 tqsys_binhtqdemsptmod_par,
                  UInt32 copt_spdvehgearratcord_par,
                  UInt16 veh_spdveh_par,
                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bmodspt_ptr,
                  CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_raccpsptmod_ptr
                  );

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Transitions (
                  UInt8 tqdem_bacvnregtakeoff_par,
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffeco_par, /* BIN4 */
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffnorm_par, /* BIN4 */
                  UInt16 tqdem_rdrivtakeoff_par,
                  UInt16 tqdem_rtraneconorm_par,
                  UInt16 tqdem_rtrandrv_par,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqcktakeoffmap_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltaeconorm_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltatakeoff_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_IVC1 (
                  UInt16 accp_raccp_par, /* BIN7 */
                  UInt16 eng_nckfil_par, /* BIN2 */
                  SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                  UInt16 tqsys_ntaridl_par, /* BIN2 */
                  SInt16 dzone_tqefcdiflrnout_par,
                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_btqgrdlim_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefc_ptr, /* BIN4 */
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcmax_ptr, /* BIN4 */
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcmin_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcwoutantidb_ptr);


INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_xPed_xVV ( UInt16 accp_raccp_par,
                                                UInt8 copt_bacvprotclup_par,
                                                UInt16 tqdem_rdrivtakeoff_par,
                                                UInt8 ext_bmodspt_par,
                                                UInt8 copt_noegdgearcord_par,
                                                UInt8 frm_binhtqdemsptmod_par,
                                                UInt8 tqsys_binhtqdemsptmod_par,
                                                UInt32 copt_spdvehgearratcord_par,
                                                UInt16 veh_spdveh_par,
                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bmodspt_ptr,
                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_raccpsptmod_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Choix_Indice (UInt16 tqdem_rdrivtakeoff_par,
                                 UInt16 tqdem_rtraneconorm_par,
                                 UInt8  tqdem_idxmaptrandrvfirst_par,
                                 UInt8  tqdem_idxmaptrandrvsec_par,
                                 UInt8  tqdem_idxmaprvsdrv_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Choix_Cartos ( UInt16 eng_nckfil_par,
                                                            UInt16 accp_raccp_par, /* BIN7 */
                                                            UInt8 copt_bacvprotclup_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Choix_Couple (UInt8  tqdem_idxmaptrandrvfirst_par,
                                 UInt8  tqdem_idxmaptrandrvsec_par,
                                 UInt8  tqdem_idxmaprvsdrv_par);


INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Trans_Roul (
                  UInt8 tqdem_bacvnregtakeoff_par,
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffeco_par, /* BIN4 */
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffnorm_par, /* BIN4 */
                  UInt16 tqdem_rtrandrv_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Trans_Deco (UInt16 tqdem_rdrivtakeoff_par,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltaeconorm_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Trans_Green (UInt16 tqdem_rtraneconorm_par,
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltatakeoff_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_Tqdem_Tqcka (UInt8  tqdem_idxmaptrandrvfirst_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_Tqdem_Tqckb (UInt8  tqdem_idxmaptrandrvsec_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_TqDem_tqCkTakeOff_1c_2c(UInt8  tqdem_idxmaprvsdrv_par);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Ivc_Content(SInt16 DZone_tqEfcDifLrnOut_swc_in, /* BIN4 */
                                           UInt8 TqDem_bAcvNRegTakeOff_swc_in,
                                           CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffEco_swc_in, /* tab[] BIN4 */
                                           CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqEfcNRegTakeOffNorm_swc_in, /* tab[] BIN4 */
                                           UInt16 TqDem_rDrivTakeOff_swc_in, /* BIN10 */
                                           UInt8 TqDem_idxMapRvsDrv_swc_in, /* BIN0 */
                                           UInt8 TqDem_idxMapTranDrvFirst_swc_in, /* BIN0 */
                                           UInt8 TqDem_idxMapTranDrvSec_swc_in, /* BIN0 */
                                           UInt16 TqDem_rTranDrv_swc_in, /* BIN10 */
                                           UInt16 TqDem_rTranEcoNorm_swc_in, /* BIN10 */
                                           UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           UInt8 CoPt_bAcvProtCluP_swc_in,
                                           UInt8 CoPt_noEgdGearCord_swc_in,
                                           UInt32 CoPt_spdVehGearRatCord_swc_in, /* BIN10 */
                                           UInt8 Ext_bModSpt_swc_in,
                                           UInt8 FRM_bInhTqDemSptMod_swc_in,
                                           UInt8 TqSys_bInhTqDemSptMod_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bTqGrdLim_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfc_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMin_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkTakeOffMap_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bModSpt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rAccPSptMod_swc_out, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaTakeOff_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaEcoNorm_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcWoutAntiDB_swc_out /* BIN4 */)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.1.1 */

TQDEM_Ivc_Content_Interpolations_Cartos (
                        AccP_rAccP_swc_in,        /* BIN7 */
                        Eng_nCkFil_swc_in,
                        TqDem_rDrivTakeOff_swc_in,
                        TqDem_rTranEcoNorm_swc_in,
                        TqDem_idxMapTranDrvFirst_swc_in,
                        TqDem_idxMapTranDrvSec_swc_in,
                        TqDem_idxMapRvsDrv_swc_in,
                        CoPt_bAcvProtCluP_swc_in,
                        Ext_bModSpt_swc_in,
                        CoPt_noEgdGearCord_swc_in,
                        FRM_bInhTqDemSptMod_swc_in,
                        TqSys_bInhTqDemSptMod_swc_in,
                        CoPt_spdVehGearRatCord_swc_in,
                        Veh_spdVeh_swc_in,
                        TqDem_bModSpt_swc_out,
                        TqDem_rAccPSptMod_swc_out
                  );


  TQDEM_Ivc_Content_Transitions (
                TqDem_bAcvNRegTakeOff_swc_in,
                TqDem_tqEfcNRegTakeOffEco_swc_in, /* BIN4 */
                TqDem_tqEfcNRegTakeOffNorm_swc_in, /* BIN4 */
                TqDem_rDrivTakeOff_swc_in,
                TqDem_rTranEcoNorm_swc_in,
                TqDem_rTranDrv_swc_in,
                TqDem_tqCkTakeOffMap_swc_out,
                TqDem_tqCkEfcDeltaEcoNorm_swc_out,
                TqDem_tqCkEfcDeltaTakeOff_swc_out);

  TQDEM_Ivc_Content_IVC1 (
                AccP_rAccP_swc_in, /* BIN7 */
                Eng_nCkFil_swc_in, /* BIN2 */
                TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                TqSys_nTarIdl_swc_in, /* BIN2 */
                DZone_tqEfcDifLrnOut_swc_in,
                TqDem_bTqGrdLim_swc_out,
                TqDem_tqCkEfc_swc_out, /* BIN4 */
                TqDem_tqCkEfcMax_swc_out, /* BIN4 */
                TqDem_tqCkEfcMin_swc_out,
                TqDem_tqCkEfcWoutAntiDB_swc_out);


}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Interpolations_Cartos
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Interpolations_Cartos (
                  UInt16 accp_raccp_par,        /* BIN7 */
                  UInt16 eng_nckfil_par,
                  UInt16 tqdem_rdrivtakeoff_par,
                  UInt16 tqdem_rtraneconorm_par,
                  UInt8  tqdem_idxmaptrandrvfirst_par,
                  UInt8  tqdem_idxmaptrandrvsec_par,
                  UInt8  tqdem_idxmaprvsdrv_par,
                  UInt8 copt_bacvprotclup_par,
                  UInt8 ext_bmodspt_par,
                  UInt8 copt_noegdgearcord_par,
                  UInt8 frm_binhtqdemsptmod_par,
                  UInt8 tqsys_binhtqdemsptmod_par,
                  UInt32 copt_spdvehgearratcord_par,
                  UInt16 veh_spdveh_par,
                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bmodspt_ptr,
                  CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_raccpsptmod_ptr
                  )
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.2.1 */

    tqdem_ivc_cont_current_time = DDS_TQDEM_1MS_U32_TIME;
    tqdem_ivc_cont_delta_time = tqdem_ivc_cont_current_time - tqdem_ivc_cont_prev_time;
    tqdem_ivc_cont_delta_time = DDS_M_MIN(tqdem_ivc_cont_delta_time, (2 * TQDEM_IVC_CONT_SCHED));

    tqdem_ivc_cont_prev_time = tqdem_ivc_cont_current_time;

    TQDEM_Ivc_xPed_xVV (accp_raccp_par,
                        copt_bacvprotclup_par,
                        tqdem_rdrivtakeoff_par,
                        ext_bmodspt_par,
                        copt_noegdgearcord_par,
                        frm_binhtqdemsptmod_par,
                        tqsys_binhtqdemsptmod_par,
                        copt_spdvehgearratcord_par,
                        veh_spdveh_par,
                        tqdem_bmodspt_ptr,
                        tqdem_raccpsptmod_ptr);

    TQDEM_Ivc_Content_Choix_Indice (tqdem_rdrivtakeoff_par,
                                  tqdem_rtraneconorm_par,
                                  tqdem_idxmaptrandrvfirst_par,
                                  tqdem_idxmaptrandrvsec_par,
                                  tqdem_idxmaprvsdrv_par);

    TQDEM_Ivc_Content_Choix_Cartos ( eng_nckfil_par,
                                accp_raccp_par, /* BIN7 */
                                copt_bacvprotclup_par);

    TQDEM_Ivc_Content_Choix_Couple (tqdem_idxmaptrandrvfirst_par,
                                  tqdem_idxmaptrandrvsec_par,
                                  tqdem_idxmaprvsdrv_par);

}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_xPed_xVV
* Description :   Calculation of TqDem_rAccP
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_xPed_xVV ( UInt16 accp_raccp_par,
                                                UInt8 copt_bacvprotclup_par,
                                                UInt16 tqdem_rdrivtakeoff_par,
                                                UInt8 ext_bmodspt_par,
                                                UInt8 copt_noegdgearcord_par,
                                                UInt8 frm_binhtqdemsptmod_par,
                                                UInt8 tqsys_binhtqdemsptmod_par,
                                                UInt32 copt_spdvehgearratcord_par,
                                                UInt16 veh_spdveh_par,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bmodspt_ptr,
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_raccpsptmod_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.3.1 */
    UInt32 out_swith_and, f02_01_in_sat;
    UInt16 in2_trans_tmp, out_trans_tmp, in_axis_spdvehgearratcord;

    /*Calc of TqDem_bModSpt*/

    switch((UInt32)TqDem_stAuthSptMod_C)
    {
        case TQDEM_STAUTHSPTMOD_0:
            out_swith_and = (UInt32)0;
            break;

        case TQDEM_STAUTHSPTMOD_1:
            out_swith_and = (UInt32)copt_bacvprotclup_par;
            break;

        case TQDEM_STAUTHSPTMOD_2:
            if(((UInt32)tqdem_rdrivtakeoff_par < (UInt32)(1*BIN10))&&((UInt32)DDS_FALSE != (UInt32)copt_bacvprotclup_par))
            {
            out_swith_and = (UInt32)1;
            }
            else
            {
            out_swith_and = (UInt32)0;
            }
            break;

        default:
            out_swith_and = (UInt32)0;
            break;
    }
    if(
        ((UInt32)DDS_FALSE != (UInt32)ext_bmodspt_par)&&
        ((UInt32)copt_noegdgearcord_par != (UInt32)7)&&
        ((UInt32)DDS_FALSE == out_swith_and)&&
        ((UInt32)DDS_FALSE == (UInt32)frm_binhtqdemsptmod_par)&&
        ((UInt32)DDS_FALSE == (UInt32)tqsys_binhtqdemsptmod_par)&&
        ((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPThdAcvSptMod_C))
    {
        *tqdem_bmodspt_ptr = DDS_TRUE;
    }
    else
    {
        *tqdem_bmodspt_ptr = DDS_FALSE;
    }

    if((UInt32)TqDem_bTypSptSel_C != (UInt32)DDS_FALSE)
    {
        /* [0;255]BIN8*/
        in_axis_spdvehgearratcord = (UInt16)(copt_spdvehgearratcord_par / (UInt32)BIN2);
        /* BIN7 = BIN4 * BIN3 */
        in2_trans_tmp = (UInt16)((UInt32)DDS_M_MAP2D_U16(&TQDEM_FACSPTSPDRATACCP_T_APM, in_axis_spdvehgearratcord) * BIN3);
    }
    else
    {
        /* BIN7 = BIN4 * BIN3 */
        /*[0;3]*/
        in2_trans_tmp = (UInt16)((UInt32)DDS_M_MAP2D_U16(&TQDEM_FACSPTSPDACCP_T_APM, veh_spdveh_par) * BIN3);
    }

    if((UInt32)DDS_FALSE == (UInt32)f02_01_soft_trans_init)
    {
        out_trans_tmp = (UInt16)DDS_M_SOFT_TRANS_DELTA_U32_INIT(*tqdem_bmodspt_ptr,                     /* E Boolean */
                                                (UInt32)1 * BIN7,                       /* Val 0 */
                                                (UInt32)in2_trans_tmp,                  /* Val 1 BIN7[0;3] */
                                                DDS_NULL_PTR,                           /* Tup */
                                                &f02_01_xped_xvv_soft_trans);           /* Pointer to structure */
        f02_01_soft_trans_init = DDS_TRUE;
    }
    else
    {
        /*BIN7*/
        out_trans_tmp = (UInt16)DDS_M_SOFT_TRANS_DELTA_U32(*tqdem_bmodspt_ptr,                  /* E Boolean */
                                                         (UInt32)1 * BIN7,                      /* Val 0 */
                                                         (UInt32)in2_trans_tmp,                 /* Val 1 BIN7[0;3] */
                                                         tqdem_ivc_cont_delta_time,                 /* Delta time */
                                                         ((UInt32)TqDem_tiTranSptOn_C * DEC1),      /* Tup */
                                                         ((UInt32)TqDem_tiTranSptOff_C * DEC1), /* Tdown  */
                                                         &f02_01_xped_xvv_soft_trans);      /* Pointer to structure */
     }

    /*[0;300]BIN14  [0;3]BIN7    *  [0;100]BIN7 */
    f02_01_in_sat = (UInt32)out_trans_tmp * (UInt32)accp_raccp_par;
    /*[0;300]BIN7*/
    f02_01_in_sat = f02_01_in_sat / BIN7;


    /*Calc of TqDem_rAccPSptMod*/

    *tqdem_raccpsptmod_ptr = (UInt16)DDS_M_SATURATION_V2(f02_01_in_sat,
                                                        (UInt32)(0*BIN7),
                                                        (UInt32)(100*BIN7));

    /*Calc of TqDem_rAccP*/
    TqDem_rAccP[0] = *tqdem_raccpsptmod_ptr;
    TqDem_rAccP[1] = (UInt16)(100 * BIN7);
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Choix_Indice
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Choix_Indice (UInt16 tqdem_rdrivtakeoff_par,
                                 UInt16 tqdem_rtraneconorm_par,
                                 UInt8  tqdem_idxmaptrandrvfirst_par,
                                 UInt8  tqdem_idxmaptrandrvsec_par,
                                 UInt8  tqdem_idxmaprvsdrv_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.4.1 */

  TqDem_bDrvLoSpdMap = (UInt8)(((UInt32)tqdem_idxmaptrandrvsec_par == 1) || ((UInt32)tqdem_idxmaptrandrvfirst_par == 1));
  TqDem_bDrvAvrSpdMap = (UInt8)(((UInt32)tqdem_idxmaptrandrvsec_par == 2) || ((UInt32)tqdem_idxmaptrandrvfirst_par == 2));
  TqDem_bDrvHiSpdMap = (UInt8)(((UInt32)tqdem_idxmaptrandrvsec_par == 3) || ((UInt32)tqdem_idxmaptrandrvfirst_par == 3));
  TqDem_bNormOn = (UInt8)((UInt32)tqdem_rtraneconorm_par > (0 * BIN10));
  TqDem_bEcoOn = (UInt8)((UInt32)tqdem_rtraneconorm_par < (1 * BIN10));
  TqDem_bRvsMap = (UInt8)(((UInt32)tqdem_idxmaptrandrvfirst_par == 4) || ((UInt32)tqdem_idxmaprvsdrv_par == 4));
  TqDem_bTakeOffMap = (UInt8)(((UInt32)tqdem_idxmaprvsdrv_par == 5) && ((UInt32)tqdem_rdrivtakeoff_par < (1 * BIN10) ));
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Choix_Cartos
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Choix_Cartos ( UInt16 eng_nckfil_par,
                                                            UInt16 accp_raccp_par, /* BIN7 */
                                                            UInt8 copt_bacvprotclup_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.5.2 */
    /* Requirement updated */

    UInt32 i;
    UInt32 f02_03_02_val0, f02_03_02_val1;
    SInt32 out_trans_temp;

    /* offset of 2000 * BIN4 on the 2 inputs of DDS_M_SOFT_TRANS_DELTA_U32 */
    /* because the macro exists only in UInt32 (not in SInt32) */
    /* this offset is possible because the macro DDS_M_SOFT_TRANS_DELTA_U32 is linear : */
    /* DDS_M_SOFT_TRANS_DELTA_U32(In1 + Offset, In2 + Offset, ...) - Offset = DDS_M_SOFT_TRANS_DELTA_U32(In1, In2, ...) */

    /*val1*/
    /*[0;4000]BIN4=[-2000;2000]BIN4 + [0;2000]BIN4*/
    f02_03_02_val1 = (UInt32)((SInt32)DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCTAKEOFFPROT_M_APM,
                                                          accp_raccp_par,
                                                        eng_nckfil_par)+
                                                        ((SInt32)(2000 * BIN4)));

    for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
    {
        /*val0*/
        /*[0;4000]BIN4=[-2000;2000]BIN4 + [0;2000]BIN4*/
        f02_03_02_val0 = (UInt32)((SInt32)DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCTAKEOFFNORM_M_APM[i],
                                                            TqDem_rAccP[i],
                                                            eng_nckfil_par)+
                                                            ((SInt32)(2000 * BIN4)));
        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.7.1 */
        if(((UInt32)DDS_FALSE != (UInt32)TqDem_bTakeOffMap) && ((UInt32)DDS_FALSE != (UInt32)TqDem_bNormOn))
        {
            if((UInt32)DDS_FALSE == (UInt32)f02_03_02_soft_trans_init[i])
            {
                out_trans_temp = (SInt32)DDS_M_SOFT_TRANS_DELTA_U32_INIT(copt_bacvprotclup_par,                                     /* E Boolean */
                                                    f02_03_02_val0,                     /* Val 0 */
                                                    f02_03_02_val1,                     /* Val 1 */
                                                    DDS_NULL_PTR,
                                                    &f02_03_02_soft_trans[i]);
                f02_03_02_soft_trans_init[i] = DDS_TRUE;
            }
            else
            {
                /*[0;4000]BIN4*/
                 out_trans_temp = (SInt32)DDS_M_SOFT_TRANS_DELTA_U32(copt_bacvprotclup_par,                                     /* E Boolean */
                                                                     f02_03_02_val0,                        /* Val 0 */
                                                                     f02_03_02_val1,                        /* Val 1 */
                                                                     tqdem_ivc_cont_delta_time,                     /* Delta time */
                                                                     ((UInt32)TqDem_tiTranProtCluPOn_C * DEC1),     /* Tup */
                                                                     ((UInt32)TqDem_tiTranProtCluPOff_C * DEC1),    /* Tdown UInt16 DEC2 [0;5] */
                                                                     &f02_03_02_soft_trans[i]);             /* Pointer to structure */
            }

            /*[-2000;2000]BIN4 =[0;4000]BIN4 - 2000BIN4*/
            out_trans_temp = out_trans_temp - (SInt32)(2000*BIN4);

            TqDem_tqCkEfcTakeOffNorm[i]  = (SInt16)out_trans_temp;
        }

        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.8.2 */
        if(((UInt32)DDS_FALSE != (UInt32)TqDem_bDrvLoSpdMap) && ((UInt32)DDS_FALSE != (UInt32)TqDem_bNormOn))
        {
            TqDem_tqCkEfcLoSpdNorm[i]  = DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCLOSPDNORM_M_APM[i],
                                                       TqDem_rAccP[i],
                                                       eng_nckfil_par);
        }

        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.9.2 */
        if(((UInt32)DDS_FALSE != (UInt32)TqDem_bDrvAvrSpdMap) && ((UInt32)DDS_FALSE != (UInt32)TqDem_bNormOn))
        {
            TqDem_tqCkEfcAvrSpdNorm[i]  = DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCAVRSPDNORM_M_APM[i],
                                                       TqDem_rAccP[i],
                                                       eng_nckfil_par);
        }

        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.10.2 */
        if(((UInt32)DDS_FALSE != (UInt32)TqDem_bDrvHiSpdMap) && ((UInt32)DDS_FALSE != (UInt32)TqDem_bNormOn))
        {
            TqDem_tqCkEfcHiSpdNorm[i]  = DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCHISPDNORM_M_APM[i],
                                                      TqDem_rAccP[i],
                                                      eng_nckfil_par);
        }

        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.6.2 */
        if ((UInt32)DDS_FALSE != (UInt32)TqDem_bRvsMap)
        {
            TqDem_tqCkEfcRev[i]  = DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCREV_M_APM[i],
                                                   TqDem_rAccP[i],
                                                   eng_nckfil_par);
        }

        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.11.2 */
        if(((UInt32)DDS_FALSE != (UInt32)TqDem_bTakeOffMap) && ((UInt32)DDS_FALSE != (UInt32)TqDem_bEcoOn))
        {
            TqDem_tqCkEfcTakeOffEco[i]  = DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCTAKEOFFECO_M_APM[i],
                                                        TqDem_rAccP[i],
                                                        eng_nckfil_par);
        }

        /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.12.1 */
        if(((UInt32)DDS_FALSE != (UInt32)TqDem_bEcoOn)
        &&(((UInt32)DDS_FALSE != (UInt32)TqDem_bDrvLoSpdMap)
         ||((UInt32)DDS_FALSE != (UInt32)TqDem_bDrvHiSpdMap)
         ||((UInt32)DDS_FALSE != (UInt32)TqDem_bDrvAvrSpdMap) ) )
        {
            TqDem_tqCkEfcLoSpdEco[i] = DDS_M_MAP3D_UUS16(&TQDEM_TQCKEFCLOSPDECO_M_APM[i],
                                                       TqDem_rAccP[i],
                                                       eng_nckfil_par);

            TqDem_tqCkEfcAvrSpdEco[i] = TqDem_tqCkEfcLoSpdEco[i];

            TqDem_tqCkEfcHiSpdEco[i] = TqDem_tqCkEfcLoSpdEco[i];
        }
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Choix_Couple
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Choix_Couple (UInt8  tqdem_idxmaptrandrvfirst_par,
                                 UInt8  tqdem_idxmaptrandrvsec_par,
                                 UInt8  tqdem_idxmaprvsdrv_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.15.0 */

  TQDEM_Calc_Tqdem_Tqcka(tqdem_idxmaptrandrvfirst_par);
  TQDEM_Calc_Tqdem_Tqckb(tqdem_idxmaptrandrvsec_par);
  TQDEM_Calc_TqDem_tqCkTakeOff_1c_2c(tqdem_idxmaprvsdrv_par);
}

/*******************************************************************************
*
* Function Name : Local_Function
* Description : Calculate TqDem_tqCkEfcDrvEcoFirst, TqDem_tqCkEfcDrvNormFirst

*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_Tqdem_Tqcka (UInt8 tqdem_idxmaptrandrvfirst_par)
{
  UInt32 i;

  switch((UInt32)tqdem_idxmaptrandrvfirst_par)
  {
    case TQDEM_1:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoFirst[i] = TqDem_tqCkEfcLoSpdEco[i];
        TqDem_tqCkEfcDrvNormFirst[i] = TqDem_tqCkEfcLoSpdNorm[i];
      }
    break;

    case TQDEM_2:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoFirst[i] = TqDem_tqCkEfcAvrSpdEco[i];
        TqDem_tqCkEfcDrvNormFirst[i] = TqDem_tqCkEfcAvrSpdNorm[i];
      }
    break;

    case TQDEM_3:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoFirst[i] = TqDem_tqCkEfcHiSpdEco[i];
        TqDem_tqCkEfcDrvNormFirst[i] = TqDem_tqCkEfcHiSpdNorm[i];
      }
    break;

    case TQDEM_4:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoFirst[i] = TqDem_tqCkEfcRev[i];
        TqDem_tqCkEfcDrvNormFirst[i] = TqDem_tqCkEfcRev[i];
      }
    break;

    default:
    /* ini = 1 */
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoFirst[i] = TqDem_tqCkEfcLoSpdEco[i];
        TqDem_tqCkEfcDrvNormFirst[i] = TqDem_tqCkEfcLoSpdNorm[i];
      }
    break;
    }
}

/*******************************************************************************
*
* Function Name : Local_Function
* Description : Calculate TqDem_tqCkEfcDrvEcoSec, TqDem_tqCkEfcDrvNormSec
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_Tqdem_Tqckb (UInt8  tqdem_idxmaptrandrvsec_par)
{
  UInt32 i;

  switch((UInt32)tqdem_idxmaptrandrvsec_par)
  {
    case TQDEM_1:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoSec[i] = TqDem_tqCkEfcLoSpdEco[i];
        TqDem_tqCkEfcDrvNormSec[i] = TqDem_tqCkEfcLoSpdNorm[i];
      }
    break;

    case TQDEM_2:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoSec[i] = TqDem_tqCkEfcAvrSpdEco[i];
        TqDem_tqCkEfcDrvNormSec[i] = TqDem_tqCkEfcAvrSpdNorm[i];
      }
    break;

    case TQDEM_3:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoSec[i] = TqDem_tqCkEfcHiSpdEco[i];
        TqDem_tqCkEfcDrvNormSec[i] = TqDem_tqCkEfcHiSpdNorm[i];
      }
    break;

    case TQDEM_4:
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoSec[i] = TqDem_tqCkEfcRev[i];
        TqDem_tqCkEfcDrvNormSec[i] = TqDem_tqCkEfcRev[i];
      }
    break;

    default:
    /* ini = 1 */
      for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
      {
        TqDem_tqCkEfcDrvEcoSec[i] = TqDem_tqCkEfcLoSpdEco[i];
        TqDem_tqCkEfcDrvNormSec[i] = TqDem_tqCkEfcLoSpdNorm[i];
      }
     break;
    }
}

/*******************************************************************************
*
* Function Name : Local_Function
* Description : Calculate TqDem_tqCkEfcRvsTakeOffEco & TqDem_tqCkEfcRvsTakeOffNorm
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_TqDem_tqCkTakeOff_1c_2c(UInt8  tqdem_idxmaprvsdrv_par)
{
  UInt32 i;

  if( (UInt32)tqdem_idxmaprvsdrv_par == 4)
  {
    for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
    {
      TqDem_tqCkEfcRvsTakeOffEco[i] = TqDem_tqCkEfcRev[i];
      TqDem_tqCkEfcRvsTakeOffNorm[i] = TqDem_tqCkEfcRev[i];
    }
  }
  else
  {
    for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
    {
      TqDem_tqCkEfcRvsTakeOffEco[i] = TqDem_tqCkEfcTakeOffEco[i];
      TqDem_tqCkEfcRvsTakeOffNorm[i] = TqDem_tqCkEfcTakeOffNorm[i];
    }
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Transitions
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Transitions (
                  UInt8 tqdem_bacvnregtakeoff_par,
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffeco_par, /* BIN4 */
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffnorm_par, /* BIN4 */
                  UInt16 tqdem_rdrivtakeoff_par,
                  UInt16 tqdem_rtraneconorm_par,
                  UInt16 tqdem_rtrandrv_par,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqcktakeoffmap_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltaeconorm_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltatakeoff_ptr)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.16.1 */

  *tqdem_tqcktakeoffmap_ptr = TqDem_tqCkEfcRvsTakeOffNorm[0];

  TQDEM_Ivc_Content_Trans_Roul (tqdem_bacvnregtakeoff_par,
                                tqdem_tqefcnregtakeoffeco_par, /* BIN4 */
                                tqdem_tqefcnregtakeoffnorm_par, /* BIN4 */
                                tqdem_rtrandrv_par);

  TQDEM_Ivc_Trans_Deco (tqdem_rdrivtakeoff_par,
                        tqdem_tqckefcdeltaeconorm_ptr);

  TQDEM_Ivc_Trans_Green (tqdem_rtraneconorm_par,
                         tqdem_tqckefcdeltatakeoff_ptr);
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Trans_Roul
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Trans_Roul (
                  UInt8 tqdem_bacvnregtakeoff_par,
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffeco_par, /* BIN4 */
                  CONSTP2CONST(SInt16, AUTOMATIC, AUTOMATIC)  tqdem_tqefcnregtakeoffnorm_par, /* BIN4 */
                  UInt16 tqdem_rtrandrv_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.17.0 */

  UInt32 i;
  SInt32 sub1, sub2;

  for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
  {
    TqDem_tqCkEfcDrvNorm[i] = DDS_M_BARY_FILTER_S16(TqDem_tqCkEfcDrvNormSec[i],
                                                  TqDem_tqCkEfcDrvNormFirst[i],
                                                  (SInt16)tqdem_rtrandrv_par,
                                                  BIN10);

    TqDem_tqCkEfcDrvEco[i] = DDS_M_BARY_FILTER_S16(TqDem_tqCkEfcDrvEcoSec[i],
                                                  TqDem_tqCkEfcDrvEcoFirst[i],
                                                  (SInt16)tqdem_rtrandrv_par,
                                                  BIN10);
    if( (UInt32)DDS_FALSE != (UInt32)tqdem_bacvnregtakeoff_par)
    {
      TqDem_tqCkTakeOffNorm[0] = tqdem_tqefcnregtakeoffnorm_par[0];
      TqDem_tqCkTakeOffNorm[1] = tqdem_tqefcnregtakeoffnorm_par[1];
      TqDem_tqCkTakeOffEco[0] = tqdem_tqefcnregtakeoffeco_par[0];
      TqDem_tqCkTakeOffEco[1] = tqdem_tqefcnregtakeoffeco_par[1];
    }
    else
    {
      TqDem_tqCkTakeOffNorm[i] = TqDem_tqCkEfcRvsTakeOffNorm[i];
      TqDem_tqCkTakeOffEco[i] = TqDem_tqCkEfcRvsTakeOffEco[i];
    }

    /* BIN4 = BIN4 - BIN4 */
    /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000] */
    sub2 = (SInt32)TqDem_tqCkTakeOffNorm[i] - (SInt32)TqDem_tqCkEfcDrvNorm[i];
    TqDem_tqCkEfcDrvDeltaNorm[i] = (SInt16)DDS_M_LIMIT(sub2,
                                                 (SInt32)(-2000 * BIN4),
                                                 (SInt32)( 2000 * BIN4));
    /* BIN4 = BIN4 - BIN4 */
    /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000] */
    sub1 = (SInt32)TqDem_tqCkTakeOffEco[i] - (SInt32)TqDem_tqCkEfcDrvEco[i];
    TqDem_tqCkEfcDrvDeltaEco[i] = (SInt16)DDS_M_LIMIT(sub1,
                                                 (SInt32)(-2000 * BIN4),
                                                 (SInt32)( 2000 * BIN4));
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Trans_Deco
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Trans_Deco (UInt16 tqdem_rdrivtakeoff_par,
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltaeconorm_ptr)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.18.0 */

  UInt32 i;
  SInt32 delta_1_2;

  for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
  {
    TqDem_tqCkEfcMapEco[i] = DDS_M_BARY_FILTER_S16( TqDem_tqCkEfcDrvEco[i],
                                            TqDem_tqCkTakeOffEco[i],
                                            (SInt16)tqdem_rdrivtakeoff_par,
                                            BIN10);

    TqDem_tqCkEfcMapNorm[i] = DDS_M_BARY_FILTER_S16( TqDem_tqCkEfcDrvNorm[i],
                                            TqDem_tqCkTakeOffNorm[i],
                                            (SInt16)tqdem_rdrivtakeoff_par,
                                            BIN10);
  }
  /* BIN4 = BIN4 - BIN4 */
  /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000] */
  delta_1_2 = (SInt32)TqDem_tqCkEfcMapEco[0] - (SInt32)TqDem_tqCkEfcMapNorm[0];
  *tqdem_tqckefcdeltaeconorm_ptr = (SInt16)DDS_M_LIMIT(delta_1_2,
                                                  (SInt32)(-2000 * BIN4),
                                                  (SInt32)( 2000 * BIN4));
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Trans_Green
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Trans_Green (UInt16 tqdem_rtraneconorm_par,
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcdeltatakeoff_ptr)
{
  /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.19.0 */

  UInt32 i;

  /* selector */
  *tqdem_tqckefcdeltatakeoff_ptr = DDS_M_BARY_FILTER_S16( TqDem_tqCkEfcDrvDeltaNorm[0],
                                                          TqDem_tqCkEfcDrvDeltaEco[0],
                                                          (SInt16)tqdem_rtraneconorm_par,
                                                          BIN10);

  for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
  {
    TqDem_tqCkEfcMap[i] = DDS_M_BARY_FILTER_S16( TqDem_tqCkEfcMapNorm[i],
                                           TqDem_tqCkEfcMapEco[i],
                                           (SInt16)tqdem_rtraneconorm_par,
                                           BIN10);
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_IVC1
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_IVC1 (
                  UInt16 accp_raccp_par, /* BIN7 */
                  UInt16 eng_nckfil_par, /* BIN2 */
                  SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                  UInt16 tqsys_ntaridl_par, /* BIN2 */
                  SInt16 dzone_tqefcdiflrnout_par,
                  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_btqgrdlim_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefc_ptr, /* BIN4 */
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcmax_ptr, /* BIN4 */
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcmin_ptr,
                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqdem_tqckefcwoutantidb_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_0062.FR.20.1 */

    SInt16 tqdem_tqck_current;
    SInt32 result_add1, result_div_secure;
    SInt32 map_out_fac_idlnck_t, result_mux, num_div_secure, denum_div_secure;
    UInt16 result_map_eng_nckfil;
    SInt32 result_mux2, result_sub0, result_sub1, result_sub2;

    tqdem_tqck_current = TqDem_tqCkEfcMap[0];
    *tqdem_tqckefcmax_ptr   = TqDem_tqCkEfcMap[1];
    *tqdem_tqckefcmin_ptr   = (SInt16)(-1 * (SInt32)tqcmp_tqsumlosscmp_par);

    /* BIN4 = BIN4 + BIN4 - BIN4 */
    /* [-6000; 6000] = [-2000; 2000] + [-2000; 2000] - [-2000; 2000] */
    result_add1 = ((SInt32)tqcmp_tqsumlosscmp_par + (SInt32)tqdem_tqck_current) - (SInt32)TqDem_tqCkEfcLossOfs_C;

    /* BIN2 = BIN2 - BIN2 */
    /* [-8000; 8000] = [0; 8000] - [0; 8000] */
    result_sub0 = (SInt32)eng_nckfil_par - (SInt32)tqsys_ntaridl_par;

    /* BIN4 [-1; 1] */
    map_out_fac_idlnck_t = DDS_M_MAP2D_S16(&TQDEM_FACNENGIDL_T_APM, (SInt16)result_sub0);

    /* BIN4 = (BIN4 * BIN4) / BIN4 */
    /* [-6000; 6000] = [-1; 1] * [-6000; 6000] */
    result_mux = (map_out_fac_idlnck_t * result_add1) / BIN4 ;

    /* BIN4 [-2000; 2000] */
    TqDem_tqCkEfcLossDelta_MP = (SInt16)DDS_M_LIMIT(result_mux,
                                         (SInt32)(-2000 * BIN4),
                                         (SInt32)( 2000 * BIN4));

    /* BIN7 [0; 100] */
    result_map_eng_nckfil = DDS_M_MAP2D_U16(&TQDEM_RACCPADP_T_APM, eng_nckfil_par);

    /* BIN7 = BIN7 - BIN7 */
    /* [-100; 100] = [0; 100] - [0; 100] */
    denum_div_secure = (SInt32)result_map_eng_nckfil - (SInt32)TqDem_rAccPOfs_C;

    /* BIN14 = (BIN7 - BIN7) * BIN7 */
    /* [-100; 100] = [0; 100] - [0; 100] */
    num_div_secure   = (((SInt32)accp_raccp_par - (SInt32)TqDem_rAccPOfs_C) * BIN7);

    if(0 == num_div_secure)
    {
        result_div_secure = 0 * BIN14;
    }
    else if( 0 == denum_div_secure)
    {
        if( 0 <= num_div_secure )
        {
            result_div_secure = DDS_SINT32_MAX;
        }
        else
        {
            result_div_secure = DDS_SINT32_MIN;
        }
    }
    else
    {
        /* BIN14 = BIN14 * BIN7 / BIN7 */
        /* [-12800; 12800] = [-100; 100] / [-100; 100] */
        result_div_secure = (num_div_secure * BIN7) / denum_div_secure ;
    }

    /* Saturation with HitMax */
    if(result_div_secure >=  (1 * BIN14))
    {
        TqDem_facAdpAccPOff_MP = 0 * BIN7;
        *tqdem_btqgrdlim_ptr = DDS_FALSE;
    }
    else if( result_div_secure <= (0 * BIN7) )
    {
        TqDem_facAdpAccPOff_MP = 1 * BIN7;
        *tqdem_btqgrdlim_ptr = DDS_TRUE;
    }
    else
    {
        /* BIN7 = (BIN14 - BIN14) / BIN7 */
        TqDem_facAdpAccPOff_MP = (UInt8)(((1 * BIN14) - result_div_secure) / BIN7) ;
        *tqdem_btqgrdlim_ptr = DDS_TRUE;
    }

    /* BIN4 = (BIN4 * BIN7) / BIN7 */
    /* [-2000; 2000] = [-2000; 2000] * [0; 1] */
    result_mux2 = (((SInt32)TqDem_tqCkEfcLossDelta_MP * (SInt32)TqDem_facAdpAccPOff_MP) / BIN7);

    /* BIN4 = BIN4 - BIN4 */
    /* [-4000; 4000] = [-2000; 2000] - [-2000; 2000] */
    result_sub1 = (SInt32)tqdem_tqck_current - result_mux2;

    *tqdem_tqckefcwoutantidb_ptr = (SInt16)DDS_M_LIMIT(result_sub1,
                                        (SInt32)(-2000 * BIN4),
                                        (SInt32)( 2000 * BIN4));

    /* BIN4 = BIN4 + BIN4 */
    /* [-4000; 4000] = [-2000; 2000] + [-2000; 2000] */
    result_sub2 = result_sub1 + (SInt32)dzone_tqefcdiflrnout_par;

    *tqdem_tqckefc_ptr = (SInt16)DDS_M_LIMIT(result_sub2,
                                       (SInt32)(-2000 * BIN4),
                                       (SInt32)( 2000 * BIN4));

}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Content_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Ivc_Content_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bTqGrdLim_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfc_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcMin_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkTakeOffMap_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bModSpt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rAccPSptMod_swc_out, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaTakeOff_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcDeltaEcoNorm_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcWoutAntiDB_swc_out /* BIN4 */)


{
  UInt32 i;

  tqdem_ivc_cont_prev_time = DDS_TQDEM_1MS_U32_TIME;

  *TqDem_bTqGrdLim_swc_out = DDS_FALSE;
  *TqDem_tqCkEfcMin_swc_out = (SInt16)(0 * BIN4);
  *TqDem_tqCkEfcMax_swc_out = (SInt16)(0 * BIN4);
  *TqDem_tqCkEfcWoutAntiDB_swc_out = (SInt16)(0 * BIN4);
  *TqDem_tqCkEfc_swc_out = (SInt16)(0 * BIN4);
  *TqDem_tqCkEfcDeltaTakeOff_swc_out = (SInt16)(0 * BIN4);
  *TqDem_tqCkEfcDeltaEcoNorm_swc_out = (SInt16)(0 * BIN4);
  *TqDem_tqCkTakeOffMap_swc_out = (SInt16)(0 * BIN4);
  *TqDem_rAccPSptMod_swc_out = (UInt16)(0 * BIN7);
  *TqDem_bModSpt_swc_out = DDS_FALSE;
  for (i=0;i<TQDEM_TQCKEFC_VECT_SIZE;i++)
  {
    TqDem_rAccP[i] = 0;
    TqDem_tqCkEfcMap[i] = 0;
    TqDem_tqCkEfcMapEco[i] = 0;
    TqDem_tqCkEfcDrvEcoFirst[i] = 0;
    TqDem_tqCkEfcDrvEcoSec[i] = 0;
    TqDem_tqCkEfcMapNorm[i] = 0;
    TqDem_tqCkEfcDrvNormFirst[i] = 0;
    TqDem_tqCkEfcDrvNormSec[i] = 0;
    TqDem_tqCkEfcDrvDeltaEco[i] = 0;
    TqDem_tqCkEfcDrvDeltaNorm[i] = 0;
    TqDem_tqCkEfcDrvEco[i] = 0;
    TqDem_tqCkEfcDrvNorm[i] = 0;
    TqDem_tqCkEfcHiSpdEco[i] = 0;
    TqDem_tqCkEfcHiSpdNorm[i] = 0;
    TqDem_tqCkEfcLoSpdEco[i] = 0;
    TqDem_tqCkEfcLoSpdNorm[i] = 0;
    TqDem_tqCkEfcAvrSpdEco[i] = 0;
    TqDem_tqCkEfcAvrSpdNorm[i] = 0;
    TqDem_tqCkEfcRev[i] = 0;
    TqDem_tqCkEfcTakeOffEco[i] = 0;
    TqDem_tqCkEfcTakeOffNorm[i] = 0;
    TqDem_tqCkEfcRvsTakeOffEco[i] = 0;
    TqDem_tqCkEfcRvsTakeOffNorm[i] = 0;
    TqDem_tqCkTakeOffEco[i] = 0;
    TqDem_tqCkTakeOffNorm[i] = 0;
    f02_03_02_soft_trans_init[i] = DDS_FALSE;
  }

  TqDem_tqCkEfcLossDelta_MP = 0;
  TqDem_bEcoOn = 0;
  TqDem_bDrvLoSpdMap = 0;
  TqDem_bDrvAvrSpdMap = 0;
  TqDem_bDrvHiSpdMap = 0;
  TqDem_bRvsMap = 0;
  TqDem_bTakeOffMap = 0;
  TqDem_bNormOn = 0;
  TqDem_facAdpAccPOff_MP = 0;

  f02_01_soft_trans_init = DDS_FALSE;
}

#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

