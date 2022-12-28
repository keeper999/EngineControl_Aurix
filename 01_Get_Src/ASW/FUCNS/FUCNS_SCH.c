/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FUCNS                                                   */
/* !Description     : FUCNS component.                                        */
/*                                                                            */
/* !Module          : FUCNS                                                   */
/* !Description     : CONSOMMATION CARBURANT                                  */
/*                                                                            */
/* !File            : FUCNS_SCH.C                                             */
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
/*   1 / Fu_EveRst_FuCns                                                      */
/*   2 / Fu_EveInj_FuCns                                                      */
/*   3 / Fu_SdlMid_FuCns                                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5139613 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066800                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FU/FUCNS/FUCNS_SCH.C_v          $*/
/* $Revision::   1.6      $$Author::   HHAMLAOU       $$Date::   02 Sep 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   02 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "FUCNS.H"
#include "FUCNS_L.H"
#include "FUCNS_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveRst_FuCns                                            */
/* !Description :  Evènement Reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_09_03050_024.01                                     */
/*                 VEMS_E_09_03050_025.01                                     */
/*                 VEMS_E_09_03050_026.01                                     */
/*                 VEMS_E_11_00116_001.01                                     */
/*                 VEMS_E_11_00116_002.01                                     */
/*                 VEMS_E_11_00116_003.01                                     */
/*                 VEMS_E_11_00116_004.01                                     */
/*                 VEMS_E_11_00116_005.01                                     */
/*                 VEMS_E_11_00116_006.01                                     */
/*                 VEMS_E_11_00116_007.01                                     */
/*                 VEMS_E_11_00116_008.01                                     */
/*                 VEMS_E_11_00116_009.01                                     */
/*                 VEMS_E_11_00116_010.01                                     */
/*                 VEMS_E_11_00116_011.01                                     */
/*                 VEMS_E_11_00116_012.01                                     */
/*                 VEMS_E_11_00116_013.01                                     */
/*                 VEMS_E_11_00116_014.01                                     */
/*                 VEMS_E_11_00116_015.01                                     */
/*                 VEMS_E_11_00116_016.01                                     */
/*                 VEMS_E_11_00116_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUCNS_vidInitOutput();                                   */
/*  extf argret void FUCNS_vidInit();                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveRst_FuCns                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveRst_FuCns(void)
{
   FUCNS_vidInitOutput();
   FUCNS_vidInit();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_EveInj_FuCns                                            */
/* !Description :  Evènement injection pour la fonction carburant             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_09_03050_024.01                                     */
/*                 VEMS_E_09_03050_025.01                                     */
/*                 VEMS_E_09_03050_026.01                                     */
/*                 VEMS_E_11_00116_001.01                                     */
/*                 VEMS_E_11_00116_002.01                                     */
/*                 VEMS_E_11_00116_003.01                                     */
/*                 VEMS_E_11_00116_004.01                                     */
/*                 VEMS_E_11_00116_005.01                                     */
/*                 VEMS_E_11_00116_006.01                                     */
/*                 VEMS_E_11_00116_007.01                                     */
/*                 VEMS_E_11_00116_008.01                                     */
/*                 VEMS_E_11_00116_009.01                                     */
/*                 VEMS_E_11_00116_010.01                                     */
/*                 VEMS_E_11_00116_011.01                                     */
/*                 VEMS_E_11_00116_012.01                                     */
/*                 VEMS_E_11_00116_013.01                                     */
/*                 VEMS_E_11_00116_014.01                                     */
/*                 VEMS_E_11_00116_015.01                                     */
/*                 VEMS_E_11_00116_016.01                                     */
/*                 VEMS_E_11_00116_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUCNS_vidCalcTotalMassInj();                             */
/*  input uint8 FUCNS_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_EveInj_FuCns                                                */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_EveInj_FuCns(void)
{
   if (FUCNS_u8Inhib != 0x5A)
   {
      FUCNS_vidCalcTotalMassInj();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Fu_SdlMid_FuCns                                            */
/* !Description :  Moniteur moyen pour la fonction Fu                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  L.DHIB                                                     */
/* !Trace_To    :  VEMS_E_09_03050_024.01                                     */
/*                 VEMS_E_09_03050_025.01                                     */
/*                 VEMS_E_09_03050_026.01                                     */
/*                 VEMS_E_11_00116_001.01                                     */
/*                 VEMS_E_11_00116_002.01                                     */
/*                 VEMS_E_11_00116_003.01                                     */
/*                 VEMS_E_11_00116_004.01                                     */
/*                 VEMS_E_11_00116_005.01                                     */
/*                 VEMS_E_11_00116_006.01                                     */
/*                 VEMS_E_11_00116_007.01                                     */
/*                 VEMS_E_11_00116_008.01                                     */
/*                 VEMS_E_11_00116_009.01                                     */
/*                 VEMS_E_11_00116_010.01                                     */
/*                 VEMS_E_11_00116_011.01                                     */
/*                 VEMS_E_11_00116_012.01                                     */
/*                 VEMS_E_11_00116_013.01                                     */
/*                 VEMS_E_11_00116_014.01                                     */
/*                 VEMS_E_11_00116_015.01                                     */
/*                 VEMS_E_11_00116_016.01                                     */
/*                 VEMS_E_11_00116_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FUCNS_vidCalcRealConso();                                */
/*  extf argret void FUCNS_vidCalcPseudoConso();                              */
/*  extf argret void FUCNS_vidFinalInstructionCalc();                         */
/*  extf argret void FUCNS_vidSendFrame();                                    */
/*  input uint8 FUCNS_u8Inhib;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Fu_SdlFast_FuCns                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Fu_SdlMid_FuCns(void)
{
   if (FUCNS_u8Inhib != 0x5A)
   {
      FUCNS_vidCalcRealConso();
      FUCNS_vidCalcPseudoConso();
      FUCNS_vidFinalInstructionCalc();
      FUCNS_vidSendFrame();
   }
}
/*------------------------------- end of file --------------------------------*/