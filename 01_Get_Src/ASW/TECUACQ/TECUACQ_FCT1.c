/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TECUACQ                                                 */
/* !Description     : TECUACQ Component                                       */
/*                                                                            */
/* !Module          : TECUACQ                                                 */
/* !Description     : ECU Temperature Acquisition                             */
/*                                                                            */
/* !File            : TECUACQ_FCT1.C                                          */
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
/*   1 / TECUACQ_vidInit                                                      */
/*   2 / TECUACQ_vidAcquisition                                               */
/*   3 / TECUACQ_vidDiagnosis                                                 */
/*   4 / TECUACQ_vidElectrical_Diagnosis                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6851405 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TECUACQ/TECUACQ_FCT1.C_v        $*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   01 Sep 2014 $*/
/* $Author::   etsasson                               $$Date::   01 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TECUACQ.h"
#include "TECUACQ_L.h"
#include "TECUACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TECUACQ_vidInit                                            */
/* !Description :  ECU temperature is set to a configurable initialization    */
/*                 value at the reset.                                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SenAct_tECUIni_C;                                             */
/*  output uint8 SenAct_tECUAcq;                                              */
/*  output uint8 SenAct_tECUIni_C;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TECUACQ_vidInit(void)
{
   VEMS_vidSET(SenAct_tECUAcq, SenAct_tECUIni_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TECUACQ_vidAcquisition                                     */
/* !Description :  The voltage sent by the sensor is converted into the ECU   */
/*                 temperature with a linear interpolation based on the       */
/*                 characteristic behavior of the sensor.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenAct_utECUMes;                                             */
/*  input uint16 SenAct_tECUAcq_utECUMes_A[33];                               */
/*  input uint8 SenAct_utECU_T[33];                                           */
/*  output uint8 SenAct_tECUAcq;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TECUACQ_vidAcquisition(void)
{
   uint8  u8LocalData1;
   uint16 u16LocalSenAct_utECUMes;
   uint16 u16LocalPara;


   VEMS_vidGET(SenAct_utECUMes, u16LocalSenAct_utECUMes);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(SenAct_tECUAcq_utECUMes_A,
                                               u16LocalSenAct_utECUMes,
                                               33);

   u8LocalData1 = MATHSRV_u8Interp1d(SenAct_utECU_T,
                                    u16LocalPara);

   VEMS_vidSET(SenAct_tECUAcq, u8LocalData1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TECUACQ_vidDiagnosis                                       */
/* !Description :  The ECU temperature electrical diagnoses are carried out if*/
/*                 there is no downgraded mode inhibition.                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void TECUACQ_vidElectrical_Diagnosis();                       */
/*  output boolean SenAct_bMonRunScg_tECUAcq;                                 */
/*  output boolean SenAct_bMonRunScp_tECUAcq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TECUACQ_vidDiagnosis(void)
{
   boolean bLocalInhDiag_tECUAcq;


   bLocalInhDiag_tECUAcq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_TECUACQ);
   if (bLocalInhDiag_tECUAcq != 0)
   {
      SenAct_bMonRunScg_tECUAcq = 0;
      SenAct_bMonRunScp_tECUAcq = 0;
   }
   else
   {
      SenAct_bMonRunScg_tECUAcq = 1;
      SenAct_bMonRunScp_tECUAcq = 1;
      TECUACQ_vidElectrical_Diagnosis();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TECUACQ_vidElectrical_Diagnosis                            */
/* !Description :  The electrical diagnosis is managed in this sub-system.    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  I.JEMAÏ                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SenAct_utECUMes;                                             */
/*  input uint16 SenAct_uDgoScg_tECUAcq_C;                                    */
/*  input uint16 SenAct_uDgoScp_tECUAcq_C;                                    */
/*  output boolean SenAct_bDgoScg_tECUAcq;                                    */
/*  output boolean SenAct_bDgoScp_tECUAcq;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TECUACQ_vidElectrical_Diagnosis(void)
{
   uint16 u16LocalSenAct_utECUMes;


   VEMS_vidGET(SenAct_utECUMes, u16LocalSenAct_utECUMes);
   if (u16LocalSenAct_utECUMes < SenAct_uDgoScg_tECUAcq_C)
   {
      SenAct_bDgoScg_tECUAcq = 1;
   }
   else
   {
      SenAct_bDgoScg_tECUAcq = 0;
   }
   if (u16LocalSenAct_utECUMes > SenAct_uDgoScp_tECUAcq_C)
   {
      SenAct_bDgoScp_tECUAcq = 1;
   }
   else
   {
      SenAct_bDgoScp_tECUAcq = 0;
   }
}

/*------------------------------- end of file --------------------------------*/