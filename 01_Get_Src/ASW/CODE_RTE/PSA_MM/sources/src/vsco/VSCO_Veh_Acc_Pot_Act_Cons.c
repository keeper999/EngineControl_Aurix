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
* Ref X:\integration_view_00PSASWC_D720D01\blois_psa_sstg\Software\Appli\VSCo\src\VSCO_Veh_Acc_Pot_Act_Cons.c
* Version int :/main/L03_01/1 Date: 10/1/2012 8 h 34 m User:meme 
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L03_010_IMPL1
*    comments :For VSCo_12_0_e6
* Version dev :\main\branch_halouane_vsco_euro6\1 Date: 1/12/2011 14 h 32 m User:halouane 
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L03_010_IMPL1
*    comments :For VSCo_12_0_e6
* Version int :/main/L02_01/1 Date: 6/9/2011 15 h 42 m User:meme
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L02_010_IMPL1
*    comments :correction following TU report for VSCo 11.0
* Version dev :\main\branch_demezil_vsco_view\1 Date: 26/8/2011 16 h 22 m User:demezil
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L02_010_IMPL1
*    comments :correction following TU report for VSCo 11.0
* Version dev :\main\branch_halouane_vsco_euro6\1 Date: 9/8/2011 15 h 42 m User:halouane
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L02_010_IMPL1
*    comments :For vsco_11.0_e6
* Version int :/main/L01_01/2 Date: 24/2/2011 10 h 21 m User:esnault
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0 (Correction after TU)
* Version dev :\main\branch_veillard_vsco\9 Date: 18/2/2011 9 h 27 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0 (Correction after TU)
* Version int :/main/L01_01/1 Date: 4/2/2011 17 h 29 m User:esnault
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\8 Date: 4/2/2011 12 h 43 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\7 Date: 3/2/2011 17 h 11 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\6 Date: 27/1/2011 12 h 33 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\5 Date: 26/1/2011 14 h 21 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\4 Date: 25/1/2011 17 h 58 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\3 Date: 14/12/2010 17 h 47 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCO 10.0
* Version dev :\main\branch_veillard_vsco\2 Date: 14/12/2010 11 h 30 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCO 10.0
* Version dev :\main\branch_veillard_vsco\1 Date: 13/12/2010 17 h 42 m User:veillard
*    TWK_model:VSCO_Veh_Acc_Pot_Act_Cons_L01_010_IMPL1
*    comments :For VSCO 10.0
*
*******************************************************************************/



/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSCo.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/


/* VSCtl_stHld_aVehPot */
#define VSCO_ACCEL_POT_CONS_PAS_GEL         (UInt32)0
#define VSCO_ACCEL_POT_CONS_GEL_1_INIT      (UInt32)1
#define VSCO_ACCEL_POT_CONS_GEL_1           (UInt32)2
#define VSCO_ACCEL_POT_CONS_GEL_2_MONTE     (UInt32)3
#define VSCO_ACCEL_POT_CONS_GEL_2_DESCENTE  (UInt32)4
#define VSCO_ACCEL_POT_CONS_GEL_INHIBITION  (UInt32)5


/* stateflow vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule */
#define VSCO_F6211_PAS_GEL          (UInt32)0
#define VSCO_F6211_GEL_1_INIT       (UInt32)1
#define VSCO_F6211_GEL_1            (UInt32)2
#define VSCO_F6211_GEL_2_MONTE      (UInt32)3
#define VSCO_F6211_GEL_2_DESCENTE   (UInt32)4
#define VSCO_F6211_GEL_INHIBITION   (UInt32)5

/*  values */
#define VSCO_ACCEL_POT_CONS_10_BIN10_NEG    (SInt16)(-10 * BIN10)
#define VSCO_ACCEL_POT_CONS_10_BIN10_POS    (SInt16)(10 * BIN10)
#define VSCO_ACCEL_POT_CONS_0_BIN10         (SInt16)(0 * BIN10)



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

