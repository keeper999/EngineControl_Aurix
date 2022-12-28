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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Pre_Treat.c
* Version int :/main/C00_00/1 Date: 29/8/2013 11 h 43 m User:meme 
*    TWK_model:PFILFAST_Pre_Treat_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\2 Date: 21/8/2013 13 h 34 m User:thauvin 
*    TWK_model:PFILFAST_Pre_Treat_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 10 h 47 m User:thauvin
*    TWK_model:PFILFAST_Pre_Treat_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version int :/main/L02_02/1 Date: 12/3/2012 15 h 14 m User:esnault
*    TWK_model:PFILFAST_Pre_Treat_L02_020_IMPL1
*    comments :for PFilFast 12.0: spec update
* Version dev :\main\branch_morisseau_pfilfast_euro6_dev\2 Date: 5/3/2012 17 h 39 m User:morisseau
*    TWK_model:PFILFAST_Pre_Treat_L02_020_IMPL1
*    comments :for PFilFast 12.0: spec update
* Version int :/main/L02_01/2 Date: 18/2/2011 12 h 25 m User:meme
*    TWK_model:PFILFAST_Pre_Treat_L02_010_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\4 Date: 18/2/2011 11 h 24 m User:halouane
*    TWK_model:PFILFAST_Pre_Treat_L02_010_IMPL2
*    comments :update for 11.0
* Version dev :\main\branch_halouane\3 Date: 18/2/2011 11 h 18 m User:halouane
*    TWK_model:PFILFAST_Pre_Treat_L02_010_IMPL2
*    comments :update for 11.0.
* Version int :/main/L02_01/1 Date: 17/2/2011 15 h 36 m User:meme
*    TWK_model:PFILFAST_Pre_Treat_L02_010_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\2 Date: 27/1/2011 17 h 5 m User:halouane
*    TWK_model:PFILFAST_Pre_Treat_L02_010_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane\1 Date: 27/1/2011 12 h 51 m User:halouane
*    TWK_model:PFILFAST_Pre_Treat_L02_010_IMPL1
*    comments :update for TU
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 38 m User:esnault
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\10 Date: 12/8/2010 9 h 25 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast euro6
* Version dev :\main\branch_demezil_pfilfast_dev\9 Date: 30/7/2010 16 h 4 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\8 Date: 13/7/2010 12 h 20 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\7 Date: 6/7/2010 15 h 45 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\6 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 30/6/2010 16 h 55 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 28/6/2010 16 h 51 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 28/6/2010 15 h 4 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 28/6/2010 14 h 52 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 28/6/2010 14 h 28 m User:demezil
*    TWK_model:PFILFAST_Pre_Treat_L01_010_IMPL1
*    comments :for PFilFast e6
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/
#include "PFilFast.h"
/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define PFILFAST_7_SIZE                       7
#define PFILFAST_10_SIZE                      10
#define PFILFAST_9_SIZE                       9

#define PFILFAST_CONF_0                             (UInt8)(0 * BIN0)
#define PFILFAST_CONF_1                             (UInt8)(1 * BIN0)
#define PFILFAST_CONF_2                             (UInt8)(2 * BIN0)
#define PFILFAST_CONF_3                             (UInt8)(3 * BIN0)
#define PFILFAST_CONF_4                             (UInt8)(4 * BIN0)

#define PFILFAST_BVM                                 (UInt8)(0 * BIN0)
#define PFILFAST_BVA                                 (UInt8)(1 * BIN0)
#define PFILFAST_BVMP                                (UInt8)(2 * BIN0)
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

