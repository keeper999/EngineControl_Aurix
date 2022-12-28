/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIACQ                                               */
/* !Description     : BRKASIACQ component.                                    */
/*                                                                            */
/* !Module          : BRKASIACQ                                               */
/* !Description     : ACQUISITION DE LA MESURE DU CAPTEUR DE DEPRESSION       */
/*                    MASTERVAC.                                              */
/*                                                                            */
/* !File            : BRKASIACQ_FCT1.C                                        */
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
/*   1 / BRKASIACQ_vidInitOutput                                              */
/*   2 / BRKASIACQ_vidInitialization                                          */
/*   3 / BRKASIACQ_vidCallMng                                                 */
/*   4 / BRKASIACQ_vidBrkAsiAcqBrut                                           */
/*   5 / BRKASIACQ_vidMstrVacSensorDiag                                       */
/*   6 / BRKASIACQ_vidScDiagnostic                                            */
/*   7 / BRKASIACQ_vidGrdDiagnostic                                           */
/*   8 / BRKASIACQ_vidBrkAsiAcq                                               */
/*   9 / BRKASIACQ_vidSftLvl2                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6525171 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BRKASIACQ/BRKASIACQ_FCT1.C_v      $*/
/* $Revision::   1.7      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "BRKASIACQ.h"
#include "BRKASIACQ_L.h"
#include "BRKASIACQ_IM.h"
#include "LIBSFTYLVL2.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pBrkAsiRaw;                                              */
/*  output uint32 BRKASIACQ_u32ExtBrkAsiMem;                                  */
/*  output uint16 BRKASIACQ_u16ExtRBrkAsiPrev;                                */
/*  output boolean AirPres_bDftSftyScp_pBrkAsi;                               */
/*  output boolean AirPres_bDftSftyScg_pBrkAsi;                               */
/*  output boolean Ext_bDgoScp_pBrkAsi;                                       */
/*  output boolean Ext_bDgoScg_pBrkAsi;                                       */
/*  output uint8 BRKASIACQ_u8CntFilt_1;                                       */
/*  output uint8 BRKASIACQ_u8CntFilt_2;                                       */
/*  output boolean BRKASIACQ_bFilSig_1;                                       */
/*  output boolean BRKASIACQ_bFilSig_2;                                       */
/*  output uint8 AirPres_ctDftSftyScp_pBrkAsi;                                */
/*  output uint8 AirPres_ctDftSftyScg_pBrkAsi;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidInitOutput(void)
{
   BRKASIACQ_u32ExtBrkAsiMem = (uint32)(Ext_pBrkAsiRaw * 65536);
   BRKASIACQ_u16ExtRBrkAsiPrev = 0;
   VEMS_vidSET(AirPres_bDftSftyScp_pBrkAsi, 0);
   VEMS_vidSET(AirPres_bDftSftyScg_pBrkAsi, 0);
   Ext_bDgoScp_pBrkAsi = 0;
   Ext_bDgoScg_pBrkAsi = 0;
   BRKASIACQ_u8CntFilt_1 = 0;
   BRKASIACQ_u8CntFilt_2 = 0;
   BRKASIACQ_bFilSig_1 = 0;
   BRKASIACQ_bFilSig_2 = 0;
   AirPres_ctDftSftyScp_pBrkAsi = 0;
   AirPres_ctDftSftyScg_pBrkAsi = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidInitialization                                */
