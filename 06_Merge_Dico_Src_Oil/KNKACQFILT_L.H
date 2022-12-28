/***************************************************************************
;**
;** FILE NAME      : KNKACQFILT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKACQFILT_L_H
#define KNKACQFILT_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNKACQFILT_NOKNKMESRAWTBLIDX_COLS      ( 4 )
#define KNKACQFILT_PRM_AGKNKMESWIN_COLS        ( 4 )
#define KNKACQFILT_PRM_AGKNKMESWINRAW_COLS     ( 4 )
#define KNKACQFILT_PRM_UKNKMESRAW_COLS         ( 2000 )
#define SOMME_RBL_COLS                         ( 16 )

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

extern const uint8  KNKACQFILT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean KNKACQFILT_bAcvCalSdlFastPrev;
extern boolean KnkRbl_bAcvCalSdlFast;
extern boolean KnkTreat_bInhRblAcq;
extern uint32 KnkAcqFilt_noKnkMesRawTblIdx[KNKACQFILT_NOKNKMESRAWTBLIDX_COLS];
extern uint32 somme_clq;
extern uint32 somme_rbl[SOMME_RBL_COLS];
extern sint8 KnkAcqFilt_FiltParam;
extern uint8 KnkAcqFilt_noKnkMesWin;
extern uint8 KnkAcqFilt_noSigConvGain;
extern uint8 KnkAcqFilt_noSigConvGainApp;
extern uint8 KnkAcqFilt_noSigConvGainReq;
extern uint8 KNKACQFILT_u8DebfencliquetisPrev;
extern uint8 KNKACQFILT_u8DurfencliquetisPrev;
extern sint16 KnkAcqFilt_prm_agKnkMesWinRaw[KNKACQFILT_PRM_AGKNKMESWINRAW_COLS];
extern uint16 Fin_fenetre_cliquetis;
extern uint16 Knk_OfsInjrNoiseKnk;
extern uint16 Knk_OfsPmpHPNoiseKnk;
extern uint16 KnkAcqFilt_agTDCOfs;
extern uint16 KnkAcqFilt_agWdWinFiltInit;
extern uint16 KnkAcqFilt_prm_agKnkMesWin[KNKACQFILT_PRM_AGKNKMESWIN_COLS];
extern uint16 KnkAcqFilt_prm_uKnkMesRaw[KNKACQFILT_PRM_UKNKMESRAW_COLS];
extern uint16 KnkAcqFilt_rSigConvGainApp;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKACQFILT_vidCheckCondition(void);
void KNKACQFILT_vidConfigParamInit(void);
void KNKACQFILT_vidDefKnkWindows(void);
void KNKACQFILT_vidFilterEnergyCalc(void);
void KNKACQFILT_vidInitializationRbl(void);
void KNKACQFILT_vidInitOutput(void);
void KNKACQFILT_vidInterfaceBSW(void);
void KNKACQFILT_vidKnkMesWin(void);
void KNKACQFILT_vidOfsInjrNKnkcalc(void);
void KNKACQFILT_vidOfsPmpHPNKnkcalc(void);
void KNKACQFILT_vidReadingKnkEnergy(void);
void KNKACQFILT_vidReadingRblEnergy(void);
void KNKACQFILT_vidReadKnkRblEnergy(void);
void KNKACQFILT_vidSigConvGainCalc(void);
void KNKACQFILT_vidSignalSampleFilter(void);


#endif /* KNKACQFILT_L_H */

/*-------------------------------- end of file -------------------------------*/
