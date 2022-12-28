/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RELBRKASIACQ                                            */
/* !Description     : RELBRKASIACQ Component                                  */
/*                                                                            */
/* !Module          : RELBRKASIACQ                                            */
/* !Description     : Relative Mastervac Pressure Acquisition                 */
/*                                                                            */
/* !File            : RELBRKASIACQ_FCT2.C                                     */
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
/*   1 / RELBRKASIACQ_vidSftLvl2                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6547160 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RELBRKASIACQ/RELBRKASIACQ_FCT2.C_v$*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "RELBRKASIACQ.h"
#include "RELBRKASIACQ_l.h"
#include "RELBRKASIACQ_IM.h"
#include "LIBSFTYLVL2.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidSftLvl2                                    */
/* !Description :  The aim of this function is to satisfy the requirement of  */
/*                 safety level 2 for the mastervac relative pressure sensor. */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoScp_pRelBrkAsi;                                     */
/*  input uint8 AirPres_nUpTranThd_ScpRelAsi_C;                               */
/*  input uint8 AirPres_nDownTranThd_ScpRelAsi_C;                             */
/*  input uint8 AirPres_nInitCptConf_ScpRelAsi_C;                             */
/*  input uint8 AirPres_nDecCpt_ScpRelBrkAsi_C;                               */
/*  input uint8 RELBRKASIACQ_u8CntFilt_1;                                     */
/*  input boolean RELBRKASIACQ_bFilSig_1;                                     */
/*  input uint8 AirPres_ctDftSftyScp_pRelBrkAsi;                              */
/*  input boolean RELBRKASIACQ_bScp_pRelBrkAsi;                               */
/*  input boolean Ext_bDgoScg_pRelBrkAsi;                                     */
/*  input uint8 AirPres_nUpTranThd_ScgRelAsi_C;                               */
/*  input uint8 AirPres_nDownTranThd_ScgRelAsi_C;                             */
/*  input uint8 AirPres_nInitCptConf_ScgRelAsi_C;                             */
/*  input uint8 AirPres_nDecCpt_ScgRelBrkAsi_C;                               */
/*  input uint8 RELBRKASIACQ_u8CntFilt_2;                                     */
/*  input boolean RELBRKASIACQ_bFilSig_2;                                     */
/*  input uint8 AirPres_ctDftSftyScg_pRelBrkAsi;                              */
/*  input boolean RELBRKASIACQ_bScg_pRelBrkAsi;                               */
/*  output boolean AirPres_bDftSftyScp_pRelBrkAsi;                            */
/*  output boolean RELBRKASIACQ_bScp_pRelBrkAsi;                              */
/*  output boolean AirPres_bDftSftyScg_pRelBrkAsi;                            */
/*  output boolean RELBRKASIACQ_bScg_pRelBrkAsi;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidSftLvl2(void)
{
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScp_pRelBrkAsi,
                                AirPres_nUpTranThd_ScpRelAsi_C,
                                AirPres_nDownTranThd_ScpRelAsi_C,
                                AirPres_nInitCptConf_ScpRelAsi_C,
                                AirPres_nDecCpt_ScpRelBrkAsi_C,
                                &RELBRKASIACQ_u8CntFilt_1,
                                &RELBRKASIACQ_bFilSig_1,
                                &AirPres_ctDftSftyScp_pRelBrkAsi,
                                &RELBRKASIACQ_bScp_pRelBrkAsi);
   VEMS_vidSET(AirPres_bDftSftyScp_pRelBrkAsi, RELBRKASIACQ_bScp_pRelBrkAsi);

   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScg_pRelBrkAsi,
                                AirPres_nUpTranThd_ScgRelAsi_C,
                                AirPres_nDownTranThd_ScgRelAsi_C,
                                AirPres_nInitCptConf_ScgRelAsi_C,
                                AirPres_nDecCpt_ScgRelBrkAsi_C,
                                &RELBRKASIACQ_u8CntFilt_2,
                                &RELBRKASIACQ_bFilSig_2,
                                &AirPres_ctDftSftyScg_pRelBrkAsi,
                                &RELBRKASIACQ_bScg_pRelBrkAsi);
   VEMS_vidSET(AirPres_bDftSftyScg_pRelBrkAsi, RELBRKASIACQ_bScg_pRelBrkAsi);
}
/*---------------------------- end of file -----------------------------------*/