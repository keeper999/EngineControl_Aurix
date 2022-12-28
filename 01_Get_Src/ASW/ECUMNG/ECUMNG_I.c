/******************************************************************************/
/*                                                                            */
/* !Layer          : ECUMNG                                                   */
/*                                                                            */
/* !Component      : ECUMNG                                                   */
/*                                                                            */
/* !Module         : ECUMNG                                                   */
/* !Description    : Contains internal defines of the ECUMNG component        */
/*                                                                            */
/* !File           : ECUMNG_I.C                                               */
/*                                                                            */
/* !Scope          : PrivateComponent                                         */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ECUST/ECUMNG/ECUMNG_I.c_v       $*/
/* $Revision::   1.1          $$Author::   pbakabad    $$Date::   Jun 25 2013$*/
/******************************************************************************/
#include "STD_TYPES.H"
#include "ECUMNG_I.H"

#define ECUMNG_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"
   boolean EcuSt_bRstSw;
#define ECUMNG_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
