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
* Ref X:\integration_view_00PSASWC_EC01D01\blois_psa_sstg\Software\Appli\CoTq\src\COTQ_Cme_Cmi_Convers.c
* Version int :/main/L01_01/2 Date: 22/11/2010 15 h 9 m User:esnault 
*    TWK_model:COTQ_Cme_Cmi_Convers_L01_010_IMPL1_D
*    comments :correct FDS32873
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 22/11/2010 14 h 3 m User:lemort 
*    TWK_model:COTQ_Cme_Cmi_Convers_L01_010_IMPL1_D
*    comments :correct FDS32873
* Version int :/main/L01_01/1 Date: 5/11/2010 11 h 57 m User:esnault
*    TWK_model:COTQ_Cme_Cmi_Convers_L01_010_IMPL1
*    comments :dev in progress
* Version dev :\main\branch_lemort_cotq_dev\1 Date: 21/10/2010 15 h 47 m User:lemort
*    TWK_model:COTQ_Cme_Cmi_Convers_L01_010_IMPL1
*    comments :dev in progress
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

#define COTQ_M2000_BIN4 ((SInt32)-2000 * BIN4)
#define COTQ_2000_BIN4  ((SInt32)2000 * BIN4)


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

/* NONE */


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define COTQ_START_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqLimEM_tqLimEMUpd; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) CoPt_tqEfcCordLim_tqGBxUpd; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqSys_tqAltLossPos; /* BIN4 */
#define COTQ_STOP_SEC_INTERNAL_VAR_16BIT
#include "CoTq_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define COTQ_START_SEC_CODE
#include "CoTq_MemMap.h"

STATIC FUNC(void, AUTOMATIC) COTQ_F02_01_PreTraitement( UInt8 tqsys_bfucutoffreq_par,
                                                        SInt16 tqcmp_tqsumlosscmp_par,
                                                        SInt16 tqlimem_tqlimemtrv_par,
                                                        SInt16 copt_tqefccordlim_tqgbx_par,
                                                        SInt16 tqcmp_tqaltloss_par,
                                                        UInt8 tqsys_btypfu_par);

