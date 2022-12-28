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
* Ref X:\integration_view_00PSASWC_E414D11\blois_psa_sstg\Software\Appli\TqDem\src\TqDem.c
* Version int :/main/00PSASWC_E4/BR_00PSASWC_E41/2 Date: 14/3/2013 12 h 6 m User:meme 
*    TWK_model:NO_MODEL
*    comments :For Tqdem 11.4
* Version dev :\main\branch_thauvin_euro6\1 Date: 14/3/2013 10 h 40 m User:thauvin 
*    TWK_model:NO_MODEL
*    comments :For Tqdem 11.4
* Version int :/main/00PSASWC_E4/BR_00PSASWC_E41/1 Date: 17/7/2012 15 h 49 m User:posmyk
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.3 CDC 1.9
* Version dev :\main\branch_lemort_dev_tqdem\3 Date: 11/7/2012 15 h 45 m User:lemort
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.3 CDC 1.9
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 11/7/2012 11 h 14 m User:lemort
*    TWK_model:NO_MODEL
*    comments :for TqDem 11.3 CDC 1.9
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 11 m User:lemort
*    TWK_model:NO_MODEL
*    comments :change TqDem_ModuleVersion_Minor_MP from 2 to 3
* Version int :/main/00PSASWC_E4/5 Date: 15/9/2011 10 h 19 m User:meme
*    TWK_model:NO_MODEL
*    comments :Update for TqDem 11.2
* Version dev :\main\branch_moisan_module_dev\1 Date: 14/9/2011 16 h 59 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for TqDem 11.2
* Version int :/main/00PSASWC_E4/4 Date: 10/3/2011 11 h 45 m User:esnault
*    TWK_model:NO_MODEL
*    comments :TqDem 11.1: CSEE_CLCO09_0318 1.5
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 1/3/2011 15 h 21 m User:moisan
*    TWK_model:NO_MODEL
*    comments :TqDem 11.1: CSEE_CLCO09_0318 1.5
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/3/2011 14 h 10 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update code for TqDem v11.1: new STIL 01552_10_01245_11.2.xls
* Version int :/main/00PSASWC_E4/3 Date: 13/1/2011 14 h 48 m User:meme
*    TWK_model:NO_MODEL
*    comments :For TqDem 11.0.. Spec CSMT_CGMT05_1397_v3_1
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 4/1/2011 12 h 21 m User:demezil
*    TWK_model:NO_MODEL
*    comments :For TqDem 11.0.. Spec CSMT_CGMT05_1397_v3_1
* Version int :/main/00PSASWC_E4/2 Date: 8/10/2010 16 h 30 m User:meme
*    TWK_model:NO_MODEL
*    comments :change TqDem_ModuleVersion_Minor_MP 0 to 1
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 8/10/2010 9 h 35 m User:lemort
*    TWK_model:NO_MODEL
*    comments :change TqDem_ModuleVersion_Minor_MP 0 to 1
* Version int :/main/00PSASWC_E4/1 Date: 1/9/2010 14 h 3 m User:esnault
*    TWK_model:NO_MODEL
*    comments :dev in progress
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev in progress
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "TqDem.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if TQDEM_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
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
#define TQDEM_START_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) CoVSCtl_tqEfcReq_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) DZone_tqEfcDifLrnOut_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcDeltaEcoNorm_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcDeltaTakeOff_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcMax_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcMin_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcWoutAntiDB_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfc_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkTakeOffMap_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqIdcLimNReg_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqLimEM_tqLimEM_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPEng_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPTra_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facGainFil_nCk_B = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_nEngReq_B = (CONST(UInt16, AUTOMATIC))(750 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPSptMod_B = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rDrivTakeOff_B = (CONST(UInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rTranDrv_B = (CONST(UInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rTranEcoNorm_B = (CONST(UInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nOfsTotTakeOff_B = (CONST(UInt16, AUTOMATIC))(0 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTarFFL_B = (CONST(UInt16, AUTOMATIC))(0 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTarIdlCVCReq_B = (CONST(UInt16, AUTOMATIC))(0 * BIN2);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"

