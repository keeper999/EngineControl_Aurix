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
* Ref X:\integration_view_00PSASWC_D210D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Elabor_Info_Las_Sl.c
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 6 m User:meme 
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 6 m User:demezil 
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L02_010_IMPL1
*    comments :for VSInfo 11.0
* Version int :/main/L01_01/3 Date: 12/5/2011 8 h 48 m User:meme
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1_D
*    comments :use DDS_M_BARY_FILTER_V2 instead of DDS_M_BARY_FILTER
* Version dev :\main\branch_demezil_generic_view\1 Date: 10/5/2011 17 h 30 m User:demezil
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1_D
*    comments :use DDS_M_BARY_FILTER_V2 instead of DDS_M_BARY_FILTER
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 24 m User:meme
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :UT correction
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\11 Date: 24/2/2011 12 h 59 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\10 Date: 15/2/2011 17 h 16 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :for VSInfo 10.0
* Version dev :\main\branch_morisseau_vsinfo_dev\9 Date: 2/2/2011 17 h 51 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\8 Date: 2/2/2011 17 h 49 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :for QAC
* Version dev :\main\branch_morisseau_vsinfo_dev\7 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\6 Date: 6/1/2011 14 h 25 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :correc IN/OUT
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 21/12/2010 14 h 13 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :delete main declaration
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 21/12/2010 9 h 33 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :correct filter init
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 8 h 30 m User:morisseau
*    TWK_model:VSINFO_Elabor_Info_Las_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 9 m User:morisseau
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

#define VSINFO_0                (0)
#define VSINFO_100_BIN7         (100 * BIN7)
#define VSINFO_255_BIN7         (255 * BIN7)

  /* VSCtl_stVehSpdRefModClc */
#define VSCTL_STVEHSPDREFMODCLC_ARRET           (0)
#define VSCTL_STVEHSPDREFMODCLC_VERIF_16        (1)
#define VSCTL_STVEHSPDREFMODCLC_INIT_16         (2)
#define VSCTL_STVEHSPDREFMODCLC_AVANT_16        (3)
#define VSCTL_STVEHSPDREFMODCLC_ARRIERE_16      (4)
#define VSCTL_STVEHSPDREFMODCLC_INTEGRAL_16     (5)
#define VSCTL_STVEHSPDREFMODCLC_DEFAUT_16       (6)

  /* VSCtl_st_rWhlSlipModClc */
#define VSCTL_ST_RWHLSLIPMODCLC_ARRET           (0)
#define VSCTL_ST_RWHLSLIPMODCLC_VERIF_19        (1)
#define VSCTL_ST_RWHLSLIPMODCLC_INIT_19         (2)
#define VSCTL_ST_RWHLSLIPMODCLC_NOMINAL_19      (3)
#define VSCTL_ST_RWHLSLIPMODCLC_DEFAUT_19       (4)

  /* VSCtl_stDetLoWhlGripClc */
#define VSCTL_STDETLOWHLGRIPCLC_ARRET           (0)
#define VSCTL_STDETLOWHLGRIPCLC_VERIF_21        (1)
#define VSCTL_STDETLOWHLGRIPCLC_NOMINAL_21      (2)
#define VSCTL_STDETLOWHLGRIPCLC_DEFAUT_21       (3)

  /* VSCtl_stnFrntWhlModClc */
