/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RBLDETBENCH                                             */
/* !Description     : RBLDETBENCH component.                                  */
/*                                                                            */
/* !Module          : RBLDETBENCH                                             */
/* !Description     : MODE BANC POUR LA CALIBRATION DE LA DETECTION RUMBLE    */
/*                                                                            */
/* !File            : RBLDETBENCH_FCT1.C                                      */
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
/*   1 / RBLDETBENCH_vidInitOutput                                            */
/*   2 / RBLDETBENCH_vidRbl_Test_bed                                          */
/*   3 / RBLDETBENCH_vidcalc_variables                                        */
/*   4 / RBLDETBENCH_vidretard                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 02549 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#060167                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "RBLDETBENCH.h"
#include "RBLDETBENCH_L.h"
#include "RBLDETBENCH_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLDETBENCH_vidInitOutput                                  */
/* !Description :  fonction d'initialisation des variables prev.              */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Bruit_moy_rbl_for_test_bed_uavn0;                           */
/*  output uint16 Bruit_inst_rbl_test_bed_uavn0;                              */
/*  output uint8 Detection_rbl_test_bed_uavn0;                                */
/*  output uint16 Rbl_test_bed_delay_0_uavn0;                                 */
/*  output uint16 Rbl_test_bed_delay_1_uavn0;                                 */
/*  output uint16 Rbl_test_bed_delay_2_uavn0;                                 */
/*  output uint16 Rbl_test_bed_delay_3_uavn0;                                 */
/*  output uint16 Bruit_moy_rbl_cyl_prev[4];                                  */
/*  output uint8 Rbl_gain_for_test_bed_uavn1[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLDETBENCH_vidInitOutput(void)
{
   uint8  u8LocalIndex;


   Bruit_moy_rbl_for_test_bed_uavn0 = 0;
   Bruit_inst_rbl_test_bed_uavn0 = 0;
   Detection_rbl_test_bed_uavn0 = 0;
   Rbl_test_bed_delay_0_uavn0 = 0;
   Rbl_test_bed_delay_1_uavn0 = 0;
   Rbl_test_bed_delay_2_uavn0 = 0;
   Rbl_test_bed_delay_3_uavn0 = 0;
   for (u8LocalIndex = 0;
        u8LocalIndex < RBLDETBENCH_u16ARRAY_LENGTH;
        u8LocalIndex++)
   {
      Bruit_moy_rbl_cyl_prev[u8LocalIndex] = 0;
      Rbl_gain_for_test_bed_uavn1[u8LocalIndex] = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLDETBENCH_vidRbl_Test_bed                                */
/* !Description :  Ce module permet de calculer le rapport de bruit,créer une */
/*                 voie regroupant les quatre cylindres et  retarder de 1 à 3 */
/*                 pmh la voie qu’il a créée.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void RBLDETBENCH_vidcalc_variables();                         */
/*  extf argret void RBLDETBENCH_vidretard();                                 */
/*  input uint16 Bruit_moyen_rbl_cyl[4];                                      */
/*  input boolean Rbl_test_bed_uacb0;                                         */
/*  output uint16 Bruit_moy_rbl_cyl_prev[4];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLDETBENCH_vidRbl_Test_bed(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalBruit_moyen_rbl_cyl[RBLDETBENCH_u16ARRAY_LENGTH];


   u16LocalBruit_moyen_rbl_cyl[0] = 0;
   VEMS_vidGET1DArray(Bruit_moyen_rbl_cyl,
                      RBLDETBENCH_u16ARRAY_LENGTH,
                      u16LocalBruit_moyen_rbl_cyl);

   if (Rbl_test_bed_uacb0 != 0)
   {
      RBLDETBENCH_vidcalc_variables();
      RBLDETBENCH_vidretard();
   }

   for (u8LocalIndex = 0;
        u8LocalIndex < RBLDETBENCH_u16ARRAY_LENGTH;
        u8LocalIndex++)
   {
      Bruit_moy_rbl_cyl_prev[u8LocalIndex] =
         u16LocalBruit_moyen_rbl_cyl[u8LocalIndex];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLDETBENCH_vidcalc_variables                              */
/* !Description :  Ce module permet de calculer les gains correspondants aux  */
/*                 rapports (bruit instantané – offset) / bruit moyen         */
/*                 (cylindre à cylindre), utilisés pour la calibration des    */
/*                 cartographies des gains de détection.                      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Bruit_instantane_rbl[16][4];                                 */
/*  input uint16 Bruit_moy_rbl_cyl_prev[4];                                   */
/*  input uint16 Bruit_moyen_rbl_max_thresh[4];                               */
/*  output uint8 Rbl_gain_for_test_bed_uavn1[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLDETBENCH_vidcalc_variables(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalKnkRbl_noCyl;
   uint16 u16LocalBruitinstantaneRbl_Max;
   sint32 s32LocalGain;


   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);
   if (u8LocalKnkRbl_noCyl < RBLDETBENCH_u16ARRAY_LENGTH)
   {
      u16LocalBruitinstantaneRbl_Max = 0;
      for (u8LocalIndex = 0;
           u8LocalIndex < RBLDETBENCH_u8ARRAY_LENGTH;
           u8LocalIndex++)
      {
         if (Bruit_instantane_rbl[u8LocalIndex][u8LocalKnkRbl_noCyl] >
             u16LocalBruitinstantaneRbl_Max)
         {
            u16LocalBruitinstantaneRbl_Max =
               Bruit_instantane_rbl[u8LocalIndex][u8LocalKnkRbl_noCyl];
         }
      }
      if (Bruit_moy_rbl_cyl_prev[u8LocalKnkRbl_noCyl] != 0)
      {
         s32LocalGain =
            (sint32)( u16LocalBruitinstantaneRbl_Max
                    - Bruit_moyen_rbl_max_thresh[u8LocalKnkRbl_noCyl]);
         s32LocalGain = s32LocalGain * 32;
         s32LocalGain =
            s32LocalGain / Bruit_moy_rbl_cyl_prev[u8LocalKnkRbl_noCyl];
         Rbl_gain_for_test_bed_uavn1[u8LocalKnkRbl_noCyl] =
            (uint8)MATHSRV_udtCLAMP(s32LocalGain, 0, 255);
      }
      else
      {
         Rbl_gain_for_test_bed_uavn1[u8LocalKnkRbl_noCyl] = 255;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RBLDETBENCH_vidretard                                      */
