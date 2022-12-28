/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : COFANCMDDIAG                                            */
/* !Description     : COFANCMDDIAG component.                                 */
/*                                                                            */
/* !Module          : COFANCMDDIAG                                            */
/* !Description     : COMMANDE ET DIAGNOSTICS DES GMV.                        */
/*                                                                            */
/* !File            : COFANCMDDIAG_FCT5.C                                     */
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
/*   1 / COFANCMDDIAG_vidSpdFanB1Mng                                          */
/*   2 / COFANCMDDIAG_vidSpdFanB2Mng                                          */
/*   3 / COFANCMDDIAG_vidSpdFanCMng                                           */
/*   4 / COFANCMDDIAG_vidDgoCoFanC                                            */
/*   5 / COFANCMDDIAG_vidDgoHalFanC                                           */
/*   6 / COFANCMDDIAG_vidDgClsdRlyCoFanB2                                     */
/*   7 / COFANCMDDIAG_vidDgoCohCoFanB2                                        */
/*   8 / COFANCMDDIAG_vidECIDgo                                               */
/*   9 / COFANCMDDIAG_vidCritScCnt                                            */
/*   10 / COFANCMDDIAG_vidDiagBMonRun                                         */
/*                                                                            */
/* !Reference   : PTS_DOC_6722439 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/COFANCMDDIAG/COFANCMDDIAG_FCT5.C_v$*/
/* $Revision::   1.13     $$Author::   wbouach        $$Date::   24 Jul 2014 $*/
/* $Author::   wbouach                                $$Date::   24 Jul 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "COFANCMDDIAG_IM.H"
#include "COFANCMDDIAG_L.H"
#include "COFANCMDDIAG.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidSpdFanB1Mng                                */
/* !Description :  Fonction de calcule, pour un équipement de type B1 la      */
/*                 vitesse prédite à partir de la consigne de vitesse GMV.    */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB1HiThd_C;                                          */
/*  input uint8 CoFan_rHiSpdFan_C;                                            */
/*  input uint8 CoFan_rFanB1LoThd_C;                                          */
/*  input boolean ThMgt_bTarHiSpdFan;                                         */
/*  output uint8 CoFan_rSpdFanPred;                                           */
/*  output boolean ThMgt_bTarHiSpdFan;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidSpdFanB1Mng(void)
{
   boolean bLocalThMgt_bTarHiSpdFan;
   uint8   u8LocalThMgtrSpdFanReq;


   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgtrSpdFanReq);
   if (CoFan_rSpdFanPred == 0)
   {
      if (u8LocalThMgtrSpdFanReq > CoFan_rFanB1HiThd_C)
      {
         CoFan_rSpdFanPred = (uint8)MATHSRV_udtMIN(CoFan_rHiSpdFan_C, 110);
      }
      else
      {
         CoFan_rSpdFanPred = 0;
      }
   }
   else
   {
      if (u8LocalThMgtrSpdFanReq < CoFan_rFanB1LoThd_C)
      {
         CoFan_rSpdFanPred = 0;
      }
      else
      {
         CoFan_rSpdFanPred = (uint8)MATHSRV_udtMIN(CoFan_rHiSpdFan_C, 110);
      }
   }

   VEMS_vidGET(ThMgt_bTarHiSpdFan, bLocalThMgt_bTarHiSpdFan);
   if (bLocalThMgt_bTarHiSpdFan == 0)
   {
      if (u8LocalThMgtrSpdFanReq > CoFan_rFanB1HiThd_C)
      {
         bLocalThMgt_bTarHiSpdFan = 1;
      }
      else
      {
         bLocalThMgt_bTarHiSpdFan = 0;
      }
   }
   else
   {
      if (u8LocalThMgtrSpdFanReq < CoFan_rFanB1LoThd_C)
      {
         bLocalThMgt_bTarHiSpdFan = 0;
      }
      else
      {
         bLocalThMgt_bTarHiSpdFan = 1;
      }
   }
   VEMS_vidSET(ThMgt_bTarHiSpdFan, bLocalThMgt_bTarHiSpdFan);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidSpdFanB2Mng                                */
