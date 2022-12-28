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
* Ref X:\integration_view_00PSASWC_EC00D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Torque_Selection.c
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 55 m User:esnault 
*    TWK_model:COTQ_Torque_Selection_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 47 m User:lemort 
*    TWK_model:COTQ_Torque_Selection_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 43 m User:lemort
*    TWK_model:COTQ_Torque_Selection_L01_010_IMPL1
*    comments :first dev CoTq
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "CoTq.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define COTQ_GMP_HYBRIDE	1

#define COTQ_BVA		2


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

/* 16-bits scalar calibration definition */
#define COTQ_START_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqDem_facGainFilHY_nCk_C = (CONST(UInt16, AUTOMATIC))(0.5 * BIN10);
#define COTQ_STOP_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"


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

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_Torque_Selection
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Torque_Selection(UInt8 CoCha_bAcvCllIt_swc_in,
                                            UInt8 CoCha_bInhEGR_swc_in,
                                            UInt8 CoCha_bInhEGRExt_swc_in,
                                            SInt8 CoCha_noCylCutAuthIt_swc_in, /* BIN0 */
                                            UInt16 CoCha_tiTranCllIt_swc_in, /* DEC2 */
                                            SInt16 CoCha_tqIncCllIt_swc_in, /* BIN4 */
                                            UInt8 CoPt_bDeacCllExt_swc_in,
                                            UInt8 CoPt_bDeacCllIt_swc_in,
                                            SInt16 CoPt_tqEfcAirCordLimExtTqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqEfcAirCordLimIt_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqEfcCordLimExt_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqEfcCordLimIt_tqGBx_swc_in, /* BIN4 */
                                            UInt8 CoPtUH_bEngAsiReq_swc_in,
                                            UInt8 CoPtUH_bEngAsiReqExt_swc_in,
                                            UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                            UInt16 CoVSCtl_rAccPEngExt_swc_in, /* BIN7 */
                                            SInt16 EngLim_tqCkEfcStatLimExt_swc_in, /* BIN4 */
                                            SInt16 EngLim_tqCkEfcStatLimIt_swc_in, /* BIN4 */
                                            UInt8 Ext_stTraTypCf_swc_in,
                                            UInt16 TqDem_facGainFil_nCk_swc_in, /* BIN10 */
                                            SInt16 TqDem_tqCkEfc_swc_in, /* BIN4 */
                                            SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                            SInt16 TqLimEM_tqLimEMExt_swc_in, /* BIN4 */
                                            UInt8 TqSys_bAcceClrCrossAOSExt_swc_in,
                                            UInt8 TqSys_bAcceClrCrossAOSIt_swc_in,
                                            UInt8 TqSys_bAcceDetAOSExt_swc_in,
                                            UInt8 TqSys_bAcceDetAOSIt_swc_in,
                                            UInt8 TqSys_bAcvCllExt_swc_in,
                                            UInt8 TqSys_bAcvCllIt_swc_in,
                                            UInt8 TqSys_bDeceAcvExt_swc_in,
                                            UInt8 TqSys_bDeceAcvIt_swc_in,
                                            UInt8 TqSys_bDeceDetAOSExt_swc_in,
                                            UInt8 TqSys_bDeceDetAOSIt_swc_in,
                                            SInt8 TqSys_noCylCutAuthExt_swc_in, /* BIN0 */
                                            SInt8 TqSys_noCylCutAuthIt_swc_in, /* BIN0 */
                                            UInt8 TqSys_stDrivFilPhaExt_swc_in,
                                            UInt8 TqSys_stDrivFilPhaIt_swc_in,
                                            UInt8 TqSys_stTypPwtCf_swc_in,
                                            UInt16 TqSys_tiTranCllExt_swc_in, /* DEC2 */
                                            UInt16 TqSys_tiTranCllIt_swc_in, /* DEC2 */
                                            SInt16 TqSys_tqCkDeceIniExt_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqCkEfcFilExt_swc_in, /* BIN4 */
                                            UInt16 TqSys_tqIncCllExt_swc_in, /* BIN4 */
                                            UInt16 TqSys_tqIncCllIt_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqThdPha3Ext_swc_in, /* BIN4 */
                                            SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCll_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGRTrv_swc_out,
                                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoCha_noCylCutAuth_swc_out, /* BIN0 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCll_swc_out, /* DEC2 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCll_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCll_swc_out,
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLim_tqGBx_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEngTrv_swc_out, /* BIN7 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcStatLim_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFilTrv_nCk_swc_out, /* BIN10 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcTrv_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEMTrv_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOS_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOS_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCll_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcv_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOS_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngAsiReqTrv_swc_out,
                                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuth_swc_out, /* BIN0 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPha_swc_out,
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCll_swc_out, /* DEC2 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIni_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFilTrv_swc_out, /* BIN4 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCll_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3_swc_out /* BIN4 */)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_1446.FR.1.2 */

	/* for stack consumption reduction, sub-functions have been deleted*/

	if((UInt32)TqSys_stTypPwtCf_swc_in == (UInt32)COTQ_GMP_HYBRIDE)
	{
		if((UInt32)Ext_stTraTypCf_swc_in == (UInt32)COTQ_BVA)
		{
			/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.2.0 */
			*CoPt_tqEfcAirCordLim_tqGBx_swc_out = CoPt_tqEfcAirCordLimIt_tqGBx_swc_in;
			*CoPt_tqEfcCordLim_tqGBx_swc_out = CoPt_tqEfcCordLimIt_tqGBx_swc_in;

			/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.3.0 */
			*CoPt_bDeacCll_swc_out = CoPt_bDeacCllIt_swc_in;
		}
		else
		{
			/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.2.0 */
			*CoPt_tqEfcAirCordLim_tqGBx_swc_out = CoPt_tqEfcAirCordLimExtTqGBx_swc_in;
			*CoPt_tqEfcCordLim_tqGBx_swc_out = CoPt_tqEfcCordLimExt_tqGBx_swc_in;

			/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.3.0 */
			*CoPt_bDeacCll_swc_out = CoPt_bDeacCllExt_swc_in;
		}

		/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.2.0 */
		*CoVSCtl_rAccPEngTrv_swc_out = CoVSCtl_rAccPEngExt_swc_in;
		*EngLim_tqCkEfcStatLim_swc_out = EngLim_tqCkEfcStatLimExt_swc_in;
		*TqLimEM_tqLimEMTrv_swc_out = TqLimEM_tqLimEMExt_swc_in;
		*TqDem_tqCkEfcTrv_swc_out = TqLimEM_tqLimEMExt_swc_in;
		*TqSys_tqCkDeceIni_swc_out = TqSys_tqCkDeceIniExt_swc_in;
		*TqSys_stDrivFilPha_swc_out = TqSys_stDrivFilPhaExt_swc_in;
		*TqSys_tqCkEfcFilTrv_swc_out = TqSys_tqCkEfcFilExt_swc_in;
		*TqSys_tqThdPha3_swc_out = TqSys_tqThdPha3Ext_swc_in;
		*CoCha_tiTranCll_swc_out = TqSys_tiTranCllExt_swc_in;
		*TqSys_tiTranCll_swc_out = TqSys_tiTranCllExt_swc_in;
		*CoCha_tqIncCll_swc_out = TqSys_tqIncCllExt_swc_in;
		*TqSys_tqIncCll_swc_out = TqSys_tqIncCllExt_swc_in;
		*CoCha_noCylCutAuth_swc_out = TqSys_noCylCutAuthExt_swc_in;
		*TqSys_noCylCutAuth_swc_out = TqSys_noCylCutAuthExt_swc_in;
		*TqDem_facGainFilTrv_nCk_swc_out = TqDem_facGainFilHY_nCk_C;

		/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.3.0 */
		*TqSys_bDeceAcv_swc_out = TqSys_bDeceAcvExt_swc_in;
		*TqSys_bAcceDetAOS_swc_out = TqSys_bAcceDetAOSExt_swc_in;
		*TqSys_bAcceClrCrossAOS_swc_out = TqSys_bAcceClrCrossAOSExt_swc_in;
		*TqSys_bDeceDetAOS_swc_out = TqSys_bDeceDetAOSExt_swc_in;
		*CoCha_bAcvCll_swc_out = TqSys_bAcvCllExt_swc_in;
		*TqSys_bAcvCll_swc_out = TqSys_bAcvCllExt_swc_in;
		*CoCha_bInhEGRTrv_swc_out = CoCha_bInhEGRExt_swc_in;
		*TqSys_bEngAsiReqTrv_swc_out = CoPtUH_bEngAsiReqExt_swc_in;

	}
	else
	{
		/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.2.0 */
		*CoPt_tqEfcAirCordLim_tqGBx_swc_out = CoPt_tqEfcAirCordLimIt_tqGBx_swc_in;
		*CoPt_tqEfcCordLim_tqGBx_swc_out = CoPt_tqEfcCordLimIt_tqGBx_swc_in;
		*CoVSCtl_rAccPEngTrv_swc_out = CoVSCtl_rAccPEng_swc_in;
		*EngLim_tqCkEfcStatLim_swc_out = EngLim_tqCkEfcStatLimIt_swc_in;
		*TqLimEM_tqLimEMTrv_swc_out = TqLimEM_tqLimEM_swc_in;
		*TqDem_tqCkEfcTrv_swc_out = TqDem_tqCkEfc_swc_in;
		*TqSys_tqCkDeceIni_swc_out = TqSys_tqCkDeceIniIt_swc_in;
		*TqSys_stDrivFilPha_swc_out = TqSys_stDrivFilPhaIt_swc_in;
		*TqSys_tqCkEfcFilTrv_swc_out = TqSys_tqCkEfcFil_swc_in;
		*TqSys_tqThdPha3_swc_out = TqSys_tqThdPha3It_swc_in;
		*CoCha_tiTranCll_swc_out = CoCha_tiTranCllIt_swc_in;
		*TqSys_tiTranCll_swc_out = TqSys_tiTranCllIt_swc_in;
		*CoCha_tqIncCll_swc_out = (UInt16)DDS_M_MAX((SInt32)CoCha_tqIncCllIt_swc_in,0);
		*TqSys_tqIncCll_swc_out = TqSys_tqIncCllIt_swc_in;
		*CoCha_noCylCutAuth_swc_out = CoCha_noCylCutAuthIt_swc_in;
		*TqSys_noCylCutAuth_swc_out = TqSys_noCylCutAuthIt_swc_in;
		*TqDem_facGainFilTrv_nCk_swc_out = TqDem_facGainFil_nCk_swc_in;

		/* SSTG_TEQ_TAG : CSMT_CGMT08_1446.FR.3.0 */
		*TqSys_bDeceAcv_swc_out = TqSys_bDeceAcvIt_swc_in;
		*TqSys_bAcceDetAOS_swc_out = TqSys_bAcceDetAOSIt_swc_in;
		*TqSys_bAcceClrCrossAOS_swc_out = TqSys_bAcceClrCrossAOSIt_swc_in;
		*TqSys_bDeceDetAOS_swc_out = TqSys_bDeceDetAOSIt_swc_in;
		*CoCha_bAcvCll_swc_out = CoCha_bAcvCllIt_swc_in;
		*TqSys_bAcvCll_swc_out = TqSys_bAcvCllIt_swc_in;
		*CoPt_bDeacCll_swc_out = CoPt_bDeacCllIt_swc_in;
		*CoCha_bInhEGRTrv_swc_out = CoCha_bInhEGR_swc_in;
		*TqSys_bEngAsiReqTrv_swc_out = CoPtUH_bEngAsiReq_swc_in;

	}

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/




