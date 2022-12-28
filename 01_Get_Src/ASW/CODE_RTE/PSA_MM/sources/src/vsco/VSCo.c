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
* Ref X:\integration_view_00PSASWC_D721D01\blois_psa_sstg\Software\Appli\VSCo\src\VSCo.c
* Version int :/main/00PSASWC_D7/7 Date: 12/4/2012 13 h 55 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for VSCo 12.1
* Version dev :\main\branch_morisseau_vsco_euro6\1 Date: 12/4/2012 11 h 5 m User:morisseau 
*    TWK_model:NO_MODEL
*    comments :for VSCo 12.1
* Version int :/main/00PSASWC_D7/6 Date: 10/1/2012 8 h 35 m User:meme
*    TWK_model:NO_MODEL
*    comments :For VSCo_12_0_e6
* Version dev :\main\branch_halouane_vsco_euro6\1 Date: 6/1/2012 15 h 24 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For VSCo_12_0_e6
*
*******************************************************************************/

/*******************************************************************************/

/* File generated with swc_main_code_generator Version 1.00 */

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "VSCo.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if VSCO_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
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
#define VSCO_START_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehCordVSLimReq_B = (CONST(SInt16, AUTOMATIC))(10 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehCordVSRegReq_B = (CONST(SInt16, AUTOMATIC))(-10 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehReq_B = (CONST(SInt16, AUTOMATIC))(-10 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnTqMaxReq_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnTqMinReq_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupTqMaxReq_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiCfmSupTqMinReq_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMaxReq_B = (CONST(SInt16, AUTOMATIC))(16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMinReq_B = (CONST(SInt16, AUTOMATIC))(-16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMinSat_B = (CONST(SInt16, AUTOMATIC))(-16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxReq_B = (CONST(SInt16, AUTOMATIC))(16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxRsvHiThd_B = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxRsvLoThd_B = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinReq_B = (CONST(SInt16, AUTOMATIC))(-16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinRsvHiThd_B = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinRsvLoThd_B = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPotReq_B = (CONST(SInt16, AUTOMATIC))(-16000 * BIN1);
#define VSCO_STOP_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSCO_START_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCO_ACTIVE_BYP_C = DDS_FALSE;

STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAuthAntTqWhlMax_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bAuthAntTqWhlMin_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDrvOvrdDVSReg_aVeh_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSLim_aVeh_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSMax_aVeh_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bEndTranVSLim_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bEndTranVSMax_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bEndTranVSReg_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bKdAuth_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bTqWhlMinSat_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlMax_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlMin_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPot_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPotMax_B = (UInt8)VSCO_POT_ARRET ;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPotMin_B = (UInt8)VSCO_POT_ARRET ;
#define VSCO_STOP_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"

/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variables definition */
#define VSCO_START_SEC_VAR_8BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlpotmax_swc_out_prev;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlpotmin_swc_out_prev;

/* [0] = z-1 */
/* [1] = z-2 */
/* [2] = z-3 */
/* [3] = z-4 */
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlmin_swc_out_prev[VSCO_PREV_TAB_SIZE_4];
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlmax_swc_out_prev;
#define VSCO_STOP_SEC_VAR_8BIT
#include "VSCo_MemMap.h"

