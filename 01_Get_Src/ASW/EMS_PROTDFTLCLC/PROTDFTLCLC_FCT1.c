/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PROTDFTLCLC                                             */
/* !Description     : PROTDFTLCLC component.                                  */
/*                                                                            */
/* !Module          : PROTDFTLCLC                                             */
/* !Description     : Protection Differentiel et Surchauffe Frein             */
/*                                                                            */
/* !File            : PROTDFTLCLC_FCT1.C                                      */
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
/*   1 / PROTDFTLCLC_vidInitOutput                                            */
/*   2 / PROTDFTLCLC_vidEstimSollicitDiff                                     */
/*   3 / PROTDFTLCLC_vidDetEnergieCourant                                     */
/*   4 / PROTDFTLCLC_vidDetCoupleCouronne                                     */
/*   5 / PROTDFTLCLC_vidEstimerRegimeDiff                                     */
/*   6 / PROTDFTLCLC_vidDetPuissance                                          */
/*   7 / PROTDFTLCLC_vidDeterminerEnergie                                     */
/*   8 / PROTDFTLCLC_vidEstimSollicit                                         */
/*   9 / PROTDFTLCLC_vidDetActLimitCouple                                     */
/*   10 / PROTDFTLCLC_vidDetCoupleProtDiff                                    */
/*                                                                            */
/* !Reference   : V02 NT 11 04686 / 01                                        */
/* !OtherRefs   : 01460_10_02301 / 1.2                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PROTDFTLCLC.h"
#include "PROTDFTLCLC_L.h"
#include "PROTDFTLCLC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidInitOutput                                  */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_spdRiFrntWhl;                                            */
/*  input uint16 Ext_spdLeFrntWhl;                                            */
/*  input uint16 Ext_spdRiReWhl;                                              */
/*  input uint16 Ext_spdLeReWhl;                                              */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint8 CoPt_noEgdGearCordIt;                                         */
/*  input boolean Ext_bAcvProtBrk;                                            */
/*  input uint16 CoPt_wMaxSatProtDftl_C;                                      */
/*  input uint16 CoPt_wMaxProtDftl_C;                                         */
/*  input uint16 PROTDFTLCLC_u16SpdRiFrntWhl;                                 */
/*  input uint16 PROTDFTLCLC_u16SpdLeFrntWhl;                                 */
/*  input uint16 PROTDFTLCLC_u16SpdRiReWhl;                                   */
/*  input uint16 PROTDFTLCLC_u16SpdLeReWhl;                                   */
/*  input uint16 CoPt_nEngProtBrkX_A[16];                                     */
/*  input uint8 CoPt_noGearProtBrkY_A[10];                                    */
/*  input uint16 CoPt_tqEfcMaxProtBrk_M[16][10];                              */
/*  input sint16 CoPt_tqEfcMaxProtBrk_MP;                                     */
/*  input boolean CoPt_bProtDftlAcv;                                          */
/*  input uint8 CoPt_tiAcvTqProtDftl_C;                                       */
/*  input uint8 CoPt_tiDeacTqProtDftl_C;                                      */
/*  input uint8 PROTDFTLCLC_u8ProtAcvSelOld;                                  */
/*  input sint16 CoPt_tqMaxProtDftlBfCord_MP;                                 */
/*  input uint8 CoPt_tiAcvTqProtBrk_C;                                        */
/*  input uint8 CoPt_tiDeacTqProtBrk_C;                                       */
/*  input uint8 PROTDFTLCLC_u8ProtAcvBrkSelOld;                               */
/*  output uint8 CoPt_stProt;                                                 */
/*  output sint16 CoPt_tqEfcMaxProtDftl;                                      */
/*  output uint16 PROTDFTLCLC_u16CoProtDftl;                                  */
/*  output uint16 CoPt_wSpcProtDftl;                                          */
/*  output uint16 PROTDFTLCLC_u16SpdRiFrntWhl;                                */
/*  output uint32 PROTDFTLCLC_u32rFilRiFrntWhlMem;                            */
/*  output uint16 PROTDFTLCLC_u16SpdLeFrntWhl;                                */
/*  output uint32 PROTDFTLCLC_u32rFilLeFrntWhlMem;                            */
/*  output uint16 PROTDFTLCLC_u16SpdRiReWhl;                                  */
/*  output uint32 PROTDFTLCLC_u32rFilRiReWhlMem;                              */
/*  output uint16 PROTDFTLCLC_u16SpdLeReWhl;                                  */
/*  output uint32 PROTDFTLCLC_u32rFilLeReWhlMem;                              */
/*  output sint16 CoPt_tqEfcMaxProtBrk_MP;                                    */
/*  output sint32 PROTDFTLCLC_s32rFilMaxProtBrkMem;                           */
/*  output uint16 PROTDFTLCLC_u16CoPtDftlWhl;                                 */
/*  output uint32 PROTDFTLCLC_u32rFilDftlWhlMem;                              */
/*  output uint16 PROTDFTLCLC_u16WhlMaxProtDftl;                              */
/*  output uint32 PROTDFTLCLC_u32rFilMaxProtMem;                              */
/*  output sint16 CoPt_tqMaxProtDftlBfCord_MP;                                */
/*  output uint8 PROTDFTLCLC_u8Counter;                                       */
/*  output boolean PROTDFTLCLC_bEtatTmr;                                      */
/*  output boolean PROTDFTLCLC_bActivationMem;                                */
/*  output uint8 PROTDFTLCLC_u8CounterBrk;                                    */
/*  output boolean PROTDFTLCLC_bEtatTmrBrk;                                   */
/*  output boolean PROTDFTLCLC_bActivationMemBrk;                             */
/*  output boolean PROTDFTLCLC_bOutHysNeg;                                    */
/*  output uint8 PROTDFTLCLC_u8ProtAcvSelPrev;                                */
/*  output uint8 PROTDFTLCLC_u8ProtAcvSelOld;                                 */
/*  output uint8 PROTDFTLCLC_u8AcvDeacTrDly;                                  */
/*  output sint16 PROTDFTLCLC_s16MaxProtBfCord;                               */
/*  output uint8 PROTDFTLCLC_u8AcvBrkSelPrev;                                 */
/*  output uint8 PROTDFTLCLC_u8ProtAcvBrkSelOld;                              */
/*  output uint8 PROTDFTLCLC_u8AcvDeacBrkTrDly;                               */
/*  output sint16 PROTDFTLCLC_s16MaxProtBrk;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidInitOutput(void)
{
   boolean bLocalExtAcvProtBrk;
   uint8   u8LocalCoPtEgdGearCordIt;
   uint8   u8LocalTrSat;
   sint8   s8LocalEgdGearCordIt;
   uint16  u16LocalExt_spdRiFrntWhl;
   uint16  u16LocalExt_spdLeFrntWhl;
   uint16  u16LocalExt_spdRiReWhl;
   uint16  u16LocalExt_spdLeReWhl;
   uint16  u16LocalCalcParaX;
   uint16  u16LocalCalcParaY;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalCoPtEfcMaxBrk;
   uint32  u32LocalCoPt_wMaxSatProtDftl;
   sint32  s32LocalCoPtEfcMaxBrk;


   VEMS_vidGET(Ext_spdRiFrntWhl, u16LocalExt_spdRiFrntWhl);
   VEMS_vidGET(Ext_spdLeFrntWhl, u16LocalExt_spdLeFrntWhl);
   VEMS_vidGET(Ext_spdRiReWhl, u16LocalExt_spdRiReWhl);
   VEMS_vidGET(Ext_spdLeReWhl, u16LocalExt_spdLeReWhl);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(CoPt_noEgdGearCordIt, s8LocalEgdGearCordIt);
   VEMS_vidGET(Ext_bAcvProtBrk, bLocalExtAcvProtBrk);

   VEMS_vidSET(CoPt_stProt, 0);
   VEMS_vidSET(CoPt_tqEfcMaxProtDftl, 32000);
   u32LocalCoPt_wMaxSatProtDftl = CoPt_wMaxSatProtDftl_C * 2;
   PROTDFTLCLC_u16CoProtDftl =
      (uint16)MATHSRV_udtMIN(CoPt_wMaxProtDftl_C, u32LocalCoPt_wMaxSatProtDftl);
   CoPt_wSpcProtDftl = 0;

   PROTDFTLCLC_u16SpdRiFrntWhl = u16LocalExt_spdRiFrntWhl;
   PROTDFTLCLC_u32rFilRiFrntWhlMem =
      (uint32)(PROTDFTLCLC_u16SpdRiFrntWhl * 256);

   PROTDFTLCLC_u16SpdLeFrntWhl = u16LocalExt_spdLeFrntWhl;
   PROTDFTLCLC_u32rFilLeFrntWhlMem =
      (uint32)(PROTDFTLCLC_u16SpdLeFrntWhl * 256);

   PROTDFTLCLC_u16SpdRiReWhl = u16LocalExt_spdRiReWhl;
   PROTDFTLCLC_u32rFilRiReWhlMem = (uint32)(PROTDFTLCLC_u16SpdRiReWhl * 256);

   PROTDFTLCLC_u16SpdLeReWhl = u16LocalExt_spdLeReWhl;
   PROTDFTLCLC_u32rFilLeReWhlMem = (uint32)(PROTDFTLCLC_u16SpdLeReWhl * 256);

   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(CoPt_nEngProtBrkX_A,
                                                    u16LocalEng_nCkFil,
                                                    16);
   s8LocalEgdGearCordIt = (sint8)MATHSRV_udtMAX(s8LocalEgdGearCordIt, -1);
   u8LocalCoPtEgdGearCordIt = (uint8)(s8LocalEgdGearCordIt + 1);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(CoPt_noGearProtBrkY_A,
                                                   u8LocalCoPtEgdGearCordIt,
                                                   10);
   u16LocalCoPtEfcMaxBrk =
      MATHSRV_u16Interp2d(&CoPt_tqEfcMaxProtBrk_M[0][0],
                          u16LocalCalcParaX,
                          u16LocalCalcParaY,
                          10);
   s32LocalCoPtEfcMaxBrk = (sint32)(u16LocalCoPtEfcMaxBrk - 32000);
   CoPt_tqEfcMaxProtBrk_MP =
      (sint16)MATHSRV_udtMIN(s32LocalCoPtEfcMaxBrk, 32000);
   PROTDFTLCLC_s32rFilMaxProtBrkMem = (sint32)(CoPt_tqEfcMaxProtBrk_MP * 256);

   PROTDFTLCLC_u16CoPtDftlWhl = 0;
   PROTDFTLCLC_u32rFilDftlWhlMem = 0;

   PROTDFTLCLC_u16WhlMaxProtDftl = 0;
   PROTDFTLCLC_u32rFilMaxProtMem = 0;

   CoPt_tqMaxProtDftlBfCord_MP = 0;
   PROTDFTLCLC_u8Counter = 0;
   PROTDFTLCLC_bEtatTmr = 0;
   PROTDFTLCLC_bActivationMem = 0;
   PROTDFTLCLC_u8CounterBrk = 0;
   PROTDFTLCLC_bEtatTmrBrk = 0;
   PROTDFTLCLC_bActivationMemBrk = 0;

   PROTDFTLCLC_bOutHysNeg = 0;
   if (CoPt_bProtDftlAcv != 0)
   {
      PROTDFTLCLC_u8ProtAcvSelPrev = 1;
      PROTDFTLCLC_u8ProtAcvSelOld = 1;
      u8LocalTrSat = (uint8)((25 * CoPt_tiAcvTqProtDftl_C) / 32);
   }
   else
   {
      PROTDFTLCLC_u8ProtAcvSelPrev = 2;
      PROTDFTLCLC_u8ProtAcvSelOld = 2;
      u8LocalTrSat = (uint8)((25 * CoPt_tiDeacTqProtDftl_C) / 32);
   }
   PROTDFTLCLC_u8AcvDeacTrDly = (uint8)MATHSRV_udtMAX(u8LocalTrSat, 1);

   if (PROTDFTLCLC_u8ProtAcvSelOld == 1)
   {
      PROTDFTLCLC_s16MaxProtBfCord = CoPt_tqMaxProtDftlBfCord_MP;
   }
   else
   {
      PROTDFTLCLC_s16MaxProtBfCord = 32000;
   }
   if (bLocalExtAcvProtBrk != 0)
   {
      PROTDFTLCLC_u8AcvBrkSelPrev = 1;
      PROTDFTLCLC_u8ProtAcvBrkSelOld = 1;
      u8LocalTrSat = (uint8)((25 * CoPt_tiAcvTqProtBrk_C) / 32);
   }
   else
   {
      PROTDFTLCLC_u8AcvBrkSelPrev = 2;
      PROTDFTLCLC_u8ProtAcvBrkSelOld = 2;
      u8LocalTrSat = (uint8)((25 * CoPt_tiDeacTqProtBrk_C) / 32);
   }
   PROTDFTLCLC_u8AcvDeacBrkTrDly = (uint8)MATHSRV_udtMAX(u8LocalTrSat, 1);

   if (PROTDFTLCLC_u8ProtAcvBrkSelOld == 1)
   {
      PROTDFTLCLC_s16MaxProtBrk = CoPt_tqEfcMaxProtBrk_MP;
   }
   else
   {
      PROTDFTLCLC_s16MaxProtBrk = 32000;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidEstimSollicitDiff                           */
