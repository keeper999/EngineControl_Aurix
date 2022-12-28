/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FCTDIAGTRBPRES                                          */
/* !Description     : FCTDIAGTRBPRES Component                                */
/*                                                                            */
/* !Module          : FCTDIAGTRBPRES                                          */
/* !Description     :  Diagnostic fonctionnel de la pression de               */
/*                    suralimentation                                         */
/*                                                                            */
/* !File            : FCTDIAGTRBPRES_FCT1.C                                   */
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
/*   1 / FCTDIAGTRBPRES_vidInitOutput                                         */
/*   2 / FCTDIAGTRBPRES_vidDiagTrbPrsinit                                     */
/*   3 / FCTDIAGTRBPRES_vidDiagTrbPres                                        */
/*   4 / FCTDIAGTRBPRES_vidCdEnaHiTrbPre                                      */
/*   5 / FCTDIAGTRBPRES_vidHiTrbPres                                          */
/*   6 / FCTDIAGTRBPRES_vidCdnEnaLoTrbPre                                     */
/*   7 / FCTDIAGTRBPRES_vidLoTrbPres                                          */
/*   8 / FCTDIAGTRBPRES_vidCdnCohTrbPrId                                      */
/*   9 / FCTDIAGTRBPRES_vidCohTrbPresIdl                                      */
/*   10 / FCTDIAGTRBPRES_vidEnaCohTrbPsBst                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5198884 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065845                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRPRES/FCTDIAGTRBPRES/FCTDIAGTR$*/
/* $Revision::   1.4      $$Author::   etsasson       $$Date::   16 May 2013 $*/
/* $Author::   etsasson                               $$Date::   16 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "FCTDIAGTRBPRES.h"
#include "FCTDIAGTRBPRES_L.h"
#include "FCTDIAGTRBPRES_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidInitOutput                               */
/* !Description :  Initialisation des outputs                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 AirPres_ctTiUsThrPlaus;                                      */
/*  output boolean FCTDIAGTRBPRES_bOutTimer1;                                 */
/*  output boolean FCtDIAGTRBPRES_bAcvIdlCtlPrev;                             */
/*  output boolean FCTDIAGTRBPRES_bBoostPresPrev;                             */
/*  output uint8 AirPres_ctTiBoostPresClCtlAcv;                               */
/*  output boolean FCTDIAGTRBPRES_bOutTimer2;                                 */
/*  output boolean FCTDIAGTRBPRES_btiDifpUsThrPrev;                           */
/*  output boolean FCTDIAGTRBPRES_btiDifpUsThr;                               */
/*  output boolean FCTDIAGTRBPRES_bOutTimer3;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidInitOutput(void)
{
   /* Timer1*/
   AirPres_ctTiUsThrPlaus        = 0;
   FCTDIAGTRBPRES_bOutTimer1     = 0;
   FCtDIAGTRBPRES_bAcvIdlCtlPrev = 0;
   /*Timer2*/
   FCTDIAGTRBPRES_bBoostPresPrev = 0;
   AirPres_ctTiBoostPresClCtlAcv = 0;
   FCTDIAGTRBPRES_bOutTimer2     = 0;
   /* Timer3*/
   FCTDIAGTRBPRES_btiDifpUsThrPrev = 0;
   FCTDIAGTRBPRES_btiDifpUsThr     = 0;
   FCTDIAGTRBPRES_bOutTimer3       = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidDiagTrbPrsinit                           */
