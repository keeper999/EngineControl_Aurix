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
/* !File            : HEATSENO2DSFONCDIAG_FCT5.C                              */
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
/*   1 / HEATSENO2DSFONCDIAG_vidFcoMdEr6                                      */
/*   2 / HEATSENO2DSFONCDIAG_vidFldMdEr6                                      */
/*   3 / HEATSENO2DSFONCDIAG_vidDiagIhBva                                     */
/*   4 / HEATSENO2DSFONCDIAG_vidtrsvCount                                     */
/*   5 / HEATSENO2DSFONCDIAG_vidCheckrMCy                                     */
/*   6 / HEATSENO2DSFONCDIAG_vidtrsvCtBva                                     */
/*   7 / HEATSENO2DSFONCDIAG_vidChMCyBva                                      */
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
/* !Function    :  HEATSENO2DSFONCDIAG_vidFcoMdEr6                            */
/* !Description :  Ce bloc permet de respecter les exigences euro6.           */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_07942_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenO2Ds_FcoPlausFacMesRaw;                                   */
/*  input uint16 SenO2Ds_FcoPlausFacMaxRaw;                                   */
/*  input boolean SenO2Ds_bAcvEuro6DsPlausFco_C;                              */
/*  input boolean SenO2Ds_bDgoORng_DsPlausFco;                                */
/*  input uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Ds_FcoPlausFacMax_Obd6Mod;                              */
/*  input boolean SenO2Ds_bInhMonWait_PlausFco_C;                             */
/*  input boolean SenO2Ds_bMonRunRaw_DsPlausFco;                              */
/*  input boolean SenO2Ds_bMonWaitRaw_DsPlausFco;                             */
/*  output uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Ds_FcoPlausFacMax_Obd6Mod;                             */
/*  output boolean SenO2Ds_bMonWaitORng_DsPlausFco;                           */
/*  output boolean SenO2Ds_bMonRunORng_DsPlausFco;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidFcoMdEr6(void)
{
   boolean bLocalCfmSenO2DsStuckRich;
   uint16  u16LocalSenO2DsFcoPlFcMsOd6Md;
   uint16  u16LocalSenO2DsFcoPlFcMxOd6Md;


   bLocalCfmSenO2DsStuckRich = GDGAR_bGetFRM(FRM_FRM_CFMSENO2DSSTUCKRICH);

   if (bLocalCfmSenO2DsStuckRich != 0)
   {
      u16LocalSenO2DsFcoPlFcMsOd6Md = SenO2Ds_FcoPlausFacMesRaw;
      u16LocalSenO2DsFcoPlFcMxOd6Md = SenO2Ds_FcoPlausFacMaxRaw;
   }
   else
   {
      if (  (SenO2Ds_bAcvEuro6DsPlausFco_C == 0)
         || (SenO2Ds_bDgoORng_DsPlausFco == 0))
      {
         u16LocalSenO2DsFcoPlFcMsOd6Md = SenO2Ds_FcoPlausFacMesRaw;
         u16LocalSenO2DsFcoPlFcMxOd6Md = SenO2Ds_FcoPlausFacMaxRaw;
      }
      else
      {
         VEMS_vidGET(SenO2Ds_FcoPlausFacMes_Obd6Mod,
                     u16LocalSenO2DsFcoPlFcMsOd6Md);
         VEMS_vidGET(SenO2Ds_FcoPlausFacMax_Obd6Mod,
                     u16LocalSenO2DsFcoPlFcMxOd6Md);
      }
   }
   u16LocalSenO2DsFcoPlFcMsOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2DsFcoPlFcMsOd6Md, 1024);
   VEMS_vidSET(SenO2Ds_FcoPlausFacMes_Obd6Mod,
               u16LocalSenO2DsFcoPlFcMsOd6Md);
   u16LocalSenO2DsFcoPlFcMxOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2DsFcoPlFcMxOd6Md, 1024);
   VEMS_vidSET(SenO2Ds_FcoPlausFacMax_Obd6Mod,
               u16LocalSenO2DsFcoPlFcMxOd6Md);

   if (SenO2Ds_bInhMonWait_PlausFco_C != 0)
   {
      SenO2Ds_bMonWaitORng_DsPlausFco = DIAG_DISPO;
      if (  (SenO2Ds_bMonRunRaw_DsPlausFco != 0)
         && (SenO2Ds_bMonWaitRaw_DsPlausFco == 0))
      {
         SenO2Ds_bMonRunORng_DsPlausFco = 1;
      }
      else
      {
         SenO2Ds_bMonRunORng_DsPlausFco = 0;
      }
   }
   else
   {
      SenO2Ds_bMonWaitORng_DsPlausFco = SenO2Ds_bMonWaitRaw_DsPlausFco;
      SenO2Ds_bMonRunORng_DsPlausFco = SenO2Ds_bMonRunRaw_DsPlausFco;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidFldMdEr6                            */
