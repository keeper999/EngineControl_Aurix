/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STRTRCMDDIAG                                            */
/* !Description     : STRTRCMDDIAG component                                  */
/*                                                                            */
/* !Module          : STRTRCMDDIAG                                            */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE DML         */
/*                                                                            */
/* !File            : STRTRCMDDIAG_FCT1.C                                     */
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
/*   1 / STRTRCMDDIAG_vidCmdStrtrRly                                          */
/*   2 / STRTRCMDDIAG_vidDiagStrtrRly                                         */
/*   3 / STRTRCMDDIAG_vidDiagElec                                             */
/*   4 / STRTRCMDDIAG_vidDiagBlockedStrtr                                     */
/*   5 / STRTRCMDDIAG_vidResetTempo                                           */
/*   6 / STRTRCMDDIAG_vidRunTempo                                             */
/*   7 / STRTRCMDDIAG_vidCondResetTempo                                       */
/*   8 / STRTRCMDDIAG_vidDiagBlockedStEna                                     */
/*   9 / STRTRCMDDIAG_vidIni                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6528767 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/STRTRCMDDIAG/STRTRCMDDIAG_FCT1.C_v$*/
/* $Revision::   1.9                                                         $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "STRTRCMDDIAG.h"
#include "STRTRCMDDIAG_L.h"
#include "STRTRCMDDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidCmdStrtrRly                                */
/* !Description :  Le pilotage de la Dml doit être Low Side Tout Ou Rien (TOR)*/
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03808_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Dml_cmd_cranking;                                           */
/*  input boolean ECU_bWkuMain;                                               */
/*  output boolean Cmde_logique_dml_tor;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidCmdStrtrRly(void)
{
   boolean bLocalDml_cmd_cranking;
   boolean bLocalECU_bWkuMain;
   boolean bLocalInhDmlCmd;


   VEMS_vidGET(Dml_cmd_cranking, bLocalDml_cmd_cranking);
   VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
   bLocalInhDmlCmd = GDGAR_bGetFRM(FRM_FRM_INHDMLCMD);

   if (bLocalInhDmlCmd != 0)
   {
      VEMS_vidSET(Cmde_logique_dml_tor, 0);
   }
   else
   {
      if (  (bLocalDml_cmd_cranking != 0)
         && (bLocalECU_bWkuMain != 0))
      {
         VEMS_vidSET(Cmde_logique_dml_tor, 1);
      }
      else
      {
         VEMS_vidSET(Cmde_logique_dml_tor, 0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidDiagStrtrRly                               */
/* !Description :  Ce bloc permet de faire les diagnostics électriques liés au*/
/*                 DML (court-circuit à l’alimentation, court-circuit à la    */
/*                 masse, circuit ouvert) ainsi que le diagnostic lié au      */
/*                 défaut blocage du démarreur.                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03808_001.01                                     */
/*                 VEMS_R_08_03808_002.01                                     */
/*                 VEMS_R_08_03808_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void STRTRCMDDIAG_vidDiagElec();                              */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STRTRCMDDIAG_vidDiagBlockedStrtr();                      */
/*  input boolean ECU_bWkuMain;                                               */
/*  input boolean STRTRCMDDIAG_bscw_diag_ena;                                 */
/*  input boolean EcuSt_bInhDiagOcCmdActr;                                    */
/*  input boolean STRTRCMDDIAG_boc_diag_ena;                                  */
/*  input boolean STRTRCMDDIAG_bscg_diag_ena;                                 */
/*  output boolean Ext_bMonRunScp_Dml;                                        */
/*  output boolean Ext_bMonRunOc_Dml;                                         */
/*  output boolean Ext_bMonRunScg_Dml;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidDiagStrtrRly(void)
{
   boolean bLocalInhDmlDiagEl;
   boolean bLocalEcuSt_bInhDiagOcCmdActr;
   boolean bLocalECU_bWkuMain;


   bLocalInhDmlDiagEl = GDGAR_bGetFRM(FRM_FRM_INHDMLDIAGEL);

   if (bLocalInhDmlDiagEl == 0)
   {
      STRTRCMDDIAG_vidDiagElec();
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      if (bLocalECU_bWkuMain != 0)
      {
         Ext_bMonRunScp_Dml = STRTRCMDDIAG_bscw_diag_ena;
         VEMS_vidGET(EcuSt_bInhDiagOcCmdActr, bLocalEcuSt_bInhDiagOcCmdActr);
         if (bLocalEcuSt_bInhDiagOcCmdActr == 0)
         {
            Ext_bMonRunOc_Dml = STRTRCMDDIAG_boc_diag_ena;
            Ext_bMonRunScg_Dml = STRTRCMDDIAG_bscg_diag_ena;
         }
         else
         {
            Ext_bMonRunOc_Dml = 0;
            Ext_bMonRunScg_Dml = 0;
         }
      }
      else
      {
         Ext_bMonRunScp_Dml = 0;
         Ext_bMonRunOc_Dml = 0;
         Ext_bMonRunScg_Dml = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_Dml = 0;
      Ext_bMonRunOc_Dml = 0;
      Ext_bMonRunScg_Dml = 0;
   }
   STRTRCMDDIAG_vidDiagBlockedStrtr();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidDiagElec                                   */
