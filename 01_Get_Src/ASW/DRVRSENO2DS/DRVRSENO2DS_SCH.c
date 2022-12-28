/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DRVRSENO2DS                                             */
/* !Description     : DRVRSENO2DS component                                   */
/*                                                                            */
/* !Module          : DRVRSENO2DS                                             */
/* !Description     : COMMANDE ET DIAGNOSTIC DE LA SORTIE LOGIQUE SONDE A     */
/*                    OXYGENE AVAL                                            */
/*                                                                            */
/* !File            : DRVRSENO2DS_SCH.c                                       */
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
/*   1 / DRVRSENO2DS_vidEntryInit                                             */
/*   2 / HeatSenO2_SdlFast_DrvrSenO2Ds                                        */
/*   3 / HeatSenO2_EveKOf_DrvrSenO2Ds                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6545446 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#047678                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/HEATSENO2/DRVRSENO2DS/DRVRSENO2DS_$*/
/* $Revision::   1.10     $$Author::   hmelloul       $$Date::   19 May 2014 $*/
/* $Author::   hmelloul                               $$Date::   19 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DRVRSENO2DS.h"
#include "DRVRSENO2DS_l.h"
#include "DRVRSENO2DS_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DRVRSENO2DS_vidEntryInit                                   */
/* !Description :  Evénement reset du calculateur.                            */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2DS_vidInitOutput();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : DRVRSENO2DS_vidEntryInit                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DRVRSENO2DS_vidEntryInit(void)
{
   DRVRSENO2DS_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_SdlFast_DrvrSenO2Ds                              */
/* !Description :  Récurrence rapide de la fonction HeatSenO2.                */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2DS_vidHeatSenO2DsCmd();                         */
/*  extf argret void DRVRSENO2DS_vidSdlDiag();                                */
/*  extf argret void DRVRSENO2DS_vidUAcqn();                                  */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input uint8 DRVRSENO2DS_u8Inhib;                                          */
/*  input boolean Ext_bDgoHi_DrvrSenO2Ds;                                     */
/*  input boolean Ext_bMonRunHi_DrvrSenO2Ds;                                  */
/*  input boolean Ext_bDgoLo_DrvrSenO2Ds;                                     */
/*  input boolean Ext_bMonRunLo_DrvrSenO2Ds;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_SdlFast_DrvrSenO2Ds                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_SdlFast_DrvrSenO2Ds(void)
{
   if (DRVRSENO2DS_u8Inhib != 0x5A)
   {
      DRVRSENO2DS_vidHeatSenO2DsCmd();
      DRVRSENO2DS_vidSdlDiag();
      DRVRSENO2DS_vidUAcqn();
      GDGAR_vidGdu(GD_DFT_HI_DRVRSENO2DS,
                   Ext_bDgoHi_DrvrSenO2Ds,
                   Ext_bMonRunHi_DrvrSenO2Ds,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_LO_DRVRSENO2DS,
                   Ext_bDgoLo_DrvrSenO2Ds,
                   Ext_bMonRunLo_DrvrSenO2Ds,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HeatSenO2_EveKOf_DrvrSenO2Ds                               */
/* !Description :  Evénement Clé On -> Off.                                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DRVRSENO2DS_vidHeatSenO2DsCmd();                         */
/*  input uint8 DRVRSENO2DS_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : HeatSenO2_EveKOf_DrvrSenO2Ds                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HeatSenO2_EveKOf_DrvrSenO2Ds(void)
{
   if (DRVRSENO2DS_u8Inhib != 0x5A)
   {
      DRVRSENO2DS_vidHeatSenO2DsCmd();
   }
}
/*------------------------------- End of file --------------------------------*/