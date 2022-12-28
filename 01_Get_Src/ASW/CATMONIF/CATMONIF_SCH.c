/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CATMONIF                                                */
/* !Description     : CATMONIF component.                                     */
/*                                                                            */
/* !Module          : CATMONIF                                                */
/* !Description     : SPÉCIFICATION D'INTERFACE POUR LE DIAGNOSTIC CATALYSEUR */
/*                                                                            */
/* !File            : CATMONIF_SCH.C                                          */
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
/*   1 / CatMon_EveRst_CatMonIf                                               */
/*   2 / CatMon_SdlMid_CatMonIf                                               */
/*                                                                            */
/* !Reference   : V02 NT 12 04035 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#064360                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CATMONIF/CATMONIF_SCH.C_v         $*/
/* $Revision::   1.0      $$Author::   cbanchie       $$Date::   19 May 2011 $*/
/* $Author::   cbanchie                               $$Date::   19 May 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"CATMONIF.h"
#include"CATMONIF_L.h"
#include"CATMONIF_IM.h"
#include"GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CatMon_EveRst_CatMonIf                                     */
/* !Description :  Evenement reset                                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CATMONIF_vidInit();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CatMon_EveRst_CatMonIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CatMon_EveRst_CatMonIf(void)
{
   CATMONIF_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CatMon_SdlMid_CatMonIf                                     */
/* !Description :  Moniteur moyen de la fonction CatMonIf                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CATMONIF_vidCatMonIf();                                  */
/*  input uint8 CATMONIF_u8inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : CatMon_SdlMid_CatMonIf                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CatMon_SdlMid_CatMonIf(void)
{
   if (CATMONIF_u8inhib != 0x5A)
   {
      CATMONIF_vidCatMonIf();
   }
}

/*------------------------------ end of file ---------------------------------*/