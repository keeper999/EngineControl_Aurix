/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VSSNWDMTRACV                                            */
/* !Description     : VSSNWDMTRACV Component                                  */
/*                                                                            */
/* !Module          : VSSNWDMTRACV                                            */
/* !Description     : PILOTAGE DEMANDE MAINTIENT DMTR (DISPOSITIF DE MAINTIENT*/
/*                    EN TENSION RESEAU)                                      */
/*                                                                            */
/* !File            : VSSNWDMTRACV_FCT1.C                                     */
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
/*   1 / VSSNWDMTRACV_vidInitOutput                                           */
/*   2 / VSSNWDMTRACV_vidCallMng                                              */
/*   3 / VSSNWDMTRACV_vidDMTR_AcvReq                                          */
/*   4 / VSSNWDMTRACV_vidDMTR_Cmd                                             */
/*   5 / VSSNWDMTRACV_vidDiag                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6525894 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/VSSNWDMTRACV/VSSNWDMTRACV_FCT1.C_v$*/
/* $Revision::   1.5      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VSSNWDMTRACV.h"
#include "VSSNWDMTRACV_L.h"
#include "VSSNWDMTRACV_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSSNWDMTRACV_vidInitOutput                                 */
/* !Description :  Initialisation des variables                               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Commande_maintien_dmtr_tor;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSSNWDMTRACV_vidInitOutput(void)
{
   VEMS_vidSET(Commande_maintien_dmtr_tor, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSSNWDMTRACV_vidCallMng                                    */
/* !Description :  Si le flux de contrôle Pwr_bAcvDMTRAcq est actif alors la  */
/*                 fonction Software "demande de maintien tension réseau" est */
/*                 activée sinon elle n'est pas activée.                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_03595_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VSSNWDMTRACV_vidDMTR_AcvReq();                           */
/*  extf argret void VSSNWDMTRACV_vidDMTR_Cmd();                              */
/*  extf argret void VSSNWDMTRACV_vidDiag();                                  */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Pwr_bAcvDMTRAcq;                                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Ext_bDgoScp_VSSNwAcvReq;                                    */
/*  input boolean Ext_bMonRunScp_VSSNwAcvReq;                                 */
/*  input boolean Ext_bDgoScg_VSSNwAcvReq;                                    */
/*  input boolean Ext_bMonRunScg_VSSNwAcvReq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSSNWDMTRACV_vidCallMng(void)
{
   boolean bLocalPwr_bAcvDMTRAcq;
   boolean bLocalDIAGCAN_bIntegratioElect;


   VEMS_vidGET(Pwr_bAcvDMTRAcq, bLocalPwr_bAcvDMTRAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioElect);
   if (  (bLocalPwr_bAcvDMTRAcq != 0)
      && (bLocalDIAGCAN_bIntegratioElect == 0))
   {
      VSSNWDMTRACV_vidDMTR_AcvReq();
      VSSNWDMTRACV_vidDMTR_Cmd();
      VSSNWDMTRACV_vidDiag();
      GDGAR_vidGdu(GD_DFT_SCP_VSSNWACVREQ,
                   Ext_bDgoScp_VSSNwAcvReq,
                   Ext_bMonRunScp_VSSNwAcvReq,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_VSSNWACVREQ,
                   Ext_bDgoScg_VSSNwAcvReq,
                   Ext_bMonRunScg_VSSNwAcvReq,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSSNWDMTRACV_vidDMTR_AcvReq                                */
/* !Description :  la consigne de commande pour le driver de la demande de    */
/*                 maintien tension réseau DMTR                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_03595_002.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoStrtRStrt_bVSSNwAcvAuth;                                  */
/*  input boolean StaStrtMgt_bStaReq;                                         */
/*  output boolean Ext_bVSSNwAcvAuth;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSSNWDMTRACV_vidDMTR_AcvReq(void)
{
   boolean bLocalCoStrtRStrt_bVSSNwAcvAuth;
   boolean bLocalStaStrtMgt_bStaReq;


   VEMS_vidGET(CoStrtRStrt_bVSSNwAcvAuth, bLocalCoStrtRStrt_bVSSNwAcvAuth);
   VEMS_vidGET(StaStrtMgt_bStaReq, bLocalStaStrtMgt_bStaReq );
   if (  (bLocalCoStrtRStrt_bVSSNwAcvAuth != 0)
      && (bLocalStaStrtMgt_bStaReq != 0))
   {
      Ext_bVSSNwAcvAuth = 1;
   }
   else
   {
      Ext_bVSSNwAcvAuth = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSSNWDMTRACV_vidDMTR_Cmd                                   */