/* !Description :  Ce bloc estime les sollicitations du différentiel. La      */
/*                 fonction se décompose en 2 blocs:Déterminer l’énergie      */
/*                 courante dans le différentiel, Estimer la sollicitation    */
/*                 énergétique du différentiel par rapport à son énergie      */
/*                 maximale admissible.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTDFTLCLC_vidDetEnergieCourant();                      */
/*  extf argret void PROTDFTLCLC_vidEstimSollicit();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidEstimSollicitDiff(void)
{
   PROTDFTLCLC_vidDetEnergieCourant();
   PROTDFTLCLC_vidEstimSollicit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetEnergieCourant                           */
/* !Description :  Ce bloc détermine les composantes énergétiques. La fonction*/
/*                 se décompose en 4 blocs : Déterminer le couple couronne,   */
/*                 Estimer le régime différentiel des roues motrices,         */
/*                 Déterminer la puissance, Déterminer l’énergie.             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTDFTLCLC_vidDetCoupleCouronne();                      */
/*  extf argret void PROTDFTLCLC_vidEstimerRegimeDiff();                      */
/*  extf argret void PROTDFTLCLC_vidDetPuissance();                           */
/*  extf argret void PROTDFTLCLC_vidDeterminerEnergie();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetEnergieCourant(void)
{
   PROTDFTLCLC_vidDetCoupleCouronne();
   PROTDFTLCLC_vidEstimerRegimeDiff();
   PROTDFTLCLC_vidDetPuissance();
   PROTDFTLCLC_vidDeterminerEnergie();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetCoupleCouronne                           */
