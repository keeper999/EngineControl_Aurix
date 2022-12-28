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
* Ref X:\integration_view_00PSASWC_D721D01\blois_psa_sstg\Software\Appli\VSCo\src\VSCO_Whl_Tq_Pot_Cons_Kick.c
* Version int :/main/L03_01/1 Date: 12/4/2012 13 h 55 m User:esnault 
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L03_010_IMPL1
*    comments :for VSCo 12.1
* Version dev :\main\branch_morisseau_vsco_euro6\1 Date: 3/4/2012 13 h 44 m User:morisseau 
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L03_010_IMPL1
*    comments :for VSCo 12.1
* Version int :/main/L02_01/1 Date: 6/9/2011 15 h 42 m User:meme
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L02_010_IMPL1
*    comments :for VSCo 11.0 : correction following TU report
* Version dev :\main\branch_halouane_vsco_euro6\1 Date: 9/8/2011 15 h 41 m User:halouane
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L02_010_IMPL1
*    comments :For vsco_11.0_e6.
* Version int :/main/L01_01/2 Date: 24/2/2011 10 h 22 m User:esnault
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL2
*    comments :For VSCo 10.0 . Correction after TU
* Version dev :\main\branch_veillard_vsco\17 Date: 23/2/2011 14 h 19 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL2
*    comments :For VSCo 10.0
*    comments :Correction after TU
* Version dev :\main\branch_veillard_vsco\16 Date: 23/2/2011 14 h 18 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL2
*    comments :For VSCo 10.0
*    comments :Correction after TU
* Version dev :\main\branch_veillard_vsco\15 Date: 23/2/2011 14 h 2 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL2
*    comments :For VSCo 10.0
*    comments :Correction after TU
* Version dev :\main\branch_veillard_vsco\14 Date: 18/2/2011 15 h 48 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL2
*    comments :For VSCo 10.0 (Update of model only after TU return on other models)
* Version dev :\main\branch_veillard_vsco\13 Date: 16/2/2011 17 h 42 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCO 10.0 (built a new bubble only)
* Version dev :\main\branch_veillard_vsco\12 Date: 16/2/2011 17 h 31 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCO 10.0 (built a new bubble only)
* Version int :/main/L01_01/1 Date: 4/2/2011 17 h 30 m User:esnault
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\11 Date: 4/2/2011 15 h 5 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\10 Date: 3/2/2011 17 h 11 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\9 Date: 28/1/2011 15 h 16 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\8 Date: 27/1/2011 14 h 45 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\7 Date: 27/1/2011 14 h 36 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\6 Date: 27/1/2011 10 h 47 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\5 Date: 16/12/2010 11 h 11 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\4 Date: 15/12/2010 17 h 58 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\3 Date: 15/12/2010 16 h 54 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\2 Date: 15/12/2010 11 h 56 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
*    comments :For VSCo 10.0
* Version dev :\main\branch_veillard_vsco\1 Date: 14/12/2010 17 h 46 m User:veillard
*    TWK_model:VSCO_Whl_Tq_Pot_Cons_Kick_L01_010_IMPL1
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


/* VSCtl_stCtl_aVehPotDVSReg */
#define VSCO_VSCTL_STCTL_AVEHPOTDVSREG_ARRET                    (UInt32)0
#define VSCO_VSCTL_STCTL_AVEHPOTDVSREG_CONTROLE_MODE_GMP        (UInt32)1
#define VSCO_VSCTL_STCTL_AVEHPOTDVSREG_CONTROLE_MODE_FREIN      (UInt32)2


/* VSCtl_sgnTqWhlPotMin */
#define VSCO_WHEEL_TORQUE_POT_NEGATIF       (UInt8)0
#define VSCO_WHEEL_TORQUE_POT_POSITIF       (UInt8)1

/* stateflow vsco_f623_autorisation_kick_down */
#define VSCO_F623_INIT          (UInt32)0
#define VSCO_F623_VRAI          (UInt32)1
#define VSCO_F623_TEMPO_1       (UInt32)2
#define VSCO_F623_FAUX          (UInt32)3
#define VSCO_F623_TEMPO_2       (UInt32)4


#define VSCO_WHEEL_TORQUE_POT_0_DEC2        (UInt16)(0 * DEC2)
#define VSCO_WHEEL_TORQUE_POT_0_BIN4        (UInt16)(0 * BIN4)

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
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehPotMaxReq; /* BIN10 */
extern VAR(SInt16, AUTOMATIC) VSCtl_aVehPotMinReq; /* BIN10 */
extern VAR(UInt16, AUTOMATIC) VSCtl_aVehRsv_HysHi; /* BIN10 */
extern VAR(UInt16, AUTOMATIC) VSCtl_aVehRsv_HysLo; /* BIN10 */
extern VAR(SInt16, AUTOMATIC) VSCtl_aResFil; /* BIN10 */
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variables definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bCtlEfc_tqMax;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSRegInt_aVeh;
extern VAR(UInt8, AUTOMATIC) VSCtl_bHld_aVehPotReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_stCtl_aVehPot;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdDVSRegInt_aVeh;
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
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTolDft_bKdAuthVSLim_C      = (CONST(UInt16, AUTOMATIC))(199 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiTol_bKdAuthVSLim_C         = (CONST(UInt16, AUTOMATIC))(199 * BIN0);
#define VSCO_STOP_SEC_CALIB_16BIT
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define VSCO_START_SEC_VAR_8BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bhld_avehpotreq_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_avehpot_cpy;
STATIC VAR(UInt8, AUTOMATIC) vsco_f62211_min_mode_controle_potentiel_couple_roue;
STATIC VAR(UInt8, AUTOMATIC) vsco_f62221_max_mode_controle_potentiel_couple_roue;
STATIC VAR(UInt8, AUTOMATIC) vsctl_bkdauth_local;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlpot_prev;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlpotmax_prev;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stctl_tqwhlpotmin_prev;
#define VSCO_STOP_SEC_VAR_8BIT
#include "VSCo_MemMap.h"



/* 16-bits variable definition */
#define VSCO_START_SEC_VAR_16BIT
#include "VSCo_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsctl_aresfil_cpy;
STATIC VAR(UInt16, AUTOMATIC) vsctl_avehrsv_hyslo_cpy;
STATIC VAR(UInt16, AUTOMATIC) vsctl_avehrsv_hyshi_cpy;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotminreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotmaxreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_ticfmsdwntqminreq_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_ticfmsuptqmaxreq_prev;
STATIC VAR(UInt16, AUTOMATIC) vsctl_ticfmsuptqminreq_prev;
STATIC VAR(SInt16, AUTOMATIC) vsctl_tqwhlpotreq_prev;
#define VSCO_STOP_SEC_VAR_16BIT
#include "VSCo_MemMap.h"



/* 32-bits variable definition */
#define VSCO_START_SEC_VAR_32BIT
#include "VSCo_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsctl_stctl_tqwhlpotmin_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_stctl_tqwhlpotmax_local;
STATIC VAR(UInt32, AUTOMATIC) vsctl_stctl_tqwhlpot_local;
STATIC VAR(UInt32, AUTOMATIC) vsco_f623_autorisation_kick_down;
STATIC VAR(SInt32, AUTOMATIC) vsctl_tqwhlpot_rsvhithd_temp;
STATIC VAR(SInt32, AUTOMATIC) vsctl_tqwhlpot_rsvlothd_temp;
#define VSCO_STOP_SEC_VAR_32BIT
#include "VSCo_MemMap.h"


/* complex variables definition */
#define VSCO_START_SEC_VAR_UNSPECIFIED
#include "VSCo_MemMap.h"
STATIC VAR(t_dds_m_filter_hyst_s32, AUTOMATIC) vsco_f62213_min_1_filter_hyst_s32;
STATIC VAR(t_dds_m_filter_hyst_s32, AUTOMATIC) vsco_f62213_min_2_filter_hyst_s32;
STATIC VAR(t_dds_m_filter_hyst_s32, AUTOMATIC) vsco_max_1_filter_hyst_s32;
STATIC VAR(t_dds_m_filter_hyst_s32, AUTOMATIC) vsco_max_2_filter_hyst_s32;
#define VSCO_STOP_SEC_VAR_UNSPECIFIED
#include "VSCo_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rCtlTqWhlPotMin; /* BIN4 */
/* <PRQA_COMMENT><3229> variable linked to a terminator in the SPEC</3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMinReqRaw; /* BIN1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rCtlTqWhlPotMax; /* BIN4 */
/* <PRQA_COMMENT><3229> variable linked to a terminator in the SPEC</3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqWhlPotMaxReqRaw; /* BIN1 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiKdAuth;
#define VSCO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSCo_MemMap.h"

/* 8-bits variable definition */
#define VSCO_START_SEC_INTERNAL_VAR_8BIT
#include "VSCo_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvRsv_tqWhlMin;
/* <PRQA_COMMENT><3229> variable linked to a terminator in the SPEC</3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_sgnTqWhlPotMin;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bAcvRsv_tqWhlMax;
/* <PRQA_COMMENT><3229> variable linked to a terminator in the SPEC</3229></PRQA_COMMENT> */
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_sgnTqWhlPotMax;
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


STATIC FUNC(void, AUTOMATIC) VSCO_F622_Wheel_Torque_Pot_Cons_Deter(UInt16 vsctl_mveh_par,
                                                                   UInt16 vsctl_rdwhl_par,
                                                                   UInt16 vsctl_rctltqwhlptpotvslim_par,
                                                                   UInt16 vsctl_rctltqwhlptpotvsmax_par,
                                                                   UInt16 vsctl_rctltqwhlptpotdvsreg_par,
                                                                   UInt16 vsctl_rctltqwhlptpotvsreg_par,
                                                                   SInt16 vsctl_tqwhlptpotmax_par,
                                                                   SInt16 vsctl_tqwhlptpotmin_par,
                                                                   UInt8 vsctl_bctl_avehpotvsmax_par,
                                                                   UInt8 vsctl_bctl_avehpotvsreg_par,
                                                                   UInt8 vsctl_bctl_avehpotvslim_par,
                                                                   UInt8 vsctl_stctl_avehpotdvsreg_par,
                                                                   UInt16 vsctl_ticfmsdwndvsregreq_par,
                                                                   UInt16 vsctl_ticfmsdwnvslimreq_par,
                                                                   UInt16 vsctl_ticfmsdwnvsmaxreq_par,
                                                                   UInt16 vsctl_ticfmsdwnvsregreq_par,
                                                                   UInt16 vsctl_ticfmsupdvsregreq_par,
                                                                   UInt16 vsctl_ticfmsupvslimreq_par,
                                                                   UInt16 vsctl_ticfmsupvsmaxreq_par,
                                                                   UInt16 vsctl_ticfmsupvsregreq_par,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminreq_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxreq_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqminreq_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqmaxreq_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqminreq_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpot_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmax_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmin_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotreq_ptr);



STATIC FUNC(void, AUTOMATIC) VSCO_F623_Kickdown_Auth_Deter(UInt8 vsctl_stvsctlinfo_par,
                                                           UInt8 vsctl_bdrvovrdvsmax_aveh_par,
                                                           UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                                           UInt8 vsctl_stctl_avehdvsreg_par,
                                                           UInt8 vsctl_stctl_avehvslim_par,
                                                           UInt8 vsctl_stctl_avehvsreg_par,
                                                           UInt8 vsctl_stctl_avehvsmax_par,
                                                           UInt8 frm_bdeacvsctlkdctl_par,
                                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bkdauth_ptr);





STATIC FUNC(void, AUTOMATIC) VSCO_F6221_Min_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_bctl_avehpotvsreg_par,
                                                                        UInt8  vsctl_stctl_avehpotdvsreg_par,
                                                                        UInt16 vsctl_rctltqwhlptpotdvsreg_par,
                                                                        UInt16 vsctl_rctltqwhlptpotvsreg_par,
                                                                        UInt16 vsctl_rdwhl_par,
                                                                        UInt16 vsctl_mveh_par,
                                                                        SInt16 vsctl_tqwhlptpotmax_par,
                                                                        SInt16 vsctl_tqwhlptpotmin_par,
                                                                        UInt16 vsctl_ticfmsupvsregreq_par,
                                                                        UInt16 vsctl_ticfmsdwnvsregreq_par,
                                                                        UInt16 vsctl_ticfmsupdvsregreq_par,
                                                                        UInt16 vsctl_ticfmsdwndvsregreq_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmin_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminreq_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqminreq_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqminreq_ptr);



