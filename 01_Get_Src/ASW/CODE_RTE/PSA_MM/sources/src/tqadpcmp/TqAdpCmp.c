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
* Ref X:\integration_view_00PSASWC_E522D11\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TqAdpCmp.c
* Version int :/main/00PSASWC_E5/13 Date: 28/11/2013 15 h 40 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :Update with QAC . For TqAdpCmp 12.2 / Update with A0104548 1.0 (CSMT_CGMT06_2023_V3_4.zip)
* Version dev :\main\branch_thauvin_euro6\2 Date: 28/11/2013 15 h 4 m User:thauvin 
*    TWK_model:NO_MODEL
*    comments :Update with QAC 
*    comments :For TqAdpCmp 12.2 / Update with A0104548 1.0 (CSMT_CGMT06_2023_V3_4.zip)
* Version dev :\main\branch_thauvin_euro6\1 Date: 22/11/2013 14 h 37 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp 12.2 / Update with A0104548 1.0 (CSMT_CGMT06_2023_V3_4.zip)
* Version int :/main/00PSASWC_E5/12 Date: 2/5/2013 12 h 22 m User:posmyk
*    TWK_model:NO_MODEL
*    comments :update TQADPCMP_Estim_Air_Cond_T4 for TqAdpCmp 12.1
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 25/4/2013 13 h 20 m User:lemort
*    TWK_model:NO_MODEL
*    comments :update TQADPCMP_Estim_Air_Cond_T4
* Version int :/main/00PSASWC_E5/11 Date: 9/8/2012 12 h 29 m User:meme
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_12_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 9/8/2012 10 h 10 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_12_0_e6
* Version int :/main/00PSASWC_E5/10 Date: 23/4/2012 11 h 58 m User:meme
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_11_1_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 19/4/2012 15 h 56 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_11_1_e6
* Version int :/main/00PSASWC_E5/9 Date: 21/3/2012 15 h 7 m User:esnault
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 20/3/2012 10 h 52 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/00PSASWC_E5/8 Date: 14/9/2011 16 h 28 m User:meme
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_10.6_e6, Add a diversity constant "OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC",
*    comments :and correction FDS "A0202589".
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 26/8/2011 14 h 28 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp_10.6_e6, Add a diversity constant "OPTIM_TQADPCMP_CSMT_CGMT06_1806_INTERNAL_TORQUE_SC",
*    comments :and correction FDS "A0202589".
* Version int :/main/00PSASWC_E5/6 Date: 3/1/2011 14 h 12 m User:meme
*    TWK_model:NO_MODEL
*    comments :Update for TqAdpCmp 10.4
* Version dev :\main\branch_moisan_module_dev\1 Date: 3/1/2011 12 h 59 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for TqAdpCmp 10.4
* Version int :/main/00PSASWC_E5/5 Date: 21/12/2010 17 h 54 m User:esnault
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp 10.3 . Correct FDS_32968. Correct FDS_32209
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 25/11/2010 15 h 47 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :TqAdpCmp 10.3 : correct FDS_32968 and FDS_32209
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 22/11/2010 16 h 1 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correct FDS32371 (TqAdpCmp 10.3)
* Version int :/main/00PSASWC_E5/4 Date: 18/11/2010 14 h 28 m User:meme
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 10.2
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 18/11/2010 14 h 18 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 10.2
* Version int :/main/00PSASWC_E5/3 Date: 18/11/2010 12 h 49 m User:meme
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 17/11/2010 16 h 49 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 16/11/2010 17 h 10 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp 10.2 (update Minor version)
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 16/11/2010 16 h 51 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :For TqAdpCmp 10.2
* Version int :/main/00PSASWC_E5/2 Date: 12/10/2010 9 h 44 m User:meme
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version int :/main/00PSASWC_E5/1 Date: 13/9/2010 14 h 16 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 11/10/2010 11 h 9 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 10/9/2010 15 h 52 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 10/9/2010 10 h 40 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 3/9/2010 12 h 29 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 22/7/2010 12 h 18 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 9/7/2010 16 h 22 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 8/7/2010 18 h 4 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 7/7/2010 9 h 22 m User:morisseau
*    TWK_model:NO_MODEL
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

#include "TqAdpCmp.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if TQADPCMP_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
dds_lib.* version is not compatible with current SWC version
#endif

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/


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

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> This constant is used in other files</3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTEng_A
[TQADPCMP_8_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0),
(UInt16)(4 * BIN0), (UInt16)(5 * BIN0), (UInt16)(6 * BIN0),
(UInt16)(7 * BIN0), (UInt16)(8 * BIN0)
};

/* <PRQA_COMMENT><3211> This constant is used in other files</3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTqAccu_A[TQADPCMP_10_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0),
(UInt16)(4 * BIN0), (UInt16)(5 * BIN0), (UInt16)(6 * BIN0),
(UInt16)(7 * BIN0), (UInt16)(8 * BIN0), (UInt16)(9 * BIN0),
(UInt16)(10 * BIN0)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"

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
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pwrACLoss_B = (UInt16)(0 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqACLoss_B = (UInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqAltLoss_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqCnvLoss_B = (UInt16)(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpLoss_B = (UInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossCmpWoutCnv_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossCmp_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tqSumLossEstim_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEngLossAdp_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqCkEngLoss_B = (UInt16)(0 * BIN4);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bFrzAdpACOn_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bFrzAdpAltOn_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bFrzAdpCnvOn_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bFrzAdpStgPmpOn_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bInhEngStop_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_stCdnNxtCkg_B = (UInt8)TQADPCMP_NOMINAL;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bACOffDftSelOn_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bEngStrtReq_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bTAirChk_B = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqCmp_tAirEstim_B = (SInt8)(20 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TQADPCMP_ACTIVE_BYP_C = DDS_FALSE;
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
/* declaration for DEM */
STATIC VAR(UInt8, AUTOMATIC) tqadp_bmonrunorngneut;
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdgoornghineut;
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdgoorngloneut;
STATIC VAR(UInt8, AUTOMATIC) tqadp_bmonrunorngdragred;
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdgoornghidragred;
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdgoornglodragred;

STATIC VAR(UInt8, AUTOMATIC) tqcmp_bdgo_tqaltrv;
STATIC VAR(UInt8, AUTOMATIC) tqcmp_bmonrun_tqaltrv;

/* prev for DEM used in TQADPCMP_SET_DEM_EVENT_STATUS */
STATIC VAR(UInt8, AUTOMATIC) tqadp_bmonrunorngneut_prev;
STATIC VAR(UInt8, AUTOMATIC) tqadp_bmonrunorngdragred_prev;
STATIC VAR(UInt8, AUTOMATIC) tqcmp_bmonrun_tqaltrv_prev;

