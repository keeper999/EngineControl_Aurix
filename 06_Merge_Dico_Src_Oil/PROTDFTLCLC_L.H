/***************************************************************************
;**
;** FILE NAME      : PROTDFTLCLC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef PROTDFTLCLC_L_H
#define PROTDFTLCLC_L_H

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

extern const uint8  PROTDFTLCLC_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoPt_bProtDftlAcv;
extern boolean PROTDFTLCLC_bActivationMem;
extern boolean PROTDFTLCLC_bActivationMemBrk;
extern boolean PROTDFTLCLC_bEtatTmr;
extern boolean PROTDFTLCLC_bEtatTmrBrk;
extern boolean PROTDFTLCLC_bOutHysNeg;
extern uint32 PROTDFTLCLC_u32rFilDftlWhlMem;
extern uint32 PROTDFTLCLC_u32rFilLeFrntWhlMem;
extern uint32 PROTDFTLCLC_u32rFilLeReWhlMem;
extern uint32 PROTDFTLCLC_u32rFilMaxProtMem;
extern uint32 PROTDFTLCLC_u32rFilRiFrntWhlMem;
extern uint32 PROTDFTLCLC_u32rFilRiReWhlMem;
extern sint8 CoPt_facSignNDftlWhl_MP;
extern uint8 CoPt_rEProtDftl;
extern uint8 PROTDFTLCLC_u8AcvBrkSelPrev;
extern uint8 PROTDFTLCLC_u8AcvDeacBrkTr;
extern uint8 PROTDFTLCLC_u8AcvDeacBrkTrDly;
extern uint8 PROTDFTLCLC_u8AcvDeacTr;
extern uint8 PROTDFTLCLC_u8AcvDeacTrDly;
extern uint8 PROTDFTLCLC_u8Counter;
extern uint8 PROTDFTLCLC_u8CounterBrk;
extern uint8 PROTDFTLCLC_u8ProtAcvBrkSelOld;
extern uint8 PROTDFTLCLC_u8ProtAcvSelOld;
extern uint8 PROTDFTLCLC_u8ProtAcvSelPrev;
extern sint16 CoPt_tqEfcMaxProtBrk;
extern sint16 CoPt_tqEfcMaxProtBrk_MP;
extern sint16 CoPt_tqEfcMaxProtDftlBfCord;
extern sint16 CoPt_tqMaxProtDftlBfCord_MP;
extern sint16 PROTDFTLCLC_s16MaxProtBfCord;
extern sint16 PROTDFTLCLC_s16MaxProtBrk;
extern uint16 CoPt_nDftlWhl;
extern uint16 CoPt_nReWhlAvr;
extern uint16 CoPt_pwrProtDftl;
extern uint16 CoPt_pwrProtDftl_MP;
extern uint16 CoPt_tqWhlMaxProtDftl;
extern uint16 CoPt_tqWhlProtDftl;
extern uint16 CoPt_wMaxProtDftl;
extern uint16 CoPt_wMaxSpcProtDftl;
extern uint16 CoPt_wProtDftl;
extern uint16 CoPt_wSpcProtDftl;
extern uint16 PROTDFTLCLC_u16CoProtDftl;
extern uint16 PROTDFTLCLC_u16CoPtDftlWhl;
extern uint16 PROTDFTLCLC_u16SpdLeFrntWhl;
extern uint16 PROTDFTLCLC_u16SpdLeReWhl;
extern uint16 PROTDFTLCLC_u16SpdRiFrntWhl;
extern uint16 PROTDFTLCLC_u16SpdRiReWhl;
extern uint16 PROTDFTLCLC_u16WhlMaxProtDftl;
extern sint32 PROTDFTLCLC_s32rFilMaxProtBrkMem;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void PROTDFTLCLC_vidCoordCouplLimit(void);
void PROTDFTLCLC_vidDetActLimitCouple(void);
void PROTDFTLCLC_vidDetCoupleCouronne(void);
void PROTDFTLCLC_vidDetCoupleLimitMot(void);
void PROTDFTLCLC_vidDetCoupleLimitRou(void);
void PROTDFTLCLC_vidDetCoupleProtDiff(void);
void PROTDFTLCLC_vidDetCouplProtFrein(void);
void PROTDFTLCLC_vidDetEnergieCourant(void);
void PROTDFTLCLC_vidDeterminerEnergie(void);
void PROTDFTLCLC_vidDetPuissance(void);
void PROTDFTLCLC_vidEstimerRegimeDiff(void);
void PROTDFTLCLC_vidEstimSollicit(void);
void PROTDFTLCLC_vidEstimSollicitDiff(void);
void PROTDFTLCLC_vidInitOutput(void);


#endif /* PROTDFTLCLC_L_H */

/*-------------------------------- end of file -------------------------------*/