STATIC FUNC(void, AUTOMATIC) VSCO_F6222_Max_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_bctl_avehpotvslim_par,
                                                                        UInt8  vsctl_bctl_avehpotvsmax_par,
                                                                        UInt16 vsctl_rctltqwhlptpotvsmax_par,
                                                                        UInt16 vsctl_rctltqwhlptpotvslim_par,
                                                                        UInt16 vsctl_ticfmsupvslimreq_par,
                                                                        UInt16 vsctl_ticfmsdwnvslimreq_par,
                                                                        UInt16 vsctl_ticfmsupvsmaxreq_par,
                                                                        UInt16 vsctl_ticfmsdwnvsmaxreq_par,
                                                                        UInt16 vsctl_rdwhl_par,
                                                                        UInt16 vsctl_mveh_par,
                                                                        SInt16 vsctl_tqwhlptpotmax_par,
                                                                        SInt16 vsctl_tqwhlptpotmin_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmax_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxreq_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqmaxreq_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F6223_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                    SInt16 vsctl_tqwhlpotmaxreq_par,
                                                                    UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                    SInt16  vsctl_tqwhlpotminreq_par,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotreq_ptr,
                                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpot_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F62211_Min_Wheel_Torque_Pot_Ctrl_Mode_Deter(UInt8 vsctl_bctl_avehpotvsreg_par,
                                                                              UInt8 vsctl_stctl_avehpotdvsreg_par,
                                                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmin_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F62212_Min_Wheel_Torque_Pot_App_Rate_Deter(UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                             UInt16 vsctl_rctltqwhlptpotdvsreg_par,
                                                                             UInt16 vsctl_rctltqwhlptpotvsreg_par);


STATIC FUNC(void, AUTOMATIC) VSCO_F62213_Min_Wheel_Torque_Pot_Cons_Deter(UInt8 vsctl_stctl_tqwhlpotmin_par,
                                                                         UInt16 vsctl_rdwhl_par,
                                                                         UInt16 vsctl_mveh_par,
                                                                         SInt16 vsctl_tqwhlptpotmax_par,
                                                                         SInt16 vsctl_tqwhlptpotmin_par,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminreq_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_Vsctl_Tqwhlrsv_Hys_Calc(UInt16 vsctl_rdwhl_par,
                                                          UInt16 vsctl_mveh_par,
                                                          SInt16 vsctl_tqwhlptpotmax_par,
                                                          SInt16 vsctl_tqwhlptpotmin_par);

STATIC FUNC(void, AUTOMATIC) VSCO_F62214_Min_Wheel_Torque_Gear_Chgt_Conf_Time_Deter(UInt8 vsctl_stctl_tqwhlpotmin_par,
                                                                                    UInt16 vsctl_ticfmsupvsregreq_par,
                                                                                    UInt16 vsctl_ticfmsdwnvsregreq_par,
                                                                                    UInt16 vsctl_ticfmsupdvsregreq_par,
                                                                                    UInt16 vsctl_ticfmsdwndvsregreq_par,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqminreq_ptr,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqminreq_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F62221_Max_Wheel_Torque_Pot_Ctrl_Mode_Deter(UInt8  vsctl_bctl_avehpotvslim_par,
                                                                              UInt8  vsctl_bctl_avehpotvsmax_par,
                                                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmax_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F62222_Max_Wheel_Torque_Pot_App_Rate_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                             UInt16 vsctl_rctltqwhlptpotvsmax_par,
                                                                             UInt16 vsctl_rctltqwhlptpotvslim_par);

STATIC FUNC(void, AUTOMATIC) VSCO_F62223_Max_Wheel_Torque_Pot_Cons_Deter(UInt8 vsctl_stctl_tqwhlpotmax_par,
                                                                         UInt16 vsctl_rdwhl_par,
                                                                         UInt16 vsctl_mveh_par,
                                                                         SInt16 vsctl_tqwhlptpotmax_par,
                                                                         SInt16 vsctl_tqwhlptpotmin_par,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxreq_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_ptr);

STATIC FUNC(void, AUTOMATIC) VSCO_F62224_Max_Wheel_Torque_Gear_Chgt_Conf_Time_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                                    UInt16 vsctl_ticfmsupvslimreq_par,
                                                                                    UInt16 vsctl_ticfmsdwnvslimreq_par,
                                                                                    UInt16 vsctl_ticfmsupvsmaxreq_par,
                                                                                    UInt16 vsctl_ticfmsdwnvsmaxreq_par,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqmaxreq_ptr,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F62231_Wheel_Torque_Pot_Ctrl_Mode_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                          UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpot_ptr);


STATIC FUNC(void, AUTOMATIC) VSCO_F62232_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_stctl_tqwhlpot_par,
                                                                     SInt16 vsctl_tqwhlpotminreq_par,
                                                                     SInt16 vsctl_tqwhlpotmaxreq_par,
                                                                     UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotreq_ptr);

/*******************************************************************************
*
* Function Name : VSCO_Whl_Tq_Pot_Cons_Kick
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Whl_Tq_Pot_Cons_Kick(UInt16 VSCtl_mVeh_swc_in, /* BIN0 */
                                                UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotVSLim_swc_in, /* BIN4 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotVSMax_swc_in, /* BIN4 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotDVSReg_swc_in, /* BIN4 */
                                                UInt16 VSCtl_rCtlTqWhlPTPotVSReg_swc_in, /* BIN4 */
                                                SInt16 VSCtl_tqWhlPTPotMax_swc_in, /* BIN1 */
                                                SInt16 VSCtl_tqWhlPTPotMin_swc_in, /* BIN1 */
                                                UInt8 VSCtl_bCtl_aVehPotVSMax_swc_in,
                                                UInt8 VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                UInt8 VSCtl_bCtl_aVehPotVSLim_swc_in,
                                                UInt8 VSCtl_stCtl_aVehPotDVSReg_swc_in,
                                                UInt16 VSCtl_tiCfmSdwnDVSRegReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSdwnVSLimReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSdwnVSMaxReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSdwnVSRegReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupDVSRegReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupVSLimReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupVSMaxReq_swc_in, /* DEC2 */
                                                UInt16 VSCtl_tiCfmSupVSRegReq_swc_in, /* DEC2 */
                                                UInt8 VSCtl_stVSCtlInfo_swc_in,
                                                UInt8 Ext_stCtlCmdPTTqPotCf_swc_in,
                                                UInt8 VSCtl_bDrvOvrdVSMax_aVeh_swc_in,
                                                UInt8 VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                                UInt8 VSCtl_stCtl_aVehDVSReg_swc_in,
                                                UInt8 VSCtl_stCtl_aVehVSLim_swc_in,
                                                UInt8 VSCtl_stCtl_aVehVSMax_swc_in,
                                                UInt8 VSCtl_stCtl_aVehVSReg_swc_in,
                                                UInt8 FRM_bDeacVSCtlKDCtl_swc_in,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinReq_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxReq_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvLoThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvHiThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvLoThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvHiThd_swc_out, /* BIN1 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMaxReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMinReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMaxReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMinReq_swc_out, /* DEC2 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPot_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMax_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMin_swc_out,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotReq_swc_out, /* BIN1 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bKdAuth_swc_out)
{


    vsctl_aresfil_cpy           = VSCtl_aResFil;
    vsctl_avehrsv_hyslo_cpy     = VSCtl_aVehRsv_HysLo;
    vsctl_avehrsv_hyshi_cpy     = VSCtl_aVehRsv_HysHi;
    vsctl_bhld_avehpotreq_cpy   = VSCtl_bHld_aVehPotReq;
    vsctl_stctl_avehpot_cpy     = VSCtl_stCtl_aVehPot;

    if((UInt32)Ext_stCtlCmdPTTqPotCf_swc_in != VSCO_STCTLCMDPTTQPOTCF_LEURAGE_PED )
    {
        VSCO_F622_Wheel_Torque_Pot_Cons_Deter(VSCtl_mVeh_swc_in,
                                                  VSCtl_rdWhl_swc_in,
                                                  VSCtl_rCtlTqWhlPTPotVSLim_swc_in,
                                                  VSCtl_rCtlTqWhlPTPotVSMax_swc_in,
                                                  VSCtl_rCtlTqWhlPTPotDVSReg_swc_in,
                                                  VSCtl_rCtlTqWhlPTPotVSReg_swc_in,
                                                  VSCtl_tqWhlPTPotMax_swc_in,
                                                  VSCtl_tqWhlPTPotMin_swc_in,
                                                  VSCtl_bCtl_aVehPotVSMax_swc_in,
                                                  VSCtl_bCtl_aVehPotVSReg_swc_in,
                                                  VSCtl_bCtl_aVehPotVSLim_swc_in,
                                                  VSCtl_stCtl_aVehPotDVSReg_swc_in,
                                                  VSCtl_tiCfmSdwnDVSRegReq_swc_in,
                                                  VSCtl_tiCfmSdwnVSLimReq_swc_in,
                                                  VSCtl_tiCfmSdwnVSMaxReq_swc_in,
                                                  VSCtl_tiCfmSdwnVSRegReq_swc_in,
                                                  VSCtl_tiCfmSupDVSRegReq_swc_in,
                                                  VSCtl_tiCfmSupVSLimReq_swc_in,
                                                  VSCtl_tiCfmSupVSMaxReq_swc_in,
                                                  VSCtl_tiCfmSupVSRegReq_swc_in,
                                                  VSCtl_tqWhlPotMinReq_swc_out,
                                                  VSCtl_tqWhlPotMaxReq_swc_out,
                                                  VSCtl_tqWhlPotMinRsvLoThd_swc_out,
                                                  VSCtl_tqWhlPotMinRsvHiThd_swc_out,
                                                  VSCtl_tqWhlPotMaxRsvLoThd_swc_out,
                                                  VSCtl_tqWhlPotMaxRsvHiThd_swc_out,
                                                  VSCtl_tiCfmSdwnTqMaxReq_swc_out,
                                                  VSCtl_tiCfmSdwnTqMinReq_swc_out,
                                                  VSCtl_tiCfmSupTqMaxReq_swc_out,
                                                  VSCtl_tiCfmSupTqMinReq_swc_out,
                                                  VSCtl_stCtl_tqWhlPot_swc_out,
                                                  VSCtl_stCtl_tqWhlPotMax_swc_out,
                                                  VSCtl_stCtl_tqWhlPotMin_swc_out,
                                                  VSCtl_tqWhlPotReq_swc_out);

        vsctl_tqwhlpotminreq_prev = *VSCtl_tqWhlPotMinReq_swc_out;
        vsctl_tqwhlpotmaxreq_prev = *VSCtl_tqWhlPotMaxReq_swc_out;
        vsctl_tqwhlpotminrsvlothd_prev = *VSCtl_tqWhlPotMinRsvLoThd_swc_out;
        vsctl_tqwhlpotminrsvhithd_prev = *VSCtl_tqWhlPotMinRsvHiThd_swc_out;
        vsctl_tqwhlpotmaxrsvlothd_prev = *VSCtl_tqWhlPotMaxRsvLoThd_swc_out;
        vsctl_tqwhlpotmaxrsvhithd_prev = *VSCtl_tqWhlPotMaxRsvHiThd_swc_out;
        vsctl_ticfmsdwntqmaxreq_prev = *VSCtl_tiCfmSdwnTqMaxReq_swc_out;
        vsctl_ticfmsdwntqminreq_prev = *VSCtl_tiCfmSdwnTqMinReq_swc_out;
        vsctl_ticfmsuptqmaxreq_prev = *VSCtl_tiCfmSupTqMaxReq_swc_out;
        vsctl_ticfmsuptqminreq_prev = *VSCtl_tiCfmSupTqMinReq_swc_out;
        vsctl_stctl_tqwhlpot_prev = *VSCtl_stCtl_tqWhlPot_swc_out;
        vsctl_stctl_tqwhlpotmax_prev = *VSCtl_stCtl_tqWhlPotMax_swc_out;
        vsctl_stctl_tqwhlpotmin_prev = *VSCtl_stCtl_tqWhlPotMin_swc_out;
        vsctl_tqwhlpotreq_prev = *VSCtl_tqWhlPotReq_swc_out;
    }
    else
    {
        *VSCtl_tqWhlPotMinReq_swc_out = vsctl_tqwhlpotminreq_prev;
        *VSCtl_tqWhlPotMaxReq_swc_out = vsctl_tqwhlpotmaxreq_prev;
        *VSCtl_tqWhlPotMinRsvLoThd_swc_out = vsctl_tqwhlpotminrsvlothd_prev;
        *VSCtl_tqWhlPotMinRsvHiThd_swc_out = vsctl_tqwhlpotminrsvhithd_prev;
        *VSCtl_tqWhlPotMaxRsvLoThd_swc_out = vsctl_tqwhlpotmaxrsvlothd_prev;
        *VSCtl_tqWhlPotMaxRsvHiThd_swc_out = vsctl_tqwhlpotmaxrsvhithd_prev;
        *VSCtl_tiCfmSdwnTqMaxReq_swc_out = vsctl_ticfmsdwntqmaxreq_prev;
        *VSCtl_tiCfmSdwnTqMinReq_swc_out = vsctl_ticfmsdwntqminreq_prev;
        *VSCtl_tiCfmSupTqMaxReq_swc_out = vsctl_ticfmsuptqmaxreq_prev;
        *VSCtl_tiCfmSupTqMinReq_swc_out = vsctl_ticfmsuptqminreq_prev;
        *VSCtl_stCtl_tqWhlPot_swc_out = vsctl_stctl_tqwhlpot_prev;
        *VSCtl_stCtl_tqWhlPotMax_swc_out = vsctl_stctl_tqwhlpotmax_prev;
        *VSCtl_stCtl_tqWhlPotMin_swc_out = vsctl_stctl_tqwhlpotmin_prev;
        *VSCtl_tqWhlPotReq_swc_out = vsctl_tqwhlpotreq_prev;
    }

    VSCO_F623_Kickdown_Auth_Deter(VSCtl_stVSCtlInfo_swc_in,
                                  VSCtl_bDrvOvrdVSMax_aVeh_swc_in,
                                  VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                  VSCtl_stCtl_aVehDVSReg_swc_in,
                                  VSCtl_stCtl_aVehVSLim_swc_in,
                                  VSCtl_stCtl_aVehVSReg_swc_in,
                                  VSCtl_stCtl_aVehVSMax_swc_in,
                                  FRM_bDeacVSCtlKDCtl_swc_in,
                                  VSCtl_bKdAuth_swc_out);

}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/
/*******************************************************************************
*
* Function Name : VSCO_F622_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSCO_F622_Wheel_Torque_Pot_Cons_Deter(UInt16 vsctl_mveh_par,
                                                                   UInt16 vsctl_rdwhl_par,
                                                                   UInt16 vsctl_rctltqwhlptpotvslim_par,
                                                                   UInt16 vsctl_rctltqwhlptpotvsmax_par,
                                                                   UInt16 vsctl_rctltqwhlptpotdvsreg_par,
                                                                   UInt16 vsctl_rctltqwhlptpotvsreg_par,
                                                                   SInt16 vsctl_tqwhlptpotmax_par,
                                                                   SInt16 vsctl_tqwhlptpotmin_par,
                                                                   UInt8 vsctl_bctl_avehpotvsmax_par,
                                                                   UInt8 vsctl_bctl_avehpotvsreg_par,
                                                                   UInt8 vsctl_bctl_avehpotvslim_par,
                                                                   UInt8 vsctl_stctl_avehpotdvsreg_par,
                                                                   UInt16 vsctl_ticfmsdwndvsregreq_par,
                                                                   UInt16 vsctl_ticfmsdwnvslimreq_par,
                                                                   UInt16 vsctl_ticfmsdwnvsmaxreq_par,
                                                                   UInt16 vsctl_ticfmsdwnvsregreq_par,
                                                                   UInt16 vsctl_ticfmsupdvsregreq_par,
                                                                   UInt16 vsctl_ticfmsupvslimreq_par,
                                                                   UInt16 vsctl_ticfmsupvsmaxreq_par,
                                                                   UInt16 vsctl_ticfmsupvsregreq_par,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminreq_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxreq_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqminreq_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqmaxreq_ptr,
                                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqminreq_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpot_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmax_ptr,
                                                                   CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmin_ptr,
                                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotreq_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.26.2 */

    VSCO_F6221_Min_Wheel_Torque_Pot_Cons_Deter(vsctl_bctl_avehpotvsreg_par,
                                               vsctl_stctl_avehpotdvsreg_par,
                                               vsctl_rctltqwhlptpotdvsreg_par,
                                               vsctl_rctltqwhlptpotvsreg_par,
                                               vsctl_rdwhl_par,
                                               vsctl_mveh_par,
                                               vsctl_tqwhlptpotmax_par,
                                               vsctl_tqwhlptpotmin_par,
                                               vsctl_ticfmsupvsregreq_par,
                                               vsctl_ticfmsdwnvsregreq_par,
                                               vsctl_ticfmsupdvsregreq_par,
                                               vsctl_ticfmsdwndvsregreq_par,
                                               vsctl_stctl_tqwhlpotmin_ptr,
                                               vsctl_tqwhlpotminreq_ptr,
                                               vsctl_tqwhlpotminrsvlothd_ptr,
                                               vsctl_tqwhlpotminrsvhithd_ptr,
                                               vsctl_ticfmsuptqminreq_ptr,
                                               vsctl_ticfmsdwntqminreq_ptr);

    VSCO_F6222_Max_Wheel_Torque_Pot_Cons_Deter(vsctl_bctl_avehpotvslim_par,
                                               vsctl_bctl_avehpotvsmax_par,
                                               vsctl_rctltqwhlptpotvsmax_par,
                                               vsctl_rctltqwhlptpotvslim_par,
                                               vsctl_ticfmsupvslimreq_par,
                                               vsctl_ticfmsdwnvslimreq_par,
                                               vsctl_ticfmsupvsmaxreq_par,
                                               vsctl_ticfmsdwnvsmaxreq_par,
                                               vsctl_rdwhl_par,
                                               vsctl_mveh_par,
                                               vsctl_tqwhlptpotmax_par,
                                               vsctl_tqwhlptpotmin_par,
                                               vsctl_stctl_tqwhlpotmax_ptr,
                                               vsctl_tqwhlpotmaxreq_ptr,
                                               vsctl_tqwhlpotmaxrsvlothd_ptr,
                                               vsctl_tqwhlpotmaxrsvhithd_ptr,
                                               vsctl_ticfmsuptqmaxreq_ptr,
                                               vsctl_ticfmsdwntqmaxreq_ptr);


    VSCO_F6223_Wheel_Torque_Pot_Cons_Deter(*vsctl_stctl_tqwhlpotmax_ptr,
                                           *vsctl_tqwhlpotmaxreq_ptr,
                                           *vsctl_stctl_tqwhlpotmin_ptr,
                                           *vsctl_tqwhlpotminreq_ptr,
                                           vsctl_tqwhlpotreq_ptr,
                                           vsctl_stctl_tqwhlpot_ptr);



}

