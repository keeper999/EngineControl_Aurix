/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPEM                                                  */
/* !Description     : ACCPEM Component                                        */
/*                                                                            */
/* !Module          : ACCPEM                                                  */
/* !Description     : Calcul de l’enfoncement de la pédale d’accélérateur pour*/
/*                    Easy Move                                               */
/*                                                                            */
/* !File            : ACCPEM_SCH.C                                            */
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
/*   1 / AccP_EveRst_AccPEM                                                   */
/*   2 / AccP_EveKOf_AccPEM                                                   */
/*   3 / AccP_SdlFast_AccPEM                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5021748 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCPEM/ACCPEM_SCH.c_v             $*/
/* $Revision::   1.4      $$Author::   hmelloul       $$Date::   26 Sep 2014 $*/
/* $Author::   hmelloul                               $$Date::   26 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPEM.h"
#include "ACCPEM_L.h"
#include "ACCPEM_IM.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_AccPEM                                         */
/* !Description :  Event reset.                                               */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_001.01                                     */
/*                 VEMS_E_11_05596_002.01                                     */
/*                 VEMS_E_11_05596_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPEM_vidInitOutput();                                  */
/*  extf argret void ACCPEM_vidInit();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveRst_AccPEM                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_AccPEM(void)
{
   ACCPEM_vidInitOutput();
   ACCPEM_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveKOf_AccPEM                                         */
/* !Description :  Evénement clef On_Off                                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_001.01                                     */
/*                 VEMS_E_11_05596_002.01                                     */
/*                 VEMS_E_11_05596_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPEM_vidPosPedKOff();                                  */
/*  input uint8 ACCPEM_u8Inhib;                                               */
/*  input boolean AccPEM_bAccPInvld;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveKOf_AccPEM                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveKOf_AccPEM(void)
{
   boolean  bLocalAccPEM_bAccPInvld;


   if (ACCPEM_u8Inhib != 0x5A)
   {
      VEMS_vidGET(AccPEM_bAccPInvld, bLocalAccPEM_bAccPInvld);
      if (bLocalAccPEM_bAccPInvld == 0)
      {
         ACCPEM_vidPosPedKOff();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_AccPEM                                        */
/* !Description :  Moniteur rapide de la fonction pédale d'accélérateur       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_11_05596_001.01                                     */
/*                 VEMS_E_11_05596_002.01                                     */
/*                 VEMS_E_11_05596_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPEM_vidPosPedFinale();                                */
/*  extf argret void ACCPEM_vidDiagCoh();                                     */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPEM_vidPosPedValid();                                 */
/*  extf argret void ACCPEM_vidPosPedRst();                                   */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 ACCPEM_u8Inhib;                                               */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean AccP_bDgoCoh_rAccP;                                         */
/*  input boolean AccP_bMonRunCoh_rAccP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_AccPEM                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_AccPEM(void)
{
   boolean bLocalClef_de_contact;


   if (ACCPEM_u8Inhib != 0x5A)
   {
      ACCPEM_vidPosPedFinale();
      ACCPEM_vidDiagCoh();
      VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
      if (bLocalClef_de_contact != 0)
      {
         ACCPEM_vidPosPedValid();
      }
      ACCPEM_vidPosPedRst();
      GDGAR_vidGdu(GD_DFT_COH_RACCP,
                   AccP_bDgoCoh_rAccP,
                   AccP_bMonRunCoh_rAccP,
                   DIAG_DISPO);
   }
}
/*------------------------------end of file-----------------------------------*/