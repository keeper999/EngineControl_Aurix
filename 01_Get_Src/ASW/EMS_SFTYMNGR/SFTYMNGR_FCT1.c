/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMNGR                                                */
/* !Description     : SFTYMNGR Component                                      */
/*                                                                            */
/* !Module          : SFTYMNGR                                                */
/* !Description     : SAFETY TMS :SAFETY MANAGER                              */
/*                                                                            */
/* !File            : SFTYMNGR_FCT1.C                                         */
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
/*   1 / SFTYMNGR_vidInitOutput                                               */
/*   2 / SFTYMNGR_vidTraiteMem1                                               */
/*   3 / SFTYMNGR_vidExtraitMem                                               */
/*   4 / SFTYMNGR_vidTraiteNbEcritures                                        */
/*   5 / SFTYMNGR_vidCalcCompteurEscalade                                     */
/*   6 / SFTYMNGR_vidCalculeMiseEnVeille                                      */
/*   7 / SFTYMNGR_vidTraitDelaiRecAntiEsc                                     */
/*   8 / SFTYMNGR_vidCalculeSeuilRPM                                          */
/*   9 / SFTYMNGR_vidAppliqueInhiDefaut                                       */
/*   10 / SFTYMNGR_vidAdaptationEdge                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_FCT1$*/
/* $Revision::   1.16     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SFTYMNGR.h"
#include "SFTYMNGR_l.h"
#include "SFTYMNGR_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation des sorties au reset             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoIrvVSCtlPrev;                                   */
/*  input boolean SftyMgt_bDgoIrvSTTPrev;                                     */
/*  input boolean SftyMgt_bDgoIrvEMPrev;                                      */
/*  input boolean SftyMgt_bKeyOffEdge;                                        */
/*  output boolean SftyMgt_bDgoIrvECU;                                        */
/*  output boolean SftyMgt_bDgoIrvEM;                                         */
/*  output boolean SftyMgt_bDgoIrvEngStop;                                    */
/*  output boolean SftyMgt_bDgoIrvSTT;                                        */
/*  output boolean SftyMgt_bDgoIrvVSCtl;                                      */
/*  output boolean SftyMgt_bDgoRvLih;                                         */
/*  output boolean SftyMgt_bMonRunIrvECU;                                     */
/*  output boolean SftyMgt_bMonRunIrvEM;                                      */
/*  output boolean SftyMgt_bMonRunIrvEngStop;                                 */
/*  output boolean SftyMgt_bMonRunIrvSTT;                                     */
/*  output boolean SftyMgt_bMonRunIrvVSCtl;                                   */
/*  output boolean SftyMgt_bMonRunRvLih;                                      */
/*  output boolean SftyMgt_bRstHwReq;                                         */
/*  output boolean SftyMgt_bRstHwReqAnt;                                      */
/*  output boolean SftyMgt_bRstSwReq;                                         */
/*  output boolean SftyMgt_bRstSwReqAnt;                                      */
/*  output boolean SftyMgt_bInhSTT;                                           */
/*  output uint16 SftyMgt_prm_bDftHisAfts1;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts2;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts3;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts4;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts5;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts6;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts7;                                   */
/*  output uint16 SftyMgt_prm_bDftHisAfts8;                                   */
/*  output boolean SftyMgt_bDftIpEMLadd;                                      */
/*  output boolean SftyMgt_bDftIpSTTLadd;                                     */
/*  output boolean SftyMgt_bDftIpVSCtlLadd;                                   */
/*  output boolean SftyMgt_bDgoIrvECUTmp;                                     */
/*  output boolean SftyMgt_bDgoIrvEMTmp;                                      */
/*  output boolean SftyMgt_bDgoIrvSTTTmp;                                     */
/*  output boolean SftyMgt_bDgoIrvVSCtlTmp;                                   */
/*  output boolean SftyMgt_bDgoSatMemEveDft;                                  */
/*  output boolean SftyMgt_bDgoSatMemEveSat;                                  */
/*  output boolean SftyMgt_bInhDftEdge;                                       */
/*  output boolean SftyMgt_bDgoIrvEdgeVSCtl;                                  */
/*  output boolean SftyMgt_bDgoIrvEdgeSTT;                                    */
/*  output boolean SftyMgt_bDgoIrvEdgeEM;                                     */
/*  output boolean SftyMgt_bDgoIrvEdgeECU;                                    */
/*  output uint8 SftyMgt_ctDftLaddEveDft;                                     */
/*  output uint8 SftyMgt_ctDftLaddEveKeyOff;                                  */
/*  output boolean SftyMgt_bDgoSatMemEveKeyOff;                               */
/*  output boolean SftyMgt_bEveKeyOffWrMem;                                   */
/*  output uint16 SftyMgt_ctWrMemEveDft;                                      */
/*  output uint16 SftyMgt_ctWrMemEveKeyOff;                                   */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev1;                                */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev2;                                */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev3;                                */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev4;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev1;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev2;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev3;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev4;                                */
/*  output boolean SFTYMNGR_bExtKeyOffPrev;                                   */
/*  output boolean SFTYMNGR_bSftyEngStopReqPrev;                              */
/*  output boolean SFTYMNGR_bSfty3RstHwReqPrev;                               */
/*  output boolean SFTYMNGR_bResetAutomate;                                   */
/*  output boolean SftyMgt_bDgoIni;                                           */
/*  output boolean SftyMgt_bPresentInitVar;                                   */
/*  output st103 SFTYMNGR_stEscaladeDefautsState;                             */
/*  output uint16 SFTYMNGR_u16RstTurnOffDlySmpl;                              */
/*  output uint16 SFTYMNGR_u16CntTurnOffDlySmpl;                              */
/*  output uint32 SftyMgt_prm_bDftHisEveDft[4];                               */
/*  output uint16 SftyMgt_prm_bFrfEveDft[8];                                  */
/*  output uint32 SftyMgt_prm_bDftHisEveKeyOff[4];                            */
/*  output uint16 SftyMgt_prm_bFrfEveKeyOff[8];                               */
/*  output st101 SFTYMNGR_stDiagVSCtlState;                                   */
/*  output st102 SFTYMNGR_stDiagSTTState;                                     */
/*  output st104 SFTYMNGR_stDiagEMState;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidInitOutput(void)
{
   boolean bLocalSftyMgtDgoIrvEMPrev;
   boolean bLocalSftyMgtDgoIrvSTTPrev;
   boolean bLocalSftyMgtDgoIrvVSCtlPrev;
   uint8   u8LocalInd;


   VEMS_vidGET(SftyMgt_bDgoIrvVSCtlPrev, bLocalSftyMgtDgoIrvVSCtlPrev);
   VEMS_vidGET(SftyMgt_bDgoIrvSTTPrev, bLocalSftyMgtDgoIrvSTTPrev);
   VEMS_vidGET(SftyMgt_bDgoIrvEMPrev, bLocalSftyMgtDgoIrvEMPrev);
   VEMS_vidSET(SftyMgt_bDgoIrvECU, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvEM, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvEngStop, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvSTT, 0);
   VEMS_vidSET(SftyMgt_bDgoIrvVSCtl, 0);
   VEMS_vidSET(SftyMgt_bDgoRvLih, 0);
   VEMS_vidSET(SftyMgt_bMonRunIrvECU, 0);
   VEMS_vidSET(SftyMgt_bMonRunIrvEM, 0);
   VEMS_vidSET(SftyMgt_bMonRunIrvEngStop, 0);
   VEMS_vidSET(SftyMgt_bMonRunIrvSTT, 0);
   VEMS_vidSET(SftyMgt_bMonRunIrvVSCtl, 0);
   VEMS_vidSET(SftyMgt_bMonRunRvLih, 0);
   VEMS_vidSET(SftyMgt_bRstHwReq, 0);
   VEMS_vidSET(SftyMgt_bRstHwReqAnt, 0);
   VEMS_vidSET(SftyMgt_bRstSwReq, 0);
   VEMS_vidSET(SftyMgt_bRstSwReqAnt, 0);
   VEMS_vidSET(SftyMgt_bInhSTT, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts1, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts2, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts3, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts4, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts5, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts6, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts7, 0);
   VEMS_vidSET(SftyMgt_prm_bDftHisAfts8, 0);
   SftyMgt_bDftIpEMLadd = 0;
   SftyMgt_bDftIpSTTLadd = 0;
   SftyMgt_bDftIpVSCtlLadd = 0;
   SftyMgt_bDgoIrvECUTmp = 0;
   SftyMgt_bDgoIrvEMTmp = 0;
   SftyMgt_bDgoIrvSTTTmp = 0;
   SftyMgt_bDgoIrvVSCtlTmp = 0;
   SftyMgt_bDgoSatMemEveDft = 0;
   SftyMgt_bDgoSatMemEveSat = 0;
   SftyMgt_bInhDftEdge = 0;
   SftyMgt_bDgoIrvEdgeVSCtl = 0;
   SftyMgt_bDgoIrvEdgeSTT = 0;
   SftyMgt_bDgoIrvEdgeEM = 0;
   SftyMgt_bDgoIrvEdgeECU = 0;
   SftyMgt_ctDftLaddEveDft = 0;
   SftyMgt_ctDftLaddEveKeyOff = 0;
   SftyMgt_bDgoSatMemEveKeyOff = 0;
   SftyMgt_bEveKeyOffWrMem = 0;
   SftyMgt_ctWrMemEveDft = 0;
   SftyMgt_ctWrMemEveKeyOff = 0;
   SFTYMNGR_bRstHwReqAntPrev1 = 0;
   SFTYMNGR_bRstHwReqAntPrev2 = 0;
   SFTYMNGR_bRstHwReqAntPrev3 = 0;
   SFTYMNGR_bRstHwReqAntPrev4 = 0;
   SFTYMNGR_bRstSwReqAntPrev1 = 0;
   SFTYMNGR_bRstSwReqAntPrev2 = 0;
   SFTYMNGR_bRstSwReqAntPrev3 = 0;
   SFTYMNGR_bRstSwReqAntPrev4 = 0;
   SFTYMNGR_bExtKeyOffPrev = 1;
   SFTYMNGR_bSftyEngStopReqPrev = 1;
   SFTYMNGR_bSfty3RstHwReqPrev = 1;
   SFTYMNGR_bResetAutomate = 0;
   SftyMgt_bDgoIni = 0;
   SftyMgt_bPresentInitVar = 1;
   SFTYMNGR_stEscaladeDefautsState = DEFAUT_INACTIF;
   SFTYMNGR_u16RstTurnOffDlySmpl = 0;
   SFTYMNGR_u16CntTurnOffDlySmpl = 0;

   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisEveDft[u8LocalInd] = 0;
   }
   for(u8LocalInd = 0; u8LocalInd < 8; u8LocalInd++)
   {
      SftyMgt_prm_bFrfEveDft[u8LocalInd] = 0;
   }

   for(u8LocalInd = 0; u8LocalInd < 4; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisEveKeyOff[u8LocalInd] = 0;
   }
   for(u8LocalInd = 0; u8LocalInd < 8; u8LocalInd++)
   {
      SftyMgt_prm_bFrfEveKeyOff[u8LocalInd] = 0;
   }

   if (  (bLocalSftyMgtDgoIrvVSCtlPrev != 0)
      && (SftyMgt_bKeyOffEdge == 0) )
   {
      SFTYMNGR_stDiagVSCtlState = IRV_VSCTL;
   }
   else
   {
      SFTYMNGR_stDiagVSCtlState = NOMINAL_VSCTL;
   }

   if (  (bLocalSftyMgtDgoIrvSTTPrev != 0)
      && (SftyMgt_bKeyOffEdge == 0) )
   {
      SFTYMNGR_stDiagSTTState = IRV_STT;
   }
   else
   {
      SFTYMNGR_stDiagSTTState = NOMINAL_STT;
   }

   if (  (bLocalSftyMgtDgoIrvEMPrev != 0)
      && (SftyMgt_bKeyOffEdge == 0) )
   {
      SFTYMNGR_stDiagEMState = IRV_EM;
   }
   else
   {
      SFTYMNGR_stDiagEMState = NOMINAL_EM;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraiteMem1                                     */
