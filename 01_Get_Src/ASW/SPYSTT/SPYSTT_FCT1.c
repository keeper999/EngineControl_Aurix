/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SPYSTT                                                  */
/* !Description     : SPYSTT component.                                       */
/*                                                                            */
/* !Module          : SPYSTT                                                  */
/* !Description     : SPY STT                                                 */
/*                                                                            */
/* !File            : SPYSTT_FCT1.C                                           */
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
/*   1 / SPYSTT_vidInitOutput                                                 */
/*   2 / SPYSTT_vidRecNotStopCase                                             */
/*   3 / SPYSTT_vidRecNotStopCase1                                            */
/*   4 / SPYSTT_vidRecHisNotStopCase                                          */
/*   5 / SPYSTT_vidCutCasRstFaiRec                                            */
/*   6 / SPYSTT_vidCutCaseRec                                                 */
/*   7 / SPYSTT_vidRstrtFaiRec                                                */
/*   8 / SPYSTT_NVMSRV_vidInit                                                */
/*                                                                            */
/* !Reference   : V02 NT 10 02508 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/SPYSTT/SPYSTT_FCT1.C_v            $*/
/* $Revision::   1.4      $$Author::   ACHEBINO       $$Date::   30 Sep 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   30 Sep 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SPYSTT.h"
#include "SPYSTT_L.h"
#include "SPYSTT_IM.h"
#include "GDGAR.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidInitOutput                                       */
/* !Description :  fonction d'initialisation des outputs                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint32 SpySTT_prmHisDstWin1[2];                                     */
/*  input uint8 SpySTT_noDstWin_C;                                            */
/*  output uint8 SpySTT_stCutCaseCur;                                         */
/*  output uint16 SpySTT_stNotStopCase;                                       */
/*  output uint32 SpySTT_prmHisDstWin1[2];                                    */
/*  output uint32 SpySTT_prmHisDstWin2[2];                                    */
/*  output uint32 SpySTT_prmHisDstWin3[2];                                    */
/*  output uint8 SPYSTT_u8CoPtUH_stPwt_Prev;                                  */
/*  output boolean SPYSTT_bRecNotStop_Prev;                                   */
/*  output boolean SPYSTT_bRecHisNotStopCase_Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidInitOutput(void)
{
   uint8  u8LocalIdx;
   uint32 u32LocalprmHisWin1[SPYSTT_U8PRMHISDSTWIN_LENGTH];
   uint32 u32LocalprmHisWin2[SPYSTT_U8PRMHISDSTWIN_LENGTH];
   uint32 u32LocalprmHisWin3[SPYSTT_U8PRMHISDSTWIN_LENGTH];
   sint32 s32LocalprmHisWin;


   u32LocalprmHisWin1[0] = 0;
   SpySTT_stCutCaseCur = 0;
   VEMS_vidSET(SpySTT_stNotStopCase, 0);

   for (u8LocalIdx = 0;
        u8LocalIdx < SPYSTT_U8PRMHISDSTWIN_LENGTH;
        u8LocalIdx ++)
   {
      VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin1,
                                u8LocalIdx,
                                u32LocalprmHisWin1[u8LocalIdx]);
      u32LocalprmHisWin1[u8LocalIdx] =
         MATHSRV_udtMIN(u32LocalprmHisWin1[u8LocalIdx], 500000);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin1,
                                u8LocalIdx,
                                u32LocalprmHisWin1[u8LocalIdx]);
      s32LocalprmHisWin = (sint32)( (u32LocalprmHisWin1[u8LocalIdx]
                                  - SpySTT_noDstWin_C)
                                  + 200);
      u32LocalprmHisWin2[u8LocalIdx] = (uint32)MATHSRV_udtMAX(s32LocalprmHisWin,
                                                              0);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin2,
                                u8LocalIdx,
                                u32LocalprmHisWin2[u8LocalIdx]);
      s32LocalprmHisWin = (sint32)( (u32LocalprmHisWin2[u8LocalIdx]
                                  - SpySTT_noDstWin_C)
                                  + 200);
      u32LocalprmHisWin3[u8LocalIdx] = (uint32)MATHSRV_udtMAX(s32LocalprmHisWin,
                                                              0);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin3,
                                u8LocalIdx,
                                u32LocalprmHisWin3[u8LocalIdx]);
   }

   SPYSTT_u8CoPtUH_stPwt_Prev = 1;
   SPYSTT_bRecNotStop_Prev = 0;
   SPYSTT_bRecHisNotStopCase_Prev = 0;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidRecNotStopCase                                   */
