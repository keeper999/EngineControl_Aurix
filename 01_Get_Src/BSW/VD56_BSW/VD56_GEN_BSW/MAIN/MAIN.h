/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : MAIN                                                    */
/* !Description     : Core Main Functions                                     */
/*                                                                            */
/* !File            : MAIN.h                                                  */
/* !Description     : Core Main Functions                                     */
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
 * %PID: P2017_BSW:0A111536.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

/******************************************************************************/
/*                         Exported prototypes                                */
/******************************************************************************/
#define  MAIN_START_SEC_CODE
#include "MAIN_MemMap.h"

void MAIN_core0_main (void);
void MAIN_core1_main (void);
void MAIN_core2_main (void);

#define  MAIN_STOP_SEC_CODE
#include "MAIN_MemMap.h"

#endif /* MAIN_H_ */

/*-------------------------------- end of file -------------------------------*/
