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
/* !File            : ACQCMDDIO_FCT2.C                                        */
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
/*   1 / ACQCMDDIO_vidSenO2Us                                                 */
/*   2 / ACQCMDDIO_vidAcqDioClu                                               */
/*   3 / ACQCMDDIO_vidAcqDioOil                                               */
/*   4 / ACQCMDDIO_vidAcqDioGear                                              */
/*   5 / ACQCMDDIO_vidAcqDioBrk                                               */
/*   6 / ACQCMDDIO_vidAcqDioSTT                                               */
/*   7 / ACQCMDDIO_vidInitCoFan                                               */
/*   8 / ACQCMDDIO_vidAcqCmdCoFan                                             */
/*   9 / ACQCMDDIO_vidCmdDioCoFanB1                                           */
/*   10 / ACQCMDDIO_vidCmdDioCoFanB2                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_6509298 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQCMDDIO/ACQCMDDIO_FCT2.C_v      $*/
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
#include "PFCHAL.H"
#include "ACQCMDDIO_toRte.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidSenO2Us                                       */
/* !Description :  Demande d'activation du chauffage de la sonde amont.       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_chauffage_drvrseno2us;                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidSenO2Us(void)
{
   /*F02_SenO2Us*/
   boolean bLocalCmdchauffage_drvrseno2us;


   VEMS_vidGET(Commande_chauffage_drvrseno2us, bLocalCmdchauffage_drvrseno2us);
   DIOHAL_vidWrite(CH_DIO_OUT_SO2_HEAT_UP, bLocalCmdchauffage_drvrseno2us);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioClu                                     */
/* !Description :  Acquisition de l'information pédale embrayage TOR.         */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_pedale_embrayage_tor;                          */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioClu(void)
{
   /*F06_AcqDioClu*/
   boolean bLocalAcqPedale_embrayage_tor;


   bLocalAcqPedale_embrayage_tor = DIOHAL_bRead(CH_DIO_IN_CLU_PDL_ACQ);
   VEMS_vidSET(Acquisition_pedale_embrayage_tor, bLocalAcqPedale_embrayage_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioOil                                     */
/* !Description :  Acquisition manocontact de pression huile                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_pression_huile_tor;                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioOil(void)
{
   /*F07_AcqDioOil*/
   boolean bLocalAcq_pression_huile_tor;


   bLocalAcq_pression_huile_tor = DIOHAL_bRead(CH_DIO_IN_OIL_PRES_ACQ );
   VEMS_vidSET(Acquisition_pression_huile_tor, bLocalAcq_pression_huile_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioGear                                    */
/* !Description :  Acquisition de l'information Start Lock TOR                */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_startlock_tor;                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioGear(void)
{
   /*F08_AcqDioGear*/
   boolean bLocalAcquisition_startlock_tor;


   bLocalAcquisition_startlock_tor = DIOHAL_bRead(CH_DIO_IN_STARTLOCK_ACQ);
   VEMS_vidSET(Acquisition_startlock_tor, bLocalAcquisition_startlock_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioBrk                                     */
/* !Description :  Acquisition de l'information pédale de frein secondaire    */
/*                 TOR.                                                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_pedale_frein_tor;                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioBrk(void)
{
   /*F09_AcqDioBrk*/
   boolean bLocalAcq_pedale_frein_tor;


   bLocalAcq_pedale_frein_tor = DIOHAL_bRead(CH_DIO_IN_BRK_PDL_ACQ);
   VEMS_vidSET(Acquisition_pedale_frein_tor, bLocalAcq_pedale_frein_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioSTT                                     */
/* !Description :  Acquisition de l'information brute de la ligne Key/Push.   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_keypush_tor;                                   */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioSTT(void)
{
   /*F10_AcqDioSTT*/
   boolean bLocalAcquisition_keypush_tor;


   bLocalAcquisition_keypush_tor = DIOHAL_bRead(CH_DIO_IN_KEY_PUSH_INFO_ACQ);
   VEMS_vidSET(Acquisition_keypush_tor, bLocalAcquisition_keypush_tor);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidInitCoFan                                     */
/* !Description :  Sur Reset CMM, il faut configurer le type de l’entré état  */
/*                 GMV. Elle est de type booléen en B1 ou B2, et RCO en C’.   */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void PFCHAL_vidDioEnable(argin uint8 u8Channel);              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidInitCoFan(void)
{
   PFCHAL_vidDioEnable(CH_PFC_GMV_1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqCmdCoFan                                   */
/* !Description :  L'activation du signal de commande du GMV depend du type   */
/*                 d'equipements GMV sur véhicule.                            */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidCmdDioCoFanB1();                            */
/*  extf argret void ACQCMDDIO_vidCmdDioCoFanB2();                            */
/*  extf argret void ACQCMDDIO_vidAcqDioCoFan();                              */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqCmdCoFan(void)
{
   uint8 u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   if (  (u8LocalCfCoolFan == EQUIPMENT_B1)
      || (u8LocalCfCoolFan == EQUIPMENT_B2))
   {
      ACQCMDDIO_vidCmdDioCoFanB1();
   }
   if (  (u8LocalCfCoolFan == EQUIPMENT_B2)
      || (u8LocalCfCoolFan == EQUIPMENT_C))
   {
      ACQCMDDIO_vidCmdDioCoFanB2();
   }
   ACQCMDDIO_vidAcqDioCoFan();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidCmdDioCoFanB1                                 */
/* !Description :  Demande d'activation du signal de commande du GMV 1        */
/*                 (équipements B1 et B2).                                    */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_GMV_B1;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidCmdDioCoFanB1(void)
{
   /*F01_CmdDioCoFanB1*/
   boolean bLocalCommande_GMV_B1;


   VEMS_vidGET(Commande_GMV_B1, bLocalCommande_GMV_B1);
   DIOHAL_vidWrite(CH_DIO_OUT_GMV_1, bLocalCommande_GMV_B1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidCmdDioCoFanB2                                 */
/* !Description :  Demande d'activation du signal de commande du GMV 1        */
/*                 (équipements B2 et C').                                    */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIOHAL_vidWrite(argin uint8 u8Channel, argin boolean     */
/* bVal);                                                                     */
/*  input boolean Commande_GMV_B2;                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidCmdDioCoFanB2(void)
{
   /*F01_CmdDioCoFanB2*/
   boolean bLocalCommande_GMV_B2;


   VEMS_vidGET(Commande_GMV_B2, bLocalCommande_GMV_B2);
   DIOHAL_vidWrite(CH_DIO_OUT_GMV_2, bLocalCommande_GMV_B2);
}
/*------------------------------- end of file --------------------------------*/