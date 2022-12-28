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
* Ref X:\integration_view_00PSASWC_D500D02\blois_psa_sstg\Software\Appli\VSLim\src\VSLIM_Fct_Mode.c
* Version int :/main/L01_01/2 Date: 25/1/2011 14 h 24 m User:esnault 
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0 : correction following TU report
* Version dev :\main\branch_demezil_vslim\5 Date: 19/1/2011 15 h 15 m User:demezil 
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0 : correction following TU report
* Version dev :\main\branch_demezil_vslim\4 Date: 18/1/2011 17 h 33 m User:demezil
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0
*    comments :FOR TESTOR : DO NOT TAKE ACCOUNT OF THIS VERSION
* Version dev :\main\branch_demezil_vslim\3 Date: 17/1/2011 10 h 0 m User:demezil
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0
*    comments :FOR TESTOR : DO NOT TAKE ACCOUNT OF THIS VERSION
* Version dev :\main\branch_demezil_vslim\2 Date: 22/12/2010 17 h 6 m User:demezil
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0
* Version dev :\main\branch_demezil_vslim\1 Date: 22/12/2010 15 h 2 m User:demezil
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0
* Version dev :\main\branch_demezil\1 Date: 22/12/2010 14 h 53 m User:demezil
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :for VSLim 10.0
* Version dev :\main\branch_veillard_vslim\3 Date: 21/12/2010 17 h 55 m User:veillard
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\2 Date: 17/12/2010 9 h 40 m User:veillard
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\1 Date: 10/12/2010 9 h 1 m User:veillard
*    TWK_model:VSLIM_Fct_Mode_L01_010_IMPL1
*    comments :For VSLim 10.0
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSLim.h"


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

/* 8-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_Ini; /* BIN0 */
VAR(UInt8, AUTOMATIC) VSCtl_stMonVSLim;
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"

/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 8-bits scalar calibration definition */
#define VSLIM_START_SEC_CALIB_8BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_ctTolRvDftVSLim_C = (CONST(UInt8, AUTOMATIC))(255 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiIni_VSLim_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_tiDftRvVSLim_C = (CONST(UInt8, AUTOMATIC))(49 * BIN0);

#define VSLIM_STOP_SEC_CALIB_8BIT
#include "VSLim_MemMap.h"



/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define VSLIM_START_SEC_VAR_8BIT
#include "VSLim_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bmonrunvslim_prv;
STATIC VAR(UInt8, AUTOMATIC) vsctl_bdgovslim_prev;
#define VSLIM_STOP_SEC_VAR_8BIT
#include "VSLim_MemMap.h"



