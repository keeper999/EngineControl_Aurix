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
* Ref X:\integration_view_00PSASWC_EA20D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Req_Cll_Opl_Gbl.c
* Version int :/main/L05_01/1 Date: 11/4/2012 9 h 48 m User:esnault 
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L05_010_IMPL2
*    comments :for CoClLASl 12.0
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 5/4/2012 14 h 35 m User:morisseau 
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L05_010_IMPL2
*    comments :for CoClLASl 12.0
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 5/4/2012 14 h 25 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L05_010_IMPL2
*    comments :for CoClLASl 12.0
* Version int :/main/L04_01/1 Date: 6/6/2011 10 h 40 m User:esnault
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L04_010_IMPL1
*    comments :update for CoClLASl 11.2: rename TqSys_tqIdcAirReq by TqSys_tqIdcAirReqGen
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 4/5/2011 14 h 55 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L04_010_IMPL1
*    comments :update for CoClLASl 11.2: rename TqSys_tqIdcAirReq by TqSys_tqIdcAirReqGen
* Version int :/main/L03_01/1 Date: 25/2/2011 11 h 30 m User:esnault
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L03_010_IMPL1
*    comments :Update for YU
* Version dev :\main\branch_halouane_CoClLASl_dev\3 Date: 21/2/2011 11 h 39 m User:halouane
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L03_010_IMPL1
*    comments :Update for YU
* Version dev :\main\branch_halouane_CoClLASl_dev\2 Date: 21/2/2011 11 h 12 m User:halouane
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L03_010_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\1 Date: 4/2/2011 10 h 13 m User:halouane
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L03_010_IMPL1
*    comments :update for COCLLASL 11.0
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 42 m User:meme
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 1/10/2010 12 h 32 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L02_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 58 m User:esnault
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\10 Date: 1/9/2010 9 h 54 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\9 Date: 31/8/2010 17 h 43 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\8 Date: 27/8/2010 11 h 11 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :changed from PSA for TqCll_bAcvCll done
* Version dev :\main\branch_morisseau_cocllasl_view\7 Date: 27/8/2010 10 h 53 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 29/7/2010 17 h 34 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 22/7/2010 11 h 35 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 21/7/2010 18 h 22 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 21/7/2010 14 h 29 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :work in progress FR.4.1
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 17 h 56 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 40 m User:morisseau
*    TWK_model:COCLLASL_Req_Cll_Opl_Gbl_L01_010_IMPL1
*    comments :work in progress
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CoClLASl.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define COCLLASL_9_SIZE 9

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
#define COCLLASL_START_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tiAcvDifForc_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tiDiDifForc_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tiTqDifCfm_C = (CONST(UInt16, AUTOMATIC))(0.5 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tiTranForc_C = (CONST(UInt16, AUTOMATIC))(0.2 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tiTranCllEngReq_C = (CONST(UInt16, AUTOMATIC))(0.1 * DEC3);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqDifHiForc_C = (CONST(SInt16, AUTOMATIC))(50 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqDifLoForc_C = (CONST(SInt16, AUTOMATIC))(-50 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqGainDeltaCll_C = (CONST(SInt16, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqGainDeltaOpl_C = (CONST(SInt16, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqIncForc_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqOfsCllConv_C = (CONST(SInt16, AUTOMATIC))(2 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqOfsOplConv_C = (CONST(SInt16, AUTOMATIC))(2 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tqIncEngReq_C = (CONST(UInt16, AUTOMATIC))(2 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqIncOplDft_C = (CONST(SInt16, AUTOMATIC))(5 * BIN4);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits scalar calibration definition */
#define COCLLASL_START_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCll_bCondTmrAcv_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCll_bLimTranAcv_C = DDS_FALSE;
#define COCLLASL_STOP_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COCLLASL_START_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_facTiTranOpl_T
[COCLLASL_8_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(2 * BIN7), (UInt16)(2 * BIN7),
(UInt16)(2 * BIN7), (UInt16)(2 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_nEngOpl_A[COCLLASL_8_SIZE] = {
(UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(4500 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_tiTranOpl_M
[COCLLASL_7_SIZE][COCLLASL_8_SIZE] = {
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) },
{
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3),
(UInt16)(0.5 * DEC3), (UInt16)(0.5 * DEC3) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqDifTranOpl_A[COCLLASL_8_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-25 * BIN4), (SInt16)(-10 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(10 * BIN4), (SInt16)(25 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(100 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCll_tqIncOpl_M
[COCLLASL_7_SIZE][COCLLASL_8_SIZE] = {
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCll_noGearOpl_A[COCLLASL_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0),
(UInt16)(4 * BIN0), (UInt16)(5 * BIN0), (UInt16)(6 * BIN0)
};

#define COCLLASL_STOP_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcll_factitranopl_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcll_titranopl_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcll_tqincopl_m_sav;
STATIC VAR(t_dds_m_turn_on_delay_delta_type, AUTOMATIC) cocllasl_f01_01_turn_on_delay;
STATIC VAR(t_dds_m_turn_off_delay_delta_type, AUTOMATIC) cocllasl_f01_01_turn_off_delay;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f01_00_rs_edge_detect[COCLLASL_9_SIZE];
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f01_01_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f01_02_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f01_02_edge_detect_1;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f01_02_edge_detect_2;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_1_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_2_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_1_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_2_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_3_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_4_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_5_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_6_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_7_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f02_tmrrst_val_vect_8_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f03_edge_detect;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) cocllasl_f03_edge_detect_1;
#define COCLLASL_STOP_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"

#define COCLLASL_START_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) cocllasl_f02_0x_calcul_num_value;
#define COCLLASL_STOP_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"

#define COCLLASL_START_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) cocllasl_tqsys_tqckenglimcordprev_cpy;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_f01_01_tmrrst_val;
STATIC VAR(SInt16, AUTOMATIC) cocllasl_englim_tqidcengcurmax_prev;
STATIC VAR(SInt16, AUTOMATIC) cocllasl_tqsys_tqidcenglimcord_prev;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_ticharun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_titrarun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tilimrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tidrivrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tiidlrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tiresrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tiengreqrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tiadvminrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tiforcrun_dec3;
STATIC VAR(UInt16, AUTOMATIC) cocllasl_tqcll_tioplrun_dec3;
#define COCLLASL_STOP_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"

#define COCLLASL_START_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) cocllasl_tqcll_bacvcll_loc;
STATIC VAR(UInt8, AUTOMATIC) cocllasl_tqcll_bforccll_loc;
STATIC VAR(UInt8, AUTOMATIC) cocllasl_tqcll_breqcllptl_loc;

#define COCLLASL_STOP_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiAdvMinRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiChaRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiDrivRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiForcRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiIdlRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiLimRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiOplRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiResRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiTraRun; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiTranOpl; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCll_tiEngReqRun; /* DEC2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqCllTranRaw_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqCllTran_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqDifCll; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqDifOpl; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIdcCllRaw_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncChaRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncCha_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncDrivRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncDriv_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncForc; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncForcRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncIdlRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncIdl_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncLimRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncLim_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncOpl; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncOplRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncOplVld; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncResRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncRes_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncTraRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncTra_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncVld; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqOplTranRaw_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqOplTran_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkEngLimCordPrev; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkEngLimCordRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncAdvMinRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCll_tqIncEngReqRaw; /* BIN4 */
#define COCLLASL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bAcvCllPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bReqCll;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bReqCllGbl;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTmrOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranAdvMin;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranCha;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranCll;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranDriv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranForc;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranIdl;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranEngReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranOpl;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranRes;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bTranTra;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCll_bAcvCllRaw;
#define COCLLASL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COCLLASL_START_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCLL_FACTITRANOPL_T_APM = {
&tqcll_factitranopl_t_sav,
COCLLASL_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCll_tqDifTranOpl_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCll_facTiTranOpl_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCLL_TITRANOPL_M_APM = {
&tqcll_titranopl_m_sav,
COCLLASL_8_SIZE,
COCLLASL_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCll_nEngOpl_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCll_noGearOpl_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCll_tiTranOpl_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQCLL_TQINCOPL_M_APM = {
&tqcll_tqincopl_m_sav,
COCLLASL_8_SIZE,
COCLLASL_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCll_nEngOpl_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCll_noGearOpl_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCll_tqIncOpl_M[0][0]
};

#define COCLLASL_STOP_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_State_calculation(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           UInt8 cocha_bacvcll_par,
                                           UInt8 copt_bacvcll_par,
                                           UInt8 englim_bacvcll_par,
                                           UInt8 tqsys_bacvcll_par,
                                           UInt8 idlsys_bacvcll_par,
                                           UInt8 tqres_bacvcll_par,
                                           UInt16 cocha_tqinccll_par, /* BIN4 */
                                           UInt16 copt_tqinccll_par, /* BIN4 */
                                           UInt16 englim_tqinccll_par, /* BIN4 */
                                           UInt16 tqsys_tqinccll_par, /* BIN4 */
                                           UInt16 idlsys_tqinccll_par, /* BIN4 */
                                           UInt16 tqres_tqinccll_par, /* BIN4 */
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           UInt8 tqsys_baosacv_par,
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt8 frm_binhtqcll_par,
                                           SInt16 tqsys_tqidcairreqgen_par, /* BIN4 */
                                           UInt8 eng_bacvcllengreq_par,
                                           UInt8 tqadvmin_bacvcll_par,
                                           UInt16 tqadvmin_tqinccll_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bacvcll_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bforccll_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_breqcllptl_ptr);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_00_RS_Calcul(UInt8 boolean_input,
                                                       UInt8 edge_index,
                                                       UInt8 tqcll_brsttran_par,
                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) rs_out_ptr);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_00_Output_Calcul(
                               UInt16 cocha_tqinccll_par, /* BIN4 */
                               UInt16 copt_tqinccll_par, /* BIN4 */
                               UInt16 englim_tqinccll_par, /* BIN4 */
                               UInt8 ext_titdc_par, /* DEC3 */
                               UInt16 tqsys_tqinccll_par, /* BIN4 */
                               UInt16 idlsys_tqinccll_par, /* BIN4 */
                               UInt16 tqres_tqinccll_par, /* BIN4 */
                               UInt16 tqadvmin_tqinccll_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_01_Forcage_CLL(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           SInt16 tqsys_tqidcairreqgen_par, /* BIN4 */
                                           UInt8 frm_binhtqcll_par,
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bforccll_ptr);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_02_Cll_state_calculation(
                                           UInt8 tqsys_baosacv_par,
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bacvcll_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_breqcllptl_ptr);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Increment_calculation(
                                           UInt16 cocha_titrancll_par, /* DEC2 */
                                           UInt16 copt_titrancll_par, /* DEC2 */
                                           UInt16 englim_titrancll_par, /* DEC2 */
                                           UInt16 tqsys_titrancll_par, /* DEC2 */
                                           UInt16 idlsys_titrancll_par, /* DEC2 */
                                           UInt16 tqres_titrancll_par, /* DEC2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 copt_nogearcorddrivfil_par,
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           UInt16 tqadvmin_titrancl_par); /* DEC2 */

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_00_Calc_Timer_Rst(
                                           UInt8 timer_start,
                                           UInt16 timer_init_val,
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_str,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) timer_val);


STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_01_Calcul_inc_Cha(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_02_Calcul_inc_Tra(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_03_Calcul_inc_Lim(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_04_Calcul_inc_Driv(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_05_Calcul_inc_Idl(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_06_Calcul_inc_Reserve(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_07_Calcul_inc_Opl(
                                           UInt8 ext_titdc_par /* DEC3 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_08_Calcul_inc_Froc(
                                           UInt8 ext_titdc_par /* DEC3 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_09_Param_Opl(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 copt_nogearcorddrivfil_par,
                                           SInt16 englim_tqidcengcurmax_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_10_Calcul_inc_EngReq(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_11_Calcul_inc_AdvMin(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_12_TqCll_tqIncOplVld(
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           SInt16 englim_tqidcengcurmax_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_13_TqCll_tqIncVld(
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           SInt16 sum_input /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Transition_calculation(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           SInt16 tqsys_tqidcenglimcord_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F04_Configuration(
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           UInt8 tqsys_btypfu_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckenglimcord_ptr /* BIN4 */);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Req_Cll_Opl_Gbl
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Req_Cll_Opl_Gbl(UInt8 CoCha_bAcvCll_swc_in,
                                           UInt16 CoCha_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 CoCha_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 CoPt_bAcvCll_swc_in,
                                           UInt8 CoPt_noGearCordDrivFil_swc_in,
                                           UInt16 CoPt_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 CoPt_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 EngLim_bAcvCll_swc_in,
                                           UInt16 EngLim_tiTranCll_swc_in, /* DEC2 */
                                           SInt16 EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           UInt16 EngLim_tqIncCll_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 FRM_bInhTqCll_swc_in,
                                           UInt8 IdlSys_bAcvCll_swc_in,
                                           UInt16 IdlSys_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 IdlSys_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 TqRes_bAcvCll_swc_in,
                                           UInt16 TqRes_tiTranCll_swc_in, /* DEC2 */
                                           UInt16 TqRes_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAOSAcv_swc_in,
                                           UInt8 TqSys_bAcvCll_swc_in,
                                           UInt8 TqSys_bEngNOnIdl_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_tiTranCll_swc_in, /* DEC2 */
                                           SInt16 TqSys_tqIdcAirReqGen_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcEngLimCord_swc_in, /* BIN4 */
                                           UInt16 TqSys_tqIncCll_swc_in, /* BIN4 */
                                           UInt8 Eng_bAcvCllEngReq_swc_in,
                                           UInt8 TqAdvMin_bAcvCll_swc_in,
                                           UInt16 TqAdvMin_tqIncCll_swc_in, /* BIN4 */
                                           UInt16 TqAdvMin_tiTranCll_swc_in, /* DEC2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bAcvCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bForcCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bReqCllPtl_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)TqSys_tqCkEngLimCord_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.1.4 */


    if((UInt32)TqSys_bTypFu_swc_in != (UInt32)DDS_FALSE)
    {
        COCLLASL_F01_State_calculation(EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                       CoCha_bAcvCll_swc_in,
                                       CoPt_bAcvCll_swc_in,
                                       EngLim_bAcvCll_swc_in,
                                       TqSys_bAcvCll_swc_in,
                                       IdlSys_bAcvCll_swc_in,
                                       TqRes_bAcvCll_swc_in,
                                       CoCha_tqIncCll_swc_in, /* BIN4 */
                                       CoPt_tqIncCll_swc_in, /* BIN4 */
                                       EngLim_tqIncCll_swc_in, /* BIN4 */
                                       TqSys_tqIncCll_swc_in, /* BIN4 */
                                       IdlSys_tqIncCll_swc_in, /* BIN4 */
                                       TqRes_tqIncCll_swc_in, /* BIN4 */
                                       TqSys_tqIdcEngLimCord_swc_in, /* BIN4 */
                                       TqSys_bAOSAcv_swc_in,
                                       Ext_tiTDC_swc_in, /* DEC3 */
                                       TqSys_bEngNOnIdl_swc_in,
                                       FRM_bInhTqCll_swc_in,
                                       TqSys_tqIdcAirReqGen_swc_in, /* BIN4 */
                                       Eng_bAcvCllEngReq_swc_in,
                                       TqAdvMin_bAcvCll_swc_in,
                                       TqAdvMin_tqIncCll_swc_in, /* BIN4 */
                                       &cocllasl_tqcll_bacvcll_loc,
                                       &cocllasl_tqcll_bforccll_loc,
                                       &cocllasl_tqcll_breqcllptl_loc);

        COCLLASL_F02_Increment_calculation(CoCha_tiTranCll_swc_in, /* DEC2 */
                                           CoPt_tiTranCll_swc_in, /* DEC2 */
                                           EngLim_tiTranCll_swc_in, /* DEC2 */
                                           TqSys_tiTranCll_swc_in, /* DEC2 */
                                           IdlSys_tiTranCll_swc_in, /* DEC2 */
                                           TqRes_tiTranCll_swc_in, /* DEC2 */
                                           Eng_nCkFil_swc_in, /* BIN2 */
                                           CoPt_noGearCordDrivFil_swc_in,
                                           TqSys_tqIdcEngLimCord_swc_in, /* BIN4 */
                                           Ext_tiTDC_swc_in, /* DEC3 */
                                           EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           TqAdvMin_tiTranCll_swc_in /* DEC2 */);

        COCLLASL_F03_Transition_calculation(EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                            TqSys_tqIdcEngLimCord_swc_in /* BIN4 */);
    }
    else
    {
        /* nothing to do */
    }

    *TqCll_bAcvCll_swc_out = cocllasl_tqcll_bacvcll_loc;
    *TqCll_bForcCll_swc_out = cocllasl_tqcll_bforccll_loc;
    *TqCll_bReqCllPtl_swc_out = cocllasl_tqcll_breqcllptl_loc;

    COCLLASL_F04_Configuration(TqSys_tqIdcEngLimCord_swc_in, /* BIN4 */
                               TqSys_bTypFu_swc_in,
                               TqSys_tqCkEngLimCord_swc_out /* BIN4 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F01_State_calculation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_State_calculation(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           UInt8 cocha_bacvcll_par,
                                           UInt8 copt_bacvcll_par,
                                           UInt8 englim_bacvcll_par,
                                           UInt8 tqsys_bacvcll_par,
                                           UInt8 idlsys_bacvcll_par,
                                           UInt8 tqres_bacvcll_par,
                                           UInt16 cocha_tqinccll_par, /* BIN4 */
                                           UInt16 copt_tqinccll_par, /* BIN4 */
                                           UInt16 englim_tqinccll_par, /* BIN4 */
                                           UInt16 tqsys_tqinccll_par, /* BIN4 */
                                           UInt16 idlsys_tqinccll_par, /* BIN4 */
                                           UInt16 tqres_tqinccll_par, /* BIN4 */
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           UInt8 tqsys_baosacv_par,
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 tqsys_bengnonidl_par,
                                           UInt8 frm_binhtqcll_par,
                                           SInt16 tqsys_tqidcairreqgen_par, /* BIN4 */
                                           UInt8 eng_bacvcllengreq_par,
                                           UInt8 tqadvmin_bacvcll_par,
                                           UInt16 tqadvmin_tqinccll_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bacvcll_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bforccll_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_breqcllptl_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.2.6 */
    UInt8 tqcll_bforccll_loc;
    UInt8 tqcll_brsttran;

    COCLLASL_F01_01_Forcage_CLL(englim_tqidcengcurmax_par, /* BIN4 */
                                tqsys_tqidcairreqgen_par, /* BIN4 */
                                frm_binhtqcll_par,
                                ext_titdc_par, /* DEC3 */
                                &tqcll_bforccll_loc);

    *tqcll_bforccll_ptr = tqcll_bforccll_loc;

    if(  ((UInt32)cocha_bacvcll_par == (UInt32)DDS_TRUE)
       ||((UInt32)copt_bacvcll_par == (UInt32)DDS_TRUE)
       ||((UInt32)englim_bacvcll_par == (UInt32)DDS_TRUE)
       ||((UInt32)tqsys_bacvcll_par == (UInt32)DDS_TRUE)
       ||(  ((UInt32)tqsys_bengnonidl_par == (UInt32)DDS_TRUE)
          &&((UInt32)idlsys_bacvcll_par == (UInt32)DDS_TRUE))
       ||((UInt32)tqres_bacvcll_par == (UInt32)DDS_TRUE)
       ||((UInt32)eng_bacvcllengreq_par == (UInt32)DDS_TRUE)
       ||((UInt32)tqcll_bforccll_loc== (UInt32)DDS_TRUE)
       ||((UInt32)tqadvmin_bacvcll_par != (UInt32)DDS_FALSE))

    {
        TqCll_bReqCllGbl = DDS_TRUE;
    }
    else
    {
        TqCll_bReqCllGbl = DDS_FALSE;
    }

    if((SInt32) TqSys_tqCkEngLimCordPrev <= ((SInt32)tqsys_tqidcenglimcord_par+(SInt32)TqCll_tqOfsCllConv_C))
    {
        tqcll_brsttran = DDS_TRUE;
    }
    else
    {
        tqcll_brsttran = DDS_FALSE;
    }

    COCLLASL_F01_00_RS_Calcul(cocha_bacvcll_par,0,tqcll_brsttran,&TqCll_bTranCha);
    COCLLASL_F01_00_RS_Calcul(copt_bacvcll_par,1,tqcll_brsttran,&TqCll_bTranTra);
    COCLLASL_F01_00_RS_Calcul(englim_bacvcll_par,2,tqcll_brsttran,&TqCll_bTranLim);
    COCLLASL_F01_00_RS_Calcul(tqsys_bacvcll_par,3,tqcll_brsttran,&TqCll_bTranDriv);
    if(  ((UInt32)tqsys_bengnonidl_par == (UInt32)DDS_TRUE)
       &&((UInt32)idlsys_bacvcll_par == (UInt32)DDS_TRUE))
    {
        COCLLASL_F01_00_RS_Calcul(DDS_TRUE,4,tqcll_brsttran,&TqCll_bTranIdl);
    }
    else
    {
        COCLLASL_F01_00_RS_Calcul(DDS_FALSE,4,tqcll_brsttran,&TqCll_bTranIdl);
    }
    COCLLASL_F01_00_RS_Calcul(tqres_bacvcll_par,5,tqcll_brsttran,&TqCll_bTranRes);
    COCLLASL_F01_00_RS_Calcul(eng_bacvcllengreq_par,6,tqcll_brsttran,&TqCll_bTranEngReq);
    COCLLASL_F01_00_RS_Calcul(tqadvmin_bacvcll_par,7,tqcll_brsttran,&TqCll_bTranAdvMin);
    COCLLASL_F01_00_RS_Calcul(tqcll_bforccll_loc,8,tqcll_brsttran,&TqCll_bTranForc);

    COCLLASL_F01_00_Output_Calcul(
                               cocha_tqinccll_par, /* BIN4 */
                               copt_tqinccll_par, /* BIN4 */
                               englim_tqinccll_par, /* BIN4 */
                               ext_titdc_par, /* DEC3 */
                               tqsys_tqinccll_par, /* BIN4 */
                               idlsys_tqinccll_par, /* BIN4 */
                               tqres_tqinccll_par, /* BIN4 */
                               tqadvmin_tqinccll_par /* BIN4 */);

    COCLLASL_F01_02_Cll_state_calculation(tqsys_baosacv_par,
                                          englim_tqidcengcurmax_par, /* BIN4 */
                                          tqcll_bacvcll_ptr,
                                          tqcll_breqcllptl_ptr);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F01_00_RS_Calcul
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_00_RS_Calcul(UInt8 boolean_input,
                                                       UInt8 edge_index,
                                                       UInt8 tqcll_brsttran_par,
                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) rs_out_ptr)
{
    t_dds_m_edge_detected_event edge_out;

    edge_out = DDS_M_EDGE_DETECT(&cocllasl_f01_00_rs_edge_detect[(UInt32)edge_index],boolean_input);

    if(  (edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
       ||((UInt32)tqcll_brsttran_par != (UInt32)DDS_FALSE))
    {
        *rs_out_ptr = DDS_FALSE;
    }
    else if(edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        *rs_out_ptr = DDS_TRUE;
    }
    else
    {
        /* Nothing to do */
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F01_00_Output_Calcul
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_00_Output_Calcul(
                               UInt16 cocha_tqinccll_par, /* BIN4 */
                               UInt16 copt_tqinccll_par, /* BIN4 */
                               UInt16 englim_tqinccll_par, /* BIN4 */
                               UInt8 ext_titdc_par, /* DEC3 */
                               UInt16 tqsys_tqinccll_par, /* BIN4 */
                               UInt16 idlsys_tqinccll_par, /* BIN4 */
                               UInt16 tqres_tqinccll_par, /* BIN4 */
                               UInt16 tqadvmin_tqinccll_par /* BIN4 */)

{
    SInt32 cocllasl_f01_value;
    SInt16 cocllasl_temp_s16;
    SInt16 cocllasl_temp_s16_2;
    UInt8 cocllasl_f01_bool;

    cocllasl_f01_bool = DDS_FALSE;

    if((UInt32)TqCll_bTranCha != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncCha_MP = (SInt16)(((SInt32)cocha_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncCha_MP = 0;
    }

    if((UInt32)TqCll_bTranTra != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncTra_MP = (SInt16)(((SInt32)copt_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncTra_MP = 0;
    }

    if((UInt32)TqCll_bTranLim != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncLim_MP = (SInt16)(((SInt32)englim_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncLim_MP = 0;
    }

    if((UInt32)TqCll_bTranDriv != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncDriv_MP = (SInt16)(((SInt32)tqsys_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncDriv_MP = 0;
    }

    if((UInt32)TqCll_bTranIdl != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncIdl_MP = (SInt16)(((SInt32)idlsys_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncIdl_MP = 0;
    }

    if((UInt32)TqCll_bTranRes != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncRes_MP = (SInt16)(((SInt32)tqres_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncRes_MP  = 0;
    }

    if((UInt32)TqCll_bTranEngReq != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        cocllasl_temp_s16 = (SInt16)(((SInt32)TqCll_tqIncEngReq_C * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        cocllasl_temp_s16 = 0;
    }

    if((UInt32)TqCll_bTranAdvMin != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        cocllasl_temp_s16_2 = (SInt16)(((SInt32)tqadvmin_tqinccll_par * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        cocllasl_temp_s16_2 = 0;
    }

    if((UInt32)TqCll_bTranForc != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_bool = DDS_TRUE;
        TqCll_tqIncForc = (SInt16)(((SInt32)TqCll_tqIncForc_C * (SInt32)ext_titdc_par) / DEC3);
    }
    else
    {
        TqCll_tqIncForc = 0;
    }

    TqCll_bTranCll = cocllasl_f01_bool;

    cocllasl_f01_value = DDS_M_MAX((SInt32)TqCll_tqIncCha_MP,(SInt32)TqCll_tqIncTra_MP);
    cocllasl_f01_value = DDS_M_MAX(cocllasl_f01_value,(SInt32)TqCll_tqIncLim_MP);
    cocllasl_f01_value = DDS_M_MAX(cocllasl_f01_value,(SInt32)TqCll_tqIncDriv_MP);
    cocllasl_f01_value = DDS_M_MAX(cocllasl_f01_value,(SInt32)TqCll_tqIncIdl_MP);
    cocllasl_f01_value = DDS_M_MAX(cocllasl_f01_value,(SInt32)TqCll_tqIncRes_MP);
    cocllasl_f01_value = DDS_M_MAX(cocllasl_f01_value,(SInt32)cocllasl_temp_s16);
    TqCll_tqIncRaw =(SInt16)DDS_M_MAX(cocllasl_f01_value,(SInt32)cocllasl_temp_s16_2);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F01_01_Forcage_CLL
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_01_Forcage_CLL(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           SInt16 tqsys_tqidcairreqgen_par, /* BIN4 */
                                           UInt8 frm_binhtqcll_par,
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bforccll_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.14.2 */
    SInt32 cocllasl_f01_01_value;
    UInt8 cocllasl_f01_01_test;
    UInt8 cocllasl_f01_01_tmrrst_out;

    t_dds_m_edge_detected_event cocllasl_f01_01_edge_out;

    /* BIN4 */
    /* [-4000;4000] = [-2000;2000] - [-2000;2000] */
    cocllasl_f01_01_value = (SInt32)englim_tqidcengcurmax_par - (SInt32)tqsys_tqidcairreqgen_par; /* BIN4 */
    if(  (cocllasl_f01_01_value >= (SInt32)TqCll_tqDifHiForc_C)
       ||(cocllasl_f01_01_value <= (SInt32)TqCll_tqDifLoForc_C))
    {
        cocllasl_f01_01_test = DDS_TRUE;
    }
    else
    {
        cocllasl_f01_01_test = DDS_FALSE;
    }
    cocllasl_f01_01_edge_out = DDS_M_EDGE_DETECT(&cocllasl_f01_01_edge_detect,cocllasl_f01_01_test);

/* Begin TmrRst */

    if((UInt32)cocllasl_f01_01_test != (UInt32)DDS_TRUE)
    {
        /* reset of TmrRst */
        cocllasl_f01_01_tmrrst_val = 0;
        cocllasl_f01_01_tmrrst_out = DDS_FALSE;
    }
    else if(cocllasl_f01_01_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        cocllasl_f01_01_tmrrst_val = TqCll_tiTqDifCfm_C;
        if((UInt32)cocllasl_f01_01_tmrrst_val == 0)
        {
            cocllasl_f01_01_tmrrst_out = DDS_FALSE;
        }
        else
        {
            cocllasl_f01_01_tmrrst_out = DDS_TRUE;
        }
    }
    else
    {
        if((UInt32)cocllasl_f01_01_tmrrst_val <= (UInt32)ext_titdc_par)
        {
            cocllasl_f01_01_tmrrst_val = 0;
            cocllasl_f01_01_tmrrst_out = DDS_FALSE;
        }
        else
        {
            cocllasl_f01_01_tmrrst_val = (UInt16)((SInt32)cocllasl_f01_01_tmrrst_val - (SInt32)ext_titdc_par);
            cocllasl_f01_01_tmrrst_out = DDS_TRUE;
        }
    }
/* End TmrRst */

    if(  (  ((UInt32)cocllasl_f01_01_tmrrst_out != (UInt32)DDS_TRUE)
          &&((UInt32)cocllasl_f01_01_test == (UInt32)DDS_TRUE)
          &&((UInt32)TqCll_bAcvCllPrev == (UInt32)DDS_FALSE))
       ||((UInt32)frm_binhtqcll_par == (UInt32)DDS_TRUE))
    {
        cocllasl_f01_01_test = DDS_TRUE;
    }
    else
    {
        cocllasl_f01_01_test = DDS_FALSE;
    }



    cocllasl_f01_01_test = DDS_M_TURN_ON_DELAY_DELTA(cocllasl_f01_01_test,
                                                     ext_titdc_par,
                                                     (UInt32)TqCll_tiAcvDifForc_C,
                                                     &cocllasl_f01_01_turn_on_delay);

    *tqcll_bforccll_ptr = DDS_M_TURN_OFF_DELAY_DELTA(cocllasl_f01_01_test,
                                                     ext_titdc_par,
                                                     (UInt32)TqCll_tiDiDifForc_C,
                                                     &cocllasl_f01_01_turn_off_delay);


}

/*******************************************************************************
*
* Function Name : COCLLASL_F01_02_Cll_state_calculation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_02_Cll_state_calculation(
                                           UInt8 tqsys_baosacv_par,
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_bacvcll_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcll_breqcllptl_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.3.4 */
    t_dds_m_edge_detected_event cocllasl_f01_02_edge_out;
    t_dds_m_edge_detected_event cocllasl_f01_02_edge_out_2;
    UInt8 tqcll_brsttranopl_loc;

    TqCll_bAcvCllPrev = TqCll_bAcvCllRaw;
    TqCll_bReqCll = TqCll_bReqCllGbl;

    if((SInt32)TqSys_tqCkEngLimCordPrev >= ((SInt32)englim_tqidcengcurmax_par + (SInt32)TqCll_tqOfsOplConv_C))
    {
        tqcll_brsttranopl_loc = DDS_TRUE;
    }
    else
    {
        tqcll_brsttranopl_loc = DDS_FALSE;
    }

    cocllasl_f01_02_edge_out = DDS_M_EDGE_DETECT(&cocllasl_f01_02_edge_detect,TqCll_bReqCllGbl);

    if((UInt32)TqCll_bTmrOff != (UInt32)DDS_FALSE)
    {
        cocllasl_f01_02_edge_out_2 = DDS_M_EDGE_DETECT(&cocllasl_f01_02_edge_detect_2,DDS_FALSE);
    }
    else
    {
        cocllasl_f01_02_edge_out_2 = DDS_M_EDGE_DETECT(&cocllasl_f01_02_edge_detect_2,DDS_TRUE);
    }

    if(  (cocllasl_f01_02_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
       ||((UInt32)tqcll_brsttranopl_loc != (UInt32)DDS_FALSE)
       ||(  ((UInt32)TqCll_bCondTmrAcv_C != (UInt32)DDS_FALSE)
          &&(cocllasl_f01_02_edge_out_2 == DDS_M_POSITIVE_EDGE_DETECTED)))
    {
        TqCll_bTranOpl = DDS_FALSE;
    }else if(cocllasl_f01_02_edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
    {
        TqCll_bTranOpl = DDS_TRUE;
    }
    else
    {
        /*nothing to do*/
    }

    cocllasl_f01_02_edge_out = DDS_M_EDGE_DETECT(&cocllasl_f01_02_edge_detect_1,TqCll_bTranOpl);

    if(  (  (cocllasl_f01_02_edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
          ||((UInt32)tqcll_brsttranopl_loc != (UInt32)DDS_FALSE))
       &&((UInt32)TqCll_bReqCllGbl == (UInt32)DDS_FALSE))
    {
        TqCll_bAcvCllRaw = DDS_FALSE;
    }
    else if((UInt32)TqCll_bReqCllGbl != (UInt32)DDS_FALSE)
    {
        TqCll_bAcvCllRaw = DDS_TRUE;
    }
    else
    {
        /*nothing to do*/
    }

    if(  ((UInt32)TqCll_bAcvCllRaw != (UInt32)DDS_FALSE)
       ||((UInt32)tqsys_baosacv_par != (UInt32)DDS_FALSE))
    {
        *tqcll_bacvcll_ptr = DDS_TRUE;
    }
    else
    {
        *tqcll_bacvcll_ptr = DDS_FALSE;
    }

    if(  ((UInt32)TqCll_bAcvCllRaw == (UInt32)DDS_FALSE)
           &&((UInt32)tqsys_baosacv_par != (UInt32)DDS_FALSE))
    {
        *tqcll_breqcllptl_ptr = DDS_TRUE;
    }
    else
    {
        *tqcll_breqcllptl_ptr = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_Increment_calculation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Increment_calculation(
                                           UInt16 cocha_titrancll_par, /* DEC2 */
                                           UInt16 copt_titrancll_par, /* DEC2 */
                                           UInt16 englim_titrancll_par, /* DEC2 */
                                           UInt16 tqsys_titrancll_par, /* DEC2 */
                                           UInt16 idlsys_titrancll_par, /* DEC2 */
                                           UInt16 tqres_titrancll_par, /* DEC2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 copt_nogearcorddrivfil_par,
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           UInt16 tqadvmin_titrancl_par) /* DEC2 */
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.4.3 */
    SInt32 cocllasl_f02_value;

    TqCll_tqDifCll = (SInt16)DDS_M_LIMIT((SInt32)TqSys_tqCkEngLimCordPrev - (SInt32)tqsys_tqidcenglimcord_par,
                                         -2000*BIN4,
                                         2000*BIN4);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranCha,
                                   (UInt16)((UInt32)cocha_titrancll_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_1_edge_detect,
                                   &cocllasl_tqcll_ticharun_dec3);
    TqCll_tiChaRun = (UInt16)((UInt32)cocllasl_tqcll_ticharun_dec3 / DEC1);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranTra,
                                   (UInt16)((UInt32)copt_titrancll_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_2_edge_detect,
                                   &cocllasl_tqcll_titrarun_dec3);
    TqCll_tiTraRun = (UInt16)((UInt32)cocllasl_tqcll_titrarun_dec3 / DEC1);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranLim,
                                   (UInt16)((UInt32)englim_titrancll_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_3_edge_detect,
                                   &cocllasl_tqcll_tilimrun_dec3);
    TqCll_tiLimRun = (UInt16)((UInt32)cocllasl_tqcll_tilimrun_dec3 / DEC1);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranDriv,
                                   (UInt16)((UInt32)tqsys_titrancll_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_4_edge_detect,
                                   &cocllasl_tqcll_tidrivrun_dec3);
    TqCll_tiDrivRun = (UInt16)((UInt32)cocllasl_tqcll_tidrivrun_dec3 / DEC1);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranIdl,
                                   (UInt16)((UInt32)idlsys_titrancll_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_5_edge_detect,
                                   &cocllasl_tqcll_tiidlrun_dec3);
    TqCll_tiIdlRun = (UInt16)((UInt32)cocllasl_tqcll_tiidlrun_dec3 / DEC1);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranRes,
                                   (UInt16)((UInt32)tqres_titrancll_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_6_edge_detect,
                                   &cocllasl_tqcll_tiresrun_dec3);
    TqCll_tiResRun = (UInt16)((UInt32)cocllasl_tqcll_tiresrun_dec3 / DEC1);

     COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranEngReq,
                                   TqCll_tiTranCllEngReq_C,
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_7_edge_detect,
                                   &cocllasl_tqcll_tiengreqrun_dec3);
    TqCll_tiEngReqRun = (UInt16)((UInt32)cocllasl_tqcll_tiengreqrun_dec3 / DEC1);

     COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranAdvMin,
                                   (UInt16)((UInt32)tqadvmin_titrancl_par * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_vect_8_edge_detect,
                                   &cocllasl_tqcll_tiadvminrun_dec3);
    TqCll_tiAdvMinRun = (UInt16)((UInt32)cocllasl_tqcll_tiadvminrun_dec3 / DEC1);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranForc,
                                   TqCll_tiTranForc_C,
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_2_edge_detect,
                                   &cocllasl_tqcll_tiforcrun_dec3);
    TqCll_tiForcRun = (UInt16)((UInt32)cocllasl_tqcll_tiforcrun_dec3 / DEC1);


    if((UInt32)TqCll_bTranForc != (UInt32)DDS_FALSE)
    {
        COCLLASL_F02_08_Calcul_inc_Froc(ext_titdc_par /* DEC3 */);
        COCLLASL_F02_13_TqCll_tqIncVld(tqsys_tqidcenglimcord_par, /* BIN4 */
                                       TqCll_tqIncForcRaw);
    }
    else
    {
        cocllasl_f02_0x_calcul_num_value = ((SInt32)ext_titdc_par * (SInt32)TqCll_tqDifCll);
        COCLLASL_F02_01_Calcul_inc_Cha();
        COCLLASL_F02_02_Calcul_inc_Tra();
        COCLLASL_F02_03_Calcul_inc_Lim();
        COCLLASL_F02_04_Calcul_inc_Driv();
        COCLLASL_F02_05_Calcul_inc_Idl();
        COCLLASL_F02_06_Calcul_inc_Reserve();
        COCLLASL_F02_10_Calcul_inc_EngReq();
        COCLLASL_F02_11_Calcul_inc_AdvMin();

        cocllasl_f02_value = DDS_M_MAX((SInt32)TqCll_tqIncRaw,(SInt32)TqCll_tqIncChaRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncTraRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncLimRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncDrivRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncIdlRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncResRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncEngReqRaw);
        cocllasl_f02_value = DDS_M_MAX(cocllasl_f02_value,(SInt32)TqCll_tqIncAdvMinRaw);
        COCLLASL_F02_13_TqCll_tqIncVld(tqsys_tqidcenglimcord_par, /* BIN4 */
                                       (SInt16)cocllasl_f02_value);
    }

    COCLLASL_F02_09_Param_Opl(eng_nckfil_par, /* BIN2 */
                              copt_nogearcorddrivfil_par,
                              englim_tqidcengcurmax_par /* BIN4 */);

    COCLLASL_F02_00_Calc_Timer_Rst(TqCll_bTranOpl,
                                   (UInt16)((UInt32)TqCll_tiTranOpl * DEC1),
                                   ext_titdc_par,
                                   &cocllasl_f02_tmrrst_val_1_edge_detect,
                                   &cocllasl_tqcll_tioplrun_dec3);
    TqCll_tiOplRun = (UInt16)((UInt32)cocllasl_tqcll_tioplrun_dec3 / DEC1);

    if((UInt32)0 < (UInt32)cocllasl_tqcll_tioplrun_dec3)
    {
        TqCll_bTmrOff = DDS_TRUE;
    }
    else
    {
        TqCll_bTmrOff = DDS_FALSE;
    }

    cocllasl_f02_value = (SInt32)englim_tqidcengcurmax_par - (SInt32)TqSys_tqCkEngLimCordPrev;
    TqCll_tqDifOpl = (SInt16)DDS_M_LIMIT(cocllasl_f02_value,-2000*BIN4,2000*BIN4);

    COCLLASL_F02_07_Calcul_inc_Opl(ext_titdc_par);

    COCLLASL_F02_12_TqCll_tqIncOplVld(
                                 ext_titdc_par, /* DEC3 */
                                 englim_tqidcengcurmax_par /* BIN4 */);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_00_Calc_Timer_Rst
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_00_Calc_Timer_Rst(
                                           UInt8 timer_start,
                                           UInt16 timer_init_val, /* DEC3 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(t_dds_m_edge_detect, AUTOMATIC, AUTOMATIC) edge_str,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) timer_val) /* DEC3 */
{
    /* SSTG_REQ_TAG part of CSMT_CGMT08_0928.FR.4.2*/
    t_dds_m_edge_detected_event cocllasl_f02_00_edge_out;

    cocllasl_f02_00_edge_out = DDS_M_EDGE_DETECT(edge_str,timer_start);
    if(cocllasl_f02_00_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        /* DEC3 = DEC3 */
        *timer_val = timer_init_val;
    }
    else
    {
        if((UInt32)*timer_val <= (UInt32)ext_titdc_par)
        {
            *timer_val = 0;
        }
        else
        {
            /*DEC3 = DEC3 - DEC3 */
            *timer_val = (UInt16)((UInt32)*timer_val - (UInt32)ext_titdc_par);
        }
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_01_Calcul_inc_Cha
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_01_Calcul_inc_Cha(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.5.1 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiChaRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiChaRun * DEC1);
        TqCll_tqIncChaRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncChaRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_02_Calcul_inc_Tra
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_02_Calcul_inc_Tra(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.6.1 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiTraRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiTraRun * DEC1);
        TqCll_tqIncTraRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncTraRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_03_Calcul_inc_Lim
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_03_Calcul_inc_Lim(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.7.1 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiLimRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiLimRun * DEC1);
        TqCll_tqIncLimRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncLimRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_04_Calcul_inc_Driv
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_04_Calcul_inc_Driv(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.8.1 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiDrivRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiDrivRun * DEC1);
        TqCll_tqIncDrivRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncDrivRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_05_Calcul_inc_Idl
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_05_Calcul_inc_Idl(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.9.1 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiIdlRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiIdlRun * DEC1);
        TqCll_tqIncIdlRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncIdlRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_06_Calcul_inc_Reserve
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_06_Calcul_inc_Reserve(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.10.1 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiResRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiResRun * DEC1);
        TqCll_tqIncResRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncResRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_07_Calcul_inc_Opl
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_07_Calcul_inc_Opl(
                                           UInt8 ext_titdc_par /* DEC3 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.11.2 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiOplRun > (UInt32)0)
    {
        /* BIN4 = (BIN4 * DEC3) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = ((SInt32)TqCll_tqDifOpl * (SInt32)ext_titdc_par) / ((SInt32)TqCll_tiOplRun * DEC1);
        TqCll_tqIncOplRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncOplRaw = TqCll_tqIncOplDft_C;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_08_Calcul_inc_Froc
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_08_Calcul_inc_Froc(
                                           UInt8 ext_titdc_par /* DEC3 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.15.0 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiForcRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1)*/
        /*[-20000;20000]= ([-2000;2000]*[0;0,1]) / [0;5]*/
        cocllasl_f02_01_value = ((SInt32)TqCll_tqIncForc * (SInt32)ext_titdc_par) / ((SInt32)TqCll_tiForcRun * DEC1);
        TqCll_tqIncForcRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncForcRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_09_Param_Opl
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_09_Param_Opl(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 copt_nogearcorddrivfil_par,
                                           SInt16 englim_tqidcengcurmax_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.16.1 */
    SInt32 cocllasl_f02_09_value_1;
    SInt32 cocllasl_f02_09_value_2;

    TqCll_tqIncOpl = DDS_M_MAP3D_UUS16(&TQCLL_TQINCOPL_M_APM,eng_nckfil_par,(UInt16)copt_nogearcorddrivfil_par);

    /* BIN4 */
    cocllasl_f02_09_value_1 = (SInt32)englim_tqidcengcurmax_par - (SInt32)TqSys_tqCkEngLimCordPrev;

    cocllasl_f02_09_value_1 = DDS_M_LIMIT(cocllasl_f02_09_value_1, DDS_SINT16_MIN, DDS_SINT16_MAX);
    /* BIN7 */
    cocllasl_f02_09_value_2 = (SInt32)DDS_M_MAP2D_SU16(&TQCLL_FACTITRANOPL_T_APM,(SInt16)cocllasl_f02_09_value_1);
    /* DEC3 */
    cocllasl_f02_09_value_1 = (SInt32)DDS_M_MAP3D_U16(&TQCLL_TITRANOPL_M_APM,eng_nckfil_par,(UInt16)copt_nogearcorddrivfil_par);

    /* DEC2 = (DEC3 * BIN7) / (BIN7 * DEC1)*/
    cocllasl_f02_09_value_1 = (cocllasl_f02_09_value_1 * cocllasl_f02_09_value_2) / (BIN7 * DEC1);

    TqCll_tiTranOpl = (UInt16)DDS_M_MIN(5 * DEC2,cocllasl_f02_09_value_1);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_10_Calcul_inc_EngReq
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_10_Calcul_inc_EngReq(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.17.0 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiEngReqRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiEngReqRun * DEC1);
        TqCll_tqIncEngReqRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncEngReqRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_11_Calcul_inc_AdvMin
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_11_Calcul_inc_AdvMin(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.17.0 */
    SInt32 cocllasl_f02_01_value;

    if((UInt32)TqCll_tiAdvMinRun > (UInt32)0)
    {
        /* BIN4 = (DEC3 * BIN4) / (DEC2 * DEC1) */
        cocllasl_f02_01_value = cocllasl_f02_0x_calcul_num_value / ((SInt32)TqCll_tiAdvMinRun * DEC1);
        TqCll_tqIncAdvMinRaw = (SInt16)DDS_M_SATURATION(cocllasl_f02_01_value,-2000*BIN4,2000*BIN4);
    }
    else
    {
        TqCll_tqIncAdvMinRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_12_TqCll_tqIncOplVld
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_12_TqCll_tqIncOplVld(
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           SInt16 englim_tqidcengcurmax_par /* BIN4 */)
{
    SInt32 cocllasl_f02_value;
    SInt32 cocllasl_f02_value_2;

    /* BIN4 = BIN4 * DEC3 / DEC3 */
    /* [-200;200] = [-2000;2000] * [0;0.1] */
    cocllasl_f02_value = ((SInt32)TqCll_tqIncOpl * (SInt32)ext_titdc_par) / DEC3;
    /*BIN4 [-2000;200]*/
    cocllasl_f02_value = DDS_M_MIN(cocllasl_f02_value,(SInt32)TqCll_tqIncOplRaw);

    /*BIN4 [-4000;4000]*/
    cocllasl_f02_value_2 = (SInt32)englim_tqidcengcurmax_par - (SInt32)cocllasl_englim_tqidcengcurmax_prev;
    cocllasl_f02_value_2 = DDS_M_MAX(cocllasl_f02_value_2,(SInt32)0);

    /* BIN4 = BIN4 * BIN4 / BIN4 */
    /* [-8000000;8000000] = [-4000;4000] * [-2000;2000]*/
    cocllasl_f02_value_2 = (cocllasl_f02_value_2 * (SInt32)TqCll_tqGainDeltaOpl_C) / BIN4;

    /* BIN4 = BIN4 + BIN4 */
    /* [-8002000;8000200] = [-2000;200] + [-8000000;8000000]*/
    cocllasl_f02_value = cocllasl_f02_value + cocllasl_f02_value_2;

    TqCll_tqIncOplVld = (SInt16)DDS_M_SATURATION(cocllasl_f02_value,-2000*BIN4,2000*BIN4);

    /* update prev value */
    cocllasl_englim_tqidcengcurmax_prev = englim_tqidcengcurmax_par;
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_13_TqCll_tqIncVld
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_13_TqCll_tqIncVld(
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           SInt16 sum_input /* BIN4 */)
{
    SInt32 cocllasl_f02_value;

    /* BIN4 [-4000;4000] */
    cocllasl_f02_value = (SInt32)tqsys_tqidcenglimcord_par - (SInt32)cocllasl_tqsys_tqidcenglimcord_prev;
    cocllasl_f02_value = DDS_M_MIN(cocllasl_f02_value,(SInt32)0);

    /* BIN4 = BIN4 * BIN4 / BIN4 */
    /* [-8000000;8000000] = [-4000;4000] * [-2000;2000]*/
    cocllasl_f02_value = (cocllasl_f02_value * (SInt32)TqCll_tqGainDeltaCll_C) / BIN4;

    /* BIN4 = BIN4 + BIN4 */
    /* [-8002000;8002000] = [-2000;2000] - [-8000000;8000000]*/
    cocllasl_f02_value = (SInt32)sum_input - cocllasl_f02_value;

    TqCll_tqIncVld = (SInt16)DDS_M_SATURATION(cocllasl_f02_value,-2000*BIN4,2000*BIN4);

    /* update prev value */
    cocllasl_tqsys_tqidcenglimcord_prev = tqsys_tqidcenglimcord_par;
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_Transition_calculation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Transition_calculation(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           SInt16 tqsys_tqidcenglimcord_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.12.6 */
    t_dds_m_edge_detected_event cocllasl_f03_edge_out;
    SInt32 cocllasl_f02_09_value_1;
    SInt32 cocllasl_s32_value;

    cocllasl_f03_edge_out = DDS_M_EDGE_DETECT(&cocllasl_f03_edge_detect,TqCll_bTranCll);
    if(cocllasl_f03_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        cocllasl_f02_09_value_1 = (SInt32)TqSys_tqCkEngLimCordPrev - (SInt32)TqCll_tqIncVld;
    }
    else
    {
        cocllasl_f02_09_value_1 = (SInt32)TqCll_tqCllTranRaw_MP - (SInt32)TqCll_tqIncVld;
    }
    /* BIN4 [-2000;2000] */
    TqCll_tqCllTranRaw_MP = (SInt16)DDS_M_SATURATION(cocllasl_f02_09_value_1,-2000*BIN4,2000*BIN4);

    cocllasl_f03_edge_out = DDS_M_EDGE_DETECT(&cocllasl_f03_edge_detect_1,TqCll_bReqCll);
    if(cocllasl_f03_edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
    {
        cocllasl_f02_09_value_1 = (SInt32)TqSys_tqCkEngLimCordPrev + (SInt32)TqCll_tqIncOplVld;
    }
    else
    {
        cocllasl_f02_09_value_1 = (SInt32)TqCll_tqOplTranRaw_MP + (SInt32)TqCll_tqIncOplVld;
    }
    /* BIN4 [-2000;2000] */
    TqCll_tqOplTranRaw_MP = (SInt16)DDS_M_SATURATION(cocllasl_f02_09_value_1,-2000*BIN4,2000*BIN4);

    if((UInt32)TqCll_bAcvCllRaw != (UInt32)DDS_FALSE)
    {
        if((UInt32)TqCll_bReqCll != (UInt32)DDS_FALSE)
        {
            if((UInt32)TqCll_bTranCll != (UInt32)DDS_FALSE)
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqCllTran_MP = TqCll_tqCllTranRaw_MP;
            }
            else
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqCllTran_MP = tqsys_tqidcenglimcord_par;
            }

            cocllasl_s32_value = DDS_M_MAX((SInt32)TqCll_tqCllTran_MP,(SInt32)tqsys_tqidcenglimcord_par);
            if((UInt32)TqCll_bLimTranAcv_C != (UInt32)DDS_FALSE)
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqIdcCllRaw_MP = (SInt16)DDS_M_MIN(cocllasl_s32_value,
                                                         (SInt32)englim_tqidcengcurmax_par);
            }
            else
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqIdcCllRaw_MP = (SInt16)cocllasl_s32_value;
            }
        }
        else
        {
            if((UInt32)TqCll_bTranOpl != (UInt32)DDS_FALSE)
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqOplTran_MP = TqCll_tqOplTranRaw_MP;
            }
            else
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqOplTran_MP = englim_tqidcengcurmax_par;
            }

            cocllasl_s32_value = DDS_M_MIN((SInt32)TqCll_tqOplTran_MP,(SInt32)englim_tqidcengcurmax_par);
            if((UInt32)TqCll_bLimTranAcv_C != (UInt32)DDS_FALSE)
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqIdcCllRaw_MP = (SInt16)DDS_M_MAX(cocllasl_s32_value,
                                                         (SInt32)tqsys_tqidcenglimcord_par);
            }
            else
            {
                /* BIN4 [-2000;2000] */
                TqCll_tqIdcCllRaw_MP = (SInt16)cocllasl_s32_value;
            }
        }

        /* BIN4 [-2000;2000] */
        TqSys_tqCkEngLimCordRaw = TqCll_tqIdcCllRaw_MP;
    }
    else
    {
        /* BIN4 [-2000;2000] */
        TqSys_tqCkEngLimCordRaw = englim_tqidcengcurmax_par;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F04_Configuration
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F04_Configuration(
                                           SInt16 tqsys_tqidcenglimcord_par, /* BIN4 */
                                           UInt8 tqsys_btypfu_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckenglimcord_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0928.FR.13.2 */


    TqSys_tqCkEngLimCordPrev = cocllasl_tqsys_tqckenglimcordprev_cpy;

    if((UInt32)tqsys_btypfu_par != (UInt32)DDS_FALSE)
    {
        cocllasl_tqsys_tqckenglimcordprev_cpy = TqSys_tqCkEngLimCordRaw;
    }
    else
    {
        cocllasl_tqsys_tqckenglimcordprev_cpy = tqsys_tqidcenglimcord_par;
    }

    *tqsys_tqckenglimcord_ptr = cocllasl_tqsys_tqckenglimcordprev_cpy;

}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Req_Cll_Opl_Gbl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Req_Cll_Opl_Gbl_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bAcvCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bForcCll_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCll_bReqCllPtl_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLimCord_swc_out /* BIN4 */ )
{
    *TqCll_bAcvCll_swc_out = DDS_FALSE;
    *TqCll_bForcCll_swc_out = DDS_FALSE;
    *TqCll_bReqCllPtl_swc_out = DDS_FALSE;
    *TqCll_bReqCllPtl_swc_out = DDS_FALSE;
    *TqSys_tqCkEngLimCord_swc_out = 0;
    cocllasl_tqcll_bacvcll_loc = DDS_FALSE;
    cocllasl_tqcll_bforccll_loc = DDS_FALSE;

    cocllasl_tqsys_tqckenglimcordprev_cpy = *TqSys_tqCkEngLimCord_swc_out;
    cocllasl_englim_tqidcengcurmax_prev = 0;
    cocllasl_tqsys_tqidcenglimcord_prev = 0;

    cocllasl_f01_01_tmrrst_val = 0;


    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[0],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[1],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[2],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[3],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[4],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[5],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[6],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[7],DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_00_rs_edge_detect[8],DDS_FALSE);

    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_01_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_02_edge_detect_1,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_02_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f01_02_edge_detect_2,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_1_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_2_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_1_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_2_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_3_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_4_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_5_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_6_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_7_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f02_tmrrst_val_vect_8_edge_detect,DDS_FALSE);

    DDS_M_EDGE_DETECT_INIT(&cocllasl_f03_edge_detect,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&cocllasl_f03_edge_detect_1,DDS_FALSE);

    DDS_M_TURN_ON_DELAY_DELTA_INIT(DDS_FALSE,&cocllasl_f01_01_turn_on_delay);
    DDS_M_TURN_OFF_DELAY_DELTA_INIT(DDS_FALSE,&cocllasl_f01_01_turn_off_delay);

    TqCll_bAcvCllPrev = DDS_FALSE;
    TqCll_bAcvCllRaw = DDS_FALSE;
    TqCll_bReqCll = DDS_FALSE;
    TqCll_bReqCllGbl = DDS_FALSE;
    TqCll_bTmrOff = DDS_FALSE;
    TqCll_bTranAdvMin = DDS_FALSE;
    TqCll_bTranCha = DDS_FALSE;
    TqCll_bTranCll = DDS_FALSE;
    TqCll_bTranDriv = DDS_FALSE;
    TqCll_bTranEngReq = DDS_FALSE;
    TqCll_bTranForc = DDS_FALSE;
    TqCll_bTranIdl = DDS_FALSE;
    TqCll_bTranLim = DDS_FALSE;
    TqCll_bTranOpl = DDS_FALSE;
    TqCll_bTranRes = DDS_FALSE;
    TqCll_bTranTra = DDS_FALSE;
    TqCll_tiAdvMinRun = 0;
    TqCll_tiChaRun = 0;
    TqCll_tiDrivRun = 0;
    TqCll_tiEngReqRun = 0;
    TqCll_tiForcRun = 0;
    TqCll_tiIdlRun = 0;
    TqCll_tiLimRun = 0;
    TqCll_tiOplRun = 0;
    TqCll_tiResRun = 0;
    TqCll_tiTraRun = 0;
    TqCll_tiTranOpl = 0;
    TqCll_tqCllTranRaw_MP = 0;
    TqCll_tqCllTran_MP = 0;
    TqCll_tqDifCll = 0;
    TqCll_tqDifOpl = 0;
    TqCll_tqIdcCllRaw_MP = 0;
    TqCll_tqIncAdvMinRaw = 0;
    TqCll_tqIncChaRaw = 0;
    TqCll_tqIncCha_MP = 0;
    TqCll_tqIncDrivRaw = 0;
    TqCll_tqIncDriv_MP = 0;
    TqCll_tqIncEngReqRaw = 0;
    TqCll_tqIncForc = 0;
    TqCll_tqIncForcRaw = 0;
    TqCll_tqIncIdlRaw = 0;
    TqCll_tqIncIdl_MP = 0;
    TqCll_tqIncLimRaw = 0;
    TqCll_tqIncLim_MP = 0;
    TqCll_tqIncOpl = 0;
    TqCll_tqIncOplRaw = 0;
    TqCll_tqIncOplVld = 0;
    TqCll_tqIncRaw = 0;
    TqCll_tqIncResRaw = 0;
    TqCll_tqIncRes_MP = 0;
    TqCll_tqIncTraRaw = 0;
    TqCll_tqIncTra_MP = 0;
    TqCll_tqIncVld = 0;
    TqCll_tqOplTranRaw_MP = 0;
    TqCll_tqOplTran_MP = 0;
    TqSys_tqCkEngLimCordPrev = 0;
    TqSys_tqCkEngLimCordRaw = 0;
    cocllasl_tqcll_breqcllptl_loc = *TqCll_bReqCllPtl_swc_out;

    cocllasl_tqcll_ticharun_dec3 = 0;
    cocllasl_tqcll_titrarun_dec3 = 0;
    cocllasl_tqcll_tilimrun_dec3 = 0;
    cocllasl_tqcll_tidrivrun_dec3 = 0;
    cocllasl_tqcll_tiidlrun_dec3 = 0;
    cocllasl_tqcll_tiresrun_dec3 = 0;
    cocllasl_tqcll_tiengreqrun_dec3 = 0;
    cocllasl_tqcll_tiadvminrun_dec3 = 0;
    cocllasl_tqcll_tiforcrun_dec3 = 0;
    cocllasl_tqcll_tioplrun_dec3 = 0;

}

#define COCLLASL_STOP_SEC_CODE
#include "CoClLASl_MemMap.h"

