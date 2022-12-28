/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IUPRSPCDEN                                              */
/* !Description     : IUPRSPCDEN Component                                    */
/*                                                                            */
/* !Module          : IUPRSPCDEN                                              */
/* !Description     : IUPRSPCDENORISATION DES PARAMETRES DEFAUTS              */
/*                                                                            */
/* !File            : IUPRSPCDEN_FCT1.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / IUPRSPCDEN_vidF01_Ini                                                */
/*   2 / IUPRSPCDEN_vidInternalValueInit                                      */
/*   3 / IUPRSPCDEN_vidF02_ColdStrtCdn                                        */
/*   4 / IUPRSPCDEN_vidF03_ClcnIncCdn                                         */
/*   5 / IUPRSPCDEN_bF01_tCoSen                                               */
/*   6 / IUPRSPCDEN_bF0x_XxVlv                                                */
/*   7 / IUPRSPCDEN_bF0x_XxCmSen                                              */
/*   8 / IUPRSPCDEN_bF06_pSpgSen                                              */
/*   9 / IUPRSPCDEN_bF07_tCoDiag                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 03254 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/IUPRSPCDEN/IUPRSPCDEN_FCT1.C_$*/
/* $Revision::   1.5      $$Author::   alaouni        $$Date::   28 Mar 2012 $*/
/* $Author::   alaouni                                $$Date::   28 Mar 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "IUPRSPCDEN.h"
#include "IUPRSPCDEN_L.h"
#include "IUPRSPCDEN_IM.h"
#include "GD_api.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_vidF01_Ini                                      */
/* !Description :  Fonction d'initialisation appelée soir sur un événement    */
/*                 Reset au sur un événement DC global.                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 u8Iupr_xxx_denom_ok;                                          */
/*  output uint8 Iupr_tiAcvtCoSen;                                            */
/*  output uint8 Iupr_tiAcvInCmSenSaved;                                      */
/*  output uint8 Iupr_ctAcvInCmSen;                                           */
/*  output uint8 Iupr_tiAcvInVlvSaved;                                        */
/*  output uint8 Iupr_tiAcvExCmSenSaved;                                      */
/*  output uint8 Iupr_tiAcvInVlvReinit;                                       */
/*  output uint8 Iupr_ctAcvExCmSen;                                           */
/*  output uint8 Iupr_ctAcvInVlv;                                             */
/*  output uint8 Iupr_tiAcvSpgSen;                                            */
/*  output uint8 Iupr_tiAcvExVlvSaved;                                        */
/*  output uint8 Iupr_tiAcvExVlvReinit;                                       */
/*  output uint8 Iupr_ctAcvExVlv;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRSPCDEN_vidF01_Ini(void)
{

   boolean bLocalValue;


   bLocalValue = FALSE;
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_TCO_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_TCO_DIAG_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_IN_VLV_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_EX_VLV_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_IN_CAM_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_EX_CAM_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok, DEF_IUPR_PSPG_DENOM_OK, bLocalValue);

   Iupr_tiAcvtCoSen = 0;
   Iupr_tiAcvInCmSenSaved = 0;
   Iupr_ctAcvInCmSen = 0;
   Iupr_tiAcvInVlvSaved = 0;
   Iupr_tiAcvExCmSenSaved = 0;
   Iupr_tiAcvInVlvReinit = 0;
   Iupr_ctAcvExCmSen = 0;
   Iupr_ctAcvInVlv = 0;
   Iupr_tiAcvSpgSen = 0;
   Iupr_tiAcvExVlvSaved = 0;
   Iupr_tiAcvExVlvReinit = 0;
   Iupr_ctAcvExVlv = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_vidInternalValueInit                            */
