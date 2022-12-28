/***************************************************************************
;**
;** FILE NAME      : ECTREQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ECTREQ_L_H
#define ECTREQ_L_H

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

extern const uint8  ECTREQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoFan_bDgoOc_ECTReq;
extern boolean CoFan_bDgoScg_ECTReq;
extern boolean CoFan_bDgoScp_ECTReq;
extern boolean CoFan_bMonRunOc_ECTReq;
extern boolean CoFan_bMonRunScg_ECTReq;
extern boolean CoFan_bMonRunScp_ECTReq;
extern boolean Dena_oc_ectcommand;
extern boolean Dena_scg_ectcommand;
extern boolean Dena_scw_ectcommand;
extern boolean Dft_oc_ectcommand;
extern boolean Dft_scg_ectcommand;
extern boolean Dft_scw_ectcommand;
extern sint16 ECTREQ_s16Ext_uBattMesPrev;
extern uint16 CoFan_uBattMes_Filtered;
extern uint16 PwrHw_rCtlECTReq_Cnv;
extern uint16 PwrHw_rCtlECTReq_Cor;
extern uint16 PwrHw_rCtlECTReq_Sat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ECTREQ_vidCmdRCO_Cor(void);
void ECTREQ_vidDiagnosis(void);
void ECTREQ_vidDrvCmd(void);
void ECTREQ_vidFiltBatt(void);
void ECTREQ_vidInitialization(void);
void ECTREQ_vidInitOutput(void);
void ECTREQ_vidTreatment(void);


#endif /* ECTREQ_L_H */

/*-------------------------------- end of file -------------------------------*/
