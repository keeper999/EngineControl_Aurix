/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CSTRMGR                                                 */
/* !Description     : CSTRMGR Component                                       */
/*                                                                            */
/* !Module          : CSTRMGR                                                 */
/* !Description     : Calcul de la consigne d_ouverture de la purge.          */
/*                                                                            */
/* !File            : CSTRMGR_SCH.C                                           */
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
/*   1 / Cstr_EveRst_CstrMgr                                                  */
/*   2 / Cstr_EveKOf_CstrMgr                                                  */
/*   3 / Cstr_SdlMid_CstrMgr                                                  */
/*                                                                            */
/* !Reference   : V02 NT 09 01858 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CSTR/CSTRMGR/CSTRMGR_SCH.C_v      $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   19 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   19 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "CSTRMGR.H"
#include "CSTRMGR_L.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveRst_CstrMgr                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mariem BOUATTOUR                                           */
/* !Trace_To    :  VEMS_R_07_07376_001.01                                     */
/*                 VEMS_R_07_07376_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRMGR_vidInitOutput();                                 */
/*  extf argret void CSTRMGR_vidInit();                                       */
/*  extf argret void CSTRMGR_vidMgr();                                        */
/*  extf argret void CSTRMGR_vidOutputInterface();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveRst_CstrMgr                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_CstrMgr(void)
{
   CSTRMGR_vidInitOutput();
   CSTRMGR_vidInit();
   CSTRMGR_vidMgr();
   CSTRMGR_vidOutputInterface();

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveKOf_CstrMgr                                        */
/* !Description :  Evénement associé au passage de clef ON à clef OFF         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mariem BOUATTOUR                                           */
/* !Trace_To    :  VEMS_R_07_07376_001.01                                     */
/*                 VEMS_R_07_07376_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRMGR_vidCalcRcoPurgeApplique();                       */
/*  extf argret void CSTRMGR_vidOutputInterface();                            */
/*  input uint8 CSTRMGR_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveKOf_CstrMgr                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveKOf_CstrMgr(void)
{
   if (CSTRMGR_u8Inhib != 0x5A)
   {
      CSTRMGR_vidCalcRcoPurgeApplique();
      CSTRMGR_vidOutputInterface();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlMid_CstrMgr                                        */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mariem BOUATTOUR                                           */
/* !Trace_To    :  VEMS_R_07_07376_001.01                                     */
/*                 VEMS_R_07_07376_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CSTRMGR_vidMgr();                                        */
/*  extf argret void CSTRMGR_vidCalcRcoPurgeApplique();                       */
/*  extf argret void CSTRMGR_vidOutputInterface();                            */
/*  input uint8 CSTRMGR_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlMid_CstrMgr                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlMid_CstrMgr(void)
{
   if (CSTRMGR_u8Inhib != 0x5A)
   {
      CSTRMGR_vidMgr();
      CSTRMGR_vidCalcRcoPurgeApplique();
      CSTRMGR_vidOutputInterface();
   }
}
/*------------------------------- end of file --------------------------------*/