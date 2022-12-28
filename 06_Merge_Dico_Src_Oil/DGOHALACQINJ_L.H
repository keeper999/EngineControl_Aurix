/***************************************************************************
;**
;** FILE NAME      : DGOHALACQINJ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DGOHALACQINJ_L_H
#define DGOHALACQINJ_L_H

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

extern const uint8  DGOHALACQINJ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_Inj1Cmd;
extern boolean Ext_bDgoOc_Inj2Cmd;
extern boolean Ext_bDgoOc_Inj3Cmd;
extern boolean Ext_bDgoOc_Inj4Cmd;
extern boolean Ext_bDgoOvld_Inj1Cmd;
extern boolean Ext_bDgoOvld_Inj2Cmd;
extern boolean Ext_bDgoOvld_Inj3Cmd;
extern boolean Ext_bDgoOvld_Inj4Cmd;
extern boolean Ext_bDgoScg_Inj1Cmd;
extern boolean Ext_bDgoScg_Inj2Cmd;
extern boolean Ext_bDgoScg_Inj3Cmd;
extern boolean Ext_bDgoScg_Inj4Cmd;
extern boolean Ext_bDgoScp_Inj1Cmd;
extern boolean Ext_bDgoScp_Inj2Cmd;
extern boolean Ext_bDgoScp_Inj3Cmd;
extern boolean Ext_bDgoScp_Inj4Cmd;
extern boolean Ext_bMonRunOc_Inj1Cmd;
extern boolean Ext_bMonRunOc_Inj2Cmd;
extern boolean Ext_bMonRunOc_Inj3Cmd;
extern boolean Ext_bMonRunOc_Inj4Cmd;
extern boolean Ext_bMonRunOvld_Inj1Cmd;
extern boolean Ext_bMonRunOvld_Inj2Cmd;
extern boolean Ext_bMonRunOvld_Inj3Cmd;
extern boolean Ext_bMonRunOvld_Inj4Cmd;
extern boolean Ext_bMonRunScg_Inj1Cmd;
extern boolean Ext_bMonRunScg_Inj2Cmd;
extern boolean Ext_bMonRunScg_Inj3Cmd;
extern boolean Ext_bMonRunScg_Inj4Cmd;
extern boolean Ext_bMonRunScp_Inj1Cmd;
extern boolean Ext_bMonRunScp_Inj2Cmd;
extern boolean Ext_bMonRunScp_Inj3Cmd;
extern boolean Ext_bMonRunScp_Inj4Cmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DGOHALACQINJ_vidInjector1Diag(void);
void DGOHALACQINJ_vidInjector2Diag(void);
void DGOHALACQINJ_vidInjector3Diag(void);
void DGOHALACQINJ_vidInjector4Diag(void);
void DGOHALACQINJ_vidInjectorsDiag(void);


#endif /* DGOHALACQINJ_L_H */

/*-------------------------------- end of file -------------------------------*/
