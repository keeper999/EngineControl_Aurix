/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INMNFPRESDIAG                                           */
/* !Description     : INMNFPRESDIAG Component.                                */
/*                                                                            */
/* !Module          : INMNFPRESDIAG                                           */
/* !Description     : Diagnostic fonctionnel de la pression collecteur.       */
/*                                                                            */
/* !File            : INMNFPRESDIAG_FCT3.C                                    */
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
/*   1 / INMNFPRESDIAG_vidDftPres_GrdPres                                     */
/*   2 / INMNFPRESDIAG_vidRefPressFreeze                                      */
/*   3 / INMNFPRESDIAG_vidDetectionEnabled                                    */
/*   4 / INMNFPRESDIAG_vidDftPres_Reinit                                      */
/*   5 / INMNFPRESDIAG_vidPrsDiagStallIni                                     */
/*   6 / INMNFPRESDIAG_vidAirPressSens1                                       */
/*   7 / INMNFPRESDIAG_vidNoAirPressSens1                                     */
/*   8 / INMNFPRESDIAG_vidAirPressSens                                        */
/*   9 / INMNFPRESDIAG_vidNoAirPressSens                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6539920 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INMNFPRESDIAG/INMNFPRESDIAG_FCT3.C$*/
/* $Revision::   1.10     $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "INMNFPRESDIAG.h"
#include "INMNFPRESDIAG_L.h"
#include "INMNFPRESDIAG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPres_GrdPres                           */
/* !Description :  Résultat du diagnostic de cohérence dans le taux de        */
/*                 variation  de la pression de la collecteur d'admission     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void INMNFPRESDIAG_vidRefPressFreeze();                       */
/*  extf argret void INMNFPRESDIAG_vidDetectionEnabled();                     */
/*  input uint16 Acquisition_press_coll;                                      */
/*  input uint16 Tension_alimentation_air_pts;                                */
/*  input uint16 Io_map_manifold_press_gain;                                  */
/*  input sint16 Io_map_manifold_press_offset;                                */
/*  input uint8 AirPres_idxGrdDiagPresDsThr;                                  */
/*  input uint8 AirPres_noGrdDiagPresDsThr_C;                                 */
/*  output uint16 AirPres_Manifold_PresAcq;                                   */
/*  output uint8 AirPres_idxGrdDiagPresDsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPres_GrdPres(void)
{
   uint16 u16LocalTensionalimtationairpts;
   uint16 u16LocalAirPres;
   uint16 u16LocalDiv;
   uint16 u16LocalAcquisition_press_coll;
   uint32 u32LocalResult;
   uint32 u32LocalResultDif;
   sint32 s32LocalAirPresMan;


   VEMS_vidGET(Acquisition_press_coll, u16LocalAcquisition_press_coll);
   /*Production of AirPres_Manifold_PresAcq*/
   VEMS_vidGET(Tension_alimentation_air_pts, u16LocalTensionalimtationairpts);

   if (u16LocalTensionalimtationairpts == 0)
   {
      u16LocalAirPres = 65535;
      u16LocalDiv = 1;
   }
   else
   {
      u16LocalAirPres = u16LocalAcquisition_press_coll;
      u16LocalDiv = u16LocalTensionalimtationairpts;
   }

   u32LocalResult = ( (uint32)( u16LocalAirPres * Io_map_manifold_press_gain)
                    / u16LocalDiv);
   u32LocalResultDif = (uint32)(75000 - Io_map_manifold_press_offset);
   if (u32LocalResult > u32LocalResultDif)
   {
      s32LocalAirPresMan = 6000;
   }
   else
   {
      s32LocalAirPresMan = ( (sint32)u32LocalResult
                           + (sint32)Io_map_manifold_press_offset);
      s32LocalAirPresMan = (((s32LocalAirPresMan * 20) + 125) / 250);
   }
   AirPres_Manifold_PresAcq = (uint16)MATHSRV_udtMAX(s32LocalAirPresMan, 0);
   AirPres_idxGrdDiagPresDsThr = (uint8)( ( AirPres_idxGrdDiagPresDsThr + 1)
                                        % ( AirPres_noGrdDiagPresDsThr_C + 1));
   if (AirPres_idxGrdDiagPresDsThr == 0)
   {
      INMNFPRESDIAG_vidRefPressFreeze();
   }
   if (AirPres_idxGrdDiagPresDsThr == AirPres_noGrdDiagPresDsThr_C)
   {
      INMNFPRESDIAG_vidDetectionEnabled();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidRefPressFreeze                            */
/* !Description :  Figeage de la valeur de référence de la pression collecteur*/
/*                 qui sera utilisée par la suite pour la comparaison  avec la*/
/*                 pression « courante n point de mesures plus tard ».        */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 AirPres_Manifold_PresAcq;                                    */
/*  output uint16 AirPres_pFrzDsThrDiagGrd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidRefPressFreeze(void)
{
   AirPres_pFrzDsThrDiagGrd = (uint16)MATHSRV_udtMIN(AirPres_Manifold_PresAcq,
                                                     6000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDetectionEnabled                          */
/* !Description :  La détection du défaut revient à tester si la variation de */
/*                 la pression collecteur reste raisonnable (pas de pic de    */
/*                 pression intempestifs).                                    */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 AirPres_pFrzDsThrDiagGrd;                                    */
/*  input uint16 AirPres_Manifold_PresAcq;                                    */
/*  input uint8 AirPres_pDsThrThdGrd_C;                                       */
/*  output boolean AirPres_bDgoGrd_pDsThr;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDetectionEnabled(void)
{
   uint16 u16LocalAbs;
   sint32 s32LocalDiff;


   s32LocalDiff =(sint32)(AirPres_pFrzDsThrDiagGrd - AirPres_Manifold_PresAcq);
   u16LocalAbs = (uint16)MATHSRV_udtABS(s32LocalDiff);
   if (u16LocalAbs > AirPres_pDsThrThdGrd_C)
   {
      AirPres_bDgoGrd_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoGrd_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidDftPres_Reinit                            */
/* !Description :  A chaque  fois que  le diagnostic s’active,  la  fenêtre de*/
/*                 vérification se  réinitialise. Cela permet ainsi d’éviter  */
/*                 les  fausses détections lors des phases de désactivations  */
/*                 puis de réactivations successives du diagnostic.           */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 AirPres_idxGrdDiagPresDsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidDftPres_Reinit(void)
{
   AirPres_idxGrdDiagPresDsThr = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidPrsDiagStallIni                           */
/* !Description :  le seuil minimale de pression du capteur de pression au    */
/*                 démarrage.                                                 */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Diag_min_pressure_in_crank;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidPrsDiagStallIni(void)
{
   Diag_min_pressure_in_crank = 1310;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidAirPressSens1                             */
/* !Description :  Le diagnostic revient à calculer la valeur absolue de la   */
/*                 differnce de  deux valeurs réalistes de pression           */
/*                 atmosphérique.                                             */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  PTS_R_5075012_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_pDsThrStrt;                                              */
/*  input uint16 Ext_pAirExtStrt;                                             */
/*  input uint16 AirPres_pDsThrThdDifMax1_C;                                  */
/*  output uint8 AirPres_pDsThrDif;                                           */
/*  output boolean AirPres_bDgoStallCoh_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidAirPressSens1(void)
{
   uint16 u16LocalAbsValue;
   sint32 s32LocalAbsValue;


   s32LocalAbsValue = (sint32)(Ext_pDsThrStrt - Ext_pAirExtStrt);
   u16LocalAbsValue = (uint16)MATHSRV_udtABS(s32LocalAbsValue);
   AirPres_pDsThrDif = (uint8)MATHSRV_udtMIN(u16LocalAbsValue, 255);
   if (u16LocalAbsValue > AirPres_pDsThrThdDifMax1_C)
   {
      AirPres_bDgoStallCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoStallCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidNoAirPressSens1                           */
/* !Description :  Le diagnostic revient à comparer la pression admission à   */
/*                 deux valeurs réalistes de pression atmosphérique (valeurs  */
/*                 mini et maxi majorées).                                    */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_pDsThrStrt;                                              */
/*  input uint16 Pressure_in_stall_max_threshold;                             */
/*  input uint16 Pressure_in_stall_min_threshold;                             */
/*  output boolean AirPres_bDgoStallCoh_pDsThr;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidNoAirPressSens1(void)
{
   if (  (Ext_pDsThrStrt >= Pressure_in_stall_max_threshold)
      || (Ext_pDsThrStrt < Pressure_in_stall_min_threshold))
   {
      AirPres_bDgoStallCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoStallCoh_pDsThr = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidAirPressSens                              */
/* !Description :  Le diagnostic revient à calculer la valeur absolue de la   */
/*                 differnce de  deux valeurs réalistes de pression           */
/*                 atmosphérique.                                             */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint8 AirPres_pDsThrThdDifMax3_C;                                   */
/*  output uint16 AirPres_pDsThrFldMem;                                       */
/*  output uint8 AirPres_pDsThrDif3;                                          */
/*  output boolean AirPres_bDgoFldCoh_pDsThr;                                 */
/*  output uint16 AirPres_pAirExtMem;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidAirPressSens(void)
{
   uint16 u16LocalExt_pAirExtMes;
   uint16 u16LocalAbsValue;
   uint16 u16LocalAirPres_pDsThrDif3;
   sint16 s16LocalExt_pDsThrMes;
   sint32 s32LocalAbsValue;


   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);

   AirPres_pDsThrFldMem = (uint16)MATHSRV_udtCLAMP(s16LocalExt_pDsThrMes,
                                                   0,
                                                   6000);

   s32LocalAbsValue = (sint32)(s16LocalExt_pDsThrMes - u16LocalExt_pAirExtMes);
   u16LocalAbsValue = (uint16)MATHSRV_udtABS(s32LocalAbsValue);
   u16LocalAirPres_pDsThrDif3 = (uint16)(u16LocalAbsValue / 10);
   AirPres_pDsThrDif3 = (uint8)MATHSRV_udtMIN(u16LocalAirPres_pDsThrDif3, 255);

   if (u16LocalAbsValue > AirPres_pDsThrThdDifMax3_C)
   {
      AirPres_bDgoFldCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoFldCoh_pDsThr = 0;
   }
   AirPres_pAirExtMem = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pAirExtMes,
                                                 500,
                                                 1500);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INMNFPRESDIAG_vidNoAirPressSens                            */
/* !Description :  Le diagnostic de la pression collecteur en pleine charge   */
/*                 revient à vérifier que la pression collecteur se trouve    */
/*                 bien dans une plage de valeur de pression.                 */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_11_03503_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_pDsThrMes;                                               */
/*  input uint16 Pressure_in_full_load_min_thresh;                            */
/*  input uint16 Pressure_in_full_load_max_thresh;                            */
/*  output boolean AirPres_bDgoFldCoh_pDsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INMNFPRESDIAG_vidNoAirPressSens(void)
{
   sint16 s16LocalExt_pDsThrMes;


   VEMS_vidGET(Ext_pDsThrMes, s16LocalExt_pDsThrMes);
   if (  (s16LocalExt_pDsThrMes < Pressure_in_full_load_min_thresh)
      || (s16LocalExt_pDsThrMes > Pressure_in_full_load_max_thresh))
   {
      AirPres_bDgoFldCoh_pDsThr = 1;
   }
   else
   {
      AirPres_bDgoFldCoh_pDsThr = 0;
   }
}
/************************************* end of file ****************************/