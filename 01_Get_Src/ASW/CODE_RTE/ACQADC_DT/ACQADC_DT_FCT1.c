/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQADC_DT                                               */
/* !Description     : ACQADC_DT Component.                                    */
/*                                                                            */
/* !Module          : ACQADC_DT                                               */
/* !Description     : SPECIFICATION OF ANALOG  ACQUISITIONS (ADCHAL)          */
/*                                                                            */
/* !File            : ACQADC_DT_FCT1.C                                        */
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
/*   1 / ACQADC_DT_vidInit                                                    */
/*   2 / ACQADC_DT_vidSpgPresAcq                                              */
/*   3 / ACQADC_DT_vidTIGBTAcq                                                */
/*   4 / ACQADC_DT_vidOilPresAcq                                              */
/*   5 / ACQADC_DT_vidPFuAcq_Spill                                            */
/*   6 / ACQADC_DT_vidPFuAcq_Inj                                              */
/*   7 / ACQADC_DT_vidTECUAcq                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_6913284 / 01                                        */
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

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "ACQADC_DT.h"
#include "ACQADC_DT_L.h"
#include "ACQADC_DT_IM.h"
#include "ADCHAL.h"
#include "ACQADC_DT_toRte.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidInit                                          */
/* !Description :  The outputs are initialized to zero at event reset.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 SenAct_utECUMes;                                            */
/*  output uint16 Ext_upFuMes;                                                */
/*  output uint16 SenAct_utIGBTMes;                                           */
/*  output uint16 Ext_uSpgPresSenVolt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidInit(void)
{
   VEMS_vidSET(SenAct_utECUMes, 0);
   VEMS_vidSET(Ext_upFuMes, 0);
   VEMS_vidSET(SenAct_utIGBTMes, 0);
   VEMS_vidSET(Ext_uSpgPresSenVolt, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidSpgPresAcq                                    */
/* !Description :  The raw voltage is acquired by the boost pressure sensor   */
/*                 according to the standard supply voltage of the sensor     */
/*                 before being sent to the application software.             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_uSpgPresSenVolt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidSpgPresAcq(void)
{
   uint16 u16LocalExt_uSpgPresSenVolt;


   u16LocalExt_uSpgPresSenVolt = ADCHAL_udtRead(CH_ADC_PRESS_TURBO);
   u16LocalExt_uSpgPresSenVolt =
      (uint16)MATHSRV_udtMIN(u16LocalExt_uSpgPresSenVolt, 4095);
   VEMS_vidSET(Ext_uSpgPresSenVolt, u16LocalExt_uSpgPresSenVolt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidTIGBTAcq                                      */
/* !Description :  The raw voltage is acquired by the IGBT temperature sensor */
/*                 according to the standard supply voltage of the sensor     */
/*                 before being sent to the application software.             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 SenAct_utIGBTMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidTIGBTAcq(void)
{
   uint16 u16LocalSenAct_utIGBTMes;


   u16LocalSenAct_utIGBTMes = ADCHAL_udtRead(CH_ADC_INT_IGBT_TMP);
   u16LocalSenAct_utIGBTMes = (uint16)(u16LocalSenAct_utIGBTMes / 4);
   u16LocalSenAct_utIGBTMes =
      (uint16)MATHSRV_udtMIN(u16LocalSenAct_utIGBTMes, 1024);
   VEMS_vidSET(SenAct_utIGBTMes, u16LocalSenAct_utIGBTMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidOilPresAcq                                    */
/* !Description :  The raw voltage is acquired by the oil proportional        */
/*                 pressure sensor according to the standard supply voltage of*/
/*                 the sensor before being sent to the application software   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_upOilMes;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidOilPresAcq(void)
{
   uint16 u16LocalExt_upOilMes;


   u16LocalExt_upOilMes = ADCHAL_udtRead(CH_ADC_OILPROPPRESACQ);
   u16LocalExt_upOilMes = (uint16)MATHSRV_udtMIN(u16LocalExt_upOilMes, 4096);
   VEMS_vidSET(Ext_upOilMes, u16LocalExt_upOilMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidPFuAcq_Spill                                  */
/* !Description :  The raw voltage is acquired by the rail pressure sensor if */
/*                 the engine is not synchronized or at “spill event” when the*/
/*                 engine is synchronized.                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_upFuMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidPFuAcq_Spill(void)
{
   uint16 u16LocalExt_upFuMes;


   u16LocalExt_upFuMes = ADCHAL_udtRead(CH_ADC_PRESS_RAMPE);
   u16LocalExt_upFuMes = (uint16)MATHSRV_udtMIN(u16LocalExt_upFuMes, 4095);
   VEMS_vidSET(Ext_upFuMes, u16LocalExt_upFuMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidPFuAcq_Inj                                    */
/* !Description :  The raw voltage is acquired by the rail pressure sensor if */
/*                 the engine is not running or at INJ event when the engine  */
/*                 is running.                                                */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_upFuMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidPFuAcq_Inj(void)
{
   uint16 u16LocalExt_upFuMes;


   u16LocalExt_upFuMes = ADCHAL_udtRead(CH_ADC_PRESS_RAMPE);
   u16LocalExt_upFuMes = (uint16)MATHSRV_udtMIN(u16LocalExt_upFuMes, 4095);
   VEMS_vidSET(Ext_upFuMes, u16LocalExt_upFuMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQADC_DT_vidTECUAcq                                       */
/* !Description :  The raw voltage is acquired by the power supply sensor     */
/*                 according to the standard supply voltage of the sensor     */
/*                 before being sent to the application software.             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret ADCHAL_tudtAdcResult  ADCHAL_udtRead(argin uint8 u8Channel);  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 SenAct_utECUMes;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQADC_DT_vidTECUAcq(void)
{
   uint16 u16LocalSenAct_utECUMes;


   u16LocalSenAct_utECUMes = ADCHAL_udtRead(CH_ADC_TEMP_INTERNE);
   u16LocalSenAct_utECUMes = (uint16)(u16LocalSenAct_utECUMes / 4);
   u16LocalSenAct_utECUMes =
      (uint16)MATHSRV_udtMIN(u16LocalSenAct_utECUMes, 1024);
   VEMS_vidSET(SenAct_utECUMes, u16LocalSenAct_utECUMes);
}
/*-------------------------------- end of file -------------------------------*/