/***************************************************************************
;**
;** FILE NAME      : SUMRAT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SUMRAT_H
#define SUMRAT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IUPR_NB_DFT_PAR_MOD               5
#define IUPR_NB_MOD_PRE_REG               3
#define SUMRAT_AU8PREVDRVCYC_LNS              ( 972 )
#define SUMRAT_IDXDFTIUPRSYNT_C_LNS           ( 3 )
#define SUMRAT_IDXDFTIUPRSYNT_C_COLS           ( 5 )

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

extern const uint8  SUMRAT_u8Inhib;
extern const uint16  SumRat_idxDftIUPRSynt_C[SUMRAT_IDXDFTIUPRSYNT_C_LNS][SUMRAT_IDXDFTIUPRSYNT_C_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Sumrat_au8PrevDrvCyc[SUMRAT_AU8PREVDRVCYC_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_SumRat(void);
void GD_SdlSlow_SumRat(void);


#endif /* SUMRAT_H */

/*-------------------------------- end of file -------------------------------*/
