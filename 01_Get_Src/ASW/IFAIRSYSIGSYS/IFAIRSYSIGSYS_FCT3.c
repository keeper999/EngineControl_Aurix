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
/* !File            : IFAIRSYSIGSYS_FCT3.C                                    */
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
/*   1 / IFAIRSYSIGSYS_vidInjCtlIf2                                           */
/*   2 / IFAIRSYSIGSYS_vidInjCtlIf3                                           */
/*   3 / IFAIRSYSIGSYS_vidInputVlvActExIf                                     */
/*   4 / IFAIRSYSIGSYS_vidInputVlvActInIf                                     */
/*   5 / IFAIRSYSIGSYS_vidCkMngIf                                             */
/*   6 / IFAIRSYSIGSYS_vidBattVolt                                            */
/*   7 / IFAIRSYSIGSYS_vidDsLsAcqIf                                           */
/*   8 / IFAIRSYSIGSYS_vidEndDiagDsHeat                                       */
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

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInjCtlIf2                                 */
/* !Description :  Fonction d'interfaçage.                                    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Lambda_feedback_filtered;                                    */
/*  input boolean Lambda_closed_loop;                                         */
/*  input uint8 Lambda_filtered_fdbk_mode_delay;                              */
/*  output sint32 InjSys_lamFbFil;                                            */
/*  output boolean InjSys_bAcvFuCll;                                          */
/*  output uint8 InjSys_noTDCDlyLsclFilMod;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInjCtlIf2(void)
{
   /*F09_InjCtlIf2 */
   boolean bLocalLambda_closed_loop;
   uint8   u8LocalLambda_filt_fdbk_mde_dly;
   sint16  s16LocalLambda_feedback_filtered;
   sint32  s32LocalInjSys_lamFbFil;


   VEMS_vidGET(Lambda_feedback_filtered, s16LocalLambda_feedback_filtered);

   s32LocalInjSys_lamFbFil = s16LocalLambda_feedback_filtered;

   VEMS_vidSET(InjSys_lamFbFil, s32LocalInjSys_lamFbFil);

   VEMS_vidGET(Lambda_closed_loop, bLocalLambda_closed_loop);
   VEMS_vidSET(InjSys_bAcvFuCll, bLocalLambda_closed_loop);

   VEMS_vidGET(Lambda_filtered_fdbk_mode_delay,
               u8LocalLambda_filt_fdbk_mde_dly);
   VEMS_vidSET(InjSys_noTDCDlyLsclFilMod, u8LocalLambda_filt_fdbk_mde_dly);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInjCtlIf3                                 */
/* !Description :  Fonction d'interaçage.                                     */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Lambda_filtered_fdbk_mode_delay;                              */
/*  output uint8 InjSys_noTDCDlyLsclFilMod;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInjCtlIf3(void)
{
   /*F10_InjCtlIf3*/
   uint8   u8LocalLambda_filt_fdbk_mode_dly;


   VEMS_vidGET(Lambda_filtered_fdbk_mode_delay,
               u8LocalLambda_filt_fdbk_mode_dly);
   VEMS_vidSET(InjSys_noTDCDlyLsclFilMod, u8LocalLambda_filt_fdbk_mode_dly);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInputVlvActExIf                           */