/* !Description :  Cette fonction calcule, pour un équipement de type B2 la   */
/*                 vitesse prédite à partir de la consigne de vitesse GMV.    */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input uint8 COFANCMDDIAG_u8SchmitOutput1;                                 */
/*  input uint8 CoFan_rFanB2LoSpdHiThd_C;                                     */
/*  input uint8 CoFan_rLoSpdFan_C;                                            */
/*  input uint8 CoFan_rFanB2LoSpdLoThd_C;                                     */
/*  input uint8 CoFan_rSpdFanPred;                                            */
/*  input uint8 CoFan_rFanB2HiSpdHiThd_C;                                     */
/*  input uint8 CoFan_rHiSpdFan_C;                                            */
/*  input uint8 CoFan_rFanB2HiSpdLoThd_C;                                     */
/*  input uint8 CoFan_rFanB2HiSpd2LoThd_C;                                    */
/*  input uint8 CoFan_rFanB2HiSpd2HiThd_C;                                    */
/*  input boolean CoFan_bFanB2HiSpd2;                                         */
/*  input boolean ThMgt_bTarLowSpdFan;                                        */
/*  input boolean ThMgt_bTarHiSpdFan;                                         */
/*  output uint8 COFANCMDDIAG_u8SchmitOutput1;                                */
/*  output uint8 CoFan_rSpdFanPred;                                           */
/*  output boolean ThMgt_bTarLowSpdFan;                                       */
/*  output boolean ThMgt_bTarHiSpdFan;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidSpdFanB2Mng(void)
{
   boolean bLocalThMgt_bTarLowSpdFan;
   boolean bLocalThMgt_bTarHiSpdFan;
   uint8   u8LocalThMgtrSpdFanReq;


   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgtrSpdFanReq);
   if (COFANCMDDIAG_u8SchmitOutput1 == 0)
   {
      if (u8LocalThMgtrSpdFanReq > CoFan_rFanB2LoSpdHiThd_C)
      {
         COFANCMDDIAG_u8SchmitOutput1 = CoFan_rLoSpdFan_C;
      }
      else
      {
         COFANCMDDIAG_u8SchmitOutput1 = 0;
      }
   }
   else
   {
      if (u8LocalThMgtrSpdFanReq < CoFan_rFanB2LoSpdLoThd_C)
      {
         COFANCMDDIAG_u8SchmitOutput1 = 0;
      }
      else
      {
         COFANCMDDIAG_u8SchmitOutput1 = CoFan_rLoSpdFan_C;
      }
   }

   if (CoFan_rSpdFanPred == COFANCMDDIAG_u8SchmitOutput1)
   {
      if (u8LocalThMgtrSpdFanReq > CoFan_rFanB2HiSpdHiThd_C)
      {
         CoFan_rSpdFanPred = (uint8)MATHSRV_udtMIN(CoFan_rHiSpdFan_C, 110);
      }
      else
      {
         CoFan_rSpdFanPred = (uint8)MATHSRV_udtMIN(COFANCMDDIAG_u8SchmitOutput1,
                                                   110);
      }
   }
   else
   {
      if (u8LocalThMgtrSpdFanReq < CoFan_rFanB2HiSpdLoThd_C)
      {
         CoFan_rSpdFanPred = (uint8)MATHSRV_udtMIN(COFANCMDDIAG_u8SchmitOutput1,
                                                   110);
      }
      else
      {
         CoFan_rSpdFanPred = (uint8)MATHSRV_udtMIN(CoFan_rHiSpdFan_C, 110);
      }
   }
   MATHSRV_vidSchmittTriggerU16((uint16)u8LocalThMgtrSpdFanReq,
                                (uint16)CoFan_rFanB2HiSpd2LoThd_C,
                                (uint16)CoFan_rFanB2HiSpd2HiThd_C,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &CoFan_bFanB2HiSpd2);

   VEMS_vidGET(ThMgt_bTarLowSpdFan, bLocalThMgt_bTarLowSpdFan);
   if (bLocalThMgt_bTarLowSpdFan == 0)
   {
      if (u8LocalThMgtrSpdFanReq > CoFan_rFanB2LoSpdHiThd_C)
      {
         bLocalThMgt_bTarLowSpdFan = 1;
      }
      else
      {
         bLocalThMgt_bTarLowSpdFan = 0;
      }
   }
   else
   {
      if (u8LocalThMgtrSpdFanReq < CoFan_rFanB2LoSpdLoThd_C)
      {
         bLocalThMgt_bTarLowSpdFan = 0;
      }
      else
      {
         bLocalThMgt_bTarLowSpdFan = 1;
      }
   }
   VEMS_vidSET(ThMgt_bTarLowSpdFan, bLocalThMgt_bTarLowSpdFan);

   VEMS_vidGET(ThMgt_bTarHiSpdFan, bLocalThMgt_bTarHiSpdFan);
   if (bLocalThMgt_bTarHiSpdFan == 0)
   {
      if (u8LocalThMgtrSpdFanReq > CoFan_rFanB2HiSpdHiThd_C)
      {
         bLocalThMgt_bTarHiSpdFan = 1;
      }
      else
      {
         bLocalThMgt_bTarHiSpdFan = 0;
      }
   }
   else
   {
      if (u8LocalThMgtrSpdFanReq < CoFan_rFanB2HiSpdLoThd_C)
      {
         bLocalThMgt_bTarHiSpdFan = 0;
      }
      else
      {
         bLocalThMgt_bTarHiSpdFan = 1;
      }
   }
   VEMS_vidSET(ThMgt_bTarHiSpdFan, bLocalThMgt_bTarHiSpdFan);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidSpdFanCMng                                 */
