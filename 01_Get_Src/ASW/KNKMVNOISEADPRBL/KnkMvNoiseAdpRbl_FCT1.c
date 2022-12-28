/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KnkMvNoiseAdpRbl                                        */
/* !Description     : KnkMvNoiseAdpRbl component.                             */
/*                                                                            */
/* !Module          : KnkMvNoiseAdpRbl                                        */
/* !Description     : ADAPTATION OF THE AVERAGE ENGINE NOISE (RUMBLE)         */
/*                                                                            */
/* !File            : KnkMvNoiseAdpRbl_FCT1.C                                 */
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
/*   1 / KnkMvNoiseAdpRbl_vidInit_adaptation_knk                              */
/*   2 / KnkMvNoiseAdpRbl_vidEnable_Adaptation                                */
/*   3 / KnkMvNoiseAdpRbl_vidActivation_condition                             */
/*   4 / KnkMvNoiseAdpRbl_vidAdaptation                                       */
/*   5 / KnkMvNoiseAdpRbl_vidCylindre_noi_ad_gain                             */
/*                                                                            */
/* !Reference   : V02 NT 10 02582 / 4                                         */
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
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "VEMS.h"
#include "KnkMvNoiseAdpRbl.h"
#include "KnkMvNoiseAdpRbl_L.h"
#include "KnkMvNoiseAdpRbl_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkMvNoiseAdpRbl_vidInit_adaptation_knk                    */
/* !Description :  Initialize the gain of adaptation to 1.                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint16 Knk_rbl_noi_ad_gain_uavn1[4];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkMvNoiseAdpRbl_vidInit_adaptation_knk(void)
{
   uint8 u8LocalIndex;

   for (u8LocalIndex=0;u8LocalIndex<4;u8LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(Knk_rbl_noi_ad_gain_uavn1 ,u8LocalIndex ,4096);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkMvNoiseAdpRbl_vidEnable_Adaptation                      */
/* !Description :  Manage the adaptation of the average noise if permitted or */
/*                 not then do adaptation action.                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void KnkMvNoiseAdpRbl_vidActivation_condition();              */
/*  extf argret void KnkMvNoiseAdpRbl_vidAdaptation();                        */
/*  input boolean Knk_rbl_noi_ad_cdn_ok_uavb0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkMvNoiseAdpRbl_vidEnable_Adaptation(void)
{
   KnkMvNoiseAdpRbl_vidActivation_condition();
   if (Knk_rbl_noi_ad_cdn_ok_uavb0 != 0)
   {
      KnkMvNoiseAdpRbl_vidAdaptation();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkMvNoiseAdpRbl_vidActivation_condition                   */
