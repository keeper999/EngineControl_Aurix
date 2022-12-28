/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TRBWAPMP                                                */
/* !Description     : TRBWAPMP component.                                     */
/*                                                                            */
/* !Module          : TRBWAPMP                                                */
/* !Description     : WATER PUMP COMMAND AND DIAGNOSIS                        */
/*                                                                            */
/* !File            : TRBWAPMP_FCT1.C                                         */
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
/*   1 / TRBWAPMP_vidInit                                                     */
/*   2 / TRBWAPMP_vidInitOutput                                               */
/*   3 / TRBWAPMP_vidTreatment                                                */
/*   4 / TRBWAPMP_vidConversionInPercent                                      */
/*   5 / TRBWAPMP_vidCmdRCOCor                                                */
/*   6 / TRBWAPMP_vidDrvCmd                                                   */
/*   7 / TRBWAPMP_vidDiagnosis                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6851428 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TRBWAPMP/TRBWAPMP_FCT1.C_v      $*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   20 Oct 2014 $*/
/* $Author::   mbenfrad                               $$Date::   20 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include"STD_TYPES.h"
#include"MATHSRV.h"
#include"TRBWAPMP.h"
#include"TRBWAPMP_L.h"
#include"TRBWAPMP_IM.h"
#include"GDGAR.h"
#include"VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidInit                                           */
/* !Description :  Cette fonction donne les valeurs d'initialisation des      */
/*                 sorties.                                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HIND GHORBEL                                               */
/* !Trace_To    :  VEMS_R_11_02775_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq_Drv;                                */
/*  output uint16 Commande_water_pump_pwm_freq;                               */
/*  output uint16 Commande_water_pump_pwm_rco;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidInit(void)
{
   VEMS_vidSET(TrbCoSysHw_rCtlWaPmpReq_Drv, 0);
   VEMS_vidSET(Commande_water_pump_pwm_freq, 0);
   VEMS_vidSET(Commande_water_pump_pwm_rco, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidInitOutput                                     */
/* !Description :  fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  output sint16 TRBWAPMP_s16ExtuBattMesPrev;                                */
/*  output boolean TrbWaPmp_bTiInh_DiagEl;                                    */
/*  output boolean TRBWAPMP_bInitDiagnosisTimerPRev;                          */
/*  output uint8 TRBWAPMP_u8Timer;                                            */
/*  output boolean TrbCoSysHw_bDgoScp_TrbWaPmp;                               */
/*  output boolean TrbCoSysHw_bDgoScg_TrbWaPmp;                               */
/*  output boolean TrbCoSysHw_bDgoOc_TrbWaPmp;                                */
/*  output boolean TrbCoSysHw_bMonRunOc_TrbWaPmp;                             */
/*  output boolean TrbCoSysHw_bMonRunScg_TrbWaPmp;                            */
/*  output boolean TrbCoSysHw_bMonRunScp_TrbWaPmp;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidInitOutput(void)
{
   sint16 s16LocalExt_uBattMes;


   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   TRBWAPMP_s16ExtuBattMesPrev =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
   TrbWaPmp_bTiInh_DiagEl = 0;
   TRBWAPMP_bInitDiagnosisTimerPRev = 0;
   TRBWAPMP_u8Timer = 0;
   TrbCoSysHw_bDgoScp_TrbWaPmp = 0;
   TrbCoSysHw_bDgoScg_TrbWaPmp = 0;
   TrbCoSysHw_bDgoOc_TrbWaPmp = 0;
   TrbCoSysHw_bMonRunOc_TrbWaPmp = 0;
   TrbCoSysHw_bMonRunScg_TrbWaPmp = 0;
   TrbCoSysHw_bMonRunScp_TrbWaPmp = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidTreatment                                      */
/* !Description :  cette fct permet la réalisation des étapes du              */
/*                 fonctionnement de la pompe à eau.                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HIND GHORBEL                                               */
/* !Trace_To    :  VEMS_R_11_02775_005.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TRBWAPMP_vidConversionInPercent();                       */
/*  extf argret void TRBWAPMP_vidCmdRCOCor();                                 */
/*  extf argret void TRBWAPMP_vidDrvCmd();                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidTreatment(void)
{
   TRBWAPMP_vidConversionInPercent();
   TRBWAPMP_vidCmdRCOCor();
   TRBWAPMP_vidDrvCmd();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidConversionInPercent                            */
