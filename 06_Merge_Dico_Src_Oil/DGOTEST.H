/***************************************************************************
;**
;** FILE NAME      : DGOTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DGOTEST_H
#define DGOTEST_H

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

extern const boolean  DgoTest_bDgoAaStart_Bidon_C;
extern const boolean  DgoTest_bDgoZzEnd_Bidon_C;
extern const boolean  DgoTest_bMonRunAaStart_Bidon_C;
extern const boolean  DgoTest_bMonRunZzEnd_Bidon_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DgoTest_bDgoAaStart_Bidon;
extern boolean DgoTest_bDgoZzEnd_Bidon;
extern boolean DgoTest_bMonRunAaStart_Bidon;
extern boolean DgoTest_bMonRunZzEnd_Bidon;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DGOTEST_vidSdlSlow(void);


#endif /* DGOTEST_H */

/*-------------------------------- end of file -------------------------------*/
