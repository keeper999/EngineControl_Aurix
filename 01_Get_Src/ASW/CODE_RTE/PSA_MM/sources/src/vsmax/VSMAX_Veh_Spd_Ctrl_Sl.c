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
* Ref X:\integration_view_00PSASWC_D610D01\blois_psa_sstg\Software\Appli\VSMax\src\VSMAX_Veh_Spd_Ctrl_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 10 h 48 m User:meme 
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L02_010_IMPL1
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\3 Date: 1/8/2011 16 h 30 m User:demezil 
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L02_010_IMPL1
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\2 Date: 18/7/2011 10 h 46 m User:demezil
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L02_010_IMPL1
*    comments :for VSMax 11.0
* Version dev :\main\branch_demezil_vsmax_view\1 Date: 12/7/2011 16 h 24 m User:demezil
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL2_D
*    comments :for VSMax 11.0
* Version int :/main/L01_01/2 Date: 3/2/2011 15 h 9 m User:esnault
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL2
*    comments :for VSMax 10.0
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\4 Date: 21/1/2011 14 h 50 m User:demezil
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL2
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\3 Date: 18/1/2011 8 h 14 m User:demezil
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 17/1/2011 17 h 52 m User:demezil
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 17/1/2011 17 h 52 m User:lemort
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 17/1/2011 17 h 51 m User:lemort
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 17/1/2011 17 h 50 m User:lemort
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\1 Date: 17/12/2010 14 h 13 m User:lemort
*    TWK_model:VSMAX_Veh_Spd_Ctrl_Sl_L01_010_IMPL1
*    comments :dev VSMax 10.0
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/


#include "VSMax.h"



/*******************************************************************************
* File Macro Definitions
*******************************************************************************/






/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stSpdVehCritModClc; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stSpdVehCritFilModClc; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxc;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxf;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxp;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvVSMaxs;
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"


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


/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxc; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxf; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxp; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxs; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_spdVehCrit;
VAR(UInt16, AUTOMATIC) VSCtl_spdVehVSMaxReqInt; /* BIN7 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"

/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"




/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSMAX_START_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_spdVehCritOfs_C = (CONST(SInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxFRM_no1_C = (CONST(UInt16, AUTOMATIC))(120 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehReqVSMaxFRM_no2_C = (CONST(UInt16, AUTOMATIC))(30 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehVSMaxFixReq_C = (CONST(UInt16, AUTOMATIC))(255 * BIN7);
#define VSMAX_STOP_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"



/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSMAX_START_SEC_CARTO_16BIT
#include "VSMax_MemMap.h"

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVehCrit_spdVeh_T
[VSC_8_SIZE] = {
(UInt16)(255 * BIN7), (UInt16)(255 * BIN7), (UInt16)(255 * BIN7),
(UInt16)(255 * BIN7), (UInt16)(255 * BIN7), (UInt16)(255 * BIN7),
(UInt16)(255 * BIN7), (UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_spdVehCrit_A[VSC_8_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(10 * BIN7), (UInt16)(20 * BIN7),
(UInt16)(40 * BIN7), (UInt16)(60 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(150 * BIN7), (UInt16)(200 * BIN7)
};

#define VSMAX_STOP_SEC_CARTO_16BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSMAX_START_SEC_VAR_UNSPECIFIED
#include "VSMax_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_spdvehcrit_spdveh_t_sav;
#define VSMAX_STOP_SEC_VAR_UNSPECIFIED
#include "VSMax_MemMap.h"

/* 16bit variable definition */
#define VSMAX_START_SEC_VAR_16BIT
#include "VSMax_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) vsmax_f52142_swcitch_input_prev; /* BIN7 */
#define VSMAX_STOP_SEC_VAR_16BIT
#include "VSMax_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/


/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSMAX_START_SEC_CONST_UNSPECIFIED
#include "VSMax_MemMap.h"


STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_SPDVEHCRIT_SPDVEH_T_APM = {
&vsctl_spdvehcrit_spdveh_t_sav,
VSC_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_spdVehCrit_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVehCrit_spdVeh_T[0]
};



#define VSMAX_STOP_SEC_CONST_UNSPECIFIED
#include "VSMax_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSMAX_START_SEC_CODE
#include "VSMax_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_swc_inamtype parameter); */




/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/




