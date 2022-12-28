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
* Ref X:\integration_view_00PSASWC_E414D11\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Ivc_Structure.c
* Version int :/main/L02_03/1 Date: 14/3/2013 12 h 7 m User:meme 
*    TWK_model:TQDEM_Ivc_Structure_L02_030_IMPL1
*    comments :For TqDem 11.4
* Version dev :\main\branch_thauvin_euro6\2 Date: 11/3/2013 11 h 29 m User:thauvin 
*    TWK_model:TQDEM_Ivc_Structure_L02_030_IMPL1
*    comments :For TqDem 11.4
* Version dev :\main\branch_thauvin_euro6\1 Date: 6/3/2013 9 h 29 m User:thauvin
*    TWK_model:TQDEM_Ivc_Structure_L02_030_IMPL1
*    comments :For TqDem 11.4
*    comments :Update with CSMT_CGMT05_1397_v3_2
* Version int :/main/L02_02/3 Date: 17/7/2012 15 h 48 m User:posmyk
*    TWK_model:TQDEM_Ivc_Structure_L02_021_IMPL1_D
*    comments :add INLINE for TqDem 11.3
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 11/7/2012 11 h 15 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_021_IMPL1_D
*    comments :add INLINE for TqDem 11.3
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 13 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_021_IMPL1_D
*    comments :add INLINE for static functions
* Version int :/main/L02_02/2 Date: 15/9/2011 10 h 20 m User:meme
*    TWK_model:TQDEM_Ivc_Structure_L02_021_IMPL1
*    comments :Correct FDS A0202653
* Version dev :\main\branch_moisan_module_dev\1 Date: 12/9/2011 11 h 56 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L02_021_IMPL1
*    comments :Correct FDS A0202653
* Version int :/main/L02_02/1 Date: 13/1/2011 14 h 48 m User:meme
*    TWK_model:TQDEM_Ivc_Structure_L02_020_IMPL2
*    comments :For TqDem 11.0.. Spec CSMT_CGMT05_1397_v3_1. correction following TU
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 12/1/2011 15 h 11 m User:demezil
*    TWK_model:TQDEM_Ivc_Structure_L02_020_IMPL2
*    comments :For TqDem 11.0.
*    comments :Spec CSMT_CGMT05_1397_v3_1
*    comments :correction following TU
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 4/1/2011 12 h 21 m User:demezil
*    TWK_model:TQDEM_Ivc_Structure_L02_020_IMPL1
*    comments :For TqDem 11.0.. Spec CSMT_CGMT05_1397_v3_1
* Version int :/main/L02_01/2 Date: 8/10/2010 16 h 32 m User:meme
*    TWK_model:TQDEM_Ivc_Structure_L02_011_IMPL1
*    comments :Fail Code
* Version dev :\main\branch_salmane_tqdem_e6_dev\3 Date: 30/9/2010 14 h 17 m User:salmane
*    TWK_model:TQDEM_Ivc_Structure_L02_011_IMPL1
*    comments :Fail Code
* Version dev :\main\branch_salmane_tqdem_e6_dev\2 Date: 22/9/2010 9 h 59 m User:salmane
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1_D
*    comments :Fail CODE
* Version int :/main/L02_01/1 Date: 1/9/2010 14 h 7 m User:esnault
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\5 Date: 12/8/2010 10 h 7 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\4 Date: 30/7/2010 16 h 24 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :for debug
* Version dev :\main\branch_lemort_dev_tqdem\3 Date: 30/7/2010 15 h 55 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :implementation of PSA demand on remark_tracking_sheet
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 26/7/2010 17 h 2 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_salmane_tqdem_e6_dev\1 Date: 9/7/2010 15 h 41 m User:salmane
*    TWK_model:TQDEM_Ivc_Structure_L02_010_IMPL1
*    comments :Update for TqDem 1.0 Euro6
* Version int :/main/L01_02/1 Date: 16/9/2009 10 h 45 m User:langendorf
*    TWK_model:TQDEM_Ivc_Structure_L01_020_IMPL2
*    comments :Correct fail code for TqDem 2.0
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 9/9/2009 10 h 27 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_020_IMPL2
*    comments :Correct fail code for TqDem 2.0
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 2/9/2009 15 h 32 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_020_IMPL1
*    comments :Correct wrong initialisation
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 28/8/2009 15 h 41 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_020_IMPL1
*    comments :First issue for TqDem 2.0: new specification CSMT_CGMT05_1397 2.2
* Version int :/main/L01_01/4 Date: 3/12/2008 19 h 8 m User:boucher
*    TWK_model:TQDEM_Ivc_Structure_L01_011_IMPL1
*    comments :FDS 24803
* Version dev :\main\branch_moisan_tqdem_dev\8 Date: 24/11/2008 14 h 44 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_011_IMPL1
*    comments :FDS 24803
* Version int :/main/L01_01/3 Date: 14/10/2008 16 h 23 m User:langendorf
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL2
*    comments :Error in CSMT_CGMT05_1397.FR.9.0
*    comments :Error in CSMT_CGMT05_1397.FR.9.0
* Version dev :\main\branch_moisan_tqdem_dev\7 Date: 13/10/2008 16 h 25 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL2
*    comments :Error in CSMT_CGMT05_1397.FR.9.0
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 9/10/2008 13 h 12 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL2
*    comments :Correction of Fail test
* Version dev :\main\branch_moisan_tqdem_integ\2 Date: 15/9/2008 16 h 22 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :error with tqdem_stgreen_state default value
* Version dev :\main\branch_moisan_tqdem_integ\1 Date: 15/9/2008 13 h 39 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :Precaution with tempory variable
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 10/9/2008 9 h 39 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :Correction due to Tracking sheet back
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 8/9/2008 10 h 7 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :New QAC warning
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 8/9/2008 9 h 59 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :Tracking sheet file modification
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 5/9/2008 13 h 11 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :Wrong definition of TqDem_noGearHiSpd_C
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 3/9/2008 13 h 15 m User:moisan
*    TWK_model:TQDEM_Ivc_Structure_L01_010_IMPL1
*    comments :First implementation for PSA SSTG TqDem E
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
* File Macro Definitions
*******************************************************************************/

#define TQDEM_NOLDX_SIZE                      7
#define TQDEM_RACCMAX_SIZE                    5
#define TQDEM_RACCMIN_SIZE                    5

/* TqDem_stDrvTakeOff */
#define STDRVTAKEOFF_DECO                    (UInt32)1
#define STDRVTAKEOFF_HORS_DECO               (UInt32)2
#define STDRVTAKEOFF_TRANS_CONV_COUPLE       (UInt32)3
#define STDRVTAKEOFF_ATTENTE                 (UInt32)4
#define STDRVTAKEOFF_TRANS_TEMP_DECO_ROUL    (UInt32)5
#define STDRVTAKEOFF_TRANS_TEMP_ROUL_DECO    (UInt32)6

/* tqdem_stdrivtakeoff_sub_state */
#define TQDEM_DECO1                           (UInt32)1
#define TQDEM_DECO2                           (UInt32)2
#define TQDEM_DECO3                           (UInt32)3

/* TqDem_bRvs */
#define TQDEM_BRVS_MA_NON_ENGAGEE             (UInt32)0
#define TQDEM_BRVS_MA_ENGAGEE                 (UInt32)1

/* CoPt_noEgdGearCord */
#define NOEGDGEARCORD_N                       (UInt32)0
#define NOEGDGEARCORD_R1                      (UInt32)1
#define NOEGDGEARCORD_R2                      (UInt32)2
#define NOEGDGEARCORD_R3                      (UInt32)3
#define NOEGDGEARCORD_R4                      (UInt32)4
#define NOEGDGEARCORD_R5                      (UInt32)5
#define NOEGDGEARCORD_R6                      (UInt32)6
#define NOEGDGEARCORD_MA                      (UInt32)7

/* TqDem_stTqDrvReq */
#define TQDEM_MA                              (UInt32)0
#define TQDEM_BV                              (UInt32)2
#define TQDEM_TRANS_BV_MV                     (UInt32)3
#define TQDEM_MV                              (UInt32)4
#define TQDEM_TRANS_MV_HV                     (UInt32)5
#define TQDEM_HV                              (UInt32)6

/* TqDem_stDrvEcoReq */
#define STGREEN_NON_DEMARRE                   (UInt32)1
#define STGREEN_DEMARRE                       (UInt32)2
#define STGREEN_TRANSITION_TEMPORELLE         (UInt32)3
#define STGREEN_ATTENTE                       (UInt32)4
#define STGREEN_NORMAL                        (UInt32)5

/* TqDem_stStrt */
#define STSTRT_ECU_ETEINT                     (UInt32)1
#define STSTRT_ECU_REVEILLE                   (UInt32)2
#define STSTRT_MOTEUR_DEMARRE                 (UInt32)3
#define STSTRT_MOTEUR_ARRETE_OU_CALE          (UInt32)4
#define STSTRT_ECU_EXTINCTION                 (UInt32)5
#define STSTRT_ECU_EXTINCTION2                (UInt32)6

#define TQDEM_TI_WAITECO_DELTA              (UInt32)(0.01*DEC2)

/* CoPTSt_stEng */
#define STENG_COUPE_CALE                      (UInt32)1
#define STENG_PREPARATION                     (UInt32)2
#define STENG_DRIVEN_START                    (UInt32)3
#define STENG_AUTONOMOUS_START                (UInt32)4
#define STENG_ENGINE_RUNNING                  (UInt32)5
#define STENG_STATE_STOP                      (UInt32)6
#define STENG_DRIVEN_RESTART                  (UInt32)7
#define STENG_AUTONOMOUS_RESTART              (UInt32)8


/* Ext_stGBxCf */
#define TQDEM_BVM                             (UInt32)0
#define TQDEM_BVA                             (UInt32)1
#define TQDEM_BVMP                            (UInt32)2

#define TQDEM_IVC_STRUCTURE_0                 (UInt32)0
#define TQDEM_IVC_STRUCTURE_1                 (UInt32)1
#define TQDEM_IVC_STRUCTURE_2                 (UInt32)2


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

