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
* Ref X:\integration_view_00PSASWC_EB22D11\blois_psa_sstg\Software\Appli\CurDrivFil\src\CurDrivFil.c
* Version int :/main/00PSASWC_EB/7 Date: 23/7/2013 15 h 42 m User:posmyk 
*    TWK_model:NO_MODEL
*    comments :CurDrivFil 12.2
* Version dev :\main\branch_lemort_e6_dev\2 Date: 18/7/2013 14 h 24 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :CurDrivFil 12.2
* Version dev :\main\branch_lemort_e6_dev\1 Date: 18/7/2013 11 h 47 m User:lemort
*    TWK_model:NO_MODEL
*    comments :CurDrivFil 12.2 : correct FDS A0208449
* Version int :/main/00PSASWC_EB/6 Date: 12/12/2012 17 h 3 m User:meme
*    TWK_model:NO_MODEL
*    comments :regen for CurDrivFil 12.1. correct FDS A0206816 / ALTIS 1786257
* Version dev :\main\branch_lemort_thr_dev\1 Date: 12/12/2012 15 h 42 m User:lemort
*    TWK_model:NO_MODEL
*    comments :regen for CurDrivFil 12.1. correct FDS A0206816 / ALTIS 1786257
* Version int :/main/00PSASWC_EB/5 Date: 19/11/2012 12 h 20 m User:posmyk
*    TWK_model:NO_MODEL
*    comments :dev curdrivfil 12.0
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\3 Date: 16/11/2012 11 h 59 m User:halouane
*    TWK_model:NO_MODEL
*    comments :dev curdrivfil 12.0
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\2 Date: 29/10/2012 11 h 55 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For CurDrivfil_12_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\1 Date: 26/10/2012 10 h 18 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil_12_0_e6
* Version int :/main/00PSASWC_EB/4 Date: 7/6/2012 16 h 56 m User:meme
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil_11_0_e6
* Version dev :\main\branch_halouane_curdrivfil_euro6_dev\1 Date: 4/6/2012 16 h 53 m User:halouane
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil_11_0_e6
* Version int :/main/00PSASWC_EB/3 Date: 18/5/2011 17 h 27 m User:esnault
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.2, Change minor version
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 12/5/2011 14 h 53 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.2, Change minor version
* Version int :/main/00PSASWC_EB/2 Date: 21/12/2010 16 h 3 m User:meme
*    TWK_model:NO_MODEL
*    comments :Update for CurDrivFil 10.1
* Version dev :\main\branch_moisan_module_dev\1 Date: 21/12/2010 15 h 32 m User:moisan
*    TWK_model:NO_MODEL
*    comments :Update for CurDrivFil 10.1
* Version int :/main/00PSASWC_EB/1 Date: 27/8/2010 10 h 47 m User:meme
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 21/7/2010 11 h 14 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil 10.0 Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 9/7/2010 12 h 48 m User:veillard
*    TWK_model:NO_MODEL
*    comments :For CurDrivFil Euro-6
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CurDrivFil.h"

/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if CURDRIVFIL_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
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

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
/* <PRQA_COMMENT><3211> defined here but used in many files </3211></PRQA_COMMENT> */
volatile CONST(UInt8, AUTOMATIC) TqSys_bDisNEngEna_C = DDS_TRUE;
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
*  Software Component Level Map Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
/* <PRQA_COMMENT><3211> defined here but used in many files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_idxGain_A[TQSYS_6_SIZE] = {
(UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0),
(UInt16)(4 * BIN0), (UInt16)(5 * BIN0), (UInt16)(6 * BIN0)
};

volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_AOSGain_A[TQSYS_12_SIZE] = {
(UInt16)(800 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1200 * BIN2),
(UInt16)(1600 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(2400 * BIN2),
(UInt16)(2800 * BIN2), (UInt16)(3200 * BIN2), (UInt16)(3600 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(4400 * BIN2), (UInt16)(4800 * BIN2)
};

/* <PRQA_COMMENT><3211> defined here but used in many files </3211></PRQA_COMMENT> */
volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_AOS_A[TQSYS_9_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(7 * BIN0), (UInt16)(8 * BIN0)
};

/* <PRQA_COMMENT><3211> defined here but used in many files </3211></PRQA_COMMENT> */
volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDeceIni_AOS_A[CURDRIVFIL_5_SIZE] = {
(SInt16)(0 * BIN4),(SInt16)(20 * BIN4),(SInt16)(50 * BIN4),(SInt16)(100 * BIN4),
(SInt16)(150 * BIN4)
};

/* <PRQA_COMMENT><3211> defined here but used in many files </3211></PRQA_COMMENT> */
volatile CONST(SInt16, AUTOMATIC) TqSys_tqLimEM_AOS_A[CURDRIVFIL_5_SIZE] = {
(SInt16)(0 * BIN4),(SInt16)(20 * BIN4),(SInt16)(50 * BIN4),(SInt16)(100 * BIN4),
(SInt16)(150 * BIN4)
};

