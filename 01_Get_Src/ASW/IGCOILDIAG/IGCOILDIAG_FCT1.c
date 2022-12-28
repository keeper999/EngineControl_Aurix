/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGCOILDIAG                                              */
/* !Description     : IGCOILDIAG component.                                   */
/*                                                                            */
/* !Module          : IGCOILDIAG                                              */
/* !Description     : DIAGNOSTIC DES BOBINES D’ALLUMAGE                       */
/*                                                                            */
/* !File            : IGCOILDIAG_FCT1.C                                       */
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
/*   1 / IGCOILDIAG_vidCalcIcdDiagEnabled                                     */
/*   2 / IGCOILDIAG_vidCallDiagICD                                            */
/*   3 / IGCOILDIAG_vidCallDiagSdlFast                                        */
/*   4 / IGCOILDIAG_vidDiagnostic                                             */
/*   5 / IGCOILDIAG_vidDiagBob1                                               */
/*   6 / IGCOILDIAG_vidDiagBob2                                               */
/*   7 / IGCOILDIAG_vidDiagBob3                                               */
/*   8 / IGCOILDIAG_vidDiagBob4                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6719446 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGCOILDIAG/IGCOILDIAG_FCT1.C_v    $*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   04 Sep 2014 $*/
/* $Author::   wbouach                                $$Date::   04 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IGCOILDIAG.h"
#include "IGCOILDIAG_L.h"
#include "IGCOILDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidCalcIcdDiagEnabled                           */
/* !Description :  A haut régime ou faible tension batterie, il devient       */
/*                 impossible de diagnostiquer un court-circuit ouvert sur les*/
/*                 bobines.                                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Tension_batterie_filt;                                       */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint16 Seuil_tension_inf_diag_bobine;                               */
/*  input uint8 Seuil_regime_diag_bobine;                                     */
/*  output boolean Icd_diagnostic_enabled;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidCalcIcdDiagEnabled(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint16 u16LocalTension_batterie_filt;

   VEMS_vidGET(Tension_batterie_filt, u16LocalTension_batterie_filt);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   if (  (u16LocalTension_batterie_filt > Seuil_tension_inf_diag_bobine)
      && (u8LocalRegime_moteur_32 < Seuil_regime_diag_bobine))
   {
      Icd_diagnostic_enabled = 1;
   }
   else
   {
      Icd_diagnostic_enabled = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidCallDiagICD                                  */
/* !Description :  Il est inutile de prendre en compte la condition sur       */
/*                 Code_test_action ni celle Srv_stActrTstStatus puisque les  */
/*                 tests actionneurs n’ont lieu que lorsque le moteur est     */
/*                 arrêté (pas de PMB).                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IGCOILDIAG_vidDiagnostic();                              */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input boolean IgCmd_bCallDiagTyp_C;                                       */
/*  input boolean Ext_bDgoOc_IgCoil1Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil1Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil1Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil1Cmd;                                  */
/*  input boolean Ext_bDgoOc_IgCoil2Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil2Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil2Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil2Cmd;                                  */
/*  input boolean Ext_bDgoOc_IgCoil3Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil3Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil3Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil3Cmd;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidCallDiagICD(void)
{
   if (IgCmd_bCallDiagTyp_C == 0)
   {
      IGCOILDIAG_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_OC_IGCOIL1CMD,
                   Ext_bDgoOc_IgCoil1Cmd,
                   Ext_bMonRunOc_IgCoil1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_IGCOIL1CMD,
                   Ext_bDgoScp_IgCoil1Cmd,
                   Ext_bMonRunScp_IgCoil1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_IGCOIL2CMD,
                   Ext_bDgoOc_IgCoil2Cmd,
                   Ext_bMonRunOc_IgCoil2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_IGCOIL2CMD,
                   Ext_bDgoScp_IgCoil2Cmd,
                   Ext_bMonRunScp_IgCoil2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_IGCOIL3CMD,
                   Ext_bDgoOc_IgCoil3Cmd,
                   Ext_bMonRunOc_IgCoil3Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_IGCOIL3CMD,
                   Ext_bDgoScp_IgCoil3Cmd,
                   Ext_bMonRunScp_IgCoil3Cmd,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidCallDiagSdlFast                              */
