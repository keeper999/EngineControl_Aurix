/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVEXSPMGT                                              */
/* !Description     : VLVEXSPMGT component                                    */
/*                                                                            */
/* !Module          : VLVEXSPMGT                                              */
/* !Description     : Gestion de la consigne VVT échappement                  */
/*                                                                            */
/* !File            : VLVEXSPMGT_SCH.C                                        */
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
/*   1 / VlvSys_EveIni_VlvEx                                                  */
/*   2 / VlvSys_SdlFast_VlvEx                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 02167 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_2177_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#053820                                         */
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
#include "VLVEXSPMGT.h"
#include "VLVEXSPMGT_L.h"
#include "VLVEXSPMGT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_EveIni_VlvEx                                        */
/* !Description :  Fonction d'appel de l'initialisation de la fonction VlvEx  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_001.01                                     */
/*                 VEMS_R_11_02167_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVEXSPMGT_vidInit();                                    */
/*  extf argret void VLVEXSPMGT_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_EveIni_VlvEx                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_EveIni_VlvEx(void)
{
   VLVEXSPMGT_vidInit();
   VLVEXSPMGT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_SdlFast_VlvEx                                       */
/* !Description :  Fonction d'appel de la fonction VlvEx                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_001.01                                     */
/*                 VEMS_R_11_02167_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVEXSPMGT_vidVlvExEna();                                */
/*  input uint8 VLVEXSPMGT_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_SdlFast_VlvEx                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_SdlFast_VlvEx(void)
{
   if (VLVEXSPMGT_u8Inhib != 0x5A)
   {
      VLVEXSPMGT_vidVlvExEna();
   }
}

/*---------------------------------end of file--------------------------------*/