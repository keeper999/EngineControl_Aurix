/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SAIMMO                                                  */
/* !Description     : SAIMMO Component                                        */
/*                                                                            */
/* !Module          : SAIMMO                                                  */
/* !Description     : Structure d'accueil pour le module IMMO                 */
/*                                                                            */
/* !File            : SAIMMO_FCT3.C                                           */
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
/*   1 / Srv_EveRdByDidADC                                                    */
/*   2 / Srv_EveRcWrCodProg                                                   */
/*   3 / Srv_EveRcMatch                                                       */
/*   4 / Srv_EveRcChkCodProg                                                  */
/*   5 / Ext_sendPosAnswImmoReadSt                                            */
/*   6 / Ext_sendPosAnswRCImmo                                                */
/*   7 / Ext_sendNegAnswImmo                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5060905 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SAIMMO/SAIMMO_FCT3.c_v          $*/
/* $Revision::   1.7      $$Author::   etsasson       $$Date::   06 Jun 2013 $*/
/* $Author::   etsasson                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "saimmo_im.h"
#include "saimmo.h"
#include "saimmo_l.h"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRdByDidADC                                          */
/* !Description :  |                                                          */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Immo_ReqReadSt();                                        */
/*  output uint8 Srv_stADCRead;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRdByDidADC(void)
{
   VEMS_vidSET(Srv_stADCRead , READ_ADC_IN_PROGRESS);
   Immo_ReqReadSt();
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRcWrCodProg                                         */
/* !Description :  |                                                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Immo_ReqWrCod(argin uint32 Ext_noImmoCodProgDiag, argin  */
/* uint8 Ext_stCANMatchOptDiag);                                              */
/*  input uint8 DCM_MANU_Option_Appairage;                                    */
/*  input uint32 DCM_MANU_Code_Antidemarrage;                                 */
/*  output uint8 Srv_stADCCodWr;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRcWrCodProg(void)
{
   uint8    u8LocalstCANMatchOptDiag;     /* store temporarily the ADC type   */
   uint32   u32LocalnoImmoCodProgDiag;    /* store temporarily the ADC type   */

   VEMS_vidGET(DCM_MANU_Option_Appairage, u8LocalstCANMatchOptDiag);
   VEMS_vidGET(DCM_MANU_Code_Antidemarrage, u32LocalnoImmoCodProgDiag);


   if (( u8LocalstCANMatchOptDiag == 0x00 ) ||
      ( u8LocalstCANMatchOptDiag == 0x01 ) ||
      ( u8LocalstCANMatchOptDiag == 0x02 ) ||
      ( u8LocalstCANMatchOptDiag == 0x03 ))
   {
      VEMS_vidSET(Srv_stADCCodWr, WRITE_ADC_ACK);
      Immo_ReqWrCod (u32LocalnoImmoCodProgDiag, u8LocalstCANMatchOptDiag);
   }
   else
   {
      VEMS_vidSET(Srv_stADCCodWr, WRITE_ADC_OUT_OF_RANGE);
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRcMatch                                             */
/* !Description :  |                                                          */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Immo_ReqMatch(argin uint8 Ext_stMatchSrvDiag);           */
/*  input uint8 DCM_MANU_Option_Appairage;                                    */
/*  output uint8 Srv_stADCMatch;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRcMatch(void)
{
   /* Lancement appairage */
   if (DCM_MANU_Option_Appairage == 1)
   {
      VEMS_vidSET(Srv_stADCMatch, MATCHING_ADC_ACK);
      Immo_ReqMatch(DCM_MANU_Option_Appairage);
   }
   /* Statut appairage */
   else if (DCM_MANU_Option_Appairage == 3)
   {
      Immo_ReqMatch(DCM_MANU_Option_Appairage);
   }
   else /* Mauvais paramètre */
   {
      VEMS_vidSET(Srv_stADCMatch, MATCHING_ADC_IMPOSSIBLE);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRcChkCodProg                                        */
/* !Description :  |                                                          */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void Immo_ReqCtlCod(argin uint32 Ext_noImmoCodTestDiag);      */
/*  input uint32 DCM_MANU_Code_Antidemarrage;                                 */
/*  output uint8 Srv_stADCCodChk;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRcChkCodProg(void)
{
   uint32   u32LocalnoImmoCodTestDiag;    /* store temporarily the ADC type   */

   VEMS_vidGET(DCM_MANU_Code_Antidemarrage, u32LocalnoImmoCodTestDiag);
   VEMS_vidSET(Srv_stADCCodChk, CHECK_ADC_ACK);
   Immo_ReqCtlCod (u32LocalnoImmoCodTestDiag);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_sendPosAnswImmoReadSt                                  */
/* !Description :  |                                                          */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 SAIMMO_stLockECUReadSt;                                      */
/*  output uint8 SAIMMO_stProgImmoReadSt;                                     */
/*  output uint8 SAIMMO_bfImmoReadStDft;                                      */
/*  output uint8 SAIMMO_stCANMatchOptReadSt;                                  */
/*  output uint8 Srv_stADCRead;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_sendPosAnswImmoReadSt
(
   uint8 Immo_stLockECUReadSt,
   uint8 Immo_stProgImmoReadSt,
   uint8 Immo_bfImmoReadStDft,
   uint8 Immo_stCANMatchOptReadSt
)
{
   VEMS_vidSET(SAIMMO_stLockECUReadSt, Immo_stLockECUReadSt);
   VEMS_vidSET(SAIMMO_stProgImmoReadSt, Immo_stProgImmoReadSt);
   VEMS_vidSET(SAIMMO_bfImmoReadStDft, Immo_bfImmoReadStDft);
   VEMS_vidSET(SAIMMO_stCANMatchOptReadSt, Immo_stCANMatchOptReadSt);
   VEMS_vidSET(Srv_stADCRead, READ_ADC_OK);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_sendPosAnswRCImmo                                      */
/* !Description :  |                                                          */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Srv_stADCMatch;                                              */
/*  output uint8 Srv_noADCMatchOutpPrm;                                       */
/*  output uint8 Srv_stADCCodChk;                                             */
/*  output uint8 Srv_noADCCodChkOutpPrm;                                      */
/*  output uint8 Srv_stADCCodWr;                                              */
/*  output uint8 Srv_noADCCodWrOutpPrm;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_sendPosAnswRCImmo
(
   uint8 Immo_noRC,
   uint8 Immo_stRCSrv1,
   uint8 Immo_stRCSrv2
)
{
   switch (Immo_noRC)
   {
      case 0x01:
         switch (Immo_stRCSrv1)
         {
            case 0x01:
               VEMS_vidSET(Srv_stADCMatch, MATCHING_ADC_IN_PROGRESS);
               break;
            case 0x02:
               VEMS_vidSET(Srv_stADCMatch, MATCHING_ADC_OK);
               break;
            case 0x03:
               VEMS_vidSET(Srv_stADCMatch, MATCHING_ADC_NOK);
               break;
            default:
               ; /* do nothing */
         }
         VEMS_vidSET(Srv_noADCMatchOutpPrm, Immo_stRCSrv2);
      break;

      case 0x02:
         switch (Immo_stRCSrv1)
         {
            case 0x01:
               VEMS_vidSET(Srv_stADCCodChk, CHECK_ADC_IN_PROGRESS);
               break;
            case 0x02:
               VEMS_vidSET(Srv_stADCCodChk, CHECK_ADC_OK);
               break;
            case 0x03:
               VEMS_vidSET(Srv_stADCCodChk, CHECK_ADC_NOK);
               break;
            default:
               ; /* do nothing */
         }
         VEMS_vidSET(Srv_noADCCodChkOutpPrm, Immo_stRCSrv2);
      break;

      case 0x03:
         switch (Immo_stRCSrv1)
         {
            case 0x01:
               VEMS_vidSET(Srv_stADCCodWr, WRITE_ADC_IN_PROGRESS);
               break;
            case 0x02:
               VEMS_vidSET(Srv_stADCCodWr, WRITE_ADC_OK);
               break;
            case 0x03:
               VEMS_vidSET(Srv_stADCCodWr, WRITE_ADC_NOK);
               break;
            default:
               ; /* do nothing */
         }
         VEMS_vidSET(Srv_noADCCodWrOutpPrm, Immo_stRCSrv2);
      break;

      default:
         ; /* do nothing */
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Ext_sendNegAnswImmo                                        */
/* !Description :  interface function called by IMMO. Used to send a negative */
/*                 answer for a UDS request.                                  */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_R_11_08134_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_stADCMatch;                                               */
/*  input uint8 Srv_stADCCodWr;                                               */
/*  output uint8 Srv_stADCRead;                                               */
/*  output uint8 Srv_stADCMatch;                                              */
/*  output uint8 Srv_stADCCodWr;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Ext_sendNegAnswImmo
(
   uint8 Immo_stNegAnswSrv,
   uint8 Immo_noNegAnswCod
)
{
   uint8 u8LocalSrv_stADCMatch;
   uint8 u8LocalSrv_stADCCodWr;

   if (Immo_stNegAnswSrv == 0x22)
   {
      VEMS_vidSET(Srv_stADCRead, READ_ADC_IMPOSSIBLE);
   }
   else
   {
      VEMS_vidGET(Srv_stADCMatch , u8LocalSrv_stADCMatch);
      VEMS_vidGET(Srv_stADCCodWr , u8LocalSrv_stADCCodWr);
      if ((u8LocalSrv_stADCMatch == MATCHING_ADC_ACK)
         || (u8LocalSrv_stADCMatch == MATCHING_ADC_IN_PROGRESS))
      {
         VEMS_vidSET(Srv_stADCMatch, MATCHING_ADC_IMPOSSIBLE);
      }
      if ((u8LocalSrv_stADCCodWr == WRITE_ADC_ACK)
         || (u8LocalSrv_stADCCodWr == WRITE_ADC_IN_PROGRESS))
      {
         VEMS_vidSET(Srv_stADCCodWr, WRITE_ADC_IMPOSSIBLE);
      }
   }
}

/*-------------------------------- end of file -------------------------------*/