/* 16-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_aVehPotMaxReq; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehPotMinReq; /* BIN10 */
VAR(UInt16, AUTOMATIC) VSCtl_aVehRsv_HysHi; /* BIN10 */
VAR(UInt16, AUTOMATIC) VSCtl_aVehRsv_HysLo; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aResFil; /* BIN10 */
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bHld_aVehPotReq;
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_aVehPot;
#define VSCO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSCO_START_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHldMin_aVehPotReq_C        = (CONST(UInt16, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHldMax_aVehPotReq_C        = (CONST(UInt16, AUTOMATIC))(399 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_aVehPotReq_C           = (CONST(UInt16, AUTOMATIC))(1 * DEC3);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiNotHldMin_aVehPot_C        = (CONST(UInt16, AUTOMATIC))(199 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErr_aVehPot_SlopN_C    = (CONST(SInt16, AUTOMATIC))(-10 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehErr_aVehPot_SlopP_C    = (CONST(SInt16, AUTOMATIC))(10 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aResErr_aVehPot_Hys_C        = (CONST(SInt16, AUTOMATIC))(0.5 * BIN10);
#define VSCO_STOP_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSCO_START_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_ctSIPChg_aVehPot_C    = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacHld_aVehPotReq_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacPosnGBxLev_C     = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacSpdVehErr_C      = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacAResErr_C        = DDS_FALSE;
#define VSCO_STOP_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSCO_START_SEC_CARTO_16BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehRsvHysHi_aRes_T
[VSC_8_SIZE] = {
(SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10),
(SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10),
(SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aRes_aVehRsvHysHi_A[VSC_8_SIZE] = {
(SInt16)(-5 * BIN10), (SInt16)(-2 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(1 * BIN10), (SInt16)(2 * BIN10),
(SInt16)(5 * BIN10), (SInt16)(10 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehRsvHysLo_aRes_T
[VSC_8_SIZE] = {
(SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10),
(SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10),
(SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10), (SInt16)(0.125 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aRes_aVehRsvHysLo_A[VSC_8_SIZE] = {
(SInt16)(-5 * BIN10), (SInt16)(-2 * BIN10), (SInt16)(-1 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(1 * BIN10), (SInt16)(2 * BIN10),
(SInt16)(5 * BIN10), (SInt16)(10 * BIN10)
};

#define VSCO_STOP_SEC_CARTO_16BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define VSCO_START_SEC_VAR_8BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsco_f6211_mode_calcul_consignes_potentiel_acceleration_vehicule_global;
STATIC VAR(UInt8, AUTOMATIC) vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule;
#define VSCO_STOP_SEC_VAR_8BIT
#include "VSCo_MemMap.h"

/* 16-bits variable definition */
#define VSCO_START_SEC_VAR_16BIT
#include "VSCo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehpotminreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehpotreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehpotmaxreq_prev;
#define VSCO_STOP_SEC_VAR_16BIT
#include "VSCo_MemMap.h"

/* 32-bits variable definition */
#define VSCO_START_SEC_VAR_32BIT
#include "VSCo_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) f6212_sat_out_max;
STATIC VAR(SInt32, AUTOMATIC) f6212_sat_out_min;
#define VSCO_STOP_SEC_VAR_32BIT
#include "VSCo_MemMap.h"

/* Complex variable definition */
#define VSCO_START_SEC_VAR_UNSPECIFIED
#include "VSCo_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_avehrsvhyshi_ares_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_avehrsvhyslo_ares_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) f6214_low_pass_t_struct;
#define VSCO_STOP_SEC_VAR_UNSPECIFIED
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPotReqRaw; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPotReq; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aResRef_aVehPot; /* BIN10 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehErrRef_aVehPot_1; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehErrRef_aVehPot_2; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehRef_aVehPot; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHldMax_aVehPotReq; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHldMin_aVehPotReq; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiNotHldMin_aVehPot; /* BIN0 */
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVehPot;
/* <PRQA_COMMENT><3229> variable linked to a terminator in the SPEC</3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stHld_aVehPot; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTPotPre_no3;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_ctSIPChg_aVehPot; /* BIN0 */
#define VSCO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSCO_START_SEC_CONST_UNSPECIFIED
#include "VSCo_MemMap.h"
STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_AVEHRSVHYSHI_ARES_T_APM = {
&vsctl_avehrsvhyshi_ares_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aRes_aVehRsvHysHi_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehRsvHysHi_aRes_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_AVEHRSVHYSLO_ARES_T_APM = {
&vsctl_avehrsvhyslo_ares_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aRes_aVehRsvHysLo_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehRsvHysLo_aRes_T[0]
};

#define VSCO_STOP_SEC_CONST_UNSPECIFIED
#include "VSCo_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSCO_START_SEC_CODE
#include "VSCo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6211_Veh_Accel_Pot_Cons_Calc_Mode_Deter(UInt8  vsctl_stvsctlinfo_par,
                                                                           SInt16 vsctl_avehptmax_par,
                                                                           SInt16 vsctl_avehptmin_par,
                                                                           UInt16 vsctl_spdveh_par,
                                                                           UInt8  vsctl_bavltqwhlpt_no3_par,
                                                                           UInt8  ext_stgbxcf_par,
                                                                           UInt8  copt_posnlev_par,
                                                                           UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                           UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                           UInt8  ext_bposngbxcf_par );


STATIC FUNC(void, AUTOMATIC) VSCO_F6212_Veh_Accel_Pot_Cons_Coord(SInt16 vsctl_avehpotvsregreq_par,
                                                                 SInt16 vsctl_avehpotvslimreq_par,
                                                                 SInt16 vsctl_avehpotdvsregreq_par,
                                                                 SInt16 vsctl_avehpotvsmaxreq_par,
                                                                 SInt16 vsctl_avehptpotmax_par,
                                                                 SInt16 vsctl_avehptpotmin_par,
                                                                 UInt8  ext_stdvsregcf_par,
                                                                 UInt8  ext_bvslimcf_par,
                                                                 UInt8  ext_bvsmaxfcf_par,
                                                                 UInt8  ext_bvsmaxpcf_par,
                                                                 UInt8  ext_bvsmaxscf_par);


STATIC FUNC(void, AUTOMATIC) VSCO_F6213_Veh_Accel_Pot_Res_Deter(SInt16 vsctl_ares_par);


STATIC FUNC(void, AUTOMATIC) VSCO_F6214_Filtering_Resist_Accel_Deter(SInt16 vsctl_ares_par);


STATIC FUNC(void, AUTOMATIC) VSCO_F6212_Sat_Output_Calc(SInt16 vsctl_avehptpotmax_par,
                                                        SInt16 vsctl_avehptpotmin_par,
                                                        UInt8  ext_stdvsregcf_par,
                                                        SInt16 vsctl_avehpotvsregreq_par,
                                                        SInt16 vsctl_avehpotdvsregreq_par,
                                                        UInt8  ext_bvslimcf_par,
                                                        SInt16 vsctl_avehpotvslimreq_par,
                                                        UInt8  ext_bvsmaxfcf_par,
                                                        UInt8  ext_bvsmaxpcf_par,
                                                        UInt8  ext_bvsmaxscf_par,
                                                        SInt16 vsctl_avehpotvsmaxreq_par);



/*******************************************************************************
*
* Function Name : VSCO_Veh_Acc_Pot_Act_Cons
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Veh_Acc_Pot_Act_Cons(UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                                                SInt16 VSCtl_aRes_swc_in, /* BIN10 */
                                                SInt16 VSCtl_aVehPotVSRegReq_swc_in, /* BIN10 */
                                                SInt16 VSCtl_aVehPotVSLimReq_swc_in, /* BIN10 */
                                                SInt16 VSCtl_aVehPotDVSRegReq_swc_in, /* BIN10 */
                                                SInt16 VSCtl_aVehPotVSMaxReq_swc_in, /* BIN10 */
                                                UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                UInt8 Ext_stGBxCf_swc_in,
                                                UInt8 CoPt_posnLev_swc_in,
                                                SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                                SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                                UInt8 VSCtl_stVSCtlInfo_swc_in,
                                                SInt16 VSCtl_aVehPTPotMax_swc_in, /* BIN10 */
                                                SInt16 VSCtl_aVehPTPotMin_swc_in, /* BIN10 */
                                                UInt8 Ext_stDVSRegCf_swc_in,
                                                UInt8 Ext_bVSLimCf_swc_in,
                                                UInt8 Ext_bVSMaxfCf_swc_in,
                                                UInt8 Ext_bVSMaxpCf_swc_in,
                                                UInt8 Ext_bVSMaxsCf_swc_in,
                                                UInt8 VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                UInt8 VSCtl_stCtl_tqWhlPotMin_swc_in,
                                                UInt8 Ext_bPosnGBxCf_swc_in,
                                                UInt8 Ext_stCtlCmdPTTqPotCf_swc_in)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.22.4 */

    if((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in != VSCO_STCTLCMDPTTQPOTCF_LEURAGE_PED )
    {
        VSCO_F6211_Veh_Accel_Pot_Cons_Calc_Mode_Deter(VSCtl_stVSCtlInfo_swc_in,
                                                          VSCtl_aVehPTMax_swc_in,
                                                          VSCtl_aVehPTMin_swc_in,
                                                          VSCtl_spdVeh_swc_in,
                                                          VSCtl_bAvlTqWhlPT_no3_swc_in,
                                                          Ext_stGBxCf_swc_in,
                                                          CoPt_posnLev_swc_in,
                                                          VSCtl_stCtl_tqWhlPotMax_swc_in,
                                                          VSCtl_stCtl_tqWhlPotMin_swc_in,
                                                          Ext_bPosnGBxCf_swc_in );



        VSCO_F6212_Veh_Accel_Pot_Cons_Coord(VSCtl_aVehPotVSRegReq_swc_in,
                                                VSCtl_aVehPotVSLimReq_swc_in,
                                                VSCtl_aVehPotDVSRegReq_swc_in,
                                                VSCtl_aVehPotVSMaxReq_swc_in,
                                                VSCtl_aVehPTPotMax_swc_in,
                                                VSCtl_aVehPTPotMin_swc_in,
                                                Ext_stDVSRegCf_swc_in,
                                                Ext_bVSLimCf_swc_in,
                                                Ext_bVSMaxfCf_swc_in,
                                                Ext_bVSMaxpCf_swc_in,
                                                Ext_bVSMaxsCf_swc_in);


        VSCO_F6213_Veh_Accel_Pot_Res_Deter(VSCtl_aRes_swc_in);


        VSCO_F6214_Filtering_Resist_Accel_Deter(VSCtl_aRes_swc_in);
    }
    else
    {
        /*Do nothing*/
    }

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_F6211_Veh_Accel_Pot_Cons_Calc_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6211_Veh_Accel_Pot_Cons_Calc_Mode_Deter(UInt8  vsctl_stvsctlinfo_par,
                                                                           SInt16 vsctl_avehptmax_par,
                                                                           SInt16 vsctl_avehptmin_par,
                                                                           UInt16 vsctl_spdveh_par,
                                                                           UInt8  vsctl_bavltqwhlpt_no3_par,
                                                                           UInt8  ext_stgbxcf_par,
                                                                           UInt8  copt_posnlev_par,
                                                                           UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                           UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                           UInt8  ext_bposngbxcf_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.23.5 */

    SInt32 vsctl_spdveherrref_avehpot_1_unlim;
    SInt32 vsctl_spdveherrref_avehpot_2_unlim;


    /* MODE_CALCUL_CONSIGNES_POTENTIEL_ACCELERATION_VEHICULE_GLOBAL */
    switch((UInt32)vsco_f6211_mode_calcul_consignes_potentiel_acceleration_vehicule_global)
    {
        case (UInt32)DDS_FALSE:
            if((UInt32)vsctl_stvsctlinfo_par == VSCO_NOMINAL_20)
            {
                vsco_f6211_mode_calcul_consignes_potentiel_acceleration_vehicule_global = DDS_TRUE;
                VSCtl_stCtl_aVehPot     = (UInt8)VSCO_CONTROLE;
                VSCtl_bAcvFil_aVehPot   = DDS_TRUE;
            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case (UInt32)DDS_TRUE:
            if((UInt32)vsctl_stvsctlinfo_par != VSCO_NOMINAL_20)
            {
                vsco_f6211_mode_calcul_consignes_potentiel_acceleration_vehicule_global = DDS_FALSE;
                VSCtl_stCtl_aVehPot     = (UInt8)VSCO_ARRET;
                VSCtl_bAcvFil_aVehPot   = DDS_FALSE;
            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_stCtl_aVehPot     = (UInt8)VSCO_ARRET;
            VSCtl_bAcvFil_aVehPot   = DDS_FALSE;
        break;
    }



    /* MODE_GEL_CONSIGNES_POTENTIEL_ACCELERATION_VEHICULE */
    switch((UInt32)vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule)
    {
        case VSCO_F6211_PAS_GEL:
            if(((UInt32)VSCtl_bDeacHld_aVehPotReq_C == (UInt32)DDS_FALSE)                                                                   &&
               (((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_POT_CONTROLE) || ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_POT_CONTROLE))   &&
               ((UInt32)ext_stgbxcf_par != VSCO_BVM)                                                                                        &&
               (((UInt32)copt_posnlev_par == VSCO_COPT_POSNLEV_DRIVE) || ((UInt32)DDS_FALSE == (UInt32)ext_bposngbxcf_par)
               || ((UInt32)VSCtl_bDeacPosnGBxLev_C == (UInt32)DDS_TRUE))                                                                    &&
               ((UInt32)vsctl_bavltqwhlpt_no3_par == (UInt32)DDS_FALSE)                                                                     &&
               ((UInt32)VSCtl_bAvlTqWhlPTPotPre_no3 == (UInt32)DDS_TRUE))   /* tracking sheet spec add */
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_1_INIT;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_GEL_1_INIT;
                VSCtl_bHld_aVehPotReq   = DDS_TRUE;
                VSCtl_spdVehRef_aVehPot = vsctl_spdveh_par;
                VSCtl_ctSIPChg_aVehPot  = (UInt8)(0 * BIN0);
            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F6211_GEL_1_INIT:
            if( ((UInt32)VSCtl_bDeacHld_aVehPotReq_C == (UInt32)DDS_TRUE)                           /* Go back to PAS_GEL */                ||
                (((UInt32)vsctl_stctl_tqwhlpotmin_par != VSCO_POT_CONTROLE) && ((UInt32)vsctl_stctl_tqwhlpotmax_par != VSCO_POT_CONTROLE))  ||
                (((UInt32)copt_posnlev_par != VSCO_COPT_POSNLEV_DRIVE) && ((UInt32)DDS_FALSE != (UInt32)ext_bposngbxcf_par)
                && ((UInt32)VSCtl_bDeacPosnGBxLev_C == (UInt32)DDS_FALSE))                                                                  ||
                ((UInt32)ext_stgbxcf_par == VSCO_BVM))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);

            }

            else if(    (   ((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_POT_CONTROLE) ||                          /* Go back to GEL_INHIBITION */
                            ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_POT_CONTROLE) )    &&
                        (   ((UInt32)VSCtl_ctSIPChg_aVehPot >= (UInt32)VSCtl_ctSIPChg_aVehPot_C)    ||
                            ((UInt32)VSCtl_tiHldMax_aVehPotReq == 0)  ) )
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_INHIBITION;
                VSCtl_stHld_aVehPot = (UInt8)VSCO_ACCEL_POT_CONS_GEL_INHIBITION;
                VSCtl_bHld_aVehPotReq = DDS_FALSE;
            }

            else                                                                                        /* Go to GEL_1 */
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_1;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_GEL_1;
                VSCtl_bHld_aVehPotReq   = DDS_TRUE;
                VSCtl_ctSIPChg_aVehPot  = (UInt8)DDS_M_LIMITED_INCREMENT((SInt32)VSCtl_ctSIPChg_aVehPot,
                                                                         (SInt32)(1 * BIN0),
                                                                         (SInt32)DDS_UINT8_MAX);
            }
        break;

        case VSCO_F6211_GEL_1:
            if( ((UInt32)VSCtl_bDeacHld_aVehPotReq_C == (UInt32)DDS_TRUE)                           /* Go back to PAS_GEL */                ||
                (((UInt32)vsctl_stctl_tqwhlpotmin_par != VSCO_POT_CONTROLE) && ((UInt32)vsctl_stctl_tqwhlpotmax_par != VSCO_POT_CONTROLE))  ||
                (((UInt32)copt_posnlev_par != VSCO_COPT_POSNLEV_DRIVE) && ((UInt32)DDS_FALSE != (UInt32)ext_bposngbxcf_par)
                && ((UInt32)VSCtl_bDeacPosnGBxLev_C == (UInt32)DDS_FALSE))                                                                  ||
                ((UInt32)ext_stgbxcf_par == VSCO_BVM))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);

            }

            else if(    (   ((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_POT_CONTROLE) ||                          /* Go back to GEL_INHIBITION */
                            ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_POT_CONTROLE) )    &&
                        (   ((UInt32)VSCtl_ctSIPChg_aVehPot >= (UInt32)VSCtl_ctSIPChg_aVehPot_C)    ||
                            ((UInt32)VSCtl_tiHldMax_aVehPotReq == 0)  ) )
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_INHIBITION;
                VSCtl_stHld_aVehPot = (UInt8)VSCO_ACCEL_POT_CONS_GEL_INHIBITION;
                VSCtl_bHld_aVehPotReq = DDS_FALSE;
            }

            else if(((UInt32)vsctl_bavltqwhlpt_no3_par == (UInt32)DDS_TRUE) &&                          /* Go to GEL_2_DESCENTE */
                    ((SInt32)VSCtl_aResFil > (SInt32)(0 * BIN10)))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_2_DESCENTE;
                VSCtl_stHld_aVehPot = (UInt8)VSCO_ACCEL_POT_CONS_GEL_2_DESCENTE;
                VSCtl_tiHldMin_aVehPotReq = VSCtl_tiHldMin_aVehPotReq_C;
            }

            else if(((UInt32)vsctl_bavltqwhlpt_no3_par == (UInt32)DDS_TRUE) &&                          /* Go to GEL_2_MONTE */
                    ((SInt32)VSCtl_aResFil <= (SInt32)(0 * BIN0)))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_2_MONTE;
                VSCtl_stHld_aVehPot = (UInt8)VSCO_ACCEL_POT_CONS_GEL_2_MONTE;
                VSCtl_tiHldMin_aVehPotReq = VSCtl_tiHldMin_aVehPotReq_C;
            }
            else        /* during actions */
            {
                VSCtl_tiHldMax_aVehPotReq = (UInt16)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiHldMax_aVehPotReq,
                                                                            (UInt32)(1 * BIN0),
                                                                            (UInt32)(0 * BIN0));

                vsctl_spdveherrref_avehpot_1_unlim = ((SInt32)VSCtl_spdVehRef_aVehPot - (SInt32)vsctl_spdveh_par);
                VSCtl_spdVehErrRef_aVehPot_1       = (UInt16)DDS_M_MAX(vsctl_spdveherrref_avehpot_1_unlim,(SInt32)(0 * BIN7));
                VSCtl_aResRef_aVehPot = VSCtl_aResFil;
            }
        break;

        case VSCO_F6211_GEL_2_DESCENTE:
            if( ((UInt32)VSCtl_bDeacHld_aVehPotReq_C == (UInt32)DDS_TRUE)                           /* Go back to PAS_GEL */                ||
                (((UInt32)vsctl_stctl_tqwhlpotmin_par != VSCO_POT_CONTROLE) && ((UInt32)vsctl_stctl_tqwhlpotmax_par != VSCO_POT_CONTROLE))  ||
                (((UInt32)copt_posnlev_par != VSCO_COPT_POSNLEV_DRIVE) && ((UInt32)DDS_FALSE != (UInt32)ext_bposngbxcf_par)
                && ((UInt32)VSCtl_bDeacPosnGBxLev_C == (UInt32)DDS_FALSE))                                                                  ||
                ((UInt32)ext_stgbxcf_par == VSCO_BVM))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);

            }


            else if(    (   ((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_POT_CONTROLE) ||                          /* Go back to GEL_INHIBITION */
                            ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_POT_CONTROLE) )    &&
                        (   ((UInt32)VSCtl_ctSIPChg_aVehPot >= (UInt32)VSCtl_ctSIPChg_aVehPot_C)    ||
                            ((UInt32)VSCtl_tiHldMax_aVehPotReq == 0)  ) )
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_INHIBITION;
                VSCtl_stHld_aVehPot = (UInt8)VSCO_ACCEL_POT_CONS_GEL_INHIBITION;
                VSCtl_bHld_aVehPotReq = DDS_FALSE;
            }

            else if((UInt32)vsctl_bavltqwhlpt_no3_par == (UInt32)DDS_FALSE)                         /* Go to GEL_1 */
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_1;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_GEL_1;
                VSCtl_bHld_aVehPotReq   = DDS_TRUE;
                VSCtl_ctSIPChg_aVehPot  = (UInt8)DDS_M_LIMITED_INCREMENT((SInt32)VSCtl_ctSIPChg_aVehPot,
                                                                                         (SInt32)(1 * BIN0),
                                                                                         (SInt32)DDS_UINT8_MAX);
            }

            else if(((UInt32)VSCtl_tiHldMin_aVehPotReq == 0)
                                    &&
                    ((((UInt32)VSCtl_bDeacSpdVehErr_C == (UInt32)DDS_FALSE)
                    && ((SInt32)VSCtl_spdVehErrRef_aVehPot_2 < ((SInt32)VSCtl_spdVehErrRef_aVehPot_1 - (SInt32)VSCtl_spdVehErr_aVehPot_SlopN_C)))
                                    ||
                    (((UInt32)VSCtl_bDeacAResErr_C == (UInt32)DDS_FALSE)
                    && ((DDS_M_ABS((SInt32)VSCtl_aResRef_aVehPot - (SInt32)VSCtl_aResFil)) > (SInt32)VSCtl_aResErr_aVehPot_Hys_C))
                                    ||
                    (((SInt32)VSCtl_aVehPotReqRaw <= (SInt32)vsctl_avehptmax_par)
                    && ((SInt32)VSCtl_aVehPotReqRaw >= (SInt32)vsctl_avehptmin_par))))

            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);
            }

            else        /* during actions */
            {
                VSCtl_tiHldMin_aVehPotReq = (UInt16)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiHldMin_aVehPotReq,
                                                                         (UInt32)(1 * BIN0),
                                                                         (UInt32)(0 * BIN0));

                VSCtl_tiHldMax_aVehPotReq = (UInt16)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiHldMax_aVehPotReq,
                                                                         (UInt32)(1 * BIN0),
                                                                         (UInt32)(0 * BIN0));

                vsctl_spdveherrref_avehpot_2_unlim = (SInt32)VSCtl_spdVehRef_aVehPot - (SInt32)vsctl_spdveh_par;
                VSCtl_spdVehErrRef_aVehPot_2 = (UInt16)DDS_M_MAX(vsctl_spdveherrref_avehpot_2_unlim , (SInt32)(0 * BIN7));
            }
        break;

        case VSCO_F6211_GEL_2_MONTE:
            if( ((UInt32)VSCtl_bDeacHld_aVehPotReq_C == (UInt32)DDS_TRUE)                           /* Go back to PAS_GEL */                ||
                (((UInt32)vsctl_stctl_tqwhlpotmin_par != VSCO_POT_CONTROLE) && ((UInt32)vsctl_stctl_tqwhlpotmax_par != VSCO_POT_CONTROLE))  ||
                (((UInt32)copt_posnlev_par != VSCO_COPT_POSNLEV_DRIVE) && ((UInt32)DDS_FALSE != (UInt32)ext_bposngbxcf_par)
                && ((UInt32)VSCtl_bDeacPosnGBxLev_C == (UInt32)DDS_FALSE))                                                                  ||
                ((UInt32)ext_stgbxcf_par == VSCO_BVM))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);

            }

            else if(    (   ((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_POT_CONTROLE) ||                          /* Go back to GEL_INHIBITION */
                            ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_POT_CONTROLE) )    &&
                        (   ((UInt32)VSCtl_ctSIPChg_aVehPot >= (UInt32)VSCtl_ctSIPChg_aVehPot_C)    ||
                            ((UInt32)VSCtl_tiHldMax_aVehPotReq == 0)  ) )
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_INHIBITION;
                VSCtl_stHld_aVehPot = (UInt8)VSCO_ACCEL_POT_CONS_GEL_INHIBITION;
                VSCtl_bHld_aVehPotReq = DDS_FALSE;
            }

            else if((UInt32)vsctl_bavltqwhlpt_no3_par == (UInt32)DDS_FALSE)                         /* Go to GEL_1 */
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_GEL_1;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_GEL_1;
                VSCtl_bHld_aVehPotReq   = DDS_TRUE;
                VSCtl_ctSIPChg_aVehPot  = (UInt8)DDS_M_LIMITED_INCREMENT((SInt32)VSCtl_ctSIPChg_aVehPot,
                                                                                         (SInt32)(1 * BIN0),
                                                                                         (SInt32)DDS_UINT8_MAX);
            }
            else if(((UInt32)VSCtl_tiHldMin_aVehPotReq == 0)                                        /* Go to PAS_GEL */
                                &&
                    ((((UInt32)VSCtl_bDeacSpdVehErr_C == (UInt32)DDS_FALSE)
                    &&((SInt32)VSCtl_spdVehErrRef_aVehPot_2 > ((SInt32)VSCtl_spdVehErrRef_aVehPot_1 + (SInt32)VSCtl_spdVehErr_aVehPot_SlopP_C)))
                                ||
                    (((UInt32)VSCtl_bDeacAResErr_C == (UInt32)DDS_FALSE)
                    && ((DDS_M_ABS((SInt32)VSCtl_aResRef_aVehPot - (SInt32)VSCtl_aResFil)) > (SInt32)VSCtl_aResErr_aVehPot_Hys_C))
                                ||
                    (((SInt32)VSCtl_aVehPotReqRaw   <= (SInt32)vsctl_avehptmax_par)
                    && ((SInt32)VSCtl_aVehPotReqRaw >= (SInt32)vsctl_avehptmin_par))))
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);
            }
            else        /* during actions */
            {
                VSCtl_tiHldMin_aVehPotReq = (UInt16)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiHldMin_aVehPotReq,
                                                                            (UInt32)(1 * BIN0),
                                                                            (UInt32)(0 * BIN0));

                VSCtl_tiHldMax_aVehPotReq = (UInt16)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiHldMax_aVehPotReq,
                                                                            (UInt32)(1 * BIN0),
                                                                            (UInt32)(0 * BIN0));

                vsctl_spdveherrref_avehpot_2_unlim = (SInt32)VSCtl_spdVehRef_aVehPot - (SInt32)vsctl_spdveh_par;
                VSCtl_spdVehErrRef_aVehPot_2 = (UInt16)DDS_M_MAX(vsctl_spdveherrref_avehpot_2_unlim , (SInt32)(0 * BIN7));
            }
        break;

        case VSCO_F6211_GEL_INHIBITION:
            if((SInt32)VSCtl_tiNotHldMin_aVehPot <= (SInt32)(0 * BIN0))                         /* Go to PAS_GEL */
            {
                vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL;
                VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
                VSCtl_bHld_aVehPotReq   = DDS_FALSE;
                VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
                VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
                VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
                VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
                VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
                VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);
            }
            else        /* during actions */
            {
                VSCtl_tiNotHldMin_aVehPot = (UInt16)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiNotHldMin_aVehPot,
                                                                            (UInt32)(1 * BIN0),
                                                                            (UInt32)(0 * BIN0));
            }
        break;

        default:
            VSCtl_stHld_aVehPot     = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;
            VSCtl_bHld_aVehPotReq   = DDS_FALSE;
            VSCtl_spdVehRef_aVehPot = (UInt16)(0 * BIN7);
            VSCtl_aResRef_aVehPot   = (SInt16)(0 * BIN10);
            VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
            VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
            VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
            VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);
        break;
    }

    VSCtl_bAvlTqWhlPTPotPre_no3 = vsctl_bavltqwhlpt_no3_par;


}

