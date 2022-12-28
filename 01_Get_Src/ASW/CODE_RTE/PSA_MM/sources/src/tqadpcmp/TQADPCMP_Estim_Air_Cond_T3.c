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
* Ref X:\integration_view_00PSASWC_E511D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Estim_Air_Cond_T3.c
* Version int :/main/L03_02/1 Date: 23/4/2012 11 h 58 m User:meme 
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L03_020_IMPL1
*    comments :For TqAdCmp_11_1_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 18/4/2012 15 h 24 m User:halouane 
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L03_020_IMPL1
*    comments :For TqAdCmp_11_1_e6
* Version int :/main/L03_01/1 Date: 21/3/2012 15 h 9 m User:esnault
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\2 Date: 2/3/2012 10 h 17 m User:halouane
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 2/3/2012 10 h 4 m User:halouane
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_01/3 Date: 14/9/2011 16 h 28 m User:meme
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_halouane_tqadpcmp_euro6\1 Date: 14/9/2011 14 h 25 m User:halouane
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2_D
*    comments :code optimisation for TqAdpCmp 10.6 / same code that prev file tested (branch_demezil)
* Version dev :\main\branch_demezil_tqadpcmp_dev\1 Date: 29/4/2011 9 h 26 m User:demezil
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2_D
*    comments :to reduce CPU load
* Version int :/main/L02_01/2 Date: 18/11/2010 12 h 48 m User:meme
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2_D
*    comments :For TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 16/11/2010 17 h 0 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2_D
*    comments :For TqAdpCmp 10.2
* Version int :/main/L02_01/1 Date: 13/9/2010 14 h 19 m User:esnault
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2
*    comments :For TqAdpCmp 10.0 Euro-6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 8/9/2010 9 h 37 m User:veillard
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL2
*    comments :For TqAdpCmp 10.0 Euro-6
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 6/9/2010 14 h 40 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 29/6/2010 9 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L02_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version int :/main/L01_02/1 Date: 9/9/2009 13 h 30 m User:langendorf
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_020_IMPL1
*    comments :to delete QAC warning
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 24/8/2009 13 h 32 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_020_IMPL1
*    comments :to delete QAC warning
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 24/8/2009 13 h 11 m User:lemort
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_020_IMPL1
*    comments :work in progress, adaptation for STIL 2.0
* Version int :/main/L01_01/2 Date: 23/10/2008 14 h 6 m User:boucher
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_010_IMPL2
*    comments :No change in code, only design (TqCmp_facFilg_T has a new unit)
* Version dev :\main\branch_moisan_tqadpcmp_validation\3 Date: 16/10/2008 13 h 42 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_010_IMPL2
*    comments :No change in code, only design (TqCmp_facFilg_T has a new unit)
* Version dev :\main\branch_moisan_tqadpcmp_validation\2 Date: 13/10/2008 12 h 16 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_010_IMPL1
*    comments :Fail correction: TqCmp_tqAC3BasLoss should be initialized
* Version dev :\main\branch_moisan_tqadpcmp_validation\1 Date: 10/10/2008 11 h 18 m User:moisan
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_010_IMPL1
*    comments :Correction fo Fail
* Version dev :\main\branch_girodon_tqadpcmp_1_dev\3 Date: 22/9/2008 17 h 4 m User:girodon
*    TWK_model:TQADPCMP_Estim_Air_Cond_T3_L01_010_IMPL1
*    comments :Implement "CSMT_CGMT06_1930 v2.0 / R6515129 1.0".
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

