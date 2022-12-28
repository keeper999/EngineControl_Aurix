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
* Ref X:\integration_view_00PSASWC_E413D01\blois_psa_sstg\Software\Appli\TqDem\src\TQDEM_Coord_Xvv.c
* Version int :/main/L03_01/2 Date: 17/7/2012 15 h 48 m User:posmyk 
*    TWK_model:TQDEM_Coord_Xvv_L03_010_IMPL1_D
*    comments :add INLINE for static functions
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 3/7/2012 17 h 12 m User:lemort 
*    TWK_model:TQDEM_Coord_Xvv_L03_010_IMPL1_D
*    comments :add INLINE for static functions
* Version int :/main/L03_01/1 Date: 10/3/2011 11 h 46 m User:esnault
*    TWK_model:TQDEM_Coord_Xvv_L03_010_IMPL1
*    comments :New specification: CSMT_CGMT06_2026_v3_1
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 1/3/2011 10 h 23 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L03_010_IMPL1
*    comments :New specification: CSMT_CGMT06_2026_v3_1
* Version int :/main/L02_01/2 Date: 8/10/2010 16 h 31 m User:meme
*    TWK_model:TQDEM_Coord_Xvv_L02_011_IMPL1
*    comments :Error File
* Version dev :\main\branch_salmane_tqdem_e6_dev\1 Date: 9/9/2010 11 h 39 m User:salmane
*    TWK_model:TQDEM_Coord_Xvv_L02_011_IMPL1
*    comments :Error File
* Version int :/main/L02_01/1 Date: 1/9/2010 14 h 5 m User:esnault
*    TWK_model:TQDEM_Coord_Xvv_L02_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\2 Date: 12/8/2010 10 h 7 m User:lemort
*    TWK_model:TQDEM_Coord_Xvv_L02_010_IMPL1
*    comments :for TqDem E6
* Version dev :\main\branch_lemort_dev_tqdem\1 Date: 26/7/2010 17 h 2 m User:lemort
*    TWK_model:TQDEM_Coord_Xvv_L02_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_demezil_tqdem_dev\2 Date: 19/7/2010 9 h 59 m User:demezil
*    TWK_model:TQDEM_Coord_Xvv_L02_010_IMPL1
*    comments :for TqDem e6 spec CSMT_CGMT06_2026_v3_0
* Version dev :\main\branch_demezil_tqdem_dev\1 Date: 17/6/2010 16 h 51 m User:demezil
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2_D
*    comments :QAC and code shaker e6 pass
* Version int :/main/L01_01/3 Date: 16/9/2009 10 h 44 m User:langendorf
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2_D
*    comments :work in progress
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 25/8/2009 11 h 14 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2_D
*    comments :work in progress
* Version dev :\main\branch_moisan_tqdem_dev\1 Date: 17/8/2009 10 h 13 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2_D
*    comments :Correct QAC warning for xVV 3.0
* Version int :/main/L01_01/2 Date: 10/10/2008 10 h 49 m User:boucher
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2
*    comments :Error with PFlt_MemMap.
* Version dev :\main\branch_moisan_tqdem_dev\8 Date: 23/9/2008 12 h 31 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2
*    comments :Error with PFlt_MemMap.
* Version dev :\main\branch_moisan_tqdem_dev\7 Date: 23/9/2008 12 h 28 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2
*    comments :*covsctl_staccp_ptr need to be save
* Version dev :\main\branch_moisan_tqdem_dev\6 Date: 18/9/2008 14 h 34 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2
*    comments :correction of initialisation of CoVSCtl_rAccPTra
* Version dev :\main\branch_moisan_tqdem_dev\5 Date: 18/9/2008 12 h 38 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL2
*    comments :Tracking sheet back (CoVSCtl_AccPThd1Hyst) + Fail correction
* Version dev :\main\branch_moisan_tqdem_dev\4 Date: 5/9/2008 16 h 39 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL1
*    comments :New warning QAC....
* Version dev :\main\branch_moisan_tqdem_dev\3 Date: 4/9/2008 9 h 45 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL1
*    comments :Correct wrong requirement
* Version dev :\main\branch_moisan_tqdem_dev\2 Date: 27/8/2008 14 h 14 m User:moisan
*    TWK_model:TQDEM_Coord_Xvv_L01_010_IMPL1
*    comments :First implementation for TqDem E PSA SSTG
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "dds_lib.h"
#include "TqDem.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define COVSCTL_STACCP_PIED_LEVE        (UInt32)(0 * BIN0)
#define COVSCTL_STACCP_PIED_POSE        (UInt32)(1 * BIN0)
#define COVSCTL_STACCP_PIED_A_FOND      (UInt32)(2 * BIN0)

#define PEDALE_PUSH_SPORT               (UInt32)(0 * BIN0)

