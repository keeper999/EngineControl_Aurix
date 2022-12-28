/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VSC                                                     */
/* !Description     : VSC Component                                           */
/*                                                                            */
/* !Module          : VSC                                                     */
/* !Description     : Aftersales memorization management of Vehicle speed     */
/*                    control                                                 */
/*                                                                            */
/* !File            : VSC_FCT1.C                                              */
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
/*   1 / VSC_vidInit                                                          */
/*   2 / VSC_vidInit_Output                                                   */
/*   3 / VSC_vidRecHis1                                                       */
/*   4 / VSC_vidRecHis2                                                       */
/*   5 / VSC_vidRecLstCrsCtlDeacCaus1                                         */
/*   6 / VSC_vidRecLstCrsCtlDeacCaus2                                         */
/*                                                                            */
/* !Reference   : V02 NT 12 04370 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#064189                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "VSC.H"
#include "VSC_L.H"
#include "VSC_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSC_vidInit                                                */
/* !Description :  Variables initialization                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus1[11];                              */
/*  output uint8 VSCtl_stRec_stDeacVSRegReq1Prev;                             */
/*  output uint16 VSCtl_nEng;                                                 */
/*  output uint8 VSCtl_noEgdGearCord;                                         */
/*  output boolean VSCtl_bVSregDeacEngNotAvl;                                 */
/*  output boolean VSCtl_bVSregDeacPtOp;                                      */
/*  output boolean VSCtl_bVSregDeacVehReg;                                    */
/*  output boolean VSCtl_bVSregDeacVhlSpdGap;                                 */
/*  output boolean VSCtl_bVSregDeacAcceNotCoh;                                */
/*  output boolean VSCtl_bVSregDeacAutBrk;                                    */
/*  output boolean VSCtl_bVSregDeacBrkPedPress;                               */
/*  output boolean VSCtl_bVSregDeacDrvCmd;                                    */
/*  output boolean VSCtl_bVSregDeacSecuLvl;                                   */
/*  output boolean VSCtl_bVSregDeacGBxLev;                                    */
/*  output boolean VSCtl_bVSregDeacGear;                                      */
/*  output boolean VSCtl_bVSregDeacGBxGearDft;                                */
/*  output uint8 VSCtl_rAccP;                                                 */
/*  output uint8 VSCtl_spdVehVSRegReq;                                        */
/*  output uint8 VSCtl_spdVehicle;                                            */
/*  output uint32 VSCtl_tiCurVehTmr;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSC_vidInit(void)
{
   uint8  u8LocalDeacCaus_2;
   uint8  u8LocalDeacCaus_3;
   uint8  u8LocalVSCtl_rAccP;
   uint8  u8LocalVSCprmLsCrsCtlDacCaus[11];
   /*QAC Msg(2:3132) : No impact on the function*/
   /*QAC Msg(2:3204) : No impact on the function*/
   uint16 u16LocalVSCtl_nEng;
   uint32 u32LocalVSCtl_tiCurVehTmr;


   VSCtl_stRec_stDeacVSRegReq1Prev = 0;
   /*VSCtl_noEgdGearCord and VSCtl_nEng */
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus1,
                      11,
                      u8LocalVSCprmLsCrsCtlDacCaus);
   u16LocalVSCtl_nEng = (uint16)((u8LocalVSCprmLsCrsCtlDacCaus[0] * 256)
                               + u8LocalVSCprmLsCrsCtlDacCaus[1]);
   u16LocalVSCtl_nEng = (uint16)MATHSRV_udtMIN(u16LocalVSCtl_nEng, 7500);
   VEMS_vidSET(VSCtl_nEng, u16LocalVSCtl_nEng);

   u8LocalDeacCaus_2 = u8LocalVSCprmLsCrsCtlDacCaus[2];
   VEMS_vidSET(VSCtl_noEgdGearCord, (uint8)((u8LocalDeacCaus_2 & 0xE0) >> 5));

   /*VSCtl_bVSregDeacEngNotAvl*/
   if ((u8LocalDeacCaus_2 & 0x10) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacEngNotAvl, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacEngNotAvl, 0);
   }

   /*VSCtl_bVSregDeacPtOp*/
   if ((u8LocalDeacCaus_2 & 0x08) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacPtOp, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacPtOp, 0);
   }

   /*VSCtl_bVSregDeacVehReg*/
   if ((u8LocalDeacCaus_2 & 0x04) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacVehReg, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacVehReg, 0);
   }

   /*VSCtl_bVSregDeacVhlSpdGap*/
   if ((u8LocalDeacCaus_2 & 0x02) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacVhlSpdGap, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacVhlSpdGap, 0);
   }

   u8LocalDeacCaus_3 = u8LocalVSCprmLsCrsCtlDacCaus[3];
   /*VSCtl_bVSregDeacAcceNotCoh*/
   if ((u8LocalDeacCaus_3 & 0x80) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacAcceNotCoh, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacAcceNotCoh, 0);
   }

   /*VSCtl_bVSregDeacAutBrk*/
   if ((u8LocalDeacCaus_3 & 0x40) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacAutBrk, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacAutBrk, 0);
   }

   /*VSCtl_bVSregDeacBrkPedPress*/
   if ((u8LocalDeacCaus_3 & 0x20) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacBrkPedPress, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacBrkPedPress, 0);
   }

   /*VSCtl_bVSregDeacDrvCmd*/;
   if ((u8LocalDeacCaus_3 & 0x10) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacDrvCmd, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacDrvCmd, 0);
   }

   /*VSCtl_bVSregDeacSecuLvl*/
   if ((u8LocalDeacCaus_3 & 0x08) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacSecuLvl, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacSecuLvl, 0);
   }

   /*VSCtl_bVSregDeacGBxLev*/
   if ((u8LocalDeacCaus_3 & 0x04) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacGBxLev, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacGBxLev, 0);
   }

   /*VSCtl_bVSregDeacGear*/
   if ((u8LocalDeacCaus_3 & 0x02) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacGear, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacGear, 0);
   }

   /*VSCtl_bVSregDeacGBxGearDft*/
   if ((u8LocalDeacCaus_3 & 0x01) != 0)
   {
      VEMS_vidSET(VSCtl_bVSregDeacGBxGearDft, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacGBxGearDft, 0);
   }

   u8LocalVSCtl_rAccP =
      (uint8)MATHSRV_udtMIN(u8LocalVSCprmLsCrsCtlDacCaus[4], 100);
   VEMS_vidSET(VSCtl_rAccP, u8LocalVSCtl_rAccP);
   VEMS_vidSET(VSCtl_spdVehVSRegReq, u8LocalVSCprmLsCrsCtlDacCaus[5]);
   VEMS_vidSET(VSCtl_spdVehicle, u8LocalVSCprmLsCrsCtlDacCaus[6]);

   /*VSCtl_tiCurVehTmr*/
   u32LocalVSCtl_tiCurVehTmr =
      ( ((uint32)u8LocalVSCprmLsCrsCtlDacCaus[7] << 24)
      | ((uint32)u8LocalVSCprmLsCrsCtlDacCaus[8] << 16)
      | ((uint32)u8LocalVSCprmLsCrsCtlDacCaus[9] << 8)
      | ((uint32)u8LocalVSCprmLsCrsCtlDacCaus[10]));

   VEMS_vidSET(VSCtl_tiCurVehTmr, u32LocalVSCtl_tiCurVehTmr);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSC_vidInit_Output                                         */