#define TQADPCMP_03_01_02_CNT_MAX             ((UInt32)(400 * DEC3))
#define TQADPCMP_INCREMENT_COUNTER            ((UInt32)(0.01* DEC3))

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
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilACItECULoss_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilACItECUSelOn_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facTqACItECU_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiACItECUOff_C = (CONST(UInt16, AUTOMATIC))(0.04 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiACItECUOn_C = (CONST(UInt16, AUTOMATIC))(0.08 * DEC2);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facACItECULd_T
[TQADPCMP_10_SIZE] = {
(UInt16)(1 * BIN10), (UInt16)(0.72 * BIN10), (UInt16)(0.72 * BIN10),
(UInt16)(0.5 * BIN10), (UInt16)(0.5 * BIN10), (UInt16)(0.4 * BIN10),
(UInt16)(0.4 * BIN10), (UInt16)(0.3 * BIN10), (UInt16)(0.3 * BIN10),
(UInt16)(0.25 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facCnvTqPwr_M
[TQADPCMP_10_SIZE][TQADPCMP_8_SIZE] = {
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(524 * BIN0), (UInt16)(1047 * BIN0), (UInt16)(1571 * BIN0),
(UInt16)(2094 * BIN0), (UInt16)(2618 * BIN0), (UInt16)(3142 * BIN0),
(UInt16)(4189 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(785 * BIN0), (UInt16)(1571 * BIN0), (UInt16)(2356 * BIN0),
(UInt16)(3142 * BIN0), (UInt16)(3927 * BIN0), (UInt16)(4712 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(1047 * BIN0), (UInt16)(2094 * BIN0), (UInt16)(3142 * BIN0),
(UInt16)(4189 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(1309 * BIN0), (UInt16)(2618 * BIN0), (UInt16)(3927 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(1571 * BIN0), (UInt16)(3142 * BIN0), (UInt16)(4712 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(1833 * BIN0), (UInt16)(3665 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(2094 * BIN0), (UInt16)(4189 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(2356 * BIN0), (UInt16)(4712 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) },
{
(UInt16)(2618 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(5000 * BIN0) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_nCkACItECU_A[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2),
(UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(3500 * BIN2), (UInt16)(4000 * BIN2), (UInt16)(4500 * BIN2),
(UInt16)(5000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_pMesACItECU_A[TQADPCMP_6_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(7 * BIN0), (UInt16)(10 * BIN0),
(UInt16)(15 * BIN0), (UInt16)(20 * BIN0), (UInt16)(30 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tAirACItECU_T
[TQADPCMP_6_SIZE] = {
(SInt16)(-23 * BIN0), (SInt16)(60 * BIN0), (SInt16)(110 * BIN0),
(SInt16)(140 * BIN0), (SInt16)(140 * BIN0), (SInt16)(140 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tiACItECUCycX_A[TQADPCMP_4_SIZE] = {
(SInt16)(20 * BIN0), (SInt16)(35 * BIN0), (SInt16)(45 * BIN0),
(SInt16)(60 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiACItECUCyc_T
[TQADPCMP_4_SIZE] = {
(UInt16)(0 * DEC0), (UInt16)(0 * DEC0), (UInt16)(0 * DEC0),
(UInt16)(0 * DEC0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqACItECUSelOn_T
[TQADPCMP_10_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tqRawACItECUX_A[TQADPCMP_8_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(5 * BIN4), (UInt16)(10 * BIN4),
(UInt16)(15 * BIN4), (UInt16)(20 * BIN4), (UInt16)(25 * BIN4),
(UInt16)(30 * BIN4), (UInt16)(40 * BIN4)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facaciteculd_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_faccnvtqpwr_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tairacitecu_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tiacitecucyc_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tqacitecuselon_t_sav;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_t3_02_turn_on_delay;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_t3_02_turn_off_delay;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_baccluauthsel_edge_detect;
STATIC VAR(t_dds_m_edge_detected_event, AUTOMATIC) tqadpcmp_baccluauthsel_edge_out;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_03_01_04_filtre;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_03_01_05_filtre;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 32-bits variable definition */
#define TQADPCMP_START_SEC_VAR_32BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqadpcmp_03_01_02_counter;
#define TQADPCMP_STOP_SEC_VAR_32BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_03_01_04_filter_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_03_01_05_filter_init;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pACMes; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqACItECUBasFil; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqACItECUBasLoss; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqACItECUBasMem; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqACItECURaw; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_tqACItECUSelOn_MP; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqCmp_pwrACItECULossCf; /* BIN4 */

#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bACCluAuthSel;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bACOnPrem;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bAvlACInt;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_bFrzAdpACItECUOnCf;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACACITECULD_T_APM = {
&tqcmp_facaciteculd_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkACItECU_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facACItECULd_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_FACCNVTQPWR_M_APM = {
&tqcmp_faccnvtqpwr_m_sav,
TQADPCMP_8_SIZE,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqRawACItECUX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkACItECU_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facCnvTqPwr_M[0][0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQCMP_TAIRACITECU_T_APM = {
&tqcmp_tairacitecu_t_sav,
TQADPCMP_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_pMesACItECU_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tAirACItECU_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_TIACITECUCYC_T_APM = {
&tqcmp_tiacitecucyc_t_sav,
TQADPCMP_4_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tiACItECUCycX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tiACItECUCyc_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_TQACITECUSELON_T_APM = {
&tqcmp_tqacitecuselon_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_nCkACItECU_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tqACItECUSelOn_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Des_Entrees_T3(
                                           UInt8 ext_baccluauth_par,
                                           UInt16 ext_pac_par, /* BIN0 */
                                           UInt8 frm_binhaciteculossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calcul_Couple(
                                           SInt8 ext_tair_par, /* BIN0 */
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_Couple_Base(
                                           SInt8 ext_tair_par, /* BIN0 */
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_01_Couple_Base(
                                           SInt8 ext_tair_par, /* BIN0 */
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_02_Premier_Enclenchement(
                                           SInt8 ext_tair_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_03_Memorisation_Couple(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_04_Filtrage(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_Couple_Enclenchement(
                                           UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Conversion_Puissance(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 frm_binhaciteculossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Adaptation_T3(
                                           UInt8 frm_binhaciteculossmdl_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Determiner_condition_calcul_Clim3(UInt8 ext_stactypcf_par);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_Perte_Clim3( UInt16 eng_nckfil_par, /* BIN2 */
								UInt8 ext_baccluauth_par,
								UInt16 ext_pac_par, /* BIN0 */
								SInt8 ext_tair_par, /* BIN0 */
								UInt8 frm_binhaciteculossmdl_par );


STATIC FUNC(void, AUTOMATIC)	TQADPCMP_F06_Selectionner_couple_Clim3_applicable(
									CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqadp_bfrzadpacitecuon_ptr,
									CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  tqcmp_pwraciteculoss_ptr);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Air_Cond_T3
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T3(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_bACCluAuth_swc_in,
                                           UInt16 Ext_pAC_swc_in, /* BIN0 */
                                           SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhACItECULossMdl_swc_in,
                                           UInt8 Ext_stACTypCf_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACItECUOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACItECULoss_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.0 */

    TQADPCMP_05_Determiner_condition_calcul_Clim3(Ext_stACTypCf_swc_in);

    if((UInt32)DDS_FALSE != (UInt32)TqAdp_bAvlACInt)
    {
		TQADPCMP_01_Perte_Clim3( Eng_nCkFil_swc_in, /* BIN2 */
								Ext_bACCluAuth_swc_in,
								Ext_pAC_swc_in, /* BIN0 */
								Ext_tAir_swc_in, /* BIN0 */
								FRM_bInhACItECULossMdl_swc_in );
	}
	else
	{
		/*Do nothings*/
	}

	TQADPCMP_F06_Selectionner_couple_Clim3_applicable( TqAdp_bFrzAdpACItECUOn_swc_out,
                                            TqCmp_pwrACItECULoss_swc_out);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/
/*******************************************************************************
*
* Function Name :  TQADPCMP_05_Determiner_condition_calcul_Clim3
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)  TQADPCMP_05_Determiner_condition_calcul_Clim3(UInt8 ext_stactypcf_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.12.0 */
	if((UInt32)ext_stactypcf_par == (UInt32)TQADPCMP_CLIM_TYPE_3  )
	{

		TqAdp_bAvlACInt = DDS_TRUE;
	}
	else
	{
		TqAdp_bAvlACInt = DDS_FALSE;
	}

}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_Perte_Clim3
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)  	TQADPCMP_01_Perte_Clim3( UInt16 eng_nckfil_par, /* BIN2 */
								UInt8 ext_baccluauth_par,
								UInt16 ext_pac_par, /* BIN0 */
								SInt8 ext_tair_par, /* BIN0 */
								UInt8 frm_binhaciteculossmdl_par )
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR..0 */
    TQADPCMP_02_Traitement_Des_Entrees_T3(ext_baccluauth_par,
	                                       ext_pac_par, /* BIN0 */
	                                       frm_binhaciteculossmdl_par);

	TQADPCMP_03_Calcul_Couple(ext_tair_par, /* BIN0 */
							  eng_nckfil_par /* BIN2 */);

	TQADPCMP_04_Conversion_Puissance(eng_nckfil_par, /* BIN2 */
									 frm_binhaciteculossmdl_par
									 );

	TQADPCMP_05_Adaptation_T3(frm_binhaciteculossmdl_par  );

}

/*******************************************************************************
*
* Function Name : TQADPCMP_F06_Selectionner_couple_Clim3_applicable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC)   TQADPCMP_F06_Selectionner_couple_Clim3_applicable(
										CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  tqadp_bfrzadpacitecuon_ptr,
                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  tqcmp_pwraciteculoss_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.13.0 */
	if((UInt32)DDS_FALSE == (UInt32)TqAdp_bAvlACInt )
	{
		*tqcmp_pwraciteculoss_ptr = 0;
		*tqadp_bfrzadpacitecuon_ptr = DDS_FALSE;

	}
	else
	{
		*tqcmp_pwraciteculoss_ptr = TqCmp_pwrACItECULossCf;
		*tqadp_bfrzadpacitecuon_ptr = TqAdp_bFrzAdpACItECUOnCf;
	}

}
/*******************************************************************************
*
* Function Name : TQADPCMP_02_Traitement_Des_Entrees_T3
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Traitement_Des_Entrees_T3(
                                           UInt8 ext_baccluauth_par,
                                           UInt16 ext_pac_par, /* BIN0 */
                                           UInt8 frm_binhaciteculossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.2.0 */
    UInt32 tqadpcmp_te;
    UInt8 tqadpcmp_turn_out;

    tqadpcmp_te = DDS_TQADPCMP_1MS_U32_TIME;

    tqadpcmp_turn_out = DDS_M_TURN_ON_DELAY(ext_baccluauth_par,
                                            tqadpcmp_te,
                                            ((UInt32)TqCmp_tiACItECUOn_C*DEC1),
                                            &tqadpcmp_t3_02_turn_on_delay);

    TqCmp_bACCluAuthSel = DDS_M_TURN_OFF_DELAY(tqadpcmp_turn_out,
                                               tqadpcmp_te,
                                               ((UInt32)TqCmp_tiACItECUOff_C*DEC1),
                                               &tqadpcmp_t3_02_turn_off_delay);

    if((UInt32)frm_binhaciteculossmdl_par != (UInt32)DDS_FALSE)
    {
        TqCmp_pACMes = 0;
    }
    else
    {
        TqCmp_pACMes = ext_pac_par;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_Calcul_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Calcul_Couple(
                                           SInt8 ext_tair_par, /* BIN0 */
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.3.0 */
    TQADPCMP_03_01_Couple_Base(ext_tair_par, /* BIN0 */
                               eng_nckfil_par /* BIN2 */);

    TQADPCMP_03_02_Couple_Enclenchement(eng_nckfil_par /* BIN2 */);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_Couple_Base
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_Couple_Base(
                                           SInt8 ext_tair_par, /* BIN0 */
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.4.0 */
    /* delay done with the scheduling */
    tqadpcmp_baccluauthsel_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_baccluauthsel_edge_detect,TqCmp_bACCluAuthSel);

    TQADPCMP_03_01_01_Couple_Base(ext_tair_par, /* BIN0 */
                                  eng_nckfil_par /* BIN2 */);

    TQADPCMP_03_01_02_Premier_Enclenchement(ext_tair_par /* BIN2 */);

    TQADPCMP_03_01_03_Memorisation_Couple();

    TQADPCMP_03_01_04_Filtrage();
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_01_Couple_Base
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_01_Couple_Base(
                                           SInt8 ext_tair_par, /* BIN0 */
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.5.0 */
    SInt32 tqadpcmp_svalue;
    SInt32 tqadpcmp_svalue2;

    if((UInt32)eng_nckfil_par != (UInt32)0)
    {
        tqadpcmp_svalue = (SInt32)DDS_M_MAP2D_US16(&TQCMP_TAIRACITECU_T_APM,TqCmp_pACMes);
        tqadpcmp_svalue = tqadpcmp_svalue - (SInt32)ext_tair_par;

        tqadpcmp_svalue2 = (SInt32)DDS_M_MAP2D_U16(&TQCMP_FACACITECULD_T_APM,eng_nckfil_par);

        tqadpcmp_svalue2 = ((tqadpcmp_svalue * tqadpcmp_svalue2) * (SInt32)TqCmp_facTqACItECU_C) / BIN13;
        TqCmp_tqACItECUBasLoss = (UInt16)DDS_M_LIMIT(tqadpcmp_svalue2,
                                                     0,
                                                     500*BIN4);
    }
    else
    {
        TqCmp_tqACItECUBasLoss = 0;
        (void)DDS_M_MAP2D_US16(&TQCMP_TAIRACITECU_T_APM,TqCmp_pACMes);
        (void)DDS_M_MAP2D_U16(&TQCMP_FACACITECULD_T_APM,eng_nckfil_par);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_02_Premier_Enclenchement
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_02_Premier_Enclenchement(
                                           SInt8 ext_tair_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.6.0 */
    UInt32 tqadpcmp_uvalue;

    /* [0;1800]DEC0 */
    tqadpcmp_uvalue = (UInt32)DDS_M_MAP2D_SU16(&TQCMP_TIACITECUCYC_T_APM,ext_tair_par);


    if (tqadpcmp_baccluauthsel_edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
    {
        tqadpcmp_03_01_02_counter = 0 * DEC3 ;
    }
    else if ((UInt32)TqCmp_bACCluAuthSel == FALSE)
    {
        tqadpcmp_03_01_02_counter = DDS_M_MIN( (tqadpcmp_03_01_02_counter + TQADPCMP_INCREMENT_COUNTER),  /* prev + 0.01 * DEC3*/
                                                 TQADPCMP_03_01_02_CNT_MAX);                               /* 400 * DEC3        */
    }
    else
    {
        /* Do nothing, keep counter value */
    }


    if(  (tqadpcmp_baccluauthsel_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
       &&(tqadpcmp_03_01_02_counter >= (tqadpcmp_uvalue * DEC3)))           /* test [0;400]DEC3 >= [0;1800]DEC0 * DEC3 */
    {
        TqCmp_bACOnPrem = DDS_TRUE;
    }
    else
    {
        TqCmp_bACOnPrem = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_03_Memorisation_Couple
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_03_Memorisation_Couple(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.7.0 */
    if(tqadpcmp_baccluauthsel_edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
    {
        TqCmp_tqACItECUBasMem = TqCmp_tqACItECUBasFil;
    }
    else
    {
        /* nothing to do */
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_04_Filtrage
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_04_Filtrage(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.8.0 */
    UInt16 tqadpcmp_uvalue;

    if(  (tqadpcmp_baccluauthsel_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
       ||((UInt32)tqadpcmp_03_01_04_filter_init != (UInt32)DDS_TRUE))
    {
        tqadpcmp_03_01_04_filter_init = DDS_TRUE;

        if(  ((UInt32)TqCmp_tqACItECUBasLoss >= (UInt32)TqCmp_tqACItECUBasMem)
           ||((UInt32)TqCmp_bACOnPrem == (UInt32)DDS_TRUE))
        {
            tqadpcmp_uvalue = TqCmp_tqACItECUBasLoss;
        }
        else
        {
            tqadpcmp_uvalue = TqCmp_tqACItECUBasMem;
        }
        TqCmp_tqACItECUBasFil = DDS_M_FILTER_LP1_U16_INIT(&tqadpcmp_03_01_04_filtre, tqadpcmp_uvalue);
    }
    else
    {
        TqCmp_tqACItECUBasFil = DDS_M_FILTER_LP1_U16(&tqadpcmp_03_01_04_filtre, TqCmp_tqACItECUBasLoss, TqCmp_facFilACItECULoss_C, BIN10);
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_02_Couple_Enclenchement
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_Couple_Enclenchement(
                                           UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.9.0 */
    UInt16 tqadpcmp_uvalue;

    if(  (tqadpcmp_baccluauthsel_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
       ||((UInt32)tqadpcmp_03_01_05_filter_init != (UInt32)DDS_TRUE))
    {
        tqadpcmp_03_01_05_filter_init = DDS_TRUE;
        tqadpcmp_uvalue = DDS_M_MAP2D_U16(&TQCMP_TQACITECUSELON_T_APM,eng_nckfil_par);

        TqCmp_tqACItECUSelOn_MP = DDS_M_FILTER_LP1_U16_INIT(&tqadpcmp_03_01_05_filtre, tqadpcmp_uvalue);
    }
    else
    {
        TqCmp_tqACItECUSelOn_MP = DDS_M_FILTER_LP1_U16(&tqadpcmp_03_01_05_filtre, 0, TqCmp_facFilACItECUSelOn_C, BIN10);
    }

    TqCmp_tqACItECURaw = (UInt16)DDS_M_MIN((UInt32)TqCmp_tqACItECUBasFil + (UInt32)TqCmp_tqACItECUSelOn_MP,
                                           500*BIN4);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Conversion_Puissance
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Conversion_Puissance(
                                           UInt16 eng_nckfil_par, /* BIN2 */
                                           UInt8 frm_binhaciteculossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.10.1 */

    if((UInt32)frm_binhaciteculossmdl_par != (UInt32)DDS_FALSE)
    {
        TqCmp_pwrACItECULossCf = 0;
    }
    else
    {
        if((UInt32)TqCmp_bACCluAuthSel != (UInt32)DDS_FALSE)
        {
            TqCmp_pwrACItECULossCf = DDS_M_MAP3D_U16(&TQCMP_FACCNVTQPWR_M_APM,TqCmp_tqACItECURaw,eng_nckfil_par);
        }
        else
        {
            TqCmp_pwrACItECULossCf = DDS_M_MAP3D_U16(&TQCMP_FACCNVTQPWR_M_APM,0,eng_nckfil_par);
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_Adaptation_T3
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Adaptation_T3(
                                           UInt8 frm_binhaciteculossmdl_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_1930.FR.11.1 */

    if(  (tqadpcmp_baccluauthsel_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
       ||(tqadpcmp_baccluauthsel_edge_out == DDS_M_NEGATIVE_EDGE_DETECTED)
       ||((UInt32)frm_binhaciteculossmdl_par == (UInt32)DDS_TRUE))
    {
        TqAdp_bFrzAdpACItECUOnCf = DDS_TRUE;
    }
    else
    {
        TqAdp_bFrzAdpACItECUOnCf = DDS_FALSE;
    }
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Estim_Air_Cond_T3_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Estim_Air_Cond_T3_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqAdp_bFrzAdpACItECUOn_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqCmp_pwrACItECULoss_swc_out /* BIN0 */)
{
    *TqAdp_bFrzAdpACItECUOn_swc_out = DDS_FALSE;
    *TqCmp_pwrACItECULoss_swc_out = 0;

    TqCmp_pwrACItECULossCf = 0;
    TqAdp_bFrzAdpACItECUOnCf = DDS_FALSE;
    TqAdp_bAvlACInt = DDS_FALSE;

    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_t3_02_turn_on_delay);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_t3_02_turn_off_delay);
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_baccluauthsel_edge_detect,DDS_FALSE);
    tqadpcmp_03_01_02_counter = (UInt32)(0 * DEC3);

    TqCmp_tqACItECUBasMem = 0;
    tqadpcmp_03_01_04_filter_init = DDS_FALSE;
    tqadpcmp_03_01_05_filter_init = DDS_FALSE;

    TqCmp_tqACItECUBasFil = 0;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

