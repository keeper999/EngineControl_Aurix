/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HEATSENO2UPFONCDIAG                                     */
/* !Description     : HEATSENO2UPFONCDIAG Component                           */
/*                                                                            */
/* !Module          : HEATSENO2UPFONCDIAG                                     */
/* !Description     : DIAGNOSTIC FONCTIONNEL SONDE AMONT                      */
/*                                                                            */
/* !File            : HEATSENO2UPFONCDIAG_FCT2.C                              */
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
/*   1 / HEATSENO2UPFONCDIAG_vidDecTConfD                                     */
/*   2 / HEATSENO2UPFONCDIAG_vidIniTConfD                                     */
/*   3 / HEATSENO2UPFONCDIAG_vidMode6                                         */
/*   4 / HEATSENO2UPFONCDIAG_vidFldObd6M                                      */
/*   5 / HEATSENO2UPFONCDIAG_vidFcoObd6M                                      */
/*   6 / HEATSENO2UPFONCDIAG_vidSeqFld                                        */
/*   7 / HEATSENO2UPFONCDIAG_vidModTran                                       */
/*   8 / HEATSENO2UPFONCDIAG_vidInitModTr                                     */
/*   9 / HEATSENO2UPFONCDIAG_vidNormDiag                                      */
/*   10 / HEATSENO2UPFONCDIAG_vidDiagCount                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5482727 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/ARCHI_SENO2US/HEATSENO2UPFONCDIA$*/
/* $Revision::   1.3      $$Author::   etsasson       $$Date::   17 Sep 2013 $*/
/* $Author::   etsasson                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HEATSENO2UPFONCDIAG.h"
#include "HEATSENO2UPFONCDIAG_L.h"
#include "HEATSENO2UPFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidDecTConfD                           */
/* !Description :  Decrementation de Ldsd_am_f_diag_confirm_count             */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ldsd_am_f_diag_confirm_count;                                */
/*  output uint16 Ldsd_am_f_diag_confirm_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidDecTConfD(void)
{
   sint16 s16LocalLdsd_am_f_diag_cf_count;


   s16LocalLdsd_am_f_diag_cf_count = (sint16)(Ldsd_am_f_diag_confirm_count - 1);
   Ldsd_am_f_diag_confirm_count =
      (uint16)MATHSRV_udtCLAMP(s16LocalLdsd_am_f_diag_cf_count, 0, 5990);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidIniTConfD                           */
/* !Description :  Initialisation de Ldsd_am_f_diag_confirm_count             */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input boolean Auto_injection;                                             */
/*  input uint16 Ldsd_am_f_diag_fld_conf_g_delay;                             */
/*  input uint16 Ldsd_am_f_diag_fld_conf_delay;                               */
/*  input uint16 Ldsd_am_f_diag_fco_conf_g_delay;                             */
/*  input uint16 Ldsd_am_f_diag_fco_conf_delay;                               */
/*  output uint16 Ldsd_am_f_diag_confirm_count;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidIniTConfD(void)
{
   boolean bLocalAuto_injection;
   uint8   u8LocalExt_stSysGas;

   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   if (bLocalAuto_injection != 0)
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fld_conf_g_delay, 5990);
      }
      else
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fld_conf_delay, 5990);
      }
   }
   else
   {
      if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fco_conf_g_delay, 5990);
      }
      else
      {
         Ldsd_am_f_diag_confirm_count =
            (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fco_conf_delay, 5990);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidMode6                               */
/* !Description :  Dans ce bloc on enregistre les dernières valeurs de la     */
/*                 tension sonde amont dans le cas d’une panne sonde amont    */
/*                 bloquée riche et sonde amont bloquée pauvre.               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07980_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPFONCDIAG_vidFldObd6M();                       */
/*  extf argret void HEATSENO2UPFONCDIAG_vidFcoObd6M();                       */
/*  input boolean Auto_injection;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidMode6(void)
{
   boolean bLocalAuto_injection;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   if (bLocalAuto_injection != 0)
   {
      HEATSENO2UPFONCDIAG_vidFldObd6M();
   }
   else
   {
      HEATSENO2UPFONCDIAG_vidFcoObd6M();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidFldObd6M                            */
/* !Description :  comptage panne fld                                         */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_am_f_diag_fld_thd_g;                                    */
/*  input uint16 Ldsd_am_f_diag_fld_thresh;                                   */
/*  output uint16 SenO2Us_FldPlausFacMesRaw;                                  */
/*  output uint16 SenO2Us_FldPlausFacMinRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidFldObd6M(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalTension_sonde_amont;


   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   SenO2Us_FldPlausFacMesRaw =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont, 1024);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      SenO2Us_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fld_thd_g, 1024);
   }
   else
   {
      SenO2Us_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fld_thresh, 1024);

   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidFcoObd6M                            */
