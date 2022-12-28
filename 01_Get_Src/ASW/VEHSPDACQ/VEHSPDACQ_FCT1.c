/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VEHSPDACQ                                               */
/* !Description     : VEHSPDACQ Component                                     */
/*                                                                            */
/* !Module          : VEHSPDACQ                                               */
/* !Description     : ACQUISITION DE LA VITESSE VEHICULE FILAIRE              */
/*                                                                            */
/* !File            : VEHSPDACQ_FCT1.C                                        */
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
/*   1 / VEHSPDACQ_vidInitOutput                                              */
/*   2 / VEHSPDACQ_vidAcvEveVSTopCall                                         */
/*   3 / VEHSPDACQ_vidAcvSdlFastCall                                          */
/*   4 / VEHSPDACQ_vidInit                                                    */
/*   5 / VEHSPDACQ_vidInitDistance                                            */
/*   6 / VEHSPDACQ_vidChkBatt                                                 */
/*   7 / VEHSPDACQ_vidChkCondCalc                                             */
/*   8 / VEHSPDACQ_vidDataAcquisition                                         */
/*   9 / VEHSPDACQ_vidReadCtrAndDate                                          */
/*   10 / VEHSPDACQ_vidTiIntlComputation                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5455394 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VEHSPD/VEHSPDACQ/VEHSPDACQ_FCT1.$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   19 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   19 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VEHSPDACQ.h"
#include "VEHSPDACQ_L.h"
#include "VEHSPDACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidInitOutput                                    */
/* !Description :  Initialisation des variables internes de la spec.          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint32 VehSpd_PrevPlsDate;                                         */
/*  output uint32 VEHSPDACQ_u32FirstOrderFilterMem;                           */
/*  output uint8 Acceleration_filaireRaw;                                     */
/*  output boolean VehSpd_bInfoAvl;                                           */
/*  output uint16 VEHSPDACQ_u16CounterAntiRebond;                             */
/*  output boolean VEHSPDACQ_bFilterAnRebond;                                 */
/*  output uint32 VEHSPDACQ_u32AccelFiltredMem;                               */
/*  output uint8 VEHSPDACQ_u8InputFilter;                                     */
/*  output uint8 VEHSPDACQ_au8AccelfilaireRaw[8];                             */
/*  output uint8 Compteur_arret_vehicule;                                     */
/*  output boolean VEHSPDACQ_bTimeOut;                                        */
/*  output uint16 VEHSPDACQ_u16CtPlsPrev;                                     */
/*  output boolean VEHSPDACQ_bBattVoltOKPrev;                                 */
/*  output boolean VEHSPDACQ_bRisingHystOutput;                               */
/*  output boolean VEHSPDACQ_bFallingHystOutput;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidInitOutput(void)
{
   uint8 u8LocalIndex;


   /*03_SPDHALAcq*/
   VehSpd_PrevPlsDate = 0;

   /*02_SpdComputation*/
   VEHSPDACQ_u32FirstOrderFilterMem = 0;

   /*03_AccelComputation*/
   Acceleration_filaireRaw = 175;

   /*04_AccelMoyen*/
   VehSpd_bInfoAvl = 0;
   VEHSPDACQ_u16CounterAntiRebond = 0;
   VEHSPDACQ_bFilterAnRebond = 0;
   VEHSPDACQ_u32AccelFiltredMem = 0;
   VEHSPDACQ_u8InputFilter = 175;

   for(u8LocalIndex = 0; u8LocalIndex < VehSpd_noPlsCalcMean_SC; u8LocalIndex++)
   {
      VEHSPDACQ_au8AccelfilaireRaw[u8LocalIndex] = 175;
   }

   /*060_Detection_arret*/
   Compteur_arret_vehicule = 0;
   VEHSPDACQ_bTimeOut = 0;
   VEHSPDACQ_u16CtPlsPrev = 0;

   /*01_ReadCtrAndDate*/
   VEHSPDACQ_bBattVoltOKPrev = 0;

   /*Chk_Cond_Calc*/
   VEHSPDACQ_bRisingHystOutput = 0;
   VEHSPDACQ_bFallingHystOutput = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidAcvEveVSTopCall                               */
/* !Description :  L’évènement VehSpd_EveVSTop_SpdAcq n’est propagé que si    */
/*                 l’on n’est ni en ABS ni en ESP.                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHSPDACQ_vidChkBatt();                                  */
/*  extf argret void VEHSPDACQ_vidDataAcquisition();                          */
/*  extf argret void VEHSPDACQ_vidVehSpdComputation();                        */
/*  input boolean Abs_mux;                                                    */
/*  input boolean Esp_present;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidAcvEveVSTopCall(void)
{
   boolean bLocalAbs_mux;
   boolean bLocalEsp_present;


   VEMS_vidGET(Abs_mux, bLocalAbs_mux);
   VEMS_vidGET(Esp_present, bLocalEsp_present);
   if (  (bLocalAbs_mux == 0)
      && (bLocalEsp_present == 0))
   {
      VEHSPDACQ_vidChkBatt();
      VEHSPDACQ_vidDataAcquisition();
      VEHSPDACQ_vidVehSpdComputation();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidAcvSdlFastCall                                */
