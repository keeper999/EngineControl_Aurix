/***************************************************************************
;**
;** FILE NAME      : SPTMOD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPTMOD_L_H
#define SPTMOD_L_H

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

extern const uint8  SPTMOD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SPTMOD_bExt_ModSptSwitch;
extern boolean SPTMOD_bHystOutput1;
extern boolean SPTMOD_bHystOutput2;
extern uint32 SPTMOD_u32TqEfcLimModSptFi1Rest1;
extern uint32 SPTMOD_u32TqEfcLimModSptFi1Rest2;
extern uint32 SPTMOD_u32TqEfcLimModSptFi2Rest1;
extern uint32 SPTMOD_u32TqEfcLimModSptFi2Rest2;
extern uint8 TqSys_rBoostPresClcModSpt;
extern uint8 TqSys_rPwrEngClcModSpt;
extern uint8 TqSys_rTqEfcClcModSpt;
extern sint16 TqDem_tqEfcLimModSptFil1;
extern sint16 TqDem_tqEfcLimModSptFil2;
extern sint16 TqSys_tqEfcMaxNomModSpt;
extern sint16 TqSys_tqEfcModSpt;
extern uint16 TqSys_pBoostClcModSpt;
extern uint16 TqSys_pwrEngClcModSpt;
extern uint16 TqSys_tqEfcClcModSpt;
extern sint32 SPTMOD_s32TqEfcLimModSptFi1Prev1;
extern sint32 SPTMOD_s32TqEfcLimModSptFi1Prev2;
extern sint32 SPTMOD_s32TqEfcLimModSptFi2Prev1;
extern sint32 SPTMOD_s32TqEfcLimModSptFi2Prev2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SPTMOD_vidEng_State_Treatment(void);
void SPTMOD_vidInitOutputs(void);
void SPTMOD_vidRatio_Calculation(void);
void SPTMOD_vidSportMode_State(void);
void SPTMOD_vidSuperviseurModeSport(void);
void SPTMOD_vidTorque_Selection(void);
void SPTMOD_vidTrqLimitationFiltering(void);


#endif /* SPTMOD_L_H */

/*-------------------------------- end of file -------------------------------*/
