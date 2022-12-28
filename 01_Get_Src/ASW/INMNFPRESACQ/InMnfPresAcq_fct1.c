/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INMNFPRESACQ                                            */
/* !Description     : INMNFPRESACQ Component                                  */
/*                                                                            */
/* !Module          : INMNFPRESACQ                                            */
/* !Description     : ACQUISITION DE LA PRESSION COLLECTEUR                   */
/*                                                                            */
/* !File            : INMNFPRESACQ_FCT1.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / INMNFPRESACQ_vidInit                                                 */
/*   2 / INMNFPRESACQ_vidAcqPressManifld                                      */
/*   3 / INMNFPRESACQ_vidDiagPressManifld                                     */
/*   4 / INMNFPRESACQ_vidPresElectricDiag                                     */
/*   5 / INMNFPRESACQ_vidFormPressManifld                                     */
/*   6 / INMNFPRESACQ_vidArbPressManifld                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6525158 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/INMNFPRESACQ/InMnfPresAcq_fct1.c_v$*/
/* $Revision::   1.8                                                         $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INMNFPRESACQ.h"
#include "INMNFPRESACQ_L.h"
#include "INMNFPRESACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESACQ_vidInit                                       */
/* !Description :  Les valeurs de la pression collecteur sont initialisés à la*/
/*                 valeur de la pression atmosphérique.                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirPres_upDsThrFilt;                                         */
/*  input uint16 Ext_pDsThrIni_C;                                             */
/*  output uint16 AirPres_upDsThrFilt;                                        */
/*  output uint32 INMNFPRESACQ_u32upDsThrFiltMEM;                             */
/*  output uint16 Ext_pDsThr;                                                 */
/*  output uint16 Ext_pDsThrMesSI;                                            */
/*  output uint8 Ext_pDsThrMesWRV;                                            */
/*  output uint16 AirPres_uDsThrPresSenVoltAvrPre1;                           */
/*  output uint16 AirPres_uDsThrPresSenVoltAvrPre2;                           */
/*  output uint16 AirPres_uDsThrPresSenVoltAvrPre3;                           */
/*  output uint16 Io_map_manifold_press_measured;                             */
/*  output sint16 Ext_pDsThrMes;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESACQ_vidInit(void)
{
   uint16  u16LocalExt_pDsThrMesSI;
   sint16  s16LocalExt_pDsThrMes;


   AirPres_upDsThrFilt = 0;
   INMNFPRESACQ_u32upDsThrFiltMEM = (uint32)(AirPres_upDsThrFilt * 256);
   Ext_pDsThr = Ext_pDsThrIni_C;
   u16LocalExt_pDsThrMesSI = Ext_pDsThrIni_C;
   VEMS_vidSET(Ext_pDsThrMesSI, u16LocalExt_pDsThrMesSI);
   VEMS_vidSET(Ext_pDsThrMesWRV, 100);
   AirPres_uDsThrPresSenVoltAvrPre1 = 0;
   AirPres_uDsThrPresSenVoltAvrPre2 = 0;
   AirPres_uDsThrPresSenVoltAvrPre3 = 0;
   VEMS_vidSET(Io_map_manifold_press_measured, u16LocalExt_pDsThrMesSI);

   s16LocalExt_pDsThrMes = (sint16)(((u16LocalExt_pDsThrMesSI * 2) + 13) / 25);
   VEMS_vidSET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESACQ_vidAcqPressManifld                            */
