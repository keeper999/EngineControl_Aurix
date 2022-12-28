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
/* !File            : INJTICOR_FCT4.C                                         */
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
/*   1 / INJTICOR_vidOnEnleanClampDiag                                        */
/*   2 / INJTICOR_vidFailureManager                                           */
/*   3 / INJTICOR_vidNoFailure                                                */
/*   4 / INJTICOR_vidSeqDftFuAfl                                              */
/*   5 / INJTICOR_vidSeqDftSenO2Afl                                           */
/*   6 / INJTICOR_vidSeqORngLfbkAfl                                           */
/*   7 / INJTICOR_vidSeqDftFuAfr                                              */
/*   8 / INJTICOR_vidSeqDftSenO2Afr                                           */
/*   9 / INJTICOR_vidSeqORngLfbkAfr                                           */
/*   10 / INJTICOR_vidDiagComputation                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_FCT4.C_v        $*/
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
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidOnEnleanClampDiag                              */
/* !Description :  Lorsque cette fonction est activé, Lfbk_stuck_rich prend la*/
/*                 valeur 1.                                                  */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Lfbk_stuck_rich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidOnEnleanClampDiag(void)
{
   /*01_on_enlean_clamp_diagnosis*/
   Lfbk_stuck_rich = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidFailureManager                                 */
/* !Description :  Lorsqu'une panne Inj_bDgoStuckLfbk remonte, c'est-à-dire   */
/*                 que la régulation ne peut pas être décollée de la butée,   */
/*                 Lfbk_cor_completed passe à 1, et le diagnostic est fini    */
/*                 jusqu'au prochain reset.                                   */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint8 Diag_trim;                                                   */
/*  output boolean Lfbk_cor_completed;                                        */
/*  output boolean Lfbk_diag_no_failure_completed;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidFailureManager(void)
{
   /*03_Failure_Manager*/
   VEMS_vidSET(Diag_trim, 0);
   VEMS_vidSET(Lfbk_cor_completed, 1);
   VEMS_vidSET(Lfbk_diag_no_failure_completed, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidNoFailure                                      */
/* !Description :  si les conditions d'activation du diagnostic sont présentes*/
/*                 et qu'il n'y a pas de panne, les booléens de sortie de la  */
/*                 partie curative sont à 0.                                  */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Oxy_sensor_test;                                            */
/*  input uint16 Lfbk_diag_aborted_count;                                     */
/*  input uint16 Lfbk_diag_aborted_delay_gas_c;                               */
/*  input uint16 Lfbk_diag_aborted_delay_c;                                   */
/*  input uint16 Lfbk_no_failure_delay_gas_c;                                 */
/*  input uint16 Lfbk_no_failure_delay_c;                                     */
/*  output uint16 Lfbk_diag_aborted_count;                                    */
/*  output boolean Lfbk_diag_completed;                                       */
/*  output uint16 Lfbk_tempo_no_failure;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidNoFailure(void)
{
   /*04_no_failure*/
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalDiagAbortedCount;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   if (Oxy_sensor_test == 0)
   {
      if (Lfbk_diag_aborted_count > 0)
      {
         u16LocalDiagAbortedCount = (uint16)(Lfbk_diag_aborted_count - 1);
      }
      else
      {
         u16LocalDiagAbortedCount = 0;
      }
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         u16LocalDiagAbortedCount = Lfbk_diag_aborted_delay_gas_c;
      }
      else
      {
         u16LocalDiagAbortedCount = Lfbk_diag_aborted_delay_c;
      }
   }
   Lfbk_diag_aborted_count = (uint16)MATHSRV_udtMIN(u16LocalDiagAbortedCount,
                                                    2500);
   if (Lfbk_diag_aborted_count == 0)
   {
      Lfbk_diag_completed = 0;
   }
   else
   {
      Lfbk_diag_completed = 1;
   }

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Lfbk_tempo_no_failure =
         (uint16)MATHSRV_udtMIN(Lfbk_no_failure_delay_gas_c, 49999);
   }
   else
   {
      Lfbk_tempo_no_failure = (uint16)MATHSRV_udtMIN(Lfbk_no_failure_delay_c,
                                                     49999);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSeqDftFuAfl                                    */
/* !Description :  Diagnostic de la regulation de richesse bloquee pauvre a   */
/*                 cause de l'injection.                                      */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Lfbk_diag_enable;                                           */
/*  input boolean Inj_bAcvSeqDftFu_Afl_C;                                     */
/*  input boolean Lfbk_stuck_lean;                                            */
/*  input boolean Flev_low_fuel_level_sw_lfbk;                                */
/*  input boolean Flev_low_fuel_level_Afl;                                    */
/*  output boolean Inj_bMonRunDftFu_Afl;                                      */
/*  output boolean Inj_bMonRunDftFuGas_Afl;                                   */
/*  output boolean Inj_bDgoDftFu_Afl;                                         */
/*  output boolean Inj_bDgoDftFuGas_Afl;                                      */
/*  output boolean Inj_bMonWaitDftFu_Afl;                                     */
/*  output boolean Inj_bMonWaitDftFuGas_Afl;                                  */
/*  output boolean Inj_bAcvSeqDftFuGas_Afl;                                   */
/*  output boolean Inj_bAcvSeqDftFu_Afl;                                      */
/*  output boolean Inj_bAcvSeqMemDftFu_Afl;                                   */
/*  output boolean Inj_bAcvSeqMemDftFuGas_Afl;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSeqDftFuAfl(void)
{
   /*04_SeqDftFu_Afl*/
   GDFRM_tenuGDUState LocalstDgoORngUsPlausFco;
   GDFRM_tenuGDUState LocalstDgoORngDsHeat;
   GDFRM_tenuGDUState LocalstDgoORngOxyApvPerd;
   GDFRM_tenuGDUState LocalstDgoORngOxySensPerd;
   GDFRM_tenuGDUState LocalstDgoORngDsPlausFco;
   boolean            bLocalFlev_low_fuel_level_sw_lfb;
   boolean            bLocalMonWait1;
   boolean            bLocalMonWait2;
   boolean            bLocalEndDiagStrtORngUsPlausFco;
   boolean            bLocalEndDiagStrtORngDsHeat;
   boolean            bLocalEndDiagStrtORngOxyApvPerd;
   boolean            bLocalEndDiagStrtORngOxySensPerd;
   boolean            bLocalEndDiagStrtORngDsPlausFco;
   boolean            bLocalEndDiagStrtORng;
   boolean            bLocalInhFuLowLvlHw;
   boolean            blocalInjbDgoDftFu;
   uint8              u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Inj_bMonRunDftFu_Afl = 0;
      Inj_bMonRunDftFuGas_Afl = Lfbk_diag_enable;
   }
   else
   {
      Inj_bMonRunDftFu_Afl = Lfbk_diag_enable;
      Inj_bMonRunDftFuGas_Afl = 0;
   }

   LocalstDgoORngUsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USPLAUSFCO);
   LocalstDgoORngDsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   LocalstDgoORngOxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   LocalstDgoORngOxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   LocalstDgoORngDsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (  (LocalstDgoORngUsPlausFco == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxyApvPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxySensPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsPlausFco == GDU_ETAT_PRESENT))
      && (Inj_bAcvSeqDftFu_Afl_C != 0))
   {
      Inj_bDgoDftFu_Afl = 0;
      Inj_bDgoDftFuGas_Afl = 0;
      blocalInjbDgoDftFu = 0;
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bDgoDftFu_Afl = 0;
         Inj_bDgoDftFuGas_Afl = Lfbk_stuck_lean;
      }
      else
      {
         Inj_bDgoDftFu_Afl = Lfbk_stuck_lean;
         Inj_bDgoDftFuGas_Afl = 0;
      }
      blocalInjbDgoDftFu = Lfbk_stuck_lean;
   }

   if (blocalInjbDgoDftFu != 0)
   {
      VEMS_vidGET(Flev_low_fuel_level_sw_lfbk,
                  bLocalFlev_low_fuel_level_sw_lfb);
      bLocalInhFuLowLvlHw = GDGAR_bGetFRM(FRM_FRM_INHFULOWLVLHW);
      if (  (Flev_low_fuel_level_Afl != 0)
         || (  (bLocalFlev_low_fuel_level_sw_lfb != 0)
            && (bLocalInhFuLowLvlHw != 0)))
      {
         bLocalMonWait1 = 1;
      }
      else
      {
         bLocalMonWait1 = 0;
      }
   }
   else
   {
      if (Lfbk_diag_enable != 0)
      {
         bLocalMonWait1 = 0;
      }
      else
      {
         bLocalMonWait1 = 1;
      }
   }

   bLocalEndDiagStrtORngUsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USPLAUSFCO);
   bLocalEndDiagStrtORngDsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalEndDiagStrtORngOxySensPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalEndDiagStrtORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (bLocalEndDiagStrtORngUsPlausFco == 0)
      || (bLocalEndDiagStrtORngDsHeat == 0)
      || (bLocalEndDiagStrtORngOxyApvPerd == 0)
      || (bLocalEndDiagStrtORngOxySensPerd == 0)
      || (bLocalEndDiagStrtORngDsPlausFco == 0))
   {
      bLocalEndDiagStrtORng = 1;
   }
   else
   {
      bLocalEndDiagStrtORng = 0;
   }

   if (Inj_bAcvSeqDftFu_Afl_C != 0)
   {
      bLocalMonWait2 = bLocalEndDiagStrtORng;
   }
   else
   {
      bLocalMonWait2 = 0;
   }

   if (  (bLocalMonWait1 != 0)
      || (bLocalMonWait2 != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bMonWaitDftFu_Afl = 0;
         Inj_bMonWaitDftFuGas_Afl = 1;
      }
      else
      {
         Inj_bMonWaitDftFu_Afl = 1;
         Inj_bMonWaitDftFuGas_Afl = 0;
      }
   }
   else
   {
      Inj_bMonWaitDftFu_Afl = 0;
      Inj_bMonWaitDftFuGas_Afl = 0;
   }

   if (  (bLocalEndDiagStrtORng != 0)
      && (Lfbk_stuck_lean != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afl, 0);
         VEMS_vidSET(Inj_bAcvSeqDftFu_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqMemDftFu_Afl, 1);
      }
      else
      {
         VEMS_vidSET(Inj_bAcvSeqDftFu_Afl, 0);
         VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqMemDftFuGas_Afl, 1);
      }
   }
   else
   {
      VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afl, 0);
      VEMS_vidSET(Inj_bAcvSeqDftFu_Afl, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSeqDftSenO2Afl                                 */
/* !Description :  Diagnostic de la regulation de richesse bloquee pauvre a   */
/*                 cause des sondes O2                                        */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Lfbk_diag_enable;                                           */
/*  input boolean Inj_bAcvSeqDftSenO2_Afl_C;                                  */
/*  input boolean Lfbk_switch_rich;                                           */
/*  input boolean Flev_low_fuel_level_sw_lfbk;                                */
/*  output boolean Inj_bMonRunDftSenO2_Afl;                                   */
/*  output boolean Inj_bMonRunDftSenO2Gas_Afl;                                */
/*  output boolean Inj_bDgoDftSenO2_Afl;                                      */
/*  output boolean Inj_bDgoDftSenO2Gas_Afl;                                   */
/*  output boolean Inj_bMonWaitDftSenO2_Afl;                                  */
/*  output boolean Inj_bMonWaitDftSenO2Gas_Afl;                               */
/*  output boolean Inj_bAcvSeqDftSenO2_Afl;                                   */
/*  output boolean Inj_bAcvSeqDftSenO2Gas_Afl;                                */
/*  output boolean Inj_bAcvSeqMemDftSenO2Gas_Afl;                             */
/*  output boolean Inj_bAcvSeqMemDftSenO2_Afl;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSeqDftSenO2Afl(void)
{
   /*04_SeqDftSenO2_Afl*/
   GDFRM_tenuGDUState LocalstDgoORngUsPlausFco;
   GDFRM_tenuGDUState LocalstDgoORngDsHeat;
   GDFRM_tenuGDUState LocalstDgoORngOxyApvPerd;
   GDFRM_tenuGDUState LocalstDgoORngOxySensPerd;
   GDFRM_tenuGDUState LocalstDgoORngDsPlausFco;
   boolean            bLocalFlev_low_fuel_level_sw_lfb;
   boolean            bLocalMonWait1;
   boolean            bLocalMonWait2;
   boolean            bLocalEndDiagStrtORngUsPlausFco;
   boolean            bLocalEndDiagStrtORngDsHeat;
   boolean            bLocalEndDiagStrtORngOxyApvPerd;
   boolean            bLocalEndDiagStrtORngOxySensPerd;
   boolean            bLocalEndDiagStrtORngDsPlausFco;
   boolean            bLocalEndDiagStrtORng;
   boolean            bLocalInhFuLowLvlHw;
   boolean            blocalInjbDgoDftSenO2;
   uint8              u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Inj_bMonRunDftSenO2_Afl = 0;
      Inj_bMonRunDftSenO2Gas_Afl = Lfbk_diag_enable;
   }
   else
   {
      Inj_bMonRunDftSenO2_Afl = Lfbk_diag_enable;
      Inj_bMonRunDftSenO2Gas_Afl = 0;
   }

   LocalstDgoORngUsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USPLAUSFCO);
   LocalstDgoORngDsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   LocalstDgoORngOxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   LocalstDgoORngOxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   LocalstDgoORngDsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (  (LocalstDgoORngUsPlausFco == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxyApvPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxySensPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsPlausFco == GDU_ETAT_PRESENT))
      && (Inj_bAcvSeqDftSenO2_Afl_C != 0))
   {
      Inj_bDgoDftSenO2_Afl = 0;
      Inj_bDgoDftSenO2Gas_Afl = 0;
      blocalInjbDgoDftSenO2 = 0;
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bDgoDftSenO2_Afl = 0;
         Inj_bDgoDftSenO2Gas_Afl = Lfbk_switch_rich;
      }
      else
      {
         Inj_bDgoDftSenO2_Afl = Lfbk_switch_rich;
         Inj_bDgoDftSenO2Gas_Afl = 0;
      }
      blocalInjbDgoDftSenO2 = Lfbk_switch_rich;
   }

   if (blocalInjbDgoDftSenO2 != 0)
   {
      VEMS_vidGET(Flev_low_fuel_level_sw_lfbk,
                  bLocalFlev_low_fuel_level_sw_lfb);
      bLocalInhFuLowLvlHw = GDGAR_bGetFRM(FRM_FRM_INHFULOWLVLHW);
      if (  (bLocalFlev_low_fuel_level_sw_lfb != 0)
         && (bLocalInhFuLowLvlHw != 0))
      {
         bLocalMonWait1 = 1;
      }
      else
      {
         bLocalMonWait1 = 0;
      }
   }
   else
   {
      if (Lfbk_diag_enable != 0)
      {
         bLocalMonWait1 = 0;
      }
      else
      {
         bLocalMonWait1 = 1;
      }
   }

   bLocalEndDiagStrtORngUsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USPLAUSFCO);
   bLocalEndDiagStrtORngDsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalEndDiagStrtORngOxySensPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalEndDiagStrtORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (bLocalEndDiagStrtORngUsPlausFco == 0)
      || (bLocalEndDiagStrtORngDsHeat == 0)
      || (bLocalEndDiagStrtORngOxyApvPerd == 0)
      || (bLocalEndDiagStrtORngOxySensPerd == 0)
      || (bLocalEndDiagStrtORngDsPlausFco == 0))
   {
      bLocalEndDiagStrtORng = 1;
   }
   else
   {
      bLocalEndDiagStrtORng = 0;
   }

   if (Inj_bAcvSeqDftSenO2_Afl_C != 0)
   {
      bLocalMonWait2 = bLocalEndDiagStrtORng;
   }
   else
   {
      bLocalMonWait2 = 0;
   }

   if (  (bLocalMonWait1 != 0)
      || (bLocalMonWait2 != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bMonWaitDftSenO2_Afl = 0;
         Inj_bMonWaitDftSenO2Gas_Afl = 1;
      }
      else
      {
         Inj_bMonWaitDftSenO2_Afl = 1;
         Inj_bMonWaitDftSenO2Gas_Afl = 0;
      }
   }
   else
   {
      Inj_bMonWaitDftSenO2_Afl = 0;
      Inj_bMonWaitDftSenO2Gas_Afl = 0;
   }

   if (  (bLocalEndDiagStrtORng != 0)
      && (Lfbk_switch_rich != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afl, 0);
         VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqMemDftSenO2Gas_Afl, 1);
      }
      else
      {
         VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqMemDftSenO2_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afl, 0);
      }
   }
   else
   {
      VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afl, 0);
      VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afl, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSeqORngLfbkAfl                                 */
