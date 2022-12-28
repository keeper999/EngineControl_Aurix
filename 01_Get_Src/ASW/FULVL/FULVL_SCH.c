/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FULVL                                                   */
/* !Description     : FULVL component.                                        */
/*                                                                            */
/* !Module          : FULVL                                                   */
/* !Description     : GESTION DU NIVEAU CARBURANT                             */
/*                                                                            */
/* !File            : FULVL_SCH.C                                             */
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
/*   1 / Fu_EveRst_FuLvl                                                      */
/*   2 / Fu_EveKOn_FuLvl                                                      */
/*   3 / Fu_SdlMid_FuLvl                                                      */
/*   4 / Fu_EveRxn412_FuLvl                                                   */
/*   5 / Fu_EveRxn612_FuLvl                                                   */
/*   6 / Fu_SdlSlow_FuLvl                                                     */
/*   7 / Fu_EveKOf_FuLvl                                                      */
/*   8 / Fu_EvePwrl_FuLvl                                                     */
/*   9 / Fu_EveStTR_FuLvl                                                     */
/*   10 / Fu_EveRTSt_FuLvl                                                    */
/*   11 / Fu_SdlFast_FuLvl                                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5462804 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#049911                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FULVL/FULVL_SCH.C_v          $*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   20 Aug 2013 $*/
/* $Author::   mbenfrad                               $$Date::   20 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "FULVL.h"
#include "FULVL_L.h"
#include "FULVL_IM.h"
#include "GDGAR.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveRst_FuLvl                                            */
/* !Description :  Evènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidInitOutputs();                                  */
/*  extf argret void FULVL_vidInitReset();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveKOn_FuLvl                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveRst_FuLvl(void)
{
   FULVL_vidInitOutputs();
   FULVL_vidInitReset();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveKOn_FuLvl                                            */
/* !Description :  Evénement associé au passage de clef OFF à clef ON.        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidInitKeyOffOn();                                 */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveKOn_FuLvl                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveKOn_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidInitKeyOffOn();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_SdlMid_FuLvl                                            */
/* !Description :  Moniteur moyen pour la fonction Fuel.                      */
/* !Number      :  SCH.3                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidCounterDec();                                   */
/*  extf argret void FULVL_vidLowFuelLevelSoftware();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 FULVL_u8Inhib;                                                */
/*  input boolean Fu_bDgoORng_FuGaugeLvl;                                     */
/*  input boolean Fu_bMonRunORng_FuGaugeLvl;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_SdlFast_FuLvl                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_SdlMid_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidCounterDec();
      FULVL_vidLowFuelLevelSoftware();
      GDGAR_vidGdu(GD_DFT_ORNG_FUGAUGELVL,
                   Fu_bDgoORng_FuGaugeLvl,
                   Fu_bMonRunORng_FuGaugeLvl,
                   DIAG_DISPO);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveRxn412_FuLvl                                         */
/* !Description :  Evènement de rception de la trame 412.                     */
/* !Number      :  SCH.4                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelGaugeState();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void FULVL_vidLowFuelLevelHardware();                         */
/*  input uint8 FULVL_u8Inhib;                                                */
/*  input boolean Fu_bDgoOc_FuGauge;                                          */
/*  input boolean Fu_bMonRunOc_FuGauge;                                       */
/*  input boolean Fu_bDgoScg_FuGauge;                                         */
/*  input boolean Fu_bMonRunScg_FuGauge;                                      */
/*  input boolean Fu_bDgoORng_FuGauge;                                        */
/*  input boolean Fu_bMonRunORng_FuGauge;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveRxn412_FuLvl                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveRxn412_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidFuelGaugeState();
      GDGAR_vidGdu(GD_DFT_OC_FUGAUGE,
                   Fu_bDgoOc_FuGauge,
                   Fu_bMonRunOc_FuGauge,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_FUGAUGE,
                   Fu_bDgoScg_FuGauge,
                   Fu_bMonRunScg_FuGauge,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNG_FUGAUGE,
                   Fu_bDgoORng_FuGauge,
                   Fu_bMonRunORng_FuGauge,
                   DIAG_DISPO);
      FULVL_vidLowFuelLevelHardware();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveRxn612_FuLvl                                         */
/* !Description :  Evènement de rception de la trame 612.                     */
/* !Number      :  SCH.5                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_001.01                                     */
/*                 VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelLevel();                                    */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveRxn612_FuLvl                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveRxn612_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidFuelLevel();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_SdlSlow_FuLvl                                           */
/* !Description :  Moniteur lent pour la fonction Fuel.                       */
/* !Number      :  SCH.6                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelLevelState();                               */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_SdlSlow_FuLvl                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_SdlSlow_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidFuelLevelState();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveKOf_FuLvl                                            */
/* !Description :  Evénement associé au passage de clef ON à clef OFF.        */
/* !Number      :  SCH.7                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelLevelCpteCaleOrOff();                       */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveKOf_FuLvl                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveKOf_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidFuelLevelCpteCaleOrOff();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EvePwrl_FuLvl                                           */
/* !Description :  Evènement Powerlatch.                                      */
/* !Number      :  SCH.8                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidEepromWrite();                                  */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EvePwrl_FuLvl                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EvePwrl_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidEepromWrite();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveStTR_FuLvl                                           */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.9                                                      */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidInitEngineRunning();                            */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveStTR_FuLvl                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveStTR_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidInitEngineRunning();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveRTSt_FuLvl                                           */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant.                                           */
/* !Number      :  SCH.10                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vidFuelLevelCpteCaleOrOff();                       */
/*  input uint8 FULVL_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveRTSt_FuLvl                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveRTSt_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vidFuelLevelCpteCaleOrOff();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_SdlFast_FuLvl                                           */
/* !Description :  Moniteur rapide de la fonction Fu                          */
/* !Number      :  SCH.11                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_04734_003.01                                     */
/*                 VEMS_E_11_04734_002.01                                     */
/*                 VEMS_E_11_04734_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FULVL_vid1BisDiagLowFuelLevel();                         */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 FULVL_u8Inhib;                                                */
/*  input boolean FuLvl_bDgoLoFuLvl;                                          */
/*  input boolean FuLvl_bMonRunLoFuLvl;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_SdlFast_FuLvl                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_SdlFast_FuLvl(void)
{
   if (FULVL_u8Inhib != 0x5A)
   {
      FULVL_vid1BisDiagLowFuelLevel();
      GDGAR_vidGdu(GD_DFT_LOFULVL,
                   FuLvl_bDgoLoFuLvl,
                   FuLvl_bMonRunLoFuLvl,
                   DIAG_DISPO);
   }
}
/*------------------------------- end of file --------------------------------*/