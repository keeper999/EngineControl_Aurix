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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Model_Tair.c
* Version int :/main/L02_01/1 Date: 21/3/2012 15 h 10 m User:esnault 
*    TWK_model:TQADPCMP_Model_Tair_L02_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\2 Date: 7/3/2012 17 h 12 m User:halouane 
*    TWK_model:TQADPCMP_Model_Tair_L02_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 29/2/2012 15 h 48 m User:halouane
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1_D
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L01_01/6 Date: 6/6/2011 10 h 27 m User:meme
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1_D
*    comments :QAC warning and init
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 26/5/2011 15 h 2 m User:lemort
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1_D
*    comments :QAC warning and init
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 26/5/2011 14 h 24 m User:lemort
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1_D
*    comments :include nvm.h
* Version int :/main/L01_01/5 Date: 21/12/2010 17 h 54 m User:esnault
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1_D
*    comments :TqAdpCmp 10.3 :  correct FDS_32372
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 25/11/2010 15 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1_D
*    comments :TqAdpCmp 10.3 :  correct FDS_32372
* Version int :/main/L01_01/4 Date: 18/11/2010 12 h 48 m User:meme
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 17/11/2010 16 h 50 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 16/11/2010 16 h 58 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1
*    comments :For TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 15/11/2010 16 h 56 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_012_IMPL1
*    comments :work in progress
* Version int :/main/L01_01/3 Date: 12/10/2010 11 h 44 m User:meme
*    TWK_model:TQADPCMP_Model_Tair_L01_011_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 27/9/2010 14 h 47 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_011_IMPL1
*    comments :for TqAdpCmp euro 6
* Version int :/main/L01_01/2 Date: 12/10/2010 9 h 45 m User:meme
*    TWK_model:TQADPCMP_Model_Tair_L01_011_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 21/9/2010 17 h 44 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_011_IMPL1
*    comments :for TqAdpCmp
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 21 m User:esnault
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\12 Date: 10/9/2010 10 h 1 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\11 Date: 3/9/2010 12 h 2 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\10 Date: 18/8/2010 9 h 13 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 17/8/2010 16 h 9 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 7/7/2010 9 h 24 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 29/6/2010 11 h 50 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 24/6/2010 8 h 55 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 23/6/2010 17 h 50 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Model_Tair_L01_010_IMPL1
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

