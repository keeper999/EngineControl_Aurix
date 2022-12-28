/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFFAICTR                                              */
/* !Description     : MISFFAICTR component.                                   */
/*                                                                            */
/* !Module          : MISFFAICTR                                              */
/* !Description     : Comptage Des Misfires Pour Les Emissions De Polluants Et*/
/*                    La Protection Composants .                              */
/*                                                                            */
/* !File            : MISFFAICTR_FCT7.C                                       */
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
/*   1 / MISFFAICTR_vidMisfireDefault                                         */
/*   2 / MISFFAICTR_vidEssenceDefault                                         */
/*   3 / MISFFAICTR_vidGazDefault                                             */
/*   4 / MISFFAICTR_vidFuelLowLevelComput                                     */
/*   5 / MISFFAICTR_vidMisfFaiCtrEnable                                       */
/*   6 / MISFFAICTR_vidInhDetNoMisfEnable                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT7.C_$*/
/* $Revision::   1.9      $$Author::   wbouach        $$Date::   19 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MISFFAICTR.h"
#include "MISFFAICTR_L.h"
#include "MISFFAICTR_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMisfireDefault                               */
/* !Description :  Ce bloc détermine la gestion des défauts de ratés de       */
/*                 combustion qui doit être distincte entre un fonctionnement */
/*                 au gaz et un fonctionnement en essence.                    */
/* !Number      :  FCT7.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_09_00890_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFFAICTR_vidGazDefault();                              */
/*  extf argret void MISFFAICTR_vidEssenceDefault();                          */
/*  input boolean Ext_bPresGaz_C;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMisfireDefault(void)
{
   if (Ext_bPresGaz_C != 0)
   {
      MISFFAICTR_vidGazDefault();
   }
   else
   {
      MISFFAICTR_vidEssenceDefault();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidEssenceDefault                               */
/* !Description :  Ce bloc détermine la gestion des défauts de ratés de       */
/*                 combustion durant le fonctionnement en essence.            */
/* !Number      :  FCT7.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin  boolean       */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait) ;                    */
/*  input boolean Mf_cat_dam_horizon_uavb0;                                   */
/*  input boolean Mf_emiss_horizon_uavb0;                                     */
/*  input boolean Misf_bDgoORngDmgCat1;                                       */
/*  input boolean Misf_bMonRunORngDmgCat1;                                    */
/*  input boolean Misf_bDgoORngDmgCat2;                                       */
/*  input boolean Misf_bMonRunORngDmgCat2;                                    */
/*  input boolean Misf_bDgoORngDmgCat3;                                       */
/*  input boolean Misf_bMonRunORngDmgCat3;                                    */
/*  input boolean Misf_bDgoORngDmgCat4;                                       */
/*  input boolean Misf_bMonRunORngDmgCat4;                                    */
/*  input boolean Misf_bDgoORngDmgCatMDAll;                                   */
/*  input boolean Misf_bMonRunORngDmgCatMDAll;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC1;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC2;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC3;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC4;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTCAll;                              */
/*  input boolean Misf_bDgoORngMisfEmi1;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi1;                                   */
/*  input boolean Misf_bDgoORngMisfEmi2;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi2;                                   */
/*  input boolean Misf_bDgoORngMisfEmi3;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi3;                                   */
/*  input boolean Misf_bDgoORngMisfEmi4;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi4;                                   */
/*  input boolean Misf_bDgoORngMisfEmiAll;                                    */
/*  input boolean Misf_bMonRunORngMisfEmiAll;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidEssenceDefault(void)
{
   boolean bLocalMf_cat_dam_horizon_uavb0;
   boolean bLocalMf_emiss_horizon_uavb0;


   VEMS_vidGET(Mf_cat_dam_horizon_uavb0, bLocalMf_cat_dam_horizon_uavb0);
   VEMS_vidGET(Mf_emiss_horizon_uavb0, bLocalMf_emiss_horizon_uavb0);

   if (bLocalMf_cat_dam_horizon_uavb0 != 0)
   {
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMD1,
                   Misf_bDgoORngDmgCat1,
                   Misf_bMonRunORngDmgCat1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMD2,
                   Misf_bDgoORngDmgCat2,
                   Misf_bMonRunORngDmgCat2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMD3,
                   Misf_bDgoORngDmgCat3,
                   Misf_bMonRunORngDmgCat3,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMD4,
                   Misf_bDgoORngDmgCat4,
                   Misf_bMonRunORngDmgCat4,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMDALL,
                   Misf_bDgoORngDmgCatMDAll,
                   Misf_bMonRunORngDmgCatMDAll,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTC1,
                   Misf_bDgoORngDmgCat1,
                   Misf_bMonRunORngDmgCat1,
                   Misf_bMonWaitORngDmgCatDTC1);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTC2,
                   Misf_bDgoORngDmgCat2,
                   Misf_bMonRunORngDmgCat2,
                   Misf_bMonWaitORngDmgCatDTC2);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTC3,
                   Misf_bDgoORngDmgCat3,
                   Misf_bMonRunORngDmgCat3,
                   Misf_bMonWaitORngDmgCatDTC3);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTC4,
                   Misf_bDgoORngDmgCat4,
                   Misf_bMonRunORngDmgCat4,
                   Misf_bMonWaitORngDmgCatDTC4);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTCALL,
                   Misf_bDgoORngDmgCatMDAll,
                   Misf_bMonRunORngDmgCatMDAll,
                   Misf_bMonWaitORngDmgCatDTCAll);
   }
   if(bLocalMf_emiss_horizon_uavb0 != 0)
   {
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMI1,
                   Misf_bDgoORngMisfEmi1,
                   Misf_bMonRunORngMisfEmi1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMI2,
                   Misf_bDgoORngMisfEmi2,
                   Misf_bMonRunORngMisfEmi2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMI3,
                   Misf_bDgoORngMisfEmi3,
                   Misf_bMonRunORngMisfEmi3,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMI4,
                   Misf_bDgoORngMisfEmi4,
                   Misf_bMonRunORngMisfEmi4,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMIALL,
                   Misf_bDgoORngMisfEmiAll,
                   Misf_bMonRunORngMisfEmiAll,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidGazDefault                                   */
