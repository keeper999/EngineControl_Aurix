/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKSHDCOR                                               */
/* !Description     : KNKSHDCOR Component                                     */
/*                                                                            */
/* !Module          : KNKSHDCOR                                               */
/* !Description     : Correction palliative de cliquetis                      */
/*                                                                            */
/* !File            : KNKSHDCOR_FCT1.C                                        */
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
/*   1 / KNKSHDCOR_vidInit                                                    */
/*   2 / KNKSHDCOR_vidCorr_manager                                            */
/*   3 / KNKSHDCOR_vidCorrect_palliative                                      */
/*   4 / KNKSHDCOR_vidCorr_manage                                             */
/*   5 / KNKSHDCOR_vidWin_manage                                              */
/*   6 / KNKSHDCOR_vidInit_win                                                */
/*   7 / KNKSHDCOR_vidDec_win                                                 */
/*   8 / KNKSHDCOR_vidKnk_count                                               */
/*   9 / KNKSHDCOR_vidCorr_calculate                                          */
/*   10 / KNKSHDCOR_vidraz_corr                                               */
/*                                                                            */
/* !Reference: V02 NT 08 07294 / 03                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKSHDCOR/KNKSHDCOR_FCT1.C_v$*/
/* $Revision::   1.2      $$Author::   vgarnier       $$Date::   25 Mar 2010 $*/
/* $Author::   vgarnier                               $$Date::   25 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "KNKSHDCOR.H"
#include "KNKSHDCOR_L.H"
#include "KNKSHDCOR_IM.H"
#include "VEMS.H"

#define INDEX 4


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidInit                                           */
/* !Description : Au Reset du calculateur (EveRst), ainsi qu’a l’activation   */
/*                des combustions (EveRTSn), on réinitialise les variables de */
/*                la stratégie.                                               */
/* !Number      : FCT1.1                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   output uint8 Knk_deg_det_count_uavn1[4];                                 */
/*   output uint8 Knk_deg_obs_win_uavn1[4];                                   */
/*   output uint16 Knk_deg_cor_tempo_uavn0;                                   */
/*   output uint8 Knk_deg_cor_uavn0;                                          */
/*   output uint8 KnkMgt_agIgOfsKnkDft;                                       */
/*   output uint8 Knk_deg_cor_av_filt_uavn0;                                  */
/*   output boolean knk_corr_inc_uavb0;                                       */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidInit(void)
{
   Knk_deg_det_count_uavn1[0] = 0;
   Knk_deg_det_count_uavn1[1] = 0;
   Knk_deg_det_count_uavn1[2] = 0;
   Knk_deg_det_count_uavn1[3] = 0;
   Knk_deg_obs_win_uavn1[0] = 0;
   Knk_deg_obs_win_uavn1[1] = 0;
   Knk_deg_obs_win_uavn1[2] = 0;
   Knk_deg_obs_win_uavn1[3] = 0;
   Knk_deg_cor_tempo_uavn0 = 0;
   VEMS_vidSET(Knk_deg_cor_uavn0, 0);
   VEMS_vidSET(KnkMgt_agIgOfsKnkDft, 96);
   Knk_deg_cor_av_filt_uavn0 = 0;
   knk_corr_inc_uavb0 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_manager                                   */
/* !Description : Si la stratégie de détection palliative de cliquetis est    */
/*                inhibée, la correction palliative n’a pas lieu d’être       */
/*                activée.                                                    */
/* !Number      : FCT1.2                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void KNKSHDCOR_vidCorrect_palliative();                      */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input boolean Knk_deg_manu_inh_Acv;                                      */
/*   input boolean Knk_deg_det_cur_manu_inh_uacb0;                            */
/*   input uint8 Knk_deg_cor_uavn0;                                           */
/*   output uint8 KnkMgt_agIgOfsKnkDft;                                       */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_manager(void)
{
   boolean bLocalKnk_deg_manu_inh_Acv;
   uint8   u8LocalKnk_deg_cor_uavn0;
   uint16  u16LocalKnk_deg_cor_uavn0;


   VEMS_vidGET(Knk_deg_manu_inh_Acv, bLocalKnk_deg_manu_inh_Acv);
   if (  (Knk_deg_det_cur_manu_inh_uacb0 != 0)
      && (bLocalKnk_deg_manu_inh_Acv == 0))
   {
      KNKSHDCOR_vidCorrect_palliative();
   }

   VEMS_vidGET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);
   u16LocalKnk_deg_cor_uavn0 = (uint16)(u8LocalKnk_deg_cor_uavn0 + 96);
   u8LocalKnk_deg_cor_uavn0 = (uint8)(MATHSRV_udtMIN(u16LocalKnk_deg_cor_uavn0,
                                                     255));
   VEMS_vidSET(KnkMgt_agIgOfsKnkDft, u8LocalKnk_deg_cor_uavn0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorrect_palliative                             */
/* !Description : En cas de sortie de zone critique ou de zone d'autorisation */
/*                cliquetis, la correction palliative est filtrée vers 0.Lors */
/*                du retour en zone critique, la correction revient par       */
/*                filtrage à sa valeur lors de la sortie de la zone critique. */
/* !Number      : FCT1.3                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void KNKSHDCOR_vidCorr_manage();                             */
/*   extf argret void KNKSHDCOR_vidraz_corr();                                */
/*   input boolean Zone_critique;                                             */
/*   input boolean Autorise_detection_clq;                                    */
/*   input boolean Knk_deg_zc_manu_inh_uacb0;                                 */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorrect_palliative(void)
{
   boolean bLocalZone_critique;
   boolean bLocalAutorise_detection_clq;


   VEMS_vidGET(Zone_critique, bLocalZone_critique);
   VEMS_vidGET(Autorise_detection_clq, bLocalAutorise_detection_clq);
   if (  (  (bLocalZone_critique != 0)
         || (Knk_deg_zc_manu_inh_uacb0 != 0))
      && (bLocalAutorise_detection_clq != 0))
   {
      KNKSHDCOR_vidCorr_manage();
   }
   else
   {
      KNKSHDCOR_vidraz_corr();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_manage                                    */
/* !Description : La correction d’avance anti-cliquetis est décomposée en deux*/
/*                parties : Gestion des fenêtres d'observation des détections */
/*                dégradées et Gestion de la correction s'il y a eu un nombre */
/*                de détections dégradées suffisantes lors de l'observation.  */
/* !Number      : FCT1.4                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void KNKSHDCOR_vidWin_manage();                              */
/*   extf argret void KNKSHDCOR_vidCorr_calculate();                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_manage(void)
{
   KNKSHDCOR_vidWin_manage();
   KNKSHDCOR_vidCorr_calculate();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidWin_manage                                     */
/* !Description : Une fois la détection palliative réalisée, on utilise une   */
/*                fenêtre d’observation (en nombre de cycles) pour confirmer  */
/*                ou non la présence de cliquetis.                            */
/* !Number      : FCT1.5                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET1DArray(argin, argin, argio);                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void KNKSHDCOR_vidInit_win();                                */
/*   extf argret void KNKSHDCOR_vidDec_win();                                 */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*   input boolean Knk_deg_det_uavb1[4];                                      */
/*   input uint8 Eng_noCmprCyl;                                               */
/*   input uint8 Knk_deg_obs_win_uavn1[4];                                    */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidWin_manage(void)
{
   boolean bLocalKnk_deg_det_uavb1[INDEX];
   uint8   u8LocalEng_noCmprCyl;


   /* Initialization used in order to avoid QAC warning 3204 */
   bLocalKnk_deg_det_uavb1[0] = 0;

   VEMS_vidGET1DArray(Knk_deg_det_uavb1, 4, bLocalKnk_deg_det_uavb1);
   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         if (Knk_deg_obs_win_uavn1[u8LocalEng_noCmprCyl] == 0)
         {
            if (bLocalKnk_deg_det_uavb1[u8LocalEng_noCmprCyl] != 0)
            {
               KNKSHDCOR_vidInit_win();
            }
         }
         else
         {
            KNKSHDCOR_vidDec_win();
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidInit_win                                       */
/* !Description : Ouvertire de la fenêtre d'observation suite à une détection */
/*                palliative du premier coup de cliquetis.                    */
/* !Number      : FCT1.6                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*   input uint16 Regime_moteur;                                              */
/*   input uint16 Regime_moteur_bkpt_map[16];                                 */
/*   input uint8 Knk_deg_obs_win_length_uacn1[16];                            */
/*   input uint8 Eng_noCmprCyl;                                               */
/*   output uint8 Knk_deg_obs_win_uavn1[4];                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidInit_win(void)
{
   uint8  u8LocalEng_noCmprCyl;
   uint8  u8LocalInterp;
   uint16 u16LocalPara;
   uint16 u16LocalRegime_moteur;
   uint32 u32LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u32LocalRegime_moteur = (uint32)(u16LocalRegime_moteur * 8);
   u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u32LocalRegime_moteur, 65535);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                               u16LocalRegime_moteur,
                                               16);
   u8LocalInterp = MATHSRV_u8Interp1d(Knk_deg_obs_win_length_uacn1,
                                      u16LocalPara);

   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         Knk_deg_obs_win_uavn1[u8LocalEng_noCmprCyl] = u8LocalInterp;
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidDec_win                                        */
/* !Description : comptage du nombres de "coups de cliquetis" pendant la      */
/*                fenêtre d'observation                                       */
/* !Number      : FCT1.7                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET1DArray(argin, argin, argio);                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void KNKSHDCOR_vidKnk_count();                               */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*   input boolean Knk_deg_det_uavb1[4];                                      */
/*   input uint8 Eng_noCmprCyl;                                               */
/*   input uint8 Knk_deg_obs_win_uavn1[4];                                    */
/*   output uint8 Knk_deg_obs_win_uavn1[4];                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidDec_win(void)
{
   boolean bLocalKnk_deg_det_uavb1[INDEX];
   uint8   u8LocalEng_noCmprCyl;


   /* Initialization used in order to avoid QAC warning 3204 */
   bLocalKnk_deg_det_uavb1[0] = 0;

   VEMS_vidGET1DArray(Knk_deg_det_uavb1, 4, bLocalKnk_deg_det_uavb1);
   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         if (Knk_deg_obs_win_uavn1[u8LocalEng_noCmprCyl] > 0)
         {
            Knk_deg_obs_win_uavn1[u8LocalEng_noCmprCyl] =
               (uint8)(Knk_deg_obs_win_uavn1[u8LocalEng_noCmprCyl] - 1);
         }
         if (bLocalKnk_deg_det_uavb1[u8LocalEng_noCmprCyl] != 0)
         {
            KNKSHDCOR_vidKnk_count();
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidKnk_count                                      */
/* !Description : A chaque fois que l’on détecte un « coup de cliquetis » de  */
/*                la stratégie palliative, on incrémente le compteur          */
/*                Knk_deg_det_count_uavn1 du cylindre considéré.              */
/* !Number      : FCT1.8                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*   input uint8 Eng_noCmprCyl;                                               */
/*   input uint8 Knk_deg_det_count_uavn1[4];                                  */
/*   output uint8 Knk_deg_det_count_uavn1[4];                                 */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidKnk_count(void)
{
   uint8 u8LocalEng_noCmprCyl;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         if (Knk_deg_det_count_uavn1[u8LocalEng_noCmprCyl] < 255)
         {
            Knk_deg_det_count_uavn1[u8LocalEng_noCmprCyl] =
               (uint8)(Knk_deg_det_count_uavn1[u8LocalEng_noCmprCyl] + 1);
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_calculate                                 */
/* !Description : La correction d’avance anti-cliquetis est appliquée si dans */
/*                la fenêtre d’observation, le nombre de « coups de cliquetis */
/*                » en mode dégradé dépasse un seuil calibrable.              */
/* !Number      : FCT1.9                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void KNKSHDCOR_vidCorr_init();                               */
/*   extf argret void KNKSHDCOR_vidReset_win();                               */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*   extf argret void KNKSHDCOR_vidCorr_enable();                             */
/*   extf argret void KNKSHDCOR_vidCorr_inc();                                */
/*   extf argret void KNKSHDCOR_vidCorr_dec();                                */
/*   input uint8 Eng_noCmprCyl;                                               */
/*   input uint8 Knk_deg_det_count_uavn1[4];                                  */
/*   input uint8 Knk_deg_det_count_thr_uacn0;                                 */
/*   input uint8 Knk_deg_obs_win_uavn1[4];                                    */
/*   input uint8 Knk_deg_cor_uavn0;                                           */
/*   input uint8 Knk_deg_cor_av_filt_uavn0;                                   */
/*   input boolean Changement_rapport_bvm;                                    */
/*   input boolean Bvmp_inh_cliq_acquisition;                                 */
/*   input boolean Bv_changement_rapport;                                     */
/*   input boolean Presence_bva;                                              */
/*   input boolean Knk_deg_bv_chgt_inh_uacb0;                                 */
/*   input boolean knk_corr_inc_uavb0;                                        */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_calculate(void)
{
   boolean bLocalChangement_rapport_bvm;
   boolean bLocalBvmp_inh_cliq_acquisition;
   boolean bLocalBv_changement_rapport;
   boolean bLocalPresence_bva;
   boolean bLocalknk_deg_bv_chgt_uavb0;
   uint8   u8LocalEng_noCmprCyl;
   uint8   u8LocalKnk_deg_cor_uavn0;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         if (Knk_deg_det_count_uavn1[u8LocalEng_noCmprCyl] >=
             Knk_deg_det_count_thr_uacn0)
         {
            KNKSHDCOR_vidCorr_init();
         }

         if (Knk_deg_obs_win_uavn1[u8LocalEng_noCmprCyl] == 0)
         {
            KNKSHDCOR_vidReset_win();
         }
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   VEMS_vidGET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);
   if (Knk_deg_cor_av_filt_uavn0 != u8LocalKnk_deg_cor_uavn0)
   {
      KNKSHDCOR_vidCorr_enable();
   }

   VEMS_vidGET(Changement_rapport_bvm, bLocalChangement_rapport_bvm);
   VEMS_vidGET(Bvmp_inh_cliq_acquisition, bLocalBvmp_inh_cliq_acquisition);
   VEMS_vidGET(Bv_changement_rapport, bLocalBv_changement_rapport);
   VEMS_vidGET(Presence_bva, bLocalPresence_bva);
   if (  (  (  bLocalChangement_rapport_bvm != 0)
            || (  (bLocalBvmp_inh_cliq_acquisition != 0)
               || (  (bLocalBv_changement_rapport != 0)
                  && (bLocalPresence_bva != 0))))
         && (Knk_deg_bv_chgt_inh_uacb0 == 0))
   {
      bLocalknk_deg_bv_chgt_uavb0 = 1;
   }
   else
   {
      bLocalknk_deg_bv_chgt_uavb0 = 0;
   }

   if (  (knk_corr_inc_uavb0 != 0)
      && (bLocalknk_deg_bv_chgt_uavb0 == 0)
      && (Knk_deg_cor_av_filt_uavn0 == u8LocalKnk_deg_cor_uavn0))
   {
      KNKSHDCOR_vidCorr_inc();
   }

   VEMS_vidGET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);
   if (  (Knk_deg_cor_av_filt_uavn0 > 0)
      && (knk_corr_inc_uavb0 == 0)
      && (bLocalknk_deg_bv_chgt_uavb0 == 0)
      && (Knk_deg_cor_av_filt_uavn0 == u8LocalKnk_deg_cor_uavn0))
   {
      KNKSHDCOR_vidCorr_dec();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidraz_corr                                       */
/* !Description : Dans les cas hors zone critique, il n'est pas nécessaire    */
/*                d'appliquer une correction dégradée. La correction est alors*/
/*                filtrée vers 0. La fenêtre d’observation et le compteur de  */
/*                "coups de cliquetis" sont remis à zéro.                     */
/* !Number      : FCT1.10                                                     */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint8 Knk_deg_cor_uavn0;                                           */
/*   input uint8 Knk_deg_cor_out_filt_uacn0;                                  */
/*   output uint8 Knk_deg_cor_uavn0;                                          */
/*   output uint8 Knk_deg_det_count_uavn1[4];                                 */
/*   output uint8 Knk_deg_obs_win_uavn1[4];                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidraz_corr(void)
{
   uint8  u8LocalKnk_deg_cor_uavn0;
   uint8  u8LocalDiv;
   uint8  u8LocalCounter;
   uint16 u16localProd;
   sint16 s16LocalDiff;


   VEMS_vidGET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);
   u16localProd = (uint16)( Knk_deg_cor_out_filt_uacn0
                          * u8LocalKnk_deg_cor_uavn0);
   u8LocalDiv = (uint8)(u16localProd / 256);
   s16LocalDiff = (sint16)(u8LocalKnk_deg_cor_uavn0 - u8LocalDiv);
   u8LocalKnk_deg_cor_uavn0 = (uint8)MATHSRV_udtMAX(s16LocalDiff, 0);
   VEMS_vidSET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);

   for (u8LocalCounter = 0; u8LocalCounter < 4; u8LocalCounter++)
   {
      Knk_deg_det_count_uavn1[u8LocalCounter] = 0;
      Knk_deg_obs_win_uavn1[u8LocalCounter] = 0;
   }
}
/*------------------------------- end of file --------------------------------*/