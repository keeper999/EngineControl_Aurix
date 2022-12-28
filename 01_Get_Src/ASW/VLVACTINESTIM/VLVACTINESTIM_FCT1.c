/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINESTIM                                           */
/* !Description     : VLVACTINESTIM component                                 */
/*                                                                            */
/* !Module          : VLVACTINESTIM                                           */
/* !Description     : ESTIMATION DU DECALAGE AAC D’ADMISSION                  */
/*                                                                            */
/* !File            : VLVACTINESTIM_FCT1.C                                    */
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
/*   1 / VLVACTINESTIM_vidInitOutput                                          */
/*   2 / VLVACTINESTIM_vidInPosnEstimCmp                                      */
/*   3 / VLVACTINESTIM_vidFilCmp                                              */
/*   4 / VLVACTINESTIM_vidDeadZone                                            */
/*   5 / VLVACTINESTIM_vidEstimGainCmp                                        */
/*   6 / VLVACTINESTIM_vidKalmanFil                                           */
/*   7 / VLVACTINESTIM_vidInPosnEstimUpd                                      */
/*   8 / VLVACTINESTIM_vidInPosnEstimVar                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 01756 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#063078                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINESTIM/VLVACTINE$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   11 Oct 2012 $*/

/* $Author::   etsasson                               $$Date::   11 Oct 2012 $*/

/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINESTIM.h"
#include "VLVACTINESTIM_L.h"
#include "VLVACTINESTIM_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidInitOutput                                */
/* !Description :  Initialisation of the component outputs                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvAct_agCmInEstimVar;                                      */
/*  output uint16 VlvAct_agCmInMesVar;                                        */
/*  output uint16 VlvAct_agCmInPosnEstim;                                     */
/*  output sint16 VlvAct_agCmInSpdEstim;                                      */
/*  output uint16 VLVACTINESTIM_u16RelInVvtMesPrev;                           */
/*  output uint16 VLVACTINESTIM_u16agCmInEstimPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidInitOutput(void)
{
   VEMS_vidSET(VlvAct_agCmInEstimVar, 0);
   VEMS_vidSET(VlvAct_agCmInMesVar, 0);
   VEMS_vidSET(VlvAct_agCmInPosnEstim, 0);
   VEMS_vidSET(VlvAct_agCmInSpdEstim, 0);
   VLVACTINESTIM_u16RelInVvtMesPrev = 0;
   VLVACTINESTIM_u16agCmInEstimPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidInPosnEstimCmp                            */
/* !Description :  L’estimation temporelle du décalage AAC peut être inhibée  */
/*                 totalement ou partiellement                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_01756_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTINESTIM_vidFilCmp();                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Vcpi_learning_finished;                                     */
/*  input boolean VlvAct_bInPosnEstimInh_C;                                   */
/*  input uint8 VlvAct_nInPosnEstimEnaMax_C;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidInPosnEstimCmp(void)
{
   boolean bLocalInhCmInEstim;
   boolean bLocalVcpi_learning_finished;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Vcpi_learning_finished, bLocalVcpi_learning_finished );

   bLocalInhCmInEstim = GDGAR_bGetFRM(FRM_FRM_INHCMINESTIM);

   if (  (bLocalVcpi_learning_finished != 0)
      && (bLocalInhCmInEstim == 0)
      && (VlvAct_bInPosnEstimInh_C == 0)
      && (u16LocalExt_nEng < (VlvAct_nInPosnEstimEnaMax_C * 32)))
   {
      VLVACTINESTIM_vidFilCmp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidFilCmp                                    */
/* !Description :  Calculer la variation de l'estimation et de la mesure du   */
/*                 décalage AAC admisson.                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINESTIM_vidDeadZone();                             */
/*  extf argret void VLVACTINESTIM_vidEstimGainCmp();                         */
/*  extf argret void VLVACTINESTIM_vidKalmanFil();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidFilCmp(void)
{
   VLVACTINESTIM_vidDeadZone();
   VLVACTINESTIM_vidEstimGainCmp();
   VLVACTINESTIM_vidKalmanFil();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidDeadZone                                  */
