/***************************************************************************
;**
;** FILE NAME      : IDLCMDMOD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IDLCMDMOD.H"
#include "IDLCMDMOD_L.H"
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
const boolean  TqSys_bCfNTarIdlCmbMod_C = 0;
const uint8  IDLCMDMOD_u8Inhib = 0;
const sint16  TqSys_nDecTarIdlCmbMod1_C = 0;
const sint16  TqSys_nDecTarIdlCmbMod2_C = 0;
const sint16  TqSys_nDecTarIdlCmbMod3_C = 0;
const sint16  TqSys_nDecTarIdlCmbMod4_C = 0;
const sint16  TqSys_nDecTarIdlCmbMod5_C = 0;
const sint16  TqSys_nDecTarIdlCmbMod6_C = 0;
const uint16  TqSys_nIncTarIdlCmbMod1_C = 0;
const uint16  TqSys_nIncTarIdlCmbMod2_C = 0;
const uint16  TqSys_nIncTarIdlCmbMod3_C = 0;
const uint16  TqSys_nIncTarIdlCmbMod4_C = 0;
const uint16  TqSys_nIncTarIdlCmbMod5_C = 0;
const uint16  TqSys_nIncTarIdlCmbMod6_C = 0;
const uint16  TqSys_nTarIdlCmbMod1Egd_C = 0;
const uint16  TqSys_nTarIdlCmbMod1Neut_C = 0;
const uint16  TqSys_nTarIdlCmbMod2Egd_C = 0;
const uint16  TqSys_nTarIdlCmbMod2Neut_C = 0;
const uint16  TqSys_nTarIdlCmbMod3Egd_C = 0;
const uint16  TqSys_nTarIdlCmbMod3Neut_C = 0;
const uint16  TqSys_nTarIdlCmbMod4Egd_C = 0;
const uint16  TqSys_nTarIdlCmbMod4Neut_C = 0;
const uint16  TqSys_nTarIdlCmbMod5Egd_C = 0;
const uint16  TqSys_nTarIdlCmbMod5Neut_C = 0;
const uint16  TqSys_nTarIdlCmbMod6Egd_C = 0;
const uint16  TqSys_nTarIdlCmbMod6Neut_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean TqSys_bAcvNTarIdlCmbModEgd;
uint8 TqSys_facBasModCur;
uint8 TqSys_facBasModTar;
uint8 TqSys_facTranMod;
uint8 TqSys_idxBas1ModCur;
uint8 TqSys_idxBas1ModTar;
uint8 TqSys_idxBas2ModCur;
uint8 TqSys_idxBas2ModTar;
uint16 TqSys_nTarIdlBas1ModCur;
uint16 TqSys_nTarIdlBas1ModTar;
uint16 TqSys_nTarIdlBas2ModCur;
uint16 TqSys_nTarIdlBas2ModTar;
uint16 TqSys_nTarIdlCmbMod;
uint16 TqSys_nTarIdlCmbMod1;
uint16 TqSys_nTarIdlCmbMod2;
uint16 TqSys_nTarIdlCmbMod3;
uint16 TqSys_nTarIdlCmbMod4;
uint16 TqSys_nTarIdlCmbMod5;
uint16 TqSys_nTarIdlCmbMod6;
uint16 TqSys_nTarIdlCmbMod7;
uint16 TqSys_prm_nTarIdlCmbMod[TQSYS_PRM_NTARIDLCMBMOD_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

