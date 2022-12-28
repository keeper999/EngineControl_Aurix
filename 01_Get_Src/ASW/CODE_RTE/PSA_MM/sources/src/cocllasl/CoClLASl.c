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
* Ref X:\integration_view_00PSASWC_EA30D11\blois_psa_sstg\Software\Appli\CoClLASl\src\CoClLASl.c
* Version int :/main/00PSASWC_EA/9 Date: 21/1/2014 11 h 58 m User:groult 
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl 13.0
* Version dev :\main\branch_lemort\1 Date: 17/12/2013 15 h 32 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl 13.0
* Version int :/main/00PSASWC_EA/8 Date: 24/5/2012 16 h 24 m User:meme
*    TWK_model:NO_MODEL
*    comments :For CoClLASl_12_1_e6
* Version dev :\main\branch_halouane_cocllasl_dev\1 Date: 24/5/2012 15 h 41 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For CoClLASl_12_1_e6
* Version int :/main/00PSASWC_EA/7 Date: 11/4/2012 9 h 47 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 12.0
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 2/4/2012 10 h 25 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 12.0
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 8/3/2012 14 h 33 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 12.0
* Version int :/main/00PSASWC_EA/6 Date: 6/6/2011 10 h 39 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 11.2: rename TqSys_tqIdcAirReq by TqSys_tqIdcAirReqGen
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 23/5/2011 17 h 17 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl 11.2: rename TqSys_tqIdcAirReq by TqSys_tqIdcAirReqGen
* Version int :/main/00PSASWC_EA/5 Date: 17/3/2011 9 h 26 m User:esnault
*    TWK_model:NO_MODEL
*    comments :update for CoClLASl 11.1
* Version dev :\main\branch_demezil_cocllasl_view\1 Date: 15/3/2011 15 h 37 m User:demezil
*    TWK_model:NO_MODEL
*    comments :update for CoClLASl 11.1
* Version int :/main/00PSASWC_EA/4 Date: 25/2/2011 11 h 29 m User:esnault
*    TWK_model:NO_MODEL
*    comments :Update for CoClLASl 11.0
* Version dev :\main\branch_moisan_cocla\1 Date: 25/2/2011 11 h 0 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for CoClLASl 11.0
* Version dev :\main\branch_halouane_CoClLASl_dev\2 Date: 16/2/2011 17 h 55 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for new STIL.
* Version dev :\main\branch_halouane_CoClLASl_dev\1 Date: 4/2/2011 11 h 12 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for 11.0
* Version int :/main/00PSASWC_EA/3 Date: 21/12/2010 16 h 34 m User:esnault
*    TWK_model:NO_MODEL
*    comments :Update for CoClLASl 10.2
* Version dev :\main\branch_moisan_module_dev\1 Date: 21/12/2010 15 h 54 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for CoClLASl 10.2
* Version int :/main/00PSASWC_EA/2 Date: 4/10/2010 9 h 41 m User:meme
*    TWK_model:NO_MODEL
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 1/10/2010 12 h 25 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for CoClLASl
* Version int :/main/00PSASWC_EA/1 Date: 1/9/2010 17 h 55 m User:esnault
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 31/8/2010 17 h 42 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 29/7/2010 17 h 33 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :validation done
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
*  Check Library Version
*******************************************************************************/

#if COCLLASL_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
dds_lib.* version is not compatible with current SWC version
#endif

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

/* NONE */

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
#define COCLLASL_START_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqCkCurDrivFil_B = (SInt16)(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqIdcEngLimMax_B = (SInt16)(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqIdcLim_B = (SInt16)(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) EngLim_tqIdcMaxNReg_B = (SInt16)(2000 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facAntiStall1_B = (UInt16)(0 * BIN14);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facAntiStall2_B = (UInt16)(0 * BIN14);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facAntiStall3_B = (UInt16)(0 * BIN14);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTqCkAntiStall_B = (UInt16)(0 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkAOSCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEngLimCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkIdlCmn_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkIdlCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcAirEngIdlCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcAirEngLimCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcAirLimCordWiRes_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcAirLimCordWoutRes_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcAirReqUnlim_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcEngIdlCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcEngLimCord_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkAntiStall_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcColdSmkCord_B = (SInt16)(0 * BIN4);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits scalar calibration definition */
#define COCLLASL_START_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) CoPt_bAcvAntiStallFil_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) ESLim_bAcvEngSpdLim_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCll_bAcvCll_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCll_bForcCll_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCll_bReqCllPtl_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvAntiStallSmk_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvAntiStallMan_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvAntiStall_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bEngNOnIdl_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bEngUHNOnIdl_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bIdlAcvCmn_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) COCLLASL_ACTIVE_BYP_C = DDS_FALSE;
#define COCLLASL_STOP_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/


