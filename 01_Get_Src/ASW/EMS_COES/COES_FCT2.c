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
/* !File            : COES_FCT2.C                                             */
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
/*   1 / COES_vidSelectionnerCommandArret                                     */
/*   2 / COES_vidDetecterInterrupSeqArret                                     */
/*   3 / COES_vidCutOffSequenceInterrupt                                      */
/*   4 / COES_vidImposerDelaiActivVanos                                       */
/*   5 / COES_vidImposeDelaiActivCanister                                     */
/*   6 / COES_vidFiltrerRegimeDentADent                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5660023 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_2877 / 1.6                                      */
/* !OtherRefs   : VEMS V02 ECU#067169                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/STT/COES/COES_FCT2.C_v    $*/
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
/* !Function    :  COES_vidSelectionnerCommandArret                           */
/* !Description :  Cette fonction détermine l’application des commandes de    */
/*                 l’automate de gestion de la séquence d’arrêt.              */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_007.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void COES_vidDetecterInterrupSeqArret();                      */
/*  extf argret void COES_vidImposerDelaiActivVanos();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COES_vidImposeDelaiActivCanister();                      */
/*  input boolean CoEs_bAcvVlvSysLockPosnSTTEs_C;                             */
/*  input boolean CoEs_bPctlAcvVlvSysLockPosnSTTEs;                           */
/*  input boolean CoEs_bAcvClsCanPurgSTTEs_C;                                 */
/*  input boolean CoEs_bPctlAcvClsCanPurgSTTEs;                               */
/*  input boolean CoEs_bAcvOilPmpSysSTTEs_C;                                  */
/*  input boolean CoEs_bCmdActrSTTEs;                                         */
/*  input boolean CoEs_bAcvVlvSysRiseSTTEs_C;                                 */
/*  input boolean CoEs_bCutActrSTTEs;                                         */
/*  input boolean CoEs_bAcvIgSysSTTEs_C;                                      */
/*  input boolean CoEs_bAcvThrSysSTTEs_C;                                     */
/*  input boolean CoEs_bAcvInjCutOffSTTEs_C;                                  */
/*  input boolean CoEs_bAcvIgCutOffSTTEs_C;                                   */
/*  input boolean CoEs_bCutOffIgSTTEs;                                        */
/*  output boolean CoEs_bAcvVlvSysLockPosnSTTEs;                              */
/*  output boolean CoEs_bPctlAcvVlvSysLockPosnSTTEs;                          */
/*  output boolean CoEs_bAcvClsCanPurgSTTEs;                                  */
/*  output boolean CoEs_bPctlAcvClsCanPurgSTTEs;                              */
/*  output boolean CoEs_bAcvOilPmpSysSTTEs;                                   */
/*  output boolean CoEs_bCmdActrSTTEs;                                        */
/*  output boolean CoEs_bAcvVlvSysRiseSTTEs;                                  */
/*  output boolean CoEs_bCutActrSTTEs;                                        */
/*  output boolean CoEs_bAcvIgSysSTTEs;                                       */
/*  output boolean CoEs_bAcvThrSysSTTEs;                                      */
/*  output boolean CoEs_bAcvInjCutOffSTTEs;                                   */
/*  output boolean CoEs_bAcvIgCutOffSTTEs;                                    */
/*  output boolean CoEs_bCutOffIgSTTEs;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidSelectionnerCommandArret(void)
{
   /*F05_Selectionner_commande_d_arret*/

   COES_vidDetecterInterrupSeqArret();
   COES_vidImposerDelaiActivVanos();

   if (CoEs_bAcvVlvSysLockPosnSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvVlvSysLockPosnSTTEs,
                  CoEs_bPctlAcvVlvSysLockPosnSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvVlvSysLockPosnSTTEs, 0);
   }

   COES_vidImposeDelaiActivCanister();

   if (CoEs_bAcvClsCanPurgSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvClsCanPurgSTTEs, CoEs_bPctlAcvClsCanPurgSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvClsCanPurgSTTEs, 0);
   }

   if (CoEs_bAcvOilPmpSysSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvOilPmpSysSTTEs, CoEs_bCmdActrSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvOilPmpSysSTTEs, 0);
   }

   if (CoEs_bAcvVlvSysRiseSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvVlvSysRiseSTTEs, CoEs_bCutActrSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvVlvSysRiseSTTEs, 0);
   }

   if (CoEs_bAcvIgSysSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvIgSysSTTEs, CoEs_bCutActrSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvIgSysSTTEs, 0);
   }

   if (CoEs_bAcvThrSysSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvThrSysSTTEs, CoEs_bCutActrSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvThrSysSTTEs, 0);
   }

   if (CoEs_bAcvInjCutOffSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvInjCutOffSTTEs, CoEs_bCutActrSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvInjCutOffSTTEs, 0);
   }

   if (CoEs_bAcvIgCutOffSTTEs_C != 0)
   {
      VEMS_vidSET(CoEs_bAcvIgCutOffSTTEs, CoEs_bCutOffIgSTTEs);
   }
   else
   {
      VEMS_vidSET(CoEs_bAcvIgCutOffSTTEs, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidDetecterInterrupSeqArret                           */
/* !Description :  Cette fonction détermine si la phase d’arrêt est           */
/*                 interrompue alors que le moteur est encore tournant et que */
/*                 l’on est en phase 2 (ou plus) de la séquence d’arrêt.      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_008.05                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COES_vidCutOffSequenceInterrupt();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input boolean EngReqH_bEngRStrtAutnAvl;                                   */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input uint8 CoEs_tCo_nLimIntr_A[8];                                       */
/*  input uint16 CoEs_nLimIntrSTTEs_T[8];                                     */
/*  input boolean CoEs_bCfCdnIntrSTT_C;                                       */
/*  input uint16 CoEs_nEngTthClcFil;                                          */
/*  input boolean CoEs_bEndIntrCdnEngSpd_MP;                                  */
/*  input uint16 CoEs_nEndIntrSTTEs_T[8];                                     */
/*  input boolean CoEs_bDlyEndIntrHiSpd_MP;                                   */
/*  input uint16 COES_u16TiDlyIntrSTTEsHiEngSpd;                              */
/*  input boolean CoEs_bIntrSTTEsHiEngSpdPrev;                                */
/*  input uint16 CoEs_tiDlyIntrSTTEsHiEngSpd_C;                               */
/*  input boolean CoEs_bDlyEndIntrLoSpd_MP;                                   */
/*  input uint16 COES_u16TiDlyIntrSTTEsLoEngSpd;                              */
/*  input boolean CoEs_bIntrSTTEsLoEngSpdPrev;                                */
/*  input uint16 CoEs_tiDlyIntrSTTEsLoEngSpd_C;                               */
/*  input boolean CoEs_bAcvIntrCdnEngRun_C;                                   */
/*  input boolean CoEs_bEngStopReq;                                           */
/*  input boolean COES_bCoPTStEngRunPrev;                                     */
/*  input boolean CoEs_bAcvIntrCdnNStall_C;                                   */
/*  input boolean CoEs_bIntrSTTEs;                                            */
/*  input boolean CoEs_bCndEngLoLim_MP;                                       */
/*  output boolean CoEs_bCndEngLoLim_MP;                                      */
/*  output boolean CoEs_bEndIntrCdnEngSpd_MP;                                 */
/*  output boolean CoEs_bDlyEndIntrHiSpd_MP;                                  */
/*  output uint16 COES_u16TiDlyIntrSTTEsHiEngSpd;                             */
/*  output boolean CoEs_bIntrSTTEsHiEngSpdPrev;                               */
/*  output boolean CoEs_bDlyEndIntrLoSpd_MP;                                  */
/*  output uint16 COES_u16TiDlyIntrSTTEsLoEngSpd;                             */
/*  output boolean CoEs_bIntrSTTEsLoEngSpdPrev;                               */
/*  output boolean CoEs_bIntrSTTEsHiEngSpd;                                   */
/*  output boolean CoEs_bIntrSTTEsLoEngSpd;                                   */
/*  output boolean COES_bCoPTStEngRunPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidDetecterInterrupSeqArret(void)
{
   /*F05_01_detecter_interruption_sequence_arret*/
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalEnd_CoPTStEngRun;
   boolean bLocalEngReqH_bEngRStrtAutnAvl;
   boolean bLocalCoEs_bIntrSTTEsHiEngSpd;
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   boolean bLocalEndIntrCdnEngSpdMPPrev;
   boolean bLocalDlyEndIntrHiSpdMPPrev;
   boolean bLocalDlyEndIntrLoSpdMPPrev;
   boolean bLocalTriggerEndIntrCdnEngSpd_MP;
   boolean bLocalTriggerDlyEndIntrHiSpd_MP;
   boolean bLocalTriggerDlyEndIntrLoSpd_MP;
   uint8   u8LocalExttCoMes;
   uint16  u16LocalParaX1;
   uint16  u16LocalInter1D1;
   uint16  u16LocalInter1D2;
   uint16  u16LocalTiDlyIntrSTTEsHiEngSpd;
   uint16  u16LocalTiDlyIntrSTTEsLoEngSpd;
   sint16  s16LocalExt_tCoMes;
   sint32  s32LocalExttCoMes;


   /* Get all inputs */
   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   VEMS_vidGET(EngReqH_bEngRStrtAutnAvl, bLocalEngReqH_bEngRStrtAutnAvl);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, bLocalCoEs_bIntrSTTEsHiEngSpd);
   VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, bLocalCoEs_bIntrSTTEsLoEngSpd);

   /* Calcul of CoEs_bCndEngLoLim_MP */
   s32LocalExttCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExttCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExttCoMes, 0, 255);
   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU8(CoEs_tCo_nLimIntr_A,
                                                u8LocalExttCoMes,
                                                8);
   u16LocalInter1D1 = MATHSRV_u16Interp1d(CoEs_nLimIntrSTTEs_T, u16LocalParaX1);

   if (CoEs_bCfCdnIntrSTT_C != 0)
   {
      CoEs_bCndEngLoLim_MP = bLocalEngReqH_bEngRStrtAutnAvl;
   }
   else
   {
      if (CoEs_nEngTthClcFil >= u16LocalInter1D1)
      {
         CoEs_bCndEngLoLim_MP = 1;
      }
      else
      {
         CoEs_bCndEngLoLim_MP = 0;
      }
   }

   /* Calcul of CoEs_bEndIntrCdnEngSpd_MP */
   bLocalEndIntrCdnEngSpdMPPrev = CoEs_bEndIntrCdnEngSpd_MP;
   u16LocalInter1D2 = MATHSRV_u16Interp1d(CoEs_nEndIntrSTTEs_T, u16LocalParaX1);
   if (CoEs_nEngTthClcFil >= u16LocalInter1D2)
   {
      CoEs_bEndIntrCdnEngSpd_MP = 1;
   }
   else
   {
      CoEs_bEndIntrCdnEngSpd_MP = 0;
   }

   /* Calcul of CoEs_bDlyEndIntrHiSpd_MP */
   bLocalDlyEndIntrHiSpdMPPrev = CoEs_bDlyEndIntrHiSpd_MP;
   u16LocalTiDlyIntrSTTEsHiEngSpd = COES_u16TiDlyIntrSTTEsHiEngSpd;
   if (bLocalCoEs_bIntrSTTEsHiEngSpd != 0)
   {
      if (CoEs_bIntrSTTEsHiEngSpdPrev == 0)
      {
         u16LocalTiDlyIntrSTTEsHiEngSpd = CoEs_tiDlyIntrSTTEsHiEngSpd_C;
      }
      else
      {
         if (u16LocalTiDlyIntrSTTEsHiEngSpd > 0)
         {
            u16LocalTiDlyIntrSTTEsHiEngSpd =
               (uint16)(u16LocalTiDlyIntrSTTEsHiEngSpd - 1);
         }
      }
      if (u16LocalTiDlyIntrSTTEsHiEngSpd == 0)
      {
         CoEs_bDlyEndIntrHiSpd_MP = 1;
      }
      else
      {
         CoEs_bDlyEndIntrHiSpd_MP = 0;
      }
   }
   else
   {
      CoEs_bDlyEndIntrHiSpd_MP = 0;
   }
   COES_u16TiDlyIntrSTTEsHiEngSpd =
      (uint16)MATHSRV_udtMIN(u16LocalTiDlyIntrSTTEsHiEngSpd, 1000);
   CoEs_bIntrSTTEsHiEngSpdPrev = bLocalCoEs_bIntrSTTEsHiEngSpd;

   /* Calcul of CoEs_bDlyEndIntrLoSpd_MP */
   bLocalDlyEndIntrLoSpdMPPrev = CoEs_bDlyEndIntrLoSpd_MP;
   u16LocalTiDlyIntrSTTEsLoEngSpd = COES_u16TiDlyIntrSTTEsLoEngSpd;
   if (bLocalCoEs_bIntrSTTEsLoEngSpd != 0)
   {
      if (CoEs_bIntrSTTEsLoEngSpdPrev == 0)
      {
         u16LocalTiDlyIntrSTTEsLoEngSpd = CoEs_tiDlyIntrSTTEsLoEngSpd_C;
      }
      else
      {
         if (u16LocalTiDlyIntrSTTEsLoEngSpd > 0)
         {
            u16LocalTiDlyIntrSTTEsLoEngSpd =
               (uint16)(u16LocalTiDlyIntrSTTEsLoEngSpd - 1);
         }
      }
      if (u16LocalTiDlyIntrSTTEsLoEngSpd == 0)
      {
         CoEs_bDlyEndIntrLoSpd_MP = 1;
      }
      else
      {
         CoEs_bDlyEndIntrLoSpd_MP = 0;
      }
   }
   else
   {
      CoEs_bDlyEndIntrLoSpd_MP = 0;
   }
   COES_u16TiDlyIntrSTTEsLoEngSpd =
      (uint16)MATHSRV_udtMIN(u16LocalTiDlyIntrSTTEsLoEngSpd, 1000);
   CoEs_bIntrSTTEsLoEngSpdPrev = bLocalCoEs_bIntrSTTEsLoEngSpd;

   /* Call of the blo F05_01_01_Cut_Off_sequence_interruptionck  */
   COES_vidCutOffSequenceInterrupt();

   /* Calcul of the trigger of CoEs_bEndIntrCdnEngSpd_MP */
   bLocalTriggerEndIntrCdnEngSpd_MP = 0;
   if (  (CoEs_bEndIntrCdnEngSpd_MP != 0)
      && (bLocalEndIntrCdnEngSpdMPPrev == 0))
   {
      bLocalTriggerEndIntrCdnEngSpd_MP = 1;
   }

   /* Calcul of the trigger of CoEs_bDlyEndIntrHiSpd_MP */
   bLocalTriggerDlyEndIntrHiSpd_MP = 0;
   if (  (CoEs_bDlyEndIntrHiSpd_MP != 0)
      && (bLocalDlyEndIntrHiSpdMPPrev == 0))
   {
      bLocalTriggerDlyEndIntrHiSpd_MP = 1;
   }

   /* Calcul of the trigger of CoEs_bDlyEndIntrLoSpd_MP */
   bLocalTriggerDlyEndIntrLoSpd_MP = 0;
   if (  (CoEs_bDlyEndIntrLoSpd_MP != 0)
      && (bLocalDlyEndIntrLoSpdMPPrev == 0))
   {
      bLocalTriggerDlyEndIntrLoSpd_MP = 1;
   }

   if (  (bLocalCoPTSt_bEngRun != 0)
      && (CoEs_bAcvIntrCdnEngRun_C != 0))
   {
      bLocalEnd_CoPTStEngRun = 1;
   }
   else
   {
      bLocalEnd_CoPTStEngRun = 0;
   }
   /* Calcul of CoEs_bIntrSTTEsHiEngSpd and CoEs_bIntrSTTEsLoEngSpd */
   if ( (CoEs_bEngStopReq != 0)
      || (  (bLocalEnd_CoPTStEngRun != 0)
         && (COES_bCoPTStEngRunPrev == 0))
      || (  (CoEs_nEngTthClcFil == 0)
         && (CoEs_bAcvIntrCdnNStall_C != 0))
      || (bLocalTriggerEndIntrCdnEngSpd_MP != 0)
      || (bLocalTriggerDlyEndIntrHiSpd_MP != 0)
      || (bLocalTriggerDlyEndIntrLoSpd_MP != 0))
   {
      VEMS_vidSET(CoEs_bIntrSTTEsHiEngSpd, 0);
      VEMS_vidSET(CoEs_bIntrSTTEsLoEngSpd, 0);
   }
   else
   {
      if (CoEs_bIntrSTTEs != 0)
      {
         if (CoEs_bCndEngLoLim_MP != 0)
         {
            VEMS_vidSET(CoEs_bIntrSTTEsHiEngSpd, 1);
         }
         else
         {
            VEMS_vidSET(CoEs_bIntrSTTEsLoEngSpd, 1);
         }
      }
   }

   COES_bCoPTStEngRunPrev = bLocalEnd_CoPTStEngRun;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidCutOffSequenceInterrupt                            */
