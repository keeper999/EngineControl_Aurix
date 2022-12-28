/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRRATIO                                               */
/* !Description     : IUPRRATIO Component                                     */
/*                                                                            */
/* !Module          : IUPRRATIO                                               */
/* !Description     : IUPRRATIO CALCUL DES RATIOS IUPR                        */
/*                                                                            */
/* !File            : IUPRRATIO_fct1.c                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IUPRRATIO_vidInitOutput                                              */
/*   2 / IUPRRATIO_vidF02_CntNumDen                                           */
/*   3 / IUPRRATIO_vidF01_Ratio                                               */
/*   4 / IUPRRATIO_vidF01_CntNum                                              */
/*   5 / IUPRRATIO_vidF01_CntDen                                              */
/*   6 / IUPRRATIO_vidF01_DenNumCal                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5338298 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRRATIO/IUPRRATIO_fct1.c_v $*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   24 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "IUPRRATIO.h"
#include "IUPRRATIO_L.h"
#include "IUPRRATIO_im.h"
#include "MATHSRV.h"
#include "nvmsrv.h"
#include "std_limits.h"
#include "GD_api.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidInitOutput                                    */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 IUPR_idxDftRat_C[100];                                       */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*  output uint16 IUPR_ctDenGrpRat[12];                                       */
/*  output uint16 IUPR_ctNumGrpRat[12];                                       */
/*  output boolean IUPRRATIO_DenChoicePrev[100];                              */
/*  output boolean IUPRRATIO_abDcPrev[100];                                   */
/*  output uint16 u16MinRatioIdx;                                             */
/*  output boolean IUPRRATIO_bRstPrm_prev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidInitOutput(void)
{
   boolean bLocalDc;
   uint8   u8LocalDivision;
   uint8   u8LocalRatio;
   uint16  u16LocalDftRat;
   sint32  s32LocalIndex;


   for (s32LocalIndex = 0 ; s32LocalIndex < MAX_GRP_RAT;  s32LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(IUPR_ctDenGrpRat, s32LocalIndex, 0);
      VEMS_vidSET1DArrayElement(IUPR_ctNumGrpRat, s32LocalIndex, 0);
   }
   for (s32LocalIndex = 0 ; s32LocalIndex < IUPR_NB_RAT;  s32LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(IUPRRATIO_DenChoicePrev, s32LocalIndex,
                              0);
      u16LocalDftRat = IUPR_idxDftRat_C[s32LocalIndex];
      u8LocalDivision = (uint8)(u16LocalDftRat / 8);
      u8LocalRatio = (uint8)(u16LocalDftRat % 8);

      bLocalDc = GD_bBitRead(DC_au8DC_EEPROM[u8LocalDivision], u8LocalRatio);
      VEMS_vidSET1DArrayElement(IUPRRATIO_abDcPrev, s32LocalIndex, bLocalDc);
   }
   u16MinRatioIdx = 0;
   IUPRRATIO_bRstPrm_prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidF02_CntNumDen                                 */
