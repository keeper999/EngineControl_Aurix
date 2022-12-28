/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VSC                                                     */
/* !Description     : VSC Component                                           */
/*                                                                            */
/* !Module          : VSC                                                     */
/* !Description     : Aftersales memorization management of Vehicle speed     */
/*                    control                                                 */
/*                                                                            */
/* !File            : VSC_SCH.C                                               */
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
/*   1 / VSCTL_EveRst_LstCrsCtlDeacCaus                                       */
/*   2 / VSCTL_SdlMid_LstCrsCtlDeacCaus                                       */
/*                                                                            */
/* !Reference   : V02 NT 12 04370 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#064189                                         */
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

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "VSC.H"
#include "VSC_L.H"
#include "VSC_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSCTL_EveRst_LstCrsCtlDeacCaus                             */
/* !Description :  Evenement Reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_12_04370_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VSC_vidInit();                                           */
/*  extf argret void VSC_vidInit_Output();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VSCTL_EveRst_LstCrsCtlDeacCaus                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSCTL_EveRst_LstCrsCtlDeacCaus(void)
{
   VSC_vidInit();
   VSC_vidInit_Output();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSCTL_SdlMid_LstCrsCtlDeacCaus                             */
/* !Description :  Event SdlMid                                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_12_04370_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VSC_vidRecHis1();                                        */
/*  extf argret void VSC_vidRecHis2();                                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VSC_vidRecLstCrsCtlDeacCaus1();                          */
/*  extf argret void VSC_vidRecLstCrsCtlDeacCaus2();                          */
/*  input uint8 VSC_u8Inhib;                                                  */
/*  input uint8 VSCtl_stRec_stDeacVSRegReq1;                                  */
/*  input uint8 VSCtl_stRec_stDeacVSRegReq1Prev;                              */
/*  output uint8 VSCtl_stRec_stDeacVSRegReq1Prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VSCTL_SdlMid_LstCrsCtlDeacCaus                                 */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSCTL_SdlMid_LstCrsCtlDeacCaus(void)
{
   uint8 u8LocalVSCtlRecstDeacVSRegReq1;


   if (VSC_u8Inhib != 0x5A)
   {
      VSC_vidRecHis1();
      VSC_vidRecHis2();
      VEMS_vidGET(VSCtl_stRec_stDeacVSRegReq1, u8LocalVSCtlRecstDeacVSRegReq1);
      if (  (u8LocalVSCtlRecstDeacVSRegReq1 == 1)
         && (VSCtl_stRec_stDeacVSRegReq1Prev != u8LocalVSCtlRecstDeacVSRegReq1))
      {
         VSC_vidRecLstCrsCtlDeacCaus1();
         VSC_vidRecLstCrsCtlDeacCaus2();
      }
      VSCtl_stRec_stDeacVSRegReq1Prev =
         (uint8)MATHSRV_udtMIN(u8LocalVSCtlRecstDeacVSRegReq1, 2);
   }
}
/*------------------------------- end of file --------------------------------*/