/* !Description :  Fonction d'initialisation appelée uniquement sur un        */
/*                 événement Reset                                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 u8Iupr_xxx_denom_ok_prev;                                     */
/*  output boolean Iupr_bAvlInCmSen;                                          */
/*  output boolean Iupr_bAvlExCmSen;                                          */
/*  output boolean IUPRSPCDEN_bInVlvReinit_prev;                              */
/*  output boolean IUPRSPCDEN_bExVlvReinit_prev;                              */
/*  output boolean IUPRSPCDEN_bInCmSenReinit_prev;                            */
/*  output boolean IUPRSPCDEN_bExCmSenReinit_prev;                            */
/*  output boolean IUPRSPCDEN_UpdateDenomOkPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRSPCDEN_vidInternalValueInit(void)
{
   boolean bLocalValue;


   bLocalValue = FALSE;
   Iupr_bAvlInCmSen = FALSE;
   Iupr_bAvlExCmSen = FALSE;

   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev, DEF_IUPR_TCO_DENOM_OK, bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                  DEF_IUPR_TCO_DIAG_DENOM_OK,
                  bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                  DEF_IUPR_IN_VLV_DENOM_OK,
                  bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                  DEF_IUPR_EX_VLV_DENOM_OK,
                  bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                  DEF_IUPR_IN_CAM_DENOM_OK,
                  bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                  DEF_IUPR_EX_CAM_DENOM_OK,
                  bLocalValue);
   GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                  DEF_IUPR_PSPG_DENOM_OK,
                  bLocalValue);

   IUPRSPCDEN_bInVlvReinit_prev = FALSE;
   IUPRSPCDEN_bExVlvReinit_prev = FALSE;
   IUPRSPCDEN_bInCmSenReinit_prev = FALSE;
   IUPRSPCDEN_bExCmSenReinit_prev = FALSE;
   IUPRSPCDEN_UpdateDenomOkPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_vidF02_ColdStrtCdn                              */
/* !Description :  Détection du démarrage à froid                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_tAirExtMes;                                              */
/*  input sint16 Iupr_ColdStrtTAirOfs_C;                                      */
/*  input sint16 Iupr_ColdStrtTCoMax_C;                                       */
/*  output boolean Iupr_bColdStrt;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRSPCDEN_vidF02_ColdStrtCdn(void)
{
   sint16 s16localExt_tCoMes;
   sint16 s16localExt_tAirExtMes;
   sint32 s32localExt_tAirExtMes;


   VEMS_vidGET(Ext_tCoMes, s16localExt_tCoMes);
   VEMS_vidGET(Ext_tAirExtMes, s16localExt_tAirExtMes);

   s32localExt_tAirExtMes = (sint32)( s16localExt_tAirExtMes
                                    + Iupr_ColdStrtTAirOfs_C);

   if (  (s16localExt_tCoMes <= Iupr_ColdStrtTCoMax_C)
      && (s16localExt_tCoMes <= s32localExt_tAirExtMes))
   {
      Iupr_bColdStrt = 1;
   }
   else
   {
      Iupr_bColdStrt = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_vidF03_ClcnIncCdn                               */
