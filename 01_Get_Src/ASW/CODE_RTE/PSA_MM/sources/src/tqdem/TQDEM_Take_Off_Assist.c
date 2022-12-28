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
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Take_Off_Assist.c
* Version int :/main/L02_01/2 Date: 17/7/2012 15 h 48 m User:posmyk 
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1_D
*    comments :add INLINE for static functions
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 13 m User:lemort 
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1_D
*    comments :add INLINE for static functions
* Version int :/main/L02_01/1 Date: 1/9/2010 14 h 8 m User:esnault
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\3 Date: 12/8/2010 10 h 7 m User:lemort
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 26/7/2010 17 h 2 m User:lemort
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 23/7/2010 16 h 35 m User:lemort
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_salmane_tqdem_e6_dev\1 Date: 9/7/2010 15 h 42 m User:salmane
*    TWK_model:TQDEM_Take_Off_Assist_L02_010_IMPL1
*    comments :TqDem1.0 Euro6
* Version int :/main/L01_02/1 Date: 16/9/2009 10 h 45 m User:langendorf
*    TWK_model:TQDEM_Take_Off_Assist_L01_020_IMPL1
*    comments :Correct fail code
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 2/9/2009 16 h 5 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_020_IMPL1
*    comments :Correct fail code
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 2/9/2009 9 h 27 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_020_IMPL1
*    comments :Correct fail code with TqSys_nTakeOffDec_C
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 28/8/2009 16 h 19 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_020_IMPL1
*    comments :TqDem 2.0: new specification CSMT_CGMT08_0091_v1_1
* Version int :/main/L01_01/4 Date: 3/12/2008 19 h 8 m User:boucher
*    TWK_model:TQDEM_Take_Off_Assist_L01_011_IMPL1
*    comments :FDS 24865
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 24/11/2008 16 h 47 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_011_IMPL1
*    comments :FDS 24865
* Version int :/main/L01_01/3 Date: 14/10/2008 16 h 25 m User:langendorf
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL2
*    comments :Error with Slew_rate
*    comments :Error with Slew_rate
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 13/10/2008 14 h 13 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL2
*    comments :Error with Slew_rate
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 25/9/2008 10 h 0 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL2
*    comments :no change
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 25/9/2008 9 h 47 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL2
*    comments :error with Slew macro
* Version dev :\main\branch_moisan_tqdem_integ\2 Date: 24/9/2008 16 h 17 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL2
*    comments :Correction following a fail test response
* Version dev :\main\branch_moisan_tqdem_integ\1 Date: 15/9/2008 9 h 31 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL1
*    comments :Error in CSMT_CGMT08_0091.FR.3.0
* Version int :/main/L01_01/1 Date: 9/9/2008 8 h 9 m User:boucher
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL1
*    comments :First implementation for TqDem PSA SSTG
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 28/8/2008 12 h 34 m User:moisan
*    TWK_model:TQDEM_Take_Off_Assist_L01_010_IMPL1
*    comments :First implementation for TqDem PSA SSTG
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"
#include "TqDem.h"


/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/



/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQDEM_TAKEOFF_7_SIZE                  7
#define TQDEM_TAKEOFF_8_SIZE                  8


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
#define TQDEM_START_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_facGainFilTakeOff_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_facGainSpdTakeOff_C = (CONST(UInt16, AUTOMATIC))(1 * BIN7);
_DDS_STATIC_ volatile CONST(SInt16, AUTOMATIC) TqSys_nTakeOffDec_C = (CONST(SInt16, AUTOMATIC))(-50 / DEC1);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffInc_C = (CONST(UInt16, AUTOMATIC))(20 / DEC1);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffMax_C = (CONST(UInt16, AUTOMATIC))(500 * BIN0);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN0);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_pAirExtDft_C = (CONST(UInt16, AUTOMATIC))(1000 * BIN0);
_DDS_STATIC_ volatile CONST(UInt16, AUTOMATIC) TqSys_tiTakeOffAntiStallMax_C = (CONST(UInt16, AUTOMATIC))(0.5 * DEC2);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"

