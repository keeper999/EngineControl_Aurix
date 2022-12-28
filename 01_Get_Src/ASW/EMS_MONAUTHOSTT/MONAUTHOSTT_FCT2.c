/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MONAUTHOSTT                                             */
/* !Description     : MONAUTHOSTT Component                                   */
/*                                                                            */
/* !Module          : MONAUTHOSTT                                             */
/* !Description     : SAFETY TMS : STT Chaine de Traction                     */
/*                                                                            */
/* !File            : MONAUTHOSTT_FCT2.C                                      */
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
/*   1 / MONAUTHOSTT_vidSecurisationSTTDA                                     */
/*   2 / MONAUTHOSTT_vidAutorisRedemSTT                                       */
/*   3 / MONAUTHOSTT_vidSecuriser_STT                                         */
/*   4 / MONAUTHOSTT_vidSecurEmbrContNeut                                     */
/*   5 / MONAUTHOSTT_vidCalcul_Defaut_CdT                                     */
/*   6 / MONAUTHOSTT_vidCoord_defaut_CdT                                      */
/*   7 / MONAUTHOSTT_vidSecuEmbConNeutBVA                                     */
/*   8 / MONAUTHOSTT_vidCrdEmbConNeutConf                                     */
/*   9 / MONAUTHOSTT_vidAutorRedemSansSTT                                     */
/*   10 / MONAUTHOSTT_vidAutorisationDem                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5199597 / 01                                        */
/* !OtherRefs   : 01460_10_03769 / 1.3                                        */
/* !OtherRefs   : VEMS V02 ECU#047008                                         */
/* !OtherRefs   : VEMS V02 ECU#060257                                         */
/* !OtherRefs   : VEMS V02 ECU#065855                                         */
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
#include "MONAUTHOSTT.h"
#include "MONAUTHOSTT_L.h"
#include "MONAUTHOSTT_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidSecurisationSTTDA                           */
/* !Description :  Cette fonction permet de surveiller le démarrage /         */
/*                 redémarrage intempestif STT , DAGMP.                       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MONAUTHOSTT_vidAutorisRedemSTT();                        */
/*  extf argret void MONAUTHOSTT_vidAutorRedemSansSTT();                      */
/*  extf argret void MONAUTHOSTT_vidAutorisationDem();                        */
/*  extf argret void MONAUTHOSTT_vidCoordAutDemRedem();                       */
/*  extf argret void MONAUTHOSTT_vidCrdDemdAutDmRdmN1();                      */
/*  extf argret void MONAUTHOSTT_vidCompGenDefautSTT();                       */
/*  input boolean SftyMgt_bEnaSTTADCf;                                        */
/*  input boolean SftyMgt_bEnaNotSTTADCf;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidSecurisationSTTDA(void)
{
   if (SftyMgt_bEnaSTTADCf != 0)
   {
      MONAUTHOSTT_vidAutorisRedemSTT();
   }
   if (SftyMgt_bEnaNotSTTADCf != 0)
   {
      MONAUTHOSTT_vidAutorRedemSansSTT();
   }
   MONAUTHOSTT_vidAutorisationDem();
   MONAUTHOSTT_vidCoordAutDemRedem();
   MONAUTHOSTT_vidCrdDemdAutDmRdmN1();
   MONAUTHOSTT_vidCompGenDefautSTT();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidAutorisRedemSTT                             */
/* !Description :  Cette fonction permet de surveiller le démarrage /         */
/*                 redémarrage intempestif STT , DAGMP.                       */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MONAUTHOSTT_vidSecuriser_STT();                          */
/*  extf argret void MONAUTHOSTT_vidSecurEmbrContNeut();                      */
/*  extf argret void MONAUTHOSTT_vidSecuEmbConNeutBVA();                      */
/*  extf argret void MONAUTHOSTT_vidCrdEmbConNeutConf();                      */
/*  input boolean SftyMgt_bEnaMTSTTADCf;                                      */
/*  input boolean SftyMgt_bEnaNotMTSTTADCf;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidAutorisRedemSTT(void)
{
   MONAUTHOSTT_vidSecuriser_STT();
   if (SftyMgt_bEnaMTSTTADCf != 0)
   {
      MONAUTHOSTT_vidSecurEmbrContNeut();
   }

   if (SftyMgt_bEnaNotMTSTTADCf != 0)
   {
      MONAUTHOSTT_vidSecuEmbConNeutBVA();
   }
   MONAUTHOSTT_vidCrdEmbConNeutConf();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidSecuriser_STT                               */
