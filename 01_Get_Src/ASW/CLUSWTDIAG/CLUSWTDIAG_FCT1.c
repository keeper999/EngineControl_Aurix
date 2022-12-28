/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUSWTDIAG                                              */
/* !Description     : CLUSWTDIAG Component                                    */
/*                                                                            */
/* !Module          : CLUSWTDIAG                                              */
/* !Description     : Diagnostic switch embrayage                             */
/*                                                                            */
/* !File            : CLUSWTDIAG_FCT1.C                                       */
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
/*   1 / CLUSWTDIAG_vidInit                                                   */
/*   2 / CLUSWTDIAG_vidInitOutput                                             */
/*   3 / CLUSWTDIAG_vidEventFlagOn                                            */
/*   4 / CLUSWTDIAG_vidDiagCohMonitoring                                      */
/*   5 / CLUSWTDIAG_vidInitDiagStuck                                          */
/*   6 / CLUSWTDIAG_vidDiagCoh                                                */
/*   7 / CLUSWTDIAG_vidCounter                                                */
/*   8 / CLUSWTDIAG_vidDiagStuck                                              */
/*   9 / CLUSWTDIAG_vidTempo                                                  */
/*   10 / CLUSWTDIAG_vidStateCluInit                                          */
/*                                                                            */
/* !Reference   : V02 NT 08 04680 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#045677                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/CLUSWTDIAG/CLUSWTDIAG_FCT1.C_v    $*/
/* $Revision::   1.4      $$Author::   ACHEBINO       $$Date::   12 Jul 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   12 Jul 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "CLUSWTDIAG.H"
#include "CLUSWTDIAG_L.H"
#include "CLUSWTDIAG_IM.H"
#include "GDGAR.H"
#include "VEMS.H"
#include "SWFAIL.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidInit                                         */
/* !Description :  Initialisation des variables au reset de l’ECU             */
/*                 (Clu_EveRst_CluSwtDiag).                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Cps_controle_coh_delay;                                       */
/*  output uint8 Cps_controle_coh_tempo;                                      */
/*  output uint16 Cps_emb_tempo;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidInit(void)
{
   Cps_controle_coh_tempo = Cps_controle_coh_delay;
   Cps_emb_tempo = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidInitOutput                                   */
/* !Description :  Initialisation des variables internes.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidStateCluInit();                            */
/*  output boolean CLUSWTDIAG_bMonRunStuck_prev;                              */
/*  output boolean CLUSWTDIAG_bRisingCompInit_prev;                           */
/*  output boolean CLUSWTDIAG_bExtBCluPedPrssPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidInitOutput(void)
{
   CLUSWTDIAG_bMonRunStuck_prev = 0;
   CLUSWTDIAG_bRisingCompInit_prev = 0;
   CLUSWTDIAG_bExtBCluPedPrssPrev = 0;

   /* Initialisation de l'automate.*/
   CLUSWTDIAG_vidStateCluInit();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidEventFlagOn                                  */
/* !Description :  Cette fonction est appelée aux évenememnts                 */
/*                 Clu_EveKOn_CluSwtDiag Clu_EveCrTR_CluSwtDiag, elle sert à  */
/*                 mettre la variable CLUSWTDIAG_bAllowCohRunnigToInit à 1    */
/*                 pour autoriser la transaction de l'automate.               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CLUSWTDIAG_bAllowCohRunnigToInit;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidEventFlagOn(void)
{
   CLUSWTDIAG_bAllowCohRunnigToInit = 1;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagCohMonitoring                            */
