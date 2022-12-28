/***************************************************************************
;**
;** FILE NAME      : BUFNES_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BUFNES_L_H
#define BUFNES_L_H

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

extern const uint8  BUFNES_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean BufNEs_bAcvClcBufNEs;
extern boolean BufNEs_bClcBufNEs;
extern boolean BUFNES_bRSTPrev;
extern uint8 BufNEs_noNFillTiRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BUFNES_vidActivateCalcBufRecord(void);
void BUFNES_vidGlobal_View(void);
void BUFNES_vidInitOutput(void);
void BUFNES_vidRcrdCrankshafToothDrt(void);
void BUFNES_vidRplceOutptIfCalcDisabl(void);


#endif /* BUFNES_L_H */

/*-------------------------------- end of file -------------------------------*/
