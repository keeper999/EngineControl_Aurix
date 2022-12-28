/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUPEDPOSNDIAG                                          */
/* !Description     : CLUPEDPOSNDIAG Component.                               */
/*                                                                            */
/* !Module          : CLUPEDPOSNDIAG                                          */
/* !Description     : SURVEILLANCE DE LA POSITION EMBRAYAGE CONTINUE.         */
/*                                                                            */
/* !File            : CLUPEDPOSNDIAG_FCT1.C                                   */
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
/*   1 / CLUPEDPOSNDIAG_vidInitOutput                                         */
/*   2 / CLUPEDPOSNDIAG_vidActiv_diag                                         */
/*   3 / CLUPEDPOSNDIAG_vidCycle_de_tests                                     */
/*   4 / CLUPEDPOSNDIAG_vidDetect_dysfcts                                     */
/*   5 / CLUPEDPOSNDIAG_vidDetectionMvt                                       */
/*   6 / CLUPEDPOSNDIAG_vidCondIncDecCnt                                      */
/*   7 / CLUPEDPOSNDIAG_vidCompteur                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5050499 / 01                                        */
/* !OtherRefs   : CSMT_CGMT07_2265 / 2.1                                      */
/* !OtherRefs   : VEMS V02 ECU#044847                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/CLUPEDPOSNDIAG/CL$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   04 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   04 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CLUPEDPOSNDIAG.h"
#include "CLUPEDPOSNDIAG_L.h"
#include "CLUPEDPOSNDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidInitOutput                               */
/* !Description :  Fonction qui fait l'initialisation des sorties             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 StaCtl_ctDiagCluP_NV;                                         */
/*  output boolean StaCtl_bDgoFctCluP;                                        */
/*  output boolean StaCtl_bMonRunFctCluP;                                     */
/*  output uint8 StaCtl_ctDiagCluP;                                           */
/*  output uint8 StaCtl_ctDiagCluP_NV;                                        */
/*  output boolean StaCtl_bCluPMainDfct;                                      */
/*  output boolean StaCtl_bDrvCycDiagCluP;                                    */
/*  output boolean CLUPEDPOSNDIAG_bEnaCounter_Prev;                           */
/*  output sint16 CLUPEDPOSNDIAG_s16ExtCoMes;                                 */
/*  output uint16 CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt;                           */
/*  output uint16 CLUPEDPOSNDIAG_u16VehSpdVeh;                                */
/*  output uint8 CLUPEDPOSNDIAG_u8CoPTStEngPrev;                              */
/*  output uint8 CLUPEDPOSNDIAG_u8GearRatioPrev;                              */
/*  output boolean CLUPEDPOSNDIAG_bBasculeRSOutInv;                           */
/*  output boolean CLUPEDPOSNDIAG_bBasculeRSOutput;                           */
/*  output boolean CLUPEDPOSNDIAG_bCluBasculeRSOut;                           */
/*  output uint16 CLUPEDPOSNDIAG_u16CounterOutput;                            */
/*  output boolean CLUPEDPOSNDIAG_bRstCntDiaCluPrev;                          */
/*  output uint8 CLUPEDPOSNDIAG_u8ResteCounter;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidInitOutput(void)
{
   /* Outputs Initialization */
   VEMS_vidSET(StaCtl_bDgoFctCluP, 0);
   VEMS_vidSET(StaCtl_bMonRunFctCluP, 0);
   VEMS_vidSET(StaCtl_ctDiagCluP, StaCtl_ctDiagCluP_NV);

   StaCtl_bCluPMainDfct = 0;
   StaCtl_bDrvCycDiagCluP = 0;
   /* Previous values initialization */
   CLUPEDPOSNDIAG_bEnaCounter_Prev = 0;
   CLUPEDPOSNDIAG_s16ExtCoMes = 0;
   CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt = 0;
   CLUPEDPOSNDIAG_u16VehSpdVeh = 0;
   CLUPEDPOSNDIAG_u8CoPTStEngPrev = 0;
   CLUPEDPOSNDIAG_u8GearRatioPrev = 0;
   /* RS Flip-Flop Outputs Initialization */
   CLUPEDPOSNDIAG_bBasculeRSOutInv = 1;
   CLUPEDPOSNDIAG_bBasculeRSOutput = 0;
   CLUPEDPOSNDIAG_bCluBasculeRSOut = 1;
   /* Counter Initialization */
   CLUPEDPOSNDIAG_u16CounterOutput = 0;
   CLUPEDPOSNDIAG_bRstCntDiaCluPrev = 0;
   CLUPEDPOSNDIAG_u8ResteCounter = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidActiv_diag                               */
