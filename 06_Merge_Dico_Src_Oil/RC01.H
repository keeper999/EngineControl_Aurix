/***************************************************************************
;**
;** FILE NAME      : RC01.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RC01_H
#define RC01_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CAT                               0
#define CLASRDY_CAT_NB_DFT                5
#define CLASRDY_HEATO2_NB_DFT             20
#define CLASRDY_LFBK_NB_DFT               40
#define CLASRDY_MISF_NB_DFT               10
#define CLASRDY_O2S_NB_DFT                20
#define CLASRDY_VVT_NB_DFT                20
#define CLASRDYCAT_T_COLS                      ( 5 )
#define CLASRDYHEATO2_T_COLS                   ( 20 )
#define CLASRDYLFBK_T_COLS                     ( 40 )
#define CLASRDYMISF_T_COLS                     ( 10 )
#define CLASRDYO2S_T_COLS                      ( 20 )
#define CLASRDYVVT_T_COLS                      ( 20 )
#define CLIM                              7
#define CPT                               9
#define EVAP                              8
#define GD_BPRIORDY_LNS                       ( 972 )
#define HEATCAT                           10
#define HEATO2                            1
#define IAE                               3
#define LFBK                              4
#define MISF                              5
#define O2S                               6
#define RC01_FAMILY_NB                    8
#define RDY_AU8CTDC_LNS                       ( 972 )
#define VVTRC01                           2

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

extern const uint16  ClasRdyCat_T[CLASRDYCAT_T_COLS];
extern const uint16  ClasRdyHeatO2_T[CLASRDYHEATO2_T_COLS];
extern const uint16  ClasRdyLfbk_T[CLASRDYLFBK_T_COLS];
extern const uint16  ClasRdyMisf_T[CLASRDYMISF_T_COLS];
extern const uint16  ClasRdyO2S_T[CLASRDYO2S_T_COLS];
extern const uint16  ClasRdyVVT_T[CLASRDYVVT_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GD_bPrioRdy[GD_BPRIORDY_LNS];
extern uint8 Rdy_au8ctDC[RDY_AU8CTDC_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_Rdy(void);
void GD_EveRstDft_Rdy(void);
void GD_EveRstDftObd_Rdy(void);
void RC01_vidExitEveStObdRec(uint16 u16IdxDft);
void RC01_vidMngEveGlbDCStrt(void);
void RC01_vidMngEveRstDft(void);


#endif /* RC01_H */

/*-------------------------------- end of file -------------------------------*/