/* !Description :  traiter  le nombre d’écriture effectuées dans la mémoire   */
/*                 sauvegardée                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_052.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidExtraitMem();                                */
/*  extf argret void SFTYMNGR_vidTraiteNbEcritures();                         */
/*  extf argret void SFTYMNGR_vidCalcCompteurEscalade();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraiteMem1(void)
{
   SFTYMNGR_vidExtraitMem();
   SFTYMNGR_vidTraiteNbEcritures();
   SFTYMNGR_vidCalcCompteurEscalade();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidExtraitMem                                     */
/* !Description :  extraire les données de la mémoire                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint16 ECU_ctWrMem;                                                 */
/*  input uint32 ECU_prm_bDftHis[4];                                          */
/*  input uint16 ECU_prm_bFrf[8];                                             */
/*  output uint16 SftyMgt_ctWrMemOld;                                         */
/*  output uint32 SftyMgt_prm_bDftHisOld[4];                                  */
/*  output uint16 SftyMgt_prm_bFrfOld[8];                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidExtraitMem(void)
{
   uint8  u8LocalInd;
   uint16 u16LocalECUctWrMem;
   uint16 u16LocalECUprmbFrf[8];
   /*QAC Msg(2:3132): declaration umposed by issue VEMS V02 ECU#059998 */
   uint32 u32LocalECUprmbDftHis[4];
   /*QAC Msg(2:3132): declaration umposed by issue VEMS V02 ECU#059998 */


   VEMS_vidGET(ECU_ctWrMem,u16LocalECUctWrMem);
   VEMS_vidGET1DArray(ECU_prm_bDftHis,
                      4,
                      u32LocalECUprmbDftHis);
   VEMS_vidGET1DArray(ECU_prm_bFrf,
                      8,
                      u16LocalECUprmbFrf);

   SftyMgt_ctWrMemOld = (uint16)MATHSRV_udtMIN(u16LocalECUctWrMem, 65000);

   for(u8LocalInd = 0; u8LocalInd < 3; u8LocalInd++)
   {
      SftyMgt_prm_bDftHisOld[u8LocalInd] = u32LocalECUprmbDftHis[u8LocalInd];
   }
   for(u8LocalInd = 0; u8LocalInd < 7; u8LocalInd++)
   {
      SftyMgt_prm_bFrfOld[u8LocalInd] = u16LocalECUprmbFrf[u8LocalInd];
   }
   SftyMgt_prm_bDftHisOld[3] = (u32LocalECUprmbDftHis[3] & 0xFFFFFFF8UL);
   SftyMgt_prm_bFrfOld[7] = (uint16)(u16LocalECUprmbFrf[7] & 0xFF00);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraiteNbEcritures                              */