/* !Description :  Ce bloc détermine la gestion des défauts de ratés de       */
/*                 combustion durant le fonctionnement au gaz.                */
/* !Number      :  FCT7.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin  boolean       */
/* bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait) ;                    */
/*  input boolean Mf_cat_dam_horizon_uavb0;                                   */
/*  input boolean Mf_emiss_horizon_uavb0;                                     */
/*  input boolean Misf_bDgoORngDmgCat1;                                       */
/*  input boolean Misf_bMonRunORngDmgCat1;                                    */
/*  input boolean Misf_bDgoORngDmgCat2;                                       */
/*  input boolean Misf_bMonRunORngDmgCat2;                                    */
/*  input boolean Misf_bDgoORngDmgCat3;                                       */
/*  input boolean Misf_bMonRunORngDmgCat3;                                    */
/*  input boolean Misf_bDgoORngDmgCat4;                                       */
/*  input boolean Misf_bMonRunORngDmgCat4;                                    */
/*  input boolean Misf_bDgoORngDmgCatMDAll;                                   */
/*  input boolean Misf_bMonRunORngDmgCatMDAll;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC1;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC2;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC3;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTC4;                                */
/*  input boolean Misf_bMonWaitORngDmgCatDTCAll;                              */
/*  input boolean Misf_bDgoORngMisfEmi1;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi1;                                   */
/*  input boolean Misf_bDgoORngMisfEmi2;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi2;                                   */
/*  input boolean Misf_bDgoORngMisfEmi3;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi3;                                   */
/*  input boolean Misf_bDgoORngMisfEmi4;                                      */
/*  input boolean Misf_bMonRunORngMisfEmi4;                                   */
/*  input boolean Misf_bDgoORngMisfEmiAll;                                    */
/*  input boolean Misf_bMonRunORngMisfEmiAll;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidGazDefault(void)
{
   boolean bLocalMf_cat_dam_horizon_uavb0;
   boolean bLocalMf_emiss_horizon_uavb0;


   VEMS_vidGET(Mf_cat_dam_horizon_uavb0, bLocalMf_cat_dam_horizon_uavb0);
   VEMS_vidGET(Mf_emiss_horizon_uavb0, bLocalMf_emiss_horizon_uavb0);

   if (bLocalMf_cat_dam_horizon_uavb0 != 0)
   {
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMDGAZ1,
                   Misf_bDgoORngDmgCat1,
                   Misf_bMonRunORngDmgCat1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMDGAZ2,
                   Misf_bDgoORngDmgCat2,
                   Misf_bMonRunORngDmgCat2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMDGAZ3,
                   Misf_bDgoORngDmgCat3,
                   Misf_bMonRunORngDmgCat3,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMDGAZ4,
                   Misf_bDgoORngDmgCat4,
                   Misf_bMonRunORngDmgCat4,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATMDGAZALL,
                   Misf_bDgoORngDmgCatMDAll,
                   Misf_bMonRunORngDmgCatMDAll,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTCGAZ1,
                   Misf_bDgoORngDmgCat1,
                   Misf_bMonRunORngDmgCat1,
                   Misf_bMonWaitORngDmgCatDTC1);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTCGAZ2,
                   Misf_bDgoORngDmgCat2,
                   Misf_bMonRunORngDmgCat2,
                   Misf_bMonWaitORngDmgCatDTC2);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTCGAZ3,
                   Misf_bDgoORngDmgCat3,
                   Misf_bMonRunORngDmgCat3,
                   Misf_bMonWaitORngDmgCatDTC3);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTCGAZ4,
                   Misf_bDgoORngDmgCat4,
                   Misf_bMonRunORngDmgCat4,
                   Misf_bMonWaitORngDmgCatDTC4);
      GDGAR_vidGdu(GD_DFT_ORNGDMGCATDTCGAZALL,
                   Misf_bDgoORngDmgCatMDAll,
                   Misf_bMonRunORngDmgCatMDAll,
                   Misf_bMonWaitORngDmgCatDTCAll);
   }
   if(bLocalMf_emiss_horizon_uavb0 != 0)
   {
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMIGAZ1,
                   Misf_bDgoORngMisfEmi1,
                   Misf_bMonRunORngMisfEmi1,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMIGAZ2,
                   Misf_bDgoORngMisfEmi2,
                   Misf_bMonRunORngMisfEmi2,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMIGAZ3,
                   Misf_bDgoORngMisfEmi3,
                   Misf_bMonRunORngMisfEmi3,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMIGAZ4,
                   Misf_bDgoORngMisfEmi4,
                   Misf_bMonRunORngMisfEmi4,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_ORNGMISFEMIGAZALL,
                   Misf_bDgoORngMisfEmiAll,
                   Misf_bMonRunORngMisfEmiAll,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidFuelLowLevelComput                           */
