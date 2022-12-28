/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILPROPPRESACQ                                          */
/* !Description     : OILPROPPRESACQ Component                                */
/*                                                                            */
/* !Module          : OILPROPPRESACQ                                          */
/* !Description     : OIL PROPORTIONAL PRESSURE ACQUISITION AND DIAGNOSIS     */
/*                                                                            */
/* !File            : OILPROPPRESACQ_FCT1.C                                   */
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
/*   1 / OILPROPPRESACQ_vidInitOutput                                         */
/*   2 / OILPROPPRESACQ_vidInitialization                                     */
/*   3 / OILPROPPRESACQ_vidOilSdlFastEna                                      */
/*   4 / OILPROPPRESACQ_vidOilAcqCond                                         */
/*   5 / OILPROPPRESACQ_vidOilPressDiag                                       */
/*   6 / OILPROPPRESACQ_vidOilPressTreat                                      */
/*   7 / OILPROPPRESACQ_vidOilPresMesAcq                                      */
/*   8 / OILPROPPRESACQ_vidOilPresFilter                                      */
/*   9 / OILPROPPRESACQ_vidOilPresInfoAcq                                     */
/*   10 / OILPROPPRESACQ_vidOilDiag                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6978050 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OIL/OILPROPPRESACQ/OILPROPPRESAC$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   20 Oct 2014 $*/
/* $Author::   mbenfrad                               $$Date::   20 Oct 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "OILPROPPRESACQ.h"
#include "OILPROPPRESACQ_L.h"
#include "OILPROPPRESACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidInitOutput                               */
/* !Description :  Output's initialization                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Ext_pOilMesRaw;                                             */
/*  output uint16 Ext_pOilMesPrev;                                            */
/*  output boolean OILPROPPRESACQ_bAcqCondHystOut;                            */
/*  output boolean OILPROPPRESACQ_bHystOutput;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidInitOutput(void)
{
   /*F01_OilPresMesAcq*/
   VEMS_vidSET(Ext_pOilMesRaw, 0);

   /*Other variables*/
   Ext_pOilMesPrev = 0;
   OILPROPPRESACQ_bAcqCondHystOut = 0;
   OILPROPPRESACQ_bHystOutput = 0;

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidInitialization                           */
/* !Description :  The Output variable Ext_pOilMes is initialized with zero at*/
/*                 event reset.                                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Oil_Pres_alertProp;                                        */
/*  output boolean Ext_bOilPresProp;                                          */
/*  output uint16 Ext_pOilMesSI;                                              */
/*  output uint16 Ext_pOilMes;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidInitialization(void)
{
   VEMS_vidSET(Oil_Pres_alertProp, 0);
   VEMS_vidSET(Ext_bOilPresProp, 0);
   VEMS_vidSET(Ext_pOilMesSI, 0);
   VEMS_vidSET(Ext_pOilMes, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilSdlFastEna                            */
/* !Description :  Fonction d'activation de l'événement                       */
/*                 Oil_SdlFast_OilPropPresAcq                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void OILPROPPRESACQ_vidOilPresAcqMean();                      */
/*  extf argret void OILPROPPRESACQ_vidOilPresFilter();                       */
/*  extf argret void OILPROPPRESACQ_vidOilPressDiag();                        */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void OILPROPPRESACQ_vidOilPressTreat();                       */
/*  input boolean Oil_bAcvOilPresAcq;                                         */
/*  input boolean Oil_bAcvCkOilPresAcq;                                       */
/*  input boolean Ext_bDgoScp_pOilMes;                                        */
/*  input boolean Ext_bMonRunScp_pOilMes;                                     */
/*  input boolean Ext_bDgoScg_pOilMes;                                        */
/*  input boolean Ext_bMonRunScg_pOilMes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilSdlFastEna(void)
{
   boolean bLocalOil_bAcvCkOilPresAcq;


   if (Oil_bAcvOilPresAcq != 0)
   {
      VEMS_vidGET(Oil_bAcvCkOilPresAcq, bLocalOil_bAcvCkOilPresAcq);
      if (bLocalOil_bAcvCkOilPresAcq == 0)
      {
         OILPROPPRESACQ_vidOilPresAcqMean();
      }
      OILPROPPRESACQ_vidOilPresFilter();
      OILPROPPRESACQ_vidOilPressDiag();
      GDGAR_vidGdu(GD_DFT_SCP_POILMES,
                   Ext_bDgoScp_pOilMes,
                   Ext_bMonRunScp_pOilMes,
                   DIAG_DISPO);
      GDGAR_vidGdu(GD_DFT_SCG_POILMES,
                  Ext_bDgoScg_pOilMes,
                  Ext_bMonRunScg_pOilMes,
                  DIAG_DISPO);
      OILPROPPRESACQ_vidOilPressTreat();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilAcqCond                               */
