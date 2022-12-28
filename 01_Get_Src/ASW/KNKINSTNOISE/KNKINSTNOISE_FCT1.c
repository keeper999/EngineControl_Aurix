/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKINSTNOISE                                            */
/* !Description     : KNKINSTNOISE Component                                  */
/*                                                                            */
/* !Module          : KNKINSTNOISE                                            */
/* !Description     : CALCUL DU BRUIT INSTANTANE POUR LA STRATEGIE DE         */
/*                    DETECTION DE CLIQUETIS                                  */
/*                                                                            */
/* !File            : KNKINSTNOISE_FCT1.C                                     */
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
/*   1 / KNKINSTNOISE_vidInitInstantNoise                                     */
/*   2 / KNKINSTNOISE_vidCalcInstantNoise                                     */
/*   3 / KNKINSTNOISE_vidFormatInstNoise                                      */
/*                                                                            */
/* !Reference   : V02 NT 08 05345 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#050451                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/KNKTREAT/KNKINSTNOISE/KNKINSTNOISE$*/
/* $Revision::   1.6      $$Author::   wbouach        $$Date::   19 Oct 2010 $*/
/* $Author::   wbouach                                $$Date::   19 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "KNKINSTNOISE.h"
#include "KNKINSTNOISE_L.h"
#include "KNKINSTNOISE_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISE_vidInitInstantNoise                           */
/* !Description :  Le vecteur de Bruit_instantane est initialisé à 0. De cette*/
/*                 façon, on s’assure que la valeur du bruit des cylindres non*/
/*                 existants vaut 0. (Dans le cas du moteur trois cylindres,  */
/*                 Bruit_instantane_cyl4 vaudra toujours 0)                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output uint16 Bruit_instantane[4];                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISE_vidInitInstantNoise(void)
{
   uint16 u16LocalBruit_instantane[KNKINSTNOISE_u32ARRAY_LENGTH];


   u16LocalBruit_instantane[0] = 0;
   u16LocalBruit_instantane[1] = 0;
   u16LocalBruit_instantane[2] = 0;
   u16LocalBruit_instantane[3] = 0;
   VEMS_vidSET1DArray(Bruit_instantane,
                      KNKINSTNOISE_u32ARRAY_LENGTH,
                      u16LocalBruit_instantane);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISE_vidCalcInstantNoise                           */
