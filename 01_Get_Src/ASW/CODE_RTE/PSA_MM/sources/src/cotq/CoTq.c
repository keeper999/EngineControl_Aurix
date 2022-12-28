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
* Ref X:\integration_view_00PSASWC_EC20D01\blois_psa_sstg\Software\Appli\CoTq\src\CoTq.c
* Version int :/main/00PSASWC_EC/BR_00PSASWC_EC20/1 Date: 21/9/2012 14 h 45 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :for CoTq 12.0
* Version dev :\main\branch_morisseau_cotq_e6_view\1 Date: 21/9/2012 8 h 43 m User:morisseau 
*    TWK_model:NO_MODEL
*    comments :for CoTq 12.0
* Version int :/main/00PSASWC_EC/3 Date: 31/1/2011 15 h 15 m User:meme
*    TWK_model:NO_MODEL
*    comments :Update module minor version for CoTq 10.2
* Version dev :\main\branch_girodon_module_dev\2 Date: 27/1/2011 16 h 35 m User:girodon
*    TWK_model:NO_MODEL
*    comments :Update module minor version for CoTq 10.2
* Version int :/main/00PSASWC_EC/2 Date: 22/11/2010 15 h 8 m User:esnault
*    TWK_model:NO_MODEL
*    comments :update module minor version for CoTq 10.1
* Version dev :\main\branch_lemort_cotq_dev\4 Date: 22/11/2010 14 h 4 m User:lemort
*    TWK_model:NO_MODEL
*    comments :update module minor version for CoTq 10.1
* Version int :/main/00PSASWC_EC/1 Date: 5/11/2010 11 h 58 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\3 Date: 26/10/2010 17 h 2 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 46 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 42 m User:lemort
*    TWK_model:NO_MODEL
*    comments :first dev CoTq
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CoTq.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if COTQ_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
dds_lib.* version is not compatible with current SWC version
#endif

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/


#define COTQ_SCHED          (UInt32)10      /* 0.01 * DEC3 */


/*******************************************************************************
*  File Level Type Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Scalar Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Map Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define COTQ_START_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) CoCha_tiTranCll_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) CoCha_tqIncCll_B = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) CoPt_nTarBuf_B = (CONST(UInt16, AUTOMATIC))(750 * BIN2);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqEfcAirCordLim_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqEfcAirCordLimIt_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqEfcCordLim_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqEfcCordLimIt_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqEfcReqCord_nRegReq_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqIdcAirCordLim_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqIdcAirMaxGBx_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqIdcCordLim_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqIdcCordLimBuf_tqGBx_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqIdcMaxGBx_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqIdcMaxGBxBuf_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoPt_tqMaxGBx_nRegBuf_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPEngTrv_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqCkEfcFLdLim_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqCkEfcLim_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqCkEfcSmkLim_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqCkEfcStatLim_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcCurMinFuCutSel_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcEngCurMax_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcEngCurMin_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcEngLim_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcEngLimCmb_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcEngProt_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcLdAdvMinFuCutSel_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcLdMaxTrbMax_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcLdMaxWoutOvb_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcLdMinAdvMin_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcMaxEngLimCmb_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcMaxNReg_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcMinCurCutOffTrv_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcMinCurTrv_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcMinEngLimCmb_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcPresUsThrMax_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcRed_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcSfty_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqEfcSyst_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) ThMgt_tqEfcLimAntiBoilProt_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facGainFilTrv_nCk_B = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcTrv_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqLimEM_tqIdcLimEM_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqLimEM_tqLimEMTrv_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiTranCll_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDeceIni_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEfcFilTrv_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEfcMinFeas_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEfcReq_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEngReal_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEngRealEM_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqEfcAirIdl_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqEfcEngWoutAOS_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqEfcIdl_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcAirLim_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqIncCll_B = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
#define COTQ_STOP_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"

/* 8-bits scalar calibration definition */
#define COTQ_START_SEC_CALIB_8BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(SInt8, AUTOMATIC) CoCha_noCylCutAuth_B = (CONST(SInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(SInt8, AUTOMATIC) CoPt_noTarGearCordBuf_B = (CONST(SInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_noCylCutAuth_B = (CONST(SInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bAcvCll_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bInhEGRTrv_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bAcvNRegReqBuf_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bDeacCll_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bDeacCllBuf_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bInjCutDynAuth1_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bInjCutDynAuth2_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bSIPBuf_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) COTQ_ACTIVE_BYP_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcceClrCrossAOS_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcceDetAOS_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvCll_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDeceAcv_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDeceDetAOS_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bEngAsiReqTrv_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bInhEGR_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bRstAOS_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_rLdEngRef_B = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_stDrivFilPha_B = TQSYS_STFILTRAGE_DESACTIVE;
#define COTQ_STOP_SEC_CALIB_8BIT
#include "CoTq_MemMap.h"

/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define COTQ_START_SEC_VAR_32BIT
#include "CoTq_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) cotq_prev_time;
#define COTQ_STOP_SEC_VAR_32BIT
#include "CoTq_MemMap.h"