/* !Description :  Comptage panne fco                                         */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Ldsd_am_f_diag_fco_thd_g;                                    */
/*  input uint16 Ldsd_am_f_diag_fco_thresh;                                   */
/*  output uint16 SenO2Us_FcoPlausFacMesRaw;                                  */
/*  output uint16 SenO2Us_FcoPlausFacMaxRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidFcoObd6M(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalTension_sonde_amont;


   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);
   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);

   SenO2Us_FcoPlausFacMesRaw =
      (uint16)MATHSRV_udtMIN(u16LocalTension_sonde_amont, 1024);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      SenO2Us_FcoPlausFacMaxRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fco_thd_g, 1024);
   }
   else
   {
      SenO2Us_FcoPlausFacMaxRaw =
         (uint16)MATHSRV_udtMIN(Ldsd_am_f_diag_fco_thresh, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidSeqFld                              */
/* !Description :  Le diagnostic de la sonde amont bloquée pauvre est séquencé*/
/*                 par le diagnostic "condition" chauffage sonde amont.       */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetEndDiagStrt(argin uint16 u16IdxDft);       */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean SenO2Us_bAcvSeqUsPlausFld_C;                                */
/*  input boolean Ldsd_am_fld_failure;                                        */
/*  input boolean Ldsd_am_fld_confirm;                                        */
/*  output boolean SenO2Us_bDgoORng_UsPlausFld;                               */
/*  output boolean SenO2Us_bMonWaitRaw_UsPlausFld;                            */
/*  output boolean SenO2Us_bAcvSeqUsPlausFld;                                 */
/*  output boolean SenO2Us_bAcvSeqMemUsPlausFld;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidSeqFld(void)
{
   boolean            bLocalGDU_bEndDiagStrtORngUsHeat;
   GDFRM_tenuGDUState u8LocalGDU_stDgoORng_UsHeat;


   bLocalGDU_bEndDiagStrtORngUsHeat = GDGAR_bGetEndDiagStrt(GD_DFT_ORNG_USHEAT);

   if (SenO2Us_bAcvSeqUsPlausFld_C != 0)
   {
      u8LocalGDU_stDgoORng_UsHeat = GDGAR_tenuGetStDgo(GD_DFT_ORNG_USHEAT);
      if (u8LocalGDU_stDgoORng_UsHeat == GDU_ETAT_PRESENT)
      {
         SenO2Us_bDgoORng_UsPlausFld = 0;
      }
      else
      {
         SenO2Us_bDgoORng_UsPlausFld = Ldsd_am_fld_failure;
      }
      if (  (Ldsd_am_fld_confirm == 0)
         || (bLocalGDU_bEndDiagStrtORngUsHeat == 0))
      {
         SenO2Us_bMonWaitRaw_UsPlausFld = 1;
      }
      else
      {
         SenO2Us_bMonWaitRaw_UsPlausFld = 0;
      }
   }
   else
   {
      SenO2Us_bDgoORng_UsPlausFld = Ldsd_am_fld_failure;
      SenO2Us_bMonWaitRaw_UsPlausFld = 0;
   }

   if (  (bLocalGDU_bEndDiagStrtORngUsHeat == 0)
      && (Ldsd_am_fld_failure != 0))
   {
      VEMS_vidSET(SenO2Us_bAcvSeqUsPlausFld, 1);
      VEMS_vidSET(SenO2Us_bAcvSeqMemUsPlausFld, 1);
   }
   else
   {
      VEMS_vidSET(SenO2Us_bAcvSeqUsPlausFld, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidModTran                             */
/* !Description :  Ce bloc permet la réinitialisation du diagnostic lors des  */
/*                 transitions essence ver gaz ou gaz vers essence.           */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPFONCDIAG_vidInitModTr();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint8 HEATSENO2UPFONCDIAG_u8SysGasPrev;                             */
/*  output uint8 HEATSENO2UPFONCDIAG_u8SysGasPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidModTran(void)
{
   uint8  u8LocalExt_stSysGas;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   if (  (  (u8LocalExt_stSysGas == Ext_stTranGslGas_SC)
         && (HEATSENO2UPFONCDIAG_u8SysGasPrev == Ext_stGslMod_SC))
      || (  (u8LocalExt_stSysGas == Ext_stTranGasGsl_SC)
         && (HEATSENO2UPFONCDIAG_u8SysGasPrev == Ext_stGasMod_SC)))
   {
      HEATSENO2UPFONCDIAG_vidInitModTr();
   }
   HEATSENO2UPFONCDIAG_u8SysGasPrev = u8LocalExt_stSysGas;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidInitModTr                           */
