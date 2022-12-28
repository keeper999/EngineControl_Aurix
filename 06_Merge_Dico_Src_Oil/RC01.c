/***************************************************************************
;**
;** FILE NAME      : RC01.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "RC01.H"
#include "RC01_L.H"
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
const boolean  Rdy_bDftValCat_C = 0;
const boolean  Rdy_bDftValClim_C = 0;
const boolean  Rdy_bDftValCpt_C = 0;
const boolean  Rdy_bDftValEVAP_C = 0;
const boolean  Rdy_bDftValHeatCat_C = 0;
const boolean  Rdy_bDftValHeatO2_C = 0;
const boolean  Rdy_bDftValIAE_C = 0;
const boolean  Rdy_bDftValLfbk_C = 0;
const boolean  Rdy_bDftValMisf_C = 0;
const boolean  Rdy_bDftValO2S_C = 0;
const boolean  Rdy_bDftValVVT_C = 0;
const uint8  RC01_u8Inhib = 0;
const uint16  ClasRdyCat_T[CLASRDYCAT_T_COLS] = {0};
const uint16  ClasRdyHeatO2_T[CLASRDYHEATO2_T_COLS] = {0};
const uint16  ClasRdyLfbk_T[CLASRDYLFBK_T_COLS] = {0};
const uint16  ClasRdyMisf_T[CLASRDYMISF_T_COLS] = {0};
const uint16  ClasRdyO2S_T[CLASRDYO2S_T_COLS] = {0};
const uint16  ClasRdyVVT_T[CLASRDYVVT_T_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean GD_bPrioRdy[GD_BPRIORDY_LNS];
uint8 Rdy_au8ctDC[RDY_AU8CTDC_LNS];
uint8 Rdy_u8ClasRdyLSB;
uint8 Rdy_u8ClasRdyMSB;
uint16 Rdy_u16ClasRdy_EEPROM_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

