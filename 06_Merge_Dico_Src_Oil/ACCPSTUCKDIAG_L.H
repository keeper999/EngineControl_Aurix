/***************************************************************************
;**
;** FILE NAME      : ACCPSTUCKDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPSTUCKDIAG_L_H
#define ACCPSTUCKDIAG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st32 */
#define ACCPSTUCKDIAG_u8INIT              1
#define ACCPSTUCKDIAG_u8DIAG_NON_ACTIF    2
#define ACCPSTUCKDIAG_u8DEFAUT_NON_CONFIRME  3
#define ACCPSTUCKDIAG_u8DEFAUT_CONFIRME   4
#define ACCPSTUCKDIAG_u8DEVALIDATION      5
/*extern uint8 ACCPSTUCKDIAG_stDiag;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  ACCPSTUCKDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 ACCPSTUCKDIAG_stDiag;
extern boolean AccP_bDgoStuckAccP;
extern boolean AccP_bMonRunStuckAccP;
extern boolean ACCPSTUCKDIAG_bRstDgo;
extern boolean ACCPSTUCKDIAG_bSetDgo;
extern boolean Aps_lck_brk_pdl_in;
extern boolean Aps_lck_brk_pdl_in_prev;
extern uint16 ACCPSTUCKDIAG_u16SsmPrPedPosPrev;
extern uint16 Aps_lck_pdl_pos_fix;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPSTUCKDIAG_vidInitOutput(void);
void ACCPSTUCKDIAG_vidMngMonRun(void);
void ACCPSTUCKDIAG_vidStuckAccPMonRun(void);
void ACCPSTUCKDIAG_vidStuckAccPPdlin(void);


#endif /* ACCPSTUCKDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
