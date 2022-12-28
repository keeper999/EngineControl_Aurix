/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINENDSTOP                                         */
/* !Description     : VLVACTINENDSTOP Component.                              */
/*                                                                            */
/* !Module          : VLVACTINENDSTOP                                         */
/* !Description     : Calcul des butées pour le décaleur d'arbre à cames      */
/*                    d'admission .                                           */
/*                                                                            */
/* !File            : VLVACTINENDSTOP_SCH.C                                   */
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
/*   1 / VlvAct_EveRst_InEndStop                                              */
/*   2 / VlvAct_EveKOn_InEndStop                                              */
/*   3 / VlvAct_SdlSlow_InEndStop                                             */
/*   4 / VlvAct_EveCkSnOn_InEndStop                                           */
/*   5 / VlvAct_EveInCmToo_InEndStop                                          */
/*   6 / VlvAct_SdlFast_InEndStop                                             */
/*   7 / VlvAct_EveRstVVT_InEndStop                                           */
/*   8 / VlvAct_EvePwrl_InEndStop                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5883893 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINENDSTOP/VLVACTI$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   14 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINENDSTOP.h"
#include "VLVACTINENDSTOP_L.h"
#include "VLVACTINENDSTOP_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InEndStop                                    */
/* !Description :  Evènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_R_08_06255_016.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidInitOutput();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InEndStop                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InEndStop(void)
{
   VLVACTINENDSTOP_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOn_InEndStop                                    */
/* !Description :  Evénement associé au passage de clef OFF à clef ON         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_016.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidInitFailure();                        */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOn_InEndStop                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOn_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINENDSTOP_vidInitFailure();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlSlow_InEndStop                                   */
/* !Description :  Moniteur Lent pour la fonction VVT                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_R_08_06255_016.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidLstLrnTmpCntr();                      */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlSlow_InEndStop                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlSlow_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINENDSTOP_vidLstLrnTmpCntr();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveCkSnOn_InEndStop                                 */
/* !Description :  Evénement de synchronisation                               */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_016.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidReset();                              */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveCkSnOn_InEndStop                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveCkSnOn_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINENDSTOP_vidReset();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveInCmToo_InEndStop                                */
/* !Description :  Evènement dent AAC  admission.                             */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_R_08_06255_016.01                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidOffsetsReset();                       */
/*  extf argret void VLVACTINENDSTOP_vidIntakeOff();                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean VlvAct_bDgoLrnEndStopVlvActIn;                              */
/*  input boolean VlvAct_bMonRunLrnEndStopVlvActIn;                           */
/*  input boolean VlvAct_bDgoEndStopOldVlvActIn;                              */
/*  input boolean VlvAct_bMonRunEndStopOldVlvActIn;                           */
/*  input boolean VlvAct_bDgoLrnFaiLimVlvActIn;                               */
/*  input boolean VlvAct_bMonRunLrnFaiLimVlvActIn;                            */
/*  input boolean VlvAct_bDgoOldLrnVlvActIn;                                  */
/*  input boolean VlvAct_bMonRunOldLrnVlvActIn;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveInCmToo_InEndStop                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveInCmToo_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINENDSTOP_vidOffsetsReset();
         VLVACTINENDSTOP_vidIntakeOff();
         GDGAR_vidGdu(GD_DFT_LRNENDSTOPVLVACTIN,
                      VlvAct_bDgoLrnEndStopVlvActIn,
                      VlvAct_bMonRunLrnEndStopVlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_ENDSTOPOLDVLVACTIN,
                      VlvAct_bDgoEndStopOldVlvActIn,
                      VlvAct_bMonRunEndStopOldVlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_LRNFAILIMVLVACTIN,
                      VlvAct_bDgoLrnFaiLimVlvActIn,
                      VlvAct_bMonRunLrnFaiLimVlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_OLDLRNVLVACTIN,
                      VlvAct_bDgoOldLrnVlvActIn,
                      VlvAct_bMonRunOldLrnVlvActIn,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InEndStop                                   */
/* !Description :  Moniteur rapide pour la fonction VVT.                      */
/* !Number      :  SCH.6                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_016.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidIntAllowLrng();                       */
/*  extf argret void VLVACTINENDSTOP_vidFrstOffLrnCon();                      */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InEndStop                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINENDSTOP_vidIntAllowLrng();
         VLVACTINENDSTOP_vidFrstOffLrnCon();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRstVVT_InEndStop                                 */
/* !Description :  Runnable Demande de reset apprentissage VVT.               */
/* !Number      :  SCH.7                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_016.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidInitDiagSrv();                        */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRstVVT_InEndStop                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRstVVT_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      VLVACTINENDSTOP_vidInitDiagSrv();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EvePwrl_InEndStop                                   */
/* !Description :  Evénement powerlatch                                       */
/* !Number      :  SCH.8                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_06255_022.01                                     */
/*                 VEMS_R_08_06255_021.01                                     */
/*                 VEMS_R_08_06255_020.01                                     */
/*                 VEMS_R_08_06255_019.01                                     */
/*                 VEMS_R_08_06255_018.01                                     */
/*                 VEMS_R_08_06255_017.01                                     */
/*                 VEMS_R_08_06255_016.01                                     */
/*                 VEMS_R_08_06255_014.01                                     */
/*                 VEMS_R_08_06255_013.01                                     */
/*                 VEMS_R_08_06255_012.01                                     */
/*                 VEMS_R_08_06255_008.01                                     */
/*                 VEMS_R_08_06255_001.02                                     */
/*                 VEMS_E_08_06255_024.01                                     */
/*                 VEMS_E_08_06255_025.01                                     */
/*                 VEMS_E_08_06255_026.01                                     */
/*                 VEMS_R_08_06255_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINENDSTOP_vidEepromWrite();                        */
/*  input uint8 VLVACTINENDSTOP_u8Inhib;                                      */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EvePwrl_InEndStop                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EvePwrl_InEndStop(void)
{
   if (VLVACTINENDSTOP_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINENDSTOP_vidEepromWrite();
      }
   }
}

/*--------------------------------- end of file ------------------------------*/