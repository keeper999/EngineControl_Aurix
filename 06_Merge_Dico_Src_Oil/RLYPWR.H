/***************************************************************************
;**
;** FILE NAME      : RLYPWR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RLYPWR_H
#define RLYPWR_H

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

extern const boolean  RlyPwr_bModEcoBatt_Inh_C;
extern const uint8  RlyPwr_ctInhDiagOcCmdActr_C;
extern const uint16  Rly_InitTimer_C;
extern const uint16  Rly_tiMaintMainRly_C;
extern const uint16  RlyPwr_tiAftEndDiag_C;
extern const uint16  RlyPwr_tiEcuStPwrlLong_C;
extern const uint16  RlyPwr_tiWaitAcvModEcoBatt_C;
extern const uint16  RlyPwr_tiWaitOp_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Actionneurs;
extern boolean EcuSt_bInhDiagOcCmdActr;
extern boolean Ext_bUnBlsReq;
extern boolean PwrRly_rCtl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RlyPwr_EveKOf_Mng(void);
void RlyPwr_EveKOn_Mng(void);
void RlyPwr_EveRst_Mng(void);
void RlyPwr_EveStTR_Mng(void);
void RlyPwr_SdlFast_Mng(void);
void RlyPwr_SdlMid_Mng(void);
void RlyPwr_SdlSlow_Mng(void);


#endif /* RLYPWR_H */

/*-------------------------------- end of file -------------------------------*/
