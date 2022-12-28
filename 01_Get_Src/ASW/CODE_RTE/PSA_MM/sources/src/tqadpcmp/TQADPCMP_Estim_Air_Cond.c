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
* Ref X:\integration_view_00PSASWC_E506D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Estim_Air_Cond.c
* Version int :/main/L04_01/2 Date: 14/9/2011 16 h 28 m User:meme 
*    TWK_model:TQADPCMP_Estim_Air_Cond_L04_010_IMPL1_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 14/9/2011 14 h 25 m User:halouane 
*    TWK_model:TQADPCMP_Estim_Air_Cond_L04_010_IMPL1_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_demezil_tqadpcmp_dev\1 Date: 29/4/2011 9 h 20 m User:demezil
*    TWK_model:TQADPCMP_Estim_Air_Cond_L04_010_IMPL1_D
*    comments :to reduce CPU load
* Version int :/main/L04_01/1 Date: 18/11/2010 12 h 48 m User:meme
*    TWK_model:TQADPCMP_Estim_Air_Cond_L04_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 17/11/2010 16 h 50 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L04_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 17/11/2010 15 h 36 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L04_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version int :/main/L03_01/1 Date: 13/9/2010 14 h 19 m User:esnault
*    TWK_model:TQADPCMP_Estim_Air_Cond_L03_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 10/9/2010 10 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L03_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 6/9/2010 14 h 24 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp euro6
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 23/7/2010 8 h 53 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 22/7/2010 16 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 29/6/2010 8 h 12 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 28/6/2010 17 h 29 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_02/1 Date: 9/9/2009 13 h 29 m User:langendorf
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_020_IMPL1
*    comments :work in progress, for STIL 2.0
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 24/8/2009 13 h 11 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_020_IMPL1
*    comments :work in progress, for STIL 2.0
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 5 m User:boucher
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL3
*    comments :TqCmp_idxACTyp_C must be volatile
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 15/10/2008 17 h 8 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL3
*    comments :TqCmp_idxACTyp_C must be volatile
* Version dev :\main\branch_miaille\6 Date: 3/10/2008 15 h 48 m User:miaille
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL2
*    comments :Remove unused "TqCmp_nCkfil" variable from code.
* Version dev :\main\branch_miaille\5 Date: 30/9/2008 12 h 59 m User:miaille
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL2
*    comments :Checked out to link source to correct TeamWork schema version.
* Version dev :\main\branch_miaille\4 Date: 30/9/2008 12 h 42 m User:miaille
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL2
*    comments :Checked out to link source to correct TeamWork schema version.
* Version dev :\main\branch_miaille\3 Date: 30/9/2008 10 h 52 m User:miaille
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL1
*    comments :Tests feedback errors fix.
* Version dev :\main\branch_miaille\2 Date: 22/9/2008 15 h 8 m User:miaille
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL1
*    comments :Input variables error fix.
* Version dev :\main\branch_miaille\1 Date: 17/9/2008 10 h 31 m User:miaille
*    TWK_model:TQADPCMP_Estim_Air_Cond_L01_010_IMPL1
*    comments :Implements specification CSMT_CGMT06_1931_v2_0.
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

