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
* Ref X:\integration_view_00PSASWC_EA30D11\blois_psa_sstg\Software\Appli\CoClLASl\src\COCLLASL_Idl_Coord_Lim_Sync.c
* Version int :/main/C00_00/1 Date: 21/1/2014 11 h 58 m User:groult 
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_C00_000_IMPL1
*    comments :dev CoClLASl 13.0
* Version dev :\main\branch_lemort\1 Date: 17/12/2013 15 h 33 m User:lemort 
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_C00_000_IMPL1
*    comments :dev CoClLASl 13.0
* Version int :/main/L03_02/1 Date: 11/4/2012 9 h 47 m User:esnault
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_020_IMPL1
*    comments :for CoClLASl 12.0
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 16/3/2012 8 h 38 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_020_IMPL1
*    comments :for CoClLASl 12.0
* Version int :/main/L03_01/1 Date: 25/2/2011 11 h 30 m User:esnault
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\6 Date: 9/2/2011 16 h 56 m User:halouane
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\5 Date: 9/2/2011 16 h 37 m User:halouane
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL2
*    comments :update for TU
* Version dev :\main\branch_halouane_CoClLASl_dev\4 Date: 19/1/2011 14 h 44 m User:halouane
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane_CoClLASl_dev\3 Date: 19/1/2011 14 h 32 m User:halouane
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL1
*    comments :update for 11.0
* Version dev :\main\branch_halouane_CoClLASl_dev\2 Date: 19/1/2011 14 h 26 m User:halouane
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL1
*    comments :update for CoClLASl11.0.
* Version dev :\main\branch_halouane_CoClLASl_dev\1 Date: 19/1/2011 9 h 56 m User:halouane
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L03_010_IMPL1
*    comments :update for CoClLASl11.0.
* Version int :/main/L02_01/1 Date: 4/10/2010 9 h 42 m User:meme
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 1/10/2010 12 h 31 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L02_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 30/9/2010 14 h 5 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L02_010_IMPL1
*    comments :for CoClLASl
* Version int :/main/L01_01/1 Date: 1/9/2010 17 h 57 m User:esnault
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\6 Date: 31/8/2010 17 h 43 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
*    comments :dev CoClLASl e6
* Version dev :\main\branch_morisseau_cocllasl_view\5 Date: 29/7/2010 17 h 34 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
*    comments :validation done
* Version dev :\main\branch_morisseau_cocllasl_view\4 Date: 22/7/2010 11 h 35 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
*    comments :for CoClLASl
* Version dev :\main\branch_morisseau_cocllasl_view\3 Date: 21/7/2010 17 h 43 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
*    comments :for CoClASl
* Version dev :\main\branch_morisseau_cocllasl_view\2 Date: 20/7/2010 16 h 22 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
*    comments :for CoClLASl 10.0
* Version dev :\main\branch_morisseau_cocllasl_view\1 Date: 19/7/2010 16 h 40 m User:morisseau
*    TWK_model:COCLLASL_Idl_Coord_Lim_Sync_L01_010_IMPL1
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
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nIdlOff_C = (UInt16)(200 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nIdlOn_C = (UInt16)(100 * BIN0);
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_rAccPThdPedPrss_C = (UInt16)(2 * BIN7);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqHystTqSmkDeac_C = (SInt16)(5 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqMaxProtDfw_C = (SInt16)(2000 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsThdHiIdlAcv_C = (SInt16)(10 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) TqSys_tqOfsThdLoIdlAcv_C = (SInt16)(5 * BIN4);
#define COCLLASL_STOP_SEC_CALIB_16BIT
#include "CoClLASl_MemMap.h"

/* 8-bits scalar calibration definition */
#define COCLLASL_START_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bAcvSBPA_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bProtDfwTypSel_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_bUseFuelRunDry_C = DDS_FALSE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqSys_facTqSmkAcv_C = (UInt8)(0.75 * BIN7);
STATIC volatile CONST(UInt8, AUTOMATIC) Tqsys_bUseExhTempProt_C = DDS_FALSE;
#define COCLLASL_STOP_SEC_CALIB_8BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define COCLLASL_START_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_nEngColdSmk_A[COCLLASL_6_SIZE] = {
(UInt16)(1000 * BIN0), (UInt16)(2000 * BIN0), (UInt16)(3000 * BIN0),
(UInt16)(4000 * BIN0), (UInt16)(5000 * BIN0), (UInt16)(6000 * BIN0)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiTranSmkOff_T
[COCLLASL_6_SIZE] = {
(UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3),
(UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3)
};

STATIC volatile CONST(UInt16, AUTOMATIC) TqSys_tiTranSmkOn_T
[COCLLASL_6_SIZE] = {
(UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3),
(UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3), (UInt16)(0.2 * DEC3)
};

#define COCLLASL_STOP_SEC_CARTO_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_titransmkoff_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqsys_titransmkon_t_sav;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) cocllasl_f02_hyst;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) cocllasl_f07_hyst;
STATIC VAR(t_dds_m_hyst_type, AUTOMATIC) cocllasl_f07_hyst_1;
STATIC VAR(t_dds_m_soft_trans_delta_u32_type, AUTOMATIC) cocllasl_f02_contmltpswrmptran;
#define COCLLASL_STOP_SEC_VAR_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/* Complex variable definition */
#define COCLLASL_START_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) cocllasl_f02_contmltpswrmptran_init;
#define COCLLASL_STOP_SEC_VAR_8BIT
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COCLLASL_START_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) IdlSys_tqIdcIdlAvSBPA; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqIdcEngLimCordRaw; /* BIN4 */
#define COCLLASL_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoClLASl_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define COCLLASL_START_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"
STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_TITRANSMKOFF_T_APM = {
&tqsys_titransmkoff_t_sav,
COCLLASL_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngColdSmk_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiTranSmkOff_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) TQSYS_TITRANSMKON_T_APM = {
&tqsys_titransmkon_t_sav,
COCLLASL_6_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_nEngColdSmk_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqSys_tiTranSmkOn_T[0]
};

#define COCLLASL_STOP_SEC_CONST_UNSPECIFIED
#include "CoClLASl_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COCLLASL_START_SEC_CODE
#include "CoClLASl_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_Calc_Idle_Coordination(
                                           SInt16 tqsys_tqckantistall_par, /* BIN4 */
                                           UInt8 tqsys_bacvantistallaut_par,
                                           UInt8 tqsys_bacvantistallman_par,
                                           UInt8 ext_stgbxcf_par,
                                           SInt16 idlsys_tqidcidl_par, /* BIN4 */
                                           UInt8 idlsys_bacvidlctl_par,
                                           SInt16 tqsys_tqidcsbpa_par, /* BIN4 */
                                           SInt16 tqsys_tqidclvlsbpa_par, /* BIN4 */
                                           UInt8 idlsys_bacvantistall_par,
                                           UInt8 tqsys_bidlacv_par,
                                           SInt16 tqsys_tqckidl_par, /* BIN4 */
                                           UInt8 dfwctl_bacvlimtqidl_par,
                                           SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                           UInt8 tqsys_btypfu_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistall_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bidlacvcmn_ptr,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckidlcmn_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckidlcord_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) idlsys_tqidcidlairsbpa_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_CordFumeeBleu(
                                           UInt8 tqsys_btypfu_par,
                                           SInt16 englim_tqidccoldsmkraw_par, /* BIN4 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 copt_bsipcord_par,
                                           UInt16 covsctl_raccpengtrv_par, /* BIN7 */
                                           SInt16 copt_tqidcreqcord_nregreq_par, /* BIN4 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidccoldsmkcord_ptr);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Commun_CordAvance(
                                           SInt16 englim_tqidclim_par, /* BIN4 */
                                           SInt16 englim_tqidcred_par, /* BIN4 */
                                           SInt16 tqsys_tqckidlcord_par, /* BIN4 */
                                           SInt16 tqsys_tqidccoldsmkcord_par,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcengidlcord_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F04_CordFord(
                                           UInt8 tqsys_facreqexhtempprot_par, /* BIN7 */
                                           UInt8 tqsys_facreqfuelrundry_par, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcenglimcord_ptr /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) COCLLASL_F07_Calcul_flag_ralenti(
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidlcord_par, /* BIN4 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 copt_tqidcreqcord_nregreq_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bengnonidl_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_benguhnonidl_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COCLLASL_Idl_Coord_Lim_Sync
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim_Sync(UInt8 CoPt_bSIPCord_swc_in,
                                           SInt16 CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
                                           UInt16 CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                                           UInt8 DfwCtl_bAcvLimTqIdl_swc_in,
                                           SInt16 EngLim_tqIdcColdSmkRaw_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcLim_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqIdcRed_swc_in, /* BIN4 */
                                           UInt16 Ext_nEng_swc_in, /* BIN0 */
                                           UInt8 Ext_stGBxCf_swc_in,
                                           UInt8 Ext_tiTDC_swc_in, /* DEC3 */
                                           UInt8 IdlSys_bAcvAntiStall_swc_in,
                                           UInt8 IdlSys_bAcvIdlCtl_swc_in,
                                           SInt16 IdlSys_tqIdcIdl_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           UInt8 TqSys_bAcvAntiStallAut_swc_in,
                                           UInt8 TqSys_bAcvAntiStallMan_swc_in,
                                           UInt8 TqSys_bIdlAcv_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           UInt8 TqSys_facReqExhTempProt_swc_in, /* BIN7 */
                                           UInt8 TqSys_facReqFuelRunDry_swc_in, /* BIN7 */
                                           UInt16 TqSys_nTarIdl_swc_in, /* BIN2 */
                                           SInt16 TqSys_tqCkAntiStall_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqCkIdl_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcLvlSBPA_swc_in, /* BIN4 */
                                           SInt16 TqSys_tqIdcSBPA_swc_in, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStall_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngUHNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bIdlAcvCmn_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCmn_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) IdlSys_tqIdcIdlAirSBPA_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcColdSmkCord_swc_out /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.3.3 */
    SInt16 tqsys_tqidccoldsmkcord_loc;

    COCLLASL_F01_Calc_Idle_Coordination(TqSys_tqCkAntiStall_swc_in, /* BIN4 */
                                        TqSys_bAcvAntiStallAut_swc_in,
                                        TqSys_bAcvAntiStallMan_swc_in,
                                        Ext_stGBxCf_swc_in,
                                        IdlSys_tqIdcIdl_swc_in, /* BIN4 */
                                        IdlSys_bAcvIdlCtl_swc_in,
                                        TqSys_tqIdcSBPA_swc_in, /* BIN4 */
                                        TqSys_tqIdcLvlSBPA_swc_in, /* BIN4 */
                                        IdlSys_bAcvAntiStall_swc_in,
                                        TqSys_bIdlAcv_swc_in,
                                        TqSys_tqCkIdl_swc_in, /* BIN4 */
                                        DfwCtl_bAcvLimTqIdl_swc_in,
                                        TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                        TqSys_bTypFu_swc_in,
                                        TqSys_bAcvAntiStall_swc_out,
                                        TqSys_bIdlAcvCmn_swc_out,
                                        TqSys_tqCkIdlCmn_swc_out, /* BIN4 */
                                        TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                        IdlSys_tqIdcIdlAirSBPA_swc_out /* BIN4 */);

    COCLLASL_F02_CordFumeeBleu(TqSys_bTypFu_swc_in,
                               EngLim_tqIdcColdSmkRaw_swc_in, /* BIN4 */
                               Ext_tiTDC_swc_in, /* DEC3 */
                               CoPt_bSIPCord_swc_in,
                               CoVSCtl_rAccPEngTrv_swc_in, /* BIN7 */
                               CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
                               Ext_nEng_swc_in, /* BIN0 */
                               &tqsys_tqidccoldsmkcord_loc /* BIN4 */);

    *TqSys_tqIdcColdSmkCord_swc_out = tqsys_tqidccoldsmkcord_loc;

    COCLLASL_F03_Commun_CordAvance(EngLim_tqIdcLim_swc_in, /* BIN4 */
                                   EngLim_tqIdcRed_swc_in, /* BIN4 */
                                   *TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                   tqsys_tqidccoldsmkcord_loc,
                                   TqSys_tqIdcEngIdlCord_swc_out /* BIN4 */);

    COCLLASL_F04_CordFord(TqSys_facReqExhTempProt_swc_in, /* BIN7 */
                          TqSys_facReqFuelRunDry_swc_in, /* BIN7 */
                          TqSys_tqIdcEngLimCord_swc_out /* BIN4 */);

    COCLLASL_F07_Calcul_flag_ralenti(TqSys_nTarIdl_swc_in, /* BIN2 */
                                     *TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                     Ext_nEng_swc_in, /* BIN0 */
                                     CoPt_tqIdcReqCord_nRegReq_swc_in, /* BIN4 */
                                     TqSys_bEngNOnIdl_swc_out,
                                     TqSys_bEngUHNOnIdl_swc_out);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_F01_Calc_Idle_Coordination
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F01_Calc_Idle_Coordination(
                                           SInt16 tqsys_tqckantistall_par, /* BIN4 */
                                           UInt8 tqsys_bacvantistallaut_par,
                                           UInt8 tqsys_bacvantistallman_par,
                                           UInt8 ext_stgbxcf_par,
                                           SInt16 idlsys_tqidcidl_par, /* BIN4 */
                                           UInt8 idlsys_bacvidlctl_par,
                                           SInt16 tqsys_tqidcsbpa_par, /* BIN4 */
                                           SInt16 tqsys_tqidclvlsbpa_par, /* BIN4 */
                                           UInt8 idlsys_bacvantistall_par,
                                           UInt8 tqsys_bidlacv_par,
                                           SInt16 tqsys_tqckidl_par, /* BIN4 */
                                           UInt8 dfwctl_bacvlimtqidl_par,
                                           SInt16 tqcmp_tqsumlosscmp_par, /* BIN4 */
                                           UInt8 tqsys_btypfu_par,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bacvantistall_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bidlacvcmn_ptr,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckidlcmn_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqckidlcord_ptr, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) idlsys_tqidcidlairsbpa_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.6.0 */
    SInt32 cocllasl_f01_value;
    SInt32 cocllasl_f01_value_2;

    if((UInt32)TqSys_bAcvSBPA_C != (UInt32)DDS_FALSE)
    {
        IdlSys_tqIdcIdlAvSBPA = tqsys_tqidcsbpa_par;
        *idlsys_tqidcidlairsbpa_ptr = tqsys_tqidclvlsbpa_par;
    }
    else
    {
        IdlSys_tqIdcIdlAvSBPA = 0;
        *idlsys_tqidcidlairsbpa_ptr = 0;
    }

    if((UInt32)tqsys_btypfu_par != (UInt32)DDS_FALSE)
    {
        *tqsys_bidlacvcmn_ptr = idlsys_bacvidlctl_par;
        *tqsys_bacvantistall_ptr = idlsys_bacvantistall_par;
        cocllasl_f01_value = (SInt32)idlsys_tqidcidl_par;
        *tqsys_tqckidlcmn_ptr = idlsys_tqidcidl_par;
    }
    else
    {
        *tqsys_bidlacvcmn_ptr = tqsys_bidlacv_par;

        if((UInt32)ext_stgbxcf_par != 0)
        {
            *tqsys_bacvantistall_ptr = tqsys_bacvantistallaut_par;
        }
        else
        {
            *tqsys_bacvantistall_ptr = tqsys_bacvantistallman_par;
        }

        if((UInt32)tqsys_bacvantistallman_par != (UInt32)DDS_FALSE)
        {
            cocllasl_f01_value = tqsys_tqckantistall_par;
        }
        else
        {
            cocllasl_f01_value = tqsys_tqckidl_par;
        }

        *tqsys_tqckidlcmn_ptr = tqsys_tqckidl_par;
    }

    if((UInt32)dfwctl_bacvlimtqidl_par != (UInt32)DDS_FALSE)
    {
        if((UInt32)TqSys_bProtDfwTypSel_C != (UInt32)DDS_FALSE)
        {
            cocllasl_f01_value_2 = DDS_M_SATURATION((SInt32)tqcmp_tqsumlosscmp_par+(SInt32)TqSys_tqMaxProtDfw_C,-2000*BIN4,2000*BIN4);
        }
        else
        {
            cocllasl_f01_value_2 = (SInt32)TqSys_tqMaxProtDfw_C;
        }
        *tqsys_tqckidlcord_ptr = (SInt16)DDS_M_MIN(cocllasl_f01_value_2,cocllasl_f01_value);
    }
    else
    {
        *tqsys_tqckidlcord_ptr = (SInt16)cocllasl_f01_value;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F02_CordFumeeBleu
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F02_CordFumeeBleu(
                                           UInt8 tqsys_btypfu_par,
                                           SInt16 englim_tqidccoldsmkraw_par, /* BIN4 */
                                           UInt8 ext_titdc_par, /* DEC3 */
                                           UInt8 copt_bsipcord_par,
                                           UInt16 covsctl_raccpengtrv_par, /* BIN7 */
                                           SInt16 copt_tqidcreqcord_nregreq_par, /* BIN4 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidccoldsmkcord_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.7.0 */
    SInt32 cocllasl_f03_value_1;
    SInt32 cocllasl_f03_value_2;
    SInt32 cocllasl_f03_value_3;
    UInt8 cocllasl_f03_target;
    UInt32 cocllasl_u32;
    UInt32 cocllasl_temp_u32;

    cocllasl_f03_value_1 = ((SInt32)TqSys_facTqSmkAcv_C * (SInt32)englim_tqidccoldsmkraw_par) / BIN7;

    cocllasl_f03_value_2 = (SInt32)DDS_M_HYST_PH_S32(&cocllasl_f02_hyst,
                                                     (SInt32)copt_tqidcreqcord_nregreq_par,
                                                     cocllasl_f03_value_1 + (SInt32)TqSys_tqHystTqSmkDeac_C,
                                                     cocllasl_f03_value_1);

    cocllasl_f03_value_1 = (SInt32)DDS_M_MAP2D_U16(&TQSYS_TITRANSMKON_T_APM,ext_neng_par);
    cocllasl_f03_value_3 = (SInt32)DDS_M_MAP2D_U16(&TQSYS_TITRANSMKOFF_T_APM,ext_neng_par);

    if(  ((UInt32)cocllasl_f03_value_2 == (UInt32)DDS_TRUE)
       &&((UInt32)covsctl_raccpengtrv_par >= (UInt32)TqSys_rAccPThdPedPrss_C))
    {
        cocllasl_f03_target = DDS_FALSE;
        /* cocllasl_f03_value_1 doesn't need to change */
    }
    else
    {
        cocllasl_f03_target = DDS_TRUE;
        cocllasl_f03_value_1 = cocllasl_f03_value_3;
    }

    if((UInt32)cocllasl_f02_contmltpswrmptran_init != (UInt32)DDS_TRUE)
    {
        cocllasl_f02_contmltpswrmptran_init = DDS_TRUE;

        cocllasl_temp_u32 = (UInt32)((SInt32)englim_tqidccoldsmkraw_par+(2000*BIN4));
        cocllasl_u32 = DDS_M_SOFT_TRANS_DELTA_U32_INIT(cocllasl_f03_target,
                                                                        /* +2000 offset in order to work with UInt32*/
                                                                       cocllasl_temp_u32,
                                                                       (2000*BIN4),
                                                                       /*UInt32 delta_time,*/
                                                                       DDS_NULL_PTR,      /* May be DDS_NULL_PTR */
                                                                       &cocllasl_f02_contmltpswrmptran);
    }
    else
    {
        cocllasl_temp_u32 = (UInt32)((SInt32)englim_tqidccoldsmkraw_par+(2000*BIN4));
        cocllasl_u32 = DDS_M_SOFT_TRANS_DELTA_U32(cocllasl_f03_target,/* E Boolean */
                                                                    /* +2000 offset in order to work with UInt32*/
                                                                    cocllasl_temp_u32,
                                                                    (UInt32)(2000*BIN4),
                                                                    (UInt32)ext_titdc_par,/* Delta time */
                                                                    (UInt32)cocllasl_f03_value_1,/* Tup */
                                                                    (UInt32)cocllasl_f03_value_1, /* Tdown UInt16 DEC3 [0;3] */
                                                                    &cocllasl_f02_contmltpswrmptran);/* Pointer to structure */
    }
    /* get the true value : value - offset */
    cocllasl_f03_value_2 = (SInt32)cocllasl_u32 - (2000*BIN4);

    if(  ((UInt32)copt_bsipcord_par == (UInt32)DDS_FALSE)
       &&((UInt32)tqsys_btypfu_par == (UInt32)DDS_FALSE)
       &&((SInt32)englim_tqidccoldsmkraw_par > (SInt32)copt_tqidcreqcord_nregreq_par))
    {
        *tqsys_tqidccoldsmkcord_ptr = (SInt16)cocllasl_f03_value_2;
    }
    else
    {
        *tqsys_tqidccoldsmkcord_ptr = copt_tqidcreqcord_nregreq_par;
    }
}

/*******************************************************************************
*
* Function Name : COCLLASL_F03_Commun_CordAvance
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F03_Commun_CordAvance(
                                           SInt16 englim_tqidclim_par, /* BIN4 */
                                           SInt16 englim_tqidcred_par, /* BIN4 */
                                           SInt16 tqsys_tqckidlcord_par, /* BIN4 */
                                           SInt16 tqsys_tqidccoldsmkcord_par, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcengidlcord_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.5.1 */
    SInt32 cocllasl_f03_value_1;

    *tqsys_tqidcengidlcord_ptr = (SInt16)DDS_M_LIMIT_V2((SInt32)englim_tqidcred_par,
                                                        (SInt32)tqsys_tqckidlcord_par,
                                                        (SInt32)tqsys_tqidccoldsmkcord_par);

    cocllasl_f03_value_1 = DDS_M_LIMIT((SInt32)*tqsys_tqidcengidlcord_ptr + (SInt32)IdlSys_tqIdcIdlAvSBPA,
                                        -2000*BIN4,
                                        2000*BIN4);

    TqSys_tqIdcEngLimCordRaw = (SInt16)DDS_M_MIN((SInt32)englim_tqidclim_par,cocllasl_f03_value_1);
}

/*******************************************************************************
*
* Function Name : COCLLASL_F04_CordFord
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F04_CordFord(
                                           UInt8 tqsys_facreqexhtempprot_par, /* BIN7 */
                                           UInt8 tqsys_facreqfuelrundry_par, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcenglimcord_ptr /* BIN4 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.8.0 */
    SInt32 cocllasl_f03_value_1; /* BIN11 */

    if((UInt32)TqSys_bUseFuelRunDry_C != (UInt32)DDS_FALSE)
    {
        cocllasl_f03_value_1 = (SInt32)TqSys_tqIdcEngLimCordRaw * (SInt32)tqsys_facreqfuelrundry_par;
    }
    else
    {
        cocllasl_f03_value_1 = (SInt32)TqSys_tqIdcEngLimCordRaw * BIN7;
    }

    if((UInt32)Tqsys_bUseExhTempProt_C != (UInt32)DDS_FALSE)
    {
        /* BIN4 = BIN7 * BIN11 / BIN14 */
        *tqsys_tqidcenglimcord_ptr = (SInt16)(((SInt32)tqsys_facreqexhtempprot_par * cocllasl_f03_value_1) / BIN14);
    }
    else
    {
        /* BIN4 = BIN11 / BIN7 */
        *tqsys_tqidcenglimcord_ptr = (SInt16)(cocllasl_f03_value_1 / BIN7);
    }

}

/*******************************************************************************
*
* Function Name : COCLLASL_F07_Calcul_flag_ralenti
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COCLLASL_F07_Calcul_flag_ralenti(
                                           UInt16 tqsys_ntaridl_par, /* BIN2 */
                                           SInt16 tqsys_tqckidlcord_par, /* BIN4 */
                                           UInt16 ext_neng_par, /* BIN0 */
                                           SInt16 copt_tqidcreqcord_nregreq_par, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_bengnonidl_ptr,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_benguhnonidl_ptr)
{
    /* SSTG_REQ_TAG CSMT_CGMT08_0939.FR.4.4 */

    UInt32 cocllasl_f02_hyst_out;

    *tqsys_bengnonidl_ptr = DDS_M_HYST_PH_S32(&cocllasl_f07_hyst,
                                              (SInt32)tqsys_tqckidlcord_par,
                                              (SInt32)copt_tqidcreqcord_nregreq_par + (SInt32)TqSys_tqOfsThdHiIdlAcv_C,
                                              (SInt32)copt_tqidcreqcord_nregreq_par + (SInt32)TqSys_tqOfsThdLoIdlAcv_C);


    cocllasl_f02_hyst_out = (UInt32)DDS_M_HYST_LH_U32(&cocllasl_f07_hyst_1,
                                                      (UInt32)ext_neng_par * BIN2,
                                                      (UInt32)tqsys_ntaridl_par + ((UInt32)TqSys_nIdlOff_C * BIN2),
                                                      (UInt32)tqsys_ntaridl_par + ((UInt32)TqSys_nIdlOn_C * BIN2));

    if(  (cocllasl_f02_hyst_out == (UInt32)DDS_TRUE)
       &&((UInt32)*tqsys_bengnonidl_ptr == (UInt32)DDS_TRUE))
    {
        *tqsys_benguhnonidl_ptr = DDS_TRUE;
    }
    else
    {
        *tqsys_benguhnonidl_ptr = DDS_FALSE;
    }
}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COCLLASL_Idl_Coord_Lim_Sync_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COCLLASL_Idl_Coord_Lim_Sync_Init( CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bAcvAntiStall_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bEngUHNOnIdl_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bIdlAcvCmn_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCmn_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngIdlCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcEngLimCord_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) IdlSys_tqIdcIdlAirSBPA_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcColdSmkCord_swc_out /* BIN4 */)
{
    *TqSys_bAcvAntiStall_swc_out = DDS_TRUE;
    *TqSys_bEngNOnIdl_swc_out = DDS_TRUE;
    *TqSys_bEngUHNOnIdl_swc_out = DDS_TRUE;
    *TqSys_bIdlAcvCmn_swc_out = DDS_TRUE;
    *TqSys_tqCkIdlCmn_swc_out = 0;
    *TqSys_tqCkIdlCord_swc_out = 0;
    *TqSys_tqIdcEngIdlCord_swc_out = 0;
    *TqSys_tqIdcEngLimCord_swc_out = 0;
    *IdlSys_tqIdcIdlAirSBPA_swc_out = 0;
    *TqSys_tqIdcColdSmkCord_swc_out = 0;

    DDS_M_HYST_S32_INIT(&cocllasl_f02_hyst,DDS_FALSE);
    DDS_M_HYST_S32_INIT(&cocllasl_f07_hyst,DDS_FALSE);
    DDS_M_HYST_U32_INIT(&cocllasl_f07_hyst_1,DDS_TRUE);

    cocllasl_f02_contmltpswrmptran_init = DDS_FALSE;

    IdlSys_tqIdcIdlAvSBPA = 0;
    TqSys_tqIdcEngLimCordRaw = 0;


}

