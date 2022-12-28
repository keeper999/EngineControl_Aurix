/***************************************************************************
;**
;** FILE NAME      : IDLSYSCUTOFF.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IDLSYSCUTOFF.H"
#include "IDLSYSCUTOFF_L.H"
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
const boolean  IdlSys_bAcvInjCutOffNEng_C = 0;
const uint8  IdlSys_facCorAcvInjNEng_T[IDLSYS_FACCORACVINJNENG_T_COLS] = {0};
const uint8  IdlSys_tCoInjCutOff_A[IDLSYS_TCOINJCUTOFF_A_COLS] = {0};
const uint8  IDLSYSCUTOFF_u8Inhib = 0;
const sint16  IdlSys_tqThdAuthInjCutOff_C = 0;
const uint16  IdlSys_nGrdInjCutOff_A[IDLSYS_NGRDINJCUTOFF_A_COLS] = {0};
const uint16  IdlSys_nOfsAcvInjNEng_M[IDLSYS_NOFSACVINJNENG_M_LNS][IDLSYS_NOFSACVINJNENG_M_COLS] = {0};
const uint16  IdlSys_nOfsAuthInjCutOffIVC_M[IDLSYS_NOFSAUTHINJCUTOFFIVC_M_LNS][IDLSYS_NOFSAUTHINJCUTOFFIVC_M_COLS] = {0};
const uint16  IdlSys_nOfsInjCutOffNEng_T[IDLSYS_NOFSINJCUTOFFNENG_T_COLS] = {0};
const uint16  IdlSys_tiFilNGrdInjCutOff_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IdlSys_bAuthInjCutOffINEng;
boolean IdlSys_bAuthInjCutOffIVC;
boolean IdlSys_bCdnNEngInjCutOffIVC;
boolean IdlSys_bCdnTqInjCutOffIVC;
boolean IdlSys_bInjCutOff;
boolean IDLSYSCUTOFF_bPosHysOut;
sint16 IdlSys_nGrdFilInjCutOff_MP;
uint16 IdlSys_nInhInjCutOffNEng_MP;
sint32 IDLSYSCUTOFF_s32FiltredTrtTDCMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

