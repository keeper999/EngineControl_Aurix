/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCKEFCFIL                                              */
/* !Description     : TQCKEFCFIL Component                                    */
/*                                                                            */
/* !Module          : TQCKEFCFIL                                              */
/* !Description     : SAFETY TMS : VALIDER AGRÉMENT PRÉVENTIF                 */
/*                                                                            */
/* !File            : TQCKEFCFIL_FCT2.C                                       */
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
/*   1 / TQCKEFCFIL_vidCalcDiffCplePPhase                                     */
/*   2 / TQCKEFCFIL_vidCalcDureeDesPhases                                     */
/*   3 / TQCKEFCFIL_vidCalcEtCoordPentes                                      */
/*   4 / TQCKEFCFIL_vidChoiPteDecIPCalCpt                                     */
/*   5 / TQCKEFCFIL_vidComptDrivFilDeceIP                                     */
/*   6 / TQCKEFCFIL_vidIFTHENComptDeceAcv                                     */
/*   7 / TQCKEFCFIL_vidCptInctDrvFilDecIP                                     */
/*   8 / TQCKEFCFIL_vidIncCptDrivFilDecIP                                     */
/*   9 / TQCKEFCFIL_vidSyntPtDrivFilDecIP                                     */
/*   10 / TQCKEFCFIL_vidCalcPfTqFiltre                                        */
/*                                                                            */
/* !Reference   : V02 NT 10 01236 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#056922                                         */
/* !OtherRefs   : CSCT_CGMT09_2398 / 2.6                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKEFCFIL/TQCKEFCFIL_$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQCKEFCFIL.h"
#include "TQCKEFCFIL_L.h"
#include "TQCKEFCFIL_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcDiffCplePPhase                           */
/* !Description :  Calcule Des différentiels de couple pour toutes les phases.*/
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_029.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 SftyMgt_tqThdPha9;                                           */
/*  input sint16 SftyMgt_tqThdPha8;                                           */
/*  input sint16 SftyMgt_tqThdPha10;                                          */
/*  input sint16 SftyMgt_tqCkDrivNotFil;                                      */
/*  output sint16 SftyMgt_tqDifIniPha9;                                       */
/*  output sint16 SftyMgt_tqIntlPha10;                                        */
/*  output boolean SftyMgt_bDiPha10;                                          */
/*  output sint16 SftyMgt_tqIntlPha11;                                        */
/*  output boolean SftyMgt_bDiPha11;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcDiffCplePPhase(void)
{
   /*F01_03_04_01_calculDuDifferentielDeCoupleParPhase*/
   sint32 s32LocalDiffD1D0;
   sint32 s32LocalDiffUnfilD0;
   sint32 s32LocalDiffUnfilD1;


   /*Production of SftyMgt_tqDifIniPha9*/
   s32LocalDiffD1D0 = (sint32)(SftyMgt_tqThdPha9 - SftyMgt_tqThdPha8);
   SftyMgt_tqDifIniPha9 = (sint16)MATHSRV_udtCLAMP(s32LocalDiffD1D0,
                                                   -32000,
                                                   32000);
   /*Production of SftyMgt_tqIntlPha10*/
   s32LocalDiffUnfilD0 = (sint32)(SftyMgt_tqThdPha10 - SftyMgt_tqThdPha9);
   SftyMgt_tqIntlPha10 = (sint16)MATHSRV_udtCLAMP(s32LocalDiffUnfilD0,
                                                  -32000,
                                                  32000);
   /*Production of SftyMgt_bDiPha10*/
   if (s32LocalDiffUnfilD0 >= 0)
   {
      SftyMgt_bDiPha10 = 1;
   }
   else
   {
      SftyMgt_bDiPha10 = 0;
   }
   /*Production of SftyMgt_tqIntlPha11*/
   s32LocalDiffUnfilD1 = (sint32)(SftyMgt_tqCkDrivNotFil - SftyMgt_tqThdPha10);
   SftyMgt_tqIntlPha11 = (sint16)MATHSRV_udtCLAMP(s32LocalDiffUnfilD1,
                                                  -32000,
                                                  32000);
   /*Production of SftyMgt_bDiPha11*/
   if (s32LocalDiffUnfilD1 >= 0)
   {
      SftyMgt_bDiPha11 = 1;
   }
   else
   {
      SftyMgt_bDiPha11 = 0;
   }

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcDureeDesPhases                           */
/* !Description :  Calcule des délais pour toutes les phases.                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_030.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDiPha10;                                           */
/*  input uint8 SftyMgt_tiDlyPha10;                                           */
/*  input boolean SftyMgt_bDiPha11;                                           */
/*  input uint8 SftyMgt_tiDlyPha11;                                           */
/*  input uint8 SftyMgt_tiDlyPha9;                                            */
/*  output uint8 SftyMgt_tiDlyDrivFilDecePha10;                               */
/*  output uint8 SftyMgt_tiDlyDrivFilDecePha11;                               */
/*  output uint16 SftyMgt_tiDlyDrivFilDeceTotTol;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcDureeDesPhases(void)
{
   /*F01_03_04_02_calculDeLaDureeDesPhases*/
   uint8  u8LocalSftMgtiDlyDrvFilDecPha10;
   uint8  u8LocalSftMgtiDlyDrvFilDecPha11;
   uint16 u16LocalSftMgttiDlyDrvFilDecTot;


   if (SftyMgt_bDiPha10 != 0)
   {
      u8LocalSftMgtiDlyDrvFilDecPha10 = 1;
   }
   else
   {
      u8LocalSftMgtiDlyDrvFilDecPha10 = SftyMgt_tiDlyPha10;
   }
   SftyMgt_tiDlyDrivFilDecePha10 =
      (uint8)MATHSRV_udtMIN(u8LocalSftMgtiDlyDrvFilDecPha10, 200);

   if (SftyMgt_bDiPha11 != 0)
   {
      u8LocalSftMgtiDlyDrvFilDecPha11 = 1;
   }
   else
   {
      u8LocalSftMgtiDlyDrvFilDecPha11 = SftyMgt_tiDlyPha11;

   }
   SftyMgt_tiDlyDrivFilDecePha11 =
      (uint8) MATHSRV_udtMIN(u8LocalSftMgtiDlyDrvFilDecPha11, 200);

   u16LocalSftMgttiDlyDrvFilDecTot =
      (uint16)( SftyMgt_tiDlyPha9
              + u8LocalSftMgtiDlyDrvFilDecPha10
              + u8LocalSftMgtiDlyDrvFilDecPha11);
   SftyMgt_tiDlyDrivFilDeceTotTol =
      (uint16)MATHSRV_udtMIN(u16LocalSftMgttiDlyDrvFilDecTot, 300);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcEtCoordPentes                            */
