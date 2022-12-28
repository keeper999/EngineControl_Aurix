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
* Ref X:\integration_view_00PSASWC_EC00D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Cord_Lim_Torq_Struct.c
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 56 m User:esnault 
*    TWK_model:COTQ_Cord_Lim_Torq_Struct_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 47 m User:lemort 
*    TWK_model:COTQ_Cord_Lim_Torq_Struct_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 18/10/2010 14 h 49 m User:lemort
*    TWK_model:COTQ_Cord_Lim_Torq_Struct_L01_010_IMPL1
*    comments :dev CoTq 10.0
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

/* NONE */


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COTQ_START_SEC_VAR_16BIT
#include "CoTq_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) copt_tqefcaircordlimit_tqgbx_prev;
#define COTQ_STOP_SEC_VAR_16BIT
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
* Function Name : COTQ_Cord_Lim_Torq_Struct
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Cord_Lim_Torq_Struct(SInt16 CoPt_tqAirCord_tqGBx_swc_in, /* BIN4 */
                                                SInt16 CoPt_tqCord_tqGBx_swc_in, /* BIN4 */
                                                SInt16 EngLim_tqCkEfcAirGBxLimCord_swc_in, /* BIN4 */
                                                SInt16 EngLim_tqCkEfcGBxLimCord_swc_in, /* BIN4 */
                                                UInt8 TqSys_bTypFu_swc_in,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLimIt_tqGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLimIt_tqGBx_swc_out /* BIN4 */)
{


	/* SSTG_REQ_TAG : CSMT_CGMT06_2167.FR.1.1 */

	/* SSTG_REQ_TAG : CSMT_CGMT06_2167.FR.2.1 */
	if((UInt32)DDS_FALSE != (UInt32)TqSys_bTypFu_swc_in)
	{
		*CoPt_tqEfcAirCordLimIt_tqGBx_swc_out = (SInt16)DDS_M_MIN((SInt32)EngLim_tqCkEfcAirGBxLimCord_swc_in,
																	(SInt32)CoPt_tqAirCord_tqGBx_swc_in);
		copt_tqefcaircordlimit_tqgbx_prev = *CoPt_tqEfcAirCordLimIt_tqGBx_swc_out;
	}
	else
	{
		*CoPt_tqEfcAirCordLimIt_tqGBx_swc_out = copt_tqefcaircordlimit_tqgbx_prev;
	}


	/* SSTG_REQ_TAG : CSMT_CGMT06_2167.FR.3.1 */
	*CoPt_tqEfcCordLimIt_tqGBx_swc_out = (SInt16)DDS_M_MIN((SInt32)EngLim_tqCkEfcGBxLimCord_swc_in,
																(SInt32)CoPt_tqCord_tqGBx_swc_in);

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
* Function Name : COTQ_Cord_Lim_Torq_Struct_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Cord_Lim_Torq_Struct_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLimIt_tqGBx_swc_out, /* BIN4 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLimIt_tqGBx_swc_out /* BIN4 */)
{
    /* ---- Init Outputs ---- */
    *CoPt_tqEfcAirCordLimIt_tqGBx_swc_out = 0;
	*CoPt_tqEfcCordLimIt_tqGBx_swc_out = 0;

    /* ---- Init Global Datas ---- */
    copt_tqefcaircordlimit_tqgbx_prev = 0;

}



#define COTQ_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoTq_MemMap.h"