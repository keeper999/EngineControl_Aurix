/***************************************************************************
;**
;** FILE NAME      : VEHMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VEHMNG_L_H
#define VEHMNG_L_H

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

extern const uint8  VEHMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VEHMNG_bInhClcnDstCoveredPrev;
extern uint32 Distance_parcourue_totale;
extern uint32 Distance_parcourue_totale_prev;
extern uint32 VEHMNG_u32VitesseVehFiltreeMem;
extern uint16 Distance_parcourue_prev;
extern uint16 VEHMNG_u16DistanceParcourue;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VEHMNG_vidCanTranSpeedManagement(void);
void VEHMNG_vidClcDistTraveledViaCAN(void);
void VEHMNG_vidClcDistTraveledViaWire(void);
void VEHMNG_vidCmmTranSpeedManagement(void);
void VEHMNG_vidDistTraveledViaCAN(void);
void VEHMNG_vidDistTraveledViaWire(void);
void VEHMNG_vidVehDstClcMng(void);
void VEHMNG_vidVehicleSpeedFiltered(void);
void VEHMNG_vidVehSdpMngInit(void);
void VEHMNG_vidVehSpdInformation(void);
void VEHMNG_vidVehSpdMngCanCmm(void);


#endif /* VEHMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