/* !Description :  cette fonction permet d'emettre en sortie un vecteur       */
/*                 renfermant les causes de non arrêt et d'enregistrer une    */
/*                 matrice renfermant l'historique de ces causes              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SPYSTT_vidRecNotStopCase1();                             */
/*  extf argret void SPYSTT_vidRecHisNotStopCase();                           */
/*  input uint32 Ext_dstVehTotMes;                                            */
/*  input boolean CoPtUH_bRecNotStop;                                         */
/*  input uint32 SpySTT_prmHisDstWin1[2];                                     */
/*  input boolean SPYSTT_bRecNotStop_Prev;                                    */
/*  input boolean SPYSTT_bRecHisNotStopCase_Prev;                             */
/*  output boolean SPYSTT_bRecNotStop_Prev;                                   */
/*  output boolean SPYSTT_bRecHisNotStopCase_Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidRecNotStopCase(void)
{
   boolean bLocalCoPtUH_bRecNotStop;
   boolean bLocalCondition;
   uint32  u32LocalExt_dstVehTotMes;
   uint32  u32LocalprmHisWin1_2;


   VEMS_vidGET(Ext_dstVehTotMes, u32LocalExt_dstVehTotMes);
   VEMS_vidGET(CoPtUH_bRecNotStop, bLocalCoPtUH_bRecNotStop);
   VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin1, 1, u32LocalprmHisWin1_2);
   if (u32LocalExt_dstVehTotMes >= u32LocalprmHisWin1_2)
   {
      bLocalCondition = 1;
   }
   else
   {
      bLocalCondition = 0;
   }
   if (  (bLocalCoPtUH_bRecNotStop != 0)
      && (SPYSTT_bRecNotStop_Prev == 0))
   {
      SPYSTT_vidRecNotStopCase1();
   }
   if (  (bLocalCondition != 0)
      && (SPYSTT_bRecHisNotStopCase_Prev == 0))
   {
      SPYSTT_vidRecHisNotStopCase();
   }

   SPYSTT_bRecNotStop_Prev = bLocalCoPtUH_bRecNotStop;
   SPYSTT_bRecHisNotStopCase_Prev = bLocalCondition;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidRecNotStopCase1                                  */
