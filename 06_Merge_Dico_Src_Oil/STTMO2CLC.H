/***************************************************************************
;**
;** FILE NAME      : STTMO2CLC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef STTMO2CLC_H
#define STTMO2CLC_H

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

extern const sint8  Eng_FacmO2DownLsLean_UpLean_C;
extern const sint8  Eng_FacmO2DownLsLean_UpRich_C;
extern const sint8  Eng_FacmO2DownLsRich_UpLean_C;
extern const sint8  Eng_FacmO2DownLsRich_UpRich_C;
extern const uint16  Eng_FacmO2Stall_C;
extern const uint16  Eng_mO2EstimOxCInit_C;
extern const uint16  Eng_VoltDownLsHighLim_C;
extern const uint16  Eng_VoltDownLsHighLowLim_C;
extern const uint16  Eng_VoltDownLsLowHighLim_C;
extern const uint16  Eng_VoltDownLsLowLim_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Eng_ctTDCStrt;
extern uint16 Eng_mO2Cat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STT_EveRst_STTmO2Clc(void);
void STT_EveTDC_STTmO2Clc(void);
void STT_SdlFast_STTmO2Clc(void);


#endif /* STTMO2CLC_H */

/*-------------------------------- end of file -------------------------------*/
