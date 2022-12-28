/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FUPMPMNG                                                */
/* !Description     : FUPMPMNG Component                                      */
/*                                                                            */
/* !Module          : FUPMPMNG                                                */
/* !Description     : STRATEGIE GESTION DE LA POMPE A ESSENCE                 */
/*                                                                            */
/* !File            : FUPMPMNG_SCH.C                                          */
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
/*   1 / FuPmp_EveRst_Mng                                                     */
/*   2 / FuPmp_EveKOn_Mng                                                     */
/*   3 / FuPmp_EveRxnIdDaRcdDml                                               */
/*   4 / FuPmp_EveRTSt_Mng                                                    */
/*   5 / FuPmp_EveStTR_Mng                                                    */
/*   6 / FuPmp_SdlFast_Mng                                                    */
/*   7 / FuPmp_SdlMid_Mng                                                     */
/*                                                                            */
/* !Reference   : V02 NT 07 01322 / 08                                        */
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/FUPMP/FUPMPMNG/FUPMPMNG_SCH.c_v   $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   hmelloul                               $$Date::   26 Sep 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "FUPMPMNG.h"
#include "FUPMPMNG_L.h"
#include "FUPMPMNG_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveRst_Mng                                           */
/* !Description :  Fonction d'accroche sur l'event FuPmp_EveRst_Mng           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidInit();                                      */
/*  extf argret void FUPMPMNG_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveRst_Mng                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveRst_Mng(void)
{
   FUPMPMNG_vidInit();
   FUPMPMNG_vidInitOutput();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveKOn_Mng                                           */
/* !Description :  Fonction d'accroche sur l'event FuPmp_EveKOn_Mng           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidInitEveKOnMng();                             */
/*  input uint8 FUPMPMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveKOn_Mng                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveKOn_Mng(void)
{
   if (FUPMPMNG_u8Inhib != 0x5A)
   {
      FUPMPMNG_vidInitEveKOnMng();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveRxnIdDaRcdDml                                     */
/* !Description :  FuPmp_EveKOn_Mng                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidInitEveRxnIdDaRcdDml();                      */
/*  input uint8 FUPMPMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveRxnIdDaRcdDml                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveRxnIdDaRcdDml(void)
{
   if (FUPMPMNG_u8Inhib != 0x5A)
   {
      FUPMPMNG_vidInitEveRxnIdDaRcdDml();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveRTSt_Mng                                          */
/* !Description :  Fonction d'accroche sur l'event FuPmp_EveRTSt_Mng          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidInitPumpCrankStall();                        */
/*  input uint8 FUPMPMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveRTSt_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveRTSt_Mng(void)
{
   if (FUPMPMNG_u8Inhib != 0x5A)
   {
      FUPMPMNG_vidInitPumpCrankStall();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveStTR_Mng                                          */
/* !Description :  Fonction d'accroche sur l'event FuPmp_EveStTR_Mng          */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidInitPumpStallCrank();                        */
/*  input uint8 FUPMPMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveStTR_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveStTR_Mng(void)
{
   if (FUPMPMNG_u8Inhib != 0x5A)
   {
      FUPMPMNG_vidInitPumpStallCrank();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlFast_Mng                                          */
/* !Description :  Moniteur rapide de la fonction pompe à essence             */
/* !Number      :  SCH.6                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidInitCallMng();                               */
/*  input uint8 FUPMPMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlFast_Mng                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlFast_Mng(void)
{
   if (FUPMPMNG_u8Inhib != 0x5A)
   {
      FUPMPMNG_vidInitCallMng();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlMid_Mng                                           */
/* !Description :  Moniteur moyen de la fonction pompe à essence              */
/* !Number      :  SCH.7                                                      */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUPMPMNG_vidControlPump();                               */
/*  input uint8 FUPMPMNG_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlMid_Mng                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlMid_Mng(void)
{
   if (FUPMPMNG_u8Inhib != 0x5A)
   {
      FUPMPMNG_vidControlPump();
   }
}

/*------------------------------- end of file --------------------------------*/