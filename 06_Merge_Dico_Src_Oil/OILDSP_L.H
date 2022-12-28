/***************************************************************************
;**
;** FILE NAME      : OILDSP_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILDSP_L_H
#define OILDSP_L_H

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

extern const uint8  OILDSP_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean OilDsp_bDgoIdcBlbyCnd;
extern boolean OilDsp_bMonRunIdcBlbyCnd;
extern boolean OilSys_EnaOilAbs_TCdn;
extern boolean OilSys_EnaOilDsp_TCdn;
extern uint32 OilDsp_mFuInOilEstimPrev;
extern uint8 OilDsp_rCrcPresInPresBlbyCnd;
extern uint8 OilDsp_rFuDspInBlbyCnd;
extern uint8 OilDsp_rFuMassInOil;
extern uint8 OilDsp_rMassFlowInBlbyCnd;
extern uint16 OilDsp_mFuDspBlbyCndEstim;
extern uint16 OilDsp_mFuInjBurn;
extern uint16 OilDsp_mFuResiAfterCmb;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OILDSP_NVMSRV_vidInit(void);
void OILDSP_vidAbsorption(void);
void OILDSP_vidDesorption(void);
void OILDSP_vidDisableAFACanister(void);
void OILDSP_vidEnaAbsorption(void);
void OILDSP_vidEnaDesorption(void);
void OILDSP_vidInit(void);
void OILDSP_vidInitOutput(void);


#endif /* OILDSP_L_H */

/*-------------------------------- end of file -------------------------------*/