/* 32-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_32BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt32, AUTOMATIC) CoPt_spdVehGearRatDft_C = (CONST(UInt32, AUTOMATIC))(0 * BIN10);
#define TQDEM_STOP_SEC_CALIB_32BIT
#include "TqDem_MemMap.h"

/* 16-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_nCkIdlHys_C = (CONST(UInt16, AUTOMATIC))(20 * BIN0);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPMax_C = (CONST(UInt16, AUTOMATIC))(40 * BIN7);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_rAccPMinEco_C = (CONST(SInt16, AUTOMATIC))(5 * BIN7);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tOxCHiTranNorm_C = (CONST(SInt16, AUTOMATIC))(100 * BIN0);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tOxCLoTranNorm_C = (CONST(SInt16, AUTOMATIC))(50 * BIN0);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tCoMesDft_C = (CONST(SInt16, AUTOMATIC))(90 * BIN0);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tCoThdHiTranNorm_C = (CONST(SInt16, AUTOMATIC))(100 * BIN0);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tCoThdLoTranNorm_C = (CONST(SInt16, AUTOMATIC))(50 * BIN0);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tOxCDft_C = (CONST(SInt16, AUTOMATIC))(500 * BIN0);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcMinEco_C = (CONST(SInt16, AUTOMATIC))(10 * BIN4);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOff_C = (CONST(SInt16, AUTOMATIC))(10 * BIN4);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehDft_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehMaxHiSpdDrv_C = (CONST(UInt16, AUTOMATIC))(90 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehMaxAvrDrv_C = (CONST(UInt16, AUTOMATIC))(50 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehMaxTakeOff_C = (CONST(UInt16, AUTOMATIC))(6 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehMinHiSpdDrv_C = (CONST(UInt16, AUTOMATIC))(75 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehMinAvrDrv_C = (CONST(UInt16, AUTOMATIC))(30 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_spdVehMinTakeOff_C = (CONST(UInt16, AUTOMATIC))(4 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPThdTranNorm_C = (CONST(UInt16, AUTOMATIC))(20 * BIN7);


#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bAcvEcoOn_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bRvsDrvInh_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bRvsTakeOff_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bTakeOffGBx_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bTranDrv_C = DDS_TRUE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bTranStallEco_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bTranTakeOff_C = DDS_TRUE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bTranTiEcoOn_C = DDS_TRUE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_bAcvPtSptGsl_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_facGearFil_C = (CONST(UInt8, AUTOMATIC))(0.5 * BIN7);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_idxPtSpt_C = (CONST(UInt8, AUTOMATIC))(50 * BIN0);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_noGearHiSpd_C = (CONST(UInt8, AUTOMATIC))(3 * BIN0);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_noGearLoSpd_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_noGearAvrSpd_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_stTranNormCf_C = (CONST(UInt8, AUTOMATIC))(1 * BIN0);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiCfmEco_C = (CONST(UInt8, AUTOMATIC))(5 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiEgdGearCfm_C = (CONST(UInt8, AUTOMATIC))(2 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_facFilNEngTraCls_C = (CONST(UInt8, AUTOMATIC))(0.3 * BIN7);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_facFilNEngTraOp_C = (CONST(UInt8, AUTOMATIC))(1 * BIN7);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiMaxAcvEco_C = (CONST(UInt8, AUTOMATIC))(10 * DEC0);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiMaxTakeOff_C = (CONST(UInt8, AUTOMATIC))(5 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiMinTakeOff_C = (CONST(UInt8, AUTOMATIC))(0.5 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTraTakeOffDownDft_C = (CONST(UInt8, AUTOMATIC))(10 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTraTakeOffDown_C = (CONST(UInt8, AUTOMATIC))(0.5 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTraTakeOffUp_C = (CONST(UInt8, AUTOMATIC))(1 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTranEcoNorm_C = (CONST(UInt8, AUTOMATIC))(5 * DEC1);

_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTranGearRatDftOff_C = (CONST(UInt8, AUTOMATIC))(1 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTranGearRatDftOn_C = (CONST(UInt8, AUTOMATIC))(1 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTranSpdDftOff_C = (CONST(UInt8, AUTOMATIC))(1 * DEC1);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) TqDem_tiTranSpdDftOn_C = (CONST(UInt8, AUTOMATIC))(1 * DEC1);
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQDEM_START_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_idxGearRat_A[TQDEM_NOLDX_SIZE] = {
(UInt16)(0 * BIN8), (UInt16)(8 * BIN8), (UInt16)(16 * BIN8),
(UInt16)(25 * BIN8), (UInt16)(35 * BIN8), (UInt16)(45 * BIN8),
(UInt16)(55 * BIN8)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_idxGearRat_T
[TQDEM_NOLDX_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(2 * BIN7), (UInt16)(2 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(3 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPMaxEco_A[TQDEM_RACCMAX_SIZE] = {
(UInt16)(700 * BIN0), (UInt16)(1000 * BIN0), (UInt16)(1300 * BIN0),
(UInt16)(1500 * BIN0), (UInt16)(1750 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPMaxEco_T
[TQDEM_RACCMAX_SIZE] = {
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7), (UInt16)(40 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(40 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPMin_A[TQDEM_RACCMIN_SIZE] = {
(UInt16)(700 * BIN0), (UInt16)(1000 * BIN0), (UInt16)(1300 * BIN0),
(UInt16)(1500 * BIN0), (UInt16)(1750 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_rAccPMin_T
[TQDEM_RACCMIN_SIZE] = {
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7),
(UInt16)(0.5 * BIN7), (UInt16)(0.5 * BIN7)
};

#define TQDEM_STOP_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQDEM_START_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_idxgearrat_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_raccpmaxeco_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqdem_raccpmin_t_sav;
STATIC VAR(t_dds_m_soft_trans_u32_type, AUTOMATIC) tqdem_vveh_rampe;
STATIC VAR(t_dds_m_soft_trans_u32_type, AUTOMATIC) tqdem_r_vveh_rampe;
STATIC VAR(t_dds_m_soft_trans_u32_type, AUTOMATIC) tqdem_idxgear_rampe;
STATIC VAR(t_dds_m_soft_trans_u32_type, AUTOMATIC) tqdem_rgreen_rampe;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) tqdem_spdveh_hyst;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_tqdem_idxgear;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqdem_idxgear_turn_on;

#define TQDEM_STOP_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"


/* 8-bits variable definition */
#define TQDEM_START_SEC_VAR_8BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqdem_rampe_initialised;       /* Boolean */
STATIC VAR(UInt8, AUTOMATIC) tqdem_rampe_filter_idxgear_initialised;       /* Boolean */
STATIC VAR(UInt8, AUTOMATIC) tqdem_rgreen_rampe_initialised;       /* Boolean */
STATIC VAR(UInt8, AUTOMATIC) tqdem_stdrivtakeoff_sub_state; /* enum */
STATIC VAR(UInt8, AUTOMATIC) tqdem_stdrivtakeoff_state; /* enum */
STATIC VAR(UInt8, AUTOMATIC) tqdem_sttqdrvreq_state; /* enum */
STATIC VAR(UInt8, AUTOMATIC) tqdem_bacvtraneco_prev; /* BIN7 */
STATIC VAR(UInt8, AUTOMATIC) tqdem_stgreen_state; /* enum */

STATIC VAR(UInt8, AUTOMATIC) tqdem_idxmaptrandrvfirst_prev;
STATIC VAR(UInt8, AUTOMATIC) tqdem_idxmaptrandrvsec_prev;
STATIC VAR(UInt8, AUTOMATIC) tqdem_idxmaprvsdrv_prev;
#define TQDEM_STOP_SEC_VAR_8BIT
#include "TqDem_MemMap.h"

/* 32-bits variable definition */
#define TQDEM_START_SEC_VAR_32BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqdem_1ms_u32_time_prev ;
#define TQDEM_STOP_SEC_VAR_32BIT
#include "TqDem_MemMap.h"

/* 16-bits variable definition */
#define TQDEM_START_SEC_VAR_16BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqdem_rdrivtakeoff_prev ;
STATIC VAR(UInt16, AUTOMATIC) tqdem_rtraneconorm_prev;
STATIC VAR(UInt16, AUTOMATIC) tqdem_rtrandrv_prev;
#define TQDEM_STOP_SEC_VAR_16BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_32BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt32, AUTOMATIC) TqDem_spdVehGearRatCord_MP; /* BIN10 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_32BIT
#include "TqDem_MemMap.h"

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facTranLvlDrv; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_idxGear; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_nCkIdlHys; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rTranLoAvrSpd; /* BIN10 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rTranAvrHiSpd; /* BIN10 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rSpdVeh; /* BIN10 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rAccPMax; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rAccPMaxEco; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rAccPMin; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rAccPMinEco; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_rTranEco; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tCoMes; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facTranLoAvrSpdOut; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facTranAvrHiSpdOut; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facTranLoAvrSpdIn; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_facTranAvrHiSpdIn; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiAcvEco; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiMaxAcvEco; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiCfmEco; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiMaxTakeOff; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiMinTakeOff; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiTakeOff; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiTakeOffMax; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_tiWaitEco; /* DEC2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tOxCEstim; /* BIN0 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcMinEco; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqDem_tqCkEfcTakeOff; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVeh; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVehMaxHiSpdDrv; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVehMaxAvrDrv; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVehMaxTakeOff; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVehMinHiSpdDrv; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVehMinAvrDrv; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqDem_spdVehMinTakeOff; /* BIN7 */

