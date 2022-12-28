/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TECUACQ                                                 */
/* !Description     : TECUACQ Component                                       */
/*                                                                            */
/* !Module          : TECUACQ                                                 */
/* !Description     : ECU Temperature Acquisition                             */
/*                                                                            */
/* !File            : TECUACQ_SCH.C                                           */
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
/*   1 / SenAct_EveRst_tECUAcq                                                */
/*   2 / SenAct_SdlMid_tECUAcq                                                */
/*   3 / SenAct_EveCrTR_tECUAcq                                               */
/*   4 / SenAct_EveRTSt_tECUAcq                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6851405 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TECUACQ/TECUACQ_SCH.C_v         $*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   01 Sep 2014 $*/
/* $Author::   etsasson                               $$Date::   01 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TECUACQ.h"
#include "TECUACQ_L.h"
#include "TECUACQ_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_EveRst_tECUAcq                                      */
/* !Description :  EveRst for TECUACQ                                         */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TECUACQ_vidInit();                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_EveRst_tECUAcq                                          */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_EveRst_tECUAcq(void)
{
   TECUACQ_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_SdlMid_tECUAcq                                      */
/* !Description :  Middle scheduler                                           */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TECUACQ_vidAcquisition();                                */
/*  extf argret void TECUACQ_vidDiagnosis();                                  */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 TECUACQ_u8Inhib;                                              */
/*  input boolean SenAct_bDgoScg_tECUAcq;                                     */
/*  input boolean SenAct_bMonRunScg_tECUAcq;                                  */
/*  input boolean SenAct_bDgoScp_tECUAcq;                                     */
/*  input boolean SenAct_bMonRunScp_tECUAcq;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_SdlMid_tECUAcq                                          */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_SdlMid_tECUAcq(void)
{
   if (TECUACQ_u8Inhib != 0x5A)
   {
      TECUACQ_vidAcquisition();
      TECUACQ_vidDiagnosis();
      GDGAR_vidGdu(GD_DFT_SCG_TECUACQ,
                   SenAct_bDgoScg_tECUAcq,
                   SenAct_bMonRunScg_tECUAcq,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_TECUACQ,
                   SenAct_bDgoScp_tECUAcq,
                   SenAct_bMonRunScp_tECUAcq,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_EveCrTR_tECUAcq                                     */
/* !Description :  CRANK to RUN event                                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TECUACQ_vidAcquisition();                                */
/*  input uint8 TECUACQ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_EveCrTR_tECUAcq                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_EveCrTR_tECUAcq(void)
{
   if (TECUACQ_u8Inhib != 0x5A)
   {
      TECUACQ_vidAcquisition();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_EveRTSt_tECUAcq                                     */
/* !Description :  RUN to STALL event                                         */
/* !Number      :  SCH.4                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TECUACQ_vidAcquisition();                                */
/*  input uint8 TECUACQ_u8Inhib;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_EveRTSt_tECUAcq                                         */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_EveRTSt_tECUAcq(void)
{
   if (TECUACQ_u8Inhib != 0x5A)
   {
      TECUACQ_vidAcquisition();
   }
}

/*------------------------------- end of file --------------------------------*/