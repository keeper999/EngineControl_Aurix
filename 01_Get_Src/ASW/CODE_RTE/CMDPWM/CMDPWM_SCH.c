/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CMDPWM                                                  */
/* !Description     : CMDPWM component.                                       */
/*                                                                            */
/* !Module          : CMDPWM                                                  */
/* !Description     : SPECIFICATION DES COMMANDES EN PWM  ENVOYEES AU BSW     */
/*                                                                            */
/* !File            : CMDPWM_SCH.C                                            */
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
/*   1 / VlvAct_SdlFast_CmdPwmVlvActIn                                        */
/*   2 / VlvAct_SdlFast_CmdPwmVlvActEx                                        */
/*   3 / FuPmp_SdlFast_CmdPwmPropFuPmp                                        */
/*   4 / Cstr_EveRst_CmdPwmCstr                                               */
/*   5 / Cstr_SdlMid_CmdPwmCstr                                               */
/*   6 / Ext_EveRst_CmdPwm                                                    */
/*   7 / Thr_EveClcnServo_CmdPwmThrCmd                                        */
/*   8 / Thr_EveRst_CmdPwmThrCmd                                              */
/*   9 / Thr_SdlMid_CmdPwmThrCmd                                              */
/*   10 / CoFan_SdlSlow_CmdPmwECTCmd                                          */
/*   11 / CoFan_SdlMid_CmdPwmCoFan                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6669891 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CMDPWM/CMDPWM_SCH.c_v             $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   29 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   29 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "CMDPWM.h"
#include "CMDPWM_L.h"
#include "CMDPWM_IM.h"
#include "CMDPWM_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_CmdPwmVlvActIn                              */
/* !Description :  Evènement moniteur rapide de la fonction VVT admission.    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidCmdPwmVlvActIn();                              */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_CmdPwmVlvActIn                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_CmdPwmVlvActIn(void)
{
   if (CMDPWM_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         CMDPWM_vidCmdPwmVlvActIn();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_CmdPwmVlvActEx                              */
/* !Description :  Evènement moniteur rapide de la fonction VVT échappement.  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidCmdPwmVlvActEx();                              */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_CmdPwmVlvActEx                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_CmdPwmVlvActEx(void)
{
   if (CMDPWM_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         CMDPWM_vidCmdPwmVlvActEx();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuPmp_SdlFast_CmdPwmPropFuPmp                              */
/* !Description :  Evènement moniteur rapide de la fonction FuPmp.            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWM_vidCmdPwmPropFuPmp();                             */
/*  input boolean Ctrl_bAcv_FuTnkPmp;                                         */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input boolean ECU_bImmoUnlockWkuSt;                                       */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuPmp_SdlFast_CmdPwmPropFuPmp                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuPmp_SdlFast_CmdPwmPropFuPmp(void)
{
   boolean bLocalCtrl_bAcv_FuTnkPmp;
   boolean bLocalECU_bWkuMain;
   boolean bLocalUCE_bPwrlAcv;
   boolean bLocalECU_bImmoUnlockWkuSt;

   VEMS_vidGET(Ctrl_bAcv_FuTnkPmp, bLocalCtrl_bAcv_FuTnkPmp);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);

   if (CMDPWM_u8Inhib != 0x5A)
   {
      if (  (bLocalCtrl_bAcv_FuTnkPmp != 0)
         || (  (bLocalECU_bWkuMain != 0)
            && (bLocalUCE_bPwrlAcv != 0)
            && (bLocalECU_bImmoUnlockWkuSt != 0)))
      {
         CMDPWM_vidCmdPwmPropFuPmp();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_EveRst_CmdPwmCstr                                     */
/* !Description :  Evènement reset du calculateur.                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidCmdPwmCstr();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_EveRst_CmdPwmCstr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_EveRst_CmdPwmCstr(void)
{
   CMDPWM_vidCmdPwmCstr();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cstr_SdlMid_CmdPwmCstr                                     */
/* !Description :  Evènement moniteur moyen pour la fonction purge canister.  */
/* !Number      :  SCH.5                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidCmdPwmCstr();                                  */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cstr_SdlMid_CmdPwmCstr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cstr_SdlMid_CmdPwmCstr(void)
{
   if (CMDPWM_u8Inhib != 0x5A)
   {
      CMDPWM_vidCmdPwmCstr();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_EveRst_CmdPwm                                          */
/* !Description :  Evénement reset de CmdPwm                                  */
/* !Number      :  SCH.6                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidInitOutput();                                  */
/*  extf argret void CMDPWM_vidF00_Init_CmdPwmVlvAct();                       */
/*  extf argret void CMDPWM_vidF00InitCmdPwmPropFuPmP();                      */
/*  extf argret void CMDPWM_vidF00_Init_CmdPwmThrCmd();                       */
/*  extf argret void CMDPWM_vidF00_Init_CmdPwmECTCmd();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Ext_EveRst_CmdPwm                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_EveRst_CmdPwm(void)
{
   CMDPWM_vidInitOutput();
   CMDPWM_vidF00_Init_CmdPwmVlvAct();
   CMDPWM_vidF00InitCmdPwmPropFuPmP();
   CMDPWM_vidF00_Init_CmdPwmThrCmd();
   CMDPWM_vidF00_Init_CmdPwmECTCmd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_CmdPwmThrCmd                              */
/* !Description :  Evénement de calcul de l'asservissement papillon motorisé  */
/*                 (front montant du signal PWM de commande)                  */
/* !Number      :  SCH.7                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidCmd_tpac();                                    */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_CmdPwmThrCmd                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_CmdPwmThrCmd(void)
{
   if (CMDPWM_u8Inhib != 0x5A)
   {
      CMDPWM_vidCmd_tpac();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_CmdPwmThrCmd                                    */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.8                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidInitOutput();                                  */
/*  extf argret void CMDPWM_vidDriverInh();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_CmdPwmThrCmd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_CmdPwmThrCmd(void)
{
   CMDPWM_vidInitOutput();
   CMDPWM_vidDriverInh();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlMid_CmdPwmThrCmd                                    */
/* !Description :  Moniteur moyen de la fonction papillon                     */
/* !Number      :  SCH.9                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CMDPWM_vidDriverInh();                                   */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlMid_CmdPwmThrCmd                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlMid_CmdPwmThrCmd(void)
{
   if (CMDPWM_u8Inhib != 0x5A)
   {
      CMDPWM_vidDriverInh();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlSlow_CmdPmwECTCmd                                 */
/* !Description :  Moniteur lent de la fonction CoFan                         */
/* !Number      :  SCH.10                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWM_vidCmdPwmECTCmd();                                */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Ctrl_bAcv_ECTReq;                                           */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlSlow_CmdPmwECTCmd                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlSlow_CmdPmwECTCmd(void)
{
   boolean  bLocalECU_bWkuMain;
   boolean  bLocalCtrl_bAcv_ECTReq;


   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   VEMS_vidGET(Ctrl_bAcv_ECTReq, bLocalCtrl_bAcv_ECTReq);

   if (CMDPWM_u8Inhib != 0x5A)
   {
      if (  (bLocalECU_bWkuMain != 0)
         && (bLocalCtrl_bAcv_ECTReq != 0))
      {
         CMDPWM_vidCmdPwmECTCmd();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoFan_SdlMid_CmdPwmCoFan                                   */
/* !Description :  Moniteur moyen de la fonction CoFan                        */
/* !Number      :  SCH.11                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CMDPWM_vidCmdPwmCoFan();                                 */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*  input uint8 CMDPWM_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoFan_SdlMid_CmdPwmCoFan                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoFan_SdlMid_CmdPwmCoFan(void)
{
   uint8  u8LocalCf_cooling_fan_equipment;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCf_cooling_fan_equipment);

   if (CMDPWM_u8Inhib != 0x5A)
   {
      if (u8LocalCf_cooling_fan_equipment == EQUIPMENT_C)
      {
         CMDPWM_vidCmdPwmCoFan();
      }
   }
}

/*------------------------------- end of file --------------------------------*/