/***************************************************************************
;**
;** FILE NAME      : CLUPEDFREQACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLUPEDFREQACQ_L_H
#define CLUPEDFREQACQ_L_H

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

extern const uint8  CLUPEDFREQACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CLUPEDFREQACQ_bFilSig_1;
extern boolean CLUPEDFREQACQ_bFilSig_2;
extern boolean CLUPEDFREQACQ_bScgrCluPedPrsMes;
extern boolean CLUPEDFREQACQ_bScprCluPedPrsMes;
extern boolean Ext_bDgoGrd_rCluPedPrssMes;
extern boolean Ext_bDgoORng_rCluPedPrssMes;
extern boolean Ext_bDgoScg_rCluPedPrssMes;
extern boolean Ext_bDgoScp_rCluPedPrssMes;
extern boolean Ext_bMonRunGrd_rCluPedPrssMes;
extern boolean Ext_bMonRunORng_rCluPedPrssMes;
extern boolean Ext_bMonRunScg_rCluPedPrssMes;
extern boolean Ext_bMonRunScp_rCluPedPrssMes;
extern uint8 CLUPEDFREQACQ_u8CntFilt_1;
extern uint8 CLUPEDFREQACQ_u8CntFilt_2;
extern uint8 Ext_ctDftSftyScg_rCluPedPrssMes;
extern uint8 Ext_ctDftSftyScp_rCluPedPrssMes;
extern uint16 Clu_perRateCluPedPrssMes;
extern uint16 Clu_rCluPedPrssLnrMes;
extern uint16 Clu_rCluPedPrssLnrMesPrev;
extern uint16 Clu_rCluPedPrssMem;
extern uint16 Ext_rCluPedPrssMesPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CLUPEDFREQACQ_vidAcvCall(void);
void CLUPEDFREQACQ_vidCluPedAcq(void);
void CLUPEDFREQACQ_vidCluPedDiag(void);
void CLUPEDFREQACQ_vidCluPedLnr(void);
void CLUPEDFREQACQ_vidCluPedSel(void);
void CLUPEDFREQACQ_vidDiagFreq(void);
void CLUPEDFREQACQ_vidDiagGrad(void);
void CLUPEDFREQACQ_vidDiagnosticniv2(void);
void CLUPEDFREQACQ_vidGDUFreq(void);
void CLUPEDFREQACQ_vidGDUGrad(void);
void CLUPEDFREQACQ_vidInit(void);
void CLUPEDFREQACQ_vidOSCallAcv(void);


#endif /* CLUPEDFREQACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
