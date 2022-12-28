/***************************************************************************
;**
;** FILE NAME      : CLCNFISAGAIN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLCNFISAGAIN_H
#define CLCNFISAGAIN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define FISA_ENRICH_FACADPY_A_COLS             ( 5 )
#define FISA_ENRICH_TCOMESX_A_COLS             ( 12 )
#define FISA_FACASTADP_M_LNS                  ( 12 )
#define FISA_FACASTADP_M_COLS                  ( 5 )
#define FISA_FACSTRTADP_M_LNS                 ( 12 )
#define FISA_FACSTRTADP_M_COLS                 ( 5 )
#define FISA_FACTRANADP_M_LNS                 ( 12 )
#define FISA_FACTRANADP_M_COLS                 ( 5 )
#define FISA_FACWUPADP_M_LNS                  ( 12 )
#define FISA_FACWUPADP_M_COLS                  ( 5 )

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

extern const uint8  FISA_Enrich_facAdpY_A[FISA_ENRICH_FACADPY_A_COLS];
extern const uint8  FISA_Enrich_tCoMesX_A[FISA_ENRICH_TCOMESX_A_COLS];
extern const uint8  FISA_facTranAdp_M[FISA_FACTRANADP_M_LNS][FISA_FACTRANADP_M_COLS];
extern const uint16  FISA_facAstAdp_M[FISA_FACASTADP_M_LNS][FISA_FACASTADP_M_COLS];
extern const uint16  FISA_facStrtAdp_M[FISA_FACSTRTADP_M_LNS][FISA_FACSTRTADP_M_COLS];
extern const uint16  FISA_facWupAdp_M[FISA_FACWUPADP_M_LNS][FISA_FACWUPADP_M_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 FISA_facOld;
extern uint8 FISA_facTranAdp;
extern uint16 FISA_facAstAdp;
extern uint16 FISA_facStrtAdp;
extern uint16 FISA_facWupAdp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CLCNFISAGAIN_vidEntryInit(void);
void Fisa_EvePwrl_ClcnFisaGain(void);
void Fisa_EveStTR_ClcnFisaGain(void);
void Fisa_EveTDC_ClcnFisaGain(void);


#endif /* CLCNFISAGAIN_H */

/*-------------------------------- end of file -------------------------------*/
