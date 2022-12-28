/******************************************************************************/
/*                                                                            */
/* !Layer          : ECUMNG                                                   */
/*                                                                            */
/* !Component      : ECUMNG                                                   */
/*                                                                            */
/* !Module         : ECUMNG_I                                                 */
/* !Description    : Contains internal defines of the ECUMNG component        */
/*                                                                            */
/* !File           : ECUMNG_I.H                                               */
/*                                                                            */
/* !Scope          : PrivateComponent                                         */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ECUST/ECUMNG/ECUMNG_I.h_v       $*/
/* $Revision::   1.1          $$Author::   pbakabad    $$Date::   Sep 20 2012$*/
/******************************************************************************/
#ifndef ECUMNG_I_H
#define ECUMNG_I_H

#include "STD_TYPES.H"

#define ECUMNG_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"
   extern boolean EcuSt_bRstSw;
#define ECUMNG_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"

#endif /* ECUMNG_I_H */

/*------------------------------- end of file --------------------------------*/
