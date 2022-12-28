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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Elabor_Info_Brake_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 6 m User:meme 
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 4 m User:demezil 
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 15 m User:meme
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 8/2/2011 9 h 9 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/2/2011 18 h 16 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :for vSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 2/2/2011 17 h 34 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 7/1/2011 9 h 13 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :correct IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 14 h 27 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :correct function name
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 20/12/2010 18 h 18 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Brake_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 6 m User:morisseau
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

#define VSINFO_0                              (0)

  /* VSCtl_stBrkInfo */
#define VSCTL_STBRKINFO_ARRET           (UInt32)0
#define VSCTL_STBRKINFO_VERIF_11        (UInt32)1
#define VSCTL_STBRKINFO_INIT_11         (UInt32)2
#define VSCTL_STBRKINFO_NOMINAL_11      (UInt32)3
#define VSCTL_STBRKINFO_DEFAUT_11       (UInt32)4


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stBrkInfo;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



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
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlBrk_SatMax_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlBrk_SatMin_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


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
* Function Name : VSINFO_F122_Determiner_Couples_Roue_Frein
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F122_Determiner_Couples_Roue_Frein(SInt16 Brk_tqWhlBrkEstim_swc_in, /* BIN1 */
                           SInt16 Brk_tqWhlBrkReq_swc_in, /* BIN1 */
                           UInt8 Ext_bTqWhlBrkCf_swc_in,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkEstim_swc_out,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkReq_swc_out)
{
    if((UInt32)VSCtl_stBrkInfo == VSCTL_STBRKINFO_NOMINAL_11)
    {
        if((UInt32)Ext_bTqWhlBrkCf_swc_in == (UInt32)DDS_TRUE)
        {
            *VSCtl_tqWhlBrkEstim_swc_out = (SInt16)DDS_M_SATURATION_V2((SInt32)Brk_tqWhlBrkEstim_swc_in,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMin_C,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMax_C);
            *VSCtl_tqWhlBrkReq_swc_out = (SInt16)DDS_M_SATURATION_V2((SInt32)Brk_tqWhlBrkReq_swc_in,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMin_C,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMax_C);
        }
        else
        {
            *VSCtl_tqWhlBrkEstim_swc_out = (SInt16)DDS_M_SATURATION_V2(VSINFO_0,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMin_C,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMax_C);
            *VSCtl_tqWhlBrkReq_swc_out = (SInt16)DDS_M_SATURATION_V2(VSINFO_0,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMin_C,
                                                              (SInt32)VSCtl_tqWhlBrk_SatMax_C);
        }
    }
    else
    {
        *VSCtl_tqWhlBrkEstim_swc_out = VSINFO_0;
        *VSCtl_tqWhlBrkReq_swc_out = VSINFO_0;
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
* Function Name : VSINFO_Elabor_Info_Brake_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Brake_Sl_Init(
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkEstim_swc_out,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlBrkReq_swc_out)
{
    /* ---- Init Outputs ---- */
    *VSCtl_tqWhlBrkEstim_swc_out = (SInt16)(0 * BIN1);
    *VSCtl_tqWhlBrkReq_swc_out = (SInt16)(0 * BIN1);

    /* ---- Init Global Datas ---- */

}


#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