/* !Description :  Diagnostic de la regulation de richesse en butee pauvre.   */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Lfbk_diag_enable;                                           */
/*  input boolean Inj_bAcvSeqORngLfbkGas_Afl_C;                               */
/*  input boolean Lfbk_lean_fuel;                                             */
/*  input boolean Flev_low_fuel_level_sw_lfbk;                                */
/*  input boolean Flev_low_fuel_level_Afl;                                    */
/*  input boolean Inj_bAcvSeqORngLfbk_Afl_C;                                  */
/*  output boolean Inj_bMonRunORngLfbk_Afl;                                   */
/*  output boolean Inj_bMonRunORngLfbkGas_Afl;                                */
/*  output boolean Inj_bDgoORngLfbk_Afl;                                      */
/*  output boolean Inj_bDgoORngLfbkGas_Afl;                                   */
/*  output boolean Inj_bMonWaitORngLfbk_Afl;                                  */
/*  output boolean Inj_bMonWaitORngLfbkGas_Afl;                               */
/*  output boolean Inj_bAcvSeqORngLfbk_Afl;                                   */
/*  output boolean Inj_bAcvSeqMemORngLfbkGas_Afl;                             */
/*  output boolean Inj_bAcvSeqORngLfbkGas_Afl;                                */
/*  output boolean Inj_bAcvSeqMemORngLfbk_Afl;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSeqORngLfbkAfl(void)
{
   /*04_SeqORngLfbk_Afl*/
   GDFRM_tenuGDUState LocalstDgoORngUsPlausFco;
   GDFRM_tenuGDUState LocalstDgoORngDsHeat;
   GDFRM_tenuGDUState LocalstDgoORngOxyApvPerd;
   GDFRM_tenuGDUState LocalstDgoORngOxySensPerd;
   GDFRM_tenuGDUState LocalstDgoORngDsPlausFco;
   boolean            bLocalFlev_low_fuel_level_sw_lfb;
   boolean            bLocalMonWait1;
   boolean            bLocalMonWait2;
   boolean            bLocalEndDiagStrtORngUsPlausFco;
   boolean            bLocalEndDiagStrtORngDsHeat;
   boolean            bLocalEndDiagStrtORngOxyApvPerd;
   boolean            bLocalEndDiagStrtORngOxySensPerd;
   boolean            bLocalEndDiagStrtORngDsPlausFco;
   boolean            bLocalEndDiagStrtORng;
   boolean            bLocalInhFuLowLvlHw;
   boolean            blocalInjbDgoORngLfbk;
   uint8              u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Inj_bMonRunORngLfbk_Afl = 0;
      Inj_bMonRunORngLfbkGas_Afl = Lfbk_diag_enable;
   }
   else
   {
      Inj_bMonRunORngLfbk_Afl = Lfbk_diag_enable;
      Inj_bMonRunORngLfbkGas_Afl = 0;
   }

   LocalstDgoORngUsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USPLAUSFCO);
   LocalstDgoORngDsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   LocalstDgoORngOxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   LocalstDgoORngOxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   LocalstDgoORngDsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (  (LocalstDgoORngUsPlausFco == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxyApvPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxySensPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsPlausFco == GDU_ETAT_PRESENT))
      && (Inj_bAcvSeqORngLfbkGas_Afl_C != 0))
   {
      Inj_bDgoORngLfbk_Afl = 0;
      Inj_bDgoORngLfbkGas_Afl = 0;
      blocalInjbDgoORngLfbk = 0;
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bDgoORngLfbk_Afl = 0;
         Inj_bDgoORngLfbkGas_Afl = Lfbk_lean_fuel;
      }
      else
      {
         Inj_bDgoORngLfbk_Afl = Lfbk_lean_fuel;
         Inj_bDgoORngLfbkGas_Afl = 0;
      }
      blocalInjbDgoORngLfbk = Lfbk_lean_fuel;
   }

   if (blocalInjbDgoORngLfbk != 0)
   {
      VEMS_vidGET(Flev_low_fuel_level_sw_lfbk,
                  bLocalFlev_low_fuel_level_sw_lfb);
      bLocalInhFuLowLvlHw = GDGAR_bGetFRM(FRM_FRM_INHFULOWLVLHW);
      if (  (Flev_low_fuel_level_Afl != 0)
         || (  (bLocalFlev_low_fuel_level_sw_lfb != 0)
            && (bLocalInhFuLowLvlHw != 0)))
      {
         bLocalMonWait1  = 1;
      }
      else
      {
         bLocalMonWait1  = 0;
      }
   }
   else
   {
      if (Lfbk_diag_enable != 0)
      {
         bLocalMonWait1 = 0;
      }
      else
      {
         bLocalMonWait1 = 1;
      }
   }

   bLocalEndDiagStrtORngUsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USPLAUSFCO);
   bLocalEndDiagStrtORngDsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalEndDiagStrtORngOxySensPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalEndDiagStrtORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (bLocalEndDiagStrtORngUsPlausFco == 0)
      || (bLocalEndDiagStrtORngDsHeat == 0)
      || (bLocalEndDiagStrtORngOxyApvPerd == 0)
      || (bLocalEndDiagStrtORngOxySensPerd == 0)
      || (bLocalEndDiagStrtORngDsPlausFco == 0))
   {
      bLocalEndDiagStrtORng = 1;
   }
   else
   {
      bLocalEndDiagStrtORng = 0;
   }

   if (Inj_bAcvSeqORngLfbk_Afl_C != 0)
   {
      bLocalMonWait2 = bLocalEndDiagStrtORng;
   }
   else
   {
      bLocalMonWait2 = 0;
   }

   if (  (bLocalMonWait1 != 0)
      || (bLocalMonWait2 != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bMonWaitORngLfbk_Afl = 0;
         Inj_bMonWaitORngLfbkGas_Afl = 1;
      }
      else
      {
         Inj_bMonWaitORngLfbk_Afl = 1;
         Inj_bMonWaitORngLfbkGas_Afl = 0;
      }
   }
   else
   {
      Inj_bMonWaitORngLfbk_Afl = 0;
      Inj_bMonWaitORngLfbkGas_Afl = 0;
   }

   if (  (bLocalEndDiagStrtORng != 0)
      && (Lfbk_lean_fuel != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afl, 0);
         VEMS_vidSET(Inj_bAcvSeqMemORngLfbkGas_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afl, 1);
      }
      else
      {
         VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afl, 1);
         VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afl, 0);
         VEMS_vidSET(Inj_bAcvSeqMemORngLfbk_Afl, 1);
      }
   }
   else
   {
      VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afl, 0);
      VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afl, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSeqDftFuAfr                                    */
