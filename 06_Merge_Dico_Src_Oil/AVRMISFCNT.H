/***************************************************************************
;**
;** FILE NAME      : AVRMISFCNT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AVRMISFCNT_H
#define AVRMISFCNT_H

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

extern const uint8  MonMisf_facEWMACyl_C;
extern const uint16  MonMisf_nEngMinAcvCtMfAvg_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 MonMisf_ctOccurMfAvg10DCCyl1;
extern uint16 MonMisf_ctOccurMfAvg10DCCyl2;
extern uint16 MonMisf_ctOccurMfAvg10DCCyl3;
extern uint16 MonMisf_ctOccurMfAvg10DCCyl4;
extern uint16 MonMisf_ctOccurMfDCCyl1;
extern uint16 MonMisf_ctOccurMfDCCyl2;
extern uint16 MonMisf_ctOccurMfDCCyl3;
extern uint16 MonMisf_ctOccurMfDCCyl4;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Misf_EveCrTR_AvrMisfCnt(void);
void Misf_EveKOf_AvrMisfCnt(void);
void Misf_EveMisf_AvrMisfCnt(void);
void Misf_EveRst_AvrMisfCnt(void);
void Misf_EveRstDftObd_AvrMisfCnt(void);


#endif /* AVRMISFCNT_H */

/*-------------------------------- end of file -------------------------------*/
