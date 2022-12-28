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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Get_Info_Gmp2_Sl.c
* Version int :/main/L01_02/1 Date: 4/1/2012 16 h 31 m User:esnault 
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 22/11/2011 14 h 3 m User:demezil 
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_020_IMPL1
*    comments :for VSInfo 12.0 : update calibrations value
* Version int :/main/L01_01/3 Date: 12/5/2011 8 h 48 m User:meme
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1_D
*    comments :for CPU load optimization
* Version dev :\main\branch_demezil_generic_view\1 Date: 10/5/2011 17 h 32 m User:demezil
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1_D
*    comments :for CPU load optimization
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 24 m User:meme
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 24/2/2011 14 h 42 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 15 m User:meme
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 8/2/2011 9 h 14 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/2/2011 18 h 16 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :for vSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 2/2/2011 17 h 45 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 1/2/2011 16 h 29 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :correct undisplayable data name
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 9 h 39 m User:morisseau
*    TWK_model:VSINFO_Get_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 25 m User:morisseau
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

#define VSC_ARRET           (UInt32)0
#define VSC_VERIF_2         (UInt32)1
#define VSC_DEFAUT_2        (UInt32)4

#define VSC_P2000_BIN4      (SInt32)(2000 * BIN4)
#define VSC_N2000_BIN4      (SInt32)(-2000 * BIN4)
#define VSC_0               (SInt32)0
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
extern VAR(UInt16, AUTOMATIC) VSCtl_rConvTraVirt_no1; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rConvTraVirt_no2; /* BIN7 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilEngInfo;
extern VAR(UInt8, AUTOMATIC) VSCtl_stEngInfo; /* BIN0 */
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
extern volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_nFrntWhl_C;
extern volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtl_Ini_C;
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

