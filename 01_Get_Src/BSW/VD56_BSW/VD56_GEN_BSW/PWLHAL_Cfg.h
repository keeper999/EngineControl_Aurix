/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL_Cfg.h                                            */
/* !Description     : PWLHAL configuration                                    */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192563.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
 
#ifndef PWLHAL_CFG_H
#define PWLHAL_CFG_H

#include "Std_Types.h"
#include "DEVHAL.h"
#include "DGOHAL.h"
#include "Dio.h"
#include "Gpt.h"
#include "Os.h"
#include "TLE8718_Gateway.h"
#include "Wdg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !Comment : DIO channel that commands the Main Relay                        */
#define PWLHAL_udtPWL_MAIN_RLY                 DioConf_DioChannel_M_MAIN_RELAY

/* !Comment : Configurable Ignition key name                                  */
#define PWLHAL_udtIGK_DIN                      DioConf_DioChannel_M_STARTUP_IGK

/* !Comment : Configurable Main Relay DGOHAL name                             */
#define PWLHAL_udtMAIN_RELAY_DGO_CH            DGOHAL_udtPWL_MAIN_RELAY

/* !MComment: Arguments used by dodelay (with timer) with timer resol 160 ns */
#define ONE_USEC_TIMER                          6u
#define TWO_USEC_TIMER                          12u
#define THREE_USEC_TIMER                        19u
#define FOUR_USEC_TIMER                         25u
#define FIVE_USEC_TIMER                         31u
#define SIX_USEC_TIMER                          37u
#define TEN_USEC_TIMER                          62u
#define THIRTY_USEC_TIMER                       187u
#define FIFTY_USEC_TIMER                        312u
#define ONE_100_USEC_TIMER                      625u
#define ONE_150_USEC_TIMER                      937u
#define TWO_100_USEC_TIMER                      1250u
#define ONE_MSEC_TIMER                          6250u
#define TEN_MSEC_TIMER                          62500u

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/* !Description : Starting Timer                                              */
/*                                                                            */
/* !LastAuthor : M. Sabry                                                     */
/******************************************************************************/
#define PWLHAL_vidSTART_DELAY_TIMER() \
do \
{ \
   Gpt_StartTimer(GptConf_GptChannel_PWL_TIMER, 0xFFFFU); \
} \
while (0u)

/******************************************************************************/
/*                                                                            */
/* !Description : Waiting loop using timer                                    */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#define PWLHAL_vidPERFORM_DELAY( \
\
   Delay         /* !Comment : Desired time of the waiting loop             */ \
                 /* !Range   : ONE_USEC, TWO_USEC, THREE_USEC, FOUR_USEC,   */ \
                 /*            FIVE_USEC, SIX_USEC, TEN_USEC, THIRTY_USEC,  */ \
                 /*            FIFTY_USEC, ONE_100_USEC, ONE_150_USEC,      */ \
                 /*            TWO_100_USEC, ONE_MSEC, TEN_MSEC             */ \
) \
do \
{ \
   uint16 u16LocalDelay; \
  \
  \
   u16LocalDelay = (uint16)Gpt_GetTimeElapsed(GptConf_GptChannel_PWL_TIMER); \
   while( (uint16)( Gpt_GetTimeElapsed(GptConf_GptChannel_PWL_TIMER) \
                  - u16LocalDelay) \
        < (uint16)(Delay##_TIMER)){;} \
} \
while (0u)

/******************************************************************************/
/*                                                                            */
/* !Description : Inform DEVAID that the ECU is going to shutdown             */
/*                                                                            */
/* !LastAuthor  : ASAL                                                        */
/******************************************************************************/
#define PWLHAL_vidDEVAID_POWER_DOWN() \
do \
{ \
   DEVHAL_vidTrapDevaidPowerDown(DEVHAL_u8TRAP_PWD_END); \
} \
while (0u)

/******************************************************************************/
/*                                                                            */
/* !Description : Waits 10ms                                                  */
/*                                                                            */
/* !LastAuthor  : H. Saidi                                                    */
/******************************************************************************/
#define PWLHAL_vidDELAY_10MS() PWLHAL_vidPERFORM_DELAY(TEN_MSEC);

/******************************************************************************/
/* !FuncName    : PWLHAL_vidREFRESH_WTDG                                      */
/* !Description : Refresh the watchdog timer.                                 */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define PWLHAL_vidREFRESH_WTDG() \
do \
{ \
   Wdg_vidRefreshWatchdog(); \
   /* Core 1 WDT can be refreshed only by Core 1 (performed using Taks Call   */ \
   ActivateTask(OSTSK_S_WTDG_REFRESH_WATCHDOG_ASW); \
   /* dbg: add refresh of external watchdog WTDG_vidEXT(); */ \
} \
while (0u)

/******************************************************************************/
/*                                                                            */
/* !Description : Write actuators power relay                                 */
/*                                                                            */
/* !LastAuthor : M. Sabry                                                     */
/******************************************************************************/
#define PWLHAL_vidWRITE_POWER_RELAY( \
State            /* !Comment : Desired command state                        */ \
                 /* !Range   : STD_OFF, STD_ON                              */ \
) \
do \
{ \
   TLE8718_vidDioWrite_INST1_OUT11(State); \
} \
while (0u)

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PWLHAL_START_SEC_CODE
#include "PWLHAL_MemMap.h"

/******************************************************************************/
/*                                                                            */
/* !Description : This function is used to disable all the actuators linked   */
/*                to the actuator relay or main relay upon shutdown.          */
/*                                                                            */
/* !LastAuthor  : M. Badran                                                   */
/******************************************************************************/
extern void PWLHAL_vidDisableActuators(void);

#define PWLHAL_STOP_SEC_CODE
#include "PWLHAL_MemMap.h"

#endif /* PWLHAL_CFG_H  */
/*--------------------------------------------------- end of file ----------------------------------------------------*/
