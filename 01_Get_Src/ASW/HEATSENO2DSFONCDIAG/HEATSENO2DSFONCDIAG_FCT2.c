/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2DSFONCDIAG                                     */
/* !Description     : HEATSENO2DSFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2DSFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AVAL                       */
/*                                                                            */
/* !File            : HEATSENO2DSFONCDIAG_FCT2.C                              */
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
/*   1 / HEATSENO2DSFONCDIAG_vidDecTConfD                                     */
/*   2 / HEATSENO2DSFONCDIAG_vidIniTConfD                                     */
/*   3 / HEATSENO2DSFONCDIAG_vidMode6                                         */
/*   4 / HEATSENO2DSFONCDIAG_vidFldObd6M                                      */
/*   5 / HEATSENO2DSFONCDIAG_vidFcoObd6M                                      */
/*   6 / HEATSENO2DSFONCDIAG_vidSeqFld                                        */
/*   7 / HEATSENO2DSFONCDIAG_vidModTran                                       */
/*   8 / HEATSENO2DSFONCDIAG_vidInitDiag1                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 07942 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2DS/HEATSENO2DSFONCDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   24 Sep 2012 $*/
/* $Author::   etsasson                               $$Date::   24 Sep 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2DSFONCDIAG.h"
#include "HEATSENO2DSFONCDIAG_L.h"
#include "HEATSENO2DSFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDecTConfD                           */
/* !Description :  Decrementation de Ldsd_av_f_diag_confirm_count             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_av_f_diag_confirm_count;                                */
/*  output uint16 Ldsd_av_f_diag_confirm_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDecTConfD(void)
{
   sint32 s32LocalLdsd_av_f_diag_cf_count;


   s32LocalLdsd_av_f_diag_cf_count = (sint32)(Ldsd_av_f_diag_confirm_count - 1);
   Ldsd_av_f_diag_confirm_count =
      (uint16)MATHSRV_udtCLAMP(s32LocalLdsd_av_f_diag_cf_count, 0, 5990);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidIniTConfD                           */
/* !Description :  Initialisation de Ldsd_av_f_diag_confirm_count             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Auto_injection;                                             */
/*  input uint16 Ldsd_av_f_diag_fld_conf_delay;                               */
/*  input uint16 Ldsd_av_f_diag_fco_conf_delay;                               */
/*  output uint16 Ldsd_av_f_diag_confirm_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidIniTConfD(void)
{
   boolean bLocalAuto_injection;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   if (bLocalAuto_injection != 0)
   {
      Ldsd_av_f_diag_confirm_count =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fld_conf_delay, 5990);
   }
   else
   {
      Ldsd_av_f_diag_confirm_count =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fco_conf_delay, 5990);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidMode6                               */
