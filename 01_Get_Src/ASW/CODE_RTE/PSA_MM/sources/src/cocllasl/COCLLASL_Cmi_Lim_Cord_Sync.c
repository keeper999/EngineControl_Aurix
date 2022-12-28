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
* Ref X:\integration_view_00PSASWC_EA01D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Cmi_Lim_Cord_Sync.c
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 42 m User:meme 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 1/10/2010 12 h 30 m User:morisseau 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L02_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 57 m User:esnault 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 31/8/2010 17 h 43 m User:morisseau 
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 29/7/2010 17 h 34 m User:morisseau
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 22/7/2010 11 h 35 m User:morisseau
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 12 h 10 m User:morisseau
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 40 m User:morisseau
*    TWK_model:COCLLASL_Cmi_Lim_Cord_Sync_L01_010_IMPL1
*    comments :work in progress
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CoClLASl.h"

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

/* NONE */


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

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COCLLASL_START_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEngTqOfsAntiJerkX_A[COCLLASL_12_SIZE] = {
(UInt16)(700 * BIN0), (UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0),
(UInt16)(2000 * BIN0), (UInt16)(2500 * BIN0), (UInt16)(3000 * BIN0),
(UInt16)(3500 * BIN0), (UInt16)(4000 * BIN0), (UInt16)(4500 * BIN0),
(UInt16)(5000 * BIN0), (UInt16)(6000 * BIN0), (UInt16)(7000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqOfsAntiJerkLim_M
[COCLLASL_7_SIZE][COCLLASL_12_SIZE] = {
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) },
{
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4),
(UInt16)(0 * BIN4), (UInt16)(0 * BIN4), (UInt16)(0 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nbGearTqOfsAntiJerkY_A[COCLLASL_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0), (UInt16)(3 * BIN0),
(UInt16)(4 * BIN0), (UInt16)(5 * BIN0), (UInt16)(6 * BIN0)
};

#define COCLLASL_STOP_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqofsantijerklim_m_sav;
#define COCLLASL_STOP_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) EngLim_tqIdcLimDsl; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) EngLim_tqIdcLimGsl; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) EngLim_tqIdcMaxNRegDsl; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) EngLim_tqIdcMaxNRegGsl; /* BIN4 */
#define COCLLASL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COCLLASL_START_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_TQOFSANTIJERKLIM_M_APM = {
&tqsys_tqofsantijerklim_m_sav,
COCLLASL_12_SIZE,
COCLLASL_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngTqOfsAntiJerkX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nbGearTqOfsAntiJerkY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqOfsAntiJerkLim_M[0][0]
};