/*******************************************************************************
*
* Function Name : VSCO_F623_Kickdown_Auth_Deter
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSCO_F623_Kickdown_Auth_Deter(UInt8 vsctl_stvsctlinfo_par,
                                                           UInt8 vsctl_bdrvovrdvsmax_aveh_par,
                                                           UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                                           UInt8 vsctl_stctl_avehdvsreg_par,
                                                           UInt8 vsctl_stctl_avehvslim_par,
                                                           UInt8 vsctl_stctl_avehvsreg_par,
                                                           UInt8 vsctl_stctl_avehvsmax_par,
                                                           UInt8 frm_bdeacvsctlkdctl_par,
                                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bkdauth_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.35.3 */

    UInt32 vsctl_bdrvovrdvsregint_aveh_cpy;
    UInt32 vsctl_bdrvovrddvsregint_aveh_cpy;

    vsctl_bdrvovrdvsregint_aveh_cpy     = (UInt32)VSCtl_bDrvOvrdVSRegInt_aVeh;
    vsctl_bdrvovrddvsregint_aveh_cpy    = (UInt32)VSCtl_bDrvOvrdDVSRegInt_aVeh;

    /* AUTORISATION_KICK_DOWN */
    switch(vsco_f623_autorisation_kick_down)
    {
        case VSCO_F623_INIT:                                                                /* Go to VRAI */
            if((UInt32)VSCtl_bCtlEfc_tqMax == (UInt32)DDS_FALSE)
            {
                vsco_f623_autorisation_kick_down = VSCO_F623_VRAI;
                vsctl_bkdauth_local              = DDS_TRUE;
                VSCtl_tiKdAuth                   = (0 * BIN0);

            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F623_VRAI:                                                                /* Go to FAUX */
            if( ((UInt32)vsctl_stvsctlinfo_par == VSCO_NOMINAL_20)
                                        &&
                ((((UInt32)vsctl_stctl_avehvslim_par == VSCO_VSCTL_STCTL_AVEHVSLIM_CONTROL)
                && ((UInt32)vsctl_bdrvovrdvslim_aveh_par == (UInt32)DDS_FALSE))
                                        ||
                (((UInt32)vsctl_stctl_avehvsmax_par == VSCO_VSCTL_STCTL_AVEHVSMAX_CONTROL)
                && ((UInt32)vsctl_bdrvovrdvsmax_aveh_par == (UInt32)DDS_FALSE))
                                        ||
                (((UInt32)vsctl_stctl_avehvsreg_par == VSCO_VSCTL_STCTL_AVEHVSREG_CONTROL)
                && (vsctl_bdrvovrdvsregint_aveh_cpy == (UInt32)DDS_FALSE))
                                        ||
                (((UInt32)vsctl_stctl_avehdvsreg_par == VSCO_CONTROLE)
                && (vsctl_bdrvovrddvsregint_aveh_cpy == (UInt32)DDS_FALSE))))
            {
                vsco_f623_autorisation_kick_down = VSCO_F623_FAUX;
                vsctl_bkdauth_local = DDS_FALSE;
            }
            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F623_FAUX:
            if( (((UInt32)vsctl_stvsctlinfo_par == VSCO_NOMINAL_20)                         /* Go back to VRAI */   &&

                ((((UInt32)vsctl_stctl_avehvslim_par        == VSCO_VSCTL_STCTL_AVEHVSLIM_CONTROL)
                && ((UInt32)vsctl_bdrvovrdvslim_aveh_par    == (UInt32)DDS_TRUE))
                || ((UInt32)vsctl_stctl_avehvslim_par       == VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET))                   &&

                ((((UInt32)vsctl_stctl_avehvsmax_par        == VSCO_VSCTL_STCTL_AVEHVSMAX_CONTROL)
                && ((UInt32)vsctl_bdrvovrdvsmax_aveh_par    == (UInt32)DDS_TRUE))
                ||((UInt32)vsctl_stctl_avehvsmax_par        == VSCO_VSCTL_STCTL_AVEHVSMAX_ARRET))                   &&

                ((((UInt32)vsctl_stctl_avehvsreg_par        == VSCO_VSCTL_STCTL_AVEHVSREG_CONTROL)
                &&(vsctl_bdrvovrdvsregint_aveh_cpy          == (UInt32)DDS_TRUE))
                ||((UInt32)vsctl_stctl_avehvsreg_par        == VSCO_VSCTL_STCTL_AVEHVSREG_ARRET))                   &&

                ((((UInt32)vsctl_stctl_avehdvsreg_par       == VSCO_CONTROLE)
                &&(vsctl_bdrvovrddvsregint_aveh_cpy         == (UInt32)DDS_TRUE))
                ||((UInt32)vsctl_stctl_avehdvsreg_par       == VSCO_ARRET)))

                                    ||

                (((UInt32)vsctl_stvsctlinfo_par             != VSCO_NOMINAL_20)
                && ((UInt32)VSCtl_bCtlEfc_tqMax    == (UInt32)DDS_FALSE)))
            {
                vsco_f623_autorisation_kick_down = VSCO_F623_VRAI;
                vsctl_bkdauth_local              = DDS_TRUE;
                VSCtl_tiKdAuth                   = (0 * BIN0);

            }
            else if(((UInt32)frm_bdeacvsctlkdctl_par    == (UInt32)DDS_FALSE)   &&                              /* Go to TEMPO_1 */
                    ((UInt32)vsctl_stctl_avehvslim_par  == VSCO_VSCTL_STCTL_AVEHVSLIM_TRANSITION_RAPIDE))
            {
                vsco_f623_autorisation_kick_down    = VSCO_F623_TEMPO_1;
                VSCtl_tiKdAuth                      = VSCtl_tiTol_bKdAuthVSLim_C;
            }

            else if (((UInt32)frm_bdeacvsctlkdctl_par   == (UInt32)DDS_TRUE)    &&                              /* Go to TEMPO_2 */
                     ((UInt32)vsctl_stctl_avehvslim_par != VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET))
            {
                vsco_f623_autorisation_kick_down    = VSCO_F623_TEMPO_2;
                VSCtl_tiKdAuth                      = VSCtl_tiTolDft_bKdAuthVSLim_C;
            }

            else    /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_F623_TEMPO_1:
            if( (((UInt32)vsctl_stvsctlinfo_par == VSCO_NOMINAL_20)                         /* Go back to VRAI */   &&

                ((((UInt32)vsctl_stctl_avehvslim_par        == VSCO_VSCTL_STCTL_AVEHVSLIM_CONTROL)
                && ((UInt32)vsctl_bdrvovrdvslim_aveh_par    == (UInt32)DDS_TRUE))
                || ((UInt32)vsctl_stctl_avehvslim_par       == VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET))                   &&

                ((((UInt32)vsctl_stctl_avehvsmax_par        == VSCO_VSCTL_STCTL_AVEHVSMAX_CONTROL)
                && ((UInt32)vsctl_bdrvovrdvsmax_aveh_par    == (UInt32)DDS_TRUE))
                ||((UInt32)vsctl_stctl_avehvsmax_par        == VSCO_VSCTL_STCTL_AVEHVSMAX_ARRET))                   &&

                ((((UInt32)vsctl_stctl_avehvsreg_par        == VSCO_VSCTL_STCTL_AVEHVSREG_CONTROL)
                &&(vsctl_bdrvovrdvsregint_aveh_cpy          == (UInt32)DDS_TRUE))
                ||((UInt32)vsctl_stctl_avehvsreg_par        == VSCO_VSCTL_STCTL_AVEHVSREG_ARRET))                   &&

                ((((UInt32)vsctl_stctl_avehdvsreg_par       == VSCO_CONTROLE)
                &&(vsctl_bdrvovrddvsregint_aveh_cpy         == (UInt32)DDS_TRUE))
                ||((UInt32)vsctl_stctl_avehdvsreg_par       == VSCO_ARRET)))

                                    ||

                (((UInt32)vsctl_stvsctlinfo_par             != VSCO_NOMINAL_20)
                && ((UInt32)VSCtl_bCtlEfc_tqMax    == (UInt32)DDS_FALSE)))
            {
                vsco_f623_autorisation_kick_down = VSCO_F623_VRAI;
                vsctl_bkdauth_local              = DDS_TRUE;
                VSCtl_tiKdAuth                   = (0 * BIN0);

            }

            else if((UInt32)VSCtl_tiKdAuth == 0)                                            /* Go to VRAI */
            {
                vsco_f623_autorisation_kick_down = VSCO_F623_VRAI;
                vsctl_bkdauth_local              = DDS_TRUE;
                VSCtl_tiKdAuth                   = (0 * BIN0);

            }

            else    /* during actions */
            {
                VSCtl_tiKdAuth = (UInt16)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiKdAuth, (UInt32)(1 * BIN0));
            }
        break;

        case VSCO_F623_TEMPO_2:
            if(
                ((((UInt32)vsctl_stvsctlinfo_par        == VSCO_NOMINAL_20)
                && ((UInt32)vsctl_stctl_avehvslim_par   == VSCO_VSCTL_STCTL_AVEHVSLIM_ARRET))
                                    ||
                (((UInt32)vsctl_stvsctlinfo_par         != VSCO_NOMINAL_20)
                && ((UInt32)VSCtl_bCtlEfc_tqMax == (UInt32)DDS_FALSE)))

                                &&

                ((UInt32)VSCtl_tiKdAuth == 0))
            {
                vsco_f623_autorisation_kick_down = VSCO_F623_VRAI;                          /* Go to VRAI */
                vsctl_bkdauth_local              = DDS_TRUE;
                VSCtl_tiKdAuth                   = (0 * BIN0);

            }
            else    /* during actions */
            {
                VSCtl_tiKdAuth = (UInt16)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiKdAuth, (UInt32)(1 * BIN0));
            }
        break;

        default:
            vsctl_bkdauth_local = DDS_FALSE;
            VSCtl_tiKdAuth = (0 * BIN0);
        break;
    }

    *vsctl_bkdauth_ptr = vsctl_bkdauth_local;

}


