/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCMDMISFGENR                                           */
/* !Description     : IGCMDMISFGENR component.                                */
/*                                                                            */
/* !Module          : IGCMDMISFGENR                                           */
/* !Description     : Générateur De Ratés D'allumage.                         */
/*                                                                            */
/* !File            : IGCMDMISFGENR_FCT1.C                                    */
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
/*   1 / IGCMDMISFGENR_vidInit                                                */
/*   2 / IGCMDMISFGENR_vidInitOutput                                          */
/*   3 / IGCMDMISFGENR_vidManageMisfCoils                                     */
/*   4 / IGCMDMISFGENR_vidAutorisMisfConf                                     */
/*   5 / IGCMDMISFGENR_vidInhibMisfConf                                       */
/*   6 / IGCMDMISFGENR_vidMisfireCylinder                                     */
/*   7 / IGCMDMISFGENR_vidDeterministMode                                     */
/*   8 / IGCMDMISFGENR_vidRandomMode                                          */
/*   9 / IGCMDMISFGENR_vidReachedRecur                                        */
/*   10 / IGCMDMISFGENR_vidNotReachedRecur                                    */
/*                                                                            */
/* !Reference   : V02 NT 09 06148 / 06                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/MISF/IGCMDMISFGENR/IGCMDMISFGENR$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   26 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   26 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCMDMISFGENR.h"
#include "IGCMDMISFGENR_L.h"
#include "IGCMDMISFGENR_IM.h"
#include "VEMS.h"
#include "GPT.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidInit                                      */
/* !Description :  Initialisation des variables au reset.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Autorisation_misfire;                                       */
/*  input uint8 Recurrence_misfire_deterministe;                              */
/*  input boolean Mode_successif;                                             */
/*  input uint16 Taux_misfire_aleatoire;                                      */
/*  input boolean Mode_deterministe;                                          */
/*  output uint8 Msm_spark_counter;                                           */
/*  output uint8 Misfire_cylindre;                                            */
/*  output boolean Misfire_cylindre_1;                                        */
/*  output boolean Misfire_cylindre_2;                                        */
/*  output boolean Misfire_cylindre_3;                                        */
/*  output boolean Misfire_cylindre_4;                                        */
/*  output uint16 Taux_deterministe;                                          */
/*  output uint16 Taux_aleatoire;                                             */
/*  output uint16 Taux_misfire;                                               */
/*  output boolean Autorisation_misfire_confirmee;                            */
/*  output uint16 Taux_misfire_reel;                                          */
/*  output uint16 Cnt_misfire;                                                */
/*  output uint16 Cnt_global;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidInit(void)
{
   /* 01_init */
   uint16  u16LocalTaux;
   uint32  u32LocalTaux;


   Msm_spark_counter = 0;
   VEMS_vidSET(Misfire_cylindre, 0);
   VEMS_vidSET(Misfire_cylindre_1, 0);
   VEMS_vidSET(Misfire_cylindre_2, 0);
   VEMS_vidSET(Misfire_cylindre_3, 0);
   VEMS_vidSET(Misfire_cylindre_4, 0);

   if (Autorisation_misfire != 0)
   {
      if (Recurrence_misfire_deterministe == 0)
      {
         u32LocalTaux = 65535;
      }
      else
      {
         if (Mode_successif != 0)
         {
            u32LocalTaux = (uint32)(131072 / Recurrence_misfire_deterministe);
         }
         else
         {
            u32LocalTaux = (uint32)(65536 / Recurrence_misfire_deterministe);
         }
      }
      u16LocalTaux = (uint16)MATHSRV_udtMIN(u32LocalTaux, 65535);
      VEMS_vidSET(Taux_deterministe, u16LocalTaux);
      VEMS_vidSET(Taux_aleatoire, Taux_misfire_aleatoire);

      if (Mode_deterministe != 0)
      {
         VEMS_vidSET(Taux_misfire, u16LocalTaux);
      }
      else
      {
         VEMS_vidSET(Taux_misfire, Taux_misfire_aleatoire);
      }
   }
   else
   {
      VEMS_vidSET(Taux_deterministe, 0);
      VEMS_vidSET(Taux_aleatoire, 0);
      VEMS_vidSET(Taux_misfire, 0);
   }

   Autorisation_misfire_confirmee = 0;
   VEMS_vidSET(Taux_misfire_reel, 0);
   Cnt_misfire = 0;
   Cnt_global = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidInitOutput                                */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean IGCMDMISFGENR_bAutorisMisfirPrev;                          */