/* !Description :  cette fonction permet d' enregistrer une matrice renfermant*/
/*                 l'historique des causes de non arrêt par tranches          */
/*                 kilométriques.                                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 Veh_stDrvAvl;                                                 */
/*  input uint8 CoReqVeh_stEngStopAuth;                                       */
/*  input uint8 CoReqStg_stEngStopAuth;                                       */
/*  input uint8 CoReqCha_stEngStopAuth;                                       */
/*  input boolean CoReqCha_bHillAsiRdyEngStop;                                */
/*  input boolean CoPtUH_bStopAuthSlop;                                       */
/*  input boolean CoPtUH_bStPresLo;                                           */
/*  input uint8 EngReqH_stEngStopAuth;                                        */
/*  input uint8 CoEmSTT_stEngStopAuth;                                        */
/*  input boolean CoPtUH_bCompTqRStrt;                                        */
/*  input uint8 CoReqAMT_stEngStopAuth;                                       */
/*  input boolean CoPtUH_bBltStopAuth;                                        */
/*  input uint8 SpySTT_noDstWin_C;                                            */
/*  input uint8 SpySTT_prmHisNotStopCase1[11];                                */
/*  output uint16 SpySTT_stNotStopCase;                                       */
/*  output uint8 SpySTT_prmHisNotStopCase1[11];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidRecNotStopCase1(void)
{
   boolean bLocalArrayTemp[SPYSTT_U8STOPCASE_LENGTH];
   boolean bLocalCoPtUH_bCompTqRStrt;
   boolean bLocalInhStopCoPtUH;
   boolean bLocalCoPtUH_bBltStopAuth;
   boolean bLocalCoReqCha_bHillAsiRdyEngStop;
   boolean bLocalCoPtUH_bStopAuthSlop;
   boolean bLocalCoPtUH_bStPresLo;
   uint8   u8LocalVeh_stDrvAvl;
   uint8   u8LocalCoReqVeh_stEngStopAuth;
   uint8   u8LocalCoReqStg_stEngStopAuth;
   uint8   u8LocalCoReqCha_stEngStopAuth;
   uint8   u8LocalEngReqH_stEngStopAuth;
   uint8   u8LocalCoEmSTT_stEngStopAuth;
   uint8   u8LocalMin2;
   uint8   u8LocalIndex;
   uint8   u8LocalSpySTT_prmHisNotStopCase1[SPYSTT_U8STOPCASE_LENGTH];
   uint8   u8LocalCoReqAMT_stEngStopAuth;
   uint16  u16LocalArrayMin1[SPYSTT_U8STOPCASE_LENGTH];
   uint16  u16LocalSpySTT_stNotStopCase;


   VEMS_vidGET(Veh_stDrvAvl, u8LocalVeh_stDrvAvl);
   VEMS_vidGET(CoReqVeh_stEngStopAuth, u8LocalCoReqVeh_stEngStopAuth);
   VEMS_vidGET(CoReqStg_stEngStopAuth, u8LocalCoReqStg_stEngStopAuth);
   VEMS_vidGET(CoReqCha_stEngStopAuth, u8LocalCoReqCha_stEngStopAuth);
   VEMS_vidGET(CoReqCha_bHillAsiRdyEngStop, bLocalCoReqCha_bHillAsiRdyEngStop);
   VEMS_vidGET(CoPtUH_bStopAuthSlop, bLocalCoPtUH_bStopAuthSlop);
   VEMS_vidGET(CoPtUH_bStPresLo, bLocalCoPtUH_bStPresLo);
   VEMS_vidGET(EngReqH_stEngStopAuth, u8LocalEngReqH_stEngStopAuth);
   VEMS_vidGET(CoEmSTT_stEngStopAuth, u8LocalCoEmSTT_stEngStopAuth);
   VEMS_vidGET(CoPtUH_bCompTqRStrt, bLocalCoPtUH_bCompTqRStrt);
   VEMS_vidGET(CoReqAMT_stEngStopAuth, u8LocalCoReqAMT_stEngStopAuth);
   bLocalInhStopCoPtUH = GDGAR_bGetFRM(FRM_FRM_INHSTOPCOPTUH);
   VEMS_vidGET(CoPtUH_bBltStopAuth, bLocalCoPtUH_bBltStopAuth);

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8STOPCASE_LENGTH;
        u8LocalIndex ++)
   {
      bLocalArrayTemp[u8LocalIndex] = 0;
   }

   if (u8LocalVeh_stDrvAvl != 1)
   {
      bLocalArrayTemp[0] = 1;
      u16LocalSpySTT_stNotStopCase = 1;
   }
   else
   {
      u16LocalSpySTT_stNotStopCase = 0;
   }

   if (u8LocalCoReqVeh_stEngStopAuth != 1)
   {
      bLocalArrayTemp[1] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)(u16LocalSpySTT_stNotStopCase + 2);
   }

   if (u8LocalCoReqStg_stEngStopAuth != 1)
   {
      bLocalArrayTemp[2] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)(u16LocalSpySTT_stNotStopCase + 4);
   }

   if (  (u8LocalCoReqCha_stEngStopAuth != 1)
      || (bLocalCoReqCha_bHillAsiRdyEngStop == 0)
      || (bLocalCoPtUH_bStopAuthSlop == 0))
   {
      bLocalArrayTemp[3] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)(u16LocalSpySTT_stNotStopCase + 8);
   }

   if (bLocalCoPtUH_bStPresLo == 0)
   {
      bLocalArrayTemp[4] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 16);
   }

   if (u8LocalEngReqH_stEngStopAuth != 1)
   {
      bLocalArrayTemp[5] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 32);
   }

   if (u8LocalCoEmSTT_stEngStopAuth != 1)
   {
      bLocalArrayTemp[6] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 64);
   }

   if (bLocalCoPtUH_bCompTqRStrt == 0)
   {
      bLocalArrayTemp[7] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 128);
   }

   if (u8LocalCoReqAMT_stEngStopAuth != 1)
   {
      bLocalArrayTemp[8] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 256);
   }

   if (bLocalInhStopCoPtUH != 0)
   {
      bLocalArrayTemp[9] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 512);
   }

   if (bLocalCoPtUH_bBltStopAuth == 0)
   {
      bLocalArrayTemp[10] = 1;
      u16LocalSpySTT_stNotStopCase = (uint16)( u16LocalSpySTT_stNotStopCase
                                             + 1024);
   }

   VEMS_vidSET(SpySTT_stNotStopCase, u16LocalSpySTT_stNotStopCase);

   if (SpySTT_noDstWin_C > 100)
   {
      u8LocalMin2 = 32;
   }
   else
   {
      u8LocalMin2 = 16;
   }

   VEMS_vidGET1DArray(SpySTT_prmHisNotStopCase1,
                      SPYSTT_U8STOPCASE_LENGTH,
                      u8LocalSpySTT_prmHisNotStopCase1);

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8STOPCASE_LENGTH;
        u8LocalIndex ++)
   {
      if (bLocalArrayTemp[u8LocalIndex] != 0)
      {
         u16LocalArrayMin1[u8LocalIndex] =
            (uint16)(u8LocalSpySTT_prmHisNotStopCase1[u8LocalIndex] + 1);
      }
      else
      {
         u16LocalArrayMin1[u8LocalIndex] =
            u8LocalSpySTT_prmHisNotStopCase1[u8LocalIndex];
      }
      u8LocalSpySTT_prmHisNotStopCase1[u8LocalIndex] =
         (uint8)MATHSRV_udtMIN(u16LocalArrayMin1[u8LocalIndex], u8LocalMin2);
   }
   VEMS_vidSET1DArray(SpySTT_prmHisNotStopCase1,
                      SPYSTT_U8STOPCASE_LENGTH,
                      u8LocalSpySTT_prmHisNotStopCase1);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidRecHisNotStopCase                                */
