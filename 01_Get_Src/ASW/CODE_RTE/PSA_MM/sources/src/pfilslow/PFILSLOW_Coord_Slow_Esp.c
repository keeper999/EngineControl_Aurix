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
* Ref X:\integration_view_00PSASWC_E310D01\blois_psa_sstg\Software\Appli\PFilSlow\src\PFILSLOW_Coord_Slow_Esp.c
* Version int :/main/L04_01/1 Date: 24/1/2011 15 h 34 m User:esnault 
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L04_010_IMPL2
*    comments :just for QAC warning
* Version dev :\main\branch_lemort_pfilslow_dev\5 Date: 24/1/2011 12 h 43 m User:lemort 
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L04_010_IMPL2
*    comments :just for QAC warning
* Version dev :\main\branch_lemort_pfilslow_dev\4 Date: 24/1/2011 12 h 8 m User:lemort
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L04_010_IMPL2
*    comments :renaming CoCha_TqMin_MP and CoCha_TqMax_MP
* Version dev :\main\branch_lemort_pfilslow_dev\3 Date: 13/1/2011 17 h 36 m User:halouane
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L04_010_IMPL1
*    comments :update for PFilSlow11.0, correction following TU.
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 13/1/2011 17 h 34 m User:halouane
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L04_010_IMPL1
*    comments :update for PFilSlow11.0, correction following TU.
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 6/1/2011 16 h 13 m User:lemort
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L04_010_IMPL1
*    comments :for PFilSlow 11.0
* Version int :/main/L03_01/1 Date: 23/7/2010 14 h 43 m User:esnault
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L03_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 1/7/2010 12 h 41 m User:lemort
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L03_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_demezil_pfilslow_dev\3 Date: 17/6/2010 16 h 18 m User:demezil
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L03_010_IMPL1
*    comments :for PFilSlow 2.0
* Version dev :\main\branch_demezil_pfilslow_dev\2 Date: 17/6/2010 16 h 2 m User:demezil
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L03_010_IMPL1
*    comments :for PFilSlow 2.0
* Version dev :\main\branch_demezil_pfilslow_dev\1 Date: 17/6/2010 14 h 5 m User:demezil
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L02_010_IMPL2_D
*    comments :pass QAC and code shaker e6
* Version int :/main/L02_01/1 Date: 7/9/2009 10 h 0 m User:langendorf
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L02_010_IMPL2
*    comments :typical calibration changing
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 28/8/2009 15 h 2 m User:lemort
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L02_010_IMPL2
*    comments :typical calibration changing
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 7/8/2009 14 h 19 m User:lemort
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L02_010_IMPL1
*    comments :for dev PFilSlow 2.0
* Version int :/main/L01_01/2 Date: 25/9/2008 9 h 8 m User:boucher
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L01_010_IMPL2
*    comments :Correction due to a qual test response: useless test
* Version dev :\main\branch_moisan_pfilslow\1 Date: 18/9/2008 11 h 31 m User:moisan
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L01_010_IMPL2
*    comments :Correction due to a qual test response: useless test
* Version int :/main/L01_01/1 Date: 2/9/2008 15 h 31 m User:boucher
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L01_010_IMPL1
*    comments :Add missing requirement tag and update calibration data.
* Version dev :\main\branch_girodon_pfilslow_1_dev\1 Date: 2/9/2008 8 h 41 m User:girodon
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L01_010_IMPL1
*    comments :Add missing requirement tag and update calibration data.
* Version dev :\main\branch_salmane_dev_1\2 Date: 30/7/2008 11 h 29 m User:salmane
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L01_010_IMPL1
*    comments :Parameter name update.
* Version dev :\main\branch_salmane_dev_1\1 Date: 29/7/2008 16 h 4 m User:salmane
*    TWK_model:PFILSLOW_Coord_Slow_Esp_L01_010_IMPL1
*    comments :First version
*
*******************************************************************************/



/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "PFilSlow.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/


