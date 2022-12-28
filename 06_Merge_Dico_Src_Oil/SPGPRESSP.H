/***************************************************************************
;**
;** FILE NAME      : SPGPRESSP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPGPRESSP_H
#define SPGPRESSP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AIRPRES_PSPGSP_NENG_A_COLS             ( 16 )
#define AIRPRES_PSPGSP_TQIDCAIR_A_COLS         ( 16 )
#define AIRPRES_PSPGSP_TQIDCAIR_NENG_M_LNS    ( 16 )
#define AIRPRES_PSPGSP_TQIDCAIR_NENG_M_COLS    ( 16 )

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

extern const boolean  SpgPresSp_bBenchModEna_C;
extern const uint8  SpgPresSp_u8Inhib;
extern const uint16  AirPres_pSpgSp_nEng_A[AIRPRES_PSPGSP_NENG_A_COLS];
extern const uint16  AirPres_pSpgSp_tqIdcAir_A[AIRPRES_PSPGSP_TQIDCAIR_A_COLS];
extern const uint16  AirPres_pSpgSp_tqIdcAir_nEng_M[AIRPRES_PSPGSP_TQIDCAIR_NENG_M_LNS][AIRPRES_PSPGSP_TQIDCAIR_NENG_M_COLS];
extern const uint16  SpgPresSp_Max_pres_slew_C;
extern const uint16  SpgPresSp_Min_pres_slew_C;
extern const uint16  SpgPresSp_pBenchModIniSp_C;
extern const uint16  SpgPresSp_pDftValSp_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 AirPres_pSpgPresRawSp;
extern uint16 AirPres_pSpgPresSp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AirPres_EveRst_SpgPresSp(void);
void AirPres_SdlMid_SpgPresSp(void);


#endif /* SPGPRESSP_H */

/*-------------------------------- end of file -------------------------------*/
