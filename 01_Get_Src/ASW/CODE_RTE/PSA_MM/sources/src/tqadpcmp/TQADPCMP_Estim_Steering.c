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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Estim_Steering.c
* Version int :/main/L02_02/1 Date: 21/3/2012 15 h 9 m User:esnault 
*    TWK_model:TQADPCMP_Estim_Steering_L02_020_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 29/2/2012 15 h 45 m User:halouane 
*    TWK_model:TQADPCMP_Estim_Steering_L02_020_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_01/3 Date: 14/9/2011 16 h 27 m User:meme
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 14/9/2011 14 h 25 m User:halouane
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_demezil_tqadpcmp_dev\1 Date: 28/4/2011 15 h 10 m User:demezil
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2_D
*    comments :to reduce CPU load
* Version int :/main/L02_01/2 Date: 12/10/2010 9 h 45 m User:meme
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2_D
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/9/2010 8 h 46 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2_D
*    comments :for TqAdpCmp euro 6
* Version int :/main/L02_01/1 Date: 13/9/2010 14 h 20 m User:esnault
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 8/9/2010 10 h 57 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 8/9/2010 10 h 19 m User:veillard
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL2
*    comments :for TqAdpCmp 10.0 - euro6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 3/9/2010 12 h 29 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 18/8/2010 9 h 11 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 21/7/2010 15 h 19 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 28/6/2010 15 h 40 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Steering_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 7 m User:boucher
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL3
*    comments :TqCmp_idxStgPmpTyp_C has to be volatile
* Version dev :\main\branch_moisan_tqadpcmp_validation\4 Date: 15/10/2008 17 h 8 m User:moisan
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL3
*    comments :TqCmp_idxStgPmpTyp_C has to be volatile
* Version dev :\main\branch_moisan_tqadpcmp_validation\3 Date: 15/10/2008 10 h 22 m User:moisan
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL3
*    comments :Wrong initialisation
* Version dev :\main\branch_moisan_tqadpcmp_validation\2 Date: 15/10/2008 10 h 7 m User:moisan
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL3
*    comments :Wrong initialisation with TqCmp_facCoefFiltTqStgPmpLoss
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 10/10/2008 13 h 11 m User:moisan
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL2
*    comments :TqCmp_pStgPmpThd_C: wrong initialisation
* Version dev :\main\branch_miaille\3 Date: 6/10/2008 11 h 45 m User:miaille
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL2
*    comments :Change "TqCmp_idxStgPmpTyp_swc_in" with "TqCmp_idxStgPmpTyp_par".
* Version dev :\main\branch_miaille\2 Date: 6/10/2008 11 h 4 m User:miaille
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL2
*    comments :Fix test feedback errors.
* Version dev :\main\branch_miaille\1 Date: 15/9/2008 14 h 13 m User:miaille
*    TWK_model:TQADPCMP_Estim_Steering_L01_010_IMPL1
*    comments :Implements specification CSMT_CGMT06_1929_v2_0.
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

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

