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
* Ref X:\integration_view_00PSASWC_E640D11\blois_psa_sstg\Software\Appli\PFilFast\src\PFILFAST_Filt_Activ.c
* Version int :/main/C00_00/1 Date: 29/8/2013 11 h 44 m User:meme 
*    TWK_model:PFILFAST_Filt_Activ_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version dev :\main\branch_thauvin_euro6\1 Date: 5/8/2013 13 h 16 m User:thauvin 
*    TWK_model:PFILFAST_Filt_Activ_C00_000_IMPL1
*    comments :For PFilFast 14.0
* Version int :/main/L01_02/1 Date: 12/3/2012 15 h 13 m User:esnault
*    TWK_model:PFILFAST_Filt_Activ_L01_020_IMPL2
*    comments :for PFilFast 12.0: spec update
* Version dev :\main\branch_morisseau_pfilfast_euro6_dev\2 Date: 7/3/2012 13 h 39 m User:morisseau
*    TWK_model:PFILFAST_Filt_Activ_L01_020_IMPL2
*    comments :for PFilFast 12.0: spec update
* Version int :/main/L01_01/2 Date: 16/5/2011 15 h 6 m User:esnault
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1_D
*    comments :for CPU optimization
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 27/4/2011 14 h 20 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1_D
*    comments :for CPU optimization
* Version int :/main/L01_01/1 Date: 12/8/2010 12 h 39 m User:esnault
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\6 Date: 4/8/2010 14 h 44 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\5 Date: 16/7/2010 11 h 52 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\4 Date: 13/7/2010 12 h 20 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\3 Date: 7/7/2010 10 h 55 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\2 Date: 1/7/2010 15 h 30 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
*    comments :for PFilFast e6
* Version dev :\main\branch_demezil_pfilfast_dev\1 Date: 30/6/2010 14 h 14 m User:demezil
*    TWK_model:PFILFAST_Filt_Activ_L01_010_IMPL1
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

#define PFILFAST_8_SIZE                       8
#define PFILFAST_7_SIZE                       7


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
extern VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivFilRawPrev; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqSys_tqThdPha4; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

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
extern volatile CONST(UInt16, AUTOMATIC) TqSys_nEng1_A[PFILFAST_8_SIZE]; /* BIN2 */
extern volatile CONST(UInt16, AUTOMATIC) TqSys_noGear_A[PFILFAST_7_SIZE]; /* BIN0 */
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

