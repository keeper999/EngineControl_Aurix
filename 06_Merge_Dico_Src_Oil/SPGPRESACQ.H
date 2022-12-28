/***************************************************************************
;**
;** FILE NAME      : SPGPRESACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPGPRESACQ_H
#define SPGPRESACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRPRES_PSPGDFTV_NENG_T_COLS           ( 9 )
#define AIRPRES_PSPGPRESACQ_NENG_A_COLS        ( 9 )
#define AIRPRES_PSPGPRESSENVOLT_T_COLS         ( 2 )
#define AIRPRES_PUSTHRMES_NENG_A_COLS          ( 10 )
#define AIRPRES_RFILGAINSPGPRES_NENG_T_COLS    ( 10 )
#define AIRPRES_USPGPRESSENVOLT_A_COLS         ( 2 )

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

extern const uint8  AirPres_rFilGainSpgPres_nEng_T[AIRPRES_RFILGAINSPGPRES_NENG_T_COLS];
extern const uint16  AirPres_pSpgDftv_nEng_T[AIRPRES_PSPGDFTV_NENG_T_COLS];
extern const uint16  AirPres_pSpgPresAcq_nEng_A[AIRPRES_PSPGPRESACQ_NENG_A_COLS];
extern const uint16  AirPres_pSpgPresSenVolt_T[AIRPRES_PSPGPRESSENVOLT_T_COLS];
extern const uint16  AirPres_pUsThrMes_nEng_A[AIRPRES_PUSTHRMES_NENG_A_COLS];
extern const uint16  AirPres_uDgoScg_pSpgPres_C;
extern const uint16  AirPres_uDgoScp_pSpgPres_C;
extern const uint16  AirPres_uSpgPresSenVolt_A[AIRPRES_USPGPRESSENVOLT_A_COLS];
extern const uint16  Ext_pUsThrIni_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Acq_spg_pres_measured;
extern uint16 Acq_spg_prs_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirPres_Eve14TDC_SpgPresAcq(void);
void AirPres_EveRst_SpgPresAcq(void);
void AirPres_SdlMid_SpgPresAcq(void);


#endif /* SPGPRESACQ_H */

/*-------------------------------- end of file -------------------------------*/
