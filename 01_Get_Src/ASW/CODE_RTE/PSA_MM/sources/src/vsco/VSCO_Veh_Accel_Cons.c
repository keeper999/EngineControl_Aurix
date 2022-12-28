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
* Ref X:\integration_view_00PSASWC_D721D01\blois_psa_sstg\Software\Appli\VSCo\src\VSCO_Veh_Accel_Cons.c
* Version int :/main/L04_01/1 Date: 12/4/2012 13 h 55 m User:esnault 
*    TWK_model:VSCO_Veh_Accel_Cons_L04_010_IMPL1
*    comments :for VSCo 12.1
* Version dev :\main\branch_morisseau_vsco_euro6\1 Date: 3/4/2012 17 h 11 m User:morisseau 
*    TWK_model:VSCO_Veh_Accel_Cons_L04_010_IMPL1
*    comments :for VSCo 12.1
* Version int :/main/L03_01/1 Date: 10/1/2012 8 h 34 m User:meme
*    TWK_model:VSCO_Veh_Accel_Cons_L03_010_IMPL2
*    comments :for VSco_12_0
* Version int :/main/L02_01/3 Date: 26/9/2011 9 h 51 m User:esnault
*    TWK_model:VSCO_Veh_Accel_Cons_L02_011_IMPL1
*    comments :for FDS A0203143
* Version int :/main/L02_01/2 Date: 13/9/2011 12 h 8 m User:esnault
*    TWK_model:VSCO_Veh_Accel_Cons_L02_011_IMPL1
*    comments :for VSCo 11.1 : rename VSCtl_stTqWhlPTCutOffReqPrev to VSCtl_stTqWhlCutOffReqPrev
* Version int :/main/L02_01/1 Date: 6/9/2011 15 h 42 m User:meme
*    TWK_model:VSCO_Veh_Accel_Cons_L02_010_IMPL1
*    comments :For VSCo_11.0_e6
* Version int :/main/L01_01/3 Date: 11/5/2011 8 h 41 m User:meme
*    TWK_model:VSCO_Veh_Accel_Cons_L01_010_IMPL2_D
*    comments :FDS A0201586 / ALTIS 1588481
* Version int :/main/L01_01/2 Date: 24/2/2011 10 h 21 m User:esnault
*    TWK_model:VSCO_Veh_Accel_Cons_L01_010_IMPL2
*    comments :For VSCo 10.0 (Correction after TU)
* Version int :/main/L01_01/1 Date: 4/2/2011 17 h 29 m User:esnault
*    TWK_model:VSCO_Veh_Accel_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
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
#include "SC.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

/* VSCtl_stCtl_TqWhlCutOff_aVeh
   VSCtl_stTqWhlPTCutOffReq       */
#define VSCO_ACCEL_CONS_ARRET           (UInt32)0
#define VSCO_ACCEL_CONS_PILOTABLE_H     (UInt32)1
#define VSCO_ACCEL_CONS_PILOTABLE_B     (UInt32)2


/* stateflow vsco_f6111_mode_calcul_consignes_acceleration_vehicule_global */
#define VSCO_F6111_FAUX     (UInt32)0
#define VSCO_F6111_VRAI     (UInt32)1

/* stateflow vsco_f6111_mode_gel_consignes_acceleration_vehicule */
#define VSCO_F6111_ARRET        (UInt32)0
#define VSCO_F6111_GEL          (UInt32)1
#define VSCO_F6111_GEL_INHIBE   (UInt32)2

/* stateflow vsco_f6115_attribution_effectivite_couples_moteur_couples_roue */
#define VSCO_F6115_NON_ATTRIBUEE    (UInt32)0
#define VSCO_F6115_COUPLE_ROUE      (UInt32)1
#define VSCO_F6115_COUPLE_MOTEUR    (UInt32)2



#define VSCO_ACCEL_CONS_10_BIN10_NEG    (SInt16)(-10 * BIN10)
#define VSCO_ACCEL_CONS_10_BIN10_POS    (SInt16)(10 * BIN10)
#define VSCO_ACCEL_CONS_0_BIN10         (SInt16)(0 * BIN10)

#define VSCO_ACCEL_CONS_0_BIN7          (SInt16)(0 * BIN7)

#define VSCO_ACCEL_CONS_100_BIN7_NEG    (SInt32)(-100 * BIN7)
#define VSCO_ACCEL_CONS_100_BIN7_POS    (SInt32)(100 * BIN7)

#define VSCO_ACCEL_CONS_10_BIN7_NEG     (SInt32)(-10 * BIN7)
#define VSCO_ACCEL_CONS_10_BIN7_POS     (SInt32)(10 * BIN7)




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

/* 16-bits variables definition */
#define VSCO_START_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_aVehWhlMinSat; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehMinReq; /* BIN10 */
VAR(SInt16, AUTOMATIC) VSCtl_aVehMaxReq; /* BIN10 */
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variables definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdDVSRegInt_aVeh;
VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSRegInt_aVeh;
VAR(UInt8, AUTOMATIC) VSCtl_stCtlaVehMinSat; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_stCtl_aVeh;
VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVehMin;
VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVehMax;
VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqMax;
#define VSCO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 8-bits scalar calibration definition */
#define VSCO_START_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacSatCordVSRegReq_C    = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) VSCtl_tiFil_jrkVehReq_C         = (CONST(UInt8, AUTOMATIC))(0.2890625 * BIN7);
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacHld_aVehReq_C        = DDS_TRUE;
#define VSCO_STOP_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"


/* 16-bits scalar calibration definition */
#define VSCO_START_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) VSCtl_tiNotHldMin_aVehReq_C     = (CONST(UInt16, AUTOMATIC))(199 * BIN0);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHldMax_aVehReq_C        = (CONST(UInt16, AUTOMATIC))(199 * BIN0);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehHldaVehReqHysHi_C   = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehHldaVehReqHysLo_C   = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSReg_HysHi_C  = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSReg_HysLo_C  = (CONST(SInt16, AUTOMATIC))(-0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVhEDrvOvdDVSReg_HysHi_C  = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVhEDrvOvdDVSReg_HysLo_C  = (CONST(SInt16, AUTOMATIC))(-0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSLim_HysHi_C  = (CONST(SInt16, AUTOMATIC))(0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSLim_HysLo_C  = (CONST(SInt16, AUTOMATIC))(-0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSMax_HysHi_C  = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSMax_HysLo_C  = (CONST(SInt16, AUTOMATIC))(-0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSReg_HysHi2_C = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehEDrvOvdVSReg_HysLo2_C = (CONST(SInt16, AUTOMATIC))(-0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVhEDrvOvdDVSReg_HysHi2_C = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) VSCtl_aVhEDrvOvdDVSReg_HysLo2_C = (CONST(SInt16, AUTOMATIC))(-0.046875 * BIN10);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFilStCtlAVehMinSat_C    = (CONST(UInt16, AUTOMATIC))(299 * BIN0);
#define VSCO_STOP_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"




/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSCO_START_SEC_CARTO_16BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_jrkVehTranLim_aVehReq_T
[VSC_8_SIZE] = {
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7),
(SInt16)(-3 * BIN7), (SInt16)(-3 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehReq_jrkVehTranLim_A[VSC_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0.1015625 * BIN10), (SInt16)(0.203125 * BIN10),
(SInt16)(0.296875 * BIN10), (SInt16)(0.3984375 * BIN10),
(SInt16)(0.5 * BIN10), (SInt16)(0.6015625 * BIN10),
(SInt16)(0.703125 * BIN10)
};

#define VSCO_STOP_SEC_CARTO_16BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/


/* 8-bits variable definition */
#define VSCO_START_SEC_VAR_8BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsco_f6111_mode_calcul_consignes_acceleration_vehicule_global;
STATIC VAR(UInt8, AUTOMATIC) vsco_f6111_mode_gel_consignes_acceleration_vehicule;
STATIC VAR(UInt8, AUTOMATIC) vsco_f6115_attribution_effectivite_couples_moteur_couples_roue;
#define VSCO_STOP_SEC_VAR_8BIT
#include "VSCo_MemMap.h"


/* 16-bits variable definition */
#define VSCO_START_SEC_VAR_16BIT
#include "VSCo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehmaxreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehminreq_prev;
STATIC VAR(SInt16, AUTOMATIC) f6112_max_input_1;
STATIC VAR(SInt16, AUTOMATIC) f6112_max_input_2;
STATIC VAR(SInt16, AUTOMATIC) f6112_min_input;
STATIC VAR(SInt16, AUTOMATIC) f6112_max_output;
STATIC VAR(SInt16, AUTOMATIC) f6112_min_input_2;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreq_prev_1;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreq_prev_2;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreq_prev_3;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreq_prev_4;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehwhlminsat_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehcordvsregreq_calc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehcordvslimreq_calc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehreq_calc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehmaxreq_calc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehminreq_calc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreq_calc;
#define VSCO_STOP_SEC_VAR_16BIT
#include "VSCo_MemMap.h"


/* 32-bits variable definition */
#define VSCO_START_SEC_VAR_32BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsctl_bdrvovrdvsreg_aveh_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bdrvovrddvsreg_aveh_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bdrvovrdvslim_aveh_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bdrvovrdvsmax_aveh_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bendtranvsreg_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bendtranvslim_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bendtranvsmax_local;
#define VSCO_STOP_SEC_VAR_32BIT
#include "VSCo_MemMap.h"


