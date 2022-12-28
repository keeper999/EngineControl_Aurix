/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGSTOUTPIDC                                            */
/* !Description     : ENGSTOUTPIDC Component                                  */
/*                                                                            */
/* !Module          : ENGSTOUTPIDC                                            */
/* !Description     : SORTIE FILAIRE MOTEUR TOURNANT                          */
/*                                                                            */
/* !File            : ENGSTOUTPIDC_FCT1.C                                     */
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
/*   1 / ENGSTOUTPIDC_vidInit                                                 */
/*   2 / ENGSTOUTPIDC_vidEngineRunningInfo                                    */
/*   3 / ENGSTOUTPIDC_vidDiagOutput                                           */
/*   4 / ENGSTOUTPIDC_vidElectricDiag                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6528229 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ENGSTOUTPIDC/ENGSTOUTPIDC_FCT1.C_v$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   22 May 2014 $*/
/* $Author::   wbouach                                $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "ENGSTOUTPIDC.h"
#include "ENGSTOUTPIDC_L.h"
#include "ENGSTOUTPIDC_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTOUTPIDC_vidInit                                       */
/* !Description :  Initialisation du variable Info_moteur_tournant            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bEngRun_Archi2010EcoPush;                               */
/*  input boolean EngSt_bIniEngRun_Archi2010_C;                               */
/*  input boolean EngSt_bIniEngRun_NotArchi2010_C;                            */
/*  output boolean Info_moteur_tournant;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTOUTPIDC_vidInit(void)
{
   boolean bLocalExt_bEgRn_Archi2010EcoPush;


   VEMS_vidGET(Ext_bEngRun_Archi2010EcoPush, bLocalExt_bEgRn_Archi2010EcoPush);
   if (bLocalExt_bEgRn_Archi2010EcoPush != 0)
   {
      Info_moteur_tournant = EngSt_bIniEngRun_Archi2010_C;
   }
   else
   {
      Info_moteur_tournant = EngSt_bIniEngRun_NotArchi2010_C;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTOUTPIDC_vidEngineRunningInfo                          */
/* !Description :  Moteur tournant : Info_MotTournant=1; Moteur à l'arrêt :   */
/*                 Info_MotTournant=0                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Eng_st_output_test_bed_mode;                                */
/*  input boolean Eng_st_output_for_test_bed;                                 */
/*  input boolean CoPTSt_bEngRunSTT;                                          */
/*  output boolean Info_moteur_tournant;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTOUTPIDC_vidEngineRunningInfo(void)
{
   boolean bLocalCoPTSt_bEngRunSTT;


   if (Eng_st_output_test_bed_mode != 0)
   {
      Info_moteur_tournant = Eng_st_output_for_test_bed;
   }
   else
   {
      VEMS_vidGET(CoPTSt_bEngRunSTT, bLocalCoPTSt_bEngRunSTT);
      Info_moteur_tournant = bLocalCoPTSt_bEngRunSTT;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTOUTPIDC_vidDiagOutput                                 */
/* !Description :  En cas de défaut sur la batterie, la détection des défauts */
/*                 électriques est inhibée ; dans le  cas d'un défaut sur les */
/*                 alimentations capteurs, la détection de défaut est inhibée */
/*                 sur le groupe de capteurs alimenté par l'alimentation en   */
/*                 défaut.                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_12_01048_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bEngRun_Archi2010EcoPush;                               */
/*  input boolean Info_moteur_tournant;                                       */
/*  input boolean Config_info_moteur_tournant;                                */
/*  input boolean Info_moteur_tournant_applique;                              */
/*  output boolean CoPTStHw_bEngRunSTT;                                       */
/*  output boolean Info_moteur_tournant_applique;                             */
/*  output boolean Cmde_info_moteur_tournant_tor;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTOUTPIDC_vidDiagOutput(void)
{
   boolean bLocalExt_bEgRn_Archi2010EcoPush;
   boolean bLocalCoPTStHw_bEngRunSTT;


   VEMS_vidGET(Ext_bEngRun_Archi2010EcoPush, bLocalExt_bEgRn_Archi2010EcoPush);
   if (Info_moteur_tournant == bLocalExt_bEgRn_Archi2010EcoPush)
   {
      bLocalCoPTStHw_bEngRunSTT = 1;
   }
   else
   {
      bLocalCoPTStHw_bEngRunSTT = 0;
   }
   VEMS_vidSET(CoPTStHw_bEngRunSTT, bLocalCoPTStHw_bEngRunSTT);

   if (Config_info_moteur_tournant != 0)
   {
      if (bLocalCoPTStHw_bEngRunSTT != 0)
      {
         Info_moteur_tournant_applique = 0;
      }
      else
      {
         Info_moteur_tournant_applique = 1;
      }
   }
   else
   {
      Info_moteur_tournant_applique = bLocalCoPTStHw_bEngRunSTT;
   }

   VEMS_vidSET(Cmde_info_moteur_tournant_tor, Info_moteur_tournant_applique);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGSTOUTPIDC_vidElectricDiag                               */