/* !Description :  La tension brute renvoyée par le capteur est normalisée en */
/*                 fonction de la tension d’alimentation du capteur,avant     */
/*                 d’être envoyée au LdA.                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_12_01656_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint16 Ext_uptAirSenPwr;                                            */
/*  input uint16 Acquisition_press_coll;                                      */
/*  input uint16 AirPres_uDsThrMesAvr;                                        */
/*  input uint16 AirPres_uDsThrPresSenVoltAvrPre1;                            */
/*  input uint16 AirPres_uDsThrPresSenVoltAvrPre2;                            */
/*  input uint16 AirPres_uDsThrPresSenVoltAvrPre3;                            */
/*  input uint16 Ext_upDsThrMes;                                              */
/*  output uint16 Pression_air_result_ad_conv;                                */
/*  output uint16 AirPres_uDsThrMesAvr;                                       */
/*  output uint16 Ext_upDsThrMes;                                             */
/*  output uint16 AirPres_uDsThrPresSenVoltAvrPre3;                           */
/*  output uint16 AirPres_uDsThrPresSenVoltAvrPre2;                           */
/*  output uint16 AirPres_uDsThrPresSenVoltAvrPre1;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESACQ_vidAcqPressManifld(void)
{
   boolean bLocalCoPTSt_bEngRun;
   uint16  u16LocalExt_uptAirSenPwr;
   uint16  u16LocalAcquisition_press_coll;
   uint32  u32LocalSum;
   uint32  u32LocalPressionAirResultConv;


   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   VEMS_vidGET(Ext_uptAirSenPwr, u16LocalExt_uptAirSenPwr);
   VEMS_vidGET(Acquisition_press_coll, u16LocalAcquisition_press_coll);

   VEMS_vidSET(Pression_air_result_ad_conv, u16LocalAcquisition_press_coll);
   if (u16LocalExt_uptAirSenPwr != 0)
   {
      u32LocalPressionAirResultConv =
         (uint32)( (u16LocalAcquisition_press_coll * 4096)
                 / u16LocalExt_uptAirSenPwr);
      AirPres_uDsThrMesAvr =
         (uint16)MATHSRV_udtMIN(u32LocalPressionAirResultConv, 4095);
   }
   else
   {
      AirPres_uDsThrMesAvr = 4095;
   }
   if (bLocalCoPTSt_bEngRun !=0)
   {
      u32LocalSum =  ( AirPres_uDsThrMesAvr
                     + AirPres_uDsThrPresSenVoltAvrPre1
                     + AirPres_uDsThrPresSenVoltAvrPre2
                     + AirPres_uDsThrPresSenVoltAvrPre3);
      Ext_upDsThrMes = (uint16)((u32LocalSum + 2) / 4);
   }
   else
   {
      Ext_upDsThrMes = AirPres_uDsThrMesAvr;
   }

   Ext_upDsThrMes = (uint16)MATHSRV_udtMIN(Ext_upDsThrMes, 4095);

   AirPres_uDsThrPresSenVoltAvrPre3 =
      (uint16)MATHSRV_udtMIN(AirPres_uDsThrPresSenVoltAvrPre2, 4095);
   AirPres_uDsThrPresSenVoltAvrPre2 =
      (uint16)MATHSRV_udtMIN(AirPres_uDsThrPresSenVoltAvrPre1, 4095);
   AirPres_uDsThrPresSenVoltAvrPre1 = AirPres_uDsThrMesAvr;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESACQ_vidDiagPressManifld                           */
/* !Description :  Les diagnostics éléctriques pour les valeurs haute et basse*/
/*                 sur signal de pression collecteur sont activés lorsque la  */
/*                 chaîne d’acquisition est activée et si aucun défaut n’est  */
/*                 confirmé.                                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_12_01656_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf argret void INMNFPRESACQ_vidPresElectricDiag();                      */
/*  output boolean Ext_bMonRunScp_pDsThrMes;                                  */
/*  output boolean Ext_bMonRunScg_pDsThrMes;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESACQ_vidDiagPressManifld(void)
{
   boolean bLocalInhDiag_pDsThrMes;


   bLocalInhDiag_pDsThrMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PDSTHRMES);

   if (bLocalInhDiag_pDsThrMes == 0)
   {
      Ext_bMonRunScp_pDsThrMes = 1;
      Ext_bMonRunScg_pDsThrMes=1;
      INMNFPRESACQ_vidPresElectricDiag();
   }
   else
   {
      Ext_bMonRunScp_pDsThrMes = 0;
      Ext_bMonRunScg_pDsThrMes=0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESACQ_vidPresElectricDiag                           */
/* !Description :  A chaque acquisition de la tensions collecteur, un         */
/*                 diagnostic est effectué sur la validité de la nouvelle     */
/*                 mesure, à l’aide de seuils calibrables, permettant         */
/*                 l’actualisation des indicateurs de défauts.                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_12_01656_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Pression_air_result_ad_conv;                                 */
/*  input uint16 AirPres_uDgoScp_pDsThrMes_C;                                 */
/*  input uint16 AirPres_uDgoScg_pDsThrMes_C;                                 */
/*  output boolean Ext_bDgoScp_pDsThrMes;                                     */
/*  output boolean Ext_bDgoScg_pDsThrMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESACQ_vidPresElectricDiag(void)
{
   uint16 u16LocalPressionAirResultConv;


   VEMS_vidGET(Pression_air_result_ad_conv, u16LocalPressionAirResultConv);

   if (u16LocalPressionAirResultConv > AirPres_uDgoScp_pDsThrMes_C)
   {
      Ext_bDgoScp_pDsThrMes = 1;
   }
   else
   {
      Ext_bDgoScp_pDsThrMes = 0;
   }
   if (u16LocalPressionAirResultConv < AirPres_uDgoScg_pDsThrMes_C)
   {
      Ext_bDgoScg_pDsThrMes = 1;
   }
   else
   {
      Ext_bDgoScg_pDsThrMes = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESACQ_vidFormPressManifld                           */