/* !Description :  Calcul de la consigne RCO de commande normalisée de la VVT */
/*                 admission                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_InMngStCmd;                                           */
/*  input boolean VlvAct_bInPosnEstimCmdOfsSel_C;                             */
/*  input uint16 Vcpi_integral_value;                                         */
/*  input uint16 VlvAct_InPosnEstimCmdOfs_C;                                  */
/*  input uint8 VlvAct_InPosnEstimCmdDb_C;                                    */
/*  output sint16 VlvAct_InMngStCmdNorm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidDeadZone(void)
{
   uint16  u16LocalVlvAct_InMngStCmd;
   uint16  u16LocalVcpiIntegralValue;
   uint32  u32LocalCmd;
   sint32  s32LocalCmd;


   VEMS_vidGET(VlvAct_InMngStCmd, u16LocalVlvAct_InMngStCmd);
   u16LocalVlvAct_InMngStCmd = (uint16)MATHSRV_udtMIN(u16LocalVlvAct_InMngStCmd,
                                                      1023);
   if (VlvAct_bInPosnEstimCmdOfsSel_C != 0)
   {
      VEMS_vidGET(Vcpi_integral_value, u16LocalVcpiIntegralValue);
      s32LocalCmd = (sint32)( u16LocalVlvAct_InMngStCmd
                            - ((u16LocalVcpiIntegralValue + 32) / 64));
   }
   else
   {
      s32LocalCmd = (sint32)( u16LocalVlvAct_InMngStCmd
                            - VlvAct_InPosnEstimCmdOfs_C);
   }
   u32LocalCmd = (uint32)MATHSRV_udtABS(s32LocalCmd);

   if ( u32LocalCmd > VlvAct_InPosnEstimCmdDb_C)
   {
      VlvAct_InMngStCmdNorm = (sint16)MATHSRV_udtMAX(s32LocalCmd, -1024);
   }
   else
   {
      VlvAct_InMngStCmdNorm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidEstimGainCmp                              */
/* !Description :  Calcul du gain du dénominateur et du numérateur de la      */
/*                 fonction de transfert du modèle VVT admission              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint8 VlvAct_nInPosnEstim_T[5];                                     */
/*  input uint8 VlvAct_tOilInPosnEstim_T[5];                                  */
/*  input uint8 VlvAct_InPosnEstimInvTo_M[5][5];                              */
/*  input uint8 VlvAct_InPosnEstimK_M[5][5];                                  */
/*  input uint8 VlvAct_InPosnEstimGainA;                                      */
/*  output uint8 VlvAct_InPosnEstimGainA;                                     */
/*  output uint16 VlvAct_InPosnEstimGainB;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidEstimGainCmp(void)
{
   uint8  u8LocalExtnEng;
   uint8  u8LocalOilEstim;
   uint8  u8LocalInPosnEstimK;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalExt_nEng;
   sint16 s16LocalEng_tOilEstim;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);

   u16LocalExt_nEng = (uint16)(u16LocalExt_nEng / 32);
   u8LocalExtnEng = (uint8)MATHSRV_udtMIN(u16LocalExt_nEng, 255);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(VlvAct_nInPosnEstim_T,
                                               u8LocalExtnEng,
                                               5);

   s16LocalEng_tOilEstim = (sint16)((sint32)(s16LocalEng_tOilEstim + 200) / 4);
   u8LocalOilEstim = (uint8)MATHSRV_udtCLAMP(s16LocalEng_tOilEstim, 0, 255);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(VlvAct_tOilInPosnEstim_T,
                                               u8LocalOilEstim,
                                               5);

   VlvAct_InPosnEstimGainA =
      MATHSRV_u8Interp2d(&VlvAct_InPosnEstimInvTo_M[0][0],
                         u16LocalParaX,
                         u16LocalParaY,
                         5);

   u8LocalInPosnEstimK = MATHSRV_u8Interp2d(&VlvAct_InPosnEstimK_M[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            5);

   VlvAct_InPosnEstimGainB = (uint16)( u8LocalInPosnEstimK
                                     * VlvAct_InPosnEstimGainA);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidKalmanFil                                 */
