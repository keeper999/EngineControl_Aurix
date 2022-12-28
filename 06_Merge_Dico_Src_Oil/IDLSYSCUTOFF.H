/***************************************************************************
;**
;** FILE NAME      : IDLSYSCUTOFF.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLSYSCUTOFF_H
#define IDLSYSCUTOFF_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IDLSYS_FACCORACVINJNENG_T_COLS         ( 8 )
#define IDLSYS_NGRDINJCUTOFF_A_COLS            ( 12 )
#define IDLSYS_NOFSACVINJNENG_M_LNS           ( 12 )
#define IDLSYS_NOFSACVINJNENG_M_COLS           ( 8 )
#define IDLSYS_NOFSAUTHINJCUTOFFIVC_M_LNS     ( 8 )
#define IDLSYS_NOFSAUTHINJCUTOFFIVC_M_COLS     ( 8 )
#define IDLSYS_NOFSINJCUTOFFNENG_T_COLS        ( 8 )
#define IDLSYS_TCOINJCUTOFF_A_COLS             ( 8 )

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

extern const boolean  IdlSys_bAcvInjCutOffNEng_C;
extern const uint8  IdlSys_facCorAcvInjNEng_T[IDLSYS_FACCORACVINJNENG_T_COLS];
extern const uint8  IdlSys_tCoInjCutOff_A[IDLSYS_TCOINJCUTOFF_A_COLS];
extern const sint16  IdlSys_tqThdAuthInjCutOff_C;
extern const uint16  IdlSys_nGrdInjCutOff_A[IDLSYS_NGRDINJCUTOFF_A_COLS];
extern const uint16  IdlSys_nOfsAcvInjNEng_M[IDLSYS_NOFSACVINJNENG_M_LNS][IDLSYS_NOFSACVINJNENG_M_COLS];
extern const uint16  IdlSys_nOfsAuthInjCutOffIVC_M[IDLSYS_NOFSAUTHINJCUTOFFIVC_M_LNS][IDLSYS_NOFSAUTHINJCUTOFFIVC_M_COLS];
extern const uint16  IdlSys_nOfsInjCutOffNEng_T[IDLSYS_NOFSINJCUTOFFNENG_T_COLS];
extern const uint16  IdlSys_tiFilNGrdInjCutOff_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IdlSys_bInjCutOff;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IdlSys_EveSync_bInjCutOff(void);
void IDLSYSCUTOFF_vidEntryInit(void);


#endif /* IDLSYSCUTOFF_H */

/*-------------------------------- end of file -------------------------------*/