/* !Description :  Diagnostic de la regulation de richesse bloquee riche a    */
/*                 cause de l'injection.                                      */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Lfbk_diag_enable;                                           */
/*  input boolean Inj_bAcvSeqDftFu_Afr_C;                                     */
/*  input boolean Lfbk_stuck_rich;                                            */
/*  output boolean Inj_bMonRunDftFu_Afr;                                      */
/*  output boolean Inj_bMonRunDftFuGas_Afr;                                   */
/*  output boolean Inj_bDgoDftFu_Afr;                                         */
/*  output boolean Inj_bDgoDftFuGas_Afr;                                      */
/*  output boolean Inj_bMonWaitDftFu_Afr;                                     */
/*  output boolean Inj_bMonWaitDftFuGas_Afr;                                  */
/*  output boolean Inj_bAcvSeqDftFu_Afr;                                      */
/*  output boolean Inj_bAcvSeqDftFuGas_Afr;                                   */
/*  output boolean Inj_bAcvSeqMemDftFuGas_Afr;                                */
/*  output boolean Inj_bAcvSeqMemDftFu_Afr;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSeqDftFuAfr(void)
{
   /*05_SeqDftFu_Afr*/
   GDFRM_tenuGDUState LocalstDgoORngUsHeat;
   GDFRM_tenuGDUState LocalstDgoORngDsHeat;
   GDFRM_tenuGDUState LocalstDgoORngOxyApvPerd;
   GDFRM_tenuGDUState LocalstDgoORngOxySensPerd;
   GDFRM_tenuGDUState LocalstDgoORngDsPlausFco;
   boolean            bLocalMonWait1;
   boolean            bLocalMonWait2;
   boolean            bLocalEndDiagStrtORngUsHeat;
   boolean            bLocalEndDiagStrtORngDsHeat;
   boolean            bLocalEndDiagStrtORngOxyApvPerd;
   boolean            bLocalEndDiagStrtORngOxySensPerd;
   boolean            bLocalEndDiagStrtORngDsPlausFco;
   boolean            bLocalEndDiagStrtORng;
   boolean            bLocalInjbDgoDftFu;
   uint8              u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Inj_bMonRunDftFu_Afr = 0;
      Inj_bMonRunDftFuGas_Afr = Lfbk_diag_enable;
   }
   else
   {
      Inj_bMonRunDftFu_Afr = Lfbk_diag_enable;
      Inj_bMonRunDftFuGas_Afr = 0;
   }

   LocalstDgoORngUsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
   LocalstDgoORngDsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   LocalstDgoORngOxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   LocalstDgoORngOxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   LocalstDgoORngDsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (  (LocalstDgoORngUsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxyApvPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxySensPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsPlausFco == GDU_ETAT_PRESENT))
      && (Inj_bAcvSeqDftFu_Afr_C != 0))
   {
      Inj_bDgoDftFu_Afr = 0;
      Inj_bDgoDftFuGas_Afr = 0;
      bLocalInjbDgoDftFu = 0;
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bDgoDftFu_Afr = 0;
         Inj_bDgoDftFuGas_Afr = Lfbk_stuck_rich;
      }
      else
      {
         Inj_bDgoDftFu_Afr = Lfbk_stuck_rich;
         Inj_bDgoDftFuGas_Afr = 0;
      }
      bLocalInjbDgoDftFu = Lfbk_stuck_rich;
   }

   if (bLocalInjbDgoDftFu != 0)
   {
      bLocalMonWait1 = 0;
   }
   else
   {
      if (Lfbk_diag_enable != 0)
      {
         bLocalMonWait1 = 0;
      }
      else
      {
         bLocalMonWait1 = 1;
      }
   }

   bLocalEndDiagStrtORngUsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);
   bLocalEndDiagStrtORngDsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalEndDiagStrtORngOxySensPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalEndDiagStrtORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (bLocalEndDiagStrtORngUsHeat == 0)
      || (bLocalEndDiagStrtORngDsHeat == 0)
      || (bLocalEndDiagStrtORngOxyApvPerd == 0)
      || (bLocalEndDiagStrtORngOxySensPerd == 0)
      || (bLocalEndDiagStrtORngDsPlausFco == 0))
   {
      bLocalEndDiagStrtORng = 1;
   }
   else
   {
      bLocalEndDiagStrtORng = 0;
   }

   if (Inj_bAcvSeqDftFu_Afr_C != 0)
   {
      bLocalMonWait2 = bLocalEndDiagStrtORng;
   }
   else
   {
      bLocalMonWait2 = 0;
   }

   if (  (bLocalMonWait1 != 0)
      || (bLocalMonWait2 != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bMonWaitDftFu_Afr = 0;
         Inj_bMonWaitDftFuGas_Afr = 1;
      }
      else
      {
         Inj_bMonWaitDftFu_Afr = 1;
         Inj_bMonWaitDftFuGas_Afr = 0;
      }
   }
   else
   {
      Inj_bMonWaitDftFu_Afr = 0;
      Inj_bMonWaitDftFuGas_Afr = 0;
   }

   if (  (bLocalEndDiagStrtORng != 0)
      && (Lfbk_stuck_rich != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Inj_bAcvSeqDftFu_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afr, 0);
         VEMS_vidSET(Inj_bAcvSeqMemDftFuGas_Afr, 1);
      }
      else
      {
         VEMS_vidSET(Inj_bAcvSeqDftFu_Afr, 0);
         VEMS_vidSET(Inj_bAcvSeqMemDftFu_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afr, 1);
      }
   }
   else
   {
      VEMS_vidSET(Inj_bAcvSeqDftFu_Afr, 0);
      VEMS_vidSET(Inj_bAcvSeqDftFuGas_Afr, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSeqDftSenO2Afr                                 */
/* !Description :  Diagnostic de la regulation de richesse bloquee riche a    */
/*                 cause des sondes O2.                                       */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Lfbk_diag_enable;                                           */
/*  input boolean Inj_bAcvSeqDftSenO2_Afr_C;                                  */
/*  input boolean Lfbk_switch_lean;                                           */
/*  output boolean Inj_bMonRunDftSenO2_Afr;                                   */
/*  output boolean Inj_bMonRunDftSenO2Gas_Afr;                                */
/*  output boolean Inj_bDgoDftSenO2_Afr;                                      */
/*  output boolean Inj_bDgoDftSenO2Gas_Afr;                                   */
/*  output boolean Inj_bMonWaitDftSenO2_Afr;                                  */
/*  output boolean Inj_bMonWaitDftSenO2Gas_Afr;                               */
/*  output boolean Inj_bAcvSeqDftSenO2_Afr;                                   */
/*  output boolean Inj_bAcvSeqDftSenO2Gas_Afr;                                */
/*  output boolean Inj_bAcvSeqMemDftSenO2Gas_Afr;                             */
/*  output boolean Inj_bAcvSeqMemDftSenO2_Afr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSeqDftSenO2Afr(void)
{
   /*05_SeqDftSenO2_Afr*/
   GDFRM_tenuGDUState LocalstDgoORngUsHeat;
   GDFRM_tenuGDUState LocalstDgoORngDsHeat;
   GDFRM_tenuGDUState LocalstDgoORngOxyApvPerd;
   GDFRM_tenuGDUState LocalstDgoORngOxySensPerd;
   GDFRM_tenuGDUState LocalstDgoORngDsPlausFco;
   boolean            bLocalMonWait1;
   boolean            bLocalMonWait2;
   boolean            bLocalEndDiagStrtORngUsHeat;
   boolean            bLocalEndDiagStrtORngDsHeat;
   boolean            bLocalEndDiagStrtORngOxyApvPerd;
   boolean            bLocalEndDiagStrtORngOxySensPerd;
   boolean            bLocalEndDiagStrtORngDsPlausFco;
   boolean            bLocalEndDiagStrtORng;
   boolean            bLocalInjbDgoDftSenO2;
   uint8              u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Inj_bMonRunDftSenO2_Afr = 0;
      Inj_bMonRunDftSenO2Gas_Afr = Lfbk_diag_enable;
   }
   else
   {
      Inj_bMonRunDftSenO2_Afr = Lfbk_diag_enable;
      Inj_bMonRunDftSenO2Gas_Afr = 0;
   }

   LocalstDgoORngUsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
   LocalstDgoORngDsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   LocalstDgoORngOxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   LocalstDgoORngOxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   LocalstDgoORngDsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (  (LocalstDgoORngUsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxyApvPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxySensPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsPlausFco == GDU_ETAT_PRESENT))
      && (Inj_bAcvSeqDftSenO2_Afr_C != 0))
   {
      Inj_bDgoDftSenO2_Afr = 0;
      Inj_bDgoDftSenO2Gas_Afr = 0;
      bLocalInjbDgoDftSenO2 = 0;
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bDgoDftSenO2_Afr = 0;
         Inj_bDgoDftSenO2Gas_Afr = Lfbk_switch_lean;
      }
      else
      {
         Inj_bDgoDftSenO2_Afr = Lfbk_switch_lean;
         Inj_bDgoDftSenO2Gas_Afr = 0;
      }
      bLocalInjbDgoDftSenO2 = Lfbk_switch_lean;
   }

   if (bLocalInjbDgoDftSenO2 != 0)
   {
      bLocalMonWait1 = 0;
   }
   else
   {
      if (Lfbk_diag_enable != 0)
      {
         bLocalMonWait1 = 0;
      }
      else
      {
         bLocalMonWait1 = 1;
      }
   }

   bLocalEndDiagStrtORngUsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);
   bLocalEndDiagStrtORngDsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalEndDiagStrtORngOxySensPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalEndDiagStrtORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (bLocalEndDiagStrtORngUsHeat == 0)
      || (bLocalEndDiagStrtORngDsHeat == 0)
      || (bLocalEndDiagStrtORngOxyApvPerd == 0)
      || (bLocalEndDiagStrtORngOxySensPerd == 0)
      || (bLocalEndDiagStrtORngDsPlausFco == 0))
   {
      bLocalEndDiagStrtORng = 1;
   }
   else
   {
      bLocalEndDiagStrtORng = 0;
   }

   if (Inj_bAcvSeqDftSenO2_Afr_C != 0)
   {
      bLocalMonWait2 = bLocalEndDiagStrtORng;
   }
   else
   {
      bLocalMonWait2 = 0;
   }

   if (  (bLocalMonWait1 != 0)
      || (bLocalMonWait2 != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bMonWaitDftSenO2_Afr = 0;
         Inj_bMonWaitDftSenO2Gas_Afr = 1;
      }
      else
      {
         Inj_bMonWaitDftSenO2_Afr = 1;
         Inj_bMonWaitDftSenO2Gas_Afr = 0;
      }
   }
   else
   {
      Inj_bMonWaitDftSenO2_Afr = 0;
      Inj_bMonWaitDftSenO2Gas_Afr = 0;
   }

   if (  (bLocalEndDiagStrtORng != 0)
      && (Lfbk_switch_lean != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afr, 0);
         VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqMemDftSenO2Gas_Afr, 1);
      }
      else
      {
         VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqMemDftSenO2_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afr, 0);
      }
   }
   else
   {
      VEMS_vidSET(Inj_bAcvSeqDftSenO2_Afr, 0);
      VEMS_vidSET(Inj_bAcvSeqDftSenO2Gas_Afr, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidSeqORngLfbkAfr                                 */
/* !Description :  Diagnostic de la regulation de richesse en butee riche.    */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Lfbk_diag_enable;                                           */
/*  input boolean Inj_bAcvSeqORngLfbk_Afr_C;                                  */
/*  input boolean Lfbk_rich_fuel;                                             */
/*  output boolean Inj_bMonRunORngLfbk_Afr;                                   */
/*  output boolean Inj_bMonRunORngLfbkGas_Afr;                                */
/*  output boolean Inj_bDgoORngLfbk_Afr;                                      */
/*  output boolean Inj_bDgoORngLfbkGas_Afr;                                   */
/*  output boolean Inj_bMonWaitORngLfbk_Afr;                                  */
/*  output boolean Inj_bMonWaitORngLfbkGas_Afr;                               */
/*  output boolean Inj_bAcvSeqORngLfbk_Afr;                                   */
/*  output boolean Inj_bAcvSeqORngLfbkGas_Afr;                                */
/*  output boolean Inj_bAcvSeqMemORngLfbkGas_Afr;                             */
/*  output boolean Inj_bAcvSeqMemORngLfbk_Afr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidSeqORngLfbkAfr(void)
{
   /*05_SeqORngLfbk_Afr*/
   GDFRM_tenuGDUState LocalstDgoORngUsHeat;
   GDFRM_tenuGDUState LocalstDgoORngDsHeat;
   GDFRM_tenuGDUState LocalstDgoORngOxyApvPerd;
   GDFRM_tenuGDUState LocalstDgoORngOxySensPerd;
   GDFRM_tenuGDUState LocalstDgoORngDsPlausFco;
   boolean            bLocalMonWait1;
   boolean            bLocalMonWait2;
   boolean            bLocalEndDiagStrtORngUsHeat;
   boolean            bLocalEndDiagStrtORngDsHeat;
   boolean            bLocalEndDiagStrtORngOxyApvPerd;
   boolean            bLocalEndDiagStrtORngOxySensPerd;
   boolean            bLocalEndDiagStrtORngDsPlausFco;
   boolean            bLocalEndDiagStrtORng;
   boolean            bLocalInjbDgoORngLfbk;
   uint8              u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      Inj_bMonRunORngLfbk_Afr = 0;
      Inj_bMonRunORngLfbkGas_Afr = Lfbk_diag_enable;
   }
   else
   {
      Inj_bMonRunORngLfbk_Afr = Lfbk_diag_enable;
      Inj_bMonRunORngLfbkGas_Afr = 0;
   }

   LocalstDgoORngUsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
   LocalstDgoORngDsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
   LocalstDgoORngOxyApvPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYAPVPERD);
   LocalstDgoORngOxySensPerd = GDGAR_tenuGetStDgo(GD_DFT_ORNG_OXYSENSPERD);
   LocalstDgoORngDsPlausFco = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (  (LocalstDgoORngUsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsHeat == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxyApvPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngOxySensPerd == GDU_ETAT_PRESENT)
         || (LocalstDgoORngDsPlausFco == GDU_ETAT_PRESENT))
      && (Inj_bAcvSeqORngLfbk_Afr_C != 0))
   {
      Inj_bDgoORngLfbk_Afr = 0;
      Inj_bDgoORngLfbkGas_Afr = 0;
      bLocalInjbDgoORngLfbk = 0;
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bDgoORngLfbk_Afr = 0;
         Inj_bDgoORngLfbkGas_Afr = Lfbk_rich_fuel;
      }
      else
      {
         Inj_bDgoORngLfbk_Afr = Lfbk_rich_fuel;
         Inj_bDgoORngLfbkGas_Afr = 0;
      }
      bLocalInjbDgoORngLfbk = Lfbk_rich_fuel;
   }

   if (bLocalInjbDgoORngLfbk != 0)
   {
      bLocalMonWait1 = 0;
   }
   else
   {
      if (Lfbk_diag_enable != 0)
      {
         bLocalMonWait1 = 0;
      }
      else
      {
         bLocalMonWait1 = 1;
      }
   }

   bLocalEndDiagStrtORngUsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);
   bLocalEndDiagStrtORngDsHeat =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   bLocalEndDiagStrtORngOxyApvPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYAPVPERD);
   bLocalEndDiagStrtORngOxySensPerd =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_OXYSENSPERD);
   bLocalEndDiagStrtORngDsPlausFco =
      GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSPLAUSFCO);

   if (  (bLocalEndDiagStrtORngUsHeat == 0)
      || (bLocalEndDiagStrtORngDsHeat == 0)
      || (bLocalEndDiagStrtORngOxyApvPerd == 0)
      || (bLocalEndDiagStrtORngOxySensPerd == 0)
      || (bLocalEndDiagStrtORngDsPlausFco == 0))
   {
      bLocalEndDiagStrtORng = 1;
   }
   else
   {
      bLocalEndDiagStrtORng = 0;
   }

   if (Inj_bAcvSeqORngLfbk_Afr_C != 0)
   {
      bLocalMonWait2 = bLocalEndDiagStrtORng;
   }
   else
   {
      bLocalMonWait2 = 0;
   }

   if (  (bLocalMonWait1 != 0)
      || (bLocalMonWait2 != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Inj_bMonWaitORngLfbk_Afr = 0;
         Inj_bMonWaitORngLfbkGas_Afr = 1;
      }
      else
      {
         Inj_bMonWaitORngLfbk_Afr = 1;
         Inj_bMonWaitORngLfbkGas_Afr = 0;
      }
   }
   else
   {
      Inj_bMonWaitORngLfbk_Afr = 0;
      Inj_bMonWaitORngLfbkGas_Afr = 0;
   }

   if (  (bLocalEndDiagStrtORng != 0)
      && (Lfbk_rich_fuel != 0))
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afr, 0);
         VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqMemORngLfbkGas_Afr, 1);
      }
      else
      {
         VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqMemORngLfbk_Afr, 1);
         VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afr, 0);
      }
   }
   else
   {
      VEMS_vidSET(Inj_bAcvSeqORngLfbk_Afr, 0);
      VEMS_vidSET(Inj_bAcvSeqORngLfbkGas_Afr, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJTICOR_vidDiagComputation                                */
/* !Description :  Lorsque les conditions de diagnostic sont réunies, la      */
/*                 régulation est surveillée.                                 */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INJTICOR_vidWaitApplyInitAdjust();                       */
/*  extf argret void INJTICOR_vidReinitFarStraMon();                          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void INJTICOR_vidTempoNoFailure();                            */
/*  input boolean Lfbk_mon_diag_test_enable;                                  */
/*  input boolean Clamp_operated;                                             */
/*  output boolean Lfbk_mon_diag_test_request;                                */
/*  output boolean Clamp_operated;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJTICOR_vidDiagComputation(void)
{
   /* 01_diag_computation */
   boolean bLocalLfbk_mon_diag_test_enable;


   VEMS_vidGET(Lfbk_mon_diag_test_enable, bLocalLfbk_mon_diag_test_enable);
   if (bLocalLfbk_mon_diag_test_enable != 0)
   {
      if (Clamp_operated != 0)
      {
         /*01_wait_apply_initial_adjustment*/
         INJTICOR_vidWaitApplyInitAdjust();
      }
   }
   else
   {
      /*03_Reinit_FarStraMon*/
      INJTICOR_vidReinitFarStraMon();
   }
   VEMS_vidSET(Lfbk_mon_diag_test_request, Clamp_operated);
   if (Clamp_operated == 0)
   {
      /*02_tempo_no_failure*/
      INJTICOR_vidTempoNoFailure();
   }
}
/*------------------------------- end of file --------------------------------*/