/* !Description :  Cette fonction permet de surveiller le démarrage /         */
/*                 redémarrage intempestif STT , DAGMP.                       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bNeut;                                              */
/*  input boolean SftyMgt_bRStrtAuthTra;                                      */
/*  input uint16 SftyMgt_rCluPedPHiFreq;                                      */
/*  input uint16 SftyMgt_spdVeh;                                              */
/*  input uint16 SftyMgt_spdVehSecu;                                          */
/*  input boolean SftyMgt_bEnaMTSTTADCf;                                      */
/*  input uint16 SftyMgt_rCluThdSTTChk_C;                                     */
/*  input boolean SftyMgt_bInhVehSecu_C;                                      */
/*  input uint16 SftyMgt_spdVehThdSTTChk1_C;                                  */
/*  input boolean SftyMgt_bRStrtAuthSTT;                                      */
/*  output boolean SftyMgt_bRStrtAuthSTT;                                     */
/*  output boolean MONAUTHOSTT_bRStrtAuthSTTMerge;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidSecuriser_STT(void)
{
   boolean bLocalSftyMgt_bNeut;
   boolean bLocalSftyMgt_bRStrtAuthTra;
   boolean bLocalVar;
   uint16  u16LocalSftyMgt_rCluPedPHiFreq;
   uint16  u16LocalSftyMgt_spdVeh;
   uint16  u16LocalSftyMgt_spdVehSecu;
   uint16  u16LocalVar;


   VEMS_vidGET(SftyMgt_bNeut, bLocalSftyMgt_bNeut);
   VEMS_vidGET(SftyMgt_bRStrtAuthTra, bLocalSftyMgt_bRStrtAuthTra);
   VEMS_vidGET(SftyMgt_rCluPedPHiFreq, u16LocalSftyMgt_rCluPedPHiFreq);
   VEMS_vidGET(SftyMgt_spdVeh, u16LocalSftyMgt_spdVeh);
   VEMS_vidGET(SftyMgt_spdVehSecu, u16LocalSftyMgt_spdVehSecu);

   if (SftyMgt_bEnaMTSTTADCf != 0)
   {
      if (  (bLocalSftyMgt_bNeut != 0)
         || (u16LocalSftyMgt_rCluPedPHiFreq >= SftyMgt_rCluThdSTTChk_C))
      {
         bLocalVar = 1;
      }
      else
      {
         bLocalVar = 0;
      }
   }
   else
   {
      bLocalVar = bLocalSftyMgt_bRStrtAuthTra;
   }

   if (SftyMgt_bInhVehSecu_C != 0)
   {
      u16LocalVar = u16LocalSftyMgt_spdVeh;
   }
   else
   {
      u16LocalVar = u16LocalSftyMgt_spdVehSecu;
   }

   if (  (bLocalVar != 0)
      || (u16LocalVar > SftyMgt_spdVehThdSTTChk1_C))
   {
      SftyMgt_bRStrtAuthSTT = 1;
   }
   else
   {
      SftyMgt_bRStrtAuthSTT = 0;
   }
   MONAUTHOSTT_bRStrtAuthSTTMerge = SftyMgt_bRStrtAuthSTT;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidSecurEmbrContNeut                           */
/* !Description :  Sécurisation de l’embrayage continu, seulement valide en   */
/*                 BVM                                                        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MONAUTHOSTT_vidCalcul_Defaut_CdT();                      */
/*  extf argret void MONAUTHOSTT_vidCoord_defaut_CdT();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidSecurEmbrContNeut(void)
{
   MONAUTHOSTT_vidCalcul_Defaut_CdT();
   MONAUTHOSTT_vidCoord_defaut_CdT();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCalcul_Defaut_CdT                           */