/* !Description :  fonction de diagnostic électrique.                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_12_01048_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPTStHw_bEngRunSTT;                                        */
/*  input boolean Dena_oc_infomoteurtournant;                                 */
/*  input boolean Dena_scg_infomoteurtournant;                                */
/*  input boolean Dena_scp_infomoteurtournant;                                */
/*  input boolean Dft_oc_infomoteurtournant;                                  */
/*  input boolean Dft_scg_infomoteurtournant;                                 */
/*  input boolean Dft_scp_infomoteurtournant;                                 */
/*  input boolean Ext_bMonRunOc_EngStOutIdc;                                  */
/*  input boolean Ext_bMonRunScg_EngStOutIdc;                                 */
/*  input boolean Ext_bMonRunScp_EngStOutIdc;                                 */
/*  output boolean Ext_bMonRunOc_EngStOutIdc;                                 */
/*  output boolean Ext_bMonRunScg_EngStOutIdc;                                */
/*  output boolean Ext_bMonRunScp_EngStOutIdc;                                */
/*  output boolean Ext_bDgoOc_EngStOutIdc;                                    */
/*  output boolean Ext_bDgoScg_EngStOutIdc;                                   */
/*  output boolean Ext_bDgoScp_EngStOutIdc;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGSTOUTPIDC_vidElectricDiag(void)
{
   boolean bLocalInhEngStOutIdcDiagEl;
   boolean bLocalCoPTStHw_bEngRunSTT;
   boolean bLocalDena_oc_infomoteurtournant;
   boolean bLocalDena_scg_infmoteurtournant;
   boolean bLocalDena_scp_infmoteurtournant;
   boolean bLocalDft_oc_infomoteurtournant;
   boolean bLocalDft_scg_infomoteurtournant;
   boolean bLocalDft_scp_infomoteurtournant;


   bLocalInhEngStOutIdcDiagEl = GDGAR_bGetFRM(FRM_FRM_INHENGSTOUTIDCDIAGEL);
   VEMS_vidGET(CoPTStHw_bEngRunSTT, bLocalCoPTStHw_bEngRunSTT);
   VEMS_vidGET(Dena_oc_infomoteurtournant, bLocalDena_oc_infomoteurtournant);
   VEMS_vidGET(Dena_scg_infomoteurtournant, bLocalDena_scg_infmoteurtournant);
   VEMS_vidGET(Dena_scp_infomoteurtournant, bLocalDena_scp_infmoteurtournant);
   VEMS_vidGET(Dft_oc_infomoteurtournant, bLocalDft_oc_infomoteurtournant);
   VEMS_vidGET(Dft_scg_infomoteurtournant, bLocalDft_scg_infomoteurtournant);
   VEMS_vidGET(Dft_scp_infomoteurtournant, bLocalDft_scp_infomoteurtournant);

   if (bLocalInhEngStOutIdcDiagEl == 0)
   {
      if (bLocalCoPTStHw_bEngRunSTT != 0)
      {
         Ext_bMonRunOc_EngStOutIdc = 0;
         Ext_bMonRunScg_EngStOutIdc = 0;
         Ext_bMonRunScp_EngStOutIdc = 1;
      }
      else
      {
         Ext_bMonRunOc_EngStOutIdc = 1;
         Ext_bMonRunScg_EngStOutIdc = 1;
         Ext_bMonRunScp_EngStOutIdc = 0;
      }
   }
   else
   {
      Ext_bMonRunOc_EngStOutIdc = 0;
      Ext_bMonRunScg_EngStOutIdc = 0;
      Ext_bMonRunScp_EngStOutIdc = 0;
   }

   if (  (Ext_bMonRunOc_EngStOutIdc != 0)
      && (bLocalDena_oc_infomoteurtournant != 0)
      && (bLocalDft_oc_infomoteurtournant != 0))
   {
      Ext_bDgoOc_EngStOutIdc = 1;
   }
   else
   {
      Ext_bDgoOc_EngStOutIdc = 0;
   }

   if (  (Ext_bMonRunScg_EngStOutIdc != 0)
      && (bLocalDena_scg_infmoteurtournant != 0)
      && (bLocalDft_scg_infomoteurtournant != 0))
   {
      Ext_bDgoScg_EngStOutIdc = 1;
   }
   else
   {
      Ext_bDgoScg_EngStOutIdc = 0;
   }

   if (  (Ext_bMonRunScp_EngStOutIdc != 0)
      && (bLocalDena_scp_infmoteurtournant != 0)
      && (bLocalDft_scp_infomoteurtournant != 0))
   {
      Ext_bDgoScp_EngStOutIdc = 1;
   }
   else
   {
      Ext_bDgoScp_EngStOutIdc = 0;
   }
}
/*------------------------------- end of file --------------------------------*/