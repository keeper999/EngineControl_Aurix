/******************************************************************************/
/*                                                                            */
/* !Layer          : COM                                                      */
/*                                                                            */
/* !Component      : OSEK_COM                                                 */
/* !Description    : Communication layer                                      */
/*                                                                            */
/* !Module         : OSEK_COM                                                 */
/* !Description    : OSEK_COM declarations                                    */
/*                                                                            */
/* !File           : OSEK_COM.H                                               */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor          : Valeo VEES                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2005-2009 VALEO                                                  */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/OSEK_COM.H_v                $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/

#ifndef OSEK_COM_H
#define OSEK_COM_H

#include "STD_TYPES.h"
#include "osek_com_typ.h"
#include "osek_com_i.h"
//#include "cominl.h"

/*-------------------------------------------------------------------------*/
/* Prototypes des fonctions de la Communication OSEK/VDX 2.? revision ?    */
/*-------------------------------------------------------------------------*/
extern StatusType SendMessage               (SymbolicName udtMessageId, AccessName *pudtMessagePtr);
extern StatusType ReceiveMessage            (SymbolicName udtMessageId, AccessName *pudtMessagePtr);
extern StatusType GetMessageResource        (SymbolicName udtMessageId);
extern StatusType ReleaseMessageResource    (SymbolicName udtMessageId);
extern StatusType GetMessageStatus          (SymbolicName udtMessageId);
extern StatusType MessageInit               (void);
extern StatusType StartPeriodical           (void);
extern StatusType StopPeriodical            (void);
extern StatusType StartCOM                  (void);

extern StatusType SendMessageTo             (SymbolicName udtMessageId, AccessName *pudtMessagePtr, Length udtLength, AddressType udtRecipient);
extern StatusType ReceiveMessageFrom        (SymbolicName udtMessageId, AccessName *pudtMessagePtr, Length *pudtLength, AddressType *pudtSender);


/*-------------------------------------------------------------------------*/
/* CODES ERREUR                                                                 */
/*-------------------------------------------------------------------------*/

#define E_COM_BUSY                        1
#define E_COM_LOCKED                      2
#define E_COM_NOMSG                       3
#define E_COM_NEW_MSG                     4
#define E_COM_OLD_MSG                     5
#define E_COM_LOST_MSG                    6
#define E_COM_LIMIT                       7
#define E_COM_ID                          8
#define E_COM_SYS_BUS_INIT_FAILED         16
#define E_COM_SYS_LENGTH                  17


#endif /* OSEK_COM_H */

/*------------------------------- end of file -------------------------------*/