/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCfVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bctDefRevVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_ctDftRevVSLim;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilDftRvVSLim; /* BIN0 */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_tiFilIniVSLim; /* BIN0 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"

/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSLIM_START_SEC_CODE
#include "VSLim_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSLIM_F4111_Determiner_Condition_Configuration_Fonction(UInt8 vsctl_stvsctlinfo_par,
																					UInt8 ecu_bauthvsctlini_par,
																					UInt8 ext_bvslimcf_par);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4112_Determiner_Etat_Service(UInt8 ext_bvslimcf_par,
											  UInt8 ecu_bauthvsctlini_par,
											  UInt8 ext_bkeyoff_par,
											  UInt8 ext_stacvregvsctlreq_par,
											  UInt8 ext_stmodregvsctlreq_par,
											  UInt8 frm_bdeacirvvslim_par,
											  UInt8 frm_bdeacrvvslim_par,
											  UInt8 frm_bdifastdeacvsctlvslim_par,
											  UInt8 vsctl_stvsctlinfo_par,
											  UInt8 sftymgt_bdeacirvvslim_par,
											  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bmonrunvslim_ptr,
											  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdgovslim_ptr);


STATIC FUNC(void, AUTOMATIC) VSLIM_F4113_Determiner_Condition_Maintenance_Init_Secur(UInt8 ext_bkeyoff_par,
																					UInt8 frm_bdeacrvvslim_par,
																					UInt8 frm_bdeacirvvslim_par,
																					UInt8 frm_bdifastdeacvsctlvslim_par,
																					UInt8 sftymgt_bdeacirvvslim_par);

/*******************************************************************************
*
* Function Name : VSLIM_Fct_Mode
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Fct_Mode(UInt8 ECU_bAuthVSCtlIni_swc_in,
									 UInt8 Ext_bKeyOff_swc_in,
									 UInt8 Ext_bVSLimCf_swc_in,
									 UInt8 Ext_stAcvRegVSCtlReq_swc_in,
									 UInt8 Ext_stModRegVSCtlReq_swc_in,
									 UInt8 FRM_bDeacIrvVSLim_swc_in,
									 UInt8 FRM_bDeacRvVSLim_swc_in,
									 UInt8 FRM_bDiFastDeacVSCtlVSLim_swc_in,
									 UInt8 SftyMgt_bDeacIrvVSLim_swc_in,
									 UInt8 VSCtl_stVSCtlInfo_swc_in,
									 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLim_swc_out,
									 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLim_swc_out )
{
	/* SSTG REQ TAG : CSMT_CGMT08_2271.FR.03.2 */

	VSLIM_F4111_Determiner_Condition_Configuration_Fonction(VSCtl_stVSCtlInfo_swc_in,
															ECU_bAuthVSCtlIni_swc_in,
															Ext_bVSLimCf_swc_in);

	VSLIM_F4112_Determiner_Etat_Service(Ext_bVSLimCf_swc_in,
										  ECU_bAuthVSCtlIni_swc_in,
										  Ext_bKeyOff_swc_in,
										  Ext_stAcvRegVSCtlReq_swc_in,
										  Ext_stModRegVSCtlReq_swc_in,
										  FRM_bDeacIrvVSLim_swc_in,
										  FRM_bDeacRvVSLim_swc_in,
										  FRM_bDiFastDeacVSCtlVSLim_swc_in,
										  VSCtl_stVSCtlInfo_swc_in,
										  SftyMgt_bDeacIrvVSLim_swc_in,
										  VSCtl_bMonRunVSLim_swc_out,
										  VSCtl_bDgoVSLim_swc_out);



	VSLIM_F4113_Determiner_Condition_Maintenance_Init_Secur(Ext_bKeyOff_swc_in,
															FRM_bDeacRvVSLim_swc_in,
															FRM_bDeacIrvVSLim_swc_in,
															FRM_bDiFastDeacVSCtlVSLim_swc_in,
															SftyMgt_bDeacIrvVSLim_swc_in);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_F4111_Determiner_Condition_Configuration_Fonction
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4111_Determiner_Condition_Configuration_Fonction(UInt8 vsctl_stvsctlinfo_par,
																					UInt8 ecu_bauthvsctlini_par,
																					UInt8 ext_bvslimcf_par)
{
	/*SSTG REQ TAG : CSMT_CGMT08_2271.FR.42.0 */
	if((UInt32)DDS_FALSE != (UInt32)VSCtl_bCfVSLim)
	{
		if(	(VSLIM_STVSCTLINFO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par)	||
			((UInt32)DDS_TRUE != (UInt32)ecu_bauthvsctlini_par)		||
			((UInt32)DDS_TRUE != (UInt32)ext_bvslimcf_par)	)
		{
			/* do nothing */
		}
		else
		{
			VSCtl_bCfVSLim = DDS_FALSE;
		}
	}
	else
	{
		if(	(VSLIM_STVSCTLINFO_NOMINAL_20 != (UInt32)vsctl_stvsctlinfo_par)	||
			(((UInt32)DDS_TRUE != (UInt32)ext_bvslimcf_par)) )
		{
			VSCtl_bCfVSLim = DDS_TRUE;
		}
		else
		{
				/* do nothing */
		}
	}
}
/*******************************************************************************
*
* Function Name : VSLIM_F4112_Determiner_Etat_Service
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4112_Determiner_Etat_Service(UInt8 ext_bvslimcf_par,
																  UInt8 ecu_bauthvsctlini_par,
																  UInt8 ext_bkeyoff_par,
																  UInt8 ext_stacvregvsctlreq_par,
																  UInt8 ext_stmodregvsctlreq_par,
																  UInt8 frm_bdeacirvvslim_par,
																  UInt8 frm_bdeacrvvslim_par,
																  UInt8 frm_bdifastdeacvsctlvslim_par,
																  UInt8 vsctl_stvsctlinfo_par,
																  UInt8 sftymgt_bdeacirvvslim_par,
																  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bmonrunvslim_ptr,
																  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdgovslim_ptr)
{
	/*SSTG REQ TAG : CSMT_CGMT08_2271.FR.43.0*/