/* !Description :  Variables Initilizition.                                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 VSCtl_stRec_stDeacVSRegReq1Prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSC_vidInit_Output(void)
{
   VSCtl_stRec_stDeacVSRegReq1Prev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSC_vidRecHis1                                             */
/* !Description :  Calculation of the new values for                          */
/*                 VSCtl_prmLstCrsCtlDeacCaus1 when a new memorization is     */
/*                 effective (part1 of the function)                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_12_04370_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 VSCtl_stDeacVSRegReqLo_no1;                                  */
/*  input uint32 VSCtl_stDeacVSRegReqHi_no1;                                  */
/*  output boolean VSCtl_bVSregDeacPtOp;                                      */
/*  output boolean VSCtl_bVSregDeacDrvCmd;                                    */
/*  output boolean VSCtl_bVSregDeacVehReg;                                    */
/*  output boolean VSCtl_bVSregDeacGBxLev;                                    */
/*  output boolean VSCtl_bVSregDeacAcceNotCoh;                                */
/*  output boolean VSCtl_bVSregDeacVhlSpdGap;                                 */
/*  output boolean VSCtl_bVSregDeacEngNotAvl;                                 */
/*  output boolean VSCtl_bVSregDeacSecuLvl;                                   */
/*  output boolean VSCtl_bVSregDeacGBxGearDft;                                */
/*  output boolean VSCtl_bVSregDeacGear;                                      */
/*  output boolean VSCtl_bVSregDeacAutBrk;                                    */
/*  output boolean VSCtl_bVSregDeacBrkPedPress;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSC_vidRecHis1(void)
{
   boolean bLocalDeacVSRegReqHi[24];
   /*QAC Msg(2:3132) : No impact on the function*/
   boolean bLocalDeacVSRegReqLo[24];
   /*QAC Msg(2:3132) : No impact on the function*/
   uint8   u8LocalTableIdx;
   uint32  u32LocalVSCtlstDeacVSRegReqLono1;
   uint32  u32LocalVSCtlstDeacVSRegReqHino1;


   /*Extracting bits from VSCtl_stDeacVSRegReqHi_no1*/
   /*and VSCtl_stDeacVSRegReqLo_no1*/
   VEMS_vidGET(VSCtl_stDeacVSRegReqLo_no1, u32LocalVSCtlstDeacVSRegReqLono1);
   VEMS_vidGET(VSCtl_stDeacVSRegReqHi_no1, u32LocalVSCtlstDeacVSRegReqHino1);
   for (u8LocalTableIdx = 0; u8LocalTableIdx < 24; u8LocalTableIdx++)
   {
      if ( ( (u32LocalVSCtlstDeacVSRegReqLono1 >> u8LocalTableIdx)
           & 0x00000001) != 0)
      {
         bLocalDeacVSRegReqLo[u8LocalTableIdx] = 1;
      }
      else
      {
         bLocalDeacVSRegReqLo[u8LocalTableIdx] = 0;
      }

      if ( ( (u32LocalVSCtlstDeacVSRegReqHino1 >> u8LocalTableIdx)
           & 0x00000001) != 0)
      {
         bLocalDeacVSRegReqHi[u8LocalTableIdx] = 1;
      }
      else
      {
         bLocalDeacVSRegReqHi[u8LocalTableIdx] = 0;
      }
   }
   /*VSCtl_bVSregDeacPtOp*/
   if ((bLocalDeacVSRegReqLo[14] != 0) || (bLocalDeacVSRegReqLo[22] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacPtOp, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacPtOp, 0);
   }
   /*VSCtl_bVSregDeacDrvCmd*/
   if (  (bLocalDeacVSRegReqHi[17] != 0)
      || (bLocalDeacVSRegReqHi[18] != 0)
      || (bLocalDeacVSRegReqHi[20] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacDrvCmd, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacDrvCmd, 0);
   }
   /*VSCtl_bVSregDeacVehReg*/
   if (  (bLocalDeacVSRegReqHi[4] != 0)
      || (bLocalDeacVSRegReqHi[5] != 0)
      || (bLocalDeacVSRegReqHi[6] != 0)
      || (bLocalDeacVSRegReqHi[7] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacVehReg, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacVehReg, 0);
   }
   /*VSCtl_bVSregDeacGBxLev*/
   if ((bLocalDeacVSRegReqLo[13] != 0) || (bLocalDeacVSRegReqLo[17] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacGBxLev, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacGBxLev, 0);
   }
   /*VSCtl_bVSregDeacAcceNotCoh*/
   if (  (bLocalDeacVSRegReqHi[12] != 0)
      || (bLocalDeacVSRegReqHi[13] != 0)
      || (bLocalDeacVSRegReqHi[14] != 0)
      || (bLocalDeacVSRegReqHi[15] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacAcceNotCoh, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacAcceNotCoh, 0);
   }
   /*VSCtl_bVSregDeacVhlSpdGap*/
   if ((bLocalDeacVSRegReqHi[9] != 0) || (bLocalDeacVSRegReqHi[10] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacVhlSpdGap, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacVhlSpdGap, 0);
   }
   /*VSCtl_bVSregDeacEngNotAvl*/
   if (  (bLocalDeacVSRegReqLo[12] != 0)
      || (bLocalDeacVSRegReqLo[15] != 0)
      || (bLocalDeacVSRegReqLo[16] != 0)
      || (bLocalDeacVSRegReqLo[18] != 0)
      || (bLocalDeacVSRegReqLo[19] != 0)
      || (bLocalDeacVSRegReqLo[20] != 0)
      || (bLocalDeacVSRegReqLo[21] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacEngNotAvl, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacEngNotAvl, 0);
   }
   /*VSCtl_bVSregDeacSecuLvl*/
   if (  (bLocalDeacVSRegReqLo[2] != 0)
      || (bLocalDeacVSRegReqLo[3] != 0)
      || (bLocalDeacVSRegReqLo[0] != 0)
      || (bLocalDeacVSRegReqLo[4] != 0)
      || (bLocalDeacVSRegReqLo[10] != 0)
      || (bLocalDeacVSRegReqLo[9] != 0)
      || (bLocalDeacVSRegReqHi[19] != 0)
      || (bLocalDeacVSRegReqLo[8] != 0)
      || (bLocalDeacVSRegReqLo[11] != 0))
   {
      VEMS_vidSET(VSCtl_bVSregDeacSecuLvl, 1);
   }
   else
   {
      VEMS_vidSET(VSCtl_bVSregDeacSecuLvl, 0);
   }

   /*VSCtl_bVSregDeacGBxGearDft*/
   VEMS_vidSET(VSCtl_bVSregDeacGBxGearDft, bLocalDeacVSRegReqLo[1]);
   /*VSCtl_bVSregDeacGear*/
   VEMS_vidSET(VSCtl_bVSregDeacGear, bLocalDeacVSRegReqLo[23]);
   /*VSCtl_bVSregDeacAutBrk*/
   VEMS_vidSET(VSCtl_bVSregDeacAutBrk, bLocalDeacVSRegReqHi[2]);
   /*VSCtl_bVSregDeacBrkPedPress*/
   VEMS_vidSET(VSCtl_bVSregDeacBrkPedPress, bLocalDeacVSRegReqHi[0]);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSC_vidRecHis2                                             */
