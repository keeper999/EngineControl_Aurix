/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RSTSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : RSTSRV_Private.h                                        */
/* !Description     : Private Declaration of RSTSRV Component                 */
/*                                                                            */
/* !Reference       : V03 NT 07 02929                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A167415.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RSTSRV_PRIVATE_H
#define RSTSRV_PRIVATE_H

#include "Std_Types.h"

/******************************************************************************/
/* DATA DECLARATIONS                                                          */
/******************************************************************************/

#define RSTSRV_START_SEC_VAR_CLEARED_BOOLEAN
#include "RSTSRV_MemMap.h"

extern boolean RSTSRV_bSWResetDetected;

#define RSTSRV_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "RSTSRV_MemMap.h"

#endif /* RSTSRV_PRIVATE_H */

/*-------------------------------- end of file -------------------------------*/
