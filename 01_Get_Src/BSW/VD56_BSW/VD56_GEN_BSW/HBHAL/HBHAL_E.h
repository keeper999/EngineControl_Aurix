/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : HBHAL                                                   */
/* !Description     : HBHAL Component                                         */
/*                                                                            */
/* !File            : HBHAL_E.h                                               */
/* !Description     : APIs of the HBHAL Component.                            */
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
 * %PID: LIBEMB:HBHAL E H-99053648X5000X796.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef HBHAL_E_H
#define HBHAL_E_H

#include "HBHAL_TYPES.h"
#include "HBHAL_CFG.h"

#define HBHAL_vidInit() 

#define HBHAL_vidEnable(u8Channel) \
   HBHAL_vidENABLE_I(u8Channel)

#define HBHAL_vidDisable(u8Channel) \
   HBHAL_vidDISABLE_I(u8Channel)

#define HBHAL_vidWrite(u8Channel, udtSetPoint) \
   HBHAL_vidWRITE_I(u8Channel, udtSetPoint)

#define HBHAL_enuReadStatus(u8Channel) \
   HBHAL_enuREAD_STATUS_I(u8Channel)
   
#define HBHAL_vidEnableNotification(u8Channel) \
   HBHAL_vidENABLE_NOTIFICATION_I(u8Channel)

#define HBHAL_vidDisableNotification(u8Channel) \
   HBHAL_vidDISABLE_NOTIFICATION_I(u8Channel)

#endif /* HBHAL_E_H */

/*-------------------------------- end of file -------------------------------*/
