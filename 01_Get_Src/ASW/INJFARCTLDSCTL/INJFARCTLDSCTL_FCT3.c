/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJFARCTLDSCTL                                          */
/* !Description     : INJFARCTLDSCTL Component                                */
/*                                                                            */
/* !Module          : INJFARCTLDSCTL                                          */
/* !Description     : REGULATION DE RICHESSE PAR LA SONDE A OXYGENE AVAL      */
/*                    (DOUBLE BOUCLE)                                         */
/*                                                                            */
/* !File            : INJFARCTLDSCTL_FCT3.C                                   */
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
/*   1 / INJFARCTLDSCTL_vidInitPurgeCata                                      */
/*   2 / INJFARCTLDSCTL_vidResetPurgeCata                                     */
/*   3 / INJFARCTLDSCTL_vidPurgeCata                                          */
/*   4 / INJFARCTLDSCTL_vidPurgeCataLow                                       */
/*   5 / INJFARCTLDSCTL_vidDecrLowCount                                       */
/*   6 / INJFARCTLDSCTL_vidPurgeCataRich                                      */
/*   7 / INJFARCTLDSCTL_vidDecrRichCount                                      */
/*   8 / INJFARCTLDSCTL_vidCalcErrTension                                     */
/*   9 / INJFARCTLDSCTL_vidCalcErrTenGain                                     */
/*   10 / INJFARCTLDSCTL_vidFeedbackCorr                                      */
/*                                                                            */
/* !Reference   : V02 NT 08 05886 / 09                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJ/INJCTL/INJFARCTLDSCTL/INJFARCT$*/
/* $Revision::   1.8      $$Author::   ACHEBINO       $$Date::   16 Jan 2012 $*/
/* $Author::   ACHEBINO                               $$Date::   16 Jan 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "INJFARCTLDSCTL.h"
#include "INJFARCTLDSCTL_L.h"
#include "INJFARCTLDSCTL_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidInitPurgeCata                            */
/* !Description :  spécifier les délais d’enrichissement et d’appauvrissement.*/
/* !Number      :  FCT3.1                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dnstr_time_in_low_volt_delay;                                */
/*  input uint16 Dnstr_time_in_high_volt_delay;                               */
/*  output uint16 Dnstr_time_in_low_volt_count;                               */
/*  output uint16 Dnstr_time_in_high_volt_count;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidInitPurgeCata(void)
{
   Dnstr_time_in_low_volt_count =
      (uint16)MATHSRV_udtMIN(Dnstr_time_in_low_volt_delay, 60000);
   Dnstr_time_in_high_volt_count =
      (uint16)MATHSRV_udtMIN(Dnstr_time_in_high_volt_delay, 60000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidResetPurgeCata                           */
/* !Description :  réinitialiser les délais d’enrichissement et               */
/*                 d’appauvrissement possible par la purge du catalyseur      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Dnstr_time_in_low_volt_count;                               */
/*  output uint16 Dnstr_time_in_high_volt_count;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidResetPurgeCata(void)
{
   Dnstr_time_in_low_volt_count  = 0;
   Dnstr_time_in_high_volt_count = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidPurgeCata                                */
/* !Description :  détermine les conditions et les paramètres de la purge     */
/*                 catalyseur pour les cas d’enrichissement et                */
/*                 d’appauvrissement.                                         */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_vidPurgeCataLow();                        */
/*  extf argret void INJFARCTLDSCTL_vidPurgeCataRich();                       */
/*  input boolean Dnstr_purge_cata_low;                                       */
/*  input boolean Dnstr_purge_cata_rich;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidPurgeCata(void)
{
   boolean bLocalDnstr_purge_cata_rich;
   boolean bLocalDnstr_purge_cata_low;


   VEMS_vidGET(Dnstr_purge_cata_low, bLocalDnstr_purge_cata_low);
   VEMS_vidGET(Dnstr_purge_cata_rich, bLocalDnstr_purge_cata_rich);

   if (bLocalDnstr_purge_cata_low != 0)
   {
      INJFARCTLDSCTL_vidPurgeCataLow();
   }
   if (bLocalDnstr_purge_cata_rich != 0)
   {
      INJFARCTLDSCTL_vidPurgeCataRich();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidPurgeCataLow                             */