/* !Description :  This function gives different conditions to activate oil   */
/*                 pressure acquisition.                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ctrl_bOilPropPresAcq;                                       */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_nEngOilPresAcqLoThd_C;                                   */
/*  input uint16 Ext_nEngOilPresAcqHiThd_C;                                   */
/*  input boolean OILPROPPRESACQ_bAcqCondHystOut;                             */
/*  output boolean Oil_bAcvOilPresAcq;                                        */
/*  output boolean Oil_bAcvCkOilPresAcq;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilAcqCond(void)
{
   boolean bLocalCtrl_bOilPropPresAcq;
   uint16  u16LocalExt_nEng;


   VEMS_vidGET(Ctrl_bOilPropPresAcq, bLocalCtrl_bOilPropPresAcq);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   /*** Hysteresis Block  ***/
   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                Ext_nEngOilPresAcqLoThd_C,
                                Ext_nEngOilPresAcqHiThd_C,
                                MATHSRV_RISING_SCHMITT_TRIGGER,
                                &OILPROPPRESACQ_bAcqCondHystOut);

   Oil_bAcvOilPresAcq = bLocalCtrl_bOilPropPresAcq;

   if (  (bLocalCtrl_bOilPropPresAcq != 0)
      && (OILPROPPRESACQ_bAcqCondHystOut != 0))
   {
      VEMS_vidSET(Oil_bAcvCkOilPresAcq, 1);
   }
   else
   {
      VEMS_vidSET(Oil_bAcvCkOilPresAcq, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilPressDiag                             */
/* !Description :  The diagnosis is authorized if there is no electrical      */
/*                 failure on the sensor.                                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_03195_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void OILPROPPRESACQ_vidOilDiag();                             */
/*  output boolean Ext_bMonRunScp_pOilMes;                                    */
/*  output boolean Ext_bMonRunScg_pOilMes;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilPressDiag(void)
{
   boolean bLocalInhElDiagpOilMes;


   bLocalInhElDiagpOilMes = GDGAR_bGetFRM(FRM_FRM_INHELDIAGPOILMES);
   if (bLocalInhElDiagpOilMes == 0)
   {
      Ext_bMonRunScp_pOilMes = 1;
      Ext_bMonRunScg_pOilMes = 1;
      OILPROPPRESACQ_vidOilDiag();
   }
   else
   {
      Ext_bMonRunScp_pOilMes = 0;
      Ext_bMonRunScg_pOilMes = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilPressTreat                            */
/* !Description :  Treatment and detection of the oil pressure sensor.        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_03195_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILPROPPRESACQ_vidOilPresMesAcq();                       */
/*  extf argret void OILPROPPRESACQ_vidOilPresInfoAcq();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilPressTreat(void)
{
   OILPROPPRESACQ_vidOilPresMesAcq();
   OILPROPPRESACQ_vidOilPresInfoAcq();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilPresMesAcq                            */
/* !Description :  The oil pressure after treatement is calculated in the 3   */
/*                 cases : When there is no electrical faults concerning the  */
/*                 oil pressure sensor,If an electrical fault was detected and*/
/*                 If a fault was confirmed.                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_E_10_03195_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 Oil_pOilPresAcq_uOilMes_A[2];                                */
/*  input uint16 Oil_upOilMesLnr_T[2];                                        */
/*  input uint16 Oil_upOilMesAct;                                             */
/*  input uint16 Oil_pOilMesDft_C;                                            */
/*  input boolean Ext_bDgoScg_pOilMes;                                        */
/*  input boolean Ext_bDgoScp_pOilMes;                                        */
/*  input uint16 Ext_pOilMesPrev;                                             */
/*  input uint16 Ext_pOilMesRaw_bornee;                                       */
/*  output uint16 Ext_pOilMesRaw;                                             */
/*  output uint16 Ext_pOilMesRaw_bornee;                                      */
/*  output uint16 Ext_pOilMesSI;                                              */
/*  output uint16 Ext_pOilMes;                                                */
/*  output uint16 Ext_pOilMesPrev;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilPresMesAcq(void)
{
   boolean bLocalAcvDftMod_pOilMes;
   boolean bLocalInhElDiagpOilMes;
   uint16  u16LocalExt_pOilMesSI;
   uint16  u16LocalExt_pOilMes;
   uint16  u16LocalExt_pOilMesRaw;
   uint16  u16LocalBKPTSup;
   uint16  u16LocalBKPTInf;
   uint16  u16LocalMapSup;
   uint16  u16LocalMapInf;
   uint16  u16LocalInterpolation;
   uint16  u16LocalSiteInterpolation;
   uint16  u16Local;
   uint32  u32LocalDeltaValue;
   uint32  u32LocalInterpolation;
   sint32  s32LocalInterpolation;


   /*Interpolation calculation*/
   if (Oil_pOilPresAcq_uOilMes_A[1] >= Oil_pOilPresAcq_uOilMes_A[0])
   {
      u16LocalBKPTSup = Oil_pOilPresAcq_uOilMes_A[1];
      u16LocalBKPTInf = Oil_pOilPresAcq_uOilMes_A[0];
      u16LocalMapSup = Oil_upOilMesLnr_T[1];
      u16LocalMapInf = Oil_upOilMesLnr_T[0];
   }
   else
   {
      u16LocalBKPTSup = Oil_pOilPresAcq_uOilMes_A[0];
      u16LocalBKPTInf = Oil_pOilPresAcq_uOilMes_A[1];
      u16LocalMapSup = Oil_upOilMesLnr_T[0];
      u16LocalMapInf = Oil_upOilMesLnr_T[1];
   }
   if (Oil_pOilPresAcq_uOilMes_A[1] != Oil_pOilPresAcq_uOilMes_A[0])
   {
      if (Oil_upOilMesAct >= u16LocalBKPTSup)
      {
         u16LocalExt_pOilMesRaw = u16LocalMapSup;
      }
      else
      {
         if (Oil_upOilMesAct < u16LocalBKPTInf)
         {
            u16LocalExt_pOilMesRaw = u16LocalMapInf;
         }
         else
         {
            /* Calculate the "Para" value of Oil_upOilMesAct with
               Oil_upOilMesLnr_T */
            u32LocalDeltaValue =
               (uint32)MATHSRV_udtABS( Oil_upOilMesAct
                                     - Oil_pOilPresAcq_uOilMes_A[0]);
            u32LocalDeltaValue = u32LocalDeltaValue << 16;
            u16LocalInterpolation = (uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
            u16LocalSiteInterpolation =
               (uint16)(u32LocalDeltaValue / u16LocalInterpolation);

            /* Calculate the interpolation value on Oil_upOilMesLnr_T */
            s32LocalInterpolation = (sint32)Oil_upOilMesLnr_T[1]
                                  - (sint32)Oil_upOilMesLnr_T[0];
            u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
            if (s32LocalInterpolation > 0)
            {
               u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
               s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            }
            else
            {
               u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
               s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
               s32LocalInterpolation = ((-1) * s32LocalInterpolation);
            }
            u16LocalExt_pOilMesRaw =
               (uint16)((sint32)Oil_upOilMesLnr_T[0] + s32LocalInterpolation);
         }
      }
   }
   else
   {
      u16LocalExt_pOilMesRaw = Oil_upOilMesLnr_T[0];
   }
   VEMS_vidSET(Ext_pOilMesRaw, u16LocalExt_pOilMesRaw);

   Ext_pOilMesRaw_bornee =
      (uint16)MATHSRV_udtCLAMP(u16LocalExt_pOilMesRaw,
                               OILPROPPRESACQ_u32OIL_PMIN_SC,
                               OILPROPPRESACQ_u32OIL_PMAX_SC);

   bLocalAcvDftMod_pOilMes = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_POILMES);

   if (bLocalAcvDftMod_pOilMes != 0)
   {
      u16LocalExt_pOilMesSI = Oil_pOilMesDft_C;
   }
   else
   {
      bLocalInhElDiagpOilMes = GDGAR_bGetFRM(FRM_FRM_INHELDIAGPOILMES);
      if (  (Ext_bDgoScg_pOilMes != 0)
         || (Ext_bDgoScp_pOilMes != 0)
         || (bLocalInhElDiagpOilMes != 0))
      {
         u16LocalExt_pOilMesSI = Ext_pOilMesPrev;
      }
      else
      {
         u16LocalExt_pOilMesSI = Ext_pOilMesRaw_bornee;
      }
   }
   u16LocalExt_pOilMes = (uint16)( ( (uint32)( u16LocalExt_pOilMesSI
                                             * 64)
                                   + 1562)
                                 / 3125);
   u16LocalExt_pOilMes = (uint16)MATHSRV_udtMIN(u16LocalExt_pOilMes, 1280);

   VEMS_vidSET(Ext_pOilMesSI, u16LocalExt_pOilMesSI);
   VEMS_vidSET(Ext_pOilMes, u16LocalExt_pOilMes);
   Ext_pOilMesPrev = u16LocalExt_pOilMesSI;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilPresFilter                            */
/* !Description :  cette fonction calcule le tension de pression d'huile.     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Oil_prm_noAcqOilPresLstSample_T[12];                          */
/*  input uint16 Ext_prm_uPresOilMesMem[12];                                  */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint16 Oil_upOilMesMean;                                            */
/*  input uint16 Ext_upOilMes;                                                */
/*  input uint16 Ext_uptOilSenPwr;                                            */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 Ext_OilCoef_nEng_A[3];                                       */
/*  input uint16 Ext_OilCoef_tOilMes_A[3];                                    */
/*  input uint8 Ext_upOilMesCoef_M[3][3];                                     */
/*  input uint8 Ext_upOilMesCoef_MP;                                          */
/*  input uint32 OILPROPPRESACQ_u32OilActFilMEM;                              */
/*  output uint16 Oil_upOilMesMean;                                           */
/*  output uint8 Ext_upOilMesCoef_MP;                                         */
/*  output uint32 OILPROPPRESACQ_u32OilActFilMEM;                             */
/*  output uint16 Oil_upOilMesAct;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilPresFilter(void)
{
   boolean bLocalCoPTSt_bEngRun;
   uint8   u8LocalIndex;
   uint8   u8LocalInterp2d;
   uint8   u8LocalFilterGain;
   uint16  u16LocalOil_upOilMesAct;
   uint16  u16LocalExt_uptOilSenPwr;
   uint16  u16LocalExt_tOilMes;
   uint16  u16LocalPara_nEngdX;
   uint16  u16LocalPara_tOilMesY;
   uint16  u16LocalFilterMem;
   uint16  u16LocalFilterOutput;
   uint16  u16LocalExt_nEng;
   uint32  u32Localsomme1;
   uint32  u32Localsomme2;
   uint32  u32LocalOil_upOilMesAct;
   uint32  u32LocalOil_upOilMesMean;
   sint16  s16LocalExt_tOilMes;


   u32Localsomme1 = 0;
   u32Localsomme2 = 0;
   for (u8LocalIndex = 0; u8LocalIndex < 12 ;u8LocalIndex ++)
   {
      u32Localsomme1 = ( u32Localsomme1
                       + ( Oil_prm_noAcqOilPresLstSample_T[u8LocalIndex]
                         * Ext_prm_uPresOilMesMem[u8LocalIndex]));

      u32Localsomme2 = u32Localsomme2
                     + Oil_prm_noAcqOilPresLstSample_T[u8LocalIndex];
   }

   if (u32Localsomme2 != 0)
   {
      u32LocalOil_upOilMesMean = (u32Localsomme1 / u32Localsomme2);
      Oil_upOilMesMean = (uint16)MATHSRV_udtMIN(u32LocalOil_upOilMesMean, 4096);
   }
   else
   {
      Oil_upOilMesMean = 0;

   }

   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   if (bLocalCoPTSt_bEngRun != 0)
   {
      u16LocalOil_upOilMesAct = Oil_upOilMesMean;
   }
   else
   {
      VEMS_vidGET(Ext_upOilMes, u16LocalOil_upOilMesAct);
   }

   VEMS_vidGET(Ext_uptOilSenPwr, u16LocalExt_uptOilSenPwr);
   if (u16LocalExt_uptOilSenPwr != 0)
   {
      u32LocalOil_upOilMesAct = (uint32)( ( u16LocalOil_upOilMesAct
                                          * 4096)
                                          / u16LocalExt_uptOilSenPwr );
      u16LocalOil_upOilMesAct =
         (uint16)MATHSRV_udtMIN(u32LocalOil_upOilMesAct, 65535);
   }
   else
   {
      u16LocalOil_upOilMesAct = 65535;
   }

   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
   if (s16LocalExt_tOilMes <= -500)
   {
      u16LocalExt_tOilMes = 0;
   }
   else
   {
      u16LocalExt_tOilMes = (uint16)(s16LocalExt_tOilMes + 500);
   }

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   u16LocalPara_nEngdX = MATHSRV_u16CalcParaIncAryU16(Ext_OilCoef_nEng_A,
                                                      u16LocalExt_nEng,
                                                      3);

   u16LocalPara_tOilMesY = MATHSRV_u16CalcParaIncAryU16(Ext_OilCoef_tOilMes_A,
                                                        u16LocalExt_tOilMes,
                                                        3);

   u8LocalInterp2d = MATHSRV_u8Interp2d(&Ext_upOilMesCoef_M[0][0],
                                        u16LocalPara_nEngdX,
                                        u16LocalPara_tOilMesY,
                                        3);
   Ext_upOilMesCoef_MP = (uint8)MATHSRV_udtMIN(u8LocalInterp2d, 100);

   if (Ext_upOilMesCoef_MP == 100)
   {
      u16LocalFilterOutput = u16LocalOil_upOilMesAct;
      u16LocalFilterMem = (uint16)MATHSRV_udtMIN(u16LocalOil_upOilMesAct, 4096);
      OILPROPPRESACQ_u32OilActFilMEM = (uint32)(u16LocalFilterMem * 256);
   }
   else
   {
      u8LocalFilterGain = (uint8)((Ext_upOilMesCoef_MP * 64) / 25);
      u16LocalFilterOutput =
         MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                        &OILPROPPRESACQ_u32OilActFilMEM,
                                        u16LocalOil_upOilMesAct);
   }
   Oil_upOilMesAct = (uint16)MATHSRV_udtMIN(u16LocalFilterOutput, 4096);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilPresInfoAcq                           */
/* !Description :  The normalized ADC output voltage is converted into        */
/*                 pressure using the table Oil_upOilMesLnr_T and clamped     */
/*                 between Oil_pMin_SC and Oil_pMax_SCto produce              */
/*                 Ext_pOilMesRaw_bornee.                                     */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input uint16 Ext_pOilMesSI;                                               */
/*  input uint16 Ext_noOilPresDetecLoThd_C;                                   */
/*  input uint16 Ext_noOilPresDetecDeltThd_C;                                 */
/*  input boolean OILPROPPRESACQ_bHystOutput;                                 */
/*  input boolean Oil_pres_alertTypProp_C;                                    */
/*  output boolean OILPROPPRESACQ_bHystOutput;                                */
/*  output boolean Ext_bRawOilPresProp;                                       */
/*  output boolean Ext_bOilPresProp;                                          */
/*  output boolean Oil_Pres_alertProp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilPresInfoAcq(void)
{
   boolean bLocalAcvDftValOilPresAcq;
   uint16  u16LocalExt_pOilMesSI;
   uint32  u32Local_Somme;


   VEMS_vidGET(Ext_pOilMesSI, u16LocalExt_pOilMesSI);
   u32Local_Somme = (uint32)( Ext_noOilPresDetecLoThd_C
                            + Ext_noOilPresDetecDeltThd_C);
   if (u16LocalExt_pOilMesSI >= u32Local_Somme)
   {
      OILPROPPRESACQ_bHystOutput = 1;
   }
   else
   {
      if (u16LocalExt_pOilMesSI <= Ext_noOilPresDetecLoThd_C)
      {
         OILPROPPRESACQ_bHystOutput = 0;
      }
   }
   VEMS_vidSET(Ext_bRawOilPresProp, OILPROPPRESACQ_bHystOutput);

   bLocalAcvDftValOilPresAcq = GDGAR_bGetFRM(FRM_FRM_ACVDFTVALOILPRESACQPROP);
   if (bLocalAcvDftValOilPresAcq != 0)
   {
      VEMS_vidSET(Ext_bOilPresProp, 0);
   }
   else
   {
      VEMS_vidSET(Ext_bOilPresProp, OILPROPPRESACQ_bHystOutput);
   }

   if (Oil_pres_alertTypProp_C != 0)
   {
      VEMS_vidSET(Oil_Pres_alertProp, OILPROPPRESACQ_bHystOutput);
   }
   else
   {
      if(OILPROPPRESACQ_bHystOutput != 0)
      {
         VEMS_vidSET(Oil_Pres_alertProp, 0);
      }
      else
      {
         VEMS_vidSET(Oil_Pres_alertProp, 1);
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilDiag                                  */
/* !Description :  Electrical diagnosis on the ADC output voltage is done to  */
/*                 check for: Short circuit to ground or Short circuit to     */
/*                 supply.                                                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_03195_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Oil_bSelTypOilMesDiag_C;                                    */
/*  input uint16 Ext_upOilMes;                                                */
/*  input uint16 Oil_upOilMesMean;                                            */
/*  input uint16 Oil_uDgoScp_pOilMes_C;                                       */
/*  input uint16 Oil_uDgoScg_pOilMes_C;                                       */
/*  output boolean Ext_bDgoScp_pOilMes;                                       */
/*  output boolean Ext_bDgoScg_pOilMes;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilDiag(void)
{
   uint16  u16LocalOilPresMes;


   if (Oil_bSelTypOilMesDiag_C != 0)
   {
      VEMS_vidGET(Ext_upOilMes, u16LocalOilPresMes);
   }
   else
   {
      u16LocalOilPresMes = Oil_upOilMesMean;
   }

   if (u16LocalOilPresMes > Oil_uDgoScp_pOilMes_C)
   {
      Ext_bDgoScp_pOilMes = 1;
   }
   else
   {
      Ext_bDgoScp_pOilMes = 0;
   }

   if (u16LocalOilPresMes < Oil_uDgoScg_pOilMes_C)
   {
      Ext_bDgoScg_pOilMes = 1;
   }

   else
   {
      Ext_bDgoScg_pOilMes = 0;
   }
}
/*---------------------------- end of file -----------------------------------*/