/* !Description :  Le stateflow permet de gérer les phases du diagnostic de   */
/*                 cohérence d’état, notamment le déclenchement des           */
/*                 temporisations à l’initialisation et lorsque le diagnostic */
/*                 est activé.                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUSWTDIAG_vidStateCluInit();                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*  input st48 Clu_stDiagCoh;                                                 */
/*  input uint16 Cps_vitesse_vehicule_init_tempo;                             */
/*  input boolean Cps_controle_ok;                                            */
/*  input boolean Clu_bDiagCohIninCdn;                                        */
/*  input boolean Clu_bDiagCohDacvn;                                          */
/*  input boolean CLUSWTDIAG_bAllowCohRunnigToInit;                           */
/*  input uint8 Cps_controle_coh_tempo;                                       */
/*  input uint8 Cps_controle_coh_delay;                                       */
/*  input boolean Clu_bDiagCohCdn;                                            */
/*  output st48 Clu_stDiagCoh;                                                */
/*  output boolean Clu_bMonRunCoh_CluSt;                                      */
/*  output boolean Clu_bDftCohCtr;                                            */
/*  output boolean Clu_bDiagCohCtrInin;                                       */
/*  output boolean Clu_bDiagCohCtrAcvn;                                       */
/*  output uint16 Cps_vitesse_vehicule_init_tempo;                            */
/*  output boolean Clu_bDgoCoh_CluSt;                                         */
/*  output boolean CLUSWTDIAG_bAllowCohRunnigToInit;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagCohMonitoring(void)
{
   boolean bLocalFlowMng_bCluSwtEna;
   uint16  u16LocalInitTempo;


   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);

   switch (Clu_stDiagCoh)
   {
      case CLU_INIT:
         if (  ( Cps_vitesse_vehicule_init_tempo == 0)
            && (bLocalFlowMng_bCluSwtEna != 0))
         {
            Clu_stDiagCoh = CLU_DIAG_COH_INIT;
            Clu_bMonRunCoh_CluSt = 0;
            Clu_bDftCohCtr = 0;
            Clu_bDiagCohCtrInin = 1;
            Clu_bDiagCohCtrAcvn = 0;
         }
         else
         {
            if (Cps_vitesse_vehicule_init_tempo > 0)
            {
               u16LocalInitTempo =
                  (uint16)(Cps_vitesse_vehicule_init_tempo - 1);
               Cps_vitesse_vehicule_init_tempo =
                   (uint16)MATHSRV_udtMIN(u16LocalInitTempo, 510);
            }
         }
         break;

         case CLU_DIAG_COH_INIT:
            if (bLocalFlowMng_bCluSwtEna == 0)
            {
               CLUSWTDIAG_vidStateCluInit();
            }
            else
            {
               if (Cps_controle_ok != 0)
               {
                  Clu_stDiagCoh = CLU_DIAG_COH_OK;
                  Clu_bDgoCoh_CluSt = 0;
                  Clu_bMonRunCoh_CluSt = 1;
                  Clu_bDftCohCtr = 0;
                  Clu_bDiagCohCtrInin = 1;
                  Clu_bDiagCohCtrAcvn = 0;
               }
               else
               {
                  if (  (Clu_bDiagCohIninCdn != 0)
                     && (Clu_bDiagCohDacvn == 0))
                  {
                     Clu_stDiagCoh = CLU_DIAG_COH_RUNNING;
                     Clu_bDiagCohCtrInin = 1;
                     Clu_bDiagCohCtrAcvn = 1;
                  }
               }
            }
            break;

      case CLU_DIAG_COH_RUNNING:
         if (bLocalFlowMng_bCluSwtEna == 0)
         {
            CLUSWTDIAG_vidStateCluInit();
         }
         else
         {
            if (Cps_controle_ok != 0)
            {
               Clu_stDiagCoh = CLU_DIAG_COH_OK;
               Clu_bDgoCoh_CluSt = 0;
               Clu_bMonRunCoh_CluSt = 1;
               Clu_bDftCohCtr = 0;
               Clu_bDiagCohCtrInin = 1;
               Clu_bDiagCohCtrAcvn = 0;
            }
            else
            {
               if (  (CLUSWTDIAG_bAllowCohRunnigToInit != 0)
                  || (Clu_bDiagCohDacvn != 0)
                  || (  (Cps_controle_coh_tempo <= 0)
                     && (Cps_controle_coh_delay !=0)))
               {
                  Clu_stDiagCoh = CLU_DIAG_COH_INIT;
                  Clu_bMonRunCoh_CluSt = 0;
                  Clu_bDftCohCtr = 0;
                  Clu_bDiagCohCtrInin = 1;
                  Clu_bDiagCohCtrAcvn = 0;
               }
               else
               {
                  if (Clu_bDiagCohCdn != 0)
                  {
                     Clu_stDiagCoh = CLU_DIAG_COH_NOK;
                     Clu_bDgoCoh_CluSt = 1;
                     Clu_bMonRunCoh_CluSt = 1;
                     Clu_bDftCohCtr = 1;
                     Clu_bDiagCohCtrInin = 1;
                     Clu_bDiagCohCtrAcvn = 0;
                  }
                  else
                  {
                     Clu_bDiagCohCtrInin = 0;
                     Clu_bDiagCohCtrAcvn = 1;
                  }
               }
            }
         }
         break;

      case CLU_DIAG_COH_NOK:
         if (bLocalFlowMng_bCluSwtEna == 0)
         {
            CLUSWTDIAG_vidStateCluInit();
         }
         else
         {
            if (Cps_controle_ok != 0)
            {
               Clu_stDiagCoh = CLU_DIAG_COH_OK;
               Clu_bDgoCoh_CluSt = 0;
               Clu_bMonRunCoh_CluSt = 1;
               Clu_bDftCohCtr = 0;
               Clu_bDiagCohCtrInin = 1;
               Clu_bDiagCohCtrAcvn = 0;
            }
            else
            {
               Clu_stDiagCoh = CLU_DIAG_COH_INIT;
               Clu_bMonRunCoh_CluSt = 0;
               Clu_bDftCohCtr = 0;
               Clu_bDiagCohCtrInin = 1;
               Clu_bDiagCohCtrAcvn = 0;
            }
         }
         break;

      case CLU_DIAG_COH_OK:
         if (bLocalFlowMng_bCluSwtEna == 0)
         {
            CLUSWTDIAG_vidStateCluInit();
         }
         else
         {
            Clu_stDiagCoh = CLU_DIAG_COH_INIT;
            Clu_bMonRunCoh_CluSt = 0;
            Clu_bDftCohCtr = 0;
            Clu_bDiagCohCtrInin = 1;
            Clu_bDiagCohCtrAcvn = 0;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         CLUSWTDIAG_vidStateCluInit();
         break;
   }
   CLUSWTDIAG_bAllowCohRunnigToInit = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidInitDiagStuck                                */