#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*  Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkAOSCor_B = (SInt16)(0 * BIN4);
#define CURDRIVFIL_STOP_SEC_CALIB_16BIT
#include "CurDrivFil_MemMap.h"

/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqClrCros_bAcvClrCross_B    = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqClrCros_stDetClr_B        = (UInt8)CURDRIVFIL_DETECTION_INACTIF;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAOSAcv_B             = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bInjCutDynReq_B       = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_noCylCutAuthCord_B    = (UInt8)(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) CURDRIVFIL_ACTIVE_BYP_C     = DDS_FALSE;
#define CURDRIVFIL_STOP_SEC_CALIB_8BIT
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/


/* 8-bits scalar calibration definition */
#define CURDRIVFIL_START_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_AOSGain_T
[TQSYS_12_SIZE] = {
(UInt16)(800 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1200 * BIN2),
(UInt16)(1600 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(2400 * BIN2),
(UInt16)(2800 * BIN2), (UInt16)(3200 * BIN2), (UInt16)(3600 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(4400 * BIN2), (UInt16)(4800 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_prm_AOSConf3_B
[TQSYS_6_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10)

};

#define CURDRIVFIL_STOP_SEC_CARTO_16BIT
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define CURDRIVFIL_START_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) tqsys_neng_aosgain_t_sav;
#define CURDRIVFIL_STOP_SEC_VAR_UNSPECIFIED
#include "CurDrivFil_MemMap.h"



/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variables definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"
/* irv to put displayable */

_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_stAcceAOS_irv_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAOSSlopAcv_irv_MP;
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CurDrivFil_MemMap.h"

/* 16-bits variables definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
/* irv to put displayable */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facCorGlbl_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facCorIdlPha_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facCorOxCHeatPha_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facSpd0AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facSpd1AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facTq0AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facTq1AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facTq2AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_facTq3AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nFil2AOS_irv_MP;
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkFilRawAOS_irv_MP;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_ctIncAcvAOS_irv_MP;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_ctIncDiAOS_irv_MP;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_ctOfsAcvAOS_irv_MP;

#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CONST_VERSION_MODULE_8BIT
#include "CurDrivFil_MemMap.h"
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) CurDriv_ModuleVersion_Major_MP = (UInt8)12;
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) CurDriv_ModuleVersion_Minor_MP = (UInt8)2;
#define CURDRIVFIL_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*  Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* Complex constant definition */
#define CURDRIVFIL_START_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"
/* <PRQA_COMMENT><3211> defined here but used in many files </3211></PRQA_COMMENT> */
CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) TQSYS_NENG_AOSGAIN_T_APM = {
&tqsys_neng_aosgain_t_sav,
TQSYS_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_AOSGain_T[0]
};
#define CURDRIVFIL_STOP_SEC_CONST_UNSPECIFIED
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Runnables Definition
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    : RE_CurDrivFil_001_MSE
*  Event            : on ECU power on
*  Description      : Call initialisation functions
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_CurDrivFil_001_MSE(void)
{

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqclrcros_bacvclrcross_swc_out;
    UInt8 tqclrcros_stdetclr_swc_out;
    UInt8 tqsys_nocylcutauthcord_swc_out;
    UInt8 tqsys_binjcutdynreq_swc_out;
    UInt8 tqsys_baosacv_swc_out;
    SInt16 tqsys_tqckaoscor_swc_out;
    t_CurDrivFil_Tab6_S16 tqsys_prm_aosconf3_swc_out;



    CURDRIVFIL_Accel_State_Init(&TqSys_stAcceAOS_irv_MP,                /* 2433 */
                                tqsys_prm_aosconf3_swc_out);

    CURDRIVFIL_Curatif_Param_Init(&TqSys_bAOSSlopAcv_irv_MP,    /* 1958 */
                                &TqSys_ctIncAcvAOS_irv_MP,
                                &TqSys_ctIncDiAOS_irv_MP,
                                &TqSys_ctOfsAcvAOS_irv_MP,
                                  &TqSys_facCorGlbl_irv_MP,
                                  &TqSys_facCorIdlPha_irv_MP,
                                  &TqSys_facCorOxCHeatPha_irv_MP,
                                  &TqSys_facSpd0AOS_irv_MP,
                                  &TqSys_facSpd1AOS_irv_MP,
                                  &TqSys_facTq0AOS_irv_MP,
                                  &TqSys_facTq1AOS_irv_MP,
                                  &TqSys_facTq2AOS_irv_MP,
                                  &TqSys_facTq3AOS_irv_MP);


    CURDRIVFIL_Aos_Func_Agr_Init(&TqSys_nFil2AOS_irv_MP,                /* 2095 */
                                 &TqSys_tqCkFilRawAOS_irv_MP);


    CURDRIVFIL_Final_Curat_Corr_Init(&tqsys_baosacv_swc_out,                /* 2089 */
                                     &tqsys_tqckaoscor_swc_out);


    CURDRIVFIL_Coor_Cut_Dyn_Sel_Init(&tqsys_binjcutdynreq_swc_out,      /* 936 */
                                     &tqsys_nocylcutauthcord_swc_out);


    CURDRIVFIL_Detect_Clr_Cross_Init(&tqclrcros_bacvclrcross_swc_out,   /* 934 */
                                     &tqclrcros_stdetclr_swc_out);

        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I400(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_nFil2AOS_irv(TqSys_nFil2AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I401(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_tqCkFilRawAOS_irv(TqSys_tqCkFilRawAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I403(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facCorGlbl_irv(TqSys_facCorGlbl_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I404(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facCorIdlPha_irv(TqSys_facCorIdlPha_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I405(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facCorOxCHeatPha_irv(TqSys_facCorOxCHeatPha_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I406(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facSpd0AOS_irv(TqSys_facSpd0AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I407(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facSpd1AOS_irv(TqSys_facSpd1AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I408(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facTq0AOS_irv(TqSys_facTq0AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I409(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facTq1AOS_irv(TqSys_facTq1AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I410(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facTq2AOS_irv(TqSys_facTq2AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I411(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_facTq3AOS_irv(TqSys_facTq3AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I414(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_stAcceAOS_irv(TqSys_stAcceAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I415(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_bAOSSlopAcv_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqSys_bAOSSlopAcv_irv_MP));
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I416(1) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_ctIncAcvAOS_irv(TqSys_ctIncAcvAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I417(0) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_ctIncDiAOS_irv(TqSys_ctIncDiAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I418(0) */
        Rte_IrvWrite_RE_CurDrivFil_001_MSE_TqSys_ctOfsAcvAOS_irv(TqSys_ctOfsAcvAOS_irv_MP);

        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I127(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_Write_P_TqClrCros_bAcvClrCross_TqClrCros_bAcvClrCross(DDS_M_CONVERT_UINT8_TO_BOOL(tqclrcros_bacvclrcross_swc_out));
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I128(0) */
        Rte_Write_P_TqClrCros_stDetClr_TqClrCros_stDetClr(tqclrcros_stdetclr_swc_out);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I131(1) */
        Rte_Write_P_TqSys_noCylCutAuthCord_TqSys_noCylCutAuthCord(tqsys_nocylcutauthcord_swc_out);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I132(1) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_Write_P_TqSys_bInjCutDynReq_TqSys_bInjCutDynReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_binjcutdynreq_swc_out));
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I145(1) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_Write_P_TqSys_bAOSAcv_TqSys_bAOSAcv(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_baosacv_swc_out));
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I146(1) */
        Rte_Write_P_TqSys_tqCkAOSCor_TqSys_tqCkAOSCor(tqsys_tqckaoscor_swc_out);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I413(2) */
        Rte_Write_P_TqSys_prm_AOSConf3_TqSys_prm_AOSConf3(tqsys_prm_aosconf3_swc_out);


}
/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_AOS
*  Event            :
*  Description      : 2095
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_AOS(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 ext_nengclc0_swc_in;
    UInt16 ext_nengclc1_swc_in;
    /* IRV */
    SInt16 tqsys_facspd0aos_irv_in;
    SInt16 tqsys_facspd1aos_irv_in;
    SInt16 tqsys_factq0aos_irv_in;
    SInt16 tqsys_factq1aos_irv_in;
    SInt16 tqsys_factq2aos_irv_in;
    SInt16 tqsys_factq3aos_irv_in;

    if ((UInt32)DDS_FALSE == (UInt32)CURDRIVFIL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I102(0) */
        Rte_Read_R_Ext_nEngClc0_Ext_nEngClc0(&ext_nengclc0_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I103(0) */
        Rte_Read_R_Ext_nEngClc1_Ext_nEngClc1(&ext_nengclc1_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I406(0) */
        tqsys_facspd0aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_AOS_TqSys_facSpd0AOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I407(0) */
        tqsys_facspd1aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_AOS_TqSys_facSpd1AOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I408(0) */
        tqsys_factq0aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_AOS_TqSys_facTq0AOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I409(0) */
        tqsys_factq1aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_AOS_TqSys_facTq1AOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I410(0) */
        tqsys_factq2aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_AOS_TqSys_facTq2AOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I411(0) */
        tqsys_factq3aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_AOS_TqSys_facTq3AOS_irv();



        CURDRIVFIL_Aos_Func_Agr(ext_nengclc0_swc_in, /* BIN2 */
                                ext_nengclc1_swc_in, /* BIN2 */
                                tqsys_facspd0aos_irv_in, /* BIN10 */
                                tqsys_facspd1aos_irv_in, /* BIN10 */
                                tqsys_factq0aos_irv_in, /* BIN10 */
                                tqsys_factq1aos_irv_in, /* BIN10 */
                                tqsys_factq2aos_irv_in, /* BIN10 */
                                tqsys_factq3aos_irv_in, /* BIN10 */
                                &TqSys_nFil2AOS_irv_MP, /* BIN2 */
                                &TqSys_tqCkFilRawAOS_irv_MP /* BIN4 */);


        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I400(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_AOS_TqSys_nFil2AOS_irv(TqSys_nFil2AOS_irv_MP);
        /* SSTG_REQ_TAG: SInt16 */
        Rte_IrvWrite_RE_TqSys_EveSync_AOS_TqSys_tqCkFilRawAOS_irv(TqSys_tqCkFilRawAOS_irv_MP);
    }
    else
    {
        /* Do nothing */
    }

    /* OUTPUT */

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_CurCor
*  Event            :
*  Description      : 2089
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_CurCor(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 copt_facantijerk_swc_in;
    UInt8 ext_stgbxcf_swc_in;
    UInt16 ext_nengclc0_swc_in;
    SInt16 copt_tqidcreqcord_nregreq_swc_in;
    SInt16 tqsys_tqckidlcord_swc_in;
    SInt16 tqsys_tqckdeceini_swc_in;
    SInt16 ext_tcomes_swc_in;
    UInt8 ext_titdc_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    Boolean tqsys_brstaos_swc_in;
    SInt16 tqlimem_tqlimemtrv_swc_in;
    SInt16 tqsys_tqckenglimcord_swc_in;

    /* FIM (FRM) */
    Boolean frm_binhaos_fim_in;

    Boolean curdrivfil_bool_temp;

    /* IRV */
    SInt16 tqsys_nfil2aos_irv_in;
    SInt16 tqsys_tqckfilrawaos_irv_in;
    SInt16 tqsys_faccorglbl_irv_in;
    SInt16 tqsys_faccoridlpha_irv_in;
    SInt16 tqsys_faccoroxcheatpha_irv_in;
    UInt8  tqsys_stacceaos_irv_in;
    Boolean tqsys_baosslopacv_irv_in;
    UInt16 tqsys_ctincacvaos_irv_in;
    UInt16 tqsys_ctincdiaos_irv_in;
    UInt16 tqsys_ctofsacvaos_irv_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqsys_baosacv_swc_out;
    SInt16 tqsys_tqckaoscor_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)CURDRIVFIL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I100(0) */
        Rte_Read_R_CoPt_facAntiJerk_CoPt_facAntiJerk(&copt_facantijerk_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I107(1) */
        Rte_Read_R_TqSys_tqCkEngLimCord_TqSys_tqCkEngLimCord(&tqsys_tqckenglimcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I101(0) */
        Rte_Read_R_Ext_stGBxCf_Ext_stGBxCf(&ext_stgbxcf_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I102(0) */
        Rte_Read_R_Ext_nEngClc0_Ext_nEngClc0(&ext_nengclc0_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I105(0) */
        Rte_Read_R_CoPt_tqIdcReqCord_nRegReq_CoPt_tqIdcReqCord_nRegReq(&copt_tqidcreqcord_nregreq_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I106(0) */
        Rte_Read_R_TqSys_tqCkIdlCord_TqSys_tqCkIdlCord(&tqsys_tqckidlcord_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I108(0) */
        Rte_Read_R_TqSys_tqCkDeceIni_TqSys_tqCkDeceIni(&tqsys_tqckdeceini_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I112(0) */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I113(0) */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I119(0) */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I147(0) */

        Rte_Read_R_TqSys_bRstAOS_TqSys_bRstAOS(&tqsys_brstaos_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I155(1) */
        Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&tqlimem_tqlimemtrv_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I500(0) */
        Rte_Call_R_FRM_bInhAOS_GetFunctionPermission(&curdrivfil_bool_temp);
        if((UInt32)curdrivfil_bool_temp == (UInt32)DDS_FALSE)
        {
			frm_binhaos_fim_in = (Boolean)DDS_TRUE;
		}
		else
        {
			frm_binhaos_fim_in = (Boolean)DDS_FALSE;
		}

        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I400(1) */
        tqsys_nfil2aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_nFil2AOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I401(1) */
        tqsys_tqckfilrawaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_tqCkFilRawAOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I403(1) */


        tqsys_faccorglbl_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_facCorGlbl_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I404(1) */
        tqsys_faccoridlpha_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_facCorIdlPha_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I405(1) */
        tqsys_faccoroxcheatpha_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_facCorOxCHeatPha_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I414(1) */
        tqsys_stacceaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_stAcceAOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I415(0) */
        tqsys_baosslopacv_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_bAOSSlopAcv_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I416(1) */
        tqsys_ctincacvaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_ctIncAcvAOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I417(0) */
        tqsys_ctincdiaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_ctIncDiAOS_irv();
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I418(0) */
        tqsys_ctofsacvaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurCor_TqSys_ctOfsAcvAOS_irv();


        CURDRIVFIL_Final_Curat_Corr(
                            copt_facantijerk_swc_in, /* BIN8 */
                            copt_nogearcorddrivfil_swc_in, /* BIN0 */
                            copt_tqidcreqcord_nregreq_swc_in, /* BIN4 */
                            ext_nengclc0_swc_in, /* BIN2 */
                            ext_stgbxcf_swc_in,
                            ext_tcomes_swc_in, /* BIN0 */
                            ext_titdc_swc_in, /* DEC3 */
                            /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhaos_fim_in),
                            tqlimem_tqlimemtrv_swc_in, /* BIN4 */
                             /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_baosslopacv_irv_in),
                            /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                            (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_brstaos_swc_in),
                            tqsys_ctincacvaos_irv_in, /* BIN10 */
                             tqsys_ctincdiaos_irv_in, /* BIN10 */
                             tqsys_ctofsacvaos_irv_in, /* BIN10 */
                             tqsys_faccorglbl_irv_in, /* BIN4 */
                             tqsys_faccoridlpha_irv_in, /* BIN4 */
                             tqsys_faccoroxcheatpha_irv_in, /* BIN4 */
                             tqsys_nfil2aos_irv_in, /* BIN2 */
                             tqsys_stacceaos_irv_in,
                             tqsys_tqckdeceini_swc_in, /* BIN4 */
                             tqsys_tqckenglimcord_swc_in,
                             tqsys_tqckfilrawaos_irv_in, /* BIN4 */
                             tqsys_tqckidlcord_swc_in, /* BIN4 */
                            &tqsys_baosacv_swc_out,
                            &tqsys_tqckaoscor_swc_out); /* BIN4 */



        /* IRV OUTPUT */
    }
    else
    {
        tqsys_baosacv_swc_out = TqSys_bAOSAcv_B;
        tqsys_tqckaoscor_swc_out = TqSys_tqCkAOSCor_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I139(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bAOSAcv_TqSys_bAOSAcv(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_baosacv_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I140(0) */
    Rte_Write_P_TqSys_tqCkAOSCor_TqSys_tqCkAOSCor(tqsys_tqckaoscor_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_CurDrivFil
*  Event            :
*  Description      : 1958
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_CurDrivFil(void)
{
    /* INPUT */
    /* SWC IN */
/* INPUT */
    /* SWC IN */
    UInt16 ext_nengclc0_swc_in;
    UInt16 veh_spdveh_swc_in;
    SInt16 tqsys_tqckdeceini_swc_in;
    Boolean tqsys_bengnonidl_swc_in;
    SInt16 treattdc_nckgrd_swc_in;
    UInt8 ext_titdc_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    UInt16 covsctl_raccpengtrv_swc_in;
    Boolean eom_btwcheatpha_swc_in;
    t_CurDrivFil_Tab6_S16 tqsys_prm_aosconf3_swc_in;

    /* IRV */
    UInt8 tqsys_stacceaos_irv_in;

    if ((UInt32)DDS_FALSE == (UInt32)CURDRIVFIL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I102(0) */
        Rte_Read_R_Ext_nEngClc0_Ext_nEngClc0(&ext_nengclc0_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I104(0) */
        Rte_Read_R_Veh_spdVeh_Veh_spdVeh(&veh_spdveh_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I108(0) */
        Rte_Read_R_TqSys_tqCkDeceIni_TqSys_tqCkDeceIni(&tqsys_tqckdeceini_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I109(0) */
        Rte_Read_R_TqSys_bEngNOnIdl_TqSys_bEngNOnIdl(&tqsys_bengnonidl_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I111(0) */
        Rte_Read_R_TreatTDC_nCkGrd_TreatTDC_nCkGrd(&treattdc_nckgrd_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I113(0) */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I119(0) */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I120(0) */
        Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&covsctl_raccpengtrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I121(0) */
        Rte_Read_R_EOM_bTWCHeatPha_EOM_bTWCHeatPha(&eom_btwcheatpha_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I154(0) */
        Rte_Read_R_TqSys_prm_AOSConf3_TqSys_prm_AOSConf3(tqsys_prm_aosconf3_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I414(0) */
        tqsys_stacceaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurDrivFil_TqSys_stAcceAOS_irv();

        CURDRIVFIL_Curatif_Param(
                                 copt_nogearcorddrivfil_swc_in, /* BIN0 */
                                 covsctl_raccpengtrv_swc_in, /* BIN7 */
                                 /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                 (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(eom_btwcheatpha_swc_in), /*BIN0*/
                                 ext_nengclc0_swc_in, /* BIN2 */
                                 ext_titdc_swc_in, /* DEC3 */
                                 /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                 (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bengnonidl_swc_in),
                                 tqsys_prm_aosconf3_swc_in, /* tab[] bin10 */
                                 tqsys_stacceaos_irv_in,
                                 tqsys_tqckdeceini_swc_in, /* BIN4 */
                                 treattdc_nckgrd_swc_in, /* BIN2 */
                                 veh_spdveh_swc_in, /* BIN7 */
                                &TqSys_bAOSSlopAcv_irv_MP,
                                &TqSys_ctIncAcvAOS_irv_MP, /* BIN10 */
                                &TqSys_ctIncDiAOS_irv_MP, /* BIN10 */
                                &TqSys_ctOfsAcvAOS_irv_MP, /* BIN10 */
                                 &TqSys_facCorGlbl_irv_MP, /* BIN4 */
                                 &TqSys_facCorIdlPha_irv_MP, /* BIN4 */
                                 &TqSys_facCorOxCHeatPha_irv_MP, /* BIN4 */
                                 &TqSys_facSpd0AOS_irv_MP, /* BIN10 */
                                 &TqSys_facSpd1AOS_irv_MP, /* BIN10 */
                                 &TqSys_facTq0AOS_irv_MP, /* BIN10 */
                                 &TqSys_facTq1AOS_irv_MP, /* BIN10 */
                                 &TqSys_facTq2AOS_irv_MP, /* BIN10 */
                                 &TqSys_facTq3AOS_irv_MP /* BIN10 */);


        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I402(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_bAOSSlopAcv_irv(DDS_M_CONVERT_UINT8_TO_BOOL(TqSys_bAOSSlopAcv_irv_MP));
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I403(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_ctIncAcvAOS_irv(TqSys_ctIncAcvAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I403(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_ctIncDiAOS_irv(TqSys_ctIncDiAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I403(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_ctOfsAcvAOS_irv(TqSys_ctOfsAcvAOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I403(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facCorGlbl_irv(TqSys_facCorGlbl_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I404(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facCorIdlPha_irv(TqSys_facCorIdlPha_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I405(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facCorOxCHeatPha_irv(TqSys_facCorOxCHeatPha_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I406(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facSpd0AOS_irv(TqSys_facSpd0AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I407(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facSpd1AOS_irv(TqSys_facSpd1AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I408(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facTq0AOS_irv(TqSys_facTq0AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I409(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facTq1AOS_irv(TqSys_facTq1AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I410(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facTq2AOS_irv(TqSys_facTq2AOS_irv_MP);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I411(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurDrivFil_TqSys_facTq3AOS_irv(TqSys_facTq3AOS_irv_MP);

    }
    else
    {
        /* Do nothing */
    }

    /* OUTPUT */

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_CurStCalc
*  Event            :
*  Description      : 2433
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_CurStCalc(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 ext_nengclc0_swc_in;
    SInt16 tqsys_tqckdeceini_swc_in;
    UInt8 ext_titdc_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    Boolean tqsys_bacceclrcrossaos_swc_in;
    Boolean tqsys_baccedetaos_swc_in;
    Boolean tqsys_bdecedetaos_swc_in;
    SInt16 tqsys_tqckefcfiltrv_swc_in;
    SInt16 tqsys_tqthdpha3_swc_in;
    SInt16 tqlimem_tqlimemtrv_swc_in;
    UInt8 tqclrcros_stdetclr_swc_in;
    SInt16 tqsys_tqckaoscor_swc_in;

    /* SWC OUT */
    t_CurDrivFil_Tab6_S16 tqsys_prm_aosconf3_swc_out;

    /* IRV */
    SInt16 tqsys_nfil2aos_irv_in;

    UInt32 i;

    if ((UInt32)DDS_FALSE == (UInt32)CURDRIVFIL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I102(0) */
        Rte_Read_R_Ext_nEngClc0_Ext_nEngClc0(&ext_nengclc0_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I108(0) */
        Rte_Read_R_TqSys_tqCkDeceIni_TqSys_tqCkDeceIni(&tqsys_tqckdeceini_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I113(0) */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I119(0) */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I124(0) */
        Rte_Read_R_TqSys_bAcceClrCrossAOS_TqSys_bAcceClrCrossAOS(&tqsys_bacceclrcrossaos_swc_in);

        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I125(0) */
        Rte_Read_R_TqSys_bAcceDetAOS_TqSys_bAcceDetAOS(&tqsys_baccedetaos_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I126(0) */

        Rte_Read_R_TqSys_bDeceDetAOS_TqSys_bDeceDetAOS(&tqsys_bdecedetaos_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I129(0) */
        Rte_Read_R_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(&tqsys_tqckefcfiltrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I130(0) */
        Rte_Read_R_TqSys_tqThdPha3_TqSys_tqThdPha3(&tqsys_tqthdpha3_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I155(1) */
        Rte_Read_R_TqLimEM_tqLimEMTrv_TqLimEM_tqLimEMTrv(&tqlimem_tqlimemtrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I156(0) */
        Rte_Read_R_TqClrCros_stDetClr_TqClrCros_stDetClr(&tqclrcros_stdetclr_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I157(0) */
        Rte_Read_R_TqSys_tqCkAOSCor_TqSys_tqCkAOSCor(&tqsys_tqckaoscor_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I400(1) */
        tqsys_nfil2aos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CurStCalc_TqSys_nFil2AOS_irv();


        CURDRIVFIL_Accel_State(copt_nogearcorddrivfil_swc_in, /* BIN0 */
                               ext_nengclc0_swc_in, /* BIN2 */
                               ext_titdc_swc_in, /* DEC3 */
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bacceclrcrossaos_swc_in),
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_baccedetaos_swc_in),
                               /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                               (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqsys_bdecedetaos_swc_in),
                               tqsys_nfil2aos_irv_in, /* BIN2 */
                               tqclrcros_stdetclr_swc_in, /*BIN0*/
                               tqlimem_tqlimemtrv_swc_in, /*BIN4*/
                               tqsys_tqckaoscor_swc_in, /*BIN4*/
                               tqsys_tqckdeceini_swc_in, /*BIN4*/
                               tqsys_tqckefcfiltrv_swc_in, /*BIN4*/
                               tqsys_tqthdpha3_swc_in, /*BIN4*/
                               &TqSys_stAcceAOS_irv_MP,
                               tqsys_prm_aosconf3_swc_out);

        /* IRV OUTPUT */
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I414(0) */
        Rte_IrvWrite_RE_TqSys_EveSync_CurStCalc_TqSys_stAcceAOS_irv(TqSys_stAcceAOS_irv_MP);
    }
    else
    {
         for (i=0; i < TQSYS_6_SIZE; i++)
            {
                tqsys_prm_aosconf3_swc_out[i] = TqSys_prm_AOSConf3_B[i];
            }

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I413(2) */
    Rte_Write_P_TqSys_prm_AOSConf3_TqSys_prm_AOSConf3(tqsys_prm_aosconf3_swc_out);

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_CutDyn
*  Event            :
*  Description      : 936
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_CutDyn(void)
{
    /* INPUT */
    /* SWC IN */
    SInt16 tqsys_tqckdeceini_swc_in;
    SInt16 ext_tcomes_swc_in;
    UInt8 ext_titdc_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    UInt16 covsctl_raccpengtrv_swc_in;
    SInt16 tqsys_tqckefcfiltrv_swc_in;
    SInt8 cocha_nocylcutauth_swc_in;
    Boolean copt_binjcutdynauth1_swc_in;
    Boolean copt_binjcutdynauth2_swc_in;
    Boolean copt_binjcutdynauth3_swc_in;
    SInt8 copt_nocylcutauth_swc_in;
    SInt16 copt_tqidccordlimbuf_tqgbx_swc_in;
    UInt16 eng_nckfil_swc_in;
    UInt8 ext_nocyleng_swc_in;
    Boolean tqcll_bforccll_swc_in;
    SInt8 tqsys_nocylcutauth_swc_in;
    /* IRV */
    SInt16 tqsys_tqckfilrawaos_irv_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqsys_nocylcutauthcord_swc_out;
    UInt8 tqsys_binjcutdynreq_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)CURDRIVFIL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I108(0) */
        Rte_Read_R_TqSys_tqCkDeceIni_TqSys_tqCkDeceIni(&tqsys_tqckdeceini_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I112(0) */
        Rte_Read_R_Ext_tCoMes_Ext_tCoMes(&ext_tcomes_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I113(0) */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I114(0) */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I115(0) */
        Rte_Read_R_CoVSCtl_rAccPEngTrv_CoVSCtl_rAccPEngTrv(&covsctl_raccpengtrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I124(0) */
        Rte_Read_R_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(&tqsys_tqckefcfiltrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I128(0) */
        Rte_Read_R_CoCha_noCylCutAuth_CoCha_noCylCutAuth(&cocha_nocylcutauth_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I129(0) */
        Rte_Read_R_CoPt_bInjCutDynAuth1_CoPt_bInjCutDynAuth1(&copt_binjcutdynauth1_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I130(0) */
        Rte_Read_R_CoPt_bInjCutDynAuth2_CoPt_bInjCutDynAuth2(&copt_binjcutdynauth2_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I131(0) */
        Rte_Read_R_CoPt_bInjCutDynAuth3_CoPt_bInjCutDynAuth3(&copt_binjcutdynauth3_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I132(0) */
        Rte_Read_R_CoPt_noCylCutAuth_CoPt_noCylCutAuth(&copt_nocylcutauth_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I133(0) */
        Rte_Read_R_CoPt_tqIdcCordLimBuf_tqGBx_CoPt_tqIdcCordLimBuf_tqGBx(&copt_tqidccordlimbuf_tqgbx_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I134(0) */
        Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I135(0) */
        Rte_Read_R_Ext_noCylEng_Ext_noCylEng(&ext_nocyleng_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I136(0) */
        Rte_Read_R_TqCll_bForcCll_TqCll_bForcCll(&tqcll_bforccll_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I138(0) */
        Rte_Read_R_TqSys_noCylCutAuth_TqSys_noCylCutAuth(&tqsys_nocylcutauth_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I401(0) */
        tqsys_tqckfilrawaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_CutDyn_TqSys_tqCkFilRawAOS_irv();


        CURDRIVFIL_Coor_Cut_Dyn_Sel(cocha_nocylcutauth_swc_in, /* BIN0 */
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_binjcutdynauth1_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_binjcutdynauth2_swc_in),
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(copt_binjcutdynauth3_swc_in),
                                    copt_nocylcutauth_swc_in, /* BIN0 */
                                    copt_nogearcorddrivfil_swc_in, /* BIN0 */
                                    copt_tqidccordlimbuf_tqgbx_swc_in, /* BIN4 */
                                    covsctl_raccpengtrv_swc_in, /* BIN7 */
                                    eng_nckfil_swc_in, /* BIN2 */
                                    ext_nocyleng_swc_in, /* BIN0 */
                                    ext_tcomes_swc_in, /* BIN0 */
                                    ext_titdc_swc_in, /* DEC3 */
                                    /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                                    (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(tqcll_bforccll_swc_in),
                                    tqsys_nocylcutauth_swc_in, /* BIN0 */
                                    tqsys_tqckdeceini_swc_in, /* BIN4 */
                                    tqsys_tqckefcfiltrv_swc_in, /* BIN4 */
                                    tqsys_tqckfilrawaos_irv_in, /* BIN4 */
                                    &tqsys_binjcutdynreq_swc_out,
                                    &tqsys_nocylcutauthcord_swc_out /* BIN0 */);



        /* IRV OUTPUT */
    }
    else
    {
        tqsys_nocylcutauthcord_swc_out = TqSys_noCylCutAuthCord_B;
        tqsys_binjcutdynreq_swc_out = TqSys_bInjCutDynReq_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I126(0) */
    Rte_Write_P_TqSys_noCylCutAuthCord_TqSys_noCylCutAuthCord(tqsys_nocylcutauthcord_swc_out);
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I127(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqSys_bInjCutDynReq_TqSys_bInjCutDynReq(DDS_M_CONVERT_UINT8_TO_BOOL(tqsys_binjcutdynreq_swc_out));

}

/*******************************************************************************
*
*  Runnable Name    : RE_TqSys_EveSync_TqClrCros
*  Event            :
*  Description      : 934
*
*******************************************************************************/

FUNC(void, AUTOMATIC) RE_TqSys_EveSync_TqClrCros(void)
{
    /* INPUT */
    /* SWC IN */
    UInt16 ext_nengclc0_swc_in;
    UInt16 ext_nengclc1_swc_in;
    UInt8 ext_titdc_swc_in;
    UInt8 copt_nogearcorddrivfil_swc_in;
    SInt16 tqsys_tqckefcfiltrv_swc_in;
    SInt16 tqsys_tqthdpha3_swc_in;
    /* IRV */
    SInt16 tqsys_tqckfilrawaos_irv_in;

    /* OUTPUT */
    /* SWC OUT */
    UInt8 tqclrcros_bacvclrcross_swc_out;
    UInt8 tqclrcros_stdetclr_swc_out;

    if ((UInt32)DDS_FALSE == (UInt32)CURDRIVFIL_ACTIVE_BYP_C)
    {
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I102(0) */
        Rte_Read_R_Ext_nEngClc0_Ext_nEngClc0(&ext_nengclc0_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I103(0) */
        Rte_Read_R_Ext_nEngClc1_Ext_nEngClc1(&ext_nengclc1_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I113(0) */
        Rte_Read_R_Ext_tiTDC_Ext_tiTDC(&ext_titdc_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I114(0) */
        Rte_Read_R_CoPt_noGearCordDrivFil_CoPt_noGearCordDrivFil(&copt_nogearcorddrivfil_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I124(0) */
        Rte_Read_R_TqSys_tqCkEfcFilTrv_TqSys_tqCkEfcFilTrv(&tqsys_tqckefcfiltrv_swc_in);
        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I125(0) */
        Rte_Read_R_TqSys_tqThdPha3_TqSys_tqThdPha3(&tqsys_tqthdpha3_swc_in);


        /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I401(0) */
        tqsys_tqckfilrawaos_irv_in = Rte_IrvRead_RE_TqSys_EveSync_TqClrCros_TqSys_tqCkFilRawAOS_irv();


        CURDRIVFIL_Detect_Clr_Cross(copt_nogearcorddrivfil_swc_in, /* BIN0 */
                                    ext_nengclc0_swc_in, /* BIN2 */
                                    ext_nengclc1_swc_in, /* BIN2 */
                                    ext_titdc_swc_in, /* DEC3 */
                                    tqsys_tqckefcfiltrv_swc_in, /* BIN4 */
                                    tqsys_tqthdpha3_swc_in, /* BIN4 */
                                    tqsys_tqckfilrawaos_irv_in,
                                    &tqclrcros_bacvclrcross_swc_out,
                                    &tqclrcros_stdetclr_swc_out);



        /* IRV OUTPUT */
    }
    else
    {
        tqclrcros_bacvclrcross_swc_out = TqClrCros_bAcvClrCross_B;
        tqclrcros_stdetclr_swc_out = TqClrCros_stDetClr_B;

    }

    /* OUTPUT */
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I122(0) */
    /* <PRQA_COMMENT><4470><2100> Warning due to tool, conversion is ok </2100></4470></PRQA_COMMENT> */
    Rte_Write_P_TqClrCros_bAcvClrCross_TqClrCros_bAcvClrCross(DDS_M_CONVERT_UINT8_TO_BOOL(tqclrcros_bacvclrcross_swc_out));
    /* SSTG_REQ_TAG: 01552_10_01787-CurDrivFil.I123(0) */
    Rte_Write_P_TqClrCros_stDetClr_TqClrCros_stDetClr(tqclrcros_stdetclr_swc_out);

}

/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : CurDrivFil_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) CurDrivFil_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_CurDrivFil_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define CURDRIVFIL_STOP_SEC_CODE
#include "CurDrivFil_MemMap.h"