/* !Description :  L’évènement VehSpd_SdlFast_AcqVehSpdSen n’est propagé que  */
/*                 si l’on n’est ni en ABS ni en ESP.                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VEHSPDACQ_vidStopDetection();                            */
/*  extf argret void VEHSPDACQ_vidTransmission();                             */
/*  input boolean Abs_mux;                                                    */
/*  input boolean Esp_present;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidAcvSdlFastCall(void)
{
   boolean bLocalAbs_mux;
   boolean bLocalEsp_present;


   VEMS_vidGET(Abs_mux, bLocalAbs_mux);
   VEMS_vidGET(Esp_present, bLocalEsp_present);

   if (  (bLocalAbs_mux == 0)
      && (bLocalEsp_present == 0))
   {
      VEHSPDACQ_vidStopDetection();
      VEHSPDACQ_vidTransmission();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidInit                                          */
/* !Description :  Les différentes variables sont initialisées à 0.           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Acceleration_filaire;                                        */
/*  output uint16 Vitesse_vehicule_fil_precise;                               */
/*  output uint16 Ext_spdVehRaw;                                              */
/*  output uint16 Ext_VehSpdPlsTiIntl;                                        */
/*  output uint16 Vitesse_vehicule_fil_preciseAcq;                            */
/*  output uint16 Ext_spdVehRawAcq;                                           */
/*  output uint32 Cumul_PlsTiIntr;                                            */
/*  output uint16 Ext_spdVehRawAcqPrev;                                       */
/*  output uint8 Acceleration_filaireAcq;                                     */
/*  output uint8 BufVEHSPDACQ_index;                                          */
/*  output uint8 Ext_VehSpdBuf;                                               */
/*  output uint8 AccMoyen_index;                                              */
/*  output uint8 Ext_AccBuf;                                                  */
/*  output uint16 BufVEHSPDACQ[8];                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidInit(void)
{
   uint8 u8LocalIndex;


   VEMS_vidSET(Acceleration_filaire, 175);
   VEMS_vidSET(Vitesse_vehicule_fil_precise, 0);
   VEMS_vidSET(Ext_spdVehRaw, 0);
   Ext_VehSpdPlsTiIntl = 0;
   Vitesse_vehicule_fil_preciseAcq = 0;
   Ext_spdVehRawAcq = 0;
   Cumul_PlsTiIntr = 0;
   Ext_spdVehRawAcqPrev = 0;
   Acceleration_filaireAcq = 175;
   BufVEHSPDACQ_index = 0;
   Ext_VehSpdBuf = 0;
   AccMoyen_index = 0;
   Ext_AccBuf= 0;

   for(u8LocalIndex = 0; u8LocalIndex < VehSpd_noPlsCalcMean_SC; u8LocalIndex++)
   {
      BufVEHSPDACQ[u8LocalIndex] = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidInitDistance                                  */
/* !Description :  Initialisation de la distance parcourue. Celle si n’est    */
/*                 faite qu’au reset, et pas lors de la détection d’un arrêt  */
/*                 véhicule comme c’est le cas pour les autres variables.     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Distance_parcourue_fil;                                     */
/*  output uint32 Distance_fil_precise;                                       */
/*  output boolean Vehicle_stopped;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidInitDistance(void)
{
   VEMS_vidSET(Distance_parcourue_fil, 0);
   Distance_fil_precise = 0;
   Vehicle_stopped = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidChkBatt                                       */
/* !Description :  La calibration VehSpd_bEnaChkBattVolt_C, lorsqu’elle vaut  */
/*                 1, permet d’activer la vérification des conditions         */
/*                 d’alimentation de la batterie. Lorsqu’elle vaut 0, la      */
/*                 vérification n’est pas faite et le booléen                 */
/*                 VehSpd_bBattVoltOK est mis à 1.                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidChkCondCalc();                              */
/*  input boolean VehSpd_bEnaChkBattVolt_C;                                   */
/*  output boolean VehSpd_bBattVoltOK;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidChkBatt(void)
{
   if (VehSpd_bEnaChkBattVolt_C != 0)
   {
      VEHSPDACQ_vidChkCondCalc();
   }
   else
   {
      VehSpd_bBattVoltOK = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidChkCondCalc                                   */