/* !Description :  Fonction de calcul pour un équipement de type C de la      */
/*                 vitesse prédite à partir de la consigne de vitesse GMV     */
/*                 après l’avoir filtrée à l’aide d’un limiteur de pente.     */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CoFan_rSpdFanCMaxSlewRate_C;                                 */
/*  input uint16 CoFan_rSpdFanCMinSlewRate_C;                                 */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input uint8 CoFan_rSpdFanCReqFil;                                         */
/*  input uint8 CoFan_rSpdFanCThd_C;                                          */
/*  input uint8 CoFan_LoStFan1_C;                                             */
/*  input uint8 CoFan_HiStFan1_C;                                             */
/*  input uint8 CoFan_CFricMinSpd_C;                                          */
/*  output uint8 CoFan_rSpdFanCReqFil;                                        */
/*  output uint8 CoFan_rSpdFanPred;                                           */
/*  output uint8 CoFan_rRCOFanC;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidSpdFanCMng(void)
{

   uint8  u8LocalThMgtrSpdFanReq;
   sint16 s16LocalCoFan;
   sint16 s16LocalCoFan2;
   sint16 s16LocalCoFan3;
   sint32 s32LocalCoFan;
   uint16 u16LocalMaxSlewRate;
   uint16 u16LocalMinSlewRate;
   uint16 u16LocalSpdFanCReqFil;

   u16LocalMaxSlewRate = (uint16)( ( CoFan_rSpdFanCMaxSlewRate_C
                                   * CoFan_SampleTiMid_SC)
                                 / 10000);
   u16LocalMinSlewRate = (uint16)( ( CoFan_rSpdFanCMinSlewRate_C
                                   * CoFan_SampleTiMid_SC)
                                 / 10000);
   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgtrSpdFanReq);
   u16LocalSpdFanCReqFil = MATHSRV_u16SlewFilter((uint16)CoFan_rSpdFanCReqFil,
                                                 (uint16)u8LocalThMgtrSpdFanReq,
                                                 u16LocalMaxSlewRate,
                                                 u16LocalMinSlewRate);
   CoFan_rSpdFanCReqFil = (uint8)MATHSRV_udtMIN(u16LocalSpdFanCReqFil, 110);
   if (CoFan_rSpdFanCReqFil <= CoFan_rSpdFanCThd_C)
   {
      CoFan_rSpdFanPred = 0;
      CoFan_rRCOFanC = (uint8)MATHSRV_udtMIN(CoFan_LoStFan1_C, 100);
   }
   else
   {
      CoFan_rSpdFanPred = CoFan_rSpdFanCReqFil;
      s16LocalCoFan = (sint16)(CoFan_HiStFan1_C - CoFan_CFricMinSpd_C);
      s16LocalCoFan3 = (sint16)(CoFan_rSpdFanCReqFil - 100);
      s16LocalCoFan2 = (sint16)(CoFan_HiStFan1_C * (100 - CoFan_rSpdFanCThd_C));
      s32LocalCoFan = (sint32)((s16LocalCoFan * s16LocalCoFan3));
      if (CoFan_rSpdFanCThd_C == 100)
      {
         if (s32LocalCoFan < 0)
         {
            s32LocalCoFan = 0;
         }
         else
         {
            s32LocalCoFan = 100;
         }
      }
      else
/* !QAC Deviation: Msg(2:0584) Division by value that is possibly zero.       */
/*  Reason : Division by zero is treated before reaching this part of code.   */
      {
         s32LocalCoFan = ( (s32LocalCoFan + s16LocalCoFan2)
                         / (100 - CoFan_rSpdFanCThd_C));
      }
      CoFan_rRCOFanC = (uint8)MATHSRV_udtCLAMP(s32LocalCoFan, 0, 100);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoCoFanC                                  */
/* !Description :  Cette fonction réalise l’acquisition d’ETAT_GMV provenant  */
/*                 du LdB en équipement C.                                    */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_010.01                                     */
/*                 VEMS_R_09_00032_011.01                                     */
/*                 VEMS_R_09_00032_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void COFANCMDDIAG_vidDgoHalFanC();                            */
/*  extf argret void COFANCMDDIAG_vidECIDgo();                                */
/*  extf argret void COFANCMDDIAG_vidCritScCnt();                             */
/*  input uint16 Acquisition_etat_gmvC;                                       */
/*  input uint8 CoFan_rFanOKVal_C;                                            */
/*  input uint8 CoFan_rFanTolRngVal_C;                                        */
/*  input uint8 CoFan_rFanCritScVal_C;                                        */
/*  input uint8 CoFan_rFanNOKVal_C;                                           */
/*  input boolean CoFan_bMonRunEl_StFanC;                                     */
/*  output uint16 Ext_rStFanC;                                                */
/*  output boolean CoFan_bDgoUnVld_StFanC;                                    */
/*  output boolean CoFan_bDgoCritSc_StFanC;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoCoFanC(void)
{
   sint16 s16LocalFanOKVal;
   sint16 s16LocalFanCritScVal;
   sint16 s16LocalFanNOKVal;
   uint16 u16LocalFanOKVal;
   uint16 u16LocalFanOKVal2;
   uint16 u16LocalFanCritScVal;
   uint16 u16LocalFanCritScVal2;
   uint16 u16LocalFanNOKVal;
   uint16 u16LocalFanNOKVal2;
   uint16 u16LocalExt_rStFanC;
   uint16 u16LocalAcquisitionEtatGmvC;


   VEMS_vidGET(Acquisition_etat_gmvC, u16LocalAcquisitionEtatGmvC);
   u16LocalAcquisitionEtatGmvC =
      (uint16)(((u16LocalAcquisitionEtatGmvC * 125) + 2048) / 4096);
   u16LocalExt_rStFanC =
      (uint16)MATHSRV_udtMIN(u16LocalAcquisitionEtatGmvC, 1000);
   VEMS_vidSET(Ext_rStFanC, u16LocalExt_rStFanC);
   COFANCMDDIAG_vidDgoHalFanC();
   COFANCMDDIAG_vidECIDgo();
   s16LocalFanOKVal = (sint16)( (CoFan_rFanOKVal_C - CoFan_rFanTolRngVal_C)
                              * 10);
   u16LocalFanOKVal = (uint16)MATHSRV_udtMAX(s16LocalFanOKVal, 0);
   u16LocalFanOKVal2 = (uint16)( (CoFan_rFanOKVal_C + CoFan_rFanTolRngVal_C)
                               * 10);
   s16LocalFanCritScVal = (sint16)( ( CoFan_rFanCritScVal_C
                                    - CoFan_rFanTolRngVal_C)
                                  * 10);
   u16LocalFanCritScVal = (uint16)MATHSRV_udtMAX(s16LocalFanCritScVal, 0);
   u16LocalFanCritScVal2 = (uint16)( ( CoFan_rFanCritScVal_C
                                     + CoFan_rFanTolRngVal_C)
                                   * 10);
   s16LocalFanNOKVal = (sint16)( ( CoFan_rFanNOKVal_C - CoFan_rFanTolRngVal_C)
                               * 10);
   u16LocalFanNOKVal = (uint16)MATHSRV_udtMAX(s16LocalFanNOKVal, 0);
   u16LocalFanNOKVal2 = (uint16)( (CoFan_rFanNOKVal_C + CoFan_rFanTolRngVal_C)
                                * 10);

   if (  (u16LocalExt_rStFanC > 0)
      && (u16LocalExt_rStFanC < u16LocalFanOKVal))
   {
      CoFan_bDgoUnVld_StFanC = 1;
   }
   else
   {
      if (  (u16LocalExt_rStFanC > u16LocalFanOKVal2)
         && (u16LocalExt_rStFanC < u16LocalFanCritScVal))
      {
         CoFan_bDgoUnVld_StFanC = 1;
      }
      else
      {
         if (  (u16LocalExt_rStFanC > u16LocalFanCritScVal2)
            && (u16LocalExt_rStFanC < u16LocalFanNOKVal))
         {
            CoFan_bDgoUnVld_StFanC = 1;
         }
         else
         {
            if (  (u16LocalExt_rStFanC > u16LocalFanNOKVal2)
               && (u16LocalExt_rStFanC < 1000))
            {
               CoFan_bDgoUnVld_StFanC = 1;
            }
            else
            {
               CoFan_bDgoUnVld_StFanC = 0;
            }
         }
      }
   }
   if (  (u16LocalExt_rStFanC > u16LocalFanCritScVal)
      && (u16LocalExt_rStFanC < u16LocalFanCritScVal2))
   {
      CoFan_bDgoCritSc_StFanC = 1;
   }
   else
   {
      CoFan_bDgoCritSc_StFanC = 0;
   }
   if (CoFan_bMonRunEl_StFanC != 0)
   {
      COFANCMDDIAG_vidCritScCnt();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoHalFanC                                 */
