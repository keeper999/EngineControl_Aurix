/***************************************************************************
;**
;** FILE NAME      : ENGRUNST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGRUNST_L_H
#define ENGRUNST_L_H

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

extern const uint8  ENGRUNST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean ENGRUNST_Srv_bByCnOvrNEngMx_prev;
extern boolean Engs_full_load_entry_delay_cond;
extern boolean Engs_full_load_entry_with_delay;
extern boolean EngSt_bDgoRedESLim;
extern boolean EngSt_bEntryOVERSPEED_FCO;
extern boolean EngSt_bMonRunRedESLim;
extern boolean ESLim_bAcvRedESLimProtMec;
extern boolean ESLim_bAcvRedESLimProtMecKOn;
extern boolean Fco_main_conditions_ok;
extern boolean Fco_temp_cata_ok;
extern uint8 EngSt_EngSpdLimThd;
extern uint8 Full_load_pedale;
extern uint8 Full_load_throttle;
extern uint16 Engs_full_load_after_crank_count;
extern uint16 Engs_full_load_entry_count;
extern uint16 EngSt_ctOverSpdFCO;
extern uint16 ESLim_tiCntOverNEngMaxTmp;
extern uint16 Esp_cut_off_allowed_count;
extern uint16 Pl_fco_entry_delay_timeout;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ENGRUNST_vidCutOffInputMngt(void);
void ENGRUNST_vidDelayTimeout(void);
void ENGRUNST_vidDiag(void);
void ENGRUNST_vidEngrunst(void);
void ENGRUNST_vidEngrunStInterface(void);
void ENGRUNST_vidFcoMainConditions(void);
void ENGRUNST_vidFullLoadEntryDelay(void);
void ENGRUNST_vidInit(void);
void ENGRUNST_vidInitOutput(void);
void ENGRUNST_vidKeyOnCalc(void);
void ENGRUNST_vidOverpeedFcoCondEntry(void);
void ENGRUNST_vidRstAcvTrqLim(void);


#endif /* ENGRUNST_L_H */

/*-------------------------------- end of file -------------------------------*/
