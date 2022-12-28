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
* Ref X:\integration_view_00PSASWC_D220D01\blois_psa_sstg\Software\Appli\VSInfo\src\VSINFO_Info_Transmission_Sl.c
* Version int :/main/L03_01/1 Date: 4/1/2012 16 h 30 m User:esnault 
*    TWK_model:VSINFO_Info_Transmission_Sl_L03_010_IMPL1
*    comments :for VSInfo 12.0 : rename Tra_rConvTra in CoPt_rCnvTq and Tra_tqLoss in TqCmp_tqCnvLoss
* Version dev :\main\branch_demezil_vsinfo_view\2 Date: 22/11/2011 11 h 54 m User:demezil 
*    TWK_model:VSINFO_Info_Transmission_Sl_L03_010_IMPL1
*    comments :for VSInfo 12.0 : rename Tra_rConvTra in CoPt_rCnvTq and Tra_tqLoss in TqCmp_tqCnvLoss
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 14/11/2011 9 h 39 m User:demezil
*    TWK_model:VSINFO_Info_Transmission_Sl_L03_010_IMPL1
*    comments :for VSInfo 12.0 : rename Tra_rConvTra in CoPt_rCnvTq and Tra_tqLoss in TqCmp_tqCnvLoss
* Version int :/main/L02_01/1 Date: 25/8/2011 16 h 7 m User:meme
*    TWK_model:VSINFO_Info_Transmission_Sl_L02_010_IMPL1
*    comments :for VSInfo11.0
* Version dev :\main\branch_demezil_vsinfo_view\1 Date: 8/7/2011 9 h 11 m User:demezil
*    TWK_model:VSINFO_Info_Transmission_Sl_L02_010_IMPL1
*    comments :for VSInfo11.0
* Version int :/main/L01_01/3 Date: 12/5/2011 8 h 48 m User:meme
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1_D
*    comments :FDS A0201372 / ALTIS_1583771
* Version dev :\main\branch_demezil_generic_view\1 Date: 10/5/2011 17 h 32 m User:demezil
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1_D
*    comments :FDS A0201372 / ALTIS_1583771
* Version int :/main/L01_01/2 Date: 4/3/2011 12 h 24 m User:meme
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 25/2/2011 14 h 24 m User:morisseau
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :UT correction
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 22/2/2011 12 h 45 m User:morisseau
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :UT correction
* Version int :/main/L01_01/1 Date: 14/2/2011 15 h 15 m User:meme
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :correct undisplayable data name
* Version dev :\main\branch_morisseau_vsinfo_dev\5 Date: 1/2/2011 16 h 30 m User:morisseau
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :correct undisplayable data name
* Version dev :\main\branch_morisseau_vsinfo_dev\4 Date: 7/1/2011 11 h 35 m User:morisseau
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :QAC correction
* Version dev :\main\branch_morisseau_vsinfo_dev\3 Date: 5/1/2011 18 h 26 m User:morisseau
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :correct in/out after model check and compilation
* Version dev :\main\branch_morisseau_vsinfo_dev\2 Date: 21/12/2010 9 h 51 m User:morisseau
*    TWK_model:VSINFO_Info_Transmission_Sl_L01_010_IMPL1
*    comments :add model to code file
* Version dev :\main\branch_morisseau_vsinfo_dev\1 Date: 20/12/2010 17 h 17 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :first version for VSInfo 10.0
*
*******************************************************************************/

/*******************************************************************************
* Library Include Files
*******************************************************************************/

#include "dds_lib.h"


/*******************************************************************************
* Software Component API Header File
*******************************************************************************/

#include "VSInfo.h"


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define VSC_ARRET                   (UInt32)0

/* VSCtl_strConvTraIntno1ModClc */
#define VSC_INIT_5                  (UInt32)2
#define VSC_NOMINAL_5               (UInt32)3

/* VSCtl_strConvTraIntno2ModClc */
#define VSC_INIT_6                  (UInt32)2
#define VSC_NOMINAL_6               (UInt32)3

#define VSC_20_BIN7                 (20 * BIN7)
#define VSCTL_RCONVTRA_MIN          (UInt32)(0.1 * BIN7)


/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* 16-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt16, AUTOMATIC) VSCtl_tirConvTra; /* BIN0 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8-bits variables definition */
#define VSINFO_START_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFilTraInfo;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rConvTraExt;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rConvTraInt1;
extern VAR(UInt8, AUTOMATIC) VSCtl_bAcvFil_rConvTraInt2;
extern VAR(UInt8, AUTOMATIC) VSCtl_strConvTraExtModClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_strConvTraIntno1ModClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_strConvTraIntno2ModClc;
extern VAR(UInt8, AUTOMATIC) VSCtl_strConvTraModClc;
#define VSINFO_STOP_SEC_INTERNAL_VAR_8BIT
#include "VSInfo_MemMap.h"



