/***************************************************************************
;**
;** FILE NAME      : CLCNFISAGAIN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CLCNFISAGAIN.H"
#include "CLCNFISAGAIN_L.H"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

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
const uint8  CLCNFISAGAIN_u8inhib = 0;
const uint8  FISA_Enrich_facAdpY_A[FISA_ENRICH_FACADPY_A_COLS] = {0};
const uint8  FISA_Enrich_tCoMesX_A[FISA_ENRICH_TCOMESX_A_COLS] = {0};
const uint8  FISA_facTranAdp_M[FISA_FACTRANADP_M_LNS][FISA_FACTRANADP_M_COLS] = {0};
const uint16  FISA_facAstAdp_M[FISA_FACASTADP_M_LNS][FISA_FACASTADP_M_COLS] = {0};
const uint16  FISA_facStrtAdp_M[FISA_FACSTRTADP_M_LNS][FISA_FACSTRTADP_M_COLS] = {0};
const uint16  FISA_facWupAdp_M[FISA_FACWUPADP_M_LNS][FISA_FACWUPADP_M_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 FISA_facOld;
uint8 FISA_facTranAdp;
uint16 FISA_facAstAdp;
uint16 FISA_facStrtAdp;
uint16 FISA_facWupAdp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