/* 32-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivNotFil; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 8-bits variables definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
VAR(UInt8, AUTOMATIC) TqSys_bAcceAcv;
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
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaOfsAcce_C = (SInt16)(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsHighTq_C = (SInt16)(200 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThd_tqDeltaMinDece_C = (SInt16)(2000 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccPEngRstDeceThd_C = (UInt16)(0.1 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsCkDrivFilTqMax_C = (SInt16)(-15 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsDeceMax_C = (SInt16)(10 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsThdCll_C = (SInt16)(5 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccPThdTqCll_C = (UInt16)(3 * BIN7);
#define PFILFAST_STOP_SEC_CALIB_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits scalar calibration definition */
#define PFILFAST_START_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqCkDrivFilLimSel_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqMaxAcv_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDeceTqAir_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_tqOfsRstDece_C = (UInt8)(0.1 * BIN4);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bDeceTyp_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bnoGearDeceAcv_C = DDS_FALSE;
#define PFILFAST_STOP_SEC_CALIB_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define PFILFAST_START_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaMinAcce_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaMaxDiAcce_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) },
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) },
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) },
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) },
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) },
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) },
{
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4),
(SInt16)(2.5 * BIN4), (SInt16)(2.5 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqDeltaMaxDiAcceX_A[PFILFAST_8_SIZE] = {
(UInt16)(800 * BIN2), (UInt16)(1000 * BIN2), (UInt16)(1250 * BIN2),
(UInt16)(1500 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(2500 * BIN2),
(UInt16)(3000 * BIN2), (UInt16)(4000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqDeltaMaxDiAcceY_A[PFILFAST_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdCllAcv_M
[PFILFAST_7_SIZE][PFILFAST_7_SIZE] = {
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) },
{
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(150 * BIN4), (SInt16)(150 * BIN4),
(SInt16)(150 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqThdCllAcvX_A[PFILFAST_7_SIZE] = {
(SInt16)(-150 * BIN4), (SInt16)(0 * BIN4), (SInt16)(20 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(80 * BIN4), (SInt16)(130 * BIN4),
(SInt16)(200 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tqThdCllAcvY_A[PFILFAST_7_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(1 * BIN0), (UInt16)(2 * BIN0),
(UInt16)(3 * BIN0), (UInt16)(4 * BIN0), (UInt16)(5 * BIN0),
(UInt16)(6 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaMinDece_M
[PFILFAST_7_SIZE][PFILFAST_8_SIZE] = {
{
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4),
(SInt16)(2000 * BIN4), (SInt16)(2000 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) },
{
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4), (SInt16)(5 * BIN4),
(SInt16)(5 * BIN4), (SInt16)(5 * BIN4) }
};

#define PFILFAST_STOP_SEC_CARTO_16BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define PFILFAST_START_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltaminacce_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltamaxdiacce_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqthdcllacv_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltamindece_m_sav;
STATIC VAR(t_dds_m_edge_detect, AUTOMATIC) pfilfast_f03_01_04_edge_detect_ptr;
#define PFILFAST_STOP_SEC_VAR_UNSPECIFIED
#include "PFilFast_MemMap.h"

/* 32-bits variable definition */
#define PFILFAST_START_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqckdrivnotfilacce_prev;    /* BIN11 */
STATIC VAR(SInt32, AUTOMATIC) tqsys_tqckdrivfilrawprev_cpy;     /* BIN11 */
#define PFILFAST_STOP_SEC_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variable definition */
#define PFILFAST_START_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckdeceiniit_prev;
STATIC VAR(UInt16, AUTOMATIC) tqsys_nengdeceini_prev;
STATIC VAR(SInt16, AUTOMATIC) tqcmp_tqsumlosscmp_dly;
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqthdpha4_cpy; /* BIN4 */
#define PFILFAST_STOP_SEC_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) pfilfast_f03_01_03_tqsys_bdecereqraw;
STATIC VAR(UInt8, AUTOMATIC) tqsys_bdeceacvit_prev;
#define PFILFAST_STOP_SEC_VAR_8BIT
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivNotFilGsl; /* BIN11 */
_DDS_STATIC_ VAR(SInt32, AUTOMATIC) TqSys_tqCkDrivNotFilAcce; /* BIN11 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_32BIT
#include "PFilFast_MemMap.h"

/* 16-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqDeltaMinAcce; /* BIN4 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_16BIT
#include "PFilFast_MemMap.h"

/* 8-bits variable definition */
#define PFILFAST_START_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceAcvTqMax;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceDi;
/* <PRQA_COMMENT><3229> displayable variable </3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bAcceReq_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceReq_MP;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_bDeceAcvRaw;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) TqSys_noGearDeceIniIt; /* BIN0 */
#define PFILFAST_STOP_SEC_INTERNAL_VAR_8BIT
#include "PFilFast_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define PFILFAST_START_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"
STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQDELTAMINACCE_M_APM = {
&tqsys_tqdeltaminacce_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMinAcce_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQDELTAMAXDIACCE_M_APM = {
&tqsys_tqdeltamaxdiacce_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMaxDiAcceX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMaxDiAcceY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMaxDiAcce_M[0][0]
};

STATIC CONST(t_dds_m_map3d_sus16, AUTOMATIC) TQSYS_TQTHDCLLACV_M_APM = {
&tqsys_tqthdcllacv_m_sav,
PFILFAST_7_SIZE,
PFILFAST_7_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdCllAcvX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdCllAcvY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqThdCllAcv_M[0][0]
};

STATIC CONST(t_dds_m_map3d_uus16, AUTOMATIC) TQSYS_TQDELTAMINDECE_M_APM = {
&tqsys_tqdeltamindece_m_sav,
PFILFAST_8_SIZE,
PFILFAST_7_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEng1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_noGear_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaMinDece_M[0][0]
};

#define PFILFAST_STOP_SEC_CONST_UNSPECIFIED
#include "PFilFast_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define PFILFAST_START_SEC_CODE
#include "PFilFast_MemMap.h"

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_01_Driver_Torqe_Unfiltered(SInt16 tqlimem_tqlimem_par, /* BIN4 */
                                                                        SInt16 englim_tqckdrivfil_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_02_Acceleration_Detection( UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_bdidrivfilreq_par,
                                                                        UInt8 tqsys_btypfu_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_02_01_Acceleration_Activation(UInt16 eng_nckfil_par, /* BIN2 */
                                                                           UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_02_02_Acceleration_Activation_Reset(
                                                                                    UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqsys_btypfu_par,
                                                                                    UInt8 tqsys_bdidrivfilreq_par);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_03_Deceleration_Detection(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                       SInt16 englim_tqckdrivfil_par, /* BIN4 */
                                                                       UInt16 eng_nckfil_par, /* BIN2 */
                                                                       UInt8 tqcll_bacvcll_par,
                                                                       SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                                                       SInt16 tqlimem_tqlimem_par, /* BIN4 */
                                                                       UInt8 tqsys_bdidrivfilreq_par,
                                                                       UInt8 tqsys_binjcutdynreq_par,
                                                                       UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bdeceacvit_ptr);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_04_Deceleration_Phase_Initializing(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_nengdeceini_ptr, /* BIN2 */
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_nogeardece_ptr, /* BIN0 */
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckdeceiniit_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_04_01_Deceleration_Phase_Init_Values(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_nengdeceini_ptr, /* BIN2 */
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckdeceiniit_ptr /* BIN4 */);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : PFILFAST_Filt_Activ
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Filt_Activ(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                           SInt16 EngLim_tqCkDrivFil_swc_in, /* BIN4 */
                                           UInt16 Eng_nCkFil_swc_in, /* BIN2 */
                                           UInt8 TqCll_bAcvCll_swc_in,
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                           UInt8 TqSys_bDiDrivFilReq_swc_in,
                                           UInt8 TqSys_bInjCutDynReq_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcvIt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nEngDeceIni_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearDece_swc_out, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIniIt_swc_out /* BIN4 */ )
{
    tqsys_tqckdrivfilrawprev_cpy = TqSys_tqCkDrivFilRawPrev;
	tqsys_tqthdpha4_cpy = TqSys_tqThdPha4;

    PFILFAST_F03_01_01_Driver_Torqe_Unfiltered(TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                               EngLim_tqCkDrivFil_swc_in);

    PFILFAST_F03_01_02_Acceleration_Detection(  Eng_nCkFil_swc_in, /* BIN2 */
                                                TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                TqSys_bDiDrivFilReq_swc_in,
                                                TqSys_bTypFu_swc_in);

    PFILFAST_F03_01_03_Deceleration_Detection(CoVSCtl_rAccPEng_swc_in, /* BIN7 */
                                               EngLim_tqCkDrivFil_swc_in, /* BIN4 */
                                               Eng_nCkFil_swc_in, /* BIN2 */
                                               TqCll_bAcvCll_swc_in,
                                               TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                               TqLimEM_tqLimEM_swc_in, /* BIN4 */
                                               TqSys_bDiDrivFilReq_swc_in,
                                               TqSys_bInjCutDynReq_swc_in,
                                               TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                               TqSys_bDeceAcvIt_swc_out);

    PFILFAST_F03_01_04_Deceleration_Phase_Initializing(Eng_nCkFil_swc_in, /* BIN2 */
                                                        TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
                                                        TqSys_nEngDeceIni_swc_out, /* BIN2 */
                                                        TqSys_noGearDece_swc_out, /* BIN0 */
                                                        TqSys_tqCkDeceIniIt_swc_out /* BIN4 */);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_01_Driver_Torqe_Unfiltered
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_01_Driver_Torqe_Unfiltered(SInt16 tqlimem_tqlimem_par, /* BIN4 */
                                                                        SInt16 englim_tqckdrivfil_par /* BIN4 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.12 */
    SInt32 temp_s32;

    /* BIN4 = BIN4 */
    temp_s32 = DDS_M_MIN((SInt32)tqlimem_tqlimem_par, (SInt32)englim_tqckdrivfil_par);

    /*BIN11 = BIN4 * BIN7 */
    TqSys_tqCkDrivNotFilAcce = temp_s32 * BIN7;

    if((UInt32)DDS_FALSE != (UInt32)TqSys_bTqCkDrivFilLimSel_C)
    {
        /* BIN11 = BIN11 */
        TqSys_tqCkDrivNotFilGsl = TqSys_tqCkDrivNotFilAcce;
    }
    else
    {
        /* BIN11 = BIN4 * BIN7 */
        TqSys_tqCkDrivNotFilGsl = (SInt32)tqlimem_tqlimem_par * BIN7;
    }

    if( ((UInt32)DDS_FALSE == (UInt32)TqSys_bDeceAcvTqMax) ||
        ((UInt32)DDS_FALSE != (UInt32)TqSys_bAcceAcv) ||
        ((UInt32)DDS_FALSE == (UInt32)TqSys_bTqMaxAcv_C) )
    {
        /* BIN11 = BIN11 */
        TqSys_tqCkDrivNotFil = TqSys_tqCkDrivNotFilGsl;
    }
    else
    {
        /* BIN11 = BIN4 * BIN7 */
        temp_s32 = (SInt32)englim_tqckdrivfil_par * BIN7;
        TqSys_tqCkDrivNotFil = DDS_M_MAX(TqSys_tqCkDrivNotFilGsl, temp_s32);
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_02_Acceleration_Detection
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_02_Acceleration_Detection( UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        UInt8 tqsys_bdidrivfilreq_par,
                                                                        UInt8 tqsys_btypfu_par)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.13.2 */
    PFILFAST_F03_01_02_01_Acceleration_Activation(eng_nckfil_par, /* BIN2 */
                                                    tqsys_nogearcorddrivfil_par /* BIN0 */);

    PFILFAST_F03_01_02_02_Acceleration_Activation_Reset(
                                                        eng_nckfil_par, /* BIN2 */
                                                        tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                        tqsys_btypfu_par,
                                                        tqsys_bdidrivfilreq_par);

    if((UInt32)DDS_FALSE != (UInt32)TqSys_bAcceDi)
    {
        TqSys_bAcceAcv = DDS_FALSE;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bAcceReq)
        {
            TqSys_bAcceAcv = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_02_01_Acceleration_Activation
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_02_01_Acceleration_Activation(UInt16 eng_nckfil_par, /* BIN2 */
                                                                           UInt8 tqsys_nogearcorddrivfil_par /* BIN0 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.14 */
    SInt32 temp_s32;

    TqSys_tqDeltaMinAcce = DDS_M_MAP3D_UUS16(&TQSYS_TQDELTAMINACCE_M_APM,
                                                eng_nckfil_par,
                                                (UInt16)tqsys_nogearcorddrivfil_par);

    if(tqsys_tqckdrivfilrawprev_cpy >= ((SInt32)tqsys_tqthdpha4_cpy * BIN7))
    {
        /* BIN11 = (BIN4 * BIN7) + (BIN4 * BIN7) + BIN11 */
        temp_s32 = (((SInt32)TqSys_tqDeltaMinAcce * BIN7) + ((SInt32)TqSys_tqDeltaOfsAcce_C * BIN7)) + tqsys_tqckdrivfilrawprev_cpy;
    }
    else
    {
        /* BIN11 = (BIN4 * BIN7) + BIN11 */
        temp_s32 = ((SInt32)TqSys_tqDeltaMinAcce * BIN7) + tqsys_tqckdrivfilrawprev_cpy;
    }

    if(TqSys_tqCkDrivNotFilAcce > temp_s32)
    {
        TqSys_bAcceReq = DDS_TRUE;
        TqSys_bAcceReq_MP = DDS_TRUE;
    }
    else
    {
        TqSys_bAcceReq = DDS_FALSE;
        TqSys_bAcceReq_MP = DDS_FALSE;
    }
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_02_02_Acceleration_Activation_Reset
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_02_02_Acceleration_Activation_Reset(
                                                                                    UInt16 eng_nckfil_par, /* BIN2 */
                                                                                    UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                                    UInt8 tqsys_btypfu_par,
                                                                                    UInt8 tqsys_bdidrivfilreq_par)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.15.1 */
    SInt32 tqsys_tqdeltamaxdiacce_m;
    SInt32 temp_s32;
    UInt8 tqsys_baccedi_tmp;

    tqsys_baccedi_tmp = DDS_FALSE;

    if((UInt32)DDS_FALSE == (UInt32)tqsys_bdidrivfilreq_par)
    {
        if(  ((UInt32)DDS_TRUE != (UInt32)tqsys_btypfu_par)
           ||(TqSys_tqCkDrivNotFilAcce > tqsys_tqckdrivfilrawprev_cpy)
           ||(TqSys_tqCkDrivNotFilAcce > tqsys_tqckdrivnotfilacce_prev))
        {
        }
        else
        {
            tqsys_baccedi_tmp = DDS_TRUE;
        }

        if((UInt32)DDS_FALSE == (UInt32)tqsys_baccedi_tmp)
        {
            tqsys_tqdeltamaxdiacce_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQDELTAMAXDIACCE_M_APM,
                                                                    eng_nckfil_par,
                                                                    (UInt16)tqsys_nogearcorddrivfil_par);

            /* BIN4 = DDS_M_MIN(BIN4, BIN4) */
            temp_s32 = DDS_M_MIN((SInt32)TqSys_tqDeltaMinAcce, tqsys_tqdeltamaxdiacce_m);

            /* BIN11 = (BIN4 * BIN7) + BIN11 */
            temp_s32 = (temp_s32 * BIN7) + tqsys_tqckdrivfilrawprev_cpy;

            if(TqSys_tqCkDrivNotFilAcce > temp_s32)
            {
                TqSys_bAcceDi = DDS_FALSE;
            }
            else
            {
                TqSys_bAcceDi = DDS_TRUE;
            }
        }
        else
        {
            TqSys_bAcceDi = DDS_TRUE;
        }
    }
    else
    {
        TqSys_bAcceDi = DDS_TRUE;
    }

    /* BIN11 = BIN11 */
    tqsys_tqckdrivnotfilacce_prev = TqSys_tqCkDrivNotFilAcce;

}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_03_Deceleration_Detection
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_03_Deceleration_Detection(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                       SInt16 englim_tqckdrivfil_par, /* BIN4 */
                                                                       UInt16 eng_nckfil_par, /* BIN2 */
                                                                       UInt8 tqcll_bacvcll_par,
                                                                       SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                                                       SInt16 tqlimem_tqlimem_par, /* BIN4 */
                                                                       UInt8 tqsys_bdidrivfilreq_par,
                                                                       UInt8 tqsys_binjcutdynreq_par,
                                                                       UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                       CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bdeceacvit_ptr)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.16.2 */
    SInt32 tqsys_tqthdcllacv_m;
    SInt32 tqsys_tqdeltamindece_m;
    UInt8 reset_flip_flop;
    SInt32 temp_s32;
    SInt32 tqsys_tqthdcll;

    /* calul maps */
    tqsys_tqdeltamindece_m = (SInt32)DDS_M_MAP3D_UUS16(&TQSYS_TQDELTAMINDECE_M_APM,
                                                        eng_nckfil_par,
                                                        (UInt16)tqsys_nogearcorddrivfil_par);

    /* calcul tqsys_bdecereqraw */
    /* BIN11 = BIN4 * BIN7 */
    temp_s32 = (SInt32)tqlimem_tqlimem_par * BIN7;
    /* Calcul reset condition for the first RS flip-flop*/
    if( ((UInt32)DDS_FALSE != (UInt32)tqsys_bdidrivfilreq_par) ||
        ((UInt32)DDS_FALSE != (UInt32)tqsys_binjcutdynreq_par) ||
        (temp_s32 >= tqsys_tqckdrivfilrawprev_cpy) )
    {
        reset_flip_flop = DDS_TRUE;
    }
    else
    {
        /* BIN11 == (BIN4 - BIN4) * BIN7 */
        temp_s32 = ((SInt32)TqSys_tqOfsRstDece_C - (SInt32)tqcmp_tqsumlosscmp_dly) * BIN7;
        if( ((UInt32)TqSys_rAccPEngRstDeceThd_C < (UInt32)covsctl_raccpeng_par) ||
            (temp_s32 < tqsys_tqckdrivfilrawprev_cpy) )
        {
            reset_flip_flop = DDS_FALSE;
        }
        else
        {
            reset_flip_flop = DDS_TRUE;
        }
    }
/* calcul TqSys_bDeceReq_MP */
    /* BIN11 = BIN4 * BIN7 */
    temp_s32 = (SInt32)TqSys_tqThd_tqDeltaMinDece_C * BIN7;
    if(tqsys_tqckdrivfilrawprev_cpy >= temp_s32)
    {
        /* BIN11 = BIN11 - ((BIN4 + BIN4) * BIN7)*/
        temp_s32 = tqsys_tqckdrivfilrawprev_cpy - (((SInt32)TqSys_tqOfsHighTq_C + tqsys_tqdeltamindece_m) * BIN7);
    }
    else
    {
        /* BIN11 = BIN11 - (BIN4 * BIN7) */
        temp_s32 = tqsys_tqckdrivfilrawprev_cpy - (tqsys_tqdeltamindece_m * BIN7);
    }
    /* BIN4 = BIN11 / BIN7 */
    temp_s32 = temp_s32 / BIN7;

    if(temp_s32 < (SInt32)tqlimem_tqlimem_par)
    {
        /* no output variation */
        TqSys_bDeceReq_MP = DDS_FALSE;
    }
    else
    {
        TqSys_bDeceReq_MP = DDS_TRUE;
    }

/* calcul pfilfast_f03_01_03_tqsys_bdecereqraw */
    if((UInt32)DDS_FALSE != (UInt32)reset_flip_flop)
    {
        /* reset RS flip-flop */
        pfilfast_f03_01_03_tqsys_bdecereqraw = DDS_FALSE;
    }
    else
    {
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bDeceReq_MP)
        {
            /* if set */
            pfilfast_f03_01_03_tqsys_bdecereqraw = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }

/* calcul outputs */
    /* reset condition for the RS1 flip-flop*/
    if( ((UInt32)DDS_FALSE != (UInt32)tqcll_bacvcll_par) ||
        ((UInt32)covsctl_raccpeng_par <= (UInt32)TqSys_rAccPThdTqCll_C) )
    {
        reset_flip_flop = DDS_TRUE;
    }
    else
    {
        /* BIN4 = BIN4 + BIN4 */
        temp_s32 = (SInt32)englim_tqckdrivfil_par + (SInt32)TqSys_tqOfsCkDrivFilTqMax_C;
        if((SInt32)tqlimem_tqlimem_par <= temp_s32)
        {
            reset_flip_flop = DDS_TRUE;
        }
        else
        {
            /* BIN11 = (BIN4 - BIN4) * BIN7 */
            temp_s32 = ((SInt32)englim_tqckdrivfil_par - (SInt32)TqSys_tqOfsDeceMax_C) * BIN7;
            if(tqsys_tqckdrivfilrawprev_cpy <= temp_s32)
            {
                reset_flip_flop = DDS_TRUE;
            }
            else
            {
                tqsys_tqthdcllacv_m = (SInt32)DDS_M_MAP3D_SUS16(&TQSYS_TQTHDCLLACV_M_APM,
                                                                englim_tqckdrivfil_par,
                                                                (UInt16)tqsys_nogearcorddrivfil_par);
                /* BIN4 = BIN4 + BIN4 */
                tqsys_tqthdcll = (SInt32)tqsys_tqthdpha4_cpy + tqsys_tqthdcllacv_m;

                /* BIN4 = BIN4 + (BIN0 * BIN4) */
                temp_s32 = tqsys_tqthdcll + ((SInt32)TqSys_tqOfsThdCll_C * BIN4);
                if((SInt32)tqlimem_tqlimem_par <= temp_s32)
                {
                    reset_flip_flop = DDS_TRUE;
                }
                else
                {
                    reset_flip_flop = DDS_FALSE;
                }
            }
        }
    }

    /* calcul TqSys_bDeceAcvTqMax */
    if((UInt32)DDS_FALSE == (UInt32)reset_flip_flop)
    {
        if( ((UInt32)DDS_FALSE != (UInt32)pfilfast_f03_01_03_tqsys_bdecereqraw ) &&
            ((UInt32)DDS_FALSE != (UInt32)TqSys_bDeceTqAir_C) )
        {
            /* if set */
            TqSys_bDeceAcvTqMax = DDS_TRUE;
        }
        else
        {
            /* DO NOTHING */
        }
    }
    else
    {
        /* if reset */
        TqSys_bDeceAcvTqMax = DDS_FALSE;
    }

    /* calcul TqSys_bDeceAcvIt*/
    if((UInt32)DDS_FALSE != (UInt32)pfilfast_f03_01_03_tqsys_bdecereqraw)
    {
        if((UInt32)DDS_FALSE == (UInt32)TqSys_bDeceAcvTqMax)
        {
            /* if set */
            *tqsys_bdeceacvit_ptr = DDS_TRUE;
        }
        else
        {
            *tqsys_bdeceacvit_ptr = tqsys_bdeceacvit_prev;
        }
    }
    else
    {
        /* if reset*/
        *tqsys_bdeceacvit_ptr = DDS_FALSE;
    }

    /* calcul TqSys_bDeceAcvRaw */
    if((UInt32)DDS_FALSE != (UInt32)TqSys_bDeceTyp_C)
    {
        TqSys_bDeceAcvRaw = *tqsys_bdeceacvit_ptr;
    }
    else
    {
        TqSys_bDeceAcvRaw = pfilfast_f03_01_03_tqsys_bdecereqraw;
    }
    tqsys_bdeceacvit_prev = *tqsys_bdeceacvit_ptr;

    /* update delay */
    tqcmp_tqsumlosscmp_dly = tqcmp_tqsumlosscmp_par;
}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_04_Deceleration_Phase_Initializing
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_04_Deceleration_Phase_Initializing(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_nengdeceini_ptr, /* BIN2 */
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_nogeardece_ptr, /* BIN0 */
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckdeceiniit_ptr /* BIN4 */)
{
    t_dds_m_edge_detected_event pfilfast_edge_result;

    pfilfast_edge_result = DDS_M_EDGE_DETECT(&pfilfast_f03_01_04_edge_detect_ptr,
                                        TqSys_bDeceAcvRaw);


    /* SSTG REQ_TAG 01460_10_01107.FR.17 */
    if((UInt32)DDS_M_POSITIVE_EDGE_DETECTED == (UInt32)pfilfast_edge_result)
    {
        PFILFAST_F03_01_04_01_Deceleration_Phase_Init_Values(eng_nckfil_par, /* BIN2 */
                                                                tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                tqsys_nengdeceini_ptr, /* BIN2 */
                                                                tqsys_tqckdeceiniit_ptr /* BIN4 */);
    }
    else
    {
        *tqsys_tqckdeceiniit_ptr = tqsys_tqckdeceiniit_prev;
        *tqsys_nengdeceini_ptr = tqsys_nengdeceini_prev;
    }

    tqsys_tqckdeceiniit_prev = *tqsys_tqckdeceiniit_ptr;
    tqsys_nengdeceini_prev = *tqsys_nengdeceini_ptr;


    if((UInt32)DDS_FALSE != (UInt32)TqSys_bnoGearDeceAcv_C)
    {
        *tqsys_nogeardece_ptr = TqSys_noGearDeceIniIt;
    }
    else
    {
        *tqsys_nogeardece_ptr = tqsys_nogearcorddrivfil_par;
    }

}

/*******************************************************************************
*
* Function Name : PFILFAST_F03_01_04_01_Deceleration_Phase_Init_Values
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) PFILFAST_F03_01_04_01_Deceleration_Phase_Init_Values(UInt16 eng_nckfil_par, /* BIN2 */
                                                                        UInt8 tqsys_nogearcorddrivfil_par, /* BIN0 */
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) tqsys_nengdeceini_ptr, /* BIN2 */
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckdeceiniit_ptr /* BIN4 */)
{
    /* SSTG REQ_TAG 01460_10_01107.FR.18 */
    /*BIN4 = BIN11 / BIN7*/
    *tqsys_tqckdeceiniit_ptr = (SInt16)(tqsys_tqckdrivfilrawprev_cpy / BIN7);

    /* BIN2 = BIN2*/
    *tqsys_nengdeceini_ptr = eng_nckfil_par;

    /* BIN0 = BIN0 */
    TqSys_noGearDeceIniIt = tqsys_nogearcorddrivfil_par;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : PFILFAST_Filt_Activ_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) PFILFAST_Filt_Activ_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bDeceAcvIt_swc_out,
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) TqSys_nEngDeceIni_swc_out, /* BIN2 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_noGearDece_swc_out, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkDeceIniIt_swc_out /* BIN4 */)
{
    /* Init ouputs */
    *TqSys_nEngDeceIni_swc_out = (UInt16)(0 * BIN2);
    *TqSys_noGearDece_swc_out = (UInt8)(0 * BIN0);
    *TqSys_tqCkDeceIniIt_swc_out = (SInt16)(0 * BIN4);
    *TqSys_bDeceAcvIt_swc_out = DDS_FALSE;

    /* Init RUN_OUT*/
    TqSys_bAcceAcv = DDS_FALSE;
    TqSys_tqCkDrivNotFil = (SInt32)(0 * BIN11);

    /* Init prev  and RS flip-flop */
    tqsys_tqckdrivnotfilacce_prev = (SInt32)(0 * BIN11);
    tqsys_bdeceacvit_prev = DDS_FALSE;
    pfilfast_f03_01_03_tqsys_bdecereqraw = DDS_FALSE;
    TqSys_bDeceAcvTqMax = DDS_FALSE;
    TqSys_noGearDeceIniIt = 0;
    tqsys_tqckdeceiniit_prev = *TqSys_tqCkDeceIniIt_swc_out;
    tqsys_nengdeceini_prev = *TqSys_nEngDeceIni_swc_out;

    /* Init MACRO */
    DDS_M_EDGE_DETECT_INIT(&pfilfast_f03_01_04_edge_detect_ptr,
                            DDS_FALSE);

    /** PFILFAST_F03_01_03_Deceleration_Detection **/
    tqcmp_tqsumlosscmp_dly = (SInt16)(0 * BIN4);

    /* Init Intern variables */
    tqsys_tqthdpha4_cpy = 0;
}



#define PFILFAST_STOP_SEC_CODE
#include "PFilFast_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 6.11
* Date: 05/08/2013 11:13:59
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
CoVSCtl_rAccPEng ; ;COVSCTL ;% ;0 ;100 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur pédale moteur ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqCkDrivFil ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple moteur effectif de coordination des limitations pour fonction agrément ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Eng_nCkFil ; ;ENG ;rpm ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime moteur filtré envoyé à 10ms ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCll_bAcvCll ;["FALSE"|"TRUE"] ;TQCLL ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Etat global de bouclage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqSumLossCmp ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple des pertes globales à compenser. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqLimEM_tqLimEM ; ;TQLIMEM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple conducteur limité envoyé à l'agrément préventif ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDiDrivFilReq ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen de desactivation la strategie filtration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bInjCutDynReq ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Demande de coupure d'injection sélective ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bTypFu ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Type de carburant retraité et simplifié ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEng1_A ;1{t_pfilfast_neng1_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de régime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearCordDrivFil ; ;TQSYS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilise dans la strategie ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGear_A ;1{t_pfilfast_nogear_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;SEE_APPLI ;Vecteur de rapport de boite ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivFilRawPrev ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur precedente du couple filtre avec une haute resolution ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdPha4 ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Seuil de couple pour la transition phase 01 a phase 1 en acceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
TqSys_bAcceAcv ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l'activation de l'acceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceAcvIt ;["FALSE"|"TRUE"] ;TQS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Indique l'activation de la décélération ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEngDeceIni ; ;TQSYS ;RPM ;0 ;8000 ;1/4 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Régime moteur filtré à l'activation de la décélération ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearDece ; ;TQS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite utilisé pendant la décélération ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDeceIniIt ; ;TQS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple à l'initialisation de la décélération ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivNotFil ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple non filtré après limitation pour motorisation essence ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
PFILFAST_7_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;7 ;7 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
PFILFAST_8_SIZE ; ;PFILFAST ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;8 ;8 size for map ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcceDi ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen issu des conditions de desactivation de la fonction. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcceReq ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Boolen de detection de l'accel, pris en compte dans la bascule RS de l'acceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcceReq_MP ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Boolen de detection de l'accel, pris en compte dans la bascule RS de l'acceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceAcvRaw ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booléen de détéction de l’accélération brute ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceAcvTqMax ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen d’activation de la demande de passage du couple non filtre sur le couple max ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceReq_MP ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Boolen de détéction de la decel pris en compte dans la bascule RS de la décélération ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceTqAir_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Booleen d’activation de la strategie de debouclage en deceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bDeceTyp_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Booleen de choix du couple utilise pour l’initialisation des parametres de la decel. ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bTqCkDrivFilLimSel_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Permet de limiterle couple non filtre avant filtrage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bTqMaxAcv_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Booleen d’utilisation du couple max ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bnoGearDeceAcv_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Permet de choisir pour la deceleration entre le rapport de boite courant et le rapport de boite a l'activation de la deceleration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_noGearDeceIniIt ; ;TQSYS ;N/A ;0 ;6 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Rapport de boite a l'activation de la deceleration ;["YES"] ;UInt8 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccPEngRstDeceThd_C ; ;TQSYS ;% ;0 ;3 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.1 ;Seuil de position pedale pour la desactivation de la deceleration ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccPThdTqCll_C ; ;TQSYS ;% ;0 ;3 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;3 ;Seuil de position pedale pour autoriser le debouclage en decel ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivNotFilAcce ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple non filtre apres limitation pour motorisation essence en acceleration ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkDrivNotFilGsl ; ;TQSYS ;N.m ;-2000 ;2000 ;1/2048 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple non filtre apres limitation pour motorisation essence ;["YES"] ;SInt32 ;BIN11 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaMaxDiAcceX_A ;1{t_pfilfast_tqdeltamaxdiaccex_a}PFILFAST_8_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[800 1000 1250 1500 2000 2500 3000 4000] ;Regime moteur filtre utilise dans la structure couple ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaMaxDiAcceY_A ;1{t_pfilfast_tqdeltamaxdiaccey_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 1 2 3 4 5 6] ;Rapport de boite utilise dans la strategie ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaMaxDiAcce_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] [2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] [2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] [2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] [2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] [2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] [2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5] ;Delta minimum entre le couple non filtre et le couple filtre pour desactiver l'acceleration ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_tqDeltaMaxDiAcceX_A ;TqSys_tqDeltaMaxDiAcceY_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaMinAcce ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Delta de couple activant le preventif en phase d’acceleration en dessous d’un seuil calibrable. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaMinAcce_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[2000 2000 2000 2000 2000 2000 2000 2000] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] ;Delta minimum entre le couple non filtre et le couple filtre pour activer l'acceleration ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaMinDece_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;Eng_nCkFil ;N/A ;N/A ;[2000 2000 2000 2000 2000 2000 2000 2000] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] [5 5 5 5 5 5 5 5] ;Delta minimum entre le couple non filtre et le couple filtre pour activer la deceleration ;["YES"] ;DDS_M_MAP3D_UUS16 ;BIN4 ;TqSys_nEng1_A ;TqSys_noGear_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqDeltaOfsAcce_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0 ;Offset minimum ajoute au delta minimum de couple pour l'activation de l'acceleration si le couple est superieur au seuil des jeux ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsCkDrivFilTqMax_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;-15 ;Offset sur le EngLim_tqCkDrivFil pour le reset de la condition TqSys_bDeceAcvTqMax. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsDeceMax_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ;Offset sur le couple EngLim_tqCkDrivFil pour activer la demande de passage TqSys_tqCkDrivUnfil de sur le couple EngLim_tqCkDrivFil . ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsHighTq_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;200 ;Offset sur le couple pour la detection de la deceleration quand le couple filtre est passe au dessus d'un seuil ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsRstDece_C ; ;TQSYS ;N.m ;0 ;0.1875 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.1 ;Offset de couple de pertes pour desactivation de la deceleration ;["YES"] ;UInt8 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsThdCll_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;5 ;Offset sur le seuil de couple pour l’application du filtre preventif. ;["YES"] ;SInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdCllAcvX_A ;1{t_pfilfast_tqthdcllacvx_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[-150 0 20 50 80 130 200] ;Point d’appui en couple maximum pour la carto TqSys_tqThdCllAcv_M ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdCllAcvY_A ;1{t_pfilfast_tqthdcllacvy_a}PFILFAST_7_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[0 1 2 3 4 5 6] ;Point d’appui en rapport de boite maximum pour la carto TqSys_tqThdCllAcv_M ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThdCllAcv_M ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["MAP"] ;["N/A"] ;EngLim_tqCkDrivFil ;N/A ;N/A ;[150 150 150 150 150 150 150] [150 150 150 150 150 150 150] [150 150 150 150 150 150 150] [150 150 150 150 150 150 150] [150 150 150 150 150 150 150] [150 150 150 150 150 150 150] [150 150 150 150 150 150 150] ;Seuil de couple pour l’application du filtre preventif. ;["YES"] ;DDS_M_MAP3D_SUS16 ;BIN4 ;TqSys_tqThdCllAcvX_A ;TqSys_tqThdCllAcvY_A ;N/A ;N/A ;N/A ;N/A
TqSys_tqThd_tqDeltaMinDece_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Seuil de couple au dela duquel le delta minimum de couple doit être plus grand pour activer la deceleration ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_neng1_a ; ;PFILFAST ;rpm ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_nEng1_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_nogear_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_noGear_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqdeltamaxdiaccex_a ; ;PFILFAST ;rpm ;0 ;8000 ;1/4 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tqDeltaMaxDiAcceX_A ;["NO"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqdeltamaxdiaccey_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tqDeltaMaxDiAcceY_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqthdcllacvx_a ; ;PFILFAST ;N.m ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tqThdCllAcvX_A ;["NO"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_pfilfast_tqthdcllacvy_a ; ;PFILFAST ;N/A ;0 ;6 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis TqSys_tqThdCllAcvY_A ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

