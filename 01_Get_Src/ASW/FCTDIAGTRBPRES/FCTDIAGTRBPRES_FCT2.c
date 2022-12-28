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
/* !File            : FCTDIAGTRBPRES_FCT2.C                                   */
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
/*   1 / FCTDIAGTRBPRES_vidCohTrbPresBst                                      */
/*   2 / FCTDIAGTRBPRES_vidCdnNegTrbPres                                      */
/*   3 / FCTDIAGTRBPRES_vidNegTrbPres                                         */
/*   4 / FCTDIAGTRBPRES_vidCdnPosTrbPres                                      */
/*   5 / FCTDIAGTRBPRES_vidPosTrbPres                                         */
/*   6 / FCTDIAGTRBPRES_vidDiagCntTrbPres                                     */
/*   7 / FCTDIAGTRBPRES_vidDgCntTrbSenAcv                                     */
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
/* !Function    :  FCTDIAGTRBPRES_vidCohTrbPresBst                            */
/* !Description :  Détection de la pression de suralimentation incohérente en */
/*                 zone sural.                                                */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input uint16 AirPres_pAirExtMes2_C;                                       */
/*  input uint16 AirPres_pUsThrBoostPlaus_C;                                  */
/*  output boolean AirPres_bDgoPlaus_pUsThrBoost;                             */
/*  output uint16 AirPres_pAirExtMes2;                                        */
/*  output uint16 AirPres_pUsThrPlaus2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCohTrbPresBst(void)
{
   /*F07_CohTrbPresBoost */
   boolean bLocalPresPAirExtSens;
   uint16  u16LocalAirExtMes;
   uint16  u16LocalTrbActUsThrFil;
   uint16  u16LocalDiff;
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
      u32LocalSwitch1 = AirPres_pAirExtMes2_C;
   }
   s32LocalDiff = (sint32)((uint32)u16LocalTrbActUsThrFil - u32LocalSwitch1);
   u16LocalDiff =( uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
   if(u16LocalDiff < AirPres_pUsThrBoostPlaus_C)
   {
      AirPres_bDgoPlaus_pUsThrBoost = 1;
   }
   else
   {
      AirPres_bDgoPlaus_pUsThrBoost = 0;
   }
   AirPres_pAirExtMes2 = (uint16)MATHSRV_udtMIN(u32LocalSwitch1, 65535);
   AirPres_pUsThrPlaus2 = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidCdnNegTrbPres                            */
/* !Description :  Conditions d’activation du diagnostic dérive positive du   */
/*                 capteur de pression de  suralimentation.                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  output boolean AirPres_bMonRunNegDif_pUsThrSen;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCdnNegTrbPres(void)
{
   /*F08_CdnEnaNegTrbPres */
   boolean bLocalInhFctDiagNegTrbPres;

   bLocalInhFctDiagNegTrbPres  = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGNEGTRBPRES);
   if (bLocalInhFctDiagNegTrbPres != 0)
   {
      AirPres_bMonRunNegDif_pUsThrSen = 0;
   }
   else
   {
      AirPres_bMonRunNegDif_pUsThrSen = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidNegTrbPres                               */
/* !Description :  Détection d'une dérive positive du capteur de pression de  */
/*                 suralimentation .                                          */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 AirSys_pUsThrReq;                                            */
/*  input uint16 AirPres_pUsThrNegDifSen;                                     */
/*  input uint16 AirPres_pUsThrNegDifSen_C;                                   */
/*  output uint16 AirPres_pUsThrNegDifSen;                                    */
/*  output boolean AirPres_bDgoNegDif_pUsThrSen;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidNegTrbPres(void)
{
   /*F09_NegTrbPres */
   uint16 u16LocalTrbActUsThrFil;
   uint16 u16LocalAirSysUsThrReq;
   sint32 s32Localdiff1;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbActUsThrFil);
   VEMS_vidGET(AirSys_pUsThrReq, u16LocalAirSysUsThrReq);
   s32Localdiff1 = (sint32)(u16LocalAirSysUsThrReq - u16LocalTrbActUsThrFil);
   AirPres_pUsThrNegDifSen = (uint16)MATHSRV_udtMAX(s32Localdiff1, 0);
   if (AirPres_pUsThrNegDifSen > AirPres_pUsThrNegDifSen_C)
   {
      AirPres_bDgoNegDif_pUsThrSen = 1;
   }
   else
   {
      AirPres_bDgoNegDif_pUsThrSen = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidCdnPosTrbPres                            */
/* !Description :  Conditions d’activation du diagnostic dérive négative du   */
/*                 capteur de pression  de suralimentation                    */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  output boolean AirPres_bMonRunPosDif_pUsThrSen;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidCdnPosTrbPres(void)
{
   /* F10_CdnEnaPosTrbPres */
   boolean bLocalFctDiagPosTrbPres;


   bLocalFctDiagPosTrbPres = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGPOSTRBPRES);
   if (bLocalFctDiagPosTrbPres != 0)
   {
      AirPres_bMonRunPosDif_pUsThrSen = 0;
   }
   else
   {
      AirPres_bMonRunPosDif_pUsThrSen = 1;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidPosTrbPres                               */
/* !Description :  Détection d'une dérive négative du capteur de pression de  */
/*                 suralimentation                                            */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbAct_pUsThrFil;                                            */
/*  input uint16 AirSys_pUsThrReq;                                            */
/*  input uint16 AirPres_pUsThrPosDifSen;                                     */
/*  input uint16 AirPres_pUsThrPosDifSen_C;                                   */
/*  output uint16 AirPres_pUsThrPosDifSen;                                    */
/*  output boolean AirPres_bDgoPosDif_pUsThrSen;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidPosTrbPres(void)
{
   /*F11_PosTrbPres */
   uint16 u16LocalTrbActUsThrFil;
   uint16 u16LocalAirSysUsThrReq;
   sint32 s32Localdiff1;


   VEMS_vidGET(TrbAct_pUsThrFil, u16LocalTrbActUsThrFil);
   VEMS_vidGET(AirSys_pUsThrReq, u16LocalAirSysUsThrReq);
   s32Localdiff1 = (sint32)(u16LocalTrbActUsThrFil - u16LocalAirSysUsThrReq);
   AirPres_pUsThrPosDifSen = (uint16)MATHSRV_udtMAX(s32Localdiff1, 0);
   if (AirPres_pUsThrPosDifSen > AirPres_pUsThrPosDifSen_C)
   {
      AirPres_bDgoPosDif_pUsThrSen = 1;
   }
   else
   {
      AirPres_bDgoPosDif_pUsThrSen = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidDiagCntTrbPres                           */
/* !Description :  Détection de la pression de suralimentation maxi           */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  KJED                                                       */
/* !Trace_To    :  VEMS_E_11_03491_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void FCTDIAGTRBPRES_vidDgCntTrbSenAcv();                      */
/*  output boolean AirPres_bMonRunMaxAbs_pUsThr;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidDiagCntTrbPres(void)
{
   /*F03_DiagContTrbPres*/
   boolean bLocalInhFctDiagMaxTrbPres;


   bLocalInhFctDiagMaxTrbPres = GDGAR_bGetFRM(FRM_FRM_INHFCTDIAGMAXTRBPRES);
   if (bLocalInhFctDiagMaxTrbPres == 0)
   {
      AirPres_bMonRunMaxAbs_pUsThr = 1;
      FCTDIAGTRBPRES_vidDgCntTrbSenAcv();
   }
   else
   {
      AirPres_bMonRunMaxAbs_pUsThr = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FCTDIAGTRBPRES_vidDgCntTrbSenAcv                           */
/* !Description :  Cette fonction permet de déterminer le défaut pression     */
/*                 sural maxi                                                 */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  KJED                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAirExtMesSI;                                            */
/*  input uint16 Ext_pAirExtMesSI_A[8];                                       */
/*  input uint16 AirPres_pUsThrMaxDiag_T[8];                                  */
/*  input uint16 Acq_spg_pres_measured;                                       */
/*  input uint16 AirPres_pUsThrMaxDiag;                                       */
/*  output uint16 AirPres_pUsThrMaxDiag;                                      */
/*  output boolean AirPres_bDgoMaxAbs_pUsThr;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FCTDIAGTRBPRES_vidDgCntTrbSenAcv(void)
{
   /*/F01_DiagContTrbSenAcv */
   uint16 u16LocalExt_pAirExtMesSI;
   uint16 u16LocalAcq_spg_pres_measured;
   uint16 u16LocalCalcPara;


   VEMS_vidGET(Ext_pAirExtMesSI, u16LocalExt_pAirExtMesSI);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(Ext_pAirExtMesSI_A,
                                                   u16LocalExt_pAirExtMesSI,
                                                   8);
   AirPres_pUsThrMaxDiag = MATHSRV_u16Interp1d(AirPres_pUsThrMaxDiag_T,
                                               u16LocalCalcPara);

   VEMS_vidGET(Acq_spg_pres_measured, u16LocalAcq_spg_pres_measured);
   if (u16LocalAcq_spg_pres_measured > AirPres_pUsThrMaxDiag)
   {
      AirPres_bDgoMaxAbs_pUsThr = 1;
   }
   else
   {
      AirPres_bDgoMaxAbs_pUsThr = 0;
   }
}
/*------------------------------- end of file --------------------------------*/