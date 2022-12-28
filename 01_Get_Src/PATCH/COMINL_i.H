/******************************************************************************/
/*                                                                            */
/* !Layer           : COM                                                     */
/*                                                                            */
/* !Component       : COMINL                                                  */
/* !Description     : COMINL internal APIs                                    */
/*                                                                            */
/* !Module          : COMINL                                                  */
/* !Description     : COMINL Configuration                                    */
/*                                                                            */
/* !File            : COMINL_I.H                                              */
/*                                                                            */
/* !Scope           : PrivateComponent                                        */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT  2009 VALEO                                                      */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/COMINL_i.H_v                $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/

#ifndef _COMINL_I_
#define _COMINL_I_

#include "STD_TYPES.H"
#include "OSEK_COM.H"

/******************************************************************************/
/*                                                                            */
/* !Description : This API COMINL_bIsMsgMonitored Returns TRUE if the Message */
/*                is configured with confirmation and FALSE otherwise.        */
/*                                                                            */
/* !LastAuthor : Mohamed Mohi                                                 */
/******************************************************************************/

#define COMINL_bIsMsgMonitored( \
   udtMessageId  /* Message Identifier                                      */ \
) \
   (((Table_config_message[udtMessageId].Mode & (uint8)COMINL_bfACON) == 0) \
      ?  FALSE : TRUE)

#endif /* _COMINL_I_ */

/*----------------------------------End of File-------------------------------*/