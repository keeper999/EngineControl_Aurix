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
* Ref X:\integration_view_00PSASWC_D620D01\blois_psa_sstg\Software\Appli\VSMax\src\VSMAX_Fct_Mode_Sl.c
* Version int :/main/L02_01/1 Date: 6/1/2012 12 h 4 m User:meme 
*    TWK_model:VSMAX_Fct_Mode_Sl_L02_010_IMPL1
*    comments :for VSMax 12.0
* Version dev :\main\branch_morisseau_xvv_vsmax_e6_dev\2 Date: 24/11/2011 16 h 2 m User:morisseau 
*    TWK_model:VSMAX_Fct_Mode_Sl_L02_010_IMPL1
*    comments :for VSMax 12.0
* Version int :/main/L01_01/2 Date: 3/2/2011 15 h 8 m User:esnault
*    TWK_model:VSMAX_Fct_Mode_Sl_L01_010_IMPL2
*    comments :add delay for input VSCtl_bRec_stDeacVSMaxReq
* Version dev :\main\branch_lemort_vsmax_dev\3 Date: 25/1/2011 12 h 27 m User:lemort
*    TWK_model:VSMAX_Fct_Mode_Sl_L01_010_IMPL2
*    comments :add delay for input VSCtl_bRec_stDeacVSMaxReq
* Version dev :\main\branch_lemort_vsmax_dev\2 Date: 24/1/2011 11 h 13 m User:demezil
*    TWK_model:VSMAX_Fct_Mode_Sl_L01_010_IMPL2
*    comments :for VSMax 10.0
* Version dev :\main\branch_lemort_vsmax_dev\1 Date: 17/12/2010 14 h 13 m User:lemort
*    TWK_model:VSMAX_Fct_Mode_Sl_L01_010_IMPL1
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
extern VAR(UInt8, AUTOMATIC) VSCtl_bCfVSMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDeacVSMaxp;
extern VAR(UInt8, AUTOMATIC) VSCtl_bRec_stDeacVSMaxReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bctDefRevVSMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSMax; /* BIN0 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"


/* 16-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_16BIT
#include "VSMax_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSMaxReq; /* BIN7 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_16BIT
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
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bEnaDeacVSMaxReq_no2; /* Enum */
VAR(UInt8, AUTOMATIC) VSCtl_bTyreWarnVSMax;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_stEnaDeacVSMaxReqno2_C = (CONST(UInt16, AUTOMATIC))(8127 * BIN0);
#define VSMAX_STOP_SEC_CALIB_16BIT
#include "VSMax_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSMAX_START_SEC_CALIB_8BIT
#include "VSMax_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacTyreWarnVSMax_C = DDS_TRUE;
#define VSMAX_STOP_SEC_CALIB_8BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/



/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/



/* 32bit variable definition */
#define VSMAX_START_SEC_VAR_32BIT
#include "VSMax_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsctl_dstvehtotmes_deacvsmax_prev; /* BIN0 */
#define VSMAX_STOP_SEC_VAR_32BIT
#include "VSMax_MemMap.h"

/* 16bit variable definition */
#define VSMAX_START_SEC_VAR_16BIT
#include "VSMax_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehvsmaxreq_deacvsmax_prev; /* BIN10 */
STATIC VAR(SInt16, AUTOMATIC) vsctl_aveh_deacvsmax_prev; /* BIN10 */
STATIC VAR(UInt16, AUTOMATIC) vsctl_spdveh_deacvsmax_prev; /* BIN7 */
STATIC VAR(UInt16, AUTOMATIC) vsctl_raccp_deacvsmax_prev; /* BIN7 */
STATIC VAR(SInt16, AUTOMATIC) vsctl_rslop_deacvsmax_prev; /* BIN7 */
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreqdeacvsmax_prev; /* BIN7 */
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkveh_deacvsmax_prev; /* BIN7 */
STATIC VAR(UInt16, AUTOMATIC) vsctl_stdeacvsmaxreq_no1_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_stdeacvsmaxreq_no2_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_spdvehreqdeacvsmax_prev; /* BIN7 */
#define VSMAX_STOP_SEC_VAR_16BIT
#include "VSMax_MemMap.h"

