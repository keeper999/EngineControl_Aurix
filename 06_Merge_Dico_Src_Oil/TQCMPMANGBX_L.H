/***************************************************************************
;**
;** FILE NAME      : TQCMPMANGBX_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQCMPMANGBX_L_H
#define TQCMPMANGBX_L_H

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

extern const uint8  TQCMPMANGBX_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean TqDem_bManGBxLossClc;
extern uint32 TQCMPMANGBX_u32EOM_tiEngStopMem;
extern sint16 TqCmp_tManGBx_MP;
extern sint16 TqCmp_tOilFil;
extern uint16 TqCmp_tiEngRunClu;
extern uint16 TQCMPMANGBX_u16Eng_nCkFilPrev;
extern sint32 TQCMPMANGBX_s32TqCmptOilFilMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQCMPMANGBX_vidInitOutput(void);
void TQCMPMANGBX_vidManualGearBoxLoss(void);


#endif /* TQCMPMANGBX_L_H */

/*-------------------------------- end of file -------------------------------*/