/* !Description :  Calcul de la Variable d'état position et d'état vitesse du */
/*                 filtre d'estimation du décalage AAC admission              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_InPosnEstimSpd;                                       */
/*  input uint16 VlvAct_InPosnEstimPosn;                                      */
/*  input uint8 VlvAct_InPosnEstimMax_C;                                      */
/*  input uint8 VlvAct_InPosnEstimMin_C;                                      */
/*  input sint16 VlvAct_InMngStCmdNorm;                                       */
/*  input uint16 VlvAct_InPosnEstimGainB;                                     */
/*  input uint8 VlvAct_InPosnEstimGainA;                                      */
/*  output uint16 VlvAct_InPosnEstimPosn;                                     */
/*  output uint16 VlvAct_agCmInPosnEstim;                                     */
/*  output sint16 VlvAct_InPosnEstimSpd;                                      */
/*  output sint16 VlvAct_agCmInSpdEstim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidKalmanFil(void)
{
   uint16 u16LocalMax;
   uint16 u16LocalMin;
   uint32 u32LocalSpdB;
   sint32 s32LocalSpdA;
   sint32 s32LocalSpdB;
   sint32 s32LocalSpd;
   sint32 s32LocalPosn;


   s32LocalPosn = VlvAct_InPosnEstimSpd * (sint16)VlvActIn_SampleTiFast_SC;

   if (s32LocalPosn > 0)
   {
      s32LocalPosn = (s32LocalPosn + 500) / 1000;
   }
   else
   {
      s32LocalPosn = (s32LocalPosn - 500) / 1000;
   }
   s32LocalPosn = s32LocalPosn + VlvAct_InPosnEstimPosn;
   u16LocalMax = (uint16)(VlvAct_InPosnEstimMax_C * 4);
   u16LocalMin = (uint16)(VlvAct_InPosnEstimMin_C * 4);

   VlvAct_InPosnEstimPosn = (uint16)MATHSRV_udtCLAMP(s32LocalPosn,
                                                     u16LocalMin,
                                                     u16LocalMax);

   VEMS_vidSET(VlvAct_agCmInPosnEstim, VlvAct_InPosnEstimPosn);

   s32LocalSpdB = (sint32)(VlvAct_InMngStCmdNorm * VlvAct_InPosnEstimGainB);
   u32LocalSpdB = (uint32)MATHSRV_udtABS(s32LocalSpdB);

   if (u32LocalSpdB > (uint32)(2147483647 / VlvActIn_SampleTiFast_SC))
   {
      s32LocalSpdB = s32LocalSpdB / 10;
      s32LocalSpdB = (s32LocalSpdB * (sint32)VlvActIn_SampleTiFast_SC) / 96;
   }
   else
   {
      s32LocalSpdB = (s32LocalSpdB * (sint32)VlvActIn_SampleTiFast_SC) / 960;
   }

   s32LocalSpdA = VlvAct_InPosnEstimSpd * VlvAct_InPosnEstimGainA;
   s32LocalSpdA = (s32LocalSpdA * (sint32)VlvActIn_SampleTiFast_SC) / 1000;
   s32LocalSpd = s32LocalSpdB - s32LocalSpdA;
   s32LocalSpd = s32LocalSpd + VlvAct_InPosnEstimSpd;

   if (  (  (s32LocalSpd > 0)
         && (s32LocalPosn >= u16LocalMax))
      || (  (s32LocalSpd < 0)
         && (s32LocalPosn <= u16LocalMin)))
   {
      VlvAct_InPosnEstimSpd = 0;
   }
   else
   {
      VlvAct_InPosnEstimSpd = (sint16)MATHSRV_udtCLAMP(s32LocalSpd,
                                                       -5333,
                                                       5333);
   }

   VEMS_vidSET(VlvAct_agCmInSpdEstim, VlvAct_InPosnEstimSpd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidInPosnEstimUpd                            */
