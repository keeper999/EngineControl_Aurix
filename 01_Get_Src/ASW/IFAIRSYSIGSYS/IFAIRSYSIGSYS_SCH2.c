/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_SCH2.C                                    */
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
/*   1 / Can_EveRst_FHCanF349If_2                                             */
/*   2 / Cf_SdlSlow_IfAirSys                                                  */
/*   3 / Can_SdlSlow_FHCanF38DIf                                              */
/*   4 / KnkTreat_EveRst_KnkMgrCorRblIf                                       */
/*   5 / Can_EveRxn349_FHCanF349If_2                                          */
/*   6 / SenO2Us_SdlFast_UpLsAcqIf                                            */
/*   7 / HeatSenO2_SdlFast_HeatSenO2MonIf                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF349If_2                                   */
/* !Description :  Evènement reset de l'ECU.                                  */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidIntfacIsCanIf2();                       */
/*  input boolean Ctrl_bTraNoTarGear;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF349If_2                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF349If_2(void)
{
   boolean  bLocalCtrl_bTraNoTarGear;


   VEMS_vidGET(Ctrl_bTraNoTarGear, bLocalCtrl_bTraNoTarGear);
   if (bLocalCtrl_bTraNoTarGear != 0)
   {
      IFAIRSYSIGSYS_vidIntfacIsCanIf2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlSlow_IfAirSys                                        */
/* !Description :  Moniteur lent pour la fonction                             */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidDuree_Fctmt();                          */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlSlow_IfAirSys                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlSlow_IfAirSys(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidDuree_Fctmt();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlSlow_FHCanF38DIf                                    */
/* !Description :  Moniteur lent pour la fonction FH CAN F38Dh                */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidIntfacIsCanIf15();                      */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlSlow_FHCanF38DIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlSlow_FHCanF38DIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidIntfacIsCanIf15();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkTreat_EveRst_KnkMgrCorRblIf                             */
/* !Description :  Evenement reset du calculateur                             */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidOutInjCutOffPtl();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : KnkTreat_EveRst_KnkMgrCorRblIf                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkTreat_EveRst_KnkMgrCorRblIf(void)
{
   IFAIRSYSIGSYS_vidOutInjCutOffPtl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn349_FHCanF349If_2                                */
/* !Description :  Evenement de reception de la trame 349.                    */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYSIGSYS_vidIntfacIsCanIf2();                       */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*  input boolean Ctrl_bTraNoTarGear;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn349_FHCanF349If_2                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn349_FHCanF349If_2(void)
{
   boolean  bLocalCtrl_bTraNoTarGear;


   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bTraNoTarGear, bLocalCtrl_bTraNoTarGear);
      if (bLocalCtrl_bTraNoTarGear != 0)
      {
         IFAIRSYSIGSYS_vidIntfacIsCanIf2();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlFast_UpLsAcqIf                                  */
/* !Description :  Moniteur rapide pour la fonction sonde amont               */
/* !Number      :  SCH2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidECU1();                                 */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger     : SenO2Us_SdlFast_UpLsAcqIf                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlFast_UpLsAcqIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidECU1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_HeatSenO2MonIf                           */
/* !Description :  Moniteur rapide pour la fonction HeatSenO2                 */
/* !Number      :  SCH2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYSIGSYS_vidEndDiagDsHeat();                        */
/*  input uint8 IFAIRSYSIGSYS_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_HeatSenO2MonIf(void)
{
   if (IFAIRSYSIGSYS_u8Inhib != 0x5A)
   {
      IFAIRSYSIGSYS_vidEndDiagDsHeat();
   }
}

/*-------------------------------- end of file -------------------------------*/