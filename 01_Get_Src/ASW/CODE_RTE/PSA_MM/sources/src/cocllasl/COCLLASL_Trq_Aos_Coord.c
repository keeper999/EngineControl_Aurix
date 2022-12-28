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
* Ref X:\integration_view_00PSASWC_EA01D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Trq_Aos_Coord.c
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 43 m User:meme 
*    TWK_model:COCLLASL_Trq_Aos_Coord_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 1/10/2010 12 h 32 m User:morisseau 
*    TWK_model:COCLLASL_Trq_Aos_Coord_L02_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 58 m User:esnault 
*    TWK_model:COCLLASL_Trq_Aos_Coord_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 31/8/2010 17 h 44 m User:morisseau 
*    TWK_model:COCLLASL_Trq_Aos_Coord_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 29/7/2010 17 h 35 m User:morisseau
*    TWK_model:COCLLASL_Trq_Aos_Coord_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 22/7/2010 11 h 56 m User:morisseau
*    TWK_model:COCLLASL_Trq_Aos_Coord_L01_010_IMPL1
*    comments :for CoClASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 40 m User:morisseau
*    TWK_model:COCLLASL_Trq_Aos_Coord_L01_010_IMPL1
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

/* 8-bits scalar calibration definition */
#define COCLLASL_START_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bMaxTqLim_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqAOSCVC_C = DDS_FALSE;
#define COCLLASL_STOP_SEC_CALIB_8BIT
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

/* 16-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkAOSCordUnLim; /* BIN4 */
#define COCLLASL_STOP_SEC_INTERNAL_VAR_16BIT
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
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_Coord_Curatif(
                                           SInt16 tqsys_tqaoscvc_par, /* BIN4 */
                                           SInt16 tqsys_tqckaoscor_par, /* BIN4 */
                                           SInt16 tqsys_tqckenglimcord_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Limitation_Couple_Global(
                                           SInt16 englim_tqckcurdrivfil_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckaoscord_ptr /* BIN4 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Trq_Aos_Coord
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Trq_Aos_Coord(SInt16 EngLim_tqCkCurDrivFil_swc_in, /* BIN4 */
                                             SInt16 TqSys_tqAOSCVC_swc_in, /* BIN4 */
                                             SInt16 TqSys_tqCkAOSCor_swc_in, /* BIN4 */
                                             SInt16 TqSys_tqCkEngLimCord_swc_in, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCord_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2711.FR.1.0 */
    COCLLASL_F01_Coord_Curatif(TqSys_tqAOSCVC_swc_in, /* BIN4 */
                               TqSys_tqCkAOSCor_swc_in, /* BIN4 */
                               TqSys_tqCkEngLimCord_swc_in /* BIN4 */);

    COCLLASL_F02_Limitation_Couple_Global(EngLim_tqCkCurDrivFil_swc_in, /* BIN4 */
                                          TqSys_tqCkAOSCord_swc_out /* BIN4 */);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F01_Coord_Curatif
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_Coord_Curatif(
                                           SInt16 tqsys_tqaoscvc_par, /* BIN4 */
                                           SInt16 tqsys_tqckaoscor_par, /* BIN4 */
                                           SInt16 tqsys_tqckenglimcord_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2711.FR.2.2 */

    if((UInt32)TqSys_bTqAOSCVC_C != (UInt32)DDS_FALSE)
    {
        TqSys_tqCkAOSCordUnLim = (SInt16)DDS_M_LIMIT((SInt32)tqsys_tqckenglimcord_par + (SInt32)tqsys_tqaoscvc_par,
                                                     -2000 * BIN4,
                                                     2000 * BIN4);
    }
    else
    {
        TqSys_tqCkAOSCordUnLim = (SInt16)DDS_M_LIMIT((SInt32)tqsys_tqckenglimcord_par + (SInt32)tqsys_tqckaoscor_par,
                                                     -2000 * BIN4,
                                                     2000 * BIN4);
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_Limitation_Couple_Global
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Limitation_Couple_Global(
                                           SInt16 englim_tqckcurdrivfil_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckaoscord_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2711.FR.3.2 */
    if((UInt32)TqSys_bMaxTqLim_C != (UInt32)DDS_FALSE)
    {
        *tqsys_tqckaoscord_ptr = (SInt16)DDS_M_LIMIT_V2((SInt32)englim_tqckcurdrivfil_par,
        												(SInt32)0,
        												(SInt32)TqSys_tqCkAOSCordUnLim);
    }
    else
    {
        *tqsys_tqckaoscord_ptr = (SInt16)DDS_M_MAX((SInt32)TqSys_tqCkAOSCordUnLim,0);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Trq_Aos_Coord_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Trq_Aos_Coord_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkAOSCord_swc_out /* BIN4 */)
{
    *TqSys_tqCkAOSCord_swc_out = 0;

    TqSys_tqCkAOSCordUnLim = 0;
}



#define COCLLASL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoClLASl_MemMap.h"
