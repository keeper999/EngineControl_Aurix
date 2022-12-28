/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINENDSTOP                                         */
/* !Description     : VLVACTINENDSTOP Component.                              */
/*                                                                            */
/* !Module          : VLVACTINENDSTOP                                         */
/* !Description     : Calcul des butées pour le décaleur d'arbre à cames      */
/*                    d'admission .                                           */
/*                                                                            */
/* !File            : VLVACTINENDSTOP_FCT3.C                                  */
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
/*   1 / VLVACTINENDSTOP_vidEepromWrite                                       */
/*   2 / VLVACTINENDSTOP_IntOffIndUpdate1                                     */
/*   3 / VLVACTINENDSTOP_vidFrtLrnWtDfCpt                                     */
/*   4 / VLVACTINENDSTOP_vidPrevOfLrnErDt                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5883893 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINENDSTOP/VLVACTI$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   14 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINENDSTOP.h"
#include "VLVACTINENDSTOP_L.h"
#include "VLVACTINENDSTOP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidEepromWrite                             */
/* !Description :  Fonction d'écriture dans EEPROM                            */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bInOfsFrstLrn;                                       */
/*  input boolean VlvAct_bInOfsFrstLrnWouDft;                                 */
/*  input st116 Ext_stAgCmInFrstAdapt;                                        */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  output uint16 Vcpi_cam_offsets_eep[4];                                    */
/*  output boolean VlvAct_bInOfsFrstLrn_eep;                                  */
/*  output uint8 Ext_stAgCmInFrstAdapt_eep;                                   */
/*  output boolean VlvAct_bInOfsFrstLrnWouDft_eep;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidEepromWrite(void)
{
   boolean bLocalVlvAct_bInOfsFrstLrn;
   boolean bLocalVlvAct_bInOfsFrstLrnWouDft;
   uint8   u8LocalExt_stAgCmInFrstAdapt;
   uint8   u8LocalInd;
   uint16  u16LocalEep;


   VEMS_vidGET(VlvAct_bInOfsFrstLrn, bLocalVlvAct_bInOfsFrstLrn);
   VEMS_vidGET(VlvAct_bInOfsFrstLrnWouDft, bLocalVlvAct_bInOfsFrstLrnWouDft);
   VEMS_vidGET(Ext_stAgCmInFrstAdapt, u8LocalExt_stAgCmInFrstAdapt);
   for (u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
   {
      VEMS_vidGET1DArrayElement(Vcpi_cam_offsets, u8LocalInd, u16LocalEep);
      u16LocalEep = (uint16)MATHSRV_udtMIN(u16LocalEep, 7679);
      VEMS_vidSET1DArrayElement(Vcpi_cam_offsets_eep, u8LocalInd, u16LocalEep);
   }
   VEMS_vidSET(VlvAct_bInOfsFrstLrn_eep, bLocalVlvAct_bInOfsFrstLrn);
   VEMS_vidSET(Ext_stAgCmInFrstAdapt_eep, u8LocalExt_stAgCmInFrstAdapt);
   VEMS_vidSET(VlvAct_bInOfsFrstLrnWouDft_eep,
               bLocalVlvAct_bInOfsFrstLrnWouDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_IntOffIndUpdate1                           */
/* !Description :  Cette fonction permet le forçage à 1 de l'indicateur       */
/*                 Vcpi_cam_offsets_are_learned lorsque les conditions        */
/*                 d'apprentissage sont perdues.                              */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTINENDSTOP_vidFrtLrnWtDfCpt();                      */
/*  input boolean VlvAct_bInOfsFrstLrnWoutDftMod_C;                           */
/*  input boolean VlvAct_bDgoOldLrnVlvActIn;                                  */
/*  output boolean Vcpi_cam_offsets_are_learned;                              */
/*  output st62 Ext_stAgCmInAdapt;                                            */
/*  output st116 Ext_stAgCmInFrstAdapt;                                       */
/*  output boolean VlvAct_bInOfsFrstLrn;                                      */
/*  output boolean Ena_bInOfsFrstLrnWouDft;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_IntOffIndUpdate1(void)
{
   boolean bLocalbInhVlvActInFrstLrnIdc;


   VEMS_vidSET(Vcpi_cam_offsets_are_learned, 1);
   VEMS_vidSET(Ext_stAgCmInAdapt, VLVACT_ST_INLRN_DONE);
   VEMS_vidSET(Ext_stAgCmInFrstAdapt, VLVACT_ST_INFRSTLRN_DONE);
   VEMS_vidSET(VlvAct_bInOfsFrstLrn, 1);
   bLocalbInhVlvActInFrstLrnIdc =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTINFRSTLRNIDC);
   if (  (  (VlvAct_bInOfsFrstLrnWoutDftMod_C != 0)
         && (VlvAct_bDgoOldLrnVlvActIn == 0))
      || (  (VlvAct_bInOfsFrstLrnWoutDftMod_C == 0)
         && (bLocalbInhVlvActInFrstLrnIdc == 0)))
   {
      Ena_bInOfsFrstLrnWouDft = 1;
      VLVACTINENDSTOP_vidFrtLrnWtDfCpt();
   }
   else
   {
      Ena_bInOfsFrstLrnWouDft = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidFrtLrnWtDfCpt                           */
/* !Description :  Cette fonction est active si la variable                   */
/*                 FRM_bInhVlvActInFrstLrnIdc prend 0.                        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean VlvAct_bInOfsFrstLrnWouDft;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidFrtLrnWtDfCpt(void)
{
   VEMS_vidSET(VlvAct_bInOfsFrstLrnWouDft, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINENDSTOP_vidPrevOfLrnErDt                           */
/* !Description :  Cette fonction réalise un test pour vérifier que l'écart   */
/*                 entre les valeurs précédemment acquises et les actuelles   */
/*                 reste dans les tolérances fixées.                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void VLVACTINENDSTOP_vidOffLrnErrDet(argin uint16             */
/* u16Margin,argin uint16 *u16IntakeAngle,argin uint16 *u16OffMes ,argout     */
/* boolean *bErrDet);                                                         */
/*  input uint16 Vcpi_cam_offsets[4];                                         */
/*  input uint16 Vta_intake_old_off_margin;                                   */
/*  input uint16 Vta_intake_cam_off_mes_av[4];                                */
/*  input boolean VlvAct_bDgoOldLrnVlvActIn;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINENDSTOP_vidPrevOfLrnErDt(void)
{
   uint16  u16LocalVcpi_cam_offsets[VLVACTINENDSTOP_u8OFFLENGTH];


   VEMS_vidGET1DArray(Vcpi_cam_offsets, 4, u16LocalVcpi_cam_offsets);
   VLVACTINENDSTOP_vidOffLrnErrDet(Vta_intake_old_off_margin,
                                   u16LocalVcpi_cam_offsets,
                                   Vta_intake_cam_off_mes_av,
                                   &VlvAct_bDgoOldLrnVlvActIn);
}

/*--------------------------------- end of file ------------------------------*/