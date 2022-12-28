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
* Ref X:\integration_view_00PSASWC_D520D01\blois_psa_sstg\Software\Appli\VSLim\src\VSLIM_Det_State_Diag_Mnt.c
* Version int :/main/L02_01/1 Date: 6/1/2012 15 h 3 m User:esnault 
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L02_010_IMPL2
*    comments :for VSLim 12.0: spec update
* Version dev :\main\branch_morisseau_vslim_euro6\2 Date: 28/11/2011 10 h 12 m User:morisseau 
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L02_010_IMPL2
*    comments :for VSLim 12.0: spec update
* Version dev :\main\branch_morisseau_vslim_euro6\1 Date: 15/11/2011 17 h 26 m User:morisseau
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L02_010_IMPL1
*    comments :for VSLim 12.0: spec update
* Version int :/main/L01_01/4 Date: 15/3/2011 11 h 16 m User:esnault
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1_D
*    comments :for VSLim 10.2. correction after TU &  ALTIS 1548113 / FDS A0201082
* Version dev :\main\branch_veillard_vslim\1 Date: 14/3/2011 16 h 45 m User:veillard
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1_D
*    comments :for VSLim 10.2. correction after TU &  ALTIS 1548113 / FDS A0201082
* Version int :/main/L01_01/3 Date: 3/2/2011 15 h 13 m User:esnault
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1_D
*    comments :for VSLim 10.1. correction following remark tracking sheet
* Version dev :\main\branch_demezil_vslim\1 Date: 3/2/2011 14 h 48 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1_D
*    comments :for VSLim 10.1. correction following remark tracking sheet
* Version int :/main/L01_01/2 Date: 25/1/2011 14 h 24 m User:esnault
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0 : correction following TU report
*    comments :for VSLim 10.0 : correction following TU report
* Version dev :\main\branch_demezil_vslim\5 Date: 20/1/2011 9 h 56 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0 : correction following TU report
* Version dev :\main\branch_demezil_vslim\4 Date: 20/1/2011 9 h 51 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0
* Version dev :\main\branch_demezil_vslim\3 Date: 17/1/2011 12 h 14 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0
*    comments :FOR TESTOR : DO NOT TAKE ACCOUNT OF THIS VERSION
* Version dev :\main\branch_demezil_vslim\2 Date: 17/1/2011 10 h 7 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0
*    comments :FOR TESTOR : DO NOT TAKE ACCOUNT OF THIS VERSION
* Version dev :\main\branch_demezil_vslim\1 Date: 22/12/2010 15 h 2 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0
* Version dev :\main\branch_demezil\1 Date: 22/12/2010 14 h 53 m User:demezil
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :for VSLim 10.0
* Version dev :\main\branch_veillard_vslim\3 Date: 17/12/2010 14 h 43 m User:veillard
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\2 Date: 17/12/2010 10 h 5 m User:veillard
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\1 Date: 17/12/2010 9 h 39 m User:veillard
*    TWK_model:VSLIM_Det_State_Diag_Mnt_L01_010_IMPL1
*    comments :For VSLim 10.0
* Version dev :\main\branch_veillard_vslim\1 Date: 15/12/2010 17 h 58 m User:morisseau
*    TWK_model:NO_MODEL
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

/* 16-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"
extern VAR(SInt16, AUTOMATIC) VSCtl_jrkVehVSLimReq; /* BIN7 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"

/* 8-bits variables definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_stMonVSLim;
extern VAR(UInt8, AUTOMATIC) VSCtl_bInhVSLimReq;
extern VAR(UInt8, AUTOMATIC) VSCtl_bDrvOvrdVSLim;
extern VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_Ini; /* BIN0 */
extern VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_pt;
extern VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_Brk;
extern VAR(UInt8, AUTOMATIC) VSCtl_stDeacVSLimReq_Fct; /* BIN0 */
#define VSLIM_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"



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

/* 32-bits scalar calibration definition */
#define VSLIM_START_SEC_CALIB_32BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_stEnaDeacVSLimReqno2_C = (CONST(UInt32, AUTOMATIC))(8552383 * BIN0);
#define VSLIM_STOP_SEC_CALIB_32BIT
#include "VSLim_MemMap.h"

/* 16-bits scalar calibration definition */
#define VSLIM_START_SEC_CALIB_16BIT
#include "VSLim_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSLimReq1_C = (CONST(UInt16, AUTOMATIC))(0 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSLimReq2_C = (CONST(UInt16, AUTOMATIC))(0 * BIN0);
#define VSLIM_STOP_SEC_CALIB_16BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define VSLIM_START_SEC_VAR_32BIT
#include "VSLim_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) vsctl_dstvehtotmes_deacvslim_loc;
STATIC VAR(UInt32, AUTOMATIC) vsctl_stdeacvslimreq_no1_loc;
STATIC VAR(UInt32, AUTOMATIC) vsctl_stdeacvslimreq_no2_loc;
#define VSLIM_STOP_SEC_VAR_32BIT
#include "VSLim_MemMap.h"

/* 16-bits variable definition */
#define VSLIM_START_SEC_VAR_16BIT
#include "VSLim_MemMap.h"
STATIC VAR(SInt16, AUTOMATIC) vsctl_aveh_deacvslim_loc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_avehvslimreq_deacvslim_loc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkveh_deacvslim_loc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_jrkvehreqdeacvslim_loc;
STATIC VAR(UInt16, AUTOMATIC) vsctl_raccp_deacvslim_loc;
STATIC VAR(SInt16, AUTOMATIC) vsctl_rslop_deacvslim_loc;
STATIC VAR(UInt16, AUTOMATIC) vsctl_spdveh_deacvslim_loc;
#define VSLIM_STOP_SEC_VAR_16BIT
#include "VSLim_MemMap.h"