/* !Description :  Initialisation au réveil calculateur de la valeur de       */
/*                 pression d’air dans le mastervac.                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_rBrkAsiInit_C;                                           */
/*  input uint16 Ext_pBrkAsiInit_C;                                           */
/*  input uint8 Ext_tDlyDgoGrd_pBrkAsi_C;                                     */
/*  input uint16 Ext_uBrkAsiInit_C;                                           */
/*  output uint8 Ext_tDlyDgoGrd_pBrkAsi;                                      */
/*  output uint16 Ext_uBrkAsi;                                                */
/*  output uint16 Ext_rBrkAsi;                                                */
/*  output uint16 Ext_pBrkAsiMes;                                             */
/*  output uint16 Ext_pBrkAsiRaw;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidInitialization(void)
{
   uint16 u16LocalExt_pBrkAsiMes;
   uint16 u16LocalExt_uBrkAsi;
   uint16 u16LocalExt_rBrkAsi;


   u16LocalExt_rBrkAsi = (uint16)MATHSRV_udtMIN(Ext_rBrkAsiInit_C, 32768);
   u16LocalExt_pBrkAsiMes =
      (uint16)MATHSRV_udtCLAMP(Ext_pBrkAsiInit_C, 20, 1000);
   Ext_tDlyDgoGrd_pBrkAsi = (uint8)MATHSRV_udtMIN(Ext_tDlyDgoGrd_pBrkAsi_C, 10);
   u16LocalExt_uBrkAsi= (uint16)MATHSRV_udtMIN(Ext_uBrkAsiInit_C ,1000);
   VEMS_vidSET(Ext_uBrkAsi, u16LocalExt_uBrkAsi);
   VEMS_vidSET(Ext_rBrkAsi, u16LocalExt_rBrkAsi);
   VEMS_vidSET(Ext_pBrkAsiMes, u16LocalExt_pBrkAsiMes);
   Ext_pBrkAsiRaw = u16LocalExt_pBrkAsiMes;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidCallMng                                       */
/* !Description :  Fonction d'appel conditionné pour le module BrkAsiAcq.     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_04383_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BRKASIACQ_vidBrkAsiAcqBrut();                            */
/*  extf argret void BRKASIACQ_vidMstrVacSensorDiag();                        */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void BRKASIACQ_vidBrkAsiAcq();                                */
/*  input boolean AirPres_bAcvBrkAsiAcq;                                      */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Ext_bDgoScp_pBrkAsi;                                        */
/*  input boolean Ext_bMonRunScp_pBrkAsi;                                     */
/*  input boolean Ext_bDgoScg_pBrkAsi;                                        */
/*  input boolean Ext_bMonRunScg_pBrkAsi;                                     */
/*  input boolean Ext_bDgoGrd_pBrkAsi;                                        */
/*  input boolean Ext_bMonRunGrd_pBrkAsi;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidCallMng(void)
{
   boolean bLocalAirPres_bAcvBrkAsiAcq;
   boolean bLocalDIAGCAN_bIntegratioElect;


   VEMS_vidGET(AirPres_bAcvBrkAsiAcq, bLocalAirPres_bAcvBrkAsiAcq);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioElect);
   if (  (bLocalAirPres_bAcvBrkAsiAcq != 0)
      && (bLocalDIAGCAN_bIntegratioElect == 0))
   {
      BRKASIACQ_vidBrkAsiAcqBrut();
      BRKASIACQ_vidMstrVacSensorDiag();
      GDGAR_vidGdu(GD_DFT_SCP_PBRKASI,
                   Ext_bDgoScp_pBrkAsi,
                   Ext_bMonRunScp_pBrkAsi,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_PBRKASI,
                   Ext_bDgoScg_pBrkAsi,
                   Ext_bMonRunScg_pBrkAsi,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_GRD_PBRKASI,
                   Ext_bDgoGrd_pBrkAsi,
                   Ext_bMonRunGrd_pBrkAsi,
                   DIAG_DISPO);
      BRKASIACQ_vidBrkAsiAcq();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidBrkAsiAcqBrut                                 */
/* !Description :  Fonction de transfert Tension Pression                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_alimentation_pmast;                                  */
/*  input uint16 Acquisition_press_mast_abs;                                  */
/*  input uint16 Ext_rBrkAsi;                                                 */
/*  input uint16 Mvc_pressure_sensor_gain;                                    */
/*  input uint16 Mvc_pressure_sensor_offset;                                  */
/*  output uint16 Ext_uBrkAsi;                                                */
/*  output uint16 BRKASIACQ_u16ExtRBrkAsiPrev;                                */
/*  output uint16 Ext_rBrkAsi;                                                */
/*  output uint16 Ext_pBrkAsiRaw;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidBrkAsiAcqBrut(void)
{
   uint16 u16LocalExt_rBrkAsi;
   uint16 u16LocalExt_uBrkAsi;
   uint16 u16LocalTension_alim_pmast;
   uint16 u16LocalAcquisitionPressMastAbs;
   uint32 u32LocalBrkAsi;
   sint32 s32LocalBrkAsi;


   VEMS_vidGET(Tension_alimentation_pmast, u16LocalTension_alim_pmast);
   VEMS_vidGET(Acquisition_press_mast_abs, u16LocalAcquisitionPressMastAbs);

   u16LocalExt_uBrkAsi =
      (uint16)((u16LocalAcquisitionPressMastAbs * 125) / 512);
   u16LocalExt_uBrkAsi = (uint16)MATHSRV_udtMIN(u16LocalExt_uBrkAsi, 1000);
   VEMS_vidSET(Ext_uBrkAsi, u16LocalExt_uBrkAsi);

   VEMS_vidGET(Ext_rBrkAsi, u16LocalExt_rBrkAsi);
   BRKASIACQ_u16ExtRBrkAsiPrev = u16LocalExt_rBrkAsi;

   if (u16LocalTension_alim_pmast != 0)
   {
      u32LocalBrkAsi = (uint32)( ( u16LocalAcquisitionPressMastAbs
                                 * 32768)
                               / u16LocalTension_alim_pmast);
      u16LocalExt_rBrkAsi = (uint16)MATHSRV_udtMIN(u32LocalBrkAsi, 32768);
      VEMS_vidSET(Ext_rBrkAsi, u16LocalExt_rBrkAsi);
      u32LocalBrkAsi = (uint32)( ( u16LocalAcquisitionPressMastAbs
                                 * Mvc_pressure_sensor_gain)
                               / u16LocalTension_alim_pmast);
      s32LocalBrkAsi = (Mvc_pressure_sensor_offset - 32767);
      u32LocalBrkAsi = Mfx_Add_u32s32_u32(u32LocalBrkAsi, s32LocalBrkAsi);
      u32LocalBrkAsi = (u32LocalBrkAsi + 25) / 50;
      Ext_pBrkAsiRaw = (uint16)MATHSRV_udtCLAMP(u32LocalBrkAsi, 20, 1000);
   }
   else
   {
      if (Mvc_pressure_sensor_gain != 0)
      {
         Ext_pBrkAsiRaw = 1000;
      }
      else
      {
         s32LocalBrkAsi = (Mvc_pressure_sensor_offset - 32767) / 50;
         Ext_pBrkAsiRaw = (uint16)MATHSRV_udtMAX(s32LocalBrkAsi, 20);
      }
      VEMS_vidSET(Ext_rBrkAsi, 32768);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidMstrVacSensorDiag                             */
/* !Description :  Cette fonction énumère les différents court-circuits (à la */
/*                 masse et au plus) qui engendre un défaut sur le capteur    */
/*                 Mastervac                                                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_04383_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void BRKASIACQ_vidScDiagnostic();                             */
/*  extf argret void BRKASIACQ_vidGrdDiagnostic();                            */
/*  input boolean Ext_bDgoScp_pBrkAsi;                                        */
/*  input boolean Ext_bDgoScg_pBrkAsi;                                        */
/*  input uint8 Ext_tDlyDgoGrd_pBrkAsi;                                       */
/*  output boolean Ext_bMonRunScp_pBrkAsi;                                    */
/*  output boolean Ext_bMonRunScg_pBrkAsi;                                    */
/*  output boolean Ext_bMonRunGrd_pBrkAsi;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidMstrVacSensorDiag(void)
{
   boolean bLocalInhDiag_pBrkAsi;


   bLocalInhDiag_pBrkAsi = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PBRKASI);
   if (bLocalInhDiag_pBrkAsi != 0)
   {
      Ext_bMonRunScp_pBrkAsi = 0;
      Ext_bMonRunScg_pBrkAsi = 0;
      Ext_bMonRunGrd_pBrkAsi = 0;
   }
   else
   {
      Ext_bMonRunScp_pBrkAsi = 1;
      Ext_bMonRunScg_pBrkAsi = 1;
      BRKASIACQ_vidScDiagnostic();
      if (  (Ext_bDgoScp_pBrkAsi == 0)
         && (Ext_bDgoScg_pBrkAsi == 0)
         && (Ext_tDlyDgoGrd_pBrkAsi <= 0))
      {
         Ext_bMonRunGrd_pBrkAsi = 1;
         BRKASIACQ_vidGrdDiagnostic();
      }
      else
      {
         Ext_bMonRunGrd_pBrkAsi = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidScDiagnostic                                  */