#define COVSCTL_RACCPTHD_X_HYST_MIN     (SInt32)(0 * BIN4)
#define COVSCTL_RACCPTHD_X_HYST_MAX     (SInt32)(25 * BIN4)

#define COVSCTL_RACCPTHD_3_HYST_MIN     (SInt32)(75 * BIN4)
#define COVSCTL_RACCPTHD_3_HYST_MAX     (SInt32)(100 * BIN4)


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
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPThd1_C = (CONST(UInt16, AUTOMATIC))(7 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPThd1Hyst_C = (CONST(UInt16, AUTOMATIC))(2 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPThd3_C = (CONST(UInt16, AUTOMATIC))(75 * BIN4);
STATIC volatile CONST(UInt16, AUTOMATIC) CoVSCtl_rAccPThd3Hyst_C = (CONST(UInt16, AUTOMATIC))(5 * BIN4);
#define TQDEM_STOP_SEC_CALIB_16BIT
#include "TqDem_MemMap.h"


/* 8-bits scalar calibration definition */
#define TQDEM_START_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) CoVSCtl_stAcvAccPTra_C = DDS_FALSE;
_DDS_STATIC_ volatile CONST(UInt8, AUTOMATIC) CoVSCtl_stAcvAccPEng_C = DDS_FALSE;

#define TQDEM_STOP_SEC_CALIB_8BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 32-bits variable definition */
#define TQDEM_START_SEC_VAR_32BIT
#include "TqDem_MemMap.h"
STATIC VAR(UInt32, AUTOMATIC) tqdem_f01_02_01_state;
#define TQDEM_STOP_SEC_VAR_32BIT
#include "TqDem_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQDEM_START_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) CoVSCtl_rAccPThd1Hyst; /* BIN4 */
_DDS_STATIC_ VAR(UInt16, AUTOMATIC) CoVSCtl_rAccPThd3Hyst; /* BIN4 */
#define TQDEM_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqDem_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQDEM_START_SEC_CODE
#include "TqDem_MemMap.h"

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_01_Determiner_couple(SInt16 tqdem_tqckefc_par, /* BIN4 */
                                                        SInt16 vsctl_tqckefcminreq_par, /* BIN4 */
                                                        SInt16 vsctl_tqckefcmaxreq_par, /* BIN4 */
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) covsctl_tqefcreq_ptr /* BIN4 */);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_Limiter_pedales(UInt16 tqdem_raccpsptmod_par, /* BIN7 */
                                                    UInt16 accp_raccp_par, /* BIN7 */
                                                    UInt16 vsctl_raccpengmax_par, /* BIN7 */
                                                    UInt16 vsctl_raccpengmin_par, /* BIN7 */
                                                    UInt16 vsctl_raccptramax_par, /* BIN7 */
                                                    UInt16 vsctl_raccptramin_par, /* BIN7 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccpeng_ptr, /* BIN7 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccptra_ptr, /* BIN7 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) covsctl_staccp_ptr );

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_02_Coordonner_pedale(UInt16 tqdem_raccpsptmod_par, /* BIN7 */
                                                            UInt16 accp_raccp_par, /* BIN7 */
                                                            UInt16 vsctl_raccpengmax_par, /* BIN7 */
                                                            UInt16 vsctl_raccpengmin_par, /* BIN7 */
                                                            UInt16 vsctl_raccptramax_par, /* BIN7 */
                                                            UInt16 vsctl_raccptramin_par, /* BIN7 */
                                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccpeng_ptr, /* BIN7 */
                                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccptra_ptr /* BIN7 */);

INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_01_Determiner_etat_pedale(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) covsctl_staccp_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQDEM_Coord_Xvv
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Coord_Xvv(SInt16 TqDem_tqCkEfc_swc_in, /* BIN4 */
                                           UInt16 TqDem_rAccPSptMod_swc_in, /* BIN7 */
                                           UInt16 AccP_rAccP_swc_in, /* BIN7 */
                                           SInt16 VSCtl_tqCkEfcMinReq_swc_in, /* BIN4 */
                                           SInt16 VSCtl_tqCkEfcMaxReq_swc_in, /* BIN4 */
                                           UInt16 VSCtl_rAccPEngMax_swc_in, /* BIN7 */
                                           UInt16 VSCtl_rAccPEngMin_swc_in, /* BIN7 */
                                           UInt16 VSCtl_rAccPTraMax_swc_in, /* BIN7 */
                                           UInt16 VSCtl_rAccPTraMin_swc_in, /* BIN7 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_tqEfcReq_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEng_swc_out, /* BIN7 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPTra_swc_out, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoVSCtl_stAccP_swc_out )
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2026.FR.1.1 */
    TQDEM_F01_01_Determiner_couple(TqDem_tqCkEfc_swc_in, /* BIN4 */
                                VSCtl_tqCkEfcMinReq_swc_in, /* BIN4 */
                                VSCtl_tqCkEfcMaxReq_swc_in, /* BIN4 */
                                CoVSCtl_tqEfcReq_swc_out /* BIN4 */);

    TQDEM_F01_02_Limiter_pedales(TqDem_rAccPSptMod_swc_in, /* BIN7 */
                            AccP_rAccP_swc_in, /* BIN7 */
                            VSCtl_rAccPEngMax_swc_in, /* BIN7 */
                            VSCtl_rAccPEngMin_swc_in, /* BIN7 */
                            VSCtl_rAccPTraMax_swc_in, /* BIN7 */
                            VSCtl_rAccPTraMin_swc_in, /* BIN7 */
                            CoVSCtl_rAccPEng_swc_out, /* BIN7 */
                            CoVSCtl_rAccPTra_swc_out, /* BIN7 */
                            CoVSCtl_stAccP_swc_out );
}

/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : F01_01_Determiner_couple
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_01_Determiner_couple(SInt16 tqdem_tqckefc_par, /* BIN4 */
                                                        SInt16 vsctl_tqckefcminreq_par, /* BIN4 */
                                                        SInt16 vsctl_tqckefcmaxreq_par, /* BIN4 */
                                                        CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) covsctl_tqefcreq_ptr /* BIN4 */)
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2026.FR.2.1 */
    *covsctl_tqefcreq_ptr = (SInt16)DDS_M_SATURATION_V2((SInt32)tqdem_tqckefc_par,
                                                        (SInt32)vsctl_tqckefcminreq_par,
                                                        (SInt32)vsctl_tqckefcmaxreq_par);
}

