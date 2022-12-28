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
* Ref X:\integration_view_00PSASWC_E502D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Calc_Tq_Applicable.c
* Version int :/main/L01_01/2 Date: 18/11/2010 12 h 49 m User:meme 
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_011_IMPL1
*    comments :for TqAdpCmp 10.2
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 17/11/2010 16 h 49 m User:morisseau 
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_011_IMPL1
*    comments :for TqAdpCmp 10.2
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 18 m User:esnault
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\12 Date: 2/9/2010 16 h 57 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\11 Date: 2/9/2010 16 h 54 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\10 Date: 18/8/2010 8 h 48 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp e6
* Version dev :\main\branch_morisseau_tqadpcmp_view\9 Date: 2/8/2010 12 h 15 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\8 Date: 22/7/2010 16 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 9/7/2010 16 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 8/7/2010 18 h 4 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 25/6/2010 12 h 56 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 24/6/2010 15 h 26 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 21 m User:morisseau
*    TWK_model:TQADPCMP_Calc_Tq_Applicable_L01_010_IMPL1
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


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQADPCMP_TISCHED                      10    /* DEC3 */


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(UInt16, AUTOMATIC) TqAdp_idxTEngRaw; /* BIN7 */
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRed[TQADPCMP_8_SIZE]; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeut[TQADPCMP_8_SIZE]; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnAC; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnCdnAC;
extern VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnWoutAC;
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
extern volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTqAccu_A[TQADPCMP_10_SIZE];
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

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnIrvAC; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
VAR(UInt8, AUTOMATIC) TqAdp_bCorLrnIrvAC;
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_spdCorLrnSpdVehThd_C = (CONST(UInt16, AUTOMATIC))(150 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_tiCorLrnSpdVeh_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_tiDlyCorLrnSpdVeh_C = (CONST(UInt16, AUTOMATIC))(1 * DEC0);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnDecMax_C = (CONST(SInt16, AUTOMATIC))(-20 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorLrnIncMax_C = (CONST(SInt16, AUTOMATIC))(20 * BIN4);
#define TQADPCMP_STOP_SEC_CALIB_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_nCkFil_A[TQADPCMP_16_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(533 * BIN2), (UInt16)(1067 * BIN2),
(UInt16)(1600 * BIN2), (UInt16)(2133 * BIN2), (UInt16)(2667 * BIN2),
(UInt16)(3200 * BIN2), (UInt16)(3733 * BIN2), (UInt16)(4267 * BIN2),
(UInt16)(4800 * BIN2), (UInt16)(5333 * BIN2), (UInt16)(5867 * BIN2),
(UInt16)(6400 * BIN2), (UInt16)(6933 * BIN2), (UInt16)(7467 * BIN2),
(UInt16)(8000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rCorAdpACNCkFil_T
[TQADPCMP_16_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rCorAdpACSpdVeh_T
[TQADPCMP_16_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_rCorAdpNCkFil_T
[TQADPCMP_16_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_spdVeh_A[TQADPCMP_16_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(33 * BIN7), (UInt16)(67 * BIN7),
(UInt16)(100 * BIN7), (UInt16)(133 * BIN7), (UInt16)(167 * BIN7),
(UInt16)(200 * BIN7), (UInt16)(233 * BIN7), (UInt16)(267 * BIN7),
(UInt16)(300 * BIN7), (UInt16)(333 * BIN7), (UInt16)(367 * BIN7),
(UInt16)(400 * BIN7), (UInt16)(433 * BIN7), (UInt16)(467 * BIN7),
(UInt16)(500 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tqCorAdpTqAccu_T
[TQADPCMP_10_SIZE] = {
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_rcoradpacnckfil_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_rcoradpacspdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_rcoradpnckfil_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_tqcoradptqaccu_t_sav;
STATIC VAR(t_dds_m_slew, AUTOMATIC) tqadpcmp_01_02_03_03_rate_limit;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) tqadpcmp_01_02_03_02_01_turn_on_delay;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqadpcmp_01_02_03_02_01_edge_detect;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/* 32-bits variable definition */
#define TQADPCMP_START_SEC_VAR_32BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqadpcmp_01_02_03_02_01_rst_val;
STATIC VAR(UInt32, AUTOMATIC) tqadpcmp_01_02_03_03_prev_exe;
#define TQADPCMP_STOP_SEC_VAR_32BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) tqadp_idxtengraw_loc; /* BIN7 */
#define TQADPCMP_STOP_SEC_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqadpcmp_01_02_03_03_rate_limiter_init;
STATIC VAR(UInt8, AUTOMATIC) tqadp_idxteng_calc_tq_loc; /* BIN0 */
STATIC VAR(UInt8, AUTOMATIC) tqadp_bdragred_calc_tq_loc;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnItpol_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqEngCor; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnACCor; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_rCorAdpACNCkFil_MP; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_rCorAdpACSpdVeh_MP; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_rCorAdpNCkFil_MP; /* BIN7 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqAdp_facCorLrnIrvAC; /* BIN7 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_RCORADPACNCKFIL_T_APM = {
&tqadp_rcoradpacnckfil_t_sav,
TQADPCMP_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_nCkFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rCorAdpACNCkFil_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_RCORADPACSPDVEH_T_APM = {
&tqadp_rcoradpacspdveh_t_sav,
TQADPCMP_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_spdVeh_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rCorAdpACSpdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQADP_RCORADPNCKFIL_T_APM = {
&tqadp_rcoradpnckfil_t_sav,
TQADPCMP_16_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_nCkFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_rCorAdpNCkFil_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) TQADP_TQCORADPTQACCU_T_APM = {
&tqadp_tqcoradptqaccu_t_sav,
TQADPCMP_10_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTqAccu_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tqCorAdpTqAccu_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_01_Corriger_Couple_Base(UInt16 eng_nckfil_par, /* BIN2 */
                                                                       UInt8 tqsys_idxtqaccu_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_02_Reinitialiser_Corriger_Couple_Climatisation(UInt16 veh_spdveh_par, /* BIN7 */
                                                                                              UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_02_01_Reinitialiser_Couple_Climatisation(UInt16 veh_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_02_02_Corriger_Couple_Climatisation(UInt16 veh_spdveh_par, /* BIN7 */
                                                                                   UInt16 eng_nckfil_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_03_Limiter_Gradient_Couple_Applicable(
                                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckenglossadp_ptr /* BIN4 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Calc_Tq_Applicable
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Calc_Tq_Applicable(UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 TqSys_idxTqAccu_swc_in, /* BIN0 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLossAdp_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.16.6 */
    tqadp_idxteng_calc_tq_loc = TqAdp_idxTEng;
    tqadp_bdragred_calc_tq_loc = TqAdp_bDragRed;
    tqadp_idxtengraw_loc = TqAdp_idxTEngRaw;

    TQADPCMP_01_02_03_01_Corriger_Couple_Base(Eng_nCkFil_swc_in, /* BIN2 */
                                              TqSys_idxTqAccu_swc_in /* BIN0 */);

    TQADPCMP_01_02_03_02_Reinitialiser_Corriger_Couple_Climatisation(Veh_spdVeh_swc_in, /* BIN7 */
                                                                     Eng_nCkFil_swc_in /* BIN2 */);

    TQADPCMP_01_02_03_03_Limiter_Gradient_Couple_Applicable(TqSys_tqCkEngLossAdp_swc_out /* BIN4 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_03_01_Corriger_Couple_Base
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_01_Corriger_Couple_Base(UInt16 eng_nckfil_par, /* BIN2 */
                                                                       UInt8 tqsys_idxtqaccu_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.16.6 */

    UInt32 tqadpcmp_01_02_03_01_index_switch;
    SInt32 tqadpcmp_tqcorlrn_v1; /* BIN4 */
    SInt32 tqadpcmp_tqcorlrn_v2; /* BIN4 */
    SInt32 tqadpcmp_idxdif1tengraw; /* BIN7 */
    SInt32 tqadpcmp_idxdif2tengraw; /* BIN7 */
    SInt32 tqadpcmp_01_02_03_01_tab_out; /* BIN4 */

    if(((UInt32)tqadp_idxteng_calc_tq_loc*BIN7)!=(UInt32)tqadp_idxtengraw_loc)
    {
        tqadpcmp_01_02_03_01_index_switch = (UInt32)((SInt32)tqadp_idxteng_calc_tq_loc*2);
    }
    else
    {
        tqadpcmp_01_02_03_01_index_switch = (UInt32)(((SInt32)tqadp_idxteng_calc_tq_loc*2)-1);
    }

    switch(tqadpcmp_01_02_03_01_index_switch)
    {
        case (UInt32)1:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[0];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[0];
            }
            break;
        case (UInt32)2:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[0];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[1];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[0];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[1];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)3:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[1];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[1];
            }
            break;
        case (UInt32)4:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[1];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[2];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[1];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[2];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)5:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[2];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[2];
            }
            break;
        case (UInt32)6:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[2];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[3];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[2];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[3];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)7:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[3];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[3];
            }
            break;
        case (UInt32)8:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[3];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[4];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[3];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[4];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)9:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[4];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[4];
            }
            break;
        case (UInt32)10:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[4];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[5];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[4];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[5];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)11:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[5];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[5];
            }
            break;
        case (UInt32)12:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[5];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[6];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[5];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[6];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)13:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[6];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[6];
            }
            break;
        case (UInt32)14:
            tqadpcmp_idxdif2tengraw = (SInt32)tqadp_idxtengraw_loc % (1*BIN7);
            tqadpcmp_idxdif1tengraw = (1*BIN7) - tqadpcmp_idxdif2tengraw;
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnDragRed[6];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnDragRed[7];
            }
            else
            {
                tqadpcmp_tqcorlrn_v1 = TqAdp_prm_tqCorLrnNeut[6];
                tqadpcmp_tqcorlrn_v2 = TqAdp_prm_tqCorLrnNeut[7];
            }
            TqAdp_tqCorLrnItpol_MP = (SInt16)(((tqadpcmp_tqcorlrn_v1*tqadpcmp_idxdif1tengraw)+
                                     (tqadpcmp_tqcorlrn_v2*tqadpcmp_idxdif2tengraw))/BIN7);
            break;
        case (UInt32)15:
        default:
            if((UInt32)tqadp_bdragred_calc_tq_loc!=(UInt32)DDS_FALSE)
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnDragRed[7];
            }
            else
            {
                TqAdp_tqCorLrnItpol_MP = TqAdp_prm_tqCorLrnNeut[7];
            }
            break;
    }

    TqAdp_rCorAdpNCkFil_MP = (UInt8)DDS_M_MAP2D_U16(&TQADP_RCORADPNCKFIL_T_APM,eng_nckfil_par);

    /* [-2000,2000] BIN4 */
    tqadpcmp_idxdif2tengraw = ((SInt32)TqAdp_rCorAdpNCkFil_MP * (SInt32)TqAdp_tqCorLrnItpol_MP) / BIN7;

    /* [-2000,2000] BIN4 */
    tqadpcmp_01_02_03_01_tab_out = (SInt32)DDS_M_MAP2D_US16(&TQADP_TQCORADPTQACCU_T_APM,tqsys_idxtqaccu_par);

    TqAdp_tqEngCor = (SInt16) DDS_M_LIMIT(tqadpcmp_idxdif2tengraw + tqadpcmp_01_02_03_01_tab_out,-2000*BIN4,2000*BIN4);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_03_02_Reinitialiser_Corriger_Couple_Climatisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_02_Reinitialiser_Corriger_Couple_Climatisation(UInt16 veh_spdveh_par, /* BIN7 */
                                                                                              UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.54.0 */
    TQADPCMP_01_02_03_02_01_Reinitialiser_Couple_Climatisation(veh_spdveh_par /* BIN7 */);
    TQADPCMP_01_02_03_02_02_Corriger_Couple_Climatisation(veh_spdveh_par /* BIN7 */,
                                                          eng_nckfil_par /* BIN2 */);
}