/* !Description :  Ici, on vérifie que la tension d’alimentation du capteur se*/
/*                 situe entre un seuil bas et un seuil haut que l’on peut    */
/*                 régler par calibration. Le résultat est stocké dans un     */
/*                 booléen.                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 VehSpd_uBattVoltHiThd_C;                                     */
/*  input uint16 VehSpd_uBattVoltHysThd_C;                                    */
/*  input uint16 VehSpd_uBattVoltLoThd_C;                                     */
/*  input boolean VEHSPDACQ_bFallingHystOutput;                               */
/*  input boolean VEHSPDACQ_bRisingHystOutput;                                */
/*  output boolean VehSpd_bBattVoltOK;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidChkCondCalc(void)
{
   uint16 u16LocalExt_uBattMes;
   uint16 u16LocalThreshold_FALLING_1;
   uint16 u16LocalThreshold_RISING_2;
   sint16 s16LocalExt_uBattMes;
   uint32 u32LocalThreshold_RISING_2;
   sint32 s32LocalThreshold_FALLING_1;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);

   u16LocalExt_uBattMes = (uint16)MATHSRV_udtMAX(s16LocalExt_uBattMes, 0);

   s32LocalThreshold_FALLING_1 = (sint32)( VehSpd_uBattVoltHiThd_C
                                         - VehSpd_uBattVoltHysThd_C);

   u32LocalThreshold_RISING_2 = (uint32)( VehSpd_uBattVoltLoThd_C
                                        + VehSpd_uBattVoltHysThd_C);

   u16LocalThreshold_FALLING_1 =
      (uint16)MATHSRV_udtMAX(s32LocalThreshold_FALLING_1, 0);

   u16LocalThreshold_RISING_2 =
      (uint16)MATHSRV_udtMIN(u32LocalThreshold_RISING_2, 65535);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_uBattMes,
                                u16LocalThreshold_FALLING_1,
                                VehSpd_uBattVoltHiThd_C,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VEHSPDACQ_bFallingHystOutput);

   MATHSRV_vidSchmittTriggerU16(u16LocalExt_uBattMes,
                                VehSpd_uBattVoltLoThd_C,
                                u16LocalThreshold_RISING_2,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &VEHSPDACQ_bRisingHystOutput);

   if (  (VEHSPDACQ_bRisingHystOutput != 0)
      && (VEHSPDACQ_bFallingHystOutput != 0))
   {
      VehSpd_bBattVoltOK = 1;
   }
   else
   {
      VehSpd_bBattVoltOK = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidDataAcquisition                               */
/* !Description :  Le premier bloc permet de faire l’acquisition des          */
/*                 informations relatives aux impulsions qui sont transmises  */
/*                 par le LDB. Le second permet de calculer l’intervalle de   */
/*                 temps entre les deux dernières impulsions.                 */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidReadCtrAndDate();                           */
/*  extf argret void VEHSPDACQ_vidTiIntlComputation();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidDataAcquisition(void)
{
   VEHSPDACQ_vidReadCtrAndDate();
   VEHSPDACQ_vidTiIntlComputation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidReadCtrAndDate                                */
/* !Description :  Lorsque les conditions d’alimentation du capteur sont      */
/*                 bonnes, la date et le compteur d’impulsion sont transmis   */
/*                 par le Logiciel de Base vers l’applicatif.                 */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidSPDHALEna();                                */
/*  extf argret void VEHSPDACQ_vidSPDHALAcq();                                */
/*  extf argret void VEHSPDACQ_vidSPDHALDis();                                */
/*  input boolean VehSpd_bBattVoltOK;                                         */
/*  input boolean VEHSPDACQ_bBattVoltOKPrev;                                  */
/*  output boolean VEHSPDACQ_bBattVoltOKPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidReadCtrAndDate(void)
{
   if (VehSpd_bBattVoltOK != 0)
   {
      if (VEHSPDACQ_bBattVoltOKPrev == 0)
      {
         VEHSPDACQ_vidSPDHALEna();
      }
      VEHSPDACQ_vidSPDHALAcq();
   }
   else
   {
      if (VEHSPDACQ_bBattVoltOKPrev != 0)
      {
         VEHSPDACQ_vidSPDHALDis();
      }
   }

   VEHSPDACQ_bBattVoltOKPrev = VehSpd_bBattVoltOK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VEHSPDACQ_vidTiIntlComputation                             */
/* !Description :  Si l’on en est à la première impulsion reçue, on ne peut   */
/*                 pas réaliser de calcul d’intervalle de temps ; on renvoie  */
/*                 donc 0.                                                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VEHSPDACQ_vidDateOvfMng();                               */
/*  input uint32 VehSpd_PlsDate;                                              */
/*  input uint32 VehSpd_PrevPlsDate;                                          */
/*  input uint16 Ext_VehSpdOvfPlsTiIntl;                                      */
/*  output uint16 Ext_VehSpdPlsTiIntl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VEHSPDACQ_vidTiIntlComputation(void)
{
   uint32 u32LocalVehSpdPlsTiIntl;


   VEHSPDACQ_vidDateOvfMng();

   if (VehSpd_PlsDate >= VehSpd_PrevPlsDate)
   {
      u32LocalVehSpdPlsTiIntl = (VehSpd_PlsDate - VehSpd_PrevPlsDate) / 100;

      Ext_VehSpdPlsTiIntl =
         (uint16)MATHSRV_udtMIN(u32LocalVehSpdPlsTiIntl, 65535);
   }
   else
   {
      Ext_VehSpdPlsTiIntl = Ext_VehSpdOvfPlsTiIntl;
   }
}

/*--------------------------------end of file---------------------------------*/