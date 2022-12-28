/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSFONCDIAG                                     */
/* !Description     : HEATSENO2DSFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2DSFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AVAL                       */
/*                                                                            */
/* !File            : HEATSENO2DSFONCDIAG_SCH.C                               */
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
/*   1 / SenO2Ds_EveRst_DsPlaus                                               */
/*   2 / SenO2Ds_SdlMid_DsPlaus                                               */
/*                                                                            */
/* !Reference   : V02 NT 11 07942 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSFONCDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   24 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   24 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "HEATSENO2DSFONCDIAG.h"
#include "HEATSENO2DSFONCDIAG_L.h"
#include "HEATSENO2DSFONCDIAG_IM.h"
#include "GDGAR.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_EveRst_DsPlaus                                     */
/* !Description :  Evènement reset du calculateur pour la fonction SenO2Ds    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSFONCDIAG_vidIniAvDiag();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_EveRst_DsPlaus                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_EveRst_DsPlaus(void)
{
   HEATSENO2DSFONCDIAG_vidIniAvDiag();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlMid_DsPlaus                                     */
/* !Description :  Moniteur moyen pour la fonction SenO2Ds                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSFONCDIAG_vidAvFDiag();                        */
/*  extf argret void HEATSENO2DSFONCDIAG_vidSeqFld();                         */
/*  extf argret void HEATSENO2DSFONCDIAG_vidModTran();                        */
/*  extf argret void HEATSENO2DSFONCDIAG_vidFcoMdEr6();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidFldMdEr6();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 HEATSENO2DSFONCDIAG_u8Inhib;                                  */
/*  input boolean SenO2Ds_bDgoORng_DsPlausFco;                                */
/*  input boolean SenO2Ds_bMonRunORng_DsPlausFco;                             */
/*  input boolean SenO2Ds_bMonWaitORng_DsPlausFco;                            */
/*  input boolean SenO2Ds_bDgoORng_DsPlausFld;                                */
/*  input boolean SenO2Ds_bMonRunORng_DsPlausFld;                             */
/*  input boolean SenO2Ds_bMonWaitORng_DsPlausFld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlMid_DsPlaus                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlMid_DsPlaus(void)
{
   if (HEATSENO2DSFONCDIAG_u8Inhib != 0x5A)
   {
      HEATSENO2DSFONCDIAG_vidAvFDiag();
      HEATSENO2DSFONCDIAG_vidSeqFld();
      HEATSENO2DSFONCDIAG_vidModTran();
      HEATSENO2DSFONCDIAG_vidFcoMdEr6();
      HEATSENO2DSFONCDIAG_vidFldMdEr6();
      GDGAR_vidGdu(GD_DFT_ORNG_DSPLAUSFCO,
                   SenO2Ds_bDgoORng_DsPlausFco,
                   SenO2Ds_bMonRunORng_DsPlausFco,
                   SenO2Ds_bMonWaitORng_DsPlausFco);
      GDGAR_vidGdu(GD_DFT_ORNG_DSPLAUSFLD,
                   SenO2Ds_bDgoORng_DsPlausFld,
                   SenO2Ds_bMonRunORng_DsPlausFld,
                   SenO2Ds_bMonWaitORng_DsPlausFld);
   }
}
/*---------------------------- end of file -----------------------------------*/