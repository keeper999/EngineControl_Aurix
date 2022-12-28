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
* Ref X:\integration_view_00PSASWC_EC00D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Conversion_10ms.c
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 57 m User:esnault 
*    TWK_model:COTQ_Conversion_10ms_L01_010_IMPL1
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\3 Date: 26/10/2010 17 h 3 m User:demezil 
*    TWK_model:COTQ_Conversion_10ms_L01_010_IMPL1
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 47 m User:lemort
*    TWK_model:COTQ_Conversion_10ms_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 43 m User:lemort
*    TWK_model:COTQ_Conversion_10ms_L01_010_IMPL1
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

#define COTQ_4_SIZE                           4

#define COTQ_M2000_B4	((SInt32)-2000 * BIN4)
#define COTQ_2000_B4	((SInt32)2000 * BIN4)

#define COPTST_STENG_COUPE_CALE		1
#define COPTST_STENG_STOP			6

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define COTQ_START_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqSys_tqCkEfcMinFeasDsl; /* BIN4 */
#define COTQ_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"


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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_pAirExtRef_C = (CONST(UInt16, AUTOMATIC))(1000 * BIN0);
#define COTQ_STOP_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"

/* 8-bits scalar calibration definition */
#define COTQ_START_SEC_CALIB_8BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(SInt8, AUTOMATIC) TqSys_tAirRef_C = (CONST(SInt8, AUTOMATIC))(25 * BIN0);
#define COTQ_STOP_SEC_CALIB_8BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COTQ_START_SEC_CARTO_16BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rTAirExt_A[COTQ_4_SIZE] = {
(UInt16)(0.6 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1.3 * BIN7),
(UInt16)(1.7 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rTAirExt_T
[COTQ_4_SIZE] = {
(UInt16)(0.914 * BIN7), (UInt16)(0.945 * BIN7), (UInt16)(0.984 * BIN7),
(UInt16)(1.016 * BIN7)
};

#define COTQ_STOP_SEC_CARTO_16BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COTQ_START_SEC_VAR_UNSPECIFIED
#include "CoTq_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_rtairext_t_sav;
#define COTQ_STOP_SEC_VAR_UNSPECIFIED
#include "CoTq_MemMap.h"


/* 16-bits variable definition */
#define COTQ_START_SEC_VAR_16BIT
#include "CoTq_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) englim_tqckefcfldlim_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqckefclim_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqckefcsmklim_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefccurminfucutsel_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcengcurmax_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcengcurmin_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcldmaxtrbmax_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcldmaxwoutovb_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcpresusthrmax_prev;
STATIC VAR(SInt16, AUTOMATIC) thmgt_tqefclimantiboilprot_prev;
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqefcairidl_prev;
#define COTQ_STOP_SEC_VAR_16BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COTQ_START_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_rPAirExt_MP; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_rTAirExt_MP; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqIdcMaxCor_MP; /* BIN4 */
#define COTQ_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"

/* 8-bits variable definition */
#define COTQ_START_SEC_INTERNAL_VAR_8BIT
#include "CoTq_MemMap.h"
/* <PRQA_COMMENT><3229> This MP is implicitly used</3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvRLdClc_MP;
#define COTQ_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COTQ_START_SEC_CONST_UNSPECIFIED
#include "CoTq_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_RTAIREXT_T_APM = {
&tqsys_rtairext_t_sav,
COTQ_4_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rTAirExt_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_rTAirExt_T[0]
};

#define COTQ_STOP_SEC_CONST_UNSPECIFIED
#include "CoTq_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"

STATIC FUNC(void, AUTOMATIC) COTQ_F02_01_Conv_Commun_10ms (SInt16 englim_tqidcsyst_par,
															SInt16 englim_tqidcred_par,
															SInt16 englim_tqidcsfty_par,
															SInt16 englim_tqidcengprot_par,
															SInt16 tqsys_tqckidlcmn_par,
															SInt16 tqsys_tqidcreq_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcsyst_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcred_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcsfty_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcengprot_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqefcidl_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcreq_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F02_02_Conv_Essence_10ms (SInt16 englim_tqidcldmaxtrbmax_par,
															SInt16 englim_tqidcpresusthrmax_par,
															SInt16 englim_tqidcengcurmax_par,
															SInt16 englim_tqidcengcurmin_par,
															SInt16 idlsys_tqidcairidl_par,
															SInt16 englim_tqidcengcurminselc_par,
															SInt16 englim_tqidcldmaxtrbmaxnoovb_par,
															UInt16 thmgt_tqidclimreq_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldmaxtrbmax_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcpresusthrmax_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcengcurmax_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcengcurmin_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqefcairidl_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefccurminfucutsel_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldmaxwoutovb_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) thmgt_tqefclimantiboilprot_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F02_03_Conv_Diesel_10ms (	SInt16 englim_tqidcsmklim_par,
															SInt16 englim_tqidcfldlim_par,
															SInt16 englim_tqidcenglim_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckefcsmklim_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckefcfldlim_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckefclim_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F02_04_Conv_Couple_Mini (UInt8 tqsys_btypfu_par,
															SInt16 englim_tqefccurminfucutsel_par,
															SInt16 englim_tqefcengcurmin_par,
															SInt16 tqcmp_tqaltloss_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmincurcutofftrv_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmincurtrv_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcminenglimcmb_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F02_05_Calcul_Charge_Moteur (UInt16 ext_pairextmes_par,
																SInt8 ext_tair_par,
																UInt8 tqsys_btypfu_par,
																UInt8 coptst_steng_par,
																UInt8 coptst_bmainengstopreq_par,
																SInt16 englim_tqidcldmaxtrbmax_par,
																SInt16 englim_tqidcfldlim_par,
																SInt16 tqsys_tqidcreq_par,
																CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_rldengref_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_Conversion_10ms
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Conversion_10ms(UInt8 CoPTSt_bMainEngStopReq_swc_in,
                                           UInt8 CoPTSt_stEng_swc_in,
                                           SInt16 EngLim_tqIdcEngCurMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngCurMin_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngCurMinSelc_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcEngProt_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcFLdLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcLdMaxTrbMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcLdMaxTrbMaxNoOvb_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcPresUsThrMax_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSfty_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSmkLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcSyst_swc_in, /* BIN4 */
                                           UInt16 Ext_pAirExtMes_swc_in, /* BIN0 */
                                           SInt8 Ext_tAir_swc_in, /* BIN0 */
                                           SInt16 IdlSys_tqIdcAirIdl_swc_in, /* BIN4 */
                                           UInt16 ThMgt_tqIdcLimReq_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           UInt8 TqSys_bTypFu_swc_in,
                                           SInt16 TqSys_tqCkIdlCmn_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcReq_swc_in, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcFLdLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcSmkLim_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcCurMinFuCutSel_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMin_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngProt_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxTrbMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxWoutOvb_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurCutOffTrv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurTrv_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinEngLimCmb_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcPresUsThrMax_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcRed_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSfty_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSyst_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) ThMgt_tqEfcLimAntiBoilProt_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_rLdEngRef_swc_out, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcReq_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcAirIdl_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcIdl_swc_out /* BIN4 */)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.2.3 */

	COTQ_F02_01_Conv_Commun_10ms (  EngLim_tqIdcSyst_swc_in,
									EngLim_tqIdcRed_swc_in,
									EngLim_tqIdcSfty_swc_in,
									EngLim_tqIdcEngProt_swc_in,
									TqSys_tqCkIdlCmn_swc_in,
									TqSys_tqIdcReq_swc_in,
									TqCmp_tqSumLossCmp_swc_in,
									EngLim_tqEfcSyst_swc_out,
									EngLim_tqEfcRed_swc_out,
									EngLim_tqEfcSfty_swc_out,
									EngLim_tqEfcEngProt_swc_out,
									TqSys_tqEfcIdl_swc_out,
									TqSys_tqCkEfcReq_swc_out);

	if((UInt32)DDS_FALSE != (UInt32)TqSys_bTypFu_swc_in)
	{
		COTQ_F02_02_Conv_Essence_10ms ( EngLim_tqIdcLdMaxTrbMax_swc_in,
										EngLim_tqIdcPresUsThrMax_swc_in,
										EngLim_tqIdcEngCurMax_swc_in,
										EngLim_tqIdcEngCurMin_swc_in,
										IdlSys_tqIdcAirIdl_swc_in,
										EngLim_tqIdcEngCurMinSelc_swc_in,
										EngLim_tqIdcLdMaxTrbMaxNoOvb_swc_in,
										ThMgt_tqIdcLimReq_swc_in,
										TqCmp_tqSumLossCmp_swc_in,
										EngLim_tqEfcLdMaxTrbMax_swc_out,
										EngLim_tqEfcPresUsThrMax_swc_out,
										EngLim_tqEfcEngCurMax_swc_out,
										EngLim_tqEfcEngCurMin_swc_out,
										TqSys_tqEfcAirIdl_swc_out,
										EngLim_tqEfcCurMinFuCutSel_swc_out,
										EngLim_tqEfcLdMaxWoutOvb_swc_out,
										ThMgt_tqEfcLimAntiBoilProt_swc_out);

		englim_tqefcldmaxtrbmax_prev = *EngLim_tqEfcLdMaxTrbMax_swc_out;
		englim_tqefcpresusthrmax_prev = *EngLim_tqEfcPresUsThrMax_swc_out;
		englim_tqefcengcurmax_prev = *EngLim_tqEfcEngCurMax_swc_out;
		englim_tqefcengcurmin_prev = *EngLim_tqEfcEngCurMin_swc_out;
		tqsys_tqefcairidl_prev = *TqSys_tqEfcAirIdl_swc_out;
		englim_tqefccurminfucutsel_prev = *EngLim_tqEfcCurMinFuCutSel_swc_out;
		englim_tqefcldmaxwoutovb_prev = *EngLim_tqEfcLdMaxWoutOvb_swc_out;
		thmgt_tqefclimantiboilprot_prev = *ThMgt_tqEfcLimAntiBoilProt_swc_out;

		*EngLim_tqCkEfcSmkLim_swc_out = englim_tqckefcsmklim_prev;
		*EngLim_tqCkEfcFLdLim_swc_out = englim_tqckefcfldlim_prev;
		*EngLim_tqCkEfcLim_swc_out = englim_tqckefclim_prev;
	}
	else
	{
		COTQ_F02_03_Conv_Diesel_10ms (  EngLim_tqIdcSmkLim_swc_in,
										EngLim_tqIdcFLdLim_swc_in,
										EngLim_tqIdcEngLim_swc_in,
										TqCmp_tqSumLossCmp_swc_in,
										EngLim_tqCkEfcSmkLim_swc_out,
										EngLim_tqCkEfcFLdLim_swc_out,
										EngLim_tqCkEfcLim_swc_out);

		englim_tqckefcsmklim_prev = *EngLim_tqCkEfcSmkLim_swc_out;
		englim_tqckefcfldlim_prev = *EngLim_tqCkEfcFLdLim_swc_out;
		englim_tqckefclim_prev = *EngLim_tqCkEfcLim_swc_out;

		*EngLim_tqEfcLdMaxTrbMax_swc_out = englim_tqefcldmaxtrbmax_prev;
		*EngLim_tqEfcPresUsThrMax_swc_out = englim_tqefcpresusthrmax_prev;
		*EngLim_tqEfcEngCurMax_swc_out = englim_tqefcengcurmax_prev;
		*EngLim_tqEfcEngCurMin_swc_out = englim_tqefcengcurmin_prev;
		*TqSys_tqEfcAirIdl_swc_out = tqsys_tqefcairidl_prev;
		*EngLim_tqEfcCurMinFuCutSel_swc_out = englim_tqefccurminfucutsel_prev;
		*EngLim_tqEfcLdMaxWoutOvb_swc_out = englim_tqefcldmaxwoutovb_prev;
		*ThMgt_tqEfcLimAntiBoilProt_swc_out = thmgt_tqefclimantiboilprot_prev;
	}

	COTQ_F02_04_Conv_Couple_Mini (  TqSys_bTypFu_swc_in,
									*EngLim_tqEfcCurMinFuCutSel_swc_out,
									*EngLim_tqEfcEngCurMin_swc_out,
									TqCmp_tqAltLoss_swc_in,
									TqCmp_tqSumLossCmp_swc_in,
									EngLim_tqEfcMinCurCutOffTrv_swc_out,
									EngLim_tqEfcMinCurTrv_swc_out,
									EngLim_tqEfcMinEngLimCmb_swc_out);

	COTQ_F02_05_Calcul_Charge_Moteur (  Ext_pAirExtMes_swc_in,
										Ext_tAir_swc_in,
										TqSys_bTypFu_swc_in,
										CoPTSt_stEng_swc_in,
										CoPTSt_bMainEngStopReq_swc_in,
										EngLim_tqIdcLdMaxTrbMax_swc_in,
										EngLim_tqIdcFLdLim_swc_in,
										TqSys_tqIdcReq_swc_in,
										TqSys_rLdEngRef_swc_out);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_F02_01_Conv_Commun_10ms
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_01_Conv_Commun_10ms (SInt16 englim_tqidcsyst_par,
															SInt16 englim_tqidcred_par,
															SInt16 englim_tqidcsfty_par,
															SInt16 englim_tqidcengprot_par,
															SInt16 tqsys_tqckidlcmn_par,
															SInt16 tqsys_tqidcreq_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcsyst_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcred_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcsfty_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcengprot_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqefcidl_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcreq_ptr)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.9.0 */

	SInt32 englim_tqefcsyst_temp;
	SInt32 englim_tqefcred_temp;
	SInt32 englim_tqefcsfty_temp;
	SInt32 englim_tqefcengprot_temp;
	SInt32 tqsys_tqefcidl_temp;
	SInt32 tqsys_tqckefcreq_temp;

	englim_tqefcsyst_temp = (SInt32)englim_tqidcsyst_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcred_temp = (SInt32)englim_tqidcred_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcsfty_temp = (SInt32)englim_tqidcsfty_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcengprot_temp = (SInt32)englim_tqidcengprot_par - (SInt32)tqcmp_tqsumlosscmp_par;
	tqsys_tqefcidl_temp = (SInt32)tqsys_tqckidlcmn_par - (SInt32)tqcmp_tqsumlosscmp_par;
	tqsys_tqckefcreq_temp = (SInt32)tqsys_tqidcreq_par - (SInt32)tqcmp_tqsumlosscmp_par;

	*englim_tqefcsyst_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcsyst_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcred_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcred_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcsfty_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcsfty_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcengprot_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcengprot_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*tqsys_tqefcidl_ptr = (SInt16)DDS_M_LIMIT(tqsys_tqefcidl_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*tqsys_tqckefcreq_ptr = (SInt16)DDS_M_LIMIT(tqsys_tqckefcreq_temp,COTQ_M2000_B4,COTQ_2000_B4);


}