/* For Ext_stACTypCf */
#define TQADPCMP_PAS_DE_CLIM   (UInt8)0
#define TQADPCMP_CLIM_TYPE_3   (UInt8)1
#define TQADPCMP_CLIM_TYPE_4   (UInt8)2
#define TQADPCMP_RESERVE_3     (UInt8)3


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqACLossMax_C = (CONST(UInt16, AUTOMATIC))(500 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqACLossMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqGrdFrzAdpAC_C = (CONST(UInt16, AUTOMATIC))(10 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facFilTqACLoss_C = (CONST(UInt16, AUTOMATIC))(0.2 * BIN10);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facCnvPwrTq_M
[TQADPCMP_10_SIZE][TQADPCMP_8_SIZE] = {
{
(UInt16)(0.00 * BIN4), (UInt16)(9.63 * BIN4), (UInt16)(19.13 * BIN4),
(UInt16)(28.69 * BIN4), (UInt16)(38.19 * BIN4), (UInt16)(47.81 * BIN4),
(UInt16)(57.31 * BIN4), (UInt16)(76.38 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(4.81 * BIN4), (UInt16)(7.13 * BIN4),
(UInt16)(14.31 * BIN4), (UInt16)(19.13 * BIN4), (UInt16)(23.88 * BIN4),
(UInt16)(28.69 * BIN4), (UInt16)(38.19 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(2.81 * BIN4), (UInt16)(4.00 * BIN4),
(UInt16)(5.63 * BIN4), (UInt16)(8.69 * BIN4), (UInt16)(11.88 * BIN4),
(UInt16)(19.13 * BIN4), (UInt16)(25.50 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(2.38 * BIN4), (UInt16)(3.00 * BIN4),
(UInt16)(5.00 * BIN4), (UInt16)(6.00 * BIN4), (UInt16)(10.63 * BIN4),
(UInt16)(14.31 * BIN4), (UInt16)(19.13 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(1.88 * BIN4), (UInt16)(2.50 * BIN4),
(UInt16)(3.00 * BIN4), (UInt16)(4.00 * BIN4), (UInt16)(9.38 * BIN4),
(UInt16)(11.50 * BIN4), (UInt16)(15.31 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(1.63 * BIN4), (UInt16)(1.50 * BIN4),
(UInt16)(2.00 * BIN4), (UInt16)(3.00 * BIN4), (UInt16)(8.19 * BIN4),
(UInt16)(9.63 * BIN4), (UInt16)(12.69 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(1.38 * BIN4), (UInt16)(1.25 * BIN4),
(UInt16)(1.81 * BIN4), (UInt16)(2.50 * BIN4), (UInt16)(6.94 * BIN4),
(UInt16)(8.19 * BIN4), (UInt16)(10.88 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(0.25 * BIN4), (UInt16)(0.13 * BIN4),
(UInt16)(0.69 * BIN4), (UInt16)(1.38 * BIN4), (UInt16)(5.69 * BIN4),
(UInt16)(6.13 * BIN4), (UInt16)(8.19 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(0.19 * BIN4), (UInt16)(0.06 * BIN4),
(UInt16)(0.44 * BIN4), (UInt16)(0.94 * BIN4), (UInt16)(3.81 * BIN4),
(UInt16)(4.13 * BIN4), (UInt16)(5.44 * BIN4) },
{
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4),
(UInt16)(0.00 * BIN4), (UInt16)(0.00 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqACLossDown_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10),
(UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10),
(UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10),
(UInt16)(0.3 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqACLossUp_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10), (UInt16)(0.2 * BIN10),
(UInt16)(0.2 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_nCkACLoss_A[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2),
(UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(3500 * BIN2), (UInt16)(4000 * BIN2), (UInt16)(4500 * BIN2),
(UInt16)(5000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pwrACLoss_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(500 * BIN0), (UInt16)(1000 * BIN0),
(UInt16)(1500 * BIN0), (UInt16)(2000 * BIN0), (UInt16)(2500 * BIN0),
(UInt16)(3000 * BIN0), (UInt16)(4000 * BIN0)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_faccnvpwrtq_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqaclossdown_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqaclossup_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_03_filtre;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqcmp_tqacloss_prev;
#define TQADPCMP_STOP_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_03_filter_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pwrACLossFil; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bFrzAdpAC;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bTqACLossMax;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_FACCNVPWRTQ_M_APM = {
&tqcmp_faccnvpwrtq_m_sav,
TQADPCMP_8_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_pwrACLoss_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkACLoss_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facCnvPwrTq_M[0][0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQACLOSSDOWN_T_APM = {
&tqcmp_facfiltqaclossdown_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkACLoss_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqACLossDown_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQACLOSSUP_T_APM = {
&tqcmp_facfiltqaclossup_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkACLoss_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqACLossUp_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Choix_Systeme(
                                           UInt16 tqcmp_pwracauxloss_par, /* BIN0 */
                                           UInt16 tqcmp_pwracexteculoss_par, /* BIN0 */
                                           UInt16 tqcmp_pwraciteculoss_par, /* BIN0 */
                                           UInt8 tqadp_bfrzadpacauxon_par,
                                           UInt8 tqadp_bfrzadpacextecuon_par,
                                           UInt8 tqadp_bfrzadpacitecuon_par,
                                           UInt8 ext_stactypcf_par, /* BIN0 */
                                           UInt8 tqcmp_bacextecuoffdftselon_par,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_pwracloss_ptr, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_bacoffdftselon_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Filtrage(
                                           UInt16 tqcmp_pwracloss_par, /* BIN0 */
                                           UInt8 tqdem_btqgrdlim_par,
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Calcul_Du_Couple(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqacloss_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Adaptation(
                                           UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpacon_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Air_Cond
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_stACTypCf_swc_in, /* BIN0 */
                                           UInt8 TqAdp_bFrzAdpACAuxOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpACExtECUOn_swc_in,
                                           UInt8 TqAdp_bFrzAdpACItECUOn_swc_in,
                                           UInt8 TqCmp_bACExtECUOffDftSelOn_swc_in,
                                           UInt16 TqCmp_pwrACAuxLoss_swc_in, /* BIN0 */
                                           UInt16 TqCmp_pwrACExtECULoss_swc_in, /* BIN0 */
                                           UInt16 TqCmp_pwrACItECULoss_swc_in, /* BIN0 */
                                           UInt8 TqDem_bTqGrdLim_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACLoss_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqACLoss_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1931.FR.1.0 */
    TQADPCMP_02_Choix_Systeme(TqCmp_pwrACAuxLoss_swc_in, /* BIN0 */
                              TqCmp_pwrACExtECULoss_swc_in, /* BIN0 */
                              TqCmp_pwrACItECULoss_swc_in, /* BIN0 */
                              TqAdp_bFrzAdpACAuxOn_swc_in,
                              TqAdp_bFrzAdpACExtECUOn_swc_in,
                              TqAdp_bFrzAdpACItECUOn_swc_in,
                              Ext_stACTypCf_swc_in, /* BIN0 */
                              TqCmp_bACExtECUOffDftSelOn_swc_in,
                              TqCmp_pwrACLoss_swc_out, /* BIN0 */
                              TqCmp_bACOffDftSelOn_swc_out);

    TQADPCMP_03_Filtrage(*TqCmp_pwrACLoss_swc_out, /* BIN0 */
                         TqDem_bTqGrdLim_swc_in,
                         Eng_nCkFil_swc_in /* BIN2 */);

    TQADPCMP_04_Calcul_Du_Couple(Eng_nCkFil_swc_in, /* BIN2 */
                                 TqCmp_tqACLoss_swc_out /* BIN4 */);

    TQADPCMP_05_Adaptation(*TqCmp_tqACLoss_swc_out, /* BIN4 */
                           TqAdp_bFrzAdpACOn_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_02_Choix_Systeme
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Choix_Systeme(
                                           UInt16 tqcmp_pwracauxloss_par, /* BIN0 */
                                           UInt16 tqcmp_pwracexteculoss_par, /* BIN0 */
                                           UInt16 tqcmp_pwraciteculoss_par, /* BIN0 */
                                           UInt8 tqadp_bfrzadpacauxon_par,
                                           UInt8 tqadp_bfrzadpacextecuon_par,
                                           UInt8 tqadp_bfrzadpacitecuon_par,
                                           UInt8 ext_stactypcf_par, /* BIN0 */
                                           UInt8 tqcmp_bacextecuoffdftselon_par,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_pwracloss_ptr, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_bacoffdftselon_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1931.FR.2.0 */



    switch((UInt32)ext_stactypcf_par)
    {
        case (UInt32)TQADPCMP_CLIM_TYPE_3:                          /* Selector = 1 */
            *tqcmp_bacoffdftselon_ptr = DDS_FALSE;
            TqCmp_bFrzAdpAC = tqadp_bfrzadpacitecuon_par;
            *tqcmp_pwracloss_ptr = tqcmp_pwraciteculoss_par;
            break;
        case (UInt32)TQADPCMP_CLIM_TYPE_4:                          /* Selector = 2 */
            *tqcmp_bacoffdftselon_ptr = tqcmp_bacextecuoffdftselon_par;
            TqCmp_bFrzAdpAC = tqadp_bfrzadpacextecuon_par;
            *tqcmp_pwracloss_ptr = tqcmp_pwracexteculoss_par;
            break;
        case (UInt32)TQADPCMP_RESERVE_3:                            /* Selector = 3 */
            *tqcmp_bacoffdftselon_ptr = DDS_FALSE;
            TqCmp_bFrzAdpAC = tqadp_bfrzadpacauxon_par;
            *tqcmp_pwracloss_ptr = tqcmp_pwracauxloss_par;
            break;
        case (UInt32)TQADPCMP_PAS_DE_CLIM:                          /* Selector = 0 */
        default:
            *tqcmp_bacoffdftselon_ptr = DDS_FALSE;
            TqCmp_bFrzAdpAC = DDS_FALSE;
            *tqcmp_pwracloss_ptr = 0;
            break;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Filtrage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Filtrage(
                                           UInt16 tqcmp_pwracloss_par, /* BIN0 */
                                           UInt8 tqdem_btqgrdlim_par,
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1931.FR.3.0 */
    UInt16 tqadpcmp_03_switch_fac_in;

    if((UInt32)tqcmp_pwracloss_par>(UInt32)TqCmp_pwrACLossFil)
    {
        tqadpcmp_03_switch_fac_in = DDS_M_MAP2D_U16(&TQCMP_FACFILTQACLOSSUP_T_APM,eng_nckfil_par);
    }
    else
    {
        tqadpcmp_03_switch_fac_in = DDS_M_MAP2D_U16(&TQCMP_FACFILTQACLOSSDOWN_T_APM,eng_nckfil_par);
    }


    if((UInt32)tqdem_btqgrdlim_par != (UInt32)DDS_FALSE)
    {
        tqadpcmp_03_switch_fac_in = TqDem_facFilTqACLoss_C;
    }
    else
    {
        /* nothing to do */
    }

    if((UInt32)tqadpcmp_03_filter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_03_filter_init = DDS_TRUE;
        TqCmp_pwrACLossFil = DDS_M_FILTER_LP1_U16_INIT(&tqadpcmp_03_filtre, tqcmp_pwracloss_par);
    }
    else
    {
        TqCmp_pwrACLossFil = DDS_M_FILTER_LP1_U16(&tqadpcmp_03_filtre, tqcmp_pwracloss_par, tqadpcmp_03_switch_fac_in, BIN10);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Calcul_Du_Couple
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Calcul_Du_Couple(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqacloss_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1931.FR.4.0 */
    UInt16 result1;

    result1 = DDS_M_MAP3D_U16(&TQCMP_FACCNVPWRTQ_M_APM, TqCmp_pwrACLossFil, eng_nckfil_par);

    if((UInt32)result1 >= (UInt32)TqCmp_tqACLossMax_C)
    {
        TqCmp_bTqACLossMax = DDS_TRUE;
    }
    else
    {
        TqCmp_bTqACLossMax = DDS_FALSE;
    }


    *tqcmp_tqacloss_ptr = (UInt16)DDS_M_SATURATION_V2((UInt32)result1, (UInt32)TqCmp_tqACLossMin_C, (UInt32)TqCmp_tqACLossMax_C);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_Adaptation
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Adaptation(
                                           UInt16 tqcmp_tqacloss_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpacon_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1931.FR.5.0 */
    UInt32 tqadpcmp_05_uval;

    tqadpcmp_05_uval = (UInt32)DDS_M_ABS((SInt32)tqcmp_tqacloss_par - (SInt32)tqcmp_tqacloss_prev);
    tqcmp_tqacloss_prev = tqcmp_tqacloss_par;

    if(  (tqadpcmp_05_uval >= (UInt32)TqCmp_tqGrdFrzAdpAC_C)
       ||((UInt32)TqCmp_bTqACLossMax == (UInt32)DDS_TRUE)
       ||((UInt32)TqCmp_bFrzAdpAC == (UInt32)DDS_TRUE))
    {
        *tqadp_bfrzadpacon_ptr = DDS_TRUE;
    }
    else
    {
        *tqadp_bfrzadpacon_ptr = DDS_FALSE;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Air_Cond_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACLoss_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqACLoss_swc_out /* BIN4 */)
{
    *TqAdp_bFrzAdpACOn_swc_out = DDS_FALSE;
    *TqCmp_bACOffDftSelOn_swc_out = DDS_FALSE;
    *TqCmp_pwrACLoss_swc_out = 0;
    *TqCmp_tqACLoss_swc_out = 0;

    tqadpcmp_03_filter_init = DDS_FALSE;
    tqcmp_tqacloss_prev = 0;
    TqCmp_pwrACLossFil = 0;

    TqCmp_bTqACLossMax  = DDS_FALSE;
    TqCmp_bFrzAdpAC     = DDS_FALSE;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

