/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACCPLRNPOS                                              */
/* !Description     : ACCPLRNPOS component.                                   */
/*                                                                            */
/* !Module          : ACCPLRNPOS                                              */
/* !Description     : APPRENTISSAGE DES POSITIONS PIED LEVE ET PIED A FOND DE */
/*                    LA PEDALE D’ACCELERATEUR                                */
/*                                                                            */
/* !File            : ACCPLRNPOS_FCT3.C                                       */
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
/*   1 / ACCPLRNPOS_vidDvLrnFootUp1                                           */
/*   2 / ACCPLRNPOS_vidDvLrnFootUp2                                           */
/*   3 / ACCPLRNPOS_vidDvLrnFootUp1D                                          */
/*   4 / ACCPLRNPOS_vidDvLrnFootUp1M                                          */
/*   5 / ACCPLRNPOS_vidDvLrnFootUp2D                                          */
/*   6 / ACCPLRNPOS_vidDvLrnFootUp2M                                          */
/*   7 / ACCPLRNPOS_vidInitDiagsrv                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 03749 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPLRNPOS/ACCPLRNPOS_FCT3.C_$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   hmelloul                               $$Date::   15 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACCPLRNPOS.h"
#include "ACCPLRNPOS_L.h"
#include "ACCPLRNPOS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootUp1                                 */
/* !Description :  Calcul des apprentissages de la position pied levé de la   */
/*                 pédale d’accélérateur sur le signal 1                      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B.HARIBI                                                   */
/* !Trace_To    :  VEMS_R_08_03749_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootUp1D();                           */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootUp1M();                           */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input boolean Dv_app_pl_eng_spd_enable;                                   */
/*  input uint8 Dv_1_app_pos_ped_pl_min;                                      */
/*  input uint16 Dv_1_app_pos_ped_pl;                                         */
/*  output uint16 Dv_1_app_pos_ped_pl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootUp1(void)
{
   uint16 u16LocalAps_1_filtered_position;
   uint16 u16LocalDv_1_app_pos_ped_pl;
   uint16 u16LocalDv_1_app_pos_ped_pl_min;
   uint32 u32LocalAps_1_filtered_position;


   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);

   if (Dv_app_pl_eng_spd_enable != 0)
   {
      u16LocalDv_1_app_pos_ped_pl_min = (uint16)(Dv_1_app_pos_ped_pl_min * 4);
      if (u16LocalAps_1_filtered_position < u16LocalDv_1_app_pos_ped_pl_min)
      {
         u16LocalDv_1_app_pos_ped_pl = (uint16)( u16LocalDv_1_app_pos_ped_pl_min
                                               * 16);
         VEMS_vidSET(Dv_1_app_pos_ped_pl, u16LocalDv_1_app_pos_ped_pl);

      }
      else
      {
         VEMS_vidGET(Dv_1_app_pos_ped_pl, u16LocalDv_1_app_pos_ped_pl);
         u32LocalAps_1_filtered_position =
            (uint32)(u16LocalAps_1_filtered_position * 16);
         if (u32LocalAps_1_filtered_position > u16LocalDv_1_app_pos_ped_pl)
         {
            ACCPLRNPOS_vidDvLrnFootUp1D();
         }
         else
         {
            ACCPLRNPOS_vidDvLrnFootUp1M();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootUp2                                 */
