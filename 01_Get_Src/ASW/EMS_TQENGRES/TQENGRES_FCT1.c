/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQENGRES                                                */
/* !Description     : TQENGRES Component.                                     */
/*                                                                            */
/* !Module          : TQENGRES                                                */
/* !Description     : réserve de couple moteur                                */
/*                                                                            */
/* !File            : TQENGRES_FCT1.C                                         */
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
/*   1 / TQENGRES_vidInitOutput                                               */
/*   2 / TQENGRES_vidReserve_moteur                                           */
/*   3 / TQENGRES_vidDegradation_de_base                                      */
/*   4 / TQENGRES_vidReserve_au_ralenti                                       */
/*   5 / TQENGRES_vidCond_reserve_dyn                                         */
/*   6 / TQENGRES_vidTqResTqIdlResStat                                        */
/*   7 / TQENGRES_vidResAnticipRalenti                                        */
/*   8 / TQENGRES_vidActResAnticipRalenti                                     */
/*   9 / TQENGRES_vidCalCplResAntiRalenti                                     */
/*   10 / TQENGRES_vidFilResAnticipRalenti                                    */
/*                                                                            */
/* !Reference   : PTS_DOC_5135152 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_0176 / 2.3                                      */
/* !OtherRefs   : VEMS V02 ECU#065368                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQENGRES/TQENGRES$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQENGRES.h"
#include "TQENGRES_L.h"
#include "TQENGRES_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidInitOutput                                     */
/* !Description :  initialisation des variables de sorie.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void TQENGRES_vidTqResTqIdlResStat();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input uint16 TqRes_tqDftValIdlResStat_C;                                  */
/*  input uint16 TqRes_tqIdlResStatTCo_MP;                                    */
/*  input uint16 TqRes_tqIdlResStatTAir_MP;                                   */
/*  output uint16 TqRes_tqIdlResStat_MP;                                      */
/*  output uint16 TqRes_rBasRes;                                              */
/*  output uint16 TqRes_tqIdlRes;                                             */
/*  output uint8 TQENGRES_u8ctCdnResDyn_MP_Prev;                              */
/*  output boolean TqRes_bCdnIdlResDyn;                                       */
/*  output uint16 TqRes_tqIdlResDyn_MP;                                       */
/*  output boolean TQENGRES_bNegHysOut;                                       */
/*  output uint32 TQENGRES_u32FiltredResAntIdlMem;                            */
/*  output uint16 TqRes_tqAntIdl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidInitOutput(void)
{
   boolean  bLocalTqSys_bEngNOnIdl;
   boolean  bLocalAcvTqIdlResDftVal;
   uint32   u32LocalcalTqResStat;


   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);

   if (bLocalTqSys_bEngNOnIdl != 0)
   {
      bLocalAcvTqIdlResDftVal = GDGAR_bGetFRM(FRM_FRM_ACVTQIDLRESDFTVAL);
      if (bLocalAcvTqIdlResDftVal != 0)
      {
         u32LocalcalTqResStat = (uint32)(TqRes_tqDftValIdlResStat_C * 4);
         TqRes_tqIdlResStat_MP =
            (uint16)MATHSRV_udtMIN(u32LocalcalTqResStat, 1920);
      }
      else
      {
         TQENGRES_vidTqResTqIdlResStat();
         u32LocalcalTqResStat = (uint32)( ( TqRes_tqIdlResStatTCo_MP
                                          + TqRes_tqIdlResStatTAir_MP)
                                        * 4);
         TqRes_tqIdlResStat_MP = (uint16)MATHSRV_udtMIN(u32LocalcalTqResStat,
                                                        1920);
      }
   }
   else
   {
      TqRes_tqIdlResStat_MP = 0;
   }
   VEMS_vidSET(TqRes_rBasRes, 0);
   VEMS_vidSET(TqRes_tqIdlRes, 0);
   TQENGRES_u8ctCdnResDyn_MP_Prev = 0;
   TqRes_bCdnIdlResDyn = 0;
   TqRes_tqIdlResDyn_MP = 0;
   TQENGRES_bNegHysOut = 1;
   /* Filter initialization */
   TQENGRES_u32FiltredResAntIdlMem = 0;
   TqRes_tqAntIdl = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidReserve_moteur                                 */
