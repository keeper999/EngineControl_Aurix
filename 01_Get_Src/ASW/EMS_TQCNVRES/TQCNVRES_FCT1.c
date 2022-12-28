/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCNVRES                                                */
/* !Description     : TQCNVRES Component                                      */
/*                                                                            */
/* !Module          : TQCNVRES                                                */
/* !Description     : Réserve de couple BVA                                   */
/*                                                                            */
/* !File            : TQCNVRES_FCT1.C                                         */
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
/*   1 / TQCNVRES_vidInitOutput                                               */
/*   2 / TQCNVRES_vidReserve_Couple_BVA                                       */
/*   3 / TQCNVRES_vidCondition_Engagement                                     */
/*   4 / TQCNVRES_vidCondition_Sortie_Rdt                                     */
/*   5 / TQCNVRES_vidCalcul_Reserve                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 08543 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0179 / 2.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCNVRES/TQCNVRES$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "TQCNVRES.H"
#include "TQCNVRES_L.H"
#include "TQCNVRES_IM.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidInitOutput                                     */
/* !Description :  Initialisation de toutes les sorties du module ainsi que   */
/*                 les états précédentes des bascules.                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  output uint16 TqRes_tqCnvRes;                                             */
/*  output boolean TQCNVRES_bEfcBrkPedPrssPrev;                               */
/*  output boolean TQCNVRES_bInputRisingPrev;                                 */
/*  output boolean TQCNVRES_bCdnDragRedPrev;                                  */
/*  output boolean TQCNVRES_bCdnDragRedPrev1;                                 */
/*  output uint16 TQCNVRES_u16tiCdn1Cpt;                                      */
/*  output uint16 TQCNVRES_u16tiCdn2Cpt;                                      */
/*  output uint8 TQCNVRES_u8DragRedPrev;                                      */
/*  output boolean TqRes_bCdnEgdCnvRes;                                       */
/*  output boolean TQCNVRES_bInputRising2Prev;                                */
/*  output boolean TqRes_bCdnDragRedCnvRes;                                   */
/*  output boolean TqRes_bCdnStGBxEgdCnvRes_MP;                               */
/*  output uint16 TqRes_tqCnvResSat_MP;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidInitOutput(void)
{
   uint16 u16LocalTqRes_tqIdlRes;


   VEMS_vidSET(TqRes_tqCnvRes, 0);
   TQCNVRES_bEfcBrkPedPrssPrev = 0;
   TQCNVRES_bInputRisingPrev = 0;
   TQCNVRES_bCdnDragRedPrev = 0;
   TQCNVRES_bCdnDragRedPrev1 = 0;
   TQCNVRES_u16tiCdn1Cpt = 0;
   TQCNVRES_u16tiCdn2Cpt = 0;
   TQCNVRES_u8DragRedPrev = 0;
   TqRes_bCdnEgdCnvRes = 0;
   TQCNVRES_bInputRising2Prev = 0;
   TqRes_bCdnDragRedCnvRes = 0;
   TqRes_bCdnStGBxEgdCnvRes_MP = 0;

   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   TqRes_tqCnvResSat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes, 1600);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidReserve_Couple_BVA                             */
/* !Description :  La compensation de la réserve de couple BVA dépend de deux */
/*                 conditions : condition d’engagement et condition réduction */
/*                 de trainée. La fonction n’est activée que sur les          */
/*                 applications BVA.                                          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08543_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQCNVRES_vidCondition_Engagement();                      */
/*  extf argret void TQCNVRES_vidCondition_Sortie_Rdt();                      */
/*  extf argret void TQCNVRES_vidCalcul_Reserve();                            */
/*  input uint8 Ext_stGBxCf;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidReserve_Couple_BVA(void)
{
   uint8 u8LocalExt_stGBxCf;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 1)
   {
      TQCNVRES_vidCondition_Engagement();
      TQCNVRES_vidCondition_Sortie_Rdt();
      TQCNVRES_vidCalcul_Reserve();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidCondition_Engagement                           */
