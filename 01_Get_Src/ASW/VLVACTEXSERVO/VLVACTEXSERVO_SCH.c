/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXSERVO                                           */
/* !Description     : VLVACTEXSERVO Component                                 */
/*                                                                            */
/* !Module          : VLVACTEXSERVO                                           */
/* !Description     : Asservissement du decalage VVT echappement              */
/*                                                                            */
/* !File            : VLVACTEXSERVO_SCH.C                                     */
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
/*   1 / VlvAct_EveRst_ExServo                                                */
/*   2 / VlvAct_EveExCmToo_ExServo                                            */
/*   3 / VlvAct_SdlFast_ExServo                                               */
/*   4 / VlvAct_EveKOn_ExServo                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5060920 / 04                                        */
/* !OtherRefs   : VEMS V02 ECU#068045                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXSERVO/VLVACTEXS$*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   22 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   22 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "VLVACTEXSERVO.h"
#include "VLVACTEXSERVO_L.h"
#include "VLVACTEXSERVO_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveRst_ExServo                                      */
/* !Description :  Evènement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06281_003.01                                     */
/*                 VEMS_E_08_06281_004.01                                     */
/*                 VEMS_E_08_06281_005.01                                     */
/*                 VEMS_R_08_06281_001.01                                     */
/*                 VEMS_R_08_06281_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXSERVO_vidInitRst();                              */
/*  extf argret void VLVACTEXSERVO_vidInitOutput();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveRst_ExServo                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveRst_ExServo(void)
{
   VLVACTEXSERVO_vidInitRst();
   VLVACTEXSERVO_vidInitOutput();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveExCmToo_ExServo                                  */
/* !Description :  Evènement dent AAC admission                               */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06281_003.01                                     */
/*                 VEMS_E_08_06281_004.01                                     */
/*                 VEMS_E_08_06281_005.01                                     */
/*                 VEMS_R_08_06281_001.01                                     */
/*                 VEMS_R_08_06281_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXSERVO_vidInitIntegral();                         */
/*  input uint8 VLVACTEXSERVO_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveExCmToo_ExServo                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveExCmToo_ExServo(void)
{
   if (VLVACTEXSERVO_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXSERVO_vidInitIntegral();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_SdlFast_ExServo                                     */
/* !Description :  Moniteur rapide pour la fonction VVT                       */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06281_003.01                                     */
/*                 VEMS_E_08_06281_004.01                                     */
/*                 VEMS_E_08_06281_005.01                                     */
/*                 VEMS_R_08_06281_001.01                                     */
/*                 VEMS_R_08_06281_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXSERVO_vidSetpVelocity();                         */
/*  extf argret void VLVACTEXSERVO_vidControlAlgo();                          */
/*  extf argret void VLVACTEXSERVO_vidSelDutyCycl();                          */
/*  extf argret void VLVACTEXSERVO_vidVcpeDiagnosis();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 indexDefaut, argin boolean     */
/* bDgo, argin boolean bMonRun, argin boolean Ns_bMonWait);                   */
/*  input uint8 VLVACTEXSERVO_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*  input boolean Vbx_pf_vvt_exhaust_blk;                                     */
/*  input boolean Vbx_pf_vvt_exhaust_int;                                     */
/*  input boolean VlvAct_bExServoEna;                                         */
/*  input boolean VlvActEx_bDgoServoErrVlvActEx;                              */
/*  input boolean VlvActEx_bMonRunServoErrVlvActEx;                           */
/*  input boolean VlvActEx_bDgoIMaxVlvActEx;                                  */
/*  input boolean VlvActEx_bMonRunIMaxVlvActEx;                               */
/*  output boolean VlvActEx_bDgoServoErrVlvActEx;                             */
/*  output boolean VlvActEx_bDgoIMaxVlvActEx;                                 */
/*  output boolean VlvActEx_bMonRunServoErrVlvActEx;                          */
/*  output boolean VlvActEx_bMonRunIMaxVlvActEx;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_SdlFast_ExServo                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_SdlFast_ExServo(void)
{
   boolean bLocalVlvAct_bExServoEna;


   if (VLVACTEXSERVO_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXSERVO_vidSetpVelocity();
         VLVACTEXSERVO_vidControlAlgo();
         VLVACTEXSERVO_vidSelDutyCycl();
         VLVACTEXSERVO_vidVcpeDiagnosis();
         if (Vbx_pf_vvt_exhaust_blk !=0)
         {
            VlvActEx_bDgoServoErrVlvActEx = 1;
         }
         else
         {
            VlvActEx_bDgoServoErrVlvActEx = 0;
         }
         if (Vbx_pf_vvt_exhaust_int != 0)
         {
            VlvActEx_bDgoIMaxVlvActEx = 1;
         }
         else
         {
            VlvActEx_bDgoIMaxVlvActEx = 0;
         }

         VEMS_vidGET(VlvAct_bExServoEna, bLocalVlvAct_bExServoEna);

         if (bLocalVlvAct_bExServoEna != 0)
         {
            VlvActEx_bMonRunServoErrVlvActEx = 1;
            VlvActEx_bMonRunIMaxVlvActEx = 1;
         }
         else
         {
            VlvActEx_bMonRunServoErrVlvActEx = 0;
            VlvActEx_bMonRunIMaxVlvActEx = 0;
         }
         GDGAR_vidGdu(GD_DFT_SERVOERRVLVACTEX,
                      VlvActEx_bDgoServoErrVlvActEx,
                      VlvActEx_bMonRunServoErrVlvActEx,DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_IMAXVLVACTEX,
                      VlvActEx_bDgoIMaxVlvActEx,
                      VlvActEx_bMonRunIMaxVlvActEx,DIAG_DISPO);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VlvAct_EveKOn_ExServo                                      */
/* !Description :  Clef on                                                    */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_08_06281_003.01                                     */
/*                 VEMS_E_08_06281_004.01                                     */
/*                 VEMS_E_08_06281_005.01                                     */
/*                 VEMS_R_08_06281_001.01                                     */
/*                 VEMS_R_08_06281_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXSERVO_vidInitFailure();                          */
/*  input uint8 VLVACTEXSERVO_u8Inhib;                                        */
/*  input boolean VlvAct_bAcvVlvActExStr_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : VlvAct_EveKOn_ExServo                                          */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VlvAct_EveKOn_ExServo(void)
{
   if (VLVACTEXSERVO_u8Inhib != 0x5A)
   {
      if (VlvAct_bAcvVlvActExStr_C != 0)
      {
         VLVACTEXSERVO_vidInitFailure();
      }
   }
}
/*-------------------------------end of file----------------------------------*/