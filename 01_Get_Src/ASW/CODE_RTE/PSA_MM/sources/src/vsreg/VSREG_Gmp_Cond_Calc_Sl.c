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
* Ref X:\integration_view_00PSASWC_D310D01\blois_psa_sstg\Software\Appli\VSReg\src\VSREG_Gmp_Cond_Calc_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 10 h 46 m User:meme 
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L02_010_IMPL1
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\3 Date: 1/8/2011 15 h 28 m User:demezil 
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L02_010_IMPL1
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\2 Date: 19/7/2011 16 h 23 m User:demezil
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L02_010_IMPL1
*    comments :for VSReg 11.0
* Version dev :\main\branch_demezil_vsreg_view\1 Date: 19/7/2011 11 h 40 m User:demezil
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1_D
*    comments :for VSReg 11.0
* Version int :/main/L01_01/2 Date: 11/2/2011 12 h 48 m User:esnault
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_xvv_vsreg\5 Date: 2/2/2011 14 h 18 m User:morisseau
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 28/1/2011 10 h 27 m User:esnault
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\4 Date: 27/1/2011 15 h 48 m User:morisseau
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
*    comments :for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\3 Date: 17/12/2010 16 h 28 m User:morisseau
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
*    comments :remove main prototype
* Version dev :\main\branch_morisseau_xvv_vsreg\2 Date: 17/12/2010 15 h 11 m User:morisseau
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
*    comments :first version for VSReg 10.0
* Version dev :\main\branch_morisseau_xvv_vsreg\1 Date: 17/12/2010 10 h 43 m User:morisseau
*    TWK_model:VSREG_Gmp_Cond_Calc_Sl_L01_010_IMPL1
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

/* 8-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bCfVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bctDefRevVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg1_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg2_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg3_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDirMoveVehVSReg_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bORng_nTqVSReg_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bPosnGBxLevVSReg_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bStEngVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bNEngMaxVSReg;
extern VAR(UInt8, AUTOMATIC) VSCtl_bNEngMinVSReg_no1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bNEngMinVSReg_no2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg1_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg2_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAvlTqWhlPTVSReg3_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bCluPedPrssVSReg_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bPosnGBxLevVSReg_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bNoGearVSReg_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bNoGearEgdChgVSReg_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bGearCtlVSReg_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_pt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_pt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_pt2;
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
VAR(UInt16, AUTOMATIC) VSCtl_stDeacVSRegReq_pt; /* BIN0 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"

/* 8-bits variables definition */
#define VSREG_START_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_bInhVSRegReq_pt;
VAR(UInt8, AUTOMATIC) VSCtl_bFastDeacVSRegReq_pt;
VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSRegReq_Ini; /* BIN0 */
#define VSREG_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSReg_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* NONE */


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
#define VSREG_START_SEC_INTERNAL_VAR_16BIT
#include "VSReg_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_stDeacVSRegReq_pt1; /* BIN0 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_stDeacVSRegReq_pt2; /* BIN0 */
#define VSREG_STOP_SEC_INTERNAL_VAR_16BIT
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
* Function Name : VSREG_F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite(
                                             UInt8 Ext_bKeyOff_swc_in,
                                             UInt8 FRM_bDeacIrvVSReg_swc_in,
                                             UInt8 FRM_bDeacRvVSReg_swc_in,
                                             UInt8 SftyMgt_bDeacIrvVSReg_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.77.0 */
    UInt32 vsreg_uvalue;

    if((UInt32)VSCtl_bCfVSReg == (UInt32)DDS_TRUE)
    {
        vsreg_uvalue = BIN1;
    }
    else
    {
        vsreg_uvalue = 0;
    }
    if((UInt32)Ext_bKeyOff_swc_in == (UInt32)DDS_TRUE)
    {
        vsreg_uvalue = vsreg_uvalue + BIN0;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)VSCtl_bctDefRevVSReg == (UInt32)DDS_TRUE)
    {
        vsreg_uvalue = vsreg_uvalue + BIN2;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)FRM_bDeacRvVSReg_swc_in == (UInt32)DDS_TRUE)
    {
        vsreg_uvalue = vsreg_uvalue + BIN3;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)FRM_bDeacIrvVSReg_swc_in == (UInt32)DDS_TRUE)
    {
        vsreg_uvalue = vsreg_uvalue + BIN4;
    }
    else
    {
        /* Nothing to do */
    }
    if((UInt32)SftyMgt_bDeacIrvVSReg_swc_in == (UInt32)DDS_TRUE)
    {
        vsreg_uvalue = vsreg_uvalue + BIN5;
    }
    else
    {
        /* Nothing to do */
    }


    VSCtl_stDeacVSRegReq_Ini = (UInt8)vsreg_uvalue;
}

