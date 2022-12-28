/***************************************************************************
;**
;** FILE NAME      : HPPMPACTCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HPPMPACTCMD_L_H
#define HPPMPACTCMD_L_H

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

extern const uint8  HPPmpActCmd_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_HPPmpActCmd;
extern boolean Ext_bDgoOvld_HPPmpActCmd;
extern boolean Ext_bDgoScp_HPPmpActCmd;
extern boolean Ext_bMonRunOc_HPPmpActCmd;
extern boolean Ext_bMonRunOvld_HPPmpActCmd;
extern boolean Ext_bMonRunScp_HPPmpActCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HPPmpActCmd_vidbStopHPPmpActCmd(void);
void HPPmpActCmd_vidHPPmpActCmd_DiagEl(void);
void HPPmpActCmd_vidHPPmpActCmd_Init(void);


#endif /* HPPMPACTCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
