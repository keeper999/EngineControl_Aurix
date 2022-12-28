/***************************************************************************
;**
;** FILE NAME      : PFUACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PFUACQ_H
#define PFUACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define EXT_PFUMES_T_COLS                      ( 2 )
#define EXT_PFUMESSPL_T_COLS                   ( 2 )
#define PFUACQ_NENG_A_COLS                     ( 16 )
#define PFUACQ_RFILGAINPFURAILMES_T_COLS       ( 16 )
#define PFUACQ_RFILGAINPFURAILSPLMES_T_COLS    ( 16 )
#define PFUACQ_UPFUMES_A_COLS                  ( 2 )

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

extern const uint16  Ext_pFuMes_T[EXT_PFUMES_T_COLS];
extern const uint16  Ext_pFuMesSpl_T[EXT_PFUMESSPL_T_COLS];
extern const uint16  Ext_pFuMesWRV_C;
extern const uint16  Ext_pFuRcv_C;
extern const uint16  Ext_uDgoCoh_pFuMes_C;
extern const uint16  Ext_uDgoScg_pFuMes_C;
extern const uint16  Ext_uDgoScp_pFuMes_C;
extern const uint16  PFuAcq_nEng_A[PFUACQ_NENG_A_COLS];
extern const uint16  PFuAcq_rFilGainPFuRailMes_T[PFUACQ_RFILGAINPFURAILMES_T_COLS];
extern const uint16  PFuAcq_rFilGainPFuRailSplMes_T[PFUACQ_RFILGAINPFURAILSPLMES_T_COLS];
extern const uint16  PFuAcq_uPFuMes_A[PFUACQ_UPFUMES_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Ext_pFuMesWRV;
extern uint16 Ext_pFuRailMes;
extern uint16 Ext_pFuRailMesRef;
extern uint16 Ext_pFuRailSplMes;
extern uint16 PFuAcq_pFuRailMes;
extern uint16 PFuAcq_pFuRailMesRaw;
extern uint16 PFuAcq_pFuRailSplMes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FuAcq_EveInj_PFuAcq(void);
void FuAcq_EveRst_PFuAcq(void);
void FuAcq_EveSpl_PFuAcq(void);
void FuAcq_SdlFast_PFuAcq(void);


#endif /* PFUACQ_H */

/*-------------------------------- end of file -------------------------------*/
