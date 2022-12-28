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
* Ref X:\integration_view_00PSASWC_EC00D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Tempo_Data_Synch.c
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 55 m User:esnault 
*    TWK_model:COTQ_Tempo_Data_Synch_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\3 Date: 22/10/2010 11 h 31 m User:demezil 
*    TWK_model:COTQ_Tempo_Data_Synch_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 47 m User:lemort
*    TWK_model:COTQ_Tempo_Data_Synch_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 43 m User:lemort
*    TWK_model:COTQ_Tempo_Data_Synch_L01_010_IMPL1
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

/* 8-bits variable definition */
#define COTQ_START_SEC_VAR_8BIT
#include "CoTq_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) copt_binjcutdynauth1_prev;
STATIC VAR(UInt8, AUTOMATIC) copt_binjcutdynauth2_prev;
#define COTQ_STOP_SEC_VAR_8BIT
#include "CoTq_MemMap.h"


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

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_Tempo_Data_Synch
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Tempo_Data_Synch(UInt8 CoPt_bAcvNRegReq_swc_in,
                                            UInt8 CoPt_bDeacCll_swc_in,
                                            UInt8 CoPt_bSIP_swc_in,
                                            SInt8 CoPt_noTarGearCordIt_swc_in,
                                            UInt16 CoPt_nTar_swc_in, /* BIN2 */
                                            SInt16 CoPt_tqEfcCordLim_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqIdcCordLim_tqGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqIdcMaxGBx_swc_in, /* BIN4 */
                                            SInt16 CoPt_tqMaxGBx_nReg_swc_in, /* BIN4 */
                                            SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                            SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                            UInt8 TqSys_bTypFu_swc_in,
                                            SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvNRegReqBuf_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCllBuf_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth1_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth2_swc_out,
                                            CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bSIPBuf_swc_out,
                                            CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoPt_noTarGearCordBuf_swc_out, /* BIN0 */
                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoPt_nTarBuf_swc_out, /* BIN2 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLimBuf_tqGBx_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBxBuf_swc_out, /* BIN4 */
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqMaxGBx_nRegBuf_swc_out /* BIN4 */)
{
	/* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.1.1  */


	/* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.2.1 */
	if((UInt32)DDS_FALSE != (UInt32)TqSys_bTypFu_swc_in)
	{
		if((SInt32)CoPt_tqEfcCordLim_tqGBx_swc_in == (SInt32)TqSys_tqCkEfcFil_swc_in)
		{
			*CoPt_bInjCutDynAuth1_swc_out = DDS_TRUE;
		}
		else
		{
			*CoPt_bInjCutDynAuth1_swc_out = DDS_FALSE;
		}
		copt_binjcutdynauth1_prev = *CoPt_bInjCutDynAuth1_swc_out;

		if(((SInt32)TqCmp_tqSumLossCmp_swc_in + (SInt32)TqLimEM_tqLimEM_swc_in) == 0)
		{
			*CoPt_bInjCutDynAuth2_swc_out = DDS_TRUE;
		}
		else
		{
			*CoPt_bInjCutDynAuth2_swc_out = DDS_FALSE;
		}
		copt_binjcutdynauth2_prev = *CoPt_bInjCutDynAuth2_swc_out;
	}
	else
	{
		*CoPt_bInjCutDynAuth1_swc_out = copt_binjcutdynauth1_prev;
		*CoPt_bInjCutDynAuth2_swc_out = copt_binjcutdynauth2_prev;
	}



	/* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.3.2 */
	/* this requirement is respected on CoTq.c */


	/* SSTG_REQ_TAG : CSMT_CGMT06_2168.FR.4.1 */

	*CoPt_bAcvNRegReqBuf_swc_out = CoPt_bAcvNRegReq_swc_in;
	*CoPt_bDeacCllBuf_swc_out = CoPt_bDeacCll_swc_in;
	*CoPt_bSIPBuf_swc_out = CoPt_bSIP_swc_in;
	*CoPt_noTarGearCordBuf_swc_out = CoPt_noTarGearCordIt_swc_in;
	*CoPt_nTarBuf_swc_out = CoPt_nTar_swc_in;
	*CoPt_tqIdcCordLimBuf_tqGBx_swc_out = CoPt_tqIdcCordLim_tqGBx_swc_in;
	*CoPt_tqIdcMaxGBxBuf_swc_out = CoPt_tqIdcMaxGBx_swc_in;
	*CoPt_tqMaxGBx_nRegBuf_swc_out = CoPt_tqMaxGBx_nReg_swc_in;

}






/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Tempo_Data_Synch_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Tempo_Data_Synch_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bAcvNRegReqBuf_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bDeacCllBuf_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth1_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bInjCutDynAuth2_swc_out,
                                                 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoPt_bSIPBuf_swc_out,
                                                 CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) CoPt_noTarGearCordBuf_swc_out, /* BIN0 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoPt_nTarBuf_swc_out, /* BIN2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLimBuf_tqGBx_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBxBuf_swc_out, /* BIN4 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqMaxGBx_nRegBuf_swc_out /* BIN4 */)
{
    /* ---- Init Outputs ---- */

	*CoPt_bInjCutDynAuth1_swc_out = DDS_FALSE;
	*CoPt_bInjCutDynAuth2_swc_out = DDS_FALSE;
	*CoPt_nTarBuf_swc_out = (UInt16)(750 * BIN2);
	*CoPt_bAcvNRegReqBuf_swc_out = DDS_FALSE;
	*CoPt_noTarGearCordBuf_swc_out = 0;
	*CoPt_tqMaxGBx_nRegBuf_swc_out = (SInt16)(2000 * BIN4);
	*CoPt_tqIdcCordLimBuf_tqGBx_swc_out = 0;
	*CoPt_bSIPBuf_swc_out = DDS_FALSE;
	*CoPt_tqIdcMaxGBxBuf_swc_out = (SInt16)(2000 * BIN4);
	*CoPt_bDeacCllBuf_swc_out = DDS_FALSE;



    /* ---- Init Global Datas ---- */
    copt_binjcutdynauth1_prev = DDS_FALSE;
	copt_binjcutdynauth2_prev = DDS_FALSE;
}



#define COTQ_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoTq_MemMap.h"