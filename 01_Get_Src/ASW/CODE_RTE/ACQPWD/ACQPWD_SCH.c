/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQPWD                                                  */
/* !Description     : ACQPWD Component                                        */
/*                                                                            */
/* !Module          : ACQPWD                                                  */
/* !Description     : Spécification des acquisitions rco (PwdHal)             */
/*                                                                            */
/* !File            : ACQPWD_SCH.C                                            */
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
/*   1 / Ext_EveRst_AcqPwd                                                    */
/*   2 / Clu_EveRst_CluPedFreqAcqPwd                                          */
/*   3 / Clu_SdlFast_CluPedFreqAcqPwd                                         */
/*   4 / FuPmp_EveRst_PropFuPmpPwd                                            */
/*   5 / FuPmp_SdlSlow_PropFuPmpDiagPwd                                       */
/*   6 / Gear_EveRst_NeutPosnAcqPwd                                           */
/*   7 / Gear_SdlFast_NeutPosnAcqPwd                                          */
/*   8 / CoFan_EveRst_CmdDiagCoFanAcqPwd                                      */
/*   9 / CoFan_SdlMid_CmdDiagCoFanAcqPwd                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6717056 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQPWD/ACQPWD_SCH.C_v             $*/
/* $Revision::   1.3      $$Author::   achebino       $$Date::   05 Sep 2014 $*/
/* $Author::   achebino                               $$Date::   05 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "ACQPWD.h"
#include "ACQPWD_L.h"
#include "ACQPWD_IM.h"
#include "ACQPWD_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_EveRst_AcqPwd                                          */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQPWD_vidInit();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Ext_EveRst_AcqPwd                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_EveRst_AcqPwd(void)
{
   ACQPWD_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_EveRst_CluPedFreqAcqPwd                                */
/* !Description :  Evénement reset.                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQPWD_vidInitFlowMng();                                 */
/*  input boolean FlowMng_bCluPropSnsrEna;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_EveRst_CluPedFreqAcqPwd                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_EveRst_CluPedFreqAcqPwd(void)
{
   boolean bLocalFlowMng_bCluPropSnsrEna;


   VEMS_vidGET(FlowMng_bCluPropSnsrEna, bLocalFlowMng_bCluPropSnsrEna);
   if (bLocalFlowMng_bCluPropSnsrEna != 0)
   {
      ACQPWD_vidInitFlowMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlFast_CluPedFreqAcqPwd                               */
/* !Description :  Moniteur rapide.                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQPWD_vidCluPedAcq();                                   */
/*  input uint8 ACQPWD_u8Inhib;                                               */
/*  input boolean FlowMng_bCluPropSnsrEna;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_SdlFast_CluPedFreqAcqPwd                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlFast_CluPedFreqAcqPwd(void)
{
   boolean bLocalFlowMng_bCluPropSnsrEna;


   if (ACQPWD_u8Inhib != 0x5A)
   {
      VEMS_vidGET(FlowMng_bCluPropSnsrEna, bLocalFlowMng_bCluPropSnsrEna);
      if (bLocalFlowMng_bCluPropSnsrEna != 0)
      {
         ACQPWD_vidCluPedAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_EveRst_PropFuPmpPwd                                  */
/* !Description :  ECU Event Reset.                                           */
/* !Number      :  SCH.4                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQPWD_vidInitFuPmp();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_EveRst_PropFuPmpPwd                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_EveRst_PropFuPmpPwd(void)
{
   ACQPWD_vidInitFuPmp();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlSlow_PropFuPmpDiagPwd                             */
/* !Description :  Moniteur lent de la fonction FuPmp.                        */
/* !Number      :  SCH.5                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQPWD_vidFuPmpDiagAcq();                                */
/*  input uint8 ACQPWD_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlSlow_PropFuPmpDiagPwd                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlSlow_PropFuPmpDiagPwd(void)
{
   if (ACQPWD_u8Inhib != 0x5A)
   {
      ACQPWD_vidFuPmpDiagAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_EveRst_NeutPosnAcqPwd                                 */
/* !Description :  Evénement reset.                                           */
/* !Number      :  SCH.6                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQPWD_vidInitNeutPosn();                                */
/*  input boolean Gear_bAcvNeutPosnAcq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Gear_EveRst_NeutPosnAcqPwd                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_EveRst_NeutPosnAcqPwd(void)
{
   boolean bLocalGear_bAcvNeutPosnAcq;


   VEMS_vidGET(Gear_bAcvNeutPosnAcq, bLocalGear_bAcvNeutPosnAcq);
   if (bLocalGear_bAcvNeutPosnAcq != 0)
   {
      ACQPWD_vidInitNeutPosn();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Gear_SdlFast_NeutPosnAcqPwd                                */
/* !Description :  Moniteur rapide de la fonction Gear.                       */
/* !Number      :  SCH.7                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQPWD_vidNeutPosnAcq();                                 */
/*  input uint8 ACQPWD_u8Inhib;                                               */
/*  input boolean Gear_bAcvNeutPosnAcq;                                       */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Gear_SdlFast_NeutPosnAcqPwd                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Gear_SdlFast_NeutPosnAcqPwd(void)
{
   boolean bLocalGear_bAcvNeutPosnAcq;
   boolean bLocalDIAGCAN_bIntegratioEl;


   if (ACQPWD_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Gear_bAcvNeutPosnAcq, bLocalGear_bAcvNeutPosnAcq);
      VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioEl);
      if (  (bLocalGear_bAcvNeutPosnAcq != 0)
         && (bLocalDIAGCAN_bIntegratioEl == 0))
      {
         ACQPWD_vidNeutPosnAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_EveRst_CmdDiagCoFanAcqPwd                            */
/* !Description :  Evénement reset                                            */
/* !Number      :  SCH.8                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQPWD_vidInitCmdDiagCoFan();                            */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_EveRst_CmdDiagCoFanAcqPwd                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_EveRst_CmdDiagCoFanAcqPwd(void)
{
   uint8 u8LocalCf_cooling_fan_equipment;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCf_cooling_fan_equipment);
   if (u8LocalCf_cooling_fan_equipment == EQUIPMENT_C)
   {
      ACQPWD_vidInitCmdDiagCoFan();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_CmdDiagCoFanAcqPwd                            */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH.9                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQPWD_vidCmdDiagCoFanAcq();                             */
/*  input uint8 ACQPWD_u8Inhib;                                               */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlMid_CmdDiagCoFanAcqPwd                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_CmdDiagCoFanAcqPwd(void)
{
   uint8 u8LocalCf_cooling_fan_equipment;


   if (ACQPWD_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCf_cooling_fan_equipment);
      if (u8LocalCf_cooling_fan_equipment == EQUIPMENT_C)
      {
         ACQPWD_vidCmdDiagCoFanAcq();
      }
   }
}
/*--------------------------------- end of file ------------------------------*/