/* !Description :  Ce bloc calcule l’indicateur de niveau bas réservoir. Suite*/
/*                 à la détection d’un seuil minimum de dommages catalyseurs  */
/*                 sur les quatre cylindres une temporisation est enclenchée. */
/* !Number      :  FCT7.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 index)boolean;                */
/*  input boolean Flev_low_fuel_level;                                        */
/*  input boolean Flev_low_fuel_level_sw_mf;                                  */
/*  input boolean Ctrl_bAcv_PFuAcq;                                           */
/*  input uint16 Ext_pFuRailMes;                                              */
/*  input boolean Misf_bDgoORngDmgCat1;                                       */
/*  input boolean Misf_bDgoORngDmgCat2;                                       */
/*  input boolean Misf_bDgoORngDmgCat3;                                       */
/*  input boolean Misf_bDgoORngDmgCat4;                                       */
/*  input boolean Misf_bDgoORngDmgCatMDAll;                                   */
/*  input boolean Mf_cat_dam_glob_def_uavb0;                                  */
/*  input boolean MISFFAICTR_bLowFuelLevelPrev;                               */
/*  input uint16 Flev_low_fuel_level_tempo;                                   */
/*  input uint16 Flev_low_fuel_level_count;                                   */
/*  input boolean MISFFAICTR_bFuelLevelTimeOut;                               */
/*  input uint16 Misf_pFuRailMinLowFuLvl_C;                                   */
/*  output boolean Mf_cat_dam_glob_def_uavb0;                                 */
/*  output uint16 Flev_low_fuel_level_count;                                  */
/*  output boolean MISFFAICTR_bFuelLevelTimeOut;                              */
/*  output boolean Flev_low_fuel_level_cat_dam;                               */
/*  output boolean Misf_bAcvLowFuLvlCatDam;                                   */
/*  output boolean MISFFAICTR_bLowFuelLevelPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidFuelLowLevelComput(void)
{
   boolean bLocalLowFuelLevel;
   boolean bLocalFlev_low_fuel_level_sw_mf;
   boolean bLocalFlev_low_fuel_level;
   boolean bLocalCtrl_bAcv_PFuAcq;
   boolean bLocalnhFuLowLvlHw;
   uint16  u16LocalExt_pFuRailMes;


   VEMS_vidGET(Flev_low_fuel_level, bLocalFlev_low_fuel_level);
   VEMS_vidGET(Flev_low_fuel_level_sw_mf, bLocalFlev_low_fuel_level_sw_mf);
   VEMS_vidGET(Ctrl_bAcv_PFuAcq, bLocalCtrl_bAcv_PFuAcq);
   VEMS_vidGET(Ext_pFuRailMes, u16LocalExt_pFuRailMes);

   if (  (Misf_bDgoORngDmgCat1 != 0)
      || (Misf_bDgoORngDmgCat2 != 0)
      || (Misf_bDgoORngDmgCat3 != 0)
      || (Misf_bDgoORngDmgCat4 != 0)
      || (Misf_bDgoORngDmgCatMDAll != 0))
   {
      Mf_cat_dam_glob_def_uavb0 = 1;
   }
   else
   {
      Mf_cat_dam_glob_def_uavb0 = 0;
   }
   if (  (bLocalFlev_low_fuel_level != 0)
      && (Mf_cat_dam_glob_def_uavb0 != 0))
   {
      bLocalLowFuelLevel = 1;
   }
   else
   {
      bLocalLowFuelLevel = 0;
   }
   if (  (bLocalLowFuelLevel != 0)
      && (MISFFAICTR_bLowFuelLevelPrev == 0))
   {
      Flev_low_fuel_level_count = Flev_low_fuel_level_tempo;
      if (Flev_low_fuel_level_count == 0)
      {
         MISFFAICTR_bFuelLevelTimeOut = 1;
      }
      else
      {
         MISFFAICTR_bFuelLevelTimeOut = 0;
      }
   }
   else
   {
      if (Flev_low_fuel_level_count > 0)
      {
         Flev_low_fuel_level_count = (uint16)(Flev_low_fuel_level_count - 1);
         if (Flev_low_fuel_level_count == 0)
         {
            MISFFAICTR_bFuelLevelTimeOut = 1;
         }
         else
         {
            MISFFAICTR_bFuelLevelTimeOut = 0;
         }
      }
   }
   bLocalnhFuLowLvlHw = GDGAR_bGetFRM(FRM_FRM_INHFULOWLVLHW);
   if (  (MISFFAICTR_bFuelLevelTimeOut == 0)
      || (  (bLocalFlev_low_fuel_level_sw_mf != 0)
         && (bLocalnhFuLowLvlHw != 0)))
   {
      Flev_low_fuel_level_cat_dam = 1;
   }
   else
   {
      Flev_low_fuel_level_cat_dam = 0;
   }
   if (  (u16LocalExt_pFuRailMes < Misf_pFuRailMinLowFuLvl_C)
      || (bLocalCtrl_bAcv_PFuAcq == 0))
   {
      Misf_bAcvLowFuLvlCatDam = 1;
   }
   else
   {
      Misf_bAcvLowFuLvlCatDam = 0;
   }
   MISFFAICTR_bLowFuelLevelPrev = bLocalLowFuelLevel;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMisfFaiCtrEnable                             */
