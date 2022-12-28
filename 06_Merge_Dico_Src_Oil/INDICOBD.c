/***************************************************************************
;**
;** FILE NAME      : INDICOBD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
#include "INDICOBD.H"
#include "INDICOBD_L.H"
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
const boolean  GMIL_bCfgExtDistMilOn_C = 0;
const uint8  INDICOBD_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean GMIL_bEngRun;
boolean INDICOBD_bDstCntRstCdnPrev;
uint32 Dist_hecto_depuis_RstDft;
uint32 Dist_hecto_parcourue_depuis_mil;
uint32 GMIL_tiEngrunMilOn;
uint32 GMIL_tiEngrunRstDft;
uint8 INDICOBD_u8ctDftObdCfPrev;
uint16 IndicOBD_DstHecto_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