/* !Description :  Définit la condition dans laquelle l’embrayage ou le neutre*/
/*                 sont considérés en défaut                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_015.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean SftyMgt_bNeut;                                              */
/*  input sint8 SftyMgt_noEgdGearSfty;                                        */
/*  input uint16 SftyMgt_nEng;                                                */
/*  input uint16 SftyMgt_rCluPedPHiFreq;                                      */
/*  input uint16 SftyMgt_spdVehSecu;                                          */
/*  input uint8 SftyMgt_stTqReqCha;                                           */
/*  input uint8 SftyMgt_noTiDlyStepNEngGrad_C;                                */
/*  input uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev;                             */
/*  input uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev1;                            */
/*  input uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev2;                            */
/*  input uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev3;                            */
/*  input uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev4;                            */
/*  input uint16 SftyMgt_nEngTiDly_MP;                                        */
/*  input sint16 SftyMgt_nTiEngGrad_MP;                                       */
/*  input sint16 SftyMgt_nTiEngGradThd_C;                                     */
/*  input uint16 SftyMgt_nEngGradLo_C;                                        */
/*  input uint16 SftyMgt_nEngGradHi_C;                                        */
/*  input uint16 MONAUTHOSTT_u16spdVehSecuPrev;                               */
/*  input uint16 SftyMgt_spdVehGrad_C;                                        */
/*  input uint16 SftyMgt_rCluPThdClsTraLo_C;                                  */
/*  input boolean SftyMgt_bInhNoEgdGearSfty_C;                                */
/*  input boolean SftyMgt_bNoEgdGearSftyCf_C;                                 */
/*  input boolean SftyMgt_bEngAuth_MP;                                        */
/*  input uint8 SftyMgt_stTqReqChaASR_C;                                      */
/*  input boolean SftyMgt_bEngGradThd_MP;                                     */
/*  input boolean SftyMgt_bDftEngGradTraMonAcv;                               */
/*  output uint16 SftyMgt_nEngTiDly_MP;                                       */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev4;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev3;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev2;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev1;                           */
/*  output uint16 MONAUTHOSTT_u16SftyMgt_nEngPrev;                            */
/*  output sint16 SftyMgt_nTiEngGrad_MP;                                      */
/*  output boolean SftyMgt_bEngGradThd_MP;                                    */
/*  output boolean SftyMgt_bEngAuth_MP;                                       */
/*  output boolean SftyMgt_bDftEngGradTraMonAcv;                              */
/*  output boolean SftyMgt_bDftEngGradTra;                                    */
/*  output uint16 MONAUTHOSTT_u16spdVehSecuPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCalcul_Defaut_CdT(void)
{
   boolean bLocalVar;
   boolean bLocalSftyMgt_bNeut;
   boolean bLocalDftEngGradTraMonAcv1;
   boolean bLocalDftEngGradTraMonAcv2;
   uint8   u8LocalSftyMgt_stTqReqCha;
   sint8   s8LocalSftyMgt_noEgdGearSfty;
   uint16  u16LocalSftyMgt_nEng;
   uint16  u16LocalSftyMgt_rCluPedPHiFreq;
   uint16  u16LocalSftyMgt_spdVehSecu;
   uint16  u16LocalScale;
   uint16  u16LocalDenum;
   uint32  u32LocalCompare;
   uint32  u32LocalVarDly;
   sint32  s32LocalNum;
   sint32  s32LocalVar;
   sint32  s32LocalResult;


   VEMS_vidGET(SftyMgt_bNeut, bLocalSftyMgt_bNeut);
   VEMS_vidGET(SftyMgt_noEgdGearSfty, s8LocalSftyMgt_noEgdGearSfty);
   VEMS_vidGET(SftyMgt_nEng, u16LocalSftyMgt_nEng);
   VEMS_vidGET(SftyMgt_rCluPedPHiFreq, u16LocalSftyMgt_rCluPedPHiFreq);
   VEMS_vidGET(SftyMgt_spdVehSecu, u16LocalSftyMgt_spdVehSecu);
   VEMS_vidGET(SftyMgt_stTqReqCha, u8LocalSftyMgt_stTqReqCha);

   switch (SftyMgt_noTiDlyStepNEngGrad_C)
   {
      case 0:
         u32LocalVarDly = (uint32)(u16LocalSftyMgt_nEng * 4);
         break;

      case 1:
         u32LocalVarDly = (uint32)(MONAUTHOSTT_u16SftyMgt_nEngPrev * 4);
         break;

      case 2:
         u32LocalVarDly = (uint32)(MONAUTHOSTT_u16SftyMgt_nEngPrev1 * 4);
         break;

      case 3:
         u32LocalVarDly = (uint32)(MONAUTHOSTT_u16SftyMgt_nEngPrev2 * 4);
         break;

      case 4:
         u32LocalVarDly = (uint32)(MONAUTHOSTT_u16SftyMgt_nEngPrev3 * 4);
         break;

      case 5:
         u32LocalVarDly = (uint32)(MONAUTHOSTT_u16SftyMgt_nEngPrev4 * 4);
         break;

      default:
         u32LocalVarDly = (uint32)(MONAUTHOSTT_u16SftyMgt_nEngPrev4 * 4);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   SftyMgt_nEngTiDly_MP = (uint16)MATHSRV_udtMIN(u32LocalVarDly, 32000);

   MONAUTHOSTT_u16SftyMgt_nEngPrev4 =
      (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16SftyMgt_nEngPrev3, 7500);

   MONAUTHOSTT_u16SftyMgt_nEngPrev3 =
      (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16SftyMgt_nEngPrev2, 7500);

   MONAUTHOSTT_u16SftyMgt_nEngPrev2 =
      (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16SftyMgt_nEngPrev1, 7500);

   MONAUTHOSTT_u16SftyMgt_nEngPrev1 =
      (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16SftyMgt_nEngPrev, 7500);

   MONAUTHOSTT_u16SftyMgt_nEngPrev =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_nEng, 7500);

   s32LocalNum = (sint32)( ( (4 * u16LocalSftyMgt_nEng)
                           - SftyMgt_nEngTiDly_MP )
                         * 25);
   u16LocalDenum = (uint16)( SftyMgt_noTiDlyStepNEngGrad_C
                           * SftyMgt_tiSdlDrvTra_SC);

   if (u16LocalDenum == 0)
   {

      SftyMgt_nTiEngGrad_MP = 0;
   }
   else
   {
      s32LocalVar = s32LocalNum / u16LocalDenum;
      SftyMgt_nTiEngGrad_MP = (sint16)MATHSRV_udtCLAMP(s32LocalVar,
                                                       -1000,
                                                       1000);
   }

   if (SftyMgt_nTiEngGrad_MP >= SftyMgt_nTiEngGradThd_C)
   {
      SftyMgt_bEngGradThd_MP = 1;
   }
   else
   {
      SftyMgt_bEngGradThd_MP = 0;
   }
   u16LocalScale = (uint16)(u16LocalSftyMgt_nEng * 4);

   if (  (u16LocalScale >= SftyMgt_nEngGradLo_C)
      && (u16LocalScale <= SftyMgt_nEngGradHi_C))
   {
      SftyMgt_bEngAuth_MP = 1;
   }
   else
   {
      SftyMgt_bEngAuth_MP = 0;
   }
   s32LocalResult =
      (sint32)( (u16LocalSftyMgt_spdVehSecu - MONAUTHOSTT_u16spdVehSecuPrev)
              * 25);
   u32LocalCompare = (uint32)MATHSRV_udtABS(s32LocalResult);
   if (u32LocalCompare >= SftyMgt_spdVehGrad_C)
   {
      bLocalVar = 1;
   }
   else
   {
      bLocalVar = 0;
   }
   if (  (u16LocalSftyMgt_rCluPedPHiFreq <= SftyMgt_rCluPThdClsTraLo_C)
      && (bLocalSftyMgt_bNeut == 0)
      && (bLocalVar != 0))
   {
      bLocalDftEngGradTraMonAcv1 = 1;
   }
   else
   {
      bLocalDftEngGradTraMonAcv1 = 0;
   }

   if (SftyMgt_bInhNoEgdGearSfty_C != 0)
   {
      bLocalDftEngGradTraMonAcv2 = SftyMgt_bNoEgdGearSftyCf_C;
   }
   else
   {
      if (s8LocalSftyMgt_noEgdGearSfty == 0)
      {
         bLocalDftEngGradTraMonAcv2 = 1;
      }
      else
      {
         bLocalDftEngGradTraMonAcv2 = 0;
      }
   }

   if (  (SftyMgt_bEngAuth_MP != 0)
      && (bLocalDftEngGradTraMonAcv1 != 0)
      && (bLocalDftEngGradTraMonAcv2 != 0)
      && (u8LocalSftyMgt_stTqReqCha != SftyMgt_stTqReqChaASR_C))
   {
      SftyMgt_bDftEngGradTraMonAcv = 1;
   }
   else
   {
      SftyMgt_bDftEngGradTraMonAcv = 0;
   }

   if (  (SftyMgt_bEngGradThd_MP != 0)
      && (SftyMgt_bDftEngGradTraMonAcv != 0))
   {
      SftyMgt_bDftEngGradTra = 1;
   }
   else
   {
      SftyMgt_bDftEngGradTra = 0;
   }
   MONAUTHOSTT_u16spdVehSecuPrev =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_spdVehSecu, 64000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCoord_defaut_CdT                            */
