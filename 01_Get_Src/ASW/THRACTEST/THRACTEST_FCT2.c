/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRACTEST                                               */
/* !Description     : THRACTEST component.                                    */
/*                                                                            */
/* !Module          : THRACTEST                                               */
/* !Description     : TEST ACTIONNEUR PAPILLON MOTORISÉ.                      */
/*                                                                            */
/* !File            : THRACTEST_FCT2.C                                        */
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
/*   1 / THRACTEST_vidGapTestMain                                             */
/*   2 / THRACTEST_vidGapTstEna                                               */
/*   3 / THRACTEST_vidDiffPosnClcn                                            */
/*   4 / THRACTEST_vidGapTest                                                 */
/*   5 / THRACTEST_vidGapTstResInit                                           */
/*   6 / THRACTEST_vidInitGapTst                                              */
/*   7 / THRACTEST_vidGapTstResClcn                                           */
/*   8 / THRACTEST_vidUpdateGapTst                                            */
/*                                                                            */
/* !Reference   : V02 NT 09 00783 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056850                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/REF/MODULES/THR/THRACTEST/THRACTEST_FCT2.C_v$*/
/* $Revision::   1.1      $$Author::   alaouni        $$Date::   06 Oct 2011 $*/
/* $Author::   alaouni                                $$Date::   06 Oct 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRACTEST.h"
#include "THRACTEST_L.h"
#include "THRACTEST_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidGapTestMain                                   */
/* !Description :  Le test écart de boucle consiste à vérifier que le papillon*/
/*                 atteint bien sa consigne                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.SARHAN                                                   */
/* !Trace_To    :  VEMS_R_09_00783_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRACTEST_vidGapTstEna();                                */
/*  extf argret void THRACTEST_vidDiffPosnClcn();                             */
/*  extf argret void THRACTEST_vidGapTest();                                  */
/*  extf argret void THRACTEST_vidGapTstResInit();                            */
/*  extf argret void THRACTEST_vidGapTstResClcn();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidGapTestMain(void)
{
   THRACTEST_vidGapTstEna();
   THRACTEST_vidDiffPosnClcn();
   THRACTEST_vidGapTest();
   THRACTEST_vidGapTstResInit();
   THRACTEST_vidGapTstResClcn();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidGapTstEna                                     */
/* !Description :  Le test écart de boucle est lancé à chaque changement de   */
/*                 consigne.                                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input uint8 ActrTstThr_ChgtSp;                                            */
/*  input uint8 THRACTEST_u8ActrTstThrChgtSpPrev;                             */
/*  output boolean ActrTstThr_RunGapTest;                                     */
/*  output boolean ActrTstThr_StopGapTest;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidGapTstEna(void)
{
   boolean bLocalThr_bTstInProgs;


   VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);

   if (  (ActrTstThr_ChgtSp != THRACTEST_u8ActrTstThrChgtSpPrev)
      && (ActrTstThr_ChgtSp != 0)
      && (bLocalThr_bTstInProgs != 0))
   {
      ActrTstThr_RunGapTest = 1;
   }
   else
   {
      ActrTstThr_RunGapTest = 0;
   }

   if (bLocalThr_bTstInProgs != 0)
   {
      ActrTstThr_StopGapTest = 0;
   }
   else
   {
      ActrTstThr_StopGapTest = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidDiffPosnClcn                                  */
/* !Description :  L’écart de boucle locale (consigne – mesure) est calculé   */
/*                 tout au long du test actionneur.                           */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Thr_rSpPosActrTst;                                           */
/*  input uint16 Tpac_corrected_throttle_position;                            */
/*  input uint8 ActrTstThr_GapTstMaxDiffPosn;                                 */
/*  input uint8 ActrTstThr_GapTstMinDiffPosn;                                 */
/*  output boolean ActrTstThr_GapDetn;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidDiffPosnClcn(void)
{
   uint16 u16Localthrottle_position;
   uint16 u16LocalGapTstMaxDiffPosn;
   uint16 u16LocalThr_rSpPosActrTst;
   sint16 s16LocalGapTstMinDiffPosn;
   sint32 s32LocalGapTstDiff;


   VEMS_vidGET(Thr_rSpPosActrTst, u16LocalThr_rSpPosActrTst);
   VEMS_vidGET(Tpac_corrected_throttle_position, u16Localthrottle_position);

   s32LocalGapTstDiff = (sint32)( u16LocalThr_rSpPosActrTst
                                - u16Localthrottle_position);
   u16LocalGapTstMaxDiffPosn = (uint16)(ActrTstThr_GapTstMaxDiffPosn * 4);
   s16LocalGapTstMinDiffPosn =
      (sint16)((-4) * (ActrTstThr_GapTstMinDiffPosn + 1));
   if (  (s32LocalGapTstDiff >= (sint32)u16LocalGapTstMaxDiffPosn)
      || (s32LocalGapTstDiff <= (sint32)s16LocalGapTstMinDiffPosn))
   {
      ActrTstThr_GapDetn = 1;
   }
   else
   {
      ActrTstThr_GapDetn = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidGapTest                                       */
