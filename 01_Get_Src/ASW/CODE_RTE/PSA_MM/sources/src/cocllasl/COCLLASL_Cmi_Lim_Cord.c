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
* Ref X:\integration_view_00PSASWC_EA01D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Cmi_Lim_Cord.c
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 42 m User:meme 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 1/10/2010 12 h 30 m User:morisseau 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L02_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 56 m User:esnault 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 31/8/2010 17 h 43 m User:morisseau 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 29/7/2010 17 h 34 m User:morisseau 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 11 h 23 m User:morisseau
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 40 m User:morisseau
*    TWK_model:COCLLASL_Cmi_Lim_Cord_L01_010_IMPL1
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
STATIC volatile CONST(UInt16, AUTOMATIC) EngLim_tqDeltaLimMaxAir_C = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"


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

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Cmi_Lim_Cord
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord(SInt16 EngLim_tqIdcAirResMax_swc_in, /* BIN4 */
                                            SInt16 EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                            SInt16 EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                            SInt16 EngLim_tqIdcAdvOptmTrbMax_swc_in, /* BIN4 */
                                            SInt16 TqDem_tqIdcLimNReg_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqIdcAirLimCordWiRes_swc_in, /* BIN4 */
                                            UInt16 ThMgt_tqIdcLimReq_swc_in, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLimAfterRes_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLim_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) ESLim_bAcvEngSpdLim_swc_out )
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2716.FR.2.0 */
    SInt32 cocllasl_value;

    if((SInt32)TqDem_tqIdcLimNReg_swc_in <= (SInt32)TqSys_tqIdcAirLimCordWiRes_swc_in)
    {
        *ESLim_bAcvEngSpdLim_swc_out = DDS_TRUE;
    }
    else
    {
        *ESLim_bAcvEngSpdLim_swc_out = DDS_FALSE;
    }

    cocllasl_value = DDS_M_MIN((SInt32)EngLim_tqIdcAirResMax_swc_in,(SInt32)TqDem_tqIdcLimNReg_swc_in);
    *EngLim_tqIdcAirLimAfterRes_swc_out = (SInt16)DDS_M_MIN(cocllasl_value,
                                                            ((SInt32)EngLim_tqIdcAdvOptmTrbMax_swc_in+(SInt32)EngLim_tqDeltaLimMaxAir_C));

    cocllasl_value = DDS_M_MIN((SInt32)EngLim_tqIdcSyst_swc_in,(SInt32)EngLim_tqIdcEngProt_swc_in);
    *EngLim_tqIdcAirLim_swc_out = (SInt16)DDS_M_MIN(cocllasl_value,(SInt32)ThMgt_tqIdcLimReq_swc_in);
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
* Function Name : COCLLASL_Cmi_Lim_Cord_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLimAfterRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcAirLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) ESLim_bAcvEngSpdLim_swc_out )
{
    *EngLim_tqIdcAirLimAfterRes_swc_out = (SInt16)(2000 * BIN4);
    *EngLim_tqIdcAirLim_swc_out = (SInt16)(2000 * BIN4);
    *ESLim_bAcvEngSpdLim_swc_out = DDS_FALSE;
}



#define COCLLASL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoClLASl_MemMap.h"