/* CoPTSt_stEng */
#define COPTST_COUPE_CALE  1
#define COPTST_DEMARRAGE_ENTRAINE  3
#define COPTST_ARRET  6
#define COPTST_REDEMARRAGE_ENTRAINE  7


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_8bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_8BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"



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
#define TQADPCMP_START_SEC_CALIB_32BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) TqCmp_tiEngStopThr_C = (CONST(UInt32, AUTOMATIC))(14400 * DEC0);
#define TQADPCMP_STOP_SEC_CALIB_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_mfMinLrn_C = (CONST(UInt16, AUTOMATIC))(40 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_spdVehThr_C = (CONST(UInt16, AUTOMATIC))(30 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tAirSelThr_C = (CONST(SInt16, AUTOMATIC))(20 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tCoMesThr_C = (CONST(SInt16, AUTOMATIC))(20 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiEngStrtMax_C = (CONST(UInt16, AUTOMATIC))(60 * DEC0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiSpdVehThrOff_C = (CONST(UInt16, AUTOMATIC))(5 * DEC1);
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiSpdVehThrOn_C = (CONST(UInt16, AUTOMATIC))(20 * DEC1);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(SInt8, AUTOMATIC) TqCmp_tAirDft_C = (CONST(SInt8, AUTOMATIC))(20 * BIN0);
STATIC volatile CONST(SInt8, AUTOMATIC) TqCmp_tAirMax_C = (CONST(SInt8, AUTOMATIC))(100 * BIN0);
STATIC volatile CONST(SInt8, AUTOMATIC) TqCmp_tAirMin_C = (CONST(SInt8, AUTOMATIC))(-40 * BIN0);
STATIC volatile CONST(SInt8, AUTOMATIC) TqCmp_tDeltaCoAirThr_C = (CONST(SInt8, AUTOMATIC))(5 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqCmp_tiVldLrn_C = (CONST(UInt8, AUTOMATIC))(2 * DEC1);
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilSpdVeh_T
[TQADPCMP_6_SIZE] = {
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_facFilTCo_A[TQADPCMP_6_SIZE] = {
(SInt16)(-20 * BIN0), (SInt16)(0 * BIN0), (SInt16)(20 * BIN0),
(SInt16)(40 * BIN0), (SInt16)(60 * BIN0), (SInt16)(80 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_facFilTCo_T
[TQADPCMP_6_SIZE] = {
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tAirStatDif_A[TQADPCMP_6_SIZE] = {
(SInt16)(-20 * BIN0), (SInt16)(0 * BIN0), (SInt16)(20 * BIN0),
(SInt16)(40 * BIN0), (SInt16)(60 * BIN0), (SInt16)(80 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqCmp_tAirStatDif_T
[TQADPCMP_6_SIZE] = {
(SInt16)(5 * BIN0), (SInt16)(5 * BIN0), (SInt16)(7 * BIN0),
(SInt16)(10 * BIN0), (SInt16)(10 * BIN0), (SInt16)(10 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiTAirInterX_A[TQADPCMP_6_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(10 * BIN0), (UInt16)(15 * BIN0),
(UInt16)(25 * BIN0), (UInt16)(50 * BIN0), (UInt16)(100 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiTAirInterY_A[TQADPCMP_6_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(50 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(200 * BIN7), (UInt16)(300 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqCmp_tiTAirInter_M
[TQADPCMP_6_SIZE][TQADPCMP_6_SIZE] = {
{
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10) },
{
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10) },
{
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10) },
{
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10) },
{
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10) },
{
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10),
(UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10), (UInt16)(0.001 * BIN10) }
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfilspdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_facfiltco_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqcmp_tairstatdif_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqcmp_titairinter_m_sav;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_03_01_turn_on_dly;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_04_turn_on_dly;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqadpcmp_04_turn_off_dly;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) tqadpcmp_03_01_filter;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqadpcmp_03_02_01_filter;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_03_01_unit_delay_init;
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_03_02_01_unit_delay_init;
STATIC VAR(SInt8, AUTOMATIC) tqcmp_tairestim_loc;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"



/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bAdpTAirInter;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bEngCold;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqCmp_bSpdVldAdpTAirDsl_MP;
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirDif; /* BIN0 */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirDly; /* BIN0 */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirEstimDsl; /* BIN0 */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirEstimGsl; /* BIN0 */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirEstimRaw; /* BIN0 */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirInter; /* BIN0 */
_DDS_STATIC_ VAR(SInt8, AUTOMATIC) TqCmp_tAirStrt; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQCMP_FACFILSPDVEH_T_APM = {
&tqcmp_facfilspdveh_t_sav,
TQADPCMP_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tiTAirInterX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilSpdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQCMP_FACFILTCO_T_APM = {
&tqcmp_facfiltco_t_sav,
TQADPCMP_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTCo_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_facFilTCo_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQCMP_TAIRSTATDIF_T_APM = {
&tqcmp_tairstatdif_t_sav,
TQADPCMP_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tAirStatDif_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tAirStatDif_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQCMP_TITAIRINTER_M_APM = {
&tqcmp_titairinter_m_sav,
TQADPCMP_6_SIZE,
TQADPCMP_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tiTAirInterX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tiTAirInterY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqCmp_tiTAirInter_M[0][0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Start_Condition(UInt8 tqsys_btypfu_par,
                                                         UInt8 coptst_steng_par,
                                                         UInt32 eom_tiengstop_par, /* DEC0 */
                                                         SInt16 ext_tairuscmprmes_par, /* BIN0 */
                                                         SInt16 ext_tcomes_par, /* BIN0 */
                                                         SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_bengstrtreq_ptr);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Gsl_Temp_Modele(SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                         SInt16 ext_tcomes_par, /* BIN0 */
                                                         UInt16 airsys_mfairmesthrestim_par, /* BIN7 */
                                                         UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_Calcul_delta_T(UInt16 veh_spdveh_par, /* BIN7 */
                                                           SInt16 ext_tcomes_par, /* BIN0 */
                                                           UInt16 airsys_mfairmesthrestim_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_Estimation_TAmbiante(UInt16 airsys_mfairmesthrestim_par, /* BIN7 */
                                                                 SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                                 UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_01_Calcul_Tinter(UInt16 airsys_mfairmesthrestim_par, /* BIN7 */
                                                             SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                             UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_02_Calcul_Final(void);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Dsl_Temp_Modele(UInt16 veh_spdveh_par, /* BIN7 */
                                                         SInt16 ext_tairuscmprmes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Switch_Condition(UInt8 tqsys_btypfu_par,
                                                          UInt32 eom_tiengrun_par /* DEC0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_06_Final_Temp(UInt8 FRM_bInhTAirEstim_swc_in,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_btairchk_ptr,
                                                    CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) tqcmp_tairestim_ptr /* BIN0 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Model_Tair
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Model_Tair(UInt16 AirSys_mfAirMesThrEstim_swc_in, /* BIN7 */
                                           UInt8 CoPTSt_stEng_swc_in,
                                           UInt32 EOM_tiEngRun_swc_in, /* DEC0 */
                                           UInt32 EOM_tiEngStop_swc_in, /* DEC0 */
                                           SInt16 Ext_tAirUsCmprMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tDsThrMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bInhTAirEstim_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bEngStrtReq_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bTAirChk_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqCmp_tAirEstim_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.1.3 */

    TqCmp_tAirDly = tqcmp_tairestim_loc;

    TQADPCMP_02_Start_Condition(TqSys_bTypFu_swc_in,
                                CoPTSt_stEng_swc_in,
                                EOM_tiEngStop_swc_in, /* DEC0 */
                                Ext_tAirUsCmprMes_swc_in, /* BIN0 */
                                Ext_tCoMes_swc_in, /* BIN0 */
                                Ext_tDsThrMes_swc_in, /* BIN0 */
                                TqCmp_bEngStrtReq_swc_out);

    if((UInt32)TqSys_bTypFu_swc_in != (UInt32)DDS_FALSE)
    {
        TQADPCMP_03_Gsl_Temp_Modele(Ext_tDsThrMes_swc_in, /* BIN0 */
                                    Ext_tCoMes_swc_in, /* BIN0 */
                                    AirSys_mfAirMesThrEstim_swc_in, /* BIN7 */
                                    Veh_spdVeh_swc_in /* BIN7 */);
    }
    else
    {
        TQADPCMP_04_Dsl_Temp_Modele(Veh_spdVeh_swc_in, /* BIN7 */
                                    Ext_tAirUsCmprMes_swc_in /* BIN0 */);
    }

    TQADPCMP_05_Switch_Condition(TqSys_bTypFu_swc_in,
                                 EOM_tiEngRun_swc_in /* DEC0 */);

    TQADPCMP_06_Final_Temp(FRM_bInhTAirEstim_swc_in,
                           TqCmp_bTAirChk_swc_out,
                           &tqcmp_tairestim_loc /* BIN0 */);

    *TqCmp_tAirEstim_swc_out = tqcmp_tairestim_loc;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_02_Start_Condition
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_02_Start_Condition(UInt8 tqsys_btypfu_par,
                                                         UInt8 coptst_steng_par,
                                                         UInt32 eom_tiengstop_par, /* DEC0 */
                                                         SInt16 ext_tairuscmprmes_par, /* BIN0 */
                                                         SInt16 ext_tcomes_par, /* BIN0 */
                                                         SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_bengstrtreq_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.3.2 */
    SInt32 tqadpcmp_02_tair; /* BIN0 */
    UInt32 tqadpcmp_02_test_switch_out;

    if((UInt32)tqsys_btypfu_par != (UInt32)DDS_FALSE)
    {
        tqadpcmp_02_tair = (SInt32) ext_tdsthrmes_par;
    }
    else
    {
        tqadpcmp_02_tair = (SInt32) ext_tairuscmprmes_par;
    }

    if(  (tqadpcmp_02_tair<=(SInt32)TqCmp_tAirSelThr_C)
       &&(DDS_M_ABS(tqadpcmp_02_tair-(SInt32)ext_tcomes_par)<=(SInt32)TqCmp_tDeltaCoAirThr_C)
       &&((SInt32)ext_tcomes_par<=(SInt32)TqCmp_tCoMesThr_C)
       &&(eom_tiengstop_par>=TqCmp_tiEngStopThr_C))
    {
        TqCmp_bEngCold = DDS_TRUE;
    }
    else
    {
        TqCmp_bEngCold = DDS_FALSE;
    }

    if(  ((UInt32)coptst_steng_par==COPTST_DEMARRAGE_ENTRAINE)
       ||((UInt32)coptst_steng_par==COPTST_REDEMARRAGE_ENTRAINE))
    {
        *tqcmp_bengstrtreq_ptr = DDS_TRUE;
        tqadpcmp_02_test_switch_out = (UInt32) DDS_FALSE;
    }
    else
    {
        *tqcmp_bengstrtreq_ptr = DDS_FALSE;
        if((  ((UInt32)coptst_steng_par==COPTST_COUPE_CALE)
            ||((UInt32)coptst_steng_par==COPTST_ARRET))
           &&((UInt32)TqCmp_bEngCold==(UInt32)DDS_TRUE))
        {
            tqadpcmp_02_test_switch_out = (UInt32) DDS_TRUE;
        }
        else
        {
            tqadpcmp_02_test_switch_out = (UInt32) DDS_FALSE;
        }
    }

    if(tqadpcmp_02_test_switch_out != (UInt32)DDS_FALSE)
    {
        TqCmp_tAirStrt = (SInt8)DDS_M_LIMIT(tqadpcmp_02_tair,-40,100);
    }
    else
    {
        /*  Nothing to do */
    }
}
/*******************************************************************************
*
* Function Name : TQADPCMP_03_Gsl_Temp_Modele
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_Gsl_Temp_Modele(SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                         SInt16 ext_tcomes_par, /* BIN0 */
                                                         UInt16 airsys_mfairmesthrestim_par, /* BIN7 */
                                                         UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.4.2 */
    TQADPCMP_03_01_Calcul_delta_T(veh_spdveh_par, /* BIN7 */
                                  ext_tcomes_par, /* BIN0 */
                                  airsys_mfairmesthrestim_par /* BIN7 */);

    TQADPCMP_03_02_Estimation_TAmbiante(airsys_mfairmesthrestim_par, /* BIN7 */
                                        ext_tdsthrmes_par, /* BIN0 */
                                        veh_spdveh_par /* BIN7 */);
}


/*******************************************************************************
*
* Function Name : TQADPCMP_03_01_Calcul_delta_T
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_01_Calcul_delta_T(UInt16 veh_spdveh_par, /* BIN7 */
                                                           SInt16 ext_tcomes_par, /* BIN0 */
                                                           UInt16 airsys_mfairmesthrestim_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.5.1 */

    UInt8  tqadpcmp_03_01_turn_on_delay_in;
    SInt16 tqadpcmp_03_01_filter_init_value;
    SInt16 tqcmp_tairstatdif_map_out;
    UInt16 tqcmp_facfiltco_map_out;
    UInt16 tqcmp_facfilspdveh_map_out;
    UInt32 tqadpcmp_03_01_turn_on_delay_out;
    UInt32 tqadpcmp_03_01_te;

    tqadpcmp_03_01_te = DDS_TQADPCMP_1MS_U32_TIME;

    tqcmp_tairstatdif_map_out = DDS_M_MAP2D_S16(&TQCMP_TAIRSTATDIF_T_APM,TqCmp_tAirDly);
    tqcmp_facfiltco_map_out = DDS_M_MAP2D_SU16(&TQCMP_FACFILTCO_T_APM,ext_tcomes_par);
    tqcmp_facfilspdveh_map_out = DDS_M_MAP2D_U16(&TQCMP_FACFILSPDVEH_T_APM,(UInt16)((UInt32)veh_spdveh_par/BIN7));


    /* TqCmp_bAdpTAirInter calc */
    if((UInt32)airsys_mfairmesthrestim_par>(UInt32)TqCmp_mfMinLrn_C)
    {
        tqadpcmp_03_01_turn_on_delay_in = DDS_TRUE;
    }
    else
    {
        tqadpcmp_03_01_turn_on_delay_in = DDS_FALSE;
    }

    tqadpcmp_03_01_turn_on_delay_out = (UInt32)DDS_M_TURN_ON_DELAY(tqadpcmp_03_01_turn_on_delay_in,
                                                                   tqadpcmp_03_01_te,
                                                                   (UInt32)TqCmp_tiVldLrn_C,
                                                                   &tqadpcmp_03_01_turn_on_dly);

    if((UInt32)DDS_FALSE == tqadpcmp_03_01_turn_on_delay_out)
    {
        TqCmp_bAdpTAirInter = DDS_TRUE;
    }
    else
    {
        TqCmp_bAdpTAirInter = DDS_FALSE;
    }

    if((UInt32)tqadpcmp_03_01_unit_delay_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_03_01_unit_delay_init = DDS_TRUE;

        if((UInt32)TqCmp_bEngCold!=(UInt32)DDS_FALSE)
        {
            tqadpcmp_03_01_filter_init_value = 0;
        }
        else
        {
            tqadpcmp_03_01_filter_init_value = (SInt16)TqAdpCmp_sNV_Z1_CST_8BIT.TqCmp_tAirDifMem_NV;
        }

        /* [-40;100]BIN0 */
        TqCmp_tAirDif = (SInt8)DDS_M_FILTER_LP1_S32_INIT(&tqadpcmp_03_01_filter, (SInt32)tqadpcmp_03_01_filter_init_value);
    }
    else
    {
        if((UInt32)TqCmp_bAdpTAirInter!=(UInt32)DDS_TRUE)
        {
            TqCmp_tAirDif = (SInt8)DDS_M_FILTER_LP1_S32(&tqadpcmp_03_01_filter,
                                                        tqcmp_tairstatdif_map_out,      /* [-40;100]BIN0 */
                                                        /* [0;1]BIN15 = ([0;1]BIN10 * [0;1]BIN10) / BIN5 */
                                                        (UInt16)(((UInt32)tqcmp_facfiltco_map_out*(UInt32)tqcmp_facfilspdveh_map_out)/BIN5));
        }
        else
        {
            TqCmp_tAirDif = (SInt8)DDS_M_FILTER_LP1_S32_INIT(&tqadpcmp_03_01_filter, TqAdpCmp_sNV_Z1_CST_8BIT.TqCmp_tAirDifMem_NV);
        }
    }

    TqAdpCmp_sNV_Z1_CST_8BIT.TqCmp_tAirDifMem_NV = TqCmp_tAirDif;

}


/*******************************************************************************
*
* Function Name : TQADPCMP_03_02_Estimation_TAmbiante
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_Estimation_TAmbiante(UInt16 airsys_mfairmesthrestim_par, /* BIN7 */
                                                                 SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                                 UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.6.2 */

    TQADPCMP_03_02_01_Calcul_Tinter(airsys_mfairmesthrestim_par, /* BIN7 */
                                    ext_tdsthrmes_par, /* BIN0 */
                                    veh_spdveh_par /* BIN7 */);

    TQADPCMP_03_02_02_Calcul_Final();
}

/*******************************************************************************
*
* Function Name : TQADPCMP_03_02_01_Calcul_Tinter
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_01_Calcul_Tinter(UInt16 airsys_mfairmesthrestim_par, /* BIN7 */
                                                             SInt16 ext_tdsthrmes_par, /* BIN0 */
                                                             UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.7.2 */
    SInt32 tqadpcmp_tqcmp_titairinter_map_out;
    SInt32 tqadpcmp_03_02_01_filter_out;
    UInt16 tqadpcmp_03_02_01_k_factor;

    /* [0;2] BIN10 */
    tqadpcmp_tqcmp_titairinter_map_out = (SInt32)DDS_M_MAP3D_U16(&TQCMP_TITAIRINTER_M_APM,
                                                                 (UInt16)((UInt32)veh_spdveh_par/BIN7),
                                                                 airsys_mfairmesthrestim_par);

    if((UInt32)tqadpcmp_03_02_01_unit_delay_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_03_02_01_unit_delay_init = DDS_TRUE;

        tqadpcmp_03_02_01_filter_out = DDS_M_FILTER_LP1_S16_INIT(&tqadpcmp_03_02_01_filter,(SInt16)((SInt32)TqCmp_tAirDly+(SInt32)TqCmp_tAirDif));

        TqCmp_tAirInter = (SInt8)DDS_M_LIMIT(tqadpcmp_03_02_01_filter_out,-40,100); /* [-40;100]BIN0 */
    }
    else
    {
        if((UInt32)TqCmp_bAdpTAirInter!=(UInt32)DDS_FALSE)
        {
            /* [-40;100]BIN0 */
            TqCmp_tAirInter = (SInt8)DDS_M_FILTER_LP1_S16_INIT(&tqadpcmp_03_02_01_filter,(SInt16)TqCmp_tAirInter);
        }
        else
        {
             /* K = DDS_M_LIMIT( (Te / (Te + Tf)) , 0, 1); */

             /* BIN10  = BIN20 / (BIN10 + BIN10) */
             /* [0.0476;1] = 0.1 / (0.1 + [0;2]) */
             tqadpcmp_03_02_01_k_factor = (UInt16)((SInt32)(0.1*BIN20) / ((SInt32)(0.1*BIN10)+tqadpcmp_tqcmp_titairinter_map_out));

             /* [-50;200]BIN0 */
             tqadpcmp_03_02_01_filter_out = DDS_M_FILTER_LP1_S16(&tqadpcmp_03_02_01_filter,
                                                                      ext_tdsthrmes_par,
                                                                      tqadpcmp_03_02_01_k_factor,BIN10);

            /* [-40;100]BIN0 */
            TqCmp_tAirInter = (SInt8)DDS_M_LIMIT(tqadpcmp_03_02_01_filter_out,-40,100);
        }
    }

}


/*******************************************************************************
*
* Function Name : TQADPCMP_03_02_02_Calcul_Final
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_03_02_02_Calcul_Final(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.8.2 */
    TqCmp_tAirEstimGsl = (SInt8) DDS_M_LIMIT((SInt32)TqCmp_tAirInter - (SInt32)TqCmp_tAirDif,-40,100);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_04_Dsl_Temp_Modele
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_04_Dsl_Temp_Modele(UInt16 veh_spdveh_par, /* BIN7 */
                                                         SInt16 ext_tairuscmprmes_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.11.0 */
    UInt8 tqadpcmp_04_turn_on_1_condition;
    UInt8 tqadpcmp_04_turn_on_2_condition;

    UInt32 tqadpcmp_04_turn_on_out;

    UInt32 tqadpcmp_04_te;

    tqadpcmp_04_te = DDS_TQADPCMP_1MS_U32_TIME;

    if((UInt32)veh_spdveh_par>=((UInt32)TqCmp_spdVehThr_C * BIN7))
    {
        tqadpcmp_04_turn_on_1_condition = DDS_TRUE;
    }
    else
    {
        tqadpcmp_04_turn_on_1_condition = DDS_FALSE;
    }

    tqadpcmp_04_turn_on_out = DDS_M_TURN_ON_DELAY(tqadpcmp_04_turn_on_1_condition,
                                                  tqadpcmp_04_te,
                                                  (UInt32)TqCmp_tiSpdVehThrOn_C * DEC2,
                                                  &tqadpcmp_04_turn_on_dly);


    if( (tqadpcmp_04_turn_on_out                    != (UInt32)DDS_FALSE)   &&
        ((UInt32)tqadpcmp_04_turn_on_1_condition    != (UInt32)DDS_FALSE) )
    {
        tqadpcmp_04_turn_on_2_condition =   DDS_TRUE;
    }

    else
    {
        tqadpcmp_04_turn_on_2_condition =   DDS_FALSE;
    }

    TqCmp_bSpdVldAdpTAirDsl_MP = DDS_M_TURN_OFF_DELAY(tqadpcmp_04_turn_on_2_condition,
                                                      tqadpcmp_04_te,
                                                      (UInt32)TqCmp_tiSpdVehThrOff_C * DEC2,
                                                      &tqadpcmp_04_turn_off_dly);


    if((UInt32)TqCmp_bSpdVldAdpTAirDsl_MP!=(UInt32)DDS_FALSE)
    {
        TqCmp_tAirEstimDsl = (SInt8)DDS_M_LIMIT((SInt32)ext_tairuscmprmes_par,-40,100);
    }
    else
    {
        TqCmp_tAirEstimDsl = TqCmp_tAirDly;
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_05_Switch_Condition
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_05_Switch_Condition(UInt8 tqsys_btypfu_par,
                                                          UInt32 eom_tiengrun_par /* DEC0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.9.2 */
    if(  ((UInt32)TqCmp_bEngCold == (UInt32)DDS_TRUE)
       &&(eom_tiengrun_par<=(UInt32)TqCmp_tiEngStrtMax_C))
    {
        TqCmp_tAirEstimRaw = TqCmp_tAirStrt;
    }
    else
    {
        if((UInt32)tqsys_btypfu_par != (UInt32)DDS_FALSE)
        {
            TqCmp_tAirEstimRaw = TqCmp_tAirEstimGsl;
        }
        else
        {
            TqCmp_tAirEstimRaw = TqCmp_tAirEstimDsl;
        }
    }
}

/*******************************************************************************
*
* Function Name : TQADPCMP_06_Final_Temp
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_06_Final_Temp(UInt8 FRM_bInhTAirEstim_swc_in,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqcmp_btairchk_ptr,
                                                    CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) tqcmp_tairestim_ptr /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0940.FR.10.2 */
    SInt32 tqadpcmp_06_detect_in;

    if((UInt32)FRM_bInhTAirEstim_swc_in!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_06_detect_in = TqCmp_tAirDft_C;
        *tqcmp_btairchk_ptr = DDS_FALSE;
    }
    else
    {
        tqadpcmp_06_detect_in = TqCmp_tAirEstimRaw;
        *tqcmp_btairchk_ptr = DDS_TRUE;
    }

    *tqcmp_tairestim_ptr = (SInt8)DDS_M_SATURATION_V2(tqadpcmp_06_detect_in,(SInt32)TqCmp_tAirMin_C,(SInt32)TqCmp_tAirMax_C);
    TqAdpCmp_sNV_Z1_CST_8BIT.TqCmp_tAirEstimMem_NV = *tqcmp_tairestim_ptr;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Model_Tair_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Model_Tair_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bEngStrtReq_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqCmp_bTAirChk_swc_out,
                                           CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqCmp_tAirEstim_swc_out /* BIN0 */)
{
    *TqCmp_bEngStrtReq_swc_out = 0;
    *TqCmp_bTAirChk_swc_out = 0;

    *TqCmp_tAirEstim_swc_out = TqAdpCmp_sNV_Z1_CST_8BIT.TqCmp_tAirEstimMem_NV;

    TqCmp_tAirEstimGsl = (SInt8) (20 * BIN0);
    TqCmp_tAirEstimDsl = (SInt8) (20 * BIN0);

    tqadpcmp_03_01_unit_delay_init = DDS_FALSE;
    tqadpcmp_03_02_01_unit_delay_init = DDS_FALSE;

    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_03_01_turn_on_dly);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_04_turn_on_dly);
    DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE,&tqadpcmp_04_turn_off_dly);

    TqCmp_tAirStrt = 0;

    tqcmp_tairestim_loc = TqAdpCmp_sNV_Z1_CST_8BIT.TqCmp_tAirEstimMem_NV;

    TqCmp_bSpdVldAdpTAirDsl_MP = DDS_FALSE;
    TqCmp_tAirInter = 20;
    TqCmp_tAirEstimRaw = 20;
    TqCmp_tAirDly = 20;
    TqCmp_bAdpTAirInter = DDS_FALSE;
    TqCmp_bEngCold = DDS_FALSE;

}


#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

