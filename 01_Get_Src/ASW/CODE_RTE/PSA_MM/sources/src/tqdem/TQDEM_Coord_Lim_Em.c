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
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Coord_Lim_Em.c
* Version int :/main/L04_02/1 Date: 17/7/2012 15 h 49 m User:posmyk 
*    TWK_model:TQDEM_Coord_Lim_Em_L04_020_IMPL1
*    comments :implement 01460_12_01918_note_correctrice_CSCT_CGMT06_2031_v3_0 and add INLINE for 
*    comments :static functions
* Version dev :\main\branch_lemort_dev_tqdem\3 Date: 17/7/2012 15 h 0 m User:lemort 
*    TWK_model:TQDEM_Coord_Lim_Em_L04_020_IMPL1
*    comments :implement 01460_12_01918_note_correctrice_CSCT_CGMT06_2031_v3_0 and add INLINE for 
*    comments :static functions
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 11/7/2012 11 h 14 m User:lemort
*    TWK_model:TQDEM_Coord_Lim_Em_L04_020_IMPL1
*    comments :implement 01460_12_01918_note_correctrice_CSCT_CGMT06_2031_v3_0 and add INLINE for
*    comments :static functions
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 15 m User:lemort
*    TWK_model:TQDEM_Coord_Lim_Em_L04_020_IMPL1
*    comments :implement 01460_12_01918_note_correctrice_CSCT_CGMT06_2031_v3_0 and add INLINE for
*    comments :static functions
* Version int :/main/L04_01/2 Date: 15/9/2011 10 h 20 m User:meme
*    TWK_model:TQDEM_Coord_Lim_Em_L04_010_IMPL1_D
*    comments :Correct code following FDS A0202995
* Version dev :\main\branch_moisan_module_dev\1 Date: 6/9/2011 11 h 45 m User:moisan
*    TWK_model:TQDEM_Coord_Lim_Em_L04_010_IMPL1_D
*    comments :Correct code following FDS A0202995
* Version int :/main/L04_01/1 Date: 10/3/2011 11 h 45 m User:esnault
*    TWK_model:TQDEM_Coord_Lim_Em_L04_010_IMPL1
*    comments :Update model only for Cha_stHillAsi
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/3/2011 11 h 59 m User:moisan
*    TWK_model:TQDEM_Coord_Lim_Em_L04_010_IMPL1
*    comments :Update model only for Cha_stHillAsi
* Version int :/main/L03_01/2 Date: 13/1/2011 14 h 48 m User:meme
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1_D
*    comments :correct naming of variables non visualable section
* Version dev :\main\branch_demezil_tqdem_dev\3 Date: 12/1/2011 12 h 29 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1_D
*    comments :correct naming of variables non visualable section
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 12/1/2011 12 h 27 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1_D
*    comments :correct naming of variables non visualable section
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 12/1/2011 12 h 22 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1_D
*    comments :correct naming of variables non visualable section
* Version int :/main/L03_01/1 Date: 8/10/2010 16 h 30 m User:meme
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1
*    comments :for TqDem e6. spec CSMT_CGMT06_2031_v3_0 : FDS32249
* Version dev :\main\branch_demezil_tqdem_dev\5 Date: 1/10/2010 11 h 34 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1
*    comments :for TqDem e6. spec CSMT_CGMT06_2031_v3_0 : FDS32249
* Version dev :\main\branch_demezil_tqdem_dev\4 Date: 27/9/2010 13 h 59 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1
*    comments :for TqDem e6. spec CSMT_CGMT06_2031_v3_0
* Version dev :\main\branch_demezil_tqdem_dev\3 Date: 14/9/2010 12 h 36 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L03_010_IMPL1
*    comments :for TqDem e6. spec CSMT_CGMT06_2031_v3_0
* Version int :/main/L02_01/1 Date: 1/9/2010 14 h 5 m User:esnault
*    TWK_model:TQDEM_Coord_Lim_Em_L02_010_IMPL1
*    comments :for TqDem e6. spec CSMT_CGMT06_2031_v3_0
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 20/7/2010 14 h 11 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L02_010_IMPL1
*    comments :for TqDem e6
*    comments :spec CSMT_CGMT06_2031_v3_0
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 17/6/2010 16 h 41 m User:demezil
*    TWK_model:TQDEM_Coord_Lim_Em_L01_010_IMPL1_D
*    comments :QAC and code shaker e6 pass
* Version int :/main/L01_01/2 Date: 16/9/2009 10 h 44 m User:langendorf
*    TWK_model:TQDEM_Coord_Lim_Em_L01_010_IMPL1_D
*    comments :work in progress
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 25/8/2009 11 h 14 m User:moisan
*    TWK_model:TQDEM_Coord_Lim_Em_L01_010_IMPL1_D
*    comments :work in progress
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 17/8/2009 10 h 8 m User:moisan
*    TWK_model:TQDEM_Coord_Lim_Em_L01_010_IMPL1_D
*    comments :Correct QAC warning for xVV 3.0
* Version int :/main/L01_01/1 Date: 9/9/2008 8 h 7 m User:boucher
*    TWK_model:TQDEM_Coord_Lim_Em_L01_010_IMPL1
*    comments :First implementation for TqDem PSA SSTG
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 27/8/2008 11 h 2 m User:moisan
*    TWK_model:TQDEM_Coord_Lim_Em_L01_010_IMPL1
*    comments :First implementation for TqDem PSA SSTG
*
*******************************************************************************/