/*******************************************************************************
*
* Function Name : F01_02_Limiter_pedales
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_Limiter_pedales(UInt16 tqdem_raccpsptmod_par, /* BIN7 */
                                                    UInt16 accp_raccp_par, /* BIN7 */
                                                    UInt16 vsctl_raccpengmax_par, /* BIN7 */
                                                    UInt16 vsctl_raccpengmin_par, /* BIN7 */
                                                    UInt16 vsctl_raccptramax_par, /* BIN7 */
                                                    UInt16 vsctl_raccptramin_par, /* BIN7 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccpeng_ptr, /* BIN7 */
                                                    CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccptra_ptr, /* BIN7 */
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) covsctl_staccp_ptr )
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2026.FR.3.0 */
    TQDEM_F01_02_02_Coordonner_pedale(tqdem_raccpsptmod_par, /* BIN7 */
                                accp_raccp_par, /* BIN7 */
                                vsctl_raccpengmax_par, /* BIN7 */
                                vsctl_raccpengmin_par, /* BIN7 */
                                vsctl_raccptramax_par, /* BIN7 */
                                vsctl_raccptramin_par, /* BIN7 */
                                covsctl_raccpeng_ptr, /* BIN7 */
                                covsctl_raccptra_ptr /* BIN7 */);

    TQDEM_F01_02_01_Determiner_etat_pedale(*covsctl_raccpeng_ptr, /* BIN7 */
                                        covsctl_staccp_ptr);
}

/*******************************************************************************
*
* Function Name : F01_02_02_Coordonner_pedale
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_02_Coordonner_pedale(UInt16 tqdem_raccpsptmod_par, /* BIN7 */
                                                            UInt16 accp_raccp_par, /* BIN7 */
                                                            UInt16 vsctl_raccpengmax_par, /* BIN7 */
                                                            UInt16 vsctl_raccpengmin_par, /* BIN7 */
                                                            UInt16 vsctl_raccptramax_par, /* BIN7 */
                                                            UInt16 vsctl_raccptramin_par, /* BIN7 */
                                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccpeng_ptr, /* BIN7 */
                                                            CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) covsctl_raccptra_ptr /* BIN7 */)
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2026.FR.4.0 */
    UInt32 out_switch;  /* BIN7 */
    SInt32 temp_s32;


    if(PEDALE_PUSH_SPORT == (UInt32)CoVSCtl_stAcvAccPEng_C)
    {
        *covsctl_raccpeng_ptr = (UInt16)DDS_M_SATURATION_V2((UInt32)tqdem_raccpsptmod_par,
                                                            (UInt32)vsctl_raccpengmin_par,
                                                            (UInt32)vsctl_raccpengmax_par);
    }
    else
    {
        *covsctl_raccpeng_ptr = (UInt16)DDS_M_SATURATION_V2((UInt32)accp_raccp_par,
                                                            (UInt32)vsctl_raccpengmin_par,
                                                            (UInt32)vsctl_raccpengmax_par);
    }

    if(PEDALE_PUSH_SPORT == (UInt32)CoVSCtl_stAcvAccPTra_C)
    {
        out_switch = DDS_M_SATURATION_V2((UInt32)tqdem_raccpsptmod_par,
                                            (UInt32)vsctl_raccpengmin_par,
                                            (UInt32)vsctl_raccpengmax_par);
    }
    else
    {
        out_switch = DDS_M_SATURATION_V2((UInt32)accp_raccp_par,
                                            (UInt32)vsctl_raccpengmin_par,
                                            (UInt32)vsctl_raccpengmax_par);
    }

    *covsctl_raccptra_ptr = (UInt16)DDS_M_SATURATION_V2(out_switch,
                                                        (UInt32)vsctl_raccptramin_par,
                                                        (UInt32)vsctl_raccptramax_par);

    /* BIN4 = BIN4 - BIN4 */
    temp_s32 = (SInt32)CoVSCtl_rAccPThd1_C - (SInt32)CoVSCtl_rAccPThd1Hyst_C;
    CoVSCtl_rAccPThd1Hyst = (UInt16)DDS_M_LIMIT(temp_s32,
                                                COVSCTL_RACCPTHD_X_HYST_MIN,
                                                COVSCTL_RACCPTHD_X_HYST_MAX);

    /* [75;100]BIN4 = [75,100]BIN4 - [0;25]BIN4 */
    temp_s32 = (SInt32)CoVSCtl_rAccPThd3_C - (SInt32)CoVSCtl_rAccPThd3Hyst_C;
    CoVSCtl_rAccPThd3Hyst = (UInt16)DDS_M_LIMIT(temp_s32,
                                                COVSCTL_RACCPTHD_3_HYST_MIN,
                                                COVSCTL_RACCPTHD_3_HYST_MAX);
}

