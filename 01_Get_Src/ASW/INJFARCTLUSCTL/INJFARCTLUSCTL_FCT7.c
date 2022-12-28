/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLUSCTL                                          */
/* !Description     : INJFARCTLUSCTL component                                */
/*                                                                            */
/* !Module          : INJFARCTLUSCTL                                          */
/* !Description     : CALCUL DE LA BOUCLE FERMEE DE LA REGULATION DE RICHESSE */
/*                    AVEC SONDE AMONT                                        */
/*                                                                            */
/* !File            : INJFARCTLUSCTL_FCT7.c                                   */
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
/*   1 / INJFARCTLUSCTL_vidLamdaGazDelcal                                     */
/*   2 / INJFARCTLUSCTL_vidLambdaGazDelay                                     */
/*   3 / INJFARCTLUSCTL_vidRangeCalc                                          */
/*   4 / INJFARCTLUSCTL_vidRangeFilt                                          */
/*   5 / INJFARCTLUSCTL_vidMeanLamFeedCal                                     */
/*   6 / INJFARCTLUSCTL_vidMeanCalc                                           */
/*   7 / INJFARCTLUSCTL_vidMeanFilt                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5215083 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/INJCTLSYS/INJFARCTLUSCTL/INJFARC$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   18 Apr 2014 $*/
/* $Author::   mbenfrad                               $$Date::   18 Apr 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "INJFARCTLUSCTL.H"
#include "INJFARCTLUSCTL_L.H"
#include "INJFARCTLUSCTL_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLamdaGazDelcal                           */
/* !Description :  Condition d'activation de la régulation de richesse en     */
/*                 boucle fermée.                                             */
/* !Number      :  FCT7.1                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05829_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLUSCTL_vidLambdaGazDelay();                      */
/*  input boolean Lambda_closed_loop;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLamdaGazDelcal(void)
{
   boolean bLocalLambda_closed_loop;


   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   if (bLocalLambda_closed_loop != 0)
   {
      INJFARCTLUSCTL_vidLambdaGazDelay();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidLambdaGazDelay                           */
