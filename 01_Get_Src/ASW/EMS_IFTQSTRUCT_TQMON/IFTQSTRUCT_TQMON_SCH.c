/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFTQSTRUCT_TQMON                                        */
/* !Description     : IFTQSTRUCT_TQMON Component                              */
/*                                                                            */
/* !Module          : IFTQSTRUCT_TQMON                                        */
/* !Description     : Safety TMS : Interface TMS                              */
/*                                                                            */
/* !File            : IFTQSTRUCT_TQMON_SCH.C                                  */
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
/*   1 / IFTQSTRUCT_TQMON_vidEntryInit                                        */
/*   2 / SftyMgt_Sdl10ms_IfTMS                                                */
/*   3 / SftyMgt_Sdl40ms_IfTMS                                                */
/*   4 / SftyMgt_SdlMid_bEnaTqOfs                                             */
/*   5 / SftyMgt_SdlMid_bInjCutOff                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5050415 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2536 / 2.11 br1                                 */
/* !OtherRefs   : VEMS V02 ECU#058176                                         */
/* !OtherRefs   : VEMS V02 ECU#059384                                         */
/* !OtherRefs   : VEMS V02 ECU#060678                                         */
/* !OtherRefs   : VEMS V02 ECU#065782                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/IFTQSTRUCT_TQMON/IFTQS$*/
/* $Revision::   1.19     $$Author::   mbenfrad       $$Date::   15 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   15 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "IFTQSTRUCT_TQMON.h"
#include "IFTQSTRUCT_TQMON_L.h"
#include "IFTQSTRUCT_TQMON_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFTQSTRUCT_TQMON_vidEntryInit                              */
/* !Description :  Evenement reset du calculateur .                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFTQSTRUCT_TQMON_vidInitOutput();                        */
/*  extf argret void IFTQSTRUCT_TQMON_vidInitOutputBis();                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : IFTQSTRUCT_TQMON_vidEntryInit                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFTQSTRUCT_TQMON_vidEntryInit(void)
{
   IFTQSTRUCT_TQMON_vidInitOutput();
   IFTQSTRUCT_TQMON_vidInitOutputBis();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_Sdl10ms_IfTMS                                      */
/* !Description :  evenement pour le contrôle de la fonction                  */
/*                 :Generer_info_10ms                                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFTQSTRUCT_TQMON_vidGenerInf10ms();                      */
/*  input uint8 IFTQSTRUCT_TQMON_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_Sdl10ms_IfTMS                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_Sdl10ms_IfTMS(void)
{
   /*QAC Warning(2:4152): Name imposed by specification*/
   if (IFTQSTRUCT_TQMON_u8Inhib != 0x5A)
   {
      IFTQSTRUCT_TQMON_vidGenerInf10ms();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_Sdl40ms_IfTMS                                      */
/* !Description :  evenement pour le contrôle de la fonction                  */
/*                 :Generer_info_40ms                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFTQSTRUCT_TQMON_vidFluxInternes();                      */
/*  extf argret void IFTQSTRUCT_TQMON_vidGenerInfTran();                      */
/*  input uint8 IFTQSTRUCT_TQMON_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_Sdl40ms_IfTMS                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_Sdl40ms_IfTMS(void)
{
   if (IFTQSTRUCT_TQMON_u8Inhib != 0x5A)
   {
      IFTQSTRUCT_TQMON_vidFluxInternes();
      IFTQSTRUCT_TQMON_vidGenerInfTran();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_bEnaTqOfs                                   */
/* !Description :  evenement pour le contrôle de la fonction                  */
/*                 :Generer_info_tolerance                                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFTQSTRUCT_TQMON_vidGenerInfTole();                      */
/*  input uint8 IFTQSTRUCT_TQMON_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_bEnaTqOfs                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_bEnaTqOfs(void)
{
   if (IFTQSTRUCT_TQMON_u8Inhib != 0x5A)
   {
      IFTQSTRUCT_TQMON_vidGenerInfTole();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_bInjCutOff                                  */
/* !Description :  evenement pour le contrôle de la fonction :gerer coupure   */
/*                 injection                                                  */
/* !Number      :  SCH.5                                                      */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IFTQSTRUCT_TQMON_vidGerCprInject();                      */
/*  input uint8 IFTQSTRUCT_TQMON_u8Inhib;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_SdlMid_bInjCutOff                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_bInjCutOff(void)
{
   if (IFTQSTRUCT_TQMON_u8Inhib != 0x5A)
   {
      IFTQSTRUCT_TQMON_vidGerCprInject();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/
