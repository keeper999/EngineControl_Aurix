/***************************************************************************
;**
;** FILE NAME      : THRSFTYMNG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef THRSFTYMNG_H
#define THRSFTYMNG_H

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

extern const boolean  Thr_bAcvHotRstCdn_CpuSfty;
extern const uint16  Thr_posnDriftLihMeasThd1_C;
extern const uint16  Tpac_tiDlyDetDftRetLih;
extern const uint16  Tpac_tiDlyDiagDftRetLih;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Thr_bCdnTestInh_CpuSfty;
extern boolean Thr_bTestAbort_ThrSftyMng;
extern boolean Thr_bTestStart_ThrSftyMng;
extern boolean ThrSftyMng_bThrPosnLihDrift;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Thr_EveChkLih_ThrSftyMng(void);
void Thr_EveClcnServo_ThrSftyMng(void);
void Thr_EveRst_ThrCpuSftyMng(void);
void Thr_EveTestAbort_ThrSftyMng(void);
void Thr_EveTestStart_ThrSftyMng(void);
void Thr_SdlFast_ThrSftyMng(void);


#endif /* THRSFTYMNG_H */

/*-------------------------------- end of file -------------------------------*/
