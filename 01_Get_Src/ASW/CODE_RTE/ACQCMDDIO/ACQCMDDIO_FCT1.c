/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ACQCMDDIO                                               */
/* !Description     : ACQCMDDIO component.                                    */
/*                                                                            */
/* !Module          : ACQCMDDIO                                               */
/* !Description     : SPECIFICATION DES COMMANDES ET ACQUISITIONS LOGIQUES    */
/*                                                                            */
/* !File            : ACQCMDDIO_FCT1.C                                        */
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
/*   1 / ACQCMDDIO_vidInit                                                    */
/*   2 / ACQCMDDIO_vidCmdDioPwr                                               */
/*   3 / ACQCMDDIO_vidMainRly                                                 */
/*   4 / ACQCMDDIO_vidPowerRly                                                */
/*   5 / ACQCMDDIO_vidFCmdDml                                                 */
/*   6 / ACQCMDDIO_vidOutpIdc                                                 */
/*   7 / ACQCMDDIO_vidAuthStrtSTT                                             */
/*   8 / ACQCMDDIO_vidBlowBy1                                                 */
/*   9 / ACQCMDDIO_vidBlowBy2                                                 */
/*   10 / ACQCMDDIO_vidSenO2Ds                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_6509298 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQCMDDIO/ACQCMDDIO_FCT1.C_v      $*/
/* $Revision::   1.5      $$Author::   achebino       $$Date::   19 Aug 2014 $*/
/* $Author::   achebino                               $$Date::   19 Aug 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#define VEMS_H_AUTOCODE_H
#include "STD_TYPES.H"
#include "ACQCMDDIO.H"
#include "ACQCMDDIO_L.H"
#include "ACQCMDDIO_IM.H"
#include "ACQCMDDIO_GATEWAY.H"
#include "DIOHAL.h"
#include "ACQCMDDIO_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidInit                                          */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void ACQCMDDIO_vidInitCoFan();                                */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*  output boolean Acquisition_pedale_embrayage_tor;                          */
/*  output boolean Acquisition_pression_huile_tor;                            */
/*  output boolean Acquisition_startlock_tor;                                 */
/*  output boolean Acquisition_pedale_frein_tor;                              */
/*  output boolean Acquisition_keypush_tor;                                   */
/*  output boolean Acquisition_etat_gmvB1_brut;                               */
/*  output boolean Acquisition_etat_gmvB2_brut;                               */
/*  output boolean Acquisition_cmde_reveil_rcd_tor;                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidInit(void)
{
   uint8 u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   VEMS_vidSET(Acquisition_pedale_embrayage_tor, 0);
   VEMS_vidSET(Acquisition_pression_huile_tor, 0);
   VEMS_vidSET(Acquisition_startlock_tor, 0);
   VEMS_vidSET(Acquisition_pedale_frein_tor, 0);
   VEMS_vidSET(Acquisition_keypush_tor, 0);
   VEMS_vidSET(Acquisition_etat_gmvB1_brut, 0);
   VEMS_vidSET(Acquisition_etat_gmvB2_brut, 0);
   VEMS_vidSET(Acquisition_cmde_reveil_rcd_tor, 0);
   if (  (u8LocalCfCoolFan == EQUIPMENT_B1)
      || (u8LocalCfCoolFan == EQUIPMENT_B2))
   {
      ACQCMDDIO_vidInitCoFan();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidCmdDioPwr                                     */
