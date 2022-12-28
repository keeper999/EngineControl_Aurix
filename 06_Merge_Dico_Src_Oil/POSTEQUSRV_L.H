/***************************************************************************
;**
;** FILE NAME      : POSTEQUSRV_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef POSTEQUSRV_L_H
#define POSTEQUSRV_L_H

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

extern const uint8  POSTEQUSRV_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Srv_bPostEquVld;
extern uint8 POSTEQUSRV_u8stPostEcuStatPrev;
extern uint16 Srv_tiWaitDelayPostEqu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void POSTEQUSRV_vidDataVerification(void);
void POSTEQUSRV_vidInfoWrite(void);
void POSTEQUSRV_vidInitEEP(void);
void POSTEQUSRV_vidInitOutput(void);
void POSTEQUSRV_vidReInit(void);
void POSTEQUSRV_vidVarCodMng(void);
void POSTEQUSRV_vidWrite(void);


#endif /* POSTEQUSRV_L_H */

/*-------------------------------- end of file -------------------------------*/
