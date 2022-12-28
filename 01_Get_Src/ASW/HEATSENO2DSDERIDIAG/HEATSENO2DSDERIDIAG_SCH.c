/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSDERIDIAG                                     */
/* !Description     : HEATSENO2DSDERIDIAG component.                          */
/*                                                                            */
/* !Module          : HEATSENO2DSDERIDIAG                                     */
/* !Description     : DIAGNOSTIC DERIVEE TENSION SONDE A OXYGENE AVAL.        */
/*                                                                            */
/* !File            : HEATSENO2DSDERIDIAG_SCH.C                               */
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
/*   1 / SenO2Ds_EveRst_SigGrdDiag                                            */
/*   2 / SenO2Ds_SdlMid_SigGrdDiag                                            */
/*   3 / SenO2Ds_SdlFast_SigGrdDiag                                           */
/*   4 / SenO2Ds_EvePwrl_SigGrdDiag                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5012852 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSDERIDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   18 Jan 2013 $*/
/* $Author::   etsasson                               $$Date::   18 Jan 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "HEATSENO2DSDERIDIAG.h"
#include "HEATSENO2DSDERIDIAG_L.h"
#include "HEATSENO2DSDERIDIAG_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_EveRst_SigGrdDiag                                  */
/* !Description :  Evènement reset du calculateur pour la fonction SenO2Ds    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_001.01                                     */
/*                 VEMS_R_11_07985_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSDERIDIAG_vidIniOutput();                      */
/*  extf argret void HEATSENO2DSDERIDIAG_vidTrkInit();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_EveRst_SigGrdDiag                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_EveRst_SigGrdDiag(void)
{
   HEATSENO2DSDERIDIAG_vidIniOutput();
   HEATSENO2DSDERIDIAG_vidTrkInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlMid_SigGrdDiag                                  */
/* !Description :  Moniteur moyen de la fonction SenO2Ds                      */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_001.01                                     */
/*                 VEMS_R_11_07985_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSDERIDIAG_vidSwitch();                         */
/*  extf argret void HEATSENO2DSDERIDIAG_vidTrkCond();                        */
/*  extf argret void HEATSENO2DSDERIDIAG_vidTrkDiag();                        */
/*  extf argret void HEATSENO2DSDERIDIAG_vidSeqDiag();                        */
/*  extf argret void HEATSENO2DSDERIDIAG_vidInitTran();                       */
/*  extf argret void HEATSENO2DSDERIDIAG_vidSigEuro6();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                     */
/*  input uint8 HEATSENO2DSDERIDIAG_u8Inhib;                                  */
/*  input boolean SenO2Ds_bDgoORng_SigGrdDiag;                                */
/*  input boolean SenO2Ds_bMonRunORng_SigGrdDiag;                             */
/*  input boolean SenO2Ds_bMonWaitORng_SigGrdDiag;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlMid_SigGrdDiag                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlMid_SigGrdDiag(void)
{
   if (HEATSENO2DSDERIDIAG_u8Inhib != 0x5A)
   {
      HEATSENO2DSDERIDIAG_vidSwitch();
      HEATSENO2DSDERIDIAG_vidTrkCond();
      HEATSENO2DSDERIDIAG_vidTrkDiag();
      HEATSENO2DSDERIDIAG_vidSeqDiag();
      HEATSENO2DSDERIDIAG_vidInitTran();
      HEATSENO2DSDERIDIAG_vidSigEuro6();
      GDGAR_vidGdu(GD_DFT_ORNG_SIGGRDDIAG,
                   SenO2Ds_bDgoORng_SigGrdDiag,
                   SenO2Ds_bMonRunORng_SigGrdDiag,
                   SenO2Ds_bMonWaitORng_SigGrdDiag);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_SdlFast_SigGrdDiag                                 */
/* !Description :  Moniteur rapide de la fonction SenO2Ds                     */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_001.01                                     */
/*                 VEMS_R_11_07985_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSDERIDIAG_vidTrkMgr();                         */
/*  input uint8 HEATSENO2DSDERIDIAG_u8Inhib;                                  */
/*  input boolean Ldsd_trk_cond_enable;                                       */
/*  input boolean HEATSENO2DSDERIDIAG_bCondEnaPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_SdlFast_SigGrdDiag                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_SdlFast_SigGrdDiag(void)
{
   if (HEATSENO2DSDERIDIAG_u8Inhib != 0x5A)
   {
      if (  (Ldsd_trk_cond_enable != 0)
         || (HEATSENO2DSDERIDIAG_bCondEnaPrev !=0))
      {
         HEATSENO2DSDERIDIAG_vidTrkMgr();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenO2Ds_EvePwrl_SigGrdDiag                                 */
/* !Description :  Evènement powerlatch du calculateur                        */
/* !Number      :  SCH.4                                                      */
/* !Author      :  Atef Dlili                                                 */
/* !Trace_To    :  VEMS_R_11_07985_001.01                                     */
/*                 VEMS_R_11_07985_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void HEATSENO2DSDERIDIAG_vidSavePwrl();                       */
/*  input uint8 HEATSENO2DSDERIDIAG_u8Inhib;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenO2Ds_EvePwrl_SigGrdDiag                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenO2Ds_EvePwrl_SigGrdDiag(void)
{
   if (HEATSENO2DSDERIDIAG_u8Inhib != 0x5A)
   {
      HEATSENO2DSDERIDIAG_vidSavePwrl();
   }
}
/*------------------------------- end of file --------------------------------*/