/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXENDSTOP                                         */
/* !Description     : VLVACTEXENDSTOP Component.                              */
/*                                                                            */
/* !Module          : VLVACTEXENDSTOP                                         */
/* !Description     : Calcul des butées pour le décaleur d'arbre à cames      */
/*                    d'échappement .                                         */
/*                                                                            */
/* !File            : VLVACTEXENDSTOP_SCH.C                                   */
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
/*   1 / VlvAct_EveRst_ExEndStop                                              */
/*   2 / VlvAct_EveKOn_ExEndStop                                              */
/*   3 / VlvAct_SdlSlow_ExEndStop                                             */
/*   4 / VlvAct_EveCkSnOn_ExEndStop                                           */
/*   5 / VlvAct_EveExCmToo_ExEndStop                                          */
/*   6 / VlvAct_SdlFast_ExEndStop                                             */
/*   7 / VlvAct_EveRstVVT_ExEndStop                                           */
/*   8 / VlvAct_EvePwrl_ExEndStop                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5885665 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXENDSTOP/VLVACTE$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   14 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTEXENDSTOP.h"
#include "VLVACTEXENDSTOP_L.h"
#include "VLVACTEXENDSTOP_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExEndStop                                    */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_015.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExEndStop                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExEndStop(void)
{
   VLVACTEXENDSTOP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOn_ExEndStop                                    */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_013.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_R_08_06268_015.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidInitFailure();                        */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOn_ExEndStop                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOn_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXENDSTOP_vidInitFailure();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlSlow_ExEndStop                                   */
/* !Description :  Moniteur Lent pour la fonction VVT                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_015.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidLstLrnTmpCntr();                      */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlSlow_ExEndStop                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlSlow_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXENDSTOP_vidLstLrnTmpCntr();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveCkSnOn_ExEndStop                                 */
/* !Description :  Evénement de synchronisation                               */
/* !Number      :  SCH.4                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_015.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidReset();                              */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveCkSnOn_ExEndStop                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveCkSnOn_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXENDSTOP_vidReset();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveExCmToo_ExEndStop                                */
/* !Description :  Evènement dent AAC  échappement.                           */
/* !Number      :  SCH.5                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_R_08_06268_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidOffsetsReset();                       */
/*  extf argret void VLVACTEXENDSTOP_vidExhaustOff();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean VlvAct_bDgoLrnEndStopVlvActEx;                              */
/*  input boolean VlvAct_bMonRunLrnEndStopVlvActEx;                           */
/*  input boolean VlvAct_bDgoEndStopOldVlvActEx;                              */
/*  input boolean VlvAct_bMonRunEndStopOldVlvActEx;                           */
/*  input boolean VlvAct_bDgoLrnFaiLimVlvActEx;                               */
/*  input boolean VlvAct_bMonRunLrnFaiLimVlvActEx;                            */
/*  input boolean VlvAct_bDgoOldLrnVlvActEx;                                  */
/*  input boolean VlvAct_bMonRunOldLrnVlvActEx;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveExCmToo_ExEndStop                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveExCmToo_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXENDSTOP_vidOffsetsReset();
         VLVACTEXENDSTOP_vidExhaustOff();
         GDGAR_vidGdu(GD_DFT_LRNENDSTOPVLVACTEX,
                      VlvAct_bDgoLrnEndStopVlvActEx,
                      VlvAct_bMonRunLrnEndStopVlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ENDSTOPOLDVLVACTEX,
                      VlvAct_bDgoEndStopOldVlvActEx,
                      VlvAct_bMonRunEndStopOldVlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_LRNFAILIMVLVACTEX,
                      VlvAct_bDgoLrnFaiLimVlvActEx,
                      VlvAct_bMonRunLrnFaiLimVlvActEx,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OLDLRNVLVACTEX,
                      VlvAct_bDgoOldLrnVlvActEx,
                      VlvAct_bMonRunOldLrnVlvActEx,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExEndStop                                   */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.6                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_015.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidExtAllowLrng();                       */
/*  extf argret void VLVACTEXENDSTOP_vidFrstOffLrnCon();                      */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExEndStop                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXENDSTOP_vidExtAllowLrng();
         VLVACTEXENDSTOP_vidFrstOffLrnCon();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRstVVT_ExEndStop                                 */
/* !Description :  Runnable Demande de reset apprentissage VVT                */
/* !Number      :  SCH.7                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_016.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                 VEMS_R_08_06268_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidInitDiagSrv();                        */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRstVVT_ExEndStop                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRstVVT_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      VLVACTEXENDSTOP_vidInitDiagSrv();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EvePwrl_ExEndStop                                   */
/* !Description :  Evénement powerlatch                                       */
/* !Number      :  SCH.8                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06268_013.01                                     */
/*                 VEMS_R_08_06268_022.01                                     */
/*                 VEMS_R_08_06268_012.01                                     */
/*                 VEMS_R_08_06268_014.01                                     */
/*                 VEMS_R_08_06268_016.01                                     */
/*                 VEMS_R_08_06268_018.01                                     */
/*                 VEMS_R_08_06268_017.01                                     */
/*                 VEMS_R_08_06268_019.01                                     */
/*                 VEMS_R_08_06268_020.01                                     */
/*                 VEMS_R_08_06268_021.01                                     */
/*                 VEMS_R_08_06268_001.02                                     */
/*                 VEMS_E_08_06268_024.01                                     */
/*                 VEMS_E_08_06268_025.01                                     */
/*                 VEMS_E_08_06268_026.01                                     */
/*                 VEMS_R_08_06268_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXENDSTOP_vidEepromWrite();                        */
/*  input uint8 VLVACTEXENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EvePwrl_ExEndStop                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EvePwrl_ExEndStop(void)
{
   if (VLVACTEXENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXENDSTOP_vidEepromWrite();
      }
   }
}
/*--------------------------------- end of file ------------------------------*/