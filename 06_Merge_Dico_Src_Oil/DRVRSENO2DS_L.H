/***************************************************************************
;**
;** FILE NAME      : DRVRSENO2DS_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef DRVRSENO2DS_L_H
#define DRVRSENO2DS_L_H

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

extern const uint8  DRVRSENO2DS_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean DRVRSENO2DS_bDiagEnable;
extern boolean Ext_bDgoHi_DrvrSenO2Ds;
extern boolean Ext_bDgoLo_DrvrSenO2Ds;
extern boolean Ext_bMonRunHi_DrvrSenO2Ds;
extern boolean Ext_bMonRunLo_DrvrSenO2Ds;
extern uint8 DRVRSENO2DS_u8SdlDiagCall;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void DRVRSENO2DS_vidDiag(void);
void DRVRSENO2DS_vidDiagEna(void);
void DRVRSENO2DS_vidDiagTest(void);
void DRVRSENO2DS_vidHeatSenO2DsCmd(void);
void DRVRSENO2DS_vidInitOutput(void);
void DRVRSENO2DS_vidSdlDiag(void);
void DRVRSENO2DS_vidUAcqn(void);


#endif /* DRVRSENO2DS_L_H */

/*-------------------------------- end of file -------------------------------*/
