/***************************************************************************
;**
;** FILE NAME      : TQESTMAX_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TQESTMAX_L_H
#define TQESTMAX_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQESTMAX_AS16TQEFCAIRESTIMRAW_COLS     ( 16 )

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

extern const uint8  TQESTMAX_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoPt_bAcvTqMaxEstimTq_MP;
extern boolean CoPt_bASR;
extern boolean CoPt_bAuthTqMaxEstimSIP;
extern boolean TQESTMAX_bRSOutput;
extern uint8 CoPt_facTqMaxEstim;
extern uint8 TQESTMAX_u8Cha_stTqReqPrev;
extern uint8 TQESTMAX_u8CoPfacTqMaxEstimPrev2;
extern uint8 TQESTMAX_u8CoPtfacTqMaxEstimPrev;
extern sint16 CoPt_stepFacTqMaxEstim_MP;
extern sint16 CoPt_tqAirLimEstim;
extern sint16 CoPt_tqEfcAirEstimDly;
extern sint16 CoPt_tqEfcAirEstimRaw;
extern sint16 CoPt_tqEfcAirMaxFil;
extern sint16 CoPt_tqEfcAirMaxFil1;
extern sint16 TQESTMAX_as16TqEfcAirEstimRaw[TQESTMAX_AS16TQEFCAIRESTIMRAW_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void TQESTMAX_vidActivation_Filtrage(void);
void TQESTMAX_vidAcvFiltrageProc(void);
void TQESTMAX_vidAcvFiltrageSIP_ESP(void);
void TQESTMAX_vidCalcul_cpl_pot_brut(void);
void TQESTMAX_vidCalcul_gain_filtrage(void);
void TQESTMAX_vidCalculCplPotDephase(void);
void TQESTMAX_vidCalculCplPotEstime(void);
void TQESTMAX_vidCalculCplPotFiltre(void);
void TQESTMAX_vidInitOutput(void);
void TQESTMAX_vidModele_cpl_pot(void);


#endif /* TQESTMAX_L_H */

/*-------------------------------- end of file -------------------------------*/
