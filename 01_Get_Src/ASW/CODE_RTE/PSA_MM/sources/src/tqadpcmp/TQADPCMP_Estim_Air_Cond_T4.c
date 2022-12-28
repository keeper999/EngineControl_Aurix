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
* Ref X:\integration_view_00PSASWC_E522D11\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Estim_Air_Cond_T4.c
* Version int :/main/C00_00/1 Date: 28/11/2013 15 h 40 m User:posmyk 
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_C00_000_IMPL1
*    comments :For TqAdpCmp 12.2 / Update with A0104548 1.0 (CSMT_CGMT06_2023_V3_4.zip)
* Version dev :\main\branch_thauvin_euro6\1 Date: 21/11/2013 15 h 20 m User:thauvin 
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_C00_000_IMPL1
*    comments :For TqAdpCmp 12.2 / Update with A0104548 1.0 (CSMT_CGMT06_2023_V3_4.zip)
* Version int :/main/L04_01/1 Date: 2/5/2013 12 h 22 m User:posmyk
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L04_010_IMPL1
*    comments :implement CSMT_CGMT06_2023_V3_3 for TqAdpCmp 12.1
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 24/4/2013 10 h 8 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L04_010_IMPL1
*    comments :implement CSMT_CGMT06_2023_V3_3 for TqAdpCmp 12.1
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 22/4/2013 15 h 16 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L04_010_IMPL1
*    comments :implement CSMT_CGMT06_2023_V3_3 for TqAdpCmp 12.1
* Version int :/main/L03_01/2 Date: 23/4/2012 11 h 58 m User:meme
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L03_010_IMPL1
*    comments :UT defect correction
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 11/4/2012 16 h 20 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L03_010_IMPL1
*    comments :UT defect correction
* Version int :/main/L03_01/1 Date: 21/3/2012 15 h 9 m User:esnault
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_01/2 Date: 18/11/2010 12 h 48 m User:meme
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL2_D
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 17/11/2010 16 h 50 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL2_D
*    comments :for TqAdpCmp 10.2
* Version int :/main/L02_01/1 Date: 13/9/2010 14 h 19 m User:esnault
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 10/9/2010 10 h 1 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 8/9/2010 9 h 34 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 18/8/2010 9 h 17 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 22/7/2010 16 h 53 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 29/6/2010 11 h 4 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_02/1 Date: 9/9/2009 13 h 30 m User:langendorf
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_020_IMPL3
*    comments :new model : . 2 prev : DISP -> NULL
* Version dev :\main\branch_lemort_tqadpcmp_dev\3 Date: 1/9/2009 11 h 5 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_020_IMPL3
*    comments :2 prev : DISP -> NULL
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 25/8/2009 14 h 32 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_020_IMPL2
*    comments :new model for TqCmp_tiMaxACOffDft_C resolution
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 24/8/2009 13 h 11 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_020_IMPL1
*    comments :work in progress, adaptation for STIL 2.0
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 6 m User:boucher
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_010_IMPL1
*    comments :No change in code.
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 10/10/2008 9 h 36 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_010_IMPL1
*    comments :No change in code.
* Version dev :\main\branch_moisan_integ_tqadpcmp\2 Date: 24/9/2008 17 h 30 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_010_IMPL1
*    comments :Correction of fail test
* Version dev :\main\branch_moisan_integ_tqadpcmp\1 Date: 23/9/2008 13 h 25 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_010_IMPL1
*    comments :Wrong requirement
* Version int :/main/L01_01/1 Date: 23/9/2008 10 h 29 m User:boucher
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_010_IMPL1
*    comments :Implement CSMT_CGMT06_2023_v2_0 / R6515134 1.0
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\1 Date: 18/9/2008 16 h 55 m User:girodon
*    TWK_model:TQADPCMP_Estim_Air_Cond_T4_L01_010_IMPL1
*    comments :Implement CSMT_CGMT06_2023_v2_0 / R6515134 1.0
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

