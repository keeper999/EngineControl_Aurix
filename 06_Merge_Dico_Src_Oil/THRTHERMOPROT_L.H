/***************************************************************************
;**
;** FILE NAME      : THRTHERMOPROT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRTHERMOPROT_L_H
#define THRTHERMOPROT_L_H

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

extern const uint8  THRTHERMOPROT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bCdnCll_thermoProt;
extern boolean Thr_bCdnLih_thermoProt;
extern boolean Thr_bCdnSpThd_thermoProt;
extern boolean Thr_bCdnStopLrn_thermoProt;
extern boolean Thr_bDgoOvldThermoThr;
extern boolean Thr_bMonRunOvldThermoThr;
extern boolean THRTHERMOPROT_bDlyCfmOvldThrPrev;
extern boolean THRTHERMOPROT_bThermoThrTimeOut;
extern boolean THRTHERMOPROT_bTpacOpenLpCtrPrev;
extern uint8 THRTHERMOPROT_u8ThrDlCfmOvldThr;
extern sint16 Thr_tEngGrd;
extern uint16 THRTHERMOPROT_u16ThrthermoProt;
extern sint32 THRTHERMOPROT_s32ThruCmdFilMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void THRTHERMOPROT_vidDiag(void);
void THRTHERMOPROT_vidDiagCdn(void);
void THRTHERMOPROT_vidEngTEstim(void);
void THRTHERMOPROT_vidFilThrVolt(void);
void THRTHERMOPROT_vidInit(void);
void THRTHERMOPROT_vidInitOutput(void);


#endif /* THRTHERMOPROT_L_H */

/*-------------------------------- end of file -------------------------------*/