/* !Description :  Commande du DMTR pour maintenir la tension réseau.         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_maintien_dmtr_tor;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidCmdDioPwr(void)
{
   /*F01_CmdDioPwr*/
   boolean bLocalCmdMaintien_dmtr_tor;


   VEMS_vidGET(Commande_maintien_dmtr_tor, bLocalCmdMaintien_dmtr_tor);
   DIOHAL_vidWrite(CH_DIO_OUT_DMTR, bLocalCmdMaintien_dmtr_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidMainRly                                       */
/* !Description :  Commande du relais principal.                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_relais_principal;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidMainRly(void)
{
   /*F01_MainRly*/
   boolean bLocalCommande_relais_principal;


   VEMS_vidGET(Commande_relais_principal, bLocalCommande_relais_principal);
   DIOHAL_vidWrite(CH_DIO_OUT_MAIN_RELAY_CMD, bLocalCommande_relais_principal);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidPowerRly                                      */
/* !Description :  Commande du relais de puissance.                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_relais_puissance;                                  */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidPowerRly(void)
{
   /*F02_PowerRly*/
   boolean bLocalCommande_relais_puissance;


   VEMS_vidGET(Commande_relais_puissance, bLocalCommande_relais_puissance);
   DIOHAL_vidWrite(CH_DIO_OUT_ACTR_RELAY_CMD, bLocalCommande_relais_puissance);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidFCmdDml                                       */
/* !Description :  Etat de la commande de l'actionneur de la sortie logique.  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Cmde_logique_dml_tor;                                       */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidFCmdDml(void)
{
   /*F01_CmdDml*/
   boolean bLocalCmde_logique_dml_tor;


   VEMS_vidGET(Cmde_logique_dml_tor, bLocalCmde_logique_dml_tor);
   DIOHAL_vidWrite(CH_DIO_OUT_DML_RELAY, bLocalCmde_logique_dml_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidOutpIdc                                       */
/* !Description :  Etat de la commande de l'actionneur de la sortie           */
/*                 information moteur tournant,  commandé en low side (0 =    */
/*                 fermé, 1 = ouvert).                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Cmde_info_moteur_tournant_tor;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidOutpIdc(void)
{
   /*F02_OutpIdc */
   boolean bLocalInfoMoteurTournantTor;


   VEMS_vidGET(Cmde_info_moteur_tournant_tor, bLocalInfoMoteurTournantTor);
   DIOHAL_vidWrite(CH_DIO_OUT_ENGST_OUTPUT, bLocalInfoMoteurTournantTor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAuthStrtSTT                                   */
/* !Description :  Etat de la commande de l'actionneur suivant que            */
/*                 l'actionneur soit commandé  en low side (piolté à la masse:*/
/*                 0 = fermé, 1 = ouvert) ou en high side (0 = ouvert, 1 =    */
/*                 fermé).                                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Cmde_autorisation_redem_stt_tor;                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAuthStrtSTT(void)
{
   /*F03_AuthStrtSTT*/
   boolean bLocalAutorisationRedemStt_tor;


   VEMS_vidGET(Cmde_autorisation_redem_stt_tor, bLocalAutorisationRedemStt_tor);
   DIOHAL_vidWrite(CH_DIO_OUT_STT, bLocalAutorisationRedemStt_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidBlowBy1                                       */
/* !Description :  State of the actuator control of the Blowby1 heater        */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_rechauff_blowby1_tor;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidBlowBy1(void)
{
   /*F01_BlowBy1*/
   boolean bLocalCmdRechauff_blowby1_tor;


   VEMS_vidGET(Commande_rechauff_blowby1_tor, bLocalCmdRechauff_blowby1_tor);
   DIOHAL_vidWrite(CH_DIO_OUT_BLOW_BY_1, bLocalCmdRechauff_blowby1_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidBlowBy2                                       */
/* !Description :  State of the actuator control of the Blowby2 heater        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_rechauff_blowby2_tor;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidBlowBy2(void)
{
   /*F02_BlowBy2*/
   boolean bLocalCmdRechauff_blowby2_tor;


   VEMS_vidGET(Commande_rechauff_blowby2_tor, bLocalCmdRechauff_blowby2_tor);
   DIOHAL_vidWrite(CH_DIO_OUT_BLOW_BY_2, bLocalCmdRechauff_blowby2_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidSenO2Ds                                       */
/* !Description :  Demande d'activation du chauffage de la sonde aval         */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_chauffage_drvrseno2ds;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidSenO2Ds(void)
{
   /*F01_SenO2Ds*/
   boolean bLocalCmdchauffage_drvrseno2ds;


   VEMS_vidGET(Commande_chauffage_drvrseno2ds, bLocalCmdchauffage_drvrseno2ds);
   DIOHAL_vidWrite(CH_DIO_OUT_SO2_HEAT_DOWN, bLocalCmdchauffage_drvrseno2ds);
}
/*------------------------------- end of file --------------------------------*/