/* !Description :  cette fonction permet l’implémentation des enregistrements */
/*                 des causes de non arrêt                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 SpySTT_prmHisNotStopCase1[11];                                */
/*  input uint8 SpySTT_prmHisNotStopCase2[11];                                */
/*  input uint32 SpySTT_prmHisDstWin1[2];                                     */
/*  input uint32 SpySTT_prmHisDstWin2[2];                                     */
/*  input uint8 SpySTT_noDstWin_C;                                            */
/*  output uint8 SpySTT_prmHisNotStopCase3[11];                               */
/*  output uint8 SpySTT_prmHisNotStopCase2[11];                               */
/*  output uint8 SpySTT_prmHisNotStopCase1[11];                               */
/*  output uint32 SpySTT_prmHisDstWin3[2];                                    */
/*  output uint32 SpySTT_prmHisDstWin2[2];                                    */
/*  output uint32 SpySTT_prmHisDstWin1[2];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidRecHisNotStopCase(void)
{
   uint8  u8LocalSpySTT_prmHisNotStopCase2[SPYSTT_U8STOPCASE_LENGTH];
   /* QAC warning 3204 due to using table*/
   uint8  u8LocalHisNoStopCase1[SPYSTT_U8STOPCASE_LENGTH];
   /* QAC warning 3204 due to using table*/
   uint8  u8LocalIndex;
   uint32 u32LocalSpySTT_prmHisDstWin1[SPYSTT_U8PRMHISDSTWIN_LENGTH];
   uint32 u32LocalSpySTT_prmHisDstWin2[SPYSTT_U8PRMHISDSTWIN_LENGTH];
   uint32 u32LocalSpySTT_prmHisDstWin3[SPYSTT_U8PRMHISDSTWIN_LENGTH];
   uint32 u32LocalprmHisWin1_1;
   uint32 u32LocalprmHisWin1_2;
   uint32 u32Local_calc1;
   uint32 u32Local_calc2;

   VEMS_vidGET1DArray(SpySTT_prmHisNotStopCase1,
                      SPYSTT_U8STOPCASE_LENGTH,
                      u8LocalHisNoStopCase1);
   VEMS_vidGET1DArray(SpySTT_prmHisNotStopCase2,
                      SPYSTT_U8STOPCASE_LENGTH,
                      u8LocalSpySTT_prmHisNotStopCase2);

   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8STOPCASE_LENGTH;
        u8LocalIndex ++)
   {
      u8LocalSpySTT_prmHisNotStopCase2[u8LocalIndex] =
         (uint8)MATHSRV_udtMIN(u8LocalSpySTT_prmHisNotStopCase2[u8LocalIndex],
                               32);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisNotStopCase3,
                                u8LocalIndex,
                                u8LocalSpySTT_prmHisNotStopCase2[u8LocalIndex]);
      u8LocalHisNoStopCase1[u8LocalIndex] =
         (uint8)MATHSRV_udtMIN(u8LocalHisNoStopCase1[u8LocalIndex], 32);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisNotStopCase2,
                                u8LocalIndex,
                                u8LocalHisNoStopCase1[u8LocalIndex]);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisNotStopCase1, u8LocalIndex, 0);
   }
   VEMS_vidGET1DArray(SpySTT_prmHisDstWin1,
                      SPYSTT_U8PRMHISDSTWIN_LENGTH,
                      u32LocalSpySTT_prmHisDstWin1);
   VEMS_vidGET1DArray(SpySTT_prmHisDstWin2,
                      SPYSTT_U8PRMHISDSTWIN_LENGTH,
                      u32LocalSpySTT_prmHisDstWin2);
   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8PRMHISDSTWIN_LENGTH;
        u8LocalIndex ++)
   {
      u32LocalSpySTT_prmHisDstWin3[u8LocalIndex] =
         u32LocalSpySTT_prmHisDstWin2[u8LocalIndex] + 200;
      u32LocalSpySTT_prmHisDstWin3[u8LocalIndex] =
         MATHSRV_udtMIN(u32LocalSpySTT_prmHisDstWin3[u8LocalIndex], 500400);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin3,
                                u8LocalIndex,
                                u32LocalSpySTT_prmHisDstWin3[u8LocalIndex]);
      u32LocalSpySTT_prmHisDstWin2[u8LocalIndex] =
         u32LocalSpySTT_prmHisDstWin1[u8LocalIndex] + 200;
      u32LocalSpySTT_prmHisDstWin2[u8LocalIndex] =
         MATHSRV_udtMIN(u32LocalSpySTT_prmHisDstWin2[u8LocalIndex], 500200);
      VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin2,
                                u8LocalIndex,
                                u32LocalSpySTT_prmHisDstWin2[u8LocalIndex]);
   }
   VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin1, 0, u32LocalprmHisWin1_1);
   VEMS_vidGET1DArrayElement(SpySTT_prmHisDstWin1, 1, u32LocalprmHisWin1_2);

   u32Local_calc1 = u32LocalprmHisWin1_1 + SpySTT_noDstWin_C;
   u32Local_calc1 = MATHSRV_udtMIN(u32Local_calc1, 500000);
   u32Local_calc2 = u32LocalprmHisWin1_2 + SpySTT_noDstWin_C;
   u32Local_calc2 = MATHSRV_udtMIN(u32Local_calc2, 500000);
   VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin1, 0, u32Local_calc1);
   VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin1, 1, u32Local_calc2);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidCutCasRstFaiRec                                  */
