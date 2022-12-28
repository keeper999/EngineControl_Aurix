/***************************************************************************
;**
;** FILE NAME      : INJCUTOFFBVMP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INJCUTOFFBVMP_L_H
#define INJCUTOFFBVMP_L_H

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

extern const uint8  INJCUTOFFBVMP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean INJCUTOFFBVMP_bHystOut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INJCUTOFFBVMP_vidAcvBvmpFco(void);
void INJCUTOFFBVMP_vidCalcBVMPFCO(void);
void INJCUTOFFBVMP_vidDisBvmpFco(void);
void INJCUTOFFBVMP_vidInitBVMPFCO(void);
void INJCUTOFFBVMP_vidInitOutput(void);


#endif /* INJCUTOFFBVMP_L_H */

/*-------------------------------- end of file -------------------------------*/
