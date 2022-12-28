/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CKMNGIF                                                 */
/* !Description     : CKMNGIF component.                                      */
/*                                                                            */
/* !Module          : CKMNGIF                                                 */
/* !Description     : Interface Gestion Roue Dentée Vilebrequin.              */
/*                                                                            */
/* !File            : CKMNGIF_FCT2.C                                          */
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
/*   1 / CKMNGIF_vidSynchroFound                                              */
/*   2 / CKMNGIF_vidTDCTreatment                                              */
/*   3 / CKMNGIF_vidCountPmh                                                  */
/*   4 / CKMNGIF_vidEnginePeriodMeasure                                       */
/*   5 / CKMNGIF_vidEnginePeriodFind                                          */
/*   6 / CKMNGIF_vidPeriodeCyl                                                */
/*   7 / CKMNGIF_vidEngineSpeedCalc                                           */
/*   8 / CKMNGIF_vidFiltEngineSpeedCalc                                       */
/*   9 / CKMNGIF_vidEngineSpeedDerivCalc                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6884590 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#069167                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/SYNC/CKMNGIF/CkMngIf_fct2.c_v     $*/
/* $Revision::   1.18     $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.H"
#include "CKMNGIF.h"
#include "CKMNGIF_L.h"
#include "CKMNGIF_IM.h"
#include "GDGAR.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidSynchroFound                                    */
/* !Description :  Fonction qui permet la reconnaissance  tardive  d'un       */
/*                 calage moteur  par  la  clé                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cipd_inh_dephia;                                            */
/*  input uint8 Acqui_compteur_de_pmh;                                        */
/*  input uint8 Compteur_de_pmh_raw;                                          */
/*  input uint32 Acqui_periode_moteur;                                        */
/*  output uint16 Compteur_de_pmh;                                            */
/*  output uint16 Ext_ctInj;                                                  */
/*  output uint8 Ext_ctTDC;                                                   */
/*  output uint16 Periode_moteur;                                             */
/*  output uint16 Periode_moteur_calc;                                        */
/*  output uint8 Ext_tiTDC;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidSynchroFound(void)
{
   uint8          u8LocalTdcCounter;
   uint8          u8LocalExt_ctTDC;
   uint8          u8LocalExt_tiTDC;
   uint16         u16LocalPeriode_moteur;
   uint32         u32LocalPeriod;


   if (Cipd_inh_dephia != 0)
   {
      VEMS_vidGET(Acqui_compteur_de_pmh, u8LocalTdcCounter);
   }
   else
   {
      VEMS_vidGET(Compteur_de_pmh_raw, u8LocalTdcCounter);
   }
   VEMS_vidSET(Compteur_de_pmh, (uint16)u8LocalTdcCounter);
   VEMS_vidSET(Ext_ctInj, (uint16)u8LocalTdcCounter);
   u8LocalExt_ctTDC = (uint8)(u8LocalTdcCounter % 4);
   VEMS_vidSET(Ext_ctTDC, u8LocalExt_ctTDC);

   VEMS_vidGET(Acqui_periode_moteur, u32LocalPeriod);
   if (u32LocalPeriod <= 1048552)
   {
      u16LocalPeriode_moteur = (uint16)((u32LocalPeriod + 8) / 16);
   }
   else
   {
      u16LocalPeriode_moteur = 65535;
   }

   VEMS_vidSET(Periode_moteur, u16LocalPeriode_moteur);
   if (u32LocalPeriod <= 8388416)
   {
      Periode_moteur_calc = (uint16)((u32LocalPeriod + 64) / 128);
   }
   else
   {
      Periode_moteur_calc = 65535;
   }

   if (u32LocalPeriod <= 497500)
   {
      u8LocalExt_tiTDC = (uint8)((u32LocalPeriod + 2500) / 5000);
   }
   else
   {
      u8LocalExt_tiTDC = 100;
   }
   VEMS_vidSET(Ext_tiTDC, u8LocalExt_tiTDC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidTDCTreatment                                    */
/* !Description :  Fonction de traitement PMH                                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CKMNGIF_vidCountPmh();                                   */
/*  extf argret void CKMNGIF_vidEnginePeriodMeasure();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidTDCTreatment(void)
{
   CKMNGIF_vidCountPmh();
   CKMNGIF_vidEnginePeriodMeasure();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidCountPmh                                        */