/* !Description :  call the diagnosis function depending on                   */
/*                 IgCmd_bCallDiagTyp_C, Srv_stActrTstStatus and              */
/*                 Code_test_action.                                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILDIAG_vidDiagnostic();                              */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input st92 Srv_stActrTstStatus;                                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean IgCmd_bCallDiagTyp_C;                                       */
/*  input boolean Ext_bDgoOc_IgCoil1Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil1Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil1Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil1Cmd;                                  */
/*  input boolean Ext_bDgoOc_IgCoil2Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil2Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil2Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil2Cmd;                                  */
/*  input boolean Ext_bDgoOc_IgCoil3Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil3Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil3Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil3Cmd;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidCallDiagSdlFast(void)
{
   uint8 u8LocalSrv_stActrTstStatus;
   uint8 u8LocalCode_test_action;

   VEMS_vidGET(Srv_stActrTstStatus, u8LocalSrv_stActrTstStatus);
   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);

   if ( (IgCmd_bCallDiagTyp_C != 0)
      ||(  (u8LocalSrv_stActrTstStatus == ACTION_EN_COURS)
         &&(  (u8LocalCode_test_action == CODE_TEST_BOBINE_1)
            ||(u8LocalCode_test_action == CODE_TEST_BOBINE_2)
            ||(u8LocalCode_test_action == CODE_TEST_BOBINE_3)
            ||(u8LocalCode_test_action == CODE_TEST_BOBINE_4)))
      )
   {
      IGCOILDIAG_vidDiagnostic();
      GDGAR_vidGdu(GD_DFT_OC_IGCOIL1CMD,
                   Ext_bDgoOc_IgCoil1Cmd,
                   Ext_bMonRunOc_IgCoil1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_IGCOIL1CMD,
                   Ext_bDgoScp_IgCoil1Cmd,
                   Ext_bMonRunScp_IgCoil1Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_IGCOIL2CMD,
                   Ext_bDgoOc_IgCoil2Cmd,
                   Ext_bMonRunOc_IgCoil2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_IGCOIL2CMD,
                   Ext_bDgoScp_IgCoil2Cmd,
                   Ext_bMonRunScp_IgCoil2Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_OC_IGCOIL3CMD,
                   Ext_bDgoOc_IgCoil3Cmd,
                   Ext_bMonRunOc_IgCoil3Cmd,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCP_IGCOIL3CMD,
                   Ext_bDgoScp_IgCoil3Cmd,
                   Ext_bMonRunScp_IgCoil3Cmd,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidDiagnostic                                   */
/* !Description :  Pour garder la transversalité 3 cylindres/4 cylindres,     */
/*                 l'appel au diagnostic se fera pour tous les cylindres à    */
/*                 chaque PMB. Les diagnostics non réalisés seront couverts   */
/*                 par les _bMonRun à 0                                       */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGCOILDIAG_vidDiagBob1();                                */
/*  extf argret void IGCOILDIAG_vidDiagBob2();                                */
/*  extf argret void IGCOILDIAG_vidDiagBob3();                                */
/*  extf argret void IGCOILDIAG_vidDiagBob4();                                */
/*  input uint8 Ext_noCylEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidDiagnostic(void)
{
   uint8 u8LocalExt_noCylEng;

   VEMS_vidGET(Ext_noCylEng, u8LocalExt_noCylEng);

   IGCOILDIAG_vidDiagBob1();
   IGCOILDIAG_vidDiagBob2();
   IGCOILDIAG_vidDiagBob3();

   if (u8LocalExt_noCylEng == 4)
   {
      IGCOILDIAG_vidDiagBob4();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidDiagBob1                                     */
