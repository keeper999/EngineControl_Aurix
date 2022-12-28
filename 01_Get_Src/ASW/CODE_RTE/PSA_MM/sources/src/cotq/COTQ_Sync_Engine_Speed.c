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
* Ref X:\integration_view_00PSASWC_EC20D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Sync_Engine_Speed.c
* Version int :/main/L01_02/1 Date: 21/9/2012 14 h 46 m User:posmyk 
*    TWK_model:COTQ_Sync_Engine_Speed_L01_020_IMPL2
*    comments :Specification update
* Version dev :\main\branch_morisseau_cotq_e6_view\5 Date: 21/9/2012 11 h 29 m User:morisseau 
*    TWK_model:COTQ_Sync_Engine_Speed_L01_020_IMPL2
*    comments :Specification update
* Version int :/main/L01_01/2 Date: 31/1/2011 15 h 15 m User:meme
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1_D
*    comments :Correct division on filter factor
* Version dev :\main\branch_girodon_module_dev\6 Date: 31/1/2011 12 h 9 m User:girodon
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1_D
*    comments :Correct division on filter factor
* Version dev :\main\branch_girodon_module_dev\4 Date: 31/1/2011 8 h 34 m User:girodon
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1_D
*    comments :Correct division on filter factor
* Version dev :\main\branch_girodon_module_dev\2 Date: 27/1/2011 14 h 50 m User:girodon
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1_D
*    comments :Correct filter factor calculation
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 17/1/2011 11 h 58 m User:demezil
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1_D
*    comments :correction following TU report
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 17/1/2011 11 h 54 m User:demezil
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1_D
*    comments :correction following TU report
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 56 m User:esnault
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\4 Date: 26/10/2010 17 h 3 m User:demezil
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1
*    comments :for CoTq euro6
* Version dev :\main\branch_lemort_cotq_dev\3 Date: 26/10/2010 11 h 44 m User:demezil
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\2 Date: 21/10/2010 15 h 47 m User:lemort
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 14/10/2010 17 h 43 m User:lemort
*    TWK_model:COTQ_Sync_Engine_Speed_L01_010_IMPL1
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
#define COTQ_6_SIZE                           6
#define COTQ_8_SIZE                           8

#define COTQ_M2000_BIN4 ((SInt32)-2000 * BIN4)
#define COTQ_2000_BIN4  ((SInt32)2000 * BIN4)

#define COPTST_STENG_COUPE_CALE     1
#define COPTST_STENG_STOP           6

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

/* 16-bits variables definition */
#define COTQ_START_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"
VAR(SInt16, AUTOMATIC) TqSys_tqCkEfcMinFeasDsl; /* BIN4 */
#define COTQ_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"



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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiSatTqEfcRealMax_C = (CONST(UInt16, AUTOMATIC))(0.01 * DEC2);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqEngRealMaxEs_C = (CONST(SInt16, AUTOMATIC))(2000 * BIN0);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqEngRealMinEs_C = (CONST(SInt16, AUTOMATIC))(-2000 * BIN0);
#define COTQ_STOP_SEC_CALIB_16BIT
#include "CoTq_MemMap.h"

