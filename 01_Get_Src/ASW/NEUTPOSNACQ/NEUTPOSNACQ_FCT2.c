/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : NEUTPOSNACQ                                             */
/* !Description     : NEUTPOSNACQ component.                                  */
/*                                                                            */
/* !Module          : NEUTPOSNACQ                                             */
/* !Description     : ACQUISITION DE LA POSITION POINT MORT                   */
/*                                                                            */
/* !File            : NEUTPOSNACQ_FCT2.C                                      */
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
/*   1 / NEUTPOSNACQ_vidBneutNom                                              */
/*   2 / NEUTPOSNACQ_vidSafetyLevel2                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6533527 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/NEUTPOSNACQ/NEUTPOSNACQ_FCT2.C_v  $*/
/* $Revision::   1.0      $$Author::   achebino       $$Date::   27 May 2014 $*/
/* $Author::   achebino                               $$Date::   27 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "NEUTPOSNACQ.h"
#include "NEUTPOSNACQ_L.h"
#include "NEUTPOSNACQ_IM.h"
#include "LIBSFTYLVL2.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidBneutNom                                    */
/* !Description :  En mode nominal, le booléen de position point mort est issu*/
/*                 d’un hystérésis sur la valeur du RCO du signal du capteur  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bNeut;                                                  */
/*  input uint16 Ext_rNeut;                                                   */
/*  input uint16 Ext_rThdNeut2_C;                                             */
/*  input uint16 Ext_rThdNeut3_C;                                             */
/*  input uint16 Ext_rThdNeut1_C;                                             */
/*  input uint16 Ext_rThdNeut4_C;                                             */
/*  output boolean Ext_bNeutNom;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidBneutNom(void)
{
   boolean bLocalExt_bNeut;
   boolean bLocalHyst;
   uint16  u16LocalExt_rNeut;


   bLocalHyst = 0;
   VEMS_vidGET(Ext_bNeut, bLocalExt_bNeut);
   VEMS_vidGET(Ext_rNeut, u16LocalExt_rNeut);

   if (  (u16LocalExt_rNeut > Ext_rThdNeut2_C)
      && (u16LocalExt_rNeut < Ext_rThdNeut3_C))
   {
      bLocalHyst = 1;
   }
   else
   {
      if (  (u16LocalExt_rNeut > Ext_rThdNeut1_C)
         && (u16LocalExt_rNeut < Ext_rThdNeut4_C)
         && (bLocalExt_bNeut != 0) )
      {
         bLocalHyst = 1;
      }
   }
   Ext_bNeutNom = bLocalHyst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  NEUTPOSNACQ_vidSafetyLevel2                                */