/* Etat_Service_LVV */

	UInt32 vsctl_tifilinivslim_tmp;

	switch((UInt32)VSCtl_stMonVSLim)
		{
		case VSLIM_STMONVSLIM_ARRET:
			if( (VSLIM_BVSLIMCF_PRESENT == (UInt32)ext_bvslimcf_par)
			&&((UInt32)DDS_FALSE == (UInt32)ext_bkeyoff_par)
			&&(VSLIM_STVSCTLINFO_ARRET != (UInt32)vsctl_stvsctlinfo_par)
			&&(VSLIM_STVSCTLINFO_VERIF_20 != (UInt32)vsctl_stvsctlinfo_par)
			&&(VSLIM_STVSCTLINFO_INIT_20 != (UInt32)vsctl_stvsctlinfo_par))
			{
				VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_VERIFICATION;
				vsctl_bmonrunvslim_prv= DDS_TRUE;
			}
			else
			{
				/* do nothing */
			}
			break;

		case VSLIM_STMONVSLIM_VERIFICATION:
			if( (VSLIM_BVSLIMCF_PRESENT != (UInt32)ext_bvslimcf_par)
				||((UInt32)DDS_FALSE != (UInt32)ext_bkeyoff_par)
				||(VSLIM_STVSCTLINFO_ARRET == (UInt32)vsctl_stvsctlinfo_par) )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
					VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
					vsctl_bdgovslim_prev = DDS_FALSE;
					vsctl_bmonrunvslim_prv= DDS_FALSE;
					VSCtl_bctDefRevVSLim = DDS_FALSE;
				}
			else if ( ((UInt32)DDS_FALSE != (UInt32)ecu_bauthvsctlini_par)
						&&(((UInt32)DDS_FALSE != (UInt32)frm_bdeacirvvslim_par)
						||((UInt32)sftymgt_bdeacirvvslim_par == (UInt32)DDS_TRUE)))
				{
						VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_IRREV;
				}


			else if((((UInt32)DDS_FALSE != (UInt32)ecu_bauthvsctlini_par)
				&&(((UInt32)DDS_FALSE != (UInt32)frm_bdeacrvvslim_par)
				||((UInt32)DDS_FALSE != (UInt32)frm_bdifastdeacvsctlvslim_par)
				||(VSLIM_STVSCTLINFO_DEFAUT_20 == (UInt32)vsctl_stvsctlinfo_par)))
				&&((UInt32)DDS_FALSE == (UInt32)frm_bdeacirvvslim_par)
				&&((UInt32)DDS_FALSE == (UInt32)sftymgt_bdeacirvvslim_par))
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_REV;
					VSCtl_ctDftRevVSLim = (UInt8)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_ctDftRevVSLim,
																		(UInt32)(1 * BIN0), (UInt32)(0 * BIN0));
					VSCtl_tiFilDftRvVSLim = VSCtl_tiDftRvVSLim_C;
				}

			else if(((UInt32)DDS_FALSE != (UInt32)ecu_bauthvsctlini_par)
						&&((UInt32)DDS_FALSE == (UInt32)frm_bdeacrvvslim_par)
						&&((UInt32)DDS_FALSE == (UInt32)frm_bdeacirvvslim_par)
						&&((UInt32)DDS_FALSE == (UInt32)frm_bdifastdeacvsctlvslim_par)
						&&(VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par) )
				{
							VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_INITIALISATION;
							VSCtl_tiFilIniVSLim = VSCtl_tiIni_VSLim_C;
				}

			else
				{
						/* do nothing */
				}
		break;

		case VSLIM_STMONVSLIM_INITIALISATION:
				if( (VSLIM_BVSLIMCF_PRESENT != (UInt32)ext_bvslimcf_par)
				||((UInt32)DDS_FALSE != (UInt32)ext_bkeyoff_par)
				||(VSLIM_STVSCTLINFO_ARRET == (UInt32)vsctl_stvsctlinfo_par) )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
					VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
					vsctl_bdgovslim_prev = DDS_FALSE;
					vsctl_bmonrunvslim_prv= DDS_FALSE;
					VSCtl_bctDefRevVSLim = DDS_FALSE;

				}
				else if((UInt32)DDS_FALSE != (UInt32)frm_bdeacirvvslim_par)
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_IRREV;
				}
				else if( ((UInt32)DDS_FALSE != (UInt32)frm_bdeacrvvslim_par)
				||((UInt32)DDS_FALSE != (UInt32)frm_bdifastdeacvsctlvslim_par)
				||(VSLIM_STVSCTLINFO_DEFAUT_20 == (UInt32)vsctl_stvsctlinfo_par) )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_REV;
					VSCtl_tiFilDftRvVSLim = VSCtl_tiDftRvVSLim_C;
					VSCtl_ctDftRevVSLim = (UInt8)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_ctDftRevVSLim,
																		(UInt32)(1 * BIN0), (UInt32)(0 * BIN0));
				}
				else if((UInt32)(0 * BIN0) == (UInt32)VSCtl_tiFilIniVSLim)
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_NOMINAL;
				}
				else
				{
					/* during actions */
					vsctl_tifilinivslim_tmp = DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiFilIniVSLim,
																	(UInt32)(1 * BIN0), (UInt32)(0 * BIN0));
					VSCtl_tiFilIniVSLim = (UInt8)DDS_M_MAX(vsctl_tifilinivslim_tmp, (UInt32)(0*BIN0));
				}
			break;

			case VSLIM_STMONVSLIM_NOMINAL:
				if( (VSLIM_BVSLIMCF_PRESENT != (UInt32)ext_bvslimcf_par)
				||((UInt32)DDS_FALSE != (UInt32)ext_bkeyoff_par)
				||(VSLIM_STVSCTLINFO_ARRET == (UInt32)vsctl_stvsctlinfo_par) )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
					VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
					vsctl_bdgovslim_prev = DDS_FALSE;
					vsctl_bmonrunvslim_prv= DDS_FALSE;
					VSCtl_bctDefRevVSLim = DDS_FALSE;

				}
				else if((UInt32)DDS_FALSE != (UInt32)frm_bdeacirvvslim_par)
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_IRREV;
				}
				else if( ((UInt32)DDS_FALSE != (UInt32)frm_bdeacrvvslim_par)
				||((UInt32)DDS_FALSE != (UInt32)frm_bdifastdeacvsctlvslim_par)
				||(VSLIM_STVSCTLINFO_DEFAUT_20 == (UInt32)vsctl_stvsctlinfo_par) )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_REV;
					VSCtl_tiFilDftRvVSLim = VSCtl_tiDftRvVSLim_C;
					VSCtl_ctDftRevVSLim = (UInt8)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_ctDftRevVSLim,
																		(UInt32)(1 * BIN0), (UInt32)(0 * BIN0));
				}
				else
				{
					/* do nothing */
				}
			break;

			case VSLIM_STMONVSLIM_DEFAUT_REV:
				if( (VSLIM_BVSLIMCF_PRESENT != (UInt32)ext_bvslimcf_par)
				||((UInt32)DDS_FALSE != (UInt32)ext_bkeyoff_par)
				||(VSLIM_STVSCTLINFO_ARRET == (UInt32)vsctl_stvsctlinfo_par) )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
					VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
					vsctl_bdgovslim_prev = DDS_FALSE;
					vsctl_bmonrunvslim_prv= DDS_FALSE;
					VSCtl_bctDefRevVSLim = DDS_FALSE;

				}
				else if((UInt32)DDS_FALSE != (UInt32)frm_bdeacirvvslim_par)
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_IRREV;
				}
				else if( (UInt32)(0*BIN0) == (UInt32)VSCtl_ctDftRevVSLim)
				{
					vsctl_bdgovslim_prev = DDS_TRUE;
					VSCtl_bctDefRevVSLim  = DDS_TRUE;
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_DEFAUT_IRREV;
				}
				else if( ( ( (UInt32)DDS_FALSE == (UInt32)frm_bdeacrvvslim_par)
				&&((UInt32)DDS_FALSE == (UInt32)frm_bdifastdeacvsctlvslim_par)
				&&(VSLIM_STVSCTLINFO_NOMINAL_20 == (UInt32)vsctl_stvsctlinfo_par)
				&&(VSLIM_STMODREGVSCTLREQ_REGULATION_LVV != (UInt32)ext_stmodregvsctlreq_par)
				&&(VSLIM_STACVREGVSCTLREQ_REGULATION_LVV != (UInt32)ext_stacvregvsctlreq_par)
				/* <PRQA_COMMENT><3355> always true due to spec </3355></PRQA_COMMENT> */
				&&((UInt32)(0*BIN0) != (UInt32)VSCtl_ctDftRevVSLim)
				&&( (UInt32)(0*BIN0) == (UInt32)VSCtl_tiFilDftRvVSLim) )  )
				{
					VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_INITIALISATION;
					VSCtl_tiFilIniVSLim = VSCtl_tiIni_VSLim_C;
				}
				else
				{
					/* during actions */
					VSCtl_tiFilDftRvVSLim = (UInt8)DDS_M_LIMITED_DECREMENT((UInt32)VSCtl_tiFilDftRvVSLim,
											(UInt32)(1 * BIN0), (UInt32)(0 * BIN0));
				}
			break;

			case VSLIM_STMONVSLIM_DEFAUT_IRREV:
				if( (VSLIM_BVSLIMCF_PRESENT != (UInt32)ext_bvslimcf_par)
				|| ((UInt32)DDS_FALSE != (UInt32)ext_bkeyoff_par))
				{

				VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
				VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
				vsctl_bdgovslim_prev = DDS_FALSE;
				vsctl_bmonrunvslim_prv= DDS_FALSE;
				VSCtl_bctDefRevVSLim = DDS_FALSE;

				}
				else
				{
					/* during actions */
				}
			break;

			default:

				VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
				VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
				vsctl_bdgovslim_prev = DDS_FALSE;
				vsctl_bmonrunvslim_prv= DDS_FALSE;
				VSCtl_bctDefRevVSLim = DDS_FALSE;
			break;
		}

		/* Update previous value */

		*vsctl_bdgovslim_ptr = vsctl_bdgovslim_prev;
		*vsctl_bmonrunvslim_ptr = vsctl_bmonrunvslim_prv;

}

