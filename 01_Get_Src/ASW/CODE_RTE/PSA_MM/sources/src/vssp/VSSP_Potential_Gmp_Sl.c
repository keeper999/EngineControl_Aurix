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
* Ref X:\integration_view_00PSASWC_D810D01\blois_psa_sstg\Software\Appli\VSSp\src\VSSP_Potential_Gmp_Sl.c
* Version int :/main/L02_01/1 Date: 7/9/2011 16 h 41 m User:esnault 
*    TWK_model:VSSP_Potential_Gmp_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version dev :\main\branch_demezil_vssp_view\1 Date: 26/7/2011 9 h 57 m User:demezil 
*    TWK_model:VSSP_Potential_Gmp_Sl_L02_010_IMPL1
*    comments :for VSSp 11.0
* Version int :/main/L01_01/1 Date: 25/2/2011 8 h 54 m User:meme
*    TWK_model:VSSP_Potential_Gmp_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\5 Date: 22/2/2011 17 h 51 m User:morisseau
*    TWK_model:VSSP_Potential_Gmp_Sl_L01_010_IMPL1
*    comments :VSSp 10.0 : for QAC
* Version dev :\main\branch_morisseau_vssp_euro6\4 Date: 22/2/2011 16 h 56 m User:morisseau
*    TWK_model:VSSP_Potential_Gmp_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0
* Version dev :\main\branch_morisseau_vssp_euro6\3 Date: 10/2/2011 12 h 43 m User:morisseau
*    TWK_model:VSSP_Potential_Gmp_Sl_L01_010_IMPL1
*    comments :for VSSp 10.0 - work in progress
* Version dev :\main\branch_morisseau_vssp_euro6\2 Date: 18/1/2011 11 h 22 m User:morisseau
*    TWK_model:VSSP_Potential_Gmp_Sl_L01_010_IMPL1
*    comments :add model
* Version dev :\main\branch_morisseau_vssp_euro6\1 Date: 11/1/2011 16 h 42 m User:morisseau
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

#define VSSP_0                  (0)
#define VSSP_4000_BIN1          (4000 * BIN1)
#define VSSP_11000_BIN1         (11000 * BIN1)
#define VSSP_16000_BIN1         (16000 * BIN1)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 8-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_8BIT
#include "VSSp_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTPotMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTPotMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTPotMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTPotMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_tqWhlPTPot;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_tqWhlPTPot;
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

/* 16-bits variables definition */
#define VSSP_START_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinIntReq; /* BIN1 */
VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxIntReq; /* BIN1 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSupIntReq; /* DEC2 */
VAR(UInt16, AUTOMATIC) VSCtl_tiCfmSdwnIntReq; /* DEC2 */
VAR(SInt16, AUTOMATIC) VSCtl_dtqWhlPTPotReq; /* BIN1 */
#define VSSP_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSSP_START_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlPTMinReq_C = (CONST(UInt16, AUTOMATIC))(0.203 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlPTMaxReq_C = (CONST(UInt16, AUTOMATIC))(0.203 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_tqWhlPTReq_C = (CONST(UInt16, AUTOMATIC))(0.200 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_dtqWhlPTPotReq_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
#define VSSP_STOP_SEC_CALIB_16BIT
#include "VSSp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSSP_START_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72112_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72122_filter_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vssp_f72152_filter_saturation_str;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vssp_f72152_dt_filter_str;
#define VSSP_STOP_SEC_VAR_UNSPECIFIED
#include "VSSp_MemMap.h"

