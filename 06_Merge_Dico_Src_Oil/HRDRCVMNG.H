/***************************************************************************
;**
;** FILE NAME      : HRDRCVMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HRDRCVMNG_H
#define HRDRCVMNG_H

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

extern const uint16  Fgid_ti_VsctlDiagIni_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean FRM_bEnaDeacVSCtlEng;
extern boolean FRM_bEnaDeacVSCtlTra;
extern boolean FRM_bEnaDeacVSCtlVeh;
extern boolean FRM_bEnaDeacVSCtlVSLim;
extern boolean FRM_bEnaDeacVSCtlVSMax;
extern boolean FRM_bEnaDeacVSCtlVSReg;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_HrdRcvMng(void);
void GD_SdlMid_HrdRcvMng(void);


#endif /* HRDRCVMNG_H */

/*-------------------------------- end of file -------------------------------*/
