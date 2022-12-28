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
* Ref X:\integration_view_00PSASWC_E521D11\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Estim_Bva.c
* Version int :/main/L02_05/1 Date: 2/5/2013 12 h 23 m User:posmyk 
*    TWK_model:TQADPCMP_Estim_Bva_L02_050_IMPL1
*    comments :New remark tracking sheet filled by PSA for TqAdpCmp 12.1 €6. R6515133 7.1 
* Version dev :\main\branch_thauvin_euro6\2 Date: 26/4/2013 11 h 47 m User:thauvin 
*    TWK_model:TQADPCMP_Estim_Bva_L02_050_IMPL1
*    comments :New remark tracking sheet filled by PSA for TqAdpCmp 12.1 €6
*    comments :R6515133 7.1 
* Version dev :\main\branch_thauvin_euro6\1 Date: 19/4/2013 9 h 57 m User:thauvin
*    TWK_model:TQADPCMP_Estim_Bva_L02_050_IMPL1
*    comments :For TqAdpCmp 12.1 / CSMT_CGMT06_2021 3.3
* Version int :/main/L02_04/1 Date: 9/8/2012 12 h 29 m User:meme
*    TWK_model:TQADPCMP_Estim_Bva_L02_040_IMPL1
*    comments :For TqAdpCmp_12_0_e6, correction for UT
* Version dev :\main\branch_halouane_tqadpcmp_e6\2 Date: 7/8/2012 10 h 12 m User:halouane
*    TWK_model:TQADPCMP_Estim_Bva_L02_040_IMPL1
*    comments :For TqAdpCmp_12_0_e6, correction for UT
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 25/7/2012 10 h 23 m User:halouane
*    TWK_model:TQADPCMP_Estim_Bva_L02_040_IMPL1
*    comments :For TqAdpCmp_12_0_e6
* Version int :/main/L02_03/1 Date: 21/3/2012 15 h 9 m User:esnault
*    TWK_model:TQADPCMP_Estim_Bva_L02_030_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 29/2/2012 15 h 43 m User:halouane
*    TWK_model:TQADPCMP_Estim_Bva_L02_030_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_02/1 Date: 14/9/2011 16 h 27 m User:meme
*    TWK_model:TQADPCMP_Estim_Bva_L02_020_IMPL1
*    comments :dev TqAdpCmp 10.6
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 12/9/2011 12 h 31 m User:halouane
*    TWK_model:TQADPCMP_Estim_Bva_L02_020_IMPL1
*    comments :dev TqAdpCmp 10.6
* Version dev :\main\branch_demezil_tqadpcmp_dev\1 Date: 29/4/2011 9 h 24 m User:demezil
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1_D
*    comments :to reduce CPU load
* Version int :/main/L02_01/1 Date: 13/9/2010 14 h 20 m User:esnault
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 10/9/2010 10 h 1 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 28/6/2010 16 h 51 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Bva_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_02/1 Date: 9/9/2009 13 h 30 m User:langendorf
*    TWK_model:TQADPCMP_Estim_Bva_L01_020_IMPL1
*    comments :change limitation : . DDS_M_MAX -> DDS_M_MIN
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 3/9/2009 11 h 30 m User:lemort
*    TWK_model:TQADPCMP_Estim_Bva_L01_020_IMPL1
*    comments :change limitation :
*    comments :DDS_M_MAX -> DDS_M_MIN
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 1/9/2009 11 h 5 m User:lemort
*    TWK_model:TQADPCMP_Estim_Bva_L01_020_IMPL1
*    comments :new model : . 1 prev : DISP -> NULL
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 7 m User:boucher
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL3
*    comments :Add as extern axe TqCmp_v_CA
* Version dev :\main\branch_moisan_tqadpcmp_validation\4 Date: 15/10/2008 10 h 6 m User:moisan
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL3
*    comments :Add as extern axe TqCmp_v_CA
* Version dev :\main\branch_moisan_tqadpcmp_validation\3 Date: 10/10/2008 10 h 38 m User:moisan
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL2
*    comments :Correction of Fail
* Version dev :\main\branch_moisan_tqadpcmp_validation\2 Date: 7/10/2008 16 h 38 m User:moisan
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL2
*    comments :Correction of fail test
* Version dev :\main\branch_moisan_integ_tqadpcmp\1 Date: 26/9/2008 14 h 3 m User:moisan
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL1
*    comments :Bad resolution of TqCmp_CoefCnvLossRed_GearX_A
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 26/9/2008 13 h 14 m User:moisan
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL1
*    comments :wrong limitation of TqCmp_tqCnvLossRed
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\1 Date: 18/9/2008 16 h 56 m User:girodon
*    TWK_model:TQADPCMP_Estim_Bva_L01_010_IMPL1
*    comments :Implement "CSMT_CGMT06_2021 v2.0" (R6515133 1.0).
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