/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"
#include "TqDem.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQDEM_BVM           (UInt32)(0 * BIN0)

#define TQDEM_CNT_MAX       (UInt32)(400 * DEC2)
#define TQDEM_10_DEC1       (UInt32)(10 * DEC1)

#define TQDEM_NOEGDGEARCORD_N       (UInt32)(0 * BIN0)
#define TQDEM_NOEGDGEARCORD_R1  (UInt32)(1 * BIN0)
#define TQDEM_NOEGDGEARCORD_R2  (UInt32)(2 * BIN0)
#define TQDEM_NOEGDGEARCORD_R3  (UInt32)(3 * BIN0)
#define TQDEM_NOEGDGEARCORD_R4  (UInt32)(4 * BIN0)
#define TQDEM_NOEGDGEARCORD_R5  (UInt32)(5 * BIN0)
#define TQDEM_NOEGDGEARCORD_R6  (UInt32)(6 * BIN0)
#define TQDEM_NOEGDGEARCORD_MA  (UInt32)(7 * BIN0)

#define TQDEM_STENG_ENGINE_RUNNING  (UInt32)(5 * BIN0)

#define TQDEM_F01_02_TQMIN  (SInt32)(-2000 * BIN4)
#define TQDEM_F01_02_TQMAX  (SInt32)(2000 * BIN4)

#define TQDEM_F01_02_TQMIN_BIN10    (SInt32)(-2000 * BIN10)
#define TQDEM_F01_02_TQMAX_BIN10    (SInt32)(2000 * BIN10)

#define TQDEM_HILLASI_HOLDING   (UInt32)(0 * BIN0)
#define TQDEM_HILLASI_NOHOLDING (UInt32)(1 * BIN0)
#define TQDEM_HILLASI_DEFAULT   (UInt32)(2 * BIN0)

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

/* 16-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqLimEM_tqThdAcvHillAsi_C = (CONST(SInt16, AUTOMATIC))(35 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqLimEM_tqThdAcv_C = (CONST(SInt16, AUTOMATIC))(35 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdDft_C = (CONST(UInt16, AUTOMATIC))(45 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiDft_C = (CONST(UInt16, AUTOMATIC))(45 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOffNb0_C = (CONST(UInt16, AUTOMATIC))(40 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOffNb1_C = (CONST(UInt16, AUTOMATIC))(40 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOffNb2_C = (CONST(UInt16, AUTOMATIC))(45 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOffNb3_C = (CONST(UInt16, AUTOMATIC))(55 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOnNb0_C = (CONST(UInt16, AUTOMATIC))(25 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOnNb1_C = (CONST(UInt16, AUTOMATIC))(25 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOnNb2_C = (CONST(UInt16, AUTOMATIC))(30 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsiOnNb3_C = (CONST(UInt16, AUTOMATIC))(40 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOffNb0_C = (CONST(UInt16, AUTOMATIC))(40 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOffNb1_C = (CONST(UInt16, AUTOMATIC))(40 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOffNb2_C = (CONST(UInt16, AUTOMATIC))(45 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOffNb3_C = (CONST(UInt16, AUTOMATIC))(55 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOnNb0_C = (CONST(UInt16, AUTOMATIC))(25 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOnNb1_C = (CONST(UInt16, AUTOMATIC))(25 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOnNb2_C = (CONST(UInt16, AUTOMATIC))(30 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqLimEM_tqGrdOnNb3_C = (CONST(UInt16, AUTOMATIC))(40 * BIN0);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqLimEM_bInhLimEM_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqLimEM_bInhLimHillAsi_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqLimEM_tiTout_C = (CONST(UInt8, AUTOMATIC))(2 * DEC1);
STATIC volatile CONST(UInt8, AUTOMATIC) TqLimEM_tiGrdHillAsiRls_C = (CONST(UInt8, AUTOMATIC))(1 * DEC1);
STATIC volatile CONST(UInt8, AUTOMATIC) TqLimEM_tiToutHillAsi_C = (CONST(UInt8, AUTOMATIC))(2 * DEC1);
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

#define TQDEM_START_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqdem_f01_02_01_edge_ptr;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqdem_f01_02_03_edge_ptr;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqdem_f01_02_04_turn_on_delay_ptr;
#define TQDEM_STOP_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"

/* 32-bits variable definition */
#define TQDEM_START_SEC_VAR_32BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqdem_f01_02_01_out_count;    /* DEC2 */
STATIC VAR(UInt32, AUTOMATIC) tqdem_f01_02_03_out_count;    /* DEC2 */