/* 16-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcAplReq; /* BIN4 */
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcIni; /* BIN4 */
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirt1; /* BIN4 */
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirt2; /* BIN4 */
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirt; /* BIN4 */
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtlMxReq; /* BIN4 */
VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcReal; /* BIN4 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_nEng_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcIni_Ini_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqCkEfcMaxCtla_SatMax_C = (CONST(UInt16, AUTOMATIC))(250 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqCkEfcMaxCtla_SatMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtlaOft_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtla_SatMn_C = (CONST(SInt16, AUTOMATIC))(-2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtla_SatMx_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinCtla_SatMax_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinCtla_SatMin_C = (CONST(SInt16, AUTOMATIC))(-50 * BIN4);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEngVirt_tqCkEfcMaxVirt_A[VSINFO_8_SIZE] = {
(UInt16)(1000 * BIN2), (UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2),
(UInt16)(2700 * BIN2), (UInt16)(3000 * BIN2), (UInt16)(3500 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(5000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_nEngVirt_tqCkEfcMinVirt_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN2), (UInt16)(500 * BIN2), (UInt16)(700 * BIN2),
(UInt16)(1000 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(5000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirt_nEngVirt_T
[VSINFO_8_SIZE] = {
(UInt16)(117.625 * BIN4), (UInt16)(140 * BIN4), (UInt16)(160 * BIN4),
(UInt16)(180 * BIN4), (UInt16)(200 * BIN4), (UInt16)(230 * BIN4),
(UInt16)(250 * BIN4), (UInt16)(250 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirt_nEngVirt_T
[VSINFO_8_SIZE] = {
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4),
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4),
(SInt16)(-50 * BIN4), (SInt16)(-50 * BIN4)
};

#define VSINFO_STOP_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tqckefcmaxvirt_nengvirt_t_sav[VSINFO_2_SIZE];
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_tqckefcminvirt_nengvirt_t_sav;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_f11212a_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f11213_filter_ptr;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
/* <PRQA_COMMENT><3229> displayable variable </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcDrvReq; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxCtla; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinCtla; /* BIN4 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSINFO_START_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_TQCKEFCMAXVIRT_NENGVIRT_T_APM[VSINFO_2_SIZE] = {
    {
        &vsctl_tqckefcmaxvirt_nengvirt_t_sav[0],
        VSINFO_8_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEngVirt_tqCkEfcMaxVirt_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMaxVirt_nEngVirt_T[0]
    },
    {
        &vsctl_tqckefcmaxvirt_nengvirt_t_sav[1],
        VSINFO_8_SIZE,
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEngVirt_tqCkEfcMaxVirt_A[0],
        (P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMaxVirt_nEngVirt_T[0]
    }
};

STATIC CONST(t_dds_m_map2d_us16, AUTOMATIC) VSCTL_TQCKEFCMINVIRT_NENGVIRT_T_APM = {
&vsctl_tqckefcminvirt_nengvirt_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_nEngVirt_tqCkEfcMinVirt_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tqCkEfcMinVirt_nEngVirt_T[0]
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

/*******************************************************************************
*
* Function Name : VSINFO_F11212_Determiner_Couples_Moteur
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11212_Determiner_Couples_Moteur(
                                   SInt16 EngLim_tqEfcMaxStatVehSpdCtl_swc_in, /* BIN4 */
                                   UInt32 Ext_nFrntWhl_swc_in, /* BIN7 */
                                   SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                   SInt16 TqDem_tqCkEfc_swc_in, /* BIN4 */
                                   SInt16 TqDem_tqCkEfcMax_swc_in, /* BIN4 */
                                   SInt16 TqDem_tqCkEfcMin_swc_in, /* BIN4 */
                                   SInt16 TqSys_tqCkEfcMinFeas_swc_in, /* BIN4 */
                                   SInt16 TqSys_tqCkEfcReq_swc_in, /* BIN4 */
                                   SInt16 TqSys_tqCkEngReal_swc_in, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMaxReq_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMinReq_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMax_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtla_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMin_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinNotCtla_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCMinReq_swc_out, /* BIN4 */
                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtlReq_swc_out /* BIN4 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.29.1 & CSMT_CGMT08_2268.FR.147.0*/
    UInt32 vsc_f11212a_filter_out;
    UInt32 vsc_temp_u32;
    SInt32 vsc_temp_s32;
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
    /* Calculate filters for F11212A */
    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFilEngInfo)
    {
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.46.1 */
        vsc_f11212a_filter_out = (UInt32)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f11212a_filter_ptr,
                                                            (SInt32)Ext_nFrntWhl_swc_in);
    }
    else
    {
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.46.1 */
        vsc_f11212a_filter_out = (UInt32)DDS_M_FILTER_LP1_S32(&vsinfo_f11212a_filter_ptr,
                                                         (SInt32)Ext_nFrntWhl_swc_in,
                                                         (UInt16)((UInt32)VSCtl_tiFil_nFrntWhl_C * BIN5));
    }
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
    /* Calculate output for (F112121 to F112129)*/
    if( (VSC_ARRET == (UInt32)VSCtl_stEngInfo)      ||
        (VSC_VERIF_2 == (UInt32)VSCtl_stEngInfo)    ||
        (VSC_DEFAUT_2 == (UInt32)VSCtl_stEngInfo)   )
    {
    /*---------------------- F112121 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.143.0 */
        VSCtl_tqCkEfcMinCtla = (SInt16)VSC_N2000_BIN4;
        VSCtl_tqCkEfcMaxCtla = (SInt16)VSC_P2000_BIN4;

    /*---------------------- F112122----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.144.0 */
        *VSCtl_tqCkEfcPreCoVSCMinReq_swc_out = (SInt16)VSC_N2000_BIN4;
        VSCtl_tqCkEfcPreCoVSCtlMxReq = (SInt16)VSC_P2000_BIN4;

    /*---------------------- F112123 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.36.1 */
        *VSCtl_tqCkEfcMin_swc_out = (SInt16)VSC_N2000_BIN4;
        *VSCtl_tqCkEfcMax_swc_out = (SInt16)VSC_P2000_BIN4;

    /*---------------------- F112124 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.37.1 */
        *VSCtl_tqCkEfcPreCoVSCtlReq_swc_out = VSCtl_tqCkEfcPreCoVSCtl_Ini_C;

    /*---------------------- F112125 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.38.1 */
        *VSCtl_tqCkEfcDrvMaxReq_swc_out = (SInt16)VSC_P2000_BIN4;
        VSCtl_tqCkEfcDrvReq = (SInt16)VSC_0;
        *VSCtl_tqCkEfcDrvMinReq_swc_out = (SInt16)VSC_N2000_BIN4;

    /*---------------------- F112126 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.145.0 */
        VSCtl_tqCkEfcAplReq = (SInt16)VSC_0;

    /*---------------------- F112127 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.43.1 */
        VSCtl_tqCkEfcReal = (SInt16)VSC_0;

    /*---------------------- F112128 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.44.1 */
        VSCtl_tqCkEfcIni = (SInt16)VSC_0;

    /*---------------------- F112129 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.146.0 */
        *VSCtl_tqCkEfcMaxNotCtla_swc_out = (SInt16)VSC_0;
        *VSCtl_tqCkEfcMinNotCtla_swc_out = (SInt16)VSC_0;

    /*---------------------- F11212A ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.46.1 */
        VSCtl_tqCkEfcMaxVirt1 = (SInt16)VSC_P2000_BIN4;
        VSCtl_tqCkEfcMaxVirt2 = (SInt16)VSC_P2000_BIN4;
        VSCtl_tqCkEfcMinVirt = (SInt16)VSC_N2000_BIN4;
    }
    else
    {
    /*---------------------- F112121 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.143.0 */
        VSCtl_tqCkEfcMinCtla = (SInt16)DDS_M_SATURATION_V2(-(SInt32)TqCmp_tqSumLossCmp_swc_in,
                                                            (SInt32)VSCtl_tqCkEfcMinCtla_SatMin_C,
                                                            (SInt32)VSCtl_tqCkEfcMinCtla_SatMax_C);

        VSCtl_tqCkEfcMaxCtla = (SInt16)DDS_M_SATURATION_V2((SInt32)EngLim_tqEfcMaxStatVehSpdCtl_swc_in,
                                                            (SInt32)VSCtl_tqCkEfcMaxCtla_SatMin_C,
                                                            (SInt32)VSCtl_tqCkEfcMaxCtla_SatMax_C);

    /*---------------------- F112122 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.144.0 */
        *VSCtl_tqCkEfcPreCoVSCMinReq_swc_out = (SInt16)DDS_M_MIN((SInt32)TqDem_tqCkEfcMin_swc_in,VSC_0);
        VSCtl_tqCkEfcPreCoVSCtlMxReq = (SInt16)DDS_M_MAX((SInt32)TqDem_tqCkEfcMax_swc_in,VSC_0);

    /*---------------------- F112123 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.36.1 */
        *VSCtl_tqCkEfcMin_swc_out = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_tqCkEfcMinCtla,
                                                            (SInt32)(*VSCtl_tqCkEfcPreCoVSCMinReq_swc_out),
                                                            VSC_0);

        *VSCtl_tqCkEfcMax_swc_out = (SInt16)DDS_M_LIMIT_V2((SInt32)VSCtl_tqCkEfcMaxCtla,
                                                        VSC_0,
                                                        (SInt32)VSCtl_tqCkEfcPreCoVSCtlMxReq);

    /*---------------------- F112124 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.37.1 */
        *VSCtl_tqCkEfcPreCoVSCtlReq_swc_out = (SInt16)DDS_M_SATURATION_V2((SInt32)TqDem_tqCkEfc_swc_in,
                                                                        (SInt32)(*VSCtl_tqCkEfcMin_swc_out),
                                                                        (SInt32)(*VSCtl_tqCkEfcMax_swc_out));

    /*---------------------- F112125 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.38.1 */
        *VSCtl_tqCkEfcDrvMinReq_swc_out = (SInt16)DDS_M_MIN((SInt32)TqDem_tqCkEfcMin_swc_in,VSC_0);
        *VSCtl_tqCkEfcDrvMaxReq_swc_out = (SInt16)DDS_M_MAX((SInt32)TqDem_tqCkEfcMax_swc_in,VSC_0);
        VSCtl_tqCkEfcDrvReq = (SInt16)DDS_M_SATURATION_V2((SInt32)TqDem_tqCkEfc_swc_in,
                                                            (SInt32)(*VSCtl_tqCkEfcDrvMinReq_swc_out),
                                                            (SInt32)(*VSCtl_tqCkEfcDrvMaxReq_swc_out));

    /*---------------------- F112126 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.145.0 */
        VSCtl_tqCkEfcAplReq = (SInt16)DDS_M_SATURATION_V2((SInt32)TqSys_tqCkEfcReq_swc_in,
                                                            (SInt32)(*VSCtl_tqCkEfcMin_swc_out),
                                                            (SInt32)(*VSCtl_tqCkEfcMax_swc_out));

    /*---------------------- F112127 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.43.1 */
        VSCtl_tqCkEfcReal = (SInt16)DDS_M_SATURATION_V2((SInt32)TqSys_tqCkEngReal_swc_in,
                                                            (SInt32)(*VSCtl_tqCkEfcMin_swc_out),
                                                            (SInt32)(*VSCtl_tqCkEfcMax_swc_out));

    /*---------------------- F112128 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.44.1 */
        VSCtl_tqCkEfcIni = (SInt16)DDS_M_SATURATION_V2((SInt32)VSCtl_tqCkEfcIni_Ini_C,
                                                            (SInt32)(VSCtl_tqCkEfcMinCtla),
                                                            (SInt32)(*VSCtl_tqCkEfcMax_swc_out));

    /*---------------------- F112129 ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.146.0 */
        *VSCtl_tqCkEfcMinNotCtla_swc_out = (SInt16)DDS_M_MIN((SInt32)(*VSCtl_tqCkEfcMin_swc_out), (SInt32)(*VSCtl_tqCkEfcMax_swc_out));

        vsc_temp_s32 = (SInt32)VSCtl_tqCkEfcMinCtla + (SInt32)VSCtl_tqCkEfcMaxNotCtlaOft_C;
        vsc_temp_s32 = DDS_M_MAX(vsc_temp_s32, (SInt32)TqSys_tqCkEfcMinFeas_swc_in);

        vsc_temp_s32 = DDS_M_SATURATION_V2(vsc_temp_s32,
                                            (SInt32)VSCtl_tqCkEfcMaxNotCtla_SatMn_C,
                                            (SInt32)VSCtl_tqCkEfcMaxNotCtla_SatMx_C);

        *VSCtl_tqCkEfcMaxNotCtla_swc_out = (SInt16)DDS_M_SATURATION_V2(vsc_temp_s32,
                                                                    (SInt32)(*VSCtl_tqCkEfcMin_swc_out),
                                                                    (SInt32)(*VSCtl_tqCkEfcMax_swc_out));

    /*---------------------- F11212A ----------------------*/
        /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.46.1 */
        /* BIN2 = (BIN7 * BIN7) / BIN12*/
        vsc_temp_u32 = (vsc_f11212a_filter_out * (UInt32)VSCtl_rConvTraVirt_no1) / BIN12;
        vsc_temp_u32 = DDS_M_MIN(vsc_temp_u32,DDS_UINT16_MAX);

        VSCtl_tqCkEfcMaxVirt1 = (SInt16)DDS_M_MAP2D_U16(&VSCTL_TQCKEFCMAXVIRT_NENGVIRT_T_APM[0],
                                                                    (UInt16)vsc_temp_u32);

        /* BIN2 = (BIN7 * BIN7) / BIN12*/
        vsc_temp_u32 = (vsc_f11212a_filter_out * (UInt32)VSCtl_rConvTraVirt_no2) / BIN12;
        vsc_temp_u32 = DDS_M_MIN(vsc_temp_u32,DDS_UINT16_MAX);

        VSCtl_tqCkEfcMaxVirt2 = (SInt16)DDS_M_MAP2D_U16(&VSCTL_TQCKEFCMAXVIRT_NENGVIRT_T_APM[1],
                                                                    (UInt16)vsc_temp_u32);

        VSCtl_tqCkEfcMinVirt = DDS_M_MAP2D_US16(&VSCTL_TQCKEFCMINVIRT_NENGVIRT_T_APM,
                                                        (UInt16)vsc_temp_u32);
    }
}