/* !Description :  L'utilité de cette fonction est d'enregistrer la cause     */
/*                 initiale ayant généré le dernier passage en coupé – calé   */
/*                 sur demande du superviseur.                                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SPYSTT_vidCutCaseRec();                                  */
/*  extf argret void SPYSTT_vidRstrtFaiRec();                                 */
/*  input boolean SpySTT_bCutCaseAcvt;                                        */
/*  input uint8 SpySTT_stCutCaseCur;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidCutCasRstFaiRec(void)
{
   SPYSTT_vidCutCaseRec();
   if ( (SpySTT_bCutCaseAcvt != 0)
      &&(SpySTT_stCutCaseCur != 0))
   {
      SPYSTT_vidRstrtFaiRec();
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidCutCaseRec                                       */
/* !Description :  La fonction permet de sauvegarder la cause de coupure      */
/*                 active et cause de coupure présente.                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_005.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPtUH_stPwt;                                                 */
/*  input boolean CoPtUH_bCutCaseClsTra;                                      */
/*  input boolean CoPtUH_bCutCaseNotRStrtAuth;                                */
/*  input boolean CoPtUH_bCutCaseAutRStrt;                                    */
/*  input boolean CoPtUH_bCutCaseSpdMax;                                      */
/*  input boolean CoPtUH_bCutCaseVehRStrtReq;                                 */
/*  input boolean CoPtUH_bEngStallReq;                                        */
/*  input boolean CoPtUH_bCutCaseRCfTyp3;                                     */
/*  input boolean CoPtUH_bCutCaseElMecRStrtReq;                               */
/*  input boolean CoPtUH_bCutCaseLongGc;                                      */
/*  input boolean CoPtUH_bCutCaseDgoBlt;                                      */
/*  input boolean CoPtUH_bCutCaseRStrtReqForc;                                */
/*  input uint8 SpySTT_stCutCaseCur;                                          */
/*  input uint8 SPYSTT_u8CoPtUH_stPwt_Prev;                                   */
/*  input uint8 SpySTT_stCutCaseRec;                                          */
/*  output uint8 SpySTT_stCutCaseCur;                                         */
/*  output boolean SpySTT_bCutCaseAcvt;                                       */
/*  output uint8 SpySTT_stCutCaseRec;                                         */
/*  output uint8 SPYSTT_u8CoPtUH_stPwt_Prev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidCutCaseRec(void)
{
   boolean bLocalCoPtUH_bCutCaseClsTra;
   boolean bLocalCoPtUH_bCutCasNotRStrtAuth;
   boolean bLocalCoPtUH_bCutCaseAutRStrt;
   boolean bLocalCoPtUH_bCutCaseSpdMax;
   boolean bLocalCoPtUH_bCutCaseVehRStrtReq;
   boolean bLocalCoPtUH_bEngStallReq;
   boolean bLocalCoPtUH_bCutCaseRCfTyp3;
   boolean bLocalCoPtUH_bCutCasElMecRStrtRq;
   boolean bLocalCoPtUH_bCutCaseLongGc;
   boolean bLocalCoPtUH_bCutCaseDgoBlt;
   boolean bLocalCoPtUH_bCutCaseRStrtRqForc;
   uint8   u8LocalCoPtUH_stPwt;
   uint8   u8LocalSpySTT_stCutCaseRec;
   uint8   u8LocalSpySTT_stCutCaseCur;


   VEMS_vidGET(CoPtUH_stPwt, u8LocalCoPtUH_stPwt);
   VEMS_vidGET(CoPtUH_bCutCaseClsTra, bLocalCoPtUH_bCutCaseClsTra);
   VEMS_vidGET(CoPtUH_bCutCaseNotRStrtAuth, bLocalCoPtUH_bCutCasNotRStrtAuth);
   VEMS_vidGET(CoPtUH_bCutCaseAutRStrt, bLocalCoPtUH_bCutCaseAutRStrt);
   VEMS_vidGET(CoPtUH_bCutCaseSpdMax, bLocalCoPtUH_bCutCaseSpdMax);
   VEMS_vidGET(CoPtUH_bCutCaseVehRStrtReq, bLocalCoPtUH_bCutCaseVehRStrtReq);
   VEMS_vidGET(CoPtUH_bEngStallReq, bLocalCoPtUH_bEngStallReq);
   VEMS_vidGET(CoPtUH_bCutCaseRCfTyp3, bLocalCoPtUH_bCutCaseRCfTyp3);
   VEMS_vidGET(CoPtUH_bCutCaseElMecRStrtReq,
               bLocalCoPtUH_bCutCasElMecRStrtRq);
   VEMS_vidGET(CoPtUH_bCutCaseLongGc, bLocalCoPtUH_bCutCaseLongGc);
   VEMS_vidGET(CoPtUH_bCutCaseDgoBlt, bLocalCoPtUH_bCutCaseDgoBlt);
   VEMS_vidGET(CoPtUH_bCutCaseRStrtReqForc, bLocalCoPtUH_bCutCaseRStrtRqForc);
   if (  (u8LocalCoPtUH_stPwt == 8)
      || (u8LocalCoPtUH_stPwt == 9)
      || (u8LocalCoPtUH_stPwt == 10)
      || (u8LocalCoPtUH_stPwt == 11)
      || (u8LocalCoPtUH_stPwt == 12)
      || (u8LocalCoPtUH_stPwt == 13))
   {
      SpySTT_stCutCaseCur = 0;
   }
   else
   {
      if (bLocalCoPtUH_bCutCaseVehRStrtReq != 0)
      {
         u8LocalSpySTT_stCutCaseCur = 6;
      }
      else
      {
         if (bLocalCoPtUH_bEngStallReq != 0)
         {
            u8LocalSpySTT_stCutCaseCur = 5;
         }
         else
         {
            if (bLocalCoPtUH_bCutCaseRCfTyp3 != 0)
            {
               u8LocalSpySTT_stCutCaseCur = 4;
            }
            else
            {
               if (bLocalCoPtUH_bCutCasElMecRStrtRq != 0)
               {
                  u8LocalSpySTT_stCutCaseCur = 3;
               }
               else
               {
                  if (bLocalCoPtUH_bCutCaseLongGc != 0)
                  {
                     u8LocalSpySTT_stCutCaseCur = 2;
                  }
                  else
                  {
                     if (bLocalCoPtUH_bCutCaseClsTra != 0)
                     {
                        u8LocalSpySTT_stCutCaseCur = 1;
                     }
                     else
                     {
                        u8LocalSpySTT_stCutCaseCur = 0;
                     }
                  }
               }
            }
         }
      }
      if (SpySTT_stCutCaseCur != 0)
      {
         SpySTT_stCutCaseCur = (uint8)MATHSRV_udtMIN(SpySTT_stCutCaseCur, 11);
      }
      else
      {
         if (bLocalCoPtUH_bCutCaseDgoBlt != 0)
         {
            SpySTT_stCutCaseCur = 11;
         }
         else
         {
            if (bLocalCoPtUH_bCutCaseRStrtRqForc != 0)
            {
               SpySTT_stCutCaseCur = 10;
            }
            else
            {
               if (bLocalCoPtUH_bCutCasNotRStrtAuth != 0)
               {
                  SpySTT_stCutCaseCur = 9;
               }
               else
               {
                  if (bLocalCoPtUH_bCutCaseAutRStrt != 0)
                  {
                     SpySTT_stCutCaseCur = 8;
                  }
                  else
                  {
                     if (bLocalCoPtUH_bCutCaseSpdMax != 0)
                     {
                        SpySTT_stCutCaseCur = 7;
                     }
                     else
                     {
                        SpySTT_stCutCaseCur = u8LocalSpySTT_stCutCaseCur;
                     }
                  }
               }
            }
         }
      }
   }
   if ( u8LocalCoPtUH_stPwt == 1)
   {
      if (  (SPYSTT_u8CoPtUH_stPwt_Prev == 2)
         || (SPYSTT_u8CoPtUH_stPwt_Prev == 4)
         || (SPYSTT_u8CoPtUH_stPwt_Prev == 5)
         || (SPYSTT_u8CoPtUH_stPwt_Prev == 6)
         || (SPYSTT_u8CoPtUH_stPwt_Prev == 7))
      {
         SpySTT_bCutCaseAcvt = 1;
         if (SpySTT_stCutCaseCur != 0)
         {
            VEMS_vidSET(SpySTT_stCutCaseRec, SpySTT_stCutCaseCur);
         }
      }
      else
      {
         SpySTT_bCutCaseAcvt = 0;
         VEMS_vidGET(SpySTT_stCutCaseRec, u8LocalSpySTT_stCutCaseRec);
         u8LocalSpySTT_stCutCaseRec =
            (uint8)MATHSRV_udtMIN(u8LocalSpySTT_stCutCaseRec, 11);
         VEMS_vidSET(SpySTT_stCutCaseRec, u8LocalSpySTT_stCutCaseRec);
      }
   }
   else
   {
      SpySTT_bCutCaseAcvt = 0;
      VEMS_vidGET(SpySTT_stCutCaseRec, u8LocalSpySTT_stCutCaseRec);
      u8LocalSpySTT_stCutCaseRec =
         (uint8)MATHSRV_udtMIN(u8LocalSpySTT_stCutCaseRec, 11);
      VEMS_vidSET(SpySTT_stCutCaseRec, u8LocalSpySTT_stCutCaseRec);
   }
   SPYSTT_u8CoPtUH_stPwt_Prev = (uint8)MATHSRV_udtMIN(u8LocalCoPtUH_stPwt, 15);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_vidRstrtFaiRec                                      */
