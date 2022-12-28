/***************************************************************************
;**
;** FILE NAME      : TCOREGKNK.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TCOREGKNK.H"
#include "TCOREGKNK_L.H"
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
const boolean  IgSys_bInhIgSysTCoColdReq_C = 0;
const sint8  IgSys_agIgDeltaAcvEngColdReq_C = 0;
const sint8  IgSys_agIgDeltaInhEngColdReq_C = 0;
const uint8  IgSys_facFilDeltaAgIg_T[IGSYS_FACFILDELTAAGIG_T_COLS] = {0};
const uint8  TCOREGKNK_u8Inhib = 0;
const uint16  IgSys_nEng_IgSysTCoColdReq_A[IGSYS_NENG_IGSYSTCOCOLDREQ_A_COLS] = {0};
const uint16  IgSys_tiEngColdReq_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IgSys_bAcvEngColdReq;
boolean IgSys_bAuthIgSysTCoColdReq;
boolean TCOREGKNK_bAcvCond;
boolean TCOREGKNK_bTmrOut;
sint8 IgSys_agIgDeltaEngColdReq_MP;
uint8 IgSys_facFilDeltaAgIg_MP;
uint16 TCOREGKNK_u16Cnt;
sint32 TCOREGKNK_s32FiltPosErrorMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