/* Complex variable definition */
#define VSCO_START_SEC_VAR_UNSPECIFIED
#include "VSCo_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_jrkvehtranlim_avehreq_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) f6111_low_pass_t_struct;
#define VSCO_STOP_SEC_VAR_UNSPECIFIED
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiNotHldMin_aVehReq; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHldMax_aVehReq; /* BIN0 */
/* <PRQA_COMMENT><3229> variable calculated but not used in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehReq; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPreCoVSCtlReqSat; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehCordVSRegReqSat; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehCordVSLimReqSat; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSRegReqSat; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSLimReqSat; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehDVSRegReqSat; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehVSMaxReqSat; /* BIN10 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiFilStCtlAVehMinSat; /* BIN0 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehWhlMinSat; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehWhlMinSatRaw1; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_jrkVehWhlMinSatRaw2; /* BIN7 */
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVeh;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiHld_stCtl_aVehCutOff; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stTqWhlCutOffReqPrev; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTPrev_no3;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stCtl_TqWhlCutOff_aVeh; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bHld_aVehReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqMin;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcv_aVehMinSat;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_aVeh;
#define VSCO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSCO_START_SEC_CONST_UNSPECIFIED
#include "VSCo_MemMap.h"
STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_JRKVEHTRANLIM_AVEHREQ_T_APM = {
&vsctl_jrkvehtranlim_avehreq_t_sav,
VSC_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehReq_jrkVehTranLim_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_jrkVehTranLim_aVehReq_T[0]
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


STATIC FUNC(void, AUTOMATIC) VSCO_F6111_Veh_Accel_Cmd_Mode_Deter(UInt8  vsctl_stvsctlinfo_par,
                                                                 UInt8  vsctl_bavltqwhlpt_no3_par,
                                                                 UInt8  ext_stgbxcf_par,
                                                                 UInt8  copt_posnlev_par,
                                                                 UInt16 vsctl_spdveh_par,
                                                                 UInt8  vsctl_sttqwhlptcutoffreq_par,
                                                                 UInt8 ext_bposngbxcf_par);

STATIC FUNC(void, AUTOMATIC) VSCO_F6112_Veh_Accel_Cons_Coord(SInt16 vsctl_avehptmax_par,
                                                             SInt16 vsctl_avehptmin_par,
                                                             SInt16 vsctl_avehprecovsctlreq_par,
                                                             SInt16 vsctl_avehdvsregreq_par,
                                                             SInt16 vsctl_avehvsregreq_par,
                                                             SInt16 vsctl_avehvslimreq_par,
                                                             SInt16 vsctl_avehvsmaxreq_par,
                                                             UInt8  ext_stdvsregcf_par,
                                                             UInt8  ext_bvslimcf_par,
                                                             UInt8  ext_bvsmaxfcf_par,
                                                             UInt8  ext_bvsmaxpcf_par,
                                                             UInt8  ext_bvsmaxscf_par,
                                                             SInt16 vsctl_avehptmaxnotctla_par,
                                                             SInt16 vsctl_avehptminnotctla_par,
                                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehreq_ptr,
                                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehcordvsregreq_ptr,
                                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehcordvslimreq_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F61121_VSCtl_aVehCordVSRegReq_Calc(void);


STATIC FUNC(void, AUTOMATIC) VSCO_F61122_VSCtl_aVeh_Calc(SInt16 vsctl_avehptmax_par,
                                                         SInt16 vsctl_avehptmin_par,
                                                         SInt16 vsctl_avehptmaxnotctla_par,
                                                         SInt16 vsctl_avehptminnotctla_par);

STATIC FUNC(void, AUTOMATIC) VSCO_F61123_VSCtl_jrkVehReq(void);


STATIC FUNC(void, AUTOMATIC) VSCO_F6113_Sat_Veh_Accel_Cons_Deter(SInt16 vsctl_avehptmax_par,
                                                                 SInt16 vsctl_avehptmin_par,
                                                                 SInt16 vsctl_avehprecovsctlreq_par,
                                                                 SInt16 vsctl_avehdvsregreq_par,
                                                                 SInt16 vsctl_avehvsregreq_par,
                                                                 SInt16 vsctl_avehvslimreq_par,
                                                                 SInt16 vsctl_avehvsmaxreq_par,
                                                                 SInt16 vsctl_avehcordvsregreq_par,
                                                                 SInt16 vsctl_avehcordvslimreq_par);


STATIC FUNC(void, AUTOMATIC) VSCO_F6114_Veh_Accel_Cons_Effec_Deter(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrdvsreg_aveh_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrddvsreg_aveh_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrdvslim_aveh_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrdvsmax_aveh_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F6115_Veh_Accel_Cons_Trans_End_Deter(UInt8 vsctl_bctlefc_tqwhlptmin_par,
                                                                       UInt8 vsctl_bctlefc_tqwhlptmax_par,
                                                                       UInt8 vsctl_bctlefc_tqckefcmin_par,
                                                                       UInt8 vsctl_bctlefc_tqckefcmax_par,
                                                                       SInt16 vsctl_avehvsregreq_par,
                                                                       SInt16 vsctl_avehvslimreq_par,
                                                                       SInt16 vsctl_avehvsmaxreq_par,
                                                                       SInt16 vsctl_avehprecovsctlreq_par,
                                                                       SInt16 vsctl_avehcordvsregreq_par,
                                                                       SInt16 vsctl_avehcordvslimreq_par,
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bendtranvsreg_ptr,
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bendtranvslim_ptr,
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bendtranvsmax_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F6116_Min_Veh_Accel_Lim_Cons_Deter(UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
                                                                     SInt16 vsctl_avehptlim_par,
                                                                     SInt16 vsctl_avehreq_par,
                                                                     SInt16 vsctl_avehptdrvminreq_par,
                                                                     SInt16 vsctl_avehptdrvminreqraw_par,
                                                                     UInt8 vsctl_stctl_tqwhlmax_par,
                                                                     UInt8 vsctl_stctl_tqwhlmin_par,
                                                                     UInt8 vsctl_bdrvovrdvsmax_aveh_par,
                                                                     UInt8 vsctl_bdrvovrdvslim_aveh_par);

STATIC FUNC(void, AUTOMATIC) VSCO_F61161_Min_Veh_Accel_Lim_Com_Mode_Deter(UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
                                                                          SInt16 vsctl_avehptlim_par,
                                                                          SInt16 vsctl_avehreq_par,
                                                                          SInt16 vsctl_avehptdrvminreq_par,
                                                                          SInt16 vsctl_avehptdrvminreqraw_par,
                                                                          UInt8 vsctl_stctl_tqwhlmax_par,
                                                                          UInt8 vsctl_stctl_tqwhlmin_par,
                                                                          UInt8 vsctl_bdrvovrdvsmax_aveh_par,
                                                                          UInt8 vsctl_bdrvovrdvslim_aveh_par);


STATIC FUNC(void, AUTOMATIC) VSCO_F61162_Min_Veh_Accel_Lim_Cons_Deter(SInt16 vsctl_avehptlim_par,
                                                                      SInt16 vsctl_avehreq_par,
                                                                      SInt16 vsctl_avehptdrvminreq_par,
                                                                      SInt16 vsctl_avehptdrvminreqraw_par);

/*******************************************************************************
*
* Function Name : VSCO_Veh_Accel_Cons
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Veh_Accel_Cons(UInt8 VSCtl_stTqWhlPTCutOffReq_swc_in,
                                           UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                           UInt8 CoPt_posnLev_swc_in,
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 VSCtl_bAvlTqWhlPT_no3_swc_in,
                                           UInt8 VSCtl_stVSCtlInfo_swc_in,
                                           SInt16 VSCtl_aVehPTMinNotCtla_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehPTMaxNotCtla_swc_in, /* BIN10 */
                                           UInt8 Ext_bVSLimCf_swc_in,
                                           UInt8 Ext_bVSMaxfCf_swc_in,
                                           UInt8 Ext_bVSMaxpCf_swc_in,
                                           UInt8 Ext_bVSMaxsCf_swc_in,
                                           UInt8 Ext_stDVSRegCf_swc_in,
                                           SInt16 VSCtl_aVehPreCoVSCtlReq_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehVSLimReq_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehVSMaxReq_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehVSRegReq_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehDVSRegReq_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehPTMax_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehPTMin_swc_in, /* BIN10 */
                                           UInt8 VSCtl_bCtlEfc_tqCkEfcMax_swc_in,
                                           UInt8 VSCtl_bCtlEfc_tqCkEfcMin_swc_in,
                                           UInt8 VSCtl_bCtlEfc_tqWhlPTMax_swc_in,
                                           UInt8 VSCtl_bCtlEfc_tqWhlPTMin_swc_in,
                                           SInt16 VSCtl_aVehPTLim_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehPTDrvMinReq_swc_in, /* BIN10 */
                                           SInt16 VSCtl_aVehPTDrvMinReqRaw_swc_in, /* BIN10 */
                                           UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                                           UInt8 VSCtl_stCtl_tqWhlMax_swc_in,
                                           UInt8 VSCtl_stCtl_tqWhlMin_swc_in,
                                           UInt8 Ext_bPosnGBxCf_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehReq_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSLimReq_swc_out, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSRegReq_swc_out, /* BIN10 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSReg_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSLim_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSMax_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdDVSReg_aVeh_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSLim_aVeh_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSMax_aVeh_swc_out)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.03.4 */

    VSCO_F6111_Veh_Accel_Cmd_Mode_Deter(VSCtl_stVSCtlInfo_swc_in,
                                        VSCtl_bAvlTqWhlPT_no3_swc_in,
                                        Ext_stGBxCf_swc_in,
                                        CoPt_posnLev_swc_in,
                                        VSCtl_spdVeh_swc_in,
                                        VSCtl_stTqWhlPTCutOffReq_swc_in,
                                        Ext_bPosnGBxCf_swc_in);



    VSCO_F6112_Veh_Accel_Cons_Coord(VSCtl_aVehPTMax_swc_in,
                                    VSCtl_aVehPTMin_swc_in,
                                    VSCtl_aVehPreCoVSCtlReq_swc_in,
                                    VSCtl_aVehDVSRegReq_swc_in,
                                    VSCtl_aVehVSRegReq_swc_in,
                                    VSCtl_aVehVSLimReq_swc_in,
                                    VSCtl_aVehVSMaxReq_swc_in,
                                    Ext_stDVSRegCf_swc_in,
                                    Ext_bVSLimCf_swc_in,
                                    Ext_bVSMaxfCf_swc_in,
                                    Ext_bVSMaxpCf_swc_in,
                                    Ext_bVSMaxsCf_swc_in,
                                    VSCtl_aVehPTMaxNotCtla_swc_in,
                                    VSCtl_aVehPTMinNotCtla_swc_in,
                                    VSCtl_aVehReq_swc_out,
                                    VSCtl_aVehCordVSRegReq_swc_out,
                                    VSCtl_aVehCordVSLimReq_swc_out);


    VSCO_F6113_Sat_Veh_Accel_Cons_Deter(VSCtl_aVehPTMax_swc_in,
                                        VSCtl_aVehPTMin_swc_in,
                                        VSCtl_aVehPreCoVSCtlReq_swc_in,
                                        VSCtl_aVehDVSRegReq_swc_in,
                                        VSCtl_aVehVSRegReq_swc_in,
                                        VSCtl_aVehVSLimReq_swc_in,
                                        VSCtl_aVehVSMaxReq_swc_in,
                                        *VSCtl_aVehCordVSRegReq_swc_out,
                                        *VSCtl_aVehCordVSLimReq_swc_out);


    VSCO_F6114_Veh_Accel_Cons_Effec_Deter(VSCtl_bDrvOvrdVSReg_aVeh_swc_out,
                                          VSCtl_bDrvOvrdDVSReg_aVeh_swc_out,
                                          VSCtl_bDrvOvrdVSLim_aVeh_swc_out,
                                          VSCtl_bDrvOvrdVSMax_aVeh_swc_out);


    VSCO_F6115_Veh_Accel_Cons_Trans_End_Deter(VSCtl_bCtlEfc_tqWhlPTMin_swc_in,
                                              VSCtl_bCtlEfc_tqWhlPTMax_swc_in,
                                              VSCtl_bCtlEfc_tqCkEfcMin_swc_in,
                                              VSCtl_bCtlEfc_tqCkEfcMax_swc_in,
                                              VSCtl_aVehVSRegReq_swc_in,
                                              VSCtl_aVehVSLimReq_swc_in,
                                              VSCtl_aVehVSMaxReq_swc_in,
                                              VSCtl_aVehPreCoVSCtlReq_swc_in,
                                              *VSCtl_aVehCordVSRegReq_swc_out,
                                              *VSCtl_aVehCordVSLimReq_swc_out,
                                              VSCtl_bEndTranVSReg_swc_out,
                                              VSCtl_bEndTranVSLim_swc_out,
                                              VSCtl_bEndTranVSMax_swc_out);

    VSCO_F6116_Min_Veh_Accel_Lim_Cons_Deter(VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
                                            VSCtl_aVehPTLim_swc_in,
                                            *VSCtl_aVehReq_swc_out,
                                            VSCtl_aVehPTDrvMinReq_swc_in,
                                            VSCtl_aVehPTDrvMinReqRaw_swc_in,
                                            VSCtl_stCtl_tqWhlMax_swc_in,
                                            VSCtl_stCtl_tqWhlMin_swc_in,
                                            *VSCtl_bDrvOvrdVSMax_aVeh_swc_out,
                                            *VSCtl_bDrvOvrdVSLim_aVeh_swc_out);






}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_F6111_Veh_Accel_Cmd_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6111_Veh_Accel_Cmd_Mode_Deter(UInt8  vsctl_stvsctlinfo_par,
                                                                 UInt8  vsctl_bavltqwhlpt_no3_par,
                                                                 UInt8  ext_stgbxcf_par,
                                                                 UInt8  copt_posnlev_par,
                                                                 UInt16 vsctl_spdveh_par,
                                                                 UInt8  vsctl_sttqwhlptcutoffreq_par,
                                                                 UInt8  ext_bposngbxcf_par )
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.36.2 */


    /* MODE_CALCUL_CONSIGNES_ACCELERATION_VEHICULE_GLOBAL */

    switch((UInt32)vsco_f6111_mode_calcul_consignes_acceleration_vehicule_global)
    {
        case VSCO_F6111_FAUX:
            if( VSCO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par )
            {
                vsco_f6111_mode_calcul_consignes_acceleration_vehicule_global = (UInt8)VSCO_F6111_VRAI;
                VSCtl_stCtl_aVeh    = (UInt8)VSCO_CONTROLE;
                VSCtl_bAcvFil_aVeh  = DDS_TRUE;

            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F6111_VRAI:
            if( VSCO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par )
            {
                vsco_f6111_mode_calcul_consignes_acceleration_vehicule_global = (UInt8)VSCO_F6111_FAUX;
                VSCtl_stCtl_aVeh    = (UInt8)VSCO_ARRET;
                VSCtl_bAcvFil_aVeh  = DDS_FALSE;

            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_stCtl_aVeh    = (UInt8)VSCO_ARRET;
            VSCtl_bAcvFil_aVeh  = DDS_FALSE;
        break;

    }


    /* MODE_GEL_CONSIGNES_ACCELERATION_VEHICULE */

    switch((UInt32)vsco_f6111_mode_gel_consignes_acceleration_vehicule)
    {
        case VSCO_F6111_ARRET:
            if(  ((UInt32)VSCtl_bDeacHld_aVehReq_C == (UInt32)DDS_FALSE)
               &&(  ((UInt32)VSCtl_bCtlCmdPTTqCf_SC == (UInt32)DDS_FALSE)
                  ||((UInt32)vsctl_spdveh_par >= (UInt32)VSCtl_spdVehHldaVehReqHysHi_C))
               &&((UInt32)VSCtl_bCtlEfc_aVeh          == VSCO_EFFECTIF)
               &&((UInt32)VSCtl_stCtl_aVeh            == VSCO_CONTROLE)
               &&(  ((UInt32)copt_posnlev_par          == VSCO_COPT_POSNLEV_DRIVE)
                  ||((UInt32)DDS_FALSE == (UInt32)ext_bposngbxcf_par ))
               &&((UInt32)ext_stgbxcf_par             != VSCO_BVM)
               &&((UInt32)vsctl_bavltqwhlpt_no3_par   == (UInt32)DDS_FALSE)
               &&((UInt32)VSCtl_bAvlTqWhlPTPrev_no3   == (UInt32)DDS_TRUE))
            {
                vsco_f6111_mode_gel_consignes_acceleration_vehicule = (UInt8)VSCO_F6111_GEL;
                VSCtl_bHld_aVehReq = DDS_TRUE;
            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F6111_GEL:
            if( ((UInt32)VSCtl_tiHldMax_aVehReq     == (UInt32)(0 * BIN0))      ||
                ((UInt32)vsctl_bavltqwhlpt_no3_par  == (UInt32)DDS_TRUE))
            {
                vsco_f6111_mode_gel_consignes_acceleration_vehicule = (UInt8)VSCO_F6111_GEL_INHIBE;
                VSCtl_bHld_aVehReq = DDS_FALSE;
            }

            else if(
                ((UInt32)VSCtl_bDeacHld_aVehReq_C == (UInt32)DDS_TRUE)                                                                              ||
                (((UInt32)VSCtl_bCtlCmdPTTqCf_SC != (UInt32)DDS_FALSE) && ((UInt32)vsctl_spdveh_par < (UInt32)VSCtl_spdVehHldaVehReqHysLo_C))||
                ((UInt32)VSCtl_bCtlEfc_aVeh     == VSCO_NON_EFFECTIF)                                                                               ||
                ((UInt32)VSCtl_stCtl_aVeh       != VSCO_CONTROLE)                                                                                   ||
                ((UInt32)ext_stgbxcf_par        == VSCO_BVM)                                                                                        ||
                (((UInt32)copt_posnlev_par     != VSCO_COPT_POSNLEV_DRIVE) && ((UInt32)FALSE != (UInt32)ext_bposngbxcf_par )))

            {
                vsco_f6111_mode_gel_consignes_acceleration_vehicule = (UInt8)VSCO_F6111_ARRET;
                VSCtl_bHld_aVehReq          = DDS_FALSE;
                VSCtl_tiHldMax_aVehReq      = VSCtl_tiHldMax_aVehReq_C;
                VSCtl_tiNotHldMin_aVehReq   = VSCtl_tiNotHldMin_aVehReq_C;
            }

            else    /* during actions */
            {
                VSCtl_tiHldMax_aVehReq = (UInt16)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiHldMax_aVehReq, (UInt32)(1 * BIN0));
            }
        break;

        case VSCO_F6111_GEL_INHIBE :
            if((UInt32)VSCtl_tiNotHldMin_aVehReq == (UInt32)(0 * BIN0))
            {
                vsco_f6111_mode_gel_consignes_acceleration_vehicule = (UInt8)VSCO_F6111_ARRET;
                VSCtl_bHld_aVehReq          = DDS_FALSE;
                VSCtl_tiHldMax_aVehReq      = VSCtl_tiHldMax_aVehReq_C;
                VSCtl_tiNotHldMin_aVehReq   = VSCtl_tiNotHldMin_aVehReq_C;
            }
            else    /* during actions */
            {
                VSCtl_tiNotHldMin_aVehReq = (UInt16)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiNotHldMin_aVehReq, (1 * BIN0));
            }
        break;

        default :
            VSCtl_bHld_aVehReq          = DDS_FALSE;
            VSCtl_tiHldMax_aVehReq      = VSCtl_tiHldMax_aVehReq_C;
            VSCtl_tiNotHldMin_aVehReq   = VSCtl_tiNotHldMin_aVehReq_C;
        break;
    }



    /* GESTION_PASSAGE_BANDE_MORTE */
    switch((UInt32)VSCtl_stCtl_TqWhlCutOff_aVeh)
    {
        case VSCO_ACCEL_CONS_ARRET:
            if(((UInt32)VSCtl_stTqWhlCutOffReqPrev == VSCO_ACCEL_CONS_PILOTABLE_H)    &&
               ((UInt32)vsctl_sttqwhlptcutoffreq_par == VSCO_ACCEL_CONS_PILOTABLE_B))
            {
                VSCtl_stCtl_TqWhlCutOff_aVeh = (UInt8)VSCO_ACCEL_CONS_PILOTABLE_B;
            }

            else if(((UInt32)VSCtl_stTqWhlCutOffReqPrev   == VSCO_ACCEL_CONS_PILOTABLE_B)     &&
                    ((UInt32)vsctl_sttqwhlptcutoffreq_par   == VSCO_ACCEL_CONS_PILOTABLE_H))
            {
                VSCtl_stCtl_TqWhlCutOff_aVeh = (UInt8)VSCO_ACCEL_CONS_PILOTABLE_H;
            }

            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCEL_CONS_PILOTABLE_B:
            if(((UInt32)vsctl_sttqwhlptcutoffreq_par == VSCO_ACCEL_CONS_ARRET) ||
               ((UInt32)VSCtl_tiHld_stCtl_aVehCutOff == (UInt32)(0 * BIN0)))
            {
                VSCtl_stCtl_TqWhlCutOff_aVeh = (UInt8)VSCO_ACCEL_CONS_ARRET;
                VSCtl_tiHld_stCtl_aVehCutOff = (3 * BIN0);
            }
            else     /* during actions */
            {
                VSCtl_tiHld_stCtl_aVehCutOff = (UInt8)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiHld_stCtl_aVehCutOff, (UInt32)(1 * BIN0));
            }
        break;

        case VSCO_ACCEL_CONS_PILOTABLE_H:
            if(((UInt32)vsctl_sttqwhlptcutoffreq_par == VSCO_ACCEL_CONS_ARRET) ||
               ((UInt32)VSCtl_tiHld_stCtl_aVehCutOff == (UInt32)(0 * BIN0)))
            {
                VSCtl_stCtl_TqWhlCutOff_aVeh = (UInt8)VSCO_ACCEL_CONS_ARRET;
                VSCtl_tiHld_stCtl_aVehCutOff = (3 * BIN0);
            }
            else    /* during actions */
            {
                VSCtl_tiHld_stCtl_aVehCutOff = (UInt8)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiHld_stCtl_aVehCutOff, (UInt32)(1 * BIN0));
            }
        break;

        default :
            VSCtl_stCtl_TqWhlCutOff_aVeh = (UInt8)VSCO_ACCEL_CONS_ARRET;
            VSCtl_tiHld_stCtl_aVehCutOff = (3 * BIN0);
        break;
    }



    VSCtl_bAvlTqWhlPTPrev_no3    = vsctl_bavltqwhlpt_no3_par;
    VSCtl_stTqWhlCutOffReqPrev = vsctl_sttqwhlptcutoffreq_par;


}


/*******************************************************************************
*
* Function Name : VSCO_F6112_Veh_Accel_Cons_Coord
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6112_Veh_Accel_Cons_Coord(SInt16 vsctl_avehptmax_par,
                                                             SInt16 vsctl_avehptmin_par,
                                                             SInt16 vsctl_avehprecovsctlreq_par,
                                                             SInt16 vsctl_avehdvsregreq_par,
                                                             SInt16 vsctl_avehvsregreq_par,
                                                             SInt16 vsctl_avehvslimreq_par,
                                                             SInt16 vsctl_avehvsmaxreq_par,
                                                             UInt8  ext_stdvsregcf_par,
                                                             UInt8  ext_bvslimcf_par,
                                                             UInt8  ext_bvsmaxfcf_par,
                                                             UInt8  ext_bvsmaxpcf_par,
                                                             UInt8  ext_bvsmaxscf_par,
                                                             SInt16 vsctl_avehptmaxnotctla_par,
                                                             SInt16 vsctl_avehptminnotctla_par,
                                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehreq_ptr,
                                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehcordvsregreq_ptr,
                                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehcordvslimreq_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.05.3 */


    /* F6112_min_input */
    if((UInt32)DDS_TRUE == (UInt32)ext_bvsmaxfcf_par)
    {
        f6112_min_input = vsctl_avehvsmaxreq_par;
    }
    else
    {
        if((UInt32)DDS_TRUE == (UInt32)ext_bvsmaxpcf_par)
        {
            f6112_min_input = vsctl_avehvsmaxreq_par;
        }
        else
        {
            if((UInt32)DDS_TRUE == (UInt32)ext_bvsmaxscf_par)
            {
                f6112_min_input = vsctl_avehvsmaxreq_par;
            }
            else
            {
                f6112_min_input = VSCO_ACCEL_CONS_10_BIN10_POS;
            }
        }
    }


    /* f6112_max_input_1 & f6112_max_input_2 */
    switch((UInt32)ext_stdvsregcf_par)
    {
        case(VSCO_ABSENTE):
            f6112_max_input_1 = VSCO_ACCEL_CONS_10_BIN10_NEG;
            f6112_max_input_2 = VSCO_ACCEL_CONS_10_BIN10_NEG;
            break;
        case(VSCO_RVV_PRESENTE):
            f6112_max_input_1 = vsctl_avehvsregreq_par;
            f6112_max_input_2 = VSCO_ACCEL_CONS_10_BIN10_NEG;
            break;
        case(VSCO_ACC_PRESENTE):
            f6112_max_input_1 = VSCO_ACCEL_CONS_10_BIN10_NEG;
            f6112_max_input_2 = vsctl_avehdvsregreq_par;
            break;
            default:
            f6112_max_input_1 = VSCO_ACCEL_CONS_10_BIN10_NEG;
            f6112_max_input_2 = VSCO_ACCEL_CONS_10_BIN10_NEG;
            break;
    }


    f6112_max_output = (SInt16)DDS_M_MAX((SInt32)f6112_max_input_1,(SInt32)f6112_max_input_2);
    f6112_max_output = (SInt16)DDS_M_MAX((SInt32)f6112_max_output,(SInt32)vsctl_avehprecovsctlreq_par);


    /* f6112_min_output */
    if((UInt32)DDS_FALSE == (UInt32)ext_bvslimcf_par)
    {
        f6112_min_input_2 = VSCO_ACCEL_CONS_10_BIN10_POS;
    }
    else
    {
        f6112_min_input_2 = vsctl_avehvslimreq_par;
    }



    VSCO_F61121_VSCtl_aVehCordVSRegReq_Calc();

    vsctl_avehcordvslimreq_calc = (SInt16)DDS_M_MIN((SInt32)f6112_max_output,(SInt32)f6112_min_input_2);

    VSCO_F61122_VSCtl_aVeh_Calc(vsctl_avehptmax_par,
                                vsctl_avehptmin_par,
                                vsctl_avehptmaxnotctla_par,
                                vsctl_avehptminnotctla_par);


    VSCO_F61123_VSCtl_jrkVehReq();



    if(VSCO_ARRET == (UInt32)VSCtl_stCtl_aVeh)
    {
        *vsctl_avehcordvsregreq_ptr = VSCO_ACCEL_CONS_10_BIN10_NEG;
        *vsctl_avehcordvslimreq_ptr = VSCO_ACCEL_CONS_10_BIN10_POS;
        *vsctl_avehreq_ptr          = VSCO_ACCEL_CONS_10_BIN10_NEG;
        VSCtl_aVehMaxReq            = VSCO_ACCEL_CONS_10_BIN10_POS;
        VSCtl_aVehMinReq            = VSCO_ACCEL_CONS_10_BIN10_NEG;
        VSCtl_jrkVehReq             = VSCO_ACCEL_CONS_0_BIN7;
    }
    else
    {
        *vsctl_avehcordvsregreq_ptr = vsctl_avehcordvsregreq_calc;
        *vsctl_avehcordvslimreq_ptr = vsctl_avehcordvslimreq_calc;
        *vsctl_avehreq_ptr          = vsctl_avehreq_calc;
        VSCtl_aVehMaxReq            = vsctl_avehmaxreq_calc;
        VSCtl_aVehMinReq            = vsctl_avehminreq_calc;
        VSCtl_jrkVehReq             = vsctl_jrkvehreq_calc;
    }

    vsctl_avehreq_prev      = *vsctl_avehreq_ptr;
    vsctl_avehmaxreq_prev   = VSCtl_aVehMaxReq;
    vsctl_avehminreq_prev   = VSCtl_aVehMinReq;

    /* [-10;10]BIN10 */
    vsctl_jrkvehreq_prev_4 = vsctl_jrkvehreq_prev_3;
    vsctl_jrkvehreq_prev_3 = vsctl_jrkvehreq_prev_2;
    vsctl_jrkvehreq_prev_2 = vsctl_jrkvehreq_prev_1;
    vsctl_jrkvehreq_prev_1 = *vsctl_avehreq_ptr;
}