/* !Description :  Pour piloter l'actionneur, l'ECU ramène la masse (et oui,  */
/*                 du courant va circuler entre le 12V et la masse à travers  */
/*                 l'actionneur). L'état de la sortie est ' 0 '. Pour ne pas  */
/*                 piloter l'actionneur, l'ECU laisse la pin en circuit       */
/*                 ouvert.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bVSSNwAcvReqInv_C;                                      */
/*  input boolean Ext_bVSSNwAcvAuth;                                          */
/*  input boolean Ext_bVSSNwAcvReq;                                           */
/*  output boolean Ext_bVSSNwAcvReq;                                          */
/*  output boolean Commande_maintien_dmtr_tor;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSSNWDMTRACV_vidDMTR_Cmd(void)
{
   if (Ext_bVSSNwAcvReqInv_C != 0)
   {
      if (Ext_bVSSNwAcvAuth != 0)
      {
         Ext_bVSSNwAcvReq = 0;
      }
      else
      {
         Ext_bVSSNwAcvReq = 1;
      }
   }
   else
   {
      if (Ext_bVSSNwAcvAuth != 0)
      {
         Ext_bVSSNwAcvReq = 1;
      }
      else
      {
         Ext_bVSSNwAcvReq = 0;
      }
   }
   VEMS_vidSET(Commande_maintien_dmtr_tor, Ext_bVSSNwAcvReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSSNWDMTRACV_vidDiag                                       */
/* !Description :  Diagnostic de la panne Court-circuit                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_03595_003.03                                     */
/*                 VEMS_R_10_03595_004.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_scp_cmd_dmtr;                                           */
/*  input boolean Dena_scp_cmd_dmtr;                                          */
/*  input boolean Dft_scg_cmd_dmtr;                                           */
/*  input boolean Dena_scg_cmd_dmtr;                                          */
/*  input boolean Dft_oc_cmd_dmtr;                                            */
/*  input boolean Dena_oc_cmd_dmtr;                                           */
/*  input boolean Ext_bMonRunScp_VSSNwAcvReq;                                 */
/*  output boolean Ext_bMonRunScp_VSSNwAcvReq;                                */
/*  output boolean Ext_bDgoScp_VSSNwAcvReq;                                   */
/*  output boolean Ext_bDgoScg_VSSNwAcvReq;                                   */
/*  output boolean Ext_bMonRunScg_VSSNwAcvReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSSNWDMTRACV_vidDiag(void)
{
   boolean bLocalDft_scp_cmd_dmtr;
   boolean bLocalDena_scp_cmd_dmtr;
   boolean bLocalDft_scg_cmd_dmtr;
   boolean bLocalDena_scg_cmd_dmtr;
   boolean bLocalDft_oc_cmd_dmtr;
   boolean bLocalDena_oc_cmd_dmtr;
   boolean bLocalA1;
   boolean bLocalA2;
   boolean bLocalAnd1;
   boolean bLocalAnd2;
   boolean bLocalInhDiagVSSNwAcvReq;


   bLocalInhDiagVSSNwAcvReq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_VSSNWACVREQ);
   VEMS_vidGET(Dft_scp_cmd_dmtr, bLocalDft_scp_cmd_dmtr);
   VEMS_vidGET(Dena_scp_cmd_dmtr, bLocalDena_scp_cmd_dmtr);
   VEMS_vidGET(Dft_scg_cmd_dmtr, bLocalDft_scg_cmd_dmtr);
   VEMS_vidGET(Dena_scg_cmd_dmtr, bLocalDena_scg_cmd_dmtr);
   VEMS_vidGET(Dft_oc_cmd_dmtr, bLocalDft_oc_cmd_dmtr);
   VEMS_vidGET(Dena_oc_cmd_dmtr, bLocalDena_oc_cmd_dmtr);

   if (  (bLocalDena_scp_cmd_dmtr != 0)
      && (bLocalInhDiagVSSNwAcvReq == 0))
   {
      Ext_bMonRunScp_VSSNwAcvReq = 1;
   }
   else
   {
      Ext_bMonRunScp_VSSNwAcvReq = 0;
   }
   if (  (Ext_bMonRunScp_VSSNwAcvReq != 0)
      && (bLocalDft_scp_cmd_dmtr != 0))
   {
      Ext_bDgoScp_VSSNwAcvReq = 1;
   }
   else
   {
      Ext_bDgoScp_VSSNwAcvReq = 0;
   }

   if (  (bLocalDena_scg_cmd_dmtr != 0)
      && (bLocalInhDiagVSSNwAcvReq == 0))
   {
      bLocalA1 = 1;
   }
   else
   {
      bLocalA1 = 0;
   }
   if (  (bLocalA1 != 0)
      && (bLocalDft_scg_cmd_dmtr != 0))
   {
      bLocalAnd1 = 1;
   }
   else
   {
      bLocalAnd1 = 0;
   }
   if (  (bLocalDena_oc_cmd_dmtr != 0)
      && (bLocalInhDiagVSSNwAcvReq == 0))
   {
      bLocalA2 = 1;
   }
   else
   {
      bLocalA2 = 0;
   }
   if (  (bLocalA2 != 0)
      && (bLocalDft_oc_cmd_dmtr != 0))
   {
      bLocalAnd2 = 1;
   }
   else
   {
      bLocalAnd2 = 0;
   }

   if (  (bLocalAnd1 != 0)
      || (bLocalAnd2 != 0))
   {
      Ext_bDgoScg_VSSNwAcvReq = 1;
   }
   else
   {
      Ext_bDgoScg_VSSNwAcvReq = 0;
   }
   if (  (bLocalA1 != 0)
      || (bLocalA2 != 0))
   {
      Ext_bMonRunScg_VSSNwAcvReq = 1;
   }
   else
   {
      Ext_bMonRunScg_VSSNwAcvReq = 0;
   }
}

/*------------------------------- end of file --------------------------------*/