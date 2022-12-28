/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJTICOR                                                */
/* !Description     : INJTICOR component                                      */
/*                                                                            */
/* !Module          : INJTICOR                                                */
/* !Description     : CORRECTION DE LA RÉGULATION DE RICHESSE EN BUTÉE        */
/*                                                                            */
/* !File            : INJTICOR_SCH.C                                          */
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
/*   1 / Inj_EveRst_InjTiCor                                                  */
/*   2 / Inj_EveRTSt_InjTiCor                                                 */
/*   3 / Inj_SdlFast_InjTiCor                                                 */
/*   4 / Inj_SdlMid_InjTiCor                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5147608 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065914                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/INJTICOR/INJTICOR_SCH.C_v         $*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   20 Dec 2012 $*/
/* $Author::   achebino                               $$Date::   20 Dec 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "INJTICOR.h"
#include "INJTICOR_L.h"
#include "INJTICOR_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveRst_InjTiCor                                        */
/* !Description :  Reset du calculateur.                                      */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_03211_001.03                                     */
/*                 VEMS_R_09_03211_002.03                                     */
/*                 VEMS_R_09_03211_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidInitOutput();                                */
/*  extf argret void INJTICOR_vidInitLfbkMonitoring();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveRst_InjTiCor                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveRst_InjTiCor(void)
{
   INJTICOR_vidInitOutput();
   INJTICOR_vidInitLfbkMonitoring();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_EveRTSt_InjTiCor                                       */
/* !Description :  Evénement correspondant au passage à 0 de la variable      */
/*                 Moteur_tournant                                            */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_03211_001.03                                     */
/*                 VEMS_R_09_03211_002.03                                     */
/*                 VEMS_R_09_03211_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidInitLfbkMonitoring();                        */
/*  input uint8 INJTICOR_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_EveRTSt_InjTiCor                                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_EveRTSt_InjTiCor(void)
{
   if (INJTICOR_u8Inhib != 0x5A)
   {
      INJTICOR_vidInitLfbkMonitoring();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_SdlFast_InjTiCor                                       */
