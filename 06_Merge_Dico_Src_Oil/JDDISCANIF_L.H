/***************************************************************************
;**
;** FILE NAME      : JDDISCANIF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef JDDISCANIF_L_H
#define JDDISCANIF_L_H

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

extern const uint8  JDDISCANIF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Jbsi_pertinence_info_cmm;
extern uint8 Jbsi_etat_rcd_tx;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void JDDISCANIF_vid1Trame(void);
void JDDISCANIF_vid3Trames(void);
void JDDISCANIF_vidAEE2004Treat(void);
void JDDISCANIF_vidAEE2010Treat(void);
void JDDISCANIF_vidDftCodTreat(void);
void JDDISCANIF_vidDftTime(void);
void JDDISCANIF_vidDstTreat(void);
void JDDISCANIF_vidHdTreat(void);
void JDDISCANIF_vidInit(void);
void JDDISCANIF_vidPrepaDataISCAN(void);
void JDDISCANIF_vidRcdTreat(void);
void JDDISCANIF_vidRemplissageTrame1(void);
void JDDISCANIF_vidRemplissageTrame2(void);
void JDDISCANIF_vidRemplissageTrame3(void);
void JDDISCANIF_vidVehCdn(void);


#endif /* JDDISCANIF_L_H */

/*-------------------------------- end of file -------------------------------*/