/* !Description :  Le calcul est inhibé lors du diagnostic du capteur         */
/*                 cliquetis, car dans ce mode les fenêtres d'acquisition du  */
/*                 bruit  moteur sont différentes de leur valeur en mode      */
/*                 détection.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKINSTNOISE_vidFormatInstNoise();                       */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISE_vidCalcInstantNoise(void)
{
   boolean bLocalKnk_sens_diag_act_uavb0;


   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   if (bLocalKnk_sens_diag_act_uavb0 == 0)
   {
      KNKINSTNOISE_vidFormatInstNoise();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISE_vidFormatInstNoise                            */
/* !Description :  Le formatage du bruit instantané se fait en deux étapes:   */
/*                 (1) un préformatage statique  (2) une adaptation dynamique */
/*                 permanente                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  W.AKKARI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint8 Knk_noi_fmt_load_bkpt_uacn1[16];                              */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Knk_noi_fmt_n_bkpt_uacn1[8];                                  */
/*  input uint8 Knk_noCyl;                                                    */
/*  input uint8 Knk_noi_fmt_map_cyl1_uacn2[16][8];                            */
/*  input uint8 Knk_noi_fmt_map_cyl2_uacn2[16][8];                            */
/*  input uint8 Knk_noi_fmt_map_cyl3_uacn2[16][8];                            */
/*  input uint8 Knk_noi_fmt_map_cyl4_uacn2[16][8];                            */
/*  input uint16 Knk_noi_ad_gain_uavn1[4];                                    */
/*  input uint16 Somme_clq_cyl[4];                                            */
/*  output uint16 Bruit_instantane[4];                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISE_vidFormatInstNoise(void)
{
   boolean bLocalKnk_noCylInRange;
   uint8   u8LocalKnkNoiCylXUacn2;
   uint8   u8LocalExt_rTotLd;
   uint8   u8LocalKnk_noCyl;
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalSitInterpY;
   uint16  u16LocalSitInterpX;
   uint16  u16LocalExt_rTotLd;
   uint16  u16LocalKnk_noi_ad_gain_uavn1;
   uint16  u16LocalSomme_clq_cyl;
   uint16  u16LocalBruit_instantane;
   uint32  u32LocalKnkCyl;


   VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
   u8LocalExt_rTotLd = (uint8)(u16LocalExt_rTotLd / 256);
   u16LocalSitInterpX = MATHSRV_u16CalcParaIncAryU8(Knk_noi_fmt_load_bkpt_uacn1,
                                                    u8LocalExt_rTotLd,
                                                    16);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalSitInterpY = MATHSRV_u16CalcParaIncAryU8(Knk_noi_fmt_n_bkpt_uacn1,
                                                    u8LocalRegime_moteur_32,
                                                    8);
   VEMS_vidGET(Knk_noCyl, u8LocalKnk_noCyl);
   switch (u8LocalKnk_noCyl)
   {
      case 0:
         bLocalKnk_noCylInRange = 1;
         u8LocalKnkNoiCylXUacn2 =
               MATHSRV_u8Interp2d(&Knk_noi_fmt_map_cyl1_uacn2[0][0],
                                  u16LocalSitInterpX,
                                  u16LocalSitInterpY,
                                  8);
         break;

      case 1:
         bLocalKnk_noCylInRange = 1;
         u8LocalKnkNoiCylXUacn2 =
               MATHSRV_u8Interp2d(&Knk_noi_fmt_map_cyl2_uacn2[0][0],
                                  u16LocalSitInterpX,
                                  u16LocalSitInterpY,
                                  8);
         break;

      case 2:
         bLocalKnk_noCylInRange = 1;
         u8LocalKnkNoiCylXUacn2 =
               MATHSRV_u8Interp2d(&Knk_noi_fmt_map_cyl3_uacn2[0][0],
                                  u16LocalSitInterpX,
                                  u16LocalSitInterpY,
                                  8);
         break;

      case 3:
         bLocalKnk_noCylInRange = 1;
         u8LocalKnkNoiCylXUacn2 =
               MATHSRV_u8Interp2d(&Knk_noi_fmt_map_cyl4_uacn2[0][0],
                                  u16LocalSitInterpX,
                                  u16LocalSitInterpY,
                                  8);
         break;

      default:
         u8LocalKnk_noCyl = 0;
         bLocalKnk_noCylInRange = 0;
         u8LocalKnkNoiCylXUacn2 = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   if (bLocalKnk_noCylInRange != 0)
   {
      if (u8LocalKnkNoiCylXUacn2 != 0)
      {
         VEMS_vidGET1DArrayElement(Knk_noi_ad_gain_uavn1,
                                   u8LocalKnk_noCyl,
                                   u16LocalKnk_noi_ad_gain_uavn1);
         VEMS_vidGET1DArrayElement(Somme_clq_cyl,
                                   u8LocalKnk_noCyl,
                                   u16LocalSomme_clq_cyl);
         u32LocalKnkCyl = (uint32)( u16LocalSomme_clq_cyl
                                  * u16LocalKnk_noi_ad_gain_uavn1);
         if (u32LocalKnkCyl <= (UINT32_MAX / (uint32)u8LocalKnkNoiCylXUacn2))
         {
            u32LocalKnkCyl = ( (u32LocalKnkCyl * u8LocalKnkNoiCylXUacn2)
                             + 204800)
                           / 409600;
         }
         else
         {
            u32LocalKnkCyl = (u32LocalKnkCyl + 128) / 256;
            u32LocalKnkCyl = ((u32LocalKnkCyl * u8LocalKnkNoiCylXUacn2) + 800)
                           / 1600;
         }
         u16LocalBruit_instantane = (uint16)MATHSRV_udtMIN(u32LocalKnkCyl,
                                                           65535);
      }
      else
      {
         u16LocalBruit_instantane = 0;
      }

      VEMS_vidSET1DArrayElement(Bruit_instantane,
                                u8LocalKnk_noCyl,
                                u16LocalBruit_instantane);
   }
}

/*--------------------------------- end of file ------------------------------*/