/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVINSPMGT                                              */
/* !Description     : VLVINSPMGT component                                    */
/*                                                                            */
/* !Module          : VLVINSPMGT                                              */
/* !Description     : Gestion de la consigne VVT admission                    */
/*                                                                            */
/* !File            : VLVINSPMGT_SCH.C                                        */
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
/*   1 / VlvSys_EveIni_VlvIn                                                  */
/*   2 / VlvSys_SdlFast_VlvIn                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 02166 / 01                                        */
/* !OtherRefs   : CSMT_CGMT09_2176_2 / 1                                      */
/* !OtherRefs   : VEMS V02 ECU#053818                                         */
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
#include "VLVINSPMGT.h"
#include "VLVINSPMGT_L.h"
#include "VLVINSPMGT_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_EveIni_VlvIn                                        */
/* !Description :  Fonction d'appel de l'initialisation de la fonction VlvIn  */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_001.01                                     */
/*                 VEMS_R_11_02166_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVINSPMGT_vidInit();                                    */
/*  extf argret void VLVINSPMGT_vidInitOutput();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_EveIni_VlvIn                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_EveIni_VlvIn(void)
{
   VLVINSPMGT_vidInit();
   VLVINSPMGT_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_SdlFast_VlvIn                                       */
/* !Description :  Fonction d'appel de la fonction VlvIn                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_001.01                                     */
/*                 VEMS_R_11_02166_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVINSPMGT_vidVlvInEna();                                */
/*  input uint8 VLVINSPMGT_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_SdlFast_VlvIn                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_SdlFast_VlvIn(void)
{
   if (VLVINSPMGT_u8Inhib != 0x5A)
   {
      VLVINSPMGT_vidVlvInEna();
   }
}

/*---------------------------------end of file--------------------------------*/