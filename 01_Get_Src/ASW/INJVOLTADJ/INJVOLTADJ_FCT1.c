/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INJVOLTADJ                                              */
/* !Description     : INJVOLTADJ Component                                    */
/*                                                                            */
/* !Module          : INJVOLTADJ                                              */
/* !Description     : VOLTAGE BOOST REQUEST FOR INJECTION SYSTEM              */
/*                                                                            */
/* !File            : INJVOLTADJ_FCT1.C                                       */
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
/*   1 / INJVOLTADJ_vidInitOutput                                             */
/*   2 / INJVOLTADJ_vidInjVoltAdj                                             */
/*   3 / INJVOLTADJ_vidInjCmdVolt                                             */
/*   4 / INJVOLTADJ_vidPmpCmdVolt                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5074748 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#059782                                         */
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
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "INJVOLTADJ.h"
#include "INJVOLTADJ_L.h"
#include "INJVOLTADJ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJVOLTADJ_vidInitOutput                                   */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean InjSys_bVoltAdj;                                           */
/*  output boolean INJVOLTADJ_bOutputHysteresis;                              */
/*  output uint16 INJVOLTADJ_u16PFuCtlCmdReqPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJVOLTADJ_vidInitOutput(void)
{
   VEMS_vidSET(InjSys_bVoltAdj, 0);
   INJVOLTADJ_bOutputHysteresis = 0;
   INJVOLTADJ_u16PFuCtlCmdReqPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJVOLTADJ_vidInjVoltAdj                                   */
/* !Description :  Ce bloc d'injection peut être divisé en deux parties:      */
/*                 InjSys_bInjVoltAdj; demande coup de pouce pour injecteurs. */
/*                 InjSys_bPmpVoltAdj: coup de pouce pour la demande de la    */
/*                 pompe HP.                                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_E_11_05229_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void INJVOLTADJ_vidInjCmdVolt();                              */
/*  extf argret void INJVOLTADJ_vidPmpCmdVolt();                              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean InjSys_bInjVoltAdj;                                         */
/*  input boolean InjSys_bPmpVoltAdj;                                         */
/*  output boolean InjSys_bVoltAdj;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJVOLTADJ_vidInjVoltAdj(void)
{
   INJVOLTADJ_vidInjCmdVolt();
   INJVOLTADJ_vidPmpCmdVolt();

   if (  (InjSys_bInjVoltAdj != 0)
      || (InjSys_bPmpVoltAdj != 0))
   {
      VEMS_vidSET(InjSys_bVoltAdj, 1);
   }
   else
   {
      VEMS_vidSET(InjSys_bVoltAdj, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJVOLTADJ_vidInjCmdVolt                                   */
