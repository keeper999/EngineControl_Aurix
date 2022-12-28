/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXESTIM                                           */
/* !Description     : VLVACTEXESTIM component                                 */
/*                                                                            */
/* !Module          : VLVACTEXESTIM                                           */
/* !Description     : ESTIMATION DU DECALAGE AAC D’ECHAPPEMENT                */
/*                                                                            */
/* !File            : VLVACTEXESTIM_FCT1.C                                    */
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
/*   1 / VLVACTEXESTIM_vidInitOutput                                          */
/*   2 / VLVACTEXESTIM_vidExPosnEstimCmp                                      */
/*   3 / VLVACTEXESTIM_vidFilCmp                                              */
/*   4 / VLVACTEXESTIM_vidDeadZone                                            */
/*   5 / VLVACTEXESTIM_vidEstimGainCmp                                        */
/*   6 / VLVACTEXESTIM_vidKalmanFil                                           */
/*   7 / VLVACTEXESTIM_vidExPosnEstimUpd                                      */
/*   8 / VLVACTEXESTIM_vidExPosnEstimVar                                      */
/*                                                                            */
/* !Reference   : V02 NT 09 02851 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#063078                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXESTIM/VLVACTEXE$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   11 Oct 2012 $*/
/* $Author::   etsasson                               $$Date::   11 Oct 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXESTIM.h"
#include "VLVACTEXESTIM_L.h"
#include "VLVACTEXESTIM_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidInitOutput                                */
/* !Description :  Exitialisation of the component outputs                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 VlvAct_agCmExEstimVar;                                      */
/*  output uint16 VlvAct_agCmExMesVar;                                        */
/*  output uint16 VlvAct_agCmExPosnEstim;                                     */
/*  output sint16 VlvAct_agCmExSpdEstim;                                      */
/*  output uint16 VLVACTEXESTIM_u16RelExVvtMesPrev;                           */
/*  output uint16 VLVACTEXESTIM_u16agCmExEstimPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidInitOutput(void)
{
   VEMS_vidSET(VlvAct_agCmExEstimVar, 0);
   VEMS_vidSET(VlvAct_agCmExMesVar, 0);
   VEMS_vidSET(VlvAct_agCmExPosnEstim, 0);
   VEMS_vidSET(VlvAct_agCmExSpdEstim, 0);
   VLVACTEXESTIM_u16RelExVvtMesPrev = 0;
   VLVACTEXESTIM_u16agCmExEstimPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidExPosnEstimCmp                            */
/* !Description :  L’estimation temporelle du décalage AAC peut être inhibée  */
/*                 totalement ou partiellement                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_02851_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTEXESTIM_vidFilCmp();                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean Vcpe_learning_finished;                                     */
/*  input boolean VlvAct_bExPosnEstimInh_C;                                   */
/*  input uint8 VlvAct_nExPosnEstimEnaMax_C;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidExPosnEstimCmp(void)
{
   boolean bLocalFRM_bInhCmExEstim;
   boolean bLocalVcpe_learning_finished;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Vcpe_learning_finished, bLocalVcpe_learning_finished);

   bLocalFRM_bInhCmExEstim = GDGAR_bGetFRM(FRM_FRM_INHCMEXESTIM);

   if (  (bLocalVcpe_learning_finished != 0)
      && (bLocalFRM_bInhCmExEstim == 0)
      && (VlvAct_bExPosnEstimInh_C == 0)
      && (u16LocalExt_nEng < (VlvAct_nExPosnEstimEnaMax_C * 32)))
   {
      VLVACTEXESTIM_vidFilCmp();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidFilCmp                                    */
/* !Description :  Calculer la variation de l'estimation et de la mesure du   */
/*                 décalage AAC échappement..                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXESTIM_vidDeadZone();                             */
/*  extf argret void VLVACTEXESTIM_vidEstimGainCmp();                         */
/*  extf argret void VLVACTEXESTIM_vidKalmanFil();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidFilCmp(void)
{
   VLVACTEXESTIM_vidDeadZone();
   VLVACTEXESTIM_vidEstimGainCmp();
   VLVACTEXESTIM_vidKalmanFil();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidDeadZone                                  */
