/***************************************************************************
;**
;** FILE NAME      : PROPFUPMP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PROPFUPMP_L_H
#define PROPFUPMP_L_H

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

extern const uint8  PROPFUPMP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ctrl_bInhCmd_FuTnkPmp;
extern boolean FuPmp_bDgoFrq_PropFuPmp;
extern boolean FuPmp_bDgoGravScp_PropFuPmp;
extern boolean FuPmp_bDgoMap_PropFuPmp;
extern boolean FuPmp_bDgoOc_PropFuPmp;
extern boolean FuPmp_bDgoScg_PropFuPmp;
extern boolean FuPmp_bDgoScp_PropFuPmp;
extern boolean FuPmp_bMonRunFrq_PropFuPmp;
extern boolean FuPmp_bMonRunGravScp_PropFuPmp;
extern boolean FuPmp_bMonRunMap_PropFuPmp;
extern boolean FuPmp_bMonRunOc_PropFuPmp;
extern boolean FuPmp_bMonRunScg_PropFuPmp;
extern boolean FuPmp_bMonRunScp_PropFuPmp;
extern boolean PROPFUPMP_bPwrRly_rCtl_Prev;
extern boolean PROPFUPMP_bTimeout;
extern uint32 Ext_tiPerStFlowFuTnkPmp;
extern uint8 Ext_frqStFlowFuTnkPmp;
extern uint8 Ext_stDftFuTnkPmpMem;
extern uint8 Ext_stFlowFuTnkPmp_Conv;
extern uint8 PROPFUPMP_u8TimerCpt;
extern uint16 Ext_rStFlowFuTnkPmp;
extern uint16 FuPmp_rFlowFuTnkPmp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PROPFUPMP_vidCmdPropFuPmp(void);
void PROPFUPMP_vidCmdPropFuPmpNull(void);
void PROPFUPMP_vidDiag_rSt(void);
void PROPFUPMP_vidDiagPropFuPmp(void);
void PROPFUPMP_vidInit(void);
void PROPFUPMP_vidInitOutput(void);
void PROPFUPMP_vidPropFuPmp_DiagHw(void);
void PROPFUPMP_vidPropFuPmp_Sel(void);
void PROPFUPMP_vidPropFuPmpDiag_Acq(void);
void PROPFUPMP_vidPropfuPmpDiag_Conv(void);
void PROPFUPMP_vidPropFuPmpDiag_Diag(void);


#endif /* PROPFUPMP_L_H */

/*-------------------------------- end of file -------------------------------*/