/* !Description :  Cette fonction permet de déterminer si la surveillance de  */
/*                 l’embrayage doit être active ou non.                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_08522_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bRvs;                                                   */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 Ext_stStrtCf;                                                 */
/*  input boolean StaCtl_bMonRunFctCluP_SC;                                   */
/*  output boolean StaCtl_bMonRunFctCluP;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidActiv_diag(void)
{
   boolean bLocalExt_bRvs;
   boolean bLocalInhDiagCluP;
   boolean bLocalStaCtl_bMonRunFctCluP;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalExt_stStrtCf;


   bLocalInhDiagCluP = GDGAR_bGetFRM(FRM_FRM_INHDIAGCLUP);

   VEMS_vidGET(Ext_bRvs, bLocalExt_bRvs);
   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   VEMS_vidGET(Ext_stStrtCf, u8LocalExt_stStrtCf);

   if (  (u8LocalExt_stGBxCf == 0)
      && (bLocalExt_bRvs == 0)
      && (bLocalInhDiagCluP == 0)
      && (u8LocalExt_stStrtCf == 2)
      && (StaCtl_bMonRunFctCluP_SC != 0))
   {
      bLocalStaCtl_bMonRunFctCluP = 1;
   }
   else
   {
      bLocalStaCtl_bMonRunFctCluP = 0;
   }
   VEMS_vidSET(StaCtl_bMonRunFctCluP, bLocalStaCtl_bMonRunFctCluP);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidCycle_de_tests                           */
/* !Description :  La  fonction  cycle_de_tests  détermine  si  l’utilisateur */
/*                 a  fait  un  cycle  de  conduite  suffisament  complet afin*/
/*                 de pouvoir effectuer certaines vérifications.              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_08522_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean StaCtl_bDrvCycDiagCluP;                                     */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input sint16 CLUPEDPOSNDIAG_s16ExtCoMes;                                  */
/*  input uint16 CLUPEDPOSNDIAG_u16VehSpdVeh;                                 */
/*  input uint8 CLUPEDPOSNDIAG_u8CoPTStEngPrev;                               */
/*  input uint16 StaCtl_spdVehDiagCluP_C;                                     */
/*  input sint16 StaCtl_tCoMesDiagCluP_C;                                     */
/*  input uint8 StaCtl_tDeltaCoMes_C;                                         */
/*  output boolean CLUPEDPOSNDIAG_bDrvCycDiagCluPrv;                          */
/*  output uint16 CLUPEDPOSNDIAG_u16VehSpdVeh;                                */
/*  output boolean StaCtl_bDrvCycDiagCluP;                                    */
/*  output sint16 CLUPEDPOSNDIAG_s16ExtCoMes;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidCycle_de_tests(void)
{
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalVeh_spdVeh;
   sint16  s16LocalExt_tCoMes;
   sint32  s32LocalExt_tCoMesDiff;


   CLUPEDPOSNDIAG_bDrvCycDiagCluPrv = StaCtl_bDrvCycDiagCluP;

   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);


   s32LocalExt_tCoMesDiff = (sint32)( s16LocalExt_tCoMes
                                    - CLUPEDPOSNDIAG_s16ExtCoMes);

   if (u16LocalVeh_spdVeh > CLUPEDPOSNDIAG_u16VehSpdVeh)
   {
      CLUPEDPOSNDIAG_u16VehSpdVeh = (uint16)MATHSRV_udtMIN(u16LocalVeh_spdVeh,
                                                           64000);
   }
   else
   {
      CLUPEDPOSNDIAG_u16VehSpdVeh =
         (uint16)MATHSRV_udtMIN(CLUPEDPOSNDIAG_u16VehSpdVeh, 64000);
   }
   if (  (CLUPEDPOSNDIAG_u8CoPTStEngPrev == Engine_Running)
      && (u8LocalCoPTSt_stEng != Engine_Running)
      && (CLUPEDPOSNDIAG_u16VehSpdVeh > StaCtl_spdVehDiagCluP_C)
      && (s16LocalExt_tCoMes > StaCtl_tCoMesDiagCluP_C)
      && (s32LocalExt_tCoMesDiff > StaCtl_tDeltaCoMes_C))
   {
      StaCtl_bDrvCycDiagCluP = 0;
   }
   else
   {
      if (  (CLUPEDPOSNDIAG_u8CoPTStEngPrev != Engine_Running)
         && (u8LocalCoPTSt_stEng == Engine_Running))
      {
         CLUPEDPOSNDIAG_s16ExtCoMes = s16LocalExt_tCoMes;
         StaCtl_bDrvCycDiagCluP = 1;
      }
   }
   CLUPEDPOSNDIAG_s16ExtCoMes =
      (sint16)MATHSRV_udtCLAMP(CLUPEDPOSNDIAG_s16ExtCoMes, -40, 214);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidDetect_dysfcts                           */
