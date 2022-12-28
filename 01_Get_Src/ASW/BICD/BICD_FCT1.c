/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BICD                                                    */
/* !Description     : BICD Component.                                         */
/*                                                                            */
/* !Module          : BICD                                                    */
/* !Description     : Information Etat BICD                                   */
/*                                                                            */
/* !File            : BICD_FCT1.C                                             */
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
/*   1 / BICD_vidDftStaCmdInit                                                */
/*   2 / BICD_vidInitOutput                                                   */
/*   3 / BICD_vidFastFunCall                                                  */
/*   4 / BICD_vidDftStaCmdAcq                                                 */
/*   5 / BICD_vidDftStaCmdDiag                                                */
/*   6 / BICD_vidDiagScpScp                                                   */
/*   7 / BICD_vidDiagInvalide                                                 */
/*   8 / BICD_vidDftStaCmdSelection                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6529336 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BICD/BICD_FCT1.C_v                $*/
/* $Revision::   1.5      $$Author::   wbouach        $$Date::   22 May 2014 $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "BICD.h"
#include "BICD_L.h"
#include "BICD_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidDftStaCmdInit                                      */
/* !Description :  permet l'initialisation de la sortie.                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bStaCmdFctSt;                                          */
/*  output boolean Ext_bStaCmdFctStMes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidDftStaCmdInit(void)
{
   VEMS_vidSET(Ext_bStaCmdFctSt, 1);
   Ext_bStaCmdFctStMes = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidInitOutput                                         */
/* !Description :  initialisation des variables internes.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 BICD_u8AntiBounceCounter;                                    */
/*  output boolean Ext_bStaCmdFctStFilt;                                      */
/*  output boolean Ext_bDgoScp_uDftStaCmd;                                    */
/*  output boolean Ext_bDgoScg_uDftStaCmd;                                    */
/*  output boolean Ext_bDgoInvld_uDftStaCmd;                                  */
/*  output uint16 Ext_uDftStaCmdRaw;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidInitOutput(void)
{
   BICD_u8AntiBounceCounter = 0;
   Ext_bStaCmdFctStFilt = 0;
   Ext_bDgoScp_uDftStaCmd = 0;
   Ext_bDgoScg_uDftStaCmd = 0;
   Ext_bDgoInvld_uDftStaCmd = 0;
   VEMS_vidSET(Ext_uDftStaCmdRaw, 0);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidFastFunCall                                        */
/* !Description :  Activation et Rafraîchissement de l’information Etat BICD. */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_10_03609_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BICD_vidDftStaCmdAcq();                                  */
/*  extf argret void BICD_vidDftStaCmdDiag();                                 */
/*  extf argret void BICD_vidDftStaCmdSelection();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean EngSt_bAcvDftStaCmdAcq;                                     */
/*  input boolean Ext_bDgoScp_uDftStaCmd;                                     */
/*  input boolean Ext_bMonRunScp_uDftStaCmd;                                  */
/*  input boolean Ext_bDgoScg_uDftStaCmd;                                     */
/*  input boolean Ext_bMonRunScg_uDftStaCmd;                                  */
/*  input boolean Ext_bDgoInvld_uDftStaCmd;                                   */
/*  input boolean Ext_bMonRunInvld_uDftStaCmd;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidFastFunCall(void)
{
   boolean bLocalDIAGCAN_bIntegrElectro;
   boolean bLocalEngSt_bAcvDftStaCmdAcq;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegrElectro);
   VEMS_vidGET(EngSt_bAcvDftStaCmdAcq, bLocalEngSt_bAcvDftStaCmdAcq);
   if(  (bLocalDIAGCAN_bIntegrElectro == 0)
     && (bLocalEngSt_bAcvDftStaCmdAcq != 0))
   {
      BICD_vidDftStaCmdAcq();
      BICD_vidDftStaCmdDiag();
      BICD_vidDftStaCmdSelection();
      GDGAR_vidGdu(GD_DFT_SCP_UDFTSTACMD,
                   Ext_bDgoScp_uDftStaCmd,
                   Ext_bMonRunScp_uDftStaCmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_UDFTSTACMD,
                   Ext_bDgoScg_uDftStaCmd,
                   Ext_bMonRunScg_uDftStaCmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_INVLD_UDFTSTACMD,
                   Ext_bDgoInvld_uDftStaCmd,
                   Ext_bMonRunInvld_uDftStaCmd,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidDftStaCmdAcq                                       */
