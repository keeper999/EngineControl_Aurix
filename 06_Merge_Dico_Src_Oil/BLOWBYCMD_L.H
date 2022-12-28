/***************************************************************************
;**
;** FILE NAME      : BLOWBYCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BLOWBYCMD_L_H
#define BLOWBYCMD_L_H

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

/* enum st125 */
#define HEATER_INIT                       0
#define HEATER_INACTIF                    1
#define HEATER_ACTIF_MOTEUR_ARRETE        2
#define HEATER_ACTIF_MOTEUR_TOURNANT      3
/*extern uint8 BlowByHw_stCtl;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  BLOWBYCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 BlowByHw_stCtl;
extern boolean BlowBy2Hw_bReq;
extern boolean OilSys_bDgoOc_BlowBy1;
extern boolean OilSys_bDgoOc_BlowBy2;
extern boolean OilSys_bDgoScg_BlowBy1;
extern boolean OilSys_bDgoScg_BlowBy2;
extern boolean OilSys_bDgoScp_BlowBy1;
extern boolean OilSys_bDgoScp_BlowBy2;
extern boolean OilSys_bMonRunOc_BlowBy1;
extern boolean OilSys_bMonRunOc_BlowBy2;
extern boolean OilSys_bMonRunScg_BlowBy1;
extern boolean OilSys_bMonRunScg_BlowBy2;
extern boolean OilSys_bMonRunScp_BlowBy1;
extern boolean OilSys_bMonRunScp_BlowBy2;
extern uint16 BlowByHw_tiHeat;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BLOWBYCMD_vidBlowBy1Cmd(void);
void BLOWBYCMD_vidBlowBy2Cmd(void);
void BLOWBYCMD_vidDiagBlowBy1(void);
void BLOWBYCMD_vidDiagBlowBy2(void);
void BLOWBYCMD_vidHeaterCmd(void);
void BLOWBYCMD_vidInit(void);


#endif /* BLOWBYCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
