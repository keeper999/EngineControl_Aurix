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
* Ref X:\integration_view_00PSASWC_D822D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSp.c
* Version int :/main/00PSASWC_D8/6 Date: 18/10/2012 14 h 47 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :Update version of software component to 12.2
* Version dev :\main\branch_girodon_module_dev\1 Date: 16/10/2012 16 h 44 m User:girodon 
*    TWK_model:NO_MODEL
*    comments :Update version of software component to 12.2
* Version int :/main/00PSASWC_D8/5 Date: 11/4/2012 15 h 13 m User:meme 
*    TWK_model:NO_MODEL
*    comments :For VSSp_12_1_e6
* Version dev :\main\branch_halouane_vssp_euro6\1 Date: 11/4/2012 11 h 45 m User:halouane 
*    TWK_model:NO_MODEL
*    comments :For VSSp_12_1_e6
* Version int :/main/00PSASWC_D8/4 Date: 6/1/2012 11 h 10 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version dev :\main\branch_moisan_module_dev\1 Date: 4/1/2012 15 h 46 m User:moisan
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 30/11/2011 11 h 16 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 12.0
* Version int :/main/00PSASWC_D8/3 Date: 7/9/2011 16 h 39 m User:esnault
*    TWK_model:NO_MODEL
*    comments :corrections on runnables 001 and 004
* Version dev :\main\branch_demezil_vssp_view\7 Date: 7/9/2011 15 h 40 m User:demezil
*    TWK_model:NO_MODEL
*    comments :corrections on runnables 001 and 004
* Version dev :\main\branch_demezil_vssp_view\6 Date: 24/8/2011 11 h 39 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\5 Date: 4/8/2011 17 h 15 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\4 Date: 1/8/2011 17 h 7 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for VSSp 11.0
*
*******************************************************************************/