/*  output boolean IGCMDMISFGENR_bInhibMisfirePrev;                           */
/*  output uint8 Misfire_cylindre_al;                                         */
/*  output uint8 Misfire_cylindre_det;                                        */
/*  output boolean IGCMDMISFGENR_bLocalRstPrev_Prev;                          */
/*  output boolean IGCMDMISFGENR_bLocalRst_Prev;                              */
/*  output boolean IGCMDMISFGENR_bLocalRst2_Prev;                             */
/*  output uint16 IGCMDMISFGENR_u16TauxmisfirePrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidInitOutput(void)
{
   IGCMDMISFGENR_bAutorisMisfirPrev = 0;
   IGCMDMISFGENR_bInhibMisfirePrev = 0;
   Misfire_cylindre_al = 0;
   Misfire_cylindre_det = 0;
   IGCMDMISFGENR_bLocalRstPrev_Prev = 0;
   IGCMDMISFGENR_bLocalRst_Prev = 0;
   IGCMDMISFGENR_bLocalRst2_Prev = 0;
   IGCMDMISFGENR_u16TauxmisfirePrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidManageMisfCoils                           */
/* !Description :  Gestion des Misfire des  bobines.                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Gpt_GetTimeElapsed(argin uint16 channel)uint32;          */
/*  extf argret void IGCMDMISFGENR_vidAutorisMisfConf();                      */
/*  extf argret void IGCMDMISFGENR_vidInhibMisfConf();                        */
/*  extf argret void IGCMDMISFGENR_vidMisfireCylinder();                      */
/*  extf argret void IGCMDMISFGENR_vidMisfireGenStop();                       */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Cipd_phase_terminated;                                      */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input boolean Cipd_inh_dephia;                                            */
/*  input uint8 Recurrence_misfire_deterministe;                              */
/*  input boolean Autorisation_misfire;                                       */
/*  input boolean IgCmd_bEngPha;                                              */
/*  input uint8 Msm_coupure_cylindre;                                         */
/*  input boolean Autorisation_misfire_confirmee;                             */
/*  input boolean IGCMDMISFGENR_bAutorisMisfirPrev;                           */
/*  input boolean IGCMDMISFGENR_bInhibMisfirePrev;                            */
/*  output boolean IgCmd_bEngPha;                                             */
/*  output uint16 IgCmd_MisfGenrTimer;                                        */
/*  output boolean IGCMDMISFGENR_bAutorisMisfirPrev;                          */
/*  output boolean IGCMDMISFGENR_bInhibMisfirePrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidManageMisfCoils(void)
{
   /* 02_manager_misfire_bobines */
   boolean bLocalExt_bPresInCmSen;
   boolean bLocalMoteur_synchronise;
   boolean bLocalCipd_phase_terminated;
   boolean bLocalInhibMisfire;
   boolean bLocalActivMisfire;
   uint8   u8LocalEng_noCmprCyl;
   uint32  u32LocalIgCmd_MisfGenrTimer;


   VEMS_vidGET(Ext_bPresInCmSen, bLocalExt_bPresInCmSen);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Cipd_phase_terminated, bLocalCipd_phase_terminated);
   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);

   if (  (bLocalExt_bPresInCmSen != 0)
      && (Cipd_inh_dephia != 0))
   {
      IgCmd_bEngPha = bLocalMoteur_synchronise;
   }
   else
   {
      IgCmd_bEngPha = bLocalCipd_phase_terminated;
   }

   u32LocalIgCmd_MisfGenrTimer =
      Gpt_GetTimeElapsed(GPT_udtGPT_APPLICATIVE_TIME);
   IgCmd_MisfGenrTimer = (uint16)(u32LocalIgCmd_MisfGenrTimer & 0x7FF);

   bLocalActivMisfire = 0;
   if (  (Recurrence_misfire_deterministe != 0)
      && (Autorisation_misfire != 0)
      && (IgCmd_bEngPha != 0))
   {
      bLocalInhibMisfire = 1;
      if (  (u8LocalEng_noCmprCyl == Msm_coupure_cylindre)
         && (Autorisation_misfire_confirmee == 0))
      {
         bLocalActivMisfire = 1;
         if (IGCMDMISFGENR_bAutorisMisfirPrev == 0)
         {
            IGCMDMISFGENR_vidAutorisMisfConf();
         }
      }
   }
   else
   {
      bLocalInhibMisfire = 0;
      if (IGCMDMISFGENR_bInhibMisfirePrev != 0)
      {
         IGCMDMISFGENR_vidInhibMisfConf();
      }
   }

   if (Autorisation_misfire_confirmee != 0)
   {
      IGCMDMISFGENR_vidMisfireCylinder();
   }
   else
   {
      IGCMDMISFGENR_vidMisfireGenStop();
   }
   IGCMDMISFGENR_bAutorisMisfirPrev = bLocalActivMisfire;
   IGCMDMISFGENR_bInhibMisfirePrev = bLocalInhibMisfire;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidAutorisMisfConf                           */
