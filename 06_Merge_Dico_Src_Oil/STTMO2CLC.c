/***************************************************************************
;**
;** FILE NAME      : STTMO2CLC.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "STTMO2CLC.H"
#include "STTMO2CLC_L.H"
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
const sint8  Eng_FacmO2DownLsLean_UpLean_C = 0;
const sint8  Eng_FacmO2DownLsLean_UpRich_C = 0;
const sint8  Eng_FacmO2DownLsRich_UpLean_C = 0;
const sint8  Eng_FacmO2DownLsRich_UpRich_C = 0;
const uint8  STTMO2CLC_u8Inhib = 0;
const uint16  Eng_FacmO2Stall_C = 0;
const uint16  Eng_mO2EstimOxCInit_C = 0;
const uint16  Eng_VoltDownLsHighLim_C = 0;
const uint16  Eng_VoltDownLsHighLowLim_C = 0;
const uint16  Eng_VoltDownLsLowHighLim_C = 0;
const uint16  Eng_VoltDownLsLowLim_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Eng_VoltDownLsHigh;
boolean Eng_VoltDownLsLow;
boolean STTMO2CLC_bMot_tournPrev;
uint8 Eng_ctTDCStrt;
uint16 Eng_mO2Cat;
uint16 Eng_mO2Cat_Err;
uint16 Eng_mO2Cat_Norm;
uint16 STTMO2CLC_u16VoltDownLsPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

