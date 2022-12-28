/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RICHBOOST                                               */
/* !Description     : RICHBOOST component                                     */
/*                                                                            */
/* !Module          : RICHBOOST                                               */
/* !Description     : Synthese des Besoins Enrichissement Perfo GMP           */
/*                                                                            */
/* !File            : RICHBOOST_FCT2.C                                        */
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
/*   1 / RICHBOOST_vidSyn_Bes_Act_Ovboost                                     */
/*   2 / RICHBOOST_vidCond_Act_OvbPerfo                                       */
/*   3 / RICHBOOST_vidTemporisations                                          */
/*   4 / RICHBOOST_vidCondition_Reset                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 06088 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0929/2                                          */
/* !OtherRefs   : VEMS V02 ECU#050139                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/RICHBOOST/RICHBOO$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "RICHBOOST.H"
#include "RICHBOOST_L.H"
#include "RICHBOOST_IM.H"
#include "MATHSRV.H"
#include "GDGAR.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidSyn_Bes_Act_Ovboost                           */
/* !Description :  La fonction se décompose en 3 étapes : l’activation de la  */
/*                 demande sur conditions « conducteur », temporisation de    */
/*                 cette demande sur des conditions particulières de roulage  */
/*                 et coordination de la demande finale avec des conditions de*/
/*                 RESET                                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RICHBOOST_vidCond_Act_OvbPerfo();                        */
/*  extf argret void RICHBOOST_vidTemporisations();                           */
/*  extf argret void RICHBOOST_vidCondition_Reset();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidSyn_Bes_Act_Ovboost(void)
{
   /*F03_01_Condition_activation_OvbPerfo*/
   RICHBOOST_vidCond_Act_OvbPerfo();

   /*F03_02_Temporisations*/
   RICHBOOST_vidTemporisations();

   /*F03_03_Condition_Reset*/
   RICHBOOST_vidCondition_Reset();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidCond_Act_OvbPerfo                             */
