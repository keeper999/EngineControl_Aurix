/***************************************************************************
;**
;** FILE NAME      : THRTHERMOPROT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRTHERMOPROT_H
#define THRTHERMOPROT_H

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

extern const boolean  Thr_bAcvCdnCll_thermoProt_C;
extern const boolean  Thr_bAcvCdnLih_thermoProt_C;
extern const boolean  Thr_bAcvCdnLrn_thermoProt_C;
extern const boolean  Thr_bAcvCdnSp_thermoProt_C;
extern const boolean  Thr_bTypDiagThermoProt_C;
extern const uint8  Thr_tiDlyCfmOvldThermoThr_C;
extern const uint16  Thr_acvSpThd_ThermoProt_C;
extern const uint16  Thr_dlyAcvCll_thermoProt_C;
extern const uint16  Thr_facFilUCmd_C;
extern const uint16  Thr_facGrd_C;
extern const uint16  Thr_facPwr_C;
extern const uint16  Thr_tEngThd_C;
extern const sint32  Thr_uCmdThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint32 Thr_tEngEstim;
extern sint16 Thr_uCmdFil;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveClcnServo_ThermoProt(void);
void Thr_EveRst_ThermoProt(void);
void Thr_SdlMid_ThermoProt(void);


#endif /* THRTHERMOPROT_H */

/*-------------------------------- end of file -------------------------------*/