/* 8-bits variable definition */
#define VSLIM_START_SEC_VAR_8BIT
#include "VSLim_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsctl_bdrvovrdvslim_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_binhvslimreq_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_brec_stdeacvslimreq_loc;
STATIC VAR(SInt8, AUTOMATIC) vsctl_nogearegd_deacvslim_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_posngbxdeacvslim_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_spdvehreqdeacvslim_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stmonvslim_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_strec_stdeacvslimreq1_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_strec_stdeacvslimreq2_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvslim_deacvslim_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvslimextd_dly;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvslimextd_loc;
STATIC VAR(UInt8, AUTOMATIC) vsctl_stvslimprev_deacvslim_loc;
#define VSLIM_STOP_SEC_VAR_8BIT
#include "VSLim_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSLimReq1;
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_tiHld_stDeacVSLimReq2;
#define VSLIM_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSLim_MemMap.h"

/* 8-bits variable definition */
#define VSLIM_START_SEC_INTERNAL_VAR_8BIT
#include "VSLim_MemMap.h"
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bDeacVSLimHab;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bEnaDeacVSLimReq_no2;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_bRec_stDeacVSLimReq;
_DDS_STATIC_ VAR(UInt8, AUTOMATIC) VSCtl_stVSLimPrev;
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

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

STATIC FUNC(void, AUTOMATIC) VSLIM_F413_Determiner_Etat_Fonctionnement(
                                               UInt8 ext_stacvregvsctlreq_par,
                                               UInt8 ext_stmodregvsctlreq_par,
                                               UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslimextd_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F414_Determiner_Diagnostic_Fonctionnel(
                                               UInt8 ext_stacvregvsctlreq_par,
                                               UInt8 ext_stmodregvsctlreq_par,
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdgovslimbody_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bmonrunvslimbody_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4141_Determiner_Diagnostic_Fonctionnel_Habitacle(
                                               UInt8 ext_stacvregvsctlreq_par,
                                               UInt8 ext_stmodregvsctlreq_par,
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdgovslimbody_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bmonrunvslimbody_ptr );

STATIC FUNC(void, AUTOMATIC) VSLIM_F415_Determiner_Conditions_Maintenance(
                                               UInt16 accp_raccp_par, /* BIN7 */
                                               UInt8 afts_brst_stdeacvslimreq1_par,
                                               UInt8 afts_brst_stdeacvslimreq2_par,
                                               UInt32 ext_dstvehtotmes_par, /* BIN0 */
                                               SInt8 copt_noegdgearcordit_par,
                                               UInt8 copt_posnlev_par,
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               SInt16 vsctl_aveh_par, /* BIN10 */
                                               SInt16 vsctl_avehvslimreq_par, /* BIN10 */
                                               SInt16 vsctl_jrkveh_par, /* BIN7 */
                                               SInt16 vsctl_rslop_par, /* BIN7 */
                                               UInt16 vsctl_spdveh_par, /* BIN7 */
                                               UInt8 vsctl_stdeacvsctlinfo_par, /* BIN0 */
                                               UInt8 vsctl_stvslimextd_par,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aveh_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_dstvehtotmes_deacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkvehreqdeacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) vsctl_nogearegd_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_posngbxdeacvslim_ptr,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_raccp_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_rslop_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_spdvehreqdeacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no1_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no2_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq1_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq2_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslimprev_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslim_deacvslim_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4151_Determiner_Conditions_Maintenance_Lvv(
                                               UInt8 vsctl_stdeacvsctlinfo_par, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no1_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no2_ptr /* BIN0 */);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4152_Determiner_Conditions_Capture_Maintenance_Lvv(
                                               UInt8 vsctl_stvslimextd_par,
                                               UInt8 afts_brst_stdeacvslimreq1_par,
                                               UInt8 afts_brst_stdeacvslimreq2_par,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq1_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq2_ptr);

STATIC FUNC(void, AUTOMATIC) VSLIM_F4153_Determiner_Contexte_Maintenance_Lvv(
                                               UInt8 vsctl_stvslimextd_par,
                                               UInt32 ext_dstvehtotmes_par, /* BIN0 */
                                               SInt16 vsctl_aveh_par, /* BIN10 */
                                               UInt16 vsctl_spdveh_par, /* BIN7 */
                                               SInt16 vsctl_jrkveh_par, /* BIN7 */
                                               SInt16 vsctl_rslop_par, /* BIN7 */
                                               UInt16 accp_raccp_par, /* BIN7 */
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               SInt16 vsctl_avehvslimreq_par, /* BIN10 */
                                               SInt8 copt_noegdgearcordit_par,
                                               UInt8 copt_posnlev_par,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aveh_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_dstvehtotmes_deacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkvehreqdeacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) vsctl_nogearegd_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_posngbxdeacvslim_ptr,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_raccp_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_rslop_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_spdvehreqdeacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslimprev_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslim_deacvslim_ptr);

/*******************************************************************************
*
* Function Name : VSLIM_Det_State_Diag_Mnt
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Det_State_Diag_Mnt(UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                               UInt8 Afts_bRst_stDeacVSLimReq1_swc_in,
                                               UInt8 Afts_bRst_stDeacVSLimReq2_swc_in,
                                               UInt32 Ext_dstVehTotMes_swc_in, /* BIN0 */
                                               SInt8 CoPt_noEgdGearCordIt_swc_in,
                                               UInt8 CoPt_posnLev_swc_in,
                                               UInt8 Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                               UInt8 Ext_stAcvRegVSCtlReq_swc_in,
                                               UInt8 Ext_stModRegVSCtlReq_swc_in,
                                               SInt16 VSCtl_aVeh_swc_in, /* BIN10 */
                                               SInt16 VSCtl_aVehVSLimReq_swc_in, /* BIN10 */
                                               UInt8 VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                               SInt16 VSCtl_jrkVeh_swc_in, /* BIN7 */
                                               SInt16 VSCtl_rSlop_swc_in, /* BIN7 */
                                               UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                               UInt8 VSCtl_stDeacVSCtlInfo_swc_in, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_DeacVSLim_swc_out, /* BIN10 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSLim_swc_out, /* BIN10 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSLim_swc_out, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSLim_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSLim_swc_out,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSLim_swc_out, /* BIN0 */
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSLim_swc_out, /* BIN7 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no1_swc_out, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no2_swc_out, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq1_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq2_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimExtd_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimPrev_DeacVSLim_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLim_DeacVSLim_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLimBody_swc_out,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLimBody_swc_out )

{
    vsctl_binhvslimreq_loc = VSCtl_bInhVSLimReq;
    vsctl_stmonvslim_loc = VSCtl_stMonVSLim;
    vsctl_bdrvovrdvslim_loc = VSCtl_bDrvOvrdVSLim;

    VSLIM_F413_Determiner_Etat_Fonctionnement(Ext_stAcvRegVSCtlReq_swc_in,
                                              Ext_stModRegVSCtlReq_swc_in,
                                              VSCtl_bDrvOvrdVSLim_aVeh_swc_in,
                                              &vsctl_stvslimextd_loc);

    VSLIM_F414_Determiner_Diagnostic_Fonctionnel(Ext_stAcvRegVSCtlReq_swc_in,
                                                 Ext_stModRegVSCtlReq_swc_in,
                                                 Ext_spdVehVSLimReq_swc_in, /* BIN0 */
                                                 VSCtl_bDgoVSLimBody_swc_out,
                                                 VSCtl_bMonRunVSLimBody_swc_out );

    VSLIM_F415_Determiner_Conditions_Maintenance(AccP_rAccP_swc_in, /* BIN7 */
                                                 Afts_bRst_stDeacVSLimReq1_swc_in,
                                                 Afts_bRst_stDeacVSLimReq2_swc_in,
                                                 Ext_dstVehTotMes_swc_in, /* BIN0 */
                                                 CoPt_noEgdGearCordIt_swc_in,
                                                 CoPt_posnLev_swc_in,
                                                 Ext_spdVehVSLimReq_swc_in,
                                                 VSCtl_aVeh_swc_in, /* BIN10 */
                                                 VSCtl_aVehVSLimReq_swc_in, /* BIN10 */
                                                 VSCtl_jrkVeh_swc_in, /* BIN7 */
                                                 VSCtl_rSlop_swc_in, /* BIN7 */
                                                 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                 VSCtl_stDeacVSCtlInfo_swc_in, /* BIN0 */
                                                 vsctl_stvslimextd_loc,
                                                 VSCtl_aVehVSLimReq_DeacVSLim_swc_out, /* BIN10 */
                                                 VSCtl_aVeh_DeacVSLim_swc_out, /* BIN10 */
                                                 VSCtl_dstVehTotMes_DeacVSLim_swc_out, /* BIN0 */
                                                 VSCtl_jrkVehReqDeacVSLim_swc_out, /* BIN7 */
                                                 VSCtl_jrkVeh_DeacVSLim_swc_out, /* BIN7 */
                                                 VSCtl_noGearEgd_DeacVSLim_swc_out,
                                                 VSCtl_posnGBxDeacVSLim_swc_out,
                                                 VSCtl_rAccP_DeacVSLim_swc_out, /* BIN7 */
                                                 VSCtl_rSlop_DeacVSLim_swc_out, /* BIN7 */
                                                 VSCtl_spdVehReqDeacVSLim_swc_out, /* BIN0 */
                                                 VSCtl_spdVeh_DeacVSLim_swc_out, /* BIN7 */
                                                 VSCtl_stDeacVSLimReq_no1_swc_out, /* BIN0 */
                                                 VSCtl_stDeacVSLimReq_no2_swc_out, /* BIN0 */
                                                 VSCtl_stRec_stDeacVSLimReq1_swc_out,
                                                 VSCtl_stRec_stDeacVSLimReq2_swc_out,
                                                 VSCtl_stVSLimPrev_DeacVSLim_swc_out,
                                                 VSCtl_stVSLim_DeacVSLim_swc_out);

    *VSCtl_stVSLimExtd_swc_out = vsctl_stvslimextd_loc;
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
*
* Function Name : VSLIM_F413_Determiner_Etat_Fonctionnement
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F413_Determiner_Etat_Fonctionnement(
                                               UInt8 ext_stacvregvsctlreq_par,
                                               UInt8 ext_stmodregvsctlreq_par,
                                               UInt8 vsctl_bdrvovrdvslim_aveh_par,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslimextd_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.19.1 */

    switch((UInt32)vsctl_stvslimextd_loc)
    {
        case VSLIM_VSCTL_STVSLIMEXTD_ARRET:
            if((UInt32)vsctl_stmonvslim_loc != VSLIM_STMONVSLIM_ARRET)
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_INITIALISATION;
            }
            else
            {
                /* Nothing to do */
            }
            break;
        case VSLIM_VSCTL_STVSLIMEXTD_INITIALISATION:
            if((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_ARRET)
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
            }
            else
            {
                if((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_NOMINAL)
                {
                    vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_INHIBE;
                }
                else if(  ((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_DEFAUT_REV)
                        ||((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_DEFAUT_IRREV))
                {
                    vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_DEFAUT;
                }
                else
                {
                    /* Nothing to do */
                }
            }
            break;
        case VSLIM_VSCTL_STVSLIMEXTD_INHIBE:
            if((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_ARRET)
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
            }
            else
            {
                if(  ((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_NOMINAL)
                   &&((UInt32)ext_stacvregvsctlreq_par != VSLIM_STACVREGVSCTLREQ_REGULATION_LVV)
                   &&((UInt32)vsctl_binhvslimreq_loc == (UInt32)DDS_FALSE))
                {
                    vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ATTENTE;
                }
                else if(  ((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_DEFAUT_REV)
                        ||((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_DEFAUT_IRREV))
                {
                    vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_DEFAUT;
                }
                else
                {
                    /* Nothing to do */
                }
            }
            break;
        case VSLIM_VSCTL_STVSLIMEXTD_DEFAUT:
            if((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_ARRET)
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
            }
            else
            {
                if((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_NOMINAL)
                {
                    vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_INHIBE;
                }
                else
                {
                    /* Nothing to do */
                }
            }
            break;
        case VSLIM_VSCTL_STVSLIMEXTD_ATTENTE:
        case VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF:
        case VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF:
        case VSLIM_VSCTL_STVSLIMEXTD_REPRISE:
            if((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_ARRET)
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
            }
            else if(  ((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_INITIALISATION)
                    ||((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_VERIFICATION))
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_INITIALISATION;
            }
            else if(  ((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_NOMINAL)
                    &&((UInt32)vsctl_binhvslimreq_loc == (UInt32)DDS_TRUE))
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_INHIBE;
            }
            else if(  ((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_DEFAUT_REV)
                    ||((UInt32)vsctl_stmonvslim_loc == VSLIM_STMONVSLIM_DEFAUT_IRREV))
            {
                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_DEFAUT;
            }
            else
            {
                switch((UInt32)vsctl_stvslimextd_loc)
                {
                    case VSLIM_VSCTL_STVSLIMEXTD_ATTENTE:
                        if(  ((UInt32)ext_stmodregvsctlreq_par == VSLIM_STMODREGVSCTLREQ_REGULATION_LVV)
                           &&((UInt32)ext_stacvregvsctlreq_par == VSLIM_STACVREGVSCTLREQ_REGULATION_LVV))
                        {
                            if((UInt32)vsctl_bdrvovrdvslim_loc != (UInt32)DDS_FALSE)
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_REPRISE;
                            }
                            else
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF;
                            }
                        }
                        else
                        {
                            /* Nothing to do */
                        }
                        break;
                    case VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF:
                        if( ((UInt32)ext_stmodregvsctlreq_par != VSLIM_STMODREGVSCTLREQ_REGULATION_LVV) ||
                            ((UInt32)ext_stacvregvsctlreq_par != VSLIM_STACVREGVSCTLREQ_REGULATION_LVV) )
                        {
                            vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ATTENTE;
                        }
                        else
                        {
                            if((UInt32)vsctl_bdrvovrdvslim_loc == (UInt32)DDS_TRUE)
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_REPRISE;
                            }
                            else if((UInt32)vsctl_bdrvovrdvslim_aveh_par == (UInt32)DDS_FALSE)
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF;
                            }
                            else
                            {
                                /* Nothing to do */
                            }
                        }
                        break;
                    case VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF:
                        if( ((UInt32)ext_stmodregvsctlreq_par != VSLIM_STMODREGVSCTLREQ_REGULATION_LVV) ||
                            ((UInt32)ext_stacvregvsctlreq_par != VSLIM_STACVREGVSCTLREQ_REGULATION_LVV) )
                        {
                            vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ATTENTE;
                        }
                        else
                        {
                            if((UInt32)vsctl_bdrvovrdvslim_loc == (UInt32)DDS_TRUE)
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_REPRISE;
                            }
                            else if((UInt32)vsctl_bdrvovrdvslim_aveh_par == (UInt32)DDS_TRUE)
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF;
                            }
                            else
                            {
                                /* Nothing to do */
                            }
                        }
                        break;
                    case VSLIM_VSCTL_STVSLIMEXTD_REPRISE:
                        if( ((UInt32)ext_stmodregvsctlreq_par != VSLIM_STMODREGVSCTLREQ_REGULATION_LVV) ||
                            ((UInt32)ext_stacvregvsctlreq_par != VSLIM_STACVREGVSCTLREQ_REGULATION_LVV) )
                        {
                            vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ATTENTE;
                        }
                        else
                        {
                            if((UInt32)vsctl_bdrvovrdvslim_loc == (UInt32)DDS_FALSE)
                            {
                                vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF;
                            }
                            else
                            {
                                /* Nothing to do */
                            }
                        }
                        break;
                    default:
                        /* It is impossible to be in this case */
                        break;
                }
            }
            break;
        default:
            vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
            break;
    }

    *vsctl_stvslimextd_ptr = vsctl_stvslimextd_loc;
}

/*******************************************************************************
*
* Function Name : VSLIM_F414_Determiner_Diagnostic_Fonctionnel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F414_Determiner_Diagnostic_Fonctionnel(
                                               UInt8 ext_stacvregvsctlreq_par,
                                               UInt8 ext_stmodregvsctlreq_par,
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdgovslimbody_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bmonrunvslimbody_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.58.0 */
    VSLIM_F4141_Determiner_Diagnostic_Fonctionnel_Habitacle(
                                               ext_stacvregvsctlreq_par,
                                               ext_stmodregvsctlreq_par,
                                               ext_spdvehvslimreq_par, /* BIN0 */
                                               vsctl_bdgovslimbody_ptr,
                                               vsctl_bmonrunvslimbody_ptr);
}

/*******************************************************************************
*
* Function Name : VSLIM_F4141_Determiner_Diagnostic_Fonctionnel_Habitacle
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4141_Determiner_Diagnostic_Fonctionnel_Habitacle(
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                               UInt8 ext_stacvregvsctlreq_par,
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                               UInt8 ext_stmodregvsctlreq_par,
/* <PRQA_COMMENT><3206> Parameter is link to a terminator block </3206></PRQA_COMMENT> */
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bdgovslimbody_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_bmonrunvslimbody_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.59.0 */
    *vsctl_bdgovslimbody_ptr = DDS_FALSE;
    *vsctl_bmonrunvslimbody_ptr = DDS_FALSE;
    VSCtl_bDeacVSLimHab = DDS_FALSE;
}