#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bAcvTranEco;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bAuthTranNorm;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bRvsDrvInh;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bRvsTakeOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bRvs;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bTakeOffGBx;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bTranDrv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bTranStallEco;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bTranTakeOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_bTranTiEcoOn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_noGearHiSpd; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_noGearLoSpd; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_noGearAvrSpd; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_stDrvTakeOff;
/* <PRQA_COMMENT><3229> Terminator in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_stDrvEcoReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_stStrt;
/* <PRQA_COMMENT><3229> Terminator in specification </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqDem_stTqDrvReq;
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQDEM_START_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_IDXGEARRAT_T_APM = {
&tqdem_idxgearrat_t_sav,
TQDEM_NOLDX_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_idxGearRat_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_idxGearRat_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_RACCPMAXECO_T_APM = {
&tqdem_raccpmaxeco_t_sav,
TQDEM_RACCMAX_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_rAccPMaxEco_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_rAccPMaxEco_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQDEM_RACCPMIN_T_APM = {
&tqdem_raccpmin_t_sav,
TQDEM_RACCMIN_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_rAccPMin_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqDem_rAccPMin_T[0]
};

#define TQDEM_STOP_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_Var_Entrees (
                                           UInt8 frm_binhgreen_tcomes_par,
                                           UInt8 ext_brvs_par,
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           SInt16 ext_toxcestim_par, /* BIN0 */
                                           UInt8 frm_binhgreen_toxcestim_par,
                                           UInt8 frm_binhrvtqdemrevstoff_par,
                                           UInt8 frm_binhrvtqdemtakeoff_par,
                                           UInt16 veh_spdveh_par); /* BIN7 */

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_Decollage_Roulage (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  tqdem_bacvnregtakeoff_par,
                       UInt8  copt_btakeoff_par,
                       UInt8  copt_noegdgearcord_par,
                       UInt16 ext_neng_par,     /* BIN0 */
                       UInt8  ext_stgbxcf_par,
                       UInt8  frm_binhrvtqdemtakeoff_par,
                       UInt16 tqdem_1ms_u16_dt_par,
                       SInt16 tqdem_tqckefcdeltatakeoff_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaprvsdrv_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_rdrivtakeoff_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_Transitions_Roulage (
                       UInt8 copt_noegdgearcord_par,
                       UInt32 copt_spdvehgearratcord_par, /* BIN10 */
                       UInt16 ext_neng_par, /* BIN0 */
                       UInt8 ext_stgbxcf_par,
                       UInt8 frm_binhrvtqdemtakeoff_par,
                       UInt16 tqsys_ntaridl_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvfirst_ptr,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvsec_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  tqdem_rtrandrv_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F04_Filtrage_Regime_moteur (
                       UInt8 tqsys_bacvantistall_par,
                       UInt16 tqdem_rdrivtakeoff_par,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_facgainfil_nck_ptr, /* BIN10 */
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bdrivtakeoff_ptr );

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_Mode_Green (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  coptst_steng_par,
                       UInt8  copt_idxptspt_par,    /* BIN0 */
                       UInt8  ext_bkeyon_par,
                       UInt16 ext_neng_par,       /* BIN0 */
                       UInt8  frm_binheco_par,
                       UInt8  eom_btwcheatpha_par,
                       UInt8  tqsys_btypfu_par,
                       SInt16 tqdem_tqckefcdeltaeconorm_par,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_rtraneconorm_ptr);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_01_Constant (
                       UInt16 ext_neng_par /* BIN0 */);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_02_Calcul_TqDem_r_vVEh (
                       UInt8 tqdem_bacvnregtakeoff_par,
                       UInt8 copt_noegdgearcord_par,
                       UInt8 frm_binhrvtqdemtakeoff_par,
                       UInt8 ext_stgbxcf_par,
                       UInt8 copt_btakeoff_par
                       );

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_03_ME_Decollage (
                       UInt16 accp_raccp_par, /* BIN7 */
                       UInt8 copt_btakeoff_par,
                       UInt8 copt_noegdgearcord_par,
                       UInt8 ext_stgbxcf_par,
                       UInt16 tqdem_1ms_u16_dt_par,
                       SInt16 tqdem_tqckefcdeltatakeoff_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaprvsdrv_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_rdrivtakeoff_ptr);

STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_Stdrivtakeoff_Sub_State(UInt8 copt_noegdgearcord_par,
                                                                  UInt8 ext_stgbxcf_par);


INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_01_Calcul_TqDem_idxGear (
                       UInt8  copt_noegdgearcord_par,
                       UInt32 copt_spdvehgearratcord_par, /* BIN10 */
                       UInt8  frm_binhrvtqdemtakeoff_par);


 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_02_Constant (void);
 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_03_TqDem_r_MidHiV (void);
 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_04_TqDem_r_LoMidV (void);

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_05_ME_Roulage (
                       UInt8 copt_noegdgearcord_par,
                       UInt16 ext_neng_par,     /* BIN0 */
                       UInt8 ext_stgbxcf_par,
                       UInt16 tqsys_ntaridl_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvfirst_ptr,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvsec_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  tqdem_rtrandrv_ptr);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_Transition_Green (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  coptst_steng_par,
                       UInt8  copt_idxptspt_par,    /* BIN0 */
                       UInt8  ext_bkeyon_par,
                       UInt16 ext_neng_par,       /* BIN0 */
                       UInt8  frm_binheco_par,
                       UInt8  eom_btwcheatpha_par,
                       UInt8  tqsys_btypfu_par,
                       SInt16 tqdem_tqckefcdeltaeconorm_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_01_Activation_Mode_Green (
	                   UInt16 accp_raccp_par,    /* BIN7 */
                       UInt8  copt_idxptspt_par,    /* BIN0 */
                       UInt8  eom_btwcheatpha_par,
                       UInt8  tqsys_btypfu_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_03_Etat_Moteur_Demarrage (
                       UInt8  coptst_steng_par,
                       UInt8  ext_bkeyon_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_02_Constant (
                       UInt16 ext_neng_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_04_ME_Green (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  frm_binheco_par,
                       SInt16 tqdem_tqckefcdeltaeconorm_par);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Structure
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Ivc_Structure(UInt8 TqDem_bAcvNRegTakeOff_swc_in,
                                         SInt16 TqDem_tqCkEfcDeltaTakeOff_swc_in, /* BIN4 */
                                         SInt16 TqDem_tqCkEfcDeltaEcoNorm_swc_in, /* BIN4 */
                                         UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                         UInt8 CoPTSt_stEng_swc_in,
                                         UInt8 CoPt_bTakeOff_swc_in,
                                         UInt8 CoPt_idxPtSpt_swc_in, /* BIN0 */
                                         UInt8 CoPt_noEgdGearCord_swc_in,
                                         UInt32 CoPt_spdVehGearRatCord_swc_in, /* BIN10 */
                                         UInt8 Ext_bKeyOn_swc_in,
                                         UInt8 Ext_bRvs_swc_in,
                                         UInt16 Ext_nEng_swc_in, /* BIN0 */
                                         UInt8 Ext_stGBxCf_swc_in,
                                         SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                         SInt16 Ext_tOxCEstim_swc_in, /* BIN0 */
                                         UInt8 FRM_bInhEco_swc_in,
                                         UInt8 FRM_bInhGreen_tCoMes_swc_in,
                                         UInt8 FRM_bInhGreen_tOxCEstim_swc_in,
                                         UInt8 FRM_bInhRvTqDemRevStOff_swc_in,
                                         UInt8 FRM_bInhRvTqDemTakeOff_swc_in,
                                         UInt8 TqSys_bAcvAntiStall_swc_in,
                                         UInt8 TqSys_bTypFu_swc_in,
                                         UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                         UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                         UInt8 EOM_bTWCHeatPha_swc_in,
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bDrivTakeOff_swc_out,
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFil_nCk_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rDrivTakeOff_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_idxMapRvsDrv_swc_out, /* BIN0 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_idxMapTranDrvFirst_swc_out, /* BIN0 */
                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_idxMapTranDrvSec_swc_out, /* BIN0 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranDrv_swc_out, /* BIN10 */
                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranEcoNorm_swc_out /* BIN10 */)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.1.1 */
  UInt16 tqdem_1ms_u16_dt;
  UInt32 tqdem_1ms_u32_time_tmp;

  tqdem_1ms_u32_time_tmp = DDS_TQDEM_1MS_U32_TIME;
  tqdem_1ms_u16_dt = (UInt16)DDS_M_MIN(tqdem_1ms_u32_time_tmp - tqdem_1ms_u32_time_prev, DDS_UINT16_MAX);
  tqdem_1ms_u32_time_prev = tqdem_1ms_u32_time_tmp;


  TQDEM_F02_Var_Entrees ( FRM_bInhGreen_tCoMes_swc_in,
                                    Ext_bRvs_swc_in,
                                    Ext_tCoMes_swc_in, /* BIN0 */
                                    Ext_tOxCEstim_swc_in, /* BIN0 */
                                    FRM_bInhGreen_tOxCEstim_swc_in,
                                    FRM_bInhRvTqDemRevStOff_swc_in,
                                    FRM_bInhRvTqDemTakeOff_swc_in,
                                    Veh_spdVeh_swc_in);

  TQDEM_F03_Decollage_Roulage (
                    AccP_rAccP_swc_in, /* BIN7 */
                    TqDem_bAcvNRegTakeOff_swc_in,
                    CoPt_bTakeOff_swc_in,
                    CoPt_noEgdGearCord_swc_in,
                    Ext_nEng_swc_in, /* BIN0 */
                    Ext_stGBxCf_swc_in,
                    FRM_bInhRvTqDemTakeOff_swc_in,
                    tqdem_1ms_u16_dt,
                    TqDem_tqCkEfcDeltaTakeOff_swc_in,
                    TqDem_idxMapRvsDrv_swc_out,
                    TqDem_rDrivTakeOff_swc_out
                    );

  TQDEM_F05_Transitions_Roulage (
                    CoPt_noEgdGearCord_swc_in,
                    CoPt_spdVehGearRatCord_swc_in, /* BIN10 */
                    Ext_nEng_swc_in,         /* BIN0 */
                    Ext_stGBxCf_swc_in,
                    FRM_bInhRvTqDemTakeOff_swc_in,
                    TqSys_nTarIdl_swc_in,
                    TqDem_idxMapTranDrvFirst_swc_out,
                    TqDem_idxMapTranDrvSec_swc_out,
                    TqDem_rTranDrv_swc_out
                    );

  TQDEM_F04_Filtrage_Regime_moteur (
                    TqSys_bAcvAntiStall_swc_in,
                    *TqDem_rDrivTakeOff_swc_out,
                    TqDem_facGainFil_nCk_swc_out,    /* BIN10 */
                    TqDem_bDrivTakeOff_swc_out
                    );

  TQDEM_F06_Mode_Green (  AccP_rAccP_swc_in, /* BIN7 */
                                    CoPTSt_stEng_swc_in,
                                    CoPt_idxPtSpt_swc_in, /* BIN0 */
                                    Ext_bKeyOn_swc_in,
                                    Ext_nEng_swc_in, /* BIN0 */
                                    FRM_bInhEco_swc_in,
                                    EOM_bTWCHeatPha_swc_in,
                                    TqSys_bTypFu_swc_in,
                                    TqDem_tqCkEfcDeltaEcoNorm_swc_in,
                                    TqDem_rTranEcoNorm_swc_out);

  if((UInt32)DDS_FALSE == (UInt32)tqdem_rampe_initialised)
  {
    tqdem_rampe_initialised = DDS_TRUE;
  }
}



/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_F02_Var_Entrees
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F02_Var_Entrees (
                                           UInt8  frm_binhgreen_tcomes_par,
                                           UInt8  ext_brvs_par,
                                           SInt16 ext_tcomes_par,         /* BIN0 */
                                           SInt16 ext_toxcestim_par,      /* BIN0 */
                                           UInt8  frm_binhgreen_toxcestim_par,
                                           UInt8  frm_binhrvtqdemrevstoff_par,
                                           UInt8  frm_binhrvtqdemtakeoff_par,
                                           UInt16 veh_spdveh_par)         /* BIN7 */
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.2.1 */

  if((UInt32)DDS_FALSE != (UInt32)tqdem_rampe_initialised)
  {
    TqDem_spdVeh = (UInt16)DDS_M_SOFT_TRANS_U32(frm_binhrvtqdemtakeoff_par,
                                              (UInt32)veh_spdveh_par,
                                              (UInt32)TqDem_spdVehDft_C,
                                              DDS_TQDEM_1MS_U32_TIME,
                                            /* DEC3 = DEC1 * DEC2 */
                                              (UInt32)TqDem_tiTranSpdDftOn_C * DEC2,
                                            /* DEC3 = DEC1 * DEC2 */
                                              (UInt32)TqDem_tiTranSpdDftOff_C * DEC2,
                                              &tqdem_vveh_rampe);
  }
  else
  {
    TqDem_spdVeh = (UInt16)DDS_M_SOFT_TRANS_INIT_U32( frm_binhrvtqdemtakeoff_par,
                                                    (UInt32)veh_spdveh_par,
                                                    (UInt32)TqDem_spdVehDft_C,
                                                    DDS_TQDEM_1MS_U32_TIME,
                                                    NULL_PTR,
                                                    &tqdem_vveh_rampe);
  }

  if((UInt32)DDS_FALSE != (UInt32)frm_binhrvtqdemrevstoff_par)
  {
    TqDem_bRvs = 0;
  }
  else
  {
    TqDem_bRvs = ext_brvs_par;
  }

  if((UInt32)DDS_FALSE != (UInt32)frm_binhgreen_tcomes_par)
  {
    TqDem_tCoMes = TqDem_tCoMesDft_C;
  }
  else
  {
    TqDem_tCoMes = ext_tcomes_par;
  }

  TqDem_spdVehMinTakeOff = TqDem_spdVehMinTakeOff_C;
  TqDem_spdVehMaxTakeOff = TqDem_spdVehMaxTakeOff_C;

  if((UInt32)DDS_FALSE != (UInt32)frm_binhgreen_toxcestim_par)
  {
    TqDem_tOxCEstim = TqDem_tOxCDft_C;
  }
  else
  {
    TqDem_tOxCEstim = ext_toxcestim_par;
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_F03_Decollage_Roulage
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_Decollage_Roulage (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  tqdem_bacvnregtakeoff_par,
                       UInt8  copt_btakeoff_par,
                       UInt8  copt_noegdgearcord_par,
                       UInt16 ext_neng_par,     /* BIN0 */
                       UInt8  ext_stgbxcf_par,
                       UInt8  frm_binhrvtqdemtakeoff_par,
                       UInt16 tqdem_1ms_u16_dt_par,
                       SInt16 tqdem_tqckefcdeltatakeoff_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaprvsdrv_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_rdrivtakeoff_ptr)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.3.2 */

  TQDEM_F03_01_Constant (  ext_neng_par ); /* BIN0 */

  TQDEM_F03_02_Calcul_TqDem_r_vVEh (
                  tqdem_bacvnregtakeoff_par,
                  copt_noegdgearcord_par,
                  frm_binhrvtqdemtakeoff_par,
                  ext_stgbxcf_par,
                  copt_btakeoff_par);

  TQDEM_F03_03_ME_Decollage (
                  accp_raccp_par, /* BIN7 */
                  copt_btakeoff_par,
                  copt_noegdgearcord_par,
                  ext_stgbxcf_par,
                  tqdem_1ms_u16_dt_par,
                  tqdem_tqckefcdeltatakeoff_par,
                  tqdem_idxmaprvsdrv_ptr,
                  tqdem_rdrivtakeoff_ptr);
}

/*******************************************************************************
*
* Function Name : TQDEM_F03_01_Constant
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_01_Constant (UInt16 ext_neng_par)
 {
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.4.1 */

  /*  [0; 100] / BIN7 */
  TqDem_rAccPMin = DDS_M_MAP2D_U16(&TQDEM_RACCPMIN_T_APM,
                                      ext_neng_par);

  TqDem_bTranTakeOff   = TqDem_bTranTakeOff_C;
  TqDem_bRvsTakeOff    = TqDem_bRvsTakeOff_C;
  TqDem_rAccPMax        = TqDem_rAccPMax_C;
  /* DEC2 = DEC1 * DEC1 */
  TqDem_tiMinTakeOff   = (UInt16)((UInt32)TqDem_tiMinTakeOff_C * DEC1);
  /* DEC2 = DEC1 * DEC1 */
  TqDem_tiMaxTakeOff   = (UInt16)((UInt32)TqDem_tiMaxTakeOff_C * DEC1);
  TqDem_tqCkEfcTakeOff = TqDem_tqCkEfcTakeOff_C;
  TqDem_bTakeOffGBx    = TqDem_bTakeOffGBx_C;
}

/*******************************************************************************
*
* Function Name : TQDEM_F03_02_Calcul_TqDem_r_vVEh
* Description :
*
*******************************************************************************/
 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_02_Calcul_TqDem_r_vVEh (
                       UInt8 tqdem_bacvnregtakeoff_par,
                       UInt8 copt_noegdgearcord_par,
                       UInt8 frm_binhrvtqdemtakeoff_par,
                       UInt8 ext_stgbxcf_par,
                       UInt8 copt_btakeoff_par
                       )
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.5.2 */
  UInt32 bposhys_output;
  UInt32 btrigger;
  UInt32 bcondition;
  UInt32 tempo_b2a; /* DEC3 */

  bposhys_output = DDS_M_HYST_PH_U32 ( &tqdem_spdveh_hyst,
                                      (UInt32)TqDem_spdVeh,
                                      (UInt32)TqDem_spdVehMaxTakeOff,
                                      (UInt32)TqDem_spdVehMinTakeOff );

  if(TQDEM_BVM == (UInt32)ext_stgbxcf_par)
  {
    bcondition = bposhys_output;
  }
  else
  {

    if((UInt32)copt_btakeoff_par != (UInt32)DDS_FALSE)
    {
        bcondition = (UInt32)DDS_FALSE;
    }
    else
    {
        bcondition = (UInt32)DDS_TRUE;
    }
  }

  if((((UInt32)copt_noegdgearcord_par > (UInt32)0)||((UInt32)tqdem_bacvnregtakeoff_par == (UInt32)DDS_FALSE))
  &&(bcondition != (UInt32)DDS_FALSE))
  {
      btrigger = (UInt32)DDS_TRUE;
  }
  else
  {
      btrigger = (UInt32)DDS_FALSE;
  }

  if((UInt32)DDS_FALSE != (UInt32)frm_binhrvtqdemtakeoff_par)
  {
      /* DEC3 = DEC1 * DEC2 */
    tempo_b2a = (UInt32)TqDem_tiTraTakeOffDownDft_C * DEC2;
  }
  else
  {
      /* DEC3 = DEC1 * DEC2 */
    tempo_b2a = (UInt32)TqDem_tiTraTakeOffDown_C * DEC2;
  }

  if((UInt32)DDS_FALSE != (UInt32)tqdem_rampe_initialised)
  {
    TqDem_rSpdVeh = (UInt16)DDS_M_SOFT_TRANS_U32( (UInt8)btrigger,
                                                 (UInt32)(0 * BIN10),
                                                 (UInt32)(1 * BIN10),
                                                 DDS_TQDEM_1MS_U32_TIME,
                                                /* DEC3 = DEC1 * DEC2 */
                                                 (UInt32)TqDem_tiTraTakeOffUp_C * DEC2,
                                                 tempo_b2a,
                                                 &tqdem_r_vveh_rampe);
  }
  else
  {
    TqDem_rSpdVeh = (UInt16)DDS_M_SOFT_TRANS_INIT_U32((UInt8)btrigger,
                                                     (UInt32)(0 * BIN10),
                                                     (UInt32)(1 * BIN10),
                                                     DDS_TQDEM_1MS_U32_TIME,
                                                     NULL_PTR,
                                                     &tqdem_r_vveh_rampe);
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_F03_03_ME_Decollage
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F03_03_ME_Decollage (
                       UInt16 accp_raccp_par, /* BIN7 */
                       UInt8 copt_btakeoff_par,
                       UInt8 copt_noegdgearcord_par,
                       UInt8 ext_stgbxcf_par,
                       UInt16 tqdem_1ms_u16_dt_par,
                       SInt16 tqdem_tqckefcdeltatakeoff_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaprvsdrv_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_rdrivtakeoff_ptr)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.6.2 */

  UInt32 tqdem_titakeoff_tmp;

  switch ((UInt32)tqdem_stdrivtakeoff_state)
  {
    case STDRVTAKEOFF_DECO: /* 1 */

      if ( (  ((UInt32)DDS_TRUE == (UInt32)TqDem_bTranTakeOff) &&
           ( (((UInt32)DDS_FALSE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)TqDem_spdVeh >= (UInt32)TqDem_spdVehMaxTakeOff)) ||
           (((UInt32)DDS_TRUE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)DDS_FALSE == (UInt32)copt_btakeoff_par)))
          ))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_TEMP_DECO_ROUL;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else if (((UInt32)DDS_FALSE == (UInt32)TqDem_bTranTakeOff) &&
              ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)TqDem_spdVeh >= (UInt32)TqDem_spdVehMaxTakeOff)) ||
              (((UInt32)DDS_TRUE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)DDS_FALSE == (UInt32)copt_btakeoff_par))))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_CONV_COUPLE;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      { /* During */
        TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_DECO;
        TqDem_tiTakeOffMax = (UInt16)(0 * DEC2);
        tqdem_rdrivtakeoff_prev = (UInt16)(0 * BIN10);

        TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
      }
    break;
    case STDRVTAKEOFF_HORS_DECO: /* 2 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMinTakeOff))||
         (((UInt32)DDS_TRUE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)DDS_TRUE == (UInt32)copt_btakeoff_par)))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_TEMP_ROUL_DECO;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_HORS_DECO;
        tqdem_rdrivtakeoff_prev = (UInt16)(1 * BIN10);

        TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
      }
    break;
    case STDRVTAKEOFF_TRANS_CONV_COUPLE: /* 3 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMaxTakeOff))||
         (((UInt32)DDS_TRUE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)DDS_TRUE == (UInt32)copt_btakeoff_par)))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_DECO;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else if ((UInt32)TqDem_tiTakeOffMax >= (UInt32)TqDem_tiMaxTakeOff )
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_TEMP_DECO_ROUL;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else if (((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPMax) || ((UInt32)accp_raccp_par <= (UInt32)TqDem_rAccPMin ) ||
           ((SInt32)tqdem_tqckefcdeltatakeoff_par <= (SInt32)TqDem_tqCkEfcTakeOff))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_ATTENTE;
        TqDem_tiTakeOff = (UInt16)(0 * DEC2);   /* for robustness : spec update potentially required ! */
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        tqdem_titakeoff_tmp = ((UInt32)TqDem_tiTakeOffMax + ((UInt32)tqdem_1ms_u16_dt_par / DEC1));
        TqDem_tiTakeOffMax = (UInt16)DDS_M_MIN(tqdem_titakeoff_tmp,10 * DEC2);
        TqDem_tiTakeOff = (UInt16)(0 * DEC2);
        TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_TRANS_CONV_COUPLE;
        tqdem_rdrivtakeoff_prev = (UInt16)(0 * BIN10);

        TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
      }
    break;
    case STDRVTAKEOFF_ATTENTE: /* 4 */

      if (!( ((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPMax) || ((UInt32)accp_raccp_par <= (UInt32)TqDem_rAccPMin ) ||
           ((SInt32)tqdem_tqckefcdeltatakeoff_par <= (SInt32)TqDem_tqCkEfcTakeOff)  ))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_CONV_COUPLE;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else if ((UInt32)TqDem_tiTakeOff >= (UInt32)TqDem_tiMinTakeOff )
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_HORS_DECO;
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_ATTENTE;

        tqdem_titakeoff_tmp = ((UInt32)TqDem_tiTakeOffMax + ((UInt32)tqdem_1ms_u16_dt_par / DEC1));
        TqDem_tiTakeOffMax = (UInt16)DDS_M_MIN(tqdem_titakeoff_tmp, 10 * DEC2);

        tqdem_titakeoff_tmp = ((UInt32)TqDem_tiTakeOff + ((UInt32)tqdem_1ms_u16_dt_par / DEC1));
        TqDem_tiTakeOff = (UInt16)DDS_M_MIN(tqdem_titakeoff_tmp,10 * DEC2);

        tqdem_rdrivtakeoff_prev = (UInt16)(0 * BIN10);

        TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
      }
    break;
    case STDRVTAKEOFF_TRANS_TEMP_DECO_ROUL:  /* 5 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMinTakeOff)) ||
        (((UInt32)DDS_TRUE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)DDS_TRUE == (UInt32)copt_btakeoff_par)))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_TEMP_ROUL_DECO;

        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else if((1 * BIN10) == (UInt32)TqDem_rSpdVeh)
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_HORS_DECO;

        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_TRANS_TEMP_DECO_ROUL;

        tqdem_rdrivtakeoff_prev = TqDem_rSpdVeh;

        TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
      }
    break;
    case STDRVTAKEOFF_TRANS_TEMP_ROUL_DECO: /* 6 */
      if ((0 * BIN10) == (UInt32)TqDem_rSpdVeh)
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_DECO;

        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)TqDem_spdVeh >= (UInt32)TqDem_spdVehMaxTakeOff)) ||
           (((UInt32)DDS_TRUE == (UInt32)TqDem_bTakeOffGBx) && ((UInt32)DDS_FALSE == (UInt32)copt_btakeoff_par)))
      {
        tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_TRANS_TEMP_DECO_ROUL;

        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_TRANS_TEMP_ROUL_DECO;

        tqdem_rdrivtakeoff_prev = TqDem_rSpdVeh;

        TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
      }
    break;

    default:
      /* Retour à l'etat DECO */
      tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_DECO;
      TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_DECO;
      TqDem_tiTakeOffMax = (UInt16)(0 * DEC2);
      tqdem_rdrivtakeoff_prev = (UInt16)(0 * BIN10);
      TQDEM_Calc_Stdrivtakeoff_Sub_State(copt_noegdgearcord_par, ext_stgbxcf_par);
    break;
  }

  *tqdem_idxmaprvsdrv_ptr = tqdem_idxmaprvsdrv_prev;
  *tqdem_rdrivtakeoff_ptr = tqdem_rdrivtakeoff_prev;
}