/* !Description :  permet l'acquisition, la linéarisation et le filtration de */
/*                 l’information Etat BICD                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_10_03609_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acquisition_tension_etat_bicd;                               */
/*  input uint16 Ext_uMaxDftStaCmd_C;                                         */
/*  input uint16 Ext_uMinDftStaCmd_C;                                         */
/*  input uint16 Ext_uMaxNoDftStaCmd_C;                                       */
/*  input uint16 Ext_uMinNoDftStaCmd_C;                                       */
/*  input boolean Ext_bStaCmdFctStMes;                                        */
/*  input boolean Ext_bStaCmdFctStFilt;                                       */
/*  input uint8 Ext_noDftStaCmdHiThd_C;                                       */
/*  input uint8 Ext_noDftStaCmdLoThd_C;                                       */
/*  input uint8 BICD_u8AntiBounceCounter;                                     */
/*  output uint16 Ext_uDftStaCmdRaw;                                          */
/*  output boolean Ext_bStaCmdFctStMes;                                       */
/*  output uint8 BICD_u8AntiBounceCounter;                                    */
/*  output boolean Ext_bStaCmdFctStFilt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidDftStaCmdAcq(void)
{
   uint8  u8LocalThd;
   uint16 u16LocalAcq_tension_etat_bicd;


   /* production de la sortie Ext_uDftStaCmdRaw*/
   VEMS_vidGET(Acquisition_tension_etat_bicd, u16LocalAcq_tension_etat_bicd);
   u16LocalAcq_tension_etat_bicd =
      (uint16)MATHSRV_udtMIN(u16LocalAcq_tension_etat_bicd, 4096);
   VEMS_vidSET(Ext_uDftStaCmdRaw, u16LocalAcq_tension_etat_bicd);

   if (  (Ext_uMaxDftStaCmd_C >= u16LocalAcq_tension_etat_bicd)
      && (u16LocalAcq_tension_etat_bicd >= Ext_uMinDftStaCmd_C))
   {
      Ext_bStaCmdFctStMes = 0;
   }
   else
   {
      if (  (Ext_uMaxNoDftStaCmd_C >= u16LocalAcq_tension_etat_bicd)
         && (u16LocalAcq_tension_etat_bicd >= Ext_uMinNoDftStaCmd_C))
      {
         Ext_bStaCmdFctStMes = 1;
      }
   }
   if (Ext_bStaCmdFctStMes != Ext_bStaCmdFctStFilt)
   {
      if (Ext_bStaCmdFctStMes != 0)
      {
         u8LocalThd = Ext_noDftStaCmdHiThd_C;
      }
      else
      {
         u8LocalThd = Ext_noDftStaCmdLoThd_C;
      }
      if (BICD_u8AntiBounceCounter < 255)
      {
         BICD_u8AntiBounceCounter = (uint8)(BICD_u8AntiBounceCounter + 1);
      }
      if (BICD_u8AntiBounceCounter > u8LocalThd)
      {
         if (Ext_bStaCmdFctStMes != 0)
         {
            Ext_bStaCmdFctStFilt = 1;
         }
         else
         {
            Ext_bStaCmdFctStFilt = 0;
         }
         BICD_u8AntiBounceCounter = 0;
      }
   }
   else
   {
      BICD_u8AntiBounceCounter = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidDftStaCmdDiag                                      */
/* !Description :  Autorisation des diagnostics et diagnostics de             */
/*                 l’information Etat BICD                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_10_03609_003.01                                     */
/*                 VEMS_R_10_03609_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void BICD_vidDiagScpScp();                                    */
/*  extf argret void BICD_vidDiagInvalide();                                  */
/*  output boolean Ext_bMonRunScp_uDftStaCmd;                                 */
/*  output boolean Ext_bMonRunScg_uDftStaCmd;                                 */
/*  output boolean Ext_bMonRunInvld_uDftStaCmd;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidDftStaCmdDiag(void)
{
   boolean bLocalbInhDiag_uDftStaCmd;


   bLocalbInhDiag_uDftStaCmd = GDGAR_bGetFRM(FRM_FRM_INHDIAG_UDFTSTACMD);
   if (bLocalbInhDiag_uDftStaCmd != 0)
   {
      Ext_bMonRunScp_uDftStaCmd = 0;
      Ext_bMonRunScg_uDftStaCmd = 0;
      Ext_bMonRunInvld_uDftStaCmd = 0;
   }
   else
   {
      BICD_vidDiagScpScp();
      BICD_vidDiagInvalide();
      Ext_bMonRunScp_uDftStaCmd = 1;
      Ext_bMonRunScg_uDftStaCmd = 1;
      Ext_bMonRunInvld_uDftStaCmd = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidDiagScpScp                                         */
/* !Description :  Diagnostics de l’information Etat BICD                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_uDftStaCmdRaw;                                           */
/*  input uint16 Ext_uDgoScp_DftStaCmd_C;                                     */
/*  input uint16 Ext_uDgoScg_DftStaCmd_C;                                     */
/*  output boolean Ext_bDgoScp_uDftStaCmd;                                    */
/*  output boolean Ext_bDgoScg_uDftStaCmd;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidDiagScpScp(void)
{
   uint16 u16LocalExt_uDftStaCmdRaw;


   VEMS_vidGET(Ext_uDftStaCmdRaw,u16LocalExt_uDftStaCmdRaw);
   if (u16LocalExt_uDftStaCmdRaw >= Ext_uDgoScp_DftStaCmd_C)
   {
      Ext_bDgoScp_uDftStaCmd = 1;
   }
   else
   {
      Ext_bDgoScp_uDftStaCmd = 0;
   }
   if (u16LocalExt_uDftStaCmdRaw <= Ext_uDgoScg_DftStaCmd_C)
   {
      Ext_bDgoScg_uDftStaCmd = 1;
   }
   else
   {
      Ext_bDgoScg_uDftStaCmd = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidDiagInvalide                                       */
/* !Description :  Autorisation des Diagnostics de l’information Etat BICD    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Ines Omezzine                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_uDftStaCmdRaw;                                           */
/*  input uint16 Ext_uMaxDftStaCmd_C;                                         */
/*  input uint16 Ext_uMinDftStaCmd_C;                                         */
/*  input uint16 Ext_uMaxNoDftStaCmd_C;                                       */
/*  input uint16 Ext_uMinNoDftStaCmd_C;                                       */
/*  input uint16 Ext_uDgoScp_DftStaCmd_C;                                     */
/*  input uint16 Ext_uDgoScg_DftStaCmd_C;                                     */
/*  output boolean Ext_bDgoInvld_uDftStaCmd;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidDiagInvalide(void)
{
   uint16 u16LocalExt_uDftStaCmdRaw;


   VEMS_vidGET(Ext_uDftStaCmdRaw,u16LocalExt_uDftStaCmdRaw);
   if(  (  (u16LocalExt_uDftStaCmdRaw <= Ext_uMaxDftStaCmd_C)
        && (u16LocalExt_uDftStaCmdRaw >= Ext_uMinDftStaCmd_C))
     || (  (u16LocalExt_uDftStaCmdRaw <= Ext_uMaxNoDftStaCmd_C)
        && (u16LocalExt_uDftStaCmdRaw >= Ext_uMinNoDftStaCmd_C))
     || (u16LocalExt_uDftStaCmdRaw >= Ext_uDgoScp_DftStaCmd_C)
     || (u16LocalExt_uDftStaCmdRaw <= Ext_uDgoScg_DftStaCmd_C))
   {
      Ext_bDgoInvld_uDftStaCmd = 0;
   }
   else
   {
      Ext_bDgoInvld_uDftStaCmd = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BICD_vidDftStaCmdSelection                                 */
/* !Description :  Consolidation de l’information Etat BICD                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Ines Omezzine                                              */
/* !Trace_To    :  VEMS_R_10_03609_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bStaCmdFctSt_C;                                         */
/*  input boolean Ext_bStaCmdFctStFilt;                                       */
/*  output boolean Ext_bStaCmdFctSt;                                          */
/*  output boolean Ext_bStaCmdFctSt_C;                                        */
/*  output boolean Ext_bStaCmdFctStFilt;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BICD_vidDftStaCmdSelection(void)
{
   GDFRM_tenuGDUState  LocalstDgoScp_uDftStaCmd;
   GDFRM_tenuGDUState  LocalstDgoScg_uDftStaCmd;
   GDFRM_tenuGDUState  LocalstDgoInvld_uDftStaCmd;


   LocalstDgoScp_uDftStaCmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_UDFTSTACMD);
   LocalstDgoScg_uDftStaCmd = GDGAR_tenuGetStDgo(GD_DFT_SCG_UDFTSTACMD);
   LocalstDgoInvld_uDftStaCmd = GDGAR_tenuGetStDgo(GD_DFT_INVLD_UDFTSTACMD);
   if (  (LocalstDgoScp_uDftStaCmd == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_uDftStaCmd == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoScg_uDftStaCmd == GDU_ETAT_PRESENT)
      || (LocalstDgoScg_uDftStaCmd == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoInvld_uDftStaCmd == GDU_ETAT_PRESENT)
      || (LocalstDgoInvld_uDftStaCmd == GDU_ETAT_DEVALIDATION))
   {
      VEMS_vidSET(Ext_bStaCmdFctSt , Ext_bStaCmdFctSt_C);
   }
   else
   {
      if (  (LocalstDgoScp_uDftStaCmd != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoScp_uDftStaCmd != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoScg_uDftStaCmd != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoScg_uDftStaCmd != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoInvld_uDftStaCmd != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoInvld_uDftStaCmd != GDU_ETAT_PCTL_PRESENT))
      {
         VEMS_vidSET(Ext_bStaCmdFctSt , Ext_bStaCmdFctStFilt);
      }
   }
}
/*------------------------------- end of file --------------------------------*/
