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
/* !File            : TIGBTACQ_FCT1.C                                         */
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
/*   1 / TIGBTACQ_vidInit                                                     */
/*   2 / TIGBTACQ_vidAcquisition                                              */
/*   3 / TIGBTACQ_vidDiagnosis                                                */
/*   4 / TIGBTACQ_vidElectrical_Diagnosis                                     */
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

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TIGBTACQ.h"
#include "TIGBTACQ_L.h"
#include "TIGBTACQ_IM.h"
#include "GDGAR.H"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIGBTACQ_vidInit                                           */
/* !Description :  At reset the IGBT temperature is set to a configurable     */
/*                 initialization value.                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SenAct_tIGBTIni_C;                                            */
/*  output uint8 SenAct_tIGBTAcq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIGBTACQ_vidInit(void)
{
   uint8 u8LocalSenAct_tIGBTAcq;


   u8LocalSenAct_tIGBTAcq = SenAct_tIGBTIni_C;
   VEMS_vidSET(SenAct_tIGBTAcq, u8LocalSenAct_tIGBTAcq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIGBTACQ_vidAcquisition                                    */
/* !Description :  The voltage sent by the sensor is converted into the IGBT  */
/*                 temperature with a linear interpolation based on the       */
/*                 characteristic behavior of the sensor.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenAct_utIGBTMes;                                            */
/*  input uint16 SenAct_tIGBTAcq_utIGBTMes_A[33];                             */
/*  input uint8 SenAct_utIGBT_T[33];                                          */
/*  output uint8 SenAct_tIGBTAcq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIGBTACQ_vidAcquisition(void)
{
   uint8  u8LocalInterp;
   uint16 u16LocalSenAct_utIGBTMes;
   uint16 u16LocalCalcPara;


   VEMS_vidGET(SenAct_utIGBTMes, u16LocalSenAct_utIGBTMes);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SenAct_tIGBTAcq_utIGBTMes_A,
                                                   u16LocalSenAct_utIGBTMes,
                                                   33);
   u8LocalInterp =
      MATHSRV_u8Interp1d(SenAct_utIGBT_T, u16LocalCalcPara);
   VEMS_vidSET(SenAct_tIGBTAcq, u8LocalInterp);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIGBTACQ_vidDiagnosis                                      */
/* !Description :  The IGBT temperature electrical diagnoses are carried out  */
/*                 if there is no downgraded mode inhibition.                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void TIGBTACQ_vidElectrical_Diagnosis();                      */
/*  output boolean SenAct_bMonRunScg_tIGBTAcq;                                */
/*  output boolean SenAct_bMonRunScp_tIGBTAcq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIGBTACQ_vidDiagnosis(void)
{
   boolean bLocalFRM_bInhDiag_tIGBTAcq;


   bLocalFRM_bInhDiag_tIGBTAcq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_TIGBTACQ);
   if (bLocalFRM_bInhDiag_tIGBTAcq != 0)
   {
      SenAct_bMonRunScg_tIGBTAcq = 0;
      SenAct_bMonRunScp_tIGBTAcq = 0;

   }
   else
   {
      SenAct_bMonRunScg_tIGBTAcq = 1;
      SenAct_bMonRunScp_tIGBTAcq = 1;
      TIGBTACQ_vidElectrical_Diagnosis();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TIGBTACQ_vidElectrical_Diagnosis                           */
/* !Description :  The voltage sent by the IGBT temperature sensor is compared*/
/*                 to high and low thresholds; if it is out of this range,    */
/*                 error flags are produced: short circuit to ground and short*/
/*                 circuit to the power source, respectively.                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SenAct_utIGBTMes;                                            */
/*  input uint16 SenAct_uDgoScg_tIGBTAcq_C;                                   */
/*  input uint16 SenAct_uDgoScp_tIGBTAcq_C;                                   */
/*  output boolean SenAct_bDgoScg_tIGBTAcq;                                   */
/*  output boolean SenAct_bDgoScp_tIGBTAcq;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TIGBTACQ_vidElectrical_Diagnosis(void)
{
   uint16 u16LocalSenAct_utIGBTMes;


   VEMS_vidGET(SenAct_utIGBTMes, u16LocalSenAct_utIGBTMes);

   if (u16LocalSenAct_utIGBTMes < SenAct_uDgoScg_tIGBTAcq_C)
   {
      SenAct_bDgoScg_tIGBTAcq = 1;
   }
   else
   {
      SenAct_bDgoScg_tIGBTAcq = 0;
   }
   if (u16LocalSenAct_utIGBTMes > SenAct_uDgoScp_tIGBTAcq_C)
   {
      SenAct_bDgoScp_tIGBTAcq = 1;
   }
   else
   {
      SenAct_bDgoScp_tIGBTAcq = 0;
   }
}

/*------------------------------ End of file ---------------------------------*/