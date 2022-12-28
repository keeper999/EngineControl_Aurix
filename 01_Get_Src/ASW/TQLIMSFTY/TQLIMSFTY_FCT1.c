/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLIMSFTY                                               */
/* !Description     : TQLIMSFTY component.                                    */
/*                                                                            */
/* !Module          : TQLIMSFTY                                               */
/* !Description     : LIMITATION DE COUPLE POUR LA SECURITE DE FONCTIONNEMENT */
/*                                                                            */
/* !File            : TQLIMSFTY_FCT1.C                                        */
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
/*   1 / TQLIMSFTY_vidEcuReset                                                */
/*   2 / TQLIMSFTY_vidTorqueLimitSafety                                       */
/*   3 / TQLIMSFTY_vidStaticLimit                                             */
/*   4 / TQLIMSFTY_vidPreviousCalc                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 07804 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/TQLIMSFTY/TQLIMSFTY_FCT1.C_v      $*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   01 Dec 2010 $*/
/* $Author::   hmelloul                               $$Date::   01 Dec 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQLIMSFTY.h"
#include "TQLIMSFTY_L.h"
#include "TQLIMSFTY_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLIMSFTY_vidEcuReset                                      */
/* !Description :  Reset ECU                                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  M.FERSI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean EngLim_bAcvTqLim_prev;                                     */
/*  output boolean EngLim_bTqLimTran;                                         */
/*  output sint16 TQLIMSFTY_s16SlewRateOutput;                                */
/*  output sint16 EngLim_tqIdcRed;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLIMSFTY_vidEcuReset(void)
{
   EngLim_bAcvTqLim_prev = GDGAR_bGetFRM(FRM_FRM_ACVTQLIM);
   EngLim_bTqLimTran = 0;
   TQLIMSFTY_s16SlewRateOutput = 0;
   VEMS_vidSET(EngLim_tqIdcRed, 32000);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLIMSFTY_vidTorqueLimitSafety                             */
/* !Description :  Ce module permet à tout défaut du système d’engendrer une  */
/*                 limitation de couple sécuritaire. L’activation de la       */
/*                 limitation s’effectue d’une manière progressive et donc    */
/*                 sécuritaire. Pour cela, le sytème devra fournir la valeur  */
/*                 du couple courant.                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  M.FERSI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void TQLIMSFTY_vidStaticLimit();                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqEngCur_Sfty;                                        */
/*  input boolean EngLim_bAcvTqLim_prev;                                      */
/*  input sint16 EngLim_tqSftystat;                                           */
/*  input boolean EngLim_bRiseEdgeTqLim;                                      */
/*  input boolean EngLim_bTqLimTran;                                          */
/*  input sint16 EngLim_tqGrdSftyDec_C;                                       */
/*  input sint16 TQLIMSFTY_s16SlewRateOutput;                                 */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  output boolean EngLim_bRiseEdgeTqLim;                                     */
/*  output boolean EngLim_bTqLimTran;                                         */
/*  output sint16 TQLIMSFTY_s16SlewRateOutput;                                */
/*  output sint16 EngLim_tqIdcRed;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLIMSFTY_vidTorqueLimitSafety(void)
{
   boolean bLocalAcvTqLim;
   uint16  u16LocalSlewRateInput;
   uint16  u16LocalSlewRateOut;
   uint16  u16LocalEngLim_tqGrdSftyDec_C;
   sint16  s16LocalSlewRateInput;
   sint16  s16LocalEngLim_tqIdcRed;
   sint16  s16LocalEngLim_tqEngCur_Sfty;
   sint16  s16LocalEngLim_tqGrdSftyDec_C;
   sint16  s16LocalSlewRateOut;
   sint16  s16LocalTqCmp_tqSumLossCmp;
   sint32  s32LocalEngLim_tqIdcRed;


   VEMS_vidGET(EngLim_tqEngCur_Sfty, s16LocalEngLim_tqEngCur_Sfty);
   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   bLocalAcvTqLim = GDGAR_bGetFRM(FRM_FRM_ACVTQLIM);

   if (bLocalAcvTqLim != 0)
   {
      TQLIMSFTY_vidStaticLimit();
   }

   if (  (bLocalAcvTqLim != 0)
      && (EngLim_bAcvTqLim_prev == 0))
   {
      EngLim_bRiseEdgeTqLim = 1;
      s16LocalSlewRateInput = s16LocalEngLim_tqEngCur_Sfty;
   }
   else
   {
      EngLim_bRiseEdgeTqLim = 0;
      s16LocalSlewRateInput = EngLim_tqSftystat;
   }

   if ( (  (s16LocalEngLim_tqEngCur_Sfty > EngLim_tqSftystat)
        && (bLocalAcvTqLim != 0))
      && ( (EngLim_bRiseEdgeTqLim != 0)
         || (EngLim_bTqLimTran != 0)))
   {
      EngLim_bTqLimTran = 1;
   }
   else
   {
      EngLim_bTqLimTran = 0;
   }

   s16LocalEngLim_tqGrdSftyDec_C = (sint16)(MATHSRV_udtMIN
                                           (EngLim_tqGrdSftyDec_C,
                                            0));
   u16LocalEngLim_tqGrdSftyDec_C = (uint16)( (-1)
                                           * s16LocalEngLim_tqGrdSftyDec_C);
   u16LocalSlewRateInput = (uint16)(s16LocalSlewRateInput + 32768);

   u16LocalSlewRateOut = (uint16)(TQLIMSFTY_s16SlewRateOutput + 32768);

   u16LocalSlewRateOut = MATHSRV_u16SlewFilter(u16LocalSlewRateOut,
                                               u16LocalSlewRateInput,
                                               (uint16)32000,
                                               u16LocalEngLim_tqGrdSftyDec_C);

   s16LocalSlewRateOut = (sint16)(u16LocalSlewRateOut - 32768);

   TQLIMSFTY_s16SlewRateOutput =
      (sint16)MATHSRV_udtCLAMP(s16LocalSlewRateOut, -32000, 32000);

   if (bLocalAcvTqLim != 0)
   {
      if (EngLim_bTqLimTran != 0)
      {
         s16LocalEngLim_tqIdcRed = TQLIMSFTY_s16SlewRateOutput;
      }
      else
      {
         s16LocalEngLim_tqIdcRed = EngLim_tqSftystat;
      }
   }
   else
   {
      s16LocalEngLim_tqIdcRed = 32000;
   }

   s32LocalEngLim_tqIdcRed = (sint32)( s16LocalTqCmp_tqSumLossCmp
                                     + s16LocalEngLim_tqIdcRed);
   s16LocalEngLim_tqIdcRed = (sint16)MATHSRV_udtCLAMP(s32LocalEngLim_tqIdcRed,
                                                      -32000,
                                                      32000);
   VEMS_vidSET(EngLim_tqIdcRed, s16LocalEngLim_tqIdcRed);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLIMSFTY_vidStaticLimit                                   */
