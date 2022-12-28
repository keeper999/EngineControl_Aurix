/***************************************************************************
;**
;** FILE NAME      : MUXTQREQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef MUXTQREQ_H
#define MUXTQREQ_H

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

/* enum st300 */
#define FONCTIONNEMENT_NOMINAL            0
#define LIM_CPLE                          1
#define LIM_CPLE_EFFECTIVE                2
#define LIM_REGIME                        3
#define LIM_REGIME_EFFECTIVE              4
#define LIM_REGIME_SEV                    5
#define LIM_REGIME_SEV_EFFECTIVE          6
#define REGUL_REGIME                      7
/*extern uint8 REOM_stEngOpm;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  MUXTQREQ_u8Inhib;
extern const sint16  Ext_nEngSpdLimHiOfs_C;
extern const sint16  Ext_nEngSpdLimLoOfs_C;
extern const sint16  Ext_tqLimOfs_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 REOM_stEngOpm;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TqSys_EveRst_MuxTqReq(void);
void TqSys_SdlMid_MuxTqReq(void);


#endif /* MUXTQREQ_H */

/*-------------------------------- end of file -------------------------------*/
