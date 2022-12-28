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
/* !File            : RICHBOOST_FCT1.C                                        */
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
/*   1 / RICHBOOST_vidInitOutput                                              */
/*   2 / RICHBOOST_vidDemandePerfoOverbst                                     */
/*   3 / RICHBOOST_vidSyn_Bes_Act_Enrich                                      */
/*   4 / RICHBOOST_vidCond_act_Richesse                                       */
/*   5 / RICHBOOST_vidTempo_glob_hors_LVV                                     */
/*   6 / RICHBOOST_vidSyn_tempo_bes_enrch                                     */
/*   7 / RICHBOOST_vidCond_Reset_Enrich                                       */
/*                                                                            */
/* !Reference   : V02 NT 10 06088 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0929/2                                          */
/* !OtherRefs   : VEMS V02 ECU#050139                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/RICHBOOST/RICHBOO$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
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
/* !Function    :  RICHBOOST_vidInitOutput                                    */
/* !Description :  Initialisation des sorties.                                */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean TqSys_bRichAuthAccPCnd_MP;                                 */
/*  output boolean TqSys_bRichAuthTqCnd_MP;                                   */
/*  output boolean RICHBOOST_bStrt;                                           */
/*  output uint16 RICHBOOST_u16TmrRstOut;                                     */
/*  output uint16 RICHBOOST_u16RichTurnOnDlyCntr;                             */
/*  output boolean RICHBOOST_bRichAuthRawPrev;                                */
/*  output uint16 RICHBOOST_u16RichTurnOffDlyCntr;                            */
/*  output boolean RICHBOOST_bAcvVehSpdCtlLimPrev;                            */
/*  output boolean TqSys_bAuthRich;                                           */
/*  output boolean TqSys_bOvbAuthAccPCnd_MP;                                  */
/*  output boolean TqSys_bOvbAuthTqCnd_MP;                                    */
/*  output uint16 RICHBOOST_u16OvbTurnOnDlyCntr;                              */
/*  output boolean RICHBOOST_bOvbAuthRawPrev;                                 */
/*  output uint16 TqSys_tiDeacOvbReq;                                         */
/*  output uint16 RICHBOOST_u16OvbTurnOffDlyCntr;                             */
/*  output boolean TqSys_bAcvOvbReq;                                          */
/*  output boolean TqSys_bAcvPrfDly;                                          */
/*  output boolean TqSys_bRichAuthCnd;                                        */
/*  output boolean TqSys_bOvbAuthCnd;                                         */
/*  output boolean TqSys_bRichAuthRaw;                                        */
/*  output boolean TqSys_bOvbAuthRaw;                                         */
/*  output boolean TqSys_bRstRichCnd_MP;                                      */
/*  output boolean TqSys_bRstOvbCnd_MP;                                       */
/*  output boolean TqSys_bRstRichSpdLimCnd_MP;                                */
/*  output boolean TqSys_bRstOvbSpdLimCnd_MP;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidInitOutput(void)
{
   /*F02_01_Condition_activation_Richesse*/
   TqSys_bRichAuthAccPCnd_MP = 0;
   TqSys_bRichAuthTqCnd_MP = 0;

   /*F02_02_Temporisation_globale_hors_sortie_LVV */
   RICHBOOST_bStrt = 0;
   RICHBOOST_u16TmrRstOut = 0;

   /*F02_03_Synthese_temporisation_besoin_enrichissement*/
   RICHBOOST_u16RichTurnOnDlyCntr = 0;
   RICHBOOST_bRichAuthRawPrev = 0;

   /*F02_04_Condition_Reset_Enrichissement*/
   RICHBOOST_u16RichTurnOffDlyCntr = 0;
   RICHBOOST_bAcvVehSpdCtlLimPrev = 0;
   VEMS_vidSET(TqSys_bAuthRich, 0);

   /*F03_01_Condition_activation_OvbPerfo*/
   TqSys_bOvbAuthAccPCnd_MP = 0;
   TqSys_bOvbAuthTqCnd_MP = 0;

   /*F03_02_Temporisations*/
   RICHBOOST_u16OvbTurnOnDlyCntr = 0;
   RICHBOOST_bOvbAuthRawPrev = 0;
   VEMS_vidSET(TqSys_tiDeacOvbReq, 0);

   /*F03_03_Condition_Reset*/
   RICHBOOST_u16OvbTurnOffDlyCntr = 0;
   VEMS_vidSET(TqSys_bAcvOvbReq, 0);

   /*Internals initialization*/
   TqSys_bAcvPrfDly = 0;
   TqSys_bRichAuthCnd = 0;
   TqSys_bOvbAuthCnd = 0;
   TqSys_bRichAuthRaw = 0;
   TqSys_bOvbAuthRaw = 0;
   TqSys_bRstRichCnd_MP = 0;
   TqSys_bRstOvbCnd_MP = 0;
   TqSys_bRstRichSpdLimCnd_MP = 0;
   TqSys_bRstOvbSpdLimCnd_MP = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidDemandePerfoOverbst                           */
