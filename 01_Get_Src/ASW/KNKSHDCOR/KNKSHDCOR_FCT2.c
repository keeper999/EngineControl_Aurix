/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKSHDCOR                                               */
/* !Description     : KNKSHDCOR Component                                     */
/*                                                                            */
/* !Module          : KNKSHDCOR                                               */
/* !Description     : Correction palliative de cliquetis                      */
/*                                                                            */
/* !File            : KNKSHDCOR_FCT2.C                                        */
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
/*   1 / KNKSHDCOR_vidCorr_init                                               */
/*   2 / KNKSHDCOR_vidReset_win                                               */
/*   3 / KNKSHDCOR_vidCorr_enable                                             */
/*   4 / KNKSHDCOR_vidCorr_inc                                                */
/*   5 / KNKSHDCOR_vidKnk_inc_stop                                            */
/*   6 / KNKSHDCOR_vidCorr_dec                                                */
/*   7 / KNKSHDCOR_vidComp_corr_dec                                           */
/*                                                                            */
/* !Reference: V02 NT 08 07294 / 03                                           */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKSHDCOR/KNKSHDCOR_FCT2.C_v$*/
/* $Revision::   1.2      $$Author::   vgarnier       $$Date::   25 Mar 2010 $*/
/* $Author::   vgarnier                               $$Date::   25 Mar 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "KNKSHDCOR.H"
#include "KNKSHDCOR_L.H"
#include "KNKSHDCOR_IM.H"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_init                                      */
/* !Description : Lorsque le compteur de "coups de cliquetis" dépasse une     */
/*                valeur calibrable, on active la correction palliative de    */
/*                cliquetis et on remet à zéro des paramètres de la détection.*/
/* !Number      : FCT2.1                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   input uint8 Knk_deg_app_count_eep;                                       */
/*   output boolean knk_corr_inc_uavb0;                                       */
/*   output uint8 Knk_deg_det_count_uavn1[4];                                 */
/*   output uint8 Knk_deg_obs_win_uavn1[4];                                   */
/*   output uint8 Knk_deg_app_count_eep;                                      */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_init(void)
{
   uint8 u8LocalCounter;


   knk_corr_inc_uavb0 = 1;
   for (u8LocalCounter = 0; u8LocalCounter < 4; u8LocalCounter++)
   {
      Knk_deg_det_count_uavn1[u8LocalCounter] = 0;
      Knk_deg_obs_win_uavn1[u8LocalCounter] = 0;
   }
   if (Knk_deg_app_count_eep < 255)
   {
      Knk_deg_app_count_eep = (uint8)(Knk_deg_app_count_eep + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidReset_win                                      */
/* !Description : Lorsqu’une fenêtre se termine, on remet à zero le compteur  */
/*                de "coups de cliquetis".                                    */
/* !Number      : FCT2.2                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void SWFAIL_vidSoftwareErrorHook();                          */
/*   input uint8 Eng_noCmprCyl;                                               */
/*   output uint8 Knk_deg_det_count_uavn1[4];                                 */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidReset_win(void)
{
   uint8 u8LocalEng_noCmprCyl;


   VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   switch(u8LocalEng_noCmprCyl)
   {
      case 1:
      case 2:
      case 3:
      case 4:
         u8LocalEng_noCmprCyl = (uint8)(u8LocalEng_noCmprCyl - 1);

         Knk_deg_det_count_uavn1[u8LocalEng_noCmprCyl] = 0;
         break;

      case 5:
      case 6:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_enable                                    */
/* !Description : Lorsque la correction est de nouveau autorisée (changement  */
/*                de rapport effectué), on filtre celle-ci vers sa dernière   */
/*                valeur avec un filtre de coefficient                        */
/*                Knk_deg_cor_in_filt_uacn0.                                  */
/* !Number      : FCT2.3                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint8 Knk_deg_cor_uavn0;                                           */
/*   input uint8 Knk_deg_cor_av_filt_uavn0;                                   */
/*   input uint8 Knk_deg_cor_in_filt_uacn0;                                   */
/*   output uint8 Knk_deg_cor_uavn0;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_enable(void)
{
   uint8  u8LocalKnk_deg_cor_uavn0;
   sint16 s16LocalDiff;
   sint16 s16LocalDiv;
   sint32 s32LocalProd;


   VEMS_vidGET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);
   s16LocalDiff = (sint16)(Knk_deg_cor_av_filt_uavn0 -
                           u8LocalKnk_deg_cor_uavn0);
   s32LocalProd = (sint32)(s16LocalDiff * Knk_deg_cor_in_filt_uacn0);
   s16LocalDiv = (sint16)(s32LocalProd / 256);
   s16LocalDiv = (sint16)(s16LocalDiv + u8LocalKnk_deg_cor_uavn0);
   u8LocalKnk_deg_cor_uavn0 = (uint8)s16LocalDiv;
   VEMS_vidSET(Knk_deg_cor_uavn0, u8LocalKnk_deg_cor_uavn0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_inc                                       */
/* !Description : La correction s’incrémente de la valeur de                  */
/*                Knk_deg_cor_inc_uacn0 tous les PMB jusqu’à atteindre        */
/*                Knk_deg_cor_offset_uacn0.                                   */
/* !Number      : FCT2.4                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void KNKSHDCOR_vidKnk_inc_stop();                            */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint8 Knk_deg_cor_av_filt_uavn0;                                   */
/*   input uint8 Knk_deg_cor_inc_uacn0;                                       */
/*   input uint8 Knk_deg_cor_offset_uacn0;                                    */
/*   output uint8 Knk_deg_cor_av_filt_uavn0;                                  */
/*   output uint8 Knk_deg_cor_uavn0;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_inc(void)
{
   uint16 u16LocalSum;


   u16LocalSum = (uint16)(Knk_deg_cor_av_filt_uavn0 + Knk_deg_cor_inc_uacn0);
   if (u16LocalSum < Knk_deg_cor_offset_uacn0)
   {
      Knk_deg_cor_av_filt_uavn0 = (uint8)u16LocalSum;
   }
   else
   {
      Knk_deg_cor_av_filt_uavn0 = Knk_deg_cor_offset_uacn0;
      KNKSHDCOR_vidKnk_inc_stop();
   }

   VEMS_vidSET(Knk_deg_cor_uavn0, Knk_deg_cor_av_filt_uavn0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidKnk_inc_stop                                   */
/* !Description : Une fois la correction d’avance Knk_deg_cor_offset_uacn0    */
/*                atteinte, on initialise le délai de maintien.               */
/* !Number      : FCT2.5                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   input uint16 Regime_moteur;                                              */
/*   input uint16 Regime_moteur_bkpt_map[16];                                 */
/*   input uint16 Knk_deg_cor_delay_uacn1[16];                                */
/*   output boolean knk_corr_inc_uavb0;                                       */
/*   output uint16 Knk_deg_cor_tempo_uavn0;                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidKnk_inc_stop(void)
{
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalPara;
   uint32 u32LocalRegime_moteur;


   knk_corr_inc_uavb0 = 0;
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u32LocalRegime_moteur = (uint32)(u16LocalRegime_moteur * 8);
   u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u32LocalRegime_moteur, 65535);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                               u16LocalRegime_moteur,
                                               16);
   Knk_deg_cor_tempo_uavn0 = MATHSRV_u16Interp1d(Knk_deg_cor_delay_uacn1,
                                                 u16LocalPara);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidCorr_dec                                       */
/* !Description : Une fois le délai de maintien écoulé, on commence à         */
/*                décrémenter la correction d’avance anti-cliquetis. La       */
/*                décrémentation Knk_deg_cor_dec_uacn0 est alors appliquée    */
/*                avec un délai entre chaque application.                     */
/* !Number      : FCT2.6                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf argret void KNKSHDCOR_vidComp_corr_dec();                           */
/*   input uint16 Knk_deg_cor_tempo_uavn0;                                    */
/*   output uint16 Knk_deg_cor_tempo_uavn0;                                   */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidCorr_dec(void)
{
   sint32 s32LocalDiff;


   s32LocalDiff = (sint32)(Knk_deg_cor_tempo_uavn0 - 1);
   Knk_deg_cor_tempo_uavn0 = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
   if (Knk_deg_cor_tempo_uavn0 == 0)
   {
      KNKSHDCOR_vidComp_corr_dec();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    : KNKSHDCOR_vidComp_corr_dec                                  */
/* !Description : Tous les Knk_deg_cor_dec_delay_uacn1 PMH, on décrémente la  */
/*                correction de Knk_deg_cor_dec_uacn0 °Vil.                   */
/* !Number      : FCT2.7                                                      */
/* !Author      : N.ABID                                                      */
/*                                                                            */
/******************************************************************************/
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*   input uint16 Regime_moteur;                                              */
/*   input uint16 Regime_moteur_bkpt_map[16];                                 */
/*   input uint16 Knk_deg_cor_dec_delay_uacn1[16];                            */
/*   input uint8 Knk_deg_cor_av_filt_uavn0;                                   */
/*   input uint8 Knk_deg_cor_dec_uacn0;                                       */
/*   output uint16 Knk_deg_cor_tempo_uavn0;                                   */
/*   output uint8 Knk_deg_cor_av_filt_uavn0;                                  */
/*   output uint8 Knk_deg_cor_uavn0;                                          */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKSHDCOR_vidComp_corr_dec(void)
{
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalPara;
   sint16 s16LocalDiff;
   uint32 u32LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u32LocalRegime_moteur = (uint32)(u16LocalRegime_moteur * 8);
   u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u32LocalRegime_moteur, 65535);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Regime_moteur_bkpt_map,
                                               u16LocalRegime_moteur,
                                               16);
   Knk_deg_cor_tempo_uavn0 = MATHSRV_u16Interp1d(Knk_deg_cor_dec_delay_uacn1,
                                                 u16LocalPara);

   s16LocalDiff = (sint16)(Knk_deg_cor_av_filt_uavn0 - Knk_deg_cor_dec_uacn0);
   Knk_deg_cor_av_filt_uavn0 = (uint8)MATHSRV_udtMAX(s16LocalDiff, 0);

   VEMS_vidSET(Knk_deg_cor_uavn0, Knk_deg_cor_av_filt_uavn0);
}
/*------------------------------- end of file --------------------------------*/