/* 8bit variable definition */
#define VSMAX_START_SEC_VAR_8BIT
#include "VSMax_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_brec_stdeacvsmaxreq_prev;
STATIC VAR(SInt8, AUTOMATIC) vsctl_nogearegd_deacvsmax_prev; /* Enum */
STATIC VAR(UInt8, AUTOMATIC) vsctl_posngbxdeacvsmax_prev; /* Enum */
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvsmaxprev_deacvsmax_prev; /* Enum */
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvsmax_deacvsmax_prev; /* Enum */
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvsmaxextd_prev; /* Enum */

#define VSMAX_STOP_SEC_VAR_8BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/



/* 8-bits variable definition */
#define VSMAX_START_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSMaxReq_Brk;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSMaxReq_Fct;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSMaxReq_Ini; /* BIN0 */
#define VSMAX_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSMax_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/



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
* Function Name : VSMAX_F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite(
                            UInt8 Ext_bKeyOff_swc_in,
                            UInt8 FRM_bDeacIrvVSMax_swc_in,
                            UInt8 FRM_bDeacRvVSMax_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.35.0 */
    UInt32 vsmax_uvalue;

    vsmax_uvalue = 0;

    if((UInt32)VSCtl_bCfVSMax == (UInt32)DDS_TRUE)
    {
        vsmax_uvalue = vsmax_uvalue + 2;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)Ext_bKeyOff_swc_in == (UInt32)DDS_TRUE)
    {
        vsmax_uvalue = vsmax_uvalue + 1;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)VSCtl_bctDefRevVSMax == (UInt32)DDS_TRUE)
    {
        vsmax_uvalue = vsmax_uvalue + 4;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)FRM_bDeacRvVSMax_swc_in == (UInt32)DDS_TRUE)
    {
        vsmax_uvalue = vsmax_uvalue + 8;
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)FRM_bDeacIrvVSMax_swc_in == (UInt32)DDS_TRUE)
    {
        vsmax_uvalue = vsmax_uvalue + 16;
    }
    else
    {
        /* Nothing to do */
    }

    VSCtl_stDeacVSMaxReq_Ini = (UInt8)vsmax_uvalue;
}

