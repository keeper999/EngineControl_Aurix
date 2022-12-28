/***************************************************************************
;**
;** FILE NAME      : CRSCTLBSITREAT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CRSCTLBSITREAT_H
#define CRSCTLBSITREAT_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CRSCTLBSITREAT_I.h"
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

extern const uint8  VSCtl_ctDecEvenFrame_C;
extern const uint8  VSCtl_ctDecZeroFrame_C;
extern const uint8  VSCtl_ctEvenFrameThd_C;
extern const uint8  VSCtl_ctIncEvenFrame_C;
extern const uint8  VSCtl_ctIncMaxFrame_C;
extern const uint8  VSCtl_ctIncMinFrame_C;
extern const uint8  VSCtl_ctIncZeroFrame_C;
extern const uint8  VSCtl_ctZeroFrameThd_C;
extern const uint8  VSCtl_spdVSLimReqDeltaMax1_C;
extern const uint8  VSCtl_spdVSLimReqDeltaMin1_C;
extern const uint8  VSCtl_spdVSLimReqMaxThd_C;
extern const uint8  VSCtl_spdVSLimReqMinThd_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMax1_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMax2_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMax3_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMax4_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMin1_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMin2_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMin3_C;
extern const uint8  VSCtl_spdVSRegReqDeltaMin4_C;
extern const uint8  VSCtl_spdVSRegReqMaxThd_C;
extern const uint8  VSCtl_spdVSRegReqMinThd_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CrsCtl_EveRst_CrsCtlBsiTreat(void);
void CrsCtl_EveRxn50E_CrsCtlBsiTreat(void);
void CrsCtl_SdlSlow_CrsCtlBsiTreat(void);


#endif /* CRSCTLBSITREAT_H */

/*-------------------------------- end of file -------------------------------*/
