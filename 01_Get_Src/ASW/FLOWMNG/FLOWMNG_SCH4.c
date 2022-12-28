/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FLOWMNG                                                 */
/* !Description     : FLOWMNG Component                                       */
/*                                                                            */
/* !Module          : FLOWMNG                                                 */
/* !Description     : Management of the configurable information flow         */
/*                                                                            */
/* !File            : FLOWMNG_SCH4.C                                          */
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
/*   1 / Cf_EveRst_FlowMngPwt                                                 */
/*   2 / Cf_EveRst_FlowMngTqSel                                               */
/*   3 / Cf_SdlFast_FlowMngAlt                                                */
/*   4 / Cf_SdlFast_FlowMngBatt                                               */
/*   5 / Cf_SdlFast_FlowMngBrk                                                */
/*   6 / Cf_SdlFast_FlowMngBrkAsi                                             */
/*   7 / Cf_SdlFast_FlowMngClu_1                                              */
/*   8 / Cf_SdlFast_FlowMngClu_2                                              */
/*   9 / Cf_SdlFast_FlowMngGear                                               */
/*   10 / Cf_SdlFast_FlowMngPedPrss                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
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

#include "STD_TYPES.h"
#include "FLOWMNG.h"
#include "FLOWMNG_L.h"
#include "FLOWMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngPwt                                       */
/* !Description :  Evenement reset de la fonction powertrain                  */
/* !Number      :  SCH4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDAGMP_Traction();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngPwt                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngPwt(void)
{
   FLOWMNG_vidDAGMP_Traction();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngTqSel                                     */
/* !Description :  Evenement de reset de la fonction couple                   */
/* !Number      :  SCH4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidTqSel();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngTqSel                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngTqSel(void)
{
   FLOWMNG_vidTqSel();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngAlt                                      */
/* !Description :  Scheduler rapide pour l'alternateur                        */
/* !Number      :  SCH4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidAltFlowMng_Processing();                      */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngAlt                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngAlt(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidAltFlowMng_Processing();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngBatt                                     */
/* !Description :  Scheduler rapide pour la tension batterie                  */
/* !Number      :  SCH4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidCANSeln();                                    */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngBatt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngBatt(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidCANSeln();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngBrk                                      */
/* !Description :  Scheduler rapide pour la pedale de frein                   */
/* !Number      :  SCH4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidBrk_CAN_Info();                               */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*  input st09 Rcd_power_state;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngBrk                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngBrk(void)
{
   uint8   u8LocalRcd_power_state;


   if (FLOWMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
      if ( (u8LocalRcd_power_state != RCD_TRANSIT)
         &&(u8LocalRcd_power_state != RCD_POWER_LATCH))
      {
         FLOWMNG_vidBrk_CAN_Info();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngBrkAsi                                   */
/* !Description :  Scheduler rapide pour le mastervac                         */
/* !Number      :  SCH4.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidPMastervac();                                 */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngBrkAsi                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngBrkAsi(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidPMastervac();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngClu_1                                    */
/* !Description :  Fast clutch monitoring                                     */
/* !Number      :  SCH4.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidClu();                                        */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngClu_1                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngClu_1(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidClu();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngClu_2                                    */
/* !Description :  Fast clutch monitoring                                     */
/* !Number      :  SCH4.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidClu2();                                       */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngClu_2                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngClu_2(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidClu2();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngGear                                     */
/* !Description :  Scheduler rapide de la fonction gear                       */
/* !Number      :  SCH4.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidPosGearLev();                                 */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngGear                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngGear(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidPosGearLev();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngPedPrss                                  */
/* !Description :  Scheduler rapide de la pedale de frein                     */
/* !Number      :  SCH4.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidBrkPush();                                    */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*  input boolean ECU_bWkuMain;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngPedPrss                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngPedPrss(void)
{
   boolean bLocalECU_bWkuMain;


   if (FLOWMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(ECU_bWkuMain, bLocalECU_bWkuMain);
      if (bLocalECU_bWkuMain != 0)
      {
         FLOWMNG_vidBrkPush();
      }
   }
}
/*------------------------------- end of file --------------------------------*/