/*******************************************************************************
*
* Function Name : COTQ_F02_02_Conv_Essence_10ms
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_02_Conv_Essence_10ms (SInt16 englim_tqidcldmaxtrbmax_par,
															SInt16 englim_tqidcpresusthrmax_par,
															SInt16 englim_tqidcengcurmax_par,
															SInt16 englim_tqidcengcurmin_par,
															SInt16 idlsys_tqidcairidl_par,
															SInt16 englim_tqidcengcurminselc_par,
															SInt16 englim_tqidcldmaxtrbmaxnoovb_par,
															UInt16 thmgt_tqidclimreq_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldmaxtrbmax_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcpresusthrmax_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcengcurmax_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcengcurmin_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqefcairidl_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefccurminfucutsel_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldmaxwoutovb_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) thmgt_tqefclimantiboilprot_ptr)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.10.0 */

	SInt32 englim_tqefcldmaxtrbmax_temp;
	SInt32 englim_tqefcpresusthrmax_temp;
	SInt32 englim_tqefcengcurmax_temp;
	SInt32 englim_tqefcengcurmin_temp;
	SInt32 tqsys_tqefcairidl_temp;
	SInt32 englim_tqefccurminfucutsel_temp;
	SInt32 englim_tqefcldmaxwoutovb_temp;
	SInt32 thmgt_tqefclimantiboilprot_temp;

	englim_tqefcldmaxtrbmax_temp = (SInt32)englim_tqidcldmaxtrbmax_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcpresusthrmax_temp = (SInt32)englim_tqidcpresusthrmax_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcengcurmax_temp = (SInt32)englim_tqidcengcurmax_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcengcurmin_temp = (SInt32)englim_tqidcengcurmin_par - (SInt32)tqcmp_tqsumlosscmp_par;
	tqsys_tqefcairidl_temp = (SInt32)idlsys_tqidcairidl_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefccurminfucutsel_temp = (SInt32)englim_tqidcengcurminselc_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqefcldmaxwoutovb_temp = (SInt32)englim_tqidcldmaxtrbmaxnoovb_par - (SInt32)tqcmp_tqsumlosscmp_par;
	thmgt_tqefclimantiboilprot_temp = (SInt32)thmgt_tqidclimreq_par - (SInt32)tqcmp_tqsumlosscmp_par;

	*englim_tqefcldmaxtrbmax_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcldmaxtrbmax_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcpresusthrmax_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcpresusthrmax_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcengcurmax_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcengcurmax_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcengcurmin_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcengcurmin_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*tqsys_tqefcairidl_ptr = (SInt16)DDS_M_LIMIT(tqsys_tqefcairidl_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefccurminfucutsel_ptr = (SInt16)DDS_M_LIMIT(englim_tqefccurminfucutsel_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqefcldmaxwoutovb_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcldmaxwoutovb_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*thmgt_tqefclimantiboilprot_ptr = (SInt16)DDS_M_LIMIT(thmgt_tqefclimantiboilprot_temp,COTQ_M2000_B4,COTQ_2000_B4);

}

/*******************************************************************************
*
* Function Name : COTQ_F02_03_Conv_Diesel_10ms
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_03_Conv_Diesel_10ms (	SInt16 englim_tqidcsmklim_par,
															SInt16 englim_tqidcfldlim_par,
															SInt16 englim_tqidcenglim_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckefcsmklim_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckefcfldlim_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqckefclim_ptr)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.11.0 */

	SInt32 englim_tqckefcsmklim_temp;
	SInt32 englim_tqckefcfldlim_temp;
	SInt32 englim_tqckefclim_temp;

	englim_tqckefcsmklim_temp = (SInt32)englim_tqidcsmklim_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqckefcfldlim_temp = (SInt32)englim_tqidcfldlim_par - (SInt32)tqcmp_tqsumlosscmp_par;
	englim_tqckefclim_temp = (SInt32)englim_tqidcenglim_par - (SInt32)tqcmp_tqsumlosscmp_par;

	*englim_tqckefcsmklim_ptr = (SInt16)DDS_M_LIMIT(englim_tqckefcsmklim_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqckefcfldlim_ptr = (SInt16)DDS_M_LIMIT(englim_tqckefcfldlim_temp,COTQ_M2000_B4,COTQ_2000_B4);
	*englim_tqckefclim_ptr = (SInt16)DDS_M_LIMIT(englim_tqckefclim_temp,COTQ_M2000_B4,COTQ_2000_B4);
}

/*******************************************************************************
*
* Function Name : COTQ_F02_04_Conv_Couple_Mini
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_04_Conv_Couple_Mini (UInt8 tqsys_btypfu_par,
															SInt16 englim_tqefccurminfucutsel_par,
															SInt16 englim_tqefcengcurmin_par,
															SInt16 tqcmp_tqaltloss_par,
															SInt16 tqcmp_tqsumlosscmp_par,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmincurcutofftrv_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmincurtrv_ptr,
															CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcminenglimcmb_ptr)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.12.1 */

	SInt32 englim_tqefcminenglimcmb_temp;

	if((UInt32)DDS_FALSE != (UInt32)tqsys_btypfu_par)
	{
		*englim_tqefcmincurtrv_ptr = englim_tqefcengcurmin_par;
		*englim_tqefcmincurcutofftrv_ptr = englim_tqefccurminfucutsel_par;
	}
	else
	{
		*englim_tqefcmincurtrv_ptr = TqSys_tqCkEfcMinFeasDsl;
		*englim_tqefcmincurcutofftrv_ptr = (SInt16)(-1 * (SInt32)tqcmp_tqsumlosscmp_par);
	}

	englim_tqefcminenglimcmb_temp = (SInt32)tqcmp_tqaltloss_par - (SInt32)tqcmp_tqsumlosscmp_par;

	*englim_tqefcminenglimcmb_ptr = (SInt16)DDS_M_LIMIT(englim_tqefcminenglimcmb_temp,COTQ_M2000_B4,COTQ_2000_B4);

}

