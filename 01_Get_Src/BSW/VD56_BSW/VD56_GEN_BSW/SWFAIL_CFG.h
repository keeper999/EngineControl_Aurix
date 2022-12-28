/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SWFAIL                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : SWFAIL_CFG.h                                            */
/* !Description     : Configuration of SWFAIL Component                       */
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
 * %PID: P2017_BSW:0A192454.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SWFAIL_CFG_H
#define SWFAIL_CFG_H

#include "Os.h"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef TaskType SWFAIL_tudtStackIdxType;

/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/

#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

extern void SWFAIL_vidPerformManualReset(void);
extern void SWFAIL_vidNotHandledISRHook(void);

#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"

#endif /* SWFAIL_CFG_H */

/*-------------------------------- end of file -------------------------------*/
