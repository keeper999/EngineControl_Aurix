/***************************************************************************
;**
;** FILE NAME      : IUPRRATIO.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRRATIO_H
#define IUPRRATIO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "gd_api.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BPIUPR                            10
#define CAT1_ASW                          1
#define EVAPIUPR                          11
#define IUPR_CTDENGRPRAT_LNS                  ( 12 )
#define IUPR_CTNUMGRPRAT_LNS                  ( 12 )
#define IUPR_CTNUMPRIVE_LNS                   ( 100 )
#define IUPR_DENCHOICERAT_C_LNS               ( 100 )
#define IUPR_IDXDFTRAT_C_LNS                  ( 100 )
#define IUPR_IDXGRPRAT_C_LNS                  ( 100 )
#define IUPR_NB_DENOM_USED                8
#define IUPR_NB_RAT                       100
#define IUPRRATIO_ABDCPREV_LNS                ( 100 )
#define IUPRRATIO_DENCHOICEPREV_LNS           ( 100 )
#define MAX_GRP_RAT                       12
#define O2S1                              6
#define PRIVE                             0
#define SO2S1                             9
#define VVT                               8

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

extern const uint8  Iupr_DenChoiceRat_C[IUPR_DENCHOICERAT_C_LNS];
extern const uint8  IUPR_idxGrpRat_C[IUPR_IDXGRPRAT_C_LNS];
extern const uint8  IUPRRATIO_u8Inhib;
extern const uint16  IUPR_idxDftRat_C[IUPR_IDXDFTRAT_C_LNS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IUPRRATIO_abDcPrev[IUPRRATIO_ABDCPREV_LNS];
extern boolean IUPRRATIO_DenChoicePrev[IUPRRATIO_DENCHOICEPREV_LNS];
extern uint16 IUPR_ctDenGrpRat[IUPR_CTDENGRPRAT_LNS];
extern uint16 IUPR_ctNumGrpRat[IUPR_CTNUMGRPRAT_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveRst_IuprRatio(void);
void IUPRRATIO_vidMngEveSdlSlow(void);


#endif /* IUPRRATIO_H */

/*-------------------------------- end of file -------------------------------*/