/*******************************************************************************
*
* Function Name : VSLIM_F415_Determiner_Conditions_Maintenance
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F415_Determiner_Conditions_Maintenance(
                                               UInt16 accp_raccp_par, /* BIN7 */
                                               UInt8 afts_brst_stdeacvslimreq1_par,
                                               UInt8 afts_brst_stdeacvslimreq2_par,
                                               UInt32 ext_dstvehtotmes_par, /* BIN0 */
                                               SInt8 copt_noegdgearcordit_par,
                                               UInt8 copt_posnlev_par,
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               SInt16 vsctl_aveh_par, /* BIN10 */
                                               SInt16 vsctl_avehvslimreq_par, /* BIN10 */
                                               SInt16 vsctl_jrkveh_par, /* BIN7 */
                                               SInt16 vsctl_rslop_par, /* BIN7 */
                                               UInt16 vsctl_spdveh_par, /* BIN7 */
                                               UInt8 vsctl_stdeacvsctlinfo_par, /* BIN0 */
                                               UInt8 vsctl_stvslimextd_par,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aveh_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_dstvehtotmes_deacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkvehreqdeacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) vsctl_nogearegd_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_posngbxdeacvslim_ptr,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_raccp_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_rslop_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_spdvehreqdeacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no1_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no2_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq1_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq2_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslimprev_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslim_deacvslim_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.60.2 */
    VSLIM_F4151_Determiner_Conditions_Maintenance_Lvv(
                                               vsctl_stdeacvsctlinfo_par, /* BIN0 */
                                               vsctl_stdeacvslimreq_no1_ptr, /* BIN0 */
                                               vsctl_stdeacvslimreq_no2_ptr /* BIN0 */);

    VSLIM_F4152_Determiner_Conditions_Capture_Maintenance_Lvv(
                                               vsctl_stvslimextd_par,
                                               afts_brst_stdeacvslimreq1_par,
                                               afts_brst_stdeacvslimreq2_par,
                                               vsctl_strec_stdeacvslimreq1_ptr,
                                               vsctl_strec_stdeacvslimreq2_ptr);

    VSLIM_F4153_Determiner_Contexte_Maintenance_Lvv(
                                               vsctl_stvslimextd_par,
                                               ext_dstvehtotmes_par, /* BIN0 */
                                               vsctl_aveh_par, /* BIN10 */
                                               vsctl_spdveh_par, /* BIN7 */
                                               vsctl_jrkveh_par, /* BIN7 */
                                               vsctl_rslop_par, /* BIN7 */
                                               accp_raccp_par, /* BIN7 */
                                               ext_spdvehvslimreq_par, /* BIN0 */
                                               vsctl_avehvslimreq_par, /* BIN10 */
                                               copt_noegdgearcordit_par,
                                               copt_posnlev_par,
                                               vsctl_avehvslimreq_deacvslim_ptr, /* BIN10 */
                                               vsctl_aveh_deacvslim_ptr, /* BIN10 */
                                               vsctl_dstvehtotmes_deacvslim_ptr, /* BIN0 */
                                               vsctl_jrkvehreqdeacvslim_ptr, /* BIN7 */
                                               vsctl_jrkveh_deacvslim_ptr, /* BIN7 */
                                               vsctl_nogearegd_deacvslim_ptr,
                                               vsctl_posngbxdeacvslim_ptr,
                                               vsctl_raccp_deacvslim_ptr, /* BIN7 */
                                               vsctl_rslop_deacvslim_ptr, /* BIN7 */
                                               vsctl_spdvehreqdeacvslim_ptr, /* BIN0 */
                                               vsctl_spdveh_deacvslim_ptr, /* BIN7 */
                                               vsctl_stvslimprev_deacvslim_ptr,
                                               vsctl_stvslim_deacvslim_ptr);

}

