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
* Ref X:\integration_view_00PSASWC_EA01D01\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Anti_Stall_Param.c
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 41 m User:meme 
*    TWK_model:COCLLASL_Anti_Stall_Param_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 1/10/2010 12 h 29 m User:morisseau 
*    TWK_model:COCLLASL_Anti_Stall_Param_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 17/9/2010 15 h 3 m User:morisseau 
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 56 m User:esnault
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\9 Date: 1/9/2010 9 h 54 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\8 Date: 31/8/2010 17 h 42 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\7 Date: 26/8/2010 9 h 36 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :fo CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 29/7/2010 17 h 33 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 22/7/2010 11 h 35 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 20/7/2010 10 h 51 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 20/7/2010 9 h 3 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 19/7/2010 17 h 48 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 39 m User:morisseau
*    TWK_model:COCLLASL_Anti_Stall_Param_L01_010_IMPL1
*    comments :work in progress
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "CoClLASl.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define COCLLASL_MOVEOFF_CTRL_OFF            0
#define COCLLASL_MOVEOFF_CTRL_ON             1
#define COCLLASL_MOVEOFF_CTRL_DISABLED       2

#define COCLLASL_EXT_STGBXCF_BVM             0

#define COCLLASL_10_DEC3                    (UInt32)(10 * DEC3)
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
#define COCLLASL_START_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEngThdAcvAntiStall_C = (CONST(UInt16, AUTOMATIC))(2000 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyDiAntiStall_C = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiDlyEnaAntiStall_C = (CONST(UInt16, AUTOMATIC))(0 * DEC2);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits scalar calibration definition */
#define COCLLASL_START_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTypDiAntiStall_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTypEnaAntiStall_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_noEngSpdAcceAntiStall_C = (CONST(UInt8, AUTOMATIC))(2 * BIN0);
#define COCLLASL_STOP_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COCLLASL_START_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_aEngThdAcvAntiStall_T
[COCLLASL_6_SIZE] = {
(SInt16)(-600 * BIN2), (SInt16)(-600 * BIN2), (SInt16)(-600 * BIN2),
(SInt16)(-600 * BIN2), (SInt16)(-600 * BIN2), (SInt16)(-600 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facAntiStall1_T
[COCLLASL_6_SIZE] = {
(UInt16)(0 * BIN14), (UInt16)(0 * BIN14), (UInt16)(0 * BIN14),
(UInt16)(0 * BIN14), (UInt16)(0 * BIN14), (UInt16)(0 * BIN14)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facAntiStall2_T
[COCLLASL_6_SIZE] = {
(UInt16)(0 * BIN14), (UInt16)(0 * BIN14), (UInt16)(0 * BIN14),
(UInt16)(0 * BIN14), (UInt16)(0 * BIN14), (UInt16)(0 * BIN14)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facAntiStall3_T
[COCLLASL_6_SIZE] = {
(UInt16)(0 * BIN14), (UInt16)(0 * BIN14), (UInt16)(0 * BIN14),
(UInt16)(0 * BIN14), (UInt16)(0 * BIN14), (UInt16)(0 * BIN14)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facCorAntiStallX_A[COCLLASL_8_SIZE] = {
(SInt16)(-500 * BIN2), (SInt16)(-300 * BIN2), (SInt16)(-200 * BIN2),
(SInt16)(-100 * BIN2), (SInt16)(100 * BIN2), (SInt16)(200 * BIN2),
(SInt16)(300 * BIN2), (SInt16)(500 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_facCorAntiStallY_A[COCLLASL_8_SIZE] = {
(SInt16)(-500 * BIN2), (SInt16)(-300 * BIN2), (SInt16)(-200 * BIN2),
(SInt16)(-100 * BIN2), (SInt16)(100 * BIN2), (SInt16)(200 * BIN2),
(SInt16)(300 * BIN2), (SInt16)(500 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facCorAntiStall_M
[COCLLASL_8_SIZE][COCLLASL_8_SIZE] = {
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) },
{
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10), (UInt16)(1 * BIN10),
(UInt16)(1 * BIN10), (UInt16)(1 * BIN10) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_nThdDiAntiStall_T
[COCLLASL_6_SIZE] = {
(SInt16)(750 * BIN2), (SInt16)(750 * BIN2), (SInt16)(750 * BIN2),
(SInt16)(750 * BIN2), (SInt16)(750 * BIN2), (SInt16)(750 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_nThdEnaAntiStall_T
[COCLLASL_6_SIZE] = {
(SInt16)(700 * BIN2), (SInt16)(700 * BIN2), (SInt16)(700 * BIN2),
(SInt16)(700 * BIN2), (SInt16)(700 * BIN2), (SInt16)(700 * BIN2)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tCoMesAntiStall_A[COCLLASL_6_SIZE] = {
(SInt16)(-30 * BIN0), (SInt16)(0 * BIN0), (SInt16)(20 * BIN0),
(SInt16)(40 * BIN0), (SInt16)(60 * BIN0), (SInt16)(100 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiStrtAntiStall_T
[COCLLASL_6_SIZE] = {
(UInt16)(0 * DEC0), (UInt16)(0 * DEC0), (UInt16)(0 * DEC0),
(UInt16)(0 * DEC0), (UInt16)(0 * DEC0), (UInt16)(0 * DEC0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqIdcThdAcvAntiStall_T
[COCLLASL_6_SIZE] = {
(SInt16)(50 * BIN4), (SInt16)(50 * BIN4), (SInt16)(50 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(50 * BIN4), (SInt16)(50 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaThdAcvAntiStall_T
[COCLLASL_6_SIZE] = {
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4)
};

#define COCLLASL_STOP_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_aengthdacvantistall_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facantistall1_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facantistall2_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facantistall3_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_faccorantistall_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_nthddiantistall_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_nthdenaantistall_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tistrtantistall_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqdeltathdacvantistall_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_tqidcthdacvantistall_t_sav;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) cocllasl_anti_stall_f02_hyst;
#define COCLLASL_STOP_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/* 8bits variable definition */
#define COCLLASL_START_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) tqsys_bacvantistallman_prev;
#define COCLLASL_STOP_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"

/* 16bits variable definition */
#define COCLLASL_START_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) treattdc_nckgrd_prev[COCLLASL_10_SIZE];
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqidcreq_prev;
STATIC VAR(UInt16, AUTOMATIC) tqsys_facantistall1_prev;
STATIC VAR(UInt16, AUTOMATIC) tqsys_facantistall2_prev;
STATIC VAR(UInt16, AUTOMATIC) tqsys_facantistall3_prev;
STATIC VAR(UInt16, AUTOMATIC) tqsys_factqckantistall_prev;
#define COCLLASL_STOP_SEC_VAR_16BIT
#include "CoClLASl_MemMap.h"

/* 32bits variable definition */
#define COCLLASL_START_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqsys_tiinidiantistall_temp_dec3;
STATIC VAR(UInt32, AUTOMATIC) tqsys_tiinienaantistall_temp_dec3;
#define COCLLASL_STOP_SEC_VAR_32BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nCkGrdDly; /* BIN2 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_nErrAntiStall_MP; /* BIN2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyDiAntiStall; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiDlyEnaAntiStall; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiIniEnaAntiStall; /* DEC2 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) TqSys_tiIniDiAntiStall; /* DEC2 */
#define COCLLASL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcvAntiStallClc;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAntiStallAuth;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDiAntiStall;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bEnaAntiStall;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_stAntiStallLvl; /* BIN0 */
#define COCLLASL_STOP_SEC_INTERNAL_VAR_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COCLLASL_START_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_AENGTHDACVANTISTALL_T_APM = {
&tqsys_aengthdacvantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_aEngThdAcvAntiStall_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_FACANTISTALL1_T_APM = {
&tqsys_facantistall1_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facAntiStall1_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_FACANTISTALL2_T_APM = {
&tqsys_facantistall2_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facAntiStall2_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_FACANTISTALL3_T_APM = {
&tqsys_facantistall3_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facAntiStall3_T[0]
};

STATIC CONST(t_dds_m_map3d_ssu16, AUTOMATIC) TQSYS_FACCORANTISTALL_M_APM = {
&tqsys_faccorantistall_m_sav,
COCLLASL_8_SIZE,
COCLLASL_8_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorAntiStallX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorAntiStallY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facCorAntiStall_M[0][0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_NTHDDIANTISTALL_T_APM = {
&tqsys_nthddiantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nThdDiAntiStall_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_NTHDENAANTISTALL_T_APM = {
&tqsys_nthdenaantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nThdEnaAntiStall_T[0]
};

STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQSYS_TISTRTANTISTALL_T_APM = {
&tqsys_tistrtantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiStrtAntiStall_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_TQDELTATHDACVANTISTALL_T_APM = {
&tqsys_tqdeltathdacvantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaThdAcvAntiStall_T[0]
};

STATIC CONST(t_dds_m_map2d_s16, AUTOMATIC) TQSYS_TQIDCTHDACVANTISTALL_T_APM = {
&tqsys_tqidcthdacvantistall_t_sav,
COCLLASL_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tCoMesAntiStall_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqIdcThdAcvAntiStall_T[0]
};

#define COCLLASL_STOP_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */


STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Activation_Calcul(
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 tqsys_btypfu_par,
                                           UInt16 ext_neng_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Parametrages(
                                           UInt8 copt_bcludiegdcord_par,
                                           UInt32 eom_tiengrun_par, /* BIN0 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 tqsys_bidlacvcmn_par,
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 tqsys_tqidcreq_par, /* BIN4 */
                                           SInt16 treattdc_nckgrd_par, /* BIN2 */
                                           SInt16 treattdc_ncktdcdelta_par, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallman_ptr,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall1_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall2_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall3_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_factqckantistall_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_01_Parametres(
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 treattdc_ncktdcdelta_par, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall1_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall2_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall3_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_factqckantistall_ptr /* BIN10 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_02_calcul_GradientRegime_dephase(
                                           SInt16 treattdc_nckgrd_par /* BIN2 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_03_Activation(
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 tqsys_tqidcreq_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_04_Autorisation(
                                           UInt32 eom_tiengrun_par, /* BIN0 */
                                           UInt8 tqsys_bidlacvcmn_par,
                                           UInt8 copt_bcludiegdcord_par,
                                           SInt16 ext_tcomes_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_05_Superviseur(
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallman_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Anti_Stall_Param
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Anti_Stall_Param(UInt8 CoPt_bCluDiEgdCord_swc_in,
                                           UInt32 EOM_tiEngRun_swc_in, /* BIN0 */
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 TqSys_bIdlAcvCmn_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt16 TqSys_nTarDynIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqIdcReq_swc_in, /* BIN4 */
                                           SInt16 TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                           SInt16 TreatTDC_nCkTDCDelta_swc_in, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallMan_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall1_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall2_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall3_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facTqCkAntiStall_swc_out /* BIN10 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.1.0 */

    COCLLASL_F02_Activation_Calcul(Ext_stGBxCf_swc_in,
                                   TqSys_bTypFu_swc_in,
                                   Ext_nEng_swc_in /* BIN0 */);

    if((UInt32)TqSys_bAcvAntiStallClc != (UInt32)DDS_FALSE)
    {
        COCLLASL_F03_Parametrages(CoPt_bCluDiEgdCord_swc_in,
                                  EOM_tiEngRun_swc_in, /* BIN0 */
                                  Ext_nEng_swc_in, /* BIN0 */
                                  Ext_tCoMes_swc_in, /* BIN0 */
                                  Ext_tiTDC_swc_in, /* DEC3 */
                                  TqSys_bIdlAcvCmn_swc_in,
                                  TqSys_nTarDynIdl_swc_in, /* BIN2 */
                                  TqSys_tqIdcReq_swc_in, /* BIN4 */
                                  TreatTDC_nCkGrd_swc_in, /* BIN2 */
                                  TreatTDC_nCkTDCDelta_swc_in, /* BIN2 */
                                  TqSys_bAcvAntiStallMan_swc_out,
                                  TqSys_facAntiStall1_swc_out, /* BIN14 */
                                  TqSys_facAntiStall2_swc_out, /* BIN14 */
                                  TqSys_facAntiStall3_swc_out, /* BIN14 */
                                  TqSys_facTqCkAntiStall_swc_out /* BIN10 */);
    }
    else
    {
        *TqSys_bAcvAntiStallMan_swc_out = tqsys_bacvantistallman_prev;
        *TqSys_facAntiStall1_swc_out = tqsys_facantistall1_prev;
        *TqSys_facAntiStall2_swc_out = tqsys_facantistall2_prev;
        *TqSys_facAntiStall3_swc_out = tqsys_facantistall3_prev;
        *TqSys_facTqCkAntiStall_swc_out = tqsys_factqckantistall_prev;
    }

    tqsys_bacvantistallman_prev = *TqSys_bAcvAntiStallMan_swc_out;
    tqsys_facantistall1_prev = *TqSys_facAntiStall1_swc_out;
    tqsys_facantistall2_prev = *TqSys_facAntiStall2_swc_out;
    tqsys_facantistall3_prev = *TqSys_facAntiStall3_swc_out;
    tqsys_factqckantistall_prev = *TqSys_facTqCkAntiStall_swc_out;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F02_Activation_Calcul
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_Activation_Calcul(
                                           UInt8 ext_stgbxcf_par,
                                           UInt8 tqsys_btypfu_par,
                                           UInt16 ext_neng_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.2.0 */
    UInt32 cocllasl_anti_stall_f02_hyst_out;

    cocllasl_anti_stall_f02_hyst_out = (UInt32)DDS_M_HYST_PH_S32(&cocllasl_anti_stall_f02_hyst,
                                                      (SInt32)ext_neng_par,
                                                      (SInt32)TqSys_nEngThdAcvAntiStall_C,
                                                      (SInt32)TqSys_nEngThdAcvAntiStall_C - (SInt32)50);

    if(  (cocllasl_anti_stall_f02_hyst_out == (UInt32)DDS_FALSE)
       &&((UInt32)ext_stgbxcf_par == (UInt32)COCLLASL_EXT_STGBXCF_BVM)
       &&((UInt32)tqsys_btypfu_par == (UInt32)DDS_FALSE))
    {
        TqSys_bAcvAntiStallClc = DDS_TRUE;
    }
    else
    {
        TqSys_bAcvAntiStallClc = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_Parametrages
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Parametrages(
                                           UInt8 copt_bcludiegdcord_par,
                                           UInt32 eom_tiengrun_par, /* BIN0 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 tqsys_bidlacvcmn_par,
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 tqsys_tqidcreq_par, /* BIN4 */
                                           SInt16 treattdc_nckgrd_par, /* BIN2 */
                                           SInt16 treattdc_ncktdcdelta_par, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallman_ptr,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall1_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall2_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall3_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_factqckantistall_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.3.0 */
    COCLLASL_F03_01_Parametres(
                  ext_tcomes_par, /* BIN0 */
                  ext_neng_par, /* BIN0 */
                  tqsys_ntardynidl_par, /* BIN2 */
                  treattdc_ncktdcdelta_par, /* BIN2 */
                  tqsys_facantistall1_ptr, /* BIN14 */
                  tqsys_facantistall2_ptr, /* BIN14 */
                  tqsys_facantistall3_ptr, /* BIN14 */
                  tqsys_factqckantistall_ptr /* BIN10 */);

    COCLLASL_F03_02_calcul_GradientRegime_dephase(
                  treattdc_nckgrd_par /* BIN2 */);

    COCLLASL_F03_03_Activation(
                  ext_tcomes_par, /* BIN0 */
                  ext_neng_par, /* BIN0 */
                  tqsys_ntardynidl_par, /* BIN2 */
                  tqsys_tqidcreq_par /* BIN4 */);

    COCLLASL_F03_04_Autorisation(
                  eom_tiengrun_par, /* BIN0 */
                  tqsys_bidlacvcmn_par,
                  copt_bcludiegdcord_par,
                  ext_tcomes_par /* BIN0 */);

    COCLLASL_F03_05_Superviseur(
                  ext_titdc_par, /* DEC3 */
                  tqsys_bacvantistallman_ptr);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_01_Parametres
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_01_Parametres(
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 treattdc_ncktdcdelta_par, /* BIN2 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall1_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall2_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_facantistall3_ptr, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_factqckantistall_ptr /* BIN10 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.4.0 */

    *tqsys_facantistall1_ptr = DDS_M_MAP2D_SU16(&TQSYS_FACANTISTALL1_T_APM,ext_tcomes_par);
    *tqsys_facantistall2_ptr = DDS_M_MAP2D_SU16(&TQSYS_FACANTISTALL2_T_APM,ext_tcomes_par);
    *tqsys_facantistall3_ptr = DDS_M_MAP2D_SU16(&TQSYS_FACANTISTALL3_T_APM,ext_tcomes_par);

    TqSys_nErrAntiStall_MP = (SInt16)((SInt32)tqsys_ntardynidl_par - (((SInt32)ext_neng_par)*BIN2));

    *tqsys_factqckantistall_ptr = DDS_M_MAP3D_SSU16(&TQSYS_FACCORANTISTALL_M_APM,TqSys_nErrAntiStall_MP,treattdc_ncktdcdelta_par);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_02_calcul_GradientRegime_dephase
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_02_calcul_GradientRegime_dephase(
                                           SInt16 treattdc_nckgrd_par /* BIN2 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.5.0 */
    SInt32 index;

    if((UInt32)TqSys_noEngSpdAcceAntiStall_C == (UInt32)0)
    {
        TqSys_nCkGrdDly = treattdc_nckgrd_par;
    }
    else
    {
        index = ((SInt32)TqSys_noEngSpdAcceAntiStall_C - 1);
        TqSys_nCkGrdDly = treattdc_nckgrd_prev[index];
    }

    treattdc_nckgrd_prev[9] = treattdc_nckgrd_prev[8];
    treattdc_nckgrd_prev[8] = treattdc_nckgrd_prev[7];
    treattdc_nckgrd_prev[7] = treattdc_nckgrd_prev[6];
    treattdc_nckgrd_prev[6] = treattdc_nckgrd_prev[5];
    treattdc_nckgrd_prev[5] = treattdc_nckgrd_prev[4];
    treattdc_nckgrd_prev[4] = treattdc_nckgrd_prev[3];
    treattdc_nckgrd_prev[3] = treattdc_nckgrd_prev[2];
    treattdc_nckgrd_prev[2] = treattdc_nckgrd_prev[1];
    treattdc_nckgrd_prev[1] = treattdc_nckgrd_prev[0];
    treattdc_nckgrd_prev[0] = treattdc_nckgrd_par;
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_03_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_03_Activation(
                                           SInt16 ext_tcomes_par, /* BIN0 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           UInt16 tqsys_ntardynidl_par, /* BIN2 */
                                           SInt16 tqsys_tqidcreq_par /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.6.0 */
    SInt32 cocllasl_f03_03_value1;
    SInt32 cocllasl_f03_03_value2;
    SInt32 cocllasl_f03_03_value3;

    SInt32 cocllasl_f03_03_switch1_out;
    SInt32 cocllasl_f03_03_switch2_out;


    cocllasl_f03_03_value1 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_AENGTHDACVANTISTALL_T_APM,ext_tcomes_par);

    cocllasl_f03_03_value2 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_TQIDCTHDACVANTISTALL_T_APM,ext_tcomes_par);

    cocllasl_f03_03_value3 = (SInt32)DDS_M_MAP2D_S16(&TQSYS_TQDELTATHDACVANTISTALL_T_APM,ext_tcomes_par);


    cocllasl_f03_03_switch1_out = (SInt32)DDS_M_MAP2D_S16(&TQSYS_NTHDENAANTISTALL_T_APM,ext_tcomes_par);
    if((UInt32)TqSys_bTypDiAntiStall_C != (UInt32)DDS_FALSE)
    {
        cocllasl_f03_03_switch1_out = (SInt32)tqsys_ntardynidl_par - cocllasl_f03_03_switch1_out;
    }
    else
    {
        /* DO NOTHING */
    }

    cocllasl_f03_03_switch2_out = (SInt32)tqsys_tqidcreq_par - (SInt32)tqsys_tqidcreq_prev;

    if(  ((SInt32)TqSys_nCkGrdDly > cocllasl_f03_03_value1)
       &&((SInt32)tqsys_tqidcreq_par > cocllasl_f03_03_value2)
       &&(cocllasl_f03_03_switch2_out > cocllasl_f03_03_value3)
       &&((((SInt32)ext_neng_par)*BIN2) <= cocllasl_f03_03_switch1_out))
    {
        TqSys_bEnaAntiStall = DDS_TRUE;
    }
    else
    {
        TqSys_bEnaAntiStall = DDS_FALSE;
    }

    cocllasl_f03_03_switch2_out = (SInt32)DDS_M_MAP2D_S16(&TQSYS_NTHDDIANTISTALL_T_APM,ext_tcomes_par);
    if((UInt32)TqSys_bTypEnaAntiStall_C != (UInt32)DDS_FALSE)
    {
        cocllasl_f03_03_switch2_out = (SInt32)tqsys_ntardynidl_par - cocllasl_f03_03_switch2_out;
    }
    else
    {
        /* DO NOTHING */
    }

    if((((SInt32)ext_neng_par)*BIN2) >= cocllasl_f03_03_switch2_out)
    {
        TqSys_bDiAntiStall = DDS_TRUE;
    }
    else
    {
        TqSys_bDiAntiStall = DDS_FALSE;
    }


    tqsys_tqidcreq_prev = tqsys_tqidcreq_par;
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_04_Autorisation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_04_Autorisation(
                                           UInt32 eom_tiengrun_par, /* BIN0 */
                                           UInt8 tqsys_bidlacvcmn_par,
                                           UInt8 copt_bcludiegdcord_par,
                                           SInt16 ext_tcomes_par /* BIN0 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.7.0 */
    UInt32 cocllasl_f03_03_value1;

    cocllasl_f03_03_value1 = (UInt32)DDS_M_MAP2D_SU16(&TQSYS_TISTRTANTISTALL_T_APM,ext_tcomes_par);

    if(  (eom_tiengrun_par > cocllasl_f03_03_value1)
       &&((UInt32)tqsys_bidlacvcmn_par == (UInt32)DDS_TRUE)
       &&((UInt32)copt_bcludiegdcord_par == (UInt32)DDS_TRUE))
    {
        TqSys_bAntiStallAuth = DDS_TRUE;
    }
    else
    {
        TqSys_bAntiStallAuth = DDS_FALSE;
    }

    TqSys_tiDlyDiAntiStall = TqSys_tiDlyDiAntiStall_C;

    TqSys_tiDlyEnaAntiStall = TqSys_tiDlyEnaAntiStall_C;
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_05_Superviseur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_05_Superviseur(
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistallman_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT07_2167.FR.8.0 */

    switch((UInt32)TqSys_stAntiStallLvl)
    {
        case (UInt32)COCLLASL_MOVEOFF_CTRL_ON:
            if(  ((UInt32)TqSys_bAntiStallAuth == (UInt32)DDS_FALSE)
               ||((UInt32)TqSys_bDiAntiStall != (UInt32)DDS_FALSE)
               ||((UInt32)TqSys_tiIniEnaAntiStall >= (UInt32)TqSys_tiDlyEnaAntiStall)   )
            {
                TqSys_stAntiStallLvl = COCLLASL_MOVEOFF_CTRL_DISABLED;
                *tqsys_bacvantistallman_ptr = DDS_FALSE;
            }
            else
            {
                *tqsys_bacvantistallman_ptr = DDS_TRUE;
                /* DEC3 = (DEC2 * DEC1) + DEC3 */
                tqsys_tiinienaantistall_temp_dec3 = DDS_M_LIMITED_INCREMENT(tqsys_tiinienaantistall_temp_dec3,
                                                                            (UInt32)ext_titdc_par,
                                                                            COCLLASL_10_DEC3);
                /* DEC2 = DEC3 / DEC1 */
                TqSys_tiIniEnaAntiStall = (UInt16)(tqsys_tiinienaantistall_temp_dec3 / DEC1);
            }
            break;
        case (UInt32)COCLLASL_MOVEOFF_CTRL_DISABLED:
            *tqsys_bacvantistallman_ptr = DDS_FALSE;
            if((UInt32)TqSys_tiIniDiAntiStall >= (UInt32)TqSys_tiDlyDiAntiStall)
            {
                TqSys_stAntiStallLvl = COCLLASL_MOVEOFF_CTRL_OFF;
                TqSys_tiIniEnaAntiStall = 0;
                TqSys_tiIniDiAntiStall = 0;
                tqsys_tiinidiantistall_temp_dec3 = 0;
                tqsys_tiinienaantistall_temp_dec3 = 0;
            }
            else
            {
                /* DEC3 = (DEC2 * DEC1) + DEC3*/
                tqsys_tiinidiantistall_temp_dec3 = DDS_M_LIMITED_INCREMENT(tqsys_tiinidiantistall_temp_dec3,
                                                                            (UInt32)ext_titdc_par,
                                                                            COCLLASL_10_DEC3);
                /* DEC2 = DEC3 / DEC1 */
                TqSys_tiIniDiAntiStall = (UInt16)(tqsys_tiinidiantistall_temp_dec3 / DEC1);
            }
            break;
        case (UInt32)COCLLASL_MOVEOFF_CTRL_OFF: /* init */
        default:
            if(  ((UInt32)TqSys_bAntiStallAuth == (UInt32)DDS_TRUE)
               &&((UInt32)TqSys_bEnaAntiStall == (UInt32)DDS_TRUE))
            {
                TqSys_stAntiStallLvl = COCLLASL_MOVEOFF_CTRL_ON;
                *tqsys_bacvantistallman_ptr = DDS_TRUE;
            }
            else
            {
                *tqsys_bacvantistallman_ptr = DDS_FALSE;
            }
            break;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Anti_Stall_Param_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Anti_Stall_Param_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStallMan_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall1_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall2_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facAntiStall3_swc_out, /* BIN14 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_facTqCkAntiStall_swc_out /* BIN10 */)
{
    TqSys_stAntiStallLvl = COCLLASL_MOVEOFF_CTRL_OFF;
    TqSys_tiIniEnaAntiStall = 0;
    /* DEC3 = DEC2 * DEC1 */
    tqsys_tiinienaantistall_temp_dec3 = (UInt32)TqSys_tiIniEnaAntiStall * DEC1;

    TqSys_tiIniDiAntiStall = 0;
    /* DEC3 = DEC2 * DEC1 */
    tqsys_tiinidiantistall_temp_dec3 = (UInt32)TqSys_tiIniDiAntiStall * DEC1;

    *TqSys_bAcvAntiStallMan_swc_out = DDS_FALSE;

    *TqSys_facAntiStall1_swc_out = 0;
    *TqSys_facAntiStall2_swc_out = 0;
    *TqSys_facAntiStall3_swc_out = 0;
    *TqSys_facTqCkAntiStall_swc_out = 0;

    DDS_M_HYST_S32_INIT(&cocllasl_anti_stall_f02_hyst,DDS_FALSE);

    treattdc_nckgrd_prev[0] = 0;
    treattdc_nckgrd_prev[1] = 0;
    treattdc_nckgrd_prev[2] = 0;
    treattdc_nckgrd_prev[3] = 0;
    treattdc_nckgrd_prev[4] = 0;
    treattdc_nckgrd_prev[5] = 0;
    treattdc_nckgrd_prev[6] = 0;
    treattdc_nckgrd_prev[7] = 0;
    treattdc_nckgrd_prev[8] = 0;
    treattdc_nckgrd_prev[9] = 0;

    tqsys_tqidcreq_prev = 0;

    TqSys_bAcvAntiStallClc = DDS_FALSE;
    TqSys_bAntiStallAuth = DDS_FALSE;
    TqSys_bDiAntiStall = DDS_FALSE;
    TqSys_bEnaAntiStall = DDS_FALSE;
    TqSys_nCkGrdDly = 0;
    TqSys_tiDlyDiAntiStall = 0;
    TqSys_tiDlyEnaAntiStall = 0;
    TqSys_nErrAntiStall_MP = 0;

    tqsys_bacvantistallman_prev = *TqSys_bAcvAntiStallMan_swc_out;
    tqsys_facantistall1_prev = *TqSys_facAntiStall1_swc_out;
    tqsys_facantistall2_prev = *TqSys_facAntiStall2_swc_out;
    tqsys_facantistall3_prev = *TqSys_facAntiStall3_swc_out;
    tqsys_factqckantistall_prev = *TqSys_facTqCkAntiStall_swc_out;

}



#define COCLLASL_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoClLASl_MemMap.h"
