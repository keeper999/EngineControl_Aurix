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
/* !File            : SFTYMNGR_FCT5.C                                         */
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
/*   1 / SFTYMNGR_vidSyntheseDefauts                                          */
/*   2 / SFTYMNGR_vidTraitEnvoiDgoVSCtl                                       */
/*   3 / SFTYMNGR_vidTraitEnvoiDgoSTT                                         */
/*   4 / SFTYMNGR_vidTraitEnvoiDgoEM                                          */
/*   5 / SFTYMNGR_vidTraitEnvoiDgoLimpHom                                     */
/*   6 / SFTYMNGR_vidTraitEnvoiResetSoft                                      */
/*   7 / SFTYMNGR_vidTraitEnvoiResetHard                                      */
/*   8 / SFTYMNGR_vidTraitEnvoiDgoArreMot                                     */
/*   9 / SFTYMNGR_vidSyntheseDefautECU                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_FCT5$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
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
#include "SWFAIL.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidSyntheseDefauts                                */
/* !Description :  traiter les évènements provenant de la gestion de          */
/*                 l’escalade, les transforme en diagnostique pour le GD et   */
/*                 produit le booléen constant positionné à 1 en interface du */
/*                 GD (bMonRun).                                              */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_042.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidTraitEnvoiDgoVSCtl();                        */
/*  extf argret void SFTYMNGR_vidTraitEnvoiDgoSTT();                          */
/*  extf argret void SFTYMNGR_vidTraitEnvoiDgoEM();                           */
/*  extf argret void SFTYMNGR_vidTraitEnvoiDgoLimpHom();                      */
/*  extf argret void SFTYMNGR_vidTraitEnvoiResetSoft();                       */
/*  extf argret void SFTYMNGR_vidTraitEnvoiResetHard();                       */
/*  extf argret void SFTYMNGR_vidTraitEnvoiDgoArreMot();                      */
/*  extf argret void SFTYMNGR_vidSyntheseDefautECU();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidSyntheseDefauts(void)
{
   SFTYMNGR_vidTraitEnvoiDgoVSCtl();
   SFTYMNGR_vidTraitEnvoiDgoSTT();
   SFTYMNGR_vidTraitEnvoiDgoEM();
   SFTYMNGR_vidTraitEnvoiDgoLimpHom();
   SFTYMNGR_vidTraitEnvoiResetSoft();
   SFTYMNGR_vidTraitEnvoiResetHard();
   SFTYMNGR_vidTraitEnvoiDgoArreMot();
   SFTYMNGR_vidSyntheseDefautECU();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiDgoVSCtl                             */
/* !Description :  sauvegarde de défaut montant vers le GD provenant de VSCtl */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_043.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoIrvVSCtlTmp;                                    */
/*  output boolean SftyMgt_bDgoIrvVSCtl;                                      */
/*  output boolean SftyMgt_bMonRunIrvVSCtl;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiDgoVSCtl(void)
{
   boolean bLocalDgoIrvVSCtl;


   bLocalDgoIrvVSCtl = SftyMgt_bDgoIrvVSCtlTmp;
   VEMS_vidSET(SftyMgt_bDgoIrvVSCtl,bLocalDgoIrvVSCtl);
   VEMS_vidSET(SftyMgt_bMonRunIrvVSCtl,1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiDgoSTT                               */
/* !Description :  sauvegarde de défaut montant vers le GD provenant de STT   */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_044.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoIrvSTTTmp;                                      */
/*  output boolean SftyMgt_bDgoIrvSTT;                                        */
/*  output boolean SftyMgt_bInhSTT;                                           */
/*  output boolean SftyMgt_bMonRunIrvSTT;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiDgoSTT(void)
{
   boolean bLocalSTT;


   bLocalSTT = SftyMgt_bDgoIrvSTTTmp;
   VEMS_vidSET(SftyMgt_bDgoIrvSTT,bLocalSTT);
   VEMS_vidSET(SftyMgt_bInhSTT,bLocalSTT);
   VEMS_vidSET(SftyMgt_bMonRunIrvSTT,1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiDgoEM                                */
/* !Description :  sauvegarde de défaut montant vers le GD provenant de EM    */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_045.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bDgoIrvEMTmp;                                       */
/*  output boolean SftyMgt_bDgoIrvEM;                                         */
/*  output boolean SftyMgt_bMonRunIrvEM;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiDgoEM(void)
{
   boolean bLocalDgoIrvEM;


   bLocalDgoIrvEM = SftyMgt_bDgoIrvEMTmp;
   VEMS_vidSET(SftyMgt_bDgoIrvEM,bLocalDgoIrvEM);
   VEMS_vidSET(SftyMgt_bMonRunIrvEM,1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiDgoLimpHom                           */
/* !Description :  traiter le mode de recouvrement LimpHome                   */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_046.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_stLih_C;                                              */
/*  output boolean SftyMgt_bDgoRvLih;                                         */
/*  output boolean SftyMgt_bMonRunRvLih;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiDgoLimpHom(void)
{
   if (SftyMgt_stDftLaddIp == SftyMgt_stLih_C)
   {
      VEMS_vidSET(SftyMgt_bDgoRvLih,1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoRvLih,0);
   }
   VEMS_vidSET(SftyMgt_bMonRunRvLih,1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiResetSoft                            */
