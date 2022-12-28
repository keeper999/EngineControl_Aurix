/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : JDDISCANIF                                              */
/* !Description     : JDDISCANIF Component                                    */
/*                                                                            */
/* !Module          : JDDISCANIF                                              */
/* !Description     : SPECIFICATION D'INTERFACE ENTRE LE JDD ET L'ISCAN       */
/*                                                                            */
/* !File            : JDDISCANIF_FCT1.C                                       */
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
/*   1 / JDDISCANIF_vidInit                                                   */
/*   2 / JDDISCANIF_vidPrepaDataISCAN                                         */
/*   3 / JDDISCANIF_vidHdTreat                                                */
/*   4 / JDDISCANIF_vidAEE2010Treat                                           */
/*   5 / JDDISCANIF_vidDftCodTreat                                            */
/*   6 / JDDISCANIF_vidDstTreat                                               */
/*   7 / JDDISCANIF_vidDftTime                                                */
/*   8 / JDDISCANIF_vidVehCdn                                                 */
/*   9 / JDDISCANIF_vidRcdTreat                                               */
/*   10 / JDDISCANIF_vidAEE2004Treat                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 02911 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#054516                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/JDDISCANIF/JDDISCANIF_FCT1.C_v  $*/
/* $Revision::   1.0      $$Author::   fguillon       $$Date::   14 Jun 2011 $*/
/* $Author::   fguillon                               $$Date::   14 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "JDDISCANIF.h"
#include "JDDISCANIF_L.h"
#include "JDDISCANIF_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidInit                                         */
/* !Description :  Fonction d'initialisation des paramètres produits          */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Jbsi_pertinence_info_cmm;                                  */
/*  output uint8 Jbsi_IscanBufferPos1;                                        */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidInit(void)
{
   Jbsi_pertinence_info_cmm = 1;
   VEMS_vidSET(Jbsi_IscanBufferPos1, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos2, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos3, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos4, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos5, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos6, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos7, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos8, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidPrepaDataISCAN                               */
/* !Description :  Sur chaque demande d’émission de trame du JDD vers la BSI, */
/*                 on teste l’architecture électrique et électronique, afin de*/
/*                 déterminer le traitement à effectuer.                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDDISCANIF_vidHdTreat();                                 */
/*  extf argret void JDDISCANIF_vidAEE2010Treat();                            */
/*  extf argret void JDDISCANIF_vidAEE2004Treat();                            */
/*  input boolean Ext_bArchiCf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidPrepaDataISCAN(void)
{
   boolean bLocalExt_bArchiCf;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   JDDISCANIF_vidHdTreat();
   if (bLocalExt_bArchiCf != 0)
   {
      JDDISCANIF_vidAEE2010Treat();
   }
   else
   {
      JDDISCANIF_vidAEE2004Treat();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidHdTreat                                      */
/* !Description :  L'octet d'entête de chaque trame à émettre doit respecter  */
/*                 le format de codage du  constructeur                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Jbsi_etat_dtc;                                              */
/*  input uint8 Jbsi_type_message;                                            */
/*  input uint8 Jbsi_numero_trame;                                            */
/*  input uint8 Jbsi_nombre_trame;                                            */
/*  output uint8 Jbsi_IscanBufferPos1;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidHdTreat(void)
{
   boolean bLocalJbsi_etat_dtc;
   uint8   u8LocalJbsi_type_message;
   uint8   u8LocalJbsi_numero_trame;
   uint8   u8LocalJbsi_nombre_trame;
   uint8   u8LocalPos1;


   VEMS_vidGET(Jbsi_etat_dtc, bLocalJbsi_etat_dtc);
   VEMS_vidGET(Jbsi_type_message, u8LocalJbsi_type_message);
   VEMS_vidGET(Jbsi_numero_trame, u8LocalJbsi_numero_trame);
   VEMS_vidGET(Jbsi_nombre_trame, u8LocalJbsi_nombre_trame);
   u8LocalPos1 = (uint8)( (u8LocalJbsi_type_message & 0x03)
                        + (bLocalJbsi_etat_dtc << 3)
                        + ((u8LocalJbsi_numero_trame & 0x03) << 4)
                        + ((u8LocalJbsi_nombre_trame & 0x03) << 6));
   VEMS_vidSET(Jbsi_IscanBufferPos1, u8LocalPos1);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidAEE2010Treat                                 */
/* !Description :  Pour une AEE 2010, on traite les données en fonction de    */
/*                 leur appartenance à la première ou à la deuxième trame.    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_001.01                                     */
/*                 VEMS_R_11_02911_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDDISCANIF_vidDftCodTreat();                             */
/*  extf argret void JDDISCANIF_vidDftTime();                                 */
/*  extf argret void JDDISCANIF_vidDstTreat();                                */
/*  extf argret void JDDISCANIF_vidVehCdn();                                  */
/*  input uint8 Jbsi_numero_trame;                                            */
/*  output boolean Jbsi_pertinence_info_cmm;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidAEE2010Treat(void)
{
   uint8 u8LocalJbsi_numero_trame;


   Jbsi_pertinence_info_cmm = 0;
   VEMS_vidGET(Jbsi_numero_trame, u8LocalJbsi_numero_trame);
   if (u8LocalJbsi_numero_trame == 1)
   {
      JDDISCANIF_vidDftCodTreat();
      JDDISCANIF_vidDftTime();
   }
   else
   {
      if (u8LocalJbsi_numero_trame == 2)
      {
         JDDISCANIF_vidDstTreat();
         JDDISCANIF_vidVehCdn();
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidDftCodTreat                                  */
/* !Description :  Le code défaut, émis vers le BSI dans la trame n 1, doit   */
/*                 respecter le format de codage  du constructeur             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Jbsi_code_defaut;                                            */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidDftCodTreat(void)
{
   uint8  u8LocalPos4;
   uint8  u8LocalPos3;
   uint8  u8LocalPos2;
   uint32 u32LocalJbsi_code_defaut;


   VEMS_vidGET(Jbsi_code_defaut, u32LocalJbsi_code_defaut);
   u8LocalPos4 = (uint8)(u32LocalJbsi_code_defaut & 0xFF);
   u8LocalPos3 = (uint8)((u32LocalJbsi_code_defaut & 0xFF00) >> 8);
   u8LocalPos2 = (uint8)((u32LocalJbsi_code_defaut & 0xFF0000) >> 16);
   VEMS_vidSET(Jbsi_IscanBufferPos4, u8LocalPos4);
   VEMS_vidSET(Jbsi_IscanBufferPos3, u8LocalPos3);
   VEMS_vidSET(Jbsi_IscanBufferPos2, u8LocalPos2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidDstTreat                                     */
/* !Description :  L'information kilométrage du défaut, émise vers la BSI dans*/
/*                 la trame n 2, doit respecter  le format de codage du       */
/*                 constructeur                                               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Jbsi_kilometrage;                                            */
/*  output uint8 Jbsi_IscanBufferPos4;                                        */
/*  output uint8 Jbsi_IscanBufferPos3;                                        */
/*  output uint8 Jbsi_IscanBufferPos2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidDstTreat(void)
{
   uint8  u8LocalPos4;
   uint8  u8LocalPos3;
   uint8  u8LocalPos2;
   uint32 u32LocalJbsi_kilometrage;


   VEMS_vidGET(Jbsi_kilometrage, u32LocalJbsi_kilometrage);
   if (u32LocalJbsi_kilometrage == 0)
   {
      u8LocalPos2 = 0;
      u8LocalPos3 = 0;
      u8LocalPos4 = 0;
   }
   else
   {
      u8LocalPos4 = (uint8)(u32LocalJbsi_kilometrage & 0xFF);
      u8LocalPos3 = (uint8)((u32LocalJbsi_kilometrage & 0xFF00) >> 8);
      u8LocalPos2 = (uint8)( ((u32LocalJbsi_kilometrage & 0xFF0000) >> 16)
                           | 0x80);
   }
   VEMS_vidSET(Jbsi_IscanBufferPos4, u8LocalPos4);
   VEMS_vidSET(Jbsi_IscanBufferPos3, u8LocalPos3);
   VEMS_vidSET(Jbsi_IscanBufferPos2, u8LocalPos2);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidDftTime                                      */
/* !Description :  La référence horaire du défaut, émise vers le BSI dans la  */
/*                 trame n 1, doit respecter le  format de codage du          */
/*                 constructeur                                               */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Jbsi_ref_horaire;                                            */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidDftTime(void)
{
   uint8  u8LocalPos8;
   uint8  u8LocalPos7;
   uint8  u8LocalPos6;
   uint8  u8LocalPos5;
   uint32 u32LocalJbsi_ref_horaire;


   VEMS_vidGET(Jbsi_ref_horaire, u32LocalJbsi_ref_horaire);
   u8LocalPos8 = (uint8)(u32LocalJbsi_ref_horaire & 0xFF);
   u8LocalPos7 = (uint8)((u32LocalJbsi_ref_horaire & 0xFF00) >> 8);
   u8LocalPos6 = (uint8)((u32LocalJbsi_ref_horaire & 0xFF0000) >> 16);
   u8LocalPos5 = (uint8)((u32LocalJbsi_ref_horaire & 0xFF000000UL) >> 24);
   VEMS_vidSET(Jbsi_IscanBufferPos8, u8LocalPos8);
   VEMS_vidSET(Jbsi_IscanBufferPos7, u8LocalPos7);
   VEMS_vidSET(Jbsi_IscanBufferPos6, u8LocalPos6);
   VEMS_vidSET(Jbsi_IscanBufferPos5, u8LocalPos5);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidVehCdn                                       */
/* !Description :  L'information situation de vie, émise vers le BSI dans la  */
/*                 trame n 2, doit respecter le  format de codage du          */
/*                 constructeur                                               */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_006.01                                     */
/*                 VEMS_R_11_02911_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDDISCANIF_vidRcdTreat();                                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Jbsi_etat_reseau_electrique;                                  */
/*  input uint8 Jbsi_info_moteur_therm;                                       */
/*  input uint8 Jbsi_etat_principal_sev;                                      */
/*  input uint8 Jbsi_shunt_parc_bsi;                                          */
/*  input uint8 Jbsi_etat_alimentation;                                       */
/*  input boolean Jbsi_pertinence_info_bsi;                                   */
/*  input uint8 Jbsi_etat_rcd_tx;                                             */
/*  input boolean Jbsi_pertinence_info_cmm;                                   */
/*  output uint8 Jbsi_IscanBufferPos8;                                        */
/*  output uint8 Jbsi_IscanBufferPos7;                                        */
/*  output uint8 Jbsi_IscanBufferPos6;                                        */
/*  output uint8 Jbsi_IscanBufferPos5;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidVehCdn(void)
{
   boolean bLocalJbsi_pertinence_info_bsi;
   uint8   u8LocalPos7;
   uint8   u8LocalPos6;
   uint8   u8LocalPos5;
   uint8   u8LocalJbsi_etat_reseau_electriq;
   uint8   u8LocalJbsi_info_moteur_therm;
   uint8   u8LocalJbsi_etat_principal_sev;
   uint8   u8LocalJbsi_shunt_parc_bsi;
   uint8   u8LocalJbsi_etat_alimentation;


   VEMS_vidGET(Jbsi_etat_reseau_electrique, u8LocalJbsi_etat_reseau_electriq);
   VEMS_vidGET(Jbsi_info_moteur_therm, u8LocalJbsi_info_moteur_therm);
   VEMS_vidGET(Jbsi_etat_principal_sev, u8LocalJbsi_etat_principal_sev);
   VEMS_vidGET(Jbsi_shunt_parc_bsi, u8LocalJbsi_shunt_parc_bsi);
   VEMS_vidGET(Jbsi_etat_alimentation, u8LocalJbsi_etat_alimentation);
   VEMS_vidGET(Jbsi_pertinence_info_bsi, bLocalJbsi_pertinence_info_bsi);
   u8LocalPos7 = (uint8)((u8LocalJbsi_etat_reseau_electriq & 0x0F) << 4);
   u8LocalPos6 = (uint8)( ((u8LocalJbsi_info_moteur_therm) & 0x0F)
                        + ((u8LocalJbsi_etat_principal_sev & 0x03) << 4)
                        + ((u8LocalJbsi_shunt_parc_bsi & 0x03) << 6));
   JDDISCANIF_vidRcdTreat();
   u8LocalPos5 = (uint8)( (u8LocalJbsi_etat_alimentation & 0x07)
                        + ((Jbsi_etat_rcd_tx & 0x07) << 3)
                        + (Jbsi_pertinence_info_cmm << 6)
                        + (bLocalJbsi_pertinence_info_bsi << 7));

   VEMS_vidSET(Jbsi_IscanBufferPos8, 0);
   VEMS_vidSET(Jbsi_IscanBufferPos7, u8LocalPos7);
   VEMS_vidSET(Jbsi_IscanBufferPos6, u8LocalPos6);
   VEMS_vidSET(Jbsi_IscanBufferPos5, u8LocalPos5);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidRcdTreat                                     */
/* !Description :  Fonction qui détermine L’information Etat automate RCD à   */
/*                 émettre                                                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Rcd_mode_active;                                            */
/*  input st111 Jbsi_etat_rcd;                                                */
/*  output uint8 Jbsi_etat_rcd_tx;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidRcdTreat(void)
{
   uint8 u8LocalJbsi_etat_rcd;


   if (Rcd_mode_active == 0)
   {
      Jbsi_etat_rcd_tx = 7;
   }
   else
   {
      VEMS_vidGET(Jbsi_etat_rcd, u8LocalJbsi_etat_rcd);
      switch (u8LocalJbsi_etat_rcd)
      {
         case JBSI_ANTICIPATION:
            Jbsi_etat_rcd_tx = 1;
            break;

         case JBSI_POWER_LATCH:
            Jbsi_etat_rcd_tx = 3;
            break;

         case JBSI_TRANSIT:
            Jbsi_etat_rcd_tx = 3;
            break;

         case JBSI_POWER_ON:
            Jbsi_etat_rcd_tx = 4;
            break;

         case JBSI_POWER_ON_DEFAUT:
            Jbsi_etat_rcd_tx = 5;
            break;

         case JBSI_SLEEPING:
            Jbsi_etat_rcd_tx = 6;
            break;

         default:
            Jbsi_etat_rcd_tx = 0;
            break;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  JDDISCANIF_vidAEE2004Treat                                 */
/* !Description :  Le traitement des trames pour une AEE 2004 ou 2007 n’est   */
/*                 pas encore spécifie. Néanmoins il est pris en compte dans  */
/*                 l’architecture de cette NT.                                */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_R_11_02911_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void JDDISCANIF_vid1Trame();                                  */
/*  extf argret void JDDISCANIF_vid3Trames();                                 */
/*  input boolean Jbsi_etat_dtc;                                              */
/*  input boolean Jbsi_manu_inh_3_trames_evt_fug;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void JDDISCANIF_vidAEE2004Treat(void)
{
   boolean bLocalJbsi_etat_dtc;


   VEMS_vidGET(Jbsi_etat_dtc, bLocalJbsi_etat_dtc);
   if (  (bLocalJbsi_etat_dtc == 0)
      && (Jbsi_manu_inh_3_trames_evt_fug != 0))
   {
      JDDISCANIF_vid1Trame();
   }
   else
   {
      JDDISCANIF_vid3Trames();
   }
}
/*------------------------------- end of file --------------------------------*/