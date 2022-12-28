/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CRSCTLOUTTREAT                                          */
/* !Description     : CRSCTLOUTTREAT Component                                */
/*                                                                            */
/* !Module          : CRSCTLOUTTREAT                                          */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LA FONCTION XVV ET      */
/*                    L’ISCAN                                                 */
/*                                                                            */
/* !File            : CRSCTLOUTTREAT_SCH.C                                    */
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
/*   1 / CrsCtl_EveRst_CrsCtlOutTreat                                         */
/*   2 / CrsCtl_SdlFast_CrsCtlOutTreat                                        */
/*                                                                            */
/* !Reference   : V02 NT 12 01019 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#060743                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLOUTTREAT/CRSCTLOUTT$*/
/* $Revision::   1.0      $$Author::   alaouni        $$Date::   06 Apr 2012 $*/
/* $Author::   alaouni                                $$Date::   06 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CRSCTLOUTTREAT.h"
#include "CRSCTLOUTTREAT_l.h"
#include "CRSCTLOUTTREAT_IM.h"
#include "GDGAR.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_EveRst_CrsCtlOutTreat                               */
/* !Description :  Fonction d'accroche à l'evenement Reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  sakrani.nouha                                              */
/* !Trace_To    :  VEMS_R_09_03334_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLOUTTREAT_vidxVV_init();                            */
/*  extf argret void CRSCTLOUTTREAT_vidInitOutput();                          */
/*  extf argret void CRSCTLOUTTREAT_vidxVVFailCond();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : CrsCtl_EveRst_CrsCtlOutTreat                                   */
/* !Trigger  : CrsCtl_EveRst_CrsCtlOutTreat                                   */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_EveRst_CrsCtlOutTreat(void)
{
   CRSCTLOUTTREAT_vidxVV_init();
   CRSCTLOUTTREAT_vidInitOutput();
   CRSCTLOUTTREAT_vidxVVFailCond();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CrsCtl_SdlFast_CrsCtlOutTreat                              */
/* !Description :  Moniteur rapide pour la fonction xVV                       */
/* !Number      :  SCH.2                                                      */
/* !Author      :  sakrani.nouha                                              */
/* !Trace_To    :  VEMS_R_09_03334_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CRSCTLOUTTREAT_vidxVVStIndiCond();                       */
/*  extf argret void CRSCTLOUTTREAT_vidxVVFailCond();                         */
/*  extf argret void CRSCTLOUTTREAT_vidxVVInFctTreat();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 CRSCTLOUTTREAT_u8Inhib;                                       */
/*  input boolean CrsCtl_bDgoCrsCtlDft;                                       */
/*  input boolean CrsCtl_bMonRunCrsCtlDft;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : CrsCtl_SdlFast_CrsCtlOutTreat                                  */
/* !Trigger  : CrsCtl_SdlFast_CrsCtlOutTreat                                  */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CrsCtl_SdlFast_CrsCtlOutTreat(void)
{
   if (CRSCTLOUTTREAT_u8Inhib != 0x5A)
   {
      CRSCTLOUTTREAT_vidxVVStIndiCond();
      CRSCTLOUTTREAT_vidxVVFailCond();
      CRSCTLOUTTREAT_vidxVVInFctTreat();
      GDGAR_vidGdu(GD_DFT_CRSCTLDFT,
                   CrsCtl_bDgoCrsCtlDft,
                   CrsCtl_bMonRunCrsCtlDft,
                   DIAG_DISPO);
   }
}
/*--------------------------------- end of file ------------------------------*/