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
/* !File            : ACQADC_SCH3.C                                           */
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
/*   1 / AC_SdlFast_ACPresAcqAdc                                              */
/*   2 / AC_EveRst_ACPresAcqAdc                                               */
/*   3 / CoT_SdlMid_AcqCoTAdc                                                 */
/*   4 / CoT_EveStTR_AcqCoTAdc                                                */
/*   5 / CoT_EveRst_AcqCoTAdc                                                 */
/*   6 / AirT_EveRst_AcqAirTAdc                                               */
/*   7 / AirT_SdlMid_AcqAirTAdc                                               */
/*   8 / AccP_EveRst_AcqPosnAdc                                               */
/*   9 / AccP_SdlFast_AcqPosnAdc                                              */
/*   10 / AccP_SdlFast_SwtAcqDiagAdc                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6669203 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQADC/ACQADC_SCH3.C_v            $*/
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
/* !Function    :  AC_SdlFast_ACPresAcqAdc                                    */
/* !Description :  Moniteur rapide de la fonction climatisation               */
/* !Number      :  SCH3.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcPresAC();                                */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_SdlFast_ACPresAcqAdc                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_SdlFast_ACPresAcqAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcPresAC();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AC_EveRst_ACPresAcqAdc                                     */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH3.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcPresAC();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AC_EveRst_ACPresAcqAdc                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AC_EveRst_ACPresAcqAdc(void)
{
   ACQADC_vidAcqAdcPresAC();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_SdlMid_AcqCoTAdc                                       */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH3.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcCoT();                                   */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_SdlMid_AcqCoTAdc                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_SdlMid_AcqCoTAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcCoT();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveStTR_AcqCoTAdc                                      */
/* !Description :  Evénement correspondant au passage à 1 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH3.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcCoT();                                   */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveStTR_AcqCoTAdc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveStTR_AcqCoTAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcCoT();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CoT_EveRst_AcqCoTAdc                                       */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH3.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcCoT();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CoT_EveRst_AcqCoTAdc                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CoT_EveRst_AcqCoTAdc(void)
{
   ACQADC_vidAcqAdcCoT();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_EveRst_AcqAirTAdc                                     */
/* !Description :  Evènement reset                                            */
/* !Number      :  SCH3.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAirT();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_EveRst_AcqAirTAdc                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_EveRst_AcqAirTAdc(void)
{
   ACQADC_vidAcqAdcAirT();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirT_SdlMid_AcqAirTAdc                                     */
/* !Description :  Moniteur moyen                                             */
/* !Number      :  SCH3.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAirT();                                  */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirT_SdlMid_AcqAirTAdc                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirT_SdlMid_AcqAirTAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcAirT();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_EveRst_AcqPosnAdc                                     */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH3.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAccP1();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_EveRst_AcqPosnAdc                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_EveRst_AcqPosnAdc(void)
{
   ACQADC_vidAcqAdcAccP1();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_AcqPosnAdc                                    */
/* !Description :  Moniteur rapide de la fonction pédale d'accélérateur       */
/* !Number      :  SCH3.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_vidAcqAdcAccP1();                                 */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_AcqPosnAdc                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_AcqPosnAdc(void)
{
   if (ACQADC_u8Inhib != 0x5A)
   {
      ACQADC_vidAcqAdcAccP1();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AccP_SdlFast_SwtAcqDiagAdc                                 */
/* !Description :  Moniteur rapide pour la fonction pédale                    */
/* !Number      :  SCH3.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_vidAcqAdcAccP2();                                 */
/*  input boolean AccP_bHdPtSen;                                              */
/*  input boolean Presence_bva_pt_dur;                                        */
/*  input boolean Presence_bvmp_pt_dur;                                       */
/*  input boolean Ext_bVSLimCf;                                               */
/*  input uint8 ACQADC_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AccP_SdlFast_SwtAcqDiagAdc                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AccP_SdlFast_SwtAcqDiagAdc(void)
{
   boolean bLocalAccP_bHdPtSen;
   boolean bLocalPresence_bva_pt_dur;
   boolean bLocalPresence_bvmp_pt_dur;
   boolean bLocalExt_bVSLimCf;


   VEMS_vidGET(AccP_bHdPtSen, bLocalAccP_bHdPtSen);
   VEMS_vidGET(Presence_bva_pt_dur, bLocalPresence_bva_pt_dur);
   VEMS_vidGET(Presence_bvmp_pt_dur, bLocalPresence_bvmp_pt_dur);
   VEMS_vidGET(Ext_bVSLimCf, bLocalExt_bVSLimCf);
   if (ACQADC_u8Inhib != 0x5A)
   {
      if (  (bLocalAccP_bHdPtSen == 0)
         && (  (bLocalPresence_bva_pt_dur != 0)
            || (bLocalPresence_bvmp_pt_dur != 0)
            || (bLocalExt_bVSLimCf != 0)))
      {
         ACQADC_vidAcqAdcAccP2();
      }
   }
}

/*------------------------------- end of file --------------------------------*/