/* !Description :  Une information de rapport de boite spécifique aux besoins */
/*                 de la sureté de fonctionnement devra être mise à           */
/*                 disposition par les fonctions créatrices du rapport de     */
/*                 boite.                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  M.FERSI                                                    */
/* !Trace_To    :  VEMS_R_08_07804_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_noGearCord_Sfty;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 EngLim_tqIdcSyst_Gear_A[8];                                   */
/*  input uint16 EngLim_tqIdcSyst_nEng_A[10];                                 */
/*  input uint16 EngLim_tqIdcSyst_M[8][10];                                   */
/*  output sint16 EngLim_tqSftystat;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLIMSFTY_vidStaticLimit(void)
{
   uint8  u8LocalCoPt_noGearCord_Sfty;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalEngLim_tqSftystat;
   uint16 u16LocalExt_nEng;
   sint32 s32LocalEngLim_tqSftystat;


   VEMS_vidGET(CoPt_noGearCord_Sfty, u8LocalCoPt_noGearCord_Sfty);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(EngLim_tqIdcSyst_Gear_A,
                                                   u8LocalCoPt_noGearCord_Sfty,
                                                   8);

   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(EngLim_tqIdcSyst_nEng_A,
                                                    u16LocalExt_nEng,
                                                    10);

   u16LocalEngLim_tqSftystat = MATHSRV_u16Interp2d(&EngLim_tqIdcSyst_M[0][0],
                                                   u16LocalCalcParaX,
                                                   u16LocalCalcParaY,
                                                   10);

   s32LocalEngLim_tqSftystat = (sint32)(u16LocalEngLim_tqSftystat - 32000);

   EngLim_tqSftystat = (sint16)MATHSRV_udtMIN(s32LocalEngLim_tqSftystat, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLIMSFTY_vidPreviousCalc                                  */
/* !Description :  Calcul de la valeur precedente                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  M.FERSI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  output boolean EngLim_bAcvTqLim_prev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLIMSFTY_vidPreviousCalc(void)
{
   boolean bLocalAcvTqLim;


   bLocalAcvTqLim = GDGAR_bGetFRM(FRM_FRM_ACVTQLIM);
   EngLim_bAcvTqLim_prev = bLocalAcvTqLim;
}

/*---------------------------- end of file -----------------------------------*/