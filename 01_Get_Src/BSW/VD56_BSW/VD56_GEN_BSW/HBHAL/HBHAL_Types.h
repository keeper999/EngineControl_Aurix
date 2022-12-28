/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : HBHAL                                                   */
/* !Description     : HBHAL Component                                         */
/*                                                                            */
/* !File            : HBHAL_TYPES.h                                           */
/* !Description     : Public types declarations of the HBHAL Component.       */
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
 * %PID: LIBEMB:HBHAL TYPES H-99053648X5000X802.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef HBHAL_TYPES_H
#define HBHAL_TYPES_H

#include "STD_TYPES.h"

typedef sint32 HBHAL_tudtSetPoint;

/* typedef enum
{
   HBHAL_H_BRIDGE_ENABLED,
   HBHAL_H_BRIDGE_DISABLED
}
HBHAL_tenuStatus; */

typedef uint8 HBHAL_tenuStatus;
#define HBHAL_H_BRIDGE_ENABLED    1
#define HBHAL_H_BRIDGE_DISABLED   0

#define HBHAL_u8OPPOSED_PWM_DRIVE_MODE  1
#define HBHAL_u8STANDARD_DRIVE_MODE     0

#endif /* HBHAL_TYPES_H */

/*-------------------------------- end of file -------------------------------*/