/* 16-bits calibrations definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_A[PFILFAST_7_SIZE]; /* BIN0 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng_A[PFILFAST_10_SIZE]; /* BIN2 */
#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"



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

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
VAR(UInt16, AUTOMATIC) TqSys_tqACLossFil; /* BIN4 */
VAR(UInt16, AUTOMATIC) TqSys_nTrb; /* BIN2 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
VAR(UInt8, AUTOMATIC) TqSys_facGainDiDrivFil; /* BIN7 */
VAR(UInt8, AUTOMATIC) TqSys_bClrCrossOff;
VAR(UInt8, AUTOMATIC) TqSys_bClrCrossOn;
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_spdVehHys_bTkOff_C = (UInt16)(2 * BIN7);
#define PFILFAST_STOP_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDiDrivFil_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_tiFilTqACLoss_C = (UInt8)(0.1 * DEC1);
#define PFILFAST_STOP_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) Tq_spdVehThd_bTkOff_T
[PFILFAST_7_SIZE] = {
(UInt16)(255 * BIN7), (UInt16)(4 * BIN7), (UInt16)(4 * BIN7),
(UInt16)(4 * BIN7), (UInt16)(4 * BIN7), (UInt16)(4 * BIN7),
(UInt16)(4 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facGainDiDrivFil_M
[PFILFAST_7_SIZE][PFILFAST_10_SIZE] = {
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) },
{
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7),
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(1 * BIN7) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_noGearCordDrivFil_T
[PFILFAST_9_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(6 * BIN0), (UInt16)(6 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_noGearCordDrivFil_A[PFILFAST_9_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0), (UInt16)(7 * BIN0), (UInt16)(8 * BIN0)
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tq_spdvehthd_btkoff_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facgaindidrivfil_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_nogearcorddrivfil_t_sav;

STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) pfilfast_edge_detect_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) pfilfast_filter_ptr;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) pfilfast_hyst_u32_ptr;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) pfilfast_tqsys_stdrivfilcfpha_prev;
STATIC VAR(UInt8, AUTOMATIC) pfilfast_f01_f03_filter_init;
#define PFILFAST_STOP_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDrivFilTakeOff;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDiDrivFilCfReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_stDrivFilCf;
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQ_SPDVEHTHD_BTKOFF_T_APM = {
&tq_spdvehthd_btkoff_t_sav,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&Tq_spdVehThd_bTkOff_T[0]
};