/* !Description :  Comparer le nombre d’écriture effectuées dans la mémoire   */
/*                 sauvegardée à un seuil d’écriture autorisées.              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_ctWrMemOld;                                          */
/*  input uint16 SftyMgt_ctStopWrMemThd_C;                                    */
/*  output boolean SftyMgt_bEnaWrMem;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraiteNbEcritures(void)
{
   if (SftyMgt_ctWrMemOld < SftyMgt_ctStopWrMemThd_C)
   {
      SftyMgt_bEnaWrMem = 1;
   }
   else
   {
      SftyMgt_bEnaWrMem = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCalcCompteurEscalade                           */
/* !Description :  calcul du Compteur de l'echelle des défauts ECU            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ECU_ctDftLadd;                                                */
/*  input boolean SftyMgt_bEnaWrMem;                                          */
/*  output uint8 SftyMgt_ctDftLaddCord;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCalcCompteurEscalade(void)
{
   uint8 u8LocalECUctDftLadd;


   VEMS_vidGET(ECU_ctDftLadd,u8LocalECUctDftLadd);
   if (SftyMgt_bEnaWrMem != 0)
   {
      SftyMgt_ctDftLaddCord = (uint8)MATHSRV_udtMIN(u8LocalECUctDftLadd, 9);
   }
   else
   {
      SftyMgt_ctDftLaddCord = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCalculeMiseEnVeille                            */