/*******************************************************************************
*
* Function Name : TQDEM_Calc_Stdrivtakeoff_Sub_State
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQDEM_Calc_Stdrivtakeoff_Sub_State(UInt8 copt_noegdgearcord_par,
                                                                  UInt8 ext_stgbxcf_par)
{
  switch ((UInt32)tqdem_stdrivtakeoff_sub_state)
  {
    case TQDEM_DECO1:

      if ((TQDEM_BRVS_MA_ENGAGEE == (UInt32)TqDem_bRvs) && (TQDEM_BVM == (UInt32)ext_stgbxcf_par))
      {
        if ((UInt32)DDS_FALSE == (UInt32)TqDem_bRvsTakeOff)
        {
          tqdem_stdrivtakeoff_sub_state =  (UInt8)TQDEM_DECO2;
        }
        else
        {
          tqdem_stdrivtakeoff_sub_state =  (UInt8)TQDEM_DECO3;
        }
      }
      else if ( (TQDEM_BVM != (UInt32)ext_stgbxcf_par) && (NOEGDGEARCORD_MA == (UInt32)copt_noegdgearcord_par) )
      {
        tqdem_stdrivtakeoff_sub_state =  (UInt8)TQDEM_DECO2;
      }
      else
      {
        tqdem_idxmaprvsdrv_prev = 5;
      }
    break;
    case TQDEM_DECO2:
      if(((TQDEM_BRVS_MA_NON_ENGAGEE == (UInt32)TqDem_bRvs) && (TQDEM_BVM == (UInt32)ext_stgbxcf_par) &&
         ((UInt32)DDS_FALSE == (UInt32)TqDem_bRvsTakeOff)) ||
         ((TQDEM_BVM != (UInt32)ext_stgbxcf_par) && (NOEGDGEARCORD_MA != (UInt32)copt_noegdgearcord_par)))
      {
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        tqdem_idxmaprvsdrv_prev = 4;
      }
    break;
    case TQDEM_DECO3:
      if((TQDEM_BRVS_MA_NON_ENGAGEE == (UInt32)TqDem_bRvs) && (TQDEM_BVM == (UInt32)ext_stgbxcf_par) &&
        ((UInt32)DDS_FALSE != (UInt32)TqDem_bRvsTakeOff))
      {
        tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      }
      else
      {
        tqdem_idxmaprvsdrv_prev = 5;
      }
    break;

    default:
      /*Return to state Deco1*/
      tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
      tqdem_idxmaprvsdrv_prev = 5;
    break;
  }
}


