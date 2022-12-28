/***************************************************************************
;**
;** FILE NAME      : SPYSTT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SPYSTT_L_H
#define SPYSTT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SPYSTT_U8PRMHISDSTWIN_LENGTH      2
#define SPYSTT_U8STOPCASE_LENGTH          11

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

extern const uint8  SPYSTT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean SpySTT_bCutCaseAcvt;
extern boolean SPYSTT_bRecHisNotStopCase_Prev;
extern boolean SPYSTT_bRecNotStop_Prev;
extern uint8 SpySTT_stCutCaseCur;
extern uint8 SPYSTT_u8CoPtUH_stPwt_Prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SPYSTT_NVMSRV_vidInit(void);
void SPYSTT_vidCutCaseRec(void);
void SPYSTT_vidCutCasRstFaiRec(void);
void SPYSTT_vidInitOutput(void);
void SPYSTT_vidRecHisNotStopCase(void);
void SPYSTT_vidRecNotStopCase(void);
void SPYSTT_vidRecNotStopCase1(void);
void SPYSTT_vidRstrtFaiRec(void);


#endif /* SPYSTT_L_H */

/*-------------------------------- end of file -------------------------------*/
