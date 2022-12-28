/***************************************************************************
;**
;** FILE NAME      : GDGAR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GDGAR_H
#define GDGAR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "GDFRMDEF.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DEM_CPT_TRY_EVENT_STATUS          2
#define DIAG_ACTIF                        1
#define DIAG_DISPO                        0
#define FIM_CPT_TRY_FCT_PERM              2
#define GD_BINHDIAGPWRL_COLS                   ( 972 )
#define GD_SampleTiFast_SC                10
#define GD_SampleTiMid_SC                 40
#define GD_SAMPLETISLOW_SC                1000
#define GD_STRSAVEDFTEEP_LNS                  ( 972 )

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

extern const boolean  GD_bInhDiagPwrl[GD_BINHDIAGPWRL_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GDGAR_bInitInProgress;
extern GD_tstrSaveDftEep GD_strSaveDftEep[GD_STRSAVEDFTEEP_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GDGAR_EepromRamCpyPack(void);
void GDGAR_EepromRamCpyUnpack(void);
void GDGAR_EveCrkRun(void);
void GDGAR_EveCrTst(void);
void GDGAR_EveKeyOff(void);
void GDGAR_EveKeyOn(void);
void GDGAR_EveRst(void);
void GDGAR_SdlFast(void);
void GDGAR_SdlMid(void);
void GDGAR_SdlSlow(void);
void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean bMonRun, boolean Ns_bMonWait);
void GDGAR_vidMngEveRstDftApv(void);
void GDGAR_vidMngEveRstDftObd(void);
boolean GDGAR_bGetFRM(uint16 u16IndexFRM);
boolean GDGAR_bGetEndDiagStrt(uint16 u16IdxDft);
GDFRM_tenuGDUState GDGAR_tenuGetStDgo(uint16 u16IdxDft);


#endif /* GDGAR_H */

/*-------------------------------- end of file -------------------------------*/
