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
* Ref X:\integration_view_00PSASWC_E310D01\blois_psa_sstg\Software\Appli\PFilSlow\src\PFilSlow.c
* Version int :/main/00PSASWC_E3/3 Date: 24/1/2011 15 h 33 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :just for QAC
* Version dev :\main\branch_lemort_pfilslow_dev\3 Date: 24/1/2011 12 h 48 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :just for QAC
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 24/1/2011 12 h 46 m User:lemort
*    TWK_model:NO_MODEL
*    comments :add convertion for cocha_bacvcllit_swc_out
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 24/1/2011 12 h 8 m User:lemort
*    TWK_model:NO_MODEL
*    comments :for PFilSlow 11.0
* Version int :/main/00PSASWC_E3/2 Date: 23/7/2010 16 h 5 m User:esnault
*    TWK_model:NO_MODEL
*    comments :change runnable names
*    comments :change runnable names
* Version dev :\main\branch_lemort_pfilslow_dev\4 Date: 23/7/2010 15 h 37 m User:lemort
*    TWK_model:NO_MODEL
*    comments :change runnable names
* Version dev :\main\branch_lemort_pfilslow_dev\3 Date: 23/7/2010 12 h 24 m User:lemort
*    TWK_model:NO_MODEL
*    comments :delete bypass in init
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 23/7/2010 10 h 41 m User:lemort
*    TWK_model:NO_MODEL
*    comments :for PFilSlow e6 10.0
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 1/7/2010 12 h 41 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev in progress
* Version int :/main/P2868/BR_06E3/4 Date: 7/9/2009 9 h 58 m User:langendorf
*    TWK_model:LDCR_Application_06E310_IMPL1
*    comments :change bypass extansions
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 3/9/2009 17 h 42 m User:lemort
*    TWK_model:LDCR_Application_06E310_IMPL1
*    comments :change bypass extansions
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 7/8/2009 14 h 19 m User:lemort
*    TWK_model:LDCR_Application_06E310_IMPL1
*    comments :for dev PFilSlow 2.0
* Version int :/main/P2868/BR_06E3/3 Date: 19/11/2008 9 h 38 m User:boucher
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Runnables need to be cut
* Version dev :\main\branch_moisan_pfilslow\3 Date: 22/10/2008 10 h 29 m User:moisan
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Runnables need to be cut
* Version dev :\main\branch_moisan_pfilslow\2 Date: 22/10/2008 9 h 30 m User:moisan
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Change in name of runnables
* Version int :/main/P2868/BR_06E3/2 Date: 26/9/2008 9 h 11 m User:boucher
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Correction: missed Bypass
* Version dev :\main\branch_moisan_pfilslow\1 Date: 4/9/2008 17 h 3 m User:moisan
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Correction: missed Bypass
* Version int :/main/P2868/BR_06E3/1 Date: 2/9/2008 15 h 29 m User:boucher
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Implement call to task and bypass requirement (R6515141 1.0)
* Version dev :\main\branch_girodon_pfilslow_1_dev\1 Date: 2/9/2008 10 h 2 m User:girodon
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :Implement call to task and bypass requirement (R6515141 1.0)
*
*******************************************************************************/



/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "PFilSlow.h"


/*******************************************************************************
*  Check Library Version
*******************************************************************************/

#if PFILSLOW_DDS_LIB_VERSION_REQ > DDS_LIB_VERSION
dds_lib.* version is not compatible with current SWC version
#endif

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Level Type Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Scalar Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Map Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define PFILSLOW_START_SEC_CALIB_16BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) CoCha_tqEfcAirReq_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);/* BIN4 */
STATIC volatile CONST(UInt16, AUTOMATIC) CoCha_tiTranCllIt_B = (CONST(UInt16, AUTOMATIC))(0 * DEC2);  /* DEC2 */
STATIC volatile CONST(SInt16, AUTOMATIC) CoCha_tqIncCllIt_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);   /* BIN4 */
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkEfcAirFil_B = (CONST(SInt16, AUTOMATIC))(0 * BIN4);/* BIN4 */
#define PFILSLOW_STOP_SEC_CALIB_16BIT
#include "PFilSlow_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILSLOW_START_SEC_CALIB_8BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) PFILSLOW_ACTIVE_BYP_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bAcvCllIt_B = DDS_FALSE;
#define PFILSLOW_STOP_SEC_CALIB_8BIT
#include "PFilSlow_MemMap.h"


