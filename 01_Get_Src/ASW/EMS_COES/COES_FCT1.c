/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COES                                                    */
/* !Description     : COES component.                                         */
/*                                                                            */
/* !Module          : COES                                                    */
/* !Description     : Gestionnaire séquence d’arrêt STT                       */
/*                                                                            */
/* !File            : COES_FCT1.C                                             */
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
/*   1 / COES_vidInitOutput                                                   */
/*   2 / COES_vidInterdirInterrupSeqArret                                     */
/*   3 / COES_vidObserverVanosPositionRef                                     */
/*   4 / COES_vidObserverVanneCanisFermee                                     */
/*   5 / COES_vidSequencerPhaseArretSTT                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5660023 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_2877 / 1.6                                      */
/* !OtherRefs   : VEMS V02 ECU#067169                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COES/COES_FCT1.C_v    $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   22 Nov 2013 $*/
/* $Author::   mbenfrad                               $$Date::   22 Nov 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "COES.h"
#include "COES_L.h"
#include "COES_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidInitOutput                                         */
/* !Description :  Cette fonction permet l'initialisation des sorties.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEngToothClc;                                            */
/*  output boolean CoEs_bAcvClsCanPurgSTTEs;                                  */
/*  output boolean CoEs_bAcvIgCutOffSTTEs;                                    */
/*  output boolean CoEs_bAcvIgSysSTTEs;                                       */
/*  output boolean CoEs_bAcvInjCutOffSTTEs;                                   */
/*  output boolean CoEs_bAcvOilPmpSysSTTEs;                                   */
/*  output boolean CoEs_bAcvThrSysSTTEs;                                      */
/*  output boolean CoEs_bAcvVlvSysLockPosnSTTEs;                              */
/*  output boolean CoEs_bAcvVlvSysRiseSTTEs;                                  */
/*  output boolean CoEs_bIntrSTTEsHiEngSpd;                                   */
/*  output boolean CoEs_bIntrSTTEsLoEngSpd;                                   */
/*  output boolean CoEs_bCndEngHiLim_MP;                                      */
/*  output boolean CoEs_bCndEngLoLim_MP;                                      */
/*  output boolean CoEs_bDlyCanPurgCls;                                       */
/*  output boolean CoEs_bDlyCanPurgCls_MP;                                    */
/*  output boolean CoEs_bEngStopReq;                                          */
/*  output boolean CoEs_bPctlAcvClsCanPurgSTTEs;                              */
/*  output boolean CoEs_bPctlAcvClsCanPurgSTTEs_MP;                           */
/*  output boolean CoEs_bPctlAcvVlvSysLockPosnSTTEs;                          */
/*  output boolean CoEs_bAcvVlvSysLockPosnSTTEs_MP;                           */
/*  output boolean CoEs_bVlvSysLockPosn;                                      */
/*  output boolean CoEs_bDlyEndIntrLoSpd_MP;                                  */
/*  output boolean CoEs_bEndIntrCdnEngSpd_MP;                                 */
/*  output boolean CoEs_bDlyEndIntrHiSpd_MP;                                  */
/*  output boolean COES_btiDlyCanPurgClsPrev;                                 */
/*  output uint16 COES_u16TiDlyCanPurgCls;                                    */
/*  output uint16 COES_u16TiDlyIntrSTTEsHiEngSpd;                             */
/*  output uint16 COES_u16TiDlyIntrSTTEsLoEngSpd;                             */
/*  output uint16 COES_u16TiDlyCmdVlvSysIntrSTTEs;                            */
/*  output uint16 COES_u16TiDlyCmdCanPurgIntrSTTEs;                           */
/*  output boolean CoEs_bIntrSTTEsHiEngSpdPrev;                               */
/*  output boolean CoEs_bIntrSTTEsLoEngSpdPrev;                               */
/*  output boolean COES_bCutOffSeqInterrupRS;                                 */
/*  output uint16 COES_u16CoEs_nEngTthClcFilPrev;                             */
/*  output uint16 COES_u16Counter_CoEs_bIntrSTTEs;                            */
/*  output boolean CoEs_bIntrSTTEs;                                           */
/*  output uint8 COES_u8CoStrtRStrtStEngStrtPrev;                             */
/*  output boolean COES_bCoPTStEngRunPrev;                                    */
/*  output boolean CoEs_btiDlyCmdVlvSysIntrSTTEPrev;                          */
/*  output boolean CoEs_btiDlyCmdCanPurgIntSTTEPrev;                          */
/*  output uint32 COES_u32FiltredEngTthClcFilMem;                             */
/*  output uint16 CoEs_nEngTthClcFil;                                         */
/*  output st24 COES_stStopSeq;                                               */
/*  output boolean CoEs_bCmdActrSTTEs;                                        */
/*  output boolean CoEs_bCutActrSTTEs;                                        */
/*  output boolean CoEs_bCutOffIgSTTEs;                                       */
/*  output uint8 CoEs_tiCutOffIg;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidInitOutput(void)
{
   uint16  u16LocalExt_nEngToothClc;


   /*Outputs initialization */
   VEMS_vidSET(CoEs_bAcvClsCanPurgSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvIgCutOffSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvIgSysSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvInjCutOffSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvOilPmpSysSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvThrSysSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvVlvSysLockPosnSTTEs, 0);
   VEMS_vidSET(CoEs_bAcvVlvSysRiseSTTEs, 0);
   VEMS_vidSET(CoEs_bIntrSTTEsHiEngSpd, 0);
   VEMS_vidSET(CoEs_bIntrSTTEsLoEngSpd, 0);
   /*Internals initialization */
   CoEs_bCndEngHiLim_MP = 0;
   CoEs_bCndEngLoLim_MP = 0;
   CoEs_bDlyCanPurgCls = 0;
   CoEs_bDlyCanPurgCls_MP = 0;
   CoEs_bEngStopReq  = 0;
   CoEs_bPctlAcvClsCanPurgSTTEs = 0;
   CoEs_bPctlAcvClsCanPurgSTTEs_MP = 0;
   CoEs_bPctlAcvVlvSysLockPosnSTTEs = 0;
   CoEs_bAcvVlvSysLockPosnSTTEs_MP = 0;
   CoEs_bVlvSysLockPosn = 0;
   CoEs_bDlyEndIntrLoSpd_MP = 0;
   CoEs_bEndIntrCdnEngSpd_MP = 0;
   CoEs_bDlyEndIntrHiSpd_MP = 0;
   COES_btiDlyCanPurgClsPrev = 0;
   COES_u16TiDlyCanPurgCls = 0;
   COES_u16TiDlyIntrSTTEsHiEngSpd = 0;
   COES_u16TiDlyIntrSTTEsLoEngSpd = 0;
   COES_u16TiDlyCmdVlvSysIntrSTTEs = 0;
   COES_u16TiDlyCmdCanPurgIntrSTTEs = 0;
   CoEs_bIntrSTTEsHiEngSpdPrev = 0;
   CoEs_bIntrSTTEsLoEngSpdPrev = 0;
   COES_bCutOffSeqInterrupRS = 0;
   COES_u16CoEs_nEngTthClcFilPrev = 0;
   COES_u16Counter_CoEs_bIntrSTTEs = 0;
   CoEs_bIntrSTTEs = 0;

   /*F05_01_detecter_interruption_sequence_arret */
   COES_u8CoStrtRStrtStEngStrtPrev = 0;
   COES_bCoPTStEngRunPrev = 0;

   /*F05_02_imposer_delai_activation_vanos */
   CoEs_btiDlyCmdVlvSysIntrSTTEPrev = 0;

   /*F05_03_imposer_delai_activation_canister*/
   CoEs_btiDlyCmdCanPurgIntSTTEPrev = 0;
   /* Filter initialization */
   VEMS_vidGET(Ext_nEngToothClc, u16LocalExt_nEngToothClc);
   COES_u32FiltredEngTthClcFilMem =
      (uint32)(u16LocalExt_nEngToothClc * 65536);
   CoEs_nEngTthClcFil =
      (uint16)MATHSRV_udtMIN(u16LocalExt_nEngToothClc, 2000);
   /* State machine initialization */
   COES_stStopSeq = COES_STOPSEQ_INIT;
   CoEs_bCmdActrSTTEs = 0;
   CoEs_bCutActrSTTEs = 0;
   CoEs_bCutOffIgSTTEs = 0;
   CoEs_tiCutOffIg = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidInterdirInterrupSeqArret                           */
/* !Description :  Cette fonction maintient la demande d’arrêt STT à sa       */
/*                 dernière valeur prise si l’on est dans les conditions      */
/*                 moteur tournant et régime inférieur à un seuil calibrable. */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint8 CoStrtRStrt_stStopCutReq;                                     */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 CoEs_tCo_nLimIntr_A[8];                                       */
/*  input uint16 CoEs_nLimLoIntrSTTEs_T[8];                                   */
/*  input uint16 CoEs_nEngTthClcFil;                                          */
/*  input boolean CoEs_bAcvIntrSTTEs_C;                                       */
/*  input boolean CoEs_bCndEngHiLim_MP;                                       */
/*  output boolean CoEs_bCndEngHiLim_MP;                                      */
/*  output boolean CoEs_bEngStopReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidInterdirInterrupSeqArret(void)
{
   /*F01_Interdire_interruption_sequence_arret*/
   boolean bLocalCoPTSt_bEngRun;
   uint8   u8LocalExttCoMes;
   uint8   u8LocalCoStrtRStrt_stStopCutReq;
   uint16  u16LocalParaX;
   uint16  u16LocalInter1D;
   sint16  s16LocalExt_tCoMes;
   sint32  s32LocalExttCoMes;


   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   VEMS_vidGET(CoStrtRStrt_stStopCutReq, u8LocalCoStrtRStrt_stStopCutReq);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   s32LocalExttCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExttCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExttCoMes, 0, 255);
   u16LocalParaX =
      MATHSRV_u16CalcParaIncAryU8(CoEs_tCo_nLimIntr_A, u8LocalExttCoMes, 8);
   u16LocalInter1D = MATHSRV_u16Interp1d(CoEs_nLimLoIntrSTTEs_T, u16LocalParaX);

   if (CoEs_nEngTthClcFil <= u16LocalInter1D)
   {
      CoEs_bCndEngHiLim_MP = 1;
   }
   else
   {
      CoEs_bCndEngHiLim_MP = 0;
   }

   if (  (CoEs_bAcvIntrSTTEs_C == 0)
      || (bLocalCoPTSt_bEngRun == 0)
      || (CoEs_bCndEngHiLim_MP == 0))
   {
      if (u8LocalCoStrtRStrt_stStopCutReq == 2)
      {
         CoEs_bEngStopReq = 1;
      }
      else
      {
         CoEs_bEngStopReq = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidObserverVanosPositionRef                           */
/* !Description :  Cette fonction permet de déterminer si les vanos admission */
/*                 et échappement sont tous deux sur leur position décroisée  */
/*                 de verrouillage.                                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean VlvAct_bInEngStopAuth;                                      */
/*  input boolean VlvAct_bExEngStopAuth;                                      */
/*  input boolean CoEs_bCdnInVlvLockPosn_C;                                   */
/*  input boolean CoEs_bCdnExVlvLockPosn_C;                                   */
/*  output boolean CoEs_bVlvSysLockPosn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidObserverVanosPositionRef(void)
{
   /*F02_Observer_vanos_sur_position_reference*/
   boolean bLocalDEACCDNINVLV;
   boolean bLocalDEACCDNEXVLV;
   boolean bLocalVlvAct_bInEngStopAuth;
   boolean bLocalVlvAct_bExEngStopAuth;
   boolean bLocalcond1;
   boolean bLocalcond2;


   VEMS_vidGET(VlvAct_bInEngStopAuth, bLocalVlvAct_bInEngStopAuth);
   VEMS_vidGET(VlvAct_bExEngStopAuth, bLocalVlvAct_bExEngStopAuth);


   bLocalDEACCDNINVLV = GDGAR_bGetFRM(FRM_FRM_DEACCDNINVLV);
   if (  (bLocalDEACCDNINVLV == 0)
      && (CoEs_bCdnInVlvLockPosn_C != 0))
   {
      bLocalcond1 = bLocalVlvAct_bInEngStopAuth;
   }
   else
   {
      bLocalcond1 = 1;
   }

   bLocalDEACCDNEXVLV = GDGAR_bGetFRM(FRM_FRM_DEACCDNEXVLV);
   if (  (bLocalDEACCDNEXVLV == 0)
      && (CoEs_bCdnExVlvLockPosn_C != 0))
   {
      bLocalcond2 = bLocalVlvAct_bExEngStopAuth;
   }
   else
   {
      bLocalcond2 = 1;
   }

   if (  (bLocalcond1 != 0)
      && (bLocalcond2 != 0))
   {
      CoEs_bVlvSysLockPosn = 1;
   }
   else
   {
      CoEs_bVlvSysLockPosn = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidObserverVanneCanisFermee                           */
/* !Description :  Cette fonction détermine si la vanne du canister est       */
/*                 suffisamment proche de sa position fermée depuis au moins  */
/*                 une temporisation calibrable.                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint8 CanPurg_rOpCanPurgReq;                                        */
/*  input uint16 COES_u16TiDlyCanPurgCls;                                     */
/*  input uint8 CoEs_rCmdLimCanPurg_C;                                        */
/*  input boolean COES_btiDlyCanPurgClsPrev;                                  */
/*  input uint16 CoEs_tiDlyCanPurgCls_C;                                      */
/*  input boolean CoEs_bDeacCdnCanPurg_C;                                     */
/*  input boolean CoEs_bDlyCanPurgCls_MP;                                     */
/*  output boolean CoEs_bDlyCanPurgCls_MP;                                    */
/*  output boolean COES_btiDlyCanPurgClsPrev;                                 */
/*  output uint16 COES_u16TiDlyCanPurgCls;                                    */
/*  output boolean CoEs_bDlyCanPurgCls;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidObserverVanneCanisFermee(void)
{
   /*F03_Observer_vanne_canister_fermee*/
   boolean bLocalDEACCDNCANPURG;
   uint8   u8LocalCanPurg_rOpCanPurgReq;
   uint16  u16LocalTiDlyCanPurgClsCnt;


   VEMS_vidGET(CanPurg_rOpCanPurgReq, u8LocalCanPurg_rOpCanPurgReq);

   u16LocalTiDlyCanPurgClsCnt = COES_u16TiDlyCanPurgCls;

   if (u8LocalCanPurg_rOpCanPurgReq <= CoEs_rCmdLimCanPurg_C)
   {
      if (COES_btiDlyCanPurgClsPrev == 0)
      {
         u16LocalTiDlyCanPurgClsCnt = CoEs_tiDlyCanPurgCls_C;
      }
      else
      {
         if (u16LocalTiDlyCanPurgClsCnt > 0)
         {
            u16LocalTiDlyCanPurgClsCnt = (uint16)( u16LocalTiDlyCanPurgClsCnt
                                                 - 1);
         }
      }
      if (u16LocalTiDlyCanPurgClsCnt == 0)
      {
         CoEs_bDlyCanPurgCls_MP = 1;
      }
      else
      {
         CoEs_bDlyCanPurgCls_MP = 0;
      }
      COES_btiDlyCanPurgClsPrev = 1;
   }
   else
   {
      CoEs_bDlyCanPurgCls_MP = 0;
      COES_btiDlyCanPurgClsPrev = 0;
   }
   COES_u16TiDlyCanPurgCls =
      (uint16)MATHSRV_udtMIN(u16LocalTiDlyCanPurgClsCnt, 400);

   bLocalDEACCDNCANPURG = GDGAR_bGetFRM(FRM_FRM_DEACCDNCANPURG);
   if (  (bLocalDEACCDNCANPURG == 0)
      && (CoEs_bDeacCdnCanPurg_C != 0))
   {
      CoEs_bDlyCanPurgCls = CoEs_bDlyCanPurgCls_MP;
   }
   else
   {
      CoEs_bDlyCanPurgCls = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidSequencerPhaseArretSTT                             */
/* !Description :  Cette fonction détermine l’état de la séquence d’arrêt. Si */
/*                 la demande d’arrêt n’est plus émise, les commandes de la   */
/*                 séquence d’arrêt sont imposées à 0. Cette fonction est     */
/*                 calculée à chaque événement PMH.                           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_006.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st24 COES_stStopSeq;                                                */
/*  input boolean CoEs_bEngStopReq;                                           */
/*  input boolean CoEs_bVlvSysLockPosn;                                       */
/*  input boolean CoEs_bDlyCanPurgCls;                                        */
/*  input uint8 CoEs_tiCutOffIg;                                              */
/*  input uint8 CoEs_tiCutIg_C;                                               */
/*  output st24 COES_stStopSeq;                                               */
/*  output boolean CoEs_bCmdActrSTTEs;                                        */
/*  output boolean CoEs_bCutActrSTTEs;                                        */
/*  output boolean CoEs_bCutOffIgSTTEs;                                       */
/*  output uint8 CoEs_tiCutOffIg;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidSequencerPhaseArretSTT(void)
{
   /*F04_Sequencer_phase_arret_STT*/
   uint16 u16LocalCoEs_tiCutOffIg;


   switch (COES_stStopSeq)
   {
      case COES_STOPSEQ_INIT:
         if (CoEs_bEngStopReq != 0)
         {
            COES_stStopSeq = COES_STOPSEQ_FIRSTSTEP;
            CoEs_bCmdActrSTTEs = 1;
         }
         break;

      case COES_STOPSEQ_FIRSTSTEP:
         if (CoEs_bEngStopReq == 0)
         {
            COES_stStopSeq = COES_STOPSEQ_INIT;
            CoEs_bCmdActrSTTEs = 0;
            CoEs_bCutActrSTTEs = 0;
            CoEs_bCutOffIgSTTEs = 0;
            CoEs_tiCutOffIg = 0;
         }
         else
         {
            if (  (CoEs_bVlvSysLockPosn != 0)
               && (CoEs_bDlyCanPurgCls != 0))
            {
               COES_stStopSeq = COES_STOPSEQ_SECONDSTEP;
               CoEs_bCutActrSTTEs = 1;
            }
         }
         break;

      case COES_STOPSEQ_SECONDSTEP:
         if (CoEs_bEngStopReq == 0)
         {
            COES_stStopSeq = COES_STOPSEQ_INIT;
            CoEs_bCmdActrSTTEs = 0;
            CoEs_bCutActrSTTEs = 0;
            CoEs_bCutOffIgSTTEs = 0;
            CoEs_tiCutOffIg = 0;
         }
         else
         {
            if (CoEs_tiCutOffIg >= CoEs_tiCutIg_C)
            {
               COES_stStopSeq = COES_STOPSEQ_THIRDSTEP;
               CoEs_bCutOffIgSTTEs = 1;
            }
            else
            {
               u16LocalCoEs_tiCutOffIg = (uint16)(CoEs_tiCutOffIg + 1);
               CoEs_tiCutOffIg =
                  (uint8)MATHSRV_udtMIN(u16LocalCoEs_tiCutOffIg, 200);
            }
         }
         break;

      case COES_STOPSEQ_THIRDSTEP:
         if (CoEs_bEngStopReq == 0)
         {
            COES_stStopSeq = COES_STOPSEQ_INIT;
            CoEs_bCmdActrSTTEs = 0;
            CoEs_bCutActrSTTEs = 0;
            CoEs_bCutOffIgSTTEs = 0;
            CoEs_tiCutOffIg = 0;
         }
         break;

      default:
         COES_stStopSeq = COES_STOPSEQ_INIT;
         CoEs_bCmdActrSTTEs = 0;
         CoEs_bCutActrSTTEs = 0;
         CoEs_bCutOffIgSTTEs = 0;
         CoEs_tiCutOffIg = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*------------------------------- end of file --------------------------------*/