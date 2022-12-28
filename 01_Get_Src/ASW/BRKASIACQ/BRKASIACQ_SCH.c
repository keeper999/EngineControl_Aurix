/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIACQ                                               */
/* !Description     : BRKASIACQ component.                                    */
/*                                                                            */
/* !Module          : BRKASIACQ                                               */
/* !Description     : ACQUISITION DE LA MESURE DU CAPTEUR DE DEPRESSION       */
/*                    MASTERVAC.                                              */
/*                                                                            */
/* !File            : BRKASIACQ_SCH.C                                         */
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
/*   1 / AirPres_EveRst_BrkAsiAcq                                             */
/*   2 / AirPres_SdlFast_BrkAsiAcq                                            */
/*   3 / AirPres_SdlSfty_BrkAsiAcq                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6525171 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BRKASIACQ/BRKASIACQ_SCH.C_v       $*/
/* $Revision::   1.6      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BRKASIACQ.h"
#include "BRKASIACQ_L.h"
#include "BRKASIACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_EveRst_BrkAsiAcq                                   */
/* !Description :  Fonction d'accroche à l'évènement reset                    */
/* !Number      :  SCH.1                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_05703_003.01                                     */
/*                 VEMS_E_11_05703_001.01                                     */
/*                 VEMS_E_11_05703_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIACQ_vidInitialization();                           */
/*  extf argret void BRKASIACQ_vidInitOutput();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : AirPres_EveRst_BrkAsiAcq                                       */
/* !Trigger  : AirPres_EveRst_BrkAsiAcq                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_EveRst_BrkAsiAcq(void)
{
   BRKASIACQ_vidInitialization();
   BRKASIACQ_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlFast_BrkAsiAcq                                  */
/* !Description :  Fonction d'accroche au moniteur rapide de la fonction      */
/*                 AirPres                                                    */
/* !Number      :  SCH.2                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_05703_001.01                                     */
/*                 VEMS_E_11_05703_002.01                                     */
/*                 VEMS_E_11_05703_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BRKASIACQ_vidCallMng();                                  */
/*  input uint8 BRKASIACQ_u8Inhib;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Runnable : AirPres_SdlFast_BrkAsiAcq                                      */
/* !Trigger  : AirPres_SdlFast_BrkAsiAcq                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlFast_BrkAsiAcq(void)
{
   if (BRKASIACQ_u8Inhib != 0x5A)
   {
      BRKASIACQ_vidCallMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AirPres_SdlSfty_BrkAsiAcq                                  */
/* !Description :  Evènement de calcul des fonctions safety de niveau 2       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_E_11_05703_001.01                                     */
/*                 VEMS_E_11_05703_002.01                                     */
/*                 VEMS_E_11_05703_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void BRKASIACQ_vidSftLvl2();                                  */
/*  input uint8 BRKASIACQ_u8Inhib;                                            */
/*  input boolean AirPres_bAcvBrkAsiAcq;                                      */
/*  input boolean Ext_bAcv_BrkAsiSftyLvl2;                                    */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : AirPres_SdlSfty_BrkAsiAcq                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AirPres_SdlSfty_BrkAsiAcq(void)
{
   boolean bLocalAirPres_bAcvBrkAsiAcq;
   boolean bLocalExt_bAcv_BrkAsiSftyLvl2;
   boolean bLocalDIAGCAN_bIntegratioElect;


   if (BRKASIACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(AirPres_bAcvBrkAsiAcq, bLocalAirPres_bAcvBrkAsiAcq);
      VEMS_vidGET(Ext_bAcv_BrkAsiSftyLvl2, bLocalExt_bAcv_BrkAsiSftyLvl2);
      VEMS_vidGET(DIAGCAN_bIntegratioElectronique,
                  bLocalDIAGCAN_bIntegratioElect);
      if (  (bLocalAirPres_bAcvBrkAsiAcq != 0)
         && (bLocalDIAGCAN_bIntegratioElect == 0)
         && (bLocalExt_bAcv_BrkAsiSftyLvl2 != 0))
      {
         BRKASIACQ_vidSftLvl2();
      }
   }
}
/*-------------------------------- End of file -------------------------------*/