/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Torque_Selection_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Torque_Selection_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCll_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bInhEGRTrv_swc_out,
                                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoCha_noCylCutAuth_swc_out, /* BIN0 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCll_swc_out, /* DEC2 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCll_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCll_swc_out,
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcCordLim_tqGBx_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEngTrv_swc_out, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcStatLim_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqDem_facGainFilTrv_nCk_swc_out, /* BIN10 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqDem_tqCkEfcTrv_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqLimEMTrv_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceClrCrossAOS_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcceDetAOS_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvCll_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcv_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceDetAOS_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngAsiReqTrv_swc_out,
                                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) TqSys_noCylCutAuth_swc_out, /* BIN0 */
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPha_swc_out,
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tiTranCll_swc_out, /* DEC2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIni_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFilTrv_swc_out, /* BIN4 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIncCll_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqThdPha3_swc_out /* BIN4 */)
{
    /* ---- Init Outputs ---- */
	*CoCha_bAcvCll_swc_out = DDS_FALSE;
	*CoCha_bInhEGRTrv_swc_out = DDS_FALSE;
	*CoCha_noCylCutAuth_swc_out = 0;
	*CoCha_tiTranCll_swc_out = 0;
	*CoCha_tqIncCll_swc_out = 0;
	*CoPt_bDeacCll_swc_out = DDS_FALSE;
	*CoPt_tqEfcAirCordLim_tqGBx_swc_out = 0;
	*CoPt_tqEfcCordLim_tqGBx_swc_out = 0;
	*CoVSCtl_rAccPEngTrv_swc_out = 0;
	*EngLim_tqCkEfcStatLim_swc_out = (SInt16)(2000 * BIN4);
	*TqDem_facGainFilTrv_nCk_swc_out = (UInt16)(1 * BIN10);
	*TqDem_tqCkEfcTrv_swc_out = 0;
	*TqLimEM_tqLimEMTrv_swc_out = 0;
	*TqSys_bAcceClrCrossAOS_swc_out = DDS_FALSE;
	*TqSys_bAcceDetAOS_swc_out = DDS_FALSE;
	*TqSys_bAcvCll_swc_out = DDS_FALSE;
	*TqSys_bDeceAcv_swc_out = DDS_FALSE;
	*TqSys_bDeceDetAOS_swc_out = DDS_FALSE;
	*TqSys_bEngAsiReqTrv_swc_out = DDS_FALSE;
	*TqSys_noCylCutAuth_swc_out = 0;
	*TqSys_stDrivFilPha_swc_out = 0;
	*TqSys_tiTranCll_swc_out = 0;
	*TqSys_tqCkDeceIni_swc_out = 0;
	*TqSys_tqCkEfcFilTrv_swc_out = 0;
	*TqSys_tqIncCll_swc_out = 0;
	*TqSys_tqThdPha3_swc_out = 0;




    /* ---- Init Global Datas ---- */

}



#define COTQ_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoTq_MemMap.h"
