/***************************************************************************
;**
;** FILE NAME      : TRBWAPMP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TRBWAPMP_L_H
#define TRBWAPMP_L_H

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

extern const uint8  TRBWAPMP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TrbCoSysHw_bDgoOc_TrbWaPmp;
extern boolean TrbCoSysHw_bDgoScg_TrbWaPmp;
extern boolean TrbCoSysHw_bDgoScp_TrbWaPmp;
extern boolean TrbCoSysHw_bMonRunOc_TrbWaPmp;
extern boolean TrbCoSysHw_bMonRunScg_TrbWaPmp;
extern boolean TrbCoSysHw_bMonRunScp_TrbWaPmp;
extern boolean TRBWAPMP_bInitDiagnosisTimerPRev;
extern boolean TrbWaPmp_bTiInh_DiagEl;
extern uint8 TRBWAPMP_u8Timer;
extern sint16 TRBWAPMP_s16ExtuBattMesPrev;
extern uint16 Ext_uBattMes_Filtered;
extern uint16 TrbCoSysHw_RcoTact;
extern uint16 TrbCoSysHw_rCtlWaPmpReq;
extern uint16 TrbCoSysHw_rCtlWaPmpReq_Abs;
extern uint16 TrbCoSysHw_rCtlWaPmpReq_Cnv;
extern uint16 TrbCoSysHw_rCtlWaPmpReq_Cor;
extern uint16 TrbCoSysHw_rCtlWaPmpReq_Lim;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TRBWAPMP_vidCmdRCOCor(void);
void TRBWAPMP_vidConversionInPercent(void);
void TRBWAPMP_vidDiagnosis(void);
void TRBWAPMP_vidDrvCmd(void);
void TRBWAPMP_vidInit(void);
void TRBWAPMP_vidInitOutput(void);
void TRBWAPMP_vidTreatment(void);


#endif /* TRBWAPMP_L_H */

/*-------------------------------- end of file -------------------------------*/
