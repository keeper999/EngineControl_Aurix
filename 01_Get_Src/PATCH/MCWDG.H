/***************************************************************************
;**
;** FILE NAME      : MCWDG.H
;**
;** FILE AUTHOR    : lthibau (VEES)
;**
;**************************************************************************/

#ifndef MCWDG_H
#define MCWDG_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "MCWDG_Cfg.h"
#include "MCWDG_Typ.h"
#include "STD_Types.h"
#include "type.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define MCWDG_bMCW_INHIBIT_ACTIVE         1
#define MCWDG_bMCW_INHIBIT_INACTIVE       0
#define MCWDG_u8MCP_OUT1                  1
#define MCWDG_u8MCP_OUT2                  2
#define MCWDG_u8MCW_INHIBITION_OUT1       1
#define MCWDG_u8MCW_INHIBITION_OUT2       2

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

extern uint8 MCWDG_u8McpInitSafetyResult;
extern uint8 MCWDG_u8McwInitSafetyResult;
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void MCWDG_vidDisable(void);
void MCWDG_vidEnable(void);
void MCWDG_vidFunctionalTestExchange(Std_ReturnType stdTestStatus);
void MCWDG_vidInit(void);
void MCWDG_vidItAcknowledgeByteMcw(void);
void MCWDG_vidItTimeoutSpiCom(void);
void MCWDG_vidMcwManagement(void);
void MCWDG_vidResumeSampleCheck(void);
void MCWDG_vidRx(void);
void MCWDG_vidStartInhibitState(uint8 u8McwInhPin);
void MCWDG_vidStopInhibitState(uint8 u8McwInhPin);
void MCWDG_vidSuspendSampleCheck(void);
void MCWDG_vidTx(void);
void MCWDG_vidWriteMcpFaultState(uint8 bfFaultMask);
void MCWDG_vidWritePrepInitStatus(MCWDG_tbfPrepInitStatus bfPrepInitStatus);
uint8 MCWDG_bfReadMcwFaultState(void);
boolean MCWDG_bMcpIsEnableAuthorized(uint8 u8McpOutput);
//boolean MCWDG_bReadInhibitState(uint8 u8McwInhPin);


#endif /* MCWDG_H */

/*-------------------------------- end of file -------------------------------*/
