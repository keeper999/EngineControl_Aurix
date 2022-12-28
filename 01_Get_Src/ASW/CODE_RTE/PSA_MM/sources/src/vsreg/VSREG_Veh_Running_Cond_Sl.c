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
* Ref X:\integration_view_00PSASWC_D320D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Veh_Running_Cond_Sl.c
* Version int :/main/L02_01/1 Date: 5/1/2012 11 h 24 m User:esnault 
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\3 Date: 16/11/2011 15 h 20 m User:demezil 
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 16/11/2011 11 h 44 m User:demezil
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 14/11/2011 16 h 42 m User:demezil
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L02_010_IMPL1
*    comments :for VSReg 12.0 : rename Ext_noGearEgd in CoPt_noEgdGearCordIt
* Version int :/main/L01_01/2 Date: 11/2/2011 12 h 48 m User:esnault
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL2
*    comments :UT correction
* Version dev :\main\branch_morisseau_xvv_vsreg\7 Date: 2/2/2011 12 h 19 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL2
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 28/1/2011 10 h 26 m User:esnault
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\6 Date: 27/1/2011 15 h 48 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\5 Date: 18/1/2011 16 h 28 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :correct init value
* Version dev :\main\branch_morisseau_xvv_vsreg\4 Date: 23/12/2010 10 h 21 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :correct init function
* Version dev :\main\branch_morisseau_xvv_vsreg\3 Date: 20/12/2010 14 h 33 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :correct states name
* Version dev :\main\branch_morisseau_xvv_vsreg\2 Date: 17/12/2010 16 h 31 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :first version for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 17/12/2010 10 h 43 m User:morisseau
*    TWK_model:VSREG_Veh_Running_Cond_Sl_L01_010_IMPL1
*    comments :add model to file
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSReg.h"


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

/* 16-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSRegReq; /* BIN7 */
extern VAR(UInt16, AUTOMATIC) VSCtl_stDeacVSRegReq_Brk; /* BIN0 */
extern VAR(UInt16, AUTOMATIC) VSCtl_stDeacVSRegReq_pt; /* BIN0 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"

/* 8-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAccVehMaxVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAccVehMinVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAccVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvRegVSCtlReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDeceVehVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bModRegVSCtlReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bRec_stDeacVSRegReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bSpdVehDrvOvrdVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bSpdVehMaxVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bSpdVehMinVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bVehCollWarnVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSRegReq_Ini; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"



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

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bEnaDeacVSRegReq_no2;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 32-bits scalar calibration definition */
#define VSREG_START_SEC_CALIB_32BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_stEnaDeacVSRegReqno2Hi_C = (CONST(UInt32, AUTOMATIC))(1700336 * BIN0);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_stEnaDeacVSRegReqno2Lo_C = (CONST(UInt32, AUTOMATIC))(33558463 * BIN0);
#define VSREG_STOP_SEC_CALIB_32BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define VSREG_START_SEC_VAR_32BIT
#include "VSReg_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsreg_dstvehtotmes_deacvsreg_loc;
STATIC VAR(UInt32, AUTOMATIC) vsreg_stdeacvsregreqhi_no1_dly;
STATIC VAR(UInt32, AUTOMATIC) vsreg_stdeacvsregreqhi_no2_dly;
STATIC VAR(UInt32, AUTOMATIC) vsreg_stdeacvsregreqlo_no1_dly;
STATIC VAR(UInt32, AUTOMATIC) vsreg_stdeacvsregreqlo_no2_dly;
#define VSREG_STOP_SEC_VAR_32BIT
#include "VSReg_MemMap.h"

/* 16-bits variable definition */
#define VSREG_START_SEC_VAR_16BIT
#include "VSReg_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsreg_aveh_deacvsreg_loc;
STATIC VAR(SInt16, AUTOMATIC) vsreg_avehvsregreq_deacvsreg_loc;
STATIC VAR(SInt16, AUTOMATIC) vsreg_jrkveh_deacvsreg_loc;
STATIC VAR(SInt16, AUTOMATIC) vsreg_jrkvehreqdeacvsreg_loc;
STATIC VAR(SInt16, AUTOMATIC) vsreg_rslop_deacvsreg_loc;
STATIC VAR(UInt16, AUTOMATIC) vsreg_raccp_deacvsreg_loc;
STATIC VAR(UInt16, AUTOMATIC) vsreg_spdveh_deacvsreg_loc;
#define VSREG_STOP_SEC_VAR_16BIT
#include "VSReg_MemMap.h"

