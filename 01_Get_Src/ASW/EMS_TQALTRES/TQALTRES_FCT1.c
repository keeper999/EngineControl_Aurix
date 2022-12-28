/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQALTRES                                                */
/* !Description     : TQALTRES component                                      */
/*                                                                            */
/* !Module          : TQALTRES                                                */
/* !Description     : RÉSERVE DE COUPLE ALTERNATEUR                           */
/*                                                                            */
/* !File            : TQALTRES_FCT1.C                                         */
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
/*   1 / TQALTRES_vidInitOutput                                               */
/*   2 / TQALTRES_vidReserveCoupleALT                                         */
/*   3 / TQALTRES_vidConditionReserveALT                                      */
/*   4 / TQALTRES_vidCalculReserveALT                                         */
/*   5 / TQALTRES_vidCalculReserveAltICCP                                     */
/*   6 / TQALTRES_vidCalculReserveAltGap                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 02660 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0177 / 2.2                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQALTRES/TQALTRES$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQALTRES.h"
#include "TQALTRES_L.h"
#include "TQALTRES_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation de la variable de sortie.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint8 Ext_rAltCycOp;                                                */
/*  input uint8 TqRes_rAltFil_MP;                                             */
/*  input uint8 Ext_iAltExct;                                                 */
/*  input uint8 TqRes_iAltFil_MP;                                             */
/*  output uint16 TqRes_tqAltRes;                                             */
/*  output uint16 TQALTRES_u16tiAltCpt;                                       */
/*  output boolean TqRes_bCdnAltRes;                                          */
/*  output uint16 TqRes_tqAltResSat_MP;                                       */
/*  output boolean TQALTRES_bCdnAltRes_prev;                                  */
/*  output uint8 TqRes_rAltFil_MP;                                            */
/*  output uint32 TQALTRES_u32FiltredCoefFilCCPMem;                           */
/*  output uint8 TqRes_iAltFil_MP;                                            */
/*  output uint32 TQALTRES_u32FiltredCoefFilGapMem;                           */
/*  output boolean TqRes_bCdnNEngAltRes_MP;                                   */
/*  output uint16 TqRes_tqAltResGap;                                          */
/*  output uint16 TqRes_tqAltResStd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidInitOutput(void)
{
   uint8  u8LocalExt_rAltCycOp;
   uint8  u8LocalExt_iAltExct;
   uint16 u16LocalTqRes_tqIdlRes;


   VEMS_vidSET(TqRes_tqAltRes, 0);
   TQALTRES_u16tiAltCpt = 0;
   TqRes_bCdnAltRes = 0;
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   TqRes_tqAltResSat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes, 1600);
   TQALTRES_bCdnAltRes_prev = 0;
   VEMS_vidGET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
   TqRes_rAltFil_MP = (uint8)MATHSRV_udtMIN(u8LocalExt_rAltCycOp, 100);
   TQALTRES_u32FiltredCoefFilCCPMem = (uint32)(TqRes_rAltFil_MP * 256);
   VEMS_vidGET(Ext_iAltExct, u8LocalExt_iAltExct);
   TqRes_iAltFil_MP = (uint8)MATHSRV_udtMIN(u8LocalExt_iAltExct, 254);
   TQALTRES_u32FiltredCoefFilGapMem = (uint32)(TqRes_iAltFil_MP * 256);
   TqRes_bCdnNEngAltRes_MP = 0;
   TqRes_tqAltResGap = 0;
   TqRes_tqAltResStd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidReserveCoupleALT                               */
/* !Description :  fonction réserve de couple alternateur                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQALTRES_vidConditionReserveALT();                       */
/*  extf argret void TQALTRES_vidCalculReserveALT();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidReserveCoupleALT(void)
{
   TQALTRES_vidConditionReserveALT();
   TQALTRES_vidCalculReserveALT();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidConditionReserveALT                            */
