/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFADV                                                   */
/* !Description     : IFADV component                                         */
/*                                                                            */
/* !Module          : IFADV                                                   */
/* !Description     : INTERFACE DE LA CHAINE D’AVANCE                         */
/*                                                                            */
/* !File            : IFADV_FCT1.C                                            */
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
/*   1 / IFADV_vidIgSys1                                                      */
/*   2 / IFADV_vidIgSys2                                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 07695 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CAA/IFADV/IFADV_FCT1.c_v        $*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   04 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   04 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IFADV.h"
#include "IFADV_L.h"
#include "IFADV_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFADV_vidIgSys1                                            */
/* !Description :  Calcul de la variable IgSys_agIgLimMinRef2.                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_agIgLimMinRef;                                          */
/*  output uint8 IgSys_agIgLimMinRef2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFADV_vidIgSys1(void)
{
   uint8 u8LocalIgSys_agIgLimMinRef;


   VEMS_vidGET(IgSys_agIgLimMinRef, u8LocalIgSys_agIgLimMinRef);
   VEMS_vidSET(IgSys_agIgLimMinRef2, u8LocalIgSys_agIgLimMinRef);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFADV_vidIgSys2                                            */
/* !Description :  Calcul des variables Cha_bASRReg et Cha_bESPReg.           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  GHADDAB                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bASRRegFirst;                                           */
/*  input boolean Ext_bESPRegFirst;                                           */
/*  output boolean Cha_bASRReg;                                               */
/*  output boolean Cha_bESPReg;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFADV_vidIgSys2(void)
{
   boolean bLocalExt_bESPRegFirst;
   boolean bLocalExt_bASRRegFirst;


   VEMS_vidGET(Ext_bASRRegFirst, bLocalExt_bASRRegFirst);
   VEMS_vidGET(Ext_bESPRegFirst, bLocalExt_bESPRegFirst);
   VEMS_vidSET(Cha_bASRReg, bLocalExt_bASRRegFirst);
   VEMS_vidSET(Cha_bESPReg, bLocalExt_bESPRegFirst);
}
/*------------------------------- end of file --------------------------------*/