/* !Description :  La fonction réserve de couple moteur contient deux types de*/
/*                 réserves :Une réserve de base et Une  réserve  de  couple  */
/*                 calibrée  en  fonction  de  la  température  de  l’eau,  de*/
/*                  la  température  d’air ambiant et du rapport de boîte     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07504_002.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQENGRES_vidDegradation_de_base();                       */
/*  extf argret void TQENGRES_vidResAnticipRalenti();                         */
/*  extf argret void TQENGRES_vidReserve_au_ralenti();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidReserve_moteur(void)
{
   TQENGRES_vidDegradation_de_base();
   TQENGRES_vidResAnticipRalenti();
   TQENGRES_vidReserve_au_ralenti();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidDegradation_de_base                            */
/* !Description :  La dégradation de base est issue soit d’une cartographie   */
/*                 calibrable en fonction du régime moteur et du remplissage, */
/*                 soit du rendement d’avance maximum.   La dégradation est   */
/*                 saturée par un seuil maximum.                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqRes_bCfEfcIvsBasRes_C;                                    */
/*  input uint16 IgSys_rMaxIgEfc;                                             */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 TqRes_nEngBasRes_A[12];                                      */
/*  input uint16 TqRes_rAirLdBasRes_A[12];                                    */
/*  input uint8 TqRes_rEfcIvsBasRes_M[12][12];                                */
/*  input uint16 TqRes_rBasResNotSat_MP;                                      */
/*  input uint8 TqRes_rMaxBasRes_C;                                           */
/*  output uint16 TqRes_rBasResNotSat_MP;                                     */
/*  output uint16 TqRes_rBasRes;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidDegradation_de_base(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalEngnCkFil;
   uint16 u16LocalEngM_rAirLdCorCalcPara;
   uint16 u16LocalTempEngnCkFil;
   uint16 u16LocalEngNCkFil;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalIgSys_rMaxIgEfc;
   uint16 u16LocalTqRes_rBasRes;
   uint16 u16LocalTqRes_rMaxBasRes;
   uint16 u16LocalTqRes_rBasResNotSat_MP;
   sint32 s32LocalTqRes_rBasRes_NoSat_MP;


   if (TqRes_bCfEfcIvsBasRes_C != 0)
   {
      VEMS_vidGET(IgSys_rMaxIgEfc, u16LocalIgSys_rMaxIgEfc);
      if (u16LocalIgSys_rMaxIgEfc > 1)
      {
         s32LocalTqRes_rBasRes_NoSat_MP =
            ((1024 - u16LocalIgSys_rMaxIgEfc) * 1024) / u16LocalIgSys_rMaxIgEfc;
         TqRes_rBasResNotSat_MP =
            (uint16)MATHSRV_udtCLAMP(s32LocalTqRes_rBasRes_NoSat_MP, 0, 1024);
      }
      else
      {
         TqRes_rBasResNotSat_MP = 1024;
      }
   }
   else
   {
      VEMS_vidGET(Eng_nCkFil, u16LocalEngNCkFil);
      VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

      u16LocalTempEngnCkFil = (uint16)(u16LocalEngNCkFil / 4);
      u16LocalEngnCkFil = MATHSRV_u16CalcParaIncAryU16(TqRes_nEngBasRes_A,
                                                       u16LocalTempEngnCkFil,
                                                       12);
      u16LocalEngM_rAirLdCor = (uint16)(u16LocalEngM_rAirLdCor / 64);
      u16LocalEngM_rAirLdCorCalcPara =
         MATHSRV_u16CalcParaIncAryU16(TqRes_rAirLdBasRes_A,
                                      u16LocalEngM_rAirLdCor,
                                      12);
      u8LocalInterp2d = MATHSRV_u8Interp2d(&TqRes_rEfcIvsBasRes_M[0][0],
                                           u16LocalEngnCkFil,
                                           u16LocalEngM_rAirLdCorCalcPara,
                                           12);

      TqRes_rBasResNotSat_MP = (uint16)(u8LocalInterp2d * 4);
   }

   u16LocalTqRes_rBasResNotSat_MP =
      (uint16)(((TqRes_rBasResNotSat_MP * 125) + 64) / 128);
   u16LocalTqRes_rMaxBasRes = (uint16)(((TqRes_rMaxBasRes_C * 125) + 16) / 32);
   u16LocalTqRes_rBasRes =
      (uint16)MATHSRV_udtMIN(u16LocalTqRes_rBasResNotSat_MP,
                             u16LocalTqRes_rMaxBasRes);
   VEMS_vidSET(TqRes_rBasRes, u16LocalTqRes_rBasRes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidReserve_au_ralenti                             */