/* !Description :  Calculation of the new values for                          */
/*                 VSCtl_prmLstCrsCtlDeacCaus1 when a new memorization is     */
/*                 effective (part2 of the function)                          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_12_04370_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint8 Ext_spdVehVSRegReq;                                           */
/*  output uint32 VSCtl_tiCurVehTmr;                                          */
/*  output uint8 VSCtl_spdVehicle;                                            */
/*  output uint8 VSCtl_rAccP;                                                 */
/*  output uint16 VSCtl_nEng;                                                 */
/*  output uint8 VSCtl_noEgdGearCord;                                         */
/*  output uint8 VSCtl_spdVehVSRegReq;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSC_vidRecHis2(void)
{
   uint8   u8LocalVSCtl_spdVehicle;
   uint8   u8LocalVSCtl_rAccP;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalExt_spdVehVSRegReq;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalAccP_rAccP;
   uint16  u16LocalExt_nEng;
   uint32  u32LocalExt_tiCurVehTmr;


   /*VSCtl_tiCurVehTmr*/
   VEMS_vidGET(Ext_tiCurVehTmr,u32LocalExt_tiCurVehTmr);
   u32LocalExt_tiCurVehTmr = u32LocalExt_tiCurVehTmr / 10;
   VEMS_vidSET(VSCtl_tiCurVehTmr,u32LocalExt_tiCurVehTmr);

   /*VSCtl_spdVehicle*/
   VEMS_vidGET(Veh_spdVeh,u16LocalVeh_spdVeh);
   u16LocalVeh_spdVeh = (uint16)((u16LocalVeh_spdVeh + 64) / 128);
   u8LocalVSCtl_spdVehicle = (uint8)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 255);
   VEMS_vidSET(VSCtl_spdVehicle,u8LocalVSCtl_spdVehicle);

   /*VSCtl_rAccP*/
   VEMS_vidGET(AccP_rAccP,u16LocalAccP_rAccP);
   u16LocalAccP_rAccP = (uint16)((u16LocalAccP_rAccP + 64) / 128);
   u8LocalVSCtl_rAccP = (uint8)MATHSRV_udtMIN(u16LocalAccP_rAccP, 100);
   VEMS_vidSET(VSCtl_rAccP,u8LocalVSCtl_rAccP);

   /*VSCtl_nEng*/
   VEMS_vidGET(Ext_nEng,u16LocalExt_nEng);
   u16LocalExt_nEng = (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 7500);
   VEMS_vidSET(VSCtl_nEng,u16LocalExt_nEng);

   /*VSCtl_noEgdGearCord*/
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   u8LocalCoPt_noEgdGearCord =
      (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 7);
   VEMS_vidSET(VSCtl_noEgdGearCord,u8LocalCoPt_noEgdGearCord);

   /*VSCtl_spdVehVSRegReq*/
   VEMS_vidGET(Ext_spdVehVSRegReq, u8LocalExt_spdVehVSRegReq);
   VEMS_vidSET(VSCtl_spdVehVSRegReq,u8LocalExt_spdVehVSRegReq);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSC_vidRecLstCrsCtlDeacCaus1                               */