/*******************************************************************************
*
* Function Name : VSCO_F6221_Min_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSCO_F6221_Min_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_bctl_avehpotvsreg_par,
                                                                        UInt8  vsctl_stctl_avehpotdvsreg_par,
                                                                        UInt16 vsctl_rctltqwhlptpotdvsreg_par,
                                                                        UInt16 vsctl_rctltqwhlptpotvsreg_par,
                                                                        UInt16 vsctl_rdwhl_par,
                                                                        UInt16 vsctl_mveh_par,
                                                                        SInt16 vsctl_tqwhlptpotmax_par,
                                                                        SInt16 vsctl_tqwhlptpotmin_par,
                                                                        UInt16 vsctl_ticfmsupvsregreq_par,
                                                                        UInt16 vsctl_ticfmsdwnvsregreq_par,
                                                                        UInt16 vsctl_ticfmsupdvsregreq_par,
                                                                        UInt16 vsctl_ticfmsdwndvsregreq_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmin_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminreq_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqminreq_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqminreq_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.27.2 */

    VSCO_F62211_Min_Wheel_Torque_Pot_Ctrl_Mode_Deter(vsctl_bctl_avehpotvsreg_par,
                                                     vsctl_stctl_avehpotdvsreg_par,
                                                     vsctl_stctl_tqwhlpotmin_ptr);



    VSCO_F62212_Min_Wheel_Torque_Pot_App_Rate_Deter(*vsctl_stctl_tqwhlpotmin_ptr,
                                                    vsctl_rctltqwhlptpotdvsreg_par,
                                                    vsctl_rctltqwhlptpotvsreg_par);



    VSCO_F62213_Min_Wheel_Torque_Pot_Cons_Deter(*vsctl_stctl_tqwhlpotmin_ptr,
                                                vsctl_rdwhl_par,
                                                vsctl_mveh_par,
                                                vsctl_tqwhlptpotmax_par,
                                                vsctl_tqwhlptpotmin_par,
                                                vsctl_tqwhlpotminreq_ptr,
                                                vsctl_tqwhlpotminrsvlothd_ptr,
                                                vsctl_tqwhlpotminrsvhithd_ptr);


    VSCO_F62214_Min_Wheel_Torque_Gear_Chgt_Conf_Time_Deter(*vsctl_stctl_tqwhlpotmin_ptr,
                                                           vsctl_ticfmsupvsregreq_par,
                                                           vsctl_ticfmsdwnvsregreq_par,
                                                           vsctl_ticfmsupdvsregreq_par,
                                                           vsctl_ticfmsdwndvsregreq_par,
                                                           vsctl_ticfmsuptqminreq_ptr,
                                                           vsctl_ticfmsdwntqminreq_ptr);














}