/* !Description :  La fonction detection_dysfonctionnements effectue la       */
/*                 surveillance proprement dite  de  la position embrayage.   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_08522_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUPEDPOSNDIAG_vidDetectionMvt();                        */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_rCluPHiFreq;                                             */
/*  input uint8 TqDem_rGearRatAftRng;                                         */
/*  input uint16 StaCtl_rCluPThdCalLo_C;                                      */
/*  input uint16 StaCtl_rCluPThdCalHi_C;                                      */
/*  input uint16 StaCtl_nEngDiagCluP_C;                                       */
/*  input uint8 CLUPEDPOSNDIAG_u8GearRatioPrev;                               */
/*  input boolean CLUPEDPOSNDIAG_bBasculeRSOutput;                            */
/*  input boolean StaCtl_bCluPMainDfct;                                       */
/*  input boolean CLUPEDPOSNDIAG_bEnaCounter_Prev;                            */
/*  input uint16 StaCtl_tiDlyNotGc_C;                                         */
/*  input uint8 CLUPEDPOSNDIAG_u8ResteCounter;                                */
/*  input uint16 CLUPEDPOSNDIAG_u16CounterOutput;                             */
/*  input uint8 StaCtl_tiSdlDiagCluP_SC;                                      */
/*  output boolean CLUPEDPOSNDIAG_bBasculeRSOutput;                           */
/*  output uint16 CLUPEDPOSNDIAG_u16CounterOutput;                            */
/*  output uint8 CLUPEDPOSNDIAG_u8ResteCounter;                               */
/*  output boolean StaCtl_bCluPMainDfct;                                      */
/*  output boolean CLUPEDPOSNDIAG_bEnaCounter_Prev;                           */
/*  output uint8 CLUPEDPOSNDIAG_u8GearRatioPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidDetect_dysfcts(void)
{
   boolean bLocalEnaCounter;
   uint8   u8LocalTqDem_rGearRatAftRng;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalExt_rCluPHiFreq;
   sint16  s16LocalGearRatioDiff;
   uint32  u32LocalCluPThdCalLo;
   uint32  u32Localdiv;
   uint32  u32LocalCluPThdCalHi;
   uint32  u32LocalExt_rCluPHiFreq;
   uint32  u32LocalEngDiagCluP;
   uint32  u32LocalCounterOutput;
   uint32  u32LocalCOutput;

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_rCluPHiFreq, u16LocalExt_rCluPHiFreq);
   VEMS_vidGET(TqDem_rGearRatAftRng, u8LocalTqDem_rGearRatAftRng);

   u32LocalCluPThdCalLo = (uint32)(StaCtl_rCluPThdCalLo_C * 8);
   u32LocalCluPThdCalHi = (uint32)(StaCtl_rCluPThdCalHi_C * 8);
   u32LocalExt_rCluPHiFreq = (uint32)(u16LocalExt_rCluPHiFreq * 5);
   u32LocalEngDiagCluP = (uint32)(StaCtl_nEngDiagCluP_C * 10);

   if (u32LocalExt_rCluPHiFreq < u32LocalCluPThdCalLo)
   {
      CLUPEDPOSNDIAG_bBasculeRSOutput = 0;
   }
   else
   {
      if (u32LocalExt_rCluPHiFreq > u32LocalCluPThdCalHi)
      {
         CLUPEDPOSNDIAG_bBasculeRSOutput = 1;
      }
   }

   s16LocalGearRatioDiff = (sint16)( u8LocalTqDem_rGearRatAftRng
                                   - CLUPEDPOSNDIAG_u8GearRatioPrev);
   if (  (CLUPEDPOSNDIAG_bBasculeRSOutput != 0)
      && (StaCtl_bCluPMainDfct == 0)
      && (u8LocalTqDem_rGearRatAftRng != 0)
      && (s16LocalGearRatioDiff == 0)
      && (u16LocalExt_nEng > u32LocalEngDiagCluP))
   {
      bLocalEnaCounter = 1;
   }
   else
   {
      bLocalEnaCounter = 0;
   }
   /*** TURN_ON_DELAY ***/
   if (bLocalEnaCounter != 0)
   {
      if (CLUPEDPOSNDIAG_bEnaCounter_Prev == 0)
      {
         CLUPEDPOSNDIAG_u16CounterOutput =
            (uint16)MATHSRV_udtMIN(StaCtl_tiDlyNotGc_C, 600);
         CLUPEDPOSNDIAG_u8ResteCounter = 0;
      }
      else
      {
         CLUPEDPOSNDIAG_u8ResteCounter =
               (uint8)MATHSRV_udtMIN(CLUPEDPOSNDIAG_u8ResteCounter, 10);
         u32Localdiv = (uint32)( ( CLUPEDPOSNDIAG_u16CounterOutput
                                 * 10)
                               + CLUPEDPOSNDIAG_u8ResteCounter);
         if (u32Localdiv > StaCtl_tiSdlDiagCluP_SC)
         {
            u32LocalCounterOutput = u32Localdiv - StaCtl_tiSdlDiagCluP_SC;
            if (u32LocalCounterOutput < 10)
            {
               u32LocalCOutput = (u32LocalCounterOutput + 5) / 10;
            }
            else
            {
               u32LocalCOutput = u32LocalCounterOutput / 10;
            }
            CLUPEDPOSNDIAG_u16CounterOutput =
               (uint16)MATHSRV_udtMIN(u32LocalCOutput, 600);
            CLUPEDPOSNDIAG_u8ResteCounter = (uint8)(u32LocalCounterOutput % 10);
         }
         else
         {
            CLUPEDPOSNDIAG_u8ResteCounter = 0;
            CLUPEDPOSNDIAG_u16CounterOutput = 0;
         }
      }
      if (CLUPEDPOSNDIAG_u16CounterOutput == 0)
      {
         StaCtl_bCluPMainDfct = 1;
      }
      else
      {
         StaCtl_bCluPMainDfct = 0;
      }
   }
   else
   {
      CLUPEDPOSNDIAG_u8ResteCounter = 0;
      StaCtl_bCluPMainDfct = 0;
   }
   CLUPEDPOSNDIAG_bEnaCounter_Prev = bLocalEnaCounter;
   CLUPEDPOSNDIAG_u8GearRatioPrev =
      (uint8)MATHSRV_udtMIN(u8LocalTqDem_rGearRatAftRng, 8);
   CLUPEDPOSNDIAG_vidDetectionMvt();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidDetectionMvt                             */