/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define VSCO_START_SEC_CONST_VERSION_MODULE_8BIT
#include "VSCo_MemMap.h"
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) VSCo_ModuleVersion_Major_MP = (UInt8)12;
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) VSCo_ModuleVersion_Minor_MP = (UInt8)1;
#define VSCO_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "VSCo_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define VSCO_START_SEC_CODE
#include "VSCo_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_VSCo_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_VSCo_001_MSE(void)
{
    /* OUTPUT */
    /* SWC OUT */
    SInt16 vsctl_avehcordvslimreq_swc_out;
    SInt16 vsctl_avehcordvsregreq_swc_out;
    SInt16 vsctl_avehreq_swc_out;
    UInt8 vsctl_bauthanttqwhlmax_swc_out;
    UInt8 vsctl_bauthanttqwhlmin_swc_out;
    UInt8 vsctl_bdrvovrddvsreg_aveh_swc_out;
    UInt8 vsctl_bdrvovrdvslim_aveh_swc_out;
    UInt8 vsctl_bdrvovrdvsmax_aveh_swc_out;
    UInt8 vsctl_bdrvovrdvsreg_aveh_swc_out;
    UInt8 vsctl_bendtranvslim_swc_out;
    UInt8 vsctl_bendtranvsmax_swc_out;
    UInt8 vsctl_bendtranvsreg_swc_out;
    UInt8 vsctl_bkdauth_swc_out;
    UInt8 vsctl_btqwhlminsat_swc_out;
    UInt8 vsctl_stctl_tqwhlmax_swc_out;
    UInt8 vsctl_stctl_tqwhlmin_swc_out;
    UInt8 vsctl_stctl_tqwhlpot_swc_out;
    UInt8 vsctl_stctl_tqwhlpotmax_swc_out;
    UInt8 vsctl_stctl_tqwhlpotmin_swc_out;
    UInt16 vsctl_ticfmsdwntqmaxreq_swc_out;
    UInt16 vsctl_ticfmsdwntqminreq_swc_out;
    UInt16 vsctl_ticfmsuptqmaxreq_swc_out;
    UInt16 vsctl_ticfmsuptqminreq_swc_out;
    SInt16 vsctl_tqwhlmaxreq_swc_out;
    SInt16 vsctl_tqwhlminreq_swc_out;
    SInt16 vsctl_tqwhlminsat_swc_out;
    SInt16 vsctl_tqwhlpotmaxreq_swc_out;
    SInt16 vsctl_tqwhlpotmaxrsvhithd_swc_out;
    SInt16 vsctl_tqwhlpotmaxrsvlothd_swc_out;
    SInt16 vsctl_tqwhlpotminreq_swc_out;
    SInt16 vsctl_tqwhlpotminrsvhithd_swc_out;
    SInt16 vsctl_tqwhlpotminrsvlothd_swc_out;
    SInt16 vsctl_tqwhlpotreq_swc_out;


    VSCO_Veh_Accel_Cons_Init(&vsctl_avehreq_swc_out, /* BIN10 */
                             &vsctl_avehcordvslimreq_swc_out, /* BIN10 */
                             &vsctl_avehcordvsregreq_swc_out, /* BIN10 */
                             &vsctl_bendtranvsreg_swc_out,
                             &vsctl_bendtranvslim_swc_out,
                             &vsctl_bendtranvsmax_swc_out,
                             &vsctl_bdrvovrdvsreg_aveh_swc_out,
                             &vsctl_bdrvovrddvsreg_aveh_swc_out,
                             &vsctl_bdrvovrdvslim_aveh_swc_out,
                             &vsctl_bdrvovrdvsmax_aveh_swc_out);


    VSCO_Wheel_Torque_Cons_Init(&vsctl_tqwhlminreq_swc_out, /* BIN1 */
                                &vsctl_tqwhlmaxreq_swc_out, /* BIN1 */
                                &vsctl_bauthanttqwhlmin_swc_out,
                                &vsctl_bauthanttqwhlmax_swc_out,
                                &vsctl_stctl_tqwhlmin_swc_out,
                                &vsctl_stctl_tqwhlmax_swc_out,
                                &vsctl_tqwhlminsat_swc_out, /* BIN1 */
                                &vsctl_btqwhlminsat_swc_out);

    VSCO_Veh_Acc_Pot_Act_Cons_Init();


    VSCO_Whl_Tq_Pot_Cons_Kick_Init(&vsctl_tqwhlpotminreq_swc_out,
                                   &vsctl_tqwhlpotmaxreq_swc_out,
                                   &vsctl_tqwhlpotminrsvlothd_swc_out,
                                   &vsctl_tqwhlpotminrsvhithd_swc_out,
                                   &vsctl_tqwhlpotmaxrsvlothd_swc_out,
                                   &vsctl_tqwhlpotmaxrsvhithd_swc_out,
                                   &vsctl_ticfmsdwntqmaxreq_swc_out,
                                   &vsctl_ticfmsdwntqminreq_swc_out,
                                   &vsctl_ticfmsuptqmaxreq_swc_out,
                                   &vsctl_ticfmsuptqminreq_swc_out,
                                   &vsctl_stctl_tqwhlpot_swc_out,
                                   &vsctl_stctl_tqwhlpotmax_swc_out,
                                   &vsctl_stctl_tqwhlpotmin_swc_out,
                                   &vsctl_tqwhlpotreq_swc_out,
                                   &vsctl_bkdauth_swc_out);



    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I065(0) */
    Rte_Write_P_VSCtl_aVehCordVSLimReq_VSCtl_aVehCordVSLimReq(vsctl_avehcordvslimreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I066(0) */
    Rte_Write_P_VSCtl_aVehCordVSRegReq_VSCtl_aVehCordVSRegReq(vsctl_avehcordvsregreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I067(0) */
    Rte_Write_P_VSCtl_aVehReq_VSCtl_aVehReq(vsctl_avehreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I068(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAuthAntTqWhlMax_VSCtl_bAuthAntTqWhlMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bauthanttqwhlmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I069(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAuthAntTqWhlMin_VSCtl_bAuthAntTqWhlMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bauthanttqwhlmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I070(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdDVSReg_aVeh_VSCtl_bDrvOvrdDVSReg_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrddvsreg_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I071(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdVSLim_aVeh_VSCtl_bDrvOvrdVSLim_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrdvslim_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I072(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdVSMax_aVeh_VSCtl_bDrvOvrdVSMax_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrdvsmax_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I073(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdVSReg_aVeh_VSCtl_bDrvOvrdVSReg_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrdvsreg_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I074(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bEndTranVSLim_VSCtl_bEndTranVSLim(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bendtranvslim_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I075(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bEndTranVSMax_VSCtl_bEndTranVSMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bendtranvsmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I076(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bEndTranVSReg_VSCtl_bEndTranVSReg(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bendtranvsreg_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I077(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bKdAuth_VSCtl_bKdAuth(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bkdauth_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I078(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bTqWhlMinSat_VSCtl_bTqWhlMinSat(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_btqwhlminsat_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I079(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_stCtl_tqWhlMax_VSCtl_stCtl_tqWhlMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_stctl_tqwhlmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I080(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_stCtl_tqWhlMin_VSCtl_stCtl_tqWhlMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_stctl_tqwhlmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I081(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_stCtl_tqWhlPot_VSCtl_stCtl_tqWhlPot(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_stctl_tqwhlpot_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I082(1) */
    Rte_Write_P_VSCtl_stCtl_tqWhlPotMax_VSCtl_stCtl_tqWhlPotMax(vsctl_stctl_tqwhlpotmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I083(1) */
    Rte_Write_P_VSCtl_stCtl_tqWhlPotMin_VSCtl_stCtl_tqWhlPotMin(vsctl_stctl_tqwhlpotmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I084(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnTqMaxReq_VSCtl_tiCfmSdwnTqMaxReq(vsctl_ticfmsdwntqmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I085(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnTqMinReq_VSCtl_tiCfmSdwnTqMinReq(vsctl_ticfmsdwntqminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I086(0) */
    Rte_Write_P_VSCtl_tiCfmSupTqMaxReq_VSCtl_tiCfmSupTqMaxReq(vsctl_ticfmsuptqmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I087(0) */
    Rte_Write_P_VSCtl_tiCfmSupTqMinReq_VSCtl_tiCfmSupTqMinReq(vsctl_ticfmsuptqminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I088(0) */
    Rte_Write_P_VSCtl_tqWhlMaxReq_VSCtl_tqWhlMaxReq(vsctl_tqwhlmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I089(0) */
    Rte_Write_P_VSCtl_tqWhlMinReq_VSCtl_tqWhlMinReq(vsctl_tqwhlminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I090(0) */
    Rte_Write_P_VSCtl_tqWhlMinSat_VSCtl_tqWhlMinSat(vsctl_tqwhlminsat_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I091(0) */
    Rte_Write_P_VSCtl_tqWhlPotMaxReq_VSCtl_tqWhlPotMaxReq(vsctl_tqwhlpotmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I092(0) */
    Rte_Write_P_VSCtl_tqWhlPotMaxRsvHiThd_VSCtl_tqWhlPotMaxRsvHiThd(vsctl_tqwhlpotmaxrsvhithd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I093(0) */
    Rte_Write_P_VSCtl_tqWhlPotMaxRsvLoThd_VSCtl_tqWhlPotMaxRsvLoThd(vsctl_tqwhlpotmaxrsvlothd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I094(0) */
    Rte_Write_P_VSCtl_tqWhlPotMinReq_VSCtl_tqWhlPotMinReq(vsctl_tqwhlpotminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I095(0) */
    Rte_Write_P_VSCtl_tqWhlPotMinRsvHiThd_VSCtl_tqWhlPotMinRsvHiThd(vsctl_tqwhlpotminrsvhithd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I096(0) */
    Rte_Write_P_VSCtl_tqWhlPotMinRsvLoThd_VSCtl_tqWhlPotMinRsvLoThd(vsctl_tqwhlpotminrsvlothd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I097(0) */
    Rte_Write_P_VSCtl_tqWhlPotReq_VSCtl_tqWhlPotReq(vsctl_tqwhlpotreq_swc_out);

    /* Update 1/Z SWC_OUT  after init */
    vsctl_stctl_tqwhlpotmax_swc_out_prev = vsctl_stctl_tqwhlpotmax_swc_out;
    vsctl_stctl_tqwhlpotmin_swc_out_prev = vsctl_stctl_tqwhlpotmin_swc_out;
    vsctl_stctl_tqwhlmax_swc_out_prev = vsctl_stctl_tqwhlmax_swc_out;

    /* Update Z-4 SWC_OUT  after init */
    vsctl_stctl_tqwhlmin_swc_out_prev[3] = 0;
    vsctl_stctl_tqwhlmin_swc_out_prev[2] = 0;
    vsctl_stctl_tqwhlmin_swc_out_prev[1] = 0;
    vsctl_stctl_tqwhlmin_swc_out_prev[0] = vsctl_stctl_tqwhlmin_swc_out;


}
/*******************************************************************************
*
*  Runnable Name    : RE_VSCo_002_TEV
*  Event            : Every 0.01
*  Description      : Call  scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_VSCo_002_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    Boolean ext_bvslimcf_swc_in;
    Boolean ext_bvsmaxfcf_swc_in;
    Boolean ext_bvsmaxpcf_swc_in;
    Boolean ext_bvsmaxscf_swc_in;
    UInt8 copt_posnlev_swc_in;
    UInt8 ext_stdvsregcf_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    SInt16 vsctl_ares_swc_in;
    SInt16 vsctl_avehdvsregreq_swc_in;
    SInt16 vsctl_avehpotdvsregreq_swc_in;
    SInt16 vsctl_avehpotvslimreq_swc_in;
    SInt16 vsctl_avehpotvsmaxreq_swc_in;
    SInt16 vsctl_avehpotvsregreq_swc_in;
    SInt16 vsctl_avehprecovsctlreq_swc_in;
    SInt16 vsctl_avehptdrvminreq_swc_in;
    SInt16 vsctl_avehptdrvminreqraw_swc_in;
    SInt16 vsctl_avehptlim_swc_in;
    SInt16 vsctl_avehptmax_swc_in;
    SInt16 vsctl_avehptmaxnotctla_swc_in;
    SInt16 vsctl_avehptmin_swc_in;
    SInt16 vsctl_avehptminnotctla_swc_in;
    SInt16 vsctl_avehptpotmax_swc_in;
    SInt16 vsctl_avehptpotmin_swc_in;
    SInt16 vsctl_avehvslimreq_swc_in;
    SInt16 vsctl_avehvsmaxreq_swc_in;
    SInt16 vsctl_avehvsregreq_swc_in;
    Boolean vsctl_bavltqwhlpt_no3_swc_in;
    Boolean vsctl_bctlefc_tqckefcmax_swc_in;
    Boolean vsctl_bctlefc_tqckefcmin_swc_in;
    Boolean vsctl_bctlefc_tqwhlptmax_swc_in;
    Boolean vsctl_bctlefc_tqwhlptmin_swc_in;
    Boolean vsctl_bdrvovrdvsreg_spdveh_swc_in;
    UInt16 vsctl_mveh_swc_in;
    UInt16 vsctl_rctltqwhlptpotdvsreg_swc_in;
    UInt16 vsctl_rctltqwhlptpotvslim_swc_in;
    UInt16 vsctl_rctltqwhlptpotvsmax_swc_in;
    UInt16 vsctl_rctltqwhlptpotvsreg_swc_in;
    UInt16 vsctl_rdwhl_swc_in;
    UInt16 vsctl_spdveh_swc_in;
    Boolean vsctl_stctl_avehdvsreg_swc_in;
    UInt8 vsctl_stctl_avehpotdvsreg_swc_in;
    UInt8 vsctl_bctl_avehpotvslim_swc_in;
    UInt8 vsctl_bctl_avehpotvsmax_swc_in;
    UInt8 vsctl_bctl_avehpotvsreg_swc_in;
    UInt8 vsctl_stctl_avehvslim_swc_in;
    UInt8 vsctl_stctl_avehvsmax_swc_in;
    UInt8 vsctl_stctl_avehvsreg_swc_in;
    UInt8 vsctl_sttqwhlptcutoffreq_swc_in;
    UInt8 vsctl_stvsctlinfo_swc_in;
    UInt16 vsctl_ticfmsdwndvsregreq_swc_in;
    UInt16 vsctl_ticfmsdwnvslimreq_swc_in;
    UInt16 vsctl_ticfmsdwnvsmaxreq_swc_in;
    UInt16 vsctl_ticfmsdwnvsregreq_swc_in;
    UInt16 vsctl_ticfmsupdvsregreq_swc_in;
    UInt16 vsctl_ticfmsupvslimreq_swc_in;
    UInt16 vsctl_ticfmsupvsmaxreq_swc_in;
    UInt16 vsctl_ticfmsupvsregreq_swc_in;
    SInt16 vsctl_tqwhlptmax_swc_in;
    SInt16 vsctl_tqwhlptmin_swc_in;
    SInt16 vsctl_tqwhlptpotmax_swc_in;
    SInt16 vsctl_tqwhlptpotmin_swc_in;
    SInt16 vsctl_tqwhlthptmin_swc_in;
    SInt16 vsctl_tqwhlthptpotmin_swc_in;
    Boolean ext_bposngbxcf_swc_in;
    UInt8 ext_stctlcmdpttqpotcf_swc_in;
    /* FIM (FRM) */
    Boolean vsco_bool_temp;
    Boolean frm_bdeacvsctlkdctl_fim_in;
    /* OUTPUT */
    /* SWC OUT */
    SInt16 vsctl_avehcordvslimreq_swc_out;
    SInt16 vsctl_avehcordvsregreq_swc_out;
    SInt16 vsctl_avehreq_swc_out;
    UInt8 vsctl_bauthanttqwhlmax_swc_out;
    UInt8 vsctl_bauthanttqwhlmin_swc_out;
    UInt8 vsctl_bdrvovrddvsreg_aveh_swc_out;
    UInt8 vsctl_bdrvovrdvslim_aveh_swc_out;
    UInt8 vsctl_bdrvovrdvsmax_aveh_swc_out;
    UInt8 vsctl_bdrvovrdvsreg_aveh_swc_out;
    UInt8 vsctl_bendtranvslim_swc_out;
    UInt8 vsctl_bendtranvsmax_swc_out;
    UInt8 vsctl_bendtranvsreg_swc_out;
    UInt8 vsctl_bkdauth_swc_out;
    UInt8 vsctl_btqwhlminsat_swc_out;
    UInt8 vsctl_stctl_tqwhlmax_swc_out;
    UInt8 vsctl_stctl_tqwhlmin_swc_out;
    UInt8 vsctl_stctl_tqwhlpot_swc_out;
    UInt8 vsctl_stctl_tqwhlpotmax_swc_out;
    UInt8 vsctl_stctl_tqwhlpotmin_swc_out;
    UInt16 vsctl_ticfmsdwntqmaxreq_swc_out;
    UInt16 vsctl_ticfmsdwntqminreq_swc_out;
    UInt16 vsctl_ticfmsuptqmaxreq_swc_out;
    UInt16 vsctl_ticfmsuptqminreq_swc_out;
    SInt16 vsctl_tqwhlmaxreq_swc_out;
    SInt16 vsctl_tqwhlminreq_swc_out;
    SInt16 vsctl_tqwhlminsat_swc_out;
    SInt16 vsctl_tqwhlpotmaxreq_swc_out;
    SInt16 vsctl_tqwhlpotmaxrsvhithd_swc_out;
    SInt16 vsctl_tqwhlpotmaxrsvlothd_swc_out;
    SInt16 vsctl_tqwhlpotminreq_swc_out;
    SInt16 vsctl_tqwhlpotminrsvhithd_swc_out;
    SInt16 vsctl_tqwhlpotminrsvlothd_swc_out;
    SInt16 vsctl_tqwhlpotreq_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)VSCO_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I100(0) */
        Rte_Read_R_Ext_bPosnGBxCf_Ext_bPosnGBxCf(&ext_bposngbxcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I002(0) */
        Rte_Read_R_Ext_bVSLimCf_Ext_bVSLimCf(&ext_bvslimcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I003(0) */
        Rte_Read_R_Ext_bVSMaxfCf_Ext_bVSMaxfCf(&ext_bvsmaxfcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I004(0) */
        Rte_Read_R_Ext_bVSMaxpCf_Ext_bVSMaxpCf(&ext_bvsmaxpcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I005(0) */
        Rte_Read_R_Ext_bVSMaxsCf_Ext_bVSMaxsCf(&ext_bvsmaxscf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I006(0) */
        Rte_Read_R_CoPt_posnLev_CoPt_posnLev(&copt_posnlev_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I101(0) */
        Rte_Read_R_Ext_stCtlCmdPTTqPotCf_Ext_stCtlCmdPTTqPotCf(&ext_stctlcmdpttqpotcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I007(0) */
        Rte_Read_R_Ext_stDVSRegCf_Ext_stDVSRegCf(&ext_stdvsregcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I008(0) */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I009(0) */
        Rte_Read_R_VSCtl_aRes_VSCtl_aRes(&vsctl_ares_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I010(0) */
        Rte_Read_R_VSCtl_aVehDVSRegReq_VSCtl_aVehDVSRegReq(&vsctl_avehdvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I016(0) */
        Rte_Read_R_VSCtl_aVehPTDrvMinReq_VSCtl_aVehPTDrvMinReq(&vsctl_avehptdrvminreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I017(0) */
        Rte_Read_R_VSCtl_aVehPTDrvMinReqRaw_VSCtl_aVehPTDrvMinReqRaw(&vsctl_avehptdrvminreqraw_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I018(0) */
        Rte_Read_R_VSCtl_aVehPTLim_VSCtl_aVehPTLim(&vsctl_avehptlim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I019(0) */
        Rte_Read_R_VSCtl_aVehPTMax_VSCtl_aVehPTMax(&vsctl_avehptmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I020(0) */
        Rte_Read_R_VSCtl_aVehPTMaxNotCtla_VSCtl_aVehPTMaxNotCtla(&vsctl_avehptmaxnotctla_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I021(0) */
        Rte_Read_R_VSCtl_aVehPTMin_VSCtl_aVehPTMin(&vsctl_avehptmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I022(0) */
        Rte_Read_R_VSCtl_aVehPTMinNotCtla_VSCtl_aVehPTMinNotCtla(&vsctl_avehptminnotctla_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I023(0) */
        Rte_Read_R_VSCtl_aVehPTPotMax_VSCtl_aVehPTPotMax(&vsctl_avehptpotmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I024(0) */
        Rte_Read_R_VSCtl_aVehPTPotMin_VSCtl_aVehPTPotMin(&vsctl_avehptpotmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I011(0) */
        Rte_Read_R_VSCtl_aVehPotDVSRegReq_VSCtl_aVehPotDVSRegReq(&vsctl_avehpotdvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I012(0) */
        Rte_Read_R_VSCtl_aVehPotVSLimReq_VSCtl_aVehPotVSLimReq(&vsctl_avehpotvslimreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I013(0) */
        Rte_Read_R_VSCtl_aVehPotVSMaxReq_VSCtl_aVehPotVSMaxReq(&vsctl_avehpotvsmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I014(0) */
        Rte_Read_R_VSCtl_aVehPotVSRegReq_VSCtl_aVehPotVSRegReq(&vsctl_avehpotvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I015(0) */
        Rte_Read_R_VSCtl_aVehPreCoVSCtlReq_VSCtl_aVehPreCoVSCtlReq(&vsctl_avehprecovsctlreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I025(0) */
        Rte_Read_R_VSCtl_aVehVSLimReq_VSCtl_aVehVSLimReq(&vsctl_avehvslimreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I026(0) */
        Rte_Read_R_VSCtl_aVehVSMaxReq_VSCtl_aVehVSMaxReq(&vsctl_avehvsmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I027(0) */
        Rte_Read_R_VSCtl_aVehVSRegReq_VSCtl_aVehVSRegReq(&vsctl_avehvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I028(0) */
        Rte_Read_R_VSCtl_bAvlTqWhlPT_no3_VSCtl_bAvlTqWhlPT_no3(&vsctl_bavltqwhlpt_no3_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I029(0) */
        Rte_Read_R_VSCtl_bCtlEfc_tqCkEfcMax_VSCtl_bCtlEfc_tqCkEfcMax(&vsctl_bctlefc_tqckefcmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I030(0) */
        Rte_Read_R_VSCtl_bCtlEfc_tqCkEfcMin_VSCtl_bCtlEfc_tqCkEfcMin(&vsctl_bctlefc_tqckefcmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I031(0) */
        Rte_Read_R_VSCtl_bCtlEfc_tqWhlPTMax_VSCtl_bCtlEfc_tqWhlPTMax(&vsctl_bctlefc_tqwhlptmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I032(0) */
        Rte_Read_R_VSCtl_bCtlEfc_tqWhlPTMin_VSCtl_bCtlEfc_tqWhlPTMin(&vsctl_bctlefc_tqwhlptmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I043(2) */
        Rte_Read_R_VSCtl_bCtl_aVehPotVSLim_VSCtl_bCtl_aVehPotVSLim(&vsctl_bctl_avehpotvslim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I044(2) */
        Rte_Read_R_VSCtl_bCtl_aVehPotVSMax_VSCtl_bCtl_aVehPotVSMax(&vsctl_bctl_avehpotvsmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I045(2) */
        Rte_Read_R_VSCtl_bCtl_aVehPotVSReg_VSCtl_bCtl_aVehPotVSReg(&vsctl_bctl_avehpotvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I033(0) */
        Rte_Read_R_VSCtl_bDrvOvrdVSReg_spdVeh_VSCtl_bDrvOvrdVSReg_spdVeh(&vsctl_bdrvovrdvsreg_spdveh_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I034(0) */
        Rte_Read_R_VSCtl_mVeh_VSCtl_mVeh(&vsctl_mveh_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I035(0) */
        Rte_Read_R_VSCtl_rCtlTqWhlPTPotDVSReg_VSCtl_rCtlTqWhlPTPotDVSReg(&vsctl_rctltqwhlptpotdvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I036(0) */
        Rte_Read_R_VSCtl_rCtlTqWhlPTPotVSLim_VSCtl_rCtlTqWhlPTPotVSLim(&vsctl_rctltqwhlptpotvslim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I037(0) */
        Rte_Read_R_VSCtl_rCtlTqWhlPTPotVSMax_VSCtl_rCtlTqWhlPTPotVSMax(&vsctl_rctltqwhlptpotvsmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I038(0) */
        Rte_Read_R_VSCtl_rCtlTqWhlPTPotVSReg_VSCtl_rCtlTqWhlPTPotVSReg(&vsctl_rctltqwhlptpotvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I039(0) */
        Rte_Read_R_VSCtl_rdWhl_VSCtl_rdWhl(&vsctl_rdwhl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I040(0) */
        Rte_Read_R_VSCtl_spdVeh_VSCtl_spdVeh(&vsctl_spdveh_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I041(0) */
        Rte_Read_R_VSCtl_stCtl_aVehDVSReg_VSCtl_stCtl_aVehDVSReg(&vsctl_stctl_avehdvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I042(0) */
        Rte_Read_R_VSCtl_stCtl_aVehPotDVSReg_VSCtl_stCtl_aVehPotDVSReg(&vsctl_stctl_avehpotdvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I046(0) */
        Rte_Read_R_VSCtl_stCtl_aVehVSLim_VSCtl_stCtl_aVehVSLim(&vsctl_stctl_avehvslim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I047(0) */
        Rte_Read_R_VSCtl_stCtl_aVehVSMax_VSCtl_stCtl_aVehVSMax(&vsctl_stctl_avehvsmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I048(0) */
        Rte_Read_R_VSCtl_stCtl_aVehVSReg_VSCtl_stCtl_aVehVSReg(&vsctl_stctl_avehvsreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I049(0) */
        Rte_Read_R_VSCtl_stTqWhlPTCutOffReq_VSCtl_stTqWhlPTCutOffReq(&vsctl_sttqwhlptcutoffreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I050(0) */
        Rte_Read_R_VSCtl_stVSCtlInfo_VSCtl_stVSCtlInfo(&vsctl_stvsctlinfo_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I051(0) */
        Rte_Read_R_VSCtl_tiCfmSdwnDVSRegReq_VSCtl_tiCfmSdwnDVSRegReq(&vsctl_ticfmsdwndvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I052(0) */
        Rte_Read_R_VSCtl_tiCfmSdwnVSLimReq_VSCtl_tiCfmSdwnVSLimReq(&vsctl_ticfmsdwnvslimreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I053(0) */
        Rte_Read_R_VSCtl_tiCfmSdwnVSMaxReq_VSCtl_tiCfmSdwnVSMaxReq(&vsctl_ticfmsdwnvsmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I054(0) */
        Rte_Read_R_VSCtl_tiCfmSdwnVSRegReq_VSCtl_tiCfmSdwnVSRegReq(&vsctl_ticfmsdwnvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I055(0) */
        Rte_Read_R_VSCtl_tiCfmSupDVSRegReq_VSCtl_tiCfmSupDVSRegReq(&vsctl_ticfmsupdvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I056(0) */
        Rte_Read_R_VSCtl_tiCfmSupVSLimReq_VSCtl_tiCfmSupVSLimReq(&vsctl_ticfmsupvslimreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I057(0) */
        Rte_Read_R_VSCtl_tiCfmSupVSMaxReq_VSCtl_tiCfmSupVSMaxReq(&vsctl_ticfmsupvsmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I058(0) */
        Rte_Read_R_VSCtl_tiCfmSupVSRegReq_VSCtl_tiCfmSupVSRegReq(&vsctl_ticfmsupvsregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I059(0) */
        Rte_Read_R_VSCtl_tqWhlPTMax_VSCtl_tqWhlPTMax(&vsctl_tqwhlptmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I060(0) */
        Rte_Read_R_VSCtl_tqWhlPTMin_VSCtl_tqWhlPTMin(&vsctl_tqwhlptmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I061(0) */
        Rte_Read_R_VSCtl_tqWhlPTPotMax_VSCtl_tqWhlPTPotMax(&vsctl_tqwhlptpotmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I062(0) */
        Rte_Read_R_VSCtl_tqWhlPTPotMin_VSCtl_tqWhlPTPotMin(&vsctl_tqwhlptpotmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I063(0) */
        Rte_Read_R_VSCtl_tqWhlThPTMin_VSCtl_tqWhlThPTMin(&vsctl_tqwhlthptmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I064(0) */
        Rte_Read_R_VSCtl_tqWhlThPTPotMin_VSCtl_tqWhlThPTPotMin(&vsctl_tqwhlthptpotmin_swc_in);

        /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I099(0) */
        Rte_Call_R_FRM_bDeacVSCtlKDCtl_GetFunctionPermission(&vsco_bool_temp);
        frm_bdeacvsctlkdctl_fim_in = ((UInt32)vsco_bool_temp == (UInt32)DDS_FALSE);



    VSCO_Veh_Accel_Cons(vsctl_sttqwhlptcutoffreq_swc_in,
                            vsctl_spdveh_swc_in, /* BIN7 */
                            copt_posnlev_swc_in,
                            ext_stgbxcf_swc_in,
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bavltqwhlpt_no3_swc_in),
                            vsctl_stvsctlinfo_swc_in,
                            vsctl_avehptminnotctla_swc_in, /* BIN10 */
                            vsctl_avehptmaxnotctla_swc_in, /* BIN10 */
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvslimcf_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvsmaxfcf_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvsmaxpcf_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvsmaxscf_swc_in),
                            ext_stdvsregcf_swc_in,
                            vsctl_avehprecovsctlreq_swc_in, /* BIN10 */
                            vsctl_avehvslimreq_swc_in, /* BIN10 */
                            vsctl_avehvsmaxreq_swc_in, /* BIN10 */
                            vsctl_avehvsregreq_swc_in, /* BIN10 */
                            vsctl_avehdvsregreq_swc_in, /* BIN10 */
                            vsctl_avehptmax_swc_in, /* BIN10 */
                            vsctl_avehptmin_swc_in, /* BIN10 */
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlefc_tqckefcmax_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlefc_tqckefcmin_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlefc_tqwhlptmax_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bctlefc_tqwhlptmin_swc_in),
                            vsctl_avehptlim_swc_in, /* BIN10 */
                            vsctl_avehptdrvminreq_swc_in, /* BIN10 */
                            vsctl_avehptdrvminreqraw_swc_in, /* BIN10 */
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bdrvovrdvsreg_spdveh_swc_in),
                            vsctl_stctl_tqwhlmax_swc_out_prev,
                            vsctl_stctl_tqwhlmin_swc_out_prev[3],
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_bposngbxcf_swc_in),
                            &vsctl_avehreq_swc_out, /* BIN10 */
                            &vsctl_avehcordvslimreq_swc_out, /* BIN10 */
                            &vsctl_avehcordvsregreq_swc_out, /* BIN10 */
                            &vsctl_bendtranvsreg_swc_out,
                            &vsctl_bendtranvslim_swc_out,
                            &vsctl_bendtranvsmax_swc_out,
                            &vsctl_bdrvovrdvsreg_aveh_swc_out,
                            &vsctl_bdrvovrddvsreg_aveh_swc_out,
                            &vsctl_bdrvovrdvslim_aveh_swc_out,
                            &vsctl_bdrvovrdvsmax_aveh_swc_out);


    VSCO_Wheel_Torque_Cons(vsctl_tqwhlptmin_swc_in, /* BIN1 */
                               vsctl_tqwhlptmax_swc_in, /* BIN1 */
                               vsctl_stctl_avehvsreg_swc_in,
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_avehdvsreg_swc_in),
                               vsctl_stctl_avehvslim_swc_in,
                               vsctl_stctl_avehvsmax_swc_in,
                               vsctl_mveh_swc_in, /* BIN0 */
                               vsctl_rdwhl_swc_in, /* BIN7 */
                               vsctl_ares_swc_in, /* BIN10 */
                               vsctl_tqwhlthptmin_swc_in, /* BIN1 */
                               vsctl_tqwhlthptpotmin_swc_in, /* BIN1 */
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bdrvovrdvsreg_spdveh_swc_in),
                               &vsctl_tqwhlminreq_swc_out, /* BIN1 */
                               &vsctl_tqwhlmaxreq_swc_out, /* BIN1 */
                               &vsctl_bauthanttqwhlmin_swc_out,
                               &vsctl_bauthanttqwhlmax_swc_out,
                               &vsctl_stctl_tqwhlmin_swc_out,
                               &vsctl_stctl_tqwhlmax_swc_out,
                               &vsctl_tqwhlminsat_swc_out, /* BIN1 */
                               &vsctl_btqwhlminsat_swc_out);


    VSCO_Veh_Acc_Pot_Act_Cons(/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_bavltqwhlpt_no3_swc_in),
                                  vsctl_ares_swc_in, /* BIN10 */
                                  vsctl_avehpotvsregreq_swc_in, /* BIN10 */
                                  vsctl_avehpotvslimreq_swc_in, /* BIN10 */
                                  vsctl_avehpotdvsregreq_swc_in, /* BIN10 */
                                  vsctl_avehpotvsmaxreq_swc_in, /* BIN10 */
                                  vsctl_spdveh_swc_in, /* BIN7 */
                                  ext_stgbxcf_swc_in,
                                  copt_posnlev_swc_in,
                                  vsctl_avehptmin_swc_in, /* BIN10 */
                                  vsctl_avehptmax_swc_in, /* BIN10 */
                                  vsctl_stvsctlinfo_swc_in,
                                  vsctl_avehptpotmax_swc_in, /* BIN10 */
                                  vsctl_avehptpotmin_swc_in, /* BIN10 */
                                  ext_stdvsregcf_swc_in,
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvslimcf_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvsmaxfcf_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvsmaxpcf_swc_in),
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(ext_bvsmaxscf_swc_in),
                                  vsctl_stctl_tqwhlpotmax_swc_out_prev,
                                  vsctl_stctl_tqwhlpotmin_swc_out_prev,
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(ext_bposngbxcf_swc_in),
                                  ext_stctlcmdpttqpotcf_swc_in);

    VSCO_Whl_Tq_Pot_Cons_Kick(vsctl_mveh_swc_in, /* BIN0 */
                                  vsctl_rdwhl_swc_in, /* BIN7 */
                                  vsctl_rctltqwhlptpotvslim_swc_in, /* BIN4 */
                                  vsctl_rctltqwhlptpotvsmax_swc_in, /* BIN4 */
                                  vsctl_rctltqwhlptpotdvsreg_swc_in, /* BIN4 */
                                  vsctl_rctltqwhlptpotvsreg_swc_in, /* BIN4 */
                                  vsctl_tqwhlptpotmax_swc_in, /* BIN1 */
                                  vsctl_tqwhlptpotmin_swc_in, /* BIN1 */
                                  vsctl_bctl_avehpotvsmax_swc_in,
                                  vsctl_bctl_avehpotvsreg_swc_in,
                                  vsctl_bctl_avehpotvslim_swc_in,
                                  vsctl_stctl_avehpotdvsreg_swc_in,
                                  vsctl_ticfmsdwndvsregreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsdwnvslimreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsdwnvsmaxreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsdwnvsregreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsupdvsregreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsupvslimreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsupvsmaxreq_swc_in, /* DEC2 */
                                  vsctl_ticfmsupvsregreq_swc_in, /* DEC2 */
                                  vsctl_stvsctlinfo_swc_in,
                                  ext_stctlcmdpttqpotcf_swc_in,
                                  vsctl_bdrvovrdvsmax_aveh_swc_out,
                                  vsctl_bdrvovrdvslim_aveh_swc_out,
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(vsctl_stctl_avehdvsreg_swc_in),
                                  vsctl_stctl_avehvslim_swc_in,
                                  vsctl_stctl_avehvsmax_swc_in,
                                  vsctl_stctl_avehvsreg_swc_in,
                /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdeacvsctlkdctl_fim_in),
                                  &vsctl_tqwhlpotminreq_swc_out,
                                  &vsctl_tqwhlpotmaxreq_swc_out,
                                  &vsctl_tqwhlpotminrsvlothd_swc_out,
                                  &vsctl_tqwhlpotminrsvhithd_swc_out,
                                  &vsctl_tqwhlpotmaxrsvlothd_swc_out,
                                  &vsctl_tqwhlpotmaxrsvhithd_swc_out,
                                  &vsctl_ticfmsdwntqmaxreq_swc_out,
                                  &vsctl_ticfmsdwntqminreq_swc_out,
                                  &vsctl_ticfmsuptqmaxreq_swc_out,
                                  &vsctl_ticfmsuptqminreq_swc_out,
                                  &vsctl_stctl_tqwhlpot_swc_out,
                                  &vsctl_stctl_tqwhlpotmax_swc_out,
                                  &vsctl_stctl_tqwhlpotmin_swc_out,
                                  &vsctl_tqwhlpotreq_swc_out,
                                  &vsctl_bkdauth_swc_out);



    }
    else
    {
        vsctl_avehcordvslimreq_swc_out = VSCtl_aVehCordVSLimReq_B;
        vsctl_avehcordvsregreq_swc_out = VSCtl_aVehCordVSRegReq_B;
        vsctl_avehreq_swc_out = VSCtl_aVehReq_B;
        vsctl_bauthanttqwhlmax_swc_out = VSCtl_bAuthAntTqWhlMax_B;
        vsctl_bauthanttqwhlmin_swc_out = VSCtl_bAuthAntTqWhlMin_B;
        vsctl_bdrvovrddvsreg_aveh_swc_out = VSCtl_bDrvOvrdDVSReg_aVeh_B;
        vsctl_bdrvovrdvslim_aveh_swc_out = VSCtl_bDrvOvrdVSLim_aVeh_B;
        vsctl_bdrvovrdvsmax_aveh_swc_out = VSCtl_bDrvOvrdVSMax_aVeh_B;
        vsctl_bdrvovrdvsreg_aveh_swc_out = VSCtl_bDrvOvrdVSReg_aVeh_B;
        vsctl_bendtranvslim_swc_out = VSCtl_bEndTranVSLim_B;
        vsctl_bendtranvsmax_swc_out = VSCtl_bEndTranVSMax_B;
        vsctl_bendtranvsreg_swc_out = VSCtl_bEndTranVSReg_B;
        vsctl_bkdauth_swc_out = VSCtl_bKdAuth_B;
        vsctl_btqwhlminsat_swc_out = VSCtl_bTqWhlMinSat_B;
        vsctl_stctl_tqwhlmax_swc_out = VSCtl_stCtl_tqWhlMax_B;
        vsctl_stctl_tqwhlmin_swc_out = VSCtl_stCtl_tqWhlMin_B;
        vsctl_stctl_tqwhlpot_swc_out = VSCtl_stCtl_tqWhlPot_B;
        vsctl_stctl_tqwhlpotmax_swc_out = VSCtl_stCtl_tqWhlPotMax_B;
        vsctl_stctl_tqwhlpotmin_swc_out = VSCtl_stCtl_tqWhlPotMin_B;
        vsctl_ticfmsdwntqmaxreq_swc_out = VSCtl_tiCfmSdwnTqMaxReq_B;
        vsctl_ticfmsdwntqminreq_swc_out = VSCtl_tiCfmSdwnTqMinReq_B;
        vsctl_ticfmsuptqmaxreq_swc_out = VSCtl_tiCfmSupTqMaxReq_B;
        vsctl_ticfmsuptqminreq_swc_out = VSCtl_tiCfmSupTqMinReq_B;
        vsctl_tqwhlmaxreq_swc_out = VSCtl_tqWhlMaxReq_B;
        vsctl_tqwhlminreq_swc_out = VSCtl_tqWhlMinReq_B;
        vsctl_tqwhlminsat_swc_out = VSCtl_tqWhlMinSat_B;
        vsctl_tqwhlpotmaxreq_swc_out = VSCtl_tqWhlPotMaxReq_B;
        vsctl_tqwhlpotmaxrsvhithd_swc_out = VSCtl_tqWhlPotMaxRsvHiThd_B;
        vsctl_tqwhlpotmaxrsvlothd_swc_out = VSCtl_tqWhlPotMaxRsvLoThd_B;
        vsctl_tqwhlpotminreq_swc_out = VSCtl_tqWhlPotMinReq_B;
        vsctl_tqwhlpotminrsvhithd_swc_out = VSCtl_tqWhlPotMinRsvHiThd_B;
        vsctl_tqwhlpotminrsvlothd_swc_out = VSCtl_tqWhlPotMinRsvLoThd_B;
        vsctl_tqwhlpotreq_swc_out = VSCtl_tqWhlPotReq_B;

    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I065(0) */
    Rte_Write_P_VSCtl_aVehCordVSLimReq_VSCtl_aVehCordVSLimReq(vsctl_avehcordvslimreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I066(0) */
    Rte_Write_P_VSCtl_aVehCordVSRegReq_VSCtl_aVehCordVSRegReq(vsctl_avehcordvsregreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I067(0) */
    Rte_Write_P_VSCtl_aVehReq_VSCtl_aVehReq(vsctl_avehreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I068(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAuthAntTqWhlMax_VSCtl_bAuthAntTqWhlMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bauthanttqwhlmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I069(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bAuthAntTqWhlMin_VSCtl_bAuthAntTqWhlMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bauthanttqwhlmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I070(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdDVSReg_aVeh_VSCtl_bDrvOvrdDVSReg_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrddvsreg_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I071(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdVSLim_aVeh_VSCtl_bDrvOvrdVSLim_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrdvslim_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I072(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdVSMax_aVeh_VSCtl_bDrvOvrdVSMax_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrdvsmax_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I073(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bDrvOvrdVSReg_aVeh_VSCtl_bDrvOvrdVSReg_aVeh(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bdrvovrdvsreg_aveh_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I074(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bEndTranVSLim_VSCtl_bEndTranVSLim(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bendtranvslim_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I075(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bEndTranVSMax_VSCtl_bEndTranVSMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bendtranvsmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I076(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bEndTranVSReg_VSCtl_bEndTranVSReg(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bendtranvsreg_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I077(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bKdAuth_VSCtl_bKdAuth(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_bkdauth_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I078(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_bTqWhlMinSat_VSCtl_bTqWhlMinSat(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_btqwhlminsat_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I079(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_stCtl_tqWhlMax_VSCtl_stCtl_tqWhlMax(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_stctl_tqwhlmax_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I080(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_stCtl_tqWhlMin_VSCtl_stCtl_tqWhlMin(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_stctl_tqwhlmin_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I081(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_VSCtl_stCtl_tqWhlPot_VSCtl_stCtl_tqWhlPot(DDS_M_CONVERT_UINT8_TO_BOOL(vsctl_stctl_tqwhlpot_swc_out));
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I082(1) */
    Rte_Write_P_VSCtl_stCtl_tqWhlPotMax_VSCtl_stCtl_tqWhlPotMax(vsctl_stctl_tqwhlpotmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I083(1) */
    Rte_Write_P_VSCtl_stCtl_tqWhlPotMin_VSCtl_stCtl_tqWhlPotMin(vsctl_stctl_tqwhlpotmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I084(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnTqMaxReq_VSCtl_tiCfmSdwnTqMaxReq(vsctl_ticfmsdwntqmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I085(0) */
    Rte_Write_P_VSCtl_tiCfmSdwnTqMinReq_VSCtl_tiCfmSdwnTqMinReq(vsctl_ticfmsdwntqminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I086(0) */
    Rte_Write_P_VSCtl_tiCfmSupTqMaxReq_VSCtl_tiCfmSupTqMaxReq(vsctl_ticfmsuptqmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I087(0) */
    Rte_Write_P_VSCtl_tiCfmSupTqMinReq_VSCtl_tiCfmSupTqMinReq(vsctl_ticfmsuptqminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I088(0) */
    Rte_Write_P_VSCtl_tqWhlMaxReq_VSCtl_tqWhlMaxReq(vsctl_tqwhlmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I089(0) */
    Rte_Write_P_VSCtl_tqWhlMinReq_VSCtl_tqWhlMinReq(vsctl_tqwhlminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I090(0) */
    Rte_Write_P_VSCtl_tqWhlMinSat_VSCtl_tqWhlMinSat(vsctl_tqwhlminsat_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I091(0) */
    Rte_Write_P_VSCtl_tqWhlPotMaxReq_VSCtl_tqWhlPotMaxReq(vsctl_tqwhlpotmaxreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I092(0) */
    Rte_Write_P_VSCtl_tqWhlPotMaxRsvHiThd_VSCtl_tqWhlPotMaxRsvHiThd(vsctl_tqwhlpotmaxrsvhithd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I093(0) */
    Rte_Write_P_VSCtl_tqWhlPotMaxRsvLoThd_VSCtl_tqWhlPotMaxRsvLoThd(vsctl_tqwhlpotmaxrsvlothd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I094(0) */
    Rte_Write_P_VSCtl_tqWhlPotMinReq_VSCtl_tqWhlPotMinReq(vsctl_tqwhlpotminreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I095(0) */
    Rte_Write_P_VSCtl_tqWhlPotMinRsvHiThd_VSCtl_tqWhlPotMinRsvHiThd(vsctl_tqwhlpotminrsvhithd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I096(0) */
    Rte_Write_P_VSCtl_tqWhlPotMinRsvLoThd_VSCtl_tqWhlPotMinRsvLoThd(vsctl_tqwhlpotminrsvlothd_swc_out);
    /* SSTG_REQ_TAG: 01552_10_02850-VSCo-I097(0) */
    Rte_Write_P_VSCtl_tqWhlPotReq_VSCtl_tqWhlPotReq(vsctl_tqwhlpotreq_swc_out);

    /* Update 1/Z SWC_OUT */
    vsctl_stctl_tqwhlpotmax_swc_out_prev = vsctl_stctl_tqwhlpotmax_swc_out;
    vsctl_stctl_tqwhlpotmin_swc_out_prev = vsctl_stctl_tqwhlpotmin_swc_out;
    vsctl_stctl_tqwhlmax_swc_out_prev = vsctl_stctl_tqwhlmax_swc_out;

    /* Update Z-4 SWC_OUT */
    vsctl_stctl_tqwhlmin_swc_out_prev[3] = vsctl_stctl_tqwhlmin_swc_out_prev[2];
    vsctl_stctl_tqwhlmin_swc_out_prev[2] = vsctl_stctl_tqwhlmin_swc_out_prev[1];
    vsctl_stctl_tqwhlmin_swc_out_prev[1] = vsctl_stctl_tqwhlmin_swc_out_prev[0];
    vsctl_stctl_tqwhlmin_swc_out_prev[0] = vsctl_stctl_tqwhlmin_swc_out;

}

/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : VSCo_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) VSCo_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_VSCo_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define VSCO_STOP_SEC_CODE
#include "VSCo_MemMap.h"

