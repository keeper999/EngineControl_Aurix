/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RTMCKS                                                  */
/* !Description     : Real Time Monitoring: Memory Checksum Control           */
/*                                                                            */
/* !File            : RTMCKS_I.C                                              */
/* !Description     : RTMCKS data definitions                                 */
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
 * %PID: LIBEMB:RTMCKS I C-99057336X5000X1104.A-SRC;1.3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "RTMCKS_I.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define RTMCKS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "RTMCKS_MemMap.h"

RTMCKS_tstrMainObject RTMCKS_astrValues[RTMCKS_udtCHANNELS_NUMBER];

#define RTMCKS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "RTMCKS_MemMap.h"
/*-------------------------------- end of file -------------------------------*/
