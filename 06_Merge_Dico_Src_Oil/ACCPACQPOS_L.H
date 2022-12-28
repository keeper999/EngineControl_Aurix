/***************************************************************************
;**
;** FILE NAME      : ACCPACQPOS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPACQPOS_L_H
#define ACCPACQPOS_L_H

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

extern const uint8  ACCPACQPOS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ACCPACQPOS_bInitFilter1;
extern boolean ACCPACQPOS_bInitFilter2;
extern boolean Ext_bDgoCoh_Ped;
extern boolean Ext_bDgoDftSenr_AccP;
extern boolean Ext_bDgoScg_Ped1;
extern boolean Ext_bDgoScg_Ped2;
extern boolean Ext_bDgoScpOc_Ped1;
extern boolean Ext_bDgoScpOc_Ped2;
extern boolean Ext_bMonRunCoh_Ped;
extern boolean Ext_bMonRunDftSenr_AccP;
extern boolean Ext_bMonRunScg_Ped1;
extern boolean Ext_bMonRunScg_Ped2;
extern boolean Ext_bMonRunScpOc_Ped1;
extern boolean Ext_bMonRunScpOc_Ped2;
extern uint32 ACCPACQPOS_u32FiltrePositionMem1;
extern uint32 ACCPACQPOS_u32FiltrePositionMem2;
extern uint16 Aps_2_raw_position;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPACQPOS_vidDiagElecPiste1(void);
void ACCPACQPOS_vidDiagElecPiste2(void);
void ACCPACQPOS_vidDiagnosticCoh(void);
void ACCPACQPOS_vidDoubleFaultAccP(void);
void ACCPACQPOS_vidElectCoherence(void);
void ACCPACQPOS_vidInit(void);
void ACCPACQPOS_vidInitOutput(void);
void ACCPACQPOS_vidLinearFilterPiste1(void);
void ACCPACQPOS_vidLinearFilterPiste2(void);
void ACCPACQPOS_vidPanne1Measurement(void);
void ACCPACQPOS_vidPanne2Measurement(void);
void ACCPACQPOS_vidPosPedalAcquisition(void);
void ACCPACQPOS_vidRstSw(void);


#endif /* ACCPACQPOS_L_H */

/*-------------------------------- end of file -------------------------------*/