/* !Description :  The calculation of the adaptive of the clanking noise is   */
/*                 authorized only if the average noise is representative of  */
/*                 what is measured in normal conditions.                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint8 Temperature_eau;                                              */
/*  input boolean Detection_cliquetis[4];                                     */
/*  input boolean Knk_det_ris_knk_cyl_uavb1[4];                               */
/*  input boolean Detection_rbl[4];                                           */
/*  input boolean Detection_fort_cliquetis[4];                                */
/*  input uint8 Knk_rbl_noi_ad_cdn_n_hthresh;                                 */
/*  input uint8 Knk_rbl_noi_ad_cdn_n_lthresh;                                 */
/*  input uint16 Knk_rbl_noi_ad_cdn_load_hthrsh;                              */
/*  input uint16 Knk_rbl_noi_ad_cdn_load_lthrsh;                              */
/*  input uint8 Knk_rbl_noi_ad_cdn_tco_lthresh;                               */
/*  input boolean Knk_rbl_noi_ad_knk_manu_inh_uacb;                           */
/*  input boolean Knk_rbl_noi_ad_risknk_manu_inh_u;                           */
/*  input boolean Knk_rbl_noi_ad_manu_inh_uacb0;                              */
/*  output boolean Knk_rbl_noi_ad_cdn_ok_uavb0;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkMvNoiseAdpRbl_vidActivation_condition(void)
{
   boolean  bLocalKnk_sens_diag_act_uavb0;
   boolean  bLocalInhNoiseAdp;
   boolean  bLocalDetection_cliquetis;
   boolean  bLocalKnk_det_ris_knk_cyl_uavb1;
   boolean  bLocalDetection_rbl;
   boolean  bLocalDetection_fort_cliquetis;
   uint8    u8LocalRegime_moteur_32;
   uint8    u8LocalTemperature_eau;
   uint8    u8LocalKnkRbl_noCyl;
   uint16   u16LocalExt_rTotLd;

   VEMS_vidGET(KnkRbl_noCyl,u8LocalKnkRbl_noCyl);
   bLocalInhNoiseAdp = GDGAR_bGetFRM(FRM_FRM_INHNOISEADP);
   switch(u8LocalKnkRbl_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      /* warning QAC:Msg(2:2215) Indentation is not consistent with configured*/
      /*depth. This warning 2215 is to ignore if VEMS indentation rule        */
      /*is respected.                                                         */
         VEMS_vidGET(Knk_sens_diag_act_uavb0,bLocalKnk_sens_diag_act_uavb0);
         VEMS_vidGET(Regime_moteur_32,u8LocalRegime_moteur_32);
         VEMS_vidGET(Ext_rTotLd,u16LocalExt_rTotLd);
         VEMS_vidGET(Temperature_eau,u8LocalTemperature_eau);
         VEMS_vidGET1DArrayElement(Detection_cliquetis,
                                   u8LocalKnkRbl_noCyl,
                                   bLocalDetection_cliquetis);
         VEMS_vidGET1DArrayElement(Knk_det_ris_knk_cyl_uavb1,
                                   u8LocalKnkRbl_noCyl,
                                   bLocalKnk_det_ris_knk_cyl_uavb1);
         VEMS_vidGET1DArrayElement(Detection_rbl,
                                   u8LocalKnkRbl_noCyl,
                                   bLocalDetection_rbl);
         VEMS_vidGET1DArrayElement(Detection_fort_cliquetis,
                                   u8LocalKnkRbl_noCyl,
                                   bLocalDetection_fort_cliquetis);

         if (  (bLocalKnk_sens_diag_act_uavb0 == 0)
            && (u8LocalRegime_moteur_32 <= Knk_rbl_noi_ad_cdn_n_hthresh)
            && (u8LocalRegime_moteur_32 >= Knk_rbl_noi_ad_cdn_n_lthresh)
            && (u16LocalExt_rTotLd <= Knk_rbl_noi_ad_cdn_load_hthrsh)
            && (u16LocalExt_rTotLd >= Knk_rbl_noi_ad_cdn_load_lthrsh)
            && (u8LocalTemperature_eau >= Knk_rbl_noi_ad_cdn_tco_lthresh)
            && (bLocalInhNoiseAdp == 0)
            && (  (bLocalDetection_cliquetis == 0)
               ||  (Knk_rbl_noi_ad_knk_manu_inh_uacb != 0))
            && (  (bLocalKnk_det_ris_knk_cyl_uavb1 == 0)
               || (Knk_rbl_noi_ad_risknk_manu_inh_u != 0))
            && (bLocalDetection_rbl == 0)
            && (Knk_rbl_noi_ad_manu_inh_uacb0 == 0)
            && (bLocalDetection_fort_cliquetis == 0))
         {
            Knk_rbl_noi_ad_cdn_ok_uavb0 = 1;
         }
         else
         {
            Knk_rbl_noi_ad_cdn_ok_uavb0 = 0;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkMvNoiseAdpRbl_vidAdaptation                             */
/* !Description :  Calculate an adaptive by cylinder                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KnkMvNoiseAdpRbl_vidCylindre_noi_ad_gain();              */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Knk_rbl_noi_ad_gain_uavn0;                                   */
/*  output uint16 Knk_rbl_noi_ad_gain_uavn1[4];                               */
/*  output uint16 Knk_rbl_noi_ad_gain_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkMvNoiseAdpRbl_vidAdaptation(void)
{
   uint8 u8LocalKnkRbl_noCyl;


   VEMS_vidGET(KnkRbl_noCyl,u8LocalKnkRbl_noCyl);
   if (u8LocalKnkRbl_noCyl < 4)
   {
      KnkMvNoiseAdpRbl_vidCylindre_noi_ad_gain();
      VEMS_vidSET1DArrayElement(Knk_rbl_noi_ad_gain_uavn1,
                                u8LocalKnkRbl_noCyl,
                                Knk_rbl_noi_ad_gain_uavn0);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KnkMvNoiseAdpRbl_vidCylindre_noi_ad_gain                   */
/* !Description :  The adaptive is updated according to the following         */
/*                 iteration: Adaptive [ k ] = Adaptive [ k-1 ] + Filter(Leak */
/*                 out) * (Setpoint - AveraigeNoise [k])                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Bruit_moyen_rbl_cyl[4];                                      */
/*  input uint16 Knk_rbl_noi_ad_gain_uavn1[4];                                */
/*  input uint16 Knk_rbl_noi_mv_sp_uacn0;                                     */
/*  input uint16 Knk_rbl_noi_ad_dz_uacn0;                                     */
/*  input uint16 Knk_rbl_noi_ad_filt_gain_uacn0;                              */
/*  input uint16 Knk_rbl_noi_ad_var_clmp_uacn0;                               */
/*  input uint8 Knk_rbl_noi_ad_gain_lclmp_uacn0;                              */
/*  input uint8 Knk_rbl_noi_ad_gain_hclmp_uacn0;                              */
/*  input uint16 Knk_rbl_noi_ad_gain_uavn0;                                   */
/*  output uint16 Knk_rbl_noi_ad_gain_uavn0;                                  */
/*  output boolean Knk_rbl_noi_ad_h_hit_uavb0;                                */
/*  output boolean Knk_rbl_noi_ad_l_hit_uavb0;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KnkMvNoiseAdpRbl_vidCylindre_noi_ad_gain(void)
{
   uint8   u8LocalKnkRbl_noCyl;
   uint16  u16LocalBruit_moyen_rbl_cyl;
   uint16  u16LocalKnk_rblnoi_ad_gain_uavn1;
   uint16  u16LocalAbsDiff;
   uint16  u16LocalKnk_gain_lclmp;
   uint16  u16LocalKnk_gain_hclmp;
   uint16  u16LocalMod;
   uint32  u32LocalClampInput;
   sint32  s32LocalDiff;
   sint32  s32LocalClampOutput;
   sint32  s32LocalClampInput2;

   VEMS_vidGET(KnkRbl_noCyl,u8LocalKnkRbl_noCyl);
   switch(u8LocalKnkRbl_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
      VEMS_vidGET1DArrayElement(Bruit_moyen_rbl_cyl,
                                u8LocalKnkRbl_noCyl,
                                u16LocalBruit_moyen_rbl_cyl);
      VEMS_vidGET1DArrayElement(Knk_rbl_noi_ad_gain_uavn1,
                                u8LocalKnkRbl_noCyl,
                                u16LocalKnk_rblnoi_ad_gain_uavn1);
      s32LocalDiff = (sint32)(Knk_rbl_noi_mv_sp_uacn0
                            - u16LocalBruit_moyen_rbl_cyl);
      u16LocalAbsDiff = (uint16)MATHSRV_udtABS(s32LocalDiff);

      if (u16LocalAbsDiff > Knk_rbl_noi_ad_dz_uacn0)
      {
         u32LocalClampInput = (Knk_rbl_noi_ad_filt_gain_uacn0
                              * u16LocalAbsDiff );

         if (u32LocalClampInput < 171798692)
         {
            u32LocalClampInput = (u32LocalClampInput * 25) / 4096;
         }
         else
         {
            u16LocalMod = (uint16)(u32LocalClampInput % 4096);
            u16LocalMod = (uint16)((u16LocalMod * 25) / 4096);
            u32LocalClampInput = u32LocalClampInput / 4096;

            u32LocalClampInput =
               (u32LocalClampInput * 25) + u16LocalMod;
         }
         if (s32LocalDiff < 0)
         {
            s32LocalClampOutput =
               MATHSRV_udtMAX( -(sint32)u32LocalClampInput,
                               -(sint32)(Knk_rbl_noi_ad_var_clmp_uacn0));
         }
         else
         {
            s32LocalClampOutput =
               MATHSRV_udtMIN( (sint32)u32LocalClampInput,
                               (sint32)Knk_rbl_noi_ad_var_clmp_uacn0);
         }
      }
      else
      {
         s32LocalClampOutput = 0;
      }

      s32LocalClampInput2 = ((sint32)u16LocalKnk_rblnoi_ad_gain_uavn1
                                   + s32LocalClampOutput);

      u16LocalKnk_gain_lclmp = (uint16) ( Knk_rbl_noi_ad_gain_lclmp_uacn0
                                      * 256);

      u16LocalKnk_gain_hclmp = (uint16)( Knk_rbl_noi_ad_gain_hclmp_uacn0
                                       * 256);
      Knk_rbl_noi_ad_gain_uavn0 = (uint16)MATHSRV_udtCLAMP(
                                                s32LocalClampInput2,
                                                u16LocalKnk_gain_lclmp,
                                                u16LocalKnk_gain_hclmp);
      /* Msg(3:0291) An integer expression with a value that is               */
      /* apparently negative is being converted to an unsigned type.          */
      /* !justification: The variable Knk_rbl_noi_ad_gain_uavn0               */
      /* is an uint16 and casted between 2 uint16                             */
      if (Knk_rbl_noi_ad_gain_uavn0 == u16LocalKnk_gain_hclmp)
      {
         Knk_rbl_noi_ad_h_hit_uavb0 = 1;
      }
      else
      {
         Knk_rbl_noi_ad_h_hit_uavb0 = 0;
      }
      if(Knk_rbl_noi_ad_gain_uavn0 == u16LocalKnk_gain_lclmp)
      {
         Knk_rbl_noi_ad_l_hit_uavb0 = 1;
      }
      else
      {
         Knk_rbl_noi_ad_l_hit_uavb0 = 0;
      }
      break;

      default:
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
}

/*------------------------------- end of file --------------------------------*/