/*******************************************************************************
*
* Function Name : VSCO_F6212_Veh_Accel_Pot_Cons_Coord
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6212_Veh_Accel_Pot_Cons_Coord(SInt16 vsctl_avehpotvsregreq_par,
                                                                 SInt16 vsctl_avehpotvslimreq_par,
                                                                 SInt16 vsctl_avehpotdvsregreq_par,
                                                                 SInt16 vsctl_avehpotvsmaxreq_par,
                                                                 SInt16 vsctl_avehptpotmax_par,
                                                                 SInt16 vsctl_avehptpotmin_par,
                                                                 UInt8  ext_stdvsregcf_par,
                                                                 UInt8  ext_bvslimcf_par,
                                                                 UInt8  ext_bvsmaxfcf_par,
                                                                 UInt8  ext_bvsmaxpcf_par,
                                                                 UInt8  ext_bvsmaxscf_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.24.1 */

    if (VSCO_ARRET == (UInt32)VSCtl_stCtl_aVehPot)
    {
        VSCtl_aVehPotReqRaw     = VSCO_ACCEL_POT_CONS_0_BIN10;
        VSCtl_aVehPotMinReq     = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
        VSCtl_aVehPotReq        = VSCO_ACCEL_POT_CONS_0_BIN10;
        VSCtl_aVehPotMaxReq     = VSCO_ACCEL_POT_CONS_10_BIN10_POS;
    }
    else
    {
        VSCO_F6212_Sat_Output_Calc(vsctl_avehptpotmax_par,
                                   vsctl_avehptpotmin_par,
                                   ext_stdvsregcf_par,
                                   vsctl_avehpotvsregreq_par,
                                   vsctl_avehpotdvsregreq_par,
                                   ext_bvslimcf_par,
                                   vsctl_avehpotvslimreq_par,
                                   ext_bvsmaxfcf_par,
                                   ext_bvsmaxpcf_par,
                                   ext_bvsmaxscf_par,
                                   vsctl_avehpotvsmaxreq_par);


        VSCtl_aVehPotReqRaw = (SInt16)DDS_M_MIN(f6212_sat_out_max,f6212_sat_out_min);

        if((UInt32)DDS_FALSE != (UInt32)VSCtl_bHld_aVehPotReq)
        {
            VSCtl_aVehPotMinReq = vsctl_avehpotminreq_prev;
            VSCtl_aVehPotReq    = vsctl_avehpotreq_prev;
            VSCtl_aVehPotMaxReq = vsctl_avehpotmaxreq_prev;
        }
        else
        {
            VSCtl_aVehPotMinReq = (SInt16)f6212_sat_out_max;
            VSCtl_aVehPotReq    = VSCtl_aVehPotReqRaw;
            VSCtl_aVehPotMaxReq = (SInt16)f6212_sat_out_min;
        }
    }

    vsctl_avehpotminreq_prev    = VSCtl_aVehPotMinReq;
    vsctl_avehpotreq_prev       = VSCtl_aVehPotReq;
    vsctl_avehpotmaxreq_prev    = VSCtl_aVehPotMaxReq;

}

