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
/* !File            : ACQCMDDIO_SCH2.C                                        */
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
/*   1 / PwrlRly_SdlMid_IfCmdDiagDio                                          */
/*   2 / PwrRly_SdlMid_IfCmdDiagDio                                           */
/*   3 / PwrRly_EveKOn_IfCmdDiagDio                                           */
/*   4 / PwrRly_EveCkOn_IfCmdDiagDio                                          */
/*   5 / Strtr_SdlMid_IfCmdDiagDio                                            */
/*   6 / EngSt_SdlFast_EngStOutIdcDio                                         */
/*   7 / EngSt_SdlFast_AuthStrtSTTDio                                         */
/*   8 / Oil_SdlSlow_BlowByCmdDio                                             */
/*   9 / HeatSenO2_SdlFast_DrvrSenO2DsDio                                     */
/*   10 / HeatSenO2_EveKOf_DrvrSenO2DsDio                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6509298 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQCMDDIO/ACQCMDDIO_SCH2.C_v      $*/
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
/* !Function    :  PwrlRly_SdlMid_IfCmdDiagDio                                */
/* !Description :  Moniteur moyen du relais principal.                        */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidMainRly();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrlRly_SdlMid_IfCmdDiagDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrlRly_SdlMid_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidMainRly();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_SdlMid_IfCmdDiagDio                                 */
/* !Description :  Moniteur moyen du relais puissance.                        */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidPowerRly();                                 */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_SdlMid_IfCmdDiagDio                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_SdlMid_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidPowerRly();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_EveKOn_IfCmdDiagDio                                 */
/* !Description :  Evénement associé au passage de clef OFF à clef ON.        */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidPowerRly();                                 */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_EveKOn_IfCmdDiagDio                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_EveKOn_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidPowerRly();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PwrRly_EveCkOn_IfCmdDiagDio                                */
/* !Description :  Evènement de détection rotation moteur                     */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidPowerRly();                                 */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PwrRly_EveCkOn_IfCmdDiagDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PwrRly_EveCkOn_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidPowerRly();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Strtr_SdlMid_IfCmdDiagDio                                  */
/* !Description :  Recurence du diagnostic électrique du DML.                 */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidFCmdDml();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Strtr_SdlMid_IfCmdDiagDio                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Strtr_SdlMid_IfCmdDiagDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidFCmdDml();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_EngStOutIdcDio                               */
/* !Description :  Moniteur rapide pour la fonction état moteur.              */
/* !Number      :  SCH2.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidOutpIdc();                                  */
/*  input boolean Ctrl_bEngRun;                                               */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_EngStOutIdcDio                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_EngStOutIdcDio(void)
{
   boolean bLocalCtrl_bEngRun;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;


   VEMS_vidGET(Ctrl_bEngRun, bLocalCtrl_bEngRun);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bEngRun != 0)
         && (  (bLocalECU_bWkuMain != 0)
            || (bLocalUCE_bPwrlAcv != 0)
            || (bLocalECU_bImmoUnlockWkuSt != 0)))
      {
         ACQCMDDIO_vidOutpIdc();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EngSt_SdlFast_AuthStrtSTTDio                               */
/* !Description :  Monitoring rapide de la fonction EngSt.                    */
/* !Number      :  SCH2.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidAuthStrtSTT();                              */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean EngSt_bAcvAuthStrtSTTAcq;                                   */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EngSt_SdlFast_AuthStrtSTTDio                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EngSt_SdlFast_AuthStrtSTTDio(void)
{
   boolean bLocalIntegratioElectronique;
   boolean bLocalEngSt_bAcvAuthStrtSTTAcq;
   boolean bLocalECU_bWkuMain;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   VEMS_vidGET(EngSt_bAcvAuthStrtSTTAcq, bLocalEngSt_bAcvAuthStrtSTTAcq);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);

   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (  (bLocalIntegratioElectronique == 0)
         && (bLocalEngSt_bAcvAuthStrtSTTAcq != 0)
         && (bLocalECU_bWkuMain != 0))
      {
         ACQCMDDIO_vidAuthStrtSTT();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlSlow_BlowByCmdDio                                   */
/* !Description :  Evénement de Reset pour la commande BlowBy.                */
/* !Number      :  SCH2.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidBlowBy1();                                  */
/*  extf argret void ACQCMDDIO_vidBlowBy2();                                  */
/*  input boolean Ctrl_bAvc_BlowBy1;                                          */
/*  input boolean Ctrl_bAvc_BlowBy2;                                          */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlSlow_BlowByCmdDio                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlSlow_BlowByCmdDio(void)
{
   boolean bLocalCtrl_bAvc_BlowBy1;
   boolean bLocalCtrl_bAvc_BlowBy2;


   VEMS_vidGET(Ctrl_bAvc_BlowBy1, bLocalCtrl_bAvc_BlowBy1);
   VEMS_vidGET(Ctrl_bAvc_BlowBy2, bLocalCtrl_bAvc_BlowBy2);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAvc_BlowBy1 != 0)
      {
         ACQCMDDIO_vidBlowBy1();
      }
      if (bLocalCtrl_bAvc_BlowBy2 != 0)
      {
         ACQCMDDIO_vidBlowBy2();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DrvrSenO2DsDio                           */
/* !Description :  Récurrence rapide de la fonction HeatSenO2.                */
/* !Number      :  SCH2.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidSenO2Ds();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DrvrSenO2DsDio                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DrvrSenO2DsDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidSenO2Ds();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveKOf_DrvrSenO2DsDio                            */
/* !Description :  Evénement Clé On -> Off.                                   */
/* !Number      :  SCH2.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidSenO2Ds();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveKOf_DrvrSenO2DsDio                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveKOf_DrvrSenO2DsDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidSenO2Ds();
   }
}
/*------------------------------- end of file --------------------------------*/