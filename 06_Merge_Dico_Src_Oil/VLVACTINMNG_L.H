/***************************************************************************
;**
;** FILE NAME      : VLVACTINMNG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINMNG_L_H
#define VLVACTINMNG_L_H

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

/* enum st74 */
#define VLVACT_INIT                       0
#define VLVACT_LRN                        1
#define VLVACT_SERVO                      2
#define VLVACT_CLEAN                      3
#define VLVACT_DFT                        4
#define VLVACT_UNLOCK                     5
/*extern uint8 VlvAct_InMngSt;*/

/* enum st43 */
#define VLVACT_IN_UNLOCK_IDLE             0
#define VLVACT_IN_UNLOCK_INIT             1
#define VLVACT_IN_UNLOCK_SLOPE            2
#define VLVACT_IN_UNLOCK_STAB             3
#define VLVACT_IN_UNLOCK_END              4
/*extern uint8 VlvAct_InUnlckStrSt;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  VLVACTINMNG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 VlvAct_InMngSt;
extern uint8 VlvAct_InUnlckStrSt;
extern boolean VlvAct_bInInUnlckStrEndIdc;
extern boolean VlvAct_bInMngClnStEna;
extern boolean VlvAct_bInMngInitStEna;
extern boolean VlvAct_bInMngUnlckStEna;
extern boolean VlvAct_bInUnlckEna;
extern boolean VLVACTINMNG_bagInAcvSpFuncIntThd;
extern boolean VLVACTINMNG_bAgInAcvUnlckPosnThd;
extern boolean VLVACTINMNG_bInLrnHyst01;
extern boolean VLVACTINMNG_bInLrnHyst02;
extern boolean VLVACTINMNG_bInLrnHyst03;
extern boolean VLVACTINMNG_bInLrnHyst04;
extern boolean VLVACTINMNG_bInLrnHyst05;
extern boolean VLVACTINMNG_bInLrnHyst06;
extern boolean VLVACTINMNG_bInLrnHyst07;
extern boolean VLVACTINMNG_bInLrnHyst08;
extern boolean VLVACTINMNG_bInServoHyst01;
extern boolean VLVACTINMNG_bInServoHyst02;
extern boolean VLVACTINMNG_bInServoHyst03;
extern boolean VLVACTINMNG_bNEngInUnlckThd;
extern boolean VLVACTINMNG_bOilPresPrev;
extern boolean VLVACTINMNG_bTimeout1;
extern boolean VLVACTINMNG_bTimeout2;
extern boolean VLVACTINMNG_bTimeout3;
extern boolean VLVACTINMNG_bTimeout4;
extern boolean VLVACTINMNG_bTimeout5;
extern boolean VLVACTINMNG_bTimer1Input;
extern boolean VLVACTINMNG_bTimer2Input;
extern boolean VLVACTINMNG_bTOilInUnlckThd;
extern boolean VLVACTINMNG_bVehicleStatePrev;
extern uint8 VlvAct_noInUnlckStr;
extern uint8 VlvAct_noInUnlckStrThd;
extern uint8 VlvAct_tiInUnlck;
extern uint8 VlvAct_tiInUnlckIni;
extern uint8 VlvAct_tiInUnlckSlop;
extern uint8 VlvAct_tiInUnlckStab;
extern uint8 VLVACTINMNG_u8Tempo1;
extern uint8 VLVACTINMNG_u8Tempo2;
extern uint8 VLVACTINMNG_u8Tempo3;
extern uint8 VLVACTINMNG_u8Tempo4;
extern uint8 VLVACTINMNG_u8VehActStatPrev;
extern uint16 VlvAct_InUnlckCmd;
extern uint16 VlvAct_InUnlckCmdIni;
extern uint16 VlvAct_InUnlckCmdStab;
extern uint16 VlvAct_InUnlckSlop1;
extern uint16 VlvAct_InUnlckSlop2;
extern uint16 VLVACTINMNG_u16Tempo5;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VLVACTINMNG_vidClnStEnaCdn(void);
void VLVACTINMNG_vidEngStopAuth(void);
void VLVACTINMNG_vidInitOutput(void);
void VLVACTINMNG_vidInitStEnaCdn(void);
void VLVACTINMNG_vidLrnStEnaCdn(void);
void VLVACTINMNG_vidMngStCmd(void);
void VLVACTINMNG_vidServoStEnaCdn(void);
void VLVACTINMNG_vidStMng(void);
void VLVACTINMNG_vidTimer1(void);
void VLVACTINMNG_vidTimer2(void);
void VLVACTINMNG_vidUnlckStr(void);
void VLVACTINMNG_vidUnlockStrategy(void);


#endif /* VLVACTINMNG_L_H */

/*-------------------------------- end of file -------------------------------*/
