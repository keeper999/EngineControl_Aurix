/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPPERDDIAG                                     */
/* !Description     : HEATSENO2UPPERDDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPPERDDIAG                                     */
/* !Description     : DIAGNOSTIC DE LA SONDE A OXYGENE AMONT                  */
/*                                                                            */
/* !File            : HEATSENO2UPPERDDIAG_FCT3.C                              */
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
/*   1 / HEATSENO2UPPERDDIAG_vidCompPerR                                      */
/*   2 / HEATSENO2UPPERDDIAG_vidCpThdSnsR                                     */
/*   3 / HEATSENO2UPPERDDIAG_vidCpThdApvR                                     */
/*   4 / HEATSENO2UPPERDDIAG_vidOsPFaultR                                     */
/*   5 / HEATSENO2UPPERDDIAG_vidRepOsPFlR                                     */
/*   6 / HEATSENO2UPPERDDIAG_vidPerTest                                       */
/*   7 / HEATSENO2UPPERDDIAG_vidReInPrTst                                     */
/*   8 / HEATSENO2UPPERDDIAG_vidDiagCompl                                     */
/*   9 / HEATSENO2UPPERDDIAG_vidPMonitor                                      */
/*   10 / HEATSENO2UPPERDDIAG_vidApvPMonit                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5012863 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPPERDDIA$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2UPPERDDIAG.h"
#include "HEATSENO2UPPERDDIAG_L.h"
#include "HEATSENO2UPPERDDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCompPerR                            */
/* !Description :  Calcul de Oxy_ups_period.                                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_period;                                              */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint16 Oxy_ups_period_rich;                                         */
/*  output uint16 Oxy_ups_period;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCompPerR(void)
{
   /* 01_Compute_Period */
   uint32 u32Localoutput1;
   uint32 u32Localoutput2;


   u32Localoutput1 = (uint32)( (Oxy_ups_period * Oxy_period_tests)
                             + Oxy_ups_period_rich);
   u32Localoutput2 = u32Localoutput1 / (Oxy_period_tests + 1);
   Oxy_ups_period = (uint16)MATHSRV_udtMIN(u32Localoutput2, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCpThdSnsR                           */
/* !Description :  Ici le seuil max est calculé et moyenné. De plus, si       */
/*                 l’application GPL/GNV est active, les seuils utilisés sont */
/*                 spécifiques à cette application.                           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Cat_old_gain_obd;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 Engine_load_2_bkpt_map[9];                                   */
/*  input uint16 Max_oxy_sens_period_gas_map[9][9];                           */
/*  input uint16 Max_oxy_sens_period_emis_gas_map[9][9];                      */
/*  input uint16 Max_oxy_sens_period_map[9][9];                               */
/*  input uint16 Max_oxy_sens_period_emis_map[9][9];                          */
/*  input uint16 Oxy_sens_period_map_max;                                     */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint16 Max_oxy_sens_period_r;                                       */
/*  output uint16 Max_oxy_sens_period_r;                                      */
/*  output uint16 Oxy_sens_period_map_max;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCpThdSnsR(void)
{
   /* 02a_Compute_Thd_Sens */
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalExt_stSysGas;
   uint8  u8LocalCat_old_gain_obd;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalEngine_load;
   uint16 u16LocalMaxSensPerLMap1;
   uint16 u16LocalMaxSensPerLMap2;
   uint16 u16LocalMaxOxySensPeriodR;
   uint32 u32Localoutput1;
   uint32 u32Localoutput2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Engine_load, u16LocalEngine_load);
   VEMS_vidGET(Cat_old_gain_obd, u8LocalCat_old_gain_obd);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Engine_load_2_bkpt_map,
                                                u16LocalEngine_load,
                                                9);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalMaxSensPerLMap1 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_gas_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
      u16LocalMaxSensPerLMap2 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_emis_gas_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
   }
   else
   {
      u16LocalMaxSensPerLMap1 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
      u16LocalMaxSensPerLMap2 =
         MATHSRV_u16Interp2d(&Max_oxy_sens_period_emis_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
   }

   u16LocalMaxOxySensPeriodR = (uint16)( ( ( u16LocalMaxSensPerLMap1
                                           * u8LocalCat_old_gain_obd)
                                         + ( (256 - u8LocalCat_old_gain_obd)
                                           * u16LocalMaxSensPerLMap2)) / 256);

   Max_oxy_sens_period_r = (uint16)MATHSRV_udtMIN(u16LocalMaxOxySensPeriodR,
                                                  26214);

   u32Localoutput1 = (uint32)(Oxy_sens_period_map_max * Oxy_period_tests)
                     + Max_oxy_sens_period_r;
   u32Localoutput2 = u32Localoutput1 / (Oxy_period_tests + 1);
   Oxy_sens_period_map_max = (uint16)MATHSRV_udtMIN(u32Localoutput2, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidCpThdApvR                           */
/* !Description :  Ici le seuil max apv est calculé et moyenné. De plus, si   */
/*                 l’application GPL/GNV est active, les seuils utilisés sont */
/*                 spécifiques à cette application.                           */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Engine_load;                                                 */
/*  input uint8 Regime_moteur_2_bkpt_map[9];                                  */
/*  input uint16 Engine_load_2_bkpt_map[9];                                   */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Max_oxy_apv_period_gas_map[9][9];                            */
/*  input uint16 Max_oxy_apv_period_map[9][9];                                */
/*  input uint16 Oxy_apv_period_map_max;                                      */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint16 Max_oxy_apv_period_r;                                        */
/*  output uint16 Max_oxy_apv_period_r;                                       */
/*  output uint16 Oxy_apv_period_map_max;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidCpThdApvR(void)
{
   /* 02b_Compute_Thd_Apv */
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalEngine_load;
   uint16 u16LocalMaxApvPerR;
   uint32 u32Localoutput1;
   uint32 u32Localoutput2;


   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Engine_load, u16LocalEngine_load);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(Regime_moteur_2_bkpt_map,
                                               u8LocalRegime_moteur_32,
                                               9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Engine_load_2_bkpt_map,
                                                u16LocalEngine_load,
                                                9);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalMaxApvPerR =
         MATHSRV_u16Interp2d(&Max_oxy_apv_period_gas_map[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             9);
   }
   else
   {
      u16LocalMaxApvPerR = MATHSRV_u16Interp2d(&Max_oxy_apv_period_map[0][0],
                                               u16LocalParaX,
                                               u16LocalParaY,
                                               9);
   }

   Max_oxy_apv_period_r = (uint16)MATHSRV_udtMIN(u16LocalMaxApvPerR, 26214);

   u32Localoutput1 = (uint32)(Oxy_apv_period_map_max * Oxy_period_tests)
                     + Max_oxy_apv_period_r;
   u32Localoutput2 = u32Localoutput1 / (Oxy_period_tests + 1);
   Oxy_apv_period_map_max = (uint16)MATHSRV_udtMIN(u32Localoutput2, 26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidOsPFaultR                           */
/* !Description :  Reporter la période fausse de la sonde riche à l'OS        */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPPERDDIAG_vidRepOsPFlR();                      */
/*  input uint8 Oxy_period_tests;                                             */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Oxy_sens_diag_sample_size_gas_c;                              */
/*  input uint8 Oxy_sens_diag_sample_size_c;                                  */
/*  output uint8 Oxy_period_tests;                                            */
/*  output boolean SenO2Us_bMonRunRaw_OxySensPerd;                            */
/*  output boolean SenO2Us_bMonRunRaw_OxyApvPerd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidOsPFaultR(void)
{
   /* 03_Report_os_period_fault_r */
   uint8  u8LocalExt_stSysGas;
   uint8  u8LocalOxySensDiagSampleSize;
   uint16 u16LocalInc;


   u16LocalInc = (uint16)(Oxy_period_tests + 1);
   Oxy_period_tests = (uint8)MATHSRV_udtMIN(u16LocalInc, 255);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8LocalOxySensDiagSampleSize = Oxy_sens_diag_sample_size_gas_c;
   }
   else
   {
      u8LocalOxySensDiagSampleSize = Oxy_sens_diag_sample_size_c;
   }
   if (Oxy_period_tests >= u8LocalOxySensDiagSampleSize)
   {
      SenO2Us_bMonRunRaw_OxySensPerd = 1;
      SenO2Us_bMonRunRaw_OxyApvPerd = 1;
      HEATSENO2UPPERDDIAG_vidRepOsPFlR();
   }
   else
   {
      SenO2Us_bMonRunRaw_OxySensPerd = 0;
      SenO2Us_bMonRunRaw_OxyApvPerd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidRepOsPFlR                           */
/* !Description :  Calculer la période fausse de la sonde riche               */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPPERDDIAG_vidPerTest();                        */
/*  extf argret void HEATSENO2UPPERDDIAG_vidReInPrTst();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidRepOsPFlR(void)
{
   /* 01_Report_os_period_fault_r */
   HEATSENO2UPPERDDIAG_vidPerTest();
   HEATSENO2UPPERDDIAG_vidReInPrTst();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidPerTest                             */
/* !Description :  Une fois le nombre d’échantillon souhaité atteint, on      */
/*                 effectue la comparaison entre la moyenne des périodes et la*/
/*                 moyenne des seuils.                                        */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Oxy_ups_period;                                              */
/*  input uint16 Oxy_sens_period_map_max;                                     */
/*  input uint16 Oxy_apv_period_map_max;                                      */
/*  output boolean Oxy_sens_period_failure;                                   */
/*  output boolean Oxy_sens_period_apv_failure;                               */
/*  output uint16 SenO2Us_PerDiag_FacMesRaw;                                  */
/*  output uint16 SenO2Us_PerDiag_FacMaxRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidPerTest(void)
{
   /* 01_Period_Test */
   if (Oxy_ups_period >= Oxy_sens_period_map_max)
   {
      Oxy_sens_period_failure = 1;
   }
   else
   {
      Oxy_sens_period_failure = 0;
   }

   if (Oxy_ups_period >= Oxy_apv_period_map_max)
   {
      Oxy_sens_period_apv_failure = 1;
   }
   else
   {
      Oxy_sens_period_apv_failure = 0;
   }

   SenO2Us_PerDiag_FacMesRaw = (uint16)MATHSRV_udtMIN(Oxy_ups_period, 26214);
   SenO2Us_PerDiag_FacMaxRaw = (uint16)MATHSRV_udtMIN(Oxy_sens_period_map_max,
                                                      26214);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidReInPrTst                           */
/* !Description :  Calcul de Os_period_tests_done. Initialisation de          */
/*                 Oxy_period_tests.                                          */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Os_period_tests_done;                                         */
/*  output uint8 Os_period_tests_done;                                        */
/*  output uint8 Oxy_period_tests;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidReInPrTst(void)
{
   /* 02_ReInit_period_tests */
   uint16 u16LocalInc;

   u16LocalInc = (uint16)(Os_period_tests_done + 1);
   Os_period_tests_done = (uint8)MATHSRV_udtMIN(u16LocalInc, 255);

   Oxy_period_tests = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidDiagCompl                           */
/* !Description :  Détecte et comptabilise la fin du diagnostic               */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Os_period_tests_done;                                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 Os_period_tests_done_gas_c;                                   */
/*  input uint8 Os_period_tests_done_c;                                       */
/*  output boolean Oxy_sens_diag_test_completed;                              */
/*  output boolean Oxy_sens_diag_test_finished;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidDiagCompl(void)
{

   boolean bLocalOxy_sens_diag_test_complet;
   boolean bLocalOxy_sens_diag_test_finishe;
   uint8   u8LocalExt_stSysGas;
   uint8   u8LocalOsPeriodTestsDone;


   if (Os_period_tests_done > 0)
   {
      bLocalOxy_sens_diag_test_complet = 1;
   }
   else
   {
      bLocalOxy_sens_diag_test_complet = 0;
   }
   VEMS_vidSET(Oxy_sens_diag_test_completed, bLocalOxy_sens_diag_test_complet);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u8LocalOsPeriodTestsDone = Os_period_tests_done_gas_c;
   }
   else
   {
      u8LocalOsPeriodTestsDone = Os_period_tests_done_c;
   }

   if (Os_period_tests_done >= u8LocalOsPeriodTestsDone)
   {
      bLocalOxy_sens_diag_test_finishe = 1;
   }
   else
   {
      bLocalOxy_sens_diag_test_finishe = 0;
   }
   VEMS_vidSET(Oxy_sens_diag_test_finished, bLocalOxy_sens_diag_test_finishe);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidPMonitor                            */
/* !Description :  Séquenceur du diagnostic OxySensPerd                       */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SenO2Us_bAcvSeqOxySensPerd_C;                               */
/*  input boolean Oxy_sens_period_failure;                                    */
/*  output boolean SenO2Us_bDgoORng_OxySensPerd;                              */
/*  output boolean SenO2Us_bMonWaitRaw_OxySensPerd;                           */
/*  output boolean SenO2Us_bAcvSeqOxySensPerd;                                */
/*  output boolean SenO2Us_bAcvSeqMemOxySensPerd;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidPMonitor(void)
{
   /* 08_Sequ_DiagOxySensPerd_SenO2Us */
   boolean            bLocalGDU_bEndDiagStrtUsHeat;
   boolean            bLocalSenO2Us_bAcvSeqOxySensPerd;
   GDFRM_tenuGDUState u8LocalstDgoUsHeat;


   u8LocalstDgoUsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
   if (  (u8LocalstDgoUsHeat == GDU_ETAT_PRESENT)
      && (SenO2Us_bAcvSeqOxySensPerd_C != 0))
   {
      SenO2Us_bDgoORng_OxySensPerd = 0;
   }
   else
   {
      SenO2Us_bDgoORng_OxySensPerd = Oxy_sens_period_failure;
   }
   bLocalGDU_bEndDiagStrtUsHeat = GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);

   if (SenO2Us_bAcvSeqOxySensPerd_C != 0)
   {
      if (bLocalGDU_bEndDiagStrtUsHeat != 0)
      {
         SenO2Us_bMonWaitRaw_OxySensPerd = 0;
      }
      else
      {
         SenO2Us_bMonWaitRaw_OxySensPerd = 1;
      }
   }
   else
   {
      SenO2Us_bMonWaitRaw_OxySensPerd = 0;
   }

   if (  (bLocalGDU_bEndDiagStrtUsHeat == 0)
      && (Oxy_sens_period_failure != 0))
   {
      bLocalSenO2Us_bAcvSeqOxySensPerd = 1;
   }
   else
   {
      bLocalSenO2Us_bAcvSeqOxySensPerd = 0;
   }
   VEMS_vidSET(SenO2Us_bAcvSeqOxySensPerd, bLocalSenO2Us_bAcvSeqOxySensPerd);

   if (bLocalSenO2Us_bAcvSeqOxySensPerd != 0)
   {
      VEMS_vidSET(SenO2Us_bAcvSeqMemOxySensPerd, 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPPERDDIAG_vidApvPMonit                           */
/* !Description :  Séquenceur du diagnostic OxyApvPerd                        */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SenO2Us_bAcvSeqOxyApvPerd_C;                                */
/*  input boolean Oxy_sens_period_apv_failure;                                */
/*  output boolean SenO2Us_bDgoORng_OxyApvPerd;                               */
/*  output boolean SenO2Us_bMonWaitRaw_OxyApvPerd;                            */
/*  output boolean SenO2Us_bAcvSeqOxyApvPerd;                                 */
/*  output boolean SenO2Us_bAcvSeqMemOxyApvPerd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPPERDDIAG_vidApvPMonit(void)
{
   /* 09_Sequ_DiagOxyApvPerd_SenO2Us  */
   boolean            bLocalGDU_bEndDiagStrtUsHeat;
   boolean            bLocalSenO2Us_bAcvSeqOxyApvPerd;
   GDFRM_tenuGDUState u8LocalstDgoUsHeat;


   u8LocalstDgoUsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
   if (  (u8LocalstDgoUsHeat == GDU_ETAT_PRESENT)
      && (SenO2Us_bAcvSeqOxyApvPerd_C != 0))
   {
      SenO2Us_bDgoORng_OxyApvPerd = 0;
   }
   else
   {
      SenO2Us_bDgoORng_OxyApvPerd = Oxy_sens_period_apv_failure;
   }

   bLocalGDU_bEndDiagStrtUsHeat = GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);
   if (SenO2Us_bAcvSeqOxyApvPerd_C != 0)
   {
      if (bLocalGDU_bEndDiagStrtUsHeat != 0)
      {
         SenO2Us_bMonWaitRaw_OxyApvPerd = 0;
      }
      else
      {
         SenO2Us_bMonWaitRaw_OxyApvPerd = 1;
      }
   }
   else
   {
      SenO2Us_bMonWaitRaw_OxyApvPerd = 0;
   }

   if (  (bLocalGDU_bEndDiagStrtUsHeat == 0)
      && (Oxy_sens_period_apv_failure != 0))
   {
      bLocalSenO2Us_bAcvSeqOxyApvPerd = 1;
   }
   else
   {
      bLocalSenO2Us_bAcvSeqOxyApvPerd = 0;
   }
   VEMS_vidSET(SenO2Us_bAcvSeqOxyApvPerd, bLocalSenO2Us_bAcvSeqOxyApvPerd);

   if (bLocalSenO2Us_bAcvSeqOxyApvPerd != 0)
   {
      VEMS_vidSET(SenO2Us_bAcvSeqMemOxyApvPerd, 1);
   }
}
/*------------------------------- end of file --------------------------------*/