/* !Description :  La condition engagement s’active après un front montant au */
/*                 passage du neutre à un rapport cible BVA <> 0, à condition */
/*                 que l’état réduction de trainée soit différent de la valeur*/
/*                 3.                                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08543_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input uint8 CoPt_noTarGearCord;                                           */
/*  input uint8 CoPt_stDragRed;                                               */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean TQCNVRES_bInputRisingPrev;                                  */
/*  input uint8 TqRes_spdThrEgdCnvRes_C;                                      */
/*  input boolean TQCNVRES_bCdnDragRedPrev;                                   */
/*  input uint8 TqRes_tiCdnEgdCnvRes_C;                                       */
/*  input uint16 TQCNVRES_u16tiCdn1Cpt;                                       */
/*  input boolean TqRes_bCdnSpdEgdCnvRes_MP;                                  */
/*  input boolean TqRes_bCdnStGBxEgdCnvRes_MP;                                */
/*  input boolean TqRes_bCdnGearEgdCnvRes_MP;                                 */
/*  output boolean TqRes_bCdnGearEgdCnvRes_MP;                                */
/*  output boolean TqRes_bCdnSpdEgdCnvRes_MP;                                 */
/*  output uint16 TQCNVRES_u16tiCdn1Cpt;                                      */
/*  output boolean TqRes_bCdnStGBxEgdCnvRes_MP;                               */
/*  output boolean TqRes_bCdnEgdCnvRes;                                       */
/*  output boolean TQCNVRES_bInputRisingPrev;                                 */
/*  output boolean TQCNVRES_bCdnDragRedPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidCondition_Engagement(void)
{
   boolean bLocalDft_spdVeh;
   boolean bLocalInputRising;
   boolean bLocalCond;
   uint8   u8LocalCoPt_noTarGearCord;
   uint8   u8LocalCoPt_stDragRed;
   uint16  u16LocalTqRes_spdCnvSpd;
   uint16  u16LocalVeh_spdVeh;


   VEMS_vidGET(CoPt_noTarGearCord, u8LocalCoPt_noTarGearCord);
   VEMS_vidGET(CoPt_stDragRed, u8LocalCoPt_stDragRed);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   if (  (u8LocalCoPt_noTarGearCord != 0)
      && (u8LocalCoPt_stDragRed != 3))
   {
      bLocalInputRising = 1;
   }
   else
   {
      bLocalInputRising = 0;
   }

   if (  (bLocalInputRising != 0)
      && (TQCNVRES_bInputRisingPrev == 0))
   {
      TqRes_bCdnGearEgdCnvRes_MP = 1;
   }
   else
   {
      TqRes_bCdnGearEgdCnvRes_MP = 0;
   }

   bLocalDft_spdVeh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);

   u16LocalTqRes_spdCnvSpd = (uint16)(32 * TqRes_spdThrEgdCnvRes_C);

   if (  (u16LocalVeh_spdVeh >= u16LocalTqRes_spdCnvSpd)
      && (bLocalDft_spdVeh == 0))
   {
      TqRes_bCdnSpdEgdCnvRes_MP = 1;
   }
   else
   {
      TqRes_bCdnSpdEgdCnvRes_MP = 0;
   }

   if (  (u8LocalCoPt_stDragRed == 1)
      || (u8LocalCoPt_stDragRed == 2))
   {
      bLocalCond = 1;
   }
   else
   {
      bLocalCond = 0;
   }

   if (bLocalCond != 0)
   {
      if (TQCNVRES_bCdnDragRedPrev == 0)
      {
         TQCNVRES_u16tiCdn1Cpt =
            (uint16)(((TqRes_tiCdnEgdCnvRes_C * 25) + 2) / 4);
      }
      else
      {
         if (TQCNVRES_u16tiCdn1Cpt > 0)
         {
            TQCNVRES_u16tiCdn1Cpt = (uint16)(TQCNVRES_u16tiCdn1Cpt - 1);
         }
      }
      if (TQCNVRES_u16tiCdn1Cpt == 0)
      {
         TqRes_bCdnStGBxEgdCnvRes_MP = 1;
      }
      else
      {
         TqRes_bCdnStGBxEgdCnvRes_MP = 0;
      }
   }
   else
   {
      TqRes_bCdnStGBxEgdCnvRes_MP = 0;
   }

   if (  (bLocalInputRising == 0)
      || (TqRes_bCdnSpdEgdCnvRes_MP != 0)
      || (TqRes_bCdnStGBxEgdCnvRes_MP != 0))
   {
      TqRes_bCdnEgdCnvRes = 0;
   }
   else
   {
      if (TqRes_bCdnGearEgdCnvRes_MP != 0)
      {
         TqRes_bCdnEgdCnvRes = 1;
      }
   }
   TQCNVRES_bInputRisingPrev = bLocalInputRising;
   TQCNVRES_bCdnDragRedPrev = bLocalCond;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidCondition_Sortie_Rdt                           */
