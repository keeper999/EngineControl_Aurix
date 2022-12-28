/***************************************************************************
;**
;** FILE NAME      : LAYERSYNC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef LAYERSYNC_L_H
#define LAYERSYNC_L_H

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

extern const uint8  LAYERSYNC_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean SyncAcq_bCalcOk;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void LAYERSYNC_vidAcq(void);
void LAYERSYNC_vidAcqExPos(void);
void LAYERSYNC_vidAcqInPos(void);
void LAYERSYNC_vidAcquiDureeDent(void);
void LAYERSYNC_vidAcquiPeriodeMoteur(void);
void LAYERSYNC_vidBwdRotMng(void);
void LAYERSYNC_vidCallAPI(void);
void LAYERSYNC_vidChangeOfMind(void);
void LAYERSYNC_vidCkOff(void);
void LAYERSYNC_vidCtEdgeCmExRstrt(void);
void LAYERSYNC_vidCtEdgeCmExStrt(void);
void LAYERSYNC_vidCtEdgeCmInRstrt(void);
void LAYERSYNC_vidCtEdgeCmInStrt(void);
void LAYERSYNC_vidDiagExCm(void);
void LAYERSYNC_vidDiagInCm(void);
void LAYERSYNC_vidDisBwdRot(void);
void LAYERSYNC_vidDisQuickSync(void);
void LAYERSYNC_vidEnaBwdRot(void);
void LAYERSYNC_vidEnaQuickSync(void);
void LAYERSYNC_vidEngStopPosn(void);
void LAYERSYNC_vidEngStopPosnAfter(void);
void LAYERSYNC_vidExAcq(void);
void LAYERSYNC_vidExCmSt(void);
void LAYERSYNC_vidInCmSt(void);
void LAYERSYNC_vidIniAcq(void);
void LAYERSYNC_vidIniExAcq(void);
void LAYERSYNC_vidIniExAcqPos(void);
void LAYERSYNC_vidIniExCmAcq(void);
void LAYERSYNC_vidIniInAcqPos(void);
void LAYERSYNC_vidIniInCmAcq(void);
void LAYERSYNC_vidInit(void);
void LAYERSYNC_vidInitAPI(void);
void LAYERSYNC_vidIniTDCCnt(void);
void LAYERSYNC_vidInitOutput(void);
void LAYERSYNC_vidPhaseCylEch(void);
void LAYERSYNC_vidReadToothInfo(void);
void LAYERSYNC_vidTrouverPhaseMoteur(void);


#endif /* LAYERSYNC_L_H */

/*-------------------------------- end of file -------------------------------*/
