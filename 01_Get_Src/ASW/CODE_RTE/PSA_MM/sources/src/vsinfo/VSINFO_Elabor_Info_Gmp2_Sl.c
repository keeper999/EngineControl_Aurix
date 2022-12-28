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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Elabor_Info_Gmp2_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 6 m User:meme 
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 6 m User:demezil 
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 15 m User:meme
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 2/2/2011 17 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 19 h 30 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L01_010_IMPL1
*    comments :add init of internal var
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 21/12/2010 19 h 25 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Gmp2_Sl_L01_010_IMPL1
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

#define VSINFO_0                (0)
#define VSINFO_100_BIN7         (100 * BIN7)
#define VSINFO_16000_BIN1       (16000 * BIN1)


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
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcPreCoVSCtlMxReq; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcAplReq; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcReal; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcIni; /* BIN4 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rConvTraVirt_no1; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_rConvTraVirt_no2; /* BIN7 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirt1; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMaxVirt2; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqCkEfcMinVirt; /* BIN4 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stPTInfo_pt2;
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

/* 16-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMinNotCtla_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMaxNotCtla_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMn_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlMx_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMin_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTMax_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPreCVSCtlRq_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMinReq_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTDrvMaxReq_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTAplReq_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTReal_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTIni_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMax_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMin_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMax_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRawMin_pt2; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMxCtla1_pt2; /* BIN1 */
VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTDrvReq_pt2; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_rTqWhlPTRe_pt2; /* BIN7 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bCtlaTqPT_pt2;
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
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl1pt2Mn_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl1pt2Mx_C = (CONST(SInt16, AUTOMATIC))(16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl2pt2Mn_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtl2pt2Mx_C = (CONST(SInt16, AUTOMATIC))(16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtlpt2Mn_C = (CONST(SInt16, AUTOMATIC))(-16000 * BIN1);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtlpt2Mx_C = (CONST(SInt16, AUTOMATIC))(0 * BIN1);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rTqWhlPTReIni_pt2_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMaxCtla2_pt2; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRwMxCtl2_pt2; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotMinCtla_pt2; /* BIN1 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPTPotRwMnCtla_pt2; /* BIN1 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

STATIC FUNC(void, AUTOMATIC) VSINFO_F112341_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable(
                                                    SInt16 vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                                                    SInt16 vsctl_tqwhlpotminrsvhithd_par  /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F112342_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable(
                                                    SInt16 vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                                                    SInt16 vsctl_tqwhlpotminrsvlothd_par  /* BIN1 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F112343_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max(void);

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
*
* Function Name : VSINFO_F11233_Determiner_Couples_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11233_Determiner_Couples_Roue_Gmp(
                                                    UInt16 VSCtl_rConvTra_swc_in, /* BIN7 */
                                                    SInt16 VSCtl_tqCkEfcDrvMaxReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcDrvMinReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMaxNotCtla_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMax_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMinNotCtla_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcMin_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcPreCoVSCMinReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqCkEfcPreCoVSCtlReq_swc_in, /* BIN4 */
                                                    SInt16 VSCtl_tqLossTra_swc_in /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.178.0 */
    SInt32 vsinfo_svalue;

    if((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_NOMINAL_1)
    {
        /* [-80000;80000] = ([-2000;2000] + [-2000;2000]) * [0;20] */
        /* BIN1 = (BIN4 + BIN4) * BIN7 / BIN10 */

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcMinNotCtla_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTMinNotCtla_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcMaxNotCtla_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTMaxNotCtla_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcPreCoVSCMinReq_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTPreCVSCtlMn_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcPreCoVSCtlMxReq + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTPreCVSCtlMx_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcMin_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTMin_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcMax_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTMax_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcPreCoVSCtlReq_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTPreCVSCtlRq_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcDrvMinReq_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTDrvMinReq_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcDrvMaxReq_swc_in + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTDrvMaxReq_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcAplReq + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTAplReq_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcReal + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTReal_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);

        vsinfo_svalue = (((SInt32)VSCtl_tqCkEfcIni + (SInt32)VSCtl_tqLossTra_swc_in) * (SInt32)VSCtl_rConvTra_swc_in) / BIN10;
        VSCtl_tqWhlPTIni_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlPTMinNotCtla_pt2 = (SInt16)(0 * BIN1);
        VSCtl_tqWhlPTMaxNotCtla_pt2 = (SInt16)(0 * BIN1);
        VSCtl_tqWhlPTPreCVSCtlMn_pt2 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlPTPreCVSCtlMx_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTMin_pt2 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlPTMax_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTPreCVSCtlRq_pt2 = VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
        VSCtl_tqWhlPTDrvMinReq_pt2 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlPTDrvMaxReq_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTAplReq_pt2 = (SInt16)(0 * BIN1);
        VSCtl_tqWhlPTReal_pt2 = (SInt16)(0 * BIN1);
        VSCtl_tqWhlPTIni_pt2 = (SInt16)(0 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11234_Determiner_Potentiels_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11234_Determiner_Potentiels_Couple_Roue_Gmp(
                                                    SInt16 VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPotMinRsvHiThd_swc_in, /* BIN1 */
                                                    SInt16 VSCtl_tqWhlPotMinRsvLoThd_swc_in  /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.22.2 */
    VSINFO_F112341_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable(
                                                    VSCtl_tqWhlPotMaxRsvHiThd_swc_in, /* BIN1 */
                                                    VSCtl_tqWhlPotMinRsvHiThd_swc_in  /* BIN1 */);

    VSINFO_F112342_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable(
                                                    VSCtl_tqWhlPotMaxRsvLoThd_swc_in, /* BIN1 */
                                                    VSCtl_tqWhlPotMinRsvLoThd_swc_in  /* BIN1 */);

    VSINFO_F112343_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max();
}

/*******************************************************************************
*
* Function Name : VSINFO_F112341_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F112341_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable(
                                                    SInt16 vsctl_tqwhlpotmaxrsvhithd_par, /* BIN1 */
                                                    SInt16 vsctl_tqwhlpotminrsvhithd_par  /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.23.2 */
    SInt32 vsinfo_svalue;

    if(  ((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        /* [-40000;40000] = [-2000;2000] * [0;20] */
        /* BIN1 = BIN4 * BIN7 / BIN10 */
        vsinfo_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirt1 * (SInt32)VSCtl_rConvTraVirt_no1) / BIN10;
        VSCtl_tqWhlPTPotMxCtla1_pt2 = (SInt16)DDS_M_SATURATION_V2(vsinfo_svalue,
                                                                  (SInt32)VSCtl_tqWhlPTPotMaxCtl1pt2Mn_C,
                                                                  (SInt32)VSCtl_tqWhlPTPotMaxCtl1pt2Mx_C);

        /* [-40000;40000] = [-2000;2000] * [0;20] */
        /* BIN1 = BIN4 * BIN7 / BIN10 */
        vsinfo_svalue = ((SInt32)VSCtl_tqCkEfcMaxVirt2 * (SInt32)VSCtl_rConvTraVirt_no2) / BIN10;
        VSCtl_tqWhlPTPotRwMxCtl2_pt2 = (SInt16)DDS_M_SATURATION_V2(vsinfo_svalue,
                                                                  (SInt32)VSCtl_tqWhlPTPotMaxCtl2pt2Mn_C,
                                                                  (SInt32)VSCtl_tqWhlPTPotMaxCtl2pt2Mx_C);

        vsinfo_svalue = (SInt32)VSCtl_tqWhlPTPotRwMxCtl2_pt2 + DDS_M_MAX((SInt32)vsctl_tqwhlpotmaxrsvhithd_par,
                                                                         (SInt32)vsctl_tqwhlpotminrsvhithd_par);

        VSCtl_tqWhlPTPotMaxCtla2_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlPTPotMxCtla1_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTPotRwMxCtl2_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTPotMaxCtla2_pt2 = (SInt16)(16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F112342_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F112342_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable(
                                                    SInt16 vsctl_tqwhlpotmaxrsvlothd_par, /* BIN1 */
                                                    SInt16 vsctl_tqwhlpotminrsvlothd_par  /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.24.2 */
    SInt32 vsinfo_svalue;

    if(  ((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        /* [-40000;40000] = [-2000;2000] * [0;20] */
        /* BIN1 = BIN4 * BIN7 / BIN10 */
        vsinfo_svalue = ((SInt32)VSCtl_tqCkEfcMinVirt * (SInt32)VSCtl_rConvTraVirt_no2) / BIN10;
        VSCtl_tqWhlPTPotRwMnCtla_pt2 = (SInt16)DDS_M_SATURATION_V2(vsinfo_svalue,
                                                                  (SInt32)VSCtl_tqWhlPTPotMinCtlpt2Mn_C,
                                                                  (SInt32)VSCtl_tqWhlPTPotMinCtlpt2Mx_C);

        vsinfo_svalue = (SInt32)VSCtl_tqWhlPTPotRwMnCtla_pt2 - DDS_M_MAX((SInt32)vsctl_tqwhlpotmaxrsvlothd_par,
                                                                         (SInt32)vsctl_tqwhlpotminrsvlothd_par);

        VSCtl_tqWhlPTPotMinCtla_pt2 = (SInt16)DDS_M_LIMIT(vsinfo_svalue,-VSINFO_16000_BIN1,VSINFO_16000_BIN1);
    }
    else
    {
        VSCtl_tqWhlPTPotRwMnCtla_pt2 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlPTPotMinCtla_pt2 = (SInt16)(-16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F112343_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F112343_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.25.1 */
    if(  ((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_INIT_1)
       ||((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_NOMINAL_1))
    {
        VSCtl_tqWhlPTPotMax_pt2 = VSCtl_tqWhlPTPotMaxCtla2_pt2;
        VSCtl_tqWhlPTPotMin_pt2 = VSCtl_tqWhlPTPotMinCtla_pt2;
        VSCtl_tqWhlPTPotRawMax_pt2 = VSCtl_tqWhlPTPotRwMxCtl2_pt2;
        VSCtl_tqWhlPTPotRawMin_pt2 = VSCtl_tqWhlPTPotRwMnCtla_pt2;
    }
    else
    {
        VSCtl_tqWhlPTPotMax_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTPotMin_pt2 = (SInt16)(-16000 * BIN1);
        VSCtl_tqWhlPTPotRawMax_pt2 = (SInt16)(16000 * BIN1);
        VSCtl_tqWhlPTPotRawMin_pt2 = (SInt16)(-16000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11235_Determiner_Pilotabilite_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11235_Determiner_Pilotabilite_Couple_Roue_Gmp(
                                                    UInt8 InjSys_bFuCutOff_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.154.0 */
    if(  ((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_NOMINAL_1)
       &&((UInt32)InjSys_bFuCutOff_swc_in != (UInt32)DDS_TRUE))
    {
        VSCtl_bCtlaTqPT_pt2 = DDS_TRUE;
    }
    else
    {
        VSCtl_bCtlaTqPT_pt2 = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11236_Determiner_Consigne_Couple_Roue_Gmp_Normee
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11236_Determiner_Consigne_Couple_Roue_Gmp_Normee(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.155.0 */
    SInt32 vsinfo_svalue;
    SInt32 vsinfo_numerator;
    SInt32 vsinfo_divi_1;
    SInt32 vsinfo_divi_2;

    if((UInt32)VSCtl_stPTInfo_pt2 == (UInt32)VSCTL_STPTINFO_NOMINAL_1)
    {
        if((SInt32)VSCtl_tqWhlPTAplReq_pt2 != VSINFO_0)
        {
            /* BIN8: [-3200000;3200000] */
            vsinfo_numerator = (SInt32)VSCtl_tqWhlPTAplReq_pt2 * (100 * BIN7);

            if((SInt32)VSCtl_tqWhlPTDrvMaxReq_pt2 != VSINFO_0)
            {
                vsinfo_divi_1 = VSCtl_tqWhlPTDrvMaxReq_pt2;
            }
            else
            {
                vsinfo_divi_1 = 1;
            }
            vsinfo_divi_1 = vsinfo_numerator / vsinfo_divi_1;
            vsinfo_divi_1 = DDS_M_LIMIT(vsinfo_divi_1,VSINFO_0,VSINFO_100_BIN7);

            if((SInt32)VSCtl_tqWhlPTDrvMinReq_pt2 != VSINFO_0)
            {
                vsinfo_divi_2 = VSCtl_tqWhlPTDrvMinReq_pt2;
            }
            else
            {
                vsinfo_divi_2 = 1;
            }
            vsinfo_divi_2 = vsinfo_numerator / vsinfo_divi_2;
            vsinfo_divi_2 = DDS_M_LIMIT(vsinfo_divi_2,-VSINFO_100_BIN7,VSINFO_0);

            vsinfo_svalue = vsinfo_divi_1 + vsinfo_divi_2;
            VSCtl_rTqWhlPTDrvReq_pt2 = (UInt16)DDS_M_MAX(vsinfo_svalue,VSINFO_0);
        }
        else
        {
            VSCtl_rTqWhlPTDrvReq_pt2 = (UInt16)VSINFO_0;
        }
    }
    else
    {
        VSCtl_rTqWhlPTDrvReq_pt2 = (UInt16)(0 * BIN7);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F11237_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11237_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.81.1 */
    VSCtl_rTqWhlPTRe_pt2 = VSCtl_rTqWhlPTReIni_pt2_C;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Elabor_Info_Gmp2_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Gmp2_Sl_Init(void)
{
    /* ---- Init Outputs ---- */
    VSCtl_bCtlaTqPT_pt2 = DDS_FALSE;
    VSCtl_rTqWhlPTDrvReq_pt2 = (UInt16)(0 * BIN7);
    VSCtl_rTqWhlPTRe_pt2 = VSCtl_rTqWhlPTReIni_pt2_C;
    VSCtl_tqWhlPTAplReq_pt2 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTDrvMaxReq_pt2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTDrvMinReq_pt2 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTIni_pt2 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTMaxNotCtla_pt2 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTMax_pt2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTMinNotCtla_pt2 = (SInt16)(0 * BIN1);
    VSCtl_tqWhlPTMin_pt2 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPotMax_pt2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotMin_pt2 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPotMxCtla1_pt2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotRawMax_pt2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotRawMin_pt2 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPreCVSCtlMn_pt2 = (SInt16)(-16000 * BIN1);
    VSCtl_tqWhlPTPreCVSCtlMx_pt2 = (SInt16)(16000* BIN1);
    VSCtl_tqWhlPTPreCVSCtlRq_pt2 = VSCtl_tqWhlPTPreCoVSCtl_Ini_C;
    VSCtl_tqWhlPTReal_pt2 = (SInt16)(0 * BIN1);

    /* ---- Init Global Datas ---- */
    VSCtl_tqWhlPTPotMaxCtla2_pt2 = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPTPotMinCtla_pt2 = (SInt16)(-16000* BIN1);
    VSCtl_tqWhlPTPotRwMnCtla_pt2 = (SInt16)(-16000* BIN1);
    VSCtl_tqWhlPTPotRwMxCtl2_pt2 = (SInt16)(16000 * BIN1);

    /* ---- VSINFO_F11233_Determiner_Couples_Roue_Gmp ---- */

    /* ---- VSINFO_F11234_Determiner_Potentiels_Couple_Roue_Gmp ---- */

    /* ---- VSINFO_F112341_Determiner_Potentiels_Couple_Roue_Gmp_Max_Pilotable ---- */

    /* ---- VSINFO_F112342_Determiner_Potentiel_Couple_Roue_Gmp_Min_Pilotable ---- */

    /* ---- VSINFO_F112343_Determiner_Potentiels_Couple_Roue_Gmp_Min_Max ---- */

    /* ---- VSINFO_F11235_Determiner_Pilotabilite_Couple_Roue_Gmp ---- */

    /* ---- VSINFO_F11236_Determiner_Consigne_Couple_Roue_Gmp_Normee ---- */

    /* ---- VSINFO_F11237_Determiner_Taux_Repartition_Couple_Roue_Gmp_Ar ---- */

}



#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