/* !Description :  initialisation des variables internes.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean AirPres_bDgoPosDif1_pUsThr;                                */
/*  output boolean AirPres_bMonRunPosDif1_pUsThr;                             */
/*  output boolean AirPres_bDgoPosDif2_pUsThr;                                */
/*  output boolean AirPres_bMonRunPosDif2_pUsThr;                             */
/*  output boolean AirPres_bDgoNegDif1_pUsThr;                                */
/*  output boolean AirPres_bMonRunNegDif1_pUsThr;                             */
/*  output boolean AirPres_bDgoNegDif2_pUsThr;                                */
/*  output boolean AirPres_bMonRunNegDif2_pUsThr;                             */
/*  output boolean AirPres_bDgoPlaus_pUsThrIdl;                               */
/*  output boolean AirPres_bMonRunPlaus_pUsThrIdl;                            */
/*  output boolean AirPres_bDgoPlaus_pUsThrBoost;                             */
/*  output boolean AirPres_bMonRunPlaus_pUsThrBoost;                          */
/*  output boolean AirPres_bDgoNegDif_pUsThrSen;                              */
/*  output boolean AirPres_bMonRunNegDif_pUsThrSen;                           */
/*  output boolean AirPres_bDgoPosDif_pUsThrSen;                              */
/*  output boolean AirPres_bMonRunPosDif_pUsThrSen;                           */
/*  output boolean AirPres_bDgoMaxAbs_pUsThr;                                 */
/*  output boolean AirPres_bMonRunMaxAbs_pUsThr;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidDiagTrbPrsinit(void)
{
   AirPres_bDgoPosDif1_pUsThr       = 0;
   AirPres_bMonRunPosDif1_pUsThr    = 0;
   AirPres_bDgoPosDif2_pUsThr       = 0;
   AirPres_bMonRunPosDif2_pUsThr    = 0;
   AirPres_bDgoNegDif1_pUsThr       = 0;
   AirPres_bMonRunNegDif1_pUsThr    = 0;
   AirPres_bDgoNegDif2_pUsThr       = 0;
   AirPres_bMonRunNegDif2_pUsThr    = 0;
   AirPres_bDgoPlaus_pUsThrIdl      = 0;
   AirPres_bMonRunPlaus_pUsThrIdl   = 0;
   AirPres_bDgoPlaus_pUsThrBoost    = 0;
   AirPres_bMonRunPlaus_pUsThrBoost = 0;
   AirPres_bDgoNegDif_pUsThrSen     = 0;
   AirPres_bMonRunNegDif_pUsThrSen  = 0;
   AirPres_bDgoPosDif_pUsThrSen     = 0;
   AirPres_bMonRunPosDif_pUsThrSen  = 0;
   AirPres_bDgoMaxAbs_pUsThr        = 0;
   AirPres_bMonRunMaxAbs_pUsThr     = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidDiagTrbPres                              */