/* NONE */


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiACExtECUOff_C = (UInt16)(0.2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiACExtECUOn_C = (UInt16)(0.2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiMaxACOffDft_C = (UInt16)(0.5 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pwrThdDiFil_C = (UInt16)(1 * BIN0);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_facFilTqACExtECUOff_C = (UInt8)(0.1 * BIN7);
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facACFilAcv_T
[TQADPCMP_4_SIZE] = {
(UInt16)(1 * BIN10), (UInt16)(0.5 * BIN10),
(UInt16)(0.1 * BIN10), (UInt16)(0.01 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pFlowSatPres_T
[TQADPCMP_4_SIZE] = {
(UInt16)(3 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(8 * BIN0), (UInt16)(12 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pDeltaACflow_A[TQADPCMP_4_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(13 * BIN0),
(UInt16)(26 * BIN0), (UInt16)(40 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tAirFlowPres_A[TQADPCMP_4_SIZE] = {
(SInt16)(0 * BIN0), (SInt16)(15 * BIN0),
(SInt16)(30 * BIN0), (SInt16)(45 * BIN0)
};



#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facacfilacv_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_pflowsatpres_t_sav;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_t4_02_turn_on_delay;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_t4_02_turn_off_delay;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_t4_03_filtre;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_04_edge_detect_1;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_04_edge_detect_2;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_04_edge_detect_3;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_t4_04_turn_on_delay;
STATIC VAR(UInt16, AUTOMATIC) tqadp_filter_prev;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_bacextecuoffdftselon_dly;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_t4_03_filtre_is_filter_initialised;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_bq;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pwrAC; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pwrACExtECULossCf; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bACClu;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bACCluSel;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bAvlACExt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bFrzAdpACExtECUOnCf;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bACExtECUOffDftSelOnCf;

#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACACFILACV_T_APM = {
&tqcmp_facacfilacv_t_sav,
TQADPCMP_4_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_pDeltaACflow_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facACFilAcv_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_PFLOWSATPRES_T_APM = {
&tqcmp_pflowsatpres_t_sav,
TQADPCMP_4_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tAirFlowPres_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_pFlowSatPres_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Entrees(
                                           UInt8 ac_bacclu_par,
                                           UInt8 ac_pwrac_par, /* NBIN0 resol 25 */
                                           UInt8 frm_binhacexteculossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Gestion_Puissance_Clim4(SInt8 ext_tair_par,
                                           					     UInt16 ext_pac_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Adaptation_T4(
                                           UInt8 ac_bacclu_par,
                                           UInt8 frm_binhacexteculossmdl_par,
                                           UInt8 tqres_bdftacswton_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_F05_Determiner_condition_calcul_Clim4(UInt8 ext_stactypcf_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_Perte_Clim4(UInt8 ac_bacclu_par,
                                           UInt8 ac_pwrac_par, /* NBIN0 resol 25 */
                                           UInt8 frm_binhacexteculossmdl_par,
                                           UInt8 tqres_bdftacswton_par,
                                    	   SInt8 ext_tair_par,
                                           UInt16 ext_pac_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_F06_Selectionner_couple_Clim4_applicable(
                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpacextecuon_ptr,
                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_bacextecuoffdftselon_ptr,
                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_pwracexteculoss_ptr /* BIN0 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Air_Cond_T4
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T4(UInt8 AC_bACClu_swc_in,
                                           UInt8 AC_pwrAC_swc_in, /* NBIN0 resol 25 */
                                           UInt8 FRM_bInhACExtECULossMdl_swc_in,
                                           UInt8 TqRes_bDftACSwtOn_swc_in,
                                           UInt8 Ext_stACTypCf_swc_in,
                                           SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           UInt16 Ext_pAC_swc_in, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACExtECUOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACExtECUOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACExtECULoss_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.0.0 */

    TQADPCMP_F05_Determiner_condition_calcul_Clim4(Ext_stACTypCf_swc_in);

    if((UInt32) DDS_FALSE != (UInt32)TqAdp_bAvlACExt)
    {
        TQADPCMP_01_Perte_Clim4( AC_bACClu_swc_in,
                                    AC_pwrAC_swc_in, /* NBIN0 resol 25 */
                                    FRM_bInhACExtECULossMdl_swc_in,
                                    TqRes_bDftACSwtOn_swc_in,
                                    Ext_tAir_swc_in,
                                    Ext_pAC_swc_in);
    }
    else
    {
        /* Do nothings */
    }

    TQADPCMP_F06_Selectionner_couple_Clim4_applicable(TqAdp_bFrzAdpACExtECUOn_swc_out,
                                                      TqCmp_bACExtECUOffDftSelOn_swc_out,
                                                       TqCmp_pwrACExtECULoss_swc_out /* BIN0 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_F05_Determiner_condition_calcul_Clim4
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)        TQADPCMP_F05_Determiner_condition_calcul_Clim4(UInt8 ext_stactypcf_par)

{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.5.0 */
    if((UInt32)ext_stactypcf_par == (UInt32)TQADPCMP_CLIM_TYPE_4  )
    {

        TqAdp_bAvlACExt = DDS_TRUE;
    }
    else
    {
        TqAdp_bAvlACExt = DDS_FALSE;
    }

}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_Perte_Clim4
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_Perte_Clim4(UInt8 ac_bacclu_par,
                                           UInt8 ac_pwrac_par, /* NBIN0 resol 25 */
                                           UInt8 frm_binhacexteculossmdl_par,
                                           UInt8 tqres_bdftacswton_par,
                                    	   SInt8 ext_tair_par,
                                           UInt16 ext_pac_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.1.2 */
    TQADPCMP_02_Traitement_Entrees(ac_bacclu_par,
                                   ac_pwrac_par, /* nbin0 resol 25 */
                                   frm_binhacexteculossmdl_par);

    TQADPCMP_03_Gestion_Puissance_Clim4(ext_tair_par,
                                        ext_pac_par);

    TQADPCMP_04_Adaptation_T4(ac_bacclu_par,
                           frm_binhacexteculossmdl_par,
                           tqres_bdftacswton_par );

}

/*******************************************************************************
*
* Function Name : TQADPCMP_F06_Selectionner_couple_Clim4_applicable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)    TQADPCMP_F06_Selectionner_couple_Clim4_applicable(
                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpacextecuon_ptr,
                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_bacextecuoffdftselon_ptr,
                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_pwracexteculoss_ptr /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.6.0 */
    if((UInt32)DDS_FALSE == (UInt32)TqAdp_bAvlACExt )
    {
        *tqadp_bfrzadpacextecuon_ptr = DDS_FALSE;
        *tqcmp_bacextecuoffdftselon_ptr = DDS_FALSE;
        *tqcmp_pwracexteculoss_ptr = 0;

    }
    else
    {
        *tqadp_bfrzadpacextecuon_ptr = TqAdp_bFrzAdpACExtECUOnCf;
        *tqcmp_bacextecuoffdftselon_ptr = TqCmp_bACExtECUOffDftSelOnCf;
        *tqcmp_pwracexteculoss_ptr = TqCmp_pwrACExtECULossCf;

    }

}
/*******************************************************************************
*
* Function Name : TQADPCMP_02_Traitement_Entrees
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Entrees(
                                           UInt8 ac_bacclu_par,
                                           UInt8 ac_pwrac_par, /* NBIN0 resol 25 */
                                           UInt8 frm_binhacexteculossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.2.0 */
    UInt8 tqadpcmp_uvalue;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    if ((UInt32)frm_binhacexteculossmdl_par != (UInt32)DDS_FALSE)
    {
        TqCmp_pwrAC = 0 ;
        TqCmp_bACClu = DDS_FALSE;
    }
    else
    {
        TqCmp_pwrAC = (UInt16)((UInt32)ac_pwrac_par * 25); /* NBIN0 resol 25 */
        TqCmp_bACClu = ac_bacclu_par;
    }

    tqadpcmp_uvalue = DDS_M_TURN_ON_DELAY(TqCmp_bACClu,
                                          tqadpcmp_te,
                                          ((UInt32)TqCmp_tiACExtECUOn_C*DEC1),
                                          &tqadpcmp_t4_02_turn_on_delay);

    TqCmp_bACCluSel = DDS_M_TURN_OFF_DELAY(tqadpcmp_uvalue,
                                           tqadpcmp_te,
                                           ((UInt32)TqCmp_tiACExtECUOff_C*DEC1),
                                           &tqadpcmp_t4_02_turn_off_delay);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Gestion_Puissance_Clim4
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Gestion_Puissance_Clim4(SInt8 ext_tair_par,
                                           						 UInt16 ext_pac_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.3.4  */

    UInt16 tqadp_input_k_u16_b10;
    UInt16 tqcmp_pwracswtbffil;
    UInt16 tqadp_temp_u16;
    UInt8 tqadp_temp_u8;
    SInt32 tqadp_temp_s32;
    UInt8  tqadp_reset_condition;
    UInt8  tqadp_set_condition;
    UInt16 tqadp_temp_u16_abs;
    t_dds_m_edge_detected_event tqadpcmp_edge_result;

    if((UInt32)TqCmp_bACCluSel == (UInt32)DDS_FALSE)
    {
		tqadp_input_k_u16_b10 = (UInt16)((UInt32)TqCmp_facFilTqACExtECUOff_C * BIN3);
		tqcmp_pwracswtbffil = 0;
	}
	else
	{
		tqadp_temp_u16 = DDS_M_MAP2D_SU16(&TQCMP_PFLOWSATPRES_T_APM,(SInt16)ext_tair_par); /* [0;31000] BIN0 */
		tqadp_temp_s32 = (SInt32)ext_pac_par - (SInt32)tqadp_temp_u16; /* [0;31000] BIN0 - [0;31000] BIN0 = [-31000;31000] BIN0 */
		tqadp_temp_u16 = (UInt16)DDS_M_MAX(tqadp_temp_s32,0);
		tqadp_input_k_u16_b10 = DDS_M_MAP2D_U16(&TQCMP_FACACFILACV_T_APM,tqadp_temp_u16); /* [0;31000] BIN10 */
		tqcmp_pwracswtbffil = TqCmp_pwrAC;
	}
	tqadp_temp_s32 = (SInt32)tqcmp_pwracswtbffil - (SInt32)tqadp_filter_prev;
	tqadp_temp_u16_abs = (UInt16)DDS_M_ABS(tqadp_temp_s32);

    if((UInt32)tqadp_temp_u16_abs <= (UInt32)TqCmp_pwrThdDiFil_C)
    {
		tqadp_temp_u8 = DDS_TRUE;
	}
	else
	{
		tqadp_temp_u8 = DDS_FALSE;
    }

	if(((UInt32)tqadpcmp_bq == (UInt32)DDS_TRUE) && ((UInt32)tqadp_temp_u8 == (UInt32)DDS_TRUE))
	{
	    tqadp_reset_condition = DDS_TRUE;
	}
	else
	{
        tqadp_reset_condition = DDS_FALSE;
	}

	tqadpcmp_edge_result = DDS_M_EDGE_DETECT(&tqadpcmp_04_edge_detect_3,TqCmp_bACCluSel);
	if((UInt32)tqadpcmp_edge_result != (UInt32)DDS_M_NO_EDGE_DETECTED)

	{
		tqadp_set_condition = DDS_TRUE;
	}
	else
	{
		tqadp_set_condition = DDS_FALSE;
    }


	if((UInt32)tqadp_reset_condition == (UInt32)DDS_TRUE)
	{
		tqadpcmp_bq = DDS_FALSE;
	}
	else if ((UInt32)tqadp_set_condition == (UInt32)DDS_TRUE)
	{
		tqadpcmp_bq = DDS_TRUE;
	}
	else
	{
		/* keep tqadpcmp_bq */
	}

    if (((UInt32)DDS_FALSE == (UInt32)tqadpcmp_t4_03_filtre_is_filter_initialised) ||((UInt32)DDS_FALSE == (UInt32)tqadpcmp_bq))
	{
	  tqadp_filter_prev = DDS_M_FILTER_LP1_U16_INIT(&tqadpcmp_t4_03_filtre, tqcmp_pwracswtbffil);
	  tqadpcmp_t4_03_filtre_is_filter_initialised = DDS_TRUE;
    }
    else
    {
	  tqadp_filter_prev = DDS_M_FILTER_LP1_U16(&tqadpcmp_t4_03_filtre, tqcmp_pwracswtbffil, tqadp_input_k_u16_b10, BIN10);
	}



    if( ((UInt32)TqCmp_bACCluSel != (UInt32)DDS_FALSE)
      &&((UInt32)TqCmp_pwrAC == 0) )
    {
		/* do nothing */
	}
	else
	{
		TqCmp_pwrACExtECULossCf = (UInt16)DDS_M_MIN((UInt32)tqadp_filter_prev,5000);
	}
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Adaptation_T4
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Adaptation_T4(
                                           UInt8 ac_bacclu_par,
                                           UInt8 frm_binhacexteculossmdl_par,
                                           UInt8 tqres_bdftacswton_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2023.FR.4.2 */
    t_dds_m_edge_detected_event tqadpcmp_edge_out;
    UInt32 tqadpcmp_turn_out;
    UInt32 tqadpcmp_te;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_04_edge_detect_1,ac_bacclu_par);

    if(  ((UInt32)tqadpcmp_edge_out != (UInt32)DDS_M_NO_EDGE_DETECTED)
       ||((UInt32)frm_binhacexteculossmdl_par == (UInt32)DDS_TRUE))
    {
        TqAdp_bFrzAdpACExtECUOnCf = DDS_TRUE;
    }
    else
    {
        TqAdp_bFrzAdpACExtECUOnCf = DDS_FALSE;
    }

    if(  (  ((UInt32)TqCmp_pwrAC == 0)
          &&((UInt32)TqCmp_bACClu != (UInt32)DDS_FALSE))
       ||((UInt32)tqres_bdftacswton_par == (UInt32)DDS_TRUE))
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_04_edge_detect_2,DDS_TRUE);
    }
    else
    {
        tqadpcmp_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_04_edge_detect_2,DDS_FALSE);
    }

    tqadpcmp_turn_out = (UInt32)DDS_M_TURN_ON_DELAY(tqadpcmp_bacextecuoffdftselon_dly,
                                                    tqadpcmp_te,
                                                    ((UInt32)TqCmp_tiMaxACOffDft_C*DEC1),
                                                    &tqadpcmp_t4_04_turn_on_delay);

    if(tqadpcmp_turn_out != (UInt32)DDS_FALSE)
    {
        tqadpcmp_bacextecuoffdftselon_dly = DDS_FALSE;
    }
    else if((UInt32)tqadpcmp_edge_out == (UInt32)DDS_M_POSITIVE_EDGE_DETECTED)
    {
        tqadpcmp_bacextecuoffdftselon_dly = DDS_TRUE;
    }
    else
    {
        /* nothing to do */
    }
    TqCmp_bACExtECUOffDftSelOnCf = tqadpcmp_bacextecuoffdftselon_dly;
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Air_Cond_T4_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T4_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACExtECUOn_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bACExtECUOffDftSelOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACExtECULoss_swc_out /* BIN0 */)
{
    *TqAdp_bFrzAdpACExtECUOn_swc_out = DDS_FALSE;
    *TqCmp_bACExtECUOffDftSelOn_swc_out = DDS_FALSE;
    *TqCmp_pwrACExtECULoss_swc_out = 0;

    TqAdp_bAvlACExt = DDS_FALSE;
    TqCmp_pwrACExtECULossCf = 0;
    TqAdp_bFrzAdpACExtECUOnCf = DDS_FALSE;
    TqCmp_bACExtECUOffDftSelOnCf = DDS_FALSE;

    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_t4_02_turn_on_delay);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_t4_02_turn_off_delay);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_t4_04_turn_on_delay);

    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_04_edge_detect_2,
                           DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_04_edge_detect_1,
                           DDS_FALSE);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_04_edge_detect_3,
                           DDS_FALSE);

    tqadpcmp_bacextecuoffdftselon_dly = DDS_FALSE;

    tqadpcmp_t4_03_filtre_is_filter_initialised = DDS_FALSE;

    TqCmp_bACClu = DDS_FALSE;
	TqCmp_bACCluSel = DDS_FALSE;
	TqCmp_pwrAC = 0;
	tqadpcmp_bq = 0;
	tqadp_filter_prev = 0;
}



#define TQADPCMP_STOP_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 7.02
* Date: 21/11/2013 09:40:16
* PERL v5.14.2
* Lib_CC 1.36
* Lib_Clipboard 1.01
* Lib_CQ 1.21
* Lib_DD_Check 2.12
* Lib_DD_Check_Checks 1.51
* Lib_DD_Check_Data 2.10
* Lib_DD_Check_Utils 2.14
* Lib_DD_Compare 1.10
* Lib_DD_GenCode 3.30
* Lib_DD_Load 3.08
* Lib_DD_Load 3.10
* Lib_DD_Structure 1.10
* Lib_Feature 1.02
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.03
* Lib_Gui_ComboBox 1.07
* Lib_Gui_Common 1.43
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.02
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.18
* Lib_Hash 1.33
* Lib_Log 1.32
* Lib_Maths 1.10
* Lib_Pjt 1.32
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.26
* Lib_Scheduler_Tag 2.27
* Lib_Scheduler_XML 1.48
* Lib_Spectool_Gen_DD 2.23
* Lib_Twk 1.06
* Lib_Utils 1.06
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.09
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* INPUT_SECTION *
AC_bACClu ;["FALSE"|"TRUE"] ;AC ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag embrayage du compresseur de clim ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
AC_pwrAC ; ;AC ;W ;0 ;6350 ;25 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Puissance preleve par le systeme de Clim de type 4 (estimateur de couple situe dans le BSI). (W = variable x 25) ;["YES"] ;UInt8 ;1/25 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_pAC ; ;EXT ;mbar ;0 ;31000 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;PressRefri post traitement envoyee a l applicatif ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_stACTypCf ;["PAS_DE_CLIM"*0*|"CLIM_TYPE_3"*1*|"CLIM_TYPE_4"*2*|"RESERVE_3"*3*|"RESERVE_4"*4*|"RESERVE_5"*5*|"RESERVE_6"*6*|"RESERVE"*7*] ;EXT ;N/A ;0 ;7 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Presence et type de climatisation (Refri) ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_tAir ; ;EXT ;deg C ;-40 ;100 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Temperature exterieure ;["YES"] ;SInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
FRM_bInhACExtECULossMdl ;["FALSE"|"TRUE"] ;FRM ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;FID de non disponibilite du flag embrayage du compresseur de clim ou de la puissance preleve par le systeme de Clim de type 4 ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqRes_bDftACSwtOn ;["FALSE"|"TRUE"] ;TQRES ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Defaut de declenchement reserve clim ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
TqAdp_bFrzAdpACExtECUOn ;["FALSE"|"TRUE"] ;TQADP ;N/A ;0 ;1 ;1 ;["NULL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen interdisant l’apprentissage de l’adaptatif de pertes en cas d’embrayage ou de debrayage du compresseur de climatisation de type 4. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bACExtECUOffDftSelOn ;["FALSE"|"TRUE"] ;TQCMP ;N/A ;0 ;1 ;1 ;["NULL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Requete de debrayage du compresseur en cas d’incoherence des variables d’entree (puissance nulle alors que le flag embrayage est non nul). ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrACExtECULoss ; ;TQCMP ;W ;0 ;5000 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Puissance calcule preleve par le systeme de Clim de type 4 ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
TQADPCMP_4_SIZE ; ;TQADPCMP ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;4 ;4 size for Table ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bAvlACExt ;["FALSE"|"TRUE"] ;TQADP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booléen d'activation de la fonction Estimation Puissance Clim4. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqAdp_bFrzAdpACExtECUOnCf ;["FALSE"|"TRUE"] ;TQADP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booléen interdisant l’apprentissage de l’adaptatif de pertes en cas d’embrayage ou de débrayage du compresseur de climatisation de type 4, avant variantage. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bACClu ;["FALSE"|"TRUE"] ;TQCMP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag embrayage du compresseur avec prise en compte de la valeur d’inhibition. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bACCluSel ;["FALSE"|"TRUE"] ;TQCMP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag embrayage du compresseur temporise ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_bACExtECUOffDftSelOnCf ;["FALSE"|"TRUE"] ;TQCMP ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Requête de débrayage du compresseur en cas d’incohérence des variables d’entrée (puissance nulle alors que le flag embrayage est non nul), avant variantage. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_facACFilAcv_T ; ;TQADP ;N/A ;0 ;1 ;0.001 ;["MAP"] ;["N/A"] ;N/A ;N/A ;N/A ;[1 0.5 0.1 0.01] ;Facteur du filtre à l’enclenchement fonction du delta de pression du circuit clim ;["YES"] ;DDS_M_MAP2D_U16 ;BIN10 ;TqCmp_pDeltaACflow_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_facFilTqACExtECUOff_C ; ;TQCMP ;N/A ;0 ;1 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.1 ;Coefficient de filtrage du couple calcule ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pDeltaACflow_A ;1{t_tqcmp_pdeltaacflow_a}TQADPCMP_4_SIZE ;TQADP ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 13 26 40] ;Breakpoint de pression pour le delta pression clim / pression de saturation ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pFlowSatPres_T ; ;TQADP ;mbar ;0 ;31000 ;1 ;["MAP"] ;["N/A"] ;N/A ;N/A ;N/A ;[3 5 8 12] ;Pression de saturation de la climatisation ;["YES"] ;DDS_M_MAP2D_SU16 ;BIN0 ;TqCmp_tAirFlowPres_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrAC ; ;TQCMP ;W ;0 ;6350 ;25 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Puissance prelevee par le compresseur de climatisation avec prise en compte de la valeur d’inhibition. ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrACExtECULossCf ; ;TQCMP ;W ;0 ;5000 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Puissance calculé prélevé par le système de Clim de type 4, avant variantage. ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_pwrThdDiFil_C ; ;TQCMP ;W ;0 ;6325 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;1 ;Seuil en dessous duquel on reset le filtre ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tAirFlowPres_A ;1{t_tqcmp_tairflowpres_a}TQADPCMP_4_SIZE ;TQADP ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 15 30 45] ;Breakpoint en température d’air pour la pression de satutation ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tiACExtECUOff_C ; ;TQCMP ;s ;0 ;5 ;0.02 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.2 ;Delai entre le debrayage du compresseur par la BSI et l’arret de prise de couple sur l’arbre moteur. ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tiACExtECUOn_C ; ;TQCMP ;s ;0 ;5 ;0.02 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.2 ;Delai entre l’embrayage du compresseur par la BSI et la prise de couple sur l’arbre moteur ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tiMaxACOffDft_C ; ;TQCMP ;s ;0 ;5 ;0.02 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.5 ;Delai max entre le debrayage du compresseur par la BSI et l’arret de prise de couple sur l’arbre moteur. ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_tqcmp_pdeltaacflow_a ; ;TQADPCMP ;mbar ;0 ;31000 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;type ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_tqcmp_tairflowpres_a ; ;TQADPCMP ;degC ;-40 ;100 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;type ;["NO"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

/* Function_Interface_1.0
* Lib_Scheduler_Tag 2.27 *
* Tool : DD_Editor 7.02 *

Function_Interface */