/*******************************************************************************
*
* Function Name : TQDEM_F04_Filtrage_Regime_moteur
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F04_Filtrage_Regime_moteur (
                                           UInt8 tqsys_bacvantistall_par,
                                           UInt16 tqdem_rdrivtakeoff_par,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_facgainfil_nck_ptr, /* BIN10 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqdem_bdrivtakeoff_ptr )
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.7.1 */
  UInt32 result_sub, result_add, result_mux1, result_mux2;

  *tqdem_bdrivtakeoff_ptr = (UInt8)((UInt32)tqdem_rdrivtakeoff_par >= (1 * BIN10));

  if( (UInt32)DDS_FALSE != (UInt32)tqsys_bacvantistall_par)
  {
    *tqdem_facgainfil_nck_ptr = (UInt16)((UInt32)TqDem_facFilNEngTraOp_C * BIN3);
  }
  else
  {
    /* BIN10 = BIN10 - BIN10 */
    /* [0; 1] = 1 - [0; 1] */
    result_sub = (1 * BIN10) - (UInt32)tqdem_rdrivtakeoff_par;

    /* BIN17 = BIN10 * BIN7 */
    /* [0; 1] = [0; 1] * [0; 1] */
    result_mux1 = result_sub * (UInt32)TqDem_facFilNEngTraOp_C;

    /* BIN17 = BIN10 * BIN7 */
    /* [0; 1] = [0; 1] * [0; 1] */
    result_mux2 = (UInt32)tqdem_rdrivtakeoff_par * (UInt32)TqDem_facFilNEngTraCls_C;

    /* BIN17 = BIN17 + BIN17 */
    /* [0; 2] = [0; 1] + [0; 1] */
    result_add = result_mux1 + result_mux2;

    *tqdem_facgainfil_nck_ptr = (UInt16)DDS_M_MIN( (result_add / BIN7), (1 * BIN10));
  }

}


/*******************************************************************************
*
* Function Name : TQDEM_F05_Transitions_Roulage
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_Transitions_Roulage (
                       UInt8 copt_noegdgearcord_par,
                       UInt32 copt_spdvehgearratcord_par, /* BIN10 */
                       UInt16 ext_neng_par, /* BIN0 */
                       UInt8 ext_stgbxcf_par,
                       UInt8 frm_binhrvtqdemtakeoff_par,
                       UInt16 tqsys_ntaridl_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvfirst_ptr,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvsec_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  tqdem_rtrandrv_ptr)
{ /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.8.1 */

  TQDEM_F05_01_Calcul_TqDem_idxGear (  copt_noegdgearcord_par,
                          copt_spdvehgearratcord_par,
                          frm_binhrvtqdemtakeoff_par);

  TQDEM_F05_02_Constant ();

  TQDEM_F05_03_TqDem_r_MidHiV ();

  TQDEM_F05_04_TqDem_r_LoMidV ();

  TQDEM_F05_05_ME_Roulage ( copt_noegdgearcord_par,
                   ext_neng_par,
                   ext_stgbxcf_par,
                   tqsys_ntaridl_par,
                   tqdem_idxmaptrandrvfirst_ptr,
                   tqdem_idxmaptrandrvsec_ptr,
                   tqdem_rtrandrv_ptr
                   );
}

/*******************************************************************************
*
* Function Name : TQDEM_F05_01_Calcul_TqDem_idxGear
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_01_Calcul_TqDem_idxGear (
                       UInt8 copt_noegdgearcord_par,
                       UInt32 copt_spdvehgearratcord_par, /* BIN10 */
                       UInt8 frm_binhrvtqdemtakeoff_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.9.1 */

  UInt16 filter_in, filter_out;
  UInt32  condition_delay, result_turn_on, result_turn_on_out;

  condition_delay = (NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par);
  result_turn_on_out = ((UInt32)DDS_M_TURN_ON_DELAY( (UInt8)condition_delay,
                          DDS_TQDEM_1MS_U32_TIME,
                          /* DEC3 = DEC1 * DEC2 */
                          (UInt32)TqDem_tiEgdGearCfm_C * DEC2,
                          &tqdem_idxgear_turn_on)) ;

  if((UInt32)DDS_FALSE !=  result_turn_on_out)
  {
      result_turn_on = (UInt32)DDS_FALSE;
  }
  else
  {
      result_turn_on = (UInt32)DDS_TRUE;
  }

  if((UInt32)DDS_FALSE != (UInt32)tqdem_rampe_filter_idxgear_initialised)
  {
    TqDem_spdVehGearRatCord_MP =
                DDS_M_SOFT_TRANS_U32(frm_binhrvtqdemtakeoff_par,
                         copt_spdvehgearratcord_par,
                         CoPt_spdVehGearRatDft_C,
                         DDS_TQDEM_1MS_U32_TIME,
                          /* DEC3 = DEC1 * DEC2 */
                         (UInt32)TqDem_tiTranGearRatDftOn_C * DEC2,
                          /* DEC3 = DEC1 * DEC2 */
                         (UInt32)TqDem_tiTranGearRatDftOff_C * DEC2,
                         &tqdem_idxgear_rampe);
  }
  else
  {
    TqDem_spdVehGearRatCord_MP = DDS_M_SOFT_TRANS_INIT_U32(frm_binhrvtqdemtakeoff_par,
                                copt_spdvehgearratcord_par,
                                CoPt_spdVehGearRatDft_C,
                                DDS_TQDEM_1MS_U32_TIME,
                                NULL_PTR,
                                &tqdem_idxgear_rampe);
  }

  /*  [1; 3] / BIN7 */
  filter_in = DDS_M_MAP2D_U16(&TQDEM_IDXGEARRAT_T_APM,
                (UInt16)(TqDem_spdVehGearRatCord_MP / BIN2));

  if((UInt32)DDS_FALSE != (UInt32)tqdem_rampe_filter_idxgear_initialised)
  {
    /* [1; 3] / BIN7  */
    filter_out = DDS_M_FILTER_LP1_U16(&tqdem_filter_tqdem_idxgear,
                      filter_in,
                      (UInt16)TqDem_facGearFil_C,
                      BIN7);
  }
  else
  {
    filter_out = DDS_M_FILTER_LP1_U16_INIT(&tqdem_filter_tqdem_idxgear,
                         filter_in);

    tqdem_rampe_filter_idxgear_initialised = DDS_TRUE;
  }

  if((UInt32)DDS_FALSE != result_turn_on)
  {
    TqDem_idxGear = filter_out;
  }
  else
  {
    TqDem_idxGear = (1 * BIN7);
  }

  TqDem_bTranDrv = TqDem_bTranDrv_C;
  if((UInt32)DDS_FALSE != (UInt32)TqDem_bTranDrv)
  {
    TqDem_facTranLvlDrv = TqDem_idxGear;
  }
  else
  {
    TqDem_facTranLvlDrv = TqDem_spdVeh;
  }

}


