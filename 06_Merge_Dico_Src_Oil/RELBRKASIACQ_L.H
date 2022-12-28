/***************************************************************************
;**
;** FILE NAME      : RELBRKASIACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RELBRKASIACQ_L_H
#define RELBRKASIACQ_L_H

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

extern const uint8  RELBRKASIACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoGrd_pRelBrkAsi;
extern boolean Ext_bDgoScg_pRelBrkAsi;
extern boolean Ext_bDgoScp_pRelBrkAsi;
extern boolean Ext_bMonRunGrd_pRelBrkAsi;
extern boolean Ext_bMonRunScg_pRelBrkAsi;
extern boolean Ext_bMonRunScp_pRelBrkAsi;
extern boolean RELBRKASIACQ_bFilSig_1;
extern boolean RELBRKASIACQ_bFilSig_2;
extern boolean RELBRKASIACQ_bScg_pRelBrkAsi;
extern boolean RELBRKASIACQ_bScp_pRelBrkAsi;
extern uint32 RELBRKASIACQ_u32OutFilterMem;
extern uint8 AirPres_ctAcvGrdDiag;
extern uint8 AirPres_ctDftSftyScg_pRelBrkAsi;
extern uint8 AirPres_ctDftSftyScp_pRelBrkAsi;
extern uint8 Ext_pRelBrkAsiLnr;
extern uint8 Ext_pRelBrkAsiMem;
extern uint8 RELBRKASIACQ_u8CntFilt_1;
extern uint8 RELBRKASIACQ_u8CntFilt_2;
extern uint16 Ext_uRelBrkAsi;
extern uint16 Ext_uRelBrkAsiFil;
extern uint16 RELBRKASIACQ_u16ExtReBrAsiPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RELBRKASIACQ_vidAcqusition(void);
void RELBRKASIACQ_vidCalc(void);
void RELBRKASIACQ_vidDiagnosis(void);
void RELBRKASIACQ_vidFiltering(void);
void RELBRKASIACQ_vidGrdDiag(void);
void RELBRKASIACQ_vidInit(void);
void RELBRKASIACQ_VidInitOutput(void);
void RELBRKASIACQ_vidLinearization(void);
void RELBRKASIACQ_vidScpScgDiag(void);
void RELBRKASIACQ_vidSelection(void);
void RELBRKASIACQ_vidSftLvl2(void);


#endif /* RELBRKASIACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
