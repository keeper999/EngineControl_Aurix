/***************************************************************************
;**
;** FILE NAME      : TQSYSSPBENCHMOD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQSYSSPBENCHMOD_H
#define TQSYSSPBENCHMOD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQSYS_NENGX_A_COLS                     ( 16 )
#define TQSYS_POSNACCPY_A_COLS                 ( 16 )
#define TQSYS_TQAIRSP_NENGX_POSNACCPY_M_LNS   ( 16 )
#define TQSYS_TQAIRSP_NENGX_POSNACCPY_M_COLS   ( 16 )
#define TQSYS_TQIGNSP_NENGX_POSNACCPY_M_LNS   ( 16 )
#define TQSYS_TQIGNSP_NENGX_POSNACCPY_M_COLS   ( 16 )

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

extern const boolean  TqSys_bSelTqSpManModTyp_C;
extern const boolean  TqSys_bTqSpBenchModEna_C;
extern const uint8  TqSys_posnAccPY_A[TQSYS_POSNACCPY_A_COLS];
extern const uint8  TQSYSSPBENCHMOD_u8Inhib;
extern const sint16  TqSys_tqIdcAirBenchModIniSp_C;
extern const sint16  TqSys_tqIdcAirManModSp_C;
extern const sint16  TqSys_tqIdcIgnBenchModIniSp_C;
extern const sint16  TqSys_tqIdcIgnManModSp_C;
extern const uint16  TqSys_nEngX_A[TQSYS_NENGX_A_COLS];
extern const uint16  TqSys_tqAirSp_nEngX_posnAccPY_M[TQSYS_TQAIRSP_NENGX_POSNACCPY_M_LNS][TQSYS_TQAIRSP_NENGX_POSNACCPY_M_COLS];
extern const uint16  TqSys_tqIdcAirMaxRate_C;
extern const uint16  TqSys_tqIdcAirMinRate_C;
extern const uint16  TqSys_tqIdcIgnMaxRate_C;
extern const uint16  TqSys_tqIdcIgnMinRate_C;
extern const uint16  TqSys_tqIgnSp_nEngX_posnAccPY_M[TQSYS_TQIGNSP_NENGX_POSNACCPY_M_LNS][TQSYS_TQIGNSP_NENGX_POSNACCPY_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqSys_bTqSpBenchModEna;
extern sint16 TqSys_tqIdcAirSpBenchMod;
extern sint16 TqSys_tqIdcIgnSpBenchMod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TqSys_EveRst_SpBenchMod(void);
void TqSys_EveTDC_SpBenchMod(void);
void TqSys_SdlFast_SpBenchMod(void);
void TQSYSSPBENCHMOD_vidInit_TqSpBenchMod(void);
void TQSYSSPBENCHMOD_vidManage_TqAirSpBenchMod(void);
void TQSYSSPBENCHMOD_vidManage_TqIgnSpBenchMod(void);
void TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam(void);


#endif /* TQSYSSPBENCHMOD_H */

/*-------------------------------- end of file -------------------------------*/
