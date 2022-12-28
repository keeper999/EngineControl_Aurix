/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYS                                                */
/* !Description     : IFAIRSYS Component                                      */
/*                                                                            */
/* !Module          : IFAIRSYS                                                */
/* !Description     : INTERFACE DE LA CHAINE D AIR                            */
/*                                                                            */
/* !File            : IFAIRSYS_SCH1.C                                         */
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
/*   1 / IFAIRSYS_vidEntryInit                                                */
/*   2 / AccP_SdlFast_StIf                                                    */
/*   3 / Crkmgt_sdlFast_tqStructMngtIf2                                       */
/*   4 / Thr_EveClcnServo_CorrdPosnIf2                                        */
/*   5 / VehSpd_SdlFast_VehMngIf                                              */
/*   6 / Inj_SdlFast_FuTiRunIf2                                               */
/*   7 / Inj_EveRst_FuTiRunIf2                                                */
/*   8 / AirPres_Eve14TDC_SpgPresAcqif                                        */
/*   9 / AirPres_SdlMid_SpgPresAcqif                                          */
/*   10 / AirPres_EveRst_SpgPresAcqif                                         */
/*   11 / AirT_EveRst_AcqAirTIfAir                                            */
/*   12 / AirT_SdlMid_AcqAirTIfAir                                            */
/*   13 / Sync_EveRst_CkMngIfIfAir                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5199971 / 07                                        */
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
#include "IFAIRSYS.h"
#include "IFAIRSYS_L.h"
#include "IFAIRSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYS_vidEntryInit                                      */
/* !Description :  Evénement reset ECU du module d'interface                  */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IFAIRSYS_vidEntryInit                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYS_vidEntryInit(void)
{
   IFAIRSYS_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_StIf                                          */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidAccP();                                      */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_StIf                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_StIf(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidAccP();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Crkmgt_sdlFast_tqStructMngtIf2                             */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidCrkMgt();                                    */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Crkmgt_sdlFast_tqStructMngtIf2                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Crkmgt_sdlFast_tqStructMngtIf2(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidCrkMgt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_CorrdPosnIf2                              */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidThr();                                       */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_CorrdPosnIf2                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_CorrdPosnIf2(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidThr();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VehSpd_SdlFast_VehMngIf                                    */
/* !Description :  eve d'interface.                                           */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidVehRun();                                    */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VehSpd_SdlFast_VehMngIf                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VehSpd_SdlFast_VehMngIf(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidVehRun();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_SdlFast_FuTiRunIf2                                     */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidInj();                                       */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_SdlFast_FuTiRunIf2                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_SdlFast_FuTiRunIf2(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidInj();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveRst_FuTiRunIf2                                      */
/* !Description :  Evènement.                                                 */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidInj();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveRst_FuTiRunIf2                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveRst_FuTiRunIf2(void)
{
   IFAIRSYS_vidInj();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_Eve14TDC_SpgPresAcqif                              */
/* !Description :  Evénement d'appel de tâche "quart de PMH" du CMM           */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYS_vidBoostPressure();                             */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_Eve14TDC_SpgPresAcqif                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_Eve14TDC_SpgPresAcqif(void)
{
   boolean bLocalCtrl_bAcv_pUsThr;
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);
      if (bLocalCtrl_bAcv_pUsThr != 0)
      {
         IFAIRSYS_vidBoostPressure();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_SpgPresAcqif                                */
/* !Description :  Moniteur moyen pour la fonction AirPres                    */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IFAIRSYS_vidBoostPressure();                             */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*  input boolean Ext_bRun;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_SpgPresAcqif                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_SpgPresAcqif(void)
{
   boolean bLocalCtrl_bAcv_pUsThr;
   boolean bLocalExt_bRun;


   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);
      if (  (bLocalExt_bRun == 0)
         && (bLocalCtrl_bAcv_pUsThr != 0))
      {
         IFAIRSYS_vidBoostPressure();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_SpgPresAcqif                                */
/* !Description :  Evènement_reset                                            */
/* !Number      :  SCH1.10                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidBoostPressure();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_SpgPresAcqif                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_SpgPresAcqif(void)
{
   IFAIRSYS_vidBoostPressure();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_EveRst_AcqAirTIfAir                                   */
/* !Description :  Evènement Reset                                            */
/* !Number      :  SCH1.11                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidmfAirMid2();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_EveRst_AcqAirTIfAir                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_EveRst_AcqAirTIfAir(void)
{
   IFAIRSYS_vidmfAirMid2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_SdlMid_AcqAirTIfAir                                   */
/* !Description :  Moniteur de module d'interface.                            */
/* !Number      :  SCH1.12                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidmfAirMid2();                                 */
/*  input uint8 IFAIRSYS_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_SdlMid_AcqAirTIfAir                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_SdlMid_AcqAirTIfAir(void)
{
   if (IFAIRSYS_u8Inhib != 0x5A)
   {
      IFAIRSYS_vidmfAirMid2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Sync_EveRst_CkMngIfIfAir                                   */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH1.13                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFAIRSYS_vidInitFilter();                                */
/*  extf argret void IFAIRSYS_vidNEngGrd();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Sync_EveRst_CkMngIfIfAir                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Sync_EveRst_CkMngIfIfAir(void)
{
   IFAIRSYS_vidInitFilter();
   IFAIRSYS_vidNEngGrd();
}
/*-------------------------------- end of file -------------------------------*/