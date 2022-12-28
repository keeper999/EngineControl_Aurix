/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RLYPWR                                                  */
/* !Description     : RLYPWR Component                                        */
/*                                                                            */
/* !Module          : RLYPWR                                                  */
/* !Description     : Gestionnaire du relais actionneurs                      */
/*                                                                            */
/* !File            : RlyPwr_fct1.c                                           */
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
/*   1 / RLYPWR_vidInitOutput                                                 */
/*   2 / RLYPWR_vidInitbEndDiag                                               */
/*   3 / RLYPWR_vidRlyPwrAcvCond                                              */
/*   4 / RLYPWR_vidRlyPwrDiagActif                                            */
/*   5 / RLYPWR_vidRlyPwrTestPwrlLong                                         */
/*   6 / RLYPWR_vidRlyPwrCtlMng                                               */
/*   7 / RLYPWR_vidRlyPwrActrTst                                              */
/*   8 / RLYPWR_vidInitbPwrLong                                               */
/*   9 / RLYPWR_vidRlyPwrEcoBatt                                              */
/*   10 / RLYPWR_vidRlyPwrAcvModEcoBatt                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5137464 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/RLYPWR/RlyPwr_fct1.c_v      $*/
/* $Revision::   1.12                                                        $*/
/* $Author::   etsasson                               $$Date::   12 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "RLYPWR.h"
#include "RLYPWR_L.h"
#include "RLYPWR_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidInitOutput                                       */
/* !Description :  Fonction d'initialisation de l'automate                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Rly_InitTimer_C;                                             */
/*  output st61 RlyPwrMng_stPwrRlyCmd;                                        */
/*  output boolean Actionneurs_Int;                                           */
/*  output uint16 Rly_InitTimer;                                              */
/*  output boolean Ext_bFctHldReq;                                            */
/*  output uint8 RLYPWR_u8PowercondstatePrev;                                 */
/*  output uint16 Rly_tiEndHldRlyActr;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidInitOutput(void)
{
   /* State machine initialization */
   RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_INITCLOSED;
   Actionneurs_Int = 1;
   Rly_InitTimer = (uint16)MATHSRV_udtMIN(Rly_InitTimer_C, 65000);
   /* Output initialization */
   VEMS_vidSET(Ext_bFctHldReq, 0);
   /* Initialization of variable consumed before its producing */
   RLYPWR_u8PowercondstatePrev = 0;
   Rly_tiEndHldRlyActr = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidInitbEndDiag                                     */
/* !Description :  Fonction d'initialisation.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean RlyPwr_bAcvModEcoBatt;                                      */
/*  input uint16 RlyPwr_tiWaitAcvModEcoBatt_C;                                */
/*  output boolean RlyPwr_bEndDiag;                                           */
/*  output boolean RlyPwr_bAcvModEcoBatt;                                     */
/*  output boolean Ext_bUnBlsReq;                                             */
/*  output boolean EcuSt_bPwrlLong;                                           */
/*  output boolean RlyPwr_bEngStopped;                                        */
/*  output uint16 RlyPwr_tiWaitAcvModEcoBatt;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidInitbEndDiag(void)
{
   RlyPwr_bEndDiag = 1;
   RlyPwr_bAcvModEcoBatt = 0;
   VEMS_vidSET(Ext_bUnBlsReq, RlyPwr_bAcvModEcoBatt);
   EcuSt_bPwrlLong = 0;
   RlyPwr_bEngStopped = 1;
   RlyPwr_tiWaitAcvModEcoBatt =
      (uint16)MATHSRV_udtMIN(RlyPwr_tiWaitAcvModEcoBatt_C, 38250);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrAcvCond                                    */
/* !Description :  Le relais de puissance se ferme soit dès l'entrée en réveil*/
/*                 principal, soit dès que la commande de la pompe à essence  */
/*                 est demandée soit dès qu'une session de diagnostic est     */
/*                 requise. Il est réouvert si KEY ON et moteur non tournant  */
/*                 après un certain temps.                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidRlyPwrDiagActif();                             */
/*  extf argret void RLYPWR_vidRlyPwrTestPwrlLong();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrAcvCond(void)
{
   RLYPWR_vidRlyPwrDiagActif();
   RLYPWR_vidRlyPwrTestPwrlLong();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrDiagActif                                  */
