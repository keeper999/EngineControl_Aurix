/***************************************************************************
;**
;** FILE NAME      : CANTXMIXMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CANTXMIXMOD.H"
#include "CANTXMIXMOD_L.H"
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
const uint8  CANTXMIXMOD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CANTXMIXMOD_bCoPtUHbRStrtAntPrev;
boolean CANTXMIXMOD_bThMgtbPosnFSFPrev;
boolean ISCAN_bFastTxn1E8Req;
boolean ISCAN_bFastTxn468Req;
boolean ISCAN_bTxnSlow1E8Req;
uint8 CANTXMIXMOD_u8CoEmSTTstTypEmPrev;
uint8 CANTXMIXMOD_u8CoOptmElstElEPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

