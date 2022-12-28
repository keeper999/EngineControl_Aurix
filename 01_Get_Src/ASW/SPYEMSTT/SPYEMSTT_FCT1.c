/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPYEMSTT                                                */
/* !Description     : SPYEMSTT Component                                      */
/*                                                                            */
/* !Module          : SPYEMSTT                                                */
/* !Description     : Espionner le SEEM STT : SpyEmSTT                        */
/*                                                                            */
/* !File            : SPYEMSTT_FCT1.C                                         */
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
/*   1 / SPYEMSTT_vidInitOutput                                               */
/*   2 / SPYEMSTT_vidInitialization                                           */
/*   3 / SPYEMSTT_vidRecNotStopCase                                           */
/*   4 / SPYEMSTT_vidRecNotStopCase1                                          */
/*   5 / SPYEMSTT_vidRecHisNotStopCase                                        */
/*   6 / SPYEMSTT_NVMSRV_vidInit                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 05852 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SPYEMSTT/SPYEMSTT_FCT1.C_v        $*/
/* $Revision::   1.2      $$Author::   ACHEBINO       $$Date::   04 Oct 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   04 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SPYEMSTT.h"
#include "SPYEMSTT_L.h"
#include "SPYEMSTT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYEMSTT_vidInitOutput                                     */
/* !Description :  Initialisation des variables produites du module SPYEMSTT  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  W.LASSOUED                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean SPYEMSTT_bHisDstWin1_Prev;                                 */
/*  output boolean SPYEMSTT_bRecNotStop_Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYEMSTT_vidInitOutput(void)
{
   SPYEMSTT_bHisDstWin1_Prev = 0;
   SPYEMSTT_bRecNotStop_Prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYEMSTT_vidInitialization                                 */
/* !Description :  En sortie d’usine (équivalent à la 1ère initialisation du  */
/*                 CMM), les vecteurs de la pile sont initialisés avec des    */
/*                 valeurs nulles.                                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint32 SpyEmSTT_prmHisDstWin1[2];                                   */
/*  input uint8 SpyEmSTT_noDstWin_C;                                          */
/*  output uint8 SpyEmSTT_stNotStopCase;                                      */
/*  output sint32 SpyEmSTT_prmHisDstWin2[2];                                  */
/*  output sint32 SpyEmSTT_prmHisDstWin3[2];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYEMSTT_vidInitialization(void)
{
   uint8   u8LocalIndex;
   uint32  u32LocalSpyEmSTT_prmHisDstWin1;
   sint32  s32LocalTemp;
   sint32  s32LocalSpyEmSTT_prmHisDstWin2;
   sint32  s32LocalSpyEmSTT_prmHisDstWin3;


   VEMS_vidSET(SpyEmSTT_stNotStopCase, 0);

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYEMSTT_u8ARRAY_LENGTH2;
        u8LocalIndex ++)
   {
      VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin1,
                                u8LocalIndex,
                                u32LocalSpyEmSTT_prmHisDstWin1);

      s32LocalTemp = MATHSRV_s32Sub_u32_u32(u32LocalSpyEmSTT_prmHisDstWin1,
                                            (uint32)SpyEmSTT_noDstWin_C);
      s32LocalSpyEmSTT_prmHisDstWin2 =
         MATHSRV_udtCLAMP(s32LocalTemp, -200, 16777214);
      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin2,
                                u8LocalIndex,
                                s32LocalSpyEmSTT_prmHisDstWin2);

      s32LocalSpyEmSTT_prmHisDstWin3 =
         MATHSRV_s32Sub_s32_u32(s32LocalTemp, (uint32)SpyEmSTT_noDstWin_C);

      s32LocalSpyEmSTT_prmHisDstWin3 =
         MATHSRV_udtCLAMP(s32LocalSpyEmSTT_prmHisDstWin3, -400, 16777214);
      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin3,
                                u8LocalIndex,
                                s32LocalSpyEmSTT_prmHisDstWin3);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYEMSTT_vidRecNotStopCase                                 */