/* !Description :  Cette fonction permet la détection d' un dysfonctionnement */
/*                 du capteur continu d'embrayage suite à une absence de      */
/*                 mouvement de la pédale d'embrayage pendant un cycle de     */
/*                 conduite                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rCluPHiFreq;                                             */
/*  input boolean CLUPEDPOSNDIAG_bDrvCycDiagCluPrv;                           */
/*  input boolean StaCtl_bDrvCycDiagCluP;                                     */
/*  input uint16 CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt;                            */
/*  input uint16 StaCtl_rCluPThdChg_C;                                        */
/*  input boolean CLUPEDPOSNDIAG_bCluBasculeRSOut;                            */
/*  output uint16 CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt;                           */
/*  output boolean CLUPEDPOSNDIAG_bCluBasculeRSOut;                           */
/*  output boolean StaCtl_bCluPDrvCycDfct;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidDetectionMvt(void)
{
   uint16 u16LocalExt_rCluPHiFreq;
   uint16 u16LocalExt_rCluPHiFreqSwtDiff;
   uint32 u32LocalCluPThdChg;
   uint32 u32LocalExt_rCluPHiFreqSwtDiff;
   sint32 s32LocalExt_rCluPHiFreqSwtDiff;


   VEMS_vidGET(Ext_rCluPHiFreq, u16LocalExt_rCluPHiFreq);

   if (  (CLUPEDPOSNDIAG_bDrvCycDiagCluPrv == 0)
      && (StaCtl_bDrvCycDiagCluP != 0))
   {
      CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt = u16LocalExt_rCluPHiFreq;
   }

   s32LocalExt_rCluPHiFreqSwtDiff = (sint32)( u16LocalExt_rCluPHiFreq
                                            - CLUPEDPOSNDIAG_u16Ext_PHiFreqSwt);
   u16LocalExt_rCluPHiFreqSwtDiff =
      (uint16)MATHSRV_udtABS(s32LocalExt_rCluPHiFreqSwtDiff);

   u32LocalCluPThdChg = (uint32)(StaCtl_rCluPThdChg_C * 8);
   u32LocalExt_rCluPHiFreqSwtDiff = (uint32)( u16LocalExt_rCluPHiFreqSwtDiff
                                            * 5);

   if (  (u32LocalExt_rCluPHiFreqSwtDiff > u32LocalCluPThdChg)
      && (StaCtl_bDrvCycDiagCluP != 0))
   {
      CLUPEDPOSNDIAG_bCluBasculeRSOut = 0;
   }

   if (  (CLUPEDPOSNDIAG_bCluBasculeRSOut != 0)
      && (CLUPEDPOSNDIAG_bDrvCycDiagCluPrv != 0)
      && (StaCtl_bDrvCycDiagCluP == 0))
   {
      StaCtl_bCluPDrvCycDfct = 1;
   }
   else
   {
      StaCtl_bCluPDrvCycDfct = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidCondIncDecCnt                            */
