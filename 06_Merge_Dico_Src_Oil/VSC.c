/***************************************************************************
;**
;** FILE NAME      : VSC.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "VSC.H"
#include "VSC_L.H"
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
const uint8  VSC_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean VSCtl_bVSregDeacAcceNotCoh;
boolean VSCtl_bVSregDeacAutBrk;
boolean VSCtl_bVSregDeacBrkPedPress;
boolean VSCtl_bVSregDeacDrvCmd;
boolean VSCtl_bVSregDeacEngNotAvl;
boolean VSCtl_bVSregDeacGBxGearDft;
boolean VSCtl_bVSregDeacGBxLev;
boolean VSCtl_bVSregDeacGear;
boolean VSCtl_bVSregDeacPtOp;
boolean VSCtl_bVSregDeacSecuLvl;
boolean VSCtl_bVSregDeacVehReg;
boolean VSCtl_bVSregDeacVhlSpdGap;
uint32 VSCtl_tiCurVehTmr;
uint8 VSCtl_noEgdGearCord;
uint8 VSCtl_rAccP;
uint8 VSCtl_spdVehicle;
uint8 VSCtl_spdVehVSRegReq;
uint8 VSCtl_stRec_stDeacVSRegReq1Prev;
uint16 VSCtl_nEng;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