/*******************************************************************************
*
* Function Name : F01_02_01_Determiner_etat_pedale
* Description :
*
*******************************************************************************/
INLINE STATIC FUNC(void, AUTOMATIC) TQDEM_F01_02_01_Determiner_etat_pedale(UInt16 covsctl_raccpeng_par, /* BIN7 */
                                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) covsctl_staccp_ptr)
{
    /* SSTG REQ_TAG : CSMT_CGMT06_2026.FR.5.0 */
    switch (tqdem_f01_02_01_state)
    {
        case COVSCTL_STACCP_PIED_LEVE :
        /*BIN4*BIN3 < BIN7 */
            if(((UInt32)CoVSCtl_rAccPThd1_C * BIN3) < (UInt32)covsctl_raccpeng_par)
            {
                tqdem_f01_02_01_state = COVSCTL_STACCP_PIED_POSE;
            }
            else
            {
                /* DO NOTHING*/
            }
            break;

        case COVSCTL_STACCP_PIED_POSE :
            if(((UInt32)CoVSCtl_rAccPThd3_C * BIN3)< (UInt32)covsctl_raccpeng_par)
            {
                tqdem_f01_02_01_state = COVSCTL_STACCP_PIED_A_FOND;
            }
            else
            {
                if(((UInt32)CoVSCtl_rAccPThd1Hyst * BIN3) > (UInt32)covsctl_raccpeng_par)
                {
                    tqdem_f01_02_01_state = COVSCTL_STACCP_PIED_LEVE;
                }
                else
                {
                    /* DO NOTHING */
                }
            }
            break;

        case COVSCTL_STACCP_PIED_A_FOND :
            if(((UInt32)CoVSCtl_rAccPThd3Hyst * BIN3) > (UInt32)covsctl_raccpeng_par)
            {
                tqdem_f01_02_01_state = COVSCTL_STACCP_PIED_POSE;
            }
            break;

        default :
            if(((UInt32)CoVSCtl_rAccPThd1_C * BIN3) < (UInt32)covsctl_raccpeng_par)
            {
                tqdem_f01_02_01_state = COVSCTL_STACCP_PIED_POSE;
            }
            else
            {
                /* DO NOTHING*/
            }
            break;
    }

    *covsctl_staccp_ptr = (UInt8)tqdem_f01_02_01_state;
}

/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQDEM_Coord_Xvv_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQDEM_Coord_Xvv_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_tqEfcReq_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPEng_swc_out, /* BIN7 */
                                           CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoVSCtl_rAccPTra_swc_out, /* BIN7 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoVSCtl_stAccP_swc_out )
{
    /* Init state machine */
    tqdem_f01_02_01_state = COVSCTL_STACCP_PIED_LEVE;

    /* Init outputs */
    *CoVSCtl_tqEfcReq_swc_out = (0 * BIN4);
    *CoVSCtl_rAccPEng_swc_out = (0 * BIN7);
    *CoVSCtl_rAccPTra_swc_out = (0 * BIN7);
    *CoVSCtl_stAccP_swc_out = (0 * BIN0);
}



#define TQDEM_STOP_SEC_CODE
#include "TqDem_MemMap.h"

