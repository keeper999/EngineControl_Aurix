/***************************************************************************
;**
;** FILE NAME      : ACTRTSTFARSP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTFARSP_L_H
#define ACTRTSTFARSP_L_H

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

extern const uint8  ACTRTSTFARSP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 ActrTstFarSp_Tempo;
extern uint16 ActrTstFarSp_TstTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ACTRTSTFARSP_vidFarSpUsActrTst(void);
void ACTRTSTFARSP_vidFarSpUsLeanTst(void);
void ACTRTSTFARSP_vidFarSpUsMainTst(void);
void ACTRTSTFARSP_vidFarSpUsRichTst(void);
void ACTRTSTFARSP_vidInitOutput(void);
void ACTRTSTFARSP_vidTransition_END(void);
void ACTRTSTFARSP_vidTransition_IDLE(void);


#endif /* ACTRTSTFARSP_L_H */

/*-------------------------------- end of file -------------------------------*/
