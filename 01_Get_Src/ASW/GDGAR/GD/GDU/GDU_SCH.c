/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : GDU                                                     */
/* !Description     : GDU Component.                                          */
/*                                                                            */
/* !Module          : GDU                                                     */
/* !Description     : SINGLE FAILURE MANAGER                                  */
/*                                                                            */
/* !File            : GDU_SCH.c                                               */
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
/*   1 / GD_EveRst_GDU                                                        */
/*   2 / GD_EveRstDft_GDU                                                     */
/*   3 / GDU_vidSdlSlow                                                       */
/*   4 / GD_EveKOn_GDU                                                        */
/*   5 / GD_EveRstDftObd_GDU                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5444560 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/GDU/GDU_SCH.c_v              $*/
/* $Revision::   1.15     $$Author::   mbenfrad       $$Date::   30 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   30 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "GDU.h"
#include "GDU_L.h"
#include "GDU_IM.h"
#include "GD_api.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_GDU                                              */
/* !Description :  ECU reset event                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5444560_001.01                                       */
/*                 PTS_R_5444560_002.01                                       */
/*                 PTS_R_5444560_003.01                                       */
/*                 VEMS_E_10_03081_001.02                                     */
/*                 VEMS_E_10_03081_002.02                                     */
/*                 VEMS_E_10_03081_003.02                                     */
/*                 VEMS_E_10_03081_004.01                                     */
/*                 VEMS_E_10_03081_005.01                                     */
/*                 VEMS_E_10_03081_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF02_IniCntDet();                                  */

