/******************************************************************************/
/* !Layer           : APPLI                                                   */
/* !Component       :                                                         */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : APPLI_StackSize.h                                       */
/* !Description     : Configuration of the stack size                         */
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
 * %PID: P2017_BSW:A93482.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef APPLI_STACKSIZE_H
#define APPLI_STACKSIZE_H

/* Sizes defined here shall be the same than sizes declared in .mem linker scipt. */

#define CSA_CPU0_SIZE     8192 /* 8k */
#define USTACK_CPU0_SIZE  8192 /* 8k */

#define CSA_CPU1_SIZE     8192 /* 8k */
#define USTACK_CPU1_SIZE  8192 /* 8k */

#define CSA_CPU2_SIZE     8192 /* 8k */
#define USTACK_CPU2_SIZE  8192 /* 8k */

#endif /* APPLI_STACKSIZE_H */

/*------------------------------ end of file ---------------------------------*/