/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define COTQ_START_SEC_INTERNAL_VAR_8BIT
#include "CoTq_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvTqCnv_irv_MP;
#define COTQ_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define COTQ_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoTq_MemMap.h"
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) CoTq_ModuleVersion_Major_MP = (UInt8)12;
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) CoTq_ModuleVersion_Minor_MP = (UInt8)0;
#define COTQ_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoTq_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_001_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    SInt16 copt_tqefcaircordlimit_tqgbx_swc_out;
    SInt16 copt_tqefccordlimit_tqgbx_swc_out;

    COTQ_Cord_Lim_Torq_Struct_Init(&copt_tqefcaircordlimit_tqgbx_swc_out,
                                   &copt_tqefccordlimit_tqgbx_swc_out);

    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I001(0) */
    Rte_Write_P_CoPt_tqEfcAirCordLimIt_tqGBx_CoPt_tqEfcAirCordLimIt_tqGBx(copt_tqefcaircordlimit_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I002(0) */
    Rte_Write_P_CoPt_tqEfcCordLimIt_tqGBx_CoPt_tqEfcCordLimIt_tqGBx(copt_tqefccordlimit_tqgbx_swc_out);
}
/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_002_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/
FUNC(void, AUTOMATIC) RE_CoTq_002_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 copt_tqaircord_tqgbx_swc_in;
    SInt16 copt_tqcord_tqgbx_swc_in;
    SInt16 englim_tqckefcairgbxlimcord_swc_in;
    SInt16 englim_tqckefcgbxlimcord_swc_in;
    Boolean tqsys_btypfu_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 copt_tqefcaircordlimit_tqgbx_swc_out;
    SInt16 copt_tqefccordlimit_tqgbx_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COTQ_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I003(0) */
        Rte_Read_R_CoPt_tqAirCord_tqGBx_CoPt_tqAirCord_tqGBx(&copt_tqaircord_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I004(0) */
        Rte_Read_R_CoPt_tqCord_tqGBx_CoPt_tqCord_tqGBx(&copt_tqcord_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I005(0) */
        Rte_Read_R_EngLim_tqCkEfcAirGBxLimCord_EngLim_tqCkEfcAirGBxLimCord(&englim_tqckefcairgbxlimcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I006(0) */
        Rte_Read_R_EngLim_tqCkEfcGBxLimCord_EngLim_tqCkEfcGBxLimCord(&englim_tqckefcgbxlimcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I007(0) */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);


        COTQ_Cord_Lim_Torq_Struct(copt_tqaircord_tqgbx_swc_in,
                                  copt_tqcord_tqgbx_swc_in,
                                  englim_tqckefcairgbxlimcord_swc_in,
                                  englim_tqckefcgbxlimcord_swc_in,
                                  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                  &copt_tqefcaircordlimit_tqgbx_swc_out,
                                  &copt_tqefccordlimit_tqgbx_swc_out );


        /* IRV OUTPUT */
    }
    else
    {
        copt_tqefcaircordlimit_tqgbx_swc_out = CoPt_tqEfcAirCordLimIt_tqGBx_B;
        copt_tqefccordlimit_tqgbx_swc_out = CoPt_tqEfcCordLimIt_tqGBx_B;
    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I001(0) */
    Rte_Write_P_CoPt_tqEfcAirCordLimIt_tqGBx_CoPt_tqEfcAirCordLimIt_tqGBx(copt_tqefcaircordlimit_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I002(0) */
    Rte_Write_P_CoPt_tqEfcCordLimIt_tqGBx_CoPt_tqEfcCordLimIt_tqGBx(copt_tqefccordlimit_tqgbx_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_003_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_003_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqdem_tqckefctrv_swc_out;
    UInt8 cocha_bacvcll_swc_out;
    UInt8 cocha_binhegrtrv_swc_out;
    SInt8 cocha_nocylcutauth_swc_out;
    UInt16 cocha_titrancll_swc_out;
    UInt16 cocha_tqinccll_swc_out;
    UInt8 copt_bdeaccll_swc_out;
    SInt16 copt_tqefcaircordlim_tqgbx_swc_out;
    SInt16 copt_tqefccordlim_tqgbx_swc_out;
    UInt16 covsctl_raccpengtrv_swc_out;
    SInt16 englim_tqckefcstatlim_swc_out;
    UInt16 tqdem_facgainfiltrv_nck_swc_out;
    SInt16 tqlimem_tqlimemtrv_swc_out;
    UInt8 tqsys_bacceclrcrossaos_swc_out;
    UInt8 tqsys_baccedetaos_swc_out;
    UInt8 tqsys_bacvcll_swc_out;
    UInt8 tqsys_bdeceacv_swc_out;
    UInt8 tqsys_bdecedetaos_swc_out;
    UInt8 tqsys_bengasireqtrv_swc_out;
    SInt8 tqsys_nocylcutauth_swc_out;
    UInt8 tqsys_stdrivfilpha_swc_out;
    UInt16 tqsys_titrancll_swc_out;
    SInt16 tqsys_tqckdeceini_swc_out;
    SInt16 tqsys_tqckefcfiltrv_swc_out;
    UInt16 tqsys_tqinccll_swc_out;
    SInt16 tqsys_tqthdpha3_swc_out;


    COTQ_Torque_Selection_Init( &cocha_bacvcll_swc_out,
                                &cocha_binhegrtrv_swc_out,
                                &cocha_nocylcutauth_swc_out,
                                &cocha_titrancll_swc_out,
                                &cocha_tqinccll_swc_out,
                                &copt_bdeaccll_swc_out,
                                &copt_tqefcaircordlim_tqgbx_swc_out,
                                &copt_tqefccordlim_tqgbx_swc_out,
                                &covsctl_raccpengtrv_swc_out,
                                &englim_tqckefcstatlim_swc_out,
                                &tqdem_facgainfiltrv_nck_swc_out,
                                &tqdem_tqckefctrv_swc_out,
                                &tqlimem_tqlimemtrv_swc_out,
                                &tqsys_bacceclrcrossaos_swc_out,
                                &tqsys_baccedetaos_swc_out,
                                &tqsys_bacvcll_swc_out,
                                &tqsys_bdeceacv_swc_out,
                                &tqsys_bdecedetaos_swc_out,
                                &tqsys_bengasireqtrv_swc_out,
                                &tqsys_nocylcutauth_swc_out,
                                &tqsys_stdrivfilpha_swc_out,
                                &tqsys_titrancll_swc_out,
                                &tqsys_tqckdeceini_swc_out,
                                &tqsys_tqckefcfiltrv_swc_out,
                                &tqsys_tqinccll_swc_out,
                                &tqsys_tqthdpha3_swc_out );





    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I009(0) */
    Rte_Write_P_TqDem_tqCkEfcTrv_TqDem_tqCkEfcTrv(tqdem_tqckefctrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I010(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bAcvCll_CoCha_bAcvCll(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_bacvcll_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I011(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bInhEGRTrv_CoCha_bInhEGRTrv(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_binhegrtrv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I012(0) */
    Rte_Write_P_CoCha_noCylCutAuth_CoCha_noCylCutAuth(cocha_nocylcutauth_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I013(0) */
    Rte_Write_P_CoCha_tiTranCll_CoCha_tiTranCll(cocha_titrancll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I014(0) */
    Rte_Write_P_CoCha_tqIncCll_CoCha_tqIncCll(cocha_tqinccll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I015(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bDeacCll_CoPt_bDeacCll(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bdeaccll_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I016(0) */
    Rte_Write_P_CoPt_tqEfcAirCordLim_tqGBx_CoPt_tqEfcAirCordLim_tqGBx(copt_tqefcaircordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I017(0) */
    Rte_Write_P_CoPt_tqEfcCordLim_tqGBx_CoPt_tqEfcCordLim_tqGBx(copt_tqefccordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I018(0) */
    Rte_Write_P_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(covsctl_raccpengtrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I019(0) */
    Rte_Write_P_EngLim_tqCkEfcStatLim_EngLim_tqCkEfcStatLim(englim_tqckefcstatlim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I020(0) */
    Rte_Write_P_TqDem_facGainFilTrv_nCk_TqDem_facGainFilTrv_nCk(tqdem_facgainfiltrv_nck_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I021(0) */
    Rte_Write_P_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(tqlimem_tqlimemtrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I022(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceClrCrossAOS_TqSys_bAcceClrCrossAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacceclrcrossaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I023(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceDetAOS_TqSys_bAcceDetAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_baccedetaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I024(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvCll_TqSys_bAcvCll(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvcll_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I025(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceAcv_TqSys_bDeceAcv(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdeceacv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I026(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceDetAOS_TqSys_bDeceDetAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdecedetaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I027(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bEngAsiReqTrv_TqSys_bEngAsiReqTrv(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bengasireqtrv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I028(0) */
    Rte_Write_P_TqSys_noCylCutAuth_TqSys_noCylCutAuth(tqsys_nocylcutauth_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I029(0) */
    Rte_Write_P_TqSys_stDrivFilPha_TqSys_stDrivFilPha(tqsys_stdrivfilpha_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I030(0) */
    Rte_Write_P_TqSys_tiTranCll_TqSys_tiTranCll(tqsys_titrancll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I031(0) */
    Rte_Write_P_TqSys_tqCkDeceIni_TqSys_tqCkDeceIni(tqsys_tqckdeceini_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I032(0) */
    Rte_Write_P_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(tqsys_tqckefcfiltrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I033(0) */
    Rte_Write_P_TqSys_tqIncCll_TqSys_tqIncCll(tqsys_tqinccll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I034(0) */
    Rte_Write_P_TqSys_tqThdPha3_TqSys_tqThdPha3(tqsys_tqthdpha3_swc_out);
}
/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_004_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_004_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 copt_tqefcaircordlimit_tqgbx_swc_in;
    SInt16 copt_tqefccordlimit_tqgbx_swc_in;
    Boolean cocha_bacvcllit_swc_in;
    Boolean cocha_binhegr_swc_in;
    Boolean cocha_binhegrext_swc_in;
    SInt8 cocha_nocylcutauthit_swc_in;
    UInt16 cocha_titrancllit_swc_in;
    SInt16 cocha_tqinccllit_swc_in;
    Boolean copt_bdeaccllext_swc_in;
    Boolean copt_bdeaccllit_swc_in;
    SInt16 copt_tqefcaircordlimexttqgbx_swc_in;
    SInt16 copt_tqefccordlimext_tqgbx_swc_in;
    Boolean coptuh_bengasireq_swc_in;
    Boolean coptuh_bengasireqext_swc_in;
    UInt16 covsctl_raccpeng_swc_in;
    UInt16 covsctl_raccpengext_swc_in;
    SInt16 englim_tqckefcstatlimext_swc_in;
    SInt16 englim_tqckefcstatlimit_swc_in;
    UInt8 ext_sttratypcf_swc_in;
    UInt16 tqdem_facgainfil_nck_swc_in;
    SInt16 tqdem_tqckefc_swc_in;
    SInt16 tqlimem_tqlimem_swc_in;
    SInt16 tqlimem_tqlimemext_swc_in;
    Boolean tqsys_bacceclrcrossaosext_swc_in;
    Boolean tqsys_bacceclrcrossaosit_swc_in;
    Boolean tqsys_baccedetaosext_swc_in;
    Boolean tqsys_baccedetaosit_swc_in;
    Boolean tqsys_bacvcllext_swc_in;
    Boolean tqsys_bacvcllit_swc_in;
    Boolean tqsys_bdeceacvext_swc_in;
    Boolean tqsys_bdeceacvit_swc_in;
    Boolean tqsys_bdecedetaosext_swc_in;
    Boolean tqsys_bdecedetaosit_swc_in;
    SInt8 tqsys_nocylcutauthext_swc_in;
    SInt8 tqsys_nocylcutauthit_swc_in;
    UInt8 tqsys_stdrivfilphaext_swc_in;
    UInt8 tqsys_stdrivfilphait_swc_in;
    UInt8 tqsys_sttyppwtcf_swc_in;
    UInt16 tqsys_titrancllext_swc_in;
    UInt16 tqsys_titrancllit_swc_in;
    SInt16 tqsys_tqckdeceiniext_swc_in;
    SInt16 tqsys_tqckdeceiniit_swc_in;
    SInt16 tqsys_tqckefcfil_swc_in;
    SInt16 tqsys_tqckefcfilext_swc_in;
    UInt16 tqsys_tqinccllext_swc_in;
    UInt16 tqsys_tqinccllit_swc_in;
    SInt16 tqsys_tqthdpha3ext_swc_in;
    SInt16 tqsys_tqthdpha3it_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqdem_tqckefctrv_swc_out;
    UInt8 cocha_bacvcll_swc_out;
    UInt8 cocha_binhegrtrv_swc_out;
    SInt8 cocha_nocylcutauth_swc_out;
    UInt16 cocha_titrancll_swc_out;
    UInt16 cocha_tqinccll_swc_out;
    UInt8 copt_bdeaccll_swc_out;
    SInt16 copt_tqefcaircordlim_tqgbx_swc_out;
    SInt16 copt_tqefccordlim_tqgbx_swc_out;
    UInt16 covsctl_raccpengtrv_swc_out;
    SInt16 englim_tqckefcstatlim_swc_out;
    UInt16 tqdem_facgainfiltrv_nck_swc_out;
    SInt16 tqlimem_tqlimemtrv_swc_out;
    UInt8 tqsys_bacceclrcrossaos_swc_out;
    UInt8 tqsys_baccedetaos_swc_out;
    UInt8 tqsys_bacvcll_swc_out;
    UInt8 tqsys_bdeceacv_swc_out;
    UInt8 tqsys_bdecedetaos_swc_out;
    UInt8 tqsys_bengasireqtrv_swc_out;
    SInt8 tqsys_nocylcutauth_swc_out;
    UInt8 tqsys_stdrivfilpha_swc_out;
    UInt16 tqsys_titrancll_swc_out;
    SInt16 tqsys_tqckdeceini_swc_out;
    SInt16 tqsys_tqckefcfiltrv_swc_out;
    UInt16 tqsys_tqinccll_swc_out;
    SInt16 tqsys_tqthdpha3_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COTQ_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I001(0) */
        Rte_Read_R_CoPt_tqEfcAirCordLimIt_tqGBx_CoPt_tqEfcAirCordLimIt_tqGBx(&copt_tqefcaircordlimit_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I002(0) */
        Rte_Read_R_CoPt_tqEfcCordLimIt_tqGBx_CoPt_tqEfcCordLimIt_tqGBx(&copt_tqefccordlimit_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I035(0) */
        Rte_Read_R_CoCha_bAcvCllIt_CoCha_bAcvCllIt(&cocha_bacvcllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I036(0) */
        Rte_Read_R_CoCha_bInhEGR_CoCha_bInhEGR(&cocha_binhegr_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I037(0) */
        Rte_Read_R_CoCha_bInhEGRExt_CoCha_bInhEGRExt(&cocha_binhegrext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I038(0) */
        Rte_Read_R_CoCha_noCylCutAuthIt_CoCha_noCylCutAuthIt(&cocha_nocylcutauthit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I039(0) */
        Rte_Read_R_CoCha_tiTranCllIt_CoCha_tiTranCllIt(&cocha_titrancllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I040(0) */
        Rte_Read_R_CoCha_tqIncCllIt_CoCha_tqIncCllIt(&cocha_tqinccllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I041(0) */
        Rte_Read_R_CoPt_bDeacCllExt_CoPt_bDeacCllExt(&copt_bdeaccllext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I042(0) */
        Rte_Read_R_CoPt_bDeacCllIt_CoPt_bDeacCllIt(&copt_bdeaccllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I043(0) */
        Rte_Read_R_CoPt_tqEfcAirCordLimExtTqGBx_CoPt_tqEfcAirCordLimExtTqGBx(&copt_tqefcaircordlimexttqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I045(0) */
        Rte_Read_R_CoPt_tqEfcCordLimExt_tqGBx_CoPt_tqEfcCordLimExt_tqGBx(&copt_tqefccordlimext_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I047(0) */
        Rte_Read_R_CoPtUH_bEngAsiReq_CoPtUH_bEngAsiReq(&coptuh_bengasireq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I048(0) */
        Rte_Read_R_CoPtUH_bEngAsiReqExt_CoPtUH_bEngAsiReqExt(&coptuh_bengasireqext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I049(0) */
        Rte_Read_R_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(&covsctl_raccpeng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I050(0) */
        Rte_Read_R_CoVSCtl_rAccPEngExt_CoVSCtl_rAccPEngExt(&covsctl_raccpengext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I051(0) */
        Rte_Read_R_EngLim_tqCkEfcStatLimExt_EngLim_tqCkEfcStatLimExt(&englim_tqckefcstatlimext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I052(0) */
        Rte_Read_R_EngLim_tqCkEfcStatLimIt_EngLim_tqCkEfcStatLimIt(&englim_tqckefcstatlimit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I053(0) */
        Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&ext_sttratypcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I054(0) */
        Rte_Read_R_TqDem_facGainFil_nCk_TqDem_facGainFil_nCk(&tqdem_facgainfil_nck_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I055(0) */
        Rte_Read_R_TqDem_tqCkEfc_TqDem_tqCkEfc(&tqdem_tqckefc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I056(0) */
        Rte_Read_R_TqLimEM_tqLimEM_TqLimEM_tqLimEM(&tqlimem_tqlimem_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I057(0) */
        Rte_Read_R_TqLimEM_tqLimEMExt_TqLimEM_tqLimEMExt(&tqlimem_tqlimemext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I058(0) */
        Rte_Read_R_TqSys_bAcceClrCrossAOSExt_TqSys_bAcceClrCrossAOSExt(&tqsys_bacceclrcrossaosext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I059(0) */
        Rte_Read_R_TqSys_bAcceClrCrossAOSIt_TqSys_bAcceClrCrossAOSIt(&tqsys_bacceclrcrossaosit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I060(0) */
        Rte_Read_R_TqSys_bAcceDetAOSExt_TqSys_bAcceDetAOSExt(&tqsys_baccedetaosext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I061(0) */
        Rte_Read_R_TqSys_bAcceDetAOSIt_TqSys_bAcceDetAOSIt(&tqsys_baccedetaosit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I062(0) */
        Rte_Read_R_TqSys_bAcvCllExt_TqSys_bAcvCllExt(&tqsys_bacvcllext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I063(0) */
        Rte_Read_R_TqSys_bAcvCllIt_TqSys_bAcvCllIt(&tqsys_bacvcllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I064(0) */
        Rte_Read_R_TqSys_bDeceAcvExt_TqSys_bDeceAcvExt(&tqsys_bdeceacvext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I065(0) */
        Rte_Read_R_TqSys_bDeceAcvIt_TqSys_bDeceAcvIt(&tqsys_bdeceacvit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I066(0) */
        Rte_Read_R_TqSys_bDeceDetAOSExt_TqSys_bDeceDetAOSExt(&tqsys_bdecedetaosext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I067(0) */
        Rte_Read_R_TqSys_bDeceDetAOSIt_TqSys_bDeceDetAOSIt(&tqsys_bdecedetaosit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I068(0) */
        Rte_Read_R_TqSys_noCylCutAuthExt_TqSys_noCylCutAuthExt(&tqsys_nocylcutauthext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I069(0) */
        Rte_Read_R_TqSys_noCylCutAuthIt_TqSys_noCylCutAuthIt(&tqsys_nocylcutauthit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I071(0) */
        Rte_Read_R_TqSys_stDrivFilPhaExt_TqSys_stDrivFilPhaExt(&tqsys_stdrivfilphaext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I072(0) */
        Rte_Read_R_TqSys_stDrivFilPhaIt_TqSys_stDrivFilPhaIt(&tqsys_stdrivfilphait_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I073(0) */
        Rte_Read_R_TqSys_stTypPwtCf_TqSys_stTypPwtCf(&tqsys_sttyppwtcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I074(0) */
        Rte_Read_R_TqSys_tiTranCllExt_TqSys_tiTranCllExt(&tqsys_titrancllext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I075(0) */
        Rte_Read_R_TqSys_tiTranCllIt_TqSys_tiTranCllIt(&tqsys_titrancllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I076(0) */
        Rte_Read_R_TqSys_tqCkDeceIniExt_TqSys_tqCkDeceIniExt(&tqsys_tqckdeceiniext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I077(0) */
        Rte_Read_R_TqSys_tqCkDeceIniIt_TqSys_tqCkDeceIniIt(&tqsys_tqckdeceiniit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I078(0) */
        Rte_Read_R_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(&tqsys_tqckefcfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I079(0) */
        Rte_Read_R_TqSys_tqCkEfcFilExt_TqSys_tqCkEfcFilExt(&tqsys_tqckefcfilext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I080(0) */
        Rte_Read_R_TqSys_tqIncCllExt_TqSys_tqIncCllExt(&tqsys_tqinccllext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I081(0) */
        Rte_Read_R_TqSys_tqIncCllIt_TqSys_tqIncCllIt(&tqsys_tqinccllit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I082(0) */
        Rte_Read_R_TqSys_tqThdPha3Ext_TqSys_tqThdPha3Ext(&tqsys_tqthdpha3ext_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I083(0) */
        Rte_Read_R_TqSys_tqThdPha3It_TqSys_tqThdPha3It(&tqsys_tqthdpha3it_swc_in);



        COTQ_Torque_Selection(  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(cocha_bacvcllit_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(cocha_binhegr_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(cocha_binhegrext_swc_in),
                                cocha_nocylcutauthit_swc_in,
                                cocha_titrancllit_swc_in,
                                cocha_tqinccllit_swc_in,
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(copt_bdeaccllext_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(copt_bdeaccllit_swc_in),
                                copt_tqefcaircordlimexttqgbx_swc_in,
                                copt_tqefcaircordlimit_tqgbx_swc_in,
                                copt_tqefccordlimext_tqgbx_swc_in,
                                copt_tqefccordlimit_tqgbx_swc_in,
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(coptuh_bengasireq_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(coptuh_bengasireqext_swc_in),
                                covsctl_raccpeng_swc_in,
                                covsctl_raccpengext_swc_in,
                                englim_tqckefcstatlimext_swc_in,
                                englim_tqckefcstatlimit_swc_in,
                                ext_sttratypcf_swc_in,
                                tqdem_facgainfil_nck_swc_in,
                                tqdem_tqckefc_swc_in,
                                tqlimem_tqlimem_swc_in,
                                tqlimem_tqlimemext_swc_in,
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacceclrcrossaosext_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacceclrcrossaosit_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_baccedetaosext_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_baccedetaosit_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvcllext_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvcllit_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bdeceacvext_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bdeceacvit_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bdecedetaosext_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bdecedetaosit_swc_in),
                                tqsys_nocylcutauthext_swc_in,
                                tqsys_nocylcutauthit_swc_in,
                                tqsys_stdrivfilphaext_swc_in,
                                tqsys_stdrivfilphait_swc_in,
                                tqsys_sttyppwtcf_swc_in,
                                tqsys_titrancllext_swc_in,
                                tqsys_titrancllit_swc_in,
                                tqsys_tqckdeceiniext_swc_in,
                                tqsys_tqckdeceiniit_swc_in,
                                tqsys_tqckefcfil_swc_in,
                                tqsys_tqckefcfilext_swc_in,
                                tqsys_tqinccllext_swc_in,
                                tqsys_tqinccllit_swc_in,
                                tqsys_tqthdpha3ext_swc_in,
                                tqsys_tqthdpha3it_swc_in,
                                &cocha_bacvcll_swc_out,
                                &cocha_binhegrtrv_swc_out,
                                &cocha_nocylcutauth_swc_out,
                                &cocha_titrancll_swc_out,
                                &cocha_tqinccll_swc_out,
                                &copt_bdeaccll_swc_out,
                                &copt_tqefcaircordlim_tqgbx_swc_out,
                                &copt_tqefccordlim_tqgbx_swc_out,
                                &covsctl_raccpengtrv_swc_out,
                                &englim_tqckefcstatlim_swc_out,
                                &tqdem_facgainfiltrv_nck_swc_out,
                                &tqdem_tqckefctrv_swc_out,
                                &tqlimem_tqlimemtrv_swc_out,
                                &tqsys_bacceclrcrossaos_swc_out,
                                &tqsys_baccedetaos_swc_out,
                                &tqsys_bacvcll_swc_out,
                                &tqsys_bdeceacv_swc_out,
                                &tqsys_bdecedetaos_swc_out,
                                &tqsys_bengasireqtrv_swc_out,
                                &tqsys_nocylcutauth_swc_out,
                                &tqsys_stdrivfilpha_swc_out,
                                &tqsys_titrancll_swc_out,
                                &tqsys_tqckdeceini_swc_out,
                                &tqsys_tqckefcfiltrv_swc_out,
                                &tqsys_tqinccll_swc_out,
                                &tqsys_tqthdpha3_swc_out );

        /* IRV OUTPUT */
    }
    else
    {

        tqdem_tqckefctrv_swc_out = TqDem_tqCkEfcTrv_B;
        cocha_bacvcll_swc_out = CoCha_bAcvCll_B;
        cocha_binhegrtrv_swc_out = CoCha_bInhEGRTrv_B;
        cocha_nocylcutauth_swc_out = CoCha_noCylCutAuth_B;
        cocha_titrancll_swc_out = CoCha_tiTranCll_B;
        cocha_tqinccll_swc_out = CoCha_tqIncCll_B;
        copt_bdeaccll_swc_out = CoPt_bDeacCll_B;
        copt_tqefcaircordlim_tqgbx_swc_out = CoPt_tqEfcAirCordLim_tqGBx_B;
        copt_tqefccordlim_tqgbx_swc_out = CoPt_tqEfcCordLim_tqGBx_B;
        covsctl_raccpengtrv_swc_out = CoVSCtl_rAccPEngTrv_B;
        englim_tqckefcstatlim_swc_out = EngLim_tqCkEfcStatLim_B;
        tqdem_facgainfiltrv_nck_swc_out = TqDem_facGainFilTrv_nCk_B;
        tqlimem_tqlimemtrv_swc_out = TqLimEM_tqLimEMTrv_B;
        tqsys_bacceclrcrossaos_swc_out = TqSys_bAcceClrCrossAOS_B;
        tqsys_baccedetaos_swc_out = TqSys_bAcceDetAOS_B;
        tqsys_bacvcll_swc_out = TqSys_bAcvCll_B;
        tqsys_bdeceacv_swc_out = TqSys_bDeceAcv_B;
        tqsys_bdecedetaos_swc_out = TqSys_bDeceDetAOS_B;
        tqsys_bengasireqtrv_swc_out = TqSys_bEngAsiReqTrv_B;
        tqsys_nocylcutauth_swc_out = TqSys_noCylCutAuth_B;
        tqsys_stdrivfilpha_swc_out = TqSys_stDrivFilPha_B;
        tqsys_titrancll_swc_out = TqSys_tiTranCll_B;
        tqsys_tqckdeceini_swc_out = TqSys_tqCkDeceIni_B;
        tqsys_tqckefcfiltrv_swc_out = TqSys_tqCkEfcFilTrv_B;
        tqsys_tqinccll_swc_out = TqSys_tqIncCll_B;
        tqsys_tqthdpha3_swc_out = TqSys_tqThdPha3_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I009(0) */
    Rte_Write_P_TqDem_tqCkEfcTrv_TqDem_tqCkEfcTrv(tqdem_tqckefctrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I010(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bAcvCll_CoCha_bAcvCll(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_bacvcll_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I011(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bInhEGRTrv_CoCha_bInhEGRTrv(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_binhegrtrv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I012(0) */
    Rte_Write_P_CoCha_noCylCutAuth_CoCha_noCylCutAuth(cocha_nocylcutauth_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I013(0) */
    Rte_Write_P_CoCha_tiTranCll_CoCha_tiTranCll(cocha_titrancll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I014(0) */
    Rte_Write_P_CoCha_tqIncCll_CoCha_tqIncCll(cocha_tqinccll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I015(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bDeacCll_CoPt_bDeacCll(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bdeaccll_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I016(0) */
    Rte_Write_P_CoPt_tqEfcAirCordLim_tqGBx_CoPt_tqEfcAirCordLim_tqGBx(copt_tqefcaircordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I017(0) */
    Rte_Write_P_CoPt_tqEfcCordLim_tqGBx_CoPt_tqEfcCordLim_tqGBx(copt_tqefccordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I018(0) */
    Rte_Write_P_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(covsctl_raccpengtrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I019(0) */
    Rte_Write_P_EngLim_tqCkEfcStatLim_EngLim_tqCkEfcStatLim(englim_tqckefcstatlim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I020(0) */
    Rte_Write_P_TqDem_facGainFilTrv_nCk_TqDem_facGainFilTrv_nCk(tqdem_facgainfiltrv_nck_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I021(0) */
    Rte_Write_P_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(tqlimem_tqlimemtrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I022(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceClrCrossAOS_TqSys_bAcceClrCrossAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacceclrcrossaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I023(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceDetAOS_TqSys_bAcceDetAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_baccedetaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I024(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvCll_TqSys_bAcvCll(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvcll_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I025(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceAcv_TqSys_bDeceAcv(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdeceacv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I026(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceDetAOS_TqSys_bDeceDetAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdecedetaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I027(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bEngAsiReqTrv_TqSys_bEngAsiReqTrv(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bengasireqtrv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I028(0) */
    Rte_Write_P_TqSys_noCylCutAuth_TqSys_noCylCutAuth(tqsys_nocylcutauth_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I029(0) */
    Rte_Write_P_TqSys_stDrivFilPha_TqSys_stDrivFilPha(tqsys_stdrivfilpha_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I030(0) */
    Rte_Write_P_TqSys_tiTranCll_TqSys_tiTranCll(tqsys_titrancll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I031(0) */
    Rte_Write_P_TqSys_tqCkDeceIni_TqSys_tqCkDeceIni(tqsys_tqckdeceini_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I032(0) */
    Rte_Write_P_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(tqsys_tqckefcfiltrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I033(0) */
    Rte_Write_P_TqSys_tqIncCll_TqSys_tqIncCll(tqsys_tqinccll_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I034(0) */
    Rte_Write_P_TqSys_tqThdPha3_TqSys_tqThdPha3(tqsys_tqthdpha3_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_005_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_005_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    SInt16 copt_tqidcaircordlim_tqgbx_swc_out;
    SInt16 copt_tqidcairmaxgbx_swc_out;
    SInt16 copt_tqidccordlim_tqgbx_swc_out;
    SInt16 copt_tqidcmaxgbx_swc_out;
    SInt16 tqlimem_tqidclimem_swc_out;
    UInt8 tqsys_binhegr_swc_out;
    UInt8 tqsys_brstaos_swc_out;
    SInt16 tqsys_tqidcairlim_swc_out;

    COTQ_Cme_Cmi_Convers_Init(  &copt_tqidcaircordlim_tqgbx_swc_out,
                                &copt_tqidcairmaxgbx_swc_out,
                                &copt_tqidccordlim_tqgbx_swc_out,
                                &copt_tqidcmaxgbx_swc_out,
                                &tqlimem_tqidclimem_swc_out,
                                &tqsys_binhegr_swc_out,
                                &tqsys_brstaos_swc_out,
                                &tqsys_tqidcairlim_swc_out );


    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I084(0) */
    Rte_Write_P_CoPt_tqIdcAirCordLim_tqGBx_CoPt_tqIdcAirCordLim_tqGBx(copt_tqidcaircordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I085(0) */
    Rte_Write_P_CoPt_tqIdcAirMaxGBx_CoPt_tqIdcAirMaxGBx(copt_tqidcairmaxgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I086(0) */
    Rte_Write_P_CoPt_tqIdcCordLim_tqGBx_CoPt_tqIdcCordLim_tqGBx(copt_tqidccordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I087(0) */
    Rte_Write_P_CoPt_tqIdcMaxGBx_CoPt_tqIdcMaxGBx(copt_tqidcmaxgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I088(0) */
    Rte_Write_P_TqLimEM_tqIdcLimEM_TqLimEM_tqIdcLimEM(tqlimem_tqidclimem_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I089(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bInhEGR_TqSys_bInhEGR(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_binhegr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I090(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bRstAOS_TqSys_bRstAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_brstaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I091(0) */
    Rte_Write_P_TqSys_tqIdcAirLim_TqSys_tqIdcAirLim(tqsys_tqidcairlim_swc_out);
}
/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_006_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_006_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    Boolean cocha_binhegrtrv_swc_in;
    Boolean cocha_brstaos_swc_in;
    Boolean copt_binhegr_swc_in;
    SInt16 copt_tqairmaxgbx_swc_in;
    SInt16 copt_tqefcaircordlim_tqgbx_swc_in;
    SInt16 copt_tqefccordlim_tqgbx_swc_in;
    SInt16 copt_tqmaxgbx_swc_in;
    SInt16 englim_tqckefcairlim_swc_in;
    SInt16 tqcmp_tqaltloss_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqsys_bfucutoffreq_swc_in;
    SInt16 tqlimem_tqlimemtrv_swc_in;
    Boolean tqsys_btypfu_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 copt_tqidcaircordlim_tqgbx_swc_out;
    SInt16 copt_tqidcairmaxgbx_swc_out;
    SInt16 copt_tqidccordlim_tqgbx_swc_out;
    SInt16 copt_tqidcmaxgbx_swc_out;
    SInt16 tqlimem_tqidclimem_swc_out;
    UInt8 tqsys_binhegr_swc_out;
    UInt8 tqsys_brstaos_swc_out;
    SInt16 tqsys_tqidcairlim_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COTQ_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I092(0) */
        Rte_Read_R_CoCha_bInhEGRTrv_CoCha_bInhEGRTrv(&cocha_binhegrtrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I093(0) */
        Rte_Read_R_CoCha_bRstAOS_CoCha_bRstAOS(&cocha_brstaos_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I094(0) */
        Rte_Read_R_CoPt_bInhEGR_CoPt_bInhEGR(&copt_binhegr_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I095(0) */
        Rte_Read_R_CoPt_tqAirMaxGBx_CoPt_tqAirMaxGBx(&copt_tqairmaxgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I096(0) */
        Rte_Read_R_CoPt_tqEfcAirCordLim_tqGBx_CoPt_tqEfcAirCordLim_tqGBx(&copt_tqefcaircordlim_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I097(0) */
        Rte_Read_R_CoPt_tqEfcCordLim_tqGBx_CoPt_tqEfcCordLim_tqGBx(&copt_tqefccordlim_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I098(0) */
        Rte_Read_R_CoPt_tqMaxGBx_CoPt_tqMaxGBx(&copt_tqmaxgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I099(0) */
        Rte_Read_R_EngLim_tqCkEfcAirLim_EngLim_tqCkEfcAirLim(&englim_tqckefcairlim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I100(0) */
        Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&tqcmp_tqaltloss_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I101(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I103(0) */
        Rte_Read_R_TqSys_bFuCutOffReq_TqSys_bFuCutOffReq(&tqsys_bfucutoffreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I102(0) */
        Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&tqlimem_tqlimemtrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I007(0) */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);

        COTQ_Cme_Cmi_Convers(  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(cocha_binhegrtrv_swc_in),
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(cocha_brstaos_swc_in),
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(copt_binhegr_swc_in),
                               copt_tqairmaxgbx_swc_in,
                               copt_tqefcaircordlim_tqgbx_swc_in,
                               copt_tqefccordlim_tqgbx_swc_in,
                               copt_tqmaxgbx_swc_in,
                               englim_tqckefcairlim_swc_in,
                               tqcmp_tqaltloss_swc_in,
                               tqcmp_tqsumlosscmp_swc_in,
                               tqlimem_tqlimemtrv_swc_in,
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bfucutoffreq_swc_in),
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                               &copt_tqidcaircordlim_tqgbx_swc_out,
                               &copt_tqidcairmaxgbx_swc_out,
                               &copt_tqidccordlim_tqgbx_swc_out,
                               &copt_tqidcmaxgbx_swc_out,
                               &tqlimem_tqidclimem_swc_out,
                               &tqsys_binhegr_swc_out,
                               &tqsys_brstaos_swc_out,
                               &tqsys_tqidcairlim_swc_out );



        /* IRV OUTPUT */
    }
    else
    {
        copt_tqidcaircordlim_tqgbx_swc_out = CoPt_tqIdcAirCordLim_tqGBx_B;
        copt_tqidcairmaxgbx_swc_out = CoPt_tqIdcAirMaxGBx_B;
        copt_tqidccordlim_tqgbx_swc_out = CoPt_tqIdcCordLim_tqGBx_B;
        copt_tqidcmaxgbx_swc_out = CoPt_tqIdcMaxGBx_B;
        tqlimem_tqidclimem_swc_out = TqLimEM_tqIdcLimEM_B;
        tqsys_binhegr_swc_out = TqSys_bInhEGR_B;
        tqsys_brstaos_swc_out = TqSys_bRstAOS_B;
        tqsys_tqidcairlim_swc_out = TqSys_tqIdcAirLim_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I084(0) */
    Rte_Write_P_CoPt_tqIdcAirCordLim_tqGBx_CoPt_tqIdcAirCordLim_tqGBx(copt_tqidcaircordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I085(0) */
    Rte_Write_P_CoPt_tqIdcAirMaxGBx_CoPt_tqIdcAirMaxGBx(copt_tqidcairmaxgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I086(0) */
    Rte_Write_P_CoPt_tqIdcCordLim_tqGBx_CoPt_tqIdcCordLim_tqGBx(copt_tqidccordlim_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I087(0) */
    Rte_Write_P_CoPt_tqIdcMaxGBx_CoPt_tqIdcMaxGBx(copt_tqidcmaxgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I088(0) */
    Rte_Write_P_TqLimEM_tqIdcLimEM_TqLimEM_tqIdcLimEM(tqlimem_tqidclimem_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I089(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bInhEGR_TqSys_bInhEGR(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_binhegr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I090(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bRstAOS_TqSys_bRstAOS(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_brstaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I091(0) */
    Rte_Write_P_TqSys_tqIdcAirLim_TqSys_tqIdcAirLim(tqsys_tqidcairlim_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_007_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_007_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    SInt16 copt_tqefcreqcord_nregreq_swc_out;
    SInt16 englim_tqefccurminfucutsel_swc_out;
    SInt16 englim_tqefcengcurmin_swc_out;
    SInt16 englim_tqefcenglim_swc_out;
    SInt16 englim_tqefcenglimcmb_swc_out;
    SInt16 englim_tqefcldadvminfucutsel_swc_out;
    SInt16 englim_tqefcldmaxwoutovb_swc_out;
    SInt16 englim_tqefcldminadvmin_swc_out;
    SInt16 englim_tqefcmaxenglimcmb_swc_out;
    SInt16 englim_tqefcminenglimcmb_swc_out;
    UInt8 tqsys_rldengref_swc_out;
    SInt16 tqsys_tqckengrealem_swc_out;
    SInt16 tqsys_tqefcengwoutaos_swc_out;
    SInt16 englim_tqckefcfldlim_swc_out;
    SInt16 englim_tqckefclim_swc_out;
    SInt16 englim_tqckefcsmklim_swc_out;
    SInt16 englim_tqefcengcurmax_swc_out;
    SInt16 englim_tqefcengprot_swc_out;
    SInt16 englim_tqefcldmaxtrbmax_swc_out;
    SInt16 englim_tqefcmaxnreg_swc_out;
    SInt16 englim_tqefcmincurcutofftrv_swc_out;
    SInt16 englim_tqefcmincurtrv_swc_out;
    SInt16 englim_tqefcpresusthrmax_swc_out;
    SInt16 englim_tqefcred_swc_out;
    SInt16 englim_tqefcsfty_swc_out;
    SInt16 englim_tqefcsyst_swc_out;
    SInt16 thmgt_tqefclimantiboilprot_swc_out;
    SInt16 tqsys_tqckefcminfeas_swc_out;
    SInt16 tqsys_tqckefcreq_swc_out;
    SInt16 tqsys_tqckengreal_swc_out;
    SInt16 tqsys_tqefcairidl_swc_out;
    SInt16 tqsys_tqefcidl_swc_out;

    COTQ_Func_Call_Init(&TqSys_bAcvTqCnv_irv_MP);

    COTQ_Sync_Engine_Speed_Init(  &copt_tqefcreqcord_nregreq_swc_out,
                                  &englim_tqefcenglim_swc_out,
                                  &englim_tqefcenglimcmb_swc_out,
                                  &englim_tqefcldadvminfucutsel_swc_out,
                                  &englim_tqefcldminadvmin_swc_out,
                                  &englim_tqefcmaxenglimcmb_swc_out,
                                  &englim_tqefcmaxnreg_swc_out,
                                  &tqsys_tqckefcminfeas_swc_out,
                                  &tqsys_tqckengreal_swc_out,
                                  &tqsys_tqckengrealem_swc_out,
                                  &tqsys_tqefcengwoutaos_swc_out );

    cotq_prev_time = DDS_COTQ_1MS_U32_TIME;

    COTQ_Conversion_10ms_Init(  &englim_tqckefcfldlim_swc_out,
                                &englim_tqckefclim_swc_out,
                                &englim_tqckefcsmklim_swc_out,
                                &englim_tqefccurminfucutsel_swc_out,
                                &englim_tqefcengcurmax_swc_out,
                                &englim_tqefcengcurmin_swc_out,
                                &englim_tqefcengprot_swc_out,
                                &englim_tqefcldmaxtrbmax_swc_out,
                                &englim_tqefcldmaxwoutovb_swc_out,
                                &englim_tqefcmincurcutofftrv_swc_out,
                                &englim_tqefcmincurtrv_swc_out,
                                &englim_tqefcminenglimcmb_swc_out,
                                &englim_tqefcpresusthrmax_swc_out,
                                &englim_tqefcred_swc_out,
                                &englim_tqefcsfty_swc_out,
                                &englim_tqefcsyst_swc_out,
                                &thmgt_tqefclimantiboilprot_swc_out,
                                &tqsys_rldengref_swc_out,
                                &tqsys_tqckefcreq_swc_out,
                                &tqsys_tqefcairidl_swc_out,
                                &tqsys_tqefcidl_swc_out );

    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.IRV1(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_CoTq_007_MSE_TqSys_bAcvTqCnv_irv(DDS_M_CONVERT_BOOL_TO_UINT8(TqSys_bAcvTqCnv_irv_MP));

    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I105(0) */
    Rte_Write_P_CoPt_tqEfcReqCord_nRegReq_CoPt_tqEfcReqCord_nRegReq(copt_tqefcreqcord_nregreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I106(0) */
    Rte_Write_P_EngLim_tqEfcCurMinFuCutSel_EngLim_tqEfcCurMinFuCutSel(englim_tqefccurminfucutsel_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I107(0) */
    Rte_Write_P_EngLim_tqEfcEngCurMin_EngLim_tqEfcEngCurMin(englim_tqefcengcurmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I108(0) */
    Rte_Write_P_EngLim_tqEfcEngLim_EngLim_tqEfcEngLim(englim_tqefcenglim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I109(0) */
    Rte_Write_P_EngLim_tqEfcEngLimCmb_EngLim_tqEfcEngLimCmb(englim_tqefcenglimcmb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I110(0) */
    Rte_Write_P_EngLim_tqEfcLdAdvMinFuCutSel_EngLim_tqEfcLdAdvMinFuCutSel(englim_tqefcldadvminfucutsel_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I111(0) */
    Rte_Write_P_EngLim_tqEfcLdMaxWoutOvb_EngLim_tqEfcLdMaxWoutOvb(englim_tqefcldmaxwoutovb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I112(0) */
    Rte_Write_P_EngLim_tqEfcLdMinAdvMin_EngLim_tqEfcLdMinAdvMin(englim_tqefcldminadvmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I113(0) */
    Rte_Write_P_EngLim_tqEfcMaxEngLimCmb_EngLim_tqEfcMaxEngLimCmb(englim_tqefcmaxenglimcmb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I114(0) */
    Rte_Write_P_EngLim_tqEfcMinEngLimCmb_EngLim_tqEfcMinEngLimCmb(englim_tqefcminenglimcmb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I115(0) */
    Rte_Write_P_TqSys_rLdEngRef_TqSys_rLdEngRef(tqsys_rldengref_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I116(0) */
    Rte_Write_P_TqSys_tqCkEngRealEM_TqSys_tqCkEngRealEM(tqsys_tqckengrealem_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I117(0) */
    Rte_Write_P_TqSys_tqEfcEngWoutAOS_TqSys_tqEfcEngWoutAOS(tqsys_tqefcengwoutaos_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I118(0) */
    Rte_Write_P_EngLim_tqCkEfcFLdLim_EngLim_tqCkEfcFLdLim(englim_tqckefcfldlim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I119(0) */
    Rte_Write_P_EngLim_tqCkEfcLim_EngLim_tqCkEfcLim(englim_tqckefclim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I120(0) */
    Rte_Write_P_EngLim_tqCkEfcSmkLim_EngLim_tqCkEfcSmkLim(englim_tqckefcsmklim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I121(0) */
    Rte_Write_P_EngLim_tqEfcEngCurMax_EngLim_tqEfcEngCurMax(englim_tqefcengcurmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I122(0) */
    Rte_Write_P_EngLim_tqEfcEngProt_EngLim_tqEfcEngProt(englim_tqefcengprot_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I123(0) */
    Rte_Write_P_EngLim_tqEfcLdMaxTrbMax_EngLim_tqEfcLdMaxTrbMax(englim_tqefcldmaxtrbmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I124(0) */
    Rte_Write_P_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(englim_tqefcmaxnreg_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I125(0) */
    Rte_Write_P_EngLim_tqEfcMinCurCutOffTrv_EngLim_tqEfcMinCurCutOffTrv(englim_tqefcmincurcutofftrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I126(0) */
    Rte_Write_P_EngLim_tqEfcMinCurTrv_EngLim_tqEfcMinCurTrv(englim_tqefcmincurtrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I127(0) */
    Rte_Write_P_EngLim_tqEfcPresUsThrMax_EngLim_tqEfcPresUsThrMax(englim_tqefcpresusthrmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I128(0) */
    Rte_Write_P_EngLim_tqEfcRed_EngLim_tqEfcRed(englim_tqefcred_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I129(0) */
    Rte_Write_P_EngLim_tqEfcSfty_EngLim_tqEfcSfty(englim_tqefcsfty_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I130(0) */
    Rte_Write_P_EngLim_tqEfcSyst_EngLim_tqEfcSyst(englim_tqefcsyst_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I131(0) */
    Rte_Write_P_ThMgt_tqEfcLimAntiBoilProt_ThMgt_tqEfcLimAntiBoilProt(thmgt_tqefclimantiboilprot_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I132(0) */
    Rte_Write_P_TqSys_tqCkEfcMinFeas_TqSys_tqCkEfcMinFeas(tqsys_tqckefcminfeas_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I133(0) */
    Rte_Write_P_TqSys_tqCkEfcReq_TqSys_tqCkEfcReq(tqsys_tqckefcreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I134(0) */
    Rte_Write_P_TqSys_tqCkEngReal_TqSys_tqCkEngReal(tqsys_tqckengreal_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I135(0) */
    Rte_Write_P_TqSys_tqEfcAirIdl_TqSys_tqEfcAirIdl(tqsys_tqefcairidl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I136(0) */
    Rte_Write_P_TqSys_tqEfcIdl_TqSys_tqEfcIdl(tqsys_tqefcidl_swc_out);
}
/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_008_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_008_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 copt_tqidcreqcord_nregreq_swc_in;
    Boolean coptst_bmainengstopreq_swc_in;
    UInt8 coptst_steng_swc_in;
    SInt16 englim_tqidcengcur_swc_in;
    SInt16 englim_tqidcengcurgbx_swc_in;
    SInt16 englim_tqidcengcurmax_swc_in;
    SInt16 englim_tqidcengcurmin_swc_in;
    SInt16 englim_tqidcengcurminselc_swc_in;
    SInt16 englim_tqidcenglim_swc_in;
    SInt16 englim_tqidcenglimmax_swc_in;
    SInt16 englim_tqidcengprot_swc_in;
    SInt16 englim_tqidcfldlim_swc_in;
    SInt16 englim_tqidcldmaxtrbmax_swc_in;
    SInt16 englim_tqidcldmaxtrbmaxnoovb_swc_in;
    SInt16 englim_tqidcldminadvmin_swc_in;
    SInt16 englim_tqidcldminadvminselc_swc_in;
    SInt16 englim_tqidcmaxnreg_swc_in;
    SInt16 englim_tqidcpresusthrmax_swc_in;
    SInt16 englim_tqidcred_swc_in;
    SInt16 englim_tqidcsfty_swc_in;
    SInt16 englim_tqidcsmklim_swc_in;
    SInt16 englim_tqidcsyst_swc_in;
    UInt32 eom_tiengstop_swc_in;
    UInt16 ext_neng_swc_in;
    UInt16 ext_pairextmes_swc_in;
    SInt8 ext_tair_swc_in;
    SInt16 ext_tcomes_swc_in;
    UInt8 ext_titdc_swc_in;
    SInt16 ext_toilmes_swc_in;
    SInt16 idlsys_tqidcairidl_swc_in;
    SInt16 injsys_tqidcminfeas_swc_in;
    SInt16 tqcmp_tqaltloss_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqsys_btypfu_swc_in;
    SInt16 tqlimem_tqlimemtrv_swc_in;
    UInt16 thmgt_tqidclimreq_swc_in;
    SInt16 tqcmp_tqsumlosscmpwoutcnv_swc_in;
    SInt16 tqest_tqidcestim_swc_in;
    SInt16 tqsys_tqckenglimcord_swc_in;
    SInt16 tqsys_tqckidlcmn_swc_in;
    SInt16 tqsys_tqidcreq_swc_in;
    UInt16 treattdc_nckfil_swc_in;
    SInt16 treattdc_nckgrdfil_swc_in;
    UInt16 veh_spdveh_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 copt_tqefcreqcord_nregreq_swc_out;
    SInt16 englim_tqefccurminfucutsel_swc_out;
    SInt16 englim_tqefcengcurmin_swc_out;
    SInt16 englim_tqefcenglim_swc_out;
    SInt16 englim_tqefcenglimcmb_swc_out;
    SInt16 englim_tqefcldadvminfucutsel_swc_out;
    SInt16 englim_tqefcldmaxwoutovb_swc_out;
    SInt16 englim_tqefcldminadvmin_swc_out;
    SInt16 englim_tqefcmaxenglimcmb_swc_out;
    SInt16 englim_tqefcminenglimcmb_swc_out;
    UInt8 tqsys_rldengref_swc_out;
    SInt16 tqsys_tqckengrealem_swc_out;
    SInt16 tqsys_tqefcengwoutaos_swc_out;
    SInt16 englim_tqckefcfldlim_swc_out;
    SInt16 englim_tqckefclim_swc_out;
    SInt16 englim_tqckefcsmklim_swc_out;
    SInt16 englim_tqefcengcurmax_swc_out;
    SInt16 englim_tqefcengprot_swc_out;
    SInt16 englim_tqefcldmaxtrbmax_swc_out;
    SInt16 englim_tqefcmaxnreg_swc_out;
    SInt16 englim_tqefcmincurcutofftrv_swc_out;
    SInt16 englim_tqefcmincurtrv_swc_out;
    SInt16 englim_tqefcpresusthrmax_swc_out;
    SInt16 englim_tqefcred_swc_out;
    SInt16 englim_tqefcsfty_swc_out;
    SInt16 englim_tqefcsyst_swc_out;
    SInt16 thmgt_tqefclimantiboilprot_swc_out;
    SInt16 tqsys_tqckefcminfeas_swc_out;
    SInt16 tqsys_tqckefcreq_swc_out;
    SInt16 tqsys_tqckengreal_swc_out;
    SInt16 tqsys_tqefcairidl_swc_out;
    SInt16 tqsys_tqefcidl_swc_out;

    UInt32 cotq_current_time;
    UInt32 cotq_delta_time;

    if ((UInt32)DDS_FALSE == (UInt32)COTQ_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I160(0) */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);

        COTQ_Func_Call(ext_neng_swc_in,
                        &TqSys_bAcvTqCnv_irv_MP);

        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.IRV1(0) */
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        Rte_IrvWrite_RE_CoTq_008_TEV_TqSys_bAcvTqCnv_irv(DDS_M_CONVERT_BOOL_TO_UINT8(TqSys_bAcvTqCnv_irv_MP));


        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I007(0) */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I100(0) */
        Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&tqcmp_tqaltloss_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I101(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I102(0) */
        Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&tqlimem_tqlimemtrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I137(0) */
        Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(&copt_tqidcreqcord_nregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I138(0) */
        Rte_Read_R_CoPTSt_bMainEngStopReq_CoPTSt_bMainEngStopReq(&coptst_bmainengstopreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I139(0) */
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I140(0) */
        Rte_Read_R_EngLim_tqIdcEngCur_EngLim_tqIdcEngCur(&englim_tqidcengcur_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I141(0) */
        Rte_Read_R_EngLim_tqIdcEngCurGBx_EngLim_tqIdcEngCurGBx(&englim_tqidcengcurgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I142(0) */
        Rte_Read_R_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax(&englim_tqidcengcurmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I143(0) */
        Rte_Read_R_EngLim_tqIdcEngCurMin_EngLim_tqIdcEngCurMin(&englim_tqidcengcurmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I144(0) */
        Rte_Read_R_EngLim_tqIdcEngCurMinSelc_EngLim_tqIdcEngCurMinSelc(&englim_tqidcengcurminselc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I145(0) */
        Rte_Read_R_EngLim_tqIdcEngLim_EngLim_tqIdcEngLim(&englim_tqidcenglim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I146(0) */
        Rte_Read_R_EngLim_tqIdcEngLimMax_EngLim_tqIdcEngLimMax(&englim_tqidcenglimmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I147(0) */
        Rte_Read_R_EngLim_tqIdcEngProt_EngLim_tqIdcEngProt(&englim_tqidcengprot_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I148(0) */
        Rte_Read_R_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(&englim_tqidcfldlim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I149(0) */
        Rte_Read_R_EngLim_tqIdcLdMaxTrbMax_EngLim_tqIdcLdMaxTrbMax(&englim_tqidcldmaxtrbmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I150(0) */
        Rte_Read_R_EngLim_tqIdcLdMaxTrbMaxNoOvb_EngLim_tqIdcLdMaxTrbMaxNoOvb(&englim_tqidcldmaxtrbmaxnoovb_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I151(0) */
        Rte_Read_R_EngLim_tqIdcLdMinAdvMin_EngLim_tqIdcLdMinAdvMin(&englim_tqidcldminadvmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I152(0) */
        Rte_Read_R_EngLim_tqIdcLdMinAdvMinSelc_EngLim_tqIdcLdMinAdvMinSelc(&englim_tqidcldminadvminselc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I153(0) */
        Rte_Read_R_EngLim_tqIdcMaxNReg_EngLim_tqIdcMaxNReg(&englim_tqidcmaxnreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I154(0) */
        Rte_Read_R_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax(&englim_tqidcpresusthrmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I155(0) */
        Rte_Read_R_EngLim_tqIdcRed_EngLim_tqIdcRed(&englim_tqidcred_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I156(0) */
        Rte_Read_R_EngLim_tqIdcSfty_EngLim_tqIdcSfty(&englim_tqidcsfty_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I157(0) */
        Rte_Read_R_EngLim_tqIdcSmkLim_EngLim_tqIdcSmkLim(&englim_tqidcsmklim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I158(0) */
        Rte_Read_R_EngLim_tqIdcSyst_EngLim_tqIdcSyst(&englim_tqidcsyst_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I159(0) */
        Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&eom_tiengstop_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I160(0) */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I161(0) */
        Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&ext_pairextmes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I162(0) */
        Rte_Read_R_Ext_tAir_Ext_tAir(&ext_tair_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I163(0) */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);

        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I164(0) */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);

        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I165(0) */
        Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&ext_toilmes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I166(0) */
        Rte_Read_R_IdlSys_tqIdcAirIdl_IdlSys_tqIdcAirIdl(&idlsys_tqidcairidl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I167(0) */
        Rte_Read_R_InjSys_tqIdcMinFeas_InjSys_tqIdcMinFeas(&injsys_tqidcminfeas_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I168(0) */
        Rte_Read_R_ThMgt_tqIdcLimReq_ThMgt_tqIdcLimReq(&thmgt_tqidclimreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I169(0) */
        Rte_Read_R_TqCmp_tqSumLossCmpWoutCnv_TqCmp_tqSumLossCmpWoutCnv(&tqcmp_tqsumlosscmpwoutcnv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I170(0) */
        Rte_Read_R_TqEst_tqIdcEstim_TqEst_tqIdcEstim(&tqest_tqidcestim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I173(0) */
        Rte_Read_R_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(&tqsys_tqckenglimcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I174(0) */
        Rte_Read_R_TqSys_tqCkIdlCmn_TqSys_tqCkIdlCmn(&tqsys_tqckidlcmn_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I175(0) */
        Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq(&tqsys_tqidcreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I176(0) */
        Rte_Read_R_TreatTDC_nCkFil_TreatTDC_nCkFil(&treattdc_nckfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I177(0) */
        Rte_Read_R_TreatTDC_nCkGrdFil_TreatTDC_nCkGrdFil(&treattdc_nckgrdfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I178(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);


        if((UInt32)TqSys_bAcvTqCnv_irv_MP == (UInt32)DDS_FALSE)
        {
            cotq_current_time = DDS_COTQ_1MS_U32_TIME;
            cotq_delta_time = cotq_current_time - cotq_prev_time;
            ext_titdc_swc_in = (UInt8)DDS_M_MIN(cotq_delta_time, (2 * COTQ_SCHED));
            cotq_prev_time = cotq_current_time;

            COTQ_Sync_Engine_Speed( copt_tqidcreqcord_nregreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    DDS_M_CONVERT_BOOL_TO_UINT8(coptst_bmainengstopreq_swc_in),
                                    coptst_steng_swc_in,
                                    englim_tqidcengcur_swc_in,
                                    englim_tqidcenglimmax_swc_in,
                                    englim_tqidcfldlim_swc_in,
                                    englim_tqidcldmaxtrbmax_swc_in,
                                    englim_tqidcldminadvmin_swc_in,
                                    englim_tqidcldminadvminselc_swc_in,
                                    englim_tqidcmaxnreg_swc_in,
                                    englim_tqidcpresusthrmax_swc_in,
                                    englim_tqidcengcurgbx_swc_in,
                                    eom_tiengstop_swc_in,
                                    ext_tcomes_swc_in,
                                    ext_titdc_swc_in,
                                    ext_toilmes_swc_in,
                                    injsys_tqidcminfeas_swc_in,
                                    tqcmp_tqaltloss_swc_in,
                                    tqcmp_tqsumlosscmp_swc_in,
                                    tqcmp_tqsumlosscmpwoutcnv_swc_in,
                                    tqest_tqidcestim_swc_in,
                                    tqlimem_tqlimemtrv_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    tqsys_tqckenglimcord_swc_in,
                                    treattdc_nckfil_swc_in,
                                    treattdc_nckgrdfil_swc_in,
                                    veh_spdveh_swc_in,
                                    &copt_tqefcreqcord_nregreq_swc_out,
                                    &englim_tqefcenglim_swc_out,
                                    &englim_tqefcenglimcmb_swc_out,
                                    &englim_tqefcldadvminfucutsel_swc_out,
                                    &englim_tqefcldminadvmin_swc_out,
                                    &englim_tqefcmaxenglimcmb_swc_out,
                                    &englim_tqefcmaxnreg_swc_out,
                                    &tqsys_tqckefcminfeas_swc_out,
                                    &tqsys_tqckengreal_swc_out,
                                    &tqsys_tqckengrealem_swc_out,
                                    &tqsys_tqefcengwoutaos_swc_out );

            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I105(0) */
            Rte_Write_P_CoPt_tqEfcReqCord_nRegReq_CoPt_tqEfcReqCord_nRegReq(copt_tqefcreqcord_nregreq_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I108(0) */
            Rte_Write_P_EngLim_tqEfcEngLim_EngLim_tqEfcEngLim(englim_tqefcenglim_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I109(0) */
            Rte_Write_P_EngLim_tqEfcEngLimCmb_EngLim_tqEfcEngLimCmb(englim_tqefcenglimcmb_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I110(0) */
            Rte_Write_P_EngLim_tqEfcLdAdvMinFuCutSel_EngLim_tqEfcLdAdvMinFuCutSel(englim_tqefcldadvminfucutsel_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I112(0) */
            Rte_Write_P_EngLim_tqEfcLdMinAdvMin_EngLim_tqEfcLdMinAdvMin(englim_tqefcldminadvmin_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I113(0) */
            Rte_Write_P_EngLim_tqEfcMaxEngLimCmb_EngLim_tqEfcMaxEngLimCmb(englim_tqefcmaxenglimcmb_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I116(0) */
            Rte_Write_P_TqSys_tqCkEngRealEM_TqSys_tqCkEngRealEM(tqsys_tqckengrealem_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I117(0) */
            Rte_Write_P_TqSys_tqEfcEngWoutAOS_TqSys_tqEfcEngWoutAOS(tqsys_tqefcengwoutaos_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I124(0) */
            Rte_Write_P_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(englim_tqefcmaxnreg_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I132(0) */
            Rte_Write_P_TqSys_tqCkEfcMinFeas_TqSys_tqCkEfcMinFeas(tqsys_tqckefcminfeas_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I134(0) */
            Rte_Write_P_TqSys_tqCkEngReal_TqSys_tqCkEngReal(tqsys_tqckengreal_swc_out);

        /* IRV OUTPUT */
        }
        else
        {


        }

        COTQ_Conversion_10ms(   /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(coptst_bmainengstopreq_swc_in),
                                coptst_steng_swc_in,
                                englim_tqidcengcurmax_swc_in,
                                englim_tqidcengcurmin_swc_in,
                                englim_tqidcengcurminselc_swc_in,
                                englim_tqidcenglim_swc_in,
                                englim_tqidcengprot_swc_in,
                                englim_tqidcfldlim_swc_in,
                                englim_tqidcldmaxtrbmax_swc_in,
                                englim_tqidcldmaxtrbmaxnoovb_swc_in,
                                englim_tqidcpresusthrmax_swc_in,
                                englim_tqidcred_swc_in,
                                englim_tqidcsfty_swc_in,
                                englim_tqidcsmklim_swc_in,
                                englim_tqidcsyst_swc_in,
                                ext_pairextmes_swc_in,
                                ext_tair_swc_in,
                                idlsys_tqidcairidl_swc_in,
                                thmgt_tqidclimreq_swc_in,
                                tqcmp_tqaltloss_swc_in,
                                tqcmp_tqsumlosscmp_swc_in,
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                tqsys_tqckidlcmn_swc_in,
                                tqsys_tqidcreq_swc_in,
                                &englim_tqckefcfldlim_swc_out,
                                &englim_tqckefclim_swc_out,
                                &englim_tqckefcsmklim_swc_out,
                                &englim_tqefccurminfucutsel_swc_out,
                                &englim_tqefcengcurmax_swc_out,
                                &englim_tqefcengcurmin_swc_out,
                                &englim_tqefcengprot_swc_out,
                                &englim_tqefcldmaxtrbmax_swc_out,
                                &englim_tqefcldmaxwoutovb_swc_out,
                                &englim_tqefcmincurcutofftrv_swc_out,
                                &englim_tqefcmincurtrv_swc_out,
                                &englim_tqefcminenglimcmb_swc_out,
                                &englim_tqefcpresusthrmax_swc_out,
                                &englim_tqefcred_swc_out,
                                &englim_tqefcsfty_swc_out,
                                &englim_tqefcsyst_swc_out,
                                &thmgt_tqefclimantiboilprot_swc_out,
                                &tqsys_rldengref_swc_out,
                                &tqsys_tqckefcreq_swc_out,
                                &tqsys_tqefcairidl_swc_out,
                                &tqsys_tqefcidl_swc_out );

    }
    else
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I105(0) */
        Rte_Write_P_CoPt_tqEfcReqCord_nRegReq_CoPt_tqEfcReqCord_nRegReq(CoPt_tqEfcReqCord_nRegReq_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I108(0) */
        Rte_Write_P_EngLim_tqEfcEngLim_EngLim_tqEfcEngLim(EngLim_tqEfcEngLim_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I109(0) */
        Rte_Write_P_EngLim_tqEfcEngLimCmb_EngLim_tqEfcEngLimCmb(EngLim_tqEfcEngLimCmb_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I110(0) */
        Rte_Write_P_EngLim_tqEfcLdAdvMinFuCutSel_EngLim_tqEfcLdAdvMinFuCutSel(EngLim_tqEfcLdAdvMinFuCutSel_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I112(0) */
        Rte_Write_P_EngLim_tqEfcLdMinAdvMin_EngLim_tqEfcLdMinAdvMin(EngLim_tqEfcLdMinAdvMin_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I113(0) */
        Rte_Write_P_EngLim_tqEfcMaxEngLimCmb_EngLim_tqEfcMaxEngLimCmb(EngLim_tqEfcMaxEngLimCmb_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I116(0) */
        Rte_Write_P_TqSys_tqCkEngRealEM_TqSys_tqCkEngRealEM(TqSys_tqCkEngRealEM_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I117(0) */
        Rte_Write_P_TqSys_tqEfcEngWoutAOS_TqSys_tqEfcEngWoutAOS(TqSys_tqEfcEngWoutAOS_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I124(0) */
        Rte_Write_P_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(EngLim_tqEfcMaxNReg_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I132(0) */
        Rte_Write_P_TqSys_tqCkEfcMinFeas_TqSys_tqCkEfcMinFeas(TqSys_tqCkEfcMinFeas_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I134(0) */
        Rte_Write_P_TqSys_tqCkEngReal_TqSys_tqCkEngReal(TqSys_tqCkEngReal_B);


        englim_tqefccurminfucutsel_swc_out = EngLim_tqEfcCurMinFuCutSel_B;
        englim_tqefcengcurmin_swc_out = EngLim_tqEfcEngCurMin_B;
        englim_tqefcldmaxwoutovb_swc_out = EngLim_tqEfcLdMaxWoutOvb_B;
        englim_tqefcminenglimcmb_swc_out = EngLim_tqEfcMinEngLimCmb_B;
        tqsys_rldengref_swc_out = TqSys_rLdEngRef_B;
        englim_tqckefcfldlim_swc_out = EngLim_tqCkEfcFLdLim_B;
        englim_tqckefclim_swc_out = EngLim_tqCkEfcLim_B;
        englim_tqckefcsmklim_swc_out = EngLim_tqCkEfcSmkLim_B;
        englim_tqefcengcurmax_swc_out = EngLim_tqEfcEngCurMax_B;
        englim_tqefcengprot_swc_out = EngLim_tqEfcEngProt_B;
        englim_tqefcldmaxtrbmax_swc_out = EngLim_tqEfcLdMaxTrbMax_B;
        englim_tqefcmincurcutofftrv_swc_out = EngLim_tqEfcMinCurCutOffTrv_B;
        englim_tqefcmincurtrv_swc_out = EngLim_tqEfcMinCurTrv_B;
        englim_tqefcpresusthrmax_swc_out = EngLim_tqEfcPresUsThrMax_B;
        englim_tqefcred_swc_out = EngLim_tqEfcRed_B;
        englim_tqefcsfty_swc_out = EngLim_tqEfcSfty_B;
        englim_tqefcsyst_swc_out = EngLim_tqEfcSyst_B;
        thmgt_tqefclimantiboilprot_swc_out = ThMgt_tqEfcLimAntiBoilProt_B;
        tqsys_tqckefcreq_swc_out = TqSys_tqCkEfcReq_B;
        tqsys_tqefcairidl_swc_out = TqSys_tqEfcAirIdl_B;
        tqsys_tqefcidl_swc_out = TqSys_tqEfcIdl_B;
    }

    /* OUTPUT */

    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I106(0) */
    Rte_Write_P_EngLim_tqEfcCurMinFuCutSel_EngLim_tqEfcCurMinFuCutSel(englim_tqefccurminfucutsel_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I107(0) */
    Rte_Write_P_EngLim_tqEfcEngCurMin_EngLim_tqEfcEngCurMin(englim_tqefcengcurmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I111(0) */
    Rte_Write_P_EngLim_tqEfcLdMaxWoutOvb_EngLim_tqEfcLdMaxWoutOvb(englim_tqefcldmaxwoutovb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I114(0) */
    Rte_Write_P_EngLim_tqEfcMinEngLimCmb_EngLim_tqEfcMinEngLimCmb(englim_tqefcminenglimcmb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I115(0) */
    Rte_Write_P_TqSys_rLdEngRef_TqSys_rLdEngRef(tqsys_rldengref_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I118(0) */
    Rte_Write_P_EngLim_tqCkEfcFLdLim_EngLim_tqCkEfcFLdLim(englim_tqckefcfldlim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I119(0) */
    Rte_Write_P_EngLim_tqCkEfcLim_EngLim_tqCkEfcLim(englim_tqckefclim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I120(0) */
    Rte_Write_P_EngLim_tqCkEfcSmkLim_EngLim_tqCkEfcSmkLim(englim_tqckefcsmklim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I121(0) */
    Rte_Write_P_EngLim_tqEfcEngCurMax_EngLim_tqEfcEngCurMax(englim_tqefcengcurmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I122(0) */
    Rte_Write_P_EngLim_tqEfcEngProt_EngLim_tqEfcEngProt(englim_tqefcengprot_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I123(0) */
    Rte_Write_P_EngLim_tqEfcLdMaxTrbMax_EngLim_tqEfcLdMaxTrbMax(englim_tqefcldmaxtrbmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I125(0) */
    Rte_Write_P_EngLim_tqEfcMinCurCutOffTrv_EngLim_tqEfcMinCurCutOffTrv(englim_tqefcmincurcutofftrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I126(0) */
    Rte_Write_P_EngLim_tqEfcMinCurTrv_EngLim_tqEfcMinCurTrv(englim_tqefcmincurtrv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I127(0) */
    Rte_Write_P_EngLim_tqEfcPresUsThrMax_EngLim_tqEfcPresUsThrMax(englim_tqefcpresusthrmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I128(0) */
    Rte_Write_P_EngLim_tqEfcRed_EngLim_tqEfcRed(englim_tqefcred_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I129(0) */
    Rte_Write_P_EngLim_tqEfcSfty_EngLim_tqEfcSfty(englim_tqefcsfty_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I130(0) */
    Rte_Write_P_EngLim_tqEfcSyst_EngLim_tqEfcSyst(englim_tqefcsyst_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I131(0) */
    Rte_Write_P_ThMgt_tqEfcLimAntiBoilProt_ThMgt_tqEfcLimAntiBoilProt(thmgt_tqefclimantiboilprot_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I133(0) */
    Rte_Write_P_TqSys_tqCkEfcReq_TqSys_tqCkEfcReq(tqsys_tqckefcreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I135(0) */
    Rte_Write_P_TqSys_tqEfcAirIdl_TqSys_tqEfcAirIdl(tqsys_tqefcairidl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I136(0) */
    Rte_Write_P_TqSys_tqEfcIdl_TqSys_tqEfcIdl(tqsys_tqefcidl_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_009_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_009_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    UInt8 copt_bacvnregreqbuf_swc_out;
    UInt8 copt_bdeaccllbuf_swc_out;
    UInt8 copt_binjcutdynauth1_swc_out;
    UInt8 copt_binjcutdynauth2_swc_out;
    UInt8 copt_bsipbuf_swc_out;
    SInt8 copt_notargearcordbuf_swc_out;
    UInt16 copt_ntarbuf_swc_out;
    SInt16 copt_tqidccordlimbuf_tqgbx_swc_out;
    SInt16 copt_tqidcmaxgbxbuf_swc_out;
    SInt16 copt_tqmaxgbx_nregbuf_swc_out;


    COTQ_Tempo_Data_Synch_Init( &copt_bacvnregreqbuf_swc_out,
                                &copt_bdeaccllbuf_swc_out,
                                &copt_binjcutdynauth1_swc_out,
                                &copt_binjcutdynauth2_swc_out,
                                &copt_bsipbuf_swc_out,
                                &copt_notargearcordbuf_swc_out,
                                &copt_ntarbuf_swc_out,
                                &copt_tqidccordlimbuf_tqgbx_swc_out,
                                &copt_tqidcmaxgbxbuf_swc_out,
                                &copt_tqmaxgbx_nregbuf_swc_out);


    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I181(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bInjCutDynAuth1_CoPt_bInjCutDynAuth1(DDS_M_CONVERT_UINT8_TO_BOOL(copt_binjcutdynauth1_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I182(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bInjCutDynAuth2_CoPt_bInjCutDynAuth2(DDS_M_CONVERT_UINT8_TO_BOOL(copt_binjcutdynauth2_swc_out));

    /* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.3.2 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_COTQ_bSynchCoherFlag_COTQ_bSynchCoherFlag(DDS_M_CONVERT_UINT8_TO_BOOL(DDS_FALSE));

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I179(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bAcvNRegReqBuf_CoPt_bAcvNRegReqBuf(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bacvnregreqbuf_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I180(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bDeacCllBuf_CoPt_bDeacCllBuf(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bdeaccllbuf_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I183(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bSIPBuf_CoPt_bSIPBuf(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bsipbuf_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I184(0) */
    Rte_Write_P_CoPt_noTarGearCordBuf_CoPt_noTarGearCordBuf(copt_notargearcordbuf_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I185(0) */
    Rte_Write_P_CoPt_nTarBuf_CoPt_nTarBuf(copt_ntarbuf_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I186(0) */
    Rte_Write_P_CoPt_tqIdcCordLimBuf_tqGBx_CoPt_tqIdcCordLimBuf_tqGBx(copt_tqidccordlimbuf_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I187(0) */
    Rte_Write_P_CoPt_tqIdcMaxGBxBuf_CoPt_tqIdcMaxGBxBuf(copt_tqidcmaxgbxbuf_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I188(0) */
    Rte_Write_P_CoPt_tqMaxGBx_nRegBuf_CoPt_tqMaxGBx_nRegBuf(copt_tqmaxgbx_nregbuf_swc_out);

    /* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.3.2 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_COTQ_bSynchCoherFlag_COTQ_bSynchCoherFlag(DDS_M_CONVERT_UINT8_TO_BOOL(DDS_TRUE));
}
/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_010_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_010_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    Boolean copt_bacvnregreq_swc_in;
    Boolean copt_bdeaccll_swc_in;
    Boolean copt_bsip_swc_in;
    SInt16 copt_tqefccordlim_tqgbx_swc_in;
    SInt16 copt_tqidccordlim_tqgbx_swc_in;
    SInt16 copt_tqidcmaxgbx_swc_in;
    SInt16 copt_tqmaxgbx_nreg_swc_in;
    SInt16 tqlimem_tqlimem_swc_in;
    SInt16 tqsys_tqckefcfil_swc_in;
    SInt8 copt_notargearcordit_swc_in;
    UInt16 copt_ntar_swc_in;
    Boolean tqsys_btypfu_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 copt_bacvnregreqbuf_swc_out;
    UInt8 copt_bdeaccllbuf_swc_out;
    UInt8 copt_binjcutdynauth1_swc_out;
    UInt8 copt_binjcutdynauth2_swc_out;
    UInt8 copt_bsipbuf_swc_out;
    SInt8 copt_notargearcordbuf_swc_out;
    UInt16 copt_ntarbuf_swc_out;
    SInt16 copt_tqidccordlimbuf_tqgbx_swc_out;
    SInt16 copt_tqidcmaxgbxbuf_swc_out;
    SInt16 copt_tqmaxgbx_nregbuf_swc_out;
    SInt16 tqcmp_tqsumlosscmp_swc_in;

    if ((UInt32)DDS_FALSE == (UInt32)COTQ_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I056(0) */
        Rte_Read_R_TqLimEM_tqLimEM_TqLimEM_tqLimEM(&tqlimem_tqlimem_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I078(0) */
        Rte_Read_R_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(&tqsys_tqckefcfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I017(0) */
        Rte_Read_R_CoPt_tqEfcCordLim_tqGBx_CoPt_tqEfcCordLim_tqGBx(&copt_tqefccordlim_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I101(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I007(0) */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);

        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I015(0) */
        Rte_Read_R_CoPt_bDeacCll_CoPt_bDeacCll(&copt_bdeaccll_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I086(0) */
        Rte_Read_R_CoPt_tqIdcCordLim_tqGBx_CoPt_tqIdcCordLim_tqGBx(&copt_tqidccordlim_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I087(0) */
        Rte_Read_R_CoPt_tqIdcMaxGBx_CoPt_tqIdcMaxGBx(&copt_tqidcmaxgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I189(0) */
        Rte_Read_R_CoPt_bAcvNRegReq_CoPt_bAcvNRegReq(&copt_bacvnregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I191(0) */
        Rte_Read_R_CoPt_bSIP_CoPt_bSIP(&copt_bsip_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I192(0) */
        Rte_Read_R_CoPt_noTarGearCordIt_CoPt_noTarGearCordIt(&copt_notargearcordit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I193(0) */
        Rte_Read_R_CoPt_nTar_CoPt_nTar(&copt_ntar_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I196(0) */
        Rte_Read_R_CoPt_tqMaxGBx_nReg_CoPt_tqMaxGBx_nReg(&copt_tqmaxgbx_nreg_swc_in);

        COTQ_Tempo_Data_Synch(  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(copt_bacvnregreq_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(copt_bdeaccll_swc_in),
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(copt_bsip_swc_in),
                                copt_notargearcordit_swc_in,
                                copt_ntar_swc_in, /* bin2 */
                                copt_tqefccordlim_tqgbx_swc_in, /* bin4 */
                                copt_tqidccordlim_tqgbx_swc_in, /* bin4 */
                                copt_tqidcmaxgbx_swc_in, /* bin4 */
                                copt_tqmaxgbx_nreg_swc_in, /* bin4 */
                                tqcmp_tqsumlosscmp_swc_in, /* bin4 */
                                tqlimem_tqlimem_swc_in, /* bin4 */
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                tqsys_tqckefcfil_swc_in, /* bin4 */
                                &copt_bacvnregreqbuf_swc_out,
                                &copt_bdeaccllbuf_swc_out,
                                &copt_binjcutdynauth1_swc_out,
                                &copt_binjcutdynauth2_swc_out,
                                &copt_bsipbuf_swc_out,
                                &copt_notargearcordbuf_swc_out, /* bin0 */
                                &copt_ntarbuf_swc_out, /* bin2 */
                                &copt_tqidccordlimbuf_tqgbx_swc_out, /* bin4 */
                                &copt_tqidcmaxgbxbuf_swc_out, /* bin4 */
                                &copt_tqmaxgbx_nregbuf_swc_out /* bin4 */);



        /* IRV OUTPUT */
    }
    else
    {

        copt_bacvnregreqbuf_swc_out = CoPt_bAcvNRegReqBuf_B;
        copt_bdeaccllbuf_swc_out = CoPt_bDeacCllBuf_B;
        copt_binjcutdynauth1_swc_out = CoPt_bInjCutDynAuth1_B;
        copt_binjcutdynauth2_swc_out = CoPt_bInjCutDynAuth2_B;
        copt_bsipbuf_swc_out = CoPt_bSIPBuf_B;
        copt_notargearcordbuf_swc_out = CoPt_noTarGearCordBuf_B;
        copt_ntarbuf_swc_out = CoPt_nTarBuf_B;
        copt_tqidccordlimbuf_tqgbx_swc_out = CoPt_tqIdcCordLimBuf_tqGBx_B;
        copt_tqidcmaxgbxbuf_swc_out = CoPt_tqIdcMaxGBxBuf_B;
        copt_tqmaxgbx_nregbuf_swc_out = CoPt_tqMaxGBx_nRegBuf_B;

    }

    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I181(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bInjCutDynAuth1_CoPt_bInjCutDynAuth1(DDS_M_CONVERT_UINT8_TO_BOOL(copt_binjcutdynauth1_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I182(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bInjCutDynAuth2_CoPt_bInjCutDynAuth2(DDS_M_CONVERT_UINT8_TO_BOOL(copt_binjcutdynauth2_swc_out));

    /* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.3.2 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_COTQ_bSynchCoherFlag_COTQ_bSynchCoherFlag(DDS_M_CONVERT_UINT8_TO_BOOL(DDS_FALSE));

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I179(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bAcvNRegReqBuf_CoPt_bAcvNRegReqBuf(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bacvnregreqbuf_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I180(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bDeacCllBuf_CoPt_bDeacCllBuf(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bdeaccllbuf_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I183(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bSIPBuf_CoPt_bSIPBuf(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bsipbuf_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I184(0) */
    Rte_Write_P_CoPt_noTarGearCordBuf_CoPt_noTarGearCordBuf(copt_notargearcordbuf_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I185(0) */
    Rte_Write_P_CoPt_nTarBuf_CoPt_nTarBuf(copt_ntarbuf_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I186(0) */
    Rte_Write_P_CoPt_tqIdcCordLimBuf_tqGBx_CoPt_tqIdcCordLimBuf_tqGBx(copt_tqidccordlimbuf_tqgbx_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I187(0) */
    Rte_Write_P_CoPt_tqIdcMaxGBxBuf_CoPt_tqIdcMaxGBxBuf(copt_tqidcmaxgbxbuf_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I188(0) */
    Rte_Write_P_CoPt_tqMaxGBx_nRegBuf_CoPt_tqMaxGBx_nRegBuf(copt_tqmaxgbx_nregbuf_swc_out);

    /* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.3.2 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_COTQ_bSynchCoherFlag_COTQ_bSynchCoherFlag(DDS_M_CONVERT_UINT8_TO_BOOL(DDS_TRUE));

}

/*******************************************************************************
*
*  Runnable Name    : RE_CoTq_011_DRE
*  Event            : EV_CoTq_011_DRE
*  Description      :
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoTq_011_DRE(void)
{
    /* INPUT */
    /* SWC IN */

    Boolean coptst_bmainengstopreq_swc_in;
    SInt16 copt_tqidcreqcord_nregreq_swc_in;
    SInt16 englim_tqidcengcur_swc_in;
    SInt16 englim_tqidcenglimmax_swc_in;
    SInt16 englim_tqidcfldlim_swc_in;
    SInt16 englim_tqidcldmaxtrbmax_swc_in;
    SInt16 englim_tqidcldminadvmin_swc_in;
    SInt16 englim_tqidcldminadvminselc_swc_in;
    SInt16 englim_tqidcmaxnreg_swc_in;
    SInt16 englim_tqidcengcurgbx_swc_in;
    SInt16 englim_tqidcpresusthrmax_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 ext_toilmes_swc_in;
    SInt16 injsys_tqidcminfeas_swc_in;
    UInt8 ext_titdc_swc_in;
    UInt32 eom_tiengstop_swc_in;
    UInt8 coptst_steng_swc_in;
    SInt16 tqcmp_tqaltloss_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqsys_btypfu_swc_in;
    SInt16 tqlimem_tqlimemtrv_swc_in;
    SInt16 tqcmp_tqsumlosscmpwoutcnv_swc_in;
    SInt16 tqest_tqidcestim_swc_in;
    SInt16 tqsys_tqckenglimcord_swc_in;
    UInt16 treattdc_nckfil_swc_in;
    SInt16 treattdc_nckgrdfil_swc_in;
    UInt16 veh_spdveh_swc_in;

    /* IRV IN */

    Boolean tqsys_bacvtqcnv_irv_in;


    SInt16 copt_tqefcreqcord_nregreq_swc_out;
    SInt16 englim_tqefcenglim_swc_out;
    SInt16 englim_tqefcenglimcmb_swc_out;
    SInt16 englim_tqefcldadvminfucutsel_swc_out;
    SInt16 englim_tqefcldminadvmin_swc_out;
    SInt16 englim_tqefcmaxenglimcmb_swc_out;
    SInt16 englim_tqefcmaxnreg_swc_out;
    SInt16 tqsys_tqckefcminfeas_swc_out;
    SInt16 tqsys_tqckengreal_swc_out;
    SInt16 tqsys_tqckengrealem_swc_out;
    SInt16 tqsys_tqefcengwoutaos_swc_out;


    if ((UInt32)DDS_FALSE == (UInt32)COTQ_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.IRV1(0) */
        tqsys_bacvtqcnv_irv_in = Rte_IrvRead_RE_CoTq_011_DRE_TqSys_bAcvTqCnv_irv();

        if((UInt32)tqsys_bacvtqcnv_irv_in != (UInt32)DDS_FALSE)
        {
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I007(0) */
            Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I100(0) */
            Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&tqcmp_tqaltloss_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I101(0) */
            Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I137(0) */
            Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(&copt_tqidcreqcord_nregreq_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I138(0) */
            Rte_Read_R_CoPTSt_bMainEngStopReq_CoPTSt_bMainEngStopReq(&coptst_bmainengstopreq_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I139(0) */
            Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I140(0) */
            Rte_Read_R_EngLim_tqIdcEngCur_EngLim_tqIdcEngCur(&englim_tqidcengcur_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I141(0) */
            Rte_Read_R_EngLim_tqIdcEngCurGBx_EngLim_tqIdcEngCurGBx(&englim_tqidcengcurgbx_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I146(0) */
            Rte_Read_R_EngLim_tqIdcEngLimMax_EngLim_tqIdcEngLimMax(&englim_tqidcenglimmax_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I148(0) */
            Rte_Read_R_EngLim_tqIdcFLdLim_EngLim_tqIdcFLdLim(&englim_tqidcfldlim_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I149(0) */
            Rte_Read_R_EngLim_tqIdcLdMaxTrbMax_EngLim_tqIdcLdMaxTrbMax(&englim_tqidcldmaxtrbmax_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I151(0) */
            Rte_Read_R_EngLim_tqIdcLdMinAdvMin_EngLim_tqIdcLdMinAdvMin(&englim_tqidcldminadvmin_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I152(0) */
            Rte_Read_R_EngLim_tqIdcLdMinAdvMinSelc_EngLim_tqIdcLdMinAdvMinSelc(&englim_tqidcldminadvminselc_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I153(0) */
            Rte_Read_R_EngLim_tqIdcMaxNReg_EngLim_tqIdcMaxNReg(&englim_tqidcmaxnreg_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I154(0) */
            Rte_Read_R_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax(&englim_tqidcpresusthrmax_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I159(0) */
            Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&eom_tiengstop_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I163(0) */
            Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I164(0) */
            Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I165(0) */
            Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&ext_toilmes_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I167(0) */
            Rte_Read_R_InjSys_tqIdcMinFeas_InjSys_tqIdcMinFeas(&injsys_tqidcminfeas_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I102(0) */
            Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&tqlimem_tqlimemtrv_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I178(0) */
            Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I177(0) */
            Rte_Read_R_TreatTDC_nCkGrdFil_TreatTDC_nCkGrdFil(&treattdc_nckgrdfil_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I176(0) */
            Rte_Read_R_TreatTDC_nCkFil_TreatTDC_nCkFil(&treattdc_nckfil_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I173(0) */
            Rte_Read_R_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(&tqsys_tqckenglimcord_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I170(0) */
            Rte_Read_R_TqEst_tqIdcEstim_TqEst_tqIdcEstim(&tqest_tqidcestim_swc_in);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I169(0) */
            Rte_Read_R_TqCmp_tqSumLossCmpWoutCnv_TqCmp_tqSumLossCmpWoutCnv(&tqcmp_tqsumlosscmpwoutcnv_swc_in);

            COTQ_Sync_Engine_Speed( copt_tqidcreqcord_nregreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    DDS_M_CONVERT_BOOL_TO_UINT8(coptst_bmainengstopreq_swc_in),
                                    coptst_steng_swc_in,
                                    englim_tqidcengcur_swc_in,
                                    englim_tqidcenglimmax_swc_in,
                                    englim_tqidcfldlim_swc_in,
                                    englim_tqidcldmaxtrbmax_swc_in,
                                    englim_tqidcldminadvmin_swc_in,
                                    englim_tqidcldminadvminselc_swc_in,
                                    englim_tqidcmaxnreg_swc_in,
                                    englim_tqidcpresusthrmax_swc_in,
                                    englim_tqidcengcurgbx_swc_in,
                                    eom_tiengstop_swc_in,
                                    ext_tcomes_swc_in,
                                    ext_titdc_swc_in,
                                    ext_toilmes_swc_in,
                                    injsys_tqidcminfeas_swc_in,
                                    tqcmp_tqaltloss_swc_in,
                                    tqcmp_tqsumlosscmp_swc_in,
                                    tqcmp_tqsumlosscmpwoutcnv_swc_in,
                                    tqest_tqidcestim_swc_in,
                                    tqlimem_tqlimemtrv_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    tqsys_tqckenglimcord_swc_in,
                                    treattdc_nckfil_swc_in,
                                    treattdc_nckgrdfil_swc_in,
                                    veh_spdveh_swc_in,
                                    &copt_tqefcreqcord_nregreq_swc_out,
                                    &englim_tqefcenglim_swc_out,
                                    &englim_tqefcenglimcmb_swc_out,
                                    &englim_tqefcldadvminfucutsel_swc_out,
                                    &englim_tqefcldminadvmin_swc_out,
                                    &englim_tqefcmaxenglimcmb_swc_out,
                                    &englim_tqefcmaxnreg_swc_out,
                                    &tqsys_tqckefcminfeas_swc_out,
                                    &tqsys_tqckengreal_swc_out,
                                    &tqsys_tqckengrealem_swc_out,
                                    &tqsys_tqefcengwoutaos_swc_out );

            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I105(0) */
            Rte_Write_P_CoPt_tqEfcReqCord_nRegReq_CoPt_tqEfcReqCord_nRegReq(copt_tqefcreqcord_nregreq_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I108(0) */
            Rte_Write_P_EngLim_tqEfcEngLim_EngLim_tqEfcEngLim(englim_tqefcenglim_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I109(0) */
            Rte_Write_P_EngLim_tqEfcEngLimCmb_EngLim_tqEfcEngLimCmb(englim_tqefcenglimcmb_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I110(0) */
            Rte_Write_P_EngLim_tqEfcLdAdvMinFuCutSel_EngLim_tqEfcLdAdvMinFuCutSel(englim_tqefcldadvminfucutsel_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I112(0) */
            Rte_Write_P_EngLim_tqEfcLdMinAdvMin_EngLim_tqEfcLdMinAdvMin(englim_tqefcldminadvmin_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I113(0) */
            Rte_Write_P_EngLim_tqEfcMaxEngLimCmb_EngLim_tqEfcMaxEngLimCmb(englim_tqefcmaxenglimcmb_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I116(0) */
            Rte_Write_P_TqSys_tqCkEngRealEM_TqSys_tqCkEngRealEM(tqsys_tqckengrealem_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I117(0) */
            Rte_Write_P_TqSys_tqEfcEngWoutAOS_TqSys_tqEfcEngWoutAOS(tqsys_tqefcengwoutaos_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I124(0) */
            Rte_Write_P_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(englim_tqefcmaxnreg_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I132(0) */
            Rte_Write_P_TqSys_tqCkEfcMinFeas_TqSys_tqCkEfcMinFeas(tqsys_tqckefcminfeas_swc_out);
            /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I134(0) */
            Rte_Write_P_TqSys_tqCkEngReal_TqSys_tqCkEngReal(tqsys_tqckengreal_swc_out);

        /* IRV OUTPUT */
        }
        else
        {


        }

    }
    else
    {
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I105(0) */
        Rte_Write_P_CoPt_tqEfcReqCord_nRegReq_CoPt_tqEfcReqCord_nRegReq(CoPt_tqEfcReqCord_nRegReq_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I108(0) */
        Rte_Write_P_EngLim_tqEfcEngLim_EngLim_tqEfcEngLim(EngLim_tqEfcEngLim_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I109(0) */
        Rte_Write_P_EngLim_tqEfcEngLimCmb_EngLim_tqEfcEngLimCmb(EngLim_tqEfcEngLimCmb_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I110(0) */
        Rte_Write_P_EngLim_tqEfcLdAdvMinFuCutSel_EngLim_tqEfcLdAdvMinFuCutSel(EngLim_tqEfcLdAdvMinFuCutSel_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I112(0) */
        Rte_Write_P_EngLim_tqEfcLdMinAdvMin_EngLim_tqEfcLdMinAdvMin(EngLim_tqEfcLdMinAdvMin_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I113(0) */
        Rte_Write_P_EngLim_tqEfcMaxEngLimCmb_EngLim_tqEfcMaxEngLimCmb(EngLim_tqEfcMaxEngLimCmb_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I116(0) */
        Rte_Write_P_TqSys_tqCkEngRealEM_TqSys_tqCkEngRealEM(TqSys_tqCkEngRealEM_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I117(0) */
        Rte_Write_P_TqSys_tqEfcEngWoutAOS_TqSys_tqEfcEngWoutAOS(TqSys_tqEfcEngWoutAOS_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I124(0) */
        Rte_Write_P_EngLim_tqEfcMaxNReg_EngLim_tqEfcMaxNReg(EngLim_tqEfcMaxNReg_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I132(0) */
        Rte_Write_P_TqSys_tqCkEfcMinFeas_TqSys_tqCkEfcMinFeas(TqSys_tqCkEfcMinFeas_B);
        /* SSTG_REQ_TAG: 01552_10_02369-CoTq.I134(0) */
        Rte_Write_P_TqSys_tqCkEngReal_TqSys_tqCkEngReal(TqSys_tqCkEngReal_B);
    }

}



/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : CoTq_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) CoTq_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_CoTq_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define COTQ_STOP_SEC_CODE
#include "CoTq_MemMap.h"