/* !Description :  Ce bloc traite la génération de stimuler la demande de     */
/*                 tension pour injecteur pour examiner certaines restrictions*/
/*                 liées aux limites du matériel.                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 InjrSys_prm_tiInj[4];                                        */
/*  input uint8 InjSys_NrInjVoltBstReq;                                       */
/*  input uint32 InjSys_tiInjVoltBstReq_A[9];                                 */
/*  input uint32 InjSys_tiTotInjVoltBstReq;                                   */
/*  input uint16 InjSys_factiInjVoltBstReq_T[9];                              */
/*  input uint8 InjSys_stTypElCmdInjrReq;                                     */
/*  input uint8 InjSys_stTypInjVoltBstReq_A[4];                               */
/*  input uint16 InjSys_facInjVoltBstReq_T[4];                                */
/*  input uint8 InjSys_NrInjuBattOfsThd_A[4];                                 */
/*  input uint16 InjSys_uBattNrInjOfsThd_T[4];                                */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 InjSys_nInjVoltAdjThd_A[9];                                  */
/*  input uint16 InjSys_uBattInjVoltAdjThd_T[9];                              */
/*  input uint16 InjSys_facInjVoltBstReq;                                     */
/*  input uint16 InjSys_uBatInjVoltAdjThd;                                    */
/*  input uint16 InjSys_uBatInjVoltBstReqThd;                                 */
/*  input uint16 InjSys_uBatMinThd_C;                                         */
/*  input sint16 Ext_uBattMes;                                                */
/*  input boolean InjSys_bTotCutOff;                                          */
/*  output uint8 InjSys_NrInjVoltBstReq;                                      */
/*  output uint32 InjSys_tiTotInjVoltBstReq;                                  */
/*  output uint16 InjSys_facInjVoltBstReq;                                    */
/*  output uint16 InjSys_uBatInjVoltAdjThd;                                   */
/*  output uint16 InjSys_uBatInjVoltBstReqThd;                                */
/*  output boolean InjSys_bInjVoltAdj;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJVOLTADJ_vidInjCmdVolt(void)
{
   boolean  bLocalInjSys_bTotCutOff;
   uint8    u8LocalIdx;
   uint8    u8LocalInjSys_stTypElCmdInjrReq;
   uint16   u16LocalCalcPara_factiInjVoltBst;
   uint16   u16LocalInterp1d_facInjVoltBst;
   uint16   u16LocalInterp1d_BattNrInjOfsThd;
   uint16   u16LocalCalcPara_uBattInjVoltAdj;
   uint16   u16LocalInterp1d_uBattInjVoltAdj;
   uint16   u16LocalInjSys_tiInjVoltBstReq_A[9];
   /*QAC Warning : Msg(2:3132) --> No impact*/
   uint16   u16LocalInjSys_TotInjVoltBstReq;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalCalcPara_facNrInjOfs;
   uint16   u16LocalCalcPara_facInjVoltBst;
   uint16   u16LocalInterp1d_factiInjVoltBst;
   uint16   u16LocalSwitch;
   uint16   u16LocalProd;
   sint16   s16LocalExt_uBattMes;
   uint32   u32LocalInjrSys_prm_tiInj[4];
   /*QAC Warning : Msg(2:3204) --> local variable used once should be declared
   as constant : no impact*/
   uint32   u32LocalInjSys_tiTotInjVoBstReq;
   uint32   u32LocalVariable1;
   uint32   u32LocalVariable2;
   uint32   u32LocalVariable3;
   uint32   u32LocalProd;
   sint32   s32LocalInjSys_uBatVoltBstReqThd;


   /* calcul de InjSys_NrInjVoltBstReq */
   VEMS_vidGET1DArray(InjrSys_prm_tiInj, 4, u32LocalInjrSys_prm_tiInj);
   InjSys_NrInjVoltBstReq = 0;
   if (u32LocalInjrSys_prm_tiInj[0] != 0)
   {
      InjSys_NrInjVoltBstReq = (uint8)(InjSys_NrInjVoltBstReq + 1);
   }

   if (u32LocalInjrSys_prm_tiInj[1] != 0)
   {
      InjSys_NrInjVoltBstReq = (uint8)(InjSys_NrInjVoltBstReq + 1);
   }

   if (u32LocalInjrSys_prm_tiInj[2] != 0)
   {
      InjSys_NrInjVoltBstReq = (uint8)(InjSys_NrInjVoltBstReq + 1);
   }

   if (u32LocalInjrSys_prm_tiInj[3] != 0)
   {
      InjSys_NrInjVoltBstReq = (uint8)(InjSys_NrInjVoltBstReq + 1);
   }

   /* calcul de InjSys_tiTotInjVoltBstReq */
   u32LocalVariable1 = (UINT32_MAX - u32LocalInjrSys_prm_tiInj[1]);
   if (u32LocalInjrSys_prm_tiInj[0] > u32LocalVariable1)
   {
      u32LocalInjSys_tiTotInjVoBstReq = UINT32_MAX;
   }
   else
   {
      u32LocalInjSys_tiTotInjVoBstReq = ( u32LocalInjrSys_prm_tiInj[0]
                                        + u32LocalInjrSys_prm_tiInj[1]);
      u32LocalVariable2 = (UINT32_MAX - u32LocalInjrSys_prm_tiInj[2]);
      if (u32LocalInjSys_tiTotInjVoBstReq > u32LocalVariable2)
      {
         u32LocalInjSys_tiTotInjVoBstReq = UINT32_MAX;
      }
      else
      {
         u32LocalInjSys_tiTotInjVoBstReq = ( u32LocalInjSys_tiTotInjVoBstReq
                                           + u32LocalInjrSys_prm_tiInj[2]);
         u32LocalVariable3 = (UINT32_MAX - u32LocalInjrSys_prm_tiInj[3]);
         if (u32LocalInjSys_tiTotInjVoBstReq > u32LocalVariable3)
         {
            u32LocalInjSys_tiTotInjVoBstReq = UINT32_MAX;
         }
         else
         {
            u32LocalInjSys_tiTotInjVoBstReq = ( u32LocalInjSys_tiTotInjVoBstReq
                                              + u32LocalInjrSys_prm_tiInj[3]);
         }
      }
   }
   InjSys_tiTotInjVoltBstReq = u32LocalInjSys_tiTotInjVoBstReq;


   for (u8LocalIdx = 0; u8LocalIdx < 9; u8LocalIdx++)
   {
      u16LocalInjSys_tiInjVoltBstReq_A[u8LocalIdx] =
         (uint16)(InjSys_tiInjVoltBstReq_A[u8LocalIdx] / 65536);
   }
   u16LocalInjSys_TotInjVoltBstReq = (uint16)( InjSys_tiTotInjVoltBstReq
                                             / 65536);

   u16LocalCalcPara_factiInjVoltBst =
      MATHSRV_u16CalcParaIncAryU16(u16LocalInjSys_tiInjVoltBstReq_A,
                                   u16LocalInjSys_TotInjVoltBstReq,
                                   9);
   u16LocalInterp1d_factiInjVoltBst =
      MATHSRV_u16Interp1d(InjSys_factiInjVoltBstReq_T,
                          u16LocalCalcPara_factiInjVoltBst);

   VEMS_vidGET(InjSys_stTypElCmdInjrReq, u8LocalInjSys_stTypElCmdInjrReq);
   u16LocalCalcPara_facInjVoltBst =
      MATHSRV_u16CalcParaIncAryU8(InjSys_stTypInjVoltBstReq_A,
                                  u8LocalInjSys_stTypElCmdInjrReq,
                                  4);
   u16LocalInterp1d_facInjVoltBst =
      MATHSRV_u16Interp1d(InjSys_facInjVoltBstReq_T,
                          u16LocalCalcPara_facInjVoltBst);

   u16LocalCalcPara_facNrInjOfs =
      MATHSRV_u16CalcParaIncAryU8(InjSys_NrInjuBattOfsThd_A,
                                  InjSys_NrInjVoltBstReq,
                                  4);
   u16LocalInterp1d_BattNrInjOfsThd =
      MATHSRV_u16Interp1d(InjSys_uBattNrInjOfsThd_T,
                          u16LocalCalcPara_facNrInjOfs);

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalCalcPara_uBattInjVoltAdj =
      MATHSRV_u16CalcParaIncAryU16(InjSys_nInjVoltAdjThd_A,
                                   u16LocalExt_nEng,
                                   9);

   u16LocalInterp1d_uBattInjVoltAdj =
      MATHSRV_u16Interp1d(InjSys_uBattInjVoltAdjThd_T,
                          u16LocalCalcPara_uBattInjVoltAdj);

   /* calcul de InjSys_facInjVoltBstReq */
   if (  (u16LocalInterp1d_factiInjVoltBst == 0)
      || (u16LocalInterp1d_facInjVoltBst == 0))
   {
      InjSys_facInjVoltBstReq = 0;
   }
   else
   {
      u32LocalProd =(uint32)( ( ( u16LocalInterp1d_factiInjVoltBst
                                * u16LocalInterp1d_facInjVoltBst)
                              + 500)
                            / 1000);
      InjSys_facInjVoltBstReq = (uint16) MATHSRV_udtMIN(u32LocalProd, 1000);
   }

   /* calcul de InjSys_uBatInjVoltAdjThd */
   u16LocalProd =
      (uint16)( ( ( InjSys_facInjVoltBstReq
                  * u16LocalInterp1d_uBattInjVoltAdj)
                + 500)
              / 1000);
   InjSys_uBatInjVoltAdjThd = (uint16)MATHSRV_udtMIN(u16LocalProd, 3200);

   /*calcul de InjSys_uBatInjVoltBstReqThd*/

   s32LocalInjSys_uBatVoltBstReqThd =
      (sint32)(InjSys_uBatInjVoltAdjThd - u16LocalInterp1d_BattNrInjOfsThd);
   InjSys_uBatInjVoltBstReqThd =
      (uint16)MATHSRV_udtMAX(s32LocalInjSys_uBatVoltBstReqThd, 0);

   /* calcul de InjSys_bInjVoltAdj */
   if (InjSys_uBatInjVoltBstReqThd < InjSys_uBatMinThd_C)
   {
      u16LocalSwitch = InjSys_uBatMinThd_C;
   }
   else
   {
      u16LocalSwitch = InjSys_uBatInjVoltBstReqThd;
   }

   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   VEMS_vidGET(InjSys_bTotCutOff, bLocalInjSys_bTotCutOff);
   if (  (s16LocalExt_uBattMes < u16LocalSwitch)
      && (bLocalInjSys_bTotCutOff == 0))
   {
      InjSys_bInjVoltAdj = 1;
   }
   else
   {
      InjSys_bInjVoltAdj = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INJVOLTADJ_vidPmpCmdVolt                                   */
/* !Description :  Ce bloc envoie une requête pour stimuler la pompe HP.      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 PFuCtl_tiBeg2PulseDif;                                       */
/*  input uint16 PFuCtl_tiPmpCmdDecelReq;                                     */
/*  input uint16 PFuCtl_tiPmpCmdReq;                                          */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 PFuCtl_agPmpCmdReq;                                          */
/*  input uint16 InjSys_tiTotPmpCmdReq;                                       */
/*  input uint16 INJVOLTADJ_u16PFuCtlCmdReqPrev;                              */
/*  input uint16 FuSysM_agPerPmpRef_C;                                        */
/*  input uint16 InjSys_agPmpVoltAdjThd_C;                                    */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint16 InjSys_uBattPmpVoltAdjLoThd_C;                               */
/*  input uint16 InjSys_uBattPmpVoltAdjHiThd_C;                               */
/*  input boolean INJVOLTADJ_bOutputHysteresis;                               */
/*  input boolean Ext_bStoHPPmpActCmd;                                        */
/*  output uint16 InjSys_tiTotPmpCmdReq;                                      */
/*  output uint16 INJVOLTADJ_u16PFuCtlCmdReqPrev;                             */
/*  output boolean InjSys_bPmpVoltAdj;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INJVOLTADJ_vidPmpCmdVolt(void)
{
   boolean  bLocalExt_bStoHPPmpActCmd;
   boolean  bLocalInputand;
   uint16   u16LocalPFuCtl_tiBeg2PulseDif;
   uint16   u16LocalPFuCtl_tiPmpCmdDecelReq;
   uint16   u16LocalPFuCtl_tiPmpCmdReq;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalPFuCtl_agPmpCmdReq;
   uint16   u16LocalExt_uBattMes;
   uint16   u16LocalDiv;
   sint16   s16LocalExt_uBattMes;
   uint32   u32LocalInjSys_tiTotPmpCmdReq;
   uint32   u32LocalResult;
   uint32   u32LocalProd;
   sint32   s32LocalResult;


   VEMS_vidGET(PFuCtl_tiBeg2PulseDif, u16LocalPFuCtl_tiBeg2PulseDif);
   VEMS_vidGET(PFuCtl_tiPmpCmdDecelReq, u16LocalPFuCtl_tiPmpCmdDecelReq);
   VEMS_vidGET(PFuCtl_tiPmpCmdReq, u16LocalPFuCtl_tiPmpCmdReq);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(PFuCtl_agPmpCmdReq, u16LocalPFuCtl_agPmpCmdReq);

   if (u16LocalPFuCtl_tiPmpCmdDecelReq > 0)
   {
      u32LocalInjSys_tiTotPmpCmdReq =
         (uint32)( u16LocalPFuCtl_tiBeg2PulseDif
                 + u16LocalPFuCtl_tiPmpCmdDecelReq);
   }
   else
   {
      u32LocalInjSys_tiTotPmpCmdReq = u16LocalPFuCtl_tiPmpCmdReq;
   }
   InjSys_tiTotPmpCmdReq = (uint16)MATHSRV_udtMIN(u32LocalInjSys_tiTotPmpCmdReq,
                                                  65535);

   u32LocalProd = (u16LocalExt_nEng * InjSys_tiTotPmpCmdReq);
   if (u32LocalProd < 134217727UL)
   {
      u32LocalProd = (u32LocalProd * 32);
      u32LocalResult = ((u32LocalProd + 39063) / 78125);
   }
   else
   {
      u16LocalDiv = (uint16)((u32LocalProd + 39063) / 78125);
      u32LocalResult = (u16LocalDiv * 32);
   }
   s32LocalResult = (sint32)( ( u32LocalResult
                              + INJVOLTADJ_u16PFuCtlCmdReqPrev)
                            - ( FuSysM_agPerPmpRef_C
                              + u16LocalPFuCtl_agPmpCmdReq));
   if (s32LocalResult > InjSys_agPmpVoltAdjThd_C)
   {
      bLocalInputand = 1;
   }
   else
   {
      bLocalInputand = 0;
   }
   INJVOLTADJ_u16PFuCtlCmdReqPrev =
      (uint16)MATHSRV_udtMIN(u16LocalPFuCtl_agPmpCmdReq, 7680);

   VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
   u16LocalExt_uBattMes = (uint16)MATHSRV_udtMAX(s16LocalExt_uBattMes, 0);
   MATHSRV_vidSchmittTriggerU16(u16LocalExt_uBattMes,
                                InjSys_uBattPmpVoltAdjLoThd_C,
                                InjSys_uBattPmpVoltAdjHiThd_C,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &INJVOLTADJ_bOutputHysteresis);

   VEMS_vidGET(Ext_bStoHPPmpActCmd, bLocalExt_bStoHPPmpActCmd);

   if (  (bLocalInputand != 0)
      && (INJVOLTADJ_bOutputHysteresis != 0)
      && (bLocalExt_bStoHPPmpActCmd != 0))
   {
      InjSys_bPmpVoltAdj = 1;
   }
   else
   {
      InjSys_bPmpVoltAdj = 0;
   }
}
/*------------------------------- end of file --------------------------------*/