/*******************************************************************************
*
* Function Name : VSCO_F61121_VSCtl_aVehCordVSRegReq_Calc
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61121_VSCtl_aVehCordVSRegReq_Calc(void)
{
    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bDeacSatCordVSRegReq_C)
    {
        vsctl_avehcordvsregreq_calc = (SInt16)DDS_M_MIN((SInt32)f6112_min_input,(SInt32)f6112_max_output);
    }
    else
    {
        vsctl_avehcordvsregreq_calc = f6112_max_output;
    }
}


/*******************************************************************************
*
* Function Name : VSCO_F61122_VSCtl_aVeh_Calc
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61122_VSCtl_aVeh_Calc(SInt16 vsctl_avehptmax_par,
                                                         SInt16 vsctl_avehptmin_par,
                                                         SInt16 vsctl_avehptmaxnotctla_par,
                                                         SInt16 vsctl_avehptminnotctla_par)
{

    SInt16 vsctl_avehreq_unlim,vsctl_avehreq_lim;
    SInt16 vsctl_avehmaxreq_unlim,vsctl_avehmaxreq_lim;
    SInt16 vsctl_avehminreq_unlim,vsctl_avehminreq_lim;

    if((UInt32)DDS_TRUE == (UInt32)VSCtl_bHld_aVehReq)
    {
        vsctl_avehreq_calc      = vsctl_avehreq_prev;
        vsctl_avehmaxreq_calc   = vsctl_avehmaxreq_prev;
        vsctl_avehminreq_calc   = vsctl_avehminreq_prev;
    }
    else
    {
        vsctl_avehreq_unlim     = (SInt16)DDS_M_MIN((SInt32)vsctl_avehcordvslimreq_calc,(SInt32)f6112_min_input);
        vsctl_avehmaxreq_unlim  = (SInt16)DDS_M_MIN((SInt32)f6112_min_input_2,(SInt32)f6112_min_input);
        vsctl_avehminreq_unlim  = (SInt16)DDS_M_MAX((SInt32)f6112_max_input_1,(SInt32)f6112_max_input_2);

        vsctl_avehreq_lim       = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehreq_unlim,(SInt32)vsctl_avehptmin_par,(SInt32)vsctl_avehptmax_par);
        vsctl_avehmaxreq_lim    = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehmaxreq_unlim,(SInt32)vsctl_avehptmin_par,(SInt32)vsctl_avehptmax_par);
        vsctl_avehminreq_lim    = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehminreq_unlim,(SInt32)vsctl_avehptmin_par,(SInt32)vsctl_avehptmax_par);

        switch((UInt32)VSCtl_stCtl_TqWhlCutOff_aVeh)
        {
            case(VSCO_ACCEL_CONS_ARRET):
                vsctl_avehreq_calc      = vsctl_avehreq_lim;
                vsctl_avehmaxreq_calc   = vsctl_avehmaxreq_lim;
                vsctl_avehminreq_calc   = vsctl_avehminreq_lim;
                break;
            case(VSCO_ACCEL_CONS_PILOTABLE_H):
                vsctl_avehreq_calc      = (SInt16)DDS_M_MIN((SInt32)vsctl_avehreq_lim,(SInt32)vsctl_avehptmaxnotctla_par);
                vsctl_avehmaxreq_calc   = (SInt16)DDS_M_MIN((SInt32)vsctl_avehmaxreq_lim,(SInt32)vsctl_avehptmaxnotctla_par);
                vsctl_avehminreq_calc   = (SInt16)DDS_M_MIN((SInt32)vsctl_avehminreq_lim,(SInt32)vsctl_avehptmaxnotctla_par);
                break;
            case(VSCO_ACCEL_CONS_PILOTABLE_B):
                vsctl_avehreq_calc      = (SInt16)DDS_M_MAX((SInt32)vsctl_avehreq_lim,(SInt32)vsctl_avehptminnotctla_par);
                vsctl_avehmaxreq_calc   = (SInt16)DDS_M_MAX((SInt32)vsctl_avehmaxreq_lim,(SInt32)vsctl_avehptminnotctla_par);
                vsctl_avehminreq_calc   = (SInt16)DDS_M_MAX((SInt32)vsctl_avehminreq_lim,(SInt32)vsctl_avehptminnotctla_par);
                break;
            default:
                vsctl_avehreq_calc      = vsctl_avehreq_lim;
                vsctl_avehmaxreq_calc   = vsctl_avehmaxreq_lim;
                vsctl_avehminreq_calc   = vsctl_avehminreq_lim;
                break;
        }
    }
}

/*******************************************************************************
*
* Function Name : VSCO_F61123_VSCtl_jrkVehReq
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61123_VSCtl_jrkVehReq(void)

{
    SInt32 vsco_f61123_filter_in;


    /* [-20;20]BIN10 = [-10;10]BIN10 - [-10;10]BIN10 */
    vsco_f61123_filter_in = (SInt32)vsctl_avehreq_calc - (SInt32)vsctl_jrkvehreq_prev_4;


    /* [-500;500]BIN10 = ([-20;20]BIN10 * DEC3) / (0.04 * DEC3) */
    vsco_f61123_filter_in = (vsco_f61123_filter_in * (SInt32)DEC3) / VSCO_SCHEDULING_T1;

    /* [-100;100]BIN7 */
    vsco_f61123_filter_in = DDS_M_LIMIT((vsco_f61123_filter_in / BIN3),
                                        VSCO_ACCEL_CONS_100_BIN7_NEG,
                                        VSCO_ACCEL_CONS_100_BIN7_POS);


    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvFil_aVeh)
    {
        vsctl_jrkvehreq_calc = DDS_M_FILTER_LP1_S16(&f6111_low_pass_t_struct,
                                               (SInt16)vsco_f61123_filter_in,
                                               (UInt16)VSCtl_tiFil_jrkVehReq_C,
                                               BIN7);
    }
    else
    {
        vsctl_jrkvehreq_calc = DDS_M_FILTER_LP1_S16_INIT(&f6111_low_pass_t_struct,
                                                    (SInt16)vsco_f61123_filter_in);
    }


}