/* !Description :  Dans ce bloc on enregistre les dernières valeurs de la     */
/*                 tension sonde aval dans le cas d’une panne sonde aval      */
/*                 bloquée riche et sonde aval bloquée pauvre.                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidFldObd6M();                       */
/*  extf argret void HEATSENO2DSFONCDIAG_vidFcoObd6M();                       */
/*  input boolean Auto_injection;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidMode6(void)
{
   boolean bLocalAuto_injection;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   if (bLocalAuto_injection != 0)
   {
      /* 01_Fld_failure_mode6 */
      HEATSENO2DSFONCDIAG_vidFldObd6M();
   }
   else
   {
      /* 02_Fco_failure_mode6 */
      HEATSENO2DSFONCDIAG_vidFcoObd6M();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidFldObd6M                            */
/* !Description :  comptage panne fld                                         */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_av_f_diag_fld_thd_g;                                    */
/*  input uint16 Ldsd_av_f_diag_fld_thresh;                                   */
/*  output uint16 SenO2Ds_FldPlausFacMesRaw;                                  */
/*  output uint16 SenO2Ds_FldPlausFacMinRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidFldObd6M(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalTension_sonde_aval;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   SenO2Ds_FldPlausFacMesRaw =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1024);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      SenO2Ds_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fld_thd_g, 1024);
   }
   else
   {
      SenO2Ds_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fld_thresh, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidFcoObd6M                            */
/* !Description :  Comptage panne fco                                         */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_av_f_diag_fco_thd_g;                                    */
/*  input uint16 Ldsd_av_f_diag_fco_thresh;                                   */
/*  output uint16 SenO2Ds_FcoPlausFacMesRaw;                                  */
/*  output uint16 SenO2Ds_FcoPlausFacMaxRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidFcoObd6M(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalTension_sonde_aval;


   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   SenO2Ds_FcoPlausFacMesRaw =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_aval, 1024);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      SenO2Ds_FcoPlausFacMaxRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fco_thd_g, 1024);
   }
   else
   {
      SenO2Ds_FcoPlausFacMaxRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_av_f_diag_fco_thresh, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidSeqFld                              */
/* !Description :  Le diagnostic de la sonde aval bloquée pauvre est séquencé */
/*                 par le diagnostic "condition" chauffage sonde aval.        */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16 u16Index);*/
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SenO2Ds_bAcvSeqDsPlausFld_C;                                */
/*  input boolean Ldsd_av_fld_failure;                                        */
/*  input boolean Ldsd_av_fld_confirm;                                        */
/*  output boolean SenO2Ds_bDgoORng_DsPlausFld;                               */
/*  output boolean SenO2Ds_bMonWaitRaw_DsPlausFld;                            */
/*  output boolean SenO2Ds_bAcvSeqDsPlausFld;                                 */
/*  output boolean SenO2Ds_bAcvSeqMemDsPlausFld;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidSeqFld(void)
{
   boolean            bLocalGDU_bEndDiagStrtORngDsHeat;
   GDFRM_tenuGDUState u8LocalGDU_stDgoORng_DsHeat;


   bLocalGDU_bEndDiagStrtORngDsHeat = GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_DSHEAT);

   if (SenO2Ds_bAcvSeqDsPlausFld_C != 0)
   {
      u8LocalGDU_stDgoORng_DsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_DSHEAT);
      if (u8LocalGDU_stDgoORng_DsHeat == GDU_ETAT_PRESENT)
      {
         SenO2Ds_bDgoORng_DsPlausFld = 0;
      }
      else
      {
         SenO2Ds_bDgoORng_DsPlausFld = Ldsd_av_fld_failure;
      }
      if (  (Ldsd_av_fld_confirm ==0)
         || (bLocalGDU_bEndDiagStrtORngDsHeat ==0))
      {
         SenO2Ds_bMonWaitRaw_DsPlausFld = 1;
      }
      else
      {
         SenO2Ds_bMonWaitRaw_DsPlausFld = 0;
      }
   }
   else
   {
      SenO2Ds_bDgoORng_DsPlausFld = Ldsd_av_fld_failure;
      SenO2Ds_bMonWaitRaw_DsPlausFld = 0;
   }

   if (  (bLocalGDU_bEndDiagStrtORngDsHeat == 0)
      && (Ldsd_av_fld_failure != 0))
   {
      VEMS_vidSET(SenO2Ds_bAcvSeqDsPlausFld, 1);
      VEMS_vidSET(SenO2Ds_bAcvSeqMemDsPlausFld, 1);
   }
   else
   {
      VEMS_vidSET(SenO2Ds_bAcvSeqDsPlausFld, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidModTran                             */
/* !Description :  Ce bloc permet la réinitialisation du diagnostic lors des  */
/*                 transitions essence ver gaz ou gaz vers essence.           */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2DSFONCDIAG_vidInitDiag1();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 HEATSENO2DSFONCDIAG_u8SysGasPrev;                             */
/*  output uint8 HEATSENO2DSFONCDIAG_u8SysGasPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidModTran(void)
{
   uint8  u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (  (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
         && (HEATSENO2DSFONCDIAG_u8SysGasPrev == Ext_stGslMod_SC))
      || (  (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
         && (HEATSENO2DSFONCDIAG_u8SysGasPrev == Ext_stGasMod_SC)))
   {
      HEATSENO2DSFONCDIAG_vidInitDiag1();
   }
   HEATSENO2DSFONCDIAG_u8SysGasPrev = u8LocalExt_stSysGas;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidInitDiag1                           */
/* !Description :  Initialisation des compteurs du diagnostic sonde aval.     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Ldsd_av_f_diag_count;                                       */
/*  output uint16 Ldsd_av_f_diag_confirm_count;                               */
/*  output uint16 Ldsd_av_diag_ai_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidInitDiag1(void)
{
   Ldsd_av_f_diag_count = 0;
   Ldsd_av_f_diag_confirm_count = 0;
   Ldsd_av_diag_ai_count = 0;
}
/*---------------------------- end of file -----------------------------------*/