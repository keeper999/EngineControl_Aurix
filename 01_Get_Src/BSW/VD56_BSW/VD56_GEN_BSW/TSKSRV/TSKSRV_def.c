/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : TSKSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : TSKSRV_DEF.c                                            */
/* !Description     : TSKSRV Data Definition                                  */
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
 * %PID: P2017_BSW:A282.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "Std_Types.h"
#include "TSKSRV_I.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* PrivateComponent variables                                                 */
/******************************************************************************/

#define  TSKSRV_START_SEC_VAR_UNSPECIFIED
#include "TSKSRV_MemMap.h"

/* !Comment: Stores the activation requests, one filed for each task */
boolean TSKSRV_abActivationRequest[TSKSRV_u8NUMBER_OF_TASKS];

#define  TSKSRV_STOP_SEC_VAR_UNSPECIFIED
#include "TSKSRV_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
