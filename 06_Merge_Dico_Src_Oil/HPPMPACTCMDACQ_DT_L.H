/***************************************************************************
;**
;** FILE NAME      : HPPMPACTCMDACQ_DT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef HPPMPACTCMDACQ_DT_L_H
#define HPPMPACTCMDACQ_DT_L_H

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

extern const uint8  HPPMPACTCMDACQ_DT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 PFuCtl_tiPmpCmdAppl;
extern uint32 PFuCtl_tiPmpCmdDecelAppl;
extern uint8 PFuCtl_NrProfCmdAppl;
extern uint16 PFuCtl_agPmpCmdAppl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void HPPMPACTCMDACQ_DT_vidbStopHPPCmd(void);
void HPPMPACTCMDACQ_DT_vidHPPApplCmd(void);
void HPPMPACTCMDACQ_DT_vidHPPCmd_Ena(void);
void HPPMPACTCMDACQ_DT_vidHPPCmd_Init(void);
void HPPMPACTCMDACQ_DT_vidHPPCmdAppl(void);
void HPPMPACTCMDACQ_DT_vidHPPContnCmd(void);
void HPPMPACTCMDACQ_DT_vidHPPProfSeln(void);


#endif /* HPPMPACTCMDACQ_DT_L_H */

/*-------------------------------- end of file -------------------------------*/
