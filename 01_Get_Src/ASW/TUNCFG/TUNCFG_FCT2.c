/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TUNCFG                                                  */
/* !Description     : TUNCFG component.                                       */
/*                                                                            */
/* !Module          : TUNCFG                                                  */
/* !Description     : GESTION DES DIVERSITES                                  */
/*                                                                            */
/* !File            : TUNCFG_FCT2.C                                           */
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
/*   1 / TUNCFG_vidUCSelLsb                                                   */
/*   2 / TUNCFG_vidUCSelMsb                                                   */
/*   3 / TUNCFG_vidSelCfg                                                     */
/*   4 / TUNCFG_vidGEESel                                                     */
/*   5 / TUNCFG_vidDAGMPSel                                                   */
/*   6 / TUNCFG_vidDCTSel                                                     */
/*   7 / TUNCFG_vidCANAdapt                                                   */
/*   8 / TUNCFG_vidAltClassSel                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5304544 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TUNCFG/TUNCFG_FCT2.C_v          $*/
/* $Revision::   1.17     $$Author::   pbakabad       $$Date::   Jun 28 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 28 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TUNCFG.h"
#include "TUNCFG_L.h"
#include "TUNCFG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidUCSelLsb                                         */
/* !Description :  Les fonctions ABS, BVV, DSG, ESP ASR, FSE, LVV et RVV sont */
/*                 sélectionnées et créent les flux associés.                 */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_020.02                                     */
/*                 VEMS_R_11_02421_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Tele_program_uc;                                             */
/*  input boolean Ext_bEPBCf;                                                 */
/*  output boolean Ext_bASRESPCf;                                             */
/*  output boolean Esp_present;                                               */
/*  output uint8 Ext_stDVSRegCf;                                              */
/*  output boolean Ext_bVSRegCf;                                              */
/*  output boolean Amvar_present;                                             */
/*  output boolean Ext_bEasyMoveCf;                                           */
/*  output boolean Ext_bEPBCf;                                                */
/*  output boolean Ext_bBrkDynCf;                                             */
/*  output boolean Ext_bFSFCf;                                                */
/*  output boolean Ext_bBrkParkCf;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidUCSelLsb(void)
{
   boolean  bLocalExt_bVSRegCf;
   boolean  bLocalExt_bEPBCf;
   uint32   u32LocalTele_uc;


   VEMS_vidGET(Tele_program_uc, u32LocalTele_uc);

   if ( (u32LocalTele_uc & 0x00000001) == 0x00000001)
   {
      VEMS_vidSET(Ext_bASRESPCf, 0);
      VEMS_vidSET(Esp_present, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bASRESPCf, 1);
      VEMS_vidSET(Esp_present, 1);
   }
   if (  ( (u32LocalTele_uc & 0x00000002) == 0x00000002)
      && ( (u32LocalTele_uc & 0x00002000) == 0x00002000))
   {
      bLocalExt_bVSRegCf = 0;
   }
   else
   {
      bLocalExt_bVSRegCf = 1;
   }
   if ((u32LocalTele_uc & 0x00000002) == 0x00000002)
   {
      VEMS_vidSET(Ext_stDVSRegCf, 2);
   }
   else
   {
      if (bLocalExt_bVSRegCf != 0)
      {
         VEMS_vidSET(Ext_stDVSRegCf, 1);
      }
      else
      {
         VEMS_vidSET(Ext_stDVSRegCf, 0);
      }
   }
   VEMS_vidSET(Ext_bVSRegCf, bLocalExt_bVSRegCf);

   if ( (u32LocalTele_uc & 0x00000040) == 0x00000040)
   {
      VEMS_vidSET(Amvar_present, 0);
   }
   else
   {
      VEMS_vidSET(Amvar_present, 1);
   }

   if ( (u32LocalTele_uc & 0x00000080) == 0x00000080)
   {
      VEMS_vidSET(Ext_bEasyMoveCf, 0);
      VEMS_vidSET(Ext_bEPBCf, 0);
      VEMS_vidSET(Ext_bBrkDynCf, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bEasyMoveCf, 1);
      VEMS_vidSET(Ext_bEPBCf, 1);
      VEMS_vidSET(Ext_bBrkDynCf, 1);
   }

   if ( (u32LocalTele_uc & 0x00000010) == 0x00000010)
   {
      VEMS_vidSET(Ext_bFSFCf, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bFSFCf, 0);
   }

   VEMS_vidGET(Ext_bEPBCf, bLocalExt_bEPBCf);
   if (bLocalExt_bEPBCf == 0)
   {
      VEMS_vidSET(Ext_bBrkParkCf, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bBrkParkCf, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidUCSelMsb                                         */
