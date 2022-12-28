/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TCOREGKNK                                               */
/* !Description     : TCOREGKNK Component                                     */
/*                                                                            */
/* !Module          : TCOREGKNK                                               */
/* !Description     : Cooling Request for Knock Control                       */
/*                                                                            */
/* !File            : TCOREGKNK_FCT1.C                                        */
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
/*   1 / TCOREGKNK_vidInitOutput                                              */
/*   2 / TCOREGKNK_vidFlag_Generation                                         */
/*   3 / TCOREGKNK_vidActiv_Condition                                         */
/*   4 / TCOREGKNK_vidCool_Req_Coord                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 04673 / 01                                        */
/* !OtherRefs   : 01460_11_01153_2 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#056462                                         */
/* !OtherRefs   : VEMS V02 ECU#056985                                         */
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
#include "MATHSRV.h"
#include "TCOREGKNK.h"
#include "TCOREGKNK_L.h"
#include "TCOREGKNK_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TCOREGKNK_vidInitOutput                                    */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 IgSys_agIgDeltaEngColdReq_MP;                                 */
/*  output boolean IgSys_bAcvLoTCoRegKnk;                                     */
/*  output boolean TCOREGKNK_bAcvCond;                                        */
/*  output uint16 TCOREGKNK_u16Cnt;                                           */
/*  output boolean TCOREGKNK_bTmrOut;                                         */
/*  output sint8 IgSys_agIgDeltaEngColdReq_MP;                                */
/*  output sint32 TCOREGKNK_s32FiltPosErrorMem;                               */
/*  output boolean IgSys_bAcvEngColdReq;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TCOREGKNK_vidInitOutput(void)
{
   VEMS_vidSET(IgSys_bAcvLoTCoRegKnk, 0);
   TCOREGKNK_bAcvCond = 0;
   TCOREGKNK_u16Cnt = 0;
   TCOREGKNK_bTmrOut = 0;
   IgSys_agIgDeltaEngColdReq_MP = 0;
   TCOREGKNK_s32FiltPosErrorMem = IgSys_agIgDeltaEngColdReq_MP * 256 ;
   IgSys_bAcvEngColdReq = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TCOREGKNK_vidFlag_Generation                               */