/*******************************************************************************
*
* Function Name : VSMAX_F5211_Determiner_Consigne_Vitesse_Bvvf
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5211_Determiner_Consigne_Vitesse_Bvvf(
                            UInt8 Ext_bVSMaxfCf_swc_in,
                            UInt8 FRM_bDeacRvVSMaxf_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.51.0 */

    if((UInt32)Ext_bVSMaxfCf_swc_in != (UInt32)DDS_TRUE)
    {
        VSCtl_spdVehReqVSMaxf = (UInt16)VSMAX_255_BIN7;
    }
    else if((UInt32)FRM_bDeacRvVSMaxf_swc_in != (UInt32)DDS_TRUE)
    {
        VSCtl_spdVehReqVSMaxf = VSCtl_spdVehVSMaxFixReq_C;
    }
    else
    {
        VSCtl_spdVehReqVSMaxf = (UInt16)VSMAX_255_BIN7;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5212_Determiner_Consigne_Vitesse_Bvvp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5212_Determiner_Consigne_Vitesse_Bvvp(
                            UInt8 Ext_bVSMaxpCf_swc_in,
                            UInt8 Ext_spdVehVSMaxPrmaReq_swc_in,
                            UInt8 FRM_bDeacRvVSMaxp_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.52.0 */

    if((UInt32)Ext_bVSMaxpCf_swc_in != (UInt32)DDS_TRUE)
    {
        VSCtl_spdVehReqVSMaxp = (UInt16)VSMAX_255_BIN7;
    }
    else if((UInt32)FRM_bDeacRvVSMaxp_swc_in != (UInt32)DDS_TRUE)
    {
        VSCtl_spdVehReqVSMaxp = (UInt16)((UInt32)Ext_spdVehVSMaxPrmaReq_swc_in * BIN7);
    }
    else
    {
        VSCtl_spdVehReqVSMaxp = (UInt16)VSMAX_255_BIN7;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5213_Determiner_Consigne_Vitesse_Bvvs
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5213_Determiner_Consigne_Vitesse_Bvvs(
                            UInt8 Ext_bVSMaxsCf_swc_in,
                            UInt8 FRM_bAcvVSMax_no1_swc_in,
                            UInt8 FRM_bAcvVSMax_no2_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.53.0 */
    UInt32 vsmax_uvalue_1;
    UInt32 vsmax_uvalue_2;

    if((UInt32)Ext_bVSMaxsCf_swc_in != (UInt32)DDS_TRUE)
    {
        VSCtl_spdVehReqVSMaxs = (UInt16)VSMAX_255_BIN7;
    }
    else
    {
        if((UInt32)FRM_bAcvVSMax_no1_swc_in != (UInt32)DDS_TRUE)
        {
            vsmax_uvalue_1 = VSMAX_255_BIN7;
        }
        else
        {
            vsmax_uvalue_1 = VSCtl_spdVehReqVSMaxFRM_no1_C;
        }

        if((UInt32)FRM_bAcvVSMax_no2_swc_in != (UInt32)DDS_TRUE)
        {
            vsmax_uvalue_2 = VSMAX_255_BIN7;
        }
        else
        {
            vsmax_uvalue_2 = (UInt32)VSCtl_spdVehReqVSMaxFRM_no2_C;
        }

        VSCtl_spdVehReqVSMaxs = (UInt16)DDS_M_MIN(vsmax_uvalue_1,vsmax_uvalue_2);
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F52142_Determiner_Consigne_Vitesse_Bvvc
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F52142_Determiner_Consigne_Vitesse_Bvvc(
                            UInt8 VehEst_spdVehCrit_swc_in, /* BIN0 */
                            UInt16 VSCtl_spdVeh_swc_in /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.56.0 */
    UInt32 vsmax_uvalue;
    SInt32 vsmax_svalue;

    vsmax_uvalue = (UInt32)DDS_M_MAP2D_U16(&VSCTL_SPDVEHCRIT_SPDVEH_T_APM,VSCtl_spdVeh_swc_in);
/* <PRQA_COMMENT><3346> statement value change with VSCtl_bCtlCmdPTTqCf_SC </3346></PRQA_COMMENT> */
    if((UInt32)VSCtl_bCtlCmdPTTqCf_SC != (UInt32)DDS_TRUE)
    {
        VSCtl_spdVehCrit = (UInt16)vsmax_uvalue;
    }
    else
/* <PRQA_COMMENT><3201> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </3201></PRQA_COMMENT> */
    {
        vsmax_svalue = (SInt32)VSCtl_spdVehCritOfs_C + ((SInt32)VehEst_spdVehCrit_swc_in * BIN7);
        VSCtl_spdVehCrit = (UInt16)DDS_M_LIMIT(vsmax_svalue,0,VSMAX_255_BIN7);
    }

    if((UInt32)VSCtl_stSpdVehCritFilModClc == (UInt32)1)
    {
        vsmax_f52142_swcitch_input_prev = VSCtl_spdVehCrit;
    }
    else if((UInt32)VSCtl_stSpdVehCritFilModClc != (UInt32)2)
    {
        vsmax_f52142_swcitch_input_prev = VSMAX_255_BIN7;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)VSCtl_stSpdVehCritModClc != VSCTL_STSPDVEHCRITMODCLC_EFFECTIF_17)
    {
        VSCtl_spdVehReqVSMaxc = VSMAX_255_BIN7;
    }
    else
    {
        VSCtl_spdVehReqVSMaxc = vsmax_f52142_swcitch_input_prev;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5215_Determiner_Consigne_Vitesse_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5215_Determiner_Consigne_Vitesse_Vehicule(
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt8 VSCtl_stVSMaxExtd_swc_in, /* Enum */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehVSMaxReq_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.58.0 */
    UInt32 vsmax_uvalue;

    vsmax_uvalue = DDS_M_MIN((UInt32)VSCtl_spdVehReqVSMaxf,(UInt32)VSCtl_spdVehReqVSMaxp);
    *VSCtl_spdVehVSMaxReq_swc_out = (UInt16)DDS_M_MIN(vsmax_uvalue,(UInt32)VSCtl_spdVehReqVSMaxs);

    if(  ((UInt32)VSCtl_stVSMaxExtd_swc_in == VSCTL_STVSMAXEXTD_ANE)
       ||((UInt32)VSCtl_stVSMaxExtd_swc_in == VSCTL_STVSMAXEXTD_AE))
    {
        vsmax_uvalue = VSMAX_255_BIN7;

        if((UInt32)VSCtl_bAcvVSMaxf != (UInt32)DDS_FALSE)
        {
            vsmax_uvalue = (UInt32)VSCtl_spdVehReqVSMaxf;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAcvVSMaxp != (UInt32)DDS_FALSE)
        {
            vsmax_uvalue = DDS_M_MIN(vsmax_uvalue,(UInt32)VSCtl_spdVehReqVSMaxp);
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAcvVSMaxs != (UInt32)DDS_FALSE)
        {
            vsmax_uvalue = DDS_M_MIN(vsmax_uvalue,(UInt32)VSCtl_spdVehReqVSMaxs);
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAcvVSMaxc != (UInt32)DDS_FALSE)
        {
            vsmax_uvalue = DDS_M_MIN(vsmax_uvalue,(UInt32)VSCtl_spdVehReqVSMaxc);
        }
        else
        {
            /* Nothing to do */
        }

        VSCtl_spdVehVSMaxReqInt = (UInt16)vsmax_uvalue;

        *VSCtl_spdVehErrVSMax_swc_out = (SInt16)((SInt32)vsmax_uvalue - (SInt32)VSCtl_spdVeh_swc_in);
    }
    else
    {
        VSCtl_spdVehVSMaxReqInt = (UInt16)VSMAX_255_BIN7;
        *VSCtl_spdVehErrVSMax_swc_out = (SInt16)VSMAX_255_BIN7;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSMAX_Simulink_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_Veh_Spd_Ctrl_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehVSMaxReq_swc_out,
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehErrVSMax_swc_out)
{
    /* ---- Init Outputs ---- */
    *VSCtl_spdVehErrVSMax_swc_out = (SInt16)VSMAX_0;
    *VSCtl_spdVehVSMaxReq_swc_out = (UInt16)VSMAX_255_BIN7;


    VSCtl_spdVehCrit = (UInt16)(255 * BIN7);
    VSCtl_spdVehReqVSMaxc = (UInt16)(255 * BIN7);
    VSCtl_spdVehReqVSMaxf = (UInt16)(255 * BIN7);
    VSCtl_spdVehReqVSMaxp = (UInt16)(255 * BIN7);
    VSCtl_spdVehReqVSMaxs = (UInt16)(255 * BIN7);
    VSCtl_spdVehVSMaxReqInt = (UInt16)(255 * BIN7);




    /* ---- VSMAX_F5211_Determiner_Consigne_Vitesse_Bvvf ---- */

    /* ---- VSMAX_F5212_Determiner_Consigne_Vitesse_Bvvp ---- */

    /* ---- VSMAX_F5213_Determiner_Consigne_Vitesse_Bvvs ---- */

    /* ---- VSMAX_F52142_Determiner_Consigne_Vitesse_Bvvc ---- */
    vsmax_f52142_swcitch_input_prev = VSMAX_255_BIN7;

    /* ---- VSMAX_F5215_Determiner_Consigne_Vitesse_Vehicule ---- */


}



#define VSMAX_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSMax_MemMap.h"

