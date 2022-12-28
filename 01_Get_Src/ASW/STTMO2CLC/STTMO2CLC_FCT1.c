/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : STTMO2CLC                                               */
/* !Description     : STTMO2CLC Component                                     */
/*                                                                            */
/* !Module          : STTMO2CLC                                               */
/* !Description     : Calcul de la masse O2 dans le catalyseur                */
/*                                                                            */
/* !File            : STTMO2CLC_FCT1.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BITS                                                  */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / STTMO2CLC_vidInitOutput                                              */
/*   2 / STTMO2CLC_vidInit                                                    */
/*   3 / STTMO2CLC_vidCompteur_TDC_STT                                        */
/*   4 / STTMO2CLC_vidCalcul_mO2_cata                                         */
/*   5 / STTMO2CLC_vidCalcul_mO2cat                                           */
/*   6 / STTMO2CLC_vidMoteur_tournant                                         */
/*   7 / STTMO2CLC_vidMoteur_non_tournant                                     */
/*   8 / STTMO2CLC_vidCal_cond_tens_sonde                                     */
/*   9 / STTMO2CLC_vidCalcul_mO2cat_final                                     */
/*   10 / STTMO2CLC_vidMasse_stockee_STT                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 05704 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                 */
/* $Revision::                                                                */
/* $Author::                                                                  */
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "STTMO2CLC.h"
#include "STTMO2CLC_L.h"
#include "STTMO2CLC_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidInitOutput                                    */
/* !Description :  Initialisation des variables intermédiaires.               */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Eng_VoltDownLsHigh;                                        */
/*  output boolean Eng_VoltDownLsLow;                                         */
/*  output uint16 STTMO2CLC_u16VoltDownLsPrev;                                */
/*  output boolean STTMO2CLC_bMot_tournPrev;                                  */
/*  output uint16 Eng_mO2Cat;                                                 */
/*  output uint16 ExM_mO2StgCur;                                              */
/*  output uint16 ExM_mO2StgEngStop;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidInitOutput(void)
{
   /* Init of internal data */
   Eng_VoltDownLsHigh = 0;
   Eng_VoltDownLsLow = 0;
   /* Init of previous data */
   STTMO2CLC_u16VoltDownLsPrev = 0;
   STTMO2CLC_bMot_tournPrev = 0;

   /* Init of output data */
   VEMS_vidSET(Eng_mO2Cat, 0);
   VEMS_vidSET(ExM_mO2StgCur, 0);
   VEMS_vidSET(ExM_mO2StgEngStop, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidInit                                          */
/* !Description :  Initialisation des variables de sorties                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_E_11_05704_001.01                                     */
/*                 VEMS_E_11_05704_002.01                                     */
/*                 VEMS_E_11_05704_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Eng_mO2EstimOxCInit_C;                                       */
/*  output uint8 Eng_ctTDCStrt;                                               */
/*  output uint16 Eng_mO2Cat_Norm;                                            */
/*  output uint16 Eng_mO2Cat_Err;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidInit(void)
{
   /* 0_init */
   VEMS_vidSET(Eng_ctTDCStrt, 0);
   Eng_mO2Cat_Norm = (uint16)((Eng_mO2EstimOxCInit_C * 5) / 32);
   Eng_mO2Cat_Err = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidCompteur_TDC_STT                              */
/* !Description :  Lors d’un redémarrage STT on calcule le nombre de PMH      */
/*                 écoulés durant la phase de cranking.                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_E_11_05704_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input st23 Vehicle_active_state;                                          */
/*  input uint8 Eng_ctTDCStrt;                                                */
/*  output uint8 Eng_ctTDCStrt;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidCompteur_TDC_STT(void)
{
   /* 1_Compteur_TDC_STT */
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalVehicle_active_state;
   uint8   u8LocalEng_ctTDCStrt;


   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   VEMS_vidGET(Vehicle_active_state, u8LocalVehicle_active_state);
   VEMS_vidGET(Eng_ctTDCStrt, u8LocalEng_ctTDCStrt);
   if (  (u8LocalVehicle_active_state == VS_CRANKING)
      && (bLocalCoPTSt_bRStrtSTT != 0))
   {
      if (u8LocalEng_ctTDCStrt < 50)
      {
         u8LocalEng_ctTDCStrt = (uint8)(u8LocalEng_ctTDCStrt + 1);

      }
      else
      {
         u8LocalEng_ctTDCStrt = 50;
      }
   }
   else
   {
      u8LocalEng_ctTDCStrt = 0;
   }
   VEMS_vidSET(Eng_ctTDCStrt, u8LocalEng_ctTDCStrt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidCalcul_mO2_cata                               */
/* !Description :  calcul des conditions d'activation du bloc Calcul_mO2cat   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  ETSASSON                                                   */
/* !Trace_To    :  VEMS_E_11_05704_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STTMO2CLC_vidCalcul_mO2cat();                            */
/*  extf argret void STTMO2CLC_vidCal_cond_tens_sonde();                      */
/*  extf argret void STTMO2CLC_vidCalcul_mO2cat_final();                      */
/*  input boolean LsSys_bLsUsMainOxCHeatOk;                                   */
/*  input boolean LsSys_bLsDsMainOxCHeatOk;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidCalcul_mO2_cata(void)
{
   /* 2_Calcul_mO2_cata */
   boolean bLocalLsSys_bLsUsMainOxCHeatOk;
   boolean bLocalLsSys_bLsDsMainOxCHeatOk;


   VEMS_vidGET(LsSys_bLsUsMainOxCHeatOk, bLocalLsSys_bLsUsMainOxCHeatOk);
   VEMS_vidGET(LsSys_bLsDsMainOxCHeatOk, bLocalLsSys_bLsDsMainOxCHeatOk);

   if (  (bLocalLsSys_bLsUsMainOxCHeatOk != 0)
      && (bLocalLsSys_bLsDsMainOxCHeatOk != 0))
   {
      STTMO2CLC_vidCalcul_mO2cat();
   }
   STTMO2CLC_vidCal_cond_tens_sonde();
   STTMO2CLC_vidCalcul_mO2cat_final();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidCalcul_mO2cat                                 */
/* !Description :  Ce bloc permet d’effectuer le calcul de la masse d’O2 dans */
/*                 le catalyseur en fonctionnement normal                     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STTMO2CLC_vidMoteur_tournant();                          */
/*  extf argret void STTMO2CLC_vidMoteur_non_tournant();                      */
/*  input boolean Moteur_tournant;                                            */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Eng_VoltDownLsHighLim_C;                                     */
/*  input uint16 Eng_VoltDownLsLowLim_C;                                      */
/*  input uint16 OxC_mO2StgMvEstim;                                           */
/*  output uint16 Eng_mO2Cat_Err;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidCalcul_mO2cat(void)
{
   /* 1_Calcul_mO2cat */
   boolean bLocalMoteur_tournant;
   uint16  u16LocalTension_sonde_aval;
   uint16  u16LocalOxC_mO2StgMvEstim;


   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   if (bLocalMoteur_tournant != 0)
   {
      STTMO2CLC_vidMoteur_tournant();
   }
   else
   {
      STTMO2CLC_vidMoteur_non_tournant();
   }

   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   if (u16LocalTension_sonde_aval > Eng_VoltDownLsHighLim_C)
   {
      Eng_mO2Cat_Err = 0;
   }
   else
   {
      if (u16LocalTension_sonde_aval <= Eng_VoltDownLsLowLim_C)
      {
         VEMS_vidGET(OxC_mO2StgMvEstim, u16LocalOxC_mO2StgMvEstim);
         Eng_mO2Cat_Err = (uint16)(((u16LocalOxC_mO2StgMvEstim * 5)+ 16) / 32);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidMoteur_tournant                               */
/* !Description :  Dans le cas où le moteur est tournant, la masse d’oxygène  */
/*                 stockée dans le catalyseur est calculée à partir           */
/*                 del’intégrale du débit d’air cylindre converti en masse    */
/*                 d’oxygène.                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Sonde_riche_amont;                                          */
/*  input boolean Sonde_riche_aval;                                           */
/*  input uint16 EngM_mfTotExCor;                                             */
/*  input sint8 Eng_FacmO2DownLsRich_UpRich_C;                                */
/*  input sint8 Eng_FacmO2DownLsRich_UpLean_C;                                */
/*  input sint8 Eng_FacmO2DownLsLean_UpRich_C;                                */
/*  input sint8 Eng_FacmO2DownLsLean_UpLean_C;                                */
/*  input ???? SINT32_MAX;                                                    */
/*  input ???? SINT32_MIN;                                                    */
/*  input uint16 Eng_mO2Cat_Norm;                                             */
/*  output uint16 Eng_mO2Cat_Norm;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidMoteur_tournant(void)
{
   /* 1_Moteur_tournant */
   boolean bLocalSonde_riche_amont;
   boolean bLocalSonde_riche_aval;
   sint8   s8LocalFacmO2DownLs;
   uint16  u16LocalEngM_mfTotExCor;
   sint32  s32LocalEng_FacmO2DownLs;
   sint32  s32LocalEng_mO2Cat_Norm;
   sint32  s32LocalDiv;


   VEMS_vidGET(Sonde_riche_amont, bLocalSonde_riche_amont);
   VEMS_vidGET(Sonde_riche_aval, bLocalSonde_riche_aval);
   VEMS_vidGET(EngM_mfTotExCor, u16LocalEngM_mfTotExCor);

   if (bLocalSonde_riche_aval != 0)
   {
      if (bLocalSonde_riche_amont != 0)
      {
         s8LocalFacmO2DownLs = Eng_FacmO2DownLsRich_UpRich_C;
      }
      else
      {
         s8LocalFacmO2DownLs = Eng_FacmO2DownLsRich_UpLean_C;
      }
   }
   else
   {
      if (bLocalSonde_riche_amont != 0)
      {
         s8LocalFacmO2DownLs = Eng_FacmO2DownLsLean_UpRich_C;
      }
      else
      {
         s8LocalFacmO2DownLs = Eng_FacmO2DownLsLean_UpLean_C;
      }
   }

   s32LocalEng_FacmO2DownLs = (sint32)( s8LocalFacmO2DownLs
                                      * u16LocalEngM_mfTotExCor
                                      * STT_SampleTiFast_SC);
   s32LocalDiv = (SINT32_MAX / (sint32)125);
   if (s32LocalEng_FacmO2DownLs >= s32LocalDiv)
   {
      Eng_mO2Cat_Norm = 65535;
   }
   else
   {
      s32LocalDiv = (SINT32_MIN / (sint32)125);
      if (s32LocalEng_FacmO2DownLs <= s32LocalDiv)
      {
         Eng_mO2Cat_Norm = 0;
      }
      else
      {
         s32LocalEng_FacmO2DownLs = ((s32LocalEng_FacmO2DownLs * 125)) / 16384;

         s32LocalEng_mO2Cat_Norm = (Eng_mO2Cat_Norm + s32LocalEng_FacmO2DownLs);
         Eng_mO2Cat_Norm = (uint16)MATHSRV_udtCLAMP(s32LocalEng_mO2Cat_Norm,
                                                    0,
                                                    65535);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidMoteur_non_tournant                           */
/* !Description :  Dans la phase moteur non tournant, la masse d’oxygène      */
/*                 stockée dans le catalyseur est calculée à partir de la     */
/*                 dernière valeur actualisée en phase moteur tournant        */
/*                 pondérée par un offset calibrable.                         */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Eng_mO2Cat_Norm;                                             */
/*  input uint16 Eng_FacmO2Stall_C;                                           */
/*  output uint16 Eng_mO2Cat_Norm;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidMoteur_non_tournant(void)
{
   /* 2_Moteur_non_tournant */
   sint32  s32LocalEng_mO2Cat_Norm;


   s32LocalEng_mO2Cat_Norm = (sint32)( ( (Eng_mO2Cat_Norm * 32)
                                       - (Eng_FacmO2Stall_C * 5))
                                     / 32);
   Eng_mO2Cat_Norm = (uint16)MATHSRV_udtMAX(s32LocalEng_mO2Cat_Norm, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidCal_cond_tens_sonde                           */
/* !Description :  Ce bloc détermine si la valeur de tension de la sonde aval */
/*                 se trouve dans une plage de fonctionnement « correcte »    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void STTMO2CLC_vidAct_tens_sond_basse();                      */
/*  extf argret void STTMO2CLC_vidDesac_tens_sond_bas();                      */
/*  extf argret void STTMO2CLC_vidAct_tens_sond_haute();                      */
/*  extf argret void STTMO2CLC_vidDesac_tens_sond_hau();                      */
/*  input boolean Eng_VoltDownLsLow;                                          */
/*  input boolean Eng_VoltDownLsHigh;                                         */
/*  input uint16 Tension_sonde_aval;                                          */
/*  input uint16 Eng_VoltDownLsLowLim_C;                                      */
/*  input uint16 STTMO2CLC_u16VoltDownLsPrev;                                 */
/*  input uint16 Eng_VoltDownLsLowHighLim_C;                                  */
/*  input uint16 Eng_VoltDownLsHighLim_C;                                     */
/*  input uint16 Eng_VoltDownLsHighLowLim_C;                                  */
/*  output uint16 STTMO2CLC_u16VoltDownLsPrev;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidCal_cond_tens_sonde(void)/*FCT8*/
{
   /* 2_Calcul_conditions_tension_sonde */
   boolean bLocalEng_VoltDownLsLowPrev;
   boolean bLocalEng_VoltDownLsHighPrev;
   uint16  u16LocalTension_sonde_aval;


   bLocalEng_VoltDownLsLowPrev = Eng_VoltDownLsLow;
   bLocalEng_VoltDownLsHighPrev = Eng_VoltDownLsHigh;

   VEMS_vidGET(Tension_sonde_aval, u16LocalTension_sonde_aval);
   if (  (u16LocalTension_sonde_aval <= Eng_VoltDownLsLowLim_C)
      && (STTMO2CLC_u16VoltDownLsPrev > Eng_VoltDownLsLowLim_C))
   {
      STTMO2CLC_vidAct_tens_sond_basse();
   }

   if (  (  (Eng_VoltDownLsLow != 0)
         && (u16LocalTension_sonde_aval >= Eng_VoltDownLsLowHighLim_C))
      && (  (bLocalEng_VoltDownLsLowPrev == 0)
         || (STTMO2CLC_u16VoltDownLsPrev < Eng_VoltDownLsLowHighLim_C)))
   {
      STTMO2CLC_vidDesac_tens_sond_bas();
   }

   if (  (u16LocalTension_sonde_aval >= Eng_VoltDownLsHighLim_C)
      && (STTMO2CLC_u16VoltDownLsPrev < Eng_VoltDownLsHighLim_C))
   {
      STTMO2CLC_vidAct_tens_sond_haute();
   }

   if (  (  (Eng_VoltDownLsHigh != 0)
         && (u16LocalTension_sonde_aval <= Eng_VoltDownLsHighLowLim_C))
      && (  (bLocalEng_VoltDownLsHighPrev == 0)
         || (STTMO2CLC_u16VoltDownLsPrev > Eng_VoltDownLsHighLowLim_C)))
   {
      STTMO2CLC_vidDesac_tens_sond_hau();
   }

   STTMO2CLC_u16VoltDownLsPrev = u16LocalTension_sonde_aval;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidCalcul_mO2cat_final                           */
/* !Description :  Ce bloc permet de mettre à jour et de saturer la variable  */
/*                 de sortie donnant la masse d’oxygène stockée par le        */
/*                 catalyseur qui sera utilisée par les autres fonctions du   */
/*                 contrôle moteur.                                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void STTMO2CLC_vidMasse_stockee_STT();                        */
/*  input boolean Eng_VoltDownLsLow;                                          */
/*  input boolean Eng_VoltDownLsHigh;                                         */
/*  input uint16 Eng_mO2Cat_Err;                                              */
/*  input uint16 Eng_mO2Cat_Norm;                                             */
/*  input uint16 OxC_mO2StgMvEstim;                                           */
/*  input boolean Moteur_tournant;                                            */
/*  input boolean STTMO2CLC_bMot_tournPrev;                                   */
/*  output uint16 ExM_mO2StgCur;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidCalcul_mO2cat_final(void)
{
   boolean bLocalMoteur_tournant;
   uint16  u16LocalInputClamp;
   uint16  u16LocalExM_mO2StgCur;
   uint16  u16LocalOxC_mO2StgMvEstim;
   uint16  u16LocalVaxClamp;
   uint16  u16LocalOutputClamp;


   if (  (Eng_VoltDownLsLow != 0)
      || (Eng_VoltDownLsHigh != 0))
   {
      u16LocalInputClamp = Eng_mO2Cat_Err;
   }
   else
   {
      u16LocalInputClamp = Eng_mO2Cat_Norm;
   }

   VEMS_vidGET(OxC_mO2StgMvEstim, u16LocalOxC_mO2StgMvEstim);
   u16LocalVaxClamp = (uint16)(((u16LocalOxC_mO2StgMvEstim * 5) + 16) / 32);
   if (u16LocalInputClamp >= u16LocalVaxClamp)
   {
      u16LocalOutputClamp = u16LocalVaxClamp;
   }
   else
   {
      u16LocalOutputClamp = u16LocalInputClamp;
   }

   u16LocalExM_mO2StgCur = (uint16)(u16LocalOutputClamp / 10);
   VEMS_vidSET(ExM_mO2StgCur, u16LocalExM_mO2StgCur);

   VEMS_vidGET(Moteur_tournant, bLocalMoteur_tournant);
   if (  (bLocalMoteur_tournant != 0)
      && (STTMO2CLC_bMot_tournPrev == 0))
   {
      STTMO2CLC_vidMasse_stockee_STT();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  STTMO2CLC_vidMasse_stockee_STT                             */
/* !Description :  Ce bloc permet de mettre à jour la variable                */
/*                 ExM_mO2StgEngStop à la fin de la phase d’arrêt, lorsque le */
/*                 moteur passe à moteur tournant.                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  ETSASSON                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ExM_mO2StgCur;                                               */
/*  output uint16 ExM_mO2StgEngStop;                                          */
/*  output uint16 Eng_mO2Cat;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void STTMO2CLC_vidMasse_stockee_STT(void)
{
   uint16  u16LocalExM_mO2StgCur;
   uint16  u16LocalEng_mO2Cat;
   uint16  u16LocalExM_mO2StgEngStop;
   uint32  u32LocalEng_mO2Cat;


   VEMS_vidGET(ExM_mO2StgCur, u16LocalExM_mO2StgCur);
   u16LocalExM_mO2StgEngStop = (uint16)MATHSRV_udtMIN(u16LocalExM_mO2StgCur,
                                                      5000);
   VEMS_vidSET(ExM_mO2StgEngStop, u16LocalExM_mO2StgEngStop);
   u32LocalEng_mO2Cat = (u16LocalExM_mO2StgCur * 10);
   u16LocalEng_mO2Cat = (uint16)MATHSRV_udtMIN(u32LocalEng_mO2Cat, 65535);
   VEMS_vidSET(Eng_mO2Cat, u16LocalEng_mO2Cat);
}
/*------------------------------- end of file --------------------------------*/