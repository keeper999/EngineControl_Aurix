/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : LBHOT                                                   */
/* !Description     : Oxygen (Lambda) Sensor Heating management               */
/*                                                                            */
/* !File            : LBHOT_Cfg.h                                             */
/* !Description     : LBHOT's Configurations                                  */
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
 * %PID: P2017_BSW:0A192477.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef LBHOT_CFG_H
#define LBHOT_CFG_H

#include "Std_Types.h"
#include "TLE8718_Gateway.h"


/******************************************************************************/
/*  DEFINES                                                                   */
/******************************************************************************/

#define LBHOT_bUPS_CMD_IDLE_LEVEL    STD_OFF
#define LBHOT_udtPeriod_MAX          40958U
#define LBHOT_udtDuty_MIN            0U
#define LBHOT_udtUPS_CMD_PWM_CH      TLE8718_udtOUT_1


/******************************************************************************/
/*  MACROS                                                                    */
/******************************************************************************/
#define LBHOT_WRITE_UPS_DIO(State)   TLE8718_vidDioWrite_INST1_OUT1(State)
#define LBHOT_WRITE_DWN_DIO(State)   TLE8718_vidDioWrite_INST1_OUT3(State)

#define LBHOT_READ_UPS_DIO()         TLE8718_bDioRead_INST1_OUT1()
#define LBHOT_READ_DWN_DIO()         TLE8718_bDioRead_INST1_OUT3()

#define LBHOT_SET_PER_DUTY_UPS_PWM(Channel, Period, Duty) \
   TLE8718_vidSetPerAndDuty_INST1(Channel, Period, Duty)

#define LBHOT_SET_DUTY_UPS_PWM(Channel, Duty) \
   TLE8718_vidSetDutyCycle_INST1(Channel, Duty)

#define LBHOT_SET_OUTPUT_IDLE_UPS_PWM(Channel) \
   TLE8718_vidSetPwmOutToIdle_INST1(Channel)

#endif /* LBHOT_CFG_H */

/*------------------------------- end of file --------------------------------*/