/* !Description :  Calcule des pentes pour toutes les phases.                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_031.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 SftyMgt_tiDlyPha9;                                            */
/*  input sint16 SftyMgt_tqDifIniPha9;                                        */
/*  input uint8 SftyMgt_tiDlyDrivFilDecePha10;                                */
/*  input sint16 SftyMgt_tqIntlPha10;                                         */
/*  input uint8 SftyMgt_tiDlyDrivFilDecePha11;                                */
/*  input sint16 SftyMgt_tqIntlPha11;                                         */
/*  output sint16 SftyMgt_tqSlopPha9;                                         */
/*  output sint16 SftyMgt_tqSlopPha10;                                        */
/*  output sint16 SftyMgt_tqSlopPha11;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcEtCoordPentes(void)
{
   /*F01_03_04_03_CalculEt_CoordinationDesPentes*/
   sint32 s32LocalDiv1;
   sint32 s32LocalDiv2;
   sint32 s32LocalDiv3;


   /*First division*/
   if (SftyMgt_tiDlyPha9 != 0)
   {
      s32LocalDiv1 = ( (sint32)( SftyMgt_tqDifIniPha9
                               * SftyMgt_tiSdlTqCkEfcFil_SC)
                     / ( SftyMgt_tiDlyPha9
                       * 10));
   }
   else
   {
      if (SftyMgt_tqDifIniPha9 >= 0)
      {
         s32LocalDiv1 = 32000;
      }
      else
      {
         s32LocalDiv1 = -32000;
      }
   }

   SftyMgt_tqSlopPha9 = (sint16)MATHSRV_udtCLAMP(s32LocalDiv1, -32000, 32000);

   /*Second division*/
   if (SftyMgt_tiDlyDrivFilDecePha10 != 0)
   {
      s32LocalDiv2 = ( (sint32)( SftyMgt_tqIntlPha10
                               * SftyMgt_tiSdlTqCkEfcFil_SC)
                     / ( SftyMgt_tiDlyDrivFilDecePha10
                       * 10));
   }
   else
   {
      if (SftyMgt_tqIntlPha10 >= 0)
      {
         s32LocalDiv2 = 32000;
      }
      else
      {
         s32LocalDiv2 = -32000;
      }
   }
   SftyMgt_tqSlopPha10 = (sint16)MATHSRV_udtCLAMP(s32LocalDiv2, -32000, 32000);

    /*Third division*/
   if (SftyMgt_tiDlyDrivFilDecePha11 != 0)
   {
      s32LocalDiv3 =( (sint32)( SftyMgt_tqIntlPha11
                              * SftyMgt_tiSdlTqCkEfcFil_SC)
                    / ( SftyMgt_tiDlyDrivFilDecePha11
                      * 10));
   }
   else
   {
      if (SftyMgt_tqIntlPha11 >= 0)
      {
         s32LocalDiv3 = 32000;
      }
      else
      {
         s32LocalDiv3 = -32000;
      }
   }
   SftyMgt_tqSlopPha11 = (sint16)MATHSRV_udtCLAMP(s32LocalDiv3, -32000, 32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidChoiPteDecIPCalCpt                           */
/* !Description :  Synthèse de la pente maximale permissible et calcul du     */
/*                 compteur de temps passé en phase de décélération.          */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidComptDrivFilDeceIP();                      */
/*  extf argret void TQCKEFCFIL_vidSyntPtDrivFilDecIP();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidChoiPteDecIPCalCpt(void)
{
   TQCKEFCFIL_vidComptDrivFilDeceIP();
   TQCKEFCFIL_vidSyntPtDrivFilDecIP();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidComptDrivFilDeceIP                           */
/* !Description :  Défaut sur le dépassement temporel de l’activation du      */
/*                 filtrage de la décélération.                               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidIFTHENComptDeceAcv();                      */
/*  extf argret void TQCKEFCFIL_vidCptInctDrvFilDecIP();                      */
/*  extf argret void TQCKEFCFIL_vidIncCptDrivFilDecIP();                      */
/*  input boolean SftyMgt_bEnaDrivFilDeceIpCntRst;                            */
/*  input boolean SftyMgt_bEnaDrivFilDeceIpCntRun;                            */
/*  input boolean TQCKEFCFIL_bDeceIpCntRunPrev;                               */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCntRun;                              */
/*  output boolean TQCKEFCFIL_bDeceIpCntRunPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidComptDrivFilDeceIP(void)
{
   TQCKEFCFIL_vidIFTHENComptDeceAcv();
   if (SftyMgt_bEnaDrivFilDeceIpCntRst != 0)
   {
      TQCKEFCFIL_vidCptInctDrvFilDecIP();
   }
   if (SftyMgt_bEnaDrivFilDeceIpCntRun != 0)
   {
      if(TQCKEFCFIL_bDeceIpCntRunPrev == 0)
      {
         SftyMgt_tiDrivFilDeceIpCntRun = 0;
      }
      else
      {
         TQCKEFCFIL_vidIncCptDrivFilDecIP();
      }
   }
   TQCKEFCFIL_bDeceIpCntRunPrev = SftyMgt_bEnaDrivFilDeceIpCntRun;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidIFTHENComptDeceAcv                           */
/* !Description :  Démarre et raz le compteur                                 */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDrivFilDeceIp;                                     */
/*  input boolean SftyMgt_bDeceAcvIniEdge;                                    */
/*  output boolean SftyMgt_bEnaDrivFilDeceIpCntRun;                           */
/*  output boolean SftyMgt_bEnaDrivFilDeceIpCntRst;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidIFTHENComptDeceAcv(void)
{
   if (  (SftyMgt_bDrivFilDeceIp != 0)
      && (SftyMgt_bDeceAcvIniEdge == 0))
   {
      SftyMgt_bEnaDrivFilDeceIpCntRun = 1;
      SftyMgt_bEnaDrivFilDeceIpCntRst = 0;
   }
   else
   {
      SftyMgt_bEnaDrivFilDeceIpCntRun = 0;
      SftyMgt_bEnaDrivFilDeceIpCntRst = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCptInctDrvFilDecIP                           */
/* !Description :  remise à zéro du compteur de durée d'activation de filtrage*/
/*                 de décélération                                            */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_013.01                                     */
/*                 VEMS_R_10_01236_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCntRst;                              */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCnt;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCptInctDrvFilDecIP(void)
{
   SftyMgt_tiDrivFilDeceIpCntRst = 0;
   SftyMgt_tiDrivFilDeceIpCnt = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidIncCptDrivFilDecIP                           */
/* !Description :  calcul de la durée de la phase d'activation de filtrage en */
/*                 décél en cours                                             */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_014.01                                     */
/*                 VEMS_R_10_01236_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_tiDrivFilDeceIpCntRun;                               */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCntRun;                              */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCnt;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidIncCptDrivFilDecIP(void)
{
   if (SftyMgt_tiDrivFilDeceIpCntRun < 14960)
   {
      SftyMgt_tiDrivFilDeceIpCntRun = (uint16)( SftyMgt_tiDrivFilDeceIpCntRun
                                              + 40);
   }
   else
   {
      SftyMgt_tiDrivFilDeceIpCntRun = 15000;
   }
   SftyMgt_tiDrivFilDeceIpCnt = (uint16)( ( SftyMgt_tiDrivFilDeceIpCntRun
                                          + 20)
                                        / 40);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidSyntPtDrivFilDecIP                           */
/* !Description :  Choisit la pente en fonction du temps passé en             */
/*                 décélération. Peut aussi prendre la pente maximale par     */
/*                 calibration indépendamment du temps passé.                 */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 SftyMgt_tiDlyPha9;                                            */
/*  input uint16 SftyMgt_tiDrivFilDeceIpCnt;                                  */
/*  input sint16 SftyMgt_tqSlopPha9;                                          */
/*  input uint8 SftyMgt_tiDlyPha10;                                           */
/*  input sint16 SftyMgt_tqSlopPha10;                                         */
/*  input sint16 SftyMgt_tqSlopPha11;                                         */
/*  output sint16 SftyMgt_tqSlop;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidSyntPtDrivFilDecIP(void)
{
   /*F01_03_05_02_synthesePenteDrivFilDeceIP*/
   sint16   s16LocalSftyMgt_tqSlop;
   uint16   u16LocalSum;


   if (SftyMgt_tiDlyPha9 > SftyMgt_tiDrivFilDeceIpCnt)
   {
      s16LocalSftyMgt_tqSlop = SftyMgt_tqSlopPha9;
   }
   else
   {
      u16LocalSum = (uint16)(SftyMgt_tiDlyPha9 + SftyMgt_tiDlyPha10);
      if (u16LocalSum > SftyMgt_tiDrivFilDeceIpCnt)
      {
         s16LocalSftyMgt_tqSlop = SftyMgt_tqSlopPha10;
      }
      else
      {
         s16LocalSftyMgt_tqSlop = SftyMgt_tqSlopPha11;
      }
   }
   SftyMgt_tqSlop = (sint16)(s16LocalSftyMgt_tqSlop / 4);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcPfTqFiltre                               */
/* !Description :  Calcule le filtre en couple maximal permissible au niveau 2*/
/*                 en décélération et accélération. Applique les conditions   */
/*                 initiales de couples lors de l’activation du filtrage de la*/
/*                 décélération.                                              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_017.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDrivFilDeceIp;                                     */
/*  input boolean SftyMgt_bDeceAcvIniEdge;                                    */
/*  input sint16 SftyMgt_tqThdPha8;                                           */
/*  input sint16 SftyMgt_tqFilDifMin_C;                                       */
/*  input sint16 SftyMgt_tqCkDrivNotFil;                                      */
/*  input sint16 SftyMgt_tqSlop;                                              */
/*  input sint16 SftyMgt_tqCkEfcFilTol;                                       */
/*  input sint16 SftyMgt_tqCkDrivFilMin_C;                                    */
/*  input sint16 SftyMgt_tqCkDrivFilMax_C;                                    */
/*  input sint16 SftyMgt_tqOfsDrivFiNotDeceIp_C;                              */
/*  output sint16 SftyMgt_tqCkEfcFilTol;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcPfTqFiltre(void)
{
   sint16 s16LocalMin;
   sint32 s32LocalFilDiffMin;
   sint32 s32LocalSum;
   sint32 s32LocalMax;
   sint32 s32LocalSftyMgt_tqCkEfcFilTol;


   if (SftyMgt_bDrivFilDeceIp != 0)
   {
      if (SftyMgt_bDeceAcvIniEdge != 0)
      {
         s32LocalSum = (sint32)(SftyMgt_tqThdPha8 - SftyMgt_tqFilDifMin_C);
         s32LocalMax = MATHSRV_udtMAX(s32LocalSum, SftyMgt_tqCkDrivNotFil);
      }
      else
      {
         s32LocalFilDiffMin = (sint32)((-1) * SftyMgt_tqFilDifMin_C);
         s16LocalMin = (sint16)MATHSRV_udtMIN(SftyMgt_tqSlop,
                                              s32LocalFilDiffMin);
         s32LocalSum = (sint32)(SftyMgt_tqCkEfcFilTol + s16LocalMin);
         s32LocalMax = MATHSRV_udtMAX(s32LocalSum, SftyMgt_tqCkDrivNotFil);
      }
      s32LocalSftyMgt_tqCkEfcFilTol =
         MATHSRV_udtCLAMP(s32LocalMax,
                          SftyMgt_tqCkDrivFilMin_C,
                          SftyMgt_tqCkDrivFilMax_C);
   }
   else
   {
      s32LocalSftyMgt_tqCkEfcFilTol = (sint32)( SftyMgt_tqCkDrivNotFil
                                              + SftyMgt_tqOfsDrivFiNotDeceIp_C);
   }
   SftyMgt_tqCkEfcFilTol =
      (sint16)MATHSRV_udtCLAMP(s32LocalSftyMgt_tqCkEfcFilTol,
                               -32000,
                               32000);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/