/***************************************************************************
;**
;** FILE NAME      : AUTHSTRTSTT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AUTHSTRTSTT_L_H
#define AUTHSTRTSTT_L_H

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

extern const uint8  AUTHSTRTSTT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean EngSt_bInhCrkAlt;
extern boolean EngSt_bInhCrkAltHw;
extern boolean Ext_bDgoOc_bInhCrkAltHw;
extern boolean Ext_bDgoScg_bInhCrkAltHw;
extern boolean Ext_bDgoScp_bInhCrkAltHw;
extern boolean Ext_bMonRunOc_bInhCrkAltHw;
extern boolean Ext_bMonRunScg_bInhCrkAltHw;
extern boolean Ext_bMonRunScp_bInhCrkAltHw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AUTHSTRTSTT_vidCallMng(void);
void AUTHSTRTSTT_vidDiagnostic(void);
void AUTHSTRTSTT_vidInhCrkAlt(void);
void AUTHSTRTSTT_vidInhCrkAltHw(void);
void AUTHSTRTSTT_vidInitialisation(void);


#endif /* AUTHSTRTSTT_L_H */

/*-------------------------------- end of file -------------------------------*/