/* !Description :  cette fonction détermine si le prochain redémarrage doit   */
/*                 être normal  ou des séquences d'interruption .             */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoStrtRStrt_stEngStrtReq;                                     */
/*  input uint16 CoEs_nEngTthClcFil;                                          */
/*  input uint16 COES_u16CoEs_nEngTthClcFilPrev;                              */
/*  input uint8 CoEs_tiDlyVldNNull_C;                                         */
/*  input uint16 COES_u16Counter_CoEs_bIntrSTTEs;                             */
/*  input boolean CoEs_bCutActrSTTEs;                                         */
/*  input uint8 COES_u8CoStrtRStrtStEngStrtPrev;                              */
/*  input boolean COES_bCutOffSeqInterrupRS;                                  */
/*  output uint16 COES_u16Counter_CoEs_bIntrSTTEs;                            */
/*  output boolean COES_bCutOffSeqInterrupRS;                                 */
/*  output boolean CoEs_bIntrSTTEs;                                           */
/*  output uint16 COES_u16CoEs_nEngTthClcFilPrev;                             */
/*  output uint8 COES_u8CoStrtRStrtStEngStrtPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidCutOffSequenceInterrupt(void)
{
   boolean bLocalTurnON;
   uint8   u8LocalCoStrtRStrt_stEngStrtReq;


   VEMS_vidGET(CoStrtRStrt_stEngStrtReq, u8LocalCoStrtRStrt_stEngStrtReq);

   /*** Begin Bloc TURN_ON_DELAY ***/
   if (CoEs_nEngTthClcFil == 0)
   {
      if (COES_u16CoEs_nEngTthClcFilPrev != 0)
      {
         COES_u16Counter_CoEs_bIntrSTTEs =
            (uint16)(((CoEs_tiDlyVldNNull_C * 5) + 1) / 2);
      }
      else
      {
         if (COES_u16Counter_CoEs_bIntrSTTEs > 0)
         {
            COES_u16Counter_CoEs_bIntrSTTEs =
               (uint16)(COES_u16Counter_CoEs_bIntrSTTEs - 1);
         }
      }
      if (COES_u16Counter_CoEs_bIntrSTTEs == 0)
      {
         bLocalTurnON = 1;
      }
      else
      {
         bLocalTurnON = 0;
      }
   }
   else
   {
      bLocalTurnON = 0;
   }
   /*** End Bloc TURN_ON_DELAY ***/

   if (bLocalTurnON != 0)
   {
      COES_bCutOffSeqInterrupRS = 0;
   }
   else
   {
      if (CoEs_bCutActrSTTEs != 0)
      {
         COES_bCutOffSeqInterrupRS = 1;
      }
   }
   if ( (  (u8LocalCoStrtRStrt_stEngStrtReq == 2)
        && (COES_u8CoStrtRStrtStEngStrtPrev != 2))
      && (COES_bCutOffSeqInterrupRS != 0))
   {
      CoEs_bIntrSTTEs = 1;
   }
   else
   {
      CoEs_bIntrSTTEs = 0;
   }
   COES_u16CoEs_nEngTthClcFilPrev =
      (uint16)MATHSRV_udtMIN(CoEs_nEngTthClcFil, 2000);
   COES_u8CoStrtRStrtStEngStrtPrev =
      (uint8)MATHSRV_udtMIN(u8LocalCoStrtRStrt_stEngStrtReq, 7);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidImposerDelaiActivVanos                             */
