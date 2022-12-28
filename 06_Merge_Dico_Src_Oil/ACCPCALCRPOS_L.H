/***************************************************************************
;**
;** FILE NAME      : ACCPCALCRPOS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACCPCALCRPOS_L_H
#define ACCPCALCRPOS_L_H

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

extern const uint8  ACCPCALCRPOS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 ACCPCALCRPOS_u16DvPsPedRlApsPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACCPCALCRPOS_vidAcquisitionDVApp(void);
void ACCPCALCRPOS_vidApsPedPos(void);
void ACCPCALCRPOS_vidDetection_aps(void);
void ACCPCALCRPOS_vidDVApp(void);
void ACCPCALCRPOS_vidEtat_pos_aps(void);
void ACCPCALCRPOS_vidFinal_Detection(void);
void ACCPCALCRPOS_vidFinal_state_Pos(void);
void ACCPCALCRPOS_vidInit(void);


#endif /* ACCPCALCRPOS_L_H */

/*-------------------------------- end of file -------------------------------*/