/* !Description :  calcule le délai (en PMH)  avant de basculer la régulation */
/*                 de richesse vers un mélange riche. Ce calcul est réalisé   */
/*                 par l’intermédiaire d’une hystérésis.                      */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_vidDecrLowCount();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Dnstr_down_stream_ref_voltage;                               */
/*  input uint16 Dnstr_seuil_tension_av_bas_hyst;                             */
/*  input uint16 Dnstr_fenetre_activation_bas;                                */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Dnstr_time_in_low_volt_count;                                */
/*  input uint16 Dnstr_seuil_tension_aval_bas;                                */
/*  input uint16 Dnstr_retard_purge_riche;                                    */
/*  input uint16 Dnstr_retard_purge_riche_pas;                                */
/*  input uint16 Dnstr_retard_purge_riche_max;                                */
/*  input boolean INJFARCTLDSCTL_bHystOutputLow;                              */
/*  input uint16 Periode_moteur;                                              */
/*  output boolean Enable_decre_low_count;                                    */
/*  output uint16 Dnstr_retard_purge_riche;                                   */
/*  output uint16 Dnstr_retard_s_purge_riche;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidPurgeCataLow(void)
{
   uint16 u16LocalVal;
   uint16 u16LocalThr2;
   uint16 u16LocalPeriodeMoteur;
   uint16 u16LocalTensionSondeAval;
   uint16 u16LocalDnstrRetardPurgeRiche;
   uint32 u32LocalRtrdPurgeRiche;
   uint32 u32LocalThr2;
   sint32 s32Local;


   s32Local = (sint32)( ( Dnstr_down_stream_ref_voltage
                        + Dnstr_seuil_tension_av_bas_hyst)
                      - Dnstr_fenetre_activation_bas);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTensionSondeAval);

   if (  (u16LocalTensionSondeAval <= s32Local)
      && (Dnstr_time_in_low_volt_count != 0))
   {
      Enable_decre_low_count = 1;
      INJFARCTLDSCTL_vidDecrLowCount();
   }
   else
   {
      Enable_decre_low_count = 0;
   }

   u32LocalThr2 = (uint32)( Dnstr_seuil_tension_aval_bas
                          + Dnstr_seuil_tension_av_bas_hyst);
   u16LocalThr2 = (uint16)MATHSRV_udtMIN(u32LocalThr2, 65535);
   VEMS_vidGET(Dnstr_retard_purge_riche, u16LocalDnstrRetardPurgeRiche);
   u32LocalRtrdPurgeRiche = (uint32)( u16LocalDnstrRetardPurgeRiche
                                    + Dnstr_retard_purge_riche_pas);
   u16LocalVal = (uint16)MATHSRV_udtMIN(u32LocalRtrdPurgeRiche,
                                        Dnstr_retard_purge_riche_max);

   MATHSRV_vidSchmittTriggerU16( u16LocalTensionSondeAval,
                                 Dnstr_seuil_tension_aval_bas,
                                 (u16LocalThr2),
                                 MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &INJFARCTLDSCTL_bHystOutputLow);

   if (INJFARCTLDSCTL_bHystOutputLow != 0)
   {
      VEMS_vidSET(Dnstr_retard_purge_riche, u16LocalVal);
   }
   else
   {
      VEMS_vidSET(Dnstr_retard_purge_riche, 0);
   }

   VEMS_vidGET(Periode_moteur, u16LocalPeriodeMoteur);
   VEMS_vidGET(Dnstr_retard_purge_riche, u16LocalDnstrRetardPurgeRiche);
   if (  (u16LocalDnstrRetardPurgeRiche == 0)
      || (u16LocalPeriodeMoteur == 0))
   {
      Dnstr_retard_s_purge_riche = 0;
   }
   else
   {
      Dnstr_retard_s_purge_riche =
         (uint16)( (uint32)( u16LocalPeriodeMoteur
                           * u16LocalDnstrRetardPurgeRiche)
                 / 800000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidDecrLowCount                             */
/* !Description :  La décrémentation du temps restant d'appauvrissement       */
/*                 possible par la pu InjCtl_SampleTiFast_SC.                 */
/*                 Dnstr_purge_cata_done_wo_result indique la fin de la purge */
/*                 catalyseur                                                 */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dnstr_time_in_low_volt_count;                                */
/*  output uint16 Dnstr_time_in_low_volt_count;                               */
/*  output boolean Dnstr_purge_cata_done_wo_result;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidDecrLowCount(void)
{

   if (Dnstr_time_in_low_volt_count > 1)
   {
      Dnstr_time_in_low_volt_count =
                                 (uint16)(Dnstr_time_in_low_volt_count - 1);
      Dnstr_purge_cata_done_wo_result = 0;
   }
   else
   {
      Dnstr_time_in_low_volt_count = 0;
      Dnstr_purge_cata_done_wo_result = 1;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidPurgeCataRich                            */
