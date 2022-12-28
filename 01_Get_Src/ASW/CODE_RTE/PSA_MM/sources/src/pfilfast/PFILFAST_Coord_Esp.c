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
* Ref X:\integration_view_00PSASWC_E611D01\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Coord_Esp.c
* Version int :/main/L03_01/2 Date: 16/5/2011 15 h 7 m User:esnault 
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1_D
*    comments :to reduce CPU load
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 29/4/2011 9 h 40 m User:demezil 
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1_D
*    comments :to reduce CPU load
* Version int :/main/L03_01/1 Date: 12/8/2010 12 h 40 m User:esnault
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 13/7/2010 12 h 20 m User:demezil
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 30/6/2010 17 h 12 m User:demezil
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 21/6/2010 12 h 49 m User:demezil
*    TWK_model:PFILFAST_Coord_Esp_L03_010_IMPL1
*    comments :for PFilFAST e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 18/6/2010 9 h 47 m User:demezil
*    TWK_model:PFILFAST_Coord_Esp_L02_010_IMPL1_D
*    comments :QAC and codeshaker e6 pass
* Version int :/main/L02_01/1 Date: 24/9/2009 10 h 33 m User:langendorf
*    TWK_model:PFILFAST_Coord_Esp_L02_010_IMPL1
*    comments :wrong calculation of CoCha_stTqReqMSR and CoCha_stTqReqASR
* Version dev :\main\branch_salmane_pfilfast\2 Date: 22/9/2009 12 h 55 m User:salmane
*    TWK_model:PFILFAST_Coord_Esp_L02_010_IMPL1
*    comments :wrong calculation of CoCha_stTqReqMSR and CoCha_stTqReqASR
* Version dev :\main\branch_salmane_pfilfast\1 Date: 1/9/2009 17 h 30 m User:salmane
*    TWK_model:PFILFAST_Coord_Esp_L02_010_IMPL1
*    comments :For PFilFast 2.0 / 06E61000_DELIV_1
* Version int :/main/L01_01/1 Date: 24/10/2008 9 h 30 m User:langendorf
*    TWK_model:PFILFAST_Coord_Esp_L01_010_IMPL1
*    comments :CoCha_bInhEGR instead of CoPt_bInhEGR
* Version dev :\main\branch_salmane_pfilfast\3 Date: 21/10/2008 11 h 11 m User:salmane
*    TWK_model:PFILFAST_Coord_Esp_L01_010_IMPL1
*    comments :CoCha_bInhEGR instead of CoPt_bInhEGR
* Version dev :\main\branch_salmane_pfilfast\1 Date: 29/9/2008 11 h 34 m User:salmane
*    TWK_model:PFILFAST_Coord_Esp_L01_010_IMPL1
*    comments :For PFILFAST coding
* Version dev :\main\branch_miaille\1 Date: 24/9/2008 14 h 11 m User:miaille
*    TWK_model:PFILFAST_Coord_Esp_L01_010_IMPL1
*    comments :Implements CSMT_CGMT06_2027_v2id0 specification.
* Version int :\main\1 Date: 12/9/2008 9 h 9 m User:boucher
*    TWK_model:NO_MODEL
*    comments :new file creation
*
*******************************************************************************/


/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/
#include "PFilFast.h"
/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define ASR             (UInt32)5
#define MSR             (UInt32)6

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