/* !Description :  cette fonction permet de calcluler CoFan_bDgoClsdRly_StFanC*/
/*                 et CoFan_bDgoEl_StFanC.                                    */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void COFANCMDDIAG_vidDgoCohCoFanB2();                         */
/*  extf argret void COFANCMDDIAG_vidDgClsdRlyCoFanB2();                      */
/*  input uint16 Ext_rStFanC;                                                 */
/*  input boolean COFANCMDDIAG_bDgoHiDrvrFan1;                                */
/*  input boolean COFANCMDDIAG_bFaultOpen1;                                   */
/*  input boolean COFANCMDDIAG_bFaultGround1;                                 */
/*  input boolean COFANCMDDIAG_bFaultOpen2;                                   */
/*  input boolean COFANCMDDIAG_bFaultGround2;                                 */
/*  input boolean COFANCMDDIAG_bDgoHiDrvrFan2;                                */
/*  input boolean CoFan_bDgoOc_DrvrFan2;                                      */
/*  input boolean CoFan_bDgoLo_DrvrFan2;                                      */
/*  input boolean CoFan_bDgoHi_DrvrFan2;                                      */
/*  input boolean CoFan_bAcvCoFan2CmdAppld;                                   */
/*  input boolean COFANCMDDIAG_bDgoEl_DrvrFan2;                               */
/*  output boolean CoFan_bDgoHi_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoOc_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoLo_DrvrFan1;                                     */
/*  output boolean CoFan_bDgoOc_DrvrFan2;                                     */
/*  output boolean CoFan_bDgoLo_DrvrFan2;                                     */
/*  output boolean CoFan_bDgoHi_DrvrFan2;                                     */
/*  output boolean COFANCMDDIAG_bDgoEl_DrvrFan2;                              */
/*  output boolean CoFan_bDgoEl_StFanC;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoHalFanC(void)
{
   boolean bLocalCoFan_bAcvCoFan2CmdAppld;
   uint16  u16LocalExt_rStFanC;


   VEMS_vidGET(Ext_rStFanC, u16LocalExt_rStFanC);
   CoFan_bDgoHi_DrvrFan1 = COFANCMDDIAG_bDgoHiDrvrFan1;
   if (  (COFANCMDDIAG_bFaultOpen1 != 0)
      || (COFANCMDDIAG_bFaultGround1 != 0))
   {
      CoFan_bDgoOc_DrvrFan1 = 1;
      CoFan_bDgoLo_DrvrFan1 = 1;
   }
   else
   {
      CoFan_bDgoOc_DrvrFan1 = 0;
      CoFan_bDgoLo_DrvrFan1 = 0;
   }
   if (  (COFANCMDDIAG_bFaultOpen2 != 0)
      || (COFANCMDDIAG_bFaultGround2 != 0))
   {
      if (u16LocalExt_rStFanC == 1000)
      {
         CoFan_bDgoOc_DrvrFan2 = 1;
         CoFan_bDgoLo_DrvrFan2 = 0;
      }
      else
      {
         CoFan_bDgoOc_DrvrFan2 = 0;
         CoFan_bDgoLo_DrvrFan2 = 1;
      }
   }
   else
   {
      CoFan_bDgoOc_DrvrFan2 = 0;
      CoFan_bDgoLo_DrvrFan2 = 0;
   }
   CoFan_bDgoHi_DrvrFan2 = COFANCMDDIAG_bDgoHiDrvrFan2;
   if (  (CoFan_bDgoOc_DrvrFan2 != 0)
      || (CoFan_bDgoLo_DrvrFan2 != 0)
      || (CoFan_bDgoHi_DrvrFan2 != 0))
   {
      COFANCMDDIAG_bDgoEl_DrvrFan2 = 1;
   }
   else
   {
      COFANCMDDIAG_bDgoEl_DrvrFan2 = 0;
   }
   VEMS_vidGET(CoFan_bAcvCoFan2CmdAppld, bLocalCoFan_bAcvCoFan2CmdAppld);
   if (bLocalCoFan_bAcvCoFan2CmdAppld != 0)
   {
      COFANCMDDIAG_vidDgoCohCoFanB2();
   }
   else
   {
      if (COFANCMDDIAG_bDgoEl_DrvrFan2 == 0)
      {
         COFANCMDDIAG_vidDgClsdRlyCoFanB2();
      }
      if (u16LocalExt_rStFanC == 0)
      {
         CoFan_bDgoEl_StFanC = 1;
      }
      else
      {
         CoFan_bDgoEl_StFanC = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgClsdRlyCoFanB2                           */