/* !Description :  Le compteur_de_pmh est incrémenté à chaque événement PMH.  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Compteur_de_pmh;                                             */
/*  output uint16 Compteur_de_pmh;                                            */
/*  output uint16 Ext_ctInj;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidCountPmh(void)
{
   uint16 u16LocalExt_ctInj;
   uint16 u16LocalCompteur_de_pmh;


   VEMS_vidGET(Compteur_de_pmh, u16LocalCompteur_de_pmh);
   u16LocalCompteur_de_pmh = (uint16)(u16LocalCompteur_de_pmh + 1);
   VEMS_vidSET(Compteur_de_pmh, u16LocalCompteur_de_pmh);
   u16LocalExt_ctInj = u16LocalCompteur_de_pmh;
   VEMS_vidSET(Ext_ctInj, u16LocalExt_ctInj);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidEnginePeriodMeasure                             */
/* !Description :  Le LdA récupère du LdB la valeur de la période moteur tous */
/*                 les événements PMH. dans le cas du 1er PMH, le LdB évalue  */
/*                 la période moteur à partir de la durée dent.               */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Acqui_periode_moteur;                                        */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output uint16 Periode_moteur;                                             */
/*  output uint16 Periode_moteur_calc;                                        */
/*  output uint8 Ext_tiTDC;                                                   */
/*  output uint16 Ext_nEngTDC;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidEnginePeriodMeasure(void)
{
   uint8          u8LocalExt_tiTDC;
   uint8          u8LocalExt_noCylEng;
   uint16         u16LocalPeriode_moteur;
   uint16         u16LocalExt_nEngTDC;
   uint32         u32LocalPeriod;
   uint32         u32LocalResult;
   uint32         u32LocalDenom;


   VEMS_vidGET(Acqui_periode_moteur, u32LocalPeriod);
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   if (u32LocalPeriod <= 1048552)
   {
      u16LocalPeriode_moteur = (uint16)((u32LocalPeriod + 8) / 16);
   }
   else
   {
      u16LocalPeriode_moteur = 65535;
   }
   VEMS_vidSET(Periode_moteur, u16LocalPeriode_moteur);

   if (u32LocalPeriod <= 8388416)
   {
      Periode_moteur_calc = (uint16)((u32LocalPeriod + 64) / 128);
   }
   else
   {
      Periode_moteur_calc = 65535;
   }
   if (u32LocalPeriod <= 497500)
   {
      u8LocalExt_tiTDC = (uint8)((u32LocalPeriod + 2500) / 5000);
   }
   else
   {
      u8LocalExt_tiTDC = 100;
   }
   VEMS_vidSET(Ext_tiTDC, u8LocalExt_tiTDC);
   if (  (u32LocalPeriod != 0)
      && (u8LocalExt_noCylEng != 0))
   {
      if (u32LocalPeriod > 16843009)
      {
         u32LocalDenom = 4294967295uL;
      }
      else
      {
         u32LocalDenom = u32LocalPeriod * u8LocalExt_noCylEng;
      }

      u32LocalResult = 600000000 / u32LocalDenom;
      u16LocalExt_nEngTDC = (uint16)MATHSRV_udtMIN(u32LocalResult, 8000);
   }
   else
   {
      u16LocalExt_nEngTDC = 0;
   }
   VEMS_vidSET(Ext_nEngTDC, u16LocalExt_nEngTDC);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidEnginePeriodFind                                */
