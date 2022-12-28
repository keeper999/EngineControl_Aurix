/***************************************************************************
;**
;** FILE NAME      : INJCMD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCMD_H
#define INJCMD_H

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

extern const boolean  Inhibe_reactualisation_t_inj;
extern const boolean  Manu_coupure_inj_1;
extern const boolean  Manu_coupure_inj_2;
extern const boolean  Manu_coupure_inj_3;
extern const boolean  Manu_coupure_inj_4;
extern const uint8  InjSys_ModeInjection_C;
extern const uint16  InjSys_nInjPhaOfs_C;

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

void Inj_EveCkOff_InjCmd(void);
void Inj_EveCkSnOf_InjCmd(void);
void Inj_EveCrTR_InjCmd(void);
void Inj_EveInj_InjCmd(void);
void Inj_EveKOf_InjCmd(void);
void Inj_EveRst_InjCmd(void);
void Inj_EveSpl_InjCmd(void);
void Inj_EveStTCr_InjCmd(void);
void Inj_EveSyncNotAccu_InjCmd(void);
void Inj_SdlFast_InjCmd(void);


#endif /* INJCMD_H */

/*-------------------------------- end of file -------------------------------*/
