/***************************************************************************
;**
;** FILE NAME      : CTLPMPREQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CTLPMPREQ_H
#define CTLPMPREQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define OILSYSHW_FRQBASEFRQPMPCMD_T_COLS       ( 5 )
#define OILSYSHW_TOIL_FRQPMPCMD_A_COLS         ( 5 )

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

extern const boolean  Ext_bAcv_OilPmp_rCtlBattCor_C;
extern const boolean  OilSysHw_bSelCmdFreq_C;
extern const uint8  Ext_uBattMes_Nom;
extern const uint8  OilSysHw_iMesOilPmpGain_C;
extern const uint16  OilSysHw_CtlPmpReq_CmdFreq_C;
extern const uint16  OilSysHw_CtlPmpReq_DrvMax_C;
extern const uint16  OilSysHw_CtlPmpReq_DrvMin_C;
extern const uint16  OilSysHw_frqBaseFrqPmpCmd_T[OILSYSHW_FRQBASEFRQPMPCMD_T_COLS];
extern const uint16  OilSysHw_frqOfsThdDZone1_C;
extern const uint16  OilSysHw_frqOfsThdDZone2_C;
extern const uint16  OilSysHw_frqRetDZone1_C;
extern const uint16  OilSysHw_frqRetDZone2_C;
extern const uint16  OilSysHw_frqThdDZone1_C;
extern const uint16  OilSysHw_frqThdDZone2_C;
extern const uint16  OilSysHw_nEngOfsThdZone1_C;
extern const uint16  OilSysHw_nEngThdZone1_C;
extern const uint16  OilSysHw_tOil_frqPmpCmd_A[OILSYSHW_TOIL_FRQPMPCMD_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Ext_iMesOilPmp;
extern uint16 OilSysHw_CtlPmpReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OilSysHw_EveRst_CtlPmpReq(void);
void OilSysHw_SdlFast_CtlPmpReq(void);


#endif /* CTLPMPREQ_H */

/*-------------------------------- end of file -------------------------------*/
