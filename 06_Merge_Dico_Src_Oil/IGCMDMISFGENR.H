/***************************************************************************
;**
;** FILE NAME      : IGCMDMISFGENR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCMDMISFGENR_H
#define IGCMDMISFGENR_H

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

extern const boolean  Autorisation_misfire;
extern const boolean  Mode_deterministe;
extern const boolean  Mode_successif;
extern const uint8  Msm_coupure_cylindre;
extern const uint8  Recurrence_misfire_deterministe;
extern const uint16  Taux_misfire_aleatoire;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Misfire_cylindre;
extern uint16 Taux_aleatoire;
extern uint16 Taux_deterministe;
extern uint16 Taux_misfire;
extern uint16 Taux_misfire_reel;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IgCmd_EveBDC_MisfGenr(void);
void IgCmd_EveRst_MisfGenr(void);
void IgCmd_EveRTSt_MisfGenr(void);
void IgCmd_EveStTR_MisfGenr(void);
void IgCmd_SdlSlow_MisfGenr(void);


#endif /* IGCMDMISFGENR_H */

/*-------------------------------- end of file -------------------------------*/