/*******************************************************************************
*
* Function Name : VSLIM_F4151_Determiner_Conditions_Maintenance_Lvv
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4151_Determiner_Conditions_Maintenance_Lvv(
                                               UInt8 vsctl_stdeacvsctlinfo_par, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no1_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_stdeacvslimreq_no2_ptr /* BIN0 */)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.61.0 */
    UInt32 vslim_uvalue;
    UInt32 vslim_uvalue_2;

    if((UInt32)VSCtl_bDeacVSLimHab == (UInt32)DDS_TRUE)
    {
        vslim_uvalue = BIN23;
    }
    else
    {
        vslim_uvalue = 0;
    }

    vslim_uvalue = vslim_uvalue + (UInt32)vsctl_stdeacvsctlinfo_par;
    vslim_uvalue = vslim_uvalue + ((UInt32)VSCtl_stDeacVSLimReq_Ini * BIN6);
    vslim_uvalue = vslim_uvalue + ((UInt32)VSCtl_stDeacVSLimReq_pt * BIN13);
    vslim_uvalue = vslim_uvalue + ((UInt32)VSCtl_stDeacVSLimReq_Brk * BIN14);
    vslim_uvalue = vslim_uvalue + ((UInt32)VSCtl_stDeacVSLimReq_Fct * BIN15);

    vslim_uvalue_2 = (vslim_uvalue & VSCtl_stEnaDeacVSLimReqno2_C);

    if((UInt32)VSCtl_bRec_stDeacVSLimReq == (UInt32)DDS_TRUE)
    {
        /* Nothing to do */
    }
    else
    {
        vsctl_stdeacvslimreq_no1_loc = vslim_uvalue;
        vsctl_stdeacvslimreq_no2_loc = vslim_uvalue_2;
    }

    if(vslim_uvalue_2 > 0)
    {
        VSCtl_bEnaDeacVSLimReq_no2 = DDS_TRUE;
    }
    else
    {
        VSCtl_bEnaDeacVSLimReq_no2 = DDS_FALSE;
    }

    *vsctl_stdeacvslimreq_no1_ptr = vsctl_stdeacvslimreq_no1_loc;
    *vsctl_stdeacvslimreq_no2_ptr = vsctl_stdeacvslimreq_no2_loc;
}