/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
extern volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_nFrntWhl_C;
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"

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
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
VAR(UInt16, AUTOMATIC) VSCtl_rConvTraVirt_no1; /* BIN7 */
VAR(UInt16, AUTOMATIC) VSCtl_rConvTraVirt_no2; /* BIN7 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 32-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_32BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nEng_SatMax_C = (CONST(UInt32, AUTOMATIC))(5000 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nEng_SatMin_C = (CONST(UInt32, AUTOMATIC))(750 * BIN7);
STATIC volatile CONST(UInt32, AUTOMATIC) VSCtl_nFrntWhlFil_SatMin_C = (CONST(UInt32, AUTOMATIC))(0.1015625 * BIN7);
#define VSINFO_STOP_SEC_CALIB_32BIT
#include "VSInfo_MemMap.h"

/* 16-bits scalar calibration definition */
#define VSINFO_START_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraExt_SatMax_C = (CONST(UInt16, AUTOMATIC))(20 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraExt_SatMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraInt_SatMax_C = (CONST(UInt16, AUTOMATIC))(20 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraInt_SatMin_C = (CONST(UInt16, AUTOMATIC))(0 * BIN7);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_FilMaxrConvTra_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_FilMinrConvTra_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_grdRatConvTra_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_nEng1_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_nEng2_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rConvTraExt_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rConvTraInt_no1_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_rConvTraInt_no2_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tiFil_spdFrntWhl_C = (CONST(UInt16, AUTOMATIC))(1 * BIN10);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqLossTraExt_SatMax_C = (CONST(SInt16, AUTOMATIC))(0 * BIN4);
STATIC volatile CONST(SInt16, AUTOMATIC) VSCtl_tqLossTraExt_SatMin_C = (CONST(SInt16, AUTOMATIC))(-50 * BIN4);
#define VSINFO_STOP_SEC_CALIB_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define VSINFO_START_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraVirt1_spdVeh_T
[VSINFO_8_SIZE] = {
(UInt16)(8.203125 * BIN7), (UInt16)(5.3984375 * BIN7), (UInt16)(4 * BIN7),
(UInt16)(2.9765625 * BIN7), (UInt16)(2.3828125 * BIN7),
(UInt16)(2.3828125 * BIN7), (UInt16)(2.3828125 * BIN7),
(UInt16)(2.3828125 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rConvTraVirt2_spdVeh_T
[VSINFO_8_SIZE] = {
(UInt16)(14.453125 * BIN7), (UInt16)(8.203125 * BIN7),
(UInt16)(5.3984375 * BIN7), (UInt16)(4 * BIN7), (UInt16)(2.9765625 * BIN7),
(UInt16)(2.3828125 * BIN7), (UInt16)(2.3828125 * BIN7),
(UInt16)(2.3828125 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rConvTraVirt1_A[VSINFO_8_SIZE] = {
(UInt16)(41.0703125 * BIN7), (UInt16)(72.375 * BIN7),
(UInt16)(109.8984375 * BIN7), (UInt16)(148.3671875 * BIN7),
(UInt16)(199.1484375 * BIN7), (UInt16)(249.3515625 * BIN7),
(UInt16)(254 * BIN7), (UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_spdVeh_rConvTraVirt2_A[VSINFO_8_SIZE] = {
(UInt16)(41.0703125 * BIN7), (UInt16)(72.375 * BIN7),
(UInt16)(109.8984375 * BIN7), (UInt16)(148.3671875 * BIN7),
(UInt16)(199.1484375 * BIN7), (UInt16)(249.3515625 * BIN7),
(UInt16)(254 * BIN7), (UInt16)(255 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_rFilrConvTra_tirConvTra_T
[VSINFO_8_SIZE] = {
(UInt16)(100 * BIN7), (UInt16)(100 * BIN7),
(UInt16)(50 * BIN7), (UInt16)(30 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7),
(UInt16)(0 * BIN7), (UInt16)(0 * BIN7)
};

STATIC volatile CONST(UInt16, AUTOMATIC) VSCtl_tirConvTra_rFilrConvTra_A[VSINFO_8_SIZE] = {
(UInt16)(0 * BIN0), (UInt16)(10 * BIN0),
(UInt16)(20 * BIN0), (UInt16)(30 * BIN0),
(UInt16)(40 * BIN0), (UInt16)(50 * BIN0),
(UInt16)(60 * BIN0), (UInt16)(255 * BIN0)
};
#define VSINFO_STOP_SEC_CARTO_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define VSINFO_START_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) vsctl_rconvtravirt1_spdveh_t_sav;
STATIC VAR(t_dds_m_tab2d_sav, AUTOMATIC) vsctl_rconvtravirt2_spdveh_t_sav;
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) vsctl_rfilrconvtra_tirconvtra_t_sav;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1122221_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_f1122222_neng_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_f1122222_nfrnt_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1122222_sat_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1122224_first_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_f1122224_last_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1_s32, AUTOMATIC) vsinfo_f1122223_neng_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1122223_spdfrnt_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f1122223_sat_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f112231_filter_ptr;
STATIC VAR(t_dds_m_filter_lp1, AUTOMATIC) vsinfo_f112232_filter_ptr;
#define VSINFO_STOP_SEC_VAR_UNSPECIFIED
#include "VSInfo_MemMap.h"

/* 16_bits variable definition */
#define VSINFO_START_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt16, AUTOMATIC) vsinfo_f1122224_first_swicth_out;    /* BIN7 */
STATIC VAR(UInt16, AUTOMATIC) vsinfo_f1122224_first_filter_out;    /* BIN7 */
#define VSINFO_STOP_SEC_VAR_16BIT
#include "VSInfo_MemMap.h"

/* 8_bits variable definition */
#define VSINFO_START_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) vsinfo_strconvtramodclc_cpy;    /* BIN0 */
STATIC VAR(UInt8, AUTOMATIC) vsinfo_strconvtraextmodclc_cpy;
#define VSINFO_STOP_SEC_VAR_8BIT
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define VSINFO_START_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rFilrConvTra; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rConvTra_Ext; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rConvTra_no1; /* BIN7 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) VSCtl_rConvTra_no2; /* BIN7 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) VSCtl_tqLossTra_Ext; /* BIN4 */
#define VSINFO_STOP_SEC_INTERNAL_VAR_16BIT
#include "VSInfo_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define VSINFO_START_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"
STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) VSCTL_RCONVTRAVIRT1_SPDVEH_T_APT = {
&vsctl_rconvtravirt1_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rConvTraVirt1_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rConvTraVirt1_spdVeh_T[0]
};

STATIC CONST(t_dds_m_tab2d_u16_v2, AUTOMATIC) VSCTL_RCONVTRAVIRT2_SPDVEH_T_APT = {
&vsctl_rconvtravirt2_spdveh_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_spdVeh_rConvTraVirt2_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rConvTraVirt2_spdVeh_T[0]
};

STATIC CONST(t_dds_m_map2d_u16, AUTOMATIC) VSCTL_RFILRCONVTRA_TIRCONVTRA_T_APM = {
&vsctl_rfilrconvtra_tirconvtra_t_sav,
VSINFO_8_SIZE,
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_tirConvTra_rFilrConvTra_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&VSCtl_rFilrConvTra_tirConvTra_T[0]
};

#define VSINFO_STOP_SEC_CONST_UNSPECIFIED
#include "VSInfo_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define VSINFO_START_SEC_CODE
#include "VSInfo_MemMap.h"

/*******************************************************************************
* Runnables Definition
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122221_Determiner_Taux_Conversion_Couple_Externe(UInt16 copt_rcnvtq_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122222_Determiner_Taux_Conversion_Couple_Interne_1(UInt16 ext_neng_par, /* BIN0 */
                                                                                            UInt32 ext_nfrntwhl_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122223_Determiner_Taux_Conversion_Couple_Interne_2(UInt16 ext_neng_par, /* BIN0 */
                                                                                            UInt16 ext_spdfrntwhl_par, /* BIN7 */
                                                                                            UInt16 vsctl_rdwhl_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122224_Determiner_Taux_Conversion_Couple_Reference(
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_grdratconvtra_ptr, /* BIN1 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_rconvtra_ptr /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122225_Determiner_Taux_Conversion_Couple_Virtuel(UInt16 vsctl_spdveh_par /* BIN7 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F112231_Determiner_couple_Perte_BV_Externe(UInt16 tqcmp_tqcnvloss_par /* BIN4 */);

STATIC FUNC(void, AUTOMATIC) VSINFO_F112232_Determiner_couple_Perte_BV_Reference(
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqlosstra_ptr /* BIN4 */);

/*******************************************************************************
*
* Function Name : VSINFO_F112222_Determiner_Taux_Conversion_Couple
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F112222_Determiner_Taux_Conversion_Couple(
                                                    UInt16 Ext_nEng_swc_in, /* BIN0 */
                                                    UInt32 Ext_nFrntWhl_swc_in, /* BIN7 */
                                                    UInt16 Ext_spdFrntWhl_swc_in, /* BIN7 */
                                                    UInt16 CoPt_rCnvTq_swc_in, /* BIN7 */
                                                    UInt16 VSCtl_rdWhl_swc_in, /* BIN7 */
                                                    UInt16 VSCtl_spdVeh_swc_in, /* BIN7 */
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_grdRatConvTra_swc_out, /* BIN1 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rConvTra_swc_out /* BIN7 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.181.1 */
    vsinfo_strconvtramodclc_cpy = VSCtl_strConvTraModClc;
    vsinfo_strconvtraextmodclc_cpy = VSCtl_strConvTraExtModClc;

    VSINFO_F1122221_Determiner_Taux_Conversion_Couple_Externe(CoPt_rCnvTq_swc_in /* BIN7 */);

    VSINFO_F1122222_Determiner_Taux_Conversion_Couple_Interne_1(Ext_nEng_swc_in, /* BIN0 */
                                                                    Ext_nFrntWhl_swc_in /* BIN7 */);

    VSINFO_F1122223_Determiner_Taux_Conversion_Couple_Interne_2(Ext_nEng_swc_in, /* BIN0 */
                                                                    Ext_spdFrntWhl_swc_in, /* BIN7 */
                                                                    VSCtl_rdWhl_swc_in /* BIN7 */);

    VSINFO_F1122224_Determiner_Taux_Conversion_Couple_Reference(VSCtl_grdRatConvTra_swc_out, /* BIN1 */
                                                                    VSCtl_rConvTra_swc_out /* BIN7 */);

    VSINFO_F1122225_Determiner_Taux_Conversion_Couple_Virtuel(VSCtl_spdVeh_swc_in /* BIN7 */);
}

/*******************************************************************************
*
* Function Name : VSINFO_F11223_Determiner_Couple_Perte_BV
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_F11223_Determiner_Couple_Perte_BV(UInt16 TqCmp_tqCnvLoss_swc_in, /* BIN4 */
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqLossTra_swc_out /* BIN4 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.60.2 */
    vsinfo_strconvtramodclc_cpy = VSCtl_strConvTraModClc;
    vsinfo_strconvtraextmodclc_cpy = VSCtl_strConvTraExtModClc;
    VSINFO_F112231_Determiner_couple_Perte_BV_Externe(TqCmp_tqCnvLoss_swc_in /* BIN4 */);

    VSINFO_F112232_Determiner_couple_Perte_BV_Reference(VSCtl_tqLossTra_swc_out /* BIN4 */);
}
/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_F1122221_Determiner_Taux_Conversion_Couple_Externe
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1122221_Determiner_Taux_Conversion_Couple_Externe(UInt16 copt_rcnvtq_par /* BIN7 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.55.3 */
    UInt16 vsinfo_filter_in;
    UInt16 vsinfo_filter_out;

    /* BIN7 : [0;20] */
    vsinfo_filter_in = (UInt16)DDS_M_SATURATION_V2((UInt32)copt_rcnvtq_par,
                                                   (UInt32)VSCtl_rConvTraExt_SatMin_C,
                                                   (UInt32)VSCtl_rConvTraExt_SatMax_C);

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_rConvTraExt)
    {
        /* BIN7 : [0;20] */
        vsinfo_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122221_filter_ptr,
                                                            vsinfo_filter_in);
    }
    else
    {
    /* BIN7 : [0;20] */
        vsinfo_filter_out = DDS_M_FILTER_LP1_U16(&vsinfo_f1122221_filter_ptr,
                                                 vsinfo_filter_in,
                                                 VSCtl_tiFil_rConvTraExt_C,
                                                 BIN10);
    }

    if( (VSCTL_STRCONVTRAEXTMODCLC_ARRET == (UInt32)vsinfo_strconvtraextmodclc_cpy)  ||
        (VSCTL_STRCONVTRAEXTMODCLC_VERIF == (UInt32)vsinfo_strconvtraextmodclc_cpy)  ||
        (VSCTL_STRCONVTRAEXTMODCLC_DEFAULT == (UInt32)vsinfo_strconvtraextmodclc_cpy) )
    {
        VSCtl_rConvTra_Ext = (UInt16)VSC_20_BIN7;
    }
    else
    {
        VSCtl_rConvTra_Ext = (UInt16)DDS_M_MAX((UInt32)vsinfo_filter_out,VSCTL_RCONVTRA_MIN);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1122222_Determiner_Taux_Conversion_Couple_Interne_1
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) VSINFO_F1122222_Determiner_Taux_Conversion_Couple_Interne_1(UInt16 ext_neng_par, /* BIN0 */
                                                                                            UInt32 ext_nfrntwhl_par /* BIN7 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.56.1 */
    UInt32 vsinfo_neng_filter_out;    /* BIN7 */
    UInt32 vsinfo_nfrnt_filter_out;   /* BIN7 */
    UInt16 vsinfo_sat_filter_out; /* BIN7 */
    UInt16 vsinfo_sat_filter_in;  /* BIN7 */
    UInt32 vsinfo_num;
    UInt32 vsinfo_den;
    UInt32 vsinfo_temp_u32;
    UInt8 vsctl_bacvfil_rconvtraint1_cpy;
    UInt8 vsctl_strconvtraintno1modclc_cpy;

    vsctl_bacvfil_rconvtraint1_cpy = VSCtl_bAcvFil_rConvTraInt1;
    vsctl_strconvtraintno1modclc_cpy = VSCtl_strConvTraIntno1ModClc;

    /* calculate output of the two first filters */
    if((UInt32)DDS_FALSE == (UInt32)vsctl_bacvfil_rconvtraint1_cpy)
    {
        /* BIN7 = BIN0 * BIN7 */
        vsinfo_neng_filter_out = (UInt32)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122222_neng_filter_ptr,
                                                                   ((SInt32)ext_neng_par * BIN7));

        vsinfo_nfrnt_filter_out = (UInt32)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122222_nfrnt_filter_ptr,
                                                                    (SInt32)ext_nfrntwhl_par);

    }
    else
    {
        /* BIN7 = BIN0 * BIN7 */
        vsinfo_neng_filter_out = (UInt32)DDS_M_FILTER_LP1_S32(&vsinfo_f1122222_neng_filter_ptr,
                                                              ((SInt32)ext_neng_par * BIN7),
                                                              (UInt16)((UInt32)VSCtl_tiFil_nEng1_C * BIN5));

        vsinfo_nfrnt_filter_out = (UInt32)DDS_M_FILTER_LP1_S32(&vsinfo_f1122222_nfrnt_filter_ptr,
                                                                        (SInt32)ext_nfrntwhl_par,
                                                                        /* BIN15 = BIN10 * BIN5 */
                                                                        (UInt16)((UInt32)VSCtl_tiFil_nFrntWhl_C * BIN5));
    }

    /* calculate input of the last filter */
    if(VSC_NOMINAL_5 != (UInt32)vsctl_strconvtraintno1modclc_cpy)
    {
        vsinfo_sat_filter_in = (UInt16)DDS_M_SATURATION_V2(VSC_20_BIN7,
                                                                (UInt32)VSCtl_rConvTraInt_SatMin_C,
                                                                (UInt32)VSCtl_rConvTraInt_SatMax_C);
    }
    else
    {
        vsinfo_num = DDS_M_SATURATION_V2(vsinfo_neng_filter_out,
                                         VSCtl_nEng_SatMin_C,
                                         VSCtl_nEng_SatMax_C);

        vsinfo_den = DDS_M_MAX(vsinfo_nfrnt_filter_out,
                               VSCtl_nFrntWhlFil_SatMin_C);

        if(0 != vsinfo_den)
        {
            /* BIN7 = (BIN7 * BIN7) / BIN7 */
            vsinfo_temp_u32 = (vsinfo_num * BIN7) / vsinfo_den;
        }
        else
        {
            vsinfo_temp_u32 = DDS_UINT32_MAX;
        }
        vsinfo_sat_filter_in = (UInt16)DDS_M_SATURATION_V2(vsinfo_temp_u32,
                                                           (UInt32)VSCtl_rConvTraInt_SatMin_C,
                                                           (UInt32)VSCtl_rConvTraInt_SatMax_C);
    }

    /* calculate output of the last filter */
    if((UInt32)DDS_FALSE == (UInt32)vsctl_bacvfil_rconvtraint1_cpy)
    {
        vsinfo_sat_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122222_sat_filter_ptr,
                                                          vsinfo_sat_filter_in);
    }
    else
    {
        vsinfo_sat_filter_out = DDS_M_FILTER_LP1_U16(&vsinfo_f1122222_sat_filter_ptr,
                                                     vsinfo_sat_filter_in,
                                                     VSCtl_tiFil_rConvTraInt_no1_C,
                                                     BIN10);
    }

    /* calulate output */
    if( (VSC_INIT_5 == (UInt32)vsctl_strconvtraintno1modclc_cpy)    ||
        (VSC_NOMINAL_5 == (UInt32)vsctl_strconvtraintno1modclc_cpy))
    {
        VSCtl_rConvTra_no1 = (UInt16)DDS_M_MAX((UInt32)vsinfo_sat_filter_out,VSCTL_RCONVTRA_MIN);
    }
    else
    {
        VSCtl_rConvTra_no1 = (UInt16)VSC_20_BIN7;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1122223_Determiner_Taux_Conversion_Couple_Interne_2
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122223_Determiner_Taux_Conversion_Couple_Interne_2(UInt16 ext_neng_par, /* BIN0 */
                                                                                            UInt16 ext_spdfrntwhl_par, /* BIN7 */
                                                                                            UInt16 vsctl_rdwhl_par /* BIN7 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.57.2 */
    UInt32 vsinfo_f1122223_neng_filter_out;    /* BIN7 */
    UInt32 vsinfo_f1122223_spdfrnt_filter_out; /* BIN7 */
    UInt16 vsinfo_f1122223_sat_filter_out; /* BIN7 */
    UInt16 vsinfo_f1122223_sat_filter_in;  /* BIN7 */
    UInt32 vsinfo_f1122223_num;
    UInt32 vsinfo_f1122223_den;
    UInt32 vsinfo_temp_u32;
    SInt8 vsinfo_nb_shift;
    UInt8 vsctl_bacvfil_rconvtraint2_cpy;
    UInt8 vsctl_strconvtraintno2modclc_cpy;

    vsctl_bacvfil_rconvtraint2_cpy = VSCtl_bAcvFil_rConvTraInt2;
    vsctl_strconvtraintno2modclc_cpy = VSCtl_strConvTraIntno2ModClc;

    /* calculate output of the two first filters */
    if((UInt32)DDS_FALSE == (UInt32)vsctl_bacvfil_rconvtraint2_cpy)
    {
        /* BIN7 = BIN0 * BIN7 */
        vsinfo_f1122223_neng_filter_out = (UInt32)DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122223_neng_filter_ptr,
                                                                            ((SInt32)ext_neng_par * BIN7));

        vsinfo_f1122223_spdfrnt_filter_out = (UInt32)DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122223_spdfrnt_filter_ptr,
                                                                            ext_spdfrntwhl_par);

    }
    else
    {
        /* BIN7 = BIN0 * BIN7 */
        vsinfo_f1122223_neng_filter_out = (UInt32)DDS_M_FILTER_LP1_S32(&vsinfo_f1122223_neng_filter_ptr,
                                                                       ((SInt32)ext_neng_par * BIN7),
                                                                       (UInt16)((UInt32)VSCtl_tiFil_nEng2_C * BIN5));

        vsinfo_f1122223_spdfrnt_filter_out = (UInt32)DDS_M_FILTER_LP1_U16(&vsinfo_f1122223_spdfrnt_filter_ptr,
                                                                        ext_spdfrntwhl_par,
                                                                        VSCtl_tiFil_spdFrntWhl_C,
                                                                        BIN10);
    }

    /* calculate input of the last filter */
    if(VSC_NOMINAL_6 != (UInt32)vsctl_strconvtraintno2modclc_cpy)
    {
        vsinfo_f1122223_sat_filter_in = (UInt16)DDS_M_SATURATION_V2(VSC_20_BIN7,
                                                                (UInt32)VSCtl_rConvTraInt_SatMin_C,
                                                                (UInt32)VSCtl_rConvTraInt_SatMax_C);
    }
    else
    {
        vsinfo_f1122223_num = DDS_M_SATURATION_V2(vsinfo_f1122223_neng_filter_out,
                                                VSCtl_nEng_SatMin_C,
                                                VSCtl_nEng_SatMax_C);

        /* BIN7 = [0;10000]BIN7 * 2.6526 / [0.0078125;10]BIN7 */
        /* vsinfo_f1122223_den = (vsinfo_f1122223_spdfrnt_filter_out * (26526 / 10000)) / vsctl_rdwhl_par */
        /* vsinfo_f1122223_den = (vsinfo_f1122223_spdfrnt_filter_out * (13263 / 5000)) / vsctl_rdwhl_par */
        /* vsinfo_f1122223_den = (vsinfo_f1122223_spdfrnt_filter_out * 13263) / (vsctl_rdwhl_par  * 5000) */
        vsinfo_nb_shift = 7;
        vsinfo_f1122223_den = DDS_M_DYNAMIC_MULT_U32(vsinfo_f1122223_spdfrnt_filter_out,
                                                    (UInt32)13263,
                                                    &vsinfo_nb_shift);

        /* [39.0625;50000]BIN7 = [0.0078125;10]BIN7 * 5000 */
        vsinfo_temp_u32 = (UInt32)vsctl_rdwhl_par * 5000;

        vsinfo_f1122223_den = DDS_M_DYNAMIC_DIV_U32(vsinfo_f1122223_den,
                                                    vsinfo_temp_u32,
                                                    vsinfo_nb_shift,
                                                    7,
                                                    12);

        vsinfo_f1122223_den = DDS_M_MAX(vsinfo_f1122223_den,
                                        /* BIN12 = BIN7 * BIN5 */
                                        VSCtl_nFrntWhlFil_SatMin_C * BIN5);

        if(0 != vsinfo_f1122223_den)
        {
            /* BIN7 = (BIN7 * BIN12) / BIN12 */
            vsinfo_temp_u32 = (vsinfo_f1122223_num * BIN12) / vsinfo_f1122223_den;
        }
        else
        {
            vsinfo_temp_u32 = DDS_UINT32_MAX;
        }
        vsinfo_f1122223_sat_filter_in = (UInt16)DDS_M_SATURATION_V2(vsinfo_temp_u32,
                                                                    (UInt32)VSCtl_rConvTraInt_SatMin_C,
                                                                    (UInt32)VSCtl_rConvTraInt_SatMax_C);
    }

    /* calculate output of the last filter */
    if((UInt32)DDS_FALSE == (UInt32)vsctl_bacvfil_rconvtraint2_cpy)
    {
        vsinfo_f1122223_sat_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122223_sat_filter_ptr,
                                                            vsinfo_f1122223_sat_filter_in);
    }
    else
    {
        vsinfo_f1122223_sat_filter_out = DDS_M_FILTER_LP1_U16(&vsinfo_f1122223_sat_filter_ptr,
                                                        vsinfo_f1122223_sat_filter_in,
                                                        VSCtl_tiFil_rConvTraInt_no2_C,
                                                        BIN10);
    }

    /* calulate output */
    if( (VSC_INIT_6 == (UInt32)vsctl_strconvtraintno2modclc_cpy)    ||
        (VSC_NOMINAL_6 == (UInt32)vsctl_strconvtraintno2modclc_cpy))
    {
        VSCtl_rConvTra_no2 = (UInt16)DDS_M_MAX((UInt32)vsinfo_f1122223_sat_filter_out,VSCTL_RCONVTRA_MIN);
    }
    else
    {
        VSCtl_rConvTra_no2 = (UInt16)VSC_20_BIN7;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1122224_Determiner_Taux_Conversion_Couple_Reference
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122224_Determiner_Taux_Conversion_Couple_Reference(
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_grdratconvtra_ptr, /* BIN1 */
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) vsctl_rconvtra_ptr /* BIN7 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.58.1 */
    UInt16 vsinfo_out_barycentre;  /* BIN10 */
    SInt32 vsinfo_last_filter_in; /* BIN7 */
    SInt32 vsinfo_last_filter_out; /* BIN7 */
    SInt32 vsinfo_first_filter_out_prev;
    UInt8 vsctl_bacvfiltrainfo_cpy;

    vsctl_bacvfiltrainfo_cpy = VSCtl_bAcvFilTraInfo;

    switch((UInt32)vsinfo_strconvtramodclc_cpy)
    {
        case (UInt32)VSCTL_STRCONVTRAMODCLC_INIT :
        case (UInt32)VSCTL_STRCONVTRAMODCLC_DEFAULT :
            /* DO NOTHING */
            break;

        case (UInt32)VSCTL_STRCONVTRAMODCLC_EXTERNE :
            vsinfo_f1122224_first_swicth_out = VSCtl_rConvTra_Ext;
            break;

        case (UInt32)VSCTL_STRCONVTRAMODCLC_1_INTERNE :
            vsinfo_f1122224_first_swicth_out = VSCtl_rConvTra_no1;
            break;

        case (UInt32)VSCTL_STRCONVTRAMODCLC_2_INTERNE :
            vsinfo_f1122224_first_swicth_out = VSCtl_rConvTra_no2;
            break;

        case (UInt32)VSCTL_STRCONVTRAMODCLC_ARRET :
        case (UInt32)VSCTL_STRCONVTRAMODCLC_VERIF :
        default :
            vsinfo_f1122224_first_swicth_out = (UInt16)VSC_20_BIN7;
            break;
    }

    /* Calculate numeric filter value of the first filter */
    VSCtl_rFilrConvTra = DDS_M_MAP2D_U16(&VSCTL_RFILRCONVTRA_TIRCONVTRA_T_APM,
                                            VSCtl_tirConvTra);

    vsinfo_out_barycentre = (UInt16)DDS_M_BARY_FILTER_S16_V2((SInt16)VSCtl_tiFil_FilMaxrConvTra_C,
                                                        (SInt16)VSCtl_tiFil_FilMinrConvTra_C,
                                                        (SInt16)VSCtl_rFilrConvTra,
                                                        (UInt16)(100 * BIN7));

    /* Calculate first lowpass filter */
    vsinfo_first_filter_out_prev = (SInt32)vsinfo_f1122224_first_filter_out;
    if((UInt32)DDS_FALSE == (UInt32)vsctl_bacvfiltrainfo_cpy)
    {
        vsinfo_f1122224_first_filter_out = DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122224_first_filter_ptr,
                                                                    vsinfo_f1122224_first_swicth_out);
    }
    else
    {
        vsinfo_f1122224_first_filter_out = DDS_M_FILTER_LP1_U16(&vsinfo_f1122224_first_filter_ptr,
                                                                vsinfo_f1122224_first_swicth_out,
                                                                vsinfo_out_barycentre,
                                                                BIN10);
    }

    /* Calculate last lowpass filter */
    /* [-1990;1990]BIN7 = (([0.1;20]BIN7 - [0.1;20]BIN7) * DEC3) / (0.01 * DEC3) */
    vsinfo_last_filter_in =   (((SInt32)vsinfo_f1122224_first_filter_out - vsinfo_first_filter_out_prev) * DEC3)
                                  / (SInt32)VSINFO_SCHEDULING_10MS;

    if((UInt32)DDS_FALSE == (UInt32)vsctl_bacvfiltrainfo_cpy)
    {
        vsinfo_last_filter_out = DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122224_last_filter_ptr,
                                                           vsinfo_last_filter_in);
    }
    else
    {
        vsinfo_last_filter_out = DDS_M_FILTER_LP1_S32(&vsinfo_f1122224_last_filter_ptr,
                                                      vsinfo_last_filter_in,
                                                      /* BIN15 = BIN10 * BIN5*/
                                                      (UInt16)((UInt32)VSCtl_tiFil_grdRatConvTra_C * BIN5));
    }

    if( (VSCTL_STRCONVTRAMODCLC_ARRET == (UInt32)vsinfo_strconvtramodclc_cpy)   ||
        (VSCTL_STRCONVTRAMODCLC_VERIF == (UInt32)vsinfo_strconvtramodclc_cpy) )
    {
        *vsctl_rconvtra_ptr = (UInt16)VSC_20_BIN7;
        *vsctl_grdratconvtra_ptr = (SInt16)0;
    }
    else
    {
        *vsctl_rconvtra_ptr = vsinfo_f1122224_first_filter_out;
        /* BIN1 = BIN7 / BIN6 */
        *vsctl_grdratconvtra_ptr = (SInt16)(vsinfo_last_filter_out / BIN6);
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F1122225_Determiner_Taux_Conversion_Couple_Virtuel
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSINFO_F1122225_Determiner_Taux_Conversion_Couple_Virtuel(UInt16 vsctl_spdveh_par /* BIN7 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.59.1 */
    if( (VSCTL_STRCONVTRAMODCLC_EXTERNE == (UInt32)vsinfo_strconvtramodclc_cpy)   ||
        (VSCTL_STRCONVTRAMODCLC_1_INTERNE == (UInt32)vsinfo_strconvtramodclc_cpy)  ||
        (VSCTL_STRCONVTRAMODCLC_2_INTERNE == (UInt32)vsinfo_strconvtramodclc_cpy)  )
    {
        VSCtl_rConvTraVirt_no1 = DDS_M_TAB2D_U16_V2(&VSCTL_RCONVTRAVIRT1_SPDVEH_T_APT,
                                                    vsctl_spdveh_par);

        VSCtl_rConvTraVirt_no2 = DDS_M_TAB2D_U16_V2(&VSCTL_RCONVTRAVIRT2_SPDVEH_T_APT,
                                                    vsctl_spdveh_par);
    }
    else
    {
        VSCtl_rConvTraVirt_no1 = (UInt16)VSC_20_BIN7;
        VSCtl_rConvTraVirt_no2 = (UInt16)VSC_20_BIN7;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F112231_Determiner_couple_Perte_BV_Externe
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSINFO_F112231_Determiner_couple_Perte_BV_Externe(UInt16 tqcmp_tqcnvloss_par /* BIN4 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.61.2 */
    SInt16 vsinfo_f112231_filter_in;
    SInt16 vsinfo_f112231_filter_out;

    vsinfo_f112231_filter_in = (SInt16)DDS_M_SATURATION_V2(-(SInt32)tqcmp_tqcnvloss_par,
                                                        (SInt32)VSCtl_tqLossTraExt_SatMin_C,
                                                        (SInt32)VSCtl_tqLossTraExt_SatMax_C);

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFil_rConvTraExt)
    {
        vsinfo_f112231_filter_out = DDS_M_FILTER_LP1_S16_INIT(&vsinfo_f112231_filter_ptr,
                                                            vsinfo_f112231_filter_in);
    }
    else
    {
        vsinfo_f112231_filter_out = DDS_M_FILTER_LP1_S16(&vsinfo_f112231_filter_ptr,
                                                        vsinfo_f112231_filter_in,
                                                        VSCtl_tiFil_rConvTraExt_C,
                                                        BIN10);
    }

    if( (VSCTL_STRCONVTRAEXTMODCLC_ARRET == (UInt32)vsinfo_strconvtraextmodclc_cpy)  ||
        (VSCTL_STRCONVTRAEXTMODCLC_VERIF == (UInt32)vsinfo_strconvtraextmodclc_cpy)  ||
        (VSCTL_STRCONVTRAEXTMODCLC_DEFAULT == (UInt32)vsinfo_strconvtraextmodclc_cpy) )
    {
        VSCtl_tqLossTra_Ext = (SInt16)0;
    }
    else
    {
        VSCtl_tqLossTra_Ext = vsinfo_f112231_filter_out;
    }
}

/*******************************************************************************
*
* Function Name : VSINFO_F112232_Determiner_couple_Perte_BV_Reference
* Description :
*
*******************************************************************************/

STATIC FUNC(void, AUTOMATIC) VSINFO_F112232_Determiner_couple_Perte_BV_Reference(
                                            CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) vsctl_tqlosstra_ptr /* BIN4 */)
{
    /* SSTG REQ_TAG CSMT_CGMT08_2268.FR.63.1 */
    SInt16 vsinfo_f112232_filter_in;
    SInt16 vsinfo_f112232_filter_out;
    UInt16 vsinfo_f112232_filter_gain;

    if(VSCTL_STRCONVTRAMODCLC_EXTERNE == (UInt32)vsinfo_strconvtramodclc_cpy)
    {
        vsinfo_f112232_filter_in = VSCtl_tqLossTra_Ext;
    }
    else
    {
        vsinfo_f112232_filter_in = (SInt16)0;
    }

    vsinfo_f112232_filter_gain = (UInt16)DDS_M_BARY_FILTER_S16_V2((SInt16)VSCtl_tiFil_FilMaxrConvTra_C,
                                                            (SInt16)VSCtl_tiFil_FilMinrConvTra_C,
                                                            (SInt16)VSCtl_rFilrConvTra,
                                                            (UInt16)(100 * BIN7));

    if((UInt32)DDS_FALSE == (UInt32)VSCtl_bAcvFilTraInfo)
    {
        vsinfo_f112232_filter_out = DDS_M_FILTER_LP1_S16_INIT(&vsinfo_f112232_filter_ptr,
                                                            vsinfo_f112232_filter_in);
    }
    else
    {
        vsinfo_f112232_filter_out = DDS_M_FILTER_LP1_S16(&vsinfo_f112232_filter_ptr,
                                                        vsinfo_f112232_filter_in,
                                                        vsinfo_f112232_filter_gain,
                                                        BIN10);
    }

    if( (VSCTL_STRCONVTRAMODCLC_EXTERNE == (UInt32)vsinfo_strconvtramodclc_cpy)   ||
        (VSCTL_STRCONVTRAMODCLC_1_INTERNE == (UInt32)vsinfo_strconvtramodclc_cpy) ||
        (VSCTL_STRCONVTRAMODCLC_2_INTERNE == (UInt32)vsinfo_strconvtramodclc_cpy) ||
        (VSCTL_STRCONVTRAMODCLC_DEFAULT == (UInt32)vsinfo_strconvtramodclc_cpy)    )
    {
        *vsctl_tqlosstra_ptr = vsinfo_f112232_filter_out;
    }
    else
    {
        *vsctl_tqlosstra_ptr = (SInt16)0;
    }
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : VSINFO_Info_Transmission_Sl_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) VSINFO_Info_Transmission_Sl_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_grdRatConvTra_swc_out, /* BIN1 */
                                                 CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) VSCtl_rConvTra_swc_out, /* BIN7 */
                                                 CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) VSCtl_tqLossTra_swc_out /* BIN4 */)
{
    /* ---- Init Outputs ---- */
    VSCtl_rConvTraVirt_no1 = (UInt16)VSC_20_BIN7;
    VSCtl_rConvTraVirt_no2 = (UInt16)VSC_20_BIN7;
    *VSCtl_grdRatConvTra_swc_out = (SInt16)(0 * BIN1);
    *VSCtl_rConvTra_swc_out = (UInt16)VSC_20_BIN7;
    *VSCtl_tqLossTra_swc_out = (SInt16)(0 * BIN4);

    /* ---- Init Global Datas ---- */
    vsinfo_f1122224_first_swicth_out = (UInt16)VSC_20_BIN7;
    vsinfo_f1122224_first_filter_out = (UInt16)0;
    VSCtl_rFilrConvTra = (UInt16)(0 * BIN7);
    VSCtl_rConvTra_Ext = (UInt16)VSC_20_BIN7;
    VSCtl_rConvTra_no1 = (UInt16)VSC_20_BIN7;
    VSCtl_rConvTra_no2 = (UInt16)VSC_20_BIN7;
    VSCtl_tqLossTra_Ext = (SInt16)(0 * BIN4);

    /* Filter init */
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122221_filter_ptr,0);
    DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122222_neng_filter_ptr,0);
    DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122222_nfrnt_filter_ptr,0);
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122222_sat_filter_ptr,0);
    DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122223_neng_filter_ptr,0);
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122223_sat_filter_ptr,0);
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122223_spdfrnt_filter_ptr,0);
    DDS_M_FILTER_LP1_U16_INIT(&vsinfo_f1122224_first_filter_ptr,0);
    DDS_M_FILTER_LP1_S32_INIT(&vsinfo_f1122224_last_filter_ptr,0);
    DDS_M_FILTER_LP1_S16_INIT(&vsinfo_f112231_filter_ptr,0);
    DDS_M_FILTER_LP1_S16_INIT(&vsinfo_f112232_filter_ptr,0);

    /* Local data */
    vsinfo_strconvtramodclc_cpy = 0;
    vsinfo_strconvtraextmodclc_cpy = 0;
}

#define VSINFO_STOP_SEC_CODE
#include "VSInfo_MemMap.h"