/* !Description :  Ajouter une valeur d’offset en nombre de PMH en mode gaz   */
/*                 (Delta_PMH_gaz) au  temps de transfert (Transfer_count).   */
/* !Number      :  FCT7.2                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidRangeCalc();                           */
/*  extf argret void INJFARCTLUSCTL_vidRangeFilt();                           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Lambda_feedback_max_calc;                                   */
/*  input boolean Lambda_feedback_min_calc;                                   */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Engine_load_InjCtl_bkpt_map[9];                              */
/*  input uint8 Regime_moteur_InjCtl_bkpt_map[9];                             */
/*  input uint16 T_Regulation_map[9][9];                                      */
/*  input boolean Manu_inh_Delta_PMH_gaz;                                     */
/*  input sint16 Delta_lam_gaz;                                               */
/*  input uint16 Aregulation_filt;                                            */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 T_Regulation;                                                */
/*  output uint16 T_Regulation;                                               */
/*  output uint8 Delta_PMH_gaz;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidLambdaGazDelay(void)
{

   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalExt_noCylEng;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16Localinterp1;
   uint16  u16LocalEngine_load;
   uint16  u16LocalDelta_lam_gaz;
   uint16  u16LocalRegime_moteur;
   sint16  s16LocalDelta_lam_gaz;
   uint32  u32Local_Delta_PMH_gaz;
   sint32  s32LocalSwich;
   sint32  s32LocalDiv;
   sint32  s32Local_Delta_PMH_gaz;
   sint32  s32Local_Delta_PMH_gaz_div;
   sint32  s32Local_Delta_PMH_gaz_mod;

   if (  (Lambda_feedback_max_calc != 0)
      && (Lambda_feedback_min_calc != 0))
   {
      INJFARCTLUSCTL_vidRangeCalc();
   }
   INJFARCTLUSCTL_vidRangeFilt();

   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Engine_load_InjCtl_bkpt_map,
                                                u16LocalEngine_load,
                                                9);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_InjCtl_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);
   u16Localinterp1 = MATHSRV_u16Interp2d(T_Regulation_map[0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         9);
   T_Regulation = (uint16)MATHSRV_udtCLAMP(u16Localinterp1, 1, 256);

   if (  ( Manu_inh_Delta_PMH_gaz == 0 )
      && ( u8LocalExt_stSysGas == Ext_stGasMod_SC ))
   {
      VEMS_vidGET(Delta_lam_gaz, s16LocalDelta_lam_gaz);
      u16LocalDelta_lam_gaz = (uint16)MATHSRV_udtABS(s16LocalDelta_lam_gaz);
      s32LocalDiv = (sint32)( (10 * Aregulation_filt)
                            - (147 * u16LocalDelta_lam_gaz));
      s32LocalSwich = s32LocalDiv / 10;

      if (s32LocalSwich != 0)
      {
         VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
         VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
         u8LocalExt_noCylEng = (uint8)MATHSRV_udtCLAMP(u8LocalExt_noCylEng,
                                                       1,
                                                       12);
         u32Local_Delta_PMH_gaz = ( (uint32)( u16LocalRegime_moteur
                                            * u16LocalDelta_lam_gaz)
                                  / 2000);
         s32Local_Delta_PMH_gaz_div = ( (sint32)( 49 * u32Local_Delta_PMH_gaz
                                                * u8LocalExt_noCylEng)
                                      / s32LocalDiv);
         s32Local_Delta_PMH_gaz_mod = ( (sint32)( 49 * u32Local_Delta_PMH_gaz
                                                * u8LocalExt_noCylEng)
                                      % s32LocalDiv);
         /*Msg(2:0584) Division by value that is possibly zero: s32LocalDiv
         can't take zero */
         s32Local_Delta_PMH_gaz = s32Local_Delta_PMH_gaz_div * T_Regulation;

         s32Local_Delta_PMH_gaz = ( s32Local_Delta_PMH_gaz
                                  + ( ( s32Local_Delta_PMH_gaz_mod
                                      * T_Regulation)
                                    / s32LocalDiv));

         Delta_PMH_gaz = (uint8)MATHSRV_udtCLAMP(s32Local_Delta_PMH_gaz,
                                                 0,
                                                 255);
      }
      else
      {
         Delta_PMH_gaz = 255;
      }

   }
   else
   {
      Delta_PMH_gaz = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidRangeCalc                                */
/* !Description :  Calcul de l'amplitude du signal correcteur de richesse de  */
/*                 la régulation de richesse .                                */
/* !Number      :  FCT7.3                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Lambda_feedback_max;                                         */
/*  input sint16 Lambda_feedback_min;                                         */
/*  output uint16 Aregulation;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidRangeCalc(void)
{
   sint16  s16Local_Aregulation;

   s16Local_Aregulation = (sint16)( ( Lambda_feedback_max
                                    - Lambda_feedback_min)
                                  / 2);
   Aregulation = (uint16) MATHSRV_udtMAX(s16Local_Aregulation, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidRangeFilt                                */
/* !Description :  Calcul de l'amplitude du signal correcteur de richesse de  */
/*                 la régulation de richesse après filtrage .                 */
/* !Number      :  FCT7.4                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Reg_range_filtered_factor;                                    */
/*  input uint32 INJFARCTLUSCTL_u32AregulFiltMem;                             */
/*  input uint16 Aregulation;                                                 */
/*  output uint16 Aregulation_filt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidRangeFilt(void)
{

   Aregulation_filt =
      MATHSRV_u16FirstOrderFilterGu8(Reg_range_filtered_factor,
                                     &INJFARCTLUSCTL_u32AregulFiltMem,
                                     Aregulation);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidMeanLamFeedCal                           */
/* !Description :  Calcul de la moyenne du correcteur de richesse de la       */
/*                 régulation de richesse puis sa filtration .                */
/* !Number      :  FCT7.5                                                     */
/* !Author      :  BENNASR                                                    */
/* !Trace_To    :  VEMS_R_08_05829_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJFARCTLUSCTL_vidMeanCalc();                            */
/*  extf argret void INJFARCTLUSCTL_vidMeanFilt();                            */
/*  input boolean Lambda_feedback_max_calc;                                   */
/*  input boolean Lambda_feedback_min_calc;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidMeanLamFeedCal(void)
{

   if (  (Lambda_feedback_max_calc != 0)
      && (Lambda_feedback_min_calc != 0))
   {
      INJFARCTLUSCTL_vidMeanCalc();
   }
   INJFARCTLUSCTL_vidMeanFilt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidMeanCalc                                 */
/* !Description :  Calcul de la valeur moyenne du correcteur de richesse de la*/
/*                 régulation de richesse .                                   */
/* !Number      :  FCT7.6                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 Lambda_feedback_max;                                         */
/*  input sint16 Lambda_feedback_min;                                         */
/*  output sint16 Moyenne_Lambda_feedback;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidMeanCalc(void)
{

   Moyenne_Lambda_feedback = (sint16)( ( Lambda_feedback_max
                                       + Lambda_feedback_min )
                                     / 2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLUSCTL_vidMeanFilt                                 */
/* !Description :  Filtration de la valeur moyenne du correcteur de richesse  */
/*                 de la régulation de richesse .                             */
/* !Number      :  FCT7.7                                                     */
/* !Author      :  BENNASR                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Reg_mean_filtered_factor;                                     */
/*  input sint32 INJFARCTLUSCTL_s32LamFeedCanMem;                             */
/*  input sint16 Moyenne_Lambda_feedback;                                     */
/*  input sint16 INJFARCTLUSCTL_s16LamFeedCanFilt;                            */
/*  output sint16 INJFARCTLUSCTL_s16LamFeedCanFilt;                           */
/*  output uint32 Lambda_feedback_can;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLUSCTL_vidMeanFilt(void)
{
   uint32  u32Local_Lambda_feedback_can;


   INJFARCTLUSCTL_s16LamFeedCanFilt =
      MATHSRV_s16FirstOrderFilterGu8(Reg_mean_filtered_factor,
                                     &INJFARCTLUSCTL_s32LamFeedCanMem,
                                     Moyenne_Lambda_feedback);
   u32Local_Lambda_feedback_can = (uint32)( INJFARCTLUSCTL_s16LamFeedCanFilt
                                          + 131072);
   VEMS_vidSET(Lambda_feedback_can, u32Local_Lambda_feedback_can);
}

/*------------------------------- end of file --------------------------------*/