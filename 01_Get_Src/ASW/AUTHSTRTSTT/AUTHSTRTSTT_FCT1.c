/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AUTHSTRTSTT                                             */
/* !Description     : AUTHSTRTSTT Component                                   */
/*                                                                            */
/* !Module          : AUTHSTRTSTT                                             */
/* !Description     : Pilotage Autorisation de redémarrage STT                */
/*                                                                            */
/* !File            : AUTHSTRTSTT_FCT1.C                                      */
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
/*   1 / AUTHSTRTSTT_vidInitialisation                                        */
/*   2 / AUTHSTRTSTT_vidCallMng                                               */
/*   3 / AUTHSTRTSTT_vidInhCrkAlt                                             */
/*   4 / AUTHSTRTSTT_vidInhCrkAltHw                                           */
/*   5 / AUTHSTRTSTT_vidDiagnostic                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6525148 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/AUTHSTRTSTT/AUTHSTRTSTT_FCT1.C_v  $*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   22 May 2014 $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "AUTHSTRTSTT.h"
#include "AUTHSTRTSTT_L.h"
#include "AUTHSTRTSTT_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AUTHSTRTSTT_vidInitialisation                              */
/* !Description :  L’état ouvert de la commande « autorisation redémarrage STT*/
/*                 » correspond à la valeur 1                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EngSt_bInhCrkAlt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AUTHSTRTSTT_vidInitialisation(void)
{
   EngSt_bInhCrkAlt = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AUTHSTRTSTT_vidCallMng                                     */
/* !Description :  cette fonction sert a déclencher les evenement sous        */
/*                 conditions                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_12_01002.02                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AUTHSTRTSTT_vidInhCrkAlt();                              */
/*  extf argret void AUTHSTRTSTT_vidInhCrkAltHw();                            */
/*  extf argret void AUTHSTRTSTT_vidDiagnostic();                             */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean EngSt_bAcvAuthStrtSTTAcq;                                   */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean Ext_bDgoScp_bInhCrkAltHw;                                   */
/*  input boolean Ext_bMonRunScp_bInhCrkAltHw;                                */
/*  input boolean Ext_bDgoScg_bInhCrkAltHw;                                   */
/*  input boolean Ext_bMonRunScg_bInhCrkAltHw;                                */
/*  input boolean Ext_bDgoOc_bInhCrkAltHw;                                    */
/*  input boolean Ext_bMonRunOc_bInhCrkAltHw;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AUTHSTRTSTT_vidCallMng(void)
{
   boolean bLocalDIAGCAN_IntegElec;
   boolean bLocalEngSt_bAcvAuthStrtSTTAcq;
   boolean bLocalECU_bWkuMain;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_IntegElec);
   VEMS_vidGET(EngSt_bAcvAuthStrtSTTAcq, bLocalEngSt_bAcvAuthStrtSTTAcq);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   if (  (bLocalDIAGCAN_IntegElec == 0)
      && (bLocalEngSt_bAcvAuthStrtSTTAcq != 0)
      && (bLocalECU_bWkuMain != 0))
   {
      AUTHSTRTSTT_vidInhCrkAlt();
      AUTHSTRTSTT_vidInhCrkAltHw();
      AUTHSTRTSTT_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_SCP_BINHCRKALTHW,
                   Ext_bDgoScp_bInhCrkAltHw,
                   Ext_bMonRunScp_bInhCrkAltHw,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_BINHCRKALTHW,
                   Ext_bDgoScg_bInhCrkAltHw,
                   Ext_bMonRunScg_bInhCrkAltHw,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_BINHCRKALTHW,
                   Ext_bDgoOc_bInhCrkAltHw,
                   Ext_bMonRunOc_bInhCrkAltHw,
                   DIAG_DISPO);

   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AUTHSTRTSTT_vidInhCrkAlt                                   */
/* !Description :  On copie la demande d’inhibition du driver de démarrage par*/
/*                 la safety, dans une variable interne à la fonction qui     */
/*                 servira à construire la variable de pilotage du driver de  */
/*                 redémarrage STT.                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bInhSTTCord;                                        */
/*  output boolean EngSt_bInhCrkAlt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AUTHSTRTSTT_vidInhCrkAlt(void)
{
   boolean bLocalSftyMgt_bInhSTTCord;


   VEMS_vidGET(SftyMgt_bInhSTTCord, bLocalSftyMgt_bInhSTTCord);
   EngSt_bInhCrkAlt = bLocalSftyMgt_bInhSTTCord;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AUTHSTRTSTT_vidInhCrkAltHw                                 */
/* !Description :  cette fonction permet de Piloter l'actionneur              */
/*                 d'autorisation de redémarrage STT                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_12_01002_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bInhCrkAltHwInv_C;                                      */
/*  input boolean EngSt_bInhCrkAlt;                                           */
/*  input boolean EngSt_bInhCrkAltHw;                                         */
/*  output boolean EngSt_bInhCrkAltHw;                                        */
/*  output boolean Cmde_autorisation_redem_stt_tor;                           */
/*  output boolean Ext_bInhCrkAltHw;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AUTHSTRTSTT_vidInhCrkAltHw(void)
{
   if (Ext_bInhCrkAltHwInv_C != 0)
   {
      EngSt_bInhCrkAltHw = EngSt_bInhCrkAlt;
   }
   else
   {
      if (EngSt_bInhCrkAlt != 0)
      {
         EngSt_bInhCrkAltHw = 0;
      }
      else
      {
         EngSt_bInhCrkAltHw = 1;
      }
   }
   VEMS_vidSET(Cmde_autorisation_redem_stt_tor, EngSt_bInhCrkAltHw);
   if (EngSt_bInhCrkAlt != 0)
   {
      VEMS_vidSET(Ext_bInhCrkAltHw, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bInhCrkAltHw, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AUTHSTRTSTT_vidDiagnostic                                  */
