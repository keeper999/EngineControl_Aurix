/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINMNG                                             */
/* !Description     : VLVACTINMNG component.                                  */
/*                                                                            */
/* !Module          : VLVACTINMNG                                             */
/* !Description     : MANAGER DE LA FONCTION VVT ADMISSION .                  */
/*                                                                            */
/* !File            : VLVACTINMNG_SCH.C                                       */
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
/*   1 / VLVACTINMNG_vidEntryInit                                             */
/*   2 / VlvAct_SdlFast_InMng_1                                               */
/*   3 / VlvAct_SdlFast_InMng_2                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 07174 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#068180                                         */
/* !OtherRefs   : VEMS V02 ECU#068137                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINMNG/VLVACTINMNG$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Feb 2014 $*/
/* $Author::   etsasson                               $$Date::   17 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINMNG.h"
#include "VLVACTINMNG_L.h"
#include "VLVACTINMNG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidEntryInit                                   */
/* !Description :  sched reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_008.01                                     */
/*                 VEMS_R_08_07174_010.01                                     */
/*                 VEMS_R_08_07174_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMNG_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VLVACTINMNG_vidEntryInit                                       */
/* !Trigger  : VLVACTINMNG_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidEntryInit(void)
{
   VLVACTINMNG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InMng_1                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_008.01                                     */
/*                 VEMS_R_08_07174_010.01                                     */
/*                 VEMS_R_08_07174_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMNG_vidInitStEnaCdn();                           */
/*  extf argret void VLVACTINMNG_vidLrnStEnaCdn();                            */
/*  extf argret void VLVACTINMNG_vidServoStEnaCdn();                          */
/*  extf argret void VLVACTINMNG_vidClnStEnaCdn();                            */
/*  extf argret void VLVACTINMNG_vidUnlckStr();                               */
/*  extf argret void VLVACTINMNG_vidStMng();                                  */
/*  input uint8 VLVACTINMNG_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_SdlFast_InMng_1                                         */
/* !Trigger  : VlvAct_SdlFast_InMng_1                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InMng_1(void)
{
   if (VLVACTINMNG_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINMNG_vidInitStEnaCdn();
         VLVACTINMNG_vidLrnStEnaCdn();
         VLVACTINMNG_vidServoStEnaCdn();
         VLVACTINMNG_vidClnStEnaCdn();
         VLVACTINMNG_vidUnlckStr();
         VLVACTINMNG_vidStMng();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InMng_2                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_008.01                                     */
/*                 VEMS_R_08_07174_010.01                                     */
/*                 VEMS_R_08_07174_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINMNG_vidMngStCmd();                               */
/*  input uint8 VLVACTINMNG_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_SdlFast_InMng_2                                         */
/* !Trigger  : VlvAct_SdlFast_InMng_2                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InMng_2(void)
{
   if (VLVACTINMNG_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINMNG_vidMngStCmd();
      }
   }
}
/*------------------------------- end of file --------------------------------*/