/* !Description :  La seconde variable d’état (variable du décalage) du filtre*/
/*                 estimateur est mise à jour à chaque évènement              */
/*                 d’acquisition.                                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_01756_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint16 VlvAct_InPosnEstimPosn;                                      */
/*  input sint16 Vta_intake_filt_velocity;                                    */
/*  input sint16 VlvAct_InPosnEstimSpd;                                       */
/*  output uint16 VLVACTINESTIM_u16agCmInEstimPrev;                           */
/*  output uint16 VlvAct_InPosnEstimPosn;                                     */
/*  output uint16 VlvAct_agCmInPosnEstim;                                     */
/*  output sint16 VlvAct_InPosnEstimSpd;                                      */
/*  output sint16 VlvAct_agCmInSpdEstim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidInPosnEstimUpd(void)
{
   uint16 u16LocalVxx_rel_in_vvt_mes;
   uint16 u16LocalVlvAct_agCmInPosnEstim;
   sint16 s16LocalVta_intake_filt_velocity;


   VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalVlvAct_agCmInPosnEstim);
   VLVACTINESTIM_u16agCmInEstimPrev = u16LocalVlvAct_agCmInPosnEstim;
   VlvAct_InPosnEstimPosn = (uint16)MATHSRV_udtMIN(u16LocalVxx_rel_in_vvt_mes,
                                                   1066);

   VEMS_vidSET(VlvAct_agCmInPosnEstim, VlvAct_InPosnEstimPosn);

   VEMS_vidGET(Vta_intake_filt_velocity, s16LocalVta_intake_filt_velocity);
   VlvAct_InPosnEstimSpd =
      (sint16)MATHSRV_udtCLAMP(s16LocalVta_intake_filt_velocity, -5333, 5333);
   VEMS_vidSET(VlvAct_agCmInSpdEstim, VlvAct_InPosnEstimSpd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINESTIM_vidInPosnEstimVar                            */
/* !Description :  Après chaque mesure du décalage AAC admission, on calcule  */
/*                 les variations suivantes, qui donnent une indication sur la*/
/*                 précision et le comportement du filtre estimateur par      */
/*                 rapport à la simple mesure.                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_01756_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vxx_rel_in_vvt_mes;                                          */
/*  input uint16 VLVACTINESTIM_u16agCmInEstimPrev;                            */
/*  input uint16 VLVACTINESTIM_u16RelInVvtMesPrev;                            */
/*  output uint16 VlvAct_agCmInEstimVar;                                      */
/*  output uint16 VlvAct_agCmInMesVar;                                        */
/*  output uint16 VLVACTINESTIM_u16RelInVvtMesPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINESTIM_vidInPosnEstimVar(void)
{
   uint16 u16LocalCmInEstimVar;
   uint16 u16LocalVxx_rel_in_vvt_mes;
   sint32 s32LocalEstimVar;


   VEMS_vidGET(Vxx_rel_in_vvt_mes, u16LocalVxx_rel_in_vvt_mes);
   s32LocalEstimVar = (sint32)( u16LocalVxx_rel_in_vvt_mes
                              - VLVACTINESTIM_u16agCmInEstimPrev);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtABS(s32LocalEstimVar);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtMIN(u16LocalCmInEstimVar, 1066);
   VEMS_vidSET(VlvAct_agCmInEstimVar, u16LocalCmInEstimVar);

   s32LocalEstimVar = (sint32)( u16LocalVxx_rel_in_vvt_mes
                              - VLVACTINESTIM_u16RelInVvtMesPrev);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtABS(s32LocalEstimVar);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtMIN(u16LocalCmInEstimVar, 1066);
   VEMS_vidSET(VlvAct_agCmInMesVar, u16LocalCmInEstimVar);

   VLVACTINESTIM_u16RelInVvtMesPrev = u16LocalVxx_rel_in_vvt_mes;
}
/*------------------------------- end of file --------------------------------*/