/* !Description :  ce module permet de générer une variable regroupant les    */
/*                 signaux des quatre cylindres et d’effectuer un retard sur  */
/*                 les voies.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Rbl_test_bed_delay_2_uavn0;                                  */
/*  input uint16 Rbl_test_bed_delay_1_uavn0;                                  */
/*  input uint16 Rbl_test_bed_delay_0_uavn0;                                  */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Bruit_instantane_rbl[16][4];                                 */
/*  input uint16 Bruit_moy_rbl_cyl_prev[4];                                   */
/*  input uint8 Rbl_gain_for_test_bed_uavn1[4];                               */
/*  input boolean Detection_rbl[4];                                           */
/*  input uint8 Rbl_test_bed_mode_uacn0;                                      */
/*  input uint16 Bruit_inst_rbl_test_bed_uavn0;                               */
/*  input uint16 Bruit_moy_rbl_for_test_bed_uavn0;                            */
/*  input uint8 Detection_rbl_test_bed_uavn0;                                 */
/*  output uint16 Rbl_test_bed_delay_3_uavn0;                                 */
/*  output uint16 Rbl_test_bed_delay_2_uavn0;                                 */
/*  output uint16 Rbl_test_bed_delay_1_uavn0;                                 */
/*  output uint16 Bruit_inst_rbl_test_bed_uavn0;                              */
/*  output uint16 Bruit_moy_rbl_for_test_bed_uavn0;                           */
/*  output uint8 Detection_rbl_test_bed_uavn0;                                */
/*  output uint16 Rbl_test_bed_delay_0_uavn0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RBLDETBENCH_vidretard(void)
{
   boolean bLocalDetection_rbl;
   uint8   u8LocalIndex;
   uint8   u8LocalGain;
   uint8   u8LocalKnkRbl_noCyl;
   uint16  u16LocalBruitinstantaneRbl_Max;


   Rbl_test_bed_delay_3_uavn0 = Rbl_test_bed_delay_2_uavn0;
   Rbl_test_bed_delay_2_uavn0 = Rbl_test_bed_delay_1_uavn0;
   Rbl_test_bed_delay_1_uavn0 = Rbl_test_bed_delay_0_uavn0;

   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);
   if (u8LocalKnkRbl_noCyl < RBLDETBENCH_u16ARRAY_LENGTH)
   {
      u16LocalBruitinstantaneRbl_Max = 0;
      for (u8LocalIndex = 0;
           u8LocalIndex < RBLDETBENCH_u8ARRAY_LENGTH;
           u8LocalIndex++)
      {
         if (Bruit_instantane_rbl[u8LocalIndex][u8LocalKnkRbl_noCyl] >
                u16LocalBruitinstantaneRbl_Max)
         {
            u16LocalBruitinstantaneRbl_Max =
               Bruit_instantane_rbl[u8LocalIndex][u8LocalKnkRbl_noCyl];
         }
      }
      Bruit_inst_rbl_test_bed_uavn0 = u16LocalBruitinstantaneRbl_Max;
      Bruit_moy_rbl_for_test_bed_uavn0 =
         Bruit_moy_rbl_cyl_prev[u8LocalKnkRbl_noCyl];

      u8LocalGain = Rbl_gain_for_test_bed_uavn1[u8LocalKnkRbl_noCyl];
      VEMS_vidGET1DArrayElement(Detection_rbl,
                                u8LocalKnkRbl_noCyl,
                                bLocalDetection_rbl);
      if (bLocalDetection_rbl != 0)
      {
         Detection_rbl_test_bed_uavn0 = 1;
      }
      else
      {
         Detection_rbl_test_bed_uavn0 = 0;
      }

      switch (Rbl_test_bed_mode_uacn0)
      {
         case 0:
            Rbl_test_bed_delay_0_uavn0 = Bruit_inst_rbl_test_bed_uavn0;
            break;

         case 1:
            Rbl_test_bed_delay_0_uavn0 = Bruit_moy_rbl_for_test_bed_uavn0;
            break;

         case 2:
            Rbl_test_bed_delay_0_uavn0 = (uint16)( (uint32)(u8LocalGain * 65535)
                                                 / 255);
            break;

         case 3:
            Rbl_test_bed_delay_0_uavn0 =
              (uint16)(Detection_rbl_test_bed_uavn0 * 65535);
            break;

         default:
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*------------------------------- end of file --------------------------------*/