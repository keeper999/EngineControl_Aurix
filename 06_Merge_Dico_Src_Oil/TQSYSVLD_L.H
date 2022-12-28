/***************************************************************************
;**
;** FILE NAME      : TQSYSVLD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQSYSVLD_L_H
#define TQSYSVLD_L_H

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


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  TQSYSVLD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Diag_misfire_bas;
extern boolean Diag_misfire_bas_EM;
extern boolean Diag_misfire_haut;
extern boolean Diag_misfire_haut_EM;
extern uint8 Nb_Cyl_NoProd;
extern uint8 Rat_Cyl_NoProd;
extern uint16 TqDiag_noWght;
extern uint16 TqDiag_noWght1;
extern uint16 TqDiag_noWght2;
extern uint16 TqDiag_noWght3;
extern uint16 TqDiag_noWght4;
extern uint16 TqDiag_noWght5;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQSYSVLD_vidDiagMisfire(void);
void TQSYSVLD_vidInit(void);
void TQSYSVLD_vidNoWght(void);
void TQSYSVLD_vidNoWght1(void);
void TQSYSVLD_vidNoWght2(void);
void TQSYSVLD_vidNoWght3(void);
void TQSYSVLD_vidNoWght4(void);
void TQSYSVLD_vidNoWght5(void);
void TQSYSVLD_vidStDiagESPReq(void);
void TQSYSVLD_vidTqCkEngReal(void);
void TQSYSVLD_vidTqEM(void);


#endif /* TQSYSVLD_L_H */

/*-------------------------------- end of file -------------------------------*/
