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
* Ref X:\integration_view_00PSASWC_EC11D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Func_Call.c
* Version int :/main/L02_01/2 Date: 25/10/2011 15 h 54 m User:meme 
*    TWK_model:COTQ_Func_Call_L02_011_IMPL1
*    comments :upadte for CoTq 11.1 : FDS A0203582/ALTIS 1682813. 
* Version dev :\main\branch_demezil_cotq_view\2 Date: 25/10/2011 12 h 2 m User:demezil 
*    TWK_model:COTQ_Func_Call_L02_011_IMPL1
*    comments :upadte for CoTq 11.1 : FDS A0203582/ALTIS 1682813. 
* Version int :/main/L02_01/1 Date: 5/10/2011 9 h 15 m User:esnault
*    TWK_model:COTQ_Func_Call_L02_010_IMPL1
*    comments :for CoTq 11.0: no modification in code set TqSys_bAcvTqCnv to disp into model
* Version dev :\main\branch_demezil_cotq_view\1 Date: 28/9/2011 9 h 43 m User:demezil
*    TWK_model:COTQ_Func_Call_L02_010_IMPL1
*    comments :for CoTq 11.0: no modification in code set TqSys_bAcvTqCnv to disp into model
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 56 m User:esnault
*    TWK_model:COTQ_Func_Call_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 47 m User:lemort
*    TWK_model:COTQ_Func_Call_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 43 m User:lemort
*    TWK_model:COTQ_Func_Call_L01_010_IMPL1
*    comments :first dev CoTq
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "CoTq.h"

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
#define COTQ_START_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nThdStopIdcCnvEfc_C = (CONST(UInt16, AUTOMATIC))(200 * BIN0);
#define COTQ_STOP_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"

/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COTQ_START_SEC_VAR_UNSPECIFIED
#include "CoTq_MemMap.h"
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) cotq_func_call_hyst;
#define COTQ_STOP_SEC_VAR_UNSPECIFIED
#include "CoTq_MemMap.h"

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

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Func_Call
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Func_Call(UInt16 Ext_nEng_swc_in, /* BIN0 */
                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvTqCnv_swc_out )
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.4.0 */

    *TqSys_bAcvTqCnv_swc_out = DDS_M_HYST_PH_U32(&cotq_func_call_hyst,
                                                    (UInt32)Ext_nEng_swc_in,
                                                    ((UInt32)TqSys_nThdStopIdcCnvEfc_C + 50),
                                                    (UInt32)TqSys_nThdStopIdcCnvEfc_C );
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/* NONE */

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Func_Call_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Func_Call_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvTqCnv_swc_out )
{
    /* ---- Init Outputs ---- */
    *TqSys_bAcvTqCnv_swc_out = DDS_FALSE;

    /* ---- Init Global Datas ---- */

    (void)DDS_M_HYST_U32_INIT(&cotq_func_call_hyst,DDS_FALSE);

}

#define COTQ_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoTq_MemMap.h"

