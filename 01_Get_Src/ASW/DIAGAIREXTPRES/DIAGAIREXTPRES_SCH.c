/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGAIREXTPRES                                          */
/* !Description     : DIAGAIREXTPRES component.                               */
/*                                                                            */
/* !Module          : DIAGAIREXTPRES                                          */
/* !Description     : DIAGNOSTIC FONCTIONNEL DE LA PRESSION DE ATMOSPHERIQUE  */
/*                                                                            */
/* !File            : DIAGAIREXTPRES_SCH.C                                    */
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
/*   1 / AirPres_EveRst_DiagAirExtPres                                        */
/*   2 / AirPres_EveKOn_DiagAirExtPres                                        */
/*   3 / AirPres_SdlSlow_DiagAirExtPres                                       */
/*   4 / AirPres_EveKOf_DiagAirExtPres                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 03594 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRPRES/DIAGAIREXTPRES/DIAGAIREX$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   19 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DIAGAIREXTPRES.h"
#include "DIAGAIREXTPRES_L.h"
#include "DIAGAIREXTPRES_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_DiagAirExtPres                              */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_001.01                                     */
/*                 VEMS_E_11_03594_002.01                                     */
/*                 VEMS_E_11_03594_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DIAGAIREXTPRES_vidInitOutput();                          */
/*  extf argret void DIAGAIREXTPRES_vidDiaAirExtPrsIn();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveRst_DiagAirExtPres                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_DiagAirExtPres(void)
{
   DIAGAIREXTPRES_vidInitOutput();
   DIAGAIREXTPRES_vidDiaAirExtPrsIn();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveKOn_DiagAirExtPres                              */
/* !Description :  Evénement clef Off_On                                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_001.01                                     */
/*                 VEMS_E_11_03594_002.01                                     */
/*                 VEMS_E_11_03594_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGAIREXTPRES_vidMemAirExtPres();                       */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input uint8 DIAGAIREXTPRES_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveKOn_DiagAirExtPres                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveKOn_DiagAirExtPres(void)
{
   boolean bLocalCf_bPresPAirExtSens;


   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalCf_bPresPAirExtSens);
   if (DIAGAIREXTPRES_u8Inhib != 0x5A)
   {
      if (bLocalCf_bPresPAirExtSens != 0)
      {
         DIAGAIREXTPRES_vidMemAirExtPres();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlSlow_DiagAirExtPres                             */
/* !Description :  Moniteur lent                                              */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_001.01                                     */
/*                 VEMS_E_11_03594_002.01                                     */
/*                 VEMS_E_11_03594_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGAIREXTPRES_vidDiagAirExtPres();                      */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input uint8 DIAGAIREXTPRES_u8Inhib;                                       */
/*  input boolean AirPres_bDgoMax_pAirExt;                                    */
/*  input boolean AirPres_bMonRunMax_pAirExt;                                 */
/*  input boolean AirPres_bDgoMin_pAirExt;                                    */
/*  input boolean AirPres_bMonRunMin_pAirExt;                                 */
/*  input boolean AirPres_bDgoGrd_pAirExt;                                    */
/*  input boolean AirPres_bMonRunGrd_pAirExt;                                 */
/*  input boolean AirPres_bDgoGrd_pAirExtOld;                                 */
/*  input boolean AirPres_bMonRunGrd_pAirExtOld;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlSlow_DiagAirExtPres                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlSlow_DiagAirExtPres(void)
{
   boolean bLocalCf_bPresPAirExtSens;


   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalCf_bPresPAirExtSens);
   if (DIAGAIREXTPRES_u8Inhib != 0x5A)
   {
      if (bLocalCf_bPresPAirExtSens != 0)
      {
         DIAGAIREXTPRES_vidDiagAirExtPres();
      }
      GDGAR_vidGdu(GD_DFT_MAX_PAIREXT,
                   AirPres_bDgoMax_pAirExt,
                   AirPres_bMonRunMax_pAirExt,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_MIN_PAIREXT,
                   AirPres_bDgoMin_pAirExt,
                   AirPres_bMonRunMin_pAirExt,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_GRD_PAIREXT,
                   AirPres_bDgoGrd_pAirExt,
                   AirPres_bMonRunGrd_pAirExt,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_GRD_PAIREXTOLD,
                   AirPres_bDgoGrd_pAirExtOld,
                   AirPres_bMonRunGrd_pAirExtOld,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveKOf_DiagAirExtPres                              */
/* !Description :  Evénement clef On_Off                                      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_03594_001.01                                     */
/*                 VEMS_E_11_03594_002.01                                     */
/*                 VEMS_E_11_03594_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGAIREXTPRES_vidMemBeforeWr();                         */
/*  input boolean Cf_bPresPAirExtSens;                                        */
/*  input uint8 DIAGAIREXTPRES_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_EveKOf_DiagAirExtPres                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveKOf_DiagAirExtPres(void)
{
   boolean bLocalCf_bPresPAirExtSens;


   VEMS_vidGET(Cf_bPresPAirExtSens, bLocalCf_bPresPAirExtSens);
   if (DIAGAIREXTPRES_u8Inhib != 0x5A)
   {
      if (bLocalCf_bPresPAirExtSens != 0)
      {
         DIAGAIREXTPRES_vidMemBeforeWr();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/