STATIC VAR(SInt32, AUTOMATIC) tqlimem_tqlimemraw_bin10; /* BIN10 */
STATIC VAR(SInt32, AUTOMATIC) tqlimem_tqlimhillasiraw_bin10;    /* BIN10 */
#define TQDEM_STOP_SEC_VAR_32BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_VAR_8BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqdem_f01_02_01_flipflop_out;
STATIC VAR(UInt8, AUTOMATIC) tqdem_f01_02_03_flipflop_out;
#define TQDEM_STOP_SEC_VAR_8BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqLimEM_tqGrdEM_MP; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqLimEM_tqGrdHillAsi_MP; /* BIN0 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqLimEM_tqLimEMRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqLimEM_tqLimHillAsiRaw; /* BIN4 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_bAcvLimEM;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_bAcvLimEM_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_bAcvLimHillAsi;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_bAcvLimHillAsi_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_bBrkParkElDft;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_stBrkParkElOn;
    /* <PRQA_COMMENT><3229> Implicitely used </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_tiDiLimEM_MP; /* DEC1 */
    /* <PRQA_COMMENT><3229> Implicitely used </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqLimEM_tiDiLimHillAsi_MP; /* DEC1 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_01_Pretraiter_les_entrees(UInt8 cha_stepb_par, /* BIN0 */
                                                                    UInt8 frm_binhtqlimem_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_Limiter_couple(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                           UInt8 cha_sthillasi_par, /* BIN0 */
                                                           UInt8 coptst_steng_par,
                                                           UInt8 copt_noegdgearcord_par,
                                                           UInt8 ext_stgbxcf_par,
                                                           UInt8 frm_binhtqlimem_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_01_Activer_Condition_EM(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                   UInt8 coptst_steng_par,
                                                                   UInt8 copt_noegdgearcord_par,
                                                                   UInt8 ext_stgbxcf_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_02_Calculer_Limitation_EM(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                       UInt8 coptst_steng_par,
                                                                       UInt8 copt_noegdgearcord_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_03_Activer_Condition_Hill_Assist(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                           UInt8 cha_sthillasi_par, /* BIN0 */
                                                                           UInt8 coptst_steng_par,
                                                                           UInt8 copt_noegdgearcord_par,
                                                                           UInt8 ext_stgbxcf_par,
                                                                           UInt8 frm_binhtqlimem_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_04_Calculer_Limitation_Hill_Assis(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                           UInt8 cha_sthillasi_par, /* BIN0 */
                                                                           UInt8 coptst_steng_par,
                                                                           UInt8 copt_noegdgearcord_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_03_Coordonner_limitation_EM(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqlimem_tqlimem_ptr /* BIN4 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQDEM_Coord_Lim_Em
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Coord_Lim_Em(SInt16 CoVSCtl_tqEfcReq_swc_in, /* BIN4 */
                                           UInt8 Cha_stEPB_swc_in, /* BIN0 */
                                           UInt8 Cha_stHillAsi_swc_in, /* BIN0 */
                                           UInt8 CoPTSt_stEng_swc_in,
                                           UInt8 CoPt_noEgdGearCord_swc_in,
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 FRM_bInhTqLimEM_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEM_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.1 */
    TQDEM_F01_01_Pretraiter_les_entrees(Cha_stEPB_swc_in, /* BIN0 */
                                        FRM_bInhTqLimEM_swc_in);

    TQDEM_F01_02_Limiter_couple(CoVSCtl_tqEfcReq_swc_in, /* BIN4 */
                                Cha_stHillAsi_swc_in, /* BIN0 */
                                CoPTSt_stEng_swc_in,
                                CoPt_noEgdGearCord_swc_in,
                                Ext_stGBxCf_swc_in,
                                FRM_bInhTqLimEM_swc_in);

    TQDEM_F01_03_Coordonner_limitation_EM(CoVSCtl_tqEfcReq_swc_in, /* BIN4 */
                                            TqLimEM_tqLimEM_swc_out /* BIN4 */);
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_F01_01_Pretraiter_les_entrees
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_01_Pretraiter_les_entrees(UInt8 cha_stepb_par, /* BIN0 */
                                                                    UInt8 frm_binhtqlimem_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.2 */
    if( ((UInt32)0 != (UInt32)cha_stepb_par) &&
        ((UInt32)4 != (UInt32)cha_stepb_par) &&
        ((UInt32)6 > (UInt32)cha_stepb_par) )
    {
        TqLimEM_stBrkParkElOn = DDS_TRUE;
    }
    else
    {
        TqLimEM_stBrkParkElOn = DDS_FALSE;
    }

    if((UInt32)5 < (UInt32)cha_stepb_par)
    {
        TqLimEM_bBrkParkElDft = DDS_TRUE;
    }
    else
    {
        TqLimEM_bBrkParkElDft = frm_binhtqlimem_par;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F01_02_Limiter_couple
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_Limiter_couple(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                           UInt8 cha_sthillasi_par, /* BIN0 */
                                                           UInt8 coptst_steng_par,
                                                           UInt8 copt_noegdgearcord_par,
                                                           UInt8 ext_stgbxcf_par,
                                                           UInt8 frm_binhtqlimem_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.3 */
    TQDEM_F01_02_01_Activer_Condition_EM(covsctl_tqefcreq_par, /* BIN4 */
                                           coptst_steng_par,
                                           copt_noegdgearcord_par,
                                           ext_stgbxcf_par);

    TQDEM_F01_02_02_Calculer_Limitation_EM(covsctl_tqefcreq_par, /* BIN4 */
                                           coptst_steng_par,
                                           copt_noegdgearcord_par);

    TQDEM_F01_02_03_Activer_Condition_Hill_Assist(covsctl_tqefcreq_par, /* BIN4 */
                                                   cha_sthillasi_par, /* BIN0 */
                                                   coptst_steng_par,
                                                   copt_noegdgearcord_par,
                                                   ext_stgbxcf_par,
                                                   frm_binhtqlimem_par);

    TQDEM_F01_02_04_Calculer_Limitation_Hill_Assis(covsctl_tqefcreq_par, /* BIN4 */
                                                    cha_sthillasi_par, /* BIN0 */
                                                    coptst_steng_par,
                                                    copt_noegdgearcord_par);
}

/*******************************************************************************
*
* Function Name : TQDEM_F01_02_01_Activer_Condition_EM
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_01_Activer_Condition_EM(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                   UInt8 coptst_steng_par,
                                                                   UInt8 copt_noegdgearcord_par,
                                                                   UInt8 ext_stgbxcf_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.5 */
    t_dds_m_edge_detected_event reset_edge_result;
    UInt32 temp_u32;
    UInt8 reset_flipflop;

    /**************************************************************************
    *       TqLimEM_bAcvLimEM_MP calculation
    ***************************************************************************/
    if( (TQDEM_STENG_ENGINE_RUNNING != (UInt32)coptst_steng_par) ||
        ((UInt32)DDS_FALSE == (UInt32)TqLimEM_stBrkParkElOn) ||
        ((SInt32)TqLimEM_tqThdAcv_C >= (SInt32)covsctl_tqefcreq_par) )
    {
        TqLimEM_bAcvLimEM_MP = DDS_FALSE;
    }
    else
    {
        if(TQDEM_BVM == (UInt32)ext_stgbxcf_par)
        {
            TqLimEM_bAcvLimEM_MP = DDS_TRUE;
        }
        else
        {
            if(TQDEM_NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par)
            {
                TqLimEM_bAcvLimEM_MP = DDS_FALSE;
            }
            else
            {
                TqLimEM_bAcvLimEM_MP = DDS_TRUE;
            }
        }
    }

    /**************************************************************************
    *       TqLimEM_tiDiLimEM_MP calculation
    ***************************************************************************/
    reset_edge_result = DDS_M_EDGE_DETECT(&tqdem_f01_02_01_edge_ptr,
                                            TqLimEM_bAcvLimEM_MP);

    if((UInt32)DDS_M_NEGATIVE_EDGE_DETECTED == (UInt32)reset_edge_result)
    {
        tqdem_f01_02_01_out_count = 0 * DEC2;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bAcvLimEM_MP)
        {
            /* DEC2 = DEC2 + (0.01 * DEC2)*/
            temp_u32 = tqdem_f01_02_01_out_count + 1;
            tqdem_f01_02_01_out_count = DDS_M_MIN(temp_u32 , TQDEM_CNT_MAX);
        }
        else
        {
            /* DO NOTHING */
        }
    }

    /* DEC1 = DEC2 / DEC1*/
    temp_u32 = tqdem_f01_02_01_out_count / DEC1;
    TqLimEM_tiDiLimEM_MP = (UInt8)DDS_M_MIN(temp_u32, TQDEM_10_DEC1);

    /**************************************************************************
    *       TqLimEM_bAcvLimEM calculation
    ***************************************************************************/
    /* reset RS flipflop calculation */
    if((UInt32)TqLimEM_tiTout_C < temp_u32)
    {
        reset_flipflop = DDS_TRUE;
    }
    else
    {
        if((SInt32)TqLimEM_tqLimEMRaw > (SInt32)covsctl_tqefcreq_par)
        {
            reset_flipflop = DDS_TRUE;
        }
        else
        {
            if( ((UInt32)DDS_FALSE == (UInt32)TqLimEM_bAcvLimEM) &&
                ((UInt32)DDS_FALSE != (UInt32)TqLimEM_bBrkParkElDft) )
            {
                reset_flipflop = DDS_TRUE;
            }
            else
            {
                reset_flipflop = DDS_FALSE;
            }
        }
    }

    if((UInt32)DDS_FALSE != (UInt32)reset_flipflop)
    {
        tqdem_f01_02_01_flipflop_out = DDS_FALSE;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bAcvLimEM_MP)
        {
            tqdem_f01_02_01_flipflop_out = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }


    if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bInhLimEM_C)
    {
        TqLimEM_bAcvLimEM = DDS_FALSE;
    }
    else
    {
        TqLimEM_bAcvLimEM = tqdem_f01_02_01_flipflop_out;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F01_02_02_Calculer_Limitation_EM
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_02_Calculer_Limitation_EM(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                       UInt8 coptst_steng_par,
                                                                       UInt8 copt_noegdgearcord_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.6 */
    SInt32 tqlimem_tqgrd_epb; /* BIN10 */

    /**************************************************************************
    *       TqLimEM_tqGrdEM_MP calculation
    ***************************************************************************/
    if((UInt32)DDS_FALSE == (UInt32)TqLimEM_stBrkParkElOn)
    {
        if(TQDEM_NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par)
        {
            TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOffNb0_C;
        }
        else
        {
            if(TQDEM_NOEGDGEARCORD_R1 == (UInt32)copt_noegdgearcord_par)
            {
                TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOffNb1_C;
            }
            else
            {
                if(TQDEM_NOEGDGEARCORD_R2 == (UInt32)copt_noegdgearcord_par)
                {
                    TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOffNb2_C;
                }
                else
                {
                    TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOffNb3_C;
                }
            }
        }
    }
    else
    {
        if(TQDEM_NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par)
        {
            TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOnNb0_C;
        }
        else
        {
            if(TQDEM_NOEGDGEARCORD_R1 == (UInt32)copt_noegdgearcord_par)
            {
                TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOnNb1_C;
            }
            else
            {
                if(TQDEM_NOEGDGEARCORD_R2 == (UInt32)copt_noegdgearcord_par)
                {
                    TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOnNb2_C;
                }
                else
                {
                    TqLimEM_tqGrdEM_MP = TqLimEM_tqGrdOnNb3_C;
                }
            }
        }
    }

    /**************************************************************************
    *       TqLimEM_tqLimEMRaw calculation
    ***************************************************************************/
    if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bAcvLimEM)
    {
        if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bBrkParkElDft)
        {
            /* BIN10 = (BIN0 * BIN10) / BIN0 */
            tqlimem_tqgrd_epb = ((SInt32)TqLimEM_tqGrdDft_C * BIN10) / (100 * BIN0);
        }
        else
        {
            /* BIN10 = (BIN0 * BIN10) / BIN0 */
            tqlimem_tqgrd_epb = ((SInt32)TqLimEM_tqGrdEM_MP * BIN10) / (100 * BIN0);
        }

        /* BIN10 = BIN10 + BIN10 */
        tqlimem_tqlimemraw_bin10 = tqlimem_tqlimemraw_bin10 + tqlimem_tqgrd_epb;
        tqlimem_tqlimemraw_bin10 = DDS_M_LIMIT(tqlimem_tqlimemraw_bin10,
                                               TQDEM_F01_02_TQMIN_BIN10,
                                               TQDEM_F01_02_TQMAX_BIN10);

        /* BIN4 = BIN10/BIN6 */
        TqLimEM_tqLimEMRaw = (SInt16)(tqlimem_tqlimemraw_bin10 / BIN6);
    }

    else
    {
        if( (TQDEM_STENG_ENGINE_RUNNING != (UInt32)coptst_steng_par) ||
            ((SInt32)TqLimEM_tqThdAcv_C > (SInt32)covsctl_tqefcreq_par) )
        {
            TqLimEM_tqLimEMRaw = (SInt16)DDS_M_MIN((SInt32)TqLimEM_tqThdAcv_C, (SInt32)covsctl_tqefcreq_par);
        }
        else
        {
            TqLimEM_tqLimEMRaw = (SInt16)(2000 * BIN4);
        }
        tqlimem_tqlimemraw_bin10 = (SInt32)TqLimEM_tqLimEMRaw * BIN6;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F01_02_03_Activer_Condition_Hill_Assist
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_03_Activer_Condition_Hill_Assist(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                           UInt8 cha_sthillasi_par, /* BIN0 */
                                                                           UInt8 coptst_steng_par,
                                                                           UInt8 copt_noegdgearcord_par,
                                                                           UInt8 ext_stgbxcf_par,
                                                                           UInt8 frm_binhtqlimem_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.7 */
    t_dds_m_edge_detected_event reset_edge_result;
    UInt32 temp_u32;
    UInt8 reset_flipflop;
    UInt8 condition;

    /**************************************************************************
    *       TqLimEM_bAcvLimHillAsi_MP calculation
    ***************************************************************************/
    if( (TQDEM_STENG_ENGINE_RUNNING != (UInt32)coptst_steng_par) ||
        (TQDEM_HILLASI_HOLDING != (UInt32)cha_sthillasi_par) ||
        ((SInt32)TqLimEM_tqThdAcvHillAsi_C >= (SInt32)covsctl_tqefcreq_par) )
    {
        TqLimEM_bAcvLimHillAsi_MP = DDS_FALSE;
    }
    else
    {
        if(TQDEM_BVM == (UInt32)ext_stgbxcf_par)
        {
            TqLimEM_bAcvLimHillAsi_MP = DDS_TRUE;
        }
        else
        {
            if(TQDEM_NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par)
            {
                TqLimEM_bAcvLimHillAsi_MP = DDS_FALSE;
            }
            else
            {
                TqLimEM_bAcvLimHillAsi_MP = DDS_TRUE;
            }
        }
    }

    /**************************************************************************
    *       TqLimEM_tiDiLimHillAsi_MP calculation
    ***************************************************************************/
    reset_edge_result = DDS_M_EDGE_DETECT(&tqdem_f01_02_03_edge_ptr,
                                            TqLimEM_bAcvLimHillAsi_MP);

    if((UInt32)DDS_M_NEGATIVE_EDGE_DETECTED == (UInt32)reset_edge_result)
    {
        tqdem_f01_02_03_out_count = 0 * DEC2;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bAcvLimHillAsi_MP)
        {
            /* DEC2 = DEC2 + (0.01 * DEC2)*/
            temp_u32 = tqdem_f01_02_03_out_count + 1;
            tqdem_f01_02_03_out_count = DDS_M_MIN(temp_u32 , TQDEM_CNT_MAX);
        }
        else
        {
            /* DO NOTHING */
        }
    }

    /* DEC1 = DEC2 / DEC1*/
    temp_u32 = tqdem_f01_02_03_out_count / DEC1;
    TqLimEM_tiDiLimHillAsi_MP = (UInt8)DDS_M_MIN(temp_u32, TQDEM_10_DEC1);

    /**************************************************************************
    *       TqLimEM_bAcvLimHillAsi calculation
    ***************************************************************************/
    /* reset RS flipflop calculation */
    if((UInt32)TqLimEM_tiToutHillAsi_C < temp_u32)
    {
        reset_flipflop = DDS_TRUE;
    }
    else
    {
        if((SInt32)TqLimEM_tqLimHillAsiRaw > (SInt32)covsctl_tqefcreq_par)
        {
            reset_flipflop = DDS_TRUE;
        }
        else
        {
            if( (TQDEM_HILLASI_NOHOLDING < (UInt32)cha_sthillasi_par) ||
                ((UInt32)DDS_FALSE != (UInt32)frm_binhtqlimem_par) )
            {
                condition = DDS_TRUE;
            }
            else
            {
                condition = DDS_FALSE;
            }

            if( ((UInt32)DDS_FALSE == (UInt32)TqLimEM_bAcvLimHillAsi) &&
                ((UInt32)DDS_FALSE != (UInt32)condition) )
            {
                reset_flipflop = DDS_TRUE;
            }
            else
            {
                reset_flipflop = DDS_FALSE;
            }
        }
    }

    if((UInt32)DDS_FALSE != (UInt32)reset_flipflop)
    {
        tqdem_f01_02_03_flipflop_out = DDS_FALSE;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bAcvLimHillAsi_MP)
        {
            tqdem_f01_02_03_flipflop_out = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }



    if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bInhLimHillAsi_C)
    {
        TqLimEM_bAcvLimHillAsi = DDS_FALSE;
    }
    else
    {
        TqLimEM_bAcvLimHillAsi = tqdem_f01_02_03_flipflop_out;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F01_02_04_Calculer_Limitation_Hill_Assis
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_04_Calculer_Limitation_Hill_Assis(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                           UInt8 cha_sthillasi_par, /* BIN0 */
                                                                           UInt8 coptst_steng_par,
                                                                           UInt8 copt_noegdgearcord_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.8 */
    UInt8 turn_on_delay_input;
    UInt8 turn_on_delay_output;
    SInt32 tqlimem_tqgrd_epb;

    /**************************************************************************
    *       turn_on_delay calculation
    ***************************************************************************/
    if(TQDEM_HILLASI_HOLDING == (UInt32)cha_sthillasi_par)
    {
        turn_on_delay_input = DDS_TRUE;
    }
    else
    {
        turn_on_delay_input = DDS_FALSE;
    }
    turn_on_delay_output = DDS_M_TURN_ON_DELAY(turn_on_delay_input,
                                                DDS_TQDEM_1MS_U32_TIME,
                                                (UInt32)TqLimEM_tiGrdHillAsiRls_C * DEC2,
                                                &tqdem_f01_02_04_turn_on_delay_ptr);

    /**************************************************************************
    *       TqLimEM_tqGrdHillAsi_MP calculation
    ***************************************************************************/
    if((UInt32)DDS_FALSE == (UInt32)turn_on_delay_output)
    {
        if(TQDEM_NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par)
        {
            TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOffNb0_C;
        }
        else
        {
            if(TQDEM_NOEGDGEARCORD_R1 == (UInt32)copt_noegdgearcord_par)
            {
                TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOffNb1_C;
            }
            else
            {
                if(TQDEM_NOEGDGEARCORD_R2 == (UInt32)copt_noegdgearcord_par)
                {
                    TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOffNb2_C;
                }
                else
                {
                    TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOffNb3_C;
                }
            }
        }
    }
    else
    {
        if(TQDEM_NOEGDGEARCORD_N == (UInt32)copt_noegdgearcord_par)
        {
            TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOnNb0_C;
        }
        else
        {
            if(TQDEM_NOEGDGEARCORD_R1 == (UInt32)copt_noegdgearcord_par)
            {
                TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOnNb1_C;
            }
            else
            {
                if(TQDEM_NOEGDGEARCORD_R2 == (UInt32)copt_noegdgearcord_par)
                {
                    TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOnNb2_C;
                }
                else
                {
                    TqLimEM_tqGrdHillAsi_MP = TqLimEM_tqGrdHillAsiOnNb3_C;
                }
            }
        }
    }

    /**************************************************************************
    *       TqLimEM_tqLimHillAsiRaw calculation
    ***************************************************************************/
    if((UInt32)DDS_FALSE != (UInt32)TqLimEM_bAcvLimHillAsi)
    {
        if(TQDEM_HILLASI_DEFAULT == (UInt32)cha_sthillasi_par)
        {
            /* BIN10 = (BIN0 * BIN10) / BIN0 */
            tqlimem_tqgrd_epb = ((SInt32)TqLimEM_tqGrdHillAsiDft_C * BIN10) / (100 * BIN0);
        }
        else
        {
            /* BIN10 = (BIN0 * BIN10) / BIN0 */
            tqlimem_tqgrd_epb = ((SInt32)TqLimEM_tqGrdHillAsi_MP * BIN10) / (100 * BIN0);
        }

        /* BIN10 = BIN10 + BIN10 */
        tqlimem_tqlimhillasiraw_bin10 = tqlimem_tqlimhillasiraw_bin10 + tqlimem_tqgrd_epb;
        tqlimem_tqlimhillasiraw_bin10 = DDS_M_LIMIT(tqlimem_tqlimhillasiraw_bin10,
                                               TQDEM_F01_02_TQMIN_BIN10,
                                               TQDEM_F01_02_TQMAX_BIN10);
        /* BIN4 = BIN10/BIN6 */
        TqLimEM_tqLimHillAsiRaw = (SInt16)(tqlimem_tqlimhillasiraw_bin10 / BIN6);
    }

    else
    {
        if( (TQDEM_STENG_ENGINE_RUNNING != (UInt32)coptst_steng_par) ||
            ((SInt32)TqLimEM_tqThdAcvHillAsi_C > (SInt32)covsctl_tqefcreq_par) )
        {
            TqLimEM_tqLimHillAsiRaw = (SInt16)DDS_M_MIN((SInt32)TqLimEM_tqThdAcvHillAsi_C, (SInt32)covsctl_tqefcreq_par);
        }
        else
        {
            TqLimEM_tqLimHillAsiRaw = (SInt16)(2000 * BIN4);
        }
        tqlimem_tqlimhillasiraw_bin10 = (SInt32)TqLimEM_tqLimHillAsiRaw * BIN6;
    }
}

/*******************************************************************************
*
* Function Name : TQDEM_F01_03_Coordonner_limitation_EM
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_03_Coordonner_limitation_EM(SInt16 covsctl_tqefcreq_par, /* BIN4 */
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqlimem_tqlimem_ptr /* BIN4 */)


{
    /* SSTG_REQ_TAG: CSMT_CGMT06_2031.FR.4 */
    SInt32 temp_s32;

    temp_s32 = DDS_M_MIN((SInt32)TqLimEM_tqLimEMRaw, (SInt32)covsctl_tqefcreq_par);
    *tqlimem_tqlimem_ptr = (SInt16)DDS_M_MIN(temp_s32, (SInt32)TqLimEM_tqLimHillAsiRaw);
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Coord_Lim_Em_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Coord_Lim_Em_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEM_swc_out /* BIN4 */)
{
    /* Init global variables */
    tqdem_f01_02_01_out_count = 0 * DEC2;
    tqdem_f01_02_03_out_count = 0 * DEC2;

    /* Init prev and local */
    TqLimEM_tqLimEMRaw = (SInt16)0;
    tqlimem_tqlimemraw_bin10 = 0;
    TqLimEM_tqLimHillAsiRaw = (SInt16)0;
    tqlimem_tqlimhillasiraw_bin10 = 0;
    TqLimEM_bAcvLimEM = DDS_FALSE;
    TqLimEM_bAcvLimHillAsi = DDS_FALSE;
    tqdem_f01_02_01_flipflop_out = DDS_FALSE;
    tqdem_f01_02_03_flipflop_out = DDS_FALSE;

    /* Init macros */
    DDS_M_EDGE_DETECT_INIT(&tqdem_f01_02_01_edge_ptr,
                            DDS_TRUE);
    DDS_M_EDGE_DETECT_INIT(&tqdem_f01_02_03_edge_ptr,
                            DDS_TRUE);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,
                                &tqdem_f01_02_04_turn_on_delay_ptr);

    /* Init output */
    *TqLimEM_tqLimEM_swc_out = (SInt16)(0 * BIN4);
}


#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

