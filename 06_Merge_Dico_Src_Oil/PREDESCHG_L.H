/***************************************************************************
;**
;** FILE NAME      : PREDESCHG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PREDESCHG_L_H
#define PREDESCHG_L_H

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

extern const uint8  PREDESCHG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean PredEsChg_bAcvCalcPredEs;
extern boolean PredEsChg_bCalcPredEs;
extern boolean PredEsChg_bDirRotCk_MP;
extern boolean PREDESCHG_bVld;
extern boolean PredEsChg_bVldFastN;
extern uint32 PredEsChg_tiCgt_MP;
extern uint32 PredEsChg_tiCgtLst_MP;
extern uint8 PredEsChg_ctEdgeCk_MP;
extern uint8 PREDESCHG_u8ExtctEdgeCk;
extern uint8 PREDESCHG_u8ExtctEdgeCkPrev;
extern sint16 PredEsChg_nFast;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PREDESCHG_vidEffectCalcRegInsta(void);
void PREDESCHG_vidEffectSwitchCasVie(void);
void PREDESCHG_vidInhibCalcRegHautReg(void);
void PREDESCHG_vidInitOutput(void);
void PREDESCHG_vidPredEsChgDraft(void);


#endif /* PREDESCHG_L_H */

/*-------------------------------- end of file -------------------------------*/
