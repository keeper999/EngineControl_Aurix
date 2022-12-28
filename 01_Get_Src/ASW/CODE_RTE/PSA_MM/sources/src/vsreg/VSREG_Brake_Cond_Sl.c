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
* Ref X:\integration_view_00PSASWC_D300D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Brake_Cond_Sl.c
* Version int :/main/L01_01/1 Date: 28/1/2011 10 h 27 m User:esnault 
*    TWK_model:VSREG_Brake_Cond_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\5 Date: 27/1/2011 15 h 48 m User:morisseau 
*    TWK_model:VSREG_Brake_Cond_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\4 Date: 17/12/2010 16 h 22 m User:morisseau
*    TWK_model:VSREG_Brake_Cond_Sl_L01_010_IMPL1
*    comments :remove main prototype
* Version dev :\main\branch_morisseau_xvv_vsreg\3 Date: 17/12/2010 10 h 42 m User:morisseau
*    TWK_model:VSREG_Brake_Cond_Sl_L01_010_IMPL1
*    comments :first version for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\2 Date: 17/12/2010 10 h 32 m User:morisseau
*    TWK_model:VSREG_Brake_Cond_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 15/12/2010 16 h 51 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :for VSReg 10.0
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

/* 8-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bWhlSlipVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bESPRegVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bASRRegVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bABSRegVSReg;
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

/* 16-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_stDeacVSRegReq_Brk; /* BIN0 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"

/* 8-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bTyreWarnVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bBrkPedPrssVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bBrkDynVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bBrkAutoVSReg;
VAR(UInt8, AUTOMATIC) VSCtl_bPrkBrkVSReg;
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 8-bits scalar calibration definition */
#define VSREG_START_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacTyreWarnVSReg_C = DDS_TRUE;
#define VSREG_STOP_SEC_CALIB_8BIT
#include "VSReg_MemMap.h"


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

/* NONE */

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
* Function Name : VSREG_F21221_Determiner_Condition_Appui_Pedale_Frein
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21221_Determiner_Condition_Appui_Pedale_Frein(
                                                      UInt8 Ext_bBrkPedPrss_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.93.0 */

    if((UInt32)VSCTL_STMONVSREG_NOMINAL == (UInt32)VSCtl_stMonVSReg)
    {
        VSCtl_bBrkPedPrssVSReg = Ext_bBrkPedPrss_swc_in;
    }
    else
    {
        VSCtl_bBrkPedPrssVSReg = DDS_TRUE;
    }

}