/* 8-bits variable definition */
#define VSREG_START_SEC_VAR_8BIT
#include "VSReg_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsreg_brec_stdeacvsregreq_dly;
STATIC VAR(UInt8, AUTOMATIC) vsreg_stvsregextd_dly;
STATIC VAR(SInt8, AUTOMATIC) vsreg_nogearegd_deacvsreg_loc;
STATIC VAR(UInt8, AUTOMATIC) vsreg_posngbxdeacvsreg_loc;
STATIC VAR(UInt8, AUTOMATIC) vsreg_spdvehreqdeacvsreg_loc;
STATIC VAR(UInt8, AUTOMATIC) vsreg_stvsreg_deacvsreg_loc;
STATIC VAR(UInt8, AUTOMATIC) vsreg_stvsregprev_deacvsreg_loc;
#define VSREG_STOP_SEC_VAR_8BIT
#include "VSReg_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSRegReq_Veh; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSRegReq_Fct; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bDeacVSRegHab;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSREG_START_SEC_CODE
#include "VSReg_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/* None */

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
* Function Name : VSREG_F21234_Determiner_Condition_Conditions_Maintenance_Vehicule
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21234_Determiner_Condition_Conditions_Maintenance_Vehicule(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.108.0 */
    UInt32 vsreg_uvalue;

    if((UInt32)VSCtl_stMonVSReg == (UInt32)VSCTL_STMONVSREG_NOMINAL)
    {
        if((UInt32)VSCtl_bSpdVehMaxVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = BIN0;
        }
        else
        {
            vsreg_uvalue = 0;
        }
        if((UInt32)VSCtl_bSpdVehMinVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN1;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bSpdVehDrvOvrdVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN2;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAccVehMaxVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN3;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAccVehMinVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN4;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bDeceVehVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN5;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAccVehVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN6;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bVehCollWarnVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN7;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    {
        vsreg_uvalue = BIN8 - 1;
    }


    VSCtl_stDeacVSRegReq_Veh = (UInt8)vsreg_uvalue;
}

/*******************************************************************************
*
* Function Name : VSREG_F21247_Determiner_Condition_Conditions_Maintenance_Fonction
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21247_Determiner_Condition_Conditions_Maintenance_Fonction(
                                             UInt8 FRM_bInhVSReg_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.115.0 */
    UInt32 vsreg_uvalue;

    if((UInt32)VSCtl_stMonVSReg == (UInt32)VSCTL_STMONVSREG_NOMINAL)
    {
        if((UInt32)VSCtl_bModRegVSCtlReq == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = BIN0;
        }
        else
        {
            vsreg_uvalue = 0;
        }
        if((UInt32)VSCtl_bAcvRegVSCtlReq == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN1;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)FRM_bInhVSReg_swc_in == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN2;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    {
        vsreg_uvalue = BIN3 - 1;
    }


    VSCtl_stDeacVSRegReq_Fct = (UInt8)vsreg_uvalue;
}

/*******************************************************************************
*
* Function Name : VSREG_F2141_Determiner_Diagnostic_Fonctionnel_Habitacle
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2141_Determiner_Diagnostic_Fonctionnel_Habitacle(
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                             UInt8 Ext_spdVehVSRegReq_swc_in,
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                             UInt8 Ext_stAcvRegVSCtlReq_swc_in,
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                             UInt8 Ext_stModRegVSCtlReq_swc_in,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSRegBody_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSRegBody_swc_out)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.117.0 */
    *VSCtl_bDgoVSRegBody_swc_out = DDS_FALSE;
    *VSCtl_bMonRunVSRegBody_swc_out = DDS_FALSE;
    VSCtl_bDeacVSRegHab = DDS_FALSE;
}

/*******************************************************************************
*
* Function Name : VSREG_F2151_Determiner_Conditions_Maintenance_Rvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2151_Determiner_Conditions_Maintenance_Rvv(
                                             UInt8 VSCtl_stDeacVSCtlInfo_swc_in,
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no1_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no2_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no1_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no2_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.120.0 */
    UInt32 vsreg_and_input_lo;
    UInt32 vsreg_and_input_hi;
    UInt32 vsreg_and_output_lo;
    UInt32 vsreg_and_output_hi;

    vsreg_and_input_lo = (UInt32)VSCtl_stDeacVSCtlInfo_swc_in;
    vsreg_and_input_lo = vsreg_and_input_lo + ((UInt32)VSCtl_stDeacVSRegReq_Ini * BIN6);
    vsreg_and_input_lo = vsreg_and_input_lo + ((UInt32)VSCtl_stDeacVSRegReq_pt * BIN12);

    vsreg_and_input_hi = (UInt32)VSCtl_stDeacVSRegReq_Brk;
    vsreg_and_input_hi = vsreg_and_input_hi + ((UInt32)VSCtl_stDeacVSRegReq_Veh * BIN9);
    vsreg_and_input_hi = vsreg_and_input_hi + ((UInt32)VSCtl_stDeacVSRegReq_Fct * BIN17);
    if((UInt32)VSCtl_bDeacVSRegHab == (UInt32)DDS_TRUE)
    {
        vsreg_and_input_hi = vsreg_and_input_hi + BIN20;
    }
    else
    {
        /* Nothing to do */
    }

    vsreg_and_output_lo = (vsreg_and_input_lo & VSCtl_stEnaDeacVSRegReqno2Lo_C);
    vsreg_and_output_hi = (vsreg_and_input_hi & VSCtl_stEnaDeacVSRegReqno2Hi_C);

    if((UInt32)VSCtl_bRec_stDeacVSRegReq != (UInt32)DDS_TRUE)
    {
        vsreg_stdeacvsregreqhi_no1_dly = vsreg_and_input_lo;
        vsreg_stdeacvsregreqhi_no2_dly = vsreg_and_output_lo;
        vsreg_stdeacvsregreqlo_no1_dly = vsreg_and_input_hi;
        vsreg_stdeacvsregreqlo_no2_dly = vsreg_and_output_hi;
    }
    else
    {
        /* Nothing to do */
    }
    *VSCtl_stDeacVSRegReqLo_no1_swc_out = vsreg_stdeacvsregreqhi_no1_dly;
    *VSCtl_stDeacVSRegReqLo_no2_swc_out = vsreg_stdeacvsregreqhi_no2_dly;
    *VSCtl_stDeacVSRegReqHi_no1_swc_out = vsreg_stdeacvsregreqlo_no1_dly;
    *VSCtl_stDeacVSRegReqHi_no2_swc_out = vsreg_stdeacvsregreqlo_no2_dly;

    if(  (vsreg_and_output_lo > 0)
       ||(vsreg_and_output_hi > 0))
    {
        VSCtl_bEnaDeacVSRegReq_no2 = DDS_TRUE;
    }
    else
    {
        VSCtl_bEnaDeacVSRegReq_no2 = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F2153_Determiner_Contexte_Maintenance_Rvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2153_Determiner_Contexte_Maintenance_Rvv(
                                             UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                             UInt32 Ext_dstVehTotMes_swc_in, /* BIN0 */
                                             SInt8 CoPt_noEgdGearCordIt_swc_in,
                                             UInt8 CoPt_posnLev_swc_in,
                                             UInt8 Ext_spdVehVSRegReq_swc_in, /* BIN0 */
                                             SInt16 VSCtl_aVehVSRegReq_swc_in, /* BIN10 */
                                             SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                                             SInt16 VSCtl_jrkVeh_swc_in, /* BIN7 */
                                             SInt16 VSCtl_rSlop_swc_in, /* BIN7 */
                                             UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                             UInt8 VSCtl_stVSRegExtd_swc_in,
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_DeacVSReg_swc_out, /* BIN10 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSReg_swc_out, /* BIN10 */
                                             CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSReg_swc_out, /* BIN0 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSReg_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSReg_swc_out,
                                             CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSReg_swc_out, /* BIN0 */
                                             CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSReg_swc_out, /* BIN7 */
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                                             CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSReg_DeacVSReg_swc_out)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.122.1 */
    if((UInt32)vsreg_brec_stdeacvsregreq_dly != (UInt32)DDS_TRUE)
    {
        vsreg_aveh_deacvsreg_loc = VSCtl_aVeh_swc_in;
        vsreg_avehvsregreq_deacvsreg_loc = VSCtl_aVehVSRegReq_swc_in;
        vsreg_dstvehtotmes_deacvsreg_loc = Ext_dstVehTotMes_swc_in;
        vsreg_jrkvehreqdeacvsreg_loc = VSCtl_jrkVehVSRegReq;
        vsreg_jrkveh_deacvsreg_loc = VSCtl_jrkVeh_swc_in;
        vsreg_nogearegd_deacvsreg_loc = CoPt_noEgdGearCordIt_swc_in;
        vsreg_posngbxdeacvsreg_loc = CoPt_posnLev_swc_in;
        vsreg_raccp_deacvsreg_loc = AccP_rAccP_swc_in;
        vsreg_rslop_deacvsreg_loc = VSCtl_rSlop_swc_in;
        vsreg_spdvehreqdeacvsreg_loc = Ext_spdVehVSRegReq_swc_in;
        vsreg_spdveh_deacvsreg_loc = VSCtl_spdVeh_swc_in;
        vsreg_stvsregprev_deacvsreg_loc = vsreg_stvsregextd_dly;
        vsreg_stvsreg_deacvsreg_loc = VSCtl_stVSRegExtd_swc_in;
    }
    else
    {
        /* Nothing to do */
    }

    vsreg_stvsregextd_dly = VSCtl_stVSRegExtd_swc_in;
    vsreg_brec_stdeacvsregreq_dly = VSCtl_bRec_stDeacVSRegReq;

    *VSCtl_aVehVSRegReq_DeacVSReg_swc_out  = vsreg_avehvsregreq_deacvsreg_loc;
    *VSCtl_aVeh_DeacVSReg_swc_out  = vsreg_aveh_deacvsreg_loc;
    *VSCtl_dstVehTotMes_DeacVSReg_swc_out  = vsreg_dstvehtotmes_deacvsreg_loc;
    *VSCtl_jrkVehReqDeacVSReg_swc_out  = vsreg_jrkvehreqdeacvsreg_loc;
    *VSCtl_jrkVeh_DeacVSReg_swc_out  = vsreg_jrkveh_deacvsreg_loc;
    *VSCtl_noGearEgd_DeacVSReg_swc_out  = vsreg_nogearegd_deacvsreg_loc;
    *VSCtl_posnGBxDeacVSReg_swc_out  = vsreg_posngbxdeacvsreg_loc;
    *VSCtl_rAccP_DeacVSReg_swc_out  = vsreg_raccp_deacvsreg_loc;
    *VSCtl_rSlop_DeacVSReg_swc_out  = vsreg_rslop_deacvsreg_loc;
    *VSCtl_spdVehReqDeacVSReg_swc_out  = vsreg_spdvehreqdeacvsreg_loc;
    *VSCtl_spdVeh_DeacVSReg_swc_out  = vsreg_spdveh_deacvsreg_loc;
    *VSCtl_stVSRegPrev_DeacVSReg_swc_out  = vsreg_stvsregprev_deacvsreg_loc;
    *VSCtl_stVSReg_DeacVSReg_swc_out  = vsreg_stvsreg_deacvsreg_loc;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSREG_Veh_Running_Cond_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_Veh_Running_Cond_Sl_Init(
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSRegReq_DeacVSReg_swc_out, /* BIN10 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSReg_swc_out, /* BIN10 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bDgoVSRegBody_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_bMonRunVSRegBody_swc_out,
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSReg_swc_out, /* BIN0 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC)  VSCtl_noGearEgd_DeacVSReg_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_posnGBxDeacVSReg_swc_out,
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_spdVehReqDeacVSReg_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSReg_swc_out, /* BIN7 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no1_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqHi_no2_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no1_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSRegReqLo_no2_swc_out, /* BIN0 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSRegPrev_DeacVSReg_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC)  VSCtl_stVSReg_DeacVSReg_swc_out)
{
    /* ---- Init Outputs ---- */
    *VSCtl_aVehVSRegReq_DeacVSReg_swc_out = (SInt16)(-10 * BIN10);
    *VSCtl_aVeh_DeacVSReg_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_dstVehTotMes_DeacVSReg_swc_out = (UInt32)(0 * BIN0);
    *VSCtl_jrkVehReqDeacVSReg_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_jrkVeh_DeacVSReg_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_noGearEgd_DeacVSReg_swc_out = (SInt8)VSREG_COPT_NOEGDGEARCORDIT_NEUTRE;
    *VSCtl_posnGBxDeacVSReg_swc_out = (UInt8)VSCTL_POSNGBXDEACVSREG_P;
    *VSCtl_rAccP_DeacVSReg_swc_out = (UInt16)(100 * BIN7);
    *VSCtl_rSlop_DeacVSReg_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_spdVehReqDeacVSReg_swc_out = (UInt8)(0 * BIN0);
    *VSCtl_spdVeh_DeacVSReg_swc_out = (UInt16)(0 * BIN7);
    *VSCtl_stVSRegPrev_DeacVSReg_swc_out = (UInt8)VSREG_VSCTL_STVSREGEXTD_ARRET;
    *VSCtl_stVSReg_DeacVSReg_swc_out = (UInt8)VSREG_VSCTL_STVSREGEXTD_ARRET;
    *VSCtl_stDeacVSRegReqLo_no1_swc_out = 67108863;
    *VSCtl_stDeacVSRegReqLo_no2_swc_out = 67108863;
    *VSCtl_stDeacVSRegReqHi_no1_swc_out = 2097151;
    *VSCtl_stDeacVSRegReqHi_no2_swc_out = 2097151;

    *VSCtl_bDgoVSRegBody_swc_out = DDS_FALSE;
    *VSCtl_bMonRunVSRegBody_swc_out = DDS_FALSE;

    VSCtl_bEnaDeacVSRegReq_no2 = DDS_FALSE;

    /* ---- Init Global Datas ---- */
    VSCtl_stDeacVSRegReq_Veh = (UInt8)(BIN8 - 1);
    VSCtl_stDeacVSRegReq_Fct = (UInt8)(BIN3 - 1);
    VSCtl_bDeacVSRegHab = DDS_TRUE;

    /* ---- VSREG_F21234_Determiner_Condition_Conditions_Maintenance_Vehicule ---- */

    /* ---- VSREG_F21247_Determiner_Condition_Conditions_Maintenance_Fonction ---- */

    /* ---- VSREG_F2141_Determiner_Diagnostic_Fonctionnel_Habitacle ---- */

    /* ---- VSREG_F2151_Determiner_Conditions_Maintenance_Rvv ---- */
    vsreg_stdeacvsregreqhi_no1_dly = 0;
    vsreg_stdeacvsregreqhi_no2_dly = 0;
    vsreg_stdeacvsregreqlo_no1_dly = 0;
    vsreg_stdeacvsregreqlo_no2_dly = 0;

    /* ---- VSREG_F2153_Determiner_Contexte_Maintenance_Rvv ---- */
    vsreg_brec_stdeacvsregreq_dly = DDS_FALSE;
    vsreg_stvsregextd_dly = 0;
    vsreg_aveh_deacvsreg_loc = 0;
    vsreg_avehvsregreq_deacvsreg_loc = 0;
    vsreg_dstvehtotmes_deacvsreg_loc = 0;
    vsreg_jrkvehreqdeacvsreg_loc = 0;
    vsreg_jrkveh_deacvsreg_loc = 0;
    vsreg_nogearegd_deacvsreg_loc = 0;
    vsreg_posngbxdeacvsreg_loc = 0;
    vsreg_raccp_deacvsreg_loc = 0;
    vsreg_rslop_deacvsreg_loc = 0;
    vsreg_spdvehreqdeacvsreg_loc = 0;
    vsreg_spdveh_deacvsreg_loc = 0;
    vsreg_stvsregprev_deacvsreg_loc = 0;
    vsreg_stvsreg_deacvsreg_loc = 0;
}

#define VSREG_STOP_SEC_CODE
#include "VSReg_MemMap.h"

