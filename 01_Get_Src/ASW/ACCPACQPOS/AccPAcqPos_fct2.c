/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AccP                                                    */
/* !Description     : AccP component.                                         */
/*                                                                            */
/* !Module          : ACCPACQPOS                                              */
/* !Description     : Acquisition de la position pedale                       */
/*                                                                            */
/* !File            : ACCPACQPOS_FCT2.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / ACCPACQPOS_vidElectCoherence                                         */
/*   2 / ACCPACQPOS_vidDiagnosticCoh                                          */
/*   3 / ACCPACQPOS_vidInitOutput                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6601121 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/ACCP/ACCPACQPOS/ACCPACQPOS_FCT2.c_$*/
/* $Revision::   1.9      $$Author::   achebino       $$Date::   23 Sep 2014 $*/
/* $Author::   achebino                               $$Date::   23 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ACCPACQPOS.h"
#include "ACCPACQPOS_L.h"
#include "ACCPACQPOS_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPACQPOS_vidElectCoherence                               */
/* !Description :  En cas de défaut sur la batterie, la détection de défaut   */
/*                 est inhibée ; dans le cas d'un  défaut sur les             */
/*                 alimentations capteurs, la détection de défaut est inhibée */
/*                 sur le groupe de capteurs alimenté par l'alimentation en   */
/*                 défaut.                                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  VEMS_R_5197989_014.02                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf argret void ACCPACQPOS_vidDiagnosticCoh();                           */
/*  input boolean Ext_bMonRunScpOc_Ped1;                                      */
/*  input boolean Ext_bMonRunScg_Ped1;                                        */
/*  input boolean Ext_bMonRunScpOc_Ped2;                                      */
/*  input boolean Ext_bMonRunScg_Ped2;                                        */
/*  input boolean Ext_bDgoScpOc_Ped1;                                         */
/*  input boolean Ext_bDgoScg_Ped1;                                           */
/*  input boolean Ext_bDgoScpOc_Ped2;                                         */
/*  input boolean Ext_bDgoScg_Ped2;                                           */
/*  output boolean Ext_bMonRunCoh_Ped;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPACQPOS_vidElectCoherence(void)
{
   boolean bLocalInhCohPed;


   bLocalInhCohPed  = GDGAR_bGetFRM(FRM_FRM_INHCOHPED);

   if (  (Ext_bMonRunScpOc_Ped1 != 0)
      && (Ext_bMonRunScg_Ped1 != 0)
      && (Ext_bMonRunScpOc_Ped2 != 0)
      && (Ext_bMonRunScg_Ped2 != 0)
      && (Ext_bDgoScpOc_Ped1 == 0)
      && (Ext_bDgoScg_Ped1 == 0)
      && (Ext_bDgoScpOc_Ped2 == 0)
      && (Ext_bDgoScg_Ped2 == 0)
      && (bLocalInhCohPed == 0))
   {
      ACCPACQPOS_vidDiagnosticCoh();
      Ext_bMonRunCoh_Ped = 1;
   }
   else
   {
      Ext_bMonRunCoh_Ped = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPACQPOS_vidDiagnosticCoh                                */
/* !Description :  Fonction permettant de vérifier la cohérence électrique des*/
/*                 deux signaux, en les comparant. La comparaison est         */
/*                 effectuée avec la valeur absolue filtrée de la différence  */
/*                 entre les deux mesures.                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/* !Trace_To    :  PTS_R_6601121_006.001                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Acqui_position_pedale_1;                                     */
/*  input uint16 Acqui_position_pedale_2;                                     */
/*  input uint16 AccP_uThdCohSens_C;                                          */
/*  output boolean Ext_bDgoCoh_Ped;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPACQPOS_vidDiagnosticCoh(void)
{
   uint16 u16LocalAcqui_position_pedale_1;
   uint16 u16LocalAcqui_position_pedale_2;
   uint32 u32LocalAccP_uThdCohSens_C;
   uint32 u32LocalPosition;
   sint32 s32LocalAcqui_position_pedale_2;
   sint32 s32LocalPosition;


   VEMS_vidGET(Acqui_position_pedale_1, u16LocalAcqui_position_pedale_1);
   VEMS_vidGET(Acqui_position_pedale_2, u16LocalAcqui_position_pedale_2);

   s32LocalAcqui_position_pedale_2 = (sint32)( u16LocalAcqui_position_pedale_2
                                             * 2);
   s32LocalPosition = ( u16LocalAcqui_position_pedale_1
                      - s32LocalAcqui_position_pedale_2);
   u32LocalPosition = (uint32)MATHSRV_udtABS(s32LocalPosition);

   u32LocalAccP_uThdCohSens_C = (uint32)(AccP_uThdCohSens_C * 4);
   if (u32LocalPosition > u32LocalAccP_uThdCohSens_C)
   {
      Ext_bDgoCoh_Ped = 1;
   }
   else
   {
      Ext_bDgoCoh_Ped = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACCPACQPOS_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Ext_bDgoCoh_Ped;                                           */
/*  output boolean Ext_bMonRunCoh_Ped;                                        */
/*  output boolean Ext_bDgoScpOc_Ped2;                                        */
/*  output boolean Ext_bMonRunScpOc_Ped2;                                     */
/*  output boolean Ext_bDgoScg_Ped2;                                          */
/*  output boolean Ext_bMonRunScg_Ped2;                                       */
/*  output boolean Ext_bDgoScpOc_Ped1;                                        */
/*  output boolean Ext_bMonRunScpOc_Ped1;                                     */
/*  output boolean Ext_bDgoScg_Ped1;                                          */
/*  output boolean Ext_bMonRunScg_Ped1;                                       */
/*  output boolean Ext_bDgoDftSenr_AccP;                                      */
/*  output boolean Ext_bMonRunDftSenr_AccP;                                   */
/*  output boolean ACCPACQPOS_bInitFilter1;                                   */
/*  output boolean ACCPACQPOS_bInitFilter2;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACCPACQPOS_vidInitOutput(void)
{
   Ext_bDgoCoh_Ped = 0;
   Ext_bMonRunCoh_Ped = 0;
   Ext_bDgoScpOc_Ped2 = 0;
   Ext_bMonRunScpOc_Ped2 = 0;
   Ext_bDgoScg_Ped2 = 0;
   Ext_bMonRunScg_Ped2 = 0;
   Ext_bDgoScpOc_Ped1 = 0;
   Ext_bMonRunScpOc_Ped1 = 0;
   Ext_bDgoScg_Ped1 = 0;
   Ext_bMonRunScg_Ped1 = 0;
   Ext_bDgoDftSenr_AccP = 0;
   Ext_bMonRunDftSenr_AccP = 0;
   ACCPACQPOS_bInitFilter1 = 0;
   ACCPACQPOS_bInitFilter2 = 0;
}
/*---------------------------- end of file -----------------------------------*/