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
/* !File            : TQCKEFCFIL_FCT1.C                                       */
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
/*   1 / TQCKEFCFIL_vidInitOutput                                             */
/*   2 / TQCKEFCFIL_vidCalculEstimation                                       */
/*   3 / TQCKEFCFIL_vidCalcPfTqNonfiltere                                     */
/*   4 / TQCKEFCFIL_vidCalcPrevfDecelInit                                     */
/*   5 / TQCKEFCFIL_vidTreatSdlNiv1VNiv2                                      */
/*   6 / TQCKEFCFIL_vidCalcPfDecelInit                                        */
/*   7 / TQCKEFCFIL_vidCalcPfDecelParam                                       */
/*   8 / TQCKEFCFIL_vidCalculTempoDeceIp                                      */
/*   9 / TQCKEFCFIL_vidCalcSeuilCpleDecIp                                     */
/*   10 / TQCKEFCFIL_vidCalculPenteDeceIp                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01236 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#056922                                         */
/* !OtherRefs   : CSCT_CGMT09_2398 / 2.6                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCKEFCFIL/TQCKEFCFIL_$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
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
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidInitOutput                                   */
/* !Description :  fonction qui initialise les sorties                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean SftyMgt_bDgoTqCkEfcFil;                                    */
/*  output sint16 SftyMgt_tqCkDeceIni;                                        */
/*  output uint16 SftyMgt_nEngDeceIni;                                        */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCntRst;                              */
/*  output uint16 SftyMgt_tiDrivFilDeceIpCntRun;                              */
/*  output sint16 SftyMgt_tqCkEfcFilTol;                                      */
/*  output uint8 TQCKEFCFIL_u8tiDlyOnDgoCounter;                              */
/*  output uint8 TQCKEFCFIL_u8tiDlyOnDgoIpCounter;                            */
/*  output uint8 TQCKEFCFIL_u8DlyOnDgoInvdCounter;                            */
/*  output boolean TQCKEFCFIL_bDeceIpCntRunPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidInitOutput(void)
{
   /*Outputs*/
   VEMS_vidSET(SftyMgt_bDgoTqCkEfcFil, 0);

   /*Internal variables*/
   SftyMgt_tqCkDeceIni = 0;
   SftyMgt_nEngDeceIni = 0;
   SftyMgt_tiDrivFilDeceIpCntRst = 0;
   SftyMgt_tiDrivFilDeceIpCntRun = 0;
   SftyMgt_tqCkEfcFilTol = 0;

   /*Created variables*/
   TQCKEFCFIL_u8tiDlyOnDgoCounter = 0;
   TQCKEFCFIL_u8tiDlyOnDgoIpCounter = 0;
   TQCKEFCFIL_u8DlyOnDgoInvdCounter = 0;
   TQCKEFCFIL_bDeceIpCntRunPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalculEstimation                             */
/* !Description :  Fonction qui enveloppe max simplifiée de la partie         */
/*                 applicative                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_002.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidCalcPfTqNonfiltere();                      */
/*  extf argret void TQCKEFCFIL_vidCalcPrevfDecelInit();                      */
/*  extf argret void TQCKEFCFIL_vidCalcPfDecelParam();                        */
/*  extf argret void TQCKEFCFIL_vidCalcPfTqFiltre();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalculEstimation(void)
{
   TQCKEFCFIL_vidCalcPfTqNonfiltere();
   TQCKEFCFIL_vidCalcPrevfDecelInit();
   TQCKEFCFIL_vidCalcPfDecelParam();
   TQCKEFCFIL_vidCalcPfTqFiltre();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcPfTqNonfiltere                           */
