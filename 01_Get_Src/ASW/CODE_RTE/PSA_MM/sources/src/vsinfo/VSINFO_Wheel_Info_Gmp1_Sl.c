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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Wheel_Info_Gmp1_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 8 m User:meme 
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSInfo11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 13 m User:demezil 
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSInfo11.0
* Version int :/main/L01_01/3 Date: 12/5/2011 8 h 47 m User:meme
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1_D
*    comments :FDS A0201611 / ALTIS_1596911
* Version dev :\main\branch_demezil_generic_view\1 Date: 10/5/2011 17 h 38 m User:demezil
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1_D
*    comments :FDS A0201611 / ALTIS_1596911
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 25 m User:meme
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0 : Correction after TU
* Version dev :\main\branch_morisseau_vsinfo_dev\12 Date: 3/3/2011 9 h 29 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0 : Correction after TU
* Version dev :\main\branch_morisseau_vsinfo_dev\11 Date: 9/2/2011 9 h 17 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\10 Date: 8/2/2011 9 h 14 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\9 Date: 7/2/2011 18 h 16 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for vSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 2/2/2011 17 h 45 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/1/2011 14 h 57 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 7/1/2011 11 h 36 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 6/1/2011 14 h 25 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :correc IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 14 h 33 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :add model
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 14 h 20 m User:morisseau
*    TWK_model:VSINFO_Wheel_Info_Gmp1_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 32 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSInfo 10.0
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSInfo.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define VSINFO_0                              (0)
#define VSINFO_10_BIN10                       (10 * BIN10)
#define VSINFO_10_BIN10_NEG                   (-10 * BIN10)
#define VSINFO_100_BIN7                       (100 * BIN7)
#define VSINFO_16000_BIN1                     (16000 * BIN1)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMax_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMin_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlThPTPotMin_pt1; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilPTInfo_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt1; /* BIN0 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
extern volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


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
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTAplReq_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMnReqRaw_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTIni_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLim_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMax_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMin_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTReal_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlThPTMin_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMn_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMx_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlRq_pt1; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt1_no1;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt1_no2;
VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPt1_no3;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_rSlopMax_tqWhlPTLim_C = (CONST(SInt16, AUTOMATIC))(-4 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTInipt1_Ini_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTLim_Max_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTLim_Min_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtlapt1Mn_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtlapt1Mx_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinCtlapt1_Max_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinCtlapt1_Min_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtlapt1Mn_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtlapt1Mx_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinThpt1_Max_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinThpt1_Min_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMaxCtlaTolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMaxCtlaTolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMaxCtlapt1_Max_C = (CONST(UInt16, AUTOMATIC))(11000 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMaxCtlapt1_Min_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtlaTolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtlaTolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMinCtlaTolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMinCtlaTolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtlaTolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtlaTolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bTqWhlThPTMinMod_C = DDS_FALSE;
#define VSINFO_STOP_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aVehLim_rSlop_T
[VSINFO_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(-0.5 * BIN10),
(SInt16)(-0.5 * BIN10), (SInt16)(-0.5 * BIN10)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_rSlop_aVehLim_A[VSINFO_8_SIZE] = {
(SInt16)(-8 * BIN7), (SInt16)(-7 * BIN7), (SInt16)(-6 * BIN7),
(SInt16)(-5 * BIN7), (SInt16)(-4 * BIN7), (SInt16)(-2 * BIN7),
(SInt16)(-1 * BIN7), (SInt16)(0 * BIN7)
};

#define VSINFO_STOP_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_avehlim_rslop_t_sav;
STATIC VAR(t_dds_m_filter_hyst_s16, AUTOMATIC) vsinfo_f11131_hyst_filter_min_str;
STATIC VAR(t_dds_m_filter_hyst_s16, AUTOMATIC) vsinfo_f11131_hyst_filter_max_str;
STATIC VAR(t_dds_m_filter_hyst_s32, AUTOMATIC) vsinfo_f111391_filter_struct;
STATIC VAR(t_dds_m_filter_hyst_s32, AUTOMATIC) vsinfo_f111392_filter_struct;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_stptinfo_pt1_loc; /* BIN0 */
STATIC VAR(UInt8, AUTOMATIC) vsinfo_bacvfilptinfo_pt1_loc;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPTLimRaw1_pt1; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPTLimRaw2_pt2; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPTLimRaw3_pt3; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLimRaw1_pt1; /* BIN1 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLimRaw2_pt1; /* BIN1 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLimRaw3_pt1; /* BIN1 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLimRaw4_pt1; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTLimRaw5_pt1; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxCtla_pt1; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinCtla_pt1; /* BIN1 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvReq_pt1; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSINFO_START_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) VSCTL_AVEHLIM_RSLOP_T_APM = {
&vsctl_avehlim_rslop_t_sav,
VSINFO_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rSlop_aVehLim_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aVehLim_rSlop_T[0]
};

#define VSINFO_STOP_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) VSINFO_F1112_Determiner_Disponibilite_Couple_Roue_Gmp(
                           UInt8 ext_bavltqwhlpt_no1_par,
                           UInt8 ext_bavltqwhlpt_no2_par,
                           UInt8 ext_bavltqwhlpt_no3_par);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1113_Determiner_Couples_Roue_GMP(
                           SInt16 ptlim_tqwhlptmaxctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptmaxnotctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptminctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptminnotctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlthptmin_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreqraw_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovscmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovscminreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovsctlreq_par, /* BIN1 */
                           SInt16 vehest_tqwhlptrealestim_par, /* BIN1 */
                           SInt16 vehest_tqwhlptreq_par, /* BIN1 */
                           SInt16 vsctl_aaero_par, /* BIN10 */
                           UInt16 vsctl_mveh_par, /* BIN0 */
                           UInt16 vsctl_rdwhl_par, /* BIN7 */
                           SInt16 vsctl_rslop_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11131_Determiner_Couples_Roue_Gmp_Pilotable_Min_Max(
                           SInt16 ptlim_tqwhlptmaxctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptminctla_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11132_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv_Min_Max(
                           SInt16 tqdem_tqwhlptprecovscmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovscminreq_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11133_Determiner_Couples_Roue_Gmp_Min_Max(void);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11134_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv(
                           SInt16 tqdem_tqwhlptprecovsctlreq_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11135_Determiner_Consignes_Couple_Roue_Gmp_Conducteur(
                           SInt16 tqdem_tqwhlptdrvmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreqraw_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvreq_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11136_Determiner_Consignes_Couple_Roue_Gmp_Appliquee(
                           SInt16 vehest_tqwhlptreq_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11137_Determiner_Couple_Roue_Gmp_Realisee(
                           SInt16 vehest_tqwhlptrealestim_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11138_Determiner_Couple_Roue_Gmp_Initialisation(void);

STATIC FUNC(void, AUTOMATIC) VSINFO_F111391_Determiner_Couple_Roue_Gmp_Min_Non_Pilotable(
                           SInt16 ptlim_tqwhlptminnotctla_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F111392_Determiner_Couple_Roue_Gmp_Max_Non_Pilotable(
                           SInt16 ptlim_tqwhlptmaxnotctla_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1113A_Determiner_Couple_Roue_Gmp_Min_Thermique(
                           SInt16 ptlim_tqwhlthptmin_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1113B_Determiner_Limitation_Couple_Roue_Gmp_Min(
                           SInt16 vsctl_aaero_par, /* BIN10 */
                           UInt16 vsctl_mveh_par, /* BIN0 */
                           SInt16 vsctl_rslop_par, /* BIN7 */
                           UInt16 vsctl_rdwhl_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1113B1_VSCtl_tqWhlPTLimRaw_Calc(
                           SInt16 vsctl_avehptlimraw, /* BIN10 */
                           UInt16 vsctl_mveh_par, /* BIN0 */
                           UInt16 vsctl_rdwhl_par, /* BIN7 */
                           CONSTP2VAR(SInt32, AUTOMATIC, AUTOMATIC) vsctl_tqwhlptlimraw /* BIN1 */);

/*******************************************************************************
*
* Function Name : VSINFO_Wheel_Info_Gmp1_Sl
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Wheel_Info_Gmp1_Sl(
                           UInt8 Ext_bAvlTqWhlPT_no1_swc_in,
                           UInt8 Ext_bAvlTqWhlPT_no2_swc_in,
                           UInt8 Ext_bAvlTqWhlPT_no3_swc_in,
                           SInt16 PtLim_tqWhlPTMaxCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTMinCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlThPTMin_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTDrvReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                           SInt16 TqDem_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
                           SInt16 VehEst_tqWhlPTRealEstim_swc_in, /* BIN1 */
                           SInt16 VehEst_tqWhlPTReq_swc_in, /* BIN1 */
                           SInt16 VSCtl_aAero_swc_in, /* BIN10 */
                           UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                           UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                           SInt16 VSCtl_rSlop_swc_in /* BIN7 */)
{
    vsinfo_stptinfo_pt1_loc = VSCtl_stPTInfo_pt1;
    vsinfo_bacvfilptinfo_pt1_loc = VSCtl_bAcvFilPTInfo_pt1;

    VSINFO_F1112_Determiner_Disponibilite_Couple_Roue_Gmp(
             Ext_bAvlTqWhlPT_no1_swc_in,
             Ext_bAvlTqWhlPT_no2_swc_in,
             Ext_bAvlTqWhlPT_no3_swc_in);


    VSINFO_F1113_Determiner_Couples_Roue_GMP(
             PtLim_tqWhlPTMaxCtla_swc_in, /* BIN1 */
             PtLim_tqWhlPTMaxNotCtla_swc_in, /* BIN1 */
             PtLim_tqWhlPTMinCtla_swc_in, /* BIN1 */
             PtLim_tqWhlPTMinNotCtla_swc_in, /* BIN1 */
             PtLim_tqWhlThPTMin_swc_in, /* BIN1 */
             TqDem_tqWhlPTDrvMaxReq_swc_in, /* BIN1 */
             TqDem_tqWhlPTDrvMinReq_swc_in, /* BIN1 */
             TqDem_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1 */
             TqDem_tqWhlPTDrvReq_swc_in, /* BIN1 */
             TqDem_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
             TqDem_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
             TqDem_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1 */
             VehEst_tqWhlPTRealEstim_swc_in, /* BIN1 */
             VehEst_tqWhlPTReq_swc_in, /* BIN1 */
             VSCtl_aAero_swc_in, /* BIN10 */
             VSCtl_mVeh_swc_in, /* BIN0 */
             VSCtl_rdWhl_swc_in, /* BIN7 */
             VSCtl_rSlop_swc_in /* BIN7 */);
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
*
* Function Name : VSINFO_F1112_Determiner_Disponibilite_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1112_Determiner_Disponibilite_Couple_Roue_Gmp(
                           UInt8 ext_bavltqwhlpt_no1_par,
                           UInt8 ext_bavltqwhlpt_no2_par,
                           UInt8 ext_bavltqwhlpt_no3_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.84.1 */

    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_bAvlTqWhlPt1_no1 = ext_bavltqwhlpt_no1_par;
        VSCtl_bAvlTqWhlPt1_no2 = ext_bavltqwhlpt_no2_par;
        VSCtl_bAvlTqWhlPt1_no3 = ext_bavltqwhlpt_no3_par;
    }
    else
    {
        VSCtl_bAvlTqWhlPt1_no1 = DDS_FALSE;
        VSCtl_bAvlTqWhlPt1_no2 = DDS_FALSE;
        VSCtl_bAvlTqWhlPt1_no3 = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11131_Determiner_Couples_Roue_Gmp_Pilotable_Min_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1113_Determiner_Couples_Roue_GMP(
                           SInt16 ptlim_tqwhlptmaxctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptmaxnotctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptminctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptminnotctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlthptmin_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreqraw_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovscmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovscminreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovsctlreq_par, /* BIN1 */
                           SInt16 vehest_tqwhlptrealestim_par, /* BIN1 */
                           SInt16 vehest_tqwhlptreq_par, /* BIN1 */
                           SInt16 vsctl_aaero_par, /* BIN10 */
                           UInt16 vsctl_mveh_par, /* BIN0 */
                           UInt16 vsctl_rdwhl_par, /* BIN7 */
                           SInt16 vsctl_rslop_par /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.05.2 */
    VSINFO_F11131_Determiner_Couples_Roue_Gmp_Pilotable_Min_Max(
                               ptlim_tqwhlptmaxctla_par, /* BIN1 */
                               ptlim_tqwhlptminctla_par /* BIN1 */);

    VSINFO_F11132_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv_Min_Max(
                               tqdem_tqwhlptprecovscmaxreq_par, /* BIN1 */
                               tqdem_tqwhlptprecovscminreq_par /* BIN1 */);

    VSINFO_F11133_Determiner_Couples_Roue_Gmp_Min_Max();

    VSINFO_F11134_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv(
                               tqdem_tqwhlptprecovsctlreq_par /* BIN1 */);

    VSINFO_F11135_Determiner_Consignes_Couple_Roue_Gmp_Conducteur(
                               tqdem_tqwhlptdrvmaxreq_par, /* BIN1 */
                               tqdem_tqwhlptdrvminreq_par, /* BIN1 */
                               tqdem_tqwhlptdrvminreqraw_par, /* BIN1 */
                               tqdem_tqwhlptdrvreq_par /* BIN1 */);

    VSINFO_F11136_Determiner_Consignes_Couple_Roue_Gmp_Appliquee(
                               vehest_tqwhlptreq_par /* BIN1 */);

    VSINFO_F11137_Determiner_Couple_Roue_Gmp_Realisee(
                               vehest_tqwhlptrealestim_par /* BIN1 */);

    VSINFO_F11138_Determiner_Couple_Roue_Gmp_Initialisation();

    VSINFO_F111391_Determiner_Couple_Roue_Gmp_Min_Non_Pilotable(
                               ptlim_tqwhlptminnotctla_par /* BIN1 */);

    VSINFO_F111392_Determiner_Couple_Roue_Gmp_Max_Non_Pilotable(
                               ptlim_tqwhlptmaxnotctla_par /* BIN1 */);

    VSINFO_F1113A_Determiner_Couple_Roue_Gmp_Min_Thermique(
                               ptlim_tqwhlthptmin_par /* BIN1 */);

    VSINFO_F1113B_Determiner_Limitation_Couple_Roue_Gmp_Min(
                               vsctl_aaero_par, /* BIN10 */
                               vsctl_mveh_par, /* BIN0 */
                               vsctl_rslop_par, /* BIN7 */
                               vsctl_rdwhl_par /* BIN7 */);
}

/*******************************************************************************
*
* Function Name : VSINFO_F11131_Determiner_Couples_Roue_Gmp_Pilotable_Min_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11131_Determiner_Couples_Roue_Gmp_Pilotable_Min_Max(
                           SInt16 ptlim_tqwhlptmaxctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptminctla_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.137.0 */
    SInt16 vasinfo_s16_svalue;
    SInt16 vsinfo_filter_min_out;
    SInt16 vsinfo_filter_max_out;

    /* Calculation of VSCtl_tqWhlPTMinCtla_pt1 */
    vasinfo_s16_svalue = (SInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptminctla_par,
                                                     (SInt32)VSCtl_tqWhlPTMinCtlapt1_Min_C,
                                                     (SInt32)VSCtl_tqWhlPTMinCtlapt1_Max_C);

    vsinfo_filter_min_out = DDS_M_FILTER_HYST_S16(&vsinfo_f11131_hyst_filter_min_str,
                                                  vasinfo_s16_svalue,
                                                  VSCtl_tqWhlPTMinCtlaTolP_C,
                                                  VSCtl_tqWhlPTMinCtlaTolN_C,
                                                  vsinfo_bacvfilptinfo_pt1_loc);

    /* Calculation of VSCtl_tqWhlPTMaxCtla_pt1 */
    vasinfo_s16_svalue = (SInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptmaxctla_par,
                                                     (SInt32)VSCtl_tqWhlPTMaxCtlapt1_Min_C,
                                                     (SInt32)VSCtl_tqWhlPTMaxCtlapt1_Max_C);

    vsinfo_filter_max_out = DDS_M_FILTER_HYST_S16(&vsinfo_f11131_hyst_filter_max_str,
                                                  vasinfo_s16_svalue,
                                                  VSCtl_tqWhlPTMaxCtlaTolP_C,
                                                  VSCtl_tqWhlPTMaxCtlaTolN_C,
                                                  vsinfo_bacvfilptinfo_pt1_loc);


    /* Set Output */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTMinCtla_pt1 = vsinfo_filter_min_out;
        VSCtl_tqWhlPTMaxCtla_pt1 = vsinfo_filter_max_out;
    }
    else
    {
        VSCtl_tqWhlPTMinCtla_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTMaxCtla_pt1 = (SInt16)VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11132_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv_Min_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11132_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv_Min_Max(
                           SInt16 tqdem_tqwhlptprecovscmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptprecovscminreq_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.138.0 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTPreCVSCtlMn_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptprecovscminreq_par,
                                                                   (SInt32)-VSINFO_16000_BIN1,
                                                                   (SInt32)VSINFO_0);

        VSCtl_tqWhlPTPreCVSCtlMx_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptprecovscmaxreq_par,
                                                                   (SInt32)VSINFO_0,
                                                                   (SInt32)VSINFO_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlPTPreCVSCtlMn_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPreCVSCtlMx_pt1 = (SInt16)VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11133_Determiner_Couples_Roue_Gmp_Min_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11133_Determiner_Couples_Roue_Gmp_Min_Max(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.12.3 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTMin_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPTPreCVSCtlMn_pt1,
                                                           (SInt32)VSCtl_tqWhlPTMinCtla_pt1,
                                                           (SInt32)VSINFO_0);

        VSCtl_tqWhlPTMax_pt1 = (SInt16)DDS_M_LIMIT_V2((SInt32)VSCtl_tqWhlPTPreCVSCtlMx_pt1,
                                                      (SInt32)VSINFO_0,
                                                      (SInt32)VSCtl_tqWhlPTMaxCtla_pt1);
    }
    else
    {
        VSCtl_tqWhlPTMin_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTMax_pt1 = (SInt16)VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11134_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11134_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv(
                           SInt16 tqdem_tqwhlptprecovsctlreq_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.13.1 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTPreCVSCtlRq_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptprecovsctlreq_par,
                                                                   (SInt32)VSCtl_tqWhlPTPotMin_pt1,
                                                                   (SInt32)VSCtl_tqWhlPTPotMax_pt1);
    }
    else
    {
        VSCtl_tqWhlPTPreCVSCtlRq_pt1 = VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11135_Determiner_Consignes_Couple_Roue_Gmp_Conducteur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11135_Determiner_Consignes_Couple_Roue_Gmp_Conducteur(
                           SInt16 tqdem_tqwhlptdrvmaxreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreq_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvminreqraw_par, /* BIN1 */
                           SInt16 tqdem_tqwhlptdrvreq_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.14.2 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTDrvMaxReq_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptdrvmaxreq_par,
                                                           (SInt32)VSINFO_0,
                                                           (SInt32)VSINFO_16000_BIN1);

        VSCtl_tqWhlPTDrvMinReq_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptdrvminreq_par,
                                                           (SInt32)-VSINFO_16000_BIN1,
                                                           (SInt32)VSINFO_0);

        VSCtl_tqWhlPTDrvMnReqRaw_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptdrvminreqraw_par,
                                                           (SInt32)-VSINFO_16000_BIN1,
                                                           (SInt32)VSINFO_0);

        VSCtl_tqWhlPTDrvReq_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqwhlptdrvreq_par,
                                                           (SInt32)VSCtl_tqWhlPTDrvMinReq_pt1,
                                                           (SInt32)VSCtl_tqWhlPTDrvMaxReq_pt1);
    }
    else
    {
        VSCtl_tqWhlPTDrvMaxReq_pt1 = (SInt16)VSINFO_16000_BIN1;
        VSCtl_tqWhlPTDrvReq_pt1 = (SInt16)VSINFO_0;
        VSCtl_tqWhlPTDrvMinReq_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTDrvMnReqRaw_pt1 = (SInt16)-VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11136_Determiner_Consignes_Couple_Roue_Gmp_Appliquee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11136_Determiner_Consignes_Couple_Roue_Gmp_Appliquee(
                           SInt16 vehest_tqwhlptreq_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.139.0 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTAplReq_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)vehest_tqwhlptreq_par,
                                                              (SInt32)VSCtl_tqWhlPTMin_pt1,
                                                              (SInt32)VSCtl_tqWhlPTMax_pt1);
    }
    else
    {
        VSCtl_tqWhlPTAplReq_pt1 = (SInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11137_Determiner_Couple_Roue_Gmp_Realisee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11137_Determiner_Couple_Roue_Gmp_Realisee(
                           SInt16 vehest_tqwhlptrealestim_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.19.1 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTReal_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)vehest_tqwhlptrealestim_par,
                                                            (SInt32)VSCtl_tqWhlPTMin_pt1,
                                                            (SInt32)VSCtl_tqWhlPTMax_pt1);
    }
    else
    {
        VSCtl_tqWhlPTReal_pt1 = (SInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11138_Determiner_Couple_Roue_Gmp_Initialisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11138_Determiner_Couple_Roue_Gmp_Initialisation(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.20.3 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTIni_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPTInipt1_Ini_C,
                                                           (SInt32)VSCtl_tqWhlPTMin_pt1,
                                                           (SInt32)VSCtl_tqWhlPTMax_pt1);
    }
    else
    {
        VSCtl_tqWhlPTIni_pt1 = (SInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F111391_Determiner_Couple_Roue_Gmp_Min_Non_Pilotable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F111391_Determiner_Couple_Roue_Gmp_Min_Non_Pilotable(
                           SInt16 ptlim_tqwhlptminnotctla_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.131.1 */
    SInt32 vsctl_tqwhlptminnotctla_pt1_tmp;

    /* [-16000; 16000] BIN1 */
    vsctl_tqwhlptminnotctla_pt1_tmp = DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptminnotctla_par,
                                                          (SInt32)VSCtl_tqWhlPTMinNotCtlapt1Mn_C,
                                                          (SInt32)VSCtl_tqWhlPTMinNotCtlapt1Mx_C);
    /* filtering */
    /* [-16000; 16000] BIN1 */
    vsctl_tqwhlptminnotctla_pt1_tmp = DDS_M_FILTER_HYST_S32(&vsinfo_f111391_filter_struct,
                                                            vsctl_tqwhlptminnotctla_pt1_tmp,
                                                            (UInt32)VSCtl_tqWhlPTMinNotCtlaTolP_C,
                                                            (UInt32)VSCtl_tqWhlPTMinNotCtlaTolN_C,
                                                            vsinfo_bacvfilptinfo_pt1_loc);

    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTMinNotCtla_pt1 = (SInt16)DDS_M_SATURATION_V2(vsctl_tqwhlptminnotctla_pt1_tmp,
                                                                  (SInt32)VSCtl_tqWhlPTMin_pt1,
                                                                  (SInt32)VSCtl_tqWhlPTMax_pt1);
    }
    else
    {
        /* default */
        VSCtl_tqWhlPTMinNotCtla_pt1 = (SInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F111392_Determiner_Couple_Roue_Gmp_Max_Non_Pilotable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F111392_Determiner_Couple_Roue_Gmp_Max_Non_Pilotable(
                           SInt16 ptlim_tqwhlptmaxnotctla_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.132.1 */
    SInt32 vsctl_tqwhlptmaxnotctla_pt1_tmp;

    /* [-16000; 16000] BIN1 */
    vsctl_tqwhlptmaxnotctla_pt1_tmp = DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptmaxnotctla_par,
                                                          (SInt32)VSCtl_tqWhlPTMaxNotCtlapt1Mn_C,
                                                          (SInt32)VSCtl_tqWhlPTMaxNotCtlapt1Mx_C);
    /* filtering */
    /* [-16000; 16000] BIN1 */
    vsctl_tqwhlptmaxnotctla_pt1_tmp = DDS_M_FILTER_HYST_S32(&vsinfo_f111392_filter_struct,
                                                            vsctl_tqwhlptmaxnotctla_pt1_tmp,
                                                            (UInt32)VSCtl_tqWhlPTMaxNotCtlaTolP_C,
                                                            (UInt32)VSCtl_tqWhlPTMaxNotCtlaTolN_C,
                                                            vsinfo_bacvfilptinfo_pt1_loc);

    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTMaxNotCtla_pt1 = (SInt16)DDS_M_SATURATION_V2(vsctl_tqwhlptmaxnotctla_pt1_tmp,
                                                                  (SInt32)VSCtl_tqWhlPTMinNotCtla_pt1,
                                                                  (SInt32)VSCtl_tqWhlPTMax_pt1);
    }
    else
    {
        /* default */
        VSCtl_tqWhlPTMaxNotCtla_pt1 = (SInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1113a_Determiner_Couple_Roue_Gmp_Min_Thermique
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1113A_Determiner_Couple_Roue_Gmp_Min_Thermique(
                           SInt16 ptlim_tqwhlthptmin_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.134.1 */
    if(  ((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)vsinfo_stptinfo_pt1_loc == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlThPTMin_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlthptmin_par,
                                                           (SInt32)VSCtl_tqWhlPTMinThpt1_Min_C,
                                                           (SInt32)VSCtl_tqWhlPTMinThpt1_Max_C);
    }
    else
    {
        VSCtl_tqWhlThPTMin_pt1 = (SInt16)-VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1113b_Determiner_Limitation_Couple_Roue_Gmp_Min
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1113B_Determiner_Limitation_Couple_Roue_Gmp_Min(
                           SInt16 vsctl_aaero_par, /* BIN10 */
                           UInt16 vsctl_mveh_par, /* BIN0 */
                           SInt16 vsctl_rslop_par, /* BIN7 */
                           UInt16 vsctl_rdwhl_par /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.135.1 */
    SInt32 temp1_s32;

    SInt32 vsctl_tqwhlptlimraw4_pt1_loc; /* BIN3 */
    SInt32 vsctl_tqwhlptlimraw3_pt1_loc; /* BIN3 */
    SInt32 vsctl_tqwhlptlimraw2_pt1_loc; /* BIN3 */

    if ((2 == (UInt32)vsinfo_stptinfo_pt1_loc)||
        (3 == (UInt32)vsinfo_stptinfo_pt1_loc))
    {
        /*---VSCtl_aVehPTLimRaw1_pt1---*/
        /* [-10;10]BIN10 */
        VSCtl_aVehPTLimRaw1_pt1 = DDS_M_MAP2D_S16(&VSCTL_AVEHLIM_RSLOP_T_APM, vsctl_rslop_par);

        /*---VSCtl_aVehPTLimRaw2_pt2---*/
        /* [-10;10]BIN10 */
        VSCtl_aVehPTLimRaw2_pt2 = vsctl_aaero_par;

        /*---VSCtl_aVehPTLimRaw3_pt3---*/
        /* BIN10 = BIN7 * BIN0 * BIN3 / BIN0 */
        /* [-1.96; 1.96] = [-20; 20] * -98 / 1000 */
        VSCtl_aVehPTLimRaw3_pt3 = (SInt16)(((DDS_M_MAX((SInt32)vsctl_rslop_par, (SInt32)VSCtl_rSlopMax_tqWhlPTLim_C)) * (SInt32)(-98 * BIN3))
                                            / (SInt32)1000);

        /*---VSCtl_tqWhlPTLimRaw5_pt1---*/
        if ((SInt32)DDS_TRUE == (SInt32)VSCtl_bTqWhlThPTMinMod_C)
        {
            /* BIN1:[-16000;16000] = BIN1:[-16000;16000] */
            VSCtl_tqWhlPTLimRaw5_pt1 = VSCtl_tqWhlThPTPotMin_pt1;
        }
        else
        {
            /* BIN1:[-16000;16000] = BIN1:[-16000;16000] */
            VSCtl_tqWhlPTLimRaw5_pt1 = VSCtl_tqWhlThPTMin_pt1;
        }

        /*---VSCtl_tqWhlPTLimRaw4_pt1---*/
        VSINFO_F1113B1_VSCtl_tqWhlPTLimRaw_Calc(
                                   VSCtl_aVehPTLimRaw3_pt3,         /* BIN10 */
                                   vsctl_mveh_par,                  /* BIN0 */
                                   vsctl_rdwhl_par,                 /* BIN7 */
                                   &vsctl_tqwhlptlimraw4_pt1_loc);  /* BIN1 */

        VSCtl_tqWhlPTLimRaw4_pt1 = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptlimraw4_pt1_loc,
                                                       -VSINFO_16000_BIN1,
                                                       VSINFO_16000_BIN1);




        /*---VSCtl_tqWhlPTLimRaw3_pt1---*/
        VSINFO_F1113B1_VSCtl_tqWhlPTLimRaw_Calc(
                                   VSCtl_aVehPTLimRaw2_pt2,         /* BIN10 */
                                   vsctl_mveh_par,                  /* BIN0 */
                                   vsctl_rdwhl_par,                 /* BIN7 */
                                   &vsctl_tqwhlptlimraw3_pt1_loc    /* BIN1 */);

        VSCtl_tqWhlPTLimRaw3_pt1 = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptlimraw3_pt1_loc,
                                                       -VSINFO_16000_BIN1,
                                                       VSINFO_16000_BIN1);




        /*---VSCtl_tqWhlPTLimRaw2_pt1---*/
        VSINFO_F1113B1_VSCtl_tqWhlPTLimRaw_Calc(
                                   VSCtl_aVehPTLimRaw1_pt1,         /* BIN10 */
                                   vsctl_mveh_par,                  /* BIN0 */
                                   vsctl_rdwhl_par,                 /* BIN7 */
                                   &vsctl_tqwhlptlimraw2_pt1_loc    /* BIN0 */);

        VSCtl_tqWhlPTLimRaw2_pt1 = (SInt16)DDS_M_LIMIT(vsctl_tqwhlptlimraw2_pt1_loc,
                                                       -VSINFO_16000_BIN1,
                                                       VSINFO_16000_BIN1);




        /*---VSCtl_tqWhlPTLimRaw1_pt1---*/
        /* BIN1 = BIN1 - BIN1 - BIN1 - BIN1 */
        /* [-4000000; 4000000] = [-1000000;1000000] - [-1000000;1000000] - [-1000000;1000000] - [-1000000;1000000] */
        temp1_s32 = ((vsctl_tqwhlptlimraw2_pt1_loc
                    - vsctl_tqwhlptlimraw3_pt1_loc)
                    - vsctl_tqwhlptlimraw4_pt1_loc)
                    - (SInt32)VSCtl_tqWhlPTLimRaw5_pt1;

        VSCtl_tqWhlPTLimRaw1_pt1 = (SInt16)DDS_M_LIMIT(temp1_s32, -VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        /* <PRQA_COMMENT><0272> Tool error: datatype conversion is done correctly </0272></PRQA_COMMENT> */
        VSCtl_tqWhlPTLim_pt1 = (SInt16)DDS_M_SATURATION_V2(temp1_s32,
                                                           (SInt32)VSCtl_tqWhlPTLim_Min_C,
                                                           (SInt32)VSCtl_tqWhlPTLim_Max_C);
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* default */
        VSCtl_aVehPTLimRaw1_pt1 = (SInt16)VSINFO_10_BIN10_NEG;
        VSCtl_aVehPTLimRaw2_pt2 = (SInt16)VSINFO_10_BIN10_NEG;
        VSCtl_aVehPTLimRaw3_pt3 = (SInt16)VSINFO_10_BIN10_NEG;

        VSCtl_tqWhlPTLim_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTLimRaw1_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTLimRaw2_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTLimRaw3_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTLimRaw4_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTLimRaw5_pt1 = (SInt16)-VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1113B1_VSCtl_tqWhlPTLimRaw_Calc
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1113B1_VSCtl_tqWhlPTLimRaw_Calc(
                           SInt16 vsctl_avehptlimraw, /* BIN10 */
                           UInt16 vsctl_mveh_par, /* BIN0 */
                           UInt16 vsctl_rdwhl_par, /* BIN7 */
                           CONSTP2VAR(SInt32, AUTOMATIC, AUTOMATIC) vsctl_tqwhlptlimraw /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.135.1 */
    SInt32 mult1_s32;
    SInt32 mult1_s32_small;

   /* vsctl_mveh_par    [1;10000]BIN0   A parameter */

   /* vsctl_rdwhl_par   [1/128;10]BIN7  B parameter */
   /* 3 cases possible  [-10;10]BIN10   C parameter  VSCtl_aVehPTLimRaw1_pt1 or VSCtl_aVehPTLimRaw1_pt2 or VSCtl_aVehPTLimRaw1_pt3 */
   /* (B * C) parameter [-100;100]BIN17 D parameter */

   mult1_s32        = (SInt32)vsctl_rdwhl_par * (SInt32)vsctl_avehptlimraw;     /* [-100;100]BIN17 */
   mult1_s32_small  = mult1_s32 % BIN16;

   mult1_s32        = ((mult1_s32 / BIN16) * (SInt32)vsctl_mveh_par) + ((mult1_s32_small * (SInt32)vsctl_mveh_par) / BIN16);

   *vsctl_tqwhlptlimraw = mult1_s32;    /* [-1000000;1000000]BIN1 */
}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Wheel_Info_Gmp1_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Wheel_Info_Gmp1_Sl_Init(void)
{
    /* ---- Init Outputs ---- */
    VSCtl_bAvlTqWhlPt1_no1 = DDS_FALSE;
    VSCtl_bAvlTqWhlPt1_no2 = DDS_FALSE;
    VSCtl_bAvlTqWhlPt1_no3 = DDS_FALSE;
    VSCtl_tqWhlPTAplReq_pt1 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTDrvMaxReq_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTDrvMinReq_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTDrvMnReqRaw_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTIni_pt1 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTLim_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTMax_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTMaxNotCtla_pt1 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTMin_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTMinNotCtla_pt1 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTPreCVSCtlMn_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPreCVSCtlMx_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPreCVSCtlRq_pt1 = VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
    VSCtl_tqWhlPTReal_pt1 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlThPTMin_pt1 = (SInt16)(-16000 * BIN1);

    /* ---- Init Global Datas ---- */
    VSCtl_aVehPTLimRaw1_pt1 = (SInt16)(-10 * BIN10);
    VSCtl_aVehPTLimRaw2_pt2 = (SInt16)(-10 * BIN10);
    VSCtl_aVehPTLimRaw3_pt3 = (SInt16)(-10 * BIN10);
    VSCtl_tqWhlPTDrvReq_pt1 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTLimRaw1_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTLimRaw2_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTLimRaw3_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTLimRaw4_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTLimRaw5_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTMaxCtla_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTMinCtla_pt1 = (SInt16)(0 * BIN1);

    /* ---- VSINFO_F1112_Determiner_Disponibilite_Couple_Roue_Gmp ---- */

    /* ---- VSINFO_F11131_Determiner_Couples_Roue_Gmp_Pilotable_Min_Max ---- */
    DDS_M_FILTER_HYST_S16_INIT(&vsinfo_f11131_hyst_filter_min_str,DDS_FALSE);
    DDS_M_FILTER_HYST_S16_INIT(&vsinfo_f11131_hyst_filter_max_str,DDS_FALSE);

    /* ---- VSINFO_F11132_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv_Min_Max ---- */

    /* ---- VSINFO_F11133_Determiner_Couples_Roue_Gmp_Min_Max ---- */

    /* ---- VSINFO_F11134_Determiner_Consigne_Couple_Roue_Gmp_Pre_Coord_Xvv ---- */

    /* ---- VSINFO_F11135_Determiner_Consignes_Couple_Roue_Gmp_Conducteur ---- */

    /* ---- VSINFO_F11136_Determiner_Consignes_Couple_Roue_Gmp_Appliquee ---- */

    /* ---- VSINFO_F11137_Determiner_Couple_Roue_Gmp_Realisee ---- */

    /* ---- VSINFO_F11138_Determiner_Couple_Roue_Gmp_Initialisation ---- */

    /* ---- VSINFO_F111391_Determiner_Couple_Roue_Gmp_Min_Non_Pilotable ---- */
    DDS_M_FILTER_HYST_S32_INIT(&vsinfo_f111391_filter_struct, 0);

    /* ---- VSINFO_F111392_Determiner_Couple_Roue_Gmp_Max_Non_Pilotable ---- */
    DDS_M_FILTER_HYST_S32_INIT(&vsinfo_f111392_filter_struct, 0);

    /* ---- VSINFO_F1113A_Determiner_Couple_Roue_Gmp_Min_Thermique ---- */

    /* ---- VSINFO_F1113B_Determiner_Limitation_Couple_Roue_Gmp_Min ---- */
}



#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

