/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INDICOBD                                                */
/* !Description     : INDICOBD Component                                      */
/*                                                                            */
/* !Module          : INDICOBD                                                */
/* !Description     : REGULATEUR DES INDICATEURS OBD                          */
/*                                                                            */
/* !File            : INDICOBD_SCH.c                                          */
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
/*   1 / GD_EveRst_IndicOBD                                                   */
/*   2 / GD_SdlSlow_IndicOBD                                                  */
/*   3 / GD_EveCrTR_IndicOBD                                                  */
/*   4 / GD_EveCrTSt_IndicOBD                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5075367 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#065277                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/INDICOBD/INDICOBD_SCH.C_v    $*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "INDICOBD.h"
#include "INDICOBD_L.h"
#include "INDICOBD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveRst_IndicOBD                                         */
/* !Description :  ECU reset event                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_06449_001.01                                     */
/*                 VEMS_E_10_06449_002.01                                     */
/*                 VEMS_E_10_06449_003.01                                     */
/*                 VEMS_E_10_06449_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidInit();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveRst_IndicOBD                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveRst_IndicOBD(void)
{
   INDICOBD_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_SdlSlow_IndicOBD                                        */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_06449_001.01                                     */
/*                 VEMS_E_10_06449_002.01                                     */
/*                 VEMS_E_10_06449_003.01                                     */
/*                 VEMS_E_10_06449_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidIndObdDstAndDurRstDf();                      */
/*  extf argret void INDICOBD_DstAndDurMIL();                                 */
/*  extf argret void INDICOBD_vidDstPrevCalc();                               */
/*  input uint8 INDICOBD_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_SdlSlow_IndicOBD                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_SdlSlow_IndicOBD(void)
{
   if(INDICOBD_u8Inhib != 0x5A)
   {
      INDICOBD_vidIndObdDstAndDurRstDf();
      INDICOBD_DstAndDurMIL();
      INDICOBD_vidDstPrevCalc();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveCrTR_IndicOBD                                        */
/* !Description :  Crank To Run event                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_06449_001.01                                     */
/*                 VEMS_E_10_06449_002.01                                     */
/*                 VEMS_E_10_06449_003.01                                     */
/*                 VEMS_E_10_06449_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidEnableEngRun();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveCrTR_IndicOBD                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveCrTR_IndicOBD(void)
{
   INDICOBD_vidEnableEngRun();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GD_EveCrTSt_IndicOBD                                       */
/* !Description :  Crank To Stall event                                       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_06449_001.01                                     */
/*                 VEMS_E_10_06449_002.01                                     */
/*                 VEMS_E_10_06449_003.01                                     */
/*                 VEMS_E_10_06449_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INDICOBD_vidDisableEngRun();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : GD_EveCrTSt_IndicOBD                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void GD_EveCrTSt_IndicOBD(void)
{
   INDICOBD_vidDisableEngRun();
}
/*-------------------------------- end of file -------------------------------*/