/* !Description :  La fonction permet l'enregistrement la cause de coupure    */
/*                 liées à un échec de redémarrage.                           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SpySTT_stCutCaseCur;                                          */
/*  input uint8 CoPtUH_stLstRStrtFailCase;                                    */
/*  input uint8 SpySTT_noRStrtFailRec_C;                                      */
/*  input uint8 CoPtUH_stBfLstRStrtFailCase;                                  */
/*  input uint8 CoPtUH_stBfBfLstRStrtFail;                                    */
/*  output uint8 SpySTT_stRStrtFailRec1;                                      */
/*  output uint8 SpySTT_stRStrtFailRec2;                                      */
/*  output uint8 SpySTT_stRStrtFailRec3;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_vidRstrtFaiRec(void)
{
   uint8 u8LocalCoPtUH_stLstRStrtFailCase;
   uint8 u8LocalCoPtUH_stBLstRStFailCase;
   uint8 u8LocalCoPtUH_stBfBLstRStFail;

   if (SpySTT_stCutCaseCur == 5)
   {
      VEMS_vidGET(CoPtUH_stLstRStrtFailCase, u8LocalCoPtUH_stLstRStrtFailCase);
      u8LocalCoPtUH_stLstRStrtFailCase =
         (uint8)MATHSRV_udtMIN(u8LocalCoPtUH_stLstRStrtFailCase, 63);
      VEMS_vidSET(SpySTT_stRStrtFailRec1, u8LocalCoPtUH_stLstRStrtFailCase);
      if (SpySTT_noRStrtFailRec_C >= 2)
      {
         VEMS_vidGET(CoPtUH_stBfLstRStrtFailCase,
                     u8LocalCoPtUH_stBLstRStFailCase);
         u8LocalCoPtUH_stBLstRStFailCase =
            (uint8)MATHSRV_udtMIN(u8LocalCoPtUH_stBLstRStFailCase, 63);
         VEMS_vidSET(SpySTT_stRStrtFailRec2, u8LocalCoPtUH_stBLstRStFailCase);
      }
      else
      {
         VEMS_vidSET(SpySTT_stRStrtFailRec2, 0);
      }
      if (SpySTT_noRStrtFailRec_C >= 3)
      {
         VEMS_vidGET(CoPtUH_stBfBfLstRStrtFail,
                     u8LocalCoPtUH_stBfBLstRStFail);
         u8LocalCoPtUH_stBfBLstRStFail =
            (uint8)MATHSRV_udtMIN(u8LocalCoPtUH_stBfBLstRStFail, 63);
         VEMS_vidSET(SpySTT_stRStrtFailRec3, u8LocalCoPtUH_stBfBLstRStFail);
      }
      else
      {
         VEMS_vidSET(SpySTT_stRStrtFailRec3, 0);
      }
   }
   else
   {
      VEMS_vidSET(SpySTT_stRStrtFailRec1, 0);
      VEMS_vidSET(SpySTT_stRStrtFailRec2, 0);
      VEMS_vidSET(SpySTT_stRStrtFailRec3, 0);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SPYSTT_NVMSRV_vidInit                                      */