/* !Description :  Calibration de la remontée des défauts et filtres          */
/*                 antirebonds.                                               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_016.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDftEngGradTra_C;                                */
/*  input boolean SftyMgt_bDftEngGradTra;                                     */
/*  input uint16 SftyMgt_tiDlyInhEngStopSTTReq_C;                             */
/*  input uint16 MONAUTHOSTT_u16Counter2;                                     */
/*  input boolean SftyMgt_bDftEngGradTraMonAcv;                               */
/*  input uint16 MONAUTHOSTT_u16Counter4;                                     */
/*  input boolean SftyMgt_bInhNoEgdGearSfty_C;                                */
/*  input boolean SftyMgt_bInhEngStopMTCf;                                    */
/*  output uint16 MONAUTHOSTT_u16Counter2;                                    */
/*  output uint16 MONAUTHOSTT_u16Counter4;                                    */
/*  output boolean SftyMgt_bInhEngStopMTCf;                                   */
/*  output boolean MONAUTHOSTT_bInhEngStopMTCfMerge;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCoord_defaut_CdT(void)
{
   boolean bLocalInputRstBasculeRS;
   boolean bLocalInputCounterTMS;
   boolean bLocalTurnOnDLyOut_1;
   boolean bLocalTurnOnDLyOut_2;
   uint16  u16LocalSumTurnOnDelaySimple;
   uint16  u16LocalMinTurnOnDelaySimple;


   if (SftyMgt_bInhDftEngGradTra_C != 0)
   {
      bLocalInputCounterTMS = 0;
   }
   else
   {
      bLocalInputCounterTMS = SftyMgt_bDftEngGradTra;
   }

   /*Turn_On_Delay_Simple_1*/
   u16LocalSumTurnOnDelaySimple =
      (uint16)((SftyMgt_tiDlyInhEngStopSTTReq_C + 6) / 4);
   if (bLocalInputCounterTMS == 0)
   {
      MONAUTHOSTT_u16Counter2 = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16Counter2,
                                u16LocalSumTurnOnDelaySimple);
      MONAUTHOSTT_u16Counter2 = (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   if (MONAUTHOSTT_u16Counter2 >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalTurnOnDLyOut_1 = 1;
   }
   else
   {
      bLocalTurnOnDLyOut_1 = 0;
   }
   /*fin Turn_On_Delay_Simple_1*/

   /*Turn_On_Delay_Simple_2*/

   if (  (bLocalTurnOnDLyOut_1 == 0)
      && (SftyMgt_bDftEngGradTraMonAcv != 0))
   {
      u16LocalMinTurnOnDelaySimple =
         (uint16)MATHSRV_udtMIN(MONAUTHOSTT_u16Counter4,
                                u16LocalSumTurnOnDelaySimple);
      MONAUTHOSTT_u16Counter4 = (uint16)(u16LocalMinTurnOnDelaySimple + 1);
   }
   else
   {
      MONAUTHOSTT_u16Counter4 = 0;
   }
   if (MONAUTHOSTT_u16Counter4 >= u16LocalSumTurnOnDelaySimple)
   {
      bLocalTurnOnDLyOut_2 = 1;
   }
   else
   {
      bLocalTurnOnDLyOut_2 = 0;
   }
   /*fin Turn_On_Delay_Simple_2*/
   if (SftyMgt_bInhNoEgdGearSfty_C != 0)
   {
      bLocalInputRstBasculeRS = 0;
   }
   else
   {
      bLocalInputRstBasculeRS = bLocalTurnOnDLyOut_2;
   }
   /*Bascule RS à Reset Prioritaire*/
   if (bLocalInputRstBasculeRS != 0)
   {
      SftyMgt_bInhEngStopMTCf = 0;
   }
   else
   {
      if (bLocalTurnOnDLyOut_1 != 0)
      {
         SftyMgt_bInhEngStopMTCf = 1;
      }
   }
   MONAUTHOSTT_bInhEngStopMTCfMerge = SftyMgt_bInhEngStopMTCf;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidSecuEmbConNeutBVA                           */
/* !Description :  Pas de sécurisation d’embrayage et neutre en BVA/BVMP      */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhEngStopNotMTCf;                                 */
/*  output boolean SftyMgt_bInhEngStopNotMTCf;                                */
/*  output boolean MONAUTHOSTT_bInhEngStopMTCfMerge;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidSecuEmbConNeutBVA(void)
{
   SftyMgt_bInhEngStopNotMTCf = 0;
   MONAUTHOSTT_bInhEngStopMTCfMerge = SftyMgt_bInhEngStopNotMTCf;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidCrdEmbConNeutConf                           */
/* !Description :  Merge                                                      */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean MONAUTHOSTT_bInhEngStopMTCfMerge;                           */
/*  output boolean Sfty_bInhEngStopSTTReq;                                    */
/*  output boolean SftyMgt_bDgoInhEngStopSTT;                                 */
/*  output boolean SftyMgt_bMonRunInhEngStopSTT;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidCrdEmbConNeutConf(void)
{
   boolean bLocalSftyMgt_bDgoInhEngStopSTT;
   boolean bLocalSfty_bInhEngStopSTTReq;


   bLocalSfty_bInhEngStopSTTReq = MONAUTHOSTT_bInhEngStopMTCfMerge;
   VEMS_vidSET(Sfty_bInhEngStopSTTReq, bLocalSfty_bInhEngStopSTTReq);

   bLocalSftyMgt_bDgoInhEngStopSTT = bLocalSfty_bInhEngStopSTTReq;
   VEMS_vidSET(SftyMgt_bDgoInhEngStopSTT, bLocalSftyMgt_bDgoInhEngStopSTT);

   VEMS_vidSET(SftyMgt_bMonRunInhEngStopSTT, 1);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidAutorRedemSansSTT                           */
/* !Description :  Pas de sécurisation hors STT                               */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bRStrtAuthNotSTT;                                   */
/*  output boolean SftyMgt_bRStrtAuthNotSTT;                                  */
/*  output boolean MONAUTHOSTT_bRStrtAuthSTTMerge;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidAutorRedemSansSTT(void)
{
   SftyMgt_bRStrtAuthNotSTT = 0;
   MONAUTHOSTT_bRStrtAuthSTTMerge = SftyMgt_bRStrtAuthNotSTT;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MONAUTHOSTT_vidAutorisationDem                             */
/* !Description :  Autorisation de démarrage                                  */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Riadh.CHAKCHOUK                                            */
/* !Trace_To    :  VEMS_R_11_01222_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SftyMgt_bEngStrtReq;                                        */
/*  input boolean SftyMgt_bDrvStrtReq;                                        */
/*  input boolean SftyMgt_bStaAuthStaCtl;                                     */
/*  input boolean SftyMgt_bInhStaAuth_C;                                      */
/*  output boolean SftyMgt_bStrtAuth;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MONAUTHOSTT_vidAutorisationDem(void)
{
   boolean bLocalSftyMgt_bEngStrtReq;
   boolean bLocalSftyMgt_bDrvStrtReq;
   boolean bLocalSftyMgt_bStaAuthStaCtl;
   boolean bLocalVar;


   VEMS_vidGET(SftyMgt_bEngStrtReq, bLocalSftyMgt_bEngStrtReq);
   VEMS_vidGET(SftyMgt_bDrvStrtReq, bLocalSftyMgt_bDrvStrtReq);
   VEMS_vidGET(SftyMgt_bStaAuthStaCtl, bLocalSftyMgt_bStaAuthStaCtl);

   if (SftyMgt_bInhStaAuth_C != 0)
   {
      bLocalVar = 1;
   }
   else
   {
      bLocalVar = bLocalSftyMgt_bStaAuthStaCtl;
   }

   if (  (bLocalSftyMgt_bEngStrtReq != 0)
      && (bLocalSftyMgt_bDrvStrtReq != 0)
      && (bLocalVar !=0))
   {
      SftyMgt_bStrtAuth = 1;
   }
   else
   {
      SftyMgt_bStrtAuth = 0;
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/