/* !Description :  Calcul de la consigne RCO de commande normalisée de la VVT */
/*                 échappement.                                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 VlvAct_ExMngStCmd;                                           */
/*  input boolean VlvAct_bExPosnEstimCmdOfsSel_C;                             */
/*  input uint16 Vcpe_integral_value;                                         */
/*  input uint16 VlvAct_ExPosnEstimCmdOfs_C;                                  */
/*  input uint8 VlvAct_ExPosnEstimCmdDb_C;                                    */
/*  output sint16 VlvAct_ExMngStCmdNorm;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidDeadZone(void)
{
   uint16  u16LocalVlvAct_ExMngStCmd;
   uint16  u16LocalVcpeIntegralValue;
   sint32  s32LocalCmd;
   uint32  u32LocalCmd;


   VEMS_vidGET(VlvAct_ExMngStCmd, u16LocalVlvAct_ExMngStCmd);
   u16LocalVlvAct_ExMngStCmd = (uint16)MATHSRV_udtMIN(u16LocalVlvAct_ExMngStCmd,
                                                      1023);
   if (VlvAct_bExPosnEstimCmdOfsSel_C != 0)
   {
      VEMS_vidGET(Vcpe_integral_value, u16LocalVcpeIntegralValue);
      s32LocalCmd = (sint32)( u16LocalVlvAct_ExMngStCmd
                            - ((u16LocalVcpeIntegralValue + 32) / 64));
   }
   else
   {
      s32LocalCmd = (sint32)( u16LocalVlvAct_ExMngStCmd
                            - VlvAct_ExPosnEstimCmdOfs_C);
   }

   u32LocalCmd = (uint32)MATHSRV_udtABS(s32LocalCmd);

   if ( u32LocalCmd > VlvAct_ExPosnEstimCmdDb_C)
   {
      VlvAct_ExMngStCmdNorm = (sint16)MATHSRV_udtMAX(s32LocalCmd, -1024);
   }
   else
   {
      VlvAct_ExMngStCmdNorm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidEstimGainCmp                              */
/* !Description :  Calcul du gain du dénominateur et du numérateur de la      */
/*                 fonction de transfert du modèle VVT échappement.           */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint8 VlvAct_nExPosnEstim_T[5];                                     */
/*  input uint8 VlvAct_tOilExPosnEstim_T[5];                                  */
/*  input uint8 VlvAct_ExPosnEstimInvTo_M[5][5];                              */
/*  input uint8 VlvAct_ExPosnEstimK_M[5][5];                                  */
/*  input uint8 VlvAct_ExPosnEstimGainA;                                      */
/*  output uint8 VlvAct_ExPosnEstimGainA;                                     */
/*  output uint16 VlvAct_ExPosnEstimGainB;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidEstimGainCmp(void)
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

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(VlvAct_nExPosnEstim_T,
                                               u8LocalExtnEng,
                                               5);

   s16LocalEng_tOilEstim = (sint16)((sint32)(s16LocalEng_tOilEstim + 200) / 4);
   u8LocalOilEstim = (uint8)MATHSRV_udtCLAMP(s16LocalEng_tOilEstim, 0, 255);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(VlvAct_tOilExPosnEstim_T,
                                               u8LocalOilEstim,
                                               5);

   VlvAct_ExPosnEstimGainA =
      MATHSRV_u8Interp2d(&VlvAct_ExPosnEstimInvTo_M[0][0],
                         u16LocalParaX,
                         u16LocalParaY,
                         5);

   u8LocalInPosnEstimK = MATHSRV_u8Interp2d(&VlvAct_ExPosnEstimK_M[0][0],
                                            u16LocalParaX,
                                            u16LocalParaY,
                                            5);

   VlvAct_ExPosnEstimGainB = (uint16)( u8LocalInPosnEstimK
                                     * VlvAct_ExPosnEstimGainA);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidKalmanFil                                 */
