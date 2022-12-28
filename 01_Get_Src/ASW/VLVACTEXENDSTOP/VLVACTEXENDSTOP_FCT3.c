/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXENDSTOP                                         */
/* !Description     : VLVACTEXENDSTOP Component.                              */
/*                                                                            */
/* !Module          : VLVACTEXENDSTOP                                         */
/* !Description     : Calcul des butées pour le décaleur d'arbre à cames      */
/*                    d'échappement .                                         */
/*                                                                            */
/* !File            : VLVACTEXENDSTOP_FCT3.C                                  */
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
/*   1 / VLVACTEXENDSTOP_vidEepromWrite                                       */
/*   2 / VLVACTEXENDSTOP_ExtOffIndUpdate1                                     */
/*   3 / VLVACTEXENDSTOP_vidFrtLrnWtDfCpt                                     */
/*   4 / VLVACTEXENDSTOP_vidPrvLrnErDetec                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5885665 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#067950                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXENDSTOP/VLVACTE$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   14 Jan 2014 $*/
/* $Author::   etsasson                               $$Date::   14 Jan 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXENDSTOP.h"
#include "VLVACTEXENDSTOP_L.h"
#include "VLVACTEXENDSTOP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidEepromWrite                             */
/* !Description :  Fonction d'écriture dans EEPROM                            */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean VlvAct_bExOfsFrstLrn;                                       */
/*  input boolean VlvAct_bExOfsFrstLrnWouDft;                                 */
/*  input st117 Ext_stAgCmExFrstAdapt;                                        */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  output uint16 Vcpe_cam_offsets_eep[4];                                    */
/*  output boolean VlvAct_bExOfsFrstLrn_eep;                                  */
/*  output uint8 Ext_stAgCmExFrstAdapt_eep;                                   */
/*  output boolean VlvAct_bExOfsFrstLrnWouDft_eep;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidEepromWrite(void)
{
   boolean bLocalVlvAct_bExOfsFrstLrn;
   boolean bLocalVlvAct_bExOfsFrstLrnWouDft;
   uint8   u8LocalExt_stAgCmExFrstAdapt;
   uint8   u8LocalInd;
   uint16  u16Local;


   VEMS_vidGET(VlvAct_bExOfsFrstLrn, bLocalVlvAct_bExOfsFrstLrn);
   VEMS_vidGET(VlvAct_bExOfsFrstLrnWouDft, bLocalVlvAct_bExOfsFrstLrnWouDft);
   VEMS_vidGET(Ext_stAgCmExFrstAdapt, u8LocalExt_stAgCmExFrstAdapt);
   for(u8LocalInd=0; u8LocalInd<4; u8LocalInd++)
   {
      VEMS_vidGET1DArrayElement(Vcpe_cam_offsets,u8LocalInd,u16Local);
      u16Local = (uint16)MATHSRV_udtMIN(u16Local,7679);
      VEMS_vidSET1DArrayElement(Vcpe_cam_offsets_eep,u8LocalInd,u16Local);
   }
   VEMS_vidSET(VlvAct_bExOfsFrstLrn_eep, bLocalVlvAct_bExOfsFrstLrn);
   VEMS_vidSET(Ext_stAgCmExFrstAdapt_eep, u8LocalExt_stAgCmExFrstAdapt);
   VEMS_vidSET(VlvAct_bExOfsFrstLrnWouDft_eep,
               bLocalVlvAct_bExOfsFrstLrnWouDft);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_ExtOffIndUpdate1                           */
/* !Description :  Cette fonction permet le forçage à 1 de l'indicateur       */
/*                 Vcpe_cam_offsets_are_learned lorsque les conditions        */
/*                 d'apprentissage sont perdues.                              */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void VLVACTEXENDSTOP_vidFrtLrnWtDfCpt();                      */
/*  input boolean VlvAct_bExOfsFrstLrnWoutDftMod_C;                           */
/*  input boolean VlvAct_bDgoOldLrnVlvActEx;                                  */
/*  output boolean Vcpe_cam_offsets_are_learned;                              */
/*  output st17 Ext_stAgCmExAdapt;                                            */
/*  output st117 Ext_stAgCmExFrstAdapt;                                       */
/*  output boolean VlvAct_bExOfsFrstLrn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_ExtOffIndUpdate1(void)
{
   boolean bLocalbInhVlvActExFrstLrnIdc;


   VEMS_vidSET(Vcpe_cam_offsets_are_learned, 1);
   VEMS_vidSET(Ext_stAgCmExAdapt, VLVACT_ST_EXLRN_DONE);
   VEMS_vidSET(Ext_stAgCmExFrstAdapt, VLVACT_ST_EXFRSTLRN_DONE);
   VEMS_vidSET(VlvAct_bExOfsFrstLrn, 1);
   bLocalbInhVlvActExFrstLrnIdc =
      GDGAR_bGetFRM(FRM_FRM_INHVLVACTEXFRSTLRNIDC);
   if (  (  (VlvAct_bExOfsFrstLrnWoutDftMod_C != 0)
         && (VlvAct_bDgoOldLrnVlvActEx == 0))
      || (  (VlvAct_bExOfsFrstLrnWoutDftMod_C == 0)
         && (bLocalbInhVlvActExFrstLrnIdc == 0)))
   {
      VLVACTEXENDSTOP_vidFrtLrnWtDfCpt();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidFrtLrnWtDfCpt                           */
/* !Description :  Cette   fonction est active dés que                        */
/*                 FRM_bInhVlvActExFrstLrnIdc égale à 0.                      */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean VlvAct_bExOfsFrstLrnWouDft;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidFrtLrnWtDfCpt(void)
{
   VEMS_vidSET(VlvAct_bExOfsFrstLrnWouDft, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXENDSTOP_vidPrvLrnErDetec                           */
/* !Description :  Cette fonction réalize un test pour vérifier que  l'écart  */
/*                 entre les valeurs précédemment acquises et  les actuelles  */
/*                 reste dans les tolérances fixées.                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void VLVACTEXENDSTOP_vidOffLrnErrDet(argin uint16             */
/* u16Margin,argin uint16 *u16ExhaustAngle,uint16 *u16OffMes,argout boolean   */
/* *bErrDet);                                                                 */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  input uint16 Vta_exhaust_old_off_margin;                                  */
/*  input uint16 Vta_exhaust_cam_off_mes_av[4];                               */
/*  input boolean VlvAct_bDgoOldLrnVlvActEx;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXENDSTOP_vidPrvLrnErDetec(void)
{
   uint16  u16LocalVcpe_cam_offsets[VLVACTEXENDSTOP_u8OFFLENGTH];
   VEMS_vidGET1DArray(Vcpe_cam_offsets, 4, u16LocalVcpe_cam_offsets);
   VLVACTEXENDSTOP_vidOffLrnErrDet(Vta_exhaust_old_off_margin,
                                   u16LocalVcpe_cam_offsets,
                                   Vta_exhaust_cam_off_mes_av,
                                   &VlvAct_bDgoOldLrnVlvActEx);
}

/*--------------------------------- end of file ------------------------------*/