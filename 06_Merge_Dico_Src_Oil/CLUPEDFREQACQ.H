/***************************************************************************
;**
;** FILE NAME      : CLUPEDFREQACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLUPEDFREQACQ_H
#define CLUPEDFREQACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CLU_POSPED_MAP_COLS                    ( 2 )
#define CLU_RCO_BKPT_COLS                      ( 2 )

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

extern const uint8  Clu_nDecCpt_ScgPrssMes_C;
extern const uint8  Clu_nDecCpt_ScpPrssMes_C;
extern const uint8  Clu_nDownTranThd_ScgPrssMes_C;
extern const uint8  Clu_nDownTranThd_ScpPrssMes_C;
extern const uint8  Clu_nInitCpt_ScgPrssMes_C;
extern const uint8  Clu_nInitCpt_ScpPrssMes_C;
extern const uint8  Clu_nUpTranThd_ScgPrssMes_C;
extern const uint8  Clu_nUpTranThd_ScpPrssMes_C;
extern const uint16  Clu_FEmbFreq_Max_C;
extern const uint16  Clu_FEmbFreq_Min_C;
extern const uint16  Clu_GradEmbFreqCrois_C;
extern const uint16  Clu_GradEmbFreqDecrois_C;
extern const uint16  Clu_PosPed_Map[CLU_POSPED_MAP_COLS];
extern const uint16  Clu_rCluPedPrssMesFault_C;
extern const uint16  Clu_Rco_Bkpt[CLU_RCO_BKPT_COLS];
extern const uint16  Clu_RcoEmbFreq_Max_C;
extern const uint16  Clu_RcoEmbFreq_Min_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDftSftyScg_rCluPedPrssMes;
extern boolean Ext_bDftSftyScp_rCluPedPrssMes;
extern uint16 Ext_rCluPedPrssBrutMes;
extern uint16 Ext_rCluPedPrssMes;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Clu_EveRst_CluPedFreqAcq(void);
void Clu_SdlFast_CluPedFreqAcq(void);
void Clu_SdlSfty_rCluPedPrssMes(void);


#endif /* CLUPEDFREQACQ_H */

/*-------------------------------- end of file -------------------------------*/