/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_03_02_01_Reinitialiser_Couple_Climatisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_02_01_Reinitialiser_Couple_Climatisation(UInt16 veh_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.20.1 */
    UInt32 tqadpcmp_01_02_03_02_01_te;
    UInt32 tqadpcmp_01_02_03_02_01_tutn_on_out;
    t_dds_m_edge_detected_event tqadpcmp_01_02_03_02_01_edge_out;

    tqadpcmp_01_02_03_02_01_te = DDS_TQADPCMP_1MS_U32_TIME;

    if((UInt32)veh_spdveh_par>=(UInt32)TqAdp_spdCorLrnSpdVehThd_C)
    {
        tqadpcmp_01_02_03_02_01_tutn_on_out = DDS_M_TURN_ON_DELAY(DDS_TRUE,
                                                                  tqadpcmp_01_02_03_02_01_te,
                                                                  (UInt32)((SInt32)TqAdp_tiDlyCorLrnSpdVeh_C*DEC3),
                                                                  &tqadpcmp_01_02_03_02_01_turn_on_delay);
    }
    else
    {
        tqadpcmp_01_02_03_02_01_tutn_on_out = DDS_M_TURN_ON_DELAY(DDS_FALSE,
                                                                  tqadpcmp_01_02_03_02_01_te,
                                                                  (UInt32)((SInt32)TqAdp_tiDlyCorLrnSpdVeh_C*DEC3),
                                                                  &tqadpcmp_01_02_03_02_01_turn_on_delay);
    }

    if((UInt32)TqAdp_bCorLrnCdnAC!=(UInt32)DDS_FALSE)
    {
        TqAdp_bCorLrnIrvAC = DDS_FALSE;
    }
    else
    {
        if(tqadpcmp_01_02_03_02_01_tutn_on_out !=(UInt32)DDS_FALSE)
        {
            TqAdp_bCorLrnIrvAC = DDS_TRUE;
        }
        else
        {
            /* Nothing to do */
        }
    }

    tqadpcmp_01_02_03_02_01_edge_out = DDS_M_EDGE_DETECT(&tqadpcmp_01_02_03_02_01_edge_detect,TqAdp_bCorLrnIrvAC);

    if (tqadpcmp_01_02_03_02_01_edge_out == DDS_M_POSITIVE_EDGE_DETECTED)
    {
        tqadpcmp_01_02_03_02_01_rst_val = BIN7*DEC3;
    }
    else
    {
        if (tqadpcmp_01_02_03_02_01_rst_val <= ((UInt32)TqAdp_tiCorLrnSpdVeh_C*(UInt32)TQADPCMP_TISCHED))
        {
            tqadpcmp_01_02_03_02_01_rst_val = 0;
        }
        else
        {
            tqadpcmp_01_02_03_02_01_rst_val = (UInt32)((SInt32)tqadpcmp_01_02_03_02_01_rst_val -
                                                       ((SInt32)TqAdp_tiCorLrnSpdVeh_C*(SInt32)TQADPCMP_TISCHED));
        }
    }

    if((UInt32)TqAdp_bCorLrnIrvAC!=(UInt32)DDS_FALSE)
    {
        TqAdp_facCorLrnIrvAC = (UInt8)(tqadpcmp_01_02_03_02_01_rst_val/DEC3);
    }
    else
    {
        TqAdp_facCorLrnIrvAC = (UInt8)(1 * BIN7);
    }

}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_03_02_02_Corriger_Couple_Climatisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_02_02_Corriger_Couple_Climatisation(UInt16 veh_spdveh_par, /* BIN7 */
                                                                                   UInt16 eng_nckfil_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.56.0 */

    TqAdp_tqCorLrnIrvAC = (SInt16)(((SInt32)TqAdp_facCorLrnIrvAC * (SInt32)TqAdp_tqCorLrnAC) / BIN7);
    TqAdp_rCorAdpACSpdVeh_MP = (UInt8)DDS_M_MAP2D_U16(&TQADP_RCORADPACSPDVEH_T_APM,veh_spdveh_par);
    TqAdp_rCorAdpACNCkFil_MP = (UInt8)DDS_M_MAP2D_U16(&TQADP_RCORADPACNCKFIL_T_APM,eng_nckfil_par);

    TqAdp_tqCorLrnACCor = (SInt16)((((SInt32)TqAdp_tqCorLrnIrvAC * (SInt32)TqAdp_rCorAdpACSpdVeh_MP) * (SInt32)TqAdp_rCorAdpACNCkFil_MP)/BIN14);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_03_03_Limiter_Gradient_Couple_Applicable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_03_03_Limiter_Gradient_Couple_Applicable(
                                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckenglossadp_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.55.0 */
    SInt32 tqadpcmp_01_02_03_03_rate_in; /* BIN4 */
    SInt32 tqadpcmp_01_02_03_03_rate_out; /* BIN4 */
    UInt32 tqadpcmp_01_02_03_03_time;
    UInt32 tqadpcmp_01_02_03_03_delta_time;

    tqadpcmp_01_02_03_03_time = DDS_TQADPCMP_1MS_U32_TIME;

    tqadpcmp_01_02_03_03_delta_time = tqadpcmp_01_02_03_03_time - tqadpcmp_01_02_03_03_prev_exe;

    tqadpcmp_01_02_03_03_prev_exe = tqadpcmp_01_02_03_03_time;

    if((UInt32)TqAdp_bCorLrnWoutAC!=(UInt32)DDS_FALSE)
    {
        tqadpcmp_01_02_03_03_rate_in = (SInt32)TqAdp_tqEngCor;
    }
    else
    {
        tqadpcmp_01_02_03_03_rate_in = (SInt32)TqAdp_tqEngCor + (SInt32)TqAdp_tqCorLrnACCor;
    }

    if((UInt32)tqadpcmp_01_02_03_03_rate_limiter_init!=(UInt32)DDS_TRUE)
    {
        tqadpcmp_01_02_03_03_rate_limiter_init = DDS_TRUE;
        tqadpcmp_01_02_03_03_rate_out = DDS_M_SLEW_S32_INIT(&tqadpcmp_01_02_03_03_rate_limit, tqadpcmp_01_02_03_03_rate_in * DEC3); /* BIN4 * DEC3 */

        /* BIN4 = BIN4 * DEC3 / DEC3 */
        tqadpcmp_01_02_03_03_rate_out = tqadpcmp_01_02_03_03_rate_out / DEC3;
    }
    else
    {
        tqadpcmp_01_02_03_03_rate_out =DDS_M_SLEW_S32(&tqadpcmp_01_02_03_03_rate_limit,
                                             tqadpcmp_01_02_03_03_rate_in * DEC3,  /* BIN4 * DEC3 */
                                             (UInt32)((SInt32)TqAdp_tqCorLrnIncMax_C*(SInt32)tqadpcmp_01_02_03_03_delta_time), /* BIN4 * DEC3 */
                                             (UInt32)(-(SInt32)TqAdp_tqCorLrnDecMax_C*(SInt32)tqadpcmp_01_02_03_03_delta_time)) /* BIN4 * DEC3 */;
        /* BIN4 = BIN4 * DEC3 / DEC3 */
        tqadpcmp_01_02_03_03_rate_out = tqadpcmp_01_02_03_03_rate_out / DEC3;
    }

    *tqsys_tqckenglossadp_ptr = (SInt16)DDS_M_LIMIT(tqadpcmp_01_02_03_03_rate_out,-2000*BIN4,2000*BIN4);
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Calc_Tq_Applicable_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Calc_Tq_Applicable_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngLossAdp_swc_out /* BIN4 */)
{
    *TqSys_tqCkEngLossAdp_swc_out = (SInt16)(0 * BIN4);
    tqadpcmp_01_02_03_03_rate_limiter_init = DDS_FALSE;

    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&tqadpcmp_01_02_03_02_01_turn_on_delay);

    TqAdp_bCorLrnIrvAC = DDS_FALSE;
    DDS_M_EDGE_DETECT_INIT(&tqadpcmp_01_02_03_02_01_edge_detect,DDS_FALSE);

    tqadpcmp_01_02_03_02_01_rst_val = 0;
    tqadpcmp_01_02_03_03_prev_exe = 0;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"
