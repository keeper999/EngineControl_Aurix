/***************************************************************************
;**
;** FILE NAME      : NVMSRV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef NVMSRV_H
#define NVMSRV_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "NVMSRV_I.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AV_BMAX_ADAPT_ANTI_K_CYL1_COLS         ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_CYL2_COLS         ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_CYL3_COLS         ( 15 )
#define AV_BMAX_ADAPT_ANTI_K_CYL4_COLS         ( 15 )
#define COPT_PRM_TCLUESTIMMEM_NV_COLS          ( 5 )
#define FAULT_CONTEXT_EEP_EOBD_COLS            ( 16 )
#define GD_AS16TCOMESNOFRF_COLS                ( 40 )
#define GD_AU16IDXDFTNOFRF_COLS                ( 40 )
#define GD_AU16NENGNOFRF_COLS                  ( 40 )
#define GD_AU16PRMCLASDID1_COLS                ( 40 )
#define GD_AU16PRMCLASDID2_COLS                ( 40 )
#define GD_AU16PRMCLASDID3_COLS                ( 40 )
#define GD_AU16PRMCLASDID4_COLS                ( 40 )
#define GD_AU16PRMCLASDID5_COLS                ( 40 )
#define GD_AU16PRMCLASDID6_COLS                ( 40 )
#define GD_AU16PRMCLASDID7_COLS                ( 40 )
#define GD_AU16PRMCLASDID8_COLS                ( 40 )
#define GD_AU16PRMCLASDID9_COLS                ( 40 )
#define GD_AU32DSTABSKMNOFRF_COLS              ( 40 )
#define GD_AU32PRMCLASFRF1NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF2NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF3NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF4NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF5NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF6NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF7NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF8NOFRF_COLS           ( 40 )
#define GD_AU32PRMCLASFRF9NOFRF_COLS           ( 40 )
#define GD_AU8IDXFLTTOCXTNOFRF_COLS            ( 40 )
#define GD_AU8RNKFRF_COLS                      ( 734 )
#define GD_AU8STFRFRECNOFRF_COLS               ( 40 )
#define GD_PID03_NOFRF_COLS                    ( 40 )
#define GD_PID04_NOFRF_COLS                    ( 40 )
#define GD_PID05_NOFRF_COLS                    ( 40 )
#define GD_PID06_NOFRF_COLS                    ( 40 )
#define GD_PID07_NOFRF_COLS                    ( 40 )
#define GD_PID0B_NOFRF_COLS                    ( 40 )
#define GD_PID0C_NOFRF_COLS                    ( 40 )
#define GD_PID0D_NOFRF_COLS                    ( 40 )
#define GD_PID23_NOFRF_COLS                    ( 40 )
#define GD_PID42_NOFRF_COLS                    ( 40 )
#define GD_PRMDTCSTATUS_COLS                   ( 734 )
#define GD_RACCP_NOFRF_COLS                    ( 40 )
#define GD_SPDVEH_NOFRF_COLS                   ( 40 )
#define GD_TICURVEHTMR_NOFRF_COLS              ( 40 )
#define GD_UBATTMES_NOFRF_COLS                 ( 40 )
#define GOBD_BNCFDC_COLS                       ( 734 )
#define GOBD_BPRESDC_COLS                      ( 734 )
#define GOBD_CTDC_COLS                         ( 734 )
#define GOBD_CTWUC_COLS                        ( 734 )
#define IUPR_CTDENRAT_COLS                     ( 100 )
#define IUPR_CTNUMRAT_COLS                     ( 100 )
#define MCWDG_AU8INITIALMCWROMCHECKSUM_COLS    ( 2 )
#define MF_ADAP_BDC_DELTA_APPLIED_UAVN1_COLS   ( 4 )
#define MF_ADAP_EXP_DELTA_APPLIED_UAVN1_COLS   ( 4 )
#define MF_ADAP_LW_CORR_COUNT_UAVN1_COLS       ( 9 )
#define MF_ADAP_LW_DELTA_APPLIED_UAVN1_COLS    ( 4 )
#define MF_ADAP_SHRT_CORR_COUNT_UAVN1_COLS     ( 9 )
#define MF_ADAP_TDC_DELTA_APPLIED_UAVN1_COLS   ( 4 )
#define MISF_PRM_TIDLYBDCWINLRNCYL1_COLS       ( 9 )
#define MISF_PRM_TIDLYBDCWINLRNCYL2_COLS       ( 9 )
#define MISF_PRM_TIDLYBDCWINLRNCYL3_COLS       ( 9 )
#define MISF_PRM_TIDLYBDCWINLRNCYL4_COLS       ( 9 )
#define MISF_PRM_TIDLYEXPWINLRNCYL1_COLS       ( 9 )
#define MISF_PRM_TIDLYEXPWINLRNCYL2_COLS       ( 9 )
#define MISF_PRM_TIDLYEXPWINLRNCYL3_COLS       ( 9 )
#define MISF_PRM_TIDLYEXPWINLRNCYL4_COLS       ( 9 )
#define MISF_PRM_TIDLYLONGWINLRNCYL1_COLS      ( 9 )
#define MISF_PRM_TIDLYLONGWINLRNCYL2_COLS      ( 9 )
#define MISF_PRM_TIDLYLONGWINLRNCYL3_COLS      ( 9 )
#define MISF_PRM_TIDLYLONGWINLRNCYL4_COLS      ( 9 )
#define MISF_PRM_TIDLYTDCWINLRNCYL1_COLS       ( 9 )
#define MISF_PRM_TIDLYTDCWINLRNCYL2_COLS       ( 9 )
#define MISF_PRM_TIDLYTDCWINLRNCYL3_COLS       ( 9 )
#define MISF_PRM_TIDLYTDCWINLRNCYL4_COLS       ( 9 )
#define PROD_AU8CIEVALEONUM_COLS               ( 5 )
#define PROD_AU8CIEVALEONUMIDX_COLS            ( 2 )
#define PROD_AU8ECUSERIAL_COLS                 ( 5 )
#define PROD_AU8FUNCPRODUCTNUM_COLS            ( 5 )
#define PROD_AU8FUNCSCHEMATICNUM_COLS          ( 5 )
#define PROD_AU8PROD1RESERVE_COLS              ( 11 )
#define PROD_AU8PROD2RESERVE_COLS              ( 20 )
#define PROD_AU8PROD5RESERVE_COLS              ( 21 )
#define PROD_AU8PROD8RESERVE_COLS              ( 24 )
#define PROD_AU8REFAINDEX_COLS                 ( 2 )
#define PROD_AU8REFANUM_COLS                   ( 5 )
#define PROD_AU8REFCINDEX_COLS                 ( 2 )
#define PROD_AU8REFCNUM_COLS                   ( 5 )
#define RDY_AU8RDY_EEPROM_COLS                 ( 92 )
#define RED_AU8CIEVALEONUM_COLS                ( 5 )
#define RED_AU8CIEVALEONUMIDX_COLS             ( 2 )
#define RED_AU8ECUSERIAL_COLS                  ( 5 )
#define RED_AU8FUNCPRODUCTNUM_COLS             ( 5 )
#define RED_AU8FUNCSCHEMATICNUM_COLS           ( 5 )
#define RED_AU8INITIALMCWROMCHECKSUM_COLS      ( 2 )
#define RED_AU8PROD1RESERVE_COLS               ( 11 )
#define RED_AU8PROD2RESERVE_COLS               ( 20 )
#define RED_AU8PROD5RESERVE_COLS               ( 21 )
#define RED_AU8PROD8RESERVE_COLS               ( 24 )
#define RED_AU8REFAINDEX_COLS                  ( 2 )
#define RED_AU8REFANUM_COLS                    ( 5 )
#define RED_AU8REFCINDEX_COLS                  ( 2 )
#define RED_AU8REFCNUM_COLS                    ( 5 )
#define REF_IDENT_ETAL_COLS                    ( 12 )
#define SFTYMGT_PRM_BDFTHIS_COLS               ( 4 )
#define SFTYMGT_PRM_BFRFNEW_COLS               ( 8 )
#define SPYEMSTT_PRMHISDSTWIN1_COLS            ( 2 )
#define SPYEMSTT_PRMHISTNOTSTOPCASE1_COLS      ( 7 )
#define SPYEMSTT_PRMHISTNOTSTOPCASE2_COLS      ( 7 )
#define SPYEMSTT_PRMHISTNOTSTOPCASE3_COLS      ( 7 )
#define SPYSTT_PRMHISDSTWIN1_COLS              ( 2 )
#define SPYSTT_PRMHISNOTSTOPCASE1_COLS         ( 11 )
#define SPYSTT_PRMHISNOTSTOPCASE2_COLS         ( 11 )
#define SPYSTT_PRMHISNOTSTOPCASE3_COLS         ( 11 )
#define SYNC_PRM_BLRNCORAR_COLS                ( 20 )
#define SYNC_PRM_NCORNENGCYL1_COLS             ( 20 )
#define SYNC_PRM_NCORNENGCYL2_COLS             ( 20 )
#define SYNC_PRM_NCORNENGCYL3_COLS             ( 20 )
#define VCPE_CAM_OFFSETS_EEP_COLS              ( 4 )
#define VCPI_CAM_OFFSETS_EEP_COLS              ( 4 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS1_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS10_COLS      ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS11_COLS      ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS2_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS3_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS4_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS5_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS6_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS7_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS8_COLS       ( 11 )
#define VSCTL_PRMLSTCRSCTLDEACCAUS9_COLS       ( 11 )

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* NVMSRV_H */

/*-------------------------------- end of file -------------------------------*/
