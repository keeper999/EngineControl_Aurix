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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Elabor_Info_Gmp_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 6 m User:meme 
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\3 Date: 1/8/2011 14 h 44 m User:demezil 
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 13/7/2011 14 h 24 m User:demezil
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 6 m User:demezil
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 24 m User:meme
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 18/2/2011 13 h 58 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 15 m User:meme
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 14/2/2011 9 h 54 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 2/2/2011 17 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 6/1/2011 14 h 25 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :correc IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 14 h 24 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :correct function name
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 9 h 13 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 8 m User:morisseau
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

#define VSINFO_4000_BIN1        (4000 * BIN1)
#define VSINFO_11000_BIN1       (11000 * BIN1)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMax_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMin_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMn_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMx_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlRq_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMnReqRaw_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTAplReq_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTReal_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTIni_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLim_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlThPTMin_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMin_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMax_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMn_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMx_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlRq_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTAplReq_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTReal_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTIni_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMin_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMax_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla1_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla1_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlThPTPotMin_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMin_pt2; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMax_pt2; /* BIN1 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTRe_pt1; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTRe_pt2; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_pt1; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_pt2; /* BIN7 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bCtlaTqPT_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bCtlaTqPT_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt1_no1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt1_no2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt1_no3;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt2_no1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt2_no2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt2_no3;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
extern volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


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

/*******************************************************************************
*
* Function Name : VSINFO_F113_Elaborer_Informations_GMP
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Gmp_Sl(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no1_swc_out,
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no2_swc_out,
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no3_swc_out,
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlaTqPT_swc_out,
                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_swc_out, /* BIN7 */
                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTRe_swc_out, /* BIN7 */
                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stPTInfo_swc_out,
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTAplReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReqRaw_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTIni_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTLim_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMax_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMax_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtla_no1_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMinReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCtlReq_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTReal_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTMin_swc_out, /* BIN1 */
                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTPotMin_swc_out /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.179.0 */

/* <PRQA_COMMENT><3325> statement value change with VSCtl_bCtlCmdPTTqCf_SC </3325></PRQA_COMMENT> */
    if((UInt32)VSCtl_bCtlCmdPTTqCf_SC != (UInt32)DDS_FALSE)