/* !Description :  Le LdB fournit au LdA le compteur de PMH phasé et modulo le*/
/*                 nombre de cylindres                                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Cipd_inh_dephia;                                            */
/*  input uint8 Acqui_compteur_de_pmh;                                        */
/*  input uint8 Compteur_de_pmh_raw;                                          */
/*  input uint8 Table_cyl_phys_ordre_allumage[6];                             */
/*  input uint8 Ext_noCylEng;                                                 */
/*  output uint8 Ext_ctTDC;                                                   */
/*  output uint8 Eng_noCmprCyl;                                               */
/*  output uint8 Eng_noCmbNxtCyl;                                             */
/*  output uint8 Eng_noCmbCyl;                                                */
/*  output uint8 Eng_noCmprNxtCyl;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidEnginePeriodFind(void)
{
   uint8          u8LocalExt_ctTDC;
   uint8          u8LocalExt_noCylEng;
   uint8          u8LocalEng_noCmprCyl;
   uint8          u8LocalEng_noCmbCyl;
   uint8          u8LocalEng_noCmprNxtCyl;
   uint8          u8LocalIgnOrder;
   uint8          u8LocalIdx1;
   uint8          u8LocalIdx2;


   if (Cipd_inh_dephia != 0)
   {
      VEMS_vidGET(Acqui_compteur_de_pmh, u8LocalExt_ctTDC);
   }
   else
   {
      VEMS_vidGET(Compteur_de_pmh_raw, u8LocalExt_ctTDC);
   }
   u8LocalExt_ctTDC = (uint8)(u8LocalExt_ctTDC % 4);
   VEMS_vidSET(Ext_ctTDC, u8LocalExt_ctTDC);

   u8LocalIgnOrder =
      (uint8)MATHSRV_udtMIN(Table_cyl_phys_ordre_allumage[u8LocalExt_ctTDC], 5);
   u8LocalEng_noCmprCyl = (uint8)(u8LocalIgnOrder + 1);
   VEMS_vidSET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
   VEMS_vidSET(Eng_noCmbNxtCyl, u8LocalEng_noCmprCyl);

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   if (u8LocalExt_noCylEng != 0)
   {
      u8LocalIdx1 = (uint8)( ((u8LocalExt_noCylEng + u8LocalExt_ctTDC) - 1)
                           % u8LocalExt_noCylEng);
      u8LocalIdx2 = (uint8)((u8LocalExt_ctTDC + 1) % u8LocalExt_noCylEng);
   }
   else
   {
      u8LocalIdx1  = 0;
      u8LocalIdx2 = 0;
   }
   u8LocalIgnOrder =
      (uint8)MATHSRV_udtMIN(Table_cyl_phys_ordre_allumage[u8LocalIdx1], 5);
   u8LocalEng_noCmbCyl = (uint8)(u8LocalIgnOrder + 1);
   VEMS_vidSET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   u8LocalIgnOrder =
      (uint8)MATHSRV_udtMIN(Table_cyl_phys_ordre_allumage[u8LocalIdx2], 5);
   u8LocalEng_noCmprNxtCyl = (uint8)(u8LocalIgnOrder + 1);
   VEMS_vidSET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidPeriodeCyl                                      */
/* !Description :  Fonction qui permet de fournir le numéro du cylindre en    */
/*                 phase de compression et admission                          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctTDC;                                                    */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Table_cyl_phys_ordre_allumage[6];                             */
/*  output uint8 Eng_noInCyl;                                                 */
/*  output uint8 Eng_noInNxtCyl;                                              */
/*  output uint8 Eng_noInNxtNxtCyl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidPeriodeCyl(void)
{
   uint8   u8LocalCalc;
   uint8   u8LocalCalc1;
   uint8   u8LocalCalc2;
   uint8   u8LocalCalc3;
   uint8   u8LocalExt_ctTDC;
   uint8   u8LocalExt_noCylEng;
   uint16  u16LocalCalc1;
   uint16  u16LocalCalc2;
   uint16  u16LocalCalc3;


   VEMS_vidGET(Ext_ctTDC, u8LocalExt_ctTDC);
   u16LocalCalc1 = (uint16)(u8LocalExt_ctTDC + 1);
   u16LocalCalc2 = (uint16)(u8LocalExt_ctTDC + 2);
   u16LocalCalc3 = (uint16)(u8LocalExt_ctTDC + 3);

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   if (u8LocalExt_noCylEng != 0)
   {
      u8LocalCalc = (uint8)(u16LocalCalc1 % u8LocalExt_noCylEng);
      u8LocalCalc1  = (uint8)MATHSRV_udtMIN(u8LocalCalc, 5);
      u8LocalCalc = (uint8)(u16LocalCalc2 % u8LocalExt_noCylEng);
      u8LocalCalc2 = (uint8)MATHSRV_udtMIN(u8LocalCalc, 5);
      u8LocalCalc = (uint8)(u16LocalCalc3 % u8LocalExt_noCylEng);
      u8LocalCalc3 = (uint8)MATHSRV_udtMIN(u8LocalCalc, 5);
   }
   else
   {
      u8LocalCalc1 = 0;
      u8LocalCalc2 = 0;
      u8LocalCalc3 = 0;
   }

   u8LocalCalc1 =
      (uint8)MATHSRV_udtMIN(Table_cyl_phys_ordre_allumage[u8LocalCalc1], 5);
   u8LocalCalc2 =
      (uint8)MATHSRV_udtMIN(Table_cyl_phys_ordre_allumage[u8LocalCalc2], 5);
   u8LocalCalc3 =
      (uint8)MATHSRV_udtMIN(Table_cyl_phys_ordre_allumage[u8LocalCalc3], 5);
   u8LocalCalc1 = (uint8)(u8LocalCalc1 + 1);
   u8LocalCalc2 = (uint8)(u8LocalCalc2 + 1);
   u8LocalCalc3 = (uint8)(u8LocalCalc3 + 1);

   VEMS_vidSET(Eng_noInCyl, u8LocalCalc1);
   VEMS_vidSET(Eng_noInNxtCyl, u8LocalCalc2);
   VEMS_vidSET(Eng_noInNxtNxtCyl, u8LocalCalc3);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidEngineSpeedCalc                                 */