/* !Description :  Relais CCA collé fermé                                     */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rStFanC;                                                 */
/*  output boolean CoFan_bDgoClsdRly_StFanC;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgClsdRlyCoFanB2(void)
{
   uint16  u16LocalExt_rStFanC;


   VEMS_vidGET(Ext_rStFanC, u16LocalExt_rStFanC);
   if (u16LocalExt_rStFanC != 1000)
   {
      CoFan_bDgoClsdRly_StFanC = 1;
   }
   else
   {
      CoFan_bDgoClsdRly_StFanC = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDgoCohCoFanB2                              */
/* !Description :  Fonction qui permet de calculer CoFan_bDgoEl_StFanC.       */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_rStFanC;                                                 */
/*  input boolean COFANCMDDIAG_bDgoEl_DrvrFan2;                               */
/*  output boolean CoFan_bDgoEl_StFanC;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDgoCohCoFanB2(void)
{
   uint16  u16LocalExt_rStFanC;


   VEMS_vidGET(Ext_rStFanC, u16LocalExt_rStFanC);
   if (  (u16LocalExt_rStFanC == 0)
      || (  (u16LocalExt_rStFanC == 1000)
         && (COFANCMDDIAG_bDgoEl_DrvrFan2 == 0)))
   {
      CoFan_bDgoEl_StFanC = 1;
   }
   else
   {
      CoFan_bDgoEl_StFanC = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidECIDgo                                     */
/* !Description :  Cette fonction gére le diagnostic ECI de la commande GMV.  */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoFan_rFanNOKVal_C;                                           */
/*  input uint8 CoFan_rFanTolRngVal_C;                                        */
/*  input uint8 CoFan_rFanOKVal_C;                                            */
/*  input uint16 Ext_rStFanC;                                                 */
/*  input boolean CoFan_bDgoECI_StFanC;                                       */
/*  output boolean CoFan_bDgoECI_StFanC;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidECIDgo(void)
{
   sint16 s16LocalFanNOKVal;
   sint16 s16LocalFanOKVal;
   uint16 u16LocalFanNOKVal;
   uint16 u16LocalFanOKVal;
   uint16 u16LocalFanOKVal2;
   uint16 u16LocalFanNoKVal3;
   uint16 u16LocalExt_rStFanC;


   s16LocalFanNOKVal = (sint16)( ( CoFan_rFanNOKVal_C - CoFan_rFanTolRngVal_C)
                               * 10);
   u16LocalFanNOKVal = (uint16)MATHSRV_udtMAX(s16LocalFanNOKVal, 0);
   u16LocalFanNoKVal3 = (uint16)( ( CoFan_rFanNOKVal_C
                                  + CoFan_rFanTolRngVal_C)
                                * 10);
   s16LocalFanOKVal = (sint16)( (CoFan_rFanOKVal_C - CoFan_rFanTolRngVal_C)
                              * 10);
   u16LocalFanOKVal = (uint16)MATHSRV_udtMAX(s16LocalFanOKVal, 0);
   u16LocalFanOKVal2 = (uint16)( (CoFan_rFanOKVal_C + CoFan_rFanTolRngVal_C)
                               * 10);
   VEMS_vidGET(Ext_rStFanC, u16LocalExt_rStFanC);
   if (CoFan_bDgoECI_StFanC == 0)
   {
      if (  (u16LocalExt_rStFanC >= u16LocalFanNOKVal)
         && (u16LocalExt_rStFanC <= u16LocalFanNoKVal3))
      {
         CoFan_bDgoECI_StFanC = 1;
      }
   }
   else
   {
      if (  (u16LocalExt_rStFanC >= u16LocalFanOKVal)
         && (u16LocalExt_rStFanC <= u16LocalFanOKVal2))
      {
         CoFan_bDgoECI_StFanC = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidCritScCnt                                  */