/* !Description :  Dés l’ouverture d’une session de diagnostique,  le relais  */
/*                 de puissance doit être fermé. A la fin de la session de    */
/*                 diag, le relais de puissance s’ouvre au bout d’une         */
/*                 temporisation (RlyPwr_tiAftEndDiag).                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Srv_bStartDiag;                                             */
/*  input uint16 RlyPwr_tiAftEndDiag_C;                                       */
/*  input uint16 RlyPwr_tiAftEndDiag;                                         */
/*  output boolean RlyPwr_bEndDiag;                                           */
/*  output uint16 RlyPwr_tiAftEndDiag;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrDiagActif(void)
{
   boolean bLocalSrv_bStartDiag;
   uint16  u16LocalRlyPwrtiAftEndDiag;


   VEMS_vidGET(Srv_bStartDiag, bLocalSrv_bStartDiag);
   if (bLocalSrv_bStartDiag != 0)
   {
      RlyPwr_bEndDiag = 0;
      u16LocalRlyPwrtiAftEndDiag = RlyPwr_tiAftEndDiag_C;
   }
   else
   {
      if (RlyPwr_tiAftEndDiag > 1)
      {
         u16LocalRlyPwrtiAftEndDiag = (uint16)(RlyPwr_tiAftEndDiag - 1);
      }
      else
      {
         RlyPwr_bEndDiag = 1;
         u16LocalRlyPwrtiAftEndDiag = 0;
      }
   }
   RlyPwr_tiAftEndDiag =
      (uint16)MATHSRV_udtMIN(u16LocalRlyPwrtiAftEndDiag, 65000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrTestPwrlLong                               */
/* !Description :  Condition sur la durée du Power-Latch                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_00419_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void RLYPWR_vidInitWaitPwrlEnd();                             */
/*  extf argret void RLYPWR_vidWaitPwrlEnd();                                 */
/*  input st08 Power_conditions_state;                                        */
/*  input uint8 RLYPWR_u8PowercondstatePrev;                                  */
/*  output uint8 RLYPWR_u8PowercondstatePrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrTestPwrlLong(void)
{
   /*2_RlyPwr_TestPwrlLong*/
   uint8 u8LocalPower_conditions_state;


   VEMS_vidGET(Power_conditions_state, u8LocalPower_conditions_state);
   if (u8LocalPower_conditions_state == WAITING_FOR_ANTICIPATION)
   {
      if (RLYPWR_u8PowercondstatePrev != WAITING_FOR_ANTICIPATION)
      {
         RLYPWR_vidInitWaitPwrlEnd();
      }
   }
   else
   {
      if (u8LocalPower_conditions_state == WAITING_FOR_POWER_LATCH_DELAY)
      {
         RLYPWR_vidWaitPwrlEnd();
      }
   }
   RLYPWR_u8PowercondstatePrev = u8LocalPower_conditions_state;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrCtlMng                                     */