/*  extf argret void GDU_vidMngAutomateEntry(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidF02_IniEndDiag();                                 */
/*  input boolean GD_abThdDownPrev;                                           */
/*  input boolean GD_abThdUpPrev;                                             */
/*  input boolean GD_abctDetPrev;                                             */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  input uint8 GD_au8IdxClassDet[8];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_GDU                                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_GDU(void)
{
   sint32             s32LocalIdx;
   uint8              u8LocalIdxClasDet;
   uint8              u8LocalDivision;
   uint8              u8LocalRatio;
   boolean            bLocalStPres;
   GDFRM_tenuGDUState enuLocalStDgo;
   boolean            bLocalReIniStKey;   /* Reinit state of GDU Manager      */
   boolean            bLocalInit;         /* Reinit the prev Variable      */

   /*initialisation des variable prev*/
   bLocalInit = 0;
   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      u8LocalDivision = (uint8)(s32LocalIdx / 8);
      u8LocalRatio = (uint8)(s32LocalIdx % 8);
      GD_vidBitWrite(GD_abThdDownPrev[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit );
      GD_vidBitWrite(GD_abThdUpPrev[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit);
      GD_vidBitWrite(GD_abctDetPrev[u8LocalDivision],
                     u8LocalRatio,
                     bLocalInit);
   }
   /*Read EEPROM*/
   GDU_vidF02_IniCntDet();

   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      enuLocalStDgo = GD_astrDftEep[s32LocalIdx].enuStDgo;
      u8LocalIdxClasDet = GD_au8IdxClassDet[s32LocalIdx];
      bLocalReIniStKey = GD_astrClasDet[u8LocalIdxClasDet].bReIniStKeyOnClasDet;
      bLocalStPres = GD_bBitRead(GD_astrDftEep[s32LocalIdx].u8GduGobdManagement,
                                 BSTPRES);
      if (  (  (enuLocalStDgo == GDU_ETAT_PRESENT)
            || (enuLocalStDgo == GDU_ETAT_DEVALIDATION))
         && (bLocalReIniStKey == 1))
      {
         GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_PRESENT;
      }
      else
      {
         if (bLocalStPres == 1)
         {
            GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_FUGITIF;
         }
         else
         {
            GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_ABSENT;
         }
      }
      GDU_vidMngAutomateEntry((uint16)s32LocalIdx);
   }
   GDU_vidF02_IniEndDiag();
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDft_GDU                                           */
/* !Description :  After-sale tool request for a clear failure                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5444560_001.01                                       */
/*                 PTS_R_5444560_002.01                                       */
/*                 PTS_R_5444560_003.01                                       */
/*                 VEMS_E_10_03081_001.02                                     */
/*                 VEMS_E_10_03081_002.02                                     */
/*                 VEMS_E_10_03081_003.02                                     */
/*                 VEMS_E_10_03081_004.01                                     */
/*                 VEMS_E_10_03081_005.01                                     */
/*                 VEMS_E_10_03081_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF02_IniCntDet();                                  */
/*  extf argret void GDU_vidMngAutomateEntry(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidF06_CntDetEvents(argin uint16 u16DftIdx);         */
/*  extf argret void GDU_vidF02_IniEndDiag();                                 */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDft_GDU                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDft_GDU(void)
{
   sint32             s32LocalIdx;

   GDU_vidF02_IniCntDet();
   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_ABSENT;
      GDU_vidMngAutomateEntry((uint16)s32LocalIdx);
      GDU_vidF06_CntDetEvents((uint16)s32LocalIdx);
   }
   GDU_vidF02_IniEndDiag();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GDU_vidSdlSlow                                             */
/* !Description :  Function used only on debug. It used to reset all the      */
/*                 default on a rising edge for GD_bRstDftCal.                */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5444560_001.01                                       */
/*                 PTS_R_5444560_002.01                                       */
/*                 PTS_R_5444560_003.01                                       */
/*                 VEMS_E_10_03081_001.02                                     */
/*                 VEMS_E_10_03081_002.02                                     */
/*                 VEMS_E_10_03081_003.02                                     */
/*                 VEMS_E_10_03081_004.01                                     */
/*                 VEMS_E_10_03081_005.01                                     */
/*                 VEMS_E_10_03081_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF02_IniCntDet();                                  */
/*  extf argret void GDU_vidMngAutomateEntry(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidF06_CntDetEvents(argin uint16 u16DftIdx);         */
/*  extf argret void GDU_vidF02_IniEndDiag();                                 */
/*  extf argret void GDU_vidExitEveRstDftCal();                               */
/*  input boolean GDU_bRstDftCal_C;                                           */
/*  input boolean GDU_bMemRstDftCal;                                          */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*  output boolean GDU_bMemRstDftCal;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GDU_vidSdlSlow                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GDU_vidSdlSlow(void)
{
   sint32             s32LocalIdx;

   if (  (GDU_bRstDftCal_C == TRUE)
      && (GDU_bMemRstDftCal == FALSE))
   {
      GDU_vidF02_IniCntDet();
      for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
      {
         GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_ABSENT;
         GDU_vidMngAutomateEntry((uint16)s32LocalIdx);
         GDU_vidF06_CntDetEvents((uint16)s32LocalIdx);
      }
      GDU_vidF02_IniEndDiag();
      GDU_vidExitEveRstDftCal();
   }
   GDU_bMemRstDftCal = GDU_bRstDftCal_C;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveKOn_GDU                                              */
/* !Description :  Ignition key's transit from ON to OFF                      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5444560_001.01                                       */
/*                 PTS_R_5444560_002.01                                       */
/*                 PTS_R_5444560_003.01                                       */
/*                 VEMS_E_10_03081_001.02                                     */
/*                 VEMS_E_10_03081_002.02                                     */
/*                 VEMS_E_10_03081_003.02                                     */
/*                 VEMS_E_10_03081_004.01                                     */
/*                 VEMS_E_10_03081_005.01                                     */
/*                 VEMS_E_10_03081_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF02_IniCntDet();                                  */
/*  extf argret void GDU_vidMngAutomateExit(argin uint16 u16IdxDft, argin     */
/* GDFRM_tenuGDUState enuStDgo);                                              */
/*  extf argret void JDD_DftExitUnval(argin uint16 u16IdxDft);                */
/*  extf argret void GDU_vidMngAutomateEntry(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidF06_CntDetEvents(argin uint16 u16DftIdx);         */
/*  extf argret void FRM_vidF01_PrmDft_Init_opt_suite();                      */
/*  input uint8 GD_au8IdxClassDet[8];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  input GD_tstrDftEep GD_astrDftEep[8];                                     */
/*  output boolean FRM_Dis_PrmDftInitLoop;                                    */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveKOn_GDU                                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveKOn_GDU(void)
{
   sint32             s32LocalIdx;
   uint8              u8LocalIdxClasDet;
   boolean            bLocalReIniStKey;        /* Reinit state of GDU Manager */
   boolean            bLocalStPres;
   GDFRM_tenuGDUState enuLocalStDgo;   /* State of GDU manager */

   GDU_vidF02_IniCntDet();

   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      u8LocalIdxClasDet = GD_au8IdxClassDet[s32LocalIdx];
      bLocalReIniStKey = GD_astrClasDet[u8LocalIdxClasDet].bReIniStKeyOnClasDet;
      enuLocalStDgo = GD_astrDftEep[s32LocalIdx].enuStDgo;

      /* TRANSITION: GDU_PRESENT->GDU_ABSENT
      (label=GD_EveKOn_GDU_2[NS_bReIniStKeyTypCc_NameVar == 0]) */
      if (  (enuLocalStDgo == GDU_ETAT_DEVALIDATION)
         || (enuLocalStDgo == GDU_ETAT_PRESENT))
      {
         if (bLocalReIniStKey == 0)
         {
            bLocalStPres =
               GD_bBitRead(GD_astrDftEep[s32LocalIdx].u8GduGobdManagement,
                           BSTPRES);
            /* Transition->GDU_ETAT_ABSENT */
            if (bLocalStPres == 0)
            {
               GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_ABSENT;
            }
            /* Transition->GDU_ETAT_FUGITIF */
            else
            {
               GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_FUGITIF;
            }

            GDU_vidMngAutomateExit((uint16)s32LocalIdx, enuLocalStDgo);
            JDD_DftExitUnval((uint16)s32LocalIdx);
            GDU_vidMngAutomateEntry((uint16)s32LocalIdx);
         }
      }

      /* TRANSITION: GDU_PONCTUEL->GDU_ABSENT (label=GD_EveKOn_GDU_2) */
      if (  (enuLocalStDgo == GDU_ETAT_PCTL_ABSENT)
         || (enuLocalStDgo == GDU_ETAT_PCTL_PRESENT))
      {
         bLocalStPres =
            GD_bBitRead(GD_astrDftEep[s32LocalIdx].u8GduGobdManagement,BSTPRES);

         /* Transition->GDU_ETAT_ABSENT */
         if (bLocalStPres == 0)
         {
            GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_ABSENT;
         }
         /* Transition->GDU_ST_FUGITIF */
         else
         {
            GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_FUGITIF;
         }

         GDU_vidMngAutomateExit((uint16)s32LocalIdx, enuLocalStDgo);
         GDU_vidMngAutomateEntry((uint16)s32LocalIdx);
      }
      GDU_vidF06_CntDetEvents((uint16)s32LocalIdx);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRstDftObd_GDU                                        */
/* !Description :  After-sale tool request for an OBD clear failure           */
/* !Number      :  SCH.5                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  PTS_R_5444560_001.01                                       */
/*                 PTS_R_5444560_002.01                                       */
/*                 PTS_R_5444560_003.01                                       */
/*                 VEMS_E_10_03081_001.02                                     */
/*                 VEMS_E_10_03081_002.02                                     */
/*                 VEMS_E_10_03081_003.02                                     */
/*                 VEMS_E_10_03081_004.01                                     */
/*                 VEMS_E_10_03081_005.01                                     */
/*                 VEMS_E_10_03081_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDU_vidF03_IniCntDetScanTool();                          */
/*  extf argret void GDU_vidMngAutomateEntry(argin uint16 u16IdxDft);         */
/*  extf argret void GDU_vidF06_CntDetEvents(argin uint16 u16DftIdx);         */
/*  extf argret void GDU_vidF03_IniEndDiagScanTool();                         */
/*  input uint8 GD_au8IdxClasObd[8];                                          */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  output GD_tstrDftEep GD_astrDftEep[8];                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRstDftObd_GDU                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRstDftObd_GDU(void)
{
   sint32           s32LocalIdx;
   uint8            u8LocalIdxClasObd;    /* detect class index link to obd   */
   boolean          bLocalEnaSctl;

   GDU_vidF03_IniCntDetScanTool();
   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      u8LocalIdxClasObd = GD_au8IdxClasObd[s32LocalIdx];
      bLocalEnaSctl = GD_astrClasObd[u8LocalIdxClasObd].bEnaSctl;
      if (bLocalEnaSctl ==1)
      {
         GD_astrDftEep[s32LocalIdx].enuStDgo = GDU_ETAT_ABSENT;
         GDU_vidMngAutomateEntry((uint16)s32LocalIdx);
      }
      GDU_vidF06_CntDetEvents((uint16)s32LocalIdx);
   }
   GDU_vidF03_IniEndDiagScanTool();
}
/*------------------------------- end of file --------------------------------*/