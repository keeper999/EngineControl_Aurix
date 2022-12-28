/***************************************************************************
;**
;** FILE NAME      : STTMO2CLC_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef STTMO2CLC_L_H
#define STTMO2CLC_L_H

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

extern const uint8  STTMO2CLC_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eng_VoltDownLsHigh;
extern boolean Eng_VoltDownLsLow;
extern boolean STTMO2CLC_bMot_tournPrev;
extern uint16 Eng_mO2Cat_Err;
extern uint16 Eng_mO2Cat_Norm;
extern uint16 STTMO2CLC_u16VoltDownLsPrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void STTMO2CLC_vidAct_tens_sond_basse(void);
void STTMO2CLC_vidAct_tens_sond_haute(void);
void STTMO2CLC_vidCal_cond_tens_sonde(void);
void STTMO2CLC_vidCalcul_mO2_cata(void);
void STTMO2CLC_vidCalcul_mO2cat(void);
void STTMO2CLC_vidCalcul_mO2cat_final(void);
void STTMO2CLC_vidCompteur_TDC_STT(void);
void STTMO2CLC_vidDesac_tens_sond_bas(void);
void STTMO2CLC_vidDesac_tens_sond_hau(void);
void STTMO2CLC_vidInit(void);
void STTMO2CLC_vidInitOutput(void);
void STTMO2CLC_vidMasse_stockee_STT(void);
void STTMO2CLC_vidMoteur_non_tournant(void);
void STTMO2CLC_vidMoteur_tournant(void);


#endif /* STTMO2CLC_L_H */

/*-------------------------------- end of file -------------------------------*/
