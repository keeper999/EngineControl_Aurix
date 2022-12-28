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
* Ref X:\integration_view_00PSASWC_E501D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Coord_Global_Loss.c
* Version int :/main/L02_01/2 Date: 12/10/2010 9 h 45 m User:meme 
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1_D
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/9/2010 8 h 46 m User:morisseau 
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1_D
*    comments :for TqAdpCmp euro 6
* Version int :/main/L02_01/1 Date: 13/9/2010 14 h 19 m User:esnault
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 2/9/2010 11 h 34 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 22/7/2010 16 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 9/7/2010 16 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 29/6/2010 11 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Coord_Global_Loss_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_02/1 Date: 9/9/2009 13 h 29 m User:langendorf
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_020_IMPL1
*    comments :work in progress, adaptation for STIL 2.0
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 24/8/2009 13 h 11 m User:lemort
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_020_IMPL1
*    comments :work in progress, adaptation for STIL 2.0
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 5 m User:boucher
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_010_IMPL3
*    comments :Line length exceeds 150 characters.
* Version dev :\main\branch_moisan_tqadpcmp_validation\3 Date: 6/10/2008 13 h 49 m User:moisan
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_010_IMPL3
*    comments :Line length exceeds 150 characters.
* Version dev :\main\branch_moisan_tqadpcmp_validation\2 Date: 6/10/2008 13 h 45 m User:moisan
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_010_IMPL3
*    comments :Modication in tracking sheet file:
*    comments :TqSys_tqCkEngLossAdp
*    comments :TqCmp_tqAuxSumLossEst
*    comments :TqCmp_tqAuxSumLossCmp
*    comments :TqCmp_tqSumLossEst
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 24/9/2008 14 h 42 m User:moisan
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_010_IMPL2
*    comments :Wrong interface: TqCmp_bTypFu must be renamed
* Version int :/main/L01_01/1 Date: 23/9/2008 10 h 28 m User:boucher
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_010_IMPL1
*    comments :Implement "CSMT_CGMT06_1934 v2.0" (R6515132 1.0)
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\2 Date: 29/8/2008 9 h 0 m User:girodon
*    TWK_model:TQADPCMP_Coord_Global_Loss_L01_010_IMPL1
*    comments :Implement "CSMT_CGMT06_1934 v2.0" (R6515132 1.0)
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

#define COPTST_STENG_COUPLE_CALE    1
#define COPTST_STENG_ARRET          6


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
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossCmpMax_C = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossCmpMin_C = (CONST(SInt16, AUTOMATIC))(-2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossEstimMax_C = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossEstimMin_C = (CONST(SInt16, AUTOMATIC))(-2000 * BIN4);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumLossCmpAdp_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bSumLossCmpCnv_C = DDS_FALSE;
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
* Function Name : TQADPCMP_Coord_Global_Loss
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Coord_Global_Loss(UInt8 CoPTSt_stEng_swc_in,
                                           SInt16 TqCmp_tqAuxSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAuxSumLossEstim_swc_in, /* BIN4 */
                                           UInt16 TqCmp_tqCnvLoss_swc_in, /* BIN4 */
                                           UInt16 TqSys_tqCkEngLoss_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkEngLossAdp_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmpWoutCnv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossEstim_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1934.FR.1.0 */
    SInt32 tqadpcmp_svalue;

    if(  ((UInt32)CoPTSt_stEng_swc_in == COPTST_STENG_COUPLE_CALE)
       ||((UInt32)CoPTSt_stEng_swc_in == COPTST_STENG_ARRET))
    {
        *TqCmp_tqSumLossCmp_swc_out = 0;
        *TqCmp_tqSumLossCmpWoutCnv_swc_out = 0;
        *TqCmp_tqSumLossEstim_swc_out = 0;
    }
    else
    {
        *TqCmp_tqSumLossEstim_swc_out = (SInt16)DDS_M_SATURATION_V2(((SInt32)TqCmp_tqCnvLoss_swc_in +
                                                                  (SInt32)TqSys_tqCkEngLoss_swc_in +
                                                                  (SInt32)TqCmp_tqAuxSumLossEstim_swc_in),
                                                                 (SInt32)TqCmp_tqSumLossEstimMin_C,
                                                                 (SInt32)TqCmp_tqSumLossEstimMax_C);

        if((UInt32)TqCmp_bSumLossCmpAdp_C != (UInt32)DDS_FALSE)
        {
            tqadpcmp_svalue = (SInt32)TqSys_tqCkEngLossAdp_swc_in + (SInt32)TqCmp_tqAuxSumLossCmp_swc_in + (SInt32)TqSys_tqCkEngLoss_swc_in;
        }
        else
        {
            tqadpcmp_svalue = (SInt32)TqCmp_tqAuxSumLossCmp_swc_in + (SInt32)TqSys_tqCkEngLoss_swc_in;
        }

        *TqCmp_tqSumLossCmpWoutCnv_swc_out = (SInt16)DDS_M_SATURATION_V2(tqadpcmp_svalue,
                                                                      (SInt32)TqCmp_tqSumLossCmpMin_C,
                                                                      (SInt32)TqCmp_tqSumLossCmpMax_C);

        if((UInt32)TqCmp_bSumLossCmpCnv_C != (UInt32)DDS_FALSE)
        {
            tqadpcmp_svalue = tqadpcmp_svalue + (SInt32)TqCmp_tqCnvLoss_swc_in;
        }
        else
        {
            /* nothing to do */
        }

        *TqCmp_tqSumLossCmp_swc_out = (SInt16)DDS_M_SATURATION_V2(tqadpcmp_svalue,
                                                               (SInt32)TqCmp_tqSumLossCmpMin_C,
                                                               (SInt32)TqCmp_tqSumLossCmpMax_C);
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
* Function Name : TQADPCMP_Coord_Global_Loss_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Coord_Global_Loss_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmp_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossCmpWoutCnv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqSumLossEstim_swc_out /* BIN4 */)
{
    *TqCmp_tqSumLossCmp_swc_out = 0;
    *TqCmp_tqSumLossCmpWoutCnv_swc_out = 0;
    *TqCmp_tqSumLossEstim_swc_out = 0;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"