/* !Description :  Cette fonction gère la stratégie spécifique de comptage de */
/*                 panne défaut CCA sur 1 DC global                           */
/* !Number      :  FCT5.9                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/* !Trace_To    :  VEMS_R_09_00032_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean COFANCMDDIAG_bStFanCPrev;                                   */
/*  input boolean CoFan_bDCDftStFanC;                                         */
/*  input uint16 CoFan_ctDftStFanC;                                           */
/*  input uint8 CoFan_incCntDftFanC_C;                                        */
/*  input uint16 CoFan_noMaxThdCntDftFanC_C;                                  */
/*  input uint8 CoFan_ctRskCritScFanC;                                        */
/*  input uint8 CoFan_noThdCntRskCritScFanC_C;                                */
/*  input uint16 CoFan_noRecThdCntDftFanC_C;                                  */
/*  input boolean COFANCMDDIAG_bNoMaxThdPrev;                                 */
/*  input boolean COFANCMDDIAG_bNoRecThdPrev;                                 */
/*  input uint8 CoFan_incCntRskCritScFanC_C;                                  */
/*  input boolean COFANCMDDIAG_bNoThdPrev;                                    */
/*  input uint8 CoFan_ctCritScFanC;                                           */
/*  input uint8 CoFan_incCntCritScFanC_C;                                     */
/*  input uint8 CoFan_noThdCntCritScFanC_C;                                   */
/*  output boolean CoFan_bDCDftStFanC;                                        */
/*  output boolean COFANCMDDIAG_bStFanCPrev;                                  */
/*  output uint16 CoFan_ctDftStFanC;                                          */
/*  output boolean COFANCMDDIAG_bNoMaxThdPrev;                                */
/*  output boolean COFANCMDDIAG_bNoRecThdPrev;                                */
/*  output uint8 CoFan_ctRskCritScFanC;                                       */
/*  output uint8 CoFan_ctCritScFanC;                                          */
/*  output boolean COFANCMDDIAG_bNoThdPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidCritScCnt(void)
{
   boolean bLocalStFanC;
   boolean bLocalNoMaxThd;
   boolean bLocalNoRecThd;
   boolean bLocalAcvSpcDgoStraFanC;
   uint32  u32LocalInc;
   uint16  u16LocalMin;
   sint16  s16LocalDec;
   uint16  u16LocalRskCritScFanC;
   uint16  u16LocalCritScFanC;
   uint16  u16LocalDftStFanC;

   bLocalAcvSpcDgoStraFanC = GDGAR_bGetFRM(FRM_FRM_ACVSPCDGOSTRAFANC);
   if (bLocalAcvSpcDgoStraFanC != 0)
   {
      if (COFANCMDDIAG_bStFanCPrev == 0)
      {
         if (CoFan_bDCDftStFanC == 0)
         {
            bLocalStFanC = 1;
         }
         else
         {
            bLocalStFanC = 0;
         }
         CoFan_bDCDftStFanC = 1;
      }
      else
      {
         bLocalStFanC = 0;
      }
      COFANCMDDIAG_bStFanCPrev = 1;
      u32LocalInc = (uint32)(CoFan_ctDftStFanC + CoFan_incCntDftFanC_C);
      u16LocalDftStFanC = (uint16)MATHSRV_udtMIN(u32LocalInc,
                                                 CoFan_noMaxThdCntDftFanC_C);
   }
   else
   {
      bLocalStFanC = 0;
      COFANCMDDIAG_bStFanCPrev = 0;
      s16LocalDec = (sint16)(CoFan_ctDftStFanC - CoFan_incCntDftFanC_C);
      u16LocalMin = (uint16)MATHSRV_udtMAX(s16LocalDec, 0);
      u16LocalDftStFanC = (uint16)MATHSRV_udtMIN(u16LocalMin,
                                                 CoFan_noMaxThdCntDftFanC_C);
   }
   if (  (CoFan_ctRskCritScFanC < CoFan_noThdCntRskCritScFanC_C)
      || (  (CoFan_ctDftStFanC != CoFan_noRecThdCntDftFanC_C)
         && (CoFan_ctDftStFanC != CoFan_noMaxThdCntDftFanC_C)))
   {
      CoFan_ctDftStFanC = u16LocalDftStFanC;
   }
   if (CoFan_ctDftStFanC == CoFan_noMaxThdCntDftFanC_C)
   {
      if (COFANCMDDIAG_bNoMaxThdPrev == 0)
      {
         bLocalNoMaxThd = 1;
      }
      else
      {
         bLocalNoMaxThd = 0;
      }
      COFANCMDDIAG_bNoMaxThdPrev = 1;
   }
   else
   {
      bLocalNoMaxThd = 0;
      COFANCMDDIAG_bNoMaxThdPrev = 0;
   }
   if (CoFan_ctDftStFanC >= CoFan_noRecThdCntDftFanC_C)
   {
      if (COFANCMDDIAG_bNoRecThdPrev == 0)
      {
         bLocalNoRecThd = 1;
      }
      else
      {
         bLocalNoRecThd = 0;
      }
      COFANCMDDIAG_bNoRecThdPrev = 1;
   }
   else
   {
      bLocalNoRecThd = 0;
      COFANCMDDIAG_bNoRecThdPrev = 0;
   }

   if (  (bLocalNoMaxThd != 0)
      || (bLocalNoRecThd != 0)
      || (bLocalStFanC != 0))
   {
      u16LocalRskCritScFanC = (uint16)( CoFan_ctRskCritScFanC
                                      + CoFan_incCntRskCritScFanC_C);
      CoFan_ctRskCritScFanC =
         (uint8)MATHSRV_udtMIN(u16LocalRskCritScFanC,
                              CoFan_noThdCntRskCritScFanC_C);
   }
   else
   {
      CoFan_ctRskCritScFanC =
         (uint8)MATHSRV_udtMIN(CoFan_ctRskCritScFanC,
                               CoFan_noThdCntRskCritScFanC_C);
   }
   if (CoFan_ctRskCritScFanC == CoFan_noThdCntRskCritScFanC_C)
   {
      if (COFANCMDDIAG_bNoThdPrev == 0)
      {
         u16LocalCritScFanC = (uint16)(CoFan_ctCritScFanC
                                      + CoFan_incCntCritScFanC_C);
         CoFan_ctCritScFanC =
            (uint8)MATHSRV_udtMIN(u16LocalCritScFanC,
                                  CoFan_noThdCntCritScFanC_C);
      }
      else
      {
         CoFan_ctCritScFanC =
            (uint8)MATHSRV_udtMIN(CoFan_ctCritScFanC,
                                  CoFan_noThdCntCritScFanC_C);
      }
      COFANCMDDIAG_bNoThdPrev = 1;
   }
   else
   {
      COFANCMDDIAG_bNoThdPrev = 0;
      CoFan_ctCritScFanC =
         (uint8)MATHSRV_udtMIN(CoFan_ctCritScFanC,
                               CoFan_noThdCntCritScFanC_C);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  COFANCMDDIAG_vidDiagBMonRun                                */