/* !Description :  calcule le délai (en PMH)  avant de basculer la régulation */
/*                 de richesse vers un mélange pauvre. Ce calcul est réalisé  */
/*                 par l’intermédiaire d’une hystérésis.                      */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJFARCTLDSCTL_vidDecrRichCount();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Dnstr_down_stream_ref_voltage;                               */
/*  input uint16 Dnstr_fenetre_activation_haut;                               */
/*  input uint16 Dnstr_seuil_tension_av_haut_hyst;                            */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Dnstr_time_in_high_volt_count;                               */
/*  input uint16 Dnstr_seuil_tension_aval_haut;                               */
/*  input uint16 Dnstr_retard_purge_pauvre;                                   */
/*  input uint16 Dnstr_retard_purge_pauvre_pas;                               */
/*  input uint16 Dnstr_retard_purge_pauvre_max;                               */
/*  input boolean INJFARCTLDSCTL_bHystOutputRich;                             */
/*  input uint16 Periode_moteur;                                              */
/*  output boolean Enable_decre_rich_count;                                   */
/*  output uint16 Dnstr_retard_purge_pauvre;                                  */
/*  output uint16 Dnstr_retard_s_purge_pauvre;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidPurgeCataRich(void)
{
   uint16 u16LocalVal2;
   uint16 u16LocalThr1;
   uint16 u16LocalPeriodeMoteur;
   uint16 u16LocalTensionSondeAval;
   uint16 u16LocalDnstrRetardPurgePauvre;
   uint32 u32LocalVal2;
   uint32 u32Local;
   sint32 s32Local;
   sint32 s32LocalThr1;


   s32Local = (sint32)( ( Dnstr_down_stream_ref_voltage
                        + Dnstr_fenetre_activation_haut)
                      - Dnstr_seuil_tension_av_haut_hyst);
   u32Local = (uint32)MATHSRV_udtMAX(s32Local, 0);
   VEMS_vidGET(Tension_sonde_aval, u16LocalTensionSondeAval);

   if (  (u16LocalTensionSondeAval >= u32Local)
      && (Dnstr_time_in_high_volt_count != 0))
   {
      Enable_decre_rich_count = 1;
      INJFARCTLDSCTL_vidDecrRichCount();
   }
   else
   {
      Enable_decre_rich_count = 0;
   }

   s32LocalThr1 = (sint32)( Dnstr_seuil_tension_aval_haut
                          - Dnstr_seuil_tension_av_haut_hyst);
   u16LocalThr1 = (uint16)MATHSRV_udtMAX(s32LocalThr1, 0);
   VEMS_vidGET(Dnstr_retard_purge_pauvre, u16LocalDnstrRetardPurgePauvre);
   u32LocalVal2 = ( u16LocalDnstrRetardPurgePauvre
                  + Dnstr_retard_purge_pauvre_pas);
   u16LocalVal2 =
            (uint16)MATHSRV_udtMIN(u32LocalVal2,
                                   Dnstr_retard_purge_pauvre_max);

   MATHSRV_vidSchmittTriggerU16( u16LocalTensionSondeAval,
                                 u16LocalThr1,
                                 Dnstr_seuil_tension_aval_haut,
                                 MATHSRV_RISING_SCHMITT_TRIGGER,
                                &INJFARCTLDSCTL_bHystOutputRich);

   if (INJFARCTLDSCTL_bHystOutputRich != 0)
   {
      VEMS_vidSET(Dnstr_retard_purge_pauvre, u16LocalVal2);
   }
   else
   {
      VEMS_vidSET(Dnstr_retard_purge_pauvre, 0);
   }

   VEMS_vidGET(Periode_moteur, u16LocalPeriodeMoteur);
   VEMS_vidGET(Dnstr_retard_purge_pauvre, u16LocalDnstrRetardPurgePauvre);
   if (  (u16LocalDnstrRetardPurgePauvre == 0)
      || (u16LocalPeriodeMoteur == 0))
   {
      Dnstr_retard_s_purge_pauvre = 0;
   }
   else
   {
      Dnstr_retard_s_purge_pauvre =
         (uint16)( (uint32)( u16LocalPeriodeMoteur
                           * u16LocalDnstrRetardPurgePauvre)
                 / 800000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidDecrRichCount                            */