/* !Description :  Conditions d'ouverture et de fermeture du relais.          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_00419_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Ext_bAcvLoFuPmp;                                            */
/*  input boolean ThMgt_bPwrHldTrbWaPmpReq;                                   */
/*  input boolean Crash_fps_detected;                                         */
/*  input boolean Crash_fps_confirmed;                                        */
/*  input boolean Ext_bEngStrtReq;                                            */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean Clef_de_contact;                                            */
/*  input st09 Rcd_power_state;                                               */
/*  input boolean Rcd_preparation_moteur;                                     */
/*  input boolean Ext_bAcvSta;                                                */
/*  input boolean RlyPwr_bEndDiag;                                            */
/*  input st61 RlyPwrMng_stPwrRlyCmd;                                         */
/*  input uint16 Rly_InitTimer;                                               */
/*  input boolean RLYPWR_bEcuStPwrlLongPrev;                                  */
/*  input boolean RlyPwr_bAcvModEcoBatt;                                      */
/*  input boolean RlyPwr_bModEcoBatt_Inh_C;                                   */
/*  input boolean RlyPwr_bEngStopped;                                         */
/*  input uint16 RlyPwr_tiWaitOp_C;                                           */
/*  input boolean Actionneurs_Int;                                            */
/*  input uint16 RlyPwr_tiWaitOp;                                             */
/*  input uint16 Rly_InitTimer_C;                                             */
/*  output st61 RlyPwrMng_stPwrRlyCmd;                                        */
/*  output boolean Actionneurs_Int;                                           */
/*  output uint16 Rly_InitTimer;                                              */
/*  output uint16 RlyPwr_tiWaitOp;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrCtlMng(void)
{
   /*1_RlyPwr_Acv*/
   boolean bLocalExt_bAcvLoFuPmp;
   boolean bLocalCrash_fps_detected;
   boolean bLocalCrash_fps_confirmed;
   boolean bLocalTransInitToRun;
   boolean bLocalExt_bEngStrtReq;
   boolean bLocalClef_de_contact;
   boolean bLocalThMgt_bPwrHldTrbWaPmpReq;
   boolean bLocalMoteur_tournant;
   boolean bLocalInhCmdActr;
   boolean bLocalRcd_preparation_moteur;
   boolean bLocalExt_bAcvSta;
   uint8   u8LocalRcd_power_state;
   uint16  u16Localcounter;


   VEMS_vidGET(Ext_bAcvLoFuPmp, bLocalExt_bAcvLoFuPmp);
   VEMS_vidGET(ThMgt_bPwrHldTrbWaPmpReq, bLocalThMgt_bPwrHldTrbWaPmpReq);
   VEMS_vidGET(Crash_fps_detected, bLocalCrash_fps_detected);
   VEMS_vidGET(Crash_fps_confirmed, bLocalCrash_fps_confirmed);
   VEMS_vidGET(Ext_bEngStrtReq, bLocalExt_bEngStrtReq);
   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);
   VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
   VEMS_vidGET(Rcd_preparation_moteur, bLocalRcd_preparation_moteur);
   VEMS_vidGET(Ext_bAcvSta, bLocalExt_bAcvSta);
   bLocalInhCmdActr = GDGAR_bGetFRM(FRM_FRM_INHCMDACTR);
   if (  (  (RlyPwr_bEndDiag == 0)
         || (bLocalExt_bAcvLoFuPmp != 0)
         || (bLocalThMgt_bPwrHldTrbWaPmpReq != 0)
         || (bLocalClef_de_contact != 0)
         || (bLocalExt_bEngStrtReq != 0)
         || (bLocalExt_bAcvSta != 0))
      && (bLocalCrash_fps_detected == 0)
      && (bLocalInhCmdActr == 0))
   {
      bLocalTransInitToRun = 1;
   }
   else
   {
      bLocalTransInitToRun = 0;
   }
   switch (RlyPwrMng_stPwrRlyCmd)
   {
      case RLYPWRMNG_INITCLOSED:
         if (bLocalTransInitToRun != 0)
         {
            RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_CLOSE;
            Actionneurs_Int = 1;
         }
         else
         {
            if (  (Rly_InitTimer == 0)
               || (bLocalCrash_fps_confirmed != 0))
            {
               RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_INITOPEN;
               Actionneurs_Int = 0;
            }
            else
            {
               u16Localcounter = (uint16)(Rly_InitTimer - 1);
               Rly_InitTimer = (uint16)MATHSRV_udtMIN(u16Localcounter, 65000);
            }
         }
         break;

      case RLYPWRMNG_INITOPEN:
         if (bLocalTransInitToRun != 0)
         {
            RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_CLOSE;
            Actionneurs_Int = 1;
         }
         break;

      case RLYPWRMNG_CLOSE:
         if (  (bLocalCrash_fps_confirmed != 0)
            || (  (RLYPWR_bEcuStPwrlLongPrev != 0)
               && (u8LocalRcd_power_state != RCD_ANTICIPATION)
               && (bLocalRcd_preparation_moteur == 0))
            || (bLocalInhCmdActr != 0))
         {
            RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_OPEN;
            Actionneurs_Int = 0;
         }
         else
         {
            if (  (  (bLocalClef_de_contact == 0)
                  || (  (RlyPwr_bAcvModEcoBatt != 0)
                     && (RlyPwr_bModEcoBatt_Inh_C == 0)))
               && (bLocalExt_bAcvLoFuPmp == 0)
               && (bLocalThMgt_bPwrHldTrbWaPmpReq == 0)
               && (RlyPwr_bEngStopped != 0)
               && (RlyPwr_bEndDiag != 0)
               && (  (  (RLYPWR_bEcuStPwrlLongPrev == 0)
                     || (  (u8LocalRcd_power_state == RCD_ANTICIPATION)
                        && (bLocalRcd_preparation_moteur != 0))))
               && (bLocalMoteur_tournant == 0))
            {
               RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_ACTRCUTWAIT;
               RlyPwr_tiWaitOp = (uint16)MATHSRV_udtMIN(RlyPwr_tiWaitOp_C,
                                                        65000);
            }
         }
         break;

      case RLYPWRMNG_OPEN:
         if (  (  (RlyPwr_bEndDiag == 0)
               || (bLocalExt_bAcvLoFuPmp != 0)
               || (  (bLocalClef_de_contact == 1)
                  && (RlyPwr_bAcvModEcoBatt == 0))
               || (bLocalThMgt_bPwrHldTrbWaPmpReq != 0)
               || (bLocalExt_bEngStrtReq != 0)
               || (bLocalExt_bAcvSta != 0)
               || (bLocalMoteur_tournant != 0))
            && (bLocalCrash_fps_detected == 0)
            && (bLocalCrash_fps_confirmed == 0)
            && (bLocalInhCmdActr == 0))
         {
            RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_CLOSE;
            Actionneurs_Int = 1;
         }
         break;

      case RLYPWRMNG_ACTRCUTWAIT:
         if (  (  (RlyPwr_bEndDiag == 0)
               || (  (bLocalClef_de_contact == 1)
                  && (RlyPwr_bAcvModEcoBatt == 0))
               || (bLocalExt_bAcvLoFuPmp != 0)
               || (bLocalThMgt_bPwrHldTrbWaPmpReq != 0)
               || (bLocalExt_bEngStrtReq != 0)
               || (bLocalExt_bAcvSta != 0))
            && (bLocalCrash_fps_detected == 0))
         {
            RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_CLOSE;
            Actionneurs_Int = 1;
         }
         else
         {
            if (  (  (  (Actionneurs_Int == 0)
                     || (RlyPwr_tiWaitOp == 0)
                     || (  (RLYPWR_bEcuStPwrlLongPrev != 0)
                        && (  (u8LocalRcd_power_state != RCD_ANTICIPATION)
                           && (bLocalRcd_preparation_moteur == 0))))
                  && (bLocalMoteur_tournant == 0))
               || (bLocalCrash_fps_confirmed != 0)
               || (bLocalInhCmdActr != 0) )
            {
               RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_OPEN;
               Actionneurs_Int = 0;
            }
            else
            {
               if (RlyPwr_tiWaitOp > 0)
               {
                  u16Localcounter = (uint16)(RlyPwr_tiWaitOp - 1);
                  RlyPwr_tiWaitOp =
                     (uint16)MATHSRV_udtMIN(u16Localcounter, 65000);
               }
            }
         }
         break;

      default:
         RlyPwrMng_stPwrRlyCmd = RLYPWRMNG_INITCLOSED;
         Actionneurs_Int = 1;
         Rly_InitTimer = (uint16)MATHSRV_udtMIN(Rly_InitTimer_C, 65000);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrActrTst                                    */
/* !Description :  En cas de test actionneur sur le relais de puissance       */
/*                 (PwrRly_btstInProgress = 1), on applique la commande       */
/*                 spécifique au test (PwrRly_bActrTstCmd).                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Rly_bActrTstCmd;                                            */
/*  input boolean Rly_bTstInProgress;                                         */
/*  input boolean Actionneurs_Int;                                            */
/*  output boolean Actionneurs;                                               */
/*  output boolean PwrRly_rCtl;                                               */
/*  output boolean Actionneurs_Int;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrActrTst(void)
{
   /*5_RlyPwr_ActrTst*/
   boolean   bLocalRly_bActrTstCmd;
   boolean   bLocalRly_bTstInProgress;
   boolean   bLocalInhCmdActr;


   VEMS_vidGET(Rly_bActrTstCmd, bLocalRly_bActrTstCmd);
   VEMS_vidGET(Rly_bTstInProgress, bLocalRly_bTstInProgress);
   bLocalInhCmdActr = GDGAR_bGetFRM(FRM_FRM_INHCMDACTR);
   if (  (bLocalRly_bTstInProgress != 0)
      && (bLocalInhCmdActr == 0))
   {
      VEMS_vidSET(Actionneurs, bLocalRly_bActrTstCmd);
      VEMS_vidSET(PwrRly_rCtl, bLocalRly_bActrTstCmd);
   }
   else
   {
      VEMS_vidSET(Actionneurs, Actionneurs_Int);
      VEMS_vidSET(PwrRly_rCtl, Actionneurs_Int);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidInitbPwrLong                                     */
/* !Description :  Le booléen EcuSt_bPwrlLong est réinitialisé sur transition */
/*                 clé off /clé on pour éviter que le relais actionneur soit  */
/*                 commandé en ouverture et en continu dans le cas où on      */
/*                 revient d’un power-latch très long à POWER_ON sans         */
/*                 réinitialisé le calculateur                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean EcuSt_bPwrlLong;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidInitbPwrLong(void)
{
   EcuSt_bPwrlLong = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrEcoBatt                                    */
/* !Description :  Ouverture du relais au bout d'un certain temps si son      */
/*                 maintien en position fermée n'est pas justifié.            */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_00419_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void RLYPWR_vidRlyPwrAcvModEcoBatt();                         */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean Clef_de_contact;                                            */
/*  output boolean RlyPwr_bEngStopped;                                        */
/*  output boolean RlyPwr_bActivTempoEcoBatt;                                 */
/*  output boolean RlyPwr_bInitTempoEcoBatt;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrEcoBatt(void)
{
   /*4_RlyPwr_EcoBatt*/
   boolean bLocalClef_de_contact;
   uint8   u8LocalCoPTSt_stEng;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (u8LocalCoPTSt_stEng == 1)
   {
      RlyPwr_bEngStopped = 1;
      if (bLocalClef_de_contact != 0)
      {
         RlyPwr_bActivTempoEcoBatt = 1;
         RlyPwr_bInitTempoEcoBatt = 0;
      }
      else
      {
         RlyPwr_bActivTempoEcoBatt = 0;
         RlyPwr_bInitTempoEcoBatt = 1;
      }
   }
   else
   {
      RlyPwr_bEngStopped = 0;
      if (u8LocalCoPTSt_stEng == 2)
      {
         if (bLocalClef_de_contact != 0)
         {
            RlyPwr_bActivTempoEcoBatt = 1;
            RlyPwr_bInitTempoEcoBatt = 0;
         }
         else
         {
            RlyPwr_bActivTempoEcoBatt = 0;
            RlyPwr_bInitTempoEcoBatt = 1;
         }
      }
      else
      {
         RlyPwr_bActivTempoEcoBatt = 0;
         RlyPwr_bInitTempoEcoBatt = 1;
      }
   }
   RLYPWR_vidRlyPwrAcvModEcoBatt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RLYPWR_vidRlyPwrAcvModEcoBatt                              */
/* !Description :  Afin de limiter la consommation électrique batterie au sein*/
/*                 du véhicule, le relais est ouvert au bout d'une certaine   */
/*                 durée, dans le cas où le client entre dans la voiture, met */
/*                 le contact, mais ne démarre pas.                           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_00419_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RLYPWR_vidInitWaitAcvModEcoBatt();                       */
/*  extf argret void RLYPWR_vidWaitAcvModEcoBatt();                           */
/*  extf argret void RLYPWR_vidWaitAcvModEcoBattCalib();                      */
/*  input boolean RlyPwr_bModEcoBatt_Inh_C;                                   */
/*  input boolean RlyPwr_bInitTempoEcoBatt;                                   */
/*  input boolean RlyPwr_bActivTempoEcoBatt;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RLYPWR_vidRlyPwrAcvModEcoBatt(void)
{
   /*0_RlyPwr_AcvModEcoBattCond*/
   if (RlyPwr_bModEcoBatt_Inh_C == 0)
   {
      if (RlyPwr_bInitTempoEcoBatt != 0)
      {
         RLYPWR_vidInitWaitAcvModEcoBatt();
      }
      if (RlyPwr_bActivTempoEcoBatt != 0)
      {
         RLYPWR_vidWaitAcvModEcoBatt();
      }
   }
   else
   {
      RLYPWR_vidWaitAcvModEcoBattCalib();
   }
}
/*------------------------------- end of file --------------------------------*/