STATIC FUNC(void, AUTOMATIC) COTQ_F02_02_Conversion(UInt8 cocha_binhegrtrv_par,
                                                    UInt8 cocha_brstaos_par,
                                                    UInt8 copt_binhegr_par,
                                                    SInt16 copt_tqmaxgbx_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidccordlim_tqgbx_ptr,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidcmaxgbx_ptr,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqlimem_tqidclimem_ptr,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_binhegr_ptr,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_brstaos_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F03_Bloc_Conversion_Air_Diesel(SInt16 tqcmp_tqsumlosscmp_par,
                                                                SInt16 englim_tqckefcairlim_par,
                                                                SInt16 tqcmp_tqaltloss_par,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairlim_ptr);

STATIC FUNC(void, AUTOMATIC) COTQ_F04_Bloc_Conversion_Air_Essence(SInt16 tqcmp_tqsumlosscmp_par,
                                                                    SInt16 copt_tqefcaircordlim_tqgbx_par,
                                                                    SInt16 copt_tqairmaxgbx_par,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidcaircordlim_tqgbx_ptr,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidcairmaxgbx_ptr);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_Cme_Cmi_Convers
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Cme_Cmi_Convers(UInt8 CoCha_bInhEGRTrv_swc_in,
                                           UInt8 CoCha_bRstAOS_swc_in,
                                           UInt8 CoPt_bInhEGR_swc_in,
                                           SInt16 CoPt_tqAirMaxGBx_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqEfcAirCordLim_tqGBx_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqEfcCordLim_tqGBx_swc_in, /* BIN4 */
                                           SInt16 CoPt_tqMaxGBx_swc_in, /* BIN4 */
                                           SInt16 EngLim_tqCkEfcAirLim_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqAltLoss_swc_in, /* BIN4 */
                                           SInt16 TqCmp_tqSumLossCmp_swc_in, /* BIN4 */
                                           SInt16 TqLimEM_tqLimEMTrv_swc_in, /* BIN4 */
                                           UInt8 TqSys_bFuCutOffReq_swc_in,
                                           UInt8 TqSys_bTypFu_swc_in,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirMaxGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLim_tqGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBx_swc_out, /* BIN4 */
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqIdcLimEM_swc_out, /* BIN4 */
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInhEGR_swc_out,
                                           CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bRstAOS_swc_out,
                                           CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLim_swc_out /* BIN4 */)
{

    /* SSTG_REQ_TAG : CSMT_CGMT08_0921.FR.1.1 */
    /* SSTG_REQ_TAG : CSMT_CGMT08_0921.FR.2.0 */

    COTQ_F02_01_PreTraitement(  TqSys_bFuCutOffReq_swc_in,
                                TqCmp_tqSumLossCmp_swc_in,
                                TqLimEM_tqLimEMTrv_swc_in,
                                CoPt_tqEfcCordLim_tqGBx_swc_in,
                                TqCmp_tqAltLoss_swc_in,
                                TqSys_bTypFu_swc_in);

    COTQ_F02_02_Conversion( CoCha_bInhEGRTrv_swc_in,
                            CoCha_bRstAOS_swc_in,
                            CoPt_bInhEGR_swc_in,
                            CoPt_tqMaxGBx_swc_in,
                            TqCmp_tqSumLossCmp_swc_in,
                            CoPt_tqIdcCordLim_tqGBx_swc_out,
                            CoPt_tqIdcMaxGBx_swc_out,
                            TqLimEM_tqIdcLimEM_swc_out,
                            TqSys_bInhEGR_swc_out,
                            TqSys_bRstAOS_swc_out);

    COTQ_F03_Bloc_Conversion_Air_Diesel(TqCmp_tqSumLossCmp_swc_in,
                                        EngLim_tqCkEfcAirLim_swc_in,
                                        TqCmp_tqAltLoss_swc_in,
                                        TqSys_tqIdcAirLim_swc_out);

    COTQ_F04_Bloc_Conversion_Air_Essence(   TqCmp_tqSumLossCmp_swc_in,
                                            CoPt_tqEfcAirCordLim_tqGBx_swc_in,
                                            CoPt_tqAirMaxGBx_swc_in,
                                            CoPt_tqIdcAirCordLim_tqGBx_swc_out,
                                            CoPt_tqIdcAirMaxGBx_swc_out);


}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : COTQ_F02_01_PreTraitement
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_01_PreTraitement( UInt8 tqsys_bfucutoffreq_par,
                                                        SInt16 tqcmp_tqsumlosscmp_par,
                                                        SInt16 tqlimem_tqlimemtrv_par,
                                                        SInt16 copt_tqefccordlim_tqgbx_par,
                                                        SInt16 tqcmp_tqaltloss_par,
                                                        UInt8 tqsys_btypfu_par)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0921.FR.3.0 */

    if((UInt32)DDS_FALSE != (UInt32)tqsys_bfucutoffreq_par)
    {
        TqLimEM_tqLimEMUpd = (SInt16)(-1 * (SInt32)tqcmp_tqsumlosscmp_par);
        CoPt_tqEfcCordLim_tqGBxUpd = TqLimEM_tqLimEMUpd;
    }
    else
    {
        TqLimEM_tqLimEMUpd = tqlimem_tqlimemtrv_par;
        CoPt_tqEfcCordLim_tqGBxUpd = copt_tqefccordlim_tqgbx_par;
    }

    if( ((SInt32)0 > (SInt32)tqcmp_tqaltloss_par)
    &&  ((UInt32)DDS_FALSE == (UInt32)tqsys_btypfu_par) )
    {
        TqSys_tqAltLossPos = tqcmp_tqaltloss_par;
    }
    else
    {
        TqSys_tqAltLossPos = 0;
    }

}


/*******************************************************************************
*
* Function Name : COTQ_F02_02_Conversion
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F02_02_Conversion(UInt8 cocha_binhegrtrv_par,
                                                    UInt8 cocha_brstaos_par,
                                                    UInt8 copt_binhegr_par,
                                                    SInt16 copt_tqmaxgbx_par,
                                                    SInt16 tqcmp_tqsumlosscmp_par,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidccordlim_tqgbx_ptr,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidcmaxgbx_ptr,
                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqlimem_tqidclimem_ptr,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_binhegr_ptr,
                                                    CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) tqsys_brstaos_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0921.FR.4.0 */

    SInt32 cotq_s32_temp;

    cotq_s32_temp = ((SInt32)tqcmp_tqsumlosscmp_par + (SInt32)TqLimEM_tqLimEMUpd) - (SInt32)TqSys_tqAltLossPos;
    *tqlimem_tqidclimem_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)tqcmp_tqsumlosscmp_par + (SInt32)CoPt_tqEfcCordLim_tqGBxUpd;
    *copt_tqidccordlim_tqgbx_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)tqcmp_tqsumlosscmp_par + (SInt32)copt_tqmaxgbx_par;
    *copt_tqidcmaxgbx_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    *tqsys_brstaos_ptr = cocha_brstaos_par;

    if( ((UInt32)DDS_FALSE != (UInt32)copt_binhegr_par)
    ||  ((UInt32)DDS_FALSE != (UInt32)cocha_binhegrtrv_par) )
    {
        *tqsys_binhegr_ptr = DDS_TRUE;
    }
    else
    {
        *tqsys_binhegr_ptr = DDS_FALSE;
    }

}