/* !Description :  L’activation de la demande d’overboost/perfo est demandée  */
/*                 sur 2 conditions : la condition de couple max sans         */
/*                 overboost atteint et la condition de position pédale       */
/*                 atteinte.                                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 CoVSCtl_rAccPEng;                                            */
/*  input sint16 EngLim_tqEfcLdMaxWoutOvb;                                    */
/*  input sint16 TqLimEM_tqLimEM;                                             */
/*  input uint16 TqSys_nEngPrfMod_A[6];                                       */
/*  input uint16 TqSys_rAccPThdAuthOvb_T[6];                                  */
/*  input uint16 TqSys_rAccPHysOvbAuth_C;                                     */
/*  input uint16 TqSys_tqEfcOfsOvbAuth_T[6];                                  */
/*  input sint16 TqSys_tqHysOvbAuth_C;                                        */
/*  input boolean TqSys_bOvbAuthAccPCnd_MP;                                   */
/*  input boolean TqSys_bOvbAuthTqCnd_MP;                                     */
/*  output boolean TqSys_bOvbAuthAccPCnd_MP;                                  */
/*  output boolean TqSys_bOvbAuthTqCnd_MP;                                    */
/*  output boolean TqSys_bOvbAuthRaw;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidCond_Act_OvbPerfo(void)
{
   uint16 u16LocalPara;
   uint16 u16LocalInterp;
   uint16 u16LocalHysPos1High;
   uint16 u16LocalCoVSCtl_rAccPEng;
   uint16 u16LocalEng_nCkFil;
   sint16 s16LocalEngLim_tqEfcLdMaxWoutOvb;
   sint16 s16LocalTqLimEM_tqLimEM;
   sint32 s32LocalHysPos2High;
   sint32 s32LocalHysPosLow;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(CoVSCtl_rAccPEng, u16LocalCoVSCtl_rAccPEng);
   VEMS_vidGET(EngLim_tqEfcLdMaxWoutOvb, s16LocalEngLim_tqEfcLdMaxWoutOvb);
   VEMS_vidGET(TqLimEM_tqLimEM, s16LocalTqLimEM_tqLimEM);

   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngPrfMod_A,
                                               u16LocalEng_nCkFil,
                                               6);
   /*1st SchmittTrigger*/
   u16LocalHysPos1High = MATHSRV_u16Interp1d(TqSys_rAccPThdAuthOvb_T,
                                             u16LocalPara);

   if (u16LocalCoVSCtl_rAccPEng >= u16LocalHysPos1High)
   {
      TqSys_bOvbAuthAccPCnd_MP = 1;
   }
   else
   {
      s32LocalHysPosLow =
         (sint32)(u16LocalHysPos1High - TqSys_rAccPHysOvbAuth_C);
      if (u16LocalCoVSCtl_rAccPEng <= s32LocalHysPosLow)
      {
         TqSys_bOvbAuthAccPCnd_MP = 0;
      }
   }

   /*2nd SchmittTrigger*/
   u16LocalInterp = MATHSRV_u16Interp1d(TqSys_tqEfcOfsOvbAuth_T, u16LocalPara);
   s32LocalHysPos2High =
      (sint32)(s16LocalEngLim_tqEfcLdMaxWoutOvb - (u16LocalInterp - 32000));

   if (s16LocalTqLimEM_tqLimEM >= s32LocalHysPos2High)
   {
      TqSys_bOvbAuthTqCnd_MP = 1;
   }
   else
   {
      s32LocalHysPosLow = s32LocalHysPos2High - TqSys_tqHysOvbAuth_C;
      if (s16LocalTqLimEM_tqLimEM <= s32LocalHysPosLow)
      {
         TqSys_bOvbAuthTqCnd_MP = 0;
      }
   }

   if (   (TqSys_bOvbAuthAccPCnd_MP != 0)
      && (TqSys_bOvbAuthTqCnd_MP != 0))
   {
      TqSys_bOvbAuthRaw = 1;
   }
   else
   {
      TqSys_bOvbAuthRaw = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidTemporisations                                */
/* !Description :  La demande d’overboost/perfo est temporisée en fonction du */
/*                 régime. Mais s’il y a une demande spécifique on peut la    */
/*                 temporiser sur un autre temps spécifique. On calcule       */
/*                 également un temps de désactivation pour gérer « l’agrément*/
/*                 » en sortie du mode perfo.                                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqSys_nEngPrfMod_A[6];                                       */
/*  input uint16 TqSys_tiDlyOvbRst_T[6];                                      */
/*  input boolean TqSys_bOvbAuthRaw;                                          */
/*  input boolean RICHBOOST_bOvbAuthRawPrev;                                  */
/*  input boolean TqSys_bAcvPrfDly;                                           */
/*  input boolean TqSys_bPrfOvbAuthSel_C;                                     */
/*  input uint16 TqSys_tiDlyPrfAuthOvb_C;                                     */
/*  input uint16 TqSys_tiDlyAuthOvb_T[6];                                     */
/*  input uint16 RICHBOOST_u16OvbTurnOnDlyCntr;                               */
/*  output uint16 TqSys_tiDeacOvbReq;                                         */
/*  output uint16 RICHBOOST_u16OvbTurnOnDlyCntr;                              */
/*  output boolean TqSys_bOvbAuthCnd;                                         */
/*  output boolean RICHBOOST_bOvbAuthRawPrev;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidTemporisations(void)
{
   uint16 u16LocalTqSys_tiDeacOvbReq;
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalPara;
   uint16 u16LocalTrnOnDlyCntr;
   uint32 u32LocalTrnOnDlyCntr;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngPrfMod_A,
                                               u16LocalEng_nCkFil,
                                               6);
   u16LocalTqSys_tiDeacOvbReq = MATHSRV_u16Interp1d(TqSys_tiDlyOvbRst_T,
                                                    u16LocalPara);
   u16LocalTqSys_tiDeacOvbReq =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_tiDeacOvbReq, 1000);
   VEMS_vidSET(TqSys_tiDeacOvbReq, u16LocalTqSys_tiDeacOvbReq);

   if (TqSys_bOvbAuthRaw != 0)
   {
      if (RICHBOOST_bOvbAuthRawPrev == 0)
      {
         if (  (TqSys_bAcvPrfDly != 0)
            && (TqSys_bPrfOvbAuthSel_C != 0))
         {
            u16LocalTrnOnDlyCntr = TqSys_tiDlyPrfAuthOvb_C;
         }
         else
         {
            u16LocalTrnOnDlyCntr = MATHSRV_u16Interp1d(TqSys_tiDlyAuthOvb_T,
                                                       u16LocalPara);
         }
         u32LocalTrnOnDlyCntr = (uint32)(u16LocalTrnOnDlyCntr * 10);
         RICHBOOST_u16OvbTurnOnDlyCntr =
            (uint16)MATHSRV_udtMIN(u32LocalTrnOnDlyCntr, 65535);
      }
      else
      {
         if (RICHBOOST_u16OvbTurnOnDlyCntr > 0)
         {
            RICHBOOST_u16OvbTurnOnDlyCntr =
               (uint16)(RICHBOOST_u16OvbTurnOnDlyCntr - 1);
         }
      }

      if (RICHBOOST_u16OvbTurnOnDlyCntr == 0)
      {
         TqSys_bOvbAuthCnd = 1;
      }
      else
      {
         TqSys_bOvbAuthCnd = 0;
      }
   }
   else
   {
      TqSys_bOvbAuthCnd = 0;
   }
   RICHBOOST_bOvbAuthRawPrev = TqSys_bOvbAuthRaw;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidCondition_Reset                               */
/* !Description :  Ce bloc présente les conditions de se/reset de la fonction.*/
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bAcvVehSpdCtlLim;                                     */
/*  input boolean Ext_bInhTqSysOvb;                                           */
/*  input boolean TqSys_bAcvVehSpdCtlReg;                                     */
/*  input boolean RICHBOOST_bAcvVehSpdCtlLimPrev;                             */
/*  input uint16 TqSys_tiSpdLimDlyAuthOvb_C;                                  */
/*  input uint16 RICHBOOST_u16OvbTurnOffDlyCntr;                              */
/*  input boolean TqSys_bOvbAuthCnd;                                          */
/*  input boolean TqSys_bRstOvbSpdLimCnd_MP;                                  */
/*  output boolean TqSys_bRstOvbSpdLimCnd_MP;                                 */
/*  output uint16 RICHBOOST_u16OvbTurnOffDlyCntr;                             */
/*  output boolean TqSys_bRstOvbCnd_MP;                                       */
/*  output boolean TqSys_bAcvOvbReq;                                          */
/*  output boolean RICHBOOST_bAcvVehSpdCtlLimPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidCondition_Reset(void)
{
   boolean bLocalTqSys_bAcvVehSpdCtlLim;
   boolean bLocalExt_bInhTqSysOvb;
   boolean bLocalTqSys_bAcvVehSpdCtlReg;
   boolean bLocalInhTqSysOvb;
   uint32  u32LocalTrnOffDlyCntr;


   VEMS_vidGET(TqSys_bAcvVehSpdCtlLim, bLocalTqSys_bAcvVehSpdCtlLim);
   VEMS_vidGET(Ext_bInhTqSysOvb, bLocalExt_bInhTqSysOvb);
   VEMS_vidGET(TqSys_bAcvVehSpdCtlReg, bLocalTqSys_bAcvVehSpdCtlReg);

   if (bLocalTqSys_bAcvVehSpdCtlLim != 0)
   {
      TqSys_bRstOvbSpdLimCnd_MP = 1;
   }
   else
   {
      if (RICHBOOST_bAcvVehSpdCtlLimPrev != 0)
      {
         u32LocalTrnOffDlyCntr = (uint32)(TqSys_tiSpdLimDlyAuthOvb_C * 10);
         RICHBOOST_u16OvbTurnOffDlyCntr =
            (uint16)MATHSRV_udtMIN(u32LocalTrnOffDlyCntr, 65535);
      }
      else
      {
         if (RICHBOOST_u16OvbTurnOffDlyCntr > 0)
         {
            RICHBOOST_u16OvbTurnOffDlyCntr =
               (uint16)(RICHBOOST_u16OvbTurnOffDlyCntr - 1);
         }
      }
      if (RICHBOOST_u16OvbTurnOffDlyCntr == 0)
      {
         TqSys_bRstOvbSpdLimCnd_MP = 0;
      }
      else
      {
         TqSys_bRstOvbSpdLimCnd_MP = 1;
      }
   }

   bLocalInhTqSysOvb = GDGAR_bGetFRM(FRM_FRM_INHTQSYSOVB);

   if (  (TqSys_bOvbAuthCnd == 0)
      || (bLocalInhTqSysOvb != 0)
      || (bLocalExt_bInhTqSysOvb != 0)
      || (bLocalTqSys_bAcvVehSpdCtlReg != 0)
      || (TqSys_bRstOvbSpdLimCnd_MP != 0))
   {
      TqSys_bRstOvbCnd_MP = 1;
      VEMS_vidSET(TqSys_bAcvOvbReq, 0);
   }
   else
   {
      TqSys_bRstOvbCnd_MP = 0;
      VEMS_vidSET(TqSys_bAcvOvbReq, 1);
   }

   RICHBOOST_bAcvVehSpdCtlLimPrev = bLocalTqSys_bAcvVehSpdCtlLim ;
}

/*-------------------------------- end of file -------------------------------*/
