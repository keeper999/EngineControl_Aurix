/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PRESDIAGCOH                                             */
/* !Description     : PRESDIAGCOH Component                                   */
/*                                                                            */
/* !Module          : PRESDIAGCOH                                             */
/* !Description     : PRESSURE SENSORS COHERENCY DIAGNOSIS                    */
/*                                                                            */
/* !File            : PRESDIAGCOH_FCT1.C                                      */
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
/*   1 / PRESDIAGCOH_vidInitOutput                                            */
/*   2 / PRESDIAGCOH_vidInitialization                                        */
/*   3 / PRESDIAGCOH_vidCounterKeyOn                                          */
/*   4 / PRESDIAGCOH_vidInhDiagSecKeyOn                                       */
/*   5 / PRESDIAGCOH_vidPressureDiagnosis                                     */
/*   6 / PRESDIAGCOH_vidCohDiagEnaCond                                        */
/*   7 / PRESDIAGCOH_vidCoherenciesDiag                                       */
/*   8 / PRESDIAGCOH_vidCalcPresureDrifts                                     */
/*   9 / PRESDIAGCOH_vidOilPSDrift                                            */
/*   10 / PRESDIAGCOH_vidAtmospherPSDrift                                     */
/*                                                                            */
/* !Reference   : V02 NT 12 01298 / 04                                        */
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
#include "PRESDIAGCOH.h"
#include "PRESDIAGCOH_L.h"
#include "PRESDIAGCOH_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidInitOutput                                  */
/* !Description :  Initialisation des sorties du module PRESDIAGCOH.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 PRESDIAGCOH_u8Oil_ctKeyOn;                                   */
/*  output uint16 PRESDIAGCOH_u16OilTimerCount;                               */
/*  output boolean DgSen_bOilPrssSupORng;                                     */
/*  output uint16 PRESDIAGCOH_u16OilTimer1Count;                              */
/*  output boolean DgSen_bOilPrssSdwnORng;                                    */
/*  output boolean PRESDIAGCOH_bOilTimerOut;                                  */
/*  output boolean PRESDIAGCOH_bOilTimer1Out;                                 */
/*  output uint16 PRESDIAGCOH_u16AtmTimerCount;                               */
/*  output boolean DgSen_bAirPrssExtSup;                                      */
/*  output uint16 PRESDIAGCOH_u16AtmTimer1Count;                              */
/*  output boolean DgSen_bAirPrssExtSdwn;                                     */
/*  output boolean PRESDIAGCOH_bAtmTimerOut;                                  */
/*  output boolean PRESDIAGCOH_bAtmTimer1Out;                                 */
/*  output uint16 PRESDIAGCOH_u16UpstrmTimerCount;                            */
/*  output boolean DgSen_bUsThrPrssSup;                                       */
/*  output uint16 PRESDIAGCOH_u16UpstrmTimer1Count;                           */
/*  output boolean DgSen_bUsThrPrssSdwn;                                      */
/*  output boolean PRESDIAGCOH_bUpstrmTimerOut;                               */
/*  output boolean PRESDIAGCOH_bUpstrmTimer1Out;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidInitOutput(void)
{
   /*F01_Compteur_KeyOn*/
   PRESDIAGCOH_u8Oil_ctKeyOn = 0;

   /* F01_oil_pressure_sensor_drift */
   PRESDIAGCOH_u16OilTimerCount = 0;
   DgSen_bOilPrssSupORng = 0;
   PRESDIAGCOH_u16OilTimer1Count = 0;
   DgSen_bOilPrssSdwnORng = 0;
   PRESDIAGCOH_bOilTimerOut = 0;
   PRESDIAGCOH_bOilTimer1Out = 0;

   /* F02_atmospheric_pressure_sensor_drift */
   PRESDIAGCOH_u16AtmTimerCount = 0;
   DgSen_bAirPrssExtSup = 0;
   PRESDIAGCOH_u16AtmTimer1Count = 0;
   DgSen_bAirPrssExtSdwn = 0;
   PRESDIAGCOH_bAtmTimerOut = 0;
   PRESDIAGCOH_bAtmTimer1Out = 0;

   /* F03_upstream_throttle_pressure_sensor_drift */
   PRESDIAGCOH_u16UpstrmTimerCount = 0;
   DgSen_bUsThrPrssSup = 0;
   PRESDIAGCOH_u16UpstrmTimer1Count = 0;
   DgSen_bUsThrPrssSdwn = 0;
   PRESDIAGCOH_bUpstrmTimerOut = 0;
   PRESDIAGCOH_bUpstrmTimer1Out = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidInitialization                              */
