/***************************************************************************
;**
;** FILE NAME      : ACTRTSTFARSP.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ACTRTSTFARSP.H"
#include "ACTRTSTFARSP_L.H"
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
const boolean  FarSp_bInhSenO2UsEEDiag_C = 0;
const uint8  ACTRTSTFARSP_u8Inhib = 0;
const uint8  Afts_uAflRlamSpTest_C = 0;
const uint8  Afts_uAfrRlamSpTest_C = 0;
const uint16  ActrTstFarSp_Tempo_C = 0;
const uint16  Afts_rMixtReqAflRlamSpTest_C = 0;
const uint16  Afts_rMixtReqAfrRlamSpTest_C = 0;
const uint16  Afts_tiDlyPha1RlamSpTest_C = 0;
const uint16  Afts_tiDlyPha2RlamSpTest_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 FarSp_stActrTst;
boolean FarSp_bActrTstCmpl;
boolean FarSp_bTstInProgs;
boolean FarSp_bUsPlausFcoActrTst;
boolean FarSp_bUsPlausFldActrTst;
uint16 ActrTstFarSp_Tempo;
uint16 ActrTstFarSp_TstTime;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