/* !Description :  Fonction du diagnostic du bobine 1                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Dena_scp_bobine1;                                           */
/*  input boolean Dft_scp_bobine1;                                            */
/*  input boolean Dena_oc_bobine1;                                            */
/*  input boolean Dft_oc_bobine1;                                             */
/*  input boolean Dft_scg_bobine1;                                            */
/*  input boolean Dena_scg_bobine1;                                           */
/*  input boolean Icd_diagnostic_enabled;                                     */
/*  output boolean Ext_bMonRunScp_IgCoil1Cmd;                                 */
/*  output boolean Ext_bDgoScp_IgCoil1Cmd;                                    */
/*  output boolean Ext_bMonRunOc_IgCoil1Cmd;                                  */
/*  output boolean Ext_bDgoOc_IgCoil1Cmd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidDiagBob1(void)
{
   boolean bLocalDena_scp_bobine1;
   boolean bLocalDft_scp_bobine1;
   boolean bLocalDena_oc_bobine1;
   boolean bLocalDft_oc_bobine1;
   boolean bLocalDft_scg_bobine1;
   boolean bLocalDena_scg_bobine1;
   boolean bLocalInhIgCoilMngElDiag;

   VEMS_vidGET(Dena_scp_bobine1, bLocalDena_scp_bobine1);
   VEMS_vidGET(Dft_scp_bobine1, bLocalDft_scp_bobine1);
   VEMS_vidGET(Dena_oc_bobine1, bLocalDena_oc_bobine1);
   VEMS_vidGET(Dft_oc_bobine1, bLocalDft_oc_bobine1);
   VEMS_vidGET(Dft_scg_bobine1, bLocalDft_scg_bobine1);
   VEMS_vidGET(Dena_scg_bobine1, bLocalDena_scg_bobine1);
   bLocalInhIgCoilMngElDiag = GDGAR_bGetFRM(FRM_FRM_INHIGCOILMNGELDIAG);

   if (  (bLocalDena_scp_bobine1 != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      Ext_bMonRunScp_IgCoil1Cmd = 1;
      if (bLocalDft_scp_bobine1 != 0)
      {
         Ext_bDgoScp_IgCoil1Cmd = 1;
      }
      else
      {
         Ext_bDgoScp_IgCoil1Cmd = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_IgCoil1Cmd = 0;
      Ext_bDgoScp_IgCoil1Cmd = 0;
   }

   if (  (Icd_diagnostic_enabled != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      if (bLocalDena_oc_bobine1 != 0)
      {
         Ext_bMonRunOc_IgCoil1Cmd = 1;
         if (bLocalDft_oc_bobine1 != 0)
         {
            Ext_bDgoOc_IgCoil1Cmd = 1;
         }
         else
         {
            Ext_bDgoOc_IgCoil1Cmd = 0;
         }
      }
      else
      {
         if (bLocalDena_scg_bobine1 != 0)
         {
            Ext_bMonRunOc_IgCoil1Cmd = 1;
            if (bLocalDft_scg_bobine1 != 0)
            {
               Ext_bDgoOc_IgCoil1Cmd = 1;
            }
            else
            {
               Ext_bDgoOc_IgCoil1Cmd = 0;
            }
         }
         else
         {
            Ext_bMonRunOc_IgCoil1Cmd = 0;
            Ext_bDgoOc_IgCoil1Cmd = 0;
         }
      }
   }
   else
   {
      Ext_bMonRunOc_IgCoil1Cmd = 0;
      Ext_bDgoOc_IgCoil1Cmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidDiagBob2                                     */
