/***************************************************************************
;**
;** FILE NAME      : DRVRSENO2DS.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "DRVRSENO2DS.H"
#include "DRVRSENO2DS_L.H"
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
const uint8  DRVRSENO2DS_u8Inhib = 0;
const uint16  Ichauff_min_SenO2Ds = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean DRVRSENO2DS_bDiagEnable;
boolean Ext_bDgoHi_DrvrSenO2Ds;
boolean Ext_bDgoLo_DrvrSenO2Ds;
boolean Ext_bMonRunHi_DrvrSenO2Ds;
boolean Ext_bMonRunLo_DrvrSenO2Ds;
uint8 DRVRSENO2DS_u8SdlDiagCall;
uint16 Ext_uEcuDsMes;
uint16 Ichauff_SO2Ds;
uint16 Rchauff_SO2Ds;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

