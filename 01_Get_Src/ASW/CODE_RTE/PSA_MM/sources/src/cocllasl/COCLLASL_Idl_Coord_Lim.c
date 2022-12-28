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
* Ref X:\integration_view_00PSASWC_EA01D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Idl_Coord_Lim.c
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 42 m User:meme 
*    TWK_model:COCLLASL_Idl_Coord_Lim_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\7 Date: 1/10/2010 12 h 31 m User:morisseau 
*    TWK_model:COCLLASL_Idl_Coord_Lim_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 15/9/2010 12 h 29 m User:morisseau 
*    TWK_model:COCLLASL_Idl_Coord_Lim_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 15/9/2010 12 h 26 m User:morisseau 
*    TWK_model:COCLLASL_Idl_Coord_Lim_L01_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 57 m User:esnault
*    TWK_model:COCLLASL_Idl_Coord_Lim_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 31/8/2010 17 h 43 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 29/7/2010 17 h 34 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 12 h 28 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 40 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_L01_010_IMPL1
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

/* NONE */


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

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

#define COCLLASL_START_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqidcairengidlcord_loc;
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqidcairenglimcord_loc;
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqidcairlimcordwires_loc;
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqidcairlimcordwoutres_loc;
#define COCLLASL_STOP_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"



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

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) COCLLASL_F05_Ess_CoordAir(
                                           SInt16 copt_tqidcaircord_ncross_par, /* BIN4 */
                                           SInt16 englim_tqidcairlim_par, /* BIN4 */
                                           SInt16 englim_tqidcairlimafterres_par, /* BIN4 */
                                           SInt16 englim_tqidcred_par, /* BIN4 */
                                           SInt16 idlsys_tqidcairidl_par, /* BIN4 */
                                           SInt16 tqres_tqmaxres_par, /* BIN4 */
                                           SInt16 idlsys_tqidcidlairsbpa_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairengidlcord_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairenglimcord_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairlimcordwires_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairlimcordwoutres_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F06_Diesel_CoordAir(
                                           SInt16 tqsys_tqckidlcord_par, /* BIN4 */
                                           SInt16 copt_tqidcairdslcord_nreg_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairrequnlim_ptr /* BIN0 */);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Idl_Coord_Lim
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim(SInt16 CoPt_tqIdcAirCord_nCross_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqIdcAirDslCord_nReg_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcAirLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcAirLimAfterRes_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           SInt16 IdlSys_tqIdcAirIdl_swc_in, /* BIN4 */
                                           SInt16 TqRes_tqMaxRes_swc_in, /* BIN4 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           SInt16 TqSys_tqCkIdlCord_swc_in, /* BIN4 */
                                           SInt16 IdlSys_tqIdcIdlAirSBPA_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWiRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWoutRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirReqUnlim_swc_out /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.2.3 */
    if((UInt32)TqSys_bTypFu_swc_in != (UInt32)DDS_FALSE)
    {
        COCLLASL_F05_Ess_CoordAir(CoPt_tqIdcAirCord_nCross_swc_in, /* BIN4 */
                                  EngLim_tqIdcAirLim_swc_in, /* BIN4 */
                                  EngLim_tqIdcAirLimAfterRes_swc_in, /* BIN4 */
                                  EngLim_tqIdcRed_swc_in, /* BIN4 */
                                  IdlSys_tqIdcAirIdl_swc_in, /* BIN4 */
                                  TqRes_tqMaxRes_swc_in, /* BIN4 */
                                  IdlSys_tqIdcIdlAirSBPA_swc_in, /* BIN4 */
                                  &tqsys_tqidcairengidlcord_loc, /* BIN4 */
                                  &tqsys_tqidcairenglimcord_loc, /* BIN4 */
                                  &tqsys_tqidcairlimcordwires_loc, /* BIN4 */
                                  &tqsys_tqidcairlimcordwoutres_loc /* BIN4 */);
    }
    else
    {
        /* Nothing to do */
    }

    *TqSys_tqIdcAirEngIdlCord_swc_out = tqsys_tqidcairengidlcord_loc;
    *TqSys_tqIdcAirEngLimCord_swc_out = tqsys_tqidcairenglimcord_loc;
    *TqSys_tqIdcAirLimCordWiRes_swc_out = tqsys_tqidcairlimcordwires_loc;
    *TqSys_tqIdcAirLimCordWoutRes_swc_out = tqsys_tqidcairlimcordwoutres_loc;


    COCLLASL_F06_Diesel_CoordAir(TqSys_tqCkIdlCord_swc_in, /* BIN4 */
                                 CoPt_tqIdcAirDslCord_nReg_swc_in, /* BIN4 */
                                 TqSys_tqIdcAirReqUnlim_swc_out /* BIN0 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F05_Ess_CoordAir
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F05_Ess_CoordAir(
                                           SInt16 copt_tqidcaircord_ncross_par, /* BIN4 */
                                           SInt16 englim_tqidcairlim_par, /* BIN4 */
                                           SInt16 englim_tqidcairlimafterres_par, /* BIN4 */
                                           SInt16 englim_tqidcred_par, /* BIN4 */
                                           SInt16 idlsys_tqidcairidl_par, /* BIN4 */
                                           SInt16 tqres_tqmaxres_par, /* BIN4 */
                                           SInt16 idlsys_tqidcidlairsbpa_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairengidlcord_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairenglimcord_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairlimcordwires_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairlimcordwoutres_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.9.0 */
    SInt32 cocllasl_f05_value;

    *tqsys_tqidcairengidlcord_ptr = (SInt16)DDS_M_LIMIT_V2((SInt32)englim_tqidcred_par,
                                                            (SInt32)idlsys_tqidcairidl_par,
                                                            (SInt32)copt_tqidcaircord_ncross_par);

   *tqsys_tqidcairlimcordwoutres_ptr = (SInt16)DDS_M_MIN((SInt32)(*tqsys_tqidcairengidlcord_ptr),(SInt32)englim_tqidcairlim_par);

    cocllasl_f05_value =   ((SInt32)*tqsys_tqidcairlimcordwoutres_ptr
                         + (SInt32)tqres_tqmaxres_par)
                         + (SInt32)idlsys_tqidcidlairsbpa_par;

    *tqsys_tqidcairlimcordwires_ptr = (SInt16)DDS_M_LIMIT(cocllasl_f05_value,-2000*BIN4,2000*BIN4);

    *tqsys_tqidcairenglimcord_ptr = (SInt16)DDS_M_MIN((SInt32)*tqsys_tqidcairlimcordwires_ptr,(SInt32)englim_tqidcairlimafterres_par);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F06_Diesel_CoordAir
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F06_Diesel_CoordAir(
                                           SInt16 tqsys_tqckidlcord_par, /* BIN4 */
                                           SInt16 copt_tqidcairdslcord_nreg_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairrequnlim_ptr /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.10.0 */
    *tqsys_tqidcairrequnlim_ptr = (SInt16)DDS_M_MAX((SInt32)tqsys_tqckidlcord_par,(SInt32)copt_tqidcairdslcord_nreg_par);
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Idl_Coord_Lim_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWiRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLimCordWoutRes_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirReqUnlim_swc_out /* BIN0 */)
{
    *TqSys_tqIdcAirEngIdlCord_swc_out = 0;
    *TqSys_tqIdcAirEngLimCord_swc_out = 0;
    *TqSys_tqIdcAirLimCordWiRes_swc_out = 0;
    *TqSys_tqIdcAirLimCordWoutRes_swc_out = 0;
    *TqSys_tqIdcAirReqUnlim_swc_out = 0;
    tqsys_tqidcairengidlcord_loc = 0;
    tqsys_tqidcairenglimcord_loc = 0;
    tqsys_tqidcairlimcordwires_loc = 0;
    tqsys_tqidcairlimcordwoutres_loc = 0;
}



#define COCLLASL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoClLASl_MemMap.h"
