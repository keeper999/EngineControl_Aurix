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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Allow_Inhibit_Stt.c
* Version int :/main/L02_02/1 Date: 21/3/2012 15 h 8 m User:esnault 
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_020_IMPL1
*    comments :For TqAdpCmp_11_0_e6 /  correction FDS A0204960
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 7/3/2012 16 h 9 m User:halouane 
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_020_IMPL1
*    comments :For TqAdpCmp_11_0_e6 /  correction FDS A0204960
* Version int :/main/L02_01/3 Date: 14/9/2011 16 h 28 m User:meme
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_011_IMPL1_D
*    comments :add code optimisation
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 6/9/2011 15 h 19 m User:halouane
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_011_IMPL1_D
*    comments :add code optimisation
* Version int :/main/L02_01/2 Date: 6/6/2011 10 h 27 m User:meme
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_011_IMPL1
*    comments :change range and type of TqAdp_tiDlyMonRunCdnNxtCkg_C
* Version dev :\main\branch_lemort_tqadpcmp_dev\3 Date: 31/5/2011 11 h 4 m User:lemort
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_011_IMPL1
*    comments :change range and type of TqAdp_tiDlyMonRunCdnNxtCkg_C
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 26/5/2011 15 h 3 m User:lemort
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_010_IMPL1_D
*    comments :QAC warning
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 26/5/2011 14 h 24 m User:lemort
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_010_IMPL1_D
*    comments :include nvm.h
* Version int :/main/L02_01/1 Date: 18/11/2010 12 h 49 m User:meme
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 17/11/2010 16 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 16/11/2010 16 h 53 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L02_010_IMPL1
*    comments :For TqAdpCmp 10.2
* Version int :/main/L01_01/2 Date: 12/10/2010 9 h 44 m User:meme
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL2_D
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 22/9/2010 15 h 9 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL2_D
*    comments :for TqAdpCmp euro 6
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 17 m User:esnault
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\14 Date: 13/9/2010 9 h 59 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\13 Date: 10/9/2010 10 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\12 Date: 2/9/2010 11 h 37 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\11 Date: 2/9/2010 11 h 34 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\10 Date: 18/8/2010 8 h 54 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 18/8/2010 8 h 46 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 2/8/2010 12 h 15 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 22/7/2010 16 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 9/7/2010 16 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 8/7/2010 18 h 4 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 7/7/2010 9 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 25/6/2010 16 h 36 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 21 m User:morisseau
*    TWK_model:TQADPCMP_Allow_Inhibit_Stt_L01_010_IMPL1
*    comments :for TqAdpCmp: just structure of file
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

/* DDS Library */
#include "dds_lib.h"


/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "TqAdpCmp.h"
#include "TQADPCMP_nvm.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 32-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_32bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_32BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_8bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_8BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeutIni[TQADPCMP_8_SIZE]; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRedIni[TQADPCMP_8_SIZE]; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnDragRed;
extern VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnNeut;
extern VAR(UInt8, AUTOMATIC) TqAdp_bDragRed;
extern VAR(UInt8, AUTOMATIC) TqAdp_idxTEng; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"