/* !Description :  La fonction se décompose en 2 sous fonctions : une sous    */
/*                 fonction de gestion de la demande d’enrichissement et une  */
/*                 sous fonction de gestion de la demande du mode performance */
/*                 du moteur.                                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RICHBOOST_vidSyn_Bes_Act_Enrich();                       */
/*  extf argret void RICHBOOST_vidSyn_Bes_Act_Ovboost();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidDemandePerfoOverbst(void)
{
   /*F02_Synthese_Besoins_Activation_Enrichissement*/
   RICHBOOST_vidSyn_Bes_Act_Enrich();

   /*F03_Synthese_Besoins_Activation_Overboost*/
   RICHBOOST_vidSyn_Bes_Act_Ovboost();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidSyn_Bes_Act_Enrich                            */
/* !Description :  La fonction se décompose en 3 étapes: l’activation de la   */
/*                 demande sur conditions « conducteur », temporisation de    */
/*                 cette demande sur des conditions particulières de roulage  */
/*                 et coordination de la demande finale avec des conditions de*/
/*                 RESET.                                                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RICHBOOST_vidCond_act_Richesse();                        */
/*  extf argret void RICHBOOST_vidTempo_glob_hors_LVV();                      */
/*  extf argret void RICHBOOST_vidSyn_tempo_bes_enrch();                      */
/*  extf argret void RICHBOOST_vidCond_Reset_Enrich();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidSyn_Bes_Act_Enrich(void)
{
   /*F02_01_Condition_activation_Richesse*/
   RICHBOOST_vidCond_act_Richesse();

   /*F02_02_Temporisation_globale_hors_sortie_LVV*/
   RICHBOOST_vidTempo_glob_hors_LVV();

   /*F02_03_Synthese_temporisation_besoin_enrichissement*/
   RICHBOOST_vidSyn_tempo_bes_enrch();

   /*F02_04_Condition_Reset_Enrichissement*/
   RICHBOOST_vidCond_Reset_Enrich();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidCond_act_Richesse                             */
