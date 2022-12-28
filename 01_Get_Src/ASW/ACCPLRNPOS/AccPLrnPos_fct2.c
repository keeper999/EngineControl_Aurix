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
/* !File            : ACCPLRNPOS_FCT2.C                                       */
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
/*   1 / ACCPLRNPOS_vidDvLrnFootFullDown1                                     */
/*   2 / ACCPLRNPOS_vidDvLrnFootFullDown2                                     */
/*   3 / ACCPLRNPOS_vidDvLrnFtFlDown1D                                        */
/*   4 / ACCPLRNPOS_vidDvLrnFtFlDown1M                                        */
/*   5 / ACCPLRNPOS_vidDvLrnFtFlDown2D                                        */
/*   6 / ACCPLRNPOS_vidDvLrnFtFlDown2M                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 03749 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPLRNPOS/ACCPLRNPOS_FCT2.C_$*/
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
/* !Function    :  ACCPLRNPOS_vidDvLrnFootFullDown1                           */
/* !Description :  Calcul des apprentissages de la position pied à fond de la */
/*                 pédale d’accélérateur sur le signal 1                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  B.HARIBI                                                   */
/* !Trace_To    :  VEMS_R_08_03749_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACCPLRNPOS_vidDvLrnFtFlDown1M();                         */
/*  extf argret void ACCPLRNPOS_vidDvLrnFtFlDown1D();                         */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input boolean Dv_app_pc_eng_spd_enable;                                   */
/*  input uint8 Dv_1_app_pos_ped_pc_max;                                      */
/*  input uint16 Dv_1_app_pos_ped_pc;                                         */
/*  output uint16 Dv_1_app_pos_ped_pc;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootFullDown1(void)
{
   uint16 u16LocalAps_1_filtered_position;
   uint16 u16LocalDv_1_app_pos_ped_pc;
   uint16 u16LocalDv_1_app_pos_ped_pc_max;
   uint32 u32LocalAps_1_filtered_position;


   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);

   if (Dv_app_pc_eng_spd_enable != 0)
   {
      u16LocalDv_1_app_pos_ped_pc_max = (uint16)(Dv_1_app_pos_ped_pc_max * 4);
      if (u16LocalAps_1_filtered_position > u16LocalDv_1_app_pos_ped_pc_max)
      {
         u16LocalDv_1_app_pos_ped_pc = (uint16)( u16LocalDv_1_app_pos_ped_pc_max
                                               * 16);
         VEMS_vidSET(Dv_1_app_pos_ped_pc, u16LocalDv_1_app_pos_ped_pc);
      }
      else
      {
         VEMS_vidGET(Dv_1_app_pos_ped_pc, u16LocalDv_1_app_pos_ped_pc);
         u32LocalAps_1_filtered_position =
            (uint32)(u16LocalAps_1_filtered_position * 16);
         if (u32LocalAps_1_filtered_position > u16LocalDv_1_app_pos_ped_pc)
         {
            ACCPLRNPOS_vidDvLrnFtFlDown1M();
         }
         else
         {
            ACCPLRNPOS_vidDvLrnFtFlDown1D();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFootFullDown2                           */
/* !Description :  Calcul des apprentissages de la position pied à fond de la */
/*                 pédale d’accélérateur sur le signal 2                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACCPLRNPOS_vidDvLrnFtFlDown2M();                         */
/*  extf argret void ACCPLRNPOS_vidDvLrnFtFlDown2D();                         */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input boolean Dv_app_pc_eng_spd_enable;                                   */
/*  input uint8 Dv_2_app_pos_ped_pc_max;                                      */
/*  input uint16 Dv_2_app_pos_ped_pc;                                         */
/*  output uint16 Dv_2_app_pos_ped_pc;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFootFullDown2(void)
{
   uint16 u16LocalAps_2_formated_position;
   uint16 u16LocalDv_2_app_pos_ped_pc;
   uint16 u16LocalDv_2_app_pos_ped_pc_max;
   uint32 u32LocalAps_2_formated_position;


   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);

   if (Dv_app_pc_eng_spd_enable != 0)
   {
      u16LocalDv_2_app_pos_ped_pc_max = (uint16)(Dv_2_app_pos_ped_pc_max * 4);
      if (u16LocalAps_2_formated_position > u16LocalDv_2_app_pos_ped_pc_max)
      {
         u16LocalDv_2_app_pos_ped_pc = (uint16)( u16LocalDv_2_app_pos_ped_pc_max
                                               * 16);
         VEMS_vidSET(Dv_2_app_pos_ped_pc, u16LocalDv_2_app_pos_ped_pc);
      }
      else
      {
         VEMS_vidGET(Dv_2_app_pos_ped_pc, u16LocalDv_2_app_pos_ped_pc);
         u32LocalAps_2_formated_position =
            (uint32)(u16LocalAps_2_formated_position * 16);
         if (u32LocalAps_2_formated_position > u16LocalDv_2_app_pos_ped_pc)
         {
            ACCPLRNPOS_vidDvLrnFtFlDown2M();
         }
         else
         {
            ACCPLRNPOS_vidDvLrnFtFlDown2D();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFtFlDown1D                              */