/*******************************************************************************
*
* Function Name : VSCO_F6113_Sat_Veh_Accel_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6113_Sat_Veh_Accel_Cons_Deter(SInt16 vsctl_avehptmax_par,
                                                                 SInt16 vsctl_avehptmin_par,
                                                                 SInt16 vsctl_avehprecovsctlreq_par,
                                                                 SInt16 vsctl_avehdvsregreq_par,
                                                                 SInt16 vsctl_avehvsregreq_par,
                                                                 SInt16 vsctl_avehvslimreq_par,
                                                                 SInt16 vsctl_avehvsmaxreq_par,
                                                                 SInt16 vsctl_avehcordvsregreq_par,
                                                                 SInt16 vsctl_avehcordvslimreq_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.06.1 */

    if(VSCO_CONTROLE == (UInt32)VSCtl_stCtl_aVeh)
    {
        VSCtl_aVehDVSRegReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehdvsregreq_par,
                                                             (SInt32)vsctl_avehptmin_par,
                                                             (SInt32)vsctl_avehptmax_par);

        VSCtl_aVehVSRegReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehvsregreq_par,
                                                            (SInt32)vsctl_avehptmin_par,
                                                            (SInt32)vsctl_avehptmax_par);

        VSCtl_aVehVSLimReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehvslimreq_par,
                                                            (SInt32)vsctl_avehptmin_par,
                                                            (SInt32)vsctl_avehptmax_par);

        VSCtl_aVehVSMaxReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehvsmaxreq_par,
                                                            (SInt32)vsctl_avehptmin_par,
                                                            (SInt32)vsctl_avehptmax_par);

        VSCtl_aVehPreCoVSCtlReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehprecovsctlreq_par,
                                                                (SInt32)vsctl_avehptmin_par,
                                                                (SInt32)vsctl_avehptmax_par);

        VSCtl_aVehCordVSRegReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehcordvsregreq_par,
                                                                (SInt32)vsctl_avehptmin_par,
                                                                (SInt32)vsctl_avehptmax_par);

        VSCtl_aVehCordVSLimReqSat = (SInt16)DDS_M_SATURATION_V2((SInt32)vsctl_avehcordvslimreq_par,
                                                                (SInt32)vsctl_avehptmin_par,
                                                                (SInt32)vsctl_avehptmax_par);
    }
    else
    {
        VSCtl_aVehDVSRegReqSat      = VSCO_ACCEL_CONS_10_BIN10_NEG;
        VSCtl_aVehVSRegReqSat       = VSCO_ACCEL_CONS_10_BIN10_NEG;
        VSCtl_aVehVSLimReqSat       = VSCO_ACCEL_CONS_10_BIN10_POS;
        VSCtl_aVehVSMaxReqSat       = VSCO_ACCEL_CONS_10_BIN10_POS;
        VSCtl_aVehPreCoVSCtlReqSat  = (SInt16)(0 * BIN10);
        VSCtl_aVehCordVSRegReqSat   = VSCO_ACCEL_CONS_10_BIN10_NEG;
        VSCtl_aVehCordVSLimReqSat   = VSCO_ACCEL_CONS_10_BIN10_POS;
    }

}