/*******************************************************************************
*
* Function Name : VSMAX_F51211_Determiner_Condition_Alerte_Pneumatiques
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F51211_Determiner_Condition_Alerte_Pneumatiques(
                            UInt8 Ext_bTyreWarn_swc_in,
                            UInt8 Ext_bTyreWarnCf_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.37.0 */

    if((UInt32)VSCtl_stMonVSMax != (UInt32)3)
    {
        VSCtl_bTyreWarnVSMax = DDS_TRUE;
    }
    else
    {
        if((UInt32)Ext_bTyreWarnCf_swc_in != (UInt32)DDS_TRUE)
        {
            VSCtl_bTyreWarnVSMax = DDS_FALSE;
        }
        else if((UInt32)VSCtl_bDeacTyreWarnVSMax_C != (UInt32)DDS_TRUE)
        {
            VSCtl_bTyreWarnVSMax = Ext_bTyreWarn_swc_in;
        }
        else
        {
            VSCtl_bTyreWarnVSMax = DDS_FALSE;
        }
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F51212_Determiner_Conditions_Maintenance_Frein_Las
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F51212_Determiner_Conditions_Maintenance_Frein_Las(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.38.0 */

    if((UInt32)VSCtl_stMonVSMax != (UInt32)3)
    {
        VSCtl_stDeacVSMaxReq_Brk = DDS_TRUE;
    }
    else
    {
        VSCtl_stDeacVSMaxReq_Brk = VSCtl_bTyreWarnVSMax;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F51223_Determiner_Condition_Conditions_Maintenance_Fonction
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F51223_Determiner_Condition_Conditions_Maintenance_Fonction(
                            UInt8 FRM_bInhVSMax_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.44.0 */

    if((UInt32)VSCtl_stMonVSMax != (UInt32)3)
    {
        VSCtl_stDeacVSMaxReq_Fct = DDS_TRUE;
    }
    else
    {
        VSCtl_stDeacVSMaxReq_Fct = FRM_bInhVSMax_swc_in;
    }
}

/*******************************************************************************
*
* Function Name : VSMAX_F5151_Determiner_Conditions_Maintenance_Bvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5151_Determiner_Conditions_Maintenance_Bvv(
                            UInt8 VSCtl_stDeacVSCtlInfo_swc_in, /* BIN0 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no1_swc_out, /* BIN0 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no2_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.48.0 */
    UInt32 vsmax_uvalue;
    UInt32 vsmax_uvalue_2;

    /* [0;1984] = [0;31] * 64 */
    vsmax_uvalue = (UInt32)VSCtl_stDeacVSMaxReq_Ini * 64;
    /* [0;4032] = [0;1984] + ([0;1] * 2048)*/
    vsmax_uvalue = vsmax_uvalue + ((UInt32)VSCtl_stDeacVSMaxReq_Brk * 2048);
    /* [0;8128] = [0;4032] + ([0;1] * 4096)*/
    vsmax_uvalue = vsmax_uvalue + ((UInt32)VSCtl_stDeacVSMaxReq_Fct * 4096);
    /* [0;8160] = [0;8128] + [0;32] */
    vsmax_uvalue = vsmax_uvalue + (UInt32)VSCtl_stDeacVSCtlInfo_swc_in;

    /* [0;16352] = [0;8160] + [0;8192] */
    if((UInt32)VSCtl_bDeacVSMaxp == (UInt32)DDS_TRUE)
    {
        vsmax_uvalue = vsmax_uvalue + 8192;
    }
    else
    {
        /* Nothing to do */
    }


    vsmax_uvalue_2 = (vsmax_uvalue & (UInt32)VSCtl_stEnaDeacVSMaxReqno2_C);

    if(vsmax_uvalue_2 > (UInt32)0)
    {
        VSCtl_bEnaDeacVSMaxReq_no2 = DDS_TRUE;
    }
    else
    {
        VSCtl_bEnaDeacVSMaxReq_no2 = DDS_FALSE;
    }

    if((UInt32)VSCtl_bRec_stDeacVSMaxReq != (UInt32)DDS_TRUE)
    {
        vsctl_stdeacvsmaxreq_no1_prev = (UInt16)vsmax_uvalue;
        vsctl_stdeacvsmaxreq_no2_prev = (UInt16)vsmax_uvalue_2;
    }
    else
    {
        /* Nothing to do */
    }

    *VSCtl_stDeacVSMaxReq_no1_swc_out = vsctl_stdeacvsmaxreq_no1_prev;
    *VSCtl_stDeacVSMaxReq_no2_swc_out = vsctl_stdeacvsmaxreq_no2_prev;
}

/*******************************************************************************
*
* Function Name : VSMAX_F5153_Determiner_Contexte_Maintenance_Bvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSMAX_F5153_Determiner_Contexte_Maintenance_Bvv(
                            UInt16 AccP_rAccP_swc_in, /* BIN7 */
                            UInt32 Ext_dstVehTotMes_swc_in, /* BIN0 */
                            SInt8 CoPt_noEgdGearCordIt_swc_in, /* Enum */
                            UInt8 CoPt_posnLev_swc_in, /* Enum */
                            SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                            SInt16 VSCtl_aVehVSMaxReq_swc_in, /* BIN10 */
                            SInt16 VSCtl_jrkVeh_swc_in, /* BIN7 */
                            SInt16 VSCtl_rSlop_swc_in, /* BIN7 */
                            UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                            UInt16 VSCtl_spdVehVSMaxReq_swc_in, /* BIN7 */
                            UInt8 VSCtl_stVSMaxExtd_swc_in, /* Enum */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_DeacVSMax_swc_out, /* BIN10 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSMax_swc_out, /* BIN10 */
                            CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSMax_swc_out, /* BIN0 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSMax_swc_out, /* Enum */
                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSMax_swc_out, /* Enum */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSMax_swc_out, /* BIN7 */
                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMaxPrev_DeacVSMax_swc_out, /* Enum */
                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMax_DeacVSMax_swc_out /* Enum */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2272.FR.50.0 */

    /* Delay associated to VSCtl_bRec_stDeacVSMaxReq could not be done by scheduling. So it is implemented in this function. */

    if((UInt32)vsctl_brec_stdeacvsmaxreq_prev != (UInt32)DDS_TRUE)
    {
        vsctl_dstvehtotmes_deacvsmax_prev = Ext_dstVehTotMes_swc_in; /* BIN0 */
        vsctl_avehvsmaxreq_deacvsmax_prev = VSCtl_aVehVSMaxReq_swc_in; /* BIN10 */
        vsctl_aveh_deacvsmax_prev = VSCtl_aVeh_swc_in; /* BIN10 */
        vsctl_spdveh_deacvsmax_prev = VSCtl_spdVeh_swc_in; /* BIN7 */
        vsctl_raccp_deacvsmax_prev = AccP_rAccP_swc_in; /* BIN7 */
        vsctl_rslop_deacvsmax_prev = VSCtl_rSlop_swc_in; /* BIN7 */
        vsctl_jrkvehreqdeacvsmax_prev = VSCtl_jrkVehVSMaxReq; /* BIN7 */
        vsctl_jrkveh_deacvsmax_prev = VSCtl_jrkVeh_swc_in; /* BIN7 */
        vsctl_nogearegd_deacvsmax_prev = CoPt_noEgdGearCordIt_swc_in; /* Enum */
        vsctl_posngbxdeacvsmax_prev = CoPt_posnLev_swc_in; /* Enum */
        vsctl_spdvehreqdeacvsmax_prev = VSCtl_spdVehVSMaxReq_swc_in; /* BIN7 */
        vsctl_stvsmaxprev_deacvsmax_prev = vsctl_stvsmaxextd_prev; /* Enum */
        vsctl_stvsmax_deacvsmax_prev = VSCtl_stVSMaxExtd_swc_in; /* Enum */
    }
    else
    {
        /* Nothing to do */
    }
    vsctl_stvsmaxextd_prev = VSCtl_stVSMaxExtd_swc_in;
    vsctl_brec_stdeacvsmaxreq_prev = VSCtl_bRec_stDeacVSMaxReq;

    *VSCtl_aVehVSMaxReq_DeacVSMax_swc_out = vsctl_avehvsmaxreq_deacvsmax_prev; /* BIN10 */
    *VSCtl_aVeh_DeacVSMax_swc_out = vsctl_aveh_deacvsmax_prev; /* BIN10 */
    *VSCtl_dstVehTotMes_DeacVSMax_swc_out = vsctl_dstvehtotmes_deacvsmax_prev; /* BIN0 */
    *VSCtl_jrkVehReqDeacVSMax_swc_out = vsctl_jrkvehreqdeacvsmax_prev; /* BIN7 */
    *VSCtl_jrkVeh_DeacVSMax_swc_out = vsctl_jrkveh_deacvsmax_prev; /* BIN7 */
    *VSCtl_noGearEgd_DeacVSMax_swc_out = vsctl_nogearegd_deacvsmax_prev; /* Enum */
    *VSCtl_posnGBxDeacVSMax_swc_out = vsctl_posngbxdeacvsmax_prev; /* Enum */
    *VSCtl_rAccP_DeacVSMax_swc_out = vsctl_raccp_deacvsmax_prev; /* BIN7 */
    *VSCtl_rSlop_DeacVSMax_swc_out = vsctl_rslop_deacvsmax_prev; /* BIN7 */
    *VSCtl_spdVehReqDeacVSMax_swc_out = vsctl_spdvehreqdeacvsmax_prev; /* BIN7 */
    *VSCtl_spdVeh_DeacVSMax_swc_out = vsctl_spdveh_deacvsmax_prev; /* BIN7 */
    *VSCtl_stVSMaxPrev_DeacVSMax_swc_out = vsctl_stvsmaxprev_deacvsmax_prev; /* Enum */
    *VSCtl_stVSMax_DeacVSMax_swc_out = vsctl_stvsmax_deacvsmax_prev; /* Enum */
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

FUNC(void, AUTOMATIC) VSMAX_Fct_Mode_Sl_Init(
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSMaxReq_DeacVSMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSMax_swc_out, /* BIN10 */
                                 CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSMax_swc_out, /* BIN0 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSMax_swc_out, /* NBIN6 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSMax_swc_out, /* NBIN6 */
                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSMax_swc_out,
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSMax_swc_out,
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSMax_swc_out, /* BIN7 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no1_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSMaxReq_no2_swc_out, /* BIN0 */
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMaxPrev_DeacVSMax_swc_out,
                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSMax_DeacVSMax_swc_out)
{
    /* ---- Init Outputs ---- */
    *VSCtl_aVeh_DeacVSMax_swc_out = (SInt16)VSMAX_0;
    *VSCtl_aVehVSMaxReq_DeacVSMax_swc_out = (SInt16)VSMAX_10_BIN10;
    *VSCtl_dstVehTotMes_DeacVSMax_swc_out = (UInt32)VSMAX_0;
    *VSCtl_jrkVeh_DeacVSMax_swc_out = (SInt16)VSMAX_0;
    *VSCtl_jrkVehReqDeacVSMax_swc_out = (SInt16)VSMAX_0;
    *VSCtl_noGearEgd_DeacVSMax_swc_out = (SInt8)VSMAX_COPT_NOEGDGEARCORDIT_NEUTRE;
    *VSCtl_posnGBxDeacVSMax_swc_out = (UInt8)VSCTL_POSNGBXDEACVSMAX_P;
    *VSCtl_rAccP_DeacVSMax_swc_out = (UInt16)VSMAX_100_BIN7;
    *VSCtl_rSlop_DeacVSMax_swc_out = (SInt16)VSMAX_0;
    *VSCtl_spdVeh_DeacVSMax_swc_out = (UInt16)VSMAX_0;
    *VSCtl_spdVehReqDeacVSMax_swc_out = (UInt16)VSMAX_0;
    *VSCtl_stDeacVSMaxReq_no1_swc_out = (UInt16)16383;
    *VSCtl_stDeacVSMaxReq_no2_swc_out = (UInt16)16383;
    *VSCtl_stVSMax_DeacVSMax_swc_out = (UInt8)VSMAX_STVSMAX_DEAC_ARRET;
    *VSCtl_stVSMaxPrev_DeacVSMax_swc_out = (UInt8)VSMAX_STVSMAX_DEAC_ARRET;


    /* ---- Init Output to others files Datas ---- */
    VSCtl_bEnaDeacVSMaxReq_no2 = DDS_FALSE;
    VSCtl_bTyreWarnVSMax = DDS_TRUE;

    VSCtl_stDeacVSMaxReq_Brk = DDS_TRUE;
    VSCtl_stDeacVSMaxReq_Fct = DDS_TRUE;
    VSCtl_stDeacVSMaxReq_Ini = (UInt8)(31 * BIN0);


    /* ---- Init Global Datas ---- */
    vsctl_stvsmaxextd_prev = 0; /* Enum */
    vsctl_brec_stdeacvsmaxreq_prev = DDS_FALSE;

    /* ---- VSMAX_F5113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite ---- */

    /* ---- VSMAX_F51211_Determiner_Condition_Alerte_Pneumatiques ---- */

    /* ---- VSMAX_F51212_Determiner_Conditions_Maintenance_Frein_Las ---- */

    /* ---- VSMAX_F51223_Determiner_Condition_Conditions_Maintenance_Fonction ---- */

    /* ---- VSMAX_F5151_Determiner_Conditions_Maintenance_Bvv ---- */
    vsctl_stdeacvsmaxreq_no1_prev = 0;
    vsctl_stdeacvsmaxreq_no2_prev = 0;

    /* ---- VSMAX_F5153_Determiner_Contexte_Maintenance_Bvv ---- */
    vsctl_dstvehtotmes_deacvsmax_prev = 0; /* BIN0 */
    vsctl_avehvsmaxreq_deacvsmax_prev = 0; /* BIN10 */
    vsctl_aveh_deacvsmax_prev = 0; /* BIN10 */
    vsctl_spdveh_deacvsmax_prev = 0; /* BIN7 */
    vsctl_raccp_deacvsmax_prev = 0; /* BIN7 */
    vsctl_rslop_deacvsmax_prev = 0; /* BIN7 */
    vsctl_jrkvehreqdeacvsmax_prev = 0; /* BIN7 */
    vsctl_jrkveh_deacvsmax_prev = 0; /* BIN7 */
    vsctl_nogearegd_deacvsmax_prev = 0; /* Enum */
    vsctl_posngbxdeacvsmax_prev = 0; /* Enum */
    vsctl_spdvehreqdeacvsmax_prev = 0; /* BIN7 */
    vsctl_stvsmaxprev_deacvsmax_prev = 0; /* Enum */
    vsctl_stvsmax_deacvsmax_prev = 0; /* Enum */


}

#define VSMAX_STOP_SEC_CODE
#include "VSMax_MemMap.h"