/* !Description :  retarder la demande d’un nombre de pas d’échantillonnage   */
/*                 égal à sftyMgt_noSdlOnRstSw_C                              */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_047.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean SftyMgt_bRstSwReqAnt;                                       */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_stRstSw_C;                                            */
/*  input uint8 SFTYMNGR_u8ctDftLaddPrev;                                     */
/*  input uint8 SftyMgt_noSdlOnRstSw_C;                                       */
/*  input boolean SFTYMNGR_bRstSwReqAntPrev1;                                 */
/*  input boolean SFTYMNGR_bRstSwReqAntPrev2;                                 */
/*  input boolean SFTYMNGR_bRstSwReqAntPrev3;                                 */
/*  input boolean SFTYMNGR_bRstSwReqAntPrev4;                                 */
/*  output boolean SftyMgt_bRstSwReqAnt;                                      */
/*  output boolean SftyMgt_bRstSwReq;                                         */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev4;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev3;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev2;                                */
/*  output boolean SFTYMNGR_bRstSwReqAntPrev1;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiResetSoft(void)
{
   boolean bLocalRstSwReqAnt;
   boolean bLocalRstSwReq;
   boolean bLocalRstSwReqAntPrev;
   uint8   u8LocalctDftLadd;


   VEMS_vidGET(SftyMgt_bRstSwReqAnt, bLocalRstSwReqAntPrev);
   VEMS_vidGET(SftyMgt_ctDftLadd, u8LocalctDftLadd);

   if (  (SftyMgt_stDftLaddIp == SftyMgt_stRstSw_C)
      && (u8LocalctDftLadd != SFTYMNGR_u8ctDftLaddPrev))
   {
      bLocalRstSwReqAnt = 1;
   }
   else
   {
      bLocalRstSwReqAnt = 0;
   }
   VEMS_vidSET(SftyMgt_bRstSwReqAnt, bLocalRstSwReqAnt);

   switch (SftyMgt_noSdlOnRstSw_C)
   {
      case 0:
         bLocalRstSwReq = bLocalRstSwReqAnt;
         break;

      case 1:
         bLocalRstSwReq = bLocalRstSwReqAntPrev;
         break;

      case 2:
         bLocalRstSwReq = SFTYMNGR_bRstSwReqAntPrev1;
         break;

      case 3:
         bLocalRstSwReq = SFTYMNGR_bRstSwReqAntPrev2;
         break;

      case 4:
         bLocalRstSwReq = SFTYMNGR_bRstSwReqAntPrev3;
         break;

      case 5:
         bLocalRstSwReq = SFTYMNGR_bRstSwReqAntPrev4;
         break;

      default:
         bLocalRstSwReq = SFTYMNGR_bRstSwReqAntPrev4;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidSET(SftyMgt_bRstSwReq, bLocalRstSwReq);
   SFTYMNGR_bRstSwReqAntPrev4 = SFTYMNGR_bRstSwReqAntPrev3;
   SFTYMNGR_bRstSwReqAntPrev3 = SFTYMNGR_bRstSwReqAntPrev2;
   SFTYMNGR_bRstSwReqAntPrev2 = SFTYMNGR_bRstSwReqAntPrev1;
   SFTYMNGR_bRstSwReqAntPrev1 = bLocalRstSwReqAntPrev;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiResetHard                            */
