/***************************************************************************
;**
;** FILE NAME      : IGCOILMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCOILMNG_L_H
#define IGCOILMNG_L_H

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

extern const uint8  IGCOILMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean IgCmd_bInhIgCoilCmd;
extern boolean IgCmd_bInhIgCoilNxtCmd;
extern boolean IGCOILMNG_bIGBTAcqOuthyst;
extern uint8 IgCmd_stCurIgCoil;
extern uint8 IgCmd_stCurNxtIgCoil;
extern uint8 Ign_mode_status;
extern uint16 Icd_desired_current;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGCOILMNG_vidAgIgMng(void);
void IGCOILMNG_vidCalcDwellTime(void);
void IGCOILMNG_vidCalcIcdRatioEnergy(void);
void IGCOILMNG_vidCalcIcdState(void);
void IGCOILMNG_vidCallDiagICD(void);
void IGCOILMNG_vidCallDiagSdlFast(void);
void IGCOILMNG_vidDiagBob1(void);
void IGCOILMNG_vidDiagBob2(void);
void IGCOILMNG_vidDiagBob3(void);
void IGCOILMNG_vidDiagBob4(void);
void IGCOILMNG_vidDiagCoil(uint32 udtChannel,boolean *bDgoOc,boolean *bMonRunOc,boolean *bDgoScg,boolean *bMonRunScg,boolean *bDgoScp,boolean *bMonRunScp);
void IGCOILMNG_vidDiagnostic(void);
void IGCOILMNG_vidDisable(void);
void IGCOILMNG_vidDwellTime(void);
void IGCOILMNG_vidEnable(void);
void IGCOILMNG_vidIcdRatioEnergy(void);
void IGCOILMNG_vidInhibIgn(void);
void IGCOILMNG_vidInhibIgnNext(void);
void IGCOILMNG_vidInitilization(void);
void IGCOILMNG_vidInitOutput(void);
void IGCOILMNG_vidProgAvance(void);
void IGCOILMNG_vidProgAvanceNext(void);
void IGCOILMNG_vidTestInhibIgn(void);


#endif /* IGCOILMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
