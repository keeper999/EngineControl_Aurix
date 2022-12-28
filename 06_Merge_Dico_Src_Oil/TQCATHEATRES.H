/***************************************************************************
;**
;** FILE NAME      : TQCATHEATRES.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCATHEATRES_H
#define TQCATHEATRES_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQRES_NENGEOMRESMOD1_A_COLS            ( 8 )
#define TQRES_NENGEOMRESMOD2_A_COLS            ( 8 )
#define TQRES_NENGEOMRESMOD3_A_COLS            ( 8 )
#define TQRES_NENGEOMRESMOD4_A_COLS            ( 16 )
#define TQRES_NENGEOMRESMOD5_A_COLS            ( 16 )
#define TQRES_NENGEOMRESMOD6_A_COLS            ( 16 )
#define TQRES_NENGEOMRESMOD7_A_COLS            ( 16 )
#define TQRES_TQEOMRESMOD1_M_LNS              ( 8 )
#define TQRES_TQEOMRESMOD1_M_COLS              ( 8 )
#define TQRES_TQEOMRESMOD2_M_LNS              ( 8 )
#define TQRES_TQEOMRESMOD2_M_COLS              ( 8 )
#define TQRES_TQEOMRESMOD3_M_LNS              ( 8 )
#define TQRES_TQEOMRESMOD3_M_COLS              ( 8 )
#define TQRES_TQEOMRESMOD4_M_LNS              ( 16 )
#define TQRES_TQEOMRESMOD4_M_COLS              ( 16 )
#define TQRES_TQEOMRESMOD5_M_LNS              ( 16 )
#define TQRES_TQEOMRESMOD5_M_COLS              ( 16 )
#define TQRES_TQEOMRESMOD6_M_LNS              ( 16 )
#define TQRES_TQEOMRESMOD6_M_COLS              ( 16 )
#define TQRES_TQEOMRESMOD7_M_LNS              ( 16 )
#define TQRES_TQEOMRESMOD7_M_COLS              ( 16 )
#define TQRES_TQIDCAIREOMRESMOD1_A_COLS        ( 8 )
#define TQRES_TQIDCAIREOMRESMOD2_A_COLS        ( 8 )
#define TQRES_TQIDCAIREOMRESMOD3_A_COLS        ( 8 )
#define TQRES_TQIDCAIREOMRESMOD4_A_COLS        ( 16 )
#define TQRES_TQIDCAIREOMRESMOD5_A_COLS        ( 16 )
#define TQRES_TQIDCAIREOMRESMOD6_A_COLS        ( 16 )
#define TQRES_TQIDCAIREOMRESMOD7_A_COLS        ( 16 )

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

extern const uint16  TqRes_nEngEOMResMod1_A[TQRES_NENGEOMRESMOD1_A_COLS];
extern const uint16  TqRes_nEngEOMResMod2_A[TQRES_NENGEOMRESMOD2_A_COLS];
extern const uint16  TqRes_nEngEOMResMod3_A[TQRES_NENGEOMRESMOD3_A_COLS];
extern const uint16  TqRes_nEngEOMResMod4_A[TQRES_NENGEOMRESMOD4_A_COLS];
extern const uint16  TqRes_nEngEOMResMod5_A[TQRES_NENGEOMRESMOD5_A_COLS];
extern const uint16  TqRes_nEngEOMResMod6_A[TQRES_NENGEOMRESMOD6_A_COLS];
extern const uint16  TqRes_nEngEOMResMod7_A[TQRES_NENGEOMRESMOD7_A_COLS];
extern const uint16  TqRes_tqEOMResMod1_M[TQRES_TQEOMRESMOD1_M_LNS][TQRES_TQEOMRESMOD1_M_COLS];
extern const uint16  TqRes_tqEOMResMod2_M[TQRES_TQEOMRESMOD2_M_LNS][TQRES_TQEOMRESMOD2_M_COLS];
extern const uint16  TqRes_tqEOMResMod3_M[TQRES_TQEOMRESMOD3_M_LNS][TQRES_TQEOMRESMOD3_M_COLS];
extern const uint16  TqRes_tqEOMResMod4_M[TQRES_TQEOMRESMOD4_M_LNS][TQRES_TQEOMRESMOD4_M_COLS];
extern const uint16  TqRes_tqEOMResMod5_M[TQRES_TQEOMRESMOD5_M_LNS][TQRES_TQEOMRESMOD5_M_COLS];
extern const uint16  TqRes_tqEOMResMod6_M[TQRES_TQEOMRESMOD6_M_LNS][TQRES_TQEOMRESMOD6_M_COLS];
extern const uint16  TqRes_tqEOMResMod7_M[TQRES_TQEOMRESMOD7_M_LNS][TQRES_TQEOMRESMOD7_M_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod1_A[TQRES_TQIDCAIREOMRESMOD1_A_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod2_A[TQRES_TQIDCAIREOMRESMOD2_A_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod3_A[TQRES_TQIDCAIREOMRESMOD3_A_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod4_A[TQRES_TQIDCAIREOMRESMOD4_A_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod5_A[TQRES_TQIDCAIREOMRESMOD5_A_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod6_A[TQRES_TQIDCAIREOMRESMOD6_A_COLS];
extern const uint16  TqRes_tqIdcAirEOMResMod7_A[TQRES_TQIDCAIREOMRESMOD7_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 TqRes_tqEOMRes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCATHEATRES_vidEntryInit(void);
void TqRes_Sdl10ms_tqEOMRes(void);


#endif /* TQCATHEATRES_H */

/*-------------------------------- end of file -------------------------------*/
