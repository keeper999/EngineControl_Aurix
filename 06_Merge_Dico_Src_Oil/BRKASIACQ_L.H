/***************************************************************************
;**
;** FILE NAME      : BRKASIACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKASIACQ_L_H
#define BRKASIACQ_L_H

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

extern const uint8  BRKASIACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean BRKASIACQ_bFilSig_1;
extern boolean BRKASIACQ_bFilSig_2;
extern boolean BRKASIACQ_bScgrpBrkAsi;
extern boolean BRKASIACQ_bScprpBrkAsi;
extern boolean Ext_bDgoGrd_pBrkAsi;
extern boolean Ext_bDgoScg_pBrkAsi;
extern boolean Ext_bDgoScp_pBrkAsi;
extern boolean Ext_bMonRunGrd_pBrkAsi;
extern boolean Ext_bMonRunScg_pBrkAsi;
extern boolean Ext_bMonRunScp_pBrkAsi;
extern uint32 BRKASIACQ_u32ExtBrkAsiMem;
extern uint8 AirPres_ctDftSftyScg_pBrkAsi;
extern uint8 AirPres_ctDftSftyScp_pBrkAsi;
extern uint8 BRKASIACQ_u8CntFilt_1;
extern uint8 BRKASIACQ_u8CntFilt_2;
extern uint8 Ext_tDlyDgoGrd_pBrkAsi;
extern uint16 BRKASIACQ_u16ExtRBrkAsiPrev;
extern uint16 Ext_pBrkAsiRaw;
extern uint16 Ext_pbrkAsiSat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BRKASIACQ_vidBrkAsiAcq(void);
void BRKASIACQ_vidBrkAsiAcqBrut(void);
void BRKASIACQ_vidCallMng(void);
void BRKASIACQ_vidGrdDiagnostic(void);
void BRKASIACQ_vidInitialization(void);
void BRKASIACQ_vidInitOutput(void);
void BRKASIACQ_vidMstrVacSensorDiag(void);
void BRKASIACQ_vidScDiagnostic(void);
void BRKASIACQ_vidSftLvl2(void);


#endif /* BRKASIACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