/* !Description :  L’activation de la demande d’enrichissement est demandée   */
/*                 sur 3 conditions : la  condition de couple max atteinte, la*/
/*                 condition de position pédale atteinte, la condition de     */
/*                 température d’eau atteinte.                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 CoVSCtl_rAccPEng;                                            */
/*  input sint16 EngLim_tqIdcPresUsThrMax;                                    */
/*  input sint16 TqSys_tqCkEngLimCord;                                        */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 TqSys_nEngPrfMod_A[6];                                       */
/*  input uint16 TqSys_rAccPThdAuthRich_T[6];                                 */
/*  input uint16 TqSys_rAccPHysAuthRich_C;                                    */
/*  input uint16 TqSys_tqIdcOfsAuthRich_T[6];                                 */
/*  input sint16 TqSys_tqHysRichAuth_C;                                       */
/*  input boolean TqSys_bRichAuthAccPCnd_MP;                                  */
/*  input sint16 TqSys_tCoMesAuthRich_C;                                      */
/*  input boolean TqSys_bRichAuthTqCnd_MP;                                    */
/*  output boolean TqSys_bRichAuthAccPCnd_MP;                                 */
/*  output boolean TqSys_bRichAuthTqCnd_MP;                                   */
/*  output boolean TqSys_bRichAuthRaw;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidCond_act_Richesse(void)
{
   uint16 u16LocalPara;
   uint16 u16LocalInterp;
   uint16 u16LocalHysPos1High;
   uint16 u16LocalCoVSCtl_rAccPEng;
   uint16 u16LocalEng_nCkFil;
   sint16 s16LocalEngLim_tqIdcPresUsThrMax;
   sint16 s16LocalTqSys_tqCkEngLimCord;
   sint16 s16LocalExt_tCoMes;
   sint32 s32LocalHysPos2High;
   sint32 s32LocalHysPosLow;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(CoVSCtl_rAccPEng, u16LocalCoVSCtl_rAccPEng);
   VEMS_vidGET(EngLim_tqIdcPresUsThrMax, s16LocalEngLim_tqIdcPresUsThrMax);
   VEMS_vidGET(TqSys_tqCkEngLimCord, s16LocalTqSys_tqCkEngLimCord);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngPrfMod_A,
                                               u16LocalEng_nCkFil,
                                               6);
   /*1st SchmittTrigger*/
   u16LocalHysPos1High = MATHSRV_u16Interp1d(TqSys_rAccPThdAuthRich_T,
                                             u16LocalPara);

   if (u16LocalCoVSCtl_rAccPEng >= u16LocalHysPos1High)
   {
      TqSys_bRichAuthAccPCnd_MP = 1;
   }
   else
   {
      s32LocalHysPosLow =
         (sint32)(u16LocalHysPos1High - TqSys_rAccPHysAuthRich_C);
      if (u16LocalCoVSCtl_rAccPEng <= s32LocalHysPosLow)
      {
         TqSys_bRichAuthAccPCnd_MP = 0;
      }
   }

   /*2nd SchmittTrigger*/
   u16LocalInterp = MATHSRV_u16Interp1d(TqSys_tqIdcOfsAuthRich_T, u16LocalPara);
   s32LocalHysPos2High =
      (sint32)(s16LocalEngLim_tqIdcPresUsThrMax - (u16LocalInterp - 32000));

   if (s16LocalTqSys_tqCkEngLimCord >= s32LocalHysPos2High)
   {
      TqSys_bRichAuthTqCnd_MP = 1;
   }
   else
   {
      s32LocalHysPosLow = s32LocalHysPos2High - TqSys_tqHysRichAuth_C;
      if (s16LocalTqSys_tqCkEngLimCord <= s32LocalHysPosLow)
      {
         TqSys_bRichAuthTqCnd_MP = 0;
      }
   }

   if (  (TqSys_bRichAuthAccPCnd_MP != 0)
      && (s16LocalExt_tCoMes >= TqSys_tCoMesAuthRich_C)
      && (TqSys_bRichAuthTqCnd_MP != 0))
   {
      TqSys_bRichAuthRaw = 1;
   }
   else
   {
      TqSys_bRichAuthRaw = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidTempo_glob_hors_LVV                           */
/* !Description :  Le calcul du retard à appliquer peut être spécifique pour  */
/*                 des besoins de performances.                               */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CoVSCtl_rAccPEng;                                            */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean RICHBOOST_bStrt;                                            */
/*  input uint16 TqSys_rAccPThdPrfAuthRich_C;                                 */
/*  input uint16 TqSys_nThdPrfAuthRich_C;                                     */
/*  input uint16 TqSys_rAccPThdPrfInhRich_C;                                  */
/*  input boolean TqSys_bPrfInhRich_C;                                        */
/*  input uint16 TqSys_tiPrfRtAuthRich_C;                                     */
/*  input uint16 RICHBOOST_u16TmrRstOut;                                      */
/*  output boolean RICHBOOST_bStrt;                                           */
/*  output boolean TqSys_bAcvPrfDly;                                          */
/*  output uint16 RICHBOOST_u16TmrRstOut;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidTempo_glob_hors_LVV(void)
{
   boolean bLocalStrtPrev;
   uint16  u16LocalCoVSCtl_rAccPEng;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalVeh_spdVeh;
   uint32  u32LocalTmrRstCounter;


   VEMS_vidGET(CoVSCtl_rAccPEng, u16LocalCoVSCtl_rAccPEng);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);

   /*TmrRst*/
   bLocalStrtPrev = RICHBOOST_bStrt;
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   if (  (u16LocalVeh_spdVeh == 0)
      && (u16LocalCoVSCtl_rAccPEng >= TqSys_rAccPThdPrfAuthRich_C)
      && (u16LocalEng_nCkFil >= TqSys_nThdPrfAuthRich_C))
   {
      RICHBOOST_bStrt = 1;
   }
   else
   {
      RICHBOOST_bStrt = 0;
   }

   if (  (  (u16LocalVeh_spdVeh == 0)
         && (u16LocalCoVSCtl_rAccPEng <= TqSys_rAccPThdPrfInhRich_C))
      || (TqSys_bPrfInhRich_C != 0))
   {
      TqSys_bAcvPrfDly = 0;
   }
   else
   {
      if (  (RICHBOOST_bStrt != 0)
         && (bLocalStrtPrev == 0))
      {
         u32LocalTmrRstCounter = (uint32)(TqSys_tiPrfRtAuthRich_C * 10);
         RICHBOOST_u16TmrRstOut =
            (uint16)MATHSRV_udtMIN(u32LocalTmrRstCounter, 65535);
      }
      else
      {
         if (RICHBOOST_u16TmrRstOut > 0)
         {
            RICHBOOST_u16TmrRstOut = (uint16)(RICHBOOST_u16TmrRstOut - 1);
         }
      }

      if (RICHBOOST_u16TmrRstOut > 0)
      {
         TqSys_bAcvPrfDly = 1;
      }
      else
      {
         TqSys_bAcvPrfDly = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidSyn_tempo_bes_enrch                           */
/* !Description :  La demande d’enrichissement est temporisée en fonction du  */
/*                 régime. Mais s’il y a une demande spécifique on peut la    */
/*                 temporiser sur un autre temps spécifique.                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bRichAuthRaw;                                         */
/*  input boolean RICHBOOST_bRichAuthRawPrev;                                 */
/*  input boolean TqSys_bAcvPrfDly;                                           */
/*  input boolean TqSys_bPrfRichAuthSel_C;                                    */
/*  input uint16 TqSys_tiPrfDlyAuthRich_C;                                    */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqSys_nEngPrfMod_A[6];                                       */
/*  input uint16 TqSys_tiDlyAuthRich_T[6];                                    */
/*  input uint16 RICHBOOST_u16RichTurnOnDlyCntr;                              */
/*  output uint16 RICHBOOST_u16RichTurnOnDlyCntr;                             */
/*  output boolean TqSys_bRichAuthCnd;                                        */
/*  output boolean RICHBOOST_bRichAuthRawPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidSyn_tempo_bes_enrch(void)
{
   uint16 u16LocalEng_nCkFil;
   uint16 u16LocalPara;
   uint16 u16LocalTrnOnDlyCntr;
   uint32 u32LocalTrnOnDlyCntr;


   if (TqSys_bRichAuthRaw != 0)
   {
      if (RICHBOOST_bRichAuthRawPrev == 0)
      {
         if (  (TqSys_bAcvPrfDly != 0)
            && (TqSys_bPrfRichAuthSel_C != 0))
         {
            u16LocalTrnOnDlyCntr = TqSys_tiPrfDlyAuthRich_C;
         }
         else
         {
            VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
            u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
            u16LocalPara = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngPrfMod_A,
                                                        u16LocalEng_nCkFil,
                                                        6);
            u16LocalTrnOnDlyCntr = MATHSRV_u16Interp1d(TqSys_tiDlyAuthRich_T,
                                                       u16LocalPara);
         }
         u32LocalTrnOnDlyCntr = (uint32)(u16LocalTrnOnDlyCntr * 10);
         RICHBOOST_u16RichTurnOnDlyCntr =
            (uint16)MATHSRV_udtMIN(u32LocalTrnOnDlyCntr, 65535);
      }
      else
      {
         if (RICHBOOST_u16RichTurnOnDlyCntr > 0)
         {
            RICHBOOST_u16RichTurnOnDlyCntr =
               (uint16)(RICHBOOST_u16RichTurnOnDlyCntr - 1);
         }
      }

      if (RICHBOOST_u16RichTurnOnDlyCntr == 0)
      {
         TqSys_bRichAuthCnd = 1;
      }
      else
      {
         TqSys_bRichAuthCnd = 0;
      }
   }
   else
   {
      TqSys_bRichAuthCnd = 0;
   }
   RICHBOOST_bRichAuthRawPrev = TqSys_bRichAuthRaw;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RICHBOOST_vidCond_Reset_Enrich                             */
/* !Description :  Ce bloc présente les conditions de set/reset de la         */
/*                 fonction.                                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06088_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(uint16 u16IndexFRM)boolean;                */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bAcvVehSpdCtlLim;                                     */
/*  input boolean EOM_bInhTqSysRich;                                          */
/*  input boolean TqSys_bAcvVehSpdCtlReg;                                     */
/*  input boolean RICHBOOST_bAcvVehSpdCtlLimPrev;                             */
/*  input uint16 TqSys_tiSpdLimDlyAuthRich_C;                                 */
/*  input uint16 RICHBOOST_u16RichTurnOffDlyCntr;                             */
/*  input boolean TqSys_bRichAuthCnd;                                         */
/*  input boolean TqSys_bRstRichSpdLimCnd_MP;                                 */
/*  output boolean TqSys_bRstRichSpdLimCnd_MP;                                */
/*  output uint16 RICHBOOST_u16RichTurnOffDlyCntr;                            */
/*  output boolean TqSys_bRstRichCnd_MP;                                      */
/*  output boolean TqSys_bAuthRich;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RICHBOOST_vidCond_Reset_Enrich(void)
{
   boolean bLocalTqSys_bAcvVehSpdCtlLim;
   boolean bLocalEOM_bInhTqSysRich;
   boolean bLocalTqSys_bAcvVehSpdCtlReg;
   boolean bLocalInhTqSysRich;
   uint32  u32LocalTrnOffDlyCntr;


   VEMS_vidGET(TqSys_bAcvVehSpdCtlLim, bLocalTqSys_bAcvVehSpdCtlLim);
   VEMS_vidGET(EOM_bInhTqSysRich, bLocalEOM_bInhTqSysRich);
   VEMS_vidGET(TqSys_bAcvVehSpdCtlReg, bLocalTqSys_bAcvVehSpdCtlReg);

   if (bLocalTqSys_bAcvVehSpdCtlLim != 0)
   {
      TqSys_bRstRichSpdLimCnd_MP = 1;
   }
   else
   {
      if (RICHBOOST_bAcvVehSpdCtlLimPrev != 0)
      {
         u32LocalTrnOffDlyCntr = (uint32)(TqSys_tiSpdLimDlyAuthRich_C * 10);
         RICHBOOST_u16RichTurnOffDlyCntr =
            (uint16)MATHSRV_udtMIN(u32LocalTrnOffDlyCntr, 65535);
      }
      else
      {
         if (RICHBOOST_u16RichTurnOffDlyCntr > 0)
         {
            RICHBOOST_u16RichTurnOffDlyCntr =
               (uint16)(RICHBOOST_u16RichTurnOffDlyCntr - 1);
         }
      }
      if (RICHBOOST_u16RichTurnOffDlyCntr == 0)
      {
         TqSys_bRstRichSpdLimCnd_MP = 0;
      }
      else
      {
         TqSys_bRstRichSpdLimCnd_MP = 1;
      }
   }

   bLocalInhTqSysRich = GDGAR_bGetFRM(FRM_FRM_INHTQSYSRICH);

   if (  (TqSys_bRichAuthCnd == 0)
      || (bLocalInhTqSysRich != 0)
      || (bLocalEOM_bInhTqSysRich != 0)
      || (bLocalTqSys_bAcvVehSpdCtlReg != 0)
      || (TqSys_bRstRichSpdLimCnd_MP != 0))
   {
      TqSys_bRstRichCnd_MP = 1;
      VEMS_vidSET(TqSys_bAuthRich, 0);
   }
   else
   {
      TqSys_bRstRichCnd_MP = 0;
      VEMS_vidSET(TqSys_bAuthRich, 1);
   }
}

/*-------------------------------- end of file -------------------------------*/
