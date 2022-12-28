/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCLUPED                                               */
/* !Description     : ACQCLUPED Component                                     */
/*                                                                            */
/* !Module          : ACQCLUPED                                               */
/* !Description     : ACQUISITION DE LA PEDALE D'EMBRAYAGE                    */
/*                                                                            */
/* !File            : ACQCLUPED_FCT1.c                                        */
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
/*   1 / ACQCLUPED_vidResetCpsCluPedInput                                     */
/*   2 / ACQCLUPED_vidClutchReadInput                                         */
/*   3 / ACQCLUPED_vidRead                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_6509293 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACQCLUPED/ACQCLUPED_FCT1.c_v      $*/
/* $Revision::   1.9                                                         $*/
/* $Author::   achebino                               $$Date::   23 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ACQCLUPED.h"
#include "ACQCLUPED_L.h"
#include "ACQCLUPED_IM.h"
#include "VEMS.h"
#include "MATHSRV.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCLUPED_vidResetCpsCluPedInput                           */
/* !Description :  A la mise sous tension du calculateur, on initialise la    */
/*                 donnée Cps_clutch_pedal_input avec Clu_bCluPedInpIni_C.    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04680_001.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Clu_bCluPedInpIni_C;                                        */
/*  output boolean Ext_bCluPedPrssMes;                                        */
/*  output boolean Clu_bCluPedInpIni_C;                                       */
/*  output boolean ACQCLUPED_bRawSig;                                         */
/*  output uint8 ACQCLUPED_u8AntiBounceCounter;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCLUPED_vidResetCpsCluPedInput(void)
{
   VEMS_vidSET(Ext_bCluPedPrssMes, Clu_bCluPedInpIni_C);
   /*initialization of the block filtre_anti_rebond*/
   ACQCLUPED_bRawSig = 1;
   ACQCLUPED_u8AntiBounceCounter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCLUPED_vidClutchReadInput                               */
/* !Description :  l’acquisition n’est effective qu’en présence d’un capteur  */
/*                 de pédale d’embrayage Tout ou Rien.                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_08_04680_002.01                                     */
/*                 VEMS_R_08_04680_003.01                                     */
/*                 VEMS_R_08_04680_005.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCLUPED_vidRead();                                     */
/*  input boolean FlowMng_bCluSwtEna;                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCLUPED_vidClutchReadInput(void)
{
   boolean bLocalFlowMng_bCluSwtEna;


   VEMS_vidGET(FlowMng_bCluSwtEna, bLocalFlowMng_bCluSwtEna);
   if (bLocalFlowMng_bCluSwtEna != 0)
   {
      ACQCLUPED_vidRead();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCLUPED_vidRead                                          */
/* !Description :  Lecture entrée embrayage.                                  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Acquisition_pedale_embrayage_tor;                           */
/*  input boolean Cps_config_capteur;                                         */
/*  input boolean Ext_bCluPedPrssMes;                                         */
/*  input boolean ACQCLUPED_bRawSig;                                          */
/*  input uint8 Low_clutch_thresh;                                            */
/*  input uint8 High_clutch_thresh;                                           */
/*  input uint8 ACQCLUPED_u8AntiBounceCounter;                                */
/*  output boolean ACQCLUPED_bRawSig;                                         */
/*  output uint8 ACQCLUPED_u8AntiBounceCounter;                               */
/*  output boolean Ext_bCluPedPrssMes;                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCLUPED_vidRead(void)
{
   boolean bLocalAcqpedaleembrayagetor;
   boolean bLocalExt_bCluPedPrssMes;
   uint8   u8LocalClutchThresh;
   uint16  u16LocalCnt;

   VEMS_vidGET(Acquisition_pedale_embrayage_tor, bLocalAcqpedaleembrayagetor);
   if (Cps_config_capteur != 0)
   {
      ACQCLUPED_bRawSig = bLocalAcqpedaleembrayagetor;
   }
   else
   {
      if (bLocalAcqpedaleembrayagetor != 0)
      {
         ACQCLUPED_bRawSig = 0;
      }
      else
      {
         ACQCLUPED_bRawSig = 1;
      }
   }

   VEMS_vidGET(Ext_bCluPedPrssMes, bLocalExt_bCluPedPrssMes);
   if (ACQCLUPED_bRawSig != bLocalExt_bCluPedPrssMes)
   {
      if (ACQCLUPED_bRawSig == 0)
      {
         u8LocalClutchThresh = Low_clutch_thresh;
      }
      else
      {
         u8LocalClutchThresh = High_clutch_thresh;
      }
      u16LocalCnt = (uint16)(ACQCLUPED_u8AntiBounceCounter + 1);
      ACQCLUPED_u8AntiBounceCounter = (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);
      if (ACQCLUPED_u8AntiBounceCounter > u8LocalClutchThresh)
      {
         VEMS_vidSET(Ext_bCluPedPrssMes, ACQCLUPED_bRawSig);
         ACQCLUPED_u8AntiBounceCounter = 0;
      }
   }
   else
   {
      ACQCLUPED_u8AntiBounceCounter = 0;
   }
}

/*------------------------------- end of file --------------------------------*/