/***************************************************************************
;**
;** FILE NAME      : PFUACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PFUACQ_L_H
#define PFUACQ_L_H

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

extern const uint8  PFUACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoCoh_PFuAcq;
extern boolean Ext_bDgoScg_PFuAcq;
extern boolean Ext_bDgoScp_PFuAcq;
extern boolean Ext_bMonRunCoh_PFuAcq;
extern boolean Ext_bMonRunScg_PFuAcq;
extern boolean Ext_bMonRunScp_PFuAcq;
extern uint32 PFUACQ_u32RailFilt_Mem;
extern uint32 PFUACQ_u32RailSplFilt_Mem;
extern uint16 Ext_upFuMesNorm;
extern uint16 Ext_upFuMesSplNorm;
extern uint16 PFuAcq_pFuRailFilt;
extern uint16 PFuAcq_pFuRailMesPrev;
extern uint16 PFuAcq_pFuRailMesSplPrev;
extern uint16 PFuAcq_pFuRailSplFilt;
extern uint16 PFuAcq_pFuRailSplMesRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PFUACQ_vidCoherencyDiagnosis(void);
void PFUACQ_vidElectrical_Diagnosis(void);
void PFUACQ_vidInit(void);
void PFUACQ_vidInitOutputs(void);
void PFUACQ_vidInj(void);
void PFUACQ_vidPrevEveInjPressureVal(void);
void PFUACQ_vidPrevRailSplPressureVal(void);
void PFUACQ_vidRailInjPressureTreat(void);
void PFUACQ_vidRailPressureDiagnosis(void);
void PFUACQ_vidRailSplPressureTreat(void);
void PFUACQ_vidSpill(void);


#endif /* PFUACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