/* !Description :  Gere l’inhibition de l’écoute des défauts                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidCalculeSeuilRPM();                           */
/*  extf argret void SFTYMNGR_vidTraitDelaiRecAntiEsc();                      */
/*  extf argret void SFTYMNGR_vidAppliqueInhiDefaut();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCalculeMiseEnVeille(void)
{
   SFTYMNGR_vidCalculeSeuilRPM();
   SFTYMNGR_vidTraitDelaiRecAntiEsc();
   SFTYMNGR_vidAppliqueInhiDefaut();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitDelaiRecAntiEsc                           */
/* !Description :  traitement du Dela de iRecouvrement AntiEscalade           */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_011.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sfty3_bEndRcvRun;                                           */
/*  input uint8 SftyMgt_tiDlyInhDftIpECULadd_C;                               */
/*  input boolean SftyMgt_bInhDftEdge;                                        */
/*  input uint16 SFTYMNGR_u16RstTurnOffDlySmpl;                               */
/*  input uint16 SFTYMNGR_u16CntTurnOffDlySmpl;                               */
/*  output uint16 SFTYMNGR_u16CntTurnOffDlySmpl;                              */
/*  output uint16 SFTYMNGR_u16RstTurnOffDlySmpl;                              */
/*  output boolean SftyMgt_bInhDftIpECULadd;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitDelaiRecAntiEsc(void)
{
   boolean bLocalSftyMgtInhDftIpECULadd;
   boolean bLocalSfty3EndRcvRun;
   uint16  u16LocalSumTurnOffDelaySimple;
   uint16  u16LocalMinTurnOffDelaySimple;


   VEMS_vidGET(Sfty3_bEndRcvRun, bLocalSfty3EndRcvRun);
   u16LocalSumTurnOffDelaySimple = (uint16)(SftyMgt_tiDlyInhDftIpECULadd_C + 1);

   if (SftyMgt_bInhDftEdge != 0)
   {
      SFTYMNGR_u16CntTurnOffDlySmpl = 0;
   }
   else
   {
      u16LocalMinTurnOffDelaySimple =
         (uint16)MATHSRV_udtMIN(SFTYMNGR_u16RstTurnOffDlySmpl,
                                u16LocalSumTurnOffDelaySimple);
      SFTYMNGR_u16CntTurnOffDlySmpl =
         (uint16)(u16LocalMinTurnOffDelaySimple + 1);
   }

   if (bLocalSfty3EndRcvRun != 0)
   {
      SFTYMNGR_u16RstTurnOffDlySmpl = SftyMgt_tiDlyInhDftIpECULadd_C;
   }
   else
   {
      SFTYMNGR_u16RstTurnOffDlySmpl = SFTYMNGR_u16CntTurnOffDlySmpl;
   }

   if (SFTYMNGR_u16CntTurnOffDlySmpl >= u16LocalSumTurnOffDelaySimple)
   {
      bLocalSftyMgtInhDftIpECULadd = 0;
   }
   else
   {
      bLocalSftyMgtInhDftIpECULadd = 1;
   }

   if (SftyMgt_tiDlyInhDftIpECULadd_C != 0)
   {
      SftyMgt_bInhDftIpECULadd = bLocalSftyMgtInhDftIpECULadd;
   }
   else
   {
      SftyMgt_bInhDftIpECULadd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCalculeSeuilRPM                                */