/* NONE */


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoCha_tqMax_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoCha_tqMin_MP; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_01_traiter_donnees(SInt16 tqsys_tqckefcfil_par, /* BIN4 */
                                                                UInt8 cha_sttqreq_par, /* BIN0 */
                                                                SInt16 englim_tqckefcchalim_par, /* BIN4 */
                                                                SInt16 englim_tqefcmaxdynvehspdctl_par, /* BIN4 */
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqreqasr_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqreqmsr_ptr,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) cocha_tqefclim_ptr, /* BIN4 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) cocha_tqefclimtqmaxdyn_ptr); /* BIN4 */

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_02_determiner_couple_a_transmettre(SInt16 tqsys_tqckefcfil_par, /* BIN4 */
                                                                            SInt16 cha_tqdynasrreq_par, /* BIN4 */
                                                                            SInt16 cha_tqmsrreq_par, /* BIN4 */
                                                                            SInt16 copt_tqefcmaxprotdftl_par, /* BIN4 */
                                                                            UInt8 cocha_btqreqasr_par,
                                                                            UInt8 cocha_btqreqmsr_par,
                                                                            UInt8 frm_binhespreq_par,
                                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) cocha_tqefcreq_ptr, /* BIN4 */
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_brstaos_ptr,
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_binhegr_ptr,
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqaccureq_ptr,
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqdynreq_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/
/*******************************************************************************
*
* Function Name : PFILFAST_Coord_Esp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Coord_Esp(UInt8 Cha_stTqReq_swc_in, /* BIN0 */
                                               SInt16 Cha_tqDynASRReq_swc_in, /* BIN4 */
                                               SInt16 Cha_tqMSRReq_swc_in, /* BIN4 */
                                               SInt16 EngLim_tqCkEfcChaLim_swc_in, /* BIN4 */
                                               SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                               SInt16 CoPt_tqEfcMaxProtDftl_swc_in, /* BIN4 */
                                               SInt16 EngLim_tqEfcMaxDynVehSpdCtl_swc_in, /* BIN4 */
                                               UInt8 FRM_bInhESPReq_swc_in,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcReq_swc_out, /* BIN4 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGR_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqAccuReq_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqDynReq_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqASR_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqMSR_swc_out,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLim_swc_out, /* BIN4 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bRstAOS_swc_out,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLimTqMaxDyn_swc_out /* BIN4 */)
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2027.FR.1 */
    PFILFAST_F01_01_traiter_donnees(TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                    Cha_stTqReq_swc_in, /* BIN0 */
                                    EngLim_tqCkEfcChaLim_swc_in, /* BIN4 */
                                    EngLim_tqEfcMaxDynVehSpdCtl_swc_in, /* BIN4 */
                                    CoCha_bTqReqASR_swc_out,
                                    CoCha_bTqReqMSR_swc_out,
                                    CoCha_tqEfcLim_swc_out, /* BIN4 */
                                    CoCha_tqEfcLimTqMaxDyn_swc_out); /* BIN4 */

    PFILFAST_F01_02_determiner_couple_a_transmettre(TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                                    Cha_tqDynASRReq_swc_in, /* BIN4 */
                                                    Cha_tqMSRReq_swc_in, /* BIN4 */
                                                    CoPt_tqEfcMaxProtDftl_swc_in, /* BIN4 */
                                                    *CoCha_bTqReqASR_swc_out,
                                                    *CoCha_bTqReqMSR_swc_out,
                                                    FRM_bInhESPReq_swc_in,
                                                    CoCha_tqEfcReq_swc_out, /* BIN4 */
                                                    CoCha_bRstAOS_swc_out,
                                                    CoCha_bInhEGR_swc_out,
                                                    CoCha_bTqAccuReq_swc_out,
                                                    CoCha_bTqDynReq_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : f01_01_traiter_donnees
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_01_traiter_donnees(SInt16 tqsys_tqckefcfil_par, /* BIN4 */
                                                                UInt8 cha_sttqreq_par, /* BIN0 */
                                                                SInt16 englim_tqckefcchalim_par, /* BIN4 */
                                                                SInt16 englim_tqefcmaxdynvehspdctl_par, /* BIN4 */
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqreqasr_ptr,
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqreqmsr_ptr,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) cocha_tqefclim_ptr, /* BIN4 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) cocha_tqefclimtqmaxdyn_ptr) /* BIN4 */
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2027.FR.2 */
    *cocha_tqefclim_ptr = (SInt16)DDS_M_MIN((SInt32)englim_tqckefcchalim_par, (SInt32)tqsys_tqckefcfil_par);
    *cocha_tqefclimtqmaxdyn_ptr = (SInt16)DDS_M_MIN((SInt32)tqsys_tqckefcfil_par, (SInt32)englim_tqefcmaxdynvehspdctl_par);

    if (ASR == (UInt32)cha_sttqreq_par)
    {
        *cocha_btqreqasr_ptr = DDS_TRUE;
        *cocha_btqreqmsr_ptr = DDS_FALSE;
    }
    else
    {
        if(MSR == (UInt32)cha_sttqreq_par)
        {
            *cocha_btqreqasr_ptr = DDS_FALSE;
            *cocha_btqreqmsr_ptr = DDS_TRUE;
        }
        else
        {
            *cocha_btqreqasr_ptr = DDS_FALSE;
            *cocha_btqreqmsr_ptr = DDS_FALSE;
        }
    }
}
/*******************************************************************************
*
* Function Name : f01_02_determiner_couple_a_transmettre
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_02_determiner_couple_a_transmettre(SInt16 tqsys_tqckefcfil_par, /* BIN4 */
                                                                            SInt16 cha_tqdynasrreq_par, /* BIN4 */
                                                                            SInt16 cha_tqmsrreq_par, /* BIN4 */
                                                                            SInt16 copt_tqefcmaxprotdftl_par, /* BIN4 */
                                                                            UInt8 cocha_btqreqasr_par,
                                                                            UInt8 cocha_btqreqmsr_par,
                                                                            UInt8 frm_binhespreq_par,
                                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) cocha_tqefcreq_ptr, /* BIN4 */
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_brstaos_ptr,
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_binhegr_ptr,
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqaccureq_ptr,
                                                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) cocha_btqdynreq_ptr)
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2027.FR.3 */
    SInt32 temp_s32;

    if((UInt32)DDS_FALSE != (UInt32)frm_binhespreq_par)
    {
        *cocha_tqefcreq_ptr = (SInt16)DDS_M_MIN((SInt32)tqsys_tqckefcfil_par, (SInt32)copt_tqefcmaxprotdftl_par);
        *cocha_brstaos_ptr = DDS_FALSE;
        *cocha_btqaccureq_ptr = DDS_FALSE;
        *cocha_btqdynreq_ptr = DDS_FALSE;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)cocha_btqreqmsr_par)
        {
            CoCha_tqMax_MP = (SInt16)DDS_M_LIMIT_V2((SInt32)copt_tqefcmaxprotdftl_par,
                                                    (SInt32)cha_tqmsrreq_par,
                                                    (SInt32)tqsys_tqckefcfil_par);
            temp_s32 = (SInt32)CoCha_tqMax_MP;
        }
        else
        {
            temp_s32 = DDS_M_MIN((SInt32)tqsys_tqckefcfil_par, (SInt32)copt_tqefcmaxprotdftl_par);
        }

        if((UInt32)DDS_FALSE != (UInt32)cocha_btqreqasr_par)
        {
            CoCha_tqMin_MP = (SInt16)DDS_M_MIN(temp_s32, (SInt32)cha_tqdynasrreq_par);
            *cocha_tqefcreq_ptr = CoCha_tqMin_MP;
        }
        else
        {
            *cocha_tqefcreq_ptr = (SInt16)temp_s32;
        }

        *cocha_btqaccureq_ptr = cocha_btqreqmsr_par;
        *cocha_btqdynreq_ptr = cocha_btqreqasr_par;
        if(((UInt32)DDS_FALSE != (UInt32)cocha_btqreqasr_par) ||
            ((UInt32)DDS_FALSE != (UInt32)cocha_btqreqmsr_par))
        {
            *cocha_brstaos_ptr = DDS_TRUE;
        }
        else
        {
            *cocha_brstaos_ptr = DDS_FALSE;
        }

    }
    *cocha_binhegr_ptr = *cocha_brstaos_ptr;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Coord_Esp_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Coord_Esp_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcReq_swc_out, /* BIN4 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGR_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqAccuReq_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqDynReq_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqASR_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bTqReqMSR_swc_out,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLim_swc_out, /* BIN4 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bRstAOS_swc_out,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcLimTqMaxDyn_swc_out /* BIN4 */)
{
    *CoCha_tqEfcReq_swc_out = (SInt16)(0 * BIN4);
    *CoCha_bInhEGR_swc_out = DDS_FALSE;
    *CoCha_bTqAccuReq_swc_out = DDS_FALSE;
    *CoCha_bTqDynReq_swc_out = DDS_FALSE;
    *CoCha_bTqReqASR_swc_out = DDS_FALSE;
    *CoCha_bTqReqMSR_swc_out = DDS_FALSE;
    *CoCha_tqEfcLim_swc_out = (SInt16)(0 * BIN4);
    *CoCha_bRstAOS_swc_out = DDS_FALSE;
    *CoCha_tqEfcLimTqMaxDyn_swc_out = (SInt16)(0 * BIN4);
}



#define PFILFAST_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "PFilFast_MemMap.h"