/* !Description :  Cette fonction applique un délai calibrable durant         */
/*                 laquelle on maintient les vanos sur leur position décroisé */
/*                 de verrouillage lors d’une interruption de la séquence     */
/*                 d’arrêt.                                                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input boolean CoEs_btiDlyCmdVlvSysIntrSTTEPrev;                           */
/*  input uint16 CoEs_tiDlyCmdVlvSysIntrSTTEs_C;                              */
/*  input uint16 COES_u16TiDlyCmdVlvSysIntrSTTEs;                             */
/*  input boolean CoEs_bAcvVlvSysLockPosnSTTEs_MP;                            */
/*  input boolean CoEs_bCmdActrSTTEs;                                         */
/*  output uint16 COES_u16TiDlyCmdVlvSysIntrSTTEs;                            */
/*  output boolean CoEs_bAcvVlvSysLockPosnSTTEs_MP;                           */
/*  output boolean CoEs_btiDlyCmdVlvSysIntrSTTEPrev;                          */
/*  output boolean CoEs_bPctlAcvVlvSysLockPosnSTTEs;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidImposerDelaiActivVanos(void)
{
   /*F05_02_imposer_delai_activation_vanos*/
   boolean bLocalInputTurnOnDelay;
   boolean bLocalCoEs_bIntrSTTEsHiEngSpd;
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   uint16  u16LocalTiDlyCmdVlvSysIntrSTTEs;


   /*Production of CoEs_bAcvVlvSysLockPosnSTTEs_MP*/
   VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, bLocalCoEs_bIntrSTTEsHiEngSpd);
   VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, bLocalCoEs_bIntrSTTEsLoEngSpd);

   if (  (bLocalCoEs_bIntrSTTEsHiEngSpd != 0)
      || (bLocalCoEs_bIntrSTTEsLoEngSpd != 0))
   {
      bLocalInputTurnOnDelay = 1;
   }
   else
   {
      bLocalInputTurnOnDelay = 0;
   }

   if (bLocalInputTurnOnDelay != 0)
   {
      if (CoEs_btiDlyCmdVlvSysIntrSTTEPrev == 0)
      {
         COES_u16TiDlyCmdVlvSysIntrSTTEs =
            (uint16)MATHSRV_udtMIN(CoEs_tiDlyCmdVlvSysIntrSTTEs_C, 1000);
      }
      else
      {
         if (COES_u16TiDlyCmdVlvSysIntrSTTEs > 0)
         {
            u16LocalTiDlyCmdVlvSysIntrSTTEs =
               (uint16)(COES_u16TiDlyCmdVlvSysIntrSTTEs - 1);
            COES_u16TiDlyCmdVlvSysIntrSTTEs =
               (uint16)MATHSRV_udtMIN(u16LocalTiDlyCmdVlvSysIntrSTTEs, 1000);
         }
      }
      if (COES_u16TiDlyCmdVlvSysIntrSTTEs == 0)
      {
         CoEs_bAcvVlvSysLockPosnSTTEs_MP = 1;
      }
      else
      {
         CoEs_bAcvVlvSysLockPosnSTTEs_MP = 0;
      }
   }
   else
   {
      CoEs_bAcvVlvSysLockPosnSTTEs_MP = 0;
   }
   CoEs_btiDlyCmdVlvSysIntrSTTEPrev = bLocalInputTurnOnDelay;

   /*Production of CoEs_bPctlAcvVlvSysLockPosnSTTEs*/
   if (bLocalInputTurnOnDelay != 0)
   {
      if (CoEs_bAcvVlvSysLockPosnSTTEs_MP == 0)
      {
         CoEs_bPctlAcvVlvSysLockPosnSTTEs = 1;
      }
      else
      {
         CoEs_bPctlAcvVlvSysLockPosnSTTEs = 0;
      }
   }
   else
   {
      CoEs_bPctlAcvVlvSysLockPosnSTTEs = CoEs_bCmdActrSTTEs;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidImposeDelaiActivCanister                           */
/* !Description :  Cette fonction applique un délai calibrable durant         */
/*                 laquelle on maintient la vanne canister fermée lors d’une  */
/*                 interruption de la séquence d’arrêt.                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_009.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoEs_bIntrSTTEsHiEngSpd;                                    */
/*  input boolean CoEs_bIntrSTTEsLoEngSpd;                                    */
/*  input boolean CoEs_btiDlyCmdCanPurgIntSTTEPrev;                           */
/*  input uint16 CoEs_tiDlyCmdCanPurgIntrSTTEs_C;                             */
/*  input uint16 COES_u16TiDlyCmdCanPurgIntrSTTEs;                            */
/*  input boolean CoEs_bPctlAcvClsCanPurgSTTEs_MP;                            */
/*  input boolean CoEs_bCmdActrSTTEs;                                         */
/*  output uint16 COES_u16TiDlyCmdCanPurgIntrSTTEs;                           */
/*  output boolean CoEs_bPctlAcvClsCanPurgSTTEs_MP;                           */
/*  output boolean CoEs_btiDlyCmdCanPurgIntSTTEPrev;                          */
/*  output boolean CoEs_bPctlAcvClsCanPurgSTTEs;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidImposeDelaiActivCanister(void)
{
   /*F05_03_imposer_delai_activation_canister*/
   boolean bLocalInputTurnOnDelay;
   boolean bLocalCoEs_bIntrSTTEsHiEngSpd;
   boolean bLocalCoEs_bIntrSTTEsLoEngSpd;
   uint16  u16LocalTiDlyCmdCanPurgIntrSTTEs;


   /*Production of CoEs_bPctlAcvClsCanPurgSTTEs_MP*/
   VEMS_vidGET(CoEs_bIntrSTTEsHiEngSpd, bLocalCoEs_bIntrSTTEsHiEngSpd);
   VEMS_vidGET(CoEs_bIntrSTTEsLoEngSpd, bLocalCoEs_bIntrSTTEsLoEngSpd);

   if (  (bLocalCoEs_bIntrSTTEsHiEngSpd != 0)
      || (bLocalCoEs_bIntrSTTEsLoEngSpd != 0))
   {
      bLocalInputTurnOnDelay = 1;
   }
   else
   {
      bLocalInputTurnOnDelay = 0;
   }

   if (bLocalInputTurnOnDelay != 0)
   {
      if (CoEs_btiDlyCmdCanPurgIntSTTEPrev == 0)
      {
         COES_u16TiDlyCmdCanPurgIntrSTTEs =
            (uint16)MATHSRV_udtMIN(CoEs_tiDlyCmdCanPurgIntrSTTEs_C, 1000);
      }
      else
      {
         if (COES_u16TiDlyCmdCanPurgIntrSTTEs > 0)
         {
            u16LocalTiDlyCmdCanPurgIntrSTTEs =
               (uint16)(COES_u16TiDlyCmdCanPurgIntrSTTEs - 1);
            COES_u16TiDlyCmdCanPurgIntrSTTEs =
               (uint16)MATHSRV_udtMIN(u16LocalTiDlyCmdCanPurgIntrSTTEs, 1000);
         }
      }
      if (COES_u16TiDlyCmdCanPurgIntrSTTEs == 0)
      {
         CoEs_bPctlAcvClsCanPurgSTTEs_MP = 1;
      }
      else
      {
         CoEs_bPctlAcvClsCanPurgSTTEs_MP = 0;
      }
   }
   else
   {
      CoEs_bPctlAcvClsCanPurgSTTEs_MP = 0;
   }
   CoEs_btiDlyCmdCanPurgIntSTTEPrev = bLocalInputTurnOnDelay;

   /*Production of CoEs_bPctlAcvClsCanPurgSTTEs*/
   if (bLocalInputTurnOnDelay != 0)
   {
      if (CoEs_bPctlAcvClsCanPurgSTTEs_MP == 0)
      {
         CoEs_bPctlAcvClsCanPurgSTTEs = 1;
      }
      else
      {
         CoEs_bPctlAcvClsCanPurgSTTEs = 0;
      }
   }
   else
   {
      CoEs_bPctlAcvClsCanPurgSTTEs = CoEs_bCmdActrSTTEs;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COES_vidFiltrerRegimeDentADent                             */
/* !Description :  Cette fonction filtre via un passe bas du 1er ordre le     */
/*                 régime vilebrequin calculé dent à dent.                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_09_05956_011.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEngToothClc;                                            */
/*  input uint16 CoEs_facFilNEngTth_C;                                        */
/*  input uint32 COES_u32FiltredEngTthClcFilMem;                              */
/*  input boolean CoEs_bCfNEngIntrSTTEs_C;                                    */
/*  input uint16 Ext_nEng;                                                    */
/*  output uint32 COES_u32FiltredEngTthClcFilMem;                             */
/*  output uint16 CoEs_nEngTthClcFil;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COES_vidFiltrerRegimeDentADent(void)
{
   /*F06_Filtrer_regime_dent_a_dent*/
   uint16 u16LocalExt_nEngToothClc;
   uint16 u16LocalCoEs_nEngTthClcFil;
   uint16 u16LocalCoEs_facFilNEngTth;


   VEMS_vidGET(Ext_nEngToothClc, u16LocalExt_nEngToothClc);

   if (CoEs_facFilNEngTth_C < 1000)
   {
      u16LocalCoEs_facFilNEngTth =
         (uint16)( ( (CoEs_facFilNEngTth_C * 65536) + 500) / 1000);

      u16LocalCoEs_nEngTthClcFil =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalCoEs_facFilNEngTth,
                                         &COES_u32FiltredEngTthClcFilMem,
                                         u16LocalExt_nEngToothClc);
   }
   else
   {
      COES_u32FiltredEngTthClcFilMem =
         (uint32)(u16LocalExt_nEngToothClc * 65536);
      u16LocalCoEs_nEngTthClcFil = u16LocalExt_nEngToothClc;
   }
   if (CoEs_bCfNEngIntrSTTEs_C != 0)
   {
      VEMS_vidGET(Ext_nEng, u16LocalCoEs_nEngTthClcFil);
   }
   CoEs_nEngTthClcFil =
      (uint16)MATHSRV_udtMIN(u16LocalCoEs_nEngTthClcFil, 2000);
}
/*------------------------------- end of file --------------------------------*/