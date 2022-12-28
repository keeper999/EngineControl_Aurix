/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFROUGHNSROADCAN                                      */
/* !Description     : MISFROUGHNSROADCAN component.                           */
/*                                                                            */
/* !Module          : MISFROUGHNSROADCAN                                      */
/* !Description     : DETECTION DE LA MAUVAISE ROUTE EN FONCTION DE LA VITESSE*/
/*                    DES ROUES                                               */
/*                                                                            */
/* !File            : MISFROUGHNSROADCAN_SCH.C                                */
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
/*   1 / MISFROUGHNSROADCAN_vidEntryInit                                      */
/*   2 / Misf_SdlFast_MisfRoughnsRoadCan                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 01896 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFROUGHNSROADCAN/MISFROUGHN$*/
/* $Revision::   1.2      $$Author::   wbouach        $$Date::   29 Jun 2010 $*/
/* $Author::   wbouach                                $$Date::   29 Jun 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MISFROUGHNSROADCAN.h"
#include "MISFROUGHNSROADCAN_L.h"
#include "MISFROUGHNSROADCAN_IM.h"
#include "GDGAR.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFROUGHNSROADCAN_vidEntryInit                            */
/* !Description :  Evénement reset du calculateur.                           */
/* !Number      :  SCH.1                                                      */
/* !Author      :  ALI.FARES                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFROUGHNSROADCAN_vidInitOutput();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : MISFROUGHNSROADCAN_vidEntryInit                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFROUGHNSROADCAN_vidEntryInit(void)
{
   MISFROUGHNSROADCAN_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Misf_SdlFast_MisfRoughnsRoadCan                            */
/* !Description :  Moniteur rapide pour la fonction Misfire.                  */
/* !Number      :  SCH.2                                                      */
/* !Author      :  ALI.FARES                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFROUGHNSROADCAN_vidClcn();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 MISFROUGHNSROADCAN_u8Inhib;                                   */
/*  input boolean Misf_bDgoLostMisfRoughnsRoad;                               */
/*  input boolean Misf_bMonRunLostMisfRoughnsRoad;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Misf_SdlFast_MisfRoughnsRoadCan                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Misf_SdlFast_MisfRoughnsRoadCan(void)
{
   if(MISFROUGHNSROADCAN_u8Inhib != 0x5A)
   {
      MISFROUGHNSROADCAN_vidClcn();
      GDGAR_vidGdu(GD_DFT_LOSTMISFROUGHNSROAD,
                   Misf_bDgoLostMisfRoughnsRoad,
                   Misf_bMonRunLostMisfRoughnsRoad,
                   DIAG_DISPO);
   }
}

/*------------------------------- end of file --------------------------------*/