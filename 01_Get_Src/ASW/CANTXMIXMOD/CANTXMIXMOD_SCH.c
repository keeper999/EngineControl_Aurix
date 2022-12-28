/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CANTXMIXMOD                                             */
/* !Description     : CANTXMIXMOD Component                                   */
/*                                                                            */
/* !Module          : CANTXMIXMOD                                             */
/* !Description     : SPECIFICATION D’INTERFACE MESSAGERIE CAN POUR GESTION   */
/*                    DES TRAMES MIXTES                                       */
/*                                                                            */
/* !File            : CANTXMIXMOD_SCH.c                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Can_EveRst_CanTxMixMod                                               */
/*   2 / Can_SdlFast_CanTxMixMod                                              */
/*   3 / Can_SdlSlow_CanTxMixMod                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5708641 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ISCAN/CANTXMIXMOD/CANTXMIXMOD_SCH.$*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   02 Dec 2013 $*/
/* $Author::   hmelloul                               $$Date::   02 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "CANTXMIXMOD.H"
#include "CANTXMIXMOD_L.H"
#include "CANTXMIXMOD_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_CanTxMixMod                                     */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  PTS_R_5708641_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CANTXMIXMOD_vidInitOutput();                             */
/*  extf argret void CANTXMIXMOD_vidFastCheck();                              */
/*  extf argret void CANTXMIXMOD_vidSlowCheck();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_CanTxMixMod                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_CanTxMixMod(void)
{
   CANTXMIXMOD_vidInitOutput();
   CANTXMIXMOD_vidFastCheck();
   CANTXMIXMOD_vidSlowCheck();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlFast_CanTxMixMod                                    */
/* !Description :  Moniteur rapide.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  PTS_R_5708641_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CANTXMIXMOD_vidFastCheck();                              */
/*  extf argret void Can_EveTxn468_CanTxMixMod();                             */
/*  extf argret void Can_EveTxn1E8_CanTxMixMod();                             */
/*  input uint8 CANTXMIXMOD_u8Inhib;                                          */
/*  input boolean ISCAN_bFastTxn468Req;                                       */
/*  input boolean ISCAN_bFastTxn1E8Req;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlFast_CanTxMixMod                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlFast_CanTxMixMod(void)
{
   if (CANTXMIXMOD_u8Inhib != 0x5A)
   {
      CANTXMIXMOD_vidFastCheck();
      if (ISCAN_bFastTxn468Req != 0)
      {
         Can_EveTxn468_CanTxMixMod();
      }

      if (ISCAN_bFastTxn1E8Req != 0)
      {
         Can_EveTxn1E8_CanTxMixMod();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlSlow_CanTxMixMod                                    */
/* !Description :  Moniteur lent.                                             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  PTS_R_5708641_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CANTXMIXMOD_vidSlowCheck();                              */
/*  extf argret void Can_EveTxn1E8_CanTxMixMod();                             */
/*  input uint8 CANTXMIXMOD_u8Inhib;                                          */
/*  input boolean ISCAN_bTxnSlow1E8Req;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlSlow_CanTxMixMod                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlSlow_CanTxMixMod(void)
{
   if (CANTXMIXMOD_u8Inhib != 0x5A)
   {
      CANTXMIXMOD_vidSlowCheck();
      if (ISCAN_bTxnSlow1E8Req != 0)
      {
         Can_EveTxn1E8_CanTxMixMod();
      }
   }
}