/* !Description :  Ce bloc détermine le couple couronne à partir du taux de   */
/*                 conversion de couple et du couple moteur réel.             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CoPt_rCnvTq;                                                 */
/*  input sint16 TqSys_tqCkEngReal;                                           */
/*  output uint16 CoPt_tqWhlProtDftl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetCoupleCouronne(void)
{
   uint16 u16LocalCoPt_rCnvTq;
   sint16 s16LocalTqSys_tqCkEngReal;
   sint32 s32LocalCoPt_tqWhlProtDftl;


   VEMS_vidGET(CoPt_rCnvTq, u16LocalCoPt_rCnvTq);
   VEMS_vidGET(TqSys_tqCkEngReal, s16LocalTqSys_tqCkEngReal);

   s32LocalCoPt_tqWhlProtDftl =
      (((u16LocalCoPt_rCnvTq * s16LocalTqSys_tqCkEngReal) + 256) / 512);
   CoPt_tqWhlProtDftl =
      (uint16)MATHSRV_udtCLAMP(s32LocalCoPt_tqWhlProtDftl, 0, 44000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidEstimerRegimeDiff                           */
/* !Description :  Ce bloc convertit les vitesses roues en régimes roues pour */
/*                 déterminer le régime différentiel des roues motrices ainsi */
/*                 que le régime moyen des roues arrière.                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_spdRiFrntWhl;                                            */
/*  input uint16 Ext_spdLeFrntWhl;                                            */
/*  input uint16 Ext_spdRiReWhl;                                              */
/*  input uint16 Ext_spdLeReWhl;                                              */
/*  input uint8 CoPt_facSpdWhlFil_C;                                          */
/*  input uint16 PROTDFTLCLC_u16SpdRiFrntWhl;                                 */
/*  input uint16 PROTDFTLCLC_u16SpdLeFrntWhl;                                 */
/*  input uint16 PROTDFTLCLC_u16SpdRiReWhl;                                   */
/*  input uint16 PROTDFTLCLC_u16SpdLeReWhl;                                   */
/*  input uint32 PROTDFTLCLC_u32rFilRiFrntWhlMem;                             */
/*  input uint32 PROTDFTLCLC_u32rFilLeFrntWhlMem;                             */
/*  input uint32 PROTDFTLCLC_u32rFilRiReWhlMem;                               */
/*  input uint32 PROTDFTLCLC_u32rFilLeReWhlMem;                               */
/*  input uint16 CoPt_dstWhlProtDftl_C;                                       */
/*  input uint16 CoPt_nReWhlAvr;                                              */
/*  output uint16 PROTDFTLCLC_u16SpdRiFrntWhl;                                */
/*  output uint32 PROTDFTLCLC_u32rFilRiFrntWhlMem;                            */
/*  output uint16 PROTDFTLCLC_u16SpdLeFrntWhl;                                */
/*  output uint32 PROTDFTLCLC_u32rFilLeFrntWhlMem;                            */
/*  output uint16 PROTDFTLCLC_u16SpdRiReWhl;                                  */
/*  output uint32 PROTDFTLCLC_u32rFilRiReWhlMem;                              */
/*  output uint16 PROTDFTLCLC_u16SpdLeReWhl;                                  */
/*  output uint32 PROTDFTLCLC_u32rFilLeReWhlMem;                              */
/*  output uint16 CoPt_nReWhlAvr;                                             */
/*  output uint16 CoPt_nDftlWhl;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidEstimerRegimeDiff(void)
{
   boolean bLocalDftSpdRiReWhl;
   boolean bLocalDftSpdLeReWhl;
   uint8   u8LocalCoPt_facSpdWhlFil;
   uint16  u16LocalExt_spdRiFrntWhl;
   uint16  u16LocalExt_spdLeFrntWhl;
   uint16  u16LocalExt_spdRiReWhl;
   uint16  u16LocalExt_spdLeReWhl;
   uint32  u32LocalCoPt_nRiFrntWhl;
   uint32  u32LocalRiFrntWhl;
   uint32  u32LocalCoPt_nLeFrntWhl;
   uint32  u32LocalCoPt_nRiReWhl;
   uint32  u32LocalCoPt_nLeReWhl;
   uint32  u32LocalCoPt_nReWhlAvr;
   sint32  s32LocalCoPt_nDftlWhl;


   bLocalDftSpdRiReWhl = GDGAR_bGetFRM(FRM_FRM_DFTSPDRIREWHL);
   bLocalDftSpdLeReWhl = GDGAR_bGetFRM(FRM_FRM_DFTSPDLEREWHL);

   VEMS_vidGET(Ext_spdRiFrntWhl, u16LocalExt_spdRiFrntWhl);
   VEMS_vidGET(Ext_spdLeFrntWhl, u16LocalExt_spdLeFrntWhl);
   VEMS_vidGET(Ext_spdRiReWhl, u16LocalExt_spdRiReWhl);
   VEMS_vidGET(Ext_spdLeReWhl, u16LocalExt_spdLeReWhl);

   if (CoPt_facSpdWhlFil_C >= 128)
   {
      PROTDFTLCLC_u16SpdRiFrntWhl = u16LocalExt_spdRiFrntWhl;
      PROTDFTLCLC_u32rFilRiFrntWhlMem = (uint32)( PROTDFTLCLC_u16SpdRiFrntWhl
                                                * 256);

      PROTDFTLCLC_u16SpdLeFrntWhl = u16LocalExt_spdLeFrntWhl;
      PROTDFTLCLC_u32rFilLeFrntWhlMem = (uint32)( PROTDFTLCLC_u16SpdLeFrntWhl
                                                * 256);

      PROTDFTLCLC_u16SpdRiReWhl = u16LocalExt_spdRiReWhl;
      PROTDFTLCLC_u32rFilRiReWhlMem = (uint32)( PROTDFTLCLC_u16SpdRiReWhl
                                              * 256);

      PROTDFTLCLC_u16SpdLeReWhl = u16LocalExt_spdLeReWhl;
      PROTDFTLCLC_u32rFilLeReWhlMem = (uint32)( PROTDFTLCLC_u16SpdLeReWhl
                                              * 256);
   }
   else
   {
      u8LocalCoPt_facSpdWhlFil = (uint8)(CoPt_facSpdWhlFil_C * 2);
      PROTDFTLCLC_u16SpdRiFrntWhl =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalCoPt_facSpdWhlFil,
                                        &PROTDFTLCLC_u32rFilRiFrntWhlMem,
                                        u16LocalExt_spdRiFrntWhl);

      PROTDFTLCLC_u16SpdLeFrntWhl =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalCoPt_facSpdWhlFil,
                                        &PROTDFTLCLC_u32rFilLeFrntWhlMem,
                                        u16LocalExt_spdLeFrntWhl);

      PROTDFTLCLC_u16SpdRiReWhl =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalCoPt_facSpdWhlFil,
                                        &PROTDFTLCLC_u32rFilRiReWhlMem,
                                        u16LocalExt_spdRiReWhl);

      PROTDFTLCLC_u16SpdLeReWhl =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalCoPt_facSpdWhlFil,
                                        &PROTDFTLCLC_u32rFilLeReWhlMem,
                                        u16LocalExt_spdLeReWhl);
   }

   if (CoPt_dstWhlProtDftl_C != 0)
   {
      u32LocalCoPt_nRiFrntWhl = (uint32)(PROTDFTLCLC_u16SpdRiFrntWhl * 16667);
      u32LocalRiFrntWhl = (uint32)(CoPt_dstWhlProtDftl_C * 25);
      u32LocalCoPt_nRiFrntWhl = (u32LocalCoPt_nRiFrntWhl / u32LocalRiFrntWhl);

      u32LocalCoPt_nLeFrntWhl = (uint32)(PROTDFTLCLC_u16SpdLeFrntWhl * 16667);
      u32LocalCoPt_nLeFrntWhl = (u32LocalCoPt_nLeFrntWhl / u32LocalRiFrntWhl);

      u32LocalCoPt_nRiReWhl = (uint32)(PROTDFTLCLC_u16SpdRiReWhl * 16667);
      u32LocalCoPt_nRiReWhl = (u32LocalCoPt_nRiReWhl / u32LocalRiFrntWhl);

      u32LocalCoPt_nLeReWhl = (uint32)(PROTDFTLCLC_u16SpdLeReWhl * 16667);
      u32LocalCoPt_nLeReWhl = (u32LocalCoPt_nLeReWhl / u32LocalRiFrntWhl);
   }
   else
   {
      u32LocalCoPt_nRiFrntWhl = 43690873;
      u32LocalCoPt_nLeFrntWhl = 43690873;
      u32LocalCoPt_nRiReWhl = 43690873;
      u32LocalCoPt_nLeReWhl = 43690873;
   }

   if (  (bLocalDftSpdRiReWhl != 0)
      || (bLocalDftSpdLeReWhl != 0))
   {
      if (bLocalDftSpdRiReWhl != 0)
      {
         u32LocalCoPt_nReWhlAvr = u32LocalCoPt_nLeReWhl;
      }
      else
      {
         u32LocalCoPt_nReWhlAvr = u32LocalCoPt_nRiReWhl;
      }
   }
   else
   {
      u32LocalCoPt_nReWhlAvr =
         ((u32LocalCoPt_nLeReWhl / 2) + (u32LocalCoPt_nRiReWhl / 2));
   }
   CoPt_nReWhlAvr = (uint16)MATHSRV_udtMIN(u32LocalCoPt_nReWhlAvr, 32000);

   if (CoPt_nReWhlAvr > u32LocalCoPt_nLeFrntWhl)
   {
      u32LocalCoPt_nLeFrntWhl = 0;
   }
   else
   {
      u32LocalCoPt_nLeFrntWhl = (u32LocalCoPt_nLeFrntWhl - CoPt_nReWhlAvr);
   }

   if (CoPt_nReWhlAvr > u32LocalCoPt_nRiFrntWhl)
   {
      u32LocalCoPt_nRiFrntWhl = 0;
   }
   else
   {
      u32LocalCoPt_nRiFrntWhl = (u32LocalCoPt_nRiFrntWhl - CoPt_nReWhlAvr);
   }

   s32LocalCoPt_nDftlWhl =
      (sint32)u32LocalCoPt_nLeFrntWhl - (sint32)u32LocalCoPt_nRiFrntWhl;
   s32LocalCoPt_nDftlWhl = MATHSRV_udtABS(s32LocalCoPt_nDftlWhl);
   CoPt_nDftlWhl = (uint16)MATHSRV_udtMIN(s32LocalCoPt_nDftlWhl, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetPuissance                                */
