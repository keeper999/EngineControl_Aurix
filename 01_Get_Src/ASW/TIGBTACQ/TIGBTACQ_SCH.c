/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TIGBTACQ                                                */
/* !Description     : TIGBTACQ component.                                     */
/*                                                                            */
/* !Module          : TIGBTACQ                                                */
/* !Description     : Ignition Coil IGBT temperature acquisition              */
/*                                                                            */
/* !File            : TIGBTACQ_SCH.C                                          */
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
/*   1 / SenAct_EveRst_tIGBTAcq                                               */
/*   2 / SenAct_SdlSlow_tIGBTAcq                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5257921 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "TIGBTACQ.H"
#include "TIGBTACQ_IM.H"
#include "TIGBTACQ_L.H"
#include "VEMS.H"
#include "GDGAR.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_EveRst_tIGBTAcq                                     */
/* !Description :  Reset event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  PTS_R_5257921_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TIGBTACQ_vidInit();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_EveRst_tIGBTAcq                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_EveRst_tIGBTAcq(void)
{
   TIGBTACQ_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SenAct_SdlSlow_tIGBTAcq                                    */
/* !Description :  Slow scheduler                                             */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  PTS_R_5257921_001.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TIGBTACQ_vidAcquisition();                               */
/*  extf argret void TIGBTACQ_vidDiagnosis();                                 */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Ctrl_bAcvtIGBTAcq;                                          */
/*  input uint8 TIGBTACQ_u8Inhib;                                             */
/*  input boolean SenAct_bDgoScg_tIGBTAcq;                                    */
/*  input boolean SenAct_bMonRunScg_tIGBTAcq;                                 */
/*  input boolean SenAct_bDgoScp_tIGBTAcq;                                    */
/*  input boolean SenAct_bMonRunScp_tIGBTAcq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : SenAct_SdlSlow_tIGBTAcq                                        */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SenAct_SdlSlow_tIGBTAcq(void)
{
   boolean bLocalCtrl_bAcvtIGBTAcq;


   VEMS_vidGET(Ctrl_bAcvtIGBTAcq, bLocalCtrl_bAcvtIGBTAcq);
   if (TIGBTACQ_u8Inhib != 0x5A)
   {
      if (bLocalCtrl_bAcvtIGBTAcq != 0)
      {
         TIGBTACQ_vidAcquisition();
         TIGBTACQ_vidDiagnosis();
         GDGAR_vidGdu(GD_DFT_SCG_TIGBTACQ,
                      SenAct_bDgoScg_tIGBTAcq,
                      SenAct_bMonRunScg_tIGBTAcq,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCP_TIGBTACQ,
                      SenAct_bDgoScp_tIGBTAcq,
                      SenAct_bMonRunScp_tIGBTAcq,
                      DIAG_DISPO);
      }
   }
}

/*------------------------------ End of file ---------------------------------*/