/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AccP                                                    */
/* !Description     : AccP component.                                         */
/*                                                                            */
/* !Module          : ACCPCALCRPOS                                            */
/* !Description     : Calcul de la position pedale relative a partir des      */
/*                    positions pied à fond et pied leve                      */
/*                                                                            */
/* !File            : ACCPCALCRPOS_FCT1.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / ACCPCALCRPOS_vidInit                                                 */
/*   2 / ACCPCALCRPOS_vidDVApp                                                */
/*   3 / ACCPCALCRPOS_vidAcquisitionDVApp                                     */
/*   4 / ACCPCALCRPOS_vidApsPedPos                                            */
/*   5 / ACCPCALCRPOS_vidEtat_pos_aps                                         */
/*   6 / ACCPCALCRPOS_vidDetection_aps                                        */
/*   7 / ACCPCALCRPOS_vidFinal_state_Pos                                      */
/*   8 / ACCPCALCRPOS_vidFinal_Detection                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_7293537 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPCALCRPOS/AccPCalcRPos_fct$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   wbouach                                $$Date::   22 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACCPCALCRPOS.h"
#include "ACCPCALCRPOS_L.h"
#include "ACCPCALCRPOS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidInit                                       */
/* !Description :  Cette fonction initialise les variables produites par le   */
/*                 module ACCPCALCRPOS                                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Dv_position_pedale_relative;                                 */
/*  output boolean Dv_detection_pied_leve_final;                              */
/*  output boolean Dv_detection_pied_leve;                                    */
/*  output boolean Dv_detection_pied_a_fond;                                  */
/*  output uint8 Dv_Etat_Pedale;                                              */
/*  output uint8 AccP_stAccP;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidInit(void)
{
   VEMS_vidSET(Dv_position_pedale_relative, 0);
   VEMS_vidSET(Dv_detection_pied_leve_final, 0);
   VEMS_vidSET(Dv_detection_pied_leve, 0);
   VEMS_vidSET(Dv_detection_pied_a_fond, 0);
   VEMS_vidSET(Dv_Etat_Pedale, PIED_LEVE);
   VEMS_vidSET(AccP_stAccP, PIED_LEVE);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidDVApp                                      */
/* !Description :  Cette fonction calcule la position pedale relative a partir*/
/*                 des  positions pied à fond et pied leve                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPCALCRPOS_vidAcquisitionDVApp();                      */
/*  input boolean Tr_test_bed_mode_dyn;                                       */
/*  input boolean Tr_test_bed_mode_stat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidDVApp(void)
{
   if (  (Tr_test_bed_mode_dyn == 0)
      && (Tr_test_bed_mode_stat == 0))
   {
      ACCPCALCRPOS_vidAcquisitionDVApp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidAcquisitionDVApp                           */
/* !Description :  Acquisition de la position pedale                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPCALCRPOS_vidApsPedPos();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidAcquisitionDVApp(void)
{
   ACCPCALCRPOS_vidApsPedPos();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidApsPedPos                                  */
/* !Description :  Calcul de la position pédale finale bornee par la position */
/*                 pédale RVV et la position pédale LVV                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint8 Position_pedale_limiteur;                                     */
/*  input uint8 Position_pedale_regulateur;                                   */
/*  output uint8 Dv_position_pedale_relative;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidApsPedPos(void)
{
   uint8  u8LocalPosition_ped_regulateur;
   uint8  u8LocalPosition_pedale_limiteur;
   uint8  u8LocalDv_pos_ped_relative;
   uint16 u16LocalAccP_rAccP;
   uint16 u16LocalMax;
   uint16 u16LocalPosPedReg;


   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   VEMS_vidGET(Position_pedale_limiteur, u8LocalPosition_pedale_limiteur);
   VEMS_vidGET(Position_pedale_regulateur, u8LocalPosition_ped_regulateur);

   u16LocalPosPedReg = (uint16)((u16LocalAccP_rAccP + 25) / 50);
   u16LocalMax = (uint16)MATHSRV_udtMAX(u8LocalPosition_ped_regulateur,
                                        u16LocalPosPedReg);
   u8LocalDv_pos_ped_relative =
      (uint8)MATHSRV_udtMIN(u16LocalMax, u8LocalPosition_pedale_limiteur);

   VEMS_vidSET(Dv_position_pedale_relative, u8LocalDv_pos_ped_relative);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidEtat_pos_aps                               */
/* !Description :  Ce bloc décrit l’état de la pédale accélérateur à partir de*/
/*                 l’information volonté conducteur.                          */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPCALCRPOS_vidDetection_aps();                         */
/*  input boolean Tr_test_bed_mode_dyn;                                       */
/*  input boolean Tr_test_bed_mode_stat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidEtat_pos_aps(void)
{
   if (  (Tr_test_bed_mode_dyn == 0)
      && (Tr_test_bed_mode_stat == 0))
   {
      ACCPCALCRPOS_vidDetection_aps();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidDetection_aps                              */