/* !Description :  A chaque point mort haut combustion, l'applicatif          */
/*                 réceptionne la période moteur qui est  convertie ensuite en*/
/*                 régime moteur.                                             */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04457_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void CKMNGIF_vidEngineSpeedDerivCalc();                       */
/*  extf argret void CKMNGIF_vidFiltEngineSpeedCalc();                        */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Periode_moteur_calc;                                         */
/*  output uint16 Regime_moteur_0_125;                                        */
/*  output uint16 Ext_nEngFineResl;                                           */
/*  output uint16 Regime_moteur;                                              */
/*  output uint8 Regime_moteur_32;                                            */
/*  output uint16 Ext_nEng;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidEngineSpeedCalc(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalRegime_moteur_32;
   uint16 u16LocalExt_nEngFineResl;
   uint16 u16LocalRegime_moteur;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngSpd;
   uint32 u32LocalDenom;
   uint32 u32LocalResult;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   if (  (Periode_moteur_calc != 0)
      && (u8LocalExt_noCylEng != 0))
   {
      u32LocalDenom = (uint32)(Periode_moteur_calc * u8LocalExt_noCylEng);

      u32LocalResult = 37500000uL / u32LocalDenom;
      u16LocalEngSpd = (uint16)MATHSRV_udtMIN(u32LocalResult, 65535);
   }
   else
   {
      u16LocalEngSpd = 0;
   }
   VEMS_vidSET(Regime_moteur_0_125, u16LocalEngSpd);

   u16LocalExt_nEngFineResl = (uint16)(u16LocalEngSpd / 2);
   u16LocalExt_nEngFineResl = (uint16)MATHSRV_udtMIN(u16LocalExt_nEngFineResl,
                                                     32000);
   VEMS_vidSET(Ext_nEngFineResl, u16LocalExt_nEngFineResl);

   u16LocalRegime_moteur = (uint16)(u16LocalEngSpd / 8);
   VEMS_vidSET(Regime_moteur, u16LocalRegime_moteur);

   u8LocalRegime_moteur_32 = (uint8)(u16LocalEngSpd / 256);
   VEMS_vidSET(Regime_moteur_32, u8LocalRegime_moteur_32);

   u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u16LocalRegime_moteur, 7500);
   VEMS_vidSET(Ext_nEng, u16LocalExt_nEng);

   CKMNGIF_vidEngineSpeedDerivCalc();
   CKMNGIF_vidFiltEngineSpeedCalc();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidFiltEngineSpeedCalc                             */
/* !Description :  Fonction qui produit le régime moteur filtré               */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_08_04457_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 CKMNGIF_u16RegimeMoteurPrev[3];                              */
/*  output uint16 CKMNGIF_u16RegimeMoteurPrev[3];                             */
/*  output uint16 Regime_moteur_filtre;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidFiltEngineSpeedCalc(void)
{
   uint16 u16Local_Regime_moteur;
   uint16 u16LocalRegimemoteurfiltre;
   uint32 u32LocalOutputSwitch;
   uint8  u8LocalExt_noCylEng;


   VEMS_vidGET(Regime_moteur, u16Local_Regime_moteur);
   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);
   switch (u8LocalExt_noCylEng)
   {
      case 1:
         /* QAC Warning 2215: QAC Noise */
         u32LocalOutputSwitch = u16Local_Regime_moteur;
         break;

      case 2:
         u32LocalOutputSwitch =
            (uint32)(u16Local_Regime_moteur + CKMNGIF_u16RegimeMoteurPrev[0]);
         break;

      case 3:
         u32LocalOutputSwitch =
            (uint32)(u16Local_Regime_moteur + CKMNGIF_u16RegimeMoteurPrev[0]
                    + CKMNGIF_u16RegimeMoteurPrev[1]);
         break;

      case 4:
         u32LocalOutputSwitch =
           (uint32)(u16Local_Regime_moteur + CKMNGIF_u16RegimeMoteurPrev[0]
                    + CKMNGIF_u16RegimeMoteurPrev[1]
                    + CKMNGIF_u16RegimeMoteurPrev[2]);
         break;

      default:
         u32LocalOutputSwitch =
           (uint32)(u16Local_Regime_moteur + CKMNGIF_u16RegimeMoteurPrev[0]
                    + CKMNGIF_u16RegimeMoteurPrev[1]
                    + CKMNGIF_u16RegimeMoteurPrev[2]);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   CKMNGIF_u16RegimeMoteurPrev[2] = CKMNGIF_u16RegimeMoteurPrev[1];
   CKMNGIF_u16RegimeMoteurPrev[1] = CKMNGIF_u16RegimeMoteurPrev[0];
   CKMNGIF_u16RegimeMoteurPrev[0] = u16Local_Regime_moteur;

   if (u8LocalExt_noCylEng != 0)
   {
      u16LocalRegimemoteurfiltre =
         (uint16)(u32LocalOutputSwitch / u8LocalExt_noCylEng);
   }
   else
   {
      u16LocalRegimemoteurfiltre = 8191;
   }
   VEMS_vidSET(Regime_moteur_filtre, u16LocalRegimemoteurfiltre);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CKMNGIF_vidEngineSpeedDerivCalc                            */
