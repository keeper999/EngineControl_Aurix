/***************************************************************************
;**
;** FILE NAME      : AVRMISFCNT.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "AVRMISFCNT.H"
#include "AVRMISFCNT_L.H"
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
const uint8  AVRMISFCNT_u8Inhib = 0;
const uint8  MonMisf_facEWMACyl_C = 0;
const uint16  MonMisf_nEngMinAcvCtMfAvg_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean AVRMISFCNT_bMfMisfDetecUavb0Prev;
boolean Mf_1_mf_Mod6_uavb0;
boolean Mf_2_mf_Mod6_uavb0;
boolean Misf_bEnaMisfCntCyl1;
boolean Misf_bEnaMisfCntCyl2;
boolean Misf_bEnaMisfCntCyl3;
boolean Misf_bEnaMisfCntCyl4;
uint8 AVRMISFCNT_u8MfNoCyMod6Uavb0Prev;
uint8 Mf_no_cyl_mod6_uavb0;
uint16 MonMisf_ctOccurMfAvg10DCCyl1;
uint16 MonMisf_ctOccurMfAvg10DCCyl2;
uint16 MonMisf_ctOccurMfAvg10DCCyl3;
uint16 MonMisf_ctOccurMfAvg10DCCyl4;
uint16 MonMisf_ctOccurMfDCCyl1;
uint16 MonMisf_ctOccurMfDCCyl1_Raw;
uint16 MonMisf_ctOccurMfDCCyl2;
uint16 MonMisf_ctOccurMfDCCyl2_Raw;
uint16 MonMisf_ctOccurMfDCCyl3;
uint16 MonMisf_ctOccurMfDCCyl3_Raw;
uint16 MonMisf_ctOccurMfDCCyl4;
uint16 MonMisf_ctOccurMfDCCyl4_Raw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