#define COCLLASL_STOP_SEC_CODE
#include "CoClLASl_MemMap.h"

/* Data_Dictionary_v1.0
* Tool: DD_Editor 7.10
* Date: 10/12/2013 13:25:48
* PERL v5.14.2
* Lib_CC 1.37
* Lib_Clipboard 1.01
* Lib_Code_Writer 1.00
* Lib_CQ 1.22
* Lib_DD_Check 2.13
* Lib_DD_Check_Checks 1.51
* Lib_DD_Check_Data 2.10
* Lib_DD_Check_Utils 2.14
* Lib_DD_Compare 1.11
* Lib_DD_GenCode 3.31
* Lib_DD_Load 3.11
* Lib_DD_Structure 1.11
* Lib_Feature 1.03
* Lib_Gui_Button 1.03
* Lib_Gui_CheckBox 1.03
* Lib_Gui_ComboBox 1.07
* Lib_Gui_Common 1.43
* Lib_Gui_Grid 1.01
* Lib_Gui_GridLayout 1.10
* Lib_Gui_GroupBox 1.02
* Lib_Gui_Hotkey 1.02
* Lib_Gui_Label 1.11
* Lib_Gui_ListView 1.02
* Lib_Gui_Menu 1.02
* Lib_Gui_MsgBox 1.01
* Lib_Gui_NotifyIcon 1.01
* Lib_Gui_ProgressBar 1.02
* Lib_Gui_RadioButton 1.02
* Lib_Gui_TextBox 1.04
* Lib_Gui_Windows 1.18
* Lib_Hash 1.33
* Lib_Log 1.32
* Lib_Maths 1.10
* Lib_Pjt 1.32
* Lib_Preprocessor 1.25
* Lib_QAC 1.11
* Lib_Scheduler_Tag 2.30
* Lib_Scheduler_XML 1.50
* Lib_Spectool_Gen_DD 2.33
* Lib_Twk 1.06
* Lib_Utils 1.06
* Lib_Version 1.11
* Lib_Xml_Xsd_Check_Tool 1.09
* Name ;Bnf ;Feature ;Unit ;Min ;Max ;Resolution ;Nature ;Control Type ;XInput ;YInput ;ZInput ;Typical Calibration ;Description ;Implemented ;Data Type ;BinPoint ;XAxis ;YAxis ;ZAxis ;BitCarrier ;Parent Alias ;Position

* INPUT_SECTION *
CoPt_bSIPCord ;["FALSE"|"TRUE"] ;COPT ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Detection du changement de rapport de boite / Gear change detection ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoPt_tqIdcReqCord_nRegReq ; ;COPT ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple indiqué coordonné avec la demande de régulation en régime BV branche avance ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
CoVSCtl_rAccPEngTrv ; ;COVSCTL ;% ;0 ;100 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Valeur pedale moteur transversal ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
DfwCtl_bAcvLimTqIdl ;["FALSE"|"TRUE"] ;DFWCTL ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Demande de saturation du couple de ralenti pour protection DVA ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcColdSmkRaw ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;couple de limitation fumee bleue de base ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcLim ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple de limitation apres la coodination du ralenti sur la branche avance ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
EngLim_tqIdcRed ; ;ENGLIM ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple indique de limitation debit reduit (safety) ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_nEng ; ;EXT ;rpm ;0 ;7500 ;1 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Regime moteur mesure sur une phase moteur ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_stGBxCf ;["BVM"*0*|"BVA"*1*|"BVMP"*2*] ;EXT ;N/A ;0 ;2 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Type de boite0=BVM1=BVA2=BVMP ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
Ext_tiTDC ; ;EXT ;s ;0 ;0.1 ;1/1000 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Temps entre 2 PMH ;["YES"] ;UInt8 ;DEC3 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
IdlSys_bAcvAntiStall ;["FALSE"|"TRUE"] ;IDLSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen indiquant une demande d activation de la strategie anti-calage ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
IdlSys_bAcvIdlCtl ;["FALSE"|"TRUE"] ;IDLSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Booleen d activation des calculs du regulateur de ralenti ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
IdlSys_tqIdcIdl ; ;IDLSYS ;Nm ;-2000 ;2000 ;0.0625 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple indique sur l’avance pour le ralenti ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqCmp_tqSumLossCmp ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple des pertes globales a compenser. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallAut ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["NULL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag d activation de la strategie d anti-calage BVA/BVMP utilisee par la strategie IVC ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStallMan ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Vrai si l’anti-calage BVM est actif ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bIdlAcv ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag d activation du regulateur de ralenti renomme ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bTypFu ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Type de carburant retraite et simplifie ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facReqExhTempProt ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Gain de ponderation provenant de CVC ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facReqFuelRunDry ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Gain de ponderation provenant de CVC ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nTarIdl ; ;TQSYS ;rpm ;0 ;8000 ;0.25 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Regime de ralenti cible final ;["YES"] ;UInt16 ;BIN2 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkAntiStall ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple de sortie de la strategie anti-calage BVM (specifique Diesel) ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkIdl ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple du regulateur de ralenti ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcLvlSBPA ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Somme des niveaux haut et bas appliques a la SBPA. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcSBPA ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;SBPA delivree par le generateur. ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
s_s_start_up_init ;["FALSE"|"TRUE"] ;S_S ;N/A ;0 ;1 ;1 ;["NULL"] ;["EVENT"] ;N/A ;N/A ;N/A ;N/A ;This is a conceptual flow used to show the activation of the init functions within each of the tasks. ;["NO"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* OUTPUT_SECTION *
IdlSys_tqIdcIdlAirSBPA ; ;IDLSYS ;Nm ;-2000 ;2000 ;1/16 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Amplitude de la correction de la fonction SBPA Air apres activation ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvAntiStall ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Coordination des flags d activation d anti-calage BVM/BVA/BVMP Essence/diesel ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bEngNOnIdl ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag : Moteur sous contrôle du regulateur de ralenti generique ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bEngUHNOnIdl ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Flag : Moteur sous contrôle du regulateur de ralenti pour les besoins STTx ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bIdlAcvCmn ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["DISP"] ;["LEVEL"] ;N/A ;N/A ;N/A ;N/A ;Activation du regulateur de ralenti commun ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkIdlCmn ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple du regulateur de ralenti commun ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqCkIdlCord ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple ralenti coordonne avec l’anticalage ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcColdSmkCord ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple coordonne avec la fumee bleue ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcEngIdlCord ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple consigne coordonne avec le couple du regulateur ralenti branche avance ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcEngLimCord ; ;TQSYS ;Nm ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple consigne coordonne avec tous les limtations branche avance ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
* LOCAL_SECTION *
COCLLASL_6_SIZE ; ;COCLLASL ;N/A ;0 ;255 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;6 ;Type for axis ;["YES"] ;N/A ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
IdlSys_tqIdcIdlAvSBPA ; ;IDLSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Amplitude de la correction de la fonction SBPA Avance apres activation ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bAcvSBPA_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Flag d activation de la fonction SBPA pour la calibration ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bProtDfwTypSel_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;TRUE ;Choix du type de couple MAX pour protection DVA ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_bUseFuelRunDry_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Flag de configuration pour prendre en compte les fonctions CVC ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_facTqSmkAcv_C ; ;TQSYS ;N/A ;0 ;1 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;0.75 ;Coefficient de gain sur le couple de fumee de base pour activation descendante ;["YES"] ;UInt8 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nEngColdSmk_A ;1{t_tqsys_nengcoldsmk_a}COCLLASL_6_SIZE ;TQSYS ;N/A ;N/A ;N/A ;N/A ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;[1000 2000 3000 4000 5000 6000] ;Bkpts de regime moteur ;["YES"] ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nIdlOff_C ; ;TQSYS ;rpm ;0 ;7500 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;200 ;Seuil bas d hysterisis de regime pour le calcul du flag de ralenti actif ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_nIdlOn_C ; ;TQSYS ;rpm ;0 ;7500 ;1 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;100 ;Seuil haut d hysterisis de regime pour le calcul du flag de ralenti actif ;["YES"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_rAccPThdPedPrss_C ; ;TQSYS ;% ;0 ;100 ;1/128 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2 ;Seuil de pedale pour etre hors Pied Leve ;["YES"] ;UInt16 ;BIN7 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiTranSmkOff_T ; ;TQSYS ;s ;0 ;1 ;0.001 ;["MAP"] ;["N/A"] ;Ext_nEng ;N/A ;N/A ;[0.2 0.2 0.2 0.2 0.2 0.2] ;Temps de transition ascendante dans la coordination de la fumee bleue ;["YES"] ;DDS_M_MAP2D_U16 ;DEC3 ;TqSys_nEngColdSmk_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tiTranSmkOn_T ; ;TQSYS ;s ;0 ;1 ;0.001 ;["MAP"] ;["N/A"] ;Ext_nEng ;N/A ;N/A ;[0.2 0.2 0.2 0.2 0.2 0.2] ;Temps de transition descendante dans la coordination de la fumee bleue ;["YES"] ;DDS_M_MAP2D_U16 ;DEC3 ;TqSys_nEngColdSmk_A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqHystTqSmkDeac_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;5 ;Hysteresis de couple sur le seuil d activation ascendante de la fumee bleue ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqIdcEngLimCordRaw ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["DISP"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Couple coordonne avec le ralenti et les limitations brute ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqMaxProtDfw_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;2000 ;Couple max de saturation du couple du regulateur de ralenti pour protection DVA ;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

TqSys_tqOfsThdHiIdlAcv_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;10 ;Seuil haut d'hystérésis de couple pour le calcul du flag de ralenti effectif;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
TqSys_tqOfsThdLoIdlAcv_C ; ;TQSYS ;N.m ;-2000 ;2000 ;1/16 ;["CAL"] ;["N/A"] ;N/A ;N/A ;N/A ;5 ;Seuil bas d'hystérésis de couple pour le calcul du flag de ralenti effectif;["YES"] ;SInt16 ;BIN4 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Tqsys_bUseExhTempProt_C ;["FALSE"|"TRUE"] ;TQSYS ;N/A ;0 ;1 ;1 ;["CAL"] ;["LEVEL"] ;N/A ;N/A ;N/A ;FALSE ;Flag de configuration pour prendre en compte les fonctions CVC ;["YES"] ;UInt8 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A
t_tqsys_nengcoldsmk_a ; ;TQS ;rpm ;0 ;7500 ;1 ;["NULL"] ;["N/A"] ;N/A ;N/A ;N/A ;N/A ;Type for axis ;["NO"] ;UInt16 ;BIN0 ;N/A ;N/A ;N/A ;N/A ;N/A ;N/A

Data_Dictionary */