/*******************************************************************************
*
* Function Name : VSCO_F6213_Veh_Accel_Pot_Res_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6213_Veh_Accel_Pot_Res_Deter(SInt16 vsctl_ares_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.25.1 */

    SInt16 vsctl_avehrsv_hyshi_unlim;
    SInt16 vsctl_avehrsv_hyslo_unlim;

    if(VSCO_ARRET == (UInt32)VSCtl_stCtl_aVehPot)
    {
        VSCtl_aVehRsv_HysHi = (UInt16)VSCO_ACCEL_POT_CONS_0_BIN10;
        VSCtl_aVehRsv_HysLo = (UInt16)VSCO_ACCEL_POT_CONS_0_BIN10;
    }
    else
    {
        vsctl_avehrsv_hyshi_unlim = DDS_M_MAP2D_S16(&VSCTL_AVEHRSVHYSHI_ARES_T_APM,         /* [-10;10]BIN10 */
                                                    vsctl_ares_par);

        VSCtl_aVehRsv_HysHi = (UInt16)DDS_M_MAX((SInt32)vsctl_avehrsv_hyshi_unlim,          /* [0;10]BIN10 */
                                              (SInt32)VSCO_ACCEL_POT_CONS_0_BIN10);


        vsctl_avehrsv_hyslo_unlim = DDS_M_MAP2D_S16(&VSCTL_AVEHRSVHYSLO_ARES_T_APM,         /* [-10;10]BIN10 */
                                                    vsctl_ares_par);


        VSCtl_aVehRsv_HysLo = (UInt16)DDS_M_MAX((SInt32)vsctl_avehrsv_hyslo_unlim,          /* [0;10]BIN10 */
                                                (SInt32)VSCO_ACCEL_POT_CONS_0_BIN10);
    }
}


