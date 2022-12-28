/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OBDSRV                                                  */
/* !Description     : OBDSRV Component                                        */
/*                                                                            */
/* !Module          : OBDSRV                                                  */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : OBDSRV_MODE9Auto_API1.c                                 */
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
/*   1 / OBDMODE9_Inftyp_08                                                   */
/*   2 / OBDMODE9_Inftyp_02                                                   */
/*                                                                            */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/OBDSRV_MODE9Auto_API1.c_v   $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/* $Author::   croche2                                $$Date::   11 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "OBDSRV.h"
#include "OBDSRV_L.h"
#include "OBDSRV_im.h"
#include "VEMS.h"
#include "RTE.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE9_Inftyp_08                                         */
/* !Description :  Is called from Dcm when OBD service ReadData PID is called */
/* !Number      :  MODE9Auto_API1.2                                           */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint16 Iupr_gen_denom_count_eep;                                    */
/*  input uint16 IUPR_ctObdStrt;                                              */
/*  input uint16 IUPR_ctNumGrpRat[12];                                        */
/*  input uint16 IUPR_ctDenGrpRat[12];                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE9_Inftyp_08
(
   uint8* Data
)
{
   uint16   u16LocalValueCopy;

   /* Lecture des groupes de ratios d’efficacité diagnostic */
  
   /* Dénominateur général */
   VEMS_vidGET(Iupr_gen_denom_count_eep,u16LocalValueCopy);
   Data[0] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[1] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* Dénominateur général */
   VEMS_vidGET(IUPR_ctObdStrt,u16LocalValueCopy);
   Data[2] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[3] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* Catalyst Monitor completion and Condition bank 1 */
   VEMS_vidGET1DArrayElement(IUPR_ctNumGrpRat,(uint32)CAT1_ASW,
                                                            u16LocalValueCopy);
   Data[4] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[5] = (uint8)((u16LocalValueCopy & 0x00FF));
   VEMS_vidGET1DArrayElement(IUPR_ctDenGrpRat,(uint32)CAT1_ASW,
                                                            u16LocalValueCopy);
   Data[6] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[7] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* Catalyst Monitor completion and Condition bank 2 */
   Data[8] = 0x00;
   Data[9] = 0x00;
   Data[10] = 0x00;
   Data[11] = 0x00;

   /* O2 Sensor Monitor Completion and Condition bank 1 */
   VEMS_vidGET1DArrayElement(IUPR_ctNumGrpRat,(uint32)O2S1,
                                                            u16LocalValueCopy);
   Data[12] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[13] = (uint8)((u16LocalValueCopy & 0x00FF));
   VEMS_vidGET1DArrayElement(IUPR_ctDenGrpRat,(uint32)O2S1,
                                                            u16LocalValueCopy);
   Data[14] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[15] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* O2 Sensor Monitor Completion and Condition bank 2 */
   Data[16] = 0x00;
   Data[17] = 0x00;
   Data[18] = 0x00;
   Data[19] = 0x00;

   /* EGR / VVT Monitor Completion and Condition */
   VEMS_vidGET1DArrayElement(IUPR_ctNumGrpRat,(uint32)VVT,
                                                            u16LocalValueCopy);
   Data[20] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[21] = (uint8)((u16LocalValueCopy & 0x00FF));
   VEMS_vidGET1DArrayElement(IUPR_ctDenGrpRat,(uint32)VVT,
                                                            u16LocalValueCopy);
   Data[22] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[23] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* AIR Monitor Completion and Condition (Secondary Air) */
   VEMS_vidGET1DArrayElement(IUPR_ctNumGrpRat,(uint32)BP_DCM,
                                                            u16LocalValueCopy);
   Data[24] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[25] = (uint8)((u16LocalValueCopy & 0x00FF));
   VEMS_vidGET1DArrayElement(IUPR_ctDenGrpRat,(uint32)BP_DCM,
                                                            u16LocalValueCopy);
   Data[26] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[27] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* EVAP Monitor Completion and Condition */
   VEMS_vidGET1DArrayElement(IUPR_ctNumGrpRat,(uint32)EVAP_DCM,
                                                            u16LocalValueCopy);
   Data[28] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[29] = (uint8)((u16LocalValueCopy & 0x00FF));
   VEMS_vidGET1DArrayElement(IUPR_ctDenGrpRat,(uint32)EVAP_DCM,
                                                            u16LocalValueCopy);
   Data[30] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[31] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* Secondary O2 Sensor Monitor Completion Counts Bank 1 */
   VEMS_vidGET1DArrayElement(IUPR_ctNumGrpRat,(uint32)SO2S1,
                                                            u16LocalValueCopy);
   Data[32] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[33] = (uint8)((u16LocalValueCopy & 0x00FF));
   VEMS_vidGET1DArrayElement(IUPR_ctDenGrpRat,(uint32)SO2S1,
                                                            u16LocalValueCopy);
   Data[34] = (uint8)((u16LocalValueCopy & 0xFF00) >> 8);
   Data[35] = (uint8)((u16LocalValueCopy & 0x00FF));

   /* Secondary O2 Sensor Monitor Completion Counts Bank 2 */
   Data[36] = 0x00;
   Data[37] = 0x00;
   Data[38] = 0x00;
   Data[39] = 0x00;

   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OBDMODE9_Inftyp_02                                         */
/* !Description :  Function called upon reception of request mode 09 infotype */
/*                 $02                                                        */
/* !Number      :  Mode09Auto_API1.2                                          */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_06099_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ISCAN_u8N8F4D2PM1472;                                         */
/*  input uint8 ISCAN_u8N8F4D2PM1473;                                         */
/*  input uint8 ISCAN_u8N8F4D2PM1474;                                         */
/*  input uint8 ISCAN_u8N8F492PM1475;                                         */
/*  input uint8 ISCAN_u8N8F492PM1476;                                         */
/*  input uint8 ISCAN_u8N8F492PM1477;                                         */
/*  input uint8 ISCAN_u8N8F492PM1478;                                         */
/*  input uint8 ISCAN_u8N8F492PM1479;                                         */
/*  input uint8 ISCAN_u8N8F492PM1480;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1481;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1482;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1483;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1484;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1485;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1486;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1487;                                         */
/*  input uint8 ISCAN_u8N8F4B2PM1488;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType OBDMODE9_Inftyp_02
(
   uint8* Data
)
{
   uint8 u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4D2PM1472,u8LocalValueCopy);
   Data[0] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4D2PM1473,u8LocalValueCopy);
   Data[1] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4D2PM1474,u8LocalValueCopy);
   Data[2] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F492PM1475,u8LocalValueCopy);
   Data[3] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F492PM1476,u8LocalValueCopy);
   Data[4] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F492PM1477,u8LocalValueCopy);
   Data[5] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F492PM1478,u8LocalValueCopy);
   Data[6] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F492PM1479,u8LocalValueCopy);
   Data[7] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F492PM1480,u8LocalValueCopy);
   Data[8] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1481,u8LocalValueCopy);
   Data[9] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1482,u8LocalValueCopy);
   Data[10] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1483,u8LocalValueCopy);
   Data[11] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1484,u8LocalValueCopy);
   Data[12] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1485,u8LocalValueCopy);
   Data[13] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1486,u8LocalValueCopy);
   Data[14] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1487,u8LocalValueCopy);
   Data[15] = u8LocalValueCopy;

   VEMS_vidGET(ISCAN_u8N8F4B2PM1488,u8LocalValueCopy);
   Data[16] = u8LocalValueCopy;

   return E_OK;
}