/* !Description :  Ce bloc détermine la puissance fournie par le moteur au    */
/*                 différentiel. Cette puissance est égale au produit du      */
/*                 couple couronne et du régime différentiel des roues        */
/*                 motrices.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 CoPt_tqWhlProtDftl;                                          */
/*  input uint16 CoPt_nDftlWhl;                                               */
/*  output uint16 CoPt_pwrProtDftl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetPuissance(void)
{
   uint32 u32LocalCoPt_pwrProtDftl;


   u32LocalCoPt_pwrProtDftl =
      (uint32)(((CoPt_tqWhlProtDftl * CoPt_nDftlWhl) + 4775) / 9551);
   CoPt_pwrProtDftl = (uint16)MATHSRV_udtMIN(u32LocalCoPt_pwrProtDftl, 1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDeterminerEnergie                           */
/* !Description :  Ce bloc détermine l’énergie dans le différentiel ainsi que */
/*                 l’énergie « exceptionnelle » du différentiel.              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 CoPt_pwrColdProtDftl_C;                                       */
/*  input uint16 CoPt_pwrProtDftl;                                            */
/*  input uint16 CoPt_pwrProtDftl_MP;                                         */
/*  input uint16 PROTDFTLCLC_u16CoProtDftl;                                   */
/*  input uint16 CoPt_wMaxSatProtDftl_C;                                      */
/*  input uint16 CoPt_wMaxProtDftl_C;                                         */
/*  input uint16 CoPt_wSpcProtDftl;                                           */
/*  input uint16 CoPt_wMaxSpcProtDftl_C;                                      */
/*  output uint16 CoPt_pwrProtDftl_MP;                                        */
/*  output uint16 PROTDFTLCLC_u16CoProtDftl;                                  */
/*  output uint16 CoPt_wProtDftl;                                             */
/*  output uint16 CoPt_wMaxProtDftl;                                          */
/*  output uint16 CoPt_wSpcProtDftl;                                          */
/*  output uint16 CoPt_wMaxSpcProtDftl;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDeterminerEnergie(void)
{
   uint16 u16LocalCoPtProtDftl;
   uint32 u32LocalCoPtMaxSatProtDftl;
   uint32 u32LocalCoPMaxProtDftl;
   uint32 u32LocalCoPMaxSpcProtDftl;
   uint32 u32LocalCoPtSpcProtDftl;
   uint32 u32LocalCoPtProtDftl;
   sint32 s32LocalCoPtProtDftl;


   s32LocalCoPtProtDftl =
      (sint32)(CoPt_pwrProtDftl - (16 * CoPt_pwrColdProtDftl_C));
   CoPt_pwrProtDftl_MP =
      (uint16)MATHSRV_udtCLAMP(s32LocalCoPtProtDftl, 0, 1600);

   u32LocalCoPtProtDftl = (uint32)( PROTDFTLCLC_u16CoProtDftl
                                  + ((CoPt_pwrProtDftl_MP + 800) / 1600));
   u32LocalCoPtMaxSatProtDftl = (uint32)(CoPt_wMaxSatProtDftl_C * 2);
   u32LocalCoPtProtDftl =
      MATHSRV_udtMIN(u32LocalCoPtProtDftl, u32LocalCoPtMaxSatProtDftl);
   PROTDFTLCLC_u16CoProtDftl =
      (uint16)MATHSRV_udtMIN(u32LocalCoPtProtDftl, 65535);
   u32LocalCoPMaxProtDftl = (uint32)(CoPt_wMaxProtDftl_C * 2);
   u16LocalCoPtProtDftl =
      (uint16)MATHSRV_udtMIN(PROTDFTLCLC_u16CoProtDftl, u32LocalCoPMaxProtDftl);
   CoPt_wProtDftl = (uint16)MATHSRV_udtMIN(u16LocalCoPtProtDftl, 10000);

   CoPt_wMaxProtDftl = (uint16)MATHSRV_udtMIN(u32LocalCoPMaxProtDftl, 10000);

   u32LocalCoPtSpcProtDftl = (uint32)( CoPt_wSpcProtDftl
                                     + ((CoPt_pwrProtDftl_MP + 800) / 1600));
   u32LocalCoPMaxSpcProtDftl = (uint32)(CoPt_wMaxSpcProtDftl_C * 2);
   u32LocalCoPtSpcProtDftl =
      MATHSRV_udtMIN(u32LocalCoPtSpcProtDftl, u32LocalCoPMaxSpcProtDftl);
   CoPt_wSpcProtDftl = (uint16)MATHSRV_udtMIN(u32LocalCoPtSpcProtDftl, 10000);

   CoPt_wMaxSpcProtDftl =
      (uint16)MATHSRV_udtMIN(u32LocalCoPMaxSpcProtDftl, 10000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidEstimSollicit                               */
