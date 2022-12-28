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
/* !File            : FLOWMNG_SCH1.C                                          */
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
/*   1 / FLOWMNG_vidEntryInit                                                 */
/*   2 / Cf_EveRst_AirTFlowMng                                                */
/*   3 / Cf_SdlFast_FlowMngOilPres                                            */
/*   4 / Cf_SdlFast_FlowMngPwt                                                */
/*   5 / Cf_SdlSlow_FlowMng                                                   */
/*   6 / Cf_EvePwrl_FlowMng                                                   */
/*   7 / Cf_EveRxn552_FlowMng                                                 */
/*   8 / Cf_EveRxn552bis_FlowMng                                              */
/*   9 / Can_EveRxn349_FHCanF349_FlowMng                                      */
/*   10 / Cf_SdlMid_FlowMngGmv                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_SCH.C_v         $*/
/* $Revision::   1.10     $$Author::   pbakabad       $$Date::   Oct 22 2012 $*/
/* $Author::   pbakabad                               $$Date::   Oct 22 2012 $*/
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
/* !Function    :  FLOWMNG_vidEntryInit                                       */
/* !Description :  Evénement reset ECU du module FLOWMNG                      */
/* !Number      :  SCH1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidInitOutput();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FLOWMNG_vidEntryInit                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidEntryInit(void)
{
   FLOWMNG_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_AirTFlowMng                                      */
/* !Description :  Reset event of the external temprature.                    */
/* !Number      :  SCH1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidTExtMng();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_AirTFlowMng                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_AirTFlowMng(void)
{
   FLOWMNG_vidTExtMng();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngOilPres                                  */
/* !Description :  Scheduler rapide pour la fonction pression huile           */
/* !Number      :  SCH1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOil();                                        */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngOilPres                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngOilPres(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidOil();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlFast_FlowMngPwt                                      */
/* !Description :  Scheduler rapide de la fonction powertrain                 */
/* !Number      :  SCH1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDAGMP_Traction();                             */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlFast_FlowMngPwt                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlFast_FlowMngPwt(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidDAGMP_Traction();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlSlow_FlowMng                                         */
/* !Description :  Slow monitor of the FlowMng function                       */
/* !Number      :  SCH1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidTqSel();                                      */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlSlow_FlowMng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlSlow_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidTqSel();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EvePwrl_FlowMng                                         */
/* !Description :  Fonction d'accroche à l'événement power latch              */
/* !Number      :  SCH1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDayCtMng_EEPROM();                            */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EvePwrl_FlowMng                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EvePwrl_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidDayCtMng_EEPROM();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRxn552_FlowMng                                       */
/* !Description :  Evénement de réception de la trame 552.                    */
/* !Number      :  SCH1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_032.02                                     */
/*                 VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidFirst_DayCtMng();                             */
/*  extf argret void FLOWMNG_vidDayCtMng();                                   */
/*  extf argret void FLOWMNG_vidFirstDayCtMngInit();                          */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean FlowMng_bFirstTiCntMng;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRxn552_FlowMng                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRxn552_FlowMng(void)
{
   boolean bLocalExt_bArchiCf;


   if (FLOWMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
      if (bLocalExt_bArchiCf == 0)
      {
         /*02_First_DayCtMng*/
         FLOWMNG_vidFirst_DayCtMng();
         /*02_DayCtMng*/
         FLOWMNG_vidDayCtMng();
         if (FlowMng_bFirstTiCntMng == 0)
         {
            /*04_bFirstDayCtMng_Init*/
            FLOWMNG_vidFirstDayCtMngInit();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRxn552bis_FlowMng                                    */
/* !Description :  Evénement de réception de la trame 552bis                  */
/* !Number      :  SCH1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                 VEMS_R_11_00339_032.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidFirst_DayCtMng();                             */
/*  extf argret void FLOWMNG_vidDayCtMng();                                   */
/*  extf argret void FLOWMNG_vidFirstDayCtMngInit();                          */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean FlowMng_bFirstTiCntMng;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRxn552bis_FlowMng                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRxn552bis_FlowMng(void)
{
   boolean bLocalExt_bArchiCf;


   if (FLOWMNG_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
      if (bLocalExt_bArchiCf != 0)
      {
         /*02_First_DayCtMng*/
         FLOWMNG_vidFirst_DayCtMng();
         /*02_DayCtMng*/
         FLOWMNG_vidDayCtMng();
         if (FlowMng_bFirstTiCntMng == 0)
         {
            /*04_bFirstDayCtMng_Init*/
            FLOWMNG_vidFirstDayCtMngInit();
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn349_FHCanF349_FlowMng                            */
/* !Description :  Evenement de reception de la trame 349.                    */
/* !Number      :  SCH1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOutput_posnGBxLev();                          */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn349_FHCanF349_FlowMng                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn349_FHCanF349_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidOutput_posnGBxLev();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlMid_FlowMngGmv                                       */
/* !Description :  Scheduler moyen pour la sous fonction GMV                  */
/* !Number      :  SCH1.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidGMV();                                        */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlMid_FlowMngGmv                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlMid_FlowMngGmv(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidGMV();
   }
}
/*------------------------------- end of file --------------------------------*/