#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAuxSumLossCmp_irv_MP;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pwrACItECULoss_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqAuxSumLossEstim_irv_MP;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pwrACExtECULoss_irv_MP;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bACExtECUOfDftSelOn_irv_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bFrzAdpACExtECUOn_irv_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bFrzAdpACItECUOn_irv_MP;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define TQADPCMP_START_SEC_CONST_VERSION_MODULE_8BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) TqAdpCmp_ModuleVersion_Major_MP = (UInt8)12;
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) TqAdpCmp_ModuleVersion_Minor_MP = (UInt8)2;
#define TQADPCMP_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_TqAdpCmp_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqAdpCmp_001_MSE(void)
{
    SInt16 tqcmp_tqaltloss_swc_out;
    SInt16 tqcmp_tqsumlosscmp_swc_out;
    SInt16 tqcmp_tqsumlosscmpwoutcnv_swc_out;
    SInt16 tqcmp_tqsumlossestim_swc_out;
    UInt16 tqcmp_pwracloss_swc_out;
    SInt8 tqcmp_tairestim_swc_out;
    UInt16 tqcmp_tqacloss_swc_out;
    UInt16 tqcmp_tqcnvloss_swc_out;
    UInt16 tqcmp_tqstgpmploss_swc_out;
    SInt16 tqsys_tqckenglossadp_swc_out;
    UInt16 tqsys_tqckengloss_swc_out;
    UInt8 tqadp_bfrzadpacon_swc_out;
    UInt8 tqadp_bfrzadpcnvon_swc_out;
    UInt8 tqadp_bfrzadpalton_swc_out;
    UInt8 tqadp_binhengstop_swc_out;
    UInt8 tqadp_stcdnnxtckg_swc_out;
    UInt8 tqadp_bfrzadpstgpmpon_swc_out;
    UInt8 tqcmp_bacoffdftselon_swc_out;
    UInt8 tqcmp_bengstrtreq_swc_out;
    UInt8 tqcmp_btairchk_swc_out;

    tqadp_bmonrunorngneut = DDS_FALSE;
    tqadp_bdgoornghineut = DDS_FALSE;
    tqadp_bdgoorngloneut = DDS_FALSE;
    tqadp_bmonrunorngdragred = DDS_FALSE;
    tqadp_bdgoornghidragred = DDS_FALSE;
    tqadp_bdgoornglodragred = DDS_FALSE;
    tqadp_bmonrunorngneut_prev = DDS_FALSE;
    tqadp_bmonrunorngdragred_prev = DDS_FALSE;

    tqcmp_bdgo_tqaltrv = DDS_FALSE;
    tqcmp_bmonrun_tqaltrv = DDS_TRUE;
    tqcmp_bmonrun_tqaltrv_prev = DDS_TRUE;


/* INSERT INIT FUNCTIONS HERE */
    TQADPCMP_Allow_Inhibit_Stt_Init(&tqadp_binhengstop_swc_out,
                                    &tqadp_stcdnnxtckg_swc_out);

    TQADPCMP_Calc_Running_Tq_Init(&tqadp_bdgoornghidragred,
                                  &tqadp_bdgoornghineut,
                                  &tqadp_bdgoornglodragred,
                                  &tqadp_bdgoorngloneut,
                                  &tqadp_bmonrunorngdragred,
                                  &tqadp_bmonrunorngneut );

    TQADPCMP_Calc_Tq_Applicable_Init(&tqsys_tqckenglossadp_swc_out /* BIN4 */);

    TQADPCMP_Coord_Accessory_Ls_Init(&TqCmp_tqAuxSumLossCmp_irv_MP, /* BIN4 */
                                     &TqCmp_tqAuxSumLossEstim_irv_MP /* BIN4 */);

    TQADPCMP_Coord_Global_Loss_Init(&tqcmp_tqsumlosscmp_swc_out, /* BIN4 */
                                    &tqcmp_tqsumlosscmpwoutcnv_swc_out, /* BIN4 */
                                    &tqcmp_tqsumlossestim_swc_out /* BIN4 */);

    TQADPCMP_Coord_Lost_Motor_Init(&tqsys_tqckengloss_swc_out /* BIN4 */);

    TQADPCMP_Estim_Air_Cond_Init(&tqadp_bfrzadpacon_swc_out,
                                 &tqcmp_bacoffdftselon_swc_out,
                                 &tqcmp_pwracloss_swc_out, /* BIN0 */
                                 &tqcmp_tqacloss_swc_out /* BIN4 */);

    TQADPCMP_Estim_Air_Cond_T3_Init(&TqAdp_bFrzAdpACItECUOn_irv_MP,
                                    &TqCmp_pwrACItECULoss_irv_MP /* BIN0 */);

    TQADPCMP_Estim_Air_Cond_T4_Init(&TqAdp_bFrzAdpACExtECUOn_irv_MP,
                                    &TqCmp_bACExtECUOfDftSelOn_irv_MP,
                                    &TqCmp_pwrACExtECULoss_irv_MP /* BIN0 */);

    TQADPCMP_Estim_Alternator_Init(&tqcmp_bdgo_tqaltrv,
                                   &tqadp_bfrzadpalton_swc_out,
                                   &tqcmp_tqaltloss_swc_out /* BIN4 */);

    TQADPCMP_Estim_Bva_Init(&tqadp_bfrzadpcnvon_swc_out,
                            &tqcmp_tqcnvloss_swc_out /* BIN4 */);

    TQADPCMP_Estim_Steering_Init(&tqcmp_tqstgpmploss_swc_out,
                                 &tqadp_bfrzadpstgpmpon_swc_out);

    TQADPCMP_Loss_Nvm_Init();

    TQADPCMP_Model_Tair_Init(&tqcmp_bengstrtreq_swc_out,
                             &tqcmp_btairchk_swc_out,
                             &tqcmp_tairestim_swc_out /* BIN0 */);

    TQADPCMP_Temp_Engine_Init();

    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I400(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqAdp_bFrzAdpACExtECUOn_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqAdp_bFrzAdpACExtECUOn_irv_MP));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I401(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqAdp_bFrzAdpACItECUOn_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqAdp_bFrzAdpACItECUOn_irv_MP));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I402(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqCmp_bACExtECUOffDftSelOn_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqCmp_bACExtECUOfDftSelOn_irv_MP));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I403(0) */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqCmp_pwrACExtECULoss_irv(TqCmp_pwrACExtECULoss_irv_MP);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I404(0) */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqCmp_pwrACItECULoss_irv(TqCmp_pwrACItECULoss_irv_MP);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I405(0) */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqCmp_tqAuxSumLossCmp_irv(TqCmp_tqAuxSumLossCmp_irv_MP);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I406(0) */
    Rte_IrvWrite_RE_TqAdpCmp_001_MSE_TqCmp_tqAuxSumLossEstim_irv(TqCmp_tqAuxSumLossEstim_irv_MP);


    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I159(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bInhEngStop_TqAdp_bInhEngStop(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_binhengstop_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I160(0) */
    Rte_Write_P_TqAdp_stCdnNxtCkg_TqAdp_stCdnNxtCkg(tqadp_stcdnnxtckg_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I188(0) */
    Rte_Write_P_TqSys_tqCkEngLossAdp_TqSys_tqCkEngLossAdp(tqsys_tqckenglossadp_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I151(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCmp_bEngStrtReq_TqCmp_bEngStrtReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqcmp_bengstrtreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I152(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCmp_bTAirChk_TqCmp_bTAirChk(DDS_M_CONVERT_UINT8_TO_BOOL(tqcmp_btairchk_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I153(0) */
    Rte_Write_P_TqCmp_tAirEstim_TqCmp_tAirEstim(tqcmp_tairestim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I175(0) */
    Rte_Write_P_TqSys_tqCkEngLoss_TqSys_tqCkEngLoss(tqsys_tqckengloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I129(0) */
    Rte_Write_P_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(tqcmp_tqsumlosscmp_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I130(0) */
    Rte_Write_P_TqCmp_tqSumLossCmpWoutCnv_TqCmp_tqSumLossCmpWoutCnv(tqcmp_tqsumlosscmpwoutcnv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I184(0) */
    Rte_Write_P_TqCmp_tqSumLossEstim_TqCmp_tqSumLossEstim(tqcmp_tqsumlossestim_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I123(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpACOn_TqAdp_bFrzAdpACOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpacon_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I124(0) */
    Rte_Write_P_TqCmp_pwrACLoss_TqCmp_pwrACLoss(tqcmp_pwracloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I125(0) */
    Rte_Write_P_TqCmp_tqACLoss_TqCmp_tqACLoss(tqcmp_tqacloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I132(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqcmp_bacoffdftselon_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I121(0) */
    Rte_Write_P_TqCmp_tqAltLoss_TqCmp_tqAltLoss(tqcmp_tqaltloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I122(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpAltOn_TqAdp_bFrzAdpAltOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpalton_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I127(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpCnvOn_TqAdp_bFrzAdpCnvOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpcnvon_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I128(0) */
    Rte_Write_P_TqCmp_tqCnvLoss_TqCmp_tqCnvLoss(tqcmp_tqcnvloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I126(0) */
    Rte_Write_P_TqCmp_tqStgPmpLoss_TqCmp_tqStgPmpLoss(tqcmp_tqstgpmploss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I136(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpStgPmpOn_TqAdp_bFrzAdpStgPmpOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpstgpmpon_swc_out));

}
/*******************************************************************************
*
*  Runnable Name    : RE_TqAdp_Sdl10ms_TqAdpLossClc
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqAdp_Sdl10ms_TqAdpLossClc(void)
{
    /* INPUT */
    /* SWC IN */
    UInt8 ext_stgbxcf_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 ext_toilmes_swc_in;
    UInt8 ac_bacclu_swc_in;
    UInt8 copt_btqtx_swc_in;
    UInt8 cooptmel_stelprod_swc_in;
    UInt8 copt_stdragred_swc_in;
    UInt8 copt_stcpl_swc_in;
    UInt16 eom_tiengrunstrt_swc_in;
    UInt16 eng_nckfil_swc_in;
    UInt8 tqadp_bfrzadpacon_swc_in;
    UInt8 tqadp_bfrzadpalton_swc_in;
    UInt8 tqadp_bfrzadpcnvon_swc_in;
    UInt8 tqadp_bfrzadpstgpmpon_swc_in;
    UInt16 tqcmp_tqacloss_swc_in;
    SInt16 tqcmp_tqsumlossestim_swc_in;
    UInt8 tqsys_bengnonidl_swc_in;
    UInt8 tqsys_idxtqaccu_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    SInt16 tqsys_tqckidlcmn_swc_in;
    UInt16 veh_spdveh_swc_in;
    UInt8 coptst_steng_swc_in;
    UInt32 ext_dstvehmes_swc_in;

    /* FIM (FRM) */
    Boolean frm_binhadp_fim_in;

    Boolean tqadpcmp_bool_temp;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqadp_binhengstop_swc_out;
    UInt8 tqadp_stcdnnxtckg_swc_out;
    SInt16 tqsys_tqckenglossadp_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_AC_bACClu_AC_bACClu(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        ac_bacclu_swc_in = (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_CoOptmEl_stElProd_CoOptmEl_stElProd(&cooptmel_stelprod_swc_in);
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        Rte_Read_R_CoPt_stDragRed_CoPt_stDragRed(&copt_stdragred_swc_in);
        Rte_Read_R_CoPt_stCpl_CoPt_stCpl(&copt_stcpl_swc_in);
        Rte_Read_R_EOM_tiEngRunStrt_EOM_tiEngRunStrt(&eom_tiengrunstrt_swc_in);
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_Ext_dstVehMes_Ext_dstVehMes(&ext_dstvehmes_swc_in);
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&ext_toilmes_swc_in);
        Rte_Read_R_TqAdp_bFrzAdpACOn_TqAdp_bFrzAdpACOn(&tqadpcmp_bool_temp);
        Rte_Read_R_CoPt_bTqTx_CoPt_bTqTx(&tqadpcmp_bool_temp);
		/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
		 copt_btqtx_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpacon_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqAdp_bFrzAdpAltOn_TqAdp_bFrzAdpAltOn(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpalton_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqAdp_bFrzAdpCnvOn_TqAdp_bFrzAdpCnvOn(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpcnvon_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqAdp_bFrzAdpStgPmpOn_TqAdp_bFrzAdpStgPmpOn(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpstgpmpon_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqCmp_tqACLoss_TqCmp_tqACLoss(&tqcmp_tqacloss_swc_in);
        Rte_Read_R_TqCmp_tqSumLossEstim_TqCmp_tqSumLossEstim(&tqcmp_tqsumlossestim_swc_in);
        Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqsys_bengnonidl_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqSys_idxTqAccu_TqSys_idxTqAccu(&tqsys_idxtqaccu_swc_in);
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        Rte_Read_R_TqSys_tqCkIdlCmn_TqSys_tqCkIdlCmn(&tqsys_tqckidlcmn_swc_in);
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I709(0) */
        Rte_Call_R_FRM_bInhAdp_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhadp_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhadp_fim_in = (Boolean)DDS_FALSE;
		}


        TQADPCMP_Loss_Nvm();


        TQADPCMP_Temp_Engine(copt_stdragred_swc_in,
                             ext_stgbxcf_swc_in,
                             ext_tcomes_swc_in, /* BIN0 */
                             ext_toilmes_swc_in /* DEC1 */);

        TQADPCMP_Calc_Running_Tq(ac_bacclu_swc_in,
                                 cooptmel_stelprod_swc_in,
                                 copt_btqtx_swc_in,
                                 copt_stcpl_swc_in,
                                 eom_tiengrunstrt_swc_in, /* DEC2 */
                                 eng_nckfil_swc_in, /* BIN2 */
                                 ext_stgbxcf_swc_in,
                                 ext_tcomes_swc_in, /* BIN0 */
                                 /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                 (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhadp_fim_in),
                                 tqadp_bfrzadpacon_swc_in,
                                 tqadp_bfrzadpalton_swc_in,
                                 tqadp_bfrzadpcnvon_swc_in,
                                 tqadp_bfrzadpstgpmpon_swc_in,
                                 tqcmp_tqacloss_swc_in, /* BIN4 */
                                 tqcmp_tqsumlossestim_swc_in, /* BIN4 */
                                 tqsys_bengnonidl_swc_in,
                                 tqsys_idxtqaccu_swc_in, /* BIN0 */
                                 tqsys_ntaridl_swc_in, /* BIN2 */
                                 tqsys_tqckidlcmn_swc_in, /* BIN4 */
                                 veh_spdveh_swc_in, /* BIN7 */
                                 copt_stdragred_swc_in, /*BIN0*/
                                 &tqadp_bdgoornghidragred,
                                 &tqadp_bdgoornghineut,
                                 &tqadp_bdgoornglodragred,
                                 &tqadp_bdgoorngloneut,
                                 &tqadp_bmonrunorngdragred,
                                 &tqadp_bmonrunorngneut);

        TQADPCMP_Calc_Tq_Applicable(eng_nckfil_swc_in, /* BIN2 */
                                    tqsys_idxtqaccu_swc_in, /* BIN0 */
                                    veh_spdveh_swc_in, /* BIN7 */
                                    &tqsys_tqckenglossadp_swc_out /* BIN4 */);

        TQADPCMP_Allow_Inhibit_Stt(coptst_steng_swc_in,
                                   ext_dstvehmes_swc_in, /* BIN0 */
                                   ext_tcomes_swc_in, /* BIN0 */
                                   /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhadp_fim_in),
                                   tqadp_bmonrunorngdragred,
                                   tqadp_bmonrunorngneut,
                                   &tqadp_binhengstop_swc_out,
                                   &tqadp_stcdnnxtckg_swc_out);

        /* DEM :  TqAdp_ORngHiDragRed & TqAdp_ORngLoDragRed */
        if((UInt32)tqadp_bmonrunorngdragred==(UInt32)DDS_TRUE)
        {
            /* Diagnostic activation */
            if((UInt32)tqadp_bdgoornghidragred==(UInt32)DDS_TRUE)
            {
                (void)Rte_Call_R_TqAdp_ORngHiDragRed_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
            }
            else
            {
                (void)Rte_Call_R_TqAdp_ORngHiDragRed_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
            }
            /* Diagnostic activation */
            if((UInt32)tqadp_bdgoornglodragred==(UInt32)DDS_TRUE)
            {
                (void)Rte_Call_R_TqAdp_ORngLoDragRed_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
            }
            else
            {
                (void)Rte_Call_R_TqAdp_ORngLoDragRed_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
            }
        }
        else
        {
            if ((UInt32)tqadp_bmonrunorngdragred_prev==(UInt32)DDS_TRUE)
            {
                (void)Rte_Call_R_TqAdp_ORngHiDragRed_SetEventStatus(DEM_EVENT_STATUS_INIT);
                (void)Rte_Call_R_TqAdp_ORngLoDragRed_SetEventStatus(DEM_EVENT_STATUS_INIT);
            }
            else
            {
                /* case E_OK */
            }
        }
        tqadp_bmonrunorngdragred_prev = tqadp_bmonrunorngdragred;



        /* DEM : TqAdp_ORngHiNeut & TqAdp_ORngLoNeut */
        if((UInt32)tqadp_bmonrunorngneut==(UInt32)DDS_TRUE)
        {
            /* Diagnostic activation */
            if((UInt32)tqadp_bdgoornghineut==(UInt32)DDS_TRUE)
            {
                (void)Rte_Call_R_TqAdp_ORngHiNeut_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
            }
            else
            {
                (void)Rte_Call_R_TqAdp_ORngHiNeut_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
            }
            /* Diagnostic activation */
            if((UInt32)tqadp_bdgoorngloneut==(UInt32)DDS_TRUE)
            {
                (void)Rte_Call_R_TqAdp_ORngLoNeut_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
            }
            else
            {
                (void)Rte_Call_R_TqAdp_ORngLoNeut_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
            }
        }
        else
        {
            if ((UInt32)tqadp_bmonrunorngneut_prev==(UInt32)DDS_TRUE)
            {
                (void)Rte_Call_R_TqAdp_ORngHiNeut_SetEventStatus(DEM_EVENT_STATUS_INIT);
                (void)Rte_Call_R_TqAdp_ORngLoNeut_SetEventStatus(DEM_EVENT_STATUS_INIT);
            }
            else
            {
                /* case E_OK */
            }
        }
        tqadp_bmonrunorngneut_prev = tqadp_bmonrunorngneut;
    }
    else
    {
        tqadp_binhengstop_swc_out = TqAdp_bInhEngStop_B;
        tqadp_stcdnnxtckg_swc_out = TqAdp_stCdnNxtCkg_B;
        tqsys_tqckenglossadp_swc_out = TqSys_tqCkEngLossAdp_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I159(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bInhEngStop_TqAdp_bInhEngStop(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_binhengstop_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I160(0) */
    Rte_Write_P_TqAdp_stCdnNxtCkg_TqAdp_stCdnNxtCkg(tqadp_stcdnnxtckg_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I188(0) */
    Rte_Write_P_TqSys_tqCkEngLossAdp_TqSys_tqCkEngLossAdp(tqsys_tqckenglossadp_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl100ms_TqCmpTAir
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl100ms_TqCmpTAir(void)
{
    /* INPUT */
    UInt16 airsys_mfairmesthrestim_swc_in;
    UInt8 coptst_steng_swc_in;
    UInt32 eom_tiengrun_swc_in;
    UInt32 eom_tiengstop_swc_in;
    SInt16 ext_tairuscmprmes_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 ext_tdsthrmes_swc_in;
    UInt8 tqsys_btypfu_swc_in;
    UInt16 veh_spdveh_swc_in;

    /* FIM (FRM) */
    Boolean frm_binhtairestim_fim_in;
    Boolean tqadpcmp_bool_temp;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqcmp_bengstrtreq_swc_out;
    UInt8 tqcmp_btairchk_swc_out;
    SInt8 tqcmp_tairestim_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_AirSys_mfAirMesThrEstim_AirSys_mfAirMesThrEstim(&airsys_mfairmesthrestim_swc_in);
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        Rte_Read_R_EOM_tiEngRun_EOM_tiEngRun(&eom_tiengrun_swc_in);
        Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&eom_tiengstop_swc_in);
        Rte_Read_R_Ext_tAirUsCmprMes_Ext_tAirUsCmprMes(&ext_tairuscmprmes_swc_in);
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        Rte_Read_R_Ext_tDsThrMes_Ext_tDsThrMes(&ext_tdsthrmes_swc_in);
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqsys_btypfu_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I708(0) */
        Rte_Call_R_FRM_bInhTAirEstim_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhtairestim_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhtairestim_fim_in = (Boolean)DDS_FALSE;
		}




        TQADPCMP_Model_Tair(airsys_mfairmesthrestim_swc_in, /* BIN7 */
                            coptst_steng_swc_in,
                            eom_tiengrun_swc_in, /* DEC0 */
                            eom_tiengstop_swc_in, /* DEC0 */
                            ext_tairuscmprmes_swc_in, /* BIN0 */
                            ext_tcomes_swc_in, /* BIN0 */
                            ext_tdsthrmes_swc_in, /* BIN0 */
                            /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhtairestim_fim_in),
                            tqsys_btypfu_swc_in,
                            veh_spdveh_swc_in, /* BIN7 */
                            &tqcmp_bengstrtreq_swc_out,
                            &tqcmp_btairchk_swc_out,
                            &tqcmp_tairestim_swc_out /* BIN0 */);

        /* IRV OUTPUT */
    }
    else
    {
        tqcmp_bengstrtreq_swc_out = TqCmp_bEngStrtReq_B;
        tqcmp_btairchk_swc_out = TqCmp_bTAirChk_B;
        tqcmp_tairestim_swc_out = TqCmp_tAirEstim_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I151(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCmp_bEngStrtReq_TqCmp_bEngStrtReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqcmp_bengstrtreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I152(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCmp_bTAirChk_TqCmp_bTAirChk(DDS_M_CONVERT_UINT8_TO_BOOL(tqcmp_btairchk_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I153(0) */
    Rte_Write_P_TqCmp_tAirEstim_TqCmp_tAirEstim(tqcmp_tairestim_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpAccCord
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpAccCord(void)
{
    /* INPUT */
    UInt16 tqcmp_tqacloss_swc_in;
    SInt16 tqcmp_tqaltloss_swc_in;
    UInt16 tqcmp_tqauxloss_swc_in;
    UInt16 tqcmp_tqstgpmploss_swc_in;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_TqCmp_tqACLoss_TqCmp_tqACLoss(&tqcmp_tqacloss_swc_in);
        Rte_Read_R_TqCmp_tqAltLoss_TqCmp_tqAltLoss(&tqcmp_tqaltloss_swc_in);
        Rte_Read_R_TqCmp_tqAuxLoss_TqCmp_tqAuxLoss(&tqcmp_tqauxloss_swc_in);
        Rte_Read_R_TqCmp_tqStgPmpLoss_TqCmp_tqStgPmpLoss(&tqcmp_tqstgpmploss_swc_in);

        TQADPCMP_Coord_Accessory_Ls(tqcmp_tqacloss_swc_in, /* BIN4 */
                                    tqcmp_tqaltloss_swc_in, /* BIN4 */
                                    tqcmp_tqauxloss_swc_in, /* BIN4 */
                                    tqcmp_tqstgpmploss_swc_in, /* BIN4 */
                                    &TqCmp_tqAuxSumLossCmp_irv_MP, /* BIN4 */
                                    &TqCmp_tqAuxSumLossEstim_irv_MP /* BIN4 */);


        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I405(0) */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpAccCord_TqCmp_tqAuxSumLossCmp_irv(TqCmp_tqAuxSumLossCmp_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I406(0) */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpAccCord_TqCmp_tqAuxSumLossEstim_irv(TqCmp_tqAuxSumLossEstim_irv_MP);
    }
    else
    {


    }


}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpEngLoss
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpEngLoss(void)
{
    /* INPUT */
    SInt16 ext_pdsthrmes_swc_in;
    UInt32 eom_tiengstop_swc_in;
    UInt16 engm_rairldcor_swc_in;
    UInt16 eng_nckfil_swc_in;
    UInt16 exm_pexmnfestim_swc_in;
    SInt16 exm_pustrbestimtqsys_swc_in;
    UInt16 ext_pairextmes_swc_in;
    UInt16 ext_poilmes_swc_in;
    SInt16 ext_tcomes_swc_in;
    SInt16 ext_toilmes_swc_in;
    UInt16 inm_pdsthrcor_swc_in;
    UInt8 tqsys_btypfu_swc_in;
    UInt16 tqsys_tqckpumphiploss_swc_in;
    UInt16 ext_neng_swc_in;

    /* FIM */
    UInt8 frm_bacvtqenglossdftoil_fim_in;
    UInt8 frm_bacvtqenglossdftpds_fim_in;
    UInt8 frm_bacvtqenglossdftpmp_fim_in;
    UInt8 frm_bacvtqenglossdftt_fim_in;
    Boolean tqadpcmp_bool_temp;

    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqsys_tqckengloss_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I192(0) */
        Rte_Read_R_Ext_pDsThrMes_Ext_pDsThrMes(&ext_pdsthrmes_swc_in);
        Rte_Read_R_EOM_tiEngStop_EOM_tiEngStop(&eom_tiengstop_swc_in);
        Rte_Read_R_Ext_nEng_Ext_nEng(&ext_neng_swc_in);
        Rte_Read_R_EngM_rAirLdCor_EngM_rAirLdCor(&engm_rairldcor_swc_in);
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_ExM_pExMnfEstim_ExM_pExMnfEstim(&exm_pexmnfestim_swc_in);
        Rte_Read_R_ExM_pUsTrbEstimTqSys_ExM_pUsTrbEstimTqSys(&exm_pustrbestimtqsys_swc_in);
        Rte_Read_R_Ext_pAirExtMes_Ext_pAirExtMes(&ext_pairextmes_swc_in);
        Rte_Read_R_Ext_pOilMes_Ext_pOilMes(&ext_poilmes_swc_in);
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        Rte_Read_R_Ext_tOilMes_Ext_tOilMes(&ext_toilmes_swc_in);
        Rte_Read_R_InM_pDsThrCor_InM_pDsThrCor(&inm_pdsthrcor_swc_in);
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqsys_btypfu_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqSys_tqCkPumpHiPLoss_TqSys_tqCkPumpHiPLoss(&tqsys_tqckpumphiploss_swc_in);

		Rte_Call_R_FRM_bAcvTqEngLossDftOil_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bacvtqenglossdftoil_fim_in = DDS_TRUE;
		}
		else
		{
			frm_bacvtqenglossdftoil_fim_in = DDS_FALSE;
		}
        Rte_Call_R_FRM_bAcvTqEngLossDftPDs_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bacvtqenglossdftpds_fim_in = DDS_TRUE;
		}
		else
		{
			frm_bacvtqenglossdftpds_fim_in = DDS_FALSE;
		}
        Rte_Call_R_FRM_bAcvTqEngLossDftPmp_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bacvtqenglossdftpmp_fim_in = DDS_TRUE;
		}
		else
		{
			frm_bacvtqenglossdftpmp_fim_in = DDS_FALSE;
		}
        Rte_Call_R_FRM_bAcvTqEngLossDftT_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bacvtqenglossdftt_fim_in = DDS_TRUE;
		}
		else
		{
			frm_bacvtqenglossdftt_fim_in = DDS_FALSE;
		}


        TQADPCMP_Coord_Lost_Motor(eom_tiengstop_swc_in, /* DEC0 */
                                  engm_rairldcor_swc_in, /* BIN14 */
                                  eng_nckfil_swc_in, /* BIN2 */
                                  exm_pexmnfestim_swc_in, /* NBIN3 */
                                  exm_pustrbestimtqsys_swc_in, /* BIN0 */
                                  ext_pairextmes_swc_in, /* BIN0 */
                                  ext_pdsthrmes_swc_in, /* BIN0 */
                                  ext_poilmes_swc_in, /* BIN7 */
                                  ext_tcomes_swc_in, /* BIN0 */
                                  ext_toilmes_swc_in, /* DEC1 */
                                  frm_bacvtqenglossdftoil_fim_in,
                                  frm_bacvtqenglossdftpds_fim_in,
                                  frm_bacvtqenglossdftpmp_fim_in,
                                  frm_bacvtqenglossdftt_fim_in,
                                  inm_pdsthrcor_swc_in, /* NBIN3 */
                                  tqsys_btypfu_swc_in,
                                  tqsys_tqckpumphiploss_swc_in, /* BIN4 */
                                  ext_neng_swc_in,/*BIN0*/
                                  &tqsys_tqckengloss_swc_out /* BIN4 */);


        /* IRV OUTPUT */
    }
    else
    {
        tqsys_tqckengloss_swc_out = TqSys_tqCkEngLoss_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I175(0) */
    Rte_Write_P_TqSys_tqCkEngLoss_TqSys_tqCkEngLoss(tqsys_tqckengloss_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpGlbCord
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpGlbCord(void)
{
    /* INPUT */
    UInt8 coptst_steng_swc_in;
    UInt16 tqcmp_tqcnvloss_swc_in; /* BIN4 */
    UInt16 tqsys_tqckengloss_swc_in; /* BIN4 */
    SInt16 tqsys_tqckenglossadp_swc_in; /* BIN4 */

    /* IRV */
    SInt16 tqcmp_tqauxsumlosscmp_irv_in;
    SInt16 tqcmp_tqauxsumlossestim_irv_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqcmp_tqsumlosscmp_swc_out;
    SInt16 tqcmp_tqsumlosscmpwoutcnv_swc_out;
    SInt16 tqcmp_tqsumlossestim_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        Rte_Read_R_TqCmp_tqCnvLoss_TqCmp_tqCnvLoss(&tqcmp_tqcnvloss_swc_in);
        Rte_Read_R_TqSys_tqCkEngLoss_TqSys_tqCkEngLoss(&tqsys_tqckengloss_swc_in);
        Rte_Read_R_TqSys_tqCkEngLossAdp_TqSys_tqCkEngLossAdp(&tqsys_tqckenglossadp_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I405(0) */
        tqcmp_tqauxsumlosscmp_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpGlbCord_TqCmp_tqAuxSumLossCmp_irv();
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I406(0) */
        tqcmp_tqauxsumlossestim_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpGlbCord_TqCmp_tqAuxSumLossEstim_irv();


        TQADPCMP_Coord_Global_Loss(coptst_steng_swc_in,
                                   tqcmp_tqauxsumlosscmp_irv_in, /* BIN4 */
                                   tqcmp_tqauxsumlossestim_irv_in, /* BIN4 */
                                   tqcmp_tqcnvloss_swc_in, /* BIN4 */
                                   tqsys_tqckengloss_swc_in, /* BIN4 */
                                   tqsys_tqckenglossadp_swc_in, /* BIN4 */
                                   &tqcmp_tqsumlosscmp_swc_out, /* BIN4 */
                                   &tqcmp_tqsumlosscmpwoutcnv_swc_out, /* BIN4 */
                                   &tqcmp_tqsumlossestim_swc_out /* BIN4 */);


        /* IRV OUTPUT */
    }
    else
    {
        tqcmp_tqsumlosscmp_swc_out = TqCmp_tqSumLossCmp_B;
        tqcmp_tqsumlosscmpwoutcnv_swc_out = TqCmp_tqSumLossCmpWoutCnv_B;
        tqcmp_tqsumlossestim_swc_out = TqCmp_tqSumLossEstim_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I129(0) */
    Rte_Write_P_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(tqcmp_tqsumlosscmp_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I130(0) */
    Rte_Write_P_TqCmp_tqSumLossCmpWoutCnv_TqCmp_tqSumLossCmpWoutCnv(tqcmp_tqsumlosscmpwoutcnv_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I184(0) */
    Rte_Write_P_TqCmp_tqSumLossEstim_TqCmp_tqSumLossEstim(tqcmp_tqsumlossestim_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpTqAC
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpTqAC(void)
{
    /* INPUT */
    UInt16 eng_nckfil_swc_in;
    UInt8 ext_stactypcf_swc_in;
    UInt8 tqadp_bfrzadpacauxon_swc_in;
    UInt16 tqcmp_pwracauxloss_swc_in;
    UInt8 tqdem_btqgrdlim_swc_in;

    Boolean tqadpcmp_bool_temp;

    /* IRV */
    UInt8 tqadp_bfrzadpacitecuon_irv_in;
    UInt8 tqcmp_bacextecuoffdftselon_irv_in;
    UInt16 tqcmp_pwracexteculoss_irv_in;
    UInt16 tqcmp_pwraciteculoss_irv_in;
    UInt8 tqadp_bfrzadpacextecuon_irv_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqadp_bfrzadpacon_swc_out;
    UInt16 tqcmp_pwracloss_swc_out;
    UInt16 tqcmp_tqacloss_swc_out;
    UInt8 tqcmp_bacoffdftselon_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_Ext_stACTypCf_Ext_stACTypCf(&ext_stactypcf_swc_in);
        Rte_Read_R_TqAdp_bFrzAdpACAuxOn_TqAdp_bFrzAdpACAuxOn(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpacauxon_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqCmp_pwrACAuxLoss_TqCmp_pwrACAuxLoss(&tqcmp_pwracauxloss_swc_in);
        Rte_Read_R_TqDem_bTqGrdLim_TqDem_bTqGrdLim(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqdem_btqgrdlim_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);

        tqadpcmp_bool_temp = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpTqAC_TqAdp_bFrzAdpACExtECUOn_irv();
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpacextecuon_irv_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I401(0) */
        tqadpcmp_bool_temp = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpTqAC_TqAdp_bFrzAdpACItECUOn_irv();
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqadp_bfrzadpacitecuon_irv_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I402(0) */
        tqadpcmp_bool_temp = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpTqAC_TqCmp_bACExtECUOffDftSelOn_irv();
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqcmp_bacextecuoffdftselon_irv_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I403(0) */
        tqcmp_pwracexteculoss_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpTqAC_TqCmp_pwrACExtECULoss_irv();
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I404(0) */
        tqcmp_pwraciteculoss_irv_in = Rte_IrvRead_RE_TqSys_Sdl10ms_TqCmpTqAC_TqCmp_pwrACItECULoss_irv();


        TQADPCMP_Estim_Air_Cond(eng_nckfil_swc_in, /* BIN2 */
                                ext_stactypcf_swc_in, /* BIN0 */
                                tqadp_bfrzadpacauxon_swc_in,
                                tqadp_bfrzadpacextecuon_irv_in,
                                tqadp_bfrzadpacitecuon_irv_in,
                                tqcmp_bacextecuoffdftselon_irv_in,
                                tqcmp_pwracauxloss_swc_in, /* BIN0 */
                                tqcmp_pwracexteculoss_irv_in, /* BIN0 */
                                tqcmp_pwraciteculoss_irv_in, /* BIN0 */
                                tqdem_btqgrdlim_swc_in,
                                &tqadp_bfrzadpacon_swc_out,
                                &tqcmp_bacoffdftselon_swc_out,
                                &tqcmp_pwracloss_swc_out, /* BIN0 */
                                &tqcmp_tqacloss_swc_out /* BIN4 */);


        /* IRV OUTPUT */
    }
    else
    {
        tqadp_bfrzadpacon_swc_out = TqAdp_bFrzAdpACOn_B;
        tqcmp_pwracloss_swc_out = TqCmp_pwrACLoss_B;
        tqcmp_tqacloss_swc_out = TqCmp_tqACLoss_B;
        tqcmp_bacoffdftselon_swc_out = TqCmp_bACOffDftSelOn_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I123(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpACOn_TqAdp_bFrzAdpACOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpacon_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I124(0) */
    Rte_Write_P_TqCmp_pwrACLoss_TqCmp_pwrACLoss(tqcmp_pwracloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I125(0) */
    Rte_Write_P_TqCmp_tqACLoss_TqCmp_tqACLoss(tqcmp_tqacloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I132(0) */
    /* <PRQA_COMMENT><4470> <2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqCmp_bACOffDftSelOn_TqCmp_bACOffDftSelOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqcmp_bacoffdftselon_swc_out));

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpTqAC3
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpTqAC3(void)
{
    /* INPUT */
    UInt16 eng_nckfil_swc_in;
    UInt8 ext_baccluauth_swc_in;
    UInt16 ext_pac_swc_in;
    SInt8 ext_tair_swc_in;
    UInt8 ext_stactypcf_swc_in;


    /* FIM (FRM) */
    Boolean frm_binhaciteculossmdl_fim_in;
    Boolean tqadpcmp_bool_temp;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_Ext_bACCluAuth_Ext_bACCluAuth(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        ext_baccluauth_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_Ext_pAC_Ext_pAC(&ext_pac_swc_in);
        Rte_Read_R_Ext_tAir_Ext_tAir(&ext_tair_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I700(0) */
        Rte_Call_R_FRM_bInhACItECULossMdl_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhaciteculossmdl_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhaciteculossmdl_fim_in = (Boolean)DDS_FALSE;
		}
        Rte_Read_R_Ext_stACTypCf_Ext_stACTypCf(&ext_stactypcf_swc_in);

        TQADPCMP_Estim_Air_Cond_T3(eng_nckfil_swc_in, /* BIN2 */
                                       ext_baccluauth_swc_in,
                                       ext_pac_swc_in, /* BIN0 */
                                       ext_tair_swc_in, /* BIN0 */
                                       /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                       (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhaciteculossmdl_fim_in),
                                       ext_stactypcf_swc_in, /*BIN0*/
                                       &TqAdp_bFrzAdpACItECUOn_irv_MP,
                                       &TqCmp_pwrACItECULoss_irv_MP /* BIN0 */);




        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I401(0) */
        /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpTqAC3_TqAdp_bFrzAdpACItECUOn_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqAdp_bFrzAdpACItECUOn_irv_MP));
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I404(0) */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpTqAC3_TqCmp_pwrACItECULoss_irv(TqCmp_pwrACItECULoss_irv_MP);
    }
    else
    {


    }


}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpTqAC4
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpTqAC4(void)
{
    /* INPUT */
    UInt8 ac_bacclu_swc_in;
    UInt8 ac_pwrac_swc_in;
    UInt8 tqres_bdftacswton_swc_in;
    UInt8 ext_stactypcf_swc_in;
    UInt16 ext_pac_swc_in;
    SInt8 ext_tair_swc_in;


    /* FIM (FRM) */
    Boolean frm_binhacexteculossmdl_fim_in;

    Boolean tqadpcmp_bool_temp;


    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_AC_bACClu_AC_bACClu(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        ac_bacclu_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_AC_pwrAC_AC_pwrAC(&ac_pwrac_swc_in);
        Rte_Read_R_TqRes_bDftACSwtOn_TqRes_bDftACSwtOn(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqres_bdftacswton_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_Ext_pAC_Ext_pAC(&ext_pac_swc_in);
        Rte_Read_R_Ext_tAir_Ext_tAir(&ext_tair_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I701(0) */
        Rte_Call_R_FRM_bInhACExtECULossMdl_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhacexteculossmdl_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhacexteculossmdl_fim_in = (Boolean)DDS_FALSE;
		}
        Rte_Read_R_Ext_stACTypCf_Ext_stACTypCf(&ext_stactypcf_swc_in);

        TQADPCMP_Estim_Air_Cond_T4(ac_bacclu_swc_in,
                                       ac_pwrac_swc_in, /* NBIN0 resol 25 */
                                       /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                       (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhacexteculossmdl_fim_in),
                                       tqres_bdftacswton_swc_in,
                                       ext_stactypcf_swc_in,
                                       ext_tair_swc_in, /* BIN0 */
                                       ext_pac_swc_in, /* BIN0 */
                                       &TqAdp_bFrzAdpACExtECUOn_irv_MP,
                                       &TqCmp_bACExtECUOfDftSelOn_irv_MP,
                                       &TqCmp_pwrACExtECULoss_irv_MP /* BIN0 */);

        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I400(0) */
        /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpTqAC4_TqAdp_bFrzAdpACExtECUOn_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqAdp_bFrzAdpACExtECUOn_irv_MP));
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I402(0) */
        /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpTqAC4_TqCmp_bACExtECUOffDftSelOn_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqCmp_bACExtECUOfDftSelOn_irv_MP));
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I403(0) */
        Rte_IrvWrite_RE_TqSys_Sdl10ms_TqCmpTqAC4_TqCmp_pwrACExtECULoss_irv(TqCmp_pwrACExtECULoss_irv_MP);
    }
    else
    {

    }

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpTqAlt
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpTqAlt(void)
{
    /* INPUT */
    SInt16 cooptmel_tqalt_swc_in;
    UInt8 coptst_steng_swc_in;
    UInt8 coptuh_stpwt_swc_in;
    UInt16 eng_nckfil_swc_in;
    UInt8 ext_btqaltestimelsys_swc_in;
    UInt16 ext_facrattqaltcf_swc_in;
    UInt8 ext_ialtexct_swc_in;
    UInt8 ext_idxaltclas_swc_in;
    UInt8 ext_idxctlaltprovidf_swc_in;
    UInt8 ext_raltcycop_swc_in;
    UInt8 ext_staltclascf_swc_in;
    UInt8 ext_stelprodcf_swc_in;
    SInt16 ext_tqalt_swc_in;
    UInt8 tqdem_btqgrdlim_swc_in;
    UInt16 tqres_tqfanstrtloss_swc_in;

    /* FIM (FRM) */
    Boolean frm_bdftalttyp_fim_in;
    Boolean frm_bdftcomalt_fim_in;
    Boolean frm_bdftelalt_fim_in;
    Boolean frm_bdftmecalt_fim_in;
    Boolean frm_binhaltlossmdl_fim_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 tqcmp_tqaltloss_swc_out;
    UInt8 tqadp_bfrzadpalton_swc_out;

    Boolean tqadpcmp_bool_temp;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_CoOptmEl_tqAlt_CoOptmEl_tqAlt(&cooptmel_tqalt_swc_in);
        Rte_Read_R_CoPTSt_stEng_CoPTSt_stEng(&coptst_steng_swc_in);
        Rte_Read_R_CoPtUH_stPwt_CoPtUH_stPwt(&coptuh_stpwt_swc_in);
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_Ext_bTqAltEstimElSys_Ext_bTqAltEstimElSys(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        ext_btqaltestimelsys_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_Ext_facRatTqAltCf_Ext_facRatTqAltCf(&ext_facrattqaltcf_swc_in);
        Rte_Read_R_Ext_iAltExct_Ext_iAltExct(&ext_ialtexct_swc_in);
        Rte_Read_R_Ext_idxAltClas_Ext_idxAltClas(&ext_idxaltclas_swc_in);
        Rte_Read_R_Ext_idxCtlAltProvIdf_Ext_idxCtlAltProvIdf(&ext_idxctlaltprovidf_swc_in);
        Rte_Read_R_Ext_rAltCycOp_Ext_rAltCycOp(&ext_raltcycop_swc_in);
        Rte_Read_R_Ext_stAltClasCf_Ext_stAltClasCf(&ext_staltclascf_swc_in);
        Rte_Read_R_Ext_stElProdCf_Ext_stElProdCf(&ext_stelprodcf_swc_in);
        Rte_Read_R_Ext_tqAlt_Ext_tqAlt(&ext_tqalt_swc_in);
        Rte_Read_R_TqDem_bTqGrdLim_TqDem_bTqGrdLim(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqdem_btqgrdlim_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_TqRes_tqFanStrtLoss_TqRes_tqFanStrtLoss(&tqres_tqfanstrtloss_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I703(0) */
        Rte_Call_R_FRM_bDftAltTyp_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bdftalttyp_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_bdftalttyp_fim_in = (Boolean)DDS_FALSE;
		}
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I704(0) */
        Rte_Call_R_FRM_bDftComAlt_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bdftcomalt_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_bdftcomalt_fim_in = (Boolean)DDS_FALSE;
		}
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I705(0) */
        Rte_Call_R_FRM_bDftElAlt_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bdftelalt_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_bdftelalt_fim_in = (Boolean)DDS_FALSE;
		}
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I706(0) */
        Rte_Call_R_FRM_bDftMecAlt_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_bdftmecalt_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_bdftmecalt_fim_in = (Boolean)DDS_FALSE;
		}
        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I707(0) */
        Rte_Call_R_FRM_bInhAltLossMdl_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhaltlossmdl_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhaltlossmdl_fim_in = (Boolean)DDS_FALSE;
		}



        TQADPCMP_Estim_Alternator(cooptmel_tqalt_swc_in, /* BIN4 */
                                  coptst_steng_swc_in,
                                  coptuh_stpwt_swc_in,
                                  eng_nckfil_swc_in, /* BIN2 */
                                  ext_btqaltestimelsys_swc_in,
                                  ext_facrattqaltcf_swc_in, /* BIN7 */
                                  ext_ialtexct_swc_in, /* DEC1 */
                                  ext_idxaltclas_swc_in, /* BIN0 */
                                  ext_idxctlaltprovidf_swc_in, /* BIN0 */
                                  ext_raltcycop_swc_in, /* BIN0 */
                                  ext_staltclascf_swc_in,
                                  ext_stelprodcf_swc_in,
                                  ext_tqalt_swc_in, /* BIN4 */
                                  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdftalttyp_fim_in),
                                  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdftcomalt_fim_in),
                                  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdftelalt_fim_in),
                                  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdftmecalt_fim_in),
                                  /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhaltlossmdl_fim_in),
                                  tqdem_btqgrdlim_swc_in,
                                  tqres_tqfanstrtloss_swc_in, /* BIN4 */
                                  &tqadp_bfrzadpalton_swc_out,
                                  &tqcmp_bdgo_tqaltrv,
                                  &tqcmp_tqaltloss_swc_out /* BIN4 */);




		 /* DEM :  TqCmp_tqAltRv */
				if((UInt32)tqcmp_bmonrun_tqaltrv==(UInt32)DDS_TRUE)
				{
					/* Diagnostic activation */
					if((UInt32)tqcmp_bdgo_tqaltrv==(UInt32)DDS_TRUE)
					{
						(void)Rte_Call_R_TqCmp_tqAltRv_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
					}
					else
					{
						(void)Rte_Call_R_TqCmp_tqAltRv_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
					}

				}
				else
				{
					if ((UInt32)tqcmp_bmonrun_tqaltrv_prev==(UInt32)DDS_TRUE)
					{
						(void)Rte_Call_R_TqCmp_tqAltRv_SetEventStatus(DEM_EVENT_STATUS_INIT);

					}
					else
					{
						/* case E_OK */
					}

					tqcmp_bmonrun_tqaltrv = DDS_TRUE;

				}
				tqcmp_bmonrun_tqaltrv_prev = tqcmp_bmonrun_tqaltrv;


    }
    else
    {
        tqcmp_tqaltloss_swc_out = TqCmp_tqAltLoss_B;
        tqadp_bfrzadpalton_swc_out = TqAdp_bFrzAdpAltOn_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I121(0) */
    Rte_Write_P_TqCmp_tqAltLoss_TqCmp_tqAltLoss(tqcmp_tqaltloss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I122(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpAltOn_TqAdp_bFrzAdpAltOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpalton_swc_out));

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpTqCnv
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpTqCnv(void)
{
    /* INPUT */
    UInt8 copt_btqtx_swc_in;
    UInt16 copt_ntrb_swc_in;
    UInt8 copt_stdragred_swc_in;
    SInt16 copt_toilgbx_swc_in;
    SInt16 copt_tqcnvclu_swc_in;
    UInt16 eng_nckfil_swc_in;
    UInt16 tqsys_ntaridl_swc_in;
    UInt16 veh_spdveh_swc_in;
    UInt8 ext_stgbxcf_swc_in;


    /* FIM (FRM) */
    Boolean frm_binhcnvlossmdl_fim_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqadp_bfrzadpcnvon_swc_out;
    UInt16 tqcmp_tqcnvloss_swc_out;

    Boolean tqadpcmp_bool_temp;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_CoPt_bTqTx_CoPt_bTqTx(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        copt_btqtx_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_CoPt_nTrb_CoPt_nTrb(&copt_ntrb_swc_in);
        Rte_Read_R_CoPt_stDragRed_CoPt_stDragRed(&copt_stdragred_swc_in);
        Rte_Read_R_CoPt_tOilGBx_CoPt_tOilGBx(&copt_toilgbx_swc_in);
        Rte_Read_R_CoPt_tqCnvClu_CoPt_tqCnvClu(&copt_tqcnvclu_swc_in);
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_TqSys_nTarIdl_TqSys_nTarIdl(&tqsys_ntaridl_swc_in);
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I709(0) */
        Rte_Call_R_FRM_bInhCnvLossMdl_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhcnvlossmdl_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhcnvlossmdl_fim_in = (Boolean)DDS_FALSE;
		}




        (void)Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);

        if((UInt32)ext_stgbxcf_swc_in == 1)
        {
            TQADPCMP_Estim_Bva(copt_btqtx_swc_in,
                               copt_ntrb_swc_in, /* BIN2 */
                               copt_stdragred_swc_in,
                               copt_toilgbx_swc_in, /* BIN2 */
                               copt_tqcnvclu_swc_in, /* BIN4 */
                               eng_nckfil_swc_in, /* BIN2 */
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhcnvlossmdl_fim_in),
                               tqsys_ntaridl_swc_in, /* BIN2 */
                               veh_spdveh_swc_in, /* BIN7 */
                               &tqadp_bfrzadpcnvon_swc_out,
                               &tqcmp_tqcnvloss_swc_out /* BIN4 */);
        }
        else
        {
            tqadp_bfrzadpcnvon_swc_out = 0;
            tqcmp_tqcnvloss_swc_out = 0;
        }


        /* IRV OUTPUT */
    }
    else
    {
        tqadp_bfrzadpcnvon_swc_out = TqAdp_bFrzAdpCnvOn_B;
        tqcmp_tqcnvloss_swc_out = TqCmp_tqCnvLoss_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I127(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpCnvOn_TqAdp_bFrzAdpCnvOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpcnvon_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I128(0) */
    Rte_Write_P_TqCmp_tqCnvLoss_TqCmp_tqCnvLoss(tqcmp_tqcnvloss_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_TqCmpTqStg
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_TqCmpTqStg(void)
{
    /* INPUT */
    UInt16 eng_nckfil_swc_in;
    UInt8 ext_ststgpmpcf_swc_in;
    UInt8 stg_bstgpmpthdmes_swc_in;
    UInt16 stg_pstgpmplnrmes_swc_in;
    UInt8 tqdem_btqgrdlim_swc_in;
    UInt16 veh_spdveh_swc_in;

    /* FIM (FRM) */
    Boolean frm_binhstgpmplossmdl_fim_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt16 tqcmp_tqstgpmploss_swc_out;
    UInt8 tqadp_bfrzadpstgpmpon_swc_out;

    Boolean tqadpcmp_bool_temp;

    if ((UInt32)DDS_FALSE == (UInt32)TQADPCMP_ACTIVE_BYP_C)
    {
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        Rte_Read_R_Ext_stStgPmpCf_Ext_stStgPmpCf(&ext_ststgpmpcf_swc_in);
        Rte_Read_R_Stg_bStgPmpThdMes_Stg_bStgPmpThdMes(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        stg_bstgpmpthdmes_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_Stg_pStgPmpLnrMes_Stg_pStgPmpLnrMes(&stg_pstgpmplnrmes_swc_in);
        Rte_Read_R_TqDem_bTqGrdLim_TqDem_bTqGrdLim(&tqadpcmp_bool_temp);
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        tqdem_btqgrdlim_swc_in = DDS_M_CONVERT_BOOL_TO_UINT8(tqadpcmp_bool_temp);
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I702(0) */
        Rte_Call_R_FRM_bInhStgPmpLossMdl_GetFunctionPermission(&tqadpcmp_bool_temp);
		if((UInt32)tqadpcmp_bool_temp == (UInt32)DDS_FALSE)
		{
			frm_binhstgpmplossmdl_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhstgpmplossmdl_fim_in = (Boolean)DDS_FALSE;
		}

        if((UInt32)ext_ststgpmpcf_swc_in != (UInt32)0)
        {
            TQADPCMP_Estim_Steering(eng_nckfil_swc_in, /* BIN2 */
                                    ext_ststgpmpcf_swc_in,
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhstgpmplossmdl_fim_in),
                                    stg_bstgpmpthdmes_swc_in,
                                    stg_pstgpmplnrmes_swc_in, /* BIN2 */
                                    tqdem_btqgrdlim_swc_in,
                                    veh_spdveh_swc_in /* BIN7 */,
                                    &tqcmp_tqstgpmploss_swc_out,
                                    &tqadp_bfrzadpstgpmpon_swc_out);
        }
        else
        {
            tqcmp_tqstgpmploss_swc_out = 0;
            tqadp_bfrzadpstgpmpon_swc_out = DDS_FALSE;
        }

        /* IRV OUTPUT */
    }
    else
    {
        tqcmp_tqstgpmploss_swc_out = TqCmp_tqStgPmpLoss_B;
        tqadp_bfrzadpstgpmpon_swc_out = TqAdp_bFrzAdpStgPmpOn_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I126(0) */
    Rte_Write_P_TqCmp_tqStgPmpLoss_TqCmp_tqStgPmpLoss(tqcmp_tqstgpmploss_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-TqAdpCmp.I136(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqAdp_bFrzAdpStgPmpOn_TqAdp_bFrzAdpStgPmpOn(DDS_M_CONVERT_UINT8_TO_BOOL(tqadp_bfrzadpstgpmpon_swc_out));

}

/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : TqAdpCmp_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) TqAdpCmp_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_TqAdpCmp_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define TQADPCMP_STOP_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.31
* Date: 18/10/2013 11:42:11
* PERL v5.14.2
* Lib_CC 1.35
* Lib_Clipboard 1.01
* Lib_CQ 1.21
* Lib_DD_Check 2.10
* Lib_DD_Check_Checks 1.35
* Lib_DD_Check_Data 2.10
* Lib_DD_Check_Utils 2.00
* Lib_DD_Compare 1.10
* Lib_DD_GenCode 3.29
* Lib_DD_Load 3.07
* Lib_DD_Structure 1.10
* Lib_Feature 1.01
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.02
* Lib_Gui_ComboBox 1.06
* Lib_Gui_Common 1.43
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.01
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.17
* Lib_Hash 1.33
* Lib_Log 1.31
* Lib_Pjt 1.32
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.19
* Lib_Scheduler_XML 1.48
* Lib_Spectool_Gen_DD 2.23
* Lib_Twk 1.06
* Lib_Utils 1.06
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.09
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* LOCAL_SECTION *
TQADPCMP_ACTIVE_BYP_C ;["FALSE"*0*|"TRUE"*1*] ;TQADPCMP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;"FALSE" ; Bypass  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdpCmp_ModuleVersion_Major_MP ; ;TQADPCMP ;N/A ;0 ;255 ;1 ;["COMP"] ;["N/A"] ;N/A ;N/A ;N/A ;12 ; TqAdpCmp_ModuleVersion_Major_MP  ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdpCmp_ModuleVersion_Minor_MP ; ;TQADPCMP ;N/A ;0 ;255 ;1 ;["COMP"] ;["N/A"] ;N/A ;N/A ;N/A ;1 ; TqAdpCmp_ModuleVersion_Minor_MP  ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpACExtECUOn_irv_MP ;["FALSE"|"TRUE"] ;TQADP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ; IRV mesure point  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpACItECUOn_irv_MP ;["FALSE"|"TRUE"] ;TQADP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ; IRV mesure point  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpACOn_B ;["FALSE"*0*|"TRUE"*1*] ;TQADP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqAdp_bFrzAdpACOn  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpAltOn_B ;["FALSE"*0*|"TRUE"*1*] ;TQADP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqAdp_bFrzAdpAltOn  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpCnvOn_B ;["FALSE"*0*|"TRUE"*1*] ;TQADP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqAdp_bFrzAdpCnvOn  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpStgPmpOn_B ;["FALSE"|"TRUE"] ;TQADP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqAdp_bFrzAdpStgPmpOn  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bInhEngStop_B ;["FALSE"*0*|"TRUE"*1*] ;TQADP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqAdp_bInhEngStop  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_stCdnNxtCkg_B ;["NOMINAL"*0*|"FAVORABLE"*1*|"DEFAVORABLE"*2*] ;TQADP ;N/A ;0 ;2 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;NOMINAL ; Bypass de TqAdp_stCdnNxtCkg  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bACExtECUOfDftSelOn_irv_MP ;["FALSE"|"TRUE"] ;TQCMP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ; IRV mesure point  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bACOffDftSelOn_B ;["FALSE"*0*|"TRUE"*1*] ;TQCMP ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqCmp_bACOffDftSelOn  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bEngStrtReq_B ;["FALSE"*0*|"TRUE"*1*] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqCmp_bEngStrtReq  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bTAirChk_B ;["FALSE"*0*|"TRUE"*1*] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Bypass de TqCmp_bTAirChk  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrACExtECULoss_irv_MP ; ;TQCMP ;W ;0 ;5000 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Puissance calcule preleve par le systeme de Clim de type 4  ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrACItECULoss_irv_MP ; ;TQCMP ;W ;0 ;5000 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Puissance preleve par le systeme de Clim de type 3.  ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrACLoss_B ; ;TQS ;W ;0 ;5000 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_pwrACLoss  ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tAirEstim_B ; ;TQS ;deg C ;-40 ;100 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;20 ; Bypass de TqCmp_tAirEstim  ;["YES"] ;SInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqACLoss_B ; ;TQS ;Nm ;0 ;500 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqACLoss  ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqAltLoss_B ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqAltLoss  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqAuxSumLossCmp_irv_MP ; ;TQCMP ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; IRV mesure point  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqAuxSumLossEstim_irv_MP ; ;TQCMP ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Couple estime preleve par les accessoires  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqCnvLoss_B ; ;TQS ;Nm ;0 ;500 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqCnvLoss  ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqStgPmpLoss_B ; ;TQS ;Nm ;0 ;500 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqStgPmpLoss  ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqSumLossCmpWoutCnv_B ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqSumLossCmpWoutCnv  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqSumLossCmp_B ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqSumLossCmp  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqSumLossEstim_B ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqCmp_tqSumLossEstim  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEngLossAdp_B ; ;TQS ;Nm ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqSys_tqCkEngLossAdp  ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEngLoss_B ; ;TQS ;Nm ;0 ;500 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; Bypass de TqSys_tqCkEngLoss  ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_tqadp_idxteng ; ;TQADPCMP ;N/A ;1 ;8 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;type ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_tqadp_idxtqaccu ; ;TQADPCMP ;N/A ;1 ;10 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;type ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TQADPCMP_10_SIZE ; ;TQADPCMP ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ;10 size for Table ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TQADPCMP_8_SIZE ; ;TQADPCMP ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;8 ;8 size for Table ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
TqAdp_idxTEng_A ;1{t_tqadp_idxteng}TQADPCMP_8_SIZE ;TQADP ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[1 2 3 4 5 6 7 8] ;Vecteur partage de cartographies (zone de temperature moteur) ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_idxTqAccu_A ;1{t_tqadp_idxtqaccu}TQADPCMP_10_SIZE ;TQADP ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[1 2 3 4 5 6 7 8 9 10] ;Vecteur partage de cartographies (indice de precision de couple) ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A



Data_Dictionary */

