/***************************************************************************
;**
;** FILE NAME      : TRBWAPMP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TRBWAPMP_H
#define TRBWAPMP_H

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

extern const boolean  Ext_bAcvCtlBattCor_TrbWaPmp_C;
extern const boolean  TrbCoSysHw_bInvDuCy_C;
extern const uint8  TrbWaPmp_TiInh_DiagEl_C;
extern const uint16  TrbCoSysHw_WaPmpReqFreq_C;
extern const uint16  TrbCoSysHw_WaPmpReqMax_C;
extern const uint16  TrbCoSysHw_WaPmpReqMin_C;
extern const uint16  TrbCoSysHw_WaPmpReqMinDiagEl_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TrbCoSysHw_rCtlWaPmpReq_Drv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CoT_EveRst_TrbWaPmp(void);
void CoT_SdlSlow_TrbWaPmp(void);


#endif /* TRBWAPMP_H */

/*-------------------------------- end of file -------------------------------*/