/* !Description :  La  réserve de  couple au  ralenti est  la  somme de  la   */
/*                 réserve de  couple  statique et de  la  réserve de couple  */
/*                 dynamique.                                                 */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQENGRES_vidTqResTqIdlResStat();                         */
/*  extf argret void TQENGRES_vidCond_reserve_dyn();                          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input uint16 TqRes_tqDftValIdlResStat_C;                                  */
/*  input uint16 TqRes_tqIdlResStatTCo_MP;                                    */
/*  input uint16 TqRes_tqIdlResStatTAir_MP;                                   */
/*  input uint16 TqRes_tqIncMaxIdlResStat_C;                                  */
/*  input sint16 TqRes_tqDecMaxIdlResStat_C;                                  */
/*  input uint16 TqRes_tqIdlResStat_MP;                                       */
/*  input boolean TqRes_bCdnIdlResDyn;                                        */
/*  input uint16 TqRes_tqDynMaxIdlRes_C;                                      */
/*  input sint16 TqRes_tqDecMaxSlowIdlResDyn_C;                               */
/*  input sint16 TqRes_tqDecMaxFastIdlResDyn_C;                               */
/*  input uint16 TqRes_tqIncMaxIdlResDyn_C;                                   */
/*  input uint16 TqRes_tqIdlResDyn_MP;                                        */
/*  input uint16 TqRes_tqAntIdl;                                              */
/*  output uint16 TqRes_tqIdlResStat_MP;                                      */
/*  output uint16 TqRes_tqIdlResDyn_MP;                                       */
/*  output uint16 TqRes_tqIdlRes;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidReserve_au_ralenti(void)
{
   boolean  bLocalAcvTqIdlResDftVal;
   boolean  bLocalTqSys_bEngNOnIdl;
   uint16   u16LocalTqRes_tqIdlRes;
   uint16   u16LocalIncStat;
   uint16   u16LocalDecStat;
   uint16   u16LocalIncDyn;
   uint16   u16LocalDecDyn;
   uint16   u16LocalTqRes_tqIdlResStat;
   uint16   u16LocalTqRes_tqIdlResDyn;
   uint16   u16LocalResStatPlusResDyn;
   uint16   u16LocalcalTqResStat;
   uint16   u16LocalcalTqResDyn;
   uint32   u32LocalcalTqResStat;
   uint32   u32LocalcalTqResDyn;
   sint16   s16LocalDecStat;
   sint16   s16LocalDecDyn;


   bLocalAcvTqIdlResDftVal = GDGAR_bGetFRM(FRM_FRM_ACVTQIDLRESDFTVAL);
   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);

   /*Calcul_Reserve_Couple_Ralenti_Statique*/
   TQENGRES_vidTqResTqIdlResStat();
   if (bLocalTqSys_bEngNOnIdl != 0)
   {
      if (bLocalAcvTqIdlResDftVal != 0)
      {
         u32LocalcalTqResStat = (uint32)(TqRes_tqDftValIdlResStat_C * 4);
      }
      else
      {
         u32LocalcalTqResStat = (uint32)( ( TqRes_tqIdlResStatTCo_MP
                                          + TqRes_tqIdlResStatTAir_MP)
                                        * 4);
      }
   }
   else
   {
      u32LocalcalTqResStat = 0;
   }
   u16LocalcalTqResStat = (uint16)MATHSRV_udtMIN(u32LocalcalTqResStat, 65535);
   u16LocalIncStat = (uint16)(((TqRes_tqIncMaxIdlResStat_C * 8) + 25) / 50);
   s16LocalDecStat = (sint16)( ( ((-1) * TqRes_tqDecMaxIdlResStat_C * 8)
                               + 25)
                             / 50);
   u16LocalDecStat =  (uint16)MATHSRV_udtMAX(s16LocalDecStat, 0);
   u16LocalTqRes_tqIdlResStat = MATHSRV_u16SlewFilter(TqRes_tqIdlResStat_MP,
                                                      u16LocalcalTqResStat,
                                                      u16LocalIncStat,
                                                      u16LocalDecStat);
   TqRes_tqIdlResStat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlResStat,
                                                  1920);

   /*F02_02_01_Condition_reserve_dynamique*/
   TQENGRES_vidCond_reserve_dyn();
   if (TqRes_bCdnIdlResDyn != 0)
   {
      u32LocalcalTqResDyn = (uint32)(TqRes_tqDynMaxIdlRes_C * 4);
      u16LocalcalTqResDyn = (uint16)MATHSRV_udtMIN(u32LocalcalTqResDyn,
                                                   65535);
   }
   else
   {
      u16LocalcalTqResDyn = 0;
   }
   if (bLocalTqSys_bEngNOnIdl != 0)
   {
      s16LocalDecDyn =
         (sint16)(((TqRes_tqDecMaxSlowIdlResDyn_C * 8) - 25) / 50);
   }
   else
   {
      s16LocalDecDyn =
         (sint16)(((TqRes_tqDecMaxFastIdlResDyn_C * 8) - 25) / 50);
   }
   u16LocalIncDyn = (uint16)(((TqRes_tqIncMaxIdlResDyn_C * 8) + 25) / 50);
   s16LocalDecDyn = (sint16)((-1) * s16LocalDecDyn);
   u16LocalDecDyn =  (uint16)MATHSRV_udtMAX(s16LocalDecDyn, 0);
   u16LocalTqRes_tqIdlResDyn = MATHSRV_u16SlewFilter(TqRes_tqIdlResDyn_MP,
                                                     u16LocalcalTqResDyn,
                                                     u16LocalIncDyn,
                                                     u16LocalDecDyn);
   TqRes_tqIdlResDyn_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlResDyn,
                                                 1920);
   u16LocalResStatPlusResDyn = (uint16)( ( TqRes_tqIdlResStat_MP
                                         + TqRes_tqIdlResDyn_MP
                                         + 2)
                                       / 4);

   u16LocalTqRes_tqIdlRes = (uint16)MATHSRV_udtMAX(u16LocalResStatPlusResDyn,
                                                   TqRes_tqAntIdl);
   u16LocalTqRes_tqIdlRes = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes,
                                                   1600);
   VEMS_vidSET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidCond_reserve_dyn                               */
