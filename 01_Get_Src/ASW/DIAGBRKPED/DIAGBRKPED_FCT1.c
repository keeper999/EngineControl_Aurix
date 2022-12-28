/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DIAGBRKPED                                              */
/* !Description     : DIAGBRKPED component                                    */
/*                                                                            */
/* !Module          : DIAGBRKPED                                              */
/* !Description     : ACQUISITION DE LA PEDALE DE FREIN                       */
/*                                                                            */
/* !File            : DIAGBRKPED_FCT1.C                                       */
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
/*   1 / DIAGBRKPED_vidInitOutput                                             */
/*   2 / DIAGBRKPED_vidIni                                                    */
/*   3 / DIAGBRKPED_vidLogicAcqui                                             */
/*   4 / DIAGBRKPED_vidFilterAcqui                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_6526884 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/BRK/DIAGBRKPED/DIAGBRKPED_FCT1.C_v$*/
/* $Revision::   1.10                                                        $*/
/* $Author::   wbouach                                $$Date::   14 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DIAGBRKPED.h"
#include "MATHSRV.h"
#include "DIAGBRKPED_l.h"
#include "DIAGBRKPED_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPED_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 DIAGBRKPED_u8AntiBounceCounter;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPED_vidInitOutput(void)
{
   DIAGBRKPED_u8AntiBounceCounter = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPED_vidIni                                          */
/* !Description :  Initialisation du signal frein secondaire                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_04207_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_bSecBrkPedPrssRaw;                                     */
/*  output boolean Ext_bSecBrkPedPrssFilt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPED_vidIni(void)
{
   VEMS_vidSET(Ext_bSecBrkPedPrssRaw, 0);
   VEMS_vidSET(Ext_bSecBrkPedPrssFilt, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPED_vidLogicAcqui                                   */
/* !Description :  Acquisition de l'information concernant la pédale de frein */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_04207_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void DIAGBRKPED_vidFilterAcqui();                             */
/*  input boolean Cf_bSecBrkPedPrss;                                          */
/*  input boolean DIAGCAN_bIntegratioElectronique;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPED_vidLogicAcqui(void)
{
   boolean bLocalCf_bSecBrkPedPrss;
   boolean bLocalDIAGCAN_bIntegrElec;


   VEMS_vidGET(Cf_bSecBrkPedPrss, bLocalCf_bSecBrkPedPrss);
   VEMS_vidGET(DIAGCAN_bIntegratioElectronique, bLocalDIAGCAN_bIntegrElec);

   if (  (bLocalCf_bSecBrkPedPrss != 0)
      && (bLocalDIAGCAN_bIntegrElec == 0))
   {
      DIAGBRKPED_vidFilterAcqui();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DIAGBRKPED_vidFilterAcqui                                  */
/* !Description :  L’information frein secondaire doit être filtrée à l'aide  */
/*                 d'un filtre anti rebond afin d'éviter battement hautes     */
/*                 fréquences                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_R_08_04207_004.01                                     */
/*                 VEMS_R_08_04207_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Acquisition_pedale_frein_tor;                               */
/*  input boolean Bps_brake_inv_sensor;                                       */
/*  input boolean Bps_brake_pedal_inv_input;                                  */
/*  input boolean Ext_bSecBrkPedPrssRaw;                                      */
/*  input boolean Ext_bSecBrkPedPrssFilt;                                     */
/*  input uint8 High_brake_thresh;                                            */
/*  input uint8 Low_brake_thresh;                                             */
/*  input uint8 DIAGBRKPED_u8AntiBounceCounter;                               */
/*  output boolean Bps_brake_pedal_inv_input;                                 */
/*  output boolean Ext_bSecBrkPedPrssRaw;                                     */
/*  output uint8 DIAGBRKPED_u8AntiBounceCounter;                              */
/*  output boolean Ext_bSecBrkPedPrssFilt;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DIAGBRKPED_vidFilterAcqui(void)
{
   boolean bLocalExt_bSecBrkPedPrssRaw;
   boolean bLocalExt_bSecBrkPedPrssFilt;
   boolean bLocalAcquis_pedale_frein_tor;
   uint8   u8LocalThd;
   uint16  u16LocalCnt;


   VEMS_vidGET(Acquisition_pedale_frein_tor, bLocalAcquis_pedale_frein_tor);

   if (bLocalAcquis_pedale_frein_tor != 0)
   {
      Bps_brake_pedal_inv_input = 1;
   }
   else
   {
      Bps_brake_pedal_inv_input = 0;
   }

   if (Bps_brake_inv_sensor != 0)
   {
      if (Bps_brake_pedal_inv_input != 0)
      {
         VEMS_vidSET(Ext_bSecBrkPedPrssRaw, 0);
      }
      else
      {
         VEMS_vidSET(Ext_bSecBrkPedPrssRaw, 1);
      }
   }
   else
   {
      if (Bps_brake_pedal_inv_input != 0)
      {
         VEMS_vidSET(Ext_bSecBrkPedPrssRaw, 1);
      }
      else
      {
         VEMS_vidSET(Ext_bSecBrkPedPrssRaw, 0);
      }
   }

   VEMS_vidGET(Ext_bSecBrkPedPrssRaw, bLocalExt_bSecBrkPedPrssRaw);
   VEMS_vidGET(Ext_bSecBrkPedPrssFilt, bLocalExt_bSecBrkPedPrssFilt);
   if (bLocalExt_bSecBrkPedPrssRaw != bLocalExt_bSecBrkPedPrssFilt)
   {
      if (bLocalExt_bSecBrkPedPrssRaw != 0)
      {
         u8LocalThd = High_brake_thresh;
      }
      else
      {
         u8LocalThd = Low_brake_thresh;
      }

      u16LocalCnt = (uint16)(DIAGBRKPED_u8AntiBounceCounter + 1);
      DIAGBRKPED_u8AntiBounceCounter = (uint8)MATHSRV_udtMIN(u16LocalCnt, 255);

      if (DIAGBRKPED_u8AntiBounceCounter > u8LocalThd)
      {
         if (bLocalExt_bSecBrkPedPrssRaw != 0)
         {
            VEMS_vidSET(Ext_bSecBrkPedPrssFilt, 1);
         }
         else
         {
            VEMS_vidSET(Ext_bSecBrkPedPrssFilt, 0);
         }
         DIAGBRKPED_u8AntiBounceCounter = 0;
      }
   }
   else
   {
      DIAGBRKPED_u8AntiBounceCounter = 0;
   }
}
/*------------------------------- end of file --------------------------------*/