/* !Description :  cette fonction permet la commutation entre l'incrémentation*/
/*                 et la décrémentation du compteur: incrémentation lors de la*/
/*                 détéction d'un dysfonctionnment et décrémentation si le    */
/*                 compteur reste inchangé pendant tout un cycle de conduite. */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean StaCtl_bCluPMainDfct;                                       */
/*  input boolean StaCtl_bCluPDrvCycDfct;                                     */
/*  input boolean CLUPEDPOSNDIAG_bDrvCycDiagCluPrv;                           */
/*  input boolean CLUPEDPOSNDIAG_bBasculeRSOutInv;                            */
/*  input boolean StaCtl_bDrvCycDiagCluP;                                     */
/*  output boolean CLUPEDPOSNDIAG_bBasculeRSOutInv;                           */
/*  output boolean CLUPEDPOSNDIAG_bCondIncDecCnt;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidCondIncDecCnt(void)
{
   if (  (  (StaCtl_bCluPMainDfct != 0)
         || (StaCtl_bCluPDrvCycDfct != 0))
      && (CLUPEDPOSNDIAG_bDrvCycDiagCluPrv != 0))
   {
      CLUPEDPOSNDIAG_bBasculeRSOutInv = 0;
   }

   if (  (CLUPEDPOSNDIAG_bBasculeRSOutInv != 0)
      && (CLUPEDPOSNDIAG_bDrvCycDiagCluPrv != 0)
      && (StaCtl_bDrvCycDiagCluP == 0))
   {
      CLUPEDPOSNDIAG_bCondIncDecCnt = 1;
   }
   else
   {
      CLUPEDPOSNDIAG_bCondIncDecCnt = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDPOSNDIAG_vidCompteur                                 */