/* !Description :  Cette fonction comprend une sous-fonction                  */
/*                 F01_IUPR_EnaGrpRat dans laquelle sont calculés les ratios  */
/*                 des défauts unitaires ainsi que les Numérateurs et         */
/*                 Dénominateurs des Groupes Ratios. Ces variables peuvent    */
/*                 être réinitialisés à 0 par calibration (IUPR_bRs           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IUPRRATIO_vidF01_Ratio(argin uint16 u16IdxIupr, argin    */
/* uint16 u16IdxDft);                                                         */
/*  extf argret void IUPRRATIO_vidF01_DenNumCal(uint16 u16IdxDft, uint8       */
/* u8IdxGrpRat);                                                              */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input boolean Iupr_bFrzGenDen;                                            */
/*  input uint8 IUPR_idxGrpRat_C[100];                                        */
/*  input boolean IUPRRATIO_bFirstUse;                                        */
/*  input uint16 IUPR_idxDftRat_C[100];                                       */
/*  input boolean IUPR_bRstPrm_C;                                             */
/*  input boolean IUPRRATIO_bRstPrm_prev;                                     */
/*  output boolean IUPRRATIO_bFirstUse;                                       */
/*  output uint16 u16MinRatioIdx;                                             */
/*  output uint16 IUPR_ctDenRat[100];                                         */
/*  output uint16 IUPR_ctNumRat[100];                                         */
/*  output uint16 IUPR_ctNumGrpRat[12];                                       */
/*  output uint16 IUPR_ctDenGrpRat[12];                                       */
/*  output boolean IUPRRATIO_bRstPrm_prev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidF02_CntNumDen(void)
{
   boolean bLocalIupr_bFrzGenDen;
   sint32  s32LocalIdx;
   sint32  s32LocalIdxGrpRat;
   sint32  s32LocalIUPR;
   sint32  s32LocalIdx2;


   VEMS_vidGET(Iupr_bFrzGenDen, bLocalIupr_bFrzGenDen);
   if (bLocalIupr_bFrzGenDen != 1)
   {
      /* IUPRRATIO_vidF01_EnaGrpRat */
      for (s32LocalIdxGrpRat = 0;
           s32LocalIdxGrpRat < MAX_GRP_RAT;
           s32LocalIdxGrpRat++)
      {
         IUPRRATIO_bFirstUse = 1;
         for(s32LocalIUPR = 0 ; s32LocalIUPR < IUPR_NB_RAT ; s32LocalIUPR++)
         {
            if (IUPR_idxGrpRat_C[s32LocalIUPR] ==
                  (uint8)s32LocalIdxGrpRat)
            {
               if (IUPRRATIO_bFirstUse == 1)
               {
                  u16MinRatioIdx = (uint16)s32LocalIUPR;
                  IUPRRATIO_bFirstUse = 0;
               }

               IUPRRATIO_vidF01_Ratio((uint16)s32LocalIUPR,
                                      IUPR_idxDftRat_C[s32LocalIUPR]);
               IUPRRATIO_vidF01_DenNumCal((uint16)s32LocalIUPR,
                                        IUPR_idxGrpRat_C[s32LocalIUPR]);
            }
         }
         if (s32LocalIdxGrpRat == 1)
         {
            s32LocalIdxGrpRat = (sint32)(s32LocalIdxGrpRat + 4);
            /*QAC Warning : Msg(2:2469); code must respect the specification*/
         }
         else if (s32LocalIdxGrpRat == 6)
         {
            s32LocalIdxGrpRat = (sint32)(s32LocalIdxGrpRat + 1);
            /*QAC Warning : Msg(2:2469); code must respect the specification*/
         }
         else
         {
         }
      }
   }

   if((IUPR_bRstPrm_C == 1) &&
      (IUPRRATIO_bRstPrm_prev == 0))
   {
      for(s32LocalIdx = 0 ; s32LocalIdx < IUPR_NB_RAT ; s32LocalIdx++)
      {
         VEMS_vidSET1DArrayElement(IUPR_ctDenRat,s32LocalIdx,0);
         VEMS_vidSET1DArrayElement(IUPR_ctNumRat,s32LocalIdx,0);
      }

      for(s32LocalIdx2 = 0 ; s32LocalIdx2 < MAX_GRP_RAT ; s32LocalIdx2++)
      {
         VEMS_vidSET1DArrayElement(IUPR_ctNumGrpRat,s32LocalIdx2,0);
         VEMS_vidSET1DArrayElement(IUPR_ctDenGrpRat,s32LocalIdx2,0);
      }
   }

   IUPRRATIO_bRstPrm_prev = IUPR_bRstPrm_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidF01_Ratio                                     */