#define COPT_STDRAGRED_PARK_OU_N            0
#define COPT_STDRAGRED_DEBRAYE_A_LARRET     1
#define COPT_STDRAGRED_INFO_INDISPONIBLE    3

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
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_spdVehDftCnv_C = (UInt16)(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqCnvLossMin_C = (UInt16)(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqGrdFrzAdpCnv_C = (UInt16)(10 * BIN4);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bNCkTypSel_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bInhTqTraCdn_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_idxCnvTyp_C = (UInt8)(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_bCnvLossNewClc_C = DDS_TRUE;
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqCnvLossDown_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10),
(UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10),
(UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10),
(UInt16)(0.01 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTqCnvLossUp_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10),
(UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10),
(UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10), (UInt16)(0.01 * BIN10),
(UInt16)(0.01 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvDrvNEng_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(13 * BIN4), (UInt16)(22 * BIN4),
(UInt16)(25 * BIN4), (UInt16)(26 * BIN4), (UInt16)(30 * BIN4),
(UInt16)(31 * BIN4), (UInt16)(34 * BIN4), (UInt16)(34 * BIN4),
(UInt16)(34 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvDrvRatNCk_T
[TQADPCMP_8_SIZE] = {
(UInt16)(1 * BIN8), (UInt16)(1 * BIN8), (UInt16)(1 * BIN8),
(UInt16)(1 * BIN8), (UInt16)(1 * BIN8), (UInt16)(1 * BIN8),
(UInt16)(1 * BIN8), (UInt16)(1 * BIN8)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvDrvTOilGBx_T
[TQADPCMP_5_SIZE] = {
(UInt16)(0.41 * BIN6), (UInt16)(0.58 * BIN6), (UInt16)(0.86 * BIN6),
(UInt16)(1.14 * BIN6), (UInt16)(1 * BIN6)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvNeut_T
[TQADPCMP_5_SIZE] = {
(UInt16)(0.41 * BIN6), (UInt16)(0.58 * BIN6), (UInt16)(0.86 * BIN6),
(UInt16)(1.14 * BIN6), (UInt16)(1 * BIN6)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvLossSpdVeh_T
[TQADPCMP_5_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvRedNEng_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(8 * BIN4), (UInt16)(11 * BIN4),
(UInt16)(13 * BIN4), (UInt16)(15 * BIN4), (UInt16)(14 * BIN4),
(UInt16)(14 * BIN4), (UInt16)(15 * BIN4), (UInt16)(16 * BIN4),
(UInt16)(16 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvRedRatNCk_T
[TQADPCMP_8_SIZE] = {
(UInt16)(1 * BIN8), (UInt16)(1 * BIN8), (UInt16)(1 * BIN8),
(UInt16)(1 * BIN8), (UInt16)(1 * BIN8), (UInt16)(1 * BIN8),
(UInt16)(1 * BIN8), (UInt16)(1 * BIN8)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqCnvRedTOilGBx_T
[TQADPCMP_5_SIZE] = {
(UInt16)(0.41 * BIN6), (UInt16)(0.58 * BIN6), (UInt16)(0.86 * BIN6),
(UInt16)(1.14 * BIN6), (UInt16)(1 * BIN6)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_nCkCnv_A[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(500 * BIN2), (UInt16)(750 * BIN2),
(UInt16)(800 * BIN2), (UInt16)(820 * BIN2), (UInt16)(850 * BIN2),
(UInt16)(900 * BIN2), (UInt16)(950 * BIN2), (UInt16)(1000 * BIN2),
(UInt16)(4500 * BIN2)
};


STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_nCkCnvX_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(500 * BIN2), (UInt16)(750 * BIN2),
(UInt16)(800 * BIN2), (UInt16)(850 * BIN2), (UInt16)(900 * BIN2),
(UInt16)(1000 * BIN2), (UInt16)(4500 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_rNCkCnvY_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN5), (UInt16)(0.25 * BIN5), (UInt16)(0.5 * BIN5),
(UInt16)(1 * BIN5), (UInt16)(1.5 * BIN5), (UInt16)(2 * BIN5),
(UInt16)(2.5 * BIN5), (UInt16)(3 * BIN5)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_rNCkCnv_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN5), (UInt16)(0.25 * BIN5), (UInt16)(0.5 * BIN5),
(UInt16)(1 * BIN5), (UInt16)(1.5 * BIN5), (UInt16)(2 * BIN5),
(UInt16)(2.5 * BIN5), (UInt16)(3 * BIN5)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_spdVehCnv_A[TQADPCMP_5_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(7 * BIN7), (UInt16)(15 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(100 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tOilGBxCnv_A[TQADPCMP_5_SIZE] = {
(SInt16)(-25 * BIN2), (SInt16)(0 * BIN2), (SInt16)(30 * BIN2),
(SInt16)(65 * BIN2), (SInt16)(80 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqCnvLossMax_T
[TQADPCMP_5_SIZE] = {
(UInt16)(500 * BIN4), (UInt16)(500 * BIN4), (UInt16)(500 * BIN4),
(UInt16)(500 * BIN4), (UInt16)(500 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_facTqCnvRatNCk_M
[TQADPCMP_8_SIZE][TQADPCMP_8_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)}
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_facTqCnvRatNeut_M
[TQADPCMP_8_SIZE][TQADPCMP_8_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)},
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4),(SInt16)(0 * BIN4),
(SInt16)(0 * BIN4),(SInt16)(0 * BIN4)}
};
#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqcnvlossdown_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltqcnvlossup_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvdrvneng_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvdrvratnck_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvdrvtoilgbx_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvneut_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvlossspdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvredneng_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvredratnck_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_factqcnvredtoilgbx_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tqcnvlossmax_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_06_filtre;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) ttqcmp_factqcnvratnck_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) ttqcmp_factqcnvratneut_m_sav;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqcmp_tqcnvloss_prev;
#define TQADPCMP_STOP_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_06_filter_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_nCkFil; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_nTrb; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_spdVehCnvSel; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossDrv; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossRed; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossUnlim; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossRawNew; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossClcRaw; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossClcNeut; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqCmp_tqCnvLossRawOld; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bCnvLossNewClc;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQCNVLOSSDOWN_T_APM = {
&tqcmp_facfiltqcnvlossdown_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqCnvLossDown_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILTQCNVLOSSUP_T_APM = {
&tqcmp_facfiltqcnvlossup_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTqCnvLossUp_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACTQCNVDRVNENG_T_APM = {
&tqcmp_factqcnvdrvneng_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvDrvNEng_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACTQCNVDRVRATNCK_T_APM = {
&tqcmp_factqcnvdrvratnck_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rNCkCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvDrvRatNCk_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_FACTQCNVDRVTOILGBX_T_APM = {
&tqcmp_factqcnvdrvtoilgbx_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tOilGBxCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvDrvTOilGBx_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_FACTQCNVNEUT_T_APM = {
&tqcmp_factqcnvneut_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tOilGBxCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvNeut_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACTQCNVLOSSSPDVEH_T_APM = {
&tqcmp_factqcnvlossspdveh_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_spdVehCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvLossSpdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACTQCNVREDNENG_T_APM = {
&tqcmp_factqcnvredneng_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvRedNEng_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACTQCNVREDRATNCK_T_APM = {
&tqcmp_factqcnvredratnck_t_sav,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rNCkCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvRedRatNCk_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_FACTQCNVREDTOILGBX_T_APM = {
&tqcmp_factqcnvredtoilgbx_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tOilGBxCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvRedTOilGBx_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_TQCNVLOSSMAX_T_APM = {
&tqcmp_tqcnvlossmax_t_sav,
TQADPCMP_5_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tOilGBxCnv_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqCnvLossMax_T[0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQCMP_FACTQCNVRATNCK_M_APM = {
&ttqcmp_factqcnvratnck_m_sav,
TQADPCMP_8_SIZE,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkCnvX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rNCkCnvY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvRatNCk_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQCMP_FACTQCNVRATNEUT_M_APM = {
&ttqcmp_factqcnvratneut_m_sav,
TQADPCMP_8_SIZE,
TQADPCMP_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkCnvX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_rNCkCnvY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facTqCnvRatNeut_M[0][0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Des_Entrees_Bva(
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           UInt16 copt_ntrb_par, /* BIN2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 frm_binhcnvlossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calcul_Couple_Drive(
                                           SInt16 copt_toilgbx_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Calcul_Couple_Reduction_Trainee(
                                           SInt16 copt_toilgbx_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_GestionND(
                                           UInt8 frm_binhcnvlossmdl_par,
                                           SInt16 copt_tqcnvclu_par, /* BIN4 */
                                           UInt8 copt_stdragred_par,
                                           UInt8 copt_btqtx_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_06_Filtrage_Attenuation(
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_07_Limitation_Adaptation(
                                           UInt8 frm_binhcnvlossmdl_par,
                                           SInt16 copt_toilgbx_par, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpcnvon_ptr,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqcnvloss_ptr /* BIN4 */);


 STATIC FUNC(void, AUTOMATIC) TQADPCMP_F08_Calcul_couple_Drive_Reduction_de_trainee( SInt16 copt_toilgbx_par,
																					UInt8 copt_stdragred_par,
																					UInt8 copt_btqtx_par,
																					UInt8 frm_binhcnvlossmdl_par,
																					SInt16 copt_tqcnvclu_par);

 STATIC FUNC(void, AUTOMATIC) TQADPCMP_F11_Calcul_couple_convertisseur_generique(SInt16 copt_tqcnvclu_par,
																				SInt16 copt_toilgbx_par,
																				UInt8 frm_binhcnvlossmdl_par,
																				UInt8 copt_stdragred_par);
STATIC FUNC(void, AUTOMATIC) TQADPCMP_F12_Choix_couple_applicable(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_F09_Calcul_couple_convertisseur(SInt16 copt_toilgbx_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_F13_Calcul_couple_convertisseur_neutre(SInt16 copt_toilgbx_par);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Bva
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Bva(UInt8 CoPt_bTqTx_swc_in,
                                           UInt16 CoPt_nTrb_swc_in, /* BIN2 */
                                           UInt8 CoPt_stDragRed_swc_in,
                                           SInt16 CoPt_tOilGBx_swc_in, /* BIN2 */
                                           SInt16 CoPt_tqCnvClu_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 FRM_bInhCnvLossMdl_swc_in,
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpCnvOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqCnvLoss_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.1.2 */

    TqCmp_bCnvLossNewClc = TqCmp_bCnvLossNewClc_C;

    TQADPCMP_02_Traitement_Des_Entrees_Bva(Veh_spdVeh_swc_in, /* BIN7 */
                                       TqSys_nTarIdl_swc_in, /* BIN2 */
                                       CoPt_nTrb_swc_in, /* BIN2 */
                                       Eng_nCkFil_swc_in, /* BIN2 */
                                       FRM_bInhCnvLossMdl_swc_in);
	/*states = held, so keep the previous values*/

	if((UInt32)DDS_FALSE !=  (UInt32)TqCmp_bCnvLossNewClc)
	{

		TQADPCMP_F11_Calcul_couple_convertisseur_generique(CoPt_tqCnvClu_swc_in,
															CoPt_tOilGBx_swc_in,
															FRM_bInhCnvLossMdl_swc_in,
															CoPt_stDragRed_swc_in);
	}
	else
	{
		TQADPCMP_F08_Calcul_couple_Drive_Reduction_de_trainee(  CoPt_tOilGBx_swc_in,
																CoPt_stDragRed_swc_in,
																CoPt_bTqTx_swc_in,
																FRM_bInhCnvLossMdl_swc_in,
															    CoPt_tqCnvClu_swc_in);
	}

	TQADPCMP_F12_Choix_couple_applicable();

    TQADPCMP_06_Filtrage_Attenuation(Eng_nCkFil_swc_in /* BIN2 */);

    TQADPCMP_07_Limitation_Adaptation(FRM_bInhCnvLossMdl_swc_in,
                                      CoPt_tOilGBx_swc_in, /* BIN2 */
                                      TqAdp_bFrzAdpCnvOn_swc_out,
                                      TqCmp_tqCnvLoss_swc_out /* BIN4 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_02_Traitement_Des_Entrees_Bva
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Des_Entrees_Bva(
                                           UInt16 veh_spdveh_par, /* BIN7 */
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           UInt16 copt_ntrb_par, /* BIN2 */
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 frm_binhcnvlossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.2.0 */
    UInt32 tqadpcmp_02_test_out;

    if((UInt32)TqCmp_bNCkTypSel_C != (UInt32)DDS_FALSE)
    {
        tqadpcmp_02_test_out = (UInt32)eng_nckfil_par;
    }
    else
    {
        tqadpcmp_02_test_out = (UInt32)tqsys_ntaridl_par;
    }

    if(tqadpcmp_02_test_out != 0)
    {
        TqCmp_nCkFil = (UInt16)tqadpcmp_02_test_out;
    }
    else
    {
        TqCmp_nCkFil = (UInt16)(1 * BIN2);
    }

    if((UInt32)frm_binhcnvlossmdl_par != (UInt32)DDS_FALSE)
    {
        TqCmp_spdVehCnvSel = TqCmp_spdVehDftCnv_C;
        TqCmp_nTrb = TqCmp_nCkFil;
    }
    else
    {
        TqCmp_spdVehCnvSel = veh_spdveh_par;
        TqCmp_nTrb = copt_ntrb_par;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Calcul_Couple_Drive
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calcul_Couple_Drive(
                                           SInt16 copt_toilgbx_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.3.0 */
    UInt32 tqadpcmp_03_tmp;
    UInt16 tqadpcmp_03_a_u16;
    UInt16 tqadpcmp_03_b_u16;
    UInt16 tqadpcmp_03_c_u16;
    UInt32 tqadpcmp_03_map_in;

    /* TqCmp_tqCnvLossDrv */
    /*--------------------*/

    /* [0;500] BIN4 */
    tqadpcmp_03_a_u16 = DDS_M_MAP2D_U16(&TQCMP_FACTQCNVDRVNENG_T_APM, TqCmp_nCkFil);


        /* BIN5 = (BIN2 * BIN5) / BIN2 */
        /* [0; 32000] = [0; 8000] / [1; 8000] */
        /* <PRQA_COMMENT><2834> Division by zero not possible </2834></PRQA_COMMENT> */
    tqadpcmp_03_map_in = (((UInt32)TqCmp_nTrb * BIN5) / (UInt32)TqCmp_nCkFil);


    /* Limitation to [0; 1] BIN5 */
    tqadpcmp_03_map_in = DDS_M_MIN(tqadpcmp_03_map_in, (UInt32)(1 * BIN5));

    /* [0;3] BIN8 */
    tqadpcmp_03_b_u16 = DDS_M_MAP2D_U16(&TQCMP_FACTQCNVDRVRATNCK_T_APM, (UInt16)tqadpcmp_03_map_in);

    /* [0;4] BIN6 */
    tqadpcmp_03_c_u16 = DDS_M_MAP2D_SU16(&TQCMP_FACTQCNVDRVTOILGBX_T_APM, copt_toilgbx_par);

    /* BIN18 = (BIN4 * BIN8) * BIN6*/
    /* [0; 6000] = ([0;500] * [0;3]) * [0;4] */
    tqadpcmp_03_tmp = ((UInt32)tqadpcmp_03_a_u16 * (UInt32)tqadpcmp_03_b_u16) * (UInt32)tqadpcmp_03_c_u16;
    /* [-2000; 2000] BIN4 */
    TqCmp_tqCnvLossDrv = (SInt16)DDS_M_MIN((tqadpcmp_03_tmp/ BIN14), (2000 * BIN4));
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Calcul_Couple_Reduction_Trainee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Calcul_Couple_Reduction_Trainee(
                                           SInt16 copt_toilgbx_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.4.0 */
    UInt32 tqadpcmp_04_tmp;
    UInt16 tqadpcmp_04_a_u16;
    UInt16 tqadpcmp_04_b_u16;
    UInt16 tqadpcmp_04_c_u16;
    UInt32 tqadpcmp_04_map_in;

    /* TqCmp_tqCnvLossDrv */
    /*--------------------*/

    /* [0;500] BIN4 */
    tqadpcmp_04_a_u16 = DDS_M_MAP2D_U16(&TQCMP_FACTQCNVREDNENG_T_APM, TqCmp_nCkFil);

    /* [0;4] BIN6 */
    tqadpcmp_04_b_u16 = DDS_M_MAP2D_SU16(&TQCMP_FACTQCNVREDTOILGBX_T_APM, copt_toilgbx_par);


        /* BIN5 = (BIN2 * BIN5) / BIN2 */
        /* [0; 32000] = [0; 8000] / [1; 8000] */
    /* <PRQA_COMMENT><2834> Division by zero not possible </2834></PRQA_COMMENT> */
    tqadpcmp_04_map_in = (((UInt32)TqCmp_nTrb * BIN5) / (UInt32)TqCmp_nCkFil);


    /* Limitation to [0; 1] BIN5 */
    tqadpcmp_04_map_in = DDS_M_MIN(tqadpcmp_04_map_in, (UInt32)(1 * BIN5));

    /* [0;1] BIN8 */
    tqadpcmp_04_c_u16 = DDS_M_MAP2D_U16(&TQCMP_FACTQCNVREDRATNCK_T_APM, (UInt16)tqadpcmp_04_map_in);

    /* BIN18 = (BIN4 * BIN6) * BIN8*/
    /* [0; 6000] = ([0;500] * [0;4]) * [0;3] */
    tqadpcmp_04_tmp = ((UInt32)tqadpcmp_04_a_u16 * (UInt32)tqadpcmp_04_b_u16) * (UInt32)tqadpcmp_04_c_u16;
    /* [-2000; 2000] BIN4 */
    TqCmp_tqCnvLossRed = (SInt16)DDS_M_MIN((tqadpcmp_04_tmp/ BIN14), ( 2000 * BIN4));
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_GestionND
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_GestionND(
                                           UInt8 frm_binhcnvlossmdl_par,
                                           SInt16 copt_tqcnvclu_par, /* BIN4 */
                                           UInt8 copt_stdragred_par,
                                           UInt8 copt_btqtx_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.5.2 */
    if(  (((UInt32)copt_btqtx_par == (UInt32)DDS_FALSE) && ((UInt32)TqCmp_bInhTqTraCdn_C == (UInt32)DDS_TRUE) )
       ||((UInt32)frm_binhcnvlossmdl_par == (UInt32)DDS_TRUE)
       ||((UInt32)copt_stdragred_par == COPT_STDRAGRED_PARK_OU_N)
       ||((UInt32)copt_stdragred_par == COPT_STDRAGRED_INFO_INDISPONIBLE))
    {
        TqCmp_tqCnvLossRawOld = 0;
    }
    else
    {
        switch((UInt32)TqCmp_idxCnvTyp_C)
        {
            case (UInt32)0:
                TqCmp_tqCnvLossRawOld = 0;
                break;
            case (UInt32)1:
                TqCmp_tqCnvLossRawOld = copt_tqcnvclu_par;
                break;
            case (UInt32)2:
            default:
                if((UInt32)copt_stdragred_par == (UInt32)COPT_STDRAGRED_DEBRAYE_A_LARRET)
                {
                    TqCmp_tqCnvLossRawOld = TqCmp_tqCnvLossRed;
                }
                else
                {
                    TqCmp_tqCnvLossRawOld = TqCmp_tqCnvLossDrv;
                }
                break;
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_06_Filtrage_Attenuation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_06_Filtrage_Attenuation(
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.6.0 */
    SInt16 tqadpcmp_06_switch_filter_in; /* BIN7 */
    UInt16 tqadpcmp_06_switch_fac_in;

    tqadpcmp_06_switch_filter_in = (SInt16)DDS_M_MAP2D_U16(&TQCMP_FACTQCNVLOSSSPDVEH_T_APM,TqCmp_spdVehCnvSel);
    tqadpcmp_06_switch_filter_in = (SInt16)(((SInt32)tqadpcmp_06_switch_filter_in * (SInt32)TqCmp_tqCnvLossRaw) / BIN7);

    if((SInt32)tqadpcmp_06_switch_filter_in>(SInt32)TqCmp_tqCnvLossUnlim)
    {
        tqadpcmp_06_switch_fac_in = DDS_M_MAP2D_U16(&TQCMP_FACFILTQCNVLOSSUP_T_APM,eng_nckfil_par);
    }
    else
    {
        tqadpcmp_06_switch_fac_in = DDS_M_MAP2D_U16(&TQCMP_FACFILTQCNVLOSSDOWN_T_APM,eng_nckfil_par);
    }


    if((UInt32)tqadpcmp_06_filter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_06_filter_init = DDS_TRUE;
        TqCmp_tqCnvLossUnlim = DDS_M_FILTER_LP1_S16_INIT(&tqadpcmp_06_filtre, tqadpcmp_06_switch_filter_in);
    }
    else
    {
        TqCmp_tqCnvLossUnlim = DDS_M_FILTER_LP1_S16(&tqadpcmp_06_filtre, tqadpcmp_06_switch_filter_in, tqadpcmp_06_switch_fac_in, BIN10);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_07_Limitation_Adaptation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_07_Limitation_Adaptation(
                                           UInt8 frm_binhcnvlossmdl_par,
                                           SInt16 copt_toilgbx_par, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqadp_bfrzadpcnvon_ptr,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqcmp_tqcnvloss_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.7.0 */
    UInt32 tqadpcmp_07_uval;
    SInt32 tqadpcmp_07_tqcnvloss_cpy;

    tqadpcmp_07_uval = (UInt32)DDS_M_MAP2D_SU16(&TQCMP_TQCNVLOSSMAX_T_APM,copt_toilgbx_par);

    tqadpcmp_07_tqcnvloss_cpy = DDS_M_SATURATION_V2((SInt32)TqCmp_tqCnvLossUnlim,
                                                    (SInt32)TqCmp_tqCnvLossMin_C,
                                                    (SInt32)tqadpcmp_07_uval);

    if((SInt32)TqCmp_tqCnvLossUnlim >= (SInt32)tqadpcmp_07_uval)
    {
        *tqadp_bfrzadpcnvon_ptr = DDS_TRUE;
    }
    else
    {
        tqadpcmp_07_uval = (UInt32)DDS_M_ABS(tqadpcmp_07_tqcnvloss_cpy - (SInt32)tqcmp_tqcnvloss_prev);

        if(  (tqadpcmp_07_uval >= (UInt32)TqCmp_tqGrdFrzAdpCnv_C)
           ||((UInt32)frm_binhcnvlossmdl_par == (UInt32)DDS_TRUE))
        {
            *tqadp_bfrzadpcnvon_ptr = DDS_TRUE;
        }
        else
        {
            *tqadp_bfrzadpcnvon_ptr = DDS_FALSE;
        }
    }



    tqcmp_tqcnvloss_prev = (UInt16) tqadpcmp_07_tqcnvloss_cpy;
    *tqcmp_tqcnvloss_ptr = (UInt16) tqadpcmp_07_tqcnvloss_cpy;
}

/*******************************************************************************
*
* Function Name :	TQADPCMP_F08_Calcul_couple_Drive_Reduction_de_trainee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_F08_Calcul_couple_Drive_Reduction_de_trainee( SInt16 copt_toilgbx_par,
																					UInt8 copt_stdragred_par,
																					UInt8 copt_btqtx_par,
																					UInt8 frm_binhcnvlossmdl_par,
																					SInt16 copt_tqcnvclu_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.8.0 */
	TQADPCMP_03_Calcul_Couple_Drive(copt_toilgbx_par /* BIN2 */);

    TQADPCMP_04_Calcul_Couple_Reduction_Trainee(copt_toilgbx_par /* BIN2 */);

    TQADPCMP_05_GestionND(frm_binhcnvlossmdl_par,
                          copt_tqcnvclu_par, /* bin4 */
                          copt_stdragred_par,
                          copt_btqtx_par);
}

/*******************************************************************************
*
* Function Name :	TQADPCMP_F11_Calcul_couple_convertisseur_generique
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_F11_Calcul_couple_convertisseur_generique(SInt16 copt_tqcnvclu_par,
																				SInt16 copt_toilgbx_par,
																				UInt8 frm_binhcnvlossmdl_par,
																				UInt8 copt_stdragred_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.10.1 */
	/*Remove the function TQADPCMP_F10_Gestion_couple for Optimization but implemented in F11*/
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.11.1 */
	/*Optimization in F10 for call only F09 or only F13 depending of CoPt_stDragRed*/



    if((UInt32)DDS_FALSE != (UInt32)frm_binhcnvlossmdl_par)
    {
		TqCmp_tqCnvLossRawNew = (SInt16)(0 * BIN4);

	}
	else
	{
	    switch((UInt32)TqCmp_idxCnvTyp_C)
		{
			case (UInt32)0:
				TqCmp_tqCnvLossRawNew = (SInt16)(0 * BIN4);
				break;

			case (UInt32)1:
				TqCmp_tqCnvLossRawNew = copt_tqcnvclu_par;
				break;
			case (UInt32)2:
			default:
				if((UInt32)copt_stdragred_par == (UInt32)0)
				{
					TQADPCMP_F13_Calcul_couple_convertisseur_neutre(copt_toilgbx_par);
					TqCmp_tqCnvLossRawNew = TqCmp_tqCnvLossClcNeut;
				}
				else
				{
					TQADPCMP_F09_Calcul_couple_convertisseur(copt_toilgbx_par);
					TqCmp_tqCnvLossRawNew = TqCmp_tqCnvLossClcRaw;
				}
				break;
		}
	}

}

/*******************************************************************************
*
* Function Name :	TQADPCMP_F12_Choix_couple_applicable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_F12_Choix_couple_applicable(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.12.0 */
	if((UInt32)DDS_FALSE != (UInt32)TqCmp_bCnvLossNewClc)
	{
		TqCmp_tqCnvLossRaw = TqCmp_tqCnvLossRawNew ;
	}
	else
	{
		TqCmp_tqCnvLossRaw = TqCmp_tqCnvLossRawOld;
	}
}

/*******************************************************************************
*
* Function Name :	TQADPCMP_F09_Calcul_couple_convertisseur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_F09_Calcul_couple_convertisseur(SInt16 copt_toilgbx_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.9.0 */
    UInt32 tqadpcmp_09_map_in;
    UInt16 tqadpcmp_u16_temp1;
    SInt16 tqadpcmp_s16_temp1;

	/* BIN5 = (BIN2 * BIN5) / BIN2 */
	/* [0; 32000] = [0; 8000] / [1; 8000] */
	/* <PRQA_COMMENT><2834> Division by zero not possible </2834></PRQA_COMMENT> */
    tqadpcmp_09_map_in = (((UInt32)TqCmp_nTrb * BIN5) / (UInt32)TqCmp_nCkFil);


    /* Limitation to [0; 1] BIN5 */
    tqadpcmp_09_map_in = DDS_M_MIN(tqadpcmp_09_map_in, (UInt32)(1 * BIN5));

	/*[-500;500]BIN4*/
	tqadpcmp_s16_temp1 = DDS_M_MAP3D_UUS16(&TQCMP_FACTQCNVRATNCK_M_APM,
                                                TqCmp_nCkFil ,
    										 (UInt16)tqadpcmp_09_map_in);

     /*[0;4]BIN6*/
     tqadpcmp_u16_temp1 =  DDS_M_MAP2D_SU16(&TQCMP_FACTQCNVDRVTOILGBX_T_APM, copt_toilgbx_par);

     /*[-2000;2000] = [0;4] *[-500;500]*/
     /*BIN4 = (BIN4 *BIN6) / BIN6*/
     TqCmp_tqCnvLossClcRaw = (SInt16)(((SInt32)tqadpcmp_s16_temp1 * (SInt32)tqadpcmp_u16_temp1) / BIN6);
}

/*******************************************************************************
*
* Function Name :	TQADPCMP_F13_Calcul_couple_convertisseur_neutre
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_F13_Calcul_couple_convertisseur_neutre(SInt16 copt_toilgbx_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2021.FR.13.0 */
    UInt32 tqadpcmp_13_map_in;
    UInt16 tqadpcmp_u16_temp1;
    SInt16 tqadpcmp_s16_temp1;

	/* BIN5 = (BIN2 * BIN5) / BIN2 */
	/* [0; 32000] = [0; 8000] / [1; 8000] */
	/* <PRQA_COMMENT><2834> Division by zero not possible </2834></PRQA_COMMENT> */
    tqadpcmp_13_map_in = (((UInt32)TqCmp_nTrb * BIN5) / (UInt32)TqCmp_nCkFil);


    /* Limitation to [0; 1] BIN5 */
    tqadpcmp_13_map_in = DDS_M_MIN(tqadpcmp_13_map_in, (UInt32)(1 * BIN5));

	/*[-500;500]BIN4*/
	tqadpcmp_s16_temp1 = DDS_M_MAP3D_UUS16(&TQCMP_FACTQCNVRATNEUT_M_APM,
                                                TqCmp_nCkFil ,
    										 (UInt16)tqadpcmp_13_map_in);

     /*[0;4]BIN6*/
     tqadpcmp_u16_temp1 =  DDS_M_MAP2D_SU16(&TQCMP_FACTQCNVNEUT_T_APM, copt_toilgbx_par);

     /*[-2000;2000] = [0;4] *[-500;500]*/
     /*BIN4 = (BIN4 *BIN6) / BIN6*/
     TqCmp_tqCnvLossClcNeut = (SInt16)(((SInt32)tqadpcmp_s16_temp1 * (SInt32)tqadpcmp_u16_temp1) / BIN6);
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Bva_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Bva_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpCnvOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_tqCnvLoss_swc_out /* BIN4 */)
{
    /* Initialise outputs */
    *TqAdp_bFrzAdpCnvOn_swc_out = DDS_FALSE;
    *TqCmp_tqCnvLoss_swc_out = (0 * BIN4);

    tqadpcmp_06_filter_init = DDS_FALSE;
    tqcmp_tqcnvloss_prev = 0;

    TqCmp_nTrb = 0;
    TqCmp_tqCnvLossUnlim = 0;

	TqCmp_tqCnvLossRed = 0;
	TqCmp_spdVehCnvSel = 0;
	TqCmp_tqCnvLossRaw = 0;
	TqCmp_tqCnvLossDrv = 0;
	TqCmp_nCkFil = 0;
	TqCmp_bCnvLossNewClc = DDS_FALSE;
	TqCmp_tqCnvLossRawNew = 0;
	TqCmp_tqCnvLossClcRaw = 0;
	TqCmp_tqCnvLossClcNeut = 0;
	TqCmp_tqCnvLossRawOld = 0;
}


#define TQADPCMP_STOP_SEC_CODE
#include "TqAdpCmp_MemMap.h"

