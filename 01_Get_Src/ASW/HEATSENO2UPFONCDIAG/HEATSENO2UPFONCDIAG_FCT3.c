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
/* !File            : HEATSENO2UPFONCDIAG_FCT3.C                              */
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
/*   1 / HEATSENO2UPFONCDIAG_vidNormMod06                                     */
/*   2 / HEATSENO2UPFONCDIAG_vidFcoMdEr6                                      */
/*   3 / HEATSENO2UPFONCDIAG_vidFldMdEr6                                      */
/*   4 / HEATSENO2UPFONCDIAG_vidIntmpDiag                                     */
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
/* !Function    :  HEATSENO2UPFONCDIAG_vidNormMod06                           */
/* !Description :  Ce bloc Vérifie si la tension de la sonde amont est bien   */
/*                 au-dessus d’un certain seuil.                              */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_sonde_amont;                                         */
/*  input uint8 Ext_stSysGas;                                                 */
/*  input uint16 LsMon_uThdSenO2UsDiagGas_C;                                  */
/*  input uint16 LsMon_uThdSenO2UsDiag_C;                                     */
/*  output uint16 SenO2Us_FldPlausFacMesRaw;                                  */
/*  output uint16 SenO2Us_FldPlausFacMinRaw;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidNormMod06(void)
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
         (uint16)MATHSRV_udtMIN(LsMon_uThdSenO2UsDiagGas_C, 1024);
   }
   else
   {
      SenO2Us_FldPlausFacMinRaw =
         (uint16)MATHSRV_udtMIN(LsMon_uThdSenO2UsDiag_C, 1024);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidFcoMdEr6                            */
/* !Description :  Ce bloc permet de respecter les exigences euro6.           */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenO2Us_FcoPlausFacMesRaw;                                   */
/*  input uint16 SenO2Us_FcoPlausFacMaxRaw;                                   */
/*  input boolean SenO2Us_bAcvEuro6UsPlausFco_C;                              */
/*  input boolean SenO2Us_bDgoORng_UsPlausFco;                                */
/*  input uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Us_FcoPlausFacMax_Obd6Mod;                              */
/*  input boolean SenO2Us_bInhMonWait_PlausFco_C;                             */
/*  input boolean SenO2Us_bMonRunRaw_UsPlausFco;                              */
/*  input boolean SenO2Us_bMonWaitRaw_UsPlausFco;                             */
/*  output uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Us_FcoPlausFacMax_Obd6Mod;                             */
/*  output boolean SenO2Us_bMonWaitORng_UsPlausFco;                           */
/*  output boolean SenO2Us_bMonRunORng_UsPlausFco;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidFcoMdEr6(void)
{
   boolean bLocalCfmSenO2UsStuckRich;
   uint16  u16LocalSenO2UsFcoPlFcMsOd6Md;
   uint16  u16LocalSenO2UsFcoPlFcMxOd6Md;


   bLocalCfmSenO2UsStuckRich = GDGAR_bGetFRM(FRM_FRM_CFMSENO2USSTUCKRICH);

   if (bLocalCfmSenO2UsStuckRich != 0)
   {
      u16LocalSenO2UsFcoPlFcMsOd6Md = SenO2Us_FcoPlausFacMesRaw;
      u16LocalSenO2UsFcoPlFcMxOd6Md = SenO2Us_FcoPlausFacMaxRaw;
   }
   else
   {
      if (  (SenO2Us_bAcvEuro6UsPlausFco_C == 0)
         || (SenO2Us_bDgoORng_UsPlausFco == 0))
      {
         u16LocalSenO2UsFcoPlFcMsOd6Md = SenO2Us_FcoPlausFacMesRaw;
         u16LocalSenO2UsFcoPlFcMxOd6Md = SenO2Us_FcoPlausFacMaxRaw;
      }
      else
      {
         VEMS_vidGET(SenO2Us_FcoPlausFacMes_Obd6Mod,
                     u16LocalSenO2UsFcoPlFcMsOd6Md);
         VEMS_vidGET(SenO2Us_FcoPlausFacMax_Obd6Mod,
                     u16LocalSenO2UsFcoPlFcMxOd6Md);
      }
   }
   u16LocalSenO2UsFcoPlFcMsOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2UsFcoPlFcMsOd6Md, 1024);
   u16LocalSenO2UsFcoPlFcMxOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2UsFcoPlFcMxOd6Md, 1024);
   VEMS_vidSET(SenO2Us_FcoPlausFacMes_Obd6Mod,
               u16LocalSenO2UsFcoPlFcMsOd6Md);
   VEMS_vidSET(SenO2Us_FcoPlausFacMax_Obd6Mod,
               u16LocalSenO2UsFcoPlFcMxOd6Md);

   if (SenO2Us_bInhMonWait_PlausFco_C != 0)
   {
      SenO2Us_bMonWaitORng_UsPlausFco = DIAG_DISPO;
      if (  (SenO2Us_bMonRunRaw_UsPlausFco != 0)
         && (SenO2Us_bMonWaitRaw_UsPlausFco == 0))
      {
         SenO2Us_bMonRunORng_UsPlausFco = 1;
      }
      else
      {
         SenO2Us_bMonRunORng_UsPlausFco = 0;
      }
   }
   else
   {
      SenO2Us_bMonWaitORng_UsPlausFco = SenO2Us_bMonWaitRaw_UsPlausFco;
      SenO2Us_bMonRunORng_UsPlausFco = SenO2Us_bMonRunRaw_UsPlausFco;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidFldMdEr6                            */