/* !Description :  Cette fonction permet d’activer la stratégie de comptage   */
/*                 des misfires à partir du moment oùle premier misfire est   */
/*                 détecté. Cette solution a été adoptée pour optimiser la    */
/*                 chaîne de calcul.                                          */
/* !Number      :  FCT7.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidInhDetNoMisfEnable();                      */
/*  input boolean Mf_misfire_detected_uavb0;                                  */
/*  input boolean MISFFAICTR_bMfMisfDetectedPrev;                             */
/*  output boolean MISFFAICTR_bMfMisfDetectedPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMisfFaiCtrEnable(void)
{
   boolean bLocalMf_misfire_detected_uavb0;


   VEMS_vidGET(Mf_misfire_detected_uavb0, bLocalMf_misfire_detected_uavb0);

   if (  (bLocalMf_misfire_detected_uavb0 != 0)
      && (MISFFAICTR_bMfMisfDetectedPrev == 0))
   {
      MISFFAICTR_vidInhDetNoMisfEnable();
   }
   MISFFAICTR_bMfMisfDetectedPrev = bLocalMf_misfire_detected_uavb0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidInhDetNoMisfEnable                           */
/* !Description :  Cette fonction inhibe le comptage lorsq'il n'y a pas encore*/
/*                 eu de misfire détecté.                                     */
/* !Number      :  FCT7.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Misf_bInhDetNoMisf;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidInhDetNoMisfEnable(void)
{
   Misf_bInhDetNoMisf = 0;
}
/*------------------------------end of file-----------------------------------*/