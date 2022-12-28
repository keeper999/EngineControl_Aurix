/******************************************************************************/
/*                                                                            */
/* !Layer          : IMMO                                                      */
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
/* $Archive::   I:\Projets\EB_DT\LOG\ASW\Ref\modules\SAIMMO\SAIMMO_I.h_v     $*/
/* $Revision::   1.1          $$Author::   ynicaise    $$Date::   13 Apr 2012$*/
/******************************************************************************/
#ifndef SAIMMO_I_H
#define SAIMMO_I_H

#include "STD_TYPES.H"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
typedef struct
{
   uint32 AdcCode;                  /**/
   uint16 Anti_theft_reserve_1;     /**/
   uint16 Anti_theft_reserve_2;     /**/
   uint8  AdcTyp;                   /**/
}Struct_ObjCode_NVM;

typedef struct
{
   uint16 Anti_theft_reserve_3;     /**/
   uint16 EcuPairOffSt;             /**/
}Struct_ObjEtat_NVM;

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define SAIMMO_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"
   extern uint16  SAIMMO_EcuLock1;
   extern uint16  SAIMMO_EcuLock2;
#define SAIMMO_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h"

#endif /* SAIMMO_I_H */

/*------------------------------- end of file --------------------------------*/
