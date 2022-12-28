/***************************************************************************
;**
;** FILE NAME      : RLYACTEST.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RLYACTEST_H
#define RLYACTEST_H

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

extern const uint8  ActrTstRly_Tempo_C;
extern const uint8  TpsOff_ActrTstPwrRly;
extern const uint8  TpsOn_ActrTstPwrRly;
extern const uint16  TpsTot_ActrTstPwrRly;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Rly_bActrTstCmd;
extern boolean Rly_bActrTstCmpl;
extern boolean Rly_bTstInProgress;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Rly_EveRst_ActTstPwrRly(void);
void Rly_SdlFast_ActTstPwrRly(void);


#endif /* RLYACTEST_H */

/*-------------------------------- end of file -------------------------------*/
