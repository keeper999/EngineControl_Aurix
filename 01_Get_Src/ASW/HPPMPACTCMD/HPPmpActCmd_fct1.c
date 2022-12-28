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
/* !File            : HPPMPACTCMD_FCT1.c                                      */
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
/*   1 / HPPmpActCmd_vidHPPmpActCmd_Init                                      */
/*   2 / HPPmpActCmd_vidHPPmpActCmd_DiagEl                                    */
/*   3 / HPPmpActCmd_vidbStopHPPmpActCmd                                      */
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
#include "MATHSRV.h"
#include "HPPMPACTCMD.h"
#include "HPPMPACTCMD_L.h"
#include "HPPMPACTCMD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPmpActCmd_vidHPPmpActCmd_Init                            */
/* !Description :  Fonction de désactivation du driver de la pompe HP au      */
/*                 calage.                                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bStoHPPmpActCmd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPmpActCmd_vidHPPmpActCmd_Init(void)
{
   VEMS_vidSET(Ext_bStoHPPmpActCmd, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPmpActCmd_vidHPPmpActCmd_DiagEl                          */
/* !Description :  Le diagnostic, fait par le LdB, fournit une information de */
/*                 panne présente, utilisée par la gestion des défauts        */
/*                 unitaires pour générer les éventuelles demandes de         */
/*                 reconfiguration et définir les modes dégradés associés.    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_HPPmpActCmd;                                         */
/*  input boolean Dft_scg_HPPmpActCmd;                                        */
/*  input boolean Dft_scp_HPPmpActCmd;                                        */
/*  input boolean Dft_ovld_HPPmpActCmd;                                       */
/*  input boolean Dena_oc_HPPmpActCmd;                                        */
/*  input boolean Dena_scg_HPPmpActCmd;                                       */
/*  input boolean Dena_scp_HPPmpActCmd;                                       */
/*  input boolean Dena_ovld_HPPmpActCmd;                                      */
/*  output boolean Ext_bDgoOc_HPPmpActCmd;                                    */
/*  output boolean Ext_bDgoScp_HPPmpActCmd;                                   */
/*  output boolean Ext_bDgoOvld_HPPmpActCmd;                                  */
/*  output boolean Ext_bMonRunOc_HPPmpActCmd;                                 */
/*  output boolean Ext_bMonRunScp_HPPmpActCmd;                                */
/*  output boolean Ext_bMonRunOvld_HPPmpActCmd;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPmpActCmd_vidHPPmpActCmd_DiagEl(void)
{
   boolean bLocalDft_oc_HPPmpActCmd;
   boolean bLocalDft_scg_HPPmpActCmd;
   boolean bLocalDft_scp_HPPmpActCmd;
   boolean bLocalDft_ovld_HPPmpActCmd;
   boolean bLocalDena_oc_HPPmpActCmd;
   boolean bLocalDena_scg_HPPmpActCmd;
   boolean bLocalDena_scp_HPPmpActCmd;
   boolean bLocalDena_ovld_HPPmpActCmd;
   boolean bLocalInhHPPmpActCmdDiagEl;
   boolean bLocalInhDiagHPPmpActCmdOvld;


   bLocalInhHPPmpActCmdDiagEl = GDGAR_bGetFRM(FRM_FRM_INHHPPMPACTCMDDIAGEL);
   bLocalInhDiagHPPmpActCmdOvld = GDGAR_bGetFRM(FRM_FRM_INHDIAGHPPMPACTCMDOVLD);
   VEMS_vidGET(Dft_oc_HPPmpActCmd, bLocalDft_oc_HPPmpActCmd);
   VEMS_vidGET(Dft_scg_HPPmpActCmd, bLocalDft_scg_HPPmpActCmd);
   VEMS_vidGET(Dft_scp_HPPmpActCmd, bLocalDft_scp_HPPmpActCmd);
   VEMS_vidGET(Dft_ovld_HPPmpActCmd, bLocalDft_ovld_HPPmpActCmd);
   VEMS_vidGET(Dena_oc_HPPmpActCmd, bLocalDena_oc_HPPmpActCmd);
   VEMS_vidGET(Dena_scg_HPPmpActCmd, bLocalDena_scg_HPPmpActCmd);
   VEMS_vidGET(Dena_scp_HPPmpActCmd, bLocalDena_scp_HPPmpActCmd);
   VEMS_vidGET(Dena_ovld_HPPmpActCmd, bLocalDena_ovld_HPPmpActCmd);

   if (  (bLocalDft_oc_HPPmpActCmd != 0)
      || (bLocalDft_scg_HPPmpActCmd != 0))
   {
      Ext_bDgoOc_HPPmpActCmd = 1;
   }
   else
   {
      Ext_bDgoOc_HPPmpActCmd = 0;
   }
   Ext_bDgoScp_HPPmpActCmd = bLocalDft_scp_HPPmpActCmd;
   Ext_bDgoOvld_HPPmpActCmd = bLocalDft_ovld_HPPmpActCmd;
   if (bLocalInhHPPmpActCmdDiagEl == 0)
   {
      if (  (bLocalDena_oc_HPPmpActCmd != 0)
         || (bLocalDena_scg_HPPmpActCmd != 0))
      {
         Ext_bMonRunOc_HPPmpActCmd = 1;
      }
      else
      {
         Ext_bMonRunOc_HPPmpActCmd = 0;
      }
      if (bLocalDena_scp_HPPmpActCmd != 0)
      {
         Ext_bMonRunScp_HPPmpActCmd = 1;
      }
      else
      {
         Ext_bMonRunScp_HPPmpActCmd = 0;
      }
   }
   else
   {
      Ext_bMonRunOc_HPPmpActCmd = 0;
      Ext_bMonRunScp_HPPmpActCmd = 0;
   }
   if (  (bLocalDena_ovld_HPPmpActCmd != 0)
      && (bLocalInhDiagHPPmpActCmdOvld == 0))
   {
      Ext_bMonRunOvld_HPPmpActCmd = 1;
   }
   else
   {
      Ext_bMonRunOvld_HPPmpActCmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HPPmpActCmd_vidbStopHPPmpActCmd                            */
/* !Description :  Cette fonction retourne l’état du driver de la pompe       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 AcquiState_stHPPmpActCmd;                                     */
/*  output boolean Ext_bStoHPPmpActCmd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HPPmpActCmd_vidbStopHPPmpActCmd(void)
{
   uint8 u8LocalAcquiState_stHPPmpActCmd;


   VEMS_vidGET(AcquiState_stHPPmpActCmd, u8LocalAcquiState_stHPPmpActCmd);

   if (u8LocalAcquiState_stHPPmpActCmd == E_OK)
   {
      VEMS_vidSET(Ext_bStoHPPmpActCmd, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bStoHPPmpActCmd, 0);
   }
}

/*------------------------------end of file-----------------------------------*/