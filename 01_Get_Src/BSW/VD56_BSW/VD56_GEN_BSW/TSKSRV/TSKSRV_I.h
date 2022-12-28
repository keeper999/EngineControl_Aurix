/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : TSKSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : TSKSRV_I.h                                              */
/* !Description     : Internal Macros of TSKSRV Component                     */
/*                                                                            */
/* !Reference       : V03 NT 12 00698                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A281.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef TSKSRV_I_H
#define TSKSRV_I_H

#include "Std_Types.h"
#include "Os.h"
#include "TSKSRV_L.h"

/******************************************************************************/
/* PrivateComponent variables                                                 */
/******************************************************************************/

#define  TSKSRV_START_SEC_VAR_UNSPECIFIED
#include "TSKSRV_MemMap.h"

extern boolean TSKSRV_abActivationRequest[TSKSRV_u8NUMBER_OF_TASKS];

#define  TSKSRV_STOP_SEC_VAR_UNSPECIFIED
#include "TSKSRV_MemMap.h"

#define  TSKSRV_START_SEC_CONST_UNSPECIFIED
#include "TSKSRV_MemMap.h"

extern const TaskType TSKSRV_audtOSTasks[TSKSRV_u8NUMBER_OF_TASKS];

#define  TSKSRV_STOP_SEC_CONST_UNSPECIFIED
#include "TSKSRV_MemMap.h"


#endif /* TSKSRV_I_H */

/*-------------------------------- end of file -------------------------------*/
