/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKBENCHMOD                                             */
/* !Description     : KNKBENCHMOD Component                                   */
/*                                                                            */
/* !Module          : KNKBENCHMOD                                             */
/* !Description     : MODE BANC POUR LA CALIBRATION DE LA STRATEGIE DE        */
/*                    DETECTION DE CLIQUETIS                                  */
/*                                                                            */
/* !File            : KNKBENCHMOD_FCT1.C                                      */
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
/*   1 / KNKBENCHMOD_vidInitialization                                        */
/*   2 / KNKBENCHMOD_vidTestBed                                               */
/*   3 / KNKBENCHMOD_vidCalcVariables                                         */
/*   4 / KNKBENCHMOD_vidCalcDelay                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 00486 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KNKTREAT/KNKBENCHMOD/KNKBENCHMOD_F$*/
/* $Revision::   1.6      $$Author::   wbouach        $$Date::   26 Oct 2010 $*/
/* $Author::   wbouach                                $$Date::   26 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "KNKBENCHMOD.h"
#include "KNKBENCHMOD_L.h"
#include "KNKBENCHMOD_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKBENCHMOD_vidInitialization                              */
/* !Description :  Initialisation du Rapport signal/bruit (gain) par cylindre */
/*                 précédent                                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Bruit_instantane_test_bed_uavn0;                            */
/*  output uint16 Bruit_moyen_cyl_prev[4];                                    */
/*  output uint16 Bruit_moyen_for_test_bed_uavn0;                             */
/*  output uint8 Detection_cliq_test_bed_uavn0;                               */
/*  output uint8 Knk_gain_for_test_bed_uavn1[4];                              */
/*  output uint16 Knk_test_bed_delay_1_uavn0;                                 */
/*  output uint16 Knk_test_bed_delay_2_uavn0;                                 */
/*  output uint16 Knk_test_bed_delay_3_uavn0;                                 */
/*  output uint16 Knk_test_bed_delay_0_uavn0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKBENCHMOD_vidInitialization(void)
{
   Bruit_instantane_test_bed_uavn0 = 0;
   Bruit_moyen_cyl_prev[0] = 0;
   Bruit_moyen_cyl_prev[1] = 0;
   Bruit_moyen_cyl_prev[2] = 0;
   Bruit_moyen_cyl_prev[3] = 0;
   Bruit_moyen_for_test_bed_uavn0 = 0;
   Detection_cliq_test_bed_uavn0 = 0;
   Knk_gain_for_test_bed_uavn1[0] = 0;
   Knk_gain_for_test_bed_uavn1[1] = 0;
   Knk_gain_for_test_bed_uavn1[2] = 0;
   Knk_gain_for_test_bed_uavn1[3] = 0;
   Knk_test_bed_delay_1_uavn0 = 0;
   Knk_test_bed_delay_2_uavn0 = 0;
   Knk_test_bed_delay_3_uavn0 = 0;
   Knk_test_bed_delay_0_uavn0 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKBENCHMOD_vidTestBed                                     */