/* !Description :  Un temps calibrable est laissé au papillon pour atteindre  */
/*                 sa consigne (phase 1), puis si le papillon reste trop      */
/*                 distant de sa consigne pendant un temps calibrable, alors  */
/*                 on détecte un papillon collé.                              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st89 Thr_stGapTst;                                                  */
/*  input boolean ActrTstThr_RunGapTest;                                      */
/*  input uint16 ActrTstThr_WaitTime;                                         */
/*  input boolean ActrTstThr_StopGapTest;                                     */
/*  input uint16 ActrGapTstThr_TstTime;                                       */
/*  input uint16 ActrTstThr_GapTstTime;                                       */
/*  input boolean ActrTstThr_GapDetn;                                         */
/*  output boolean ActrTstThr_IntGapTstRes;                                   */
/*  output st89 Thr_stGapTst;                                                 */
/*  output uint16 ActrGapTstThr_TstTime;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidGapTest(void)
{
   uint16  u16LocalGapTstThr_TstTime;


   switch (Thr_stGapTst)
   {
      case THR_GAPTST_IDLE:
         if (ActrTstThr_RunGapTest != 0)
         {
            ActrTstThr_IntGapTstRes = 0;
            Thr_stGapTst = THR_GAPTST_PHASE1;
            ActrGapTstThr_TstTime = (uint16)MATHSRV_udtMIN(ActrTstThr_WaitTime,
                                                           30000);
         }
         break;

      case THR_GAPTST_PHASE1:
         if (ActrTstThr_StopGapTest != 0)
         {
            Thr_stGapTst = THR_GAPTST_IDLE;
            ActrTstThr_IntGapTstRes = 0;
         }
         else
         {
            if (ActrGapTstThr_TstTime <= 1)
            {
               Thr_stGapTst = THR_GAPTST_PHASE2;
               u16LocalGapTstThr_TstTime = ActrTstThr_GapTstTime;
            }
            else
            {
               u16LocalGapTstThr_TstTime = (uint16)(ActrGapTstThr_TstTime - 1);
            }
            ActrGapTstThr_TstTime =
               (uint16)MATHSRV_udtMIN(u16LocalGapTstThr_TstTime, 30000);
         }
         break;

      case THR_GAPTST_PHASE2:
         if (  (ActrTstThr_GapDetn == 0)
            || (ActrTstThr_StopGapTest != 0))
         {
            Thr_stGapTst = THR_GAPTST_IDLE;
            ActrTstThr_IntGapTstRes = 0;
         }
         else
         {
            if (ActrGapTstThr_TstTime <= 1)
            {
               Thr_stGapTst = THR_GAPTST_END ;
               ActrTstThr_IntGapTstRes = 1;
            }
            else
            {
               u16LocalGapTstThr_TstTime = (uint16)(ActrGapTstThr_TstTime - 1);
               ActrGapTstThr_TstTime =
                  (uint16)MATHSRV_udtMIN(u16LocalGapTstThr_TstTime, 30000);
            }
         }
         break;

      case THR_GAPTST_END:
         Thr_stGapTst = THR_GAPTST_IDLE;
         ActrTstThr_IntGapTstRes = 0;
         break;

      default:
         Thr_stGapTst = THR_GAPTST_IDLE;
         ActrTstThr_IntGapTstRes = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidGapTstResInit                                 */
/* !Description :  Au début de chaque test actionneur, le bit de résultat     */
/*                 Thr_bGapActrTst est initialisé à 0.                        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRACTEST_vidInitGapTst();                               */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input boolean THRACTEST_bTstInProgsPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidGapTstResInit(void)
{
   boolean bLocalThr_bTstInProgs;


   VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);
   if (  (bLocalThr_bTstInProgs != 0)
      && (THRACTEST_bTstInProgsPrev == 0))
   {
      THRACTEST_vidInitGapTst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidInitGapTst                                    */
/* !Description :  fonction de mise à zéro de résultat du test écart de boucle*/
/*                 (Thr_bGapActrTst).                                         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bGapActrTst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidInitGapTst(void)
{
   VEMS_vidSET(Thr_bGapActrTst, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidGapTstResClcn                                 */
/* !Description :  A cours du test actionneur, dès qu’un écart de boucle est  */
/*                 détecté, le bit de résultat Thr_bGapActrTst est maintenu à */
/*                 1.                                                         */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRACTEST_vidUpdateGapTst();                             */
/*  input boolean Thr_bTstInProgs;                                            */
/*  input boolean THRACTEST_bTstInProgsPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidGapTstResClcn(void)
{
   boolean bLocalThr_bTstInProgs;


   VEMS_vidGET(Thr_bTstInProgs, bLocalThr_bTstInProgs);
   if (  (bLocalThr_bTstInProgs == 0)
      || (THRACTEST_bTstInProgsPrev != 0))
   {
      THRACTEST_vidUpdateGapTst();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRACTEST_vidUpdateGapTst                                  */
/* !Description :  le bit de résultat Thr_bGapActrTst est maintenu à 1        */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  F.SARHAN                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ActrTstThr_IntGapTstRes;                                    */
/*  output boolean Thr_bGapActrTst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRACTEST_vidUpdateGapTst(void)
{
   if (ActrTstThr_IntGapTstRes != 0)
   {
      VEMS_vidSET(Thr_bGapActrTst, 1);
   }
}
/*---------------------------- end of file -----------------------------------*/