/* !Description :  l'apprentissage butée haute peut se faire par              */
/*                 décrémentation par pas de la dernière valeur butée haute   */
/*                 apprise, la butée haute prend alors la valeur du minimum   */
/*                 entre le résultat de décrémentation et la valeur du rapport*/
/*                 de tension.                                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Dv_1_app_pos_ped_pc;                                         */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input uint8 Dv_1_app_pos_ped_pc_init;                                     */
/*  input boolean Dv_init_1_app_pc_tempo2_prev;                               */
/*  input uint8 Dv_1_app_pc_tempo_delay;                                      */
/*  input uint8 Dv_1_app_pc_tempo2;                                           */
/*  input uint16 Dv_1_app_decrement_pc;                                       */
/*  input boolean Dv_init_1_app_pc_tempo2;                                    */
/*  output boolean Dv_init_1_app_pc_tempo2;                                   */
/*  output uint8 Dv_1_app_pc_tempo2;                                          */
/*  output uint16 Dv_1_app_pos_ped_pc;                                        */
/*  output boolean Dv_init_1_app_pc_tempo2_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFtFlDown1D(void)
{
   boolean bLocalTimeout2;
   uint16  u16LocalAps_1_filtered_position;
   uint16  u16LocalDv_1_app_pos_ped_pc;
   uint16  u16LocalLrnPos;
   sint32  s32LocalDv1LrnDec;


   VEMS_vidGET(Dv_1_app_pos_ped_pc, u16LocalDv_1_app_pos_ped_pc);
   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);

   bLocalTimeout2 = 0;

   if (  (u16LocalDv_1_app_pos_ped_pc > (uint16)(Dv_1_app_pos_ped_pc_init * 64))
      && ( u16LocalAps_1_filtered_position
         > (uint16)(Dv_1_app_pos_ped_pc_init * 4)))
   {
      Dv_init_1_app_pc_tempo2 = 1;
      /* il faut initialiser la tempo et repositionner le timeout a zero
      sur front montant*/

      if (Dv_init_1_app_pc_tempo2_prev == 0)
      {
         Dv_1_app_pc_tempo2 = Dv_1_app_pc_tempo_delay;
      }
      else
      {
         if (Dv_1_app_pc_tempo2 != 0)
         {
            Dv_1_app_pc_tempo2 = (uint8)(Dv_1_app_pc_tempo2 - 1);
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

         s32LocalDv1LrnDec = (sint32)( u16LocalDv_1_app_pos_ped_pc
                                     - Dv_1_app_decrement_pc);

         if (s32LocalDv1LrnDec < 0)
         {
            u16LocalLrnPos = 0;
         }
         else
         {
            if (s32LocalDv1LrnDec < 16384)
            {
               u16LocalLrnPos =
                  (uint16)MATHSRV_udtMAX(u16LocalLrnPos,
                                         (uint16)s32LocalDv1LrnDec);
            }
         }
         VEMS_vidSET(Dv_1_app_pos_ped_pc, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_1_app_pc_tempo2 = 0;
   }

   Dv_init_1_app_pc_tempo2_prev = Dv_init_1_app_pc_tempo2;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFtFlDown1M                              */
/* !Description :  l'apprentissage butée haute est faite par incrémentation   */
/*                 par pas de la dernière valeur butée haute apprise. le choix*/
/*                 se fait par calibration. la butée haute prend la valeur du */
/*                 minimum entre le résultat d'incrémentation et la valeur du */
/*                 rapport de tension.                                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_1_filtered_position;                                     */
/*  input uint8 Dv_1_app_pos_ped_pc_max;                                      */
/*  input boolean Dv_init_1_app_pc_tempo1_prev;                               */
/*  input uint8 Dv_1_app_pc_tempo_delay;                                      */
/*  input uint8 Dv_1_app_pc_tempo1;                                           */
/*  input boolean Dv_app_pos_ped_pas_inst_pc;                                 */
/*  input uint16 Dv_1_app_pos_ped_pc;                                         */
/*  input uint16 Dv_1_app_increment_pc;                                       */
/*  input boolean Dv_init_1_app_pc_tempo1;                                    */
/*  output boolean Dv_init_1_app_pc_tempo1;                                   */
/*  output uint8 Dv_1_app_pc_tempo1;                                          */
/*  output uint16 Dv_1_app_pos_ped_pc;                                        */
/*  output boolean Dv_init_1_app_pc_tempo1_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFtFlDown1M(void)
{
   boolean bLocalTimeout1;
   uint16  u16LocalAps_1_filtered_position;
   uint16  u16LocalDv_1_app_pos_ped_pc;
   uint16  u16LocalLrnPos;
   uint32  u32LocalDv1LrnInc;


   VEMS_vidGET(Aps_1_filtered_position, u16LocalAps_1_filtered_position);

   bLocalTimeout1 = 0;

   if (u16LocalAps_1_filtered_position < (uint16)(Dv_1_app_pos_ped_pc_max * 4))
   {
      Dv_init_1_app_pc_tempo1 = 1;
      /*il faut initialiser la tempo et repositionner le timeout a zero
      sur front montant*/
      if (Dv_init_1_app_pc_tempo1_prev == 0)
      {
         Dv_1_app_pc_tempo1 = Dv_1_app_pc_tempo_delay;
      }
      else
      {
         if (Dv_1_app_pc_tempo1 != 0)
         {
            Dv_1_app_pc_tempo1 = (uint8)(Dv_1_app_pc_tempo1 - 1);
         }
         else
         {
            bLocalTimeout1 = 1;
         }
      }

      if (bLocalTimeout1 != 0)
      {
         u16LocalLrnPos = (uint16)(u16LocalAps_1_filtered_position * 16);
         if (Dv_app_pos_ped_pas_inst_pc == 0)
         {
            VEMS_vidGET(Dv_1_app_pos_ped_pc, u16LocalDv_1_app_pos_ped_pc);

            u32LocalDv1LrnInc = (uint32)( u16LocalDv_1_app_pos_ped_pc
                                        + Dv_1_app_increment_pc);

            if (u32LocalDv1LrnInc < u16LocalLrnPos)
            {
               u16LocalLrnPos = (uint16)u32LocalDv1LrnInc;
            }
         }
         VEMS_vidSET(Dv_1_app_pos_ped_pc, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_1_app_pc_tempo1 = 0;
   }
   Dv_init_1_app_pc_tempo1_prev = Dv_init_1_app_pc_tempo1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFtFlDown2D                              */
/* !Description :  l'apprentissage butée haute peut se faire par              */
/*                 décrémentation par pas de la dernière valeur butée haute   */
/*                 apprise, la butée haute prend alors la valeur du minimum   */
/*                 entre le résultat de décrémentation et la valeur du rapport*/
/*                 de tension.                                                */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input uint16 Dv_2_app_pos_ped_pc;                                         */
/*  input uint8 Dv_2_app_pos_ped_pc_init;                                     */
/*  input boolean Dv_init_2_app_pc_tempo2_prev;                               */
/*  input uint8 Dv_2_app_pc_tempo_delay;                                      */
/*  input uint8 Dv_2_app_pc_tempo2;                                           */
/*  input uint16 Dv_2_app_decrement_pc;                                       */
/*  input boolean Dv_init_2_app_pc_tempo2;                                    */
/*  output boolean Dv_init_2_app_pc_tempo2;                                   */
/*  output uint8 Dv_2_app_pc_tempo2;                                          */
/*  output uint16 Dv_2_app_pos_ped_pc;                                        */
/*  output boolean Dv_init_2_app_pc_tempo2_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFtFlDown2D(void)
{
   boolean bLocalTimeout2;
   uint16  u16LocalAps_2_formated_position;
   uint16  u16LocalDv_2_app_pos_ped_pc;
   uint16  u16LocalLrnPos;
   sint32  s32LocalDv2LrnDec;


   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);
   VEMS_vidGET(Dv_2_app_pos_ped_pc, u16LocalDv_2_app_pos_ped_pc);

   bLocalTimeout2 = 0;

   if (  (u16LocalDv_2_app_pos_ped_pc > (uint16)(Dv_2_app_pos_ped_pc_init * 64))
      && ( u16LocalAps_2_formated_position
         > (uint16)(Dv_2_app_pos_ped_pc_init * 4)))
   {
      Dv_init_2_app_pc_tempo2 = 1;
      /* il faut initialiser la tempo et repositionner le timeout a zero sur
      front montant*/
      if (Dv_init_2_app_pc_tempo2_prev == 0)
      {
         Dv_2_app_pc_tempo2 = Dv_2_app_pc_tempo_delay;
      }
      else
      {
         if (Dv_2_app_pc_tempo2 != 0)
         {
            Dv_2_app_pc_tempo2 = (uint8)(Dv_2_app_pc_tempo2 - 1);
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
         s32LocalDv2LrnDec = (sint32)( u16LocalDv_2_app_pos_ped_pc
                                     - Dv_2_app_decrement_pc);

         if (s32LocalDv2LrnDec < 0)
         {
            u16LocalLrnPos = 0;
         }
         else
         {
            if (s32LocalDv2LrnDec < 16384)
            {
               u16LocalLrnPos =
                  (uint16)MATHSRV_udtMAX(u16LocalLrnPos,
                                         (uint16)s32LocalDv2LrnDec);
            }
         }
         VEMS_vidSET(Dv_2_app_pos_ped_pc, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_2_app_pc_tempo2 = 0;
   }
   Dv_init_2_app_pc_tempo2_prev = Dv_init_2_app_pc_tempo2;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidDvLrnFtFlDown2M                              */
/* !Description :  l'apprentissage butée haute est faite par incrémentation   */
/*                 par pas de la dernière valeur butée haute apprise. Le choix*/
/*                 se fait par calibration. La butée haute prend la valeur du */
/*                 minimum entre le résultat d'incrémentation et la valeur du */
/*                 rapport de tension.                                        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Aps_2_formated_position;                                     */
/*  input uint8 Dv_2_app_pos_ped_pc_max;                                      */
/*  input boolean Dv_init_2_app_pc_tempo1_prev;                               */
/*  input uint8 Dv_2_app_pc_tempo_delay;                                      */
/*  input uint8 Dv_2_app_pc_tempo1;                                           */
/*  input boolean Dv_app_pos_ped_pas_inst_pc;                                 */
/*  input uint16 Dv_2_app_pos_ped_pc;                                         */
/*  input uint16 Dv_2_app_increment_pc;                                       */
/*  input boolean Dv_init_2_app_pc_tempo1;                                    */
/*  output boolean Dv_init_2_app_pc_tempo1;                                   */
/*  output uint8 Dv_2_app_pc_tempo1;                                          */
/*  output uint16 Dv_2_app_pos_ped_pc;                                        */
/*  output boolean Dv_init_2_app_pc_tempo1_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidDvLrnFtFlDown2M(void)
{
   boolean bLocalTimeout1;
   uint16  u16LocalAps_2_formated_position;
   uint16  u16LocalDv_2_app_pos_ped_pc;
   uint16  u16LocalLrnPos;
   uint32  u32LocalDv2LrnInc;


   VEMS_vidGET(Aps_2_formated_position, u16LocalAps_2_formated_position);

   bLocalTimeout1 = 0;

   if (u16LocalAps_2_formated_position < (uint16)(Dv_2_app_pos_ped_pc_max * 4))
   {
      Dv_init_2_app_pc_tempo1 = 1;
      /* il faut initialiser la tempo et repositionner le timeout a zero sur
      front montant*/
      if (Dv_init_2_app_pc_tempo1_prev == 0)
      {
         Dv_2_app_pc_tempo1 = Dv_2_app_pc_tempo_delay;
      }
      else
      {
         if (Dv_2_app_pc_tempo1 != 0)
         {
            Dv_2_app_pc_tempo1 = (uint8)(Dv_2_app_pc_tempo1 - 1);
         }
         else
         {
            bLocalTimeout1 = 1;
         }
      }

      if (bLocalTimeout1 != 0)
      {
         u16LocalLrnPos = (uint16)(u16LocalAps_2_formated_position * 16);
         if (Dv_app_pos_ped_pas_inst_pc == 0)
         {
            VEMS_vidGET(Dv_2_app_pos_ped_pc, u16LocalDv_2_app_pos_ped_pc);
            u32LocalDv2LrnInc = (uint32)( u16LocalDv_2_app_pos_ped_pc
                                        + Dv_2_app_increment_pc);

            if (u32LocalDv2LrnInc < u16LocalLrnPos)
            {
               u16LocalLrnPos = (uint16)u32LocalDv2LrnInc;
            }
         }
         VEMS_vidSET(Dv_2_app_pos_ped_pc, u16LocalLrnPos);
      }
   }
   else
   {
      Dv_init_2_app_pc_tempo1 = 0;
   }
   Dv_init_2_app_pc_tempo1_prev = Dv_init_2_app_pc_tempo1;
}

/*------------------------------- end of file --------------------------------*/