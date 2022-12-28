/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INTOBDSRV                                               */
/* !Description     : INTOBDSRV component                                     */
/*                                                                            */
/* !Module          : INTOBDSRV                                               */
/* !Description     : Définition des PID supportés pour le diagnostic OBD et  */
/*                    les services constructeurs                              */
/*                                                                            */
/* !File            : INTOBDSRV_FCT2.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / INTOBDSRV_vidMid_Pid                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 05149 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065271                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INTOBDSRV.h"
#include "INTOBDSRV_L.h"
#include "INTOBDSRV_IM.h"
#include "MATHSRV.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INTOBDSRV_vidMid_Pid                                       */
/* !Description :  Les autres PID sont produits à récurrence moyenne.         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INTOBDSRV_vidMid_Pid1();                                 */
/*  extf argret void INTOBDSRV_vidMid_Pid2();                                 */
/*  extf argret void INTOBDSRV_vidMid_Pid3();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INTOBDSRV_vidMid_Pid(void)
{
   INTOBDSRV_vidMid_Pid1();
   INTOBDSRV_vidMid_Pid2();
   INTOBDSRV_vidMid_Pid3();
}

/*------------------------------- end of file --------------------------------*/