#define VSCTL_STNFRNTWHLMODCLC_ARRET            (0)
#define VSCTL_STNFRNTWHLMODCLC_VERIF_37         (1)
#define VSCTL_STNFRNTWHLMODCLC_INIT_37          (2)
#define VSCTL_STNFRNTWHLMODCLC_NOMINAL_37       (3)
#define VSCTL_STNFRNTWHLMODCLC_DEFAUT_37        (4)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_nFrntWhlClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rWhlSlipClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_stDetLoWhlGripClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_stVehSpdRefModClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_st_rWhlSlipModClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_stnFrntWhlModClc;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rWhlSlip_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacSpdFrntWhl_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacSpdReWhl_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDetLoWhlGripIni_C = DDS_FALSE;
#define VSINFO_STOP_SEC_CALIB_8BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1342_filter_struct_no1;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1342_filter_struct_no2;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_f1362_filter_struct;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rWhlSlipRaw1; /* BIN7 */
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rWhlSlipRaw2; /* BIN7 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
/* <PRQA_COMMENT><3229> Variable is link to a terminator </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bDetLoWhlGrip;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
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

/* FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_F1332_Determiner_Vitesse_Vehicule_Reference
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F1332_Determiner_Vitesse_Vehicule_Reference(
                               UInt16 Ext_spdFrntWhl_swc_in, /* BIN7 */
                               UInt16 Ext_spdReWhl_swc_in, /* BIN7 */
                               UInt8 FRM_bRcvVSCtlSpdFrntWhl_swc_in,
                               UInt8 FRM_bRcvVSCtlSpdReWhl_swc_in,
                               UInt16 VSCtl_rTqWhlPTRe_swc_in, /* BIN7 */
                               UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehRef_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.163.0 */
    UInt16 vsinfo_switch1_out;
    UInt16 vsinfo_switch2_out;

    /* BIN7; [0;255] */
    if(  ((UInt32)FRM_bRcvVSCtlSpdFrntWhl_swc_in == (UInt32)DDS_FALSE)
       &&((UInt32)VSCtl_bDeacSpdFrntWhl_C == (UInt32)DDS_FALSE))
    {
        vsinfo_switch1_out = Ext_spdFrntWhl_swc_in;
    }
    else
    {
        vsinfo_switch1_out = (UInt16)DDS_M_SATURATION_V2((UInt32)Veh_spdVeh_swc_in,VSINFO_0,VSINFO_255_BIN7);
    }

    /* BIN7; [0;255] */
    if(  ((UInt32)FRM_bRcvVSCtlSpdReWhl_swc_in == (UInt32)DDS_FALSE)
       &&((UInt32)VSCtl_bDeacSpdReWhl_C == (UInt32)DDS_FALSE))
    {
        vsinfo_switch2_out = Ext_spdReWhl_swc_in;
    }
    else
    {
        vsinfo_switch2_out = (UInt16)DDS_M_SATURATION_V2((UInt32)Veh_spdVeh_swc_in,VSINFO_0,VSINFO_255_BIN7);
    }



    switch((UInt32)VSCtl_stVehSpdRefModClc)
    {
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_AVANT_16:
            *VSCtl_spdVehRef_swc_out = vsinfo_switch1_out;
            break;
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_ARRIERE_16:
            *VSCtl_spdVehRef_swc_out = vsinfo_switch2_out;
            break;
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_INTEGRAL_16:
            *VSCtl_spdVehRef_swc_out = (UInt16)DDS_M_BARY_FILTER_S16_V2(
                                                            (SInt16)vsinfo_switch2_out,
                                                            (SInt16)vsinfo_switch1_out,
                                                            (SInt16)VSCtl_rTqWhlPTRe_swc_in,
                                                            (UInt16)VSINFO_100_BIN7);
            break;
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_ARRET:
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_VERIF_16:
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_INIT_16:
        case (UInt32)VSCTL_STVEHSPDREFMODCLC_DEFAUT_16:
        default:
            *VSCtl_spdVehRef_swc_out = (UInt16)VSINFO_0;
            break;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1342_Determiner_Glissement_Relatif
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F1342_Determiner_Glissement_Relatif(
                               UInt16 Ext_spdFrntWhl_swc_in, /* BIN7 */
                               UInt16 Ext_spdReWhl_swc_in, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no1_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no2_swc_out /* BIN7 */)

{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.166.0 */
    SInt32 vsinfo_svalue;
    SInt32 vsinfo_filter1_in;
    SInt32 vsinfo_filter2_in;
    UInt16 vsinfo_filter1_out;
    UInt16 vsinfo_filter2_out;
    UInt32 vsctl_st_rwhlslipmodclc_loc;

    vsctl_st_rwhlslipmodclc_loc = (UInt32)VSCtl_st_rWhlSlipModClc;

    /* BIN7 = BIN7 - BIN7 */
    /* [-25500;25500] = ([0;255] -  [0;255]) * 100 */
    vsinfo_svalue = (SInt32)Ext_spdFrntWhl_swc_in - (SInt32)Ext_spdReWhl_swc_in;
    vsinfo_svalue = 100 * vsinfo_svalue;

    if((SInt32)Ext_spdReWhl_swc_in != 0)
    {
        vsinfo_filter1_in = (vsinfo_svalue * BIN7) / (SInt32)Ext_spdReWhl_swc_in;
        vsinfo_filter1_in = DDS_M_LIMIT(vsinfo_filter1_in,VSINFO_0,VSINFO_100_BIN7);
    }
    else
    {
        vsinfo_filter1_in = VSINFO_100_BIN7;
    }

    if((SInt32)Ext_spdFrntWhl_swc_in != 0)
    {
        vsinfo_filter2_in = ((- vsinfo_svalue) * BIN7)/ (SInt32)Ext_spdFrntWhl_swc_in;
        vsinfo_filter2_in = DDS_M_LIMIT(vsinfo_filter2_in,VSINFO_0,VSINFO_100_BIN7);
    }
    else
    {
        vsinfo_filter2_in = VSINFO_100_BIN7;
    }


    if((UInt32)VSCtl_bAcvFil_rWhlSlipClc != (UInt32)DDS_FALSE)
    {
        vsinfo_filter1_out = DDS_M_FILTER_LP1_U16(&vsinfo_f1342_filter_struct_no1,
                                                  (UInt16)vsinfo_filter1_in,
                                                  VSCtl_tiFil_rWhlSlip_C, BIN10);
        vsinfo_filter2_out = DDS_M_FILTER_LP1_U16(&vsinfo_f1342_filter_struct_no2,
                                                  (UInt16)vsinfo_filter2_in,
                                                  VSCtl_tiFil_rWhlSlip_C, BIN10);
    }
    else
    {
        vsinfo_filter1_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1342_filter_struct_no1,VSINFO_0);
        vsinfo_filter2_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1342_filter_struct_no2,VSINFO_0);
    }

    if(  (vsctl_st_rwhlslipmodclc_loc == (UInt32)VSCTL_ST_RWHLSLIPMODCLC_INIT_19)
       ||(vsctl_st_rwhlslipmodclc_loc == (UInt32)VSCTL_ST_RWHLSLIPMODCLC_NOMINAL_19))
    {
        *VSCtl_rWhlSlip_no1_swc_out = vsinfo_filter1_out;
        *VSCtl_rWhlSlip_no2_swc_out = vsinfo_filter2_out;
        VSCtl_rWhlSlipRaw1 = (UInt16)vsinfo_filter1_in;
        VSCtl_rWhlSlipRaw2 = (UInt16)vsinfo_filter2_in;
    }
    else
    {
        *VSCtl_rWhlSlip_no1_swc_out = (UInt16)VSINFO_0;
        *VSCtl_rWhlSlip_no2_swc_out = (UInt16)VSINFO_0;
        VSCtl_rWhlSlipRaw1 = (UInt16)VSINFO_0;
        VSCtl_rWhlSlipRaw2 = (UInt16)VSINFO_0;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1352_Determiner_Niveau_Adherence
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F1352_Determiner_Niveau_Adherence(
                               UInt8 Ext_bDetLoWhlGrip_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.182.0 */

    if((UInt32)VSCtl_stDetLoWhlGripClc == VSCTL_STDETLOWHLGRIPCLC_NOMINAL_21)
    {
        VSCtl_bDetLoWhlGrip = Ext_bDetLoWhlGrip_swc_in;
    }
    else
    {
        VSCtl_bDetLoWhlGrip = VSCtl_bDetLoWhlGripIni_C;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1362_Determiner_Regime_Roue_Avant
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F1362_Determiner_Regime_Roue_Avant(
                               UInt32 Ext_nFrntWhl_swc_in, /* BIN7 */
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nFrntWhlFil_swc_out /* BIN7 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2268.FR.169.0 */
    UInt32 vsinfo_uvalue;
    UInt32 vsctl_stnfrntwhlmodclc_loc;

    vsctl_stnfrntwhlmodclc_loc = (UInt32)VSCtl_stnFrntWhlModClc;


    if((UInt32)VSCtl_bAcvFil_nFrntWhlClc != (UInt32)DDS_FALSE)
    {
        vsinfo_uvalue = (UInt32)DDS_M_FILTER_LP1_S32(&vsinfo_f1362_filter_struct,
                                             (SInt32)Ext_nFrntWhl_swc_in,
                                             (UInt16)((UInt32)VSCtl_tiFil_nFrntWhl_C*BIN5));
    }
    else
    {
        vsinfo_uvalue = (UInt32)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1362_filter_struct,(SInt32)Ext_nFrntWhl_swc_in);
    }


    if(  (vsctl_stnfrntwhlmodclc_loc == VSCTL_STNFRNTWHLMODCLC_INIT_37)
       ||(vsctl_stnfrntwhlmodclc_loc == VSCTL_STNFRNTWHLMODCLC_NOMINAL_37))
    {
        *VSCtl_nFrntWhlFil_swc_out = vsinfo_uvalue;
    }
    else
    {
        *VSCtl_nFrntWhlFil_swc_out = VSINFO_0;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Elabor_Info_Las_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Elabor_Info_Las_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no1_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rWhlSlip_no2_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_nFrntWhlFil_swc_out, /* BIN7 */
                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVehRef_swc_out /* BIN7 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_rWhlSlip_no1_swc_out = (UInt16)(0 * BIN7);
    *VSCtl_rWhlSlip_no2_swc_out = (UInt16)(0 * BIN7);
    *VSCtl_nFrntWhlFil_swc_out = (UInt32)(0 * BIN7);
    *VSCtl_spdVehRef_swc_out = (UInt16)(0 * BIN7);

    /* ---- Init Global Datas ---- */
    VSCtl_bDetLoWhlGrip = DDS_FALSE;
    VSCtl_rWhlSlipRaw1 = (UInt16)(0 * BIN7);
    VSCtl_rWhlSlipRaw2 = (UInt16)(0 * BIN7);

    /* ---- VSINFO_F1332_Determiner_Vitesse_Vehicule_Reference ---- */

    /* ---- VSINFO_F1342_Determiner_Glissement_Relatif ---- */
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1342_filter_struct_no1,VSINFO_0);
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1342_filter_struct_no2,VSINFO_0);

    /* ---- VSINFO_F1352_Determiner_Niveau_Adherence ---- */

    /* ---- VSINFO_F1362_Determiner_Regime_Roue_Avant ---- */
    DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1362_filter_struct,(SInt32)0);
}



#define VSINFO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSInfo_MemMap.h"

