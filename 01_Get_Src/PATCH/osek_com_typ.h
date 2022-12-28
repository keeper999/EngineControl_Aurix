/******************************************************************************/
/*                                                                            */
/* !Layer           : COM                                                     */
/*                                                                            */
/* !Component       : OSEK_COM                                                */
/* !Description     : Osek_com used types                                     */
/*                                                                            */
/* !Module          : OSEK_COM                                                */
/* !Description     : OSEK_COM Configuration                                  */
/*                                                                            */
/* !File            : osek_com_typ.h                                          */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEES                                              */
/*                                                                            */
/* Coding language  : H                                                       */
/*                                                                            */
/* COPYRIGHT 2005-2009 VALEO                                                  */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/osek_com_typ.h_v            $*/
/* $Revision::   1.0                                                         $*/
/* $Author::   croche2                                $$Date::   11 Mar 2014 $*/
/******************************************************************************/

#ifndef OSEK_COM_TYP_H
#define OSEK_COM_TYP_H

#include "STD_TYPES.h"

/* Used by OSEK_COM */
typedef uint8        AddressType;
typedef uint8        AccessName;
typedef AccessName * AccessNameRef;
typedef uint16       Length;
typedef Length *     LengthRef;
typedef uint8        SymbolicName;

typedef P2FUNC(void, OSEK_COM_APPL_CODE, OSEK_COM_tpfvidCallback)(void);

typedef enum
{
   OSEK_COM_OK            =0,
   OSEK_COM_BUSY          =1,
   OSEK_COM_LOCKED        =2,
   OSEK_COM_NOMSG         =3,
   OSEK_COM_NEW_MSG       =4,
   OSEK_COM_OLD_MSG       =5,
   OSEK_COM_LOST_MSG      =6,
   OSEK_COM_WAIT          =8
}
OSEK_COM_tenuFrameStatus;

typedef uint8         OSEK_COM_tudtFrameLength;
typedef SymbolicName  OSEK_COM_tudtFrameId;
typedef uint8         OSEK_COM_tudtBusId;
typedef uint8         OSEK_COM_tudtMsgNwlId;
typedef Length        OSEK_COM_tudtMsgBufferLength;

#endif

/*----------------------------- fin de fichier ------------------------------*/
