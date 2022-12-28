/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : RTMTSK                                                  */
/* !Description     : Real time task duration calculation                     */
/*                                                                            */
/* !File            : RTMTSK_Cfg.h                                            */
/* !Description     : Configuration of RTMTSK Component                       */
/*                                                                            */
/* !Reference       : V03 NT 08 02744                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A111537.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef RTMTSK_CFG_H
#define RTMTSK_CFG_H

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* Scaling between Real/Desired resolution for the RTMTSK component           */
#define RTMTSK_DESIRED_RESOL_COEF  1  /* equiv 10ns */
#define RTMTSK_REAL_RESOL_COEF     1  /* equiv 10ns */

#endif /* RTMTSK_CFG_H */

/*-------------------------------- end of file -------------------------------*/
