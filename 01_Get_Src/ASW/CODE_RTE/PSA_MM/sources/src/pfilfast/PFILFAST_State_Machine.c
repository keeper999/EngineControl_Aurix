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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_State_Machine.c
* Version int :/main/C00_00/1 Date: 29/8/2013 11 h 43 m User:meme 
*    TWK_model:PFILFAST_State_Machine_C00_000_IMPL1
*    comments :For PFilFast  14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 5/8/2013 10 h 49 m User:thauvin 
*    TWK_model:PFILFAST_State_Machine_C00_000_IMPL1
*    comments :For PFilFast  14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 10 h 1 m User:thauvin
*    TWK_model:PFILFAST_State_Machine_C00_000_IMPL1
*    comments :DEv PFilFast 14.0
* Version int :/main/L03_01/1 Date: 26/7/2012 11 h 5 m User:posmyk
*    TWK_model:PFILFAST_State_Machine_L03_010_IMPL1
*    comments :For PFilFast_13_0_e6
* Version dev :\main\branch_halouane_pfilfast_euro6_dev\1 Date: 19/7/2012 10 h 43 m User:halouane
*    TWK_model:PFILFAST_State_Machine_L03_010_IMPL1
*    comments :For PFilFast_13_0_e6
* Version int :/main/L02_01/3 Date: 12/3/2012 15 h 14 m User:esnault
*    TWK_model:PFILFAST_State_Machine_L02_011_IMPL1
*    comments :For ALTIS_1691099 / FDS_A0203936
* Version dev :\main\branch_veillard\1 Date: 23/11/2011 17 h 3 m User:veillard
*    TWK_model:PFILFAST_State_Machine_L02_011_IMPL1
*    comments :For ALTIS_1691099 / FDS_
* Version int :/main/L02_01/2 Date: 4/11/2011 10 h 2 m User:meme
*    TWK_model:PFILFAST_State_Machine_L02_011_IMPL1
*    comments :for PFilFast 11.2: FDS A0203495 / altis 1678416
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 27/10/2011 10 h 39 m User:demezil
*    TWK_model:PFILFAST_State_Machine_L02_011_IMPL1
*    comments :for PFilFast 11.2: FDS A0203495 / altis 1678416
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/10/2011 10 h 11 m User:demezil
*    TWK_model:PFILFAST_State_Machine_L02_010_IMPL2_D
*    comments :for PFilFast 11.2: FDS A0203495 / altis 1678416
* Version int :/main/L02_01/1 Date: 17/2/2011 15 h 37 m User:meme
*    TWK_model:PFILFAST_State_Machine_L02_010_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane\5 Date: 17/2/2011 11 h 19 m User:halouane
*    TWK_model:PFILFAST_State_Machine_L02_010_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane\4 Date: 16/2/2011 12 h 13 m User:halouane
*    TWK_model:PFILFAST_State_Machine_L02_010_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane\3 Date: 9/2/2011 10 h 53 m User:halouane
*    TWK_model:PFILFAST_State_Machine_L02_010_IMPL1
*    comments :update for TU
* Version dev :\main\branch_halouane\2 Date: 31/1/2011 16 h 19 m User:halouane
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1_D
*    comments :update for 11.0
* Version dev :\main\branch_halouane\1 Date: 31/1/2011 16 h 12 m User:halouane
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1_D
*    comments :update for 11.0
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 38 m User:esnault
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1
*    comments :correction after UT
* Version dev :\main\branch_lemort_pfilfast_dev\3 Date: 10/8/2010 16 h 2 m User:lemort
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1
*    comments :correction after UT
* Version dev :\main\branch_lemort_pfilfast_dev\2 Date: 12/7/2010 16 h 10 m User:lemort
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1
*    comments :debug binpoint
* Version dev :\main\branch_lemort_pfilfast_dev\1 Date: 9/7/2010 9 h 45 m User:lemort
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1
*    comments :complete with schema on remark tracking sheet
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 1/7/2010 16 h 41 m User:demezil
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 23/6/2010 16 h 33 m User:demezil
*    TWK_model:PFILFAST_State_Machine_L01_010_IMPL1
*    comments :for PFilFast e6
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

/* DDS Library */
#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "PFilFast.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define PFILFAST_P2000_BIN11    ((SInt32)2000 * BIN11)
#define PFILFAST_N2000_BIN11    ((SInt32)-2000 * BIN11)

/* pfilfast_f03_03_state_global */
#define PFILFAST_F03_03_STATE_NO_FILTERING  (UInt32)1
#define PFILFAST_F03_03_STATE_ACCELERATION  (UInt32)2
#define PFILFAST_F03_03_STATE_DECELERATION  (UInt32)3


#define DETECTION_EFFECIF                           (UInt32)(2 * BIN0)

/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
extern VAR(SInt32, AUTOMATIC) TqSys_tqFilDifMin; /* BIN11 */
extern VAR(UInt32, AUTOMATIC) TqSys_facGainPha5; /* BIN16 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivNotFil; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha10; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha11; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha4; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha6; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha7; /* BIN11 */
extern VAR(SInt32, AUTOMATIC) TqSys_tqSlopPha9; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqSys_tqOfsPha3Thd; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha10; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha2; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha4; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha8; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha9; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha3Phy; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
extern VAR(UInt8, AUTOMATIC) TqSys_bAcceAcv;
extern VAR(UInt8, AUTOMATIC) TqSys_facGainPha; /* BIN7 */
extern VAR(UInt8, AUTOMATIC) TqSys_facGainPha3; /* BIN7 */
extern VAR(UInt8, AUTOMATIC) TqSys_bClrCrossOff;
extern VAR(UInt8, AUTOMATIC) TqSys_bClrCrossOn;
extern VAR(UInt8, AUTOMATIC) TqSys_facGainDiDrivFil; /* BIN7 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"



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

/* 8-bits variables definition */
#define PFILFAST_START_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"
VAR(UInt8, AUTOMATIC) tqsys_stdrivfilphait_prev; /* BIN0 */
#define PFILFAST_STOP_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivFilRawPrev; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccPThdAsrOff_C = (UInt16)(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_thdDiRAccP_C = (UInt16)(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiASROff_C = (UInt16)(0.2 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDiPrev_C = (UInt16)(3 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDrivFilMax_C = (SInt16)(510 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqCkDrivFilMin_C = (SInt16)(-100 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdASROff_C = (SInt16)(400 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdTqLimEM_C = (SInt16)(0 * BIN4);
#define PFILFAST_STOP_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bPha4Acv_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bPha2Acv_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bPha5Acv_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bPha5Acv_Dece_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bThdCllAcv_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bPha3PhyAcv_C = DDS_FALSE;
#define PFILFAST_STOP_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define PFILFAST_START_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) pfilfast_f03_03_state_global;
STATIC VAR(UInt8, AUTOMATIC) tqsys_stdrivfilphait_cpy;
STATIC VAR(UInt8, AUTOMATIC) tqsys_bacceacv_cpy;
STATIC VAR(UInt8, AUTOMATIC) tqsys_facgainpha_cpy; /* BIN7 */
STATIC VAR(UInt8, AUTOMATIC) tqsys_facgainpha3_cpy; /* BIN7 */
#define PFILFAST_STOP_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqofspha3thd_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha10_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha2_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha4_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha8_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha9_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha3phy_cpy; /* BIN4 */
STATIC VAR(SInt16, AUTOMATIC) cha_tqdynasrreq_prev;
#define PFILFAST_STOP_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"