/* <PRQA_COMMENT><3201> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </3201></PRQA_COMMENT> */
    {
        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.73.1 */
        *VSCtl_stPTInfo_swc_out = VSCtl_stPTInfo_pt1;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.84.1 */
        *VSCtl_bAvlTqWhlPT_no1_swc_out = VSCtl_bAvlTqWhlPt1_no1;
        *VSCtl_bAvlTqWhlPT_no2_swc_out = VSCtl_bAvlTqWhlPt1_no2;
        *VSCtl_bAvlTqWhlPT_no3_swc_out = VSCtl_bAvlTqWhlPt1_no3;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.180.0 */
        *VSCtl_tqWhlPTMin_swc_out = VSCtl_tqWhlPTMin_pt1;
        *VSCtl_tqWhlPTMax_swc_out = VSCtl_tqWhlPTMax_pt1;
        *VSCtl_tqWhlPTMinNotCtla_swc_out = VSCtl_tqWhlPTMinNotCtla_pt1;
        *VSCtl_tqWhlPTMaxNotCtla_swc_out = VSCtl_tqWhlPTMaxNotCtla_pt1;
        *VSCtl_tqWhlPTPreCoVSCMinReq_swc_out = VSCtl_tqWhlPTPreCVSCtlMn_pt1;
        *VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out = VSCtl_tqWhlPTPreCVSCtlMx_pt1;
        *VSCtl_tqWhlPTPreCoVSCtlReq_swc_out = VSCtl_tqWhlPTPreCVSCtlRq_pt1;
        *VSCtl_tqWhlPTDrvMinReq_swc_out = VSCtl_tqWhlPTDrvMinReq_pt1;
        *VSCtl_tqWhlPTDrvMaxReq_swc_out = VSCtl_tqWhlPTDrvMaxReq_pt1;
        *VSCtl_tqWhlPTDrvMinReqRaw_swc_out = VSCtl_tqWhlPTDrvMnReqRaw_pt1;
        *VSCtl_tqWhlPTAplReq_swc_out = (SInt16)DDS_M_LIMIT((SInt32)VSCtl_tqWhlPTAplReq_pt1,-VSINFO_4000_BIN1,VSINFO_11000_BIN1);
        *VSCtl_tqWhlPTReal_swc_out = (SInt16)DDS_M_LIMIT((SInt32)VSCtl_tqWhlPTReal_pt1,-VSINFO_4000_BIN1,VSINFO_11000_BIN1);
        *VSCtl_tqWhlPTIni_swc_out = VSCtl_tqWhlPTIni_pt1;
        *VSCtl_tqWhlPTLim_swc_out = VSCtl_tqWhlPTLim_pt1;
        *VSCtl_tqWhlThPTMin_swc_out = VSCtl_tqWhlThPTMin_pt1;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.80.1 */
        *VSCtl_tqWhlPTPotMaxCtla_no1_swc_out = VSCtl_tqWhlPTPotMxCtla1_pt1;
        *VSCtl_tqWhlPTPotMax_swc_out = VSCtl_tqWhlPTPotMax_pt1;
        *VSCtl_tqWhlPTPotMin_swc_out = VSCtl_tqWhlPTPotMin_pt1;
        *VSCtl_tqWhlThPTPotMin_swc_out = VSCtl_tqWhlThPTPotMin_pt1;
        *VSCtl_tqWhlPTPotRawMax_swc_out = VSCtl_tqWhlPTPotRawMax_pt1;
        *VSCtl_tqWhlPTPotRawMin_swc_out = VSCtl_tqWhlPTPotRawMin_pt1;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.156.0 */
        *VSCtl_bCtlaTqPT_swc_out = VSCtl_bCtlaTqPT_pt1;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.157.0 */
        *VSCtl_rTqWhlPTDrvReq_swc_out = VSCtl_rTqWhlPTDrvReq_pt1;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.81.1 */
        *VSCtl_rTqWhlPTRe_swc_out = VSCtl_rTqWhlPTRe_pt1;
    }
    else
    {
        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.73.1 */
        *VSCtl_stPTInfo_swc_out = VSCtl_stPTInfo_pt2;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.84.1 */
        *VSCtl_bAvlTqWhlPT_no1_swc_out = VSCtl_bAvlTqWhlPt2_no1;
        *VSCtl_bAvlTqWhlPT_no2_swc_out = VSCtl_bAvlTqWhlPt2_no2;
        *VSCtl_bAvlTqWhlPT_no3_swc_out = VSCtl_bAvlTqWhlPt2_no3;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.180.0 */
        *VSCtl_tqWhlPTMin_swc_out = VSCtl_tqWhlPTMin_pt2;
        *VSCtl_tqWhlPTMax_swc_out = VSCtl_tqWhlPTMax_pt2;
        *VSCtl_tqWhlPTMinNotCtla_swc_out = VSCtl_tqWhlPTMinNotCtla_pt2;
        *VSCtl_tqWhlPTMaxNotCtla_swc_out = VSCtl_tqWhlPTMaxNotCtla_pt2;
        *VSCtl_tqWhlPTPreCoVSCMinReq_swc_out = VSCtl_tqWhlPTPreCVSCtlMn_pt2;
        *VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out = VSCtl_tqWhlPTPreCVSCtlMx_pt2;
        *VSCtl_tqWhlPTPreCoVSCtlReq_swc_out = VSCtl_tqWhlPTPreCVSCtlRq_pt2;
        *VSCtl_tqWhlPTDrvMinReq_swc_out = VSCtl_tqWhlPTDrvMinReq_pt2;
        *VSCtl_tqWhlPTDrvMaxReq_swc_out = VSCtl_tqWhlPTDrvMaxReq_pt2;
        *VSCtl_tqWhlPTDrvMinReqRaw_swc_out = (SInt16)(-16000 * BIN1);
        *VSCtl_tqWhlPTAplReq_swc_out = (SInt16)DDS_M_LIMIT((SInt32)VSCtl_tqWhlPTAplReq_pt2,-VSINFO_4000_BIN1,VSINFO_11000_BIN1);
        *VSCtl_tqWhlPTReal_swc_out = (SInt16)DDS_M_LIMIT((SInt32)VSCtl_tqWhlPTReal_pt2,-VSINFO_4000_BIN1,VSINFO_11000_BIN1);
        *VSCtl_tqWhlPTIni_swc_out = VSCtl_tqWhlPTIni_pt2;
        *VSCtl_tqWhlPTLim_swc_out = (SInt16)(-16000 * BIN1);
        *VSCtl_tqWhlThPTMin_swc_out = (SInt16)(-16000 * BIN1);

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.80.1 */
        *VSCtl_tqWhlPTPotMaxCtla_no1_swc_out = VSCtl_tqWhlPTPotMxCtla1_pt2;
        *VSCtl_tqWhlPTPotMax_swc_out = VSCtl_tqWhlPTPotMax_pt2;
        *VSCtl_tqWhlPTPotMin_swc_out = VSCtl_tqWhlPTPotMin_pt2;
        *VSCtl_tqWhlThPTPotMin_swc_out = (SInt16)(-16000 * BIN1);
        *VSCtl_tqWhlPTPotRawMax_swc_out = VSCtl_tqWhlPTPotRawMax_pt2;
        *VSCtl_tqWhlPTPotRawMin_swc_out = VSCtl_tqWhlPTPotRawMin_pt2;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.156.0 */
        *VSCtl_bCtlaTqPT_swc_out = VSCtl_bCtlaTqPT_pt2;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.157.0 */
        *VSCtl_rTqWhlPTDrvReq_swc_out = VSCtl_rTqWhlPTDrvReq_pt2;

        /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.81.1 */
        *VSCtl_rTqWhlPTRe_swc_out = VSCtl_rTqWhlPTRe_pt2;
    }
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Elabor_Info_Gmp_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Gmp_Sl_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no1_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no2_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAvlTqWhlPT_no3_swc_out,
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bCtlaTqPT_swc_out,
                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_swc_out, /* BIN7 */
                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rTqWhlPTRe_swc_out, /* BIN7 */
                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stPTInfo_swc_out,
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTAplReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTDrvMinReqRaw_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTIni_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTLim_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMax_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMax_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtla_no1_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCMinReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCtlReq_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTReal_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTMin_swc_out, /* BIN1 */
                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlThPTPotMin_swc_out /* BIN1 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_bAvlTqWhlPT_no1_swc_out = DDS_FALSE;
    *VSCtl_bAvlTqWhlPT_no2_swc_out = DDS_FALSE;
    *VSCtl_bAvlTqWhlPT_no3_swc_out = DDS_FALSE;
    *VSCtl_bCtlaTqPT_swc_out = DDS_FALSE;
    *VSCtl_rTqWhlPTDrvReq_swc_out = (UInt16)(0 *  BIN7);
    *VSCtl_rTqWhlPTRe_swc_out = (UInt16)(0 *  BIN7);
    *VSCtl_stPTInfo_swc_out = 0;
    *VSCtl_tqWhlPTAplReq_swc_out = (SInt16)(0 *  BIN1);
    *VSCtl_tqWhlPTDrvMaxReq_swc_out = (SInt16)(16000 *  BIN1);
    *VSCtl_tqWhlPTDrvMinReqRaw_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTDrvMinReq_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTIni_swc_out = (SInt16)(0 *  BIN1);
    *VSCtl_tqWhlPTLim_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTMax_swc_out = (SInt16)(16000 *  BIN1);
    *VSCtl_tqWhlPTMaxNotCtla_swc_out = (SInt16)(0 *  BIN1);
    *VSCtl_tqWhlPTMinNotCtla_swc_out = (SInt16)(0 *  BIN1);
    *VSCtl_tqWhlPTMin_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTPotMax_swc_out = (SInt16)(16000 *  BIN1);
    *VSCtl_tqWhlPTPotMaxCtla_no1_swc_out = (SInt16)(16000 *  BIN1);
    *VSCtl_tqWhlPTPotMin_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTPotRawMax_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTPotRawMin_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTPreCoVSCMaxReq_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTPreCoVSCMinReq_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlPTPreCoVSCtlReq_swc_out = VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
    *VSCtl_tqWhlPTReal_swc_out = (SInt16)(0 *  BIN1);
    *VSCtl_tqWhlThPTMin_swc_out = (SInt16)(-16000 *  BIN1);
    *VSCtl_tqWhlThPTPotMin_swc_out = (SInt16)(-16000 *  BIN1);

    /* ---- Init Global Datas ---- */
}

#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

