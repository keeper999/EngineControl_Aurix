/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGVOLTADJ                                               */
/* !Description     : IGVOLTADJ component.                                    */
/*                                                                            */
/* !Module          : IGVOLTADJ                                               */
/* !Description     : VOLTAGE BOOST REQUEST FOR IGNITION SYSTEM               */
/*                                                                            */
/* !File            : IGVOLTADJ_FCT1.C                                        */
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
/*   1 / IGVOLTADJ_vidInitOutput                                              */
/*   2 / IGVOLTADJ_vidIgVoltAdj                                               */
/*   3 / IGVOLTADJ_vidVoltAdjZone                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_6444206 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068440                                         */
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

#include "STD_TYPES.h"
#include "IGVOLTADJ.h"
#include "IGVOLTADJ_L.h"
#include "IGVOLTADJ_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGVOLTADJ_vidInitOutput                                    */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HBCH                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean IgVoltAdj_bVoltAdj;                                        */
/*  output boolean IGVOLTADJ_bOutputHysteresis;                               */
/*  output boolean IGVOLTADJ_bResultComp_prev;                                */
/*  output uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1;                           */
/*  output uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2;                           */
/*  output boolean IGVOLTADJ_bVltAdjZnFlipFlopOut;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGVOLTADJ_vidInitOutput(void)
{
   VEMS_vidSET(IgVoltAdj_bVoltAdj, 0);
   IGVOLTADJ_bOutputHysteresis = 0;
   IGVOLTADJ_bResultComp_prev = 0;
   IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1 = 0;
   IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2 = 0;
   IGVOLTADJ_bVltAdjZnFlipFlopOut = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGVOLTADJ_vidIgVoltAdj                                     */
/* !Description :  Two conditions are considered in this specification to     */
/*                 generate a boost request:  when the ignition energy ratio  */
/*                 is lower than the threshold value and the Boolean          */
/*                 IgVoltAdj_bVoltAdj turns to true under some high-load      */
/*                 operating points                                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  PTS_R_6444206_003.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IGVOLTADJ_vidVoltAdjZone();                              */
/*  input uint8 Icd_ratio_energy;                                             */
/*  input st24 Icd_state;                                                     */
/*  input uint8 IgVoltAdj_rIcdBstReqLoThd_C;                                  */
/*  input uint8 IgVoltAdj_rIcdBstReqHiThd_C;                                  */
/*  input boolean IGVOLTADJ_bOutputHysteresis;                                */
/*  output boolean IgVoltAdj_bVoltAdjReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGVOLTADJ_vidIgVoltAdj(void)
{
   uint8 u8LocalIcd_ratio_energy;
   uint8 u8LocalIcd_state;


   VEMS_vidGET(Icd_ratio_energy,u8LocalIcd_ratio_energy);
   VEMS_vidGET(Icd_state,u8LocalIcd_state);

   MATHSRV_vidSchmittTriggerU16((uint16)u8LocalIcd_ratio_energy,
                                (uint16)IgVoltAdj_rIcdBstReqLoThd_C,
                                (uint16)IgVoltAdj_rIcdBstReqHiThd_C,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &IGVOLTADJ_bOutputHysteresis);

   if (  (u8LocalIcd_state == IGNHAL_udtMODE_ADAP)
      && (IGVOLTADJ_bOutputHysteresis != 0))
   {
      IgVoltAdj_bVoltAdjReq = 1;
   }
   else
   {
      IgVoltAdj_bVoltAdjReq = 0;
   }
   IGVOLTADJ_vidVoltAdjZone();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGVOLTADJ_vidVoltAdjZone                                   */