/* !Description :  Initialisation des compteurs du diagnostic sonde amont.    */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Ldsd_am_f_diag_count;                                       */
/*  output uint16 Ldsd_am_f_diag_confirm_count;                               */
/*  output uint16 Ldsd_am_diag_ai_count;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidInitModTr(void)
{
   Ldsd_am_f_diag_count = 0;
   Ldsd_am_f_diag_confirm_count = 0;
   Ldsd_am_diag_ai_count = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidNormDiag                            */
/* !Description :  Ce bloc correspond à la mise à jour du diagnostic « Sonde  */
/*                 amont bloquée pauvre »,pour l’application Euro 5+ avec     */
/*                 IUPR. Le diagnostic vérifie si la tension de la sonde amont*/
/*                 est bien au-dessus d’un certain seuil.                     */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void HEATSENO2UPFONCDIAG_vidDiagCount();                      */
/*  extf argret void HEATSENO2UPFONCDIAG_vidNormMod06();                      */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint16 LsMon_uThdSenO2UsDiagGas_C;                                  */
/*  input uint16 LsMon_uThdSenO2UsDiag_C;                                     */
/*  input boolean LsMon_bThdSenO2UsDiag;                                      */
/*  input uint16 LsMon_tiCfmSenO2UsDiag;                                      */
/*  input boolean Ldsd_am_fld_failure;                                        */
/*  output boolean LsMon_bThdSenO2UsDiag;                                     */
/*  output boolean Ldsd_am_fld_failure;                                       */
/*  output boolean Ldsd_am_fld_confirm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidNormDiag(void)
{
   uint8  u8LocalExt_stSysGas;
   uint16 u16LocalTension_sonde_amont;
   uint16 u16LocalLsMonuThdSenO2UsDiag;


   VEMS_vidGET(Ext_stSysGas, u8LocalExt_stSysGas);
   VEMS_vidGET(Tension_sonde_amont, u16LocalTension_sonde_amont);

   if (u8LocalExt_stSysGas == Ext_stGasMod_SC)
   {
      u16LocalLsMonuThdSenO2UsDiag = LsMon_uThdSenO2UsDiagGas_C;
   }
   else
   {
      u16LocalLsMonuThdSenO2UsDiag = LsMon_uThdSenO2UsDiag_C;
   }
   if (u16LocalTension_sonde_amont > u16LocalLsMonuThdSenO2UsDiag)
   {
      LsMon_bThdSenO2UsDiag = 1;
   }
   else
   {
      LsMon_bThdSenO2UsDiag = 0;
   }
   HEATSENO2UPFONCDIAG_vidDiagCount();
   if (  (LsMon_bThdSenO2UsDiag == 0)
      && (LsMon_tiCfmSenO2UsDiag == 0))
   {
      Ldsd_am_fld_failure = 1;
   }
   else
   {
      Ldsd_am_fld_failure = 0;
   }
   if (  (Ldsd_am_fld_failure != 0)
      || (LsMon_bThdSenO2UsDiag != 0))
   {
      Ldsd_am_fld_confirm = 1;
      HEATSENO2UPFONCDIAG_vidNormMod06();
   }
   else
   {
      Ldsd_am_fld_confirm = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidDiagCount                           */
/* !Description :  Le diagnostic vérifie si la tension de la sonde amont est  */
/*                 bien au-dessus d’un certain seuil.                         */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean LsMon_bThdSenO2UsDiag;                                      */
/*  input uint16 LsMon_tiCfmSenO2UsDiag_C;                                    */
/*  input uint16 LsMon_tiCfmSenO2UsDiag;                                      */
/*  output uint16 LsMon_tiCfmSenO2UsDiag;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidDiagCount(void)
{
   sint32 s32LocalLsMonTiCfmSenO2UsDiag;


   if (LsMon_bThdSenO2UsDiag != 0)
   {
      LsMon_tiCfmSenO2UsDiag = LsMon_tiCfmSenO2UsDiag_C;
   }
   else
   {
      s32LocalLsMonTiCfmSenO2UsDiag = (sint32)(LsMon_tiCfmSenO2UsDiag - 1);
      LsMon_tiCfmSenO2UsDiag =
         (uint16)MATHSRV_udtMAX(s32LocalLsMonTiCfmSenO2UsDiag, 0);
   }
}
/*---------------------------- end of file -----------------------------------*/