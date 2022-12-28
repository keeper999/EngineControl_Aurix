/***************************************************************************
;**
;** FILE NAME      : PWRLRLY.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PWRLRLY_H
#define PWRLRLY_H

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


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Rly_bMainRlyCmd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PwrlRly_EveKOf_IfCmdDiag(void);
void PwrlRly_EveKOn_IfCmdDiag(void);
void PwrlRly_EveRst_IfCmdDiag(void);
void PwrlRly_EveRxnIdDaRcdDml(void);
void PwrlRly_SdlMid_IfCmdDiag(void);
void PWRLRLY_vidCmd(void);
void PWRLRLY_vidDiag(void);
void PWRLRLY_vidGduCall(void);
void PWRLRLY_vidInitialization(void);


#endif /* PWRLRLY_H */

/*-------------------------------- end of file -------------------------------*/