/* !Description :  Fonction du diagnostic du bobine 2                         */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Dena_scp_bobine2;                                           */
/*  input boolean Dft_scp_bobine2;                                            */
/*  input boolean Dena_oc_bobine2;                                            */
/*  input boolean Dft_oc_bobine2;                                             */
/*  input boolean Dft_scg_bobine2;                                            */
/*  input boolean Dena_scg_bobine2;                                           */
/*  input boolean Icd_diagnostic_enabled;                                     */
/*  output boolean Ext_bMonRunScp_IgCoil2Cmd;                                 */
/*  output boolean Ext_bDgoScp_IgCoil2Cmd;                                    */
/*  output boolean Ext_bMonRunOc_IgCoil2Cmd;                                  */
/*  output boolean Ext_bDgoOc_IgCoil2Cmd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidDiagBob2(void)
{
   boolean bLocalDena_scp_bobine2;
   boolean bLocalDft_scp_bobine2;
   boolean bLocalDena_oc_bobine2;
   boolean bLocalDft_oc_bobine2;
   boolean bLocalDft_scg_bobine2;
   boolean bLocalDena_scg_bobine2;
   boolean bLocalInhIgCoilMngElDiag;

   VEMS_vidGET(Dena_scp_bobine2, bLocalDena_scp_bobine2);
   VEMS_vidGET(Dft_scp_bobine2, bLocalDft_scp_bobine2);
   VEMS_vidGET(Dena_oc_bobine2, bLocalDena_oc_bobine2);
   VEMS_vidGET(Dft_oc_bobine2, bLocalDft_oc_bobine2);
   VEMS_vidGET(Dft_scg_bobine2, bLocalDft_scg_bobine2);
   VEMS_vidGET(Dena_scg_bobine2, bLocalDena_scg_bobine2);
   bLocalInhIgCoilMngElDiag = GDGAR_bGetFRM(FRM_FRM_INHIGCOILMNGELDIAG);

   if (  (bLocalDena_scp_bobine2 != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      Ext_bMonRunScp_IgCoil2Cmd = 1;
      if (bLocalDft_scp_bobine2 != 0)
      {
         Ext_bDgoScp_IgCoil2Cmd = 1;
      }
      else
      {
         Ext_bDgoScp_IgCoil2Cmd = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_IgCoil2Cmd = 0;
      Ext_bDgoScp_IgCoil2Cmd = 0;
   }

   if (  (Icd_diagnostic_enabled != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      if (bLocalDena_oc_bobine2 != 0)
      {
         Ext_bMonRunOc_IgCoil2Cmd = 1;
         if (bLocalDft_oc_bobine2 != 0)
         {
            Ext_bDgoOc_IgCoil2Cmd = 1;
         }
         else
         {
            Ext_bDgoOc_IgCoil2Cmd = 0;
         }
      }
      else
      {
         if (bLocalDena_scg_bobine2 != 0)
         {
            Ext_bMonRunOc_IgCoil2Cmd = 1;
            if (bLocalDft_scg_bobine2 != 0)
            {
               Ext_bDgoOc_IgCoil2Cmd = 1;
            }
            else
            {
               Ext_bDgoOc_IgCoil2Cmd = 0;
            }
         }
         else
         {
            Ext_bMonRunOc_IgCoil2Cmd = 0;
            Ext_bDgoOc_IgCoil2Cmd = 0;
         }
      }
   }
   else
   {
      Ext_bMonRunOc_IgCoil2Cmd = 0;
      Ext_bDgoOc_IgCoil2Cmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidDiagBob3                                     */