/*******************************************************************************
*
* Function Name : VSCO_F6114_Veh_Accel_Cons_Effec_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6114_Veh_Accel_Cons_Effec_Deter(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrdvsreg_aveh_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrddvsreg_aveh_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrdvslim_aveh_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdrvovrdvsmax_aveh_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.07.2 */

    /* REPRISE_ACCEL_RVV */
    switch(vsctl_bdrvovrdvsreg_aveh_local)
    {
        case VSCO_ACCELERATION_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) > ((SInt32)VSCtl_aVehVSRegReqSat + (SInt32)VSCtl_aVehEDrvOvdVSReg_HysHi_C)))
            {
                vsctl_bdrvovrdvsreg_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCELERATION_NON_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh    != VSCO_CONTROLE) ||
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) <= ((SInt32)VSCtl_aVehVSRegReqSat + (SInt32)VSCtl_aVehEDrvOvdVSReg_HysLo_C)))
            {
                vsctl_bdrvovrdvsreg_aveh_local = VSCO_ACCELERATION_EFFECTIVE;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            vsctl_bdrvovrdvsreg_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
        break;
    }


    /* REPRISE_ACCEL_ACC */
    switch(vsctl_bdrvovrddvsreg_aveh_local)
    {
        case VSCO_ACCELERATION_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE)  &&
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) > ((SInt32)VSCtl_aVehDVSRegReqSat + (SInt32)VSCtl_aVhEDrvOvdDVSReg_HysHi_C)))
            {
                vsctl_bdrvovrddvsreg_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCELERATION_NON_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) <= ((SInt32)VSCtl_aVehDVSRegReqSat + (SInt32)VSCtl_aVhEDrvOvdDVSReg_HysLo_C)))
            {
                vsctl_bdrvovrddvsreg_aveh_local = VSCO_ACCELERATION_EFFECTIVE;
            }
        break;

        default:
            vsctl_bdrvovrddvsreg_aveh_local = VSCO_ACCELERATION_EFFECTIVE;
        break;
    }



    /* REPRISE_ACCEL_LVV */
    switch(vsctl_bdrvovrdvslim_aveh_local)
    {
        case VSCO_ACCELERATION_NON_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE)  &&
               (((SInt32)VSCtl_aVehCordVSRegReqSat) >= ((SInt32)VSCtl_aVehVSLimReqSat + (SInt32)VSCtl_aVehEDrvOvdVSLim_HysHi_C)))
            {
                vsctl_bdrvovrdvslim_aveh_local = VSCO_ACCELERATION_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCELERATION_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE)  ||
               (((SInt32)VSCtl_aVehCordVSRegReqSat) < ((SInt32)VSCtl_aVehVSLimReqSat + (SInt32)VSCtl_aVehEDrvOvdVSLim_HysLo_C)))
            {
                vsctl_bdrvovrdvslim_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            vsctl_bdrvovrdvslim_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
        break;
    }




    /* REPRISE_ACCEL_BVV */
    switch(vsctl_bdrvovrdvsmax_aveh_local)
    {
        case VSCO_ACCELERATION_NON_EFFECTIVE:
            if( ((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
                (((SInt32)VSCtl_aVehCordVSLimReqSat) >= ((SInt32)VSCtl_aVehVSMaxReqSat + (SInt32)VSCtl_aVehEDrvOvdVSMax_HysHi_C)))
            {
                vsctl_bdrvovrdvsmax_aveh_local = VSCO_ACCELERATION_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCELERATION_EFFECTIVE:
            if( ((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE)||
                (((SInt32)VSCtl_aVehCordVSLimReqSat) < ((SInt32)VSCtl_aVehVSMaxReqSat + (SInt32)VSCtl_aVehEDrvOvdVSMax_HysLo_C)))
            {
                vsctl_bdrvovrdvsmax_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            vsctl_bdrvovrdvsmax_aveh_local = VSCO_ACCELERATION_NON_EFFECTIVE;
        break;
    }



    /* REPRISE_ACCEL_RVV_INTERNE */
    switch((UInt32)VSCtl_bDrvOvrdVSRegInt_aVeh)
    {
        case VSCO_ACCELERATION_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) >= ((SInt32)VSCtl_aVehVSRegReqSat + (SInt32)VSCtl_aVehEDrvOvdVSReg_HysHi2_C)))
            {
                VSCtl_bDrvOvrdVSRegInt_aVeh = (UInt8)VSCO_ACCELERATION_NON_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCELERATION_NON_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE)||
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) < ((SInt32)VSCtl_aVehVSRegReqSat + (SInt32)VSCtl_aVehEDrvOvdVSReg_HysLo2_C)))
            {
                VSCtl_bDrvOvrdVSRegInt_aVeh = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bDrvOvrdVSRegInt_aVeh = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
        break;


    }


    /* REPRISE_ACCEL_ACC_INTERNE */
    switch((UInt32)VSCtl_bDrvOvrdDVSRegInt_aVeh)
    {
        case VSCO_ACCELERATION_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE)  &&
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) >= ((SInt32)VSCtl_aVehDVSRegReqSat + (SInt32)VSCtl_aVhEDrvOvdDVSReg_HysHi2_C)))
            {
                VSCtl_bDrvOvrdDVSRegInt_aVeh = (UInt8)VSCO_ACCELERATION_NON_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_ACCELERATION_NON_EFFECTIVE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE)||
               (((SInt32)VSCtl_aVehPreCoVSCtlReqSat) < ((SInt32)VSCtl_aVehDVSRegReqSat + (SInt32)VSCtl_aVhEDrvOvdDVSReg_HysLo2_C)))
            {
                VSCtl_bDrvOvrdDVSRegInt_aVeh = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bDrvOvrdDVSRegInt_aVeh = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
        break;
    }


    /* EFFECTIVITE_MIN_XVV */
    switch((UInt32)VSCtl_bCtlEfc_aVehMin)
    {
        case VSCO_NON_EFFECTIF:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
              ((vsctl_bdrvovrdvsreg_aveh_local == VSCO_ACCELERATION_EFFECTIVE) || (vsctl_bdrvovrddvsreg_aveh_local == VSCO_ACCELERATION_EFFECTIVE)))
            {
                VSCtl_bCtlEfc_aVehMin = (UInt8)VSCO_EFFECTIF;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_EFFECTIF:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (    (vsctl_bdrvovrdvsreg_aveh_local == VSCO_ACCELERATION_NON_EFFECTIVE) &&
                    (vsctl_bdrvovrddvsreg_aveh_local == VSCO_ACCELERATION_NON_EFFECTIVE)))
            {
                VSCtl_bCtlEfc_aVehMin = (UInt8)VSCO_NON_EFFECTIF;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bCtlEfc_aVehMin = (UInt8)VSCO_NON_EFFECTIF;
        break;
    }



    /* EFFECTIVITE_MAX_XVV */
    switch((UInt32)VSCtl_bCtlEfc_aVehMax)
    {
        case VSCO_NON_EFFECTIF:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               ((vsctl_bdrvovrdvslim_aveh_local == VSCO_ACCELERATION_EFFECTIVE)||(vsctl_bdrvovrdvsmax_aveh_local == VSCO_ACCELERATION_EFFECTIVE)))
            {
                VSCtl_bCtlEfc_aVehMax = (UInt8)VSCO_EFFECTIF;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_EFFECTIF:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (    (vsctl_bdrvovrdvslim_aveh_local == VSCO_ACCELERATION_NON_EFFECTIVE) &&
                    (vsctl_bdrvovrdvsmax_aveh_local == VSCO_ACCELERATION_NON_EFFECTIVE)))
            {
                VSCtl_bCtlEfc_aVehMax = (UInt8)VSCO_NON_EFFECTIF;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bCtlEfc_aVehMax = (UInt8)VSCO_NON_EFFECTIF;
        break;
    }



    /* EFFECTIVITE_XVV */
    switch((UInt32)VSCtl_bCtlEfc_aVeh)
    {
        case VSCO_NON_EFFECTIF:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE)  &&
               (((UInt32)VSCtl_bCtlEfc_aVehMin == VSCO_EFFECTIF) || ((UInt32)VSCtl_bCtlEfc_aVehMax == VSCO_EFFECTIF)))
            {
                VSCtl_bCtlEfc_aVeh = (UInt8)VSCO_EFFECTIF;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_EFFECTIF:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (((UInt32)VSCtl_bCtlEfc_aVehMin == VSCO_NON_EFFECTIF) && ((UInt32)VSCtl_bCtlEfc_aVehMax == VSCO_NON_EFFECTIF)))
            {
                VSCtl_bCtlEfc_aVeh = (UInt8)VSCO_NON_EFFECTIF;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bCtlEfc_aVeh = (UInt8)VSCO_NON_EFFECTIF;
        break;
    }


    *vsctl_bdrvovrdvsreg_aveh_ptr   = (UInt8)vsctl_bdrvovrdvsreg_aveh_local;
    *vsctl_bdrvovrddvsreg_aveh_ptr  = (UInt8)vsctl_bdrvovrddvsreg_aveh_local;
    *vsctl_bdrvovrdvslim_aveh_ptr   = (UInt8)vsctl_bdrvovrdvslim_aveh_local;
    *vsctl_bdrvovrdvsmax_aveh_ptr   = (UInt8)vsctl_bdrvovrdvsmax_aveh_local;
}

