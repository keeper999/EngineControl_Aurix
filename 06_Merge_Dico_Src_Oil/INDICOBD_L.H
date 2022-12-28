/***************************************************************************
;**
;** FILE NAME      : INDICOBD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef INDICOBD_L_H
#define INDICOBD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
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

extern const uint8  INDICOBD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GMIL_bEngRun;
extern boolean INDICOBD_bDstCntRstCdnPrev;
extern uint32 Dist_hecto_depuis_RstDft;
extern uint32 Dist_hecto_parcourue_depuis_mil;
extern uint32 GMIL_tiEngrunMilOn;
extern uint32 GMIL_tiEngrunRstDft;
extern uint8 INDICOBD_u8ctDftObdCfPrev;
extern uint16 IndicOBD_DstHecto_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void INDICOBD_DstAndDurMIL(void);
void INDICOBD_vidDftMILCntDec(void);
void INDICOBD_vidDftMILCntInc(void);
void INDICOBD_vidDftMILCntPrev(void);
void INDICOBD_vidDftMILRstCnt(void);
void INDICOBD_vidDisableEngRun(void);
void INDICOBD_vidDstAndDurnCnt(uint32* DistHecto, uint32* GMIL_tiEngRun,uint16* GMIL_DstKm,uint16* GMIL_tiMinsEngRun);
void INDICOBD_vidDstCntRstCdn(void);
void INDICOBD_vidDstPrevCalc(void);
void INDICOBD_vidEnableEngRun(void);
void INDICOBD_vidF04_RstCnt(void);
void INDICOBD_vidIndicOBDDstRstDft(void);
void INDICOBD_vidIndicOBDDurRstDft(void);
void INDICOBD_vidIndObdDstAndDurRstDf(void);
void INDICOBD_vidInit(void);
void INDICOBD_vidMngDftMILCntDec(uint16 u16IdxDft);
void INDICOBD_vidMngDftMILCntInc(uint16 u16IdxDft);


#endif /* INDICOBD_L_H */

/*-------------------------------- end of file -------------------------------*/
