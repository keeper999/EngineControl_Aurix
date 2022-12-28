/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCCKCMMONDIAG                                         */
/* !Description     : SYNCCKCMMONDIAG component.                              */
/*                                                                            */
/* !Module          : SYNCCKCMMONDIAG                                         */
/* !Description     : SURVEILLANCE DES SIGNAUX ARBRE A CAMES ET VILEBREQUIN   */
/*                                                                            */
/* !File            : SYNCCKCMMONDIAG_SCH.C                                   */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Sync_EveRst_CmCkMon                                                  */
/*   2 / Sync_EveKOn_CmCkMon                                                  */
/*   3 / Sync_SdlSlow_CmCkMon                                                 */
/*   4 / Sync_EveInCmToo_CmCkMon                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 04208 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/SYNCCKCMMONDIAG/SYNCCKCMMONDI$*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   20 Jan 2012 $*/
/* $Author::   wbouach                                $$Date::   20 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/


#include "STD_TYPES.h"
#include "SYNCCKCMMONDIAG.H"
#include "SYNCCKCMMONDIAG_L.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_CmCkMon                                        */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidInitOutput();                         */
/*  extf argret void SYNCCKCMMONDIAG_vidIniEnaDgoNoSg();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSigCkMonIni();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidLossCkMonIni();                       */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgInCmIni();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidLossInCmIni();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgExCmIni();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidLossExCmIni();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_CmCkMon                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_CmCkMon(void)
{
   SYNCCKCMMONDIAG_vidInitOutput();
   SYNCCKCMMONDIAG_vidIniEnaDgoNoSg();
   SYNCCKCMMONDIAG_vidNoSigCkMonIni();
   SYNCCKCMMONDIAG_vidLossCkMonIni();
   SYNCCKCMMONDIAG_vidNoSgInCmIni();
   SYNCCKCMMONDIAG_vidLossInCmIni();
   SYNCCKCMMONDIAG_vidNoSgExCmIni();
   SYNCCKCMMONDIAG_vidLossExCmIni();

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveKOn_CmCkMon                                        */
/* !Description :  Evènement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidIniEnaDgoNoSg();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSigCkMonIni();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidLossCkMonIni();                       */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgInCmIni();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidLossInCmIni();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidNoSgExCmIni();                        */
/*  extf argret void SYNCCKCMMONDIAG_vidLossExCmIni();                        */
/*  input uint8 SYNCCKCMMONDIAG_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveKOn_CmCkMon                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveKOn_CmCkMon(void)
{
   if (SYNCCKCMMONDIAG_u8Inhib != 0x5A)
   {
      SYNCCKCMMONDIAG_vidIniEnaDgoNoSg();
      SYNCCKCMMONDIAG_vidNoSigCkMonIni();
      SYNCCKCMMONDIAG_vidLossCkMonIni();
      SYNCCKCMMONDIAG_vidNoSgInCmIni();
      SYNCCKCMMONDIAG_vidLossInCmIni();
      SYNCCKCMMONDIAG_vidNoSgExCmIni();
      SYNCCKCMMONDIAG_vidLossExCmIni();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_SdlSlow_CmCkMon                                       */
/* !Description :  Moniteur lent de la fonction Sync                          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidClEnaDgoNoSg();                       */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrCmDiagEve();                      */
/*  extf argret void SYNCCKCMMONDIAG_vidCkMonRst();                           */
/*  input uint8 SYNCCKCMMONDIAG_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_SdlSlow_CmCkMon                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_SdlSlow_CmCkMon(void)
{
   if (SYNCCKCMMONDIAG_u8Inhib != 0x5A)
   {
      SYNCCKCMMONDIAG_vidClEnaDgoNoSg();
      SYNCCKCMMONDIAG_vidGenrCmDiagEve();
      SYNCCKCMMONDIAG_vidCkMonRst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveInCmToo_CmCkMon                                    */
/* !Description :  Evènement arbre à cames admission                          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  I.GAIED                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCCKCMMONDIAG_vidGenrCkDiagEve();                      */
/*  input uint8 SYNCCKCMMONDIAG_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveInCmToo_CmCkMon                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveInCmToo_CmCkMon(void)
{
   if (SYNCCKCMMONDIAG_u8Inhib != 0x5A)
   {
      SYNCCKCMMONDIAG_vidGenrCkDiagEve();
   }
}
/*------------------------------- end of file --------------------------------*/