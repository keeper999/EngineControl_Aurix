/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PWRSEN_ACQ                                              */
/* !Description     : PWRSEN_ACQ Component                                    */
/*                                                                            */
/* !Module          : PWRSEN_ACQ                                              */
/* !Description     : ACQUISITION TENSION ALIMENTATION CAPTEURS               */
/*                                                                            */
/* !File            : PWRSEN_ACQ_SCH.C                                        */
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
/*   1 / Pwr_EveRst_Acq                                                       */
/*   2 / Pwr_SdlFast_Acq                                                      */
/*   3 / Pwr_SdlMid_Acq                                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_6538484 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/PWRSEN_ACQ/PWRSEN_ACQ_SCH.C_v     $*/
/* $Revision::   1.5      $$Author::   fsanchez2      $$Date::   27 May 2014 $*/
/* $Author::   fsanchez2                              $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "PWRSEN_ACQ.h"
#include "PWRSEN_ACQ_L.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_EveRst_Acq                                             */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas1();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes1();                            */
/*  extf argret void PWRSEN_ACQ_vidInitVEndValMeas1();                        */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas2();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes2();                            */
/*  extf argret void PWRSEN_ACQ_vidInitVEndValMeas2();                        */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas3();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes3();                            */
/*  extf argret void PWRSEN_ACQ_vidInitVEndValMeas3();                        */
/*  extf argret void PWRSEN_ACQ_vidAcqDiagVRawMeas4();                        */
/*  extf argret void PWRSEN_ACQ_vidDiagVRawMes4();                            */
/*  extf argret void PWRSEN_ACQ_vidInitVEndValMeas4();                        */
/*  extf argret void PWRSEN_ACQ_vidAlimAps();                                 */
/*  extf argret void PWRSEN_ACQ_vidAlimAc();                                  */
/*  extf argret void PWRSEN_ACQ_vidAlimAirPts();                              */
/*  extf argret void PWRSEN_ACQ_vidAlimPmast();                               */
/*  extf argret void PWRSEN_ACQ_vidBoostPresCf();                             */
/*  extf argret void PWRSEN_ACQ_vidPfuCf();                                   */
/*  extf argret void PWRSEN_ACQ_vidTrbActCf();                                */
/*  extf argret void PWRSEN_ACQ_vidptOilCf();                                 */
/*  extf argret void PWRSEN_ACQ_vidInCmCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidExCmCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidCluPosnCf();                               */
/*  extf argret void PWRSEN_ACQ_vidNeutCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidnEngCf();                                  */
/*  extf argret void PWRSEN_ACQ_vidAccP2Cf();                                 */
/*  extf argret void PWRSEN_ACQ_vidAlimSwitchSdlFast();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_EveRst_Acq                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_EveRst_Acq(void)
{
   /* Pwr_Alim1_Acq */
   PWRSEN_ACQ_vidAcqDiagVRawMeas1();
   PWRSEN_ACQ_vidDiagVRawMes1();
   PWRSEN_ACQ_vidInitVEndValMeas1();
   /* Pwr_Alim2_Acq */
   PWRSEN_ACQ_vidAcqDiagVRawMeas2();
   PWRSEN_ACQ_vidDiagVRawMes2();
   PWRSEN_ACQ_vidInitVEndValMeas2();
   /* Pwr_Alim3_Acq */
   PWRSEN_ACQ_vidAcqDiagVRawMeas3();
   PWRSEN_ACQ_vidDiagVRawMes3();
   PWRSEN_ACQ_vidInitVEndValMeas3();
   /* Pwr_Alim4_Acq */
   PWRSEN_ACQ_vidAcqDiagVRawMeas4();
   PWRSEN_ACQ_vidDiagVRawMes4();
   PWRSEN_ACQ_vidInitVEndValMeas4();
   /* Switch_SdlMid */
   PWRSEN_ACQ_vidAlimAps();
   PWRSEN_ACQ_vidAlimAc();
   PWRSEN_ACQ_vidAlimAirPts();
   PWRSEN_ACQ_vidAlimPmast();
   PWRSEN_ACQ_vidBoostPresCf();
   PWRSEN_ACQ_vidPfuCf();
   PWRSEN_ACQ_vidTrbActCf();
   PWRSEN_ACQ_vidptOilCf();
   PWRSEN_ACQ_vidInCmCf();
   PWRSEN_ACQ_vidExCmCf();
   PWRSEN_ACQ_vidCluPosnCf();
   PWRSEN_ACQ_vidNeutCf();
   PWRSEN_ACQ_vidnEngCf();
   PWRSEN_ACQ_vidAccP2Cf();
   /* Switch_SdlFast */
   PWRSEN_ACQ_vidAlimSwitchSdlFast();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlFast_Acq                                            */
/* !Description :  Moniteur rapide de la fonction ALIM capteurs               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAlimSchSdlFastAcq();                       */
/*  input uint8 PWRSEN_ACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlFast_Acq                                                */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlFast_Acq(void)
{
   if (PWRSEN_ACQ_u8Inhib != 0x5A)
   {
      PWRSEN_ACQ_vidAlimSchSdlFastAcq();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Pwr_SdlMid_Acq                                             */
/* !Description :  Moniteur d'acquistion de la tension ALIM                   */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PWRSEN_ACQ_vidAlimSchSdlMidAcq();                        */
/*  input uint8 PWRSEN_ACQ_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Pwr_SdlMid_Acq                                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Pwr_SdlMid_Acq(void)
{
   if (PWRSEN_ACQ_u8Inhib != 0x5A)
   {
      PWRSEN_ACQ_vidAlimSchSdlMidAcq();
   }
}

/*-------------------------------- end of file -------------------------------*/