/* !Description :  Diagnostic fonctionnel de la pression de suralimentation   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FCTDIAGTRBPRES_vidCdEnaHiTrbPre();                       */
/*  extf argret void FCTDIAGTRBPRES_vidHiTrbPres();                           */
/*  extf argret void FCTDIAGTRBPRES_vidCdnEnaLoTrbPre();                      */
/*  extf argret void FCTDIAGTRBPRES_vidLoTrbPres();                           */
/*  extf argret void FCTDIAGTRBPRES_vidCdnCohTrbPrId();                       */
/*  extf argret void FCTDIAGTRBPRES_vidCohTrbPresIdl();                       */
/*  extf argret void FCTDIAGTRBPRES_vidEnaCohTrbPsBst();                      */
/*  extf argret void FCTDIAGTRBPRES_vidCohTrbPresBst();                       */
/*  extf argret void FCTDIAGTRBPRES_vidCdnNegTrbPres();                       */
/*  extf argret void FCTDIAGTRBPRES_vidNegTrbPres();                          */
/*  extf argret void FCTDIAGTRBPRES_vidCdnPosTrbPres();                       */
/*  extf argret void FCTDIAGTRBPRES_vidPosTrbPres();                          */
/*  input boolean AirPres_bMonRunPosDif1_pUsThr;                              */
/*  input boolean AirPres_bMonRunPosDif2_pUsThr;                              */
/*  input boolean AirPres_bMonRunNegDif1_pUsThr;                              */
/*  input boolean AirPres_bMonRunNegDif2_pUsThr;                              */
/*  input boolean AirPres_bMonRunPlaus_pUsThrIdl;                             */
/*  input boolean AirPres_bMonRunPlaus_pUsThrBoost;                           */
/*  input boolean AirPres_bMonRunNegDif_pUsThrSen;                            */
/*  input boolean AirPres_bMonRunPosDif_pUsThrSen;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidDiagTrbPres(void)
{
   /*F02_DiagTrbPres */
   FCTDIAGTRBPRES_vidCdEnaHiTrbPre();
   if(  (AirPres_bMonRunPosDif1_pUsThr != 0)
     && (AirPres_bMonRunPosDif2_pUsThr != 0))
   {
      FCTDIAGTRBPRES_vidHiTrbPres();
   }
   FCTDIAGTRBPRES_vidCdnEnaLoTrbPre();
   if(  (AirPres_bMonRunNegDif1_pUsThr != 0)
     && (AirPres_bMonRunNegDif2_pUsThr != 0))
   {
      FCTDIAGTRBPRES_vidLoTrbPres();
   }
   FCTDIAGTRBPRES_vidCdnCohTrbPrId();
   if(AirPres_bMonRunPlaus_pUsThrIdl != 0)
   {
      FCTDIAGTRBPRES_vidCohTrbPresIdl();
   }
   FCTDIAGTRBPRES_vidEnaCohTrbPsBst();
   if(AirPres_bMonRunPlaus_pUsThrBoost != 0)
   {
      FCTDIAGTRBPRES_vidCohTrbPresBst();
   }
   FCTDIAGTRBPRES_vidCdnNegTrbPres();
   if(AirPres_bMonRunNegDif_pUsThrSen != 0)
   {
      FCTDIAGTRBPRES_vidNegTrbPres();
   }
   FCTDIAGTRBPRES_vidCdnPosTrbPres();
   if(AirPres_bMonRunPosDif_pUsThrSen != 0)
   {
      FCTDIAGTRBPRES_vidPosTrbPres();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidCdEnaHiTrbPre                            */
/* !Description :  Conditions d’activation du diagnostic de détection d’une   */
/*                 pression de  suralimentation excessive de X mBar .         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  output boolean AirPres_bMonRunPosDif1_pUsThr;                             */
/*  output boolean AirPres_bMonRunPosDif2_pUsThr;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCdEnaHiTrbPre(void)
{
   /* F00_CdnEnaHiTrbPres*/
   boolean bLocalInhFctDiagHiTrbPres;


   bLocalInhFctDiagHiTrbPres = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGHITRBPRES);
   if (bLocalInhFctDiagHiTrbPres != 0)
   {
      AirPres_bMonRunPosDif1_pUsThr = 0;
      AirPres_bMonRunPosDif2_pUsThr = 0;
   }
   else
   {
      AirPres_bMonRunPosDif1_pUsThr = 1;
      AirPres_bMonRunPosDif2_pUsThr = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidHiTrbPres                                */
/* !Description :  Détection de la pression de suralimentation excessive.     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 AirSys_pUsThrReq;                                            */
/*  input uint16 AirPres_pUsThrPosDif;                                        */
/*  input uint16 AirPres_pUsThrPosDif1_C;                                     */
/*  input uint16 AirPres_pUsThrPosDif2_C;                                     */
/*  output uint16 AirPres_pUsThrPosDif;                                       */
/*  output boolean AirPres_bDgoPosDif1_pUsThr;                                */
/*  output boolean AirPres_bDgoPosDif2_pUsThr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidHiTrbPres(void)
{
   /* F01_HiTrbPres */
   uint16 u16LocalTrbActUsThrFil;
   uint16 u16LocalAirSysUsThrReq;
   sint32 s32Localdiff1;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbActUsThrFil);
   VEMS_vidGET(AirSys_pUsThrReq, u16LocalAirSysUsThrReq);
   s32Localdiff1 = (sint32)(u16LocalTrbActUsThrFil - u16LocalAirSysUsThrReq);
   AirPres_pUsThrPosDif = (uint16)MATHSRV_udtMAX(s32Localdiff1, 0);
   if(AirPres_pUsThrPosDif > AirPres_pUsThrPosDif1_C)
   {
      if(AirPres_pUsThrPosDif > AirPres_pUsThrPosDif2_C)
      {
         AirPres_bDgoPosDif1_pUsThr = 0;
         AirPres_bDgoPosDif2_pUsThr = 1;
      }
      else
      {
         AirPres_bDgoPosDif1_pUsThr = 1;
         AirPres_bDgoPosDif2_pUsThr = 0;
      }
   }
   else
   {
      AirPres_bDgoPosDif1_pUsThr = 0;
      AirPres_bDgoPosDif2_pUsThr = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidCdnEnaLoTrbPre                           */
/* !Description :  Conditions d’activation du diagnostic de détection d’une   */
/*                 pression de  suralimentation trop faible de X mBar .       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input uint8 Corrected_throttle_position;                                  */
/*  input uint16 Wg_pUsThrNat;                                                */
/*  input uint16 AirSys_pUsThrReq;                                            */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 AirPres_pAirExtMes_A[8];                                     */
/*  input uint16 AirPres_nEng_pAirExtMes_T[8];                                */
/*  input uint16 AirPres_nDifpUsThr_A[8];                                     */
/*  input uint8 AirPres_tiDifpUsThr_T[8];                                     */
/*  input sint16 AirPres_pUsThrNatOfs_C;                                      */
/*  input uint8 AirPres_rClsThdThr_C;                                         */
/*  input uint16 AirPres_pAirExtMes_C;                                        */
/*  input boolean FCTDIAGTRBPRES_btiDifpUsThrPrev;                            */
/*  input boolean FCTDIAGTRBPRES_btiDifpUsThr;                                */
/*  input uint8 FCTDIAGTRBPRES_u8tiDifpUsThr;                                 */
/*  input uint8 AirPres_tiDifpUsThr;                                          */
/*  input boolean FCTDIAGTRBPRES_bOutTimer3;                                  */
/*  output uint8 FCTDIAGTRBPRES_u8tiDifpUsThr;                                */
/*  output boolean FCTDIAGTRBPRES_btiDifpUsThr;                               */
/*  output uint8 AirPres_tiDifpUsThr;                                         */
/*  output boolean FCTDIAGTRBPRES_bOutTimer3;                                 */
/*  output boolean AirPres_bMonRunNegDif1_pUsThr;                             */
/*  output boolean AirPres_bMonRunNegDif2_pUsThr;                             */
/*  output boolean FCTDIAGTRBPRES_btiDifpUsThrPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCdnEnaLoTrbPre(void)
{
   /* F02_CdnEnaLoTrbPres */
   boolean bLocalInhFctDiagLoTrbPres;
   boolean bLocalBoostPresClCtlAcv;
   uint8   u8LocalCorrthropos;
   uint8   u8LocaltiDifpUsThr;
   uint16  u16LocalInterp;
   uint16  u16LocalCalcParam;
   uint16  u16LocalWgpUsThrNat;
   uint16  u16LocalExtnEng;
   uint16  u16LocalUsThrReq;
   uint16  u16LocalExtpAirExtMes;
   uint16  u16LocalCalcPara_tmr;
   sint32  s32LocalVar;


   bLocalInhFctDiagLoTrbPres = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGLOTRBPRES);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalBoostPresClCtlAcv);
   VEMS_vidGET(Corrected_throttle_position, u8LocalCorrthropos);
   VEMS_vidGET(Wg_pUsThrNat, u16LocalWgpUsThrNat);
   VEMS_vidGET(AirSys_pUsThrReq, u16LocalUsThrReq);
   VEMS_vidGET(Ext_nEng, u16LocalExtnEng);
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExtpAirExtMes);

   u16LocalCalcParam = MATHSRV_u16CalcParaIncAryU16(AirPres_pAirExtMes_A,
                                                    u16LocalExtpAirExtMes,
                                                    8);
   u16LocalInterp = MATHSRV_u16Interp1d(AirPres_nEng_pAirExtMes_T,
                                        u16LocalCalcParam);

   u16LocalCalcPara_tmr = MATHSRV_u16CalcParaIncAryU16(AirPres_nDifpUsThr_A,
                                                       u16LocalExtnEng,
                                                       8);
   FCTDIAGTRBPRES_u8tiDifpUsThr = MATHSRV_u8Interp1d(AirPres_tiDifpUsThr_T,
                                                     u16LocalCalcPara_tmr);

   s32LocalVar = (sint32)(AirPres_pUsThrNatOfs_C + u16LocalWgpUsThrNat);

   if(  (bLocalInhFctDiagLoTrbPres == 0)
     && (bLocalBoostPresClCtlAcv != 0)
     && (u8LocalCorrthropos > AirPres_rClsThdThr_C)
     && (u16LocalUsThrReq > s32LocalVar)
     && (u16LocalExtnEng > u16LocalInterp)
     && (u16LocalExtpAirExtMes > AirPres_pAirExtMes_C))
   {
      FCTDIAGTRBPRES_btiDifpUsThr = 1;
   }
   else
   {
      FCTDIAGTRBPRES_btiDifpUsThr = 0;
   }
   if (  (FCTDIAGTRBPRES_btiDifpUsThrPrev == 0)
      && (FCTDIAGTRBPRES_btiDifpUsThr != 0))
   {
      AirPres_tiDifpUsThr =
         (uint8)MATHSRV_udtMIN(FCTDIAGTRBPRES_u8tiDifpUsThr, 62);
      if (AirPres_tiDifpUsThr == 0)
      {
         FCTDIAGTRBPRES_bOutTimer3 = 1;
      }
      else
      {
         FCTDIAGTRBPRES_bOutTimer3 = 0;
      }
   }
   else
   {
      if (AirPres_tiDifpUsThr > 0)
      {
         u8LocaltiDifpUsThr = (uint8)(AirPres_tiDifpUsThr - 1);
         AirPres_tiDifpUsThr = (uint8)MATHSRV_udtMIN(u8LocaltiDifpUsThr, 62);

         if (AirPres_tiDifpUsThr == 0)
         {
            FCTDIAGTRBPRES_bOutTimer3 = 1;
         }
         else
         {
            FCTDIAGTRBPRES_bOutTimer3 = 0;
         }
      }
   }
   if (  (FCTDIAGTRBPRES_btiDifpUsThr != 0)
      && (FCTDIAGTRBPRES_bOutTimer3 != 0))
   {
      AirPres_bMonRunNegDif1_pUsThr = 1;
      AirPres_bMonRunNegDif2_pUsThr = 1;
   }
   else
   {
      AirPres_bMonRunNegDif1_pUsThr = 0;
      AirPres_bMonRunNegDif2_pUsThr = 0;
   }
   FCTDIAGTRBPRES_btiDifpUsThrPrev = FCTDIAGTRBPRES_btiDifpUsThr;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidLoTrbPres                                */
