/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUPEDFREQACQ                                           */
/* !Description     : CLUPEDFREQACQ component.                                */
/*                                                                            */
/* !Module          : CLUPEDFREQACQ                                           */
/* !Description     : ACQUISITION DE LA MESURE DU CAPTEUR D’EMBRAYAGE         */
/*                    PROPORTIONNEL.                                          */
/*                                                                            */
/* !File            : CLUPEDFREQACQ_FCT1.C                                    */
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
/*   1 / CLUPEDFREQACQ_vidInit                                                */
/*   2 / CLUPEDFREQACQ_vidCluPedAcq                                           */
/*   3 / CLUPEDFREQACQ_vidCluPedDiag                                          */
/*   4 / CLUPEDFREQACQ_vidCluPedSel                                           */
/*   5 / CLUPEDFREQACQ_vidAcvCall                                             */
/*   6 / CLUPEDFREQACQ_vidOSCallAcv                                           */
/*   7 / CLUPEDFREQACQ_vidDiagFreq                                            */
/*   8 / CLUPEDFREQACQ_vidDiagGrad                                            */
/*   9 / CLUPEDFREQACQ_vidGDUFreq                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6562175 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CLUPEDFREQACQ/CLUPEDFREQACQ_FCT1.C$*/
/* $Revision::   1.9      $$Author::   achebino       $$Date::   21 May 2014 $*/
/* $Author::   achebino                               $$Date::   21 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CLUPEDFREQACQ.h"
#include "CLUPEDFREQACQ_L.h"
#include "CLUPEDFREQACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidInit                                      */
/* !Description :  Ce bloc permet d’initialiser la position embrayage au      */
/*                 key-on quand le capteur n’est pas encore fonctionnel.      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_09_03204_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bDgoScp_rCluPedPrssMes;                                 */
/*  input boolean Ext_bDgoScg_rCluPedPrssMes;                                 */
/*  input uint16 Ext_rCluPedPrssBrutMes;                                      */
/*  input uint16 Clu_Rco_Bkpt[2];                                             */
/*  input uint16 Clu_PosPed_Map[2];                                           */
/*  output uint16 Ext_rCluPedPrssMes;                                         */
/*  output uint16 Ext_rCluPedPrssBrutMes;                                     */
/*  output uint16 Ext_rCluPedPrssMesPrev;                                     */
/*  output boolean Ext_bDgoScp_rCluPedPrssMes;                                */
/*  output boolean Ext_bDgoScg_rCluPedPrssMes;                                */
/*  output uint8 CLUPEDFREQACQ_u8CntFilt_1;                                   */
/*  output boolean CLUPEDFREQACQ_bFilSig_1;                                   */
/*  output boolean Ext_bDftSftyScg_rCluPedPrssMes;                            */
/*  output uint8 CLUPEDFREQACQ_u8CntFilt_2;                                   */
/*  output boolean CLUPEDFREQACQ_bFilSig_2;                                   */
/*  output boolean Ext_bDftSftyScp_rCluPedPrssMes;                            */
/*  output uint8 Ext_ctDftSftyScp_rCluPedPrssMes;                             */
/*  output uint8 Ext_ctDftSftyScg_rCluPedPrssMes;                             */
/*  output uint16 Clu_rCluPedPrssLnrMesPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidInit(void)
{
   uint16  u16LocalExt_rCluPedPrssBrutMes;
   uint16  u16LocalBKPTSup;
   uint16  u16LocalBKPTInf;
   uint16  u16LocalMapSup;
   uint16  u16LocalMapInf;
   uint16  u16LocalInterpolation;
   uint16  u16LocalSiteInterpolation;
   uint16  u16Local;
   sint32  s32LocalInterpolation;
   uint32  u32LocalDeltaValue;
   uint32  u32LocalInterpolation;
   uint32  u32LocalResultValue;


   VEMS_vidSET(Ext_rCluPedPrssMes, 0);
   VEMS_vidSET(Ext_rCluPedPrssBrutMes, 900);

   Ext_rCluPedPrssMesPrev = 0;
   Ext_bDgoScp_rCluPedPrssMes = 0;
   Ext_bDgoScg_rCluPedPrssMes = 0;
   CLUPEDFREQACQ_u8CntFilt_1 = 0;
   CLUPEDFREQACQ_bFilSig_1 = Ext_bDgoScp_rCluPedPrssMes;
   VEMS_vidSET(Ext_bDftSftyScg_rCluPedPrssMes, 0);
   CLUPEDFREQACQ_u8CntFilt_2 = 0;
   CLUPEDFREQACQ_bFilSig_2 = Ext_bDgoScg_rCluPedPrssMes;
   VEMS_vidSET(Ext_bDftSftyScp_rCluPedPrssMes, 0);
   Ext_ctDftSftyScp_rCluPedPrssMes = 0;
   Ext_ctDftSftyScg_rCluPedPrssMes = 0;

   /* Production of Clu_rCluPedPrssLnrMesPrev*/
   VEMS_vidGET(Ext_rCluPedPrssBrutMes, u16LocalExt_rCluPedPrssBrutMes);
   if (Clu_Rco_Bkpt[1] >= Clu_Rco_Bkpt[0])
   {
      u16LocalBKPTSup = Clu_Rco_Bkpt[1];
      u16LocalBKPTInf = Clu_Rco_Bkpt[0];
      u16LocalMapSup = Clu_PosPed_Map[1];
      u16LocalMapInf = Clu_PosPed_Map[0];
   }
   else
   {
      u16LocalBKPTSup = Clu_Rco_Bkpt[0];
      u16LocalBKPTInf = Clu_Rco_Bkpt[1];
      u16LocalMapSup = Clu_PosPed_Map[0];
      u16LocalMapInf = Clu_PosPed_Map[1];
   }
   if (Clu_Rco_Bkpt[1] != Clu_Rco_Bkpt[0])
   {
      if (u16LocalExt_rCluPedPrssBrutMes >= u16LocalBKPTSup)
      {
         Clu_rCluPedPrssLnrMesPrev =
            (uint16)MATHSRV_udtMIN(u16LocalMapSup, 1024);
      }
      if (u16LocalExt_rCluPedPrssBrutMes < u16LocalBKPTInf)
      {
         Clu_rCluPedPrssLnrMesPrev =
            (uint16)MATHSRV_udtMIN(u16LocalMapInf, 1024);
      }
      if (  (u16LocalExt_rCluPedPrssBrutMes < u16LocalBKPTSup)
         && (u16LocalExt_rCluPedPrssBrutMes >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of u16LocalExt_rCluPedPrssBrutMes with
            Clu_PosPed_Map */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS( u16LocalExt_rCluPedPrssBrutMes
                                  - Clu_Rco_Bkpt[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation =(uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on Clu_PosPed_Map */

         s32LocalInterpolation = (sint32)Clu_PosPed_Map[1] -
                                 (sint32)Clu_PosPed_Map[0];
         u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
         }
         else
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)((sint32)Clu_PosPed_Map[0] + s32LocalInterpolation);
         Clu_rCluPedPrssLnrMesPrev =
            (uint16)MATHSRV_udtMIN((uint16)u32LocalResultValue, (uint16)1024);
      }
   }
   else
   {
      Clu_rCluPedPrssLnrMesPrev =
         (uint16)MATHSRV_udtMIN(Clu_PosPed_Map[0], 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidCluPedAcq                                 */
/* !Description :  L’acquisition du signal est réalisée de façon temporelle,  */
/*                 conformément à l’exigence cliente et débutera dès le réveil*/
/*                 du calculateur.                                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Acqui_pedale_embrayage_pwd_rco;                              */
/*  input uint32 Acqui_pedale_embrayage_pwd_per;                              */
/*  output uint16 Clu_perRateCluPedPrssMes;                                   */
/*  output uint16 Ext_rCluPedPrssBrutMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidCluPedAcq(void)
{
   uint16 u16LocalCluPerRateCluPedPrssMes;
   uint16 u16LocalAcquipedalembpwdrco;
   uint32 u32LocalCluPerRateCluPedPrssMes;


   VEMS_vidGET(Acqui_pedale_embrayage_pwd_rco, u16LocalAcquipedalembpwdrco);
   VEMS_vidGET(Acqui_pedale_embrayage_pwd_per, u32LocalCluPerRateCluPedPrssMes);

   u32LocalCluPerRateCluPedPrssMes = u32LocalCluPerRateCluPedPrssMes / 100;
   u16LocalCluPerRateCluPedPrssMes =
      (uint16)MATHSRV_udtMIN(u32LocalCluPerRateCluPedPrssMes, 65535);
   Clu_perRateCluPedPrssMes = u16LocalCluPerRateCluPedPrssMes;
   u16LocalAcquipedalembpwdrco =
      (uint16)(((u16LocalAcquipedalembpwdrco * 1000) + 16384) / 32768);
   u16LocalAcquipedalembpwdrco =
      (uint16)MATHSRV_udtMIN(u16LocalAcquipedalembpwdrco, 1000);
   VEMS_vidSET(Ext_rCluPedPrssBrutMes, u16LocalAcquipedalembpwdrco);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidCluPedDiag                                */
/* !Description :  Ce bloc énumère les différents court circuits ( à la masse,*/
/*                 au plus) et les gradients qui engendrent un défaut sur le  */
/*                 capteur d’embrayage. Les critères de diagnostics ne sont   */
/*                 pas évalués si les conditions de diagnostics ne sont pas   */
/*                 présentes.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void CLUPEDFREQACQ_vidDiagFreq();                             */
/*  extf argret void CLUPEDFREQACQ_vidDiagGrad();                             */
/*  input boolean Ext_bDgoScp_rCluPedPrssMes;                                 */
/*  input boolean Ext_bDgoScg_rCluPedPrssMes;                                 */
/*  output boolean Ext_bMonRunScp_rCluPedPrssMes;                             */
/*  output boolean Ext_bMonRunScg_rCluPedPrssMes;                             */
/*  output boolean Ext_bMonRunORng_rCluPedPrssMes;                            */
/*  output boolean Ext_bMonRunGrd_rCluPedPrssMes;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidCluPedDiag(void)
{
   boolean bLocalInhDiagCluPedPrssFreqMes;


   bLocalInhDiagCluPedPrssFreqMes =
      GDGAR_bGetFRM(FRM_FRM_INHDIAGCLUPEDPRSSFREQMES);
   if (bLocalInhDiagCluPedPrssFreqMes == 0)
   {
      Ext_bMonRunScp_rCluPedPrssMes = 1;
      Ext_bMonRunScg_rCluPedPrssMes = 1;
      CLUPEDFREQACQ_vidDiagFreq();
      if (  (Ext_bDgoScp_rCluPedPrssMes == 0)
         && (Ext_bDgoScg_rCluPedPrssMes == 0))
      {
         Ext_bMonRunORng_rCluPedPrssMes = 1;
         Ext_bMonRunGrd_rCluPedPrssMes = 1;
         CLUPEDFREQACQ_vidDiagGrad();
      }
      else
      {
         Ext_bMonRunORng_rCluPedPrssMes = 0;
         Ext_bMonRunGrd_rCluPedPrssMes = 0;
      }

   }
   else
   {
      Ext_bMonRunScp_rCluPedPrssMes = 0;
      Ext_bMonRunScg_rCluPedPrssMes = 0;
      Ext_bMonRunORng_rCluPedPrssMes = 0;
      Ext_bMonRunGrd_rCluPedPrssMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidCluPedSel                                 */
/* !Description :  Ce bloc permet de mesurer l'enfoncement pédale d'embrayage */
/*                 acquis par le CMM.                                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_tenuGetStDgo(argin uint16                          */
/*  u16IdxDft)GDFRM_tenuGDUState;                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_rCluPedPrssMes;                                          */
/*  input uint16 Ext_rCluPedPrssMesPrev;                                      */
/*  input uint16 Clu_rCluPedPrssLnrMes;                                       */
/*  input uint16 Clu_rCluPedPrssMesFault_C;                                   */
/*  input uint16 Clu_rCluPedPrssMem;                                          */
/*  output uint16 Ext_rCluPedPrssMesPrev;                                     */
/*  output uint16 Clu_rCluPedPrssMem;                                         */
/*  output uint16 Ext_rCluPedPrssMes;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidCluPedSel(void)
{
   uint16             u16LocalExt_rCluPedPrs;
   uint32             u32LocalExt_rCluPedPrs;
   GDFRM_tenuGDUState LocalstDgoScp_rCluPedPrssMes;
   GDFRM_tenuGDUState LocalstDgoScg_rCluPedPrssMes;
   GDFRM_tenuGDUState LocalstDgoORng_rCluPedPrssMes;
   GDFRM_tenuGDUState LocalstDgoGrd_rCluPedPrssMes;


   LocalstDgoScp_rCluPedPrssMes = GDGAR_tenuGetStDgo(GD_DFT_SCP_RCLUPEDPRSSMES);
   LocalstDgoScg_rCluPedPrssMes = GDGAR_tenuGetStDgo(GD_DFT_SCG_RCLUPEDPRSSMES);
   LocalstDgoORng_rCluPedPrssMes =
      GDGAR_tenuGetStDgo(GD_DFT_ORNG_RCLUPEDPRSSMES);
   LocalstDgoGrd_rCluPedPrssMes = GDGAR_tenuGetStDgo(GD_DFT_GRD_RCLUPEDPRSSMES);
   VEMS_vidGET(Ext_rCluPedPrssMes, u16LocalExt_rCluPedPrs);

   Ext_rCluPedPrssMesPrev = (uint16)MATHSRV_udtMIN(u16LocalExt_rCluPedPrs,
                                                   1024);

   if (  (LocalstDgoScp_rCluPedPrssMes == GDU_ETAT_PCTL_PRESENT)
         || (LocalstDgoScp_rCluPedPrssMes == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoScg_rCluPedPrssMes == GDU_ETAT_PCTL_PRESENT)
         || (LocalstDgoScg_rCluPedPrssMes == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoORng_rCluPedPrssMes == GDU_ETAT_PCTL_PRESENT)
         || (LocalstDgoORng_rCluPedPrssMes == GDU_ETAT_PCTL_ABSENT)
         || (LocalstDgoGrd_rCluPedPrssMes == GDU_ETAT_PCTL_PRESENT)
         || (LocalstDgoGrd_rCluPedPrssMes == GDU_ETAT_PCTL_ABSENT))
   {
      Clu_rCluPedPrssMem = Ext_rCluPedPrssMesPrev;
   }
   else
   {
      Clu_rCluPedPrssMem = (uint16)MATHSRV_udtMIN(Clu_rCluPedPrssLnrMes, 1024);
   }

   if (  (LocalstDgoScp_rCluPedPrssMes == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_rCluPedPrssMes == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoScg_rCluPedPrssMes == GDU_ETAT_PRESENT)
      || (LocalstDgoScg_rCluPedPrssMes == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoORng_rCluPedPrssMes == GDU_ETAT_PRESENT)
      || (LocalstDgoORng_rCluPedPrssMes == GDU_ETAT_DEVALIDATION)
      || (LocalstDgoGrd_rCluPedPrssMes == GDU_ETAT_PRESENT)
      || (LocalstDgoGrd_rCluPedPrssMes == GDU_ETAT_DEVALIDATION))
   {
      u32LocalExt_rCluPedPrs = ((Clu_rCluPedPrssMesFault_C * 128) / 125);
      u16LocalExt_rCluPedPrs = (uint16)MATHSRV_udtMIN(u32LocalExt_rCluPedPrs,
                                                      1024);
      VEMS_vidSET(Ext_rCluPedPrssMes, u16LocalExt_rCluPedPrs);
   }
   else
   {
      VEMS_vidSET(Ext_rCluPedPrssMes, Clu_rCluPedPrssMem);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidAcvCall                                   */
/* !Description :  Fonction  qui fait appel aux fonctions dont l'occurrence   */
/*                 est Clu_SdlMid_CluPedFreqAcq et actives quand              */
/*                 FlowMng_bCluPropSnsrEna = 1.                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUPEDFREQACQ_vidOSCallAcv();                            */
/*  input boolean FlowMng_bCluPropSnsrEna;                                    */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidAcvCall(void)
{
   boolean bLocalFlowMng_bCluPropSnsrEna;
   boolean bLocalDIAGCAN_bIntegratioElec;


   VEMS_vidGET(FlowMng_bCluPropSnsrEna, bLocalFlowMng_bCluPropSnsrEna);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegratioElec);
   if (  (bLocalFlowMng_bCluPropSnsrEna != 0)
      && (bLocalDIAGCAN_bIntegratioElec == 0))
   {
      CLUPEDFREQACQ_vidOSCallAcv();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidOSCallAcv                                 */
/* !Description :  Fonction  qui fait appel aux fonctions dont l'occurrence   */
/*                 est Clu_SdlMid_CluPedFreqAcq                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUPEDFREQACQ_vidCluPedAcq();                            */
/*  extf argret void CLUPEDFREQACQ_vidCluPedLnr();                            */
/*  extf argret void CLUPEDFREQACQ_vidCluPedDiag();                           */
/*  extf argret void CLUPEDFREQACQ_vidGDUFreq();                              */
/*  extf argret void CLUPEDFREQACQ_vidGDUGrad();                              */
/*  extf argret void CLUPEDFREQACQ_vidCluPedSel();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidOSCallAcv(void)
{
   CLUPEDFREQACQ_vidCluPedAcq();
   CLUPEDFREQACQ_vidCluPedLnr();
   CLUPEDFREQACQ_vidCluPedDiag();
   CLUPEDFREQACQ_vidGDUFreq();
   CLUPEDFREQACQ_vidGDUGrad();
   CLUPEDFREQACQ_vidCluPedSel();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidDiagFreq                                  */
/* !Description :  Ce bloc énumère les différents court circuits ( à la masse,*/
/*                 au plus) et les gradients qui engendrent un défaut sur le  */
/*                 capteur d’embrayage.                                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rCluPedPrssBrutMes;                                      */
/*  input uint16 Clu_RcoEmbFreq_Max_C;                                        */
/*  input uint16 Clu_RcoEmbFreq_Min_C;                                        */
/*  output boolean Ext_bDgoScp_rCluPedPrssMes;                                */
/*  output boolean Ext_bDgoScg_rCluPedPrssMes;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidDiagFreq(void)
{
   uint16 u16LocalExt_rCluPedPrssBrutMes;


   VEMS_vidGET(Ext_rCluPedPrssBrutMes, u16LocalExt_rCluPedPrssBrutMes);

   if (u16LocalExt_rCluPedPrssBrutMes > Clu_RcoEmbFreq_Max_C)
   {
      Ext_bDgoScp_rCluPedPrssMes = 1;
   }
   else
   {
      Ext_bDgoScp_rCluPedPrssMes = 0;
   }
   if (u16LocalExt_rCluPedPrssBrutMes < Clu_RcoEmbFreq_Min_C)
   {
      Ext_bDgoScg_rCluPedPrssMes = 1;
   }
   else
   {
      Ext_bDgoScg_rCluPedPrssMes = 0;
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidDiagGrad                                  */
/* !Description :  Ce bloc énumère les différents court circuits ( à la masse,*/
/*                 au plus) et les gradients qui engendrent un défaut sur le  */
/*                 capteur d’embrayage.                                       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_012.01                                     */
/*                 VEMS_E_12_01136_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Clu_rCluPedPrssLnrMes;                                       */
/*  input uint16 Clu_rCluPedPrssLnrMesPrev;                                   */
/*  input uint16 Clu_GradEmbFreqCrois_C;                                      */
/*  input uint16 Clu_GradEmbFreqDecrois_C;                                    */
/*  input uint16 Clu_perRateCluPedPrssMes;                                    */
/*  input uint16 Clu_FEmbFreq_Min_C;                                          */
/*  input uint16 Clu_FEmbFreq_Max_C;                                          */
/*  output boolean Ext_bDgoGrd_rCluPedPrssMes;                                */
/*  output boolean Ext_bDgoORng_rCluPedPrssMes;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidDiagGrad(void)
{
   uint32 u32LocalMul;
   uint32 u32LocalCluFEmbFreqMaxC;
   uint32 u32LocalCluFEmbFreqMinC;
   sint32 s32LocalMul;
   sint32 s32LocalDiff;


   s32LocalDiff = (sint32)( ( Clu_rCluPedPrssLnrMes
                            - Clu_rCluPedPrssLnrMesPrev)
                          * 3125);
   u32LocalMul = (uint32)((Clu_GradEmbFreqCrois_C * Clu_SampleTiFast_SC) * 32);

   s32LocalMul = (sint32)(-32 * ( (Clu_GradEmbFreqDecrois_C
                               * Clu_SampleTiFast_SC)));

   if (  (s32LocalDiff > (sint32)u32LocalMul)
      || (s32LocalDiff < s32LocalMul))
   {
      Ext_bDgoGrd_rCluPedPrssMes = 1;
   }
   else
   {
      Ext_bDgoGrd_rCluPedPrssMes = 0;
   }

   if (Clu_perRateCluPedPrssMes == 0)
   {
      if (Clu_FEmbFreq_Min_C > 0)
      {
         Ext_bDgoORng_rCluPedPrssMes = 1;
      }
      else
      {
         Ext_bDgoORng_rCluPedPrssMes = 0;
      }
   }
   else
   {
      u32LocalCluFEmbFreqMaxC = (uint32)( Clu_FEmbFreq_Max_C
                                        * Clu_perRateCluPedPrssMes);
      u32LocalCluFEmbFreqMinC = (uint32)( Clu_FEmbFreq_Min_C
                                        * Clu_perRateCluPedPrssMes);
      if (  (u32LocalCluFEmbFreqMaxC < 100000)
         || (u32LocalCluFEmbFreqMinC > 100000))
      {
         Ext_bDgoORng_rCluPedPrssMes = 1;
      }
      else
      {
         Ext_bDgoORng_rCluPedPrssMes = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidGDUFreq                                   */
/* !Description :  Ce bloc définit les appels au GDU pour les défauts de type */
/*                 court circuit                                              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/*  bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                    */
/*  input boolean Ext_bDgoScp_rCluPedPrssMes;                                 */
/*  input boolean Ext_bMonRunScp_rCluPedPrssMes;                              */
/*  input boolean Ext_bDgoScg_rCluPedPrssMes;                                 */
/*  input boolean Ext_bMonRunScg_rCluPedPrssMes;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidGDUFreq(void)
{
   GDGAR_vidGdu(GD_DFT_SCP_RCLUPEDPRSSMES,
                Ext_bDgoScp_rCluPedPrssMes,
                Ext_bMonRunScp_rCluPedPrssMes,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_SCG_RCLUPEDPRSSMES,
                Ext_bDgoScg_rCluPedPrssMes,
                Ext_bMonRunScg_rCluPedPrssMes,
                DIAG_DISPO);
}

/*------------------------------- end of file --------------------------------*/