/* !Description :  Cette fonction gère l’ensemble des diagnostics GMV pour les*/
/*                 3 équipements.                                             */
/* !Number      :  FCT5.10                                                    */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Dena_oc_driver_GMV1;                                        */
/*  input boolean Dena_scg_driver_GMV1;                                       */
/*  input boolean Dena_scp_driver_GMV1;                                       */
/*  input boolean Dena_oc_driver_GMV2;                                        */
/*  input boolean Dena_scg_driver_GMV2;                                       */
/*  input boolean Dena_scp_driver_GMV2;                                       */
/*  input boolean Dft_oc_driver_GMV1;                                         */
/*  input boolean Dft_scg_driver_GMV1;                                        */
/*  input boolean Dft_scp_driver_GMV1;                                        */
/*  input boolean Dft_oc_driver_GMV2;                                         */
/*  input boolean Dft_scg_driver_GMV2;                                        */
/*  input boolean Dft_scp_driver_GMV2;                                        */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer2;                              */
/*  input boolean COFANCMDDIAG_bMonRunCoh_StFanB2;                            */
/*  input uint16 Tension_batterie;                                            */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer3;                              */
/*  input uint16 CoFan_noMinVoltThdB2_C;                                      */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer4;                              */
/*  input boolean COFANCMDDIAG_bMonRunCoh_B2NoSpd;                            */
/*  input uint8 COFANCMDDIAG_u8LocalcountTimer5;                              */
/*  input boolean COFANCMDDIAG_bMonRunCoh_StFanB1;                            */
/*  output boolean CoFan_bMonRunClsdRly_StFanC;                               */
/*  output boolean CoFan_bMonRunHi_DrvrFan2;                                  */
/*  output boolean COFANCMDDIAG_bDgoHiDrvrFan2;                               */
/*  output boolean CoFan_bMonRunOc_DrvrFan2;                                  */
/*  output boolean COFANCMDDIAG_bFaultOpen2;                                  */
/*  output boolean CoFan_bMonRunLo_DrvrFan2;                                  */
/*  output boolean COFANCMDDIAG_bFaultGround2;                                */
/*  output boolean CoFan_bMonRunHi_DrvrFan1;                                  */
/*  output boolean COFANCMDDIAG_bDgoHiDrvrFan1;                               */
/*  output boolean CoFan_bMonRunOc_DrvrFan1;                                  */
/*  output boolean COFANCMDDIAG_bFaultOpen1;                                  */
/*  output boolean CoFan_bMonRunLo_DrvrFan1;                                  */
/*  output boolean COFANCMDDIAG_bFaultGround1;                                */
/*  output boolean CoFan_bMonRunCoh_StFanB2HiSpd;                             */
/*  output boolean CoFan_bMonRunCoh_StFanB2LoSpd;                             */
/*  output boolean CoFan_bMonRunCoh_StFanB2NoSpd;                             */
/*  output boolean CoFan_bMonRunCoh_StFanB1;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void COFANCMDDIAG_vidDiagBMonRun(void)
{
   boolean bLocalDenaOcDriverGMV1;
   boolean bLocalDenaScgDriverGMV1;
   boolean bLocalDenaScpDriverGMV1;
   boolean bLocalDenaOcDriverGMV2;
   boolean bLocalDenaScgDriverGMV2;
   boolean bLocalDenaScpDriverGMV2;
   boolean bLocalDftOcDriverGMV1;
   boolean bLocalDftScgDriverGMV1;
   boolean bLocalDftScpDriverGMV1;
   boolean bLocalDftOcDriverGMV2;
   boolean bLocalDftScgDriverGMV2;
   boolean bLocalDftScpDriverGMV2;
   uint16  u16LocalTensionbatterie;


   VEMS_vidGET(Dena_oc_driver_GMV1, bLocalDenaOcDriverGMV1);
   VEMS_vidGET(Dena_scg_driver_GMV1, bLocalDenaScgDriverGMV1);
   VEMS_vidGET(Dena_scp_driver_GMV1, bLocalDenaScpDriverGMV1);
   VEMS_vidGET(Dena_oc_driver_GMV2, bLocalDenaOcDriverGMV2);
   VEMS_vidGET(Dena_scg_driver_GMV2, bLocalDenaScgDriverGMV2);
   VEMS_vidGET(Dena_scp_driver_GMV2, bLocalDenaScpDriverGMV2);
   VEMS_vidGET(Dft_oc_driver_GMV1, bLocalDftOcDriverGMV1);
   VEMS_vidGET(Dft_scg_driver_GMV1, bLocalDftScgDriverGMV1);
   VEMS_vidGET(Dft_scp_driver_GMV1, bLocalDftScpDriverGMV1);
   VEMS_vidGET(Dft_oc_driver_GMV2, bLocalDftOcDriverGMV2);
   VEMS_vidGET(Dft_scg_driver_GMV2, bLocalDftScgDriverGMV2);
   VEMS_vidGET(Dft_scp_driver_GMV2, bLocalDftScpDriverGMV2);

   if (COFANCMDDIAG_u8LocalcountTimer2 == 0)
   {
      CoFan_bMonRunClsdRly_StFanC = 1;
   }
   else
   {
      CoFan_bMonRunClsdRly_StFanC = 0;
   }

   if (bLocalDenaScpDriverGMV2 != 0)
   {
      CoFan_bMonRunHi_DrvrFan2 = 1;
      if (bLocalDftScpDriverGMV2 != 0)
      {
         COFANCMDDIAG_bDgoHiDrvrFan2 = 1;
      }
      else
      {
         COFANCMDDIAG_bDgoHiDrvrFan2 = 0;
      }
   }
   else
   {
      CoFan_bMonRunHi_DrvrFan2 = 0;
      COFANCMDDIAG_bDgoHiDrvrFan2 = 0;
   }

   if (bLocalDenaOcDriverGMV2 != 0)
   {
      CoFan_bMonRunOc_DrvrFan2 = 1;
      if (bLocalDftOcDriverGMV2 != 0)
      {
         COFANCMDDIAG_bFaultOpen2 = 1;
      }
      else
      {
         COFANCMDDIAG_bFaultOpen2 = 0;
      }
   }
   else
   {
      CoFan_bMonRunOc_DrvrFan2 = 0;
      COFANCMDDIAG_bFaultOpen2 = 0;
   }

   if (bLocalDenaScgDriverGMV2 != 0)
   {
      CoFan_bMonRunLo_DrvrFan2 = 1;
      if (bLocalDftScgDriverGMV2 != 0)
      {
         COFANCMDDIAG_bFaultGround2 = 1;
      }
      else
      {
         COFANCMDDIAG_bFaultGround2 = 0;
      }
   }
   else
   {
      CoFan_bMonRunLo_DrvrFan2 = 0;
      COFANCMDDIAG_bFaultGround2 = 0;
   }

   if (bLocalDenaScpDriverGMV1 != 0)
   {
      CoFan_bMonRunHi_DrvrFan1 = 1;
      if (bLocalDftScpDriverGMV1 != 0)
      {
         COFANCMDDIAG_bDgoHiDrvrFan1 = 1;
      }
      else
      {
         COFANCMDDIAG_bDgoHiDrvrFan1 = 0;
      }
   }
   else
   {
      CoFan_bMonRunHi_DrvrFan1 = 0;
      COFANCMDDIAG_bDgoHiDrvrFan1 = 0;
   }

   if (bLocalDenaOcDriverGMV1 != 0)
   {
      CoFan_bMonRunOc_DrvrFan1 = 1;
      if (bLocalDftOcDriverGMV1 != 0)
      {
         COFANCMDDIAG_bFaultOpen1 = 1;
      }
      else
      {
         COFANCMDDIAG_bFaultOpen1 = 0;
      }
   }
   else
   {
      CoFan_bMonRunOc_DrvrFan1 = 0;
      COFANCMDDIAG_bFaultOpen1 = 0;
   }

   if (bLocalDenaScgDriverGMV1 != 0)
   {
      CoFan_bMonRunLo_DrvrFan1 = 1;
      if (bLocalDftScgDriverGMV1 != 0)
      {
         COFANCMDDIAG_bFaultGround1 = 1;
      }
      else
      {
         COFANCMDDIAG_bFaultGround1 = 0;
      }
   }
   else
   {
      CoFan_bMonRunLo_DrvrFan1 = 0;
      COFANCMDDIAG_bFaultGround1 = 0;
   }

   if (COFANCMDDIAG_bMonRunCoh_StFanB2 != 0)
   {
      CoFan_bMonRunCoh_StFanB2HiSpd = 1;
      VEMS_vidGET(Tension_batterie, u16LocalTensionbatterie);
      if (  (COFANCMDDIAG_u8LocalcountTimer3 == 0)
         && (u16LocalTensionbatterie >= CoFan_noMinVoltThdB2_C))
      {
         CoFan_bMonRunCoh_StFanB2LoSpd = 1;
      }
      else
      {
         CoFan_bMonRunCoh_StFanB2LoSpd = 0;
      }
      if (  (COFANCMDDIAG_u8LocalcountTimer4 == 0)
         && (COFANCMDDIAG_bMonRunCoh_B2NoSpd != 0))
      {
         CoFan_bMonRunCoh_StFanB2NoSpd = 1;
      }
      else
      {
         CoFan_bMonRunCoh_StFanB2NoSpd = 0;
      }
   }
   else
   {
      CoFan_bMonRunCoh_StFanB2HiSpd = 0;
      CoFan_bMonRunCoh_StFanB2NoSpd = 0;
      CoFan_bMonRunCoh_StFanB2LoSpd = 0;
   }
   if (  (COFANCMDDIAG_u8LocalcountTimer5 == 0)
      && (COFANCMDDIAG_bMonRunCoh_StFanB1 != 0))
   {
      CoFan_bMonRunCoh_StFanB1 = 1;
   }
   else
   {
      CoFan_bMonRunCoh_StFanB1 = 0;
   }
}
/*----------------------------------end of file-------------------------------*/