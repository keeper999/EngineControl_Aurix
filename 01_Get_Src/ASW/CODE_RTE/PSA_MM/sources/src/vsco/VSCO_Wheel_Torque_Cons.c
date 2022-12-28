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
* Ref X:\integration_view_00PSASWC_D700D02\blois_psa_sstg\Software\Appli\VSCo\src\VSCO_Wheel_Torque_Cons.c
* Version int :/main/L01_01/2 Date: 24/2/2011 10 h 22 m User:esnault 
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL2
*    comments :For VSCo 10.0, correction after TU
* Version dev :\main\branch_veillard_vsco\8 Date: 18/2/2011 8 h 52 m User:veillard 
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL2
*    comments :For VSCo 10.0, correction after TU
* Version dev :\main\branch_veillard_vsco\7 Date: 17/2/2011 17 h 52 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL2
*    comments :For VSCo 10.0, correction after TU
* Version int :/main/L01_01/1 Date: 4/2/2011 17 h 29 m User:esnault
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\6 Date: 27/1/2011 12 h 22 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\5 Date: 27/1/2011 10 h 47 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\4 Date: 25/1/2011 15 h 25 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\3 Date: 14/12/2010 17 h 47 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\2 Date: 13/12/2010 10 h 46 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\1 Date: 10/12/2010 16 h 30 m User:veillard
*    TWK_model:VSCO_Wheel_Torque_Cons_L01_010_IMPL1
*    comments :For VSCo 10.0
*
*******************************************************************************/


/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSCo.h"


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

/* 16-bits variables definition */
#define VSCO_START_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehMinReq; /* BIN10 */
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehMaxReq; /* BIN10 */
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehWhlMinSat; /* BIN10 */
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variables definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_aVeh;
extern VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVehMin;
extern VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVehMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtlaVehMinSat; /* BIN0 */
#define VSCO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"



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
#define VSCO_START_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMinSat_SatMax_C = (CONST(SInt16, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqWhlMinSat_SatMin_C = (CONST(SInt16, AUTOMATIC))(-4000 * BIN0);
#define VSCO_STOP_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"

/* 8-bits scalar calibration definition */
#define VSCO_START_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) VSCtl_bTqWhlThPTMinMod_no2_C = DDS_FALSE;
#define VSCO_STOP_SEC_CALIB_8BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define VSCO_START_SEC_VAR_32BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsctl_stctl_tqwhlmin_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bauthanttqwhlmin_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_stctl_tqwhlmax_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_bauthanttqwhlmax_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_btqwhlminsat_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_stctl_aveh_cpy;
#define VSCO_STOP_SEC_VAR_32BIT
#include "VSCo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVehMinPrev;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_aVehMaxPrev;
#define VSCO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"



