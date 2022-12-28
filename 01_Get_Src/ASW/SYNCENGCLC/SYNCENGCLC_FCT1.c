/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCENGCLC                                              */
/* !Description     : SYNCENGCLC Component                                    */
/*                                                                            */
/* !Module          : SYNCENGCLC                                              */
/* !Description     : CALCUL DU REGIME RECENTRE.                              */
/*                                                                            */
/* !File            : SYNCENGCLC_FCT1.C                                       */
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
/*   1 / SYNCENGCLC_vidResetnEngClc                                           */
/*   2 / SYNCENGCLC_vidInitOutput                                             */
/*   3 / SYNCENGCLC_vidActLearningCorr                                        */
/*   4 / SYNCENGCLC_vidCalculAreaEngClc                                       */
/*   5 / SYNCENGCLC_vidCalculCorrEngClc                                       */
/*   6 / SYNCENGCLC_vidApplicationCorr                                        */
/*   7 / SYNCENGCLC_vidEngineSpeedMemr                                        */
/*   8 / SYNCENGCLC_vidEchtSumCylAllAreas                                     */
/*   9 / SYNCENGCLC_vidCorrectionArea                                         */
/*   10 / SYNCENGCLC_vidAppliCor                                              */
/*                                                                            */
/* !Reference   : V02 NT 09 06456 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SYNC/SYNCENGCLC/SYNCENGCLC_FCT1.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   07 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCENGCLC.h"
#include "SYNCENGCLC_L.h"
#include "SYNCENGCLC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidResetnEngClc                                 */
/* !Description :  Au reset calculateur, le régime recentré est égal au régime*/
/*                 moteur.                                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_nEngClc;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidResetnEngClc(void)
{
   /*F01_Reset_nEngClc*/
   VEMS_vidSET(Ext_nEngClc, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidInitOutput                                   */
/* !Description :  Initialisation des variables produites dans le module.     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Sync_bCondLrnCornEngClc;                                   */
/*  output boolean SYNCENGCLC_bTimeOutInit;                                   */
/*  output uint8 Sync_ctTiCutOff;                                             */
/*  output boolean SYNCENGCLC_bTimeOut;                                       */
/*  output uint16 Sync_nCycEngMemrCyl1;                                       */
/*  output uint16 Sync_nCycEngMemrCyl2;                                       */
/*  output uint16 Sync_nCycEngMemrCyl3;                                       */
/*  output uint8 SYNCENGCLC_u8NoArAcvnEngClc;                                 */
/*  output st95 SYNCENGCLC_StAssignEngArea;                                   */
/*  output uint8 Sync_no_BodyCorSatEngClc;                                    */
/*  output uint8 Sync_no_ArAcvnEngClc;                                        */
/*  output boolean Sync_bEndMemrnCycEng;                                      */
/*  output uint8 Sync_ct_MemrnEngCyl;                                         */
/*  output uint16 Sync_nMemrCyl1;                                             */
/*  output uint16 Sync_nMemrCyl2;                                             */
/*  output uint16 Sync_nMemrCyl3;                                             */
/*  output uint8 Sync_no_MemrArAcvnEngClc;                                    */
/*  output uint8 Sync_no_PrevMemrArAcvnEngClc;                                */
/*  output uint32 Sync_nSumCyl1ArAcvPrev;                                     */
/*  output uint32 Sync_nSumCyl2ArAcvPrev;                                     */
/*  output uint32 Sync_nSumCyl3ArAcvPrev;                                     */
/*  output uint8 SYNCENGCLC_u8NumberActiveZonPrev;                            */
/*  output boolean Sync_bProtClcSum;                                          */
/*  output uint32 Sync_nSumCyl1ArAcv;                                         */
/*  output uint32 Sync_ct_SampleCyl1ArAcv;                                    */
/*  output uint32 Sync_nSumCyl2ArAcv;                                         */
/*  output uint32 Sync_ct_SampleCyl2ArAcv;                                    */
/*  output uint32 Sync_nSumCyl3ArAcv;                                         */
/*  output uint32 Sync_ct_SampleCyl3ArAcv;                                    */
/*  output sint8 Sync_nCorContnsCylCmb;                                       */
/*  output boolean SYNCENGCLC_bHysOut;                                        */
/*  output boolean Sync_bIdlSpdInsdArAcv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidInitOutput(void)
{
   /*F02_Activation_Learning_Correction*/
   Sync_bCondLrnCornEngClc = 0;
   SYNCENGCLC_bTimeOutInit = 0;
   Sync_ctTiCutOff = 0;
   SYNCENGCLC_bTimeOut = 0;

   /*F04_Calculate_Correction_nEngClc*/
   Sync_nCycEngMemrCyl1 = 0;
   Sync_nCycEngMemrCyl2 = 0;
   Sync_nCycEngMemrCyl3 = 0;

   /*F01_nEng_Inside_Area*/
   SYNCENGCLC_u8NoArAcvnEngClc = 0;

   /*F02_Assignation_nEng_Area*/
   SYNCENGCLC_StAssignEngArea = INIT_ENG_SPEED_IN_AREA;
   Sync_no_BodyCorSatEngClc = 0;
   Sync_no_ArAcvnEngClc = 0;

   /*F03_Memr_nEng_cycle_mot */
   Sync_bEndMemrnCycEng = 0;
   Sync_ct_MemrnEngCyl = 0;
   Sync_nMemrCyl1 = 0;
   Sync_nMemrCyl2 = 0;
   Sync_nMemrCyl3 = 0;
   Sync_no_MemrArAcvnEngClc = 0;
   Sync_no_PrevMemrArAcvnEngClc = 0;

   /*F02_Echant_and_moy_Cyl_123_Areas*/
   Sync_nSumCyl1ArAcvPrev = 0;
   Sync_nSumCyl2ArAcvPrev = 0;
   Sync_nSumCyl3ArAcvPrev = 0;
   SYNCENGCLC_u8NumberActiveZonPrev = 0;

   /*F00_ProtectionCalcSomme*/
   Sync_bProtClcSum = 0;

   /*F01_Echant_and_sum_Cyl_1_Areas*/
   Sync_nSumCyl1ArAcv = 0;
   Sync_ct_SampleCyl1ArAcv = 0;

   /*F02_Echant_and_sum_Cyl_2_Areas*/
   Sync_nSumCyl2ArAcv = 0;
   Sync_ct_SampleCyl2ArAcv = 0;

   /*F03_Echant_and_sum_Cyl_3_Areas*/
   Sync_nSumCyl3ArAcv = 0;
   Sync_ct_SampleCyl3ArAcv = 0;

   /*F05_Application_Correction*/
   Sync_nCorContnsCylCmb = 0;
   SYNCENGCLC_bHysOut = 0;

   /*F01_AppliCor */
   Sync_bIdlSpdInsdArAcv = 0;
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidActLearningCorr                              */
/* !Description :  L’apprentissage des corrections est réalisé sur des        */
/*                 décélérations naturelles du véhicule en coupure            */
/*                 d’injection.                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Coupure_inj_ess_1;                                          */
/*  input boolean Coupure_inj_ess_2;                                          */
/*  input boolean Coupure_inj_ess_3;                                          */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 Gear_engaged;                                                 */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  input boolean SYNCENGCLC_bTimeOutInit;                                    */
/*  input uint8 Sync_TiCutOffLrnCornEngClc_C;                                 */
/*  input uint8 Sync_ctTiCutOff;                                              */
/*  input sint16 Sync_tCo_LrnCornEngClc_C;                                    */
/*  input uint8 Sync_no_GearLrnCornEngClc_C;                                  */
/*  input boolean SYNCENGCLC_bTimeOut;                                        */
/*  output boolean SYNCENGCLC_bTimeOutInit;                                   */
/*  output uint8 Sync_ctTiCutOff;                                             */
/*  output boolean SYNCENGCLC_bTimeOut;                                       */
/*  output boolean Sync_bCondLrnCornEngClc;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidActLearningCorr(void)
{
   boolean bLocalCoupure_inj_ess_1;
   boolean bLocalCoupure_inj_ess_2;
   boolean bLocalCoupure_inj_ess_3;
   boolean bLocalExt_bBrkPedPrss;
   boolean bLocalbInhEngCorLrn;
   boolean bLocalTimeOutInitPrev;
   uint8   u8LocalGear_engaged;
   sint16  s16LocalExt_tCoMes;


   VEMS_vidGET(Coupure_inj_ess_1 ,bLocalCoupure_inj_ess_1);
   VEMS_vidGET(Coupure_inj_ess_2 ,bLocalCoupure_inj_ess_2);
   VEMS_vidGET(Coupure_inj_ess_3 ,bLocalCoupure_inj_ess_3);
   VEMS_vidGET(Ext_tCoMes ,s16LocalExt_tCoMes);
   VEMS_vidGET(Gear_engaged ,u8LocalGear_engaged);
   VEMS_vidGET(Ext_bBrkPedPrss ,bLocalExt_bBrkPedPrss);
   bLocalbInhEngCorLrn = GDGAR_bGetFRM(FRM_FRM_INHENGCORLRN);

   bLocalTimeOutInitPrev = SYNCENGCLC_bTimeOutInit;
   if (  (bLocalCoupure_inj_ess_1 != 0)
      && (bLocalCoupure_inj_ess_2 != 0)
      && (bLocalCoupure_inj_ess_3 != 0))
   {
      SYNCENGCLC_bTimeOutInit = 1;
   }
   else
   {
      SYNCENGCLC_bTimeOutInit = 0;
   }

   if (  (bLocalTimeOutInitPrev == 0)
      && (SYNCENGCLC_bTimeOutInit != 0))
   {
      Sync_ctTiCutOff =
         (uint8)MATHSRV_udtMIN(Sync_TiCutOffLrnCornEngClc_C, 100);

      if (Sync_ctTiCutOff == 0)
      {
         SYNCENGCLC_bTimeOut = 1;
      }
      else
      {
         SYNCENGCLC_bTimeOut = 0;
      }
   }
   else
   {
      if (Sync_ctTiCutOff > 0)
      {
         Sync_ctTiCutOff = (uint8)(Sync_ctTiCutOff - 1);
         if (Sync_ctTiCutOff == 0)
         {
            SYNCENGCLC_bTimeOut = 1;
         }
         else
         {
            SYNCENGCLC_bTimeOut = 0;
         }
      }
   }

   if (  (s16LocalExt_tCoMes > Sync_tCo_LrnCornEngClc_C)
      && (u8LocalGear_engaged > Sync_no_GearLrnCornEngClc_C)
      && (bLocalExt_bBrkPedPrss == 0)
      && (bLocalbInhEngCorLrn == 0)
      && (SYNCENGCLC_bTimeOutInit != 0)
      && (SYNCENGCLC_bTimeOut != 0))
   {
      Sync_bCondLrnCornEngClc = 1;
   }
   else
   {
      Sync_bCondLrnCornEngClc = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidCalculAreaEngClc                             */
/* !Description :  On définit 20 plages de régimes moteur contiguës           */
/*                 calibrables (équi-réparties et bornées Sync_ThdnEngClcMax_C*/
/*                 et Sync_ThdnEngClcMin_C).                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Sync_ThdnEngClcMin_C;                                        */
/*  input uint16 Sync_ThdnEngClcMax_C;                                        */
/*  output uint16 Sync_prm_nThdnEngClc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidCalculAreaEngClc(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalVar;
   uint32 u32LocalVar;


   for (u8LocalIndex = 0; u8LocalIndex <= NB_ACTIVE_ZONE; u8LocalIndex++)
   {
      u32LocalVar = (uint32)( ( ( Sync_ThdnEngClcMin_C
                                * (20 - u8LocalIndex))
                              + ( Sync_ThdnEngClcMax_C
                                * u8LocalIndex)
                              + 10)
                            / 20);
      u16LocalVar = (uint16)MATHSRV_udtMIN(u32LocalVar, 8191);
      Sync_prm_nThdnEngClc[u8LocalIndex] = u16LocalVar;
   }

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidCalculCorrEngClc                             */
/* !Description :  Cet ensemble effectue l’apprentissage des corrections par  */
/*                 zone et par cylindre.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidEngineSpeedMemr();                         */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCENGCLC_vidEchtSumCylAllAreas();                      */
/*  extf argret void SYNCENGCLC_vidCorrectionArea();                          */
/*  input uint16 Sync_nEngClc;                                                */
/*  input uint16 Sync_ThdMvCorMin_C;                                          */
/*  input boolean Sync_bEndMemrnCycEng;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidCalculCorrEngClc(void)
{
   uint16 u16LocalSync_nEngClc;


   /*F01_Mem_nEng*/
   SYNCENGCLC_vidEngineSpeedMemr();

   VEMS_vidGET(Sync_nEngClc, u16LocalSync_nEngClc);
   if (u16LocalSync_nEngClc > Sync_ThdMvCorMin_C)
   {
      /*F02_Echant_and_moy_Cyl_123_Areas*/
      if (Sync_bEndMemrnCycEng != 0)
      {
         SYNCENGCLC_vidEchtSumCylAllAreas();
      }
      /*F03_Cor_Area*/
      SYNCENGCLC_vidCorrectionArea();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidApplicationCorr                              */
/* !Description :  Ce sous-système effectue l’application des corrections au  */
/*                 régime courant.                                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCENGCLC_vidAppliCor();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Sync_nEngClc;                                                */
/*  input uint16 Sync_ThdMvCorMin_C;                                          */
/*  input uint8 Sync_ThdCorHys_C;                                             */
/*  input boolean SYNCENGCLC_bHysOut;                                         */
/*  input sint8 Sync_nCorContnsCylCmb;                                        */
/*  output boolean SYNCENGCLC_bHysOut;                                        */
/*  output uint16 Ext_nEngClc;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidApplicationCorr(void)
{
   uint16 u16LocalSync_nEngClc;
   uint16 u16LocalExt_nEngClc;
   uint32 u32LocalThreshold2;
   sint32 s32LocalThreshold1;
   sint32 s32LocalValue2;


   VEMS_vidGET(Sync_nEngClc, u16LocalSync_nEngClc);

   s32LocalThreshold1 = (sint32)(Sync_ThdMvCorMin_C - Sync_ThdCorHys_C);
   u32LocalThreshold2 = (uint32)(Sync_ThdMvCorMin_C + Sync_ThdCorHys_C);

   if (SYNCENGCLC_bHysOut == 0)
   {
      if (u16LocalSync_nEngClc > u32LocalThreshold2)
      {
         SYNCENGCLC_bHysOut = 1;
      }
      else
      {
         SYNCENGCLC_bHysOut = 0;
      }
   }
   else
   {
      if (u16LocalSync_nEngClc <= s32LocalThreshold1)
      {
         SYNCENGCLC_bHysOut = 0;
      }
      else
      {
         SYNCENGCLC_bHysOut = 1;
      }
   }
   if (SYNCENGCLC_bHysOut != 0)
   {
      SYNCENGCLC_vidAppliCor();
      s32LocalValue2 = (sint32)(u16LocalSync_nEngClc + Sync_nCorContnsCylCmb);
      u16LocalExt_nEngClc = (uint16)MATHSRV_udtMIN(s32LocalValue2, 8000);
   }
   else
   {
      u16LocalExt_nEngClc =
         (uint16)MATHSRV_udtMIN(u16LocalSync_nEngClc, 8000);
   }
   VEMS_vidSET(Ext_nEngClc, u16LocalExt_nEngClc);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEngineSpeedMemr                              */
/* !Description :  Ce sous système permet de déterminer la zone où se situe le*/
/*                 régime moteur courant et le numéro de la plage active ainsi*/
/*                 que le numéro du groupe de correction et de mémoriser le   */
/*                 régime moteur par cylindre correspondant à la phase de     */
/*                 combustion.                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCENGCLC_vidEngSpdInsideArea();                        */
/*  extf argret void SYNCENGCLC_vidAssigEngSpdArea();                         */
/*  extf argret void SYNCENGCLC_vidEngSpdMemrCylMot();                        */
/*  input uint16 Sync_nEngClc;                                                */
/*  input uint16 Sync_ThdnEngClcMax_C;                                        */
/*  input uint16 Sync_ThdnEngClcMin_C;                                        */
/*  input boolean Sync_bCondLrnCornEngClc;                                    */
/*  input uint16 Sync_ThdMvCorMin_C;                                          */
/*  output boolean Sync_bnEngInsdAr;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEngineSpeedMemr(void)
{
   uint16 u16LocalSync_nEngClc;


   VEMS_vidGET(Sync_nEngClc, u16LocalSync_nEngClc);

   /*F01_nEng_Inside_Area*/
   if (  (u16LocalSync_nEngClc <= Sync_ThdnEngClcMax_C)
      && (u16LocalSync_nEngClc >= Sync_ThdnEngClcMin_C))
   {
      SYNCENGCLC_vidEngSpdInsideArea();
      Sync_bnEngInsdAr = 1;
   }
   else
   {
      Sync_bnEngInsdAr = 0;
   }

   /*F02_Assignation_nEng_Area*/
   SYNCENGCLC_vidAssigEngSpdArea();

   /*F03_Memr_nEng_cycle_mot*/
   if (  (Sync_bCondLrnCornEngClc != 0)
      && (u16LocalSync_nEngClc > Sync_ThdMvCorMin_C))
   {
      SYNCENGCLC_vidEngSpdMemrCylMot();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEchtSumCylAllAreas                           */
/* !Description :  Ces 3 blocs effectuent, pour chaque cylindre, les sommes   */
/*                 des régimes avec leur nombre d’échantillon.                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidProtectCalcSomme();                        */
/*  extf argret void SYNCENGCLC_vidEchtSumCyl_1_Areas();                      */
/*  extf argret void SYNCENGCLC_vidEchtSumCyl_2_Areas();                      */
/*  extf argret void SYNCENGCLC_vidEchtSumCyl_3_Areas();                      */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*  input uint8 SYNCENGCLC_u8NumberActiveZonPrev;                             */
/*  input uint32 Sync_nSumCyl1ArAcv;                                          */
/*  input uint32 Sync_nSumCyl2ArAcv;                                          */
/*  input uint32 Sync_nSumCyl3ArAcv;                                          */
/*  output boolean Sync_bChgnoArAcvnEngClc;                                   */
/*  output uint32 Sync_nSumCyl1ArAcvPrev;                                     */
/*  output uint32 Sync_nSumCyl2ArAcvPrev;                                     */
/*  output uint32 Sync_nSumCyl3ArAcvPrev;                                     */
/*  output uint8 SYNCENGCLC_u8NumberActiveZonPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEchtSumCylAllAreas(void)
{
   if (Sync_no_ArAcvnEngClc != SYNCENGCLC_u8NumberActiveZonPrev)
   {
      Sync_bChgnoArAcvnEngClc = 1;
   }
   else
   {
      Sync_bChgnoArAcvnEngClc = 0;
   }
   /*F00_ProtectionCalcSomme*/
   SYNCENGCLC_vidProtectCalcSomme();

   /*F01_Echant_and_sum_Cyl_1_Areas*/
   SYNCENGCLC_vidEchtSumCyl_1_Areas();

   /*F02_Echant_and_sum_Cyl_2_Areas*/
   SYNCENGCLC_vidEchtSumCyl_2_Areas();

   /*F03_Echant_and_sum_Cyl_3_Areas*/
   SYNCENGCLC_vidEchtSumCyl_3_Areas();

   Sync_nSumCyl1ArAcvPrev = Sync_nSumCyl1ArAcv;
   Sync_nSumCyl2ArAcvPrev = Sync_nSumCyl2ArAcv;
   Sync_nSumCyl3ArAcvPrev = Sync_nSumCyl3ArAcv;
   SYNCENGCLC_u8NumberActiveZonPrev =
      (uint8)MATHSRV_udtMIN(Sync_no_ArAcvnEngClc, 20);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidCorrectionArea                               */
/* !Description :  Cette fonction calcule la moyenne des sommes et détermine  */
/*                 les corrections par cylindre à apporter au régime courant  */
/*                 et permet d’affecter ces corrections et le booléen         */
/*                 d’apprentissage à leurs vecteurs correspondants.           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidCalculMean();                              */
/*  extf argret void SYNCENGCLC_vidCalculCorrection();                        */
/*  extf argret void SYNCENGCLC_vidCorrectAssignment();                       */
/*  input boolean Sync_bLrnCorArAcv;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidCorrectionArea(void)
{
   /*F01_Calc_Mean*/
   SYNCENGCLC_vidCalculMean();

   if (Sync_bLrnCorArAcv != 0)
   {
      /*F02_Calc_Cor*/
      SYNCENGCLC_vidCalculCorrection();

      /*F03_Assignment*/
      SYNCENGCLC_vidCorrectAssignment();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidAppliCor                                     */
/* !Description :  Cette fonction permet d'appliquer les corrections au régime*/
/*                 courant.                                                   */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SYNCENGCLC_vidMngIdlSpdInsidArea();                      */
/*  extf argret void SYNCENGCLC_vidContinuityRules();                         */
/*  extf argret void SYNCENGCLC_vidApplication();                             */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidAppliCor(void)
{
   /*F01_ManagerIdlSpdInsideArea*/
   if (Sync_no_ArAcvnEngClc != 0)
   {
      SYNCENGCLC_vidMngIdlSpdInsidArea();
   }

   /*F02_ReglesContinuite*/
   SYNCENGCLC_vidContinuityRules();

   /*F03_Application*/
   SYNCENGCLC_vidApplication();
}

/*------------------------------end of file-----------------------------------*/
