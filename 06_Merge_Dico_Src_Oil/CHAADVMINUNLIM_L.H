/***************************************************************************
;**
;** FILE NAME      : CHAADVMINUNLIM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CHAADVMINUNLIM_L_H
#define CHAADVMINUNLIM_L_H

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

extern const uint8  CHAADVMINUNLIM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CHAADVMINUNLIM_bInitCndPrev;
extern boolean CHAADVMINUNLIM_bTimeOut;
extern boolean Ext_bASRSecuReq_flag1;
extern boolean Ext_bASRSecuReq_flag2;
extern uint8 Ext_ctSdlASRSecuReq;
extern uint16 Ext_tiTmrASRReg;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CHAADVMINUNLIM_vidASRReg(void);
void CHAADVMINUNLIM_vidASRSecuReq(void);
void CHAADVMINUNLIM_vidESPReg(void);
void CHAADVMINUNLIM_vidEventMs(void);
void CHAADVMINUNLIM_vidInit(void);
void CHAADVMINUNLIM_vidInitOutput(void);
void CHAADVMINUNLIM_vidRearWheelSpeed(void);
void CHAADVMINUNLIM_vidRstSelc(void);


#endif /* CHAADVMINUNLIM_L_H */

/*-------------------------------- end of file -------------------------------*/