/* !Description :  A RS-FlipFlop is implemented in this block to define the   */
/*                 operating zone requiring a boost request for ignition      */
/*                 system.  The flag IgVoltAdjReq_bVoltAdj indicates the entry*/
/*                 of high load area followed by a temporisation of           */
/*                 IgVoltAdj_tiActDly_C seconds.                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HBCH                                                       */
/* !Trace_To    :  PTS_R_6444206_004.01                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint32 Ext_dstVehMes;                                               */
/*  input uint16 IgVoltAdj_nEng_bVoltAdjX_A[9];                               */
/*  input uint16 IgVoltAdj_rAir_bVoltAdjY_A[8];                               */
/*  input boolean IgVoltAdj_bVoltAdj_M[9][8];                                 */
/*  input uint32 IgVoltAdj_dstVehMinVoltAdj_C;                                */
/*  input boolean IgVoltAdj_bVoltAdjOpp;                                      */
/*  input boolean IGVOLTADJ_bResultComp_prev;                                 */
/*  input uint16 IgVoltAdj_tiActDly_C;                                        */
/*  input uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1;                            */
/*  input uint16 IgVoltAdj_tiDeacDly_C;                                       */
/*  input uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2;                            */
/*  input boolean IGVOLTADJ_bOutputTrndly;                                    */
/*  input boolean IgVoltAdjReq_bVoltAdj;                                      */
/*  input boolean IgVoltAdj_bVoltAdjReq;                                      */
/*  input boolean IGVOLTADJ_bVltAdjZnFlipFlopOut;                             */
/*  input boolean IgVoltAdj_bActVoltAdj_C;                                    */
/*  output boolean IgVoltAdj_bVoltAdjOpp;                                     */
/*  output uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1;                           */
/*  output boolean IgVoltAdjReq_bVoltAdj;                                     */
/*  output boolean IGVOLTADJ_bOutputTrndly;                                   */
/*  output uint16 IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2;                           */
/*  output boolean IGVOLTADJ_bResultComp_prev;                                */
/*  output boolean IGVOLTADJ_bVltAdjZnFlipFlopOut;                            */
/*  output boolean IgVoltAdj_bVoltAdj;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGVOLTADJ_vidVoltAdjZone(void)
{
   boolean bLocalResultComp;
   boolean bLocalIgVoltAdj_bVoltAdj;
   uint8   u8LocalIndex_X;
   uint8   u8LocalIndex_Y;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalPara_X;
   uint16  u16LocalPara_Y;
   uint32  u32LocalExt_dstVehMesr;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   VEMS_vidGET(Ext_dstVehMes, u32LocalExt_dstVehMesr);

   u16LocalPara_X = MATHSRV_u16CalcParaIncAryU16(IgVoltAdj_nEng_bVoltAdjX_A,
                                                 u16LocalExt_nEng,
                                                 9);
   u8LocalIndex_X = (uint8)(u16LocalPara_X >> 8);
   u16LocalPara_Y = MATHSRV_u16CalcParaIncAryU16(IgVoltAdj_rAir_bVoltAdjY_A,
                                                 u16LocalEngM_rAirLdCor,
                                                 8);
   u8LocalIndex_Y = (uint8)(u16LocalPara_Y >> 8);
   IgVoltAdj_bVoltAdjOpp = IgVoltAdj_bVoltAdj_M[u8LocalIndex_X][u8LocalIndex_Y];

   if (  (u32LocalExt_dstVehMesr >= IgVoltAdj_dstVehMinVoltAdj_C)
      && (IgVoltAdj_bVoltAdjOpp != 0))
   {
      bLocalResultComp = 1;
   }
   else
   {
      bLocalResultComp = 0;
   }

   /* turn_on_delay*/
   if (bLocalResultComp != 0)
   {
      if (IGVOLTADJ_bResultComp_prev == 0)
      {
         IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1 = IgVoltAdj_tiActDly_C ;
      }
      else
      {
         if (IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1 > 0)
         {
            IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1 =
               (uint16)(IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1 - 1);
         }
      }

      if (IGVOLTADJ_u16VtAjZnTrnOnDlyCntr1 == 0)
      {
         IgVoltAdjReq_bVoltAdj = 1;
      }
      else
      {
         IgVoltAdjReq_bVoltAdj = 0;
      }
      IGVOLTADJ_bOutputTrndly = 0;
   }
   else
   {
      if (IGVOLTADJ_bResultComp_prev != 0)
      {
         IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2 = IgVoltAdj_tiDeacDly_C ;
      }
      else
      {
         if (IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2 > 0)
         {
            IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2 =
               (uint16)(IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2 - 1);
         }
      }

      if (IGVOLTADJ_u16VtAjZnTrnOnDlyCntr2 == 0)
      {
         IGVOLTADJ_bOutputTrndly = 1;
      }
      else
      {
         IGVOLTADJ_bOutputTrndly = 0;
      }
      IgVoltAdjReq_bVoltAdj = 0;
   }
   IGVOLTADJ_bResultComp_prev = bLocalResultComp ;

   /*Bascule_RS*/
   if (IGVOLTADJ_bOutputTrndly != 0)
   {
      IGVOLTADJ_bVltAdjZnFlipFlopOut = 0;
   }
   else
   {
      if (IgVoltAdjReq_bVoltAdj != 0)
      {
         IGVOLTADJ_bVltAdjZnFlipFlopOut = 1;
      }
   }

   if (  (  (IgVoltAdj_bVoltAdjReq != 0)
         || (IGVOLTADJ_bVltAdjZnFlipFlopOut != 0))
      && (IgVoltAdj_bActVoltAdj_C != 0))
   {
      bLocalIgVoltAdj_bVoltAdj = 1;
   }
   else
   {
      bLocalIgVoltAdj_bVoltAdj = 0;
   }
   VEMS_vidSET(IgVoltAdj_bVoltAdj, bLocalIgVoltAdj_bVoltAdj);
}
/*-------------------------------- end of file -------------------------------*/