/* !Description :  Calcul de la Variable d'état position et d'état vitesse du */
/*                 filtre d'estimation du décalage AAC échapprment            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.JEDIDI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_ExPosnEstimSpd;                                       */
/*  input uint16 VlvAct_ExPosnEstimPosn;                                      */
/*  input uint8 VlvAct_ExPosnEstimMax_C;                                      */
/*  input uint8 VlvAct_ExPosnEstimMin_C;                                      */
/*  input sint16 VlvAct_ExMngStCmdNorm;                                       */
/*  input uint16 VlvAct_ExPosnEstimGainB;                                     */
/*  input uint8 VlvAct_ExPosnEstimGainA;                                      */
/*  output uint16 VlvAct_ExPosnEstimPosn;                                     */
/*  output uint16 VlvAct_agCmExPosnEstim;                                     */
/*  output sint16 VlvAct_ExPosnEstimSpd;                                      */
/*  output sint16 VlvAct_agCmExSpdEstim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidKalmanFil(void)
{
   uint16 u16LocalMax;
   uint16 u16LocalMin;
   uint32 u32LocalSpdB;
   sint32 s32LocalSpdA;
   sint32 s32LocalSpdB;
   sint32 s32LocalSpd;
   sint32 s32LocalPosn;


   s32LocalPosn = VlvAct_ExPosnEstimSpd * (sint16)VlvActEx_SampleTiFast_SC;

   if (s32LocalPosn > 0)
   {
      s32LocalPosn = (s32LocalPosn + 500) / 1000;
   }
   else
   {
      s32LocalPosn = (s32LocalPosn - 500) / 1000;
   }
   s32LocalPosn = s32LocalPosn + VlvAct_ExPosnEstimPosn;
   u16LocalMax = (uint16)(VlvAct_ExPosnEstimMax_C * 4);
   u16LocalMin = (uint16)(VlvAct_ExPosnEstimMin_C * 4);

   VlvAct_ExPosnEstimPosn = (uint16)MATHSRV_udtCLAMP(s32LocalPosn,
                                                     u16LocalMin,
                                                     u16LocalMax);

   VEMS_vidSET(VlvAct_agCmExPosnEstim, VlvAct_ExPosnEstimPosn);

   s32LocalSpdB = (sint32)(VlvAct_ExMngStCmdNorm * VlvAct_ExPosnEstimGainB);
   u32LocalSpdB = (uint32)MATHSRV_udtABS(s32LocalSpdB);

   if (u32LocalSpdB > (uint32)(2147483647 / VlvActEx_SampleTiFast_SC))
   {
      s32LocalSpdB = s32LocalSpdB / 10;
      s32LocalSpdB = (s32LocalSpdB * (sint32)VlvActEx_SampleTiFast_SC) / 96;
   }
   else
   {
      s32LocalSpdB = (s32LocalSpdB * (sint32)VlvActEx_SampleTiFast_SC) / 960;
   }

   s32LocalSpdA = VlvAct_ExPosnEstimSpd * VlvAct_ExPosnEstimGainA;
   s32LocalSpdA = (s32LocalSpdA * (sint32)VlvActEx_SampleTiFast_SC) / 1000;
   s32LocalSpd = s32LocalSpdB - s32LocalSpdA;
   s32LocalSpd = s32LocalSpd + VlvAct_ExPosnEstimSpd;

   if (  (  (s32LocalSpd > 0)
         && (s32LocalPosn >= u16LocalMax))
      || (  (s32LocalSpd < 0)
         && (s32LocalPosn <= u16LocalMin)))
   {
      VlvAct_ExPosnEstimSpd = 0;
   }
   else
   {
      VlvAct_ExPosnEstimSpd = (sint16)MATHSRV_udtCLAMP(s32LocalSpd,
                                                       -5333,
                                                       5333);
   }

   VEMS_vidSET(VlvAct_agCmExSpdEstim, VlvAct_ExPosnEstimSpd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidExPosnEstimUpd                            */
