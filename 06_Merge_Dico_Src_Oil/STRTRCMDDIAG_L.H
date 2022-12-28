/***************************************************************************
;**
;** FILE NAME      : STRTRCMDDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef STRTRCMDDIAG_L_H
#define STRTRCMDDIAG_L_H

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

extern const uint8  STRTRCMDDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_Dml;
extern boolean Ext_bDgoScg_Dml;
extern boolean Ext_bDgoScp_Dml;
extern boolean Ext_bMonRunOc_Dml;
extern boolean Ext_bMonRunScg_Dml;
extern boolean Ext_bMonRunScp_Dml;
extern boolean Ext_bMonWaitOc_Dml;
extern boolean Ext_bMonWaitScg_Dml;
extern boolean Ext_bMonWaitScp_Dml;
extern boolean Strtr_bDgoBlock_Strtr;
extern boolean Strtr_bMonRunBlock_Strtr;
extern boolean Strtr_bMonWaitBlock_Strtr;
extern boolean STRTRCMDDIAG_bCondRstTempo;
extern boolean STRTRCMDDIAG_bDmlCmdCrankingPrev;
extern boolean STRTRCMDDIAG_boc_diag_ena;
extern boolean STRTRCMDDIAG_bscg_diag_ena;
extern boolean STRTRCMDDIAG_bscw_diag_ena;
extern uint16 Dml_diag_cmd_blocage_sta_count;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STRTRCMDDIAG_vidCmdStrtrRly(void);
void STRTRCMDDIAG_vidCondResetTempo(void);
void STRTRCMDDIAG_vidDiagBlockedStEna(void);
void STRTRCMDDIAG_vidDiagBlockedStrtr(void);
void STRTRCMDDIAG_vidDiagElec(void);
void STRTRCMDDIAG_vidDiagStrtrRly(void);
void STRTRCMDDIAG_vidIni(void);
void STRTRCMDDIAG_vidResetTempo(void);
void STRTRCMDDIAG_vidRunTempo(void);


#endif /* STRTRCMDDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