/* !Description :  Trois types de diagnostic de pannes sont traités: panne    */
/*                 circuit ouvert/panne Court-circuit à la masse/panne        */
/*                 Court-circuit à la batterie                                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03808_007.01                                     */
/*                 VEMS_R_08_03808_008.01                                     */
/*                 VEMS_R_08_03808_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dft_oc_sortielogiquedml;                                    */
/*  input boolean Dena_oc_sortielogiquedml;                                   */
/*  input boolean Dft_scg_sortielogiquedml;                                   */
/*  input boolean Dena_scg_sortielogiquedml;                                  */
/*  input boolean Dft_scp_sortielogiquedml;                                   */
/*  input boolean Dena_scp_sortielogiquedml;                                  */
/*  output boolean Ext_bMonWaitOc_Dml;                                        */
/*  output boolean Ext_bMonWaitScg_Dml;                                       */
/*  output boolean Ext_bMonWaitScp_Dml;                                       */
/*  output boolean Ext_bDgoOc_Dml;                                            */
/*  output boolean STRTRCMDDIAG_boc_diag_ena;                                 */
/*  output boolean Ext_bDgoScg_Dml;                                           */
/*  output boolean STRTRCMDDIAG_bscg_diag_ena;                                */
/*  output boolean Ext_bDgoScp_Dml;                                           */
/*  output boolean STRTRCMDDIAG_bscw_diag_ena;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidDiagElec(void)
{
   boolean bLocalDft_oc_sortielogiquedml;
   boolean bLocalDena_oc_sortielogiquedml;
   boolean bLocalDft_scg_sortielogiquedml;
   boolean bLocalDena_scg_sortielogiquedml;
   boolean bLocalDft_scp_sortielogiquedml;
   boolean bLocalDena_scp_sortielogiquedml;


   VEMS_vidGET(Dft_oc_sortielogiquedml, bLocalDft_oc_sortielogiquedml);
   VEMS_vidGET(Dena_oc_sortielogiquedml, bLocalDena_oc_sortielogiquedml);
   VEMS_vidGET(Dft_scg_sortielogiquedml, bLocalDft_scg_sortielogiquedml);
   VEMS_vidGET(Dena_scg_sortielogiquedml, bLocalDena_scg_sortielogiquedml);
   VEMS_vidGET(Dft_scp_sortielogiquedml, bLocalDft_scp_sortielogiquedml);
   VEMS_vidGET(Dena_scp_sortielogiquedml, bLocalDena_scp_sortielogiquedml);
   Ext_bMonWaitOc_Dml  = 0;
   Ext_bMonWaitScg_Dml = 0;
   Ext_bMonWaitScp_Dml = 0;
   Ext_bDgoOc_Dml = bLocalDft_oc_sortielogiquedml;
   STRTRCMDDIAG_boc_diag_ena = bLocalDena_oc_sortielogiquedml;
   Ext_bDgoScg_Dml = bLocalDft_scg_sortielogiquedml;
   STRTRCMDDIAG_bscg_diag_ena = bLocalDena_scg_sortielogiquedml;
   Ext_bDgoScp_Dml = bLocalDft_scp_sortielogiquedml;
   STRTRCMDDIAG_bscw_diag_ena = bLocalDena_scp_sortielogiquedml;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidDiagBlockedStrtr                           */