/*******************************************************************************
*
* Function Name : VSCO_F6115_Veh_Accel_Cons_Trans_End_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6115_Veh_Accel_Cons_Trans_End_Deter(UInt8 vsctl_bctlefc_tqwhlptmin_par,
                                                                       UInt8 vsctl_bctlefc_tqwhlptmax_par,
                                                                       UInt8 vsctl_bctlefc_tqckefcmin_par,
                                                                       UInt8 vsctl_bctlefc_tqckefcmax_par,
                                                                       SInt16 vsctl_avehvsregreq_par,
                                                                       SInt16 vsctl_avehvslimreq_par,
                                                                       SInt16 vsctl_avehvsmaxreq_par,
                                                                       SInt16 vsctl_avehprecovsctlreq_par,
                                                                       SInt16 vsctl_avehcordvsregreq_par,
                                                                       SInt16 vsctl_avehcordvslimreq_par,
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bendtranvsreg_ptr,
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bendtranvslim_ptr,
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bendtranvsmax_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.08.4 */


    /* FIN_TRANSITION_CONSIGNES_ACCELERATION_VEHICULE */
    switch((UInt32)vsco_f6115_attribution_effectivite_couples_moteur_couples_roue)
    {
        case VSCO_F6115_NON_ATTRIBUEE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               ((UInt32)VSCtl_bCtlCmdPTTqCf_SC != (UInt32)DDS_FALSE))
            {
                vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_COUPLE_ROUE;
                VSCtl_bCtlEfc_tqMax = vsctl_bctlefc_tqwhlptmax_par;
                VSCtl_bCtlEfc_tqMin = vsctl_bctlefc_tqwhlptmin_par;
            }
