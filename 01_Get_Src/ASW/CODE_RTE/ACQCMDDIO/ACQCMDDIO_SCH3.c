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
/* !File            : ACQCMDDIO_SCH3.C                                        */
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
/*   1 / HeatSenO2_EveKOf_DrvrSenO2UsDio                                      */
/*   2 / HeatSenO2_SdlFast_DrvrSenO2UsDio                                     */
/*   3 / Clu_SdlFast_AcqnCluPedDio                                            */
/*   4 / Oil_SdlMid_OilPresAcqDio                                             */
/*   5 / Gear_SdlFast_StrtLockAcqDio                                          */
/*   6 / Brk_SdlMid_DiagBrkPedDio                                             */
/*   7 / STT_SdlFast_KeyPushInfoDio                                           */
/*   8 / CoFan_SdlMid_AcqCmdCoFan                                             */
/*   9 / EcuSt_SdlFast_AcqWkuSigDio                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6509298 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQCMDDIO/ACQCMDDIO_SCH3.C_v      $*/
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
/* !Function    :  HeatSenO2_EveKOf_DrvrSenO2UsDio                            */
/* !Description :  Evénement Clé On -> Off.                                   */
/* !Number      :  SCH3.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidSenO2Us();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveKOf_DrvrSenO2UsDio                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveKOf_DrvrSenO2UsDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidSenO2Us();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DrvrSenO2UsDio                           */
/* !Description :  Récurrence rapide de la fonction HeatSenO2.                */
/* !Number      :  SCH3.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidSenO2Us();                                  */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DrvrSenO2UsDio                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DrvrSenO2UsDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidSenO2Us();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlFast_AcqnCluPedDio                                  */
/* !Description :  Moniteur d'acquisition de l'embrayage.                     */
/* !Number      :  SCH3.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidAcqDioClu();                                */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_SdlFast_AcqnCluPedDio                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlFast_AcqnCluPedDio(void)
{
   boolean bLocalFlowMng_bCluSwtEna;


   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (bLocalFlowMng_bCluSwtEna != 0)
      {
         ACQCMDDIO_vidAcqDioClu();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlMid_OilPresAcqDio                                   */
/* !Description :  Moniteur moyen.                                            */
/* !Number      :  SCH3.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidAcqDioOil();                                */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlMid_OilPresAcqDio                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlMid_OilPresAcqDio(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;


   VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bOilPropPresAcq == 0)
      {
         ACQCMDDIO_vidAcqDioOil();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_SdlFast_StrtLockAcqDio                                */
/* !Description :  Moniteur rapide                                            */
/* !Number      :  SCH3.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidAcqDioGear();                               */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Gear_SdlFast_StrtLockAcqDio                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_SdlFast_StrtLockAcqDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidAcqDioGear();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlMid_DiagBrkPedDio                                   */
/* !Description :  Moniteur du diagnostic acquisition frein.                  */
/* !Number      :  SCH3.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidAcqDioBrk();                                */
/*  input boolean Cf_bSecBrkPedPrss;                                          */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_SdlMid_DiagBrkPedDio                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlMid_DiagBrkPedDio(void)
{
   boolean bLocalCf_bSecBrkPedPrss;
   boolean bLocalIntegratioElectronique;


   VEMS_vidGET(Cf_bSecBrkPedPrss, bLocalCf_bSecBrkPedPrss);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (  (bLocalCf_bSecBrkPedPrss != 0)
         && (bLocalIntegratioElectronique == 0))
      {
         ACQCMDDIO_vidAcqDioBrk();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STT_SdlFast_KeyPushInfoDio                                 */
/* !Description :  Moniteur rapide.                                           */
/* !Number      :  SCH3.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidAcqDioSTT();                                */
/*  input boolean ECU_bWkuMain;                                               */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : STT_SdlFast_KeyPushInfoDio                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STT_SdlFast_KeyPushInfoDio(void)
{
   boolean bLocalECU_bWkuMain;


   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      if (bLocalECU_bWkuMain != 0)
      {
         ACQCMDDIO_vidAcqDioSTT();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_AcqCmdCoFan                                   */
/* !Description :  Moniteur moyen de la fonction CoFan.                       */
/* !Number      :  SCH3.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidAcqCmdCoFan();                              */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlMid_AcqCmdCoFan                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_AcqCmdCoFan(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidAcqCmdCoFan();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlFast_AcqWkuSigDio                                 */
/* !Description :  Moniteur rapide de l'acquisition clé                       */
/* !Number      :  SCH3.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQCMDDIO_vidAcqDioKey();                                */
/*  input uint8 ACQCMDDIO_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_SdlFast_AcqWkuSigDio                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlFast_AcqWkuSigDio(void)
{
   if (ACQCMDDIO_u8Inhib != 0x5A)
   {
      ACQCMDDIO_vidAcqDioKey();
   }
}
/*------------------------------- end of file --------------------------------*/