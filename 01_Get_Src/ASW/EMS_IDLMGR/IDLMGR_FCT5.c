/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLMGR                                                  */
/* !Description     : IDLMGR component                                        */
/*                                                                            */
/* !Module          : IDLMGR                                                  */
/* !Description     : GESTION DU RALENTI                                      */
/*                                                                            */
/* !File            : IDLMGR_FCT5.C                                           */
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
/*   1 / IDLMGR_vidCalculer_info_regime                                       */
/*   2 / IDLMGR_vidCalculer_regime_filtre                                     */
/*   3 / IDLMGR_vidCalculer_regime_estime                                     */
/*   4 / IDLMGR_vidSuperv_regu_de_ralenti                                     */
/*   5 / IDLMGR_vidCalculer_valeurs_replis                                    */
/*   6 / IDLMGR_vidBoucler_stuct_couple                                       */
/*   7 / IDLMGR_vidCalc_pertes_convr_BVA                                      */
/*   8 / IDLMGR_vidDeterminer_demarrage                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5010777 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0003 / 2.9                                      */
/* !OtherRefs   : VEMS V02 ECU#063158                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLMGR/IDLMGR_FCT$*/
/* $Revision::   1.19     $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLMGR.h"
#include "IDLMGR_L.h"
#include "IDLMGR_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_info_regime                             */
/* !Description :  Cette fonction calcule le gradient de régime moteur.       */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidCalculer_regime_filtre();                      */
/*  extf argret void IDLMGR_vidCalculer_regime_estime();                      */
/*  extf argret void IDLMGR_vidCalculer_reg_grad_spec();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_info_regime(void)
{
   IDLMGR_vidCalculer_regime_filtre();
   IDLMGR_vidCalculer_regime_estime();
   IDLMGR_vidCalculer_reg_grad_spec();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_regime_filtre                           */