/* !Description :  Causes de non arrêt dues au SEEM.                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SPYEMSTT_vidRecNotStopCase1();                           */
/*  extf argret void SPYEMSTT_vidRecHisNotStopCase();                         */
/*  input uint32 Ext_dstVehTotMes;                                            */
/*  input boolean CoPtUH_bRecNotStop;                                         */
/*  input uint32 SpyEmSTT_prmHisDstWin1[2];                                   */
/*  input boolean SPYEMSTT_bRecNotStop_Prev;                                  */
/*  input boolean SPYEMSTT_bHisDstWin1_Prev;                                  */
/*  output boolean SPYEMSTT_bRecNotStop_Prev;                                 */
/*  output boolean SPYEMSTT_bHisDstWin1_Prev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYEMSTT_vidRecNotStopCase(void)
{
   boolean bLocalCoPtUH_bRecNotStop;
   boolean bLocalCondition;
   uint32  u32LocalExt_dstVehTotMes;
   uint32  u32LocalprmHisWin1_2;


   VEMS_vidGET(Ext_dstVehTotMes, u32LocalExt_dstVehTotMes);
   VEMS_vidGET(CoPtUH_bRecNotStop, bLocalCoPtUH_bRecNotStop);
   VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin1, 1, u32LocalprmHisWin1_2);
   if (u32LocalExt_dstVehTotMes >= u32LocalprmHisWin1_2)
   {
      bLocalCondition = 1;
   }
   else
   {
      bLocalCondition = 0;
   }
   if (  (bLocalCoPtUH_bRecNotStop != 0)
      && (SPYEMSTT_bRecNotStop_Prev == 0))
   {
      SPYEMSTT_vidRecNotStopCase1();
   }
   if ( (bLocalCondition != 0)
      &&(SPYEMSTT_bHisDstWin1_Prev == 0))
   {
      SPYEMSTT_vidRecHisNotStopCase();
   }
   SPYEMSTT_bRecNotStop_Prev = bLocalCoPtUH_bRecNotStop;
   SPYEMSTT_bHisDstWin1_Prev = bLocalCondition;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYEMSTT_vidRecNotStopCase1                                */