/* !Description :  Cette fonction permet l'initialisation de Msm_spark_counter*/
/*                 à Recurrence_misfire_deterministe afin de déclencher un    */
/*                 misfire sur le premier cylindre choisi par                 */
/*                 Msm_coupure_cylindre.                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Recurrence_misfire_deterministe;                              */
/*  output uint8 Msm_spark_counter;                                           */
/*  output boolean Autorisation_misfire_confirmee;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidAutorisMisfConf(void)
{
   Msm_spark_counter = Recurrence_misfire_deterministe;
   Autorisation_misfire_confirmee = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidInhibMisfConf                             */
/* !Description :  Cette fonction permet la réinitalisation du calcul du      */
/*                 générateur de misfire.                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Msm_spark_counter;                                           */
/*  output boolean Autorisation_misfire_confirmee;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidInhibMisfConf(void)
{
   Msm_spark_counter = 0;
   Autorisation_misfire_confirmee = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidMisfireCylinder                           */
/* !Description :  Cette fonction permet de faire le choix du mode de         */
/*                 génération de misfire : Déterministe ou Aléatoire.         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidDeterministMode();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void IGCMDMISFGENR_vidRandomMode();                           */
/*  input boolean Mode_deterministe;                                          */
/*  input uint8 Misfire_cylindre_det;                                         */
/*  input uint8 Misfire_cylindre_al;                                          */
/*  output uint8 Misfire_cylindre;                                            */
/*  output uint8 Misfire_cylindre_det;                                        */
/*  output uint8 Misfire_cylindre_al;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidMisfireCylinder(void)
{
   /* 03_Misfire_cylindre */
   if (Mode_deterministe != 0)
   {
      IGCMDMISFGENR_vidDeterministMode();
      VEMS_vidSET(Misfire_cylindre, Misfire_cylindre_det);
   }
   else
   {
      IGCMDMISFGENR_vidRandomMode();
      VEMS_vidSET(Misfire_cylindre, Misfire_cylindre_al);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidDeterministMode                           */
/* !Description :  Cette fonction permet de couper la bobine courante en mode */
/*                 déterministe et d' autoriser aussi la coupure de la bobine */
/*                 suivante en cas de mode successif.                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCMDMISFGENR_vidReachedRecur();                         */
/*  extf argret void IGCMDMISFGENR_vidNotReachedRecur();                      */
/*  input uint8 Msm_spark_counter;                                            */
/*  input uint8 Recurrence_misfire_deterministe;                              */
/*  input boolean Mode_successif;                                             */
/*  output uint8 Msm_spark_counter;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidDeterministMode(void)
{
   uint16 u16LocalMsm_spark_counter;


   u16LocalMsm_spark_counter = (uint16)(Msm_spark_counter + 1);
   Msm_spark_counter = (uint8)MATHSRV_udtMIN(u16LocalMsm_spark_counter, 255);
   if (  (Msm_spark_counter >= Recurrence_misfire_deterministe)
      || (  (Mode_successif != 0)
         && (Msm_spark_counter == 1)))
   {
      IGCMDMISFGENR_vidReachedRecur();
   }
   else
   {
      IGCMDMISFGENR_vidNotReachedRecur();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidRandomMode                                */
/* !Description :  Cette fonction produit l'indicateur de génération d'un raté*/
/*                 d'allumage.                                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void IGCMDMISFGENR_vidInitcompteurs();                        */
/*  extf argret void IGCMDMISFGENR_vidTauxmisfirereel();                      */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint16 Taux_misfire_aleatoire;                                      */
/*  input uint16 IgCmd_MisfGenrTimer;                                         */
/*  input boolean IGCMDMISFGENR_bLocalRst2_Prev;                              */
/*  input boolean IGCMDMISFGENR_bLocalRstPrev_Prev;                           */
/*  input boolean IGCMDMISFGENR_bLocalRst_Prev;                               */
/*  input boolean Misfire_al;                                                 */
/*  input uint8 Misfire_cylindre_al;                                          */
/*  input uint16 IGCMDMISFGENR_u16TauxmisfirePrev;                            */
/*  input uint16 Cnt_global;                                                  */
/*  output uint8 Msm_spark_counter;                                           */
/*  output boolean Misfire_al;                                                */
/*  output uint8 Misfire_cylindre_al;                                         */
/*  output boolean IGCMDMISFGENR_bLocalRstPrev_Prev;                          */
/*  output boolean IGCMDMISFGENR_bLocalRst_Prev;                              */
/*  output boolean IGCMDMISFGENR_bLocalRst2_Prev;                             */
/*  output uint16 IGCMDMISFGENR_u16TauxmisfirePrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidRandomMode(void)
{
   /* 02_Mode_aleatoire */
   boolean bLocalRst1;
   boolean bLocalRst2;
   boolean bLocalOutOR;
   uint8   u8LocalEng_noCmprCyl;
   uint8   u8LocalMisfire_cylindre_al;
   uint32  u32LocalClac;
   uint32  u32LocalTauxMmisfireAleatoire;
   uint32  u32LocalMod;
   uint32  u32LocalMisfGenrTimer;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   Msm_spark_counter = 0;
   u32LocalClac = (uint32)(Taux_misfire_aleatoire * 2048);
   u32LocalMisfGenrTimer = (uint32)(65536 * IgCmd_MisfGenrTimer);

   if (u32LocalMisfGenrTimer < u32LocalClac)
   {
      bLocalRst1 = 1;
   }
   else
   {
      bLocalRst1 = 0;
   }

   u32LocalMod = (uint32)((16 * IgCmd_MisfGenrTimer) % 8192) * 65536;
   u32LocalTauxMmisfireAleatoire = (uint32)(8192 * Taux_misfire_aleatoire);

   if (  (u32LocalMod < u32LocalTauxMmisfireAleatoire)
      && (bLocalRst1 != 0))
   {
      bLocalRst2 = 1;
   }
   else
   {
      bLocalRst2 = 0;
   }

   if (  (bLocalRst1 != 0)
      || (IGCMDMISFGENR_bLocalRst2_Prev != 0))
   {
      bLocalOutOR = 1;
   }
   else
   {
      bLocalOutOR = 0;
   }

   if (  (IGCMDMISFGENR_bLocalRstPrev_Prev != 0)
      && (IGCMDMISFGENR_bLocalRst_Prev != 0)
      && (bLocalRst1 != 0))
   {
      Misfire_al = 0;
   }
   else
   {
      Misfire_al = bLocalOutOR;
   }
   u8LocalMisfire_cylindre_al = 0;
   switch (u8LocalEng_noCmprCyl)
   {
      case 1:
         /* QAC Warning : Msg(2:2215) : This warning 2215 is to ignore if VEMS
         indentation rule is respected. */
         if (Misfire_al != 0)
         {
            u8LocalMisfire_cylindre_al =
               (uint8)(u8LocalMisfire_cylindre_al | 0x01);
         }
         break;

      case 2:
         if (Misfire_al != 0)
         {
            u8LocalMisfire_cylindre_al =
               (uint8)(u8LocalMisfire_cylindre_al | 0x02);
         }
         break;

      case 3:
         if (Misfire_al != 0)
         {
            u8LocalMisfire_cylindre_al =
               (uint8)(u8LocalMisfire_cylindre_al | 0x04);
         }
         break;

      case 4:
         if (Misfire_al != 0)
         {
            u8LocalMisfire_cylindre_al =
               (uint8)(u8LocalMisfire_cylindre_al | 0x08);
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   Misfire_cylindre_al = u8LocalMisfire_cylindre_al;

   if (Taux_misfire_aleatoire != IGCMDMISFGENR_u16TauxmisfirePrev)
   {
      IGCMDMISFGENR_vidInitcompteurs();
   }
   if (Cnt_global != 65535)
   {
      IGCMDMISFGENR_vidTauxmisfirereel();
   }

   IGCMDMISFGENR_bLocalRstPrev_Prev = IGCMDMISFGENR_bLocalRst_Prev;
   IGCMDMISFGENR_bLocalRst_Prev = bLocalRst1;
   IGCMDMISFGENR_bLocalRst2_Prev = bLocalRst2;
   IGCMDMISFGENR_u16TauxmisfirePrev = Taux_misfire_aleatoire;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidReachedRecur                              */
/* !Description :  Cette fonction permet,lorsque                              */
/*                 Recurrence_misfire_deterministe est atteinte, de générer un*/
/*                 misfire sur le cylindre actuellement en compression.Dans le*/
/*                 cas d’un mode successif, elle permet l'inhibition de la    */
/*                 réinitialisation du compteur de récurrence.                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void IGCMDMISFGENR_vidRazMsmSparkCnt();                       */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 Misfire_cylindre_det;                                         */
/*  input boolean Mode_successif;                                             */
/*  input uint8 Msm_spark_counter;                                            */
/*  output uint8 Misfire_cylindre_det;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidReachedRecur(void)
{
   uint8  u8LocalEng_noCmprCyl;
   uint8  u8LocalMisfire_cylindre_det;


   u8LocalMisfire_cylindre_det = 0;
   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch (u8LocalEng_noCmprCyl)
   {
      case 1:
         u8LocalMisfire_cylindre_det =
            (uint8)(u8LocalMisfire_cylindre_det | 0x01);
         break;

      case 2:
         u8LocalMisfire_cylindre_det =
            (uint8)(u8LocalMisfire_cylindre_det | 0x02);
         break;

      case 3:
         u8LocalMisfire_cylindre_det =
            (uint8)(u8LocalMisfire_cylindre_det | 0x04);
         break;

      case 4:
         u8LocalMisfire_cylindre_det =
            (uint8)(u8LocalMisfire_cylindre_det | 0x08);
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   Misfire_cylindre_det = u8LocalMisfire_cylindre_det;
   if (  (Mode_successif == 0)
      || (Msm_spark_counter != 1))
   {
      IGCMDMISFGENR_vidRazMsmSparkCnt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCMDMISFGENR_vidNotReachedRecur                           */
/* !Description :  Cette fonction permet, si Recurrence_misfire_deterministe  */
/*                 n’est pas atteinte, d'initialiser Misfire_cylindre à zéro. */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Misfire_cylindre_det;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCMDMISFGENR_vidNotReachedRecur(void)
{
   Misfire_cylindre_det = 0;
}
/****************************** end of file ***********************************/