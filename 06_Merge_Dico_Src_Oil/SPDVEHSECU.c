/***************************************************************************
;**
;** FILE NAME      : SPDVEHSECU.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "SPDVEHSECU.H"
#include "SPDVEHSECU_L.H"
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
const uint8  SPDVEHSECU_u8Inhib = 0;
const uint16  SftyMgt_facFilSpdVeh_C = 0;
const uint16  SftyMgt_spdVeh_inh_C = 0;
const uint16  SftyMgt_spdVehIni_C = 0;
const uint16  SftyMgt_spdVehMax_inh_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint32 SPDVEHSECU_U32OutputFilter1Mem;
uint32 SPDVEHSECU_U32OutputFilter2Mem;
uint32 SPDVEHSECU_U32OutputFilter3Mem;
uint32 SPDVEHSECU_U32OutputFilter4Mem;
uint16 SftyMgt_spdVehMinVal;
uint16 SPDVEHSECU_U16OutputFilter1;
uint16 SPDVEHSECU_U16OutputFilter2;
uint16 SPDVEHSECU_U16OutputFilter3;
uint16 SPDVEHSECU_U16OutputFilter4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

