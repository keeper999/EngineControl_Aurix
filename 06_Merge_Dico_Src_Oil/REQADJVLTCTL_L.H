/***************************************************************************
;**
;** FILE NAME      : REQADJVLTCTL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef REQADJVLTCTL_L_H
#define REQADJVLTCTL_L_H

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

extern const uint8  REQADJVLTCTL_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean LsSys_bAcv_stLsDsMainOxC;
extern boolean LsSys_bAcv_stLsUsMainOxC;
extern boolean LsSys_bComp_uBatt2LsDsMainOxC;
extern boolean LsSys_bComp_uBatt2LsUsMainOxC;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void REQADJVLTCTL_vidInitReqAdjVltCtl(void);
void REQADJVLTCTL_vidTraitReqAdjVltCt(void);


#endif /* REQADJVLTCTL_L_H */

/*-------------------------------- end of file -------------------------------*/
