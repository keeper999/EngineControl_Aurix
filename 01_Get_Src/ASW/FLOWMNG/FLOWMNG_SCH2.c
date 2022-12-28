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
/* !File            : FLOWMNG_SCH2.C                                          */
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
/*   1 / Can_EveRxn489_FHCanF489_FlowMng                                      */
/*   2 / Cf_EveTele_TunCfg_FlowMng                                            */
/*   3 / Can_SdlSlow_FHCanF349_FlowMng                                        */
/*   4 / Can_EveRxn552_FHCanF552_FlowMng                                      */
/*   5 / Can_EveRxn7F2_FHCanF7F2_FlowMng                                      */
/*   6 / Can_EveRst_FHCanF349_FlowMng                                         */
/*   7 / Can_EveRst_FHCanF552_FlowMng                                         */
/*   8 / Cf_EveRst_FlowMngAlt                                                 */
/*   9 / Cf_EveRst_FlowMngBatt                                                */
/*   10 / Cf_SdlMid_FlowMngTAir                                               */
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
/* !Function    :  Can_EveRxn489_FHCanF489_FlowMng                            */
/* !Description :  Evenement de reception de la trame 489.                    */
/* !Number      :  SCH2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOutput_posnGBxLev();                          */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn489_FHCanF489_FlowMng                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn489_FHCanF489_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidOutput_posnGBxLev();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveTele_TunCfg_FlowMng                                  */
/* !Description :  Evénement télécodage.                                      */
/* !Number      :  SCH2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOutput_posnGBxLev();                          */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveTele_TunCfg_FlowMng                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveTele_TunCfg_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidOutput_posnGBxLev();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_SdlSlow_FHCanF349_FlowMng                              */
/* !Description :  Moniteur lent pour la fonction FH CAN F349h.               */
/* !Number      :  SCH2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOutput_posnGBxLev();                          */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_SdlSlow_FHCanF349_FlowMng                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_SdlSlow_FHCanF349_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidOutput_posnGBxLev();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn552_FHCanF552_FlowMng                            */
/* !Description :  Evenement de reception de la trame 552.                    */
/* !Number      :  SCH2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDstVeh();                                     */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn552_FHCanF552_FlowMng                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn552_FHCanF552_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidDstVeh();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRxn7F2_FHCanF7F2_FlowMng                            */
/* !Description :  Evenement de reception de la trame 7F2.                    */
/* !Number      :  SCH2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDstVeh();                                     */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRxn7F2_FHCanF7F2_FlowMng                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRxn7F2_FHCanF7F2_FlowMng(void)
{
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      FLOWMNG_vidDstVeh();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF349_FlowMng                               */
/* !Description :  Evènement reset de l'ECU                                   */
/* !Number      :  SCH2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidOutput_posnGBxLev();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF349_FlowMng                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF349_FlowMng(void)
{
   FLOWMNG_vidOutput_posnGBxLev();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Can_EveRst_FHCanF552_FlowMng                               */
/* !Description :  Evénement reset de l'ECU                                   */
/* !Number      :  SCH2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDstVeh();                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Can_EveRst_FHCanF552_FlowMng                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Can_EveRst_FHCanF552_FlowMng(void)
{
   FLOWMNG_vidDstVeh();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngAlt                                       */
/* !Description :  Evenement reset pour l'alternateur                         */
/* !Number      :  SCH2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidAltFlowMng_Init();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngAlt                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngAlt(void)
{
   FLOWMNG_vidAltFlowMng_Init();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_EveRst_FlowMngBatt                                      */
/* !Description :  Evenement reset pour la tension batterie                   */
/* !Number      :  SCH2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidCANSeln();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_EveRst_FlowMngBatt                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_EveRst_FlowMngBatt(void)
{
   FLOWMNG_vidCANSeln();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Cf_SdlMid_FlowMngTAir                                      */
/* !Description :  Scheduler moyen pour la sous fonction TAie                 */
/* !Number      :  SCH2.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidTExtMng();                                    */
/*  input boolean Ctrl_bTAirExtMes;                                           */
/*  input uint8 FLOWMNG_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Cf_SdlMid_FlowMngTAir                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Cf_SdlMid_FlowMngTAir(void)
{
   boolean bLocalCtrl_bTAirExtMes;


   VEMS_vidGET(Ctrl_bTAirExtMes, bLocalCtrl_bTAirExtMes);
   if (FLOWMNG_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bTAirExtMes != 0)
      {
         FLOWMNG_vidTExtMng();
      }
   }
}
/*------------------------------- end of file --------------------------------*/