/*******************************************************************************
*
* Function Name : TQDEM_F03_01_Constant
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_02_Constant (void)
 {
   /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.10.2 */

   TqDem_nCkIdlHys  = TqDem_nCkIdlHys_C;
   TqDem_bRvsDrvInh  = TqDem_bRvsDrvInh_C;
   TqDem_noGearLoSpd    = TqDem_noGearLoSpd_C;
   TqDem_noGearAvrSpd = TqDem_noGearAvrSpd_C;
   TqDem_noGearHiSpd  = TqDem_noGearHiSpd_C;
   TqDem_spdVehMinAvrDrv = TqDem_spdVehMinAvrDrv_C;
   TqDem_spdVehMaxAvrDrv = TqDem_spdVehMaxAvrDrv_C;
   TqDem_spdVehMinHiSpdDrv  = TqDem_spdVehMinHiSpdDrv_C;
   TqDem_spdVehMaxHiSpdDrv  = TqDem_spdVehMaxHiSpdDrv_C;

   if((UInt32)DDS_FALSE != (UInt32)TqDem_bTranDrv)
   {
    TqDem_facTranLoAvrSpdIn = (UInt16)((UInt32)TqDem_noGearLoSpd_C * BIN7);
    TqDem_facTranLoAvrSpdOut = (UInt16)((UInt32)TqDem_noGearAvrSpd_C * BIN7);
    TqDem_facTranAvrHiSpdIn = (UInt16)((UInt32)TqDem_noGearAvrSpd_C * BIN7);
    TqDem_facTranAvrHiSpdOut = (UInt16)((UInt32)TqDem_noGearHiSpd_C * BIN7);
   }
   else
   {
    TqDem_facTranLoAvrSpdIn = TqDem_spdVehMinAvrDrv_C;
    TqDem_facTranLoAvrSpdOut = TqDem_spdVehMaxAvrDrv_C;
    TqDem_facTranAvrHiSpdIn = TqDem_spdVehMinHiSpdDrv_C;
    TqDem_facTranAvrHiSpdOut = TqDem_spdVehMaxHiSpdDrv_C;
   }
 }

/*******************************************************************************
*
* Function Name : TQDEM_F05_03_TqDem_r_MidHiV
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_03_TqDem_r_MidHiV (void)
 {
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.11.1 */
  SInt32 result_sub1, result_sub2;
  SInt32 tmp_div;

  /* BIN7 = BIN7 - BIN7 */
  /* [-500; 500] = [0; 500] - [0; 500] */
  result_sub1 = (SInt32)TqDem_facTranAvrHiSpdOut - (SInt32)TqDem_facTranAvrHiSpdIn;
  result_sub2 = (SInt32)TqDem_facTranLvlDrv - (SInt32)TqDem_facTranAvrHiSpdIn;

  if(0 == result_sub1)
  {
    TqDem_rTranAvrHiSpd = 1 * BIN10;
  }
  else
  {
    /* BIN10 = BIN7 * BIN10 / BIN7 */
    /* [-64000; 64000] = [-500; 500] / [-500; 500] */
    tmp_div = (result_sub2 * BIN10) / result_sub1;

    TqDem_rTranAvrHiSpd = (UInt16)DDS_M_LIMIT(tmp_div, (SInt32)(0 * BIN10), (SInt32)(1 * BIN10));
  }
 }

/*******************************************************************************
*
* Function Name : TQDEM_F05_04_TqDem_r_LoMidV
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_04_TqDem_r_LoMidV (void)
 {
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.12.1 */
  SInt32 result_sub1, result_sub2;
  SInt32 tmp_div;

  /* BIN7 = BIN7 - BIN7 */
  /* [-500; 500] = [0; 500] - [0; 500] */
  result_sub1 = (SInt32)TqDem_facTranLoAvrSpdOut - (SInt32)TqDem_facTranLoAvrSpdIn;
  result_sub2 = (SInt32)TqDem_facTranLvlDrv - (SInt32)TqDem_facTranLoAvrSpdIn;

  if(0 == result_sub1)
  {
    TqDem_rTranLoAvrSpd = 1 * BIN10;
  }
  else
  {
    /* BIN10 = BIN7 * BIN10 / BIN7 */
    /* [-64000; 64000] = [-500; 500] / [-500; 500] */
    tmp_div = (result_sub2 * BIN10) / result_sub1;

    TqDem_rTranLoAvrSpd = (UInt16)DDS_M_LIMIT(tmp_div, (SInt32)(0 * BIN10), (SInt32)(1 * BIN10));
  }

 }

/*******************************************************************************
*
* Function Name : TQDEM_F05_05_ME_Roulage
* Description :
*
*******************************************************************************/

 INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F05_05_ME_Roulage (
                       UInt8 copt_noegdgearcord_par,
                       UInt16 ext_neng_par,     /* BIN0 */
                       UInt8 ext_stgbxcf_par,
                       UInt16 tqsys_ntaridl_par,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvfirst_ptr,
                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqdem_idxmaptrandrvsec_ptr,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  tqdem_rtrandrv_ptr
                       )
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.13.3 */

  switch((UInt32)tqdem_sttqdrvreq_state)
  {
    case TQDEM_MA: /* 0 */
      if (
        ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMinTakeOff) ||
        (  (TQDEM_BRVS_MA_NON_ENGAGEE == (UInt32)TqDem_bRvs) && (TQDEM_BVM == (UInt32)ext_stgbxcf_par) &&
          ( NOEGDGEARCORD_N != (UInt32)copt_noegdgearcord_par) &&
             ((UInt32)ext_neng_par > ( ((UInt32)tqsys_ntaridl_par / BIN2) + (UInt32)TqDem_nCkIdlHys) )
          ) ||
          ( (NOEGDGEARCORD_MA != (UInt32)copt_noegdgearcord_par) && (TQDEM_BVM != (UInt32)ext_stgbxcf_par) )
        )
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_BV;
      }
      else
      {
        TqDem_stTqDrvReq = (UInt8)TQDEM_MA;

        tqdem_idxmaptrandrvfirst_prev = 4;

        tqdem_idxmaptrandrvsec_prev = 4;

        tqdem_rtrandrv_prev = (UInt16)(1 * BIN10);
      }
    break;
    case TQDEM_BV: /* 2 */

      if ((STDRVTAKEOFF_DECO != (UInt32)TqDem_stDrvTakeOff) && ((UInt32)DDS_FALSE == (UInt32)TqDem_bRvsDrvInh) &&
        (((TQDEM_BRVS_MA_ENGAGEE == (UInt32)TqDem_bRvs) && (TQDEM_BVM == (UInt32)ext_stgbxcf_par)) ||
         ((NOEGDGEARCORD_MA == (UInt32)copt_noegdgearcord_par) && (TQDEM_BVM != (UInt32)ext_stgbxcf_par))))
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_MA;
      }
      else if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv ) && ((UInt32)TqDem_spdVeh    >= (UInt32)TqDem_spdVehMinAvrDrv)) ||
           (((UInt32)DDS_TRUE  == (UInt32)TqDem_bTranDrv ) && ((UInt32)TqDem_idxGear > ((UInt32)TqDem_noGearLoSpd * BIN7))))
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_TRANS_BV_MV;
      }
      else
      {
        TqDem_stTqDrvReq = (UInt8)TQDEM_BV;

        tqdem_idxmaptrandrvfirst_prev = 1;
        tqdem_idxmaptrandrvsec_prev = 1;

        tqdem_rtrandrv_prev = TqDem_rTranLoAvrSpd;
      }
    break;
    case TQDEM_TRANS_BV_MV: /* 3 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMinAvrDrv)) ||
        (((UInt32)DDS_TRUE  == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear <= ((UInt32)TqDem_noGearLoSpd * BIN7))))
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_BV;
      }
      else if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh >= (UInt32)TqDem_spdVehMaxAvrDrv)) ||
           (((UInt32)DDS_TRUE  == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear >= ((UInt32)TqDem_noGearAvrSpd * BIN7))))

      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_MV;
      }
      else
      {
        TqDem_stTqDrvReq = (UInt8)TQDEM_TRANS_BV_MV;

        tqdem_idxmaptrandrvfirst_prev = 1;

        tqdem_idxmaptrandrvsec_prev = 2;

        tqdem_rtrandrv_prev= TqDem_rTranLoAvrSpd;
      }
    break;
    case TQDEM_MV: /* 4 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMaxAvrDrv)) ||
        (((UInt32)DDS_TRUE  == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear < ((UInt32)TqDem_noGearAvrSpd * BIN7))))
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_TRANS_BV_MV;
      }
      else if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh >= (UInt32)TqDem_spdVehMinHiSpdDrv)) ||
           (((UInt32)DDS_TRUE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear > ((UInt32)TqDem_noGearAvrSpd * BIN7))))

      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_TRANS_MV_HV;
      }
      else
      {
        TqDem_stTqDrvReq = (UInt8)TQDEM_MV;

        tqdem_idxmaptrandrvfirst_prev = 2;
        tqdem_idxmaptrandrvsec_prev = 2;

        tqdem_rtrandrv_prev = TqDem_rTranLoAvrSpd;
      }
    break;
    case TQDEM_TRANS_MV_HV: /* 5 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMinHiSpdDrv)) ||
        (((UInt32)DDS_TRUE  == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear <= ((UInt32)TqDem_noGearAvrSpd * BIN7))))
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_MV;
      }
      else if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh >= (UInt32)TqDem_spdVehMaxHiSpdDrv)) ||
           (((UInt32)DDS_TRUE  == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear >= ((UInt32)TqDem_noGearHiSpd * BIN7))))

      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_HV;
      }
      else
      {
        TqDem_stTqDrvReq = (UInt8)TQDEM_TRANS_MV_HV;

        tqdem_idxmaptrandrvfirst_prev = 2;
        tqdem_idxmaptrandrvsec_prev = 3;

        tqdem_rtrandrv_prev = TqDem_rTranAvrHiSpd;
      }
    break;
    case TQDEM_HV: /* 6 */

      if ((((UInt32)DDS_FALSE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_spdVeh < (UInt32)TqDem_spdVehMaxHiSpdDrv)) ||
        (((UInt32)DDS_TRUE == (UInt32)TqDem_bTranDrv) && ((UInt32)TqDem_idxGear < ((UInt32)TqDem_noGearHiSpd * BIN7))))
      {
        tqdem_sttqdrvreq_state = (UInt8)TQDEM_TRANS_MV_HV;
      }
      else
      {
        TqDem_stTqDrvReq = (UInt8)TQDEM_HV;

        tqdem_idxmaptrandrvfirst_prev = 3;

        tqdem_idxmaptrandrvsec_prev = 3;

        tqdem_rtrandrv_prev = TqDem_rTranAvrHiSpd;
      }
    break;

    default:
      /* Retour à l'état BV */
      tqdem_sttqdrvreq_state = (UInt8)TQDEM_BV;
      TqDem_stTqDrvReq = (UInt8)TQDEM_BV;
      tqdem_idxmaptrandrvfirst_prev = 1;
      tqdem_idxmaptrandrvsec_prev = 1;
      tqdem_rtrandrv_prev = TqDem_rTranLoAvrSpd;
    break;
  }

  *tqdem_idxmaptrandrvfirst_ptr = tqdem_idxmaptrandrvfirst_prev;
  *tqdem_idxmaptrandrvsec_ptr = tqdem_idxmaptrandrvsec_prev;
  *tqdem_rtrandrv_ptr = tqdem_rtrandrv_prev;
}

