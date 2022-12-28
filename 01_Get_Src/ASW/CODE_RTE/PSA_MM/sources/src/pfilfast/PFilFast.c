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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFilFast.c
* Version int :/main/00PSASWC_E6/9 Date: 29/8/2013 11 h 45 m User:meme 
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\5 Date: 27/8/2013 14 h 54 m User:thauvin 
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\4 Date: 21/8/2013 13 h 39 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\3 Date: 7/8/2013 15 h 19 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 7/8/2013 15 h 6 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 15 h 50 m User:thauvin
*    TWK_model:NO_MODEL
*    comments :dev PFilFast 14.0
* Version int :/main/00PSASWC_E6/8 Date: 8/8/2012 10 h 13 m User:posmyk
*    TWK_model:NO_MODEL
*    comments :For PFilFast_13_1_e6
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\1 Date: 7/8/2012 16 h 20 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For PFilFast_13_1_e6
* Version int :/main/00PSASWC_E6/7 Date: 26/7/2012 11 h 6 m User:posmyk
*    TWK_model:NO_MODEL
*    comments :For PFilFast_13_0_e6
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\1 Date: 26/7/2012 9 h 13 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For PFilFast_13_0_e6
* Version int :/main/00PSASWC_E6/6 Date: 12/3/2012 15 h 12 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for PFilFast 12.0
* Version dev :\main\branch_morisseau_pfilfast_euro6_dev\1 Date: 12/3/2012 14 h 34 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for PFilFast 12.0
* Version int :/main/00PSASWC_E6/5 Date: 4/11/2011 10 h 2 m User:meme
*    TWK_model:NO_MODEL
*    comments :for PFilFast 11.2
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/10/2011 10 h 51 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast 11.2
* Version int :/main/00PSASWC_E6/4 Date: 16/5/2011 15 h 7 m User:esnault
*    TWK_model:NO_MODEL
*    comments :update module version
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 12/5/2011 11 h 11 m User:demezil
*    TWK_model:NO_MODEL
*    comments :update module version
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 29/4/2011 10 h 56 m User:demezil
*    TWK_model:NO_MODEL
*    comments :to reduce CPU load
* Version int :/main/00PSASWC_E6/3 Date: 17/2/2011 15 h 35 m User:meme
*    TWK_model:NO_MODEL
*    comments :update for 11.0
* Version dev :\main\branch_halouane\2 Date: 27/1/2011 17 h 42 m User:halouane
*    TWK_model:NO_MODEL
*    comments :update for 11.0
* Version dev :\main\branch_halouane\1 Date: 24/1/2011 12 h 52 m User:halouane
*    TWK_model:NO_MODEL
*    comments :Add new function required by the split of "Acc Thres Wght" function (production of
*    comments :TqSys_tqThdPha3It before consume it)
* Version int :/main/00PSASWC_E6/2 Date: 20/9/2010 15 h 11 m User:meme
*    TWK_model:NO_MODEL
*    comments :update for PFilFast 10.1
*    comments :update for PFilFast 10.1
* Version int :/main/00PSASWC_E6/1 Date: 12/8/2010 12 h 41 m User:esnault
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 20/9/2010 14 h 27 m User:salmane
*    TWK_model:NO_MODEL
*    comments :update for PFilFast 10.1
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 26/7/2010 15 h 14 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 6/7/2010 15 h 45 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 5/7/2010 17 h 37 m User:demezil
*    TWK_model:NO_MODEL
*    comments :for PFilFast e6
* Version dev :\main\branch_lemort_pfilfast_dev\1 Date: 1/7/2010 16 h 58 m User:lemort
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

#include "PFilFast.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if PFILFAST_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
dds_lib.* version is not compatible with current SWC version
#endif

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

#define PFILFAST_12_SIZE        12
#define PFILFAST_10_SIZE        10
#define PFILFAST_8_SIZE         8
#define PFILFAST_7_SIZE         7

#define PFILFAST_CONF_0                  (UInt32)0
#define PFILFAST_CONF_1                  (UInt32)1
#define PFILFAST_CONF_2                  (UInt32)2
#define PFILFAST_CONF_3                  (UInt32)3
#define PFILFAST_CONF_4                  (UInt32)4

