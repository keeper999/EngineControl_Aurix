/***************************************************************************
;**
;** FILE NAME      : AVRMISFCNT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AVRMISFCNT_L_H
#define AVRMISFCNT_L_H

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

extern const uint8  AVRMISFCNT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AVRMISFCNT_bMfMisfDetecUavb0Prev;
extern boolean Mf_1_mf_Mod6_uavb0;
extern boolean Mf_2_mf_Mod6_uavb0;
extern boolean Misf_bEnaMisfCntCyl1;
extern boolean Misf_bEnaMisfCntCyl2;
extern boolean Misf_bEnaMisfCntCyl3;
extern boolean Misf_bEnaMisfCntCyl4;
extern uint8 AVRMISFCNT_u8MfNoCyMod6Uavb0Prev;
extern uint8 Mf_no_cyl_mod6_uavb0;
extern uint16 MonMisf_ctOccurMfDCCyl1_Raw;
extern uint16 MonMisf_ctOccurMfDCCyl2_Raw;
extern uint16 MonMisf_ctOccurMfDCCyl3_Raw;
extern uint16 MonMisf_ctOccurMfDCCyl4_Raw;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AVRMISFCNT_vidCntMisfPerCycleCyl(void);
void AVRMISFCNT_vidEWMA_MisfireCalc(void);
void AVRMISFCNT_vidInitCntMisf(void);
void AVRMISFCNT_vidInitOutput(void);
void AVRMISFCNT_vidMisfCntCyl_1(void);
void AVRMISFCNT_vidMisfCntCyl_2(void);
void AVRMISFCNT_vidMisfCntCyl_3(void);
void AVRMISFCNT_vidMisfCntCyl_4(void);
void AVRMISFCNT_vidMisfDetectPerCyl(void);
void AVRMISFCNT_vidNumMisfirePerCycle(void);
void AVRMISFCNT_vidReinit_Cnt_Misf(void);
void AVRMISFCNT_vidRstEWMAMisfireMod4(void);


#endif /* AVRMISFCNT_L_H */

/*-------------------------------- end of file -------------------------------*/