/* !Description :  Calcul des apprentissages de la position pied levé de la   */
/*                 pédale d’accélérateur sur le signal 2                      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootUp2M();                           */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootUp2D();                           */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input boolean Dv_app_pl_eng_spd_enable;                                   */
/*  input uint8 Dv_2_app_pos_ped_pl_min;                                      */
/*  input uint16 Dv_2_app_pos_ped_pl;                                         */
/*  output uint16 Dv_2_app_pos_ped_pl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootUp2(void)
{
   uint16 u16LocalAps_2_formated_position;
   uint16 u16LocalDv_2_app_pos_ped_pl;
   uint16 u16LocalDv_2_app_pos_ped_pl_min;
   uint32 u32LocalAps_2_formated_position;


   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);

   if (Dv_app_pl_eng_spd_enable != 0)
   {
      u16LocalDv_2_app_pos_ped_pl_min = (uint16)(Dv_2_app_pos_ped_pl_min * 4);
      if (u16LocalAps_2_formated_position < u16LocalDv_2_app_pos_ped_pl_min)
      {
         u16LocalDv_2_app_pos_ped_pl = (uint16)( u16LocalDv_2_app_pos_ped_pl_min
                                               * 16);
         VEMS_vidSET(Dv_2_app_pos_ped_pl, u16LocalDv_2_app_pos_ped_pl);
      }
      else
      {
         VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalDv_2_app_pos_ped_pl);
         u32LocalAps_2_formated_position =
            (uint32)(u16LocalAps_2_formated_position * 16);
         if (u32LocalAps_2_formated_position > u16LocalDv_2_app_pos_ped_pl)
         {
            ACCPLRNPOS_vidDvLrnFootUp2M();
         }
         else
         {
            ACCPLRNPOS_vidDvLrnFootUp2D();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootUp1D                                */
