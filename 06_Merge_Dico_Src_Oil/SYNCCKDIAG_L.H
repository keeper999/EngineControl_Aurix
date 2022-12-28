/***************************************************************************
;**
;** FILE NAME      : SYNCCKDIAG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef SYNCCKDIAG_L_H
#define SYNCCKDIAG_L_H

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

extern const uint8  SYNCCKDIAG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean Acq_crk_long_tooth_nok_upd_upvb0;
extern boolean Acq_crk_long_tooth_nok_upvb0;
extern boolean Acq_crk_no_gap_cond_dec_upvb0;
extern boolean Acq_crk_no_gap_cond_inc_upvb0;
extern boolean Acq_crk_no_long_tooth_upd_upvb0;
extern boolean Acq_crk_no_long_tooth_upvb0;
extern boolean Acq_crk_tooth_less_upd_upvb0;
extern boolean Acq_crk_tooth_less_upvb0;
extern boolean Acq_crk_tooth_more_upd_upvb0;
extern boolean Acq_crk_tooth_more_upvb0;
extern boolean Sync_bForcDwgMode;
extern boolean SYNCCKDIAG_bDgoCkSigPrev;
extern boolean SYNCCKDIAG_bSelectCkMode;
extern uint8 Sync_stCkMode;
extern uint8 Sync_stCkModeRead;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void SYNCCKDIAG_vidAcvDwgMode(void);
void SYNCCKDIAG_vidBackUpMode(void);
void SYNCCKDIAG_vidCkAcqVld(void);
void SYNCCKDIAG_vidCkStsAcq(void);
void SYNCCKDIAG_vidCrkDgnUpdateInReq(void);
void SYNCCKDIAG_vidCrkInvalTeethDiag(void);
void SYNCCKDIAG_vidCrkInvalToothDiag(void);
void SYNCCKDIAG_vidCrkLngLtoo1Diag(void);
void SYNCCKDIAG_vidCrkLngToothTmpDiag(void);
void SYNCCKDIAG_vidEventGeneration(void);
void SYNCCKDIAG_vidExCamSig(void);
void SYNCCKDIAG_vidInCamSig(void);
void SYNCCKDIAG_vidInitOutput(void);
void SYNCCKDIAG_vidInitSelectCkMode(void);
void SYNCCKDIAG_vidReadCkMode(void);
void SYNCCKDIAG_vidResetDiag(void);
void SYNCCKDIAG_vidSetEdgePos(void);


#endif /* SYNCCKDIAG_L_H */

/*-------------------------------- end of file -------------------------------*/
