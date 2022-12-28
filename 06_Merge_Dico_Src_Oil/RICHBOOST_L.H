/***************************************************************************
;**
;** FILE NAME      : RICHBOOST_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef RICHBOOST_L_H
#define RICHBOOST_L_H

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

extern const uint8  RICHBOOST_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean RICHBOOST_bAcvVehSpdCtlLimPrev;
extern boolean RICHBOOST_bOvbAuthRawPrev;
extern boolean RICHBOOST_bRichAuthRawPrev;
extern boolean RICHBOOST_bStrt;
extern boolean TqSys_bAcvPrfDly;
extern boolean TqSys_bOvbAuthAccPCnd_MP;
extern boolean TqSys_bOvbAuthCnd;
extern boolean TqSys_bOvbAuthRaw;
extern boolean TqSys_bOvbAuthTqCnd_MP;
extern boolean TqSys_bRichAuthAccPCnd_MP;
extern boolean TqSys_bRichAuthCnd;
extern boolean TqSys_bRichAuthRaw;
extern boolean TqSys_bRichAuthTqCnd_MP;
extern boolean TqSys_bRstOvbCnd_MP;
extern boolean TqSys_bRstOvbSpdLimCnd_MP;
extern boolean TqSys_bRstRichCnd_MP;
extern boolean TqSys_bRstRichSpdLimCnd_MP;
extern uint16 RICHBOOST_u16OvbTurnOffDlyCntr;
extern uint16 RICHBOOST_u16OvbTurnOnDlyCntr;
extern uint16 RICHBOOST_u16RichTurnOffDlyCntr;
extern uint16 RICHBOOST_u16RichTurnOnDlyCntr;
extern uint16 RICHBOOST_u16TmrRstOut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void RICHBOOST_vidCond_Act_OvbPerfo(void);
void RICHBOOST_vidCond_act_Richesse(void);
void RICHBOOST_vidCond_Reset_Enrich(void);
void RICHBOOST_vidCondition_Reset(void);
void RICHBOOST_vidDemandePerfoOverbst(void);
void RICHBOOST_vidInitOutput(void);
void RICHBOOST_vidSyn_Bes_Act_Enrich(void);
void RICHBOOST_vidSyn_Bes_Act_Ovboost(void);
void RICHBOOST_vidSyn_tempo_bes_enrch(void);
void RICHBOOST_vidTempo_glob_hors_LVV(void);
void RICHBOOST_vidTemporisations(void);


#endif /* RICHBOOST_L_H */

/*-------------------------------- end of file -------------------------------*/
