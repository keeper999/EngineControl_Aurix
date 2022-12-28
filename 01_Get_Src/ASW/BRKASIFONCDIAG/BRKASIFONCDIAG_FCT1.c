/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BRKASIFONCDIAG                                          */
/* !Description     : BRKASIFONCDIAG Component.                               */
/*                                                                            */
/* !Module          : BRKASIFONCDIAG                                          */
/* !Description     : Diagnostic fonctionnel du capteur de dépression         */
/*                    Mastervac.                                              */
/*                                                                            */
/* !File            : BRKASIFONCDIAG_FCT1.C                                   */
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
/*   1 / BRKASIFONCDIAG_vidInitOutput                                         */
/*   2 / BRKASIFONCDIAG_vidRun                                                */
/*   3 / BRKASIFONCDIAG_vidActivateDetect                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 04714 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/BRKASIFONCDIAG/BRKASIFONCDIAG_FCT1$*/
/* $Revision::   1.2      $$Author::   hmelloul       $$Date::   13 May 2011 $*/
/* $Author::   hmelloul                               $$Date::   13 May 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "BRKASIFONCDIAG.h"
#include "BRKASIFONCDIAG_L.h"
#include "BRKASIFONCDIAG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIFONCDIAG_vidInitOutput                               */
/* !Description :  Fonction d'initialisation des parametres produits.         */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 AirPres_tiCohBrkAsi;                                        */
/*  output boolean AirPres_bDgoCoh_pBrkAsi;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIFONCDIAG_vidInitOutput(void)
{
   AirPres_tiCohBrkAsi = 0;
   AirPres_bDgoCoh_pBrkAsi = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIFONCDIAG_vidRun                                      */
/* !Description :  Le test de cohérence du capteur de dépression Mastervac est*/
/*                 activé seulement si: Moteur tournant autonome, Le frein est*/
/*                 en position appuyé (avec une pression collecteur           */
/*                 raisonnable) depuis un certain temps, Le diagnostic n’est  */
/*                 pas inhibé par le GAR.                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf argret void BRKASIFONCDIAG_vidActivateDetect();                      */
/*  input boolean Ext_bBrkPedPrss;                                            */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint16 AirPres_pDsThrThdCohBrkAsi_C;                                */
/*  input uint16 AirPres_tiCohBrkAsi;                                         */
/*  input uint16 AirPres_tiDlyCohBrkAsi_C;                                    */
/*  output uint16 AirPres_tiCohBrkAsi;                                        */
/*  output boolean AirPres_bMonRunCoh_pBrkAsi;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIFONCDIAG_vidRun(void)
{
   boolean bLocalExt_bBrkPedPrss;
   boolean bLocalInhMonBrkAsi;
   uint8   u8LocalVehicle_Active_State;
   uint16  u16LocalAirPres_tiCohBrkAsi;
   uint16  u16Localpress_measured;


   VEMS_vidGET(Ext_bBrkPedPrss, bLocalExt_bBrkPedPrss);
   VEMS_vidGET(Io_map_manifold_press_measured, u16Localpress_measured);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_Active_State);

   bLocalInhMonBrkAsi = GDGAR_bGetFRM(FRM_FRM_INHMONBRKASI);

   if (  (u16Localpress_measured < AirPres_pDsThrThdCohBrkAsi_C)
      && (bLocalExt_bBrkPedPrss != 0))
   {
      if (AirPres_tiCohBrkAsi > 0)
      {
         u16LocalAirPres_tiCohBrkAsi = (uint16)(AirPres_tiCohBrkAsi - 1);
         AirPres_tiCohBrkAsi =
            (uint16)MATHSRV_udtMIN(u16LocalAirPres_tiCohBrkAsi, 1000);
      }
   }
   else
   {
      AirPres_tiCohBrkAsi = (uint16)MATHSRV_udtMIN(AirPres_tiDlyCohBrkAsi_C,
                                                  1000);
   }

   if (  (AirPres_tiCohBrkAsi == 0)
      && (u8LocalVehicle_Active_State == VS_RUNNING)
      && (bLocalInhMonBrkAsi == 0))
   {
      AirPres_bMonRunCoh_pBrkAsi = 1;
      BRKASIFONCDIAG_vidActivateDetect();
   }
   else
   {
      AirPres_bMonRunCoh_pBrkAsi = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BRKASIFONCDIAG_vidActivateDetect                           */
/* !Description :  La détection du défaut revient à constater une dépression  */
/*                 Mastervac trop importante.                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pBrkAsi;                                                 */
/*  input uint16 AirPres_pBrkAsiThdMax_C;                                     */
/*  output boolean AirPres_bDgoCoh_pBrkAsi;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BRKASIFONCDIAG_vidActivateDetect(void)
{
   uint16 u16LocalExt_pBrkAsi;


   VEMS_vidGET(Ext_pBrkAsi, u16LocalExt_pBrkAsi);

   if (u16LocalExt_pBrkAsi > AirPres_pBrkAsiThdMax_C)
   {
      AirPres_bDgoCoh_pBrkAsi = 1;
   }
   else
   {
      AirPres_bDgoCoh_pBrkAsi = 0;
   }
}
/*----------------------------- end of file ----------------------------------*/