/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINSERVO                                           */
/* !Description     : VLVACTINSERVO Component                                 */
/*                                                                            */
/* !Module          : VLVACTINSERVO                                           */
/* !Description     : Asservissement du decalage VVT admission                */
/*                                                                            */
/* !File            : VLVACTINSERVO_SCH.C                                     */
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
/*   1 / VlvAct_EveRst_InServo                                                */
/*   2 / VlvAct_EveInCmToo_InServo                                            */
/*   3 / VlvAct_SdlFast_InServo                                               */
/*   4 / VlvAct_EveKOn_InServo                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5060915 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068046                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINSERVO/VLVACTINS$*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   22 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   22 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "VLVACTINSERVO.h"
#include "VLVACTINSERVO_L.h"
#include "VLVACTINSERVO_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_InServo                                      */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06254_003.01                                     */
/*                 VEMS_E_08_06254_004.01                                     */
/*                 VEMS_E_08_06254_005.01                                     */
/*                 VEMS_R_08_06254_001.01                                     */
/*                 VEMS_R_08_06254_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINSERVO_vidInitRst();                              */
/*  extf argret void VLVACTINSERVO_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_InServo                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_InServo(void)
{
   VLVACTINSERVO_vidInitRst();
   VLVACTINSERVO_vidInitOutput();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveInCmToo_InServo                                  */
/* !Description :  Evènement dent AAC admission                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06254_003.01                                     */
/*                 VEMS_E_08_06254_004.01                                     */
/*                 VEMS_E_08_06254_005.01                                     */
/*                 VEMS_R_08_06254_001.01                                     */
/*                 VEMS_R_08_06254_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINSERVO_vidInitIntegral();                         */
/*  input uint8 VLVACTINSERVO_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveInCmToo_InServo                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveInCmToo_InServo(void)
{
   if (VLVACTINSERVO_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINSERVO_vidInitIntegral();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_InServo                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06254_003.01                                     */
/*                 VEMS_E_08_06254_004.01                                     */
/*                 VEMS_E_08_06254_005.01                                     */
/*                 VEMS_R_08_06254_001.01                                     */
/*                 VEMS_R_08_06254_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINSERVO_vidSetpVelocity();                         */
/*  extf argret void VLVACTINSERVO_vidControlAlgo();                          */
/*  extf argret void VLVACTINSERVO_vidSelDutyCycl();                          */
/*  extf argret void VLVACTINSERVO_vidVcpiDiagnosis();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 indexDefaut, argin boolean     */
/* bDgo, argin boolean bMonRun, argin boolean Ns_bMonWait);                   */
/*  input uint8 VLVACTINSERVO_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*  input boolean Vbx_pf_vvt_intake_blk;                                      */
/*  input boolean Vbx_pf_vvt_intake_int;                                      */
/*  input boolean VlvAct_bInServoEna;                                         */
/*  input boolean VlvActIn_bDgoServoErrVlvActIn;                              */
/*  input boolean VlvActIn_bMonRunServoErrVlvActIn;                           */
/*  input boolean VlvActIn_bDgoIMaxVlvActIn;                                  */
/*  input boolean VlvActIn_bMonRunIMaxVlvActIn;                               */
/*  output boolean VlvActIn_bDgoServoErrVlvActIn;                             */
/*  output boolean VlvActIn_bDgoIMaxVlvActIn;                                 */
/*  output boolean VlvActIn_bMonRunServoErrVlvActIn;                          */
/*  output boolean VlvActIn_bMonRunIMaxVlvActIn;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_InServo                                         */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_InServo(void)
{
   boolean bLocalVlvAct_bInServoEna;


   if (VLVACTINSERVO_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINSERVO_vidSetpVelocity();
         VLVACTINSERVO_vidControlAlgo();
         VLVACTINSERVO_vidSelDutyCycl();
         VLVACTINSERVO_vidVcpiDiagnosis();
         if (Vbx_pf_vvt_intake_blk !=0)
         {
            VlvActIn_bDgoServoErrVlvActIn = 1;
         }
         else
         {
            VlvActIn_bDgoServoErrVlvActIn = 0;
         }
         if (Vbx_pf_vvt_intake_int != 0)
         {
            VlvActIn_bDgoIMaxVlvActIn = 1;
         }
         else
         {
            VlvActIn_bDgoIMaxVlvActIn = 0;
         }

         VEMS_vidGET(VlvAct_bInServoEna, bLocalVlvAct_bInServoEna );

         if (bLocalVlvAct_bInServoEna != 0)
         {
            VlvActIn_bMonRunServoErrVlvActIn = 1;
            VlvActIn_bMonRunIMaxVlvActIn = 1;
         }
         else
         {
            VlvActIn_bMonRunServoErrVlvActIn = 0;
            VlvActIn_bMonRunIMaxVlvActIn = 0;
         }
         GDGAR_vidGdu(GD_DFT_SERVOERRVLVACTIN,
                      VlvActIn_bDgoServoErrVlvActIn,
                      VlvActIn_bMonRunServoErrVlvActIn,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_IMAXVLVACTIN,
                      VlvActIn_bDgoIMaxVlvActIn,
                      VlvActIn_bMonRunIMaxVlvActIn,
                      DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOn_InServo                                      */
/* !Description :  Clef on                                                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06254_005.01                                     */
/*                 VEMS_R_08_06254_001.01                                     */
/*                 VEMS_R_08_06254_002.01                                     */
/*                 VEMS_E_08_06254_003.01                                     */
/*                 VEMS_E_08_06254_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINSERVO_vidInitFailure();                          */
/*  input uint8 VLVACTINSERVO_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActInStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOn_InServo                                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOn_InServo(void)
{
   if (VLVACTINSERVO_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActInStr_C != 0)
      {
         VLVACTINSERVO_vidInitFailure();
      }
   }
}
/*-------------------------------end of file----------------------------------*/