/*******************************************************************************
*
* Function Name : VSCO_F6222_Max_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6222_Max_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_bctl_avehpotvslim_par,
                                                                        UInt8  vsctl_bctl_avehpotvsmax_par,
                                                                        UInt16 vsctl_rctltqwhlptpotvsmax_par,
                                                                        UInt16 vsctl_rctltqwhlptpotvslim_par,
                                                                        UInt16 vsctl_ticfmsupvslimreq_par,
                                                                        UInt16 vsctl_ticfmsdwnvslimreq_par,
                                                                        UInt16 vsctl_ticfmsupvsmaxreq_par,
                                                                        UInt16 vsctl_ticfmsdwnvsmaxreq_par,
                                                                        UInt16 vsctl_rdwhl_par,
                                                                        UInt16 vsctl_mveh_par,
                                                                        SInt16 vsctl_tqwhlptpotmax_par,
                                                                        SInt16 vsctl_tqwhlptpotmin_par,
                                                                        CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmax_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxreq_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqmaxreq_ptr,
                                                                        CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_ptr)


{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.31.2 */

    VSCO_F62221_Max_Wheel_Torque_Pot_Ctrl_Mode_Deter(vsctl_bctl_avehpotvslim_par,
                                                     vsctl_bctl_avehpotvsmax_par,
                                                     vsctl_stctl_tqwhlpotmax_ptr);


    VSCO_F62222_Max_Wheel_Torque_Pot_App_Rate_Deter(*vsctl_stctl_tqwhlpotmax_ptr,
                                                    vsctl_rctltqwhlptpotvsmax_par,
                                                    vsctl_rctltqwhlptpotvslim_par);


    VSCO_F62223_Max_Wheel_Torque_Pot_Cons_Deter(*vsctl_stctl_tqwhlpotmax_ptr,
                                                vsctl_rdwhl_par,
                                                vsctl_mveh_par,
                                                vsctl_tqwhlptpotmax_par,
                                                vsctl_tqwhlptpotmin_par,
                                                vsctl_tqwhlpotmaxreq_ptr,
                                                vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                vsctl_tqwhlpotmaxrsvhithd_ptr);


    VSCO_F62224_Max_Wheel_Torque_Gear_Chgt_Conf_Time_Deter(*vsctl_stctl_tqwhlpotmax_ptr,
                                                           vsctl_ticfmsupvslimreq_par,
                                                           vsctl_ticfmsdwnvslimreq_par,
                                                           vsctl_ticfmsupvsmaxreq_par,
                                                           vsctl_ticfmsdwnvsmaxreq_par,
                                                           vsctl_ticfmsuptqmaxreq_ptr,
                                                           vsctl_ticfmsdwntqmaxreq_ptr);
}

/*******************************************************************************
*
* Function Name : VSCO_F6223_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F6223_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                    SInt16 vsctl_tqwhlpotmaxreq_par,
                                                                    UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                    SInt16 vsctl_tqwhlpotminreq_par,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotreq_ptr,
                                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpot_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.48.0 */

    VSCO_F62231_Wheel_Torque_Pot_Ctrl_Mode_Deter(vsctl_stctl_tqwhlpotmax_par,
                                                 vsctl_stctl_tqwhlpotmin_par,
                                                 vsctl_stctl_tqwhlpot_ptr);



    VSCO_F62232_Wheel_Torque_Pot_Cons_Deter(*vsctl_stctl_tqwhlpot_ptr,
                                            vsctl_tqwhlpotminreq_par,
                                            vsctl_tqwhlpotmaxreq_par,
                                            vsctl_stctl_tqwhlpotmin_par,
                                            vsctl_tqwhlpotreq_ptr);


}

/*******************************************************************************
*
* Function Name : VSCO_F62211_Min_Wheel_Torque_Pot_Ctrl_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62211_Min_Wheel_Torque_Pot_Ctrl_Mode_Deter(UInt8 vsctl_bctl_avehpotvsreg_par,
                                                                              UInt8 vsctl_stctl_avehpotdvsreg_par,
                                                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmin_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.28.3 */

    /* MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_MIN */
    switch((UInt32)vsco_f62211_min_mode_controle_potentiel_couple_roue)
    {
        case VSCO_ARRET:
            if( ((UInt32)vsctl_stctl_avehpot_cpy == VSCO_CONTROLE)  &&
                (   ((UInt32)vsctl_bctl_avehpotvsreg_par != VSCO_ARRET) ||
                    ((UInt32)vsctl_stctl_avehpotdvsreg_par != VSCO_VSCTL_STCTL_AVEHPOTDVSREG_ARRET) )   )
            {
                vsco_f62211_min_mode_controle_potentiel_couple_roue = (UInt8)VSCO_CONTROLE;
                vsctl_stctl_tqwhlpotmin_local = VSCO_POT_CONTROLE;
                VSCtl_bAcvRsv_tqWhlMin = DDS_TRUE;
            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_CONTROLE:
            if( ((UInt32)vsctl_stctl_avehpot_cpy == VSCO_ARRET)  ||
                (   ((UInt32)vsctl_bctl_avehpotvsreg_par == VSCO_ARRET) &&
                    ((UInt32)vsctl_stctl_avehpotdvsreg_par == VSCO_VSCTL_STCTL_AVEHPOTDVSREG_ARRET))    )
            {
                vsco_f62211_min_mode_controle_potentiel_couple_roue = (UInt8)VSCO_ARRET;
                vsctl_stctl_tqwhlpotmin_local = VSCO_POT_ARRET;
                VSCtl_bAcvRsv_tqWhlMin = DDS_FALSE;
            }
        break;

        default:
            vsctl_stctl_tqwhlpotmin_local = VSCO_POT_ARRET;
            VSCtl_bAcvRsv_tqWhlMin = DDS_FALSE;
        break;
    }


*vsctl_stctl_tqwhlpotmin_ptr = (UInt8)vsctl_stctl_tqwhlpotmin_local;


}

/*******************************************************************************
*
* Function Name : VSCO_F62212_Min_Wheel_Torque_Pot_App_Rate_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62212_Min_Wheel_Torque_Pot_App_Rate_Deter(UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                             UInt16 vsctl_rctltqwhlptpotdvsreg_par,
                                                                             UInt16 vsctl_rctltqwhlptpotvsreg_par)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.29.2 */

    if(VSCO_POT_CONTROLE == (UInt32)vsctl_stctl_tqwhlpotmin_par)
    {
        VSCtl_rCtlTqWhlPotMin = (UInt16)DDS_M_MAX((SInt32)vsctl_rctltqwhlptpotdvsreg_par,(SInt32)vsctl_rctltqwhlptpotvsreg_par);
    }
    else
    {
        VSCtl_rCtlTqWhlPotMin = VSCO_WHEEL_TORQUE_POT_0_BIN4;
    }


}