/* !Description :  Ce bloc permet de respecter les exigences euro6.           */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SenO2Ds_FldPlausFacMesRaw;                                   */
/*  input uint16 SenO2Ds_FldPlausFacMinRaw;                                   */
/*  input boolean SenO2Ds_bAcvEuro6DsPlausFld_C;                              */
/*  input boolean SenO2Ds_bDgoORng_DsPlausFld;                                */
/*  input uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Ds_FldPlausFacMin_Obd6Mod;                              */
/*  input boolean SenO2Ds_bInhMonWait_PlausFld_C;                             */
/*  input boolean SenO2Ds_bMonRunRaw_DsPlausFld;                              */
/*  input boolean SenO2Ds_bMonWaitRaw_DsPlausFld;                             */
/*  output uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;                             */
/*  output uint16 SenO2Ds_FldPlausFacMin_Obd6Mod;                             */
/*  output boolean SenO2Ds_bMonWaitORng_DsPlausFld;                           */
/*  output boolean SenO2Ds_bMonRunORng_DsPlausFld;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidFldMdEr6(void)
{
   boolean bLocalCfmSenO2DsStuckLean;
   uint16  u16LocalSenO2DsFldPlFcMsOd6Md;
   uint16  u16LocalSenO2DsFldPlFcMnOd6Md;


   bLocalCfmSenO2DsStuckLean = GDGAR_bGetFRM(FRM_FRM_CFMSENO2DSSTUCKLEAN);

   if (bLocalCfmSenO2DsStuckLean != 0)
   {
      u16LocalSenO2DsFldPlFcMsOd6Md = SenO2Ds_FldPlausFacMesRaw;
      u16LocalSenO2DsFldPlFcMnOd6Md = SenO2Ds_FldPlausFacMinRaw;
   }
   else
   {
      if (  (SenO2Ds_bAcvEuro6DsPlausFld_C == 0)
         || (SenO2Ds_bDgoORng_DsPlausFld == 0))
      {
         u16LocalSenO2DsFldPlFcMsOd6Md = SenO2Ds_FldPlausFacMesRaw;
         u16LocalSenO2DsFldPlFcMnOd6Md = SenO2Ds_FldPlausFacMinRaw;
      }
      else
      {
         VEMS_vidGET(SenO2Ds_FldPlausFacMes_Obd6Mod,
                     u16LocalSenO2DsFldPlFcMsOd6Md);
         VEMS_vidGET(SenO2Ds_FldPlausFacMin_Obd6Mod,
                     u16LocalSenO2DsFldPlFcMnOd6Md);
      }
   }
   u16LocalSenO2DsFldPlFcMsOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2DsFldPlFcMsOd6Md, 1024);
   VEMS_vidSET(SenO2Ds_FldPlausFacMes_Obd6Mod,
               u16LocalSenO2DsFldPlFcMsOd6Md);
   u16LocalSenO2DsFldPlFcMnOd6Md =
      (uint16)MATHSRV_udtMIN(u16LocalSenO2DsFldPlFcMnOd6Md, 1024);
   VEMS_vidSET(SenO2Ds_FldPlausFacMin_Obd6Mod,
               u16LocalSenO2DsFldPlFcMnOd6Md);

   if (SenO2Ds_bInhMonWait_PlausFld_C != 0)
   {
      SenO2Ds_bMonWaitORng_DsPlausFld = DIAG_DISPO;
      if (  (SenO2Ds_bMonRunRaw_DsPlausFld != 0)
         && (SenO2Ds_bMonWaitRaw_DsPlausFld == 0))
      {
         SenO2Ds_bMonRunORng_DsPlausFld = 1;
      }
      else
      {
         SenO2Ds_bMonRunORng_DsPlausFld = 0;
      }
   }
   else
   {
      SenO2Ds_bMonWaitORng_DsPlausFld = SenO2Ds_bMonWaitRaw_DsPlausFld;
      SenO2Ds_bMonRunORng_DsPlausFld = SenO2Ds_bMonRunRaw_DsPlausFld;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidDiagIhBva                           */
