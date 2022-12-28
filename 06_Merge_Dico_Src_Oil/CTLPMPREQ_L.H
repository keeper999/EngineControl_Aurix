/***************************************************************************
;**
;** FILE NAME      : CTLPMPREQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CTLPMPREQ_L_H
#define CTLPMPREQ_L_H

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

extern const uint8  CTLPMPREQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CTLPMPREQ_bHysteresis1Output;
extern boolean CTLPMPREQ_bHysteresis2Output;
extern boolean CTLPMPREQ_bHysteresis3Output;
extern boolean OilSysHw_bDgoOc_CtlPmpReq;
extern boolean OilSysHw_bDgoScg_CtlPmpReq;
extern boolean OilSysHw_bDgoScp_CtlPmpReq;
extern boolean OilSysHw_bMonRunOc_CtlPmpReq;
extern boolean OilSysHw_bMonRunScg_CtlPmpReq;
extern boolean OilSysHw_bMonRunScp_CtlPmpReq;
extern uint32 CTLPMPREQ_u32ExtIMesOilPmpMEM;
extern uint8 Ext_uBattMes_Fil;
extern uint8 OilSysHw_noFacFrqCmdOilPmp;
extern sint16 CTLPMPREQ_s16ExtUBattMesPrev;
extern uint16 Ext_iMesOilPmp_Prev;
extern uint16 OilSys_CtlPmpReq_Abs;
extern uint16 OilSysHw_CtlPmpReq_Cor;
extern uint16 OilSysHw_CtlPmpReq_Drv;
extern uint16 OilSysHw_CtlPmpReq_Lim;
extern uint16 OilSysHw_frqBaseFrqPmpCmd;
extern uint16 OilSysHw_frqCmdFreqZone;
extern uint16 OilSysHw_frqInjFreq;
extern uint16 OilSysHw_frqPmpCmdRaw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CTLPMPREQ_vidCmd(void);
void CTLPMPREQ_vidCmdAbs(void);
void CTLPMPREQ_vidCmdAndDiagEnable(void);
void CTLPMPREQ_vidCmdApp(void);
void CTLPMPREQ_vidCmdCor(void);
void CTLPMPREQ_vidDiag(void);
void CTLPMPREQ_vidDrvCur(void);
void CTLPMPREQ_vidInit(void);
void CTLPMPREQ_vidInitOutput(void);


#endif /* CTLPMPREQ_L_H */

/*-------------------------------- end of file -------------------------------*/