/*******************************************************************************
*
* Function Name : VSCO_F62213_Min_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62213_Min_Wheel_Torque_Pot_Cons_Deter(UInt8 vsctl_stctl_tqwhlpotmin_par,
                                                                         UInt16 vsctl_rdwhl_par,
                                                                         UInt16 vsctl_mveh_par,
                                                                         SInt16 vsctl_tqwhlptpotmax_par,
                                                                         SInt16 vsctl_tqwhlptpotmin_par,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminreq_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvlothd_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotminrsvhithd_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.51.0 */

    SInt32 vsco_temp;
    SInt8 nb_shift;
    SInt32 vsco_out_hyst_1;
    SInt32 vsco_out_hyst_2;
    SInt32 vsco_input_bary;
    SInt16 vsco_temp_2;
    SInt32 vsctl_tqwhlpotminreqraw_temp;
    UInt32 vsco_hyslo, vsco_hyshi;

    /* [-20;20]BIN10 = [-10;10]BIN10 - [-10;10]BIN10 */
    vsco_temp = (SInt32)VSCtl_aVehPotMinReq - (SInt32)vsctl_aresfil_cpy;

    /* [-200;200]BIN17 = [-20;20]BIN10 * [1/128;10]BIN7 */
    vsco_temp = vsco_temp * (SInt32)vsctl_rdwhl_par;
    nb_shift = (SInt8)17;

    /* [-200;200]BIN17 * [1;10 000]BIN0 */
    vsco_temp = DDS_M_DYNAMIC_MULT_S32(vsco_temp,
                                        (SInt32)vsctl_mveh_par,
                                        &nb_shift);
    /* [-2 000000;2 000000]BIN17 reduce to [-16383;16383]BIN17 */
    vsco_temp = DDS_M_RESTORE_BINPOINT_SINT32(vsco_temp, (SInt8)((SInt32)nb_shift - (SInt32)17));

    /* [-16000;16000]BIN17 */
    vsctl_tqwhlpotminreqraw_temp = DDS_M_SATURATION_V2(vsco_temp,
                                                      (SInt32)vsctl_tqwhlptpotmin_par * BIN16,
                                                      (SInt32)vsctl_tqwhlptpotmax_par * BIN16);

    VSCO_Vsctl_Tqwhlrsv_Hys_Calc(vsctl_rdwhl_par,
                                  vsctl_mveh_par,
                                  vsctl_tqwhlptpotmax_par,
                                  vsctl_tqwhlptpotmin_par);


    vsco_hyslo = (UInt32)DDS_M_MAX(vsctl_tqwhlpot_rsvlothd_temp, 0);
    vsco_hyshi = (UInt32)DDS_M_MAX(vsctl_tqwhlpot_rsvhithd_temp, 0);

    vsco_out_hyst_1 = DDS_M_FILTER_HYST_S32(&vsco_f62213_min_1_filter_hyst_s32,
                                            vsctl_tqwhlpotminreqraw_temp,               /* [-16000;16000]BIN17 */
                                            vsco_hyslo,
                                            vsco_hyshi,
                                            VSCtl_bAcvRsv_tqWhlMin);

    vsco_out_hyst_2 = DDS_M_FILTER_HYST_S32(&vsco_f62213_min_2_filter_hyst_s32,
                                            vsctl_tqwhlpotminreqraw_temp,               /* [-16000;16000]BIN17 */
                                            vsco_hyshi,
                                            vsco_hyslo,
                                            VSCtl_bAcvRsv_tqWhlMin);

    switch((UInt32)vsctl_stctl_tqwhlpotmin_par)
    {
        case(VSCO_POT_CONTROLE):

            VSCtl_tqWhlPotMinReqRaw = (SInt16)(vsctl_tqwhlpotminreqraw_temp / BIN16);                   /* [-16000;16000]BIN1 */

            *vsctl_tqwhlpotminrsvlothd_ptr = (SInt16)(vsctl_tqwhlpot_rsvlothd_temp / BIN16);            /* [-16000;16000]BIN1 */
            *vsctl_tqwhlpotminrsvhithd_ptr = (SInt16)(vsctl_tqwhlpot_rsvhithd_temp / BIN16);            /* [-16000;16000]BIN1 */

            if((SInt32)0 < (SInt32)vsctl_tqwhlpotminreq_prev)
            {
                VSCtl_sgnTqWhlPotMin = VSCO_WHEEL_TORQUE_POT_POSITIF;
                vsco_input_bary = vsco_out_hyst_1;
            }
            else
            {
                VSCtl_sgnTqWhlPotMin = VSCO_WHEEL_TORQUE_POT_NEGATIF;
                vsco_input_bary = vsco_out_hyst_2;
            }

            if((UInt32)DDS_TRUE == (UInt32)vsctl_bhld_avehpotreq_cpy)
            {
                vsco_temp_2 = vsctl_tqwhlpotminreq_prev;                                /* [-16000;16000]BIN1 */
            }
            else
            {
                vsco_temp_2 = (SInt16)(DDS_M_BARY_FILTER_S32(vsco_input_bary,
                                                   (SInt32)(0),
                                                   VSCtl_rCtlTqWhlPotMin,
                                                   (UInt16)(100 * BIN4)) / BIN16);
            }

            *vsctl_tqwhlpotminreq_ptr = vsco_temp_2;                                    /* [-16000;16000]BIN1 */
            break;
        case(VSCO_POT_ARRET):
        default:
            *vsctl_tqwhlpotminrsvlothd_ptr  = VSCO_TORQUE_CONS_0_BIN1;
            *vsctl_tqwhlpotminrsvhithd_ptr  = VSCO_TORQUE_CONS_0_BIN1;
            VSCtl_tqWhlPotMinReqRaw         = VSCO_TORQUE_CONS_16000_BIN1_NEG;
            VSCtl_sgnTqWhlPotMin            = VSCO_WHEEL_TORQUE_POT_POSITIF;
            *vsctl_tqwhlpotminreq_ptr       = VSCO_TORQUE_CONS_16000_BIN1_NEG;
            break;

    }
}


/*******************************************************************************
*
* Function Name : VSCO_Vsctl_Tqwhlrsv_Hys_Calc
* Description :   Used for calculation of   VSCtl_tqWhlPotMinRsvLoThd and VSCtl_tqWhlPotMinRsvHiThd
*                                           VSCtl_tqWhlPotMaxRsvLoThd and VSCtl_tqWhlPotMaxRsvHiThd
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSCO_Vsctl_Tqwhlrsv_Hys_Calc(UInt16 vsctl_rdwhl_par,
                                                           UInt16 vsctl_mveh_par,
                                                           SInt16 vsctl_tqwhlptpotmax_par,
                                                           SInt16 vsctl_tqwhlptpotmin_par)
{
    SInt32 vscoh_temp;
    SInt8 nb_shift;

    /* [0;100]BIN17 = [0;10]BIN10 * [1/128;10]BIN7 */
    vscoh_temp = (SInt32)vsctl_avehrsv_hyslo_cpy * (SInt32)vsctl_rdwhl_par;

    nb_shift = (SInt8)17;

    /* [0;100]BIN17 * [1;10 000]BIN0 */
    vscoh_temp = DDS_M_DYNAMIC_MULT_S32(vscoh_temp,
                                        (SInt32)vsctl_mveh_par,
                                        &nb_shift);

    /* [0;1 000000]BIN17 reduce to [-16383;16383]BIN17 */
    vscoh_temp = DDS_M_RESTORE_BINPOINT_SINT32(vscoh_temp, (SInt8)((SInt32)nb_shift - (SInt32)17));

    /* [-16000;16000] BIN17 */
    vsctl_tqwhlpot_rsvlothd_temp = DDS_M_SATURATION_V2(vscoh_temp,
                                                      (SInt32)vsctl_tqwhlptpotmin_par * BIN16,
                                                      (SInt32)vsctl_tqwhlptpotmax_par * BIN16);



    /* [0;100]*BIN17 = [0;10]BIN10 * [1/128;10]BIN7 */
    vscoh_temp = (SInt32)vsctl_avehrsv_hyshi_cpy * (SInt32)vsctl_rdwhl_par;

    nb_shift = (SInt8)17;

    /* [0;100]BIN17 * [1;10000]BIN0 */
    vscoh_temp = DDS_M_DYNAMIC_MULT_S32(vscoh_temp,
                                        (SInt32)vsctl_mveh_par,
                                        &nb_shift);

    /* [0;1 000000]BIN17  reduce to [-16383;16383]BIN17*/
    vscoh_temp = DDS_M_RESTORE_BINPOINT_SINT32(vscoh_temp, (SInt8)((SInt32)nb_shift - (SInt32)17));

    /* [-16000; 16000]BIN17 */
    vsctl_tqwhlpot_rsvhithd_temp = DDS_M_SATURATION_V2(vscoh_temp,
                                                      (SInt32)vsctl_tqwhlptpotmin_par * BIN16,
                                                      (SInt32)vsctl_tqwhlptpotmax_par * BIN16);

}


/*******************************************************************************
*
* Function Name : VSCO_F62214_Min_Wheel_Torque_Gear_Chgt_Conf_Time_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62214_Min_Wheel_Torque_Gear_Chgt_Conf_Time_Deter(UInt8 vsctl_stctl_tqwhlpotmin_par,
                                                                                    UInt16 vsctl_ticfmsupvsregreq_par,
                                                                                    UInt16 vsctl_ticfmsdwnvsregreq_par,
                                                                                    UInt16 vsctl_ticfmsupdvsregreq_par,
                                                                                    UInt16 vsctl_ticfmsdwndvsregreq_par,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqminreq_ptr,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqminreq_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.46.0 */

    if(VSCO_POT_CONTROLE == (UInt32)vsctl_stctl_tqwhlpotmin_par)
    {
        *vsctl_ticfmsuptqminreq_ptr     = (UInt16)DDS_M_MAX((SInt32)vsctl_ticfmsupvsregreq_par,(SInt32)vsctl_ticfmsupdvsregreq_par);
        *vsctl_ticfmsdwntqminreq_ptr    = (UInt16)DDS_M_MAX((SInt32)vsctl_ticfmsdwnvsregreq_par,(SInt32)vsctl_ticfmsdwndvsregreq_par);
    }
    else
    {
        *vsctl_ticfmsuptqminreq_ptr  = VSCO_WHEEL_TORQUE_POT_0_DEC2;
        *vsctl_ticfmsdwntqminreq_ptr = VSCO_WHEEL_TORQUE_POT_0_DEC2;
    }
}



