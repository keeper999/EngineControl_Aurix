/***************************************************************************
;**
;** FILE NAME      : DGOTEST.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DGOTEST.H"
#include "DGOTEST_L.H"
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
const boolean  DgoTest_bDgoAaStart_Bidon_C = 0;
const boolean  DgoTest_bDgoZzEnd_Bidon_C = 0;
const boolean  DgoTest_bMonRunAaStart_Bidon_C = 0;
const boolean  DgoTest_bMonRunZzEnd_Bidon_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DgoTest_bDgoAaStart_Bidon;
boolean DgoTest_bDgoZzEnd_Bidon;
boolean DgoTest_bMonRunAaStart_Bidon;
boolean DgoTest_bMonRunZzEnd_Bidon;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