/* !Description :  Sort le minimum entre la pédale non filtrée et la sortie   */
/*                 filtrée pour prendre en compte une dynamique de la pédale  */
/*                 lors d’un filtrage (accélération non aboutie suivie d’une  */
/*                 décélération)                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_003.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input sint16 SftyMgt_tqCkDrivFilEngLim;                                   */
/*  input sint16 SftyMgt_prm_tqLimEM[5];                                      */
/*  input boolean SftyMgt_prm_bDeceAcvTqSys[5];                               */
/*  input boolean SftyMgt_bDrivFilDeceIp;                                     */
/*  input boolean SftyMgt_bTqCkDrivFilLimSel_C;                               */
/*  input boolean SftyMgt_bAcvCllTqCll;                                       */
/*  input boolean SftyMgt_bTypAcvCll_C;                                       */
/*  input sint16 SftyMgt_tqCkDrivNotFilMin_C;                                 */
/*  input sint16 SftyMgt_tqCkDrivNotFilMax_C;                                 */
/*  output sint16 SftyMgt_tqCkDrivNotFil;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcPfTqNonfiltere(void)
{
   /*F01_01_Calc_Preventif_Tq_NonFiltre*/
   boolean bLocalSftyMgt_bAcvCllTqCll;
   sint16  s16LocalSftyMgt_tqCkDrvFilEngLim;
   sint16  s16LocalSftyMgt_tqCkDrivNotFil;
   sint16  s16LocalOutputSwitch1;
   sint16  s16LocalOutputSwitch2;


   VEMS_vidGET(SftyMgt_tqCkDrivFilEngLim, s16LocalSftyMgt_tqCkDrvFilEngLim);
   VEMS_vidGET1DArrayElement(SftyMgt_prm_tqLimEM,
                             4,
                             s16LocalOutputSwitch2);

   VEMS_vidGET1DArrayElement(SftyMgt_prm_bDeceAcvTqSys,
                             4,
                             SftyMgt_bDrivFilDeceIp);

   if (SftyMgt_bTqCkDrivFilLimSel_C != 0)
   {
      s16LocalOutputSwitch1 =
         (sint16)MATHSRV_udtMIN(s16LocalSftyMgt_tqCkDrvFilEngLim,
                                s16LocalOutputSwitch2);
   }
   else
   {
      s16LocalOutputSwitch1 = s16LocalOutputSwitch2;
   }

   VEMS_vidGET(SftyMgt_bAcvCllTqCll, bLocalSftyMgt_bAcvCllTqCll);

   if (  (bLocalSftyMgt_bAcvCllTqCll != 0)
      || (SftyMgt_bTypAcvCll_C != 0))
   {
      s16LocalOutputSwitch2 = s16LocalOutputSwitch1;
   }
   else
   {
      s16LocalOutputSwitch2 =
         (sint16)MATHSRV_udtMAX(s16LocalSftyMgt_tqCkDrvFilEngLim,
                                s16LocalOutputSwitch1);
   }

   s16LocalSftyMgt_tqCkDrivNotFil =
      (sint16)MATHSRV_udtCLAMP(s16LocalOutputSwitch2,
                               SftyMgt_tqCkDrivNotFilMin_C,
                               SftyMgt_tqCkDrivNotFilMax_C);
   SftyMgt_tqCkDrivNotFil =
      (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_tqCkDrivNotFil,
                               -32000,
                               32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcPrevfDecelInit                           */
/* !Description :  Calcule le régime moteur et le couple lors de l’activation */
/*                 exacte du filtrage en décélération au niv1                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidTreatSdlNiv1VNiv2();                       */
/*  extf argret void TQCKEFCFIL_vidCalcPfDecelInit();                         */
/*  extf argret void TQCKEFCFIL_vidPriseCmptRapportBV();                      */
/*  input boolean SftyMgt_bDeceAcvIniEdge;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcPrevfDecelInit(void)
{
   /*F01_02_Calc_Preventif_Decel_Init*/
   TQCKEFCFIL_vidTreatSdlNiv1VNiv2();
   if (SftyMgt_bDeceAcvIniEdge != 0)
   {
      TQCKEFCFIL_vidCalcPfDecelInit();
   }
   TQCKEFCFIL_vidPriseCmptRapportBV();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidTreatSdlNiv1VNiv2                            */
/* !Description :  Gère la dynamique d’activation du niveau 1 qui a lieu lors */
/*                 de deux appels de la fonction de surveillance au niveau 2  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input boolean SftyMgt_prm_bDeceAcvTqSys[5];                               */
/*  input uint8 SftyMgt_idxDeceAcv;                                           */
/*  output uint8 SftyMgt_idxDeceAcv;                                          */
/*  output boolean SftyMgt_bDeceAcvIniEdge;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidTreatSdlNiv1VNiv2(void)
{
   boolean bLocalField1;
   boolean bLocalField2;
   boolean bLocalField3;
   boolean bLocalField4;
   boolean bLocalField5;
   boolean bLocalSftyMgt_prm_bDeceAcvTqSys[5];
   /*QAC Warning : Msg(2:3204) & Msg(2:3132): No impact*/

   VEMS_vidGET1DArray(SftyMgt_prm_bDeceAcvTqSys,
                      5,
                      bLocalSftyMgt_prm_bDeceAcvTqSys);


   if (bLocalSftyMgt_prm_bDeceAcvTqSys[4] != 0)
   {
      bLocalField5 = 1;
   }
   else
   {
      bLocalField5 = 0;
   }
   if (bLocalSftyMgt_prm_bDeceAcvTqSys[3] != 0)
   {
      bLocalField4 = 1;
   }
   else
   {
      bLocalField4 = 0;
   }
   if (  (bLocalField4 == 0)
      && (bLocalField5 != 0))
   {
      SftyMgt_idxDeceAcv = 4;
   }
   else
   {
      if (bLocalSftyMgt_prm_bDeceAcvTqSys[2] != 0)
      {
         bLocalField3 = 1;
      }
      else
      {
         bLocalField3 = 0;
      }
      if (  (bLocalField3 == 0)
         && (bLocalField4 != 0))
      {
         SftyMgt_idxDeceAcv = 3;
      }
      else
      {
         if (bLocalSftyMgt_prm_bDeceAcvTqSys[1] != 0)
         {
            bLocalField2 = 1;
         }
         else
         {
            bLocalField2 = 0;
         }
         if (  (bLocalField2 == 0)
            && (bLocalField3 != 0))
         {
            SftyMgt_idxDeceAcv = 2;
         }
         else
         {
            if (bLocalSftyMgt_prm_bDeceAcvTqSys[0] != 0)
            {
               bLocalField1 = 1;
            }
            else
            {
               bLocalField1 = 0;
            }
            if (  (bLocalField1 == 0)
               && (bLocalField2 != 0))
            {
               SftyMgt_idxDeceAcv = 1;
            }
            else
            {
               SftyMgt_idxDeceAcv = 0;
            }
         }
      }
   }

   if (  (SftyMgt_idxDeceAcv != 0)
      && (bLocalField5 != 0))
   {
      SftyMgt_bDeceAcvIniEdge = 1;
   }
   else
   {
      SftyMgt_bDeceAcvIniEdge = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcPfDecelInit                              */
/* !Description :  Prend les valeurs correspondant à l’index lors du front    */
/*                 d’activation du filtrage de la décélération.               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_006.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 SftyMgt_idxDeceAcv;                                           */
/*  input sint16 SftyMgt_prm_tqLimEM[5];                                      */
/*  input uint16 SftyMgt_prm_nCkFil[5];                                       */
/*  input uint8 SftyMgt_prm_noGearCordDrivFil[5];                             */
/*  output sint16 SftyMgt_tqCkDeceIni;                                        */
/*  output uint16 SftyMgt_nEngDeceIni;                                        */
/*  output uint8 SftyMgt_noGearDeceIniTmp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcPfDecelInit(void)
{
   /*F01_02_02_Calc_Pf_Decel_Init*/
   uint8   u8LocalIndex;
   uint8   u8LocalSftyMgtprmnoGearCrdDrvFil;
   uint16  u16LocalSftyMgt_prm_nCkFil;
   sint16  s16LocalSftyMgt_prm_tqLimEM;


   u8LocalIndex = (uint8)MATHSRV_udtMIN(SftyMgt_idxDeceAcv, 4);

   VEMS_vidGET1DArrayElement(SftyMgt_prm_tqLimEM,
                             u8LocalIndex,
                             s16LocalSftyMgt_prm_tqLimEM);

   SftyMgt_tqCkDeceIni =
      (sint16)MATHSRV_udtCLAMP(s16LocalSftyMgt_prm_tqLimEM, -32000, 32000);

   VEMS_vidGET1DArrayElement(SftyMgt_prm_nCkFil,
                             u8LocalIndex,
                             u16LocalSftyMgt_prm_nCkFil);
   SftyMgt_nEngDeceIni = (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_prm_nCkFil,
                                                32000);
   VEMS_vidGET1DArrayElement(SftyMgt_prm_noGearCordDrivFil,
                             u8LocalIndex,
                             u8LocalSftyMgtprmnoGearCrdDrvFil);
   SftyMgt_noGearDeceIniTmp =
      (uint8)MATHSRV_udtMIN(u8LocalSftyMgtprmnoGearCrdDrvFil, 8);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcPfDecelParam                             */
/* !Description :  Calcule les paramètres de seuils, de temps et la pente     */
/*                 correspondant à la maximisation du filtrage.               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidcalIdxFacPreLookup();                      */
/*  extf argret void TQCKEFCFIL_vidCalculTempoDeceIp();                       */
/*  extf argret void TQCKEFCFIL_vidCalcSeuilCpleDecIp();                      */
/*  extf argret void TQCKEFCFIL_vidCalculPenteDeceIp();                       */
/*  extf argret void TQCKEFCFIL_vidChoiPteDecIPCalCpt();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcPfDecelParam(void)
{
   TQCKEFCFIL_vidcalIdxFacPreLookup();
   TQCKEFCFIL_vidCalculTempoDeceIp();
   TQCKEFCFIL_vidCalcSeuilCpleDecIp();
   TQCKEFCFIL_vidCalculPenteDeceIp();
   TQCKEFCFIL_vidChoiPteDecIPCalCpt();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalculTempoDeceIp                            */
/* !Description :  Calcule les différents temps des pentes de manière         */
/*                 simplifiée                                                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_008.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNoGear;                              */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxTqFil;                               */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNEngTi;                              */
/*  input uint16 SftyMgt_tiDlyPha9Max_M[8][7];                                */
/*  input uint8 SftyMgt_facTiPha9Max_M[12][7];                                */
/*  input uint16 SftyMgt_tiDlyPha10Max_M[8][7];                               */
/*  input uint16 SftyMgt_facTiPha10Max_M[12][7];                              */
/*  input uint16 SftyMgt_tiDlyPha11Max_M[8][7];                               */
/*  input uint16 SftyMgt_facTiPha11Max_M[12][7];                              */
/*  output uint8 SftyMgt_tiDlyPha9;                                           */
/*  output uint8 SftyMgt_tiDlyPha10;                                          */
/*  output uint8 SftyMgt_tiDlyPha11;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalculTempoDeceIp(void)
{
   /*F01_03_02_calculTempoDeceIp*/
   uint8    u8LocalInterp2D2;
   uint16   u16LocalSftyMgt_tiDlyPha9;
   uint16   u16LocalClcParaIdxNoGear;
   uint16   u16LocalClcParaIdxNEngTi;
   uint16   u16LocalClcParaIdxTqFil;
   uint16   u16LocalInterp2D1;
   uint16   u16LocalInterp2D3;
   uint16   u16LocalInterp2D4;
   uint16   u16LocalInterp2D5;
   uint16   u16LocalInterp2D6;
   uint32   u32LocalSftyMgt_tiDlyPha10;
   uint32   u32LocalSftyMgt_tiDlyPha11;


   u16LocalClcParaIdxNoGear =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16ClcParaIdxNoGear, 1536);
   u16LocalClcParaIdxTqFil =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16ClcParaIdxTqFil, 2816);
   u16LocalClcParaIdxNEngTi =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16ClcParaIdxNEngTi, 1792);
   /*Production of SftyMgt_tiDlyPha9*/
   u16LocalInterp2D1 = MATHSRV_u16Interp2d(&SftyMgt_tiDlyPha9Max_M[0][0],
                                           u16LocalClcParaIdxNEngTi,
                                           u16LocalClcParaIdxNoGear,
                                           7);

   u8LocalInterp2D2 = MATHSRV_u8Interp2d(&SftyMgt_facTiPha9Max_M[0][0],
                                         u16LocalClcParaIdxTqFil,
                                         u16LocalClcParaIdxNoGear,
                                         7);

   u16LocalSftyMgt_tiDlyPha9 = (uint16)( (uint32)( u16LocalInterp2D1
                                                 * u8LocalInterp2D2)
                                       / 400);

   SftyMgt_tiDlyPha9 = (uint8)MATHSRV_udtMIN(u16LocalSftyMgt_tiDlyPha9, 100);

   /*Production of SftyMgt_tiDlyPha10*/
   u16LocalInterp2D3 = MATHSRV_u16Interp2d(&SftyMgt_tiDlyPha10Max_M[0][0],
                                           u16LocalClcParaIdxNEngTi,
                                           u16LocalClcParaIdxNoGear,
                                           7);

   u16LocalInterp2D4 = MATHSRV_u16Interp2d(&SftyMgt_facTiPha10Max_M[0][0],
                                           u16LocalClcParaIdxTqFil,
                                           u16LocalClcParaIdxNoGear,
                                           7);

   u32LocalSftyMgt_tiDlyPha10 = ( (uint32)( u16LocalInterp2D3
                                          * u16LocalInterp2D4)
                                / 512);

   SftyMgt_tiDlyPha10 = (uint8)MATHSRV_udtMIN(u32LocalSftyMgt_tiDlyPha10, 100);

   /*Production of SftyMgt_tiDlyPha11*/
   u16LocalInterp2D5 = MATHSRV_u16Interp2d(&SftyMgt_tiDlyPha11Max_M[0][0],
                                           u16LocalClcParaIdxNEngTi,
                                           u16LocalClcParaIdxNoGear,
                                           7);

   u16LocalInterp2D6 = MATHSRV_u16Interp2d(&SftyMgt_facTiPha11Max_M[0][0],
                                           u16LocalClcParaIdxTqFil,
                                           u16LocalClcParaIdxNoGear,
                                           7);

   u32LocalSftyMgt_tiDlyPha11 = ( (uint32)( u16LocalInterp2D5
                                          * u16LocalInterp2D6)
                                / 512);
   SftyMgt_tiDlyPha11 = (uint8)MATHSRV_udtMIN(u32LocalSftyMgt_tiDlyPha11, 100);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalcSeuilCpleDecIp                           */
/* !Description :  Calcule les différents seuils des pentes de manière        */
/*                 simplifiée                                                 */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_009.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNoGear;                              */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxTqFil;                               */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNEngThd;                             */
/*  input boolean SftyMgt_bThdPha8Sel_C;                                      */
/*  input uint16 SftyMgt_tqThdPha8BasMax_M[12][7];                            */
/*  input uint16 SftyMgt_tqThdPha8TypMax_M[12][7];                            */
/*  input uint16 SftyMgt_facPha8Max_T[12];                                    */
/*  input sint16 SftyMgt_tqCkDeceIni;                                         */
/*  input uint16 SftyMgt_tqThdPha9BasMax_M[12][7];                            */
/*  input uint16 SftyMgt_tqThdPha9TypMax_M[12][7];                            */
/*  input uint16 SftyMgt_facPha9Max_T[12];                                    */
/*  input sint16 SftyMgt_tqThdPha8;                                           */
/*  input uint16 SftyMgt_tqThdPha10Max_M[12][7];                              */
/*  input uint16 SftyMgt_facPha10Max_T[12];                                   */
/*  input sint16 SftyMgt_tqThdPha9;                                           */
/*  output sint16 SftyMgt_tqThdPha8;                                          */
/*  output sint16 SftyMgt_tqThdPha9;                                          */
/*  output sint16 SftyMgt_tqThdPha10;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalcSeuilCpleDecIp(void)
{
   /*F01_03_03_calculSeuilCoupleDeceIp*/
   uint16  u16LocalInterp2D1;
   uint16  u16LocalInterp2D2;
   uint16  u16LocalInterp2D3;
   uint16  u16LocalInterp2D4;
   uint16  u16LocalInterp2D5;
   uint16  u16LocalInterp1D1;
   uint16  u16LocalInterp1D2;
   uint16  u16LocalInterp1D3;
   uint16  u16LocalClcParaIdxNoGear;
   uint16  u16LocalClcParaIdxNEngThd;
   uint16  u16LocalClcParaIdxTqFil;
   uint32  u32LocalMultiplication1;
   uint32  u32LocalMultiplication2;
   uint32  u32LocalMultiplication3;
   sint32  s32LocalSftyMgt_tqThdPha8;
   sint32  s32LocalSftyMgt_tqThdPha9;
   sint32  s32LocalSftyMgt_tqThdPha10;
   uint32  u32LocalMultiSum1;
   uint32  u32LocalMultiSum2;
   uint32  u32LocalMultiSum3;
   uint32  u32LocalSftyMgt_tqThdPha8;
   uint32  u32LocalSftyMgt_tqThdPha9;
   uint32  u32LocalSftyMgt_tqThdPha10;
   uint32  u32LocalMultiSum;


   u16LocalClcParaIdxNoGear =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16ClcParaIdxNoGear, 1536);
   u16LocalClcParaIdxTqFil =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16ClcParaIdxTqFil, 2816);
   u16LocalClcParaIdxNEngThd =
      (uint16)MATHSRV_udtMIN(TQCKEFCFIL_u16ClcParaIdxNEngThd, 2816);
   /*Production of SftyMgt_tqThdPha8*/
   if (SftyMgt_bThdPha8Sel_C != 0)
   {
      u16LocalInterp2D1 = MATHSRV_u16Interp2d(&SftyMgt_tqThdPha8BasMax_M[0][0],
                                              u16LocalClcParaIdxNEngThd,
                                              u16LocalClcParaIdxNoGear,
                                              7);
      u16LocalInterp2D2 = MATHSRV_u16Interp2d(&SftyMgt_tqThdPha8TypMax_M[0][0],
                                              u16LocalClcParaIdxNEngThd,
                                              u16LocalClcParaIdxNoGear,
                                              7);
      u16LocalInterp1D1 = MATHSRV_u16Interp1d(SftyMgt_facPha8Max_T,
                                              u16LocalClcParaIdxTqFil);

      u32LocalMultiplication1 = (uint32)(u16LocalInterp2D2 * u16LocalInterp1D1);
      u32LocalMultiSum1 = ( (uint32)(100 * u16LocalInterp2D2)
                          + (uint32)(32000 * u16LocalInterp1D1));

      if (u32LocalMultiplication1 < u32LocalMultiSum1)
      {
         s32LocalSftyMgt_tqThdPha8 =
            ( (sint32)(u32LocalMultiplication1 - u32LocalMultiSum1)
            + (sint32)(100 * u16LocalInterp2D1));


         s32LocalSftyMgt_tqThdPha8 = s32LocalSftyMgt_tqThdPha8 / 100;
      }
      else
      {
         u32LocalMultiSum = u32LocalMultiSum1 + 32000000;
         if (u32LocalMultiplication1 > u32LocalMultiSum)
         {
            s32LocalSftyMgt_tqThdPha8 = 32000;
         }
         else
         {
            u32LocalSftyMgt_tqThdPha8 = ( ( u32LocalMultiplication1
                                          - u32LocalMultiSum1)
                                        + (uint32)( 100 * u16LocalInterp2D1));
            s32LocalSftyMgt_tqThdPha8 = (sint32)( u32LocalSftyMgt_tqThdPha8
                                                / 100);
         }
      }
   }
   else
   {
      s32LocalSftyMgt_tqThdPha8 = SftyMgt_tqCkDeceIni;
   }
   SftyMgt_tqThdPha8 = (sint16)MATHSRV_udtCLAMP(s32LocalSftyMgt_tqThdPha8,
                                                -32000,
                                                32000);
   /*Production of SftyMgt_tqThdPha9*/
   u16LocalInterp2D3 =
      MATHSRV_u16Interp2d(&SftyMgt_tqThdPha9BasMax_M[0][0],
                          u16LocalClcParaIdxNEngThd,
                          u16LocalClcParaIdxNoGear,
                          7);
   u16LocalInterp2D4 =
      MATHSRV_u16Interp2d(&SftyMgt_tqThdPha9TypMax_M[0][0],
                          u16LocalClcParaIdxNEngThd,
                          u16LocalClcParaIdxNoGear,
                          7);
   u16LocalInterp1D2 = MATHSRV_u16Interp1d(SftyMgt_facPha9Max_T,
                                           u16LocalClcParaIdxTqFil);

   u32LocalMultiplication2 = (uint32)(u16LocalInterp2D4 * u16LocalInterp1D2);
   u32LocalMultiSum2 = (100 * u16LocalInterp2D4) + (32000 * u16LocalInterp1D2);
   if (u32LocalMultiplication2 < u32LocalMultiSum2)
   {
      s32LocalSftyMgt_tqThdPha9 =
         ( (sint32)(u32LocalMultiplication2 - u32LocalMultiSum2)
         + (sint32)(100 * u16LocalInterp2D3));

      s32LocalSftyMgt_tqThdPha9 = s32LocalSftyMgt_tqThdPha9 / 100;
   }
   else
   {
      u32LocalMultiSum = u32LocalMultiSum2 + 32000000;
      if (u32LocalMultiplication2 > u32LocalMultiSum)
      {
         s32LocalSftyMgt_tqThdPha9 = 32000;
      }
      else
      {
         u32LocalSftyMgt_tqThdPha9 = ( ( u32LocalMultiplication2
                                       - u32LocalMultiSum2)
                                     + (uint32)( 100
                                               * u16LocalInterp2D3));
         s32LocalSftyMgt_tqThdPha9 = (sint32)( u32LocalSftyMgt_tqThdPha9
                                             / 100);
      }
   }

   s32LocalSftyMgt_tqThdPha9 = MATHSRV_udtMIN(s32LocalSftyMgt_tqThdPha9,
                                              SftyMgt_tqThdPha8);

   SftyMgt_tqThdPha9 =(sint16)MATHSRV_udtMAX(s32LocalSftyMgt_tqThdPha9,
                                             -32000);

   /*Production of SftyMgt_tqThdPha10*/
   u16LocalInterp2D5 =
      MATHSRV_u16Interp2d(&SftyMgt_tqThdPha10Max_M[0][0],
                          u16LocalClcParaIdxNEngThd,
                          u16LocalClcParaIdxNoGear,
                          7);
   u16LocalInterp1D3 =
      MATHSRV_u16Interp1d(SftyMgt_facPha10Max_T,
                          u16LocalClcParaIdxTqFil);

   u32LocalMultiplication3 =
         (uint32)(u16LocalInterp2D5 * u16LocalInterp1D3);
   u32LocalMultiSum3 = (100 * u16LocalInterp2D5) + (32000 * u16LocalInterp1D3);
   if (u32LocalMultiplication3 < u32LocalMultiSum3)
   {
      s32LocalSftyMgt_tqThdPha10 =
         (sint32)(u32LocalMultiplication3 - u32LocalMultiSum3);

      s32LocalSftyMgt_tqThdPha10 = ( ( s32LocalSftyMgt_tqThdPha10
                                     + 3200000
                                     + 50)
                                   / 100);
      s32LocalSftyMgt_tqThdPha10 = ( SftyMgt_tqThdPha9
                                   - s32LocalSftyMgt_tqThdPha10);
   }
   else
   {
      u32LocalSftyMgt_tqThdPha10 = ( u32LocalMultiplication3
                                   - u32LocalMultiSum3);

      u32LocalSftyMgt_tqThdPha10 = (u32LocalSftyMgt_tqThdPha10 + 3200000) / 100;
      s32LocalSftyMgt_tqThdPha10 = ( SftyMgt_tqThdPha9
                                   - (sint32)u32LocalSftyMgt_tqThdPha10);
   }
   s32LocalSftyMgt_tqThdPha10 = MATHSRV_udtMIN(s32LocalSftyMgt_tqThdPha10,
                                               SftyMgt_tqThdPha9);

   SftyMgt_tqThdPha10 = (sint16) MATHSRV_udtMAX(s32LocalSftyMgt_tqThdPha10,
                                                -32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidCalculPenteDeceIp                            */
/* !Description :  Décomposition du calcul des pentes, des tempos et de la    */
/*                 coordination.                                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_028.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQCKEFCFIL_vidCalcDiffCplePPhase();                      */
/*  extf argret void TQCKEFCFIL_vidCalcDureeDesPhases();                      */
/*  extf argret void TQCKEFCFIL_vidCalcEtCoordPentes();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidCalculPenteDeceIp(void)
{
   TQCKEFCFIL_vidCalcDiffCplePPhase();
   TQCKEFCFIL_vidCalcDureeDesPhases();
   TQCKEFCFIL_vidCalcEtCoordPentes();
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/