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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Available_Tq_Gmp1_Sl.c
* Version int :/main/L02_02/1 Date: 4/1/2012 16 h 31 m User:esnault 
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 22/11/2011 14 h 3 m User:demezil 
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 5 m User:meme
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 4 m User:demezil
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 17 m User:meme
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 25/2/2011 10 h 1 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 22/2/2011 10 h 49 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 16 m User:meme
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\11 Date: 14/2/2011 9 h 54 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\10 Date: 9/2/2011 9 h 15 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\9 Date: 8/2/2011 9 h 7 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 7/2/2011 18 h 16 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for vSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 2/2/2011 17 h 28 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 7/1/2011 14 h 57 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 13 h 59 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :delete main function declaration
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 12 h 1 m User:morisseau
*    TWK_model:VSINFO_Available_Tq_Gmp1_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 37 m User:morisseau
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
#define VSINFO_100_BIN7                       (100 * BIN7)
#define VSINFO_16000_BIN1                     (16000 * BIN1)
#define VSINFO_16000_BIN3                     (16000 * BIN3)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTAplReq_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_pt1; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_pt1; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt1; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilPTInfo_pt1;
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

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_pt1; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTRe_pt1; /* BIN7 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMax_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMin_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla1_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_pt1; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlThPTPotMin_pt1; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bCtlaTqPT_pt1;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rTqWhlPTReExt_SatMax_C = (CONST(UInt16, AUTOMATIC))(100 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rTqWhlPTReExt_SatMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rTqWhlPTReIni_pt1_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rTqWhlPTRe_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl1pt1Mn_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl1pt1Mx_C = (CONST(UInt16, AUTOMATIC))(11000 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl2pt1Mn_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl2pt1Mx_C = (CONST(UInt16, AUTOMATIC))(11000 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtlaTolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtlaTolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtlapt1Mn_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtlapt1Mx_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinThpt1_Max_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinThpt1_Min_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla1TolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla1TolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla2TolN_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla2TolP_C = (CONST(UInt16, AUTOMATIC))(0 * BIN1);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* None */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_filter_hyst_u16, AUTOMATIC) vsinfo_f11141_filter_struct_no1;
STATIC VAR(t_dds_m_filter_hyst_u16, AUTOMATIC) vsinfo_f11141_filter_struct_no2;
STATIC VAR(t_dds_m_filter_hyst_s16, AUTOMATIC) vsinfo_f11142_filter_struct_no1;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1117_filter_struct;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* 16-Bit variable definition */
#define VSINFO_START_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsinfo_tqwhlptdrvmaxreq_pt1_loc; /* BIN1 */
STATIC VAR(SInt16, AUTOMATIC) vsinfo_tqwhlptdrvminreq_pt1_loc; /* BIN1 */
STATIC VAR(SInt16, AUTOMATIC) vsinfo_tqwhlptaplreq_pt1_loc; /* BIN1 */
#define VSINFO_STOP_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-Bit variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_bacvfilptinfo_pt1_local;
STATIC VAR(UInt8, AUTOMATIC) vsinfo_stptinfo_pt1_local; /* BIN0 */
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtla_pt1; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla2_pt1; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRwMnCtla_pt1; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRwMxCtl2_pt1; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* None */


/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