/*******************************************************************************
*
* Function Name : VSCO_F62221_Max_Wheel_Torque_Pot_Ctrl_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62221_Max_Wheel_Torque_Pot_Ctrl_Mode_Deter(UInt8  vsctl_bctl_avehpotvslim_par,
                                                                              UInt8  vsctl_bctl_avehpotvsmax_par,
                                                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpotmax_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.32.3 */

    /* MODE_CONTROLE_POTENTIEL_COUPLE_ROUE_MAX */
    switch((UInt32)vsco_f62221_max_mode_controle_potentiel_couple_roue)
    {
        case VSCO_ARRET:
            if(((UInt32)vsctl_stctl_avehpot_cpy == VSCO_CONTROLE)       &&
               (((UInt32)vsctl_bctl_avehpotvslim_par == VSCO_CONTROLE) || ((UInt32)vsctl_bctl_avehpotvsmax_par == VSCO_CONTROLE)))
            {
                vsco_f62221_max_mode_controle_potentiel_couple_roue = (UInt8)VSCO_CONTROLE;
                vsctl_stctl_tqwhlpotmax_local   = VSCO_POT_CONTROLE;
                VSCtl_bAcvRsv_tqWhlMax          = DDS_TRUE;

            }
            else     /* during actions */
            {
                /* do nothing, stay in this state */
            }
        break;

        case VSCO_CONTROLE:
            if(((UInt32)vsctl_stctl_avehpot_cpy == VSCO_ARRET) ||
                (((UInt32)vsctl_bctl_avehpotvslim_par == VSCO_ARRET) && ((UInt32)vsctl_bctl_avehpotvsmax_par == VSCO_ARRET)))
            {
                vsco_f62221_max_mode_controle_potentiel_couple_roue = (UInt8)VSCO_ARRET;
                vsctl_stctl_tqwhlpotmax_local   = VSCO_POT_ARRET;
                VSCtl_bAcvRsv_tqWhlMax          = DDS_FALSE;
            }
        break;

        default:
            vsctl_stctl_tqwhlpotmax_local   = VSCO_POT_ARRET;
            VSCtl_bAcvRsv_tqWhlMax          = DDS_FALSE;
        break;
    }

    *vsctl_stctl_tqwhlpotmax_ptr = (UInt8)vsctl_stctl_tqwhlpotmax_local;

}



/*******************************************************************************
*
* Function Name : VSCO_F62222_Max_Wheel_Torque_Pot_App_Rate_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62222_Max_Wheel_Torque_Pot_App_Rate_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                             UInt16 vsctl_rctltqwhlptpotvsmax_par,
                                                                             UInt16 vsctl_rctltqwhlptpotvslim_par)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.33.3 */

    if(VSCO_POT_CONTROLE == (UInt32)vsctl_stctl_tqwhlpotmax_par)
    {
        VSCtl_rCtlTqWhlPotMax = (UInt16)DDS_M_MAX((SInt32)vsctl_rctltqwhlptpotvsmax_par,(SInt32)vsctl_rctltqwhlptpotvslim_par);
    }
    else
    {
        VSCtl_rCtlTqWhlPotMax = VSCO_WHEEL_TORQUE_POT_0_BIN4;       /* [0;100]BIN4 */
    }
}


/*******************************************************************************
*
* Function Name : VSCO_F62223_Max_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62223_Max_Wheel_Torque_Pot_Cons_Deter(UInt8 vsctl_stctl_tqwhlpotmax_par,
                                                                         UInt16 vsctl_rdwhl_par,
                                                                         UInt16 vsctl_mveh_par,
                                                                         SInt16 vsctl_tqwhlptpotmax_par,
                                                                         SInt16 vsctl_tqwhlptpotmin_par,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxreq_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvlothd_ptr,
                                                                         CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotmaxrsvhithd_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.52.0 */

    SInt32 vsco_temp;
    SInt8 nb_shift;
    SInt32 vsco_out_hyst_1;
    SInt32 vsco_out_hyst_2;
    SInt32 vsco_input_bary;
    SInt16 vsco_temp_2;
    SInt32 vsctl_tqwhlpotmaxreqraw_temp;
    UInt32 vsco_hyslo, vsco_hyshi;

    /* [-20;20]BIN10 = [-10;10]BIN10 - [-10;10]BIN10 */
    vsco_temp = (SInt32)VSCtl_aVehPotMaxReq - (SInt32)vsctl_aresfil_cpy;

    /* [-200;200]BIN17 = [-20;20]BIN10 * [1/128;10]*BIN7 */
    vsco_temp = vsco_temp * (SInt32)vsctl_rdwhl_par;

    nb_shift = (SInt8)17;

    /* [-200;200]BIN17 * [1;10 000]BIN0 */
    vsco_temp = DDS_M_DYNAMIC_MULT_S32(vsco_temp,
                                        (SInt32)vsctl_mveh_par,
                                        &nb_shift);

    /* [-2 000000;2 000000]BIN17 reduce to [-16383;16383]BIN17 */
    vsco_temp = DDS_M_RESTORE_BINPOINT_SINT32(vsco_temp, (SInt8)((SInt32)nb_shift - (SInt32)17));

    /* [-16000;16000]BIN17 */
    vsctl_tqwhlpotmaxreqraw_temp = DDS_M_SATURATION_V2(vsco_temp,
                                                       (SInt32)vsctl_tqwhlptpotmin_par * BIN16,
                                                       (SInt32)vsctl_tqwhlptpotmax_par * BIN16);

    /* Calculation of vsctl_tqwhlpot_rsvlothd_temp and vsctl_tqwhlpot_rsvhithd_temp done with VSCO_Vsctl_Tqwhlrsv_Hys_Calc */
    /* during VSCO_F62323_Min_Whl_Torq_Pot_Cons */

    vsco_hyslo = (UInt32)DDS_M_MAX(vsctl_tqwhlpot_rsvlothd_temp, 0);
    vsco_hyshi = (UInt32)DDS_M_MAX(vsctl_tqwhlpot_rsvhithd_temp, 0);

    vsco_out_hyst_1 = DDS_M_FILTER_HYST_S32(&vsco_max_1_filter_hyst_s32,
                                            vsctl_tqwhlpotmaxreqraw_temp,
                                            vsco_hyslo,
                                            vsco_hyshi,
                                            VSCtl_bAcvRsv_tqWhlMax);

    vsco_out_hyst_2 = DDS_M_FILTER_HYST_S32(&vsco_max_2_filter_hyst_s32,
                                            vsctl_tqwhlpotmaxreqraw_temp,
                                            vsco_hyshi,
                                            vsco_hyslo,
                                            VSCtl_bAcvRsv_tqWhlMax);

    switch((UInt32)vsctl_stctl_tqwhlpotmax_par)
    {
        case(VSCO_POT_CONTROLE):

            VSCtl_tqWhlPotMaxReqRaw = (SInt16)(vsctl_tqwhlpotmaxreqraw_temp / BIN16);           /* [-16000;16000]BIN1 */

            *vsctl_tqwhlpotmaxrsvlothd_ptr = (SInt16)(vsctl_tqwhlpot_rsvlothd_temp / BIN16);    /* [-16000;16000]BIN1 */
            *vsctl_tqwhlpotmaxrsvhithd_ptr = (SInt16)(vsctl_tqwhlpot_rsvhithd_temp / BIN16);    /* [-16000;16000]BIN1 */

            if((SInt32)0 < (SInt32)vsctl_tqwhlpotmaxreq_prev)
            {
                VSCtl_sgnTqWhlPotMax = VSCO_WHEEL_TORQUE_POT_POSITIF;
                vsco_input_bary = vsco_out_hyst_1;
            }
            else
            {
                VSCtl_sgnTqWhlPotMax = VSCO_WHEEL_TORQUE_POT_NEGATIF;
                vsco_input_bary = vsco_out_hyst_2;
            }

            if((UInt32)DDS_TRUE == (UInt32)vsctl_bhld_avehpotreq_cpy)
            {
                vsco_temp_2 = vsctl_tqwhlpotmaxreq_prev;
            }
            else
            {
                vsco_temp_2 = (SInt16)(DDS_M_BARY_FILTER_S32(vsco_input_bary,
                                                             16000 * BIN17,
                                                             VSCtl_rCtlTqWhlPotMax,     /* [0;100]BIN4 */
                                                             (UInt16)(100 * BIN4)) / BIN16);
            }

            *vsctl_tqwhlpotmaxreq_ptr = vsco_temp_2;
            break;
        case(VSCO_POT_ARRET):
        default:
            *vsctl_tqwhlpotmaxrsvlothd_ptr =  VSCO_TORQUE_CONS_0_BIN1;
            *vsctl_tqwhlpotmaxrsvhithd_ptr =  VSCO_TORQUE_CONS_0_BIN1;
            VSCtl_tqWhlPotMaxReqRaw = VSCO_TORQUE_CONS_16000_BIN1_POS;
            VSCtl_sgnTqWhlPotMax = VSCO_WHEEL_TORQUE_POT_POSITIF;
            *vsctl_tqwhlpotmaxreq_ptr = VSCO_TORQUE_CONS_16000_BIN1_POS;
            break;
        }
}

/*******************************************************************************
*
* Function Name : VSCO_F62224_Max_Wheel_Torque_Gear_Chgt_Conf_Time_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62224_Max_Wheel_Torque_Gear_Chgt_Conf_Time_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                                    UInt16 vsctl_ticfmsupvslimreq_par,
                                                                                    UInt16 vsctl_ticfmsdwnvslimreq_par,
                                                                                    UInt16 vsctl_ticfmsupvsmaxreq_par,
                                                                                    UInt16 vsctl_ticfmsdwnvsmaxreq_par,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsuptqmaxreq_ptr,
                                                                         CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_ticfmsdwntqmaxreq_ptr)

{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.47.0 */

    if(VSCO_POT_CONTROLE == (UInt32)vsctl_stctl_tqwhlpotmax_par)
    {
        *vsctl_ticfmsuptqmaxreq_ptr = (UInt16)DDS_M_MAX((SInt32)vsctl_ticfmsupvslimreq_par,(SInt32)vsctl_ticfmsupvsmaxreq_par);
        *vsctl_ticfmsdwntqmaxreq_ptr = (UInt16)DDS_M_MAX((SInt32)vsctl_ticfmsdwnvslimreq_par,(SInt32)vsctl_ticfmsdwnvsmaxreq_par);

    }
    else
    {
        *vsctl_ticfmsuptqmaxreq_ptr = VSCO_WHEEL_TORQUE_POT_0_DEC2;
        *vsctl_ticfmsdwntqmaxreq_ptr = VSCO_WHEEL_TORQUE_POT_0_DEC2;
    }
}


