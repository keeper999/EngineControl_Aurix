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
* Ref X:\integration_view_00PSASWC_EB00D01\blois_psa_sstg\Software\Appli\CurDrivFil\src\CURDRIVFIL_Aos_Func_Agr.c
* Version int :/main/L01_01/1 Date: 27/8/2010 10 h 48 m User:meme 
*    TWK_model:CURDRIVFIL_Aos_Func_Agr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\3 Date: 7/7/2010 12 h 52 m User:veillard 
*    TWK_model:CURDRIVFIL_Aos_Func_Agr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\2 Date: 25/6/2010 10 h 23 m User:veillard
*    TWK_model:CURDRIVFIL_Aos_Func_Agr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
* Version dev :\main\branch_veillard_sstg_mod_curdrivfil_euro_6\1 Date: 24/6/2010 17 h 3 m User:veillard
*    TWK_model:CURDRIVFIL_Aos_Func_Agr_L01_010_IMPL1
*    comments :For CurDrivFil Euro-6
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CurDrivFil.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define CURDRIVFIL_NFILANTIOSC_PREV_SIZE	2

#define CURDRIVFIL_NFILANTIOSC_MIN	(SInt32)(-8000 * BIN2)
#define CURDRIVFIL_NFILANTIOSC_MAX	(SInt32)( 8000 * BIN2)

#define CURDRIVFIL_TORQUE_MIN_BIN4 (SInt32)(-2000 * BIN4)
#define CURDRIVFIL_TORQUE_MAX_BIN4 (SInt32)( 2000 * BIN4)

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

/* 16-bits variables definition */
#define CURDRIVFIL_START_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_nfil1aos_prev[CURDRIVFIL_NFILANTIOSC_PREV_SIZE]; /* BIN2 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_nfil2aos_prev[CURDRIVFIL_NFILANTIOSC_PREV_SIZE]; /* BIN2 */
STATIC VAR(SInt16, AUTOMATIC) curdrivfil_filt1_diff_prev;
STATIC VAR(SInt16, AUTOMATIC) curdrivfil_filt2_diff_prev;
#define CURDRIVFIL_STOP_SEC_VAR_16BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define CURDRIVFIL_START_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nFil1AOS; /* BIN2 */
#define CURDRIVFIL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CurDrivFil_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define CURDRIVFIL_START_SEC_CODE
#include "CurDrivFil_MemMap.h"

STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_Calc_Aos_torque_filt1(UInt16 ext_nengclc0_par,
																  UInt16 ext_nengclc1_par,
																  SInt16 tqsys_factq0aos_par,
																  SInt16 tqsys_factq1aos_par);


STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Calc_Aos_torque_filt2(SInt16 tqsys_factq2aos_par,
																  SInt16 tqsys_factq3aos_par,
													   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)tqsys_nfil2aos_ptr);


STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Calc_Aos_unlimited_torque(SInt16 tqsys_nfil2aos_par,
															          SInt16 tqsys_facspd0aos_par,
															          SInt16 tqsys_facspd1aos_par,
													       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckfilrawaos_ptr);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : CURDRIVFIL_Aos_Func_Agr