/* !Description :  Cette fonction permet d’effectuer une stratégie safety de  */
/*                 niveau 2 sur le signal du capteur de point mort haut.      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoScp_bNeut;                                          */
/*  input uint8 NeutPosnAcq_nUpTranThd_Scp_C;                                 */
/*  input uint8 NeutPosnAcq_nDownTranThd_Scp_C;                               */
/*  input uint8 NeutPosnAcq_nInitCptConf_Scp_C;                               */
/*  input uint8 NeutPosnAcq_nDecCpt_Scp_C;                                    */
/*  input uint8 NEUTPOSNACQ_u8CntFilt_1;                                      */
/*  input boolean NEUTPOSNACQ_bFilSig_1;                                      */
/*  input uint8 NeutPosnAcq_ctDftSftyScp_bNeut;                               */
/*  input boolean NEUTPOSNACQ_bScp_bNeut;                                     */
/*  input boolean Ext_bDgoScg_bNeut;                                          */
/*  input uint8 NeutPosnAcq_nUpTranThd_Scg_C;                                 */
/*  input uint8 NeutPosnAcq_nDownTranThd_Scg_C;                               */
/*  input uint8 NeutPosnAcq_nInitCptConf_Scg_C;                               */
/*  input uint8 NeutPosnAcq_nDecCpt_Scg_C;                                    */
/*  input uint8 NEUTPOSNACQ_u8CntFilt_2;                                      */
/*  input boolean NEUTPOSNACQ_bFilSig_2;                                      */
/*  input uint8 NeutPosnAcq_ctDftSftyScg_bNeut;                               */
/*  input boolean NEUTPOSNACQ_bScg_bNeut;                                     */
/*  input boolean Ext_bDgoORng_bNeut;                                         */
/*  input uint8 NeutPosnAcq_nUpTranThd_ORng_C;                                */
/*  input uint8 NeutPosnAcq_nDownTranThd_ORng_C;                              */
/*  input uint8 NeutPosnAcq_nInitCptConf_ORng_C;                              */
/*  input uint8 NeutPosnAcq_nDecCpt_ORng_C;                                   */
/*  input uint8 NEUTPOSNACQ_u8CntFilt_3;                                      */
/*  input boolean NEUTPOSNACQ_bFilSig_3;                                      */
/*  input uint8 NeutPosnAcq_ctDftSftyORng_bNeut;                              */
/*  input boolean NEUTPOSNACQ_bORng_bNeut;                                    */
/*  output boolean NeutPosnAcq_bDftSftyScp_bNeut;                             */
/*  output boolean NEUTPOSNACQ_bScp_bNeut;                                    */
/*  output boolean NeutPosnAcq_bDftSftyScg_bNeut;                             */
/*  output boolean NEUTPOSNACQ_bScg_bNeut;                                    */
/*  output boolean NeutPosnAcq_bDftSftyORng_bNeut;                            */
/*  output boolean NEUTPOSNACQ_bORng_bNeut;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NEUTPOSNACQ_vidSafetyLevel2(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScp_bNeut,
                                NeutPosnAcq_nUpTranThd_Scp_C,
                                NeutPosnAcq_nDownTranThd_Scp_C,
                                NeutPosnAcq_nInitCptConf_Scp_C,
                                NeutPosnAcq_nDecCpt_Scp_C,
                                &NEUTPOSNACQ_u8CntFilt_1,
                                &NEUTPOSNACQ_bFilSig_1,
                                &NeutPosnAcq_ctDftSftyScp_bNeut,
                                &NEUTPOSNACQ_bScp_bNeut);
   VEMS_vidSET(NeutPosnAcq_bDftSftyScp_bNeut, NEUTPOSNACQ_bScp_bNeut);

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScg_bNeut,
                                NeutPosnAcq_nUpTranThd_Scg_C,
                                NeutPosnAcq_nDownTranThd_Scg_C,
                                NeutPosnAcq_nInitCptConf_Scg_C,
                                NeutPosnAcq_nDecCpt_Scg_C,
                                &NEUTPOSNACQ_u8CntFilt_2,
                                &NEUTPOSNACQ_bFilSig_2,
                                &NeutPosnAcq_ctDftSftyScg_bNeut,
                                &NEUTPOSNACQ_bScg_bNeut);
   VEMS_vidSET(NeutPosnAcq_bDftSftyScg_bNeut, NEUTPOSNACQ_bScg_bNeut);

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoORng_bNeut,
                                NeutPosnAcq_nUpTranThd_ORng_C,
                                NeutPosnAcq_nDownTranThd_ORng_C,
                                NeutPosnAcq_nInitCptConf_ORng_C,
                                NeutPosnAcq_nDecCpt_ORng_C,
                                &NEUTPOSNACQ_u8CntFilt_3,
                                &NEUTPOSNACQ_bFilSig_3,
                                &NeutPosnAcq_ctDftSftyORng_bNeut,
                                &NEUTPOSNACQ_bORng_bNeut);
   VEMS_vidSET(NeutPosnAcq_bDftSftyORng_bNeut, NEUTPOSNACQ_bORng_bNeut);
}

/*---------------------------- end of file -----------------------------------*/