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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Elabor_Repair_Req_Sl.c
* Version int :/main/L01_02/1 Date: 25/8/2011 16 h 7 m User:meme 
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_020_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 29/7/2011 14 h 12 m User:demezil 
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_020_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 15 m User:meme
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\10 Date: 8/2/2011 9 h 11 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\9 Date: 7/2/2011 18 h 16 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :for vSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 2/2/2011 17 h 37 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 21/12/2010 14 h 26 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :correct function name
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 21/12/2010 14 h 24 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :correct function name
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 21/12/2010 14 h 22 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :correct function name
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 20/12/2010 18 h 3 m User:morisseau
*    TWK_model:VSINFO_Elabor_Repair_Req_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 20/12/2010 17 h 21 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correct function name
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 13 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSInfo 10.0
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSInfo.h"


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

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/*******************************************************************************
*
* Function Name : VSINFO_F16_Determiner_Conditions_Maintenance
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F16_Determiner_Conditions_Maintenance(UInt8 FRM_bDeacVSCtlEngClc_swc_in,
                          UInt8 FRM_bDeacVSCtlGrdLkClc_swc_in,
                          UInt8 FRM_bDeacVSCtlPTClc_swc_in,
                          UInt8 FRM_bDeacVSCtlTraClc_swc_in,
                          UInt8 FRM_bDeacVSCtlVehClc_swc_in,
                          UInt8 VSCtl_stDiagSpdVeh_swc_in,
                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSCtlInfo_swc_out )
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.176.0 */
    UInt32 vsinfo_uvalue;

    vsinfo_uvalue = 0;

    if((UInt32)DDS_FALSE != (UInt32)FRM_bDeacVSCtlEngClc_swc_in)
    {
        vsinfo_uvalue = vsinfo_uvalue + 1;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)DDS_FALSE != (UInt32)FRM_bDeacVSCtlTraClc_swc_in)
    {
        vsinfo_uvalue = vsinfo_uvalue + 2;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)DDS_FALSE != (UInt32)FRM_bDeacVSCtlPTClc_swc_in)
    {
        vsinfo_uvalue = vsinfo_uvalue + 4;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)DDS_FALSE != (UInt32)FRM_bDeacVSCtlGrdLkClc_swc_in)
    {
        vsinfo_uvalue = vsinfo_uvalue + 8;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)DDS_FALSE != (UInt32)FRM_bDeacVSCtlVehClc_swc_in)
    {
        vsinfo_uvalue = vsinfo_uvalue + 16;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)2 == (UInt32)VSCtl_stDiagSpdVeh_swc_in)
    {
        vsinfo_uvalue = vsinfo_uvalue + 32;
    }
    else
    {
        /* Nothing to do */
    }

    /* vsinfo_uvalue: BIN0[0;63] */
    *VSCtl_stDeacVSCtlInfo_swc_out = (UInt8)DDS_M_MIN(vsinfo_uvalue,32);
}



/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/* None */


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Elabor_Repair_Req_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Repair_Req_Sl_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSCtlInfo_swc_out)
{
    /* ---- Init Outputs ---- */
    *VSCtl_stDeacVSCtlInfo_swc_out = (UInt8)32;

    /* ---- Init Global Datas ---- */

    /* ---- VSINFO_F16_Determiner_Conditions_Maintenance ---- */

}



#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