/* !Description :  La seconde variable d’état (variable du décalage) du filtre*/
/*                 estimateur est mise à jour à chaque évènement              */
/*                 d’acquisition.                                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_02851_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 VlvAct_ExPosnEstimPosn;                                      */
/*  input sint16 Vta_exhaust_filt_velocity;                                   */
/*  input sint16 VlvAct_ExPosnEstimSpd;                                       */
/*  output uint16 VLVACTEXESTIM_u16agCmExEstimPrev;                           */
/*  output uint16 VlvAct_ExPosnEstimPosn;                                     */
/*  output uint16 VlvAct_agCmExPosnEstim;                                     */
/*  output sint16 VlvAct_ExPosnEstimSpd;                                      */
/*  output sint16 VlvAct_agCmExSpdEstim;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidExPosnEstimUpd(void)
{
   uint16 u16LocalVxx_rel_ex_vvt_mes;
   uint16 u16LocalVlvAct_agCmExPosnEstim;
   sint16 s16LocalVta_exhaust_filt_velocity;


   VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   VLVACTEXESTIM_u16agCmExEstimPrev = u16LocalVlvAct_agCmExPosnEstim;
   VlvAct_ExPosnEstimPosn = (uint16)MATHSRV_udtMIN(u16LocalVxx_rel_ex_vvt_mes,
                                                   1066);

   VEMS_vidSET(VlvAct_agCmExPosnEstim, VlvAct_ExPosnEstimPosn);

   VEMS_vidGET(Vta_exhaust_filt_velocity, s16LocalVta_exhaust_filt_velocity);
   VlvAct_ExPosnEstimSpd =
      (sint16)MATHSRV_udtCLAMP(s16LocalVta_exhaust_filt_velocity, -5333, 5333);
   VEMS_vidSET(VlvAct_agCmExSpdEstim, VlvAct_ExPosnEstimSpd);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Function    :  VLVACTEXESTIM_vidExPosnEstimVar                            */
/* !Description :  Après chaque mesure du décalage AAC échappement, on calcule*/
/*                 les variations suivantes, qui donnent une indication sur la*/
/*                 précision et le comportement du filtre estimateur par      */
/*                 rapport à la simple mesure.                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.JEDIDI                                                   */
/* !Trace_To    :  VEMS_R_09_02851_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Vxx_rel_ex_vvt_mes;                                          */
/*  input uint16 VLVACTEXESTIM_u16agCmExEstimPrev;                            */
/*  input uint16 VLVACTEXESTIM_u16RelExVvtMesPrev;                            */
/*  output uint16 VlvAct_agCmExEstimVar;                                      */
/*  output uint16 VlvAct_agCmExMesVar;                                        */
/*  output uint16 VLVACTEXESTIM_u16RelExVvtMesPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
void VLVACTEXESTIM_vidExPosnEstimVar(void)
{
   uint16 u16LocalCmInEstimVar;
   uint16 u16LocalVxx_rel_ex_vvt_mes;
   sint32 s32LocalEstimVar;


   VEMS_vidGET(Vxx_rel_ex_vvt_mes, u16LocalVxx_rel_ex_vvt_mes);
   s32LocalEstimVar = (sint32)( u16LocalVxx_rel_ex_vvt_mes
                              - VLVACTEXESTIM_u16agCmExEstimPrev);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtABS(s32LocalEstimVar);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtMIN(u16LocalCmInEstimVar, 1066);
   VEMS_vidSET(VlvAct_agCmExEstimVar, u16LocalCmInEstimVar);

   s32LocalEstimVar = (sint32)( u16LocalVxx_rel_ex_vvt_mes
                              - VLVACTEXESTIM_u16RelExVvtMesPrev);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtABS(s32LocalEstimVar);
   u16LocalCmInEstimVar = (uint16)MATHSRV_udtMIN(u16LocalCmInEstimVar, 1066);
   VEMS_vidSET(VlvAct_agCmExMesVar, u16LocalCmInEstimVar);

   VLVACTEXESTIM_u16RelExVvtMesPrev = u16LocalVxx_rel_ex_vvt_mes;
}
/*------------------------------- end of file --------------------------------*/