/* !Description :  l'apprentissage butée basse se faire par incrémentation par*/
/*                 pas de l'ancienne valeur butée basse apprise, la butée     */
/*                 basse prend alors la valeur minimum entre le résultat      */
/*                 d'incrémentation et la valeur du rapport de tension.       */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input uint16 Dv_1_app_pos_ped_pl;                                         */
/*  input uint8 Dv_1_app_pos_ped_pl_init;                                     */
/*  input boolean Dv_init_1_app_pl_tempo1_prev;                               */
/*  input uint8 Dv_1_app_pl_tempo_delay;                                      */
/*  input uint8 Dv_1_app_pl_tempo1;                                           */
/*  input uint16 Dv_1_app_increment_pl;                                       */
/*  input boolean Dv_init_1_app_pl_tempo1;                                    */
/*  output boolean Dv_init_1_app_pl_tempo1;                                   */
/*  output uint8 Dv_1_app_pl_tempo1;                                          */
/*  output uint16 Dv_1_app_pos_ped_pl;                                        */
/*  output boolean Dv_init_1_app_pl_tempo1_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootUp1D(void)
{
   boolean bLocalTimeout1;
   uint16  u16LocalAps_1_filtered_position;
   uint16  u16LocalDv1LrnInc;
   uint16  u16LocalDv_1_app_pos_ped_pl;
   uint16  u16LocalLrnPos;


   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);
   VEMS_vidGET(Dv_1_app_pos_ped_pl, u16LocalDv_1_app_pos_ped_pl);

   bLocalTimeout1 = 0;

   if (  (u16LocalDv_1_app_pos_ped_pl < (uint16)(Dv_1_app_pos_ped_pl_init * 64))
      && ( u16LocalAps_1_filtered_position
         < (uint16)(Dv_1_app_pos_ped_pl_init * 4)))
   {
      Dv_init_1_app_pl_tempo1 = 1;
      /*il faut initialiser la tempo et repositionner le timeout a zero sur
      front montant*/
      if (Dv_init_1_app_pl_tempo1_prev == 0)
      {
         /*résolution : AccP_SampleTiSlow_SC = 0.1s*/
         Dv_1_app_pl_tempo1 = Dv_1_app_pl_tempo_delay;
      }
      else
      {
         if (Dv_1_app_pl_tempo1 != 0)
         {
            Dv_1_app_pl_tempo1 = (uint8)(Dv_1_app_pl_tempo1 - 1);
         }
         else
         {
            bLocalTimeout1 = 1;
         }
      }

      if (bLocalTimeout1 != 0)
      {
         u16LocalLrnPos = (uint16)(u16LocalAps_1_filtered_position * 16);
         u16LocalDv1LrnInc = (uint16)( u16LocalDv_1_app_pos_ped_pl
                                     + Dv_1_app_increment_pl);

         if (u16LocalDv1LrnInc < u16LocalLrnPos)
         {
            u16LocalLrnPos = u16LocalDv1LrnInc;
         }
         VEMS_vidSET(Dv_1_app_pos_ped_pl, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_1_app_pl_tempo1 = 0;
   }

   Dv_init_1_app_pl_tempo1_prev = Dv_init_1_app_pl_tempo1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootUp1M                                */
/* !Description :  l'apprentissage de la butée basse peut se faire par        */
/*                 decrémentation par pas ou instantanément. Le choix se fait */
/*                 par calibration .                                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input uint8 Dv_1_app_pos_ped_pl_min;                                      */
/*  input boolean Dv_init_1_app_pl_tempo2_prev;                               */
/*  input uint8 Dv_1_app_pl_tempo_delay;                                      */
/*  input uint8 Dv_1_app_pl_tempo2;                                           */
/*  input boolean Dv_app_pos_ped_pas_inst_pl;                                 */
/*  input uint16 Dv_1_app_pos_ped_pl;                                         */
/*  input uint16 Dv_1_app_decrement_pl;                                       */
/*  input boolean Dv_init_1_app_pl_tempo2;                                    */
/*  output boolean Dv_init_1_app_pl_tempo2;                                   */
/*  output uint8 Dv_1_app_pl_tempo2;                                          */
/*  output uint16 Dv_1_app_pos_ped_pl;                                        */
/*  output boolean Dv_init_1_app_pl_tempo2_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootUp1M(void)
{
   boolean bLocalTimeout2;
   uint16  u16LocalAps_1_filtered_position;
   uint16  u16LocalDv_1_app_pos_ped_pl;
   uint16  u16LocalLrnPos;
   sint32  s32LocalDv1LrnDec;


   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);

   bLocalTimeout2 = 0;

   if (u16LocalAps_1_filtered_position > (uint16)(Dv_1_app_pos_ped_pl_min * 4))
   {
      Dv_init_1_app_pl_tempo2 = 1;
      /*il faut initialiser la tempo et repositionner le timeout a zero sur
      front montant*/
      if (Dv_init_1_app_pl_tempo2_prev == 0)
      {
         /*résolution : AccP_SampleTiSlow_SC = 0.1s*/
         Dv_1_app_pl_tempo2 = Dv_1_app_pl_tempo_delay;
      }
      else
      {
         if (Dv_1_app_pl_tempo2 != 0)
         {
            Dv_1_app_pl_tempo2 = (uint8)(Dv_1_app_pl_tempo2 - 1);
         }
         else
         {
            bLocalTimeout2 = 1;
         }
      }

      if (bLocalTimeout2 != 0)
      {
         if (u16LocalAps_1_filtered_position >= 1024)
         {
            u16LocalLrnPos = 16384;
         }
         else
         {
            u16LocalLrnPos = (uint16)(u16LocalAps_1_filtered_position * 16);
         }

         if (Dv_app_pos_ped_pas_inst_pl == 0)
         {
            VEMS_vidGET(Dv_1_app_pos_ped_pl, u16LocalDv_1_app_pos_ped_pl);
            s32LocalDv1LrnDec = (sint32)( u16LocalDv_1_app_pos_ped_pl
                                        - Dv_1_app_decrement_pl);
            if (s32LocalDv1LrnDec > u16LocalLrnPos)
            {
               s32LocalDv1LrnDec = MATHSRV_udtMIN(s32LocalDv1LrnDec, 16384);
               u16LocalLrnPos = (uint16)s32LocalDv1LrnDec;
            }
         }
         VEMS_vidSET(Dv_1_app_pos_ped_pl, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_1_app_pl_tempo2 = 0;
   }
   Dv_init_1_app_pl_tempo2_prev = Dv_init_1_app_pl_tempo2;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootUp2D                                */
/* !Description :  l'apprentissage de la butée basse peut se faire par        */
/*                 decrémentation par pas ou instantanément. Le choix se fait */
/*                 par calibration .la butée basse prend alors la valeur      */
/*                 maximum entre le résultat de décrémentation et la valeur du*/
/*                 rapport de tension.                                        */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input uint8 Dv_2_app_pos_ped_pl_min;                                      */
/*  input boolean Dv_init_2_app_pl_tempo2_prev;                               */
/*  input uint8 Dv_2_app_pl_tempo_delay;                                      */
/*  input uint8 Dv_2_app_pl_tempo2;                                           */
/*  input boolean Dv_app_pos_ped_pas_inst_pl;                                 */
/*  input uint16 Dv_2_app_pos_ped_pl;                                         */
/*  input uint16 Dv_2_app_decrement_pl;                                       */
/*  input boolean Dv_init_2_app_pl_tempo2;                                    */
/*  output boolean Dv_init_2_app_pl_tempo2;                                   */
/*  output uint8 Dv_2_app_pl_tempo2;                                          */
/*  output uint16 Dv_2_app_pos_ped_pl;                                        */
/*  output boolean Dv_init_2_app_pl_tempo2_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootUp2D(void)
{
   boolean bLocalTimeout2;
   uint16  u16LocalAps_2_formated_position;
   uint16  u16LocalDv_2_app_pos_ped_pl;
   uint16  u16LocalLrnPos;
   sint32  s32LocalDv2LrnDec;


   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);

   bLocalTimeout2 = 0;

   if (u16LocalAps_2_formated_position > (uint16)(Dv_2_app_pos_ped_pl_min * 4))
   {
      Dv_init_2_app_pl_tempo2 = 1;
      /*il faut initialiser la tempo et repositionner le timeout a zero sur
      front montant*/
      if (Dv_init_2_app_pl_tempo2_prev == 0)
      {
         /*résolution : AccP_SampleTiSlow_SC = 0.1s*/
         Dv_2_app_pl_tempo2 = Dv_2_app_pl_tempo_delay;
      }
      else
      {
         if (Dv_2_app_pl_tempo2 != 0)
         {
            Dv_2_app_pl_tempo2 = (uint8)(Dv_2_app_pl_tempo2 - 1);
         }
         else
         {
            bLocalTimeout2 = 1;
         }
      }

      if (bLocalTimeout2 != 0)
      {
         if (u16LocalAps_2_formated_position >= 1024)
         {
            u16LocalLrnPos = 16384;
         }
         else
         {
            u16LocalLrnPos = (uint16)(u16LocalAps_2_formated_position * 16);
         }

         if (Dv_app_pos_ped_pas_inst_pl == 0)
         {
            VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalDv_2_app_pos_ped_pl);
            s32LocalDv2LrnDec = (sint32)( u16LocalDv_2_app_pos_ped_pl
                                        - Dv_2_app_decrement_pl);

            if (s32LocalDv2LrnDec > u16LocalLrnPos)
            {
               s32LocalDv2LrnDec = MATHSRV_udtMIN(s32LocalDv2LrnDec, 16384);
               u16LocalLrnPos = (uint16)s32LocalDv2LrnDec;
            }
         }
         VEMS_vidSET(Dv_2_app_pos_ped_pl, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_2_app_pl_tempo2 = 0;
   }

   Dv_init_2_app_pl_tempo2_prev = Dv_init_2_app_pl_tempo2;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootUp2M                                */
/* !Description :  l'apprentissage butée basse peut se faire par              */
/*                 incrémentation par pas de l'ancienne valeur butée basse    */
/*                 apprise, la butée basse prend alors la valeur minimum entre*/
/*                 le résultat de d'incrémentation et la valeur du rapport de */
/*                 tension.                                                   */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input uint16 Dv_2_app_pos_ped_pl;                                         */
/*  input uint8 Dv_2_app_pos_ped_pl_init;                                     */
/*  input boolean Dv_init_2_app_pl_tempo1_prev;                               */
/*  input uint8 Dv_2_app_pl_tempo_delay;                                      */
/*  input uint8 Dv_2_app_pl_tempo1;                                           */
/*  input uint16 Dv_2_app_increment_pl;                                       */
/*  input boolean Dv_init_2_app_pl_tempo1;                                    */
/*  output boolean Dv_init_2_app_pl_tempo1;                                   */
/*  output uint8 Dv_2_app_pl_tempo1;                                          */
/*  output uint16 Dv_2_app_pos_ped_pl;                                        */
/*  output boolean Dv_init_2_app_pl_tempo1_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootUp2M(void)
{
   boolean bLocalTimeout1;
   uint16  u16LocalAps_2_formated_position;
   uint16  u16LocalDv2LrnInc;
   uint16  u16LocalDv_2_app_pos_ped_pl;
   uint16  u16LocalLrnPos;


   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);
   VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalDv_2_app_pos_ped_pl);

   bLocalTimeout1 = 0;

   if (  (u16LocalDv_2_app_pos_ped_pl < (uint16)(Dv_2_app_pos_ped_pl_init * 64))
      && ( u16LocalAps_2_formated_position
         < (uint16)(Dv_2_app_pos_ped_pl_init * 4)))
   {
      Dv_init_2_app_pl_tempo1 = 1;
      /*il faut initialiser la tempo et repositionner le timeout a zero sur
      front montant*/
      if (Dv_init_2_app_pl_tempo1_prev == 0)
      {
         /*résolution : AccP_SampleTiSlow_SC = 0.1s*/
         Dv_2_app_pl_tempo1 = Dv_2_app_pl_tempo_delay;
      }
      else
      {
         if (Dv_2_app_pl_tempo1 != 0)
         {
            Dv_2_app_pl_tempo1 = (uint8)(Dv_2_app_pl_tempo1 - 1);
         }
         else
         {
            bLocalTimeout1 = 1;
         }
      }

      if (bLocalTimeout1 != 0)
      {
         u16LocalLrnPos = (uint16)(u16LocalAps_2_formated_position * 16);
         VEMS_vidGET(Dv_2_app_pos_ped_pl, u16LocalDv_2_app_pos_ped_pl);
         u16LocalDv2LrnInc = (uint16)( u16LocalDv_2_app_pos_ped_pl
                                     + Dv_2_app_increment_pl);

         if (u16LocalDv2LrnInc < u16LocalLrnPos)
         {
            u16LocalLrnPos = u16LocalDv2LrnInc;
         }
         VEMS_vidSET(Dv_2_app_pos_ped_pl, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_2_app_pl_tempo1 = 0;
   }

   Dv_init_2_app_pl_tempo1_prev = Dv_init_2_app_pl_tempo1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidInitDiagsrv                                  */
/* !Description :  Fonction de reset de l'apprentissage pédale accélérateur   */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Dv_1_app_pos_ped_pl_cdef;                                     */
/*  input uint8 Dv_1_app_pos_ped_pc_cdef;                                     */
/*  input uint8 Dv_2_app_pos_ped_pl_cdef;                                     */
/*  input uint8 Dv_2_app_pos_ped_pc_cdef;                                     */
/*  output uint16 Dv_1_app_pos_ped_pl;                                        */
/*  output uint16 Dv_1_app_pos_ped_pc;                                        */
/*  output uint16 Dv_2_app_pos_ped_pl;                                        */
/*  output uint16 Dv_2_app_pos_ped_pc;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidInitDiagsrv(void)
{
   uint16 u16LocalDv_1_app_pos_ped_pl;
   uint16 u16LocalDv_1_app_pos_ped_pc;
   uint16 u16LocalDv_2_app_pos_ped_pl;
   uint16 u16LocalDv_2_app_pos_ped_pc;


   u16LocalDv_1_app_pos_ped_pl = (uint16)(Dv_1_app_pos_ped_pl_cdef * 64);
   u16LocalDv_1_app_pos_ped_pc = (uint16)(Dv_1_app_pos_ped_pc_cdef * 64);
   u16LocalDv_2_app_pos_ped_pl = (uint16)(Dv_2_app_pos_ped_pl_cdef * 64);
   u16LocalDv_2_app_pos_ped_pc = (uint16)(Dv_2_app_pos_ped_pc_cdef * 64);

   VEMS_vidSET(Dv_1_app_pos_ped_pl, u16LocalDv_1_app_pos_ped_pl);
   VEMS_vidSET(Dv_1_app_pos_ped_pc, u16LocalDv_1_app_pos_ped_pc);
   VEMS_vidSET(Dv_2_app_pos_ped_pl, u16LocalDv_2_app_pos_ped_pl);
   VEMS_vidSET(Dv_2_app_pos_ped_pc, u16LocalDv_2_app_pos_ped_pc);
}

/*------------------------------- end of file --------------------------------*/