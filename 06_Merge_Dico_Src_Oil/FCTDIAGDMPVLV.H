/***************************************************************************
;**
;** FILE NAME      : FCTDIAGDMPVLV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FCTDIAGDMPVLV_H
#define FCTDIAGDMPVLV_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DMPVLV_CTTHDDIAGSTUCKCLS_T_COLS        ( 4 )
#define DMPVLV_NENGMAXTHD_T_COLS               ( 8 )
#define DMPVLV_NENGMINTHD_T_COLS               ( 8 )
#define DMPVLV_PAIREXTMES_A_COLS               ( 8 )
#define DMPVLV_PAIRINTER_A_COLS                ( 8 )
#define DMPVLV_PTHDBOOSTPRES_M_LNS            ( 8 )
#define DMPVLV_PTHDBOOSTPRES_M_COLS            ( 8 )
#define DMPVLV_TCO_A_COLS                      ( 4 )
#define DMPVLV_TITRBACTSTUCKOP_T_COLS          ( 8 )
#define FCTDIAGDMPVLV_NENG_A_COLS              ( 8 )

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

extern const uint32  DmpVlv_tiAcvCntOscStuckCls_C;
extern const uint8  DmpVlv_CoefPresStuckCls_C;
extern const uint8  DmpVlv_ctThdDiagStuckCls_T[DMPVLV_CTTHDDIAGSTUCKCLS_T_COLS];
extern const uint8  DmpVlv_nbMaxOscStuckCls_C;
extern const uint8  DmpVlv_tCo_A[DMPVLV_TCO_A_COLS];
extern const sint16  DmpVlv_pOfsOscStuckCls_C;
extern const sint16  DmpVlv_pThdOscStuckCls_C;
extern const sint16  DmpVlv_pUsThrCorReqOfst_C;
extern const uint16  DmpVlv_GainFiltPresStuckCls_C;
extern const uint16  DmpVlv_nEngMaxThd_T[DMPVLV_NENGMAXTHD_T_COLS];
extern const uint16  DmpVlv_nEngMinThd_T[DMPVLV_NENGMINTHD_T_COLS];
extern const uint16  DmpVlv_pAirExtMes_A[DMPVLV_PAIREXTMES_A_COLS];
extern const uint16  DmpVlv_pAirInter_A[DMPVLV_PAIRINTER_A_COLS];
extern const uint16  DmpVlv_pThdAcvDiagStuckCls_C;
extern const uint16  DmpVlv_pThdBoostPres_M[DMPVLV_PTHDBOOSTPRES_M_LNS][DMPVLV_PTHDBOOSTPRES_M_COLS];
extern const uint16  DmpVlv_pUsThrCorServoErrThd_C;
extern const uint16  DmpVlv_rThdCmdStuckCls_C;
extern const uint16  DmpVlv_tiTrbActStuckCls_C;
extern const uint16  DmpVlv_tiTrbActStuckOp_T[DMPVLV_TITRBACTSTUCKOP_T_COLS];
extern const uint16  DmpVlv_uBattMinStuckCls_C;
extern const uint16  FctDiagDmpVlv_nEng_A[FCTDIAGDMPVLV_NENG_A_COLS];

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

void DmpVlv_Eve14TDC_FctDiagDmpVlv(void);
void DmpVlv_EveRst_FctDiagDmpVlv(void);


#endif /* FCTDIAGDMPVLV_H */

/*-------------------------------- end of file -------------------------------*/