/* !Description :  Détection de la pression de suralimentation trop faible.   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_007.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 AirSys_pUsThrReq;                                            */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input sint8 VlvAct_agCkOpInVlvReqRef0Max;                                 */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input sint8 VlvAct_agCkClsExVlvReqRef0Min;                                */
/*  input uint16 AirPres_agAbsDeltaVlvInToMax;                                */
/*  input uint16 AirPres_agDeltaVlvPosnThd_C;                                 */
/*  input uint16 AirPres_agAbsDeltaVlvExToMin;                                */
/*  input uint16 AirPres_pUsThrNegDifVlvPosn2_C;                              */
/*  input uint16 AirPres_pUsThrNegDifVlvPosn1_C;                              */
/*  input uint16 AirPres_pUsThrNegDif2_C;                                     */
/*  input uint16 AirPres_pUsThrNegDif1_C;                                     */
/*  input uint16 AirPres_pUsThrNegDif;                                        */
/*  output uint16 AirPres_pUsThrNegDif;                                       */
/*  output uint16 AirPres_agAbsDeltaVlvInToMax;                               */
/*  output uint16 AirPres_agAbsDeltaVlvExToMin;                               */
/*  output boolean AirPres_bAcvNegDifFctVlvPosn;                              */
/*  output boolean AirPres_bDgoNegDif1_pUsThr;                                */
/*  output boolean AirPres_bDgoNegDif2_pUsThr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidLoTrbPres(void)
{
   /* F03_LoTrbPres  */
   sint8  s8LocalVlvAct_agCkClsExVlvRqRfMn;
   sint8  s8LocalVlvAct_agCkOpInVlvRqRfMx;
   sint16 s16LocalExt_agCkOpInVlvEstimRef;
   sint16 s16LocalExt_agCkClsExVlvEstmRef;
   sint16 s16LocalMul;
   uint16 u16LocalTrbActUsThrFil;
   uint16 u16LocalAirSysUsThrReq;
   uint16 u16Localswitch2;
   uint16 u16Localswitch3;
   uint16 u16Localdiff;
   sint32 s32Localdiff;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbActUsThrFil);
   VEMS_vidGET(AirSys_pUsThrReq, u16LocalAirSysUsThrReq);
   s32Localdiff = (sint32)(u16LocalAirSysUsThrReq - u16LocalTrbActUsThrFil);
   AirPres_pUsThrNegDif = (uint16)MATHSRV_udtMAX(s32Localdiff, 0);

   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalExt_agCkOpInVlvEstimRef);
   VEMS_vidGET(VlvAct_agCkOpInVlvReqRef0Max,
               s8LocalVlvAct_agCkOpInVlvRqRfMx);
   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstmRef);
   VEMS_vidGET(VlvAct_agCkClsExVlvReqRef0Min,
               s8LocalVlvAct_agCkClsExVlvRqRfMn);

   s16LocalMul = (sint16)(s8LocalVlvAct_agCkOpInVlvRqRfMx * 8);
   s32Localdiff = (sint32)( s16LocalExt_agCkOpInVlvEstimRef - s16LocalMul);
   u16Localdiff = (uint16)MATHSRV_udtABS(s32Localdiff);
   AirPres_agAbsDeltaVlvInToMax = (uint16)MATHSRV_udtMIN(u16Localdiff, 1023);

   s16LocalMul = (sint16)(s8LocalVlvAct_agCkClsExVlvRqRfMn * 8);
   s32Localdiff = (sint32)( s16LocalExt_agCkClsExVlvEstmRef - s16LocalMul);
   u16Localdiff = (uint16)MATHSRV_udtABS(s32Localdiff);
   AirPres_agAbsDeltaVlvExToMin = (uint16)MATHSRV_udtMIN(u16Localdiff, 1023);

   if (  (AirPres_agAbsDeltaVlvInToMax <= AirPres_agDeltaVlvPosnThd_C)
      || (AirPres_agAbsDeltaVlvExToMin <= AirPres_agDeltaVlvPosnThd_C))
   {
      AirPres_bAcvNegDifFctVlvPosn = 1;
      u16Localswitch2 = AirPres_pUsThrNegDifVlvPosn2_C;
      u16Localswitch3 = AirPres_pUsThrNegDifVlvPosn1_C;
   }
   else
   {
      AirPres_bAcvNegDifFctVlvPosn = 0;
      u16Localswitch2 = AirPres_pUsThrNegDif2_C;
      u16Localswitch3 = AirPres_pUsThrNegDif1_C;
   }

   if (AirPres_pUsThrNegDif > u16Localswitch3)
   {
      if (AirPres_pUsThrNegDif > u16Localswitch2)
      {
         AirPres_bDgoNegDif1_pUsThr = 0;
         AirPres_bDgoNegDif2_pUsThr = 1;
      }
      else
      {
         AirPres_bDgoNegDif1_pUsThr = 1;
         AirPres_bDgoNegDif2_pUsThr = 0;
      }
   }
   else
   {
      AirPres_bDgoNegDif1_pUsThr = 0;
      AirPres_bDgoNegDif2_pUsThr = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidCdnCohTrbPrId                            */
/* !Description :  Conditions d’activation du diagnostic de pression de       */
/*                 suralimentation  incohérente au ralenti.                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean FCtDIAGTRBPRES_bAcvIdlCtlPrev;                              */
/*  input uint8 AirPres_tiUsThrPlaus_AcvIdlCtl_C;                             */
/*  input uint8 AirPres_ctTiUsThrPlaus;                                       */
/*  input boolean FCTDIAGTRBPRES_bOutTimer1;                                  */
/*  output uint8 AirPres_ctTiUsThrPlaus;                                      */
/*  output boolean FCTDIAGTRBPRES_bOutTimer1;                                 */
/*  output boolean AirPres_bMonRunPlaus_pUsThrIdl;                            */
/*  output boolean FCtDIAGTRBPRES_bAcvIdlCtlPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCdnCohTrbPrId(void)
{
   /*F04_CdnEnaCohTrbPresIdl */
   boolean bLocalInhFctDiagCohTrbPresIdl;
   boolean bLocalIdlAcvIdlCtl;
   uint8   u8LocalTiUsThrPlaus;


   bLocalInhFctDiagCohTrbPresIdl =
      GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGCOHTRBPRESIDL);
   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlAcvIdlCtl);

   /* Timer1*/
   if(  (FCtDIAGTRBPRES_bAcvIdlCtlPrev == 0)
     && (bLocalIdlAcvIdlCtl != 0))
   {
      AirPres_ctTiUsThrPlaus =
         (uint8)MATHSRV_udtMIN(AirPres_tiUsThrPlaus_AcvIdlCtl_C, 62);
      if (AirPres_ctTiUsThrPlaus == 0)
      {
         FCTDIAGTRBPRES_bOutTimer1 = 1;
      }
      else
      {
         FCTDIAGTRBPRES_bOutTimer1 = 0;
      }
   }
   else
   {
      if (AirPres_ctTiUsThrPlaus > 0)
      {
         u8LocalTiUsThrPlaus = (uint8)(AirPres_ctTiUsThrPlaus - 1);
         AirPres_ctTiUsThrPlaus =
            (uint8)MATHSRV_udtMIN(u8LocalTiUsThrPlaus, 62);
         if (AirPres_ctTiUsThrPlaus == 0)
         {
            FCTDIAGTRBPRES_bOutTimer1 = 1;
         }
         else
         {
            FCTDIAGTRBPRES_bOutTimer1 = 0;
         }
      }
   }

   if (  (bLocalInhFctDiagCohTrbPresIdl == 0)
      && (FCTDIAGTRBPRES_bOutTimer1 != 0)
      && (bLocalIdlAcvIdlCtl != 0))
   {
      AirPres_bMonRunPlaus_pUsThrIdl = 1;
   }
   else
   {
      AirPres_bMonRunPlaus_pUsThrIdl = 0;
   }
   FCtDIAGTRBPRES_bAcvIdlCtlPrev = bLocalIdlAcvIdlCtl;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidCohTrbPresIdl                            */