#define PFILSLOW_AUCUNE_PROTECTION					(UInt32)0
#define PFILSLOW_PROTECTION_DIFFERENTIEL_ACTIVE		(UInt32)1
#define PFILSLOW_PROTECTION_FREIN_ACTIVE			 (UInt32)2



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
#define PFILSLOW_START_SEC_CALIB_16BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) CoCha_tiTranCll_C = (CONST(UInt16, AUTOMATIC))(1 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) CoCha_tqIncCll_C = (CONST(UInt16, AUTOMATIC))(500 * BIN4);
#define PFILSLOW_STOP_SEC_CALIB_16BIT
#include "PFilSlow_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILSLOW_START_SEC_CALIB_8BIT
#include "PFilSlow_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) CoCha_bProtDfltAcv_C = DDS_FALSE;
#define PFILSLOW_STOP_SEC_CALIB_8BIT
#include "PFilSlow_MemMap.h"


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
#define PFILSLOW_START_SEC_INTERNAL_VAR_16BIT
#include "PFilSlow_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoCha_tqAirMax_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoCha_tqAirMin_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoCha_tqReqASR_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoCha_tqReqMSR_MP; /* BIN4 */
#define PFILSLOW_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilSlow_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILSLOW_START_SEC_CODE
#include "PFilSlow_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/*******************************************************************************
*
* Function Name : PFilSlow_Coord_Slow_Esp
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILSLOW_Coord_Slow_Esp(UInt8 CoCha_bTqReqASR_swc_in,
                                              UInt8 CoCha_bTqReqMSR_swc_in,
                                              UInt8 CoPt_stProt_swc_in, /* BIN0 */
                                              SInt16 CoPt_tqEfcMaxProtDftl_swc_in, /* BIN4 */
                                              UInt8 FRM_bInhESPReq_swc_in,
                                              SInt16 TqCha_tqAirTqDecReq_swc_in, /* BIN4 */
                                              SInt16 TqCha_tqAirTqIncReq_swc_in, /* BIN4 */
                                              SInt16 TqSys_tqCkEfcAirFil_swc_in, /* BIN4 */
                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCllIt_swc_out,
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCllIt_swc_out, /* DEC2 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcAirReq_swc_out, /* BIN4 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCllIt_swc_out /* BIN4 */)
{
	/* SSTG_REQ_TAG: CSMT_CGMT07_2713.FR.2.1 */

	SInt16 pfilslow_out_second_switch;


	/*--------------------------------------------------------------------------*
		*   Calcul of CoCha_tqEfcAirReq                                    *
    *--------------------------------------------------------------------------*/
	if( ((UInt32)CoPt_stProt_swc_in == PFILSLOW_AUCUNE_PROTECTION)
	  ||( ((UInt32)CoPt_stProt_swc_in == PFILSLOW_PROTECTION_DIFFERENTIEL_ACTIVE)
	    &&((UInt32)DDS_FALSE==(UInt32)CoCha_bProtDfltAcv_C)))
	{
		pfilslow_out_second_switch = TqSys_tqCkEfcAirFil_swc_in;
	}
	else
	{
		pfilslow_out_second_switch = (SInt16)DDS_M_MIN((SInt32)CoPt_tqEfcMaxProtDftl_swc_in,
											 (SInt32)TqSys_tqCkEfcAirFil_swc_in);
	}

	CoCha_tqAirMax_MP =(SInt16) DDS_M_MAX((SInt32)pfilslow_out_second_switch,
									   (SInt32)TqCha_tqAirTqIncReq_swc_in);

	if((UInt32)DDS_FALSE == (UInt32)CoCha_bTqReqMSR_swc_in)
	{
		CoCha_tqReqMSR_MP = pfilslow_out_second_switch;
	}
	else
	{
		CoCha_tqReqMSR_MP = CoCha_tqAirMax_MP;
	}

	CoCha_tqAirMin_MP = (SInt16)DDS_M_MIN((SInt32)CoCha_tqReqMSR_MP,
										(SInt32)TqCha_tqAirTqDecReq_swc_in);

	if((UInt32)DDS_FALSE == (UInt32)CoCha_bTqReqASR_swc_in)
	{
		CoCha_tqReqASR_MP = CoCha_tqReqMSR_MP;
	}
	else
	{
		CoCha_tqReqASR_MP = CoCha_tqAirMin_MP;
	}

	/*--------------------------------------------------------------------------*
			*   Calcul of CoCha_bAcvCllIt                                    *
    *--------------------------------------------------------------------------*/

	if((UInt32)DDS_FALSE != (UInt32)FRM_bInhESPReq_swc_in)
	{
		*CoCha_tqEfcAirReq_swc_out = pfilslow_out_second_switch;
		*CoCha_bAcvCllIt_swc_out = DDS_FALSE;
	}
	else
	{
		*CoCha_tqEfcAirReq_swc_out = CoCha_tqReqASR_MP;

		if(((UInt32)DDS_FALSE == (UInt32)CoCha_bTqReqASR_swc_in)
		&&((UInt32)DDS_FALSE == (UInt32)CoCha_bTqReqMSR_swc_in)
		&&((UInt32)CoPt_stProt_swc_in != PFILSLOW_PROTECTION_DIFFERENTIEL_ACTIVE))
		{
			*CoCha_bAcvCllIt_swc_out = DDS_FALSE;
		}
		else
		{
			*CoCha_bAcvCllIt_swc_out = DDS_TRUE;
		}
	}


	/*--------------------------------------------------------------------------*
				*   Calcul of CoCha_tiTranCllIt && CoCha_tqIncCllIt             *
    *--------------------------------------------------------------------------*/

	if((UInt32)DDS_FALSE != ((UInt32)*CoCha_bAcvCllIt_swc_out))
	{
		*CoCha_tiTranCllIt_swc_out = CoCha_tiTranCll_C;
		*CoCha_tqIncCllIt_swc_out = (SInt16)CoCha_tqIncCll_C;
	}
	else
	{
		*CoCha_tiTranCllIt_swc_out = 0;
		*CoCha_tqIncCllIt_swc_out = 0;
    }

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*None*/



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFilSlow_Coord_Slow_Esp_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILSLOW_Coord_Slow_Esp_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCllIt_swc_out,
                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCllIt_swc_out, /* DEC2 */
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcAirReq_swc_out, /* BIN4 */
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCllIt_swc_out /* BIN4 */)
{
    /* ---- Init Outputs ---- */

    /* SWC output */
	*CoCha_tqEfcAirReq_swc_out = 0;  /* BIN4 */
	*CoCha_bAcvCllIt_swc_out = DDS_FALSE;
	*CoCha_tiTranCllIt_swc_out = 0;    /* DEC2 */
	*CoCha_tqIncCllIt_swc_out = 0;     /* BIN4 */

	/* Init Local */
	 CoCha_tqAirMax_MP = 0;
	 CoCha_tqAirMin_MP = 0;
	 CoCha_tqReqASR_MP = 0;
	 CoCha_tqReqMSR_MP = 0;
}



#define PFILSLOW_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "PFilSlow_MemMap.h"

