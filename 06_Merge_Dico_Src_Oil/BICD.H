/***************************************************************************
;**
;** FILE NAME      : BICD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BICD_H
#define BICD_H

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

extern const boolean  Ext_bStaCmdFctSt_C;
extern const uint8  Ext_noDftStaCmdHiThd_C;
extern const uint8  Ext_noDftStaCmdLoThd_C;
extern const uint16  Ext_uDgoScg_DftStaCmd_C;
extern const uint16  Ext_uDgoScp_DftStaCmd_C;
extern const uint16  Ext_uMaxDftStaCmd_C;
extern const uint16  Ext_uMaxNoDftStaCmd_C;
extern const uint16  Ext_uMinDftStaCmd_C;
extern const uint16  Ext_uMinNoDftStaCmd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Ext_uDftStaCmdRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EngSt_EveRst_DftStaCmd(void);
void EngSt_SdlFast_DftStaCmd(void);


#endif /* BICD_H */

/*-------------------------------- end of file -------------------------------*/
