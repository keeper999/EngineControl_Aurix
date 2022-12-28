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
/* !File            : ACCPLRNPOS_FCT1.C                                       */
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
/*   1 / ACCPLRNPOS_vidInitOutput                                             */
/*   2 / ACCPLRNPOS_vidFreeLearningMgt                                        */
/*   3 / ACCPLRNPOS_vidLrnMgtDetectorHigh                                     */
/*   4 / ACCPLRNPOS_vidLrnMgtDetectorLow                                      */
/*   5 / ACCPLRNPOS_vidCalculation                                            */
/*   6 / ACCPLRNPOS_NVMSRV_vidInit                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 03749 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPLRNPOS/ACCPLRNPOS_FCT1.C_$*/
/* $Revision::   1.4                                                         $*/
/* $Author::   hmelloul                               $$Date::   15 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACCPLRNPOS.h"
#include "ACCPLRNPOS_L.h"
#include "ACCPLRNPOS_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidInitOutput                                   */
/* !Description :  A la première mise sous tension, les valeurs butées haute  */
/*                 et basse sont initialisée à des valeurs calibrables        */
/*                 (respectivement Rpli et Rpfi)                              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Tr_test_bed_mode_dyn;                                       */
/*  input boolean Tr_test_bed_mode_stat;                                      */
/*  output boolean Dv_init_1_app_pc_tempo1;                                   */
/*  output boolean Dv_init_1_app_pc_tempo1_prev;                              */
/*  output boolean Dv_init_1_app_pc_tempo2;                                   */
/*  output boolean Dv_init_1_app_pc_tempo2_prev;                              */
/*  output boolean Dv_init_1_app_pl_tempo1;                                   */
/*  output boolean Dv_init_1_app_pl_tempo1_prev;                              */
/*  output boolean Dv_init_1_app_pl_tempo2;                                   */
/*  output boolean Dv_init_1_app_pl_tempo2_prev;                              */
/*  output boolean Dv_init_2_app_pc_tempo1;                                   */
/*  output boolean Dv_init_2_app_pc_tempo1_prev;                              */
/*  output boolean Dv_init_2_app_pc_tempo2;                                   */
/*  output boolean Dv_init_2_app_pc_tempo2_prev;                              */
/*  output boolean Dv_init_2_app_pl_tempo1;                                   */
/*  output boolean Dv_init_2_app_pl_tempo1_prev;                              */
/*  output boolean Dv_init_2_app_pl_tempo2;                                   */
/*  output boolean Dv_init_2_app_pl_tempo2_prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidInitOutput(void)
{
   if (  (Tr_test_bed_mode_dyn  == 0)
      && (Tr_test_bed_mode_stat == 0))
   {
      /* Timers initialization */
      Dv_init_1_app_pc_tempo1 = 0;
      Dv_init_1_app_pc_tempo1_prev = 0;
      Dv_init_1_app_pc_tempo2 = 0;
      Dv_init_1_app_pc_tempo2_prev = 0;
      Dv_init_1_app_pl_tempo1 = 0;
      Dv_init_1_app_pl_tempo1_prev = 0;
      Dv_init_1_app_pl_tempo2 = 0;
      Dv_init_1_app_pl_tempo2_prev = 0;
      Dv_init_2_app_pc_tempo1 = 0;
      Dv_init_2_app_pc_tempo1_prev = 0;
      Dv_init_2_app_pc_tempo2 = 0;
      Dv_init_2_app_pc_tempo2_prev = 0;
      Dv_init_2_app_pl_tempo1 = 0;
      Dv_init_2_app_pl_tempo1_prev = 0;
      Dv_init_2_app_pl_tempo2 = 0;
      Dv_init_2_app_pl_tempo2_prev = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidFreeLearningMgt                              */
/* !Description :  Calcul des apprentissages des positions pied levé et pied à*/
/*                 fond de la pédale d’accélérateur sur deux signaux des      */
/*                 capteurs haut et bas de cette dernière                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPLRNPOS_vidCalculation();                             */
/*  extf argret void ACCPLRNPOS_vidLrnMgtDetectorLow();                       */
/*  extf argret void ACCPLRNPOS_vidLrnMgtDetectorHigh();                      */
/*  input boolean Tr_test_bed_mode_dyn;                                       */
/*  input boolean Tr_test_bed_mode_stat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidFreeLearningMgt(void)
{
   if (  (Tr_test_bed_mode_dyn  == 0)
      && (Tr_test_bed_mode_stat == 0))
   {
      ACCPLRNPOS_vidCalculation();
      ACCPLRNPOS_vidLrnMgtDetectorLow();
      ACCPLRNPOS_vidLrnMgtDetectorHigh();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidLrnMgtDetectorHigh                           */
/* !Description :  Calcul des apprentissages des positions pied levé et pied à*/
/*                 fond de la pédale d’accélérateur sur le signal du capteur  */
/*                 haut de cette dernière                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B.HARIBI                                                   */
/* !Trace_To    :  VEMS_R_08_03749_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootFullDown1();                      */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootFullDown2();                      */
/*  input boolean Moteur_tournant;                                            */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Dv_app_eng_speed_thresh_pc;                                   */
/*  input uint8 Dv_app_eng_speed_thresh_min_pc;                               */
/*  input boolean ACCPLRNPOS_bAutoris_1_app_pl_pc;                            */
/*  input boolean ACCPLRNPOS_bAutoris_2_app_pl_pc;                            */
/*  output boolean Dv_app_pc_eng_spd_enable;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidLrnMgtDetectorHigh(void)
{
   boolean bLocalMoteur_tournant;
   uint8   u8LocalRegime_moteur_32;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   if (  (u8LocalRegime_moteur_32 < Dv_app_eng_speed_thresh_pc)
      && (  (bLocalMoteur_tournant == 0)
         || (u8LocalRegime_moteur_32 >= Dv_app_eng_speed_thresh_min_pc)))
   {
      Dv_app_pc_eng_spd_enable = 1;
   }
   else
   {
      Dv_app_pc_eng_spd_enable = 0;
   }

   if (ACCPLRNPOS_bAutoris_1_app_pl_pc != 0)
   {
      ACCPLRNPOS_vidDvLrnFootFullDown1();
   }

   if (ACCPLRNPOS_bAutoris_2_app_pl_pc != 0)
   {
      ACCPLRNPOS_vidDvLrnFootFullDown2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidLrnMgtDetectorLow                            */
/* !Description :  Calcul des apprentissages des positions pied levé et pied à*/
/*                 fond de la pédale d’accélérateur sur le signal du capteur  */
/*                 has de cette dernière                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B.HARIBI                                                   */
/* !Trace_To    :  VEMS_R_08_03749_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootUp1();                            */
/*  extf argret void ACCPLRNPOS_vidDvLrnFootUp2();                            */
/*  input boolean Moteur_tournant;                                            */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Dv_app_eng_speed_thresh_pl;                                   */
/*  input uint8 Dv_app_eng_speed_thresh_min_pl;                               */
/*  input boolean ACCPLRNPOS_bAutoris_1_app_pl_pc;                            */
/*  input boolean ACCPLRNPOS_bAutoris_2_app_pl_pc;                            */
/*  output boolean Dv_app_pl_eng_spd_enable;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidLrnMgtDetectorLow(void)
{
   boolean bLocalMoteur_tournant;
   uint8   u8LocalRegime_moteur_32;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   if (  (u8LocalRegime_moteur_32 < Dv_app_eng_speed_thresh_pl)
      && (  (bLocalMoteur_tournant == 0)
         || (u8LocalRegime_moteur_32 >= Dv_app_eng_speed_thresh_min_pl)))
   {
      Dv_app_pl_eng_spd_enable = 1;
   }
   else
   {
      Dv_app_pl_eng_spd_enable = 0;
   }


   if (ACCPLRNPOS_bAutoris_1_app_pl_pc != 0)
   {
      ACCPLRNPOS_vidDvLrnFootUp1();
   }

   if (ACCPLRNPOS_bAutoris_2_app_pl_pc != 0)
   {
      ACCPLRNPOS_vidDvLrnFootUp2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_vidCalculation                                  */
/* !Description :  Les calculs sont inhibés sur des pannes mémorisées         */
/*                 concernant les deux capteurs de la pédale d’accélérateur.  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B.HARIBI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  output boolean ACCPLRNPOS_bAutoris_1_app_pl_pc;                           */
/*  output boolean ACCPLRNPOS_bAutoris_2_app_pl_pc;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPLRNPOS_vidCalculation(void)
{
   boolean bLocalAcvPed1;
   boolean bLocalAcvPed2;


   bLocalAcvPed1 = GDGAR_bGetFRM(FRM_FRM_ACVPED1);
   bLocalAcvPed2 = GDGAR_bGetFRM(FRM_FRM_ACVPED2);

   if (bLocalAcvPed1 != 0)
   {
      ACCPLRNPOS_bAutoris_1_app_pl_pc = 0;
   }
   else
   {
      ACCPLRNPOS_bAutoris_1_app_pl_pc = 1;
   }

   if (bLocalAcvPed2 != 0)
   {
      ACCPLRNPOS_bAutoris_2_app_pl_pc = 0;
   }
   else
   {
      ACCPLRNPOS_bAutoris_2_app_pl_pc = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPLRNPOS_NVMSRV_vidInit                                  */
/* !Description :  A la première mise sous tension, les valeurs butées haute  */
/*                 et basse sont initialisée à des valeurs calibrable         */
/* !Number      :  FCT1.6                                                     */
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
void ACCPLRNPOS_NVMSRV_vidInit(void)
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