#define COCLLASL_STOP_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_01_Coord_Essence_Avance(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           SInt16 englim_tqidcengprot_par, /* BIN4 */
                                           SInt16 englim_tqidcpresusthrmax_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_02_Coord_Diesel(
                                           SInt16 englim_tqidcenglim_par, /* BIN4 */
                                           SInt16 tqdem_tqidclimnreg_par, /* BIN4 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt8 copt_nogearcord_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckcurdrivfil_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_03_Coord_Commun(
                                           SInt16 englim_tqidcsyst_par, /* BIN4 */
                                           SInt16 englim_tqidcred_par, /* BIN4 */
                                           SInt16 englim_tqidcsfty_par, /* BIN4 */
                                           UInt8 tqsys_btypfu_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqidcenglimmax_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqidclim_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqidcmaxnreg_ptr /* BIN4 */);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Cmi_Lim_Cord_Sync
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord_Sync(UInt8 CoPt_noGearCord_swc_in,
                                           SInt16 EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcPresUsThrMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSfty_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           SInt16 TqDem_tqIdcLimNReg_swc_in, /* BIN4 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkCurDrivFil_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcEngLimMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcMaxNReg_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2716.FR.3.0 */

    COCLLASL_F03_01_Coord_Essence_Avance(EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                         EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                         EngLim_tqIdcPresUsThrMax_swc_in /* BIN4 */);

    COCLLASL_F03_02_Coord_Diesel(EngLim_tqIdcEngLim_swc_in, /* BIN4 */
                                 TqDem_tqIdcLimNReg_swc_in, /* BIN4 */
                                 Ext_nEng_swc_in, /* BIN0 */
                                 CoPt_noGearCord_swc_in,
                                 EngLim_tqCkCurDrivFil_swc_out /* BIN4 */);

    COCLLASL_F03_03_Coord_Commun(EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                 EngLim_tqIdcSfty_swc_in, /* BIN4 */
                                 TqSys_bTypFu_swc_in,
                                 EngLim_tqIdcEngLimMax_swc_out, /* BIN4 */
                                 EngLim_tqIdcLim_swc_out, /* BIN4 */
                                 EngLim_tqIdcMaxNReg_swc_out /* BIN4 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F03_01_Coord_Essence_Avance
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_01_Coord_Essence_Avance(
                                           SInt16 englim_tqidcengcurmax_par, /* BIN4 */
                                           SInt16 englim_tqidcengprot_par, /* BIN4 */
                                           SInt16 englim_tqidcpresusthrmax_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2716.FR.4.0 */
    EngLim_tqIdcMaxNRegGsl = (SInt16)DDS_M_MIN((SInt32)englim_tqidcpresusthrmax_par,(SInt32)englim_tqidcengprot_par);
    EngLim_tqIdcLimGsl = (SInt16)DDS_M_MIN((SInt32)englim_tqidcengcurmax_par,(SInt32)englim_tqidcengprot_par);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_02_Coord_Diesel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_02_Coord_Diesel(
                                           SInt16 englim_tqidcenglim_par, /* BIN4 */
                                           SInt16 tqdem_tqidclimnreg_par, /* BIN4 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt8 copt_nogearcord_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckcurdrivfil_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2716.FR.5.0 */
    SInt32 cocllasl_f03_02_value;

    EngLim_tqIdcMaxNRegDsl = (SInt16)DDS_M_MIN((SInt32)englim_tqidcenglim_par,(SInt32)tqdem_tqidclimnreg_par);
    EngLim_tqIdcLimDsl = EngLim_tqIdcMaxNRegDsl;

    cocllasl_f03_02_value = (SInt32)DDS_M_MAP3D_U16(&TQSYS_TQOFSANTIJERKLIM_M_APM,ext_neng_par,(UInt16)copt_nogearcord_par);
    *englim_tqckcurdrivfil_ptr = (SInt16)DDS_M_MIN(cocllasl_f03_02_value + (SInt32)EngLim_tqIdcLimDsl,2000*BIN4);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_03_Coord_Commun
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_03_Coord_Commun(
                                           SInt16 englim_tqidcsyst_par, /* BIN4 */
                                           SInt16 englim_tqidcred_par, /* BIN4 */
                                           SInt16 englim_tqidcsfty_par, /* BIN4 */
                                           UInt8 tqsys_btypfu_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqidcenglimmax_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqidclim_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqidcmaxnreg_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2716.FR.6.0 */
    SInt32 cocllasl_f03_03_value;

    cocllasl_f03_03_value = DDS_M_MIN((SInt32)englim_tqidcred_par,(SInt32)englim_tqidcsfty_par);
    cocllasl_f03_03_value = DDS_M_MIN(cocllasl_f03_03_value,(SInt32)englim_tqidcsyst_par);

    if((UInt32)tqsys_btypfu_par != (UInt32)DDS_FALSE)
    {
        *englim_tqidcmaxnreg_ptr = (SInt16)DDS_M_MIN((SInt32)EngLim_tqIdcMaxNRegGsl,cocllasl_f03_03_value);
        *englim_tqidclim_ptr  = (SInt16)DDS_M_MIN((SInt32)englim_tqidcsyst_par,(SInt32)EngLim_tqIdcLimGsl);
    }
    else
    {
        *englim_tqidcmaxnreg_ptr = (SInt16)DDS_M_MIN((SInt32)EngLim_tqIdcMaxNRegDsl,cocllasl_f03_03_value);
        *englim_tqidclim_ptr  = (SInt16)DDS_M_MIN((SInt32)englim_tqidcsyst_par,(SInt32)EngLim_tqIdcLimDsl);
    }


    cocllasl_f03_03_value = DDS_M_MIN((SInt32)englim_tqidcred_par,(SInt32)englim_tqidcsfty_par);
    *englim_tqidcenglimmax_ptr = (SInt16)DDS_M_MIN((SInt32)*englim_tqidclim_ptr,cocllasl_f03_03_value);
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Cmi_Lim_Cord_Sync_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Cmi_Lim_Cord_Sync_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkCurDrivFil_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcEngLimMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqIdcMaxNReg_swc_out /* BIN4 */)
{
    *EngLim_tqCkCurDrivFil_swc_out = (SInt16)(2000 * BIN4);
    *EngLim_tqIdcEngLimMax_swc_out = (SInt16)(2000 * BIN4);
    *EngLim_tqIdcLim_swc_out = (SInt16)(2000 * BIN4);
    *EngLim_tqIdcMaxNReg_swc_out = (SInt16)(2000 * BIN4);

    EngLim_tqIdcLimDsl = (SInt16)(2000 * BIN4);
	EngLim_tqIdcLimGsl = (SInt16)(2000 * BIN4);
	EngLim_tqIdcMaxNRegDsl = (SInt16)(2000 * BIN4);
	EngLim_tqIdcMaxNRegGsl = (SInt16)(2000 * BIN4);

}



#define COCLLASL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoClLASl_MemMap.h"
