/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SECUBV                                                  */
/* !Description     : SECUBV Component                                        */
/*                                                                            */
/* !Module          : SECUBV                                                  */
/* !Description     : Sécuriser Boites                                        */
/*                                                                            */
/* !File            : SECUBV_SCH.C                                            */
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
/*   1 / SECUBV_vidEntryInit                                                  */
/*   2 / SftyMgt_Sdl40ms_GBxChk                                               */
/*                                                                            */
/* !Reference   : V02 NT 10 01251 / 03                                        */
/* !OtherRefs   : 01460_09_01310 / 1.2                                        */
/* !OtherRefs   : VEMS V02 ECU#047007                                         */
/* !OtherRefs   : VEMS V02 ECU#050657                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_SCH.C_v $*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SECUBV.h"
#include "SECUBV_L.h"
#include "SECUBV_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SECUBV_vidEntryInit                                        */
/* !Description :  évènement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_001.02                                     */
/*                 VEMS_R_10_01251_046.01                                     */
/*                 VEMS_R_10_01251_100.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SECUBV_vidEntryInit                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SECUBV_vidEntryInit(void)
{
   SECUBV_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_Sdl40ms_GBxChk                                     */
/* !Description :  L’évènement d’appel des fonctions permettants de sécuriser */
/*                 les demandes de couple boites BVA ou BVMP                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01251_001.02                                     */
/*                 VEMS_R_10_01251_046.01                                     */
/*                 VEMS_R_10_01251_100.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SECUBV_vidBVConfiguration();                             */
/*  extf argret void SECUBV_vidBVMConfiguration();                            */
/*  extf argret void SECUBV_vidBVABVMPConfiguration();                        */
/*  input uint8 SECUBV_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SftyMgt_Sdl40ms_GBxChk                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_Sdl40ms_GBxChk(void)
{
   if (SECUBV_u8Inhib != 0x5A)
   {
      SECUBV_vidBVConfiguration();
      SECUBV_vidBVMConfiguration();
      SECUBV_vidBVABVMPConfiguration();
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/