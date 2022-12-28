/***************************************************************************
;**
;** FILE NAME      : IDLSYSCUTOFF_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IDLSYSCUTOFF_L_H
#define IDLSYSCUTOFF_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
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

extern const uint8  IDLSYSCUTOFF_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IdlSys_bAuthInjCutOffINEng;
extern boolean IdlSys_bAuthInjCutOffIVC;
extern boolean IdlSys_bCdnNEngInjCutOffIVC;
extern boolean IdlSys_bCdnTqInjCutOffIVC;
extern boolean IDLSYSCUTOFF_bPosHysOut;
extern sint16 IdlSys_nGrdFilInjCutOff_MP;
extern uint16 IdlSys_nInhInjCutOffNEng_MP;
extern sint32 IDLSYSCUTOFF_s32FiltredTrtTDCMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IDLSYSCUTOFF_vidAutoriCoupureInj(void);
void IDLSYSCUTOFF_vidCalcAutorCoupIVC(void);
void IDLSYSCUTOFF_vidCalcCondCouple(void);
void IDLSYSCUTOFF_vidCalcCondRegime(void);
void IDLSYSCUTOFF_vidCalculCondIVC(void);
void IDLSYSCUTOFF_vidCalculCondRegime(void);
void IDLSYSCUTOFF_vidInitOutput(void);


#endif /* IDLSYSCUTOFF_L_H */

/*-------------------------------- end of file -------------------------------*/