/* !Description :  Calcul du seuil RPM                                        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input boolean SftyMgt_bInhDftIpECU_nEng_C;                                */
/*  input uint16 SftyMgt_nEngInhDftIpECUThd_C;                                */
/*  input boolean SftyMgt_bInhDftAutChk_nEng_C;                               */
/*  input uint16 SftyMgt_nEngInhDftIpAutChkThd_C;                             */
/*  output boolean SftyMgt_bInhDftIpECU_nEng;                                 */
/*  output boolean SftyMgt_bInhDftIpAutChkPrioNEng;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCalculeSeuilRPM(void)
{
   uint16 u16LocalSftyMgtEng;


   VEMS_vidGET(SftyMgt_nEng,u16LocalSftyMgtEng);
   if (SftyMgt_bInhDftIpECU_nEng_C != 0)
   {
      SftyMgt_bInhDftIpECU_nEng = 0;
   }
   else
   {
      if (u16LocalSftyMgtEng <= SftyMgt_nEngInhDftIpECUThd_C)
      {
         SftyMgt_bInhDftIpECU_nEng = 1;
      }
      else
      {
         SftyMgt_bInhDftIpECU_nEng = 0;
      }
   }

   if (SftyMgt_bInhDftAutChk_nEng_C != 0)
   {
      SftyMgt_bInhDftIpAutChkPrioNEng = 0;
   }
   else
   {
      if (u16LocalSftyMgtEng >= SftyMgt_nEngInhDftIpAutChkThd_C)
      {
         SftyMgt_bInhDftIpAutChkPrioNEng = 1;
      }
      else
      {
         SftyMgt_bInhDftIpAutChkPrioNEng = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidAppliqueInhiDefaut                             */
/* !Description :  appliquer Inhibition des Defauts                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_013.02                                     */
/*                 VEMS_R_10_01256_051.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bInhDft;                                                */
/*  input boolean SftyMgt_bDgoVSCtl;                                          */
/*  input boolean SftyMgt_bDftSTT;                                            */
/*  input boolean SftyMgt_bDftEM;                                             */
/*  input boolean SftyMgt_bDftECU;                                            */
/*  input boolean SftyMgt_bDftAutChkIni;                                      */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input uint16 SftyMgt_spdVehAftsThd_C;                                     */
/*  input boolean SftyMgt_bInhDftIpECULadd;                                   */
/*  input boolean SftyMgt_bInhDftIpVSCtl_C;                                   */
/*  input boolean SftyMgt_bInhDftIpSTT_C;                                     */
/*  input boolean SftyMgt_bInhDftIpEM_C;                                      */
/*  input boolean SftyMgt_bInhDftIpECU_nEng;                                  */
/*  input boolean SftyMgt_bInhDftIpAutChkIni_C;                               */
/*  input boolean SftyMgt_bInhDftIpAutChkPrioNEng;                            */
/*  output boolean SftyMgt_bDftIpEnaVSCtl;                                    */
/*  output boolean SftyMgt_bDftIpEnaSTT;                                      */
/*  output boolean SftyMgt_bDftIpEnaEM;                                       */
/*  output boolean SftyMgt_bDftIpEnaECU;                                      */
/*  output boolean SftyMgt_bDftIpEnaAutChkPrio;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidAppliqueInhiDefaut(void)
{
   boolean bLocalExtInhDft;
   boolean bLocalSftyMgtDgoVSCtl;
   boolean bLocalSftyMgtDftSTT;
   boolean bLocalSftyMgtDftEM;
   boolean bLocalSftyMgtDftECU;
   boolean bLocalInhDftIpECU;
   boolean bLocalInhDftIpAutChkIni;
   boolean bLocalSftyMgtDftAutChkIni;
   boolean bLocalCalcExtBInhDft;
   uint16  u16LocalSftyMgtSpdVeh;

   VEMS_vidGET(Ext_bInhDft,bLocalExtInhDft);
   VEMS_vidGET(SftyMgt_bDgoVSCtl,bLocalSftyMgtDgoVSCtl);
   VEMS_vidGET(SftyMgt_bDftSTT,bLocalSftyMgtDftSTT);
   VEMS_vidGET(SftyMgt_bDftEM,bLocalSftyMgtDftEM);
   VEMS_vidGET(SftyMgt_bDftECU,bLocalSftyMgtDftECU);
   VEMS_vidGET(SftyMgt_bDftAutChkIni,bLocalSftyMgtDftAutChkIni);
   VEMS_vidGET(SftyMgt_spdVeh,u16LocalSftyMgtSpdVeh);

   if(  (u16LocalSftyMgtSpdVeh <= SftyMgt_spdVehAftsThd_C)
     && (bLocalExtInhDft != 0))
   {
      bLocalCalcExtBInhDft = 1;
   }
   else
   {
      bLocalCalcExtBInhDft = 0;
   }
   if (  (bLocalCalcExtBInhDft != 0)
      || (SftyMgt_bInhDftIpECULadd != 0)
      || (SftyMgt_bInhDftIpVSCtl_C != 0) )
   {
      SftyMgt_bDftIpEnaVSCtl = 0;
   }
   else
   {
      SftyMgt_bDftIpEnaVSCtl = bLocalSftyMgtDgoVSCtl;
   }

   if (  (bLocalCalcExtBInhDft != 0)
      || (SftyMgt_bInhDftIpECULadd != 0)
      || (SftyMgt_bInhDftIpSTT_C != 0) )
   {
      SftyMgt_bDftIpEnaSTT = 0;
   }
   else
   {
      SftyMgt_bDftIpEnaSTT = bLocalSftyMgtDftSTT;
   }

   if (  (bLocalCalcExtBInhDft != 0)
      || (SftyMgt_bInhDftIpECULadd != 0)
      || (SftyMgt_bInhDftIpEM_C != 0) )
   {
      SftyMgt_bDftIpEnaEM = 0;
   }
   else
   {
      SftyMgt_bDftIpEnaEM = bLocalSftyMgtDftEM;
   }

   if (  (bLocalCalcExtBInhDft != 0)
      || (SftyMgt_bInhDftIpECULadd != 0)
      || (SftyMgt_bInhDftIpECU_nEng != 0) )
   {
      bLocalInhDftIpECU = 0;
   }
   else
   {
      bLocalInhDftIpECU = bLocalSftyMgtDftECU;
   }

   if (  (bLocalCalcExtBInhDft != 0)
      || (SftyMgt_bInhDftIpECULadd != 0)
      || (SftyMgt_bInhDftIpAutChkIni_C != 0) )
   {
      bLocalInhDftIpAutChkIni = 0;
   }
   else
   {
      bLocalInhDftIpAutChkIni = bLocalSftyMgtDftAutChkIni;
   }

   if (  (bLocalInhDftIpECU != 0)
      || (bLocalInhDftIpAutChkIni != 0) )
   {
      SftyMgt_bDftIpEnaECU = 1;
   }
   else
   {
      SftyMgt_bDftIpEnaECU = 0;
   }

   if (  (bLocalCalcExtBInhDft != 0)
      || (SftyMgt_bInhDftIpAutChkIni_C != 0) )
   {
      SftyMgt_bDftIpEnaAutChkPrio = 0;
   }
   else
   {
      if (SftyMgt_bInhDftIpAutChkPrioNEng != 0)
      {
         SftyMgt_bDftIpEnaAutChkPrio = 0;
      }
      else
      {
         SftyMgt_bDftIpEnaAutChkPrio = bLocalSftyMgtDftAutChkIni;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidAdaptationEdge                                 */
