/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RTMCKS                                                  */
/* !Description     : Real Time Monitoring: Memory Checksum Control           */
/*                                                                            */
/* !File            : RTMCKS_Types.h                                          */
/* !Description     : RTMCKS Internal types and datas                         */
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
 * %PID: LIBEMB:RTMCKS T H-99057336X5000X1110.A-SRC;1.2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RTMCKS_TYPES_H
#define RTMCKS_TYPES_H

#include "Std_Types.h"


/******************************************************************************/
/* TYPES DEFINITION                                                           */
/******************************************************************************/
typedef enum
{
   RTMCKS_ALIGNED      = 0,
   RTMCKS_NOT_ALIGNED
} RTMCKS_tenuMode;
typedef uint16           RTMCKS_tResult;
typedef RTMCKS_tResult * RTMCKS_tResultRef;
typedef uint32           RTMCKS_tbfSelectType;
typedef int              RTMCKS_tIndexType;
typedef int              RTMCKS_tZoneIndexType;
typedef uint8            RTMCKS_tudtChannel;



#endif   /* RTMCKS_TYPES_H */

/*-------------------------------- end of file -------------------------------*/
