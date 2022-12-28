/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Mcal_Options.h $                                           **
**                                                                           **
**  $CC VERSION : \main\1 $                                                  **
**                                                                           **
**  $DATE       : 2014-01-14 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file configures pre-compile switches          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

#ifndef MCAL_OPTIONS_H
#define MCAL_OPTIONS_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* 
   Configuration:
   IFX_MCAL_USED :
   Pre-Compile switch to enable stand alone Mcal
   IFX_SAFETLIB_USED:
   Pre-Compile switch to enable Standalone safeTlib
*/

#define IFX_MCAL_USED      STD_ON
#define IFX_SAFETLIB_USED      STD_OFF
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/



#endif /* MCAL_OPTIONS_H */