/* !Description :  détection des fronts montants                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bKeyOff;                                                */
/*  input boolean Sfty3_bEngStopReq;                                          */
/*  input boolean Sfty3_bRstHwReq;                                            */
/*  input boolean SFTYMNGR_bExtKeyOffPrev;                                    */
/*  input boolean SFTYMNGR_bSftyEngStopReqPrev;                               */
/*  input boolean SFTYMNGR_bSfty3RstHwReqPrev;                                */
/*  output boolean SftyMgt_bKeyOffEdge;                                       */
/*  output boolean SftyMgt_bSfty3EngStopReqEdge;                              */
/*  output boolean SftyMgt_bSfty3RstHwReqEdge;                                */
/*  output boolean SFTYMNGR_bExtKeyOffPrev;                                   */
/*  output boolean SFTYMNGR_bSftyEngStopReqPrev;                              */
/*  output boolean SFTYMNGR_bSfty3RstHwReqPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidAdaptationEdge(void)
{
   boolean bLocalExtKeyOff;
   boolean bLocalSftyEngStopReq;
   boolean bLocalSfty3RstHwReq;


   VEMS_vidGET(Ext_bKeyOff,bLocalExtKeyOff);
   VEMS_vidGET(Sfty3_bEngStopReq,bLocalSftyEngStopReq);
   VEMS_vidGET(Sfty3_bRstHwReq,bLocalSfty3RstHwReq);

   if (  (SFTYMNGR_bExtKeyOffPrev == 0)
      && (bLocalExtKeyOff != 0) )
   {
      SftyMgt_bKeyOffEdge = 1;
   }
   else
   {
      SftyMgt_bKeyOffEdge = 0;
   }

   if (  (SFTYMNGR_bSftyEngStopReqPrev == 0)
      && (bLocalSftyEngStopReq != 0) )
   {
      SftyMgt_bSfty3EngStopReqEdge = 1;
   }
   else
   {
      SftyMgt_bSfty3EngStopReqEdge = 0;
   }

   if (  (SFTYMNGR_bSfty3RstHwReqPrev == 0)
      && (bLocalSfty3RstHwReq != 0) )
   {
      SftyMgt_bSfty3RstHwReqEdge = 1;
   }
   else
   {
      SftyMgt_bSfty3RstHwReqEdge = 0;
   }

   SFTYMNGR_bExtKeyOffPrev = bLocalExtKeyOff;
   SFTYMNGR_bSftyEngStopReqPrev = bLocalSftyEngStopReq;
   SFTYMNGR_bSfty3RstHwReqPrev = bLocalSfty3RstHwReq;
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/