/***************************************************************************
;**
;** FILE NAME      : PROTDFTLCLC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PROTDFTLCLC_H
#define PROTDFTLCLC_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define COPT_NDFTLMAXPROTDFTL_A_COLS           ( 10 )
#define COPT_NDFTLMINPROTDFTL_A_COLS           ( 10 )
#define COPT_NENGPROTBRKX_A_COLS               ( 16 )
#define COPT_NOGEARPROTBRKY_A_COLS             ( 10 )
#define COPT_TQEFCMAXPROTBRK_M_LNS            ( 16 )
#define COPT_TQEFCMAXPROTBRK_M_COLS            ( 10 )
#define COPT_TQWHLMAXPROTDFTL_T_COLS           ( 10 )
#define COPT_TQWHLMINPROTDFTL_T_COLS           ( 10 )

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

extern const boolean  CoPt_bProtDftlAcv_C;
extern const boolean  CoPt_bTqStProt_C;
extern const uint8  CoPt_facFilProtBrk_C;
extern const uint8  CoPt_facGainFilFastProtDftl_C;
extern const uint8  CoPt_facGainFilNProtDftl_C;
extern const uint8  CoPt_facGainFilSlowProtDftl_C;
extern const uint8  CoPt_facSpdWhlFil_C;
extern const uint8  CoPt_noGearProtBrkY_A[COPT_NOGEARPROTBRKY_A_COLS];
extern const uint8  CoPt_pwrColdProtDftl_C;
extern const uint8  CoPt_tiAcvTqProtBrk_C;
extern const uint8  CoPt_tiAcvTqProtDftl_C;
extern const uint8  CoPt_tiDeacTqProtBrk_C;
extern const uint8  CoPt_tiDeacTqProtDftl_C;
extern const sint16  CoPt_tqOfsStProt_C;
extern const uint16  CoPt_dstWhlProtDftl_C;
extern const uint16  CoPt_nAcvProtDftl_C;
extern const uint16  CoPt_nDeltaAcvProtDftl_C;
extern const uint16  CoPt_nDftlMaxProtDftl_A[COPT_NDFTLMAXPROTDFTL_A_COLS];
extern const uint16  CoPt_nDftlMinProtDftl_A[COPT_NDFTLMINPROTDFTL_A_COLS];
extern const uint16  CoPt_nEngProtBrkX_A[COPT_NENGPROTBRKX_A_COLS];
extern const uint16  CoPt_tqEfcMaxProtBrk_M[COPT_TQEFCMAXPROTBRK_M_LNS][COPT_TQEFCMAXPROTBRK_M_COLS];
extern const uint16  CoPt_tqWhlMaxProtDftl_T[COPT_TQWHLMAXPROTDFTL_T_COLS];
extern const uint16  CoPt_tqWhlMinProtDftl_T[COPT_TQWHLMINPROTDFTL_T_COLS];
extern const uint16  CoPt_wMaxProtDftl_C;
extern const uint16  CoPt_wMaxSatProtDftl_C;
extern const uint16  CoPt_wMaxSpcProtDftl_C;

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

void CoPt_Sdl10ms_ProtDftlClc(void);
void PROTDFTLCLC_vidEntryInit(void);


#endif /* PROTDFTLCLC_H */

/*-------------------------------- end of file -------------------------------*/
