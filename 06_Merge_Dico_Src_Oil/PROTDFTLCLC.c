/***************************************************************************
;**
;** FILE NAME      : PROTDFTLCLC.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "PROTDFTLCLC.H"
#include "PROTDFTLCLC_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const boolean  CoPt_bProtDftlAcv_C = 0;
const boolean  CoPt_bTqStProt_C = 0;
const uint8  CoPt_facFilProtBrk_C = 0;
const uint8  CoPt_facGainFilFastProtDftl_C = 0;
const uint8  CoPt_facGainFilNProtDftl_C = 0;
const uint8  CoPt_facGainFilSlowProtDftl_C = 0;
const uint8  CoPt_facSpdWhlFil_C = 0;
const uint8  CoPt_noGearProtBrkY_A[COPT_NOGEARPROTBRKY_A_COLS] = {0};
const uint8  CoPt_pwrColdProtDftl_C = 0;
const uint8  CoPt_tiAcvTqProtBrk_C = 0;
const uint8  CoPt_tiAcvTqProtDftl_C = 0;
const uint8  CoPt_tiDeacTqProtBrk_C = 0;
const uint8  CoPt_tiDeacTqProtDftl_C = 0;
const uint8  PROTDFTLCLC_u8Inhib = 0;
const sint16  CoPt_tqOfsStProt_C = 0;
const uint16  CoPt_dstWhlProtDftl_C = 0;
const uint16  CoPt_nAcvProtDftl_C = 0;
const uint16  CoPt_nDeltaAcvProtDftl_C = 0;
const uint16  CoPt_nDftlMaxProtDftl_A[COPT_NDFTLMAXPROTDFTL_A_COLS] = {0};
const uint16  CoPt_nDftlMinProtDftl_A[COPT_NDFTLMINPROTDFTL_A_COLS] = {0};
const uint16  CoPt_nEngProtBrkX_A[COPT_NENGPROTBRKX_A_COLS] = {0};
const uint16  CoPt_tqEfcMaxProtBrk_M[COPT_TQEFCMAXPROTBRK_M_LNS][COPT_TQEFCMAXPROTBRK_M_COLS] = {0};
const uint16  CoPt_tqWhlMaxProtDftl_T[COPT_TQWHLMAXPROTDFTL_T_COLS] = {0};
const uint16  CoPt_tqWhlMinProtDftl_T[COPT_TQWHLMINPROTDFTL_T_COLS] = {0};
const uint16  CoPt_wMaxProtDftl_C = 0;
const uint16  CoPt_wMaxSatProtDftl_C = 0;
const uint16  CoPt_wMaxSpcProtDftl_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoPt_bProtDftlAcv;
boolean PROTDFTLCLC_bActivationMem;
boolean PROTDFTLCLC_bActivationMemBrk;
boolean PROTDFTLCLC_bEtatTmr;
boolean PROTDFTLCLC_bEtatTmrBrk;
boolean PROTDFTLCLC_bOutHysNeg;
uint32 PROTDFTLCLC_u32rFilDftlWhlMem;
uint32 PROTDFTLCLC_u32rFilLeFrntWhlMem;
uint32 PROTDFTLCLC_u32rFilLeReWhlMem;
uint32 PROTDFTLCLC_u32rFilMaxProtMem;
uint32 PROTDFTLCLC_u32rFilRiFrntWhlMem;
uint32 PROTDFTLCLC_u32rFilRiReWhlMem;
sint8 CoPt_facSignNDftlWhl_MP;
uint8 CoPt_rEProtDftl;
uint8 PROTDFTLCLC_u8AcvBrkSelPrev;
uint8 PROTDFTLCLC_u8AcvDeacBrkTr;
uint8 PROTDFTLCLC_u8AcvDeacBrkTrDly;
uint8 PROTDFTLCLC_u8AcvDeacTr;
uint8 PROTDFTLCLC_u8AcvDeacTrDly;
uint8 PROTDFTLCLC_u8Counter;
uint8 PROTDFTLCLC_u8CounterBrk;
uint8 PROTDFTLCLC_u8ProtAcvBrkSelOld;
uint8 PROTDFTLCLC_u8ProtAcvSelOld;
uint8 PROTDFTLCLC_u8ProtAcvSelPrev;
sint16 CoPt_tqEfcMaxProtBrk;
sint16 CoPt_tqEfcMaxProtBrk_MP;
sint16 CoPt_tqEfcMaxProtDftlBfCord;
sint16 CoPt_tqMaxProtDftlBfCord_MP;
sint16 PROTDFTLCLC_s16MaxProtBfCord;
sint16 PROTDFTLCLC_s16MaxProtBrk;
uint16 CoPt_nDftlWhl;
uint16 CoPt_nReWhlAvr;
uint16 CoPt_pwrProtDftl;
uint16 CoPt_pwrProtDftl_MP;
uint16 CoPt_tqWhlMaxProtDftl;
uint16 CoPt_tqWhlProtDftl;
uint16 CoPt_wMaxProtDftl;
uint16 CoPt_wMaxSpcProtDftl;
uint16 CoPt_wProtDftl;
uint16 CoPt_wSpcProtDftl;
uint16 PROTDFTLCLC_u16CoProtDftl;
uint16 PROTDFTLCLC_u16CoPtDftlWhl;
uint16 PROTDFTLCLC_u16SpdLeFrntWhl;
uint16 PROTDFTLCLC_u16SpdLeReWhl;
uint16 PROTDFTLCLC_u16SpdRiFrntWhl;
uint16 PROTDFTLCLC_u16SpdRiReWhl;
uint16 PROTDFTLCLC_u16WhlMaxProtDftl;
sint32 PROTDFTLCLC_s32rFilMaxProtBrkMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