/* !Description :  Cette fonction permet de calculer Engine_speed_derivate et */
/*                 Ext_aEng                                                   */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint16 Periode_moteur_calc;                                         */
/*  input uint16 Periode_moteur_calc_prev;                                    */
/*  output sint8 Engine_speed_derivate;                                       */
/*  output sint16 Ext_aEng;                                                   */
/*  output uint16 Periode_moteur_calc_prev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CKMNGIF_vidEngineSpeedDerivCalc(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalSpeedDer;
   sint16 s16LocalSpeedDer;
   uint32 u32LocalNum;
   uint32 u32LocalPeriode;
   uint32 u32LocalPeriodePrev;
   uint32 u32LocalSpeedDer;


   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   if (u8LocalExt_noCylEng != 0)
   {
      if (Periode_moteur_calc != 0)
      {
         if (Periode_moteur_calc_prev != 0)
         {
            u32LocalNum = 2861022949UL;
            u32LocalNum = u32LocalNum / Periode_moteur_calc;
            u32LocalNum = u32LocalNum / u8LocalExt_noCylEng;
            u32LocalPeriode = u32LocalNum / Periode_moteur_calc;
            u32LocalPeriodePrev = u32LocalNum / Periode_moteur_calc_prev;

            if (u32LocalPeriode >= u32LocalPeriodePrev)
            {
               u32LocalSpeedDer = u32LocalPeriode - u32LocalPeriodePrev;
               s16LocalSpeedDer = (sint16)MATHSRV_udtMIN(u32LocalSpeedDer,
                                                         SINT8_MAX);
            }
            else
            {
               u32LocalSpeedDer = u32LocalPeriodePrev - u32LocalPeriode;
               u8LocalSpeedDer = (uint8)MATHSRV_udtMIN(u32LocalSpeedDer,
                                                       128);
               s16LocalSpeedDer = (sint16)(-(sint16)(u8LocalSpeedDer));
            }
            VEMS_vidSET(Engine_speed_derivate, (sint8)(s16LocalSpeedDer));
         }
         else
         {
            VEMS_vidSET(Engine_speed_derivate, SINT8_MIN);
         }
      }
      else
      {
         VEMS_vidSET(Engine_speed_derivate, SINT8_MAX);
      }

      if (Periode_moteur_calc >= 171)
      {
         if (Periode_moteur_calc_prev != 0)
         {
            u32LocalNum = 2861022949UL;
            u32LocalNum = u32LocalNum / Periode_moteur_calc;
            u32LocalNum = u32LocalNum * 256;
            u32LocalNum = u32LocalNum / u8LocalExt_noCylEng;
            u32LocalPeriode = u32LocalNum / Periode_moteur_calc;
            u32LocalPeriodePrev = u32LocalNum / Periode_moteur_calc_prev;

            if (u32LocalPeriode >= u32LocalPeriodePrev)
            {
               u32LocalSpeedDer = u32LocalPeriode - u32LocalPeriodePrev;
               s16LocalSpeedDer = (sint16)MATHSRV_udtMIN(u32LocalSpeedDer,
                                                         32000);
            }
            else
            {
               u32LocalSpeedDer = u32LocalPeriodePrev - u32LocalPeriode;
               s16LocalSpeedDer = (sint16)MATHSRV_udtMIN(u32LocalSpeedDer,
                                                         32000);
               s16LocalSpeedDer = (sint16)(-(s16LocalSpeedDer));
            }
         }
         else
         {
            s16LocalSpeedDer = -32000;
         }
         VEMS_vidSET(Ext_aEng, s16LocalSpeedDer);
      }
      else
      {
         VEMS_vidSET(Ext_aEng, 32000);
      }
   }
   else
   {
      VEMS_vidSET(Engine_speed_derivate, 0);
      VEMS_vidSET(Ext_aEng, 0);
   }

   Periode_moteur_calc_prev =  Periode_moteur_calc;
}
/*------------------------------- end of file --------------------------------*/