/* !Description :  F01 est activée à chaque début de DC appliqué du défaut    */
/*                 concerné (DC_bTypCc_NameVar), et F02 à chaque fois que les */
/*                 conditions du roulage ont répondue aux critères définis    */
/*                 dans la note spécifiant le calcul du Dénominateur Général  */
/*                 (Iupr_gen_denom_ok).                                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void IUPRRATIO_vidF01_CntNum(uint16 u16IdxDft);               */
/*  extf argret void IUPRRATIO_vidF01_CntDen(uint16 u16IdxDft);               */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*  input uint8 Iupr_DenChoiceRat_C[100];                                     */
/*  input uint8 u8Iupr_xxx_denom_ok;                                          */
/*  input boolean Iupr_bFrzRat[100];                                          */
/*  input uint16 IUPR_idxDftRat_C[100];                                       */
/*  input boolean IUPRRATIO_abDcPrev[100];                                    */
/*  input boolean IUPRRATIO_DenChoicePrev[100];                               */
/*  input uint16 IUPR_ctDenRat[100];                                          */
/*  input uint16 IUPR_ctNumRat[100];                                          */
/*  output uint16 IUPR_noRatio[100];                                          */
/*  output boolean IUPRRATIO_abDcPrev[100];                                   */
/*  output boolean IUPRRATIO_DenChoicePrev[100];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidF01_Ratio
(
   uint16 u16IdxIupr,
   uint16 u16IdxDft
)
{
   boolean bLocalDc;
   boolean bLocalIupr_bFrzRat;
   boolean bLocalDenChoice;
   uint8   u8LocalDivision;
   uint8   u8LocalRatio;
   uint16  u16LocalIUPR_idxDft;
   uint16  u16LocalDen;
   uint16  u16LocalNum;
   uint32  u32LocalnoRatio;


   u8LocalDivision = (uint8)(u16IdxDft / 8);
   u8LocalRatio = (uint8)(u16IdxDft % 8);

   bLocalDc = GD_bBitRead(DC_au8DC_EEPROM[u8LocalDivision], u8LocalRatio);

   if(Iupr_DenChoiceRat_C[u16IdxIupr] < IUPR_NB_DENOM_USED)
   {
      bLocalDenChoice = GD_bBitRead(u8Iupr_xxx_denom_ok,
                                    Iupr_DenChoiceRat_C[u16IdxIupr]);
   }
   else
   {
      bLocalDenChoice = GD_bBitRead(u8Iupr_xxx_denom_ok,
                                    DEF_IUPR_GEN_DENOM_OK);
      SWFAIL_vidSoftwareErrorHook();
   }

   VEMS_vidGET1DArrayElement(Iupr_bFrzRat, u16IdxIupr, bLocalIupr_bFrzRat);
   u16LocalIUPR_idxDft = IUPR_idxDftRat_C[u16IdxIupr];

   if (bLocalIupr_bFrzRat == 0)
   {
      if (u16LocalIUPR_idxDft != 65535)
      {
         if (  (bLocalDc == 1)
            && (IUPRRATIO_abDcPrev[u16IdxIupr] == 0))
         {
            IUPRRATIO_vidF01_CntNum(u16IdxIupr);
         }
         else
         {
            if (  (bLocalDenChoice == 1)
               && (IUPRRATIO_DenChoicePrev[u16IdxIupr] == 0))
            {
               IUPRRATIO_vidF01_CntDen(u16IdxIupr);
            }
         }
      }
   }

   VEMS_vidGET1DArrayElement(IUPR_ctDenRat, u16IdxIupr, u16LocalDen);

   if (u16LocalDen > 0)
   {
      VEMS_vidGET1DArrayElement(IUPR_ctNumRat,u16IdxIupr,u16LocalNum);
      u32LocalnoRatio = u16LocalNum * 8192;
      u32LocalnoRatio = u32LocalnoRatio / u16LocalDen;
      IUPR_noRatio[u16IdxIupr] = (uint16)MATHSRV_udtMIN(u32LocalnoRatio, 65535);
   }
   else
   {
      IUPR_noRatio[u16IdxIupr] = (uint16)(UINT16_MAX);
   }

   IUPRRATIO_abDcPrev[u16IdxIupr] = bLocalDc;
   IUPRRATIO_DenChoicePrev[u16IdxIupr] = bLocalDenChoice;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidF01_CntNum                                    */
/* !Description :  Cette fonction gère le calcul du numérateur du ratio du    */
/*                 défaut unitaire. A chaque début de DC appliqué du défaut   */
/*                 unitaire, le numérateur, s’il n’est pas égal à sa valeur   */
/*                 maxi 65535, est incrémenté d’une unité. Lorsqu’il a atteint*/
/*                 65535, et qu’un nouveau D                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 IUPR_ctNumRat[100];                                          */
/*  input uint16 IUPR_ctDenRat[100];                                          */
/*  output uint16 IUPR_ctDenRat[100];                                         */
/*  output uint16 IUPR_ctNumRat[100];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidF01_CntNum
(
   uint16 u16IdxDft
)
{
   uint16 u16LocalNum;
   uint16 u16LocalDen;

   VEMS_vidGET1DArrayElement(IUPR_ctNumRat,u16IdxDft,u16LocalNum);
   if(u16LocalNum == (uint16)(UINT16_MAX))
   {
      VEMS_vidGET1DArrayElement(IUPR_ctDenRat,u16IdxDft,u16LocalDen);

      u16LocalDen = (uint16)(u16LocalDen / 2);

      VEMS_vidSET1DArrayElement(IUPR_ctDenRat,u16IdxDft,u16LocalDen);
      VEMS_vidSET1DArrayElement(IUPR_ctNumRat,u16IdxDft,UINT16_MAX_HALF);
   }
   else
   {
      u16LocalNum = (uint16)(u16LocalNum + 1);
      VEMS_vidSET1DArrayElement(IUPR_ctNumRat,u16IdxDft,u16LocalNum);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidF01_CntDen                                    */
