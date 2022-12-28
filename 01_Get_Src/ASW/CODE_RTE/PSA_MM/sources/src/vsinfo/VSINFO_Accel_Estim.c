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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Accel_Estim.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 5 m User:meme 
*    TWK_model:VSINFO_Accel_Estim_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\3 Date: 28/7/2011 15 h 52 m User:demezil 
*    TWK_model:VSINFO_Accel_Estim_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 27/7/2011 9 h 55 m User:demezil
*    TWK_model:VSINFO_Accel_Estim_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 4 m User:demezil
*    TWK_model:VSINFO_Accel_Estim_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 17 m User:meme
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 25/2/2011 11 h 17 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 16 m User:meme
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :validation correction
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 4/2/2011 10 h 17 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :validation correction
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 2/2/2011 18 h 39 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :Correct code shaker error
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 2/2/2011 17 h 27 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :correct undisplayable data name
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 7/1/2011 11 h 36 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 6/1/2011 14 h 25 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :correc IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 20/12/2010 18 h 1 m User:morisseau
*    TWK_model:VSINFO_Accel_Estim_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 20/12/2010 17 h 3 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 16 h 44 m User:morisseau
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

/* NONE */


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
extern VAR(UInt16, AUTOMATIC) VSCtl_SCXVeh; /* BIN7 */
extern VAR(SInt16, AUTOMATIC) VSCtl_aBrk; /* BIN10 */
extern VAR(UInt16, AUTOMATIC) VSCtl_spdVehFil;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPT;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTAplReq;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTDrvMinReq;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTDrvMinReqRaw;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTIni;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTLim;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTPotMaxCtla_no1;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTMinNotCtla;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTMax;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTMaxNotCtla;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTMin;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTPotMax;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTPotMin;
extern VAR(SInt16, AUTOMATIC) VSCtl_aPTPreCoVSCtlReq;
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stObsDyn;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilVehInfo;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"

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
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aRes_SatMax_C = (CONST(UInt16, AUTOMATIC))(3 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aRes_SatMin_C = (CONST(SInt16, AUTOMATIC))(-3 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aAero_SatMax_C = (CONST(UInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aAero_SatMin_C = (CONST(SInt16, AUTOMATIC))(-1.2607421875 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aResRoad_SatMax_C = (CONST(UInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aResRoad_SatMin_C = (CONST(SInt16, AUTOMATIC))(0 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aSlop_SatMax_C = (CONST(UInt16, AUTOMATIC))(2 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aSlop_SatMin_C = (CONST(SInt16, AUTOMATIC))(-2 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rSlop_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_rSlop_SatMax_C = (CONST(SInt16, AUTOMATIC))(15 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_rSlop_SatMin_C = (CONST(SInt16, AUTOMATIC))(-15 * BIN7);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 32-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_32BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsAResAntiSatGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0.04 * BIN14), (SInt32)(1.1727 * BIN14), (SInt32)(1 * BIN14),
(SInt32)(-1.1727 * BIN14), (SInt32)(0.04 * BIN14) },
{
(SInt32)(0.006 * BIN14), (SInt32)(0.5657 * BIN14), (SInt32)(0.2835 * BIN14),
(SInt32)(0.1508 * BIN14), (SInt32)(0.006 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsAResIniGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(1 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) },
{
(SInt32)(-1 * BIN14), (SInt32)(0 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(0 * BIN14), (SInt32)(0 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsAResStabDynGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0.04 * BIN14), (SInt32)(0.1038 * BIN14), (SInt32)(1 * BIN14),
(SInt32)(-0.1038 * BIN14), (SInt32)(0.04 * BIN14) },
{
(SInt32)(0.006 * BIN14), (SInt32)(0.1132 * BIN14), (SInt32)(0.2835 * BIN14),
(SInt32)(0.6033 * BIN14), (SInt32)(0.006 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(0.0751 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(-0.0751 * BIN14), (SInt32)(1 * BIN14) }
};

STATIC volatile CONST(SInt32, AUTOMATIC) VSCtl_prmObsAResTranDynGain_M
[VSINFO_V_DYN_MAP_M_Y][VSINFO_V_DYN_MAP_M_X] = {
{
(SInt32)(0.04 * BIN14), (SInt32)(0.1354 * BIN14), (SInt32)(1 * BIN14),
(SInt32)(-0.1354 * BIN14), (SInt32)(0.04 * BIN14) },
{
(SInt32)(0.006 * BIN14), (SInt32)(0.1414 * BIN14), (SInt32)(0.2835 * BIN14),
(SInt32)(0.5751 * BIN14), (SInt32)(0.006 * BIN14) },
{
(SInt32)(0 * BIN14), (SInt32)(0.1237 * BIN14), (SInt32)(0 * BIN14),
(SInt32)(-0.1237 * BIN14), (SInt32)(1 * BIN14) }
};

#define VSINFO_STOP_SEC_CARTO_32BIT
#include "VSInfo_MemMap.h"

/* 16-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aResRoad_spdVeh_T
[VSINFO_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_aResRoad_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

#define VSINFO_STOP_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_aresroad_spdveh_t_sav;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_rslop_filter_struct;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* 32-bits variable definition */
#define VSINFO_START_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) vsinfo_f1466_matrix_out_1[VSINFO_V_DYN_MAP_M_Y];       /* BIN20 */
STATIC VAR(SInt32, AUTOMATIC) vsinfo_f1466_matrix_out_1_prev[VSINFO_V_DYN_MAP_M_Y];  /* BIN14 */
#define VSINFO_STOP_SEC_VAR_32BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_stobsdyn_cpy;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aResRoad; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aSlop; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehEstim_no3; /* BIN7 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_spdVehMesEstim_no3; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aResEstim_no3; /* BIN10 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aVehPTAplReq; /* BIN10 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSINFO_START_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_ARESROAD_SPDVEH_T_APM = {
&vsctl_aresroad_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_aResRoad_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aResRoad_spdVeh_T[0]
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

STATIC FUNC(void, AUTOMATIC) VSINFO_F1466_Estimer_Acceleration_Resistante(
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_ares_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1467_Determiner_Acceleration_Aerodynamique(
                                 UInt16 vsctl_mveh_par, /* BIN0 */
                                 UInt16 vsctl_spdveh_par, /* BIN7 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aaero_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1468_Determiner_Acceleration_Pneu(
                                 UInt16 vsctl_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1469_Determiner_Acceleration_Pente(
                                 SInt16 vsctl_aaero_par, /* BIN10 */
                                 SInt16 vsctl_ares_par /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F146A_Determiner_Pente(
                                 UInt8 vsctl_stvehinfo_par,
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_rslop_ptr /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F147_Determiner_Accelerations_Vehicule(
                                           SInt16 vsctl_ares_par, /* BIN10 */
                                           UInt8 vsctl_stvehinfo_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehprecovsctlreq_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptdrvminreq_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptdrvminreqraw_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptini_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptlim_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptmax_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptmaxnotctla_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptmin_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptminnotctla_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptpotmaxctla_no1_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptpotmax_ptr,/* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptpotmin_ptr /* BIN10 */);

/*******************************************************************************
*
* Function Name : VSINFO_Accel_Estim
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Accel_Estim(
                            UInt8 VSCtl_stVehInfo_swc_in,
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aAero_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aRes_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReq_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReqRaw_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTIni_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTLim_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMax_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMaxNotCtla_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMin_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMinNotCtla_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMax_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMaxCtla_no1_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMin_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPreCoVSCtlReq_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_swc_out /* BIN7 */)
{
    SInt16 vsctl_aaero_loc;
    SInt16 vsctl_ares_loc;

    vsctl_stobsdyn_cpy = VSCtl_stObsDyn;

    VSINFO_F1466_Estimer_Acceleration_Resistante(
                            &vsctl_ares_loc /* BIN10 */);
    *VSCtl_aRes_swc_out = vsctl_ares_loc;

    VSINFO_F1467_Determiner_Acceleration_Aerodynamique(
                            VSCtl_mVeh_swc_in, /* BIN0 */
                            VSCtl_spdVeh_swc_in, /* BIN7 */
                            &vsctl_aaero_loc  /* BIN10 */);
    *VSCtl_aAero_swc_out = vsctl_aaero_loc;

    VSINFO_F1468_Determiner_Acceleration_Pneu(
                            VSCtl_spdVeh_swc_in /* BIN7 */);

    VSINFO_F1469_Determiner_Acceleration_Pente(
                            vsctl_aaero_loc, /* BIN10 */
                            vsctl_ares_loc /* BIN10 */);

    VSINFO_F146A_Determiner_Pente(
                            VSCtl_stVehInfo_swc_in,
                            VSCtl_rSlop_swc_out /* BIN7 */);

    VSINFO_F147_Determiner_Accelerations_Vehicule(
                            vsctl_ares_loc, /* BIN10 */
                            VSCtl_stVehInfo_swc_in,
                            VSCtl_aVehPreCoVSCtlReq_swc_out, /* BIN10 */
                            VSCtl_aVehPTDrvMinReq_swc_out, /* BIN10 */
                            VSCtl_aVehPTDrvMinReqRaw_swc_out, /* BIN10 */
                            VSCtl_aVehPTIni_swc_out, /* BIN10 */
                            VSCtl_aVehPTLim_swc_out, /* BIN10 */
                            VSCtl_aVehPTMax_swc_out, /* BIN10 */
                            VSCtl_aVehPTMaxNotCtla_swc_out, /* BIN10 */
                            VSCtl_aVehPTMin_swc_out, /* BIN10 */
                            VSCtl_aVehPTMinNotCtla_swc_out, /* BIN10 */
                            VSCtl_aVehPTPotMaxCtla_no1_swc_out, /* BIN10 */
                            VSCtl_aVehPTPotMax_swc_out, /* BIN10 */
                            VSCtl_aVehPTPotMin_swc_out /* BIN10 */);
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

/*******************************************************************************
*
* Function Name : VSINFO_F1466_Estimer_Acceleration_Resistante
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1466_Estimer_Acceleration_Resistante(
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_ares_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.119.1 */
    SInt32 vsinfo_matrix_2[VSINFO_V_DYN_MAP_M_X];
    SInt32 var_out_1,var_out_2,var_out_3;               /* BIN7 */

    P2VAR(SInt32, AUTOMATIC, AUTOMATIC) vsinfo_matrix_1;   /* BIN14 */

    switch((UInt32)vsctl_stobsdyn_cpy)
    {
        case (UInt32)VSCTL_STOBSDYN_INIT:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAResIniGain_M;            /*[-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_TRANSITOIRE:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAResTranDynGain_M;         /* [-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_STABILISE:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAResStabDynGain_M;         /* [-10;10] BIN14 */
            break;
        case (UInt32)VSCTL_STOBSDYN_ANTISATURATION:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAResAntiSatGain_M;         /* [-10;10] BIN14 */
            break;
        default:
            /* <PRQA_COMMENT><0310> Tool error on cast </0310></PRQA_COMMENT> */
            vsinfo_matrix_1 = (P2VAR(SInt32, AUTOMATIC, AUTOMATIC))VSCtl_prmObsAResIniGain_M;            /* [-10;10] BIN14 */
            break;
    }


    vsinfo_matrix_2[0] = ((SInt32)VSCtl_aBrk + (SInt32)VSCtl_aPT) * BIN4;      /* [-20;20] BIN14 */

    vsinfo_matrix_2[1] = ((SInt32)VSCtl_spdVehFil * 10 * BIN7) / 36;           /* [0;70] BIN14 */

    vsinfo_matrix_2[2] = vsinfo_f1466_matrix_out_1_prev[0] ;                                /* BIN14 */

    vsinfo_matrix_2[3] = vsinfo_f1466_matrix_out_1_prev[1] ;                                /* BIN14 */

    vsinfo_matrix_2[4] = vsinfo_f1466_matrix_out_1_prev[2] ;                                /* BIN14 */


    VSINFOH_Dds_M_Prod_Matrix_SInt32(vsinfo_matrix_1,
                                 (UInt8)VSINFO_V_DYN_MAP_M_Y, (UInt8)VSINFO_V_DYN_MAP_M_X,
                                 14,
                                 vsinfo_matrix_2,
                                 1,
                                 14,
                                 vsinfo_f1466_matrix_out_1,
                                 20);

    /*   ((vsinfo_f1466_matrix_out_1 * 36) / 10) / BIN13 = ((vsinfo_f1466_matrix_out_1 * 18) / 5) / BIN13 */
    /* = ((vsinfo_f1466_matrix_out_1 * 18) / 20) / BIN11 */
    /*   ((vsinfo_f1466_matrix_out_1 * 9) / 10)  / BIN11  */
    /*      (vsinfo_f1466_matrix_out_1 / 10) * 9 + ((vsinfo_f1466_matrix_out_1 % 10) * 9) / 10 */
    var_out_1             = ((vsinfo_f1466_matrix_out_1[0] / 10) * 9) +
                            (((vsinfo_f1466_matrix_out_1[0] % 10) * 9) / 10);
    var_out_1             = var_out_1 / BIN11;
    VSCtl_spdVehEstim_no3 = (UInt16)DDS_M_LIMIT(var_out_1,VSCTL_SPDVEH_MIN,VSCTL_SPDVEH_MAX);

    var_out_2             = ((vsinfo_f1466_matrix_out_1[1] / 10) * 9) +
                            (((vsinfo_f1466_matrix_out_1[1] % 10) * 9) / 10);
    var_out_2             = var_out_2 / BIN11;

    VSCtl_spdVehMesEstim_no3  = (UInt16)DDS_M_LIMIT(var_out_2,VSCTL_SPDVEH_MIN,VSCTL_SPDVEH_MAX);

    var_out_3             = vsinfo_f1466_matrix_out_1[2] / BIN10;
    VSCtl_aResEstim_no3       = (SInt16)DDS_M_LIMIT(var_out_3,VSCTL_ARESESTIM_MIN,VSCTL_ARESESTIM_MAX);

    /* Affectation des prev */
    /* BIN14 = BIN20 / BIN6 */
    vsinfo_f1466_matrix_out_1_prev[0] = vsinfo_f1466_matrix_out_1[0] / BIN6;
    vsinfo_f1466_matrix_out_1_prev[1] = vsinfo_f1466_matrix_out_1[1] / BIN6;
    vsinfo_f1466_matrix_out_1_prev[2] = vsinfo_f1466_matrix_out_1[2] / BIN6;

    if(  ((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_TRANSITOIRE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_STABILISE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_ANTISATURATION))
    {
        *vsctl_ares_ptr = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_aResEstim_no3,(SInt32)VSCtl_aRes_SatMin_C,(SInt32)VSCtl_aRes_SatMax_C);
    }
    else
    {
        *vsctl_ares_ptr = 0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1467_Determiner_Acceleration_Aerodynamique
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1467_Determiner_Acceleration_Aerodynamique(
                                 UInt16 vsctl_mveh_par, /* BIN0 */
                                 UInt16 vsctl_spdveh_par, /* BIN7 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aaero_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.122.1 */
    SInt32 result_mult_1,result_mult_2,result_mult_3;
    SInt32 result_div_1;
    SInt32 result_denum;

    SInt8 nb_shift;

    if(  ((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_TRANSITOIRE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_STABILISE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_ANTISATURATION))
    {
        /* Multiplication to perform */
        /* (-61 / 100) * [0;10]BIN7 * (([0;255]BIN7 * 10) / 36) * (([0;255]BIN7 * 10) / 36) */
        /* with simplification */
        /* (-61 * [0;10]BIN7 * [0;255]BIN7 * [0;255]BIN7) / 1296 */

        result_mult_1 = (SInt32)VSCtl_SCXVeh * (SInt32)(-61 * BIN0);        /* [-610;0]BIN7 */
        result_mult_2 = (SInt32)vsctl_spdveh_par * (SInt32)vsctl_spdveh_par;    /* [0;65025]BIN14 */

        nb_shift = (SInt8) ((UInt32)7 + (UInt32)14);

        result_mult_3 = DDS_M_DYNAMIC_MULT_S32(result_mult_1,
                                               result_mult_2,
                                               &nb_shift);


        /* [1296; 12 960 000] BIN0 */
        result_denum = (SInt32)vsctl_mveh_par * 1296;

        /* BIN10 */
        result_div_1 = DDS_M_DYNAMIC_DIV_S32(result_mult_3, result_denum, nb_shift, 0, 10);

        *vsctl_aaero_ptr = (SInt16)DDS_M_MIN(DDS_M_MAX(result_div_1,(SInt32)VSCtl_aAero_SatMin_C),(SInt32)VSCtl_aAero_SatMax_C);
    }
    else
    {
        *vsctl_aaero_ptr = 0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1468_Determiner_Acceleration_Pneu
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1468_Determiner_Acceleration_Pneu(
                                 UInt16 vsctl_spdveh_par /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.175.0 */
    SInt32 vsinfo_svalue;

    vsinfo_svalue = (SInt32)DDS_M_MAP2D_US16(&VSCTL_ARESROAD_SPDVEH_T_APM,vsctl_spdveh_par);

    if(  ((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_TRANSITOIRE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_STABILISE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_ANTISATURATION))
    {
        VSCtl_aResRoad = (SInt16)DDS_M_SATURATION_V2(vsinfo_svalue,(SInt32)VSCtl_aResRoad_SatMin_C,(SInt32)VSCtl_aResRoad_SatMax_C);
    }
    else
    {
        VSCtl_aResRoad = 0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1469_Determiner_Acceleration_Pente
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1469_Determiner_Acceleration_Pente(
                                 SInt16 vsctl_aaero_par, /* BIN10 */
                                 SInt16 vsctl_ares_par /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.123.1 */
    SInt32 vsinfo_svalue;

    /* DETERMINER_ACCELERATION_PENTE */

    if(  ((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_TRANSITOIRE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_STABILISE)
       ||((UInt32)vsctl_stobsdyn_cpy == (UInt32)VSCTL_STOBSDYN_ANTISATURATION))
    {
        vsinfo_svalue = ((SInt32)vsctl_ares_par - (SInt32)vsctl_aaero_par) - (SInt32)VSCtl_aResRoad;
        VSCtl_aSlop = (SInt16)DDS_M_SATURATION_V2(vsinfo_svalue,(SInt32)VSCtl_aSlop_SatMin_C,(SInt32)VSCtl_aSlop_SatMax_C);
    }
    else
    {
        VSCtl_aSlop = 0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F146a_Determiner_Pente
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F146A_Determiner_Pente(
                                 UInt8 vsctl_stvehinfo_par,
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_rslop_ptr /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.124.1 */
    SInt32 filter_in,filter_out;


    /* [-98;98]BIN10 = (([-10;10]BIN10 * 98) /10) * -1 */
    filter_in = (((SInt32)VSCtl_aSlop * -98) / 10);

    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvFilVehInfo)
    {
        filter_out = DDS_M_FILTER_LP1_S32(&vsinfo_rslop_filter_struct,
                                           filter_in,
                                           (UInt16)((UInt32)VSCtl_tiFil_rSlop_C * BIN5));
    }
    else
    {
        filter_out = DDS_M_FILTER_LP1_S32_INIT(&vsinfo_rslop_filter_struct,
                                               filter_in);

    }

    if((VSCTL_STVEHINFO_INIT_12    == (UInt32)vsctl_stvehinfo_par )   ||
       (VSCTL_STVEHINFO_NOMINAL_12 == (UInt32)vsctl_stvehinfo_par ))
    {
        /* [-98;98]BIN7 */
        filter_out = filter_out / BIN3;
        /* [-20;20]BIN7 */
        *vsctl_rslop_ptr = (SInt16)DDS_M_SATURATION_V2(filter_out,(SInt32)VSCtl_rSlop_SatMin_C,(SInt32)VSCtl_rSlop_SatMax_C);
    }
    else
    {
        *vsctl_rslop_ptr = 0; /* [-20;20]BIN7 */
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F147_Determiner_Accelerations_Vehicule
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F147_Determiner_Accelerations_Vehicule(
                                           SInt16 vsctl_ares_par, /* BIN10 */
                                           UInt8 vsctl_stvehinfo_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehprecovsctlreq_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptdrvminreq_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptdrvminreqraw_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptini_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptlim_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptmax_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptmaxnotctla_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptmin_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptminnotctla_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptpotmaxctla_no1_ptr, /* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptpotmax_ptr,/* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehptpotmin_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.125.1 */
    SInt32 vsinfo_svalue;

    if(  ((UInt32)vsctl_stvehinfo_par == VSCTL_STVEHINFO_INIT_12)
       ||((UInt32)vsctl_stvehinfo_par == VSCTL_STVEHINFO_NOMINAL_12))
    {
        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTIni + (SInt32)vsctl_ares_par;
        *vsctl_avehptini_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTMax + (SInt32)vsctl_ares_par;
        *vsctl_avehptmax_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTMin + (SInt32)vsctl_ares_par;
        *vsctl_avehptmin_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTAplReq + (SInt32)vsctl_ares_par;
        VSCtl_aVehPTAplReq = (SInt16)DDS_M_LIMIT (vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTPreCoVSCtlReq + (SInt32)vsctl_ares_par;
        *vsctl_avehprecovsctlreq_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTPotMax + (SInt32)vsctl_ares_par;
        *vsctl_avehptpotmax_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTPotMin + (SInt32)vsctl_ares_par;
        *vsctl_avehptpotmin_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTMinNotCtla + (SInt32)vsctl_ares_par;
        *vsctl_avehptminnotctla_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTMaxNotCtla + (SInt32)vsctl_ares_par;
        *vsctl_avehptmaxnotctla_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTLim + (SInt32)vsctl_ares_par;
        *vsctl_avehptlim_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTDrvMinReqRaw + (SInt32)vsctl_ares_par;
        *vsctl_avehptdrvminreqraw_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTDrvMinReq + (SInt32)vsctl_ares_par;
        *vsctl_avehptdrvminreq_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);

        /* [-10;10]BIN10 = [-10;10]BIN10 + [-10;10]BIN10 */
        vsinfo_svalue = (SInt32)VSCtl_aPTPotMaxCtla_no1 + (SInt32)vsctl_ares_par;
        *vsctl_avehptpotmaxctla_no1_ptr = (SInt16)DDS_M_LIMIT(vsinfo_svalue,VSCTL_AVEH_MIN,VSCTL_AVEH_MAX);
    }
    else
    {
        *vsctl_avehptini_ptr            = 0;                         /* BIN10 */
        *vsctl_avehptmax_ptr            = (SInt16)(10 * BIN10);      /* BIN10 */
        *vsctl_avehptmin_ptr            = (SInt16)(-10 * BIN10);     /* BIN10 */
        VSCtl_aVehPTAplReq              = 0;                         /* BIN10 */
        *vsctl_avehprecovsctlreq_ptr    = 0;                         /* BIN10 */
        *vsctl_avehptpotmax_ptr         = (SInt16)(10 * BIN10);      /* BIN10 */
        *vsctl_avehptpotmin_ptr         = (SInt16)(-10 * BIN10);     /* BIN10 */
        *vsctl_avehptminnotctla_ptr     = 0;                         /* BIN10 */
        *vsctl_avehptmaxnotctla_ptr     = 0;                         /* BIN10 */
        *vsctl_avehptlim_ptr            = (SInt16)(-10 * BIN10);     /* BIN10 */
        *vsctl_avehptdrvminreqraw_ptr   = (SInt16)(-10 * BIN10);     /* BIN10 */
        *vsctl_avehptdrvminreq_ptr      = (SInt16)(-10 * BIN10);     /* BIN10 */
        *vsctl_avehptpotmaxctla_no1_ptr = (SInt16)(10 * BIN10);      /* BIN10 */
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Accel_Estim
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Accel_Estim_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aAero_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aRes_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTDrvMinReqRaw_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTIni_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTLim_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMaxNotCtla_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMin_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTMinNotCtla_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMaxCtla_no1_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPTPotMin_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehPreCoVSCtlReq_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_swc_out /* BIN7 */)
{
    UInt32 index;
    /* ---- Init Outputs ---- */
    *VSCtl_aAero_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_aRes_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_aVehPTDrvMinReq_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVehPTDrvMinReqRaw_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVehPTIni_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_aVehPTLim_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVehPTMax_swc_out = (SInt16)(10 * BIN10);
    *VSCtl_aVehPTMaxNotCtla_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_aVehPTMin_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVehPTMinNotCtla_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_aVehPTPotMax_swc_out = (SInt16)(10 * BIN10);
    *VSCtl_aVehPTPotMaxCtla_no1_swc_out = (SInt16)(10 * BIN10);
    *VSCtl_aVehPTPotMin_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVehPreCoVSCtlReq_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_rSlop_swc_out = (SInt16)(0 * BIN7);

    /* ---- Init Global Datas ---- */
    VSCtl_aResEstim_no3 = (SInt16)(0 * BIN10);
    VSCtl_aResRoad = (SInt16)(0 * BIN10);
    VSCtl_aSlop = (SInt16)(0 * BIN10);
    VSCtl_aVehPTAplReq = (SInt16)(0 * BIN10);
    VSCtl_spdVehEstim_no3 = (UInt16)(0 * BIN7);
    VSCtl_spdVehMesEstim_no3 = (UInt16)(0 * BIN7);

    /* ---- VSINFO_F1466_Estimer_Acceleration_Resistante ---- */
    for(index = 0 ; index < (UInt32)VSINFO_V_DYN_MAP_M_Y ; index++)
    {
        vsinfo_f1466_matrix_out_1[index]    = (0 * BIN20);
        vsinfo_f1466_matrix_out_1_prev[index]    = (0 * BIN14);
    }

    /* ---- VSINFO_F1467_Determiner_Acceleration_Aerodynamique ---- */

    /* ---- VSINFO_F1468_Determiner_Acceleration_Pneu ---- */

    /* ---- VSINFO_F1469_Determiner_Acceleration_Pente ---- */

    /* ---- VSINFO_F146A_Determiner_Pente ---- */
    (void)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_rslop_filter_struct,0);

    /* ---- VSINFO_F147_Determiner_Accelerations_Vehicule ---- */

}

#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