/*******************************************************************************
*
* Function Name : VSCO_F62231_Wheel_Torque_Pot_Ctrl_Mode_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62231_Wheel_Torque_Pot_Ctrl_Mode_Deter(UInt8  vsctl_stctl_tqwhlpotmax_par,
                                                                          UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                          CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stctl_tqwhlpot_ptr)
{
    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.49.0 */

    /* MODE_CONTROLE_POTENTIEL_COUPLE_ROUE */
    switch(vsctl_stctl_tqwhlpot_local)
    {
        case(VSCO_ARRET):
            if(((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_CONTROLE) ||
               ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_CONTROLE))
            {
                vsctl_stctl_tqwhlpot_local = VSCO_CONTROLE;
            }
        break;

        case(VSCO_CONTROLE):
            if(((UInt32)vsctl_stctl_tqwhlpotmin_par == VSCO_ARRET)  &&
               ((UInt32)vsctl_stctl_tqwhlpotmax_par == VSCO_ARRET))
            {
                vsctl_stctl_tqwhlpot_local = VSCO_ARRET;
            }
        break;

        default:
            vsctl_stctl_tqwhlpot_local = VSCO_ARRET;
        break;
    }

    *vsctl_stctl_tqwhlpot_ptr = (UInt8)vsctl_stctl_tqwhlpot_local;
}




/*******************************************************************************
*
* Function Name : VSCO_F62232_Wheel_Torque_Pot_Cons_Deter
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSCO_F62232_Wheel_Torque_Pot_Cons_Deter(UInt8  vsctl_stctl_tqwhlpot_par,
                                                                     SInt16 vsctl_tqwhlpotminreq_par,
                                                                     SInt16 vsctl_tqwhlpotmaxreq_par,
                                                                     UInt8  vsctl_stctl_tqwhlpotmin_par,
                                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqwhlpotreq_ptr)
{
    SInt16 vsco_temp;

    /* SSTG_REQ_TAG: CSMT_CGMT08_2273.FR.50.0 */

    if(VSCO_CONTROLE == (UInt32)vsctl_stctl_tqwhlpot_par)
    {
        if(VSCO_POT_CONTROLE == (UInt32)vsctl_stctl_tqwhlpotmin_par)
        {
            vsco_temp = vsctl_tqwhlpotminreq_par;
        }
        else
        {
            vsco_temp = VSCO_TORQUE_CONS_16000_BIN1_POS;
        }

        *vsctl_tqwhlpotreq_ptr = (SInt16)DDS_M_MIN((SInt32)vsco_temp,(SInt32)vsctl_tqwhlpotmaxreq_par);
    }
    else
    {
        *vsctl_tqwhlpotreq_ptr = VSCO_TORQUE_CONS_0_BIN1;
    }

}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSCO_Whl_Tq_Pot_Cons_Kick_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSCO_Whl_Tq_Pot_Cons_Kick_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinReq_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxReq_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvLoThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMinRsvHiThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvLoThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotMaxRsvHiThd_swc_out, /* BIN1 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMaxReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSdwnTqMinReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMaxReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_tiCfmSupTqMinReq_swc_out, /* DEC2 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPot_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMax_swc_out,
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stCtl_tqWhlPotMin_swc_out,
                                                     CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqWhlPotReq_swc_out, /* BIN1 */
                                                     CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bKdAuth_swc_out)
{
    /* VSCO_F622_Wheel_Torque_Pot_Cons_Deter */
    /* VSCO_F6221_Min_Wheel_Torque_Pot_Cons_Deter */
    /* VSCO_F62211_Min_Wheel_Torque_Pot_Ctrl_Mode_Deter */
    *VSCtl_stCtl_tqWhlPotMin_swc_out    = (UInt8)VSCO_POT_ARRET;
    VSCtl_bAcvRsv_tqWhlMin              = DDS_FALSE;

    vsco_f62211_min_mode_controle_potentiel_couple_roue = (UInt8)VSCO_ARRET;
    vsctl_stctl_tqwhlpotmin_local       = VSCO_POT_ARRET;

    /* VSCO_F62212_Min_Wheel_Torque_Pot_App_Rate_Deter */
    VSCtl_rCtlTqWhlPotMin = VSCO_WHEEL_TORQUE_POT_0_BIN4;



    /* VSCO_F62213_Min_Wheel_Torque_Pot_Cons_Deter */
    *VSCtl_tqWhlPotMinReq_swc_out       = VSCO_TORQUE_CONS_16000_BIN1_NEG;
    *VSCtl_tqWhlPotMinRsvLoThd_swc_out  = VSCO_TORQUE_CONS_0_BIN1;
    *VSCtl_tqWhlPotMinRsvHiThd_swc_out  = VSCO_TORQUE_CONS_0_BIN1;
    VSCtl_tqWhlPotMinReqRaw = VSCO_TORQUE_CONS_16000_BIN1_NEG;
    VSCtl_sgnTqWhlPotMin    = VSCO_WHEEL_TORQUE_POT_POSITIF;

    DDS_M_FILTER_HYST_S32_INIT(&vsco_f62213_min_1_filter_hyst_s32, 0);
    DDS_M_FILTER_HYST_S32_INIT(&vsco_f62213_min_2_filter_hyst_s32, 0);

    DDS_M_FILTER_HYST_S32_INIT(&vsco_max_1_filter_hyst_s32, 0);
    DDS_M_FILTER_HYST_S32_INIT(&vsco_max_2_filter_hyst_s32, 0);


    /* VSCO_F62214_Min_Wheel_Torque_Gear_Chgt_Conf_Time_Deter */
    *VSCtl_tiCfmSupTqMinReq_swc_out     = VSCO_WHEEL_TORQUE_POT_0_DEC2;
    *VSCtl_tiCfmSdwnTqMinReq_swc_out    = VSCO_WHEEL_TORQUE_POT_0_DEC2;


    /* VSCO_F6222_Max_Wheel_Torque_Pot_Cons_Deter */
    /* VSCO_F62221_Max_Wheel_Torque_Pot_Ctrl_Mode_Deter */
    *VSCtl_stCtl_tqWhlPotMax_swc_out    = (UInt8)VSCO_POT_ARRET;
    VSCtl_bAcvRsv_tqWhlMax              = DDS_FALSE;
    vsco_f62221_max_mode_controle_potentiel_couple_roue = (UInt8)VSCO_ARRET;
    vsctl_stctl_tqwhlpotmax_local       = VSCO_POT_ARRET;

    /* VSCO_F62222_Max_Wheel_Torque_Pot_App_Rate_Deter */
    VSCtl_rCtlTqWhlPotMax = VSCO_WHEEL_TORQUE_POT_0_BIN4;

    /* VSCO_F62223_Max_Wheel_Torque_Pot_Cons_Deter */
    *VSCtl_tqWhlPotMaxReq_swc_out       = VSCO_TORQUE_CONS_16000_BIN1_POS;
    *VSCtl_tqWhlPotMaxRsvLoThd_swc_out  = VSCO_TORQUE_CONS_0_BIN1;
    *VSCtl_tqWhlPotMaxRsvHiThd_swc_out  = VSCO_TORQUE_CONS_0_BIN1;
    VSCtl_tqWhlPotMaxReqRaw = VSCO_TORQUE_CONS_16000_BIN1_POS;
    VSCtl_sgnTqWhlPotMax    = VSCO_WHEEL_TORQUE_POT_POSITIF;

    /* VSCO_F62224_Max_Wheel_Torque_Gear_Chgt_Conf_Time_Deter */
    *VSCtl_tiCfmSupTqMaxReq_swc_out     = VSCO_WHEEL_TORQUE_POT_0_DEC2;
    *VSCtl_tiCfmSdwnTqMaxReq_swc_out    = VSCO_WHEEL_TORQUE_POT_0_DEC2;


    /* VSCO_F6223_Wheel_Torque_Pot_Cons_Deter */
    /* VSCO_F62231_Wheel_Torque_Pot_Ctrl_Mode_Deter */
    *VSCtl_stCtl_tqWhlPot_swc_out       = (UInt8)VSCO_ARRET;
    vsctl_stctl_tqwhlpot_local          = VSCO_ARRET;


    /* VSCO_F62232_Wheel_Torque_Pot_Cons_Deter */
    *VSCtl_tqWhlPotReq_swc_out          = VSCO_TORQUE_CONS_16000_BIN1_NEG;


    /* VSCO_F623_Kickdown_Auth_Deter */
    *VSCtl_bKdAuth_swc_out          = DDS_FALSE;
    vsctl_bkdauth_local             = DDS_FALSE;
    vsco_f623_autorisation_kick_down = VSCO_F623_INIT;

    VSCtl_tiKdAuth  = VSCtl_tiTol_bKdAuthVSLim_C;

    vsctl_tqwhlpotminreq_prev = *VSCtl_tqWhlPotMinReq_swc_out;
    vsctl_tqwhlpotmaxreq_prev = *VSCtl_tqWhlPotMaxReq_swc_out;
    vsctl_tqwhlpotminrsvlothd_prev = *VSCtl_tqWhlPotMinRsvLoThd_swc_out;
    vsctl_tqwhlpotminrsvhithd_prev = *VSCtl_tqWhlPotMinRsvHiThd_swc_out;
    vsctl_tqwhlpotmaxrsvlothd_prev = *VSCtl_tqWhlPotMaxRsvLoThd_swc_out;
    vsctl_tqwhlpotmaxrsvhithd_prev = *VSCtl_tqWhlPotMaxRsvHiThd_swc_out;
    vsctl_ticfmsdwntqmaxreq_prev = *VSCtl_tiCfmSdwnTqMaxReq_swc_out;
    vsctl_ticfmsdwntqminreq_prev = *VSCtl_tiCfmSdwnTqMinReq_swc_out;
    vsctl_ticfmsuptqmaxreq_prev = *VSCtl_tiCfmSupTqMaxReq_swc_out;
    vsctl_ticfmsuptqminreq_prev = *VSCtl_tiCfmSupTqMinReq_swc_out;
    vsctl_stctl_tqwhlpot_prev = *VSCtl_stCtl_tqWhlPot_swc_out;
    vsctl_stctl_tqwhlpotmax_prev = *VSCtl_stCtl_tqWhlPotMax_swc_out;
    vsctl_stctl_tqwhlpotmin_prev = *VSCtl_stCtl_tqWhlPotMin_swc_out;
    vsctl_tqwhlpotreq_prev = *VSCtl_tqWhlPotReq_swc_out;
}

#define VSCO_STOP_SEC_CODE
#include "VSCo_MemMap.h"

