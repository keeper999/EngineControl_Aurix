/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RLYPWR                                                  */
/* !Description     : RLYPWR Component                                        */
/*                                                                            */
/* !Module          : RLYPWR                                                  */
/* !Description     : Gestionnaire du relais actionneurs                      */
/*                                                                            */
/* !File            : RLYPWR_SCH.C                                            */
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
/*   1 / RlyPwr_EveRst_Mng                                                    */
/*   2 / RlyPwr_EveStTR_Mng                                                   */
/*   3 / RlyPwr_EveKOn_Mng                                                    */
/*   4 / RlyPwr_SdlFast_Mng                                                   */
/*   5 / RlyPwr_SdlSlow_Mng                                                   */
/*   6 / RlyPwr_EveKOf_Mng                                                    */
/*   7 / RlyPwr_SdlMid_Mng                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5137464 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/RLYPWR/RLYPWR_SCH.C_v       $*/
/* $Revision::   1.11                                                        $*/
/* $Author::   etsasson                               $$Date::   04 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "RLYPWR.h"
#include "RLYPWR_l.h"
#include "RLYPWR_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_EveRst_Mng                                          */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidInitOutput();                                  */
/*  extf argret void RLYPWR_vidInitbEndDiag();                                */
/*  extf argret void RLYPWR_vidPrevEcuStPwrlLong();                           */
/*  extf argret void RLYPWR_vidRlyPwrActrTst();                               */
/*  extf argret void RLYPWR_vidRlyPwrDiagInh();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_EveRst_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_EveRst_Mng(void)
{
   RLYPWR_vidInitOutput();
   RLYPWR_vidInitbEndDiag();
   RLYPWR_vidPrevEcuStPwrlLong();
   RLYPWR_vidRlyPwrActrTst();
   RLYPWR_vidRlyPwrDiagInh();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_EveStTR_Mng                                         */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidRlyPwrCtlMng();                                */
/*  input uint8 RLYPWR_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_EveStTR_Mng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_EveStTR_Mng(void)
{
   if (RLYPWR_u8Inhib != 0x5A)
   {
      RLYPWR_vidRlyPwrCtlMng();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_EveKOn_Mng                                          */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidRlyPwrCtlMng();                                */
/*  extf argret void RLYPWR_vidInitbPwrLong();                                */
/*  extf argret void RLYPWR_vidPrevEcuStPwrlLong();                           */
/*  input uint8 RLYPWR_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_EveKOn_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_EveKOn_Mng(void)
{
   if (RLYPWR_u8Inhib != 0x5A)
   {
      RLYPWR_vidRlyPwrCtlMng();
      RLYPWR_vidInitbPwrLong();
      RLYPWR_vidPrevEcuStPwrlLong();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_SdlFast_Mng                                         */
/* !Description :  Moniteur rapide du relais de puissance (actionneurs)       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidRlyPwrAcvCond();                               */
/*  extf argret void RLYPWR_vidRlyPwrCtlMng();                                */
/*  extf argret void RLYPWR_vidRlyPwrActrTst();                               */
/*  extf argret void RLYPWR_vidPrevEcuStPwrlLong();                           */
/*  extf argret void RLYPWR_vidRlyPwrMngDiagNotInh();                         */
/*  input uint8 RLYPWR_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_SdlFast_Mng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_SdlFast_Mng(void)
{
   if (RLYPWR_u8Inhib != 0x5A)
   {
      RLYPWR_vidRlyPwrAcvCond();
      RLYPWR_vidRlyPwrCtlMng();
      RLYPWR_vidRlyPwrActrTst();
      RLYPWR_vidPrevEcuStPwrlLong();
      RLYPWR_vidRlyPwrMngDiagNotInh();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_SdlSlow_Mng                                         */
/* !Description :  Moniteur lent de la fonction RlyPwr                        */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidRlyPwrEcoBatt();                               */
/*  input uint8 RLYPWR_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_SdlSlow_Mng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_SdlSlow_Mng(void)
{
   if (RLYPWR_u8Inhib != 0x5A)
   {
      RLYPWR_vidRlyPwrEcoBatt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_EveKOf_Mng                                          */
/* !Description :  Evénement associé au passage de clef OFF à clef ON.        */
/* !Number      :  SCH.6                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidInitTempo();                                   */
/*  extf argret void RLYPWR_vidPrevEcuStPwrlLong();                           */
/*  input uint8 RLYPWR_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_EveKOf_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_EveKOf_Mng(void)
{
   if (RLYPWR_u8Inhib != 0x5A)
   {
      RLYPWR_vidInitTempo();
      RLYPWR_vidPrevEcuStPwrlLong();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_SdlMid_Mng                                          */
/* !Description :  Moniteur moyen pour la fonction configuration moteur.      */
/* !Number      :  SCH.7                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_11_00419_001.01                                     */
/*                 VEMS_E_11_00419_002.01                                     */
/*                 VEMS_E_11_00419_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidRlyMngHldReq();                                */
/*  input uint8 RLYPWR_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_SdlMid_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_SdlMid_Mng(void)
{
   if (RLYPWR_u8Inhib != 0x5A)
   {
      /*7_RlyMngHldReq*/
      RLYPWR_vidRlyMngHldReq();
   }
}
/*------------------------------- end of file --------------------------------*/