/*******************************************************************************
*
* Function Name : TQDEM_F06_Mode_Green
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_Mode_Green (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  coptst_steng_par,
                       UInt8  copt_idxptspt_par,    /* BIN0 */
                       UInt8  ext_bkeyon_par,
                       UInt16 ext_neng_par,       /* BIN0 */
                       UInt8  frm_binheco_par,
                       UInt8  eom_btwcheatpha_par,
                       UInt8  tqsys_btypfu_par,
                       SInt16 tqdem_tqckefcdeltaeconorm_par,
                       CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqdem_rtraneconorm_ptr)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.14.2 */

 UInt8 activ_trans_green_tmp;

 if(((UInt32)DDS_FALSE == (UInt32)frm_binheco_par)&&((UInt32)DDS_FALSE != ((UInt32)TqDem_bAcvEcoOn_C)))
 {
     activ_trans_green_tmp = DDS_TRUE;
 }
 else
 {
     activ_trans_green_tmp = DDS_FALSE;
 }

  if((UInt32)DDS_FALSE != (UInt32)activ_trans_green_tmp)
  {
    TQDEM_F06_01_Transition_Green (  accp_raccp_par,     /* BIN7 */
                        coptst_steng_par,
                        copt_idxptspt_par,    /* BIN0 */
                        ext_bkeyon_par,
                        ext_neng_par,       /* BIN0 */
                        frm_binheco_par,
                        eom_btwcheatpha_par,
                        tqsys_btypfu_par,
                        tqdem_tqckefcdeltaeconorm_par);
  }
  else
  {
    TqDem_stDrvEcoReq = (UInt8)STGREEN_NORMAL;
    tqdem_stgreen_state = (UInt8)STGREEN_NORMAL;
    tqdem_rtraneconorm_prev = 1 * BIN10;
  }

  *tqdem_rtraneconorm_ptr = tqdem_rtraneconorm_prev;
}

/*******************************************************************************
*
* Function Name : TQDEM_F06_01_Transition_Green
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_Transition_Green (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  coptst_steng_par,
                       UInt8  copt_idxptspt_par,    /* BIN0 */
                       UInt8  ext_bkeyon_par,
                       UInt16 ext_neng_par,       /* BIN0 */
                       UInt8  frm_binheco_par,
                       UInt8  eom_btwcheatpha_par,
                       UInt8  tqsys_btypfu_par,
                       SInt16 tqdem_tqckefcdeltaeconorm_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.15.1 */
  TQDEM_F06_01_01_Activation_Mode_Green (accp_raccp_par,    /* BIN7 */
                    copt_idxptspt_par,     /* BIN0 */
                    eom_btwcheatpha_par,
                    tqsys_btypfu_par);

  TQDEM_F06_01_02_Constant (
                    ext_neng_par
                    );

  TQDEM_F06_01_03_Etat_Moteur_Demarrage (
                    coptst_steng_par,
                    ext_bkeyon_par);

  TQDEM_F06_01_04_ME_Green (    accp_raccp_par,       /* BIN7 */
                    frm_binheco_par,
                    tqdem_tqckefcdeltaeconorm_par);

  tqdem_bacvtraneco_prev = TqDem_bAcvTranEco;
}