/*******************************************************************************
*
* Function Name : VSLIM_F4152_Determiner_Conditions_Capture_Maintenance_Lvv
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4152_Determiner_Conditions_Capture_Maintenance_Lvv(
                                               UInt8 vsctl_stvslimextd_par,
                                               UInt8 afts_brst_stdeacvslimreq1_par,
                                               UInt8 afts_brst_stdeacvslimreq2_par,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq1_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_strec_stdeacvslimreq2_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.62.0 */

    /* STATEFLOW : CONDITION_CAPTURE_MAINTENANCE_LVV_no1 */
    if((UInt32)vsctl_strec_stdeacvslimreq1_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE)
    {
        if((UInt32)afts_brst_stdeacvslimreq1_par != (UInt32)DDS_FALSE)
        {
            vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES;
        }
        else if(  (  ((UInt32)VSCtl_stVSLimPrev == VSLIM_VSCTL_STVSLIMEXTD_ATTENTE)
                   &&((UInt32)vsctl_stvslimextd_par == VSLIM_VSCTL_STVSLIMEXTD_REPRISE))
                ||(  (  ((UInt32)VSCtl_stVSLimPrev == VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF)
                      ||((UInt32)VSCtl_stVSLimPrev == VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF))
                   &&((UInt32)vsctl_stvslimextd_par != VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF)
                   &&((UInt32)vsctl_stvslimextd_par != VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF)))
        {
            vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION;
            VSCtl_tiHld_stDeacVSLimReq1 = VSCtl_tiHld_stDeacVSLimReq1_C;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else if((UInt32)vsctl_strec_stdeacvslimreq1_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION)
    {
        if((UInt32)afts_brst_stdeacvslimreq1_par != (UInt32)DDS_FALSE)
        {
            vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES;
        }
        else if((UInt32)VSCtl_tiHld_stDeacVSLimReq1 == (UInt32)0)
        {
            vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
            VSCtl_tiHld_stDeacVSLimReq1 = VSCtl_tiHld_stDeacVSLimReq1_C;
        }
        else
        {
            VSCtl_tiHld_stDeacVSLimReq1 = (UInt16)DDS_M_POSITIVE_DECREMENT((UInt32)VSCtl_tiHld_stDeacVSLimReq1,1);  /* 1 * BIN0 */
        }
    }
    else if((UInt32)vsctl_strec_stdeacvslimreq1_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES)
    {
        if((UInt32)afts_brst_stdeacvslimreq1_par != (UInt32)DDS_TRUE)
        {
            vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
            VSCtl_tiHld_stDeacVSLimReq1 = VSCtl_tiHld_stDeacVSLimReq1_C;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    { /* Default case of Stateflow */
        vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
        VSCtl_tiHld_stDeacVSLimReq1 = VSCtl_tiHld_stDeacVSLimReq1_C;
    }

    /* STATEFLOW : CONDITION_CAPTURE_MAINTENANCE_LVV_no2 */
    if((UInt32)vsctl_strec_stdeacvslimreq2_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE)
    {
        if((UInt32)afts_brst_stdeacvslimreq2_par != (UInt32)DDS_FALSE)
        {
            vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES;
        }
        else if((  (  ((UInt32)VSCtl_stVSLimPrev==VSLIM_VSCTL_STVSLIMEXTD_ATTENTE)
                    &&((UInt32)vsctl_stvslimextd_par == VSLIM_VSCTL_STVSLIMEXTD_REPRISE))
                 ||(  (  ((UInt32)VSCtl_stVSLimPrev == VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF)
                       ||((UInt32)VSCtl_stVSLimPrev == VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF))
                    &&(  ((UInt32)vsctl_stvslimextd_par != VSLIM_VSCTL_STVSLIMEXTD_ACTIF_NON_EFFECTIF)
                       &&((UInt32)vsctl_stvslimextd_par != VSLIM_VSCTL_STVSLIMEXTD_ACTIF_EFFECTIF))))
                &&((UInt32)VSCtl_bEnaDeacVSLimReq_no2 == (UInt32)DDS_TRUE))
        {
            vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else if((UInt32)vsctl_strec_stdeacvslimreq2_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION)
    {
        if((UInt32)afts_brst_stdeacvslimreq2_par != (UInt32)DDS_FALSE)
        {
            vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES;
        }
        else if((UInt32)VSCtl_tiHld_stDeacVSLimReq2 == (UInt32)0)
        {
            vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
            VSCtl_tiHld_stDeacVSLimReq2 = VSCtl_tiHld_stDeacVSLimReq2_C;
        }
        else
        {
            VSCtl_tiHld_stDeacVSLimReq2 = (UInt16)((SInt32)VSCtl_tiHld_stDeacVSLimReq2 - 1);
        }
    }
    else if((UInt32)vsctl_strec_stdeacvslimreq2_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_EFFACEMENT_DES_MEMOIRES)
    {
        if((UInt32)afts_brst_stdeacvslimreq2_par != (UInt32)DDS_TRUE)
        {
            vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
            VSCtl_tiHld_stDeacVSLimReq2 = VSCtl_tiHld_stDeacVSLimReq2_C;
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    { /* Default case of Stateflow */
        vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
        VSCtl_tiHld_stDeacVSLimReq2 = VSCtl_tiHld_stDeacVSLimReq2_C;
    }

    /* CONDITION_CAPTURE_MAINTENANCE_LVV */
    if(  ((UInt32)vsctl_strec_stdeacvslimreq1_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION)
       ||((UInt32)vsctl_strec_stdeacvslimreq2_loc == VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_MEMORISATION))
    {
        VSCtl_bRec_stDeacVSLimReq = DDS_TRUE;
    }
    else
    {
        VSCtl_bRec_stDeacVSLimReq = DDS_FALSE;
    }

    /* MEMOIRES */
    VSCtl_stVSLimPrev = vsctl_stvslimextd_par;

    /* set output */
    *vsctl_strec_stdeacvslimreq1_ptr = vsctl_strec_stdeacvslimreq1_loc;
    *vsctl_strec_stdeacvslimreq2_ptr = vsctl_strec_stdeacvslimreq2_loc;
}

/*******************************************************************************
*
* Function Name : VSLIM_F4153_Determiner_Contexte_Maintenance_Lvv
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSLIM_F4153_Determiner_Contexte_Maintenance_Lvv(
                                               UInt8 vsctl_stvslimextd_par,
                                               UInt32 ext_dstvehtotmes_par, /* BIN0 */
                                               SInt16 vsctl_aveh_par, /* BIN10 */
                                               UInt16 vsctl_spdveh_par, /* BIN7 */
                                               SInt16 vsctl_jrkveh_par, /* BIN7 */
                                               SInt16 vsctl_rslop_par, /* BIN7 */
                                               UInt16 accp_raccp_par, /* BIN7 */
                                               UInt8 ext_spdvehvslimreq_par, /* BIN0 */
                                               SInt16 vsctl_avehvslimreq_par, /* BIN10 */
                                               SInt8 copt_noegdgearcordit_par,
                                               UInt8 copt_posnlev_par,
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_avehvslimreq_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_aveh_deacvslim_ptr, /* BIN10 */
                                               CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) vsctl_dstvehtotmes_deacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkvehreqdeacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_jrkveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) vsctl_nogearegd_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_posngbxdeacvslim_ptr,
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_raccp_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_rslop_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_spdvehreqdeacvslim_ptr, /* BIN0 */
                                               CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_spdveh_deacvslim_ptr, /* BIN7 */
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslimprev_deacvslim_ptr,
                                               CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) vsctl_stvslim_deacvslim_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_2271.FR.63.1 */

    if((UInt32)vsctl_brec_stdeacvslimreq_loc == (UInt32)DDS_TRUE)
    {
        /* Nothing to do */
    }
    else
    {
        vsctl_aveh_deacvslim_loc = vsctl_aveh_par;
        vsctl_avehvslimreq_deacvslim_loc = vsctl_avehvslimreq_par;
        vsctl_dstvehtotmes_deacvslim_loc = ext_dstvehtotmes_par;
        vsctl_jrkveh_deacvslim_loc = vsctl_jrkveh_par;
        vsctl_jrkvehreqdeacvslim_loc = VSCtl_jrkVehVSLimReq;
        vsctl_nogearegd_deacvslim_loc = copt_noegdgearcordit_par;
        vsctl_posngbxdeacvslim_loc = copt_posnlev_par;
        vsctl_raccp_deacvslim_loc = accp_raccp_par;
        vsctl_rslop_deacvslim_loc = vsctl_rslop_par;
        vsctl_spdveh_deacvslim_loc = vsctl_spdveh_par;
        vsctl_spdvehreqdeacvslim_loc = ext_spdvehvslimreq_par;
        vsctl_stvslim_deacvslim_loc = vsctl_stvslimextd_par;
        vsctl_stvslimprev_deacvslim_loc = vsctl_stvslimextd_dly;
    }

    *vsctl_aveh_deacvslim_ptr = vsctl_aveh_deacvslim_loc;
    *vsctl_avehvslimreq_deacvslim_ptr = vsctl_avehvslimreq_deacvslim_loc;
    *vsctl_dstvehtotmes_deacvslim_ptr = vsctl_dstvehtotmes_deacvslim_loc;
    *vsctl_jrkveh_deacvslim_ptr = vsctl_jrkveh_deacvslim_loc;
    *vsctl_jrkvehreqdeacvslim_ptr = vsctl_jrkvehreqdeacvslim_loc;
    *vsctl_nogearegd_deacvslim_ptr = vsctl_nogearegd_deacvslim_loc;
    *vsctl_posngbxdeacvslim_ptr = vsctl_posngbxdeacvslim_loc;
    *vsctl_raccp_deacvslim_ptr = vsctl_raccp_deacvslim_loc;
    *vsctl_rslop_deacvslim_ptr = vsctl_rslop_deacvslim_loc;
    *vsctl_spdveh_deacvslim_ptr = vsctl_spdveh_deacvslim_loc;
    *vsctl_spdvehreqdeacvslim_ptr = vsctl_spdvehreqdeacvslim_loc;
    *vsctl_stvslim_deacvslim_ptr = vsctl_stvslim_deacvslim_loc;
    *vsctl_stvslimprev_deacvslim_ptr = vsctl_stvslimprev_deacvslim_loc;

    vsctl_brec_stdeacvslimreq_loc = VSCtl_bRec_stDeacVSLimReq;
    vsctl_stvslimextd_dly = vsctl_stvslimextd_par;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSLIM_Det_State_Diag_Mnt_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSLIM_Det_State_Diag_Mnt_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimExtd_swc_out,
                                                    CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no1_swc_out, /* BIN0 */
                                                    CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_stDeacVSLimReq_no2_swc_out, /* BIN0 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq1_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stRec_stDeacVSLimReq2_swc_out,
                                                    CONSTP2VAR(UInt32, AUTOMATIC, AUTOMATIC) VSCtl_dstVehTotMes_DeacVSLim_swc_out, /* BIN0 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVeh_DeacVSLim_swc_out, /* BIN10 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_spdVeh_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVeh_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_rSlop_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rAccP_DeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLim_DeacVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_stVSLimPrev_DeacVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_spdVehReqDeacVSLim_swc_out, /* BIN0 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_aVehVSLimReq_DeacVSLim_swc_out, /* BIN10 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_jrkVehReqDeacVSLim_swc_out, /* BIN7 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_posnGBxDeacVSLim_swc_out,
                                                    CONSTP2VAR(SInt8, AUTOMATIC, AUTOMATIC) VSCtl_noGearEgd_DeacVSLim_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bMonRunVSLimBody_swc_out,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) VSCtl_bDgoVSLimBody_swc_out )
{
    /* ---- Init Outputs ---- */
    *VSCtl_aVehVSLimReq_DeacVSLim_swc_out = (SInt16)(10 * BIN10);
    *VSCtl_aVeh_DeacVSLim_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_dstVehTotMes_DeacVSLim_swc_out = (UInt32)(0 * BIN0);
    *VSCtl_jrkVehReqDeacVSLim_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_jrkVeh_DeacVSLim_swc_out = (SInt16)(0 * BIN10);
    *VSCtl_noGearEgd_DeacVSLim_swc_out = (SInt8)VSLIM_VSCTL_NOGEAREGD_DEACVSLIM_NEUTRE;
    *VSCtl_posnGBxDeacVSLim_swc_out = (UInt8)VSLIM_VSCTL_POSNGBXDEACVSLIM_NEUTRE;
    *VSCtl_rAccP_DeacVSLim_swc_out = (UInt16)(100 * BIN7);
    *VSCtl_rSlop_DeacVSLim_swc_out = (SInt16)(0 * BIN7);
    *VSCtl_spdVehReqDeacVSLim_swc_out = (UInt8)(0 * BIN0);
    *VSCtl_spdVeh_DeacVSLim_swc_out = (UInt16)(0 * BIN7);
    *VSCtl_stDeacVSLimReq_no1_swc_out = BIN24-1;
    *VSCtl_stDeacVSLimReq_no2_swc_out = BIN24-1;
    *VSCtl_stRec_stDeacVSLimReq1_swc_out = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
    *VSCtl_stRec_stDeacVSLimReq2_swc_out = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
    *VSCtl_stVSLimExtd_swc_out = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
    *VSCtl_stVSLimPrev_DeacVSLim_swc_out = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
    *VSCtl_stVSLim_DeacVSLim_swc_out = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;
    *VSCtl_bDgoVSLimBody_swc_out = DDS_FALSE;
    *VSCtl_bMonRunVSLimBody_swc_out = DDS_FALSE;

    /* ---- Init Global Datas ---- */
    VSCtl_bDeacVSLimHab = DDS_TRUE;
    VSCtl_bEnaDeacVSLimReq_no2 = DDS_FALSE;
    VSCtl_bRec_stDeacVSLimReq = DDS_FALSE;
    VSCtl_stVSLimPrev = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;

    vsctl_bdrvovrdvslim_loc = DDS_FALSE;
    vsctl_binhvslimreq_loc = DDS_TRUE;
    vsctl_stmonvslim_loc = (UInt8)VSLIM_STMONVSLIM_ARRET;

    /* ---- VSLIM_F413_Determiner_Etat_Fonctionnement ---- */
    vsctl_stvslimextd_loc = (UInt8)VSLIM_VSCTL_STVSLIMEXTD_ARRET;

    /* ---- VSLIM_F414_Determiner_Diagnostic_Fonctionnel ---- */

    /* ---- VSLIM_F4141_Determiner_Diagnostic_Fonctionnel_Habitacle ---- */

    /* ---- VSLIM_F415_Determiner_Conditions_Maintenance ---- */

    /* ---- VSLIM_F4151_Determiner_Conditions_Maintenance_Lvv ---- */
    vsctl_stdeacvslimreq_no1_loc = 0;
    vsctl_stdeacvslimreq_no2_loc = 0;

    /* ---- VSLIM_F4152_Determiner_Conditions_Capture_Maintenance_Lvv ---- */
    vsctl_strec_stdeacvslimreq1_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
    VSCtl_tiHld_stDeacVSLimReq1 = VSCtl_tiHld_stDeacVSLimReq1_C;
    vsctl_strec_stdeacvslimreq2_loc = (UInt8)VSLIM_VSCTL_STREC_STDEACVSLIMREQ1_ATTENTE;
    VSCtl_tiHld_stDeacVSLimReq2 = VSCtl_tiHld_stDeacVSLimReq2_C;

    /* ---- VSLIM_F4153_Determiner_Contexte_Maintenance_Lvv ---- */
    vsctl_brec_stdeacvslimreq_loc = DDS_FALSE;
    vsctl_aveh_deacvslim_loc = 0;
    vsctl_avehvslimreq_deacvslim_loc = 0;
    vsctl_jrkveh_deacvslim_loc = 0;
    vsctl_jrkvehreqdeacvslim_loc = 0;
    vsctl_rslop_deacvslim_loc = 0;
    vsctl_raccp_deacvslim_loc = 0;
    vsctl_spdveh_deacvslim_loc = 0;
    vsctl_nogearegd_deacvslim_loc = 0;
    vsctl_posngbxdeacvslim_loc = 0;
    vsctl_spdvehreqdeacvslim_loc = 0;
    vsctl_stvslim_deacvslim_loc = 0;
    vsctl_stvslimprev_deacvslim_loc = 0;
    vsctl_dstvehtotmes_deacvslim_loc = 0;
    vsctl_stvslimextd_dly = 0;
}



#define VSLIM_STOP_SEC_CODE
#include "VSLim_MemMap.h"

