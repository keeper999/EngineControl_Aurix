/***************************************************************************
;**
;** FILE NAME      : POSTEQUSRV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef POSTEQUSRV_H
#define POSTEQUSRV_H

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

/* enum st132 */
#define SRV_POSTEQUECU_IDLE               0
#define SRV_POSTEQUECU_NEEDACCESS         1
#define SRV_POSTEQUECU_SEED               2
#define SRV_POSTEQUECU_WAIT               4
#define SRV_POSTEQUECU_WRITE              8
#define SRV_POSTEQUECU_ANTISCANNING       16
#define SRV_POSTEQUECU_DATANOK            32
/*extern uint8 Srv_stPostEquEcuStatus;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Srv_bInhSAFstWrPosEq_C;
extern const uint8  Srv_PostEquIndice_C;
extern const uint8  Srv_prmPostEquMax_C;
extern const uint8  Srv_prmPostEquMin_C;
extern const uint16  Srv_tiDelayPostEqu_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Srv_stPostEquEcuStatus;
extern uint8 Ext_spdVehVSMaxPrmaReq2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Srv_EveErrPostEquWr_PostEquSrv(void);
void Srv_EvePostEqu_PostEquSrv(void);
void Srv_EveRst_PostEqu(void);
void Srv_EveSa_PostEquSrv(void);
void Srv_SdlFast_PostEquSrv(void);


#endif /* POSTEQUSRV_H */

/*-------------------------------- end of file -------------------------------*/
