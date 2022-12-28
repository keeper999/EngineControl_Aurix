/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILPROPPRESACQ                                          */
/* !Description     : OILPROPPRESACQ Component                                */
/*                                                                            */
/* !Module          : OILPROPPRESACQ                                          */
/* !Description     : OIL PROPORTIONAL PRESSURE ACQUISITION AND DIAGNOSIS     */
/*                                                                            */
/* !File            : OILPROPPRESACQ_SCH.C                                    */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Oil_EveRst_OilPropPresAcq                                            */
/*   2 / Oil_SdlFast_OilPropPresAcq                                           */
/*   3 / Oil_Eve14TDC_OilPropPresAcq                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6978050 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/OILPROPPRESACQ/OILPROPPRESAC$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   20 Oct 2014 $*/
/* $Author::   mbenfrad                               $$Date::   20 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OILPROPPRESACQ.h"
#include "OILPROPPRESACQ_L.h"
#include "OILPROPPRESACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_EveRst_OilPropPresAcq                                  */
/* !Description :  ECU Event Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_03195_001.01                                     */
/*                 VEMS_E_10_03195_006.03                                     */
/*                 VEMS_E_10_03195_007.02                                     */
/*                 VEMS_R_10_03195_001.03                                     */
/*                 VEMS_R_10_03195_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILPROPPRESACQ_vidInitialization();                      */
/*  extf argret void OILPROPPRESACQ_vidOilAcqCond();                          */
/*  extf argret void OILPROPPRESACQ_vidInitPrsAcqMean();                      */
/*  extf argret void OILPROPPRESACQ_vidInitOilPrsFilt();                      */
/*  extf argret void OILPROPPRESACQ_vidInitOutput();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_EveRst_OilPropPresAcq                                      */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_EveRst_OilPropPresAcq(void)
{
   OILPROPPRESACQ_vidInitialization();
   OILPROPPRESACQ_vidOilAcqCond();
   OILPROPPRESACQ_vidInitPrsAcqMean();
   OILPROPPRESACQ_vidInitOilPrsFilt();
   OILPROPPRESACQ_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_SdlFast_OilPropPresAcq                                 */
/* !Description :  Fast scheduler.                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_03195_001.01                                     */
/*                 VEMS_E_10_03195_006.03                                     */
/*                 VEMS_E_10_03195_007.02                                     */
/*                 VEMS_R_10_03195_001.03                                     */
/*                 VEMS_R_10_03195_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILPROPPRESACQ_vidOilAcqCond();                          */
/*  extf argret void OILPROPPRESACQ_vidOilSdlFastEna();                       */
/*  input uint8 OILPROPPRESACQ_u8Inhib;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_SdlFast_OilPropPresAcq                                     */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_SdlFast_OilPropPresAcq(void)
{
   if (OILPROPPRESACQ_u8Inhib != 0x5A)
   {
      OILPROPPRESACQ_vidOilAcqCond();
      OILPROPPRESACQ_vidOilSdlFastEna();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Oil_Eve14TDC_OilPropPresAcq                                */
/* !Description :  Evénement d'appel de tâche "quart de PMH" du CMM.          */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_03195_001.01                                     */
/*                 VEMS_E_10_03195_006.03                                     */
/*                 VEMS_E_10_03195_007.02                                     */
/*                 VEMS_R_10_03195_001.03                                     */
/*                 VEMS_R_10_03195_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILPROPPRESACQ_vidOilPresAcqMean();                      */
/*  input uint8 OILPROPPRESACQ_u8Inhib;                                       */
/*  input boolean Oil_bAcvCkOilPresAcq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Oil_Eve14TDC_OilPropPresAcq                                    */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Oil_Eve14TDC_OilPropPresAcq(void)
{
   boolean bLocalOil_bAcvCkOilPresAcq;


   if (OILPROPPRESACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Oil_bAcvCkOilPresAcq, bLocalOil_bAcvCkOilPresAcq);
      if (bLocalOil_bAcvCkOilPresAcq != 0)
      {
         OILPROPPRESACQ_vidOilPresAcqMean();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/