/* !Description :  Ce bloc permet de respecter les exigences euro6.           */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenO2Us_FldPlausFacMesRaw;                                   */
/*  input uint16 SenO2Us_FldPlausFacMinRaw;                                   */
/*  input boolean SenO2Us_bAcvEuro6UsPlausFld_C;                              */
/*  input boolean SenO2Us_bDgoORng_UsPlausFld;                                */
/*  input uint16 SenO2Us_FldPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Us_FldPlausFacMin_Obd6Mod;                              */
/*  input boolean SenO2Us_bInhMonWait_PlausFld_C;                             */
/*  input boolean SenO2Us_bMonRunRaw_UsPlausFld;                              */
/*  input boolean SenO2Us_bMonWaitRaw_UsPlausFld;                             */
/*  output uint16 SenO2Us_FldPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Us_FldPlausFacMin_Obd6Mod;                             */
/*  output boolean SenO2Us_bMonWaitORng_UsPlausFld;                           */
/*  output boolean SenO2Us_bMonRunORng_UsPlausFld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidFldMdEr6(void)
{
   boolean bLocalCfmSenO2UsStuckLean;
   uint16  u16LocalSenO2UsFldPlFcMsOd6Md;
   uint16  u16LocalSenO2UsFldPlFcMnOd6Md;


   bLocalCfmSenO2UsStuckLean = GDGAR_bGetFRM(FRM_FRM_CFMSENO2USSTUCKLEAN);

   if (bLocalCfmSenO2UsStuckLean != 0)
   {
      u16LocalSenO2UsFldPlFcMsOd6Md = SenO2Us_FldPlausFacMesRaw;
      u16LocalSenO2UsFldPlFcMnOd6Md = SenO2Us_FldPlausFacMinRaw;
   }
   else
   {
      if (  (SenO2Us_bAcvEuro6UsPlausFld_C == 0)
         || (SenO2Us_bDgoORng_UsPlausFld == 0))
      {
         u16LocalSenO2UsFldPlFcMsOd6Md = SenO2Us_FldPlausFacMesRaw;
         u16LocalSenO2UsFldPlFcMnOd6Md = SenO2Us_FldPlausFacMinRaw;
      }
      else
      {
         VEMS_vidGET(SenO2Us_FldPlausFacMes_Obd6Mod,
                     u16LocalSenO2UsFldPlFcMsOd6Md);
         VEMS_vidGET(SenO2Us_FldPlausFacMin_Obd6Mod,
                     u16LocalSenO2UsFldPlFcMnOd6Md);
      }
   }
   u16LocalSenO2UsFldPlFcMsOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2UsFldPlFcMsOd6Md, 1024);
   u16LocalSenO2UsFldPlFcMnOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2UsFldPlFcMnOd6Md, 1024);
   VEMS_vidSET(SenO2Us_FldPlausFacMes_Obd6Mod,
               u16LocalSenO2UsFldPlFcMsOd6Md);
   VEMS_vidSET(SenO2Us_FldPlausFacMin_Obd6Mod,
               u16LocalSenO2UsFldPlFcMnOd6Md);

   if (SenO2Us_bInhMonWait_PlausFld_C != 0)
   {
      SenO2Us_bMonWaitORng_UsPlausFld = DIAG_DISPO;
      if (  (SenO2Us_bMonRunRaw_UsPlausFld != 0)
         && (SenO2Us_bMonWaitRaw_UsPlausFld == 0))
      {
         SenO2Us_bMonRunORng_UsPlausFld = 1;
      }
      else
      {
         SenO2Us_bMonRunORng_UsPlausFld = 0;
      }
   }
   else
   {
      SenO2Us_bMonWaitORng_UsPlausFld = SenO2Us_bMonWaitRaw_UsPlausFld;
      SenO2Us_bMonRunORng_UsPlausFld = SenO2Us_bMonRunRaw_UsPlausFld;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2UPFONCDIAG_vidIntmpDiag                           */
/* !Description :  Lancement des fonctions de diagnostic                      */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 LsMon_tiCfmSenO2UsDiag_C;                                    */
/*  output uint16 LsMon_tiCfmSenO2UsDiag;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2UPFONCDIAG_vidIntmpDiag(void)
{
   LsMon_tiCfmSenO2UsDiag = LsMon_tiCfmSenO2UsDiag_C;
}
/*---------------------------- end of file -----------------------------------*/