/* !Description :  Un filtre, de type ordre 1 avec gain calibrable en fonction*/
/*                 du régime, est appliquée sur la tension renvoyée par le    */
/*                 capteur en valeur de pression collecteur.                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_12_01656_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirPres_pDsThrMes_nEng_A[10];                                */
/*  input uint8 AirPres_rFilGainDsThrPres_nEng_T[10];                         */
/*  input uint32 INMNFPRESACQ_u32upDsThrFiltMEM;                              */
/*  input uint16 Ext_upDsThrMes;                                              */
/*  input uint16 AirPres_upDsThrFilt;                                         */
/*  input uint16 AirPres_uDsThrPresSenVolt_A[2];                              */
/*  input uint16 AirPres_pDsThrPresSenVolt_T[2];                              */
/*  input uint16 Ext_pDsThr;                                                  */
/*  output uint16 AirPres_upDsThrFilt;                                        */
/*  output uint32 INMNFPRESACQ_u32upDsThrFiltMEM;                             */
/*  output uint16 Ext_pDsThr;                                                 */
/*  output uint8 Ext_pDsThrMesWRV;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESACQ_vidFormPressManifld(void)
{
   uint8   u8LocalGain;
   uint8   u8LocalFilterGain;
   uint8   u8LocalExt_pDsThrMesWRV;
   uint16  u16Local;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalAirPres_upDsThrFilt;
   uint16  u16LocalGain;
   uint16  u16LocalPara1;
   uint16  u16LocalInterp;
   uint16  u16LocalBKPTSup;
   uint16  u16LocalBKPTInf;
   uint16  u16LocalMapSup;
   uint16  u16LocalMapInf;
   uint16  u16LocalInterpolation;
   uint16  u16LocalSiteInterpolation;
   uint32  u32LocalInterp;
   uint32  u32LocalDeltaValue;
   uint32  u32LocalInterpolation;
   uint32  u32LocalResultValue;
   sint32  s32LocalInterpolation;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalPara1 =
      MATHSRV_u16CalcParaIncAryU16(AirPres_pDsThrMes_nEng_A,
                                   u16LocalExt_nEng,
                                   10);
   u8LocalGain =
      MATHSRV_u8Interp1d(AirPres_rFilGainDsThrPres_nEng_T,
                         u16LocalPara1);
   u16LocalGain = (uint16)(u8LocalGain + 1);
   if (u16LocalGain < 100)
   {
      u8LocalFilterGain = (uint8)(((u16LocalGain * 64) + 13) / 25);
      u16LocalAirPres_upDsThrFilt =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &INMNFPRESACQ_u32upDsThrFiltMEM,
                                        Ext_upDsThrMes);
      AirPres_upDsThrFilt =
         (uint16)MATHSRV_udtMIN(u16LocalAirPres_upDsThrFilt, 4095);
   }
   else
   {
      AirPres_upDsThrFilt = (uint16)MATHSRV_udtMIN(Ext_upDsThrMes, 4095);
      INMNFPRESACQ_u32upDsThrFiltMEM = (uint32)(AirPres_upDsThrFilt * 256);
   }

   u16LocalInterp = 0;
   if (AirPres_uDsThrPresSenVolt_A[1] >= AirPres_uDsThrPresSenVolt_A[0])
   {
      u16LocalBKPTSup = AirPres_uDsThrPresSenVolt_A[1];
      u16LocalBKPTInf = AirPres_uDsThrPresSenVolt_A[0];
      u16LocalMapSup = AirPres_pDsThrPresSenVolt_T[1];
      u16LocalMapInf = AirPres_pDsThrPresSenVolt_T[0];
   }
   else
   {
      u16LocalBKPTSup = AirPres_uDsThrPresSenVolt_A[0];
      u16LocalBKPTInf = AirPres_uDsThrPresSenVolt_A[1];
      u16LocalMapSup = AirPres_pDsThrPresSenVolt_T[0];
      u16LocalMapInf = AirPres_pDsThrPresSenVolt_T[1];
   }
   if (AirPres_uDsThrPresSenVolt_A[1] != AirPres_uDsThrPresSenVolt_A[0])
   {
      if (AirPres_upDsThrFilt >= u16LocalBKPTSup)
      {
         u16LocalInterp = u16LocalMapSup;
      }
      if (AirPres_upDsThrFilt < u16LocalBKPTInf)
      {
         u16LocalInterp = u16LocalMapInf;
      }
      if (  (AirPres_upDsThrFilt < u16LocalBKPTSup)
         && (AirPres_upDsThrFilt >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of AirPres_upDsThrFilt with
            AirPres_uDsThrPresSenVolt_A */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS(AirPres_upDsThrFilt -
                                   AirPres_uDsThrPresSenVolt_A[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation =(uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on AirPres_pDsThrPresSenVolt_T */

         s32LocalInterpolation = (sint32)AirPres_pDsThrPresSenVolt_T[1] -
                                 (sint32)AirPres_pDsThrPresSenVolt_T[0];
         u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
         }
         else
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)((sint32)AirPres_pDsThrPresSenVolt_T[0] +
                     s32LocalInterpolation);
         u16LocalInterp = (uint16)u32LocalResultValue;
      }
   }
   else
   {
      u16LocalInterp = AirPres_pDsThrPresSenVolt_T[0];
   }
   u32LocalInterp = (uint32)(u16LocalInterp + 1);
   Ext_pDsThr = (uint16)MATHSRV_udtMIN(u32LocalInterp, 65535);

   u8LocalExt_pDsThrMesWRV =  (uint8)(Ext_pDsThr / 125);
   VEMS_vidSET(Ext_pDsThrMesWRV, u8LocalExt_pDsThrMesWRV);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESACQ_vidArbPressManifld                            */