/* !Description :  Fonction qui énumère les différents court-circuits qui     */
/*                 engendre un défaut sur le capteur Mastervac.               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_04383_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rBrkAsi;                                                 */
/*  input uint16 Ext_rDgoScp_pBrkAsi_C;                                       */
/*  input uint16 Ext_rDgoScg_pBrkAsi_C;                                       */
/*  output boolean Ext_bDgoScp_pBrkAsi;                                       */
/*  output boolean Ext_bDgoScg_pBrkAsi;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidScDiagnostic(void)
{
   uint16 u16LocalExt_rBrkAsi;


   VEMS_vidGET(Ext_rBrkAsi, u16LocalExt_rBrkAsi);

   if (u16LocalExt_rBrkAsi > Ext_rDgoScp_pBrkAsi_C)
   {
      Ext_bDgoScp_pBrkAsi = 1;
   }
   else
   {
      Ext_bDgoScp_pBrkAsi = 0;
   }

   if (u16LocalExt_rBrkAsi < Ext_rDgoScg_pBrkAsi_C)
   {
      Ext_bDgoScg_pBrkAsi = 1;
   }
   else
   {
      Ext_bDgoScg_pBrkAsi = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidGrdDiagnostic                                 */
/* !Description :  Fonction qui énumère les différents court-circuits qui     */
/*                 engendre un défaut sur le capteur Mastervac.               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rBrkAsi;                                                 */
/*  input uint16 BRKASIACQ_u16ExtRBrkAsiPrev;                                 */
/*  input uint16 Ext_rDgoGrd_pBrkAsi_C;                                       */
/*  output boolean Ext_bDgoGrd_pBrkAsi;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidGrdDiagnostic(void)
{
   uint16 u16LocalExt_rBrkAsi;


   VEMS_vidGET(Ext_rBrkAsi, u16LocalExt_rBrkAsi);
   u16LocalExt_rBrkAsi =
      (uint16)MATHSRV_udtABS(u16LocalExt_rBrkAsi - BRKASIACQ_u16ExtRBrkAsiPrev);
   if (u16LocalExt_rBrkAsi > Ext_rDgoGrd_pBrkAsi_C)
   {
      Ext_bDgoGrd_pBrkAsi = 1;
   }
   else
   {
      Ext_bDgoGrd_pBrkAsi = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidBrkAsiAcq                                     */
