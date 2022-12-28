/***************************************************************************
;**
;** FILE NAME      : SPDVEHSECU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPDVEHSECU_L_H
#define SPDVEHSECU_L_H

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

extern const uint8  SPDVEHSECU_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 SPDVEHSECU_U32OutputFilter1Mem;
extern uint32 SPDVEHSECU_U32OutputFilter2Mem;
extern uint32 SPDVEHSECU_U32OutputFilter3Mem;
extern uint32 SPDVEHSECU_U32OutputFilter4Mem;
extern uint16 SftyMgt_spdVehMinVal;
extern uint16 SPDVEHSECU_U16OutputFilter1;
extern uint16 SPDVEHSECU_U16OutputFilter2;
extern uint16 SPDVEHSECU_U16OutputFilter3;
extern uint16 SPDVEHSECU_U16OutputFilter4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SPDVEHSECU_vidIni(void);
void SPDVEHSECU_vidInitOutput(void);
void SPDVEHSECU_vidSecuredSpeedInfo(void);


#endif /* SPDVEHSECU_L_H */

/*-------------------------------- end of file -------------------------------*/