/* !Description :  Calcul des conditions d'incrémentation des dénominateurs   */
/*                 spécifiques à la récurrence du moniteur lent de la fonction*/
/*                 GD.                                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  IUPRSPCDEN_bF01_tCoSen(argin boolean                 */
/* blocal_iupr_gen_denom_ok_par);                                             */
/*  extf argret boolean  IUPRSPCDEN_bF0x_XxVlv(argin boolean                  */
/* biupr_gen_denom_ok_par, argin boolean bvlvact_bacvxxservo_par, argin       */
/* boolean bTiAcvXxVlvReinit_prev_par, argin uint8                            */
/* u8iupr_tihithdacvxxvlv_c_par, argin uint8 u8iupr_tilothdacvxxvlv_c_par,    */
/* argin uint8 u8iupr_ctminacvxxvlv_c_par, argin uint8                        */
/* *u8Iupr_tiAcvxxVlvSaved_par, argin boolean *u8iupr_tiAcvXxVlvReinit_par,   */
/* argin boolean *biupr_bacvxxvlv_par, argin uint8 *u8iupr_ctacvxxvlv_par);   */
/*  extf argret boolean  IUPRSPCDEN_bF0x_XxCmSen(argin boolean                */
/* biupr_gen_denom_ok_par, argin boolean bacq_xxcam_tooth_det_vld_par, argin  */
/* boolean bacq_xxcam_tooth_det_par, argin boolean                            */
/* biupr_tiAcvxxCmSenReinit_prev_par, argin uint8                             */
/* u8iupr_tihithdacvxxcmsen_c_par, argin uint8 u8iupr_tilothdacvxxcmsen_c_par,*/
/* argin uint8 u8iupr_ctminacvXXcmsen_c_par, argin boolean                    */
/* *biupr_bavlxxcmsen_par, argin uint8 *u8iupr_tiacvxxCmSenSaved_par, argin   */
/* uint8 *u8iupr_tiAcvxxCmSenReinit_par, argin uint8 *u8iupr_ctacvxxcmsen_par,*/
/* argin boolean *biupr_bacvxxcmsen_par);                                     */
/*  extf argret boolean  IUPRSPCDEN_bF06_pSpgSen(argin boolean                */
/* blocal_iupr_gen_denom_ok_par, argin boolean                                */
/* blocal_trbAct_bBoostPresClCtlAcv_par);                                     */
/*  extf argret boolean  IUPRSPCDEN_bF07_tCoDiag(argin boolean                */
/* blocal_iupr_gen_denom_ok_par, argin boolean blocal_Iupr_bColdStrt_par);    */
/*  input boolean VlvAct_bAcvInServo;                                         */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  input boolean Acq_incam_tooth_det_upvb0;                                  */
/*  input boolean Acq_excam_tooth_det_upvb0;                                  */
/*  input boolean Iupr_bFrzGenDen;                                            */
/*  input uint8 u8Iupr_xxx_denom_ok;                                          */
/*  input uint8 u8Iupr_xxx_denom_ok_prev;                                     */
/*  input boolean Ext_bPresInCmSen;                                           */
/*  input boolean Ext_bPresExCmSen;                                           */
/*  input boolean Ext_bEngTrbMode;                                            */
/*  input boolean IUPRSPCDEN_bInVlvReinit_prev;                               */
/*  input uint8 Iupr_tiHiThdAcvInVlv_C;                                       */
/*  input uint8 Iupr_tiLoThdAcvInVlv_C;                                       */
/*  input uint8 Iupr_ctMinAcvInVlv_C;                                         */
/*  input uint8 Iupr_tiAcvInVlvSaved;                                         */
/*  input uint8 Iupr_tiAcvInVlvReinit;                                        */
/*  input boolean Iupr_bAcvInVlv;                                             */
/*  input uint8 Iupr_ctAcvInVlv;                                              */
/*  input boolean IUPRSPCDEN_bExVlvReinit_prev;                               */
/*  input uint8 Iupr_tiHiThdAcvExVlv_C;                                       */
/*  input uint8 Iupr_tiLoThdAcvExVlv_C;                                       */
/*  input uint8 Iupr_ctMinAcvExVlv_C;                                         */
/*  input uint8 Iupr_tiAcvExVlvSaved;                                         */
/*  input uint8 Iupr_tiAcvExVlvReinit;                                        */
/*  input boolean Iupr_bAcvExVlv;                                             */
/*  input uint8 Iupr_ctAcvExVlv;                                              */
/*  input boolean Acq_incam_tooth_det_vld_upvb0;                              */
/*  input boolean IUPRSPCDEN_bInCmSenReinit_prev;                             */
/*  input uint8 Iupr_tiHiThdAcvInCmSen_C;                                     */
/*  input uint8 Iupr_tiLoThdAcvInCmSen_C;                                     */
/*  input uint8 Iupr_ctMinAcvInCmSen_C;                                       */
/*  input boolean Iupr_bAvlInCmSen;                                           */
/*  input uint8 Iupr_tiAcvInCmSenSaved;                                       */
/*  input uint8 Iupr_tiAcvInCmSenReinit;                                      */
/*  input uint8 Iupr_ctAcvInCmSen;                                            */
/*  input boolean Iupr_bAcvInCmSen;                                           */
/*  input boolean Acq_excam_tooth_det_vld_upvb0;                              */
/*  input boolean IUPRSPCDEN_bExCmSenReinit_prev;                             */
/*  input uint8 Iupr_tiHiThdAcvExCmSen_C;                                     */
/*  input uint8 Iupr_tiLoThdAcvExCmSen_C;                                     */
/*  input uint8 Iupr_ctMinAcvExCmSen_C;                                       */
/*  input boolean Iupr_bAvlExCmSen;                                           */
/*  input uint8 Iupr_tiAcvExCmSenSaved;                                       */
/*  input uint8 Iupr_tiAcvExCmSenReinit;                                      */
/*  input uint8 Iupr_ctAcvExCmSen;                                            */
/*  input boolean Iupr_bAcvExCmSen;                                           */
/*  input boolean TrbAct_bBoostPresClCtlAcv;                                  */
/*  input boolean Iupr_bColdStrt;                                             */
/*  input boolean IUPRSPCDEN_UpdateDenomOkPrev;                               */
/*  output boolean IUPRSPCDEN_UpdateDenomOkPrev;                              */
/*  output boolean IUPRSPCDEN_bInVlvReinit_prev;                              */
/*  output boolean IUPRSPCDEN_bExVlvReinit_prev;                              */
/*  output boolean IUPRSPCDEN_bInCmSenReinit_prev;                            */
/*  output boolean IUPRSPCDEN_bExCmSenReinit_prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IUPRSPCDEN_vidF03_ClcnIncCdn(void)
{
   boolean blocal_ext_bpresincmsen;
   boolean blocal_ext_bpresexcmsen;
   boolean blocal_ext_bEngTrbMode;
   boolean blocal_iupr_gen_denom_ok;
   boolean blocal_vlvact_bacvinservo;
   boolean blocal_vlvact_bacvexservo;
   boolean bLocal_iupr_tco_denom_ok;
   boolean blocal_Iupr_tco_diag_denom_ok;
   boolean blocal_iupr_pSpg_denom_ok;
   boolean blocal_iupr_in_vlv_denom_ok;
   boolean blocal_iupr_ex_vlv_denom_ok;
   boolean blocal_iupr_in_cam_denom_ok;
   boolean blocal_iupr_ex_cam_denom_ok;
   boolean bLocal_iupr_tco_denom_ok_prev;
   boolean bLocal_Iupr_tco_diag_dnm_ok_prev;
   boolean blocal_iupr_in_vlv_denom_ok_prev;
   boolean blocal_iupr_ex_vlv_denom_ok_prev;
   boolean blocal_iupr_in_cam_denom_ok_prev;
   boolean blocal_iupr_ex_cam_denom_ok_prev;
   boolean blocal_iupr_pSpg_denom_ok_prev;
   boolean blocal_acq_incam_tooth_det_vld_upvb0;
   boolean blocal_acq_excam_tooth_det_vld_upvb0;
   boolean blocal_acq_incam_tooth_det_upvb0;
   boolean blocal_acq_excam_tooth_det_upvb0;
   boolean blocal_trbAct_bBoostPresClCtlAcv;
   boolean bLocalIupr_bFrzGenDen;
   boolean bLocalValue;


   VEMS_vidGET(VlvAct_bAcvInServo, blocal_vlvact_bacvinservo );
   VEMS_vidGET(VlvAct_bAcvExServo, blocal_vlvact_bacvexservo );
   VEMS_vidGET(Acq_incam_tooth_det_upvb0, blocal_acq_incam_tooth_det_upvb0 );
   VEMS_vidGET(Acq_excam_tooth_det_upvb0, blocal_acq_excam_tooth_det_upvb0 );
   VEMS_vidGET(Iupr_bFrzGenDen, bLocalIupr_bFrzGenDen );

   /* Récupération de l'état en cours */
   blocal_iupr_gen_denom_ok = GD_bBitRead(u8Iupr_xxx_denom_ok,
                                          DEF_IUPR_GEN_DENOM_OK);

   /* Récupération de l'état précédent */
   bLocal_iupr_tco_denom_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                               DEF_IUPR_TCO_DENOM_OK);
   bLocal_Iupr_tco_diag_dnm_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                                  DEF_IUPR_TCO_DIAG_DENOM_OK);
   blocal_iupr_in_vlv_denom_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                                  DEF_IUPR_IN_VLV_DENOM_OK);
   blocal_iupr_ex_vlv_denom_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                                  DEF_IUPR_EX_VLV_DENOM_OK);
   blocal_iupr_in_cam_denom_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                                  DEF_IUPR_IN_CAM_DENOM_OK);
   blocal_iupr_ex_cam_denom_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                                  DEF_IUPR_EX_CAM_DENOM_OK);
   blocal_iupr_pSpg_denom_ok_prev = GD_bBitRead(u8Iupr_xxx_denom_ok_prev,
                                                DEF_IUPR_PSPG_DENOM_OK);


   if (FALSE == bLocalIupr_bFrzGenDen )
   {
      if (FALSE == bLocal_iupr_tco_denom_ok_prev )
      {
         bLocal_iupr_tco_denom_ok =
            IUPRSPCDEN_bF01_tCoSen(blocal_iupr_gen_denom_ok);

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,DEF_IUPR_TCO_DENOM_OK,
                        bLocal_iupr_tco_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,DEF_IUPR_TCO_DENOM_OK,
                        bLocal_iupr_tco_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }

      VEMS_vidGET(Ext_bPresInCmSen, blocal_ext_bpresincmsen);
      VEMS_vidGET(Ext_bPresExCmSen, blocal_ext_bpresexcmsen);
      VEMS_vidGET(Ext_bEngTrbMode, blocal_ext_bEngTrbMode);
      if( FALSE == blocal_iupr_in_vlv_denom_ok_prev )
      {
         blocal_iupr_in_vlv_denom_ok =
            IUPRSPCDEN_bF0x_XxVlv(blocal_iupr_gen_denom_ok,
                                  blocal_vlvact_bacvinservo,
                                  IUPRSPCDEN_bInVlvReinit_prev,
                                  Iupr_tiHiThdAcvInVlv_C,
                                  Iupr_tiLoThdAcvInVlv_C,
                                  Iupr_ctMinAcvInVlv_C,
                                  &Iupr_tiAcvInVlvSaved,
                                  &Iupr_tiAcvInVlvReinit,
                                  &Iupr_bAcvInVlv,
                                  &Iupr_ctAcvInVlv );

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                        DEF_IUPR_IN_VLV_DENOM_OK,
                        blocal_iupr_in_vlv_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                        DEF_IUPR_IN_VLV_DENOM_OK,
                        blocal_iupr_in_vlv_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }

      if(FALSE == blocal_iupr_ex_vlv_denom_ok_prev)
      {
         blocal_iupr_ex_vlv_denom_ok =
            IUPRSPCDEN_bF0x_XxVlv(blocal_iupr_gen_denom_ok,
                                  blocal_vlvact_bacvexservo,
                                  IUPRSPCDEN_bExVlvReinit_prev,
                                  Iupr_tiHiThdAcvExVlv_C,
                                  Iupr_tiLoThdAcvExVlv_C,
                                  Iupr_ctMinAcvExVlv_C,
                                  &Iupr_tiAcvExVlvSaved,
                                  &Iupr_tiAcvExVlvReinit,
                                  &Iupr_bAcvExVlv,
                                  &Iupr_ctAcvExVlv );

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                        DEF_IUPR_EX_VLV_DENOM_OK,
                        blocal_iupr_ex_vlv_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                        DEF_IUPR_EX_VLV_DENOM_OK,
                        blocal_iupr_ex_vlv_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }

      if (  (FALSE == blocal_iupr_in_cam_denom_ok_prev )
         && ( TRUE == blocal_ext_bpresincmsen))
      {
         VEMS_vidGET(Acq_incam_tooth_det_vld_upvb0,
                     blocal_acq_incam_tooth_det_vld_upvb0 );

         blocal_iupr_in_cam_denom_ok =
           IUPRSPCDEN_bF0x_XxCmSen(blocal_iupr_gen_denom_ok,
                                   blocal_acq_incam_tooth_det_vld_upvb0,
                                   blocal_acq_incam_tooth_det_upvb0,
                                   IUPRSPCDEN_bInCmSenReinit_prev,
                                   Iupr_tiHiThdAcvInCmSen_C,
                                   Iupr_tiLoThdAcvInCmSen_C,
                                   Iupr_ctMinAcvInCmSen_C,
                                   &Iupr_bAvlInCmSen,
                                   &Iupr_tiAcvInCmSenSaved,
                                   &Iupr_tiAcvInCmSenReinit,
                                   &Iupr_ctAcvInCmSen,
                                   &Iupr_bAcvInCmSen );

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                        DEF_IUPR_IN_CAM_DENOM_OK,
                        blocal_iupr_in_cam_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                        DEF_IUPR_IN_CAM_DENOM_OK,
                        blocal_iupr_in_cam_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }

      if (  (FALSE == blocal_iupr_ex_cam_denom_ok_prev )
         && (TRUE == blocal_ext_bpresexcmsen))
      {
         VEMS_vidGET(Acq_excam_tooth_det_vld_upvb0,
                     blocal_acq_excam_tooth_det_vld_upvb0 );

         blocal_iupr_ex_cam_denom_ok =
           IUPRSPCDEN_bF0x_XxCmSen(blocal_iupr_gen_denom_ok,
                                   blocal_acq_excam_tooth_det_vld_upvb0,
                                   blocal_acq_excam_tooth_det_upvb0,
                                   IUPRSPCDEN_bExCmSenReinit_prev,
                                   Iupr_tiHiThdAcvExCmSen_C,
                                   Iupr_tiLoThdAcvExCmSen_C,
                                   Iupr_ctMinAcvExCmSen_C,
                                   &Iupr_bAvlExCmSen,
                                   &Iupr_tiAcvExCmSenSaved,
                                   &Iupr_tiAcvExCmSenReinit,
                                   &Iupr_ctAcvExCmSen,
                                   &Iupr_bAcvExCmSen );

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                        DEF_IUPR_EX_CAM_DENOM_OK,
                        blocal_iupr_ex_cam_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                        DEF_IUPR_EX_CAM_DENOM_OK,
                        blocal_iupr_ex_cam_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }

      if (  (FALSE == blocal_iupr_pSpg_denom_ok_prev)
         && (TRUE == blocal_ext_bEngTrbMode))
      {
         VEMS_vidGET(TrbAct_bBoostPresClCtlAcv,
                     blocal_trbAct_bBoostPresClCtlAcv);

         blocal_iupr_pSpg_denom_ok =
           IUPRSPCDEN_bF06_pSpgSen(blocal_iupr_gen_denom_ok,
                                   blocal_trbAct_bBoostPresClCtlAcv);

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                        DEF_IUPR_PSPG_DENOM_OK,
                        blocal_iupr_pSpg_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                        DEF_IUPR_PSPG_DENOM_OK,
                        blocal_iupr_pSpg_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }

      if(FALSE == bLocal_Iupr_tco_diag_dnm_ok_prev)
      {
         blocal_Iupr_tco_diag_denom_ok =
            IUPRSPCDEN_bF07_tCoDiag(blocal_iupr_gen_denom_ok, Iupr_bColdStrt);

         GD_vidBitWrite(u8Iupr_xxx_denom_ok,
                        DEF_IUPR_TCO_DIAG_DENOM_OK,
                        blocal_Iupr_tco_diag_denom_ok);
         GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                        DEF_IUPR_TCO_DIAG_DENOM_OK,
                        blocal_Iupr_tco_diag_denom_ok);
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      /* Do Nothing */
   }

   bLocalValue = FALSE;
   if( IUPRSPCDEN_UpdateDenomOkPrev == TRUE )
   {
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_TCO_DENOM_OK,
                     bLocalValue);
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_TCO_DIAG_DENOM_OK,
                     bLocalValue);
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_IN_VLV_DENOM_OK,
                     bLocalValue);
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_EX_VLV_DENOM_OK,
                     bLocalValue);
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_IN_CAM_DENOM_OK,
                     bLocalValue);
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_EX_CAM_DENOM_OK,
                     bLocalValue);
      GD_vidBitWrite(u8Iupr_xxx_denom_ok_prev,
                     DEF_IUPR_PSPG_DENOM_OK,
                     bLocalValue);
      IUPRSPCDEN_UpdateDenomOkPrev = 0;
   }

   /* Previous Compute */
   if(Iupr_tiAcvInVlvReinit >= Iupr_tiLoThdAcvInVlv_C)
   {
      IUPRSPCDEN_bInVlvReinit_prev = TRUE;
   }
   else
   {
      IUPRSPCDEN_bInVlvReinit_prev = FALSE;
   }
   if(Iupr_tiAcvExVlvReinit >= Iupr_tiLoThdAcvExVlv_C)
   {
      IUPRSPCDEN_bExVlvReinit_prev = TRUE;
   }
   else
   {
      IUPRSPCDEN_bExVlvReinit_prev = FALSE;
   }
   if(Iupr_tiAcvInCmSenReinit >= Iupr_tiLoThdAcvInCmSen_C)
   {
      IUPRSPCDEN_bInCmSenReinit_prev = TRUE;
   }
   else
   {
      IUPRSPCDEN_bInCmSenReinit_prev = FALSE;
   }
   if(Iupr_tiAcvExCmSenReinit >= Iupr_tiLoThdAcvExCmSen_C)
   {
      IUPRSPCDEN_bExCmSenReinit_prev = TRUE;
   }
   else
   {
      IUPRSPCDEN_bExCmSenReinit_prev = FALSE;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_bF01_tCoSen                                     */
/* !Description :  Cette fonction produit le critère d’incrémentation du      */
/*                 dénominateur spécifique « ColdStart » pour les défauts du  */
/*                 capteur température d’eau.                                 */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/* !Trace_To    :  VEMS_R_11_03254_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  input uint8 Iupr_tiAcvtCoSen;                                             */
/*  input uint8 Iupr_tiMinAcvtCoSen_C;                                        */
/*  input boolean Iupr_bAcvtCoSen;                                            */
/*  output uint8 Iupr_tiAcvtCoSen;                                            */
/*  output boolean Iupr_bAcvtCoSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean IUPRSPCDEN_bF01_tCoSen
(
   boolean blocal_iupr_gen_denom_ok_par
)
{
   boolean bLocal_iupr_tco_denom_ok;
   boolean bLocalEOM_bTWCHeatPha;


   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   if (bLocalEOM_bTWCHeatPha != 0)
   {
      if (Iupr_tiAcvtCoSen < 255 )
      {
         Iupr_tiAcvtCoSen = (uint8)(Iupr_tiAcvtCoSen + 1);
      }
   }

   if (Iupr_tiAcvtCoSen >= Iupr_tiMinAcvtCoSen_C)
   {
      Iupr_bAcvtCoSen = 1;
   }
   else
   {
      Iupr_bAcvtCoSen = 0;
   }

   if (  (blocal_iupr_gen_denom_ok_par != 0)
      && (Iupr_bAcvtCoSen != 0))
   {
      bLocal_iupr_tco_denom_ok = 1;
   }
   else
   {
      bLocal_iupr_tco_denom_ok = 0;
   }

   return bLocal_iupr_tco_denom_ok;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_bF0x_XxVlv                                      */
/* !Description :  Cette fonction produit le critère d’incrémentation du      */
/*                 dénominateur spécifique « VVT » pour les défauts de la VVT */
/*                 admission. Cette fonction est appelée deux fois avec des   */
/*                 paramêtres différents.                                     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/* !Trace_To    :  VEMS_R_11_03254_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean IUPRSPCDEN_bF0x_XxVlv
(
   boolean biupr_gen_denom_ok_par,
   boolean bvlvact_bacvxxservo_par,
   boolean bTiAcvXxVlvReinit_prev_par,
   uint8 u8iupr_tihithdacvxxvlv_c_par,
   uint8 u8iupr_tilothdacvxxvlv_c_par,
   uint8 u8iupr_ctminacvxxvlv_c_par,
   uint8* u8Iupr_tiAcvxxVlvSaved_par,
   boolean* u8iupr_tiAcvXxVlvReinit_par,
   boolean* biupr_bacvxxvlv_par,
   uint8* u8iupr_ctacvxxvlv_par
)
{
   boolean blocal_iupr_xx_vlv_denom_ok;

   if( TRUE == bvlvact_bacvxxservo_par )
   {
      if( (*u8Iupr_tiAcvxxVlvSaved_par) < 255 )
      {
         (*u8Iupr_tiAcvxxVlvSaved_par)++;
      }
      else
      {
         /* Do Nothing */
      }
      if( (*u8iupr_tiAcvXxVlvReinit_par) < 255 )
      {
         (*u8iupr_tiAcvXxVlvReinit_par)++;
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      *u8iupr_tiAcvXxVlvReinit_par = 0;
   }

   if(*u8iupr_tiAcvXxVlvReinit_par >= u8iupr_tilothdacvxxvlv_c_par)
   {
      if(bTiAcvXxVlvReinit_prev_par == 0)
      {
         if( (*u8iupr_ctacvxxvlv_par) < 255 )
         {
            (*u8iupr_ctacvxxvlv_par)++;
         }
         else
         {
            /* Do Nothing */
         }
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      /* Do Nothing */
   }

   if( u8iupr_tihithdacvxxvlv_c_par > (*u8Iupr_tiAcvxxVlvSaved_par) )
   {
      (*biupr_bacvxxvlv_par) =
      ( (*u8iupr_ctacvxxvlv_par >=
          u8iupr_ctminacvxxvlv_c_par)) ? TRUE : FALSE;
   }
   else
   {
      (*biupr_bacvxxvlv_par) = TRUE;
   }

   blocal_iupr_xx_vlv_denom_ok =
   ( ( TRUE == biupr_gen_denom_ok_par ) &&
     ( TRUE == (*biupr_bacvxxvlv_par) ) ) ? TRUE : FALSE;

   return blocal_iupr_xx_vlv_denom_ok;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_bF0x_XxCmSen                                    */
/* !Description :  Cette fonction produit le critère d’incrémentation du      */
/*                 dénominateur spécifique « VVT » pour les défauts du capteur*/
/*                 arbre à cames admission. Cette fonction est appelée deux   */
/*                 fois avec des paramêtres différents…                       */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean IUPRSPCDEN_bF0x_XxCmSen
(
   boolean biupr_gen_denom_ok_par,
   boolean bacq_xxcam_tooth_det_vld_par,
   boolean bacq_xxcam_tooth_det_par,
   boolean biupr_tiAcvxxCmSenReinit_prev_par,
   uint8 u8iupr_tihithdacvxxcmsen_c_par,
   uint8 u8iupr_tilothdacvxxcmsen_c_par,
   uint8 u8iupr_ctminacvXXcmsen_c_par,
   boolean* biupr_bavlxxcmsen_par,
   uint8* u8iupr_tiacvxxCmSenSaved_par,
   uint8* u8iupr_tiAcvxxCmSenReinit_par,
   uint8* u8iupr_ctacvxxcmsen_par,
   boolean* biupr_bacvxxcmsen_par
)
{
   boolean biupr_xx_cam_denom_ok;

   if( TRUE == bacq_xxcam_tooth_det_vld_par )
   {
      (*biupr_bavlxxcmsen_par) = bacq_xxcam_tooth_det_par;
   }
   else
   {
      /* Do Nothing */
   }

   if( TRUE == (*biupr_bavlxxcmsen_par) )
   {
      if( (*u8iupr_tiacvxxCmSenSaved_par) < 255 )
      {
         (*u8iupr_tiacvxxCmSenSaved_par)++;
      }
      else
      {
         /* Do Nothing */
      }
      if( (*u8iupr_tiAcvxxCmSenReinit_par) < 255 )
      {
         (*u8iupr_tiAcvxxCmSenReinit_par)++;
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      *u8iupr_tiAcvxxCmSenReinit_par = 0;
   }

   if(*u8iupr_tiAcvxxCmSenReinit_par >= u8iupr_tilothdacvxxcmsen_c_par)
   {
      if(biupr_tiAcvxxCmSenReinit_prev_par == 0)
      {
         if( (*u8iupr_ctacvxxcmsen_par) < 255 )
         {
            (*u8iupr_ctacvxxcmsen_par)++;
         }
         else
         {
            /* Do Nothing */
         }
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      /* Do Nothing */
   }

   if( u8iupr_tihithdacvxxcmsen_c_par > (*u8iupr_tiacvxxCmSenSaved_par) )
   {
      (*biupr_bacvxxcmsen_par) =
      ( (*u8iupr_ctacvxxcmsen_par >=
          u8iupr_ctminacvXXcmsen_c_par)) ? TRUE : FALSE;
   }
   else
   {
      (*biupr_bacvxxcmsen_par) = TRUE;
   }

   biupr_xx_cam_denom_ok =
      ( ( TRUE == biupr_gen_denom_ok_par   ) &&
        ( TRUE == (*biupr_bacvxxcmsen_par) ) ) ? TRUE : FALSE;

   return biupr_xx_cam_denom_ok;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_bF06_pSpgSen                                    */
/* !Description :  Cette fonction produit le critère d’incrémentation du      */
/*                 dénominateur spécifique « BP » pour les diagnostics de la  */
/*                 suralimentation.                                           */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/* !Trace_To    :  VEMS_R_11_03254_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Iupr_tiAcvSpgSen;                                             */
/*  input uint8 Iupr_tiMinAcvSpg_C;                                           */
/*  input boolean Iupr_bTiBoostPIninTyp_C;                                    */
/*  input boolean Iupr_bAcvSpgSen;                                            */
/*  output uint8 Iupr_tiAcvSpgSen;                                            */
/*  output boolean Iupr_bAcvSpgSen;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean IUPRSPCDEN_bF06_pSpgSen
(
   boolean blocal_iupr_gen_denom_ok_par,
   boolean blocal_trbAct_bBoostPresClCtlAcv_par
)
{
   boolean bLocal_iupr_pSpg_denom_ok;


   if(blocal_trbAct_bBoostPresClCtlAcv_par == TRUE)
   {
      if( Iupr_tiAcvSpgSen < 255 )
      {
         Iupr_tiAcvSpgSen++;
      }
      else
      {
         /* Do Nothing */
      }
      Iupr_bAcvSpgSen =
      ( Iupr_tiAcvSpgSen >= Iupr_tiMinAcvSpg_C ) ? TRUE : FALSE;
   }
   else
   {
      if(Iupr_bTiBoostPIninTyp_C != 0)
      {
         Iupr_bAcvSpgSen =
         ( 0 >= Iupr_tiMinAcvSpg_C ) ? TRUE : FALSE;
         Iupr_tiAcvSpgSen = 0;
      }
      else
      {
         Iupr_bAcvSpgSen =
         ( Iupr_tiAcvSpgSen >= Iupr_tiMinAcvSpg_C ) ? TRUE : FALSE;
      }
   }

   bLocal_iupr_pSpg_denom_ok =
      ( ( TRUE == Iupr_bAcvSpgSen              ) &&
        ( TRUE == blocal_iupr_gen_denom_ok_par ) ) ? TRUE : FALSE;

   return bLocal_iupr_pSpg_denom_ok;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IUPRSPCDEN_bF07_tCoDiag                                    */
/* !Description :  Cette fonction produit le critère d'incrémentation du      */
/*                 dénominateur spécifique diagnostic "cold start" validés    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/* !Trace_To    :  VEMS_R_11_03254_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean IUPRSPCDEN_bF07_tCoDiag
(
   boolean blocal_iupr_gen_denom_ok_par,
   boolean blocal_Iupr_bColdStrt_par
)
{
   boolean bLocal_Iupr_tco_diag_denom_ok;


   if (  (blocal_Iupr_bColdStrt_par == TRUE)
      && (blocal_iupr_gen_denom_ok_par == TRUE))
   {
      bLocal_Iupr_tco_diag_denom_ok = TRUE;
   }
   else
   {
      bLocal_Iupr_tco_diag_denom_ok = FALSE;
   }

   return bLocal_Iupr_tco_diag_denom_ok;
}
/*------------------------------- end of file --------------------------------*/