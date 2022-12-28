/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OFSVLV                                                  */
/* !Description     : OFSVLV Component                                        */
/*                                                                            */
/* !Module          : OFSVLV                                                  */
/* !Description     : Limitation balayage et coordination des consignes VVT   */
/*                                                                            */
/* !File            : OFSVLV_FCT3.C                                           */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / OFSVLV_vidLimitation_consignes                                       */
/*   2 / OFSVLV_vidMode_banc                                                  */
/*   3 / OFSVLV_vidBanc_Admission                                             */
/*   4 / OFSVLV_vidBanc_Echappement                                           */
/*   5 / OFSVLV_vidActivation                                                 */
/*   6 / OFSVLV_vidTransition_activation                                      */
/*   7 / OFSVLV_vidActAdmission                                               */
/*   8 / OFSVLV_vidActEchappement                                             */
/*   9 / OFSVLV_vidPilotage_VVT_en_butee                                      */
/*   10 / OFSVLV_vidPilotAdmission                                            */
/*                                                                            */
/* !Reference   : V02 NT 11 02164 / 02                                        */
/* !OtherRefs   : 01460_10_03509_2/1.1                                        */
/* !OtherRefs   : VEMS V02 ECU#053816                                         */
/* !OtherRefs   : VEMS V02 ECU#054358                                         */
/* !OtherRefs   : VEMS V02 ECU#061723                                         */
/* !OtherRefs   : VEMS V02 ECU#067972                                         */
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
#include "OFSVLV.h"
#include "OFSVLV_L.h"
#include "OFSVLV_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidLimitation_consignes                             */
/* !Description :  Elle permet de saturer les consignes VVT admission et      */
/*                 échappement nominales avec la consigne VVT admission       */
/*                 minimum et la consigne VVT échappement maximum limitant le */
/*                 balayage.                                                  */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint8 VlvSys_agCkOpInVlvSatCorReq;                                  */
/*  input sint8 VlvSys_agCkClsExVlvSatCorReq;                                 */
/*  input boolean VlvSys_bPresTrb_C;                                          */
/*  input uint8 VlvSys_agCkOpInVlvMin;                                        */
/*  input uint8 VlvSys_agCkClsExVlvMax;                                       */
/*  output uint8 VlvSys_agCkOpInVlvScvCorReq;                                 */
/*  output uint8 VlvSys_agCkClsExVlvScvCorReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidLimitation_consignes(void)
{
   /*F02_Limitation_consignes */
   uint8 u8LocalCkClsExVlvSatCorReq;
   uint8 u8LocalCkOpInVlvSatCorReq;
   sint8 s8LocalCkClsExVlvSatCorReq;
   sint8 s8LocalCkOpInVlvSatCorReq;


   VEMS_vidGET(VlvSys_agCkOpInVlvSatCorReq, s8LocalCkOpInVlvSatCorReq);
   VEMS_vidGET(VlvSys_agCkClsExVlvSatCorReq, s8LocalCkClsExVlvSatCorReq);

   if (VlvSys_bPresTrb_C != 0)
   {
      u8LocalCkOpInVlvSatCorReq = (uint8)(s8LocalCkOpInVlvSatCorReq + 128);
      VlvSys_agCkOpInVlvScvCorReq =
         (uint8) MATHSRV_udtMAX(VlvSys_agCkOpInVlvMin,
                                u8LocalCkOpInVlvSatCorReq);
      u8LocalCkClsExVlvSatCorReq = (uint8)(s8LocalCkClsExVlvSatCorReq + 128);
      VlvSys_agCkClsExVlvScvCorReq =
         (uint8) MATHSRV_udtMIN(VlvSys_agCkClsExVlvMax,
                                u8LocalCkClsExVlvSatCorReq);
   }
   else
   {
      VlvSys_agCkOpInVlvScvCorReq = (uint8)(s8LocalCkOpInVlvSatCorReq + 128);
      VlvSys_agCkClsExVlvScvCorReq = (uint8)(s8LocalCkClsExVlvSatCorReq + 128);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidMode_banc                                        */
/* !Description :  Elle détermine les consignes VVT admission et échappement  */
/*                 après prise en compte du mode banc.                        */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidBanc_Admission();                              */
/*  extf argret void OFSVLV_vidBanc_Echappement();                            */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidMode_banc(void)
{
   /*F04_mode_banc */
   if (VlvSys_bPresInServo_C != 0)
   {
      OFSVLV_vidBanc_Admission();
   }
   if (VlvSys_bPresExServo_C != 0)
   {
      OFSVLV_vidBanc_Echappement();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidBanc_Admission                                   */
/* !Description :  Elle détermine les consignes VVT admission après prise en  */
/*                 compte du mode banc.                                       */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvSys_bAcvInVlvBedMod_C;                                   */
/*  input uint8 VlvSys_agCkOpInVlvBedMod_C;                                   */
/*  input uint8 VlvSys_agCkOpInVlvScvCorReq;                                  */
/*  output uint8 VlvSys_agCkOpInVlvBedModCorReq;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidBanc_Admission(void)
{
   /*F01_Admission */
   if (VlvSys_bAcvInVlvBedMod_C != 0)
   {
      VlvSys_agCkOpInVlvBedModCorReq = VlvSys_agCkOpInVlvBedMod_C;
   }
   else
   {
      VlvSys_agCkOpInVlvBedModCorReq = VlvSys_agCkOpInVlvScvCorReq;

   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidBanc_Echappement                                 */
/* !Description :  Elle détermine les consignes VVT échappement après prise en*/
/*                 compte du mode banc.                                       */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvSys_bAcvExVlvBedMod_C;                                   */
/*  input uint8 VlvSys_agCkClsExVlvBedMod_C;                                  */
/*  input uint8 VlvSys_agCkClsExVlvScvCorReq;                                 */
/*  output uint8 VlvSys_agCkClsExVlvBedModCorReq;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidBanc_Echappement(void)
{
   /*F02_Echappement */
   if (VlvSys_bAcvExVlvBedMod_C != 0)
   {
      VlvSys_agCkClsExVlvBedModCorReq = VlvSys_agCkClsExVlvBedMod_C;
   }
   else
   {
      VlvSys_agCkClsExVlvBedModCorReq = VlvSys_agCkClsExVlvScvCorReq;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidActivation                                       */
/* !Description :  Elle détermine les consignes VVT admission et échappement  */
/*                 après prise en compte de l'activation du système           */
/*                 d'actionneur VVT (autorisation venant de la boucle locale).*/
/* !Number      :  FCT3.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidTransition_activation();                       */
/*  extf argret void OFSVLV_vidActAdmission();                                */
/*  extf argret void OFSVLV_vidActEchappement();                              */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidActivation(void)
{
   /*F05_activation*/
   OFSVLV_vidTransition_activation();
   if (VlvSys_bPresInServo_C != 0)
   {
      OFSVLV_vidActAdmission();
   }
   if (VlvSys_bPresExServo_C != 0)
   {
      OFSVLV_vidActEchappement();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidTransition_activation                            */
/* !Description :  Elle détermine pour les consignes VVT admission  et        */
/*                 échappement le facteur de transition                       */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  input uint16 VlvSys_rTranAcvVlvSys;                                       */
/*  input uint16 VlvSys_facTranFilStepAcvServo_C;                             */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*  output uint16 VlvSys_rTranAcvVlvSys;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidTransition_activation(void)
{
   /* F01_Transition_activation  */
   boolean bLocalVlvAct_bAcvInServo;
   boolean bLocalVlvAct_bAcvExServo;
   uint32  u32Localop1;
   uint32  u32Localop2;
   sint32  s32LocalTranAcvVlvSys;


   VEMS_vidGET(VlvAct_bAcvInServo, bLocalVlvAct_bAcvInServo);
   VEMS_vidGET(VlvAct_bAcvExServo, bLocalVlvAct_bAcvExServo);
   u32Localop1 = (uint32)(VlvSys_rTranAcvVlvSys * 13107);
   u32Localop2 = (uint32)(VlvSys_facTranFilStepAcvServo_C * 200);

   if (  (  (  (VlvSys_bPresInServo_C != 0)
            && ( bLocalVlvAct_bAcvInServo != 0))
         || (VlvSys_bPresInServo_C == 0))
      && (  (  (VlvSys_bPresExServo_C != 0)
            && (bLocalVlvAct_bAcvExServo != 0))
         || (VlvSys_bPresExServo_C == 0)))
   {
      s32LocalTranAcvVlvSys =
         (sint32)((u32Localop2 + u32Localop1) + 6553) / 13107;
   }
   else
   {
      if (u32Localop1 < u32Localop2)
      {
         s32LocalTranAcvVlvSys =
            ((sint32)(u32Localop1 - u32Localop2) - 6553) / 13107;
      }
      else
      {
         s32LocalTranAcvVlvSys =
            ((sint32)(u32Localop1 - u32Localop2) + 6553) / 13107;
      }
   }
   VlvSys_rTranAcvVlvSys =
      (uint16)MATHSRV_udtCLAMP(s32LocalTranAcvVlvSys, 0, 1000);
   /*QAC Msg(3:3356) The CLAMP is covered in the Unitary test*/
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidActAdmission                                     */
/* !Description :  Elle détermine les consignes VVT admission après prise en  */
/*                 compte de l'activation du système d'actionneur  VVT.       */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvSys_rTranAcvVlvSys;                                       */
/*  input uint8 VlvSys_agCkOpInVlvBedModCorReq;                               */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0Max;                                 */
/*  output uint8 VlvSys_agCkOpInVlvAcvCorReq;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidActAdmission(void)
{
   /*F02_Admission */
   uint8  u8LocalOpInVlvAcvCorReq;
   uint16 u16LocalTranAcvVlvSys;


   u16LocalTranAcvVlvSys = (uint16)MATHSRV_udtMIN(VlvSys_rTranAcvVlvSys, 1000);
   u8LocalOpInVlvAcvCorReq = (uint8)( ( ( ( u16LocalTranAcvVlvSys
                                          * VlvSys_agCkOpInVlvBedModCorReq)
                                         + ( ( 1000
                                             - u16LocalTranAcvVlvSys)
                                           * VlvSys_agCkOpInVlvReqRef0Max))
                                       + 500)
                                    / 1000);
   VEMS_vidSET(VlvSys_agCkOpInVlvAcvCorReq, u8LocalOpInVlvAcvCorReq);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidActEchappement                                   */
/* !Description :  Elle détermine les consignes VVT échappement après prise en*/
/*                 compte de l'activation du système d'actionneur             */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 VlvSys_rTranAcvVlvSys;                                       */
/*  input uint8 VlvSys_agCkClsExVlvBedModCorReq;                              */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0Min;                                */
/*  output uint8 VlvSys_agCkClsExVlvAcvCorReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidActEchappement(void)
{
   /*  F03_Echappement */
   uint8  u8LocalClsExVlvAcvCorReq;
   uint16 u16LocalTranAcvVlvSys;


   u16LocalTranAcvVlvSys = (uint16) MATHSRV_udtMIN(VlvSys_rTranAcvVlvSys, 1000);

   u8LocalClsExVlvAcvCorReq = (uint8)( ( ( ( u16LocalTranAcvVlvSys
                                           * VlvSys_agCkClsExVlvBedModCorReq)
                                         + ( ( 1000
                                             - u16LocalTranAcvVlvSys)
                                           * VlvSys_agCkClsExVlvReqRef0Min))
                                       + 500)
                                     / 1000);
   VEMS_vidSET(VlvSys_agCkClsExVlvAcvCorReq, u8LocalClsExVlvAcvCorReq);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPilotage_VVT_en_butee                            */
/* !Description :  Elle détermine les consignes VVT admission et échappement  */
/*                 après prise en compte de la consigne issue de la  boucle   */
/*                 locale.                                                    */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidPilotAdmission();                              */
/*  extf argret void OFSVLV_vidPilotEchappement();                            */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPilotage_VVT_en_butee(void)
{
   /*F06_Pilotage_VVT_en_butee */
   if (VlvSys_bPresInServo_C != 0)
   {
      OFSVLV_vidPilotAdmission();
   }
   if (VlvSys_bPresExServo_C != 0)
   {
      OFSVLV_vidPilotEchappement();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPilotAdmission                                   */
/* !Description :  Elle détermine les consignes VVT admission après prise en  */
/*                 compte de la consigne issue de la boucle locale.           */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bCmdInServoLocLop;                                   */
/*  input uint8 VlvSys_agCkOpInVlvAcvCorReq;                                  */
/*  input sint8 VlvAct_agCkOpInVlvReqRef0;                                    */
/*  output uint8 VlvSys_agCkOpInVlvLocLopCorReq;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPilotAdmission(void)
{
   /*F01_Admission */
   boolean bLocalCmdInServoLocLop;
   uint8   u8LocalCkOpInVlvAcvCorReq;
   sint8   s8LocalCkOpInVlvReqRef0;

   VEMS_vidGET(VlvAct_bCmdInServoLocLop, bLocalCmdInServoLocLop);
   VEMS_vidGET(VlvSys_agCkOpInVlvAcvCorReq, u8LocalCkOpInVlvAcvCorReq);
   VEMS_vidGET(VlvAct_agCkOpInVlvReqRef0, s8LocalCkOpInVlvReqRef0);
   if (bLocalCmdInServoLocLop != 0)
   {
      VlvSys_agCkOpInVlvLocLopCorReq = u8LocalCkOpInVlvAcvCorReq;
   }
   else
   {
      VlvSys_agCkOpInVlvLocLopCorReq = (uint8)(s8LocalCkOpInVlvReqRef0 + 128);
   }
}

/*------------------------------- end of file --------------------------------*/