/* !Description :  Fonction du diagnostic du bobine 3                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Dena_scp_bobine3;                                           */
/*  input boolean Dft_scp_bobine3;                                            */
/*  input boolean Dena_oc_bobine3;                                            */
/*  input boolean Dft_oc_bobine3;                                             */
/*  input boolean Dft_scg_bobine3;                                            */
/*  input boolean Dena_scg_bobine3;                                           */
/*  input boolean Icd_diagnostic_enabled;                                     */
/*  output boolean Ext_bMonRunScp_IgCoil3Cmd;                                 */
/*  output boolean Ext_bDgoScp_IgCoil3Cmd;                                    */
/*  output boolean Ext_bMonRunOc_IgCoil3Cmd;                                  */
/*  output boolean Ext_bDgoOc_IgCoil3Cmd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidDiagBob3(void)
{
   boolean bLocalDena_scp_bobine3;
   boolean bLocalDft_scp_bobine3;
   boolean bLocalDena_oc_bobine3;
   boolean bLocalDft_oc_bobine3;
   boolean bLocalDft_scg_bobine3;
   boolean bLocalDena_scg_bobine3;
   boolean bLocalInhIgCoilMngElDiag;

   VEMS_vidGET(Dena_scp_bobine3, bLocalDena_scp_bobine3);
   VEMS_vidGET(Dft_scp_bobine3, bLocalDft_scp_bobine3);
   VEMS_vidGET(Dena_oc_bobine3, bLocalDena_oc_bobine3);
   VEMS_vidGET(Dft_oc_bobine3, bLocalDft_oc_bobine3);
   VEMS_vidGET(Dft_scg_bobine3, bLocalDft_scg_bobine3);
   VEMS_vidGET(Dena_scg_bobine3, bLocalDena_scg_bobine3);
   bLocalInhIgCoilMngElDiag = GDGAR_bGetFRM(FRM_FRM_INHIGCOILMNGELDIAG);

   if (  (bLocalDena_scp_bobine3 != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      Ext_bMonRunScp_IgCoil3Cmd = 1;
      if (bLocalDft_scp_bobine3 != 0)
      {
         Ext_bDgoScp_IgCoil3Cmd = 1;
      }
      else
      {
         Ext_bDgoScp_IgCoil3Cmd = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_IgCoil3Cmd = 0;
      Ext_bDgoScp_IgCoil3Cmd = 0;
   }

   if (  (Icd_diagnostic_enabled != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      if (bLocalDena_oc_bobine3 != 0)
      {
         Ext_bMonRunOc_IgCoil3Cmd = 1;
         if (bLocalDft_oc_bobine3 != 0)
         {
            Ext_bDgoOc_IgCoil3Cmd = 1;
         }
         else
         {
            Ext_bDgoOc_IgCoil3Cmd = 0;
         }
      }
      else
      {
         if (bLocalDena_scg_bobine3 != 0)
         {
            Ext_bMonRunOc_IgCoil3Cmd = 1;
            if (bLocalDft_scg_bobine3 != 0)
            {
               Ext_bDgoOc_IgCoil3Cmd = 1;
            }
            else
            {
               Ext_bDgoOc_IgCoil3Cmd = 0;
            }
         }
         else
         {
            Ext_bMonRunOc_IgCoil3Cmd = 0;
            Ext_bDgoOc_IgCoil3Cmd = 0;
         }
      }
   }
   else
   {
      Ext_bMonRunOc_IgCoil3Cmd = 0;
      Ext_bDgoOc_IgCoil3Cmd = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGCOILDIAG_vidDiagBob4                                     */