/* !Description :  Cette fonction calcule deux régimes moteur filtrés (un pour*/
/*                 le régime moteur filtré, et un pour le gradient de régime  */
/*                 moteur filtré).                                            */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 IdlSys_nEngFil1;                                             */
/*  input uint16 IdlSys_tiFilNEng1_A[8];                                      */
/*  input uint16 IDLMGR_u16InputFilNEng1Prev;                                 */
/*  input uint16 IdlSys_tiFilNEng1_T[8];                                      */
/*  input uint16 IdlSys_nEngFil2;                                             */
/*  input uint16 IdlSys_tiFilNEng2_A[8];                                      */
/*  input uint16 IDLMGR_u16InputFilNEng2Prev;                                 */
/*  input uint16 IdlSys_tiFilNEng2_T[8];                                      */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiFilNEng1_MP;                                        */
/*  input uint32 IDLMGR_u32FiltreEngFil1Mem;                                  */
/*  input uint16 IdlSys_tiFilNEng2_MP;                                        */
/*  input uint32 IDLMGR_u32FiltreEngFil2Mem;                                  */
/*  output uint16 IdlSys_tiFilNEng1_MP;                                       */
/*  output uint16 IDLMGR_u16InputFilNEng1Prev;                                */
/*  output uint16 IdlSys_tiFilNEng2_MP;                                       */
/*  output uint16 IDLMGR_u16InputFilNEng2Prev;                                */
/*  output uint32 IDLMGR_u32FiltreEngFil1Mem;                                 */
/*  output uint32 IDLMGR_u32FiltreEngFil2Mem;                                 */
/*  output uint16 IdlSys_nEngFil1;                                            */
/*  output uint16 IdlSys_nEngFil2;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_regime_filtre(void)
{
   boolean bLocalIdlSys_bEnaIdl;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalInputFilNEng1Prev;
   uint16  u16LocalInputFilNEng2Prev;
   uint16  u16LocalExt_nEngClc0;
   uint16  u16LocalFilNEng1Interp;
   uint16  u16LocalCalcPara;
   uint16  u16LocalMeasMemValue;
   uint16  u16LocalFilNEng2Interp;
   uint16  u16LocalIdlSys_nEngFil;
   uint16  u16LocalIdlSys_nEngFil2;
   uint32  u32LocalFilterGain;
   sint32  s32LocalInputFilNEng1Prev;
   sint32  s32LocalInputFilNEng2Prev;


   /*calc 1*/
   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   s32LocalInputFilNEng1Prev =
      (sint32)(u16LocalExt_nEngClc0 - IdlSys_nEngFil1) / 4;
   u16LocalInputFilNEng1Prev =
      (uint16)MATHSRV_udtMAX(s32LocalInputFilNEng1Prev, 0);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(IdlSys_tiFilNEng1_A,
                                                   IDLMGR_u16InputFilNEng1Prev,
                                                   8);
   u16LocalFilNEng1Interp = MATHSRV_u16Interp1d(IdlSys_tiFilNEng1_T,
                                                u16LocalCalcPara);
   IdlSys_tiFilNEng1_MP = (uint16)MATHSRV_udtMIN(u16LocalFilNEng1Interp, 2048);
   IDLMGR_u16InputFilNEng1Prev = u16LocalInputFilNEng1Prev;


   /*calc 2*/
   s32LocalInputFilNEng2Prev =
      (sint32)(u16LocalExt_nEngClc0 - IdlSys_nEngFil2) / 4;
   u16LocalInputFilNEng2Prev =
      (uint16)MATHSRV_udtMAX(s32LocalInputFilNEng2Prev, 0);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(IdlSys_tiFilNEng2_A,
                                                   IDLMGR_u16InputFilNEng2Prev,
                                                   8);
   u16LocalFilNEng2Interp = MATHSRV_u16Interp1d(IdlSys_tiFilNEng2_T,
                                                u16LocalCalcPara);
   IdlSys_tiFilNEng2_MP = (uint16)MATHSRV_udtMIN(u16LocalFilNEng2Interp, 2048);

   IDLMGR_u16InputFilNEng2Prev = u16LocalInputFilNEng2Prev;
   VEMS_vidGET(IdlSys_bEnaIdl, bLocalIdlSys_bEnaIdl);
   if (bLocalIdlSys_bEnaIdl != 0)
   {
      /*filter1*/
      VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
      u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilNEng1_MP * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilNEng1_MP == 0))
      {
         u16LocalIdlSys_nEngFil = u16LocalExt_nEngClc0;
         u16LocalMeasMemValue =
            (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
         IDLMGR_u32FiltreEngFil1Mem = (uint32)(u16LocalMeasMemValue * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608 * u8LocalExt_tiTDC)
                            / u32LocalFilterGain;
         u16LocalIdlSys_nEngFil =
            MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_u32FiltreEngFil1Mem,
                                            u16LocalExt_nEngClc0);
      }
      /*filter2*/
      u32LocalFilterGain =
         (uint32)((128 * u8LocalExt_tiTDC) + (IdlSys_tiFilNEng2_MP * 125));
      if (  (u32LocalFilterGain == 0)
         || (IdlSys_tiFilNEng2_MP == 0))
      {
         u16LocalIdlSys_nEngFil2 = u16LocalExt_nEngClc0;
         u16LocalMeasMemValue =
            (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
         IDLMGR_u32FiltreEngFil2Mem = (uint32)(u16LocalMeasMemValue * 65536);
      }
      else
      {
         u32LocalFilterGain = (uint32)( 8388608 * u8LocalExt_tiTDC)
                            / u32LocalFilterGain;
         u16LocalIdlSys_nEngFil2 =
            MATHSRV_u16FirstOrderFilterGu16((uint16)u32LocalFilterGain,
                                            &IDLMGR_u32FiltreEngFil2Mem,
                                            u16LocalExt_nEngClc0);
      }
   }
   else
   {
      u16LocalIdlSys_nEngFil = u16LocalExt_nEngClc0;
      u16LocalIdlSys_nEngFil2 = u16LocalExt_nEngClc0;
      u16LocalMeasMemValue =
         (uint16)MATHSRV_udtMIN(u16LocalExt_nEngClc0, 32000);
      IDLMGR_u32FiltreEngFil1Mem = (uint32)(u16LocalMeasMemValue * 65536);
      IDLMGR_u32FiltreEngFil2Mem = (uint32)(u16LocalMeasMemValue * 65536);
   }
   IdlSys_nEngFil1 = (uint16)MATHSRV_udtMIN(u16LocalIdlSys_nEngFil, 32000);
   IdlSys_nEngFil2 = (uint16)MATHSRV_udtMIN(u16LocalIdlSys_nEngFil2, 32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_regime_estime                           */
/* !Description :  Cette fonction estime deux régimes moteur (un pour le      */
/*                 régime filtré, et un pour le gradient de régime filtré.    */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IDLMGR_vidCalc_inertie_veh();                            */
/*  extf argret void IDLMGR_vidCalc_transition_gains();                       */
/*  extf argret void IDLMGR_vidCalc_gains_filt_regime();                      */
/*  extf argret void IDLMGR_vidCalc_gains_filtre_grad();                      */
/*  extf argret void IDLMGR_vidEstimer_regime();                              */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input sint16 TqSys_tqCkEngReal;                                           */
/*  input sint16 IdlSys_tqMaxClu;                                             */
/*  input uint16 IdlSys_jVehFil;                                              */
/*  input uint16 IdlSys_facAntNEng;                                           */
/*  input uint16 IdlSys_facIntNEng;                                           */
/*  input uint16 IdlSys_tiFilNEng;                                            */
/*  input uint16 IdlSys_facAntNGrd;                                           */
/*  input uint16 IdlSys_facIntNGrd;                                           */
/*  input uint16 IdlSys_tiFilNGrd;                                            */
/*  input uint16 IdlSys_nEngEstim[2];                                         */
/*  output boolean IdlSys_bRstNEstim;                                         */
/*  output sint16 IdlSys_nGrdPred;                                            */
/*  output uint16 IdlSys_facAnt[2];                                           */
/*  output uint16 IdlSys_facInt[2];                                           */
/*  output uint16 IdlSys_tiFil[2];                                            */
/*  output uint16 IdlSys_nEngEstim1;                                          */
/*  output uint16 IdlSys_nEngEstim2;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_regime_estime(void)
{
   uint16 u16LocalExt_nEngClc0;
   sint16 s16LocalTqSys_tqCkEngReal;
   sint32 s32LocalCalcOperation;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   VEMS_vidGET(TqSys_tqCkEngReal, s16LocalTqSys_tqCkEngReal);
   if (u16LocalExt_nEngClc0 < 1200)
   {
      IdlSys_bRstNEstim = 1;
   }
   else
   {
      IdlSys_bRstNEstim = 0;
   }
   IDLMGR_vidCalc_inertie_veh();
   /* IdlSys_aEngPred = (240 / pi )* ( (TqSys_tqCkEngReal - IdlSys_tqMaxClu)
                                     / (IdlSys_jVehFil + 1))               */

   s32LocalCalcOperation = (sint32)( ( ( s16LocalTqSys_tqCkEngReal
                                       - IdlSys_tqMaxClu)
                                     * 7639)
                                   / ((IdlSys_jVehFil + 1) * 100));
   IdlSys_nGrdPred = (sint16)MATHSRV_udtCLAMP(s32LocalCalcOperation,
                                              -8000,
                                              8000);

   IDLMGR_vidCalc_transition_gains();
   IDLMGR_vidCalc_gains_filt_regime();
   IDLMGR_vidCalc_gains_filtre_grad();

   IdlSys_facAnt[0] = (uint16)MATHSRV_udtMIN(IdlSys_facAntNEng, 4096);
   IdlSys_facInt[0] = (uint16)MATHSRV_udtMIN(IdlSys_facIntNEng, 4096);
   IdlSys_tiFil[0] = (uint16)MATHSRV_udtMIN(IdlSys_tiFilNEng, 2048);
   IdlSys_facAnt[1] = (uint16)MATHSRV_udtMIN(IdlSys_facAntNGrd, 4096);
   IdlSys_facInt[1] = (uint16)MATHSRV_udtMIN(IdlSys_facIntNGrd, 4096);
   IdlSys_tiFil[1] = (uint16)MATHSRV_udtMIN(IdlSys_tiFilNGrd, 2048);

   IDLMGR_vidEstimer_regime();
   IdlSys_nEngEstim1 = (uint16)MATHSRV_udtMIN(IdlSys_nEngEstim[0], 32000);
   IdlSys_nEngEstim2 =  (uint16)MATHSRV_udtMIN(IdlSys_nEngEstim[1], 32000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidSuperv_regu_de_ralenti                           */
/* !Description :  L’automate d’état de commande du régulateur et de la       */
/*                 consigne dynamique possède 2 états macroscopiques :        */
/*                 Régulateur désactivé (« Regulateur_OFF »), Régulateur      */
/*                 activé (« Regulateur_ON/ »).                               */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_030.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st14 IDLMGR_stRegSup;                                               */
/*  input boolean IdlSys_bIniIdl;                                             */
/*  input boolean IdlSys_bAuthIdlCtlStEng;                                    */
/*  input boolean IdlSys_bAcvAntiStallAT;                                     */
/*  input boolean IdlSys_bAcvIdlCtlDyn;                                       */
/*  input boolean IdlSys_bAcvIdlCtlEngSpd;                                    */
/*  input boolean IdlSys_bAcvIdlCtlStrt;                                      */
/*  input boolean IdlSys_bDeacIdlCtlEngSpd;                                   */
/*  input boolean IdlSys_bEngNOnIdl;                                          */
/*  input boolean IdlSys_bIniIdlCtlCrawlChg;                                  */
/*  input boolean IdlSys_bIniIdlCtlGearChg;                                   */
/*  input boolean IdlSys_bIniIdlCtlModChg;                                    */
/*  input boolean IdlSys_bIniIdlCtlDyn;                                       */
/*  output st14 IDLMGR_stRegSup;                                              */
/*  output boolean IdlSys_bAcvIdlCtl;                                         */
/*  output boolean IdlSys_bIniIdlCtl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidSuperv_regu_de_ralenti(void)
{

   switch (IDLMGR_stRegSup)
   {
      case REGULATOR_OFF:
         if (  (IdlSys_bIniIdl == 0)
            && (IdlSys_bAuthIdlCtlStEng != 0)
            && (  (IdlSys_bAcvAntiStallAT != 0)
               || (IdlSys_bAcvIdlCtlDyn != 0)
               || (IdlSys_bAcvIdlCtlEngSpd != 0)
               || (IdlSys_bAcvIdlCtlStrt !=0)))
         {
            IDLMGR_stRegSup = INIT_ENTRY;
            VEMS_vidSET(IdlSys_bAcvIdlCtl, 1);
            VEMS_vidSET(IdlSys_bIniIdlCtl, 1);
         }
         break;

      case INIT_ENTRY:
         if (  (IdlSys_bIniIdl != 0)
            || (IdlSys_bAuthIdlCtlStEng == 0)
            || (  (IdlSys_bAcvAntiStallAT == 0)
               && (IdlSys_bAcvIdlCtlDyn == 0)
               && (IdlSys_bDeacIdlCtlEngSpd != 0)
               && (IdlSys_bEngNOnIdl == 0)
               && (IdlSys_bAcvIdlCtlStrt == 0)))
         {
            IDLMGR_stRegSup = REGULATOR_OFF;
            VEMS_vidSET(IdlSys_bAcvIdlCtl, 0);
            VEMS_vidSET(IdlSys_bIniIdlCtl, 0);
         }
         else
         {
            if (  (IdlSys_bAcvAntiStallAT == 0)
               && (IdlSys_bIniIdlCtlCrawlChg == 0)
               && (IdlSys_bIniIdlCtlGearChg == 0)
               && (IdlSys_bIniIdlCtlModChg == 0)
               && (IdlSys_bIniIdlCtlDyn == 0)
               && (IdlSys_bAcvIdlCtlStrt == 0))
            {
               IDLMGR_stRegSup = WAIT_ON;
               VEMS_vidSET(IdlSys_bIniIdlCtl, 0);
            }
         }
         break;

      case WAIT_ON:
         if (  (IdlSys_bIniIdl != 0)
            || (IdlSys_bAuthIdlCtlStEng == 0)
            || (  (IdlSys_bAcvAntiStallAT == 0)
               && (IdlSys_bAcvIdlCtlDyn == 0)
               && (IdlSys_bDeacIdlCtlEngSpd != 0)
               && (IdlSys_bEngNOnIdl == 0)
               && (IdlSys_bAcvIdlCtlStrt == 0)))
         {
            IDLMGR_stRegSup = REGULATOR_OFF;
            VEMS_vidSET(IdlSys_bIniIdlCtl, 0);
            VEMS_vidSET(IdlSys_bAcvIdlCtl, 0);
         }
         else
         {
            if (  (IdlSys_bAcvAntiStallAT != 0)
               || (IdlSys_bIniIdlCtlCrawlChg != 0)
               || (IdlSys_bIniIdlCtlGearChg != 0)
               || (IdlSys_bIniIdlCtlModChg != 0)
               || (IdlSys_bIniIdlCtlDyn != 0)
               || (IdlSys_bAcvIdlCtlStrt != 0))
            {
               IDLMGR_stRegSup = INIT_ENTRY;
               VEMS_vidSET(IdlSys_bIniIdlCtl, 1);
            }
         }
         break;

      default :
         SWFAIL_vidSoftwareErrorHook();
         IDLMGR_stRegSup = REGULATOR_OFF;
         VEMS_vidSET(IdlSys_bIniIdlCtl, 0);
         VEMS_vidSET(IdlSys_bAcvIdlCtl, 0);
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_valeurs_replis                          */
/* !Description :  Dans ce bloc, on calcule les valeurs de repli à appliquer  */
/*                 lorsque les calculs de la fonction ralenti sont désactivés.*/
/* !Number      :  FCT5.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_039.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  output boolean IdlSys_bAcvIdlCtl;                                         */
/*  output boolean IdlSys_bAcvIgMinSpc;                                       */
/*  output boolean IdlSys_bAuthInjCutOff;                                     */
/*  output boolean IdlSys_bIniIdlCtl;                                         */
/*  output uint16 IdlSys_nTarIdlDyn;                                          */
/*  output sint16 IdlSys_tqIdcIdlIni;                                         */
/*  output sint16 IdlSys_tqIdcIdlIniAir;                                      */
/*  output sint16 IdlSys_tqIdcIdlStab;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_valeurs_replis(void)
{
   uint16 u16LocalTqSys_nTarIdl;


   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidSET(IdlSys_bAcvIdlCtl, 0);
   VEMS_vidSET(IdlSys_bAcvIgMinSpc, 0);
   VEMS_vidSET(IdlSys_bAuthInjCutOff, 1);
   VEMS_vidSET(IdlSys_bIniIdlCtl, 0);
   u16LocalTqSys_nTarIdl = (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdl, 32000);
   VEMS_vidSET(IdlSys_nTarIdlDyn, u16LocalTqSys_nTarIdl);
   VEMS_vidSET(IdlSys_tqIdcIdlIni, 0);
   VEMS_vidSET(IdlSys_tqIdcIdlIniAir, 0);
   VEMS_vidSET(IdlSys_tqIdcIdlStab, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidBoucler_stuct_couple                             */
/* !Description :  Ce bloc gère la transition de la structure couple du       */
/*                 débouclage vers le bouclage lors que le ralenti s’active.  */
/*                 On gère 2 informations par calibrations : - une pente de   */
/*                 transition - une durée maximale de transition              */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_040.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 IdlSys_tqIncCll_C;                                           */
/*  input uint16 IdlSys_tiTranCll_C;                                          */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  output uint16 IdlSys_tqIncCll;                                            */
/*  output uint16 IdlSys_tiTranCll;                                           */
/*  output boolean IdlSys_bAcvCll;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidBoucler_stuct_couple(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   uint16  u16LocalIdlSys_tqIncCll;
   uint16  u16LocalIdlSys_tiTranCll;


   u16LocalIdlSys_tqIncCll = (uint16)MATHSRV_udtMIN(IdlSys_tqIncCll_C, 32000);
   VEMS_vidSET(IdlSys_tqIncCll, u16LocalIdlSys_tqIncCll);
   u16LocalIdlSys_tiTranCll = (uint16)MATHSRV_udtMIN(IdlSys_tiTranCll_C, 500);
   VEMS_vidSET(IdlSys_tiTranCll, u16LocalIdlSys_tiTranCll);
   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   VEMS_vidSET(IdlSys_bAcvCll, bLocalIdlSys_bAcvIdlCtl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_pertes_convr_BVA                            */
/* !Description :  Permet de récupérer le couple prélevé par le convertisseur */
/*                 en BVA                                                     */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_041.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean IdlSys_bTqCnvLoss_C;                                        */
/*  input uint16 TqCmp_tqCnvLoss;                                             */
/*  output uint16 IdlSys_tqCnvLoss;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_pertes_convr_BVA(void)
{
   uint16 u16LocalTqCmp_tqCnvLoss;


   if (IdlSys_bTqCnvLoss_C != 0)
   {
      VEMS_vidGET(TqCmp_tqCnvLoss, u16LocalTqCmp_tqCnvLoss);
      IdlSys_tqCnvLoss = (uint16)MATHSRV_udtMIN(u16LocalTqCmp_tqCnvLoss, 8000);
   }
   else
   {
      IdlSys_tqCnvLoss = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDeterminer_demarrage                             */
/* !Description :  L’activation de la structure couple active le ralenti      */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bIniIdlReq;                                           */
/*  input boolean TqSys_bTqSysAcv;                                            */
/*  input boolean IdlSys_bAcvStrtTqSys;                                       */
/*  input boolean IdlSys_bEnaIdlCtlAcvStrt_C;                                 */
/*  input boolean IDLMGR_bIniIdlReqPrev;                                      */
/*  input boolean IdlSys_bTqSysAcvSel_C;                                      */
/*  input boolean IDLMGR_bAcvStrtTqSysPrev;                                   */
/*  input boolean IDLMGR_bTqSysAcvPrev;                                       */
/*  output boolean IdlSys_bAcvIdlCtlStrt;                                     */
/*  output boolean IDLMGR_bIniIdlReqPrev;                                     */
/*  output boolean IDLMGR_bTqSysAcvPrev;                                      */
/*  output boolean IDLMGR_bAcvStrtTqSysPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDeterminer_demarrage(void)
{
   boolean bLocalTqSys_bIniIdlReq;
   boolean bLocalTqSys_bTqSysAcv;
   boolean bLocalIdlSys_bAcvStrtTqSys;


   VEMS_vidGET(TqSys_bIniIdlReq, bLocalTqSys_bIniIdlReq);
   VEMS_vidGET(TqSys_bTqSysAcv, bLocalTqSys_bTqSysAcv);
   VEMS_vidGET(IdlSys_bAcvStrtTqSys, bLocalIdlSys_bAcvStrtTqSys);

   if (IdlSys_bEnaIdlCtlAcvStrt_C != 0)
   {
      if (  (bLocalTqSys_bIniIdlReq != 0)
         && (IDLMGR_bIniIdlReqPrev == 0))
      {
         IdlSys_bAcvIdlCtlStrt = 1;
      }
      else
      {
         if (IdlSys_bTqSysAcvSel_C != 0)
         {
            if (  (bLocalIdlSys_bAcvStrtTqSys != 0)
               && (IDLMGR_bAcvStrtTqSysPrev == 0))
            {
               IdlSys_bAcvIdlCtlStrt = 1;
            }
            else
            {
               IdlSys_bAcvIdlCtlStrt = 0;
            }
         }
         else
         {
            if (  (bLocalTqSys_bTqSysAcv != 0)
               && (IDLMGR_bTqSysAcvPrev == 0))
            {
               IdlSys_bAcvIdlCtlStrt = 1;
            }
            else
            {
               IdlSys_bAcvIdlCtlStrt = 0;
            }
         }
      }
   }
   else
   {
      IdlSys_bAcvIdlCtlStrt = 0;
   }
   IDLMGR_bIniIdlReqPrev = bLocalTqSys_bIniIdlReq;
   IDLMGR_bTqSysAcvPrev = bLocalTqSys_bTqSysAcv;
   IDLMGR_bAcvStrtTqSysPrev = bLocalIdlSys_bAcvStrtTqSys;

}
/*------------------------------- end of file --------------------------------*/