#define PFILFAST_TQSYS_FACGAINPHA3_MAX   (UInt16) (1 * BIN7)
#define PFILFAST_TQSYS_FACGAINPHA5_MAX   (UInt32) (1 * BIN16)
#define PFILFAST_TQSYS_FACGAINPHA_MAX    (UInt16) (1 * BIN7)
/*******************************************************************************
*  File Level Type Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt32, AUTOMATIC) TqSys_PrmCf1_2; /* BIN16 */
extern VAR(SInt32, AUTOMATIC) TqSys_PrmCf1_3; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_PrmCf1_4; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_PrmCf1_5; /* BIN11 */
extern VAR(UInt32, AUTOMATIC) TqSys_facPrmCf1_2; /* BIN16 */
extern VAR(SInt32, AUTOMATIC) TqSys_facPrmCf1_3; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_facPrmCf1_4; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_facPrmCf1_5; /* BIN11 */
extern VAR(UInt32, AUTOMATIC) TqSys_PrmCf2_2; /* BIN16 */
extern VAR(SInt32, AUTOMATIC) TqSys_PrmCf2_3; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_PrmCf2_4; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_PrmCf2_5; /* BIN11 */
extern VAR(UInt32, AUTOMATIC) TqSys_facPrmCf2_2; /* BIN16 */
extern VAR(SInt32, AUTOMATIC) TqSys_facPrmCf2_3; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_facPrmCf2_4; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_facPrmCf2_5; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt16, AUTOMATIC) TqSys_PrmCf2_1; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) TqSys_PrmCf2_6; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) TqSys_PrmCf1_1; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) TqSys_PrmCf1_6; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqSys_facPrmCf1_1; /* BIN7 */
extern VAR(UInt8, AUTOMATIC) TqSys_facPrmCf1_6; /* BIN7 */
extern VAR(UInt8, AUTOMATIC) TqSys_facPrmCf2_1; /* BIN7 */
extern VAR(UInt8, AUTOMATIC) TqSys_facPrmCf2_6; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"


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
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_idxTqAccuY_A
[PFILFAST_10_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0),
(UInt16)(4 * BIN0), (UInt16)(5 * BIN0), (UInt16)(6 * BIN0),
(UInt16)(7 * BIN0), (UInt16)(8 * BIN0), (UInt16)(9 * BIN0),
(UInt16)(10 * BIN0)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_A
[PFILFAST_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(SInt16, AUTOMATIC) TqSys_tCo1_A
[PFILFAST_8_SIZE] = {
(SInt16)(-20 * BIN0), (SInt16)(-10 * BIN0), (SInt16)(0 * BIN0),
(SInt16)(20 * BIN0), (SInt16)(40 * BIN0), (SInt16)(60 * BIN0),
(SInt16)(80 * BIN0), (SInt16)(100 * BIN0)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_rAccP_A
[PFILFAST_10_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(40 * BIN7), (UInt16)(50 * BIN7),
(UInt16)(60 * BIN7), (UInt16)(70 * BIN7), (UInt16)(80 * BIN7),
(UInt16)(100 * BIN7)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_nEng3_A
[PFILFAST_12_SIZE] = {
(UInt16)(700 * BIN2), (UInt16)(800 * BIN2), (UInt16)(1000 * BIN2),
(UInt16)(1250 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(1750 * BIN2),
(UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(3500 * BIN2), (UInt16)(4000 * BIN2), (UInt16)(4500 * BIN2)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_nEng1_A
[PFILFAST_8_SIZE] = {
(UInt16)(800 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1250 * BIN2),
(UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2),
(UInt16)(3000 * BIN2), (UInt16)(4000 * BIN2)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_A
[PFILFAST_10_SIZE] = {
(UInt16)(800 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1200 * BIN2),
(UInt16)(1400 * BIN2), (UInt16)(1600 * BIN2), (UInt16)(1800 * BIN2),
(UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(3500 * BIN2)
};

/* <PRQA_COMMENT><3211> Ok, the axe is used in many other files </3211></PRQA_COMMENT> */
volatile CONST(SInt16, AUTOMATIC) TqSys_tqFil_A
[PFILFAST_12_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(20 * BIN4), (SInt16)(40 * BIN4),
(SInt16)(60 * BIN4), (SInt16)(80 * BIN4), (SInt16)(100 * BIN4),
(SInt16)(120 * BIN4), (SInt16)(140 * BIN4), (SInt16)(160 * BIN4),
(SInt16)(180 * BIN4), (SInt16)(200 * BIN4), (SInt16)(220 * BIN4)
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
*  Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
VAR(UInt32, AUTOMATIC) TqSys_facGainPha5;   /* BIN16 */
VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha6;    /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha7;    /* BIN11 */
VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha4;    /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
VAR(UInt16, AUTOMATIC) TqSys_facScaPha3Cf1; /* BIN7 */
VAR(UInt16, AUTOMATIC) TqSys_facScaPha3Cf2; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
VAR(UInt8, AUTOMATIC) TqSys_facGainPha3;    /* BIN7 */
VAR(UInt8, AUTOMATIC) TqSys_facGainPha; /* BIN7 */
VAR(UInt8, AUTOMATIC) TqSys_facMinPha3; /* BIN7 */
VAR(UInt8, AUTOMATIC) TqSys_facMinPhaConv; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
*  Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) CoCha_tqEfcLim_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoCha_tqEfcLimTqMaxDyn_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) CoCha_tqEfcReq_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_nDif_nEngNTrb_B = (SInt16)(0 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEngDeceIni_B = (UInt16)(0 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiTranCllIt_B = (UInt16)(0 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDeceIniIt_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEfcFil_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqIncCllIt_B = (UInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdPha3It_B = (SInt16)(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaPha3Cf1_C = (UInt16)(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facScaPha3Cf2_C = (UInt16)(1 * BIN7);
#define PFILFAST_STOP_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facMinPha3_C = (UInt8)(0.2 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facMinPhaConv_C = (UInt8)(0.1 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bInhEGR_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bRstAOS_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bTqAccuReq_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bTqDynReq_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bTqReqASR_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bTqReqMSR_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcceClrCrossAOSIt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcceDetAOSIt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvCllIt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bClrCrossAcce_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDeceAcvIt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDeceDetAOSIt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDiDrivFilReq_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bUHFrzReq_B = DDS_FALSE;
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_noCylCutAuthIt_B = (SInt8)(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_noGearCordDrivFil_B = (UInt8)(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_noGearDece_B = (UInt8)(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_stDrivFilCfPha_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_stDrivFilPhaIt_B = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) PFILFAST_ACTIVE_BYP_C = DDS_FALSE;
#define PFILFAST_STOP_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"

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

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define PFILFAST_START_SEC_CONST_VERSION_MODULE_8BIT
#include "PFilFast_MemMap.h"
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) PFilFast_ModuleVersion_Major_MP = (UInt8)14;
/* <PRQA_COMMENT><3207> This constant has to be declared as if it is not used </3207></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) PFilFast_ModuleVersion_Minor_MP = (UInt8)0;
#define PFILFAST_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_PFilFast_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_PFilFast_001_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqsys_bdidrivfilreq_swc_out;
    UInt16 tqsys_nengdeceini_swc_out;
    UInt8 tqsys_bacceclrcrossaosit_swc_out;
    UInt8 tqsys_baccedetaosit_swc_out;
    UInt8 tqsys_bacvcllit_swc_out;
    UInt8 tqsys_bclrcrossacce_swc_out;
    UInt8 tqsys_bdeceacvit_swc_out;
    UInt8 tqsys_bdecedetaosit_swc_out;
    UInt8 tqsys_buhfrzreq_swc_out;
    SInt16 tqsys_ndif_nengntrb_swc_out;
    SInt8 tqsys_nocylcutauthit_swc_out;
    UInt8 tqsys_nogearcorddrivfil_swc_out;
    UInt8 tqsys_nogeardece_swc_out;
    UInt8 tqsys_stdrivfilcfpha_swc_out;
    UInt8 tqsys_stdrivfilphait_swc_out;
    UInt16 tqsys_titrancllit_swc_out;
    SInt16 tqsys_tqckdeceiniit_swc_out;
    SInt16 tqsys_tqckefcfil_swc_out;
    UInt16 tqsys_tqinccllit_swc_out;
    SInt16 tqsys_tqthdpha3it_swc_out;
    SInt16 cocha_tqefclimtqmaxdyn_swc_out;
    SInt16 cocha_tqefcreq_swc_out;
    UInt8 cocha_binhegr_swc_out;
    UInt8 cocha_brstaos_swc_out;
    UInt8 cocha_btqaccureq_swc_out;
    UInt8 cocha_btqdynreq_swc_out;
    UInt8 cocha_btqreqasr_swc_out;
    UInt8 cocha_btqreqmsr_swc_out;
    SInt16 cocha_tqefclim_swc_out;


    PFILFAST_Coord_Esp_Init(&cocha_tqefcreq_swc_out,
                            &cocha_binhegr_swc_out,
                            &cocha_btqaccureq_swc_out,
                            &cocha_btqdynreq_swc_out,
                            &cocha_btqreqasr_swc_out,
                            &cocha_btqreqmsr_swc_out,
                            &cocha_tqefclim_swc_out,
                            &cocha_brstaos_swc_out,
                            &cocha_tqefclimtqmaxdyn_swc_out );


    PFILFAST_Pre_Treat_Init(&tqsys_bdidrivfilreq_swc_out,
                        &tqsys_ndif_nengntrb_swc_out,
                        &tqsys_nogearcorddrivfil_swc_out,
                        &tqsys_stdrivfilcfpha_swc_out );

    PFILFAST_Scnd_Out_Init(&tqsys_bacceclrcrossaosit_swc_out,
                           &tqsys_baccedetaosit_swc_out,
                           &tqsys_bacvcllit_swc_out,
                           &tqsys_bclrcrossacce_swc_out,
                           &tqsys_bdecedetaosit_swc_out,
                           &tqsys_buhfrzreq_swc_out,
                           &tqsys_nocylcutauthit_swc_out, /* BIN0 */
                           &tqsys_titrancllit_swc_out, /* DEC2 */
                           &tqsys_tqinccllit_swc_out /* BIN4 */);

    PFILFAST_Filt_Activ_Init(&tqsys_bdeceacvit_swc_out,
                        &tqsys_nengdeceini_swc_out,
                        &tqsys_nogeardece_swc_out,
                        &tqsys_tqckdeceiniit_swc_out );

    PFILFAST_Acc_Thres_Wght_Init(&tqsys_tqthdpha3it_swc_out);

    PFILFAST_Acc_Conf2_Init();

    PFILFAST_Acc_Conf1_Init();

    PFILFAST_Decel_Times_Init();

    PFILFAST_Decel_Thres_Slew_Init();

    PFILFAST_State_Machine_Init(&tqsys_stdrivfilphait_swc_out,
                            &tqsys_tqckefcfil_swc_out);


    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I100(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDiDrivFilReq_TqSys_bDiDrivFilReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdidrivfilreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I101(0) */
    Rte_Write_P_TqSys_nEngDeceIni_TqSys_nEngDeceIni(tqsys_nengdeceini_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I102(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceClrCrossAOSIt_TqSys_bAcceClrCrossAOSIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacceclrcrossaosit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I103(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceDetAOSIt_TqSys_bAcceDetAOSIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_baccedetaosit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I104(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvCllIt_TqSys_bAcvCllIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvcllit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I105(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bClrCrossAcce_TqSys_bClrCrossAcce(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bclrcrossacce_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I106(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceAcvIt_TqSys_bDeceAcvIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdeceacvit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I107(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceDetAOSIt_TqSys_bDeceDetAOSIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdecedetaosit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I108(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bUHFrzReq_TqSys_bUHFrzReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_buhfrzreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I109(0) */
    Rte_Write_P_TqSys_nDif_nEngNTrb_TqSys_nDif_nEngNTrb(tqsys_ndif_nengntrb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I110(0) */
    Rte_Write_P_TqSys_noCylCutAuthIt_TqSys_noCylCutAuthIt(tqsys_nocylcutauthit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I111(0) */
    Rte_Write_P_TqSys_noGearCordDrivFil_TqSys_noGearCordDrivFil(tqsys_nogearcorddrivfil_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I112(0) */
    Rte_Write_P_TqSys_noGearDece_TqSys_noGearDece(tqsys_nogeardece_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I113(0) */
    Rte_Write_P_TqSys_stDrivFilCfPha_TqSys_stDrivFilCfPha(tqsys_stdrivfilcfpha_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I114(0) */
    Rte_Write_P_TqSys_stDrivFilPhaIt_TqSys_stDrivFilPhaIt(tqsys_stdrivfilphait_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I115(0) */
    Rte_Write_P_TqSys_tiTranCllIt_TqSys_tiTranCllIt(tqsys_titrancllit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I116(0) */
    Rte_Write_P_TqSys_tqCkDeceIniIt_TqSys_tqCkDeceIniIt(tqsys_tqckdeceiniit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I117(0) */
    Rte_Write_P_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(tqsys_tqckefcfil_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I118(0) */
    Rte_Write_P_TqSys_tqIncCllIt_TqSys_tqIncCllIt(tqsys_tqinccllit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I119(0) */
    Rte_Write_P_TqSys_tqThdPha3It_TqSys_tqThdPha3It(tqsys_tqthdpha3it_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I146(0) */
    Rte_Write_P_CoCha_tqEfcLimTqMaxDyn_CoCha_tqEfcLimTqMaxDyn(cocha_tqefclimtqmaxdyn_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I147(0) */
    Rte_Write_P_CoCha_tqEfcReq_CoCha_tqEfcReq(cocha_tqefcreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I148(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bInhEGR_CoCha_bInhEGR(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_binhegr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I149(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bRstAOS_CoCha_bRstAOS(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_brstaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I150(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqAccuReq_CoCha_bTqAccuReq(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqaccureq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I151(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqDynReq_CoCha_bTqDynReq(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqdynreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I152(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqReqASR_CoCha_bTqReqASR(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqreqasr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I153(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqReqMSR_CoCha_bTqReqMSR(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqreqmsr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I154(0) */
    Rte_Write_P_CoCha_tqEfcLim_CoCha_tqEfcLim(cocha_tqefclim_swc_out);
}
/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_CoCha
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_CoCha(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 cha_tqdynasrreq_swc_in;
    UInt8 cha_sttqreq_swc_in;
    SInt16 cha_tqmsrreq_swc_in;
    SInt16 copt_tqefcmaxprotdftl_swc_in;
    SInt16 englim_tqckefcchalim_swc_in;
    SInt16 englim_tqefcmaxdynvehspdctl_swc_in;
    SInt16 tqsys_tqckefcfil_swc_in;
    /* FIM (FRM) */
    Boolean frm_binhespreq_fim_in;

    /* OUTPUT */
    /* SWC OUT */
    SInt16 cocha_tqefclimtqmaxdyn_swc_out;
    SInt16 cocha_tqefcreq_swc_out;
    UInt8 cocha_binhegr_swc_out;
    UInt8 cocha_brstaos_swc_out;
    UInt8 cocha_btqaccureq_swc_out;
    UInt8 cocha_btqdynreq_swc_out;
    UInt8 cocha_btqreqasr_swc_out;
    UInt8 cocha_btqreqmsr_swc_out;
    SInt16 cocha_tqefclim_swc_out;

    Boolean pfilfast_bool_temp;

    if ((UInt32)DDS_FALSE == (UInt32)PFILFAST_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I121(0) */
        Rte_Read_R_Cha_tqDynASRReq_Cha_tqDynASRReq(&cha_tqdynasrreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I155(0) */
        Rte_Read_R_Cha_stTqReq_Cha_stTqReq(&cha_sttqreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I156(0) */
        Rte_Read_R_Cha_tqMSRReq_Cha_tqMSRReq(&cha_tqmsrreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I157(0) */
        Rte_Read_R_CoPt_tqEfcMaxProtDftl_CoPt_tqEfcMaxProtDftl(&copt_tqefcmaxprotdftl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I158(0) */
        Rte_Read_R_EngLim_tqCkEfcChaLim_EngLim_tqCkEfcChaLim(&englim_tqckefcchalim_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I159(0) */
        Rte_Read_R_EngLim_tqEfcMaxDynVehSpdCtl_EngLim_tqEfcMaxDynVehSpdCtl(&englim_tqefcmaxdynvehspdctl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I160(0) */
        Rte_Read_R_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(&tqsys_tqckefcfil_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I701(0) */
        Rte_Call_R_FRM_bInhESPReq_GetFunctionPermission(&pfilfast_bool_temp);
        if((UInt32)pfilfast_bool_temp == (UInt32)DDS_FALSE)
        {
			frm_binhespreq_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_binhespreq_fim_in = (Boolean)DDS_FALSE;
		}



        PFILFAST_Coord_Esp(cha_sttqreq_swc_in, /* BIN0 */
                           cha_tqdynasrreq_swc_in, /* BIN4 */
                           cha_tqmsrreq_swc_in, /* BIN4 */
                           englim_tqckefcchalim_swc_in, /* BIN4 */
                           tqsys_tqckefcfil_swc_in, /* BIN4 */
                           copt_tqefcmaxprotdftl_swc_in, /* BIN4 */
                           englim_tqefcmaxdynvehspdctl_swc_in, /* BIN4 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhespreq_fim_in),
                           &cocha_tqefcreq_swc_out, /* BIN4 */
                           &cocha_binhegr_swc_out,
                           &cocha_btqaccureq_swc_out,
                           &cocha_btqdynreq_swc_out,
                           &cocha_btqreqasr_swc_out,
                           &cocha_btqreqmsr_swc_out,
                           &cocha_tqefclim_swc_out, /* BIN4 */
                           &cocha_brstaos_swc_out,
                           &cocha_tqefclimtqmaxdyn_swc_out /* BIN4 */);



        /* IRV OUTPUT */
    }
    else
    {
        cocha_tqefclimtqmaxdyn_swc_out = CoCha_tqEfcLimTqMaxDyn_B;
        cocha_tqefcreq_swc_out = CoCha_tqEfcReq_B;
        cocha_binhegr_swc_out = CoCha_bInhEGR_B;
        cocha_brstaos_swc_out = CoCha_bRstAOS_B;
        cocha_btqaccureq_swc_out = CoCha_bTqAccuReq_B;
        cocha_btqdynreq_swc_out = CoCha_bTqDynReq_B;
        cocha_btqreqasr_swc_out = CoCha_bTqReqASR_B;
        cocha_btqreqmsr_swc_out = CoCha_bTqReqMSR_B;
        cocha_tqefclim_swc_out = CoCha_tqEfcLim_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I146(0) */
    Rte_Write_P_CoCha_tqEfcLimTqMaxDyn_CoCha_tqEfcLimTqMaxDyn(cocha_tqefclimtqmaxdyn_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I147(0) */
    Rte_Write_P_CoCha_tqEfcReq_CoCha_tqEfcReq(cocha_tqefcreq_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I148(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bInhEGR_CoCha_bInhEGR(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_binhegr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I149(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bRstAOS_CoCha_bRstAOS(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_brstaos_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I150(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqAccuReq_CoCha_bTqAccuReq(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqaccureq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I151(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqDynReq_CoCha_bTqDynReq(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqdynreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I152(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqReqASR_CoCha_bTqReqASR(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqreqasr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I153(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_CoCha_bTqReqMSR_CoCha_bTqReqMSR(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_btqreqmsr_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I154(0) */
    Rte_Write_P_CoCha_tqEfcLim_CoCha_tqEfcLim(cocha_tqefclim_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_Sdl10ms_tqEfcFil
*  Event            : Every 10ms
*  Description      : Call 10ms scheduled functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_tqEfcFil(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 accp_raccp_swc_in;
    SInt16 cha_tqdynasrreq_swc_in;
    UInt8 copt_nodrivfiltyp_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    UInt16 copt_ntrb_swc_in;
    UInt16 covsctl_raccpeng_swc_in;
    UInt16 eng_nckfil_swc_in;
    SInt16 englim_tqckdrivfil_swc_in;
    Boolean ext_bdidrivfilreq_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    SInt8 ext_tair_swc_in;
    SInt16 ext_tcomes_swc_in;
    Boolean tqcll_bacvcll_swc_in;
    Boolean tqclrcros_bacvclrcross_swc_in;
    UInt8 tqclrcros_stdetclr_swc_in;
    UInt16 tqcmp_tqacloss_swc_in;
    SInt16 tqcmp_tqsumlosscmp_swc_in;
    Boolean tqdem_bdrivtakeoff_swc_in;
    Boolean tqdem_bmodspt_swc_in;
    SInt16 tqlimem_tqlimem_swc_in;
    Boolean tqsys_bacvvehspdctlreg_swc_in;
    Boolean tqsys_binjcutdynreq_swc_in;
    Boolean tqsys_btypfu_swc_in;
    UInt8 tqsys_idxtqaccu_swc_in;
    SInt16 treattenms_nckgrdfil_swc_in;
    UInt16 veh_spdveh_swc_in;

    /* FIM (FRM) */
    Boolean frm_bdft_spdveh_fim_in;

    Boolean pfilfast_bool_temp;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqsys_bdidrivfilreq_swc_out;
    UInt16 tqsys_nengdeceini_swc_out;
    UInt8 tqsys_bacceclrcrossaosit_swc_out;
    UInt8 tqsys_baccedetaosit_swc_out;
    UInt8 tqsys_bacvcllit_swc_out;
    UInt8 tqsys_bclrcrossacce_swc_out;
    UInt8 tqsys_bdeceacvit_swc_out;
    UInt8 tqsys_bdecedetaosit_swc_out;
    UInt8 tqsys_buhfrzreq_swc_out;
    SInt16 tqsys_ndif_nengntrb_swc_out;
    SInt8 tqsys_nocylcutauthit_swc_out;
    UInt8 tqsys_nogearcorddrivfil_swc_out;
    UInt8 tqsys_nogeardece_swc_out;
    UInt8 tqsys_stdrivfilcfpha_swc_out;
    UInt8 tqsys_stdrivfilphait_swc_out;
    UInt16 tqsys_titrancllit_swc_out;
    SInt16 tqsys_tqckdeceiniit_swc_out;
    SInt16 tqsys_tqckefcfil_swc_out;
    UInt16 tqsys_tqinccllit_swc_out;
    SInt16 tqsys_tqthdpha3it_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)PFILFAST_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I120(0) */
        Rte_Read_R_AccP_rAccP_AccP_rAccP(&accp_raccp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I121(0) */
        Rte_Read_R_Cha_tqDynASRReq_Cha_tqDynASRReq(&cha_tqdynasrreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I122(0) */
        Rte_Read_R_CoPt_noDrivFilTyp_CoPt_noDrivFilTyp(&copt_nodrivfiltyp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I123(0) */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I124(0) */
        Rte_Read_R_CoPt_nTrb_CoPt_nTrb(&copt_ntrb_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I125(0) */
        Rte_Read_R_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(&covsctl_raccpeng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I126(0) */
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I127(0) */
        Rte_Read_R_EngLim_tqCkDrivFil_EngLim_tqCkDrivFil(&englim_tqckdrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I128(0) */
        Rte_Read_R_Ext_bDiDrivFilReq_Ext_bDiDrivFilReq(&ext_bdidrivfilreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I129(0) */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
         /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I130(0) */
        Rte_Read_R_Ext_tAir_Ext_tAir(&ext_tair_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I131(0) */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I132(0) */
        Rte_Read_R_TqCll_bAcvCll_TqCll_bAcvCll(&tqcll_bacvcll_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I133(0) */
        Rte_Read_R_TqClrCros_bAcvClrCross_TqClrCros_bAcvClrCross(&tqclrcros_bacvclrcross_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I134(0) */
        Rte_Read_R_TqClrCros_stDetClr_TqClrCros_stDetClr(&tqclrcros_stdetclr_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I135(0) */
        Rte_Read_R_TqCmp_tqACLoss_TqCmp_tqACLoss(&tqcmp_tqacloss_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I136(0) */
        Rte_Read_R_TqCmp_tqSumLossCmp_TqCmp_tqSumLossCmp(&tqcmp_tqsumlosscmp_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I137(0) */
        Rte_Read_R_TqDem_bDrivTakeOff_TqDem_bDrivTakeOff(&tqdem_bdrivtakeoff_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I138(0) */
        Rte_Read_R_TqDem_bModSpt_TqDem_bModSpt(&tqdem_bmodspt_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I139(0) */
        Rte_Read_R_TqLimEM_tqLimEM_TqLimEM_tqLimEM(&tqlimem_tqlimem_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I140(0) */
        Rte_Read_R_TqSys_bAcvVehSpdCtlReg_TqSys_bAcvVehSpdCtlReg(&tqsys_bacvvehspdctlreg_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I141(0) */
        Rte_Read_R_TqSys_bInjCutDynReq_TqSys_bInjCutDynReq(&tqsys_binjcutdynreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I142(0) */
        Rte_Read_R_TqSys_bTypFu_TqSys_bTypFu(&tqsys_btypfu_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I143(0) */
        Rte_Read_R_TqSys_idxTqAccu_TqSys_idxTqAccu(&tqsys_idxtqaccu_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I144(0) */
        Rte_Read_R_TreatTenms_nCkGrdFil_TreatTenms_nCkGrdFil(&treattenms_nckgrdfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I145(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I700(0) */
        Rte_Call_R_FRM_bDft_spdVeh_GetFunctionPermission(&pfilfast_bool_temp);
        if((UInt32)pfilfast_bool_temp == (UInt32)DDS_FALSE)
        {
			frm_bdft_spdveh_fim_in = (Boolean)DDS_TRUE;
		}
		else
		{
			frm_bdft_spdveh_fim_in = (Boolean)DDS_FALSE;
		}


        PFILFAST_Pre_Treat(copt_ntrb_swc_in, /* BIN2 */
                           copt_nodrivfiltyp_swc_in,
                           copt_nogearcorddrivfil_swc_in,
                           eng_nckfil_swc_in, /* BIN2 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(ext_bdidrivfilreq_swc_in),
                           ext_stgbxcf_swc_in,
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(tqclrcros_bacvclrcross_swc_in),
                           tqcmp_tqacloss_swc_in, /* BIN4 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(tqdem_bdrivtakeoff_swc_in),
                           veh_spdveh_swc_in, /* BIN7 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                           DDS_M_CONVERT_BOOL_TO_UINT8(frm_bdft_spdveh_fim_in),
                           &tqsys_bdidrivfilreq_swc_out,
                           &tqsys_ndif_nengntrb_swc_out, /* BIN2 */
                           &tqsys_nogearcorddrivfil_swc_out, /* BIN0 */
                           &tqsys_stdrivfilcfpha_swc_out);

    	PFILFAST_F03_02_01_Acceleration_Thresholds(eng_nckfil_swc_in, /* BIN2 */
                                        tqsys_nogearcorddrivfil_swc_out, /* BIN0 */
                                        tqsys_idxtqaccu_swc_in, /* BIN0 */
                                        tqsys_stdrivfilcfpha_swc_out, /* BIN0 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
										DDS_M_CONVERT_BOOL_TO_UINT8(tqdem_bmodspt_swc_in),
										covsctl_raccpeng_swc_in,
                                        &tqsys_tqthdpha3it_swc_out /* BIN4 */);


        PFILFAST_Filt_Activ(covsctl_raccpeng_swc_in,
                            englim_tqckdrivfil_swc_in,
                            eng_nckfil_swc_in,
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(tqcll_bacvcll_swc_in),
                            tqcmp_tqsumlosscmp_swc_in,
                            tqlimem_tqlimem_swc_in,
                            tqsys_bdidrivfilreq_swc_out,
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_binjcutdynreq_swc_in),
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_btypfu_swc_in),
                            tqsys_nogearcorddrivfil_swc_out, /* BIN0 */
                            &tqsys_bdeceacvit_swc_out,
                            &tqsys_nengdeceini_swc_out,
                            &tqsys_nogeardece_swc_out,
                            &tqsys_tqckdeceiniit_swc_out );

        PFILFAST_Acc_Thres_Wght(covsctl_raccpeng_swc_in,
                                eng_nckfil_swc_in,
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                DDS_M_CONVERT_BOOL_TO_UINT8(tqdem_bmodspt_swc_in),
                                tqsys_ndif_nengntrb_swc_out,
                                tqsys_nengdeceini_swc_out,
                                tqsys_nogearcorddrivfil_swc_out,
                                tqsys_nogeardece_swc_out,
                                treattenms_nckgrdfil_swc_in);

    /* F03_02_04_Acceleration_PArameters */
        TqSys_facMinPha3 = TqSys_facMinPha3_C;
        TqSys_facMinPhaConv = TqSys_facMinPhaConv_C;
        TqSys_facScaPha3Cf1 = TqSys_facScaPha3Cf1_C;
        TqSys_facScaPha3Cf2 = TqSys_facScaPha3Cf2_C;

        switch((UInt32)tqsys_stdrivfilcfpha_swc_out)
        {
            case(PFILFAST_CONF_1) :
                PFILFAST_Acc_Conf1( covsctl_raccpeng_swc_in,
                                    eng_nckfil_swc_in,
                                    ext_tcomes_swc_in,
                                    tqsys_nogearcorddrivfil_swc_out);
				/* <PRQA_COMMENT><2101> Warning due to tool, conversion is ok </2101></PRQA_COMMENT> */
                TqSys_facGainPha3 = (UInt8)DDS_M_MIN(TqSys_PrmCf1_1,PFILFAST_TQSYS_FACGAINPHA3_MAX);
                TqSys_facGainPha5 = DDS_M_MIN(TqSys_PrmCf1_2,PFILFAST_TQSYS_FACGAINPHA5_MAX);
                TqSys_tqSlopPha6 = TqSys_PrmCf1_3;
                TqSys_tqSlopPha7 = TqSys_PrmCf1_4;
                TqSys_tqSlopPha4 = TqSys_PrmCf1_5;
                /* <PRQA_COMMENT><2101> Warning due to tool, conversion is ok </2101></PRQA_COMMENT> */
                TqSys_facGainPha = (UInt8)DDS_M_MIN(TqSys_PrmCf1_6,PFILFAST_TQSYS_FACGAINPHA_MAX);
                break;

            case(PFILFAST_CONF_2) :
                PFILFAST_Acc_Conf1( covsctl_raccpeng_swc_in,
                                    eng_nckfil_swc_in,
                                    ext_tcomes_swc_in,
                                    tqsys_nogearcorddrivfil_swc_out);

                TqSys_facGainPha3 = TqSys_facPrmCf1_1;
                TqSys_facGainPha5 = TqSys_facPrmCf1_2;
                TqSys_tqSlopPha6 = TqSys_facPrmCf1_3;
                TqSys_tqSlopPha7 = TqSys_facPrmCf1_4;
                TqSys_tqSlopPha4 = TqSys_facPrmCf1_5;
                TqSys_facGainPha = TqSys_facPrmCf1_6;
                break;

            case(PFILFAST_CONF_3) :
                PFILFAST_Acc_Conf2( covsctl_raccpeng_swc_in,
                                    eng_nckfil_swc_in,
                                    ext_tcomes_swc_in,
                                    tqsys_nogearcorddrivfil_swc_out);
				/* <PRQA_COMMENT><2101> Warning due to tool, conversion is ok </2101></PRQA_COMMENT> */
                TqSys_facGainPha3 = (UInt8)DDS_M_MIN(TqSys_PrmCf2_1,PFILFAST_TQSYS_FACGAINPHA3_MAX);
                TqSys_facGainPha5 = DDS_M_MIN(TqSys_PrmCf2_2,PFILFAST_TQSYS_FACGAINPHA5_MAX);
                TqSys_tqSlopPha6 = TqSys_PrmCf2_3;
                TqSys_tqSlopPha7 = TqSys_PrmCf2_4;
                TqSys_tqSlopPha4 = TqSys_PrmCf2_5;
                /* <PRQA_COMMENT><2101> Warning due to tool, conversion is ok </2101></PRQA_COMMENT> */
                TqSys_facGainPha = (UInt8)DDS_M_MIN(TqSys_PrmCf2_6,PFILFAST_TQSYS_FACGAINPHA_MAX);
                break;

            case(PFILFAST_CONF_4) :
                PFILFAST_Acc_Conf2( covsctl_raccpeng_swc_in,
                                    eng_nckfil_swc_in,
                                    ext_tcomes_swc_in,
                                    tqsys_nogearcorddrivfil_swc_out);

                TqSys_facGainPha3 = TqSys_facPrmCf2_1;
                TqSys_facGainPha5 = TqSys_facPrmCf2_2;
                TqSys_tqSlopPha6 = TqSys_facPrmCf2_3;
                TqSys_tqSlopPha7 = TqSys_facPrmCf2_4;
                TqSys_tqSlopPha4 = TqSys_facPrmCf2_5;
                TqSys_facGainPha = TqSys_facPrmCf2_6;
                break;

            case(PFILFAST_CONF_0) :
            default :
                TqSys_facGainPha3 = (UInt8)(0 * BIN7);
                TqSys_facGainPha5 = (UInt32)(0 * BIN16);
                TqSys_tqSlopPha6 = (SInt32)(0 * BIN11);
                TqSys_tqSlopPha7 = (SInt32)(0 * BIN11);
                TqSys_tqSlopPha4 = (SInt32)(0 * BIN11);
                TqSys_facGainPha = (UInt8)(0 * BIN7);
                break;
        }
    /* end of F03_02_04_Acceleration_PArameters */


        PFILFAST_Decel_Times(   ext_tcomes_swc_in,
                                tqsys_nengdeceini_swc_out,
                                tqsys_nogeardece_swc_out,
                                tqsys_stdrivfilcfpha_swc_out,
                                tqsys_tqckdeceiniit_swc_out);

        PFILFAST_Decel_Thres_Slew( ext_tair_swc_in, /* BIN0 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                   DDS_M_CONVERT_BOOL_TO_UINT8(tqdem_bmodspt_swc_in),
                                   tqsys_idxtqaccu_swc_in, /* BIN0 */
                                   tqsys_nengdeceini_swc_out, /* BIN2 */
                                   tqsys_nogeardece_swc_out, /* BIN0 */
                                   tqsys_stdrivfilcfpha_swc_out,
                                   tqsys_tqckdeceiniit_swc_out /* BIN4 */);

        PFILFAST_State_Machine(accp_raccp_swc_in, /* BIN7 */
                               cha_tqdynasrreq_swc_in, /* BIN4 */
                               covsctl_raccpeng_swc_in, /* BIN7 */
                               tqcmp_tqsumlosscmp_swc_in, /* BIN4 */
                               tqlimem_tqlimem_swc_in, /* BIN4 */
    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacvvehspdctlreg_swc_in),
                               tqsys_bdeceacvit_swc_out,
                               tqsys_bdidrivfilreq_swc_out,
                               tqsys_tqthdpha3it_swc_out, /* BIN4 */
                               tqclrcros_stdetclr_swc_in, /*BIN0*/
                               &tqsys_stdrivfilphait_swc_out,
                               &tqsys_tqckefcfil_swc_out /* BIN4 */);

        PFILFAST_Scnd_Out(  copt_nodrivfiltyp_swc_in,
                            englim_tqckdrivfil_swc_in,
                            eng_nckfil_swc_in,
                            ext_stgbxcf_swc_in,
                            tqclrcros_stdetclr_swc_in,
                            tqsys_nogearcorddrivfil_swc_out,
                            tqsys_stdrivfilphait_swc_out,
                            tqsys_tqthdpha3it_swc_out,
                            tqsys_tqckefcfil_swc_out,
                            tqsys_bdeceacvit_swc_out,
                            &tqsys_bacceclrcrossaosit_swc_out,
                            &tqsys_baccedetaosit_swc_out,
                            &tqsys_bacvcllit_swc_out,
                            &tqsys_bclrcrossacce_swc_out,
                            &tqsys_bdecedetaosit_swc_out,
                            &tqsys_buhfrzreq_swc_out,
                            &tqsys_nocylcutauthit_swc_out,
                            &tqsys_titrancllit_swc_out,
                            &tqsys_tqinccllit_swc_out );

        /* IRV OUTPUT */
    }
    else
    {
        tqsys_bdidrivfilreq_swc_out = TqSys_bDiDrivFilReq_B;
        tqsys_nengdeceini_swc_out = TqSys_nEngDeceIni_B;
        tqsys_bacceclrcrossaosit_swc_out = TqSys_bAcceClrCrossAOSIt_B;
        tqsys_baccedetaosit_swc_out = TqSys_bAcceDetAOSIt_B;
        tqsys_bacvcllit_swc_out = TqSys_bAcvCllIt_B;
        tqsys_bclrcrossacce_swc_out = TqSys_bClrCrossAcce_B;
        tqsys_bdeceacvit_swc_out = TqSys_bDeceAcvIt_B;
        tqsys_bdecedetaosit_swc_out = TqSys_bDeceDetAOSIt_B;
        tqsys_buhfrzreq_swc_out = TqSys_bUHFrzReq_B;
        tqsys_ndif_nengntrb_swc_out = TqSys_nDif_nEngNTrb_B;
        tqsys_nocylcutauthit_swc_out = TqSys_noCylCutAuthIt_B;
        tqsys_nogearcorddrivfil_swc_out = TqSys_noGearCordDrivFil_B;
        tqsys_nogeardece_swc_out = TqSys_noGearDece_B;
        tqsys_stdrivfilcfpha_swc_out = TqSys_stDrivFilCfPha_B;
        tqsys_stdrivfilphait_swc_out = TqSys_stDrivFilPhaIt_B;
        tqsys_titrancllit_swc_out = TqSys_tiTranCllIt_B;
        tqsys_tqckdeceiniit_swc_out = TqSys_tqCkDeceIniIt_B;
        tqsys_tqckefcfil_swc_out = TqSys_tqCkEfcFil_B;
        tqsys_tqinccllit_swc_out = TqSys_tqIncCllIt_B;
        tqsys_tqthdpha3it_swc_out = TqSys_tqThdPha3It_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I100(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDiDrivFilReq_TqSys_bDiDrivFilReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdidrivfilreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I101(0) */
    Rte_Write_P_TqSys_nEngDeceIni_TqSys_nEngDeceIni(tqsys_nengdeceini_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I102(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceClrCrossAOSIt_TqSys_bAcceClrCrossAOSIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacceclrcrossaosit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I103(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcceDetAOSIt_TqSys_bAcceDetAOSIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_baccedetaosit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I104(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAcvCllIt_TqSys_bAcvCllIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bacvcllit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I105(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bClrCrossAcce_TqSys_bClrCrossAcce(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bclrcrossacce_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I106(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceAcvIt_TqSys_bDeceAcvIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdeceacvit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I107(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bDeceDetAOSIt_TqSys_bDeceDetAOSIt(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_bdecedetaosit_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I108(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bUHFrzReq_TqSys_bUHFrzReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_buhfrzreq_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I109(0) */
    Rte_Write_P_TqSys_nDif_nEngNTrb_TqSys_nDif_nEngNTrb(tqsys_ndif_nengntrb_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I110(0) */
    Rte_Write_P_TqSys_noCylCutAuthIt_TqSys_noCylCutAuthIt(tqsys_nocylcutauthit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I111(0) */
    Rte_Write_P_TqSys_noGearCordDrivFil_TqSys_noGearCordDrivFil(tqsys_nogearcorddrivfil_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I112(0) */
    Rte_Write_P_TqSys_noGearDece_TqSys_noGearDece(tqsys_nogeardece_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I113(0) */
    Rte_Write_P_TqSys_stDrivFilCfPha_TqSys_stDrivFilCfPha(tqsys_stdrivfilcfpha_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I114(0) */
    Rte_Write_P_TqSys_stDrivFilPhaIt_TqSys_stDrivFilPhaIt(tqsys_stdrivfilphait_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I115(0) */
    Rte_Write_P_TqSys_tiTranCllIt_TqSys_tiTranCllIt(tqsys_titrancllit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I116(0) */
    Rte_Write_P_TqSys_tqCkDeceIniIt_TqSys_tqCkDeceIniIt(tqsys_tqckdeceiniit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I117(0) */
    Rte_Write_P_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(tqsys_tqckefcfil_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I118(0) */
    Rte_Write_P_TqSys_tqIncCllIt_TqSys_tqIncCllIt(tqsys_tqinccllit_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01267-PFilFast.I119(0) */
    Rte_Write_P_TqSys_tqThdPha3It_TqSys_tqThdPha3It(tqsys_tqthdpha3it_swc_out);

}

/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : PFilFast_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) PFilFast_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_PFilFast_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"


/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 14:37:07
* PERL v5.14.2
* Lib_CC 1.34
* Lib_Clipboard 1.01
* Lib_CQ 1.21
* Lib_DD_Check 2.00
* Lib_DD_Check_Checks 1.32
* Lib_DD_Check_Checks 1.34
* Lib_DD_Check_Data 2.01
* Lib_DD_Check_Utils 2.00
* Lib_DD_Compare 1.05
* Lib_DD_GenCode 3.23
* Lib_DD_Load 3.04
* Lib_DD_Load 3.06
* Lib_DD_Structure 1.10
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.02
* Lib_Gui_ComboBox 1.05
* Lib_Gui_Common 1.42
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
* Lib_Gui_Windows 1.15
* Lib_Hash 1.30
* Lib_Log 1.25
* Lib_Pjt 1.30
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.07
* Lib_Scheduler_XML 1.45
* Lib_Spectool_Gen_DD 2.23
* Lib_Twk 1.06
* Lib_Utils 1.05
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.08
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* INPUT_SECTION *
TqSys_PrmCf1_1 ; ;TQSYS ;N/A ;0 ;128 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf1[0] ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf1_2 ; ;TQSYS ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf1[1] ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf1_3 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf1[2] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf1_4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf1[3] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf1_5 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf1[4] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf1_6 ; ;TQSYS ;N/A ;0 ;128 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf1[5] ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf1_1 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf1[0] ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf1_2 ; ;TQSYS ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf1[1] ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf1_3 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf1[2] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf1_4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf1[3] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf1_5 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf1[4] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf1_6 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf1[5] ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_1 ; ;TQSYS ;N/A ;0 ;128 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[0] ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_2 ; ;TQSYS ;N/A ;0 ;2000 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[1] ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_3 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[2] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[3] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_5 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[4] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_PrmCf2_6 ; ;TQSYS ;N/A ;0 ;128 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_PrmCf2[5] ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_1 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[0] ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_2 ; ;TQSYS ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[1] ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_3 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[2] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[3] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_5 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[4] ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facPrmCf2_6 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;TqSys_facPrmCf2[5] ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

* OUTPUT_SECTION *
TqSys_facMinPhaConv ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient minimum de la phase 4 en accélération ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facMinPha3 ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient minimum de la phase 0 en accélération ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur de l’increment de couple correspondant a la rampe 01 (traversee des jeux) ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha6 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 2 d acceleration ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha7 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 3 d acceleration ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainPha ; ;PFILFAST ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 0 d acceleration ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainPha3 ; ;PFILFAST ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 0 d acceleration ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainPha5 ; ;PFILFAST ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 1 d acceleration ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaPha3Cf1 ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Facteur de modulation du filtrage pour la phase 3 en configuration 1 ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaPha3Cf2 ; ;TQSYS ;N/A ;0 ;3 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Facteur de modulation du filtrage pour la phase 3 en configuration 2 (point de mesure) ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_idxTqAccuY_A ;1{t_pfilfast_idxtqaccuy_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [1 2 3 4 5 6 7 8 9 10] ; Indice de précision  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGear_A ;1{t_pfilfast_nogear_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [0 1 2 3 4 5 6] ; Vecteur de rapport de boite  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccP_A ;1{t_pfilfast_raccp_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [0 10 20 30 40 50 60 70 80 100] ; Vecteur de position pedale  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng1_A ;1{t_pfilfast_neng1_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [800 1000 1250 1500 2000 2500 3000 4000] ; Vecteur de régime moteur  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng3_A ;1{t_pfilfast_neng3_a}PFILFAST_12_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [700 800 1000 1250 1500 1750 2000 2500 3000 3500 4000 4500] ; Vecteur de régime moteur  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng_A ;1{t_pfilfast_neng_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [800 1000 1200 1400 1600 1800 2000 2500 3000 3500] ; Vecteur de regime moteur  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqFil_A ;1{t_pfilfast_tqfil_a}PFILFAST_12_SIZE ;PFILFAST ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [0 20 40 60 80 100 120 140 160 180 200 220] ; Vecteur du couple filtré  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tCo1_A ;1{t_pfilfast_tco1_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ; [-20 -10 0 20 40 60 80 100] ; Vecteur de température d'eau  ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

* LOCAL_SECTION *
CoCha_bInhEGR_B ;["FALSE"|"TRUE"] ;COCHA ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoCha_bInhEGR ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_bRstAOS_B ;["FALSE"|"TRUE"] ;COCHA ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoCha_bRstAOS ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_bTqAccuReq_B ;["FALSE"|"TRUE"] ;COCHA ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoCha_bTqAccuReq ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_bTqDynReq_B ;["FALSE"|"TRUE"] ;COCHA ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoCha_bTqDynReq ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_bTqReqASR_B ;["FALSE"|"TRUE"] ;COCHA ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoCha_bTqReqASR ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_bTqReqMSR_B ;["FALSE"|"TRUE"] ;COCHA ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de CoCha_bTqReqMSR ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_tqEfcLim_B ; ;COCHA ;N.m ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de CoCha_tqEfcLim ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_tqEfcLimTqMaxDyn_B ; ;COCHA ;N.m ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de CoCha_tqEfcLimTqMaxDyn ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoCha_tqEfcReq_B ; ;COCHA ;N.m ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de CoCha_tqEfcReq ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcceClrCrossAOSIt_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bAcceClrCrossAOSIt ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcceDetAOSIt_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bAcceDetAOSIt ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvCllIt_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bAcvCllIt ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bClrCrossAcce_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bClrCrossAcce ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceAcvIt_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bDeceAcvIt ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceDetAOSIt_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bDeceDetAOSIt ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDiDrivFilReq_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bDiDrivFilReq ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bUHFrzReq_B ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Bypass de TqSys_bUHFrzReq ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facMinPha3_C ; ;TQSYS ;N/A ;0.1 ;1 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.2 ; Valeur minimum du coefficient de la phase 3 en accélération  ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facMinPhaConv_C ; ;TQSYS ;N/A ;0.1 ;1 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.1 ; Valeur minimum du coefficient de la phase de convergence sur le couple conducteur en accélération  ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaPha3Cf1_C ; ;TQSYS ;N/A ;0 ;2 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;1 ; Pondération supplémentaire pour la phase 3 en accélération en configurations 1  ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facScaPha3Cf2_C ; ;TQSYS ;N/A ;0 ;2 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;1 ; Pondération supplémentaire pour la phase 3 en accélération en configurations 2  ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nDif_nEngNTrb_B ; ;TQS ;rpm ;-8000 ;8000 ;0.25 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_nDif_nEngNTrb ;["YES"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEngDeceIni_B ; ;TQS ;rpm ;0 ;8000 ;0.25 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0;Bypass de TqSys_nEngDeceIni ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noCylCutAuthIt_B ; ;TQS ;N/A ;-1 ;6 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_noCylCutAuthIt ;["YES"] ;SInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil_B ; ;TQS ;N/A ;0 ;6 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_noGearCordDrivFil ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearDece_B ; ;TQS ;N/A ;0 ;6 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_noGearDece ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_stDrivFilCfPha_B ;["CONF_0"*0*|"CONF_1"*1*|"CONF_2"*2*|"CONF_3"*3*|"CONF_4"*4*] ;TQS ;N/A ;0 ;4 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;CONF_0 ;Bypass de TqSys_stDrivFilCfPha ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_stDrivFilPhaIt_B ;["FILTRAGE_DESACTIVE"*0*|"FILTRAGE_INACTIF"*1*|"FILTRAGE_EN_ACCEL_POUR_LA_ZONE_2_SAUT_DEBUE_DU_FILTRAGE"*2*|"FILTRAGE_EN_ACCEL_POUR_LA_ZONE_3_1ER_ORDRE"*3*|"FILTRAGE_EN_ACCEL_POUR_LA_ZONE_4_PENTE_DE_TRAVERSEE_DES_JEUX"*4*|"FILTRAGE_EN_ACCEL_ZONE_5_FORME_PARABOLIQUE"*5*|"FILTRAGE_EN_ACCEL_ZONE_6_LIMITATION_DE_LA_PARABOLE"*6*|"FILTRAGE_EN_ACCEL_ZONE_7_PENTE_AU_DESSUS_DES_JEUX"*7*|"FILTRAGE_EN_DECEL_ZONE_8_SAUT_DE_DEBUT_DE_FILTRAGE"*8*|"FILTRAGE_EN_DECEL_ZONE_9_PREMIERE_PENTE"*9*|"FILTRAGE_EN_DECEL_ZONE_10_2ND_PENTE_POUR_LA_TRAVERSEE_DES_JEUX"*10*|"FILTRAGE_EN_DECEL_ZONE_11_3EME_PENTE"*11*|"RESERVE_12"*12*|"RESERVE_13"*13*|"RESERVE_14"*14*|"RESERVE_15"*15*] ;TQS ;N/A ;0 ;15 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FILTRAGE_DESACTIVE ;Bypass de TqSys_stDrivFilPhaIt ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiTranCllIt_B ; ;TQS ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tiTranCllIt ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDeceIniIt_B ; ;TQS ;N.m ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqCkDeceIniIt ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEfcFil_B ; ;TQS ;N.m ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqCkEfcFil ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIncCllIt_B ; ;TQS ;N.m/s ;0 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqIncCllIt ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3It_B ; ;TQS ;N.m ;-2000 ;2000 ;0.0625 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Bypass de TqSys_tqThdPha3It ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_ACTIVE_BYP_C ;["FALSE"*0*|"TRUE"*1*] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;"FALSE" ; Bypass  ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFilFast_ModuleVersion_Major_MP ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["COMP"] ;["N/A"] ;N/A ;N/A ;N/A ;14 ; PFilFast_ModuleVersion_Major_MP  ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFilFast_ModuleVersion_Minor_MP ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["COMP"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ; PFilFast_ModuleVersion_Minor_MP  ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_idxtqaccuy_a ; ;PFILFAST ;N/A ;1 ;10 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_idxTqAccuY_A  ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng1_a ; ;PFILFAST ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_nEng1_A  ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng3_a ; ;PFILFAST ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_nEng3_A  ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng_a ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_nEng_A  ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_nogear_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_noGear_A  ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_raccp_a ; ;PFILFAST ;% ;0 ;100 ;1/128 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_rAccP_A  ;["NO"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tco1_a ; ;PFILFAST ;deg C ;-40 ;214 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_tCo1_A  ;["NO"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqfil_a ; ;PFILFAST ;Nm ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ; Type for axis TqSys_tqFil_A  ;["NO"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_10_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ; 10 size for map  ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_12_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;12 ; 12 size for map  ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_7_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;7 ; 7 size for map  ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_8_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;8 ; 8 size for map  ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Data_Dictionary */