STATIC volatile CONST(UInt8, AUTOMATIC) CoVSCtl_stAccP_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_002_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_003_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_004_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_005_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_006_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_007_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) RE_TQDEM_008_TEV_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bAcvNRegTakeOff_B = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bDrivTakeOff_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bModSpt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_bTqGrdLim_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_idxMapRvsDrv_B = (CONST(UInt8, AUTOMATIC))(5 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_idxMapTranDrvFirst_B = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqDem_idxMapTranDrvSec_B = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"



/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQDEM_START_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqEfcNRegTakeOffEco_B
[TQDEM_2_SIZE] = {
(CONST(SInt16, AUTOMATIC))(0 * BIN4), (CONST(SInt16, AUTOMATIC))(0 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqDem_tqEfcNRegTakeOffNorm_B
[TQDEM_2_SIZE] = {
(CONST(SInt16, AUTOMATIC))(0 * BIN4), (CONST(SInt16, AUTOMATIC))(0 * BIN4)
};

#define TQDEM_STOP_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDeltaEcoNorm;
STATIC VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcDeltaTakeOff;
STATIC VAR(UInt16, AUTOMATIC) TqDem_rTranDrv;
STATIC VAR(UInt16, AUTOMATIC) TqDem_rTranEcoNorm;
#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) TqDem_idxMapRvsDrv;
STATIC VAR(UInt8, AUTOMATIC) TqDem_idxMapTranDrvFirst;
STATIC VAR(UInt8, AUTOMATIC) TqDem_idxMapTranDrvSec;
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"



/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define TQDEM_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TqDem_MemMap.h"
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) TqDem_ModuleVersion_Major_MP = (UInt8)11;
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) TqDem_ModuleVersion_Minor_MP = (UInt8)4;
#define TQDEM_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_001_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqsys_nofstottakeoff_swc_out;
    UInt16 tqsys_ntarffl_swc_out;
    UInt16 tqsys_ntaridlcvcreq_swc_out;
    UInt16 tqdem_facgainfil_nck_swc_out;
    UInt8 tqdem_bdrivtakeoff_swc_out;
    UInt8 tqdem_btqgrdlim_swc_out;
    SInt16 tqdem_tqckefc_swc_out;
    SInt16 tqdem_tqckefcmax_swc_out;
    SInt16 tqdem_tqckefcmin_swc_out;
    UInt16 covsctl_raccpeng_swc_out;
    UInt16 covsctl_raccptra_swc_out;
    UInt8 covsctl_staccp_swc_out;
    SInt16 tqlimem_tqlimem_swc_out;
    SInt16 tqdem_tqcktakeoffmap_swc_out;
    SInt16 tqdem_tqidclimnreg_swc_out;
    UInt16 tqdem_rdrivtakeoff_swc_out;
    SInt16 covsctl_tqefcreq_swc_out;
    UInt8 tqdem_bmodspt_swc_out;
    UInt16 tqdem_raccpsptmod_swc_out;
    UInt16 tqdem_nengreq_swc_out;
    UInt8 tqdem_bacvnregtakeoff_swc_out;
    SInt16 dzone_tqefcdiflrnout_swc_out;
    SInt16 tqdem_tqckefcwoutantidb_swc_out;
    SInt16 tqdem_tqefcnregtakeoffeco_swc_out[TQDEM_2_SIZE];
    SInt16 tqdem_tqefcnregtakeoffnorm_swc_out[TQDEM_2_SIZE];

    TQDEM_Dzone_Torque_Calc_Init(&dzone_tqefcdiflrnout_swc_out);

    TQDEM_Ivc_Structure_Init(&tqdem_facgainfil_nck_swc_out,
                               &tqdem_bdrivtakeoff_swc_out,
                               &TqDem_idxMapTranDrvFirst,
                               &TqDem_idxMapTranDrvSec,
                               &TqDem_idxMapRvsDrv,
                               &tqdem_rdrivtakeoff_swc_out,
                               &TqDem_rTranEcoNorm,
                               &TqDem_rTranDrv);

    TQDEM_Take_Off_Assist_Init(&tqsys_nofstottakeoff_swc_out,
                                  &tqsys_ntarffl_swc_out,
                                  &tqsys_ntaridlcvcreq_swc_out);

    TQDEM_Ivc_Content_Init(&tqdem_btqgrdlim_swc_out,
                            &tqdem_tqckefc_swc_out,
                            &tqdem_tqckefcmax_swc_out,
                            &tqdem_tqckefcmin_swc_out,
                            &tqdem_tqcktakeoffmap_swc_out,
                            &tqdem_bmodspt_swc_out,
                            &tqdem_raccpsptmod_swc_out,
                            &TqDem_tqCkEfcDeltaTakeOff,
                            &TqDem_tqCkEfcDeltaEcoNorm,
                            &tqdem_tqckefcwoutantidb_swc_out );

    TQDEM_Coord_Xvv_Init( &covsctl_tqefcreq_swc_out,
                            &covsctl_raccpeng_swc_out,
                            &covsctl_raccptra_swc_out,
                            &covsctl_staccp_swc_out );

    TQDEM_Coord_Lim_Em_Init(&tqlimem_tqlimem_swc_out );

    TQDEM_Trq_Take_Off_Assist_Init( tqdem_tqefcnregtakeoffeco_swc_out,
                                    tqdem_tqefcnregtakeoffnorm_swc_out,
                                    &tqdem_tqidclimnreg_swc_out,
                                    &tqdem_bacvnregtakeoff_swc_out,
                                    &tqdem_nengreq_swc_out );

    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I152(0) */
    Rte_Write_P_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(covsctl_raccpeng_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I153(0) */
    Rte_Write_P_CoVSCtl_rAccPTra_CoVSCtl_rAccPTra(covsctl_raccptra_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I154(0) */
    Rte_Write_P_CoVSCtl_stAccP_CoVSCtl_stAccP(covsctl_staccp_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I159(1) */
    Rte_Write_P_CoVSCtl_tqEfcReq_CoVSCtl_tqEfcReq(covsctl_tqefcreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I188(0) */
    Rte_Write_P_DZone_tqEfcDifLrnOut_DZone_tqEfcDifLrnOut(dzone_tqefcdiflrnout_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I174(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bAcvNRegTakeOff_TqDem_bAcvNRegTakeOff(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_bacvnregtakeoff_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I147(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bDrivTakeOff_TqDem_bDrivTakeOff(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_bdrivtakeoff_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I167(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bModSpt_TqDem_bModSpt(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_bmodspt_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I148(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bTqGrdLim_TqDem_bTqGrdLim(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_btqgrdlim_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I146(0) */
    Rte_Write_P_TqDem_facGainFil_nCk_TqDem_facGainFil_nCk(tqdem_facgainfil_nck_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I173(0) */
    Rte_Write_P_TqDem_nEngReq_TqDem_nEngReq(tqdem_nengreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I168(0) */
    Rte_Write_P_TqDem_rAccPSptMod_TqDem_rAccPSptMod(tqdem_raccpsptmod_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I158(1) */
    Rte_Write_P_TqDem_rDrivTakeOff_TqDem_rDrivTakeOff(tqdem_rdrivtakeoff_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I149(0) */
    Rte_Write_P_TqDem_tqCkEfc_TqDem_tqCkEfc(tqdem_tqckefc_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I150(0) */
    Rte_Write_P_TqDem_tqCkEfcMax_TqDem_tqCkEfcMax(tqdem_tqckefcmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I151(0) */
    Rte_Write_P_TqDem_tqCkEfcMin_TqDem_tqCkEfcMin(tqdem_tqckefcmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I183(0) */
    Rte_Write_P_TqDem_tqCkEfcWoutAntiDB_TqDem_tqCkEfcWoutAntiDB(tqdem_tqckefcwoutantidb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I156(0) */
    Rte_Write_P_TqDem_tqCkTakeOffMap_TqDem_tqCkTakeOffMap(tqdem_tqcktakeoffmap_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I185(0) */
    Rte_Write_P_TqDem_tqEfcNRegTakeOffEco_TqDem_tqEfcNRegTakeOffEco(tqdem_tqefcnregtakeoffeco_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I186(0) */
    Rte_Write_P_TqDem_tqEfcNRegTakeOffNorm_TqDem_tqEfcNRegTakeOffNorm(tqdem_tqefcnregtakeoffnorm_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I157(0) */
    Rte_Write_P_TqDem_tqIdcLimNReg_TqDem_tqIdcLimNReg(tqdem_tqidclimnreg_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I155(0) */
    Rte_Write_P_TqLimEM_tqLimEM_TqLimEM_tqLimEM(tqlimem_tqlimem_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I143(0) */
    Rte_Write_P_TqSys_nOfsTotTakeOff_TqSys_nOfsTotTakeOff(tqsys_nofstottakeoff_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I144(0) */
    Rte_Write_P_TqSys_nTarFFL_TqSys_nTarFFL(tqsys_ntarffl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I145(0) */
    Rte_Write_P_TqSys_nTarIdlCVCReq_TqSys_nTarIdlCVCReq(tqsys_ntaridlcvcreq_swc_out);

    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I402(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_idxMapRvsDrv(TqDem_idxMapRvsDrv);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I403(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_idxMapTranDrvFirst(TqDem_idxMapTranDrvFirst);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I404(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_idxMapTranDrvSec(TqDem_idxMapTranDrvSec);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I405(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_rTranDrv(TqDem_rTranDrv);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I406(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_rTranEcoNorm(TqDem_rTranEcoNorm);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I407(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_tqCkEfcDeltaEcoNorm(TqDem_tqCkEfcDeltaEcoNorm);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I400(1) */
    Rte_IrvWrite_RE_TqDem_001_MSE_TqDem_tqCkEfcDeltaTakeOff(TqDem_tqCkEfcDeltaTakeOff);

}
/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_002_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_002_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 veh_spdveh_swc_in;
    UInt8 copt_noegdgearcord_swc_in;
    UInt8 coptst_steng_swc_in;
    Boolean tqsys_bacvantistall_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    UInt16 eng_nckfil_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqadp_bfrzadpacon_swc_in;
    Boolean tqadp_bfrzadpalton_swc_in;
    Boolean tqadp_bfrzadpcnvon_swc_in;
    Boolean tqsys_bengnonidl_swc_in;
    UInt16 covsctl_raccpeng_swc_in;
    Boolean tqadp_bfrzadpstgpmpon_swc_in;
    UInt16 tqsys_nofstottakeoff_swc_in;
    SInt16 tqsys_tqckidlcmn_swc_in;
    SInt16 tqdem_tqckefcwoutantidb_swc_in;
    /* FIM (FRM) */
    Boolean tqdem_bool_temp;
    Boolean frm_binhantidb_fim_in;
    /* OUTPUT */
    /* SWC OUT */
    SInt16 dzone_tqefcdiflrnout_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_002_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I114(0) */
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I113(0) */
        Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&copt_noegdgearcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I160(0) */
        Rte_Read_R_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(&covsctl_raccpeng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I124(0) */
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I126(0) */
        Rte_Read_R_TqAdp_bFrzAdpACOn_TqAdp_bFrzAdpACOn(&tqadp_bfrzadpacon_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I127(0) */
        Rte_Read_R_TqAdp_bFrzAdpAltOn_TqAdp_bFrzAdpAltOn(&tqadp_bfrzadpalton_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I128(0) */
        Rte_Read_R_TqAdp_bFrzAdpCnvOn_TqAdp_bFrzAdpCnvOn(&tqadp_bfrzadpcnvon_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I161(0) */
        Rte_Read_R_TqAdp_bFrzAdpStgPmpOn_TqAdp_bFrzAdpStgPmpOn(&tqadp_bfrzadpstgpmpon_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I125(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I182(0) */
        Rte_Read_R_TqDem_tqCkEfcWoutAntiDB_TqDem_tqCkEfcWoutAntiDB(&tqdem_tqckefcwoutantidb_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I121(0) */
        Rte_Read_R_TqSys_bAcvAntiStall_TqSys_bAcvAntiStall(&tqsys_bacvantistall_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I129(0) */
        Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&tqsys_bengnonidl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I162(0) */
        Rte_Read_R_TqSys_nOfsTotTakeOff_TqSys_nOfsTotTakeOff(&tqsys_nofstottakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I123(0) */
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I163(0) */
        Rte_Read_R_TqSys_tqCkIdlCmn_TqSys_tqCkIdlCmn(&tqsys_tqckidlcmn_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I109(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I700(0) */
        Rte_Call_R_FRM_bInhAntiDB_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhantidb_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);

        TQDEM_Dzone_Torque_Calc(tqdem_tqckefcwoutantidb_swc_in,
                               tqsys_nofstottakeoff_swc_in,
                               coptst_steng_swc_in,
                               copt_noegdgearcord_swc_in,
                               covsctl_raccpeng_swc_in,
                               eng_nckfil_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhantidb_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqadp_bfrzadpacon_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqadp_bfrzadpalton_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqadp_bfrzadpcnvon_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqadp_bfrzadpstgpmpon_swc_in),
                               tqcmp_tqsumlosscmp_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvantistall_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bengnonidl_swc_in),
                               tqsys_ntaridl_swc_in,
                               tqsys_tqckidlcmn_swc_in,
                               veh_spdveh_swc_in,
                               &dzone_tqefcdiflrnout_swc_out);

    }
    else
    {
        dzone_tqefcdiflrnout_swc_out = DZone_tqEfcDifLrnOut_B;

    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I188(0) */
    Rte_Write_P_DZone_tqEfcDifLrnOut_DZone_tqEfcDifLrnOut(dzone_tqefcdiflrnout_swc_out);

    /* IRV OUTPUT */

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_003_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_003_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 veh_spdveh_swc_in;
    UInt16 accp_raccp_swc_in;
    Boolean copt_btakeoff_swc_in;
    UInt8 copt_idxptspt_swc_in;
    UInt8 copt_noegdgearcord_swc_in;
    UInt8 coptst_steng_swc_in;
    Boolean ext_bkeyon_swc_in;
    Boolean ext_brvs_swc_in;
    UInt16 ext_neng_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 ext_toxcestim_swc_in;
    Boolean tqsys_bacvantistall_swc_in;
    Boolean tqsys_btypfu_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    UInt32 copt_spdvehgearratcord_swc_in;
    Boolean eom_btwcheatpha_swc_in;
    Boolean tqdem_bacvnregtakeoff_swc_in;
    /* FIM (FRM) */
    Boolean tqdem_bool_temp;
    Boolean frm_binheco_fim_in;
    Boolean frm_binhgreen_tcomes_fim_in;
    Boolean frm_binhgreen_toxcestim_fim_in;
    Boolean frm_binhrvtqdemrevstoff_fim_in;
    Boolean frm_binhrvtqdemtakeoff_fim_in;
    /* IRV IN */
    SInt16 tqdem_tqckefcdeltatakeoff_irv_in;
    SInt16 tqdem_tqckefcdeltaeconorm_irv_in;
    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqdem_facgainfil_nck_swc_out;
    UInt8 tqdem_bdrivtakeoff_swc_out;
    UInt16 tqdem_rdrivtakeoff_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_003_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I110(0) */
        Rte_Read_R_AccP_rAccP_AccP_rAccP(&accp_raccp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I114(0) */
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I111(0) */
        Rte_Read_R_CoPt_bTakeOff_CoPt_bTakeOff(&copt_btakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I112(0) */
        Rte_Read_R_CoPt_idxPtSpt_CoPt_idxPtSpt(&copt_idxptspt_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I113(0) */
        Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&copt_noegdgearcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I164(0) */
        Rte_Read_R_CoPt_spdVehGearRatCord_CoPt_spdVehGearRatCord(&copt_spdvehgearratcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I165(0) */
        Rte_Read_R_EOM_bTWCHeatPha_EOM_bTWCHeatPha(&eom_btwcheatpha_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I115(0) */
        Rte_Read_R_Ext_bKeyOn_Ext_bKeyOn(&ext_bkeyon_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I116(0) */
        Rte_Read_R_Ext_bRvs_Ext_bRvs(&ext_brvs_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I117(0) */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I118(0) */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I119(0) */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I120(0) */
        Rte_Read_R_Ext_tOxCEstim_Ext_tOxCEstim(&ext_toxcestim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I166(0) */
        Rte_Read_R_TqDem_bAcvNRegTakeOff_TqDem_bAcvNRegTakeOff(&tqdem_bacvnregtakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I121(0) */
        Rte_Read_R_TqSys_bAcvAntiStall_TqSys_bAcvAntiStall(&tqsys_bacvantistall_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I122(0) */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I123(0) */
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I109(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I701(0) */
        Rte_Call_R_FRM_bInhEco_GetFunctionPermission(&tqdem_bool_temp);
        frm_binheco_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I702(0) */
        Rte_Call_R_FRM_bInhGreen_tCoMes_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhgreen_tcomes_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I703(0) */
        Rte_Call_R_FRM_bInhGreen_tOxCEstim_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhgreen_toxcestim_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I704(0) */
        Rte_Call_R_FRM_bInhRvTqDemRevStOff_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhrvtqdemrevstoff_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I705(0) */
        Rte_Call_R_FRM_bInhRvTqDemTakeOff_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhrvtqdemtakeoff_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I407(1) */
        tqdem_tqckefcdeltaeconorm_irv_in = Rte_IrvRead_RE_TqDem_003_TEV_TqDem_tqCkEfcDeltaEcoNorm();
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I400(1) */
        tqdem_tqckefcdeltatakeoff_irv_in = Rte_IrvRead_RE_TqDem_003_TEV_TqDem_tqCkEfcDeltaTakeOff();

        TQDEM_Ivc_Structure(
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(tqdem_bacvnregtakeoff_swc_in),
                            tqdem_tqckefcdeltatakeoff_irv_in,
                            tqdem_tqckefcdeltaeconorm_irv_in,
                            accp_raccp_swc_in,
                            coptst_steng_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(copt_btakeoff_swc_in),
                            copt_idxptspt_swc_in,
                            copt_noegdgearcord_swc_in,
                            copt_spdvehgearratcord_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_bkeyon_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(ext_brvs_swc_in),
                            ext_neng_swc_in,
                            ext_stgbxcf_swc_in,
                            ext_tcomes_swc_in,
                            ext_toxcestim_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(frm_binheco_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhgreen_tcomes_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhgreen_toxcestim_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhrvtqdemrevstoff_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhrvtqdemtakeoff_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvantistall_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                            tqsys_ntaridl_swc_in,
                            veh_spdveh_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(eom_btwcheatpha_swc_in),
                            &tqdem_bdrivtakeoff_swc_out,
                            &tqdem_facgainfil_nck_swc_out,
                            &tqdem_rdrivtakeoff_swc_out,
                            &TqDem_idxMapRvsDrv,
                            &TqDem_idxMapTranDrvFirst,
                            &TqDem_idxMapTranDrvSec,
                            &TqDem_rTranDrv,
                            &TqDem_rTranEcoNorm);


    }
    else
    {
        tqdem_bdrivtakeoff_swc_out = TqDem_bDrivTakeOff_B;
        tqdem_facgainfil_nck_swc_out = TqDem_facGainFil_nCk_B;
        tqdem_rdrivtakeoff_swc_out = TqDem_rDrivTakeOff_B;

        TqDem_idxMapRvsDrv = TqDem_idxMapRvsDrv_B;
        TqDem_idxMapTranDrvFirst = TqDem_idxMapTranDrvFirst_B;
        TqDem_idxMapTranDrvSec = TqDem_idxMapTranDrvSec_B;
        TqDem_rTranDrv = TqDem_rTranDrv_B;
        TqDem_rTranEcoNorm = TqDem_rTranEcoNorm_B;
    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I147(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bDrivTakeOff_TqDem_bDrivTakeOff(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_bdrivtakeoff_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I146(0) */
    Rte_Write_P_TqDem_facGainFil_nCk_TqDem_facGainFil_nCk(tqdem_facgainfil_nck_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I158(1) */
    Rte_Write_P_TqDem_rDrivTakeOff_TqDem_rDrivTakeOff(tqdem_rdrivtakeoff_swc_out);

    /* IRV OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I402(1) */
    Rte_IrvWrite_RE_TqDem_003_TEV_TqDem_idxMapRvsDrv(TqDem_idxMapRvsDrv);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I403(1) */
    Rte_IrvWrite_RE_TqDem_003_TEV_TqDem_idxMapTranDrvFirst(TqDem_idxMapTranDrvFirst);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I404(1) */
    Rte_IrvWrite_RE_TqDem_003_TEV_TqDem_idxMapTranDrvSec(TqDem_idxMapTranDrvSec);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I405(1) */
    Rte_IrvWrite_RE_TqDem_003_TEV_TqDem_rTranDrv(TqDem_rTranDrv);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I406(1) */
    Rte_IrvWrite_RE_TqDem_003_TEV_TqDem_rTranEcoNorm(TqDem_rTranEcoNorm);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_004_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_004_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 veh_spdveh_swc_in;
    UInt16 accp_raccp_swc_in;
    UInt8 copt_noegdgearcord_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    UInt16 eng_nckfil_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    UInt32 copt_spdvehgearratcord_swc_in;
    Boolean tqdem_bacvnregtakeoff_swc_in;
    Boolean copt_bacvprotclup_swc_in;
    Boolean ext_bmodspt_swc_in;
    UInt16 tqdem_rdrivtakeoff_swc_in;
    Boolean tqsys_binhtqdemsptmod_swc_in;
    SInt16 dzone_tqefcdiflrnout_swc_in;

    SInt16 tqdem_tqefcnregtakeoffeco_swc_in[TQDEM_2_SIZE];
    SInt16 tqdem_tqefcnregtakeoffnorm_swc_in[TQDEM_2_SIZE];

    /* FIM (FRM) */
    Boolean tqdem_bool_temp;
    Boolean frm_binhtqdemsptmod_fim_in;
    /* IRV IN */
    UInt8 tqdem_idxmaprvsdrv_irv_in;
    UInt8 tqdem_idxmaptrandrvfirst_irv_in;
    UInt8 tqdem_idxmaptrandrvsec_irv_in;
    UInt16 tqdem_rtrandrv_irv_in;
    UInt16 tqdem_rtraneconorm_irv_in;
    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqdem_btqgrdlim_swc_out;
    SInt16 tqdem_tqckefc_swc_out;
    SInt16 tqdem_tqckefcmax_swc_out;
    SInt16 tqdem_tqckefcmin_swc_out;
    SInt16 tqdem_tqcktakeoffmap_swc_out;
    UInt8 tqdem_bmodspt_swc_out;
    UInt16 tqdem_raccpsptmod_swc_out;
    SInt16 tqdem_tqckefcwoutantidb_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_004_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I110(0) */
        Rte_Read_R_AccP_rAccP_AccP_rAccP(&accp_raccp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I169(1) */
        Rte_Read_R_CoPt_bAcvProtCluP_CoPt_bAcvProtCluP(&copt_bacvprotclup_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I113(0) */
        Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&copt_noegdgearcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I164(0) */
        Rte_Read_R_CoPt_spdVehGearRatCord_CoPt_spdVehGearRatCord(&copt_spdvehgearratcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I181(0) */
        Rte_Read_R_DZone_tqEfcDifLrnOut_DZone_tqEfcDifLrnOut(&dzone_tqefcdiflrnout_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I124(0) */
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I170(0) */
        Rte_Read_R_Ext_bModSpt_Ext_bModSpt(&ext_bmodspt_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I125(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I166(0) */
        Rte_Read_R_TqDem_bAcvNRegTakeOff_TqDem_bAcvNRegTakeOff(&tqdem_bacvnregtakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I171(1) */
        Rte_Read_R_TqDem_rDrivTakeOff_TqDem_rDrivTakeOff(&tqdem_rdrivtakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I184(0) */
        Rte_Read_R_TqDem_tqEfcNRegTakeOffEco_TqDem_tqEfcNRegTakeOffEco(tqdem_tqefcnregtakeoffeco_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I187(0) */
        Rte_Read_R_TqDem_tqEfcNRegTakeOffNorm_TqDem_tqEfcNRegTakeOffNorm(tqdem_tqefcnregtakeoffnorm_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I172(0) */
        Rte_Read_R_TqSys_bInhTqDemSptMod_TqSys_bInhTqDemSptMod(&tqsys_binhtqdemsptmod_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I123(0) */
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I109(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I706(0) */
        Rte_Call_R_FRM_bInhTqDemSptMod_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhtqdemsptmod_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I402(1) */
        tqdem_idxmaprvsdrv_irv_in = Rte_IrvRead_RE_TqDem_004_TEV_TqDem_idxMapRvsDrv();
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I403(1) */
        tqdem_idxmaptrandrvfirst_irv_in = Rte_IrvRead_RE_TqDem_004_TEV_TqDem_idxMapTranDrvFirst();
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I404(1) */
        tqdem_idxmaptrandrvsec_irv_in = Rte_IrvRead_RE_TqDem_004_TEV_TqDem_idxMapTranDrvSec();
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I405(1) */
        tqdem_rtrandrv_irv_in = Rte_IrvRead_RE_TqDem_004_TEV_TqDem_rTranDrv();
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I406(1) */
        tqdem_rtraneconorm_irv_in = Rte_IrvRead_RE_TqDem_004_TEV_TqDem_rTranEcoNorm();


        TQDEM_Ivc_Content( dzone_tqefcdiflrnout_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(tqdem_bacvnregtakeoff_swc_in),
                           tqdem_tqefcnregtakeoffeco_swc_in,
                           tqdem_tqefcnregtakeoffnorm_swc_in,
                           tqdem_rdrivtakeoff_swc_in,
                           tqdem_idxmaprvsdrv_irv_in,
                           tqdem_idxmaptrandrvfirst_irv_in,
                           tqdem_idxmaptrandrvsec_irv_in,
                           tqdem_rtrandrv_irv_in,
                           tqdem_rtraneconorm_irv_in,
                           accp_raccp_swc_in,
                           eng_nckfil_swc_in,
                           tqcmp_tqsumlosscmp_swc_in,
                           tqsys_ntaridl_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(copt_bacvprotclup_swc_in),
                           copt_noegdgearcord_swc_in,
                           copt_spdvehgearratcord_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(ext_bmodspt_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhtqdemsptmod_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_binhtqdemsptmod_swc_in),
                           veh_spdveh_swc_in,
                           &tqdem_btqgrdlim_swc_out,
                           &tqdem_tqckefc_swc_out,
                           &tqdem_tqckefcmax_swc_out,
                           &tqdem_tqckefcmin_swc_out,
                           &tqdem_tqcktakeoffmap_swc_out,
                           &tqdem_bmodspt_swc_out,
                           &tqdem_raccpsptmod_swc_out,
                           &TqDem_tqCkEfcDeltaTakeOff,
                           &TqDem_tqCkEfcDeltaEcoNorm,
                           &tqdem_tqckefcwoutantidb_swc_out);




    }
    else
    {
        tqdem_bmodspt_swc_out = TqDem_bModSpt_B;
        tqdem_btqgrdlim_swc_out = TqDem_bTqGrdLim_B;
        tqdem_raccpsptmod_swc_out = TqDem_rAccPSptMod_B;
        tqdem_tqckefc_swc_out = TqDem_tqCkEfc_B;
        tqdem_tqckefcmax_swc_out = TqDem_tqCkEfcMax_B;
        tqdem_tqckefcmin_swc_out = TqDem_tqCkEfcMin_B;
        tqdem_tqckefcwoutantidb_swc_out = TqDem_tqCkEfcWoutAntiDB_B;
        tqdem_tqcktakeoffmap_swc_out = TqDem_tqCkTakeOffMap_B;

        TqDem_tqCkEfcDeltaEcoNorm = TqDem_tqCkEfcDeltaEcoNorm_B;
        TqDem_tqCkEfcDeltaTakeOff = TqDem_tqCkEfcDeltaTakeOff_B;
    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I167(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bModSpt_TqDem_bModSpt(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_bmodspt_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I148(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bTqGrdLim_TqDem_bTqGrdLim(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_btqgrdlim_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I168(0) */
    Rte_Write_P_TqDem_rAccPSptMod_TqDem_rAccPSptMod(tqdem_raccpsptmod_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I149(0) */
    Rte_Write_P_TqDem_tqCkEfc_TqDem_tqCkEfc(tqdem_tqckefc_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I150(0) */
    Rte_Write_P_TqDem_tqCkEfcMax_TqDem_tqCkEfcMax(tqdem_tqckefcmax_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I151(0) */
    Rte_Write_P_TqDem_tqCkEfcMin_TqDem_tqCkEfcMin(tqdem_tqckefcmin_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I183(0) */
    Rte_Write_P_TqDem_tqCkEfcWoutAntiDB_TqDem_tqCkEfcWoutAntiDB(tqdem_tqckefcwoutantidb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I156(0) */
    Rte_Write_P_TqDem_tqCkTakeOffMap_TqDem_tqCkTakeOffMap(tqdem_tqcktakeoffmap_swc_out);

    /* IRV OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I407(1) */
    Rte_IrvWrite_RE_TqDem_004_TEV_TqDem_tqCkEfcDeltaEcoNorm(TqDem_tqCkEfcDeltaEcoNorm);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I400(1) */
    Rte_IrvWrite_RE_TqDem_004_TEV_TqDem_tqCkEfcDeltaTakeOff(TqDem_tqCkEfcDeltaTakeOff);


}

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_005_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_005_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 veh_spdveh_swc_in;
    UInt16 accp_raccp_swc_in;
    UInt8 copt_noegdgearcord_swc_in;
    UInt16 ext_neng_swc_in;
    SInt16 ext_tcomes_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    UInt16 eng_nckfil_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqsys_bengnonidl_swc_in;
    SInt16 tqsys_tqidcairlimcordwires_swc_in;
    SInt16 treattenms_nckgrd_swc_in;
    Boolean copt_brvscord_swc_in;
    Boolean eslim_bacvtrqlim_swc_in;
    UInt16 eslim_nlofucutoff_swc_in;
    SInt16 copt_tqmaxclu_swc_in;
    UInt16 copt_nprimshaft_swc_in;
    Boolean copt_bacvprotclup_swc_in;
    UInt16 tqdem_rdrivtakeoff_swc_in;
    SInt16 englim_tqefcnregtakeofflim_swc_in;
    UInt16 tqdem_raccpsptmod_swc_in;
    SInt16 tqdem_tqckefc_swc_in;
    /* FIM (FRM) */
    Boolean tqdem_bool_temp;
    Boolean frm_binhnregtakeoff_fim_in;
    Boolean frm_binhregnlimn_fim_in;
    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqdem_tqidclimnreg_swc_out;
    UInt16 tqdem_nengreq_swc_out;
    UInt8 tqdem_bacvnregtakeoff_swc_out;

    SInt16 tqdem_tqefcnregtakeoffeco_swc_out[TQDEM_2_SIZE];
    SInt16 tqdem_tqefcnregtakeoffnorm_swc_out[TQDEM_2_SIZE];

    UInt32 i;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_005_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I110(0) */
        Rte_Read_R_AccP_rAccP_AccP_rAccP(&accp_raccp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I169(1) */
        Rte_Read_R_CoPt_bAcvProtCluP_CoPt_bAcvProtCluP(&copt_bacvprotclup_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I138(0) */
        Rte_Read_R_CoPt_bRvsCord_CoPt_bRvsCord(&copt_brvscord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I142(0) */
        Rte_Read_R_CoPt_nPrimShaft_CoPt_nPrimShaft(&copt_nprimshaft_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I113(0) */
        Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&copt_noegdgearcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I141(0) */
        Rte_Read_R_CoPt_tqMaxClu_CoPt_tqMaxClu(&copt_tqmaxclu_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I139(1) */
        Rte_Read_R_ESLim_bAcvTrqLim_ESLim_bAcvTrqLim(&eslim_bacvtrqlim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I140(0) */
        Rte_Read_R_ESLim_nLoFuCutOff_ESLim_nLoFuCutOff(&eslim_nlofucutoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I175(0) */
        Rte_Read_R_EngLim_tqEfcNRegTakeOffLim_EngLim_tqEfcNRegTakeOffLim(&englim_tqefcnregtakeofflim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I124(0) */
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I117(0) */
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I119(0) */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I125(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I176(0) */
        Rte_Read_R_TqDem_rAccPSptMod_TqDem_rAccPSptMod(&tqdem_raccpsptmod_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I171(1) */
        Rte_Read_R_TqDem_rDrivTakeOff_TqDem_rDrivTakeOff(&tqdem_rdrivtakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I177(0) */
        Rte_Read_R_TqDem_tqCkEfc_TqDem_tqCkEfc(&tqdem_tqckefc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I129(0) */
        Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&tqsys_bengnonidl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I123(0) */
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I136(0) */
        Rte_Read_R_TqSys_tqIdcAirLimCordWiRes_TqSys_tqIdcAirLimCordWiRes(&tqsys_tqidcairlimcordwires_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I137(0) */
        Rte_Read_R_TreatTenms_nCkGrd_TreatTenms_nCkGrd(&treattenms_nckgrd_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I109(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I707(0) */
        Rte_Call_R_FRM_bInhNRegTakeOff_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhnregtakeoff_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I708(0) */
        Rte_Call_R_FRM_bInhRegNLimN_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhregnlimn_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);


        TQDEM_Trq_Take_Off_Assist( accp_raccp_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(copt_bacvprotclup_swc_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(copt_brvscord_swc_in),
                                   copt_nprimshaft_swc_in,
                                   copt_noegdgearcord_swc_in,
                                   copt_tqmaxclu_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(eslim_bacvtrqlim_swc_in),
                                   eslim_nlofucutoff_swc_in,
                                   englim_tqefcnregtakeofflim_swc_in,
                                   eng_nckfil_swc_in,
                                   ext_neng_swc_in,
                                   ext_tcomes_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhnregtakeoff_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhregnlimn_fim_in),
                                   tqcmp_tqsumlosscmp_swc_in,
                                   tqdem_raccpsptmod_swc_in,
                                   tqdem_rdrivtakeoff_swc_in,
                                   tqdem_tqckefc_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bengnonidl_swc_in),
                                   tqsys_ntaridl_swc_in,
                                   tqsys_tqidcairlimcordwires_swc_in,
                                   treattenms_nckgrd_swc_in,
                                   veh_spdveh_swc_in,
                                   tqdem_tqefcnregtakeoffeco_swc_out,
                                   tqdem_tqefcnregtakeoffnorm_swc_out,
                                   &tqdem_tqidclimnreg_swc_out,
                                   &tqdem_bacvnregtakeoff_swc_out,
                                   &tqdem_nengreq_swc_out);

    }
    else
    {
        tqdem_tqidclimnreg_swc_out = TqDem_tqIdcLimNReg_B;
        tqdem_nengreq_swc_out = TqDem_nEngReq_B;
        tqdem_bacvnregtakeoff_swc_out = TqDem_bAcvNRegTakeOff_B;
        for (i=0; i < TQDEM_2_SIZE; i++)
        {
            tqdem_tqefcnregtakeoffeco_swc_out[i] = TqDem_tqEfcNRegTakeOffEco_B[i];
            tqdem_tqefcnregtakeoffnorm_swc_out[i] = TqDem_tqEfcNRegTakeOffNorm_B[i];
        }
    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I174(0) */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
    Rte_Write_P_TqDem_bAcvNRegTakeOff_TqDem_bAcvNRegTakeOff(DDS_M_CONVERT_UINT8_TO_BOOL(tqdem_bacvnregtakeoff_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I173(0) */
    Rte_Write_P_TqDem_nEngReq_TqDem_nEngReq(tqdem_nengreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I185(0) */
    Rte_Write_P_TqDem_tqEfcNRegTakeOffEco_TqDem_tqEfcNRegTakeOffEco(tqdem_tqefcnregtakeoffeco_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I186(0) */
    Rte_Write_P_TqDem_tqEfcNRegTakeOffNorm_TqDem_tqEfcNRegTakeOffNorm(tqdem_tqefcnregtakeoffnorm_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I157(0) */
    Rte_Write_P_TqDem_tqIdcLimNReg_TqDem_tqIdcLimNReg(tqdem_tqidclimnreg_swc_out);

    /* IRV OUTPUT */
}

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_006_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_006_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt8 cha_sttqreq_swc_in;
    Boolean copt_bcludiegdcord_swc_in;
    UInt16 copt_ntaridlcvc_swc_in;
    UInt16 ext_pairextmes_swc_in;
    Boolean tqsys_bacvantistallman_swc_in;
    UInt16 tqsys_nofsffl_swc_in;
    UInt16 tqsys_nofslauchidltakeoff_swc_in;
    UInt16 tqsys_ntaridlfil_swc_in;
    UInt16 tqsys_ntaridlneut_swc_in;
    UInt16 veh_spdveh_swc_in;
    UInt16 covsctl_raccpeng_swc_in;
    /* FIM (FRM) */
    Boolean tqdem_bool_temp;
    Boolean frm_bdft_pairext_fim_in;
    Boolean frm_binhntaridltakeoff_fim_in;
    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqsys_nofstottakeoff_swc_out;
    UInt16 tqsys_ntarffl_swc_out;
    UInt16 tqsys_ntaridlcvcreq_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_006_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I100(0) */
        Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&cha_sttqreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I101(0) */
        Rte_Read_R_CoPt_bCluDiEgdCord_CoPt_bCluDiEgdCord(&copt_bcludiegdcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I102(0) */
        Rte_Read_R_CoPt_nTarIdlCVC_CoPt_nTarIdlCVC(&copt_ntaridlcvc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I160(0) */
        Rte_Read_R_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(&covsctl_raccpeng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I103(0) */
        Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&ext_pairextmes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I104(0) */
        Rte_Read_R_TqSys_bAcvAntiStallMan_TqSys_bAcvAntiStallMan(&tqsys_bacvantistallman_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I105(0) */
        Rte_Read_R_TqSys_nOfsFFL_TqSys_nOfsFFL(&tqsys_nofsffl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I106(0) */
        Rte_Read_R_TqSys_nOfsLauchIdlTakeOff_TqSys_nOfsLauchIdlTakeOff(&tqsys_nofslauchidltakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I107(0) */
        Rte_Read_R_TqSys_nTarIdlFil_TqSys_nTarIdlFil(&tqsys_ntaridlfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I108(0) */
        Rte_Read_R_TqSys_nTarIdlNeut_TqSys_nTarIdlNeut(&tqsys_ntaridlneut_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I109(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I709(0) */
        Rte_Call_R_FRM_bDft_pAirExt_GetFunctionPermission(&tqdem_bool_temp);
        frm_bdft_pairext_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I710(1) */
        Rte_Call_R_FRM_bInhNTarIdlTakeOff_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhntaridltakeoff_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);

        TQDEM_Take_Off_Assist( covsctl_raccpeng_swc_in,
                               cha_sttqreq_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(copt_bcludiegdcord_swc_in),
                               copt_ntaridlcvc_swc_in,
                               ext_pairextmes_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdft_pairext_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhntaridltakeoff_fim_in),
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8( tqsys_bacvantistallman_swc_in),
                               tqsys_nofsffl_swc_in,
                               tqsys_nofslauchidltakeoff_swc_in,
                               tqsys_ntaridlfil_swc_in,
                               tqsys_ntaridlneut_swc_in,
                               veh_spdveh_swc_in,
                               &tqsys_nofstottakeoff_swc_out,
                               &tqsys_ntarffl_swc_out,
                               &tqsys_ntaridlcvcreq_swc_out );

    }
    else
    {
        tqsys_nofstottakeoff_swc_out = TqSys_nOfsTotTakeOff_B;
        tqsys_ntarffl_swc_out = TqSys_nTarFFL_B;
        tqsys_ntaridlcvcreq_swc_out = TqSys_nTarIdlCVCReq_B;

    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I143(0) */
    Rte_Write_P_TqSys_nOfsTotTakeOff_TqSys_nOfsTotTakeOff(tqsys_nofstottakeoff_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I144(0) */
    Rte_Write_P_TqSys_nTarFFL_TqSys_nTarFFL(tqsys_ntarffl_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I145(0) */
    Rte_Write_P_TqSys_nTarIdlCVCReq_TqSys_nTarIdlCVCReq(tqsys_ntaridlcvcreq_swc_out);

    /* IRV OUTPUT */

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_007_TEV
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_007_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 accp_raccp_swc_in;
    SInt16 vsctl_tqckefcmaxreq_swc_in;
    SInt16 vsctl_tqckefcminreq_swc_in;
    UInt16 vsctl_raccpengmax_swc_in;
    UInt16 vsctl_raccpengmin_swc_in;
    UInt16 vsctl_raccptramax_swc_in;
    UInt16 vsctl_raccptramin_swc_in;
    UInt16 tqdem_raccpsptmod_swc_in;
    SInt16 tqdem_tqckefc_swc_in;
    /* OUTPUT */
    /* SWC OUT */
    UInt16 covsctl_raccpeng_swc_out;
    UInt16 covsctl_raccptra_swc_out;
    UInt8 covsctl_staccp_swc_out;
    SInt16 covsctl_tqefcreq_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_007_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I110(0) */
        Rte_Read_R_AccP_rAccP_AccP_rAccP(&accp_raccp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I176(0) */
        Rte_Read_R_TqDem_rAccPSptMod_TqDem_rAccPSptMod(&tqdem_raccpsptmod_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I177(0) */
        Rte_Read_R_TqDem_tqCkEfc_TqDem_tqCkEfc(&tqdem_tqckefc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I132(1) */
        Rte_Read_R_VSCtl_rAccPEngMax_VSCtl_rAccPEngMax(&vsctl_raccpengmax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I133(1) */
        Rte_Read_R_VSCtl_rAccPEngMin_VSCtl_rAccPEngMin(&vsctl_raccpengmin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I134(1) */
        Rte_Read_R_VSCtl_rAccPTraMax_VSCtl_rAccPTraMax(&vsctl_raccptramax_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I135(1) */
        Rte_Read_R_VSCtl_rAccPTraMin_VSCtl_rAccPTraMin(&vsctl_raccptramin_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I130(1) */
        Rte_Read_R_VSCtl_tqCkEfcMaxReq_VSCtl_tqCkEfcMaxReq(&vsctl_tqckefcmaxreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I131(0) */
        Rte_Read_R_VSCtl_tqCkEfcMinReq_VSCtl_tqCkEfcMinReq(&vsctl_tqckefcminreq_swc_in);


        TQDEM_Coord_Xvv(   tqdem_tqckefc_swc_in,
                           tqdem_raccpsptmod_swc_in,
                           accp_raccp_swc_in,
                           vsctl_tqckefcminreq_swc_in,
                           vsctl_tqckefcmaxreq_swc_in,
                           vsctl_raccpengmax_swc_in,
                           vsctl_raccpengmin_swc_in,
                           vsctl_raccptramax_swc_in,
                           vsctl_raccptramin_swc_in,
                           &covsctl_tqefcreq_swc_out,
                           &covsctl_raccpeng_swc_out,
                           &covsctl_raccptra_swc_out,
                           &covsctl_staccp_swc_out );

    }
    else
    {
        covsctl_raccpeng_swc_out = CoVSCtl_rAccPEng_B;
        covsctl_raccptra_swc_out = CoVSCtl_rAccPTra_B;
        covsctl_staccp_swc_out = CoVSCtl_stAccP_B;
        covsctl_tqefcreq_swc_out = CoVSCtl_tqEfcReq_B;

    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I152(0) */
    Rte_Write_P_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(covsctl_raccpeng_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I153(0) */
    Rte_Write_P_CoVSCtl_rAccPTra_CoVSCtl_rAccPTra(covsctl_raccptra_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I154(0) */
    Rte_Write_P_CoVSCtl_stAccP_CoVSCtl_stAccP(covsctl_staccp_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I159(1) */
    Rte_Write_P_CoVSCtl_tqEfcReq_CoVSCtl_tqEfcReq(covsctl_tqefcreq_swc_out);

    /* IRV OUTPUT */

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqDem_008_TEV
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqDem_008_TEV(void)
{
    /* INPUT */
    /* SWC IN */
    UInt8 copt_noegdgearcord_swc_in;
    UInt8 coptst_steng_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    UInt8 cha_stepb_swc_in;
    UInt8 cha_sthillasi_swc_in;
    SInt16 covsctl_tqefcreq_swc_in;
    /* FIM (FRM) */
    Boolean tqdem_bool_temp;
    Boolean frm_binhtqlimem_fim_in;
    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqlimem_tqlimem_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)RE_TQDEM_008_TEV_B)
    {
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I178(0) */
        Rte_Read_R_Cha_stEPB_Cha_stEPB(&cha_stepb_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I179(1) */
        Rte_Read_R_Cha_stHillAsi_Cha_stHillAsi(&cha_sthillasi_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I114(0) */
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I113(0) */
        Rte_Read_R_CoPt_noEgdGearCord_CoPt_noEgdGearCord(&copt_noegdgearcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I180(1) */
        Rte_Read_R_CoVSCtl_tqEfcReq_CoVSCtl_tqEfcReq(&covsctl_tqefcreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I118(0) */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I711(0) */
        Rte_Call_R_FRM_bInhTqLimEM_GetFunctionPermission(&tqdem_bool_temp);
        frm_binhtqlimem_fim_in = ((UInt32)tqdem_bool_temp == (UInt32)DDS_FALSE);



        TQDEM_Coord_Lim_Em(covsctl_tqefcreq_swc_in,
                           cha_stepb_swc_in,
                           cha_sthillasi_swc_in,
                           coptst_steng_swc_in,
                           copt_noegdgearcord_swc_in,
                           ext_stgbxcf_swc_in,
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhtqlimem_fim_in),
                           &tqlimem_tqlimem_swc_out );

    }
    else
    {
        tqlimem_tqlimem_swc_out = TqLimEM_tqLimEM_B;

    }


    /* SWC OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01245-TqDem.I155(0) */
    Rte_Write_P_TqLimEM_tqLimEM_TqLimEM_tqLimEM(tqlimem_tqlimem_swc_out);

    /* IRV OUTPUT */
}
/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : TqDem_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) TqDem_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_TqDem_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

