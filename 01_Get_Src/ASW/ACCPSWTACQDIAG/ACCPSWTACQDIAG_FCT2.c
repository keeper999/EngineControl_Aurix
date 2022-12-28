/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPSWTACQDIAG                                          */
/* !Description     : ACCPSWTACQDIAG Component                                */
/*                                                                            */
/* !Module          : ACCPSWTACQDIAG                                          */
/* !Description     : IMPLEMENTATION DU TRAITEMENT DU CONTACTEUR ELECTRIQUE   */
/*                    LVV                                                     */
/*                                                                            */
/* !File            : ACCPSWTACQDIAG_FCT2.C                                   */
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
/*   1 / ACCPSWTACQDIAG_vidHightStabTrans                                     */
/*   2 / ACCPSWTACQDIAG_vidTempoHightTrans                                    */
/*   3 / ACCPSWTACQDIAG_vidTempoInvTrans                                      */
/*   4 / ACCPSWTACQDIAG_vidTempoLowTrans                                      */
/*   5 / ACCPSWTACQDIAG_vidLowStableTrans                                     */
/*   6 / ACCPSWTACQDIAG_vidHightFailTrans                                     */
/*   7 / ACCPSWTACQDIAG_vidInvFailTrans                                       */
/*   8 / ACCPSWTACQDIAG_vidLowFailTrans                                       */
/*   9 / ACCPSWTACQDIAG_vidEndPointPedCoh                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6606841 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#050819                                         */
/* !OtherRefs   : VEMS V02 ECU#068754                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACCP/ACCPSWTACQDIAG/ACCPSWTACQDIAG$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   27 May 2014 $*/
/* $Author::   wbouach                                $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "ACCPSWTACQDIAG.H"
#include "ACCPSWTACQDIAG_L.H"
#include "ACCPSWTACQDIAG_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidHightStabTrans                           */
/* !Description :  Les transitions de l'état LVV_STABLE_HAUT                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Lvv_valid_basse;                                            */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input uint16 Lvv_cpt2_confirm_defaut_elec;                                */
/*  input boolean Lvv_valid_haute;                                            */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidHightStabTrans(void)
{
   if (Lvv_valid_basse != 0)
   {
      /* Entry state LVV_TRANSITOIRE_BAS */
      VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_BAS);
      if (Lvv_cpt1_chg_etat_ou_rehab_def < 65535)
      {
         Lvv_cpt1_chg_etat_ou_rehab_def =
            (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
      }
      if (Lvv_cpt2_confirm_defaut_elec < 65535)
      {
         Lvv_cpt2_confirm_defaut_elec = (uint16)( Lvv_cpt2_confirm_defaut_elec
                                                + 1);
      }
   }
   else
   {
      if (Lvv_valid_haute == 0)
      {
         /* Entry state LVV_TRANSITOIRE_INVALIDE */
         VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_INVALIDE);
         Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         if (Lvv_cpt2_confirm_defaut_elec < 65535)
         {
            Lvv_cpt2_confirm_defaut_elec =
               (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidTempoHightTrans                          */
/* !Description :  Les transitions de l'état LVV_TRANSITOIRE_HAUT             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lvv_cpt2_confirm_defaut_elec;                                */
/*  input uint8 Lvv_nconf2_defaut_elec;                                       */
/*  input boolean Lvv_valid_haute;                                            */
/*  input boolean Lvv_valid_basse;                                            */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input uint8 Lvv_nconf1_chg_etat_haut;                                     */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidTempoHightTrans(void)
{

   if (Lvv_cpt2_confirm_defaut_elec >= Lvv_nconf2_defaut_elec)
   {
      Etat_point_dur_raw = NON_FRANCHI;
      Lvv_cpt2_confirm_defaut_elec = 0;
      if (Lvv_valid_haute != 0)
      {
         /* entry state DEFAUT_HAUT */
         VEMS_vidSET(Lvv_etat_capteur, DEFAUT_HAUT);
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
      }
      else
      {
         if (Lvv_valid_basse != 0)
         {
            /* entry state DEFAUT_BAS */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_BAS);
            Lvv_cpt1_chg_etat_ou_rehab_def = 1;
         }
         else
         {
            /* exit state LVV_TRANSITOIRE_HAUT */
            /* entry state DEFAUT_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_INVALIDE);
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         }
      }
   }
   else
   {
      if (Lvv_valid_basse != 0)
      {
         /* entry state LVV_TRANSITOIRE_BAS */
         VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_BAS);
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
         Lvv_cpt2_confirm_defaut_elec = (uint16)( Lvv_cpt2_confirm_defaut_elec
                                                + 1);
      }
      else
      {
         if (Lvv_valid_haute == 0)
         {
            /* exit state LVV_TRANSITOIRE_HAUT */
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;

            /* entry state LVV_TRANSITOIRE_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_INVALIDE);
            Lvv_cpt2_confirm_defaut_elec =
               (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
         }
         else
         {
            if (Lvv_cpt1_chg_etat_ou_rehab_def >= Lvv_nconf1_chg_etat_haut)
            {
               /* entry state LVV_STABLE_HAUT */
               VEMS_vidSET(Lvv_etat_capteur, LVV_STABLE_HAUT);
               Etat_point_dur_raw = NON_FRANCHI;
               Lvv_cpt1_chg_etat_ou_rehab_def = 0;
               Lvv_cpt2_confirm_defaut_elec = 0;
            }
            else
            {
               /* During of LVV_TRANSITOIRE_HAUT */
               Lvv_cpt1_chg_etat_ou_rehab_def =
                  (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
               Lvv_cpt2_confirm_defaut_elec =
                     (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidTempoInvTrans                            */
/* !Description :  Les transition de l'état LVV_TRANSITOIRE_INVALIDE          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lvv_cpt2_confirm_defaut_elec;                                */
/*  input uint8 Lvv_nconf2_defaut_elec;                                       */
/*  input boolean Lvv_valid_haute;                                            */
/*  input boolean Lvv_valid_basse;                                            */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidTempoInvTrans(void)
{
   if (Lvv_cpt2_confirm_defaut_elec >= Lvv_nconf2_defaut_elec)
   {
      Etat_point_dur_raw = NON_FRANCHI;
      Lvv_cpt2_confirm_defaut_elec = 0;
      if (Lvv_valid_haute != 0)
      {
         /* entry state DEFAUT_HAUT */
         VEMS_vidSET(Lvv_etat_capteur, DEFAUT_HAUT);
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
      }
      else
      {
         if (Lvv_valid_basse != 0)
         {
            /* entry state DEFAUT_BAS */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_BAS);
            Lvv_cpt1_chg_etat_ou_rehab_def = 1;
         }
         else
         {
            /* exit state LVV_TRANSITOIRE_INVALIDE */
            /* entry state DEFAUT_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_INVALIDE);
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         }
      }
   }
   else
   {
      Lvv_cpt2_confirm_defaut_elec = (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
      if (Lvv_valid_haute != 0)
      {
         /* entry state LVV_TRANSITOIRE_HAUT */
         VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_HAUT);
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
      }
      else
      {
         if (Lvv_valid_basse != 0)
         {
            /* entry state LVV_TRANSITOIRE_BAS */
            VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_BAS);
            Lvv_cpt1_chg_etat_ou_rehab_def = 1;
         }
         else
         {
            /* During of LVV_TRANSITOIRE_INVALIDE */
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidTempoLowTrans                            */
/* !Description :  Les transitions de l'état LVV_TRANSITOIRE_BAS              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 Lvv_cpt2_confirm_defaut_elec;                                */
/*  input uint8 Lvv_nconf2_defaut_elec;                                       */
/*  input boolean Lvv_valid_haute;                                            */
/*  input boolean Lvv_valid_basse;                                            */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input uint8 Lvv_nconf1_chg_etat_bas;                                      */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidTempoLowTrans(void)
{
   boolean bLocalInhAccPSwtPush;


   if (Lvv_cpt2_confirm_defaut_elec >= Lvv_nconf2_defaut_elec)
   {
      Etat_point_dur_raw = NON_FRANCHI;
      Lvv_cpt2_confirm_defaut_elec = 0;
      if (Lvv_valid_haute != 0)
      {
         /* entry state DEFAUT_HAUT */
         VEMS_vidSET(Lvv_etat_capteur, DEFAUT_HAUT);
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
      }
      else
      {
         if (Lvv_valid_basse != 0)
         {
            /* entry state DEFAUT_BAS */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_BAS);
            Lvv_cpt1_chg_etat_ou_rehab_def = 1;
         }
         else
         {
            /* exit state LVV_TRANSITOIRE_BAS */
            /* entry state DEFAUT_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_INVALIDE);
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         }
      }
   }
   else
   {
      if (Lvv_valid_haute != 0)
      {
         /* entry state LVV_TRANSITOIRE_HAUT */
         VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_HAUT);
         Lvv_cpt1_chg_etat_ou_rehab_def =1;
         Lvv_cpt2_confirm_defaut_elec = (uint16)( Lvv_cpt2_confirm_defaut_elec
                                                + 1);
      }
      else
      {
         if (Lvv_valid_basse == 0)
         {
            /* exit state LVV_TRANSITOIRE_BAS */
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;

            /* entry state LVV_TRANSITOIRE_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_INVALIDE);
            Lvv_cpt2_confirm_defaut_elec =
               (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
         }
         else
         {
            bLocalInhAccPSwtPush = GDGAR_bGetFRM(FRM_FRM_INHACCPSWTPUSH);
            if (  (Lvv_cpt1_chg_etat_ou_rehab_def >= Lvv_nconf1_chg_etat_bas)
               && (bLocalInhAccPSwtPush == 0))
            {
               /* exit state LVV_TRANSITOIRE_BAS */
               /* entry state LVV_STABLE_BAS */
               VEMS_vidSET(Lvv_etat_capteur, LVV_STABLE_BAS);
               Etat_point_dur_raw = ENFONCE;
               Lvv_cpt1_chg_etat_ou_rehab_def = 0;
               Lvv_cpt2_confirm_defaut_elec = 0;
            }
            else
            {
               /* During of LVV_TRANSITOIRE_BAS */
               if (Lvv_cpt1_chg_etat_ou_rehab_def < 65535)
               {
                  Lvv_cpt1_chg_etat_ou_rehab_def =
                     (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
               }
               Lvv_cpt2_confirm_defaut_elec =
                  (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidLowStableTrans                           */
/* !Description :  Les transitions de l'état LVV_STABLE_BAS                   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Lvv_valid_haute;                                            */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input uint16 Lvv_cpt2_confirm_defaut_elec;                                */
/*  input boolean Lvv_valid_basse;                                            */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidLowStableTrans(void)
{
   if (Lvv_valid_haute != 0)
   {
      /* Entry state LVV_TRANSITOIRE_HAUT */
      VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_HAUT);
      if (Lvv_cpt1_chg_etat_ou_rehab_def < 65535)
      {
         Lvv_cpt1_chg_etat_ou_rehab_def =
            (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
      }
      if (Lvv_cpt2_confirm_defaut_elec < 65535)
      {
         Lvv_cpt2_confirm_defaut_elec =
            (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
      }
   }
   else
   {
      if(Lvv_valid_basse == 0)
      {
         /* Entry state LVV_TRANSITOIRE_INVALIDE */
         VEMS_vidSET(Lvv_etat_capteur, LVV_TRANSITOIRE_INVALIDE);
         Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         if (Lvv_cpt2_confirm_defaut_elec < 65535)
         {
            Lvv_cpt2_confirm_defaut_elec =
               (uint16)(Lvv_cpt2_confirm_defaut_elec + 1);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidHightFailTrans                           */
/* !Description :  Les transitions de l'état DEFAUT_HAUT                      */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input uint8 Lvv_nconf3_etat_valid_rehab_def;                              */
/*  input boolean Lvv_valid_haute;                                            */
/*  input boolean Lvv_valid_basse;                                            */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidHightFailTrans(void)
{
   Lvv_cpt2_confirm_defaut_elec = 0;
   if (  (Lvv_cpt1_chg_etat_ou_rehab_def >= Lvv_nconf3_etat_valid_rehab_def)
      && (Lvv_valid_haute != 0))
   {
      /* exit state DEFAUT_HAUT */
      /* entry state LVV_STABLE_HAUT */
      VEMS_vidSET(Lvv_etat_capteur, LVV_STABLE_HAUT);
      Etat_point_dur_raw = NON_FRANCHI;
      Lvv_cpt1_chg_etat_ou_rehab_def = 0;
   }
   else
   {
      if(Lvv_valid_basse != 0)
      {
         /* entry state DEFAUT_BAS */
         VEMS_vidSET(Lvv_etat_capteur, DEFAUT_BAS);
         Etat_point_dur_raw = NON_FRANCHI;
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
      }
      else
      {
         if (Lvv_valid_haute == 0)
         {
            /* exit state DEFAUT_HAUT */
            /* entry state DEFAUT_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_INVALIDE);
            Etat_point_dur_raw = NON_FRANCHI;
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         }
         else
         {
            /* During of DEFAUT_HAUT */
            Lvv_cpt1_chg_etat_ou_rehab_def =
               (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidInvFailTrans                             */
/* !Description :  Les transitions de l'état DEFAUT_INVALIDE                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Lvv_valid_haute;                                            */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input boolean Lvv_valid_basse;                                            */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidInvFailTrans(void)
{
   if (Lvv_valid_haute != 0)
   {
      /* entry state DEFAUT_HAUT */
      VEMS_vidSET(Lvv_etat_capteur, DEFAUT_HAUT);
      Etat_point_dur_raw = NON_FRANCHI;
      if (Lvv_cpt1_chg_etat_ou_rehab_def < 65535)
      {
         Lvv_cpt1_chg_etat_ou_rehab_def =
            (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
      }
      Lvv_cpt2_confirm_defaut_elec = 0;
   }
   else
   {
      if (Lvv_valid_basse != 0)
      {
         /* entry state DEFAUT_BAS */
         VEMS_vidSET(Lvv_etat_capteur, DEFAUT_BAS);
         Etat_point_dur_raw = NON_FRANCHI;
         if (Lvv_cpt1_chg_etat_ou_rehab_def < 65535)
         {
            Lvv_cpt1_chg_etat_ou_rehab_def =
               (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
         }
         Lvv_cpt2_confirm_defaut_elec = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidLowFailTrans                             */
/* !Description :  Les transitions de l'état DEFAUT_BAS                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                              */
/*  input uint8 Lvv_nconf3_etat_valid_rehab_def;                              */
/*  input boolean Lvv_valid_basse;                                            */
/*  input boolean Lvv_valid_haute;                                            */
/*  output uint16 Lvv_cpt2_confirm_defaut_elec;                               */
/*  output st11 Lvv_etat_capteur;                                             */
/*  output boolean Etat_point_dur_raw;                                        */
/*  output uint16 Lvv_cpt1_chg_etat_ou_rehab_def;                             */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidLowFailTrans(void)
{
   Lvv_cpt2_confirm_defaut_elec = 0;
   if (  (Lvv_cpt1_chg_etat_ou_rehab_def >= Lvv_nconf3_etat_valid_rehab_def)
      && (Lvv_valid_basse != 0))
   {
      /* exit state DEFAUT_BAS */
      /* entry state LVV_STABLE_BAS */
      VEMS_vidSET(Lvv_etat_capteur, LVV_STABLE_BAS);
      Etat_point_dur_raw = ENFONCE;
      Lvv_cpt1_chg_etat_ou_rehab_def = 0;
   }
   else
   {
      if (Lvv_valid_haute != 0)
      {
         /* entry state DEFAUT_HAUT */
         VEMS_vidSET(Lvv_etat_capteur, DEFAUT_HAUT);
         Etat_point_dur_raw = NON_FRANCHI;
         Lvv_cpt1_chg_etat_ou_rehab_def = 1;
      }
      else
      {
         if (Lvv_valid_basse == 0)
         {
            /* exit state DEFAUT_BAS */
            /* entry state DEFAUT_INVALIDE */
            VEMS_vidSET(Lvv_etat_capteur, DEFAUT_INVALIDE);
            Etat_point_dur_raw = NON_FRANCHI;
            Lvv_cpt1_chg_etat_ou_rehab_def = 0;
         }
         else
         {
            /* During of DEFAUT_BAS */
            Lvv_cpt1_chg_etat_ou_rehab_def =
               (uint16)(Lvv_cpt1_chg_etat_ou_rehab_def + 1);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPSWTACQDIAG_vidEndPointPedCoh                           */
/* !Description :  Contrôle  la  cohérence  entre  la  position  pédale  et   */
/*                 l’état  point  dur.                                        */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00973_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Dv_position_pedal_relative_aps;                              */
/*  input boolean Etat_point_dur_raw;                                         */
/*  input uint16 Seuil_pedale_point_dur_haut;                                 */
/*  input uint16 Seuil_pedale_point_dur_bas;                                  */
/*  output boolean AccP_bDgoCohAccPSwt;                                       */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPSWTACQDIAG_vidEndPointPedCoh(void)
{
   boolean bLocalAccP_bDgoCohAccPSwt;
   boolean bLocalInhAccPSwtSpdLimCohDiag;
   boolean bLocalAcvAccPSwtSpdLimCohDiag;
   uint16  u16LocalDvPosPedalRelativeAps;


   bLocalInhAccPSwtSpdLimCohDiag =
      GDGAR_bGetFRM(FRM_FRM_INHACCPSWTSPDLIMCOHDIAG);
   bLocalAcvAccPSwtSpdLimCohDiag =
      GDGAR_bGetFRM(FRM_FRM_ACVACCPSWTSPDLIMCOHDIAG);
   VEMS_vidGET(Dv_position_pedal_relative_aps, u16LocalDvPosPedalRelativeAps);

   if (  (  (Etat_point_dur_raw == ENFONCE)
         && (u16LocalDvPosPedalRelativeAps < Seuil_pedale_point_dur_haut))
      || (  (Etat_point_dur_raw == NON_FRANCHI)
         && (u16LocalDvPosPedalRelativeAps > Seuil_pedale_point_dur_bas)))
   {
      bLocalAccP_bDgoCohAccPSwt = 1;
   }
   else
   {
      bLocalAccP_bDgoCohAccPSwt = 0;
   }
   if (  (bLocalAcvAccPSwtSpdLimCohDiag != 0)
      || (  (bLocalAccP_bDgoCohAccPSwt != 0)
         && (bLocalInhAccPSwtSpdLimCohDiag == 0)))
   {
      AccP_bDgoCohAccPSwt = 1;
   }
   else
   {
      AccP_bDgoCohAccPSwt = 0;
   }
}
/*------------------------------- end of file --------------------------------*/