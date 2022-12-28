/***************************************************************************
;**
;** FILE NAME      : OBDSRV06_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OBDSRV06_L_H
#define OBDSRV06_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GD_STEVENTSTATUS_PREV_LNS             ( 972 )

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

extern const uint8  OBDSRV06_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bCondDiag_Cat;
extern boolean Ext_bCondDiag_DsHeat;
extern boolean Ext_bCondDiag_DsPlausFco;
extern boolean Ext_bCondDiag_DsPlausFld;
extern boolean Ext_bCondDiag_Misf;
extern boolean Ext_bCondDiag_OxySensPerd;
extern boolean Ext_bCondDiag_SigGrdDiag;
extern boolean Ext_bCondDiag_uDsLs;
extern boolean Ext_bCondDiag_UsHeat;
extern boolean Ext_bCondDiag_UsPlausFco;
extern boolean Ext_bCondDiag_UsPlausFld;
extern boolean Ext_bCondDiag_uUpLs;
extern uint8 GD_stEventStatus_prev[GD_STEVENTSTATUS_PREV_LNS];
extern uint16 SenO2Ds_SigGrd_Obd6Mod;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OBDSRV06_EveRst(void);
void OBDSRV06_EveRstDft(void);
void OBDSRV06_pwrl(void);
void OBDSRV06_SdlMid(void);


#endif /* OBDSRV06_L_H */

/*-------------------------------- end of file -------------------------------*/
