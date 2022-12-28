/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HPPmpActCmd                                             */
/* !Description     : HPPmpActCmd component.                                  */
/*                                                                            */
/* !Module          : HPPmpActCmd                                             */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA POMPE CARBURANT HAUTE      */
/*                    PRESSION                                                */
/*                                                                            */
/* !File            : HPPMPACTCMD_SCH.c                                       */
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
/*   1 / PFuCtl_EveRst_HPPmpActCmd                                            */
/*   2 / PFuCtl_SdlMid_HPPmpActCmd                                            */
/*   3 / PFuCtl_EveRTSt_HPPmpActCmd                                           */
/*   4 / PFuCtl_EveSpl_HPPmpActCmd                                            */
/*   5 / PFuCtl_EveStTR_HPPmpActCmd                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6882952 / 01                                        */
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
#include "HPPMPACTCMD.h"
#include "HPPMPACTCMD_L.h"
#include "HPPMPACTCMD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveRst_HPPmpActCmd                                  */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_01639_002.01                                     */
/*                 VEMS_E_10_01639_003.02                                     */
/*                 VEMS_E_10_01639_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPmpActCmd_vidbStopHPPmpActCmd();                       */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PFuCtl_EveRst_HPPmpActCmd                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveRst_HPPmpActCmd(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);

   if (bLocalCtrl_bAcv_HpPmp != 0)
   {
      HPPmpActCmd_vidbStopHPPmpActCmd();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_SdlMid_HPPmpActCmd                                  */
/* !Description :  Moniteur moyen de la fonction de régulation de la pression */
/*                 rail                                                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_01639_002.01                                     */
/*                 VEMS_E_10_01639_003.02                                     */
/*                 VEMS_E_10_01639_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPmpActCmd_vidHPPmpActCmd_DiagEl();                     */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 HPPmpActCmd_u8Inhib;                                          */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*  input boolean Ext_bDgoOc_HPPmpActCmd;                                     */
/*  input boolean Ext_bMonRunOc_HPPmpActCmd;                                  */
/*  input boolean Ext_bDgoScp_HPPmpActCmd;                                    */
/*  input boolean Ext_bMonRunScp_HPPmpActCmd;                                 */
/*  input boolean Ext_bDgoOvld_HPPmpActCmd;                                   */
/*  input boolean Ext_bMonRunOvld_HPPmpActCmd;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PFuCtl_SdlMid_HPPmpActCmd                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_SdlMid_HPPmpActCmd(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPmpActCmd_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);

      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPmpActCmd_vidHPPmpActCmd_DiagEl();
         GDGAR_vidGdu(GD_DFT_OC_HPPMPACTCMD,
                     Ext_bDgoOc_HPPmpActCmd,
                     Ext_bMonRunOc_HPPmpActCmd,
                     DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCP_HPPMPACTCMD,
                     Ext_bDgoScp_HPPmpActCmd,
                     Ext_bMonRunScp_HPPmpActCmd,
                     DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OVLD_HPPMPACTCMD,
                     Ext_bDgoOvld_HPPmpActCmd,
                     Ext_bMonRunOvld_HPPmpActCmd,
                     DIAG_DISPO);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveRTSt_HPPmpActCmd                                 */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_01639_002.01                                     */
/*                 VEMS_E_10_01639_003.02                                     */
/*                 VEMS_E_10_01639_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPmpActCmd_vidHPPmpActCmd_Init();                       */
/*  input uint8 HPPmpActCmd_u8Inhib;                                          */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PFuCtl_EveRTSt_HPPmpActCmd                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveRTSt_HPPmpActCmd(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPmpActCmd_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);

      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPmpActCmd_vidHPPmpActCmd_Init();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveSpl_HPPmpActCmd                                  */
/* !Description :  Evènement "spill event" pour la commande pompe carburant HP*/
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_01639_002.01                                     */
/*                 VEMS_E_10_01639_003.02                                     */
/*                 VEMS_E_10_01639_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPmpActCmd_vidbStopHPPmpActCmd();                       */
/*  input uint8 HPPmpActCmd_u8Inhib;                                          */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PFuCtl_EveSpl_HPPmpActCmd                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveSpl_HPPmpActCmd(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPmpActCmd_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);

      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPmpActCmd_vidbStopHPPmpActCmd();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PFuCtl_EveStTR_HPPmpActCmd                                 */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_01639_002.01                                     */
/*                 VEMS_E_10_01639_003.02                                     */
/*                 VEMS_E_10_01639_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HPPmpActCmd_vidbStopHPPmpActCmd();                       */
/*  input uint8 HPPmpActCmd_u8Inhib;                                          */
/*  input boolean Ctrl_bAcv_HpPmp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : PFuCtl_EveStTR_HPPmpActCmd                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PFuCtl_EveStTR_HPPmpActCmd(void)
{
   boolean bLocalCtrl_bAcv_HpPmp;


   if (HPPmpActCmd_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_HpPmp, bLocalCtrl_bAcv_HpPmp);

      if (bLocalCtrl_bAcv_HpPmp != 0)
      {
         HPPmpActCmd_vidbStopHPPmpActCmd();
      }
   }
}
/*------------------------------end of file-----------------------------------*/