/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSCO_START_SEC_CODE
#include "VSCo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6121_Min_Wheel_Torque_Cons_Deter(SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
																    UInt8 vsctl_stctl_avehvsreg_par,
																    UInt8 vsctl_stctl_avehdvsreg_par,
																    UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
																    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminreq_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmin_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmin_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F6122_Max_Wheel_Torque_Cons_Deter(UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
																    UInt8  vsctl_stctl_avehvslim_par,
																    UInt8  vsctl_stctl_avehvsmax_par,
																    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlmaxreq_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmax_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmax_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F6123_Wheel_Torque_Lim_Cons_Deter(UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlthptmin_par,
																    SInt16 vsctl_tqwhlthptpotmin_par,
																    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminsat_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_btqwhlminsat_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F61211_Min_Wheel_Torque_Cmd_Mode_Deter(UInt8 vsctl_stctl_avehdvsreg_par,
																		 UInt8 vsctl_stctl_avehvsreg_par,
																		 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmin_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F61212_Min_Wheel_Torque_Ant_Auth_Deter(UInt8 vsctl_stctl_tqwhlmin_par,
	                                                                     UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
	                                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmin_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F61213_Min_Wheel_Torque_Cons_Calc(UInt8 vsctl_stctl_tqwhlmin_par,
																    UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
										   							CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminreq_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F61221_Max_Wheel_Torque_Cmd_Mode_Deter(UInt8 vsctl_stctl_avehvslim_par,
							 	                                         UInt8 vsctl_stctl_avehvsmax_par,
	                                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmax_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F61222_Max_Wheel_Torque_Ant_Auth_Deter(UInt8 vsctl_stctl_tqwhlmax_par,
												                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmax_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F61223_Max_Wheel_Torque_Cons_Calc(UInt8  vsctl_stctl_tqwhlmax_par,
																    UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
	                                       							CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlmaxreq_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F61231_Wheel_Torque_Lim_Cmd_Mode_Deter(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_btqwhlminsat_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F61232_Wheel_Torque_Lim_Cons_Deter(UInt8  vsctl_btqwhlminsat_par,
							 										 UInt16 vsctl_mveh_par,
							 									     UInt16 vsctl_rdwhl_par,
							 										 SInt16 vsctl_ares_par,
							 										 SInt16 vsctl_tqwhlthptmin_par,
							 										 SInt16 vsctl_tqwhlthptpotmin_par,
																	 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminsat_ptr);

/*******************************************************************************
*
* Function Name : VSCO_Wheel_Torque_Cons
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Wheel_Torque_Cons(SInt16 VSCtl_tqWhlPTMin_swc_in, /* BIN1 */
										     SInt16 VSCtl_tqWhlPTMax_swc_in, /* BIN1 */
										     UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
										     UInt8 VSCtl_stCtl_aVehDVSReg_swc_in,
										     UInt8 VSCtl_stCtl_aVehVSLim_swc_in,
										     UInt8 VSCtl_stCtl_aVehVSMax_swc_in,
										     UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
										     UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
										     SInt16 VSCtl_aRes_swc_in, /* BIN10 */
										     SInt16 VSCtl_tqWhlThPTMin_swc_in, /* BIN1 */
										     SInt16 VSCtl_tqWhlThPTPotMin_swc_in, /* BIN1 */
										     UInt8 VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
										     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinReq_swc_out, /* BIN1 */
										     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMaxReq_swc_out, /* BIN1 */
										     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMin_swc_out,
										     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMax_swc_out,
										     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMin_swc_out,
										     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMax_swc_out,
										     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinSat_swc_out, /* BIN1 */
										     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bTqWhlMinSat_swc_out )
{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.09.2 */

	vsctl_stctl_aveh_cpy = (UInt32)VSCtl_stCtl_aVeh;



	VSCO_F6121_Min_Wheel_Torque_Cons_Deter(VSCtl_tqWhlPTMin_swc_in,
										   VSCtl_tqWhlPTMax_swc_in,
										   VSCtl_stCtl_aVehVSReg_swc_in,
										   VSCtl_stCtl_aVehDVSReg_swc_in,
										   VSCtl_mVeh_swc_in,
										   VSCtl_rdWhl_swc_in,
										   VSCtl_aRes_swc_in,
										   VSCtl_bDrvOvrdVSReg_spdVeh_swc_in,
										   VSCtl_tqWhlMinReq_swc_out,
										   VSCtl_stCtl_tqWhlMin_swc_out,
										   VSCtl_bAuthAntTqWhlMin_swc_out);



	VSCO_F6122_Max_Wheel_Torque_Cons_Deter(VSCtl_mVeh_swc_in,
										   VSCtl_rdWhl_swc_in,
										   VSCtl_aRes_swc_in,
										   VSCtl_tqWhlPTMin_swc_in,
										   VSCtl_tqWhlPTMax_swc_in,
										   VSCtl_stCtl_aVehVSLim_swc_in,
										   VSCtl_stCtl_aVehVSMax_swc_in,
										   VSCtl_tqWhlMaxReq_swc_out,
										   VSCtl_stCtl_tqWhlMax_swc_out,
										   VSCtl_bAuthAntTqWhlMax_swc_out);


	VSCO_F6123_Wheel_Torque_Lim_Cons_Deter(VSCtl_mVeh_swc_in,
										   VSCtl_rdWhl_swc_in,
										   VSCtl_aRes_swc_in,
										   VSCtl_tqWhlThPTMin_swc_in,
										   VSCtl_tqWhlThPTPotMin_swc_in,
										   VSCtl_tqWhlMinSat_swc_out,
										   VSCtl_bTqWhlMinSat_swc_out);



}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_F6121_Min_Wheel_Torque_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6121_Min_Wheel_Torque_Cons_Deter(SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
																    UInt8 vsctl_stctl_avehvsreg_par,
																    UInt8 vsctl_stctl_avehdvsreg_par,
																    UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
																    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminreq_ptr, /* BIN1 */
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmin_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmin_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.10.1 */

	VSCO_F61211_Min_Wheel_Torque_Cmd_Mode_Deter(vsctl_stctl_avehdvsreg_par,
												vsctl_stctl_avehvsreg_par,
												vsctl_stctl_tqwhlmin_ptr);



	VSCO_F61212_Min_Wheel_Torque_Ant_Auth_Deter(*vsctl_stctl_tqwhlmin_ptr,
											   vsctl_bdrvovrdvsreg_spdveh_par,
											   vsctl_bauthanttqwhlmin_ptr);


	VSCO_F61213_Min_Wheel_Torque_Cons_Calc(*vsctl_stctl_tqwhlmin_ptr,
										   vsctl_mveh_par,
										   vsctl_rdwhl_par,
										   vsctl_ares_par,
										   vsctl_tqwhlptmin_par,
										   vsctl_tqwhlptmax_par,
										   vsctl_tqwhlminreq_ptr);




}


/*******************************************************************************
*
* Function Name : VSCO_F6122_Max_Wheel_Torque_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6122_Max_Wheel_Torque_Cons_Deter(UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
																    UInt8  vsctl_stctl_avehvslim_par,
																    UInt8  vsctl_stctl_avehvsmax_par,
																    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlmaxreq_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmax_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmax_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.15.1 */

	VSCO_F61221_Max_Wheel_Torque_Cmd_Mode_Deter(vsctl_stctl_avehvslim_par,
	                                            vsctl_stctl_avehvsmax_par,
	                                            vsctl_stctl_tqwhlmax_ptr);

	VSCO_F61222_Max_Wheel_Torque_Ant_Auth_Deter(*vsctl_stctl_tqwhlmax_ptr,
	                                            vsctl_bauthanttqwhlmax_ptr);



	VSCO_F61223_Max_Wheel_Torque_Cons_Calc(*vsctl_stctl_tqwhlmax_ptr,
										   vsctl_mveh_par,
										   vsctl_rdwhl_par,
										   vsctl_ares_par,
										   vsctl_tqwhlptmin_par,
										   vsctl_tqwhlptmax_par,
										   vsctl_tqwhlmaxreq_ptr);

}


/*******************************************************************************
*
* Function Name : VSCO_F6123_Wheel_Torque_Lim_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6123_Wheel_Torque_Lim_Cons_Deter(UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlthptmin_par,
																    SInt16 vsctl_tqwhlthptpotmin_par,
																    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminsat_ptr,
																    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_btqwhlminsat_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.42.0 */

	VSCO_F61231_Wheel_Torque_Lim_Cmd_Mode_Deter(vsctl_btqwhlminsat_ptr);


	VSCO_F61232_Wheel_Torque_Lim_Cons_Deter(*vsctl_btqwhlminsat_ptr,
											vsctl_mveh_par,
											vsctl_rdwhl_par,
											vsctl_ares_par,
											vsctl_tqwhlthptmin_par,
											vsctl_tqwhlthptpotmin_par,
											vsctl_tqwhlminsat_ptr);

}


/*******************************************************************************
*
* Function Name : VSCO_F61211_Min_Wheel_Torque_Cmd_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61211_Min_Wheel_Torque_Cmd_Mode_Deter(UInt8 vsctl_stctl_avehdvsreg_par,
																		 UInt8 vsctl_stctl_avehvsreg_par,
																		 CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmin_ptr)
{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.40.0 */

	/* MODE_CONTROLE_COUPLE_ROUE_MIN */
	switch(vsctl_stctl_tqwhlmin_local)
	{
		case VSCO_ARRET:
			if((vsctl_stctl_aveh_cpy == VSCO_CONTROLE)										&&
			   (((UInt32)vsctl_stctl_avehvsreg_par != VSCO_VSCTL_STCTL_AVEHVSREG_ARRET)
			   || ((UInt32)vsctl_stctl_avehdvsreg_par != VSCO_ARRET)))
			{
				vsctl_stctl_tqwhlmin_local = VSCO_CONTROLE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		case VSCO_CONTROLE:
			if((vsctl_stctl_aveh_cpy != VSCO_CONTROLE)										||
			   (((UInt32)vsctl_stctl_avehvsreg_par == VSCO_VSCTL_STCTL_AVEHVSREG_ARRET)
			   && ((UInt32)vsctl_stctl_avehdvsreg_par == VSCO_ARRET)))
			{
				vsctl_stctl_tqwhlmin_local = VSCO_ARRET;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		default:
			vsctl_stctl_tqwhlmin_local = VSCO_ARRET;
		break;
	}

	*vsctl_stctl_tqwhlmin_ptr = (UInt8)vsctl_stctl_tqwhlmin_local;

}

/*******************************************************************************
*
* Function Name : VSCO_F61212_Min_Wheel_Torque_Ant_Auth_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61212_Min_Wheel_Torque_Ant_Auth_Deter(UInt8 vsctl_stctl_tqwhlmin_par,
	                                                                     UInt8 vsctl_bdrvovrdvsreg_spdveh_par,
	                                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmin_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.12.1 */

	/* AUTORISATION_ANTICIPATION_COUPLE_ROUE_MIN */

	UInt8 vsctl_bctlefc_avehmin_cpy;

	vsctl_bctlefc_avehmin_cpy = VSCtl_bCtlEfc_aVehMin;

	switch(vsctl_bauthanttqwhlmin_local)
	{
		case (UInt32)DDS_FALSE:
			if(((UInt32)vsctl_stctl_tqwhlmin_par 	== VSCO_CONTROLE) 		&&
			   ((UInt32)vsctl_bctlefc_avehmin_cpy 	== (UInt32)DDS_TRUE)	&&
			   ((UInt32)VSCtl_bCtlEfc_aVehMinPrev 	== (UInt32)DDS_TRUE)	&&
			   ((UInt32)vsctl_bdrvovrdvsreg_spdveh_par == (UInt32)DDS_FALSE))
			{
				vsctl_bauthanttqwhlmin_local = (UInt32)DDS_TRUE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		case (UInt32)DDS_TRUE:
			if(((UInt32)vsctl_stctl_tqwhlmin_par 	!= VSCO_CONTROLE)		||
			   ((UInt32)vsctl_bctlefc_avehmin_cpy 	== (UInt32)DDS_FALSE)	||
			   ((UInt32)vsctl_bdrvovrdvsreg_spdveh_par == (UInt32)DDS_TRUE))
			{
				vsctl_bauthanttqwhlmin_local = (UInt32)DDS_FALSE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		default:
			vsctl_bauthanttqwhlmin_local = (UInt32)DDS_FALSE;
		break;
	}

	VSCtl_bCtlEfc_aVehMinPrev = vsctl_bctlefc_avehmin_cpy;
	*vsctl_bauthanttqwhlmin_ptr = (UInt8)vsctl_bauthanttqwhlmin_local;

}

/*******************************************************************************
*
* Function Name : VSCO_F61213_Min_Wheel_Torque_Cons_Calc
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61213_Min_Wheel_Torque_Cons_Calc(UInt8 vsctl_stctl_tqwhlmin_par,
																    UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
										   							CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminreq_ptr)
{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.14.2 */

	SInt32 F61213_mult_input,F61213_mult_result;

	SInt8 nb_shift;

	if(VSCO_ARRET == (UInt32)vsctl_stctl_tqwhlmin_par)
	{
		*vsctl_tqwhlminreq_ptr = VSCO_TORQUE_CONS_16000_BIN1_NEG;
	}
	else
	{
		/* [-20;20]BIN10 = [-10;10]BIN10 - [10;10]BIN10 */
		F61213_mult_input = (SInt32)VSCtl_aVehMinReq - (SInt32)vsctl_ares_par;

		/* [-200;200]BIN17 = [-20;20]BIN10 * [0.0078125;10]BIN7 */
		F61213_mult_input = F61213_mult_input * (SInt32)vsctl_rdwhl_par;


		nb_shift = (SInt8)17;

		/* [-200;200]BIN17 * [1;10000]BIN0 */
		F61213_mult_result = DDS_M_DYNAMIC_MULT_S32(F61213_mult_input,
													(SInt32)vsctl_mveh_par,
													&nb_shift);

		/* [-2 000000;2 000000]*BIN1 */
		F61213_mult_result = DDS_M_RESTORE_BINPOINT_SINT32(F61213_mult_result, (SInt8)((SInt32)nb_shift - (SInt32)1));


		/* [-16000;16000]BIN1 */
		*vsctl_tqwhlminreq_ptr = (SInt16)DDS_M_SATURATION_V2(F61213_mult_result,
												             (SInt32)vsctl_tqwhlptmin_par,
												             (SInt32)vsctl_tqwhlptmax_par);
	}

}

/*******************************************************************************
*
* Function Name : VSCO_F61221_Max_Wheel_Torque_Cmd_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61221_Max_Wheel_Torque_Cmd_Mode_Deter(UInt8 vsctl_stctl_avehvslim_par,
							 	                                         UInt8 vsctl_stctl_avehvsmax_par,
	                                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlmax_ptr)
{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.41.0 */

	/* MODE_CONTROLE_COUPLE_ROUE_MAX */
	switch(vsctl_stctl_tqwhlmax_local)
	{
		case VSCO_ARRET:
			if((vsctl_stctl_aveh_cpy == VSCO_CONTROLE) 									&&
			   (((UInt32)vsctl_stctl_avehvslim_par 	!= VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET)
				|| ((UInt32)vsctl_stctl_avehvsmax_par 	!= VSCO_VSCTL_STCTL_AVEHVSMAX_ARRET)))
			{
				vsctl_stctl_tqwhlmax_local = VSCO_CONTROLE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		case VSCO_CONTROLE:
			if((vsctl_stctl_aveh_cpy != VSCO_CONTROLE)									||
			   (((UInt32)vsctl_stctl_avehvslim_par 		== VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET)
				&&((UInt32)vsctl_stctl_avehvsmax_par 	== VSCO_VSCTL_STCTL_AVEHVSMAX_ARRET)))
			{
				vsctl_stctl_tqwhlmax_local = VSCO_ARRET;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		default:
			vsctl_stctl_tqwhlmax_local = VSCO_ARRET;
		break;
	}

	*vsctl_stctl_tqwhlmax_ptr = (UInt8)vsctl_stctl_tqwhlmax_local;
}


/*******************************************************************************
*
* Function Name : VSCO_F61222_Max_Wheel_Torque_Ant_Auth_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61222_Max_Wheel_Torque_Ant_Auth_Deter(UInt8 vsctl_stctl_tqwhlmax_par,
												                         CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bauthanttqwhlmax_ptr)

{

	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.17.2 */

	/* AUTORISATION_ANTICIPATION_COUPLE_ROUE_MAX */
	UInt8 vsctl_bctlefc_avehmax_cpy;

	vsctl_bctlefc_avehmax_cpy = VSCtl_bCtlEfc_aVehMax;

	switch(vsctl_bauthanttqwhlmax_local)
	{
		case (UInt32)DDS_FALSE:
			if(((UInt32)vsctl_stctl_tqwhlmax_par == VSCO_CONTROLE) &&
			   ((UInt32)vsctl_bctlefc_avehmax_cpy == (UInt32)DDS_TRUE) &&
			   ((UInt32)VSCtl_bCtlEfc_aVehMaxPrev == (UInt32)DDS_TRUE))
			{
				vsctl_bauthanttqwhlmax_local = (UInt32)DDS_TRUE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		case (UInt32)DDS_TRUE:
			if(((UInt32)vsctl_stctl_tqwhlmax_par != VSCO_CONTROLE) ||
			   ((UInt32)vsctl_bctlefc_avehmax_cpy == (UInt32)DDS_FALSE))
			{
				vsctl_bauthanttqwhlmax_local = (UInt32)DDS_FALSE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		default:
			vsctl_bauthanttqwhlmax_local = (UInt32)DDS_FALSE;
		break;

	}


	VSCtl_bCtlEfc_aVehMaxPrev = vsctl_bctlefc_avehmax_cpy;
	*vsctl_bauthanttqwhlmax_ptr = (UInt8)vsctl_bauthanttqwhlmax_local;
}

/*******************************************************************************
*
* Function Name : VSCO_F61223_Max_Wheel_Torque_Cons_Calc
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61223_Max_Wheel_Torque_Cons_Calc(UInt8  vsctl_stctl_tqwhlmax_par,
																    UInt16 vsctl_mveh_par,
																    UInt16 vsctl_rdwhl_par,
																    SInt16 vsctl_ares_par,
																    SInt16 vsctl_tqwhlptmin_par,
																    SInt16 vsctl_tqwhlptmax_par,
	                                       							CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlmaxreq_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.19.2 */

	SInt32 F61223_mult_input,F61223_mult_result;
	SInt8 nb_shift;

	if(VSCO_ARRET == (UInt32)vsctl_stctl_tqwhlmax_par)
	{
		*vsctl_tqwhlmaxreq_ptr = VSCO_TORQUE_CONS_16000_BIN1_POS;
	}
	else
	{
		/* [-20;20]BIN10 = [-10;10]BIN10 - [10;10]BIN10 */
		F61223_mult_input = (SInt32)VSCtl_aVehMaxReq - (SInt32)vsctl_ares_par;

		/* [-200;200]BIN17 = ( [-20;20]BIN10 * [0.0078125;10]BIN7 ) */
		F61223_mult_input = F61223_mult_input * (SInt32)vsctl_rdwhl_par;

		nb_shift = (SInt8)17;

		/* [-200;200]BIN17 * [1;10000]BIN0 */
		F61223_mult_result = DDS_M_DYNAMIC_MULT_S32(F61223_mult_input,
                                                   (SInt32)vsctl_mveh_par,
                                                   &nb_shift);


		/* [-2 000000;2 000000]*BIN1 */
		F61223_mult_result = DDS_M_RESTORE_BINPOINT_SINT32(F61223_mult_result, (SInt8)((SInt32)nb_shift - (SInt32)1));


		/* [-16000;16000]BIN1 */
		*vsctl_tqwhlmaxreq_ptr = (SInt16)DDS_M_SATURATION_V2(F61223_mult_result,
															(SInt32)vsctl_tqwhlptmin_par,
															(SInt32)vsctl_tqwhlptmax_par);

	}

}


/*******************************************************************************
*
* Function Name : VSCO_F61231_Wheel_Torque_Lim_Cmd_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61231_Wheel_Torque_Lim_Cmd_Mode_Deter(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_btqwhlminsat_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.43.0 */

	/* MODE_CONTROLE_LIMITATION_COUPLE_ROUE */
	UInt8 vsctl_stctlavehminsat_cpy;
	vsctl_stctlavehminsat_cpy = VSCtl_stCtlaVehMinSat;

	switch(vsctl_btqwhlminsat_local)
	{
		case (UInt32)DDS_FALSE:
			if((vsctl_stctl_aveh_cpy 		== VSCO_CONTROLE) 					&&
			   ((UInt32)vsctl_stctlavehminsat_cpy 	!= VSCO_STCTLAVEHMINSAT_ARRET))
			{
				vsctl_btqwhlminsat_local = (UInt32)DDS_TRUE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		case (UInt32)DDS_TRUE:
			if((vsctl_stctl_aveh_cpy 		!= VSCO_CONTROLE) 					||
			   ((UInt32)vsctl_stctlavehminsat_cpy 	== VSCO_STCTLAVEHMINSAT_ARRET))
			{
				vsctl_btqwhlminsat_local = (UInt32)DDS_FALSE;
			}

			else	 /* during actions */
			{
				/* do nothing, stay in this state */
			}
		break;

		default:
			vsctl_btqwhlminsat_local = (UInt32)DDS_FALSE;
		break;


	}

	*vsctl_btqwhlminsat_ptr = (UInt8)vsctl_btqwhlminsat_local;

}

/*******************************************************************************
*
* Function Name : VSCO_F61232_Wheel_Torque_Lim_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F61232_Wheel_Torque_Lim_Cons_Deter(UInt8  vsctl_btqwhlminsat_par,
							 										 UInt16 vsctl_mveh_par,
							 									     UInt16 vsctl_rdwhl_par,
							 										 SInt16 vsctl_ares_par,
							 										 SInt16 vsctl_tqwhlthptmin_par,
							 										 SInt16 vsctl_tqwhlthptpotmin_par,
																	 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlminsat_ptr)

{
	/* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.44.0 */

	SInt32 sub_tmp, mux_tmp, result_mux;
	SInt8 nb_shift;
	SInt32 add_tmp;


	if((UInt32)DDS_FALSE == (UInt32)vsctl_btqwhlminsat_par)
	{
		*vsctl_tqwhlminsat_ptr = VSCO_TORQUE_CONS_16000_BIN1_NEG;
	}


	else
	{
		/* [-20;20]BIN10 = [-10;10]BIN10 - [-10;10]BIN10 */
		sub_tmp = (SInt32)VSCtl_aVehWhlMinSat - (SInt32)vsctl_ares_par;


		/* [-200;200]BIN17 = [1/128; 10]BIN7 * [-20;20]BIN10 */
		mux_tmp = (SInt32)vsctl_rdwhl_par * sub_tmp;

		nb_shift = (SInt8)17;

		/* [-200;200]*BIN17 * [1;10000]*BIN0 */
		result_mux = DDS_M_DYNAMIC_MULT_S32(mux_tmp,
											(SInt32)vsctl_mveh_par,
											&nb_shift);

		/* [-2 000000;2 000000]*BIN1 */
		result_mux = DDS_M_RESTORE_BINPOINT_SINT32(result_mux, (SInt8)((SInt32)nb_shift - (SInt32)1));


		if((UInt32)DDS_FALSE == (UInt32)VSCtl_bTqWhlThPTMinMod_no2_C)
		{
			add_tmp = result_mux + (SInt32)vsctl_tqwhlthptmin_par;

		}
		else
		{
			add_tmp = result_mux + (SInt32)vsctl_tqwhlthptpotmin_par;
		}

		add_tmp = DDS_M_SATURATION_V2(add_tmp,
									          ((SInt32)VSCtl_tqWhlMinSat_SatMin_C * BIN1),
									          ((SInt32)VSCtl_tqWhlMinSat_SatMax_C * BIN1));

		*vsctl_tqwhlminsat_ptr = (SInt16)DDS_M_LIMIT(add_tmp,
													 (SInt32)VSCO_TORQUE_CONS_16000_BIN1_NEG,
													 (SInt32)VSCO_TORQUE_CONS_16000_BIN1_POS);

	}

}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_Wheel_Torque_Cons_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Wheel_Torque_Cons_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinReq_swc_out, /* BIN1 */
												  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMaxReq_swc_out, /* BIN1 */
												  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMin_swc_out,
												  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bAuthAntTqWhlMax_swc_out,
												  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMin_swc_out,
												  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlMax_swc_out,
												  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlMinSat_swc_out, /* BIN1 */
												  CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bTqWhlMinSat_swc_out )
{

	/* VSCO_F6121_Min_Wheel_Torque_Cons_Deter */
	/* VSCO_F61211_Min_Wheel_Torque_Cmd_Mode_Deter */
	*VSCtl_stCtl_tqWhlMin_swc_out 	= (UInt8)VSCO_ARRET;
	vsctl_stctl_tqwhlmin_local 		= VSCO_ARRET;

	/* VSCO_F61212_Min_Wheel_Torque_Ant_Auth_Deter*/
	VSCtl_bCtlEfc_aVehMinPrev 		= DDS_FALSE;
	*VSCtl_bAuthAntTqWhlMin_swc_out = DDS_FALSE;
	vsctl_bauthanttqwhlmin_local 	= (UInt32)DDS_FALSE;

	/* VSCO_F61213_Min_Wheel_Torque_Cons_Calc */
	*VSCtl_tqWhlMinReq_swc_out		= VSCO_TORQUE_CONS_16000_BIN1_NEG;

	/* VSCO_F6122_Max_Wheel_Torque_Cons_Deter */
	/* VSCO_F61221_Max_Wheel_Torque_Cmd_Mode_Deter */
	*VSCtl_stCtl_tqWhlMax_swc_out	= (UInt8)VSCO_ARRET;
	vsctl_stctl_tqwhlmax_local		= VSCO_ARRET;

	/* VSCO_F61222_Max_Wheel_Torque_Ant_Auth_Deter*/
	VSCtl_bCtlEfc_aVehMaxPrev 		= DDS_FALSE;
	*VSCtl_bAuthAntTqWhlMax_swc_out	= DDS_FALSE;
	vsctl_bauthanttqwhlmax_local	= (UInt32)DDS_FALSE;

	/* VSCO_F61223_Max_Wheel_Torque_Cons_Calc */
	*VSCtl_tqWhlMaxReq_swc_out 		= VSCO_TORQUE_CONS_16000_BIN1_POS;

	/* VSCO_F6123_Wheel_Torque_Lim_Cons_Deter */
	/* VSCO_F61231_Wheel_Torque_Lim_Cmd_Mode_Deter */
	*VSCtl_bTqWhlMinSat_swc_out		= DDS_FALSE;
	vsctl_btqwhlminsat_local		= (UInt32)DDS_FALSE;

	/* VSCO_F61232_Wheel_Torque_Lim_Cons_Deter */
	*VSCtl_tqWhlMinSat_swc_out 		= VSCO_TORQUE_CONS_16000_BIN1_NEG;

}



#define VSCO_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "VSCo_MemMap.h"

