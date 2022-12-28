/***************************************************************************
;**
;** FILE NAME      : VLVACTEXMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXMNG_L_H
#define VLVACTEXMNG_L_H

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

/* enum st76 */
#define VLVACTEXMNG_INIT                  0
#define VLVACTEXMNG_LRN                   1
#define VLVACTEXMNG_SERVO                 2
#define VLVACTEXMNG_CLEAN                 3
#define VLVACTEXMNG_DFT                   4
#define VLVACTEXMNG_UNLOCK                5
/*extern uint8 VlvAct_ExMngSt;*/

/* enum st46 */
#define VLVACT_EX_UNLOCK_IDLE             0
#define VLVACT_EX_UNLOCK_INIT             1
#define VLVACT_EX_UNLOCK_SLOPE            2
#define VLVACT_EX_UNLOCK_STAB             3
#define VLVACT_EX_UNLOCK_END              4
/*extern uint8 VlvAct_ExUnlckStrSt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  VLVACTEXMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 VlvAct_ExMngSt;
extern uint8 VlvAct_ExUnlckStrSt;
extern boolean VlvAct_bExMngClnStEna;
extern boolean VlvAct_bExMngInitStEna;
extern boolean VlvAct_bExMngUnlckStEna;
extern boolean VlvAct_bExUnlckEna;
extern boolean VlvAct_bExUnlckStrEndIdc;
extern boolean VLVACTEXMNG_bAgExAcvSpFuncIntThd;
extern boolean VLVACTEXMNG_bAgExAcvUnlckPosnThd;
extern boolean VLVACTEXMNG_bExLrnHyst01;
extern boolean VLVACTEXMNG_bExLrnHyst02;
extern boolean VLVACTEXMNG_bExLrnHyst03;
extern boolean VLVACTEXMNG_bExLrnHyst04;
extern boolean VLVACTEXMNG_bExLrnHyst05;
extern boolean VLVACTEXMNG_bExLrnHyst06;
extern boolean VLVACTEXMNG_bExLrnHyst07;
extern boolean VLVACTEXMNG_bExLrnHyst08;
extern boolean VLVACTEXMNG_bExServoHyst01;
extern boolean VLVACTEXMNG_bExServoHyst02;
extern boolean VLVACTEXMNG_bExServoHyst03;
extern boolean VLVACTEXMNG_bNEngExUnlckThd;
extern boolean VLVACTEXMNG_bOilPresPrev;
extern boolean VLVACTEXMNG_bTimeout1;
extern boolean VLVACTEXMNG_bTimeout2;
extern boolean VLVACTEXMNG_bTimeout3;
extern boolean VLVACTEXMNG_bTimeout4;
extern boolean VLVACTEXMNG_bTimeout5;
extern boolean VLVACTEXMNG_bTimer1Input;
extern boolean VLVACTEXMNG_bTimer2Input;
extern boolean VLVACTEXMNG_bTOilExUnlckThd;
extern boolean VLVACTEXMNG_bVehicleStatePrev;
extern uint8 VlvAct_noExUnlckStr;
extern uint8 VlvAct_noExUnlckStrThd;
extern uint8 VlvAct_tiExUnlck;
extern uint8 VlvAct_tiExUnlckIni;
extern uint8 VlvAct_tiExUnlckSlop;
extern uint8 VlvAct_tiExUnlckStab;
extern uint8 VLVACTEXMNG_u8Tempo1;
extern uint8 VLVACTEXMNG_u8Tempo2;
extern uint8 VLVACTEXMNG_u8Tempo3;
extern uint8 VLVACTEXMNG_u8Tempo4;
extern uint8 VLVACTEXMNG_u8VehActStatPrev;
extern uint16 VlvAct_ExUnlckCmd;
extern uint16 VlvAct_ExUnlckCmdIni;
extern uint16 VlvAct_ExUnlckCmdStab;
extern uint16 VlvAct_ExUnlckSlop1;
extern uint16 VlvAct_ExUnlckSlop2;
extern uint16 VLVACTEXMNG_u16ExMngStCmdPrev;
extern uint16 VLVACTEXMNG_u16Tempo5;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTEXMNG_vidClnStEnaCdn(void);
void VLVACTEXMNG_vidEngStopAuth(void);
void VLVACTEXMNG_vidInitOutput(void);
void VLVACTEXMNG_vidInitStEnaCdn(void);
void VLVACTEXMNG_vidLrnStEnaCdn(void);
void VLVACTEXMNG_vidMngStCmd(void);
void VLVACTEXMNG_vidServoStEnaCdn(void);
void VLVACTEXMNG_vidStMng(void);
void VLVACTEXMNG_vidTimer1(void);
void VLVACTEXMNG_vidTimer2(void);
void VLVACTEXMNG_vidUnlckStr(void);
void VLVACTEXMNG_vidUnlockStrategy(void);


#endif /* VLVACTEXMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
