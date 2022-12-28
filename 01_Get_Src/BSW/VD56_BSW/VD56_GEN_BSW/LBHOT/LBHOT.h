/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : LBHOT                                                   */
/* !Description     : Oxygen (Lambda) Sensor Heating management               */
/*                                                                            */
/* !File            : LBHOT.h                                                 */
/* !Description     : LBHOT's Public Header                                   */
/*                                                                            */
/* !Reference       : V03 NT 06 03885                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A36801.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/


#ifndef LBHOT_H
#define LBHOT_H

#include "Std_Types.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

#define LBHOT_START_SEC_CALIB_BOOLEAN
#include "LBHOT_MemMap.h"

extern const boolean LBHOT_kbEnableLbupHotPwmMode;

#define LBHOT_STOP_SEC_CALIB_BOOLEAN
#include "LBHOT_MemMap.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define LBHOT_START_SEC_VAR_CLEARED_BOOLEAN
#include "LBHOT_MemMap.h"

extern boolean LBHOT_bLbdwHotAppliCmd;
extern boolean LBHOT_bLbupHotAppliCmd;

#define LBHOT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "LBHOT_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define LBHOT_START_SEC_CODE
#include "LBHOT_MemMap.h"

void LBHOT_vidInit(void);
void LBHOT_vidSetDutyCycle(uint8 u8ChannelId, uint16 u16DutyCycle);
void LBHOT_vidSetPeriodAndDuty(uint8 u8ChannelId, uint16 u16Period, uint16 u16DutyCycle);
void LBHOT_vidUpCmdRestart(void);
void LBHOT_vidUpCmdStop(void);
void LBHOT_vidSetUpPwmOutputToIdle(uint8 u8ChannelId);
void LBHOT_vidWriteLbdwHotState(boolean bState);
void LBHOT_vidWriteLbupHotState(boolean bState);
boolean LBHOT_bReadRawLbdwHotState(void);
boolean LBHOT_bReadRawLbupHotState(void);

#define LBHOT_STOP_SEC_CODE
#include "LBHOT_MemMap.h"


#endif /* LBHOT_H */

/*------------------------------- end of file --------------------------------*/
