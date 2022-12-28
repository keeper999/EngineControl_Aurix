/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQWKUSIG                                               */
/* !Description     : ACQWKUSIG component                                     */
/*                                                                            */
/* !Module          : ACQWKUSIG                                               */
/* !Description     : Acquisition de la commande de reveil (rcd)              */
/*                                                                            */
/* !File            : ACQWKUSIG_SCH.C                                         */
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
/*   1 / EcuSt_EveRst_AcqWkuSig                                               */
/*   2 / EcuSt_SdlFast_AcqWkuSig                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6884549 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECUST/ACQWKUSIG/ACQWKUSIG_SCH.c_v $*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   23 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   23 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "ACQWKUSIG.h"
#include "ACQWKUSIG_l.h"
#include "ACQWKUSIG_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveRst_AcqWkuSig                                     */
/* !Description :  Evènement de reset calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_05622_001.01                                     */
/*                 VEMS_E_11_05622_002.01                                     */
/*                 VEMS_E_11_05622_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQWKUSIG_vidKeyOnOffInit();                             */
/*  extf argret void ACQWKUSIG_vidInitOutPut();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveRst_AcqWkuSig                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveRst_AcqWkuSig(void)
{
   ACQWKUSIG_vidKeyOnOffInit();
   ACQWKUSIG_vidInitOutPut();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlFast_AcqWkuSig                                    */
/* !Description :  Moniteur Rapide                                            */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Y.GANNOUN                                                  */
/* !Trace_To    :  VEMS_E_11_05622_001.01                                     */
/*                 VEMS_E_11_05622_002.01                                     */
/*                 VEMS_E_11_05622_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ACQWKUSIG_vidKeyTreatement();                            */
/*  input uint8 ACQWKUSIG_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_SdlFast_AcqWkuSig                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlFast_AcqWkuSig(void)
{
   if (ACQWKUSIG_u8Inhib != 0x5A)
   {
      ACQWKUSIG_vidKeyTreatement();
   }
}

/******************************** end of file *********************************/