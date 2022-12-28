/******************************************************************************/
/*                                                                            */
/* !Layer          : MNGBRKPED                                                */
/*                                                                            */
/* !Component      : MNGBRKPED                                                */
/*                                                                            */
/* !Module         : MNGBRKPED                                                */
/* !Description    : Contains internal defines of the MNGBRKPED component     */
/*                                                                            */
/* !File           : MNGBRKPED_I.C                                            */
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
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   07 Sep 2012 $*/
/* $Author::   HHAMLAOU                              $$Date::   07 Sep 2012 1$*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MNGBRKPED_I.H"

#define MNGBRKPED_START_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"
   boolean  Ext_bSecBrkPedPrssMesMem;
#define MNGBRKPED_STOP_SEC_VAR_NOINIT_BOOLEAN
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/