/* !Description :  Fonction qui permet qu'en cas de défaut détecté            */
/*                 (court-circuit à la masse ou au plus du capteur Mastervac) */
/*                 la valeur de la pression sera figée à sa dernière valeur   */
/*                 calculée et prendra une valeur de refuge en cas de         */
/*                 confirmation du défaut.                                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_04383_004.01                                     */
/*                 VEMS_R_09_04383_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_pBrkAsiMes;                                              */
/*  input uint8 Ext_tDlyDgoGrd_pBrkAsi;                                       */
/*  input uint16 Ext_pBrkAsiGain_C;                                           */
/*  input uint32 BRKASIACQ_u32ExtBrkAsiMem;                                   */
/*  input uint16 Ext_pBrkAsiRaw;                                              */
/*  input uint16 Ext_pBrkAsiMinSat_C;                                         */
/*  input uint16 Ext_pBrkAsiMaxSat_C;                                         */
/*  input uint16 Ext_pBrkAsiFault_C;                                          */
/*  input uint16 Ext_pbrkAsiSat;                                              */
/*  output uint8 Ext_tDlyDgoGrd_pBrkAsi;                                      */
/*  output uint16 Ext_pbrkAsiSat;                                             */
/*  output uint32 BRKASIACQ_u32ExtBrkAsiMem;                                  */
/*  output uint16 Ext_pBrkAsiMes;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidBrkAsiAcq(void)
{
   uint8   LocalstDgoScp_pBrkAsi;
   uint8   LocalstDgoScg_pBrkAsi;
   uint8   LocalstDgoGrd_pBrkAsi;
   uint16  u16LocalExt_pBrkAsiMes;
   uint16  u16LocalFilterOut;
   uint16  u16LocalFilterGain;
   uint16  u16LocalExt_pbrkAsiSat;
   sint16  s16LocalExt_tDlyDgoGrd_pBrkAsi;


   VEMS_vidGET(Ext_pBrkAsiMes, u16LocalExt_pBrkAsiMes);
   s16LocalExt_tDlyDgoGrd_pBrkAsi = (sint16)(Ext_tDlyDgoGrd_pBrkAsi - 1);
   Ext_tDlyDgoGrd_pBrkAsi =
      (uint8)MATHSRV_udtCLAMP(s16LocalExt_tDlyDgoGrd_pBrkAsi, 0, 10);

   if (Ext_pBrkAsiGain_C < 32768)
   {
      u16LocalFilterGain = (uint16)( ( ( Ext_pBrkAsiGain_C
                                       * 65536)
                                     + 16384)
                                   / 32768);
      u16LocalFilterOut =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &BRKASIACQ_u32ExtBrkAsiMem,
                                         Ext_pBrkAsiRaw);
      u16LocalExt_pbrkAsiSat = u16LocalFilterOut;
   }
   else
   {
      u16LocalExt_pbrkAsiSat = Ext_pBrkAsiRaw;
   }

   u16LocalExt_pbrkAsiSat = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pbrkAsiSat,
                                                     Ext_pBrkAsiMinSat_C,
                                                     Ext_pBrkAsiMaxSat_C);
   Ext_pbrkAsiSat = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pbrkAsiSat, 20, 1000);

   LocalstDgoScp_pBrkAsi = GDGAR_tenuGetStDgo(GD_DFT_SCP_PBRKASI);
   LocalstDgoScg_pBrkAsi = GDGAR_tenuGetStDgo(GD_DFT_SCG_PBRKASI);
   LocalstDgoGrd_pBrkAsi = GDGAR_tenuGetStDgo(GD_DFT_GRD_PBRKASI);
   if (  (LocalstDgoScp_pBrkAsi == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_pBrkAsi == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoScg_pBrkAsi == GDU_ETAT_PRESENT)
      || (LocalstDgoScg_pBrkAsi == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoGrd_pBrkAsi == GDU_ETAT_PRESENT)
      || (LocalstDgoGrd_pBrkAsi == GDU_ETAT_DEVALIDATION))
   {
      u16LocalExt_pBrkAsiMes = Ext_pBrkAsiFault_C;
   }
   else
   {
      if (  (LocalstDgoScp_pBrkAsi != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoScp_pBrkAsi != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoScg_pBrkAsi != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoScg_pBrkAsi != GDU_ETAT_PCTL_ABSENT)
         && (LocalstDgoGrd_pBrkAsi != GDU_ETAT_PCTL_PRESENT)
         && (LocalstDgoGrd_pBrkAsi != GDU_ETAT_PCTL_ABSENT))
      {
         u16LocalExt_pBrkAsiMes = Ext_pbrkAsiSat;
      }
   }
   u16LocalExt_pBrkAsiMes = (uint16)MATHSRV_udtCLAMP(u16LocalExt_pBrkAsiMes,
                                                    20,
                                                    1000);
   BRKASIACQ_u32ExtBrkAsiMem = (uint32)(u16LocalExt_pBrkAsiMes * 65536);
   VEMS_vidSET(Ext_pBrkAsiMes, u16LocalExt_pBrkAsiMes);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIACQ_vidSftLvl2                                       */
