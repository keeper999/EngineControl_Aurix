/***************************************************************************
;**
;** FILE NAME      : COHCAN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef COHCAN_L_H
#define COHCAN_L_H

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

extern const uint8  COHCAN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean COHCAN_bAC_bACClu_prev;
extern boolean COHCAN_bTimeOut;
extern boolean COHCAN_bTimerInit_prev;
extern boolean Ext_bDgoChkBattSys_iBattMes;
extern boolean Ext_bDgoChkBattSys_tBattMes;
extern boolean Ext_bDgoChkBattSys_uBattClc;
extern boolean Ext_bDgoCoh_bModSptReq;
extern boolean Ext_bDgoCoh_stCluAC;
extern boolean Ext_bDgoCoh_stPwrAC;
extern boolean Ext_bDgoCohBit2_stDftOBD;
extern boolean Ext_bDgoCohBit3_stDftOBD;
extern boolean Ext_bDgoCohBit4_stDftOBD;
extern boolean Ext_bDgoCohBit7_stDftOBD;
extern boolean Ext_bDgoStFuLvlDft;
extern boolean Ext_bMonRunChkBattSys;
extern boolean Ext_bMonRunCoh_bModSptReq;
extern boolean Ext_bMonRunCoh_stCluAC;
extern boolean Ext_bMonRunCoh_stDftOBD;
extern boolean Ext_bMonRunStFuLvlDft;
extern uint8 Ext_tiACClu;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void COHCAN_vidDiagBattSys(void);
void COHCAN_vidDiagChkBattSys(void);
void COHCAN_vidDiagCluAC(void);
void COHCAN_vidDiagFuLvlDft(void);
void COHCAN_vidDiagModSpd_FuLvl(void);
void COHCAN_vidDiagModSptReq(void);
void COHCAN_vidDiagOBD1(void);
void COHCAN_vidDiagOBD2(void);
void COHCAN_vidDiagStCluAC(void);
void COHCAN_vidInitOutput(void);
void COHCAN_vidWindowChkBattSys(void);
void COHCAN_vidWindowCluAC(void);
void COHCAN_vidWindowModSpt_FuLvl(void);
void COHCAN_vidWindowOBD(void);


#endif /* COHCAN_L_H */

/*-------------------------------- end of file -------------------------------*/