/* 8-bits scalar calibration definition */
#define COTQ_START_SEC_CALIB_8BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqLossRealSel_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqMaxGslSel_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqMinFeas_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bTqRealEsGslSel_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facTTqEngReal_C = (CONST(UInt8, AUTOMATIC))(1 * BIN4);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_noDlyTqIdcEngReal_C = (CONST(UInt8, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_tiFilTqLimEM_C = (CONST(UInt8, AUTOMATIC))(0.6 * DEC2);
#define COTQ_STOP_SEC_CALIB_8BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COTQ_START_SEC_CARTO_16BIT
#include "CoTq_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPndAstTqReal_M
[COTQ_6_SIZE][COTQ_8_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facPndSpdTqReal_T
[COTQ_4_SIZE] = {
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(0 * BIN4)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTqRealCor_M
[COTQ_6_SIZE][COTQ_6_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_facTqRealCorDriv_M
[COTQ_6_SIZE][COTQ_6_SIZE] = {
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) },
{
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4),
(UInt16)(1 * BIN4), (UInt16)(1 * BIN4), (UInt16)(1 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_nCkGrdTqRealCorX_A[COTQ_6_SIZE] = {
(SInt16)(-200 * BIN2), (SInt16)(-100 * BIN2), (SInt16)(0 * BIN2),
(SInt16)(200 * BIN2), (SInt16)(400 * BIN2), (SInt16)(800 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nCkTqRealCorY_A[COTQ_6_SIZE] = {
(UInt16)(1000 * BIN2), (UInt16)(2000 * BIN2), (UInt16)(3000 * BIN2),
(UInt16)(4000 * BIN2), (UInt16)(5000 * BIN2), (UInt16)(6000 * BIN2)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_spdVehTqReal_A[COTQ_4_SIZE] = {
(UInt16)(0 * BIN7), (UInt16)(1 * BIN7), (UInt16)(5 * BIN7),
(UInt16)(10 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tEngTqRealCorY_A[COTQ_6_SIZE] = {
(SInt16)(-20 * BIN0), (SInt16)(0 * BIN0), (SInt16)(20 * BIN0),
(SInt16)(30 * BIN0), (SInt16)(40 * BIN0), (SInt16)(80 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiStopTqRealCorX_A[COTQ_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(30 * BIN0), (UInt16)(60 * BIN0),
(UInt16)(300 * BIN0), (UInt16)(600 * BIN0), (UInt16)(1200 * BIN0),
(UInt16)(1800 * BIN0), (UInt16)(3600 * BIN0)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqDeltaRealCor_M
[COTQ_6_SIZE][COTQ_6_SIZE] = {
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) },
{
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
(SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4) }
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqGrdTqRealCorX_A[COTQ_6_SIZE] = {
(SInt16)(5 * BIN4), (SInt16)(10 * BIN4), (SInt16)(20 * BIN4),
(SInt16)(50 * BIN4), (SInt16)(70 * BIN4), (SInt16)(100 * BIN4)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqRawTqRealCorX_A[COTQ_6_SIZE] = {
(SInt16)(10 * BIN4), (SInt16)(50 * BIN4), (SInt16)(100 * BIN4),
(SInt16)(150 * BIN4), (SInt16)(200 * BIN4), (SInt16)(300 * BIN4)
};

#define COTQ_STOP_SEC_CARTO_16BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COTQ_START_SEC_VAR_UNSPECIFIED
#include "CoTq_MemMap.h"
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_facpndasttqreal_m_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_facpndspdtqreal_t_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factqrealcor_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_factqrealcordriv_m_sav;
STATIC VAR(t_dds_m_map3d_sav, AUTOMATIC) tqsys_tqdeltarealcor_m_sav;
STATIC VAR(t_dds_m_turn_on_delay_type, AUTOMATIC) cotq_f03_02_04_tond_str;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) cotq_f03_02_01_filt_str;
#define COTQ_STOP_SEC_VAR_UNSPECIFIED
#include "CoTq_MemMap.h"


/* 16-bits variable definition */
#define COTQ_START_SEC_VAR_16BIT
#include "CoTq_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) tqlimem_tqlimemtrv_prev;
STATIC VAR(SInt16, AUTOMATIC) cotq_idx[COTQ_4_SIZE];
STATIC VAR(SInt16, AUTOMATIC) tqsys_tqckengrealem_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcldminadvmin_prev;
STATIC VAR(SInt16, AUTOMATIC) englim_tqefcldadvminfucutsel_prev;
#define COTQ_STOP_SEC_VAR_16BIT
#include "CoTq_MemMap.h"


/* 8-bits variable definition */
#define COTQ_START_SEC_VAR_8BIT
#include "CoTq_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) cotq_f03_02_01_initialised;
#define COTQ_STOP_SEC_VAR_8BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COTQ_START_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqCkEfcMinFeasGsl; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqEfcEngRealDly; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqEngRealCor; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqEngRealRaw_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqLimEMGrdFil; /* BIN4 */
#define COTQ_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COTQ_START_SEC_CONST_UNSPECIFIED
#include "CoTq_MemMap.h"
STATIC CONST(t_dds_m_map3d_usu16, AUTOMATIC) TQSYS_FACPNDASTTQREAL_M_APM = {
&tqsys_facpndasttqreal_m_sav,
COTQ_8_SIZE,
COTQ_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiStopTqRealCorX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tEngTqRealCorY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPndAstTqReal_M[0][0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_FACPNDSPDTQREAL_T_APM = {
&tqsys_facpndspdtqreal_t_sav,
COTQ_4_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_spdVehTqReal_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facPndSpdTqReal_T[0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTQREALCOR_M_APM = {
&tqsys_factqrealcor_m_sav,
COTQ_6_SIZE,
COTQ_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_nCkGrdTqRealCorX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nCkTqRealCorY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTqRealCor_M[0][0]
};

STATIC CONST(t_dds_m_map3d_suu16, AUTOMATIC) TQSYS_FACTQREALCORDRIV_M_APM = {
&tqsys_factqrealcordriv_m_sav,
COTQ_6_SIZE,
COTQ_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqGrdTqRealCorX_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nCkTqRealCorY_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_facTqRealCorDriv_M[0][0]
};

STATIC CONST(t_dds_m_map3d_s16, AUTOMATIC) TQSYS_TQDELTAREALCOR_M_APM = {
&tqsys_tqdeltarealcor_m_sav,
COTQ_6_SIZE,
COTQ_6_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqRawTqRealCorX_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tEngTqRealCorY_A[0],
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqSys_tqDeltaRealCor_M[0][0]
};

#define COTQ_STOP_SEC_CONST_UNSPECIFIED
#include "CoTq_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"

STATIC FUNC(void, AUTOMATIC) COTQ_F03_01_Conv_Essence_Sync (SInt16 englim_tqidcengcur_par,
                                                            SInt16 englim_tqidcldminadvmin_par,
                                                            SInt16 englim_tqidcldminadvminselc_par,
                                                            SInt16 tqcmp_tqsumlosscmpwoutcnv_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengrealem_ptr,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldminadvmin_ptr,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldadvminfucutsel_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_01_Calcul_Gradient_Couple_Conducteur(SInt16 tqlimem_tqlimemtrv_par,
                                                                                UInt8 ext_titdc_par);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_Calcul_Couple_Reel(UInt8 tqsys_btypfu_par,
                                                            SInt16 englim_tqidcengcurgbx_par,
                                                            SInt16 tqest_tqidcestim_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 ext_tcomes_par,
                                                            SInt16 ext_toilmes_par,
                                                            UInt16 treattdc_nckfil_par,
                                                            SInt16 treattdc_nckgrdfil_par,
                                                            UInt16 veh_spdveh_par,
                                                            UInt32 eom_tiengstop_par,
                                                            UInt8 coptst_bmainengstopreq_par,
                                                            UInt8 coptst_steng_par,
                                                            SInt16 tqlimem_tqlimemtrv_par,
                                                            UInt8 ext_titdc_par,
                                                            SInt16 tqcmp_tqsumlosscmpwoutcnv_par, /* BIN4 */
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengreal_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_02_Retarder_Couple_Reel(UInt8 tqsys_btypfu_par,
                                                                SInt16 englim_tqidcengcurgbx_par,
                                                                SInt16 tqest_tqidcestim_par,
                                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                                SInt16 tqcmp_tqsumlosscmpwoutcnv_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_03_Calcul_Correction_Couple_Reel(  SInt16 ext_tcomes_par,
                                                                            SInt16 ext_toilmes_par,
                                                                            UInt16 treattdc_nckfil_par,
                                                                            SInt16 treattdc_nckgrdfil_par,
                                                                            UInt16 veh_spdveh_par,
                                                                            UInt32 eom_tiengstop_par);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_04_Coordonner_Couple_Reel_Final(UInt8 coptst_steng_par,
                                                                        UInt8 coptst_bmainengstopreq_par,
                                                                        UInt8 tqsys_btypfu_par,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengreal_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_03_Conv_Commun_Sync (SInt16 englim_tqidcmaxnreg_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 injsys_tqidcminfeas_par,
                                                            UInt8 tqsys_btypfu_par,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmaxnreg_ptr,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcminfeas_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_04_Conv_Hy_Sync ( UInt8 tqsys_btypfu_par,
                                                        SInt16 englim_tqidcenglimmax_par,
                                                        SInt16 tqcmp_tqsumlosscmp_par,
                                                        SInt16 copt_tqidcreqcord_nregreq_par,
                                                        SInt16 tqsys_tqckenglimcord_par,
                                                        SInt16 tqcmp_tqaltloss_par,
                                                        SInt16 englim_tqidcldmaxtrbmax_par,
                                                        SInt16 englim_tqidcpresusthrmax_par,
                                                        SInt16 englim_tqidcfldlim_par,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcenglim_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqefcreqcord_nregreq_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqefcengwoutaos_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcenglimcmb_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmaxenglimcmb_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_Sync_Engine_Speed
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Sync_Engine_Speed(SInt16 CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
                                             UInt8 CoPTSt_bMainEngStopReq_swc_in,
                                             UInt8 CoPTSt_stEng_swc_in,
                                             SInt16 EngLim_tqIdcEngCur_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcEngLimMax_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcFLdLim_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcLdMaxTrbMax_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcLdMinAdvMin_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcLdMinAdvMinSelc_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcMaxNReg_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcPresUsThrMax_swc_in, /* BIN4 */
                                             SInt16 EngLim_tqIdcEngCurGBx_swc_in, /* BIN4 */
                                             UInt32 EOM_tiEngStop_swc_in, /* BIN0 */
                                             SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                             UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                             SInt16 Ext_tOilMes_swc_in, /* DEC1 */
                                             SInt16 InjSys_tqIdcMinFeas_swc_in, /* BIN4 */
                                             SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                             SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                             SInt16 TqCmp_tqSumLossCmpWoutCnv_swc_in, /* BIN4 */
                                             SInt16 TqEst_tqIdcEstim_swc_in, /* BIN4 */
                                             SInt16 TqLimEM_tqLimEMTrv_swc_in, /* BIN4 */
                                             UInt8 TqSys_bTypFu_swc_in,
                                             SInt16 TqSys_tqCkEngLimCord_swc_in, /* BIN4 */
                                             UInt16 TreatTDC_nCkFil_swc_in, /* BIN2 */
                                             SInt16 TreatTDC_nCkGrdFil_swc_in, /* BIN2 */
                                             UInt16 Veh_spdVeh_swc_in, /* BIN7 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcReqCord_nRegReq_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLim_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLimCmb_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdAdvMinFuCutSel_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMinAdvMin_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxEngLimCmb_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxNReg_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcMinFeas_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngReal_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngRealEM_swc_out, /* BIN4 */
                                             CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcEngWoutAOS_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.3.3 */

    if((UInt32)DDS_FALSE != (UInt32)TqSys_bTypFu_swc_in)
    {
        COTQ_F03_01_Conv_Essence_Sync ( EngLim_tqIdcEngCur_swc_in,
                                        EngLim_tqIdcLdMinAdvMin_swc_in,
                                        EngLim_tqIdcLdMinAdvMinSelc_swc_in,
                                        TqCmp_tqSumLossCmpWoutCnv_swc_in,
                                        TqCmp_tqSumLossCmp_swc_in,
                                        TqSys_tqCkEngRealEM_swc_out,
                                        EngLim_tqEfcLdMinAdvMin_swc_out,
                                        EngLim_tqEfcLdAdvMinFuCutSel_swc_out);

        tqsys_tqckengrealem_prev = *TqSys_tqCkEngRealEM_swc_out;
        englim_tqefcldminadvmin_prev = *EngLim_tqEfcLdMinAdvMin_swc_out;
        englim_tqefcldadvminfucutsel_prev = *EngLim_tqEfcLdAdvMinFuCutSel_swc_out;
    }
    else
    {
        *TqSys_tqCkEngRealEM_swc_out = tqsys_tqckengrealem_prev;
        *EngLim_tqEfcLdMinAdvMin_swc_out = englim_tqefcldminadvmin_prev;
        *EngLim_tqEfcLdAdvMinFuCutSel_swc_out = englim_tqefcldadvminfucutsel_prev;
    }

    COTQ_F03_02_Calcul_Couple_Reel(TqSys_bTypFu_swc_in,
                                    EngLim_tqIdcEngCurGBx_swc_in,
                                    TqEst_tqIdcEstim_swc_in,
                                    TqCmp_tqSumLossCmp_swc_in,
                                    Ext_tCoMes_swc_in,
                                    Ext_tOilMes_swc_in,
                                    TreatTDC_nCkFil_swc_in,
                                    TreatTDC_nCkGrdFil_swc_in,
                                    Veh_spdVeh_swc_in,
                                    EOM_tiEngStop_swc_in,
                                    CoPTSt_bMainEngStopReq_swc_in,
                                    CoPTSt_stEng_swc_in,
                                    TqLimEM_tqLimEMTrv_swc_in,
                                    Ext_tiTDC_swc_in,
                                    TqCmp_tqSumLossCmpWoutCnv_swc_in,
                                    TqSys_tqCkEngReal_swc_out);

    COTQ_F03_03_Conv_Commun_Sync (  EngLim_tqIdcMaxNReg_swc_in,
                                    TqCmp_tqSumLossCmp_swc_in,
                                    InjSys_tqIdcMinFeas_swc_in,
                                    TqSys_bTypFu_swc_in,
                                    EngLim_tqEfcMaxNReg_swc_out,
                                    TqSys_tqCkEfcMinFeas_swc_out);

    COTQ_F03_04_Conv_Hy_Sync (  TqSys_bTypFu_swc_in,
                                EngLim_tqIdcEngLimMax_swc_in,
                                TqCmp_tqSumLossCmp_swc_in,
                                CoPt_tqIdcReqCord_nRegReq_swc_in,
                                TqSys_tqCkEngLimCord_swc_in,
                                TqCmp_tqAltLoss_swc_in,
                                EngLim_tqIdcLdMaxTrbMax_swc_in,
                                EngLim_tqIdcPresUsThrMax_swc_in,
                                EngLim_tqIdcFLdLim_swc_in,
                                EngLim_tqEfcEngLim_swc_out,
                                CoPt_tqEfcReqCord_nRegReq_swc_out,
                                TqSys_tqEfcEngWoutAOS_swc_out,
                                EngLim_tqEfcEngLimCmb_swc_out,
                                EngLim_tqEfcMaxEngLimCmb_swc_out);

}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_F03_01_Conv_Essence_Sync
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_01_Conv_Essence_Sync (SInt16 englim_tqidcengcur_par,
                                                            SInt16 englim_tqidcldminadvmin_par,
                                                            SInt16 englim_tqidcldminadvminselc_par,
                                                            SInt16 tqcmp_tqsumlosscmpwoutcnv_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengrealem_ptr,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldminadvmin_ptr,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcldadvminfucutsel_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.5.1 */

    SInt32 cotq_s32_temp;

    cotq_s32_temp = (SInt32)englim_tqidcengcur_par - (SInt32)tqcmp_tqsumlosscmpwoutcnv_par;
    *tqsys_tqckengrealem_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)englim_tqidcldminadvmin_par - (SInt32)tqcmp_tqsumlosscmp_par;
    *englim_tqefcldminadvmin_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)englim_tqidcldminadvminselc_par - (SInt32)tqcmp_tqsumlosscmp_par;
    *englim_tqefcldadvminfucutsel_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    if((UInt32)DDS_FALSE != (UInt32)TqSys_bTqMinFeas_C)
    {
        TqSys_tqCkEfcMinFeasGsl = *englim_tqefcldminadvmin_ptr;
    }
    else
    {
        TqSys_tqCkEfcMinFeasGsl = *englim_tqefcldadvminfucutsel_ptr;
    }
}


/*******************************************************************************
*
* Function Name : COTQ_F03_02_Calcul_Couple_Reel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_Calcul_Couple_Reel(UInt8 tqsys_btypfu_par,
                                                            SInt16 englim_tqidcengcurgbx_par,
                                                            SInt16 tqest_tqidcestim_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 ext_tcomes_par,
                                                            SInt16 ext_toilmes_par,
                                                            UInt16 treattdc_nckfil_par,
                                                            SInt16 treattdc_nckgrdfil_par,
                                                            UInt16 veh_spdveh_par,
                                                            UInt32 eom_tiengstop_par,
                                                            UInt8 coptst_bmainengstopreq_par,
                                                            UInt8 coptst_steng_par,
                                                            SInt16 tqlimem_tqlimemtrv_par,
                                                            UInt8 ext_titdc_par,
                                                            SInt16 tqcmp_tqsumlosscmpwoutcnv_par, /* BIN4 */
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengreal_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.6.1 */

    COTQ_F03_02_01_Calcul_Gradient_Couple_Conducteur(tqlimem_tqlimemtrv_par,
                                                        ext_titdc_par);

    COTQ_F03_02_02_Retarder_Couple_Reel(tqsys_btypfu_par,
                                         englim_tqidcengcurgbx_par,
                                         tqest_tqidcestim_par,
                                         tqcmp_tqsumlosscmp_par,
                                         tqcmp_tqsumlosscmpwoutcnv_par /* BIN4 */);

    COTQ_F03_02_03_Calcul_Correction_Couple_Reel(ext_tcomes_par,
                                                    ext_toilmes_par,
                                                    treattdc_nckfil_par,
                                                    treattdc_nckgrdfil_par,
                                                    veh_spdveh_par,
                                                    eom_tiengstop_par);

    COTQ_F03_02_04_Coordonner_Couple_Reel_Final(coptst_steng_par,
                                                coptst_bmainengstopreq_par,
                                                tqsys_btypfu_par,
                                                tqsys_tqckengreal_ptr);

}


/*******************************************************************************
*
* Function Name : COTQ_F03_02_01_Calcul_Gradient_Couple_Conducteur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_01_Calcul_Gradient_Couple_Conducteur(SInt16 tqlimem_tqlimemtrv_par,
                                                                            UInt8 ext_titdc_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.14.0 */

    SInt32 cotq_s32_temp;
    UInt32 cotq_u32_temp;

    /* [-4000 ; 4000] BIN4 */
    cotq_s32_temp = (SInt32)tqlimem_tqlimemtrv_par - (SInt32)tqlimem_tqlimemtrv_prev;

    if(0 != cotq_s32_temp)
    {
        if(0 != (UInt32)ext_titdc_par)
        {
            cotq_s32_temp = (cotq_s32_temp * DEC3) / (SInt32)ext_titdc_par;
            cotq_s32_temp = DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);
        }
        else
        {
            /* cotq_s32_temp can't be equal to 0 */
            if(cotq_s32_temp > 0)
            {
                cotq_s32_temp = COTQ_2000_BIN4;
            }
            else
            {
                cotq_s32_temp = COTQ_M2000_BIN4;
            }
        }
    }
    else
    {
        /* Do nothing */
    }

    if((UInt32)DDS_FALSE == (UInt32)cotq_f03_02_01_initialised)
    {
        TqSys_tqLimEMGrdFil = DDS_M_FILTER_LP1_S16_INIT(&cotq_f03_02_01_filt_str, (SInt16)cotq_s32_temp);
        cotq_f03_02_01_initialised = DDS_TRUE;
    }
    else
    {
        /* [0;1.1]DEC3 = [0;0.1]DEC3 + ([0;1]DEC2 * DEC1) */
        cotq_u32_temp = (UInt32)ext_titdc_par + ((UInt32)TqSys_tiFilTqLimEM_C * DEC1);
        if(0 != cotq_u32_temp)
        {
            /* BIN15 = [0;0.1]DEC3 * BIN15 / [0;1.1]DEC3 */
            cotq_u32_temp = ((UInt32)ext_titdc_par * BIN15) / cotq_u32_temp;
            cotq_u32_temp = DDS_M_MIN(cotq_u32_temp, (1 * BIN15));
        }
        else
        {
            cotq_u32_temp = (UInt32)(1 * BIN15);
        }

        TqSys_tqLimEMGrdFil = DDS_M_FILTER_LP1_S16 (&cotq_f03_02_01_filt_str,
                                                    (SInt16)cotq_s32_temp,
                                                    (UInt16)cotq_u32_temp,
                                                    BIN15);
    }

    tqlimem_tqlimemtrv_prev = tqlimem_tqlimemtrv_par;

}


/*******************************************************************************
*
* Function Name : COTQ_F03_02_02_Retarder_Couple_Reel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_02_Retarder_Couple_Reel(UInt8 tqsys_btypfu_par,
                                                                SInt16 englim_tqidcengcurgbx_par,
                                                                SInt16 tqest_tqidcestim_par,
                                                                SInt16 tqcmp_tqsumlosscmp_par,
                                                                SInt16 tqcmp_tqsumlosscmpwoutcnv_par /* BIN4 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.15.0 */

    SInt32 cotq_temp;
    SInt16 cotq_switch_out;

    if((UInt32)DDS_FALSE != (UInt32)tqsys_btypfu_par)
    {
        cotq_idx[0] = englim_tqidcengcurgbx_par;
    }
    else
    {
        cotq_idx[0] = tqest_tqidcestim_par;
    }

    cotq_switch_out = cotq_idx[(SInt32)TqSys_noDlyTqIdcEngReal_C];

    cotq_idx[3] = cotq_idx[2];
    cotq_idx[2] = cotq_idx[1];
    cotq_idx[1] = cotq_idx[0];

    if((UInt32)DDS_FALSE != (UInt32)TqSys_bTqLossRealSel_C)
    {
        cotq_temp = (SInt32)cotq_switch_out - (SInt32)tqcmp_tqsumlosscmpwoutcnv_par;
    }
    else
    {
        cotq_temp = (SInt32)cotq_switch_out - (SInt32)tqcmp_tqsumlosscmp_par;
    }

    TqSys_tqEfcEngRealDly = (SInt16)DDS_M_LIMIT(cotq_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

}


/*******************************************************************************
*
* Function Name : COTQ_F03_02_03_Calcul_Correction_Couple_Reel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_03_Calcul_Correction_Couple_Reel(  SInt16 ext_tcomes_par,
                                                                            SInt16 ext_toilmes_par,
                                                                            UInt16 treattdc_nckfil_par,
                                                                            SInt16 treattdc_nckgrdfil_par,
                                                                            UInt16 veh_spdveh_par,
                                                                            UInt32 eom_tiengstop_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.16.0 */

    SInt16 cotq_out_bary;
    UInt16 tqsys_factqrealcor_temp;
    UInt16 tqsys_factqrealcordriv_temp;
    UInt16 tqsys_facpndspdtqreal_temp;
    UInt16 tqsys_facpndasttqreal_temp;
    SInt16 tqsys_tqdeltarealcor_temp;
    SInt32 cotq_result;
    UInt16 eom_tiengstop_lim;

    /* BIN0 = ((BIN0 * DEC1) + DEC1) / DEC1 */
    cotq_out_bary = (SInt16)(DDS_M_BARY_FILTER_S32((SInt32)ext_tcomes_par * DEC1,
                                          (SInt32)ext_toilmes_par,
                                          (UInt16)TqSys_facTTqEngReal_C,
                                          BIN4) / DEC1);

    /* [0 ; 10] BIN4 */
    tqsys_factqrealcor_temp = DDS_M_MAP3D_SUU16(&TQSYS_FACTQREALCOR_M_APM,treattdc_nckgrdfil_par,treattdc_nckfil_par);

    /* [-2000 ; 2000] BIN4 */
    tqsys_tqdeltarealcor_temp = DDS_M_MAP3D_S16(&TQSYS_TQDELTAREALCOR_M_APM,TqSys_tqEfcEngRealDly,cotq_out_bary);

    /* [0 ; 10] BIN4 */
    tqsys_factqrealcordriv_temp = DDS_M_MAP3D_SUU16(&TQSYS_FACTQREALCORDRIV_M_APM,TqSys_tqLimEMGrdFil,treattdc_nckfil_par);

    /* [0 ; 1] BIN4 */
    tqsys_facpndspdtqreal_temp = DDS_M_MAP2D_U16(&TQSYS_FACPNDSPDTQREAL_T_APM,veh_spdveh_par);

    eom_tiengstop_lim = (UInt16)DDS_M_MIN(eom_tiengstop_par,DDS_UINT16_MAX);
    /* [0 ; 1] BIN4 */
    tqsys_facpndasttqreal_temp = DDS_M_MAP3D_USU16(&TQSYS_FACPNDASTTQREAL_M_APM,eom_tiengstop_lim,cotq_out_bary);

    /* [-20000 ; 20000] BIN8 = ([0 ; 10] BIN4 + [0 ; 10] BIN4) * [-2000 ; 2000] BIN4 */
    cotq_result = ((SInt32)tqsys_factqrealcor_temp + (SInt32)tqsys_factqrealcordriv_temp) * (SInt32)tqsys_tqdeltarealcor_temp;

    /* [-20000 ; 20000] BIN8 = [-20000 ; 20000] BIN8 * [0 ; 1] BIN4 / BIN4 */
    cotq_result = (cotq_result * (SInt32)tqsys_facpndspdtqreal_temp) / BIN4;

    /* [-20000 ; 20000] BIN4 = [-20000 ; 20000] BIN8 * [0 ; 1] BIN4 / BIN8 */
    cotq_result = (cotq_result * (SInt32)tqsys_facpndasttqreal_temp) / BIN8;

    TqSys_tqEngRealCor = (SInt16)DDS_M_LIMIT(cotq_result,COTQ_M2000_BIN4,COTQ_2000_BIN4);
}


/*******************************************************************************
*
* Function Name : COTQ_F03_02_04_Coordonner_Couple_Reel_Final
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_02_04_Coordonner_Couple_Reel_Final(UInt8 coptst_steng_par,
                                                                        UInt8 coptst_bmainengstopreq_par,
                                                                        UInt8 tqsys_btypfu_par,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckengreal_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.17.0 */

    SInt32 cotq_s32_temp;
    UInt8 cotq_input_tod;
    UInt8 cotq_output_tod;

    cotq_s32_temp = (SInt32)TqSys_tqEfcEngRealDly - (SInt32)TqSys_tqEngRealCor;

    TqSys_tqEngRealRaw_MP = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    if((COPTST_STENG_COUPE_CALE == (UInt32)coptst_steng_par)
    || (COPTST_STENG_STOP == (UInt32)coptst_steng_par)
    || ((UInt32)DDS_FALSE != (UInt32)coptst_bmainengstopreq_par) )
    {
        cotq_input_tod = DDS_TRUE;
    }
    else
    {
        cotq_input_tod = DDS_FALSE;
    }

    cotq_output_tod = DDS_M_TURN_ON_DELAY(cotq_input_tod,
                                            DDS_COTQ_1MS_U32_TIME,
                                            (UInt32)TqSys_tiSatTqEfcRealMax_C * DEC1,
                                            &cotq_f03_02_04_tond_str);

    if(((UInt32)DDS_FALSE != (UInt32)cotq_output_tod)
    && ( ((UInt32)DDS_FALSE == (UInt32)tqsys_btypfu_par)
      || ((UInt32)DDS_FALSE != (UInt32)TqSys_bTqRealEsGslSel_C) ) )
    {
        *tqsys_tqckengreal_ptr = (SInt16)DDS_M_SATURATION_V2((SInt32)TqSys_tqEngRealRaw_MP,
                                                            ((SInt32)TqSys_tqEngRealMinEs_C * BIN4),
                                                            ((SInt32)TqSys_tqEngRealMaxEs_C * BIN4) );
    }
    else
    {
        *tqsys_tqckengreal_ptr = TqSys_tqEngRealRaw_MP;
    }

}


/*******************************************************************************
*
* Function Name : COTQ_F03_03_Conv_Commun_Sync
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_03_Conv_Commun_Sync (SInt16 englim_tqidcmaxnreg_par,
                                                            SInt16 tqcmp_tqsumlosscmp_par,
                                                            SInt16 injsys_tqidcminfeas_par,
                                                            UInt8 tqsys_btypfu_par,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmaxnreg_ptr,
                                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckefcminfeas_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.7.1 */

    SInt32 cotq_s32_temp;

    cotq_s32_temp = (SInt32)englim_tqidcmaxnreg_par - (SInt32)tqcmp_tqsumlosscmp_par;
    *englim_tqefcmaxnreg_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)injsys_tqidcminfeas_par - (SInt32)tqcmp_tqsumlosscmp_par;
    TqSys_tqCkEfcMinFeasDsl = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    if((UInt32)DDS_FALSE != (UInt32)tqsys_btypfu_par)
    {
        *tqsys_tqckefcminfeas_ptr = TqSys_tqCkEfcMinFeasGsl;
    }
    else
    {
        *tqsys_tqckefcminfeas_ptr = TqSys_tqCkEfcMinFeasDsl;
    }

}


/*******************************************************************************
*
* Function Name : COTQ_F03_04_Conv_Hy_Sync
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_04_Conv_Hy_Sync ( UInt8 tqsys_btypfu_par,
                                                        SInt16 englim_tqidcenglimmax_par,
                                                        SInt16 tqcmp_tqsumlosscmp_par,
                                                        SInt16 copt_tqidcreqcord_nregreq_par,
                                                        SInt16 tqsys_tqckenglimcord_par,
                                                        SInt16 tqcmp_tqaltloss_par,
                                                        SInt16 englim_tqidcldmaxtrbmax_par,
                                                        SInt16 englim_tqidcpresusthrmax_par,
                                                        SInt16 englim_tqidcfldlim_par,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcenglim_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqefcreqcord_nregreq_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqefcengwoutaos_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcenglimcmb_ptr,
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) englim_tqefcmaxenglimcmb_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0922.FR.8.0 */

    SInt32 cotq_s32_temp;

    cotq_s32_temp = (SInt32)englim_tqidcenglimmax_par - (SInt32)tqcmp_tqsumlosscmp_par;
    *englim_tqefcenglim_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)copt_tqidcreqcord_nregreq_par - (SInt32)tqcmp_tqsumlosscmp_par;
    *copt_tqefcreqcord_nregreq_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)tqsys_tqckenglimcord_par - (SInt32)tqcmp_tqsumlosscmp_par;
    *tqsys_tqefcengwoutaos_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)*englim_tqefcenglim_ptr + (SInt32)tqcmp_tqaltloss_par;
    *englim_tqefcenglimcmb_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    if((UInt32)DDS_FALSE != (UInt32)tqsys_btypfu_par)
    {
        if((UInt32)DDS_FALSE != (UInt32)TqSys_bTqMaxGslSel_C)
        {
            cotq_s32_temp = ((SInt32)englim_tqidcldmaxtrbmax_par + (SInt32)tqcmp_tqaltloss_par) - (SInt32)tqcmp_tqsumlosscmp_par;
        }
        else
        {
            cotq_s32_temp = ((SInt32)englim_tqidcpresusthrmax_par + (SInt32)tqcmp_tqaltloss_par) - (SInt32)tqcmp_tqsumlosscmp_par;
        }
    }
    else
    {
        cotq_s32_temp = ((SInt32)englim_tqidcfldlim_par + (SInt32)tqcmp_tqaltloss_par) - (SInt32)tqcmp_tqsumlosscmp_par;
    }

    *englim_tqefcmaxenglimcmb_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);
}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Sync_Engine_Speed_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Sync_Engine_Speed_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqEfcReqCord_nRegReq_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLim_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcEngLimCmb_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdAdvMinFuCutSel_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcLdMinAdvMin_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxEngLimCmb_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) EngLim_tqEfcMaxNReg_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcMinFeas_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngReal_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEngRealEM_swc_out, /* BIN4 */
                                                  CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqEfcEngWoutAOS_swc_out /* BIN4 */)
{
    tqlimem_tqlimemtrv_prev = 0;

    *CoPt_tqEfcReqCord_nRegReq_swc_out = 0;
    *EngLim_tqEfcLdAdvMinFuCutSel_swc_out = 0;
    *EngLim_tqEfcLdMinAdvMin_swc_out = 0;
    *EngLim_tqEfcEngLim_swc_out = COTQ_2000_BIN4;
    *EngLim_tqEfcEngLimCmb_swc_out = COTQ_2000_BIN4;
    *EngLim_tqEfcMaxEngLimCmb_swc_out = COTQ_2000_BIN4;
    *EngLim_tqEfcMaxNReg_swc_out = 0;
    *TqSys_tqCkEfcMinFeas_swc_out = 0;
    *TqSys_tqCkEngReal_swc_out = 0;
    *TqSys_tqEfcEngWoutAOS_swc_out = 0;
    *TqSys_tqCkEngRealEM_swc_out = 0;

    (void)DDS_M_TURN_ON_DELAY_INIT(DDS_FALSE,&cotq_f03_02_04_tond_str);

    cotq_f03_02_01_initialised = DDS_FALSE;

    englim_tqefcldadvminfucutsel_prev = 0;
    englim_tqefcldminadvmin_prev = 0;
    tqsys_tqckengrealem_prev = 0;

    TqSys_tqCkEfcMinFeasDsl = 0;
    TqSys_tqCkEfcMinFeasGsl = 0;
    TqSys_tqEfcEngRealDly = 0;
    TqSys_tqEngRealCor = 0;
    TqSys_tqEngRealRaw_MP = 0;
    TqSys_tqLimEMGrdFil = 0;

    cotq_idx[3] = 0;
    cotq_idx[2] = 0;
    cotq_idx[1] = 0;
    cotq_idx[0] = 0;

}



#define COTQ_STOP_SEC_CODE
#include "CoTq_MemMap.h"

