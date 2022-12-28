/***************************************************************************
;**
;** FILE NAME      : GMIL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GMIL_L_H
#define GMIL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GMIL_EVE_KEYON                    1
#define GMIL_EVE_RST                      2
#define GMIL_EVE_SLOW                     0

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

extern const uint8  GMIL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GMIL_bStrtMilOn;
extern uint8 GMIL_tiStrtMng;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GMIL_DftAndWarnSt(void);
void GMIL_DftSt(void);
void GMIL_Init(void);
void GMIL_MilReqCanConf(void);
void GMIL_Req(uint8 u8Event);
void GMIL_StrtCntIni(void);
void GMIL_StrtMng(void);
void GMIL_vidInitOutput(void);


#endif /* GMIL_L_H */

/*-------------------------------- end of file -------------------------------*/