/* !Description :  Fonction qui permet la production de la variable           */
/*                 VlvSys_agCkClsExVlvCorRaw (interfacé avec                  */
/*                 VlvSys_agCkClsExVlvReqRef0)                                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VlvSys_agCkClsExVlvReqRef0;                                   */
/*  output uint8 VlvSys_agCkClsExVlvCorRaw;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInputVlvActExIf(void)
{
   /*F02_Input_VlvActExIf */
   uint8 u8LocalVlvSysAgCkClsExVlvReqRef0;


   VEMS_vidGET(VlvSys_agCkClsExVlvReqRef0, u8LocalVlvSysAgCkClsExVlvReqRef0);
   VEMS_vidSET(VlvSys_agCkClsExVlvCorRaw, u8LocalVlvSysAgCkClsExVlvReqRef0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidInputVlvActInIf                           */
/* !Description :  Fonction qui permet la production de la varaible           */
/*                 VlvSys_agCkOpInVlvCorRaw (interfacé avec                   */
/*                 VlvSys_agCkOpInVlvReqRef0)                                 */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VlvSys_agCkOpInVlvReqRef0;                                    */
/*  output uint8 VlvSys_agCkOpInVlvCorRaw;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidInputVlvActInIf(void)
{
   /*F03_Input_VlvActInIf */
   uint8 u8LocalVlvSys_agCkOpInVlvReqRef0;


   VEMS_vidGET(VlvSys_agCkOpInVlvReqRef0, u8LocalVlvSys_agCkOpInVlvReqRef0);
   VEMS_vidSET(VlvSys_agCkOpInVlvCorRaw, u8LocalVlvSys_agCkOpInVlvReqRef0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidCkMngIf                                   */
/* !Description :  Interface function for Duree_dent and Moteur_tournant      */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Moteur_tournant;                                            */
/*  input uint16 Duree_dent;                                                  */
/*  output boolean Ext_bRun;                                                  */
/*  output uint16 Ext_tiToothLen;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidCkMngIf(void)
{
   /*F02_CkMngIf */
   boolean bLocalMoteur_tournant;
   uint16  u16LocalDuree_dent;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   VEMS_vidGET(Duree_dent, u16LocalDuree_dent);

   VEMS_vidSET(Ext_bRun, bLocalMoteur_tournant);
   VEMS_vidSET(Ext_tiToothLen, u16LocalDuree_dent);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidBattVolt                                  */
/* !Description :  Interface function for Ext_uBattMes                        */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Ext_uBattMes;                                                */
/*  output uint16 Ext_uBatt;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidBattVolt(void)
{
   /*F03_BattVolt */
   sint16  s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   s16LocalExt_uBattMes =
      (sint16)((sint32)((s16LocalExt_uBattMes * 25) + 29) / 59);
   s16LocalExt_uBattMes = (sint16)(MATHSRV_udtMAX(s16LocalExt_uBattMes, 0));
   VEMS_vidSET(Ext_uBatt, (uint16)s16LocalExt_uBattMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidDsLsAcqIf                                 */
/* !Description :  Interface function for Ext_uLsDsMes                        */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Tension_sonde_aval;                                          */
/*  output uint8 Ext_uLsDsMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidDsLsAcqIf(void)
{
   /*F04_DsLsAcqIf */
   uint8  u8LocalExt_uLsDsMes;
   uint16 u16LocalTension_sonde_aval;
   uint32 u32LocalExt_uLsDsMes;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);

   u32LocalExt_uLsDsMes = (uint32)( ( ( u16LocalTension_sonde_aval
                                      * 625)
                                    + 256)
                                  / 512);
   u8LocalExt_uLsDsMes = (uint8)MATHSRV_udtMIN(u32LocalExt_uLsDsMes, 250);

   VEMS_vidSET(Ext_uLsDsMes, u8LocalExt_uLsDsMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IFAIRSYSIGSYS_vidEndDiagDsHeat                             */
/* !Description :  Ce block contient les entrées de la chaîne d’air issues des*/
/*                 modules projets EBx-DT.                                    */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean LsMon_bEndMonResHeatLsUs;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IFAIRSYSIGSYS_vidEndDiagDsHeat(void)
{
   /*f4_EndDiagDsHeat*/
   boolean bLocalEndDiagStrtORng_DsHeat;


   bLocalEndDiagStrtORng_DsHeat = GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);
   VEMS_vidSET(LsMon_bEndMonResHeatLsUs, bLocalEndDiagStrtORng_DsHeat);
}
/*-------------------------------- end of file -------------------------------*/