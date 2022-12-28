/***************************************************************************
;**
;** FILE NAME      : DIAGAIREXTPRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DIAGAIREXTPRES_H
#define DIAGAIREXTPRES_H

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

extern const uint8  AirPres_pAirExtThdMin_C;
extern const uint16  AirPres_pAirExtThdGrdMax_C;
extern const uint16  AirPres_pAirExtThdGrdOldMax_C;
extern const uint16  AirPres_pAirExtThdMax_C;
extern const uint16  AirPres_tiDlyGrd_pAirExt_C;

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

void AirPres_EveKOf_DiagAirExtPres(void);
void AirPres_EveKOn_DiagAirExtPres(void);
void AirPres_EveRst_DiagAirExtPres(void);
void AirPres_SdlSlow_DiagAirExtPres(void);


#endif /* DIAGAIREXTPRES_H */

/*-------------------------------- end of file -------------------------------*/
