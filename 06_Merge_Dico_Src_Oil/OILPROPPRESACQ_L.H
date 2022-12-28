/***************************************************************************
;**
;** FILE NAME      : OILPROPPRESACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILPROPPRESACQ_L_H
#define OILPROPPRESACQ_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_PRM_UPRESOILMESMEM_COLS            ( 12 )
#define OILPROPPRESACQ_u32OIL_PMAX_SC     62500
#define OILPROPPRESACQ_u32OIL_PMIN_SC     3125

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

extern const uint8  OILPROPPRESACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoScg_pOilMes;
extern boolean Ext_bDgoScp_pOilMes;
extern boolean Ext_bMonRunScg_pOilMes;
extern boolean Ext_bMonRunScp_pOilMes;
extern boolean Oil_bAcvOilPresAcq;
extern boolean OILPROPPRESACQ_bAcqCondHystOut;
extern boolean OILPROPPRESACQ_bHystOutput;
extern uint32 OILPROPPRESACQ_u32OilActFilMEM;
extern uint8 Ext_upOilMesCoef_MP;
extern uint16 Ext_pOilMesPrev;
extern uint16 Ext_pOilMesRaw_bornee;
extern uint16 Ext_prm_uPresOilMesMem[EXT_PRM_UPRESOILMESMEM_COLS];
extern uint16 Oil_upOilMesAct;
extern uint16 Oil_upOilMesMean;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OILPROPPRESACQ_vidInitialization(void);
void OILPROPPRESACQ_vidInitOilPrsFilt(void);
void OILPROPPRESACQ_vidInitOutput(void);
void OILPROPPRESACQ_vidInitPrsAcqMean(void);
void OILPROPPRESACQ_vidOilAcqCond(void);
void OILPROPPRESACQ_vidOilDiag(void);
void OILPROPPRESACQ_vidOilPresAcqMean(void);
void OILPROPPRESACQ_vidOilPresFilter(void);
void OILPROPPRESACQ_vidOilPresInfoAcq(void);
void OILPROPPRESACQ_vidOilPresMesAcq(void);
void OILPROPPRESACQ_vidOilPressDiag(void);
void OILPROPPRESACQ_vidOilPressTreat(void);
void OILPROPPRESACQ_vidOilSdlFastEna(void);


#endif /* OILPROPPRESACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