/*******************************************************************************
*
* Function Name : TQDEM_F06_01_01_Activation_Mode_Green
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_01_Activation_Mode_Green (
	                   UInt16 accp_raccp_par,    /* BIN7 */
                       UInt8  copt_idxptspt_par,    /* BIN0 */
                       UInt8  eom_btwcheatpha_par,
                       UInt8  tqsys_btypfu_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.16.3 */
  UInt8 bresult_switch;
  UInt8 bresult_temp;
  UInt8 bresult_compare;
  UInt8 bresult_compare_not;

  if(((UInt32)copt_idxptspt_par <= (UInt32)TqDem_idxPtSpt_C))
  {
      bresult_compare = DDS_TRUE;
      bresult_compare_not = DDS_FALSE;
  }
  else
  {
      bresult_compare = DDS_FALSE;
      bresult_compare_not = DDS_TRUE;
  }

  if((UInt32)DDS_FALSE != (UInt32)tqsys_btypfu_par)
  {
	bresult_temp = (UInt8)(((UInt32)eom_btwcheatpha_par == ((UInt32)DDS_TRUE)) ||
	(((UInt32)accp_raccp_par > (UInt32)TqDem_rAccPThdTranNorm_C)) ||
	(((UInt32)TqDem_bAcvPtSptGsl_C == ((UInt32)DDS_TRUE)) && ((UInt32)bresult_compare== ((UInt32)DDS_TRUE))));

    switch((UInt32)TqDem_stTranNormCf_C)
    {

      case TQDEM_IVC_STRUCTURE_1:
        bresult_switch = (UInt8)
      (
      (((SInt32)TqDem_tCoMes    <= (SInt32)TqDem_tCoThdHiTranNorm_C ) && ((SInt32)TqDem_tCoMes    >= (SInt32)TqDem_tCoThdLoTranNorm_C )) ||
      (((SInt32)TqDem_tOxCEstim <= (SInt32)TqDem_tOxCHiTranNorm_C) && ((SInt32)TqDem_tOxCEstim >= (SInt32)TqDem_tOxCLoTranNorm_C))
      );
      break;

      case TQDEM_IVC_STRUCTURE_2:
        bresult_switch = bresult_temp;
      break;

      case TQDEM_IVC_STRUCTURE_0:
      default:
        bresult_switch =  (UInt8)(
      (
        (  ((SInt32)TqDem_tCoMes    <= (SInt32)TqDem_tCoThdHiTranNorm_C )
         &&((SInt32)TqDem_tCoMes    >= (SInt32)TqDem_tCoThdLoTranNorm_C ) )
      ||(  ((SInt32)TqDem_tOxCEstim <= (SInt32)TqDem_tOxCHiTranNorm_C)
         &&((SInt32)TqDem_tOxCEstim >= (SInt32)TqDem_tOxCLoTranNorm_C) ) )
      ||((UInt32)bresult_temp == (UInt32)DDS_TRUE)
      );
      break;

    }

    if((UInt32)DDS_FALSE == (UInt32)bresult_switch)
    {
        TqDem_bAuthTranNorm = DDS_TRUE;
    }
    else
    {
        TqDem_bAuthTranNorm = DDS_FALSE;
    }
  }
  else
  {
	 TqDem_bAuthTranNorm = bresult_compare_not;
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_F06_01_02_Constant
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_02_Constant (UInt16 ext_neng_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.17.1 */

  /* [0; 100] BIN7 */
  TqDem_rAccPMaxEco = DDS_M_MAP2D_U16(&TQDEM_RACCPMAXECO_T_APM,
                                      ext_neng_par);

  TqDem_bTranTiEcoOn = TqDem_bTranTiEcoOn_C;
  /* DEC2 = DEC0 * DEC2 */
  TqDem_tiMaxAcvEco = (UInt16)((UInt32)TqDem_tiMaxAcvEco_C * DEC2);
  TqDem_bTranStallEco = TqDem_bTranStallEco_C;
  TqDem_tqCkEfcMinEco = TqDem_tqCkEfcMinEco_C;
  /* DEC2 = DEC1 * DEC1 */
  TqDem_tiCfmEco = (UInt16)((UInt32)TqDem_tiCfmEco_C * DEC1);
  TqDem_rAccPMinEco = (UInt16)DDS_M_MAX((SInt32)TqDem_rAccPMinEco_C, (SInt32)(0 * BIN7));

  if((UInt32)DDS_FALSE != (UInt32)tqdem_rgreen_rampe_initialised)
  {
    TqDem_rTranEco = (UInt16)DDS_M_SOFT_TRANS_U32( tqdem_bacvtraneco_prev,
                         (UInt32)(0 * BIN10),
                         (UInt32)(1 * BIN10),
                         DDS_TQDEM_1MS_U32_TIME,
                         /* DEC3 = DEC1 * DEC2 */
                         (UInt32)TqDem_tiTranEcoNorm_C * DEC2,
                         TQDEM_TI_WAITECO_DELTA * DEC1,
                         &tqdem_rgreen_rampe);
  }
  else
  {
    TqDem_rTranEco = (UInt16)DDS_M_SOFT_TRANS_INIT_U32(   tqdem_bacvtraneco_prev,
                            (UInt32)(0 * BIN10),
                            (UInt32)(1 * BIN10),
                            DDS_TQDEM_1MS_U32_TIME,
                            NULL_PTR,
                            &tqdem_rgreen_rampe);

    tqdem_rgreen_rampe_initialised = DDS_TRUE;
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_F06_01_03_Etat_Moteur_Demarrage
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_03_Etat_Moteur_Demarrage (
                       UInt8  coptst_steng_par,
                       UInt8  ext_bkeyon_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.18.0 */
  switch((UInt32)TqDem_stStrt)
  {
    case STSTRT_ECU_ETEINT:

      if ((UInt32)DDS_TRUE == (UInt32)ext_bkeyon_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_ECU_REVEILLE;
      }
      else
      {
        /* Do nothing */
      }
    break;
    case STSTRT_ECU_REVEILLE:

      if ((UInt32)DDS_FALSE == (UInt32)ext_bkeyon_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_ECU_EXTINCTION2; /* updated in entry */
      }
      else if (STENG_ENGINE_RUNNING == (UInt32)coptst_steng_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_MOTEUR_DEMARRE;
      }
      else
      {
        /* Do nothing */
      }
    break;
    case STSTRT_MOTEUR_DEMARRE:

      if (STENG_COUPE_CALE == (UInt32)coptst_steng_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_MOTEUR_ARRETE_OU_CALE;
      }
      else
      {
        /* Do nothing */
      }
    break;
    case STSTRT_MOTEUR_ARRETE_OU_CALE:

      if ((UInt32)DDS_FALSE == (UInt32)ext_bkeyon_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_ECU_EXTINCTION; /* updated in entry */
      }
      else if (STENG_ENGINE_RUNNING == (UInt32)coptst_steng_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_MOTEUR_DEMARRE;
      }
      else
      {
        /* Do nothing */
      }
    break;
    case STSTRT_ECU_EXTINCTION:

      if ((UInt32)DDS_TRUE == (UInt32)ext_bkeyon_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_MOTEUR_ARRETE_OU_CALE;
      }
      else
      {
        TqDem_stStrt = (UInt8)STSTRT_ECU_ETEINT;
      }
    break;
    case STSTRT_ECU_EXTINCTION2:

      if ((UInt32)DDS_TRUE == (UInt32)ext_bkeyon_par)
      {
        TqDem_stStrt = (UInt8)STSTRT_ECU_REVEILLE;
      }
      else
      {
        TqDem_stStrt = (UInt8)STSTRT_ECU_ETEINT;
      }
    break;

    default:
      /* Retour à l'état ECU_Eteint */
      TqDem_stStrt = (UInt8)STSTRT_ECU_ETEINT;

    break;
  }
}

/*******************************************************************************
*
* Function Name : TQDEM_F06_01_04_ME_Green
* Description :
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F06_01_04_ME_Green (
                       UInt16 accp_raccp_par,     /* BIN7 */
                       UInt8  frm_binheco_par,
                       SInt16 tqdem_tqckefcdeltaeconorm_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT05_1397.FR.19.2 */
  /* Requirement has been updated */

  switch((UInt32)tqdem_stgreen_state)
  {
    case STGREEN_NON_DEMARRE:

      if ( (STSTRT_MOTEUR_DEMARRE == (UInt32)TqDem_stStrt) && ((UInt32)DDS_FALSE == (UInt32)frm_binheco_par) )
      {
        tqdem_stgreen_state = (UInt8)STGREEN_DEMARRE;

      }
      else if( ((UInt32)DDS_TRUE == (UInt32)frm_binheco_par) ||
           ((STSTRT_ECU_REVEILLE == (UInt32)TqDem_stStrt) && ((UInt32)DDS_TRUE == (UInt32)TqDem_bAuthTranNorm )))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_NORMAL;
        /* entry */
        TqDem_bAcvTranEco = DDS_TRUE;
      }
      else
      {
         /* do nothing */
      }

    break;
    case STGREEN_DEMARRE:

      if ((STSTRT_MOTEUR_ARRETE_OU_CALE  == (UInt32)TqDem_stStrt) && ((UInt32)DDS_TRUE == (UInt32)TqDem_bTranStallEco))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_NORMAL;
        /* entry */
        TqDem_bAcvTranEco = DDS_TRUE;
      }
      else if (((UInt32)DDS_TRUE == (UInt32)TqDem_bAuthTranNorm) && ((UInt32)DDS_TRUE == (UInt32)TqDem_bTranTiEcoOn))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_TRANSITION_TEMPORELLE;
        /* entry */
        TqDem_bAcvTranEco = DDS_TRUE;
      }
      else if (((UInt32)DDS_TRUE == (UInt32)TqDem_bAuthTranNorm) && ((UInt32)DDS_FALSE == (UInt32)TqDem_bTranTiEcoOn) &&
           ( ((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPMaxEco) || ((UInt32)accp_raccp_par <= (UInt32)TqDem_rAccPMinEco) ||
           ((SInt32)tqdem_tqckefcdeltaeconorm_par <= (SInt32)TqDem_tqCkEfcMinEco) ))


      {
        tqdem_stgreen_state = (UInt8)STGREEN_ATTENTE;
        /* entry */
        TqDem_bAcvTranEco = DDS_FALSE;
        TqDem_tiWaitEco = TqDem_tiCfmEco;
      }
      else
      {
        TqDem_bAcvTranEco = DDS_FALSE;

        TqDem_stDrvEcoReq = (UInt8)STGREEN_DEMARRE;

        tqdem_rtraneconorm_prev = 0 * BIN10;

        TqDem_tiAcvEco = (UInt16)DDS_M_MIN(((UInt32)TqDem_tiAcvEco + TQDEM_TI_WAITECO_DELTA), 10 * DEC2);
      }
    break;
    case STGREEN_TRANSITION_TEMPORELLE:

      if (((UInt32)tqdem_rtraneconorm_prev == (1 * BIN10)) || ((UInt32)TqDem_stStrt == STSTRT_MOTEUR_ARRETE_OU_CALE) ||
        ((UInt32)TqDem_tiAcvEco >= (UInt32)TqDem_tiMaxAcvEco))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_NORMAL;

        TqDem_bAcvTranEco = DDS_TRUE;
      }
      else if (((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPMaxEco) || ((UInt32)accp_raccp_par <= (UInt32)TqDem_rAccPMinEco) ||
           ((SInt32)tqdem_tqckefcdeltaeconorm_par <= (SInt32)TqDem_tqCkEfcMinEco))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_ATTENTE;

        TqDem_bAcvTranEco = DDS_FALSE;

        TqDem_tiWaitEco = TqDem_tiCfmEco;
      }
      else
      {
        TqDem_stDrvEcoReq = (UInt8)STGREEN_TRANSITION_TEMPORELLE;
        TqDem_tiAcvEco = (UInt16)DDS_M_MIN(((UInt32)TqDem_tiAcvEco + TQDEM_TI_WAITECO_DELTA), 10 * DEC2);
        tqdem_rtraneconorm_prev = TqDem_rTranEco;
      }
    break;
    case STGREEN_ATTENTE:

      if ((UInt32)DDS_FALSE == (((UInt32)accp_raccp_par >= (UInt32)TqDem_rAccPMaxEco  ) ||
         ((UInt32)accp_raccp_par <= (UInt32)TqDem_rAccPMinEco ) ||
         ((SInt32)tqdem_tqckefcdeltaeconorm_par <= (SInt32)TqDem_tqCkEfcMinEco))   )
      {
        tqdem_stgreen_state = (UInt8)STGREEN_TRANSITION_TEMPORELLE;

        TqDem_bAcvTranEco = DDS_TRUE;
      }
      else if (((UInt32)TqDem_tiWaitEco == (0 * DEC2)) || (STSTRT_MOTEUR_ARRETE_OU_CALE == (UInt32)TqDem_stStrt))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_NORMAL;

        TqDem_bAcvTranEco = DDS_TRUE;
      }
      else
      {
        TqDem_stDrvEcoReq = (UInt8)STGREEN_ATTENTE;

        tqdem_rtraneconorm_prev = TqDem_rTranEco;

        TqDem_tiWaitEco = (UInt16)DDS_M_MAX(((UInt32)TqDem_tiWaitEco - TQDEM_TI_WAITECO_DELTA), 0 * DEC2);
        TqDem_tiAcvEco = (UInt16)DDS_M_MIN(((UInt32)TqDem_tiAcvEco + TQDEM_TI_WAITECO_DELTA), 10 * DEC2);
      }
    break;
    case STGREEN_NORMAL:

      if (((UInt32)DDS_FALSE == (UInt32)TqDem_bAuthTranNorm ) && ((UInt32)TqDem_stStrt < STSTRT_ECU_REVEILLE))
      {
        tqdem_stgreen_state = (UInt8)STGREEN_NON_DEMARRE;

        TqDem_bAcvTranEco = DDS_FALSE;

        TqDem_stDrvEcoReq = (UInt8)STGREEN_NON_DEMARRE;

        tqdem_rtraneconorm_prev = 0 * BIN10;

        TqDem_tiAcvEco = 0 * DEC2;
      }
      else
      {
        TqDem_stDrvEcoReq = (UInt8)STGREEN_NORMAL;

        tqdem_rtraneconorm_prev = 1 * BIN10;
      }
    break;
    default:
      tqdem_stgreen_state = (UInt8)STGREEN_NON_DEMARRE;
    break;
  }

}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Ivc_Structure_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Ivc_Structure_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFil_nCk_swc_out, /* BIN10 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqDem_bDrivTakeOff_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqDem_idxMapTranDrvFirst_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqDem_idxMapTranDrvSec_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  TqDem_idxMapRvsDrv_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rDrivTakeOff_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranEcoNorm_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_rTranDrv_swc_out)
{
  tqdem_sttqdrvreq_state = (UInt8)TQDEM_BV;
  TqDem_stTqDrvReq = (UInt8)TQDEM_BV;

  tqdem_rampe_initialised = DDS_FALSE;
  tqdem_rgreen_rampe_initialised = DDS_FALSE;
  tqdem_stdrivtakeoff_state = (UInt8)STDRVTAKEOFF_DECO;
  tqdem_1ms_u32_time_prev = DDS_TQDEM_1MS_U32_TIME;
  tqdem_stdrivtakeoff_sub_state = (UInt8)TQDEM_DECO1;
  (void)DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE, &tqdem_idxgear_turn_on);
  tqdem_bacvtraneco_prev = DDS_FALSE;

  tqdem_rampe_filter_idxgear_initialised = DDS_FALSE;

  /* state + entry */
  tqdem_stgreen_state = (UInt8)STGREEN_NON_DEMARRE;
  TqDem_bAcvTranEco = DDS_FALSE;
  TqDem_stDrvEcoReq = (UInt8)STGREEN_NON_DEMARRE;

  *TqDem_rTranEcoNorm_swc_out = 0 * BIN10;
  tqdem_rtraneconorm_prev = *TqDem_rTranEcoNorm_swc_out;

  TqDem_tiAcvEco = 0 * DEC2;
  TqDem_tiTakeOffMax = 0 * DEC2;
  TqDem_stDrvTakeOff = (UInt8)STDRVTAKEOFF_DECO;

  *TqDem_rTranDrv_swc_out = 0 * BIN10;
  tqdem_rtrandrv_prev = *TqDem_rTranDrv_swc_out;

  *TqDem_rDrivTakeOff_swc_out = 0 * BIN10;
  *TqDem_idxMapRvsDrv_swc_out = 5 * BIN0;
  *TqDem_idxMapTranDrvSec_swc_out = 1 * BIN0;
  *TqDem_idxMapTranDrvFirst_swc_out = 1 * BIN0;

  tqdem_idxmaptrandrvfirst_prev = *TqDem_idxMapTranDrvFirst_swc_out;
  tqdem_idxmaptrandrvsec_prev = *TqDem_idxMapTranDrvSec_swc_out;
  tqdem_idxmaprvsdrv_prev = *TqDem_idxMapRvsDrv_swc_out;
  tqdem_rdrivtakeoff_prev = *TqDem_rDrivTakeOff_swc_out;

  *TqDem_facGainFil_nCk_swc_out = (UInt16)(1 * BIN10);
  *TqDem_bDrivTakeOff_swc_out = DDS_FALSE;

  /* Precaution */
  TqDem_bAuthTranNorm = DDS_FALSE;
  TqDem_stStrt = (UInt8)STSTRT_ECU_ETEINT;
  TqDem_rAccPMaxEco = 0 * BIN7;
  TqDem_rAccPMinEco = 0 * BIN7;
  TqDem_tiCfmEco = 0 * DEC2;
  TqDem_tqCkEfcMinEco = (SInt16)(0 * BIN4);
  TqDem_bTranStallEco = DDS_FALSE;
  TqDem_bTranTiEcoOn = DDS_FALSE;
  TqDem_tiMaxAcvEco = 0 * DEC2;
  TqDem_rTranEco = 0 * BIN10;

  (void)DDS_M_HYST_U32_INIT (&tqdem_spdveh_hyst,
                             DDS_FALSE);

}




#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