/* !Description :  In this block, the flag generation.  The flag is activated */
/*                 when the difference between Optimum ignition angle and     */
/*                 knock limit ignition angle (with a low pass filter) is     */
/*                 superior in a calibration level with hysteresis.           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04673_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IgSys_agIgMaxWiPrevAdpMv;                                     */
/*  input uint8 IgSys_agIgOptm;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 IgSys_nEng_IgSysTCoColdReq_A[6];                             */
/*  input uint8 IgSys_facFilDeltaAgIg_T[6];                                   */
/*  input uint8 IgSys_facFilDeltaAgIg_MP;                                     */
/*  input sint8 IgSys_agIgDeltaEngColdReq_MP;                                 */
/*  input sint32 TCOREGKNK_s32FiltPosErrorMem;                                */
/*  input sint8 IgSys_agIgDeltaInhEngColdReq_C;                               */
/*  input sint8 IgSys_agIgDeltaAcvEngColdReq_C;                               */
/*  output uint8 IgSys_facFilDeltaAgIg_MP;                                    */
/*  output sint8 IgSys_agIgDeltaEngColdReq_MP;                                */
/*  output sint32 TCOREGKNK_s32FiltPosErrorMem;                               */
/*  output boolean IgSys_bAcvEngColdReq;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TCOREGKNK_vidFlag_Generation(void)
{
   uint8  u8LocalIgSys_agIgMaxWiPrevAdpMv;
   uint8  u8LocalIgSys_agIgOptm;
   uint8  u8LocalFilterGain;
   uint8  u8localInterp1D;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalParaExt_nEng;
   sint16 s16LocalFilterOutput;
   sint16 s16LocalDiffVar;


   VEMS_vidGET(IgSys_agIgMaxWiPrevAdpMv, u8LocalIgSys_agIgMaxWiPrevAdpMv);
   VEMS_vidGET(IgSys_agIgOptm, u8LocalIgSys_agIgOptm);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   s16LocalDiffVar =
      (sint16)(u8LocalIgSys_agIgMaxWiPrevAdpMv - u8LocalIgSys_agIgOptm);
   s16LocalDiffVar = (sint16)((sint32)((s16LocalDiffVar * 3) + 4) / 8);

   /* Interp1D */
   u16LocalParaExt_nEng =
      MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_IgSysTCoColdReq_A,
                                   u16LocalExt_nEng,
                                   6);
   u8localInterp1D = MATHSRV_u8Interp1d(IgSys_facFilDeltaAgIg_T,
                                        u16LocalParaExt_nEng);
   IgSys_facFilDeltaAgIg_MP = (uint8)MATHSRV_udtMIN(u8localInterp1D, 100);

   /* Low Pass filter */
   if (IgSys_facFilDeltaAgIg_MP >= 100)
   {
      IgSys_agIgDeltaEngColdReq_MP = (sint8)s16LocalDiffVar;
      TCOREGKNK_s32FiltPosErrorMem =
         (sint32)(IgSys_agIgDeltaEngColdReq_MP * 256);
   }
   else
   {
      u8LocalFilterGain =
         (uint8)((IgSys_facFilDeltaAgIg_MP * 64) / 25);
      s16LocalFilterOutput =
         MATHSRV_s16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &TCOREGKNK_s32FiltPosErrorMem,
                                        s16LocalDiffVar);
      IgSys_agIgDeltaEngColdReq_MP =
         (sint8)MATHSRV_udtCLAMP(s16LocalFilterOutput, -100, 100);
   }

   /*NegHys*/
   if (IgSys_agIgDeltaEngColdReq_MP >= IgSys_agIgDeltaInhEngColdReq_C)
   {
      IgSys_bAcvEngColdReq = 0;
   }
   else
   {
      if (IgSys_agIgDeltaEngColdReq_MP <= IgSys_agIgDeltaAcvEngColdReq_C)
      {
         IgSys_bAcvEngColdReq = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TCOREGKNK_vidActiv_Condition                               */
/* !Description :  In this block, the condition activation:  - Not Cat Heating*/
/*                  - Activation of the knock control  - Inhibition           */
/*                 calibration  The knock control activation KnkMgt_bAcvKnkReg*/
/*                 is a boolean which is activated when the knock control is  */
/*                 activated.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04673_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean EOM_bTWCHeatPha;                                            */
/*  input boolean KnkMgt_bAcvKnkReg;                                          */
/*  input boolean IgSys_bInhIgSysTCoColdReq_C;                                */
/*  output boolean IgSys_bAuthIgSysTCoColdReq;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TCOREGKNK_vidActiv_Condition(void)
{
   boolean bLocalEOM_bTWCHeatPha;
   boolean bLocalKnkMgt_bAcvKnkReg;


   VEMS_vidGET(EOM_bTWCHeatPha, bLocalEOM_bTWCHeatPha);
   VEMS_vidGET(KnkMgt_bAcvKnkReg, bLocalKnkMgt_bAcvKnkReg);

   if (  (bLocalEOM_bTWCHeatPha == 0)
      && (bLocalKnkMgt_bAcvKnkReg != 0)
      && (IgSys_bInhIgSysTCoColdReq_C == 0))
   {
      IgSys_bAuthIgSysTCoColdReq = 1;
   }
   else
   {
      IgSys_bAuthIgSysTCoColdReq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TCOREGKNK_vidCool_Req_Coord                                */
/* !Description :  In this block the request coordination:  The request is    */
/*                 activated when:  - Primary flag is generated  - Condition  */
/*                 activation is equal to one  - The calibration temporisation*/
/*                 is not finished                                            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_04673_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TCOREGKNK_bAcvCond;                                         */
/*  input uint16 IgSys_tiEngColdReq_C;                                        */
/*  input boolean IgSys_bAuthIgSysTCoColdReq;                                 */
/*  input boolean IgSys_bAcvEngColdReq;                                       */
/*  input uint16 TCOREGKNK_u16Cnt;                                            */
/*  input boolean TCOREGKNK_bTmrOut;                                          */
/*  output boolean TCOREGKNK_bAcvCond;                                        */
/*  output uint16 TCOREGKNK_u16Cnt;                                           */
/*  output boolean TCOREGKNK_bTmrOut;                                         */
/*  output boolean IgSys_bAcvLoTCoRegKnk;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TCOREGKNK_vidCool_Req_Coord(void)
{
   boolean bLocalIgSys_bAcvLoTCoRegKnk;
   boolean bLocalAcvCondPrev;
   uint32  u32LocalVar;


   bLocalAcvCondPrev = TCOREGKNK_bAcvCond;
   u32LocalVar = 10000 * IgSys_tiEngColdReq_C;
   if (IgSys_bAuthIgSysTCoColdReq != 0)
   {
      TCOREGKNK_bAcvCond = IgSys_bAcvEngColdReq;
   }
   else
   {
      TCOREGKNK_bAcvCond = 0;
   }

   /* TmrRst */
   if (  (TCOREGKNK_bAcvCond != 0)
      && (bLocalAcvCondPrev == 0))
   {
      TCOREGKNK_u16Cnt = (uint16)MATHSRV_udtMIN(u32LocalVar, 65535);
      if (TCOREGKNK_u16Cnt != 0)
      {
         TCOREGKNK_bTmrOut = 1;
      }
      else
      {
         TCOREGKNK_bTmrOut = 0;
      }
   }
   else
   {
      if (TCOREGKNK_u16Cnt > 0)
      {
         TCOREGKNK_u16Cnt = (uint16)(TCOREGKNK_u16Cnt - 1);
         if (TCOREGKNK_u16Cnt != 0)
         {
            TCOREGKNK_bTmrOut = 1;
         }
         else
         {
            TCOREGKNK_bTmrOut = 0;
         }
      }
      else
      {
         TCOREGKNK_bTmrOut = 0;
      }
   }

   if (  (TCOREGKNK_bTmrOut != 0)
      || (TCOREGKNK_bAcvCond != 0))
   {
      bLocalIgSys_bAcvLoTCoRegKnk = 1;
   }
   else
   {
      bLocalIgSys_bAcvLoTCoRegKnk = 0;
   }
   VEMS_vidSET(IgSys_bAcvLoTCoRegKnk, bLocalIgSys_bAcvLoTCoRegKnk);
}
/*-------------------------------- end of file -------------------------------*/