/* !Description :  Cette fonction permet de convertir la pourcentage de la    */
/*                 commande de la pompe à eau et de filtrer la tension de la  */
/*                 batterie.                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean ThMgt_bTrbWaPmpReq;                                         */
/*  input sint16 Ext_uBattMes;                                                */
/*  input sint16 TRBWAPMP_s16ExtuBattMesPrev;                                 */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq_Abs;                                */
/*  output uint16 Ext_uBattMes_Filtered;                                      */
/*  output sint16 TRBWAPMP_s16ExtuBattMesPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidConversionInPercent(void)
{
   boolean  bLocalThMgt_bTrbWaPmpReq;
   sint16   s16LocalExt_uBattMes;
   sint32   s32LocalTrbWaPmp_ExtuBattMesSom;


   VEMS_vidGET(ThMgt_bTrbWaPmpReq, bLocalThMgt_bTrbWaPmpReq);
   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);


   if (bLocalThMgt_bTrbWaPmpReq == 0)
   {
      TrbCoSysHw_rCtlWaPmpReq_Abs = 0;
   }
   else
   {
      TrbCoSysHw_rCtlWaPmpReq_Abs = 1000;
   }

   s32LocalTrbWaPmp_ExtuBattMesSom = (sint32)( s16LocalExt_uBattMes
                                             + TRBWAPMP_s16ExtuBattMesPrev);

   s32LocalTrbWaPmp_ExtuBattMesSom = s32LocalTrbWaPmp_ExtuBattMesSom / 2;

   Ext_uBattMes_Filtered =
      (uint16)MATHSRV_udtCLAMP(s32LocalTrbWaPmp_ExtuBattMesSom, 0, 3200);

   TRBWAPMP_s16ExtuBattMesPrev =
      (sint16)MATHSRV_udtCLAMP(s16LocalExt_uBattMes, 0, 3200);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidCmdRCOCor                                      */
/* !Description :  Cette fonction permet de corriger puis calculer le cycle   */
/*                 d'utilisation de la commande de la pompe à eau.            */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Ext_bAcvCtlBattCor_TrbWaPmp_C;                              */
/*  input uint16 Ext_uBattMes_Filtered;                                       */
/*  input uint8 Ext_uBattMes_Nom;                                             */
/*  input uint16 TrbCoSysHw_rCtlWaPmpReq_Abs;                                 */
/*  input uint16 TrbCoSysHw_rCtlWaPmpReq_Cor;                                 */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq_Cor;                                */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq_Lim;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidCmdRCOCor(void)
{
   /* */
   uint32 u32LocalResult;
   uint32 u32LocalMul;


   if (Ext_bAcvCtlBattCor_TrbWaPmp_C != 0)
   {
      if (Ext_uBattMes_Filtered != 0)
      {
         u32LocalMul = (uint32)( ( Ext_uBattMes_Nom
                                 * TrbCoSysHw_rCtlWaPmpReq_Abs)
                               * 10);
         u32LocalResult = (u32LocalMul / Ext_uBattMes_Filtered);
      }
      else
      {
         u32LocalResult = 0;
      }
   }
   else
   {
      u32LocalResult = TrbCoSysHw_rCtlWaPmpReq_Abs;
   }
   TrbCoSysHw_rCtlWaPmpReq_Cor = (uint16)MATHSRV_udtMIN(u32LocalResult, 1000);
   TrbCoSysHw_rCtlWaPmpReq_Lim = TrbCoSysHw_rCtlWaPmpReq_Cor;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidDrvCmd                                         */
/* !Description :  Cette fonction permet d'effectuer la transmission de la    */
/*                 commande de pompe à eau à travers la couche de base via le */
/*                 Service PWDHAL.                                            */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  HIND GHORBEL                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TrbCoSysHw_WaPmpReqFreq_C;                                   */
/*  input boolean ThMgt_bActrTstInProgs;                                      */
/*  input boolean ThMgt_bTrbWaPmpReqActrTst;                                  */
/*  input uint16 TrbCoSysHw_WaPmpReqMax_C;                                    */
/*  input uint16 TrbCoSysHw_WaPmpReqMin_C;                                    */
/*  input uint16 TrbCoSysHw_rCtlWaPmpReq_Lim;                                 */
/*  input uint16 TrbCoSysHw_RcoTact;                                          */
/*  input boolean TrbCoSysHw_bInvDuCy_C;                                      */
/*  input uint16 TrbCoSysHw_rCtlWaPmpReq;                                     */
/*  output uint16 Commande_water_pump_pwm_freq;                               */
/*  output uint16 TrbCoSysHw_WaPmpReqFreq_C;                                  */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq_Cnv;                                */
/*  output uint16 TrbCoSysHw_RcoTact;                                         */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq_Drv;                                */
/*  output uint16 TrbCoSysHw_rCtlWaPmpReq;                                    */
/*  output uint16 Commande_water_pump_pwm_rco;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidDrvCmd(void)
{
   boolean bLocalThMgt_bActrTstInProgs;
   boolean bLocalThMgt_bTrbWaPmpReqActrTst;
   uint16  u16LocalTrbCoSysHw_rCtlCnv;
   uint32  u32LocalProd;
   uint32  u32LocalABS;
   uint32  u32LocalResult;
   sint32  s32LocalDiff;
   sint32  s32LocalResult;

   VEMS_vidSET(Commande_water_pump_pwm_freq, TrbCoSysHw_WaPmpReqFreq_C);

   VEMS_vidGET(ThMgt_bActrTstInProgs, bLocalThMgt_bActrTstInProgs);
   VEMS_vidGET(ThMgt_bTrbWaPmpReqActrTst, bLocalThMgt_bTrbWaPmpReqActrTst);
   s32LocalDiff = (sint32)(TrbCoSysHw_WaPmpReqMax_C - TrbCoSysHw_WaPmpReqMin_C);
   u32LocalABS = (uint32)MATHSRV_udtABS(s32LocalDiff);
   u32LocalProd = (((u32LocalABS * TrbCoSysHw_rCtlWaPmpReq_Lim) + 500) / 1000);
   if (TrbCoSysHw_WaPmpReqMax_C > TrbCoSysHw_WaPmpReqMin_C)
   {
      u32LocalResult = u32LocalProd + TrbCoSysHw_WaPmpReqMin_C;
      u16LocalTrbCoSysHw_rCtlCnv = (uint16)MATHSRV_udtMIN(u32LocalResult,
                                                          1000);
   }
   else
   {
      s32LocalResult = (sint32)(TrbCoSysHw_WaPmpReqMin_C - u32LocalProd);
      u16LocalTrbCoSysHw_rCtlCnv = (uint16)MATHSRV_udtCLAMP(s32LocalResult,
                                                            0,
                                                            1000);
      /*QAC Warning Msg(3:3356) : the clamp is entirely covered*/
   }
   TrbCoSysHw_rCtlWaPmpReq_Cnv = u16LocalTrbCoSysHw_rCtlCnv;
   if (bLocalThMgt_bTrbWaPmpReqActrTst != 0)
   {
      TrbCoSysHw_RcoTact = 1000;
   }
   else
   {
      TrbCoSysHw_RcoTact = 0;
   }
   if (bLocalThMgt_bActrTstInProgs != 0)
   {
      u16LocalTrbCoSysHw_rCtlCnv = TrbCoSysHw_RcoTact;
   }
   VEMS_vidSET(TrbCoSysHw_rCtlWaPmpReq_Drv, u16LocalTrbCoSysHw_rCtlCnv);
   if (TrbCoSysHw_bInvDuCy_C != 0)
   {
      TrbCoSysHw_rCtlWaPmpReq = (uint16)(1000 - u16LocalTrbCoSysHw_rCtlCnv);
   }
   else
   {
      TrbCoSysHw_rCtlWaPmpReq = u16LocalTrbCoSysHw_rCtlCnv;
   }

   VEMS_vidSET(Commande_water_pump_pwm_rco, TrbCoSysHw_rCtlWaPmpReq);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TRBWAPMP_vidDiagnosis                                      */