/* !Description :  La condition de l’alternateur dépend du régime moteur et de*/
/*                 la condition au ralenti, elle s’active si le régime est    */
/*                 supérieur à un seuil minimum calibrable et inférieur à un  */
/*                 seuil maximum calibrable et la condition au ralenti est    */
/*                 active.                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input uint16 TqRes_nEngThrHiAltRes_C;                                     */
/*  input uint16 TqRes_nEngOfsLoAltRes_C;                                     */
/*  input boolean TqRes_bCdnNEngAltRes_MP;                                    */
/*  input uint16 TQALTRES_u16tiAltCpt;                                        */
/*  input uint8 TqRes_tiCdnNEngAltRes_C;                                      */
/*  output boolean TqRes_bCdnNEngAltRes_MP;                                   */
/*  output boolean TqRes_bCdnAltRes;                                          */
/*  output uint16 TQALTRES_u16tiAltCpt;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidConditionReserveALT(void)
{
   boolean bLocalTqSys_bEngNOnIdl;
   boolean bLocalTqRes_bCdnNEngAltRes_MP;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalTqSys_nTarIdl;
   uint16  u16LocalTqRes_tiCdnNEngAltRes;
   uint16  u16LocalTQALTRES_u16tiAltCpt;
   uint32  u32LocalTqSysThrSup;
   uint32  u32LocalTqResnHiAlt;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);

   u32LocalTqResnHiAlt = (uint32)(4 * TqRes_nEngThrHiAltRes_C);
   u32LocalTqSysThrSup = (uint32)( u16LocalTqSys_nTarIdl
                                 + (4 * TqRes_nEngOfsLoAltRes_C));

   bLocalTqRes_bCdnNEngAltRes_MP = TqRes_bCdnNEngAltRes_MP;

   if (  (u16LocalEng_nCkFil < u32LocalTqResnHiAlt)
      && (u16LocalEng_nCkFil > u32LocalTqSysThrSup)
      && (bLocalTqSys_bEngNOnIdl != 0))
   {
      TqRes_bCdnNEngAltRes_MP = 1;
   }
   else
   {
      TqRes_bCdnNEngAltRes_MP = 0;
   }

   if (TqRes_bCdnNEngAltRes_MP != 0)
   {
      TqRes_bCdnAltRes = 1;
      TQALTRES_u16tiAltCpt = (uint16)MATHSRV_udtMIN(TQALTRES_u16tiAltCpt, 1500);
   }
   else
   {
      if (bLocalTqRes_bCdnNEngAltRes_MP != 0)
      {
         if (bLocalTqSys_bEngNOnIdl == 0)
         {
            TQALTRES_u16tiAltCpt = 0;
         }
         else
         {
            u16LocalTqRes_tiCdnNEngAltRes =
               (uint16)((TqRes_tiCdnNEngAltRes_C * 25) / 4);
            TQALTRES_u16tiAltCpt =
               (uint16)MATHSRV_udtMIN(u16LocalTqRes_tiCdnNEngAltRes, 1500);
         }
      }
      else
      {
         if (TQALTRES_u16tiAltCpt > 0)
         {
            u16LocalTQALTRES_u16tiAltCpt = (uint16)(TQALTRES_u16tiAltCpt - 1);
            TQALTRES_u16tiAltCpt =
               (uint16)MATHSRV_udtMIN(u16LocalTQALTRES_u16tiAltCpt, 1500);
         }
      }
      if (TQALTRES_u16tiAltCpt == 0)
      {
         TqRes_bCdnAltRes = 0;
      }
      else
      {
         TqRes_bCdnAltRes = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidCalculReserveALT                               */