STATIC FUNC(void, AUTOMATIC) VSINFO_F1114_Determiner_Potentiels_Couple_Roue_GMP(
                           SInt16 ptlim_tqwhlptpotmaxctla_no1_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptpotmaxctla_no2_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptpotminctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlthptpotmin_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvhithd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvlothd_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11141_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable(
                           SInt16 ptlim_tqwhlptpotmaxctla_no1_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptpotmaxctla_no2_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvhithd_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11142_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable(
                           SInt16 ptlim_tqwhlptpotminctla_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvlothd_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11143_Determiner_Potentiel_Couple_Roue_Gmp_Min_Thermique(
                           SInt16 ptlim_tqwhlthptpotmin_par /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F11144_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max(void);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1115_Determiner_Pilotabilite_Couple_Roue_Gmp(
                          UInt8 vehest_bctltqwhlpt_par);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1116_Determiner_Consigne_Couple_Roue_Gmp_Normee(void);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1117_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar(
                          UInt8 frm_bdeacvsctlrtqwhlptreclc_par,
                          UInt16 vehest_rtqwhlptre_par /* BIN7 */);

/*******************************************************************************
*
* Function Name : VSINFO_F1114_Determiner_Potentiels_Couple_Roue_GMP
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Available_Tq_Gmp1_Sl(
                           UInt8 FRM_bDeacVSCtlrTqWhlPTReClc_swc_in,
                           SInt16 PtLim_tqWhlPTPotMaxCtla_no1_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTPotMaxCtla_no2_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlPTPotMinCtla_swc_in, /* BIN1 */
                           SInt16 PtLim_tqWhlThPTPotMin_swc_in, /* BIN1 */
                           UInt8 VehEst_bCtlTqWhlPT_swc_in,
                           UInt16 VehEst_rTqWhlPTRe_swc_in, /* BIN7 */
                           SInt16 VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                           SInt16 VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                           SInt16 VSCtl_tqWhlPotMinRsvHiThd_swc_in, /* BIN1 */
                           SInt16 VSCtl_tqWhlPotMinRsvLoThd_swc_in  /* BIN1 */)
{
    vsinfo_stptinfo_pt1_local = VSCtl_stPTInfo_pt1;
    vsinfo_bacvfilptinfo_pt1_local = VSCtl_bAcvFilPTInfo_pt1;
    vsinfo_tqwhlptaplreq_pt1_loc = VSCtl_tqWhlPTAplReq_pt1;
    vsinfo_tqwhlptdrvmaxreq_pt1_loc = VSCtl_tqWhlPTDrvMaxReq_pt1;
    vsinfo_tqwhlptdrvminreq_pt1_loc = VSCtl_tqWhlPTDrvMinReq_pt1;

    VSINFO_F1114_Determiner_Potentiels_Couple_Roue_GMP(
                           PtLim_tqWhlPTPotMaxCtla_no1_swc_in, /* BIN1 */
                           PtLim_tqWhlPTPotMaxCtla_no2_swc_in, /* BIN1 */
                           PtLim_tqWhlPTPotMinCtla_swc_in, /* BIN1 */
                           PtLim_tqWhlThPTPotMin_swc_in, /* BIN1 */
                           VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                           VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                           VSCtl_tqWhlPotMinRsvHiThd_swc_in, /* BIN1 */
                           VSCtl_tqWhlPotMinRsvLoThd_swc_in /* BIN1 */);

    VSINFO_F1115_Determiner_Pilotabilite_Couple_Roue_Gmp(
                           VehEst_bCtlTqWhlPT_swc_in);

    VSINFO_F1116_Determiner_Consigne_Couple_Roue_Gmp_Normee();

    VSINFO_F1117_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar(
                           FRM_bDeacVSCtlrTqWhlPTReClc_swc_in,
                           VehEst_rTqWhlPTRe_swc_in /* BIN7 */);
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
* Function Name : VSINFO_F1114_Determiner_Potentiels_Couple_Roue_GMP
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1114_Determiner_Potentiels_Couple_Roue_GMP(
                           SInt16 ptlim_tqwhlptpotmaxctla_no1_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptpotmaxctla_no2_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptpotminctla_par, /* BIN1 */
                           SInt16 ptlim_tqwhlthptpotmin_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvhithd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvlothd_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.22.2 */

    VSINFO_F11141_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable(
                               ptlim_tqwhlptpotmaxctla_no1_par, /* BIN1 */
                               ptlim_tqwhlptpotmaxctla_no2_par, /* BIN1 */
                               vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                               vsctl_tqwhlpotminrsvhithd_par /* BIN1 */);

    VSINFO_F11142_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable(
                               ptlim_tqwhlptpotminctla_par, /* BIN1 */
                               vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                               vsctl_tqwhlpotminrsvlothd_par /* BIN1 */);

    VSINFO_F11143_Determiner_Potentiel_Couple_Roue_Gmp_Min_Thermique(
                               ptlim_tqwhlthptpotmin_par /* BIN1 */);

    VSINFO_F11144_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max();
}

/*******************************************************************************
*
* Function Name : VSINFO_F11141_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11141_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable(
                           SInt16 ptlim_tqwhlptpotmaxctla_no1_par, /* BIN1 */
                           SInt16 ptlim_tqwhlptpotmaxctla_no2_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvhithd_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.23.2 */
    UInt16 vsctl_tqwhlptpotmaxctlano1_pt1_tmp;
    UInt16 vsctl_tqwhlptpotmaxctlano2_pt1_tmp;
    SInt32 temp1_s32;

    /* [0; 16000] BIN1 */
    vsctl_tqwhlptpotmaxctlano1_pt1_tmp = (UInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptpotmaxctla_no1_par,
                                                                     (SInt32)VSCtl_tqWhlPTPotMaxCtl1pt1Mn_C,
                                                                     (SInt32)VSCtl_tqWhlPTPotMaxCtl1pt1Mx_C);
    /* filtering */
    vsctl_tqwhlptpotmaxctlano1_pt1_tmp = DDS_M_FILTER_HYST_U16(&vsinfo_f11141_filter_struct_no1,
                                                               vsctl_tqwhlptpotmaxctlano1_pt1_tmp,
                                                               VSCtl_tqWhlPTPotMxCtla1TolP_C,
                                                               VSCtl_tqWhlPTPotMxCtla1TolN_C,
                                                               vsinfo_bacvfilptinfo_pt1_local);

    /* [0; 16000] BIN1 */
    vsctl_tqwhlptpotmaxctlano2_pt1_tmp = (UInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptpotmaxctla_no2_par,
                                                                     (SInt32)VSCtl_tqWhlPTPotMaxCtl2pt1Mn_C,
                                                                     (SInt32)VSCtl_tqWhlPTPotMaxCtl2pt1Mx_C);
    /* filtering */
    vsctl_tqwhlptpotmaxctlano2_pt1_tmp = DDS_M_FILTER_HYST_U16(&vsinfo_f11141_filter_struct_no2,
                                                               vsctl_tqwhlptpotmaxctlano2_pt1_tmp,
                                                               VSCtl_tqWhlPTPotMxCtla2TolP_C,
                                                               VSCtl_tqWhlPTPotMxCtla2TolN_C,
                                                               vsinfo_bacvfilptinfo_pt1_local);


    if ((VSCTL_STPTINFO_INIT_1 == (UInt32)vsinfo_stptinfo_pt1_local)||
        (VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local))
    {
        /* [0; 16000] BIN1 */
        VSCtl_tqWhlPTPotMxCtla1_pt1 = (SInt16)vsctl_tqwhlptpotmaxctlano1_pt1_tmp;

        /* [0; 16000] BIN1 */
        VSCtl_tqWhlPTPotRwMxCtl2_pt1 = (SInt16)vsctl_tqwhlptpotmaxctlano2_pt1_tmp;

        temp1_s32 = (SInt32)VSCtl_tqWhlPTPotRwMxCtl2_pt1 + DDS_M_MAX((SInt32)vsctl_tqwhlpotmaxrsvhithd_par,(SInt32)vsctl_tqwhlpotminrsvhithd_par);

        VSCtl_tqWhlPTPotMxCtla2_pt1 = (SInt16)DDS_M_MIN(temp1_s32,VSINFO_16000_BIN1);
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* case VSINFOH_STPTINFO_PT1_INIT_1 */
        /* default */
        VSCtl_tqWhlPTPotMxCtla1_pt1 = (SInt16)VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPotRwMxCtl2_pt1 = (SInt16)VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPotMxCtla2_pt1 = (SInt16)VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11142_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11142_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable(
                           SInt16 ptlim_tqwhlptpotminctla_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                           SInt16 vsctl_tqwhlpotminrsvlothd_par /* BIN1 */)

{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.24.2 */
    SInt16 vsctl_tqwhlptpotminctla_pt1_tmp;
    SInt32 temp1_s32;

    /* [-16000; 0] BIN1 */
    vsctl_tqwhlptpotminctla_pt1_tmp = (SInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlptpotminctla_par,
                                                                  (SInt32)VSCtl_tqWhlPTPotMinCtlapt1Mn_C,
                                                                  (SInt32)VSCtl_tqWhlPTPotMinCtlapt1Mx_C);
    /* filtering */
    vsctl_tqwhlptpotminctla_pt1_tmp = DDS_M_FILTER_HYST_S16(&vsinfo_f11142_filter_struct_no1,
                                                            vsctl_tqwhlptpotminctla_pt1_tmp,
                                                            VSCtl_tqWhlPTPotMinCtlaTolP_C,
                                                            VSCtl_tqWhlPTPotMinCtlaTolN_C,
                                                            vsinfo_bacvfilptinfo_pt1_local);

    if ((VSCTL_STPTINFO_INIT_1 == (UInt32)vsinfo_stptinfo_pt1_local)||
        (VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local))
    {
        /* BIN1: [-16000;16000] */
        VSCtl_tqWhlPTPotRwMnCtla_pt1 = vsctl_tqwhlptpotminctla_pt1_tmp;

        /* [-16000; 16000] BIN1 */
        temp1_s32 = DDS_M_MAX((SInt32)vsctl_tqwhlpotminrsvlothd_par, (SInt32)vsctl_tqwhlpotmaxrsvlothd_par);
        /* [-32000; 16000] = [-16000; 0] - [-16000; 16000] */
        /* BIN1 = BIN1 - BIN1 */
        temp1_s32 = (SInt32)vsctl_tqwhlptpotminctla_pt1_tmp - temp1_s32;
        VSCtl_tqWhlPTPotMinCtla_pt1 = (SInt16)DDS_M_MAX(temp1_s32, -VSINFO_16000_BIN1);
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* case VSINFOH_STPTINFO_PT1_INIT_1 */
        /* default */
        VSCtl_tqWhlPTPotRwMnCtla_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPotMinCtla_pt1 = (SInt16)-VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11143_Determiner_Potentiel_Couple_Roue_Gmp_Min_Thermique
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11143_Determiner_Potentiel_Couple_Roue_Gmp_Min_Thermique(
                           SInt16 ptlim_tqwhlthptpotmin_par /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.136.1 */

    if ((VSCTL_STPTINFO_INIT_1 == (UInt32)vsinfo_stptinfo_pt1_local)||
        (VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local))
    {
        VSCtl_tqWhlThPTPotMin_pt1 = (SInt16)DDS_M_SATURATION_V2((SInt32)ptlim_tqwhlthptpotmin_par,
                                                                (SInt32)VSCtl_tqWhlPTPotMinThpt1_Min_C,
                                                                (SInt32)VSCtl_tqWhlPTPotMinThpt1_Max_C);
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* case  */
        /* default */
        VSCtl_tqWhlThPTPotMin_pt1 = (SInt16)-VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11144_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F11144_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.25.1 */
    if(VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local)
    {
        VSCtl_tqWhlPTPotMax_pt1 = VSCtl_tqWhlPTPotMxCtla2_pt1;
        VSCtl_tqWhlPTPotRawMax_pt1 = VSCtl_tqWhlPTPotRwMxCtl2_pt1;
        VSCtl_tqWhlPTPotMin_pt1 = VSCtl_tqWhlPTPotMinCtla_pt1;
        VSCtl_tqWhlPTPotRawMin_pt1 = VSCtl_tqWhlPTPotRwMnCtla_pt1;
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* case VSINFOH_STPTINFO_PT1_INIT_1 */
        /* default */
        VSCtl_tqWhlPTPotMax_pt1 = (SInt16)VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPotRawMax_pt1 = (SInt16)VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPotMin_pt1 = (SInt16)-VSINFO_16000_BIN1;
        VSCtl_tqWhlPTPotRawMin_pt1 = (SInt16)-VSINFO_16000_BIN1;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1115_Determiner_Pilotabilite_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1115_Determiner_Pilotabilite_Couple_Roue_Gmp(
                           UInt8 vehest_bctltqwhlpt_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.141.0 */
    if(VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local)
    {
        VSCtl_bCtlaTqPT_pt1 = vehest_bctltqwhlpt_par;
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* case  */
        /* default */
        VSCtl_bCtlaTqPT_pt1 = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1116_Determiner_Consigne_Couple_Roue_Gmp_Normee
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1116_Determiner_Consigne_Couple_Roue_Gmp_Normee(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.142.0 */
    SInt32 vsinfo_div_0;
    SInt32 vsinfo_div_1;

    if(VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local)
    {
        /* BIN8: [-16000;16000] * 100 */
        vsinfo_div_0 = (SInt32)vsinfo_tqwhlptaplreq_pt1_loc * (SInt32)VSINFO_100_BIN7;
        vsinfo_div_1 = vsinfo_div_0;

        if((SInt32)vsinfo_tqwhlptdrvmaxreq_pt1_loc != 0)
        {
            /* BIN7 = BIN8 / BIN1 */
            /* [-1;1] * 100 = [-16000;16000] * 100 / [-16000;16000] */
            vsinfo_div_0 = vsinfo_div_0 / (SInt32)vsinfo_tqwhlptdrvmaxreq_pt1_loc;
            vsinfo_div_0 = DDS_M_MAX(vsinfo_div_0,(SInt32)VSINFO_0);
            vsinfo_div_0 = DDS_M_MIN(vsinfo_div_0,(SInt32)VSINFO_100_BIN7);
        }
        else if((SInt32)vsinfo_tqwhlptaplreq_pt1_loc <= 0)
        {
            vsinfo_div_0 = VSINFO_0;
        }
        else
        {
            vsinfo_div_0 = VSINFO_100_BIN7;
        }

        if((SInt32)vsinfo_tqwhlptdrvminreq_pt1_loc != 0)
        {
            /* BIN7 = BIN8 / BIN1 */
            /* [-1;1] * 100 = [-16000;16000] * 100 / [-16000;16000] */
            vsinfo_div_1 = vsinfo_div_1 / (SInt32)vsinfo_tqwhlptdrvminreq_pt1_loc;
            vsinfo_div_1 = DDS_M_MIN(vsinfo_div_1,(SInt32)VSINFO_0);
            vsinfo_div_1 = DDS_M_MAX(vsinfo_div_1,(SInt32)-VSINFO_100_BIN7);
        }
        else if((SInt32)vsinfo_tqwhlptaplreq_pt1_loc >= 0)
        {
            vsinfo_div_1 = VSINFO_0;
        }
        else
        {
            vsinfo_div_1 = -VSINFO_100_BIN7;
        }

        /* BIN7 = BIN7 + BIN7 */
        /* [-100;100] = [0;100] + [-100;0] */
        vsinfo_div_1 = vsinfo_div_0 + vsinfo_div_1;

        VSCtl_rTqWhlPTDrvReq_pt1 = (UInt16)DDS_M_MAX(vsinfo_div_1,VSINFO_0);
    }
    else
    {
        /* case VSINFOH_STPTINFO_PT1_ARRET */
        /* case VSINFOH_STPTINFO_PT1_VERIF_1 */
        /* case  */
        /* default */
        VSCtl_rTqWhlPTDrvReq_pt1 = (UInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1117_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1117_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar(
                           UInt8 frm_bdeacvsctlrtqwhlptreclc_par,
                           UInt16 vehest_rtqwhlptre_par /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.81.1 */
    UInt32 vsinfo_filter_out;

    if((UInt32)vsinfo_bacvfilptinfo_pt1_local == (UInt32)DDS_TRUE)
    {
        vsinfo_filter_out = (UInt32)DDS_M_FILTER_LP1_U16(&vsinfo_f1117_filter_struct, vehest_rtqwhlptre_par, VSCtl_tiFil_rTqWhlPTRe_C, BIN10);
    }
    else
    {
        vsinfo_filter_out = (UInt32)DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1117_filter_struct, vehest_rtqwhlptre_par);
    }

    if(VSCTL_STPTINFO_NOMINAL_1 == (UInt32)vsinfo_stptinfo_pt1_local)
    {
        if((UInt32)frm_bdeacvsctlrtqwhlptreclc_par == (UInt32)DDS_TRUE)
        {
            VSCtl_rTqWhlPTRe_pt1 = VSCtl_rTqWhlPTReIni_pt1_C;
        }
        else
        {
            VSCtl_rTqWhlPTRe_pt1 = (UInt16)DDS_M_SATURATION_V2(vsinfo_filter_out,
                                                               (UInt32)VSCtl_rTqWhlPTReExt_SatMin_C,
                                                               (UInt32)VSCtl_rTqWhlPTReExt_SatMax_C);
        }
    }
    else
    {
        VSCtl_rTqWhlPTRe_pt1 = VSCtl_rTqWhlPTReIni_pt1_C;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Available_Tq_Gmp1_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Available_Tq_Gmp1_Sl_Init(void)
{
    /* ---- Init Outputs ---- */

    /* ---- Init Global Datas ---- */
    VSCtl_bCtlaTqPT_pt1 = DDS_FALSE;
    VSCtl_rTqWhlPTDrvReq_pt1 = (UInt16)(0 * BIN7);
    VSCtl_rTqWhlPTRe_pt1 = (UInt16)(0 * BIN7);
    VSCtl_tqWhlPTPotMax_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotMinCtla_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPotMin_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPotMxCtla1_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotMxCtla2_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotRawMax_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotRawMin_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPotRwMnCtla_pt1 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPotRwMxCtl2_pt1 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlThPTPotMin_pt1 = (SInt16)(-16000 * BIN1);

    vsinfo_stptinfo_pt1_local = 0;
    vsinfo_bacvfilptinfo_pt1_local = 0;
    vsinfo_tqwhlptaplreq_pt1_loc = 0;
    vsinfo_tqwhlptdrvmaxreq_pt1_loc = 0;
    vsinfo_tqwhlptdrvminreq_pt1_loc = 0;

    /* ---- VSINFO_F11141_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable ---- */
    DDS_M_FILTER_HYST_U16_INIT(&vsinfo_f11141_filter_struct_no1, 0);
    DDS_M_FILTER_HYST_U16_INIT(&vsinfo_f11141_filter_struct_no2, 0);

    /* ---- VSINFO_F11142_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable ---- */
    DDS_M_FILTER_HYST_S16_INIT(&vsinfo_f11142_filter_struct_no1, 0);

    /* ---- VSINFO_F11143_Determiner_Potentiel_Couple_Roue_Gmp_Min_Thermique ---- */

    /* ---- VSINFO_F11144_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max ---- */

    /* ---- VSINFO_F1115_Determiner_Pilotabilite_Couple_Roue_Gmp ---- */

    /* ---- VSINFO_F1116_Determiner_Consigne_Couple_Roue_Gmp_Normee ---- */

    /* ---- VSINFO_F1117_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1117_filter_struct, 0);
}

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

