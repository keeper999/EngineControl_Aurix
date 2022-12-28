/******************************************************************************/
/*                                                                            */
/* !Layer          : IMMO                                                     */
/*                                                                            */
/* !Component      : SAIMMO                                                   */
/*                                                                            */
/* !Module         : SAIMMO_I                                                 */
/* !Description    : Contains internal defines of the SAIMMO component        */
/*                                                                            */
/* !File           : SAIMMO_I.H                                               */
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
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_I.c_v             $*/
/* $Revision::   1.0          $$Author::   etsasson    $$Date::   05 Jan 2012$*/
/******************************************************************************/
#include "STD_TYPES.H"

#define SAIMMO_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
uint16  SAIMMO_EcuLock1;
uint16  SAIMMO_EcuLock2;
#define SAIMMO_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"


/*------------------------------- end of file --------------------------------*/