/* !Description :  Le calcul de la réserve de couple alternateur dépend du    */
/*                 type d’alternateur (alternateur ICCP,alternateur piloté,   */
/*                 alternateur Urban Hybrid)                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQALTRES_vidCalculReserveAltICCP();                      */
/*  extf argret void TQALTRES_vidCalculReserveAltGap();                       */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input boolean TQALTRES_bCdnAltRes_prev;                                   */
/*  input boolean TqRes_bCdnAltRes;                                           */
/*  input uint16 TqRes_tqDftValAltRes_C;                                      */
/*  input uint16 TqRes_tqAltResStd;                                           */
/*  input uint16 TqRes_tqAltResGap;                                           */
/*  input uint16 TqRes_tqUHAltRes_C;                                          */
/*  input uint16 TqRes_tqIncMaxAltRes_C;                                      */
/*  input sint16 TqRes_tqDecMaxAltRes_C;                                      */
/*  input uint16 TqRes_tqAltResSat_MP;                                        */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input sint16 TqCmp_tqAltLoss;                                             */
/*  output uint16 TqRes_tqAltResSat_MP;                                       */
/*  output uint16 TqRes_tqAltRes;                                             */
/*  output boolean TQALTRES_bCdnAltRes_prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidCalculReserveALT(void)
{
   boolean bLocalAcvTqAltResDftVal;
   uint8   u8LocalExt_stElProdCf;
   uint16  u16LocalRateLimterOut;
   uint16  u16LocalTqRes_tqAltRes;
   uint16  u16LocalTqRes_tqDecMaxAltRes;
   uint16  u16LocalTqRes_tqIncMaxAltRes;
   uint16  u16LocalIn_DetectSat;
   sint16  s16LocalTqCmp_tqAltLoss;
   sint16  s16LocalTqRes_tqDecMaxAltRes;
   sint32  s32LocalDiff;


   VEMS_vidGET(Ext_stElProdCf, u8LocalExt_stElProdCf);
   if (u8LocalExt_stElProdCf == 0)
   {
      TQALTRES_vidCalculReserveAltICCP();
   }
   else
   {
      if (u8LocalExt_stElProdCf == 1)
      {
         TQALTRES_vidCalculReserveAltGap();
      }
   }
   if (  (TQALTRES_bCdnAltRes_prev != 0)
      || (TqRes_bCdnAltRes == 0))
   {
      if (TqRes_bCdnAltRes != 0)
      {
         bLocalAcvTqAltResDftVal = GDGAR_bGetFRM(FRM_FRM_ACVTQALTRESDFTVAL);
         if (bLocalAcvTqAltResDftVal != 0)
         {
            u16LocalIn_DetectSat = TqRes_tqDftValAltRes_C;
         }
         else
         {
            switch(u8LocalExt_stElProdCf)
            {
               case 0:
                  u16LocalIn_DetectSat = TqRes_tqAltResStd;
                  break;

               case 1:
                  u16LocalIn_DetectSat = TqRes_tqAltResGap;
                  break;

               case 2:
               case 3:
                  u16LocalIn_DetectSat = TqRes_tqUHAltRes_C;
                  break;

               default:
                  u16LocalIn_DetectSat = TqRes_tqUHAltRes_C;
                  SWFAIL_vidSoftwareErrorHook();
                  break;
            }
         }
      }
      else
      {
         u16LocalIn_DetectSat = 0;
      }

      u16LocalTqRes_tqIncMaxAltRes = (uint16)(TqRes_tqIncMaxAltRes_C / 25);
      s16LocalTqRes_tqDecMaxAltRes = (sint16)(TqRes_tqDecMaxAltRes_C / 25);
      s16LocalTqRes_tqDecMaxAltRes =
         (sint16)( (-1) * s16LocalTqRes_tqDecMaxAltRes);
      u16LocalTqRes_tqDecMaxAltRes =
         (uint16)MATHSRV_udtMAX(s16LocalTqRes_tqDecMaxAltRes, 0);
      u16LocalRateLimterOut =
         MATHSRV_u16SlewFilter(TqRes_tqAltResSat_MP,
                               u16LocalIn_DetectSat,
                               u16LocalTqRes_tqIncMaxAltRes,
                               u16LocalTqRes_tqDecMaxAltRes);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalRateLimterOut);
   }
   TqRes_tqAltResSat_MP = (uint16)MATHSRV_udtMIN(u16LocalRateLimterOut, 1600);

   VEMS_vidGET(TqCmp_tqAltLoss, s16LocalTqCmp_tqAltLoss);
   s32LocalDiff = (sint32)(TqRes_tqAltResSat_MP - s16LocalTqCmp_tqAltLoss);
   u16LocalTqRes_tqAltRes = (uint16)MATHSRV_udtCLAMP(s32LocalDiff, 0, 1600);
   VEMS_vidSET(TqRes_tqAltRes, u16LocalTqRes_tqAltRes);

   TQALTRES_bCdnAltRes_prev = TqRes_bCdnAltRes;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidCalculReserveAltICCP                           */
