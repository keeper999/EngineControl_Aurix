/***************************************************************************
;**
;** FILE NAME      : ISLIN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ISLIN_H
#define ISLIN_H

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

/* enum st112 */
#define CLASS_7                           0
#define CLASS_8                           1
#define RESERVE_1                         2
#define CLASS_12                          4
#define CLASS_18                          5
#define CLASS_15                          6
#define CLASS_22                          7
#define RESERVE_3                         8
#define RESERVE_4                         9
#define RESERVE_5                         10
#define RESERVE_6                         11
#define RESERVE_7                         12
#define RESERVE_8                         13
#define RESERVE_9                         14
#define RESERVE_10                        15
#define RESERVE_11                        16
#define RESERVE_12                        17
#define RESERVE_13                        18
#define RESERVE_14                        19
#define RESERVE_15                        20
#define RESERVE_16                        21
#define RESERVE_17                        22
#define RESERVE_18                        23
#define RESERVE_19                        24
#define RESERVE_20                        25
#define RESERVE_21                        26
#define RESERVE_22                        27
#define RESERVE_23                        28
#define RESERVE_24                        29
#define RESERVE_25                        30
#define RESERVE_26                        31
#define RESERVE_2                         32
/*extern uint8 Class;*/


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
extern uint8 Class;
extern boolean AltCtl_bFctlDft;
extern boolean AltCtl_dftComAlt;
extern boolean AltCtl_dftElecAlt;
extern boolean AltCtl_dftHiTAlt;
extern boolean AltCtl_dftMecAlt;
extern uint8 AltCtl_iAlt;
extern uint8 AltCtl_idxAltProv;
extern uint8 AltCtl_rAltCycOpRate;
extern uint8 IsLin_idxAltClas;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ISLIN_vidCmdeAlt(void);
void ISLIN_vidEveRst(void);
void ISLIN_vidEveRxnEtatAlt1(void);
void ISLIN_vidEveRxnEtatAlt2(void);
void ISLIN_vidSdlFast(void);
void ISLIN_vidSdlMid(void);


#endif /* ISLIN_H */

/*-------------------------------- end of file -------------------------------*/
