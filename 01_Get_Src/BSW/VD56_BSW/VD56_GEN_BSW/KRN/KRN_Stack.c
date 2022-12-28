/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_Stack.c                                             */
/* !Description     : Defines Stacks                                          */
/*                                                                            */
/* !Reference       : NONE                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192441.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "APPLI_StackSize.h"

#pragma section ".csa_cpu0" aw
uint8 KRN_au8CSACPU0[CSA_CPU0_SIZE];
#pragma section

#pragma section ".ustack_cpu0" aw
uint8 KRN_au8UStackCPU0[USTACK_CPU0_SIZE];
#pragma section

#pragma section ".csa_cpu1" aw
uint8 KRN_au8CSACPU1[CSA_CPU1_SIZE];
#pragma section

#pragma section ".ustack_cpu1" aw
uint8 KRN_au8UStackCPU1[USTACK_CPU1_SIZE];
#pragma section

#pragma section ".csa_cpu2" aw
uint8 KRN_au8CSACPU2[CSA_CPU2_SIZE];
#pragma section

#pragma section ".ustack_cpu2" aw
uint8 KRN_au8UStackCPU2[USTACK_CPU2_SIZE];
#pragma section


/*-------------------------------- end of file -------------------------------*/
