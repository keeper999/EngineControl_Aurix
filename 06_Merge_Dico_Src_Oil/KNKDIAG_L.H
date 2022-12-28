/***************************************************************************
;**
;** FILE NAME      : KNKDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKDIAG_L_H
#define KNKDIAG_L_H

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

/* enum st51 */
#define DIAG_NOT_REQUESTED                0
#define DIAG_REQUIRED                     1
#define DIAG_RUNNING                      2
#define DIAG_ENDING                       4
/*extern uint8 Knk_sens_diag_stt_uavs0;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  KNKDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Knk_sens_diag_stt_uavs0;
extern boolean KnkTreat_bDgoORng_KnkDiag;
extern boolean KnkTreat_bMonRun_KnkDiag;
extern uint8 Knk_sens_diag_count_uavn0;
extern uint16 Compteur_diag_k;
extern uint16 Knk_diag_noi_inc_uavn0;
extern uint16 Seuil_defaut_capteur;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKDIAG_vidDiagnosticConditions(void);
void KNKDIAG_vidDiagStateManagement(void);
void KNKDIAG_vidDiagStrategy(void);
void KNKDIAG_vidEndDiag(void);
void KNKDIAG_vidInitOutput(void);
void KNKDIAG_vidTreatment(void);


#endif /* KNKDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
