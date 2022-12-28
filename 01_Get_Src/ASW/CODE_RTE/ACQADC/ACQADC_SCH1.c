/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQADC                                                  */
/* !Description     : ACQADC component.                                       */
/*                                                                            */
/* !Module          : ACQADC                                                  */
/* !Description     : Spécification des acquisitions analogiques (AdcHal)     */
/*                                                                            */
/* !File            : ACQADC_SCH1.C                                           */
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
/*   1 / Ext_EveRst_AcqAdc                                                    */
/*   2 / Pwr_EveRst_AcqAdc                                                    */
/*   3 / Pwr_SdlMid_AcqAdc                                                    */
/*   4 / Pwr_SdlFast_AcqAdc                                                   */
/*   5 / Pwr_EveRst_BattVoltAcqAdc                                            */
/*   6 / Pwr_SdlFast_BattVoltAcqAdc                                           */
/*   7 / Pwr_EveInj_BattVotlAcqAdc                                            */
/*   8 / Pwr_Sdl2ms_BattVotlAcqAdc                                            */
/*   9 / SenO2Us_SdlFast_UpLsAcqAdc                                           */
/*   10 / SenO2Ds_SdlFast_DsLsAcqAdc                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6669203 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQADC/ACQADC_SCH1.C_v            $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.H"
#include "ACQADC.H"
#include "ACQADC_L.H"
#include "ACQADC_IM.H"
#include "ACQADC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_EveRst_AcqAdc                                          */
/* !Description :  Event reset                                                */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidInit();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Ext_EveRst_AcqAdc                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_EveRst_AcqAdc(void)
{
   ACQADC_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveRst_AcqAdc                                          */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAlim();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_EveRst_AcqAdc                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveRst_AcqAdc(void)
{
   ACQADC_vidAcqAdcAlim();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlMid_AcqAdc                                          */
/* !Description :  Moniteur d'acquistion de la tension ALIM                   */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAlim();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlMid_AcqAdc                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlMid_AcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcAlim();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlFast_AcqAdc                                         */
/* !Description :  Moniteur rapide de la fonction ALIM capteurs               */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAlim();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlFast_AcqAdc                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlFast_AcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcAlim();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveRst_BattVoltAcqAdc                                  */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcBatt();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_EveRst_BattVoltAcqAdc                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveRst_BattVoltAcqAdc(void)
{
   ACQADC_vidAcqAdcBatt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlFast_BattVoltAcqAdc                                 */
/* !Description :  Moniteur rapide de la fonction power                       */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcBatt();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlFast_BattVoltAcqAdc                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlFast_BattVoltAcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcBatt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveInj_BattVotlAcqAdc                                  */
/* !Description :  Evenenement d'injection                                    */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcBatt();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*  input boolean Pwr_bEnaEveInj_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_EveInj_BattVotlAcqAdc                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveInj_BattVotlAcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (Pwr_bEnaEveInj_C != 0)
      {
         ACQADC_vidAcqAdcBatt();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_Sdl2ms_BattVotlAcqAdc                                  */
/* !Description :  Scheduler à 2ms                                            */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcBatt();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*  input boolean Pwr_bEnaEve2ms_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_Sdl2ms_BattVotlAcqAdc                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_Sdl2ms_BattVotlAcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (Pwr_bEnaEve2ms_C != 0)
      {
         ACQADC_vidAcqAdcBatt();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlFast_UpLsAcqAdc                                 */
/* !Description :  Moniteur rapide pour la fonction sonde amont               */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidAcqSenO2Us();                                  */
/*  input boolean Clef_de_contact;                                            */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_SdlFast_UpLsAcqAdc                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlFast_UpLsAcqAdc(void)
{
   boolean bLocalClef_de_contact;


   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   if (ACQADC_u8Inhib != 0x5A)
   {
      if (bLocalClef_de_contact != 0)
      {
         ACQADC_vidAcqSenO2Us();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlFast_DsLsAcqAdc                                 */
/* !Description :  Moniteur rapide pour la fonction sonde aval                */
/* !Number      :  SCH1.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqSenO2Ds();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlFast_DsLsAcqAdc                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlFast_DsLsAcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqSenO2Ds();
   }
}

/*------------------------------- end of file --------------------------------*/