/* !Description :  La décrémentation du temps restant d'enrichissement        */
/*                 possible par la purge cata est réalisé à la valeur du pas  */
/*                 InjCtl_SampleTiFast_SC.  Dnstr_purge_cata_done_wo_result   */
/*                 indique la fin de la purge catalyseur                      */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Dnstr_time_in_high_volt_count;                               */
/*  output uint16 Dnstr_time_in_high_volt_count;                              */
/*  output boolean Dnstr_purge_cata_done_wo_result;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidDecrRichCount(void)
{

   if ( Dnstr_time_in_high_volt_count > 1)
   {
      Dnstr_time_in_high_volt_count =
                                 (uint16)(Dnstr_time_in_high_volt_count - 1);
      Dnstr_purge_cata_done_wo_result = 0;
   }
   else
   {
      Dnstr_time_in_high_volt_count = 0;
      Dnstr_purge_cata_done_wo_result = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidCalcErrTension                           */
/* !Description :  L’erreur de tension sur la sonde aval est calculée par la  */
/*                 différence entre l’Erreur entre la tension sonde et la     */
/*                 tension de référence et la dernière tension différentielle */
/*                 correcte.                                                  */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  GANNOUN                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Dnstr_down_stream_ref_voltage;                               */
/*  output uint16 Dnstr_err_tension;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidCalcErrTension(void)
{
   uint16 u16LocalTensionSondeAval;
   sint32 s32LocalDnstrErrTen;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTensionSondeAval);
   s32LocalDnstrErrTen = (sint32)(((Dnstr_down_stream_ref_voltage
                                   - u16LocalTensionSondeAval) + 1024));
   Dnstr_err_tension = (uint16)MATHSRV_udtCLAMP(s32LocalDnstrErrTen, 0, 2047);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidCalcErrTenGain                           */