/* !Description :  Lancement des fonctions de diagnostic                      */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 LsMon_tiCfmSenO2DsDiagFco_C;                                 */
/*  output uint16 LsMon_tiCfmSenO2DsDiagFco;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidDiagIhBva(void)
{
   LsMon_tiCfmSenO2DsDiagFco = LsMon_tiCfmSenO2DsDiagFco_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidtrsvCount                           */
/* !Description :  Vérifier si la consigne de richesse est supérieure ou égale*/
/*                 au créneau riche demandé. Sinon, la demande de créneau est */
/*                 annulée puis relancée après l’écoulement d’une             */
/*                 temporisation.                                             */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 LsMon_tiRStrtItrsvFld;                                       */
/*  output uint16 LsMon_tiRStrtItrsvFld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidtrsvCount(void)
{
   sint32 s32LocalStep;


   s32LocalStep = (sint32)(LsMon_tiRStrtItrsvFld - 1);
   LsMon_tiRStrtItrsvFld = (uint16)MATHSRV_udtCLAMP(s32LocalStep, 0, 5990);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidCheckrMCy                           */
/* !Description :  Vérifier si la consigne de richesse est supérieure ou égale*/
/*                 au créneau riche demandé.Sinon, la demande de créneau est  */
/*                 annulée puis relancée après l’écoulement d’une             */
/*                 temporisation.                                             */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 LsMon_tiRStrtItrsvFld_C;                                     */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output uint16 LsMon_tiRStrtItrsvFld;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidCheckrMCy(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   LsMon_tiRStrtItrsvFld =
      (uint16)MATHSRV_udtMIN(LsMon_tiRStrtItrsvFld_C, 5990);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidtrsvCtBva                           */
/* !Description :  Vérifier si la consigne de richesse est inférieure ou égale*/
/*                 au créneau riche demandé. Sinon, la demande de créneau est */
/*                 annulée puis relancée après l’écoulement d’une             */
/*                 temporisation.                                             */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 LsMon_tiRStrtItrsvFco;                                       */
/*  output uint16 LsMon_tiRStrtItrsvFco;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidtrsvCtBva(void)
{
   sint32 s32LocalStep;


   s32LocalStep = (sint32)(LsMon_tiRStrtItrsvFco - 1);
   LsMon_tiRStrtItrsvFco = (uint16)MATHSRV_udtCLAMP(s32LocalStep, 0, 5990);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  HEATSENO2DSFONCDIAG_vidChMCyBva                            */
/* !Description :  Vérifier si la consigne de richesse est inférieure ou égale*/
/*                 au créneau riche demandé. Sinon, la demande de créneau est */
/*                 annulée puis relancée après l’écoulement d’une             */
/*                 temporisation.                                             */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 LsMon_tiRStrtItrsvFco_C;                                     */
/*  output boolean LsMon_bAcvItrsvSenO2DsDiag;                                */
/*  output uint16 LsMon_tiRStrtItrsvFco;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HEATSENO2DSFONCDIAG_vidChMCyBva(void)
{
   VEMS_vidSET(LsMon_bAcvItrsvSenO2DsDiag, 0);
   LsMon_tiRStrtItrsvFco =
      (uint16)MATHSRV_udtMIN(LsMon_tiRStrtItrsvFco_C, 5990);
}
/*---------------------------- end of file -----------------------------------*/