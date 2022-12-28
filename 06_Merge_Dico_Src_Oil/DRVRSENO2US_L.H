/***************************************************************************
;**
;** FILE NAME      : DRVRSENO2US_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DRVRSENO2US_L_H
#define DRVRSENO2US_L_H

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

extern const uint8  DRVRSENO2US_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DRVRSENO2US_bDiagEnable;
extern boolean Ext_bDgoHi_DrvrSenO2Us;
extern boolean Ext_bDgoLo_DrvrSenO2Us;
extern boolean Ext_bMonRunHi_DrvrSenO2Us;
extern boolean Ext_bMonRunLo_DrvrSenO2Us;
extern uint8 DRVRSENO2US_u8SdlDiagCall;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DRVRSENO2US_vidDiag(void);
void DRVRSENO2US_vidDiagEna(void);
void DRVRSENO2US_vidDiagTest(void);
void DRVRSENO2US_vidEntryInit(void);
void DRVRSENO2US_vidHeatSenO2DsCmd(void);
void DRVRSENO2US_vidInitOutput(void);
void DRVRSENO2US_vidSdlDiag(void);
void DRVRSENO2US_vidUAcqn(void);


#endif /* DRVRSENO2US_L_H */

/*-------------------------------- end of file -------------------------------*/
