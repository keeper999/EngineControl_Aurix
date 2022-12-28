/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IFAIRSYSIGSYS                                           */
/* !Description     : IFAIRSYSIGSYS Component                                 */
/*                                                                            */
/* !Module          : IFAIRSYSIGSYS                                           */
/* !Description     : SPECIFICATION D’INTERFACE ENTRE LES MODULES PROJET      */
/*                    EBX-DT ET LES CHAINES GENERIQUES                        */
/*                                                                            */
/* !File            : IFAIRSYSIGSYS_FCT4.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidTqSys_2                                             */
/*   2 / IFAIRSYSIGSYS_vidmFuSpIf                                             */
/*   3 / IFAIRSYSIGSYS_vidInterfacCstrIf1                                     */
/*   4 / IFAIRSYSIGSYS_vidOutputpAC                                           */
/*   5 / IFAIRSYSIGSYS_vidOutputFHCanF572                                     */
/*   6 / IFAIRSYSIGSYS_vidIntfacIsCanIf14                                     */
/*   7 / IFAIRSYSIGSYS_vidIntfacIsCanIf15                                     */
/*   8 / IFAIRSYSIGSYS_vidIntfacIsCanIf16                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5076182 / 16                                        */
/* !OtherRefs   : VEMS V02 ECU#066287                                         */
/* !OtherRefs   : VEMS V02 ECU#066286                                         */
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
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "IFAIRSYSIGSYS.h"
#include "IFAIRSYSIGSYS_L.h"
#include "IFAIRSYSIGSYS_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidTqSys_2                                   */
/* !Description :  Cette fonction permet la production de la variable         */
/*                 EngLim_tqIdcRed.                                           */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqIdcRed;                                             */
/*  output sint16 EngLim_tqIdcSyst;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidTqSys_2(void)
{
   /*F06_EngLim */
   sint16 s16LocalEngLim_tqIdcRed;


   VEMS_vidGET(EngLim_tqIdcRed, s16LocalEngLim_tqIdcRed);
   s16LocalEngLim_tqIdcRed =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqIdcRed, -32000, 32000);
   VEMS_vidSET(EngLim_tqIdcSyst, s16LocalEngLim_tqIdcRed);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidmFuSpIf                                   */
/* !Description :  Moniteur rapide pour la correction de richesse de la       */
/*                 régulation richesse                                        */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback;                                             */
/*  output uint16 AFReg_facCorRichPrec;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidmFuSpIf(void)
{
   /*f2_interfacing_mFuSpIf*/
   sint16  s16LocalLambda_feedback;
   uint16  u16LocalAFReg_facCorRichPrec;


   VEMS_vidGET(Lambda_feedback, s16LocalLambda_feedback);
   u16LocalAFReg_facCorRichPrec =
      (uint16)((s16LocalLambda_feedback / 4 ) + 32768);
   VEMS_vidSET(AFReg_facCorRichPrec, u16LocalAFReg_facCorRichPrec);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInterfacCstrIf1                           */