/* !Description :  Les 7 valeurs de ce vecteur sont booléennes et chacune     */
/*                 correspond à une cause de non arrêt. L’ordre des causes de */
/*                 non arrêt doit être respecté, c’est-à-dire que la nième    */
/*                 valeur du vecteur doit correspondre à la nième cause       */
/*                 listée.                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input boolean CoEmSTT_bBattProt;                                          */
/*  input boolean CoEmSTT_bBattPrf;                                           */
/*  input boolean CoEmSTT_bBattUncrtSoC;                                      */
/*  input boolean CoEmSTT_bRvAltCritT;                                        */
/*  input boolean CoEmSTT_bStaProt;                                           */
/*  input boolean CoEmSTT_bUcapUndVolt;                                       */
/*  input boolean CoEmSTT_bVSSCtzCrit;                                        */
/*  input uint8 SpyEmSTT_noDstWin_C;                                          */
/*  input uint8 SpyEmSTT_prmHistNotStopCase1[7];                              */
/*  output uint8 SpyEmSTT_stNotStopCase;                                      */
/*  output uint8 SpyEmSTT_prmHistNotStopCase1[7];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYEMSTT_vidRecNotStopCase1(void)
{
   boolean bLocalCoEmSTT_bBattProt;
   boolean bLocalCoEmSTT_bBattPrf;
   boolean bLocalCoEmSTT_bBattUncrtSoC;
   boolean bLocalCoEmSTT_bRvAltCritT;
   boolean bLocalCoEmSTT_bStaProt;
   boolean bLocalCoEmSTT_bUcapUndVolt;
   boolean bLocalCoEmSTT_bVSSCtzCrit;
   uint8   u8LocalSpyEmSTT_stNotStopCase;
   uint8   u8LocalMin;
   uint8   u8LocalIndex;
   uint8   u8LocalSpyEmSTT_prmHisNotStpCas1[SPYEMSTT_u8ARRAY_LENGTH7];
   uint8   bLocalArrayTemp[SPYEMSTT_u8ARRAY_LENGTH7];
   uint16  u16LocalArrayMin1[SPYEMSTT_u8ARRAY_LENGTH7];


   VEMS_vidGET(CoEmSTT_bBattProt, bLocalCoEmSTT_bBattProt);
   VEMS_vidGET(CoEmSTT_bBattPrf, bLocalCoEmSTT_bBattPrf);
   VEMS_vidGET(CoEmSTT_bBattUncrtSoC, bLocalCoEmSTT_bBattUncrtSoC);
   VEMS_vidGET(CoEmSTT_bRvAltCritT, bLocalCoEmSTT_bRvAltCritT);
   VEMS_vidGET(CoEmSTT_bStaProt, bLocalCoEmSTT_bStaProt);
   VEMS_vidGET(CoEmSTT_bUcapUndVolt, bLocalCoEmSTT_bUcapUndVolt);
   VEMS_vidGET(CoEmSTT_bVSSCtzCrit, bLocalCoEmSTT_bVSSCtzCrit);

   u8LocalSpyEmSTT_stNotStopCase = (uint8)( bLocalCoEmSTT_bBattPrf
                                          + (bLocalCoEmSTT_bBattProt << 1)
                                          + (bLocalCoEmSTT_bBattUncrtSoC << 2)
                                          + (bLocalCoEmSTT_bRvAltCritT << 3)
                                          + (bLocalCoEmSTT_bUcapUndVolt << 4)
                                          + (bLocalCoEmSTT_bVSSCtzCrit << 5)
                                          + (bLocalCoEmSTT_bStaProt << 6));
   VEMS_vidSET(SpyEmSTT_stNotStopCase, u8LocalSpyEmSTT_stNotStopCase);

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYEMSTT_u8ARRAY_LENGTH7;
        u8LocalIndex ++)
   {
      bLocalArrayTemp[u8LocalIndex] = 0;
   }
   bLocalArrayTemp[0] = bLocalCoEmSTT_bBattPrf;
   bLocalArrayTemp[1] = bLocalCoEmSTT_bBattProt;
   bLocalArrayTemp[2] = bLocalCoEmSTT_bBattUncrtSoC;
   bLocalArrayTemp[3] = bLocalCoEmSTT_bRvAltCritT;
   bLocalArrayTemp[4] = bLocalCoEmSTT_bUcapUndVolt;
   bLocalArrayTemp[5] = bLocalCoEmSTT_bVSSCtzCrit;
   bLocalArrayTemp[6] = bLocalCoEmSTT_bStaProt;

   if (SpyEmSTT_noDstWin_C > 100)
   {
      u8LocalMin = 32;
   }
   else
   {
      u8LocalMin = 16;
   }
   VEMS_vidGET1DArray(SpyEmSTT_prmHistNotStopCase1,
                      SPYEMSTT_u8ARRAY_LENGTH7,
                      u8LocalSpyEmSTT_prmHisNotStpCas1);

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYEMSTT_u8ARRAY_LENGTH7;
        u8LocalIndex ++)
   {
      if (bLocalArrayTemp[u8LocalIndex] != 0)
      {
         u16LocalArrayMin1[u8LocalIndex] =
            (uint16)(u8LocalSpyEmSTT_prmHisNotStpCas1[u8LocalIndex] + 1);
      }
      else
      {
         u16LocalArrayMin1[u8LocalIndex] =
            u8LocalSpyEmSTT_prmHisNotStpCas1[u8LocalIndex];
      }
      u8LocalSpyEmSTT_prmHisNotStpCas1[u8LocalIndex] =
         (uint8)MATHSRV_udtMIN(u16LocalArrayMin1[u8LocalIndex], u8LocalMin);
   }
   VEMS_vidSET1DArray(SpyEmSTT_prmHistNotStopCase1,
                      SPYEMSTT_u8ARRAY_LENGTH7,
                      u8LocalSpyEmSTT_prmHisNotStpCas1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYEMSTT_vidRecHisNotStopCase                              */
