/***************************************************************************
;**
;** FILE NAME      : INMNFPRESACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INMNFPRESACQ_H
#define INMNFPRESACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRPRES_PDSTHRDFTV_NENG_T_COLS         ( 9 )
#define AIRPRES_PDSTHRMES_NENG_A_COLS          ( 10 )
#define AIRPRES_PDSTHRPRESACQ_NENG_A_COLS      ( 9 )
#define AIRPRES_PDSTHRPRESSENVOLT_T_COLS       ( 2 )
#define AIRPRES_RFILGAINDSTHRPRES_NENG_T_COLS  ( 10 )
#define AIRPRES_UDSTHRPRESSENVOLT_A_COLS       ( 2 )

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

extern const uint8  AirPres_rFilGainDsThrPres_nEng_T[AIRPRES_RFILGAINDSTHRPRES_NENG_T_COLS];
extern const uint16  Acq_pDsThrPresDftv_NoSync_C;
extern const uint16  AirPres_pDsThrDftv_nEng_T[AIRPRES_PDSTHRDFTV_NENG_T_COLS];
extern const uint16  AirPres_pDsThrMes_nEng_A[AIRPRES_PDSTHRMES_NENG_A_COLS];
extern const uint16  AirPres_pDsThrPresAcq_nEng_A[AIRPRES_PDSTHRPRESACQ_NENG_A_COLS];
extern const uint16  AirPres_pDsThrPresSenVolt_T[AIRPRES_PDSTHRPRESSENVOLT_T_COLS];
extern const uint16  AirPres_uDgoScg_pDsThrMes_C;
extern const uint16  AirPres_uDgoScp_pDsThrMes_C;
extern const uint16  AirPres_uDsThrPresSenVolt_A[AIRPRES_UDSTHRPRESSENVOLT_A_COLS];
extern const uint16  Ext_pDsThrIni_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Ext_pDsThrMesWRV;
extern uint16 Io_map_manifold_press_measured;
extern uint16 Pression_air_result_ad_conv;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirPres_Eve14TDC_InMnfPresAcq(void);
void AirPres_EveRst_InMnfPresAcq(void);
void AirPres_SdlMid_InMnfPresAcq(void);
void INMNFPRESACQ_vidAcqPressManifld(void);


#endif /* INMNFPRESACQ_H */

/*-------------------------------- end of file -------------------------------*/
