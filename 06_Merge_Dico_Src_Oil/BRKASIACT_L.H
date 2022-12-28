/***************************************************************************
;**
;** FILE NAME      : BRKASIACT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BRKASIACT_L_H
#define BRKASIACT_L_H

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

extern const uint8  BRKASIACT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean BRKASIACT_bTmrOut;
extern boolean BRKASIACT_bTqSysbDeceAcvPrev;
extern boolean TqSys_bAcvBrkAsiImdtStra;
extern boolean TqSys_bBrkAsiAcv;
extern boolean TqSys_bBrkAsiPres_MP;
extern boolean TqSys_bBrkAsiTq_MP;
extern boolean TqSys_bBrkAsiVeh;
extern boolean TqSys_bTqACCnd;
extern boolean TqSys_bTqAltCnd;
extern uint16 BRKASIACT_u16Cnt;
extern uint16 BRKASIACT_u16TqSumLossCmp;
extern uint16 TqSys_tiBrkAsiACMax;
extern uint16 TqSys_tiBrkAsiAltMax;
extern uint16 TqSys_tiInhACBrkAsi;
extern uint16 TqSys_tiInhACWait;
extern uint16 TqSys_tiInhACWaitMax;
extern uint16 TqSys_tiRlsAltBrkAsi;
extern uint16 TqSys_tiRlsAltWait;
extern uint16 TqSys_tiRlsAltWaitMax;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BRKASIACT_vidActiv_Cond_Couple(void);
void BRKASIACT_vidActiv_Cond_Veh(void);
void BRKASIACT_vidAssistAC_ON(void);
void BRKASIACT_vidAssistALT_AC_ON(void);
void BRKASIACT_vidAssistALT_OFF_AC_ON(void);
void BRKASIACT_vidAssistALT_ON(void);
void BRKASIACT_vidAssistALT_ON_AC_OFF(void);
void BRKASIACT_vidAssistOFF(void);
void BRKASIACT_vidInitOutput(void);
void BRKASIACT_vidSF_supervise_BrkAsi(void);
void BRKASIACT_vidSuperviseur(void);


#endif /* BRKASIACT_L_H */

/*-------------------------------- end of file -------------------------------*/
