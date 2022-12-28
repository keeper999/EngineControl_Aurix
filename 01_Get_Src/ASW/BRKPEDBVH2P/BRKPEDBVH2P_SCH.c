/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKPEDBVH2P                                             */
/* !Description     : BRKPEDBVH2P component.                                  */
/*                                                                            */
/* !Module          : BRKPEDBVH2P                                             */
/* !Description     : DIAGNOSTIC BVH2’ SUR L’INFORMATION FREIN FILAIRE        */
/*                                                                            */
/* !File            : BRKPEDBVH2P_SCH.C                                       */
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
/*   1 / BRKPEDBVH2P_vidEntryInit                                             */
/*   2 / Brk_SdlMid_BrkPedBVH2p                                               */
/*   3 / Brk_SdlSfty_BrkPedBVH2p                                              */
/*                                                                            */
/* !Reference   : V02 NT 10 02615 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#056811                                         */
/* !OtherRefs   : VEMS V02 ECU#056349                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHIBRK/BRKPEDBVH2P/BRKPEDBVH2P$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BRKPEDBVH2P.h"
#include "BRKPEDBVH2P_L.h"
#include "BRKPEDBVH2P_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKPEDBVH2P_vidEntryInit                                   */
/* !Description :  Evenement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_02615_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKPEDBVH2P_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BRKPEDBVH2P_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKPEDBVH2P_vidEntryInit(void)
{
   BRKPEDBVH2P_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlMid_BrkPedBVH2p                                     */
/* !Description :  Moniteur moyen du diagnostic acquisition frein.            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_02615_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKPEDBVH2P_vidEventGeneration();                        */
/*  input uint8 BRKPEDBVH2P_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_SdlMid_BrkPedBVH2p                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlMid_BrkPedBVH2p(void)
{
   if (BRKPEDBVH2P_u8Inhib != 0x5A)
   {
      BRKPEDBVH2P_vidEventGeneration();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Brk_SdlSfty_BrkPedBVH2p                                    */
/* !Description :  Moniteur du diagnostic niveau 2 acquisition frein.         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_02615_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BRKPEDBVH2P_vidDiagnostic_niv2();                        */
/*  input uint8 BRKPEDBVH2P_u8Inhib;                                          */
/*  input boolean Ext_bAcv_BrkSftyLvl2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Brk_SdlSfty_BrkPedBVH2p                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Brk_SdlSfty_BrkPedBVH2p(void)
{
   boolean bLocalExt_bAcv_BrkSftyLvl2;


   if (BRKPEDBVH2P_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bAcv_BrkSftyLvl2, bLocalExt_bAcv_BrkSftyLvl2);
      if (bLocalExt_bAcv_BrkSftyLvl2 != 0)
      {
         BRKPEDBVH2P_vidDiagnostic_niv2();
      }
   }
}
/*------------------------------- end of file --------------------------------*/