/* !Description :  When a new memorization is effective, all the previous one */
/*                 are shifted and VSCtl_prmLstCrsCtlDeacCaus1 is updated     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_12_04370_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus9[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus8[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus7[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus6[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus5[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus4[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus3[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus2[11];                              */
/*  input uint8 VSCtl_prmLstCrsCtlDeacCaus1[11];                              */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus10[11];                            */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus9[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus8[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus7[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus6[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus5[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus4[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus3[11];                             */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus2[11];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSC_vidRecLstCrsCtlDeacCaus1(void)
{
   uint8   u8LocalVSCtlprmDeacCaus[11];
   /*QAC Msg(2:3132) : No impact on the function*/

   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus9,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus10,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus8,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus9,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus7,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus8,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus6,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus7,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus5,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus6,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus4,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus5,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus3,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus4,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus2,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus3,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidGET1DArray(VSCtl_prmLstCrsCtlDeacCaus1,
                      11,
                      u8LocalVSCtlprmDeacCaus);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus2,
                      11,
                      u8LocalVSCtlprmDeacCaus);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VSC_vidRecLstCrsCtlDeacCaus2                               */
/* !Description :  When a new memorization is effective, all the previous one */
/*                 are shifted and VSCtl_prmLstCrsCtlDeacCaus1 is updated     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_12_04370_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint16 VSCtl_nEng;                                                  */
/*  input uint8 VSCtl_noEgdGearCord;                                          */
/*  input boolean VSCtl_bVSregDeacEngNotAvl;                                  */
/*  input boolean VSCtl_bVSregDeacPtOp;                                       */
/*  input boolean VSCtl_bVSregDeacVehReg;                                     */
/*  input boolean VSCtl_bVSregDeacVhlSpdGap;                                  */
/*  input boolean VSCtl_bVSregDeacAcceNotCoh;                                 */
/*  input boolean VSCtl_bVSregDeacAutBrk;                                     */
/*  input boolean VSCtl_bVSregDeacBrkPedPress;                                */
/*  input boolean VSCtl_bVSregDeacDrvCmd;                                     */
/*  input boolean VSCtl_bVSregDeacSecuLvl;                                    */
/*  input boolean VSCtl_bVSregDeacGBxLev;                                     */
/*  input boolean VSCtl_bVSregDeacGear;                                       */
/*  input boolean VSCtl_bVSregDeacGBxGearDft;                                 */
/*  input uint8 VSCtl_rAccP;                                                  */
/*  input uint8 VSCtl_spdVehVSRegReq;                                         */
/*  input uint8 VSCtl_spdVehicle;                                             */
/*  input uint32 VSCtl_tiCurVehTmr;                                           */
/*  output uint8 VSCtl_prmLstCrsCtlDeacCaus1[11];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VSC_vidRecLstCrsCtlDeacCaus2(void)
{
   boolean bLocalVSCtl_bVSregDeacEngNotAvl;
   boolean bLocalVSCtl_bVSregDeacPtOp;
   boolean bLocalVSCtl_bVSregDeacVehReg;
   boolean bLocalVSCtl_bVSregDeacVhlSpdGap;
   boolean bLocalVSCtl_bVSregDeacAcceNotCoh;
   boolean bLocalVSCtl_bVSregDeacAutBrk;
   boolean bLocalVSCtlbVSregDeacBrkPedPress;
   boolean bLocalVSCtl_bVSregDeacDrvCmd;
   boolean bLocalVSCtl_bVSregDeacSecuLvl;
   boolean bLocalVSCtl_bVSregDeacGBxLev;
   boolean bLocalVSCtl_bVSregDeacGear;
   boolean bLocalVSCtl_bVSregDeacGBxGearDft;
   uint8   u8LocalVSCtlprmLstCrsCtlDeacCaus[11];
   /*QAC Msg(2:3132) : No impact on the function*/
   uint8   u8LocalVSCtl_noEgdGearCord;
   uint8   u8LocalVSCtl_rAccP;
   uint8   u8LocalVSCtl_spdVehVSRegReq;
   uint8   u8LocalVSCtl_spdVehicle;
   uint16  u16LocalVSCtl_nEng;
   uint32  u32LocalVSCtl_tiCurVehTmr;


   /*first and second bytes*/
   VEMS_vidGET(VSCtl_nEng, u16LocalVSCtl_nEng);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [0] =
      (uint8)((u16LocalVSCtl_nEng & 0xFF00) >> 8);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [1] = (uint8)(u16LocalVSCtl_nEng & 0x00FF);

   /*third byte*/
   VEMS_vidGET(VSCtl_noEgdGearCord, u8LocalVSCtl_noEgdGearCord);
   VEMS_vidGET(VSCtl_bVSregDeacEngNotAvl, bLocalVSCtl_bVSregDeacEngNotAvl);
   VEMS_vidGET(VSCtl_bVSregDeacPtOp, bLocalVSCtl_bVSregDeacPtOp);
   VEMS_vidGET(VSCtl_bVSregDeacVehReg, bLocalVSCtl_bVSregDeacVehReg);
   VEMS_vidGET(VSCtl_bVSregDeacVhlSpdGap, bLocalVSCtl_bVSregDeacVhlSpdGap);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [2]  = 0x00;
   u8LocalVSCtlprmLstCrsCtlDeacCaus [2] |=
      (uint8)((u8LocalVSCtl_noEgdGearCord & 0x07) << 5);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [2] |=
      (uint8)((bLocalVSCtl_bVSregDeacEngNotAvl & 0x01) << 4);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [2] |=
      (uint8)((bLocalVSCtl_bVSregDeacPtOp & 0x01) << 3);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [2] |=
      (uint8)((bLocalVSCtl_bVSregDeacVehReg & 0x01) << 2);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [2] |=
      (uint8)((bLocalVSCtl_bVSregDeacVhlSpdGap & 0x01) << 1);

   /*Forth byte*/
   VEMS_vidGET(VSCtl_bVSregDeacAcceNotCoh, bLocalVSCtl_bVSregDeacAcceNotCoh);
   VEMS_vidGET(VSCtl_bVSregDeacAutBrk, bLocalVSCtl_bVSregDeacAutBrk);
   VEMS_vidGET(VSCtl_bVSregDeacBrkPedPress, bLocalVSCtlbVSregDeacBrkPedPress);
   VEMS_vidGET(VSCtl_bVSregDeacDrvCmd, bLocalVSCtl_bVSregDeacDrvCmd);
   VEMS_vidGET(VSCtl_bVSregDeacSecuLvl, bLocalVSCtl_bVSregDeacSecuLvl);
   VEMS_vidGET(VSCtl_bVSregDeacGBxLev, bLocalVSCtl_bVSregDeacGBxLev);
   VEMS_vidGET(VSCtl_bVSregDeacGear, bLocalVSCtl_bVSregDeacGear);
   VEMS_vidGET(VSCtl_bVSregDeacGBxGearDft, bLocalVSCtl_bVSregDeacGBxGearDft);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] = 0x00;
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtl_bVSregDeacAcceNotCoh & 0x01) << 7);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtl_bVSregDeacAutBrk & 0x01) << 6);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtlbVSregDeacBrkPedPress & 0x01) << 5);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtl_bVSregDeacDrvCmd & 0x01) << 4);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtl_bVSregDeacSecuLvl & 0x01) << 3);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtl_bVSregDeacGBxLev & 0x01) << 2);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)((bLocalVSCtl_bVSregDeacGear & 0x01) << 1);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [3] |=
      (uint8)(bLocalVSCtl_bVSregDeacGBxGearDft & 0x01);

   /*fifth Byte*/
   VEMS_vidGET(VSCtl_rAccP, u8LocalVSCtl_rAccP);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [4] = u8LocalVSCtl_rAccP;
   /*sixth Byte*/
   VEMS_vidGET(VSCtl_spdVehVSRegReq, u8LocalVSCtl_spdVehVSRegReq);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [5] = u8LocalVSCtl_spdVehVSRegReq;
   /*seventh Byte*/
   VEMS_vidGET(VSCtl_spdVehicle, u8LocalVSCtl_spdVehicle);
   u8LocalVSCtlprmLstCrsCtlDeacCaus [6] = u8LocalVSCtl_spdVehicle;
   /*8th, 9th, 10th and 11th Bytes*/
   VEMS_vidGET(VSCtl_tiCurVehTmr, u32LocalVSCtl_tiCurVehTmr);
   u8LocalVSCtlprmLstCrsCtlDeacCaus[10] =
      (uint8)(u32LocalVSCtl_tiCurVehTmr & 0x000000FF);
   u8LocalVSCtlprmLstCrsCtlDeacCaus[9] =
      (uint8)((u32LocalVSCtl_tiCurVehTmr & 0x0000FF00) >> 8);
   u8LocalVSCtlprmLstCrsCtlDeacCaus[8] =
      (uint8)((u32LocalVSCtl_tiCurVehTmr & 0x00FF0000) >> 16);
   u8LocalVSCtlprmLstCrsCtlDeacCaus[7] =
      (uint8)((u32LocalVSCtl_tiCurVehTmr & 0xFF000000UL) >> 24);
   VEMS_vidSET1DArray(VSCtl_prmLstCrsCtlDeacCaus1,
                      11,
                      u8LocalVSCtlprmLstCrsCtlDeacCaus);
}
/*------------------------------- end of file --------------------------------*/