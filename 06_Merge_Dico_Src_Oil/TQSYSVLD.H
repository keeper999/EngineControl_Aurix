/***************************************************************************
;**
;** FILE NAME      : TQSYSVLD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQSYSVLD_H
#define TQSYSVLD_H

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

extern const boolean  manu_inh_bInvld_tqCkEngReal;
extern const boolean  manu_inh_bInvld_tqEM;
extern const boolean  manu_inh_bUncrt_tqCkEngReal;
extern const boolean  manu_inh_bUncrt_tqEM;
extern const uint8  TqDiag_thdMisfHi_C;
extern const uint8  TqDiag_thdMisfHiEM_C;
extern const uint8  TqDiag_thdMisfLo_C;
extern const uint8  TqDiag_thdMisfLoEM_C;
extern const uint8  TqDiag_wghtdftComAlt_C;
extern const uint8  TqDiag_wghtInvldTqCkEngReal_C;
extern const uint8  TqDiag_wghtInvldTqEM_C;
extern const uint8  TqDiag_wghtInvldTqESPReq_C;
extern const uint8  TqDiag_wghtIsCanF30DP265Invld_C;
extern const uint8  TqDiag_wghtIsCanF30DP266Invld_C;
extern const uint8  TqDiag_wghtIsCanF38DP010Invld_C;
extern const uint8  TqDiag_wghtIsCanF50EP210Invld_C;
extern const uint8  TqDiag_wghtIsCanP388InvldTx_C;
extern const uint8  TqDiag_wghtLfbkAfl_C;
extern const uint8  TqDiag_wghtLfbkAfr_C;
extern const uint8  TqDiag_wghtLoFuLvl_C;
extern const uint8  TqDiag_wghtLrnThr_C;
extern const uint8  TqDiag_wghtLrnVlvAct_C;
extern const uint8  TqDiag_wghtMisfHi_C;
extern const uint8  TqDiag_wghtMisfHiEM_C;
extern const uint8  TqDiag_wghtMisfLo_C;
extern const uint8  TqDiag_wghtMisfLoEM_C;
extern const uint8  TqDiag_wghtPosnSnsr_C;
extern const uint8  TqDiag_wghtRatCylNoProd_C;
extern const uint8  TqDiag_wghtSenKnk_C;
extern const uint8  TqDiag_wghtSenpAir_C;
extern const uint8  TqDiag_wghtSenpCircDA_C;
extern const uint8  TqDiag_wghtSenSync_C;
extern const uint8  TqDiag_wghtSentAir_C;
extern const uint8  TqDiag_wghtSentCo_C;
extern const uint8  TqDiag_wghtSenUpLs_C;
extern const uint8  TqDiag_wghtSenVlvAct_C;
extern const uint8  TqDiag_wghtThrCmd_C;
extern const uint8  TqDiag_wghtUncrtTqCkEngReal_C;
extern const uint8  TqDiag_wghtUncrtTqEM_C;
extern const uint8  TqDiag_wghtUncrtTqESPReq_C;
extern const uint8  TqDiag_wghtVlvActServo_C;
extern const uint16  TqDiag_thdInvldTqCkEngReal_C;
extern const uint16  TqDiag_thdInvldTqEM_C;
extern const uint16  TqDiag_thdUncrtTqCkEngReal_C;
extern const uint16  TqDiag_thdUncrtTqEM_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqDiag_bInvld_tqCkEngReal;
extern boolean TqDiag_bInvld_tqEM;
extern boolean TqDiag_bUncrt_tqEM;
extern uint8 TqDiag_stDiagESPReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TqSys_EveBDC_TqSysVld(void);
void TqSys_EveRst_TqSysVld(void);
void TqSys_SdlFast_TqSysVld(void);


#endif /* TQSYSVLD_H */

/*-------------------------------- end of file -------------------------------*/