/* !Description :  Ce bloc calcule la sollicitation énergétique du            */
/*                 différentiel.                                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 CoPt_wSpcProtDftl;                                           */
/*  input uint16 CoPt_wMaxSpcProtDftl;                                        */
/*  input uint16 CoPt_wMaxProtDftl;                                           */
/*  input uint16 CoPt_wProtDftl;                                              */
/*  output uint8 CoPt_rEProtDftl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidEstimSollicit(void)
{
   uint32 u32LocalCoPt_rEProtDftl;


   if (CoPt_wSpcProtDftl == CoPt_wMaxSpcProtDftl)
   {
      CoPt_rEProtDftl = 128;
   }
   else
   {
      if (CoPt_wMaxProtDftl != 0)
      {
         u32LocalCoPt_rEProtDftl =
            (uint32)(((CoPt_wProtDftl * 128) + (CoPt_wMaxProtDftl / 2))
                    / CoPt_wMaxProtDftl);
         CoPt_rEProtDftl = (uint8)MATHSRV_udtMIN(u32LocalCoPt_rEProtDftl, 128);
      }
      else
      {
         CoPt_rEProtDftl = 128;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetActLimitCouple                           */
/* !Description :  Ce bloc détermine l’activation de la protection du         */
/*                 différentiel. La protection peut être inhibée par une      */
/*                 calibration.                                               */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 CoPt_nAcvProtDftl_C;                                         */
/*  input uint16 CoPt_nDeltaAcvProtDftl_C;                                    */
/*  input uint16 CoPt_nReWhlAvr;                                              */
/*  input boolean CoPt_bProtDftlAcv_C;                                        */
/*  input boolean PROTDFTLCLC_bOutHysNeg;                                     */
/*  output boolean PROTDFTLCLC_bOutHysNeg;                                    */
/*  output boolean CoPt_bProtDftlAcv;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetActLimitCouple(void)
{
   boolean bLocalDftSpdLeReWhl;
   boolean bLocalDftSpdRiReWhl;
   boolean bLocalDftSpdLeFrntWhl;
   boolean bLocalDftSpdRiFrntWhl;
   boolean bLocalSpdLeRiWhl;
   boolean bLocalSpdReFrntWhl;
   uint32  u32LocalAcvProtDftlHi;
   sint32  s32LocalAcvProtDftlLo;


   bLocalDftSpdLeReWhl = GDGAR_bGetFRM(FRM_FRM_DFTSPDLEREWHL);
   bLocalDftSpdRiReWhl = GDGAR_bGetFRM(FRM_FRM_DFTSPDRIREWHL);
   bLocalDftSpdLeFrntWhl = GDGAR_bGetFRM(FRM_FRM_DFTSPDLEFRNTWHL);
   bLocalDftSpdRiFrntWhl = GDGAR_bGetFRM(FRM_FRM_DFTSPDRIFRNTWHL);

   if (  (bLocalDftSpdLeReWhl != 0)
      && (bLocalDftSpdRiReWhl != 0))
   {
      bLocalSpdLeRiWhl = 1;
   }
   else
   {
      bLocalSpdLeRiWhl = 0;
   }

   if (  (bLocalSpdLeRiWhl == 0)
      && (bLocalDftSpdLeFrntWhl == 0)
      && (bLocalDftSpdRiFrntWhl == 0))
   {
      bLocalSpdReFrntWhl = 1;
   }
   else
   {
      bLocalSpdReFrntWhl = 0;
   }

   u32LocalAcvProtDftlHi =
      (uint32)((CoPt_nAcvProtDftl_C * 4) + CoPt_nDeltaAcvProtDftl_C);
   s32LocalAcvProtDftlLo =
      (sint32)((CoPt_nAcvProtDftl_C * 4) - CoPt_nDeltaAcvProtDftl_C);
   if (CoPt_nReWhlAvr >= u32LocalAcvProtDftlHi)
   {
      PROTDFTLCLC_bOutHysNeg = 0;
   }
   else
   {
      if (CoPt_nReWhlAvr <= s32LocalAcvProtDftlLo)
      {
         PROTDFTLCLC_bOutHysNeg = 1;
      }
   }

   if (  (bLocalSpdReFrntWhl != 0)
      && (CoPt_bProtDftlAcv_C != 0)
      && (PROTDFTLCLC_bOutHysNeg != 0))
   {
      CoPt_bProtDftlAcv = 1;
   }
   else
   {
      CoPt_bProtDftlAcv = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PROTDFTLCLC_vidDetCoupleProtDiff                           */
/* !Description :  Ce bloc détermine la limitation de couple applicable si la */
/*                 protection du différentiel est  activée. La fonction se    */
/*                 décompose en 2 blocs : Calcul de la limitation de couple à */
/*                 la roue, Calcul de la limitation de couple moteur.         */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_11_04686_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PROTDFTLCLC_vidDetCoupleLimitRou();                      */
/*  extf argret void PROTDFTLCLC_vidDetCoupleLimitMot();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PROTDFTLCLC_vidDetCoupleProtDiff(void)
{
   PROTDFTLCLC_vidDetCoupleLimitRou();
   PROTDFTLCLC_vidDetCoupleLimitMot();
}
/*---------------------------------end of file--------------------------------*/