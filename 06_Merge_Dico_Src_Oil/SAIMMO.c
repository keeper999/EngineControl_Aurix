/***************************************************************************
;**
;** FILE NAME      : SAIMMO.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SAIMMO_I.h"
#include "SAIMMO.H"
#include "SAIMMO_L.H"
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
const boolean  SAIMMO_bTmpSwitchMode = 0;
const uint8  SAIMMO_CptObjEEPROM_Code = 0;
const uint8  SAIMMO_CptObjEEPROM_Etat = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Immo_bDgoImmoCodNotRead;
boolean Immo_bDgoNoAnswCtlUnit;
boolean Immo_bDgoWrgAnswCtlUnit;
boolean Immo_bEcuAwakeImmoNeed;
boolean Immo_bEngStopReq;
boolean SAIMMO_bActived;
boolean SAIMMO_bTmpSwitchMode_prev;
boolean SAIMMO_bUnlockAutho;
Struct_ObjCode_NVM SAIMMO_ObjCode;
Struct_ObjEtat_NVM SAIMMO_ObjEtat;
uint8 IMMO_stECUConf;
uint8 IMMO_stEcuPairOffStTyp;
uint8 SAIMMO_bfImmoReadStDft;
uint8 SAIMMO_IscanBufferPos1;
uint8 SAIMMO_IscanBufferPos2;
uint8 SAIMMO_IscanBufferPos3;
uint8 SAIMMO_IscanBufferPos4;
uint8 SAIMMO_IscanBufferPos5;
uint8 SAIMMO_stCANMatchOptReadSt;
uint8 SAIMMO_stLockECUReadSt;
uint8 SAIMMO_stProgImmoReadSt;
uint8 SAIMMO_u8CptObjCode;
uint8 SAIMMO_u8CptObjEtat;
uint8 SAIMMO_u8TypeContinuFrame;
uint8 Srv_noADCCodChkOutpPrm;
uint8 Srv_noADCCodWrOutpPrm;
uint8 Srv_noADCMatchOutpPrm;
uint8 Srv_stADCCodChk;
uint8 Srv_stADCCodWr;
uint8 Srv_stADCMatch;
uint8 Srv_stADCRead;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

