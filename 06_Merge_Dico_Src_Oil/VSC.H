/***************************************************************************
;**
;** FILE NAME      : VSC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VSC_H
#define VSC_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean VSCtl_bVSregDeacAcceNotCoh;
extern boolean VSCtl_bVSregDeacAutBrk;
extern boolean VSCtl_bVSregDeacBrkPedPress;
extern boolean VSCtl_bVSregDeacDrvCmd;
extern boolean VSCtl_bVSregDeacEngNotAvl;
extern boolean VSCtl_bVSregDeacGBxGearDft;
extern boolean VSCtl_bVSregDeacGBxLev;
extern boolean VSCtl_bVSregDeacGear;
extern boolean VSCtl_bVSregDeacPtOp;
extern boolean VSCtl_bVSregDeacSecuLvl;
extern boolean VSCtl_bVSregDeacVehReg;
extern boolean VSCtl_bVSregDeacVhlSpdGap;
extern uint32 VSCtl_tiCurVehTmr;
extern uint8 VSCtl_noEgdGearCord;
extern uint8 VSCtl_rAccP;
extern uint8 VSCtl_spdVehicle;
extern uint8 VSCtl_spdVehVSRegReq;
extern uint16 VSCtl_nEng;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VSCTL_EveRst_LstCrsCtlDeacCaus(void);
void VSCTL_SdlMid_LstCrsCtlDeacCaus(void);


#endif /* VSC_H */

/*-------------------------------- end of file -------------------------------*/
