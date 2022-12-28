/***************************************************************************
;**
;** FILE NAME      : BICD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BICD_L_H
#define BICD_L_H

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

extern const uint8  BICD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoInvld_uDftStaCmd;
extern boolean Ext_bDgoScg_uDftStaCmd;
extern boolean Ext_bDgoScp_uDftStaCmd;
extern boolean Ext_bMonRunInvld_uDftStaCmd;
extern boolean Ext_bMonRunScg_uDftStaCmd;
extern boolean Ext_bMonRunScp_uDftStaCmd;
extern boolean Ext_bStaCmdFctStFilt;
extern boolean Ext_bStaCmdFctStMes;
extern uint8 BICD_u8AntiBounceCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BICD_vidDftStaCmdAcq(void);
void BICD_vidDftStaCmdDiag(void);
void BICD_vidDftStaCmdInit(void);
void BICD_vidDftStaCmdSelection(void);
void BICD_vidDiagInvalide(void);
void BICD_vidDiagScpScp(void);
void BICD_vidFastFunCall(void);
void BICD_vidInitOutput(void);


#endif /* BICD_L_H */

/*-------------------------------- end of file -------------------------------*/