/* !Description :  Lorsqu’un dysfonctionnement est détecté, un compteur est   */
/*                 incrémenté  Le pas d’incrémentation est  différent selon le*/
/*                 dysfonctionnement  activé.La décrémentation est effectuée  */
/*                 si le compteur reste inchangé pendant un cycle de test.    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_08522_007.01                                     */
/*                 VEMS_R_10_08522_008.01                                     */
/*                 VEMS_R_10_08522_009.01                                     */
/*                 VEMS_R_10_08522_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUPEDPOSNDIAG_vidCondIncDecCnt();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input boolean StaCtl_bDgoFctCluP;                                         */
/*  input boolean StaCtl_bMonRunFctCluP;                                      */
/*  input uint8 StaCtl_ctDiagCluP;                                            */
/*  input boolean Afts_bRstCntDiagCluP;                                       */
/*  input uint8 StaCtl_noDecDiagCluP_C;                                       */
/*  input boolean StaCtl_bCluPMainDfct;                                       */
/*  input uint8 StaCtl_noIncMainDiagCluP_C;                                   */
/*  input boolean StaCtl_bCluPDrvCycDfct;                                     */
/*  input uint8 StaCtl_noIncDrvCycDiagCluP_C;                                 */
/*  input boolean CLUPEDPOSNDIAG_bCondIncDecCnt;                              */
/*  input uint8 StaCtl_noMaxDiagCluP_C;                                       */
/*  input uint8 StaCtl_noLoThdDiagCluP_C;                                     */
/*  input uint8 StaCtl_noHiThdDiagCluP_C;                                     */
/*  input boolean CLUPEDPOSNDIAG_bRstCntDiaCluPrev;                           */
/*  input uint8 CLUPEDPOSNDIAG_u8CoPTStEngPrev;                               */
/*  output uint8 StaCtl_ctDiagCluP_NV;                                        */
/*  output uint8 CLUPEDPOSNDIAG_u8CoPTStEngPrev;                              */
/*  output boolean CLUPEDPOSNDIAG_bRstCntDiaCluPrev;                          */
/*  output boolean StaCtl_bDgoFctCluP;                                        */
/*  output uint8 StaCtl_ctDiagCluP;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDPOSNDIAG_vidCompteur(void)
{
   boolean bLocalStaCtl_bDgoFctCluP;
   boolean bLocalStaCtl_bMonRunFctCluP;
   boolean bLocalAfts_bRstCntDiagCluP;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalDecDiagClu;
   uint8   u8LocalIncDiagClu;
   uint8   u8LocalIncDrvCycDiagClu;
   uint8   u8LocalStaCtl_ctDiagCluP;
   sint16  s16LocalSwtOutput;


   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(StaCtl_bDgoFctCluP, bLocalStaCtl_bDgoFctCluP);
   VEMS_vidGET(StaCtl_bMonRunFctCluP, bLocalStaCtl_bMonRunFctCluP);
   VEMS_vidGET(StaCtl_ctDiagCluP, u8LocalStaCtl_ctDiagCluP);
   VEMS_vidGET(Afts_bRstCntDiagCluP , bLocalAfts_bRstCntDiagCluP);

   CLUPEDPOSNDIAG_vidCondIncDecCnt();

   if (bLocalStaCtl_bMonRunFctCluP != 0)
   {
      u8LocalDecDiagClu = StaCtl_noDecDiagCluP_C;

      if (StaCtl_bCluPMainDfct != 0)
      {
         u8LocalIncDiagClu = StaCtl_noIncMainDiagCluP_C;
      }
      else
      {
         u8LocalIncDiagClu = 0;
      }

      if (StaCtl_bCluPDrvCycDfct != 0)
      {
         u8LocalIncDrvCycDiagClu = StaCtl_noIncDrvCycDiagCluP_C;
      }
      else
      {
         u8LocalIncDrvCycDiagClu = 0;
      }
   }
   else
   {
      u8LocalDecDiagClu = 0;
      u8LocalIncDiagClu = 0;
      u8LocalIncDrvCycDiagClu = 0;
   }

   s16LocalSwtOutput = (sint16)( u8LocalStaCtl_ctDiagCluP
                               + u8LocalIncDiagClu
                               + u8LocalIncDrvCycDiagClu);
   if (CLUPEDPOSNDIAG_bCondIncDecCnt != 0)
   {
      s16LocalSwtOutput = (sint16)(s16LocalSwtOutput - u8LocalDecDiagClu);
   }

   u8LocalStaCtl_ctDiagCluP = (uint8)MATHSRV_udtCLAMP(s16LocalSwtOutput,
                                                      0,
                                                      StaCtl_noMaxDiagCluP_C);

   if (u8LocalStaCtl_ctDiagCluP <= StaCtl_noLoThdDiagCluP_C)
   {
      bLocalStaCtl_bDgoFctCluP = 0;
   }
   else
   {
      if (StaCtl_noHiThdDiagCluP_C <= u8LocalStaCtl_ctDiagCluP)
      {
         bLocalStaCtl_bDgoFctCluP = 1;
      }
   }

   if (  (bLocalAfts_bRstCntDiagCluP != 0)
      && (CLUPEDPOSNDIAG_bRstCntDiaCluPrev == 0))
   {
      StaCtl_ctDiagCluP_NV = 0;
   }
   else
   {
      if (  (CLUPEDPOSNDIAG_u8CoPTStEngPrev == Engine_Running)
         && (u8LocalCoPTSt_stEng != Engine_Running))
      {
         StaCtl_ctDiagCluP_NV = u8LocalStaCtl_ctDiagCluP;
      }
   }
   CLUPEDPOSNDIAG_u8CoPTStEngPrev = u8LocalCoPTSt_stEng;
   CLUPEDPOSNDIAG_bRstCntDiaCluPrev = bLocalAfts_bRstCntDiagCluP;

   VEMS_vidSET(StaCtl_bDgoFctCluP, bLocalStaCtl_bDgoFctCluP);
   VEMS_vidSET(StaCtl_ctDiagCluP, u8LocalStaCtl_ctDiagCluP);
}
/*---------------------------------End Of File-------------------------------*/