/*******************************************************************************
*
* Function Name : COTQ_F02_05_Calcul_Charge_Moteur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_05_Calcul_Charge_Moteur (UInt16 ext_pairextmes_par,
																SInt8 ext_tair_par,
																UInt8 tqsys_btypfu_par,
																UInt8 coptst_steng_par,
																UInt8 coptst_bmainengstopreq_par,
																SInt16 englim_tqidcldmaxtrbmax_par,
																SInt16 englim_tqidcfldlim_par,
																SInt16 tqsys_tqidcreq_par,
																CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_rldengref_ptr)
{
	/* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.13.0 */

	UInt32 tqsys_rpairext_temp;
	UInt16 cotq_temp_rate;
	SInt32 tqsys_tqidcmaxcor_temp;
	SInt32 cotq_s32_temp;

	tqsys_rpairext_temp = ((UInt32)ext_pairextmes_par * BIN7) / (UInt32)TqSys_pAirExtRef_C;

	TqSys_rPAirExt_MP = (UInt16)DDS_M_MIN(tqsys_rpairext_temp, ((UInt32)2 * BIN7));

	/* ([-40;100] + 273) / ([-40;100] + 273) = [233;373] / [233;373] = [0.62;1.6] BIN7  */
	cotq_temp_rate = (UInt16)( (((SInt32)TqSys_tAirRef_C + 273) * BIN7) / ((SInt32)ext_tair_par + 273) );

	TqSys_rTAirExt_MP = DDS_M_MAP2D_U16(&TQSYS_RTAIREXT_T_APM,cotq_temp_rate);

	/* BIN4 = BIN4 * BIN7 * BIN7 / BIN14 */
	if((UInt32)DDS_FALSE != (UInt32)tqsys_btypfu_par)
	{
		tqsys_tqidcmaxcor_temp = (((SInt32)englim_tqidcldmaxtrbmax_par * (SInt32)TqSys_rPAirExt_MP) * (SInt32)TqSys_rTAirExt_MP) / BIN14;
	}
	else
	{
		tqsys_tqidcmaxcor_temp = (((SInt32)englim_tqidcfldlim_par * (SInt32)TqSys_rPAirExt_MP) * (SInt32)TqSys_rTAirExt_MP) / BIN14;
	}

	TqSys_tqIdcMaxCor_MP = (SInt16)DDS_M_LIMIT(tqsys_tqidcmaxcor_temp,COTQ_M2000_B4,COTQ_2000_B4);

	if((COPTST_STENG_COUPE_CALE == (UInt32)coptst_steng_par)
	|| (COPTST_STENG_STOP == (UInt32)coptst_steng_par)
	|| ((UInt32)DDS_FALSE != (UInt32)coptst_bmainengstopreq_par) )
	{
		TqSys_bAcvRLdClc_MP = DDS_TRUE;
		*tqsys_rldengref_ptr = 0;
	}
	else
	{
		TqSys_bAcvRLdClc_MP = DDS_FALSE;

		cotq_s32_temp = (SInt32)tqsys_tqidcreq_par * (SInt32)TqSys_tqIdcMaxCor_MP;

		/* if TqSys_tqIdcReq and TqSys_tqIdcMaxCor_MP have different signs, the division result will be negative */
		if(cotq_s32_temp < 0)
		{
			*tqsys_rldengref_ptr = 0;
		}
		else
		{
			if((SInt32)tqsys_tqidcreq_par == 0)
			{
				*tqsys_rldengref_ptr = 0;
			}
			else
			{
				if((SInt32)TqSys_tqIdcMaxCor_MP == 0)
				{
					if((SInt32)tqsys_tqidcreq_par > 0)
					{
						*tqsys_rldengref_ptr = 100;
					}
					else
					{
						*tqsys_rldengref_ptr = 0;
					}
				}
				else
				{
					cotq_s32_temp = ((SInt32)tqsys_tqidcreq_par * 100) / (SInt32)TqSys_tqIdcMaxCor_MP;
					*tqsys_rldengref_ptr = (UInt8)DDS_M_LIMIT(cotq_s32_temp,0,100);
				}
			}
		}
	}

}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Conversion_10ms_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Conversion_10ms_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcFLdLim_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcLim_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqCkEfcSmkLim_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcCurMinFuCutSel_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMax_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngCurMin_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngProt_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxTrbMax_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMaxWoutOvb_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurCutOffTrv_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinCurTrv_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMinEngLimCmb_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcPresUsThrMax_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcRed_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSfty_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcSyst_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) ThMgt_tqEfcLimAntiBoilProt_swc_out, /* BIN4 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_rLdEngRef_swc_out, /* BIN0 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcReq_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcAirIdl_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcIdl_swc_out /* BIN4 */)
{

	*EngLim_tqCkEfcFLdLim_swc_out = COTQ_2000_B4;
	*EngLim_tqCkEfcLim_swc_out = COTQ_2000_B4;
	*EngLim_tqCkEfcSmkLim_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcCurMinFuCutSel_swc_out = 0;
	*EngLim_tqEfcEngCurMax_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcEngCurMin_swc_out = 0;
	*EngLim_tqEfcEngProt_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcLdMaxTrbMax_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcLdMaxWoutOvb_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcMinCurCutOffTrv_swc_out = 0;
	*EngLim_tqEfcMinCurTrv_swc_out = 0;
	*EngLim_tqEfcMinEngLimCmb_swc_out = 0;
	*EngLim_tqEfcPresUsThrMax_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcRed_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcSfty_swc_out = COTQ_2000_B4;
	*EngLim_tqEfcSyst_swc_out = COTQ_2000_B4;
	*ThMgt_tqEfcLimAntiBoilProt_swc_out = COTQ_2000_B4;
	*TqSys_rLdEngRef_swc_out = 0;
	*TqSys_tqCkEfcReq_swc_out = 0;
	*TqSys_tqEfcAirIdl_swc_out = 0;
	*TqSys_tqEfcIdl_swc_out = 0;

	englim_tqckefcfldlim_prev = COTQ_2000_B4;
	englim_tqckefclim_prev = COTQ_2000_B4;
	englim_tqckefcsmklim_prev = COTQ_2000_B4;
	englim_tqefccurminfucutsel_prev = 0;
	englim_tqefcengcurmax_prev = COTQ_2000_B4;
	englim_tqefcengcurmin_prev = 0;
	englim_tqefcldmaxtrbmax_prev = COTQ_2000_B4;
	englim_tqefcldmaxwoutovb_prev = COTQ_2000_B4;
	englim_tqefcpresusthrmax_prev = COTQ_2000_B4;
	thmgt_tqefclimantiboilprot_prev = COTQ_2000_B4;
	tqsys_tqefcairidl_prev = 0;

	TqSys_bAcvRLdClc_MP = 0;
	TqSys_rPAirExt_MP = 0;
	TqSys_rTAirExt_MP = 0;
	TqSys_tqIdcMaxCor_MP = 0;


}



#define COTQ_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoTq_MemMap.h"