/* !Description :  Production de la condition de réserve de couple dynamique. */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input uint16 IgSys_rMaxIgEfc;                                             */
/*  input uint16 IgSys_rStatIgSpEfc;                                          */
/*  input uint16 TqRes_rIgEfcOfsIdlResDyn_C;                                  */
/*  input uint8 TQENGRES_u8ctCdnResDyn_MP_Prev;                               */
/*  input uint8 TqRes_ctIncCdnResDyn_C;                                       */
/*  input sint16 TqRes_ctDecCdnResDyn_C;                                      */
/*  input uint8 TqRes_ctCdnResDyn_MP;                                         */
/*  input uint8 TqRes_ctThdLoCdnResDyn_C;                                     */
/*  input uint8 TqRes_ctThdHiCdnResDyn_C;                                     */
/*  output uint8 TqRes_ctCdnResDyn_MP;                                        */
/*  output uint8 TQENGRES_u8ctCdnResDyn_MP_Prev;                              */
/*  output boolean TqRes_bCdnIdlResDyn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidCond_reserve_dyn(void)
{
   /*F02_02_01_Condition_reserve_dynamique*/
   boolean bLocalTqSys_bEngNOnIdl;
   uint16  u16LocalIgSys_rMaxIgEfc;
   uint16  u16LocalIgSys_rStatIgSpEfc;
   sint32  s32LocalTqRes_ctCdnResDyn_MP;
   sint32  s32LocalrMaxIgEfcMinusfacEfcOfs;


   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);
   VEMS_vidGET(IgSys_rMaxIgEfc, u16LocalIgSys_rMaxIgEfc);
   VEMS_vidGET(IgSys_rStatIgSpEfc, u16LocalIgSys_rStatIgSpEfc);

   s32LocalrMaxIgEfcMinusfacEfcOfs =
      (sint32)u16LocalIgSys_rMaxIgEfc - (sint32)TqRes_rIgEfcOfsIdlResDyn_C;

   if (  (bLocalTqSys_bEngNOnIdl != 0)
      && ((sint32)u16LocalIgSys_rStatIgSpEfc > s32LocalrMaxIgEfcMinusfacEfcOfs))
   {
      s32LocalTqRes_ctCdnResDyn_MP =
         (sint32)(TQENGRES_u8ctCdnResDyn_MP_Prev + TqRes_ctIncCdnResDyn_C);
   }
   else
   {
      s32LocalTqRes_ctCdnResDyn_MP =
         (sint32)(TQENGRES_u8ctCdnResDyn_MP_Prev + TqRes_ctDecCdnResDyn_C);
   }

   TqRes_ctCdnResDyn_MP =
      (uint8)MATHSRV_udtCLAMP(s32LocalTqRes_ctCdnResDyn_MP, 0, 255);

   TQENGRES_u8ctCdnResDyn_MP_Prev = TqRes_ctCdnResDyn_MP;

   if (TqRes_ctCdnResDyn_MP <= TqRes_ctThdLoCdnResDyn_C)
   {
      TqRes_bCdnIdlResDyn = 0;
   }
   else
   {
      if (TqRes_ctCdnResDyn_MP >= TqRes_ctThdHiCdnResDyn_C)
      {
         TqRes_bCdnIdlResDyn = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidTqResTqIdlResStat                              */
/* !Description :  fonction de calcul de l'offset de réserve couple ralenti   */
/*                 statique fonction de la température d'air  et fonction de  */
/*                 la température d'eau.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint8 TqRes_tAir_A[8];                                              */
/*  input uint16 TqRes_tqIdlResStat_T[8];                                     */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 TqRes_tCo_A[8];                                               */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint16 TqRes_tqIdlResStat_M[8][8];                                  */
/*  output uint16 TqRes_tqIdlResStatTAir_MP;                                  */
/*  output uint16 TqRes_tqIdlResStatTCo_MP;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidTqResTqIdlResStat(void)
{
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalTQENGRES_u8Tq_tAir;
   uint8   u8LocalExttCoMes;
   uint16  u16LocalTqtAir;
   uint16  u16LocalTmpInterp1d;
   uint16  u16LocalTqRestCo;
   uint16  u16LocalTmpResInterp2d;
   uint16  u16LocalCoPt_noEgdGearCord;
   sint8   s8LocalExt_tAir;
   sint16  s16LocalExttCoMes;
   sint16  s16LocalTqtAir;
   sint32  s32LocalTqRestCo;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   s16LocalTqtAir = (sint16)(s8LocalExt_tAir + 50);
   u8LocalTQENGRES_u8Tq_tAir = (uint8)MATHSRV_udtMAX(s16LocalTqtAir, 0);
   u16LocalTqtAir = MATHSRV_u16CalcParaIncAryU8(TqRes_tAir_A ,
                                                u8LocalTQENGRES_u8Tq_tAir,
                                                8);
   u16LocalTmpInterp1d = MATHSRV_u16Interp1d(TqRes_tqIdlResStat_T,
                                             u16LocalTqtAir);
   TqRes_tqIdlResStatTAir_MP =
      (uint16)MATHSRV_udtMIN(u16LocalTmpInterp1d, 1600);

   VEMS_vidGET(Ext_tCoMes, s16LocalExttCoMes);
   s32LocalTqRestCo = (sint32)(s16LocalExttCoMes + 40);
   u8LocalExttCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalTqRestCo, 0, 254);
   u16LocalTqRestCo = MATHSRV_u16CalcParaIncAryU8(TqRes_tCo_A,
                                                  u8LocalExttCoMes,
                                                  8);

   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   u8LocalCoPt_noEgdGearCord =
      (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 7);
   u16LocalCoPt_noEgdGearCord = (uint16)(u8LocalCoPt_noEgdGearCord * 256);
   u16LocalTmpResInterp2d = MATHSRV_u16Interp2d(&TqRes_tqIdlResStat_M[0][0],
                                                 u16LocalTqRestCo,
                                                 u16LocalCoPt_noEgdGearCord,
                                                 8);
   TqRes_tqIdlResStatTCo_MP =
         (uint16)MATHSRV_udtMIN(u16LocalTmpResInterp2d, 1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidResAnticipRalenti                              */
/* !Description :  Fonction pour calculer la réserve de couple d’anticipation */
/*                 des entrées au ralenti. Ce calcule se fait en 3 temps :    */
/*                 Activation de la réserve, Calcul du couple de réserve brut */
/*                 et Filtrage du couple de réserve brut                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQENGRES_vidActResAnticipRalenti();                      */
/*  extf argret void TQENGRES_vidCalCplResAntiRalenti();                      */
/*  extf argret void TQENGRES_vidFilResAnticipRalenti();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidResAnticipRalenti(void)
{
   TQENGRES_vidActResAnticipRalenti();
   TQENGRES_vidCalCplResAntiRalenti();
   TQENGRES_vidFilResAnticipRalenti();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidActResAnticipRalenti                           */
/* !Description :  Cette fonction permet de choisir le critère d’activation de*/
/*                 la réserve d’anticipation des entrées ralenti.             */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqRes_nOfsAcvAntRes_T[4];                                    */
/*  input sint16 TqRes_nThdDeacAntRes_C;                                      */
/*  input uint8 TqRes_noSelAntRes_C;                                          */
/*  input boolean IdlSys_bEnaIdl;                                             */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean TQENGRES_bNegHysOut;                                        */
/*  input uint16 AccP_rAccP;                                                  */
/*  input sint8 TqRes_rAccPThdAcvAntDyn_C;                                    */
/*  input boolean TqRes_bDeacAntRes_C;                                        */
/*  output boolean TQENGRES_bNegHysOut;                                       */
/*  output boolean TqRes_bAcvAntIdl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidActResAnticipRalenti(void)
{
   boolean bLocalSelOut;
   boolean bLocalEnaIdl;
   boolean bLocalAcvIdlCtl;
   uint8   u8LocalIdlSysNoGear;
   uint16  u16LocalTqSysNTarIdl;
   uint16  u16LocalEngNCkFil;
   uint16  u16LocalAccPRAccP;
   sint16  s16LocalAccP;
   sint32  s32LocalNegHysLow;
   sint32  s32LocalNegHysHi;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSysNoGear);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSysNTarIdl);
   VEMS_vidGET(Eng_nCkFil, u16LocalEngNCkFil);
   u8LocalIdlSysNoGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSysNoGear, 3);
   s32LocalNegHysLow =
         (sint32)( (8 * TqRes_nOfsAcvAntRes_T[u8LocalIdlSysNoGear])
                 + u16LocalTqSysNTarIdl);
   s32LocalNegHysHi =(8 * TqRes_nThdDeacAntRes_C) + s32LocalNegHysLow;

   if (u16LocalEngNCkFil >= s32LocalNegHysHi)
   {
      TQENGRES_bNegHysOut = 0;
   }
   else
   {
      if (u16LocalEngNCkFil <= s32LocalNegHysLow)
      {
         TQENGRES_bNegHysOut = 1;
      }
   }

   if (TqRes_noSelAntRes_C == 0)
   {
      VEMS_vidGET(IdlSys_bEnaIdl, bLocalEnaIdl);
      bLocalSelOut = bLocalEnaIdl;
   }
   else
   {
      if (TqRes_noSelAntRes_C == 1)
      {
         VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalAcvIdlCtl);
         bLocalSelOut = bLocalAcvIdlCtl;
      }
      else
      {
         if (TqRes_noSelAntRes_C == 2)
         {
            bLocalSelOut = TQENGRES_bNegHysOut;
         }
         else
         {
            bLocalSelOut = TQENGRES_bNegHysOut;
            SWFAIL_vidSoftwareErrorHook();
         }
      }
   }

   VEMS_vidGET(AccP_rAccP, u16LocalAccPRAccP);
   s16LocalAccP = (sint16)(128 * TqRes_rAccPThdAcvAntDyn_C);
   if (  (u16LocalAccPRAccP <= s16LocalAccP)
      && (bLocalSelOut != 0)
      && (TqRes_bDeacAntRes_C != 0))
   {
      TqRes_bAcvAntIdl = 1;
   }
   else
   {
      TqRes_bAcvAntIdl = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidCalCplResAntiRalenti                           */
/* !Description :  Fonction de calcule le couple de réserve pour anticiper les*/
/*                 entrées au ralenti.                                        */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_tqLoss;                                               */
/*  input sint16 IdlSys_tqIdcIdlStab;                                         */
/*  input boolean TqRes_bAcvAntIdl;                                           */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input uint8 IdlSys_noGear;                                                */
/*  input boolean TqRes_bTqLossBfIdlAcv_C;                                    */
/*  input uint16 TqRes_tqDeltaTqStabLoss_A[12];                               */
/*  input uint16 TQENGRES_u16TqDeltaTqStabLoss;                               */
/*  input uint8 TqRes_tqTqLoss_A[12];                                         */
/*  input uint16 TqRes_tqIdlAntRes_M[12][12];                                 */
/*  input uint8 TqRes_facNoGearTqAntRes_T[4];                                 */
/*  output uint16 TQENGRES_u16TqDeltaTqStabLoss;                              */
/*  output uint16 TqRes_tqAntIdlRaw;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidCalCplResAntiRalenti(void)
{
   boolean bLocalAcvIdlCtl;
   uint8   u8LocalIdlSysNoGear;
   uint8   u8LocalClamp;
   uint16  u16LocalInterp2d;
   uint16  u16LocalStabLossCalcpara;
   uint16  u16LocalTqLossCalcPara;
   sint16  s16LocalTqIdcIdlStab;
   sint16  s16LocalTqLoss;
   sint16  s16LocalTqLossInterp;
   sint32  s32LocalCalc;


   VEMS_vidGET(IdlSys_tqLoss, s16LocalTqLoss);
   VEMS_vidGET(IdlSys_tqIdcIdlStab, s16LocalTqIdcIdlStab);
   s32LocalCalc = (sint32)( ( s16LocalTqLoss
                            - s16LocalTqIdcIdlStab)
                          + 3200);
   if (s32LocalCalc >= 0)
   {
      s32LocalCalc = (s32LocalCalc + 8) / 16;
   }
   else
   {
      s32LocalCalc = (s32LocalCalc - 8) / 16;
   }
   TQENGRES_u16TqDeltaTqStabLoss = (uint16)MATHSRV_udtMAX(s32LocalCalc, 0);

   if (TqRes_bAcvAntIdl != 0)
   {
      VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalAcvIdlCtl);
      VEMS_vidGET(IdlSys_noGear, u8LocalIdlSysNoGear);
      u8LocalIdlSysNoGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSysNoGear, 3);

      if (  (TqRes_bTqLossBfIdlAcv_C != 0)
         || (bLocalAcvIdlCtl != 0))
      {
         u16LocalStabLossCalcpara =
         MATHSRV_u16CalcParaIncAryU16(TqRes_tqDeltaTqStabLoss_A,
                                      TQENGRES_u16TqDeltaTqStabLoss,
                                      12);

         s16LocalTqLossInterp = (sint16)(s16LocalTqLoss / 16);
         u8LocalClamp = (uint8)MATHSRV_udtCLAMP(s16LocalTqLossInterp, 0, 255);
         u16LocalTqLossCalcPara = MATHSRV_u16CalcParaIncAryU8(TqRes_tqTqLoss_A,
                                                              u8LocalClamp,
                                                              12);

         u16LocalInterp2d = MATHSRV_u16Interp2d(&TqRes_tqIdlAntRes_M[0][0],
                                                u16LocalStabLossCalcpara,
                                                u16LocalTqLossCalcPara,
                                                12);
         s32LocalCalc =
            (sint32)( ( ( TqRes_facNoGearTqAntRes_T[u8LocalIdlSysNoGear]
                        * u16LocalInterp2d)
                      + 4)
                    / 8);
      }
      else
      {
         s32LocalCalc = (sint32)( TqRes_facNoGearTqAntRes_T[u8LocalIdlSysNoGear]
                                * s16LocalTqLoss);
         if (s16LocalTqLoss < 0)
         {
            s32LocalCalc = (s32LocalCalc - 4) / 8;
         }
         else
         {
            s32LocalCalc = (s32LocalCalc + 4) / 8;
         }
      }
      TqRes_tqAntIdlRaw = (uint16)MATHSRV_udtCLAMP(s32LocalCalc, 0, 1600);
   }
   else
   {
      TqRes_tqAntIdlRaw = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQENGRES_vidFilResAnticipRalenti                           */
/* !Description :  Ce bloc filtre le couple de réserve d’anticipation des     */
/*                 entrées ralenti pour ne pas bruiter la consigne AIR.       */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_04985_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqRes_tqAntIdlRaw;                                           */
/*  input uint16 TqRes_tqAntIdl;                                              */
/*  input uint16 TqRes_facFilIncTqAntIdlRes_C;                                */
/*  input uint16 TqRes_facFilDecTqAntIdlRes_C;                                */
/*  input uint32 TQENGRES_u32FiltredResAntIdlMem;                             */
/*  output uint16 TqRes_tqAntIdl;                                             */
/*  output uint32 TQENGRES_u32FiltredResAntIdlMem;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQENGRES_vidFilResAnticipRalenti(void)
{
   uint16 u16LocalTqAntIdlResCal;
   uint16 u16LocalTqResTqAntIdl;


   if (TqRes_tqAntIdlRaw >= TqRes_tqAntIdl)
   {
      u16LocalTqAntIdlResCal = TqRes_facFilIncTqAntIdlRes_C;
   }
   else
   {
      u16LocalTqAntIdlResCal = TqRes_facFilDecTqAntIdlRes_C;
   }

   if (u16LocalTqAntIdlResCal < 1024)
   {
      u16LocalTqAntIdlResCal = (uint16)(u16LocalTqAntIdlResCal * 64);

      u16LocalTqResTqAntIdl =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalTqAntIdlResCal,
                                         &TQENGRES_u32FiltredResAntIdlMem,
                                         TqRes_tqAntIdlRaw);
      TqRes_tqAntIdl = (uint16)MATHSRV_udtMIN(u16LocalTqResTqAntIdl, 1600);
   }
   else
   {
      TqRes_tqAntIdl = (uint16)MATHSRV_udtMIN(TqRes_tqAntIdlRaw, 1600);
      TQENGRES_u32FiltredResAntIdlMem = (uint32)(TqRes_tqAntIdl * 65536);
   }
}
/*---------------------------------end of file--------------------------------*/