/*******************************************************************************
*
* Function Name : VSINFO_F11213_Determiner_Regime_Moteur_Filtree
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11213_Determiner_Regime_Moteur_Filtree(
                                      UInt16 Ext_nEng_swc_in, /* BIN0 */
                                      CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nEngFil_swc_out /* BIN0 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.147.0 */
    UInt32 vsc_f11213_filter_out;

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFilEngInfo)
    {
        vsc_f11213_filter_out = (UInt32)DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f11213_filter_ptr,
                                                                    Ext_nEng_swc_in);
    }
    else
    {
        vsc_f11213_filter_out = (UInt32)DDS_M_FILTER_LP1_U16(&vsinfo_f11213_filter_ptr,
                                                             Ext_nEng_swc_in,
                                                             VSCtl_tiFil_nEng_C,
                                                             BIN10);
    }

    if( (VSC_ARRET == (UInt32)VSCtl_stEngInfo)      ||
        (VSC_VERIF_2 == (UInt32)VSCtl_stEngInfo)    ||
        (VSC_DEFAUT_2 == (UInt32)VSCtl_stEngInfo)   )
    {
        *VSCtl_nEngFil_swc_out = (UInt32)VSC_0;
    }
    else
    {
        *VSCtl_nEngFil_swc_out = vsc_f11213_filter_out;
    }
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/* None */


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Get_Info_Gmp2_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Get_Info_Gmp2_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMaxReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcDrvMinReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMax_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMaxNotCtla_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMin_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcMinNotCtla_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCMinReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtlReq_swc_out, /* BIN4 */
                                        CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nEngFil_swc_out /* BIN0 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_tqCkEfcDrvMaxReq_swc_out = (SInt16)(2000 * BIN4);
    *VSCtl_tqCkEfcDrvMinReq_swc_out = (SInt16)(-2000 * BIN4);
    *VSCtl_tqCkEfcMax_swc_out = (SInt16)(2000 * BIN4);
    *VSCtl_tqCkEfcMaxNotCtla_swc_out = (SInt16)(0 * BIN4);
    *VSCtl_tqCkEfcMin_swc_out = (SInt16)(-2000 * BIN4);
    *VSCtl_tqCkEfcMinNotCtla_swc_out = (SInt16)(0 * BIN4);
    *VSCtl_tqCkEfcPreCoVSCMinReq_swc_out = (SInt16)(-2000 * BIN4);
    *VSCtl_tqCkEfcPreCoVSCtlReq_swc_out = VSCtl_tqCkEfcPreCoVSCtl_Ini_C;
    *VSCtl_nEngFil_swc_out = (UInt32)(0 * BIN0);

    /* ---- Init Global Datas ---- */
    VSCtl_tqCkEfcAplReq = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcDrvReq = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcIni = (SInt16)(0 * BIN4);
    VSCtl_tqCkEfcMaxCtla = (SInt16)(2000 * BIN4);
    VSCtl_tqCkEfcMaxVirt1 = (SInt16)(2000 * BIN4);
    VSCtl_tqCkEfcMaxVirt2 = (SInt16)(2000 * BIN4);
    VSCtl_tqCkEfcMinCtla = (SInt16)(-2000 * BIN4);
    VSCtl_tqCkEfcMinVirt = (SInt16)(-2000 * BIN4);
    VSCtl_tqCkEfcPreCoVSCtlMxReq = (SInt16)(2000 * BIN4);
    VSCtl_tqCkEfcReal = (SInt16)(0 * BIN4);

    /* F11212A */
    (void)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f11212a_filter_ptr,0);

    /* VSINFO_F11213_Determiner_Regime_Moteur_Filtree */
    (void)DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f11213_filter_ptr,0);

}

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