/* !Description :  Dans le cas ou la l’état de la BVA est en « réduction de la*/
/*                 trainée » , la condition s’active sur la détection du      */
/*                 passage de l’état de la BVA à « Embrayé » , ou sur         */
/*                 détection d’une sortie d’appui frein.                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08543_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_stDragRed;                                               */
/*  input boolean Ext_bEfcBrkPedPrss;                                         */
/*  input uint8 TQCNVRES_u8DragRedPrev;                                       */
/*  input boolean TQCNVRES_bEfcBrkPedPrssPrev;                                */
/*  input boolean TqRes_bCdnStGBxDragRed_MP;                                  */
/*  input boolean TqRes_bCdnBrkDragRed_MP;                                    */
/*  input boolean TQCNVRES_bCdnDragRedPrev1;                                  */
/*  input uint8 TqRes_tiCdnDragRedCnvRes_C;                                   */
/*  input uint16 TQCNVRES_u16tiCdn2Cpt;                                       */
/*  output boolean TqRes_bCdnStGBxDragRed_MP;                                 */
/*  output boolean TqRes_bCdnBrkDragRed_MP;                                   */
/*  output boolean TqRes_bCdnDragRedCnvRes;                                   */
/*  output uint16 TQCNVRES_u16tiCdn2Cpt;                                      */
/*  output uint8 TQCNVRES_u8DragRedPrev;                                      */
/*  output boolean TQCNVRES_bEfcBrkPedPrssPrev;                               */
/*  output boolean TQCNVRES_bCdnDragRedPrev1;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidCondition_Sortie_Rdt(void)
{
   boolean bLocalDelayOffIn;
   boolean bLocalExtbEfcBrkPedPrss;
   uint8   u8LocalCoPt_stDragRed;


   VEMS_vidGET(CoPt_stDragRed, u8LocalCoPt_stDragRed);
   VEMS_vidGET(Ext_bEfcBrkPedPrss, bLocalExtbEfcBrkPedPrss);

   if (  (TQCNVRES_u8DragRedPrev == 1)
      && (u8LocalCoPt_stDragRed == 2))
   {
      TqRes_bCdnStGBxDragRed_MP = 1;
   }
   else
   {
      TqRes_bCdnStGBxDragRed_MP = 0;
   }

   if (  (bLocalExtbEfcBrkPedPrss == 0)
      && (TQCNVRES_bEfcBrkPedPrssPrev != 0)
      && (u8LocalCoPt_stDragRed == 1))
   {
      TqRes_bCdnBrkDragRed_MP = 1;
   }
   else
   {
      TqRes_bCdnBrkDragRed_MP = 0;
   }

   if (  (TqRes_bCdnStGBxDragRed_MP != 0)
      || (TqRes_bCdnBrkDragRed_MP != 0))
   {
      bLocalDelayOffIn = 1;
   }
   else
   {
      bLocalDelayOffIn = 0;
   }

   if (bLocalDelayOffIn != 0)
   {
      TqRes_bCdnDragRedCnvRes = 1;
   }
   else
   {
      if (TQCNVRES_bCdnDragRedPrev1 != 0)
      {
         TQCNVRES_u16tiCdn2Cpt =
            (uint16)(((TqRes_tiCdnDragRedCnvRes_C * 25) + 2) / 4);
      }
      else
      {
         if (TQCNVRES_u16tiCdn2Cpt > 0)
         {
            TQCNVRES_u16tiCdn2Cpt = (uint16)(TQCNVRES_u16tiCdn2Cpt - 1);

         }
      }
      if (TQCNVRES_u16tiCdn2Cpt == 0)
      {
         TqRes_bCdnDragRedCnvRes = 0;
      }
      else
      {
         TqRes_bCdnDragRedCnvRes = 1;
      }
   }

   TQCNVRES_u8DragRedPrev = (uint8)MATHSRV_udtMIN(u8LocalCoPt_stDragRed, 3);
   TQCNVRES_bEfcBrkPedPrssPrev = bLocalExtbEfcBrkPedPrss;
   TQCNVRES_bCdnDragRedPrev1 = bLocalDelayOffIn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCNVRES_vidCalcul_Reserve                                 */
