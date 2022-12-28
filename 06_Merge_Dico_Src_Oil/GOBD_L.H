/***************************************************************************
;**
;** FILE NAME      : GOBD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GOBD_L_H
#define GOBD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "GD_API.h"
#include "GDFRM.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define UINT16_VAL_MAX                    65535

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GOBD_bMemRg;
extern boolean Ns_bCntAcv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GOBD_vidAutomate(uint16 u16IdxDft);
void GOBD_vidAutomateRstDft(uint16 u16IdxDft);
void GOBD_vidAutomateUnval(uint16 u16IdxDft);
void GOBD_vidCDThdUp(uint16 u16IdxDft);
void GOBD_vidClrCntWUC(uint16 u16IdxDft);
void GOBD_vidCntWUC(uint16 u16IdxDft);
void GOBD_vidExitEveKeyOBD(void);
void GOBD_vidExitEveStObd(uint16 u16IdxDft);
void GOBD_vidF07_MngAutomateExit(uint16 u16IdxDft);
void GOBD_vidGlbDC(uint16 u16IdxDft);
void GOBD_vidIniCntWUC(uint16 u16IdxDft);
void GOBD_vidInit(void);
void GOBD_vidInitTiSinceEngStrt(void);
void GOBD_vidRstCntDC(uint16 u16IdxDft);
void GOBD_vidRstKeyOBD(void);
void GOBD_vidSetKeyOBD(void);
void GOBD_vidTiSinceEngStrt(void);
void GOBD_vidTransEnregistre(uint16 u16IdxDft);
void GOBD_vidTransHistoOff(uint16 u16IdxDft);
void GOBD_vidTransHistoOn(uint16 u16IdxDft);
void GOBD_vidTransOK(uint16 u16IdxDft);
void GOBD_vidTransPending1(uint16 u16IdxDft);
void GOBD_vidTransPending2(uint16 u16IdxDft);
void GOBD_vidWriteCntAcv(boolean bValue);
boolean GOBD_bMngAutomateTrans(uint16 u16IdxDft);


#endif /* GOBD_L_H */

/*-------------------------------- end of file -------------------------------*/