/* !Description :  Les fonctions ABS, BVV, DSG, ESP ASR, FSE, LVV et RVV sont */
/*                 sélectionnées et créent les flux associés.                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_020.02                                     */
/*                 VEMS_R_11_02421_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Tele_program_uc;                                             */
/*  input boolean Ext_bABSCf;                                                 */
/*  input boolean Ext_bSpdCf;                                                 */
/*  output boolean Da_present;                                                */
/*  output boolean Ext_bABSCf;                                                */
/*  output boolean Abs_mux;                                                   */
/*  output boolean Ext_bVSLimCf;                                              */
/*  output boolean Ext_bStrtDrvIfCf;                                          */
/*  output boolean Ext_bBPGACf;                                               */
/*  output boolean Ext_bBlowBy1Cf;                                            */
/*  output boolean Ext_bSpdFrntWhlCf;                                         */
/*  output boolean Ext_bSpdReWhlCf;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidUCSelMsb(void)
{
   boolean bLocalExt_bABSCf;
   boolean bLocalExt_bSpdCf;
   uint32  u32LocalTele_uc;


   VEMS_vidGET(Tele_program_uc, u32LocalTele_uc);

   if ( (u32LocalTele_uc & 0x00000200) == 0x00000200)
   {
      VEMS_vidSET(Da_present, 0);
   }
   else
   {
      VEMS_vidSET(Da_present, 1);
   }

   if ( (u32LocalTele_uc & 0x00000400) == 0x00000400)
   {
      VEMS_vidSET(Ext_bABSCf, 0);
      VEMS_vidSET(Abs_mux, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bABSCf, 1);
      VEMS_vidSET(Abs_mux, 1);
   }

   if ( (u32LocalTele_uc & 0x00001000) == 0x00001000)
   {
      VEMS_vidSET(Ext_bVSLimCf, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bVSLimCf, 1);
   }

   if ( (u32LocalTele_uc & 0x00004000) == 0x00004000)
   {
      VEMS_vidSET(Ext_bStrtDrvIfCf, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bStrtDrvIfCf, 0);
   }

   if ( (u32LocalTele_uc & 0x00010000) == 0x00010000)
   {
      VEMS_vidSET(Ext_bBPGACf, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bBPGACf, 1);
   }

   if ( (u32LocalTele_uc & 0x00020000) == 0x00020000)
   {
      VEMS_vidSET(Ext_bBlowBy1Cf, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bBlowBy1Cf, 1);
   }

   VEMS_vidGET(Ext_bABSCf, bLocalExt_bABSCf);
   VEMS_vidGET(Ext_bSpdCf, bLocalExt_bSpdCf);
   if (  (bLocalExt_bABSCf != 0)
      && (bLocalExt_bSpdCf == 0))
   {
      VEMS_vidSET(Ext_bSpdFrntWhlCf, 1);
      VEMS_vidSET(Ext_bSpdReWhlCf, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bSpdFrntWhlCf, 0);
      VEMS_vidSET(Ext_bSpdReWhlCf, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidSelCfg                                           */
/* !Description :  Cette fonction permet de spécifier le type de DAGMP et le  */
/*                 type d’alternateur embarqués sur le véhicule.              */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TUNCFG_vidGEESel();                                      */
/*  extf argret void TUNCFG_vidDAGMPSel();                                    */
/*  extf argret void TUNCFG_vidDCTSel();                                      */
/*  extf argret void TUNCFG_vidCANAdapt();                                    */
/*  extf argret void TUNCFG_vidAltClassSel();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidSelCfg(void)
{
   TUNCFG_vidGEESel();
   TUNCFG_vidDAGMPSel();
   TUNCFG_vidDCTSel();
   TUNCFG_vidCANAdapt();
   TUNCFG_vidAltClassSel();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidGEESel                                           */