/* !Description :  Le défaut Démarreur bloqué est détecté quand il n’y a pas  */
/*                 de défaut sur le capteur régime et au démarrage, sur       */
/*                 commande démarreur, il y a absence du signal régime        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_08_03808_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STRTRCMDDIAG_vidResetTempo();                            */
/*  extf argret void STRTRCMDDIAG_vidRunTempo();                              */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void STRTRCMDDIAG_vidDiagBlockedStEna();                      */
/*  input boolean CoPTSt_bEngStop;                                            */
/*  input boolean Dml_cmd_cranking;                                           */
/*  input boolean STRTRCMDDIAG_bCondRstTempo;                                 */
/*  input boolean STRTRCMDDIAG_bDmlCmdCrankingPrev;                           */
/*  input uint16 Dml_diag_cmd_blocage_sta_count;                              */
/*  output boolean STRTRCMDDIAG_bCondRstTempo;                                */
/*  output boolean STRTRCMDDIAG_bDmlCmdCrankingPrev;                          */
/*  output boolean Strtr_bMonWaitBlock_Strtr;                                 */
/*  output boolean Strtr_bMonRunBlock_Strtr;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidDiagBlockedStrtr(void)
{
   boolean bLocalCoPTSt_bEngStop;
   boolean bLocalCmdCrankingAndEngStopPrev;
   boolean bLocalDml_cmd_cranking;
   boolean bLocalInhDetBlockStrtr;

   VEMS_vidGET(CoPTSt_bEngStop, bLocalCoPTSt_bEngStop);
   VEMS_vidGET(Dml_cmd_cranking,bLocalDml_cmd_cranking);
   bLocalCmdCrankingAndEngStopPrev = STRTRCMDDIAG_bCondRstTempo;

   if (  (bLocalDml_cmd_cranking !=0)
      && (bLocalCoPTSt_bEngStop  !=0))
   {
      STRTRCMDDIAG_bCondRstTempo = 1;
   }
   else
   {
      STRTRCMDDIAG_bCondRstTempo = 0;
   }

   if (bLocalDml_cmd_cranking == 0)
   {
      if(STRTRCMDDIAG_bDmlCmdCrankingPrev != 0)
      {
         STRTRCMDDIAG_vidResetTempo();
      }
   }
   else
   {
      STRTRCMDDIAG_vidRunTempo();

      if (  (STRTRCMDDIAG_bCondRstTempo != 0)
         && (bLocalCmdCrankingAndEngStopPrev == 0))
      {
         STRTRCMDDIAG_vidResetTempo();
      }
   }
   STRTRCMDDIAG_bDmlCmdCrankingPrev = bLocalDml_cmd_cranking;
   bLocalInhDetBlockStrtr = GDGAR_bGetFRM(FRM_FRM_INHDETBLOCKSTRTR);
   if ( Dml_diag_cmd_blocage_sta_count == 0)
   {
      Strtr_bMonWaitBlock_Strtr = 0;
      if(bLocalInhDetBlockStrtr != 0)
      {
         Strtr_bMonRunBlock_Strtr = 0;
      }
      else
      {
         Strtr_bMonRunBlock_Strtr = 1;
         STRTRCMDDIAG_vidDiagBlockedStEna();
      }
   }
   else
   {
      Strtr_bMonRunBlock_Strtr = 0;
      if(bLocalDml_cmd_cranking != 0)
      {
         Strtr_bMonWaitBlock_Strtr = 1;
      }
      else
      {
         Strtr_bMonWaitBlock_Strtr = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidResetTempo                                 */