/* !Description :  Moniteur rapide de la fonction Inj.                        */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_03211_001.03                                     */
/*                 VEMS_R_09_03211_002.03                                     */
/*                 VEMS_R_09_03211_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidInitLfbkSwitchGslGas();                      */
/*  extf argret void INJTICOR_vidCtrlLfbkMonitoring();                        */
/*  input uint8 INJTICOR_u8Inhib;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_SdlFast_InjTiCor                                           */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_SdlFast_InjTiCor(void)
{
   if (INJTICOR_u8Inhib != 0x5A)
   {
      INJTICOR_vidInitLfbkSwitchGslGas();
      INJTICOR_vidCtrlLfbkMonitoring();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Inj_SdlMid_InjTiCor                                        */
/* !Description :  Moniteur moyen de la fonction Inj.                         */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_09_03211_001.03                                     */
/*                 VEMS_R_09_03211_002.03                                     */
/*                 VEMS_R_09_03211_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJTICOR_vidPerformClampTests();                         */
/*  extf argret void INJTICOR_vidAcvDiagEngineRunning();                      */
/*  extf argret void INJTICOR_vidSeqORngLfbkAfl();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void INJTICOR_vidSeqDftFuAfl();                               */
/*  extf argret void INJTICOR_vidSeqDftSenO2Afl();                            */
/*  extf argret void INJTICOR_vidSeqORngLfbkAfr();                            */
/*  extf argret void INJTICOR_vidSeqDftFuAfr();                               */
/*  extf argret void INJTICOR_vidSeqDftSenO2Afr();                            */
/*  input uint8 INJTICOR_u8Inhib;                                             */
/*  input boolean Inj_bDgoORngLfbk_Afl;                                       */
/*  input boolean Inj_bMonRunORngLfbk_Afl;                                    */
/*  input boolean Inj_bMonWaitORngLfbk_Afl;                                   */
/*  input boolean Inj_bDgoORngLfbkGas_Afl;                                    */
/*  input boolean Inj_bMonRunORngLfbkGas_Afl;                                 */
/*  input boolean Inj_bMonWaitORngLfbkGas_Afl;                                */
/*  input boolean Inj_bDgoDftFu_Afl;                                          */
/*  input boolean Inj_bMonRunDftFu_Afl;                                       */
/*  input boolean Inj_bMonWaitDftFu_Afl;                                      */
/*  input boolean Inj_bDgoDftFuGas_Afl;                                       */
/*  input boolean Inj_bMonRunDftFuGas_Afl;                                    */
/*  input boolean Inj_bMonWaitDftFuGas_Afl;                                   */
/*  input boolean Inj_bDgoDftSenO2_Afl;                                       */
/*  input boolean Inj_bMonRunDftSenO2_Afl;                                    */
/*  input boolean Inj_bMonWaitDftSenO2_Afl;                                   */
/*  input boolean Inj_bDgoDftSenO2Gas_Afl;                                    */
/*  input boolean Inj_bMonRunDftSenO2Gas_Afl;                                 */
/*  input boolean Inj_bMonWaitDftSenO2Gas_Afl;                                */
/*  input boolean Inj_bDgoORngLfbk_Afr;                                       */
/*  input boolean Inj_bMonRunORngLfbk_Afr;                                    */
/*  input boolean Inj_bMonWaitORngLfbk_Afr;                                   */
/*  input boolean Inj_bDgoORngLfbkGas_Afr;                                    */
/*  input boolean Inj_bMonRunORngLfbkGas_Afr;                                 */
/*  input boolean Inj_bMonWaitORngLfbkGas_Afr;                                */
/*  input boolean Inj_bDgoDftFu_Afr;                                          */
/*  input boolean Inj_bMonRunDftFu_Afr;                                       */
/*  input boolean Inj_bMonWaitDftFu_Afr;                                      */
/*  input boolean Inj_bDgoDftFuGas_Afr;                                       */
/*  input boolean Inj_bMonRunDftFuGas_Afr;                                    */
/*  input boolean Inj_bMonWaitDftFuGas_Afr;                                   */
/*  input boolean Inj_bDgoDftSenO2_Afr;                                       */
/*  input boolean Inj_bMonRunDftSenO2_Afr;                                    */
/*  input boolean Inj_bMonWaitDftSenO2_Afr;                                   */
/*  input boolean Inj_bDgoDftSenO2Gas_Afr;                                    */
/*  input boolean Inj_bMonRunDftSenO2Gas_Afr;                                 */
/*  input boolean Inj_bMonWaitDftSenO2Gas_Afr;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Inj_SdlMid_InjTiCor                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Inj_SdlMid_InjTiCor(void)
{
   if (INJTICOR_u8Inhib != 0x5A)
   {
      INJTICOR_vidPerformClampTests();
      INJTICOR_vidAcvDiagEngineRunning();

      INJTICOR_vidSeqORngLfbkAfl();
      GDGAR_vidGdu(GD_DFT_ORNGLFBK_AFL,
                   Inj_bDgoORngLfbk_Afl,
                   Inj_bMonRunORngLfbk_Afl,
                   Inj_bMonWaitORngLfbk_Afl);
      GDGAR_vidGdu(GD_DFT_ORNGLFBKGAS_AFL,
                   Inj_bDgoORngLfbkGas_Afl,
                   Inj_bMonRunORngLfbkGas_Afl,
                   Inj_bMonWaitORngLfbkGas_Afl);
      INJTICOR_vidSeqDftFuAfl();
      GDGAR_vidGdu(GD_DFT_DFTFU_AFL,
                   Inj_bDgoDftFu_Afl,
                   Inj_bMonRunDftFu_Afl,
                   Inj_bMonWaitDftFu_Afl);
      GDGAR_vidGdu(GD_DFT_DFTFUGAS_AFL,
                   Inj_bDgoDftFuGas_Afl,
                   Inj_bMonRunDftFuGas_Afl,
                   Inj_bMonWaitDftFuGas_Afl);
      INJTICOR_vidSeqDftSenO2Afl();
      GDGAR_vidGdu(GD_DFT_DFTSENO2_AFL,
                   Inj_bDgoDftSenO2_Afl,
                   Inj_bMonRunDftSenO2_Afl,
                   Inj_bMonWaitDftSenO2_Afl);
      GDGAR_vidGdu(GD_DFT_DFTSENO2GAS_AFL,
                   Inj_bDgoDftSenO2Gas_Afl,
                   Inj_bMonRunDftSenO2Gas_Afl,
                   Inj_bMonWaitDftSenO2Gas_Afl);
      INJTICOR_vidSeqORngLfbkAfr();
      GDGAR_vidGdu(GD_DFT_ORNGLFBK_AFR,
                   Inj_bDgoORngLfbk_Afr,
                   Inj_bMonRunORngLfbk_Afr,
                   Inj_bMonWaitORngLfbk_Afr);
      GDGAR_vidGdu(GD_DFT_ORNGLFBKGAS_AFR,
                   Inj_bDgoORngLfbkGas_Afr,
                   Inj_bMonRunORngLfbkGas_Afr,
                   Inj_bMonWaitORngLfbkGas_Afr);
      INJTICOR_vidSeqDftFuAfr();
      GDGAR_vidGdu(GD_DFT_DFTFU_AFR,
                   Inj_bDgoDftFu_Afr,
                   Inj_bMonRunDftFu_Afr,
                   Inj_bMonWaitDftFu_Afr);
      GDGAR_vidGdu(GD_DFT_DFTFUGAS_AFR,
                   Inj_bDgoDftFuGas_Afr,
                   Inj_bMonRunDftFuGas_Afr,
                   Inj_bMonWaitDftFuGas_Afr);
      INJTICOR_vidSeqDftSenO2Afr();
      GDGAR_vidGdu(GD_DFT_DFTSENO2_AFR,
                   Inj_bDgoDftSenO2_Afr,
                   Inj_bMonRunDftSenO2_Afr,
                   Inj_bMonWaitDftSenO2_Afr);
      GDGAR_vidGdu(GD_DFT_DFTSENO2GAS_AFR,
                   Inj_bDgoDftSenO2Gas_Afr,
                   Inj_bMonRunDftSenO2Gas_Afr,
                   Inj_bMonWaitDftSenO2Gas_Afr);
   }
}
/*------------------------------- end of file --------------------------------*/