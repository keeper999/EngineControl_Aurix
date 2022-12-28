/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RTMCKS                                                  */
/* !Description     : Real Time Monitoring: Memory Checksum Control           */
/*                                                                            */
/* !File            : RTMCKS.h                                                */
/* !Description     : RTMCKS External definitions                             */
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
 * %PID: LIBEMB:RTMCKS H-99057336X5000X1114.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RTMCKS_H
#define RTMCKS_H

#include "RTMCKS_Types.h"
#include "RTMCKS_I.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
extern void RTMCKS_vidInit(void);
extern void RTMCKS_vidMainFunction(RTMCKS_tudtChannel udtChannelName);
extern void RTMCKS_vidAreaCheckDisable(RTMCKS_tudtChannel udtChannelName, uint8 u8AreaNumber);


#endif   /* RTMCKS_H */

/*-------------------------------- end of file -------------------------------*/
