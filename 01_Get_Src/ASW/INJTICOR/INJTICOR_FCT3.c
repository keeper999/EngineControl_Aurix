/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJTICOR                                                */
/* !Description     : INJTICOR component                                      */
/*                                                                            */
/* !Module          : INJTICOR                                                */
/* !Description     : CORRECTION DE LA RÉGULATION DE RICHESSE EN BUTÉE        */
/*                                                                            */
/* !File            : INJTICOR_FCT3.C                                         */
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
/*   1 / INJTICOR_vidFuelAdjustment                                           */
/*   2 / INJTICOR_vidSwitchRichCalc                                           */
/*   3 / INJTICOR_vidInjTimeCorSwitchRich                                     */
/*   4 / INJTICOR_vidSwitchLeanCalc                                           */
/*   5 / INJTICOR_vidInjTimeCorSwitchLean                                     */
/*   6 / INJTICOR_vidWaitAbortFuelCheck                                       */
/*   7 / INJTICOR_vidEndOfDlyPeriodCntMgr                                     */
/*   8 / INJTICOR_vidEndOfDlyPeriodCntDec                                     */
/*   9 / INJTICOR_vidClampDiagnosis                                           */
/*   10 / INJTICOR_vidOnEnrichClampDiag                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_FCT3.C_v        $*/
/* $Revision::   1.15     $$Author::   achebino       $$Date::   20 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INJTICOR.h"
#include "INJTICOR_L.h"
#include "INJTICOR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidFuelAdjustment                                 */
/* !Description :  Ajustement de carburant                                    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidSwitchRichCalc();                            */
/*  extf argret void INJTICOR_vidSwitchLeanCalc();                            */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Lfbk_clamp_test_time_gas_c;                                  */
/*  input uint16 Lfbk_clamp_test_time_c;                                      */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*  output uint16 Lfbk_clamp_corr_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidFuelAdjustment(void)
{
   /*01_fuel_adjustment*/
   boolean bLocalLfbk_on_enrich_clamp;
   uint8   u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Lfbk_clamp_corr_count =
         (uint16)MATHSRV_udtMIN(Lfbk_clamp_test_time_gas_c, 324);
   }
   else
   {
      Lfbk_clamp_corr_count =
         (uint16)MATHSRV_udtMIN(Lfbk_clamp_test_time_c, 324);
   }

   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbk_on_enrich_clamp);

   if (bLocalLfbk_on_enrich_clamp != 0)
   {
      /*01_SwitchRich_calculations*/
      INJTICOR_vidSwitchRichCalc();
   }
   else
   {
      /*02_SwitchLean_calculations*/
      INJTICOR_vidSwitchLeanCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSwitchRichCalc                                 */
/* !Description :  La correction sur la chaîne d'injection Diag_trim est      */
/*                 incrémentée d'un pas de Lfbk_enrich_extra_c jusqu'au seuil */
/*                 Lfbk_enrich_max_c, où le booléen de défaillance            */
/*                 Inj_bDgoStuckLfbk_SwitchRich passe à 1.                    */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidInjTimeCorSwitchRich();                      */
/*  input sint8 Diag_trim;                                                    */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Lfbk_enrich_extra_gas_c;                                      */
/*  input uint8 Lfbk_enrich_max_gas_c;                                        */
/*  input uint8 Lfbk_enrich_extra_c;                                          */
/*  input uint8 Lfbk_enrich_max_c;                                            */
/*  output boolean Lfbk_switch_rich;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSwitchRichCalc(void)
{
   /*01_SwitchRich_calculations*/
   uint8  u8LocalExt_stSysGas;
   uint8  u8Localextra;
   uint8  u8Localmax;
   sint8  s8LocalDiag_trim;
   sint16 s16LocalDiagTrimLfbkEnrich;


   VEMS_vidGET(Diag_trim, s8LocalDiag_trim);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8Localextra = Lfbk_enrich_extra_gas_c;
      u8Localmax = Lfbk_enrich_max_gas_c;
   }
   else
   {
      u8Localextra = Lfbk_enrich_extra_c;
      u8Localmax = Lfbk_enrich_max_c;
   }
   s16LocalDiagTrimLfbkEnrich = (sint16)(s8LocalDiag_trim + u8Localextra);

   if (s16LocalDiagTrimLfbkEnrich > (sint16)u8Localmax)
   {
      Lfbk_switch_rich = 1;
   }
   else
   {
      Lfbk_switch_rich = 0;
      /*01_injection_time_correction_SwitchRich*/
      INJTICOR_vidInjTimeCorSwitchRich();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInjTimeCorSwitchRich                           */
/* !Description :  Cette fonction permet d'incrémenter Diag_trim.             */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 Diag_trim;                                                    */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Lfbk_enrich_extra_gas_c;                                      */
/*  input uint8 Lfbk_enrich_extra_c;                                          */
/*  output sint8 Diag_trim;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInjTimeCorSwitchRich(void)
{
   /*01_injection_time_correction_SwitchRich*/
   uint8  u8LocalExt_stSysGas;
   uint8  u8Localextra;
   sint8  s8LocalDiag_trim;
   sint16 s16LocalDiagTrimEnrich;


   VEMS_vidGET(Diag_trim, s8LocalDiag_trim);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8Localextra = Lfbk_enrich_extra_gas_c;
   }
   else
   {
      u8Localextra = Lfbk_enrich_extra_c;
   }
   s16LocalDiagTrimEnrich = (sint16)( s8LocalDiag_trim + u8Localextra);
   s8LocalDiag_trim = (sint8)MATHSRV_udtMIN(s16LocalDiagTrimEnrich, 127);
   VEMS_vidSET(Diag_trim, s8LocalDiag_trim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSwitchLeanCalc                                 */
/* !Description :  La correction sur la chaîne d'injection Diag_trim est      */
/*                 décrémentée d'un pas de Lfbk_enlean_extra_c jusqu'au seuil */
/*                 Lfbk_enlean_max_c, où le booléen de défaillance            */
/*                 Inj_bDgoStuckLfbk_SwitchLean passe à 1.                    */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidInjTimeCorSwitchLean();                      */
/*  input sint8 Diag_trim;                                                    */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Lfbk_enlean_extra_gas_c;                                      */
/*  input uint8 Lfbk_enlean_max_gas_c;                                        */
/*  input uint8 Lfbk_enlean_extra_c;                                          */
/*  input uint8 Lfbk_enlean_max_c;                                            */
/*  output boolean Lfbk_switch_lean;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSwitchLeanCalc(void)
{
   /*02_SwitchLean_calculations*/
   uint8  u8LocalExt_stSysGas;
   uint8  u8Localextra;
   uint8  u8Localmax;
   sint8  s8LocalDiag_trim;
   uint16 u16LocalDiagTrimLfbkEnlean;
   sint16 s16LocalDiagTrimLfbkEnlean;


   VEMS_vidGET(Diag_trim, s8LocalDiag_trim);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8Localextra = Lfbk_enlean_extra_gas_c;
      u8Localmax = Lfbk_enlean_max_gas_c;
   }
   else
   {
      u8Localextra = Lfbk_enlean_extra_c;
      u8Localmax = Lfbk_enlean_max_c;
   }

   s16LocalDiagTrimLfbkEnlean = (sint16)(s8LocalDiag_trim - u8Localextra);
   u16LocalDiagTrimLfbkEnlean =
      (uint16)MATHSRV_udtABS(s16LocalDiagTrimLfbkEnlean);

   if (u16LocalDiagTrimLfbkEnlean > (uint16)u8Localmax)
   {
      Lfbk_switch_lean = 1;
   }
   else
   {
      Lfbk_switch_lean = 0;
      /*01_injection_time_correction_SwitchLean*/
      INJTICOR_vidInjTimeCorSwitchLean();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidInjTimeCorSwitchLean                           */
/* !Description :  Cette fonction permet de décrémenter Diag_trim.            */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input sint8 Diag_trim;                                                    */
/*  input uint8 Lfbk_enlean_extra_gas_c;                                      */
/*  input uint8 Lfbk_enlean_extra_c;                                          */
/*  output sint8 Diag_trim;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidInjTimeCorSwitchLean(void)
{
   /*01_injection_time_correction_SwitchLean*/
   uint8  u8LocalExt_stSysGas;
   sint8  s8LocalDiag_trim;
   sint16 s16LocalDiagTrimEnlean;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Diag_trim, s8LocalDiag_trim);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      s16LocalDiagTrimEnlean = (sint16)( s8LocalDiag_trim
                                       - Lfbk_enlean_extra_gas_c);
   }
   else
   {
      s16LocalDiagTrimEnlean = (sint16)(s8LocalDiag_trim - Lfbk_enlean_extra_c);
   }

   s8LocalDiag_trim = (sint8)MATHSRV_udtMAX(s16LocalDiagTrimEnlean, -128);
   VEMS_vidSET(Diag_trim, s8LocalDiag_trim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidWaitAbortFuelCheck                             */
/* !Description :  Lorsque la correction 02_oxy_sensor_test_performed est     */
/*                 interrompue, un passage par le bloc 01_re_initialization   */
/*                 annule la requête de correction (Performing_oxy_sensor_test*/
/*                 = 0) et la stratégie entre dans le bloc                    */
/*                 03_wait_abort_fuel_check.                                  */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidEndOfDlyPeriodCntMgr();                      */
/*  extf argret void INJTICOR_vidClampDiagnosis();                            */
/*  input boolean Check_fuelling_fault;                                       */
/*  input boolean Clamp_operated;                                             */
/*  output boolean Lfbk_stuck_diag_done;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidWaitAbortFuelCheck(void)
{
   /*03_wait_abort_fuel_check*/

   if (Check_fuelling_fault == 0)
   {
      /*01_end_of_delay_period_count_manager*/
      INJTICOR_vidEndOfDlyPeriodCntMgr();
      Lfbk_stuck_diag_done = 0;
   }
   else
   {
      if (Clamp_operated != 0)
      {
         /*02_clamp_diagnosis*/
         INJTICOR_vidClampDiagnosis();
         Lfbk_stuck_diag_done = 1;
      }
      else
      {
         Lfbk_stuck_diag_done = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidEndOfDlyPeriodCntMgr                           */
/* !Description :  Le booléen Lfbk_clamp_tests_aborted indique que la         */
/*                 régulation de richesse n'est pas revenue en butée durant la*/
/*                 temporisation Lfbk_fuelling_clamp_delay_c. Et lediagnostic */
/*                 est toujours actif au cas où la régulation revienne en     */
/*                 butée.                                                     */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidEndOfDlyPeriodCntDec();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Lfbk_end_of_delay_period_count;                              */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Lfbk_fuelling_clamp_delay_gas_c;                             */
/*  input uint16 Lfbk_fuelling_clamp_delay_c;                                 */
/*  output boolean Lfbk_clamp_tests_aborted;                                  */
/*  output uint16 Lfbk_end_of_delay_period_count;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidEndOfDlyPeriodCntMgr(void)
{
   /*01_end_of_delay_period_count_manager*/
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalEndDelayPeriodCount;


   if (Lfbk_end_of_delay_period_count == 0)
   {
      Lfbk_clamp_tests_aborted = 1;
      /*01_end_of_delay_period_count_decrement*/
      INJTICOR_vidEndOfDlyPeriodCntDec();

      VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         u16LocalEndDelayPeriodCount = Lfbk_fuelling_clamp_delay_gas_c;
      }
      else
      {
         u16LocalEndDelayPeriodCount = Lfbk_fuelling_clamp_delay_c;
      }
   }
   else
   {
      u16LocalEndDelayPeriodCount = (uint16)( Lfbk_end_of_delay_period_count
                                            - 1);
      Lfbk_clamp_tests_aborted = 0;
   }
   Lfbk_end_of_delay_period_count =
      (uint16)MATHSRV_udtMIN(u16LocalEndDelayPeriodCount, 324);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidEndOfDlyPeriodCntDec                           */
/* !Description :  Pendant la temporisation, si la régulation de richesse     */
/*                 revient en butée (Clamp_operated = 1) alors on active      */
/*                 Check_fuelling_fault, ce qui a pour conséquence de sortir  */
/*                 de ce bloc et de rentrer dans 02_clamp_diagnosis.          */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Clamp_operated;                                             */
/*  output boolean Check_fuelling_fault;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidEndOfDlyPeriodCntDec(void)
{
   /*01_end_of_delay_period_count_decrement*/
   Check_fuelling_fault = Clamp_operated;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidClampDiagnosis                                 */
/* !Description :  Ce bloc est activé si la régulation de richesse revient en */
/*                 butée pendant la temporisation Lfbk_fuelling_clamp_delay_c,*/
/*                 et remonte instantanément le booléen de défaillance.       */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidOnEnrichClampDiag();                         */
/*  extf argret void INJTICOR_vidOnEnleanClampDiag();                         */
/*  input boolean Lfbk_on_enrich_clamp;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidClampDiagnosis(void)
{
   /*02_clamp_diagnosis*/
   boolean bLocalLfbk_on_enrich_clamp;


   VEMS_vidGET(Lfbk_on_enrich_clamp, bLocalLfbk_on_enrich_clamp);

   if (bLocalLfbk_on_enrich_clamp != 0)
   {
      /*02_on_enrich_clamp_diagnosis*/
      INJTICOR_vidOnEnrichClampDiag();
   }
   else
   {
      /*01_on_enlean_clamp_diagnosis*/
      INJTICOR_vidOnEnleanClampDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidOnEnrichClampDiag                              */
/* !Description :  Lorsque cette fonction est activé Lfbk_stuck_lean prend la */
/*                 valeur 1.                                                  */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Lfbk_stuck_lean;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidOnEnrichClampDiag(void)
{
   /*02_on_enrich_clamp_diagnosis*/
   Lfbk_stuck_lean = 1;
}
/*------------------------------- end of file --------------------------------*/