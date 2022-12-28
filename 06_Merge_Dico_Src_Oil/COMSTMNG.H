/***************************************************************************
;**
;** FILE NAME      : COMSTMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COMSTMNG_H
#define COMSTMNG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Com_RxPduGroup                    1
#define Com_TxElecItgrPduGroup            3
#define Com_TxNormalModePduGroup          4
#define Com_TxPwrlPduGroup                2

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st111 */
#define ISLIN_INIT                        0
#define ISLIN_WAKEUP                      1
#define ISLIN_NORMAL                      2
#define ISLIN_SHUTDOWN                    3
#define ISLIN_SHUTDOWNRQ                  4
#define ISLIN_WAKEUPDONE                  5
/*extern uint8 IsLin_stLin;*/


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
extern uint8 IsLin_stLin;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ComStMng_EveRst(void);
void ComStMng_EveSdlFast(void);


#endif /* COMSTMNG_H */

/*-------------------------------- end of file -------------------------------*/