/*******************************************************************************
*
* Function Name : COTQ_F03_Bloc_Conversion_Air_Diesel
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F03_Bloc_Conversion_Air_Diesel(SInt16 tqcmp_tqsumlosscmp_par,
                                                                SInt16 englim_tqckefcairlim_par,
                                                                SInt16 tqcmp_tqaltloss_par,
                                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) tqsys_tqidcairlim_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0921.FR.5.0 */

    SInt32 cotq_s32_temp;

    cotq_s32_temp = (SInt32)tqcmp_tqsumlosscmp_par + (SInt32)englim_tqckefcairlim_par;

    if((SInt32)0 > (SInt32)tqcmp_tqaltloss_par)
    {
        cotq_s32_temp = cotq_s32_temp - (SInt32)tqcmp_tqaltloss_par;
    }
    else
    {
        /* do nothing */
    }

    *tqsys_tqidcairlim_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);


}

/*******************************************************************************
*
* Function Name : COTQ_F04_Bloc_Conversion_Air_Essence
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) COTQ_F04_Bloc_Conversion_Air_Essence(SInt16 tqcmp_tqsumlosscmp_par,
                                                                    SInt16 copt_tqefcaircordlim_tqgbx_par,
                                                                    SInt16 copt_tqairmaxgbx_par,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidcaircordlim_tqgbx_ptr,
                                                                    CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) copt_tqidcairmaxgbx_ptr)
{
    /* SSTG_REQ_TAG : CSMT_CGMT08_0921.FR.6.0 */

    SInt32 cotq_s32_temp;

    cotq_s32_temp = (SInt32)tqcmp_tqsumlosscmp_par + (SInt32)copt_tqefcaircordlim_tqgbx_par;
    *copt_tqidcaircordlim_tqgbx_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

    cotq_s32_temp = (SInt32)tqcmp_tqsumlosscmp_par + (SInt32)copt_tqairmaxgbx_par;
    *copt_tqidcairmaxgbx_ptr = (SInt16)DDS_M_LIMIT(cotq_s32_temp,COTQ_M2000_BIN4,COTQ_2000_BIN4);

}


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : COTQ_Cme_Cmi_Convers_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) COTQ_Cme_Cmi_Convers_Init(CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirCordLim_tqGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcAirMaxGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcCordLim_tqGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoPt_tqIdcMaxGBx_swc_out, /* BIN4 */
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqLimEM_tqIdcLimEM_swc_out, /* BIN4 */
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bInhEGR_swc_out,
                                                CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) TqSys_bRstAOS_swc_out,
                                                CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqIdcAirLim_swc_out /* BIN4 */)
{
    /* ---- Init Outputs ---- */

    *CoPt_tqIdcAirCordLim_tqGBx_swc_out = 0;
    *CoPt_tqIdcAirMaxGBx_swc_out = (SInt16)(2000 * BIN4);
    *CoPt_tqIdcCordLim_tqGBx_swc_out = 0;
    *CoPt_tqIdcMaxGBx_swc_out = (SInt16)(2000 * BIN4);
    *TqLimEM_tqIdcLimEM_swc_out = 0;
    *TqSys_bInhEGR_swc_out = 0;
    *TqSys_bRstAOS_swc_out = 0;
    *TqSys_tqIdcAirLim_swc_out = (SInt16)(2000 * BIN4);

    /* ---- Init Global Datas ---- */

    TqLimEM_tqLimEMUpd = 0;
    CoPt_tqEfcCordLim_tqGBxUpd = 0;
    TqSys_tqAltLossPos = 0;

}



#define COTQ_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "CoTq_MemMap.h"