/* !Description :  Interface function for CoPTSt_stEngNew                     */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 CoPTStNew_stEng;                                              */
/*  output uint8 CoPTSt_stEngNew;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInterfacCstrIf1(void)
{
   /*f1_interfacing_CstrIf*/
   uint8 u8LocalCoPTStNew_stEng;
   uint8 u8LocalCoPTSt_stEngNew;


   VEMS_vidGET(CoPTStNew_stEng, u8LocalCoPTStNew_stEng);
   switch (u8LocalCoPTStNew_stEng)
   {
      case 1:
         u8LocalCoPTSt_stEngNew = CoPTSt_stStop_SC;
         break;

      case 2:
         u8LocalCoPTSt_stEngNew = CoPTSt_stResv_SC;
         break;

      case 3:
         u8LocalCoPTSt_stEngNew = CoPTSt_stFirstStrt_SC;
         break;

      case 4:
         u8LocalCoPTSt_stEngNew = CoPTSt_stResv_SC;
         break;

      case 5:
         u8LocalCoPTSt_stEngNew = CoPTSt_stEngRun_SC;
         break;

      case 6:
         u8LocalCoPTSt_stEngNew = CoPTSt_stStopSTT_SC;
         break;

      case 7:
         u8LocalCoPTSt_stEngNew = CoPTSt_stRstrt_SC;
         break;

      case 8:
         u8LocalCoPTSt_stEngNew = CoPTSt_stStall_SC;
         break;

      case 9:
         u8LocalCoPTSt_stEngNew = CoPTSt_stEndStall_SC;
         break;

      default:
         u8LocalCoPTSt_stEngNew = CoPTSt_stEndStall_SC;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   VEMS_vidSET(CoPTSt_stEngNew, u8LocalCoPTSt_stEngNew);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputpAC                                 */
/* !Description :  Cette fonction permet la production de la variable         */
/*                 EngLim_tqIdcRed.                                           */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Cl_pressure;                                                 */
/*  output uint16 Ext_pAC;                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputpAC(void)
{
   /*F02_Output_pAC */
   uint16 u16LocalCl_pressure;


   VEMS_vidGET(Cl_pressure, u16LocalCl_pressure);
   u16LocalCl_pressure = (uint16)((u16LocalCl_pressure * 16) / 25);
   u16LocalCl_pressure =
      (uint16)MATHSRV_udtMIN(u16LocalCl_pressure, 30999);
   VEMS_vidSET(Ext_pAC, u16LocalCl_pressure);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidOutputFHCanF572                           */
/* !Description :  Permet de calculer le  paramètre PM1375 à travers les      */
/*                 Données brutes du paramètre PM1446, reçue du CAN.          */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean ISCAN_bF572PM1446;                                          */
/*  output boolean ISCAN_bF572PM1375;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidOutputFHCanF572(void)
{
   /* F06_Output_FHCanF572If */
   boolean  bLocalISCAN_bF572PM1446;

   VEMS_vidGET(ISCAN_bF572PM1446, bLocalISCAN_bF572PM1446);
   VEMS_vidSET(ISCAN_bF572PM1375, bLocalISCAN_bF572PM1446);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf14                           */
/* !Description :  Fonction appelé à la réception d'une trame CAN 30D         */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_spdLeFrntWhl;                                            */
/*  input uint16 Ext_spdRiFrntWhl;                                            */
/*  input uint16 Ext_spdLeReWhl;                                              */
/*  input uint16 Ext_spdRiReWhl;                                              */
/*  output uint16 Vitesse_vehicule_avg_mux;                                   */
/*  output uint16 Vitesse_vehicule_avd_mux;                                   */
/*  output uint16 Vitesse_vehicule_arg_mux;                                   */
/*  output uint16 Vitesse_vehicule_ard_mux;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf14(void)
{
   /*f14_interfacing_IsCanIf*/
   uint16  u16LocalVitesse_vehicule_avg_mux;
   uint16  u16LocalVitesse_vehicule_avd_mux;
   uint16  u16LocalVitesse_vehicule_arg_mux;
   uint16  u16LocalVitesse_vehicule_ard_mux;


   VEMS_vidGET(Ext_spdLeFrntWhl, u16LocalVitesse_vehicule_avg_mux);
   VEMS_vidGET(Ext_spdRiFrntWhl, u16LocalVitesse_vehicule_avd_mux);
   VEMS_vidGET(Ext_spdLeReWhl, u16LocalVitesse_vehicule_arg_mux);
   VEMS_vidGET(Ext_spdRiReWhl, u16LocalVitesse_vehicule_ard_mux);

   u16LocalVitesse_vehicule_avg_mux =
      (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_avg_mux, 65533);
   u16LocalVitesse_vehicule_avd_mux =
      (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_avd_mux, 65533);
   u16LocalVitesse_vehicule_arg_mux =
      (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_arg_mux, 65533);
   u16LocalVitesse_vehicule_ard_mux =
      (uint16)MATHSRV_udtMIN(u16LocalVitesse_vehicule_ard_mux, 65533);

   VEMS_vidSET(Vitesse_vehicule_avg_mux, u16LocalVitesse_vehicule_avg_mux);
   VEMS_vidSET(Vitesse_vehicule_avd_mux, u16LocalVitesse_vehicule_avd_mux);
   VEMS_vidSET(Vitesse_vehicule_arg_mux, u16LocalVitesse_vehicule_arg_mux);
   VEMS_vidSET(Vitesse_vehicule_ard_mux, u16LocalVitesse_vehicule_ard_mux);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf15                           */
/* !Description :  Fonction appelé à la réception d'une trame CAN 38D         */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_spdEspVeh;                                               */
/*  input sint16 Ext_aVeh;                                                    */
/*  output uint16 Vitesse_vehicule_mux;                                       */
/*  output uint8 Acceleration_vehicule_mux;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf15(void)
{
   /*f15_interfacing_IsCanIf */
   uint8  u8LocalAcceleration_vehicule_mux;
   uint16 u16LocalExt_spdEspVeh;
   sint16 s16LocalExt_aVeh;
   sint32 s32LocalAccelerationVehiculeMux;


   VEMS_vidGET(Ext_spdEspVeh, u16LocalExt_spdEspVeh);
   VEMS_vidGET(Ext_aVeh, s16LocalExt_aVeh);

   s32LocalAccelerationVehiculeMux = (sint32)(s16LocalExt_aVeh + 175);
   u8LocalAcceleration_vehicule_mux =
      (uint8)MATHSRV_udtCLAMP(s32LocalAccelerationVehiculeMux, 0, 255);
   u16LocalExt_spdEspVeh = (uint16)MATHSRV_udtMIN(u16LocalExt_spdEspVeh, 65534);

   VEMS_vidSET(Vitesse_vehicule_mux, u16LocalExt_spdEspVeh);
   VEMS_vidSET(Acceleration_vehicule_mux, u8LocalAcceleration_vehicule_mux);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidIntfacIsCanIf16                           */
/* !Description :  Fonction appelé à la réception d'une trame CAN 50E         */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_spdVehVSLimReq;                                           */
/*  input uint8 Ext_spdVehVSRegReq;                                           */
/*  output uint8 Ext_spdVehReqVSLim;                                          */
/*  output uint8 Ext_spdVehReqVSReg;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidIntfacIsCanIf16(void)
{
   /*f16_interfacing_IsCanIf */
   uint8 u8LocalExt_spdVehVSLimReq;
   uint8 u8LocalExt_spdVehVSRegReq;


   VEMS_vidGET(Ext_spdVehVSLimReq, u8LocalExt_spdVehVSLimReq);
   VEMS_vidSET(Ext_spdVehReqVSLim, u8LocalExt_spdVehVSLimReq);
   VEMS_vidGET(Ext_spdVehVSRegReq, u8LocalExt_spdVehVSRegReq);
   VEMS_vidSET(Ext_spdVehReqVSReg, u8LocalExt_spdVehVSRegReq);
}
/*-------------------------------- end of file -------------------------------*/