/* !Description :  L’information position pédale relative permet de détecter  */
/*                 le pied levé et le pied à fond pédale, cette détection est */
/*                 basée dans les deux cas sur un seuil avec hystérésis.      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  PTS_DOC_7293537_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AccP_rAccP;                                                  */
/*  input boolean Dv_detection_pied_leve;                                     */
/*  input boolean Dv_detection_pied_a_fond;                                   */
/*  input uint16 Dv_detect_pl_low_thresh;                                     */
/*  input uint16 Dv_detect_pl_high_thresh;                                    */
/*  input uint16 Dv_detect_pc_low_thresh;                                     */
/*  input uint16 Dv_detect_pc_high_thresh;                                    */
/*  output uint8 Dv_Etat_Pedale;                                              */
/*  output uint8 AccP_stAccP;                                                 */
/*  output boolean Dv_detection_pied_leve;                                    */
/*  output boolean Dv_detection_pied_a_fond;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidDetection_aps(void)
{
   uint16  u16LocalAccP_rAccP;
   uint8   u8LocalDv_Etat_Pedale;
   boolean bLocalDv_detection_pied_leve;
   boolean bLocalDv_detection_pied_a_fond;


   VEMS_vidGET(AccP_rAccP, u16LocalAccP_rAccP);
   VEMS_vidGET(Dv_detection_pied_leve, bLocalDv_detection_pied_leve);
   VEMS_vidGET(Dv_detection_pied_a_fond, bLocalDv_detection_pied_a_fond);

   MATHSRV_vidSchmittTriggerU16(u16LocalAccP_rAccP,
                                Dv_detect_pl_low_thresh,
                                Dv_detect_pl_high_thresh,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &bLocalDv_detection_pied_leve);

   MATHSRV_vidSchmittTriggerU16(u16LocalAccP_rAccP,
                                Dv_detect_pc_low_thresh,
                                Dv_detect_pc_high_thresh,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &bLocalDv_detection_pied_a_fond);

   if (bLocalDv_detection_pied_leve != 0)
   {
      u8LocalDv_Etat_Pedale = PIED_LEVE;
   }
   else
   {
      if (bLocalDv_detection_pied_a_fond != 0)
      {
         u8LocalDv_Etat_Pedale = PIED_A_FOND;
      }
      else
      {
         u8LocalDv_Etat_Pedale = CHARGE_PARTIELLE;
      }
   }

   VEMS_vidSET(Dv_Etat_Pedale, u8LocalDv_Etat_Pedale);
   VEMS_vidSET(AccP_stAccP, u8LocalDv_Etat_Pedale);
   VEMS_vidSET(Dv_detection_pied_leve, bLocalDv_detection_pied_leve);
   VEMS_vidSET(Dv_detection_pied_a_fond, bLocalDv_detection_pied_a_fond);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidFinal_state_Pos                            */
/* !Description :  Prise en compte de l’issue VEMS V02 ECU#056991 : Ajout de  */
/*                 la variable Dv_detection_pied_leve_final qui prend en      */
/*                 compte le régulateur de vitesse.                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACCPCALCRPOS_vidFinal_Detection();                       */
/*  input boolean Tr_test_bed_mode_dyn;                                       */
/*  input boolean Tr_test_bed_mode_stat;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidFinal_state_Pos(void)
{
   if (  (Tr_test_bed_mode_dyn == 0)
      && (Tr_test_bed_mode_stat == 0))
   {
      ACCPCALCRPOS_vidFinal_Detection();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPCALCRPOS_vidFinal_Detection                            */
/* !Description :  L’information position pédale relative permet de détecter  */
/*                 le pied levé, cette détection est  basée dans les deux cas */
/*                 sur un seuil avec hystérésis.                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input boolean Dv_detection_pied_leve_final;                               */
/*  input uint16 Dv_detect_pl_low_thresh;                                     */
/*  input uint16 Dv_detect_pl_high_thresh;                                    */
/*  output boolean Dv_detection_pied_leve_final;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPCALCRPOS_vidFinal_Detection(void)
{
   boolean bLocalDv_detection_pied_leve_f;
   uint8   u8LocalDv_position_pedale_rel;
   uint16  u16LocalLowTRiggerSchmitt;
   uint16  u16LocalHighTRiggerSchmitt;


   /*Production of Dv_detection_pied_leve_final*/
   VEMS_vidGET(Dv_position_pedale_relative, u8LocalDv_position_pedale_rel);
   VEMS_vidGET(Dv_detection_pied_leve_final, bLocalDv_detection_pied_leve_f);

   u16LocalLowTRiggerSchmitt = (uint16)(Dv_detect_pl_low_thresh / 50);
   u16LocalHighTRiggerSchmitt = (uint16)(Dv_detect_pl_high_thresh / 50);
   MATHSRV_vidSchmittTriggerU16((uint16)u8LocalDv_position_pedale_rel,
                                u16LocalLowTRiggerSchmitt,
                                u16LocalHighTRiggerSchmitt,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &bLocalDv_detection_pied_leve_f);

   VEMS_vidSET(Dv_detection_pied_leve_final, bLocalDv_detection_pied_leve_f);
}

/*------------------------------- end of file --------------------------------*/