/* !Description :  Cette fonction effectue le calcul de la réserve de couple  */
/*                 pour un alternateur standard.                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_rAltCycOp;                                                */
/*  input uint8 Ext_stAltClasCf;                                              */
/*  input uint8 TqRes_facFilDuCyAltRes_C;                                     */
/*  input uint32 TQALTRES_u32FiltredCoefFilCCPMem;                            */
/*  input uint8 TqRes_rAltFil_MP;                                             */
/*  input uint8 TqRes_idxAltStdClas_T[8];                                     */
/*  input uint8 TqRes_rAltFil_A[8];                                           */
/*  input uint16 TqRes_tqAltResStdClas1_T[8];                                 */
/*  input uint16 TqRes_tqAltResStdClas2_T[8];                                 */
/*  input uint16 TqRes_tqAltResStdClas3_T[8];                                 */
/*  output uint8 TqRes_rAltFil_MP;                                            */
/*  output uint32 TQALTRES_u32FiltredCoefFilCCPMem;                           */
/*  output uint16 TqRes_tqAltResStd;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidCalculReserveAltICCP(void)
{
   uint8  u8LocalInterpSwitch;
   uint8  u8LocalExt_stAltClasCf;
   uint8  u8LocalFilterGain;
   uint8  u8LocalExt_rAltCycOp;
   uint16 u16LocalTqRes_rAltFil_MP;
   uint16 u16localCalcPara;
   uint16 u16LocalExt_stAltClasCf;
   uint16 u16LocalTqRes_tqAltResStd;


   VEMS_vidGET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
   VEMS_vidGET(Ext_stAltClasCf, u8LocalExt_stAltClasCf);

   if (TqRes_facFilDuCyAltRes_C < 128)
   {
      u8LocalFilterGain = (uint8)(TqRes_facFilDuCyAltRes_C * 2);
      u16LocalTqRes_rAltFil_MP =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &TQALTRES_u32FiltredCoefFilCCPMem,
                                        (uint16)u8LocalExt_rAltCycOp);
      TqRes_rAltFil_MP = (uint8)MATHSRV_udtMIN(u16LocalTqRes_rAltFil_MP, 100);
   }
   else
   {
      TqRes_rAltFil_MP = (uint8)MATHSRV_udtMIN(u8LocalExt_rAltCycOp, 100);
      TQALTRES_u32FiltredCoefFilCCPMem = (uint32)(TqRes_rAltFil_MP * 256);
   }

   u8LocalExt_stAltClasCf = (uint8)MATHSRV_udtMIN(u8LocalExt_stAltClasCf, 7);
   u16LocalExt_stAltClasCf = (uint16)(u8LocalExt_stAltClasCf * 256);
   u8LocalInterpSwitch = MATHSRV_u8Interp1d(TqRes_idxAltStdClas_T,
                                            u16LocalExt_stAltClasCf);

   u16localCalcPara = MATHSRV_u16CalcParaIncAryU8(TqRes_rAltFil_A,
                                                  TqRes_rAltFil_MP,
                                                  8);

   switch (u8LocalInterpSwitch)
   {
      case 1:
         u16LocalTqRes_tqAltResStd =
            MATHSRV_u16Interp1d(TqRes_tqAltResStdClas1_T, u16localCalcPara);
         break;

      case 2:
         u16LocalTqRes_tqAltResStd =
            MATHSRV_u16Interp1d(TqRes_tqAltResStdClas2_T, u16localCalcPara);
         break;

      case 3:
         u16LocalTqRes_tqAltResStd =
            MATHSRV_u16Interp1d(TqRes_tqAltResStdClas3_T, u16localCalcPara);
         break;

      default:
         u16LocalTqRes_tqAltResStd =
            MATHSRV_u16Interp1d(TqRes_tqAltResStdClas3_T, u16localCalcPara);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   TqRes_tqAltResStd = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqAltResStd, 1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQALTRES_vidCalculReserveAltGap                            */