/* 16-bits variable definition */
#define VSSP_START_SEC_VAR_16BIT
#include "VSSp_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vssp_f72152_filter_saturation_out[VSSP_4_SIZE]; /* BIN1 */
#define VSSP_STOP_SEC_VAR_16BIT
#include "VSSp_MemMap.h"

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
* Function Name : VSSP_F72112_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Min
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72112_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Min(
                                            UInt8  Ext_stCtlCmdPTTqPotCf_swc_in,
                                            UInt8  VSCtl_stCtl_tqWhlPotMin_swc_in,
                                            SInt16 VSCtl_tqWhlPotMinReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMinReq_swc_out /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.135.0 */
    SInt32 vssp_sat_out;
    SInt32 vssp_filter_out;

    vssp_sat_out = DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPotMinReq_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPotRawMin_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPotRawMax_swc_in);

    if(  ((UInt32)VSCtl_stCtl_tqWhlPotMin_swc_in == VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
       &&(  ((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in == VSSP_EXT_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR)
          ||((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in == VSSP_EXT_STCTLCMDPTTQPOTCF_RAPPORT)))
    {
        VSCtl_tqWhlPotMinIntReq = (SInt16)vssp_sat_out;
    }
    else
    {
        VSCtl_tqWhlPotMinIntReq = (SInt16)(-16000 * BIN1);
    }

    vssp_sat_out = DDS_M_SATURATION_V2(vssp_sat_out,
                                       (SInt32)VSCtl_tqWhlPTPreCoVSCMinReq_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in);

    if((UInt32)VSCtl_bAcvFil_tqWhlPTPotMin != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_S16(&vssp_f72112_filter_str, (SInt16)vssp_sat_out, VSCtl_tiFil_tqWhlPTMinReq_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_S16_INIT(&vssp_f72112_filter_str, (SInt16)vssp_sat_out);
    }

    if((UInt32)VSCtl_stCtl_tqWhlPTPotMin == (UInt32)DDS_TRUE)
    {
        *VSCtl_tqWhlPTPotMinReq_swc_out = (SInt16)DDS_M_LIMIT(vssp_filter_out,
                                                              -VSSP_4000_BIN1,
                                                              VSSP_11000_BIN1);
    }
    else
    {
        *VSCtl_tqWhlPTPotMinReq_swc_out = (SInt16)(-4000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72122_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Max
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72122_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Max(
                                            UInt8  Ext_stCtlCmdPTTqPotCf_swc_in,
                                            UInt8  VSCtl_stCtl_tqWhlPotMax_swc_in,
                                            SInt16 VSCtl_tqWhlPotMaxReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPreCoVSCMinReq_swc_in, /* BIN1 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxReq_swc_out /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.136.0 */
    SInt32 vssp_sat_out;
    SInt32 vssp_filter_out;

    vssp_sat_out = DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPotMaxReq_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPotRawMin_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPotRawMax_swc_in);

    if(  ((UInt32)VSCtl_stCtl_tqWhlPotMax_swc_in == VSSP_VSCTL_STTQWHLPTMINSAT_CONTROLE)
       &&(  ((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in == VSSP_EXT_STCTLCMDPTTQPOTCF_LEURAGE_PEDALE_ACCLERATEUR)
          ||((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in == VSSP_EXT_STCTLCMDPTTQPOTCF_RAPPORT)))
    {
        VSCtl_tqWhlPotMaxIntReq = (SInt16)vssp_sat_out;
    }
    else
    {
        VSCtl_tqWhlPotMaxIntReq = (SInt16)(16000 * BIN1);
    }

    vssp_sat_out = DDS_M_SATURATION_V2(vssp_sat_out,
                                       (SInt32)VSCtl_tqWhlPTPreCoVSCMinReq_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPreCoVSCMaxReq_swc_in);

    if((UInt32)VSCtl_bAcvFil_tqWhlPTPotMax != (UInt32)DDS_FALSE)
    {
        vssp_filter_out = DDS_M_FILTER_LP1_S16(&vssp_f72122_filter_str, (SInt16)vssp_sat_out, VSCtl_tiFil_tqWhlPTMaxReq_C, BIN10);
    }
    else
    {
        vssp_filter_out = DDS_M_FILTER_LP1_S16_INIT(&vssp_f72122_filter_str, (SInt16)vssp_sat_out);
    }

    if((UInt32)VSCtl_stCtl_tqWhlPTPotMax == (UInt32)DDS_TRUE)
    {
        *VSCtl_tqWhlPTPotMaxReq_swc_out = (SInt16)DDS_M_LIMIT(vssp_filter_out,
                                                              -VSSP_4000_BIN1,
                                                              VSSP_11000_BIN1);
    }
    else
    {
        *VSCtl_tqWhlPTPotMaxReq_swc_out = (SInt16)(11000 * BIN1);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F7214_Determiner_Temps_Confirmation_Changement_Rapport
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F7214_Determiner_Temps_Confirmation_Changement_Rapport(
                                            UInt8  Ext_stCtlCmdPTTqPotCf_swc_in,
                                            UInt16 VSCtl_tiCfmSdwnTqMaxReq_swc_in, /* DEC2 */
                                            UInt16 VSCtl_tiCfmSdwnTqMinReq_swc_in, /* DEC2 */
                                            UInt16 VSCtl_tiCfmSupTqMaxReq_swc_in, /* DEC2 */
                                            UInt16 VSCtl_tiCfmSupTqMinReq_swc_in, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupReq_swc_out, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnReq_swc_out /* DEC2 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.35.3 */
    if((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in == VSSP_EXT_STCTLCMDPTTQPOTCF_COUPLE)
    {
        *VSCtl_tiCfmSupReq_swc_out = (UInt16)DDS_M_MAX((UInt32)VSCtl_tiCfmSupTqMaxReq_swc_in,(UInt32)VSCtl_tiCfmSupTqMinReq_swc_in);
        *VSCtl_tiCfmSdwnReq_swc_out = (UInt16)DDS_M_MAX((UInt32)VSCtl_tiCfmSdwnTqMaxReq_swc_in,(UInt32)VSCtl_tiCfmSdwnTqMinReq_swc_in);
        VSCtl_tiCfmSupIntReq = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSdwnIntReq = (UInt16)(0 * DEC2);
    }
    else if((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in == VSSP_EXT_STCTLCMDPTTQPOTCF_RAPPORT)
    {
        *VSCtl_tiCfmSupReq_swc_out = (UInt16)(0 * DEC2);
        *VSCtl_tiCfmSdwnReq_swc_out = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSupIntReq = (UInt16)DDS_M_MAX((UInt32)VSCtl_tiCfmSupTqMaxReq_swc_in,(UInt32)VSCtl_tiCfmSupTqMinReq_swc_in);
        VSCtl_tiCfmSdwnIntReq = (UInt16)DDS_M_MAX((UInt32)VSCtl_tiCfmSdwnTqMaxReq_swc_in,(UInt32)VSCtl_tiCfmSdwnTqMinReq_swc_in);
    }
    else
    {
        *VSCtl_tiCfmSupReq_swc_out = (UInt16)(0 * DEC2);
        *VSCtl_tiCfmSdwnReq_swc_out = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSupIntReq = (UInt16)(0 * DEC2);
        VSCtl_tiCfmSdwnIntReq = (UInt16)(0 * DEC2);
    }
}

/*******************************************************************************
*
* Function Name : VSSP_F72152_Determiner_Consigne_Potentiel_Couple_Roue_Gmp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_F72152_Determiner_Consigne_Potentiel_Couple_Roue_Gmp(
                                            SInt16 VSCtl_tqWhlPotReq_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMax_swc_in, /* BIN1 */
                                            SInt16 VSCtl_tqWhlPTPotRawMin_swc_in, /* BIN1 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotReq_swc_out /* BIN1 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2274.FR.72.0 */
    SInt32 vssp_sat_out;
    SInt32 vssp_filter_out_1;
    SInt32 vssp_filter_out_2;
    SInt32 vssp_svalue;

    vssp_sat_out = DDS_M_SATURATION_V2((SInt32)VSCtl_tqWhlPotReq_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPotRawMin_swc_in,
                                       (SInt32)VSCtl_tqWhlPTPotRawMax_swc_in);


    if((UInt32)VSCtl_bAcvFil_tqWhlPTPot != (UInt32)DDS_FALSE)
    {
        vssp_filter_out_1 = DDS_M_FILTER_LP1_S16(&vssp_f72152_filter_saturation_str, (SInt16)vssp_sat_out, VSCtl_tiFil_tqWhlPTReq_C, BIN10);
        /* BIN1:[-32000;32000] N.m */
        vssp_svalue = vssp_filter_out_1 - (SInt32)vssp_f72152_filter_saturation_out[3];
        /* BIN1 = BIN1 * DEC3 / DEC3 */
        /* 40ms DEC0 = 0,04 s DEC3 */
        /* DEC3 / 40 = 25 */
        vssp_svalue = vssp_svalue * 25;
        vssp_svalue = DDS_M_FILTER_LP1_S32(&vssp_f72152_dt_filter_str, vssp_svalue, (UInt16)((UInt32)VSCtl_tiFil_dtqWhlPTPotReq_C * BIN5));
        vssp_filter_out_2 = DDS_M_LIMIT(vssp_svalue,
                                        -VSSP_16000_BIN1,
                                        VSSP_16000_BIN1);
    }
    else
    {
        vssp_filter_out_1 = DDS_M_FILTER_LP1_S16_INIT(&vssp_f72152_filter_saturation_str, (SInt16)vssp_sat_out);
        vssp_filter_out_2 = DDS_M_FILTER_LP1_S32_INIT(&vssp_f72152_dt_filter_str, 0);
    }

    if((UInt32)VSCtl_stCtl_tqWhlPTPot == (UInt32)DDS_TRUE)
    {
        *VSCtl_tqWhlPTPotReq_swc_out = (SInt16)DDS_M_LIMIT(vssp_filter_out_1,
                                                           -VSSP_4000_BIN1,
                                                           VSSP_11000_BIN1);
        VSCtl_dtqWhlPTPotReq = (SInt16)vssp_filter_out_2;
    }
    else
    {
        *VSCtl_tqWhlPTPotReq_swc_out = (SInt16)(0 * BIN1);
        VSCtl_dtqWhlPTPotReq = (SInt16)(0 * BIN1);
    }
    vssp_f72152_filter_saturation_out[3] = vssp_f72152_filter_saturation_out[2];
    vssp_f72152_filter_saturation_out[2] = vssp_f72152_filter_saturation_out[1];
    vssp_f72152_filter_saturation_out[1] = vssp_f72152_filter_saturation_out[0];
    vssp_f72152_filter_saturation_out[0] = (SInt16)vssp_filter_out_1;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSSP_Potential_Gmp_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSSP_Potential_Gmp_Sl_Init(CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnReq_swc_out, /* DEC2 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupReq_swc_out, /* DEC2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMaxReq_swc_out, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotMinReq_swc_out, /* BIN1 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPTPotReq_swc_out /* BIN1 */)
{
    /* ---- Init Outputs ---- */
    *VSCtl_tiCfmSdwnReq_swc_out = (UInt16)(0 * DEC2);
    *VSCtl_tiCfmSupReq_swc_out = (UInt16)(0 * DEC2);
    *VSCtl_tqWhlPTPotMaxReq_swc_out = (SInt16)(11000 * BIN1);
    *VSCtl_tqWhlPTPotMinReq_swc_out = (SInt16)(-4000 * BIN1);
    *VSCtl_tqWhlPTPotReq_swc_out = (SInt16)(-4000 * BIN1);

    VSCtl_dtqWhlPTPotReq = (SInt16)(0 * BIN1);
    VSCtl_tiCfmSdwnIntReq = (UInt16)(0 * DEC2);
    VSCtl_tiCfmSupIntReq = (UInt16)(0 * DEC2);
    VSCtl_tqWhlPotMaxIntReq = (SInt16)(16000 * BIN1);
    VSCtl_tqWhlPotMinIntReq = (SInt16)(-16000 * BIN1);

    /* ---- Init Global Datas ---- */

    /* ---- VSSP_F72112_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Min ---- */
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f72112_filter_str, 0);

    /* ---- VSSP_F72122_Determiner_Consigne_Potentiel_Couple_Roue_Gmp_Max ---- */
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f72122_filter_str, 0);

    /* ---- VSSP_F7214_Determiner_Temps_Confirmation_Changement_Rapport ---- */

    /* ---- VSSP_F72152_Determiner_Consigne_Potentiel_Couple_Roue_Gmp ---- */
    DDS_M_FILTER_LP1_S16_INIT(&vssp_f72152_filter_saturation_str, 0);
    DDS_M_FILTER_LP1_S32_INIT(&vssp_f72152_dt_filter_str, 0);
    vssp_f72152_filter_saturation_out[0] = (SInt16)(0 * BIN1);
    vssp_f72152_filter_saturation_out[1] = (SInt16)(0 * BIN1);
    vssp_f72152_filter_saturation_out[2] = (SInt16)(0 * BIN1);
    vssp_f72152_filter_saturation_out[3] = (SInt16)(0 * BIN1);
}



#define VSSP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSSp_MemMap.h"