* Description : F0_Fonction_Agrement_Curatif
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Aos_Func_Agr(UInt16 Ext_nEngClc0_swc_in, 	/* BIN2 */
                                           UInt16 Ext_nEngClc1_swc_in, 		/* BIN2 */
                                           SInt16 TqSys_facSpd0AOS_swc_in, 	/* BIN10 */
                                           SInt16 TqSys_facSpd1AOS_swc_in, 	/* BIN10 */
                                           SInt16 TqSys_facTq0AOS_swc_in, 	/* BIN10 */
                                           SInt16 TqSys_facTq1AOS_swc_in, 	/* BIN10 */
                                           SInt16 TqSys_facTq2AOS_swc_in, 	/* BIN10 */
                                           SInt16 TqSys_facTq3AOS_swc_in, 	/* BIN10 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nFil2AOS_swc_out, 		/* BIN2 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkFilRawAOS_swc_out 	/* BIN4 */)
{

	/* SSTG_REQ_TAG: CSMT_CGMT06_2095_5_2_3[3] */

	CURDRIVFIL_F01_Calc_Aos_torque_filt1(Ext_nEngClc0_swc_in,
										 Ext_nEngClc1_swc_in,
										 TqSys_facTq0AOS_swc_in,
										 TqSys_facTq1AOS_swc_in);

	CURDRIVFIL_F02_Calc_Aos_torque_filt2(TqSys_facTq2AOS_swc_in,
										 TqSys_facTq3AOS_swc_in,
										 TqSys_nFil2AOS_swc_out);


	CURDRIVFIL_F03_Calc_Aos_unlimited_torque(*TqSys_nFil2AOS_swc_out,
											 TqSys_facSpd0AOS_swc_in,
											 TqSys_facSpd1AOS_swc_in,
											 TqSys_tqCkFilRawAOS_swc_out);




}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_F01_Calc_Aos_torque_filt1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F01_Calc_Aos_torque_filt1(UInt16 ext_nengclc0_par,
																  UInt16 ext_nengclc1_par,
																  SInt16 tqsys_factq0aos_par,
																  SInt16 tqsys_factq1aos_par)
{
	/* SSTG_REQ_TAG: CSMT_CGMT06_2095_5_4_36 */

	SInt32 curdrivfil_temp1; 	/* BIN12 */
	SInt32 curdrivfil_temp2; 	/* BIN12 */
	SInt32 curdrivfil_temp3; 	/* BIN12 */
	SInt32 curdrivfil_s32_temp; /* BIN2 */

	/* [-8000;8000]BIN2 = [0;8000]BIN2 - [0;8000]BIN2 */
	curdrivfil_s32_temp = (SInt32)ext_nengclc0_par - (SInt32)ext_nengclc1_par;

	/* [-16000;16000]BIN12 	=   [-2;2]BIN10 	   * [-8000;8000]BIN2 */
	curdrivfil_temp1 = (SInt32)tqsys_factq0aos_par * (SInt32)tqsys_nfil1aos_prev[0]; /* BIN12 */
	curdrivfil_temp2 = (SInt32)tqsys_factq1aos_par * (SInt32)tqsys_nfil1aos_prev[1]; /* BIN12 */

	/* BIN12 		= 	( [-8000;8000]BIN2 * BIN10 ) 	- ([-16000;16000]BIN12 + [-16000;16000]BIN12) */
	curdrivfil_temp3 =  - (curdrivfil_s32_temp * BIN10) - (curdrivfil_temp1 + curdrivfil_temp2);

	/* Calculate output [-8000;8000]BIN2 = BIN12/BIN10 */
	TqSys_nFil1AOS = (SInt16)DDS_M_LIMIT( (curdrivfil_temp3 / BIN10),
												CURDRIVFIL_NFILANTIOSC_MIN,
												CURDRIVFIL_NFILANTIOSC_MAX );

	/* Store the result for the next call BIN2 */
	tqsys_nfil1aos_prev[1] = tqsys_nfil1aos_prev[0];
	tqsys_nfil1aos_prev[0] = TqSys_nFil1AOS;

}



