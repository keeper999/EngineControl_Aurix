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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Elabor_Car_Info_Sl.c
* Version int :/main/L02_02/1 Date: 4/1/2012 16 h 31 m User:esnault 
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 22/11/2011 14 h 3 m User:demezil 
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L02_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 6 m User:meme
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 28/7/2011 17 h 33 m User:demezil
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 13/7/2011 15 h 0 m User:demezil
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/3 Date: 12/5/2011 8 h 48 m User:meme
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL2_D
*    comments :use DDS_M_BARY_FILTER_V2 instead of DDS_M_BARY_FILTER
* Version dev :\main\branch_demezil_generic_view\1 Date: 10/5/2011 17 h 29 m User:demezil
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL2_D
*    comments :use DDS_M_BARY_FILTER_V2 instead of DDS_M_BARY_FILTER
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 23 m User:meme
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL2
*    comments :UT correction
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 24/2/2011 14 h 42 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL2
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 15/2/2011 17 h 16 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 2/2/2011 17 h 33 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 14 h 8 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL1
*    comments :delete main declaration
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 9 h 10 m User:morisseau
*    TWK_model:VSINFO_Elabor_Car_Info_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 16 h 46 m User:morisseau
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
extern VAR(UInt16, AUTOMATIC) VSCtl_rAccPT; /* BIN7 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bInh_aPT;
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

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_SCXVeh;
VAR(UInt16, AUTOMATIC) VSCtl_spdVehFil;
VAR(SInt16, AUTOMATIC) VSCtl_aPTMax;
VAR(SInt16, AUTOMATIC) VSCtl_aPTMin;
VAR(SInt16, AUTOMATIC) VSCtl_aPTAplReq;
VAR(SInt16, AUTOMATIC) VSCtl_aPTIni;
VAR(SInt16, AUTOMATIC) VSCtl_aPTPreCoVSCtlReq;
VAR(SInt16, AUTOMATIC) VSCtl_aPTPotMax;
VAR(SInt16, AUTOMATIC) VSCtl_aPTPotMin;
VAR(SInt16, AUTOMATIC) VSCtl_aPTPotMaxCtla_no1;
VAR(SInt16, AUTOMATIC) VSCtl_aPTMinNotCtla;
VAR(SInt16, AUTOMATIC) VSCtl_aPTMaxNotCtla;
VAR(SInt16, AUTOMATIC) VSCtl_aPTLim;
VAR(SInt16, AUTOMATIC) VSCtl_aPTDrvMinReqRaw;
VAR(SInt16, AUTOMATIC) VSCtl_aPTDrvMinReq;
VAR(SInt16, AUTOMATIC) VSCtl_aPT;
VAR(SInt16, AUTOMATIC) VSCtl_aBrk;
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_spdVehFil_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTtqPT_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPTtqBrk_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rdWhl_C = (CONST(UInt16, AUTOMATIC))(0.3125 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_SCXVeh_C = (CONST(UInt16, AUTOMATIC))(0.8125 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_mVeh_C = (CONST(UInt16, AUTOMATIC))(1600 * BIN0);   /* BIN0 */
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeac_rAccPTtqPT_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeac_rAccPTtqBrk_C = DDS_FALSE;
#define VSINFO_STOP_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aOfsPT_spdVeh_T
[VSINFO_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_aOfsPT_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aGainPT_spdVeh_T
[VSINFO_8_SIZE] = {
(UInt16)(0.5 * BIN10), (UInt16)(0.5 * BIN10), (UInt16)(0.7998046875 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_aGainPT_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(30 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccPT0_spdVeh_T
[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccPT0_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_aOfsBrk_spdVeh_T
[VSINFO_8_SIZE] = {
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10), (SInt16)(0 * BIN10),
(SInt16)(0 * BIN10), (SInt16)(0 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_aOfsBrk_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_aGainBrk_spdVeh_T
[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10), (UInt16)(0 * BIN10),
(UInt16)(0 * BIN10), (UInt16)(0 * BIN10)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_aGainBrk_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rAccBrk0_spdVeh_T
[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rAccBrk0_A[VSINFO_8_SIZE] = {
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
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_aofspt_spdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_againpt_spdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_raccpt0_spdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_aofsbrk_spdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_againbrk_spdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_raccbrk0_spdveh_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfoh_f143_filtre_vitesse_vehicule;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aBrkReq; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aPTReal; /* BIN10 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_aBrkEstim; /* BIN10 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSINFO_START_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_AOFSPT_SPDVEH_T_APM = {
&vsctl_aofspt_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_aOfsPT_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aOfsPT_spdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_AGAINPT_SPDVEH_T_APM = {
&vsctl_againpt_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_aGainPT_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aGainPT_spdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_RACCPT0_SPDVEH_T_APM = {
&vsctl_raccpt0_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccPT0_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccPT0_spdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_AOFSBRK_SPDVEH_T_APM = {
&vsctl_aofsbrk_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_aOfsBrk_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aOfsBrk_spdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_AGAINBRK_SPDVEH_T_APM = {
&vsctl_againbrk_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_aGainBrk_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_aGainBrk_spdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_RACCBRK0_SPDVEH_T_APM = {
&vsctl_raccbrk0_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rAccBrk0_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rAccBrk0_spdVeh_T[0]
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
* Function Name : VSINFO_F142_Determiner_Parametres_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F142_Determiner_Parametres_Vehicule(
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_mVeh_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rdWhl_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.91.1 */
    *VSCtl_mVeh_swc_out = VSCtl_mVeh_C;
    *VSCtl_rdWhl_swc_out = VSCtl_rdWhl_C;
    VSCtl_SCXVeh = VSCtl_SCXVeh_C;
}

/*******************************************************************************
*
* Function Name : VSINFO_F143_Filtrer_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F143_Filtrer_Vitesse_Vehicule(
                                 UInt16 VSCtl_spdVehRef_swc_in, /* BIN7 */
                                 UInt8 VSCtl_stVehInfo_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.99.1 */

    UInt16 filter_out;

    if((UInt32)DDS_FALSE != (UInt32)VSCtl_bAcvFilVehInfo)
    {

        filter_out = DDS_M_FILTER_LP1_U16(&vsinfoh_f143_filtre_vitesse_vehicule,
                                          VSCtl_spdVehRef_swc_in,
                                          VSCtl_tiFil_spdVehFil_C,
                                          BIN10);
    }
    else
    {
        filter_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfoh_f143_filtre_vitesse_vehicule,
                                               VSCtl_spdVehRef_swc_in);
    }

    if(  ((UInt32)VSCtl_stVehInfo_swc_in == (UInt32)VSCTL_STVEHINFO_INIT_12)
       ||((UInt32)VSCtl_stVehInfo_swc_in == (UInt32)VSCTL_STVEHINFO_NOMINAL_12))
    {
            VSCtl_spdVehFil = filter_out;
    }
    else
    {
            VSCtl_spdVehFil = (UInt16)(0 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F144_Determiner_Accelerations_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F144_Determiner_Accelerations_Gmp(
                                 UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                 UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                 UInt8 VSCtl_stVehInfo_swc_in,
                                 SInt16 VSCtl_tqWhlPTAplReq_swc_in, /* BIN1 */
                                 SInt16 VSCtl_tqWhlPTDrvMinReq_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTDrvMinReqRaw_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTIni_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTLim_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMaxNotCtla_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTMinNotCtla_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPotMax_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPotMaxCtla_no1_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPotMin_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTPreCoVSCtlReq_swc_in, /* BIN1*/
                                 SInt16 VSCtl_tqWhlPTReal_swc_in /* BIN1*/)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.109.3 */
    SInt32 vsinfo_s_denum;
    SInt32 vsinfo_svalue;

    if(  ((UInt32)VSCtl_stVehInfo_swc_in == (UInt32)VSCTL_STVEHINFO_INIT_12)
       ||((UInt32)VSCtl_stVehInfo_swc_in == (UInt32)VSCTL_STVEHINFO_NOMINAL_12))
    {
        /* BIN7 = BIN0 * BIN7 */
        /* [1/128;100000] = [1;10000] * [1/128;10] */
        /* kg.m = kg * m */
        vsinfo_s_denum = (SInt32)VSCtl_mVeh_swc_in * (SInt32)VSCtl_rdWhl_swc_in;

        /* BIN10 = BIN1 * BIN16 / BIN7 */
        /* [-2048000;2048000] = [-16000;16000] / [1/128;100000] */
        /* waiting for [-10;10] */
        /* m/s2 = N.m / (kg.m) */
        /* m/s2 = (Kg.m2/s2) / (kg.m) */

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTMax_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTMax = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTMin_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTMin = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTReal_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTReal = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTAplReq_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTAplReq = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTIni_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTIni = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTPreCoVSCtlReq_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTPreCoVSCtlReq = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTPotMax_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTPotMax = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTPotMin_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTPotMin = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTPotMaxCtla_no1_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTPotMaxCtla_no1 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTMinNotCtla_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTMinNotCtla = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTMaxNotCtla_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTMaxNotCtla = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTLim_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTLim = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTDrvMinReqRaw_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTDrvMinReqRaw = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlPTDrvMinReq_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aPTDrvMinReq = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);
    }
    else
    {
        VSCtl_aPTMax = (SInt16)(10 * BIN10);
        VSCtl_aPTMin = (SInt16)(-10 * BIN10);
        VSCtl_aPTReal = (SInt16)(0 * BIN10);
        VSCtl_aPTAplReq = (SInt16)(0 * BIN10);
        VSCtl_aPTIni = (SInt16)(0 * BIN10);
        VSCtl_aPTPreCoVSCtlReq = (SInt16)(-10 * BIN10);
        VSCtl_aPTPotMax = (SInt16)(10 * BIN10);
        VSCtl_aPTPotMin = (SInt16)(-10 * BIN10);
        VSCtl_aPTPotMaxCtla_no1 = (SInt16)(10 * BIN10);
        VSCtl_aPTMinNotCtla = (SInt16)(0 * BIN10);
        VSCtl_aPTMaxNotCtla = (SInt16)(0 * BIN10);
        VSCtl_aPTLim = (SInt16)(-10 * BIN10);
        VSCtl_aPTDrvMinReqRaw = (SInt16)(-10 * BIN10);
        VSCtl_aPTDrvMinReq = (SInt16)(-10 * BIN10);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F145_Determiner_Acceleration_Frein
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F145_Determiner_Acceleration_Frein(
                                 UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                 UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                 UInt8 VSCtl_stVehInfo_swc_in,
                                 SInt16 VSCtl_tqWhlBrkEstim_swc_in, /* BIN1 */
                                 SInt16 VSCtl_tqWhlBrkReq_swc_in /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.110.1 */
    SInt32 vsinfo_s_denum;
    SInt32 vsinfo_svalue;

    if(  ((UInt32)VSCtl_stVehInfo_swc_in == (UInt32)VSCTL_STVEHINFO_INIT_12)
       ||((UInt32)VSCtl_stVehInfo_swc_in == (UInt32)VSCTL_STVEHINFO_NOMINAL_12))
    {
        /* BIN7 = BIN0 * BIN7 */
        /* [1/128;100000] = [1;10000] * [1/128;10] */
        /* kg.m = kg * m */
        vsinfo_s_denum = (SInt32)VSCtl_mVeh_swc_in * (SInt32)VSCtl_rdWhl_swc_in;

        /* BIN10 = BIN1 * BIN16 / BIN7 */
        /* [-2048000;2048000] = [-16000;16000] / [1/128;100000] */
        /* waiting for [-10;10] */
        /* m/s2 = N.m / (kg.m) */
        /* m/s2 = (Kg.m2/s2) / (kg.m) */

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlBrkEstim_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aBrkEstim = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);

/* <PRQA_COMMENT><0584> Protected division. Denum minival value eq 1/128 in BIN7. </0584></PRQA_COMMENT> */
        vsinfo_svalue = ((SInt32)VSCtl_tqWhlBrkReq_swc_in * BIN16) / vsinfo_s_denum;
        VSCtl_aBrkReq = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);
    }
    else
    {
        VSCtl_aBrkEstim = (SInt16)VSINFO_0;
        VSCtl_aBrkReq = (SInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1462_Determiner_Acceleration_Gmp_Filtree
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F1462_Determiner_Acceleration_Gmp_Filtree(
                                 UInt8 VSCtl_stVehInfo_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.173.0 */
    SInt32 vsinfo_svalue;
    UInt16 vsinfo_racc_map_out;

    if((UInt32)VSCtl_stVehInfo_swc_in != (UInt32)VSCTL_STVEHINFO_NOMINAL_12)
    {
        VSCtl_aPT = (SInt16)VSINFO_0;
    }
    else if((UInt32)VSCtl_bInh_aPT == (UInt32)DDS_TRUE)
    {
        VSCtl_aPT = (SInt16)VSINFO_0;
    }
    else
    {
        if((UInt32)VSCtl_bDeac_rAccPTtqPT_C == (UInt32)DDS_TRUE)
        {
            vsinfo_svalue = (SInt32)VSCtl_rAccPTtqPT_C;
        }
        else
        {
            vsinfo_svalue = (SInt32)VSCtl_rAccPT;
        }

        /* BIN10: [-10;10] */
        vsinfo_svalue = (SInt32)DDS_M_BARY_FILTER_S16_V2(VSCtl_aPTReal,
                                                      VSCtl_aPTAplReq,
                                                      (SInt16)vsinfo_svalue,
                                                      (UInt16)VSINFO_100_BIN7);

        /* BIN10: [-20;20] */
        vsinfo_svalue = vsinfo_svalue + (SInt32)DDS_M_MAP2D_US16(&VSCTL_AOFSPT_SPDVEH_T_APM,VSCtl_spdVehFil);

        /* BIN20: [-40;40] */
        vsinfo_svalue = vsinfo_svalue * (SInt32)DDS_M_MAP2D_U16(&VSCTL_AGAINPT_SPDVEH_T_APM,VSCtl_spdVehFil);

        /* BIN10: [-40;40] */
        vsinfo_svalue = vsinfo_svalue / BIN10;

        /* BIN7: [0;100] */
        vsinfo_racc_map_out = DDS_M_MAP2D_U16(&VSCTL_RACCPT0_SPDVEH_T_APM,VSCtl_spdVehFil);

        /* BIN10: [-40;40] */
        vsinfo_svalue = DDS_M_BARY_FILTER_S32(VSINFO_0,
                                              vsinfo_svalue,
                                              vsinfo_racc_map_out,
                                              (UInt16)VSINFO_100_BIN7);

        VSCtl_aPT = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1463_Determiner_Acceleration_Frein_Filtree
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F1463_Determiner_Acceleration_Frein_Filtree(
                                 UInt8 VSCtl_stVehInfo_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.173.0 */
    SInt32 vsinfo_svalue;
    UInt16 vsinfo_racc_map_out;

    if((UInt32)VSCtl_stVehInfo_swc_in != (UInt32)VSCTL_STVEHINFO_NOMINAL_12)
    {
        VSCtl_aBrk = (SInt16)VSINFO_0;
    }
    else
    {
        if((UInt32)VSCtl_bDeac_rAccPTtqBrk_C != (UInt32)DDS_FALSE)
        {
            vsinfo_svalue = (SInt32)VSCtl_rAccPTtqBrk_C;
        }
        else
        {
            vsinfo_svalue = (SInt32)VSCtl_rAccPT;
        }

        /* BIN10: [-10;10] */
        vsinfo_svalue = (SInt32)DDS_M_BARY_FILTER_S16_V2(VSCtl_aBrkEstim,
                                                      VSCtl_aBrkReq,
                                                      (SInt16)vsinfo_svalue,
                                                      (UInt16)VSINFO_100_BIN7);

        /* BIN10: [-20;20] */
        vsinfo_svalue = vsinfo_svalue + (SInt32)DDS_M_MAP2D_US16(&VSCTL_AOFSBRK_SPDVEH_T_APM,VSCtl_spdVehFil);

        /* BIN20: [-40;40] */
        vsinfo_svalue = vsinfo_svalue * (SInt32)DDS_M_MAP2D_U16(&VSCTL_AGAINBRK_SPDVEH_T_APM,VSCtl_spdVehFil);

        /* BIN10: [-40;40] */
        vsinfo_svalue = vsinfo_svalue / BIN10;

        /* BIN7: [0;100] */
        vsinfo_racc_map_out = DDS_M_MAP2D_U16(&VSCTL_RACCBRK0_SPDVEH_T_APM,VSCtl_spdVehFil);

        /* BIN10: [-40;40] */
        vsinfo_svalue = DDS_M_BARY_FILTER_S32(VSINFO_0,
                                              vsinfo_svalue,
                                              vsinfo_racc_map_out,
                                              (UInt16)VSINFO_100_BIN7);

        VSCtl_aBrk = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_10_BIN10,VSINFO_10_BIN10);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Elabor_Car_Info_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Car_Info_Sl_Init(
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_mVeh_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rdWhl_swc_out /* BIN7 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_mVeh_swc_out = VSCtl_mVeh_C;
    *VSCtl_rdWhl_swc_out = VSCtl_rdWhl_C;
    VSCtl_aBrk = (SInt16)(0 * BIN10);
    VSCtl_aPT = (SInt16)(0 * BIN10);
    VSCtl_aPTAplReq = (SInt16)(0 * BIN10);
    VSCtl_aPTDrvMinReqRaw = (SInt16)(-10 * BIN10);
    VSCtl_aPTDrvMinReq = (SInt16)(-10 * BIN10);
    VSCtl_aPTIni = (SInt16)(0 * BIN10);
    VSCtl_aPTLim = (SInt16)(-10 * BIN10);
    VSCtl_aPTMaxNotCtla = (SInt16)(0 * BIN10);
    VSCtl_aPTMax = (SInt16)(10 * BIN10);
    VSCtl_aPTMinNotCtla = (SInt16)(0 * BIN10);
    VSCtl_aPTMin = (SInt16)(-10 * BIN10 );
    VSCtl_aPTPotMaxCtla_no1 = (SInt16)(10 * BIN10);
    VSCtl_aPTPotMax = (SInt16)(10 * BIN10);
    VSCtl_aPTPotMin = (SInt16)(-10 * BIN10);
    VSCtl_aPTPreCoVSCtlReq = (SInt16)(-10 * BIN10);
    VSCtl_spdVehFil = (UInt16)(0 * BIN7);
    VSCtl_SCXVeh = VSCtl_SCXVeh_C;

    /* ---- Init Global Datas ---- */
    VSCtl_aBrkEstim = (SInt16)(0 * BIN10);
    VSCtl_aBrkReq = (SInt16)(0 * BIN10);
    VSCtl_aPTReal = (SInt16)(0 * BIN10);

    /* ---- VSINFO_F142_Determiner_Parametres_Vehicule ---- */

    /* ---- VSINFO_F143_Filtrer_Vitesse_Vehicule ---- */
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsinfoh_f143_filtre_vitesse_vehicule,0);

    /* ---- VSINFO_F144_Determiner_Accelerations_Gmp ---- */

    /* ---- VSINFO_F145_Determiner_Acceleration_Frein ---- */

    /* ---- VSINFO_F1462_Determiner_Acceleration_Gmp_Filtree ---- */

    /* ---- VSINFO_F1463_Determiner_Acceleration_Frein_Filtree ---- */

}

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