/*******************************************************************************
*  File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Displayable Variable Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
*  File Scope Constant Definitions
*******************************************************************************/


#define PFILSLOW_START_SEC_CONST_VERSION_MODULE_8BIT
#include "PFilSlow_MemMap.h"
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) PFilSlow_ModuleVersion_Major_MP = (UInt8)11;
/* <PRQA_COMMENT><3211> This constant has to be declared as if it is not used </3211></PRQA_COMMENT> */
_DDS_STATIC_ CONST(UInt8, AUTOMATIC) PFilSlow_ModuleVersion_Minor_MP = (UInt8)0;
#define PFILSLOW_STOP_SEC_CONST_VERSION_MODULE_8BIT
#include "PFilSlow_MemMap.h"


/*******************************************************************************
*  File Local Function Prototypes
*******************************************************************************/

/* NONE */


/*******************************************************************************
*  Runnables Definition
*******************************************************************************/
#define PFILSLOW_START_SEC_CODE
#include "PFilSlow_MemMap.h"

/*******************************************************************************
*
*  Runnable Name    :   RE_TqSys_Sdl10ms_EfcAirFil
*  Event            :
*  Description      :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_EfcAirFil(void)
{
	/* INPUT */
	/* SWC IN */
	UInt16 tqsys_nengdeceini_swc_in;
	UInt16 covsctl_raccpeng_swc_in;
	UInt16 eng_nckfil_swc_in;
	SInt16 tqlimem_tqlimem_swc_in;
	SInt16 tqsys_ndif_nengntrb_swc_in;
	UInt8 tqsys_nogearcorddrivfil_swc_in;
	UInt8 tqsys_nogeardece_swc_in;
	UInt8 tqsys_stdrivfilcfpha_swc_in;
	SInt16 tqsys_tqckdeceiniit_swc_in;
	SInt16 tqsys_tqckefcfil_swc_in;
	SInt16 tqsys_tqthdpha3it_swc_in;

	/* OUTPUT */
	/* SWC OUT */
	SInt16 tqsys_tqckefcairfil_swc_out;

    /* SSTG_REQ_TAG: Req_PFilSlowBypass_1.0 */
    if ((UInt32)DDS_TRUE != (UInt32)PFILSLOW_ACTIVE_BYP_C)
    {
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I111(0) */
		Rte_Read_R_TqSys_nEngDeceIni_TqSys_nEngDeceIni(&tqsys_nengdeceini_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I112(0) */
		Rte_Read_R_CoVSCtl_rAccPEng_CoVSCtl_rAccPEng(&covsctl_raccpeng_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I113(0) */
		Rte_Read_R_Eng_nCkFil_Eng_nCkFil(&eng_nckfil_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I114(0) */
		Rte_Read_R_TqLimEM_tqLimEM_TqLimEM_tqLimEM(&tqlimem_tqlimem_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I115(0) */
		Rte_Read_R_TqSys_nDif_nEngNTrb_TqSys_nDif_nEngNTrb(&tqsys_ndif_nengntrb_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I116(0) */
		Rte_Read_R_TqSys_noGearCordDrivFil_TqSys_noGearCordDrivFil(&tqsys_nogearcorddrivfil_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I117(0) */
		Rte_Read_R_TqSys_noGearDece_TqSys_noGearDece(&tqsys_nogeardece_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I119(0) */
		Rte_Read_R_TqSys_stDrivFilCfPha_TqSys_stDrivFilCfPha(&tqsys_stdrivfilcfpha_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I120(0) */
		Rte_Read_R_TqSys_tqCkDeceIniIt_TqSys_tqCkDeceIniIt(&tqsys_tqckdeceiniit_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I121(0) */
		Rte_Read_R_TqSys_tqCkEfcFil_TqSys_tqCkEfcFil(&tqsys_tqckefcfil_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I122(0) */
		Rte_Read_R_TqSys_tqThdPha3It_TqSys_tqThdPha3It(&tqsys_tqthdpha3it_swc_in);


        /* CALL TASKS */
        /* Call order is determined by "CSMT_CGMT08_0941_1.0" specification */

        /* Agrement Preventif Branche air */
        PFILSLOW_Prev_Agr_Slow(covsctl_raccpeng_swc_in, /* BIN7 */
                               eng_nckfil_swc_in, /* BIN2 */
                               tqlimem_tqlimem_swc_in, /* BIN4 */
                               tqsys_ndif_nengntrb_swc_in, /* BIN2 */
                               tqsys_nengdeceini_swc_in, /* BIN2 */
                               tqsys_nogeardece_swc_in, /* BIN0 */
                               tqsys_nogearcorddrivfil_swc_in, /* BIN0 */
                               tqsys_stdrivfilcfpha_swc_in, /* BIN0 */
                               tqsys_tqckdeceiniit_swc_in, /* BIN4 */
                               tqsys_tqckefcfil_swc_in, /* BIN4 */
                               tqsys_tqthdpha3it_swc_in, /* BIN4 */
                               &tqsys_tqckefcairfil_swc_out /* BIN4 */);

    }
    else
    {
        /* Set swc out variables with bypass calibration */
        tqsys_tqckefcairfil_swc_out = TqSys_tqCkEfcAirFil_B;
    }

	/* OUTPUT */
	/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I110(0) */
	Rte_Write_P_TqSys_tqCkEfcAirFil_TqSys_tqCkEfcAirFil(tqsys_tqckefcairfil_swc_out);
}

/*******************************************************************************
*
*  Runnable Name    :   RE_TqSys_Sdl10ms_CoChaTqSlow
*  Event            :
*  Description      :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) RE_TqSys_Sdl10ms_CoChaTqSlow(void)
{
	/* INPUT */
	/* SWC IN */
	Boolean cocha_btqreqasr_swc_in;
	Boolean cocha_btqreqmsr_swc_in;
	SInt16 tqcha_tqairtqdecreq_swc_in;
	SInt16 tqcha_tqairtqincreq_swc_in;
	SInt16 tqsys_tqckefcairfil_swc_in;
	UInt8 copt_stprot_swc_in;
	SInt16 copt_tqefcmaxprotdftl_swc_in;
	/* FIM (FRM) */
	Boolean frm_binhespreq_fim_in;

	/* OUTPUT */
	/* SWC OUT */
	SInt16 cocha_tqefcairreq_swc_out;
	UInt8 cocha_bacvcllit_swc_out;
	UInt16 cocha_titrancllit_swc_out;
	SInt16 cocha_tqinccllit_swc_out;

	Boolean pfilslow_bool_temp;

    /* SSTG_REQ_TAG: Req_PFilSlowBypass_1.0 */
    if ((UInt32)DDS_TRUE != (UInt32)PFILSLOW_ACTIVE_BYP_C)
    {
        /* Get data from RTE */

		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I104(0) */
		Rte_Read_R_CoCha_bTqReqASR_CoCha_bTqReqASR(&cocha_btqreqasr_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I105(0) */
		Rte_Read_R_CoCha_bTqReqMSR_CoCha_bTqReqMSR(&cocha_btqreqmsr_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I106(0) */
		Rte_Read_R_TqCha_tqAirTqDecReq_TqCha_tqAirTqDecReq(&tqcha_tqairtqdecreq_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I107(0) */
		Rte_Read_R_TqCha_tqAirTqIncReq_TqCha_tqAirTqIncReq(&tqcha_tqairtqincreq_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I109(0) */
		Rte_Read_R_TqSys_tqCkEfcAirFil_TqSys_tqCkEfcAirFil(&tqsys_tqckefcairfil_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I123(0) */
		Rte_Read_R_CoPt_stProt_CoPt_stProt(&copt_stprot_swc_in);
		/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I124(0) */
		Rte_Read_R_CoPt_tqEfcMaxProtDftl_CoPt_tqEfcMaxProtDftl(&copt_tqefcmaxprotdftl_swc_in);

		/* SSTG_REQ_TAG: TAG17 */
		Rte_Call_R_FRM_bInhESPReq_GetFunctionPermission(&pfilslow_bool_temp);
		frm_binhespreq_fim_in = ((UInt32)pfilslow_bool_temp == (UInt32)DDS_FALSE);


        /* Coordonner les consignes de couple lent ESP */
        /* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
        PFILSLOW_Coord_Slow_Esp((UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(cocha_btqreqasr_swc_in),
		/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                             	  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(cocha_btqreqmsr_swc_in),
								  copt_stprot_swc_in, /* bin0 */
								  copt_tqefcmaxprotdftl_swc_in, /* bin4 */
		/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
                             	  (UInt8)DDS_M_CONVERT_BOOL_TO_UINT8(frm_binhespreq_fim_in),
								  tqcha_tqairtqdecreq_swc_in, /* bin4 */
								  tqcha_tqairtqincreq_swc_in, /* bin4 */
								  tqsys_tqckefcairfil_swc_in, /* bin4 */
								  &cocha_bacvcllit_swc_out,
								  &cocha_titrancllit_swc_out, /* dec2 */
								  &cocha_tqefcairreq_swc_out, /* bin4 */
								  &cocha_tqinccllit_swc_out /* bin4 */);

    }
    else
    {
        /* Set swc out variables with bypass calibration */
		cocha_tqefcairreq_swc_out = CoCha_tqEfcAirReq_B;
		cocha_bacvcllit_swc_out = CoCha_bAcvCllIt_B;
		cocha_titrancllit_swc_out = CoCha_tiTranCllIt_B;
		cocha_tqinccllit_swc_out = CoCha_tqIncCllIt_B;

    }
	/* OUTPUT */
	/* SSTG_REQ_TAG: TAG18 */
	Rte_Write_P_CoCha_tqEfcAirReq_CoCha_tqEfcAirReq(cocha_tqefcairreq_swc_out);
	/* SSTG_REQ_TAG: TAG19 */
	/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
	Rte_Write_P_CoCha_bAcvCllIt_CoCha_bAcvCllIt(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_bacvcllit_swc_out));
	/* SSTG_REQ_TAG: TAG20 */
	Rte_Write_P_CoCha_tiTranCllIt_CoCha_tiTranCllIt(cocha_titrancllit_swc_out);
	/* SSTG_REQ_TAG: TAG21 */
	Rte_Write_P_CoCha_tqIncCllIt_CoCha_tqIncCllIt(cocha_tqinccllit_swc_out);
}

/*******************************************************************************
*
*  Runnable Name    :   RE_PFilSlow_008_MSE
*  Event            :   On ECU Power
*  Description      :   Call Initialisation Functions
*
*******************************************************************************/
FUNC(void, AUTOMATIC) RE_PFilSlow_008_MSE(void)
{
	/* OUTPUT */
	/* SWC OUT */
	SInt16 cocha_tqefcairreq_swc_out;
	UInt8 cocha_bacvcllit_swc_out;
	UInt16 cocha_titrancllit_swc_out;
	SInt16 cocha_tqinccllit_swc_out;
	SInt16 tqsys_tqckefcairfil_swc_out;

    /* Call initialisation functions */
    PFILSLOW_Prev_Agr_Slow_Init(&tqsys_tqckefcairfil_swc_out /* BIN4 */);

    PFILSLOW_Coord_Slow_Esp_Init( &cocha_bacvcllit_swc_out,
								   &cocha_titrancllit_swc_out,
								   &cocha_tqefcairreq_swc_out,
								   &cocha_tqinccllit_swc_out);

	/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I100(0) */
	Rte_Write_P_CoCha_tqEfcAirReq_CoCha_tqEfcAirReq(cocha_tqefcairreq_swc_out);
	/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I101(0) */
	/* <PRQA_COMMENT><2100> Warning due to tool, conversion is ok </2100></PRQA_COMMENT> */
	Rte_Write_P_CoCha_bAcvCllIt_CoCha_bAcvCllIt(DDS_M_CONVERT_UINT8_TO_BOOL(cocha_bacvcllit_swc_out));
	/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I102(0) */
	Rte_Write_P_CoCha_tiTranCllIt_CoCha_tiTranCllIt(cocha_titrancllit_swc_out);
	/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I103(0) */
	Rte_Write_P_CoCha_tqIncCllIt_CoCha_tqIncCllIt(cocha_tqinccllit_swc_out);
	/* SSTG_REQ_TAG: 01552_10_01786-PFilSlow.I110(0) */
	Rte_Write_P_TqSys_tqCkEfcAirFil_TqSys_tqCkEfcAirFil(tqsys_tqckefcairfil_swc_out);


}


/*******************************************************************************
*  Function Definition for timers
*******************************************************************************/

/*******************************************************************************
*
*  Runnable Name   : PFilSlow_Timer_1ms_U32
*  Description     : Call RTE interface for 1ms timer
*
*******************************************************************************/
FUNC(UInt32, AUTOMATIC) PFilSlow_Timer_1ms_U32(void)
{
    UInt32 current_time;

    (void)Rte_Call_R_PFilSlow_GetTimer_1ms_U32_GetTimer_1ms_U32(&current_time);

    return current_time;
}

/*******************************************************************************
*  Local Task Function Definition
*******************************************************************************/

/* NONE */

#define PFILSLOW_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "PFilSlow_MemMap.h"

