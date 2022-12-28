/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INFOCRASH                                               */
/* !Description     : INFOCRASH Component                                     */
/*                                                                            */
/* !Module          : INFOCRASH                                               */
/* !Description     : Traitement Information Crash Véhicule                   */
/*                                                                            */
/* !File            : INFOCRASH_SCH.C                                         */
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
/*   1 / RlyPwr_EveRst_CrashVeh                                               */
/*   2 / RlyPwr_EveRxn4c8_CrashVeh                                            */
/*   3 / RlyPwr_SdlFast_CrashVeh                                              */
/*                                                                            */
/* !Reference   : V02 NT 08 07842 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/INFOCRASH/INFOCRASH_SCH.C_v $*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   17 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   17 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "INFOCRASH.H"
#include "INFOCRASH_L.H"
#include "INFOCRASH_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_EveRst_CrashVeh                                     */
/* !Description :  Fonction d'accroche au moniteur Reset.                     */
/* !Number      :  SCH.1                                                      */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INFOCRASH_vidInit();                                     */
/*  extf argret void INFOCRASH_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_EveRst_CrashVeh                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_EveRst_CrashVeh(void)
{
   INFOCRASH_vidInit();
   INFOCRASH_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_EveRxn4c8_CrashVeh                                  */
/* !Description :  Evènement de réception de la trame 4C8h                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INFOCRASH_vidConfirmInfoCrash();                         */
/*  extf argret void INFOCRASH_vidInhOrAuthInfoCrash();                       */
/*  input uint8 INFOCRASH_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_EveRxn4c8_CrashVeh                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_EveRxn4c8_CrashVeh(void)
{
   if (INFOCRASH_u8Inhib != 0x5A)
   {
      INFOCRASH_vidConfirmInfoCrash();
      INFOCRASH_vidInhOrAuthInfoCrash();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RlyPwr_SdlFast_CrashVeh                                    */
/* !Description :  Moniteur rapide de la fonction RlyPwr                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INFOCRASH_vidEndConfirmCrash();                          */
/*  extf argret void INFOCRASH_vidInhOrAuthInfoCrash();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 INFOCRASH_u8Inhib;                                            */
/*  input boolean Ext_bDgoDft_Info_Crash;                                     */
/*  input boolean Ext_bMonRunDft_Info_Crash;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : RlyPwr_SdlFast_CrashVeh                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RlyPwr_SdlFast_CrashVeh(void)
{
   if (INFOCRASH_u8Inhib != 0x5A)
   {
      INFOCRASH_vidEndConfirmCrash();
      INFOCRASH_vidInhOrAuthInfoCrash();
      GDGAR_vidGdu(GD_DFT_DFT_INFO_CRASH,
                   Ext_bDgoDft_Info_Crash,
                   Ext_bMonRunDft_Info_Crash,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/