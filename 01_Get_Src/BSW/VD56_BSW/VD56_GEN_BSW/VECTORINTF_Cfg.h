/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : VECTORINTF                                              */
/* !Description     : Interface to the Vector Flash Boot Loader               */
/*                                                                            */
/* !File            : VECTORINTF_Cfg.h                                        */
/* !Description     : Define the applicative startup function to be started   */
/*                    by Flash Boot Loader.                                   */
/*                    Used by VECTORINTF\applvect.c                           */
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
 * %PID: P2017_BSW:0A192388.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef VECTORINTF_CFG_H
#define VECTORINTF_CFG_H

#define RESETVECT STARTUP_Core0_start

#endif /* VECTORINTF_CFG_H */

/*------------------------------- end of file --------------------------------*/
