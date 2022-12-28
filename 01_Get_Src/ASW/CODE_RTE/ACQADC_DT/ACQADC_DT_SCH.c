/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQADC_DT                                               */
/* !Description     : ACQADC_DT Component.                                    */
/*                                                                            */
/* !Module          : ACQADC_DT                                               */
/* !Description     : SPECIFICATION OF ANALOG  ACQUISITIONS (ADCHAL)          */
/*                                                                            */
/* !File            : ACQADC_DT_SCH.C                                         */
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
/*   1 / AcqAdc_EveRst_AcqAdc                                                 */
/*   2 / AirPres_Eve14TDC_AcqAdc                                              */
/*   3 / AirPres_SdlMid_AcqAdc                                                */
/*   4 / FuAcq_EveInj_AcqAdc                                                  */
/*   5 / FuAcq_EveSpl_AcqAdc                                                  */
/*   6 / FuAcq_SdlFast_AcqAdc                                                 */
/*   7 / Oil_Eve14TDC_AcqAdc                                                  */
/*   8 / Oil_EveRst_AcqAdc                                                    */
/*   9 / Oil_SdlFast_AcqAdc                                                   */
/*   10 / SenAct_EveCrTR_AcqAdc                                               */
/*   11 / SenAct_EveRTSt_AcqAdc                                               */
/*   12 / SenAct_SdlMid_AcqAdc                                                */
/*   13 / SenAct_SdlSlow_AcqAdc                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6913284 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "ACQADC_DT.h"
#include "ACQADC_DT_L.h"
#include "ACQADC_DT_IM.h"
#include "ACQADC_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AcqAdc_EveRst_AcqAdc                                       */
/* !Description :  Rest event                                                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_DT_vidInit();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AcqAdc_EveRst_AcqAdc                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AcqAdc_EveRst_AcqAdc(void)
{
   ACQADC_DT_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_Eve14TDC_AcqAdc                                    */