/* !Description :  Détection de la pression de suralimentation incohérente au */
/*                 ralenti .                                                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input uint16 AirPres_pAirExtMes1_C;                                       */
/*  input uint16 AirPres_pUsThrIdlPlaus_C;                                    */
/*  output boolean AirPres_bDgoPlaus_pUsThrIdl;                               */
/*  output uint16 AirPres_pAirExtMes1;                                        */
/*  output uint16 AirPres_pUsThrPlaus1;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCohTrbPresIdl(void)
{
   /*F05_CohTrbPresIdl */
   boolean bLocalPresPAirExtSens;
   uint16  u16LocalAirExtMes;
   uint16  u16LocalTrbActUsThrFil;
   uint32  u32LocalSwitch1;
   sint32  s32LocalDiff;


   VEMS_vidGET(Ext_pAirExtMes, u16LocalAirExtMes);
   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbActUsThrFil);
   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalPresPAirExtSens);
   if (bLocalPresPAirExtSens != 0)
   {
      u32LocalSwitch1= (u16LocalAirExtMes * 25) / 2;
   }
   else
   {
      u32LocalSwitch1 = AirPres_pAirExtMes1_C;
   }
   s32LocalDiff = (sint32)((uint32)u16LocalTrbActUsThrFil - u32LocalSwitch1);
   if(s32LocalDiff > AirPres_pUsThrIdlPlaus_C)
   {
      AirPres_bDgoPlaus_pUsThrIdl = 1;
   }
   else
   {
      AirPres_bDgoPlaus_pUsThrIdl = 0;
   }
   AirPres_pAirExtMes1 = (uint16)MATHSRV_udtMIN(u32LocalSwitch1, 65535);
   AirPres_pUsThrPlaus1 = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidEnaCohTrbPsBst                           */
/* !Description :  Conditions d’activation du diagnostic de pression de       */
/*                 suralimentation  incohérente en zone sural.                */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input boolean FCTDIAGTRBPRES_bBoostPresPrev;                              */
/*  input uint8 AirPres_tiBoostPresClCtlAcv_C;                                */
/*  input uint8 AirPres_ctTiBoostPresClCtlAcv;                                */
/*  input boolean FCTDIAGTRBPRES_bOutTimer2;                                  */
/*  output uint8 AirPres_ctTiBoostPresClCtlAcv;                               */
/*  output boolean FCTDIAGTRBPRES_bOutTimer2;                                 */
/*  output boolean AirPres_bMonRunPlaus_pUsThrBoost;                          */
/*  output boolean FCTDIAGTRBPRES_bBoostPresPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidEnaCohTrbPsBst(void)
{
   /*F06_CdnEnaCohTrbPresBoost */
   boolean bLocalInhFctDiagCohTrbPresBoost;
   boolean bLocalBoostPresClCtlAcv;
   uint8   u8LocalTiBoostPresClCtlAcv;


   bLocalInhFctDiagCohTrbPresBoost =
      GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGCOHTRBPRESBOOST);
   VEMS_vidGET(TrbAct_bBoostPresClCtlAcv, bLocalBoostPresClCtlAcv);

   /* Timer2*/
   if (  (FCTDIAGTRBPRES_bBoostPresPrev == 0)
      && (bLocalBoostPresClCtlAcv != 0))
   {
      AirPres_ctTiBoostPresClCtlAcv =
         (uint8)MATHSRV_udtMIN(AirPres_tiBoostPresClCtlAcv_C, 62);
      if (AirPres_ctTiBoostPresClCtlAcv == 0)
      {
         FCTDIAGTRBPRES_bOutTimer2 = 1;
      }
      else
      {
         FCTDIAGTRBPRES_bOutTimer2 = 0;
      }
   }
   else
   {
      if (AirPres_ctTiBoostPresClCtlAcv > 0)
      {
         u8LocalTiBoostPresClCtlAcv =
            (uint8)(AirPres_ctTiBoostPresClCtlAcv - 1);
         AirPres_ctTiBoostPresClCtlAcv =
            (uint8)MATHSRV_udtMIN(u8LocalTiBoostPresClCtlAcv, 62);
         if (AirPres_ctTiBoostPresClCtlAcv == 0)
         {
            FCTDIAGTRBPRES_bOutTimer2 = 1;
         }
         else
         {
            FCTDIAGTRBPRES_bOutTimer2 = 0;
         }
      }
   }

   if (  (bLocalInhFctDiagCohTrbPresBoost == 0)
      && (FCTDIAGTRBPRES_bOutTimer2 != 0)
      && (bLocalBoostPresClCtlAcv != 0))
   {
      AirPres_bMonRunPlaus_pUsThrBoost = 1;
   }
   else
   {
      AirPres_bMonRunPlaus_pUsThrBoost = 0;
   }
   FCTDIAGTRBPRES_bBoostPresPrev = bLocalBoostPresClCtlAcv;
}

/*------------------------------- end of file --------------------------------*/