/* Used for switch case with Ext_stStgPmpCf */
#define TQADPCMP_PAS_DE_DA_PAR_POMPE_ATTELEE                                    (UInt32) 0
#define TQADPCMP_DA_AVEC_POMPE_ATTELEE_AVEC_UN_CAPTEUR_BUTE_ON_OFF              (UInt32) 1
#define TQADPCMP_DA_AVEC_POMPE_ATTELEE_AVEC_UN_CAPTEUR_DE_PRESSION_LINEAIRE     (UInt32) 2

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
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pStgPmpThd_C = (CONST(UInt16, AUTOMATIC))(10 * BIN2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_spdVehDftStgPmp_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpLossMax_C = (CONST(UInt16, AUTOMATIC))(30 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpLossMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpThdLossOff_C = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpThdLossOn_C = (CONST(UInt16, AUTOMATIC))(15 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facFilTqStgLoss_C = (CONST(UInt16, AUTOMATIC))(0.05 * BIN10);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqStgLossDown_T
[TQADPCMP_5_SIZE] = {
(UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10),
(UInt16)(0.1 * BIN10), (UInt16)(0.1 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqStgLossUp_T
[TQADPCMP_5_SIZE] = {
(UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10),
(UInt16)(0.05 * BIN10), (UInt16)(0.05 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facStgPmpLnrLossNEng_T
[TQADPCMP_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facStgPmpLnrLossSpd_T
[TQADPCMP_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facStgPmpThdLossNEng_T
[TQADPCMP_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facStgPmpThdLossSpd_T
[TQADPCMP_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(0.5 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_nCkStgPmp_A[TQADPCMP_5_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(500 * BIN2), (UInt16)(1000 * BIN2),
(UInt16)(2000 * BIN2), (UInt16)(3000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_spdVehStgPmp_A[TQADPCMP_5_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(7 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(100 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpLnrLossX_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(7 * BIN2), (UInt16)(10 * BIN2),
(UInt16)(20 * BIN2), (UInt16)(25 * BIN2), (UInt16)(50 * BIN2),
(UInt16)(60 * BIN2), (UInt16)(150 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqStgPmpLnrLoss_T
[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(5 * BIN4),
(UInt16)(5 * BIN4), (UInt16)(10 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(35 * BIN4), (UInt16)(35 * BIN4)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqstglossdown_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqstglossup_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facstgpmplnrlossneng_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facstgpmplnrlossspd_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facstgpmpthdlossneng_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facstgpmpthdlossspd_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tqstgpmplnrloss_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_04_filtre;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqadpcmp_04_filter_out;
#define TQADPCMP_STOP_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_04_filter_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) Stg_pStgPmpLnrMesSel; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_spdVehStgSel; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqStgPmpLnrLoss; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqStgPmpLossRaw; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqStgPmpThdLoss; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqStgPmpLossCf; /* BIN4 */

#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) Stg_bDftStgPmpLnrMes;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) Stg_bDftStgPmpThdMes;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) Stg_bStgPmpThdMesSel;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bStgPmpAvl;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bFrzAdpStgPmpOnCf;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQSTGLOSSDOWN_T_APM = {
&tqcmp_facfiltqstglossdown_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkStgPmp_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqStgLossDown_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQSTGLOSSUP_T_APM = {
&tqcmp_facfiltqstglossup_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkStgPmp_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqStgLossUp_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACSTGPMPLNRLOSSNENG_T_APM = {
&tqcmp_facstgpmplnrlossneng_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkStgPmp_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facStgPmpLnrLossNEng_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACSTGPMPLNRLOSSSPD_T_APM = {
&tqcmp_facstgpmplnrlossspd_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_spdVehStgPmp_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facStgPmpLnrLossSpd_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACSTGPMPTHDLOSSNENG_T_APM = {
&tqcmp_facstgpmpthdlossneng_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkStgPmp_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facStgPmpThdLossNEng_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACSTGPMPTHDLOSSSPD_T_APM = {
&tqcmp_facstgpmpthdlossspd_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_spdVehStgPmp_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facStgPmpThdLossSpd_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_TQSTGPMPLNRLOSS_T_APM = {
&tqcmp_tqstgpmplnrloss_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqStgPmpLnrLossX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqStgPmpLnrLoss_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Des_Entrees_Steering(
                                           UInt8 frm_binhstgpmplossmdl_par,
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 stg_bstgpmpthdmes_par,
                                           UInt16 stg_pstgpmplnrmes_par, /* BIN2 */
                                           UInt8 ext_ststgpmpcf_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calcul_Du_Couple(
                                           UInt8 ext_ststgpmpcf_par,
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_DA_ON_OFF(
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_Couple_DA_Lineaire(
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Filtrage(UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqdem_btqgrdlim_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Adaptation_Steering(
                                           UInt8 frm_binhstgpmplossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_Perte_DA(UInt8 frm_binhstgpmplossmdl_par,
												  UInt16 veh_spdveh_par, /* BIN7 */
												  UInt8 stg_bstgpmpthdmes_par,
												  UInt16 stg_pstgpmplnrmes_par, /* BIN2 */
												  UInt8 ext_ststgpmpcf_par,
												  UInt16 eng_nckfil_par,
												  UInt8 tqdem_btqgrdlim_par) ;

STATIC FUNC(void, AUTOMATIC)	TQADPCMP_06_Det_cond_calcul_pertes_DA(UInt8 ext_ststgpmpcf_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_07__Selectionner_couple_appliquable(
												CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqstgpmploss_ptr,
   												CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpstgpmpon_ptr) ;

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Steering
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Steering(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stStgPmpCf_swc_in,
                                           UInt8 FRM_bInhStgPmpLossMdl_swc_in,
                                           UInt8 Stg_bStgPmpThdMes_swc_in,
                                           UInt16 Stg_pStgPmpLnrMes_swc_in, /* BIN2 */
                                           UInt8 TqDem_bTqGrdLim_swc_in,
                                           UInt16 Veh_spdVeh_swc_in /* BIN7 */,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqStgPmpLoss_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpStgPmpOn_swc_out)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.0. */


    TQADPCMP_06_Det_cond_calcul_pertes_DA(Ext_stStgPmpCf_swc_in);

	if((UInt32)DDS_FALSE != (UInt32)TqCmp_bStgPmpAvl)

    {
		TQADPCMP_01_Perte_DA(FRM_bInhStgPmpLossMdl_swc_in,
    					Veh_spdVeh_swc_in, /* BIN7 */
						 Stg_bStgPmpThdMes_swc_in,
						 Stg_pStgPmpLnrMes_swc_in, /* BIN2 */
                         Ext_stStgPmpCf_swc_in,
                         Eng_nCkFil_swc_in,
    					TqDem_bTqGrdLim_swc_in);
	}
	else
	{
		/*Do nothings*/
	}



   TQADPCMP_07__Selectionner_couple_appliquable(TqCmp_tqStgPmpLoss_swc_out,
   												TqAdp_bFrzAdpStgPmpOn_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/
/*******************************************************************************
*
* Function Name : TQADPCMP_01_Perte_DA
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)   TQADPCMP_01_Perte_DA(UInt8 frm_binhstgpmplossmdl_par,
													  UInt16 veh_spdveh_par, /* BIN7 */
													  UInt8 stg_bstgpmpthdmes_par,
													  UInt16 stg_pstgpmplnrmes_par, /* BIN2 */
													  UInt8 ext_ststgpmpcf_par,
													  UInt16 eng_nckfil_par,
													  UInt8 tqdem_btqgrdlim_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.1.1 */
	TQADPCMP_02_Traitement_Des_Entrees_Steering(frm_binhstgpmplossmdl_par,
                                       veh_spdveh_par, /* BIN7 */
                                       stg_bstgpmpthdmes_par,
                                       stg_pstgpmplnrmes_par, /* BIN2 */
                                       ext_ststgpmpcf_par);

    TQADPCMP_03_Calcul_Du_Couple(ext_ststgpmpcf_par,
                                 eng_nckfil_par);


    TQADPCMP_04_Filtrage(eng_nckfil_par, /* bin2 */
                         tqdem_btqgrdlim_par);

    TQADPCMP_05_Adaptation_Steering(frm_binhstgpmplossmdl_par);


}

/*******************************************************************************
*
* Function Name :
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)   TQADPCMP_06_Det_cond_calcul_pertes_DA(UInt8 ext_ststgpmpcf_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.8.0 */

	if((UInt32)ext_ststgpmpcf_par != TQADPCMP_PAS_DE_DA_PAR_POMPE_ATTELEE )
	{
		TqCmp_bStgPmpAvl = DDS_TRUE;

	}
	else
	{
		TqCmp_bStgPmpAvl = DDS_FALSE;
	}
}

/*******************************************************************************
*
* Function Name :
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_07__Selectionner_couple_appliquable(
												CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqstgpmploss_ptr,
   												CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpstgpmpon_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.9.0 */

	if((UInt32)DDS_FALSE == (UInt32)TqCmp_bStgPmpAvl )
	{
		*tqcmp_tqstgpmploss_ptr = 0;
		*tqadp_bfrzadpstgpmpon_ptr = DDS_FALSE;

	}
	else
	{
		*tqcmp_tqstgpmploss_ptr = TqCmp_tqStgPmpLossCf;
		*tqadp_bfrzadpstgpmpon_ptr = TqAdp_bFrzAdpStgPmpOnCf;
	}

}
/*******************************************************************************
*
* Function Name : TQADPCMP_02_Traitement_Des_Entrees_Steering
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Des_Entrees_Steering(
                                           UInt8 frm_binhstgpmplossmdl_par,
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt8 stg_bstgpmpthdmes_par,
                                           UInt16 stg_pstgpmplnrmes_par, /* BIN2 */
                                           UInt8 ext_ststgpmpcf_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.2.1 */
    if((UInt32)frm_binhstgpmplossmdl_par != (UInt32)DDS_FALSE)
    {
        TqCmp_spdVehStgSel = TqCmp_spdVehDftStgPmp_C;
        Stg_bDftStgPmpLnrMes = DDS_TRUE;
        Stg_bDftStgPmpThdMes = DDS_TRUE;
        Stg_pStgPmpLnrMesSel = 0;
        Stg_bStgPmpThdMesSel = 0;
    }
    else
    {
        TqCmp_spdVehStgSel = veh_spdveh_par;

        if(  ((UInt32)ext_ststgpmpcf_par == TQADPCMP_PAS_DE_DA_PAR_POMPE_ATTELEE)
           ||((UInt32)ext_ststgpmpcf_par == TQADPCMP_DA_AVEC_POMPE_ATTELEE_AVEC_UN_CAPTEUR_BUTE_ON_OFF))
        {
            Stg_bDftStgPmpLnrMes = DDS_TRUE;
            Stg_pStgPmpLnrMesSel = 0;
        }
        else
        {
            Stg_bDftStgPmpLnrMes = DDS_FALSE;
            Stg_pStgPmpLnrMesSel = stg_pstgpmplnrmes_par;
        }

        if(  ((UInt32)ext_ststgpmpcf_par == TQADPCMP_PAS_DE_DA_PAR_POMPE_ATTELEE)
           ||((UInt32)ext_ststgpmpcf_par == TQADPCMP_DA_AVEC_POMPE_ATTELEE_AVEC_UN_CAPTEUR_DE_PRESSION_LINEAIRE))
        {
            Stg_bDftStgPmpThdMes = DDS_TRUE;
            Stg_bStgPmpThdMesSel = 0;
        }
        else
        {
            Stg_bDftStgPmpThdMes = DDS_FALSE;
            Stg_bStgPmpThdMesSel = stg_bstgpmpthdmes_par;
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Calcul_Du_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calcul_Du_Couple(
                                           UInt8 ext_ststgpmpcf_par,
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.3.0 */
    TQADPCMP_03_01_Couple_DA_Lineaire(eng_nckfil_par /* BIN2 */);
    TQADPCMP_03_02_DA_ON_OFF(eng_nckfil_par /* BIN2 */);

    if ((UInt32)ext_ststgpmpcf_par == TQADPCMP_PAS_DE_DA_PAR_POMPE_ATTELEE)
    {
        TqCmp_tqStgPmpLossRaw = 0;
    }
    else if((UInt32)ext_ststgpmpcf_par == TQADPCMP_DA_AVEC_POMPE_ATTELEE_AVEC_UN_CAPTEUR_BUTE_ON_OFF)
    {
        TqCmp_tqStgPmpLossRaw = TqCmp_tqStgPmpThdLoss;
    }
    else if((UInt32)ext_ststgpmpcf_par == TQADPCMP_DA_AVEC_POMPE_ATTELEE_AVEC_UN_CAPTEUR_DE_PRESSION_LINEAIRE)
    {
        TqCmp_tqStgPmpLossRaw = TqCmp_tqStgPmpLnrLoss;
    }
    else
    {
        TqCmp_tqStgPmpLossRaw = 0;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_Couple_DA_Lineaire
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_Couple_DA_Lineaire(
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.4.0 */
    UInt16 tqadpcmp_03_01_result1; /* BIN7 */
    UInt16 tqadpcmp_03_01_result2; /* BIN7 */
    UInt16 tqadpcmp_03_01_result3; /* BIN4 */

    if((UInt32)Stg_bDftStgPmpLnrMes != (UInt32)DDS_FALSE)
    {
        TqCmp_tqStgPmpLnrLoss = 0;
    }
    else
    {
        /* BIN7 */
        /* [0; 1] */
        tqadpcmp_03_01_result1 = DDS_M_MAP2D_U16(&TQCMP_FACSTGPMPLNRLOSSNENG_T_APM, eng_nckfil_par);
        /* BIN7 */
        /* [0; 1] */
        tqadpcmp_03_01_result2 = DDS_M_MAP2D_U16(&TQCMP_FACSTGPMPLNRLOSSSPD_T_APM, TqCmp_spdVehStgSel);
        /* BIN4 */
        /* [0; 500] */
        tqadpcmp_03_01_result3 = DDS_M_MAP2D_U16(&TQCMP_TQSTGPMPLNRLOSS_T_APM, Stg_pStgPmpLnrMesSel);

        /* BIN4 = BIN7 * BIN7 * BIN4 / BIN14 */
        TqCmp_tqStgPmpLnrLoss = (UInt16)((((UInt32)tqadpcmp_03_01_result1 * (UInt32)tqadpcmp_03_01_result2)
                                          * (UInt32)tqadpcmp_03_01_result3) / BIN14);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_02_DA_ON_OFF
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_DA_ON_OFF(
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.5.0 */
    UInt16 result1; /* BIN7 */
    UInt16 result2; /* BIN7 */

    if((UInt32)Stg_bDftStgPmpThdMes != (UInt32)DDS_FALSE)
    {
        TqCmp_tqStgPmpThdLoss = 0;
    }
    else
    {
        /* BIN7 */
        /* [0; 1] */
        result1 = DDS_M_MAP2D_U16(&TQCMP_FACSTGPMPTHDLOSSNENG_T_APM, eng_nckfil_par);

        /* BIN7 */
        /* [0; 1] */
        result2 = DDS_M_MAP2D_U16(&TQCMP_FACSTGPMPTHDLOSSSPD_T_APM, TqCmp_spdVehStgSel);

        if((UInt32)Stg_bStgPmpThdMesSel != (UInt32)DDS_FALSE)
        {
            TqCmp_tqStgPmpThdLoss = (UInt16)((((UInt32)result1 * (UInt32)result2) * (UInt32)TqCmp_tqStgPmpThdLossOn_C) / BIN14);
        }
        else
        {
            TqCmp_tqStgPmpThdLoss = (UInt16)((((UInt32)result1 * (UInt32)result2) * (UInt32)TqCmp_tqStgPmpThdLossOff_C) / BIN14);
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Filtrage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Filtrage(UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 tqdem_btqgrdlim_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.6.1 */
    UInt16 tqadpcmp_04_switch_fac_in;

    if((UInt32)tqdem_btqgrdlim_par != (UInt32)DDS_FALSE)
    {
        tqadpcmp_04_switch_fac_in = TqDem_facFilTqStgLoss_C;
    }
    else
    {
        if((UInt32)TqCmp_tqStgPmpLossRaw>(UInt32)tqadpcmp_04_filter_out)
        {
            tqadpcmp_04_switch_fac_in = DDS_M_MAP2D_U16(&TQCMP_FACFILTQSTGLOSSUP_T_APM,eng_nckfil_par);
        }
        else
        {
            tqadpcmp_04_switch_fac_in = DDS_M_MAP2D_U16(&TQCMP_FACFILTQSTGLOSSDOWN_T_APM,eng_nckfil_par);
        }
    }

    if((UInt32)tqadpcmp_04_filter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_04_filter_init = DDS_TRUE;
        tqadpcmp_04_filter_out = DDS_M_FILTER_LP1_U16_INIT(&tqadpcmp_04_filtre, TqCmp_tqStgPmpLossRaw);
    }
    else
    {
        tqadpcmp_04_filter_out = DDS_M_FILTER_LP1_U16(&tqadpcmp_04_filtre, TqCmp_tqStgPmpLossRaw, tqadpcmp_04_switch_fac_in, BIN10);
    }

    TqCmp_tqStgPmpLossCf = (UInt16)DDS_M_SATURATION_V2((UInt32)tqadpcmp_04_filter_out,
                                                         (UInt32)TqCmp_tqStgPmpLossMin_C,
                                                         (UInt32)TqCmp_tqStgPmpLossMax_C);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_Adaptation_Steering
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Adaptation_Steering(
                                           UInt8 frm_binhstgpmplossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1929.FR.7.1 */
    if(  ((UInt32)Stg_pStgPmpLnrMesSel >= (UInt32)TqCmp_pStgPmpThd_C)
       ||((UInt32)Stg_bStgPmpThdMesSel == (UInt32)DDS_TRUE)
       ||((UInt32)frm_binhstgpmplossmdl_par == (UInt32)DDS_TRUE))
    {
        TqAdp_bFrzAdpStgPmpOnCf = DDS_TRUE;
    }
    else
    {
        TqAdp_bFrzAdpStgPmpOnCf = DDS_FALSE;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Steering_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Steering_Init(
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqStgPmpLoss_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpStgPmpOn_swc_out)
{
    *TqCmp_tqStgPmpLoss_swc_out = 0;
    *TqAdp_bFrzAdpStgPmpOn_swc_out = DDS_FALSE;

  	 TqCmp_tqStgPmpLossCf = 0;
	 TqAdp_bFrzAdpStgPmpOnCf = DDS_FALSE;
	 TqCmp_bStgPmpAvl = DDS_FALSE;

    tqadpcmp_04_filter_init = DDS_FALSE;
    tqadpcmp_04_filter_out = 0;
}

#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

