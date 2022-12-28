/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MEM                                                     */
/* !Description     : MEM Component                                           */
/*                                                                            */
/* !Module          : MEM                                                     */
/* !Description     : MEMORISATION DES PARAMETRES DEFAUTS                     */
/*                                                                            */
/* !File            : MEM_fct1.C                                              */
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
/*   1 / MEM_vidF01_Init                                                      */
/*   2 / MEM_vidF01_DTCRec                                                    */
/*   3 / MEM_vidF01_FrzData                                                   */
/*   4 / MEM_vidF02_StoreDataFrf                                              */
/*   5 / MEM_vidF04_RstnoRnkFrf                                               */
/*   6 / MEM_vidF06_RstDftMng                                                 */
/*   7 / MEM_vidF07_RstDftObdMng                                              */
/*   8 / MEM_vidF04_StoreFrfObd                                               */
/*   9 / MEM_vidF08_StoreData                                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5447179 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/MEM/MEM_fct1.c_v             $*/
/* $Revision::   1.18     $$Author::   mbenfrad       $$Date::   17 Sep 2013 $*/
/* $Author::   mbenfrad                               $$Date::   17 Sep 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "MEM.h"
#include "MEM_L.h"
#include "MEM_IM.h"
#include "MEM_CONF.h"
#include "NVMSRV.h"
#include "GD_A.h"
#include "GD_API.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF01_Init                                            */
/* !Description :  Effacement de tous les DTC                                 */
/* !Number      :  FCT1.01                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint16 GD_DID_dstAbsKm_C;                                           */
/*  input uint16 GD_DID_tiCurVehTmr_C;                                        */
/*  input uint16 GD_DID_nEng_C;                                               */
/*  input uint16 GD_DID_rAccP_C;                                              */
/*  input uint16 GD_DID_spdVeh_C;                                             */
/*  input uint16 GD_DID_tCoMes_C;                                             */
/*  input uint16 GD_DID_uBattMes_C;                                           */
/*  output uint32 GD_NoDTC[7];                                                */
/*  output uint8 GD_au8idxFltToCxtNoFrf[40];                                  */
/*  output uint16 GD_au16idxDftNoFrf[40];                                     */
/*  output uint8 GD_au8StFrfRecNoFrf[40];                                     */
/*  output uint8 GD_Pid03_NoFrf[40];                                          */
/*  output uint8 GD_Pid04_NoFrf[40];                                          */
/*  output uint8 GD_Pid05_NoFrf[40];                                          */
/*  output uint8 GD_Pid06_NoFrf[40];                                          */
/*  output uint8 GD_Pid07_NoFrf[40];                                          */
/*  output uint8 GD_Pid0B_NoFrf[40];                                          */
/*  output uint16 GD_Pid0C_NoFrf[40];                                         */
/*  output uint8 GD_Pid0D_NoFrf[40];                                          */
/*  output uint16 GD_Pid23_NoFrf[40];                                         */
/*  output uint16 GD_Pid42_NoFrf[40];                                         */
/*  output uint32 GD_au32dstAbsKmNoFrf[40];                                   */
/*  output uint32 GD_tiCurVehTmr_NoFrf[40];                                   */
/*  output uint16 GD_au16nEngNoFrf[40];                                       */
/*  output uint16 GD_rAccP_NoFrf[40];                                         */
/*  output uint16 GD_spdVeh_NoFrf[40];                                        */
/*  output sint16 GD_as16tCoMesNoFrf[40];                                     */
/*  output uint16 GD_uBattMes_NoFrf[40];                                      */
/*  output uint32 GD_au32prmClasFrf1NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf2NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf3NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf4NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf5NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf6NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf7NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf8NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf9NoFrf[40];                                */
/*  output uint16 GD_au16prmClasDID1[40];                                     */
/*  output uint16 GD_au16prmClasDID2[40];                                     */
/*  output uint16 GD_au16prmClasDID3[40];                                     */
/*  output uint16 GD_au16prmClasDID4[40];                                     */
/*  output uint16 GD_au16prmClasDID5[40];                                     */
/*  output uint16 GD_au16prmClasDID6[40];                                     */
/*  output uint16 GD_au16prmClasDID7[40];                                     */
/*  output uint16 GD_au16prmClasDID8[40];                                     */
/*  output uint16 GD_au16prmClasDID9[40];                                     */
/*  output uint16 GD_DID_dstAbsKm;                                            */
/*  output uint16 GD_DID_dstAbsKm_C;                                          */
/*  output uint16 GD_DID_tiCurVehTmr;                                         */
/*  output uint16 GD_DID_tiCurVehTmr_C;                                       */
/*  output uint16 GD_DID_nEng;                                                */
/*  output uint16 GD_DID_nEng_C;                                              */
/*  output uint16 GD_DID_rAccP;                                               */
/*  output uint16 GD_DID_rAccP_C;                                             */
/*  output uint16 GD_DID_spdVeh;                                              */
/*  output uint16 GD_DID_spdVeh_C;                                            */
/*  output uint16 GD_DID_tCoMes;                                              */
/*  output uint16 GD_DID_tCoMes_C;                                            */
/*  output uint16 GD_DID_uBattMes;                                            */
/*  output uint16 GD_DID_uBattMes_C;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF01_Init(void)
{

   uint8  u8LocalStFrfRec;
   sint32 s32LocalIdx;


   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      /* Effacement de tous les DTC*/
      GD_NoDTC[s32LocalIdx] = DEFAULT_DTC;
   }

   for (s32LocalIdx = 0; s32LocalIdx < GD_NB_DFTCXTMAX; s32LocalIdx++)
   {
      u8LocalStFrfRec = GD_au8StFrfRecNoFrf[s32LocalIdx];

      if (u8LocalStFrfRec == 1)
      {
         /* Effacement de la table des contextes */
         GD_au8idxFltToCxtNoFrf[s32LocalIdx]   = 0;
         GD_au16idxDftNoFrf[s32LocalIdx]       = 0xFFFF;
         GD_au8StFrfRecNoFrf[s32LocalIdx]      = 0;
         GD_Pid03_NoFrf[s32LocalIdx]           = 0;
         GD_Pid04_NoFrf[s32LocalIdx]           = 0;
         GD_Pid05_NoFrf[s32LocalIdx]           = 40;
         GD_Pid06_NoFrf[s32LocalIdx]           = 128;
         GD_Pid07_NoFrf[s32LocalIdx]           = 128;
         GD_Pid0B_NoFrf[s32LocalIdx]           = 0;
         GD_Pid0C_NoFrf[s32LocalIdx]           = 0;
         GD_Pid0D_NoFrf[s32LocalIdx]           = 0;
         GD_Pid23_NoFrf[s32LocalIdx]           = 0;
         GD_Pid42_NoFrf[s32LocalIdx]           = 0;
         GD_au32dstAbsKmNoFrf[s32LocalIdx]     = 0;
         GD_tiCurVehTmr_NoFrf[s32LocalIdx]     = 0;
         GD_au16nEngNoFrf[s32LocalIdx]         = 0;
         GD_rAccP_NoFrf[s32LocalIdx]           = 0;
         GD_spdVeh_NoFrf[s32LocalIdx]          = 0;
         GD_as16tCoMesNoFrf[s32LocalIdx]        = 0;
         GD_uBattMes_NoFrf[s32LocalIdx]        = 0;
         GD_au32prmClasFrf1NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf2NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf3NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf4NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf5NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf6NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf7NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf8NoFrf[s32LocalIdx]  = 0;
         GD_au32prmClasFrf9NoFrf[s32LocalIdx]  = 0;
         GD_au16prmClasDID1[s32LocalIdx]  = 0;
         GD_au16prmClasDID2[s32LocalIdx]  = 0;
         GD_au16prmClasDID3[s32LocalIdx]  = 0;
         GD_au16prmClasDID4[s32LocalIdx]  = 0;
         GD_au16prmClasDID5[s32LocalIdx]  = 0;
         GD_au16prmClasDID6[s32LocalIdx]  = 0;
         GD_au16prmClasDID7[s32LocalIdx]  = 0;
         GD_au16prmClasDID8[s32LocalIdx]  = 0;
         GD_au16prmClasDID9[s32LocalIdx]  = 0;
      }
   }
   VEMS_vidSET(GD_DID_dstAbsKm, GD_DID_dstAbsKm_C);
   VEMS_vidSET(GD_DID_tiCurVehTmr, GD_DID_tiCurVehTmr_C);
   VEMS_vidSET(GD_DID_nEng, GD_DID_nEng_C);
   VEMS_vidSET(GD_DID_rAccP, GD_DID_rAccP_C);
   VEMS_vidSET(GD_DID_spdVeh, GD_DID_spdVeh_C);
   VEMS_vidSET(GD_DID_tCoMes, GD_DID_tCoMes_C);
   VEMS_vidSET(GD_DID_uBattMes, GD_DID_uBattMes_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF01_DTCRec                                          */
/* !Description :  Tant que le compteur de défauts unitaires apparus          */
/*                 successivement n’a pas atteint sa valeur maximale et que la*/
/*                 classe de calibration associée l’autorise, le DTC du défaut*/
/*                 concerné monte à sa valeur générique associé, autrement il */
/*                 prend la valeur 0xFFFF.                                    */
/* !Number      :  FCT1.02                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean GD_bInhFrfRec;                                              */
/*  input uint8 GD_au8RnkFrf[7];                                              */
/*  input uint32 GD_NoDTC_C[7];                                               */
/*  output uint32 GD_NoDTC[7];                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF01_DTCRec(void)
{
   boolean bLocalGD_bInhFrfRec;
   sint32  s32LocalIdx;


   VEMS_vidGET(GD_bInhFrfRec, bLocalGD_bInhFrfRec);
   for (s32LocalIdx = 0; s32LocalIdx < GD_DFT_NB; s32LocalIdx++)
   {
      if (bLocalGD_bInhFrfRec == 0)
      {
         if (GD_au8RnkFrf[s32LocalIdx] != 0xFF)
         {
            GD_NoDTC[s32LocalIdx] = GD_NoDTC_C[s32LocalIdx];
         }
         else
         {
            GD_NoDTC[s32LocalIdx] = DEFAULT_DTC;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF01_FrzData                                         */
/* !Description :  Cette fonction permet de figer de manière temporaire       */
/*                 (uniquement en RAM) les paramètres constituants la Freeze  */
/*                 frame et ce, quelque soit le défaut (à condition que la    */
/*                 classe associé l’autorise).                                */
/* !Number      :  FCT1.03                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MEM_vidClasFrfInit(argin uint16 u16IdxDft, argin uint32* */
/* au32Frf);                                                                  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 GD_au8IdxClassDet[7];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  input boolean GD_bInhFrfRec;                                              */
/*  input boolean GD_bMaxDftMem;                                              */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint8 Srv_pDsThrMes_Pid0B;                                          */
/*  input uint8 Srv_spdVeh_Pid0D;                                             */
/*  input uint16 Srv_pFuMes_Pid23;                                            */
/*  input uint16 Srv_uBattMes_Pid42;                                          */
/*  input uint16 Srv_nEng_Pid0C;                                              */
/*  input uint8 Srv_tCoMes_Pid05;                                             */
/*  input uint8 Srv_Fuel_System_Pid03;                                        */
/*  input uint8 Srv_Engine_load_Pid04;                                        */
/*  input uint8 Srv_Lfbk_Pid06;                                               */
/*  input uint8 Srv_Diag_trim_Pid07;                                          */
/*  input uint32 Ext_dstVehTotMes;                                            */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 AccP_rAccP;                                                  */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_uBattMes;                                                */
/*  input GD_strClasDID GD_astrClasDID[9];                                    */
/*  input uint16 GD_DID_spdVeh_C;                                             */
/*  input uint16 GD_DID_uBattMes_C;                                           */
/*  input uint16 GD_DID_nEng_C;                                               */
/*  input uint16 GD_DID_rAccP_C;                                              */
/*  input uint16 GD_DID_tCoMes_C;                                             */
/*  input uint16 GD_DID_dstAbsKm_C;                                           */
/*  input uint16 GD_DID_tiCurVehTmr_C;                                        */
/*  output uint8 GD_au8StFrfRecNoFrf[40];                                     */
/*  output uint16 GD_au16idxDftNoFrf[40];                                     */
/*  output uint8 GD_Pid03_NoFrf[40];                                          */
/*  output uint8 GD_Pid04_NoFrf[40];                                          */
/*  output uint8 GD_Pid05_NoFrf[40];                                          */
/*  output uint8 GD_Pid06_NoFrf[40];                                          */
/*  output uint8 GD_Pid07_NoFrf[40];                                          */
/*  output uint8 GD_Pid0B_NoFrf[40];                                          */
/*  output uint16 GD_Pid0C_NoFrf[40];                                         */
/*  output uint8 GD_Pid0D_NoFrf[40];                                          */
/*  output uint16 GD_Pid23_NoFrf[40];                                         */
/*  output uint16 GD_Pid42_NoFrf[40];                                         */
/*  output uint32 GD_au32dstAbsKmNoFrf[40];                                   */
/*  output uint32 GD_tiCurVehTmr_NoFrf[40];                                   */
/*  output uint16 GD_au16nEngNoFrf[40];                                       */
/*  output uint16 GD_rAccP_NoFrf[40];                                         */
/*  output uint16 GD_spdVeh_NoFrf[40];                                        */
/*  output sint16 GD_as16tCoMesNoFrf[40];                                     */
/*  output uint16 GD_uBattMes_NoFrf[40];                                      */
/*  output uint32 GD_au32prmClasFrf1NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf2NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf3NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf4NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf5NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf6NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf7NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf8NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf9NoFrf[40];                                */
/*  output uint16 GD_au16prmClasDID1[40];                                     */
/*  output uint16 GD_au16prmClasDID2[40];                                     */
/*  output uint16 GD_au16prmClasDID3[40];                                     */
/*  output uint16 GD_au16prmClasDID4[40];                                     */
/*  output uint16 GD_au16prmClasDID5[40];                                     */
/*  output uint16 GD_au16prmClasDID6[40];                                     */
/*  output uint16 GD_au16prmClasDID7[40];                                     */
/*  output uint16 GD_au16prmClasDID8[40];                                     */
/*  output uint16 GD_au16prmClasDID9[40];                                     */
/*  output uint16 GD_DID_spdVeh;                                              */
/*  output uint16 GD_DID_spdVeh_C;                                            */
/*  output uint16 GD_DID_uBattMes;                                            */
/*  output uint16 GD_DID_uBattMes_C;                                          */
/*  output uint16 GD_DID_nEng;                                                */
/*  output uint16 GD_DID_nEng_C;                                              */
/*  output uint16 GD_DID_rAccP;                                               */
/*  output uint16 GD_DID_rAccP_C;                                             */
/*  output uint16 GD_DID_tCoMes;                                              */
/*  output uint16 GD_DID_tCoMes_C;                                            */
/*  output uint16 GD_DID_dstAbsKm;                                            */
/*  output uint16 GD_DID_dstAbsKm_C;                                          */
/*  output uint16 GD_DID_tiCurVehTmr;                                         */
/*  output uint16 GD_DID_tiCurVehTmr_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF01_FrzData
(
   uint16 u16IdxDft
)
{
   /* Creation of local variable for data manipulation */
   boolean bLocalEndFlag1;
   boolean bLocalEndFlag2;
   boolean bLocalEnaSaveFrf;
   boolean bLocalGD_bInhFrfRec;
   sint16  s16LocalExtCoMes;
   sint16  s16LocalExt_uBattMes;
   sint32  s32LocalIdx;
   uint8   u8LocalIdxClass;
   uint8   u8LocalSrvpDsThrMesPid0B;
   uint8   u8LocalSrvspdVehPid0D;
   uint8   u8LocalSrv_DiagTrimPid07;
   uint8   u8LocalSrv_Lfbk_Pid06;
   uint8   u8LocalSrvtCoMesPid05;
   uint8   u8LocalSrvEngineloadPid04;
   uint8   u8LocalSrvFuelSystemPid03;
   uint8   u8LocalIndFrf;
   uint16  u16LocalSrvuBattMesPid42;
   uint16  u16LocalSrv_pFuMes_Pid23;
   uint16  u16LocalSrvnEngPid0C;
   uint16  u16LocalIdxDft;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalAccP_rAccP;
   uint16  u16LocalVeh_spdVeh;
   uint32  u32LocalExtdstVehTotMes;
   uint32  u32LocalExt_tiCurVehTmr;
   uint32  au32LocalFrf[9];


   u8LocalIndFrf = 0xFF;
   /* Getting of the choice to memorize of DTC and freeze frames */
   u8LocalIdxClass = GD_au8IdxClassDet[u16IdxDft];
   bLocalEnaSaveFrf = GD_astrClasDet[u8LocalIdxClass].bEnaSaveFrfClasDet;

   VEMS_vidGET(GD_bInhFrfRec, bLocalGD_bInhFrfRec);
   if (  (GD_bMaxDftMem == 0)
      && (bLocalEnaSaveFrf == TRUE)
      && (bLocalGD_bInhFrfRec == 0))
   {
      bLocalEndFlag1 = 0;
      bLocalEndFlag2 = 0;
      for (s32LocalIdx = 0;
           (s32LocalIdx < GD_NB_DFTCXTMAX) && (bLocalEndFlag1 == 0);
           s32LocalIdx++)
      {
         u16LocalIdxDft = GD_au16idxDftNoFrf[(uint8)s32LocalIdx];

         if (u16LocalIdxDft == u16IdxDft)
         {
            u8LocalIndFrf = (uint8)s32LocalIdx;
            bLocalEndFlag1 = 1;
         }
      }

      if (u8LocalIndFrf == 0xFF)
      {
         for (s32LocalIdx = 0;
              (s32LocalIdx < GD_NB_DFTCXTMAX) && (bLocalEndFlag2 == 0);
              s32LocalIdx++)
         {
            if (GD_au8StFrfRecNoFrf[(uint8)s32LocalIdx] == 0)
            {
               u8LocalIndFrf = (uint8)s32LocalIdx;
               bLocalEndFlag2 = 1;
            }
         }
      }

      if (  (u8LocalIndFrf != 0xFF)
         && (GD_au8StFrfRecNoFrf[u8LocalIndFrf] != 2))
      {
         VEMS_vidGET(Srv_pDsThrMes_Pid0B,   u8LocalSrvpDsThrMesPid0B);
         VEMS_vidGET(Srv_spdVeh_Pid0D,      u8LocalSrvspdVehPid0D);
         VEMS_vidGET(Srv_pFuMes_Pid23,      u16LocalSrv_pFuMes_Pid23);
         VEMS_vidGET(Srv_uBattMes_Pid42,    u16LocalSrvuBattMesPid42);
         VEMS_vidGET(Srv_nEng_Pid0C,        u16LocalSrvnEngPid0C);
         VEMS_vidGET(Srv_tCoMes_Pid05,      u8LocalSrvtCoMesPid05);
         VEMS_vidGET(Srv_Fuel_System_Pid03, u8LocalSrvFuelSystemPid03);
         VEMS_vidGET(Srv_Engine_load_Pid04, u8LocalSrvEngineloadPid04);
         VEMS_vidGET(Srv_Lfbk_Pid06,        u8LocalSrv_Lfbk_Pid06);
         VEMS_vidGET(Srv_Diag_trim_Pid07,   u8LocalSrv_DiagTrimPid07);
         VEMS_vidGET(Ext_dstVehTotMes,      u32LocalExtdstVehTotMes);
         VEMS_vidGET(Ext_tiCurVehTmr,       u32LocalExt_tiCurVehTmr);
         VEMS_vidGET(Ext_nEng,              u16LocalExt_nEng);
         VEMS_vidGET(AccP_rAccP,            u16LocalAccP_rAccP);
         VEMS_vidGET(Veh_spdVeh,            u16LocalVeh_spdVeh);
         VEMS_vidGET(Ext_tCoMes,            s16LocalExtCoMes);
         VEMS_vidGET(Ext_uBattMes,          s16LocalExt_uBattMes);
         GD_au8StFrfRecNoFrf[u8LocalIndFrf]   = 1;
         GD_au16idxDftNoFrf[u8LocalIndFrf]    = u16IdxDft;
         GD_Pid03_NoFrf[u8LocalIndFrf]        = u8LocalSrvFuelSystemPid03;
         GD_Pid04_NoFrf[u8LocalIndFrf]        = u8LocalSrvEngineloadPid04;
         GD_Pid05_NoFrf[u8LocalIndFrf]        = u8LocalSrvtCoMesPid05;
         GD_Pid06_NoFrf[u8LocalIndFrf]        = u8LocalSrv_Lfbk_Pid06;
         GD_Pid07_NoFrf[u8LocalIndFrf]        = u8LocalSrv_DiagTrimPid07;
         GD_Pid0B_NoFrf[u8LocalIndFrf]        = u8LocalSrvpDsThrMesPid0B;
         GD_Pid0C_NoFrf[u8LocalIndFrf]        = u16LocalSrvnEngPid0C;
         GD_Pid0D_NoFrf[u8LocalIndFrf]        = u8LocalSrvspdVehPid0D;
         GD_Pid23_NoFrf[u8LocalIndFrf]        = u16LocalSrv_pFuMes_Pid23;
         GD_Pid42_NoFrf[u8LocalIndFrf]        = u16LocalSrvuBattMesPid42;
         u32LocalExtdstVehTotMes =
            MATHSRV_udtMIN(u32LocalExtdstVehTotMes, 16777214);
         GD_au32dstAbsKmNoFrf[u8LocalIndFrf]  = u32LocalExtdstVehTotMes;
         u32LocalExt_tiCurVehTmr =
            MATHSRV_udtMIN(u32LocalExt_tiCurVehTmr, 4294967293uL);
         GD_tiCurVehTmr_NoFrf[u8LocalIndFrf]  = u32LocalExt_tiCurVehTmr;
         u16LocalExt_nEng =
            (uint16)MATHSRV_udtMIN(u16LocalExt_nEng, 7500);
         GD_au16nEngNoFrf[u8LocalIndFrf]      = u16LocalExt_nEng;
         u16LocalAccP_rAccP =
            (uint16)MATHSRV_udtMIN(u16LocalAccP_rAccP, 12800);
         GD_rAccP_NoFrf[u8LocalIndFrf]        = u16LocalAccP_rAccP;
         u16LocalVeh_spdVeh =
            (uint16)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 64000);
         GD_spdVeh_NoFrf[u8LocalIndFrf]       = u16LocalVeh_spdVeh;

         s16LocalExtCoMes =
            (sint16)MATHSRV_udtCLAMP(s16LocalExtCoMes, -40, 214);
         GD_as16tCoMesNoFrf[u8LocalIndFrf]     = s16LocalExtCoMes;
         s16LocalExt_uBattMes =
            (sint16)MATHSRV_udtMIN(s16LocalExt_uBattMes, 3200);
         GD_uBattMes_NoFrf[u8LocalIndFrf]     = (uint16)s16LocalExt_uBattMes;

         MEM_vidClasFrfInit(u16IdxDft, au32LocalFrf);

         GD_au32prmClasFrf1NoFrf[u8LocalIndFrf] = au32LocalFrf[0];
         GD_au32prmClasFrf2NoFrf[u8LocalIndFrf] = au32LocalFrf[1];
         GD_au32prmClasFrf3NoFrf[u8LocalIndFrf] = au32LocalFrf[2];
         GD_au32prmClasFrf4NoFrf[u8LocalIndFrf] = au32LocalFrf[3];
         GD_au32prmClasFrf5NoFrf[u8LocalIndFrf] = au32LocalFrf[4];
         GD_au32prmClasFrf6NoFrf[u8LocalIndFrf] = au32LocalFrf[5];
         GD_au32prmClasFrf7NoFrf[u8LocalIndFrf] = au32LocalFrf[6];
         GD_au32prmClasFrf8NoFrf[u8LocalIndFrf] = au32LocalFrf[7];
         GD_au32prmClasFrf9NoFrf[u8LocalIndFrf] = au32LocalFrf[8];
         GD_au16prmClasDID1[u8LocalIndFrf] =
         GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid1;
         GD_au16prmClasDID2[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid2;
         GD_au16prmClasDID3[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid3;
         GD_au16prmClasDID4[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid4;
         GD_au16prmClasDID5[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid5;
         GD_au16prmClasDID6[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid6;
         GD_au16prmClasDID7[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid7;
         GD_au16prmClasDID8[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid8;
         GD_au16prmClasDID9[u8LocalIndFrf] =
            GD_astrClasDID[GD_au8IdxClasFrf[u16IdxDft]].u16ClasDid9;
         VEMS_vidSET(GD_DID_spdVeh, GD_DID_spdVeh_C);
         VEMS_vidSET(GD_DID_uBattMes, GD_DID_uBattMes_C);
         VEMS_vidSET(GD_DID_nEng, GD_DID_nEng_C);
         VEMS_vidSET(GD_DID_rAccP, GD_DID_rAccP_C);
         VEMS_vidSET(GD_DID_tCoMes, GD_DID_tCoMes_C);
         VEMS_vidSET(GD_DID_dstAbsKm, GD_DID_dstAbsKm_C);
         VEMS_vidSET(GD_DID_tiCurVehTmr, GD_DID_tiCurVehTmr_C);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF02_StoreDataFrf                                    */
/* !Description :  Enregistrement des données suivant le rang                 */
/* !Number      :  FCT1.04                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void MEM_vidF08_StoreData();                                  */
/*  input uint8 GD_au8RnkFrf[7];                                              */
/*  input uint8 GD_au8IdxClassDet[7];                                         */
/*  input GD_strClasDet GD_astrClasDet[21];                                   */
/*  input boolean GD_bInhFrfRec;                                              */
/*  input boolean GD_bMaxDftMem;                                              */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input uint8 GD_ctSngDftMem;                                               */
/*  input boolean GD_bPrioRdy[7];                                             */
/*  input uint8 GD_au8StFrfRecNoFrf[40];                                      */
/*  input uint8 GD_au8idxFltToCxtNoFrf[40];                                   */
/*  input uint32 GD_NoDTC_C[7];                                               */
/*  output uint8 GD_ctSngDftMem;                                              */
/*  output boolean GD_bMaxDftMem;                                             */
/*  output uint8 GD_au8idxFltToCxtNoFrf[40];                                  */
/*  output uint8 GD_au8RnkFrf[7];                                             */
/*  output uint8 GD_au8StFrfRecNoFrf[40];                                     */
/*  output uint32 GD_NoDTC[7];                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF02_StoreDataFrf
(
   uint16 u16IdxDft
)
{
   /* Creation of local variable for data manipulation */
   boolean bLocalEndFlag;
   boolean bLocalEnaSaveFrf;
   boolean bLocalGD_bInhFrfRec;
   sint32  s32LocalIdx;
   sint32  s32LocalIdx1;
   sint32  s32LocalIdx2;
   uint8   u8LocalRnkFrf;
   uint8   u8LocalIndprio;
   uint8   u8LocalIdxClass;
   uint16  u16LocalIdxDft;
   uint16  u16LocalLbDft;


   /* Getting of the rank of appearance of the defect in state GDU_ST_FUGITIF */
   u8LocalRnkFrf = GD_au8RnkFrf[u16IdxDft];
   /* Getting of the choice to memorize of DTC and freeze frames */
   u8LocalIdxClass = GD_au8IdxClassDet[u16IdxDft];
   bLocalEnaSaveFrf = GD_astrClasDet[u8LocalIdxClass].bEnaSaveFrfClasDet;

   VEMS_vidGET(GD_bInhFrfRec, bLocalGD_bInhFrfRec);
   if (  (GD_bMaxDftMem == 0)
      && (u8LocalRnkFrf == 0xFF)
      && (bLocalEnaSaveFrf == 1)
      && (bLocalGD_bInhFrfRec == 0))
   {
      bLocalEndFlag = 0;

      for (s32LocalIdx = 0;
           (s32LocalIdx < GD_NB_DFTCXTMAX) && (bLocalEndFlag == 0);
           s32LocalIdx++)
      {
         u16LocalIdxDft = GD_au16idxDftNoFrf[(uint8)s32LocalIdx];

         if (u16LocalIdxDft == u16IdxDft)
         {
            GD_ctSngDftMem = (uint8)(GD_ctSngDftMem + 1);
            /* Check the max value of memoring defaults*/
            if(GD_ctSngDftMem == GD_NB_DFTMEMMAX)
            {
               GD_bMaxDftMem = 1;
            }
            if (GD_bPrioRdy[u16IdxDft] != 0)
            {
               u8LocalIndprio = 0;
               for (s32LocalIdx1 = 0;
                    s32LocalIdx1 < GD_NB_DFTCXTMAX;
                    s32LocalIdx1++)
               {
                  if (GD_au8StFrfRecNoFrf[(uint8)s32LocalIdx1] == 2)
                  {
                     u16LocalLbDft = GD_au16idxDftNoFrf[(uint8)s32LocalIdx1];
                     if (u16LocalLbDft < GD_DFT_NB)
                     {
                        if (  (GD_bPrioRdy[u16LocalLbDft] != 0)
                           && ( GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx1]
                              > u8LocalIndprio))
                        {
                           u8LocalIndprio =
                              GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx1];
                        }
                     }
                     else
                     {
                        SWFAIL_vidSoftwareErrorHook();
                     }
                  }
               }
               for (s32LocalIdx2 = 0;
                    s32LocalIdx2 < GD_NB_DFTCXTMAX;
                    s32LocalIdx2++)
               {
                  if (GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx2] >
                     u8LocalIndprio)
                  {
                     if (GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx2] < 255)
                     {
                        GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx2] =
                           (uint8)(GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx2] +
                              1);
                     }
                  }
               }
               if (u8LocalIndprio < 255)
               {
                  GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] =
                     (uint8)(u8LocalIndprio + 1);
               }
               else
               {
                  GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] = 255;
               }
            }
            else
            {
               GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] = GD_ctSngDftMem;
            }
            GD_au8RnkFrf[u16IdxDft] = (uint8)s32LocalIdx;
            /* Memorizing context constructor */
            GD_au8StFrfRecNoFrf[(uint8)s32LocalIdx] = 2;
            /* maj DTC */
            GD_NoDTC[u16IdxDft] = GD_NoDTC_C[u16IdxDft];
            /* Exit for */
            bLocalEndFlag = 1;
         }
      }
      /* Ecriture en EEPROM à la volée */
      MEM_vidF08_StoreData();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF04_RstnoRnkFrf                                     */
/* !Description :  Libération du contexte anciennement associé au défaut et   */
/*                 effacement du rang de Freeze Frame du défaut concerné      */
/* !Number      :  FCT1.05                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGOBDState  GOBD_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  extf argret void MEM_vidF08_StoreData();                                  */
/*  input uint8 GD_au8RnkFrf[7];                                              */
/*  input boolean GD_bInhFrfRec;                                              */
/*  input uint8 GD_ctSngDftMem;                                               */
/*  input uint8 GD_au8idxFltToCxtNoFrf[40];                                   */
/*  input uint32 GD_NoDTC[7];                                                 */
/*  input uint8 Fault_context_eep_eobd[16];                                   */
/*  input uint16 GD_au16idxDftNoFrf[40];                                      */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input boolean GD_bPrioRdy[7];                                             */
/*  input uint8 GD_Pid03_NoFrf[40];                                           */
/*  input uint8 GD_Pid04_NoFrf[40];                                           */
/*  input uint8 GD_Pid05_NoFrf[40];                                           */
/*  input uint8 GD_Pid06_NoFrf[40];                                           */
/*  input uint8 GD_Pid07_NoFrf[40];                                           */
/*  input uint8 GD_Pid0B_NoFrf[40];                                           */
/*  input uint16 GD_Pid0C_NoFrf[40];                                          */
/*  input uint8 GD_Pid0D_NoFrf[40];                                           */
/*  input uint16 GD_Pid23_NoFrf[40];                                          */
/*  input uint16 GD_Pid42_NoFrf[40];                                          */
/*  output uint8 GD_ctSngDftMem;                                              */
/*  output boolean GD_bMaxDftMem;                                             */
/*  output uint8 GD_au8idxFltToCxtNoFrf[40];                                  */
/*  output uint8 Fault_context_eep_eobd[16];                                  */
/*  output uint8 Free_context_eobd;                                           */
/*  output uint16 GD_au16idxDftNoFrf[40];                                     */
/*  output uint8 GD_au8StFrfRecNoFrf[40];                                     */
/*  output uint8 GD_Pid03_NoFrf[40];                                          */
/*  output uint8 GD_Pid04_NoFrf[40];                                          */
/*  output uint8 GD_Pid05_NoFrf[40];                                          */
/*  output uint8 GD_Pid06_NoFrf[40];                                          */
/*  output uint8 GD_Pid07_NoFrf[40];                                          */
/*  output uint8 GD_Pid0B_NoFrf[40];                                          */
/*  output uint16 GD_Pid0C_NoFrf[40];                                         */
/*  output uint8 GD_Pid0D_NoFrf[40];                                          */
/*  output uint16 GD_Pid23_NoFrf[40];                                         */
/*  output uint16 GD_Pid42_NoFrf[40];                                         */
/*  output uint32 GD_au32dstAbsKmNoFrf[40];                                   */
/*  output uint32 GD_tiCurVehTmr_NoFrf[40];                                   */
/*  output uint16 GD_au16nEngNoFrf[40];                                       */
/*  output uint16 GD_rAccP_NoFrf[40];                                         */
/*  output uint16 GD_spdVeh_NoFrf[40];                                        */
/*  output sint16 GD_as16tCoMesNoFrf[40];                                     */
/*  output uint16 GD_uBattMes_NoFrf[40];                                      */
/*  output uint32 GD_au32prmClasFrf1NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf2NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf3NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf4NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf5NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf6NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf7NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf8NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf9NoFrf[40];                                */
/*  output uint16 GD_au16prmClasDID1[40];                                     */
/*  output uint16 GD_au16prmClasDID2[40];                                     */
/*  output uint16 GD_au16prmClasDID3[40];                                     */
/*  output uint16 GD_au16prmClasDID4[40];                                     */
/*  output uint16 GD_au16prmClasDID5[40];                                     */
/*  output uint16 GD_au16prmClasDID6[40];                                     */
/*  output uint16 GD_au16prmClasDID7[40];                                     */
/*  output uint16 GD_au16prmClasDID8[40];                                     */
/*  output uint16 GD_au16prmClasDID9[40];                                     */
/*  output uint8 GD_au8RnkFrf[7];                                             */
/*  output uint32 GD_NoDTC[7];                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF04_RstnoRnkFrf
(
   uint16 u16IdxDft
)
{
   GDFRM_tenuGOBDState stLocalGOBDState;
   boolean             bLocalEndFlagx;
   boolean             bLocalEndFlagy;
   boolean             bLocalEndFlag2;
   boolean             bLocalGD_bInhFrfRec;
   uint8               u8LocalGduNoDtcMSB;
   uint8               u8LocalGduNoDtcLSB;
   uint8               u8LocalIndRef;
   uint8               u8LocalRnkFrf;
   uint8               u8LocalIdxCtx;
   sint32              s32LocalIdx;
   sint32              s32LocalIdy;
   sint32              s32LocalIdx2;
   uint16              u16LocalIdxDft;
   sint32              s32LocalIdxPanne;


   /* Getting of the choice to memorize of DTC and freeze frames */
   u8LocalIdxCtx = 0xFF;
   u8LocalIndRef = 0xFF;
   /*QAC Warning : Msg(3:3198) : the variable must be initialized -> no impact*/
   s32LocalIdxPanne = 0xFFFF;
   u8LocalRnkFrf = GD_au8RnkFrf[u16IdxDft];

   VEMS_vidGET(GD_bInhFrfRec, bLocalGD_bInhFrfRec);
   if (  (u8LocalRnkFrf != 0xFF)
      && (bLocalGD_bInhFrfRec == 0))
   {
      /* décrémentation du nbr de defauts mem */
      GD_ctSngDftMem = (uint8)(GD_ctSngDftMem - 1);
      GD_bMaxDftMem = 0;
      if (GD_ctSngDftMem > 0)
      {
         u8LocalIndRef = GD_au8idxFltToCxtNoFrf[u8LocalRnkFrf];
         GD_au8idxFltToCxtNoFrf[u8LocalRnkFrf] = 0;

         for (s32LocalIdx = 0; s32LocalIdx < GD_NB_DFTCXTMAX; s32LocalIdx++)
         {
            if (GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] > u8LocalIndRef)
            {
               GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] =
                  (uint8)(GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] - 1);
            }
         }
         /* cherche d'un new potentiel contexte EOBD */
         u8LocalGduNoDtcMSB =
            (uint8)(((GD_NoDTC[u16IdxDft]) & 0x00FF0000) >> 16);
         u8LocalGduNoDtcLSB =
            (uint8)(((GD_NoDTC[u16IdxDft]) & 0x0000FF00) >> 8);

         if (  ((Fault_context_eep_eobd[0]) == u8LocalGduNoDtcMSB)
            && ((Fault_context_eep_eobd[1]) == u8LocalGduNoDtcLSB))
         {
            bLocalEndFlagy = 0;
            bLocalEndFlagx = 0;
            for (s32LocalIdy = 1;
                 (s32LocalIdy < GD_NB_DFTMEMMAX) && (bLocalEndFlagy == 0);
                 s32LocalIdy++)
            {
               for (s32LocalIdx = 0;
                    (s32LocalIdx < GD_NB_DFTCXTMAX) && (bLocalEndFlagx == 0);
                    s32LocalIdx++)
               {
                  u16LocalIdxDft = GD_au16idxDftNoFrf[(uint8)s32LocalIdx];
                  stLocalGOBDState = GOBD_tenuGetStDgo(u16LocalIdxDft);

                  if (  (GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx] ==
                        (uint8)s32LocalIdy)
                     && (GD_astrClasObd
                        [GD_au8IdxClasObd[u16LocalIdxDft]].bEnaSctl != 0)
                     && (  (stLocalGOBDState == GOBD_ETAT_ENREGISTRE)
                        || (stLocalGOBDState == GOBD_ETAT_HIST_OFF)
                        || (stLocalGOBDState == GOBD_ETAT_HIST_ON)))
                  {
                     u8LocalIdxCtx = (uint8)s32LocalIdx;
                     bLocalEndFlagx = 1;
                  }
               }
               if (u8LocalIdxCtx != 0xFF)
               {
                  bLocalEndFlagy = 1;
               }
            }
            /* Recopie du contexte trouvé dans le contexte EOBD */
            bLocalEndFlag2 = 0;
            if (u8LocalIdxCtx != 0xFF)
            {
               for (s32LocalIdx2 = 0;
                    (s32LocalIdx2 < GD_DFT_NB) && (bLocalEndFlag2 == 0) ;
                     s32LocalIdx2++)
               {
                  if ((GD_au8RnkFrf[s32LocalIdx2]) == u8LocalIdxCtx)
                  {
                     s32LocalIdxPanne = s32LocalIdx2;
                     bLocalEndFlag2 = 1;
                  }
               }
               if (s32LocalIdxPanne != 0xFFFF)
               {
                  Fault_context_eep_eobd[0] =
                     (uint8)(((GD_NoDTC[s32LocalIdxPanne]) & 0x00FF0000) >> 16);
                  Fault_context_eep_eobd[1] =
                     (uint8)(((GD_NoDTC[s32LocalIdxPanne]) & 0x0000FF00) >> 8);
                  Fault_context_eep_eobd[2] =
                     (uint8)((GD_NoDTC[s32LocalIdxPanne]) & 0x000000FF);
                  if (GD_bPrioRdy[s32LocalIdxPanne] != 0)
                  {
                     Free_context_eobd = 0x02;
                  }
                  else
                  {
                     Free_context_eobd = 0x00;
                  }
               }
               if (u8LocalIdxCtx < GD_NB_DFTCXTMAX)
               {
                  Fault_context_eep_eobd[3] = GD_Pid03_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[4] = GD_Pid04_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[5] = GD_Pid05_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[6] = GD_Pid06_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[7] = GD_Pid07_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[8] = GD_Pid0B_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[9] =
                     (uint8)(((GD_Pid0C_NoFrf[u8LocalIdxCtx]) & 0xFF00) >> 8);
                  Fault_context_eep_eobd[10] =
                     (uint8)((GD_Pid0C_NoFrf[u8LocalIdxCtx]) & 0x00FF);
                  Fault_context_eep_eobd[11] = GD_Pid0D_NoFrf[u8LocalIdxCtx];
                  Fault_context_eep_eobd[12] =
                     (uint8)(((GD_Pid23_NoFrf[u8LocalIdxCtx]) & 0xFF00) >> 8);
                  Fault_context_eep_eobd[13] =
                     (uint8)((GD_Pid23_NoFrf[u8LocalIdxCtx]) & 0x00FF);
                  Fault_context_eep_eobd[14] =
                     (uint8)(((GD_Pid42_NoFrf[u8LocalIdxCtx]) & 0xFF00) >> 8);
                  Fault_context_eep_eobd[15] =
                     (uint8)((GD_Pid42_NoFrf[u8LocalIdxCtx]) & 0x00FF);
               }
            }
            else
            {
               Free_context_eobd = 0x01;
            }
         }
      }
      else
      {
         Free_context_eobd = 0x01;
      }
      /* Effacement du contexte correspondant au défaut effacé */
      GD_au8idxFltToCxtNoFrf[u8LocalRnkFrf]   = 0;
      GD_au16idxDftNoFrf[u8LocalRnkFrf]       = 0xFFFF;
      GD_au8StFrfRecNoFrf[u8LocalRnkFrf]      = 0;
      GD_Pid03_NoFrf[u8LocalRnkFrf]           = 0;
      GD_Pid04_NoFrf[u8LocalRnkFrf]           = 0;
      GD_Pid05_NoFrf[u8LocalRnkFrf]           = 40;
      GD_Pid06_NoFrf[u8LocalRnkFrf]           = 128;
      GD_Pid07_NoFrf[u8LocalRnkFrf]           = 128;
      GD_Pid0B_NoFrf[u8LocalRnkFrf]           = 0;
      GD_Pid0C_NoFrf[u8LocalRnkFrf]           = 0;
      GD_Pid0D_NoFrf[u8LocalRnkFrf]           = 0;
      GD_Pid23_NoFrf[u8LocalRnkFrf]           = 0;
      GD_Pid42_NoFrf[u8LocalRnkFrf]           = 0;
      GD_au32dstAbsKmNoFrf[u8LocalRnkFrf]     = 0;
      GD_tiCurVehTmr_NoFrf[u8LocalRnkFrf]     = 0;
      GD_au16nEngNoFrf[u8LocalRnkFrf]         = 0;
      GD_rAccP_NoFrf[u8LocalRnkFrf]           = 0;
      GD_spdVeh_NoFrf[u8LocalRnkFrf]          = 0;
      GD_as16tCoMesNoFrf[u8LocalRnkFrf]        = 0;
      GD_uBattMes_NoFrf[u8LocalRnkFrf]        = 0;
      GD_au32prmClasFrf1NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf2NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf3NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf4NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf5NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf6NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf7NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf8NoFrf[u8LocalRnkFrf]  = 0;
      GD_au32prmClasFrf9NoFrf[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID1[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID2[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID3[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID4[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID5[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID6[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID7[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID8[u8LocalRnkFrf]  = 0;
      GD_au16prmClasDID9[u8LocalRnkFrf]  = 0;
      /* Effacement du rang de Freeze Frame du défaut concerné */
      GD_au8RnkFrf[u16IdxDft] = 0xFF;
      /* Ecriture en EEPROM à la volée */
      MEM_vidF08_StoreData();
   }
   /* Réinitialisation du DTC */
   if (bLocalGD_bInhFrfRec == 0)
   {
      GD_NoDTC[u16IdxDft] = DEFAULT_DTC;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF06_RstDftMng                                       */
/* !Description :  Effacement des défauts standards                           */
/* !Number      :  FCT1.06                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF08_StoreData();                                  */
/*  output uint8 GD_ctSngDftMem;                                              */
/*  output boolean GD_bMaxDftMem;                                             */
/*  output uint8 Free_context_eobd;                                           */
/*  output uint8 GD_au8idxFltToCxtNoFrf[40];                                  */
/*  output uint16 GD_au16idxDftNoFrf[40];                                     */
/*  output uint8 GD_au8StFrfRecNoFrf[40];                                     */
/*  output uint8 GD_Pid03_NoFrf[40];                                          */
/*  output uint8 GD_Pid04_NoFrf[40];                                          */
/*  output uint8 GD_Pid05_NoFrf[40];                                          */
/*  output uint8 GD_Pid06_NoFrf[40];                                          */
/*  output uint8 GD_Pid07_NoFrf[40];                                          */
/*  output uint8 GD_Pid0B_NoFrf[40];                                          */
/*  output uint16 GD_Pid0C_NoFrf[40];                                         */
/*  output uint8 GD_Pid0D_NoFrf[40];                                          */
/*  output uint16 GD_Pid23_NoFrf[40];                                         */
/*  output uint16 GD_Pid42_NoFrf[40];                                         */
/*  output uint32 GD_au32dstAbsKmNoFrf[40];                                   */
/*  output uint32 GD_tiCurVehTmr_NoFrf[40];                                   */
/*  output uint16 GD_au16nEngNoFrf[40];                                       */
/*  output uint16 GD_rAccP_NoFrf[40];                                         */
/*  output uint16 GD_spdVeh_NoFrf[40];                                        */
/*  output sint16 GD_as16tCoMesNoFrf[40];                                     */
/*  output uint16 GD_uBattMes_NoFrf[40];                                      */
/*  output uint32 GD_au32prmClasFrf1NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf2NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf3NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf4NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf5NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf6NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf7NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf8NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf9NoFrf[40];                                */
/*  output uint16 GD_au16prmClasDID1[40];                                     */
/*  output uint16 GD_au16prmClasDID2[40];                                     */
/*  output uint16 GD_au16prmClasDID3[40];                                     */
/*  output uint16 GD_au16prmClasDID4[40];                                     */
/*  output uint16 GD_au16prmClasDID5[40];                                     */
/*  output uint16 GD_au16prmClasDID6[40];                                     */
/*  output uint16 GD_au16prmClasDID7[40];                                     */
/*  output uint16 GD_au16prmClasDID8[40];                                     */
/*  output uint16 GD_au16prmClasDID9[40];                                     */
/*  output uint32 GD_NoDTC[7];                                                */
/*  output uint8 GD_au8RnkFrf[7];                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF06_RstDftMng(void)
{
   sint32  s32LocalIdx;
   sint32  s32LocalIdx2;

   /*Effacement de tous les compteurs */
   GD_ctSngDftMem = 0;
   GD_bMaxDftMem = 0;
   Free_context_eobd = 0x01;  /* Effacement du contexte EOBD */

   /* Effacement de la table des contextes */
   for (s32LocalIdx = 0; s32LocalIdx < GD_NB_DFTCXTMAX; s32LocalIdx++)
   {
      GD_au8idxFltToCxtNoFrf[s32LocalIdx]   = 0;
      GD_au16idxDftNoFrf[s32LocalIdx]       = 0xFFFF;
      GD_au8StFrfRecNoFrf[s32LocalIdx]      = 0;
      GD_Pid03_NoFrf[s32LocalIdx]           = 0;
      GD_Pid04_NoFrf[s32LocalIdx]           = 0;
      GD_Pid05_NoFrf[s32LocalIdx]           = 40;
      GD_Pid06_NoFrf[s32LocalIdx]           = 128;
      GD_Pid07_NoFrf[s32LocalIdx]           = 128;
      GD_Pid0B_NoFrf[s32LocalIdx]           = 0;
      GD_Pid0C_NoFrf[s32LocalIdx]           = 0;
      GD_Pid0D_NoFrf[s32LocalIdx]           = 0;
      GD_Pid23_NoFrf[s32LocalIdx]           = 0;
      GD_Pid42_NoFrf[s32LocalIdx]           = 0;
      GD_au32dstAbsKmNoFrf[s32LocalIdx]     = 0;
      GD_tiCurVehTmr_NoFrf[s32LocalIdx]     = 0;
      GD_au16nEngNoFrf[s32LocalIdx]         = 0;
      GD_rAccP_NoFrf[s32LocalIdx]           = 0;
      GD_spdVeh_NoFrf[s32LocalIdx]          = 0;
      GD_as16tCoMesNoFrf[s32LocalIdx]        = 0;
      GD_uBattMes_NoFrf[s32LocalIdx]        = 0;
      GD_au32prmClasFrf1NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf2NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf3NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf4NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf5NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf6NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf7NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf8NoFrf[s32LocalIdx]  = 0;
      GD_au32prmClasFrf9NoFrf[s32LocalIdx]  = 0;
      GD_au16prmClasDID1[s32LocalIdx]  = 0;
      GD_au16prmClasDID2[s32LocalIdx]  = 0;
      GD_au16prmClasDID3[s32LocalIdx]  = 0;
      GD_au16prmClasDID4[s32LocalIdx]  = 0;
      GD_au16prmClasDID5[s32LocalIdx]  = 0;
      GD_au16prmClasDID6[s32LocalIdx]  = 0;
      GD_au16prmClasDID7[s32LocalIdx]  = 0;
      GD_au16prmClasDID8[s32LocalIdx]  = 0;
      GD_au16prmClasDID9[s32LocalIdx]  = 0;
   }
   for(s32LocalIdx2 = 0 ; s32LocalIdx2 < GD_DFT_NB ; s32LocalIdx2++)
   {
      /* Effacement de tous les DTC */
      GD_NoDTC[s32LocalIdx2] = DEFAULT_DTC;
      /* Effacement de tous les rangs de Frf */
      GD_au8RnkFrf[s32LocalIdx2] = 0xFF;
   }
   /* Ecriture en EEPROM à la volée */
   MEM_vidF08_StoreData();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF07_RstDftObdMng                                    */
/* !Description :  Effacement des défauts OBD                                 */
/* !Number      :  FCT1.07                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MEM_vidF08_StoreData();                                  */
/*  input uint8 GD_au8idxFltToCxtNoFrf[40];                                   */
/*  input uint8 GD_au8RnkFrf[7];                                              */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input uint8 GD_ctSngDftMem;                                               */
/*  output uint8 GD_au8RnkFrf[7];                                             */
/*  output uint32 GD_NoDTC[7];                                                */
/*  output uint8 GD_ctSngDftMem;                                              */
/*  output boolean GD_bMaxDftMem;                                             */
/*  output uint8 GD_au8idxFltToCxtNoFrf[40];                                  */
/*  output uint16 GD_au16idxDftNoFrf[40];                                     */
/*  output uint8 GD_au8StFrfRecNoFrf[40];                                     */
/*  output uint8 GD_Pid03_NoFrf[40];                                          */
/*  output uint8 GD_Pid04_NoFrf[40];                                          */
/*  output uint8 GD_Pid05_NoFrf[40];                                          */
/*  output uint8 GD_Pid06_NoFrf[40];                                          */
/*  output uint8 GD_Pid07_NoFrf[40];                                          */
/*  output uint8 GD_Pid0B_NoFrf[40];                                          */
/*  output uint16 GD_Pid0C_NoFrf[40];                                         */
/*  output uint8 GD_Pid0D_NoFrf[40];                                          */
/*  output uint16 GD_Pid23_NoFrf[40];                                         */
/*  output uint16 GD_Pid42_NoFrf[40];                                         */
/*  output uint32 GD_au32dstAbsKmNoFrf[40];                                   */
/*  output uint32 GD_tiCurVehTmr_NoFrf[40];                                   */
/*  output uint16 GD_au16nEngNoFrf[40];                                       */
/*  output uint16 GD_rAccP_NoFrf[40];                                         */
/*  output uint16 GD_spdVeh_NoFrf[40];                                        */
/*  output sint16 GD_as16tCoMesNoFrf[40];                                     */
/*  output uint16 GD_uBattMes_NoFrf[40];                                      */
/*  output uint32 GD_au32prmClasFrf1NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf2NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf3NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf4NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf5NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf6NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf7NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf8NoFrf[40];                                */
/*  output uint32 GD_au32prmClasFrf9NoFrf[40];                                */
/*  output uint16 GD_au16prmClasDID1[40];                                     */
/*  output uint16 GD_au16prmClasDID2[40];                                     */
/*  output uint16 GD_au16prmClasDID3[40];                                     */
/*  output uint16 GD_au16prmClasDID4[40];                                     */
/*  output uint16 GD_au16prmClasDID5[40];                                     */
/*  output uint16 GD_au16prmClasDID6[40];                                     */
/*  output uint16 GD_au16prmClasDID7[40];                                     */
/*  output uint16 GD_au16prmClasDID8[40];                                     */
/*  output uint16 GD_au16prmClasDID9[40];                                     */
/*  output uint8 Free_context_eobd;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF07_RstDftObdMng(void)
{
   /* Creation of local variable for data manipulation */
   boolean bLocalEnaSctl;
   boolean bLocalEndFlag;
   sint32  s32LocalIdx;
   sint32  s32LocalIdx2;
   sint32  s32LocalIdx3;
   uint8   u8LocalIndRef;
   sint32  s32LocalIdxPanne;


   s32LocalIdxPanne = 0;
   u8LocalIndRef = 0;
   /*QAC Warning : Msg(3:3198) : the variable must be initialized -> no impact*/

   for (s32LocalIdx = 0; s32LocalIdx < GD_NB_DFTCXTMAX; s32LocalIdx++)
   {
      if (GD_au8idxFltToCxtNoFrf[s32LocalIdx] != 0)
      {
         bLocalEndFlag = 0;

         for (s32LocalIdx3 = 0;
              (s32LocalIdx3 < GD_DFT_NB) && (bLocalEndFlag == 0);
              s32LocalIdx3++)
         {
            if (GD_au8RnkFrf[s32LocalIdx3] == (uint8)s32LocalIdx)
            {
               s32LocalIdxPanne = (uint16)s32LocalIdx3;
               bLocalEndFlag = 1;
            }
         }
         bLocalEnaSctl =
            GD_astrClasObd[GD_au8IdxClasObd[s32LocalIdxPanne]].bEnaSctl;
         if (bLocalEnaSctl != 0)
         {
            GD_au8RnkFrf[s32LocalIdxPanne] = 0xFF;
            GD_NoDTC[s32LocalIdxPanne] = DEFAULT_DTC;
            GD_ctSngDftMem = (uint8)(GD_ctSngDftMem - 1);
            GD_bMaxDftMem = 0;
            u8LocalIndRef = GD_au8idxFltToCxtNoFrf[(uint8)s32LocalIdx];
            GD_au8idxFltToCxtNoFrf[s32LocalIdx] = 0;
            /* Les Indices Défauts reprennent leurs valeurs par défaut à FFFFh*/
            GD_au16idxDftNoFrf[s32LocalIdx] = 0xFFFF;
            /*Les états d'écriture des freeze frame simple reprennent leurs
            valeurs par défaut à 0*/
            GD_au8StFrfRecNoFrf[s32LocalIdx] = 0;
            /* Effacement de la table des contextes */
            GD_Pid03_NoFrf[s32LocalIdx]           = 0;
            GD_Pid04_NoFrf[s32LocalIdx]           = 0;
            GD_Pid05_NoFrf[s32LocalIdx]           = 40;
            GD_Pid06_NoFrf[s32LocalIdx]           = 128;
            GD_Pid07_NoFrf[s32LocalIdx]           = 128;
            GD_Pid0B_NoFrf[s32LocalIdx]           = 0;
            GD_Pid0C_NoFrf[s32LocalIdx]           = 0;
            GD_Pid0D_NoFrf[s32LocalIdx]           = 0;
            GD_Pid23_NoFrf[s32LocalIdx]           = 0;
            GD_Pid42_NoFrf[s32LocalIdx]           = 0;
            GD_au32dstAbsKmNoFrf[s32LocalIdx]     = 0;
            GD_tiCurVehTmr_NoFrf[s32LocalIdx]     = 0;
            GD_au16nEngNoFrf[s32LocalIdx]         = 0;
            GD_rAccP_NoFrf[s32LocalIdx]           = 0;
            GD_spdVeh_NoFrf[s32LocalIdx]          = 0;
            GD_as16tCoMesNoFrf[s32LocalIdx]        = 0;
            GD_uBattMes_NoFrf[s32LocalIdx]        = 0;
            GD_au32prmClasFrf1NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf2NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf3NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf4NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf5NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf6NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf7NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf8NoFrf[s32LocalIdx]  = 0;
            GD_au32prmClasFrf9NoFrf[s32LocalIdx]  = 0;
            GD_au16prmClasDID1[s32LocalIdx]  = 0;
            GD_au16prmClasDID2[s32LocalIdx]  = 0;
            GD_au16prmClasDID3[s32LocalIdx]  = 0;
            GD_au16prmClasDID4[s32LocalIdx]  = 0;
            GD_au16prmClasDID5[s32LocalIdx]  = 0;
            GD_au16prmClasDID6[s32LocalIdx]  = 0;
            GD_au16prmClasDID7[s32LocalIdx]  = 0;
            GD_au16prmClasDID8[s32LocalIdx]  = 0;
            GD_au16prmClasDID9[s32LocalIdx]  = 0;
            for (s32LocalIdx2 = 0; s32LocalIdx2 < GD_NB_DFTCXTMAX;
                   s32LocalIdx2++)
            {
               if (GD_au8idxFltToCxtNoFrf[s32LocalIdx2] > u8LocalIndRef)
               {
                  GD_au8idxFltToCxtNoFrf[s32LocalIdx2] =
                     (uint8)(GD_au8idxFltToCxtNoFrf[s32LocalIdx2] - 1);
               }
            }
         }
      }
   }
   /* Libération du contexte EOBD */
   Free_context_eobd = 0x01;
    /* Ecriture en EEPROM à la volée */
   MEM_vidF08_StoreData();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF04_StoreFrfObd                                     */
/* !Description :  Fonction appelée sur événement CALL_StObdRecTypCc_NameVar  */
/* !Number      :  FCT1.08                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MEM_vidF08_StoreData();                                  */
/*  input uint8 GD_au8RnkFrf[7];                                              */
/*  input boolean GD_bInhFrfRec;                                              */
/*  input uint8 Free_context_eobd;                                            */
/*  input GD_strClasObd GD_astrClasObd[40];                                   */
/*  input boolean GD_bPrioRdy[7];                                             */
/*  input uint32 GD_NoDTC[7];                                                 */
/*  input uint8 GD_Pid03_NoFrf[40];                                           */
/*  input uint8 GD_Pid04_NoFrf[40];                                           */
/*  input uint8 GD_Pid05_NoFrf[40];                                           */
/*  input uint8 GD_Pid06_NoFrf[40];                                           */
/*  input uint8 GD_Pid07_NoFrf[40];                                           */
/*  input uint8 GD_Pid0B_NoFrf[40];                                           */
/*  input uint16 GD_Pid0C_NoFrf[40];                                          */
/*  input uint8 GD_Pid0D_NoFrf[40];                                           */
/*  input uint16 GD_Pid23_NoFrf[40];                                          */
/*  input uint16 GD_Pid42_NoFrf[40];                                          */
/*  output uint8 Free_context_eobd;                                           */
/*  output uint8 Fault_context_eep_eobd[16];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF04_StoreFrfObd
(
   uint16 u16IdxDft
)
{
   boolean bLocalGD_bInhFrfRec;
   uint8   u8LocalIdx;
   uint8   u8LocalPriority;
   uint8   u8LocalRnkFrf;


   u8LocalPriority = 0x00;
   /*QAC Warning : Msg(3:3198) : the variable must be initialized -> no impact*/

   /* Getting of the choice to memorize of DTC and freeze frames */
   u8LocalRnkFrf = GD_au8RnkFrf[u16IdxDft];

   VEMS_vidGET(GD_bInhFrfRec, bLocalGD_bInhFrfRec);
   if (  (u8LocalRnkFrf != 0xFF)
      && (Free_context_eobd != 0x02)
      && (GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].bEnaSctl != 0)
      && (bLocalGD_bInhFrfRec == 0))
   {
      if (GD_bPrioRdy[u16IdxDft] != 0)
      {
         u8LocalPriority = 0x02;
      }
      else
      {
         u8LocalPriority = 0x00;
      }

      if (  (Free_context_eobd == 0x01)
         || (  (Free_context_eobd == 0x00)
            && (u8LocalPriority != 0x00)))
      {
         Free_context_eobd = u8LocalPriority;

         u8LocalIdx = GD_au8RnkFrf[u16IdxDft];
         Fault_context_eep_eobd[0] =
            (uint8)(((GD_NoDTC[u16IdxDft]) & 0x00FF0000) >> 16);
         Fault_context_eep_eobd[1] =
            (uint8)(((GD_NoDTC[u16IdxDft]) & 0x0000FF00) >> 8);
         Fault_context_eep_eobd[2] =
            (uint8)((GD_NoDTC[u16IdxDft]) & 0x000000FF);
         Fault_context_eep_eobd[3] = GD_Pid03_NoFrf[u8LocalIdx];
         Fault_context_eep_eobd[4] = GD_Pid04_NoFrf[u8LocalIdx];
         Fault_context_eep_eobd[5] = GD_Pid05_NoFrf[u8LocalIdx];
         Fault_context_eep_eobd[6] = GD_Pid06_NoFrf[u8LocalIdx];
         Fault_context_eep_eobd[7] = GD_Pid07_NoFrf[u8LocalIdx];
         Fault_context_eep_eobd[8] = GD_Pid0B_NoFrf [u8LocalIdx];
         Fault_context_eep_eobd[9] =
            (uint8)(((GD_Pid0C_NoFrf[u8LocalIdx]) & 0xFF00) >> 8);
         Fault_context_eep_eobd[10] =
            (uint8)((GD_Pid0C_NoFrf[u8LocalIdx]) & 0x00FF);
         Fault_context_eep_eobd[11] = GD_Pid0D_NoFrf[u8LocalIdx];
         Fault_context_eep_eobd[12] =
            (uint8)(((GD_Pid23_NoFrf[u8LocalIdx]) & 0xFF00) >> 8);
         Fault_context_eep_eobd[13] =
            (uint8)((GD_Pid23_NoFrf[u8LocalIdx]) & 0x00FF);
         Fault_context_eep_eobd[14] =
            (uint8)(((GD_Pid42_NoFrf[u8LocalIdx]) & 0xFF00) >> 8);
         Fault_context_eep_eobd[15] =
            (uint8)((GD_Pid42_NoFrf[u8LocalIdx]) & 0x00FF);
         MEM_vidF08_StoreData();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MEM_vidF08_StoreData                                       */
/* !Description :  Enregistrement à la volée sur Eeprom                       */
/* !Number      :  FCT1.09                                                    */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/*  argin boolean bMode);                                                     */
/*  input uint8 MEM_AllowEepSave;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MEM_vidF08_StoreData(void)
{
   if (MEM_AllowEepSave != 0x5A)
   {
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM1, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM2, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM3, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM4, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM5, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM6, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM7, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM8, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM9, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM10, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM11, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM12, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM13, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM14, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM15, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM16, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM17, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM18, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM19, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM20, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM21, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM22, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM23, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM24, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM25, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM26, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM27, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM28, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM29, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM30, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM31, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM32, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM33, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM34, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM35, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM36, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM37, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM38, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM39, NVMSRV_bSAVE_NOW);
      NVMSRV_vidWrite(NVMSRV_udtOBJ_MEM40, NVMSRV_bSAVE_NOW);
   }
}
/*------------------------------- end of file --------------------------------*/