/* !Description :  Cette fonction effectue le calcul de la réserve de couple  */
/*                 pour un alternateur de type Gap.                           */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02660_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_iAltExct;                                                 */
/*  input uint8 Ext_idxAltClas;                                               */
/*  input uint8 TqRes_facFilIAltRes_C;                                        */
/*  input uint32 TQALTRES_u32FiltredCoefFilGapMem;                            */
/*  input uint8 TqRes_iAltFil_MP;                                             */
/*  input uint8 TqRes_idxAltGapClas3_C;                                       */
/*  input uint8 TqRes_idxAltGapClas2_C;                                       */
/*  input uint8 TqRes_iAltFil_A[8];                                           */
/*  input uint16 TqRes_tqAltResGapClas1_T[8];                                 */
/*  input uint16 TqRes_tqAltResGapClas2_T[8];                                 */
/*  input uint16 TqRes_tqAltResGapClas3_T[8];                                 */
/*  output uint8 TqRes_iAltFil_MP;                                            */
/*  output uint32 TQALTRES_u32FiltredCoefFilGapMem;                           */
/*  output uint16 TqRes_tqAltResGap;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQALTRES_vidCalculReserveAltGap(void)
{
   uint8  u8LocalExt_iAltExct;
   uint8  u8LocalExt_idxAltClas;
   uint8  u8LocalFilterGain;
   uint8  u8LocalInputSwitch;
   uint16 u16LocalTqRes_iAltFil_MP;
   uint16 u16localCalcPara;
   uint16 u16LocalTqRes_tqAltResGap;


   VEMS_vidGET(Ext_iAltExct, u8LocalExt_iAltExct);
   VEMS_vidGET(Ext_idxAltClas, u8LocalExt_idxAltClas);
   if (TqRes_facFilIAltRes_C < 128)
   {
      u8LocalFilterGain = (uint8)(TqRes_facFilIAltRes_C * 2);
      u16LocalTqRes_iAltFil_MP =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &TQALTRES_u32FiltredCoefFilGapMem,
                                        (uint16)u8LocalExt_iAltExct);
      TqRes_iAltFil_MP = (uint8)MATHSRV_udtMIN(u16LocalTqRes_iAltFil_MP, 254);
   }
   else
   {
      TqRes_iAltFil_MP = (uint8)MATHSRV_udtMIN(u8LocalExt_iAltExct, 254);
      TQALTRES_u32FiltredCoefFilGapMem = (uint32)(TqRes_iAltFil_MP * 256);
   }

   if (u8LocalExt_idxAltClas != TqRes_idxAltGapClas3_C)
   {
      if (u8LocalExt_idxAltClas != TqRes_idxAltGapClas2_C)
      {
         u8LocalInputSwitch = 1;
      }
      else
      {
         u8LocalInputSwitch = 2;
      }
   }
   else
   {
      u8LocalInputSwitch = 3;
   }

   u16localCalcPara = MATHSRV_u16CalcParaIncAryU8(TqRes_iAltFil_A,
                                                  TqRes_iAltFil_MP,
                                                  8);

   if (u8LocalInputSwitch == 1)
   {
      u16LocalTqRes_tqAltResGap = MATHSRV_u16Interp1d(TqRes_tqAltResGapClas1_T,
                                                      u16localCalcPara);
   }
   else
   {
      if (u8LocalInputSwitch == 2)
      {
         u16LocalTqRes_tqAltResGap =
            MATHSRV_u16Interp1d(TqRes_tqAltResGapClas2_T, u16localCalcPara);
      }
      else
      {
         u16LocalTqRes_tqAltResGap =
            MATHSRV_u16Interp1d(TqRes_tqAltResGapClas3_T, u16localCalcPara);
      }
   }

   TqRes_tqAltResGap = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqAltResGap, 1600);
}
/*---------------------------------end of file--------------------------------*/