STATIC CONST(t_dds_m_map3d_u16, AUTOMATIC) TQSYS_FACGAINDIDRIVFIL_M_APM = {
&tqsys_facgaindidrivfil_m_sav,
PFILFAST_10_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facGainDiDrivFil_M[0][0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_NOGEARCORDDRIVFIL_T_APM = {
&tqsys_nogearcorddrivfil_t_sav,
PFILFAST_9_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGearCordDrivFil_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGearCordDrivFil_T[0]
};

#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_01_Engine_And_Primary_Shaft_Speed_Difference(UInt16 copt_ntrb_par, /* BIN2 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                       CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_ndif_nengntrb_ptr /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_02_Clearance_Cross_Filtering_Disabled(UInt8 tqclrcros_bacvclrcross_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_03_Air_Conditionning_Torque_Losses_Filtering(UInt16 tqcmp_tqacloss_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_04_Filtering_Request_Takeoff_Disabled(UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                UInt16 veh_spdveh_par, /* BIN7 */
                                                                                UInt8 tqdem_bdrivtakeoff_par,
                                                                                UInt8 frm_bdft_spdveh_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_05_Filtering_Configuration(UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 copt_nodrivfiltyp_par, /* BIN0 */
                                                                        UInt8 ext_stgbxcf_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_stdrivfilcfpha_ptr /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_05_01_TakeOff_GearBox_Filtering_Config_State(UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                        UInt8 copt_nodrivfiltyp_par, /* BIN0 */
                                                                                        UInt8 ext_stgbxcf_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_06_Filtering_Phase_Disabled_Request(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                UInt8 ext_bdidrivfilreq_par,
                                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bdidrivfilreq_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_07_Gear_Calculation(UInt8 copt_nogearcorddrivfil_par, /* BIN0 */
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_nogearcorddrivfil_ptr /* BIN0 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Pre_Treat
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Pre_Treat(UInt16 CoPt_nTrb_swc_in, /* BIN2 */
                                           UInt8 CoPt_noDrivFilTyp_swc_in,
                                           UInt8 CoPt_noGearCordDrivFil_swc_in,
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 Ext_bDiDrivFilReq_swc_in,
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 TqClrCros_bAcvClrCross_swc_in,
                                           UInt16 TqCmp_tqACLoss_swc_in, /* BIN4 */
                                           UInt8 TqDem_bDrivTakeOff_swc_in,
                                           UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                           UInt8 FRM_bDft_spdVeh_swc_in,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDiDrivFilReq_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nDif_nEngNTrb_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilCfPha_swc_out )
{
    PFILFAST_F01_01_Engine_And_Primary_Shaft_Speed_Difference(CoPt_nTrb_swc_in, /* BIN2 */
                                                                Eng_nCkFil_swc_in, /* BIN2 */
                                                                TqSys_nDif_nEngNTrb_swc_out /* BIN2 */);

    PFILFAST_F01_02_Clearance_Cross_Filtering_Disabled(TqClrCros_bAcvClrCross_swc_in);

    PFILFAST_F01_03_Air_Conditionning_Torque_Losses_Filtering(TqCmp_tqACLoss_swc_in /* BIN4 */);

    PFILFAST_F01_07_Gear_Calculation(CoPt_noGearCordDrivFil_swc_in, /* BIN0 */
                                        TqSys_noGearCordDrivFil_swc_out /* BIN0 */);

    PFILFAST_F01_04_Filtering_Request_Takeoff_Disabled(*TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                                        Veh_spdVeh_swc_in, /* BIN7 */
                                                        TqDem_bDrivTakeOff_swc_in,
                                                        FRM_bDft_spdVeh_swc_in);

    PFILFAST_F01_05_Filtering_Configuration(*TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                            CoPt_noDrivFilTyp_swc_in, /* BIN0 */
                                            Ext_stGBxCf_swc_in,
                                            TqSys_stDrivFilCfPha_swc_out /* BIN0 */);

    PFILFAST_F01_06_Filtering_Phase_Disabled_Request(Eng_nCkFil_swc_in, /* BIN2 */
                                                        *TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                                        Ext_bDiDrivFilReq_swc_in,
                                                        TqSys_bDiDrivFilReq_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_F01_01_Engine_And_Primary_Shaft_Speed_Difference
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_01_Engine_And_Primary_Shaft_Speed_Difference(UInt16 copt_ntrb_par, /* BIN2 */
                                                                                        UInt16 eng_nckfil_par, /* BIN2 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_ndif_nengntrb_ptr /* BIN2 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.02 */
    /* BIN2 = BIN2 */
    TqSys_nTrb = copt_ntrb_par;

    /* BIN2 = BIN2 - BIN2 */
    *tqsys_ndif_nengntrb_ptr = (SInt16)((SInt32)eng_nckfil_par - (SInt32)copt_ntrb_par);
}

/*******************************************************************************
*
* Function Name : PFILFAST_F01_02_Clearance_Cross_Filtering_Disabled
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_02_Clearance_Cross_Filtering_Disabled(UInt8 tqclrcros_bacvclrcross_par)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.03 */
    t_dds_m_edge_detected_event edge_result;

    edge_result = DDS_M_EDGE_DETECT(&pfilfast_edge_detect_ptr,
                                    tqclrcros_bacvclrcross_par);

    if((UInt32)DDS_M_POSITIVE_EDGE_DETECTED == (UInt32)edge_result)
    {
        TqSys_bClrCrossOn = DDS_TRUE;
        TqSys_bClrCrossOff = DDS_FALSE;
    }
    else
    {
        TqSys_bClrCrossOn = DDS_FALSE;
        if((UInt32)DDS_M_NEGATIVE_EDGE_DETECTED == (UInt32)edge_result)
        {
            TqSys_bClrCrossOff = DDS_TRUE;
        }
        else
        {
            TqSys_bClrCrossOff = DDS_FALSE;
        }
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F01_03_Air_Conditionning_Torque_Losses_Filtering
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_03_Air_Conditionning_Torque_Losses_Filtering(UInt16 tqcmp_tqacloss_par /* BIN4 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.04 */
    UInt16 filter_factor;
    SInt32 temp_s32;

    if((UInt32)DDS_FALSE == (UInt32)pfilfast_f01_f03_filter_init)
    {
        TqSys_tqACLossFil = DDS_M_FILTER_LP1_U16_INIT(&pfilfast_filter_ptr,
                                                        tqcmp_tqacloss_par);
    }
    else
    {
    /* BIN15 = (0.01 * DEC2 * BIN15) / ((0.01 * DEC2) + (DEC1 * DEC1)) */
    temp_s32 = (1 * BIN15) / (1 + ((SInt32)TqSys_tiFilTqACLoss_C * DEC1));
    filter_factor = (UInt16)DDS_M_MIN(temp_s32,(1 * BIN15));

    TqSys_tqACLossFil = DDS_M_FILTER_LP1_U16(&pfilfast_filter_ptr,
                                                    tqcmp_tqacloss_par,
                                                    filter_factor,
                                                    BIN15);
    }

    pfilfast_f01_f03_filter_init = DDS_TRUE;
}


/*******************************************************************************
*
* Function Name : PFILFAST_F01_04_Filtering_Request_Takeoff_Disabled
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_04_Filtering_Request_Takeoff_Disabled(UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                UInt16 veh_spdveh_par, /* BIN7 */
                                                                                UInt8 tqdem_bdrivtakeoff_par,
                                                                                UInt8 frm_bdft_spdveh_par)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.6 */
    UInt32 pfilfast_low_thres;
    UInt32 pfilfast_high_thres;
    UInt8 pfilfast_out_hyst;

    pfilfast_low_thres = (UInt32)DDS_M_MAP2D_U16(&TQ_SPDVEHTHD_BTKOFF_T_APM,
                                        (UInt16)tqsys_nogearcorddrivfil_par);

    pfilfast_high_thres = pfilfast_low_thres + (UInt32)TqSys_spdVehHys_bTkOff_C;

    pfilfast_out_hyst = DDS_M_HYST_U32 (&pfilfast_hyst_u32_ptr,
                                        (UInt32)veh_spdveh_par,
                                        pfilfast_high_thres,
                                        (UInt32)TqSys_spdVehHys_bTkOff_C);

    if((UInt32)DDS_FALSE != (UInt32)tqdem_bdrivtakeoff_par)
    {
        TqSys_bDrivFilTakeOff = DDS_TRUE;
    }
    else
    {
        if(((UInt32)DDS_FALSE != (UInt32)frm_bdft_spdveh_par) ||
            ((UInt32)DDS_FALSE != (UInt32)pfilfast_out_hyst))
        {
            TqSys_bDrivFilTakeOff = DDS_TRUE;
        }
        else
        {
            TqSys_bDrivFilTakeOff = DDS_FALSE;
        }
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F01_05_Filtering_Configuration
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_05_Filtering_Configuration(UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 copt_nodrivfiltyp_par, /* BIN0 */
                                                                        UInt8 ext_stgbxcf_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_stdrivfilcfpha_ptr /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.7 */

    PFILFAST_F01_05_01_TakeOff_GearBox_Filtering_Config_State(tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                copt_nodrivfiltyp_par, /* BIN0 */
                                                                ext_stgbxcf_par);

    if((UInt32)PFILFAST_CONF_0 == (UInt32)TqSys_stDrivFilCf)
    {
        TqSys_bDiDrivFilCfReq = DDS_TRUE;
        *tqsys_stdrivfilcfpha_ptr = pfilfast_tqsys_stdrivfilcfpha_prev;
    }
    else
    {
        TqSys_bDiDrivFilCfReq = DDS_FALSE;
        *tqsys_stdrivfilcfpha_ptr = TqSys_stDrivFilCf;
    }
    pfilfast_tqsys_stdrivfilcfpha_prev = *tqsys_stdrivfilcfpha_ptr;
}


/*******************************************************************************
*
* Function Name : PFILFAST_F01_05_01_TakeOff_GearBox_Filtering_Config_State
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_05_01_TakeOff_GearBox_Filtering_Config_State(UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                        UInt8 copt_nodrivfiltyp_par, /* BIN0 */
                                                                                        UInt8 ext_stgbxcf_par)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.8 */
    if((UInt32)ext_stgbxcf_par != (UInt32)PFILFAST_BVM)
    {
        TqSys_stDrivFilCf = copt_nodrivfiltyp_par;
    }
    else
    {
        if((UInt32)DDS_FALSE == (UInt32)TqSys_bDrivFilTakeOff)
        {
            TqSys_stDrivFilCf = PFILFAST_CONF_0;
        }
        else
        {
            if((UInt32)0 == (UInt32)tqsys_nogearcorddrivfil_par)
            {
                TqSys_stDrivFilCf = PFILFAST_CONF_3;
            }
            else
            {
                TqSys_stDrivFilCf = PFILFAST_CONF_1;
            }
        }
    }
}


/*******************************************************************************
*
* Function Name : PFILFAST_F01_06_Filtering_Phase_Disabled_Request
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_06_Filtering_Phase_Disabled_Request(UInt16 eng_nckfil_par, /* BIN2 */
                                                                                UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                UInt8 ext_bdidrivfilreq_par,
                                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bdidrivfilreq_ptr)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.9 */
    SInt32 tqsys_facgaindidrivfil_m;

    tqsys_facgaindidrivfil_m = (SInt32)DDS_M_MAP3D_U16(&TQSYS_FACGAINDIDRIVFIL_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    if(((UInt32)DDS_FALSE == (UInt32)TqSys_bDiDrivFil_C) &&
        ((UInt32)DDS_FALSE == (UInt32)ext_bdidrivfilreq_par) &&
        ((UInt32)DDS_FALSE == (UInt32)TqSys_bDiDrivFilCfReq))
    {
        *tqsys_bdidrivfilreq_ptr = DDS_FALSE;
    }
    else
    {
        *tqsys_bdidrivfilreq_ptr = DDS_TRUE;
    }

    TqSys_facGainDiDrivFil = (UInt8)((SInt32)(1 * BIN7) - tqsys_facgaindidrivfil_m);
}


/*******************************************************************************
*
* Function Name : PFILFAST_F01_07_Gear_Calculation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F01_07_Gear_Calculation(UInt8 copt_nogearcorddrivfil_par, /* BIN0 */
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_nogearcorddrivfil_ptr /* BIN0 */)
{
    /* SSTG REQ_TAG : 01460_10_01107.FR.05 */
    *tqsys_nogearcorddrivfil_ptr = (UInt8)DDS_M_MAP2D_U16(&TQSYS_NOGEARCORDDRIVFIL_T_APM,
                                                        (UInt16)copt_nogearcorddrivfil_par);
}




/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Pre_Treat_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Pre_Treat_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDiDrivFilReq_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_nDif_nEngNTrb_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearCordDrivFil_swc_out, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_stDrivFilCfPha_swc_out )
{
    /* INIT MACROS */
    DDS_M_EDGE_DETECT_INIT(&pfilfast_edge_detect_ptr,
                            DDS_FALSE);

    DDS_M_HYST_U32_INIT (&pfilfast_hyst_u32_ptr,
                            DDS_TRUE);

    pfilfast_f01_f03_filter_init = DDS_FALSE;

    /* INIT PREV */
    pfilfast_tqsys_stdrivfilcfpha_prev = PFILFAST_CONF_1;

    /* INIT OUTPUTS */
    *TqSys_bDiDrivFilReq_swc_out = DDS_FALSE;
    *TqSys_nDif_nEngNTrb_swc_out = (0 * BIN2);
    *TqSys_stDrivFilCfPha_swc_out = PFILFAST_CONF_0;
    *TqSys_noGearCordDrivFil_swc_out = (0 * BIN0);

    /* INIT RUN_OUT */
    TqSys_bClrCrossOff = DDS_FALSE;
    TqSys_bClrCrossOn = DDS_FALSE;
    TqSys_facGainDiDrivFil = (0 * BIN7);
    TqSys_nTrb = (0 * BIN2);
    TqSys_tqACLossFil = (0 * BIN4);

    /*INIT Intern */
    TqSys_bDrivFilTakeOff = DDS_FALSE;
    TqSys_bDiDrivFilCfReq = DDS_FALSE;
    TqSys_stDrivFilCf = PFILFAST_CONF_0;
}



#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 10:07:10
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
CoPt_nTrb ; ;COPT ;rpm ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime turbine (Arbre primaire) ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_noDrivFilTyp ;["DESACTIVE"*0*|"TYPE_1"*1*|"TYPE_1_POND"*2*|"TYPE_2"*3*|"TYPE_2_POND"*4*] ;COPT ;N/A ;0 ;4 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Type d agrément préventif demandé ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_noGearCordDrivFil ;["RAPPORT_EQUIVALENT_0"*0*|"RAPPORT_EQUIVALENT_1"*1*|"RAPPORT_EQUIVALENT_2"*2*|"RAPPORT_EQUIVALENT_3"*3*|"RAPPORT_EQUIVALENT_4"*4*|"RAPPORT_EQUIVALENT_5"*5*|"RAPPORT_EQUIVALENT_6"*6*|"RAPPORT_EQUIVALENT_7"*7*|"RAPPORT_EQUIVALENT_8"*8*] ;COPT ;N/A ;0 ;8 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite pour les fonctions d'agrément ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Eng_nCkFil ; ;ENG ;rpm ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime moteur filtré envoyé à 10ms ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_bDiDrivFilReq ;["FALSE"|"TRUE"] ;EXT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Permet de désactiver en douceur la stratégie ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_stGBxCf ;["BVM"*0*|"BVA"*1*|"BVMP"*2*] ;EXT ;N/A ;0 ;2 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Type de boîte ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
FRM_bDft_spdVeh ;["FALSE"|"TRUE"] ;FRM ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Défault de vitesse véhicule ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqClrCros_bAcvClrCross ;["FALSE"|"TRUE"] ;TQCLRCROS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Détection externe de franchissement de jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqACLoss ; ;TQS ;Nm ;0 ;500 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple prélevé par le compresseur de climatisation ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqDem_bDrivTakeOff ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag de décollage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng_A ;1{t_pfilfast_neng_a}PFILFAST_10_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de regime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGear_A ;1{t_pfilfast_nogear_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de rapport de boite ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Veh_spdVeh ; ;VEH ;km/h ;0 ;500 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Vitesse véhicule ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
TqSys_bClrCrossOff ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique la sortie de la phase de traversée des jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bClrCrossOn ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l’entrée dans la phase de traversée des jeux ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainDiDrivFil ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Coefficient utilisé dans la phase de désactivation ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nDif_nEngNTrb ; ;TQS ;rpm ;-8000 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Difference entre le régime moteur filtré et le régime de l'arbre primaire de la boite de vitesse ;["YES"] ;SInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nTrb ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Regime de l arbre primaire de la boite de vitesse utilise dans la strategie ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil ; ;TQSYS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilise dans la strategie ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_stDrivFilCfPha ;["CONF_0"*0*|"CONF_1"*1*|"CONF_2"*2*|"CONF_3"*3*|"CONF_4"*4*] ;TQS ;N/A ;0 ;4 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat de configuration du filtrage utilisé dans les calculs des coefficients ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqACLossFil ; ;TQSYS ;N.m ;0 ;500 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple filtré prélevé par le compresseur de climatisation ;["YES"] ;UInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDiDrivFilReq ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen de desactivation la strategie filtration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
PFILFAST_10_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ;10 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_7_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;7 ;7 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_9_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;9 ;9 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDiDrivFil_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Permet de désactiver la stratégie ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facGainDiDrivFil_M ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;TqSys_noGearCordDrivFil ;N/A ;[1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1 1 1] ;Coefficient du filtre passe-bas pendant la phase de désactivation du filtrage ;["YES"] ;DDS_M_MAP3D_U16 ;BIN7 ;TqSys_nEng_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil_A ;1{pfilfast_nogearcorddrivfil_a}PFILFAST_9_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 1 2 3 4 5 6 7 8] ;Entrée du rapport de boite en 8 ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil_T ; ;TQS ;N/A ;0 ;6 ;1 ;["MAP"] ;["N/A"] ;CoPt_noGearCordDrivFil ;N/A ;N/A ;[0 1 2 3 4 5 6 6 6] ;Vecteur du rapport de boite limité à 8 ;["YES"] ;DDS_M_MAP2D_U16 ;BIN0 ;TqSys_noGearCordDrivFil_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_spdVehHys_bTkOff_C ; ;TQSYS ;km/h ;0 ;500 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2 ;Valeur de vitesse véhicule pour hysteresis ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiFilTqACLoss_C ; ;TQSYS ;N/A ;0 ;1 ;0.1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.1 ;Constante de temps de filtrage du couple clim ;["YES"] ;UInt8 ;DEC1 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Tq_spdVehThd_bTkOff_T ; ;TQS ;km/h ;0 ;500 ;1/128 ;["MAP"] ;["N/A"] ;TqSys_noGearCordDrivFil ;N/A ;N/A ;[255 4 4 4 4 4 4] ;Seuil de vitesse véhicule sous lequel on est en décollage ;["YES"] ;DDS_M_MAP2D_U16 ;BIN7 ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A ;N/A
pfilfast_nogearcorddrivfil_a ; ;PFILFAST ;N/A ;0 ;8 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_noGearCordDrivFil_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng_a ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_nogear_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_noGear_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDiDrivFilCfReq ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Demande de désactivation du filtrage issue de la configuration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDrivFilTakeOff ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique si le véhicule n'est plus en phase de décollage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_stDrivFilCf ;["CONF_0"*0*|"CONF_1"*1*|"CONF_2"*2*|"CONF_3"*3*|"CONF_4"*4*] ;TQSYS ;N/A ;0 ;4 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique si le véhicule n'est plus en phase de décollage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Data_Dictionary */