/* !Description :  Le type d’alternateur (standard, pilotée, réversible,      */
/*                 convertisseur DC/DC)                                       */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_022.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stFuTypCf;                                                */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 Ext_stElEMgtCf;                                               */
/*  input uint8 Ext_stStrtRstrtDevCf;                                         */
/*  output uint8 Ext_stElProdCf;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidGEESel(void)
{
   uint8 u8LocalExt_stElEMgtCf;
   uint8 u8LocalExt_stDrivAltMgt_Cf;
   uint8 u8LocalExt_stStrtRstrtDevCf;
   uint8 u8LocalExt_stFuTypCf;


   VEMS_vidGET(Ext_stFuTypCf, u8LocalExt_stFuTypCf);
   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);
   if (  (u8LocalExt_stDrivAltMgt_Cf == 2)
      && (  (u8LocalExt_stFuTypCf == 2)
         || (u8LocalExt_stFuTypCf == 3)))
   {
      VEMS_vidSET(Ext_stElProdCf, 3);
   }
   else
   {
      VEMS_vidGET(Ext_stElEMgtCf, u8LocalExt_stElEMgtCf);
      VEMS_vidGET(Ext_stStrtRstrtDevCf, u8LocalExt_stStrtRstrtDevCf);
      if (  (u8LocalExt_stDrivAltMgt_Cf == 0)
         && (u8LocalExt_stElEMgtCf == 5)
         && (  (u8LocalExt_stStrtRstrtDevCf == 2)
            || (u8LocalExt_stStrtRstrtDevCf == 5))
         && (  (u8LocalExt_stFuTypCf == 0)
            || (u8LocalExt_stFuTypCf == 1)))
      {
         VEMS_vidSET(Ext_stElProdCf, 2);
      }
      else
      {
         if (  (  (u8LocalExt_stStrtRstrtDevCf == 0)
               || (u8LocalExt_stStrtRstrtDevCf == 3)
               || (u8LocalExt_stStrtRstrtDevCf == 4))
            && (u8LocalExt_stElEMgtCf == 5)
            && (  (u8LocalExt_stDrivAltMgt_Cf == 0)
               || (u8LocalExt_stDrivAltMgt_Cf == 1))
            && (  (u8LocalExt_stFuTypCf == 0)
               || (u8LocalExt_stFuTypCf == 1) ))
         {
            VEMS_vidSET(Ext_stElProdCf, 1);
         }
         else
         {
            VEMS_vidSET(Ext_stElProdCf, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidDAGMPSel                                         */
/* !Description :  La configuration DAGMP dépend de l’architecture électrique */
/*                 de véhicule et de la présence d’une clé ou un push.        */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean Ext_bStrtDrvIfCf;                                           */
/*  input boolean Ext_bStrtDrvIfTypCf;                                        */
/*  output uint8 Ext_stStrtCf;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidDAGMPSel(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalExt_bStrtDrvIfCf;
   boolean bLocalExt_bStrtDrvIfTypCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (bLocalExt_bArchiCf == 0)
   {
      VEMS_vidSET(Ext_stStrtCf, 1);
   }
   else
   {
      VEMS_vidGET(Ext_bStrtDrvIfCf, bLocalExt_bStrtDrvIfCf);
      if (bLocalExt_bStrtDrvIfCf == 0)
      {
         VEMS_vidSET(Ext_stStrtCf, 0);
      }
      else
      {
         VEMS_vidGET(Ext_bStrtDrvIfTypCf, bLocalExt_bStrtDrvIfTypCf);
         if (bLocalExt_bStrtDrvIfTypCf == 0)
         {
            VEMS_vidSET(Ext_stStrtCf, 2);
         }
         else
         {
            VEMS_vidSET(Ext_stStrtCf, 3);
         }
      }
   }

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidDCTSel                                           */
/* !Description :  Gestion de la diversité des pièces de la fonction chauffage*/
/*                 additionnel                                                */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_027.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stCabHeatVarCf;                                           */
/*  input boolean Ext_bCabHeatDCT_C;                                          */
/*  output uint8 Ext_stCabHeatCf;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidDCTSel(void)
{
   uint8 u8LocalExt_stCabHeatVarCf;
   uint8 u8LocalValue1;
   uint8 u8LocalValue2;
   uint8 u8LocalValue3;


   VEMS_vidGET(Ext_stCabHeatVarCf, u8LocalExt_stCabHeatVarCf);

   if (Ext_bCabHeatDCT_C != 0)
   {
      u8LocalValue1 = 4;
      u8LocalValue2 = 2;
      u8LocalValue3 = 6;
   }
   else
   {
      u8LocalValue1 = 0;
      u8LocalValue2 = 1;
      u8LocalValue3 = 5;
   }
   if (u8LocalExt_stCabHeatVarCf == 0)
   {
      VEMS_vidSET(Ext_stCabHeatCf, u8LocalValue1);
   }
   else
   {
      if (  (u8LocalExt_stCabHeatVarCf == 1)
         || (u8LocalExt_stCabHeatVarCf == 2))
      {
         VEMS_vidSET(Ext_stCabHeatCf, u8LocalValue2);
      }
      else
      {
         if (  (u8LocalExt_stCabHeatVarCf == 5)
            || (u8LocalExt_stCabHeatVarCf == 6))
         {
            VEMS_vidSET(Ext_stCabHeatCf, u8LocalValue3);
         }
         else
         {
            VEMS_vidSET(Ext_stCabHeatCf, 0);
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidCANAdapt                                         */
/* !Description :  cette fonction permet de produire la configuration BVV     */
/*                 paramétrable.                                              */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_spdVehVSMaxPrmaReq1;                                      */
/*  input uint8 Ext_spdVehVSMaxPrmaReq2;                                      */
/*  output boolean Ext_bVSMaxpCf;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidCANAdapt(void)
{
   uint8 u8LocalExt_spdVehVSMaxPrmaReq1;
   uint8 u8LocalExt_spdVehVSMaxPrmaReq2;


   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq1, u8LocalExt_spdVehVSMaxPrmaReq1);
   VEMS_vidGET(Ext_spdVehVSMaxPrmaReq2, u8LocalExt_spdVehVSMaxPrmaReq2);

   if (  (u8LocalExt_spdVehVSMaxPrmaReq1 != 255)
      && (u8LocalExt_spdVehVSMaxPrmaReq1 == u8LocalExt_spdVehVSMaxPrmaReq2))
   {
      VEMS_vidSET(Ext_bVSMaxpCf, 1);
   }
   else
   {
      VEMS_vidSET(Ext_bVSMaxpCf, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TUNCFG_vidAltClassSel                                      */
