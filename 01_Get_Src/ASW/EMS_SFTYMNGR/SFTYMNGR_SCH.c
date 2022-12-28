/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMNGR                                                */
/* !Description     : SFTYMNGR Component                                      */
/*                                                                            */
/* !Module          : SFTYMNGR                                                */
/* !Description     : SAFETY TMS :SAFETY MANAGER                              */
/*                                                                            */
/* !File            : SFTYMNGR_SCH.C                                          */
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
/*   1 / SFTYMNGR_vidEntryInit                                                */
/*   2 / SftyMgt_SdlMid_SftyMgr                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_SCH.$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "SFTYMNGR.h"
#include "SFTYMNGR_l.h"
#include "SFTYMNGR_IM.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEntryInit                                      */
/* !Description :  evenement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_002.01                                     */
/*                 VEMS_R_10_01256_003.01                                     */
/*                 VEMS_R_10_01256_004.01                                     */
/*                 VEMS_R_10_01256_005.01                                     */
/*                 VEMS_R_10_01256_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidInitOutput();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : SFTYMNGR_vidEntryInit                                          */
/* !Trigger  : SFTYMNGR_vidEntryInit                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEntryInit(void)
{
   SFTYMNGR_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SftyMgt_SdlMid_SftyMgr                                     */
/* !Description :  fonction d'accroche de l'evenement SftyMgt_SdlMid_SftyMgr  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_002.01                                     */
/*                 VEMS_R_10_01256_003.01                                     */
/*                 VEMS_R_10_01256_004.01                                     */
/*                 VEMS_R_10_01256_005.01                                     */
/*                 VEMS_R_10_01256_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SFTYMNGR_vidTraiteMem1();                                */
/*  extf argret void SFTYMNGR_vidCalculeMiseEnVeille();                       */
/*  extf argret void SFTYMNGR_vidAdaptationEdge();                            */
/*  extf argret void SFTYMNGR_vidGereEscalade();                              */
/*  extf argret void SFTYMNGR_vidTraiteMem2();                                */
/*  extf argret void SFTYMNGR_vidSyntheseDefauts();                           */
/*  input uint8 SFTYMNGR_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : SftyMgt_SdlMid_SftyMgr                                         */
/* !Trigger  : SftyMgt_SdlMid_SftyMgr                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SftyMgt_SdlMid_SftyMgr(void)
{
   if (SFTYMNGR_u8Inhib != 0x5A)
   {
      SFTYMNGR_vidTraiteMem1();
      SFTYMNGR_vidCalculeMiseEnVeille();
      SFTYMNGR_vidAdaptationEdge();
      SFTYMNGR_vidGereEscalade();
      SFTYMNGR_vidTraiteMem2();
      SFTYMNGR_vidSyntheseDefauts();
   }
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/