/***************************************************************************
;**
;** FILE NAME      : GD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "GD.H"
#include "GD_L.H"
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
const  GD_strClasDet  GD_astrClasDet[GD_ASTRCLASDET_LNS] = {0};
const  GD_strClasDID  GD_astrClasDID[GD_ASTRCLASDID_LNS] = {0};
const  GD_strClasObd  GD_astrClasObd[GD_ASTRCLASOBD_LNS] = {0};
const  GD_tstrClasFrf  GD_astrClasFrf[GD_ASTRCLASFRF_LNS] = {0};
const uint8  GD_au8IdxClasFrf[GD_AU8IDXCLASFRF_LNS] = {0};
const uint8  GD_au8IdxClasObd[GD_AU8IDXCLASOBD_LNS] = {0};
const uint8  GD_au8IdxClassDet[GD_AU8IDXCLASSDET_LNS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean GD_bMemRstDftCal;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