/* !Description :  Quand le kilométrage dépasse la valeur calibrée, le 3eme   */
/*                 vecteur est effacé, le 2eme est enregistré dans le 3eme, et*/
/*                 le 1er vecteur est enregistré dans le 2eme. Le 1er vecteur */
/*                 est remis à 0, et compte les causes de non arrêt           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 SpyEmSTT_prmHistNotStopCase1[7];                              */
/*  input uint8 SpyEmSTT_prmHistNotStopCase2[7];                              */
/*  input uint32 SpyEmSTT_prmHisDstWin1[2];                                   */
/*  input sint32 SpyEmSTT_prmHisDstWin2[2];                                   */
/*  input uint8 SpyEmSTT_noDstWin_C;                                          */
/*  output uint8 SpyEmSTT_prmHistNotStopCase3[7];                             */
/*  output uint8 SpyEmSTT_prmHistNotStopCase2[7];                             */
/*  output uint8 SpyEmSTT_prmHistNotStopCase1[7];                             */
/*  output uint32 SpyEmSTT_prmHisDstWin1[2];                                  */
/*  output sint32 SpyEmSTT_prmHisDstWin2[2];                                  */
/*  output sint32 SpyEmSTT_prmHisDstWin3[2];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYEMSTT_vidRecHisNotStopCase(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalSpyEmSTT_prmHistNStopC2;
   uint8  u8LocalSpyEmSTT_prmHistNStopC1;
   uint32 u32LocalSpyEmSTT_prmHisDstWin1;
   sint32 s32LocalSpyEmSTT_prmHisDstWin2;
   sint32 s32LocalSpyEmSTT_prmHisDstWin3;


   for (u8LocalIndex = 0;
        u8LocalIndex < SPYEMSTT_u8ARRAY_LENGTH7;
        u8LocalIndex ++)
   {
      VEMS_vidGET1DArrayElement(SpyEmSTT_prmHistNotStopCase1,
                                u8LocalIndex,
                                u8LocalSpyEmSTT_prmHistNStopC1);
      VEMS_vidGET1DArrayElement(SpyEmSTT_prmHistNotStopCase2,
                                u8LocalIndex,
                                u8LocalSpyEmSTT_prmHistNStopC2);

      u8LocalSpyEmSTT_prmHistNStopC2 =
         (uint8)MATHSRV_udtMIN(u8LocalSpyEmSTT_prmHistNStopC2, 32);

      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHistNotStopCase3,
                                u8LocalIndex,
                                u8LocalSpyEmSTT_prmHistNStopC2);
      u8LocalSpyEmSTT_prmHistNStopC1 =
         (uint8)MATHSRV_udtMIN(u8LocalSpyEmSTT_prmHistNStopC1, 32);

      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHistNotStopCase2,
                                u8LocalIndex,
                                u8LocalSpyEmSTT_prmHistNStopC1);

      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHistNotStopCase1, u8LocalIndex, 0);
   }

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYEMSTT_u8ARRAY_LENGTH2;
        u8LocalIndex ++)
   {
      VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin1,
                                u8LocalIndex,
                                u32LocalSpyEmSTT_prmHisDstWin1);
      VEMS_vidGET1DArrayElement(SpyEmSTT_prmHisDstWin2,
                                u8LocalIndex,
                                s32LocalSpyEmSTT_prmHisDstWin2);

      s32LocalSpyEmSTT_prmHisDstWin3 =
         MATHSRV_udtCLAMP(s32LocalSpyEmSTT_prmHisDstWin2, -400, 16777214);

      s32LocalSpyEmSTT_prmHisDstWin2 =
         (sint32)MATHSRV_udtMIN(u32LocalSpyEmSTT_prmHisDstWin1, 16777214);

      u32LocalSpyEmSTT_prmHisDstWin1 =
         MATHSRV_u32Add_u32_u32(u32LocalSpyEmSTT_prmHisDstWin1,
                                (uint32)SpyEmSTT_noDstWin_C);
      u32LocalSpyEmSTT_prmHisDstWin1 =
         MATHSRV_udtMIN(u32LocalSpyEmSTT_prmHisDstWin1, 16777214);

      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin1,
                                u8LocalIndex,
                                u32LocalSpyEmSTT_prmHisDstWin1);

      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin2,
                                u8LocalIndex,
                                s32LocalSpyEmSTT_prmHisDstWin2);

      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin3,
                                u8LocalIndex,
                                s32LocalSpyEmSTT_prmHisDstWin3);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYEMSTT_NVMSRV_vidInit                                    */
/* !Description :  Valeurs par defaut des variables EEPROM.                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  W.LASSOUED                                                 */
/* !Trace_To    :  VEMS_R_10_05852_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint8 SpyEmSTT_prmHistNotStopCase1[7];                             */
/*  output uint8 SpyEmSTT_prmHistNotStopCase2[7];                             */
/*  output uint8 SpyEmSTT_prmHistNotStopCase3[7];                             */
/*  output uint32 SpyEmSTT_prmHisDstWin1[2];                                  */
/*  output uint8 SpyEmSTT_noDstWin_C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYEMSTT_NVMSRV_vidInit(void)
{
   uint8   u8LocalIndex;


   for (u8LocalIndex = 0 ;
        u8LocalIndex < SPYEMSTT_u8ARRAY_LENGTH7 ;
        u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHistNotStopCase1,
                                u8LocalIndex,
                                0);
      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHistNotStopCase2,
                                u8LocalIndex,
                                0);
      VEMS_vidSET1DArrayElement(SpyEmSTT_prmHistNotStopCase3,
                                u8LocalIndex,
                                0);
   }
   VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin1, 0, 0);
   VEMS_vidSET1DArrayElement(SpyEmSTT_prmHisDstWin1, 1, SpyEmSTT_noDstWin_C);
}
/*-------------------------------- end of file -------------------------------*/