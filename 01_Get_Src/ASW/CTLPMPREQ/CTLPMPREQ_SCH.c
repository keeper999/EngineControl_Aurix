/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CTLPMPREQ                                               */
/* !Description     : CTLPMPREQ component.                                    */
/*                                                                            */
/* !Module          : CTLPMPREQ                                               */
/* !Description     : OIL PUMP SOLENOID VALVE COMMAND AND DIAGNOSIS           */
/*                                                                            */
/* !File            : CTLPMPREQ_SCH.C                                         */
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
/*   1 / OilSysHw_EveRst_CtlPmpReq                                            */
/*   2 / OilSysHw_SdlFast_CtlPmpReq                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6851410 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/CTLPMPREQ/CTLPMPREQ_SCH.c_v $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   20 Oct 2014 $*/
/* $Author::   mbenfrad                               $$Date::   20 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customers                                  */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "CTLPMPREQ.H"
#include "CTLPMPREQ_L.H"
#include "CTLPMPREQ_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSysHw_EveRst_CtlPmpReq                                  */
/* !Description :  Event reset calculator.                                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_03160_001.01                                     */
/*                 VEMS_E_10_03160_002.01                                     */
/*                 VEMS_E_10_03160_003.01                                     */
/*                 VEMS_E_10_03160_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTLPMPREQ_vidInit();                                     */
/*  extf argret void CTLPMPREQ_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSysHw_EveRst_CtlPmpReq                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSysHw_EveRst_CtlPmpReq(void)
{
   CTLPMPREQ_vidInit();
   CTLPMPREQ_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OilSysHw_SdlFast_CtlPmpReq                                 */
/* !Description :  Quick Service Monitor of OilSysHw.                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  anaji                                                      */
/* !Trace_To    :  VEMS_E_10_03160_001.01                                     */
/*                 VEMS_E_10_03160_002.01                                     */
/*                 VEMS_E_10_03160_003.01                                     */
/*                 VEMS_E_10_03160_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CTLPMPREQ_vidCmdAndDiagEnable();                         */
/*  input uint8 CTLPMPREQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : OilSysHw_SdlFast_CtlPmpReq                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OilSysHw_SdlFast_CtlPmpReq(void)
{
   if (CTLPMPREQ_u8Inhib != 0x5A)
   {
      CTLPMPREQ_vidCmdAndDiagEnable();
   }
}
/*-------------------------------- end of file -------------------------------*/