/* !Description :  Cette fonction gère l’initialisation des variables après un*/
/*                 Key OFF/ON.                                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Cps_emb_tempo;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidInitDiagStuck(void)
{
   Cps_emb_tempo = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagCoh                                      */
/* !Description :  Cette fonction gère d’une part la génération des variables */
/*                 Ext_bDgoCoh_CluSt et Ext_bMonRunCoh_CluSt et d’autre part  */
/*                 le compteur d’embrayage mal utilisé.                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUSWTDIAG_vidDgoCoh_CluSt();                            */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagCoh(void)
{
   boolean bLocalFlowMng_bCluSwtEna;


   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);
   if (bLocalFlowMng_bCluSwtEna != 0)
   {
      CLUSWTDIAG_vidDgoCoh_CluSt();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidCounter                                      */
/* !Description :  L’autorisation de diagnostic monte sur un pas de temps, le */
/*                 compteur de défaut est donc incrémenté une seule fois à la */
/*                 fin de chaque diagnostic NOK.                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUSWTDIAG_vidCps_switch_mal_cpt();                      */
/*  input boolean Clu_bDftCohCtr;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidCounter(void)
{
   if (Clu_bDftCohCtr != 0)
   {
      CLUSWTDIAG_vidCps_switch_mal_cpt();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidDiagStuck                                    */
/* !Description :  Cette fonction gère gère la génération des variables       */
/*                 Ext_bDgoStuck_CluSt et Ext_bMonRunStuck_CluSt.             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUSWTDIAG_vidDiagStuck_CluSt();                         */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidDiagStuck(void)
{
   boolean bLocalFlowMng_bCluSwtEna;


   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);
   if (bLocalFlowMng_bCluSwtEna != 0)
   {
      CLUSWTDIAG_vidDiagStuck_CluSt();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidTempo                                        */
/* !Description :  Cette fonction gère la temporisation d’autorisation du     */
/*                 diagnostic du capteur embrayage, appelée à récurrence      */
/*                 temporelle lente                                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUSWTDIAG_vidTempoCoh();                                */
/*  extf argret void CLUSWTDIAG_vidTempoStuck();                              */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidTempo(void)
{
   boolean bLocalFlowMng_bCluSwtEna;


   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);
   if (bLocalFlowMng_bCluSwtEna != 0)
   {
      CLUSWTDIAG_vidTempoCoh();
      CLUSWTDIAG_vidTempoStuck();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUSWTDIAG_vidStateCluInit                                 */
/* !Description :  Fonction de transition à l'état CLU_INIT de l'automate.    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  dobregon                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Cps_vitesse_vehicule_init_delay;                             */
/*  output st48 Clu_stDiagCoh;                                                */
/*  output boolean Clu_bDgoCoh_CluSt;                                         */
/*  output boolean Clu_bMonRunCoh_CluSt;                                      */
/*  output boolean Clu_bDftCohCtr;                                            */
/*  output boolean Clu_bDiagCohCtrInin;                                       */
/*  output boolean Clu_bDiagCohCtrAcvn;                                       */
/*  output uint16 Cps_vitesse_vehicule_init_tempo;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUSWTDIAG_vidStateCluInit(void)
{
   Clu_stDiagCoh = CLU_INIT;
   Clu_bDgoCoh_CluSt = 0;
   Clu_bMonRunCoh_CluSt = 0;
   Clu_bDftCohCtr = 0;
   Clu_bDiagCohCtrInin = 1;
   Clu_bDiagCohCtrAcvn = 0;
   Cps_vitesse_vehicule_init_tempo =
      (uint16)MATHSRV_udtMIN(Cps_vitesse_vehicule_init_delay, 510);
}

/*------------------------------- end of file --------------------------------*/