/*******************************************************************************
*
* Function Name : VSLIM_F4113_Determiner_Condition_Maintenance_Init_Secur
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSLIM_F4113_Determiner_Condition_Maintenance_Init_Secur(UInt8 ext_bkeyoff_par,
																					UInt8 frm_bdeacrvvslim_par,
																					UInt8 frm_bdeacirvvslim_par,
																					UInt8 frm_bdifastdeacvsctlvslim_par,
																					UInt8 sftymgt_bdeacirvvslim_par)
{

/*SSTG REQ TAG : CSMT_CGMT08_2271.FR.44.0*/

  UInt32 vslim_uvalue;

    vslim_uvalue = 0;

    if((UInt32)VSCtl_bCfVSLim == (UInt32)DDS_TRUE)
    {
        DDS_M_BIT_SET32(vslim_uvalue, 1);
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)ext_bkeyoff_par == (UInt32)DDS_TRUE)
    {
        DDS_M_BIT_SET32(vslim_uvalue, 0);
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)VSCtl_bctDefRevVSLim == (UInt32)DDS_TRUE)
    {
        DDS_M_BIT_SET32(vslim_uvalue, 2);
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)frm_bdeacrvvslim_par == (UInt32)DDS_TRUE)
    {
        DDS_M_BIT_SET32(vslim_uvalue, 3);
    }
    else
    {
        /* Nothing to do */
    }

    if((UInt32)frm_bdeacirvvslim_par == (UInt32)DDS_TRUE)
    {
        DDS_M_BIT_SET32(vslim_uvalue, 4);
    }
    else
    {
        /* Nothing to do */
    }

	if((UInt32)sftymgt_bdeacirvvslim_par == (UInt32)DDS_TRUE)
	{
        DDS_M_BIT_SET32(vslim_uvalue, 5);
	}
	else
	{
		/* Nothing to do */
	}

    if((UInt32)frm_bdifastdeacvsctlvslim_par == (UInt32)DDS_TRUE)
	{
        DDS_M_BIT_SET32(vslim_uvalue, 6);
	}
	else
	{
		/* Nothing to do */
	}

    VSCtl_stDeacVSLimReq_Ini = (UInt8)vslim_uvalue;

}
/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_Fct_Mode_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Fct_Mode_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLim_swc_out,
                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLim_swc_out)
{
    /* ---- Init Outputs ---- */
	*VSCtl_bMonRunVSLim_swc_out = DDS_FALSE;
			vsctl_bmonrunvslim_prv = DDS_FALSE;

	*VSCtl_bDgoVSLim_swc_out = DDS_FALSE;
			vsctl_bdgovslim_prev = DDS_FALSE;

	VSCtl_stMonVSLim = (UInt8)VSLIM_STMONVSLIM_ARRET;
	VSCtl_stDeacVSLimReq_Ini = (UInt8)(127 * BIN0);

    /* ---- Init Global Datas ---- */
    VSCtl_bCfVSLim	=  DDS_TRUE;
	VSCtl_ctDftRevVSLim = VSCtl_ctTolRvDftVSLim_C;
	VSCtl_bctDefRevVSLim = DDS_FALSE;
	VSCtl_tiFilIniVSLim = VSCtl_tiIni_VSLim_C;
	VSCtl_tiFilDftRvVSLim = VSCtl_tiDftRvVSLim_C;
}



#define VSLIM_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSLim_MemMap.h"