/* !Description :  En présence de défauts, la valeur de la pression collecteur*/
/*                 n’est plus acquise mais figée à sa dernière valeur valide. */
/*                 Si le défaut est confirmée la pression est égale à une     */
/*                 valeur de repli dépendant de la synchronisation du moteur. */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_R_12_01656_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AirPres_pDsThrPresAcq_nEng_A[9];                             */
/*  input uint16 AirPres_pDsThrDftv_nEng_T[9];                                */
/*  input boolean Moteur_synchronise;                                         */
/*  input uint16 Acq_pDsThrPresDftv_SyncEng;                                  */
/*  input uint16 Acq_pDsThrPresDftv_NoSync_C;                                 */
/*  input boolean Ext_bDgoScg_pDsThrMes;                                      */
/*  input boolean Ext_bDgoScp_pDsThrMes;                                      */
/*  input uint16 Ext_pDsThrMesSI;                                             */
/*  input uint16 Ext_pDsThr;                                                  */
/*  output uint16 Acq_pDsThrPresDftv_SyncEng;                                 */
/*  output uint16 Ext_pDsThrMesSI;                                            */
/*  output uint16 Io_map_manifold_press_measured;                             */
/*  output sint16 Ext_pDsThrMes;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESACQ_vidArbPressManifld(void)
{
   boolean bLocalInhDiag_pDsThrMes;
   boolean bLocalAcvDft_pDsThrMes;
   boolean bLocalMoteur_synchronise;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalPara;
   uint16  u16Local_Ext_pDsThrMesSI;
   sint16  s16LocalExt_pDsThrMes;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalPara =
      MATHSRV_u16CalcParaIncAryU16(AirPres_pDsThrPresAcq_nEng_A,
                                   u16LocalExt_nEng,
                                   9);
   Acq_pDsThrPresDftv_SyncEng = MATHSRV_u16Interp1d(AirPres_pDsThrDftv_nEng_T,
                                                    u16LocalPara);
   bLocalAcvDft_pDsThrMes = GDGAR_bGetFRM(FRM_FRM_ACVDFT_PDSTHRMES);
   if (bLocalAcvDft_pDsThrMes !=0)
   {
      VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
      if (bLocalMoteur_synchronise !=0)
      {
         u16Local_Ext_pDsThrMesSI = Acq_pDsThrPresDftv_SyncEng;
      }
      else
      {
         u16Local_Ext_pDsThrMesSI = Acq_pDsThrPresDftv_NoSync_C;
      }
   }
   else
   {
      bLocalInhDiag_pDsThrMes = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PDSTHRMES);
      if (  (Ext_bDgoScg_pDsThrMes != 0)
         || (Ext_bDgoScp_pDsThrMes != 0)
         || (bLocalInhDiag_pDsThrMes != 0))
      {
         VEMS_vidGET(Ext_pDsThrMesSI, u16Local_Ext_pDsThrMesSI);
      }
      else
      {
         u16Local_Ext_pDsThrMesSI = Ext_pDsThr;
      }
   }
   VEMS_vidSET(Ext_pDsThrMesSI, u16Local_Ext_pDsThrMesSI);
   VEMS_vidSET(Io_map_manifold_press_measured, u16Local_Ext_pDsThrMesSI);
   s16LocalExt_pDsThrMes = (sint16)(((u16Local_Ext_pDsThrMesSI * 2) + 13) / 25);
   VEMS_vidSET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
}
/*-------------------------------- end of file -------------------------------*/