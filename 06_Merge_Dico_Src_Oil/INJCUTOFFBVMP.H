/***************************************************************************
;**
;** FILE NAME      : INJCUTOFFBVMP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCUTOFFBVMP_H
#define INJCUTOFFBVMP_H

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

extern const boolean  InjCutOff_bAcvBvmpFcoReq;
extern const boolean  InjCutOff_bAcvIdlSysFco;
extern const uint16  InjCutOff_nRegThdBvmpCutOff;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Bvmp_fco_request;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void InjCutOff_EveRst_InjCutOffBvmp(void);
void InjCutOff_SdlFast_InjCutOffBvmp(void);


#endif /* INJCUTOFFBVMP_H */

/*-------------------------------- end of file -------------------------------*/
