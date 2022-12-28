/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WKU                                                     */
/* !Description     : WKU component.                                          */
/*                                                                            */
/* !Module          : WKU                                                     */
/* !Description     : GENERATION OF INFORMATION RELATED TO RCD .              */
/*                                                                            */
/* !File            : WKU_FCT3.C                                              */
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
/*   1 / WKU_vidElectronicIntegration                                         */
/*   2 / WKU_vidInterface                                                     */
/*   3 / WKU_vidCaseRcdSignalEqual1                                           */
/*   4 / WKU_vidCaseRcdSignalEqual0                                           */
/*   5 / WKU_vidAPCFirstKeyOn                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6765172 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECUST/WKU/WKU_FCT3.C_v            $*/
/* $Revision::   1.14     $$Author::   achebino       $$Date::   16 Jun 2014 $*/
/* $Author::   achebino                               $$Date::   16 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "WKU.h"
#include "WKU_L.h"
#include "WKU_IM.h"
#include "MATHSRV.H"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidElectronicIntegration                               */
/* !Description :  Intégration Electronique                                   */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void WKU_vidCaseRcdSignalEqual1();                            */
/*  extf argret void WKU_vidCaseRcdSignalEqual0();                            */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Rcd_signal;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidElectronicIntegration(void)
{
   boolean bLocalIntegratioElectronique;
   boolean bLocalRcd_signal;


   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalIntegratioElectronique);
   if (  (Rcd_mode_active != 0)
      && (bLocalIntegratioElectronique != 0))
   {
      VEMS_vidGET(Rcd_signal, bLocalRcd_signal);
      if (bLocalRcd_signal != 0)
      {
         WKU_vidCaseRcdSignalEqual1();
      }
      else
      {
         WKU_vidCaseRcdSignalEqual0();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidInterface                                           */
/* !Description :  Affectation de valeurs aux sorties selon la valeur du      */
/*                 boolean indiquant l'integration du composant RCD.          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input boolean UCE_bWkuMain;                                               */
/*  input uint16 Ext_bfSlavePtlWkuSt;                                         */
/*  input uint8 UCE_bfSlavePtlWkuSt;                                          */
/*  input boolean EcuSt_bImmoUnlockReq;                                       */
/*  input boolean EcuSt_bOilMesEng;                                           */
/*  input boolean EcuSt_bEngFanReq;                                           */
/*  input boolean EcuSt_bEngPrep;                                             */
/*  input boolean EcuSt_bWkuMain;                                             */
/*  output boolean ECU_bImmoUnlockWkuSt;                                      */
/*  output boolean ECU_bOilWkuSt;                                             */
/*  output boolean ECU_bStopEngCoWkuSt;                                       */
/*  output boolean ECU_bPrepIgEngWkuSt;                                       */
/*  output boolean ECU_bWkuPtEngStrt;                                         */
/*  output boolean ECU_bUcapWkuSt;                                            */
/*  output boolean ECU_bWkuChDchaUcap;                                        */
/*  output boolean Rcd_anticipation_adc;                                      */
/*  output boolean Rcd_mes_huile_moteur;                                      */
/*  output boolean Rcd_post_ventil_mot;                                       */
/*  output boolean Rcd_preparation_moteur;                                    */
/*  output boolean ECU_bWkuMain;                                              */
/*  output boolean EcuSt_bImmoUnlockReq;                                      */
/*  output boolean EcuSt_bOilMesEng;                                          */
/*  output boolean EcuSt_bEngFanReq;                                          */
/*  output boolean EcuSt_bEngPrep;                                            */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output uint16 Ext_bfSlavePtlWkuSt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidInterface(void)
{
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;
   boolean bLocalECU_bImmoUnlockWkuSt;
   boolean bLocalECU_bOilWkuSt;
   boolean bLocalECU_bStopEngCoWkuSt;
   boolean bLocalECU_bPrepIgEngWkuSt;
   boolean bLocalUCE_bWkuMain;
   boolean bLocalECU_bUcapWkuSt;
   uint8   u8LocalUCE_bfSlavePtlWkuSt;
   uint16  u16LocalExt_bfSlavePtlWkuSt;


   VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);
   VEMS_vidGET(UCE_bWkuMain, bLocalUCE_bWkuMain);
   VEMS_vidGET(Ext_bfSlavePtlWkuSt, u16LocalExt_bfSlavePtlWkuSt);
   VEMS_vidGET(UCE_bfSlavePtlWkuSt, u8LocalUCE_bfSlavePtlWkuSt);

   bLocalECU_bImmoUnlockWkuSt = (boolean)(u8LocalUCE_bfSlavePtlWkuSt & 0x01);
   bLocalECU_bOilWkuSt = (boolean)((u8LocalUCE_bfSlavePtlWkuSt & 0x04) >> 2);
   bLocalECU_bStopEngCoWkuSt =
      (boolean)((u8LocalUCE_bfSlavePtlWkuSt & 0x08) >> 3);
   bLocalECU_bPrepIgEngWkuSt =
      (boolean)((u8LocalUCE_bfSlavePtlWkuSt & 0x02) >> 1);
   bLocalECU_bUcapWkuSt = (boolean)((u8LocalUCE_bfSlavePtlWkuSt & 0x10) >> 4);

   VEMS_vidSET(ECU_bImmoUnlockWkuSt, bLocalECU_bImmoUnlockWkuSt);
   VEMS_vidSET(ECU_bOilWkuSt, bLocalECU_bOilWkuSt);
   VEMS_vidSET(ECU_bStopEngCoWkuSt, bLocalECU_bStopEngCoWkuSt);
   VEMS_vidSET(ECU_bPrepIgEngWkuSt, bLocalECU_bPrepIgEngWkuSt);
   VEMS_vidSET(ECU_bWkuPtEngStrt, bLocalECU_bPrepIgEngWkuSt);
   VEMS_vidSET(ECU_bUcapWkuSt, bLocalECU_bUcapWkuSt);
   VEMS_vidSET(ECU_bWkuChDchaUcap, bLocalECU_bUcapWkuSt);

   if (bLocalEcuSt_bAcvRcdMod_EcuMng != 0)
   {
      VEMS_vidSET(Rcd_anticipation_adc, bLocalECU_bImmoUnlockWkuSt);
      VEMS_vidSET(Rcd_mes_huile_moteur, bLocalECU_bOilWkuSt);
      VEMS_vidSET(Rcd_post_ventil_mot, bLocalECU_bStopEngCoWkuSt);
      VEMS_vidSET(Rcd_preparation_moteur, bLocalECU_bPrepIgEngWkuSt);
      VEMS_vidSET(ECU_bWkuMain, bLocalUCE_bWkuMain);

      if (bLocalECU_bUcapWkuSt != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x04);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xFFFB);
      }
      if (bLocalECU_bImmoUnlockWkuSt != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x40);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xFFBF);
      }
      if (bLocalECU_bPrepIgEngWkuSt != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x80);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xFF7F);
      }
      if (bLocalECU_bOilWkuSt != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x4000);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xBFFF);
      }
      if (bLocalECU_bStopEngCoWkuSt != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x8000);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0x7FFF);
      }
   }
   else
   {
      VEMS_vidSET(Rcd_anticipation_adc, EcuSt_bImmoUnlockReq);
      VEMS_vidSET(Rcd_mes_huile_moteur, EcuSt_bOilMesEng);
      VEMS_vidSET(Rcd_post_ventil_mot, EcuSt_bEngFanReq);
      VEMS_vidSET(Rcd_preparation_moteur, EcuSt_bEngPrep);
      VEMS_vidSET(ECU_bWkuMain, EcuSt_bWkuMain);

      if (EcuSt_bImmoUnlockReq != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x40);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xFFBF);
      }
      if (EcuSt_bEngPrep != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x80);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xFF7F);
      }
      if (EcuSt_bOilMesEng != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x4000);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0xBFFF);
      }
      if (EcuSt_bEngFanReq != 0)
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt | 0x8000);
      }
      else
      {
         u16LocalExt_bfSlavePtlWkuSt =
            (uint16)(u16LocalExt_bfSlavePtlWkuSt & 0x7FFF);
      }

   }
   VEMS_vidSET(Ext_bfSlavePtlWkuSt, u16LocalExt_bfSlavePtlWkuSt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidCaseRcdSignalEqual1                                 */
/* !Description :  the value of Boolean Clef_de_contact_ss_coh and counter    */
/*                 Rcd_tempo_boot_count when RCD signal is equal to 1.        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Rcd_tempo_boot_delay;                                        */
/*  output boolean Clef_de_contact_ss_coh;                                    */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidCaseRcdSignalEqual1(void)
{
/*  This name is imposed in the Spec*/
   uint16  u16LocalRcd_tempo_boot_count;


   Clef_de_contact_ss_coh = 1;
   u16LocalRcd_tempo_boot_count =
      (uint16)MATHSRV_udtMIN(Rcd_tempo_boot_delay, 60000);
   VEMS_vidSET(Rcd_tempo_boot_count, u16LocalRcd_tempo_boot_count);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidCaseRcdSignalEqual0                                 */
/* !Description :  the value of Boolean Clef_de_contact_ss_coh and counter    */
/*                 Rcd_tempo_boot_count whenRCD signal is equal to 0.         */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ActivateTask(argin uint8 Taskid);                        */
/*  output boolean Clef_de_contact_ss_coh;                                    */
/*  output boolean Clef_de_contact;                                           */
/*  output boolean EcuSt_bWkuMain;                                            */
/*  output uint16 Rcd_tempo_boot_count;                                       */
/*  output boolean Ext_bKeyOn;                                                */
/*  output boolean Ext_bKeyOff;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidCaseRcdSignalEqual0(void)
{
   Clef_de_contact_ss_coh = 0;
   VEMS_vidSET(Clef_de_contact, 0);
   EcuSt_bWkuMain = 0;
   VEMS_vidSET(Rcd_tempo_boot_count, 0);
   VEMS_vidSET(Ext_bKeyOn, 0);
   VEMS_vidSET(Ext_bKeyOff, 1);
   /* Evenement EcuSt_EveKOf_Wku*/
   ActivateTask(OSTSK_S_IGK_OFF);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WKU_vidAPCFirstKeyOn                                       */
/* !Description :  Generation of a Key ON at the end of initialization in the */
/*                 case of +APC application.                                  */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void EcuSt_EveFrstKOn_Wku();                                  */
/*  input boolean Rcd_mode_active;                                            */
/*  input boolean Rcd_bAcv_KeyOn_event_on_reset_C;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WKU_vidAPCFirstKeyOn(void)
{
   if (  (Rcd_mode_active == 0)
      && (Rcd_bAcv_KeyOn_event_on_reset_C != 0))
   {
      EcuSt_EveFrstKOn_Wku();
   }
}

/*--------------------------------- end of file ------------------------------*/