/* 32-bits variables definition */
#define PFILFAST_START_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqsys_facgainpha5_cpy; /* BIN16 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqckdrivnotfil_cpy; /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqsloppha10_cpy; /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqsloppha11_cpy; /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqsloppha4_cpy; /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqsloppha6_cpy; /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqsloppha7_cpy; /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqsloppha9_cpy; /* BIN11 */
#define PFILFAST_STOP_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) pfilfast_f03_04_turn_on_str1;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) pfilfast_f03_04_turn_on_str2;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) pfilfast_f03_04_edge_str;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivFilRaw; /* BIN11 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqCkEfcDiff;
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqCkEfcDiff2;
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bPha2Acv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bPha5Acv_Acce;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bPha5Acv_Dece;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bThdCllAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bPha3PhyAcv;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bPha4Acv;
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
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

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_Machine_Etat(  SInt16 tqsys_tqthdpha3it_par,
                                                            UInt8 tqsys_bdeceacvit_par,
                                                            SInt16 tqlimem_tqlimem_par,
                                                            UInt8 tqsys_bdidrivfilreq_par,
                                                            UInt8 tqclrcros_stdetclr_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_01_Calibration_Conversion(void);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Stateflow_Calculation(  SInt16 tqsys_tqthdpha3it_par,
                                                                        UInt8 tqsys_bdeceacvit_par,
                                                                        SInt16 tqlimem_tqlimem_par,
                                                                        UInt8 tqsys_bdidrivfilreq_par,
                                                                        UInt8 tqclrcros_stdetclr_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Decel_Input(void);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Stay_Decel(void);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_No_Filter_To_Accel(SInt16 tqsys_tqthdpha3it_par,
                                                                   SInt16 tqlimem_tqlimem_par,
                                                                   UInt8 tqclrcros_stdetclr_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Decel_To_Accel(SInt16 tqsys_tqthdpha3it_par,
																UInt8 tqclrcros_stdetclr_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Stay_Accel(SInt16 tqsys_tqthdpha3it_par,
                                                            SInt16 tqlimem_tqlimem_par,
                                                            UInt8 tqclrcros_stdetclr_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_04_Reinit_Inhibition( SInt16 cha_tqdynasrreq_par,
                                                                UInt16 covsctl_raccpeng_par,
                                                                SInt16 tqlimem_tqlimem_par,
                                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                                UInt8 tqsys_bacvvehspdctlreg_par,
                                                                UInt16 accp_raccp_par,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcfil_ptr);


/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_State_Machine
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_State_Machine(UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                           SInt16 Cha_tqDynASRReq_swc_in, /* BIN4 */
                                           UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAcvVehSpdCtlReg_swc_in,
                                           UInt8 TqSys_bDeceAcvIt_swc_in,
                                           UInt8 TqSys_bDiDrivFilReq_swc_in,
                                           SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
                                           UInt8 TqClrCros_stDetClr_swc_in,	/*BIN0*/
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPhaIt_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFil_swc_out /* BIN4 */)
{
    tqsys_facgainpha5_cpy = TqSys_facGainPha5;
    tqsys_tqckdrivnotfil_cpy = TqSys_tqCkDrivNotFil;
    tqsys_tqsloppha10_cpy = TqSys_tqSlopPha10;
    tqsys_tqsloppha11_cpy = TqSys_tqSlopPha11;
    tqsys_tqsloppha4_cpy = TqSys_tqSlopPha4;
    tqsys_tqsloppha6_cpy = TqSys_tqSlopPha6;
    tqsys_tqsloppha7_cpy = TqSys_tqSlopPha7;
    tqsys_tqsloppha9_cpy = TqSys_tqSlopPha9;

    tqsys_tqofspha3thd_cpy = TqSys_tqOfsPha3Thd;
    tqsys_tqthdpha10_cpy = TqSys_tqThdPha10;
    tqsys_tqthdpha2_cpy = TqSys_tqThdPha2;
    tqsys_tqthdpha4_cpy = TqSys_tqThdPha4;
    tqsys_tqthdpha8_cpy = TqSys_tqThdPha8;
    tqsys_tqthdpha9_cpy = TqSys_tqThdPha9;
    tqsys_tqthdpha3phy_cpy = TqSys_tqThdPha3Phy;

    tqsys_bacceacv_cpy = TqSys_bAcceAcv;
    tqsys_facgainpha_cpy = TqSys_facGainPha;
    tqsys_facgainpha3_cpy = TqSys_facGainPha3;

    PFILFAST_F03_03_Machine_Etat(TqSys_tqThdPha3It_swc_in,
                                 TqSys_bDeceAcvIt_swc_in,
                                 TqLimEM_tqLimEM_swc_in,
                                 TqSys_bDiDrivFilReq_swc_in,
                                 TqClrCros_stDetClr_swc_in);

    *TqSys_stDrivFilPhaIt_swc_out = tqsys_stdrivfilphait_cpy;
    tqsys_stdrivfilphait_prev = tqsys_stdrivfilphait_cpy;

    PFILFAST_F03_04_Reinit_Inhibition(  Cha_tqDynASRReq_swc_in,
                                        CoVSCtl_rAccPEng_swc_in,
                                        TqLimEM_tqLimEM_swc_in,
                                        TqCmp_tqSumLossCmp_swc_in,
                                        TqSys_bAcvVehSpdCtlReg_swc_in,
                                        AccP_rAccP_swc_in,
                                        TqSys_tqCkEfcFil_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_Machine_Etat
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_Machine_Etat(  SInt16 tqsys_tqthdpha3it_par,
                                                            UInt8 tqsys_bdeceacvit_par,
                                                            SInt16 tqlimem_tqlimem_par,
                                                            UInt8 tqsys_bdidrivfilreq_par,
                                                            UInt8 tqclrcros_stdetclr_par)
{
    /* SSTG_REQ_TAG: 01460_10_01107.FR.73.2 */

    PFILFAST_F03_03_01_Calibration_Conversion();

    PFILFAST_F03_03_02_Stateflow_Calculation(   tqsys_tqthdpha3it_par,
                                                tqsys_bdeceacvit_par,
                                                tqlimem_tqlimem_par,
                                                tqsys_bdidrivfilreq_par,
                                                tqclrcros_stdetclr_par);

}



/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_01_Calibration_Conversion
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_01_Calibration_Conversion(void)
{
    /* SSTG_REQ_TAG: 01460_10_01107.FR.74.2 */

    TqSys_bPha2Acv = TqSys_bPha2Acv_C;
    TqSys_bPha5Acv_Acce = TqSys_bPha5Acv_C;
    TqSys_bPha5Acv_Dece = TqSys_bPha5Acv_Dece_C;
    TqSys_bThdCllAcv = TqSys_bThdCllAcv_C;
    TqSys_bPha3PhyAcv = TqSys_bPha3PhyAcv_C;
    TqSys_bPha4Acv = TqSys_bPha4Acv_C;
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_02_Stateflow_Calculation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Stateflow_Calculation(  SInt16 tqsys_tqthdpha3it_par,
                                                                        UInt8 tqsys_bdeceacvit_par,
                                                                        SInt16 tqlimem_tqlimem_par,
                                                                        UInt8 tqsys_bdidrivfilreq_par,
                                                                        UInt8 tqclrcros_stdetclr_par)
{
    /* SSTG_REQ_TAG: 01460_10_01107.FR.75.3 */
    SInt32 pfilfast_f03_03_02_s32_temp;

    switch ((UInt32)pfilfast_f03_03_state_global)
    {
        case(PFILFAST_F03_03_STATE_NO_FILTERING):

            if( ((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
              &&((UInt32)DDS_FALSE != (UInt32)tqsys_bdeceacvit_par)
              &&((UInt32)DDS_FALSE == (UInt32)tqsys_bacceacv_cpy) )
            {
                /* output1 */
                PFILFAST_F03_03_02_Decel_Input();
            }
            else
            {
                if( ((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
                  &&((UInt32)DDS_FALSE == (UInt32)tqsys_bdeceacvit_par)
                  &&((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_cpy) )
                {
                    /* output2 */
                    PFILFAST_F03_03_02_No_Filter_To_Accel(tqsys_tqthdpha3it_par,
                                                          tqlimem_tqlimem_par,
                                                          tqclrcros_stdetclr_par);
                }
                else
                {
                    /* stay in NO_FILTERING */
                    if(PFILFAST_DRIVFIL_OFF == (UInt32)tqsys_stdrivfilphait_cpy)
                    {
                        /* during PFILFAST_DRIVFIL_OFF */
                        TqSys_tqCkEfcDiff = 0;
                        TqSys_tqCkDrivFilRaw = tqsys_tqckdrivnotfil_cpy;
                    }
                    else
                    {
                        /* PFILFAST_PFILFAST_DRIVFIL_DISABLING */
                        pfilfast_f03_03_02_s32_temp = DDS_M_ABS(tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev);

                        if(pfilfast_f03_03_02_s32_temp <= TqSys_tqFilDifMin)
                        {
                            TqSys_tqCkEfcDiff = 0;
                            TqSys_tqCkDrivFilRaw = tqsys_tqckdrivnotfil_cpy ;
                            tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_OFF;
                        }
                        else
                        {
                            /* during PFILFAST_PFILFAST_DRIVFIL_DISABLING */
                            pfilfast_f03_03_02_s32_temp = tqsys_tqckdrivnotfil_cpy +
                                                            (((SInt32)TqSys_facGainDiDrivFil *
                                                                (TqSys_tqCkDrivFilRawPrev - tqsys_tqckdrivnotfil_cpy))
                                                            / BIN7);
                            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_f03_03_02_s32_temp,
                                                                PFILFAST_N2000_BIN11,
                                                                PFILFAST_P2000_BIN11);
                            TqSys_tqCkEfcDiff = DDS_M_LIMIT((TqSys_tqCkDrivFilRaw - TqSys_tqCkDrivFilRawPrev),
                                                                PFILFAST_N2000_BIN11,
                                                                PFILFAST_P2000_BIN11);
                        }
                    }
                }
            }
            break;

        case(PFILFAST_F03_03_STATE_DECELERATION):

            if( ((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
              &&((UInt32)DDS_FALSE == (UInt32)tqsys_bdeceacvit_par)
              &&((UInt32)DDS_FALSE == (UInt32)tqsys_bacceacv_cpy) )
            {
                /* output1 */
                TqSys_tqCkEfcDiff = 0;
                TqSys_tqCkDrivFilRaw = tqsys_tqckdrivnotfil_cpy ;
                pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_NO_FILTERING;
                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_OFF;
            }
            else
            {
                if( ((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
                  &&((UInt32)DDS_FALSE == (UInt32)tqsys_bdeceacvit_par)
                      /* <PRQA_COMMENT><2995> The result of this logical operation is always 'true' </2995></PRQA_COMMENT>*/
                  &&((UInt32)DDS_FALSE != (UInt32)tqsys_bacceacv_cpy) )
                {
                    /* output2 */
                    PFILFAST_F03_03_02_Decel_To_Accel(tqsys_tqthdpha3it_par,
                    								tqclrcros_stdetclr_par);
                }
                else
                {
                    if((UInt32)DDS_FALSE != (UInt32)tqsys_bdidrivfilreq_par)
                    {
                        /* output3 */
                        pfilfast_f03_03_02_s32_temp = tqsys_tqckdrivnotfil_cpy +
                                                        (((SInt32)TqSys_facGainDiDrivFil *
                                                            (TqSys_tqCkDrivFilRawPrev - tqsys_tqckdrivnotfil_cpy))
                                                        / BIN7);
                        TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_f03_03_02_s32_temp,
                                                            PFILFAST_N2000_BIN11,
                                                            PFILFAST_P2000_BIN11);
                        TqSys_tqCkEfcDiff = DDS_M_LIMIT((TqSys_tqCkDrivFilRaw - TqSys_tqCkDrivFilRawPrev),
                                                            PFILFAST_N2000_BIN11,
                                                            PFILFAST_P2000_BIN11);
                        pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_NO_FILTERING;
                        tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_DISABLING;
                    }
                    else
                    {
                        PFILFAST_F03_03_02_Stay_Decel();
                    }
                }
            }
            break;

        case(PFILFAST_F03_03_STATE_ACCELERATION):

            if( ((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
              &&((UInt32)DDS_FALSE == (UInt32)tqsys_bdeceacvit_par)
              &&((UInt32)DDS_FALSE == (UInt32)tqsys_bacceacv_cpy) )
            {
                /* output1 */
                TqSys_tqCkEfcDiff = 0;
                TqSys_tqCkDrivFilRaw = tqsys_tqckdrivnotfil_cpy ;
                pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_NO_FILTERING;
                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_OFF;
            }
            else
            {
                if( ((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
                  &&((UInt32)DDS_FALSE == (UInt32)tqsys_bacceacv_cpy)
     /* <PRQA_COMMENT><2995> The result of this logical operation is always 'true' </2995></PRQA_COMMENT>*/
                  &&((UInt32)DDS_FALSE != (UInt32)tqsys_bdeceacvit_par) )
                {
                    /* output2 */
                    PFILFAST_F03_03_02_Decel_Input();
                }
                else
                {
                    if((UInt32)DDS_FALSE != (UInt32)tqsys_bdidrivfilreq_par)
                    {
                        /* output3 */
                        pfilfast_f03_03_02_s32_temp = tqsys_tqckdrivnotfil_cpy +
                                                        (((SInt32)TqSys_facGainDiDrivFil *
                                                            (TqSys_tqCkDrivFilRawPrev - tqsys_tqckdrivnotfil_cpy))
                                                        / BIN7);
                        TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_f03_03_02_s32_temp,
                                                            PFILFAST_N2000_BIN11,
                                                            PFILFAST_P2000_BIN11);
                        TqSys_tqCkEfcDiff = DDS_M_LIMIT((TqSys_tqCkDrivFilRaw - TqSys_tqCkDrivFilRawPrev),
                                                            PFILFAST_N2000_BIN11,
                                                            PFILFAST_P2000_BIN11);
                        pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_NO_FILTERING;
                        tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_DISABLING;
                    }
                    else
                    {
                        PFILFAST_F03_03_02_Stay_Accel(tqsys_tqthdpha3it_par,
                                                        tqlimem_tqlimem_par,
                                                        tqclrcros_stdetclr_par);
                    }
                }
            }
            break;

        default:
            TqSys_tqCkDrivFilRaw = tqsys_tqckdrivnotfil_cpy ;
            TqSys_tqCkEfcDiff = 0;
            pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_NO_FILTERING;
            tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_OFF;
            break;
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_02_Decel_Input
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Decel_Input(void)
{
    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_DECELERATION;

    if(TqSys_tqCkDrivFilRawPrev > ((SInt32)tqsys_tqthdpha8_cpy * BIN7))
    {
        pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
        pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha8_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
        pfilfast_s32_temp3 = DDS_M_MAX(pfilfast_s32_temp1, pfilfast_s32_temp2);
        TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp3,PFILFAST_N2000_BIN11,0);

        pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
        TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

        tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_D0_GAP;
    }
    else
    {
        if(TqSys_tqCkDrivFilRawPrev > ((SInt32)tqsys_tqthdpha9_cpy * BIN7))
        {
            pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha9_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp3 = DDS_M_MAX(pfilfast_s32_temp2,tqsys_tqsloppha9_cpy);
            pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1,pfilfast_s32_temp3);
            TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

            pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

            tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_1ST_SLOPE;
        }
        else
        {
            if(TqSys_tqCkDrivFilRawPrev > ((SInt32)tqsys_tqthdpha10_cpy * BIN7))
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1,tqsys_tqsloppha10_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_2ND_SLOPE;
            }
            else
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1, tqsys_tqsloppha11_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_3RD_SLOPE;
            }
        }
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_02_Stay_Decel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Stay_Decel(void)
{
    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    switch((UInt32)tqsys_stdrivfilphait_cpy)
    {
        case(PFILFAST_DECE_D0_GAP):
            if(TqSys_tqCkDrivFilRawPrev <= ((SInt32)tqsys_tqthdpha8_cpy * BIN7))
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha9_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MAX(pfilfast_s32_temp2, tqsys_tqsloppha9_cpy);
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1, pfilfast_s32_temp3);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_1ST_SLOPE;
            }
            else
            {
                /* during PFILFAST_DECE_D0_GAP */
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha8_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MAX(pfilfast_s32_temp1,pfilfast_s32_temp2);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp3,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev+TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_DECE_1ST_SLOPE):
            if(TqSys_tqCkDrivFilRawPrev <= ((SInt32)tqsys_tqthdpha9_cpy * BIN7))
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1, tqsys_tqsloppha10_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev+TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_2ND_SLOPE;
            }
            else
            {
                /* during PFILFAST_DECE_1ST_SLOPE */
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha9_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MAX(pfilfast_s32_temp2,tqsys_tqsloppha9_cpy);
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1,pfilfast_s32_temp3);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_DECE_2ND_SLOPE):
            if(TqSys_tqCkDrivFilRawPrev <= ((SInt32)tqsys_tqthdpha10_cpy * BIN7))
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1,tqsys_tqsloppha11_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DECE_3RD_SLOPE;
            }
            else
            {
                /* during PFILFAST_DECE_2ND_SLOPE */
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1,  tqsys_tqsloppha10_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_DECE_3RD_SLOPE):
            /* during PFILFAST_DECE_3RD_SLOPE */
            pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy -TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp2 = DDS_M_MAX(pfilfast_s32_temp1,tqsys_tqsloppha11_cpy);
            TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,PFILFAST_N2000_BIN11,0);

            pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            break;

        default:
            /* this case will never be active */
            PFILFAST_F03_03_02_Decel_Input();
            break;
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_02_No_Filter_To_Accel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_No_Filter_To_Accel(SInt16 tqsys_tqthdpha3it_par,
                                                                   SInt16 tqlimem_tqlimem_par,
                                                                   UInt8 tqclrcros_stdetclr_par)
{
    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;
    SInt32 pfilfast_s32_temp4;

    pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_ACCELERATION;

    if( ((UInt32)DDS_FALSE != (UInt32)TqSys_bPha2Acv)
    &&  (TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha2_cpy * BIN7)) )
    {
        pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
        pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha2_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
        pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp1,pfilfast_s32_temp2);
        TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp3,0,PFILFAST_P2000_BIN11);

        pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
        TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

        tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_GAP_START_FILT;
    }
    else
    {
        if (((TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha3it_par * BIN7))
               &&((UInt32)DDS_FALSE == (UInt32)TqSys_bThdCllAcv)
               &&((UInt32)DDS_FALSE == (UInt32)TqSys_bPha3PhyAcv))
          ||	(((UInt32)tqclrcros_stdetclr_par < DETECTION_EFFECIF)
          	   && ((UInt32)DDS_FALSE != (UInt32)TqSys_bThdCllAcv))
          ||	((TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha3phy_cpy * BIN7))
          	   &&((UInt32)DDS_FALSE != (UInt32)TqSys_bPha3PhyAcv)))
        {
            pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha3it_par * BIN7) - TqSys_tqCkDrivFilRawPrev;
            /* BIN11 = ((BIN4 + BIN4) * BIN7) + BIN11 */
            pfilfast_s32_temp3 = (((SInt32)tqsys_tqthdpha3it_par + (SInt32)tqsys_tqofspha3thd_cpy) * BIN7) - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp4 = ((SInt32)tqsys_facgainpha3_cpy * pfilfast_s32_temp3) / BIN7;
            pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp2,pfilfast_s32_temp4);
            pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1,pfilfast_s32_temp3);
            TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,0,PFILFAST_P2000_BIN11);

            pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

            tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_1ST_ORDER_FILT;
        }
        else
        {
            if(((UInt32)DDS_FALSE == (UInt32)TqSys_bPha3PhyAcv)
              &&  (((((SInt32)tqsys_tqthdpha3it_par * BIN7) <= TqSys_tqCkDrivFilRawPrev)
                   && (TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha4_cpy * BIN7))
                   && ((UInt32)DDS_FALSE == (UInt32)TqSys_bThdCllAcv))
               	 ||(((UInt32)tqclrcros_stdetclr_par == DETECTION_EFFECIF)
               	   && ((UInt32)DDS_FALSE != (UInt32)TqSys_bThdCllAcv))))
           {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1,tqsys_tqsloppha4_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_SET_PASS_SLOPE;
            }
            else
            {
                if((UInt32)DDS_FALSE != (UInt32)TqSys_bPha5Acv_Acce)
                {
                    /* BIN11 = BIN16 * BIN4 / BIN9 */
                    pfilfast_s32_temp1 = ((SInt32)tqsys_facgainpha5_cpy * (SInt32)tqlimem_tqlimem_par) / BIN9;
                    pfilfast_s32_temp2 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                    /* BIN11 = BIN7 * BIN11 / BIN7 */
                    pfilfast_s32_temp3 = ((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp2) / BIN7;
                    pfilfast_s32_temp4 = DDS_M_MIN(pfilfast_s32_temp3,pfilfast_s32_temp1);
                    pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp4, pfilfast_s32_temp2);
                    TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                    pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                    TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                    TqSys_tqCkEfcDiff2 = 0;

                    tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_PARABOL;
                }
                else
                {
                    pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                    /* BIN11 = BIN7 * BIN11 / BIN7 */
                    pfilfast_s32_temp2 = ((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp1) / BIN7;
                    pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp1,pfilfast_s32_temp2);
                    pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp3,tqsys_tqsloppha7_cpy);
                    TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                    pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                    TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                    tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_SLOPE_ABOVE_SET;
                }
            }
        }
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_02_Decel_To_Accel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Decel_To_Accel(SInt16 tqsys_tqthdpha3it_par,
																UInt8 tqclrcros_stdetclr_par)
{
    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;
    SInt8 pfilfast_nb_shift;

    pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_ACCELERATION;

    if( ((UInt32)DDS_FALSE != (UInt32)TqSys_bPha2Acv)
    &&  (TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha2_cpy * BIN7)) )
    {
        pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
        pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha2_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
        pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp1, pfilfast_s32_temp2);
        TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp3,0,PFILFAST_P2000_BIN11);

        pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
        TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

        tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_GAP_START_FILT;
    }
    else
    {
        if (((TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha3it_par * BIN7))
               &&((UInt32)DDS_FALSE == (UInt32)TqSys_bThdCllAcv)
               &&((UInt32)DDS_FALSE == (UInt32)TqSys_bPha3PhyAcv))
          ||	(((UInt32)tqclrcros_stdetclr_par < DETECTION_EFFECIF)
          	   && ((UInt32)DDS_FALSE != (UInt32)TqSys_bThdCllAcv))
          ||	((TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha3phy_cpy * BIN7))
          	   &&((UInt32)DDS_FALSE != (UInt32)TqSys_bPha3PhyAcv)))
        {
            pfilfast_s32_temp1 = (((SInt32)tqsys_tqthdpha3it_par + (SInt32)tqsys_tqofspha3thd_cpy) * BIN7) - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp2 = ((SInt32)tqsys_facgainpha3_cpy * pfilfast_s32_temp1) / BIN7;
            pfilfast_s32_temp1 = DDS_M_MIN(((SInt32)tqsys_tqthdpha3it_par * BIN7) - TqSys_tqCkDrivFilRawPrev, pfilfast_s32_temp2);
            pfilfast_s32_temp2 = DDS_M_MIN(tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev, pfilfast_s32_temp1);
            TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,0,PFILFAST_P2000_BIN11);

            pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

            tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_1ST_ORDER_FILT;
        }
        else
        {
            if(((UInt32)DDS_FALSE == (UInt32)TqSys_bPha3PhyAcv)
              &&  (((((SInt32)tqsys_tqthdpha3it_par * BIN7) <= TqSys_tqCkDrivFilRawPrev)
                   && (TqSys_tqCkDrivFilRawPrev < ((SInt32)tqsys_tqthdpha4_cpy * BIN7))
                   && ((UInt32)DDS_FALSE == (UInt32)TqSys_bThdCllAcv))
               	 ||(((UInt32)tqclrcros_stdetclr_par == DETECTION_EFFECIF)
               	   && ((UInt32)DDS_FALSE != (UInt32)TqSys_bThdCllAcv))))
           {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1,tqsys_tqsloppha4_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_SET_PASS_SLOPE;
            }
            else
            {
                if((UInt32)DDS_FALSE != (UInt32)TqSys_bPha5Acv_Dece)
                {
                    pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                    pfilfast_s32_temp2 = ((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp1) / BIN7;
                    pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp1,pfilfast_s32_temp2);

                    /* BIN(16+11-X) */
                    /* [0; 540 000 000]BIN10 = ([0;270 000 000]BIN0 * [0; 2]BIN10) * 0.000 001 */
                    pfilfast_nb_shift = 16 + 11;
                    pfilfast_s32_temp1 = DDS_M_DYNAMIC_MULT_S32((SInt32)tqsys_facgainpha5_cpy, tqsys_tqckdrivnotfil_cpy, &pfilfast_nb_shift);
                    pfilfast_nb_shift = (SInt8)((SInt32)pfilfast_nb_shift - 11);
                    pfilfast_s32_temp2 = DDS_M_RESTORE_BINPOINT_SINT32(pfilfast_s32_temp1, pfilfast_nb_shift);
                    pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp3,pfilfast_s32_temp2) ;

                    TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                    pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                    TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                    TqSys_tqCkEfcDiff2 = 0;

                    tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_PARABOL;
                }
                else
                {
                    pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                    pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1, (((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp1) / BIN7));
                    pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp2,tqsys_tqsloppha7_cpy);
                    TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                    pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                    TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                    tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_SLOPE_ABOVE_SET;
                }
            }
        }
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_03_02_Stay_Accel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_03_02_Stay_Accel(SInt16 tqsys_tqthdpha3it_par,
                                                            SInt16 tqlimem_tqlimem_par,
                                                            UInt8 tqclrcros_stdetclr_par)
{
    SInt32 pfilfast_s32_temp1;
    SInt32 pfilfast_s32_temp2;
    SInt32 pfilfast_s32_temp3;

    switch((UInt32)tqsys_stdrivfilphait_cpy)
    {
        case(PFILFAST_ACCE_GAP_START_FILT):
            if(TqSys_tqCkDrivFilRawPrev >= ((SInt32)tqsys_tqthdpha2_cpy * BIN7))
            {
                pfilfast_s32_temp1 = (((SInt32)tqsys_tqthdpha3it_par + (SInt32)tqsys_tqofspha3thd_cpy) * BIN7) - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = ((SInt32)tqsys_facgainpha3_cpy * pfilfast_s32_temp1) / BIN7;
                pfilfast_s32_temp3 = DDS_M_MIN(((SInt32)tqsys_tqthdpha3it_par * BIN7) - TqSys_tqCkDrivFilRawPrev,pfilfast_s32_temp2 );
                pfilfast_s32_temp1 = DDS_M_MIN(tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev,pfilfast_s32_temp3);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_1ST_ORDER_FILT;
            }
            else
            {
                /* stay PFILFAST_ACCE_GAP_START_FILT */
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha2_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp1,pfilfast_s32_temp2);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp3,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_ACCE_1ST_ORDER_FILT):
            if( ( (TqSys_tqCkEfcDiff <= tqsys_tqsloppha4_cpy)
                &&((UInt32)DDS_FALSE == (UInt32)TqSys_bPha4Acv) )
              ||( ((UInt32)DDS_FALSE != (UInt32)TqSys_bClrCrossOn)
                &&((UInt32)DDS_FALSE != (UInt32)TqSys_bThdCllAcv) )
              ||( (TqSys_tqCkDrivFilRawPrev >= ((SInt32)tqsys_tqthdpha3it_par * BIN7))
				  &&((UInt32)DDS_FALSE != (UInt32)TqSys_bPha4Acv) ) )
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy -TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = ((SInt32)tqsys_tqthdpha4_cpy * BIN7) - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp1,tqsys_tqsloppha4_cpy);
                pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp3,pfilfast_s32_temp2);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_SET_PASS_SLOPE;
            }
            else
            {
                /* stay PFILFAST_ACCE_1ST_ORDER_FILT */
                pfilfast_s32_temp1 = (DDS_M_MIN(((SInt32)tqsys_tqthdpha3it_par + (SInt32)tqsys_tqofspha3thd_cpy),(SInt32)tqlimem_tqlimem_par) * BIN7);
                pfilfast_s32_temp2 = ((SInt32)tqsys_facgainpha3_cpy * (pfilfast_s32_temp1 - TqSys_tqCkDrivFilRawPrev)) / BIN7;
                pfilfast_s32_temp3 = DDS_M_MIN(((SInt32)tqsys_tqthdpha3it_par * BIN7) - TqSys_tqCkDrivFilRawPrev,pfilfast_s32_temp2);
                pfilfast_s32_temp1 = DDS_M_MIN(tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev,pfilfast_s32_temp3);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_ACCE_SET_PASS_SLOPE):
            if( (TqSys_tqCkDrivFilRawPrev >= ((SInt32)tqsys_tqthdpha4_cpy * BIN7))
            ||  ( ((UInt32)DDS_FALSE != (UInt32)TqSys_bClrCrossOff)
               && ((UInt32)DDS_FALSE != (UInt32)TqSys_bThdCllAcv) ) )
            {
                /* BIN11 = BIN16 * BIN4 / BIN9 */
                pfilfast_s32_temp1 = ((SInt32)tqsys_facgainpha5_cpy * (SInt32)tqlimem_tqlimem_par) / BIN9;
                pfilfast_s32_temp2 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MAX(tqsys_tqsloppha4_cpy,pfilfast_s32_temp1);
                pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp2, (((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp2) / BIN7));
                pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1,pfilfast_s32_temp3);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                TqSys_tqCkEfcDiff2 = 0;

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_PARABOL;
            }
            else
            {
                /* stay PFILFAST_ACCE_SET_PASS_SLOPE */
                pfilfast_s32_temp1 = DDS_M_MIN(tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev, tqsys_tqsloppha4_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_ACCE_PARABOL):
            if(TqSys_tqCkEfcDiff >= tqsys_tqsloppha6_cpy)
            {
                pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1, (((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp1) / BIN7) );
                pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp2, tqsys_tqsloppha6_cpy);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

                tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_ACCE_SLOPE_AFTER_PARABOL;
            }
            else
            {
                /* stay PFILFAST_ACCE_PARABOL */
                TqSys_tqCkEfcDiff2 = DDS_M_MAX(TqSys_tqCkEfcDiff,TqSys_tqCkEfcDiff2);

                /* BIN11 = BIN16 * BIN4 / BIN9 */
                pfilfast_s32_temp1 = ((SInt32)tqsys_facgainpha5_cpy * (SInt32)tqlimem_tqlimem_par) / BIN9;
                pfilfast_s32_temp2 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
                pfilfast_s32_temp3 = DDS_M_MIN(pfilfast_s32_temp2, (((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp2) / BIN7) );
                pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp3, TqSys_tqCkEfcDiff2 + pfilfast_s32_temp1);
                TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp2,0,PFILFAST_P2000_BIN11);

                pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
                TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);
            }
            break;

        case(PFILFAST_ACCE_SLOPE_AFTER_PARABOL):
            /* stay PFILFAST_ACCE_SLOPE_AFTER_PARABOL */

            pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1, (((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp1) / BIN7));
            pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp2, tqsys_tqsloppha6_cpy);
            TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

            pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

            break;

        case(PFILFAST_ACCE_SLOPE_ABOVE_SET):
            /* stay PFILFAST_ACCE_SLOPE_ABOVE_SET */
            pfilfast_s32_temp1 = tqsys_tqckdrivnotfil_cpy - TqSys_tqCkDrivFilRawPrev;
            pfilfast_s32_temp2 = DDS_M_MIN(pfilfast_s32_temp1, (((SInt32)tqsys_facgainpha_cpy * pfilfast_s32_temp1) / BIN7));
            pfilfast_s32_temp1 = DDS_M_MIN(pfilfast_s32_temp2, tqsys_tqsloppha7_cpy);
            TqSys_tqCkEfcDiff = DDS_M_LIMIT(pfilfast_s32_temp1,0,PFILFAST_P2000_BIN11);

            pfilfast_s32_temp1 = TqSys_tqCkDrivFilRawPrev + TqSys_tqCkEfcDiff;
            TqSys_tqCkDrivFilRaw = DDS_M_LIMIT(pfilfast_s32_temp1,PFILFAST_N2000_BIN11,PFILFAST_P2000_BIN11);

            break;

        default:
            /* this case will never be active */
            PFILFAST_F03_03_02_No_Filter_To_Accel(tqsys_tqthdpha3it_par,
                                                    tqlimem_tqlimem_par,
                                                    tqclrcros_stdetclr_par);
            break;
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F03_04_Reinit_Inhibition
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_04_Reinit_Inhibition( SInt16 cha_tqdynasrreq_par,
                                                                UInt16 covsctl_raccpeng_par,
                                                                SInt16 tqlimem_tqlimem_par,
                                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                                UInt8 tqsys_bacvvehspdctlreg_par,
                                                                UInt16 accp_raccp_par,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcfil_ptr)
{
    /* SSTG_REQ_TAG: 01460_10_01107.FR.76 */

    UInt8 pfilfast_f03_04_input_turn_on;
    UInt8 pfilfast_f03_04_output1_turn_on;
    UInt8 pfilfast_f03_04_output2_turn_on;
    t_dds_m_edge_detected_event pfilfast_f03_04_edge_detect_result;
    SInt32 pfilfast_f03_04_input_sat;
    SInt32 tqsys_tqckefcfil_mp_bin11;
    UInt32 pfilfast_current_time;

    pfilfast_current_time = PFilFast_Timer_1ms_U32();

    if( ((UInt32)accp_raccp_par <= (UInt32)TqSys_thdDiRAccP_C)
     && ((UInt32)DDS_FALSE == (UInt32)tqsys_bacvvehspdctlreg_par) )
    {
        pfilfast_f03_04_input_turn_on = DDS_TRUE;
    }
    else
    {
        pfilfast_f03_04_input_turn_on = DDS_FALSE;
    }

    pfilfast_f03_04_output1_turn_on = DDS_M_TURN_ON_DELAY(pfilfast_f03_04_input_turn_on,
                                                        pfilfast_current_time,
                                                        ((UInt32)TqSys_tiDiPrev_C * DEC1),
                                                        &pfilfast_f03_04_turn_on_str1);

    if( ((SInt32)cha_tqdynasrreq_par < (SInt32)TqSys_tqThdASROff_C)
    &&  ((UInt32)covsctl_raccpeng_par < (UInt32)TqSys_rAccPThdAsrOff_C)
    &&  (((SInt32)TqSys_tqThdTqLimEM_C - (SInt32)tqcmp_tqsumlosscmp_par) > (SInt32)tqlimem_tqlimem_par) )
    {
        pfilfast_f03_04_input_turn_on = DDS_TRUE;
    }
    else
    {
        pfilfast_f03_04_input_turn_on = DDS_FALSE;
    }

    pfilfast_f03_04_output2_turn_on = DDS_M_TURN_ON_DELAY(pfilfast_f03_04_input_turn_on,
                                                            pfilfast_current_time,
                                                            ((UInt32)TqSys_tiASROff_C * DEC1),
                                                            &pfilfast_f03_04_turn_on_str2);

    pfilfast_f03_04_edge_detect_result = DDS_M_EDGE_DETECT( &pfilfast_f03_04_edge_str,
                                                            pfilfast_f03_04_output2_turn_on);

    if((UInt32)DDS_FALSE != (UInt32)pfilfast_f03_04_output1_turn_on)
    {
        pfilfast_f03_04_input_sat = (SInt32)tqlimem_tqlimem_par * BIN7;
    }
    else
    {
        if((UInt32)DDS_M_POSITIVE_EDGE_DETECTED == (UInt32)pfilfast_f03_04_edge_detect_result)
        {
            pfilfast_f03_04_input_sat = DDS_M_MIN(((SInt32)cha_tqdynasrreq_prev * BIN7), TqSys_tqCkDrivFilRawPrev );
        }
        else
        {
            pfilfast_f03_04_input_sat = TqSys_tqCkDrivFilRaw;
        }
    }


    tqsys_tqckefcfil_mp_bin11 = DDS_M_SATURATION_V2(pfilfast_f03_04_input_sat,
                                                    ((SInt32)TqSys_tqCkDrivFilMin_C * BIN7),
                                                    ((SInt32)TqSys_tqCkDrivFilMax_C * BIN7));

    *tqsys_tqckefcfil_ptr = (SInt16)(tqsys_tqckefcfil_mp_bin11 / BIN7);

    TqSys_tqCkDrivFilRawPrev = tqsys_tqckefcfil_mp_bin11;


    /* Update prev */
    cha_tqdynasrreq_prev = cha_tqdynasrreq_par;

}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_State_Machine_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_State_Machine_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilPhaIt_swc_out, /* BIN0 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcFil_swc_out /* BIN4 */)
{
    cha_tqdynasrreq_prev = 0;

    *TqSys_stDrivFilPhaIt_swc_out = (UInt8)PFILFAST_DRIVFIL_OFF;
    *TqSys_tqCkEfcFil_swc_out = 0;

    pfilfast_f03_03_state_global = (UInt8)PFILFAST_F03_03_STATE_NO_FILTERING;
    tqsys_stdrivfilphait_cpy = (UInt8)PFILFAST_DRIVFIL_OFF;
    tqsys_stdrivfilphait_prev = (UInt8)PFILFAST_DRIVFIL_OFF;

    DDS_M_EDGE_DETECT( &pfilfast_f03_04_edge_str,DDS_FALSE);

    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE, &pfilfast_f03_04_turn_on_str1);
    DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE, &pfilfast_f03_04_turn_on_str2);

    TqSys_bPha2Acv = TqSys_bPha2Acv_C;
    TqSys_bPha5Acv_Acce = TqSys_bPha5Acv_C;
    TqSys_bPha5Acv_Dece = TqSys_bPha5Acv_Dece_C;
    TqSys_bThdCllAcv = TqSys_bThdCllAcv_C;
    TqSys_bPha3PhyAcv = TqSys_bPha3PhyAcv_C;
    TqSys_bPha4Acv = DDS_FALSE;

    TqSys_tqCkDrivFilRaw = 0;
    TqSys_tqCkEfcDiff = 0;
    TqSys_tqCkEfcDiff2 = 0;

    /* BIN11 = BIN4 * BIN7 */
    TqSys_tqCkDrivFilRawPrev = 0;

    /*Init Intern variables*/
    tqsys_tqthdpha10_cpy = 0;
    tqsys_tqsloppha9_cpy = 0;
    tqsys_facgainpha3_cpy = 0;
    tqsys_tqckdrivnotfil_cpy = 0;
    tqsys_tqthdpha8_cpy = 0;
    tqsys_tqsloppha11_cpy = 0;
    tqsys_tqthdpha9_cpy  = 0;
    tqsys_tqthdpha3phy_cpy = 0;
    tqsys_facgainpha5_cpy  = 0;
    tqsys_tqsloppha7_cpy = 0;
    tqsys_tqsloppha6_cpy = 0;
    tqsys_tqthdpha4_cpy = 0;
    tqsys_tqsloppha4_cpy = 0;
    tqsys_bacceacv_cpy  = 0;
    tqsys_tqthdpha2_cpy = 0;
    tqsys_tqofspha3thd_cpy = 0;
    tqsys_facgainpha_cpy = 0;
    tqsys_tqsloppha10_cpy = 0;
}