/* !Description :  etarder la emande d’un nombre de pas d’échantillonnage égal*/
/*                 à sftyMgt_noSdlOnRstHw_C.                                  */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_048.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean SftyMgt_bRstHwReqAnt;                                       */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_stRstHw_C;                                            */
/*  input uint8 SFTYMNGR_u8ctDftLaddPrev;                                     */
/*  input uint8 SftyMgt_noSdlOnRstHw_C;                                       */
/*  input boolean SFTYMNGR_bRstHwReqAntPrev1;                                 */
/*  input boolean SFTYMNGR_bRstHwReqAntPrev2;                                 */
/*  input boolean SFTYMNGR_bRstHwReqAntPrev3;                                 */
/*  input boolean SFTYMNGR_bRstHwReqAntPrev4;                                 */
/*  output boolean SftyMgt_bRstHwReqAnt;                                      */
/*  output boolean SftyMgt_bRstHwReq;                                         */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev4;                                */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev3;                                */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev2;                                */
/*  output boolean SFTYMNGR_bRstHwReqAntPrev1;                                */
/*  output uint8 SFTYMNGR_u8ctDftLaddPrev;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiResetHard(void)
{
   boolean bLocalRstHwReqAnt;
   boolean bLocalRstHwReq;
   boolean bLocalRstHwReqAntPrev;
   uint8   u8LocalctDftLadd;


   VEMS_vidGET(SftyMgt_bRstHwReqAnt, bLocalRstHwReqAntPrev);
   VEMS_vidGET(SftyMgt_ctDftLadd, u8LocalctDftLadd);

   if (  (SftyMgt_stDftLaddIp == SftyMgt_stRstHw_C)
      && (u8LocalctDftLadd != SFTYMNGR_u8ctDftLaddPrev))
   {
      bLocalRstHwReqAnt = 1;
   }
   else
   {
      bLocalRstHwReqAnt = 0;
   }
   VEMS_vidSET(SftyMgt_bRstHwReqAnt, bLocalRstHwReqAnt);
   switch (SftyMgt_noSdlOnRstHw_C)
   {
      case 0:
         bLocalRstHwReq = bLocalRstHwReqAnt;
         break;

      case 1:
         bLocalRstHwReq = bLocalRstHwReqAntPrev;
         break;

      case 2:
         bLocalRstHwReq = SFTYMNGR_bRstHwReqAntPrev1;
         break;

      case 3:
         bLocalRstHwReq = SFTYMNGR_bRstHwReqAntPrev2;
         break;

      case 4:
         bLocalRstHwReq = SFTYMNGR_bRstHwReqAntPrev3;
         break;

      case 5:
         bLocalRstHwReq = SFTYMNGR_bRstHwReqAntPrev4;
         break;

      default:
         bLocalRstHwReq = SFTYMNGR_bRstHwReqAntPrev4;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidSET(SftyMgt_bRstHwReq, bLocalRstHwReq);
   SFTYMNGR_bRstHwReqAntPrev4 = SFTYMNGR_bRstHwReqAntPrev3;
   SFTYMNGR_bRstHwReqAntPrev3 = SFTYMNGR_bRstHwReqAntPrev2;
   SFTYMNGR_bRstHwReqAntPrev2 = SFTYMNGR_bRstHwReqAntPrev1;
   SFTYMNGR_bRstHwReqAntPrev1 = bLocalRstHwReqAntPrev;
   SFTYMNGR_u8ctDftLaddPrev = (uint8)MATHSRV_udtMIN(u8LocalctDftLadd, 9);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidTraitEnvoiDgoArreMot                           */
/* !Description :  traiter le mode mode de recouvrement arrêt moteur          */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_049.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_stEngStop_C;                                          */
/*  output boolean SftyMgt_bDgoIrvEngStop;                                    */
/*  output boolean SftyMgt_bMonRunIrvEngStop;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidTraitEnvoiDgoArreMot(void)
{
   if (SftyMgt_stDftLaddIp == SftyMgt_stEngStop_C)
   {
      VEMS_vidSET(SftyMgt_bDgoIrvEngStop,1);
   }
   else
   {
      VEMS_vidSET(SftyMgt_bDgoIrvEngStop,0);
   }
   VEMS_vidSET(SftyMgt_bMonRunIrvEngStop,1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidSyntheseDefautECU                              */
/* !Description :  synthétise les fronts de demande de défauts provenant de   */
/*                 l’escalade globale, de la gestion des défauts locaux VSCtl,*/
/*                 STT et EM, et de l’ écriture de la mémoire sauvegardée en  */
/*                 défaut.                                                    */
/* !Number      :  FCT5.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_050.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SftyMgt_bInhDftSatMem_C;                                    */
/*  input boolean SftyMgt_bDgoSatMem;                                         */
/*  input boolean SftyMgt_bDgoIrvECUTmp;                                      */
/*  input boolean SftyMgt_bDgoIni;                                            */
/*  input boolean SftyMgt_bInhDftNomTest_C;                                   */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_stNom_C;                                              */
/*  output boolean SftyMgt_bDgoIrvECU;                                        */
/*  output boolean SftyMgt_bMonRunIrvECU;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidSyntheseDefautECU(void)
{
   boolean bLocalInhDftSatMem;
   boolean bLocalDgoIrvECUTmp;


   if (SftyMgt_bInhDftSatMem_C != 0)
   {
      bLocalInhDftSatMem = 0;
   }
   else
   {
      bLocalInhDftSatMem = SftyMgt_bDgoSatMem;
   }

   if(  (SftyMgt_bDgoIrvECUTmp == 0)
     && (SftyMgt_bDgoIni == 0))
   {
      bLocalDgoIrvECUTmp = 0;
   }
   else
   {
      if(SftyMgt_bInhDftNomTest_C != 0)
      {
         bLocalDgoIrvECUTmp = 1;
      }
      else
      {
         if(SftyMgt_stDftLaddIp != SftyMgt_stNom_C)
         {
            bLocalDgoIrvECUTmp = 1;
         }
         else
         {
            bLocalDgoIrvECUTmp = 0;
         }
      }
   }

   /* bascule RS (R Prioritaire): Q = !R . (S + Q)*/
   if (  (bLocalDgoIrvECUTmp != 0)
      || (bLocalInhDftSatMem != 0) )
   {
      VEMS_vidSET(SftyMgt_bDgoIrvECU, 1);
   }
   VEMS_vidSET(SftyMgt_bMonRunIrvECU, 1);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/