/* !Description :  Fonction du diagnostic du bobine 4. La génération des      */
/*                 événements CALL_GduOc_IgCoil4Cmd et CALL_GduScp_IgCoil4Cmd */
/*                 doit se faire après l’appel de l’API DgoHALRead.           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void GDGAR_vidGdu(uint16 u16IdxDft, boolean bDgo, boolean     */
/* bMonRun, boolean Ns_bMonWait);                                             */
/*  input boolean Dena_scp_bobine4;                                           */
/*  input boolean Dft_scp_bobine4;                                            */
/*  input boolean Dena_oc_bobine4;                                            */
/*  input boolean Dft_oc_bobine4;                                             */
/*  input boolean Dft_scg_bobine4;                                            */
/*  input boolean Dena_scg_bobine4;                                           */
/*  input boolean Icd_diagnostic_enabled;                                     */
/*  input boolean Ext_bDgoOc_IgCoil4Cmd;                                      */
/*  input boolean Ext_bMonRunOc_IgCoil4Cmd;                                   */
/*  input boolean Ext_bDgoScp_IgCoil4Cmd;                                     */
/*  input boolean Ext_bMonRunScp_IgCoil4Cmd;                                  */
/*  output boolean Ext_bMonRunScp_IgCoil4Cmd;                                 */
/*  output boolean Ext_bDgoScp_IgCoil4Cmd;                                    */
/*  output boolean Ext_bMonRunOc_IgCoil4Cmd;                                  */
/*  output boolean Ext_bDgoOc_IgCoil4Cmd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGCOILDIAG_vidDiagBob4(void)
{
   boolean bLocalDena_scp_bobine4;
   boolean bLocalDft_scp_bobine4;
   boolean bLocalDena_oc_bobine4;
   boolean bLocalDft_oc_bobine4;
   boolean bLocalDft_scg_bobine4;
   boolean bLocalDena_scg_bobine4;
   boolean bLocalInhIgCoilMngElDiag;

   VEMS_vidGET(Dena_scp_bobine4, bLocalDena_scp_bobine4);
   VEMS_vidGET(Dft_scp_bobine4, bLocalDft_scp_bobine4);
   VEMS_vidGET(Dena_oc_bobine4, bLocalDena_oc_bobine4);
   VEMS_vidGET(Dft_oc_bobine4, bLocalDft_oc_bobine4);
   VEMS_vidGET(Dft_scg_bobine4, bLocalDft_scg_bobine4);
   VEMS_vidGET(Dena_scg_bobine4, bLocalDena_scg_bobine4);
   bLocalInhIgCoilMngElDiag = GDGAR_bGetFRM(FRM_FRM_INHIGCOILMNGELDIAG);

   if (  (bLocalDena_scp_bobine4 != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      Ext_bMonRunScp_IgCoil4Cmd = 1;
      if (bLocalDft_scp_bobine4 != 0)
      {
         Ext_bDgoScp_IgCoil4Cmd = 1;
      }
      else
      {
         Ext_bDgoScp_IgCoil4Cmd = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_IgCoil4Cmd = 0;
      Ext_bDgoScp_IgCoil4Cmd = 0;
   }

   if (  (Icd_diagnostic_enabled != 0)
      && (bLocalInhIgCoilMngElDiag == 0))
   {
      if (bLocalDena_oc_bobine4 != 0)
      {
         Ext_bMonRunOc_IgCoil4Cmd = 1;
         if (bLocalDft_oc_bobine4 != 0)
         {
            Ext_bDgoOc_IgCoil4Cmd = 1;
         }
         else
         {
            Ext_bDgoOc_IgCoil4Cmd = 0;
         }
      }
      else
      {
         if (bLocalDena_scg_bobine4 != 0)
         {
            Ext_bMonRunOc_IgCoil4Cmd = 1;
            if (bLocalDft_scg_bobine4 != 0)
            {
               Ext_bDgoOc_IgCoil4Cmd = 1;
            }
            else
            {
               Ext_bDgoOc_IgCoil4Cmd = 0;
            }
         }
         else
         {
            Ext_bMonRunOc_IgCoil4Cmd = 0;
            Ext_bDgoOc_IgCoil4Cmd = 0;
         }
      }
   }
   else
   {
      Ext_bMonRunOc_IgCoil4Cmd = 0;
      Ext_bDgoOc_IgCoil4Cmd = 0;
   }

   GDGAR_vidGdu(GD_DFT_OC_IGCOIL4CMD,
                Ext_bDgoOc_IgCoil4Cmd,
                Ext_bMonRunOc_IgCoil4Cmd,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_SCP_IGCOIL4CMD,
                Ext_bDgoScp_IgCoil4Cmd,
                Ext_bMonRunScp_IgCoil4Cmd,
                DIAG_DISPO);
}

/*---------------------------------end of file--------------------------------*/