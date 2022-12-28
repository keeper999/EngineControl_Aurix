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
/* !File            : ACQCMDDIO_FCT3.C                                        */
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
/*   1 / ACQCMDDIO_vidAcqDioCoFan                                             */
/*   2 / ACQCMDDIO_vidAcqDioCoFanB1                                           */
/*   3 / ACQCMDDIO_vidAcqDioCoFanB2                                           */
/*   4 / ACQCMDDIO_vidAcqDioKey                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_6509298 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ACQCMDDIO/ACQCMDDIO_FCT3.C_v      $*/
/* $Revision::   1.1      $$Author::   achebino       $$Date::   19 Aug 2014 $*/
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
/* !Function    :  ACQCMDDIO_vidAcqDioCoFan                                   */
/* !Description :  L'acquisition de l'information ETAT_GMV brut avant filtrage*/
/*                 anti-rebond est realisée selon le type  d'équipements GMV  */
/*                 sur le véhicule.                                           */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ACQCMDDIO_vidAcqDioCoFanB1();                            */
/*  extf argret void ACQCMDDIO_vidAcqDioCoFanB2();                            */
/*  input st45 Cf_cooling_fan_equipment;                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioCoFan(void)
{
   uint8 u8LocalCfCoolFan;


   VEMS_vidGET(Cf_cooling_fan_equipment, u8LocalCfCoolFan);
   if (u8LocalCfCoolFan == EQUIPMENT_B1)
   {
      ACQCMDDIO_vidAcqDioCoFanB1();
   }
   if (u8LocalCfCoolFan == EQUIPMENT_B2)
   {
      ACQCMDDIO_vidAcqDioCoFanB2();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioCoFanB1                                 */
/* !Description :  Acquisition de l'information ETAT_GMV brut avant filtrage  */
/*                 anti-rebond (B1).                                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_etat_gmvB1_brut;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioCoFanB1(void)
{
   /*F01_vidAcqDioCoFanB1*/
   boolean bLocalAcquisition_gmvB1;


   bLocalAcquisition_gmvB1 = DIOHAL_bRead(CH_DIO_IN_DIAG_GMV);
   VEMS_vidSET(Acquisition_etat_gmvB1_brut, bLocalAcquisition_gmvB1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioCoFanB2                                 */
/* !Description :  Acquisition de l'information ETAT_GMV brut avant filtrage  */
/*                 anti-rebond (B2).                                          */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_etat_gmvB2_brut;                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioCoFanB2(void)
{
   /*F02_vidAcqDioCoFanB2*/
   boolean bLocalAcquisition_gmvB2;


   bLocalAcquisition_gmvB2 = DIOHAL_bRead(CH_DIO_IN_DIAG_GMV);
   VEMS_vidSET(Acquisition_etat_gmvB2_brut, bLocalAcquisition_gmvB2);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ACQCMDDIO_vidAcqDioKey                                     */
/* !Description :  Acquisition de la valeur logique brute de l'entrée clef    */
/*                 provenant du LDB (hystérésis et seuil de changement        */
/*                 d'état).                                                   */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  DIOHAL_bRead(argin uint8 u8Channel);                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Acquisition_cmde_reveil_rcd_tor;                           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ACQCMDDIO_vidAcqDioKey(void)
{
   /*F12_AcqDioKey*/
   boolean bLocalAcqCmdReveilRcdTor;


   bLocalAcqCmdReveilRcdTor = DIOHAL_bRead(CH_DIO_IN_IGNK);
   VEMS_vidSET(Acquisition_cmde_reveil_rcd_tor, bLocalAcqCmdReveilRcdTor);
}
/*------------------------------- end of file --------------------------------*/