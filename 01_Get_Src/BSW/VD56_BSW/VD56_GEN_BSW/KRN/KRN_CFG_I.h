/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_CFG_I.h                                             */
/* !Description     : KRN Component Configuration                             */
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
 * %PID: P2017_BSW:0A192442.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KRN_CFG_I_H
#define KRN_CFG_I_H

#include "KRN_Private.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !MComment: Configuration of STM scheduler counter registers                */
#define MSB_REGISTER_MASK              MSB_32BITS_REGISTER_MASK
/* !MComment: Configuration of STM scheduler period                           */
#define KRN_u16SCHEDULER_PERIOD_500US  2000 // (1s / 500us)

#endif /* KRN_CFG_I_H */

/*-------------------------------- end of file -------------------------------*/
