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
* Ref X:\integration_view_00PSASWC_EA30D11\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Bva_Bmp_Anti_Stall.c
* Version int :/main/C00_00/1 Date: 21/1/2014 11 h 59 m User:groult 
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_C00_000_IMPL1
*    comments :dev CoClLASl 13.0
* Version dev :\main\branch_lemort\1 Date: 17/12/2013 15 h 33 m User:lemort 
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_C00_000_IMPL1
*    comments :dev CoClLASl 13.0
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 41 m User:meme
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 1/10/2010 12 h 29 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 20/9/2010 12 h 41 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1_D
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 56 m User:esnault
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\8 Date: 1/9/2010 9 h 54 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\7 Date: 31/8/2010 17 h 42 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 26/8/2010 11 h 23 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 25/8/2010 11 h 34 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :fpr CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 29/7/2010 17 h 33 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 22/7/2010 11 h 35 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 10 h 13 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 39 m User:morisseau
*    TWK_model:COCLLASL_Bva_Bmp_Anti_Stall_L01_010_IMPL1
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
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_nAcvAntiStall_C = (UInt16)(2000 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_nGrdThdAntiStallDft_C = (SInt16)(-2000 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_nGrdThdAntiStall_C = (SInt16)(-2000 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_spdThdAntiStall_C = (UInt16)(5 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tCoDft_C = (SInt16)(0 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_tiDeacAntiStallIdl_C = (UInt16)(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_tiDeacAntiStallSmk_C = (UInt16)(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_tiDeacAntiStallSpd_C = (UInt16)(2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_tiDeacAntiStall_C = (UInt16)(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_tiMaxAntiStall_C = (UInt16)(0.5 * DEC2);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits scalar calibration definition */
#define COCLLASL_START_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bAcvAntiStallBrk_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bAcvAntiStallStPt_C = DDS_TRUE;
#define COCLLASL_STOP_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COCLLASL_START_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_bAcvAntiStallStCpl_T
[COCLLASL_4_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_nThdAntiStall_T
[COCLLASL_6_SIZE] = {
(UInt16)(1800 * BIN0), (UInt16)(1600 * BIN0), (UInt16)(1400 * BIN0),
(UInt16)(1200 * BIN0), (UInt16)(1200 * BIN0), (UInt16)(1200 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tCoAntiStall_A[COCLLASL_6_SIZE] = {
(SInt16)(-30 * BIN0), (SInt16)(-15 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(40 * BIN0), (SInt16)(80 * BIN0), (SInt16)(100 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_stCplAntiStall_A[COCLLASL_4_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0)
};

#define COCLLASL_STOP_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) copt_bacvantistallstcpl_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) copt_nthdantistall_t_sav;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) cocllasl_f03_07_turn_off_delay_1;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) cocllasl_f03_07_turn_off_delay_2;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) cocllasl_f03_07_turn_off_delay_3;
#define COCLLASL_STOP_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"

#define COCLLASL_START_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) cocllasl_f03_04_counter;
STATIC VAR(UInt32, AUTOMATIC) cocllasl_f03_07_counter;
#define COCLLASL_STOP_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"

#define COCLLASL_START_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) copt_bacvantistallfil_loc;
STATIC VAR(UInt8, AUTOMATIC) tqsys_bacvantistallsmk_loc;
STATIC VAR(UInt8, AUTOMATIC) tqsys_bacvantistallaut_loc;
#define COCLLASL_STOP_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAcvAntiStallBrk;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAcvAntiStallNEng;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAcvAntiStallNGrd;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAcvAntiStallRaw;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAcvAntiStallSpdVeh;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAcvAntiStallStPt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) CoPt_bAuthAcvAntiStall;
#define COCLLASL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COCLLASL_START_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) COPT_BACVANTISTALLSTCPL_T_APM = {
&copt_bacvantistallstcpl_t_sav,
COCLLASL_4_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&CoPt_stCplAntiStall_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&CoPt_bAcvAntiStallStCpl_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) COPT_NTHDANTISTALL_T_APM = {
&copt_nthdantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&CoPt_tCoAntiStall_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&CoPt_nThdAntiStall_T[0]
};

#define COCLLASL_STOP_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Regime_Activation(
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt8 ext_stgbxcf_par);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Activation_Anticalage(
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt8 cobrk_bacvbrk_par,
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 frm_binhcoptbrk_par,
                                           UInt8 frm_binhcoptspdveh_par,
                                           UInt8 frm_binhcoptstpt_par,
                                           UInt8 frm_binhcopttco_par,
                                           SInt16 treattdc_nckgrd_par, /* BIN2 */
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) copt_bacvantistallfil_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallsmk_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqsys_bacvantistallaut_ptr );

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_01_Condition_Frein(
                                           UInt8 cobrk_bacvbrk_par,
                                           UInt8 frm_binhcoptbrk_par);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_02_Condition_Gradient_Regime(
                                           SInt16 treattdc_nckgrd_par, /* BIN2 */
                                           UInt8 frm_binhcoptbrk_par,
                                           UInt8 frm_binhcoptspdveh_par,
                                           UInt8 frm_binhcoptstpt_par);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_03_Condition_Etat_Cdt(
                                           UInt8 copt_stcpl_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 frm_binhcoptstpt_par);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_04_Condition_Vitesse(
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 frm_binhcoptspdveh_par);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_05_Condition_Regime(
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 frm_binhcopttco_par);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_06_Coordination_conditions_activation(void);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_07_Filtrage_Activation(
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) copt_bacvantistallfil_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallsmk_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallaut_ptr );

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Bva_Bmp_Anti_Stall
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Bva_Bmp_Anti_Stall(UInt8 CoPt_bTqTx_swc_in,
                                           UInt8 CoPt_stCpl_swc_in,
                                           UInt8 CoBrk_bAcvBrk_swc_in,
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 FRM_bInhCoPtBrk_swc_in,
                                           UInt8 FRM_bInhCoPtSpdVeh_swc_in,
                                           UInt8 FRM_bInhCoPtStPt_swc_in,
                                           UInt8 FRM_bInhCoPtTCo_swc_in,
                                           SInt16 TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvAntiStallFil_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallSmk_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqSys_bAcvAntiStallAut_swc_out)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.1.2 */

    COCLLASL_F02_Regime_Activation(Ext_nEng_swc_in, /* BIN0 */
                                   Ext_stGBxCf_swc_in);

    if((UInt32)CoPt_bAuthAcvAntiStall != (UInt32)DDS_FALSE)
    {
        COCLLASL_F03_Activation_Anticalage(CoPt_bTqTx_swc_in,
                                           CoPt_stCpl_swc_in,
                                           CoBrk_bAcvBrk_swc_in,
                                           Ext_nEng_swc_in, /* BIN0 */
                                           Ext_tCoMes_swc_in, /* BIN0 */
                                           Ext_tiTDC_swc_in, /* DEC3 */
                                           FRM_bInhCoPtBrk_swc_in,
                                           FRM_bInhCoPtSpdVeh_swc_in,
                                           FRM_bInhCoPtStPt_swc_in,
                                           FRM_bInhCoPtTCo_swc_in,
                                           TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           Veh_spdVeh_swc_in, /* BIN7 */
                                           &copt_bacvantistallfil_loc,
                                           &tqsys_bacvantistallsmk_loc,
                                           &tqsys_bacvantistallaut_loc);
    }
    else
    {
        /* Nothing to do */
    }
    *CoPt_bAcvAntiStallFil_swc_out = copt_bacvantistallfil_loc;
    *TqSys_bAcvAntiStallSmk_swc_out = tqsys_bacvantistallsmk_loc;
    *TqSys_bAcvAntiStallAut_swc_out = tqsys_bacvantistallaut_loc;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F02_Regime_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Regime_Activation(
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt8 ext_stgbxcf_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.9.0 */

    if(  ((UInt32)ext_neng_par <= (UInt32)CoPt_nAcvAntiStall_C)
       &&((UInt32)ext_stgbxcf_par != 0))
    {
        CoPt_bAuthAcvAntiStall = DDS_TRUE;
    }
    else
    {
        CoPt_bAuthAcvAntiStall = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_Activation_Anticalage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Activation_Anticalage(
                                           UInt8 copt_btqtx_par,
                                           UInt8 copt_stcpl_par,
                                           UInt8 cobrk_bacvbrk_par,
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 frm_binhcoptbrk_par,
                                           UInt8 frm_binhcoptspdveh_par,
                                           UInt8 frm_binhcoptstpt_par,
                                           UInt8 frm_binhcopttco_par,
                                           SInt16 treattdc_nckgrd_par, /* BIN2 */
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) copt_bacvantistallfil_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallsmk_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallaut_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.2.2 */
    COCLLASL_F03_01_Condition_Frein(
                  cobrk_bacvbrk_par,
                  frm_binhcoptbrk_par);

    COCLLASL_F03_02_Condition_Gradient_Regime(
                  treattdc_nckgrd_par, /* BIN2 */
                  frm_binhcoptbrk_par,
                  frm_binhcoptspdveh_par,
                  frm_binhcoptstpt_par);

    COCLLASL_F03_03_Condition_Etat_Cdt(
                  copt_stcpl_par,
                  copt_btqtx_par,
                  frm_binhcoptstpt_par);

    COCLLASL_F03_04_Condition_Vitesse(
                  veh_spdveh_par, /* BIN7 */
                  ext_titdc_par, /* DEC3 */
                  frm_binhcoptspdveh_par);

    COCLLASL_F03_05_Condition_Regime(
                  ext_neng_par, /* BIN0 */
                  ext_tcomes_par, /* BIN0 */
                  frm_binhcopttco_par);

    COCLLASL_F03_06_Coordination_conditions_activation();

    COCLLASL_F03_07_Filtrage_Activation(
                  ext_titdc_par, /* DEC3 */
                  copt_bacvantistallfil_ptr,
                  tqsys_bacvantistallsmk_ptr,
                  tqsys_bacvantistallaut_ptr );
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_01_Condition_Frein
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_01_Condition_Frein(
                                           UInt8 cobrk_bacvbrk_par,
                                           UInt8 frm_binhcoptbrk_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.3.1 */
    if(  ((UInt32)CoPt_bAcvAntiStallBrk_C == (UInt32)DDS_TRUE)
       &&((UInt32)frm_binhcoptbrk_par == (UInt32)DDS_FALSE))
    {
        CoPt_bAcvAntiStallBrk = cobrk_bacvbrk_par;
    }
    else
    {
        CoPt_bAcvAntiStallBrk = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_02_Condition_Gradient_Regime
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_02_Condition_Gradient_Regime(
                                           SInt16 treattdc_nckgrd_par, /* BIN2 */
                                           UInt8 frm_binhcoptbrk_par,
                                           UInt8 frm_binhcoptspdveh_par,
                                           UInt8 frm_binhcoptstpt_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.4.1 */
    if(  ((UInt32)frm_binhcoptbrk_par == (UInt32)DDS_TRUE)
       ||((UInt32)frm_binhcoptspdveh_par == (UInt32)DDS_TRUE)
       ||((UInt32)frm_binhcoptstpt_par == (UInt32)DDS_TRUE))
    {
        if((SInt32)treattdc_nckgrd_par <= (((SInt32)CoPt_nGrdThdAntiStallDft_C)*BIN2))
        {
            CoPt_bAcvAntiStallNGrd = DDS_TRUE;
        }
        else
        {
            CoPt_bAcvAntiStallNGrd = DDS_FALSE;
        }
    }
    else
    {
        if((SInt32)treattdc_nckgrd_par <= (((SInt32)CoPt_nGrdThdAntiStall_C)*BIN2))
        {
            CoPt_bAcvAntiStallNGrd = DDS_TRUE;
        }
        else
        {
            CoPt_bAcvAntiStallNGrd = DDS_FALSE;
        }
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_03_Condition_Etat_Cdt
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_03_Condition_Etat_Cdt(
                                           UInt8 copt_stcpl_par,
                                           UInt8 copt_btqtx_par,
                                           UInt8 frm_binhcoptstpt_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.5.1 */
    UInt32 cocllasl_f03_03_value;

    cocllasl_f03_03_value = (UInt32)DDS_M_MAP2D_U16(&COPT_BACVANTISTALLSTCPL_T_APM,(UInt16)copt_stcpl_par);

    if((UInt32)frm_binhcoptstpt_par != (UInt32)DDS_FALSE)
    {
        CoPt_bAcvAntiStallStPt = CoPt_bAcvAntiStallStPt_C;
    }
    else if((UInt32)copt_btqtx_par != (UInt32)DDS_TRUE)
    {
        CoPt_bAcvAntiStallStPt = DDS_FALSE;
    }
    else
    {
        if(cocllasl_f03_03_value == (UInt32)1)
        {
            CoPt_bAcvAntiStallStPt = DDS_TRUE;
        }
        else
        {
            CoPt_bAcvAntiStallStPt = DDS_FALSE;
        }
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_04_Condition_Vitesse
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_04_Condition_Vitesse(
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 frm_binhcoptspdveh_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.6.1 */
    if((UInt32)veh_spdveh_par < ((UInt32)CoPt_spdThdAntiStall_C*BIN7))
    {
        cocllasl_f03_04_counter = cocllasl_f03_04_counter + (UInt32)ext_titdc_par;
        cocllasl_f03_04_counter = DDS_M_MIN(400*DEC3,cocllasl_f03_04_counter);
    }
    else
    {
        cocllasl_f03_04_counter = 0;
    }

    if(  ((UInt32)frm_binhcoptspdveh_par == (UInt32)DDS_TRUE)
       ||(cocllasl_f03_04_counter < (((UInt32)CoPt_tiDeacAntiStallSpd_C)*DEC1)))
    {
        CoPt_bAcvAntiStallSpdVeh = DDS_TRUE;
    }
    else
    {
        CoPt_bAcvAntiStallSpdVeh = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_05_Condition_Regime
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_05_Condition_Regime(
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 frm_binhcopttco_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.7.1 */
    UInt32 cocllasl_f03_05_value;


    if((UInt32)frm_binhcopttco_par != (UInt32)DDS_FALSE)
    {
        cocllasl_f03_05_value = (UInt32)DDS_M_MAP2D_SU16(&COPT_NTHDANTISTALL_T_APM,CoPt_tCoDft_C);
    }
    else
    {
        cocllasl_f03_05_value = (UInt32)DDS_M_MAP2D_SU16(&COPT_NTHDANTISTALL_T_APM,ext_tcomes_par);
    }

    if(  ((UInt32)ext_neng_par != (UInt32)0)
       &&((UInt32)ext_neng_par <= cocllasl_f03_05_value))
    {
        CoPt_bAcvAntiStallNEng = DDS_TRUE;
    }
    else
    {
        CoPt_bAcvAntiStallNEng = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_06_Coordination_conditions_activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_06_Coordination_conditions_activation(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.10.0 */
    if(  ((UInt32)CoPt_bAcvAntiStallBrk == (UInt32)DDS_FALSE)
       ||((UInt32)CoPt_bAcvAntiStallNGrd == (UInt32)DDS_FALSE)
       ||((UInt32)CoPt_bAcvAntiStallStPt == (UInt32)DDS_FALSE)
       ||((UInt32)CoPt_bAcvAntiStallSpdVeh == (UInt32)DDS_FALSE)
       ||((UInt32)CoPt_bAcvAntiStallNEng == (UInt32)DDS_FALSE))
    {
        CoPt_bAcvAntiStallRaw = DDS_FALSE;
    }
    else
    {
        CoPt_bAcvAntiStallRaw = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_07_Filtrage_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_07_Filtrage_Activation(
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) copt_bacvantistallfil_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallsmk_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallaut_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0938.FR.8.1 */
    UInt8 cocllasl_f03_07_value;
    UInt32 cocllasl_te;

    if((UInt32)CoPt_bAcvAntiStallRaw == (UInt32)DDS_TRUE)
    {
        cocllasl_f03_07_counter = cocllasl_f03_07_counter + (UInt32)ext_titdc_par;
        cocllasl_f03_07_counter = DDS_M_MIN(400*DEC3,cocllasl_f03_07_counter);

        if(cocllasl_f03_07_counter < (((UInt32)CoPt_tiMaxAntiStall_C)*DEC1))
        {
            cocllasl_f03_07_value = DDS_TRUE;
        }
        else
        {
            cocllasl_f03_07_value = DDS_FALSE;
        }
    }
    else
    {
        cocllasl_f03_07_counter = 0;
        cocllasl_f03_07_value = DDS_FALSE;
    }



    cocllasl_te = DDS_COCLLASL_1MS_U32_TIME;


    *copt_bacvantistallfil_ptr = DDS_M_TURN_OFF_DELAY(cocllasl_f03_07_value,
                                                      cocllasl_te,
                                                      ((UInt32)CoPt_tiDeacAntiStall_C*DEC1),
                                                      &cocllasl_f03_07_turn_off_delay_1);

    *tqsys_bacvantistallaut_ptr = DDS_M_TURN_OFF_DELAY(cocllasl_f03_07_value,
                                                  cocllasl_te,
                                                  ((UInt32)CoPt_tiDeacAntiStallIdl_C*DEC1),
                                                  &cocllasl_f03_07_turn_off_delay_2);

    *tqsys_bacvantistallsmk_ptr = DDS_M_TURN_OFF_DELAY(cocllasl_f03_07_value,
                                                       cocllasl_te,
                                                       ((UInt32)CoPt_tiDeacAntiStallSmk_C*DEC1),
                                                       &cocllasl_f03_07_turn_off_delay_3);
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Bva_Bmp_Anti_Stall_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Bva_Bmp_Anti_Stall_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvAntiStallFil_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallSmk_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqSys_bAcvAntiStallAut_swc_out )
{
    *CoPt_bAcvAntiStallFil_swc_out = DDS_FALSE;
    *TqSys_bAcvAntiStallSmk_swc_out = DDS_FALSE;
    *TqSys_bAcvAntiStallAut_swc_out = DDS_FALSE;
    copt_bacvantistallfil_loc = DDS_FALSE;
    tqsys_bacvantistallsmk_loc = DDS_FALSE;
    tqsys_bacvantistallaut_loc = DDS_FALSE;

    cocllasl_f03_04_counter = 0;
    cocllasl_f03_07_counter = 0;

    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&cocllasl_f03_07_turn_off_delay_1);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&cocllasl_f03_07_turn_off_delay_2);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&cocllasl_f03_07_turn_off_delay_3);

    CoPt_bAuthAcvAntiStall = DDS_FALSE;
    CoPt_bAcvAntiStallBrk = DDS_FALSE;
    CoPt_bAcvAntiStallNGrd = DDS_FALSE;
    CoPt_bAcvAntiStallStPt = DDS_FALSE;
    CoPt_bAcvAntiStallSpdVeh = DDS_FALSE;
    CoPt_bAcvAntiStallNEng = DDS_FALSE;
    CoPt_bAcvAntiStallRaw = DDS_FALSE;

}



#define COCLLASL_STOP_SEC_CODE
#include "CoClLASl_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 7.10
* Date: 10/12/2013 13:24:27
* PERL v5.14.2
* Lib_CC 1.37
* Lib_Clipboard 1.01
* Lib_Code_Writer 1.00
* Lib_CQ 1.22
* Lib_DD_Check 2.13
* Lib_DD_Check_Checks 1.51
* Lib_DD_Check_Data 2.10
* Lib_DD_Check_Utils 2.14
* Lib_DD_Compare 1.11
* Lib_DD_GenCode 3.31
* Lib_DD_Load 3.11
* Lib_DD_Structure 1.11
* Lib_Feature 1.03
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.03
* Lib_Gui_ComboBox 1.07
* Lib_Gui_Common 1.43
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.02
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.18
* Lib_Hash 1.33
* Lib_Log 1.32
* Lib_Maths 1.10
* Lib_Pjt 1.32
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.30
* Lib_Scheduler_XML 1.50
* Lib_Spectool_Gen_DD 2.33
* Lib_Twk 1.06
* Lib_Utils 1.06
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.09
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* INPUT_SECTION *
CoPt_bTqTx ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat transmission de couple ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_stCpl ;["OUVERT"*0*|"GLISSANT_REEL"*1*|"GLISSANT_POTENTIEL"*2*|"FERME"*3*] ;COPT ;N/A ;0 ;3 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat couplage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoBrk_bAcvBrk ;["FALSE"|"TRUE"] ;EXT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flux frein coordonné ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_nEng ; ;EXT ;rpm ;0 ;7500 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Regime moteur mesure sur une phase moteur ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_stGBxCf ;["BVM"*0*|"BVA"*1*|"BVMP"*2*] ;EXT ;N/A ;0 ;2 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Type de boite0=BVM1=BVA2=BVMP ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_tCoMes ; ;EXT ;deg C ;-40 ;214 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Teau post traitement envoyee a l applicatif ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_tiTDC ; ;EXT ;s ;0 ;0.1 ;1/1000 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Temps entre 2 PMH ;["YES"] ;UInt8 ;DEC3 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
FRM_bInhCoPtBrk ;["FALSE"|"TRUE"] ;FRM ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Inhibition de la prise en compte de l info frein ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
FRM_bInhCoPtSpdVeh ;["FALSE"|"TRUE"] ;FRM ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Inhibition de la prise en compte de la vitesse vehicule ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
FRM_bInhCoPtStPt ;["FALSE"|"TRUE"] ;FRM ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Inhibition de la prise en compte des infos d etat de la chaine de traction ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
FRM_bInhCoPtTCo ;["FALSE"|"TRUE"] ;FRM ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Inhibition de la prise en compte de la temperature d eau moteur ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TreatTDC_nCkGrd ; ;TREATTDC ;rpm/s ;-8000 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Derivee de regime moteur au PMH ;["YES"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Veh_spdVeh ; ;VEH ;km/h ;0 ;500 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Vitesse vehicule ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
CoPt_bAcvAntiStallFil ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen de demande d activation de l anti-calage pourBVA/BVMP ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallAut ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["NULL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag d activation de la strategie d anti-calage BVA/BVMP utilisee par la strategie IVC ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallSmk ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag d activation de la strategie d anti-calage BVA/BVMP utilisee par la strategie de cartographies fumee ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
COCLLASL_4_SIZE ; ;COCLLASL ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;4 ;Type for axis ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
COCLLASL_6_SIZE ; ;COCLLASL ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;6 ;Type for axis ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallBrk ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Condition d activation sur l appui frein ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallBrk_C ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Prise en compte de l info frein pour l anticalage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallNEng ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Condition d activation sur le regime moteur ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallNGrd ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Condition d activation sur le gradient de regime ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallRaw ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Condition d activation de l anticalage brute ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallSpdVeh ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Condition de desactivation sur la vitesse vehicule ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallStCpl_T ; ;COPT ;N/A ;0 ;1 ;1 ;["MAP"] ;["N/A"] ;CoPt_stCpl ;N/A ;N/A ;[0 0 1 1] ;Activation de l anticalage en fonction de l etat couplage ;["YES"] ;DDS_M_MAP2D_U16 ;BIN0 ;CoPt_stCplAntiStall_A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallStPt ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Condition d activation sur l etat de la chaine de traction ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallStPt_C ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Activation de l anticalage en cas de defaut des infos d etat chaine de traction ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAuthAcvAntiStall ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Autorisation d activation de la strategie d anticalage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_nAcvAntiStall_C ; ;COPT ;rpm ;0 ;7500 ;10 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Regime pour activer l anticalage ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_nGrdThdAntiStallDft_C ; ;COPT ;rpm/s ;-8000 ;8000 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;-2000 ;Gradient de regime pour activer l anticalage en cas de defauts ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_nGrdThdAntiStall_C ; ;COPT ;rpm/s ;-8000 ;8000 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;-2000 ;Gradient de regime pour activer l anticalage ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_nThdAntiStall_T ; ;COPT ;rpm ;0 ;8000 ;10 ;["MAP"] ;["N/A"] ;N/A ;N/A ;N/A ;[1800 1600 1400 1200 1200 1200] ;Regime mini pour activer l anticalage ;["YES"] ;DDS_M_MAP2D_SU16 ;BIN0 ;CoPt_tCoAntiStall_A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_spdThdAntiStall_C ; ;COPT ;km/h ;0 ;500 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;5 ;Seuil de vitesse pour desactiver l anticalage ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_stCplAntiStall_A ;1{t_copt_stcplantistall_a}COCLLASL_4_SIZE ;COPT ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 1 2 3] ;Bkpt "Etat couplage" ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tCoAntiStall_A ;1{t_copt_tcoantistall_a}COCLLASL_6_SIZE ;COPT ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[ -30 -15 0 40 80 100] ;Bkpt "Temperature eau moteur" ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tCoDft_C ; ;COPT ;deg C ;-40 ;214 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Temperature d eau moteur en cas de defaut ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tiDeacAntiStallIdl_C ; ;COPT ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.5 ;Tempo de maintien de l anticalage pour le ralenti ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tiDeacAntiStallSmk_C ; ;COPT ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.5 ;Tempo de maintien de l anticalage pour les cartos fumees ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tiDeacAntiStallSpd_C ; ;COPT ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2 ;Tempo pour desactiver l anticalage sur une condition de vitesse ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tiDeacAntiStall_C ; ;COPT ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.5 ;Tempo de maintien de l anticalage ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tiMaxAntiStall_C ; ;COPT ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.5 ;Tempo max d activation de l anticalage ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_copt_stcplantistall_a ; ;COPT ;N/A ;0 ;3 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_copt_tcoantistall_a ; ;COPT ;deg C ;-40 ;214 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis ;["NO"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