/* 16-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) EngLim_tqIdcAirLimAfterRes_irv;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) EngLim_tqIdcAirLim_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) IdlSys_tqIdcIdlAirSBPA_irv_MP;
#define COCLLASL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"


/* 8-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvAntiStallAut_irv_MP;
#define COCLLASL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define COCLLASL_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CoClLASl_MemMap.h"
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) CoClLASl_ModuleVersion_Major_MP = (UInt8)13;
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) CoClLASl_ModuleVersion_Minor_MP = (UInt8)0;
#define COCLLASL_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_CoClLASl_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CoClLASl_001_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqsys_facantistall1_swc_out;
    UInt16 tqsys_facantistall2_swc_out;
    UInt16 tqsys_facantistall3_swc_out;
    UInt16 tqsys_factqckantistall_swc_out;
    SInt16 tqsys_tqckantistall_swc_out;
    SInt16 tqsys_tqidcairengidlcord_swc_out;
    SInt16 tqsys_tqidcairrequnlim_swc_out;
    UInt8 tqsys_bacvantistall_swc_out;
    UInt8 tqsys_bengnonidl_swc_out;
    UInt8 tqsys_benguhnonidl_swc_out;
    UInt8 tqsys_bidlacvcmn_swc_out;
    SInt16 tqsys_tqckidlcmn_swc_out;
    SInt16 tqsys_tqckidlcord_swc_out;
    SInt16 tqsys_tqidcairenglimcord_swc_out;
    SInt16 tqsys_tqidcairlimcordwires_swc_out;
    SInt16 tqsys_tqidcairlimcordwoutres_swc_out;
    SInt16 tqsys_tqidcengidlcord_swc_out;
    SInt16 tqsys_tqidcenglimcord_swc_out;
    UInt8 tqcll_breqcllptl_swc_out;
    UInt8 tqcll_bacvcll_swc_out;
    UInt8 tqcll_bforccll_swc_out;
    SInt16 tqsys_tqckenglimcord_swc_out;
    SInt16 tqsys_tqckaoscord_swc_out;
    UInt8 eslim_bacvengspdlim_swc_out;
    SInt16 englim_tqckcurdrivfil_swc_out;
    SInt16 englim_tqidcenglimmax_swc_out;
    SInt16 englim_tqidclim_swc_out;
    SInt16 englim_tqidcmaxnreg_swc_out;
    UInt8 tqsys_bacvantistallsmk_swc_out;
    UInt8 copt_bacvantistallfil_swc_out;
    UInt8 tqsys_bacvantistallman_swc_out;
    SInt16 tqsys_tqidccoldsmkcord_swc_out;

    COCLLASL_Anti_Stall_Param_Init(&tqsys_bacvantistallman_swc_out,
                                   &tqsys_facantistall1_swc_out,
                                   &tqsys_facantistall2_swc_out,
                                   &tqsys_facantistall3_swc_out,
                                   &tqsys_factqckantistall_swc_out );

    COCLLASL_Bvm_Anti_Stall_Reg_Init( &tqsys_tqckantistall_swc_out );

    COCLLASL_Cmi_Lim_Cord_Init(&EngLim_tqIdcAirLimAfterRes_irv,
                               &EngLim_tqIdcAirLim_irv_MP,
                               &eslim_bacvengspdlim_swc_out );

    COCLLASL_Cmi_Lim_Cord_Sync_Init( &englim_tqckcurdrivfil_swc_out,
                                               &englim_tqidcenglimmax_swc_out,
                                               &englim_tqidclim_swc_out,
                                               &englim_tqidcmaxnreg_swc_out );

    COCLLASL_Idl_Coord_Lim_Init( &tqsys_tqidcairengidlcord_swc_out,
                                               &tqsys_tqidcairenglimcord_swc_out,
                                               &tqsys_tqidcairlimcordwires_swc_out,
                                               &tqsys_tqidcairlimcordwoutres_swc_out,
                                               &tqsys_tqidcairrequnlim_swc_out );

    COCLLASL_Idl_Coord_Lim_Sync_Init( &tqsys_bacvantistall_swc_out,
                                               &tqsys_bengnonidl_swc_out,
                                               &tqsys_benguhnonidl_swc_out,
                                               &tqsys_bidlacvcmn_swc_out,
                                               &tqsys_tqckidlcmn_swc_out,
                                               &tqsys_tqckidlcord_swc_out,
                                               &tqsys_tqidcengidlcord_swc_out,
                                               &tqsys_tqidcenglimcord_swc_out,
                                               &IdlSys_tqIdcIdlAirSBPA_irv_MP,
                                               &tqsys_tqidccoldsmkcord_swc_out);

    COCLLASL_Req_Cll_Opl_Gbl_Init( &tqcll_bacvcll_swc_out,
                                               &tqcll_bforccll_swc_out,
                                               &tqcll_breqcllptl_swc_out,
                                               &tqsys_tqckenglimcord_swc_out );

    COCLLASL_Trq_Aos_Coord_Init( &tqsys_tqckaoscord_swc_out );

    COCLLASL_Bva_Bmp_Anti_Stall_Init( &copt_bacvantistallfil_swc_out,
                                      &tqsys_bacvantistallsmk_swc_out,
                                      &TqSys_bAcvAntiStallAut_irv_MP);

    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I400(0) */
    Rte_IrvWrite_RE_CoClLASl_001_MSE_EngLim_tqIdcAirLim_irv(EngLim_tqIdcAirLim_irv_MP);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I401(0) */
    Rte_IrvWrite_RE_CoClLASl_001_MSE_EngLim_tqIdcAirLimAfterRes_irv(EngLim_tqIdcAirLimAfterRes_irv);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I402(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_IrvWrite_RE_CoClLASl_001_MSE_TqSys_bAcvAntiStallAut_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqSys_bAcvAntiStallAut_irv_MP));
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I404(0) */
    Rte_IrvWrite_RE_CoClLASl_001_MSE_IdlSys_tqIdcIdlAirSBPA_irv(IdlSys_tqIdcIdlAirSBPA_irv_MP);

    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvAntiStallMan_TqSys_bAcvAntiStallMan(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvantistallman_swc_out));

    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I201(0) */
    Rte_Write_P_TqSys_facAntiStall1_TqSys_facAntiStall1(tqsys_facantistall1_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I202(0) */
    Rte_Write_P_TqSys_facAntiStall2_TqSys_facAntiStall2(tqsys_facantistall2_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I203(0) */
    Rte_Write_P_TqSys_facAntiStall3_TqSys_facAntiStall3(tqsys_facantistall3_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I204(0) */
    Rte_Write_P_TqSys_facTqCkAntiStall_TqSys_facTqCkAntiStall(tqsys_factqckantistall_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_INP_026 */
    Rte_Write_P_TqSys_tqCkAntiStall_TqSys_tqCkAntiStall(tqsys_tqckantistall_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_001 */
    Rte_Write_P_TqSys_tqIdcAirEngIdlCord_TqSys_tqIdcAirEngIdlCord(tqsys_tqidcairengidlcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_002 */
    Rte_Write_P_TqSys_tqIdcAirReqUnlim_TqSys_tqIdcAirReqUnlim(tqsys_tqidcairrequnlim_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_003 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvAntiStall_TqSys_bAcvAntiStall(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvantistall_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_004 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bengnonidl_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_005 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bEngUHNOnIdl_TqSys_bEngUHNOnIdl(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_benguhnonidl_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_006 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bIdlAcvCmn_TqSys_bIdlAcvCmn(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bidlacvcmn_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_007 */
    Rte_Write_P_TqSys_tqCkIdlCmn_TqSys_tqCkIdlCmn(tqsys_tqckidlcmn_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_008 */
    Rte_Write_P_TqSys_tqCkIdlCord_TqSys_tqCkIdlCord(tqsys_tqckidlcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_009 */
    Rte_Write_P_TqSys_tqIdcAirEngLimCord_TqSys_tqIdcAirEngLimCord(tqsys_tqidcairenglimcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_010 */
    Rte_Write_P_TqSys_tqIdcAirLimCordWiRes_TqSys_tqIdcAirLimCordWiRes(tqsys_tqidcairlimcordwires_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_011 */
    Rte_Write_P_TqSys_tqIdcAirLimCordWoutRes_TqSys_tqIdcAirLimCordWoutRes(tqsys_tqidcairlimcordwoutres_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_012 */
    Rte_Write_P_TqSys_tqIdcEngIdlCord_TqSys_tqIdcEngIdlCord(tqsys_tqidcengidlcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_013 */
    Rte_Write_P_TqSys_tqIdcEngLimCord_TqSys_tqIdcEngLimCord(tqsys_tqidcenglimcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_014 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCll_bReqCllPtl_TqCll_bReqCllPtl(DDS_M_CONVERT_UINT8_TO_BOOL(tqcll_breqcllptl_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_015 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCll_bAcvCll_TqCll_bAcvCll(DDS_M_CONVERT_UINT8_TO_BOOL(tqcll_bacvcll_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_016 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCll_bForcCll_TqCll_bForcCll(DDS_M_CONVERT_UINT8_TO_BOOL(tqcll_bforccll_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_017 */
    Rte_Write_P_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(tqsys_tqckenglimcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_018 */
    Rte_Write_P_TqSys_tqCkAOSCord_TqSys_tqCkAOSCord(tqsys_tqckaoscord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_019 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_ESLim_bAcvEngSpdLim_ESLim_bAcvEngSpdLim(DDS_M_CONVERT_UINT8_TO_BOOL(eslim_bacvengspdlim_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_020 */
    Rte_Write_P_EngLim_tqCkCurDrivFil_EngLim_tqCkCurDrivFil(englim_tqckcurdrivfil_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_021 */
    Rte_Write_P_EngLim_tqIdcEngLimMax_EngLim_tqIdcEngLimMax(englim_tqidcenglimmax_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_022 */
    Rte_Write_P_EngLim_tqIdcLim_EngLim_tqIdcLim(englim_tqidclim_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_023 */
    Rte_Write_P_EngLim_tqIdcMaxNReg_EngLim_tqIdcMaxNReg(englim_tqidcmaxnreg_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_024 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvAntiStallSmk_TqSys_bAcvAntiStallSmk(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvantistallsmk_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_025 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bAcvAntiStallFil_CoPt_bAcvAntiStallFil(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bacvantistallfil_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_026 */
    Rte_Write_P_TqSys_tqIdcColdSmkCord_TqSys_tqIdcColdSmkCord(tqsys_tqidccoldsmkcord_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_AntiStallReg
*  Event            :
*  Description      :
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_AntiStallReg(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 ext_neng1_swc_in;
    UInt16 tqsys_facantistall1_swc_in;
    UInt16 tqsys_facantistall2_swc_in;
    UInt16 ext_neng2_swc_in;
    UInt16 tqsys_facantistall3_swc_in;
    UInt16 tqsys_factqckantistall_swc_in;
    SInt16 tqsys_tqckidl_swc_in;
    SInt16 tqsys_tqckidlmin_swc_in;
    SInt16 tqsys_tqckidlmax_swc_in;
    UInt16 ext_neng_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    Boolean tqsys_btypfu_swc_in;
    UInt16 tqsys_ntardynidl_swc_in;

    Boolean tqsys_bacvantistallman_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqsys_tqckantistall_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_083 */
        Rte_Read_R_Ext_nEng1_Ext_nEng1(&ext_neng1_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_084 */
        Rte_Read_R_TqSys_facAntiStall1_TqSys_facAntiStall1(&tqsys_facantistall1_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_085 */
        Rte_Read_R_TqSys_facAntiStall2_TqSys_facAntiStall2(&tqsys_facantistall2_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_086 */
        Rte_Read_R_Ext_nEng2_Ext_nEng2(&ext_neng2_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_087 */
        Rte_Read_R_TqSys_facAntiStall3_TqSys_facAntiStall3(&tqsys_facantistall3_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_088 */
        Rte_Read_R_TqSys_facTqCkAntiStall_TqSys_facTqCkAntiStall(&tqsys_factqckantistall_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_089 */
        Rte_Read_R_TqSys_tqCkIdl_TqSys_tqCkIdl(&tqsys_tqckidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_090 */
        Rte_Read_R_TqSys_tqCkIdlMin_TqSys_tqCkIdlMin(&tqsys_tqckidlmin_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_091 */
        Rte_Read_R_TqSys_tqCkIdlMax_TqSys_tqCkIdlMax(&tqsys_tqckidlmax_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_012 */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_013 */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_080 */
        Rte_Read_R_TqSys_nTarDynIdl_TqSys_nTarDynIdl(&tqsys_ntardynidl_swc_in);

        /* SSTG_REQ_TAG: DDS_REQ_INP_021 */
        Rte_Read_R_TqSys_bAcvAntiStallMan_TqSys_bAcvAntiStallMan(&tqsys_bacvantistallman_swc_in);

        COCLLASL_Bvm_Anti_Stall_Reg(ext_neng_swc_in,
                                    ext_neng1_swc_in,
                                    ext_neng2_swc_in,
                                    ext_stgbxcf_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    tqsys_ntardynidl_swc_in,
                                    tqsys_tqckidl_swc_in,
                                    tqsys_tqckidlmax_swc_in,
                                    tqsys_tqckidlmin_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvantistallman_swc_in),
                                    tqsys_facantistall1_swc_in,
                                    tqsys_facantistall2_swc_in,
                                    tqsys_facantistall3_swc_in,
                                    tqsys_factqckantistall_swc_in,
                                    &tqsys_tqckantistall_swc_out );



        /* IRV OUTPUT */
    }
    else
    {
        tqsys_tqckantistall_swc_out = TqSys_tqCkAntiStall_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_INP_026 */
    Rte_Write_P_TqSys_tqCkAntiStall_TqSys_tqCkAntiStall(tqsys_tqckantistall_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_CoPtAntiStall
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_CoPtAntiStall(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 ext_neng_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    UInt8 ext_titdc_swc_in;
    Boolean copt_btqtx_swc_in;
    UInt8 copt_stcpl_swc_in;
    Boolean cobrk_bacvbrk_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 treattdc_nckgrd_swc_in;
    UInt16 veh_spdveh_swc_in;
    /* FIM (FRM) */
    Boolean frm_binhcoptbrk_fim_in;
    Boolean frm_binhcoptspdveh_fim_in;
    Boolean frm_binhcoptstpt_fim_in;
    Boolean frm_binhcopttco_fim_in;

    Boolean cocllasl_bool_temp;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqsys_bacvantistallsmk_swc_out;
    UInt8 copt_bacvantistallfil_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_012 */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_013 */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_014 */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_070 */
        Rte_Read_R_CoPt_bTqTx_CoPt_bTqTx(&copt_btqtx_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_071 */
        Rte_Read_R_CoPt_stCpl_CoPt_stCpl(&copt_stcpl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I152(0) */
        Rte_Read_R_CoBrk_bAcvBrk_CoBrk_bAcvBrk(&cobrk_bacvbrk_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_073 */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_075 */
        Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&treattdc_nckgrd_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_076 */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I701(0) */
        Rte_Call_R_FRM_bInhCoPtBrk_GetFunctionPermission(&cocllasl_bool_temp);
		if((UInt32)cocllasl_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhcoptbrk_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhcoptbrk_fim_in = (Boolean)DDS_FALSE;
		}

        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I702(0) */
        Rte_Call_R_FRM_bInhCoPtSpdVeh_GetFunctionPermission(&cocllasl_bool_temp);
		if((UInt32)cocllasl_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhcoptspdveh_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhcoptspdveh_fim_in = (Boolean)DDS_FALSE;
		}

        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I703(0) */
        Rte_Call_R_FRM_bInhCoPtStPt_GetFunctionPermission(&cocllasl_bool_temp);
		if((UInt32)cocllasl_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhcoptstpt_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhcoptstpt_fim_in = (Boolean)DDS_FALSE;
		}

        Rte_Call_R_FRM_bInhCoPtTCo_GetFunctionPermission(&cocllasl_bool_temp);
		if((UInt32)cocllasl_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhcopttco_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhcopttco_fim_in = (Boolean)DDS_FALSE;
		}



        COCLLASL_Bva_Bmp_Anti_Stall(/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_btqtx_swc_in),
                                    copt_stcpl_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(cobrk_bacvbrk_swc_in),
                                    ext_neng_swc_in,
                                    ext_stgbxcf_swc_in,
                                    ext_tcomes_swc_in,
                                    ext_titdc_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhcoptbrk_fim_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhcoptspdveh_fim_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhcoptstpt_fim_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhcopttco_fim_in),
                                    treattdc_nckgrd_swc_in,
                                    veh_spdveh_swc_in,
                                    &copt_bacvantistallfil_swc_out,
                                    &tqsys_bacvantistallsmk_swc_out,
                                    &TqSys_bAcvAntiStallAut_irv_MP);



        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I402(0) */
        /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_IrvWrite_RE_TqSys_EveSync_CoPtAntiStall_TqSys_bAcvAntiStallAut_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqSys_bAcvAntiStallAut_irv_MP));
    }
    else
    {
        tqsys_bacvantistallsmk_swc_out = TqSys_bAcvAntiStallSmk_B;
        copt_bacvantistallfil_swc_out = CoPt_bAcvAntiStallFil_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_OUT_024 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvAntiStallSmk_TqSys_bAcvAntiStallSmk(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvantistallsmk_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_025 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoPt_bAcvAntiStallFil_CoPt_bAcvAntiStallFil(DDS_M_CONVERT_UINT8_TO_BOOL(copt_bacvantistallfil_swc_out));

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_CurCord
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_CurCord(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 englim_tqckcurdrivfil_swc_in;
    SInt16 tqsys_tqaoscvc_swc_in;
    SInt16 tqsys_tqckaoscor_swc_in;
    SInt16 tqsys_tqckenglimcord_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqsys_tqckaoscord_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_054 */
        Rte_Read_R_EngLim_tqCkCurDrivFil_EngLim_tqCkCurDrivFil(&englim_tqckcurdrivfil_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_056 */
        Rte_Read_R_TqSys_tqAOSCVC_TqSys_tqAOSCVC(&tqsys_tqaoscvc_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_057 */
        Rte_Read_R_TqSys_tqCkAOSCor_TqSys_tqCkAOSCor(&tqsys_tqckaoscor_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_058 */
        Rte_Read_R_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(&tqsys_tqckenglimcord_swc_in);




        COCLLASL_Trq_Aos_Coord( englim_tqckcurdrivfil_swc_in,
                                tqsys_tqaoscvc_swc_in,
                                tqsys_tqckaoscor_swc_in,
                                tqsys_tqckenglimcord_swc_in,
                                &tqsys_tqckaoscord_swc_out );



        /* IRV OUTPUT */
    }
    else
    {
        tqsys_tqckaoscord_swc_out = TqSys_tqCkAOSCord_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_OUT_018 */
    Rte_Write_P_TqSys_tqCkAOSCord_TqSys_tqCkAOSCord(tqsys_tqckaoscord_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_TqCll
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_TqCll(void)
{
    /* INPUT */
    /* SWC IN */
    UInt8 ext_titdc_swc_in;
    Boolean idlsys_bacvcll_swc_in;
    Boolean tqsys_btypfu_swc_in;
    Boolean cocha_bacvcll_swc_in;
    UInt16 cocha_titrancll_swc_in;
    UInt16 cocha_tqinccll_swc_in;
    Boolean copt_bacvcll_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    UInt16 copt_titrancll_swc_in;
    UInt16 copt_tqinccll_swc_in;
    UInt16 eng_nckfil_swc_in;
    Boolean englim_bacvcll_swc_in;
    UInt16 englim_titrancll_swc_in;
    SInt16 englim_tqidcengcurmax_swc_in;
    UInt16 englim_tqinccll_swc_in;
    UInt16 idlsys_titrancll_swc_in;
    UInt16 idlsys_tqinccll_swc_in;
    Boolean tqres_bacvcll_swc_in;
    UInt16 tqres_titrancll_swc_in;
    UInt16 tqres_tqinccll_swc_in;
    Boolean tqsys_bacvcll_swc_in;
    Boolean tqsys_baosacv_swc_in;
    Boolean tqsys_bengnonidl_swc_in;
    UInt16 tqsys_titrancll_swc_in;
    SInt16 tqsys_tqidcairreqgen_swc_in;
    SInt16 tqsys_tqidcenglimcord_swc_in;
    UInt16 tqsys_tqinccll_swc_in;
    Boolean eng_bacvcllengreq_swc_in;
    Boolean tqadvmin_bacvcll_swc_in;
    UInt16 tqadvmin_tqinccll_swc_in; /* BIN4 */
    UInt16 tqadvmin_titrancll_swc_in; /* DEC2 */
    /* FIM (FRM) */
    Boolean frm_binhtqcll_fim_in;

    Boolean cocllasl_bool_temp;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqcll_breqcllptl_swc_out;
    UInt8 tqcll_bacvcll_swc_out;
    UInt8 tqcll_bforccll_swc_out;
    SInt16 tqsys_tqckenglimcord_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_014 */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_016 */
        Rte_Read_R_IdlSys_bAcvCll_IdlSys_bAcvCll(&idlsys_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_029 */
        Rte_Read_R_CoCha_bAcvCll_CoCha_bAcvCll(&cocha_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_030 */
        Rte_Read_R_CoCha_tiTranCll_CoCha_tiTranCll(&cocha_titrancll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_031 */
        Rte_Read_R_CoCha_tqIncCll_CoCha_tqIncCll(&cocha_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_032 */
        Rte_Read_R_CoPt_bAcvCll_CoPt_bAcvCll(&copt_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_033 */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_034 */
        Rte_Read_R_CoPt_tiTranCll_CoPt_tiTranCll(&copt_titrancll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_035 */
        Rte_Read_R_CoPt_tqIncCll_CoPt_tqIncCll(&copt_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_036 */
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_037 */
        Rte_Read_R_EngLim_bAcvCll_EngLim_bAcvCll(&englim_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_038 */
        Rte_Read_R_EngLim_tiTranCll_EngLim_tiTranCll(&englim_titrancll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_039 */
        Rte_Read_R_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax(&englim_tqidcengcurmax_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_040 */
        Rte_Read_R_EngLim_tqIncCll_EngLim_tqIncCll(&englim_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_041 */
        Rte_Read_R_IdlSys_tiTranCll_IdlSys_tiTranCll(&idlsys_titrancll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_042 */
        Rte_Read_R_IdlSys_tqIncCll_IdlSys_tqIncCll(&idlsys_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_043 */
        Rte_Read_R_TqRes_bAcvCll_TqRes_bAcvCll(&tqres_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_044 */
        Rte_Read_R_TqRes_tiTranCll_TqRes_tiTranCll(&tqres_titrancll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_045 */
        Rte_Read_R_TqRes_tqIncCll_TqRes_tqIncCll(&tqres_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_046 */
        Rte_Read_R_TqSys_bAcvCll_TqSys_bAcvCll(&tqsys_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_047 */
        Rte_Read_R_TqSys_bAOSAcv_TqSys_bAOSAcv(&tqsys_baosacv_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_048 */
        Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&tqsys_bengnonidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_050 */
        Rte_Read_R_TqSys_tiTranCll_TqSys_tiTranCll(&tqsys_titrancll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_051 */
        Rte_Read_R_TqSys_tqIdcAirReqGen_TqSys_tqIdcAirReqGen(&tqsys_tqidcairreqgen_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_052 */
        Rte_Read_R_TqSys_tqIdcEngLimCord_TqSys_tqIdcEngLimCord(&tqsys_tqidcenglimcord_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_053 */
        Rte_Read_R_TqSys_tqIncCll_TqSys_tqIncCll(&tqsys_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_054 */
        Rte_Read_R_Eng_bAcvCllEngReq_Eng_bAcvCllEngReq(&eng_bacvcllengreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I700(0) */
        Rte_Call_R_FRM_bInhTqCll_GetFunctionPermission(&cocllasl_bool_temp);
		if((UInt32)cocllasl_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhtqcll_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhtqcll_fim_in = (Boolean)DDS_FALSE;
		}

        /* SSTG_REQ_TAG: DDS_REQ_INP_054 */
        Rte_Read_R_TqAdvMin_bAcvCll_TqAdvMin_bAcvCll(&tqadvmin_bacvcll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_054 */
        Rte_Read_R_TqAdvMin_tqIncCll_TqAdvMin_tqIncCll(&tqadvmin_tqinccll_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_054 */
        Rte_Read_R_TqAdvMin_tiTranCll_TqAdvMin_tiTranCll(&tqadvmin_titrancll_swc_in);


        COCLLASL_Req_Cll_Opl_Gbl(   /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(cocha_bacvcll_swc_in),
                                    cocha_titrancll_swc_in,
                                    cocha_tqinccll_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_bacvcll_swc_in),
                                    copt_nogearcorddrivfil_swc_in,
                                    copt_titrancll_swc_in,
                                    copt_tqinccll_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(englim_bacvcll_swc_in),
                                    englim_titrancll_swc_in,
                                    englim_tqidcengcurmax_swc_in,
                                    englim_tqinccll_swc_in,
                                    eng_nckfil_swc_in,
                                    ext_titdc_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhtqcll_fim_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(idlsys_bacvcll_swc_in),
                                    idlsys_titrancll_swc_in,
                                    idlsys_tqinccll_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqres_bacvcll_swc_in),
                                    tqres_titrancll_swc_in,
                                    tqres_tqinccll_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_baosacv_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvcll_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bengnonidl_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    tqsys_titrancll_swc_in,
                                    tqsys_tqidcairreqgen_swc_in,
                                    tqsys_tqidcenglimcord_swc_in,
                                    tqsys_tqinccll_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(eng_bacvcllengreq_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqadvmin_bacvcll_swc_in),
                                    tqadvmin_tqinccll_swc_in, /* BIN4 */
                                    tqadvmin_titrancll_swc_in, /* DEC2 */
                                    &tqcll_bacvcll_swc_out,
                                    &tqcll_bforccll_swc_out,
                                    &tqcll_breqcllptl_swc_out,
                                    &tqsys_tqckenglimcord_swc_out );



        /* IRV OUTPUT */
    }
    else
    {
        tqcll_breqcllptl_swc_out = TqCll_bReqCllPtl_B;
        tqcll_bacvcll_swc_out = TqCll_bAcvCll_B;
        tqcll_bforccll_swc_out = TqCll_bForcCll_B;
        tqsys_tqckenglimcord_swc_out = TqSys_tqCkEngLimCord_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_OUT_014 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCll_bReqCllPtl_TqCll_bReqCllPtl(DDS_M_CONVERT_UINT8_TO_BOOL(tqcll_breqcllptl_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_015 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCll_bAcvCll_TqCll_bAcvCll(DDS_M_CONVERT_UINT8_TO_BOOL(tqcll_bacvcll_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_016 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCll_bForcCll_TqCll_bForcCll(DDS_M_CONVERT_UINT8_TO_BOOL(tqcll_bforccll_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_017 */
    Rte_Write_P_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(tqsys_tqckenglimcord_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_TqCordLim
*  Event            :
*  Description      :
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_TqCordLim(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 englim_tqidcred_swc_in;
    UInt16 ext_neng_swc_in;
    Boolean tqsys_btypfu_swc_in;
    SInt16 englim_tqidcengcurmax_swc_in;
    UInt8 copt_nogearcord_swc_in;
    SInt16 englim_tqidcenglim_swc_in;
    SInt16 englim_tqidcengprot_swc_in;
    SInt16 englim_tqidcpresusthrmax_swc_in;
    SInt16 englim_tqidcsfty_swc_in;
    SInt16 englim_tqidcsyst_swc_in;
    SInt16 tqdem_tqidclimnreg_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 englim_tqckcurdrivfil_swc_out;
    SInt16 englim_tqidcenglimmax_swc_out;
    SInt16 englim_tqidclim_swc_out;
    SInt16 englim_tqidcmaxnreg_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_011 */
        Rte_Read_R_EngLim_tqIdcRed_EngLim_tqIdcRed(&englim_tqidcred_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_012 */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_039 */
        Rte_Read_R_EngLim_tqIdcEngCurMax_EngLim_tqIdcEngCurMax(&englim_tqidcengcurmax_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_059 */
        Rte_Read_R_CoPt_noGearCord_CoPt_noGearCord(&copt_nogearcord_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_062 */
        Rte_Read_R_EngLim_tqIdcEngLim_EngLim_tqIdcEngLim(&englim_tqidcenglim_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_063 */
        Rte_Read_R_EngLim_tqIdcEngProt_EngLim_tqIdcEngProt(&englim_tqidcengprot_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_064 */
        Rte_Read_R_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax(&englim_tqidcpresusthrmax_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_065 */
        Rte_Read_R_EngLim_tqIdcSfty_EngLim_tqIdcSfty(&englim_tqidcsfty_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_066 */
        Rte_Read_R_EngLim_tqIdcSyst_EngLim_tqIdcSyst(&englim_tqidcsyst_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_068 */
        Rte_Read_R_TqDem_tqIdcLimNReg_TqDem_tqIdcLimNReg(&tqdem_tqidclimnreg_swc_in);




        COCLLASL_Cmi_Lim_Cord_Sync( copt_nogearcord_swc_in,
                                    englim_tqidcengcurmax_swc_in,
                                    englim_tqidcenglim_swc_in,
                                    englim_tqidcengprot_swc_in,
                                    englim_tqidcpresusthrmax_swc_in,
                                    englim_tqidcred_swc_in,
                                    englim_tqidcsfty_swc_in,
                                    englim_tqidcsyst_swc_in,
                                    ext_neng_swc_in,
                                    tqdem_tqidclimnreg_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    &englim_tqckcurdrivfil_swc_out,
                                    &englim_tqidcenglimmax_swc_out,
                                    &englim_tqidclim_swc_out,
                                    &englim_tqidcmaxnreg_swc_out );



        /* IRV OUTPUT */
    }
    else
    {
        englim_tqckcurdrivfil_swc_out = EngLim_tqCkCurDrivFil_B;
        englim_tqidcenglimmax_swc_out = EngLim_tqIdcEngLimMax_B;
        englim_tqidclim_swc_out = EngLim_tqIdcLim_B;
        englim_tqidcmaxnreg_swc_out = EngLim_tqIdcMaxNReg_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_OUT_020 */
    Rte_Write_P_EngLim_tqCkCurDrivFil_EngLim_tqCkCurDrivFil(englim_tqckcurdrivfil_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_021 */
    Rte_Write_P_EngLim_tqIdcEngLimMax_EngLim_tqIdcEngLimMax(englim_tqidcenglimmax_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_022 */
    Rte_Write_P_EngLim_tqIdcLim_EngLim_tqIdcLim(englim_tqidclim_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_023 */
    Rte_Write_P_EngLim_tqIdcMaxNReg_EngLim_tqIdcMaxNReg(englim_tqidcmaxnreg_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_VarAntiStall
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_VarAntiStall(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 ext_neng_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    UInt8 ext_titdc_swc_in;
    Boolean tqsys_btypfu_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 treattdc_nckgrd_swc_in;
    Boolean copt_bcludiegdcord_swc_in;
    UInt32 eom_tiengrun_swc_in;
    Boolean tqsys_bidlacvcmn_swc_in;
    UInt16 tqsys_ntardynidl_swc_in;
    SInt16 tqsys_tqidcreq_swc_in;
    SInt16 treattdc_ncktdcdelta_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqsys_facantistall1_swc_out;
    UInt16 tqsys_facantistall2_swc_out;
    UInt16 tqsys_facantistall3_swc_out;
    UInt16 tqsys_factqckantistall_swc_out;
    UInt8 tqsys_bacvantistallman_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_012 */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_013 */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_014 */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_073 */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_075 */
        Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&treattdc_nckgrd_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_077 */
        Rte_Read_R_CoPt_bCluDiEgdCord_CoPt_bCluDiEgdCord(&copt_bcludiegdcord_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_078 */
        Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun(&eom_tiengrun_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_079 */
        Rte_Read_R_TqSys_bIdlAcvCmn_TqSys_bIdlAcvCmn(&tqsys_bidlacvcmn_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_080 */
        Rte_Read_R_TqSys_nTarDynIdl_TqSys_nTarDynIdl(&tqsys_ntardynidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_081 */
        Rte_Read_R_TqSys_tqIdcReq_TqSys_tqIdcReq(&tqsys_tqidcreq_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_082 */
        Rte_Read_R_TreatTDC_nCkTDCDelta_TreatTDC_nCkTDCDelta(&treattdc_ncktdcdelta_swc_in);



        COCLLASL_Anti_Stall_Param(  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_bcludiegdcord_swc_in),
                                    eom_tiengrun_swc_in,
                                    ext_neng_swc_in,
                                    ext_stgbxcf_swc_in,
                                    ext_tcomes_swc_in,
                                    ext_titdc_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bidlacvcmn_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    tqsys_ntardynidl_swc_in,
                                    tqsys_tqidcreq_swc_in,
                                    treattdc_nckgrd_swc_in,
                                    treattdc_ncktdcdelta_swc_in,
                                    &tqsys_bacvantistallman_swc_out,
                                    &tqsys_facantistall1_swc_out,
                                    &tqsys_facantistall2_swc_out,
                                    &tqsys_facantistall3_swc_out,
                                    &tqsys_factqckantistall_swc_out );


        /* IRV OUTPUT */


    }
    else
    {
        tqsys_bacvantistallman_swc_out = TqSys_bAcvAntiStallMan_B;
        tqsys_facantistall1_swc_out = TqSys_facAntiStall1_B;
        tqsys_facantistall2_swc_out = TqSys_facAntiStall2_B;
        tqsys_facantistall3_swc_out = TqSys_facAntiStall3_B;
        tqsys_factqckantistall_swc_out = TqSys_facTqCkAntiStall_B;

    }

    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvAntiStallMan_TqSys_bAcvAntiStallMan(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvantistallman_swc_out));
    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I201(0) */
    Rte_Write_P_TqSys_facAntiStall1_TqSys_facAntiStall1(tqsys_facantistall1_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I202(0) */
    Rte_Write_P_TqSys_facAntiStall2_TqSys_facAntiStall2(tqsys_facantistall2_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I203(0) */
    Rte_Write_P_TqSys_facAntiStall3_TqSys_facAntiStall3(tqsys_facantistall3_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I204(0) */
    Rte_Write_P_TqSys_facTqCkAntiStall_TqSys_facTqCkAntiStall(tqsys_factqckantistall_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCordLim
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCordLim(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 englim_tqidcairresmax_swc_in;
    SInt16 englim_tqidcengprot_swc_in;
    SInt16 englim_tqidcpresusthrmax_swc_in;
    SInt16 englim_tqidcsyst_swc_in;
    UInt16 thmgt_tqidclimreq_swc_in;
    SInt16 tqdem_tqidclimnreg_swc_in;
    SInt16 tqsys_tqidcairlimcordwires_swc_in;
    SInt16 englim_tqidcadvoptmtrbmax_swc_in;
    Boolean tqsys_btypfu_swc_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 eslim_bacvengspdlim_swc_out;

    /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
    Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);


    if((UInt32)DDS_TRUE == (UInt32)tqsys_btypfu_swc_in)
    {

        if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
        {


            /* SSTG_REQ_TAG: DDS_REQ_INP_061 */
            Rte_Read_R_EngLim_tqIdcAirResMax_EngLim_tqIdcAirResMax(&englim_tqidcairresmax_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_063 */
            Rte_Read_R_EngLim_tqIdcEngProt_EngLim_tqIdcEngProt(&englim_tqidcengprot_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_064 */
            Rte_Read_R_EngLim_tqIdcPresUsThrMax_EngLim_tqIdcPresUsThrMax(&englim_tqidcpresusthrmax_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_066 */
            Rte_Read_R_EngLim_tqIdcSyst_EngLim_tqIdcSyst(&englim_tqidcsyst_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_067 */
            Rte_Read_R_ThMgt_tqIdcLimReq_ThMgt_tqIdcLimReq(&thmgt_tqidclimreq_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_068 */
            Rte_Read_R_TqDem_tqIdcLimNReg_TqDem_tqIdcLimNReg(&tqdem_tqidclimnreg_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_069 */
            Rte_Read_R_TqSys_tqIdcAirLimCordWiRes_TqSys_tqIdcAirLimCordWiRes(&tqsys_tqidcairlimcordwires_swc_in);
            /* SSTG_REQ_TAG: DDS_REQ_INP_060 */
            Rte_Read_R_EngLim_tqIdcAdvOptmTrbMax_EngLim_tqIdcAdvOptmTrbMax(&englim_tqidcadvoptmtrbmax_swc_in);


            COCLLASL_Cmi_Lim_Cord(  englim_tqidcairresmax_swc_in,
                                    englim_tqidcengprot_swc_in,
                                    englim_tqidcsyst_swc_in,
                                    englim_tqidcadvoptmtrbmax_swc_in,
                                    tqdem_tqidclimnreg_swc_in,
                                    tqsys_tqidcairlimcordwires_swc_in,
                                    thmgt_tqidclimreq_swc_in,
                                    &EngLim_tqIdcAirLimAfterRes_irv,
                                    &EngLim_tqIdcAirLim_irv_MP,
                                    &eslim_bacvengspdlim_swc_out );



            /* IRV OUTPUT */
            /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I400(0) */
            Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCordLim_EngLim_tqIdcAirLim_irv(EngLim_tqIdcAirLim_irv_MP);
            /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I401(0) */
            Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCordLim_EngLim_tqIdcAirLimAfterRes_irv(EngLim_tqIdcAirLimAfterRes_irv);
        }
        else
        {
            eslim_bacvengspdlim_swc_out = ESLim_bAcvEngSpdLim_B;

        }

        /* OUTPUT */
        /* SSTG_REQ_TAG: DDS_REQ_OUT_019 */
        /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_Write_P_ESLim_bAcvEngSpdLim_ESLim_bAcvEngSpdLim(DDS_M_CONVERT_UINT8_TO_BOOL(eslim_bacvengspdlim_swc_out));
    }
	else
	{
		/* do nothing */

	}
}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_IdlCordLim
*  Event            :
*  Description      :
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_IdlCordLim(void)
{
    /* INPUT */
    /* SWC IN */
    Boolean tqsys_bidlacv_swc_in;
    Boolean copt_bsipcord_swc_in;
    SInt16 copt_tqidcreqcord_nregreq_swc_in;
    UInt16 covsctl_raccpengtrv_swc_in;
    Boolean dfwctl_bacvlimtqidl_swc_in;
    SInt16 englim_tqidccoldsmkraw_swc_in;
    SInt16 englim_tqidclim_swc_in;
    SInt16 englim_tqidcred_swc_in;
    UInt16 ext_neng_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    UInt8 ext_titdc_swc_in;
    Boolean idlsys_bacvantistall_swc_in;
    Boolean idlsys_bacvidlctl_swc_in;
    SInt16 idlsys_tqidcidl_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqsys_btypfu_swc_in;
    UInt8 tqsys_facreqexhtempprot_swc_in;
    UInt8 tqsys_facreqfuelrundry_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    SInt16 tqsys_tqckantistall_swc_in;
    SInt16 tqsys_tqidclvlsbpa_swc_in;
    SInt16 tqsys_tqidcsbpa_swc_in;
    SInt16 tqsys_tqckidl_swc_in;
    Boolean tqsys_bacvantistallman_swc_in;

    /* IRV */
    Boolean tqsys_bacvantistallaut_irv_in;


    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqsys_bacvantistall_swc_out;
    UInt8 tqsys_bengnonidl_swc_out;
    UInt8 tqsys_benguhnonidl_swc_out;
    UInt8 tqsys_bidlacvcmn_swc_out;
    SInt16 tqsys_tqckidlcmn_swc_out;
    SInt16 tqsys_tqckidlcord_swc_out;
    SInt16 tqsys_tqidcengidlcord_swc_out;
    SInt16 tqsys_tqidcenglimcord_swc_out;
    SInt16 tqsys_tqidccoldsmkcord_swc_out;


    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_001 */
        Rte_Read_R_TqSys_bIdlAcv_TqSys_bIdlAcv(&tqsys_bidlacv_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_003 */
        Rte_Read_R_CoPt_bSIPCord_CoPt_bSIPCord(&copt_bsipcord_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_006 */
        Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(&copt_tqidcreqcord_nregreq_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_007 */
        Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&covsctl_raccpengtrv_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_008 */
        Rte_Read_R_DfwCtl_bAcvLimTqIdl_DfwCtl_bAcvLimTqIdl(&dfwctl_bacvlimtqidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_009 */
        Rte_Read_R_EngLim_tqIdcColdSmkRaw_EngLim_tqIdcColdSmkRaw(&englim_tqidccoldsmkraw_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_010 */
        Rte_Read_R_EngLim_tqIdcLim_EngLim_tqIdcLim(&englim_tqidclim_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_011 */
        Rte_Read_R_EngLim_tqIdcRed_EngLim_tqIdcRed(&englim_tqidcred_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_012 */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_013 */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_014 */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_015 */
        Rte_Read_R_IdlSys_bAcvAntiStall_IdlSys_bAcvAntiStall(&idlsys_bacvantistall_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_016 */
        Rte_Read_R_IdlSys_bAcvIdlCtl_IdlSys_bAcvIdlCtl(&idlsys_bacvidlctl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_018 */
        Rte_Read_R_IdlSys_tqIdcIdl_IdlSys_tqIdcIdl(&idlsys_tqidcidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_019 */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_023 */
        Rte_Read_R_TqSys_facReqExhTempProt_TqSys_facReqExhTempProt(&tqsys_facreqexhtempprot_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_024 */
        Rte_Read_R_TqSys_facReqFuelRunDry_TqSys_facReqFuelRunDry(&tqsys_facreqfuelrundry_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_025 */
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_026 */
        Rte_Read_R_TqSys_tqCkAntiStall_TqSys_tqCkAntiStall(&tqsys_tqckantistall_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_027 */
        Rte_Read_R_TqSys_tqIdcLvlSBPA_TqSys_tqIdcLvlSBPA(&tqsys_tqidclvlsbpa_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_028 */
        Rte_Read_R_TqSys_tqIdcSBPA_TqSys_tqIdcSBPA(&tqsys_tqidcsbpa_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_089 */
        Rte_Read_R_TqSys_tqCkIdl_TqSys_tqCkIdl(&tqsys_tqckidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_021 */
        Rte_Read_R_TqSys_bAcvAntiStallMan_TqSys_bAcvAntiStallMan(&tqsys_bacvantistallman_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I402(0) */
        tqsys_bacvantistallaut_irv_in = Rte_IrvRead_RE_TqSys_EveSync_IdlCordLim_TqSys_bAcvAntiStallAut_irv();

        COCLLASL_Idl_Coord_Lim_Sync(/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_bsipcord_swc_in),
                                    copt_tqidcreqcord_nregreq_swc_in,
                                    covsctl_raccpengtrv_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(dfwctl_bacvlimtqidl_swc_in),
                                    englim_tqidccoldsmkraw_swc_in,
                                    englim_tqidclim_swc_in,
                                    englim_tqidcred_swc_in,
                                    ext_neng_swc_in,
                                    ext_stgbxcf_swc_in,
                                    ext_titdc_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(idlsys_bacvantistall_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(idlsys_bacvidlctl_swc_in),
                                    idlsys_tqidcidl_swc_in,
                                    tqcmp_tqsumlosscmp_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvantistallaut_irv_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvantistallman_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bidlacv_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                    tqsys_facreqexhtempprot_swc_in,
                                    tqsys_facreqfuelrundry_swc_in,
                                    tqsys_ntaridl_swc_in,
                                    tqsys_tqckantistall_swc_in,
                                    tqsys_tqckidl_swc_in,
                                    tqsys_tqidclvlsbpa_swc_in,
                                    tqsys_tqidcsbpa_swc_in,
                                    &tqsys_bacvantistall_swc_out,
                                    &tqsys_bengnonidl_swc_out,
                                    &tqsys_benguhnonidl_swc_out,
                                    &tqsys_bidlacvcmn_swc_out,
                                    &tqsys_tqckidlcmn_swc_out,
                                    &tqsys_tqckidlcord_swc_out,
                                    &tqsys_tqidcengidlcord_swc_out,
                                    &tqsys_tqidcenglimcord_swc_out,
                                    &IdlSys_tqIdcIdlAirSBPA_irv_MP,
                                    &tqsys_tqidccoldsmkcord_swc_out);



        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I404(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_IdlCordLim_IdlSys_tqIdcIdlAirSBPA_irv(IdlSys_tqIdcIdlAirSBPA_irv_MP);
    }
    else
    {
        tqsys_bacvantistall_swc_out = TqSys_bAcvAntiStall_B;
        tqsys_bengnonidl_swc_out = TqSys_bEngNOnIdl_B;
        tqsys_benguhnonidl_swc_out = TqSys_bEngUHNOnIdl_B;
        tqsys_bidlacvcmn_swc_out = TqSys_bIdlAcvCmn_B;
        tqsys_tqckidlcmn_swc_out = TqSys_tqCkIdlCmn_B;
        tqsys_tqckidlcord_swc_out = TqSys_tqCkIdlCord_B;
        tqsys_tqidcengidlcord_swc_out = TqSys_tqIdcEngIdlCord_B;
        tqsys_tqidcenglimcord_swc_out = TqSys_tqIdcEngLimCord_B;
        tqsys_tqidccoldsmkcord_swc_out = TqSys_tqIdcColdSmkCord_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_OUT_003 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvAntiStall_TqSys_bAcvAntiStall(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvantistall_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_004 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bengnonidl_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_005 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bEngUHNOnIdl_TqSys_bEngUHNOnIdl(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_benguhnonidl_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_006 */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bIdlAcvCmn_TqSys_bIdlAcvCmn(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bidlacvcmn_swc_out));
    /* SSTG_REQ_TAG: DDS_REQ_OUT_007 */
    Rte_Write_P_TqSys_tqCkIdlCmn_TqSys_tqCkIdlCmn(tqsys_tqckidlcmn_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_008 */
    Rte_Write_P_TqSys_tqCkIdlCord_TqSys_tqCkIdlCord(tqsys_tqckidlcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_012 */
    Rte_Write_P_TqSys_tqIdcEngIdlCord_TqSys_tqIdcEngIdlCord(tqsys_tqidcengidlcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_013 */
    Rte_Write_P_TqSys_tqIdcEngLimCord_TqSys_tqIdcEngLimCord(tqsys_tqidcenglimcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_026 */
    Rte_Write_P_TqSys_tqIdcColdSmkCord_TqSys_tqIdcColdSmkCord(tqsys_tqidccoldsmkcord_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_IdlCordLim
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_IdlCordLim(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 copt_tqidcaircord_ncross_swc_in;
    SInt16 copt_tqidcairdslcord_nreg_swc_in;
    SInt16 englim_tqidcred_swc_in;
    SInt16 idlsys_tqidcairidl_swc_in;
    SInt16 tqres_tqmaxres_swc_in;
    Boolean tqsys_btypfu_swc_in;
    SInt16 tqsys_tqckidlcord_swc_in;
   /* IRV */
    SInt16 englim_tqidcairlim_irv_in;
    SInt16 englim_tqidcairlimafterres_irv_in;

    SInt16 idlsys_tqidcidlairsbpa_irv_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqsys_tqidcairengidlcord_swc_out;
    SInt16 tqsys_tqidcairrequnlim_swc_out;
    SInt16 tqsys_tqidcairenglimcord_swc_out;
    SInt16 tqsys_tqidcairlimcordwires_swc_out;
    SInt16 tqsys_tqidcairlimcordwoutres_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)COCLLASL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: DDS_REQ_INP_004 */
        Rte_Read_R_CoPt_tqIdcAirCord_nCross_CoPt_tqIdcAirCord_nCross(&copt_tqidcaircord_ncross_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_005 */
        Rte_Read_R_CoPt_tqIdcAirDslCord_nReg_CoPt_tqIdcAirDslCord_nReg(&copt_tqidcairdslcord_nreg_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_011 */
        Rte_Read_R_EngLim_tqIdcRed_EngLim_tqIdcRed(&englim_tqidcred_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_017 */
        Rte_Read_R_IdlSys_tqIdcAirIdl_IdlSys_tqIdcAirIdl(&idlsys_tqidcairidl_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_020 */
        Rte_Read_R_TqRes_tqMaxRes_TqRes_tqMaxRes(&tqres_tqmaxres_swc_in);
        /* SSTG_REQ_TAG: DDS_REQ_INP_022 */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I403(0) */
        Rte_Read_R_TqSys_tqCkIdlCord_TqSys_tqCkIdlCord(&tqsys_tqckidlcord_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I400(0) */
        englim_tqidcairlim_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_IdlCordLim_EngLim_tqIdcAirLim_irv();
        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I401(0) */
        englim_tqidcairlimafterres_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_IdlCordLim_EngLim_tqIdcAirLimAfterRes_irv();

        /* SSTG_REQ_TAG: 01552_10_01788-CoClLASl.I404(0) */
        idlsys_tqidcidlairsbpa_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_IdlCordLim_IdlSys_tqIdcIdlAirSBPA_irv();


        COCLLASL_Idl_Coord_Lim( copt_tqidcaircord_ncross_swc_in,
                                copt_tqidcairdslcord_nreg_swc_in,
                                englim_tqidcairlim_irv_in,
                                englim_tqidcairlimafterres_irv_in,
                                englim_tqidcred_swc_in,
                                idlsys_tqidcairidl_swc_in,
                                tqres_tqmaxres_swc_in,
                                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                                tqsys_tqckidlcord_swc_in,
                                idlsys_tqidcidlairsbpa_irv_in,
                                &tqsys_tqidcairengidlcord_swc_out,
                                &tqsys_tqidcairenglimcord_swc_out,
                                &tqsys_tqidcairlimcordwires_swc_out,
                                &tqsys_tqidcairlimcordwoutres_swc_out,
                                &tqsys_tqidcairrequnlim_swc_out);


        /* IRV OUTPUT */
    }
    else
    {
        tqsys_tqidcairengidlcord_swc_out = TqSys_tqIdcAirEngIdlCord_B;
        tqsys_tqidcairrequnlim_swc_out = TqSys_tqIdcAirReqUnlim_B;
        tqsys_tqidcairenglimcord_swc_out = TqSys_tqIdcAirEngLimCord_B;
        tqsys_tqidcairlimcordwires_swc_out = TqSys_tqIdcAirLimCordWiRes_B;
        tqsys_tqidcairlimcordwoutres_swc_out = TqSys_tqIdcAirLimCordWoutRes_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: DDS_REQ_OUT_001 */
    Rte_Write_P_TqSys_tqIdcAirEngIdlCord_TqSys_tqIdcAirEngIdlCord(tqsys_tqidcairengidlcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_002 */
    Rte_Write_P_TqSys_tqIdcAirReqUnlim_TqSys_tqIdcAirReqUnlim(tqsys_tqidcairrequnlim_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_009 */
    Rte_Write_P_TqSys_tqIdcAirEngLimCord_TqSys_tqIdcAirEngLimCord(tqsys_tqidcairenglimcord_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_010 */
    Rte_Write_P_TqSys_tqIdcAirLimCordWiRes_TqSys_tqIdcAirLimCordWiRes(tqsys_tqidcairlimcordwires_swc_out);
    /* SSTG_REQ_TAG: DDS_REQ_OUT_011 */
    Rte_Write_P_TqSys_tqIdcAirLimCordWoutRes_TqSys_tqIdcAirLimCordWoutRes(tqsys_tqidcairlimcordwoutres_swc_out);

}

/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : CoClLASl_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) CoClLASl_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_CoClLASl_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define COCLLASL_STOP_SEC_CODE
#include "CoClLASl_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 7.10
* Date: 10/12/2013 13:50:31
* PERL v5.14.2
* Lib_CC 1.37
* Lib_Clipboard 1.01
* Lib_Code_Writer 1.00
* Lib_CQ 1.22
* Lib_DD_Check 2.13
* Lib_DD_Check_Checks 1.51
* Lib_DD_Check_Data 2.10
* Lib_DD_Check_Utils 2.14
* Lib_DD_Compare 1.11
* Lib_DD_GenCode 3.31
* Lib_DD_Load 3.11
* Lib_DD_Structure 1.11
* Lib_Feature 1.03
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.03
* Lib_Gui_ComboBox 1.07
* Lib_Gui_Common 1.43
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.02
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.18
* Lib_Hash 1.33
* Lib_Log 1.32
* Lib_Maths 1.10
* Lib_Pjt 1.32
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.30
* Lib_Scheduler_XML 1.50
* Lib_Spectool_Gen_DD 2.33
* Lib_Twk 1.06
* Lib_Utils 1.06
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.09
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* LOCAL_SECTION *
COCLLASL_ACTIVE_BYP_C ;["FALSE"*0*|"TRUE"*1*] ;COCLLASL ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;"FALSE" ;Bypass ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoClLASl_ModuleVersion_Major_MP ; ;COCLLASL ;N/A ;0 ;255 ;1 ;["COMP"] ;["N/A"] ;N/A ;N/A ;N/A ;13 ;CoClLASl_ModuleVersion_Major_MP ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoClLASl_ModuleVersion_Minor_MP ; ;COCLLASL ;N/A ;0 ;255 ;1 ;["COMP"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;CoClLASl_ModuleVersion_Minor_MP ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_bAcvAntiStallFil_B ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoPt_bAcvAntiStallFil ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
ESLim_bAcvEngSpdLim_B ;["FALSE"|"TRUE"] ;ESLIM ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de ESLim_bAcvEngSpdLim ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqCkCurDrivFil_B ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Bypass de EngLim_tqCkCurDrivFil ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcAirLimAfterRes_irv ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple de limitation apres la coordination des reserves sur la branche air ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcAirLim_irv_MP ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple de limitation apres la coodination du ralenti sur la branche air ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcEngLimMax_B ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Bypass de EngLim_tqIdcEngLimMax ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcLim_B ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Bypass de EngLim_tqIdcLim ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcMaxNReg_B ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Bypass de EngLim_tqIdcMaxNReg ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
IdlSys_tqIdcIdlAirSBPA_irv_MP ; ;IDLSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Amplitude de la correction de la fonction SBPA Air apres activation ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCll_bAcvCll_B ;["FALSE"|"TRUE"] ;TQCLL ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqCll_bAcvCll ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCll_bForcCll_B ;["FALSE"|"TRUE"] ;TQCLL ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqCll_bForcCll ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCll_bReqCllPtl_B ;["FALSE"|"TRUE"] ;TQCLL ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqCll_bReqCllPtl ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallAut_irv_MP ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag d activation de la strategie d anti-calage BVA/BVMP utilisee par la strategie IVC ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallMan_B ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bAcvAntiStallSmk ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallSmk_B ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bAcvAntiStallSmk ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStall_B ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Bypass de TqSys_bAcvAntiStall ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bEngNOnIdl_B ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Bypass de TqSys_bEngNOnIdl ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bEngUHNOnIdl_B ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Bypass de TqSys_bEngUHNOnIdl ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bIdlAcvCmn_B ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Bypass de TqSys_bIdlAcvCmn ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facAntiStall1_B ; ;TQS ;Nm/rpm ;0 ;1 ;1/16384 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_facAntiStall1 ;["YES"] ;UInt16 ;BIN14 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facAntiStall2_B ; ;TQSYS ;Nm/rpm ;0 ;1 ;1/16384 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_facAntiStall2 ;["YES"] ;UInt16 ;BIN14 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facAntiStall3_B ; ;TQSYS ;Nm/rpm ;0 ;1 ;1/16384 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_facAntiStall3 ;["YES"] ;UInt16 ;BIN14 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facTqCkAntiStall_B ; ;TQSYS ;N/A ;0 ;2 ;1/1024 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_facTqCkAntiStall ;["YES"] ;UInt16 ;BIN10 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkAOSCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqCkAOSCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkAntiStall_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEngLimCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqCkEngLimCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkIdlCmn_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqCkIdlCmn ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkIdlCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqCkIdlCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcAirEngIdlCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcAirEngIdlCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcAirEngLimCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcAirEngLimCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcAirLimCordWiRes_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcAirLimCordWiRes ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcAirLimCordWoutRes_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcAirLimCordWoutRes ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcAirReqUnlim_B ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcAirReqUnlim ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcColdSmkCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcColdSmkCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcEngIdlCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcEngIdlCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcEngLimCord_B ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIdcEngLimCord ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

