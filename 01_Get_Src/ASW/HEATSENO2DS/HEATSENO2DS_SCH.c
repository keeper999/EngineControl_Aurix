/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DS                                             */
/* !Description     : HEATSENO2DS Component                                   */
/*                                                                            */
/* !Module          : HEATSENO2DS                                             */
/* !Description     : GESTION CHAUFFAGE SONDE AVAL                            */
/*                                                                            */
/* !File            : HEATSENO2DS_SCH.C                                       */
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
/*   1 / HeatSenO2_EveRst_DsMgr                                               */
/*   2 / HeatSenO2_SdlFast_DsMgr                                              */
/*   3 / HeatSenO2_SdlMid_DsMgr                                               */
/*   4 / HeatSenO2_EveStTCr_DsMgr                                             */
/*   5 / HeatSenO2_EveCrTR_DsMgr                                              */
/*   6 / HeatSenO2_EveRTSt_DsMgr                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5421274 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#061098                                         */
/* !OtherRefs   : VEMS V02 ECU#064424                                         */
/* !OtherRefs   : VEMS V02 ECU#064562                                         */
/* !OtherRefs   : VEMS V02 ECU#066568                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/HEATSENO2DS/HEATSENO2DS_$*/
/* $Revision::   1.11     $$Author::   wbouach        $$Date::   25 Apr 2012 $*/
/* $Author::   wbouach                                $$Date::   25 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "HEATSENO2DS.h"
#include "HEATSENO2DS_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRst_DsMgr                                     */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidInitOutput();                             */
/*  extf argret void HEATSENO2DS_vidLsDsDetRTStallint();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveRst_DsMgr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRst_DsMgr(void)
{
   HEATSENO2DS_vidInitOutput();
   HEATSENO2DS_vidLsDsDetRTStallint();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DsMgr                                    */
/* !Description :  Moniteur rapide pour le module chauffage sonde O2          */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidMgrFastTran();                            */
/*  input uint8 HEATSENO2DS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DsMgr                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DsMgr(void)
{
   if (HEATSENO2DS_u8Inhib != 0x5A)
   {
      HEATSENO2DS_vidMgrFastTran();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlMid_DsMgr                                     */
/* !Description :  Moniteur moyen pour le module chauffage sonde O2           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidLsDsDewPt();                              */
/*  extf argret void HEATSENO2DS_vidMgrMidTran();                             */
/*  extf argret void HEATSENO2DS_vidMgrSlowTran();                            */
/*  extf argret void HEATSENO2DS_vidLsDsMgrHeatState();                       */
/*  input uint8 HEATSENO2DS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlMid_DsMgr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlMid_DsMgr(void)
{
   if (HEATSENO2DS_u8Inhib != 0x5A)
   {
      HEATSENO2DS_vidLsDsDewPt();
      HEATSENO2DS_vidMgrMidTran();
      HEATSENO2DS_vidMgrSlowTran();
      HEATSENO2DS_vidLsDsMgrHeatState();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveStTCr_DsMgr                                   */
/* !Description :  Evenement de détection  du passage de  l'état stall vers   */
/*                 cranking                                                   */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidLsDsDetRTStallint();                      */
/*  input uint8 HEATSENO2DS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveStTCr_DsMgr                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveStTCr_DsMgr(void)
{
   if (HEATSENO2DS_u8Inhib != 0x5A)
   {
      HEATSENO2DS_vidLsDsDetRTStallint();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveCrTR_DsMgr                                    */
/* !Description :  Evénement de détection le passage de cranking to running   */
/* !Number      :  SCH.5                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidLsDsDetRTStallint();                      */
/*  input uint8 HEATSENO2DS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveCrTR_DsMgr       								  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveCrTR_DsMgr(void)
{
   if (HEATSENO2DS_u8Inhib != 0x5A)
   {
      HEATSENO2DS_vidLsDsDetRTStallint();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveRTSt_DsMgr                                    */
/* !Description :  Evenement de détection le passage de l'état running vers   */
/*                 stall                                                      */
/* !Number      :  SCH.6                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_08_03331_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DS_vidLsDsDetRTStall();                         */
/*  input uint8 HEATSENO2DS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveRTSt_DsMgr									      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveRTSt_DsMgr(void)
{
   if (HEATSENO2DS_u8Inhib != 0x5A)
   {
      HEATSENO2DS_vidLsDsDetRTStall();
   }
}
/*------------------------------- end of file --------------------------------*/