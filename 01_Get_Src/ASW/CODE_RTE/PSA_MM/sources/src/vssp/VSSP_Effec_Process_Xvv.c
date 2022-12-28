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
* Ref X:\integration_view_00PSASWC_D810D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Effec_Process_Xvv.c
* Version int :/main/L02_01/1 Date: 7/9/2011 16 h 41 m User:esnault 
*    TWK_model:VSSP_Effec_Process_Xvv_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\3 Date: 1/8/2011 17 h 23 m User:demezil 
*    TWK_model:VSSP_Effec_Process_Xvv_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\2 Date: 26/7/2011 10 h 14 m User:demezil
*    TWK_model:VSSP_Effec_Process_Xvv_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 21/7/2011 16 h 17 m User:demezil
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1_D
*    comments :for VSSp 11.0
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 53 m User:meme
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\6 Date: 22/2/2011 17 h 51 m User:morisseau
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 22/2/2011 16 h 56 m User:morisseau
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 18/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1
*    comments :correct task name
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 19 m User:morisseau
*    TWK_model:VSSP_Effec_Process_Xvv_L01_010_IMPL1
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

#define VSCTL_STTQPT_INACTIF    (0)


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

/* NONE */


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
/*******************************************************************************
*
* Function Name : VSSP_Effec_Process_Xvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Effec_Process_Xvv(UInt8 VSCtl_bCtlEfc_tqWhlPT_pt1_swc_in,
                                                    UInt8 VSCtl_bCtlEfc_tqWhlPT_pt2_swc_in,
                                                    UInt8 VSCtl_stTqPTMaxCtl_pt1_swc_in,
                                                    UInt8 VSCtl_stTqPTMaxCtl_pt2_swc_in,
                                                    UInt8 VSCtl_stTqPTMinCtl_pt1_swc_in,
                                                    UInt8 VSCtl_stTqPTMinCtl_pt2_swc_in,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPt_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMaxCtl_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMinCtl_swc_out)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.130.0 */

/* <PRQA_COMMENT><3325> statement value change with VSCtl_bCtlCmdPTTqCf_SC </3325></PRQA_COMMENT> */
    if((UInt32)VSCtl_bCtlCmdPTTqCf_SC == (UInt32)DDS_TRUE)
/* <PRQA_COMMENT><3201> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </3201></PRQA_COMMENT> */
    {
        *VSCtl_bCtlEfc_tqWhlPt_swc_out = VSCtl_bCtlEfc_tqWhlPT_pt1_swc_in;
        *VSCtl_stTqPTMinCtl_swc_out = VSCtl_stTqPTMinCtl_pt1_swc_in;
        *VSCtl_stTqPTMaxCtl_swc_out = VSCtl_stTqPTMaxCtl_pt1_swc_in;
    }
    else
    {
        *VSCtl_bCtlEfc_tqWhlPt_swc_out = VSCtl_bCtlEfc_tqWhlPT_pt2_swc_in;
        *VSCtl_stTqPTMinCtl_swc_out = VSCtl_stTqPTMinCtl_pt2_swc_in;
        *VSCtl_stTqPTMaxCtl_swc_out = VSCtl_stTqPTMaxCtl_pt2_swc_in;
    }
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
/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Effec_Process_Xvv_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Effec_Process_Xvv_Init(
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPt_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMaxCtl_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stTqPTMinCtl_swc_out)
{
    /* ---- Init Outputs ---- */
    *VSCtl_bCtlEfc_tqWhlPt_swc_out = DDS_FALSE;
    *VSCtl_stTqPTMinCtl_swc_out = VSCTL_STTQPT_INACTIF;
    *VSCtl_stTqPTMaxCtl_swc_out = VSCTL_STTQPT_INACTIF;

    /* ---- Init Global Datas ---- */
}

#define VSSP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSSp_MemMap.h"