/* !Description :  cette fonction spécifie L'état de la commande              */
/*                 Ext_bInhCrkAltHw pour autoriser le diagnostic              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_E_12_01002_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bInhCrkAltHw;                                           */
/*  input boolean Dft_scp_cmdautoredemstt;                                    */
/*  input boolean Dena_scp_cmdautoredemstt;                                   */
/*  input boolean Dft_scg_cmdautoredemstt;                                    */
/*  input boolean Dena_scg_cmdautoredemstt;                                   */
/*  input boolean Dft_oc_cmdautoredemstt;                                     */
/*  input boolean Dena_oc_cmdautoredemstt;                                    */
/*  output boolean Ext_bMonRunScp_bInhCrkAltHw;                               */
/*  output boolean Ext_bDgoScp_bInhCrkAltHw;                                  */
/*  output boolean Ext_bMonRunScg_bInhCrkAltHw;                               */
/*  output boolean Ext_bDgoScg_bInhCrkAltHw;                                  */
/*  output boolean Ext_bMonRunOc_bInhCrkAltHw;                                */
/*  output boolean Ext_bDgoOc_bInhCrkAltHw;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AUTHSTRTSTT_vidDiagnostic(void)
{
   boolean bLocalInhDiag_bInhCrkAlt;
   boolean bLocalExt_bInhCrkAltHw;
   boolean bLocalDft_scp_cmdautoredemstt;
   boolean bLocalDena_scp_cmdautoredemstt;
   boolean bLocalDft_scg_cmdautoredemstt;
   boolean bLocalDena_scg_cmdautoredemstt;
   boolean bLocalDft_oc_cmdautoredemstt;
   boolean bLocalDena_oc_cmdautoredemstt;


   bLocalInhDiag_bInhCrkAlt = GDGAR_bGetFRM(FRM_FRM_INHDIAG_BINHCRKALT);
   VEMS_vidGET(Ext_bInhCrkAltHw, bLocalExt_bInhCrkAltHw);
   VEMS_vidGET(Dft_scp_cmdautoredemstt, bLocalDft_scp_cmdautoredemstt);
   VEMS_vidGET(Dena_scp_cmdautoredemstt, bLocalDena_scp_cmdautoredemstt);
   VEMS_vidGET(Dft_scg_cmdautoredemstt, bLocalDft_scg_cmdautoredemstt);
   VEMS_vidGET(Dena_scg_cmdautoredemstt, bLocalDena_scg_cmdautoredemstt);
   VEMS_vidGET(Dft_oc_cmdautoredemstt, bLocalDft_oc_cmdautoredemstt);
   VEMS_vidGET(Dena_oc_cmdautoredemstt, bLocalDena_oc_cmdautoredemstt);

   if (  (bLocalDena_scp_cmdautoredemstt != 0)
      && (bLocalInhDiag_bInhCrkAlt == 0)
      && (bLocalExt_bInhCrkAltHw != 0))
   {
      Ext_bMonRunScp_bInhCrkAltHw = 1;
      if (bLocalDft_scp_cmdautoredemstt != 0)
      {
         Ext_bDgoScp_bInhCrkAltHw = 1;
      }
      else
      {
         Ext_bDgoScp_bInhCrkAltHw = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_bInhCrkAltHw = 0;
      Ext_bDgoScp_bInhCrkAltHw = 0;
   }
   if (  (bLocalDena_scg_cmdautoredemstt != 0)
      && (bLocalInhDiag_bInhCrkAlt == 0)
      && (bLocalExt_bInhCrkAltHw == 0))
   {
      Ext_bMonRunScg_bInhCrkAltHw = 1;
      if (bLocalDft_scg_cmdautoredemstt != 0)
      {
         Ext_bDgoScg_bInhCrkAltHw = 1;
      }
      else
      {
         Ext_bDgoScg_bInhCrkAltHw = 0;
      }
   }
   else
   {
      Ext_bMonRunScg_bInhCrkAltHw = 0;
      Ext_bDgoScg_bInhCrkAltHw = 0;
   }
   if (  (bLocalDena_oc_cmdautoredemstt != 0)
      && (bLocalInhDiag_bInhCrkAlt == 0)
      && (bLocalExt_bInhCrkAltHw == 0))
   {
      Ext_bMonRunOc_bInhCrkAltHw = 1;
      if (bLocalDft_oc_cmdautoredemstt != 0)
      {
         Ext_bDgoOc_bInhCrkAltHw = 1;
      }
      else
      {
         Ext_bDgoOc_bInhCrkAltHw = 0;
      }
   }
   else
   {
      Ext_bMonRunOc_bInhCrkAltHw = 0;
      Ext_bDgoOc_bInhCrkAltHw = 0;
   }
}

/*---------------------------------End Of File--------------------------------*/