/* !Description :  Cette fonction permet de réaliser le diagnostic des échecs.*/
/* !Number      :  FCT1.7                                                     */
/* !Author      :  HIND GHORBEL                                               */
/* !Trace_To    :  VEMS_R_11_02775_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 TrbCoSysHw_rCtlWaPmpReq_Drv;                                 */
/*  input uint16 TrbCoSysHw_WaPmpReqMinDiagEl_C;                              */
/*  input boolean TRBWAPMP_bInitDiagnosisTimerPRev;                           */
/*  input uint8 TrbWaPmp_TiInh_DiagEl_C;                                      */
/*  input uint8 TRBWAPMP_u8Timer;                                             */
/*  input boolean Dena_oc_TrbWaPmp;                                           */
/*  input boolean Dena_scg_TrbWaPmp;                                          */
/*  input boolean Dena_scp_TrbWaPmp;                                          */
/*  input boolean Dft_oc_TrbWaPmp;                                            */
/*  input boolean Dft_scg_TrbWaPmp;                                           */
/*  input boolean Dft_scp_TrbWaPmp;                                           */
/*  input boolean TrbWaPmp_bTiInh_DiagEl;                                     */
/*  output uint8 TRBWAPMP_u8Timer;                                            */
/*  output boolean TrbWaPmp_bTiInh_DiagEl;                                    */
/*  output boolean TRBWAPMP_bInitDiagnosisTimerPRev;                          */
/*  output boolean TrbCoSysHw_bDgoScp_TrbWaPmp;                               */
/*  output boolean TrbCoSysHw_bDgoScg_TrbWaPmp;                               */
/*  output boolean TrbCoSysHw_bDgoOc_TrbWaPmp;                                */
/*  output boolean TrbCoSysHw_bMonRunScp_TrbWaPmp;                            */
/*  output boolean TrbCoSysHw_bMonRunOc_TrbWaPmp;                             */
/*  output boolean TrbCoSysHw_bMonRunScg_TrbWaPmp;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TRBWAPMP_vidDiagnosis(void)
{
   boolean bLocalInhDiag_rCtlTrbWaPmp;
   boolean bLocalInitTimer;
   boolean bLocalDena_oc_TrbWaPmp;
   boolean bLocalDena_scg_TrbWaPmp;
   boolean bLocalDena_scp_TrbWaPmp;
   boolean bLocalDft_oc_TrbWaPmp;
   boolean bLocalDft_scg_TrbWaPmp;
   boolean bLocalDft_scp_TrbWaPmp;
   uint16  u16LocalTrbCSysHw_rCtlWPmpRq_Drv;

   VEMS_vidGET(TrbCoSysHw_rCtlWaPmpReq_Drv, u16LocalTrbCSysHw_rCtlWPmpRq_Drv);
   if (u16LocalTrbCSysHw_rCtlWPmpRq_Drv > TrbCoSysHw_WaPmpReqMinDiagEl_C)
   {
      bLocalInitTimer = 1;
   }
   else
   {
      bLocalInitTimer = 0;
   }

   if (  (TRBWAPMP_bInitDiagnosisTimerPRev == 0)
      && (bLocalInitTimer != 0))
   {
      TRBWAPMP_u8Timer = TrbWaPmp_TiInh_DiagEl_C;
      if (TRBWAPMP_u8Timer == 0)
      {
         TrbWaPmp_bTiInh_DiagEl = 1;
      }
      else
      {
         TrbWaPmp_bTiInh_DiagEl = 0;
      }
   }
   else
   {
      if (TRBWAPMP_u8Timer > 0)
      {
         TRBWAPMP_u8Timer = (uint8)(TRBWAPMP_u8Timer - 1);
         if (TRBWAPMP_u8Timer == 0)
         {
            TrbWaPmp_bTiInh_DiagEl = 1;
         }
         else
         {
            TrbWaPmp_bTiInh_DiagEl = 0;
         }
      }
   }
   TRBWAPMP_bInitDiagnosisTimerPRev = bLocalInitTimer;

   bLocalInhDiag_rCtlTrbWaPmp = GDGAR_bGetFRM(FRM_FRM_INHDIAG_RCTLTRBWAPMP);
   VEMS_vidGET(Dena_oc_TrbWaPmp, bLocalDena_oc_TrbWaPmp);
   VEMS_vidGET(Dena_scg_TrbWaPmp, bLocalDena_scg_TrbWaPmp);
   VEMS_vidGET(Dena_scp_TrbWaPmp, bLocalDena_scp_TrbWaPmp);
   VEMS_vidGET(Dft_oc_TrbWaPmp, bLocalDft_oc_TrbWaPmp);
   VEMS_vidGET(Dft_scg_TrbWaPmp, bLocalDft_scg_TrbWaPmp);
   VEMS_vidGET(Dft_scp_TrbWaPmp , bLocalDft_scp_TrbWaPmp);

   TrbCoSysHw_bDgoScp_TrbWaPmp = bLocalDft_scp_TrbWaPmp;
   TrbCoSysHw_bDgoScg_TrbWaPmp = bLocalDft_scg_TrbWaPmp;
   TrbCoSysHw_bDgoOc_TrbWaPmp = bLocalDft_oc_TrbWaPmp;

   if (bLocalInhDiag_rCtlTrbWaPmp == 0)
   {
      if (bLocalDena_scp_TrbWaPmp != 0)
      {
         TrbCoSysHw_bMonRunScp_TrbWaPmp = 1;
      }
      else
      {
         TrbCoSysHw_bMonRunScp_TrbWaPmp = 0;
      }
      if (TrbWaPmp_bTiInh_DiagEl != 0)
      {
         if (bLocalDena_oc_TrbWaPmp != 0)
         {
            TrbCoSysHw_bMonRunOc_TrbWaPmp = 1;
         }
         else
         {
            TrbCoSysHw_bMonRunOc_TrbWaPmp = 0;
         }
         if (bLocalDena_scg_TrbWaPmp != 0)
         {
            TrbCoSysHw_bMonRunScg_TrbWaPmp = 1;
         }
         else
         {
            TrbCoSysHw_bMonRunScg_TrbWaPmp = 0;
         }
      }
      else
      {
         TrbCoSysHw_bMonRunOc_TrbWaPmp = 0;
         TrbCoSysHw_bMonRunScg_TrbWaPmp = 0;
      }
   }
   else
   {
      TrbCoSysHw_bMonRunScp_TrbWaPmp = 0;
      TrbCoSysHw_bMonRunOc_TrbWaPmp = 0;
      TrbCoSysHw_bMonRunScg_TrbWaPmp = 0;
   }
}
/*-------------------------------- end of file -------------------------------*/