/* !Description :  Ce bloc permet de répondre aux exigences de safety niveau 2*/
/*                 concernant le diagnostics électriques du capteur de        */
/*                 pression mastervac                                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoScp_pBrkAsi;                                        */
/*  input uint8 AirPres_nUpTranThd_ScpBrkAsi_C;                               */
/*  input uint8 AirPres_nDownTranThd_ScpBrkAsi_C;                             */
/*  input uint8 AirPres_nInitCptConf_ScpBrkAsi_C;                             */
/*  input uint8 AirPres_nDecCpt_ScpBrkAsi_C;                                  */
/*  input uint8 BRKASIACQ_u8CntFilt_1;                                        */
/*  input boolean BRKASIACQ_bFilSig_1;                                        */
/*  input uint8 AirPres_ctDftSftyScp_pBrkAsi;                                 */
/*  input boolean BRKASIACQ_bScprpBrkAsi;                                     */
/*  input boolean Ext_bDgoScg_pBrkAsi;                                        */
/*  input uint8 AirPres_nUpTranThd_ScgBrkAsi_C;                               */
/*  input uint8 AirPres_nDownTranThd_ScgBrkAsi_C;                             */
/*  input uint8 AirPres_nInitCptConf_ScgBrkAsi_C;                             */
/*  input uint8 AirPres_nDecCpt_ScgBrkAsi_C;                                  */
/*  input uint8 BRKASIACQ_u8CntFilt_2;                                        */
/*  input boolean BRKASIACQ_bFilSig_2;                                        */
/*  input uint8 AirPres_ctDftSftyScg_pBrkAsi;                                 */
/*  input boolean BRKASIACQ_bScgrpBrkAsi;                                     */
/*  output boolean AirPres_bDftSftyScp_pBrkAsi;                               */
/*  output boolean BRKASIACQ_bScprpBrkAsi;                                    */
/*  output boolean AirPres_bDftSftyScg_pBrkAsi;                               */
/*  output boolean BRKASIACQ_bScgrpBrkAsi;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIACQ_vidSftLvl2(void)
{
   /*SftyLvl2_DftSftyScp_pBrkAsi*/
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScp_pBrkAsi,
                                AirPres_nUpTranThd_ScpBrkAsi_C,
                                AirPres_nDownTranThd_ScpBrkAsi_C,
                                AirPres_nInitCptConf_ScpBrkAsi_C,
                                AirPres_nDecCpt_ScpBrkAsi_C,
                                &BRKASIACQ_u8CntFilt_1,
                                &BRKASIACQ_bFilSig_1,
                                &AirPres_ctDftSftyScp_pBrkAsi,
                                &BRKASIACQ_bScprpBrkAsi);
   VEMS_vidSET(AirPres_bDftSftyScp_pBrkAsi, BRKASIACQ_bScprpBrkAsi);
   /*SftyLvl2_DftSftyScg_pBrkAsi*/
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScg_pBrkAsi,
                                AirPres_nUpTranThd_ScgBrkAsi_C,
                                AirPres_nDownTranThd_ScgBrkAsi_C,
                                AirPres_nInitCptConf_ScgBrkAsi_C,
                                AirPres_nDecCpt_ScgBrkAsi_C,
                                &BRKASIACQ_u8CntFilt_2,
                                &BRKASIACQ_bFilSig_2,
                                &AirPres_ctDftSftyScg_pBrkAsi,
                                &BRKASIACQ_bScgrpBrkAsi);
   VEMS_vidSET(AirPres_bDftSftyScg_pBrkAsi, BRKASIACQ_bScgrpBrkAsi);
}
/*-------------------------------- End of file -------------------------------*/