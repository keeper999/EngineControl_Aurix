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
/* !File            : OFSVLV_FCT4.C                                           */
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
/*   1 / OFSVLV_vidPilotEchappement                                           */
/*   2 / OFSVLV_vidPanne                                                      */
/*   3 / OFSVLV_vidPanneAdmission                                             */
/*   4 / OFSVLV_vidPanneEchappement                                           */
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
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPilotEchappement                                 */
/* !Description :  Elle détermine les consignes VVT admission après prise en  */
/*                 compte de la consigne issue de la boucle locale.           */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bCmdExServoLocLop;                                   */
/*  input uint8 VlvSys_agCkClsExVlvAcvCorReq;                                 */
/*  input sint8 VlvAct_agCkClsExVlvReqRef0;                                   */
/*  output uint8 VlvSys_agCkClsExVlvLocLopCorReq;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPilotEchappement(void)
{
   /*F02_Echappement */
   boolean bLocalCmdExServoLocLop;
   uint8   u8LocalCkClsExVlvAcvCorReq;
   sint8   s8LocalCkClsExVlvReqRef0;


   VEMS_vidGET(VlvAct_bCmdExServoLocLop, bLocalCmdExServoLocLop);
   VEMS_vidGET(VlvSys_agCkClsExVlvAcvCorReq, u8LocalCkClsExVlvAcvCorReq);
   VEMS_vidGET(VlvAct_agCkClsExVlvReqRef0, s8LocalCkClsExVlvReqRef0);

   if (bLocalCmdExServoLocLop != 0)
   {
      VlvSys_agCkClsExVlvLocLopCorReq = u8LocalCkClsExVlvAcvCorReq;
   }
   else
   {
      VlvSys_agCkClsExVlvLocLopCorReq = (uint8)(s8LocalCkClsExVlvReqRef0 + 128);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPanne                                            */
/* !Description :  Elle détermine les consignes VVT admission et échappement  */
/*                 après prise en compte des défauts possibles.               */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OFSVLV_vidPanneAdmission();                              */
/*  extf argret void OFSVLV_vidPanneEchappement();                            */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPanne(void)
{
   /*  F07_panne */
   if (VlvSys_bPresInServo_C != 0)
   {
      OFSVLV_vidPanneAdmission();
   }
   if (VlvSys_bPresExServo_C != 0)
   {
      OFSVLV_vidPanneEchappement();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPanneAdmission                                   */
/* !Description :  Elle détermine les consignes VVT admission après prise en  */
/*                 compte des défauts possibles.                              */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_agCkOpInVlvEstimRef0;                                    */
/*  input uint8 VlvSys_agCkOpInVlvAcvCorReq;                                  */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint16 VlvSys_rFilGainOpInVlv_T[8];                                 */
/*  input sint32 OFSVLV_s32Filtre1Mem;                                        */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0Max_C;                               */
/*  input sint16 OFSVLV_s16OutFilterIn;                                       */
/*  output sint16 OFSVLV_s16OutFilterIn;                                      */
/*  output sint32 OFSVLV_s32Filtre1Mem;                                       */
/*  output uint8 VlvSys_agCkOpInVlvReqRef0;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPanneAdmission(void)
{
   /*F01_Admission*/
   boolean bLocalAcvLockPosnInVlv;
   boolean bLocalAcvCurPosnRegInVlv;
   uint8   u8LocalCkOpInVlvReqRef0;
   uint8   u8LocalVlvSys_agCkOpInVlvAcvCorR;
   uint16  u16LocalExt_nEng;
   uint16  u16localInterp1d;
   uint16  u16LocalExtnEngParaX;
   uint16  u16localGain;
   uint16  u16LocalCkOpInVlvReqRef0;
   sint16  s16LocalCkOpInVlvEstimRef0;
   sint16  s16LocalOutFilterIn;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_agCkOpInVlvEstimRef0, s16LocalCkOpInVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkOpInVlvAcvCorReq, u8LocalVlvSys_agCkOpInVlvAcvCorR);

   u16LocalExtnEngParaX = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                       u16LocalExt_nEng,
                                                       8);
   u16localInterp1d =
      MATHSRV_u16Interp1d(VlvSys_rFilGainOpInVlv_T, u16LocalExtnEngParaX);
   /* Filter1 */
   if (u16localInterp1d == 0)
   {
      OFSVLV_s16OutFilterIn =
         (sint16)MATHSRV_udtCLAMP(s16LocalCkOpInVlvEstimRef0, -1024, 1023);
      OFSVLV_s32Filtre1Mem = (sint32)(s16LocalCkOpInVlvEstimRef0 * 65536);
   }
   else
   {
      u16localGain = (uint16)( (uint32)( VlvSys_tiSampleFast_SC
                                       * 65536)
                             / ( VlvSys_tiSampleFast_SC
                               + u16localInterp1d));
      s16LocalOutFilterIn =
         MATHSRV_s16FirstOrderFilterGu16(u16localGain,
                                        &OFSVLV_s32Filtre1Mem,
                                        s16LocalCkOpInVlvEstimRef0);
      OFSVLV_s16OutFilterIn =
         (sint16)MATHSRV_udtCLAMP(s16LocalOutFilterIn, -1024, 1023);
   }

   bLocalAcvLockPosnInVlv = GDGAR_bGetFRM(FRM_FRM_ACVLOCKPOSNINVLV);
   if (bLocalAcvLockPosnInVlv != 0)
   {
      u8LocalCkOpInVlvReqRef0 = (uint8)(VlvSys_agCkOpInVlvReqRef0Max_C + 128);
   }
   else
   {
      bLocalAcvCurPosnRegInVlv = GDGAR_bGetFRM(FRM_FRM_ACVCURPOSNREGINVLV);
      if (bLocalAcvCurPosnRegInVlv != 0)
      {
         u16LocalCkOpInVlvReqRef0 = (uint16)( (OFSVLV_s16OutFilterIn + 1028)
                                            / 8);
         u8LocalCkOpInVlvReqRef0 =
            (uint8)MATHSRV_udtMIN(u16LocalCkOpInVlvReqRef0, 255);
      }
      else
      {
         u8LocalCkOpInVlvReqRef0 = u8LocalVlvSys_agCkOpInVlvAcvCorR;
      }
   }
   VEMS_vidSET(VlvSys_agCkOpInVlvReqRef0, u8LocalCkOpInVlvReqRef0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OFSVLV_vidPanneEchappement                                 */
/* !Description :  Elle  détermine les consignes VVT échappement après prise  */
/*                 en compte des défauts possibles.                           */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_02164_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Ext_agCkClsExVlvEstimRef0;                                   */
/*  input uint8 VlvSys_agCkClsExVlvAcvCorReq;                                 */
/*  input uint16 VlvSys_nEng8_A[8];                                           */
/*  input uint16 VlvSys_rFilGainClsExVlv_T[8];                                */
/*  input sint32 OFSVLV_s32Filtre2Mem;                                        */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0Min_C;                              */
/*  input sint16 OFSVLV_s16OutFilterEx;                                       */
/*  output sint16 OFSVLV_s16OutFilterEx;                                      */
/*  output sint32 OFSVLV_s32Filtre2Mem;                                       */
/*  output uint8 VlvSys_agCkClsExVlvReqRef0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OFSVLV_vidPanneEchappement(void)
{
   /*F02_Echappement */
   boolean bLocalAcvLockPosnExVlv;
   boolean bLocalAcvCurPosnRegExVlv;
   uint8   u8LocalCkOpExVlvReqRef0;
   uint8   u8LocalVlvSys_agCkClsExVlvAcvCor;
   uint16  u16LocalExt_nEng;
   uint16  u16localInterp1d;
   uint16  u16LocalExtnEngParaX;
   uint16  u16localGain;
   uint16  u16LocalCkOpExVlvReqRef0;
   sint16  s16LocalCkClsExVlvEstimRef0;
   sint16  s16LocalOutFilterEx;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Ext_agCkClsExVlvEstimRef0, s16LocalCkClsExVlvEstimRef0);
   VEMS_vidGET(VlvSys_agCkClsExVlvAcvCorReq, u8LocalVlvSys_agCkClsExVlvAcvCor);

   u16LocalExtnEngParaX = MATHSRV_u16CalcParaIncAryU16(VlvSys_nEng8_A,
                                                       u16LocalExt_nEng,
                                                       8);
   u16localInterp1d =
      MATHSRV_u16Interp1d(VlvSys_rFilGainClsExVlv_T, u16LocalExtnEngParaX);
   /*Filter2*/
   if (u16localInterp1d == 0)
   {
      OFSVLV_s16OutFilterEx =
         (sint16)MATHSRV_udtCLAMP(s16LocalCkClsExVlvEstimRef0, -1024, 1023);
      OFSVLV_s32Filtre2Mem = (sint32)(s16LocalCkClsExVlvEstimRef0 * 65536);
   }
   else
   {
      u16localGain = (uint16)( (uint32)( VlvSys_tiSampleFast_SC
                                       * 65536)
                             / ( VlvSys_tiSampleFast_SC
                               + u16localInterp1d));
      s16LocalOutFilterEx =
         MATHSRV_s16FirstOrderFilterGu16(u16localGain,
                                        &OFSVLV_s32Filtre2Mem,
                                        s16LocalCkClsExVlvEstimRef0);
      OFSVLV_s16OutFilterEx =
         (sint16)MATHSRV_udtCLAMP(s16LocalOutFilterEx, -1024, 1023);
   }

   bLocalAcvLockPosnExVlv = GDGAR_bGetFRM(FRM_FRM_ACVLOCKPOSNEXVLV);
   if (bLocalAcvLockPosnExVlv != 0)
   {
      u8LocalCkOpExVlvReqRef0 = (uint8)(VlvSys_agCkClsExVlvReqRef0Min_C + 128);
   }
   else
   {
      bLocalAcvCurPosnRegExVlv = GDGAR_bGetFRM(FRM_FRM_ACVCURPOSNREGEXVLV);
      if (bLocalAcvCurPosnRegExVlv != 0)
      {
         u16LocalCkOpExVlvReqRef0 = (uint16)( (OFSVLV_s16OutFilterEx + 1028)
                                            / 8);
         u8LocalCkOpExVlvReqRef0 =
            (uint8) MATHSRV_udtMIN(u16LocalCkOpExVlvReqRef0, 255);
      }
      else
      {
         u8LocalCkOpExVlvReqRef0 = u8LocalVlvSys_agCkClsExVlvAcvCor;
      }
   }
   VEMS_vidSET(VlvSys_agCkClsExVlvReqRef0, u8LocalCkOpExVlvReqRef0);
}

/*------------------------------- end of file --------------------------------*/