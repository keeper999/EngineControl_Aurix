/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : DRV                                                     */
/* !Description     : MCAL library                                            */
/*                                                                            */
/* !File            : McalOsConfig.h                                          */
/* !Description     : MCAL library configuration                              */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef MCAL_OS_CONFIG_H
#define MCAL_OS_CONFIG_H

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* 
   Configuration:
   MCAL_OS_HEADER :
   Supply the required header file here
   default is Os.h, user can change to "osek.h" if required
*/
#define MCAL_OS_HEADER      "Os.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* Private services                                                           */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/


#endif /* MCAL_OS_CONFIG_H */

/*------------------------------ end of file ---------------------------------*/