/*******************************************************************************
*
* Function Name : VSREG_F212115_Determiner_Conditions_Maintenance_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F212115_Determiner_Conditions_Maintenance_Gmp(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.81.0 */
    UInt32 vsreg_uvalue;

    if((UInt32)VSCtl_stMonVSReg == (UInt32)VSCTL_STMONVSREG_NOMINAL)
    {
        if((UInt32)VSCtl_bAvlTqWhlPTVSReg1_pt1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = BIN0;
        }
        else
        {
            vsreg_uvalue = 0;
        }
        if((UInt32)VSCtl_bAvlTqWhlPTVSReg2_pt1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN1;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAvlTqWhlPTVSReg3_pt1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN2;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bDirMoveVehVSReg_pt1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN3;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bORng_nTqVSReg_pt1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN4;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bPosnGBxLevVSReg_pt1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN5;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    {
        vsreg_uvalue = BIN14 - 1;
    }


    VSCtl_stDeacVSRegReq_pt1 = (UInt16)vsreg_uvalue;
}

/*******************************************************************************
*
* Function Name : VSREG_F2121231_Determiner_Conditions_Maintenance_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F2121231_Determiner_Conditions_Maintenance_Gmp(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.89.0 */
    UInt32 vsreg_uvalue;

    if((UInt32)VSCtl_stMonVSReg == (UInt32)VSCTL_STMONVSREG_NOMINAL)
    {
        if((UInt32)VSCtl_bStEngVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = BIN6;
        }
        else
        {
            vsreg_uvalue = 0;
        }
        if((UInt32)VSCtl_bNEngMaxVSReg == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN7;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bNEngMinVSReg_no1 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN8;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bNEngMinVSReg_no2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN9;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAvlTqWhlPTVSReg1_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN0;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAvlTqWhlPTVSReg2_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN1;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bAvlTqWhlPTVSReg3_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN2;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bCluPedPrssVSReg_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN10;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bPosnGBxLevVSReg_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN5;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bNoGearVSReg_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN11;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bNoGearEgdChgVSReg_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN12;
        }
        else
        {
            /* Nothing to do */
        }
        if((UInt32)VSCtl_bGearCtlVSReg_pt2 == (UInt32)DDS_TRUE)
        {
            vsreg_uvalue = vsreg_uvalue + BIN13;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    {
        vsreg_uvalue = BIN14 - 1;
    }


    VSCtl_stDeacVSRegReq_pt2 = (UInt16)vsreg_uvalue;
}

/*******************************************************************************
*
* Function Name : VSREG_F21213_Determiner_Conditions_Fonctionnement_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_F21213_Determiner_Conditions_Fonctionnement_Gmp(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2269.FR.28.3 */
/* <PRQA_COMMENT><3325> statement value change with VSCtl_bCtlCmdPTTqCf_SC </3325></PRQA_COMMENT> */
    if((UInt32)VSCtl_bCtlCmdPTTqCf_SC == (UInt32)DDS_TRUE)
/* <PRQA_COMMENT><3201> statement reachable if VSCtl_bCtlCmdPTTqCf_SC = DDS_TRUE </3201></PRQA_COMMENT> */
    {
        VSCtl_bFastDeacVSRegReq_pt = VSCtl_bFastDeacVSRegReq_pt1;
        VSCtl_bInhVSRegReq_pt = VSCtl_bInhVSRegReq_pt1;
        VSCtl_stDeacVSRegReq_pt = VSCtl_stDeacVSRegReq_pt1;
    }
    else
    {
        VSCtl_bFastDeacVSRegReq_pt = VSCtl_bFastDeacVSRegReq_pt2;
        VSCtl_bInhVSRegReq_pt = VSCtl_bInhVSRegReq_pt2;
        VSCtl_stDeacVSRegReq_pt = VSCtl_stDeacVSRegReq_pt2;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSREG_Gmp_Cond_Calc_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSREG_Gmp_Cond_Calc_Sl_Init(void)
{
    /* ---- Init Outputs ---- */
    VSCtl_bFastDeacVSRegReq_pt = DDS_TRUE;
    VSCtl_bInhVSRegReq_pt = DDS_TRUE;
    VSCtl_stDeacVSRegReq_pt = (UInt16)(BIN14 - 1);

    /* ---- Init Global Datas ---- */
    VSCtl_stDeacVSRegReq_Ini = (UInt8)(BIN6 - 1);
    VSCtl_stDeacVSRegReq_pt1 = (UInt16)(BIN14 - 1);
    VSCtl_stDeacVSRegReq_pt2 = (UInt16)(BIN14 - 1);

    /* ---- VSREG_F2113_Determiner_Condition_Conditions_Maintenance_Initialisation_Securite ---- */

    /* ---- VSREG_F212115_Determiner_Conditions_Maintenance_Gmp ---- */

    /* ---- VSREG_F2121231_Determiner_Conditions_Maintenance_Gmp ---- */

    /* ---- VSREG_F21213_Determiner_Conditions_Fonctionnement_Gmp ---- */

}

#define VSREG_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSReg_MemMap.h"