/* !Description :  Fonction d'initialisation  pour pour les variables Eeprom. */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_10_02508_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 SpySTT_prmHisNotStopCase1[11];                               */
/*  output uint8 SpySTT_prmHisNotStopCase2[11];                               */
/*  output uint8 SpySTT_prmHisNotStopCase3[11];                               */
/*  output uint8 SpySTT_stRStrtFailRec1;                                      */
/*  output uint8 SpySTT_stRStrtFailRec2;                                      */
/*  output uint8 SpySTT_stRStrtFailRec3;                                      */
/*  output uint8 SpySTT_stCutCaseRec;                                         */
/*  output uint32 SpySTT_prmHisDstWin1[2];                                    */
/*  output uint8 SpySTT_noDstWin_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SPYSTT_NVMSRV_vidInit(void)
{
   uint8 u8LocalIndex;


   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8STOPCASE_LENGTH;
        u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(SpySTT_prmHisNotStopCase1, u8LocalIndex, 0);
   }
   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8STOPCASE_LENGTH;
        u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(SpySTT_prmHisNotStopCase2, u8LocalIndex, 0);
   }
   for (u8LocalIndex = 0;
        u8LocalIndex < SPYSTT_U8STOPCASE_LENGTH;
        u8LocalIndex ++)
   {
      VEMS_vidSET1DArrayElement(SpySTT_prmHisNotStopCase3, u8LocalIndex, 0);
   }

   VEMS_vidSET(SpySTT_stRStrtFailRec1, 0);
   VEMS_vidSET(SpySTT_stRStrtFailRec2, 0);
   VEMS_vidSET(SpySTT_stRStrtFailRec3, 0);
   VEMS_vidSET(SpySTT_stCutCaseRec, 0);
   VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin1, 0, 0);
   VEMS_vidSET1DArrayElement(SpySTT_prmHisDstWin1, 1, SpySTT_noDstWin_C);
}
/*-------------------------------- end of file -------------------------------*/
