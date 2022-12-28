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
/* !File            : ACQADC_FCT2.C                                           */
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
/*   1 / ACQADC_vidAcqSenO2Us                                                 */
/*   2 / ACQADC_vidAcqSenO2Ds                                                 */
/*   3 / ACQADC_vidAcqAdcPresAC                                               */
/*   4 / ACQADC_vidAcqAdcCoT                                                  */
/*   5 / ACQADC_vidAcqAdcAirT                                                 */
/*   6 / ACQADC_vidAcqAdcAccP1                                                */
/*   7 / ACQADC_vidAcqAdcAccP2                                                */
/*   8 / ACQADC_vidAcqAdcThr                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6669203 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQADC/ACQADC_FCT2.C_v            $*/
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
/* !Function    :  ACQADC_vidAcqSenO2Us                                       */
/* !Description :  Acquisition A/N de la tension  de la sonde amont           */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acq_tension_sonde_o2_am;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqSenO2Us(void)
{
   /*F01_AcqSenO2Us*/
   uint16 u16LocalAcq_tension_sonde_o2_am;


   u16LocalAcq_tension_sonde_o2_am = ADCHAL_udtRead(CH_ADC_LBUP_V);
   VEMS_vidSET(Acq_tension_sonde_o2_am, u16LocalAcq_tension_sonde_o2_am);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqSenO2Ds                                       */
/* !Description :  Acquisition A/N de la tension  de la sonde aval            */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acq_tension_sonde_o2_av;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqSenO2Ds(void)
{
   /*F02_AcqSenO2Ds*/
   uint16 u16LocalAcq_tension_sonde_o2_av;


   u16LocalAcq_tension_sonde_o2_av = ADCHAL_udtRead(CH_ADC_LBDW_V);
   VEMS_vidSET(Acq_tension_sonde_o2_av, u16LocalAcq_tension_sonde_o2_av);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcPresAC                                     */
/* !Description :  Acquisition de la tension du capteur de pression fluide    */
/*                 réfrigérant                                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquis_tension_press_refri;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcPresAC(void)
{
   /*F04_AcqAdcPresAC*/
   uint16 u16LocalAcq_ten_press_refri;


   u16LocalAcq_ten_press_refri = ADCHAL_udtRead(CH_ADC_AC_PRS_V);
   VEMS_vidSET(Acquis_tension_press_refri, u16LocalAcq_ten_press_refri);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcCoT                                        */
/* !Description :  Acquisition de la tension du capteur de température d'eau  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acq_tension_capt_temp_eau;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcCoT(void)
{
   /*F05_AcqAdcCoT*/
   uint16 u16LocalAcq_ten_capt_temp_eau;


   u16LocalAcq_ten_capt_temp_eau = ADCHAL_udtRead(CH_ADC_TCO_V);
   VEMS_vidSET(Acq_tension_capt_temp_eau, u16LocalAcq_ten_capt_temp_eau);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcAirT                                       */
/* !Description :  Acquisition de la tension du capteur de température d'air  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acq_tension_capt_temp_air;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcAirT(void)
{
   /*F06_AcqAdcAirT*/
   uint16 u16LocalAcq_ten_capt_temp_air;


   u16LocalAcq_ten_capt_temp_air = ADCHAL_udtRead(CH_ADC_TIA_V);
   VEMS_vidSET(Acq_tension_capt_temp_air, u16LocalAcq_ten_capt_temp_air);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcAccP1                                      */
/* !Description :  Acquisition de la position pédale d'accélérateur           */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acqui_position_pedale_1;                                    */
/*  output uint16 Acqui_position_pedale_2;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcAccP1(void)
{
   /*F07_AcqAdcAccP1*/
   uint16 u16LocalAcq_pos_pedale_1;
   uint16 u16LocalAcq_pos_pedale_2;


   u16LocalAcq_pos_pedale_1 = ADCHAL_udtRead(CH_ADC_PDL_V_1);
   VEMS_vidSET(Acqui_position_pedale_1, u16LocalAcq_pos_pedale_1);

   u16LocalAcq_pos_pedale_2 = ADCHAL_udtRead(CH_ADC_PDL_V_2);
   VEMS_vidSET(Acqui_position_pedale_2, u16LocalAcq_pos_pedale_2);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcAccP2                                      */
/* !Description :  Acquisition de la tension analogique du contacteur point   */
/*                 dur de la pédale d’accélérateur LVV                        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acqui_tension_contacteur_pt_dur;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcAccP2(void)
{
   /*F07_AcqAdcAccP2*/
   uint16 u16LocalAcq_ten_contact_pt_dur;


   u16LocalAcq_ten_contact_pt_dur = ADCHAL_udtRead(CH_ADC_PDL_PT_DUR);
   VEMS_vidSET(Acqui_tension_contacteur_pt_dur, u16LocalAcq_ten_contact_pt_dur);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_vidAcqAdcThr                                        */
/* !Description :  Acquisition de la position papillion capteur 1 et la       */
/*                 position papillion capteur 2                               */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Y.GANNOUN                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Acquisition_position_bpm_cpt1;                              */
/*  output uint16 Acquisition_position_bpm_cpt2;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_vidAcqAdcThr(void)
{
   /*F08_AcqAdcThr*/
   uint16 u16LocalAcquisition_pos_cpt1 ;
   uint16 u16LocalAcquisition_pos_cpt2;


   u16LocalAcquisition_pos_cpt1 = ADCHAL_udtRead(CH_ADC_THR_V_1);
   VEMS_vidSET(Acquisition_position_bpm_cpt1, u16LocalAcquisition_pos_cpt1);

   u16LocalAcquisition_pos_cpt2 = ADCHAL_udtRead(CH_ADC_THR_V_2);
   VEMS_vidSET(Acquisition_position_bpm_cpt2, u16LocalAcquisition_pos_cpt2);
}
/*------------------------------- end of file --------------------------------*/