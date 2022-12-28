/***************************************************************************
;**
;** FILE NAME      : TQLIMSFTY.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQLIMSFTY_H
#define TQLIMSFTY_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ENGLIM_TQIDCSYST_GEAR_A_COLS           ( 8 )
#define ENGLIM_TQIDCSYST_M_LNS                ( 8 )
#define ENGLIM_TQIDCSYST_M_COLS                ( 10 )
#define ENGLIM_TQIDCSYST_NENG_A_COLS           ( 10 )

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

extern const uint8  EngLim_tqIdcSyst_Gear_A[ENGLIM_TQIDCSYST_GEAR_A_COLS];
extern const sint16  EngLim_tqGrdSftyDec_C;
extern const uint16  EngLim_tqIdcSyst_M[ENGLIM_TQIDCSYST_M_LNS][ENGLIM_TQIDCSYST_M_COLS];
extern const uint16  EngLim_tqIdcSyst_nEng_A[ENGLIM_TQIDCSYST_NENG_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TqSys_EveRst_tqLimSfty(void);
void TqSys_SdlFast_tqLimSfty(void);


#endif /* TQLIMSFTY_H */

/*-------------------------------- end of file -------------------------------*/
