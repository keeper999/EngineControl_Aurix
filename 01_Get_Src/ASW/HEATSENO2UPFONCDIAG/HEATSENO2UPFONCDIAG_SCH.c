/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPFONCDIAG                                     */
/* !Description     : HEATSENO2UPFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AMONT                      */
/*                                                                            */
/* !File            : HEATSENO2UPFONCDIAG_SCH.C                               */
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
/*   1 / SenO2Us_EveRst_UsPlaus                                               */
/*   2 / SenO2Us_SdlFast_UsPlaus                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5482727 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPFONCDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   17 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2UPFONCDIAG.h"
#include "HEATSENO2UPFONCDIAG_L.h"
#include "HEATSENO2UPFONCDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_EveRst_UsPlaus                                     */
/* !Description :  Evènement reset du calculateur pour la fonction SenO2Us    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07980_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPFONCDIAG_vidIniAmDiag();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_EveRst_UsPlaus                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_EveRst_UsPlaus(void)
{
   HEATSENO2UPFONCDIAG_vidIniAmDiag();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Us_SdlFast_UsPlaus                                    */
/* !Description :  Moniteur rapide pour la fonction SenO2Us                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07980_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2UPFONCDIAG_vidAmFDiag();                        */
/*  extf argret void HEATSENO2UPFONCDIAG_vidSeqFld();                         */
/*  extf argret void HEATSENO2UPFONCDIAG_vidModTran();                        */
/*  extf argret void HEATSENO2UPFONCDIAG_vidFcoMdEr6();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidFldMdEr6();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 HEATSENO2UPFONCDIAG_u8Inhib;                                  */
/*  input boolean SenO2Us_bDgoORng_UsPlausFco;                                */
/*  input boolean SenO2Us_bMonRunORng_UsPlausFco;                             */
/*  input boolean SenO2Us_bMonWaitORng_UsPlausFco;                            */
/*  input boolean SenO2Us_bDgoORng_UsPlausFld;                                */
/*  input boolean SenO2Us_bMonRunORng_UsPlausFld;                             */
/*  input boolean SenO2Us_bMonWaitORng_UsPlausFld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Us_SdlFast_UsPlaus                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Us_SdlFast_UsPlaus(void)
{
   if (HEATSENO2UPFONCDIAG_u8Inhib != 0x5A)
   {
      HEATSENO2UPFONCDIAG_vidAmFDiag();
      HEATSENO2UPFONCDIAG_vidSeqFld();
      HEATSENO2UPFONCDIAG_vidModTran();
      HEATSENO2UPFONCDIAG_vidFcoMdEr6();
      HEATSENO2UPFONCDIAG_vidFldMdEr6();
      GDGAR_vidGdu(GD_DFT_ORNG_USPLAUSFCO,
                   SenO2Us_bDgoORng_UsPlausFco,
                   SenO2Us_bMonRunORng_UsPlausFco,
                   SenO2Us_bMonWaitORng_UsPlausFco);
      GDGAR_vidGdu(GD_DFT_ORNG_USPLAUSFLD,
                   SenO2Us_bDgoORng_UsPlausFld,
                   SenO2Us_bMonRunORng_UsPlausFld,
                   SenO2Us_bMonWaitORng_UsPlausFld);
   }
}
/*---------------------------- end of file -----------------------------------*/