/* File generated with swc_main_code_generator Version 1.00 */

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "VSSp.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if VSSP_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
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
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPEngMax_B = (CONST(UInt16, AUTOMATIC))(100 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPEngMin_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPPTMax_B = (CONST(UInt16, AUTOMATIC))(100 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPPTMin_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMax_B = (CONST(UInt16, AUTOMATIC))(100 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTraMin_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnReq_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupReq_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxReq_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinReq_B = (CONST(SInt16, AUTOMATIC))(-2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxReq_B = (CONST(SInt16, AUTOMATIC))(11000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinReq_B = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinSat_B = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxReq_B = (CONST(SInt16, AUTOMATIC))(11000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinReq_B = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotReq_B = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqEfcTarMin_B = (CONST(SInt16, AUTOMATIC))(-2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqEfcTarMax_B = (CONST(SInt16, AUTOMATIC))(2000 * BIN4);
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) RE_VSSP_002_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_VSSP_003_TEV_B = DDS_FALSE;

STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAcvTqWhlPTMinSat_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqCkEfcMax_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqCkEfcMin_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPTMax_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPTMin_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bInhRecup_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearReqMax_B = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_noGearReqMin_B = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stCtl_noGear_B = VSSP_VSCTL_STCTL_NOGEAR_ARRET;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stGearCtlReq_B = VSSP_VSCTL_STGEARCTLREQ_NON_DEMANDE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqPTMaxCtl_B = VSSP_VSCTL_STTQPTCTL_INACTIF;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqPTMinCtl_B = VSSP_VSCTL_STTQPTCTL_INACTIF;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqWhlPTCutOffReq_B = VSSP_VSCTL_STTQWHLPTCUTOFFREQ_ARRET_INDETERMINE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqWhlPTPotCtlReq_B = VSSP_VSCTL_STTQWHLPTPOTCTLREQ_NON_DEMANDE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPT_pt1_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPT_pt2_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqPTMaxCtl_pt1_B = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqPTMaxCtl_pt2_B = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqPTMinCtl_pt1_B = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stTqPTMinCtl_pt2_B = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
#define VSSP_STOP_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"

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

/* 8-bits variable definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPT_pt1;
STATIC VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqWhlPT_pt2;
STATIC VAR(UInt8, AUTOMATIC) VSCtl_stTqPTMaxCtl_pt1;
STATIC VAR(UInt8, AUTOMATIC) VSCtl_stTqPTMaxCtl_pt2;
STATIC VAR(UInt8, AUTOMATIC) VSCtl_stTqPTMinCtl_pt1;
STATIC VAR(UInt8, AUTOMATIC) VSCtl_stTqPTMinCtl_pt2;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define VSSP_START_SEC_CONST_VERSION_MODULE_8BIT
#include "VSSp_MemMap.h"
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) VSSp_ModuleVersion_Major_MP = (UInt8)12;
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) VSSp_ModuleVersion_Minor_MP = (UInt8)2;
#define VSSP_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_VSSp_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_VSSp_001_MSE(void)
{
    /* OUTPUT */
    /* SWC OUT */
    UInt8 vsctl_bacvtqwhlptminsat_swc_out;
    UInt8 vsctl_bctlefc_tqckefcmax_swc_out;
    UInt8 vsctl_bctlefc_tqckefcmin_swc_out;
    UInt8 vsctl_bctlefc_tqwhlpt_swc_out;
    UInt8 vsctl_bctlefc_tqwhlptmax_swc_out;
    UInt8 vsctl_bctlefc_tqwhlptmin_swc_out;
    UInt8 vsctl_binhrecup_swc_out;
    UInt8 vsctl_nogearreqmax_swc_out;
    UInt8 vsctl_nogearreqmin_swc_out;
    UInt16 vsctl_raccpengmax_swc_out;
    UInt16 vsctl_raccpengmin_swc_out;
    UInt16 vsctl_raccpptmax_swc_out;
    UInt16 vsctl_raccpptmin_swc_out;
    UInt16 vsctl_raccptramax_swc_out;
    UInt16 vsctl_raccptramin_swc_out;
    UInt8 vsctl_stctl_nogear_swc_out;
    UInt8 vsctl_stgearctlreq_swc_out;
    UInt8 vsctl_sttqptmaxctl_swc_out;
    UInt8 vsctl_sttqptminctl_swc_out;
    UInt8 vsctl_sttqwhlptcutoffreq_swc_out;
    UInt8 vsctl_sttqwhlptpotctlreq_swc_out;
    UInt16 vsctl_ticfmsdwnreq_swc_out;
    UInt16 vsctl_ticfmsupreq_swc_out;
    SInt16 vsctl_tqckefcmaxreq_swc_out;
    SInt16 vsctl_tqckefcminreq_swc_out;
    SInt16 vsctl_tqwhlptmaxreq_swc_out;
    SInt16 vsctl_tqwhlptminreq_swc_out;
    SInt16 vsctl_tqwhlptminsat_swc_out;
    SInt16 vsctl_tqwhlptpotmaxreq_swc_out;
    SInt16 vsctl_tqwhlptpotminreq_swc_out;
    SInt16 vsctl_tqwhlptpotreq_swc_out;
    SInt16 vsctl_tqefctarmin_swc_out;
    SInt16 vsctl_tqefctarmax_swc_out;

    /* for cold reset, init of 2 NV */
    VSSP_Control_Wheel_Gmp1_Sl_Cinit();
    VSSP_Control_Wheel_Gmp2_Sl_Cinit();

    VSSP_Torque_Control_Gmp1_Sf_Init(
                                    &vsctl_sttqwhlptcutoffreq_swc_out,
                                    &VSCtl_bCtlEfc_tqWhlPT_pt1,
                                    &vsctl_bctlefc_tqwhlptmin_swc_out,
                                    &VSCtl_stTqPTMinCtl_pt1,
                                    &vsctl_bctlefc_tqwhlptmax_swc_out,
                                    &vsctl_bacvtqwhlptminsat_swc_out,
                                    &VSCtl_stTqPTMaxCtl_pt1,
                                    &vsctl_tqwhlptminreq_swc_out,                          /*BIN1*/
                                    &vsctl_tqwhlptminsat_swc_out,                          /*BIN1*/
                                    &vsctl_raccpptmin_swc_out,                             /*BIN7*/
                                    &vsctl_tqwhlptmaxreq_swc_out,                          /*BIN1*/
                                    &vsctl_raccpptmax_swc_out);                             /*BIN7*/


    VSSP_Torque_Control_Gmp2_Sf_Init(   &vsctl_tqwhlptpotmaxreq_swc_out,
                                        &vsctl_bctlefc_tqckefcmin_swc_out,
                                        &vsctl_ticfmsdwnreq_swc_out,
                                        &vsctl_sttqwhlptpotctlreq_swc_out,
                                        &vsctl_bctlefc_tqckefcmax_swc_out,
                                        &VSCtl_bCtlEfc_tqWhlPT_pt2,
                                        &vsctl_tqefctarmin_swc_out,
                                        &vsctl_binhrecup_swc_out,
                                        &vsctl_tqefctarmax_swc_out,
                                        &vsctl_raccpengmin_swc_out,
                                        &vsctl_raccpengmax_swc_out,
                                        &VSCtl_stTqPTMinCtl_pt2,
                                        &vsctl_tqckefcminreq_swc_out,
                                        &VSCtl_stTqPTMaxCtl_pt2,
                                        &vsctl_tqwhlptpotreq_swc_out,
                                        &vsctl_tqckefcmaxreq_swc_out,
                                        &vsctl_tqwhlptpotminreq_swc_out,
                                        &vsctl_ticfmsupreq_swc_out);


    VSSP_Det_Gearbox_Pedal_Sf_Init(
                                    &vsctl_stctl_nogear_swc_out,
                                    &vsctl_raccptramax_swc_out, /* BIN7 */
                                    &vsctl_nogearreqmin_swc_out,
                                    &vsctl_stgearctlreq_swc_out,
                                    &vsctl_nogearreqmax_swc_out,
                                    &vsctl_raccptramin_swc_out); /* BIN7 */


    VSSP_Effec_Process_Xvv_Init(
                                    &vsctl_bctlefc_tqwhlpt_swc_out,
                                    &vsctl_sttqptmaxctl_swc_out,
                                    &vsctl_sttqptminctl_swc_out);

    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I060(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAcvTqWhlPTMinSat_VSCtl_bAcvTqWhlPTMinSat(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bacvtqwhlptminsat_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I061(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqCkEfcMax_VSCtl_bCtlEfc_tqCkEfcMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqckefcmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I062(1) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqCkEfcMin_VSCtl_bCtlEfc_tqCkEfcMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqckefcmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I064(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPTMax_VSCtl_bCtlEfc_tqWhlPTMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlptmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I065(1) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPTMin_VSCtl_bCtlEfc_tqWhlPTMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlptmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I063(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPt_VSCtl_bCtlEfc_tqWhlPt(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlpt_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I066(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bInhRecup_VSCtl_bInhRecup(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_binhrecup_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I067(0) */
    Rte_Write_P_VSCtl_noGearReqMax_VSCtl_noGearReqMax(vsctl_nogearreqmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I068(0) */
    Rte_Write_P_VSCtl_noGearReqMin_VSCtl_noGearReqMin(vsctl_nogearreqmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I069(0) */
    Rte_Write_P_VSCtl_rAccPEngMax_VSCtl_rAccPEngMax(vsctl_raccpengmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I070(0) */
    Rte_Write_P_VSCtl_rAccPEngMin_VSCtl_rAccPEngMin(vsctl_raccpengmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I071(0) */
    Rte_Write_P_VSCtl_rAccPPTMax_VSCtl_rAccPPTMax(vsctl_raccpptmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I072(0) */
    Rte_Write_P_VSCtl_rAccPPTMin_VSCtl_rAccPPTMin(vsctl_raccpptmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I073(0) */
    Rte_Write_P_VSCtl_rAccPTraMax_VSCtl_rAccPTraMax(vsctl_raccptramax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I074(0) */
    Rte_Write_P_VSCtl_rAccPTraMin_VSCtl_rAccPTraMin(vsctl_raccptramin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I075(0) */
    Rte_Write_P_VSCtl_stCtl_noGear_VSCtl_stCtl_noGear(vsctl_stctl_nogear_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I076(0) */
    Rte_Write_P_VSCtl_stGearCtlReq_VSCtl_stGearCtlReq(vsctl_stgearctlreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I077(0) */
    Rte_Write_P_VSCtl_stTqPTMaxCtl_VSCtl_stTqPTMaxCtl(vsctl_sttqptmaxctl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I078(0) */
    Rte_Write_P_VSCtl_stTqPTMinCtl_VSCtl_stTqPTMinCtl(vsctl_sttqptminctl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I079(0) */
    Rte_Write_P_VSCtl_stTqWhlPTCutOffReq_VSCtl_stTqWhlPTCutOffReq(vsctl_sttqwhlptcutoffreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I080(0) */
    Rte_Write_P_VSCtl_stTqWhlPTPotCtlReq_VSCtl_stTqWhlPTPotCtlReq(vsctl_sttqwhlptpotctlreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I081(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnReq_VSCtl_tiCfmSdwnReq(vsctl_ticfmsdwnreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I082(0) */
    Rte_Write_P_VSCtl_tiCfmSupReq_VSCtl_tiCfmSupReq(vsctl_ticfmsupreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I083(0) */
    Rte_Write_P_VSCtl_tqCkEfcMaxReq_VSCtl_tqCkEfcMaxReq(vsctl_tqckefcmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I084(0) */
    Rte_Write_P_VSCtl_tqCkEfcMinReq_VSCtl_tqCkEfcMinReq(vsctl_tqckefcminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I201(0) */
    Rte_Write_P_VSCtl_tqEfcTarMax_VSCtl_tqEfcTarMax(vsctl_tqefctarmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I200(0) */
    Rte_Write_P_VSCtl_tqEfcTarMin_VSCtl_tqEfcTarMin(vsctl_tqefctarmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I085(0) */
    Rte_Write_P_VSCtl_tqWhlPTMaxReq_VSCtl_tqWhlPTMaxReq(vsctl_tqwhlptmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I086(0) */
    Rte_Write_P_VSCtl_tqWhlPTMinReq_VSCtl_tqWhlPTMinReq(vsctl_tqwhlptminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I087(0) */
    Rte_Write_P_VSCtl_tqWhlPTMinSat_VSCtl_tqWhlPTMinSat(vsctl_tqwhlptminsat_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I088(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotMaxReq_VSCtl_tqWhlPTPotMaxReq(vsctl_tqwhlptpotmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I089(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotMinReq_VSCtl_tqWhlPTPotMinReq(vsctl_tqwhlptpotminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I090(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotReq_VSCtl_tqWhlPTPotReq(vsctl_tqwhlptpotreq_swc_out);

    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I093(3) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_VSSp_001_MSE_VSCtl_bCtlEfc_tqWhlPT_pt1(DDS_M_CONVERT_UINT8_TO_BOOL(VSCtl_bCtlEfc_tqWhlPT_pt1));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I094(3) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_VSSp_001_MSE_VSCtl_bCtlEfc_tqWhlPT_pt2(DDS_M_CONVERT_UINT8_TO_BOOL(VSCtl_bCtlEfc_tqWhlPT_pt2));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I095(3) */
    Rte_IrvWrite_RE_VSSp_001_MSE_VSCtl_stTqPTMaxCtl_pt1(VSCtl_stTqPTMaxCtl_pt1);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I096(3) */
    Rte_IrvWrite_RE_VSSp_001_MSE_VSCtl_stTqPTMaxCtl_pt2(VSCtl_stTqPTMaxCtl_pt2);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I097(3) */
    Rte_IrvWrite_RE_VSSp_001_MSE_VSCtl_stTqPTMinCtl_pt1(VSCtl_stTqPTMinCtl_pt1);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I098(3) */
    Rte_IrvWrite_RE_VSSp_001_MSE_VSCtl_stTqPTMinCtl_pt2(VSCtl_stTqPTMinCtl_pt2);
}
/*******************************************************************************
*
*  Runnable Name    : RE_VSSp_002_TEV
*  Event            : Every 0.01
*  Description      : Call  scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_VSSp_002_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 accp_raccp_swc_in;
    UInt8 ext_stctlcmdpttqpotcf_swc_in;
    UInt8 tra_stgearctl_swc_in;
    SInt16 vsctl_avehdvsregreq_swc_in;
    Boolean vsctl_bauthanttqwhlmax_swc_in;
    Boolean vsctl_bauthanttqwhlmin_swc_in;
    Boolean vsctl_bctlatqpt_swc_in;
    Boolean vsctl_bfastdeacvslimreq_swc_in;
    Boolean vsctl_blgtctldyn_swc_in;
    Boolean vsctl_btqwhlminsat_swc_in;
    UInt32 vsctl_nengfil_swc_in;
    UInt32 vsctl_nfrntwhlfil_swc_in;
    UInt16 vsctl_rconvtra_swc_in;
    UInt16 vsctl_spdveh_swc_in;
    SInt16 vsctl_spdveherrvslim_swc_in;
    SInt16 vsctl_spdveherrvsmax_swc_in;
    SInt16 vsctl_spdveherrvsreg_swc_in;
    Boolean vsctl_stctl_avehdvsreg_swc_in;
    UInt8 vsctl_stctl_avehvslim_swc_in;
    UInt8 vsctl_stctl_avehvsmax_swc_in;
    UInt8 vsctl_stctl_avehvsreg_swc_in;
    Boolean vsctl_stctl_tqwhlmax_swc_in;
    Boolean vsctl_stctl_tqwhlmin_swc_in;
    Boolean vsctl_stctl_tqwhlpot_swc_in;
    UInt8 vsctl_stctl_tqwhlpotmax_swc_in;
    UInt8 vsctl_stctl_tqwhlpotmin_swc_in;
    UInt16 vsctl_ticfmsdwntqmaxreq_swc_in;
    UInt16 vsctl_ticfmsdwntqminreq_swc_in;
    UInt16 vsctl_ticfmsuptqmaxreq_swc_in;
    UInt16 vsctl_ticfmsuptqminreq_swc_in;
    SInt16 vsctl_tqckefcdrvmaxreq_swc_in;
    SInt16 vsctl_tqckefcdrvminreq_swc_in;
    SInt16 vsctl_tqckefcmax_swc_in;
    SInt16 vsctl_tqckefcmaxnotctla_swc_in;
    SInt16 vsctl_tqckefcmin_swc_in;
    SInt16 vsctl_tqckefcminnotctla_swc_in;
    SInt16 vsctl_tqckefcprecovscminreq_swc_in;
    SInt16 vsctl_tqckefcprecovsctlreq_swc_in;
    SInt16 vsctl_tqlosstra_swc_in;
    SInt16 vsctl_tqwhlmaxreq_swc_in;
    SInt16 vsctl_tqwhlminreq_swc_in;
    SInt16 vsctl_tqwhlminsat_swc_in;
    SInt16 vsctl_tqwhlpotmaxreq_swc_in;
    SInt16 vsctl_tqwhlpotminreq_swc_in;
    SInt16 vsctl_tqwhlpotreq_swc_in;
    SInt16 vsctl_tqwhlptdrvmaxreq_swc_in;
    SInt16 vsctl_tqwhlptdrvminreq_swc_in;
    SInt16 vsctl_tqwhlptdrvminreqraw_swc_in;
    SInt16 vsctl_tqwhlptmax_swc_in;
    SInt16 vsctl_tqwhlptmaxnotctla_swc_in;
    SInt16 vsctl_tqwhlptmin_swc_in;
    SInt16 vsctl_tqwhlptminnotctla_swc_in;
    SInt16 vsctl_tqwhlptpotrawmax_swc_in;
    SInt16 vsctl_tqwhlptpotrawmin_swc_in;
    SInt16 vsctl_tqwhlptprecovscmaxreq_swc_in;
    SInt16 vsctl_tqwhlptprecovscminreq_swc_in;
    SInt16 vsctl_tqwhlptprecovsctlreq_swc_in;
    SInt8 copt_notargearcordit_swc_in;
    UInt16 copt_nprimshafttar_swc_in;
    UInt32 ext_nfrntwhl_swc_in;
    UInt8 ext_sttratypcf_swc_in;
    Boolean vsctl_bavltqwhlpt_no3_swc_in;
    /* FIM (FRM) */
    Boolean vssp_bool_temp;
    Boolean frm_bdeacvsctlgearctl_fim_in;
    /* OUTPUT */
    /* SWC OUT */
    UInt8 vsctl_bacvtqwhlptminsat_swc_out;
    UInt8 vsctl_bctlefc_tqckefcmax_swc_out;
    UInt8 vsctl_bctlefc_tqckefcmin_swc_out;
    UInt8 vsctl_bctlefc_tqwhlptmax_swc_out;
    UInt8 vsctl_bctlefc_tqwhlptmin_swc_out;
    UInt8 vsctl_binhrecup_swc_out;
    UInt8 vsctl_nogearreqmax_swc_out;
    UInt8 vsctl_nogearreqmin_swc_out;
    UInt16 vsctl_raccpengmax_swc_out;
    UInt16 vsctl_raccpengmin_swc_out;
    UInt16 vsctl_raccpptmax_swc_out;
    UInt16 vsctl_raccpptmin_swc_out;
    UInt16 vsctl_raccptramax_swc_out;
    UInt16 vsctl_raccptramin_swc_out;
    UInt8 vsctl_stctl_nogear_swc_out;
    UInt8 vsctl_stgearctlreq_swc_out;
    UInt8 vsctl_sttqwhlptcutoffreq_swc_out;
    UInt8 vsctl_sttqwhlptpotctlreq_swc_out;
    UInt16 vsctl_ticfmsdwnreq_swc_out;
    UInt16 vsctl_ticfmsupreq_swc_out;
    SInt16 vsctl_tqckefcmaxreq_swc_out;
    SInt16 vsctl_tqckefcminreq_swc_out;
    SInt16 vsctl_tqwhlptmaxreq_swc_out;
    SInt16 vsctl_tqwhlptminreq_swc_out;
    SInt16 vsctl_tqwhlptminsat_swc_out;
    SInt16 vsctl_tqwhlptpotmaxreq_swc_out;
    SInt16 vsctl_tqwhlptpotminreq_swc_out;
    SInt16 vsctl_tqwhlptpotreq_swc_out;
    SInt16 vsctl_tqefctarmin_swc_out;
    SInt16 vsctl_tqefctarmax_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_VSSP_002_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I001(1) */
        Rte_Read_R_AccP_rAccP_AccP_rAccP(&accp_raccp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I203(0) */
        Rte_Read_R_CoPt_nPrimShaftTar_CoPt_nPrimShaftTar(&copt_nprimshafttar_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I202(0) */
        Rte_Read_R_CoPt_noTarGearCordIt_CoPt_noTarGearCordIt(&copt_notargearcordit_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I204(0) */
        Rte_Read_R_Ext_nFrntWhl_Ext_nFrntWhl(&ext_nfrntwhl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I004(0) */
        Rte_Read_R_Ext_stCtlCmdPTTqPotCf_Ext_stCtlCmdPTTqPotCf(&ext_stctlcmdpttqpotcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I205(0) */
        Rte_Read_R_Ext_stTraTypCf_Ext_stTraTypCf(&ext_sttratypcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I005(0) */
        Rte_Read_R_Tra_stGearCtl_Tra_stGearCtl(&tra_stgearctl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I006(0) */
        Rte_Read_R_VSCtl_aVehDVSRegReq_VSCtl_aVehDVSRegReq(&vsctl_avehdvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I007(0) */
        Rte_Read_R_VSCtl_bAuthAntTqWhlMax_VSCtl_bAuthAntTqWhlMax(&vsctl_bauthanttqwhlmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I008(0) */
        Rte_Read_R_VSCtl_bAuthAntTqWhlMin_VSCtl_bAuthAntTqWhlMin(&vsctl_bauthanttqwhlmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I206(0) */
        Rte_Read_R_VSCtl_bAvlTqWhlPT_no3_VSCtl_bAvlTqWhlPT_no3(&vsctl_bavltqwhlpt_no3_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I009(0) */
        Rte_Read_R_VSCtl_bCtlaTqPT_VSCtl_bCtlaTqPT(&vsctl_bctlatqpt_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I010(0) */
        Rte_Read_R_VSCtl_bFastDeacVSLimReq_VSCtl_bFastDeacVSLimReq(&vsctl_bfastdeacvslimreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I011(0) */
        Rte_Read_R_VSCtl_bLgtCtlDyn_VSCtl_bLgtCtlDyn(&vsctl_blgtctldyn_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I012(0) */
        Rte_Read_R_VSCtl_bTqWhlMinSat_VSCtl_bTqWhlMinSat(&vsctl_btqwhlminsat_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I013(0) */
        Rte_Read_R_VSCtl_nEngFil_VSCtl_nEngFil(&vsctl_nengfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I014(0) */
        Rte_Read_R_VSCtl_nFrntWhlFil_VSCtl_nFrntWhlFil(&vsctl_nfrntwhlfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I015(0) */
        Rte_Read_R_VSCtl_rConvTra_VSCtl_rConvTra(&vsctl_rconvtra_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I016(0) */
        Rte_Read_R_VSCtl_spdVeh_VSCtl_spdVeh(&vsctl_spdveh_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I017(0) */
        Rte_Read_R_VSCtl_spdVehErrVSLim_VSCtl_spdVehErrVSLim(&vsctl_spdveherrvslim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I018(0) */
        Rte_Read_R_VSCtl_spdVehErrVSMax_VSCtl_spdVehErrVSMax(&vsctl_spdveherrvsmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I019(0) */
        Rte_Read_R_VSCtl_spdVehErrVSReg_VSCtl_spdVehErrVSReg(&vsctl_spdveherrvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I020(0) */
        Rte_Read_R_VSCtl_stCtl_aVehDVSReg_VSCtl_stCtl_aVehDVSReg(&vsctl_stctl_avehdvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I021(0) */
        Rte_Read_R_VSCtl_stCtl_aVehVSLim_VSCtl_stCtl_aVehVSLim(&vsctl_stctl_avehvslim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I022(0) */
        Rte_Read_R_VSCtl_stCtl_aVehVSMax_VSCtl_stCtl_aVehVSMax(&vsctl_stctl_avehvsmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I023(0) */
        Rte_Read_R_VSCtl_stCtl_aVehVSReg_VSCtl_stCtl_aVehVSReg(&vsctl_stctl_avehvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I024(0) */
        Rte_Read_R_VSCtl_stCtl_tqWhlMax_VSCtl_stCtl_tqWhlMax(&vsctl_stctl_tqwhlmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I025(0) */
        Rte_Read_R_VSCtl_stCtl_tqWhlMin_VSCtl_stCtl_tqWhlMin(&vsctl_stctl_tqwhlmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I026(0) */
        Rte_Read_R_VSCtl_stCtl_tqWhlPot_VSCtl_stCtl_tqWhlPot(&vsctl_stctl_tqwhlpot_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I027(1) */
        Rte_Read_R_VSCtl_stCtl_tqWhlPotMax_VSCtl_stCtl_tqWhlPotMax(&vsctl_stctl_tqwhlpotmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I028(1) */
        Rte_Read_R_VSCtl_stCtl_tqWhlPotMin_VSCtl_stCtl_tqWhlPotMin(&vsctl_stctl_tqwhlpotmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I029(0) */
        Rte_Read_R_VSCtl_tiCfmSdwnTqMaxReq_VSCtl_tiCfmSdwnTqMaxReq(&vsctl_ticfmsdwntqmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I030(0) */
        Rte_Read_R_VSCtl_tiCfmSdwnTqMinReq_VSCtl_tiCfmSdwnTqMinReq(&vsctl_ticfmsdwntqminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I031(0) */
        Rte_Read_R_VSCtl_tiCfmSupTqMaxReq_VSCtl_tiCfmSupTqMaxReq(&vsctl_ticfmsuptqmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I032(0) */
        Rte_Read_R_VSCtl_tiCfmSupTqMinReq_VSCtl_tiCfmSupTqMinReq(&vsctl_ticfmsuptqminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I033(0) */
        Rte_Read_R_VSCtl_tqCkEfcDrvMaxReq_VSCtl_tqCkEfcDrvMaxReq(&vsctl_tqckefcdrvmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I034(0) */
        Rte_Read_R_VSCtl_tqCkEfcDrvMinReq_VSCtl_tqCkEfcDrvMinReq(&vsctl_tqckefcdrvminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I035(0) */
        Rte_Read_R_VSCtl_tqCkEfcMax_VSCtl_tqCkEfcMax(&vsctl_tqckefcmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I036(0) */
        Rte_Read_R_VSCtl_tqCkEfcMaxNotCtla_VSCtl_tqCkEfcMaxNotCtla(&vsctl_tqckefcmaxnotctla_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I037(0) */
        Rte_Read_R_VSCtl_tqCkEfcMin_VSCtl_tqCkEfcMin(&vsctl_tqckefcmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I038(0) */
        Rte_Read_R_VSCtl_tqCkEfcMinNotCtla_VSCtl_tqCkEfcMinNotCtla(&vsctl_tqckefcminnotctla_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I039(0) */
        Rte_Read_R_VSCtl_tqCkEfcPreCoVSCMinReq_VSCtl_tqCkEfcPreCoVSCMinReq(&vsctl_tqckefcprecovscminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I040(0) */
        Rte_Read_R_VSCtl_tqCkEfcPreCoVSCtlReq_VSCtl_tqCkEfcPreCoVSCtlReq(&vsctl_tqckefcprecovsctlreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I041(0) */
        Rte_Read_R_VSCtl_tqLossTra_VSCtl_tqLossTra(&vsctl_tqlosstra_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I042(0) */
        Rte_Read_R_VSCtl_tqWhlMaxReq_VSCtl_tqWhlMaxReq(&vsctl_tqwhlmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I043(0) */
        Rte_Read_R_VSCtl_tqWhlMinReq_VSCtl_tqWhlMinReq(&vsctl_tqwhlminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I044(0) */
        Rte_Read_R_VSCtl_tqWhlMinSat_VSCtl_tqWhlMinSat(&vsctl_tqwhlminsat_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I048(0) */
        Rte_Read_R_VSCtl_tqWhlPTDrvMaxReq_VSCtl_tqWhlPTDrvMaxReq(&vsctl_tqwhlptdrvmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I049(0) */
        Rte_Read_R_VSCtl_tqWhlPTDrvMinReq_VSCtl_tqWhlPTDrvMinReq(&vsctl_tqwhlptdrvminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I050(0) */
        Rte_Read_R_VSCtl_tqWhlPTDrvMinReqRaw_VSCtl_tqWhlPTDrvMinReqRaw(&vsctl_tqwhlptdrvminreqraw_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I051(0) */
        Rte_Read_R_VSCtl_tqWhlPTMax_VSCtl_tqWhlPTMax(&vsctl_tqwhlptmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I052(0) */
        Rte_Read_R_VSCtl_tqWhlPTMaxNotCtla_VSCtl_tqWhlPTMaxNotCtla(&vsctl_tqwhlptmaxnotctla_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I053(0) */
        Rte_Read_R_VSCtl_tqWhlPTMin_VSCtl_tqWhlPTMin(&vsctl_tqwhlptmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I054(0) */
        Rte_Read_R_VSCtl_tqWhlPTMinNotCtla_VSCtl_tqWhlPTMinNotCtla(&vsctl_tqwhlptminnotctla_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I055(0) */
        Rte_Read_R_VSCtl_tqWhlPTPotRawMax_VSCtl_tqWhlPTPotRawMax(&vsctl_tqwhlptpotrawmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I056(0) */
        Rte_Read_R_VSCtl_tqWhlPTPotRawMin_VSCtl_tqWhlPTPotRawMin(&vsctl_tqwhlptpotrawmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I057(0) */
        Rte_Read_R_VSCtl_tqWhlPTPreCoVSCMaxReq_VSCtl_tqWhlPTPreCoVSCMaxReq(&vsctl_tqwhlptprecovscmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I058(0) */
        Rte_Read_R_VSCtl_tqWhlPTPreCoVSCMinReq_VSCtl_tqWhlPTPreCoVSCMinReq(&vsctl_tqwhlptprecovscminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I059(0) */
        Rte_Read_R_VSCtl_tqWhlPTPreCoVSCtlReq_VSCtl_tqWhlPTPreCoVSCtlReq(&vsctl_tqwhlptprecovsctlreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I045(0) */
        Rte_Read_R_VSCtl_tqWhlPotMaxReq_VSCtl_tqWhlPotMaxReq(&vsctl_tqwhlpotmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I046(0) */
        Rte_Read_R_VSCtl_tqWhlPotMinReq_VSCtl_tqWhlPotMinReq(&vsctl_tqwhlpotminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I047(0) */
        Rte_Read_R_VSCtl_tqWhlPotReq_VSCtl_tqWhlPotReq(&vsctl_tqwhlpotreq_swc_in);

        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I092(0) */
        Rte_Call_R_FRM_bDeacVSCtlGearCtl_GetFunctionPermission(&vssp_bool_temp);
        frm_bdeacvsctlgearctl_fim_in = ((UInt32)vssp_bool_temp == (UInt32)DDS_FALSE);

        /* SSTG_REQ_TAG: CSMT_CGMT08_2274.FR.01.5 */


        VSSP_Torque_Control_Gmp1_Sf(
                                    vsctl_tqwhlptdrvminreqraw_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_blgtctldyn_swc_in),
                                    vsctl_tqwhlptmin_swc_in,
                                    vsctl_tqwhlptmax_swc_in,
                                    vsctl_tqwhlminsat_swc_in,
                                    vsctl_tqwhlminreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_tqwhlmin_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_btqwhlminsat_swc_in),
                                    vsctl_tqwhlmaxreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_tqwhlmax_swc_in),
                                    vsctl_tqwhlptprecovsctlreq_swc_in,
                                    vsctl_tqwhlptprecovscminreq_swc_in,
                                    vsctl_spdveh_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bauthanttqwhlmin_swc_in),
                                    vsctl_tqwhlptdrvminreq_swc_in,
                                    vsctl_tqwhlptminnotctla_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bauthanttqwhlmax_swc_in),
                                    vsctl_tqwhlptdrvmaxreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlatqpt_swc_in),
                                    vsctl_tqwhlptmaxnotctla_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bfastdeacvslimreq_swc_in),
                                    accp_raccp_swc_in,
                                    &vsctl_sttqwhlptcutoffreq_swc_out,
                                    &VSCtl_bCtlEfc_tqWhlPT_pt1,
                                    &vsctl_bctlefc_tqwhlptmin_swc_out,
                                    &VSCtl_stTqPTMinCtl_pt1,
                                    &vsctl_bctlefc_tqwhlptmax_swc_out,
                                    &vsctl_bacvtqwhlptminsat_swc_out,
                                    &VSCtl_stTqPTMaxCtl_pt1,
                                    &vsctl_tqwhlptminreq_swc_out,                          /*BIN1*/
                                    &vsctl_tqwhlptminsat_swc_out,                          /*BIN1*/
                                    &vsctl_raccpptmin_swc_out,                             /*BIN7*/
                                    &vsctl_tqwhlptmaxreq_swc_out,                          /*BIN1*/
                                    &vsctl_raccpptmax_swc_out);                             /*BIN7*/

            VSSP_Torque_Control_Gmp2_Sf(
                                    vsctl_tqwhlptpotrawmin_swc_in,
                                    vsctl_tqwhlptpotrawmax_swc_in,
                                    ext_nfrntwhl_swc_in,
                                    vsctl_tqckefcdrvminreq_swc_in,
                                    ext_sttratypcf_swc_in,
                                    vsctl_tqckefcminnotctla_swc_in,
                                    vsctl_tqckefcdrvmaxreq_swc_in,
                                    vsctl_ticfmsuptqminreq_swc_in,
                                    vsctl_tqwhlminreq_swc_in,
                                    vsctl_tqckefcmaxnotctla_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_tqwhlmin_swc_in),
                                    vsctl_ticfmsuptqmaxreq_swc_in,
                                    vsctl_tqwhlmaxreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_tqwhlmax_swc_in),
                                    vsctl_ticfmsdwntqminreq_swc_in,
                                    vsctl_ticfmsdwntqmaxreq_swc_in,
                                    vsctl_nengfil_swc_in,
                                    vsctl_tqwhlptprecovscminreq_swc_in,
                                    vsctl_tqckefcmin_swc_in,
                                    vsctl_tqwhlptprecovscmaxreq_swc_in,
                                    vsctl_tqckefcmax_swc_in,
                                    ext_stctlcmdpttqpotcf_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bavltqwhlpt_no3_swc_in),
                                    vsctl_tqwhlpotreq_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_tqwhlpot_swc_in),
                                    copt_nprimshafttar_swc_in,
                                    vsctl_tqlosstra_swc_in,
                                    vsctl_tqckefcprecovsctlreq_swc_in,
                                    vsctl_rconvtra_swc_in,
                                    vsctl_tqwhlpotminreq_swc_in,
                                    vsctl_stctl_tqwhlpotmin_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bfastdeacvslimreq_swc_in),
                                    vsctl_tqwhlpotmaxreq_swc_in,
                                    vsctl_stctl_tqwhlpotmax_swc_in,
                                    vsctl_tqckefcprecovscminreq_swc_in,
                                    accp_raccp_swc_in,
                                    &vsctl_tqwhlptpotmaxreq_swc_out,
                                    &vsctl_bctlefc_tqckefcmin_swc_out,
                                    &vsctl_ticfmsdwnreq_swc_out,
                                    &vsctl_sttqwhlptpotctlreq_swc_out,
                                    &vsctl_bctlefc_tqckefcmax_swc_out,
                                    &VSCtl_bCtlEfc_tqWhlPT_pt2,
                                    &vsctl_tqefctarmin_swc_out,
                                    &vsctl_binhrecup_swc_out,
                                    &vsctl_tqefctarmax_swc_out,
                                    &vsctl_raccpengmin_swc_out,
                                    &vsctl_raccpengmax_swc_out,
                                    &VSCtl_stTqPTMinCtl_pt2,
                                    &vsctl_tqckefcminreq_swc_out,
                                    &VSCtl_stTqPTMaxCtl_pt2,
                                    &vsctl_tqwhlptpotreq_swc_out,
                                    &vsctl_tqckefcmaxreq_swc_out,
                                    &vsctl_tqwhlptpotminreq_swc_out,
                                    &vsctl_ticfmsupreq_swc_out);




/* F22_ and F23_ are only called on Configuration BVA/BVMP = RAPPORT. This is only possible when VSCtl_bCtlCmdPTTqCf_SC = 0 */
        /* <PRQA_COMMENT><2741> Warning due to diversity constant </2741></PRQA_COMMENT> */
        if ((UInt32)DDS_FALSE == (UInt32)VSCtl_bCtlCmdPTTqCf_SC)    /* config structure couple moteur */
        {
            VSSP_Det_Gearbox_Pedal_Sf(  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                        (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdeacvsctlgearctl_fim_in),
                                        vsctl_avehdvsregreq_swc_in,
                                        vsctl_stctl_avehvslim_swc_in,
                                        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                        (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_avehdvsreg_swc_in),
                                        ext_sttratypcf_swc_in,
                                        vsctl_spdveherrvsreg_swc_in,
                                        vsctl_stctl_avehvsmax_swc_in,
                                        vsctl_spdveherrvslim_swc_in,
                                        vsctl_spdveherrvsmax_swc_in,
                                        vsctl_nengfil_swc_in,
                                        tra_stgearctl_swc_in,
                                        vsctl_raccpengmin_swc_out,
                                        ext_stctlcmdpttqpotcf_swc_in,
                                        vsctl_spdveh_swc_in,
                                        vsctl_nfrntwhlfil_swc_in,
                                        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                        (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlatqpt_swc_in),
                                        vsctl_tqwhlptpotreq_swc_out,
                                        vsctl_stctl_tqwhlpotmin_swc_in,
                                        vsctl_stctl_tqwhlpotmax_swc_in,
                                        copt_notargearcordit_swc_in,
                                        vsctl_stctl_avehvsreg_swc_in,
                                        accp_raccp_swc_in,
                                        &vsctl_stctl_nogear_swc_out,
                                        &vsctl_raccptramax_swc_out,
                                        &vsctl_nogearreqmin_swc_out,
                                        &vsctl_stgearctlreq_swc_out,
                                        &vsctl_nogearreqmax_swc_out,
                                        &vsctl_raccptramin_swc_out);



        }
        else        /* config structure couple moteur */
        {
            /* <PRQA_COMMENT><2880> Warning due to diversity constant </2880></PRQA_COMMENT> */
            vsctl_nogearreqmax_swc_out = VSCtl_noGearReqMax_B;
            vsctl_nogearreqmin_swc_out = VSCtl_noGearReqMin_B;
            vsctl_raccptramax_swc_out = VSCtl_rAccPTraMax_B;
            vsctl_raccptramin_swc_out = VSCtl_rAccPTraMin_B;
            vsctl_stctl_nogear_swc_out = VSCtl_stCtl_noGear_B;
            vsctl_stgearctlreq_swc_out = VSCtl_stGearCtlReq_B;
        }
    }
    else
    {
        vsctl_bacvtqwhlptminsat_swc_out = VSCtl_bAcvTqWhlPTMinSat_B;
        vsctl_bctlefc_tqckefcmax_swc_out = VSCtl_bCtlEfc_tqCkEfcMax_B;
        vsctl_bctlefc_tqckefcmin_swc_out = VSCtl_bCtlEfc_tqCkEfcMin_B;
        vsctl_bctlefc_tqwhlptmax_swc_out = VSCtl_bCtlEfc_tqWhlPTMax_B;
        vsctl_bctlefc_tqwhlptmin_swc_out = VSCtl_bCtlEfc_tqWhlPTMin_B;
        vsctl_binhrecup_swc_out = VSCtl_bInhRecup_B;
        vsctl_nogearreqmax_swc_out = VSCtl_noGearReqMax_B;
        vsctl_nogearreqmin_swc_out = VSCtl_noGearReqMin_B;
        vsctl_raccpengmax_swc_out = VSCtl_rAccPEngMax_B;
        vsctl_raccpengmin_swc_out = VSCtl_rAccPEngMin_B;
        vsctl_raccpptmax_swc_out = VSCtl_rAccPPTMax_B;
        vsctl_raccpptmin_swc_out = VSCtl_rAccPPTMin_B;
        vsctl_raccptramax_swc_out = VSCtl_rAccPTraMax_B;
        vsctl_raccptramin_swc_out = VSCtl_rAccPTraMin_B;
        vsctl_stctl_nogear_swc_out = VSCtl_stCtl_noGear_B;
        vsctl_stgearctlreq_swc_out = VSCtl_stGearCtlReq_B;
        vsctl_sttqwhlptcutoffreq_swc_out = VSCtl_stTqWhlPTCutOffReq_B;
        vsctl_sttqwhlptpotctlreq_swc_out = VSCtl_stTqWhlPTPotCtlReq_B;
        vsctl_ticfmsdwnreq_swc_out = VSCtl_tiCfmSdwnReq_B;
        vsctl_ticfmsupreq_swc_out = VSCtl_tiCfmSupReq_B;
        vsctl_tqckefcmaxreq_swc_out = VSCtl_tqCkEfcMaxReq_B;
        vsctl_tqckefcminreq_swc_out = VSCtl_tqCkEfcMinReq_B;
        vsctl_tqefctarmax_swc_out = VSCtl_tqEfcTarMax_B;
        vsctl_tqefctarmin_swc_out = VSCtl_tqEfcTarMin_B;
        vsctl_tqwhlptmaxreq_swc_out = VSCtl_tqWhlPTMaxReq_B;
        vsctl_tqwhlptminreq_swc_out = VSCtl_tqWhlPTMinReq_B;
        vsctl_tqwhlptminsat_swc_out = VSCtl_tqWhlPTMinSat_B;
        vsctl_tqwhlptpotmaxreq_swc_out = VSCtl_tqWhlPTPotMaxReq_B;
        vsctl_tqwhlptpotminreq_swc_out = VSCtl_tqWhlPTPotMinReq_B;
        vsctl_tqwhlptpotreq_swc_out = VSCtl_tqWhlPTPotReq_B;

        VSCtl_bCtlEfc_tqWhlPT_pt1 = VSCtl_bCtlEfc_tqWhlPT_pt1_B;
        VSCtl_bCtlEfc_tqWhlPT_pt2 = VSCtl_bCtlEfc_tqWhlPT_pt2_B;
        VSCtl_stTqPTMaxCtl_pt1 = VSCtl_stTqPTMaxCtl_pt1_B;
        VSCtl_stTqPTMaxCtl_pt2 = VSCtl_stTqPTMaxCtl_pt2_B;
        VSCtl_stTqPTMinCtl_pt1 = VSCtl_stTqPTMinCtl_pt1_B;
        VSCtl_stTqPTMinCtl_pt2 = VSCtl_stTqPTMinCtl_pt2_B;
    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I060(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAcvTqWhlPTMinSat_VSCtl_bAcvTqWhlPTMinSat(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bacvtqwhlptminsat_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I061(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqCkEfcMax_VSCtl_bCtlEfc_tqCkEfcMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqckefcmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I062(1) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqCkEfcMin_VSCtl_bCtlEfc_tqCkEfcMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqckefcmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I064(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPTMax_VSCtl_bCtlEfc_tqWhlPTMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlptmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I065(1) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPTMin_VSCtl_bCtlEfc_tqWhlPTMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlptmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I066(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bInhRecup_VSCtl_bInhRecup(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_binhrecup_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I067(0) */
    Rte_Write_P_VSCtl_noGearReqMax_VSCtl_noGearReqMax(vsctl_nogearreqmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I068(0) */
    Rte_Write_P_VSCtl_noGearReqMin_VSCtl_noGearReqMin(vsctl_nogearreqmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I069(0) */
    Rte_Write_P_VSCtl_rAccPEngMax_VSCtl_rAccPEngMax(vsctl_raccpengmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I070(0) */
    Rte_Write_P_VSCtl_rAccPEngMin_VSCtl_rAccPEngMin(vsctl_raccpengmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I071(0) */
    Rte_Write_P_VSCtl_rAccPPTMax_VSCtl_rAccPPTMax(vsctl_raccpptmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I072(0) */
    Rte_Write_P_VSCtl_rAccPPTMin_VSCtl_rAccPPTMin(vsctl_raccpptmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I073(0) */
    Rte_Write_P_VSCtl_rAccPTraMax_VSCtl_rAccPTraMax(vsctl_raccptramax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I074(0) */
    Rte_Write_P_VSCtl_rAccPTraMin_VSCtl_rAccPTraMin(vsctl_raccptramin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I075(0) */
    Rte_Write_P_VSCtl_stCtl_noGear_VSCtl_stCtl_noGear(vsctl_stctl_nogear_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I076(0) */
    Rte_Write_P_VSCtl_stGearCtlReq_VSCtl_stGearCtlReq(vsctl_stgearctlreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I079(0) */
    Rte_Write_P_VSCtl_stTqWhlPTCutOffReq_VSCtl_stTqWhlPTCutOffReq(vsctl_sttqwhlptcutoffreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I080(0) */
    Rte_Write_P_VSCtl_stTqWhlPTPotCtlReq_VSCtl_stTqWhlPTPotCtlReq(vsctl_sttqwhlptpotctlreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I081(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnReq_VSCtl_tiCfmSdwnReq(vsctl_ticfmsdwnreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I082(0) */
    Rte_Write_P_VSCtl_tiCfmSupReq_VSCtl_tiCfmSupReq(vsctl_ticfmsupreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I083(0) */
    Rte_Write_P_VSCtl_tqCkEfcMaxReq_VSCtl_tqCkEfcMaxReq(vsctl_tqckefcmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I084(0) */
    Rte_Write_P_VSCtl_tqCkEfcMinReq_VSCtl_tqCkEfcMinReq(vsctl_tqckefcminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I201(0) */
    Rte_Write_P_VSCtl_tqEfcTarMax_VSCtl_tqEfcTarMax(vsctl_tqefctarmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I200(0) */
    Rte_Write_P_VSCtl_tqEfcTarMin_VSCtl_tqEfcTarMin(vsctl_tqefctarmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I085(0) */
    Rte_Write_P_VSCtl_tqWhlPTMaxReq_VSCtl_tqWhlPTMaxReq(vsctl_tqwhlptmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I086(0) */
    Rte_Write_P_VSCtl_tqWhlPTMinReq_VSCtl_tqWhlPTMinReq(vsctl_tqwhlptminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I087(0) */
    Rte_Write_P_VSCtl_tqWhlPTMinSat_VSCtl_tqWhlPTMinSat(vsctl_tqwhlptminsat_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I088(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotMaxReq_VSCtl_tqWhlPTPotMaxReq(vsctl_tqwhlptpotmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I089(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotMinReq_VSCtl_tqWhlPTPotMinReq(vsctl_tqwhlptpotminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I090(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotReq_VSCtl_tqWhlPTPotReq(vsctl_tqwhlptpotreq_swc_out);

    /* IRV OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I093(3) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_VSSp_002_TEV_VSCtl_bCtlEfc_tqWhlPT_pt1(DDS_M_CONVERT_UINT8_TO_BOOL(VSCtl_bCtlEfc_tqWhlPT_pt1));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I094(3) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_VSSp_002_TEV_VSCtl_bCtlEfc_tqWhlPT_pt2(DDS_M_CONVERT_UINT8_TO_BOOL(VSCtl_bCtlEfc_tqWhlPT_pt2));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I095(3) */
    Rte_IrvWrite_RE_VSSp_002_TEV_VSCtl_stTqPTMaxCtl_pt1(VSCtl_stTqPTMaxCtl_pt1);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I096(3) */
    Rte_IrvWrite_RE_VSSp_002_TEV_VSCtl_stTqPTMaxCtl_pt2(VSCtl_stTqPTMaxCtl_pt2);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I097(3) */
    Rte_IrvWrite_RE_VSSp_002_TEV_VSCtl_stTqPTMinCtl_pt1(VSCtl_stTqPTMinCtl_pt1);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I098(3) */
    Rte_IrvWrite_RE_VSSp_002_TEV_VSCtl_stTqPTMinCtl_pt2(VSCtl_stTqPTMinCtl_pt2);
}

/*******************************************************************************
*
*  Runnable Name    : RE_VSSp_003_TEV
*  Event            : Every 0.04
*  Description      : Call  scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_VSSp_003_TEV(void)
{
    /* IRV IN */
    Boolean vsctl_bctlefc_tqwhlpt_pt1_irv_in;
    Boolean vsctl_bctlefc_tqwhlpt_pt2_irv_in;
    UInt8 vsctl_sttqptmaxctl_pt1_irv_in;
    UInt8 vsctl_sttqptmaxctl_pt2_irv_in;
    UInt8 vsctl_sttqptminctl_pt1_irv_in;
    UInt8 vsctl_sttqptminctl_pt2_irv_in;
    /* OUTPUT */
    /* SWC OUT */
    UInt8 vsctl_bctlefc_tqwhlpt_swc_out;
    UInt8 vsctl_sttqptmaxctl_swc_out;
    UInt8 vsctl_sttqptminctl_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_VSSP_003_TEV_B)
    {


        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I093(3) */
        vsctl_bctlefc_tqwhlpt_pt1_irv_in = Rte_IrvRead_RE_VSSp_003_TEV_VSCtl_bCtlEfc_tqWhlPT_pt1();
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I094(3) */
        vsctl_bctlefc_tqwhlpt_pt2_irv_in = Rte_IrvRead_RE_VSSp_003_TEV_VSCtl_bCtlEfc_tqWhlPT_pt2();
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I095(3) */
        vsctl_sttqptmaxctl_pt1_irv_in = Rte_IrvRead_RE_VSSp_003_TEV_VSCtl_stTqPTMaxCtl_pt1();
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I096(3) */
        vsctl_sttqptmaxctl_pt2_irv_in = Rte_IrvRead_RE_VSSp_003_TEV_VSCtl_stTqPTMaxCtl_pt2();
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I097(3) */
        vsctl_sttqptminctl_pt1_irv_in = Rte_IrvRead_RE_VSSp_003_TEV_VSCtl_stTqPTMinCtl_pt1();
        /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I098(3) */
        vsctl_sttqptminctl_pt2_irv_in = Rte_IrvRead_RE_VSSp_003_TEV_VSCtl_stTqPTMinCtl_pt2();

        VSSP_Effec_Process_Xvv(
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlefc_tqwhlpt_pt1_irv_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlefc_tqwhlpt_pt2_irv_in),
                            vsctl_sttqptmaxctl_pt1_irv_in,
                            vsctl_sttqptmaxctl_pt2_irv_in,
                            vsctl_sttqptminctl_pt1_irv_in,
                            vsctl_sttqptminctl_pt2_irv_in,
                            &vsctl_bctlefc_tqwhlpt_swc_out,
                            &vsctl_sttqptmaxctl_swc_out,
                            &vsctl_sttqptminctl_swc_out);

    }
    else
    {
        vsctl_bctlefc_tqwhlpt_swc_out = VSCtl_bCtlEfc_tqWhlPt_B;
        vsctl_sttqptmaxctl_swc_out = VSCtl_stTqPTMaxCtl_B;
        vsctl_sttqptminctl_swc_out = VSCtl_stTqPTMinCtl_B;

    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I063(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPt_VSCtl_bCtlEfc_tqWhlPt(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlpt_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I077(0) */
    Rte_Write_P_VSCtl_stTqPTMaxCtl_VSCtl_stTqPTMaxCtl(vsctl_sttqptmaxctl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I078(0) */
    Rte_Write_P_VSCtl_stTqPTMinCtl_VSCtl_stTqPTMinCtl(vsctl_sttqptminctl_swc_out);

    /* IRV OUTPUT */
}

/*******************************************************************************
*
*  Runnable Name    : RE_01552_10_02851_10ms_coldinit
*  Event            :
*  Description      : Call  scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_VSSp_004_MSE(void)
{
    /* OUTPUT */
    /* SWC OUT */
    UInt8 vsctl_bacvtqwhlptminsat_swc_out;
    UInt8 vsctl_bctlefc_tqckefcmax_swc_out;
    UInt8 vsctl_bctlefc_tqckefcmin_swc_out;
    UInt8 vsctl_bctlefc_tqwhlpt_swc_out;
    UInt8 vsctl_bctlefc_tqwhlptmax_swc_out;
    UInt8 vsctl_bctlefc_tqwhlptmin_swc_out;
    UInt8 vsctl_binhrecup_swc_out;
    UInt8 vsctl_nogearreqmax_swc_out;
    UInt8 vsctl_nogearreqmin_swc_out;
    UInt16 vsctl_raccpengmax_swc_out;
    UInt16 vsctl_raccpengmin_swc_out;
    UInt16 vsctl_raccpptmax_swc_out;
    UInt16 vsctl_raccpptmin_swc_out;
    UInt16 vsctl_raccptramax_swc_out;
    UInt16 vsctl_raccptramin_swc_out;
    UInt8 vsctl_stctl_nogear_swc_out;
    UInt8 vsctl_stgearctlreq_swc_out;
    UInt8 vsctl_sttqptmaxctl_swc_out;
    UInt8 vsctl_sttqptminctl_swc_out;
    UInt8 vsctl_sttqwhlptcutoffreq_swc_out;
    UInt8 vsctl_sttqwhlptpotctlreq_swc_out;
    UInt16 vsctl_ticfmsdwnreq_swc_out;
    UInt16 vsctl_ticfmsupreq_swc_out;
    SInt16 vsctl_tqckefcmaxreq_swc_out;
    SInt16 vsctl_tqckefcminreq_swc_out;
    SInt16 vsctl_tqwhlptmaxreq_swc_out;
    SInt16 vsctl_tqwhlptminreq_swc_out;
    SInt16 vsctl_tqwhlptminsat_swc_out;
    SInt16 vsctl_tqwhlptpotmaxreq_swc_out;
    SInt16 vsctl_tqwhlptpotminreq_swc_out;
    SInt16 vsctl_tqwhlptpotreq_swc_out;
    SInt16 vsctl_tqefctarmin_swc_out;
    SInt16 vsctl_tqefctarmax_swc_out;

    VSSP_Torque_Control_Gmp1_Sf_Init(
                                    &vsctl_sttqwhlptcutoffreq_swc_out,
                                    &VSCtl_bCtlEfc_tqWhlPT_pt1,
                                    &vsctl_bctlefc_tqwhlptmin_swc_out,
                                    &VSCtl_stTqPTMinCtl_pt1,
                                    &vsctl_bctlefc_tqwhlptmax_swc_out,
                                    &vsctl_bacvtqwhlptminsat_swc_out,
                                    &VSCtl_stTqPTMaxCtl_pt1,
                                    &vsctl_tqwhlptminreq_swc_out,                          /*BIN1*/
                                    &vsctl_tqwhlptminsat_swc_out,                          /*BIN1*/
                                    &vsctl_raccpptmin_swc_out,                             /*BIN7*/
                                    &vsctl_tqwhlptmaxreq_swc_out,                          /*BIN1*/
                                    &vsctl_raccpptmax_swc_out);                             /*BIN7*/

    VSSP_Torque_Control_Gmp2_Sf_Init(
                                    &vsctl_tqwhlptpotmaxreq_swc_out,
                                    &vsctl_bctlefc_tqckefcmin_swc_out,
                                    &vsctl_ticfmsdwnreq_swc_out,
                                    &vsctl_sttqwhlptpotctlreq_swc_out,
                                    &vsctl_bctlefc_tqckefcmax_swc_out,
                                    &VSCtl_bCtlEfc_tqWhlPT_pt2,
                                    &vsctl_tqefctarmin_swc_out,
                                    &vsctl_binhrecup_swc_out,
                                    &vsctl_tqefctarmax_swc_out,
                                    &vsctl_raccpengmin_swc_out,
                                    &vsctl_raccpengmax_swc_out,
                                    &VSCtl_stTqPTMinCtl_pt2,
                                    &vsctl_tqckefcminreq_swc_out,
                                    &VSCtl_stTqPTMaxCtl_pt2,
                                    &vsctl_tqwhlptpotreq_swc_out,
                                    &vsctl_tqckefcmaxreq_swc_out,
                                    &vsctl_tqwhlptpotminreq_swc_out,
                                    &vsctl_ticfmsupreq_swc_out);

    VSSP_Det_Gearbox_Pedal_Sf_Init(
                                    &vsctl_stctl_nogear_swc_out,
                                    &vsctl_raccptramax_swc_out, /* BIN7 */
                                    &vsctl_nogearreqmin_swc_out,
                                    &vsctl_stgearctlreq_swc_out,
                                    &vsctl_nogearreqmax_swc_out,
                                    &vsctl_raccptramin_swc_out); /* BIN7 */

    VSSP_Effec_Process_Xvv_Init(
                                    &vsctl_bctlefc_tqwhlpt_swc_out,
                                    &vsctl_sttqptmaxctl_swc_out,
                                    &vsctl_sttqptminctl_swc_out);

    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I060(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAcvTqWhlPTMinSat_VSCtl_bAcvTqWhlPTMinSat(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bacvtqwhlptminsat_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I061(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqCkEfcMax_VSCtl_bCtlEfc_tqCkEfcMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqckefcmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I062(1) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqCkEfcMin_VSCtl_bCtlEfc_tqCkEfcMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqckefcmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I064(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPTMax_VSCtl_bCtlEfc_tqWhlPTMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlptmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I065(1) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPTMin_VSCtl_bCtlEfc_tqWhlPTMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlptmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I063(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bCtlEfc_tqWhlPt_VSCtl_bCtlEfc_tqWhlPt(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bctlefc_tqwhlpt_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I066(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bInhRecup_VSCtl_bInhRecup(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_binhrecup_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I067(0) */
    Rte_Write_P_VSCtl_noGearReqMax_VSCtl_noGearReqMax(vsctl_nogearreqmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I068(0) */
    Rte_Write_P_VSCtl_noGearReqMin_VSCtl_noGearReqMin(vsctl_nogearreqmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I069(0) */
    Rte_Write_P_VSCtl_rAccPEngMax_VSCtl_rAccPEngMax(vsctl_raccpengmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I070(0) */
    Rte_Write_P_VSCtl_rAccPEngMin_VSCtl_rAccPEngMin(vsctl_raccpengmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I071(0) */
    Rte_Write_P_VSCtl_rAccPPTMax_VSCtl_rAccPPTMax(vsctl_raccpptmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I072(0) */
    Rte_Write_P_VSCtl_rAccPPTMin_VSCtl_rAccPPTMin(vsctl_raccpptmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I073(0) */
    Rte_Write_P_VSCtl_rAccPTraMax_VSCtl_rAccPTraMax(vsctl_raccptramax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I074(0) */
    Rte_Write_P_VSCtl_rAccPTraMin_VSCtl_rAccPTraMin(vsctl_raccptramin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I075(0) */
    Rte_Write_P_VSCtl_stCtl_noGear_VSCtl_stCtl_noGear(vsctl_stctl_nogear_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I076(0) */
    Rte_Write_P_VSCtl_stGearCtlReq_VSCtl_stGearCtlReq(vsctl_stgearctlreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I077(0) */
    Rte_Write_P_VSCtl_stTqPTMaxCtl_VSCtl_stTqPTMaxCtl(vsctl_sttqptmaxctl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I078(0) */
    Rte_Write_P_VSCtl_stTqPTMinCtl_VSCtl_stTqPTMinCtl(vsctl_sttqptminctl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I079(0) */
    Rte_Write_P_VSCtl_stTqWhlPTCutOffReq_VSCtl_stTqWhlPTCutOffReq(vsctl_sttqwhlptcutoffreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I080(0) */
    Rte_Write_P_VSCtl_stTqWhlPTPotCtlReq_VSCtl_stTqWhlPTPotCtlReq(vsctl_sttqwhlptpotctlreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I081(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnReq_VSCtl_tiCfmSdwnReq(vsctl_ticfmsdwnreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I082(0) */
    Rte_Write_P_VSCtl_tiCfmSupReq_VSCtl_tiCfmSupReq(vsctl_ticfmsupreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I083(0) */
    Rte_Write_P_VSCtl_tqCkEfcMaxReq_VSCtl_tqCkEfcMaxReq(vsctl_tqckefcmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I084(0) */
    Rte_Write_P_VSCtl_tqCkEfcMinReq_VSCtl_tqCkEfcMinReq(vsctl_tqckefcminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I201(0) */
    Rte_Write_P_VSCtl_tqEfcTarMax_VSCtl_tqEfcTarMax(vsctl_tqefctarmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I200(0) */
    Rte_Write_P_VSCtl_tqEfcTarMin_VSCtl_tqEfcTarMin(vsctl_tqefctarmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I085(0) */
    Rte_Write_P_VSCtl_tqWhlPTMaxReq_VSCtl_tqWhlPTMaxReq(vsctl_tqwhlptmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I086(0) */
    Rte_Write_P_VSCtl_tqWhlPTMinReq_VSCtl_tqWhlPTMinReq(vsctl_tqwhlptminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I087(0) */
    Rte_Write_P_VSCtl_tqWhlPTMinSat_VSCtl_tqWhlPTMinSat(vsctl_tqwhlptminsat_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I088(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotMaxReq_VSCtl_tqWhlPTPotMaxReq(vsctl_tqwhlptpotmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I089(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotMinReq_VSCtl_tqWhlPTPotMinReq(vsctl_tqwhlptpotminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I090(0) */
    Rte_Write_P_VSCtl_tqWhlPTPotReq_VSCtl_tqWhlPTPotReq(vsctl_tqwhlptpotreq_swc_out);

    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I093(3) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_VSSp_004_MSE_VSCtl_bCtlEfc_tqWhlPT_pt1(DDS_M_CONVERT_UINT8_TO_BOOL(VSCtl_bCtlEfc_tqWhlPT_pt1));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I094(3) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_IrvWrite_RE_VSSp_004_MSE_VSCtl_bCtlEfc_tqWhlPT_pt2(DDS_M_CONVERT_UINT8_TO_BOOL(VSCtl_bCtlEfc_tqWhlPT_pt2));
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I095(3) */
    Rte_IrvWrite_RE_VSSp_004_MSE_VSCtl_stTqPTMaxCtl_pt1(VSCtl_stTqPTMaxCtl_pt1);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I096(3) */
    Rte_IrvWrite_RE_VSSp_004_MSE_VSCtl_stTqPTMaxCtl_pt2(VSCtl_stTqPTMaxCtl_pt2);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I097(3) */
    Rte_IrvWrite_RE_VSSp_004_MSE_VSCtl_stTqPTMinCtl_pt1(VSCtl_stTqPTMinCtl_pt1);
    /* SSTG_REQ_TAG: 01552_10_02851-VSSp-I098(3) */
    Rte_IrvWrite_RE_VSSp_004_MSE_VSCtl_stTqPTMinCtl_pt2(VSCtl_stTqPTMinCtl_pt2);
}

/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : VSSp_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) VSSp_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_VSSp_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

