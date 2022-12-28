/***************************************************************************
;**
;** FILE NAME      : STTRALD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "STTRALD.H"
#include "STTRALD_L.H"
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
const uint8  InM_StabToTranThd_T[INM_STABTOTRANTHD_T_COLS] = {0};
const uint8  InM_TranToStabThd_T[INM_TRANTOSTABTHD_T_COLS] = {0};
const uint8  STTRALD_u8Inhib = 0;
const uint16  InM_mfTotExCor_A[INM_MFTOTEXCOR_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Eng_bAccEng;
uint8 InM_StabToTranThd_stTraLd;
uint8 InM_stTraLd;
uint8 InM_TranToStabThd_stTraLd;
sint16 InM_mfDif_stTraLd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