/* !Description :  La réserve de couple BVA est le maximum entre la valeur 0  */
/*                 et la soustraction de la réserve de couple demandée et le  */
/*                 couple compensé. La réserve de couple demandée s’active    */
/*                 lorsque la condition engagement ou la condition réduction  */
/*                 de trainée s’active.                                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08543_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqRes_bCdnEgdCnvRes;                                        */
/*  input boolean TqRes_bCdnDragRedCnvRes;                                    */
/*  input sint16 CoPt_tOilGBx;                                                */
/*  input uint8 TqRes_tOilGBx_A[8];                                           */
/*  input uint16 TqRes_tqEgdCnvRes_T[8];                                      */
/*  input uint16 TqRes_tqDragRedCnvRes_T[8];                                  */
/*  input uint16 TqRes_tqCnvResMax_MP;                                        */
/*  input uint16 TqRes_tqDftValCnvRes_C;                                      */
/*  input boolean TQCNVRES_bInputRising2Prev;                                 */
/*  input uint16 TqRes_tqIncMaxCnvRes_C;                                      */
/*  input sint16 TqRes_tqDecMaxCnvRes_C;                                      */
/*  input uint16 TqRes_tqCnvResSat_MP;                                        */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqCmp_tqCnvLoss;                                             */
/*  output uint16 TqRes_tqCnvResMax_MP;                                       */
/*  output uint16 TqRes_tqCnvResSat_MP;                                       */
/*  output uint16 TqRes_tqCnvRes;                                             */
/*  output boolean TQCNVRES_bInputRising2Prev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCNVRES_vidCalcul_Reserve(void)
{
   boolean bLocalAcvTqCnvResDftVal;
   boolean bLocalInputRising;
   uint8   u8LocalCoPt_tOilGBx;
   uint16  u16LocalInc;
   uint16  u16LocalTqRes_tqCnvResSat_MP;
   uint16  u16LocalTqRes_tqCnvResMax_MP;
   uint16  u16LocalRateLimiterInput;
   uint16  u16LocalTQCNVRESPara;
   uint16  u16LocalInterpEgd;
   uint16  u16LocalInterpDragRed;
   uint16  u16LocalTqCmp_tqCnvLoss;
   uint16  u16LocalTqRes_tqCnvRes;
   sint16  s16LocalDec;
   sint16  s16LocalCoPt_tOilGBx;
   sint32  s32LocalDiff;


   if (  (TqRes_bCdnEgdCnvRes == 0)
      && (TqRes_bCdnDragRedCnvRes == 0))
   {
      bLocalInputRising = 0;
      u16LocalRateLimiterInput = 0;
      TqRes_tqCnvResMax_MP = 0;
   }
   else
   {
      bLocalInputRising = 1;
      u16LocalInterpEgd = 0;
      u16LocalInterpDragRed = 0;

      VEMS_vidGET(CoPt_tOilGBx, s16LocalCoPt_tOilGBx);
      s16LocalCoPt_tOilGBx = (sint16)((s16LocalCoPt_tOilGBx / 4) + 50);
      u8LocalCoPt_tOilGBx = (uint8)MATHSRV_udtCLAMP(s16LocalCoPt_tOilGBx,
                                                    0,
                                                    250);
      u16LocalTQCNVRESPara = MATHSRV_u16CalcParaIncAryU8(TqRes_tOilGBx_A,
                                                         u8LocalCoPt_tOilGBx,
                                                         8);
      if (TqRes_bCdnEgdCnvRes != 0)
      {
         u16LocalInterpEgd = MATHSRV_u16Interp1d(TqRes_tqEgdCnvRes_T,
                                                 u16LocalTQCNVRESPara);
      }
      if (TqRes_bCdnDragRedCnvRes != 0)
      {
         u16LocalInterpDragRed = MATHSRV_u16Interp1d(TqRes_tqDragRedCnvRes_T,
                                                     u16LocalTQCNVRESPara);
      }

      u16LocalTqRes_tqCnvResMax_MP =
         (uint16)MATHSRV_udtMAX(u16LocalInterpDragRed, u16LocalInterpEgd);
      TqRes_tqCnvResMax_MP =
         (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqCnvResMax_MP, 1600);

      bLocalAcvTqCnvResDftVal = GDGAR_bGetFRM(FRM_FRM_ACVTQCNVRESDFTVAL);
      if (bLocalAcvTqCnvResDftVal == 0)
      {
         u16LocalRateLimiterInput = TqRes_tqCnvResMax_MP;
      }
      else
      {
         u16LocalRateLimiterInput = TqRes_tqDftValCnvRes_C;
      }
   }

   if (  (bLocalInputRising == 0)
      || (TQCNVRES_bInputRising2Prev != 0))
   {
      u16LocalInc = (uint16)(TqRes_tqIncMaxCnvRes_C / 25);
      s16LocalDec = (sint16)MATHSRV_udtMIN(TqRes_tqDecMaxCnvRes_C, 0);
      s16LocalDec = (sint16)(((-1)*s16LocalDec)  / 25);

      u16LocalTqRes_tqCnvResSat_MP =
         MATHSRV_u16SlewFilter(TqRes_tqCnvResSat_MP,
                               u16LocalRateLimiterInput,
                               u16LocalInc,
                               (uint16)s16LocalDec);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqCnvResSat_MP);
   }
   TqRes_tqCnvResSat_MP =
      (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqCnvResSat_MP, 1600);

   VEMS_vidGET(TqCmp_tqCnvLoss, u16LocalTqCmp_tqCnvLoss);
   s32LocalDiff = (sint32)(TqRes_tqCnvResSat_MP - u16LocalTqCmp_tqCnvLoss);
   u16LocalTqRes_tqCnvRes = (uint16)MATHSRV_udtMAX(0, s32LocalDiff);
   VEMS_vidSET(TqRes_tqCnvRes, u16LocalTqRes_tqCnvRes);

   TQCNVRES_bInputRising2Prev = bLocalInputRising;
}

/*------------------------------- end of file --------------------------------*/