/* !Description :  Gestion de la classe d'alternateur.                        */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02421_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input st44 Ext_stAltClasBSSCf;                                            */
/*  input uint8 Ext_idxAltClas;                                               */
/*  input uint8 Ext_stAltClasVarCf;                                           */
/*  input bool Cl15_BOSCH_LIX_C2;                                             */
/*  input bool Cl15_VALEO_FG15T044;                                           */
/*  input bool Cl12_VALEO_TG12C;                                              */
/*  input bool Cl12_MELCO_6GA3_d135mm;                                        */
/*  input bool Cl8_MELCO_6GA3_d121mm;                                         */
/*  input bool Cl18_MELCO_9G135Hd135mm;                                       */
/*  output uint8 Ext_stAltClasCf;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TUNCFG_vidAltClassSel(void)
{
   uint8 u8LocalExt_stAltClasVarCf;
   uint8 u8LocalExt_stDrivAltMgt_Cf;
   uint8 u8LocalExt_stAltClasBSSCf;
   uint8 u8LocalExt_idxAltClas;


   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);
   VEMS_vidGET(Ext_stAltClasBSSCf, u8LocalExt_stAltClasBSSCf);
   VEMS_vidGET(Ext_idxAltClas, u8LocalExt_idxAltClas);
   VEMS_vidGET(Ext_stAltClasVarCf, u8LocalExt_stAltClasVarCf);

   if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_NOSUBNET)
   {
      u8LocalExt_stAltClasVarCf =
         (uint8)MATHSRV_udtMIN(u8LocalExt_stAltClasVarCf ,7);
      VEMS_vidSET(Ext_stAltClasCf, u8LocalExt_stAltClasVarCf);
   }
   else
   {
      if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
      {
         switch (u8LocalExt_stAltClasBSSCf)
         {
            case Cl15_BOSCH_LIX_C2:
            case Cl15_VALEO_FG15T044:
               VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_15);
               break;

            case Cl12_VALEO_TG12C:
            case Cl12_MELCO_6GA3_d135mm:
               VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_12);
               break;

            case Cl8_MELCO_6GA3_d121mm:
               VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_8p);
               break;

            case Cl18_MELCO_9G135Hd135mm:
               VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_18);
               break;

            default:
               VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_7);
         }
      }
      else
      {
         if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN)
         {
            switch (u8LocalExt_idxAltClas)
            {
               case ALT_CLASS_LIN_7:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_7);
                  break;

               case ALT_CLASS_LIN_8p:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_8p);
                  break;

               case ALT_CLASS_LIN_12:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_12);
                  break;

               case ALT_CLASS_LIN_15:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_15);
                  break;

               case ALT_CLASS_LIN_18:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_18);
                  break;

               case ALT_CLASS_LIN_22:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_22);
                  break;

               default:
                  VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_7);
            }
         }
         else
         {
            VEMS_vidSET(Ext_stAltClasCf, ALTERNATEUR_7);
         }
      }
   }
}

/*----------------------------- end of file ----------------------------------*/