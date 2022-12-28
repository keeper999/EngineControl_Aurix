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
* Ref X:\integration_view_00PSASWC_D822D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Det_Gearbox_Order_Sl.c
* Version int :/main/L02_01/2 Date: 18/10/2012 14 h 47 m User:posmyk 
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L02_010_IMPL1_D
*    comments :Update F722621 function due to specification update.
* Version dev :\main\branch_girodon_module_dev\1 Date: 16/10/2012 16 h 27 m User:girodon 
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L02_010_IMPL1_D
*    comments :Update F722621 function due to specification update.
* Version int :/main/L02_01/1 Date: 6/1/2012 11 h 10 m User:esnault 
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L02_010_IMPL1
*    comments :For VSSp_12_e6, correction for UT
* Version dev :\main\branch_demezil_vssp_view\2 Date: 19/12/2011 11 h 53 m User:halouane 
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L02_010_IMPL1
*    comments :For VSSp_12_e6, correction for UT
* Version dev :\main\branch_demezil_vssp_view\1 Date: 29/11/2011 17 h 21 m User:demezil
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L02_010_IMPL1
*    comments :for VSSp 12.0
* Version int :/main/L01_01/2 Date: 16/3/2011 11 h 48 m User:esnault
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\7 Date: 3/3/2011 11 h 23 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vssp_euro6\6 Date: 28/2/2011 13 h 33 m User:veillard
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : Correction after TU
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 28/2/2011 13 h 23 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : Correction after TU
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 28/2/2011 13 h 22 m User:veillard
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : Correction after TU
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 53 m User:meme
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 22/2/2011 17 h 51 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 5 m User:morisseau
*    TWK_model:VSSP_Det_Gearbox_Order_Sl_L01_010_IMPL1
*    comments :add model
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 11/1/2011 16 h 41 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSSp
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSSp.h"


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
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear2Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear3Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear4Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear5Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear6Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear7Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMaxGear8Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear2Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear3Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear4Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear5Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear6Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear7Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlMinGear8Thd; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxIntNegReq; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxIntPosReq; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinIntNegReq; /* BIN1 */
extern VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinIntPosReq; /* BIN1 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMax; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqNegFil; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqPosFil; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearMinTqPosFil; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearTqNegMin; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_noGearTqPosMin; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_noGearMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_noGearMin;
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"



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

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqNegRaw; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_noGearMaxTqPosRaw; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_noGearMinTqPosRaw; /* BIN0 */
#define VSSP_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 8-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacSdwn_noGearMaxTqN_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bDeacTqPotMax_noGearMax_C = DDS_FALSE;
#define VSSP_STOP_SEC_CALIB_8BIT
#include "VSSp_MemMap.h"


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
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
/* <PRQA_COMMENT><3229> variable linked to a terminator in spec </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotCoordPosReq;  /* BIN1 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"

/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSSP_START_SEC_CODE
#include "VSSp_MemMap.h"

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
* Function Name : VSSP_F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute(
                                                UInt8 VSCtl_stCtl_aVehVSMax_swc_in)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.96.1 */
    SInt32 vssp_sminvalue;
    UInt32 vssp_uvalue;

    if((UInt32)VSCtl_stCtl_noGearMax == (UInt32)DDS_TRUE)
    {
        if(  (  ((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == (UInt32)VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
              ||((UInt32)VSCtl_stCtl_aVehVSMax_swc_in == (UInt32)VSSP_VSCTL_STTQWHLPTMINSAT_TRANSITION))
           &&((UInt32)VSCtl_bDeacTqPotMax_noGearMax_C != (UInt32)DDS_TRUE))
        {
            /* BIN1:[-16000;16000]N.m */
            vssp_sminvalue = DDS_M_MIN((SInt32)VSCtl_tqWhlPotMinIntPosReq,(SInt32)VSCtl_tqWhlPotMaxIntPosReq);
        }
        else
        {
            /* Equal to DDS_M_MIN(VSCtl_tqWhlPotMinIntPosReq; 16000) */
            vssp_sminvalue = (SInt32)VSCtl_tqWhlPotMinIntPosReq;
        }

        if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear8Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_8EME_RAPPORT;
        }
        else if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear7Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_7EME_RAPPORT;
        }
        else if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear6Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_6EME_RAPPORT;
        }
        else if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear5Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_5EME_RAPPORT;
        }
        else if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear4Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_4EME_RAPPORT;
        }
        else if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear3Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_3EME_RAPPORT;
        }
        else if(vssp_sminvalue <= (SInt32)VSCtl_tqWhlMaxGear2Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_2EME_RAPPORT;
        }
        else
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_1ER_RAPPORT;
        }

        VSCtl_noGearMaxTqPosRaw = (UInt8)DDS_M_SATURATION_V2(vssp_uvalue,(UInt32)VSCtl_noGearTqPosMin,(UInt32)VSCtl_noGearMax);
        VSCtl_tqWhlPotCoordPosReq = (SInt16)vssp_sminvalue;
    }
    else
    {
        VSCtl_tqWhlPotCoordPosReq = 0*BIN1;
        VSCtl_noGearMaxTqPosRaw = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.99.1 */
    SInt32 vssp_sminvalue;
    UInt32 vssp_uvalue;

    if((UInt32)VSCtl_stCtl_noGearMax == (UInt32)DDS_TRUE)
    {
        /* BIN1:[[-16000;16000]N.m */
        vssp_sminvalue = DDS_M_MIN((SInt32)VSCtl_tqWhlPotMaxIntNegReq,(SInt32)VSCtl_tqWhlPotMinIntNegReq);

        if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear8Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_8EME_RAPPORT;
        }
        else if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear7Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_7EME_RAPPORT;
        }
        else if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear6Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_6EME_RAPPORT;
        }
        else if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear5Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_5EME_RAPPORT;
        }
        else if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear4Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_4EME_RAPPORT;
        }
        else if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear3Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_3EME_RAPPORT;
        }
        else if(vssp_sminvalue >= (SInt32)VSCtl_tqWhlMinGear2Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_2EME_RAPPORT;
        }
        else
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_1ER_RAPPORT;
        }

        VSCtl_noGearMaxTqNegRaw = (UInt8)DDS_M_SATURATION_V2(vssp_uvalue,(UInt32)VSCtl_noGearTqNegMin,(UInt32)VSCtl_noGearMax);
    }
    else
    {
        VSCtl_noGearMaxTqNegRaw = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72264_Determiner_Consigne_Rapport_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72264_Determiner_Consigne_Rapport_Max(
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMax_swc_out)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.101.0 */
    UInt32 vssp_uvalue_1;
    UInt32 vssp_uvalue_2;

    UInt16 vsctl_nogearmax_cpy;

    vsctl_nogearmax_cpy = VSCtl_noGearMax;

    if((UInt32)VSCtl_stCtl_noGearMax == (UInt32)DDS_TRUE)
    {
        vssp_uvalue_1 = DDS_M_SATURATION_V2((UInt32)VSCtl_noGearMaxTqPosFil,(UInt32)VSCtl_noGearTqPosMin,(UInt32)vsctl_nogearmax_cpy);

        if((UInt32)VSCtl_bDeacSdwn_noGearMaxTqN_C == (UInt32)DDS_TRUE)
        {
            vssp_uvalue_2 = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
        }
        else
        {
            vssp_uvalue_2 = DDS_M_SATURATION_V2((UInt32)VSCtl_noGearMaxTqNegFil,(UInt32)VSCtl_noGearTqNegMin,(UInt32)vsctl_nogearmax_cpy);
        }
        *VSCtl_noGearReqMax_swc_out = (UInt8)DDS_M_MIN(vssp_uvalue_1,vssp_uvalue_2);
    }
    else
    {
        *VSCtl_noGearReqMax_swc_out = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute(void)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.105.1 */
    UInt32 vssp_uvalue;

    if((UInt32)VSCtl_stCtl_noGearMin == (UInt32)DDS_TRUE)
    {
        if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear8Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_8EME_RAPPORT;
        }
        else if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear7Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_7EME_RAPPORT;
        }
        else if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear6Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_6EME_RAPPORT;
        }
        else if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear5Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_5EME_RAPPORT;
        }
        else if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear4Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_4EME_RAPPORT;
        }
        else if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear3Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_3EME_RAPPORT;
        }
        else if((SInt32)VSCtl_tqWhlPotMaxIntPosReq <= (SInt32)VSCtl_tqWhlMaxGear2Thd)
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_2EME_RAPPORT;
        }
        else
        {
           vssp_uvalue = VSSP_VSCTL_NOGEARREQ_1ER_RAPPORT;
        }

        VSCtl_noGearMinTqPosRaw = (UInt8)DDS_M_SATURATION_V2(vssp_uvalue,(UInt32)VSCtl_noGearTqPosMin,(UInt32)VSCtl_noGearMax);
    }
    else
    {
        VSCtl_noGearMinTqPosRaw = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72273_Coordonner_Consigne_Rapport_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72273_Coordonner_Consigne_Rapport_Min(
                                                UInt8 VSCtl_noGearReqMax_swc_in,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMin_swc_out )
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.107.1 */
    UInt32 vssp_uvalue;

    if((UInt32)VSCtl_stCtl_noGearMin == (UInt32)DDS_TRUE)
    {
        vssp_uvalue = DDS_M_MIN((UInt32)VSCtl_noGearReqMax_swc_in,(UInt32)VSCtl_noGearMax);
        *VSCtl_noGearReqMin_swc_out = (UInt8)DDS_M_SATURATION_V2((UInt32)VSCtl_noGearMinTqPosFil,(UInt32)VSCtl_noGearTqPosMin,vssp_uvalue);
    }
    else
    {
        if((UInt32)VSCtl_stCtl_noGearMax == (UInt32)DDS_TRUE)
        {
            *VSCtl_noGearReqMin_swc_out = VSSP_VSCTL_NOGEARREQ_1ER_RAPPORT;
        }
        else
        {
            *VSCtl_noGearReqMin_swc_out = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;
        }
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Det_Gearbox_Order_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Det_Gearbox_Order_Sl_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMax_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearReqMin_swc_out )
{
    /* ---- Init Outputs ---- */
    *VSCtl_noGearReqMax_swc_out = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    *VSCtl_noGearReqMin_swc_out = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;

    VSCtl_noGearMaxTqNegRaw = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    VSCtl_noGearMaxTqPosRaw = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_HAUT;
    VSCtl_noGearMinTqPosRaw = VSSP_VSCTL_NOGEARREQ_RAPPORT_DE_REPLI_BAS;

    /* ---- Init Global Datas ---- */

    /* ---- VSSP_F722621_Determiner_Consigne_Rapport_Max_Couple_Roue_Positif_Brute ---- */
    VSCtl_tqWhlPotCoordPosReq = 0;

    /* ---- VSSP_F722631_Determiner_Consigne_Rapport_Max_Couple_Roue_Negatif_Brute ---- */

    /* ---- VSSP_F72264_Determiner_Consigne_Rapport_Max ---- */

    /* ---- VSSP_F722721_Determiner_Consigne_Rapport_Min_Couple_Roue_Positif_Brute ---- */

    /* ---- VSSP_F72273_Coordonner_Consigne_Rapport_Min ---- */

}



#define VSSP_STOP_SEC_CODE
#include "VSSp_MemMap.h"