/* <PRQA_COMMENT><2992><2996> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2996></2992></PRQA_COMMENT> */
            else if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
                    ((UInt32)VSCtl_bCtlCmdPTTqCf_SC == (UInt32)DDS_FALSE))
          {
/* <PRQA_COMMENT><2880> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2880></PRQA_COMMENT> */
                vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_COUPLE_MOTEUR;
                VSCtl_bCtlEfc_tqMax = vsctl_bctlefc_tqckefcmax_par;
                VSCtl_bCtlEfc_tqMin = vsctl_bctlefc_tqckefcmin_par;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F6115_COUPLE_ROUE:
            if((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE)
            {
                vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_NON_ATTRIBUEE;
                VSCtl_bCtlEfc_tqMax = DDS_FALSE;
                VSCtl_bCtlEfc_tqMin = DDS_FALSE;
            }
/* <PRQA_COMMENT><2742> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2742></PRQA_COMMENT> */
            else if((UInt32)VSCtl_bCtlCmdPTTqCf_SC == (UInt32)DDS_FALSE)
            {
                            /* <PRQA_COMMENT><2880> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </2880></PRQA_COMMENT> */
                vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_COUPLE_MOTEUR;
                VSCtl_bCtlEfc_tqMax = vsctl_bctlefc_tqckefcmax_par;
                VSCtl_bCtlEfc_tqMin = vsctl_bctlefc_tqckefcmin_par;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F6115_COUPLE_MOTEUR:
            if((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE)
            {
                vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_NON_ATTRIBUEE;
                VSCtl_bCtlEfc_tqMax = DDS_FALSE;
                VSCtl_bCtlEfc_tqMin = DDS_FALSE;
            }
/* <PRQA_COMMENT><2741> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2741></PRQA_COMMENT> */
            else if((UInt32)VSCtl_bCtlCmdPTTqCf_SC != (UInt32)DDS_FALSE)
            {
                vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_COUPLE_ROUE;
                VSCtl_bCtlEfc_tqMax = vsctl_bctlefc_tqwhlptmax_par;
                VSCtl_bCtlEfc_tqMin = vsctl_bctlefc_tqwhlptmin_par;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bCtlEfc_tqMax = DDS_FALSE;
            VSCtl_bCtlEfc_tqMin = DDS_FALSE;
        break;

    }

    /* FIN_TRANSITION_CONSIGNE_ACCELERATION_RVV */
    switch(vsctl_bendtranvsreg_local)
    {
        case DDS_TRUE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               (((UInt32)VSCtl_bCtlEfc_tqMin == (UInt32)DDS_TRUE)|| ((SInt32)vsctl_avehprecovsctlreq_par < (SInt32)vsctl_avehvsregreq_par)))
            {
                vsctl_bendtranvsreg_local = (UInt32)DDS_FALSE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case DDS_FALSE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (((UInt32)VSCtl_bCtlEfc_tqMin == (UInt32)DDS_FALSE) && ((SInt32)vsctl_avehprecovsctlreq_par >= (SInt32)vsctl_avehvsregreq_par)))
            {
                vsctl_bendtranvsreg_local = (UInt32)DDS_TRUE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            vsctl_bendtranvsreg_local = (UInt32)DDS_TRUE;
        break;
    }


    /* FIN_TRANSITION_CONSIGNE_ACCELERATION_LVV */
    switch(vsctl_bendtranvslim_local)
    {
        case (UInt32)DDS_TRUE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               (((UInt32)VSCtl_bCtlEfc_tqMax == (UInt32)DDS_TRUE) || ((SInt32)vsctl_avehcordvsregreq_par > (SInt32)vsctl_avehvslimreq_par)))
            {
                vsctl_bendtranvslim_local = (UInt32)DDS_FALSE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case (UInt32)DDS_FALSE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (((UInt32)VSCtl_bCtlEfc_tqMax == (UInt32)DDS_FALSE) && ((SInt32)vsctl_avehcordvsregreq_par <= (SInt32)vsctl_avehvslimreq_par)))
            {
                vsctl_bendtranvslim_local = (UInt32)DDS_TRUE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            vsctl_bendtranvslim_local = (UInt32)DDS_TRUE;
        break;
    }

    /* FIN_TRANSITION_CONSIGNE_ACCELERATION_BVV */
    switch(vsctl_bendtranvsmax_local)
    {
        case (UInt32)DDS_TRUE:
            if(((UInt32)VSCtl_stCtl_aVeh == VSCO_CONTROLE) &&
               (((UInt32)VSCtl_bCtlEfc_tqMax == (UInt32)DDS_TRUE) || ((SInt32)vsctl_avehcordvslimreq_par > (SInt32)vsctl_avehvsmaxreq_par)))
            {
                vsctl_bendtranvsmax_local = (UInt32)DDS_FALSE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case (UInt32)DDS_FALSE:
            if(((UInt32)VSCtl_stCtl_aVeh != VSCO_CONTROLE) ||
               (((UInt32)VSCtl_bCtlEfc_tqMax == (UInt32)DDS_FALSE) && ((SInt32)vsctl_avehcordvslimreq_par <= (SInt32)vsctl_avehvsmaxreq_par)))
            {
                vsctl_bendtranvsmax_local = (UInt32)DDS_TRUE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            vsctl_bendtranvsmax_local = (UInt32)DDS_TRUE;
        break;

    }


    *vsctl_bendtranvsreg_ptr = (UInt8)vsctl_bendtranvsreg_local;
    *vsctl_bendtranvslim_ptr = (UInt8)vsctl_bendtranvslim_local;
    *vsctl_bendtranvsmax_ptr = (UInt8)vsctl_bendtranvsmax_local;

}

/*******************************************************************************
*
* Function Name : VSCO_F6116_Min_Veh_Accel_Lim_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6116_Min_Veh_Accel_Lim_Cons_Deter(UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
                                                                     SInt16 vsctl_avehptlim_par,
                                                                     SInt16 vsctl_avehreq_par,
                                                                     SInt16 vsctl_avehptdrvminreq_par,
                                                                     SInt16 vsctl_avehptdrvminreqraw_par,
                                                                     UInt8 vsctl_stctl_tqwhlmax_par,
                                                                     UInt8 vsctl_stctl_tqwhlmin_par,
                                                                     UInt8 vsctl_bdrvovrdvsmax_aveh_par,
                                                                     UInt8 vsctl_bdrvovrdvslim_aveh_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.37.0 */

    VSCO_F61161_Min_Veh_Accel_Lim_Com_Mode_Deter(vsctl_bdrvovrdvsreg_spdveh_par,
                                                 vsctl_avehptlim_par,
                                                 vsctl_avehreq_par,
                                                 vsctl_avehptdrvminreq_par,
                                                 vsctl_avehptdrvminreqraw_par,
                                                 vsctl_stctl_tqwhlmax_par,
                                                 vsctl_stctl_tqwhlmin_par,
                                                 vsctl_bdrvovrdvsmax_aveh_par,
                                                 vsctl_bdrvovrdvslim_aveh_par);


    VSCO_F61162_Min_Veh_Accel_Lim_Cons_Deter(vsctl_avehptlim_par,
                                             vsctl_avehreq_par,
                                             vsctl_avehptdrvminreq_par,
                                             vsctl_avehptdrvminreqraw_par);





}

/*******************************************************************************
*
* Function Name : VSCO_F61161_Min_Veh_Accel_Lim_Com_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61161_Min_Veh_Accel_Lim_Com_Mode_Deter(UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
                                                                          SInt16 vsctl_avehptlim_par,
                                                                          SInt16 vsctl_avehreq_par,
                                                                          SInt16 vsctl_avehptdrvminreq_par,
                                                                          SInt16 vsctl_avehptdrvminreqraw_par,
                                                                          UInt8 vsctl_stctl_tqwhlmax_par,
                                                                          UInt8 vsctl_stctl_tqwhlmin_par,
                                                                          UInt8 vsctl_bdrvovrdvsmax_aveh_par,
                                                                          UInt8 vsctl_bdrvovrdvslim_aveh_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.38.0 */

    /* ACTIVATION_LIMITATION_ACCELERATION_VEHICULE */
    switch((UInt32)VSCtl_bAcv_aVehMinSat)
    {
        case (UInt32)DDS_FALSE:
            if( ((UInt32)VSCtl_bCtlCmdPTTqCf_SC != (UInt32)DDS_FALSE)           &&
                ((UInt32)VSCtl_stCtl_aVeh      == VSCO_CONTROLE)                    &&

                ((((UInt32)vsctl_bdrvovrdvsmax_aveh_par     == (UInt32)DDS_TRUE)
                && ((UInt32)vsctl_bdrvovrdvsreg_spdveh_par  == (UInt32)DDS_FALSE)
                && ((UInt32)vsctl_stctl_tqwhlmax_par        == VSCO_CONTROLE)
                && ((UInt32)vsctl_bdrvovrdvslim_aveh_par    ==(UInt32)DDS_FALSE))

                ||

                (((UInt32)vsctl_bdrvovrdvsmax_aveh_par      == (UInt32)DDS_TRUE)
                && ((UInt32)vsctl_bdrvovrdvsreg_spdveh_par  == (UInt32)DDS_FALSE)
                && ((UInt32)vsctl_stctl_tqwhlmin_par        == VSCO_CONTROLE)
                && ((UInt32)vsctl_stctl_tqwhlmax_par        != VSCO_CONTROLE)
                && ((UInt32)vsctl_bdrvovrdvslim_aveh_par    == (UInt32)DDS_TRUE))))
            {
                VSCtl_bAcv_aVehMinSat = DDS_TRUE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case (UInt32)DDS_TRUE:
            if( ((UInt32)VSCtl_bCtlCmdPTTqCf_SC      == (UInt32)DDS_FALSE)      ||
                ((UInt32)VSCtl_stCtl_aVeh           != VSCO_CONTROLE)               ||

                ((((UInt32)vsctl_bdrvovrdvsmax_aveh_par         != (UInt32)DDS_TRUE)
                || ((UInt32)vsctl_bdrvovrdvsreg_spdveh_par      != (UInt32)DDS_FALSE)
                || ((UInt32)vsctl_stctl_tqwhlmax_par            != VSCO_CONTROLE)
                || ((UInt32)vsctl_bdrvovrdvslim_aveh_par        != (UInt32)DDS_FALSE))

                &&

                (((UInt32)vsctl_bdrvovrdvsmax_aveh_par          != (UInt32)DDS_TRUE)
                || ((UInt32)vsctl_bdrvovrdvsreg_spdveh_par      != (UInt32)DDS_FALSE)
                || ((UInt32)vsctl_stctl_tqwhlmin_par            != VSCO_CONTROLE)
                || ((UInt32)vsctl_stctl_tqwhlmax_par            == VSCO_CONTROLE)
                || ((UInt32)vsctl_bdrvovrdvslim_aveh_par        != (UInt32)DDS_TRUE))))
            {
                VSCtl_bAcv_aVehMinSat = DDS_FALSE;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        default:
            VSCtl_bAcv_aVehMinSat = DDS_FALSE;
        break;
    }



    /* CONTROLE_LIMITATION_ACCELERATION_VEHICULE */
    switch((UInt32)VSCtl_stCtlaVehMinSat)
    {
        case VSCO_STCTLAVEHMINSAT_ARRET:
            if(((UInt32)VSCtl_bAcv_aVehMinSat == (UInt32)DDS_TRUE) &&
               ((SInt32)vsctl_avehreq_par >= (SInt32)vsctl_avehptlim_par))
            {
                VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_CONTROLE_31;
            }
            else if(((UInt32)VSCtl_bAcv_aVehMinSat == (UInt32)DDS_TRUE) &&
            /* <PRQA_COMMENT><2995> statement value change with VSCtl_bCtlCmdPTTqCf_SC </2995></PRQA_COMMENT> */
                    ((SInt32)vsctl_avehreq_par < (SInt32)vsctl_avehptlim_par))
            {
                VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_ACTIVATION_31;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_STCTLAVEHMINSAT_CONTROLE_31:
            if((UInt32)VSCtl_bAcv_aVehMinSat == (UInt32)DDS_FALSE)
            {
                VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_DESACTIVATION_31;
                VSCtl_tiFilStCtlAVehMinSat = VSCtl_tiFilStCtlAVehMinSat_C;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_STCTLAVEHMINSAT_ACTIVATION_31:
            if((UInt32)VSCtl_bAcv_aVehMinSat == (UInt32)DDS_FALSE)
            {
                VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_DESACTIVATION_31;
                VSCtl_tiFilStCtlAVehMinSat = VSCtl_tiFilStCtlAVehMinSat_C;
            }
            else
            {
                if((SInt32)vsctl_avehreq_par >= (SInt32)vsctl_avehptlim_par)
                {
                    VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_CONTROLE_31;
                }

                else    /* during actions */
                {
                    /* do nothing, stay in this state */
                }
            }
        break;

        case VSCO_STCTLAVEHMINSAT_DESACTIVATION_31:
            if((SInt32)vsctl_avehptdrvminreq_par == (SInt32)vsctl_avehptdrvminreqraw_par)
            {
                VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_ARRET;
            }

            else if((UInt32)VSCtl_bAcv_aVehMinSat == (UInt32)DDS_TRUE)
            {
                VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_ACTIVATION_31;
            }

            else    /* during actions */
            {
                VSCtl_tiFilStCtlAVehMinSat = (UInt16)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiFilStCtlAVehMinSat, (UInt32)(1 * BIN0));
            }
        break;

        default:
            VSCtl_stCtlaVehMinSat = (UInt8)VSCO_STCTLAVEHMINSAT_ARRET;
        break;

    }



}


/*******************************************************************************
*
* Function Name : VSCO_F61162_Min_Veh_Accel_Lim_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61162_Min_Veh_Accel_Lim_Cons_Deter(SInt16 vsctl_avehptlim_par,
                                                                      SInt16 vsctl_avehreq_par,
                                                                      SInt16 vsctl_avehptdrvminreq_par,
                                                                      SInt16 vsctl_avehptdrvminreqraw_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.39.0 */

    SInt32 num_div, output_div, mult_tmp;
    SInt16 f61162_map_output;

    f61162_map_output = DDS_M_MAP2D_S16(&VSCTL_JRKVEHTRANLIM_AVEHREQ_T_APM,     /* [-100;100]BIN7 */
                                    vsctl_avehreq_par);

    switch((UInt32)VSCtl_stCtlaVehMinSat)
    {
        case(VSCO_STCTLAVEHMINSAT_ARRET):
            VSCtl_aVehWhlMinSat         = VSCO_ACCEL_CONS_10_BIN10_NEG;
            VSCtl_jrkVehWhlMinSat       = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw1   = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw2   = VSCO_ACCEL_CONS_0_BIN7;
            break;
        case(VSCO_STCTLAVEHMINSAT_ACTIVATION_31):
            VSCtl_aVehWhlMinSat         = (SInt16)DDS_M_MAX((SInt32)vsctl_avehreq_par,(SInt32)vsctl_avehwhlminsat_prev);
            VSCtl_jrkVehWhlMinSat       = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw1   = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw2   = VSCO_ACCEL_CONS_0_BIN7;
            break;
        case(VSCO_STCTLAVEHMINSAT_CONTROLE_31):
            VSCtl_aVehWhlMinSat         = vsctl_avehptlim_par;
            VSCtl_jrkVehWhlMinSat       = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw1   = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw2   = VSCO_ACCEL_CONS_0_BIN7;
            break;
        case(VSCO_STCTLAVEHMINSAT_DESACTIVATION_31):

            /* [-20;20]BIN10 = [-10;10]BIN10 - [-10;10]BIN10 */
            num_div = (SInt32)vsctl_avehptdrvminreqraw_par - (SInt32)vsctl_avehptdrvminreq_par;

            if((UInt32)VSCtl_tiFilStCtlAVehMinSat != 0)
            {
                /* [-2000;2000]BIN10 = [-20;20]BIN10*DEC3 / ([0;65535]DEC0 * 0.01*DEC3) */
                output_div = (num_div * DEC3)/ ((SInt32)VSCtl_tiFilStCtlAVehMinSat * VSCO_SCHEDULING_T2);
            }
            else
            {
                if(num_div > 0)
                {
                    output_div = DDS_SINT32_MAX;
                }
                else
                {
                    output_div = DDS_SINT32_MIN;
                }
            }

            /* [-100;100]BIN7 = LIMIT ([-2000;2000]BIN10 / BIN3) */
            VSCtl_jrkVehWhlMinSatRaw2 = (SInt16)DDS_M_LIMIT((output_div / BIN3),
                                                             VSCO_ACCEL_CONS_100_BIN7_NEG,
                                                             VSCO_ACCEL_CONS_100_BIN7_POS);

            /* [-100;100]BIN7 */
            VSCtl_jrkVehWhlMinSatRaw1 = f61162_map_output;


            /* [-100;100]BIN7 */
            VSCtl_jrkVehWhlMinSat = (SInt16)DDS_M_MIN((SInt32)VSCtl_jrkVehWhlMinSatRaw1, (SInt32)VSCtl_jrkVehWhlMinSatRaw2);

            /* [-1; 1]BIN7 = ([-100; 100]BIN7 * (0.01*DEC3)) / DEC3 */
            mult_tmp = ((SInt32)VSCtl_jrkVehWhlMinSat * VSCO_SCHEDULING_T2) / DEC3;


            /* [-11;11]BIN10 = ([-1;1]BIN7 * BIN3) + [-10;10]BIN10*/
            mult_tmp = (mult_tmp * BIN3) + (SInt32)vsctl_avehwhlminsat_prev;


            /* [-10;10]BIN10 */
            VSCtl_aVehWhlMinSat = (SInt16)DDS_M_LIMIT(mult_tmp, (SInt32)VSCO_ACCEL_CONS_10_BIN10_NEG, (SInt32)VSCO_ACCEL_CONS_10_BIN10_POS);
            break;
        default:
            VSCtl_aVehWhlMinSat         = VSCO_ACCEL_CONS_10_BIN10_NEG;
            VSCtl_jrkVehWhlMinSat       = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw1   = VSCO_ACCEL_CONS_0_BIN7;
            VSCtl_jrkVehWhlMinSatRaw2   = VSCO_ACCEL_CONS_0_BIN7;
            break;
    }

    vsctl_avehwhlminsat_prev = VSCtl_aVehWhlMinSat;
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_Veh_Accel_Cons_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Veh_Accel_Cons_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehReq_swc_out, /* BIN10 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSLimReq_swc_out, /* BIN10 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehCordVSRegReq_swc_out, /* BIN10 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSReg_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSLim_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bEndTranVSMax_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSReg_aVeh_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdDVSReg_aVeh_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSLim_aVeh_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDrvOvrdVSMax_aVeh_swc_out)
{
    /* VSCO_F6111_Veh_Accel_Cmd_Mode_Deter */
    VSCtl_stCtl_aVeh                = (UInt8)VSCO_ARRET;
    VSCtl_tiHld_stCtl_aVehCutOff    = (UInt8)(3 * BIN0);
    VSCtl_tiNotHldMin_aVehReq       = VSCtl_tiNotHldMin_aVehReq_C;
    VSCtl_tiHldMax_aVehReq          = VSCtl_tiHldMax_aVehReq_C;
    VSCtl_stTqWhlCutOffReqPrev    = (UInt8)VSCO_ACCEL_CONS_ARRET;
    VSCtl_bAvlTqWhlPTPrev_no3       = DDS_FALSE;
    VSCtl_stCtl_TqWhlCutOff_aVeh    = (UInt8)VSCO_ACCEL_CONS_ARRET;
    VSCtl_bAcvFil_aVeh              = DDS_FALSE;
    VSCtl_bHld_aVehReq              = DDS_FALSE;

    vsco_f6111_mode_calcul_consignes_acceleration_vehicule_global = (UInt8)VSCO_F6111_FAUX;
    vsco_f6111_mode_gel_consignes_acceleration_vehicule = (UInt8)VSCO_F6111_ARRET;



    /* VSCO_F6112_Veh_Accel_Cons_Coord */
    *VSCtl_aVehReq_swc_out          = VSCO_ACCEL_CONS_10_BIN10_NEG;
    *VSCtl_aVehCordVSRegReq_swc_out = VSCO_ACCEL_CONS_10_BIN10_NEG;
    *VSCtl_aVehCordVSLimReq_swc_out = VSCO_ACCEL_CONS_10_BIN10_POS;

    VSCtl_aVehMaxReq    = VSCO_ACCEL_CONS_10_BIN10_POS;
    VSCtl_aVehMinReq    = VSCO_ACCEL_CONS_10_BIN10_NEG;
    VSCtl_jrkVehReq     = VSCO_ACCEL_CONS_0_BIN7;

    vsctl_avehreq_prev      = VSCO_ACCEL_CONS_10_BIN10_NEG;
    vsctl_avehmaxreq_prev   = VSCO_ACCEL_CONS_10_BIN10_POS;
    vsctl_avehminreq_prev   = VSCO_ACCEL_CONS_10_BIN10_NEG;


    vsctl_jrkvehreq_prev_1 = VSCO_ACCEL_CONS_10_BIN10_NEG;
    vsctl_jrkvehreq_prev_2 = VSCO_ACCEL_CONS_10_BIN10_NEG;
    vsctl_jrkvehreq_prev_3 = VSCO_ACCEL_CONS_10_BIN10_NEG;
    vsctl_jrkvehreq_prev_4 = VSCO_ACCEL_CONS_10_BIN10_NEG;

    (void)DDS_M_FILTER_LP1_S16_INIT(&f6111_low_pass_t_struct, 0);




    /* VSCO_F6113_Sat_Veh_Accel_Cons_Deter */
    VSCtl_aVehDVSRegReqSat      = VSCO_ACCEL_CONS_10_BIN10_NEG;
    VSCtl_aVehVSRegReqSat       = VSCO_ACCEL_CONS_10_BIN10_NEG;
    VSCtl_aVehVSLimReqSat       = VSCO_ACCEL_CONS_10_BIN10_POS;
    VSCtl_aVehVSMaxReqSat       = VSCO_ACCEL_CONS_10_BIN10_POS;
    VSCtl_aVehPreCoVSCtlReqSat  = (SInt16)(0 * BIN10);
    VSCtl_aVehCordVSRegReqSat   = VSCO_ACCEL_CONS_10_BIN10_NEG;
    VSCtl_aVehCordVSLimReqSat   = VSCO_ACCEL_CONS_10_BIN10_POS;




    /* VSCO_F6114_Veh_Accel_Cons_Effec_Deter */
    *VSCtl_bDrvOvrdVSReg_aVeh_swc_out   = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
    *VSCtl_bDrvOvrdDVSReg_aVeh_swc_out  = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
    *VSCtl_bDrvOvrdVSLim_aVeh_swc_out   = (UInt8)VSCO_ACCELERATION_NON_EFFECTIVE;
    *VSCtl_bDrvOvrdVSMax_aVeh_swc_out   = (UInt8)VSCO_ACCELERATION_NON_EFFECTIVE;
    VSCtl_bCtlEfc_aVeh                  = (UInt8)VSCO_NON_EFFECTIF;
    VSCtl_bCtlEfc_aVehMin               = (UInt8)VSCO_NON_EFFECTIF;
    VSCtl_bCtlEfc_aVehMax               = (UInt8)VSCO_NON_EFFECTIF;
    VSCtl_bDrvOvrdDVSRegInt_aVeh        = (UInt8)VSCO_ACCELERATION_EFFECTIVE;
    VSCtl_bDrvOvrdVSRegInt_aVeh         = (UInt8)VSCO_ACCELERATION_EFFECTIVE;

    vsctl_bdrvovrdvsreg_aveh_local  = VSCO_ACCELERATION_EFFECTIVE;
    vsctl_bdrvovrddvsreg_aveh_local = VSCO_ACCELERATION_EFFECTIVE;
    vsctl_bdrvovrdvslim_aveh_local  = VSCO_ACCELERATION_NON_EFFECTIVE;
    vsctl_bdrvovrdvsmax_aveh_local  = VSCO_ACCELERATION_NON_EFFECTIVE;


    /* VSCO_F6115_Veh_Accel_Cons_Trans_End_Deter */
    *VSCtl_bEndTranVSLim_swc_out = DDS_TRUE;
    *VSCtl_bEndTranVSMax_swc_out = DDS_TRUE;
    *VSCtl_bEndTranVSReg_swc_out = DDS_TRUE;
    VSCtl_bCtlEfc_tqMin = DDS_FALSE;
    VSCtl_bCtlEfc_tqMax = DDS_FALSE;

    vsco_f6115_attribution_effectivite_couples_moteur_couples_roue = (UInt8)VSCO_F6115_NON_ATTRIBUEE;
    vsctl_bendtranvsreg_local = (UInt32)DDS_TRUE;
    vsctl_bendtranvslim_local = (UInt32)DDS_TRUE;
    vsctl_bendtranvsmax_local = (UInt32)DDS_TRUE;


    /* VSCO_F6116_Min_Veh_Accel_Lim_Cons_Deter */

    /* VSCO_F61161_Min_Veh_Accel_Lim_Com_Mode_Deter */
    VSCtl_tiFilStCtlAVehMinSat  = VSCtl_tiFilStCtlAVehMinSat_C;
    VSCtl_stCtlaVehMinSat       = (UInt8)VSCO_STCTLAVEHMINSAT_ARRET;
    VSCtl_bAcv_aVehMinSat       = DDS_FALSE;


    /* VSCO_F61162_Min_Veh_Accel_Lim_Cons_Deter */
    VSCtl_jrkVehWhlMinSatRaw2 = VSCO_ACCEL_CONS_0_BIN7;
    VSCtl_jrkVehWhlMinSatRaw1 = VSCO_ACCEL_CONS_0_BIN7;
    VSCtl_jrkVehWhlMinSat     = VSCO_ACCEL_CONS_0_BIN7;
    VSCtl_aVehWhlMinSat       = VSCO_ACCEL_CONS_10_BIN10_NEG;
    vsctl_avehwhlminsat_prev = VSCO_ACCEL_CONS_10_BIN10_NEG;


}

#define VSCO_STOP_SEC_CODE
#include "VSCo_MemMap.h"

