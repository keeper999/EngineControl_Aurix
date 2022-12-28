/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCMDDIO                                               */
/* !Description     : ACQCMDDIO component.                                    */
/*                                                                            */
/* !Module          : ACQCMDDIO                                               */
/* !Description     : SPECIFICATION DES COMMANDES ET ACQUISITIONS LOGIQUES    */
/*                                                                            */
/* !File            : ACQCMDDIO_SCH1.C                                        */
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
/*   1 / Strtr_EveRst_IfCmdDiagDio                                            */
/*   2 / EngSt_EveRst_EngStOutIdcDio                                          */
/*   3 / EngSt_EveRst_AuthStrtSTTDio                                          */
/*   4 / PwrRly_EveRst_IfCmdDiagDio                                           */
/*   5 / PwrlRly_EveRst_IfCmdDiagDio                                          */
/*   6 / Ext_EveRst_AcqCmdDio                                                 */
/*   7 / Pwr_SdlMid_VoltHldDevDio                                             */
/*   8 / PwrlRly_EveKOf_IfCmdDiagDio                                          */
/*   9 / PwrlRly_EveKOn_IfCmdDiagDio                                          */
/*   10 / PwrlRly_EveRxnIdDaRcdDmlDio                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6509298 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQCMDDIO/ACQCMDDIO_SCH1.C_v      $*/
/* $Revision::   1.4      $$Author::   achebino       $$Date::   19 Aug 2014 $*/
/* $Author::   achebino                               $$Date::   19 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.H"
#include "ACQCMDDIO.H"
#include "ACQCMDDIO_L.H"
#include "ACQCMDDIO_IM.H"
#include "ACQCMDDIO_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Strtr_EveRst_IfCmdDiagDio                                  */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidFCmdDml();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Strtr_EveRst_IfCmdDiagDio                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Strtr_EveRst_IfCmdDiagDio(void)
{
   ACQCMDDIO_vidFCmdDml();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_EngStOutIdcDio                                */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidOutpIdc();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_EngStOutIdcDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_EngStOutIdcDio(void)
{
   ACQCMDDIO_vidOutpIdc();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_EveRst_AuthStrtSTTDio                                */
/* !Description :  Evènement_reset.                                           */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidAuthStrtSTT();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_EveRst_AuthStrtSTTDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_EveRst_AuthStrtSTTDio(void)
{
   ACQCMDDIO_vidAuthStrtSTT();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_EveRst_IfCmdDiagDio                                 */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidPowerRly();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_EveRst_IfCmdDiagDio                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_EveRst_IfCmdDiagDio(void)
{
   ACQCMDDIO_vidPowerRly();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveRst_IfCmdDiagDio                                */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidMainRly();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrlRly_EveRst_IfCmdDiagDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveRst_IfCmdDiagDio(void)
{
   ACQCMDDIO_vidMainRly();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_EveRst_AcqCmdDio                                       */
/* !Description :  Evènement d'initialisation.                                */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidInit();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Ext_EveRst_AcqCmdDio                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_EveRst_AcqCmdDio(void)
{
   ACQCMDDIO_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlMid_VoltHldDevDio                                   */
/* !Description :  Moniteur moyen.                                            */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidCmdDioPwr();                                */
/*  input boolean Pwr_bAcvDMTRAcq;                                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlMid_VoltHldDevDio                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlMid_VoltHldDevDio(void)
{
   boolean bLocalPwr_bAcvDMTRAcq;
   boolean bLocalIntegratioElectronique;


   VEMS_vidGET(Pwr_bAcvDMTRAcq, bLocalPwr_bAcvDMTRAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if ( (bLocalPwr_bAcvDMTRAcq != 0)
         && (bLocalIntegratioElectronique == 0))
      {
         ACQCMDDIO_vidCmdDioPwr();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveKOf_IfCmdDiagDio                                */
/* !Description :  Evènement associé au passage de clef ON à clef OFF.        */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidMainRly();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrlRly_EveKOf_IfCmdDiagDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveKOf_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidMainRly();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveKOn_IfCmdDiagDio                                */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidMainRly();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrlRly_EveKOn_IfCmdDiagDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveKOn_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidMainRly();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrlRly_EveRxnIdDaRcdDmlDio                                */
/* !Description :  Evénement de réception de la trame des données RCD et DML. */
/* !Number      :  SCH1.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidMainRly();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrlRly_EveRxnIdDaRcdDmlDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_EveRxnIdDaRcdDmlDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidMainRly();
   }
}

/*------------------------------- end of file --------------------------------*/