/* !Description :  calculer la tension de référence de la sonde aval          */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_08_05886_001.02                                     */
/*                 VEMS_R_08_05886_002.02                                     */
/*                 VEMS_R_08_05886_003.02                                     */
/*                 VEMS_R_08_05886_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Test_bed_tension_cns_sonde_aval;                            */
/*  input uint16 Dnstr_down_stream_ref_voltage_c;                             */
/*  input uint16 Engine_load;                                                 */
/*  input uint16 Engine_load_2_bkpt_map[9];                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 Dnstr_dwn_strm_ref_volt_neuf_map[9][9];                      */
/*  input uint16 Dnstr_dwn_strm_ref_volt_emis_map[9][9];                      */
/*  input uint8 Cat_old_gain;                                                 */
/*  input sint8 Delta_sonde_aval_gaz;                                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Manu_inh_delta_sonde_aval_gaz;                              */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input uint16 EngM_mfTotExCor_bkpt_map[9];                                 */
/*  input uint16 Dnstr_pro_gain_map[9];                                       */
/*  input uint16 Dnstr_int_gain_map[9];                                       */
/*  input uint16 Dnstr_err_tension_gain_bkpt_map[9];                          */
/*  input uint16 Dnstr_err_tension;                                           */
/*  input uint8 Dnstr_err_tension_pro_gain_map[9];                            */
/*  input uint8 Dnstr_err_tension_int_gain_map[9];                            */
/*  input uint8 Dnstr_err_tension_pro_gain;                                   */
/*  input uint8 Dnstr_err_tension_int_gain;                                   */
/*  output uint16 Dnstr_down_stream_ref_voltage;                              */
/*  output uint8 Dnstr_err_tension_pro_gain;                                  */
/*  output uint8 Dnstr_err_tension_int_gain;                                  */
/*  output uint16 Dnstr_pro_gain;                                             */
/*  output uint16 Dnstr_int_gain;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidCalcErrTenGain(void)
{
   /* 02_Calc_err_tension_gain */
   uint8  u8LocalCatOldGain;
   uint8  u8LocalRegimeMoteur32;
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalEmisinterp;
   uint16 u16LocalRefVoltageFuel;
   uint16 u16LocalNeufinterp;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalMfrParaX;
   uint16 u16LocalIntMfrinterp;
   uint16 u16LocalProMfrinterp;
   uint16 u16LocalErrParaX;
   uint16 u16LocalEngMmfTotExCor;
   uint16 u16LocalEngineLoad;
   uint32 u32LocalProGain;
   uint32 u32LocalIntGain;
   sint8  s8LocalDelta_sonde_aval_gaz;
   sint32 s32LocalRefVoltageGas;


   if (Test_bed_tension_cns_sonde_aval != 0)
   {
      Dnstr_down_stream_ref_voltage =
            (uint16)MATHSRV_udtMIN(Dnstr_down_stream_ref_voltage_c, 1023);
   }
   else
   {
      VEMS_vidGET(Engine_load, u16LocalEngineLoad);
      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Engine_load_2_bkpt_map,
                                                   u16LocalEngineLoad, 9);

      VEMS_vidGET(Regime_moteur_32, u8LocalRegimeMoteur32);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                                  u8LocalRegimeMoteur32, 9);

      u16LocalNeufinterp =
         MATHSRV_u16Interp2d(&Dnstr_dwn_strm_ref_volt_neuf_map[0][0],
                            u16LocalParaX, u16LocalParaY, 9);

      u16LocalEmisinterp =
         MATHSRV_u16Interp2d(&Dnstr_dwn_strm_ref_volt_emis_map[0][0],
                            u16LocalParaX, u16LocalParaY, 9);

      VEMS_vidGET(Cat_old_gain, u8LocalCatOldGain);
      u16LocalRefVoltageFuel = (uint16)( ( (u16LocalNeufinterp
                                           * u8LocalCatOldGain)
                                       + ( (256 - u8LocalCatOldGain)
                                         * u16LocalEmisinterp))
                                     / 256);
      VEMS_vidGET(Delta_sonde_aval_gaz, s8LocalDelta_sonde_aval_gaz);
      VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

      if (  (u8LocalExt_stSysGas == Ext_stGasMod_SC)
         && (Manu_inh_delta_sonde_aval_gaz == 0))
      {
         s32LocalRefVoltageGas = (sint32)( u16LocalRefVoltageFuel
                                         + (s8LocalDelta_sonde_aval_gaz * 2));
         Dnstr_down_stream_ref_voltage =
            (uint16)MATHSRV_udtCLAMP(s32LocalRefVoltageGas, 0, 1023);
      }
      else
      {
         Dnstr_down_stream_ref_voltage = u16LocalRefVoltageFuel;
      }
   }

   VEMS_vidGET(EngM_mfTotExCor, u16LocalEngMmfTotExCor);
   u16LocalMfrParaX = MATHSRV_u16CalcParaIncAryU16(EngM_mfTotExCor_bkpt_map,
                                                   u16LocalEngMmfTotExCor,9);

   u16LocalProMfrinterp = MATHSRV_u16Interp1d(Dnstr_pro_gain_map,
                                              u16LocalMfrParaX);

   u16LocalIntMfrinterp = MATHSRV_u16Interp1d(Dnstr_int_gain_map,
                                              u16LocalMfrParaX);

   u16LocalErrParaX =
      MATHSRV_u16CalcParaIncAryU16(Dnstr_err_tension_gain_bkpt_map,
                                  Dnstr_err_tension, 9);

   Dnstr_err_tension_pro_gain =
      MATHSRV_u8Interp1d(Dnstr_err_tension_pro_gain_map, u16LocalErrParaX);

   Dnstr_err_tension_int_gain =
      MATHSRV_u8Interp1d(Dnstr_err_tension_int_gain_map, u16LocalErrParaX);

   u32LocalProGain = (uint32)( ( u16LocalProMfrinterp
                               * Dnstr_err_tension_pro_gain)
                             / 128);
   Dnstr_pro_gain = (uint16)MATHSRV_udtMIN(u32LocalProGain, 65535);

   u32LocalIntGain = (uint32)( ( u16LocalIntMfrinterp
                               * Dnstr_err_tension_int_gain)
                             / 128);
   Dnstr_int_gain = (uint16)MATHSRV_udtMIN(u32LocalIntGain, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJFARCTLDSCTL_vidFeedbackCorr                             */
/* !Description :  calculer les paramètres de correction                      */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  GANNOUN                                                    */
/* !Trace_To    :  VEMS_R_08_05886_004.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Dnstr_err_tension;                                           */
/*  input uint16 Dnstr_pro_gain;                                              */
/*  input boolean Manu_inh_reset_dnstr_int;                                   */
/*  input uint16 Dnstr_err_tension_prec;                                      */
/*  input uint16 Dnstr_int_gain;                                              */
/*  input sint16 Feedback_correction_int;                                     */
/*  input uint16 Fb_correction_int_min;                                       */
/*  input uint16 Fb_correction_int_max;                                       */
/*  input boolean Test_bed_pi_feedback_correction;                            */
/*  input sint16 Feedback_correction_c;                                       */
/*  input sint16 Feedback_correction_pro;                                     */
/*  input uint16 Fb_corr_min_lim_c;                                           */
/*  input uint16 Fb_corr_max_lim_c;                                           */
/*  output sint16 Feedback_correction_pro;                                    */
/*  output sint16 Feedback_correction_int;                                    */
/*  output sint16 Feedback_correction;                                        */
/*  output uint16 Dnstr_err_tension_prec;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJFARCTLDSCTL_vidFeedbackCorr(void)
{
   uint16 u16LocalPro;
   uint32 u32LocalPro;
   uint32 u32LocalPro1;
   uint32 u32LocalInit;
   uint32 u32LocalInit1;
   sint16 s16LocalFeedbackcorrection;
   sint16 s16FeedbackcorrectionInit;
   sint32 s32LocalFeedbackInt;
   sint32 s32LocalFdbackInt;
   sint32 s32LocalFeedbackcorr;
   sint32 s32LocalFb_correction_int_min;
   sint32 s32LocalFb_corr_min_lim_c;
   sint32 s32LocalPro;
   sint32 s32LocalInit;


   u16LocalPro = (uint16)MATHSRV_udtABS(Dnstr_err_tension - 1024);
   u32LocalPro = (uint32)((u16LocalPro * Dnstr_pro_gain) / 256) ;
   u32LocalPro1 = ((u32LocalPro * 5) / 4);

   if (Dnstr_err_tension < 1024)
   {
      s32LocalPro = (sint32)(u32LocalPro1 * (-1));
      Feedback_correction_pro = (sint16)MATHSRV_udtMAX(s32LocalPro, -32768);
      /*QAC Msg(3:3355) The result of this logical operation is always 'true'*/
   }
   else
   {
      Feedback_correction_pro = (sint16)MATHSRV_udtMIN(u32LocalPro1,32767);
   }

   if (  (Manu_inh_reset_dnstr_int == 0)
         && ( (  (Dnstr_err_tension > 1024) && (Dnstr_err_tension_prec <= 1024))
              || ((Dnstr_err_tension <= 1024) && (Dnstr_err_tension_prec
                                                 > 1024))
            )
         )
   {
      Feedback_correction_int = 0;
   }
   else
   {
      u32LocalInit = (uint32)((u16LocalPro * Dnstr_int_gain) / 256) ;
      u32LocalInit1 = ((u32LocalInit * 5) / 4);

      if (Dnstr_err_tension < 1024)
      {
         s32LocalInit = (sint32)(u32LocalInit1 * (-1));
         s16FeedbackcorrectionInit =
            (sint16)MATHSRV_udtMAX(s32LocalInit, -32768);
      /*QAC Msg(3:3355) The result of this logical operation is always 'true'*/
      }
      else
      {
         s16FeedbackcorrectionInit =
            (sint16)MATHSRV_udtMIN(u32LocalInit1,32767);
      }
      s32LocalFdbackInt = (sint32)(Feedback_correction_int
                                  + s16FeedbackcorrectionInit);
      s32LocalFb_correction_int_min = (sint32)(-1 * Fb_correction_int_min);
      s32LocalFeedbackInt =
                  MATHSRV_udtCLAMP(s32LocalFdbackInt,
                                  s32LocalFb_correction_int_min,
                                  (sint32)Fb_correction_int_max);
      Feedback_correction_int =
               (sint16)MATHSRV_udtCLAMP(s32LocalFeedbackInt, -32768, 32767);
   }

   if (Test_bed_pi_feedback_correction != 0)
   {
      s32LocalFeedbackcorr = Feedback_correction_c;
   }
   else
   {

      s32LocalFeedbackcorr = (sint32)( Feedback_correction_pro
                                     + Feedback_correction_int);
   }
   s32LocalFb_corr_min_lim_c = (sint32)(-1 * Fb_corr_min_lim_c);
   s32LocalFeedbackcorr = MATHSRV_udtCLAMP(s32LocalFeedbackcorr,
                                          s32LocalFb_corr_min_lim_c,
                                          (sint32)Fb_corr_max_lim_c);

   s16LocalFeedbackcorrection =
     (sint16)MATHSRV_udtCLAMP(s32LocalFeedbackcorr, -32768, 32767);

   VEMS_vidSET(Feedback_correction, s16LocalFeedbackcorrection);
   Dnstr_err_tension_prec =
      (uint16)MATHSRV_udtMIN(Dnstr_err_tension, 2047);
}

/*------------------------------- end of file --------------------------------*/