/*******************************************************************************
*
* Function Name : VSCO_F6214_Filtering_Resist_Accel_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6214_Filtering_Resist_Accel_Deter(SInt16 vsctl_ares_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.45.0 */


    SInt16 f6214_filter_out;


    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_aVehPot)
    {
        f6214_filter_out = DDS_M_FILTER_LP1_S16_INIT(&f6214_low_pass_t_struct,
                                                      vsctl_ares_par);
    }
    else
    {
        f6214_filter_out = DDS_M_FILTER_LP1_S16(&f6214_low_pass_t_struct,
                                                 vsctl_ares_par,
                                                 VSCtl_tiFil_aVehPotReq_C,
                                                 DEC3);
    }

    if(VSCO_ARRET == (UInt32)VSCtl_stCtl_aVehPot)
    {
        VSCtl_aResFil = VSCO_ACCEL_POT_CONS_0_BIN10;
    }
    else
    {
        VSCtl_aResFil = f6214_filter_out;
    }

}



/*******************************************************************************
*
* Function Name : VSCO_F6212_Sat_Output_Calc
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6212_Sat_Output_Calc(SInt16 vsctl_avehptpotmax_par,
                                                        SInt16 vsctl_avehptpotmin_par,
                                                        UInt8  ext_stdvsregcf_par,
                                                        SInt16 vsctl_avehpotvsregreq_par,
                                                        SInt16 vsctl_avehpotdvsregreq_par,
                                                        UInt8  ext_bvslimcf_par,
                                                        SInt16 vsctl_avehpotvslimreq_par,
                                                        UInt8  ext_bvsmaxfcf_par,
                                                        UInt8  ext_bvsmaxpcf_par,
                                                        UInt8  ext_bvsmaxscf_par,
                                                        SInt16 vsctl_avehpotvsmaxreq_par)

{
    SInt16 f6212_sat_input_1,f6212_sat_input_2,f6212_sat_input_3,f6212_sat_input_4;
    SInt32 f6212_sat_out_1,f6212_sat_out_2,f6212_sat_out_3,f6212_sat_out_4;


    /* f6212_sat_input_1  & f6212_sat_input_2 calc */
    if(VSCO_ABSENTE == (UInt32)ext_stdvsregcf_par)
    {
        f6212_sat_input_1 = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
        f6212_sat_input_2 = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
    }
    else if(VSCO_RVV_PRESENTE == (UInt32)ext_stdvsregcf_par)
    {
        f6212_sat_input_1 = vsctl_avehpotvsregreq_par;
        f6212_sat_input_2 = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
    }
    else
    {
        f6212_sat_input_1 = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
        f6212_sat_input_2 = vsctl_avehpotdvsregreq_par;
    }


    /* f6212_sat_input_3 calc */
    if((UInt32)DDS_FALSE == (UInt32)ext_bvslimcf_par)
    {
        f6212_sat_input_3 = VSCO_ACCEL_POT_CONS_10_BIN10_POS;
    }
    else
    {
        f6212_sat_input_3 = vsctl_avehpotvslimreq_par;
    }

    /* f6212_sat_input_4 calc */
    if((UInt32)DDS_FALSE != (UInt32)ext_bvsmaxfcf_par)
    {
        f6212_sat_input_4 = vsctl_avehpotvsmaxreq_par;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)ext_bvsmaxpcf_par)
        {
            f6212_sat_input_4 = vsctl_avehpotvsmaxreq_par;
        }
        else
        {
            if((UInt32)DDS_FALSE != (UInt32)ext_bvsmaxscf_par)
            {
                f6212_sat_input_4 = vsctl_avehpotvsmaxreq_par;
            }
            else
            {
                f6212_sat_input_4 = VSCO_ACCEL_POT_CONS_10_BIN10_POS;
            }
        }
    }

    /* [-10;10]BIN10 */
    f6212_sat_out_1 = DDS_M_SATURATION_V2((SInt32)f6212_sat_input_1,(SInt32)vsctl_avehptpotmin_par,(SInt32)vsctl_avehptpotmax_par);
    f6212_sat_out_2 = DDS_M_SATURATION_V2((SInt32)f6212_sat_input_2,(SInt32)vsctl_avehptpotmin_par,(SInt32)vsctl_avehptpotmax_par);
    f6212_sat_out_3 = DDS_M_SATURATION_V2((SInt32)f6212_sat_input_3,(SInt32)vsctl_avehptpotmin_par,(SInt32)vsctl_avehptpotmax_par);
    f6212_sat_out_4 = DDS_M_SATURATION_V2((SInt32)f6212_sat_input_4,(SInt32)vsctl_avehptpotmin_par,(SInt32)vsctl_avehptpotmax_par);


    f6212_sat_out_max = DDS_M_MAX(f6212_sat_out_1,f6212_sat_out_2);
    f6212_sat_out_min = DDS_M_MIN(f6212_sat_out_3,f6212_sat_out_4);



}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_Veh_Acc_Pot_Act_Cons_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Veh_Acc_Pot_Act_Cons_Init(void)
{

    /* VSCO_F6211_Veh_Accel_Pot_Cons_Calc_Mode_Deter */
    VSCtl_bHld_aVehPotReq           = DDS_FALSE;
    VSCtl_stCtl_aVehPot             = (UInt8)VSCO_ARRET;
    VSCtl_bAcvFil_aVehPot           = DDS_FALSE;
    VSCtl_tiHldMin_aVehPotReq       = VSCtl_tiHldMin_aVehPotReq_C;
    VSCtl_ctSIPChg_aVehPot          = VSCtl_ctSIPChg_aVehPot_C;
    VSCtl_spdVehRef_aVehPot         = (UInt16)(0 * BIN7);
    VSCtl_aResRef_aVehPot           = (SInt16)(0 * BIN10);
    VSCtl_tiNotHldMin_aVehPot       = VSCtl_tiNotHldMin_aVehPot_C;
    VSCtl_tiHldMax_aVehPotReq       = VSCtl_tiHldMax_aVehPotReq_C;
    VSCtl_spdVehErrRef_aVehPot_1    = (UInt16)(0 * BIN7);
    VSCtl_spdVehErrRef_aVehPot_2    = (UInt16)(0 * BIN7);
    VSCtl_bAvlTqWhlPTPotPre_no3 = DDS_FALSE;
    VSCtl_stHld_aVehPot             = (UInt8)VSCO_ACCEL_POT_CONS_PAS_GEL;

    vsco_f6211_mode_calcul_consignes_potentiel_acceleration_vehicule_global = DDS_FALSE ;
    vsco_f6211_mode_gel_consignes_potentiel_acceleration_vehicule = (UInt8)VSCO_F6211_PAS_GEL ;


    /* VSCO_F6212_Veh_Accel_Pot_Cons_Coord */
    VSCtl_aVehPotMaxReq             = VSCO_ACCEL_POT_CONS_10_BIN10_POS;
    VSCtl_aVehPotMinReq             = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
    VSCtl_aVehPotReq                = VSCO_ACCEL_POT_CONS_0_BIN10;
    VSCtl_aVehPotReqRaw             = VSCO_ACCEL_POT_CONS_0_BIN10;

    vsctl_avehpotminreq_prev        = VSCO_ACCEL_POT_CONS_10_BIN10_NEG;
    vsctl_avehpotreq_prev           = VSCO_ACCEL_POT_CONS_0_BIN10;
    vsctl_avehpotmaxreq_prev        = VSCO_ACCEL_POT_CONS_10_BIN10_POS;

    /* VSCO_F6213_Veh_Accel_Pot_Res_Deter */
    VSCtl_aVehRsv_HysLo             = (UInt16)VSCO_ACCEL_POT_CONS_0_BIN10;
    VSCtl_aVehRsv_HysHi             = (UInt16)VSCO_ACCEL_POT_CONS_0_BIN10;

    /* VSCO_F6214_Filtering_Resist_Accel_Deter */
    VSCtl_aResFil                   = VSCO_ACCEL_POT_CONS_0_BIN10;
    (void)DDS_M_FILTER_LP1_S16_INIT(&f6214_low_pass_t_struct, 0);

    /* VSCO_F6212_Sat_Output_Calc */

}



#define VSCO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSCo_MemMap.h"

