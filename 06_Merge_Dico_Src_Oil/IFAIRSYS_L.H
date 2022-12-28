/***************************************************************************
;**
;** FILE NAME      : IFAIRSYS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IFAIRSYS_L_H
#define IFAIRSYS_L_H

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

extern const uint8  IFAIRSYS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern sint32 IFAIRSYS_s32OutputMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IFAIRSYS_vidAccP(void);
void IFAIRSYS_vidBoostPressure(void);
void IFAIRSYS_vidCrkMgt(void);
void IFAIRSYS_vidCrkMgt2(void);
void IFAIRSYS_vidEngSt(void);
void IFAIRSYS_vidInitCrkMgt(void);
void IFAIRSYS_vidInitFilter(void);
void IFAIRSYS_vidInitOutput(void);
void IFAIRSYS_vidInj(void);
void IFAIRSYS_vidmfAirMid2(void);
void IFAIRSYS_vidNEngGrd(void);
void IFAIRSYS_vidThr(void);
void IFAIRSYS_vidVehRun(void);


#endif /* IFAIRSYS_L_H */

/*-------------------------------- end of file -------------------------------*/
