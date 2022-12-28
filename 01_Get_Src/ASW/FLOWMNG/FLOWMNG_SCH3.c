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
/* !File            : FLOWMNG_SCH3.C                                          */
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
/*   1 / Cf_EveRst_FlowMngBrk                                                 */
/*   2 / Cf_EveRst_FlowMngBrkAsi                                              */
/*   3 / Cf_EveRst_FlowMngClu_1                                               */
/*   4 / Cf_EveRst_FlowMngClu_2                                               */
/*   5 / Cf_EveRst_FlowMngDayCt                                               */
/*   6 / Cf_EveRst_FlowMngGear                                                */
/*   7 / Cf_EveRst_FlowMngGmv                                                 */
/*   8 / Cf_EveRst_FlowMngOilPres                                             */
/*   9 / Cf_EveRst_FlowMngPedPrss                                             */
/*   10 / Cf_SdlMid_FlowMngTOil                                               */
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
/* !Function    :  Cf_EveRst_FlowMngBrk                                       */
/* !Description :  Evenement reset pour la pedale de frein                    */
/* !Number      :  SCH3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidBrk_CAN_Info();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngBrk                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngBrk(void)
{
   FLOWMNG_vidBrk_CAN_Info();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngBrkAsi                                    */
/* !Description :  Evenement reset pour le mastervac                          */
/* !Number      :  SCH3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidPMastervac();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngBrkAsi                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngBrkAsi(void)
{
   FLOWMNG_vidPMastervac();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngClu_1                                     */
/* !Description :  Evenement de reset de la pedale d'embrayage                */
/* !Number      :  SCH3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidClu();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngClu_1                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngClu_1(void)
{
   FLOWMNG_vidClu();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngClu_2                                     */
/* !Description :  Evenement de reset de la pedale d'embrayage                */
/* !Number      :  SCH3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidClu2();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngClu_2                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngClu_2(void)
{
   FLOWMNG_vidClu2();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngDayCt                                     */
/* !Description :  Evenement reset pour le compteur                           */
/* !Number      :  SCH3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidInit_EEPROM();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngDayCt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngDayCt(void)
{
   FLOWMNG_vidInit_EEPROM();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngGear                                      */
/* !Description :  Evenement reset de la fonction gear                        */
/* !Number      :  SCH3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidPosGearLev();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngGear                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngGear(void)
{
   FLOWMNG_vidPosGearLev();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngGmv                                       */
/* !Description :  Evenement reset pour la sous fonction GMV                  */
/* !Number      :  SCH3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidGMV();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngGmv                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngGmv(void)
{
   FLOWMNG_vidGMV();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngOilPres                                   */
/* !Description :  Evenement reset pour la fonction pression huile            */
/* !Number      :  SCH3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOil();                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngOilPres                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngOilPres(void)
{
   FLOWMNG_vidOil();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngPedPrss                                   */
/* !Description :  Evenement reset de la pedale de frein                      */
/* !Number      :  SCH3.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidBrkPush();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngPedPrss                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngPedPrss(void)
{
   FLOWMNG_vidBrkPush();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlMid_FlowMngTOil                                      */
/* !Description :  Scheduler moyen pour la sous fonction TOil                 */
/* !Number      :  SCH3.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidTOilMng();                                    */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*  input st09 Rcd_power_state;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlMid_FlowMngTOil                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlMid_FlowMngTOil(void)
{
   uint8 u8LocalRcd_power_state;


   if (FLOWMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Rcd_power_state, u8LocalRcd_power_state);
      if (  (u8LocalRcd_power_state != RCD_TRANSIT)
         && (u8LocalRcd_power_state != RCD_POWER_LATCH))
      {
         FLOWMNG_vidTOilMng();
      }
   }
}
/*------------------------------- end of file --------------------------------*/