/*******************************************************************************
*
* Function Name : VSREG_F21222_Determiner_Condition_Serrage_Frein_Main
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21222_Determiner_Condition_Serrage_Frein_Main(
                                                      UInt8 Ext_bPrkBrk_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.94.0 */

    if((UInt32)VSCTL_STMONVSREG_NOMINAL == (UInt32)VSCtl_stMonVSReg)
    {
        VSCtl_bPrkBrkVSReg = Ext_bPrkBrk_swc_in;
    }
    else
    {
        VSCtl_bPrkBrkVSReg = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F21223_Determiner_Condition_Freinage_Automatique
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21223_Determiner_Condition_Freinage_Automatique(
                                                      UInt8 Brk_bBrkAuto_swc_in,
                                                      UInt8 Ext_bBrkAutoCf_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.95.0 */

    if((UInt32)VSCTL_STMONVSREG_NOMINAL == (UInt32)VSCtl_stMonVSReg)
    {
        if((UInt32)DDS_TRUE == (UInt32)Ext_bBrkAutoCf_swc_in)
        {
            VSCtl_bBrkAutoVSReg = Brk_bBrkAuto_swc_in;
        }
        else
        {
            VSCtl_bBrkAutoVSReg = DDS_FALSE;
        }
    }
    else
    {
        VSCtl_bBrkAutoVSReg = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F21224_Determiner_Condition_Freinage_Dynamique
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21224_Determiner_Condition_Freinage_Dynamique(
                                                      UInt8 Brk_bBrkDyn_swc_in,
                                                      UInt8 Ext_bBrkDynCf_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.96.0 */

    if((UInt32)VSCTL_STMONVSREG_NOMINAL == (UInt32)VSCtl_stMonVSReg)
    {
        if((UInt32)DDS_TRUE == (UInt32)Ext_bBrkDynCf_swc_in)
        {
            VSCtl_bBrkDynVSReg = Brk_bBrkDyn_swc_in;
        }
        else
        {
            VSCtl_bBrkDynVSReg = DDS_FALSE;
        }
    }
    else
    {
        VSCtl_bBrkDynVSReg = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F21229_Determiner_Condition_Alerte_Pneumatiques
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21229_Determiner_Condition_Alerte_Pneumatiques(
                                                      UInt8 Ext_bTyreWarn_swc_in,
                                                      UInt8 Ext_bTyreWarnCf_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.101.0 */

    if((UInt32)VSCTL_STMONVSREG_NOMINAL == (UInt32)VSCtl_stMonVSReg)
    {
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bDeacTyreWarnVSReg_C)
        {
            VSCtl_bTyreWarnVSReg = DDS_FALSE;
        }
        else
        {
            if((UInt32)DDS_TRUE == (UInt32)Ext_bTyreWarnCf_swc_in)
            {
                VSCtl_bTyreWarnVSReg = Ext_bTyreWarn_swc_in;
            }
            else
            {
                VSCtl_bTyreWarnVSReg = DDS_FALSE;
            }
        }
    }
    else
    {
        VSCtl_bTyreWarnVSReg = DDS_TRUE;
    }
}

/*******************************************************************************
*
* Function Name : VSREG_F2122a_Determiner_Conditions_Maintenance_Frein_Las
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2122a_Determiner_Conditions_Maintenance_Frein_Las(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.102.0 */
    UInt32 vsreg_uvalue;

    if((UInt32)VSCTL_STMONVSREG_NOMINAL == (UInt32)VSCtl_stMonVSReg)
    {
        vsreg_uvalue = 0;
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bBrkPedPrssVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 1;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bPrkBrkVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 2;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bBrkAutoVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 4;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bBrkDynVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 8;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bWhlSlipVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 16;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bESPRegVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 32;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bASRRegVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 64;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bABSRegVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 128;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)DDS_TRUE == (UInt32)VSCtl_bTyreWarnVSReg)
        {
            vsreg_uvalue = vsreg_uvalue + 256;
        }
        else
        {
            /* Nothing to do */
        }

        VSCtl_stDeacVSRegReq_Brk = (UInt16)vsreg_uvalue;
    }
    else
    {
        VSCtl_stDeacVSRegReq_Brk = (UInt16)(BIN9 - 1);
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSREG_Brake_Cond_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_Brake_Cond_Sl_Init(void)
{
    /* ---- Init Outputs ---- */
    VSCtl_stDeacVSRegReq_Brk = (UInt16)(BIN9 - 1);

    /* ---- Init Global Datas ---- */
    VSCtl_bBrkPedPrssVSReg = DDS_TRUE;
    VSCtl_bPrkBrkVSReg = DDS_TRUE;
    VSCtl_bBrkAutoVSReg = DDS_TRUE;
    VSCtl_bBrkDynVSReg = DDS_TRUE;
    VSCtl_bTyreWarnVSReg = DDS_TRUE;

    /* ---- VSREG_F21221_Determiner_Condition_Appui_Pedale_Frein ---- */

    /* ---- VSREG_F21222_Determiner_Condition_Serrage_Frein_Main ---- */

    /* ---- VSREG_F21223_Determiner_Condition_Freinage_Automatique ---- */

    /* ---- VSREG_F21224_Determiner_Condition_Freinage_Dynamique ---- */

    /* ---- VSREG_F21229_Determiner_Condition_Alerte_Pneumatiques ---- */

    /* ---- VSREG_F2122a_Determiner_Conditions_Maintenance_Frein_Las ---- */

}



#define VSREG_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSReg_MemMap.h"

