/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DRVRSENO2US                                             */
/* !Description     : DRVRSENO2US Component                                   */
/*                                                                            */
/* !Module          : DRVRSENO2US                                             */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE SONDE A     */
/*                    OXYGENE AMONT                                           */
/*                                                                            */
/* !File            : DRVRSENO2US_SCH.C                                       */
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
/*   1 / DRVRSENO2US_vidEntryInit                                             */
/*   2 / HeatSenO2_SdlFast_DrvrSenO2Us                                        */
/*   3 / HeatSenO2_EveKOf_DrvrSenO2Us                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6559003 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047678                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/DRVRSENO2US/DRVRSENO2US_$*/
/* $Revision::   1.11     $$Author::   hmelloul       $$Date::   19 May 2014 $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DRVRSENO2US.h"
#include "DRVRSENO2US_l.h"
#include "DRVRSENO2US_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2US_vidEntryInit                                   */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2US_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DRVRSENO2US_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2US_vidEntryInit(void)
{
   DRVRSENO2US_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DrvrSenO2Us                              */
/* !Description :  Récurrence rapide de la fonction HeatSenO2.                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2US_vidHeatSenO2DsCmd();                         */
/*  extf argret void DRVRSENO2US_vidSdlDiag();                                */
/*  extf argret void DRVRSENO2US_vidUAcqn();                                  */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input uint8 DRVRSENO2US_u8Inhib;                                          */
/*  input boolean Ext_bDgoHi_DrvrSenO2Us;                                     */
/*  input boolean Ext_bMonRunHi_DrvrSenO2Us;                                  */
/*  input boolean Ext_bDgoLo_DrvrSenO2Us;                                     */
/*  input boolean Ext_bMonRunLo_DrvrSenO2Us;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DrvrSenO2Us                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DrvrSenO2Us(void)
{
   if (DRVRSENO2US_u8Inhib != 0x5A)
   {
      DRVRSENO2US_vidHeatSenO2DsCmd();
      DRVRSENO2US_vidSdlDiag();
      DRVRSENO2US_vidUAcqn();
      GDGAR_vidGdu(GD_DFT_HI_DRVRSENO2US,
                   Ext_bDgoHi_DrvrSenO2Us,
                   Ext_bMonRunHi_DrvrSenO2Us,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_DRVRSENO2US,
                   Ext_bDgoLo_DrvrSenO2Us,
                   Ext_bMonRunLo_DrvrSenO2Us,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveKOf_DrvrSenO2Us                               */
/* !Description :  Evénement Clé On -> Off.                                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2US_vidHeatSenO2DsCmd();                         */
/*  input uint8 DRVRSENO2US_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveKOf_DrvrSenO2Us                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveKOf_DrvrSenO2Us(void)
{
   if (DRVRSENO2US_u8Inhib != 0x5A)
   {
      DRVRSENO2US_vidHeatSenO2DsCmd();
   }
}
/*------------------------------- End of file --------------------------------*/