/* !Description :  La tempo Dml_diag_blocage_sta_count est réinitialisée      */
/*                 quand: 1) la commande n’est pas active. 2) le moteur est   */
/*                 non tournant alors que la commande est active.             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dml_diag_blocage_sta_delay;                                  */
/*  output uint16 Dml_diag_cmd_blocage_sta_count;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidResetTempo(void)
{
   Dml_diag_cmd_blocage_sta_count =
      (uint16)MATHSRV_udtMIN(Dml_diag_blocage_sta_delay, 50000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidRunTempo                                   */
/* !Description :  Ce bloc permet de calculer de Dml_diag_blocage_sta_count   */
/*                 qui est décrémentée tant que la commande de démarrage est  */
/*                 active.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dml_diag_cmd_blocage_sta_count;                              */
/*  output uint16 Dml_diag_cmd_blocage_sta_count;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidRunTempo(void)
{
   uint16 u16LocalBlocageStaCount;


   if (Dml_diag_cmd_blocage_sta_count != 0)
   {
      u16LocalBlocageStaCount =
         (uint16)(Dml_diag_cmd_blocage_sta_count - 1);
      Dml_diag_cmd_blocage_sta_count =
         (uint16)MATHSRV_udtMIN(u16LocalBlocageStaCount, 50000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidCondResetTempo                             */
/* !Description :  Fonction d'initialisation du trigger du bloc reset_tempo   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean STRTRCMDDIAG_bCondRstTempo;                                */
/*  output boolean STRTRCMDDIAG_boc_diag_ena;                                 */
/*  output boolean STRTRCMDDIAG_bDmlCmdCrankingPrev;                          */
/*  output boolean Ext_bDgoOc_Dml;                                            */
/*  output boolean STRTRCMDDIAG_bscg_diag_ena;                                */
/*  output boolean Ext_bDgoScg_Dml;                                           */
/*  output boolean STRTRCMDDIAG_bscw_diag_ena;                                */
/*  output boolean Ext_bDgoScp_Dml;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidCondResetTempo(void)
{
   STRTRCMDDIAG_bCondRstTempo = 0;
   STRTRCMDDIAG_boc_diag_ena = 0;
   STRTRCMDDIAG_bDmlCmdCrankingPrev = 0;
   Ext_bDgoOc_Dml = 0;
   STRTRCMDDIAG_bscg_diag_ena = 0;
   Ext_bDgoScg_Dml = 0;
   STRTRCMDDIAG_bscw_diag_ena = 0;
   Ext_bDgoScp_Dml = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidDiagBlockedStEna                           */
/* !Description :  Le défaut Démarreur bloqué est détecté quand il n’y a pas  */
/*                 de défaut sur le capteur régime et au démarrage, sur       */
/*                 commande démarreur, il y a absence du signal régime .      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Regime_moteur;                                               */
/*  output boolean Strtr_bDgoBlock_Strtr;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidDiagBlockedStEna(void)
{
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur,u16LocalRegime_moteur);
   if (u16LocalRegime_moteur == 0)
   {
      Strtr_bDgoBlock_Strtr = 1;
   }
   else
   {
      Strtr_bDgoBlock_Strtr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STRTRCMDDIAG_vidIni                                        */
/* !Description :  L’initialisation de la variable                            */
/*                 Dml_diag_cmd_blocage_sta_count  avec                       */
/*                 Dml_diag_blocage_sta_delay                                 */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dml_diag_blocage_sta_delay;                                  */
/*  output uint16 Dml_diag_cmd_blocage_sta_count;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STRTRCMDDIAG_vidIni(void)
{
   Dml_diag_cmd_blocage_sta_count =
   (uint16)MATHSRV_udtMIN(Dml_diag_blocage_sta_delay, 50000);
}
/*------------------------------- end of file --------------------------------*/