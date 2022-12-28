/***************************************************************************
;**
;** FILE NAME      : ENGSTOUTPIDC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGSTOUTPIDC_L_H
#define ENGSTOUTPIDC_L_H

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

extern const uint8  ENGSTOUTPIDC_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_EngStOutIdc;
extern boolean Ext_bDgoScg_EngStOutIdc;
extern boolean Ext_bDgoScp_EngStOutIdc;
extern boolean Ext_bMonRunOc_EngStOutIdc;
extern boolean Ext_bMonRunScg_EngStOutIdc;
extern boolean Ext_bMonRunScp_EngStOutIdc;
extern boolean Info_moteur_tournant;
extern boolean Info_moteur_tournant_applique;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGSTOUTPIDC_vidDiagOutput(void);
void ENGSTOUTPIDC_vidElectricDiag(void);
void ENGSTOUTPIDC_vidEngineRunningInfo(void);
void ENGSTOUTPIDC_vidInit(void);


#endif /* ENGSTOUTPIDC_L_H */

/*-------------------------------- end of file -------------------------------*/
