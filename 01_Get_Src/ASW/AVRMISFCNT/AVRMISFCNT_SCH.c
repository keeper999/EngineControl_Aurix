/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AVRMISFCNT                                              */
/* !Description     : AVRMISFCNT component.                                   */
/*                                                                            */
/* !Module          : AVRMISFCNT                                              */
/* !Description     : MISFIRE COUNTER FOR OBD MODE$6                          */
/*                                                                            */
/* !File            : AVRMISFCNT_SCH.C                                        */
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
/*   1 / Misf_EveRst_AvrMisfCnt                                               */
/*   2 / Misf_EveMisf_AvrMisfCnt                                              */
/*   3 / Misf_EveKOf_AvrMisfCnt                                               */
/*   4 / Misf_EveCrTR_AvrMisfCnt                                              */
/*   5 / Misf_EveRstDftObd_AvrMisfCnt                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 05583 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/MISF/AVRMISFCNT/AVRMISFCNT_SCH.C$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   22 Feb 2012 $*/
/* $Author::   etsasson                               $$Date::   22 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "AVRMISFCNT.h"
#include "AVRMISFCNT_L.h"
#include "AVRMISFCNT_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRst_AvrMisfCnt                                     */
/* !Description :  ECU Reset event                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_05583_001.01                                     */
/*                 VEMS_R_11_05583_002.01                                     */
/*                 VEMS_R_11_05583_003.01                                     */
/*                 VEMS_R_11_05583_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AVRMISFCNT_vidInitOutput();                              */
/*  extf argret void AVRMISFCNT_vidInitCntMisf();                             */
/*  extf argret void AVRMISFCNT_vidNumMisfirePerCycle();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRst_AvrMisfCnt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRst_AvrMisfCnt(void)
{
   AVRMISFCNT_vidInitOutput();
   AVRMISFCNT_vidInitCntMisf();
   AVRMISFCNT_vidNumMisfirePerCycle();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveMisf_AvrMisfCnt                                    */
/* !Description :  Software Interruption event of the misfire acquisition     */
/*                 window end.                                                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_05583_001.01                                     */
/*                 VEMS_R_11_05583_002.01                                     */
/*                 VEMS_R_11_05583_003.01                                     */
/*                 VEMS_R_11_05583_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AVRMISFCNT_vidCntMisfPerCycleCyl();                      */
/*  extf argret void AVRMISFCNT_vidNumMisfirePerCycle();                      */
/*  input uint8 AVRMISFCNT_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveMisf_AvrMisfCnt                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveMisf_AvrMisfCnt(void)
{
   if (AVRMISFCNT_u8Inhib != 0x5A)
   {
      AVRMISFCNT_vidCntMisfPerCycleCyl();
      AVRMISFCNT_vidNumMisfirePerCycle();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveKOf_AvrMisfCnt                                     */
/* !Description :  Event key On_Off                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_05583_001.01                                     */
/*                 VEMS_R_11_05583_002.01                                     */
/*                 VEMS_R_11_05583_003.01                                     */
/*                 VEMS_R_11_05583_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void AVRMISFCNT_vidEWMA_MisfireCalc();                        */
/*  input uint8 AVRMISFCNT_u8Inhib;                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 MonMisf_nEngMinAcvCtMfAvg_C;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveKOf_AvrMisfCnt                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveKOf_AvrMisfCnt(void)
{
   uint16 u16LocalExt_nEng;


   if (AVRMISFCNT_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
      if (u16LocalExt_nEng >= MonMisf_nEngMinAcvCtMfAvg_C)
      {
         AVRMISFCNT_vidEWMA_MisfireCalc();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveCrTR_AvrMisfCnt                                    */
/* !Description :  Event CRANK To RUN for misfire function                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_05583_004.01                                     */
/*                 VEMS_R_11_05583_003.01                                     */
/*                 VEMS_R_11_05583_002.01                                     */
/*                 VEMS_R_11_05583_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AVRMISFCNT_vidReinit_Cnt_Misf();                         */
/*  extf argret void AVRMISFCNT_vidNumMisfirePerCycle();                      */
/*  input uint8 AVRMISFCNT_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveCrTR_AvrMisfCnt                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveCrTR_AvrMisfCnt(void)
{
   if (AVRMISFCNT_u8Inhib != 0x5A)
   {
      AVRMISFCNT_vidReinit_Cnt_Misf();
      AVRMISFCNT_vidNumMisfirePerCycle();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_EveRstDftObd_AvrMisfCnt                               */
/* !Description :  Event reset of defaults by the "mode 04"                   */
/* !Number      :  SCH.5                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_05583_004.01                                     */
/*                 VEMS_R_11_05583_003.01                                     */
/*                 VEMS_R_11_05583_002.01                                     */
/*                 VEMS_R_11_05583_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AVRMISFCNT_vidRstEWMAMisfireMod4();                      */
/*  input uint8 AVRMISFCNT_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_EveRstDftObd_AvrMisfCnt                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_EveRstDftObd_AvrMisfCnt(void)
{
   if (AVRMISFCNT_u8Inhib != 0x5A)
   {
      AVRMISFCNT_vidRstEWMAMisfireMod4();
   }
}
/*------------------------------- end of file --------------------------------*/