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
* Ref X:\integration_view_00PSASWC_EA12D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Bvm_Anti_Stall_Reg.c
* Version int :/main/L04_01/2 Date: 6/6/2011 10 h 43 m User:esnault 
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L04_010_IMPL1_D
*    comments :UT correction
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 3/5/2011 16 h 42 m User:morisseau 
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L04_010_IMPL1_D
*    comments :UT correction
* Version dev :\main\branch_demezil_cocllasl_view\1 Date: 3/5/2011 9 h 55 m User:demezil
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L04_010_IMPL1_D
*    comments :correction following TU report
* Version int :/main/L04_01/1 Date: 17/3/2011 9 h 26 m User:esnault
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L04_010_IMPL1
*    comments :update for CoClLASl 11.1
* Version dev :\main\branch_demezil_cocllasl_view\2 Date: 15/3/2011 17 h 26 m User:demezil
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L04_010_IMPL1
*    comments :update for CoClLASl 11.1
* Version dev :\main\branch_demezil_cocllasl_view\1 Date: 15/3/2011 15 h 35 m User:demezil
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L04_010_IMPL1
*    comments :update for CoClLASl 11.1
* Version int :/main/L03_01/1 Date: 25/2/2011 11 h 30 m User:esnault
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L03_010_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\4 Date: 9/2/2011 17 h 57 m User:halouane
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L03_010_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\3 Date: 9/2/2011 17 h 51 m User:halouane
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L03_010_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\2 Date: 9/2/2011 17 h 42 m User:halouane
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L03_010_IMPL1
*    comments :update for TU.
* Version dev :\main\branch_halouane_CoClLASl_dev\1 Date: 3/2/2011 16 h 23 m User:halouane
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L03_010_IMPL1
*    comments :update for 11.0
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 41 m User:meme
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 1/10/2010 12 h 30 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L02_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 56 m User:esnault
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 31/8/2010 17 h 43 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 25/8/2010 11 h 34 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
*    comments :fpr CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 29/7/2010 17 h 33 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 22/7/2010 11 h 35 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 11 h 10 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 39 m User:morisseau
*    TWK_model:COCLLASL_Bvm_Anti_Stall_Reg_L01_010_IMPL1
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

