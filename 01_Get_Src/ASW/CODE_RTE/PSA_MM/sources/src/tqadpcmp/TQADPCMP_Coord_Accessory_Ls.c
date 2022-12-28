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
* Ref X:\integration_view_00PSASWC_E500D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Coord_Accessory_Ls.c
* Version int :/main/L02_01/1 Date: 13/9/2010 14 h 18 m User:esnault 
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 22/7/2010 16 h 5 m User:morisseau 
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 9/7/2010 16 h 22 m User:morisseau 
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 7/7/2010 9 h 23 m User:morisseau 
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 29/6/2010 11 h 42 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_02/1 Date: 9/9/2009 13 h 29 m User:langendorf
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_020_IMPL1
*    comments :work in progress, adaptation for STIL 2.0
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 24/8/2009 13 h 10 m User:lemort
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_020_IMPL1
*    comments :work in progress, adaptation for STIL 2.0
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 5 m User:boucher
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL2
*    comments :Modification in tracking sheet: TqCmp_tqAltLoss, . TQmp_tqAuxSumLossEst, . TqCmp_tqAuxSumLossCmp.
* Version dev :\main\branch_moisan_tqadpcmp_validation\3 Date: 6/10/2008 13 h 11 m User:moisan
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL2
*    comments :Modification in tracking sheet: TqCmp_tqAltLoss,
*    comments :TQmp_tqAuxSumLossEst,
*    comments :TqCmp_tqAuxSumLossCmp.
* Version dev :\main\branch_moisan_tqadpcmp_validation\2 Date: 2/10/2008 10 h 57 m User:moisan
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL1
*    comments :Error with TqCmp_tqAuxSumLossCmp limitation
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 30/9/2008 17 h 39 m User:moisan
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL1
*    comments :error with TqCmp_tqAuxSumLossEst limitation
* Version dev :\main\branch_miaille\3 Date: 24/9/2008 15 h 43 m User:miaille
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL1
*    comments :Limit warning fix.
* Version dev :\main\branch_miaille\2 Date: 22/9/2008 11 h 2 m User:miaille
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL1
*    comments :Fix in/out parameter error.
* Version dev :\main\branch_miaille\1 Date: 19/9/2008 13 h 24 m User:miaille
*    TWK_model:TQADPCMP_Coord_Accessory_Ls_L01_010_IMPL1
*    comments :Implements specification CSMT_CGMT06_1933_v2_0.
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

/* DDS Library */
#include "dds_lib.h"


/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "TqAdpCmp.h"

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
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumACLossCmp_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumACLossEstim_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumAltLossCmp_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumAltLossEstim_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumAuxLossCmp_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumAuxLossEstim_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumStgPmpLossCmp_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumStgPmpLossEstim_C = DDS_TRUE;
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


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

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Coord_Accessory_Ls
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Coord_Accessory_Ls(UInt16 TqCmp_tqACLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                           UInt16 TqCmp_tqAuxLoss_swc_in, /* BIN4 */
                                           UInt16 TqCmp_tqStgPmpLoss_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossEstim_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1933.FR.1.0 */
    SInt32 tqadpcmp_svalue;

    tqadpcmp_svalue = 0;

    if((UInt32)TqCmp_bSumStgPmpLossCmp_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqStgPmpLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }
    if((UInt32)TqCmp_bSumACLossCmp_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqACLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }
    if((UInt32)TqCmp_bSumAltLossCmp_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqAltLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }
    if((UInt32)TqCmp_bSumAuxLossCmp_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqAuxLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }

    *TqCmp_tqAuxSumLossCmp_swc_out = (SInt16)DDS_M_MIN(tqadpcmp_svalue,2000*BIN4);

    tqadpcmp_svalue = 0;

    if((UInt32)TqCmp_bSumStgPmpLossEstim_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqStgPmpLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }
    if((UInt32)TqCmp_bSumACLossEstim_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqACLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }
    if((UInt32)TqCmp_bSumAltLossEstim_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqAltLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }
    if((UInt32)TqCmp_bSumAuxLossEstim_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqAuxLoss_swc_in;
    }
    else
    {
        /* nothing to do */
    }

    *TqCmp_tqAuxSumLossEstim_swc_out = (SInt16)DDS_M_MIN(tqadpcmp_svalue,2000*BIN4);
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
* Function Name : TQADPCMP_Coord_Accessory_Ls_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Coord_Accessory_Ls_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqAuxSumLossEstim_swc_out /* BIN4 */)
{
    *TqCmp_tqAuxSumLossCmp_swc_out = 0;
    *TqCmp_tqAuxSumLossEstim_swc_out = 0;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"
