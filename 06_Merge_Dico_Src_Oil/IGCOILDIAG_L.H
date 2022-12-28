/***************************************************************************
;**
;** FILE NAME      : IGCOILDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCOILDIAG_L_H
#define IGCOILDIAG_L_H

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

extern const uint8  IGCOILDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoOc_IgCoil1Cmd;
extern boolean Ext_bDgoOc_IgCoil2Cmd;
extern boolean Ext_bDgoOc_IgCoil3Cmd;
extern boolean Ext_bDgoOc_IgCoil4Cmd;
extern boolean Ext_bDgoScp_IgCoil1Cmd;
extern boolean Ext_bDgoScp_IgCoil2Cmd;
extern boolean Ext_bDgoScp_IgCoil3Cmd;
extern boolean Ext_bDgoScp_IgCoil4Cmd;
extern boolean Ext_bMonRunOc_IgCoil1Cmd;
extern boolean Ext_bMonRunOc_IgCoil2Cmd;
extern boolean Ext_bMonRunOc_IgCoil3Cmd;
extern boolean Ext_bMonRunOc_IgCoil4Cmd;
extern boolean Ext_bMonRunScp_IgCoil1Cmd;
extern boolean Ext_bMonRunScp_IgCoil2Cmd;
extern boolean Ext_bMonRunScp_IgCoil3Cmd;
extern boolean Ext_bMonRunScp_IgCoil4Cmd;
extern boolean Icd_diagnostic_enabled;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGCOILDIAG_vidCalcIcdDiagEnabled(void);
void IGCOILDIAG_vidCallDiagICD(void);
void IGCOILDIAG_vidCallDiagSdlFast(void);
void IGCOILDIAG_vidDiagBob1(void);
void IGCOILDIAG_vidDiagBob2(void);
void IGCOILDIAG_vidDiagBob3(void);
void IGCOILDIAG_vidDiagBob4(void);
void IGCOILDIAG_vidDiagnostic(void);


#endif /* IGCOILDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
