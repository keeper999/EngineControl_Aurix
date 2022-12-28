/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQADC                                                  */
/* !Description     : ACQADC component.                                       */
/*                                                                            */
/* !Module          : ACQADC                                                  */
/* !Description     : Spécification des acquisitions analogiques (AdcHal)     */
/*                                                                            */
/* !File            : ACQADC_FCT1.C                                           */
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
/*   1 / ACQADC_vidInit                                                       */
/*   2 / ACQADC_vidAcqAdcAlim                                                 */
/*   3 / ACQADC_vidAcqAdcBatt                                                 */
/*   4 / ACQADC_vidInMnfPresAcq                                               */
/*   5 / ACQADC_vidAirExtPresAcq                                              */
/*   6 / ACQADC_vidBrkAsiAcq                                                  */
/*   7 / ACQADC_vidRelBrkAsiAcq                                               */
/*   8 / ACQADC_vidAcqAdcEngSt                                                */
/*   9 / ACQADC_vidHeatSenO2Ds                                                */
/*   10 / ACQADC_vidHeatSenO2Us                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6669203 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQADC/ACQADC_FCT1.C_v            $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   31 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   31 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.H"
#include "ACQADC.H"
#include "ACQADC_L.H"
#include "ACQADC_IM.H"
#include "ADCHAL.h"
#include "ACQADC_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidInit                                             */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Tension_alimentation_capteur_1;                             */
/*  output uint16 Tension_alimentation_capteur_2;                             */
/*  output uint16 Tension_alimentation_capteur_3;                             */
/*  output uint16 Tension_alimentation_capteur_4;                             */
/*  output uint16 Acquisition_tension_batterie;                               */
/*  output uint16 Acquisition_press_coll;                                     */
/*  output uint16 Acquisition_press_airext;                                   */
/*  output uint16 Acquisition_press_mast_abs;                                 */
/*  output uint16 Acquisition_press_mast_rel;                                 */
/*  output uint16 Courant_chauf_seno2ds;                                      */
/*  output uint16 Tension_commande_chauf_seno2ds;                             */
/*  output uint16 Courant_chauf_seno2us;                                      */
/*  output uint16 Tension_commande_chauf_seno2us;                             */
/*  output uint16 Acq_tension_sonde_o2_am;                                    */
/*  output uint16 Acq_tension_sonde_o2_av;                                    */
/*  output uint16 Acquisition_tension_etat_bicd;                              */
/*  output uint16 Acqui_tension_contacteur_pt_dur;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidInit(void)
{
   /*F00_Init*/
   VEMS_vidSET(Tension_alimentation_capteur_1, 0);
   VEMS_vidSET(Tension_alimentation_capteur_2, 0);
   VEMS_vidSET(Tension_alimentation_capteur_3, 0);
   VEMS_vidSET(Tension_alimentation_capteur_4, 0);
   VEMS_vidSET(Acquisition_tension_batterie, 0);
   VEMS_vidSET(Acquisition_press_coll, 0);
   VEMS_vidSET(Acquisition_press_airext, 0);
   VEMS_vidSET(Acquisition_press_mast_abs, 0);
   VEMS_vidSET(Acquisition_press_mast_rel, 0);
   VEMS_vidSET(Courant_chauf_seno2ds, 0);
   VEMS_vidSET(Tension_commande_chauf_seno2ds, 0);
   VEMS_vidSET(Courant_chauf_seno2us, 0);
   VEMS_vidSET(Tension_commande_chauf_seno2us, 0);
   VEMS_vidSET(Acq_tension_sonde_o2_am, 0);
   VEMS_vidSET(Acq_tension_sonde_o2_av, 0);
   VEMS_vidSET(Acquisition_tension_etat_bicd, 0);
   VEMS_vidSET(Acqui_tension_contacteur_pt_dur, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcAlim                                       */
/* !Description :  acquisition de la tesion d'alimentaion des capteurs 1,2,3  */
/*                 et 4                                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Tension_alimentation_capteur_1;                             */
/*  output uint16 Tension_alimentation_capteur_2;                             */
/*  output uint16 Tension_alimentation_capteur_3;                             */
/*  output uint16 Tension_alimentation_capteur_4;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcAlim(void)
{
   /*F01_AcqAdcAlim*/
   uint16 u16LocalTension_alim_capteur1;
   uint16 u16LocalTension_alim_capteur2;
   uint16 u16LocalTension_alim_capteur3;
   uint16 u16LocalTension_alim_capteur4;


   u16LocalTension_alim_capteur1 = ADCHAL_udtRead(CH_ADC_PWRS_V_1);
   VEMS_vidSET(Tension_alimentation_capteur_1, u16LocalTension_alim_capteur1);

   u16LocalTension_alim_capteur2 = ADCHAL_udtRead(CH_ADC_PWRS_V_2);
   VEMS_vidSET(Tension_alimentation_capteur_2, u16LocalTension_alim_capteur2);

   u16LocalTension_alim_capteur3 = ADCHAL_udtRead(CH_ADC_PWRS_V_3);
   VEMS_vidSET(Tension_alimentation_capteur_3, u16LocalTension_alim_capteur3);

   u16LocalTension_alim_capteur4 = ADCHAL_udtRead(CH_ADC_PWRS_V_4);
   VEMS_vidSET(Tension_alimentation_capteur_4, u16LocalTension_alim_capteur4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcBatt                                       */
/* !Description :  Acquisition de la tension batterie                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_tension_batterie;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcBatt(void)
{
   /*F02_AcqAdcBatt*/
   uint16 u16LocalAcq_tension_batterie;


   u16LocalAcq_tension_batterie = ADCHAL_udtRead(CH_ADC_BAT_RLY_V);
   VEMS_vidSET(Acquisition_tension_batterie, u16LocalAcq_tension_batterie);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidInMnfPresAcq                                     */
/* !Description :  Acquisition de la pression de collecteur                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_press_coll;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidInMnfPresAcq(void)
{
   /*F01_InMnfPresAcq*/
   uint16 u16LocalAcq_press_coll;


   u16LocalAcq_press_coll = ADCHAL_udtRead(CH_ADC_MAP_V);
   VEMS_vidSET(Acquisition_press_coll, u16LocalAcq_press_coll);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAirExtPresAcq                                    */
/* !Description :  Acquisition de la pression atmosphérique                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_press_airext;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAirExtPresAcq(void)
{
   /*F02_AirExtPresAcq*/
   uint16 u16LocalAcq_press_airext;


   u16LocalAcq_press_airext = ADCHAL_udtRead(ADCHAL_INT_ATMO_PRS_P0);
   VEMS_vidSET(Acquisition_press_airext, u16LocalAcq_press_airext);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidBrkAsiAcq                                        */
/* !Description :  Acquisition de la tension aux bornes du capteur Pression   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_press_mast_abs;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidBrkAsiAcq(void)
{
   /*F03_BrkAsiAcq*/
   uint16 u16LocalAcq_press_mast_abs;


   u16LocalAcq_press_mast_abs = ADCHAL_udtRead(CH_ADC_MSTRVAC_PRS);
   VEMS_vidSET(Acquisition_press_mast_abs, u16LocalAcq_press_mast_abs);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidRelBrkAsiAcq                                     */
/* !Description :  Acquisition de la tension mesurée aux bornes du capteur de */
/*                 pression mastervac relative                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_press_mast_rel;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidRelBrkAsiAcq(void)
{
   /*F04_RelBrkAsiAcq*/
   uint16 u16LocalAcq_press_mast_rel;


   u16LocalAcq_press_mast_rel = ADCHAL_udtRead(CH_ADC_MSTRVAC_PRS);
   VEMS_vidSET(Acquisition_press_mast_rel, u16LocalAcq_press_mast_rel);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcEngSt                                      */
/* !Description :  Acquisition de l'information état BICD                     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_tension_etat_bicd;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcEngSt(void)
{
   /*F03_AcqAdcEngSt*/
   uint16 u16LocalAcq_tension_etat_bicd;


   u16LocalAcq_tension_etat_bicd = ADCHAL_udtRead(CH_ADC_BICD);
   VEMS_vidSET(Acquisition_tension_etat_bicd, u16LocalAcq_tension_etat_bicd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidHeatSenO2Ds                                      */
/* !Description :  Demande d'activation du chauffage de la sonde aval         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Courant_chauf_seno2ds;                                      */
/*  output uint16 Tension_commande_chauf_seno2ds;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidHeatSenO2Ds(void)
{
   /*HeatSenO2Ds*/
   uint16 u16LocalCour_chauf_seno2ds;
   uint16 u16LocalTens_chauf_seno2ds;


   u16LocalCour_chauf_seno2ds = ADCHAL_udtRead(CH_ADC_HT_DW_O2_CUR);
   VEMS_vidSET(Courant_chauf_seno2ds, u16LocalCour_chauf_seno2ds);

   u16LocalTens_chauf_seno2ds = ADCHAL_udtRead(CH_ADC_HT_DW_O2_VOLT);
   VEMS_vidSET(Tension_commande_chauf_seno2ds, u16LocalTens_chauf_seno2ds);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidHeatSenO2Us                                      */
/* !Description :  Demande d'activation du chauffage de la sonde amont        */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Courant_chauf_seno2us;                                      */
/*  output uint16 Tension_commande_chauf_seno2us;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidHeatSenO2Us(void)
{
   /*HeatSenO2Us*/
   uint16 u16LocalCour_chauf_seno2us;
   uint16 u16LocalTens_chauf_seno2us;


   u16LocalCour_chauf_seno2us = ADCHAL_udtRead(CH_ADC_HT_UP_O2_CUR);
   VEMS_vidSET(Courant_chauf_seno2us, u16LocalCour_chauf_seno2us);

   u16LocalTens_chauf_seno2us = ADCHAL_udtRead(CH_ADC_HT_UP_O2_VOLT);
   VEMS_vidSET(Tension_commande_chauf_seno2us, u16LocalTens_chauf_seno2us);
}
/*------------------------------- end of file --------------------------------*/