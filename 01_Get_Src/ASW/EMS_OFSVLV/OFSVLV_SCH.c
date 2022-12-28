/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OFSVLV                                                  */
/* !Description     : OFSVLV Component                                        */
/*                                                                            */
/* !Module          : OFSVLV                                                  */
/* !Description     : Limitation balayage et coordination des consignes VVT   */
/*                                                                            */
/* !File            : OFSVLV_SCH.C                                            */
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
/*   1 / VlvSys_EveIni_VlvArb                                                 */
/*   2 / VlvSys_SdlFast_VlvArb                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 02164 / 02                                        */
/* !OtherRefs   : 01460_10_03509_2/1.1                                        */
/* !OtherRefs   : VEMS V02 ECU#053816                                         */
/* !OtherRefs   : VEMS V02 ECU#054358                                         */
/* !OtherRefs   : VEMS V02 ECU#061723                                         */
/* !OtherRefs   : VEMS V02 ECU#067972                                         */
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
#include "OFSVLV.h"
#include "OFSVLV_L.h"
#include "OFSVLV_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_EveIni_VlvArb                                       */
/* !Description :  Evenement d'initialisation                                 */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_001.01                                     */
/*                 VEMS_R_11_02164_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidInit();                                        */
/*  extf argret void OFSVLV_vidInitOutput();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_EveIni_VlvArb                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_EveIni_VlvArb(void)
{
   OFSVLV_vidInit();
   OFSVLV_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvSys_SdlFast_VlvArb                                      */
/* !Description :  Evènement scheduler rapide de la fonctionVlvSys.           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_001.01                                     */
/*                 VEMS_R_11_02164_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidVlvArb();                                      */
/*  input uint8 OFSVLV_u8Inhib;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvSys_SdlFast_VlvArb                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvSys_SdlFast_VlvArb(void)
{
   if (OFSVLV_u8Inhib != 0x5A)
   {
      OFSVLV_vidVlvArb();
   }
}

/*------------------------------- end of file --------------------------------*/