/* !Description :  Cette fonction gère le calcul du dénominateur du ratio du  */
/*                 défaut unitaire. A chaque fois que les conditions du       */
/*                 roulage ont répondue aux critères définis dans la note     */
/*                 spécifiant le calcul du Dénominateur Général               */
/*                 (Iupr_gen_denom_ok), le dénominateur, s’il n               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 IUPR_ctDenRat[100];                                          */
/*  input uint16 IUPR_ctNumRat[100];                                          */
/*  output uint16 IUPR_ctNumRat[100];                                         */
/*  output uint16 IUPR_ctDenRat[100];                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidF01_CntDen
(
   uint16 u16IdxDft
)
{
   uint16 u16LocalNum;
   uint16 u16LocalDen;

   VEMS_vidGET1DArrayElement(IUPR_ctDenRat,u16IdxDft,u16LocalDen);
   if(u16LocalDen == (uint16)(UINT16_MAX))
   {
      VEMS_vidGET1DArrayElement(IUPR_ctNumRat,u16IdxDft,u16LocalNum);

      u16LocalNum = (uint16)(u16LocalNum / 2);

      VEMS_vidSET1DArrayElement(IUPR_ctNumRat,u16IdxDft,u16LocalNum);
      VEMS_vidSET1DArrayElement(IUPR_ctDenRat,u16IdxDft,UINT16_MAX_HALF);
   }
   else
   {
      u16LocalDen++;
      VEMS_vidSET1DArrayElement(IUPR_ctDenRat,u16IdxDft,u16LocalDen);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRRATIO_vidF01_DenNumCal                                 */
/* !Description :  M-fonction pour le calcul des Dénominateurs et Numérateurs */
/*                 des Groupes Ratios                                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 IUPR_noRatio[100];                                           */
/*  input uint16 IUPR_ctNumRat[100];                                          */
/*  input uint16 u16MinRatioIdx;                                              */
/*  input uint16 IUPR_ctDenRat[100];                                          */
/*  output uint16 u16MinRatioIdx;                                             */
/*  output uint16 IUPR_ctNumGrpRat[12];                                       */
/*  output uint16 IUPR_ctDenGrpRat[12];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRRATIO_vidF01_DenNumCal
(
   uint16 u16IdxDft,
   uint8 u8IdxGrpRat
)
{
   uint16 u16LocalMinRatio;
   uint16 u16LocalRatio;
   uint16 u16LocalMinRatioNum;
   uint16 u16LocalRatioNum;
   uint16 u16LocalRatioDen;


   u16LocalMinRatio = IUPR_noRatio[u16MinRatioIdx];
   u16LocalRatio = IUPR_noRatio[u16IdxDft];

   if(u16LocalRatio < u16LocalMinRatio)
   {
      u16MinRatioIdx = u16IdxDft;
   }
   else
   {
      VEMS_vidGET1DArrayElement(IUPR_ctNumRat,u16MinRatioIdx,
                                    u16LocalMinRatioNum);
      VEMS_vidGET1DArrayElement(IUPR_ctNumRat,u16IdxDft,u16LocalRatioNum);

      if(u16LocalMinRatio == u16LocalRatio)
      {
         if(u16LocalRatioNum > u16LocalMinRatioNum)
         {
            u16MinRatioIdx = u16IdxDft;
         }
      }
   }

   VEMS_vidGET1DArrayElement(IUPR_ctNumRat,u16MinRatioIdx,u16LocalMinRatioNum);
   VEMS_vidGET1DArrayElement(IUPR_ctDenRat,u16MinRatioIdx,u16LocalRatioDen);
   VEMS_vidSET1DArrayElement(IUPR_ctNumGrpRat,u8IdxGrpRat,u16LocalMinRatioNum);
   VEMS_vidSET1DArrayElement(IUPR_ctDenGrpRat,u8IdxGrpRat,u16LocalRatioDen);
}
/* --------------------------------end of file------------------------------- */