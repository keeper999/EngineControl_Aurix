/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUPEDFREQACQ                                           */
/* !Description     : CLUPEDFREQACQ component.                                */
/*                                                                            */
/* !Module          : CLUPEDFREQACQ                                           */
/* !Description     : ACQUISITION DE LA MESURE DU CAPTEUR D’EMBRAYAGE         */
/*                    PROPORTIONNEL.                                          */
/*                                                                            */
/* !File            : CLUPEDFREQACQ_SCH.C                                     */
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
/*   1 / Clu_EveRst_CluPedFreqAcq                                             */
/*   2 / Clu_SdlFast_CluPedFreqAcq                                            */
/*   3 / Clu_SdlSfty_rCluPedPrssMes                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6562175 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CLUPEDFREQACQ/CLUPEDFREQACQ_SCH.C_$*/
/* $Revision::   1.8      $$Author::   achebino       $$Date::   21 May 2014 $*/
/* $Author::   achebino                               $$Date::   21 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "CLUPEDFREQACQ.h"
#include "CLUPEDFREQACQ_L.h"
#include "CLUPEDFREQACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_EveRst_CluPedFreqAcq                                   */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_001.01                                     */
/*                 VEMS_E_12_01136_002.01                                     */
/*                 VEMS_E_12_01136_003.01                                     */
/*                 VEMS_E_12_01136_004.01                                     */
/*                 VEMS_E_12_01136_005.01                                     */
/*                 VEMS_E_12_01136_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUPEDFREQACQ_vidInit();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_EveRst_CluPedFreqAcq                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_EveRst_CluPedFreqAcq(void)
{
   CLUPEDFREQACQ_vidInit();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlFast_CluPedFreqAcq                                  */
/* !Description :  Fonction d'accroche moniteur Clu_SdlFast_CluPedFreqAcq     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_001.01                                     */
/*                 VEMS_E_12_01136_002.01                                     */
/*                 VEMS_E_12_01136_003.01                                     */
/*                 VEMS_E_12_01136_004.01                                     */
/*                 VEMS_E_12_01136_005.01                                     */
/*                 VEMS_E_12_01136_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void CLUPEDFREQACQ_vidAcvCall();                              */
/*  input uint8 CLUPEDFREQACQ_u8Inhib;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_SdlFast_CluPedFreqAcq                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlFast_CluPedFreqAcq(void)
{
   if (CLUPEDFREQACQ_u8Inhib != 0x5A)
   {
      CLUPEDFREQACQ_vidAcvCall();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Clu_SdlSfty_rCluPedPrssMes                                 */
/* !Description :  Fonction d'accrochage moniteur Clu_SdlSfty_rCluPedPrssMes. */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_001.01                                     */
/*                 VEMS_E_12_01136_002.01                                     */
/*                 VEMS_E_12_01136_003.01                                     */
/*                 VEMS_E_12_01136_004.01                                     */
/*                 VEMS_E_12_01136_005.01                                     */
/*                 VEMS_E_12_01136_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void CLUPEDFREQACQ_vidDiagnosticniv2();                       */
/*  input uint8 CLUPEDFREQACQ_u8Inhib;                                        */
/*  input boolean Ext_bAcv_CluSftyLvl2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Clu_SdlSfty_rCluPedPrssMes                                     */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Clu_SdlSfty_rCluPedPrssMes(void)
{
   boolean bLocalExt_bAcv_CluSftyLvl2;


   if (CLUPEDFREQACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ext_bAcv_CluSftyLvl2, bLocalExt_bAcv_CluSftyLvl2);
      if (bLocalExt_bAcv_CluSftyLvl2 != 0)
      {
         CLUPEDFREQACQ_vidDiagnosticniv2();
      }
   }
}
/*------------------------------- end of file --------------------------------*/