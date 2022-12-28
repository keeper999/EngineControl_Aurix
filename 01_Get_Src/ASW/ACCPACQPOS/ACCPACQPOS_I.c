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
/* !File            : ACCPACQPOS_I.C                                          */
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
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPACQPOS/ACCPACQPOS_I.c_v  $*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   23 Sep 2014 $*/
/* $Author::   achebino                               $$Date::   23 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "ACCPACQPOS_I.H"

#define ACCPACQPOS_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
   uint16 AccP_rAccPSens1; 
   uint16 AccP_rAccPSens2; 
#define ACCPACQPOS_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/