/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* 16-bits calibrations definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTEng_A[TQADPCMP_8_SIZE]; /* BIN0 */
#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"



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
#define TQADPCMP_START_SEC_CALIB_32BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) TqAdp_dstVeh_C = (CONST(UInt32, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt32, AUTOMATIC) TqAdp_noNbKm_C = (CONST(UInt32, AUTOMATIC))(500 * BIN0);
#define TQADPCMP_STOP_SEC_CALIB_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tCoThdInhStop_C = (CONST(SInt16, AUTOMATIC))(20 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_tiDlyAdpLrn_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_tiDlyStabTEng_C = (CONST(UInt16, AUTOMATIC))(1200 * DEC0);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_noAdpLrn_C = (CONST(UInt8, AUTOMATIC))(3 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_noKmRst_C = (CONST(UInt8, AUTOMATIC))(3 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_noKmThd_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_tiDlyMonRunCdnNxtCkg_C = (CONST(UInt8, AUTOMATIC))(0 * DEC2);
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_bAuthInhSTT_T
[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(1 * BIN0),
(UInt16)(1 * BIN0), (UInt16)(1 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqThdCritNxtCkgDragRed_T
[TQADPCMP_8_SIZE] = {
(SInt16)(4 * BIN4), (SInt16)(4 * BIN4), (SInt16)(4 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqThdCritNxtCkgNeut_T
[TQADPCMP_8_SIZE] = {
(SInt16)(4 * BIN4), (SInt16)(4 * BIN4), (SInt16)(4 * BIN4),
(SInt16)(2 * BIN4), (SInt16)(2 * BIN4), (SInt16)(1 * BIN4),
(SInt16)(1 * BIN4), (SInt16)(1 * BIN4)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_bauthinhstt_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqthdcritnxtckgdragred_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqthdcritnxtckgneut_t_sav;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_edge_detect_1;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_edge_detect_2;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_edge_detect_3;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_edge_detect_4;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_01_02_05_03_turn_on_delay;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_01_02_05_05_turn_on_delay;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_01_02_06_01_turn_off_delay;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_05_02_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_06_01_unitdelay;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_06_03_unitdelay;
STATIC VAR(UInt8, AUTOMATIC) tqadp_idxteng_stt_loc; /* BIN0 */
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdragred_stt_loc;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_32BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt32, AUTOMATIC) TqAdp_dstVehHldClc_MP; /* BIN0 */
_DDS_STATIC_ VAR(UInt32, AUTOMATIC) TqAdp_dstVeh_MP; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_32BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bAuthInhEngStop;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCdn1RstInhSTT_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCdn2RstInhSTT_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnSTT;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bMonRunORngSTT;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bNbKm;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bRstAdpLrn;
/* <PRQA_COMMENT><3229> Variable is used as a mesure point </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bRstInhSTT_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_ctDstClc_MP; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_noAdpLrn_MP; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_noAdp_MP; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bMonRunCdnNxtCkgLrn;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_stCdnNxtCkgLrnOn;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_BAUTHINHSTT_T_APM = {
&tqadp_bauthinhstt_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_bAuthInhSTT_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQTHDCRITNXTCKGDRAGRED_T_APM = {
&tqadp_tqthdcritnxtckgdragred_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqThdCritNxtCkgDragRed_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQTHDCRITNXTCKGNEUT_T_APM = {
&tqadp_tqthdcritnxtckgneut_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqThdCritNxtCkgNeut_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_Autoriser_Inhibition_Stop_STT(
                                           UInt8 coptst_steng_par,
                                           UInt32 ext_dstvehmes_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 tqadp_bmonrunorngdragred_par,
                                           UInt8 tqadp_bmonrunorngneut_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_binhengstop_ptr );

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_01_Determiner_Etat_Boite(
                                           UInt8 tqadp_bmonrunorngdragred_par,
                                           UInt8 tqadp_bmonrunorngneut_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_02_Calculer_Nombre_Forfait_Kilometrique(
                                           UInt32 ext_dstvehmes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_03_Calculer_Nombre_Apprentissage(
                                           UInt8 coptst_steng_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_04_Autoriser_Inhibition_Stop_STT(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_05_Valider_Autorisation_Inhibition_Stop_STT(
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_binhengstop_ptr );

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_Determiner_Criticite_Prochain_Demarrage(
                                           UInt8 frm_binhadp_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_stcdnnxtckg_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_01_Determiner_Conditions_Activation(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_02_Determiner_Criticite(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_03_Determiner_Criticite_Applicable(
                                           UInt8 frm_binhadp_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_stcdnnxtckg_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Allow_Inhibit_Stt
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Allow_Inhibit_Stt(UInt8 CoPTSt_stEng_swc_in,
                                           UInt32 Ext_dstVehMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhAdp_swc_in,
                                           UInt8 TqAdp_bMonRunORngDragRed_swc_in,
                                           UInt8 TqAdp_bMonRunORngNeut_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bInhEngStop_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_stCdnNxtCkg_swc_out)
{
    tqadp_idxteng_stt_loc = TqAdp_idxTEng;
    tqadp_bdragred_stt_loc = TqAdp_bDragRed;

    TQADPCMP_01_02_05_Autoriser_Inhibition_Stop_STT(CoPTSt_stEng_swc_in,
                                                    Ext_dstVehMes_swc_in, /* BIN0 */
                                                    Ext_tCoMes_swc_in, /* BIN0 */
                                                    TqAdp_bMonRunORngDragRed_swc_in,
                                                    TqAdp_bMonRunORngNeut_swc_in,
                                                    TqAdp_bInhEngStop_swc_out );

    TQADPCMP_01_02_06_Determiner_Criticite_Prochain_Demarrage(FRM_bInhAdp_swc_in,
                                                              TqAdp_stCdnNxtCkg_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_05_Autoriser_Inhibition_Stop_STT
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_Autoriser_Inhibition_Stop_STT(
                                           UInt8 coptst_steng_par,
                                           UInt32 ext_dstvehmes_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 tqadp_bmonrunorngdragred_par,
                                           UInt8 tqadp_bmonrunorngneut_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_binhengstop_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.24.1 */
    TQADPCMP_01_02_05_01_Determiner_Etat_Boite(tqadp_bmonrunorngdragred_par,
                                               tqadp_bmonrunorngneut_par);

    TQADPCMP_01_02_05_02_Calculer_Nombre_Forfait_Kilometrique(ext_dstvehmes_par /* BIN0 */);

    TQADPCMP_01_02_05_03_Calculer_Nombre_Apprentissage(coptst_steng_par);

    TQADPCMP_01_02_05_04_Autoriser_Inhibition_Stop_STT();

    TQADPCMP_01_02_05_05_Valider_Autorisation_Inhibition_Stop_STT(ext_tcomes_par,
                                                                  tqadp_binhengstop_ptr );
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_05_01_Determiner_Etat_Boite
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_01_Determiner_Etat_Boite(
                                           UInt8 tqadp_bmonrunorngdragred_par,
                                           UInt8 tqadp_bmonrunorngneut_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.57.0 */
    if((UInt32)tqadp_bdragred_stt_loc!=(UInt32)DDS_FALSE)
    {
        TqAdp_bMonRunORngSTT= tqadp_bmonrunorngdragred_par;
        TqAdp_bCorLrnSTT = TqAdp_bCorLrnDragRed;
    }
    else
    {
        TqAdp_bMonRunORngSTT = tqadp_bmonrunorngneut_par;
        TqAdp_bCorLrnSTT = TqAdp_bCorLrnNeut;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_05_02_Calculer_Nombre_Forfait_Kilometrique
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_02_Calculer_Nombre_Forfait_Kilometrique(
                                           UInt32 ext_dstvehmes_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.25.1 */
    SInt32 tqadpcmp_val;
    UInt32 tqadpcmp_val2;
    t_dds_m_edge_detected_event tqadpcmp_edge_out;

    TqAdp_dstVeh_MP = (UInt32)DDS_M_MAX(((SInt32)ext_dstvehmes_par-(SInt32)TqAdp_dstVeh_C),0);

    if((UInt32)tqadpcmp_01_02_05_02_init != (UInt32)DDS_TRUE)
    {
        tqadpcmp_01_02_05_02_init = DDS_TRUE;
        TqAdp_dstVehHldClc_MP = TqAdpCmp_sNV_Z1_CST_32BIT.TqAdp_dstVehHld_NV;
        TqAdp_ctDstClc_MP = TqAdpCmp_sNV_Z1_CST_8BIT.TqAdp_ctDst_NV;
    }
    else
    {
        /* nothing to do */
    }

    tqadpcmp_val = (SInt32)TqAdp_dstVeh_MP - (SInt32)TqAdp_dstVehHldClc_MP;

    if(tqadpcmp_val>=(SInt32)TqAdp_noNbKm_C)
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_1,DDS_TRUE);
    }
    else
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_1,DDS_FALSE);
    }

    if(tqadpcmp_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        TqAdp_bNbKm = DDS_TRUE;
        TqAdp_dstVehHldClc_MP = TqAdp_dstVeh_MP;
        tqadpcmp_val2 = (UInt32)TqAdp_ctDstClc_MP+1;
    }
    else
    {
        TqAdp_bNbKm = DDS_FALSE;
        tqadpcmp_val2 = (UInt32)TqAdp_ctDstClc_MP;
    }


    if(tqadpcmp_val2>=(UInt32)TqAdp_noKmRst_C)
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_2,DDS_TRUE);
    }
    else
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_2,DDS_FALSE);
    }

    if(tqadpcmp_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        TqAdp_ctDstClc_MP = 0;
    }
    else
    {
        TqAdp_ctDstClc_MP = (UInt8)DDS_M_MIN(tqadpcmp_val2,255);
    }

    if(tqadpcmp_val2>=(UInt32)TqAdp_noKmThd_C)
    {
        TqAdp_bRstAdpLrn = DDS_TRUE;
    }
    else
    {
        TqAdp_bRstAdpLrn = DDS_FALSE;
    }

    TqAdpCmp_sNV_Z1_CST_32BIT.TqAdp_dstVehHld_NV = TqAdp_dstVehHldClc_MP;
    TqAdpCmp_sNV_Z1_CST_8BIT.TqAdp_ctDst_NV = TqAdp_ctDstClc_MP;
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_05_03_Calculer_Nombre_Apprentissage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_03_Calculer_Nombre_Apprentissage(
                                           UInt8 coptst_steng_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.27.2 */
    t_dds_m_edge_detected_event tqadpcmp_edge_out;
    UInt8 tqadpcmp_turn_on_out;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;


    tqadpcmp_turn_on_out = DDS_M_TURN_ON_DELAY(TqAdp_bMonRunORngSTT,
                                               tqadpcmp_te,
                                               ((UInt32)TqAdp_tiDlyAdpLrn_C*DEC1),
                                               &tqadpcmp_01_02_05_03_turn_on_delay);

    tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_4,tqadpcmp_turn_on_out);

    if(tqadpcmp_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        TqAdp_noAdp_MP = (UInt8)DDS_M_MIN((UInt32)TqAdp_noAdpLrn_MP+1,20);
    }
    else
    {
        TqAdp_noAdp_MP = TqAdp_noAdpLrn_MP;
    }

    if((UInt32)coptst_steng_par!=1)
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_3,DDS_FALSE);
    }
    else
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_edge_detect_3,DDS_TRUE);
    }

    if(tqadpcmp_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        TqAdp_noAdpLrn_MP = (UInt8)0;
    }
    else
    {
        TqAdp_noAdpLrn_MP = TqAdp_noAdp_MP;
    }

    if((UInt32)TqAdp_noAdpLrn_MP>=(UInt32)TqAdp_noAdpLrn_C)
    {
        TqAdp_bCdn1RstInhSTT_MP = DDS_TRUE;
    }
    else
    {
        TqAdp_bCdn1RstInhSTT_MP = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_05_04_Autoriser_Inhibition_Stop_STT
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_04_Autoriser_Inhibition_Stop_STT(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.58.0 */
    if((UInt32)TqAdp_bRstAdpLrn!=(UInt32)DDS_FALSE)
    {
        TqAdp_bCdn2RstInhSTT_MP = DDS_FALSE;
    }
    else
    {
        TqAdp_bCdn2RstInhSTT_MP = TqAdp_bCorLrnSTT;
    }

    if(  ((UInt32)TqAdp_bCdn2RstInhSTT_MP == (UInt32)DDS_TRUE)
       ||((UInt32)TqAdp_bCdn1RstInhSTT_MP == (UInt32)DDS_TRUE))
    {
        TqAdp_bRstInhSTT_MP = DDS_TRUE;
        TqAdp_bAuthInhEngStop = DDS_FALSE;
    }
    else
    {
        TqAdp_bRstInhSTT_MP = DDS_FALSE;
        if((UInt32)TqAdp_bNbKm == (UInt32)DDS_TRUE)
        {
            TqAdp_bAuthInhEngStop = DDS_TRUE;
        }
        else
        {
            /* nothing to do */
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_05_05_Valider_Autorisation_Inhibition_Stop_STT
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_05_05_Valider_Autorisation_Inhibition_Stop_STT(
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_binhengstop_ptr )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.28.1 */
    UInt32 tqadpcmp_te;
    UInt32 tqadpcmp_turn_on_out;
    UInt32 tqadpcmp_map_out;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    /* BIN0 > (BIN2 / BIN2) */
    if(((SInt32)ext_tcomes_par * BIN2) > (SInt32)TqAdp_tCoThdInhStop_C)
    {
        tqadpcmp_turn_on_out = DDS_M_TURN_ON_DELAY(DDS_TRUE,
                                                   tqadpcmp_te,
                                                   ((UInt32)TqAdp_tiDlyStabTEng_C*DEC3),
                                                   &tqadpcmp_01_02_05_05_turn_on_delay);
    }
    else
    {
        tqadpcmp_turn_on_out = DDS_M_TURN_ON_DELAY(DDS_FALSE,
                                                  tqadpcmp_te,
                                                  ((UInt32)TqAdp_tiDlyStabTEng_C*DEC3),
                                                  &tqadpcmp_01_02_05_05_turn_on_delay);
    }

    if(  ((UInt32)TqAdp_bAuthInhEngStop == (UInt32)DDS_FALSE)
       ||(tqadpcmp_turn_on_out == (UInt32)DDS_FALSE) )
    {
        *tqadp_binhengstop_ptr = DDS_FALSE;
    }
    else
    {
        tqadpcmp_map_out = (UInt32) DDS_M_MAP2D_U16(&TQADP_BAUTHINHSTT_T_APM,tqadp_idxteng_stt_loc);
        if(tqadpcmp_map_out == (UInt32)DDS_FALSE)
        {
            *tqadp_binhengstop_ptr = DDS_FALSE;
        }
        else
        {
            *tqadp_binhengstop_ptr = DDS_TRUE;
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_06_Determiner_Criticite_Prochain_Demarrage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_Determiner_Criticite_Prochain_Demarrage(
                                           UInt8 frm_binhadp_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_stcdnnxtckg_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.40.0 */
    TQADPCMP_01_02_06_01_Determiner_Conditions_Activation();

    if((UInt32)TqAdp_bMonRunCdnNxtCkgLrn == (UInt32)DDS_TRUE)
    {
        TQADPCMP_01_02_06_02_Determiner_Criticite();
    }
    else
    {
        /* nothing to do */
    }

    TQADPCMP_01_02_06_03_Determiner_Criticite_Applicable(frm_binhadp_par,
                                                         tqadp_stcdnnxtckg_ptr);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_06_01_Determiner_Conditions_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_01_Determiner_Conditions_Activation(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.59.0 */
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;


    TqAdp_bMonRunCdnNxtCkgLrn = DDS_M_TURN_OFF_DELAY(tqadpcmp_01_02_06_01_unitdelay,
                                                 tqadpcmp_te,
                                                 ((UInt32)TqAdp_tiDlyMonRunCdnNxtCkg_C*DEC1),
                                                 &tqadpcmp_01_02_06_01_turn_off_delay);

    tqadpcmp_01_02_06_01_unitdelay = DDS_FALSE;


}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_06_02_Determiner_Criticite
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_02_Determiner_Criticite(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.60.0 */
    SInt32 tqadpcmp_svalue;
    SInt32 tqadpcmp_svalue2;

    if((UInt32)tqadp_bdragred_stt_loc!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_svalue = (SInt32)TqAdp_prm_tqCorLrnDragRedIni[(UInt32)((SInt32)tqadp_idxteng_stt_loc-1)];
        tqadpcmp_svalue2 = (SInt32)DDS_M_MAP2D_US16(&TQADP_TQTHDCRITNXTCKGDRAGRED_T_APM,(UInt16)tqadp_idxteng_stt_loc);
    }
    else
    {
        tqadpcmp_svalue = (SInt32)TqAdp_prm_tqCorLrnNeutIni[(UInt32)((SInt32)tqadp_idxteng_stt_loc-1)];
        tqadpcmp_svalue2 = (SInt32)DDS_M_MAP2D_US16(&TQADP_TQTHDCRITNXTCKGNEUT_T_APM,(UInt16)tqadp_idxteng_stt_loc);
    }

    if(tqadpcmp_svalue>tqadpcmp_svalue2)
    {
        TqAdp_stCdnNxtCkgLrnOn = (UInt8)TQADPCMP_DEFAVORABLE;
    }
    else if(-tqadpcmp_svalue>tqadpcmp_svalue2)
    {
        TqAdp_stCdnNxtCkgLrnOn = (UInt8)TQADPCMP_FAVORABLE;
    }
    else
    {
        TqAdp_stCdnNxtCkgLrnOn = (UInt8)TQADPCMP_NOMINAL;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_06_03_Determiner_Criticite_Applicable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_06_03_Determiner_Criticite_Applicable(
                                           UInt8 frm_binhadp_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_stcdnnxtckg_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.61.0 */
    if((UInt32)frm_binhadp_par != (UInt32)DDS_FALSE)
    {
        tqadpcmp_01_02_06_03_unitdelay = DDS_TRUE;
    }
    else
    {
        /* nothing to do */
    }

    if((UInt32)tqadpcmp_01_02_06_03_unitdelay != (UInt32)DDS_FALSE)
    {
        *tqadp_stcdnnxtckg_ptr = (UInt8)TQADPCMP_DEFAVORABLE;
    }
    else
    {
        *tqadp_stcdnnxtckg_ptr = TqAdp_stCdnNxtCkgLrnOn;
    }
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Allow_Inhibit_Stt_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Allow_Inhibit_Stt_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bInhEngStop_swc_out ,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_stCdnNxtCkg_swc_out)
{
    *TqAdp_bInhEngStop_swc_out = DDS_FALSE;
    *TqAdp_stCdnNxtCkg_swc_out = (UInt8)TQADPCMP_NOMINAL;

    tqadpcmp_01_02_05_02_init = DDS_FALSE;

    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_edge_detect_1,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_edge_detect_2,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_edge_detect_3,DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_edge_detect_4,DDS_FALSE);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_05_03_turn_on_delay);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_05_05_turn_on_delay);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_06_01_turn_off_delay);

    tqadpcmp_01_02_06_01_unitdelay = DDS_TRUE;
    tqadpcmp_01_02_06_03_unitdelay = DDS_FALSE;

    TqAdp_noAdpLrn_MP = 0;
    TqAdp_bAuthInhEngStop = DDS_FALSE;

    TqAdp_stCdnNxtCkgLrnOn = (UInt8)TQADPCMP_NOMINAL;
    TqAdp_bMonRunCdnNxtCkgLrn = DDS_FALSE;
    TqAdp_bNbKm = DDS_FALSE;
    TqAdp_noAdp_MP = (UInt8)(0 * BIN0);
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