/* !Description :  Les fonctionnalités de calibration online ne sont utilisées*/
/*                 que lors de la mise au point. Par conséquent elles sont    */
/*                 inhibées en série.                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void KNKBENCHMOD_vidCalcVariables();                          */
/*  extf argret void KNKBENCHMOD_vidCalcDelay();                              */
/*  input uint16 Bruit_moyen_cyl[4];                                          */
/*  input boolean Knk_test_bed_uacb0;                                         */
/*  output uint16 Bruit_moyen_cyl_prev[4];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKBENCHMOD_vidTestBed(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalBruit_moyen_cyl[KNKBENCHMOD_u32ARRAY_LENGTH];

   /* Initialization used in order to avoid QAC warning 3204 */
   u16LocalBruit_moyen_cyl[0] = 0;
   VEMS_vidGET1DArray(Bruit_moyen_cyl,
                      KNKBENCHMOD_u32ARRAY_LENGTH,
                      u16LocalBruit_moyen_cyl);
   if (Knk_test_bed_uacb0 != 0)
   {
      KNKBENCHMOD_vidCalcVariables();
      KNKBENCHMOD_vidCalcDelay();
   }

   for (u8LocalIndex = 0;
        u8LocalIndex < KNKBENCHMOD_u32ARRAY_LENGTH;
        u8LocalIndex++)
   {
      Bruit_moyen_cyl_prev[u8LocalIndex] =
         u16LocalBruit_moyen_cyl[u8LocalIndex];
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKBENCHMOD_vidCalcVariables                               */
/* !Description :  Ce module permet de calculer les gains correspondants aux  */
/*                 rapports (bruit instantané – offset) / bruit moyen         */
/*                 (cylindre à cylindre), utilisés pour la calibration des    */
/*                 cartographies des gains de détection                       */
/*                 (Knk_det_gain_cyl*_n_map_uacn1).                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint16 Bruit_moyen_cyl_prev[4];                                     */
/*  input uint16 Bruit_instantane[4];                                         */
/*  input uint16 Bruit_moyen_cyl_min_thresh[4];                               */
/*  output uint8 Knk_gain_for_test_bed_uavn1[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKBENCHMOD_vidCalcVariables(void)
{
   uint8  u8LocalKnk_noCyl;
   uint16 u16LocalBruit_instantane;
   sint32 s32LocalGain;


   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   if (u8LocalKnk_noCyl < KNKBENCHMOD_u32ARRAY_LENGTH)
   {
      if (Bruit_moyen_cyl_prev[u8LocalKnk_noCyl] != 0)
      {
         VEMS_vidGET1DArrayElement(Bruit_instantane,
                                   u8LocalKnk_noCyl,
                                   u16LocalBruit_instantane);
         s32LocalGain = (sint32)( u16LocalBruit_instantane
                                - Bruit_moyen_cyl_min_thresh[u8LocalKnk_noCyl]);
         s32LocalGain = s32LocalGain * 32;
         s32LocalGain = s32LocalGain / Bruit_moyen_cyl_prev[u8LocalKnk_noCyl];
         Knk_gain_for_test_bed_uavn1[u8LocalKnk_noCyl] =
            (uint8)MATHSRV_udtCLAMP(s32LocalGain, 0, 255);
      }
      else
      {
         Knk_gain_for_test_bed_uavn1[u8LocalKnk_noCyl] = 255;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKBENCHMOD_vidCalcDelay                                   */
/* !Description :  Ce mode permet de générer une variable regroupant les      */
/*                 signaux des quatre cylindres (bruit instantané, bruit      */
/*                 moyen, gain, booléen de détection cliquetis) et d’effectuer*/
/*                 un retard sur les voies citées précédemment.               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Knk_test_bed_delay_2_uavn0;                                  */
/*  input uint16 Knk_test_bed_delay_1_uavn0;                                  */
/*  input uint16 Knk_test_bed_delay_0_uavn0;                                  */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint16 Bruit_instantane[4];                                         */
/*  input uint16 Bruit_moyen_cyl_prev[4];                                     */
/*  input uint8 Knk_gain_for_test_bed_uavn1[4];                               */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input uint8 Knk_test_bed_mode_uacn0;                                      */
/*  input uint16 Bruit_instantane_test_bed_uavn0;                             */
/*  input uint16 Bruit_moyen_for_test_bed_uavn0;                              */
/*  input uint8 Detection_cliq_test_bed_uavn0;                                */
/*  output uint16 Knk_test_bed_delay_3_uavn0;                                 */
/*  output uint16 Knk_test_bed_delay_2_uavn0;                                 */
/*  output uint16 Knk_test_bed_delay_1_uavn0;                                 */
/*  output uint16 Bruit_instantane_test_bed_uavn0;                            */
/*  output uint16 Bruit_moyen_for_test_bed_uavn0;                             */
/*  output uint8 Detection_cliq_test_bed_uavn0;                               */
/*  output uint16 Knk_test_bed_delay_0_uavn0;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKBENCHMOD_vidCalcDelay(void)
{
   boolean bLocalDetection_cliquetis;
   uint8   u8LocalGain;
   uint8   u8LocalKnk_noCyl;
   uint16  u16LocalBruit_instantane;
   uint32  u32LocalPhysToDec;


   Knk_test_bed_delay_3_uavn0 = Knk_test_bed_delay_2_uavn0;
   Knk_test_bed_delay_2_uavn0 = Knk_test_bed_delay_1_uavn0;
   Knk_test_bed_delay_1_uavn0 = Knk_test_bed_delay_0_uavn0;

   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   if (u8LocalKnk_noCyl < KNKBENCHMOD_u32ARRAY_LENGTH)
   {
      VEMS_vidGET1DArrayElement(Bruit_instantane,
                                u8LocalKnk_noCyl,
                                u16LocalBruit_instantane);
      Bruit_instantane_test_bed_uavn0 = u16LocalBruit_instantane;
      Bruit_moyen_for_test_bed_uavn0 = Bruit_moyen_cyl_prev[u8LocalKnk_noCyl];
      u8LocalGain = Knk_gain_for_test_bed_uavn1[u8LocalKnk_noCyl];
      VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                u8LocalKnk_noCyl,
                                bLocalDetection_cliquetis);
      if (bLocalDetection_cliquetis != 0)
      {
         Detection_cliq_test_bed_uavn0 = 1;
      }
      else
      {
         Detection_cliq_test_bed_uavn0 = 0;
      }

      switch (Knk_test_bed_mode_uacn0)
      {
         case 0:
            u32LocalPhysToDec = (uint32)(Bruit_instantane_test_bed_uavn0 * 64);
            Knk_test_bed_delay_0_uavn0 =
               (uint16)MATHSRV_udtMIN(u32LocalPhysToDec, 65535);
            break;

         case 1:
            u32LocalPhysToDec = (uint32)(Bruit_moyen_for_test_bed_uavn0 * 64);
            Knk_test_bed_delay_0_uavn0 =
               (uint16)MATHSRV_udtMIN(u32LocalPhysToDec, 65535);
            break;

         case 2:
            Knk_test_bed_delay_0_uavn0 = (uint16)(u8LocalGain * 256);
            break;

         case 3:
            Knk_test_bed_delay_0_uavn0 =
               (uint16)(Detection_cliq_test_bed_uavn0 * 65535);
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