/* NONE */


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEngThdAcvAntiCal_C = (CONST(UInt16, AUTOMATIC))(2000 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqAntiStallMax_C = (CONST(UInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqAntiStallMin_C = (CONST(SInt16, AUTOMATIC))(-2000 * BIN4);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) cocllasl_f02_bvm_hyst;
#define COCLLASL_STOP_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/* 16-bits variable definition */
#define COCLLASL_START_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqsys_ntardynidl_prev[COCLLASL_2_SIZE];
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckantistall_prev;
#define COCLLASL_STOP_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"

/* 32-bits variable definition */
#define COCLLASL_START_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) cocllasl_f03_switch_out[COCLLASL_2_SIZE];
#define COCLLASL_STOP_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvRegAntiStall;
#define COCLLASL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Activation(
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 tqsys_btypfu_par,
                                           UInt16 ext_neng_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_AntiCalage_Regulateur(
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt16 ext_neng1_par, /* BIN2 */
                                           UInt16 ext_neng2_par, /* BIN2 */
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidl_par, /* BIN4 */
                                           SInt16 tqsys_tqckidlmax_par, /* BIN4 */
                                           SInt16 tqsys_tqckidlmin_par, /* BIN4 */
                                           UInt8 tqsys_bacvantistallman_par,
                                           UInt16 tqsys_facantistall1_par, /* BIN14 */
                                           UInt16 tqsys_facantistall2_par, /* BIN14 */
                                           UInt16 tqsys_facantistall3_par, /* BIN14 */
                                           UInt16 tqsys_factqckantistall_par, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckantistall_ptr /* BIN4 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Bvm_Anti_Stall_Reg
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Bvm_Anti_Stall_Reg(UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt16 Ext_nEng1_swc_in, /* BIN2 */
                                           UInt16 Ext_nEng2_swc_in, /* BIN2 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_nTarDynIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqCkIdl_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkIdlMax_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkIdlMin_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAcvAntiStallMan_swc_in,
                                           UInt16 TqSys_facAntiStall1_swc_in, /* BIN14 */
                                           UInt16 TqSys_facAntiStall2_swc_in, /* BIN14 */
                                           UInt16 TqSys_facAntiStall3_swc_in, /* BIN14 */
                                           UInt16 TqSys_facTqCkAntiStall_swc_in, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAntiStall_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2103.FR.1.0 */

    COCLLASL_F02_Activation(Ext_stGBxCf_swc_in,
                            TqSys_bTypFu_swc_in,
                            Ext_nEng_swc_in /* BIN0 */);

    if((UInt32)TqSys_bAcvRegAntiStall != (UInt32)DDS_FALSE)
    {
        COCLLASL_F03_AntiCalage_Regulateur(Ext_nEng_swc_in, /* BIN0 */
                                           Ext_nEng1_swc_in, /* BIN2 */
                                           Ext_nEng2_swc_in, /* BIN2 */
                                           TqSys_nTarDynIdl_swc_in, /* BIN2 */
                                           TqSys_tqCkIdl_swc_in, /* BIN4 */
                                           TqSys_tqCkIdlMax_swc_in, /* BIN4 */
                                           TqSys_tqCkIdlMin_swc_in, /* BIN4 */
                                           TqSys_bAcvAntiStallMan_swc_in,
                                           TqSys_facAntiStall1_swc_in, /* BIN14 */
                                           TqSys_facAntiStall2_swc_in, /* BIN14 */
                                           TqSys_facAntiStall3_swc_in, /* BIN14 */
                                           TqSys_facTqCkAntiStall_swc_in, /* BIN10 */
                                           TqSys_tqCkAntiStall_swc_out /* BIN4 */);
    }
    else
    {
        *TqSys_tqCkAntiStall_swc_out = tqsys_tqckantistall_prev;
    }
    tqsys_tqckantistall_prev = *TqSys_tqCkAntiStall_swc_out;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Activation(
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 tqsys_btypfu_par,
                                           UInt16 ext_neng_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2103.FR.2.0 */
    UInt32 cocllasl_f02_hyst_out;

    cocllasl_f02_hyst_out = (UInt32)DDS_M_HYST_PH_S32(&cocllasl_f02_bvm_hyst,
                                                      (SInt32)ext_neng_par,
                                                      (SInt32)TqSys_nEngThdAcvAntiCal_C,
                                                      (SInt32)TqSys_nEngThdAcvAntiCal_C - (SInt32)50);

    if(  (cocllasl_f02_hyst_out == (UInt32)DDS_FALSE)
       &&((UInt32)ext_stgbxcf_par == (UInt32)0)
       &&((UInt32)tqsys_btypfu_par == (UInt32)DDS_FALSE))
    {
        TqSys_bAcvRegAntiStall = DDS_TRUE;
    }
    else
    {
        TqSys_bAcvRegAntiStall = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_AntiCalage_Regulateur(
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt16 ext_neng1_par, /* BIN2 */
                                           UInt16 ext_neng2_par, /* BIN2 */
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidl_par, /* BIN4 */
                                           SInt16 tqsys_tqckidlmax_par, /* BIN4 */
                                           SInt16 tqsys_tqckidlmin_par, /* BIN4 */
                                           UInt8 tqsys_bacvantistallman_par,
                                           UInt16 tqsys_facantistall1_par, /* BIN14 */
                                           UInt16 tqsys_facantistall2_par, /* BIN14 */
                                           UInt16 tqsys_facantistall3_par, /* BIN14 */
                                           UInt16 tqsys_factqckantistall_par, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckantistall_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2103.FR.3.0 */
    SInt32 cocllasl_f03_value_1;
    SInt32 cocllasl_f03_value_2;
    SInt32 cocllasl_f03_value_3;
    SInt32 cocllasl_f03_add_1;
    SInt32 cocllasl_f03_add_2;
    SInt32 cocllasl_f03_add_3;
    SInt32 cocllasl_f03_value_4;
    SInt32 cocllasl_f03_value_5;
    SInt32 cocllasl_f03_add;

    if((UInt32)tqsys_bacvantistallman_par != (UInt32)DDS_FALSE)
    {
        /* BIN2 = BIN2 + BIN0 * BIN2 */
        /* [-7500;8000] = [0;8000] - [0;7500] */
        cocllasl_f03_value_1 = (SInt32)tqsys_ntardynidl_par - ((SInt32)ext_neng_par * BIN2);

        /* BIN2 = BIN2 + BIN2 */
        /* [-8000;8000] = [0;8000] - [0;8000] */
        cocllasl_f03_value_2 = (SInt32)tqsys_ntardynidl_prev[0] - (SInt32)ext_neng1_par;

        /* calculate input 3 of mult block: cocllasl_f03_value_3 */
        /* BIN2 = BIN2 - 2*BIN2 + BIN2 - BIN2 */
        /* [-31500;32000] = [-7500;8000] - 2*[-8000;8000] + [0;8000] - [0;8000] */
        cocllasl_f03_value_3 = ((( cocllasl_f03_value_1
                                   - (cocllasl_f03_value_2*2))
                                   + (SInt32)tqsys_ntardynidl_prev[1])
                                   - (SInt32)ext_neng2_par);

        /* calculate input 2 of mult block: cocllasl_f03_value_2 */
        /* BIN2 = BIN2 - BIN2 */
        /* [-15500;16000] = [-7500;8000] - [-8000;8000] */
        cocllasl_f03_value_2 = (cocllasl_f03_value_1 - cocllasl_f03_value_2);


        /* [-7500;8000]BIN15 = ([0;1]BIN14 * [-7500;8000]BIN2) / BIN1 */
        cocllasl_f03_add_1 = ((SInt32)tqsys_facantistall1_par * cocllasl_f03_value_1) / BIN1;

        /* [-15500;16000]BIN15 = ([0;1]BIN14 * [-15500;16000]BIN2) / BIN1 */
        cocllasl_f03_add_2 = ((SInt32)tqsys_facantistall2_par * cocllasl_f03_value_2) / BIN1;

        /* [-31500;32000]BIN15 = ([0;1]BIN14 * [-31500;32000]BIN2) / BIN1 */
        cocllasl_f03_add_3 = ((SInt32)tqsys_facantistall3_par * cocllasl_f03_value_3) / BIN1;


                                                                 /* [-60500;62000]BIN15 = */
        cocllasl_f03_add =  (((cocllasl_f03_add_1 +              /* [-7500;8000]BIN15   + */
                            cocllasl_f03_add_2) +                /* [-15500;16000]BIN15 + */
                            cocllasl_f03_add_3) -                /* [-31500;32000]BIN15 - */
                            cocllasl_f03_switch_out[1]) +        /* [-2000;2000]BIN15   + */
                            (2 * cocllasl_f03_switch_out[0]);    /* 2 * [-2000;2000]BIN15 */

        /* calculate input of switch block: cocllasl_f03_value_5 */
        /* BIN15 */
        cocllasl_f03_value_5 = DDS_M_SATURATION_V2(cocllasl_f03_add,
                                                    ((SInt32)tqsys_tqckidlmin_par * BIN11),
                                                    ((SInt32)tqsys_tqckidlmax_par * BIN11));

        cocllasl_f03_switch_out[1] = cocllasl_f03_switch_out[0];
        cocllasl_f03_switch_out[0] = cocllasl_f03_value_5;
    }
    else
    {
        cocllasl_f03_switch_out[1] = cocllasl_f03_switch_out[0];
        cocllasl_f03_switch_out[0] = (SInt32)tqsys_tqckidl_par * BIN11;
    }

    /* BIN9 = BIN15 / BIN6 */
    cocllasl_f03_value_5 = DDS_M_SATURATION_V2( cocllasl_f03_switch_out[0],
                                                ((SInt32)TqSys_tqAntiStallMin_C * BIN11),
                                                ((SInt32)TqSys_tqAntiStallMax_C * BIN11)) / BIN6;

    /* [-4000;4000]BIN4 = ([-2000;2000]BIN9] * [0;2]BIN10) / BIN15 */
    cocllasl_f03_value_4 = (cocllasl_f03_value_5 * (SInt32)tqsys_factqckantistall_par) / BIN15;

    *tqsys_tqckantistall_ptr = (SInt16)DDS_M_LIMIT(cocllasl_f03_value_4,-2000*BIN4,2000*BIN4);

    tqsys_ntardynidl_prev[1] = tqsys_ntardynidl_prev[0];
    tqsys_ntardynidl_prev[0] = tqsys_ntardynidl_par;
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Bvm_Anti_Stall_Reg_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Bvm_Anti_Stall_Reg_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAntiStall_swc_out /* BIN4 */)
{
    *TqSys_tqCkAntiStall_swc_out = 0;

    DDS_M_HYST_S32_INIT(&cocllasl_f02_bvm_hyst,DDS_FALSE);

    tqsys_ntardynidl_prev[0] = 0;
    tqsys_ntardynidl_prev[1] = 0;
    cocllasl_f03_switch_out[0] = 0;
    cocllasl_f03_switch_out[1] = 0;

    TqSys_bAcvRegAntiStall = 0;

    tqsys_tqckantistall_prev = *TqSys_tqCkAntiStall_swc_out;
}

#define COCLLASL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoClLASl_MemMap.h"

