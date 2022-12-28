/***************************************************************************
;**
;** FILE NAME      : CSTRCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRCMD_L_H
#define CSTRCMD_L_H

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

extern const uint8  CSTRCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Cstr_bDgoHiCstrDrv;
extern boolean Cstr_bDgoLoCstrDrv;
extern boolean Cstr_bMonRunHiCstrDrv;
extern boolean Cstr_bMonRunLoCstrDrv;
extern boolean CSTRCMD_bMaxHysOut;
extern boolean CSTRCMD_bMinHysOut;
extern uint8 Rco_applique_purge_corr;
extern uint8 Rco_applique_purge_final;
extern sint16 CSTRCMD_s16ExtuBattMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CSTRCMD_vidCmd(void);
void CSTRCMD_vidDiag(void);
void CSTRCMD_vidInitOutput(void);


#endif /* CSTRCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
