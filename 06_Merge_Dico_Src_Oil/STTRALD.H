/***************************************************************************
;**
;** FILE NAME      : STTRALD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef STTRALD_H
#define STTRALD_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define Ext_stAcce_SC                     64
#define Ext_stDece_SC                     32
#define Ext_stStab_SC                     128
#define INM_MFTOTEXCOR_A_COLS                  ( 9 )
#define INM_STABTOTRANTHD_T_COLS               ( 9 )
#define INM_TRANTOSTABTHD_T_COLS               ( 9 )

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

extern const uint8  InM_StabToTranThd_T[INM_STABTOTRANTHD_T_COLS];
extern const uint8  InM_TranToStabThd_T[INM_TRANTOSTABTHD_T_COLS];
extern const uint16  InM_mfTotExCor_A[INM_MFTOTEXCOR_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Eng_bAccEng;
extern uint8 InM_stTraLd;
extern sint16 InM_mfDif_stTraLd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void InM_SdlFast_stTraLd(void);
void STTRALD_vidEntryInit(void);


#endif /* STTRALD_H */

/*-------------------------------- end of file -------------------------------*/
