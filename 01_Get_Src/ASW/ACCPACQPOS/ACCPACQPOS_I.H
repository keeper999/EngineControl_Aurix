/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AccP                                                    */
/* !Description     : AccP component.                                         */
/*                                                                            */
/* !Module          : ACCPACQPOS                                              */
/* !Description     : Acquisition de la position pedale                       */
/*                                                                            */
/* !File            : ACCPACQPOS_I.H                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPACQPOS/ACCPACQPOS_I.H_v  $*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   23 Sep 2014 $*/
/* $Author::   achebino                               $$Date::   23 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#ifndef ACCPACQPOS_I_H
#define ACCPACQPOS_I_H

#include "STD_TYPES.H"

#define ACCPACQPOS_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
   extern uint16 AccP_rAccPSens1; 
   extern uint16 AccP_rAccPSens2;
#define ACCPACQPOS_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

#endif /* ACCPACQPOS_I_H */

/*------------------------------- end of file --------------------------------*/
