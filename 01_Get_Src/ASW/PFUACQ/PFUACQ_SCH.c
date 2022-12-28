/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PFUACQ                                                  */
/* !Description     : PFUACQ Component                                        */
/*                                                                            */
/* !Module          : PFUACQ                                                  */
/* !Description     : PFuAcq: FUEL RAIL PRESSURE ACQUISITION (GDI)            */
/*                                                                            */
/* !File            : PFUACQ_SCH.C                                            */
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
/*   1 / FuAcq_EveRst_PFuAcq                                                  */
/*   2 / FuAcq_SdlFast_PFuAcq                                                 */
/*   3 / FuAcq_EveSpl_PFuAcq                                                  */
/*   4 / FuAcq_EveInj_PFuAcq                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_6851391 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/PFUACQ/PFUACQ_SCH.C_v           $*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   01 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   01 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "PFUACQ.h"
#include "PFUACQ_L.h"
#include "PFUACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_EveRst_PFuAcq                                        */
/* !Description :  Reset event                                                */
/* !Number      :  SCH.1                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  VEMS_R_10_04228_001.01                                     */
/*                 VEMS_R_10_04228_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PFUACQ_vidInit();                                        */
/*  extf argret void PFUACQ_vidInitOutputs();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_EveRst_PFuAcq                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_EveRst_PFuAcq(void)
{
   PFUACQ_vidInit();
   PFUACQ_vidInitOutputs();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_SdlFast_PFuAcq                                       */
/* !Description :  Fast monitor for rail pressure acquisition                 */
/* !Number      :  SCH.2                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  VEMS_R_10_04228_001.01                                     */
/*                 VEMS_R_10_04228_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PFUACQ_vidSpill();                                       */
/*  extf argret void PFUACQ_vidInj();                                         */
/*  extf argret void PFUACQ_vidRailPressureDiagnosis();                       */
/*  extf argret void PFUACQ_vidRailSplPressureTreat();                        */
/*  extf argret void PFUACQ_vidRailInjPressureTreat();                        */
/*  extf argret void PFUACQ_vidPrevRailSplPressureVal();                      */
/*  extf argret void PFUACQ_vidPrevEveInjPressureVal();                       */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 PFUACQ_u8Inhib;                                               */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*  input boolean Moteur_synchronise;                                         */
/*  input boolean Ext_bRun;                                                   */
/*  input boolean Ext_bDgoScp_PFuAcq;                                         */
/*  input boolean Ext_bMonRunScp_PFuAcq;                                      */
/*  input boolean Ext_bDgoScg_PFuAcq;                                         */
/*  input boolean Ext_bMonRunScg_PFuAcq;                                      */
/*  input boolean Ext_bDgoCoh_PFuAcq;                                         */
/*  input boolean Ext_bMonRunCoh_PFuAcq;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_SdlFast_PFuAcq                                           */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_SdlFast_PFuAcq(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;
   boolean bLocalMoteur_synchronise;
   boolean bLocalExt_bRun;


   if (PFUACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);
      VEMS_vidGET(Moteur_synchronise, bLocalMoteur_synchronise);
      VEMS_vidGET(Ext_bRun, bLocalExt_bRun);

      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         if (  (bLocalMoteur_synchronise == 0)
            && (bLocalExt_bRun == 0))
         {
            PFUACQ_vidSpill();
            PFUACQ_vidInj();
            PFUACQ_vidRailPressureDiagnosis();
            PFUACQ_vidRailSplPressureTreat();
            PFUACQ_vidRailInjPressureTreat();
            PFUACQ_vidPrevRailSplPressureVal();
            PFUACQ_vidPrevEveInjPressureVal();
         }
         else
         {
            if (  (bLocalMoteur_synchronise != 0)
               && (bLocalExt_bRun == 0))
            {
               PFUACQ_vidInj();
               PFUACQ_vidRailPressureDiagnosis();
               PFUACQ_vidRailInjPressureTreat();
               PFUACQ_vidPrevEveInjPressureVal();
            }
            else
            {
               if (  (bLocalMoteur_synchronise == 0)
                  && (bLocalExt_bRun != 0))
               {
                  PFUACQ_vidSpill();
                  PFUACQ_vidRailSplPressureTreat();
                  PFUACQ_vidPrevRailSplPressureVal();
               }
            }
         }
         GDGAR_vidGdu(GD_DFT_SCP_PFUACQ,
                      Ext_bDgoScp_PFuAcq,
                      Ext_bMonRunScp_PFuAcq,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_SCG_PFUACQ,
                      Ext_bDgoScg_PFuAcq,
                      Ext_bMonRunScg_PFuAcq,
                      DIAG_DISPO);
         GDGAR_vidGdu(GD_DFT_COH_PFUACQ,
                      Ext_bDgoCoh_PFuAcq,
                      Ext_bMonRunCoh_PFuAcq,
                      DIAG_DISPO);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_EveSpl_PFuAcq                                        */
/* !Description :  Spill event                                                */
/* !Number      :  SCH.3                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  VEMS_R_10_04228_001.01                                     */
/*                 VEMS_R_10_04228_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PFUACQ_vidSpill();                                       */
/*  extf argret void PFUACQ_vidRailPressureDiagnosis();                       */
/*  extf argret void PFUACQ_vidRailSplPressureTreat();                        */
/*  extf argret void PFUACQ_vidPrevRailSplPressureVal();                      */
/*  input uint8 PFUACQ_u8Inhib;                                               */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_EveSpl_PFuAcq                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_EveSpl_PFuAcq(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;


   if (PFUACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);

      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         PFUACQ_vidSpill();
         PFUACQ_vidRailPressureDiagnosis();
         PFUACQ_vidRailSplPressureTreat();
         PFUACQ_vidPrevRailSplPressureVal();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FuAcq_EveInj_PFuAcq                                        */
/* !Description :  INJ task for the rail pressure acquisition                 */
/* !Number      :  SCH.4                                                      */
/* !Author      :  I.JEMAÏ                                                    */
/* !Trace_To    :  VEMS_R_10_04228_001.01                                     */
/*                 VEMS_R_10_04228_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void PFUACQ_vidInj();                                         */
/*  extf argret void PFUACQ_vidRailPressureDiagnosis();                       */
/*  extf argret void PFUACQ_vidRailInjPressureTreat();                        */
/*  extf argret void PFUACQ_vidPrevEveInjPressureVal();                       */
/*  input uint8 PFUACQ_u8Inhib;                                               */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : FuAcq_EveInj_PFuAcq                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FuAcq_EveInj_PFuAcq(void)
{
   boolean bLocalCtrl_bAcv_PFuAcq;


   if (PFUACQ_u8Inhib != 0x5A)
   {
      VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);

      if (bLocalCtrl_bAcv_PFuAcq != 0)
      {
         PFUACQ_vidInj();
         PFUACQ_vidRailPressureDiagnosis();
         PFUACQ_vidRailInjPressureTreat();
         PFUACQ_vidPrevEveInjPressureVal();
      }
   }
}
/*---------------------------- end of file -----------------------------------*/