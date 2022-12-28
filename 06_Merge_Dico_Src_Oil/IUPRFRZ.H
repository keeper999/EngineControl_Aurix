/***************************************************************************
;**
;** FILE NAME      : IUPRFRZ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRFRZ_H
#define IUPRFRZ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IUPR_BFRZRAT_LNS                      ( 100 )
#define IUPR_FRZ_NB_DFT                   30
#define IUPR_IDXFRZCNTOBDSTRT_T_COLS           ( 30 )
#define IUPR_IDXFRZGENDEN_T_COLS               ( 30 )
#define IUPR_IDXFRZRAT_T_LNS                  ( 100 )
#define IUPR_IDXFRZRAT_T_COLS                  ( 30 )

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

extern const uint8  IUPRFRZ_u8Inhib;
extern const uint16  Iupr_idxFrzCntObdStrt_T[IUPR_IDXFRZCNTOBDSTRT_T_COLS];
extern const uint16  Iupr_idxFrzGenDen_T[IUPR_IDXFRZGENDEN_T_COLS];
extern const uint16  Iupr_idxFrzRat_T[IUPR_IDXFRZRAT_T_LNS][IUPR_IDXFRZRAT_T_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Iupr_bFrzCntObdStrt;
extern boolean Iupr_bFrzGenDen;
extern boolean Iupr_bFrzRat[IUPR_BFRZRAT_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_IuprFrz(void);
void GD_SdlSlow_IuprFrz(void);


#endif /* IUPRFRZ_H */

/*-------------------------------- end of file -------------------------------*/
