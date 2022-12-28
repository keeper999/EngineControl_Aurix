/***************************************************************************
;**
;** FILE NAME      : TQSYSVLD.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "TQSYSVLD.H"
#include "TQSYSVLD_L.H"
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
const boolean  manu_inh_bInvld_tqCkEngReal = 0;
const boolean  manu_inh_bInvld_tqEM = 0;
const boolean  manu_inh_bUncrt_tqCkEngReal = 0;
const boolean  manu_inh_bUncrt_tqEM = 0;
const uint8  TqDiag_thdMisfHi_C = 0;
const uint8  TqDiag_thdMisfHiEM_C = 0;
const uint8  TqDiag_thdMisfLo_C = 0;
const uint8  TqDiag_thdMisfLoEM_C = 0;
const uint8  TqDiag_wghtdftComAlt_C = 0;
const uint8  TqDiag_wghtInvldTqCkEngReal_C = 0;
const uint8  TqDiag_wghtInvldTqEM_C = 0;
const uint8  TqDiag_wghtInvldTqESPReq_C = 0;
const uint8  TqDiag_wghtIsCanF30DP265Invld_C = 0;
const uint8  TqDiag_wghtIsCanF30DP266Invld_C = 0;
const uint8  TqDiag_wghtIsCanF38DP010Invld_C = 0;
const uint8  TqDiag_wghtIsCanF50EP210Invld_C = 0;
const uint8  TqDiag_wghtIsCanP388InvldTx_C = 0;
const uint8  TqDiag_wghtLfbkAfl_C = 0;
const uint8  TqDiag_wghtLfbkAfr_C = 0;
const uint8  TqDiag_wghtLoFuLvl_C = 0;
const uint8  TqDiag_wghtLrnThr_C = 0;
const uint8  TqDiag_wghtLrnVlvAct_C = 0;
const uint8  TqDiag_wghtMisfHi_C = 0;
const uint8  TqDiag_wghtMisfHiEM_C = 0;
const uint8  TqDiag_wghtMisfLo_C = 0;
const uint8  TqDiag_wghtMisfLoEM_C = 0;
const uint8  TqDiag_wghtPosnSnsr_C = 0;
const uint8  TqDiag_wghtRatCylNoProd_C = 0;
const uint8  TqDiag_wghtSenKnk_C = 0;
const uint8  TqDiag_wghtSenpAir_C = 0;
const uint8  TqDiag_wghtSenpCircDA_C = 0;
const uint8  TqDiag_wghtSenSync_C = 0;
const uint8  TqDiag_wghtSentAir_C = 0;
const uint8  TqDiag_wghtSentCo_C = 0;
const uint8  TqDiag_wghtSenUpLs_C = 0;
const uint8  TqDiag_wghtSenVlvAct_C = 0;
const uint8  TqDiag_wghtThrCmd_C = 0;
const uint8  TqDiag_wghtUncrtTqCkEngReal_C = 0;
const uint8  TqDiag_wghtUncrtTqEM_C = 0;
const uint8  TqDiag_wghtUncrtTqESPReq_C = 0;
const uint8  TqDiag_wghtVlvActServo_C = 0;
const uint8  TQSYSVLD_u8Inhib = 0;
const uint16  TqDiag_thdInvldTqCkEngReal_C = 0;
const uint16  TqDiag_thdInvldTqEM_C = 0;
const uint16  TqDiag_thdUncrtTqCkEngReal_C = 0;
const uint16  TqDiag_thdUncrtTqEM_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Diag_misfire_bas;
boolean Diag_misfire_bas_EM;
boolean Diag_misfire_haut;
boolean Diag_misfire_haut_EM;
boolean TqDiag_bInvld_tqCkEngReal;
boolean TqDiag_bInvld_tqEM;
boolean TqDiag_bUncrt_tqEM;
uint8 Nb_Cyl_NoProd;
uint8 Rat_Cyl_NoProd;
uint8 TqDiag_stDiagESPReq;
uint16 TqDiag_noWght;
uint16 TqDiag_noWght1;
uint16 TqDiag_noWght2;
uint16 TqDiag_noWght3;
uint16 TqDiag_noWght4;
uint16 TqDiag_noWght5;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

