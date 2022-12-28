/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXMNG                                             */
/* !Description     : VLVACTEXMNG Component                                   */
/*                                                                            */
/* !Module          : VLVACTEXMNG                                             */
/* !Description     : MANAGER DE LA FONCTION VVT ECHAPPEMENT                  */
/*                                                                            */
/* !File            : VLVACTEXMNG_SCH.C                                       */
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
/*   1 / VLVACTEXMNG_vidEntryInit                                             */
/*   2 / VlvAct_SdlFast_ExMng_1                                               */
/*   3 / VlvAct_SdlFast_ExMng_2                                               */
/*                                                                            */
/* !Reference   : V02 NT 08 07819 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#068177                                         */
/* !OtherRefs   : VEMS V02 ECU#068136                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXMNG/VLVACTEXMNG$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Feb 2014 $*/
/* $Author::   etsasson                               $$Date::   17 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXMNG.h"
#include "VLVACTEXMNG_L.h"
#include "VLVACTEXMNG_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidEntryInit                                   */
/* !Description :  sched reset                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_008.01                                     */
/*                 VEMS_R_08_07819_010.01                                     */
/*                 VEMS_R_08_07819_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMNG_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VLVACTEXMNG_vidEntryInit                                       */
/* !Trigger  : VLVACTEXMNG_vidEntryInit                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidEntryInit(void)
{
   VLVACTEXMNG_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExMng_1                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_008.01                                     */
/*                 VEMS_R_08_07819_010.01                                     */
/*                 VEMS_R_08_07819_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMNG_vidInitStEnaCdn();                           */
/*  extf argret void VLVACTEXMNG_vidLrnStEnaCdn();                            */
/*  extf argret void VLVACTEXMNG_vidServoStEnaCdn();                          */
/*  extf argret void VLVACTEXMNG_vidClnStEnaCdn();                            */
/*  extf argret void VLVACTEXMNG_vidUnlckStr();                               */
/*  extf argret void VLVACTEXMNG_vidStMng();                                  */
/*  input uint8 VLVACTEXMNG_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_SdlFast_ExMng_1                                         */
/* !Trigger  : VlvAct_SdlFast_ExMng_1                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExMng_1(void)
{
   if (VLVACTEXMNG_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXMNG_vidInitStEnaCdn();
         VLVACTEXMNG_vidLrnStEnaCdn();
         VLVACTEXMNG_vidServoStEnaCdn();
         VLVACTEXMNG_vidClnStEnaCdn();
         VLVACTEXMNG_vidUnlckStr();
         VLVACTEXMNG_vidStMng();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExMng_2                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_011.01                                     */
/*                 VEMS_R_08_07819_008.01                                     */
/*                 VEMS_R_08_07819_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXMNG_vidMngStCmd();                               */
/*  input uint8 VLVACTEXMNG_u8Inhib;                                          */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : VlvAct_SdlFast_ExMng_2                                         */
/* !Trigger  : VlvAct_SdlFast_ExMng_2                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExMng_2(void)
{
   if (VLVACTEXMNG_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXMNG_vidMngStCmd();
      }
   }
}

/*------------------------------- end of file --------------------------------*/