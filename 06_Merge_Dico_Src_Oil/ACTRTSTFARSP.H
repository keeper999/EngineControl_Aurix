/***************************************************************************
;**
;** FILE NAME      : ACTRTSTFARSP.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACTRTSTFARSP_H
#define ACTRTSTFARSP_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define FarSp_SampleTiFast_SC             10

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st128 */
#define FARSP_ACTRTST_IDLE                0
#define FARSP_ACTRTST_EE                  1
#define FARSP_ACTRTST_PHASE1              2
#define FARSP_ACTRTST_PHASE2              4
#define FARSP_ACTRTST_END                 6
/*extern uint8 FarSp_stActrTst;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  FarSp_bInhSenO2UsEEDiag_C;
extern const uint8  Afts_uAflRlamSpTest_C;
extern const uint8  Afts_uAfrRlamSpTest_C;
extern const uint16  ActrTstFarSp_Tempo_C;
extern const uint16  Afts_rMixtReqAflRlamSpTest_C;
extern const uint16  Afts_rMixtReqAfrRlamSpTest_C;
extern const uint16  Afts_tiDlyPha1RlamSpTest_C;
extern const uint16  Afts_tiDlyPha2RlamSpTest_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 FarSp_stActrTst;
extern boolean FarSp_bActrTstCmpl;
extern boolean FarSp_bTstInProgs;
extern boolean FarSp_bUsPlausFcoActrTst;
extern boolean FarSp_bUsPlausFldActrTst;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void FarSp_EveRst_ActrTstFarSp(void);
void FarSp_SdlFast_ActrTstFarSp(void);


#endif /* ACTRTSTFARSP_H */

/*-------------------------------- end of file -------------------------------*/