/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bOfsLauchIdlTakeOff_C = DDS_FALSE;
#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQDEM_START_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorTakeOff_A[TQDEM_TAKEOFF_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(700 * BIN0), (UInt16)(750 * BIN0),
(UInt16)(800 * BIN0), (UInt16)(1000 * BIN0), (UInt16)(1500 * BIN0),
(UInt16)(2000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorTakeOff_T[TQDEM_TAKEOFF_7_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffAntiStall_T[TQDEM_TAKEOFF_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffOfs_M
[TQDEM_TAKEOFF_8_SIZE][TQDEM_TAKEOFF_7_SIZE] = {
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffOfsSpd_M
[TQDEM_TAKEOFF_7_SIZE][TQDEM_TAKEOFF_7_SIZE] = {
{
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0), (UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(50 * BIN0), (UInt16)(150 * BIN0),
(UInt16)(200 * BIN0), (UInt16)(400 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(50 * BIN0), (UInt16)(150 * BIN0),
(UInt16)(200 * BIN0), (UInt16)(400 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(20 * BIN0), (UInt16)(40 * BIN0),
(UInt16)(60 * BIN0), (UInt16)(80 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(20 * BIN0), (UInt16)(40 * BIN0),
(UInt16)(60 * BIN0), (UInt16)(80 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(20 * BIN0), (UInt16)(40 * BIN0),
(UInt16)(60 * BIN0), (UInt16)(80 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0) },
{
(UInt16)(0 * BIN0), (UInt16)(20 * BIN0), (UInt16)(40 * BIN0),
(UInt16)(60 * BIN0), (UInt16)(80 * BIN0), (UInt16)(0 * BIN0),
(UInt16)(0 * BIN0) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffOfsSpdX_A[TQDEM_TAKEOFF_7_SIZE] = {
(UInt16)(0 * BIN4), (UInt16)(1 * BIN4), (UInt16)(5 * BIN4),
(UInt16)(8 * BIN4), (UInt16)(20 * BIN4), (UInt16)(25 * BIN4),
(UInt16)(100 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffOfsSpdY_A[TQDEM_TAKEOFF_7_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(3 * BIN7), (UInt16)(5 * BIN7),
(UInt16)(10 * BIN7), (UInt16)(20 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(50 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nTakeOffOfsY_A[TQDEM_TAKEOFF_8_SIZE] = {
(UInt16)(500 * BIN0), (UInt16)(650 * BIN0), (UInt16)(800 * BIN0),
(UInt16)(950 * BIN0), (UInt16)(1100 * BIN0), (UInt16)(1250 * BIN0),
(UInt16)(1400 * BIN0), (UInt16)(1500 * BIN0)
};

#define TQDEM_STOP_SEC_CARTO_16BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQDEM_START_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_ntakoffofs_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_ntakoffofsspd_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_faccortakoff_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_ntakoffantistall_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_spdveh;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) tqdem_filter_facfiltakeoff_mp;
STATIC VAR(t_dds_m_slew, AUTOMATIC) tqdem_slew_rate;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) tqdem_fall_edge_tqsys_bacvantistallman;
STATIC VAR(t_dds_m_turn_off_delay_type, AUTOMATIC) tqdem_turn_off_tqsys_bacvantistallman;
#define TQDEM_STOP_SEC_VAR_UNSPECIFIED
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_facFilTakeOff_MP; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_spdVehFilTakeOff_MP; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_nOfsIdlTakeOff; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_nOfsIdlTakeOffFil; /* BIN2 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"

/* 8-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bOfsAntiStallTakeOff_MP;
#define TQDEM_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQDEM_START_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_NTAKOFFANTISTALL_T_APM = {
&tqsys_ntakoffantistall_t_sav,
TQDEM_TAKEOFF_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfsSpdY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffAntiStall_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_FACCORTAKOFF_T_APM = {
&tqsys_faccortakoff_t_sav,
TQDEM_TAKEOFF_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorTakeOff_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorTakeOff_T[0]
};


STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_NTAKOFFOFS_M_APM = {
&tqsys_ntakoffofs_m_sav,
TQDEM_TAKEOFF_7_SIZE,
TQDEM_TAKEOFF_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfsSpdX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfsY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfs_M[0][0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_NTAKOFFOFSSPD_M_APM = {
&tqsys_ntakoffofsspd_m_sav,
TQDEM_TAKEOFF_7_SIZE,
TQDEM_TAKEOFF_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfsSpdX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfsSpdY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nTakeOffOfsSpd_M[0][0]
};

#define TQDEM_STOP_SEC_CONST_UNSPECIFIED
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calcul_Consigne (
                    UInt16 covsctl_raccpeng_par,  /* BIN7 */
                    UInt8 copt_bcludiegdcord_par,
                    UInt16 ext_pairextmes_par,    /* BIN0 */
                    UInt8 frm_bdft_pairext_par,
                    UInt8 tqsys_bacvantistallman_par,
                    UInt16 tqsys_ntaridlfil_par,  /* BIN2 */
                    UInt16 veh_spdveh_par);     /* BIN7 */

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Limiteur_Pente (
                    UInt8 cha_sttqreq_par,      /* BIN0 */
                    UInt8 frm_binhntaridltakeoff_par);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_CVC_Requete (
                    UInt16 copt_ntaridlcvc_par,      /* BIN2 */
                    UInt16 tqsys_nofsffl_par,        /* BIN2 */
                    UInt16 tqsys_nofslauchidltakeoff_par, /* BIN2 */
                    UInt16 tqsys_ntaridlneut_par,      /* BIN2 */
                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_nofstottakeoff_ptr,  /* BIN2 */
                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ntarffl_ptr,     /* BIN2 */
                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ntaridlcvcreq_ptr ); /* BIN2 */



/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQDEM_Take_Off_Assist
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Take_Off_Assist(
                                           UInt16 CoVSCtl_rAccPEng_swc_out_par, /* BIN7 */
                                           UInt8 Cha_stTqReq_swc_in, /* BIN0 */
                                           UInt8 CoPt_bCluDiEgdCord_swc_in,
                                           UInt16 CoPt_nTarIdlCVC_swc_in, /* BIN2 */
                                           UInt16 Ext_pAirExtMes_swc_in, /* BIN0 */
                                           UInt8 FRM_bDft_pAirExt_swc_in,
                                           UInt8 FRM_bInhNTarIdlTakeOff_swc_in,
                                           UInt8 TqSys_bAcvAntiStallMan_swc_in,
                                           UInt16 TqSys_nOfsFFL_swc_in, /* BIN2 */
                                           UInt16 TqSys_nOfsLauchIdlTakeOff_swc_in, /* BIN2 */
                                           UInt16 TqSys_nTarIdlFil_swc_in, /* BIN2 */
                                           UInt16 TqSys_nTarIdlNeut_swc_in, /* BIN2 */
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nOfsTotTakeOff_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarFFL_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarIdlCVCReq_swc_out /* BIN2 */)
{
  /* SSTG_REQ_TAG: CSMT_CGMT08_0091.FR.1.1 */

  /* TqSys_nOfsIdlTakeOff */
  TQDEM_Calcul_Consigne(CoVSCtl_rAccPEng_swc_out_par,
                        CoPt_bCluDiEgdCord_swc_in,
                        Ext_pAirExtMes_swc_in,
                        FRM_bDft_pAirExt_swc_in,
                        TqSys_bAcvAntiStallMan_swc_in,
                        TqSys_nTarIdlFil_swc_in,
                        Veh_spdVeh_swc_in);

  /* TqSys_nOfsIdlTakeOffFil */
  TQDEM_Limiteur_Pente (Cha_stTqReq_swc_in,
                        FRM_bInhNTarIdlTakeOff_swc_in);

  TQDEM_CVC_Requete ( CoPt_nTarIdlCVC_swc_in,       /* BIN2 */
                      TqSys_nOfsFFL_swc_in,         /* BIN2 */
                      TqSys_nOfsLauchIdlTakeOff_swc_in, /* BIN2 */
                      TqSys_nTarIdlNeut_swc_in,       /* BIN2 */
                      TqSys_nOfsTotTakeOff_swc_out,     /* BIN2 */
                      TqSys_nTarFFL_swc_out,        /* BIN2 */
                      TqSys_nTarIdlCVCReq_swc_out );    /* BIN2 */

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Calcul_Consigne
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Calcul_Consigne (
                    UInt16 covsctl_raccpeng_par,  /* BIN7 */
                    UInt8 copt_bcludiegdcord_par,
                    UInt16 ext_pairextmes_par,    /* BIN0 */
                    UInt8 frm_bdft_pairext_par,
                    UInt8 tqsys_bacvantistallman_par,
                    UInt16 tqsys_ntaridlfil_par,  /* BIN2 */
                    UInt16 veh_spdveh_par)    /* BIN7 */
{
  /* SSTG_REQ_TAG: CSMT_CGMT08_0091.FR.2.1 */

  UInt32 table1_output, table2_output, map1_output, map2_output, add_in_1;
  UInt32 result_switch1, result_switch2;
  UInt32 result_add, result_final;

  /* [0; 500] */
  /* BIN7 */
  TqSys_spdVehFilTakeOff_MP = DDS_M_FILTER_LP1_U16(&tqdem_filter_spdveh,
                                                 veh_spdveh_par,
                                                 TqSys_facGainSpdTakeOff_C,
                                                 BIN7);

  /* BIN0 */
  /* [0; 8000] */
  table1_output = DDS_M_MAP2D_U16(&TQSYS_NTAKOFFANTISTALL_T_APM,
                                  TqSys_spdVehFilTakeOff_MP );

    /* BIN0 = MAP3D(BIN4, BIN4) */
    /* [0; 8000] */
    map1_output = DDS_M_MAP3D_U16(&TQSYS_NTAKOFFOFSSPD_M_APM,
                                  (UInt16)((UInt32)covsctl_raccpeng_par / BIN3),
                                  TqSys_spdVehFilTakeOff_MP );

  if(DDS_M_NEGATIVE_EDGE_DETECTED == DDS_M_EDGE_DETECT(&tqdem_fall_edge_tqsys_bacvantistallman, tqsys_bacvantistallman_par) )
  {
      TqSys_bOfsAntiStallTakeOff_MP = DDS_M_TURN_OFF_DELAY(DDS_TRUE,
                                                           DDS_TQDEM_1MS_U32_TIME,
                                                           ((UInt32)TqSys_tiTakeOffAntiStallMax_C * DEC1),
                                                           &tqdem_turn_off_tqsys_bacvantistallman);
  }
  else
  {
    TqSys_bOfsAntiStallTakeOff_MP = DDS_M_TURN_OFF_DELAY(DDS_FALSE,
                                                         DDS_TQDEM_1MS_U32_TIME,
                                                         ((UInt32)TqSys_tiTakeOffAntiStallMax_C * DEC1),
                                                         &tqdem_turn_off_tqsys_bacvantistallman);
  }

  /* [0; 8000] BIN0 */
  if((UInt32)DDS_FALSE != (UInt32)TqSys_bOfsAntiStallTakeOff_MP)
  {
    add_in_1 = table1_output;
  }
  else
  {
    add_in_1 = 0 * BIN0;
  }

  /* [500; 1500] BIN0 */
  if((UInt32)DDS_FALSE != (UInt32)frm_bdft_pairext_par)
  {
    result_switch1 = TqSys_pAirExtDft_C;
  }
  else
  {
    result_switch1 = ext_pairextmes_par;
  }

  /* BIN0 = MAP3D(BIN7, BIN0) */
  /* [0; 8000] */
  map2_output = DDS_M_MAP3D_U16(&TQSYS_NTAKOFFOFS_M_APM,
                                (UInt16)((UInt32)covsctl_raccpeng_par / BIN3),
                                (UInt16)result_switch1);

  /* BIN0 = BIN0 + BIN0 + BIN0 */
  /* [0; 24000] = [0; 8000] + [0; 8000] + [0; 8000] */
  result_add = add_in_1 + map1_output + map2_output;


  /* BIN7 */
  /* [0; 3] */
  table2_output = DDS_M_MAP2D_U16(&TQSYS_FACCORTAKOFF_T_APM,
                  (UInt16)((UInt32)tqsys_ntaridlfil_par / BIN2));

  /* [0; 3] BIN7 */
  if((UInt32)DDS_FALSE != (UInt32)copt_bcludiegdcord_par)
  {
    result_switch2 = table2_output;
  }
  else
  {
    result_switch2 = 0 * BIN7;
  }

  /* BIN7 */
  /* [0; 3] */
  TqSys_facFilTakeOff_MP = DDS_M_FILTER_LP1_U16(&tqdem_filter_facfiltakeoff_mp,
                                                (UInt16)result_switch2,
                                                TqSys_facGainFilTakeOff_C,
                                                BIN10);

    /* BIN2 = BIN7 * BIN0 / BIN5 */
    /* [0; 72000] = [0; 3] * [0; 24000] */
  result_final = (result_add * (UInt32)TqSys_facFilTakeOff_MP) / BIN5;

  TqSys_nOfsIdlTakeOff = (UInt16)DDS_M_MIN( result_final, (8000 * BIN2) );
}

/*******************************************************************************
*
* Function Name : TQDEM_Limiteur_Pente
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_Limiteur_Pente (
                    UInt8 cha_sttqreq_par,      /* BIN0 */
                    UInt8 frm_binhntaridltakeoff_par)
{
  /* SSTG_REQ_TAG: CSMT_CGMT08_0091.FR.3.2 */
  UInt32 condition;
  UInt32 result_switch;
  UInt32 result_slew_rate;
  UInt32 inc_tmp, dec_tmp, min_tmp, max_tmp;

  condition = (((UInt32)cha_sttqreq_par == 5) || ((UInt32)cha_sttqreq_par == 6) || ((UInt32)frm_binhntaridltakeoff_par == (UInt32)DDS_TRUE));

  /* [0; 8000] BIN2 */
  if((UInt32)DDS_FALSE != condition)
  {
    result_switch = 0 * BIN2;
  }
  else
  {
    result_switch = TqSys_nOfsIdlTakeOff;
  }

  /* We can use DDS_M_SLEW_U32 macro for the implementation of the rate limiter in using Inc * Te for the up rate */
  /* inc_tmp = TqSys_nTakeOffInc_C * 100 * Te = TqSys_nTakeOffInc_C * 100 / 100 = TqSys_nTakeOffInc_C  */

  /* BIN2 = NBIN3 * BIN5 */
  inc_tmp = ((UInt32)TqSys_nTakeOffInc_C * (UInt32)DEC1) * (UInt32)BIN2;
  dec_tmp = ((UInt32)(-(SInt32)TqSys_nTakeOffDec_C) * (UInt32)DEC1) * (UInt32)BIN2;

  min_tmp = (UInt32)TqSys_nTakeOffMin_C * (UInt32)BIN2;
  max_tmp = (UInt32)TqSys_nTakeOffMax_C * (UInt32)BIN2;

  result_slew_rate = DDS_M_SLEW_U32( &tqdem_slew_rate,
                                     result_switch,
                                     inc_tmp,
                                     dec_tmp );

  TqSys_nOfsIdlTakeOffFil = (UInt16)DDS_M_LIMIT(result_slew_rate,
                                                min_tmp,
                                                max_tmp );

}

/*******************************************************************************
*
* Function Name : TQDEM_CVC_Requete
* Description :   Calculation of TqSys_nOfsTotTakeOff, TqSys_nTarFFL and TqSys_nTarIdlCVCReq.
*
*******************************************************************************/

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_CVC_Requete (
                    UInt16 copt_ntaridlcvc_par,       /* BIN2 */
                    UInt16 tqsys_nofsffl_par,         /* BIN2 */
                    UInt16 tqsys_nofslauchidltakeoff_par, /* BIN2 */
                    UInt16 tqsys_ntaridlneut_par,       /* BIN2 */
                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_nofstottakeoff_ptr,  /* BIN2 */
                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ntarffl_ptr,     /* BIN2 */
                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_ntaridlcvcreq_ptr )  /* BIN2 */
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_0091.FR.4.1 */

  UInt32 tqdem_cvc_requete_tmp1;  /* BIN2 */
  UInt32 tqdem_cvc_requete_tmp2;  /* BIN2 */

  if((UInt32)DDS_FALSE != (UInt32)TqSys_bOfsLauchIdlTakeOff_C)
  {
    tqdem_cvc_requete_tmp1 = tqsys_nofslauchidltakeoff_par;
  }
  else
  {
    tqdem_cvc_requete_tmp1 = (0 * BIN2);
  }

  /* BIN2 = BIN2 + BIN2 */
  /* [0; 16000] = [0; 8000] + [0; 8000] */
  tqdem_cvc_requete_tmp1 = (UInt32)TqSys_nOfsIdlTakeOffFil + tqdem_cvc_requete_tmp1;

  /* [0; 8000] / BIN2 */
  *tqsys_nofstottakeoff_ptr = (UInt16)DDS_M_MIN(tqdem_cvc_requete_tmp1, (8000 * BIN2));

  /* BIN2 = BIN2 + BIN2 */
  /* [0; 16000] = [0; 8000] + [0; 8000] */
  tqdem_cvc_requete_tmp2 = (UInt32)tqsys_nofsffl_par + (UInt32)tqsys_ntaridlneut_par;

  tqdem_cvc_requete_tmp2 = DDS_M_MIN(tqdem_cvc_requete_tmp2, (8000 * BIN2));

  *tqsys_ntarffl_ptr = (UInt16)tqdem_cvc_requete_tmp2;

  *tqsys_ntaridlcvcreq_ptr = (UInt16)DDS_M_MAX(tqdem_cvc_requete_tmp2, (UInt32)copt_ntaridlcvc_par);
}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Take_Off_Assist_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Take_Off_Assist_Init( CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nOfsTotTakeOff_swc_out, /* BIN2 */
                                                  CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarFFL_swc_out,      /* BIN2 */
                                                  CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nTarIdlCVCReq_swc_out)  /* BIN2 */
{
  *TqSys_nOfsTotTakeOff_swc_out = (UInt16)(0 * BIN2);
  *TqSys_nTarFFL_swc_out        = (UInt16)(0 * BIN2);
  *TqSys_nTarIdlCVCReq_swc_out  = (UInt16)(0 * BIN2);

  (void)DDS_M_FILTER_LP1_U16_INIT(&tqdem_filter_spdveh,
                                  (UInt16)(0 * BIN7));

  (void)DDS_M_FILTER_LP1_U16_INIT(&tqdem_filter_facfiltakeoff_mp,
                                  (UInt16)(0 * BIN7));


  DDS_M_EDGE_DETECT_INIT(&tqdem_fall_edge_tqsys_bacvantistallman, DDS_FALSE);

  (void)DDS_M_TURN_OFF_DELAY_INIT(DDS_FALSE, &tqdem_turn_off_tqsys_bacvantistallman);

  (void)DDS_M_SLEW_U32_INIT( &tqdem_slew_rate, (UInt32)(0 * BIN9 ));
}

#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