/* !Description :  Quarter TDC event for SpgPresAcq.                          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidSpgPresAcq();                               */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_Eve14TDC_AcqAdc                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_Eve14TDC_AcqAdc(void)
{
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pUsThr;


   VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);
   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (   (bLocalCtrl_bAcv_pUsThr != 0)
          && (bLocalCoPTSt_bEngRun != 0))
      {
         ACQADC_DT_vidSpgPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlMid_AcqAdc                                      */
/* !Description :  Middle scheduler of AirPres function                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidSpgPresAcq();                               */
/*  input boolean Ctrl_bAcv_pUsThr;                                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlMid_AcqAdc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlMid_AcqAdc(void)
{
   boolean bLocalCoPTSt_bEngRun;
   boolean bLocalCtrl_bAcv_pUsThr;


   VEMS_vidGET(Ctrl_bAcv_pUsThr, bLocalCtrl_bAcv_pUsThr);
   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (   (bLocalCtrl_bAcv_pUsThr != 0)
          && (bLocalCoPTSt_bEngRun == 0))
      {
         ACQADC_DT_vidSpgPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_EveInj_AcqAdc                                        */
/* !Description :  Engine running indicator                                   */
/* !Number      :  SCH.4                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidPFuAcq_Inj();                               */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_EveInj_AcqAdc                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_EveInj_AcqAdc(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;


   VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         ACQADC_DT_vidPFuAcq_Inj();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_EveSpl_AcqAdc                                        */
/* !Description :  "Spill" event                                              */
/* !Number      :  SCH.5                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidPFuAcq_Spill();                             */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_EveSpl_AcqAdc                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_EveSpl_AcqAdc(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;


   VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         ACQADC_DT_vidPFuAcq_Spill();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_SdlFast_AcqAdc                                       */
/* !Description :  Fast monitor for rail pressure acquisition                 */
/* !Number      :  SCH.6                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidPFuAcq_Spill();                             */
/*  extf argret void ACQADC_DT_vidPFuAcq_Inj();                               */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Ext_bRun;                                                   */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_SdlFast_AcqAdc                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_SdlFast_AcqAdc(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;
   boolean bLocalExt_bRun;
   boolean bLocalMoteur_synchronise;


   VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);
   VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
   VEMS_vidGET(Ext_bRun, bLocalExt_bRun);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         if (bLocalMoteur_synchronise == 0)
         {
            ACQADC_DT_vidPFuAcq_Spill();
         }
         if (bLocalExt_bRun == 0)
         {
            ACQADC_DT_vidPFuAcq_Inj();
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_Eve14TDC_AcqAdc                                        */
/* !Description :  A Quarter TDC crankshaft angular based event               */
/* !Number      :  SCH.7                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidOilPresAcq();                               */
/*  input boolean Oil_bAcvCkOilPresAcq;                                       */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_Eve14TDC_AcqAdc                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_Eve14TDC_AcqAdc(void)
{
   boolean bLocalOil_bAcvCkOilPresAcq;


   VEMS_vidGET(Oil_bAcvCkOilPresAcq, bLocalOil_bAcvCkOilPresAcq);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (bLocalOil_bAcvCkOilPresAcq != 0)
      {
         ACQADC_DT_vidOilPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveRst_AcqAdc                                          */
/* !Description :  ECU Event Reset                                            */
/* !Number      :  SCH.8                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_DT_vidOilPresAcq();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_EveRst_AcqAdc                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveRst_AcqAdc(void)
{
   ACQADC_DT_vidOilPresAcq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlFast_AcqAdc                                         */
/* !Description :  Fast scheduler                                             */
/* !Number      :  SCH.9                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidOilPresAcq();                               */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input boolean Oil_bAcvCkOilPresAcq;                                       */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlFast_AcqAdc                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlFast_AcqAdc(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;
   boolean bLocalOil_bAcvCkOilPresAcq;


   VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
   VEMS_vidGET(Oil_bAcvCkOilPresAcq, bLocalOil_bAcvCkOilPresAcq);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (   (bLocalCtrl_bOilPropPresAcq != 0)
          && (bLocalOil_bAcvCkOilPresAcq == 0))
      {
         ACQADC_DT_vidOilPresAcq();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_EveCrTR_AcqAdc                                      */
/* !Description :  CRANK to RUN event                                         */
/* !Number      :  SCH.10                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_DT_vidTECUAcq();                                  */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_EveCrTR_AcqAdc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_EveCrTR_AcqAdc(void)
{
   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      ACQADC_DT_vidTECUAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_EveRTSt_AcqAdc                                      */
/* !Description :  RUN to STALL event                                         */
/* !Number      :  SCH.11                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_DT_vidTECUAcq();                                  */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_EveRTSt_AcqAdc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_EveRTSt_AcqAdc(void)
{
   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      ACQADC_DT_vidTECUAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_SdlMid_AcqAdc                                       */
/* !Description :  Middle scheduler                                           */
/* !Number      :  SCH.12                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQADC_DT_vidTECUAcq();                                  */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_SdlMid_AcqAdc                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_SdlMid_AcqAdc(void)
{
   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      ACQADC_DT_vidTECUAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_SdlSlow_AcqAdc                                      */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.13                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQADC_DT_vidTIGBTAcq();                                 */
/*  input boolean Ctrl_bAcvtIGBTAcq;                                          */
/*  input uint8 ACQADC_DT_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_SdlSlow_AcqAdc                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_SdlSlow_AcqAdc(void)
{
   boolean bLocalCtrl_bAcvtIGBTAcq;


   VEMS_vidGET(Ctrl_bAcvtIGBTAcq, bLocalCtrl_bAcvtIGBTAcq);

   if (ACQADC_DT_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcvtIGBTAcq != 0)
      {
         ACQADC_DT_vidTIGBTAcq();
      }
   }
}
/*------------------------------- end of file --------------------------------*/