/* !Description :  Les variables Oil_ctKeyOn, Oil_ctKeyOn_Prev et             */
/*                 Oil_bInhDiagSecondKOn sont initialisées à zéro lors de     */
/*                 l'événement Reset.                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 Oil_ctKeyOn;                                                 */
/*  output uint8 Oil_ctKeyOn_Prev;                                            */
/*  output boolean Oil_bInhDiagSecondKOn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidInitialization(void)
{
   /*F00_Initialization*/
   Oil_ctKeyOn = 0;
   Oil_ctKeyOn_Prev = 0;
   Oil_bInhDiagSecondKOn = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidCounterKeyOn                                */
/* !Description :  Incrémentation du compteur  Oil_ctKeyOn_Counter, à chaque  */
/*                 KeyOn.                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Oil_ctKeyOn_Prev;                                             */
/*  output uint8 PRESDIAGCOH_u8Oil_ctKeyOn;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidCounterKeyOn(void)
{
   /* F01_Compteur_KeyOn */
   uint16 u16LocalTransitCount;


   u16LocalTransitCount = (uint16)(Oil_ctKeyOn_Prev + 1);
   PRESDIAGCOH_u8Oil_ctKeyOn = (uint8)MATHSRV_udtMIN(u16LocalTransitCount, 255);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidInhDiagSecKeyOn                             */
/* !Description :  Le compteur Oil_ctKeyOn_Counter est initialisé à           */
/*                 zéro,lorsque l'état de l'engin est différent de l'état     */
/*                 stop. Après un Premier démarrage du moteur, une inhibition */
/*                 est envoyé                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPTStNew_stEng;                                              */
/*  input uint8 Oil_ctKeyOn;                                                  */
/*  input uint8 PRESDIAGCOH_u8Oil_ctKeyOn;                                    */
/*  output uint8 Oil_ctKeyOn_Prev;                                            */
/*  output uint8 Oil_ctKeyOn;                                                 */
/*  output boolean Oil_bInhDiagSecondKOn;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidInhDiagSecKeyOn(void)
{
   uint8 u8LocalCoPTStNew_stEng;


   /*F02_InhDiagSecondKeyOn*/
   VEMS_vidGET(CoPTStNew_stEng, u8LocalCoPTStNew_stEng);
   Oil_ctKeyOn_Prev = Oil_ctKeyOn;
   if (u8LocalCoPTStNew_stEng != MOTEUR_ARRETE)
   {
      Oil_ctKeyOn = 0;
      Oil_bInhDiagSecondKOn = 1;
   }
   else
   {
      Oil_ctKeyOn = PRESDIAGCOH_u8Oil_ctKeyOn;
      if (Oil_ctKeyOn > 1)
      {
         Oil_bInhDiagSecondKOn = 1;
      }
      else
      {
         Oil_bInhDiagSecondKOn = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidPressureDiagnosis                           */
/* !Description :  Définition du diagnostic de cohérence de pression.         */
/*                 Activation des capteurs de diagnostic de cohérence de      */
/*                 pression correspondants                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PRESDIAGCOH_vidCohDiagEnaCond();                         */
/*  extf argret void PRESDIAGCOH_vidCoherenciesDiag();                        */
/*  input boolean DgSen_bAcvCohDiagPresSen;                                   */
/*  output boolean DgSen_bMonRunUsThrPrssSup;                                 */
/*  output boolean DgSen_bMonRunUsThrPrssSdwn;                                */
/*  output boolean DgSen_bMonRunOilPrssSupORng;                               */
/*  output boolean DgSen_bMonRunOilPrssSdwnORng;                              */
/*  output boolean DgSen_bMonRunAirPrssExtSup;                                */
/*  output boolean DgSen_bMonRunAirPrssExtSdwn;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidPressureDiagnosis(void)
{
   /* F01_Pressure_Sensors_Coherency_Diag_Ena_Condition*/
   PRESDIAGCOH_vidCohDiagEnaCond();

   DgSen_bMonRunUsThrPrssSup = DgSen_bAcvCohDiagPresSen;
   DgSen_bMonRunUsThrPrssSdwn = DgSen_bAcvCohDiagPresSen;
   DgSen_bMonRunOilPrssSupORng = DgSen_bAcvCohDiagPresSen;
   DgSen_bMonRunOilPrssSdwnORng = DgSen_bAcvCohDiagPresSen;
   DgSen_bMonRunAirPrssExtSup = DgSen_bAcvCohDiagPresSen;
   DgSen_bMonRunAirPrssExtSdwn = DgSen_bAcvCohDiagPresSen;

   if (DgSen_bAcvCohDiagPresSen !=0)
   {
      /* F02_Coherencies_Diagnosis*/
      PRESDIAGCOH_vidCoherenciesDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidCohDiagEnaCond                              */
/* !Description :  Calcule de  DgSen_bAcvCohDiagPresSen, booléen d'activation */
/*                 du diagnostic de cohérence de pression                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_12_01298_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input uint16 DgSen_tOil_A[8];                                             */
/*  input uint16 DgSen_tiEngModStpThd_T[8];                                   */
/*  input boolean CoSync_bDetNNull;                                           */
/*  input uint32 EOM_tiEngStop;                                               */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input boolean Oil_bInhDiagSecondKOn;                                      */
/*  output boolean DgSen_bAcvCohDiagPresSen;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidCohDiagEnaCond(void)
{
   /* F01_Pressure_Sensors_Coherency_Diag_Ena_Condition */
   boolean bLocalCoSync_bDetNNull;
   boolean bLocalCtrl_bOilPropPresAcq;
   boolean bLocalInhDiag_pOilMes;
   uint16  u16LocalExt_tOilMes;
   uint16  u16LocalCalcPara;
   sint16  s16LocalExt_tOilMes;
   uint32  u32LocalEOM_tiEngStop;
   uint32  u32LocalEOM_tiEngStop1;
   uint16  u16LocalInterp1D;


   /* Interpolation 1D */
   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
   s16LocalExt_tOilMes = (sint16)(s16LocalExt_tOilMes + 500);
   u16LocalExt_tOilMes = (uint16)MATHSRV_udtMAX(s16LocalExt_tOilMes, 0);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(DgSen_tOil_A,
                                                   u16LocalExt_tOilMes,
                                                   8);
   u16LocalInterp1D = MATHSRV_u16Interp1d(&DgSen_tiEngModStpThd_T[0],
                                          u16LocalCalcPara);


   /* Production of DgSen_bAcvCohDiagPresSen */
   VEMS_vidGET(CoSync_bDetNNull, bLocalCoSync_bDetNNull);
   VEMS_vidGET(EOM_tiEngStop, u32LocalEOM_tiEngStop);
   VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
   bLocalInhDiag_pOilMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_POILMES);

   if (u32LocalEOM_tiEngStop > 655)
   {
      u32LocalEOM_tiEngStop1 = 65536;
   }
   else
   {
      u32LocalEOM_tiEngStop1 = u32LocalEOM_tiEngStop * 100;
   }

   if (  (bLocalCoSync_bDetNNull != 0)
      && (u32LocalEOM_tiEngStop1 > u16LocalInterp1D)
      && (Oil_bInhDiagSecondKOn == 0)
      && (bLocalCtrl_bOilPropPresAcq != 0)
      && (bLocalInhDiag_pOilMes == 0))
   {
      DgSen_bAcvCohDiagPresSen = 1;
   }
   else
   {
      DgSen_bAcvCohDiagPresSen = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidCoherenciesDiag                             */
/* !Description :  Calcule des différences absolues entre les trois pressions.*/
/*                  Détection des dérives des capteurs de pressions           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_12_01298_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PRESDIAGCOH_vidCalcPresureDrifts();                      */
/*  extf argret void PRESDIAGCOH_vidOilPSDrift();                             */
/*  extf argret void PRESDIAGCOH_vidAtmospherPSDrift();                       */
/*  extf argret void PRESDIAGCOH_vidUpstrmThrPSDrift();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidCoherenciesDiag(void)
{
   /* F00_Calculate_Presure_Drifts */
   PRESDIAGCOH_vidCalcPresureDrifts();
   /* F01_oil_pressure_sensor_drift */
   PRESDIAGCOH_vidOilPSDrift();
   /* F02_atmospheric_pressure_sensor_drift */
   PRESDIAGCOH_vidAtmospherPSDrift();
   /* F03_upstream_throttle_pressure_sensor_drift */
   PRESDIAGCOH_vidUpstrmThrPSDrift();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidCalcPresureDrifts                           */
/* !Description :  Calcule des différences absolues entre les trois pressions:*/
/*                 Pression d'huile, pression d'étranglement en amont, et la  */
/*                 pression atmosphérique.                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 Ext_pOilMes;                                                 */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  output sint16 DgSen_pDelta_pAirExt_pOil;                                  */
/*  output sint16 DgSen_pDelta_pAirExt_pUsThrFil;                             */
/*  output sint16 DgSen_pDelta_pOil_pUsThrFil;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidCalcPresureDrifts(void)
{
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalExt_pOilMes;
   uint16 u16LocalTrbAct_pUsThrFil;
   sint32 s32LocalDeltaAirExtOil;
   sint32 s32LocalDeltaAirExtUsThrFil;
   sint32 s32LocalDeltaOilUsThrFil;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   VEMS_vidGET(Ext_pOilMes, u16LocalExt_pOilMes);
   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbAct_pUsThrFil);

   /* Production of DgSen_pDelta_pAirExt_pOil */
   s32LocalDeltaAirExtOil = (sint32)( (16 * u16LocalExt_pAirExtMes)
                                    - (125 * u16LocalExt_pOilMes));
   s32LocalDeltaAirExtOil = s32LocalDeltaAirExtOil / 16;
   DgSen_pDelta_pAirExt_pOil =
      (sint16)MATHSRV_udtCLAMP(s32LocalDeltaAirExtOil, -5000, 5000);

   /* Production of DgSen_pDelta_pAirExt_pUsThrFil */
   s32LocalDeltaAirExtUsThrFil = (sint32)( (25 * u16LocalExt_pAirExtMes)
                                         - (2 * u16LocalTrbAct_pUsThrFil));
   s32LocalDeltaAirExtUsThrFil = s32LocalDeltaAirExtUsThrFil / 25;
   DgSen_pDelta_pAirExt_pUsThrFil =
      (sint16)MATHSRV_udtCLAMP(s32LocalDeltaAirExtUsThrFil, -5000, 5000);

   /* Production of DgSen_pDelta_pOil_pUsThrFil */
   s32LocalDeltaOilUsThrFil =  (sint32)( (3125 * u16LocalExt_pOilMes)
                                       - (32 * u16LocalTrbAct_pUsThrFil));
   s32LocalDeltaOilUsThrFil = s32LocalDeltaOilUsThrFil / 400;
   DgSen_pDelta_pOil_pUsThrFil =
      (sint16)MATHSRV_udtCLAMP(s32LocalDeltaOilUsThrFil, -5000, 5000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidOilPSDrift                                  */
/* !Description :  Calcule de la dérive négative et positive du capteur de la */
/*                 pression d'huile.                                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 DgSen_pDelta_pAirExt_pOil;                                   */
/*  input boolean DgSen_bOilPrssSupORng;                                      */
/*  input sint16 DgSen_pDelta_pOil_pUsThrFil;                                 */
/*  input uint16 DgSen_pDifMaxOilUsThrThd_C;                                  */
/*  input uint16 DgSen_pDifMaxOilAirExtThd_C;                                 */
/*  input uint16 Oil_tiDlyDriftPos_pOilThd_C;                                 */
/*  input uint16 PRESDIAGCOH_u16OilTimerCount;                                */
/*  input boolean PRESDIAGCOH_bOilTimerOut;                                   */
/*  input boolean DgSen_bOilPrssSdwnORng;                                     */
/*  input uint16 DgSen_pDifMaxAirExtOilThd_C;                                 */
/*  input uint16 DgSen_pDifMaxUsThrOilThd_C;                                  */
/*  input uint16 Oil_tiDlyDriftNeg_pOilThd_C;                                 */
/*  input uint16 PRESDIAGCOH_u16OilTimer1Count;                               */
/*  input boolean PRESDIAGCOH_bOilTimer1Out;                                  */
/*  output boolean DgSen_bOilPrssSupORng;                                     */
/*  output uint16 PRESDIAGCOH_u16OilTimerCount;                               */
/*  output boolean PRESDIAGCOH_bOilTimerOut;                                  */
/*  output boolean DgSen_bDgoOilPrssSupORng;                                  */
/*  output boolean DgSen_bOilPrssSdwnORng;                                    */
/*  output uint16 PRESDIAGCOH_u16OilTimer1Count;                              */
/*  output boolean PRESDIAGCOH_bOilTimer1Out;                                 */
/*  output boolean DgSen_bDgoOilPrssSdwnORng;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidOilPSDrift(void)
{
   boolean bLocalTimerInitPrev;
   boolean bLocalTimer1InitPrev;
   sint32  s32LocalDeltaAirExtOil;
   sint32  s32LocalDeltaOilUsThrFil;


   /* Production of DgSen_bDgoOilPrssSupORng */
   s32LocalDeltaAirExtOil = (sint32)((- 1) * DgSen_pDelta_pAirExt_pOil);
   bLocalTimerInitPrev = DgSen_bOilPrssSupORng;
   if (  (DgSen_pDelta_pOil_pUsThrFil > DgSen_pDifMaxOilUsThrThd_C)
      && (s32LocalDeltaAirExtOil > DgSen_pDifMaxOilAirExtThd_C))
   {
      DgSen_bOilPrssSupORng = 1;
   }
   else
   {
      DgSen_bOilPrssSupORng = 0;
   }

   if (  (bLocalTimerInitPrev == 0)
      && (DgSen_bOilPrssSupORng != 0))
   {
      PRESDIAGCOH_u16OilTimerCount = Oil_tiDlyDriftPos_pOilThd_C;
      if (PRESDIAGCOH_u16OilTimerCount == 0)
      {
         PRESDIAGCOH_bOilTimerOut = 1;
      }
      else
      {
         PRESDIAGCOH_bOilTimerOut = 0;
      }
   }
   else
   {
      if (PRESDIAGCOH_u16OilTimerCount > 0)
      {
         PRESDIAGCOH_u16OilTimerCount =
            (uint16)(PRESDIAGCOH_u16OilTimerCount - 1);
         if (PRESDIAGCOH_u16OilTimerCount == 0)
         {
            PRESDIAGCOH_bOilTimerOut = 1;
         }
         else
         {
            PRESDIAGCOH_bOilTimerOut = 0;
         }
      }
   }

   if (  (PRESDIAGCOH_bOilTimerOut != 0)
      && (DgSen_bOilPrssSupORng != 0))
   {
      DgSen_bDgoOilPrssSupORng = 1;
   }
   else
   {
      DgSen_bDgoOilPrssSupORng = 0;
   }

   /* Production of DgSen_bDgoOilPrssSdwnORng */
   bLocalTimer1InitPrev = DgSen_bOilPrssSdwnORng;
   s32LocalDeltaOilUsThrFil = (sint32)((- 1) * DgSen_pDelta_pOil_pUsThrFil);
   if (  (DgSen_pDelta_pAirExt_pOil > DgSen_pDifMaxAirExtOilThd_C)
      && (s32LocalDeltaOilUsThrFil > DgSen_pDifMaxUsThrOilThd_C ))
   {
      DgSen_bOilPrssSdwnORng = 1;
   }
   else
   {
      DgSen_bOilPrssSdwnORng = 0;
   }

   if (  (bLocalTimer1InitPrev == 0)
      && (DgSen_bOilPrssSdwnORng != 0))
   {
      PRESDIAGCOH_u16OilTimer1Count = Oil_tiDlyDriftNeg_pOilThd_C;
      if (PRESDIAGCOH_u16OilTimer1Count == 0)
      {
         PRESDIAGCOH_bOilTimer1Out = 1;
      }
      else
      {
         PRESDIAGCOH_bOilTimer1Out = 0;
      }
   }
   else
   {
      if (PRESDIAGCOH_u16OilTimer1Count > 0)
      {
         PRESDIAGCOH_u16OilTimer1Count =
               (uint16)(PRESDIAGCOH_u16OilTimer1Count - 1);
         if (PRESDIAGCOH_u16OilTimer1Count == 0)
         {
            PRESDIAGCOH_bOilTimer1Out = 1;
         }
         else
         {
            PRESDIAGCOH_bOilTimer1Out = 0;
         }
      }
   }

   if (  (PRESDIAGCOH_bOilTimer1Out != 0)
      && (DgSen_bOilPrssSdwnORng != 0))
   {
      DgSen_bDgoOilPrssSdwnORng = 1;
   }
   else
   {
      DgSen_bDgoOilPrssSdwnORng = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PRESDIAGCOH_vidAtmospherPSDrift                            */
/* !Description :  Calcule de la dérive négative et positive du capteur de    */
/*                 pression atmosphérique.                                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean DgSen_bAirPrssExtSup;                                       */
/*  input sint16 DgSen_pDelta_pAirExt_pUsThrFil;                              */
/*  input uint16 DgSen_pDifMaxAirExtUsThrThd_C;                               */
/*  input sint16 DgSen_pDelta_pAirExt_pOil;                                   */
/*  input uint16 DgSen_pDifMaxAirExtOilThd_C;                                 */
/*  input uint16 Oil_tiDlyDriftPos_pAirExtThd_C;                              */
/*  input uint16 PRESDIAGCOH_u16AtmTimerCount;                                */
/*  input boolean PRESDIAGCOH_bAtmTimerOut;                                   */
/*  input boolean DgSen_bAirPrssExtSdwn;                                      */
/*  input uint16 DgSen_pDifMaxOilAirExtThd_C;                                 */
/*  input uint16 DgSen_pDifMaxUsThrAirExtThd_C;                               */
/*  input uint16 Oil_tiDlyDriftNeg_pAirExtThd_C;                              */
/*  input uint16 PRESDIAGCOH_u16AtmTimer1Count;                               */
/*  input boolean PRESDIAGCOH_bAtmTimer1Out;                                  */
/*  output boolean DgSen_bAirPrssExtSup;                                      */
/*  output uint16 PRESDIAGCOH_u16AtmTimerCount;                               */
/*  output boolean PRESDIAGCOH_bAtmTimerOut;                                  */
/*  output boolean DgSen_bDgoAirPrssExtSup;                                   */
/*  output boolean DgSen_bAirPrssExtSdwn;                                     */
/*  output uint16 PRESDIAGCOH_u16AtmTimer1Count;                              */
/*  output boolean PRESDIAGCOH_bAtmTimer1Out;                                 */
/*  output boolean DgSen_bDgoAirPrssExtSdwn;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PRESDIAGCOH_vidAtmospherPSDrift(void)
{
   boolean bLocalTimerInitPrev;
   boolean bLocalTimer1InitPrev;
   sint32  s32LocalDeltaAirExtOil;
   sint32  s32LocalDeltaAirExtUsThrFil;


   /* Production of DgSen_bDgoAirPrssExtSup */
   bLocalTimerInitPrev = DgSen_bAirPrssExtSup;
   if (  (DgSen_pDelta_pAirExt_pUsThrFil > DgSen_pDifMaxAirExtUsThrThd_C)
      && (DgSen_pDelta_pAirExt_pOil > DgSen_pDifMaxAirExtOilThd_C))
   {
      DgSen_bAirPrssExtSup = 1;
   }
   else
   {
      DgSen_bAirPrssExtSup = 0;
   }

   if (  (bLocalTimerInitPrev == 0)
      && (DgSen_bAirPrssExtSup != 0))
   {
      PRESDIAGCOH_u16AtmTimerCount = Oil_tiDlyDriftPos_pAirExtThd_C;
      if (PRESDIAGCOH_u16AtmTimerCount == 0)
      {
         PRESDIAGCOH_bAtmTimerOut = 1;
      }
      else
      {
         PRESDIAGCOH_bAtmTimerOut = 0;
      }
   }
   else
   {
      if (PRESDIAGCOH_u16AtmTimerCount > 0)
      {
         PRESDIAGCOH_u16AtmTimerCount =
            (uint16)(PRESDIAGCOH_u16AtmTimerCount - 1);
         if (PRESDIAGCOH_u16AtmTimerCount == 0)
         {
            PRESDIAGCOH_bAtmTimerOut = 1;
         }
         else
         {
            PRESDIAGCOH_bAtmTimerOut = 0;
         }
      }
   }

   if (  (PRESDIAGCOH_bAtmTimerOut != 0)
      && (DgSen_bAirPrssExtSup != 0))
   {
      DgSen_bDgoAirPrssExtSup = 1;
   }
   else
   {
      DgSen_bDgoAirPrssExtSup = 0;
   }

   /* Production of DgSen_bDgoAirPrssExtSdwn */
   bLocalTimer1InitPrev = DgSen_bAirPrssExtSdwn;
   s32LocalDeltaAirExtOil = (sint32)((- 1) * DgSen_pDelta_pAirExt_pOil);
   s32LocalDeltaAirExtUsThrFil =
      (sint32)((- 1) * DgSen_pDelta_pAirExt_pUsThrFil);
   if (  (s32LocalDeltaAirExtOil > DgSen_pDifMaxOilAirExtThd_C)
      && (s32LocalDeltaAirExtUsThrFil > DgSen_pDifMaxUsThrAirExtThd_C))
   {
      DgSen_bAirPrssExtSdwn = 1;
   }
   else
   {
      DgSen_bAirPrssExtSdwn = 0;
   }

   if (  (bLocalTimer1InitPrev == 0)
      && (DgSen_bAirPrssExtSdwn != 0))
   {
      PRESDIAGCOH_u16AtmTimer1Count = Oil_tiDlyDriftNeg_pAirExtThd_C;
      if (PRESDIAGCOH_u16AtmTimer1Count == 0)
      {
         PRESDIAGCOH_bAtmTimer1Out = 1;
      }
      else
      {
         PRESDIAGCOH_bAtmTimer1Out = 0;
      }
   }
   else
   {
      if (PRESDIAGCOH_u16AtmTimer1Count > 0)
      {
         PRESDIAGCOH_u16AtmTimer1Count =
            (uint16)(PRESDIAGCOH_u16AtmTimer1Count - 1);

         if (PRESDIAGCOH_u16AtmTimer1Count == 0)
         {
            PRESDIAGCOH_bAtmTimer1Out = 1;
         }
         else
         {
            PRESDIAGCOH_bAtmTimer1Out = 0;
         }
      }
   }

   if (  (PRESDIAGCOH_bAtmTimer1Out != 0)
      && (DgSen_bAirPrssExtSdwn != 0))
   {
      DgSen_bDgoAirPrssExtSdwn = 1;
   }
   else
   {
      DgSen_bDgoAirPrssExtSdwn = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/