/*******************************************************************************
*
* Function Name : CURDRIVFIL_F02_Calc_Aos_torque_filt2
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F02_Calc_Aos_torque_filt2(SInt16 tqsys_factq2aos_par,
																  SInt16 tqsys_factq3aos_par,
													   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC)tqsys_nfil2aos_ptr)
{
	/* SSTG_REQ_TAG: CSMT_CGMT06_2095_5_4_37 */

	SInt32 curdrivfil_temp1; /* BIN12 */
	SInt32 curdrivfil_temp2; /* BIN12 */
	SInt32 curdrivfil_temp3; /* BIN12 */
	SInt16 curdrivfil_filt1_diff;	/* BIN2 */

	/* [-8000;8000]BIN2 */
	curdrivfil_filt1_diff = (SInt16)DDS_M_LIMIT(((SInt32)TqSys_nFil1AOS - (SInt32)curdrivfil_filt1_diff_prev),
												CURDRIVFIL_NFILANTIOSC_MIN,
												CURDRIVFIL_NFILANTIOSC_MAX);


	/* [-8000;8000]BIN2 */
	curdrivfil_filt1_diff_prev = TqSys_nFil1AOS;


	/* [-16000;160000]BIN12 = 	[-2;2]BIN10 	   * 	[-8000;8000]BIN2 */
	curdrivfil_temp1 = (SInt32)tqsys_factq2aos_par * (SInt32)tqsys_nfil2aos_prev[0];
	curdrivfil_temp2 = (SInt32)tqsys_factq3aos_par * (SInt32)tqsys_nfil2aos_prev[1];


	/* BIN12 		 = 	( [-8000;8000]BIN2 * BIN10 ) 	        - ([-16000;16000]BIN12 + [-16000;16000]BIN12) */
	curdrivfil_temp3 =  ((SInt32)curdrivfil_filt1_diff * BIN10) - (curdrivfil_temp1 + curdrivfil_temp2); /* BIN12 */


	/* Calculate output [-8000;8000]BIN2 = BIN12/BIN10 */
	*tqsys_nfil2aos_ptr = (SInt16)DDS_M_LIMIT( (curdrivfil_temp3 / BIN10),
											  CURDRIVFIL_NFILANTIOSC_MIN,
											  CURDRIVFIL_NFILANTIOSC_MAX );


	/* Store the result for the next call BIN2 */
	tqsys_nfil2aos_prev[1] = tqsys_nfil2aos_prev[0];
	tqsys_nfil2aos_prev[0] = *tqsys_nfil2aos_ptr;

}


/*******************************************************************************
*
* Function Name : CURDRIVFIL_F03_Calc_Aos_unlimited_torque
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) CURDRIVFIL_F03_Calc_Aos_unlimited_torque(SInt16 tqsys_nfil2aos_par,
															          SInt16 tqsys_facspd0aos_par,
															          SInt16 tqsys_facspd1aos_par,
													       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckfilrawaos_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT06_2095_5_4_38 */

	SInt32 curdrivfil_temp1;
	SInt32 curdrivfil_temp2;

	/* [-16000;16000]BIN12 = [-8000;8000]BIN2 	  * [-2;2]BIN10 */
	curdrivfil_temp1 = (SInt32)tqsys_nfil2aos_par * (SInt32)tqsys_facspd0aos_par;

	/* [-16000;16000]BIN12 = [-8000;8000]BIN2 			  * [-2;2]BIN10 */
	curdrivfil_temp2 = (SInt32)curdrivfil_filt2_diff_prev * (SInt32)tqsys_facspd1aos_par;


	/* [-8000;8000]BIN2 */
	curdrivfil_filt2_diff_prev = tqsys_nfil2aos_par;

	/* [-2000;2000]BIN4 = BIN12 / BIN8 */
	*tqsys_tqckfilrawaos_ptr = (SInt16)DDS_M_LIMIT( ((curdrivfil_temp1 + curdrivfil_temp2) / BIN8),
													CURDRIVFIL_TORQUE_MIN_BIN4,
													CURDRIVFIL_TORQUE_MAX_BIN4 );


}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : CURDRIVFIL_Aos_Func_Agr_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) CURDRIVFIL_Aos_Func_Agr_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nFil2AOS_swc_out, /* BIN2 */
                                           			CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkFilRawAOS_swc_out /* BIN4 */)
{


	/* CURDRIVFIL_F01_Calc_Aos_torque_filt1 */
	tqsys_nfil1aos_prev[0] 	= (SInt16)(0 * BIN2);
	tqsys_nfil1aos_prev[1] 	= (SInt16)(0 * BIN2);
	TqSys_nFil1AOS			= (SInt16)(0 * BIN2);


	/* CURDRIVFIL_F02_Calc_Aos_torque_filt2 */
	curdrivfil_filt1_diff_prev 	= (SInt16)(0 * BIN2);
	tqsys_nfil2aos_prev[0] 		= (SInt16)(0 * BIN2);
	tqsys_nfil2aos_prev[1] 		= (SInt16)(0 * BIN2);
	*TqSys_nFil2AOS_swc_out		= (SInt16)(0 * BIN2);


	/* CURDRIVFIL_F03_Calc_Aos_unlimited_torque */
	curdrivfil_filt2_diff_prev 		= (SInt16)(0 * BIN2);
	*TqSys_tqCkFilRawAOS_swc_out 	= (SInt16)(0 * BIN4);


}



#define CURDRIVFIL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CurDrivFil_MemMap.h"