#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 09:53:22
* PERL v5.14.2
* Lib_CC 1.34
* Lib_Clipboard 1.01
* Lib_CQ 1.21
* Lib_DD_Check 2.00
* Lib_DD_Check_Checks 1.32
* Lib_DD_Check_Checks 1.33
* Lib_DD_Check_Data 2.01
* Lib_DD_Check_Utils 2.00
* Lib_DD_Compare 1.05
* Lib_DD_GenCode 3.23
* Lib_DD_Load 3.04
* Lib_DD_Load 3.06
* Lib_DD_Structure 1.10
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.02
* Lib_Gui_ComboBox 1.05
* Lib_Gui_Common 1.42
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.01
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.15
* Lib_Hash 1.30
* Lib_Log 1.25
* Lib_Pjt 1.30
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.07
* Lib_Scheduler_XML 1.45
* Lib_Spectool_Gen_DD 2.23
* Lib_Twk 1.06
* Lib_Utils 1.05
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.08
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* INPUT_SECTION *
AccP_rAccP ; ;ACCP ;% ;0 ;100 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Pourcentage d'enfoncement pédale sécurisé ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Cha_tqDynASRReq ; ;CHA ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple ASR dynamique venant de l’ESP ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoVSCtl_rAccPEng ; ;COVSCTL ;% ;0 ;100 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur pédale moteur ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqClrCros_stDetClr ;["DETECTION_INACTIF"*0*|"DETECTION_EN_COURS"*1*|"DETECTION_EFFECIF"*2*|"FIN_DE_DETECTION"*3*] ;TQCLRCROS ;N/A ;0 ;3 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat de la détection ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqSumLossCmp ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple des pertes globales à compenser. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqLimEM_tqLimEM ; ;TQLIMEM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple conducteur limité envoyé à l'agrément préventif ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcceAcv ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l'activation de l'acceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvVehSpdCtlReg ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Activation de RVV/ACC ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bClrCrossOff ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique la sortie de la phase de traversée des jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bClrCrossOn ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l’entrée dans la phase de traversée des jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceAcvIt ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l'activation de la décélération ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDiDrivFilReq ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen de desactivation la strategie filtration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainDiDrivFil ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient utilisé dans la phase de désactivation ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainPha ; ;PFILFAST ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 0 d acceleration ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainPha3 ; ;PFILFAST ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 0 d acceleration ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainPha5 ; ;PFILFAST ;N/A ;0 ;1 ;1/65536 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient de la phase 1 d acceleration ;["YES"] ;UInt32 ;BIN16 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivNotFil ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple non filtré après limitation pour motorisation essence ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqFilDifMin ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Constante nécessaire pour éviter les erreurs d arrondi ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsPha3Thd ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Offset de couple pour la convergence de la phase 0 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha10 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 2 de décélération ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha11 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 3 de décélération ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur de l’increment de couple correspondant a la rampe 01 (traversee des jeux) ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha6 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 2 d acceleration ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha7 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 3 d acceleration ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqSlopPha9 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rampe de la phase 1 de décélération ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha10 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 2 à phase 3 en décélération ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 00 a phase 0 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3It ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple d'entree de la zone des jeux ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha3Phy ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple physique pour l'entrée dans la zone des jeux ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 01 a phase 1 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha8 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 0 à phase 1 en décélération ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha9 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 1 à phase 2 en décélération ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
TqSys_stDrivFilPhaIt ;["DRIVFIL_OFF"*0*|"DRIVFIL_DISABLING"*1*|"ACCE_GAP_START_FILT"*2*|"ACCE_1ST_ORDER_FILT"*3*|"ACCE_SET_PASS_SLOPE"*4*|"ACCE_PARABOL"*5*|"ACCE_SLOPE_AFTER_PARABOL"*6*|"ACCE_SLOPE_ABOVE_SET"*7*|"DECE_D0_GAP"*8*|"DECE_1ST_SLOPE"*9*|"DECE_2ND_SLOPE"*10*|"DECE_3RD_SLOPE"*11*|"RESERVED_12"*12*|"RESERVED_13"*13*|"RESERVED_14"*14*|"RESERVED_15"*15*] ;TQS ;N/A ;0 ;15 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat de la filtration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivFilRawPrev ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur precedente du couple filtre avec une haute resolution ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEfcFil ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple final après filtration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
tqsys_stdrivfilphait_prev ;["DRIVFIL_OFF"*0*|"DRIVFIL_DISABLING"*1*|"ACCE_GAP_START_FILT"*2*|"ACCE_1ST_ORDER_FILT"*3*|"ACCE_SET_PASS_SLOPE"*4*|"ACCE_PARABOL"*5*|"ACCE_SLOPE_AFTER_PARABOL"*6*|"ACCE_SLOPE_ABOVE_SET"*7*|"DECE_D0_GAP"*8*|"DECE_1ST_SLOPE"*9*|"DECE_2ND_SLOPE"*10*|"DECE_3RD_SLOPE"*11*|"RESERVED_12"*12*|"RESERVED_13"*13*|"RESERVED_14"*14*|"RESERVED_15"*15*] ;TQS ;N/A ;0 ;15 ;1 ;["NULL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;enum output prev ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
TqSys_bPha4Acv ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booléen d'activation de la phase 4 via le seuil d'entrée dans les jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha4Acv_C ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ; Permet d'activer la phase 4 sur le seuil d'activation Pha3Thd ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha2Acv ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l activation pour la transition entre la phase 00 et la phase 0 en acceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha2Acv_C ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Permet d activer la phase 2 en acceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha3PhyAcv ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booléen d'activation de la phase 3 physique ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha3PhyAcv_C ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Permet d'activer la prise en compte du Pha3Phy lorsque l'on mape la phase 3 en fonction de la pédale ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha5Acv_Acce ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l activation de l acceleration en phase 5 (Phase 1 de l acceleration) ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha5Acv_C ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Si vrai, une phase stabilisee sans filtrage est suivie de la phase 5 (sinon phase 7) ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha5Acv_Dece ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l activation de la deceleration en phase 5 (Phase 1 de l acceleration) ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bPha5Acv_Dece_C ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Si vrai, une acceleration suivant une deceleration commence par la phase 5 (sinon phase 7) ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bThdCllAcv ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen d activation de la phase 4 ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bThdCllAcv_C ;["FALSE"|"TRUE"] ;PFILFAST ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Permet d’utiliser le flag externe pour la gestion de passage de jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccPThdAsrOff_C ; ;PFILFAST ;% ;0 ;100 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Seuil de position pedale pour l initialisation de couple apres regulation ASR ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_thdDiRAccP_C ; ;PFILFAST ;% ;0 ;100 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Seuil de desactivation de l agrement ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiASROff_C ; ;PFILFAST ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.2 ;Temporisation pour l initialisation du couple en sortie de regulation ASR ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiDiPrev_C ; ;PFILFAST ;s ;0 ;5 ;0.01 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;3 ;Temporisation pour desactivation du preventif sur un pied leve ;["YES"] ;UInt16 ;DEC2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivFilMax_C ; ;PFILFAST ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;510 ;Valeur maximum du couple filtre ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivFilMin_C ; ;PFILFAST ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;-100 ;Valeur minimum du couple filtre ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivFilRaw ; ;PFILFAST ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur precedente du couple filtre avec une haute resolution ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEfcDiff ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Différence entre le couple non filtré et le couple filtré ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkEfcDiff2 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Différence entre le couple non filtré et le couple filtré (idem TqSys_tqCkEfcDiff pour 2ème calcul) ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdASROff_C ; ;PFILFAST ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;400 ;Seuil de couple pour l initialisation de couple apres regulation ASR ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdTqLimEM_C ; ;PFILFAST ;Nm ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Seuil de couple pour continuite du couple en sortie de regulation ASR ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

